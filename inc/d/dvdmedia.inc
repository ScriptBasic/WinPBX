' ########################################################################################
' Microsoft Windows
' File: DVDMedia.inc
' Contents: Typedefs and defines necessary for user mode (ring 3) DVD filters and applications.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DVDMEDIA_INC = 1

#INCLUDE ONCE "windows.inc"

'// -----------------------------------------------------------------------
'// AC-3 definition for the AM_KSPROPSETID_AC3 property set
'// -----------------------------------------------------------------------

' AM_PROPERTY_AC3 enum
%AM_PROPERTY_AC3_ERROR_CONCEALMENT = 1
%AM_PROPERTY_AC3_ALTERNATE_AUDIO   = 2
%AM_PROPERTY_AC3_DOWNMIX           = 3
%AM_PROPERTY_AC3_BIT_STREAM_MODE   = 4
%AM_PROPERTY_AC3_DIALOGUE_LEVEL    = 5
%AM_PROPERTY_AC3_LANGUAGE_CODE     = 6
%AM_PROPERTY_AC3_ROOM_TYPE         = 7

' // Size = 8 bytes
TYPE AM_AC3_ERROR_CONCEALMENT DWORD
   fRepeatPreviousBlock AS LONG   ' BOOL
   fErrorInCurrentBlock AS LONG   ' BOOL
END TYPE

' // Size = 8 bytes
TYPE AM_AC3_ALTERNATE_AUDIO DWORD
   fStereo  AS LONG    ' BOOL
   DualMode AS DWORD   ' ULONG
END TYPE

%AM_AC3_ALTERNATE_AUDIO_1    = 1
%AM_AC3_ALTERNATE_AUDIO_2    = 2
%AM_AC3_ALTERNATE_AUDIO_BOTH = 3

' // Size = 8 bytes
TYPE AM_AC3_DOWNMIX DWORD
   fDownMix       AS LONG   ' BOOL
   fDolbySurround AS LONG   ' BOOL
END TYPE

' // Size = 4 bytes
TYPE AM_AC3_BIT_STREAM_MODE DWORD
   BitStreamMode AS LONG
END TYPE

%AM_AC3_SERVICE_MAIN_AUDIO        = 0
%AM_AC3_SERVICE_NO_DIALOG         = 1
%AM_AC3_SERVICE_VISUALLY_IMPAIRED = 2
%AM_AC3_SERVICE_HEARING_IMPAIRED  = 3
%AM_AC3_SERVICE_DIALOG_ONLY       = 4
%AM_AC3_SERVICE_COMMENTARY        = 5
%AM_AC3_SERVICE_EMERGENCY_FLASH   = 6
%AM_AC3_SERVICE_VOICE_OVER        = 7

' // Size = 4 bytes
TYPE AM_AC3_DIALOGUE_LEVEL DWORD
   DialogueLevel AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
TYPE AM_AC3_ROOM_TYPE DWORD
   fLargeRoom AS LONG   ' BOOL
END TYPE


'// -----------------------------------------------------------------------
'// subpicture definition for the AM_KSPROPSETID_DvdSubPic property set
'// -----------------------------------------------------------------------

' AM_PROPERTY_DVDSUBPIC enum
%AM_PROPERTY_DVDSUBPIC_PALETTE     = 0
%AM_PROPERTY_DVDSUBPIC_HLI         = 1
%AM_PROPERTY_DVDSUBPIC_COMPOSIT_ON = 2   ' // TRUE for subpicture is displayed

' // Size = 4 bytes
TYPE AM_DVD_YUV BYTE
   Reserved AS BYTE   ' UCHAR
   Y        AS BYTE   ' UCHAR
   U        AS BYTE   ' UCHAR
   V        AS BYTE   ' UCHAR
END TYPE

' // Size = 64 bytes
TYPE AM_PROPERTY_SPPAL BYTE
   sppal(15) AS AM_DVD_YUV   ' UCHAR[16]
END TYPE

' // Size = 4 bytes
TYPE AM_COLCON DWORD
   emph1col AS BIT * 4 IN DWORD
   emph2col AS BIT * 4
   backcol  AS BIT * 4
   patcol   AS BIT * 4
   emph1con AS BIT * 4
   emph2con AS BIT * 4
   backcon  AS BIT * 4
   patcon   AS BIT * 4
END TYPE

' // Size = 24 bytes
TYPE AM_PROPERTY_SPHLI DWORD FILL
   HLISS    AS WORD
   Reserved AS WORD
   StartPTM AS DWORD       ' // start presentation time in x/90000
   EndPTM   AS DWORD       ' // end PTM in x/90000
   StartX   AS WORD
   StartY   AS WORD
   StopX    AS WORD
   StopY    AS WORD
   ColCon   AS AM_COLCON   ' // color contrast description (4 bytes as given in HLI)
END TYPE

'// -----------------------------------------------------------------------
'// copy protection definitions
'// -----------------------------------------------------------------------

'// AM_UseNewCSSKey for the dwTypeSpecificFlags in IMediaSample2 to indicate
'// the exact point in a stream after which to start applying a new CSS key.
'// This is typically sent on an empty media sample just before attempting
'// to renegotiate a CSS key.

%AM_UseNewCSSKey      = &H1

%AM_ReverseBlockStart = &H2
%AM_ReverseBlockEnd   = &H4

'//
'// AM_KSPROPSETID_CopyProt property set definitions
'//
' AM_PROPERTY_DVDCOPYPROT enum
%PROPERTY_DVDCOPY_CHLG_KEY                 = &H01
%PROPERTY_DVDCOPY_DVD_KEY1                 = &H02
%PROPERTY_DVDCOPY_DEC_KEY2                 = &H03
%PROPERTY_DVDCOPY_TITLE_KEY                = &H04
%PROPERTY_COPY_MACROVISION                 = &H05
%PROPERTY_DVDCOPY_REGION                   = &H06
%PROPERTY_DVDCOPY_SET_COPY_STATE           = &H07
%AM_PROPERTY_COPY_ANALOG_COMPONENT         = &H08   ' // GetOnly property, return data is a BOOL
%AM_PROPERTY_COPY_DIGITAL_CP               = &H09
%AM_PROPERTY_COPY_DVD_SRM                  = &H0a
%AM_PROPERTY_DVDCOPY_SUPPORTS_NEW_KEYCOUNT = &H0b   ' // read only, BOOL
'// gap
%PROPERTY_DVDCOPY_DISC_KEY                 = &H80

' enum _AM_DIGITAL_CP
%AM_DIGITAL_CP_OFF           = 0
%AM_DIGITAL_CP_ON            = 1
%AM_DIGITAL_CP_DVD_COMPLIANT = 2

' // Size = 12 bytes
TYPE AM_DVDCOPY_CHLGKEY BYTE
   ChlgKey(9)  AS BYTE   ' BYTE[10]
   Reserved(1) AS BYTE   ' BYTE[2]
END TYPE

' // Size = 6 bytes
TYPE AM_DVDCOPY_BUSKEY BYTE
   BusKey(4)   AS BYTE   ' BYTE[5]
   Reserved(0) AS BYTE   ' BYTE[1]
END TYPE

' // Size = 2048 bytes
TYPE AM_DVDCOPY_DISCKEY BYTE
   DiscKey(2047) AS BYTE   ' BYTE[2048]
END TYPE

' // Size = 20 bytes
TYPE AM_DVDCOPY_TITLEKEY BYTE
   KeyFlags     AS DWORD   ' ULONG
   Reserved1(1) AS DWORD   ' ULONG[2]
   TitleKey(5)  AS BYTE    ' UCHAR[6]
   Reserved2(1) AS BYTE    ' UCHAR[2]
END TYPE

' // Size = 4 bytes
TYPE AM_COPY_MACROVISION DWORD
   MACROVISIONLevel AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
TYPE AM_DVDCOPY_SET_COPY_STATE DWORD
   DVDCopyState AS DWORD   ' ULONG
END TYPE

' AM_DVDCOPYSTATE enum
%AM_DVDCOPYSTATE_INITIALIZE                  = 0
%AM_DVDCOPYSTATE_INITIALIZE_TITLE            = 1   ' // indicates we are starting a title
                                        ' // key copy protection sequence
%AM_DVDCOPYSTATE_AUTHENTICATION_NOT_REQUIRED = 2
%AM_DVDCOPYSTATE_AUTHENTICATION_REQUIRED     = 3
%AM_DVDCOPYSTATE_DONE                        = 4

' AM_COPY_MACROVISION_LEVEL enum
%AM_MACROVISION_DISABLED = 0
%AM_MACROVISION_LEVEL1   = 1
%AM_MACROVISION_LEVEL2   = 2
%AM_MACROVISION_LEVEL3   = 3


'// CSS region stucture
' // Size = 4 bytes
TYPE DVD_REGION BYTE
   CopySystem   AS BYTE   ' UCHAR
   RegionData   AS BYTE   ' UCHAR
   SystemRegion AS BYTE   ' UCHAR
   ResetCount   AS BYTE   ' UCHAR
END TYPE

'//
'// CGMS Copy Protection Flags
'//

%AM_DVD_CGMS_RESERVED_MASK      = &H00000078???

%AM_DVD_CGMS_COPY_PROTECT_MASK  = &H00000018???
%AM_DVD_CGMS_COPY_PERMITTED     = &H00000000???
%AM_DVD_CGMS_COPY_ONCE          = &H00000010???
%AM_DVD_CGMS_NO_COPY            = &H00000018???

%AM_DVD_COPYRIGHT_MASK          = &H00000040???
%AM_DVD_NOT_COPYRIGHTED         = &H00000000???
%AM_DVD_COPYRIGHTED             = &H00000040???

%AM_DVD_SECTOR_PROTECT_MASK     = &H00000020???
%AM_DVD_SECTOR_NOT_PROTECTED    = &H00000000???
%AM_DVD_SECTOR_PROTECTED        = &H00000020???


'// -----------------------------------------------------------------------
'// video format blocks
'// -----------------------------------------------------------------------

' enum AM_MPEG2Level
%AM_MPEG2Level_Low      = 1
%AM_MPEG2Level_Main     = 2
%AM_MPEG2Level_High1440 = 3
%AM_MPEG2Level_High     = 4

' enum AM_MPEG2Profile
%AM_MPEG2Profile_Simple            = 1
%AM_MPEG2Profile_Main              = 2
%AM_MPEG2Profile_SNRScalable       = 3
%AM_MPEG2Profile_SpatiallyScalable = 4
%AM_MPEG2Profile_High              = 5

%AMINTERLACE_IsInterlaced            = &H00000001???  ' // if 0, other interlace bits are irrelevent
%AMINTERLACE_1FieldPerSample         = &H00000002???  ' // else 2 fields per media sample
%AMINTERLACE_Field1First             = &H00000004???  ' // else Field 2 is first;  top field in PAL is field 1, top field in NTSC is field 2?
%AMINTERLACE_UNUSED                  = &H00000008???  ' //
%AMINTERLACE_FieldPatternMask        = &H00000030???  ' // use this mask with AMINTERLACE_FieldPat*
%AMINTERLACE_FieldPatField1Only      = &H00000000???  ' // stream never contains a Field2
%AMINTERLACE_FieldPatField2Only      = &H00000010???  ' // stream never contains a Field1
%AMINTERLACE_FieldPatBothRegular     = &H00000020???  ' // There will be a Field2 for every Field1 (required for Weave?)
%AMINTERLACE_FieldPatBothIrregular   = &H00000030???  ' // Random pattern of Field1s and Field2s
%AMINTERLACE_DisplayModeMask         = &H000000c0???
%AMINTERLACE_DisplayModeBobOnly      = &H00000000???
%AMINTERLACE_DisplayModeWeaveOnly    = &H00000040???
%AMINTERLACE_DisplayModeBobOrWeave   = &H00000080???

%AMCOPYPROTECT_RestrictDuplication   = &H00000001???  ' // duplication of this stream should be restricted

%AMMPEG2_DoPanScan           = &H00000001???  ' //if set, the MPEG-2 video decoder should crop output image
                                              ' //  based on pan-scan vectors in picture_display_extension
                                              ' //  and change the picture aspect ratio accordingly.
%AMMPEG2_DVDLine21Field1     = &H00000002???  ' //if set, the MPEG-2 decoder must be able to produce an output
                                              ' //  pin for DVD style closed caption data found in GOP layer of field 1
%AMMPEG2_DVDLine21Field2     = &H00000004???  ' //if set, the MPEG-2 decoder must be able to produce an output
                                              ' //  pin for DVD style closed caption data found in GOP layer of field 2
%AMMPEG2_SourceIsLetterboxed = &H00000008???  ' //if set, indicates that black bars have been encoded in the top
                                              ' //  and bottom of the video.
%AMMPEG2_FilmCameraMode      = &H00000010???  ' //if set, indicates "film mode" used for 625/50 content.  If cleared,
                                              ' //  indicates that "camera mode" was used.
%AMMPEG2_LetterboxAnalogOut  = &H00000020???  ' //if set and this stream is sent to an analog output, it should
                                              ' //  be letterboxed.  Streams sent to VGA should be letterboxed only by renderers.
%AMMPEG2_DSS_UserData        = &H00000040???  ' //if set, the MPEG-2 decoder must process DSS style user data
%AMMPEG2_DVB_UserData        = &H00000080???  ' //if set, the MPEG-2 decoder must process DVB style user data
%AMMPEG2_27MhzTimebase       = &H00000100???  ' //if set, the PTS,DTS timestamps advance at 27MHz rather than 90KHz

%AMMPEG2_WidescreenAnalogOut = &H00000200???  ' //if set and this stream is sent to an analog output, it should
                                              ' //  be in widescreen format (4x3 content should be centered on a 16x9 output).
                                              ' //  Streams sent to VGA should be widescreened only by renderers.

' // PRESENT in dwReserved1 field in VIDEOINFOHEADER2
%AMCONTROL_USED              = &H00000001???  ' // Used to test if these flags are supported.  Set and test for AcceptMediaType.
                                              ' // If rejected, then you cannot use the AMCONTROL flags (send 0 for dwReserved1)
%AMCONTROL_PAD_TO_4x3        = &H00000002???  ' // if set means display the image in a 4x3 area
%AMCONTROL_PAD_TO_16x9       = &H00000004???  ' // if set means display the image in a 16x9 area
%AMCONTROL_COLORINFO_PRESENT = &H00000080???  ' // if set, indicates DXVA color info is present in the upper (24) bits of the dwControlFlags

' // Size = 4 bytes
UNION VIDEOINFOHEADER2_UNION DWORD
   dwControlFlags AS DWORD   ' // use AMCONTROL_* defines, use this from now on
   dwReserved1    AS DWORD   ' // for backward compatiblity (was "must be 0";  connection rejected otherwise)
END UNION

' // Size = 112 bytes
TYPE VIDEOINFOHEADER2 QWORD FILL
   rcSource               AS RECT
   rcTarget               AS RECT
   dwBitRate              AS DWORD
   dwBitErrorRate         AS DWORD
   AvgTimePerFrame        AS QUAD               ' REFERENCE_TIME
   dwInterlaceFlags       AS DWORD              ' // use AMINTERLACE_* defines. Reject connection if undefined bits are not 0
   dwCopyProtectFlags     AS DWORD              ' // use AMCOPYPROTECT_* defines. Reject connection if undefined bits are not 0
   dwPictAspectRatioX     AS DWORD              ' // X dimension of picture aspect ratio, e.g. 16 for 16x9 display
   dwPictAspectRatioY     AS DWORD              ' // Y dimension of picture aspect ratio, e.g.  9 for 16x9 display
   VIDEOINFOHEADER2_UNION
   dwReserved2            AS DWORD              ' // must be 0; reject connection otherwise
   bmiHeader              AS BITMAPINFOHEADER
END TYPE

' // Size = 136 bytes
TYPE MPEG2VIDEOINFO QWORD FILL
   hdr                 AS VIDEOINFOHEADER2
   dwStartTimeCode     AS DWORD              ' //  ?? not used for DVD ??
   cbSequenceHeader    AS DWORD              ' // is 0 for DVD (no sequence header)
   dwProfile           AS DWORD              ' // use enum MPEG2Profile
   dwLevel             AS DWORD              ' // use enum MPEG2Level
   dwFlags             AS DWORD              ' // use AMMPEG2_* defines.  Reject connection if undefined bits are not 0
   dwSequenceHeader(0) AS DWORD              ' // DWORD instead of Byte for alignment purposes
                                             ' //   For MPEG-2, if a sequence_header is included, the sequence_extension
                                             ' //   should also be included
END TYPE

'#define SIZE_MPEG2VIDEOINFO(pv) (FIELD_OFFSET(MPEG2VIDEOINFO, dwSequenceHeader[0]) + (pv)->cbSequenceHeader)

'// do not use
'#define MPEG1_SEQUENCE_INFO(pv) ((const BYTE *)(pv)->bSequenceHeader)

'// use this macro instead, the previous only works for MPEG1VIDEOINFO structures
'#define MPEG2_SEQUENCE_INFO(pv) ((const BYTE *)(pv)->dwSequenceHeader)


'//===================================================================================
'// flags for dwTypeSpecificFlags in AM_SAMPLE2_PROPERTIES which define type specific
'// data in IMediaSample2
'//===================================================================================

%AM_VIDEO_FLAG_FIELD_MASK        = &H0003???   ' // use this mask to check whether the sample is field1 or field2 or frame
%AM_VIDEO_FLAG_INTERLEAVED_FRAME = &H0000???   ' // the sample is a frame (remember to use AM_VIDEO_FLAG_FIELD_MASK when using this)
%AM_VIDEO_FLAG_FIELD1            = &H0001???   ' // the sample is field1 (remember to use AM_VIDEO_FLAG_FIELD_MASK when using this)
%AM_VIDEO_FLAG_FIELD2            = &H0002???   ' // the sample is the field2 (remember to use AM_VIDEO_FLAG_FIELD_MASK when using this)
%AM_VIDEO_FLAG_FIELD1FIRST       = &H0004???   ' // if set means display field1 first, else display field2 first.
                                               ' // this bit is irrelavant for 1FieldPerSample mode
%AM_VIDEO_FLAG_WEAVE             = &H0008???   ' // if set use bob display mode else weave
%AM_VIDEO_FLAG_IPB_MASK          = &H0030???   ' // use this mask to check whether the sample is I, P or B
%AM_VIDEO_FLAG_I_SAMPLE          = &H0000???   ' // I Sample (remember to use AM_VIDEO_FLAG_IPB_MASK when using this)
%AM_VIDEO_FLAG_P_SAMPLE          = &H0010???   ' // P Sample (remember to use AM_VIDEO_FLAG_IPB_MASK when using this)
%AM_VIDEO_FLAG_B_SAMPLE          = &H0020???   ' // B Sample (remember to use AM_VIDEO_FLAG_IPB_MASK when using this)
%AM_VIDEO_FLAG_REPEAT_FIELD      = &H0040???   ' // if set means display the field which has been displayed first again after displaying
                                               ' // both fields first. This bit is irrelavant for 1FieldPerSample mode

'// -----------------------------------------------------------------------
'// AM_KSPROPSETID_DvdKaraoke property set definitions
'// -----------------------------------------------------------------------

' // Size = 8 bytes
TYPE AM_DvdKaraokeData DWORD
   dwDownmix           AS DWORD   ' // bitwise OR of AM_DvdKaraoke_Downmix flags
   dwSpeakerAssignment AS DWORD   ' // AM_DvdKaraoke_SpeakerAssignment
END TYPE

' AM_PROPERTY_DVDKARAOKE enum
%AM_PROPERTY_DVDKARAOKE_ENABLE = 0  ' // BOOL
%AM_PROPERTY_DVDKARAOKE_DATA   = 1

'// -----------------------------------------------------------------------
'// AM_KSPROPSETID_TSRateChange property set definitions for time stamp
'// rate changes.
'// -----------------------------------------------------------------------

' AM_PROPERTY_TS_RATE_CHANGE enum
%AM_RATE_SimpleRateChange       = 1   ' // rw use %AM_SimpleRateChange
%AM_RATE_ExactRateChange        = 2   ' // rw use %AM_ExactRateChange
%AM_RATE_MaxFullDataRate        = 3   ' // r  use %AM_MaxFullDataRate
%AM_RATE_Step                   = 4   ' // w  use %AM_Step
%AM_RATE_UseRateVersion         = 5   ' // w use WORD
%AM_RATE_QueryFullFrameRate     = 6   ' // r use %AM_QueryRate
%AM_RATE_QueryLastRateSegPTS    = 7   ' // r use REFERENCE_TIME
%AM_RATE_CorrectTS              = 8   ' // w  use LONG
%AM_RATE_ReverseMaxFullDataRate = 9   ' // r,  use AM_MaxFullDataRate
%AM_RATE_ResetOnTimeDisc        = 10  ' // rw, use DWORD - indicates supports new 'timeline reset on time discontinuity' sample
%AM_RATE_QueryMapping           = 11

'// -------------------------------------------------------------------
'// AM_KSPROPSETID_DVD_RateChange property set definitions for new DVD
'// rate change scheme.
'// -------------------------------------------------------------------

' AM_PROPERTY_DVD_RATE_CHANGE enum
%AM_RATE_ChangeRate       = 1    ' // w  use %AM_DVD_ChangeRate
%AM_RATE_FullDataRateMax  = 2    ' // r  use %AM_MaxFullDataRate
%AM_RATE_ReverseDecode    = 3    ' // r  use LONG
%AM_RATE_DecoderPosition  = 4    ' // r  use %AM_DVD_DecoderPosition
%AM_RATE_DecoderVersion   = 5    ' // r  use LONG

' // Size = 16 bytes
TYPE AM_SimpleRateChange QWORD
'   // this is the simplest mechanism to set a time stamp rate change on
'   // a filter (simplest for the person setting the rate change, harder
'   // for the filter doing the rate change).
   StartTime AS QUAD   ' REFERENCE_TIME //stream time at which to start this rate
   Rate      AS LONG   ' //new rate * 10000 (decimal)
END TYPE

' // Size = 8 bytes
TYPE AM_QueryRate DWORD
   lMaxForwardFullFrame AS LONG   ' //  rate * 10000
   lMaxReverseFullFrame AS LONG   ' //  rate * 10000
END TYPE

' // Size = 16 bytes
TYPE AM_ExactRateChange QWORD
   OutputZeroTime AS QUAD   ' REFERENCE_TIME //input TS that maps to zero output TS
   Rate           AS LONG   ' //new rate * 10000 (decimal)
END TYPE

'typedef LONG AM_MaxFullDataRate; //rate * 10000 (decimal)

'typedef DWORD AM_Step; // number of frame to step

'// New rate change property set, structs. enums etc.
' // Size = 24 bytes
TYPE AM_DVD_ChangeRate QWORD
   StartInTime  AS QUAD   ' REFERENCE_TIME // stream time (input) at which to start decoding at this rate
   StartOutTime AS QUAD   ' REFERENCE_TIME  // reference time (output) at which to start showing at this rate
   Rate         AS LONG   ' LONG // new rate * 10000 (decimal)
END TYPE

'typedef LONGLONG  AM_DVD_DecoderPosition ;

' DVD_PLAY_DIRECTION enum
%DVD_DIR_FORWARD  = 0
%DVD_DIR_BACKWARD = 1
