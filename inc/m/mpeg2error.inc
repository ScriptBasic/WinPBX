' ########################################################################################
' Microsoft Windows
' File: MPEG2Error.inc
' Contents: Interface specific HRESULT error codes for MPEG-2 tables.
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPEG2ERROR_INC = 1

#INCLUDE ONCE "winerror.inc"

'#pragma once

'    // Interface specific SUCCESS and ERROR macros
'#define MAKE_S_ITF_HRESULT(x)   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, (x))
'#define MAKE_E_ITF_HRESULT(x)   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (x))

MACRO MAKE_S_ITF_HRESULT(x) = MAKE_HRESULT(%SEVERITY_SUCCESS, %FACILITY_ITF, x)
MACRO MAKE_E_ITF_HRESULT(x) = MAKE_HRESULT(%SEVERITY_ERROR, %FACILITY_ITF, x)

'    // MPEG-2 base HRESULT code (must be at least 0x200)
'const unsigned int MPEG2_BASE = 0x200;
%MPEG2_BASE = &H200???

'    // MPEG-2 Success HRESULTs
%MPEG2_S_MORE_DATA_AVAILABLE            = &H00040200&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x00)
%MPEG2_S_NO_MORE_DATA_AVAILABLE         = &H00040201&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x01)
%MPEG2_S_SG_INFO_FOUND                  = &H00040202&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x02)
%MPEG2_S_SG_INFO_NOT_FOUND              = &H00040203&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x03)
%MPEG2_S_MPE_INFO_FOUND                 = &H00040204&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x04)
%MPEG2_S_MPE_INFO_NOT_FOUND             = &H00040205&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x05)
%MPEG2_S_NEW_MODULE_VERSION             = &H00040206&   ' // MAKE_S_ITF_HRESULT(MPEG2_BASE + 0x06)

'    // MPEG-2 Error HRESULTs
%MPEG2_E_UNINITIALIZED                  = &H80040200&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x00)
%MPEG2_E_ALREADY_INITIALIZED            = &H80040201&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x01)
%MPEG2_E_OUT_OF_BOUNDS                  = &H80040202&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x02)
%MPEG2_E_MALFORMED_TABLE                = &H80040203&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x03)
%MPEG2_E_UNDEFINED                      = &H80040204&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x04)
%MPEG2_E_NOT_PRESENT                    = &H80040205&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x05)
%MPEG2_E_SECTION_NOT_FOUND              = &H80040206&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x06)
%MPEG2_E_TX_STREAM_UNAVAILABLE          = &H80040207&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x07)
%MPEG2_E_SERVICE_ID_NOT_FOUND           = &H80040208&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x08)
%MPEG2_E_SERVICE_PMT_NOT_FOUND          = &H80040209&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x09)
%MPEG2_E_DSI_NOT_FOUND                  = &H8004020A&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x0A)
%MPEG2_E_SERVER_UNAVAILABLE             = &H8004020B&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x0B)
%MPEG2_E_INVALID_CAROUSEL_ID            = &H8004020C&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x0C)
%MPEG2_E_MALFORMED_DSMCC_MESSAGE        = &H8004020D&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x0D)
%MPEG2_E_INVALID_SG_OBJECT_KIND         = &H8004020E&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x0E)
%MPEG2_E_OBJECT_NOT_FOUND               = &H8004020F&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x0F)
%MPEG2_E_OBJECT_KIND_NOT_A_DIRECTORY    = &H80040210&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x10)
%MPEG2_E_OBJECT_KIND_NOT_A_FILE         = &H80040211&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x11)
%MPEG2_E_FILE_OFFSET_TOO_BIG            = &H80040212&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x12)
%MPEG2_E_STREAM_STOPPED                 = &H80040213&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x13)
%MPEG2_E_REGISTRY_ACCESS_FAILED         = &H80040214&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x14)
%MPEG2_E_INVALID_UDP_PORT               = &H80040215&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x15)
%MPEG2_E_DATA_SOURCE_FAILED             = &H80040216&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x16)
%MPEG2_E_DII_NOT_FOUND                  = &H80040217&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x17)
%MPEG2_E_DSHOW_PIN_NOT_FOUND            = &H80040218&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x18)
%MPEG2_E_BUFFER_TOO_SMALL               = &H80040219&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x19)
%MPEG2_E_MISSING_SECTIONS               = &H8004021A&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x1A)
%MPEG2_E_TOO_MANY_SECTIONS              = &H8004021B&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x1B)
%MPEG2_E_NEXT_TABLE_OPS_NOT_AVAILABLE   = &H8004021C&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x1C)
%MPEG2_E_INCORRECT_DESCRIPTOR_TAG       = &H8004021D&   ' // MAKE_E_ITF_HRESULT(MPEG2_BASE + 0x1D)
