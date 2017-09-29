' ########################################################################################
' Microsoft Windows
' File: D3D10Misc.inc
' Contents: D3D10 Device Creation APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D10MISC_INC = 1

#INCLUDE ONCE "d3d10.inc"
#INCLUDE ONCE "DXGI.inc"

'///////////////////////////////////////////////////////////////////////////
'// ID3D10Blob:
'// ------------
'// The buffer object is used by D3D10 to return arbitrary size data.
'//
'// GetBufferPointer -
'//    Returns a pointer to the beginning of the buffer.
'//
'// GetBufferSize -
'//    Returns the size of the buffer, in bytes.
'///////////////////////////////////////////////////////////////////////////

$IID_ID3D10Blob = GUID$("{8BA5FB08-5195-40E2-AC58-0D989C3A0102}")

INTERFACE ID3D10Blob $IID_ID3D10Blob

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBufferPointer ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' LPVOID
   ' =====================================================================================
   METHOD GetBufferSize ( _                             ' VTable offset = 16
   ) AS DWORD                                           ' SIZE_T
   ' =====================================================================================

END INTERFACE


'///////////////////////////////////////////////////////////////////////////
'// D3D10_DRIVER_TYPE
'// ----------------
'//
'// This identifier is used to determine the implementation of Direct3D10
'// to be used.
'//
'// Pass one of these values to D3D10CreateDevice
'//
'///////////////////////////////////////////////////////////////////////////

' enum D3D10_DRIVER_TYPE
%D3D10_DRIVER_TYPE_HARDWARE  = 0
%D3D10_DRIVER_TYPE_REFERENCE = 1
%D3D10_DRIVER_TYPE_NULL      = 2
%D3D10_DRIVER_TYPE_SOFTWARE  = 3
%D3D10_DRIVER_TYPE_WARP      = 5

$GUID_DeviceType = GUID$("{D722FB4D-7A68-437A-B20C-5804EE2494A6}")

'///////////////////////////////////////////////////////////////////////////
'// D3D10CreateDevice
'// ------------------
'//
'// pAdapter
'//      If NULL, D3D10CreateDevice will choose the primary adapter and
'//      create a new instance from a temporarily created IDXGIFactory.
'//      If non-NULL, D3D10CreateDevice will register the appropriate
'//      device, if necessary (via IDXGIAdapter::RegisterDrver), before
'//      creating the device.
'// DriverType
'//      Specifies the driver type to be created: hardware, reference or
'//      null.
'// Software
'//      HMODULE of a DLL implementing a software rasterizer. Must be NULL for
'//      non-Software driver types.
'// Flags
'//      Any of those documented for D3D10CreateDevice.
'// SDKVersion
'//      SDK version. Use the D3D10_SDK_VERSION macro.
'// ppDevice
'//      Pointer to returned interface.
'//
'// Return Values
'//  Any of those documented for
'//          CreateDXGIFactory
'//          IDXGIFactory::EnumAdapters
'//          IDXGIAdapter::RegisterDriver
'//          D3D10CreateDevice
'//
'///////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3D10CreateDevice IMPORT "D3D10.DLL" ALIAS "D3D10CreateDevice" ( _
   BYVAL pAdapter AS IDXGIAdapter _                     ' __in  IDXGIAdapter *pAdapter
 , BYVAL DriverType AS DWORD _                          ' __in  D3D10_DRIVER_TYPE DriverType
 , BYVAL Software AS DWORD _                            ' __in  HMODULE Software
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYVAL SDKVersion AS DWORD _                          ' __in  UINT SDKVersion
 , BYREF ppDevice AS ID3D10Device _                     ' __out ID3D10Device **ppDevice
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////
'// D3D10CreateDeviceAndSwapChain
'// ------------------------------
'//
'// ppAdapter
'//      If NULL, D3D10CreateDevice will choose the primary adapter and
'//      create a new instance from a temporarily created IDXGIFactory.
'//      If non-NULL, D3D10CreateDevice will register the appropriate
'//      device, if necessary (via IDXGIAdapter::RegisterDrver), before
'//      creating the device.
'// DriverType
'//      Specifies the driver type to be created: hardware, reference or
'//      null.
'// Software
'//      HMODULE of a DLL implementing a software rasterizer. Must be NULL for
'//      non-Software driver types.
'// Flags
'//      Any of those documented for D3D10CreateDevice.
'// SDKVersion
'//      SDK version. Use the D3D10_SDK_VERSION macro.
'// pSwapChainDesc
'//      Swap chain description, may be NULL.
'// ppSwapChain
'//      Pointer to returned interface. May be NULL.
'// ppDevice
'//      Pointer to returned interface.
'//
'// Return Values
'//  Any of those documented for
'//          CreateDXGIFactory
'//          IDXGIFactory::EnumAdapters
'//          IDXGIAdapter::RegisterDriver
'//          D3D10CreateDevice
'//          IDXGIFactory::CreateSwapChain
'//
'///////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3D10CreateDeviceAndSwapChain IMPORT "D3D10.DLL" ALIAS "D3D10CreateDeviceAndSwapChain" ( _
   BYVAL pAdapter AS IDXGIAdapter _                     ' __in  IDXGIAdapter *pAdapter
 , BYVAL DriverType AS DWORD _                          ' __in  D3D10_DRIVER_TYPE DriverType
 , BYVAL Software AS DWORD _                            ' __in  HMODULE Software
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYVAL SDKVersion AS DWORD _                          ' __in  UINT SDKVersion
 , BYREF pSwapChainDesc AS DXGI_SWAP_CHAIN_DESC _       ' __in  DXGI_SWAP_CHAIN_DESC *pSwapChainDesc
 , BYREF ppSwapChain AS IDXGISwapChain _                ' __out IDXGISwapChain **ppSwapChain
 , BYREF ppDevice AS ID3D10Device _                     ' __out ID3D10Device **ppDevice
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////
'// D3D10CreateBlob:
'// -----------------
'// Creates a Buffer of n Bytes
'//////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3D10CreateBlob IMPORT "D3D10.DLL" ALIAS "D3D10CreateBlob" ( _
   BYVAL NumBytes AS DWORD _                            ' __in  SIZE_T NumBytes
 , BYREF ppBuffer AS ID3D10Blob _                       ' __out LPD3D10BLOB *ppBuffer
 ) AS LONG                                              ' HRESULT
