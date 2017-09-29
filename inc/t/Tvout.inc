' ########################################################################################
' Microsoft Windows
' File: Tvout.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TVOUT_INC = 1

#IF NOT %DEF(%GUID_DEFINED)
#INCLUDE ONCE "guiddef.inc"
#ENDIF

UNION VIDEOPARAMETERS_GUID_UNION
   Guid                  AS GUID           ' GUID // GUID for this structure
   ' // For compatibility with the PB declares
   nGuid                 AS GUID           ' GUID // GUID for this structure
END UNION

UNION VIDEOPARAMETERS_bOEMCopyProtection_UNION
   bOEMCopyProtection    AS STRING * 256   ' UCHAR[256] // oem specific copy protection data SET or GET
   ' // For compatibility with the PB declares
   bOEMCopyProtection(255) AS BYTE   ' oem-specific copy protection data SET or GET
END UNION

' // size = 356 bytes
TYPE VIDEOPARAMETERS DWORD
   VIDEOPARAMETERS_GUID_UNION
   dwOffset              AS DWORD          ' ULONG // leave it 0 for now.
   dwCommand             AS DWORD          ' ULONG // VP_COMMAND_*            SET or GET
   dwFlags               AS DWORD          ' ULONG // bitfield, defined below SET or GET
   dwMode                AS DWORD          ' ULONG // bitfield, defined below SET or GET
   dwTVStandard          AS DWORD          ' ULONG // bitfield, defined below SET or GET
   dwAvailableModes      AS DWORD          ' ULONG // bitfield, defined below GET
   dwAvailableTVStandard AS DWORD          ' ULONG // bitfield, defined below GET
   dwFlickerFilter       AS DWORD          ' ULONG // value                   SET or GET
   dwOverScanX           AS DWORD          ' ULONG // value                   SET or GET
   dwOverScanY           AS DWORD          ' ULONG //                         SET or GET
   dwMaxUnscaledX        AS DWORD          ' ULONG // value                   SET or GET
   dwMaxUnscaledY        AS DWORD          ' ULONG //                         SET or GET
   dwPositionX           AS DWORD          ' ULONG // value                   SET or GET
   dwPositionY           AS DWORD          ' ULONG //                         SET or GET
   dwBrightness          AS DWORD          ' ULONG // value                   SET or GET
   dwContrast            AS DWORD          ' ULONG // value                   SET or GET
   dwCPType              AS DWORD          ' ULONG // copy protection type    SET or GET
   dwCPCommand           AS DWORD          ' ULONG // VP_CP_CMD_
   dwCPStandard          AS DWORD          ' ULONG // what TV standards CP is available on. GET
   dwCPKey               AS DWORD          ' ULONG //
   bCP_APSTriggerBits    AS DWORD          ' ULONG // (a dword for alignment) SET(bits 0 and 1 valid).
   VIDEOPARAMETERS_bOEMCopyProtection_UNION
END TYPE

%VP_COMMAND_GET          = &H0001???   ' // size set, return caps.
                                       ' // returned Flags = 0 if not supported.
%VP_COMMAND_SET          = &H0002???   ' // size and params set.

%VP_FLAGS_TV_MODE        = &H0001???
%VP_FLAGS_TV_STANDARD    = &H0002???
%VP_FLAGS_FLICKER        = &H0004???
%VP_FLAGS_OVERSCAN       = &H0008???
%VP_FLAGS_MAX_UNSCALED   = &H0010???   ' // do not use on SET
%VP_FLAGS_POSITION       = &H0020???
%VP_FLAGS_BRIGHTNESS     = &H0040???
%VP_FLAGS_CONTRAST       = &H0080???
%VP_FLAGS_COPYPROTECT    = &H0100???

%VP_MODE_WIN_GRAPHICS    = &H0001???
%VP_MODE_TV_PLAYBACK     = &H0002???   ' // optimize for TV video playback

%VP_TV_STANDARD_NTSC_M   = &H00000001???   ' //        75 IRE Setup
%VP_TV_STANDARD_NTSC_M_J = &H00000002???   ' // Japan,  0 IRE Setup
%VP_TV_STANDARD_PAL_B    = &H00000004???
%VP_TV_STANDARD_PAL_D    = &H00000008???
%VP_TV_STANDARD_PAL_H    = &H00000010???
%VP_TV_STANDARD_PAL_I    = &H00000020???
%VP_TV_STANDARD_PAL_M    = &H00000040???
%VP_TV_STANDARD_PAL_N    = &H00000080???
%VP_TV_STANDARD_SECAM_B  = &H00000100???
%VP_TV_STANDARD_SECAM_D  = &H00000200???
%VP_TV_STANDARD_SECAM_G  = &H00000400???
%VP_TV_STANDARD_SECAM_H  = &H00000800???
%VP_TV_STANDARD_SECAM_K  = &H00001000???
%VP_TV_STANDARD_SECAM_K1 = &H00002000???
%VP_TV_STANDARD_SECAM_L  = &H00004000???
%VP_TV_STANDARD_WIN_VGA  = &H00008000???
' and the rest
%VP_TV_STANDARD_NTSC_433 = &H00010000???
%VP_TV_STANDARD_PAL_G    = &H00020000???
%VP_TV_STANDARD_PAL_60   = &H00040000???
%VP_TV_STANDARD_SECAM_L1 = &H00080000???

%VP_CP_TYPE_APS_TRIGGER  = &H0001???   ' // DVD trigger bits only
%VP_CP_TYPE_MACROVISION  = &H0002???   ' // full macrovision data available

%VP_CP_CMD_ACTIVATE      = &H0001???   ' // CP command type
%VP_CP_CMD_DEACTIVATE    = &H0002???
%VP_CP_CMD_CHANGE        = &H0004???
