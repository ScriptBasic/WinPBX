' ########################################################################################
' Microsoft Windows
' File: D3D11sdklayers.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D11SDKLAYERS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "d3d11.inc"

$IID_ID3D11Debug       = GUID$("{79cf2233-7536-4948-9d36-1e4692dc5760}")
$IID_ID3D11SwitchToRef = GUID$("{1ef337e3-58e7-4f83-a692-db221f5ed47e}")
$IID_ID3D11InfoQueue   = GUID$("{6543dbb6-1b48-42f5-ab82-e97ec74326f6}")

%D3D11_SDK_LAYERS_VERSION                  = 1
%D3D11_DEBUG_FEATURE_FLUSH_PER_RENDER_OP   = &H1
%D3D11_DEBUG_FEATURE_FINISH_PER_RENDER_OP  = &H2
%D3D11_DEBUG_FEATURE_PRESENT_PER_RENDER_OP = &H4

' enum D3D11_RLDO_FLAGS
%D3D11_RLDO_SUMMARY = &H1???
%D3D11_RLDO_DETAIL  = &H2???

' ########################################################################################
' ID3D11Debug interface
' IID = 79cf2233-7536-4948-9d36-1e4692dc5760
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D11Debug_INTERFACE_DEFINED)
    %ID3D11Debug_INTERFACE_DEFINED = 1

INTERFACE ID3D11Debug $IID_ID3D11Debug

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFeatureMask ( _                            ' VTable offset = 12
     BYVAL Mask AS DWORD _                              ' __in UINT Mask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeatureMask ( _                            ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD SetPresentPerRenderOpDelay ( _                ' VTable offset = 20
     BYVAL Milliseconds AS DWORD _                      ' __in UINT Milliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentPerRenderOpDelay ( _                ' VTable offset = 24
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD SetSwapChain ( _                              ' VTable offset = 28
     BYVAL pSwapChain AS IDXGISwapChain _               ' __in_opt IDXGISwapChain *pSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSwapChain ( _                              ' VTable offset = 32
     BYREF ppSwapChain AS IDXGISwapChain _              ' __out IDXGISwapChain **ppSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateContext ( _                           ' VTable offset = 36
     BYVAL pContext AS ID3D11DeviceContext _            ' __in ID3D11DeviceContext *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportLiveDeviceObjects ( _                   ' VTable offset = 40
     BYVAL Flags AS DWORD _                             ' __in D3D11_RLDO_FLAGS Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateContextForDispatch ( _                ' VTable offset = 44
     BYVAL pContext AS ID3D11DeviceContext _            ' __in ID3D11DeviceContext *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D11Debug_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D11SwitchToRef interface
' IID = 1ef337e3-58e7-4f83-a692-db221f5ed47e
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D11SwitchToRef_INTERFACE_DEFINED)
    %ID3D11SwitchToRef_INTERFACE_DEFINED = 1

INTERFACE ID3D11SwitchToRef $IID_ID3D11SwitchToRef

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetUseRef ( _                                 ' VTable offset = 12
     BYVAL UseRef AS LONG _                             ' __in BOOL UseRef
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUseRef ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D11SwitchToRef_INTERFACE_DEFINED__ */


' enum D3D11_MESSAGE_CATEGORY
%D3D11_MESSAGE_CATEGORY_APPLICATION_DEFINED                                                   = 0
%D3D11_MESSAGE_CATEGORY_MISCELLANEOUS                                                         = %D3D11_MESSAGE_CATEGORY_APPLICATION_DEFINED                                                   + 1
%D3D11_MESSAGE_CATEGORY_INITIALIZATION                                                        = %D3D11_MESSAGE_CATEGORY_MISCELLANEOUS                                                         + 1
%D3D11_MESSAGE_CATEGORY_CLEANUP                                                               = %D3D11_MESSAGE_CATEGORY_INITIALIZATION                                                        + 1
%D3D11_MESSAGE_CATEGORY_COMPILATION                                                           = %D3D11_MESSAGE_CATEGORY_CLEANUP                                                               + 1
%D3D11_MESSAGE_CATEGORY_STATE_CREATION                                                        = %D3D11_MESSAGE_CATEGORY_COMPILATION                                                           + 1
%D3D11_MESSAGE_CATEGORY_STATE_SETTING                                                         = %D3D11_MESSAGE_CATEGORY_STATE_CREATION                                                        + 1
%D3D11_MESSAGE_CATEGORY_STATE_GETTING                                                         = %D3D11_MESSAGE_CATEGORY_STATE_SETTING                                                         + 1
%D3D11_MESSAGE_CATEGORY_RESOURCE_MANIPULATION                                                 = %D3D11_MESSAGE_CATEGORY_STATE_GETTING                                                         + 1
%D3D11_MESSAGE_CATEGORY_EXECUTION                                                             = %D3D11_MESSAGE_CATEGORY_RESOURCE_MANIPULATION                                                 + 1

' enum D3D11_MESSAGE_SEVERITY
%D3D11_MESSAGE_SEVERITY_CORRUPTION                                                            = 0
%D3D11_MESSAGE_SEVERITY_ERROR                                                                 = %D3D11_MESSAGE_SEVERITY_CORRUPTION                                                            + 1
%D3D11_MESSAGE_SEVERITY_WARNING                                                               = %D3D11_MESSAGE_SEVERITY_ERROR                                                                 + 1
%D3D11_MESSAGE_SEVERITY_INFO                                                                  = %D3D11_MESSAGE_SEVERITY_WARNING                                                               + 1

' enum D3D11_MESSAGE_ID
%D3D11_MESSAGE_ID_UNKNOWN                                                                     = 0
%D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_HAZARD                                            = %D3D11_MESSAGE_ID_UNKNOWN                                                                     + 1
%D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_HAZARD                                              = %D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_HAZARD                                            + 1
%D3D11_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_HAZARD                                              + 1
%D3D11_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETS_HAZARD                                            = %D3D11_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DEVICE_SOSETTARGETS_HAZARD                                                  = %D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETS_HAZARD                                            + 1
%D3D11_MESSAGE_ID_STRING_FROM_APPLICATION                                                     = %D3D11_MESSAGE_ID_DEVICE_SOSETTARGETS_HAZARD                                                  + 1
%D3D11_MESSAGE_ID_CORRUPTED_THIS                                                              = %D3D11_MESSAGE_ID_STRING_FROM_APPLICATION                                                     + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER1                                                        = %D3D11_MESSAGE_ID_CORRUPTED_THIS                                                              + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER2                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER1                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER3                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER2                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER4                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER3                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER5                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER4                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER6                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER5                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER7                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER6                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER8                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER7                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER9                                                        = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER8                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER10                                                       = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER9                                                        + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER11                                                       = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER10                                                       + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER12                                                       = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER11                                                       + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER13                                                       = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER12                                                       + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER14                                                       = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER13                                                       + 1
%D3D11_MESSAGE_ID_CORRUPTED_PARAMETER15                                                       = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER14                                                       + 1
%D3D11_MESSAGE_ID_CORRUPTED_MULTITHREADING                                                    = %D3D11_MESSAGE_ID_CORRUPTED_PARAMETER15                                                       + 1
%D3D11_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY                                               = %D3D11_MESSAGE_ID_CORRUPTED_MULTITHREADING                                                    + 1
%D3D11_MESSAGE_ID_IASETINPUTLAYOUT_UNBINDDELETINGOBJECT                                       = %D3D11_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY                                               + 1
%D3D11_MESSAGE_ID_IASETVERTEXBUFFERS_UNBINDDELETINGOBJECT                                     = %D3D11_MESSAGE_ID_IASETINPUTLAYOUT_UNBINDDELETINGOBJECT                                       + 1
%D3D11_MESSAGE_ID_IASETINDEXBUFFER_UNBINDDELETINGOBJECT                                       = %D3D11_MESSAGE_ID_IASETVERTEXBUFFERS_UNBINDDELETINGOBJECT                                     + 1
%D3D11_MESSAGE_ID_VSSETSHADER_UNBINDDELETINGOBJECT                                            = %D3D11_MESSAGE_ID_IASETINDEXBUFFER_UNBINDDELETINGOBJECT                                       + 1
%D3D11_MESSAGE_ID_VSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_VSSETSHADER_UNBINDDELETINGOBJECT                                            + 1
%D3D11_MESSAGE_ID_VSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_VSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_VSSETSAMPLERS_UNBINDDELETINGOBJECT                                          = %D3D11_MESSAGE_ID_VSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_GSSETSHADER_UNBINDDELETINGOBJECT                                            = %D3D11_MESSAGE_ID_VSSETSAMPLERS_UNBINDDELETINGOBJECT                                          + 1
%D3D11_MESSAGE_ID_GSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_GSSETSHADER_UNBINDDELETINGOBJECT                                            + 1
%D3D11_MESSAGE_ID_GSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_GSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_GSSETSAMPLERS_UNBINDDELETINGOBJECT                                          = %D3D11_MESSAGE_ID_GSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_SOSETTARGETS_UNBINDDELETINGOBJECT                                           = %D3D11_MESSAGE_ID_GSSETSAMPLERS_UNBINDDELETINGOBJECT                                          + 1
%D3D11_MESSAGE_ID_PSSETSHADER_UNBINDDELETINGOBJECT                                            = %D3D11_MESSAGE_ID_SOSETTARGETS_UNBINDDELETINGOBJECT                                           + 1
%D3D11_MESSAGE_ID_PSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_PSSETSHADER_UNBINDDELETINGOBJECT                                            + 1
%D3D11_MESSAGE_ID_PSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_PSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_PSSETSAMPLERS_UNBINDDELETINGOBJECT                                          = %D3D11_MESSAGE_ID_PSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_RSSETSTATE_UNBINDDELETINGOBJECT                                             = %D3D11_MESSAGE_ID_PSSETSAMPLERS_UNBINDDELETINGOBJECT                                          + 1
%D3D11_MESSAGE_ID_OMSETBLENDSTATE_UNBINDDELETINGOBJECT                                        = %D3D11_MESSAGE_ID_RSSETSTATE_UNBINDDELETINGOBJECT                                             + 1
%D3D11_MESSAGE_ID_OMSETDEPTHSTENCILSTATE_UNBINDDELETINGOBJECT                                 = %D3D11_MESSAGE_ID_OMSETBLENDSTATE_UNBINDDELETINGOBJECT                                        + 1
%D3D11_MESSAGE_ID_OMSETRENDERTARGETS_UNBINDDELETINGOBJECT                                     = %D3D11_MESSAGE_ID_OMSETDEPTHSTENCILSTATE_UNBINDDELETINGOBJECT                                 + 1
%D3D11_MESSAGE_ID_SETPREDICATION_UNBINDDELETINGOBJECT                                         = %D3D11_MESSAGE_ID_OMSETRENDERTARGETS_UNBINDDELETINGOBJECT                                     + 1
%D3D11_MESSAGE_ID_GETPRIVATEDATA_MOREDATA                                                     = %D3D11_MESSAGE_ID_SETPREDICATION_UNBINDDELETINGOBJECT                                         + 1
%D3D11_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA                                              = %D3D11_MESSAGE_ID_GETPRIVATEDATA_MOREDATA                                                     + 1
%D3D11_MESSAGE_ID_SETPRIVATEDATA_INVALIDIUNKNOWN                                              = %D3D11_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA                                              + 1
%D3D11_MESSAGE_ID_SETPRIVATEDATA_INVALIDFLAGS                                                 = %D3D11_MESSAGE_ID_SETPRIVATEDATA_INVALIDIUNKNOWN                                              + 1
%D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS                                               = %D3D11_MESSAGE_ID_SETPRIVATEDATA_INVALIDFLAGS                                                 + 1
%D3D11_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY                                                  = %D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS                                               + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDFORMAT                                             = %D3D11_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY                                                  + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDSAMPLES                                                 = %D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDFORMAT                                             + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDUSAGE                                              = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDSAMPLES                                                 + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDBINDFLAGS                                          = %D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDUSAGE                                              + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDCPUACCESSFLAGS                                     = %D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDBINDFLAGS                                          + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDMISCFLAGS                                          = %D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDCPUACCESSFLAGS                                     + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDCPUACCESSFLAGS                                          = %D3D11_MESSAGE_ID_CREATEBUFFER_UNRECOGNIZEDMISCFLAGS                                          + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDBINDFLAGS                                               = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDCPUACCESSFLAGS                                          + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDINITIALDATA                                             = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDBINDFLAGS                                               + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDDIMENSIONS                                              = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDINITIALDATA                                             + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDMIPLEVELS                                               = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDDIMENSIONS                                              + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDMISCFLAGS                                               = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDMIPLEVELS                                               + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDARG_RETURN                                              = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDMISCFLAGS                                               + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_OUTOFMEMORY_RETURN                                             = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDARG_RETURN                                              + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_NULLDESC                                                       = %D3D11_MESSAGE_ID_CREATEBUFFER_OUTOFMEMORY_RETURN                                             + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDCONSTANTBUFFERBINDINGS                                  = %D3D11_MESSAGE_ID_CREATEBUFFER_NULLDESC                                                       + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_LARGEALLOCATION                                                = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDCONSTANTBUFFERBINDINGS                                  + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDFORMAT                                          = %D3D11_MESSAGE_ID_CREATEBUFFER_LARGEALLOCATION                                                + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_UNSUPPORTEDFORMAT                                           = %D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDFORMAT                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDSAMPLES                                              = %D3D11_MESSAGE_ID_CREATETEXTURE1D_UNSUPPORTEDFORMAT                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDUSAGE                                           = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDSAMPLES                                              + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDBINDFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDUSAGE                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDCPUACCESSFLAGS                                  = %D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDBINDFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDMISCFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDCPUACCESSFLAGS                                  + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDCPUACCESSFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE1D_UNRECOGNIZEDMISCFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDBINDFLAGS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDCPUACCESSFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDINITIALDATA                                          = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDBINDFLAGS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDDIMENSIONS                                           = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDINITIALDATA                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDMIPLEVELS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDDIMENSIONS                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDMISCFLAGS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDMIPLEVELS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDARG_RETURN                                           = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDMISCFLAGS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_OUTOFMEMORY_RETURN                                          = %D3D11_MESSAGE_ID_CREATETEXTURE1D_INVALIDARG_RETURN                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_NULLDESC                                                    = %D3D11_MESSAGE_ID_CREATETEXTURE1D_OUTOFMEMORY_RETURN                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE1D_LARGEALLOCATION                                             = %D3D11_MESSAGE_ID_CREATETEXTURE1D_NULLDESC                                                    + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDFORMAT                                          = %D3D11_MESSAGE_ID_CREATETEXTURE1D_LARGEALLOCATION                                             + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_UNSUPPORTEDFORMAT                                           = %D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDFORMAT                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDSAMPLES                                              = %D3D11_MESSAGE_ID_CREATETEXTURE2D_UNSUPPORTEDFORMAT                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDUSAGE                                           = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDSAMPLES                                              + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDBINDFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDUSAGE                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDCPUACCESSFLAGS                                  = %D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDBINDFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDMISCFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDCPUACCESSFLAGS                                  + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDCPUACCESSFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE2D_UNRECOGNIZEDMISCFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDBINDFLAGS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDCPUACCESSFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDINITIALDATA                                          = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDBINDFLAGS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDDIMENSIONS                                           = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDINITIALDATA                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDMIPLEVELS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDDIMENSIONS                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDMISCFLAGS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDMIPLEVELS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDARG_RETURN                                           = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDMISCFLAGS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_OUTOFMEMORY_RETURN                                          = %D3D11_MESSAGE_ID_CREATETEXTURE2D_INVALIDARG_RETURN                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_NULLDESC                                                    = %D3D11_MESSAGE_ID_CREATETEXTURE2D_OUTOFMEMORY_RETURN                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE2D_LARGEALLOCATION                                             = %D3D11_MESSAGE_ID_CREATETEXTURE2D_NULLDESC                                                    + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDFORMAT                                          = %D3D11_MESSAGE_ID_CREATETEXTURE2D_LARGEALLOCATION                                             + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_UNSUPPORTEDFORMAT                                           = %D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDFORMAT                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDSAMPLES                                              = %D3D11_MESSAGE_ID_CREATETEXTURE3D_UNSUPPORTEDFORMAT                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDUSAGE                                           = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDSAMPLES                                              + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDBINDFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDUSAGE                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDCPUACCESSFLAGS                                  = %D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDBINDFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDMISCFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDCPUACCESSFLAGS                                  + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDCPUACCESSFLAGS                                       = %D3D11_MESSAGE_ID_CREATETEXTURE3D_UNRECOGNIZEDMISCFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDBINDFLAGS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDCPUACCESSFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDINITIALDATA                                          = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDBINDFLAGS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDDIMENSIONS                                           = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDINITIALDATA                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDMIPLEVELS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDDIMENSIONS                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDMISCFLAGS                                            = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDMIPLEVELS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDARG_RETURN                                           = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDMISCFLAGS                                            + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_OUTOFMEMORY_RETURN                                          = %D3D11_MESSAGE_ID_CREATETEXTURE3D_INVALIDARG_RETURN                                           + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_NULLDESC                                                    = %D3D11_MESSAGE_ID_CREATETEXTURE3D_OUTOFMEMORY_RETURN                                          + 1
%D3D11_MESSAGE_ID_CREATETEXTURE3D_LARGEALLOCATION                                             = %D3D11_MESSAGE_ID_CREATETEXTURE3D_NULLDESC                                                    + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT                                 = %D3D11_MESSAGE_ID_CREATETEXTURE3D_LARGEALLOCATION                                             + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC                                        = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT                                 + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT                                      = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC                                        + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS                                  = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT                                      + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE                                    = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS                                  + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_TOOMANYOBJECTS                                     = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE                                    + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDARG_RETURN                                  = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_TOOMANYOBJECTS                                     + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_OUTOFMEMORY_RETURN                                 = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDARG_RETURN                                  + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT                                   = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_OUTOFMEMORY_RETURN                                 + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT                                    = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT                                   + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC                                          = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT                                    + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT                                        = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC                                          + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS                                    = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT                                        + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE                                      = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS                                    + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_TOOMANYOBJECTS                                       = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE                                      + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDARG_RETURN                                    = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_TOOMANYOBJECTS                                       + 1
%D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_OUTOFMEMORY_RETURN                                   = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDARG_RETURN                                    + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT                                   = %D3D11_MESSAGE_ID_CREATERENDERTARGETVIEW_OUTOFMEMORY_RETURN                                   + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC                                          = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT                                   + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT                                        = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC                                          + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS                                    = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT                                        + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE                                      = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS                                    + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_TOOMANYOBJECTS                                       = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE                                      + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDARG_RETURN                                    = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_TOOMANYOBJECTS                                       + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_OUTOFMEMORY_RETURN                                   = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDARG_RETURN                                    + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY                                               = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_OUTOFMEMORY_RETURN                                   + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS                                           = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY                                               + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT                                             = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS                                           + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT                                        = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT                                             + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT                                               = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT                                        + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS                                     = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT                                               + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH                                 = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS                                     + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE                                    = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH                                 + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE                                     = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE                                    + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT                                          = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE                                     + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC                                         = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT                                          + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE                                 = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC                                         + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC                                              = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE                                 + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT                                            = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC                                              + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_NULLDESC                                                  = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT                                            + 1
%D3D11_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY                                              = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_NULLDESC                                                  + 1
%D3D11_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE                                    = %D3D11_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY                                              + 1
%D3D11_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE                                        = %D3D11_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE                                    + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY                                            = %D3D11_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE                                        + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE                                  = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY                                            + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE                                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE                                  + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY                            = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE                                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE                  = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY                            + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE                  + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED               = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDDECL                         = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED               + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_EXPECTEDDECL                           = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDDECL                         + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED                    = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_EXPECTEDDECL                           + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED                    + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT                  = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT                  = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT                  + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT                  + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION                   = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT                         = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION                   + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE              = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT                         + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC                        = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE              + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH                           = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC                        + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS                       = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH                           + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX                         = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS                       + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE                 = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX                         + 1
%D3D11_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY                                               = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE                 + 1
%D3D11_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE                                     = %D3D11_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY                                               + 1
%D3D11_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE                                         = %D3D11_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE                                     + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE                                       = %D3D11_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE                                         + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE                                       = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE                                       + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP                                 = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE                                       + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS                           = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP                                 + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_TOOMANYOBJECTS                                        = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS                           + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_NULLDESC                                              = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_TOOMANYOBJECTS                                        + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK                               = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_NULLDESC                                              + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC                                    = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK                               + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP                       = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC                                    + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP                      = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP                       + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP                       = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP                      + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC                         = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP                       + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP                        = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC                         + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP                       = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP                        + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP                        = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP                       + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC                          = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP                        + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_TOOMANYOBJECTS                                      = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC                          + 1
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_NULLDESC                                            = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_TOOMANYOBJECTS                                      + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND                                            = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_NULLDESC                                            + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND                                           = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND                                            + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP                                             = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND                                           + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA                                       = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP                                             + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA                                      = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA                                       + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA                                        = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA                                      + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK                               = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA                                        + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_TOOMANYOBJECTS                                             = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK                               + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_NULLDESC                                                   = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_TOOMANYOBJECTS                                             + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDFILTER                                            = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_NULLDESC                                                   + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSU                                          = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDFILTER                                            + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSV                                          = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSU                                          + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSW                                          = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSV                                          + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMIPLODBIAS                                        = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDADDRESSW                                          + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXANISOTROPY                                     = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMIPLODBIAS                                        + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDCOMPARISONFUNC                                    = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXANISOTROPY                                     + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMINLOD                                            = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDCOMPARISONFUNC                                    + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXLOD                                            = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMINLOD                                            + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_TOOMANYOBJECTS                                           = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_INVALIDMAXLOD                                            + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_NULLDESC                                                 = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_TOOMANYOBJECTS                                           + 1
%D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDQUERY                                         = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_NULLDESC                                                 + 1
%D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDMISCFLAGS                                     = %D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDQUERY                                         + 1
%D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_UNEXPECTEDMISCFLAG                                   = %D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_INVALIDMISCFLAGS                                     + 1
%D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_NULLDESC                                             = %D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_UNEXPECTEDMISCFLAG                                   + 1
%D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNRECOGNIZED                         = %D3D11_MESSAGE_ID_CREATEQUERYORPREDICATE_NULLDESC                                             + 1
%D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNDEFINED                            = %D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNRECOGNIZED                         + 1
%D3D11_MESSAGE_ID_IASETVERTEXBUFFERS_INVALIDBUFFER                                            = %D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNDEFINED                            + 1
%D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_OFFSET_TOO_LARGE                                  = %D3D11_MESSAGE_ID_IASETVERTEXBUFFERS_INVALIDBUFFER                                            + 1
%D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_BUFFERS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_OFFSET_TOO_LARGE                                  + 1
%D3D11_MESSAGE_ID_IASETINDEXBUFFER_INVALIDBUFFER                                              = %D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_BUFFERS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_FORMAT_INVALID                                      = %D3D11_MESSAGE_ID_IASETINDEXBUFFER_INVALIDBUFFER                                              + 1
%D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_TOO_LARGE                                    = %D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_FORMAT_INVALID                                      + 1
%D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_UNALIGNED                                    = %D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_TOO_LARGE                                    + 1
%D3D11_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_IASETINDEXBUFFER_OFFSET_UNALIGNED                                    + 1
%D3D11_MESSAGE_ID_VSSETCONSTANTBUFFERS_INVALIDBUFFER                                          = %D3D11_MESSAGE_ID_DEVICE_VSSETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_VSSETCONSTANTBUFFERS_INVALIDBUFFER                                          + 1
%D3D11_MESSAGE_ID_DEVICE_VSSETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_VSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_VSSETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_GSSETCONSTANTBUFFERS_INVALIDBUFFER                                          = %D3D11_MESSAGE_ID_DEVICE_GSSETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_GSSETCONSTANTBUFFERS_INVALIDBUFFER                                          + 1
%D3D11_MESSAGE_ID_DEVICE_GSSETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_GSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_SOSETTARGETS_INVALIDBUFFER                                                  = %D3D11_MESSAGE_ID_DEVICE_GSSETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_SOSETTARGETS_OFFSET_UNALIGNED                                        = %D3D11_MESSAGE_ID_SOSETTARGETS_INVALIDBUFFER                                                  + 1
%D3D11_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_SOSETTARGETS_OFFSET_UNALIGNED                                        + 1
%D3D11_MESSAGE_ID_PSSETCONSTANTBUFFERS_INVALIDBUFFER                                          = %D3D11_MESSAGE_ID_DEVICE_PSSETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_PSSETCONSTANTBUFFERS_INVALIDBUFFER                                          + 1
%D3D11_MESSAGE_ID_DEVICE_PSSETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_PSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_INVALIDVIEWPORT                                       = %D3D11_MESSAGE_ID_DEVICE_PSSETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_INVALIDSCISSOR                                     = %D3D11_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_INVALIDVIEWPORT                                       + 1
%D3D11_MESSAGE_ID_CLEARRENDERTARGETVIEW_DENORMFLUSH                                           = %D3D11_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_INVALIDSCISSOR                                     + 1
%D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_DENORMFLUSH                                           = %D3D11_MESSAGE_ID_CLEARRENDERTARGETVIEW_DENORMFLUSH                                           + 1
%D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID                                               = %D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_DENORMFLUSH                                           + 1
%D3D11_MESSAGE_ID_DEVICE_IAGETVERTEXBUFFERS_BUFFERS_EMPTY                                     = %D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID                                               + 1
%D3D11_MESSAGE_ID_DEVICE_VSGETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_IAGETVERTEXBUFFERS_BUFFERS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_VSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DEVICE_VSGETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_VSGETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_VSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_GSGETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_VSGETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_GSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DEVICE_GSGETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_GSGETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_GSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_SOGETTARGETS_BUFFERS_EMPTY                                           = %D3D11_MESSAGE_ID_DEVICE_GSGETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_PSGETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_SOGETTARGETS_BUFFERS_EMPTY                                           + 1
%D3D11_MESSAGE_ID_DEVICE_PSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DEVICE_PSGETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_PSGETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_PSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_RSGETVIEWPORTS_VIEWPORTS_EMPTY                                       = %D3D11_MESSAGE_ID_DEVICE_PSGETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_RSGETSCISSORRECTS_RECTS_EMPTY                                        = %D3D11_MESSAGE_ID_DEVICE_RSGETVIEWPORTS_VIEWPORTS_EMPTY                                       + 1
%D3D11_MESSAGE_ID_DEVICE_GENERATEMIPS_RESOURCE_INVALID                                        = %D3D11_MESSAGE_ID_DEVICE_RSGETSCISSORRECTS_RECTS_EMPTY                                        + 1
%D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSUBRESOURCE                         = %D3D11_MESSAGE_ID_DEVICE_GENERATEMIPS_RESOURCE_INVALID                                        + 1
%D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESUBRESOURCE                              = %D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSUBRESOURCE                         + 1
%D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCEBOX                                      = %D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESUBRESOURCE                              + 1
%D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCE                                         = %D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCEBOX                                      + 1
%D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSTATE                               = %D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCE                                         + 1
%D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESTATE                                    = %D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDDESTINATIONSTATE                               + 1
%D3D11_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCE                                                  = %D3D11_MESSAGE_ID_COPYSUBRESOURCEREGION_INVALIDSOURCESTATE                                    + 1
%D3D11_MESSAGE_ID_COPYRESOURCE_INVALIDDESTINATIONSTATE                                        = %D3D11_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCE                                                  + 1
%D3D11_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCESTATE                                             = %D3D11_MESSAGE_ID_COPYRESOURCE_INVALIDDESTINATIONSTATE                                        + 1
%D3D11_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSUBRESOURCE                             = %D3D11_MESSAGE_ID_COPYRESOURCE_INVALIDSOURCESTATE                                             + 1
%D3D11_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONBOX                                     = %D3D11_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSUBRESOURCE                             + 1
%D3D11_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSTATE                                   = %D3D11_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONBOX                                     + 1
%D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_INVALID                               = %D3D11_MESSAGE_ID_UPDATESUBRESOURCE_INVALIDDESTINATIONSTATE                                   + 1
%D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_SUBRESOURCE_INVALID                   = %D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_INVALID                               + 1
%D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_INVALID                                    = %D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_DESTINATION_SUBRESOURCE_INVALID                   + 1
%D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_SUBRESOURCE_INVALID                        = %D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_INVALID                                    + 1
%D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_FORMAT_INVALID                                    = %D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_SOURCE_SUBRESOURCE_INVALID                        + 1
%D3D11_MESSAGE_ID_BUFFER_MAP_INVALIDMAPTYPE                                                   = %D3D11_MESSAGE_ID_DEVICE_RESOLVESUBRESOURCE_FORMAT_INVALID                                    + 1
%D3D11_MESSAGE_ID_BUFFER_MAP_INVALIDFLAGS                                                     = %D3D11_MESSAGE_ID_BUFFER_MAP_INVALIDMAPTYPE                                                   + 1
%D3D11_MESSAGE_ID_BUFFER_MAP_ALREADYMAPPED                                                    = %D3D11_MESSAGE_ID_BUFFER_MAP_INVALIDFLAGS                                                     + 1
%D3D11_MESSAGE_ID_BUFFER_MAP_DEVICEREMOVED_RETURN                                             = %D3D11_MESSAGE_ID_BUFFER_MAP_ALREADYMAPPED                                                    + 1
%D3D11_MESSAGE_ID_BUFFER_UNMAP_NOTMAPPED                                                      = %D3D11_MESSAGE_ID_BUFFER_MAP_DEVICEREMOVED_RETURN                                             + 1
%D3D11_MESSAGE_ID_TEXTURE1D_MAP_INVALIDMAPTYPE                                                = %D3D11_MESSAGE_ID_BUFFER_UNMAP_NOTMAPPED                                                      + 1
%D3D11_MESSAGE_ID_TEXTURE1D_MAP_INVALIDSUBRESOURCE                                            = %D3D11_MESSAGE_ID_TEXTURE1D_MAP_INVALIDMAPTYPE                                                + 1
%D3D11_MESSAGE_ID_TEXTURE1D_MAP_INVALIDFLAGS                                                  = %D3D11_MESSAGE_ID_TEXTURE1D_MAP_INVALIDSUBRESOURCE                                            + 1
%D3D11_MESSAGE_ID_TEXTURE1D_MAP_ALREADYMAPPED                                                 = %D3D11_MESSAGE_ID_TEXTURE1D_MAP_INVALIDFLAGS                                                  + 1
%D3D11_MESSAGE_ID_TEXTURE1D_MAP_DEVICEREMOVED_RETURN                                          = %D3D11_MESSAGE_ID_TEXTURE1D_MAP_ALREADYMAPPED                                                 + 1
%D3D11_MESSAGE_ID_TEXTURE1D_UNMAP_INVALIDSUBRESOURCE                                          = %D3D11_MESSAGE_ID_TEXTURE1D_MAP_DEVICEREMOVED_RETURN                                          + 1
%D3D11_MESSAGE_ID_TEXTURE1D_UNMAP_NOTMAPPED                                                   = %D3D11_MESSAGE_ID_TEXTURE1D_UNMAP_INVALIDSUBRESOURCE                                          + 1
%D3D11_MESSAGE_ID_TEXTURE2D_MAP_INVALIDMAPTYPE                                                = %D3D11_MESSAGE_ID_TEXTURE1D_UNMAP_NOTMAPPED                                                   + 1
%D3D11_MESSAGE_ID_TEXTURE2D_MAP_INVALIDSUBRESOURCE                                            = %D3D11_MESSAGE_ID_TEXTURE2D_MAP_INVALIDMAPTYPE                                                + 1
%D3D11_MESSAGE_ID_TEXTURE2D_MAP_INVALIDFLAGS                                                  = %D3D11_MESSAGE_ID_TEXTURE2D_MAP_INVALIDSUBRESOURCE                                            + 1
%D3D11_MESSAGE_ID_TEXTURE2D_MAP_ALREADYMAPPED                                                 = %D3D11_MESSAGE_ID_TEXTURE2D_MAP_INVALIDFLAGS                                                  + 1
%D3D11_MESSAGE_ID_TEXTURE2D_MAP_DEVICEREMOVED_RETURN                                          = %D3D11_MESSAGE_ID_TEXTURE2D_MAP_ALREADYMAPPED                                                 + 1
%D3D11_MESSAGE_ID_TEXTURE2D_UNMAP_INVALIDSUBRESOURCE                                          = %D3D11_MESSAGE_ID_TEXTURE2D_MAP_DEVICEREMOVED_RETURN                                          + 1
%D3D11_MESSAGE_ID_TEXTURE2D_UNMAP_NOTMAPPED                                                   = %D3D11_MESSAGE_ID_TEXTURE2D_UNMAP_INVALIDSUBRESOURCE                                          + 1
%D3D11_MESSAGE_ID_TEXTURE3D_MAP_INVALIDMAPTYPE                                                = %D3D11_MESSAGE_ID_TEXTURE2D_UNMAP_NOTMAPPED                                                   + 1
%D3D11_MESSAGE_ID_TEXTURE3D_MAP_INVALIDSUBRESOURCE                                            = %D3D11_MESSAGE_ID_TEXTURE3D_MAP_INVALIDMAPTYPE                                                + 1
%D3D11_MESSAGE_ID_TEXTURE3D_MAP_INVALIDFLAGS                                                  = %D3D11_MESSAGE_ID_TEXTURE3D_MAP_INVALIDSUBRESOURCE                                            + 1
%D3D11_MESSAGE_ID_TEXTURE3D_MAP_ALREADYMAPPED                                                 = %D3D11_MESSAGE_ID_TEXTURE3D_MAP_INVALIDFLAGS                                                  + 1
%D3D11_MESSAGE_ID_TEXTURE3D_MAP_DEVICEREMOVED_RETURN                                          = %D3D11_MESSAGE_ID_TEXTURE3D_MAP_ALREADYMAPPED                                                 + 1
%D3D11_MESSAGE_ID_TEXTURE3D_UNMAP_INVALIDSUBRESOURCE                                          = %D3D11_MESSAGE_ID_TEXTURE3D_MAP_DEVICEREMOVED_RETURN                                          + 1
%D3D11_MESSAGE_ID_TEXTURE3D_UNMAP_NOTMAPPED                                                   = %D3D11_MESSAGE_ID_TEXTURE3D_UNMAP_INVALIDSUBRESOURCE                                          + 1
%D3D11_MESSAGE_ID_CHECKFORMATSUPPORT_FORMAT_DEPRECATED                                        = %D3D11_MESSAGE_ID_TEXTURE3D_UNMAP_NOTMAPPED                                                   + 1
%D3D11_MESSAGE_ID_CHECKMULTISAMPLEQUALITYLEVELS_FORMAT_DEPRECATED                             = %D3D11_MESSAGE_ID_CHECKFORMATSUPPORT_FORMAT_DEPRECATED                                        + 1
%D3D11_MESSAGE_ID_SETEXCEPTIONMODE_UNRECOGNIZEDFLAGS                                          = %D3D11_MESSAGE_ID_CHECKMULTISAMPLEQUALITYLEVELS_FORMAT_DEPRECATED                             + 1
%D3D11_MESSAGE_ID_SETEXCEPTIONMODE_INVALIDARG_RETURN                                          = %D3D11_MESSAGE_ID_SETEXCEPTIONMODE_UNRECOGNIZEDFLAGS                                          + 1
%D3D11_MESSAGE_ID_SETEXCEPTIONMODE_DEVICEREMOVED_RETURN                                       = %D3D11_MESSAGE_ID_SETEXCEPTIONMODE_INVALIDARG_RETURN                                          + 1
%D3D11_MESSAGE_ID_REF_SIMULATING_INFINITELY_FAST_HARDWARE                                     = %D3D11_MESSAGE_ID_SETEXCEPTIONMODE_DEVICEREMOVED_RETURN                                       + 1
%D3D11_MESSAGE_ID_REF_THREADING_MODE                                                          = %D3D11_MESSAGE_ID_REF_SIMULATING_INFINITELY_FAST_HARDWARE                                     + 1
%D3D11_MESSAGE_ID_REF_UMDRIVER_EXCEPTION                                                      = %D3D11_MESSAGE_ID_REF_THREADING_MODE                                                          + 1
%D3D11_MESSAGE_ID_REF_KMDRIVER_EXCEPTION                                                      = %D3D11_MESSAGE_ID_REF_UMDRIVER_EXCEPTION                                                      + 1
%D3D11_MESSAGE_ID_REF_HARDWARE_EXCEPTION                                                      = %D3D11_MESSAGE_ID_REF_KMDRIVER_EXCEPTION                                                      + 1
%D3D11_MESSAGE_ID_REF_ACCESSING_INDEXABLE_TEMP_OUT_OF_RANGE                                   = %D3D11_MESSAGE_ID_REF_HARDWARE_EXCEPTION                                                      + 1
%D3D11_MESSAGE_ID_REF_PROBLEM_PARSING_SHADER                                                  = %D3D11_MESSAGE_ID_REF_ACCESSING_INDEXABLE_TEMP_OUT_OF_RANGE                                   + 1
%D3D11_MESSAGE_ID_REF_OUT_OF_MEMORY                                                           = %D3D11_MESSAGE_ID_REF_PROBLEM_PARSING_SHADER                                                  + 1
%D3D11_MESSAGE_ID_REF_INFO                                                                    = %D3D11_MESSAGE_ID_REF_OUT_OF_MEMORY                                                           + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEXPOS_OVERFLOW                                              = %D3D11_MESSAGE_ID_REF_INFO                                                                    + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINDEXED_INDEXPOS_OVERFLOW                                        = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEXPOS_OVERFLOW                                              + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINSTANCED_VERTEXPOS_OVERFLOW                                     = %D3D11_MESSAGE_ID_DEVICE_DRAWINDEXED_INDEXPOS_OVERFLOW                                        + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINSTANCED_INSTANCEPOS_OVERFLOW                                   = %D3D11_MESSAGE_ID_DEVICE_DRAWINSTANCED_VERTEXPOS_OVERFLOW                                     + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INSTANCEPOS_OVERFLOW                            = %D3D11_MESSAGE_ID_DEVICE_DRAWINSTANCED_INSTANCEPOS_OVERFLOW                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INDEXPOS_OVERFLOW                               = %D3D11_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INSTANCEPOS_OVERFLOW                            + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_SHADER_NOT_SET                                           = %D3D11_MESSAGE_ID_DEVICE_DRAWINDEXEDINSTANCED_INDEXPOS_OVERFLOW                               + 1
%D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND                                = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_SHADER_NOT_SET                                           + 1
%D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERINDEX                                         = %D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND                                + 1
%D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_COMPONENTTYPE                                         = %D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERINDEX                                         + 1
%D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERMASK                                          = %D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_COMPONENTTYPE                                         + 1
%D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SYSTEMVALUE                                           = %D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_REGISTERMASK                                          + 1
%D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS                              = %D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_SYSTEMVALUE                                           + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_NOT_SET                                           = %D3D11_MESSAGE_ID_DEVICE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS                              + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INPUTLAYOUT_NOT_SET                                             = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_NOT_SET                                           + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_NOT_SET                                         = %D3D11_MESSAGE_ID_DEVICE_DRAW_INPUTLAYOUT_NOT_SET                                             + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_TOO_SMALL                                       = %D3D11_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_NOT_SET                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_SAMPLER_NOT_SET                                                 = %D3D11_MESSAGE_ID_DEVICE_DRAW_CONSTANT_BUFFER_TOO_SMALL                                       + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_SHADERRESOURCEVIEW_NOT_SET                                      = %D3D11_MESSAGE_ID_DEVICE_DRAW_SAMPLER_NOT_SET                                                 + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VIEW_DIMENSION_MISMATCH                                         = %D3D11_MESSAGE_ID_DEVICE_DRAW_SHADERRESOURCEVIEW_NOT_SET                                      + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL                                  = %D3D11_MESSAGE_ID_DEVICE_DRAW_VIEW_DIMENSION_MISMATCH                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_TOO_SMALL                                         = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL                                  + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_NOT_SET                                            = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_BUFFER_TOO_SMALL                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_FORMAT_INVALID                                     = %D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_NOT_SET                                            + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_TOO_SMALL                                          = %D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_FORMAT_INVALID                                     + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_GS_INPUT_PRIMITIVE_MISMATCH                                     = %D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_BUFFER_TOO_SMALL                                          + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_RETURN_TYPE_MISMATCH                                   = %D3D11_MESSAGE_ID_DEVICE_DRAW_GS_INPUT_PRIMITIVE_MISMATCH                                     + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_POSITION_NOT_PRESENT                                            = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_RETURN_TYPE_MISMATCH                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_NOT_SET                                           = %D3D11_MESSAGE_ID_DEVICE_DRAW_POSITION_NOT_PRESENT                                            + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_BOUND_RESOURCE_MAPPED                                           = %D3D11_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_NOT_SET                                           + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INVALID_PRIMITIVETOPOLOGY                                       = %D3D11_MESSAGE_ID_DEVICE_DRAW_BOUND_RESOURCE_MAPPED                                           + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_OFFSET_UNALIGNED                                         = %D3D11_MESSAGE_ID_DEVICE_DRAW_INVALID_PRIMITIVETOPOLOGY                                       + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_STRIDE_UNALIGNED                                         = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_OFFSET_UNALIGNED                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_OFFSET_UNALIGNED                                          = %D3D11_MESSAGE_ID_DEVICE_DRAW_VERTEX_STRIDE_UNALIGNED                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_OFFSET_UNALIGNED                                  = %D3D11_MESSAGE_ID_DEVICE_DRAW_INDEX_OFFSET_UNALIGNED                                          + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_LD_UNSUPPORTED                                  = %D3D11_MESSAGE_ID_DEVICE_DRAW_OUTPUT_STREAM_OFFSET_UNALIGNED                                  + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_UNSUPPORTED                              = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_LD_UNSUPPORTED                                  + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_C_UNSUPPORTED                            = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_UNSUPPORTED                              + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_MULTISAMPLE_UNSUPPORTED                                = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_SAMPLE_C_UNSUPPORTED                            + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_SO_TARGETS_BOUND_WITHOUT_SOURCE                                 = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_MULTISAMPLE_UNSUPPORTED                                + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_SO_STRIDE_LARGER_THAN_BUFFER                                    = %D3D11_MESSAGE_ID_DEVICE_DRAW_SO_TARGETS_BOUND_WITHOUT_SOURCE                                 + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING                      = %D3D11_MESSAGE_ID_DEVICE_DRAW_SO_STRIDE_LARGER_THAN_BUFFER                                    + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0           = %D3D11_MESSAGE_ID_DEVICE_DRAW_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING                      + 1
%D3D11_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT                                             = %D3D11_MESSAGE_ID_DEVICE_DRAW_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0           + 1
%D3D11_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT                                    = %D3D11_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT                                             + 1
%D3D11_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT                                         = %D3D11_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT                                    + 1
%D3D11_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_INVALIDARG_RETURN                               = %D3D11_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT                                         + 1
%D3D11_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_OUTOFMEMORY_RETURN                              = %D3D11_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_INVALIDARG_RETURN                               + 1
%D3D11_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_BADINTERFACE_RETURN                             = %D3D11_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_OUTOFMEMORY_RETURN                              + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_VIEWPORT_NOT_SET                                                = %D3D11_MESSAGE_ID_DEVICE_OPEN_SHARED_RESOURCE_BADINTERFACE_RETURN                             + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC                                = %D3D11_MESSAGE_ID_DEVICE_DRAW_VIEWPORT_NOT_SET                                                + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC             = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC                                + 1
%D3D11_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_DENORMFLUSH                                           = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC             + 1
%D3D11_MESSAGE_ID_OMSETRENDERTARGETS_INVALIDVIEW                                              = %D3D11_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_DENORMFLUSH                                           + 1
%D3D11_MESSAGE_ID_DEVICE_SETTEXTFILTERSIZE_INVALIDDIMENSIONS                                  = %D3D11_MESSAGE_ID_OMSETRENDERTARGETS_INVALIDVIEW                                              + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_SAMPLER_MISMATCH                                                = %D3D11_MESSAGE_ID_DEVICE_SETTEXTFILTERSIZE_INVALIDDIMENSIONS                                  + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH                                             = %D3D11_MESSAGE_ID_DEVICE_DRAW_SAMPLER_MISMATCH                                                + 1
%D3D11_MESSAGE_ID_BLENDSTATE_GETDESC_LEGACY                                                   = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH                                             + 1
%D3D11_MESSAGE_ID_SHADERRESOURCEVIEW_GETDESC_LEGACY                                           = %D3D11_MESSAGE_ID_BLENDSTATE_GETDESC_LEGACY                                                   + 1
%D3D11_MESSAGE_ID_CREATEQUERY_OUTOFMEMORY_RETURN                                              = %D3D11_MESSAGE_ID_SHADERRESOURCEVIEW_GETDESC_LEGACY                                           + 1
%D3D11_MESSAGE_ID_CREATEPREDICATE_OUTOFMEMORY_RETURN                                          = %D3D11_MESSAGE_ID_CREATEQUERY_OUTOFMEMORY_RETURN                                              + 1
%D3D11_MESSAGE_ID_CREATECOUNTER_OUTOFRANGE_COUNTER                                            = %D3D11_MESSAGE_ID_CREATEPREDICATE_OUTOFMEMORY_RETURN                                          + 1
%D3D11_MESSAGE_ID_CREATECOUNTER_SIMULTANEOUS_ACTIVE_COUNTERS_EXHAUSTED                        = %D3D11_MESSAGE_ID_CREATECOUNTER_OUTOFRANGE_COUNTER                                            + 1
%D3D11_MESSAGE_ID_CREATECOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER                                 = %D3D11_MESSAGE_ID_CREATECOUNTER_SIMULTANEOUS_ACTIVE_COUNTERS_EXHAUSTED                        + 1
%D3D11_MESSAGE_ID_CREATECOUNTER_OUTOFMEMORY_RETURN                                            = %D3D11_MESSAGE_ID_CREATECOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER                                 + 1
%D3D11_MESSAGE_ID_CREATECOUNTER_NONEXCLUSIVE_RETURN                                           = %D3D11_MESSAGE_ID_CREATECOUNTER_OUTOFMEMORY_RETURN                                            + 1
%D3D11_MESSAGE_ID_CREATECOUNTER_NULLDESC                                                      = %D3D11_MESSAGE_ID_CREATECOUNTER_NONEXCLUSIVE_RETURN                                           + 1
%D3D11_MESSAGE_ID_CHECKCOUNTER_OUTOFRANGE_COUNTER                                             = %D3D11_MESSAGE_ID_CREATECOUNTER_NULLDESC                                                      + 1
%D3D11_MESSAGE_ID_CHECKCOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER                                  = %D3D11_MESSAGE_ID_CHECKCOUNTER_OUTOFRANGE_COUNTER                                             + 1
%D3D11_MESSAGE_ID_SETPREDICATION_INVALID_PREDICATE_STATE                                      = %D3D11_MESSAGE_ID_CHECKCOUNTER_UNSUPPORTED_WELLKNOWN_COUNTER                                  + 1
%D3D11_MESSAGE_ID_QUERY_BEGIN_UNSUPPORTED                                                     = %D3D11_MESSAGE_ID_SETPREDICATION_INVALID_PREDICATE_STATE                                      + 1
%D3D11_MESSAGE_ID_PREDICATE_BEGIN_DURING_PREDICATION                                          = %D3D11_MESSAGE_ID_QUERY_BEGIN_UNSUPPORTED                                                     + 1
%D3D11_MESSAGE_ID_QUERY_BEGIN_DUPLICATE                                                       = %D3D11_MESSAGE_ID_PREDICATE_BEGIN_DURING_PREDICATION                                          + 1
%D3D11_MESSAGE_ID_QUERY_BEGIN_ABANDONING_PREVIOUS_RESULTS                                     = %D3D11_MESSAGE_ID_QUERY_BEGIN_DUPLICATE                                                       + 1
%D3D11_MESSAGE_ID_PREDICATE_END_DURING_PREDICATION                                            = %D3D11_MESSAGE_ID_QUERY_BEGIN_ABANDONING_PREVIOUS_RESULTS                                     + 1
%D3D11_MESSAGE_ID_QUERY_END_ABANDONING_PREVIOUS_RESULTS                                       = %D3D11_MESSAGE_ID_PREDICATE_END_DURING_PREDICATION                                            + 1
%D3D11_MESSAGE_ID_QUERY_END_WITHOUT_BEGIN                                                     = %D3D11_MESSAGE_ID_QUERY_END_ABANDONING_PREVIOUS_RESULTS                                       + 1
%D3D11_MESSAGE_ID_QUERY_GETDATA_INVALID_DATASIZE                                              = %D3D11_MESSAGE_ID_QUERY_END_WITHOUT_BEGIN                                                     + 1
%D3D11_MESSAGE_ID_QUERY_GETDATA_INVALID_FLAGS                                                 = %D3D11_MESSAGE_ID_QUERY_GETDATA_INVALID_DATASIZE                                              + 1
%D3D11_MESSAGE_ID_QUERY_GETDATA_INVALID_CALL                                                  = %D3D11_MESSAGE_ID_QUERY_GETDATA_INVALID_FLAGS                                                 + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_PS_OUTPUT_TYPE_MISMATCH                                         = %D3D11_MESSAGE_ID_QUERY_GETDATA_INVALID_CALL                                                  + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_GATHER_UNSUPPORTED                              = %D3D11_MESSAGE_ID_DEVICE_DRAW_PS_OUTPUT_TYPE_MISMATCH                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_INVALID_USE_OF_CENTER_MULTISAMPLE_PATTERN                       = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_FORMAT_GATHER_UNSUPPORTED                              + 1
%D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_STRIDE_TOO_LARGE                                  = %D3D11_MESSAGE_ID_DEVICE_DRAW_INVALID_USE_OF_CENTER_MULTISAMPLE_PATTERN                       + 1
%D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_INVALIDRANGE                                      = %D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_STRIDE_TOO_LARGE                                  + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_EMPTY_LAYOUT                                              = %D3D11_MESSAGE_ID_DEVICE_IASETVERTEXBUFFERS_INVALIDRANGE                                      + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_SAMPLE_COUNT_MISMATCH                                  = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_EMPTY_LAYOUT                                              + 1
%D3D11_MESSAGE_ID_D3D10_MESSAGES_END                                                          = %D3D11_MESSAGE_ID_DEVICE_DRAW_RESOURCE_SAMPLE_COUNT_MISMATCH                                  + 1
%D3D11_MESSAGE_ID_D3D10L9_MESSAGES_START                                                      = &H100000
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_STENCIL_NO_TWO_SIDED                                = %D3D11_MESSAGE_ID_D3D10L9_MESSAGES_START                                                      + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_DepthBiasClamp_NOT_SUPPORTED                          = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_STENCIL_NO_TWO_SIDED                                + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_NO_COMPARISON_SUPPORT                                    = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_DepthBiasClamp_NOT_SUPPORTED                          + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_EXCESSIVE_ANISOTROPY                                     = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_NO_COMPARISON_SUPPORT                                    + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_BORDER_OUT_OF_RANGE                                      = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_EXCESSIVE_ANISOTROPY                                     + 1
%D3D11_MESSAGE_ID_VSSETSAMPLERS_NOT_SUPPORTED                                                 = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_BORDER_OUT_OF_RANGE                                      + 1
%D3D11_MESSAGE_ID_VSSETSAMPLERS_TOO_MANY_SAMPLERS                                             = %D3D11_MESSAGE_ID_VSSETSAMPLERS_NOT_SUPPORTED                                                 + 1
%D3D11_MESSAGE_ID_PSSETSAMPLERS_TOO_MANY_SAMPLERS                                             = %D3D11_MESSAGE_ID_VSSETSAMPLERS_TOO_MANY_SAMPLERS                                             + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NO_ARRAYS                                                    = %D3D11_MESSAGE_ID_PSSETSAMPLERS_TOO_MANY_SAMPLERS                                             + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NO_VB_AND_IB_BIND                                            = %D3D11_MESSAGE_ID_CREATERESOURCE_NO_ARRAYS                                                    + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NO_TEXTURE_1D                                                = %D3D11_MESSAGE_ID_CREATERESOURCE_NO_VB_AND_IB_BIND                                            + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_DIMENSION_OUT_OF_RANGE                                       = %D3D11_MESSAGE_ID_CREATERESOURCE_NO_TEXTURE_1D                                                + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NOT_BINDABLE_AS_SHADER_RESOURCE                              = %D3D11_MESSAGE_ID_CREATERESOURCE_DIMENSION_OUT_OF_RANGE                                       + 1
%D3D11_MESSAGE_ID_OMSETRENDERTARGETS_TOO_MANY_RENDER_TARGETS                                  = %D3D11_MESSAGE_ID_CREATERESOURCE_NOT_BINDABLE_AS_SHADER_RESOURCE                              + 1
%D3D11_MESSAGE_ID_OMSETRENDERTARGETS_NO_DIFFERING_BIT_DEPTHS                                  = %D3D11_MESSAGE_ID_OMSETRENDERTARGETS_TOO_MANY_RENDER_TARGETS                                  + 1
%D3D11_MESSAGE_ID_IASETVERTEXBUFFERS_BAD_BUFFER_INDEX                                         = %D3D11_MESSAGE_ID_OMSETRENDERTARGETS_NO_DIFFERING_BIT_DEPTHS                                  + 1
%D3D11_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_TOO_MANY_VIEWPORTS                                    = %D3D11_MESSAGE_ID_IASETVERTEXBUFFERS_BAD_BUFFER_INDEX                                         + 1
%D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_ADJACENCY_UNSUPPORTED                         = %D3D11_MESSAGE_ID_DEVICE_RSSETVIEWPORTS_TOO_MANY_VIEWPORTS                                    + 1
%D3D11_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_TOO_MANY_SCISSORS                                  = %D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_ADJACENCY_UNSUPPORTED                         + 1
%D3D11_MESSAGE_ID_COPYRESOURCE_ONLY_TEXTURE_2D_WITHIN_GPU_MEMORY                              = %D3D11_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_TOO_MANY_SCISSORS                                  + 1
%D3D11_MESSAGE_ID_COPYRESOURCE_NO_TEXTURE_3D_READBACK                                         = %D3D11_MESSAGE_ID_COPYRESOURCE_ONLY_TEXTURE_2D_WITHIN_GPU_MEMORY                              + 1
%D3D11_MESSAGE_ID_COPYRESOURCE_NO_TEXTURE_ONLY_READBACK                                       = %D3D11_MESSAGE_ID_COPYRESOURCE_NO_TEXTURE_3D_READBACK                                         + 1
%D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_UNSUPPORTED_FORMAT                                        = %D3D11_MESSAGE_ID_COPYRESOURCE_NO_TEXTURE_ONLY_READBACK                                       + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_ALPHA_TO_COVERAGE                                       = %D3D11_MESSAGE_ID_CREATEINPUTLAYOUT_UNSUPPORTED_FORMAT                                        + 1
%D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_DepthClipEnable_MUST_BE_TRUE                          = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_ALPHA_TO_COVERAGE                                       + 1
%D3D11_MESSAGE_ID_DRAWINDEXED_STARTINDEXLOCATION_MUST_BE_POSITIVE                             = %D3D11_MESSAGE_ID_CREATERASTERIZERSTATE_DepthClipEnable_MUST_BE_TRUE                          + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_MUST_USE_LOWEST_LOD                                = %D3D11_MESSAGE_ID_DRAWINDEXED_STARTINDEXLOCATION_MUST_BE_POSITIVE                             + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_MINLOD_MUST_NOT_BE_FRACTIONAL                            = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_MUST_USE_LOWEST_LOD                                + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_MAXLOD_MUST_BE_FLT_MAX                                   = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_MINLOD_MUST_NOT_BE_FRACTIONAL                            + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_FIRSTARRAYSLICE_MUST_BE_ZERO                       = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_MAXLOD_MUST_BE_FLT_MAX                                   + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_CUBES_MUST_HAVE_6_SIDES                            = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_FIRSTARRAYSLICE_MUST_BE_ZERO                       + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NOT_BINDABLE_AS_RENDER_TARGET                                = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_CUBES_MUST_HAVE_6_SIDES                            + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NO_DWORD_INDEX_BUFFER                                        = %D3D11_MESSAGE_ID_CREATERESOURCE_NOT_BINDABLE_AS_RENDER_TARGET                                + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_MSAA_PRECLUDES_SHADER_RESOURCE                               = %D3D11_MESSAGE_ID_CREATERESOURCE_NO_DWORD_INDEX_BUFFER                                        + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_PRESENTATION_PRECLUDES_SHADER_RESOURCE                       = %D3D11_MESSAGE_ID_CREATERESOURCE_MSAA_PRECLUDES_SHADER_RESOURCE                               + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_INDEPENDENT_BLEND_ENABLE                                = %D3D11_MESSAGE_ID_CREATERESOURCE_PRESENTATION_PRECLUDES_SHADER_RESOURCE                       + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_INDEPENDENT_WRITE_MASKS                                 = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_INDEPENDENT_BLEND_ENABLE                                + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NO_STREAM_OUT                                                = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_INDEPENDENT_WRITE_MASKS                                 + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_ONLY_VB_IB_FOR_BUFFERS                                       = %D3D11_MESSAGE_ID_CREATERESOURCE_NO_STREAM_OUT                                                + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NO_AUTOGEN_FOR_VOLUMES                                       = %D3D11_MESSAGE_ID_CREATERESOURCE_ONLY_VB_IB_FOR_BUFFERS                                       + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_DXGI_FORMAT_R8G8B8A8_CANNOT_BE_SHARED                        = %D3D11_MESSAGE_ID_CREATERESOURCE_NO_AUTOGEN_FOR_VOLUMES                                       + 1
%D3D11_MESSAGE_ID_VSSHADERRESOURCES_NOT_SUPPORTED                                             = %D3D11_MESSAGE_ID_CREATERESOURCE_DXGI_FORMAT_R8G8B8A8_CANNOT_BE_SHARED                        + 1
%D3D11_MESSAGE_ID_GEOMETRY_SHADER_NOT_SUPPORTED                                               = %D3D11_MESSAGE_ID_VSSHADERRESOURCES_NOT_SUPPORTED                                             + 1
%D3D11_MESSAGE_ID_STREAM_OUT_NOT_SUPPORTED                                                    = %D3D11_MESSAGE_ID_GEOMETRY_SHADER_NOT_SUPPORTED                                               + 1
%D3D11_MESSAGE_ID_TEXT_FILTER_NOT_SUPPORTED                                                   = %D3D11_MESSAGE_ID_STREAM_OUT_NOT_SUPPORTED                                                    + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_SEPARATE_ALPHA_BLEND                                    = %D3D11_MESSAGE_ID_TEXT_FILTER_NOT_SUPPORTED                                                   + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_MRT_BLEND                                               = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_SEPARATE_ALPHA_BLEND                                    + 1
%D3D11_MESSAGE_ID_CREATEBLENDSTATE_OPERATION_NOT_SUPPORTED                                    = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_NO_MRT_BLEND                                               + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_NO_MIRRORONCE                                            = %D3D11_MESSAGE_ID_CREATEBLENDSTATE_OPERATION_NOT_SUPPORTED                                    + 1
%D3D11_MESSAGE_ID_DRAWINSTANCED_NOT_SUPPORTED                                                 = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_NO_MIRRORONCE                                            + 1
%D3D11_MESSAGE_ID_DRAWINDEXEDINSTANCED_NOT_SUPPORTED_BELOW_9_3                                = %D3D11_MESSAGE_ID_DRAWINSTANCED_NOT_SUPPORTED                                                 + 1
%D3D11_MESSAGE_ID_DRAWINDEXED_POINTLIST_UNSUPPORTED                                           = %D3D11_MESSAGE_ID_DRAWINDEXEDINSTANCED_NOT_SUPPORTED_BELOW_9_3                                + 1
%D3D11_MESSAGE_ID_SETBLENDSTATE_SAMPLE_MASK_CANNOT_BE_ZERO                                    = %D3D11_MESSAGE_ID_DRAWINDEXED_POINTLIST_UNSUPPORTED                                           + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_DIMENSION_EXCEEDS_FEATURE_LEVEL_DEFINITION                   = %D3D11_MESSAGE_ID_SETBLENDSTATE_SAMPLE_MASK_CANNOT_BE_ZERO                                    + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_ONLY_SINGLE_MIP_LEVEL_DEPTH_STENCIL_SUPPORTED                = %D3D11_MESSAGE_ID_CREATERESOURCE_DIMENSION_EXCEEDS_FEATURE_LEVEL_DEFINITION                   + 1
%D3D11_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_NEGATIVESCISSOR                                    = %D3D11_MESSAGE_ID_CREATERESOURCE_ONLY_SINGLE_MIP_LEVEL_DEPTH_STENCIL_SUPPORTED                + 1
%D3D11_MESSAGE_ID_SLOT_ZERO_MUST_BE_D3D10_INPUT_PER_VERTEX_DATA                               = %D3D11_MESSAGE_ID_DEVICE_RSSETSCISSORRECTS_NEGATIVESCISSOR                                    + 1
%D3D11_MESSAGE_ID_CREATERESOURCE_NON_POW_2_MIPMAP                                             = %D3D11_MESSAGE_ID_SLOT_ZERO_MUST_BE_D3D10_INPUT_PER_VERTEX_DATA                               + 1
%D3D11_MESSAGE_ID_CREATESAMPLERSTATE_BORDER_NOT_SUPPORTED                                     = %D3D11_MESSAGE_ID_CREATERESOURCE_NON_POW_2_MIPMAP                                             + 1
%D3D11_MESSAGE_ID_OMSETRENDERTARGETS_NO_SRGB_MRT                                              = %D3D11_MESSAGE_ID_CREATESAMPLERSTATE_BORDER_NOT_SUPPORTED                                     + 1
%D3D11_MESSAGE_ID_D3D10L9_MESSAGES_END                                                        = %D3D11_MESSAGE_ID_OMSETRENDERTARGETS_NO_SRGB_MRT                                              + 1
%D3D11_MESSAGE_ID_D3D11_MESSAGES_START                                                        = &H200000
%D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFLAGS                                         = %D3D11_MESSAGE_ID_D3D11_MESSAGES_START                                                        + 1
%D3D11_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDCLASSLINKAGE                                      = %D3D11_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFLAGS                                         + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDCLASSLINKAGE                                    = %D3D11_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDCLASSLINKAGE                                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTREAMS                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDCLASSLINKAGE                                    + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAMTORASTERIZER              = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTREAMS                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTREAMS                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAMTORASTERIZER              + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCLASSLINKAGE                    = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTREAMS                      + 1
%D3D11_MESSAGE_ID_CREATEPIXELSHADER_INVALIDCLASSLINKAGE                                       = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCLASSLINKAGE                    + 1
%D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_INVALID_COMMANDLISTFLAGS                              = %D3D11_MESSAGE_ID_CREATEPIXELSHADER_INVALIDCLASSLINKAGE                                       + 1
%D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_SINGLETHREADED                                        = %D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_INVALID_COMMANDLISTFLAGS                              + 1
%D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_INVALIDARG_RETURN                                     = %D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_SINGLETHREADED                                        + 1
%D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_INVALID_CALL_RETURN                                   = %D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_INVALIDARG_RETURN                                     + 1
%D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_OUTOFMEMORY_RETURN                                    = %D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_INVALID_CALL_RETURN                                   + 1
%D3D11_MESSAGE_ID_FINISHDISPLAYLIST_ONIMMEDIATECONTEXT                                        = %D3D11_MESSAGE_ID_CREATEDEFERREDCONTEXT_OUTOFMEMORY_RETURN                                    + 1
%D3D11_MESSAGE_ID_FINISHDISPLAYLIST_OUTOFMEMORY_RETURN                                        = %D3D11_MESSAGE_ID_FINISHDISPLAYLIST_ONIMMEDIATECONTEXT                                        + 1
%D3D11_MESSAGE_ID_FINISHDISPLAYLIST_INVALID_CALL_RETURN                                       = %D3D11_MESSAGE_ID_FINISHDISPLAYLIST_OUTOFMEMORY_RETURN                                        + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAM                          = %D3D11_MESSAGE_ID_FINISHDISPLAYLIST_INVALID_CALL_RETURN                                       + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDENTRIES                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAM                          + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTRIDES                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDENTRIES                      + 1
%D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTRIDES                      = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTRIDES                      + 1
%D3D11_MESSAGE_ID_DEVICE_HSSETSHADERRESOURCES_HAZARD                                          = %D3D11_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTRIDES                      + 1
%D3D11_MESSAGE_ID_DEVICE_HSSETCONSTANTBUFFERS_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_HSSETSHADERRESOURCES_HAZARD                                          + 1
%D3D11_MESSAGE_ID_HSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_DEVICE_HSSETCONSTANTBUFFERS_HAZARD                                          + 1
%D3D11_MESSAGE_ID_HSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_HSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDCALL                                                = %D3D11_MESSAGE_ID_HSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_CREATEHULLSHADER_OUTOFMEMORY                                                = %D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDCALL                                                + 1
%D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERBYTECODE                                      = %D3D11_MESSAGE_ID_CREATEHULLSHADER_OUTOFMEMORY                                                + 1
%D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERTYPE                                          = %D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERBYTECODE                                      + 1
%D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDCLASSLINKAGE                                        = %D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERTYPE                                          + 1
%D3D11_MESSAGE_ID_DEVICE_HSSETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_CREATEHULLSHADER_INVALIDCLASSLINKAGE                                        + 1
%D3D11_MESSAGE_ID_HSSETCONSTANTBUFFERS_INVALIDBUFFER                                          = %D3D11_MESSAGE_ID_DEVICE_HSSETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_HSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_HSSETCONSTANTBUFFERS_INVALIDBUFFER                                          + 1
%D3D11_MESSAGE_ID_DEVICE_HSSETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_HSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_HSGETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_HSSETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_HSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DEVICE_HSGETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_HSGETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_HSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DSSETSHADERRESOURCES_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_HSGETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DSSETCONSTANTBUFFERS_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_DSSETSHADERRESOURCES_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_DEVICE_DSSETCONSTANTBUFFERS_HAZARD                                          + 1
%D3D11_MESSAGE_ID_DSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_DSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCALL                                              = %D3D11_MESSAGE_ID_DSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_CREATEDOMAINSHADER_OUTOFMEMORY                                              = %D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCALL                                              + 1
%D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERBYTECODE                                    = %D3D11_MESSAGE_ID_CREATEDOMAINSHADER_OUTOFMEMORY                                              + 1
%D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERTYPE                                        = %D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERBYTECODE                                    + 1
%D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCLASSLINKAGE                                      = %D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERTYPE                                        + 1
%D3D11_MESSAGE_ID_DEVICE_DSSETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCLASSLINKAGE                                      + 1
%D3D11_MESSAGE_ID_DSSETCONSTANTBUFFERS_INVALIDBUFFER                                          = %D3D11_MESSAGE_ID_DEVICE_DSSETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_DSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DSSETCONSTANTBUFFERS_INVALIDBUFFER                                          + 1
%D3D11_MESSAGE_ID_DEVICE_DSSETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_DSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DSGETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_DSSETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_DSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DEVICE_DSGETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_DSGETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_DSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_HS_XOR_DS_MISMATCH                                              = %D3D11_MESSAGE_ID_DEVICE_DSGETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEFERRED_CONTEXT_REMOVAL_PROCESS_AT_FAULT                                   = %D3D11_MESSAGE_ID_DEVICE_DRAW_HS_XOR_DS_MISMATCH                                              + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINDIRECT_INVALID_ARG_BUFFER                                      = %D3D11_MESSAGE_ID_DEFERRED_CONTEXT_REMOVAL_PROCESS_AT_FAULT                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINDIRECT_OFFSET_UNALIGNED                                        = %D3D11_MESSAGE_ID_DEVICE_DRAWINDIRECT_INVALID_ARG_BUFFER                                      + 1
%D3D11_MESSAGE_ID_DEVICE_DRAWINDIRECT_OFFSET_OVERFLOW                                         = %D3D11_MESSAGE_ID_DEVICE_DRAWINDIRECT_OFFSET_UNALIGNED                                        + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_INVALIDMAPTYPE                                                 = %D3D11_MESSAGE_ID_DEVICE_DRAWINDIRECT_OFFSET_OVERFLOW                                         + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_INVALIDSUBRESOURCE                                             = %D3D11_MESSAGE_ID_RESOURCE_MAP_INVALIDMAPTYPE                                                 + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_INVALIDFLAGS                                                   = %D3D11_MESSAGE_ID_RESOURCE_MAP_INVALIDSUBRESOURCE                                             + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_ALREADYMAPPED                                                  = %D3D11_MESSAGE_ID_RESOURCE_MAP_INVALIDFLAGS                                                   + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_DEVICEREMOVED_RETURN                                           = %D3D11_MESSAGE_ID_RESOURCE_MAP_ALREADYMAPPED                                                  + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_OUTOFMEMORY_RETURN                                             = %D3D11_MESSAGE_ID_RESOURCE_MAP_DEVICEREMOVED_RETURN                                           + 1
%D3D11_MESSAGE_ID_RESOURCE_MAP_WITHOUT_INITIAL_DISCARD                                        = %D3D11_MESSAGE_ID_RESOURCE_MAP_OUTOFMEMORY_RETURN                                             + 1
%D3D11_MESSAGE_ID_RESOURCE_UNMAP_INVALIDSUBRESOURCE                                           = %D3D11_MESSAGE_ID_RESOURCE_MAP_WITHOUT_INITIAL_DISCARD                                        + 1
%D3D11_MESSAGE_ID_RESOURCE_UNMAP_NOTMAPPED                                                    = %D3D11_MESSAGE_ID_RESOURCE_UNMAP_INVALIDSUBRESOURCE                                           + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_RASTERIZING_CONTROL_POINTS                                      = %D3D11_MESSAGE_ID_RESOURCE_UNMAP_NOTMAPPED                                                    + 1
%D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNSUPPORTED                          = %D3D11_MESSAGE_ID_DEVICE_DRAW_RASTERIZING_CONTROL_POINTS                                      + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_HS_DS_SIGNATURE_MISMATCH                                        = %D3D11_MESSAGE_ID_DEVICE_IASETPRIMITIVETOPOLOGY_TOPOLOGY_UNSUPPORTED                          + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_HULL_SHADER_INPUT_TOPOLOGY_MISMATCH                             = %D3D11_MESSAGE_ID_DEVICE_DRAW_HS_DS_SIGNATURE_MISMATCH                                        + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_HS_DS_CONTROL_POINT_COUNT_MISMATCH                              = %D3D11_MESSAGE_ID_DEVICE_DRAW_HULL_SHADER_INPUT_TOPOLOGY_MISMATCH                             + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_HS_DS_TESSELLATOR_DOMAIN_MISMATCH                               = %D3D11_MESSAGE_ID_DEVICE_DRAW_HS_DS_CONTROL_POINT_COUNT_MISMATCH                              + 1
%D3D11_MESSAGE_ID_CREATE_CONTEXT                                                              = %D3D11_MESSAGE_ID_DEVICE_DRAW_HS_DS_TESSELLATOR_DOMAIN_MISMATCH                               + 1
%D3D11_MESSAGE_ID_LIVE_CONTEXT                                                                = %D3D11_MESSAGE_ID_CREATE_CONTEXT                                                              + 1
%D3D11_MESSAGE_ID_DESTROY_CONTEXT                                                             = %D3D11_MESSAGE_ID_LIVE_CONTEXT                                                                + 1
%D3D11_MESSAGE_ID_CREATE_BUFFER                                                               = %D3D11_MESSAGE_ID_DESTROY_CONTEXT                                                             + 1
%D3D11_MESSAGE_ID_LIVE_BUFFER                                                                 = %D3D11_MESSAGE_ID_CREATE_BUFFER                                                               + 1
%D3D11_MESSAGE_ID_DESTROY_BUFFER                                                              = %D3D11_MESSAGE_ID_LIVE_BUFFER                                                                 + 1
%D3D11_MESSAGE_ID_CREATE_TEXTURE1D                                                            = %D3D11_MESSAGE_ID_DESTROY_BUFFER                                                              + 1
%D3D11_MESSAGE_ID_LIVE_TEXTURE1D                                                              = %D3D11_MESSAGE_ID_CREATE_TEXTURE1D                                                            + 1
%D3D11_MESSAGE_ID_DESTROY_TEXTURE1D                                                           = %D3D11_MESSAGE_ID_LIVE_TEXTURE1D                                                              + 1
%D3D11_MESSAGE_ID_CREATE_TEXTURE2D                                                            = %D3D11_MESSAGE_ID_DESTROY_TEXTURE1D                                                           + 1
%D3D11_MESSAGE_ID_LIVE_TEXTURE2D                                                              = %D3D11_MESSAGE_ID_CREATE_TEXTURE2D                                                            + 1
%D3D11_MESSAGE_ID_DESTROY_TEXTURE2D                                                           = %D3D11_MESSAGE_ID_LIVE_TEXTURE2D                                                              + 1
%D3D11_MESSAGE_ID_CREATE_TEXTURE3D                                                            = %D3D11_MESSAGE_ID_DESTROY_TEXTURE2D                                                           + 1
%D3D11_MESSAGE_ID_LIVE_TEXTURE3D                                                              = %D3D11_MESSAGE_ID_CREATE_TEXTURE3D                                                            + 1
%D3D11_MESSAGE_ID_DESTROY_TEXTURE3D                                                           = %D3D11_MESSAGE_ID_LIVE_TEXTURE3D                                                              + 1
%D3D11_MESSAGE_ID_CREATE_SHADERRESOURCEVIEW                                                   = %D3D11_MESSAGE_ID_DESTROY_TEXTURE3D                                                           + 1
%D3D11_MESSAGE_ID_LIVE_SHADERRESOURCEVIEW                                                     = %D3D11_MESSAGE_ID_CREATE_SHADERRESOURCEVIEW                                                   + 1
%D3D11_MESSAGE_ID_DESTROY_SHADERRESOURCEVIEW                                                  = %D3D11_MESSAGE_ID_LIVE_SHADERRESOURCEVIEW                                                     + 1
%D3D11_MESSAGE_ID_CREATE_RENDERTARGETVIEW                                                     = %D3D11_MESSAGE_ID_DESTROY_SHADERRESOURCEVIEW                                                  + 1
%D3D11_MESSAGE_ID_LIVE_RENDERTARGETVIEW                                                       = %D3D11_MESSAGE_ID_CREATE_RENDERTARGETVIEW                                                     + 1
%D3D11_MESSAGE_ID_DESTROY_RENDERTARGETVIEW                                                    = %D3D11_MESSAGE_ID_LIVE_RENDERTARGETVIEW                                                       + 1
%D3D11_MESSAGE_ID_CREATE_DEPTHSTENCILVIEW                                                     = %D3D11_MESSAGE_ID_DESTROY_RENDERTARGETVIEW                                                    + 1
%D3D11_MESSAGE_ID_LIVE_DEPTHSTENCILVIEW                                                       = %D3D11_MESSAGE_ID_CREATE_DEPTHSTENCILVIEW                                                     + 1
%D3D11_MESSAGE_ID_DESTROY_DEPTHSTENCILVIEW                                                    = %D3D11_MESSAGE_ID_LIVE_DEPTHSTENCILVIEW                                                       + 1
%D3D11_MESSAGE_ID_CREATE_VERTEXSHADER                                                         = %D3D11_MESSAGE_ID_DESTROY_DEPTHSTENCILVIEW                                                    + 1
%D3D11_MESSAGE_ID_LIVE_VERTEXSHADER                                                           = %D3D11_MESSAGE_ID_CREATE_VERTEXSHADER                                                         + 1
%D3D11_MESSAGE_ID_DESTROY_VERTEXSHADER                                                        = %D3D11_MESSAGE_ID_LIVE_VERTEXSHADER                                                           + 1
%D3D11_MESSAGE_ID_CREATE_HULLSHADER                                                           = %D3D11_MESSAGE_ID_DESTROY_VERTEXSHADER                                                        + 1
%D3D11_MESSAGE_ID_LIVE_HULLSHADER                                                             = %D3D11_MESSAGE_ID_CREATE_HULLSHADER                                                           + 1
%D3D11_MESSAGE_ID_DESTROY_HULLSHADER                                                          = %D3D11_MESSAGE_ID_LIVE_HULLSHADER                                                             + 1
%D3D11_MESSAGE_ID_CREATE_DOMAINSHADER                                                         = %D3D11_MESSAGE_ID_DESTROY_HULLSHADER                                                          + 1
%D3D11_MESSAGE_ID_LIVE_DOMAINSHADER                                                           = %D3D11_MESSAGE_ID_CREATE_DOMAINSHADER                                                         + 1
%D3D11_MESSAGE_ID_DESTROY_DOMAINSHADER                                                        = %D3D11_MESSAGE_ID_LIVE_DOMAINSHADER                                                           + 1
%D3D11_MESSAGE_ID_CREATE_GEOMETRYSHADER                                                       = %D3D11_MESSAGE_ID_DESTROY_DOMAINSHADER                                                        + 1
%D3D11_MESSAGE_ID_LIVE_GEOMETRYSHADER                                                         = %D3D11_MESSAGE_ID_CREATE_GEOMETRYSHADER                                                       + 1
%D3D11_MESSAGE_ID_DESTROY_GEOMETRYSHADER                                                      = %D3D11_MESSAGE_ID_LIVE_GEOMETRYSHADER                                                         + 1
%D3D11_MESSAGE_ID_CREATE_PIXELSHADER                                                          = %D3D11_MESSAGE_ID_DESTROY_GEOMETRYSHADER                                                      + 1
%D3D11_MESSAGE_ID_LIVE_PIXELSHADER                                                            = %D3D11_MESSAGE_ID_CREATE_PIXELSHADER                                                          + 1
%D3D11_MESSAGE_ID_DESTROY_PIXELSHADER                                                         = %D3D11_MESSAGE_ID_LIVE_PIXELSHADER                                                            + 1
%D3D11_MESSAGE_ID_CREATE_INPUTLAYOUT                                                          = %D3D11_MESSAGE_ID_DESTROY_PIXELSHADER                                                         + 1
%D3D11_MESSAGE_ID_LIVE_INPUTLAYOUT                                                            = %D3D11_MESSAGE_ID_CREATE_INPUTLAYOUT                                                          + 1
%D3D11_MESSAGE_ID_DESTROY_INPUTLAYOUT                                                         = %D3D11_MESSAGE_ID_LIVE_INPUTLAYOUT                                                            + 1
%D3D11_MESSAGE_ID_CREATE_SAMPLER                                                              = %D3D11_MESSAGE_ID_DESTROY_INPUTLAYOUT                                                         + 1
%D3D11_MESSAGE_ID_LIVE_SAMPLER                                                                = %D3D11_MESSAGE_ID_CREATE_SAMPLER                                                              + 1
%D3D11_MESSAGE_ID_DESTROY_SAMPLER                                                             = %D3D11_MESSAGE_ID_LIVE_SAMPLER                                                                + 1
%D3D11_MESSAGE_ID_CREATE_BLENDSTATE                                                           = %D3D11_MESSAGE_ID_DESTROY_SAMPLER                                                             + 1
%D3D11_MESSAGE_ID_LIVE_BLENDSTATE                                                             = %D3D11_MESSAGE_ID_CREATE_BLENDSTATE                                                           + 1
%D3D11_MESSAGE_ID_DESTROY_BLENDSTATE                                                          = %D3D11_MESSAGE_ID_LIVE_BLENDSTATE                                                             + 1
%D3D11_MESSAGE_ID_CREATE_DEPTHSTENCILSTATE                                                    = %D3D11_MESSAGE_ID_DESTROY_BLENDSTATE                                                          + 1
%D3D11_MESSAGE_ID_LIVE_DEPTHSTENCILSTATE                                                      = %D3D11_MESSAGE_ID_CREATE_DEPTHSTENCILSTATE                                                    + 1
%D3D11_MESSAGE_ID_DESTROY_DEPTHSTENCILSTATE                                                   = %D3D11_MESSAGE_ID_LIVE_DEPTHSTENCILSTATE                                                      + 1
%D3D11_MESSAGE_ID_CREATE_RASTERIZERSTATE                                                      = %D3D11_MESSAGE_ID_DESTROY_DEPTHSTENCILSTATE                                                   + 1
%D3D11_MESSAGE_ID_LIVE_RASTERIZERSTATE                                                        = %D3D11_MESSAGE_ID_CREATE_RASTERIZERSTATE                                                      + 1
%D3D11_MESSAGE_ID_DESTROY_RASTERIZERSTATE                                                     = %D3D11_MESSAGE_ID_LIVE_RASTERIZERSTATE                                                        + 1
%D3D11_MESSAGE_ID_CREATE_QUERY                                                                = %D3D11_MESSAGE_ID_DESTROY_RASTERIZERSTATE                                                     + 1
%D3D11_MESSAGE_ID_LIVE_QUERY                                                                  = %D3D11_MESSAGE_ID_CREATE_QUERY                                                                + 1
%D3D11_MESSAGE_ID_DESTROY_QUERY                                                               = %D3D11_MESSAGE_ID_LIVE_QUERY                                                                  + 1
%D3D11_MESSAGE_ID_CREATE_PREDICATE                                                            = %D3D11_MESSAGE_ID_DESTROY_QUERY                                                               + 1
%D3D11_MESSAGE_ID_LIVE_PREDICATE                                                              = %D3D11_MESSAGE_ID_CREATE_PREDICATE                                                            + 1
%D3D11_MESSAGE_ID_DESTROY_PREDICATE                                                           = %D3D11_MESSAGE_ID_LIVE_PREDICATE                                                              + 1
%D3D11_MESSAGE_ID_CREATE_COUNTER                                                              = %D3D11_MESSAGE_ID_DESTROY_PREDICATE                                                           + 1
%D3D11_MESSAGE_ID_LIVE_COUNTER                                                                = %D3D11_MESSAGE_ID_CREATE_COUNTER                                                              + 1
%D3D11_MESSAGE_ID_DESTROY_COUNTER                                                             = %D3D11_MESSAGE_ID_LIVE_COUNTER                                                                + 1
%D3D11_MESSAGE_ID_CREATE_COMMANDLIST                                                          = %D3D11_MESSAGE_ID_DESTROY_COUNTER                                                             + 1
%D3D11_MESSAGE_ID_LIVE_COMMANDLIST                                                            = %D3D11_MESSAGE_ID_CREATE_COMMANDLIST                                                          + 1
%D3D11_MESSAGE_ID_DESTROY_COMMANDLIST                                                         = %D3D11_MESSAGE_ID_LIVE_COMMANDLIST                                                            + 1
%D3D11_MESSAGE_ID_CREATE_CLASSINSTANCE                                                        = %D3D11_MESSAGE_ID_DESTROY_COMMANDLIST                                                         + 1
%D3D11_MESSAGE_ID_LIVE_CLASSINSTANCE                                                          = %D3D11_MESSAGE_ID_CREATE_CLASSINSTANCE                                                        + 1
%D3D11_MESSAGE_ID_DESTROY_CLASSINSTANCE                                                       = %D3D11_MESSAGE_ID_LIVE_CLASSINSTANCE                                                          + 1
%D3D11_MESSAGE_ID_CREATE_CLASSLINKAGE                                                         = %D3D11_MESSAGE_ID_DESTROY_CLASSINSTANCE                                                       + 1
%D3D11_MESSAGE_ID_LIVE_CLASSLINKAGE                                                           = %D3D11_MESSAGE_ID_CREATE_CLASSLINKAGE                                                         + 1
%D3D11_MESSAGE_ID_DESTROY_CLASSLINKAGE                                                        = %D3D11_MESSAGE_ID_LIVE_CLASSLINKAGE                                                           + 1
%D3D11_MESSAGE_ID_LIVE_DEVICE                                                                 = %D3D11_MESSAGE_ID_DESTROY_CLASSLINKAGE                                                        + 1
%D3D11_MESSAGE_ID_LIVE_OBJECT_SUMMARY                                                         = %D3D11_MESSAGE_ID_LIVE_DEVICE                                                                 + 1
%D3D11_MESSAGE_ID_CREATE_COMPUTESHADER                                                        = %D3D11_MESSAGE_ID_LIVE_OBJECT_SUMMARY                                                         + 1
%D3D11_MESSAGE_ID_LIVE_COMPUTESHADER                                                          = %D3D11_MESSAGE_ID_CREATE_COMPUTESHADER                                                        + 1
%D3D11_MESSAGE_ID_DESTROY_COMPUTESHADER                                                       = %D3D11_MESSAGE_ID_LIVE_COMPUTESHADER                                                          + 1
%D3D11_MESSAGE_ID_CREATE_UNORDEREDACCESSVIEW                                                  = %D3D11_MESSAGE_ID_DESTROY_COMPUTESHADER                                                       + 1
%D3D11_MESSAGE_ID_LIVE_UNORDEREDACCESSVIEW                                                    = %D3D11_MESSAGE_ID_CREATE_UNORDEREDACCESSVIEW                                                  + 1
%D3D11_MESSAGE_ID_DESTROY_UNORDEREDACCESSVIEW                                                 = %D3D11_MESSAGE_ID_LIVE_UNORDEREDACCESSVIEW                                                    + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INTERFACES_FEATURELEVEL                                    = %D3D11_MESSAGE_ID_DESTROY_UNORDEREDACCESSVIEW                                                 + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INTERFACE_COUNT_MISMATCH                                   = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INTERFACES_FEATURELEVEL                                    + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE                                           = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INTERFACE_COUNT_MISMATCH                                   + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE_INDEX                                     = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE                                           + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE_TYPE                                      = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE_INDEX                                     + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE_DATA                                      = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE_TYPE                                      + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_UNBOUND_INSTANCE_DATA                                      = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INVALID_INSTANCE_DATA                                      + 1
%D3D11_MESSAGE_ID_DEVICE_SETSHADER_INSTANCE_DATA_BINDINGS                                     = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_UNBOUND_INSTANCE_DATA                                      + 1
%D3D11_MESSAGE_ID_DEVICE_CREATESHADER_CLASSLINKAGE_FULL                                       = %D3D11_MESSAGE_ID_DEVICE_SETSHADER_INSTANCE_DATA_BINDINGS                                     + 1
%D3D11_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_UNRECOGNIZED_FEATURE                             = %D3D11_MESSAGE_ID_DEVICE_CREATESHADER_CLASSLINKAGE_FULL                                       + 1
%D3D11_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_MISMATCHED_DATA_SIZE                             = %D3D11_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_UNRECOGNIZED_FEATURE                             + 1
%D3D11_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_INVALIDARG_RETURN                                = %D3D11_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_MISMATCHED_DATA_SIZE                             + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETSHADERRESOURCES_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_INVALIDARG_RETURN                                + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETCONSTANTBUFFERS_HAZARD                                          = %D3D11_MESSAGE_ID_DEVICE_CSSETSHADERRESOURCES_HAZARD                                          + 1
%D3D11_MESSAGE_ID_CSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_DEVICE_CSSETCONSTANTBUFFERS_HAZARD                                          + 1
%D3D11_MESSAGE_ID_CSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   = %D3D11_MESSAGE_ID_CSSETSHADERRESOURCES_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCALL                                             = %D3D11_MESSAGE_ID_CSSETCONSTANTBUFFERS_UNBINDDELETINGOBJECT                                   + 1
%D3D11_MESSAGE_ID_CREATECOMPUTESHADER_OUTOFMEMORY                                             = %D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCALL                                             + 1
%D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERBYTECODE                                   = %D3D11_MESSAGE_ID_CREATECOMPUTESHADER_OUTOFMEMORY                                             + 1
%D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERTYPE                                       = %D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERBYTECODE                                   + 1
%D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCLASSLINKAGE                                     = %D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERTYPE                                       + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCLASSLINKAGE                                     + 1
%D3D11_MESSAGE_ID_CSSETCONSTANTBUFFERS_INVALIDBUFFER                                          = %D3D11_MESSAGE_ID_DEVICE_CSSETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_CSSETCONSTANTBUFFERS_INVALIDBUFFER                                          + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_CSSETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_CSGETSHADERRESOURCES_VIEWS_EMPTY                                     = %D3D11_MESSAGE_ID_DEVICE_CSSETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_CSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   = %D3D11_MESSAGE_ID_DEVICE_CSGETSHADERRESOURCES_VIEWS_EMPTY                                     + 1
%D3D11_MESSAGE_ID_DEVICE_CSGETSAMPLERS_SAMPLERS_EMPTY                                         = %D3D11_MESSAGE_ID_DEVICE_CSGETCONSTANTBUFFERS_BUFFERS_EMPTY                                   + 1
%D3D11_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEFLOATOPSNOTSUPPORTED                        = %D3D11_MESSAGE_ID_DEVICE_CSGETSAMPLERS_SAMPLERS_EMPTY                                         + 1
%D3D11_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEFLOATOPSNOTSUPPORTED                          = %D3D11_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEFLOATOPSNOTSUPPORTED                        + 1
%D3D11_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEFLOATOPSNOTSUPPORTED                        = %D3D11_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEFLOATOPSNOTSUPPORTED                          + 1
%D3D11_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEFLOATOPSNOTSUPPORTED                      = %D3D11_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEFLOATOPSNOTSUPPORTED                        + 1
%D3D11_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEFLOATOPSNOTSUPPORTED      = %D3D11_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEFLOATOPSNOTSUPPORTED                      + 1
%D3D11_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEFLOATOPSNOTSUPPORTED                         = %D3D11_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEFLOATOPSNOTSUPPORTED      + 1
%D3D11_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEFLOATOPSNOTSUPPORTED                       = %D3D11_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEFLOATOPSNOTSUPPORTED                         + 1
%D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDSTRUCTURESTRIDE                                         = %D3D11_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEFLOATOPSNOTSUPPORTED                       + 1
%D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFLAGS                                       = %D3D11_MESSAGE_ID_CREATEBUFFER_INVALIDSTRUCTURESTRIDE                                         + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDRESOURCE                                   = %D3D11_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFLAGS                                       + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDESC                                       = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDRESOURCE                                   + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFORMAT                                     = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDESC                                       + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDIMENSIONS                                 = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFORMAT                                     + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_UNRECOGNIZEDFORMAT                                = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDIMENSIONS                                 + 1
%D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS_HAZARD                     = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_UNRECOGNIZEDFORMAT                                + 1
%D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS_OVERLAPPING_OLD_SLOTS      = %D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS_HAZARD                     + 1
%D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS_NO_OP                      = %D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS_OVERLAPPING_OLD_SLOTS      + 1
%D3D11_MESSAGE_ID_CSSETUNORDEREDACCESSVIEWS_UNBINDDELETINGOBJECT                              = %D3D11_MESSAGE_ID_DEVICE_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS_NO_OP                      + 1
%D3D11_MESSAGE_ID_PSSETUNORDEREDACCESSVIEWS_UNBINDDELETINGOBJECT                              = %D3D11_MESSAGE_ID_CSSETUNORDEREDACCESSVIEWS_UNBINDDELETINGOBJECT                              + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDARG_RETURN                                 = %D3D11_MESSAGE_ID_PSSETUNORDEREDACCESSVIEWS_UNBINDDELETINGOBJECT                              + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_OUTOFMEMORY_RETURN                                = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDARG_RETURN                                 + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_TOOMANYOBJECTS                                    = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_OUTOFMEMORY_RETURN                                + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_HAZARD                                     = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_TOOMANYOBJECTS                                    + 1
%D3D11_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_DENORMFLUSH                                        = %D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_HAZARD                                     + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSS_VIEWS_EMPTY                                    = %D3D11_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_DENORMFLUSH                                        + 1
%D3D11_MESSAGE_ID_DEVICE_CSGETUNORDEREDACCESSS_VIEWS_EMPTY                                    = %D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSS_VIEWS_EMPTY                                    + 1
%D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFLAGS                                      = %D3D11_MESSAGE_ID_DEVICE_CSGETUNORDEREDACCESSS_VIEWS_EMPTY                                    + 1
%D3D11_MESSAGE_ID_CREATESHADERRESESOURCEVIEW_TOOMANYOBJECTS                                   = %D3D11_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFLAGS                                      + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_INVALID_ARG_BUFFER                                  = %D3D11_MESSAGE_ID_CREATESHADERRESESOURCEVIEW_TOOMANYOBJECTS                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_OFFSET_UNALIGNED                                    = %D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_INVALID_ARG_BUFFER                                  + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_OFFSET_OVERFLOW                                     = %D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_OFFSET_UNALIGNED                                    + 1
%D3D11_MESSAGE_ID_DEVICE_SETRESOURCEMINLOD_INVALIDCONTEXT                                     = %D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_OFFSET_OVERFLOW                                     + 1
%D3D11_MESSAGE_ID_DEVICE_SETRESOURCEMINLOD_INVALIDRESOURCE                                    = %D3D11_MESSAGE_ID_DEVICE_SETRESOURCEMINLOD_INVALIDCONTEXT                                     + 1
%D3D11_MESSAGE_ID_DEVICE_SETRESOURCEMINLOD_INVALIDMINLOD                                      = %D3D11_MESSAGE_ID_DEVICE_SETRESOURCEMINLOD_INVALIDRESOURCE                                    + 1
%D3D11_MESSAGE_ID_DEVICE_GETRESOURCEMINLOD_INVALIDCONTEXT                                     = %D3D11_MESSAGE_ID_DEVICE_SETRESOURCEMINLOD_INVALIDMINLOD                                      + 1
%D3D11_MESSAGE_ID_DEVICE_GETRESOURCEMINLOD_INVALIDRESOURCE                                    = %D3D11_MESSAGE_ID_DEVICE_GETRESOURCEMINLOD_INVALIDCONTEXT                                     + 1
%D3D11_MESSAGE_ID_OMSETDEPTHSTENCIL_UNBINDDELETINGOBJECT                                      = %D3D11_MESSAGE_ID_DEVICE_GETRESOURCEMINLOD_INVALIDRESOURCE                                    + 1
%D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_DEPTH_READONLY                                        = %D3D11_MESSAGE_ID_OMSETDEPTHSTENCIL_UNBINDDELETINGOBJECT                                      + 1
%D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_STENCIL_READONLY                                      = %D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_DEPTH_READONLY                                        + 1
%D3D11_MESSAGE_ID_CHECKFEATURESUPPORT_FORMAT_DEPRECATED                                       = %D3D11_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_STENCIL_READONLY                                      + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_RETURN_TYPE_MISMATCH                             = %D3D11_MESSAGE_ID_CHECKFEATURESUPPORT_FORMAT_DEPRECATED                                       + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_NOT_SET                                          = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_RETURN_TYPE_MISMATCH                             + 1
%D3D11_MESSAGE_ID_DEVICE_DRAW_UNORDEREDACCESSVIEW_RENDERTARGETVIEW_OVERLAP                    = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_NOT_SET                                          + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_DIMENSION_MISMATCH                               = %D3D11_MESSAGE_ID_DEVICE_DRAW_UNORDEREDACCESSVIEW_RENDERTARGETVIEW_OVERLAP                    + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_APPEND_UNSUPPORTED                               = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_DIMENSION_MISMATCH                               + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMICS_UNSUPPORTED                              = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_APPEND_UNSUPPORTED                               + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_STRUCTURE_STRIDE_MISMATCH                        = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMICS_UNSUPPORTED                              + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_BUFFER_TYPE_MISMATCH                             = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_STRUCTURE_STRIDE_MISMATCH                        + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_RAW_UNSUPPORTED                                  = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_BUFFER_TYPE_MISMATCH                             + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_FORMAT_LD_UNSUPPORTED                            = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_RAW_UNSUPPORTED                                  + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_FORMAT_STORE_UNSUPPORTED                         = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_FORMAT_LD_UNSUPPORTED                            + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_ADD_UNSUPPORTED                           = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_FORMAT_STORE_UNSUPPORTED                         + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_BITWISE_OPS_UNSUPPORTED                   = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_ADD_UNSUPPORTED                           + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_CMPSTORE_CMPEXCHANGE_UNSUPPORTED          = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_BITWISE_OPS_UNSUPPORTED                   + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_EXCHANGE_UNSUPPORTED                      = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_CMPSTORE_CMPEXCHANGE_UNSUPPORTED          + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_SIGNED_MINMAX_UNSUPPORTED                 = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_EXCHANGE_UNSUPPORTED                      + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_UNSIGNED_MINMAX_UNSUPPORTED               = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_SIGNED_MINMAX_UNSUPPORTED                 + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCH_BOUND_RESOURCE_MAPPED                                       = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_ATOMIC_UNSIGNED_MINMAX_UNSUPPORTED               + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCH_THREADGROUPCOUNT_OVERFLOW                                   = %D3D11_MESSAGE_ID_DEVICE_DISPATCH_BOUND_RESOURCE_MAPPED                                       + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCH_THREADGROUPCOUNT_ZERO                                       = %D3D11_MESSAGE_ID_DEVICE_DISPATCH_THREADGROUPCOUNT_OVERFLOW                                   + 1
%D3D11_MESSAGE_ID_DEVICE_SHADERRESOURCEVIEW_STRUCTURE_STRIDE_MISMATCH                         = %D3D11_MESSAGE_ID_DEVICE_DISPATCH_THREADGROUPCOUNT_ZERO                                       + 1
%D3D11_MESSAGE_ID_DEVICE_SHADERRESOURCEVIEW_BUFFER_TYPE_MISMATCH                              = %D3D11_MESSAGE_ID_DEVICE_SHADERRESOURCEVIEW_STRUCTURE_STRIDE_MISMATCH                         + 1
%D3D11_MESSAGE_ID_DEVICE_SHADERRESOURCEVIEW_RAW_UNSUPPORTED                                   = %D3D11_MESSAGE_ID_DEVICE_SHADERRESOURCEVIEW_BUFFER_TYPE_MISMATCH                              + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCH_UNSUPPORTED                                                 = %D3D11_MESSAGE_ID_DEVICE_SHADERRESOURCEVIEW_RAW_UNSUPPORTED                                   + 1
%D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_UNSUPPORTED                                         = %D3D11_MESSAGE_ID_DEVICE_DISPATCH_UNSUPPORTED                                                 + 1
%D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_INVALIDOFFSET                                            = %D3D11_MESSAGE_ID_DEVICE_DISPATCHINDIRECT_UNSUPPORTED                                         + 1
%D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_LARGEOFFSET                                              = %D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_INVALIDOFFSET                                            + 1
%D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_INVALIDDESTINATIONSTATE                                  = %D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_LARGEOFFSET                                              + 1
%D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_INVALIDSOURCESTATE                                       = %D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_INVALIDDESTINATIONSTATE                                  + 1
%D3D11_MESSAGE_ID_CHECKFORMATSUPPORT_FORMAT_NOT_SUPPORTED                                     = %D3D11_MESSAGE_ID_COPYSTRUCTURECOUNT_INVALIDSOURCESTATE                                       + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_INVALIDVIEW                                = %D3D11_MESSAGE_ID_CHECKFORMATSUPPORT_FORMAT_NOT_SUPPORTED                                     + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_INVALIDOFFSET                              = %D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_INVALIDVIEW                                + 1
%D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_TOOMANYVIEWS                               = %D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_INVALIDOFFSET                              + 1
%D3D11_MESSAGE_ID_CLEARUNORDEREDACCESSVIEWFLOAT_INVALIDFORMAT                                 = %D3D11_MESSAGE_ID_DEVICE_CSSETUNORDEREDACCESSVIEWS_TOOMANYVIEWS                               + 1
%D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_COUNTER_UNSUPPORTED                              = %D3D11_MESSAGE_ID_CLEARUNORDEREDACCESSVIEWFLOAT_INVALIDFORMAT                                 + 1
%D3D11_MESSAGE_ID_D3D11_MESSAGES_END                                                          = %D3D11_MESSAGE_ID_DEVICE_UNORDEREDACCESSVIEW_COUNTER_UNSUPPORTED                              + 1

' // Size = 20 bytes
TYPE D3D11_MESSAGE DWORD
   Category              AS LONG         ' D3D11_MESSAGE_CATEGORY
   Severity              AS LONG         ' D3D11_MESSAGE_SEVERITY
   ID                    AS LONG         ' D3D11_MESSAGE_ID
   pDescription          AS ASCIIZ PTR   ' const char *
   DescriptionByteLength AS DWORD        ' SIZE_T
END TYPE

' // Size = 24 bytes
TYPE D3D11_INFO_QUEUE_FILTER_DESC DWORD
   NumCategories AS DWORD       ' UINT
   pCategoryList AS LONG  PTR   ' D3D11_MESSAGE_CATEGORY *
   NumSeverities AS DWORD       ' UINT
   pSeverityList AS LONG  PTR   ' D3D11_MESSAGE_SEVERITY *
   NumIDs        AS DWORD       ' UINT
   pIDList       AS LONG  PTR   ' D3D11_MESSAGE_ID *
END TYPE

' // Size = 48 bytes
TYPE D3D11_INFO_QUEUE_FILTER DWORD
   AllowList AS D3D11_INFO_QUEUE_FILTER_DESC
   DenyList  AS D3D11_INFO_QUEUE_FILTER_DESC
END TYPE

%D3D11_INFO_QUEUE_DEFAULT_MESSAGE_COUNT_LIMIT = 1024

' ########################################################################################
' ID3D11InfoQueue interface
' IID = 6543dbb6-1b48-42f5-ab82-e97ec74326f6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D11InfoQueue_INTERFACE_DEFINED)
    %ID3D11InfoQueue_INTERFACE_DEFINED = 1

INTERFACE ID3D11InfoQueue $IID_ID3D11InfoQueue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMessageCountLimit ( _                      ' VTable offset = 12
     BYVAL MessageCountLimit AS QUAD _                  ' __in UINT64 MessageCountLimit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearStoredMessages ( _                       ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMessage ( _                                ' VTable offset = 20
     BYVAL MessageIndex AS QUAD _                       ' __in UINT64 MessageIndex
   , BYREF pMessage AS D3D11_MESSAGE _                  ' __out D3D11_MESSAGE *pMessage
   , BYREF pMessageByteLength AS DWORD _                ' __inout  SIZE_T *pMessageByteLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumMessagesAllowedByStorageFilter ( _      ' VTable offset = 24
   ) AS QUAD                                            ' UINT64
   ' =====================================================================================
   METHOD GetNumMessagesDeniedByStorageFilter ( _       ' VTable offset = 28
   ) AS QUAD                                            ' UINT64
   ' =====================================================================================
   METHOD GetNumStoredMessages ( _                      ' VTable offset = 32
   ) AS QUAD                                            ' UINT64
   ' =====================================================================================
   METHOD GetNumStoredMessagesAllowedByRetrievalFilter ( _ ' VTable offset = 36
   ) AS QUAD                                            ' UINT64
   ' =====================================================================================
   METHOD GetNumMessagesDiscardedByMessageCountLimit ( _ ' VTable offset = 40
   ) AS QUAD                                            ' UINT64
   ' =====================================================================================
   METHOD GetMessageCountLimit ( _                      ' VTable offset = 44
   ) AS QUAD                                            ' UINT64
   ' =====================================================================================
   METHOD AddStorageFilterEntries ( _                   ' VTable offset = 48
     BYREF pFilter AS D3D11_INFO_QUEUE_FILTER _         ' __in D3D11_INFO_QUEUE_FILTER *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStorageFilter ( _                          ' VTable offset = 52
     BYREF pFilter AS D3D11_INFO_QUEUE_FILTER _         ' __in D3D11_INFO_QUEUE_FILTER *pFilter
   , BYREF pFilterByteLength AS DWORD _                 ' __inout SIZE_T *pFilterByteLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearStorageFilter ( _                        ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD PushEmptyStorageFilter ( _                    ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PushCopyOfStorageFilter ( _                   ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PushStorageFilter ( _                         ' VTable offset = 68
     BYREF pFilter AS D3D11_INFO_QUEUE_FILTER _         ' __in D3D11_INFO_QUEUE_FILTER *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PopStorageFilter ( _                          ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStorageFilterStackSize ( _                 ' VTable offset = 76
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD AddRetrievalFilterEntries ( _                 ' VTable offset = 80
     BYREF pFilter AS D3D11_INFO_QUEUE_FILTER _         ' __in D3D11_INFO_QUEUE_FILTER *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRetrievalFilter ( _                        ' VTable offset = 84
     BYREF pFilter AS D3D11_INFO_QUEUE_FILTER _         ' __in D3D11_INFO_QUEUE_FILTER *pFilter
   , BYREF pFilterByteLength AS DWORD _                 ' __inout SIZE_T *pFilterByteLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearRetrievalFilter ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD PushEmptyRetrievalFilter ( _                  ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PushCopyOfRetrievalFilter ( _                 ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PushRetrievalFilter ( _                       ' VTable offset = 100
     BYREF pFilter AS D3D11_INFO_QUEUE_FILTER _         ' __in D3D11_INFO_QUEUE_FILTER *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PopRetrievalFilter ( _                        ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRetrievalFilterStackSize ( _               ' VTable offset = 108
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD AddMessage ( _                                ' VTable offset = 112
     BYVAL Category AS LONG _                           ' __in D3D11_MESSAGE_CATEGORY Category
   , BYVAL Severity AS LONG _                           ' __in D3D11_MESSAGE_SEVERITY Severity
   , BYVAL ID AS LONG _                                 ' __in D3D11_MESSAGE_ID ID
   , BYREF pDescription AS ASCIIZ _                     ' __in LPCSTR pDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddApplicationMessage ( _                     ' VTable offset = 116
     BYVAL Severity AS LONG _                           ' __in D3D11_MESSAGE_SEVERITY Severity
   , BYREF pDescription AS ASCIIZ _                     ' __in LPCSTR pDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBreakOnCategory ( _                        ' VTable offset = 120
     BYVAL Category AS LONG _                           ' __in D3D11_MESSAGE_CATEGORY Category
   , BYVAL bEnable AS LONG _                            ' __in BOOL bEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBreakOnSeverity ( _                        ' VTable offset = 124
     BYVAL Severity AS LONG _                           ' __in D3D11_MESSAGE_SEVERITY Severity
   , BYVAL bEnable AS LONG _                            ' __in BOOL bEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBreakOnID ( _                              ' VTable offset = 128
     BYVAL ID AS LONG _                                 ' __in D3D11_MESSAGE_ID ID
   , BYVAL bEnable AS LONG _                            ' __in BOOL bEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBreakOnCategory ( _                        ' VTable offset = 132
     BYVAL Category AS LONG _                           ' __in D3D11_MESSAGE_CATEGORY Category
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetBreakOnSeverity ( _                        ' VTable offset = 136
     BYVAL Severity AS LONG _                           ' __in D3D11_MESSAGE_SEVERITY Severity
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetBreakOnID ( _                              ' VTable offset = 140
     BYVAL ID AS LONG _                                 ' __in D3D11_MESSAGE_ID ID
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD SetMuteDebugOutput ( _                        ' VTable offset = 144
     BYVAL bMute AS LONG _                              ' __in BOOL bMute
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMuteDebugOutput ( _                        ' VTable offset = 148
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D11InfoQueue_INTERFACE_DEFINED__ */


'#define D3D11_REGKEY_PATH __TEXT("Software\\Microsoft\\Direct3D")
'#define D3D11_MUTE_DEBUG_OUTPUT __TEXT("MuteDebugOutput")
'#define D3D11_ENABLE_BREAK_ON_MESSAGE __TEXT("EnableBreakOnMessage")
'#define D3D11_INFOQUEUE_STORAGE_FILTER_OVERRIDE __TEXT("InfoQueueStorageFilterOverride")
'#define D3D11_MUTE_CATEGORY __TEXT("Mute_CATEGORY_%s")
'#define D3D11_MUTE_SEVERITY __TEXT("Mute_SEVERITY_%s")
'#define D3D11_MUTE_ID_STRING __TEXT("Mute_ID_%s")
'#define D3D11_MUTE_ID_DECIMAL __TEXT("Mute_ID_%d")
'#define D3D11_UNMUTE_SEVERITY_INFO __TEXT("Unmute_SEVERITY_INFO")
'#define D3D11_BREAKON_CATEGORY __TEXT("BreakOn_CATEGORY_%s")
'#define D3D11_BREAKON_SEVERITY __TEXT("BreakOn_SEVERITY_%s")
'#define D3D11_BREAKON_ID_STRING __TEXT("BreakOn_ID_%s")
'#define D3D11_BREAKON_ID_DECIMAL __TEXT("BreakOn_ID_%d")
'#define D3D11_APPSIZE_STRING __TEXT("Size")
'#define D3D11_APPNAME_STRING __TEXT("Name")

$D3D11_REGKEY_PATH = "Software\\Microsoft\\Direct3D"
$D3D11_MUTE_DEBUG_OUTPUT = "MuteDebugOutput"
$D3D11_ENABLE_BREAK_ON_MESSAGE = "EnableBreakOnMessage"
$D3D11_INFOQUEUE_STORAGE_FILTER_OVERRIDE = "InfoQueueStorageFilterOverride"
$D3D11_MUTE_CATEGORY = "Mute_CATEGORY_%s"
$D3D11_MUTE_SEVERITY = "Mute_SEVERITY_%s"
$D3D11_MUTE_ID_STRING = "Mute_ID_%s"
$D3D11_MUTE_ID_DECIMAL = "Mute_ID_%d"
$D3D11_UNMUTE_SEVERITY_INFO = "Unmute_SEVERITY_INFO"
$D3D11_BREAKON_CATEGORY = "BreakOn_CATEGORY_%s"
$D3D11_BREAKON_SEVERITY = "BreakOn_SEVERITY_%s"
$D3D11_BREAKON_ID_STRING = "BreakOn_ID_%s"
$D3D11_BREAKON_ID_DECIMAL = "BreakOn_ID_%d"
$D3D11_APPSIZE_STRING = "Size"
$D3D11_APPNAME_STRING = "Name"
