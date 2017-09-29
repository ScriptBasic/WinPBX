' ########################################################################################
' Microsoft Windows
' File: DXGI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DXGI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "DXGIType.inc"

%DXGI_CPU_ACCESS_NONE       = 0
%DXGI_CPU_ACCESS_DYNAMIC    = 1
%DXGI_CPU_ACCESS_READ_WRITE = 2
%DXGI_CPU_ACCESS_SCRATCH    = 3
%DXGI_CPU_ACCESS_FIELD      = 15

%DXGI_USAGE_SHADER_INPUT             = &H10    ' 1L << (0 + 4)
%DXGI_USAGE_RENDER_TARGET_OUTPUT     = &H20    ' 1L << (1 + 4)
%DXGI_USAGE_BACK_BUFFER              = &H40    ' 1L << (2 + 4)
%DXGI_USAGE_SHARED                   = &H80    ' 1L << (3 + 4)
%DXGI_USAGE_READ_ONLY                = &H100   ' 1L << (4 + 4)
%DXGI_USAGE_DISCARD_ON_PRESENT       = &H200   ' 1L << (5 + 4)
%DXGI_USAGE_UNORDERED_ACCESS         = &H400   ' ( 1L << (6 + 4) )

'typedef UINT DXGI_USAGE;

' // Size = 32 bytes
TYPE DXGI_FRAME_STATISTICS QWORD FILL
   PresentCount        AS DWORD   ' UINT
   PresentRefreshCount AS DWORD   ' UINT
   SyncRefreshCount    AS DWORD   ' UINT
   SyncQPCTime         AS QUAD    ' LARGE_INTEGER
   SyncGPUTime         AS QUAD    ' LARGE_INTEGER
END TYPE

' // Size = 8 bytes
TYPE DXGI_MAPPED_RECT DWORD
   Pitch AS LONG       ' INT
   pBits AS BYTE PTR   ' BYTE *
END TYPE

#IF NOT %DEF(%LUID_DEFINED)
%LUID_DEFINED = 1
' // Size = 8 bytes
TYPE LUID_STRUCT DWORD
  LowPart  AS DWORD
  HighPart AS LONG
END TYPE
UNION LUID
   LUID_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF

' // Size = 292 bytes
TYPE DXGI_ADAPTER_DESC DWORD
   Description           AS WSTRINGZ * 128   ' WCHAR
   VendorId              AS DWORD             ' UINT
   DeviceId              AS DWORD             ' UINT
   SubSysId              AS DWORD             ' UINT
   Revision              AS DWORD             ' UINT
   DedicatedVideoMemory  AS DWORD             ' SIZE_T
   DedicatedSystemMemory AS DWORD             ' SIZE_T
   SharedSystemMemory    AS DWORD             ' SIZE_T
   AdapterLuid           AS QUAD              ' LUID
END TYPE

'#if !defined(HMONITOR_DECLARED) && !defined(HMONITOR) && (WINVER < 0x0500)
'#define HMONITOR_DECLARED
'#if 0
'typedef HANDLE HMONITOR;

'#endif
'DECLARE_HANDLE(HMONITOR);
'#endif

' // Size = 92 bytes
TYPE DXGI_OUTPUT_DESC DWORD
   DeviceName         AS WSTRINGZ * 32   ' WCHAR
   DesktopCoordinates AS RECT            ' RECT
   AttachedToDesktop  AS LONG            ' BOOL
   Rotation           AS LONG            ' DXGI_MODE_ROTATION enum
   Monitor            AS DWORD           ' HMONITOR
END TYPE

' // Size = 4 bytes
TYPE DXGI_SHARED_RESOURCE DWORD
   Handle AS DWORD   ' HANDLE
END TYPE

%DXGI_RESOURCE_PRIORITY_MINIMUM = &H28000000???
%DXGI_RESOURCE_PRIORITY_LOW     = &H50000000???
%DXGI_RESOURCE_PRIORITY_NORMAL  = &H78000000???
%DXGI_RESOURCE_PRIORITY_HIGH    = &Ha0000000???
%DXGI_RESOURCE_PRIORITY_MAXIMUM = &Hc8000000???

' enum DXGI_RESIDENCY
%DXGI_RESIDENCY_FULLY_RESIDENT            = 1
%DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY = 2
%DXGI_RESIDENCY_EVICTED_TO_DISK           = 3

' // Size = 20 bytes
TYPE DXGI_SURFACE_DESC DWORD
   Width      AS DWORD              ' UINT
   Height     AS DWORD              ' UINT
   Format     AS DWORD              ' DXGI_FORMAT enum
   SampleDesc AS DXGI_SAMPLE_DESC   ' DXGI_SAMPLE_DESC
END TYPE

' enum DXGI_SWAP_EFFECT
%DXGI_SWAP_EFFECT_DISCARD    = 0
%DXGI_SWAP_EFFECT_SEQUENTIAL = 1

' enum DXGI_SWAP_CHAIN_FLAG
%DXGI_SWAP_CHAIN_FLAG_NONPREROTATED     = 1
%DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH = 2
%DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE    = 4

' // Size = 60 bytes
TYPE DXGI_SWAP_CHAIN_DESC DWORD
   BufferDesc   AS DXGI_MODE_DESC     ' DXGI_MODE_DESC
   SampleDesc   AS DXGI_SAMPLE_DESC   ' DXGI_SAMPLE_DESC
   BufferUsage  AS DWORD              ' DXGI_USAGE
   BufferCount  AS DWORD              ' UINT
   OutputWindow AS DWORD              ' HWND
   Windowed     AS LONG               ' BOOL
   SwapEffect   AS DWORD              ' DXGI_SWAP_EFFECT enum
   Flags        AS DWORD              ' UINT
END TYPE


$IID_IDXGIObject          = GUID$("{AEC22FB8-76F3-4639-9BE0-28EB43A67A2E}")
$IID_IDXGIDeviceSubObject = GUID$("{3D3E0379-F9DE-4D58-BB6C-18D62992F1A6}")
$IID_IDXGIResource        = GUID$("{035F3AB4-482E-4E50-B41F-8A7F8BD8960B}")
$IID_IDXGIKeyedMutex      = GUID$("{9D8E1289-D7B3-465F-8126-250E349AF85D}")
$IID_IDXGISurface         = GUID$("{CAFCB56C-6AC3-4889-BF47-9E23BBD260EC}")
$IID_IDXGISurface1        = GUID$("{4AE63092-6327-4C1B-80AE-BFE12EA32B86}")
$IID_IDXGIAdapter         = GUID$("{2411E7E1-12AC-4CCF-BD14-9798E8534DC0}")
$IID_IDXGIOutput          = GUID$("{AE02EEDB-C735-4690-8D52-5A8DC20213AA}")
$IID_IDXGISwapChain       = GUID$("{310D36A0-D2E7-4C0A-AA04-6A9D23B8886A}")
$IID_IDXGIFactory         = GUID$("{7B7166EC-21C7-44AE-B21A-C9AE321AE369}")
$IID_IDXGIDevice          = GUID$("{54EC77FA-1377-44E6-8C32-88FD5F44C84C}")
$IID_IDXGIFactory1        = GUID$("{770AAE78-F26F-4DBA-A829-253C83D1B387}")
$IID_IDXGIAdapter1        = GUID$("{29038F61-3839-4626-91FD-086879011A05}")
$IID_IDXGIDevice1         = GUID$("{77DB970F-6276-48BA-BA28-070143B4392C}")

' ########################################################################################
' IDXGIObject interface
' IID = AEC22FB8-76F3-4639-9BE0-28EB43A67A2E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXGIObject_INTERFACE_DEFINED)
    %IDXGIObject_INTERFACE_DEFINED = 1

INTERFACE IDXGIObject $IID_IDXGIObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IDXGIDeviceSubObject interface
' IID = 3D3E0379-F9DE-4D58-BB6C-18D62992F1A6
' Inherited interface = IDXGIObject
' ########################################################################################

#IF NOT %DEF(%IDXGIDeviceSubObject_INTERFACE_DEFINED)
    %IDXGIDeviceSubObject_INTERFACE_DEFINED = 1

INTERFACE IDXGIDeviceSubObject $IID_IDXGIDeviceSubObject

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDeviceSubObject Method
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDevice AS IUnknown _                       ' __retval_out void **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIDeviceSubObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IDXGIResource interface
' IID = 035F3AB4-482E-4E50-B41F-8A7F8BD8960B
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#IF NOT %DEF(%IDXGIResource_INTERFACE_DEFINED)
    %IDXGIResource_INTERFACE_DEFINED = 1

INTERFACE IDXGIResource $IID_IDXGIResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDeviceSubObject Method
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDevice AS IUnknown _                       ' __retval_out void **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIResource Methods
   ' =====================================================================================
   METHOD GetSharedHandle ( _                           ' VTable offset = 32
     BYREF pSharedHandle AS DWORD _                     ' __out HANDLE *pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUsage ( _                                  ' VTable offset = 36
     BYREF pUsage AS DWORD _                            ' __out DXGI_USAGE *pUsage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEvictionPriority ( _                       ' VTable offset = 40
     BYVAL EvictionPriority AS DWORD _                  ' __in UINT EvictionPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvictionPriority ( _                       ' VTable offset = 44
     BYREF pEvictionPriority AS DWORD _                 ' __retval_out UINT *pEvictionPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIResource_INTERFACE_DEFINED__ */

' ########################################################################################
' IDXGIKeyedMutex interface
' IID = 9D8E1289-D7B3-465F-8126-250E349AF85D
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#IF NOT %DEF(%IDXGIKeyedMutex_INTERFACE_DEFINED)
    %IDXGIKeyedMutex_INTERFACE_DEFINED = 1

INTERFACE IDXGIKeyedMutex $IID_IDXGIKeyedMutex

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDeviceSubObject Method
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDevice AS IUnknown _                       ' __retval_out void **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIKeyedMutex Methods
   ' =====================================================================================
   METHOD AcquireSync ( _                               ' VTable offset = 32
     BYVAL Key AS QUAD _                                ' __in UINT64 Key
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseSync ( _                               ' VTable offset = 36
     BYVAL Key AS QUAD _                                ' __in UINT64 Key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIKeyedMutex_INTERFACE_DEFINED__ */

%DXGI_MAP_READ    = 1???
%DXGI_MAP_WRITE   = 2???
%DXGI_MAP_DISCARD = 4???

' ########################################################################################
' IDXGISurface interface
' IID = CAFCB56C-6AC3-4889-BF47-9E23BBD260EC
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#IF NOT %DEF(%IDXGISurface_INTERFACE_DEFINED)
    %IDXGISurface_INTERFACE_DEFINED = 1

INTERFACE IDXGISurface $IID_IDXGISurface

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDeviceSubObject Method
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDevice AS IUnknown _                       ' __retval_out void **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGISurface Methods
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __out DXGI_SURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 36
     BYREF pLockedRect AS DXGI_MAPPED_RECT _            ' __out DXGI_MAPPED_RECT *pLockedRect
   , BYVAL MapFlags AS DWORD _                          ' __in UINT MapFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGISurface_INTERFACE_DEFINED__ */

' ########################################################################################
' IDXGISurface1 interface
' IID = 4AE63092-6327-4C1B-80AE-BFE12EA32B86
' Inherited interface = IDXGISurface
' ########################################################################################

#IF NOT %DEF(%IDXGISurface1_INTERFACE_DEFINED)
    %IDXGISurface1_INTERFACE_DEFINED = 1

INTERFACE IDXGISurface1 $IID_IDXGISurface1

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDeviceSubObject Method
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDevice AS IUnknown _                       ' __retval_out void **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGISurface Methods
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __out DXGI_SURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 36
     BYREF pLockedRect AS DXGI_MAPPED_RECT _            ' __out DXGI_MAPPED_RECT *pLockedRect
   , BYVAL MapFlags AS DWORD _                          ' __in UINT MapFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGISurface1 Methods
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 44
     BYVAL Discard AS LONG _                            ' __in BOOL Discard
   , BYREF phdc AS DWORD _                              ' __out HDC *phdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 48
     BYREF pDirtyRect AS RECT _                         ' __in RECT *pDirtyRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGISurface1_INTERFACE_DEFINED__ */


' ########################################################################################
' IDXGIAdapter interface
' IID = 2411E7E1-12AC-4CCF-BD14-9798E8534DC0
' Inherited interface = IDXGIObject
' ########################################################################################

#IF NOT %DEF(%IDXGIAdapter_INTERFACE_DEFINED)
    %IDXGIAdapter_INTERFACE_DEFINED = 1

INTERFACE IDXGIAdapter $IID_IDXGIAdapter

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIAdapter Methods
   ' =====================================================================================
   METHOD EnumOutputs ( _                               ' VTable offset = 28
     BYVAL Output AS DWORD _                            ' __in UINT Output
   , BYREF ppOutput AS IDXGIOutput _                    ' __inout IDXGIOutput **ppOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __out DXGI_SURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckInterfaceSupport ( _                     ' VTable offset = 36
     BYREF InterfaceName AS GUID _                      ' __in REFGUID InterfaceName
   , BYREF pUMDVersion AS QUAD _                        ' __out LARGE_INTEGER *pUMDVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIAdapter_INTERFACE_DEFINED__ */


%DXGI_ENUM_MODES_INTERLACED = 1???
%DXGI_ENUM_MODES_SCALING    = 2???


' ########################################################################################
' IDXGIOutput interface
' IID = AEC22FB8-76F3-4639-9BE0-28EB43A67A2E
' Inherited interface = IDXGIObject
' ########################################################################################

#IF NOT %DEF(%IDXGIOutput_INTERFACE_DEFINED)
    %IDXGIOutput_INTERFACE_DEFINED = 1

INTERFACE IDXGIOutput $IID_IDXGIOutput

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIOutput Methods
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 28
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __out DXGI_SURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayModeList ( _                        ' VTable offset = 32
     BYVAL EnumFormat AS DWORD _                        ' __in DXGI_FORMAT EnumFormat
   , BYVAL Flags AS DWORD _                             ' __in UINT Flags
   , BYREF pNumModes AS DWORD _                         ' __inout UINT *pNumModes
   , BYREF pDesc AS DXGI_MODE_DESC _                    ' __out DXGI_MODE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindClosestMatchingMode ( _                   ' VTable offset = 36
     BYREF pModeToMatch AS DXGI_MODE_DESC _             ' __in const DXGI_MODE_DESC *pModeToMatch
   , BYREF pClosestMatch AS DXGI_MODE_DESC _            ' __out DXGI_MODE_DESC *pClosestMatch
   , BYVAL pConcernedDevice AS IUnknown _               ' __in IUnknown *pConcernedDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForVBlank ( _                             ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TakeOwnership ( _                             ' VTable offset = 44
     BYVAL pDevice AS IUnknown _                        ' __in IUnknown *pDevice
   , BYVAL Exclusive AS LONG _                          ' BOOL Exclusive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseOwnership ( _                          ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGammaControlCapabilities ( _               ' VTable offset = 52
     BYREF pGammaCaps AS DXGI_GAMMA_CONTROL_CAPABILITIES _ ' __out DXGI_GAMMA_CONTROL_CAPABILITIES *pGammaCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGammaControl ( _                           ' VTable offset = 56
     BYREF pArray AS DXGI_GAMMA_CONTROL _               ' __in const DXGI_GAMMA_CONTROL *pArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGammaControl ( _                           ' VTable offset = 60
     BYREF pArray AS DXGI_GAMMA_CONTROL _               ' __out DXGI_GAMMA_CONTROL *pArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplaySurface ( _                         ' VTable offset = 64
     BYVAL pScanoutSurface AS IDXGISurface _            ' __in IDXGISurface *pScanoutSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplaySurfaceData ( _                     ' VTable offset = 68
     BYVAL pDestination AS IDXGISurface _               ' __in IDXGISurface *pDestination
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameStatistics ( _                        ' VTable offset = 72
     BYREF pStats AS DXGI_FRAME_STATISTICS _            ' __out DXGI_FRAME_STATISTICS *pStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIOutput_INTERFACE_DEFINED__ */

%DXGI_MAX_SWAP_CHAIN_BUFFERS     = 16
%DXGI_PRESENT_TEST               = &H00000001???
%DXGI_PRESENT_DO_NOT_SEQUENCE    = &H00000002???
%DXGI_PRESENT_RESTART            = &H00000004???


' ########################################################################################
' IDXGISwapChain interface
' IID = 310D36A0-D2E7-4C0A-AA04-6A9D23B8886A
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#IF NOT %DEF(%IDXGISwapChain_INTERFACE_DEFINED)
    %IDXGISwapChain_INTERFACE_DEFINED = 1

INTERFACE IDXGISwapChain $IID_IDXGISwapChain

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDeviceSubObject Method
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDevice AS IUnknown _                       ' __retval_out void **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGISwapChain Methods
   ' =====================================================================================
   METHOD Present ( _                                   ' VTable offset = 32
     BYVAL SyncInterval AS DWORD _                      ' __in UINT SyncInterval
   , BYVAL Flags AS DWORD _                             ' __in UINT Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 36
     BYVAL Buffer AS DWORD _                            ' __in UINT Buffer
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSurface AS IUnknown _                      ' __inout void **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFullscreenState ( _                        ' VTable offset = 40
     BYVAL Fullscreen AS LONG _                         ' __in BOOL Fullscreen
   , BYVAL pTarget AS IDXGIOutput _                     ' __in IDXGIOutput *pTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFullscreenState ( _                        ' VTable offset = 44
     BYVAL Fullscreen AS LONG _                         ' __in BOOL Fullscreen
   , BYREF ppTarget AS IDXGIOutput _                    ' __out IDXGIOutput **ppTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 48
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __out DXGI_SURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResizeBuffers ( _                             ' VTable offset = 52
     BYVAL BufferCount AS DWORD _                       ' __in UINT BufferCount
   , BYVAL Width AS DWORD _                             ' __in UINT Width
   , BYVAL Height AS DWORD _                            ' __in UINT Height
   , BYVAL NewFormat AS DWORD _                         ' __in DXGI_FORMAT NewFormat
   , BYVAL SwapChainFlags AS DWORD _                    ' __in UINT SwapChainFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResizeTarget ( _                              ' VTable offset = 56
     BYREF pNewTargetParameters AS DXGI_MODE_DESC _     ' __in const DXGI_MODE_DESC *pNewTargetParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainingOutput ( _                       ' VTable offset = 60
     BYREF ppOutput AS IDXGIOutput _                    ' __out IDXGIOutput **ppOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameStatistics ( _                        ' VTable offset = 64
     BYREF pStats AS DXGI_FRAME_STATISTICS _            ' __out DXGI_FRAME_STATISTICS *pStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastPresentCount ( _                       ' VTable offset = 68
     BYREF pLastPresentCount AS DWORD _                 ' __out UINT *pLastPresentCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGISwapChain_INTERFACE_DEFINED__ */


%DXGI_MWA_NO_WINDOW_CHANGES = &H1   ' 1 << 0
%DXGI_MWA_NO_ALT_ENTER      = &H2   ' 1 << 1
%DXGI_MWA_NO_PRINT_SCREEN   = &H4   ' 1 << 2
%DXGI_MWA_VALID             = &H7


' ########################################################################################
' IDXGIFactory interface
' IID = 7B7166EC-21C7-44AE-B21A-C9AE321AE369
' Inherited interface = IDXGIObject
' ########################################################################################

#IF NOT %DEF(%IDXGIFactory_INTERFACE_DEFINED)
    %IDXGIFactory_INTERFACE_DEFINED = 1

INTERFACE IDXGIFactory $IID_IDXGIFactory

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIFactory Methods
   ' =====================================================================================
   METHOD EnumAdapters ( _                              ' VTable offset = 28
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF ppAdapter AS IDXGIAdapter _                  ' __out IDXGIAdapter **ppAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeWindowAssociation ( _                     ' VTable offset = 32
     BYVAL WindowHandle AS DWORD _                      ' __in HWND WindowHandle
   , BYVAL Flags AS DWORD _                             ' __in UINT Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindowAssociation ( _                      ' VTable offset = 36
     BYREF pWindowHandle AS DWORD _                     ' __out HWND *pWindowHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSwapChain ( _                           ' VTable offset = 40
     BYVAL pDevice AS IUnknown _                        ' __in IUnknown *pDevice
   , BYREF pDesc AS DXGI_SWAP_CHAIN_DESC _              ' __in DXGI_SWAP_CHAIN_DESC *pDesc
   , BYREF ppSwapChain AS IDXGISwapChain _              ' __out IDXGISwapChain **ppSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSoftwareAdapter ( _                     ' VTable offset = 44
     BYVAL Module AS DWORD _                            ' __in HMODULE Module
   , BYREF ppAdapter AS IDXGIAdapter _                  ' __out IDXGIAdapter **ppAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIFactory_INTERFACE_DEFINED__ */

DECLARE FUNCTION CreateDXGIFactory IMPORT "DXGI.DLL" ALIAS "CreateDXGIFactory" ( _
   BYREF riid AS GUID _                                 ' REFIID riid
 , BYREF ppFactory AS IUnknown _                        ' void **ppFactory
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateDXGIFactory1 IMPORT "DXGI.DLL" ALIAS "CreateDXGIFactory1" ( _
   BYREF riid AS GUID _                                 ' REFIID riid
 , BYREF ppFactory AS IUnknown _                        ' void **ppFactory
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' IDXGIDevice interface
' IID = 54EC77FA-1377-44E6-8C32-88FD5F44C84C
' Inherited interface = IDXGIObject
' ########################################################################################

#IF NOT %DEF(%IDXGIDevice_INTERFACE_DEFINED)
    %IDXGIDevice_INTERFACE_DEFINED = 1

INTERFACE IDXGIDevice $IID_IDXGIDevice

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDevice Methods
   ' =====================================================================================
   METHOD GetAdapter ( _                                ' VTable offset = 28
     BYREF pAdapter AS IDXGIAdapter _                   ' __out IDXGIAdapter **pAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 32
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __in const DXGI_SURFACE_DESC *pDesc
   , BYVAL NumSurfaces AS DWORD _                       ' __in UINT NumSurfaces
   , BYVAL Usage AS DWORD _                             ' __in DXGI_USAGE Usage
   , BYREF pSharedResource AS DXGI_SHARED_RESOURCE _    ' __in const DXGI_SHARED_RESOURCE *pSharedResource
   , BYREF ppSurface AS IDXGISurface _                  ' __out IDXGISurface **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResourceResidency ( _                    ' VTable offset = 36
     BYREF ppResources AS IUnknown _                    ' __in IUnknown *const *ppResources
   , BYREF pResidencyStatus AS DWORD _                  ' __out DXGI_RESIDENCY *pResidencyStatus
   , BYVAL NumResources AS DWORD _                      ' __in UINT NumResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGPUThreadPriority ( _                      ' VTable offset = 40
     BYVAL Priority AS LONG _                           ' __in INT Priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGPUThreadPriority ( _                      ' VTable offset = 44
     BYREF pPriority AS LONG _                          ' __retval_out INT *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIDevice_INTERFACE_DEFINED__ */

' enum DXGI_ADAPTER_FLAG
%DXGI_ADAPTER_FLAG_NONE        = 0???
%DXGI_ADAPTER_FLAG_REMOTE      = 1???
'%DXGI_ADAPTER_FLAG_FORCE_DWORD = &Hffffffff???

' // Size = 296 bytes
TYPE DXGI_ADAPTER_DESC1 DWORD
   Description           AS WSTRINGZ * 128   ' WCHAR
   VendorId              AS DWORD             ' UINT
   DeviceId              AS DWORD             ' UINT
   SubSysId              AS DWORD             ' UINT
   Revision              AS DWORD             ' UINT
   DedicatedVideoMemory  AS DWORD             ' SIZE_T
   DedicatedSystemMemory AS DWORD             ' SIZE_T
   SharedSystemMemory    AS DWORD             ' SIZE_T
   AdapterLuid           AS QUAD              ' LUID
   Flags                 AS DWORD             ' UINT
END TYPE

'typedef struct DXGI_DISPLAY_COLOR_SPACE
'    {
'    FLOAT PrimaryCoordinates[ 8 ][ 2 ];
'    FLOAT WhitePoints[ 16 ][ 2 ];
'    }    DXGI_DISPLAY_COLOR_SPACE;

' // Size = 192 bytes
TYPE DXGI_DISPLAY_COLOR_SPACE DWORD
   PrimaryCoordinates(7, 1) AS SINGLE
   WhitePoints(15, 1) AS SINGLE
END TYPE


' ########################################################################################
' IDXGIFactory1 interface
' IID = 770AAE78-F26F-4DBA-A829-253C83D1B387
' Inherited interface = IDXGIFactory
' ########################################################################################

#IF NOT %DEF(%IDXGIFactory1_INTERFACE_DEFINED)
    %IDXGIFactory1_INTERFACE_DEFINED = 1

INTERFACE IDXGIFactory1 $IID_IDXGIFactory1

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIFactory Methods
   ' =====================================================================================
   METHOD EnumAdapters ( _                              ' VTable offset = 28
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF ppAdapter AS IDXGIAdapter _                  ' __out IDXGIAdapter **ppAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeWindowAssociation ( _                     ' VTable offset = 32
     BYVAL WindowHandle AS DWORD _                      ' __in HWND WindowHandle
   , BYVAL Flags AS DWORD _                             ' __in UINT Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindowAssociation ( _                      ' VTable offset = 36
     BYREF pWindowHandle AS DWORD _                     ' __out HWND *pWindowHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSwapChain ( _                           ' VTable offset = 40
     BYVAL pDevice AS IUnknown _                        ' __in IUnknown *pDevice
   , BYREF pDesc AS DXGI_SWAP_CHAIN_DESC _              ' __in DXGI_SWAP_CHAIN_DESC *pDesc
   , BYREF ppSwapChain AS IDXGISwapChain _              ' __out IDXGISwapChain **ppSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSoftwareAdapter ( _                     ' VTable offset = 44
     BYVAL Module AS DWORD _                            ' __in HMODULE Module
   , BYREF ppAdapter AS IDXGIAdapter _                  ' __out IDXGIAdapter **ppAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIFactory1 Methods
   ' =====================================================================================
   METHOD EnumAdapters1 ( _                             ' VTable offset = 48
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF ppAdapter AS IDXGIAdapter1 _                 ' __out IDXGIAdapter1 **ppAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCurrent ( _                                 ' VTable offset = 52
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIFactory1_INTERFACE_DEFINED__ */

' ########################################################################################
' IDXGIAdapter1 interface
' IID = 29038F61-3839-4626-91FD-086879011A05
' Inherited interface = IDXGIAdapter
' ########################################################################################

#IF NOT %DEF(%IDXGIAdapter1_INTERFACE_DEFINED)
    %IDXGIAdapter1_INTERFACE_DEFINED = 1

INTERFACE IDXGIAdapter1 $IID_IDXGIAdapter1

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIAdapter Methods
   ' =====================================================================================
   METHOD EnumOutputs ( _                               ' VTable offset = 28
     BYVAL Output AS DWORD _                            ' __in UINT Output
   , BYREF ppOutput AS IDXGIOutput _                    ' __inout IDXGIOutput **ppOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS DXGI_ADAPTER_DESC _                 ' __out DXGI_ADAPTER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckInterfaceSupport ( _                     ' VTable offset = 36
     BYREF InterfaceName AS GUID _                      ' __in REFGUID InterfaceName
   , BYREF pUMDVersion AS QUAD _                        ' __out LARGE_INTEGER *pUMDVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIAdapter1 Method
   ' =====================================================================================
   METHOD GetDesc1 ( _                                  ' VTable offset = 40
     BYREF pDesc AS DXGI_ADAPTER_DESC1 _                ' __out DXGI_ADAPTER_DESC1 *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIAdapter1_INTERFACE_DEFINED__ */

' ########################################################################################
' IDXGIDevice1 interface
' IID = 77DB970F-6276-48BA-BA28-070143B4392C
' Inherited interface = IDXGIDevice
' ########################################################################################

#IF NOT %DEF(%IDXGIDevice1_INTERFACE_DEFINED)
    %IDXGIDevice1_INTERFACE_DEFINED = 1

INTERFACE IDXGIDevice1 $IID_IDXGIDevice1

   INHERIT IUnknown

   ' =====================================================================================
   ' IDXGIObject Methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 12
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 16
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYVAL pUnknown AS IUnknown _                       ' __in const IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF Name AS GUID _                               ' __in REFGUID Name
   , BYREF pDataSize AS DWORD _                         ' __inout UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParent AS IUnknown _                       ' __retval_out void **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDevice Methods
   ' =====================================================================================
   METHOD GetAdapter ( _                                ' VTable offset = 28
     BYREF pAdapter AS IDXGIAdapter _                   ' __out IDXGIAdapter **pAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 32
     BYREF pDesc AS DXGI_SURFACE_DESC _                 ' __in const DXGI_SURFACE_DESC *pDesc
   , BYVAL NumSurfaces AS DWORD _                       ' __in UINT NumSurfaces
   , BYVAL Usage AS DWORD _                             ' __in DXGI_USAGE Usage
   , BYREF pSharedResource AS DXGI_SHARED_RESOURCE _    ' __in const DXGI_SHARED_RESOURCE *pSharedResource
   , BYREF ppSurface AS IDXGISurface _                  ' __out IDXGISurface **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResourceResidency ( _                    ' VTable offset = 36
     BYREF ppResources AS IUnknown _                    ' __in IUnknown *const *ppResources
   , BYREF pResidencyStatus AS DWORD _                  ' __out DXGI_RESIDENCY *pResidencyStatus
   , BYVAL NumResources AS DWORD _                      ' __in UINT NumResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGPUThreadPriority ( _                      ' VTable offset = 40
     BYVAL Priority AS LONG _                           ' __in INT Priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGPUThreadPriority ( _                      ' VTable offset = 44
     BYREF pPriority AS LONG _                          ' __retval_out INT *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDXGIDevice1 Methods
   ' =====================================================================================
   METHOD SetMaximumFrameLatency ( _                    ' VTable offset = 48
     BYVAL MaxLatency AS DWORD _                        ' __in UINT MaxLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaximumFrameLatency ( _                    ' VTable offset = 52
     BYREF pMaxLatency AS DWORD _                       ' __out UINT *pMaxLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGIDevice1_INTERFACE_DEFINED__ */
