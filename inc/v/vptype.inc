' ########################################################################################
' Microsoft Windows
' File: VPType.inc
' Contents: This file includes all the data structures defined for the IVPConfig interface.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VPTYPE_INC = 1

#INCLUDE ONCE "windows.inc"

' // enum to specify the criterion, which the vpmixer is supposed to use
' // in order to select the video format

'enum AMVP_SELECT_FORMAT_BY
%AMVP_DO_NOT_CARE          = 0
%AMVP_BEST_BANDWIDTH       = 1
%AMVP_INPUT_SAME_AS_OUTPUT = 2

' // enum to specify the various mode

' enum AMVP_MODE
%AMVP_MODE_WEAVE             = 0
%AMVP_MODE_BOBINTERLEAVED    = 1
%AMVP_MODE_BOBNONINTERLEAVED = 2
%AMVP_MODE_SKIPEVEN          = 3
%AMVP_MODE_SKIPODD           = 4

' // struct to specify the width and height. The context could be anything
' // such as scaling cropping etc.

' // Size = 8 bytes
TYPE AMVPSIZE DWORD
   dwWidth  AS DWORD           ' // the width
   dwHeight AS DWORD           ' // the height
END TYPE

' // struct to specify the dimensional characteristics of the input stream

' // Size = 32 bytes
TYPE AMVPDIMINFO DWORD
   dwFieldWidth  AS DWORD   ' // Field height of the data
   dwFieldHeight AS DWORD   ' // Field width of the data
   dwVBIWidth    AS DWORD   ' // Width of the VBI data
   dwVBIHeight   AS DWORD   ' // Height of the VBI data
   rcValidRegion AS RECT    ' // The vaild rectangle, used for cropping
END TYPE
MACRO AMVPDIMINFO_type = AMVPDIMINFO   ' // For compatibility with the PB headers

' // struct to specify the various data specific characteristics of the input stream
' // Size = 80 bytes
TYPE AMVPDATAINFO DWORD
   dwSize                 AS DWORD         ' // Size of the struct
   dwMicrosecondsPerField AS DWORD         ' // Time taken by each field
   amvpDimInfo            AS AMVPDIMINFO   ' // Dimensional Information
   dwPictAspectRatioX     AS DWORD         ' // X dimension of Picture Aspect Ratio
   dwPictAspectRatioY     AS DWORD         ' // Y dimension of Picture Aspect Ratio
   bEnableDoubleClock     AS LONG          ' // Videoport should enable double clocking
   bEnableVACT            AS LONG          ' // Videoport should use an external VACT signal
   bDataIsInterlaced      AS LONG          ' // Indicates that the signal is interlaced
   lHalfLinesOdd          AS LONG          ' // number of halflines in the odd field
   bFieldPolarityInverted AS LONG          ' // Device inverts the polarity by default
   dwNumLinesInVREF       AS DWORD         ' // Number of lines of data in VREF
   lHalfLinesEven         AS LONG          ' // number of halflines in the even field
   dwReserved1            AS DWORD         ' // Reserved for future use
END TYPE
