'/*
'** Copyright (c) 2007-2012 The Khronos Group Inc.
'**
'** Permission is hereby granted, free of charge, to any person obtaining a
'** copy of this software and/or associated documentation files (the
'** "Materials"), to deal in the Materials without restriction, including
'** without limitation the rights to use, copy, modify, merge, publish,
'** distribute, sublicense, and/or sell copies of the Materials, and to
'** permit persons to whom the Materials are furnished to do so, subject to
'** the following conditions:
'**
'** The above copyright notice and this permission notice shall be included
'** in all copies or substantial portions of the Materials.
'**
'** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
'** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
'** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
'** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
'** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
'** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
'** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
'*/

#INCLUDE THIS ONCE
%WGLEXT_INC = 1

#INCLUDE ONCE "WINDOWS.INC"
#INCLUDE ONCE "GL.INC"
#INCLUDE ONCE "GLU.INC"

'/*************************************************************/

'/* Header file version number */
'/* wglext.h last updated 2012/01/04 */
'/* Current version at http://www.opengl.org/registry/ */

%WGL_WGLEXT_VERSION = 24

#IF NOT %DEF(%WGL_ARB_buffer_region)
%WGL_FRONT_COLOR_BUFFER_BIT_ARB                 = &H00000001???
%WGL_BACK_COLOR_BUFFER_BIT_ARB                  = &H00000002???
%WGL_DEPTH_BUFFER_BIT_ARB                       = &H00000004???
%WGL_STENCIL_BUFFER_BIT_ARB                     = &H00000008???
#ENDIF

#IF NOT %DEF(%WGL_ARB_multisample)
%WGL_SAMPLE_BUFFERS_ARB                         = &H2041???
%WGL_SAMPLES_ARB                                = &H2042???
#ENDIF

#IF NOT %DEF(%WGL_ARB_extensions_string)
#ENDIF

#IF NOT %DEF(%WGL_ARB_pixel_format)
%WGL_NUMBER_PIXEL_FORMATS_ARB                   = &H2000???
%WGL_DRAW_TO_WINDOW_ARB                         = &H2001???
%WGL_DRAW_TO_BITMAP_ARB                         = &H2002???
%WGL_ACCELERATION_ARB                           = &H2003???
%WGL_NEED_PALETTE_ARB                           = &H2004???
%WGL_NEED_SYSTEM_PALETTE_ARB                    = &H2005???
%WGL_SWAP_LAYER_BUFFERS_ARB                     = &H2006???
%WGL_SWAP_METHOD_ARB                            = &H2007???
%WGL_NUMBER_OVERLAYS_ARB                        = &H2008???
%WGL_NUMBER_UNDERLAYS_ARB                       = &H2009???
%WGL_TRANSPARENT_ARB                            = &H200A???
%WGL_TRANSPARENT_RED_VALUE_ARB                  = &H2037???
%WGL_TRANSPARENT_GREEN_VALUE_ARB                = &H2038???
%WGL_TRANSPARENT_BLUE_VALUE_ARB                 = &H2039???
%WGL_TRANSPARENT_ALPHA_VALUE_ARB                = &H203A???
%WGL_TRANSPARENT_INDEX_VALUE_ARB                = &H203B???
%WGL_SHARE_DEPTH_ARB                            = &H200C???
%WGL_SHARE_STENCIL_ARB                          = &H200D???
%WGL_SHARE_ACCUM_ARB                            = &H200E???
%WGL_SUPPORT_GDI_ARB                            = &H200F???
%WGL_SUPPORT_OPENGL_ARB                         = &H2010???
%WGL_DOUBLE_BUFFER_ARB                          = &H2011???
%WGL_STEREO_ARB                                 = &H2012???
%WGL_PIXEL_TYPE_ARB                             = &H2013???
%WGL_COLOR_BITS_ARB                             = &H2014???
%WGL_RED_BITS_ARB                               = &H2015???
%WGL_RED_SHIFT_ARB                              = &H2016???
%WGL_GREEN_BITS_ARB                             = &H2017???
%WGL_GREEN_SHIFT_ARB                            = &H2018???
%WGL_BLUE_BITS_ARB                              = &H2019???
%WGL_BLUE_SHIFT_ARB                             = &H201A???
%WGL_ALPHA_BITS_ARB                             = &H201B???
%WGL_ALPHA_SHIFT_ARB                            = &H201C???
%WGL_ACCUM_BITS_ARB                             = &H201D???
%WGL_ACCUM_RED_BITS_ARB                         = &H201E???
%WGL_ACCUM_GREEN_BITS_ARB                       = &H201F???
%WGL_ACCUM_BLUE_BITS_ARB                        = &H2020???
%WGL_ACCUM_ALPHA_BITS_ARB                       = &H2021???
%WGL_DEPTH_BITS_ARB                             = &H2022???
%WGL_STENCIL_BITS_ARB                           = &H2023???
%WGL_AUX_BUFFERS_ARB                            = &H2024???
%WGL_NO_ACCELERATION_ARB                        = &H2025???
%WGL_GENERIC_ACCELERATION_ARB                   = &H2026???
%WGL_FULL_ACCELERATION_ARB                      = &H2027???
%WGL_SWAP_EXCHANGE_ARB                          = &H2028???
%WGL_SWAP_COPY_ARB                              = &H2029???
%WGL_SWAP_UNDEFINED_ARB                         = &H202A???
%WGL_TYPE_RGBA_ARB                              = &H202B???
%WGL_TYPE_COLORINDEX_ARB                        = &H202C???
#ENDIF

#IF NOT %DEF(%WGL_ARB_make_current_read)
%ERROR_INVALID_PIXEL_TYPE_ARB                   = &H2043???
%ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB         = &H2054???
#ENDIF

#IF NOT %DEF(%WGL_ARB_pbuffer)
%WGL_DRAW_TO_PBUFFER_ARB                        = &H202D???
%WGL_MAX_PBUFFER_PIXELS_ARB                     = &H202E???
%WGL_MAX_PBUFFER_WIDTH_ARB                      = &H202F???
%WGL_MAX_PBUFFER_HEIGHT_ARB                     = &H2030???
%WGL_PBUFFER_LARGEST_ARB                        = &H2033???
%WGL_PBUFFER_WIDTH_ARB                          = &H2034???
%WGL_PBUFFER_HEIGHT_ARB                         = &H2035???
%WGL_PBUFFER_LOST_ARB                           = &H2036???
#ENDIF

#IF NOT %DEF(%WGL_ARB_render_texture)
%WGL_BIND_TO_TEXTURE_RGB_ARB                    = &H2070???
%WGL_BIND_TO_TEXTURE_RGBA_ARB                   = &H2071???
%WGL_TEXTURE_FORMAT_ARB                         = &H2072???
%WGL_TEXTURE_TARGET_ARB                         = &H2073???
%WGL_MIPMAP_TEXTURE_ARB                         = &H2074???
%WGL_TEXTURE_RGB_ARB                            = &H2075???
%WGL_TEXTURE_RGBA_ARB                           = &H2076???
%WGL_NO_TEXTURE_ARB                             = &H2077???
%WGL_TEXTURE_CUBE_MAP_ARB                       = &H2078???
%WGL_TEXTURE_1D_ARB                             = &H2079???
%WGL_TEXTURE_2D_ARB                             = &H207A???
%WGL_MIPMAP_LEVEL_ARB                           = &H207B???
%WGL_CUBE_MAP_FACE_ARB                          = &H207C???
%WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB            = &H207D???
%WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB            = &H207E???
%WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB            = &H207F???
%WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB            = &H2080???
%WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB            = &H2081???
%WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB            = &H2082???
%WGL_FRONT_LEFT_ARB                             = &H2083???
%WGL_FRONT_RIGHT_ARB                            = &H2084???
%WGL_BACK_LEFT_ARB                              = &H2085???
%WGL_BACK_RIGHT_ARB                             = &H2086???
%WGL_AUX0_ARB                                   = &H2087???
%WGL_AUX1_ARB                                   = &H2088???
%WGL_AUX2_ARB                                   = &H2089???
%WGL_AUX3_ARB                                   = &H208A???
%WGL_AUX4_ARB                                   = &H208B???
%WGL_AUX5_ARB                                   = &H208C???
%WGL_AUX6_ARB                                   = &H208D???
%WGL_AUX7_ARB                                   = &H208E???
%WGL_AUX8_ARB                                   = &H208F???
%WGL_AUX9_ARB                                   = &H2090???
#ENDIF

#IF NOT %DEF(%WGL_ARB_pixel_format_float)
%WGL_TYPE_RGBA_FLOAT_ARB                        = &H21A0???
#ENDIF

#IF NOT %DEF(%WGL_ARB_framebuffer_sRGB)
%WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB               = &H20A9???
#ENDIF

#IF NOT %DEF(%WGL_ARB_create_context)
%WGL_CONTEXT_DEBUG_BIT_ARB                      = &H00000001???
%WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB         = &H00000002???
%WGL_CONTEXT_MAJOR_VERSION_ARB                  = &H2091???
%WGL_CONTEXT_MINOR_VERSION_ARB                  = &H2092???
%WGL_CONTEXT_LAYER_PLANE_ARB                    = &H2093???
%WGL_CONTEXT_FLAGS_ARB                          = &H2094???
%ERROR_INVALID_VERSION_ARB                      = &H2095???
#ENDIF

#IF NOT %DEF(%WGL_ARB_create_context_profile)
%WGL_CONTEXT_PROFILE_MASK_ARB                   = &H9126???
%WGL_CONTEXT_CORE_PROFILE_BIT_ARB               = &H00000001???
%WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB      = &H00000002???
%ERROR_INVALID_PROFILE_ARB                      = &H2096???
#ENDIF

#IF NOT %DEF(%WGL_ARB_create_context_robustness)
%WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB              = &H00000004???
%WGL_LOSE_CONTEXT_ON_RESET_ARB                  = &H8252???
%WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB    = &H8256???
%WGL_NO_RESET_NOTIFICATION_ARB                  = &H8261???
#ENDIF

#IF NOT %DEF(%WGL_EXT_make_current_read)
%ERROR_INVALID_PIXEL_TYPE_EXT                   = &H2043???
#ENDIF

#IF NOT %DEF(%WGL_EXT_pixel_format)
%WGL_NUMBER_PIXEL_FORMATS_EXT                   = &H2000???
%WGL_DRAW_TO_WINDOW_EXT                         = &H2001???
%WGL_DRAW_TO_BITMAP_EXT                         = &H2002???
%WGL_ACCELERATION_EXT                           = &H2003???
%WGL_NEED_PALETTE_EXT                           = &H2004???
%WGL_NEED_SYSTEM_PALETTE_EXT                    = &H2005???
%WGL_SWAP_LAYER_BUFFERS_EXT                     = &H2006???
%WGL_SWAP_METHOD_EXT                            = &H2007???
%WGL_NUMBER_OVERLAYS_EXT                        = &H2008???
%WGL_NUMBER_UNDERLAYS_EXT                       = &H2009???
%WGL_TRANSPARENT_EXT                            = &H200A???
%WGL_TRANSPARENT_VALUE_EXT                      = &H200B???
%WGL_SHARE_DEPTH_EXT                            = &H200C???
%WGL_SHARE_STENCIL_EXT                          = &H200D???
%WGL_SHARE_ACCUM_EXT                            = &H200E???
%WGL_SUPPORT_GDI_EXT                            = &H200F???
%WGL_SUPPORT_OPENGL_EXT                         = &H2010???
%WGL_DOUBLE_BUFFER_EXT                          = &H2011???
%WGL_STEREO_EXT                                 = &H2012???
%WGL_PIXEL_TYPE_EXT                             = &H2013???
%WGL_COLOR_BITS_EXT                             = &H2014???
%WGL_RED_BITS_EXT                               = &H2015???
%WGL_RED_SHIFT_EXT                              = &H2016???
%WGL_GREEN_BITS_EXT                             = &H2017???
%WGL_GREEN_SHIFT_EXT                            = &H2018???
%WGL_BLUE_BITS_EXT                              = &H2019???
%WGL_BLUE_SHIFT_EXT                             = &H201A???
%WGL_ALPHA_BITS_EXT                             = &H201B???
%WGL_ALPHA_SHIFT_EXT                            = &H201C???
%WGL_ACCUM_BITS_EXT                             = &H201D???
%WGL_ACCUM_RED_BITS_EXT                         = &H201E???
%WGL_ACCUM_GREEN_BITS_EXT                       = &H201F???
%WGL_ACCUM_BLUE_BITS_EXT                        = &H2020???
%WGL_ACCUM_ALPHA_BITS_EXT                       = &H2021???
%WGL_DEPTH_BITS_EXT                             = &H2022???
%WGL_STENCIL_BITS_EXT                           = &H2023???
%WGL_AUX_BUFFERS_EXT                            = &H2024???
%WGL_NO_ACCELERATION_EXT                        = &H2025???
%WGL_GENERIC_ACCELERATION_EXT                   = &H2026???
%WGL_FULL_ACCELERATION_EXT                      = &H2027???
%WGL_SWAP_EXCHANGE_EXT                          = &H2028???
%WGL_SWAP_COPY_EXT                              = &H2029???
%WGL_SWAP_UNDEFINED_EXT                         = &H202A???
%WGL_TYPE_RGBA_EXT                              = &H202B???
%WGL_TYPE_COLORINDEX_EXT                        = &H202C???
#ENDIF

#IF NOT %DEF(%WGL_EXT_pbuffer)
%WGL_DRAW_TO_PBUFFER_EXT                        = &H202D???
%WGL_MAX_PBUFFER_PIXELS_EXT                     = &H202E???
%WGL_MAX_PBUFFER_WIDTH_EXT                      = &H202F???
%WGL_MAX_PBUFFER_HEIGHT_EXT                     = &H2030???
%WGL_OPTIMAL_PBUFFER_WIDTH_EXT                  = &H2031???
%WGL_OPTIMAL_PBUFFER_HEIGHT_EXT                 = &H2032???
%WGL_PBUFFER_LARGEST_EXT                        = &H2033???
%WGL_PBUFFER_WIDTH_EXT                          = &H2034???
%WGL_PBUFFER_HEIGHT_EXT                         = &H2035???
#ENDIF

#IF NOT %DEF(%WGL_EXT_depth_float)
%WGL_DEPTH_FLOAT_EXT                            = &H2040???
#ENDIF

#IF NOT %DEF(%WGL_3DFX_multisample)
%WGL_SAMPLE_BUFFERS_3DFX                        = &H2060???
%WGL_SAMPLES_3DFX                               = &H2061???
#ENDIF

#IF NOT %DEF(%WGL_EXT_multisample)
%WGL_SAMPLE_BUFFERS_EXT                         = &H2041???
%WGL_SAMPLES_EXT                                = &H2042???
#ENDIF

#IF NOT %DEF(%WGL_I3D_digital_video_control)
%WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D = &H2050???
%WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D       = &H2051???
%WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D          = &H2052???
%WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D          = &H2053???
#ENDIF

#IF NOT %DEF(%WGL_I3D_gamma)
%WGL_GAMMA_TABLE_SIZE_I3D                       = &H204E???
%WGL_GAMMA_EXCLUDE_DESKTOP_I3D                  = &H204F???
#ENDIF

#IF NOT %DEF(%WGL_I3D_genlock)
%WGL_GENLOCK_SOURCE_MULTIVIEW_I3D               = &H2044???
%WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D            = &H2045???
%WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D           = &H2046???
%WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D             = &H2047???
%WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D            = &H2048???
%WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D           = &H2049???
%WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D            = &H204A???
%WGL_GENLOCK_SOURCE_EDGE_RISING_I3D             = &H204B???
%WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D               = &H204C???
#ENDIF

#IF NOT %DEF(%WGL_I3D_image_buffer)
%WGL_IMAGE_BUFFER_MIN_ACCESS_I3D                = &H00000001???
%WGL_IMAGE_BUFFER_LOCK_I3D                      = &H00000002???
#ENDIF

#IF NOT %DEF(%WGL_I3D_swap_frame_lock)
#ENDIF

#IF NOT %DEF(%WGL_NV_render_depth_texture)
%WGL_BIND_TO_TEXTURE_DEPTH_NV                   = &H20A3???
%WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV         = &H20A4???
%WGL_DEPTH_TEXTURE_FORMAT_NV                    = &H20A5???
%WGL_TEXTURE_DEPTH_COMPONENT_NV                 = &H20A6???
%WGL_DEPTH_COMPONENT_NV                         = &H20A7???
#ENDIF

#IF NOT %DEF(%WGL_NV_render_texture_rectangle)
%WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV           = &H20A0???
%WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV          = &H20A1???
%WGL_TEXTURE_RECTANGLE_NV                       = &H20A2???
#ENDIF

#IF NOT %DEF(%WGL_ATI_pixel_format_float)
%WGL_TYPE_RGBA_FLOAT_ATI                        = &H21A0???
#ENDIF

#IF NOT %DEF(%WGL_NV_float_buffer)
%WGL_FLOAT_COMPONENTS_NV                        = &H20B0???
%WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV       = &H20B1???
%WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV      = &H20B2???
%WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV     = &H20B3???
%WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV    = &H20B4???
%WGL_TEXTURE_FLOAT_R_NV                         = &H20B5???
%WGL_TEXTURE_FLOAT_RG_NV                        = &H20B6???
%WGL_TEXTURE_FLOAT_RGB_NV                       = &H20B7???
%WGL_TEXTURE_FLOAT_RGBA_NV                      = &H20B8???
#ENDIF

#IF NOT %DEF(%WGL_3DL_stereo_control)
%WGL_STEREO_EMITTER_ENABLE_3DL                  = &H2055???
%WGL_STEREO_EMITTER_DISABLE_3DL                 = &H2056???
%WGL_STEREO_POLARITY_NORMAL_3DL                 = &H2057???
%WGL_STEREO_POLARITY_INVERT_3DL                 = &H2058???
#ENDIF

#IF NOT %DEF(%WGL_EXT_pixel_format_packed_float)
%WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT               = &H20A8???
#ENDIF

#IF NOT %DEF(%WGL_EXT_framebuffer_sRGB)
%WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT               = &H20A9???
#ENDIF

#IF NOT %DEF(%WGL_NV_present_video)
%WGL_NUM_VIDEO_SLOTS_NV                         = &H20F0???
#ENDIF

#IF NOT %DEF(%WGL_NV_video_out)
%WGL_BIND_TO_VIDEO_RGB_NV                       = &H20C0???
%WGL_BIND_TO_VIDEO_RGBA_NV                      = &H20C1???
%WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV             = &H20C2???
%WGL_VIDEO_OUT_COLOR_NV                         = &H20C3???
%WGL_VIDEO_OUT_ALPHA_NV                         = &H20C4???
%WGL_VIDEO_OUT_DEPTH_NV                         = &H20C5???
%WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV               = &H20C6???
%WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV               = &H20C7???
%WGL_VIDEO_OUT_FRAME                            = &H20C8???
%WGL_VIDEO_OUT_FIELD_1                          = &H20C9???
%WGL_VIDEO_OUT_FIELD_2                          = &H20CA???
%WGL_VIDEO_OUT_STACKED_FIELDS_1_2               = &H20CB???
%WGL_VIDEO_OUT_STACKED_FIELDS_2_1               = &H20CC???
#ENDIF

#IF NOT %DEF(%WGL_NV_swap_group)
#ENDIF

#IF NOT %DEF(%WGL_NV_gpu_affinity)
%WGL_ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV      = &H20D0???
%WGL_ERROR_MISSING_AFFINITY_MASK_NV            = &H20D1???
#ENDIF

#IF NOT %DEF(%WGL_AMD_gpu_association)
%WGL_GPU_VENDOR_AMD                            = &H1F00???
%WGL_GPU_RENDERER_STRING_AMD                   = &H1F01???
%WGL_GPU_OPENGL_VERSION_STRING_AMD             = &H1F02???
%WGL_GPU_FASTEST_TARGET_GPUS_AMD               = &H21A2???
%WGL_GPU_RAM_AMD                               = &H21A3???
%WGL_GPU_CLOCK_AMD                             = &H21A4???
%WGL_GPU_NUM_PIPES_AMD                         = &H21A5???
%WGL_GPU_NUM_SIMD_AMD                          = &H21A6???
%WGL_GPU_NUM_RB_AMD                            = &H21A7???
%WGL_GPU_NUM_SPI_AMD                           = &H21A8???
#ENDIF

#IF NOT %DEF(%WGL_NV_video_capture)
%WGL_UNIQUE_ID_NV                              = &H20CE???
%WGL_NUM_VIDEO_CAPTURE_SLOTS_NV                = &H20CF???
#ENDIF

#IF NOT %DEF(%WGL_NV_copy_image)
#ENDIF

#IF NOT %DEF(%WGL_NV_multisample_coverage)
%WGL_COVERAGE_SAMPLES_NV                       = &H2042
%WGL_COLOR_SAMPLES_NV                          = &H20B9
#ENDIF

#IF NOT %DEF(%WGL_EXT_create_context_es2_profile)
%WGL_CONTEXT_ES2_PROFILE_BIT_EXT               = &H00000004???
#ENDIF

#IF NOT %DEF(%WGL_NV_DX_interop)
%WGL_ACCESS_READ_ONLY_NV                       = &H00000000???
%WGL_ACCESS_READ_WRITE_NV                      = &H00000001???
%WGL_ACCESS_WRITE_DISCARD_NV                   = &H00000002???
#ENDIF

#IF NOT %DEF(%WGL_NV_DX_interop2)
#ENDIF

#IF NOT %DEF(%WGL_EXT_swap_control_tear)
#ENDIF

'/*************************************************************/

'#IF NOT %DEF(%WGL_ARB_pbuffer)
'DECLARE_HANDLE(HPBUFFERARB);
'#ENDIF
'#IF NOT %DEF(%WGL_EXT_pbuffer)
'DECLARE_HANDLE(HPBUFFEREXT);
'#ENDIF
'#IF NOT %DEF(%WGL_NV_present_video)
'DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
'#ENDIF
'#IF NOT %DEF(%WGL_NV_video_output)
'DECLARE_HANDLE(HPVIDEODEV);
'#ENDIF

#IF NOT %DEF(%WGL_NV_gpu_affinity)
'DECLARE_HANDLE(HPGPUNV);
'DECLARE_HANDLE(HGPUNV);

' // Size = 184 bytes
TYPE GPU_DEVICE DWORD
   cb              AS DWORD          ' DWORD
   DeviceName      AS ASCIIZ * 32    ' CHAR [32]
   DeviceString    AS ASCIIZ * 128   ' CHAR [128]
   Flags           AS DWORD          ' DWORD
   rcVirtualScreen AS RECT           ' RECT
END TYPE
#ENDIF

'#IF NOT %DEF(%WGL_NV_video_capture)
'DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
'#ENDIF

'#IF NOT %DEF(%WGL_ARB_buffer_region)
'%WGL_ARB_buffer_region = 1

' ========================================================================================
' HANDLE wglCreateBufferRegionARB (HDC hDC, int iLayerPlane, UINT uType);
' ========================================================================================
DECLARE FUNCTION wglCreateBufferRegionARB (BYVAL hdc AS DWORD, BYVAL iLayerPlane AS LONG, BYVAL uType AS DWORD) AS DWORD

' ========================================================================================
' VOID wglDeleteBufferRegionARB (HANDLE hRegion);
' ========================================================================================
DECLARE SUB wglDeleteBufferRegionARB (BYVAL hRegion AS DWORD)

' ========================================================================================
' BOOL wglSaveBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height);
' ========================================================================================
DECLARE FUNCTION wglSaveBufferRegionARB (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG) AS LONG

' ========================================================================================
' BOOL wglRestoreBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
' ========================================================================================
DECLARE FUNCTION wglRestoreBufferRegionARB (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG, BYVAL xSrc AS LONG, BYVAL ySrc AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_multisample)
'%WGL_ARB_multisample = 1
'#ENDIF

'#IF NOT %DEF(%WGL_ARB_extensions_string)
'%WGL_ARB_extensions_string = 1

' ========================================================================================
' const char * wglGetExtensionsStringARB (HDC hdc);
' ========================================================================================
DECLARE FUNCTION wglGetExtensionsStringARB (BYVAL hdc AS DWORD) AS DWORD

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_pixel_format)
'%WGL_ARB_pixel_format = 1

' ========================================================================================
' BOOL wglGetPixelFormatAttribivARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
' ========================================================================================
DECLARE FUNCTION wglGetPixelFormatAttribivARB (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS LONG, BYREF piAttributes AS LONG, BYREF piValues AS LONG) AS LONG

' ========================================================================================
' BOOL wglGetPixelFormatAttribfvARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
' ========================================================================================
DECLARE FUNCTION wglGetPixelFormatAttribfvARB (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS LONG, BYREF piAttributes AS LONG, BYREF pfValues AS SINGLE) AS LONG

' ========================================================================================
' BOOL wglChoosePixelFormatARB (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
' ========================================================================================
DECLARE FUNCTION wglChoosePixelFormatARB (BYVAL hdc AS DWORD, BYREF piAttribIList AS LONG, BYREF pfAttribFList AS SINGLE, BYVAL nMaxFormats AS DWORD, BYREF piFormats AS LONG, BYREF nNumFormats AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_make_current_read)
'%WGL_ARB_make_current_read = 1

' ========================================================================================
' BOOL wglMakeContextCurrentARB (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
' ========================================================================================
DECLARE FUNCTION wglMakeContextCurrentARB (BYVAL hDrawDC AS DWORD, BYVAL hReadDC AS DWORD, BYVAL hglrc AS DWORD) AS LONG

' ========================================================================================
' HDC wglGetCurrentReadDCARB (void);
' ========================================================================================
DECLARE FUNCTION wglGetCurrentReadDCARB () AS DWORD

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_pbuffer)
'%WGL_ARB_pbuffer = 1

' ========================================================================================
' HPBUFFERARB wglCreatePbufferARB (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
' ========================================================================================
DECLARE FUNCTION wglCreatePbufferARB (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG, BYREF piAttribList AS LONG) AS DWORD

' ========================================================================================
' HDC wglGetPbufferDCARB (HPBUFFERARB hPbuffer);
' ========================================================================================
DECLARE FUNCTION wglGetPbufferDCARB (BYVAL hPbuffer AS DWORD) AS DWORD

' ========================================================================================
' int wglReleasePbufferDCARB (HPBUFFERARB hPbuffer, HDC hDC);
' ========================================================================================
DECLARE FUNCTION wglReleasePbufferDCARB (BYVAL hPbuffer AS DWORD, BYVAL hdc AS DWORD) AS LONG

' ========================================================================================
' BOOL wglDestroyPbufferARB (HPBUFFERARB hPbuffer);
' ========================================================================================
DECLARE FUNCTION wglDestroyPbufferARB (BYVAL hPbuffer AS DWORD) AS LONG

' ========================================================================================
' BOOL wglQueryPbufferARB (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
' ========================================================================================
DECLARE FUNCTION wglQueryPbufferARB (BYVAL hPbuffer AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_render_texture)
'%WGL_ARB_render_texture = 1

' ========================================================================================
' BOOL wglBindTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
' ========================================================================================
DECLARE FUNCTION wglBindTexImageARB (BYVAL hPbuffer AS DWORD, BYVAL iBuffer AS LONG) AS LONG

' ========================================================================================
' BOOL wglReleaseTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
' ========================================================================================
DECLARE FUNCTION wglReleaseTexImageARB (BYVAL hPbuffer AS DWORD, BYVAL iBuffer AS LONG) AS LONG

' ========================================================================================
' BOOL wglSetPbufferAttribARB (HPBUFFERARB hPbuffer, const int *piAttribList);
' ========================================================================================
DECLARE FUNCTION wglSetPbufferAttribARB (BYVAL hPbuffer AS DWORD, BYREF piAttribList AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_pixel_format_float)
'%WGL_ARB_pixel_format_float = 1
'#ENDIF

'#IF NOT %DEF(%WGL_ARB_framebuffer_sRGB)
'%WGL_ARB_framebuffer_sRGB = 1
'#ENDIF

'#IF NOT %DEF(%WGL_ARB_create_context)
'%WGL_ARB_create_context = 1

' ========================================================================================
' HGLRC wglCreateContextAttribsARB (HDC hDC, HGLRC hShareContext, const int *attribList);
' ========================================================================================
DECLARE FUNCTION wglCreateContextAttribsARB (BYVAL hdc AS DWORD, BYVAL hShareContext AS DWORD, BYREF attribList AS LONG) AS DWORD

'#ENDIF

'#IF NOT %DEF(%WGL_ARB_create_context_profile)
'%WGL_ARB_create_context_profile = 1
'#ENDIF

'#IF NOT %DEF(%WGL_ARB_create_context_robustness)
'%WGL_ARB_create_context_robustness = 1
'#ENDIF

'#IF NOT %DEF(%WGL_EXT_display_color_table)
'%WGL_EXT_display_color_table = 1

' ========================================================================================
' GLboolean wglCreateDisplayColorTableEXT (GLushort id);
' ========================================================================================
DECLARE FUNCTION wglCreateDisplayColorTableEXT (BYVAL id AS WORD) AS BYTE

' ========================================================================================
' GLboolean wglLoadDisplayColorTableEXT (const GLushort *table, GLuint length);
' ========================================================================================
DECLARE FUNCTION wglLoadDisplayColorTableEXT (BYREF table AS WORD, BYVAL length AS DWORD) AS BYTE

' ========================================================================================
' GLboolean wglBindDisplayColorTableEXT (GLushort id);
' ========================================================================================
DECLARE FUNCTION wglBindDisplayColorTableEXT (BYVAL id AS WORD) AS BYTE

' ========================================================================================
' VOID wglDestroyDisplayColorTableEXT (GLushort id);
' ========================================================================================
DECLARE SUB wglDestroyDisplayColorTableEXT (BYVAL id AS WORD)

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_extensions_string)
'%WGL_EXT_extensions_string = 1

' ========================================================================================
' const char * wglGetExtensionsStringEXT (void);
' ========================================================================================
DECLARE FUNCTION wglGetExtensionsStringEXT () AS DWORD

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_make_current_read)
'%WGL_EXT_make_current_read = 1

' ========================================================================================
' BOOL wglMakeContextCurrentEXT (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
' ========================================================================================
DECLARE FUNCTION wglMakeContextCurrentEXT (BYVAL hDrawDC AS DWORD, BYVAL hReadDC AS DWORD, BYVAL hglrc AS DWORD) AS LONG

' ========================================================================================
' HDC wglGetCurrentReadDCEXT (void);
' ========================================================================================
DECLARE FUNCTION wglGetCurrentReadDCEXT () AS DWORD

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_pbuffer)
'%WGL_EXT_pbuffer = 1

' ========================================================================================
' HPBUFFEREXT wglCreatePbufferEXT (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
' ========================================================================================
DECLARE FUNCTION wglCreatePbufferEXT (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG, BYREF piAttribList AS LONG) AS DWORD

' ========================================================================================
' HDC wglGetPbufferDCEXT (HPBUFFEREXT hPbuffer);
' ========================================================================================
DECLARE FUNCTION wglGetPbufferDCEXT (BYVAL hPbuffer AS DWORD) AS DWORD

' ========================================================================================
' int wglReleasePbufferDCEXT (HPBUFFEREXT hPbuffer, HDC hDC);
' ========================================================================================
DECLARE FUNCTION wglReleasePbufferDCEXT (BYVAL hPbuffer AS DWORD, BYVAL hdc AS DWORD) AS LONG

' ========================================================================================
' BOOL wglDestroyPbufferEXT (HPBUFFEREXT hPbuffer);
' ========================================================================================
DECLARE FUNCTION wglDestroyPbufferEXT (BYVAL hPbuffer AS DWORD) AS LONG

' ========================================================================================
' BOOL wglQueryPbufferEXT (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
' ========================================================================================
DECLARE FUNCTION wglQueryPbufferEXT (BYVAL hPbuffer AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_pixel_format)
'%WGL_EXT_pixel_format = 1

' ========================================================================================
' BOOL wglGetPixelFormatAttribivEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
' ========================================================================================
DECLARE FUNCTION wglGetPixelFormatAttribivEXT (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS DWORD, BYREF piAttributes AS LONG, BYREF piValues AS LONG) AS LONG

' ========================================================================================
' BOOL wglGetPixelFormatAttribfvEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
' ========================================================================================
DECLARE FUNCTION wglGetPixelFormatAttribfvEXT (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS DWORD, BYREF piAttributes AS LONG,  BYREF pfValues AS SINGLE) AS LONG

' ========================================================================================
' BOOL wglChoosePixelFormatEXT (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
' ========================================================================================
DECLARE FUNCTION wglChoosePixelFormatEXT (BYVAL hdc AS DWORD, BYREF piAttribIList AS LONG, BYREF pfAttribFList AS SINGLE, BYVAL nMaxFormats AS DWORD, BYREF piFormats AS LONG,  BYREF nNumFormats AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_swap_control)
'%WGL_EXT_swap_control = 1

' ========================================================================================
' BOOL wglSwapIntervalEXT (int interval);
' ========================================================================================
DECLARE FUNCTION wglSwapIntervalEXT (BYVAL nInterval AS LONG) AS LONG

' ========================================================================================
' int wglGetSwapIntervalEXT (void);
' ========================================================================================
DECLARE FUNCTION wglGetSwapIntervalEXT () AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_depth_float)
'%WGL_EXT_depth_float = 1
'#ENDIF

'#IF NOT %DEF(%WGL_NV_vertex_array_range)
'%WGL_NV_vertex_array_range = 1

' ========================================================================================
' void* wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
' ========================================================================================
DECLARE FUNCTION wglAllocateMemoryNV (BYVAL iSize AS LONG, BYVAL readfreq AS SINGLE, BYVAL writefreq AS SINGLE, BYVAL fpriority AS SINGLE) AS DWORD

' ========================================================================================
' void wglFreeMemoryNV (void *pointer);
' ========================================================================================
DECLARE SUB wglFreeMemoryNV (BYVAL dwPointer AS DWORD)

'#ENDIF

'#IF NOT %DEF(%WGL_3DFX_multisample)
'%WGL_3DFX_multisample = 1
'#ENDIF

'#IF NOT %DEF(%WGL_EXT_multisample)
'%WGL_EXT_multisample = 1
'#ENDIF

'#IF NOT %DEF(%WGL_OML_sync_control)
'%WGL_OML_sync_control = 1

' ========================================================================================
' BOOL wglGetSyncValuesOML (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
' ========================================================================================
DECLARE FUNCTION wglGetSyncValuesOML (BYVAL hdc AS DWORD, BYREF ust AS QUAD, BYREF msc AS QUAD, BYREF sbc AS QUAD) AS LONG

' ========================================================================================
' BOOL wglGetMscRateOML (HDC hdc, INT32 *numerator, INT32 *denominator);
' ========================================================================================
DECLARE FUNCTION wglGetMscRateOML (BYVAL hdc AS DWORD, BYREF numerator AS LONG, BYREF denominator AS LONG) AS LONG

' ========================================================================================
' INT64 wglSwapBuffersMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
' ========================================================================================
DECLARE FUNCTION wglSwapBuffersMscOML (BYVAL hdc AS DWORD, BYVAL target_msc AS QUAD, BYVAL divisor AS QUAD, BYVAL remainder AS QUAD) AS QUAD

' ========================================================================================
' INT64 wglSwapLayerBuffersMscOML (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
' ========================================================================================
DECLARE FUNCTION wglSwapLayerBuffersMscOML (BYVAL hdc AS DWORD, BYVAL fuPlanes AS LONG, BYVAL target_msc AS QUAD, BYVAL divisor AS QUAD, BYVAL remainder AS QUAD) AS QUAD

' ========================================================================================
' BOOL wglWaitForMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
' ========================================================================================
DECLARE FUNCTION wglWaitForMscOML (BYVAL hdc AS DWORD, BYVAL target_msc AS QUAD, BYVAL divisor AS QUAD, BYVAL remainder AS QUAD, BYREF ust AS QUAD, BYREF msc AS QUAD, BYREF sbc AS QUAD) AS LONG

' ========================================================================================
' BOOL wglWaitForSbcOML (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
' ========================================================================================
DECLARE FUNCTION wglWaitForSbcOML (BYVAL hdc AS DWORD, BYVAL target_msc AS QUAD, BYREF ust AS QUAD, BYREF msc AS QUAD, BYREF sbc AS QUAD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_I3D_digital_video_control)
'%WGL_I3D_digital_video_control = 1

' ========================================================================================
' BOOL wglGetDigitalVideoParametersI3D (HDC hDC, int iAttribute, int *piValue);
' ========================================================================================
DECLARE FUNCTION wglGetDigitalVideoParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

' ========================================================================================
' BOOL wglSetDigitalVideoParametersI3D (HDC hDC, int iAttribute, const int *piValue);
' ========================================================================================
DECLARE FUNCTION wglSetDigitalVideoParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_I3D_gamma)
'%WGL_I3D_gamma = 1

' ========================================================================================
' BOOL wglGetGammaTableParametersI3D (HDC hDC, int iAttribute, int *piValue);
' ========================================================================================
DECLARE FUNCTION wglGetGammaTableParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

' ========================================================================================
' BOOL wglSetGammaTableParametersI3D (HDC hDC, int iAttribute, const int *piValue);
' ========================================================================================
DECLARE FUNCTION wglSetGammaTableParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

' ========================================================================================
' BOOL wglGetGammaTableI3D (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
' ========================================================================================
DECLARE FUNCTION wglGetGammaTableI3D (BYVAL hdc AS DWORD, BYVAL iEntries AS LONG, BYREF puRed AS WORD, BYREF puGreen AS WORD, BYREF puBlue AS WORD) AS LONG

' ========================================================================================
' BOOL wglSetGammaTableI3D (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
' ========================================================================================
DECLARE FUNCTION wglSetGammaTableI3D (BYVAL hdc AS DWORD, BYVAL iEntries AS LONG, BYREF puRed AS WORD, BYREF puGreen AS WORD, BYREF puBlue AS WORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_I3D_genlock)
'%WGL_I3D_genlock = 1

' ========================================================================================
' BOOL wglEnableGenlockI3D (HDC hDC);
' ========================================================================================
DECLARE FUNCTION wglEnableGenlockI3D (BYVAL hdc AS DWORD) AS LONG

' ========================================================================================
' BOOL wglDisableGenlockI3D (HDC hDC);
' ========================================================================================
DECLARE FUNCTION wglDisableGenlockI3D (BYVAL hdc AS DWORD) AS LONG

' ========================================================================================
' BOOL wglIsEnabledGenlockI3D (HDC hDC, BOOL *pFlag);
' ========================================================================================
DECLARE FUNCTION wglIsEnabledGenlockI3D (BYVAL hdc AS DWORD, BYREF pFlag AS LONG) AS LONG

' ========================================================================================
' BOOL wglGenlockSourceI3D (HDC hDC, UINT uSource);
' ========================================================================================
DECLARE FUNCTION wglGenlockSourceI3D (BYVAL hdc AS DWORD, BYVAL uSource AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGetGenlockSourceI3D (HDC hDC, UINT *uSource);
' ========================================================================================
DECLARE FUNCTION wglGetGenlockSourceI3D (BYVAL hdc AS DWORD, BYREF uSource AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGenlockSourceEdgeI3D (HDC hDC, UINT uEdge);
' ========================================================================================
DECLARE FUNCTION wglGenlockSourceEdgeI3D (BYVAL hdc AS DWORD, BYVAL uEdge AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGetGenlockSourceEdgeI3D (HDC hDC, UINT *uEdge);
' ========================================================================================
DECLARE FUNCTION wglGetGenlockSourceI3D (BYVAL hdc AS DWORD, BYREF uEdge AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGenlockSampleRateI3D (HDC hDC, UINT uRate);
' ========================================================================================
DECLARE FUNCTION wglGenlockSampleRateI3D (BYVAL hdc AS DWORD, BYVAL uRate AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGetGenlockSampleRateI3D (HDC hDC, UINT *uRate);
' ========================================================================================
DECLARE FUNCTION wglGetGenlockSampleRateI3D (BYVAL hdc AS DWORD, BYREF uRate AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGenlockSourceDelayI3D (HDC hDC, UINT uDelay);
' ========================================================================================
DECLARE FUNCTION wglGenlockSourceDelayI3D (BYVAL hdc AS DWORD, BYVAL uDelay AS DWORD) AS LONG

' ========================================================================================
' BOOL wglGetGenlockSourceDelayI3D (HDC hDC, UINT *uDelay);
' ========================================================================================
DECLARE FUNCTION wglGetGenlockSourceDelayI3D (BYVAL hdc AS DWORD, BYREF uDelay AS DWORD) AS LONG

' ========================================================================================
' BOOL wglQueryGenlockMaxSourceDelayI3D (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
' ========================================================================================
DECLARE FUNCTION wglQueryGenlockMaxSourceDelayI3D (BYVAL hdc AS DWORD, BYREF uMaxLineDelay AS DWORD, BYREF uMaxPixelDelay AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_I3D_image_buffer)
'%WGL_I3D_image_buffer = 1

' ========================================================================================
' LPVOID wglCreateImageBufferI3D (HDC hDC, DWORD dwSize, UINT uFlags);
' ========================================================================================
DECLARE FUNCTION wglCreateImageBufferI3D (BYVAL hdc AS DWORD, BYVAL dwSize AS DWORD, BYVAL uFlags AS DWORD) AS DWORD

' ========================================================================================
' BOOL wglDestroyImageBufferI3D (HDC hDC, LPVOID pAddress);
' ========================================================================================
DECLARE FUNCTION wglDestroyImageBufferI3D (BYVAL hdc AS DWORD, BYVAL pAddress AS DWORD) AS LONG

' ========================================================================================
' BOOL wglAssociateImageBufferEventsI3D (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
' ========================================================================================
DECLARE FUNCTION wglAssociateImageBufferEventsI3D (BYVAL hdc AS DWORD, BYREF pEvent AS DWORD, BYREF pAddress AS DWORD, BYREF pSize AS DWORD, BYVAL dwCount AS DWORD) AS LONG

' ========================================================================================
' BOOL wglReleaseImageBufferEventsI3D (HDC hDC, const LPVOID *pAddress, UINT count);
' ========================================================================================
DECLARE FUNCTION wglReleaseImageBufferEventsI3D (BYVAL hdc AS DWORD, BYREF pAddress AS DWORD, BYVAL dwCount AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_I3D_swap_frame_lock)
'%WGL_I3D_swap_frame_lock = 1

' ========================================================================================
' BOOL wglEnableFrameLockI3D (void);
' ========================================================================================
DECLARE FUNCTION wglEnableFrameLockI3D () AS LONG

' ========================================================================================
' BOOL wglDisableFrameLockI3D (void);
' ========================================================================================
DECLARE FUNCTION wglDisableFrameLockI3D () AS LONG

' ========================================================================================
' BOOL wglIsEnabledFrameLockI3D (BOOL *pFlag);
' ========================================================================================
DECLARE FUNCTION wglIsEnabledFrameLockI3D (BYREF pFlag AS LONG) AS LONG

' ========================================================================================
' BOOL wglQueryFrameLockMasterI3D (BOOL *pFlag);
' ========================================================================================
DECLARE FUNCTION wglQueryFrameLockMasterI3D (BYREF pFlag AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_I3D_swap_frame_usage)
'%WGL_I3D_swap_frame_usage = 1

' ========================================================================================
' BOOL wglGetFrameUsageI3D (float *pUsage);
' ========================================================================================
DECLARE FUNCTION wglGetFrameUsageI3D (BYREF pUsage AS SINGLE) AS LONG

' ========================================================================================
' BOOL wglBeginFrameTrackingI3D (void);
' ========================================================================================
DECLARE FUNCTION wglBeginFrameTrackingI3D () AS LONG

' ========================================================================================
' BOOL wglEndFrameTrackingI3D (void);
' ========================================================================================
DECLARE FUNCTION wglEndFrameTrackingI3D () AS LONG

' ========================================================================================
' BOOL wglQueryFrameTrackingI3D (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
' ========================================================================================
DECLARE FUNCTION wglQueryFrameTrackingI3D (BYREF pFrameCount AS DWORD, BYREF pMissedFrames AS DWORD, BYREF pLastMissedUsage AS SINGLE) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_ATI_pixel_format_float)
'%WGL_ATI_pixel_format_float = 1
'#ENDIF

'#IF NOT %DEF(%WGL_NV_float_buffer)
'%WGL_NV_float_buffer = 1
'#ENDIF

'#IF NOT %DEF(%WGL_3DL_stereo_control)
'%WGL_3DL_stereo_control = 1

' ========================================================================================
' BOOL WINAPI wglSetStereoEmitterState3DL (HDC hDC, UINT uState);
' ========================================================================================
DECLARE FUNCTION wglSetStereoEmitterState3DL (BYVAL hDC AS DWORD, BYVAL uState AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_EXT_pixel_format_packed_float)
'%WGL_EXT_pixel_format_packed_float = 1
'#ENDIF

'#IF NOT %DEF(%WGL_EXT_framebuffer_sRGB)
'%WGL_EXT_framebuffer_sRGB = 1
'#ENDIF

'#IF NOT %DEF(%WGL_NV_present_video)
'%WGL_NV_present_video = 1

' ========================================================================================
' int wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV *phDeviceList);
' ========================================================================================
DECLARE FUNCTION wglEnumerateVideoDevicesNV (BYVAL hdc AS DWORD, BYREF phDeviceList AS DWORD) AS LONG

' ========================================================================================
' BOOL wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice,
' const int *piAttribList);
' ========================================================================================
DECLARE FUNCTION wglBindVideoDeviceNV (BYVAL hdc AS DWORD, BYVAL uVideoSlot AS DWORD, BYVAL hVideoDevice AS DWORD, BYREF piAttribList AS LONG) AS LONG

' ========================================================================================
' BOOL wglQueryCurrentContextNV(int iAttribute, int *piValue);
' ========================================================================================
DECLARE FUNCTION wglQueryCurrentContextNV (BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_NV_video_output)
'%WGL_NV_video_output = 1

' ========================================================================================
' BOOL wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
' ========================================================================================
DECLARE FUNCTION wglGetVideoDeviceNV (BYVAL hdc AS DWORD, BYVAL numDevices AS LONG, BYREF hVideoDevice AS DWORD) AS LONG

' ========================================================================================
' BOOL wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice);
' ========================================================================================
DECLARE FUNCTION wglReleaseVideoDeviceNV (BYVAL hVideoDevice AS DWORD) AS LONG

' ========================================================================================
' BOOL wglBindVideoImageNV (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
' ========================================================================================
DECLARE FUNCTION wglBindVideoImageNV (BYVAL hVideoDevice AS DWORD, BYVAL hPbuffer AS DWORD, BYVAL iVideoBuffer AS LONG) AS LONG

' ========================================================================================
' BOOL wglReleaseVideoImageNV (HPBUFFERARB hPbuffer, int iVideoBuffer);
' ========================================================================================
DECLARE FUNCTION wglReleaseVideoImageNV (BYVAL hPbuffer AS DWORD, BYVAL iVideoBuffer AS LONG) AS LONG

' ========================================================================================
' BOOL wglSendPbufferToVideoNV (HPBUFFERARB hPbuffer, int iBufferType,
' unsigned long *pulCounterPbuffer, BOOL bBlock);
' ========================================================================================
DECLARE FUNCTION wglSendPbufferToVideoNV (BYVAL hPbuffer AS DWORD, BYVAL iBufferType AS LONG, BYREF pulCounterPbuffer AS DWORD, BYVAL bBlock AS LONG) AS LONG

' ========================================================================================
' BOOL wglGetVideoInfoNV (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer,
' unsigned long *pulCounterOutputVideo);
' ========================================================================================
DECLARE FUNCTION wglGetVideoInfoNV (BYVAL hpVideoDevice AS DWORD, BYREF pulCounterOutputPbuffer AS DWORD, BYREF pulCounterOutputVideo AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_NV_swap_group)
'%WGL_NV_swap_group = 1

' ========================================================================================
' BOOL wglJoinSwapGroupNV(HDC hDC, GLuint group);
' ========================================================================================
DECLARE FUNCTION wglJoinSwapGroupNV (BYVAL hdc AS DWORD, BYVAL dwgroup AS DWORD) AS LONG

' ========================================================================================
' BOOL wglBindSwapBarrierNV(GLuint group, GLuint barrier);
' ========================================================================================
DECLARE FUNCTION wglBindSwapBarrierNV(BYVAL dwgroup AS DWORD, BYVAL dwbarrier AS DWORD) AS LONG

' ========================================================================================
' BOOL wglQuerySwapGroupNV(HDC hDC, GLuint *group, GLuint *barrier);
' ========================================================================================
DECLARE FUNCTION wglQuerySwapGroupNV(BYVAL hdc AS DWORD, BYREF dwgroup AS DWORD, BYREF dwbarrier AS DWORD) AS LONG

' ========================================================================================
' BOOL wglQueryMaxSwapGroupsNV(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
' ========================================================================================
DECLARE FUNCTION wglQueryMaxSwapGroupsNV(BYVAL hdc AS DWORD, BYREF maxGroups AS DWORD, BYREF maxBarriers AS DWORD) AS LONG

' ========================================================================================
' BOOL wglQueryFrameCountNV(HDC hDC, GLuint *count);
' ========================================================================================
DECLARE FUNCTION wglQueryFrameCountNV(BYVAL hdc AS DWORD, BYREF dwcount AS DWORD) AS LONG

' ========================================================================================
' BOOL wglResetFrameCountNV(HDC hDC);
' ========================================================================================
DECLARE FUNCTION wglResetFrameCountNV(BYVAL hdc AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_NV_gpu_affinity)
'%WGL_NV_gpu_affinity = 1

' ========================================================================================
' BOOL WINAPI wglEnumGpusNV (UINT iIndex, HGPUNV *hGpu);
' ========================================================================================
DECLARE FUNCTION wglEnumGpusNV(BYVAL iIndex AS DWORD, BYREF hGpu AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglEnumGpuDevicesNV (HGPUNV hGpu, UINT iIndex, PGPU_DEVICE pGpuDevice);
' ========================================================================================
DECLARE FUNCTION wglEnumGpuDevicesNV(BYVAL hGpu AS DWORD, BYVAL iIndex AS DWORD, BYREF pGpuDevice AS GPU_DEVICE) AS LONG

' ========================================================================================
' HDC WINAPI wglCreateAffinityDCNV (const HGPUNV *pGpuList);
' ========================================================================================
DECLARE FUNCTION wglCreateAffinityDCNV(BYREF pGpuList AS DWORD) AS DWORD

' ========================================================================================
' BOOL WINAPI wglEnumGpusFromAffinityDCNV (HDC hAffinityDC, UINT iIndex, HGPUNV *hGpu);
' ========================================================================================
DECLARE FUNCTION wglEnumGpusFromAffinityDCNV(BYVAL hAffinityDC AS DWORD, BYVAL iIndex AS DWORD, BYREF hGpu AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglDeleteDCNV (HDC hAffinityDC);
' ========================================================================================
DECLARE FUNCTION wglDeleteDCNV(BYVAL hAffinityDC AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_AMD_gpu_association)
'%WGL_AMD_gpu_association = 1

' ========================================================================================
' UINT WINAPI wglGetGPUIDsAMD (UINT maxCount, UINT *ids);
' ========================================================================================
DECLARE FUNCTION wglGetGPUIDsAMD(BYVAL maxCount AS DWORD, BYREF ids AS DWORD) AS DWORD

' ========================================================================================
' INT WINAPI wglGetGPUInfoAMD (UINT id, int property, GLenum dataType, UINT size, void *data);
' ========================================================================================
DECLARE FUNCTION wglGetGPUInfoAMD(BYVAL dwid AS DWORD, BYVAL lproperty AS LONG, BYVAL dataType AS DWORD, BYVAL dwsize AS DWORD, BYVAL pdata AS DWORD) AS LONG

' ========================================================================================
' UINT WINAPI wglGetContextGPUIDAMD (HGLRC hglrc);
' ========================================================================================
DECLARE FUNCTION wglGetContextGPUIDAMD(BYVAL hglrc AS DWORD) AS DWORD

' ========================================================================================
' HGLRC WINAPI wglCreateAssociatedContextAMD (UINT id);
' ========================================================================================
DECLARE FUNCTION wglCreateAssociatedContextAMD(BYVAL dwid AS DWORD) AS DWORD

' ========================================================================================
' HGLRC WINAPI wglCreateAssociatedContextAttribsAMD (UINT id, HGLRC hShareContext, const int *attribList);
' ========================================================================================
DECLARE FUNCTION wglCreateAssociatedContextAttribsAMD(BYVAL dwid AS DWORD, BYVAL hShareContext AS DWORD, BYREF attribList AS LONG) AS DWORD

' ========================================================================================
' BOOL WINAPI wglDeleteAssociatedContextAMD (HGLRC hglrc);
' ========================================================================================
DECLARE FUNCTION wglDeleteAssociatedContextAMD(BYVAL hglrc AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglMakeAssociatedContextCurrentAMD (HGLRC hglrc);
' ========================================================================================
DECLARE FUNCTION wglMakeAssociatedContextCurrentAMD(BYVAL hglrc AS DWORD) AS LONG

' ========================================================================================
' HGLRC WINAPI wglGetCurrentAssociatedContextAMD (void);
' ========================================================================================
DECLARE FUNCTION wglGetCurrentAssociatedContextAMD() AS DWORD

' ========================================================================================
' VOID WINAPI wglBlitContextFramebufferAMD (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1,
' GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
' ========================================================================================
DECLARE SUB wglBlitContextFramebufferAMD (BYVAL dstCtx AS DWORD, BYVAL srcX0 AS LONG, BYVAL srcY0 AS LONG, BYVAL srcX1 AS LONG, BYVAL srcY1 AS LONG, _
   BYVAL dstX0 AS LONG, BYVAL dstY0 AS LONG, BYVAL dstX1 AS LONG, BYVAL dstY1 AS LONG, BYVAL mask AS DWORD, BYVAL filter AS DWORD)

'#ENDIF

'#IF NOT %DEF(%WGL_NV_video_capture)
'%WGL_NV_video_capture = 1

' ========================================================================================
' BOOL WINAPI wglBindVideoCaptureDeviceNV (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
' ========================================================================================
DECLARE FUNCTION wglBindVideoCaptureDeviceNV(BYVAL uVideoSlot AS DWORD, BYVAL hDevice AS DWORD) AS LONG

' ========================================================================================
' UINT WINAPI wglEnumerateVideoCaptureDevicesNV (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
' ========================================================================================
DECLARE FUNCTION wglEnumerateVideoCaptureDevicesNV(BYVAL hDc AS DWORD, BYREF phDeviceList AS DWORD) AS DWORD

' ========================================================================================
' BOOL WINAPI wglLockVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
' ========================================================================================
DECLARE FUNCTION wglLockVideoCaptureDeviceNV(BYVAL hDc AS DWORD, BYVAL hDevice AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglQueryVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
' ========================================================================================
DECLARE FUNCTION wglQueryVideoCaptureDeviceNV(BYVAL hDc AS DWORD, BYVAL hDevice AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG

' ========================================================================================
' BOOL WINAPI wglReleaseVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
' ========================================================================================
DECLARE FUNCTION wglReleaseVideoCaptureDeviceNV(BYVAL hDc AS DWORD, BYVAL hDevice AS DWORD) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_NV_copy_image)
'%WGL_NV_copy_image = 1

' ========================================================================================
' BOOL WINAPI wglCopyImageSubDataNV (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel,
' GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel,
' GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
' ========================================================================================
DECLARE FUNCTION wglCopyImageSubDataNV(BYVAL hSrcRC AS DWORD, BYVAL srcName AS DWORD, _
   BYVAL srcTarget AS DWORD, BYVAL srcLevel AS LONG, BYVAL srcX AS LONG, BYVAL srcY AS LONG, _
   BYVAL srcZ AS LONG, BYVAL hDstRC AS DWORD, BYVAL dstName AS DWORD, BYVAL dstTarget AS DWORD, _
   BYVAL dstLevel AS LONG, BYVAL dstX AS LONG, BYVAL dstY AS LONG, BYVAL dstZ AS LONG, _
   BYVAL nwidth AS LONG, BYVAL height AS LONG, BYVAL depth AS LONG) AS LONG

'#ENDIF

'#IF NOT %DEF(%WGL_NV_multisample_coverage)
'%WGL_NV_multisample_coverage = 1
'#ENDIF

#IF NOT %DEF(%WGL_NV_DX_interop)
%WGL_NV_DX_interop = 1

' ========================================================================================
' BOOL WINAPI wglDXSetResourceShareHandleNV (void *dxObject, HANDLE shareHandle);
' ========================================================================================
DECLARE FUNCTION wglDXSetResourceShareHandleNV(BYVAL dxObject AS DWORD, BYVAL shareHandle AS DWORD) AS LONG

' ========================================================================================
' HANDLE WINAPI wglDXOpenDeviceNV (void *dxDevice);
' ========================================================================================
DECLARE FUNCTION wglDXOpenDeviceNV(BYVAL dxDevice AS DWORD) AS DWORD

' ========================================================================================
' BOOL WINAPI wglDXCloseDeviceNV (HANDLE hDevice);
' ========================================================================================
DECLARE FUNCTION wglDXCloseDeviceNV(BYVAL hDevice AS DWORD) AS LONG

' ========================================================================================
' HANDLE WINAPI wglDXRegisterObjectNV (HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
' ========================================================================================
DECLARE FUNCTION wglDXRegisterObjectNV(BYVAL hDevice AS DWORD, BYVAL dxObject AS DWORD, _
   BYVAL dwName AS DWORD, BYVAL dwType AS DWORD, BYVAL dwAccess AS DWORD) AS DWORD

' ========================================================================================
' BOOL WINAPI wglDXUnregisterObjectNV (HANDLE hDevice, HANDLE hObject);
' ========================================================================================
DECLARE FUNCTION wglDXUnregisterObjectNV(BYVAL hDevice AS DWORD, BYVAL hObject AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglDXObjectAccessNV (HANDLE hObject, GLenum access);
' ========================================================================================
DECLARE FUNCTION wglDXObjectAccessNV(BYVAL hObject AS DWORD, BYVAL dwAccess AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglDXLockObjectsNV (HANDLE hDevice, GLint count, HANDLE *hObjects);
' ========================================================================================
DECLARE FUNCTION wglDXLockObjectsNV(BYVAL hDevice AS DWORD, BYVAL nCount AS LONG, BYREF hObjects AS DWORD) AS LONG

' ========================================================================================
' BOOL WINAPI wglDXUnlockObjectsNV (HANDLE hDevice, GLint count, HANDLE *hObjects);
' ========================================================================================
DECLARE FUNCTION wglDXUnlockObjectsNV(BYVAL hDevice AS DWORD, BYVAL nCount AS LONG, BYREF hObjects AS DWORD) AS LONG

#ENDIF

'#IF NOT %DEF(%WGL_NV_DX_interop2)
'%WGL_NV_DX_interop2 = 1
'#ENDIF

'#IF NOT %DEF(%WGL_EXT_swap_control_tear)
'%WGL_EXT_swap_control_tear = 1
'#ENDIF
