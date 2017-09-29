' ########################################################################################
' Microsoft Windows
' File: d3dxerr.inc
' Contents: 0xC code definitions for the D3DX API
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DXERR_INC = 1

'//
'//
'//  Values are 32 bit values layed out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//
'#define FACILITY_D3DX    0x877

%FACILITY_D3DX = &H877


'//
'// MessageId: D3DXERR_NOMEMORY
'//
'// MessageText:
'//
'//  Out of memory.
'//
'#define D3DXERR_NOMEMORY    ((HRESULT)0xC8770BB8L)

%D3DXERR_NOMEMORY = &HC8770BB8&

'//
'// MessageId: D3DXERR_NULLPOINTER
'//
'// MessageText:
'//
'//  A NULL pointer was passed as a parameter.
'//
'#define D3DXERR_NULLPOINTER    ((HRESULT)0xC8770BB9L)

%D3DXERR_NULLPOINTER = &HC8770BB9&

'//
'// MessageId: D3DXERR_INVALIDD3DXDEVICEINDEX
'//
'// MessageText:
'//
'//  The Device Index passed in is invalid.
'//
'#define D3DXERR_INVALIDD3DXDEVICEINDEX    ((HRESULT)0xC8770BBAL)

%D3DXERR_INVALIDD3DXDEVICEINDEX = &HC8770BBA&

'//
'// MessageId: D3DXERR_NODIRECTDRAWAVAILABLE
'//
'// MessageText:
'//
'//  DirectDraw has not been created.
'//
'#define D3DXERR_NODIRECTDRAWAVAILABLE    ((HRESULT)0xC8770BBBL)

%D3DXERR_NODIRECTDRAWAVAILABLE = &HC8770BBB&

'//
'// MessageId: D3DXERR_NODIRECT3DAVAILABLE
'//
'// MessageText:
'//
'//  Direct3D has not been created.
'//
'#define D3DXERR_NODIRECT3DAVAILABLE    ((HRESULT)0xC8770BBCL)

%D3DXERR_NODIRECT3DAVAILABLE = &HC8770BBC&

'//
'// MessageId: D3DXERR_NODIRECT3DDEVICEAVAILABLE
'//
'// MessageText:
'//
'//  Direct3D device has not been created.
'//
'#define D3DXERR_NODIRECT3DDEVICEAVAILABLE    ((HRESULT)0xC8770BBDL)

%D3DXERR_NODIRECT3DDEVICEAVAILABLE = &HC8770BBD&

'//
'// MessageId: D3DXERR_NOPRIMARYAVAILABLE
'//
'// MessageText:
'//
'//  Primary surface has not been created.
'//
'#define D3DXERR_NOPRIMARYAVAILABLE    ((HRESULT)0xC8770BBEL)

%D3DXERR_NOPRIMARYAVAILABLE = &HC8770BBE&

'//
'// MessageId: D3DXERR_NOZBUFFERAVAILABLE
'//
'// MessageText:
'//
'//  Z buffer has not been created.
'//
'#define D3DXERR_NOZBUFFERAVAILABLE    ((HRESULT)0xC8770BBFL)

%D3DXERR_NOZBUFFERAVAILABLE = &HC8770BBF&

'//
'// MessageId: D3DXERR_NOBACKBUFFERAVAILABLE
'//
'// MessageText:
'//
'//  Backbuffer has not been created.
'//
'#define D3DXERR_NOBACKBUFFERAVAILABLE    ((HRESULT)0xC8770BC0L)

%D3DXERR_NOBACKBUFFERAVAILABLE = &HC8770BC0&

'//
'// MessageId: D3DXERR_COULDNTUPDATECAPS
'//
'// MessageText:
'//
'//  Failed to update caps database after changing display mode.
'//
'#define D3DXERR_COULDNTUPDATECAPS    ((HRESULT)0xC8770BC1L)

%D3DXERR_COULDNTUPDATECAPS = &HC8770BC1&

'//
'// MessageId: D3DXERR_NOZBUFFER
'//
'// MessageText:
'//
'//  Could not create Z buffer.
'//
'#define D3DXERR_NOZBUFFER    ((HRESULT)0xC8770BC2L)

%D3DXERR_NOZBUFFER = &HC8770BC2&

'//
'// MessageId: D3DXERR_INVALIDMODE
'//
'// MessageText:
'//
'//  Display mode is not valid.
'//
'#define D3DXERR_INVALIDMODE    ((HRESULT)0xC8770BC3L)

%D3DXERR_INVALIDMODE = &HC8770BC3&

'//
'// MessageId: D3DXERR_INVALIDPARAMETER
'//
'// MessageText:
'//
'//  One or more of the parameters passed is invalid.
'//
'#define D3DXERR_INVALIDPARAMETER    ((HRESULT)0xC8770BC4L)

%D3DXERR_INVALIDPARAMETER = &HC8770BC4&

'//
'// MessageId: D3DXERR_INITFAILED
'//
'// MessageText:
'//
'//  D3DX failed to initialize itself.
'//
'#define D3DXERR_INITFAILED    ((HRESULT)0xC8770BC5L)

%D3DXERR_INITFAILED = &HC8770BC5&

'//
'// MessageId: D3DXERR_STARTUPFAILED
'//
'// MessageText:
'//
'//  D3DX failed to start up.
'//
'#define D3DXERR_STARTUPFAILED    ((HRESULT)0xC8770BC6L)

%D3DXERR_STARTUPFAILED = &HC8770BC6&

'//
'// MessageId: D3DXERR_D3DXNOTSTARTEDYET
'//
'// MessageText:
'//
'//  D3DXInitialize() must be called first.
'//
'#define D3DXERR_D3DXNOTSTARTEDYET    ((HRESULT)0xC8770BC7L)

%D3DXERR_D3DXNOTSTARTEDYET = &HC8770BC7&

'//
'// MessageId: D3DXERR_NOTINITIALIZED
'//
'// MessageText:
'//
'//  D3DX is not initialized yet.
'//
'#define D3DXERR_NOTINITIALIZED    ((HRESULT)0xC8770BC8L)

%D3DXERR_NOTINITIALIZED = &HC8770BC8&

'//
'// MessageId: D3DXERR_FAILEDDRAWTEXT
'//
'// MessageText:
'//
'//  Failed to render text to the surface.
'//
'#define D3DXERR_FAILEDDRAWTEXT    ((HRESULT)0xC8770BC9L)

%D3DXERR_FAILEDDRAWTEXT = &HC8770BC9&

'//
'// MessageId: D3DXERR_BADD3DXCONTEXT
'//
'// MessageText:
'//
'//  Bad D3DX context.
'//
'#define D3DXERR_BADD3DXCONTEXT    ((HRESULT)0xC8770BCAL)

%D3DXERR_BADD3DXCONTEXT = &HC8770BCA&

'//
'// MessageId: D3DXERR_CAPSNOTSUPPORTED
'//
'// MessageText:
'//
'//  The requested device capabilities are not supported.
'//
'#define D3DXERR_CAPSNOTSUPPORTED    ((HRESULT)0xC8770BCBL)

%D3DXERR_CAPSNOTSUPPORTED = &HC8770BCB&

'//
'// MessageId: D3DXERR_UNSUPPORTEDFILEFORMAT
'//
'// MessageText:
'//
'//  The image file format is unrecognized.
'//
'#define D3DXERR_UNSUPPORTEDFILEFORMAT    ((HRESULT)0xC8770BCCL)

%D3DXERR_UNSUPPORTEDFILEFORMAT = &HC8770BCC&

'//
'// MessageId: D3DXERR_IFLERROR
'//
'// MessageText:
'//
'//  The image file loading library error.
'//
'#define D3DXERR_IFLERROR    ((HRESULT)0xC8770BCDL)

%D3DXERR_IFLERROR = &HC8770BCD&

'//
'// MessageId: D3DXERR_FAILEDGETCAPS
'//
'// MessageText:
'//
'//  Could not obtain device caps.
'//
'#define D3DXERR_FAILEDGETCAPS    ((HRESULT)0xC8770BCEL)

%D3DXERR_FAILEDGETCAPS = &HC8770BCE&

'//
'// MessageId: D3DXERR_CANNOTRESIZEFULLSCREEN
'//
'// MessageText:
'//
'//  Resize does not work for full-screen.
'//
'#define D3DXERR_CANNOTRESIZEFULLSCREEN    ((HRESULT)0xC8770BCFL)

%D3DXERR_CANNOTRESIZEFULLSCREEN = &HC8770BCF&

'//
'// MessageId: D3DXERR_CANNOTRESIZENONWINDOWED
'//
'// MessageText:
'//
'//  Resize does not work for non-windowed contexts.
'//
'#define D3DXERR_CANNOTRESIZENONWINDOWED    ((HRESULT)0xC8770BD0L)

%D3DXERR_CANNOTRESIZENONWINDOWED = &HC8770BD0&

'//
'// MessageId: D3DXERR_FRONTBUFFERALREADYEXISTS
'//
'// MessageText:
'//
'//  Front buffer already exists.
'//
'#define D3DXERR_FRONTBUFFERALREADYEXISTS    ((HRESULT)0xC8770BD1L)

%D3DXERR_FRONTBUFFERALREADYEXISTS = &HC8770BD1&

'//
'// MessageId: D3DXERR_FULLSCREENPRIMARYEXISTS
'//
'// MessageText:
'//
'//  The app is using the primary in full-screen mode.
'//
'#define D3DXERR_FULLSCREENPRIMARYEXISTS    ((HRESULT)0xC8770BD2L)

%D3DXERR_FULLSCREENPRIMARYEXISTS = &HC8770BD2&

'//
'// MessageId: D3DXERR_GETDCFAILED
'//
'// MessageText:
'//
'//  Could not get device context.
'//
'#define D3DXERR_GETDCFAILED    ((HRESULT)0xC8770BD3L)

%D3DXERR_GETDCFAILED = &HC8770BD3&

'//
'// MessageId: D3DXERR_BITBLTFAILED
'//
'// MessageText:
'//
'//  Could not bitBlt.
'//
'#define D3DXERR_BITBLTFAILED    ((HRESULT)0xC8770BD4L)

%D3DXERR_BITBLTFAILED = &HC8770BD4&

'//
'// MessageId: D3DXERR_NOTEXTURE
'//
'// MessageText:
'//
'//  There is no surface backing up this texture.
'//
'#define D3DXERR_NOTEXTURE    ((HRESULT)0xC8770BD5L)

%D3DXERR_NOTEXTURE = &HC8770BD5&

'//
'// MessageId: D3DXERR_MIPLEVELABSENT
'//
'// MessageText:
'//
'//  There is no such miplevel for this surface.
'//
'#define D3DXERR_MIPLEVELABSENT    ((HRESULT)0xC8770BD6L)

%D3DXERR_MIPLEVELABSENT = &HC8770BD6&

'//
'// MessageId: D3DXERR_SURFACENOTPALETTED
'//
'// MessageText:
'//
'//  The surface is not paletted.
'//
'#define D3DXERR_SURFACENOTPALETTED    ((HRESULT)0xC8770BD7L)

%D3DXERR_SURFACENOTPALETTED = &HC8770BD7&

'//
'// MessageId: D3DXERR_ENUMFORMATSFAILED
'//
'// MessageText:
'//
'//  An error occured while enumerating surface formats.
'//
'#define D3DXERR_ENUMFORMATSFAILED    ((HRESULT)0xC8770BD8L)

%D3DXERR_ENUMFORMATSFAILED = &HC8770BD8&

'//
'// MessageId: D3DXERR_COLORDEPTHTOOLOW
'//
'// MessageText:
'//
'//  D3DX only supports color depths of 16 bit or greater.
'//
'#define D3DXERR_COLORDEPTHTOOLOW    ((HRESULT)0xC8770BD9L)

%D3DXERR_COLORDEPTHTOOLOW = &HC8770BD9&

'//
'// MessageId: D3DXERR_INVALIDFILEFORMAT
'//
'// MessageText:
'//
'//  The file format is invalid.
'//
'#define D3DXERR_INVALIDFILEFORMAT    ((HRESULT)0xC8770BDAL)

%D3DXERR_INVALIDFILEFORMAT = &HC8770BDA&

'//
'// MessageId: D3DXERR_NOMATCHFOUND
'//
'// MessageText:
'//
'//  No suitable match found.
'//
'#define D3DXERR_NOMATCHFOUND    ((HRESULT)0xC8770BDBL)

%D3DXERR_NOMATCHFOUND = &HC8770BDB&
