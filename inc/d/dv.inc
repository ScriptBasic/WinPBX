' ########################################################################################
' Microsoft Windows
' File: DV.inc
' Contents: DV typedefs and defines
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DV_INC = 1

%DV_DVSD_NTSC_FRAMESIZE = 120000&

%DV_DVSD_PAL_FRAMESIZE  = 144000&

%DV_SMCHN               = &H0000e000???
%DV_AUDIOMODE           = &H00000f00???
%DV_AUDIOSMP            = &H38000000???

%DV_AUDIOQU             = &H07000000???
%DV_NTSCPAL             = &H00200000???
%DV_STYPE               = &H001f0000???


'//There are NTSC or PAL DV camcorders
%DV_NTSC          = 0
%DV_PAL           = 1
'//DV camcorder can output sd/hd/sl
%DV_SD            = &H00
%DV_HD            = &H01
%DV_SL            = &H02
'//user can choice 12 bits or 16 bits audio from DV camcorder
%DV_CAP_AUD16Bits = &H00
%DV_CAP_AUD12Bits = &H01

%SIZE_DVINFO      = &H20

'typedef struct Tag_DVAudInfo
'{
'   BYTE    bAudStyle[2];
'   //LSB 6 bits for starting DIF sequence number
'   //MSB 2 bits: 0 for mon. 1: stereo in one 5/6 DIF sequences, 2: stereo audio in both 5/6 DIF sequences
'   //example: = &H00: mon, audio in first 5/6 DIF sequence
'   //                 = &H05: mon, audio in 2nd 5 DIF sequence
'   //                 = &H15: stereo, audio only in 2nd 5 DIF sequence
'   //                 = &H10: stereo, audio only in 1st 5/6 DIF sequence
'   //                 = &H20: stereo, left ch in 1st 5/6 DIF sequence, right ch in 2nd 5/6 DIF sequence
'   //                 = &H26: stereo, rightch in 1st 6 DIF sequence, left ch in 2nd 6 DIF sequence
'   BYTE    bAudQu[2];                      //qbits, only support 12, 16,

'   BYTE    bNumAudPin;                     //how many pin(language)
'   WORD    wAvgSamplesPerPinPerFrm[2];     //samples size for one audio pin in one frame(which has 10 or 12 DIF sequence)
'   WORD    wBlkMode;                       //45 for NTSC, 54 for PAL
'   WORD    wDIFMode;                       //5  for NTSC, 6 for PAL
'   WORD    wBlkDiv;                        //15  for NTSC, 18 for PAL
'} DVAudInfo;

' // Size = 16 bytes
TYPE DVAudInfo WORD
   bAudStyle (1)               AS BYTE   ' BYTE[2]
   bAudQu (1)                  AS BYTE   ' BYTE[2]
   bNumAudPin                  AS BYTE
   wAvgSamplesPerPinPerFrm (1) AS WORD   ' WORD[2]
   wBlkMode                    AS WORD
   wDIFMode                    AS WORD
   wBlkDiv                     AS WORD
END TYPE
