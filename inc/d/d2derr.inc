' ########################################################################################
' Microsoft Windows
' File: D2DErr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D2DERR_INC = 1

'/*=========================================================================*\
'    D2D Status Codes
'\*=========================================================================*/

%FACILITY_D2D = &H899

'#define MAKE_D2DHR( sev, code )\
'    MAKE_HRESULT( sev, FACILITY_D2D, (code) )

MACRO MAKE_D2DHR (sev, code) = MAKE_HRESULT(sev, %FACILITY_D2D, code)

'#define MAKE_D2DHR_ERR( code )\
'    MAKE_D2DHR( 1, code )

MACRO MAKE_D2DHR_ERR (code) = MAKE_D2DHR(1, code)

'//+----------------------------------------------------------------------------
'//
'// D2D error codes
'//
'//------------------------------------------------------------------------------

'//
'//  Error codes shared with WINCODECS
'//

'//
'// The pixel format is not supported.
'//
'#define D2DERR_UNSUPPORTED_PIXEL_FORMAT     WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT
%D2DERR_UNSUPPORTED_PIXEL_FORMAT = &H88982F80&

'//
'// Error codes that were already returned in prior versions and were part of the
'// MIL facility.

'//
'// Error codes mapped from WIN32 where there isn't already another HRESULT based
'// define
'//

'//
'// The supplied buffer was too small to accomodate the data.
'//
'#define D2DERR_INSUFFICIENT_BUFFER          HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
%D2DERR_INSUFFICIENT_BUFFER = &H8007007A&


'//
'// D2D specific codes
'//

'//
'// The object was not in the correct state to process the method.
'//
'#define D2DERR_WRONG_STATE                  MAKE_D2DHR_ERR(0x001)
%D2DERR_WRONG_STATE = &H88990001&

'//
'// The object has not yet been initialized.
'//
'#define D2DERR_NOT_INITIALIZED              MAKE_D2DHR_ERR(0x002)
%D2DERR_NOT_INITIALIZED = &H88990002&

'//
'// The requested opertion is not supported.
'//
'#define D2DERR_UNSUPPORTED_OPERATION        MAKE_D2DHR_ERR(0x003)
%D2DERR_UNSUPPORTED_OPERATION = &H88990003&

'//
'// The geomery scanner failed to process the data.
'//
'#define D2DERR_SCANNER_FAILED               MAKE_D2DHR_ERR(0x004)
%D2DERR_SCANNER_FAILED = &H88990004&

'//
'// D2D could not access the screen.
'//
'#define D2DERR_SCREEN_ACCESS_DENIED         MAKE_D2DHR_ERR(0x005)
%D2DERR_SCREEN_ACCESS_DENIED = &H88990005&

'//
'// A valid display state could not be determined.
'//
'#define D2DERR_DISPLAY_STATE_INVALID        MAKE_D2DHR_ERR(0x006)
%D2DERR_DISPLAY_STATE_INVALID = &H88990006&

'//
'// The supplied vector is vero.
'//
'#define D2DERR_ZERO_VECTOR                  MAKE_D2DHR_ERR(0x007)
%D2DERR_ZERO_VECTOR = &H88990007&

'//
'// An internal error (D2D bug) occurred. On checked builds, we would assert.
'//
'// The application should close this instance of D2D and should consider
'// restarting its process.
'//
'#define D2DERR_INTERNAL_ERROR               MAKE_D2DHR_ERR(0x008)
%D2DERR_INTERNAL_ERROR = &H88990008&

'//
'// The display format we need to render is not supported by the
'// hardware device.
'//
'#define D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED MAKE_D2DHR_ERR(0x009)
%D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED = &H88990009&

'//
'// A call to this method is invalid.
'//
'#define D2DERR_INVALID_CALL                 MAKE_D2DHR_ERR(0x00A)
%D2DERR_INVALID_CALL = &H8899000A&

'//
'// No HW rendering device is available for this operation.
'//
'#define D2DERR_NO_HARDWARE_DEVICE           MAKE_D2DHR_ERR(0x00B)
%D2DERR_NO_HARDWARE_DEVICE = &H8899000B&

'//
'// There has been a presentation error that may be recoverable. The caller
'// needs to recreate, rerender the entire frame, and reattempt present.
'//
'#define D2DERR_RECREATE_TARGET              MAKE_D2DHR_ERR(0x00C)
%D2DERR_RECREATE_TARGET = &H8899000C&

'//
'// Shader construction failed because it was too complex.
'//
'#define D2DERR_TOO_MANY_SHADER_ELEMENTS     MAKE_D2DHR_ERR(0x00D)
%D2DERR_TOO_MANY_SHADER_ELEMENTS = &H8899000D&

'//
'// Shader compilation failed.
'//
'#define D2DERR_SHADER_COMPILE_FAILED        MAKE_D2DHR_ERR(0x00E)
%D2DERR_SHADER_COMPILE_FAILED = &H8899000E&

'//
'// Requested DX surface size exceeded maximum texture size.
'//
'#define D2DERR_MAX_TEXTURE_SIZE_EXCEEDED    MAKE_D2DHR_ERR(0x00F)
%D2DERR_MAX_TEXTURE_SIZE_EXCEEDED = &H8899000F&

'//
'// The requested D2D version is not supported.
'//
'#define D2DERR_UNSUPPORTED_VERSION          MAKE_D2DHR_ERR(0x010)
%D2DERR_UNSUPPORTED_VERSION = &H88990010&

'//
'// Invalid number.
'//
'#define D2DERR_BAD_NUMBER                   MAKE_D2DHR_ERR(0x0011)
%D2DERR_BAD_NUMBER = &H88990011&

'//
'// Objects used together must be created from the same factory instance.
'//
'#define D2DERR_WRONG_FACTORY                MAKE_D2DHR_ERR(0x012)
%D2DERR_WRONG_FACTORY = &H88990012&

'//
'// A layer resource can only be in use once at any point in time.
'//
'#define D2DERR_LAYER_ALREADY_IN_USE         MAKE_D2DHR_ERR(0x013)
%D2DERR_LAYER_ALREADY_IN_USE = &H88990013&

'//
'// The pop call did not match the corresponding push call
'//
'#define D2DERR_POP_CALL_DID_NOT_MATCH_PUSH  MAKE_D2DHR_ERR(0x014)
%D2DERR_POP_CALL_DID_NOT_MATCH_PUSH = &H88990014&

'//
'// The resource was realized on the wrong render target
'//
'#define D2DERR_WRONG_RESOURCE_DOMAIN        MAKE_D2DHR_ERR(0x015)
%D2DERR_WRONG_RESOURCE_DOMAIN = &H88990015&

'//
'// The push and pop calls were unbalanced
'//
'#define D2DERR_PUSH_POP_UNBALANCED          MAKE_D2DHR_ERR(0x016)
%D2DERR_PUSH_POP_UNBALANCED = &H88990016&

'//
'// Attempt to copy from a render target while a layer or clip rect is applied
'//
'#define D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT MAKE_D2DHR_ERR(0x017)
%D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT  = &H88990017&

'//
'// The brush types are incompatible for the call.
'//
'#define D2DERR_INCOMPATIBLE_BRUSH_TYPES     MAKE_D2DHR_ERR(0x018)
%D2DERR_INCOMPATIBLE_BRUSH_TYPES = &H88990018&

'//
'// An unknown win32 failure occurred.
'//
'#define D2DERR_WIN32_ERROR                  MAKE_D2DHR_ERR(0x019)
%D2DERR_WIN32_ERROR = &H88990019&

'//
'// The render target is not compatible with GDI
'//
'#define D2DERR_TARGET_NOT_GDI_COMPATIBLE    MAKE_D2DHR_ERR(0x01A)
%D2DERR_TARGET_NOT_GDI_COMPATIBLE = &H8899001A&

'//
'// A text client drawing effect object is of the wrong type
'//
'#define D2DERR_TEXT_EFFECT_IS_WRONG_TYPE    MAKE_D2DHR_ERR(0x01B)
%D2DERR_TEXT_EFFECT_IS_WRONG_TYPE = &H8899001B&

'//
'// The application is holding a reference to the IDWriteTextRenderer interface
'// after the corresponding DrawText or DrawTextLayout call has returned. The
'// IDWriteTextRenderer instance will be zombied.
'//
'#define D2DERR_TEXT_RENDERER_NOT_RELEASED   MAKE_D2DHR_ERR(0x01C)
%D2DERR_TEXT_RENDERER_NOT_RELEASED = &H8899001C&

'//
'// The requested size is larger than the guaranteed supported texture size.
'//
'#define D2DERR_EXCEEDS_MAX_BITMAP_SIZE     MAKE_D2DHR_ERR(0x01D)
%D2DERR_EXCEEDS_MAX_BITMAP_SIZE = &H8899001D&
