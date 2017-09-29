' ########################################################################################
' Microsoft Windows
' File: MMReg.inc
' Contents: Multimedia Registration
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'// Define the following to skip definitions
'//
'// NOMMIDS      Multimedia IDs are not defined
'// NONEWWAVE    No new waveform types are defined except WAVEFORMATEX
'// NONEWRIFF    No new RIFF forms are defined
'// NOJPEGDIB    No JPEG DIB definitions
'// NONEWIC      No new Image Compressor types are defined
'// NOBITMAP     No extended bitmap info header definition

#INCLUDE THIS ONCE
%MMREG_INC = 1

#INCLUDE ONCE "mmsystem.inc"

'#if !defined( RC_INVOKED ) && defined( _MSC_VER )
'#if (_MSC_VER <= 800)
'#pragma pack(1)
'#else
'#include "pshpack1.h"   /* Assume byte packing throughout */
'#endif
'#endif  /* RC_INVOKED */

#IF NOT %DEF(%NOMMIDS)
'#ifndef NOMMIDS

'/* manufacturer IDs */
#IF NOT %DEF(%MM_MICROSOFT)
%MM_MICROSOFT                  = 1     ' Microsoft Corporation
#ENDIF

%MM_CREATIVE                   = 2     ' Creative Labs, Inc
%MM_MEDIAVISION                = 3     ' Media Vision, Inc.
%MM_FUJITSU                    = 4     ' Fujitsu Corp.
%MM_ARTISOFT                   = 20    ' Artisoft, Inc.
%MM_TURTLE_BEACH               = 21    ' Turtle Beach, Inc.
%MM_IBM                        = 22    ' IBM Corporation
%MM_VOCALTEC                   = 23    ' Vocaltec LTD.
%MM_ROLAND                     = 24    ' Roland
%MM_DSP_SOLUTIONS              = 25    ' DSP Solutions, Inc.
%MM_NEC                        = 26    ' NEC
%MM_ATI                        = 27    ' ATI
%MM_WANGLABS                   = 28    ' Wang Laboratories, Inc
%MM_TANDY                      = 29    ' Tandy Corporation
%MM_VOYETRA                    = 30    ' Voyetra
%MM_ANTEX                      = 31    ' Antex Electronics Corporation
%MM_ICL_PS                     = 32    ' ICL Personal Systems
%MM_INTEL                      = 33    ' Intel Corporation
%MM_GRAVIS                     = 34    ' Advanced Gravis
%MM_VAL                        = 35    ' Video Associates Labs, Inc.
%MM_INTERACTIVE                = 36    ' InterActive Inc
%MM_YAMAHA                     = 37    ' Yamaha Corporation of America
%MM_EVEREX                     = 38    ' Everex Systems, Inc
%MM_ECHO                       = 39    ' Echo Speech Corporation
%MM_SIERRA                     = 40    ' Sierra Semiconductor Corp
%MM_CAT                        = 41    ' Computer Aided Technologies
%MM_APPS                       = 42    ' APPS Software International
%MM_DSP_GROUP                  = 43    ' DSP Group, Inc
%MM_MELABS                     = 44    ' microEngineering Labs
%MM_COMPUTER_FRIENDS           = 45    ' Computer Friends, Inc.
%MM_ESS                        = 46    ' ESS Technology
%MM_AUDIOFILE                  = 47    ' Audio, Inc.
%MM_MOTOROLA                   = 48    ' Motorola, Inc.
%MM_CANOPUS                    = 49    ' Canopus, co., Ltd.
%MM_EPSON                      = 50    ' Seiko Epson Corporation
%MM_TRUEVISION                 = 51    ' Truevision
%MM_AZTECH                     = 52    ' Aztech Labs, Inc.
%MM_VIDEOLOGIC                 = 53    ' Videologic
%MM_SCALACS                    = 54    ' SCALACS
%MM_KORG                       = 55    ' Korg Inc.
%MM_APT                        = 56    ' Audio Processing Technology
%MM_ICS                        = 57    ' Integrated Circuit Systems, Inc.
%MM_ITERATEDSYS                = 58    ' Iterated Systems, Inc.
%MM_METHEUS                    = 59    ' Metheus
%MM_LOGITECH                   = 60    ' Logitech, Inc.
%MM_WINNOV                     = 61    ' Winnov, Inc.
%MM_NCR                        = 62    ' NCR Corporation
%MM_EXAN                       = 63    ' EXAN
%MM_AST                        = 64    ' AST Research Inc.
%MM_WILLOWPOND                 = 65    ' Willow Pond Corporation
%MM_SONICFOUNDRY               = 66    ' Sonic Foundry
%MM_VITEC                      = 67    ' Vitec Multimedia
%MM_MOSCOM                     = 68    ' MOSCOM Corporation
%MM_SILICONSOFT                = 69    ' Silicon Soft, Inc.
%MM_SUPERMAC                   = 73    ' Supermac
%MM_AUDIOPT                    = 74    ' Audio Processing Technology
%MM_SPEECHCOMP                 = 76    ' Speech Compression
%MM_AHEAD                      = 77    ' Ahead, Inc.
%MM_DOLBY                      = 78    ' Dolby Laboratories
%MM_OKI                        = 79    ' OKI
%MM_AURAVISION                 = 80    ' AuraVision Corporation
%MM_OLIVETTI                   = 81    ' Ing C. Olivetti & C., S.p.A.
%MM_IOMAGIC                    = 82    ' I/O Magic Corporation
%MM_MATSUSHITA                 = 83    ' Matsushita Electric Industrial Co., LTD.
%MM_CONTROLRES                 = 84    ' Control Resources Limited
%MM_XEBEC                      = 85    ' Xebec Multimedia Solutions Limited
%MM_NEWMEDIA                   = 86    ' New Media Corporation
%MM_NMS                        = 87    ' Natural MicroSystems
%MM_LYRRUS                     = 88    ' Lyrrus Inc.
%MM_COMPUSIC                   = 89    ' Compusic
%MM_OPTI                       = 90    ' OPTi Computers Inc.
%MM_ADLACC                     = 91    ' Adlib Accessories Inc.
%MM_COMPAQ                     = 92    ' Compaq Computer Corp.
%MM_DIALOGIC                   = 93    ' Dialogic Corporation
%MM_INSOFT                     = 94    ' InSoft, Inc.
%MM_MPTUS                      = 95    ' M.P. Technologies, Inc.
%MM_WEITEK                     = 96    ' Weitek
%MM_LERNOUT_AND_HAUSPIE        = 97    ' Lernout & Hauspie
%MM_QCIAR                      = 98    ' Quanta Computer Inc.
%MM_APPLE                      = 99    ' Apple Computer, Inc.
%MM_DIGITAL                    = 100   ' Digital Equipment Corporation
%MM_MOTU                       = 101   ' Mark of the Unicorn
%MM_WORKBIT                    = 102   ' Workbit Corporation
%MM_OSITECH                    = 103   ' Ositech Communications Inc.
%MM_MIRO                       = 104   ' miro Computer Products AG
%MM_CIRRUSLOGIC                = 105   ' Cirrus Logic
%MM_ISOLUTION                  = 106   ' ISOLUTION  B.V.
%MM_HORIZONS                   = 107   ' Horizons Technology, Inc
%MM_CONCEPTS                   = 108   ' Computer Concepts Ltd
%MM_VTG                        = 109   ' Voice Technologies Group, Inc.
%MM_RADIUS                     = 110   ' Radius
%MM_ROCKWELL                   = 111   ' Rockwell International
%MM_XYz                        = 112   ' Co. XYZ for testing
%MM_OPCODE                     = 113   ' Opcode Systems
%MM_VOXWARE                    = 114   ' Voxware Inc
%MM_NORTHERN_TELECOM           = 115   ' Northern Telecom Limited
%MM_APICOM                     = 116   ' APICOM
%MM_GRANDE                     = 117   ' Grande Software
%MM_ADDX                       = 118   ' ADDX
%MM_WILDCAT                    = 119   ' Wildcat Canyon Software
%MM_RHETOREX                   = 120   ' Rhetorex Inc
%MM_BROOKTREE                  = 121   ' Brooktree Corporation
%MM_ENSONIQ                    = 125   ' ENSONIQ Corporation
%MM_FAST                       = 126   ' ///FAST Multimedia AG
%MM_NVIDIA                     = 127   ' NVidia Corporation
%MM_OKSORI                     = 128   ' OKSORI Co., Ltd.
%MM_DIACOUSTICS                = 129   ' DiAcoustics, Inc.
%MM_GULBRANSEN                 = 130   ' Gulbransen, Inc.
%MM_KAY_ELEMETRICS             = 131   ' Kay Elemetrics, Inc.
%MM_CRYSTAL                    = 132   ' Crystal Semiconductor Corporation
%MM_SPLASH_STUDIOS             = 133   ' Splash Studios
%MM_QUARTERDECK                = 134   ' Quarterdeck Corporation
%MM_TDK                        = 135   ' TDK Corporation
%MM_DIGITAL_AUDIO_LABS         = 136   ' Digital Audio Labs, Inc.
%MM_SEERSYS                    = 137   ' Seer Systems, Inc.
%MM_PICTURETEL                 = 138   ' PictureTel Corporation
%MM_ATT_MICROELECTRONICS       = 139   ' AT&T Microelectronics
%MM_OSPREY                     = 140   ' Osprey Technologies, Inc.
%MM_MEDIATRIX                  = 141   ' Mediatrix Peripherals
%MM_SOUNDESIGNS                = 142   ' SounDesignS M.C.S. Ltd.
%MM_ALDIGITAL                  = 143   ' A.L. Digital Ltd.
%MM_SPECTRUM_SIGNAL_PROCESSING = 144   ' Spectrum Signal Processing, Inc.
%MM_ECS                        = 145   ' Electronic Courseware Systems, Inc.
%MM_AMD                        = 146   ' AMD
%MM_COREDYNAMICS               = 147   ' Core Dynamics
%MM_CANAM                      = 148   ' CANAM Computers
%MM_SOFTSOUND                  = 149   ' Softsound, Ltd.
%MM_NORRIS                     = 150   ' Norris Communications, Inc.
%MM_DDD                        = 151   ' Danka Data Devices
%MM_EUPHONICS                  = 152   ' EuPhonics
%MM_PRECEPT                    = 153   ' Precept Software, Inc.
%MM_CRYSTAL_NET                = 154   ' Crystal Net Corporation
%MM_CHROMATIC                  = 155   ' Chromatic Research, Inc
%MM_VOICEINFO                  = 156   ' Voice Information Systems, Inc
%MM_VIENNASYS                  = 157   ' Vienna Systems
%MM_CONNECTIX                  = 158   ' Connectix Corporation
%MM_GADGETLABS                 = 159   ' Gadget Labs LLC
%MM_FRONTIER                   = 160   ' Frontier Design Group LLC
%MM_VIONA                      = 161   ' Viona Development GmbH
%MM_CASIO                      = 162   ' Casio Computer Co., LTD
%MM_DIAMONDMM                  = 163   ' Diamond Multimedia
%MM_S3                         = 164   ' S3
%MM_FRAUNHOFER_IIS             = 172   ' Fraunhofer
%MM_QUICKNET                   = 173   ' Quicknet Technologies
%MM_ALARIS                     = 174   ' Alaris, Inc.
%MM_SICRESOURCE                = 175   ' SIC Resource Inc.
%MM_NEOMAGIC                   = 176   ' NeoMagic Corporation
%MM_MERGING_TECHNOLOGIES       = 177   ' Merging Technologies S.A.
%MM_XIRLINK                    = 178   ' Xirlink, Inc.
%MM_COLORGRAPH                 = 179   ' Colorgraph (UK) Ltd *' /
%MM_OTI                        = 180   ' Oak Technology, Inc.
%MM_AUREAL                     = 181   ' Aureal Semiconductor
%MM_VIVO                       = 182   ' Vivo Software
%MM_SHARP                      = 183   ' Sharp
%MM_LUCENT                     = 184   ' Lucent Technologies
%MM_ATT                        = 185   ' AT&T Labs, Inc.
%MM_SUNCOM                     = 186   ' Sun Communications, Inc.
%MM_SORVIS                     = 187   ' Sorenson Vision
%MM_INVISION                   = 188   ' InVision Interactive
%MM_BERKOM                     = 189   ' Deutsche Telekom Berkom GmbH
%MM_MARIAN                     = 190   ' Marian GbR Leipzig
%MM_DPSINC                     = 191   ' Digital Processing Systems, Inc.
%MM_BCB                        = 192   ' BCB Holdings Inc.
%MM_MOTIONPIXELS               = 193   ' Motion Pixels
%MM_QDESIGN                    = 194   ' QDesign Corporation
%MM_NMP                        = 195   ' Nokia Mobile Phones
%MM_DATAFUSION                 = 196   ' DataFusion Systems (Pty) (Ltd)
%MM_DUCK                       = 197   ' The Duck Corporation
%MM_FTR                        = 198   ' Future Technology Resources Pty Ltd
%MM_BERCOS                     = 199   ' BERCOS GmbH
%MM_ONLIVE                     = 200   ' OnLive! Technologies, Inc.
%MM_SIEMENS_SBC                = 201   ' Siemens Business Communications Systems
%MM_TERALOGIC                  = 202   ' TeraLogic, Inc.
%MM_PHONET                     = 203   ' PhoNet Communications Ltd.
%MM_WINBOND                    = 204   ' Winbond Electronics Corp
%MM_VIRTUALMUSIC               = 205   ' Virtual Music, Inc.
%MM_ENET                       = 206   ' e-Net, Inc.
%MM_GUILLEMOT                  = 207   ' Guillemot International
%MM_EMAGIC                     = 208   ' Emagic Soft- und Hardware GmbH
%MM_MWM                        = 209   ' MWM Acoustics LLC
%MM_PACIFICRESEARCH            = 210   ' Pacific Research and Engineering Corporation
%MM_SIPROLAB                   = 211   ' Sipro Lab Telecom Inc.
%MM_LYNX                       = 212   ' Lynx Studio Technology, Inc.
%MM_SPECTRUM_PRODUCTIONS       = 213   ' Spectrum Productions
%MM_DICTAPHONE                 = 214   ' Dictaphone Corporation
%MM_QUALCOMM                   = 215   ' QUALCOMM, Inc.
%MM_RZS                        = 216   ' Ring Zero Systems, Inc
%MM_AUDIOSCIENCE               = 217   ' AudioScience Inc.
%MM_PINNACLE                   = 218   ' Pinnacle Systems, Inc.
%MM_EES                        = 219   ' EES Technik für Musik GmbH
%MM_HAFTMANN                   = 220   ' haftmann#software
%MM_LUCID                      = 221   ' Lucid Technology, Symetrix Inc.
%MM_HEADSPACE                  = 222   ' Headspace, Inc
%MM_UNISYS                     = 223   ' UNISYS CORPORATION
%MM_LUMINOSITI                 = 224   ' Luminositi, Inc.
%MM_ACTIVEVOICE                = 225   ' ACTIVE VOICE CORPORATION
%MM_DTS                        = 226   ' Digital Theater Systems, Inc.
%MM_DIGIGRAM                   = 227   ' DIGIGRAM
%MM_SOFTLAB_NSK                = 228   ' Softlab-Nsk
%MM_FORTEMEDIA                 = 229   ' ForteMedia, Inc
%MM_SONORUS                    = 230   ' Sonorus, Inc.
%MM_ARRAY                      = 231   ' Array Microsystems, Inc.
%MM_DATARAN                    = 232   ' Data Translation, Inc.
%MM_I_LINK                     = 233   ' I-link Worldwide
%MM_SELSIUS_SYSTEMS            = 234   ' Selsius Systems Inc.
%MM_ADMOS                      = 235   ' AdMOS Technology, Inc.
%MM_LEXICON                    = 236   ' Lexicon Inc.
%MM_SGI                        = 237   ' Silicon Graphics Inc.
%MM_IPI                        = 238   ' Interactive Product Inc.
%MM_ICE                        = 239   ' IC Ensemble, Inc.
%MM_VQST                       = 240   ' ViewQuest Technologies Inc.
%MM_ETEK                       = 241   ' eTEK Labs Inc.
%MM_CS                         = 242   ' Consistent Software
%MM_ALESIS                     = 243   ' Alesis Studio Electronics
%MM_INTERNET                   = 244   ' INTERNET Corporation
%MM_SONY                       = 245   ' Sony Corporation
%MM_HYPERACTIVE                = 246   ' Hyperactive Audio Systems, Inc.
%MM_UHER_INFORMATIC            = 247   ' UHER informatic GmbH
%MM_SYDEC_NV                   = 248   ' Sydec NV
%MM_FLEXION                    = 249   ' Flexion Systems Ltd.
%MM_VIA                        = 250   ' Via Technologies, Inc.
%MM_MICRONAS                   = 251   ' Micronas Semiconductors, Inc.
%MM_ANALOGDEVICES              = 252   ' Analog Devices, Inc.
%MM_HP                         = 253   ' Hewlett Packard Company
%MM_MATROX_DIV                 = 254   ' Matrox
%MM_QUICKAUDIO                 = 255   ' Quick Audio, GbR
%MM_YOUCOM                     = 256   ' You' /Com Audiocommunicatie BV
%MM_RICHMOND                   = 257   ' Richmond Sound Design Ltd.
%MM_IODD                       = 258   ' I-O Data Device, Inc.
%MM_ICCC                       = 259   ' ICCC A' /S
%MM_3COM                       = 260   ' 3COM Corporation
%MM_MALDEN                     = 261   ' Malden Electronics Ltd.
%MM_3DFX                       = 262   ' 3Dfx Interactive, Inc.
%MM_MINDMAKER                  = 263   ' Mindmaker, Inc.
%MM_TELEKOL                    = 264   ' Telekol Corp.
%MM_ST_MICROELECTRONICS        = 265   ' ST Microelectronics
%MM_ALGOVISION                 = 266   ' Algo Vision Systems GmbH

%MM_UNMAPPED                   = &Hffff' extensible MID mapping

%MM_PID_UNMAPPED               = %MM_UNMAPPED ' /* extensible PID mapping

'#ifdef GUID_DEFINED
'#if !defined(INIT_MMREG_MID)
#IF %DEF(%GUID_DEFINED)
#IF NOT %DEF(%INIT_MMREG_MID)
%INIT_MMREG_MID = 1
'//{d5a47fa7-6d98-11d1-a21a-00a0c9223196}
'#define INIT_MMREG_MID(guid, id)\
'{\
'    (guid)->Data1 = 0xd5a47fa7 + (USHORT)(id);\
'    (guid)->Data2 = 0x6d98;\
'    (guid)->Data3 = 0x11d1;\
'    (guid)->Data4[0] = 0xa2;\
'    (guid)->Data4[1] = 0x1a;\
'    (guid)->Data4[2] = 0x00;\
'    (guid)->Data4[3] = 0xa0;\
'    (guid)->Data4[4] = 0xc9;\
'    (guid)->Data4[5] = 0x22;\
'    (guid)->Data4[6] = 0x31;\
'    (guid)->Data4[7] = 0x96;\
'}

SUB INIT_MMREG_MID (BYREF rguid AS GUID, BYVAL id AS WORD)
   LOCAL apiguid AS GUIDAPI
   apiguid.Data1 = &Hd5a47fa7 + id
   apiguid.Data2 = &H6d98
   apiguid.Data3 = &H11d1
   apiguid.Data4 = CHR$(&Ha2, &H1a, &H00, &Ha0, &Hc9, &H22, &H31, &H96)
   rguid = apiguid
END SUB

'#define EXTRACT_MMREG_MID(guid)\
'    (USHORT)((guid)->Data1 - 0xd5a47fa7)

SUB EXTRACT_MMREG_MID (BYREF rguid AS GUID)
   LOCAL apiguid AS GUIDAPI
   LSET apiguid = rguid
   apiguid.Data1 = apiguid.Data1 - &Hd5a47fa7
   rguid = apiguid
END SUB

'#define DEFINE_MMREG_MID_GUID(id)\
'    0xd5a47fa7+(USHORT)(id), 0x6d98, 0x11d1, 0xa2, 0x1a, 0x00, 0xa0, 0xc9, 0x22, 0x31, 0x96

FUNCTION DEFINE_MMREG_MID_GUID (BYVAL id AS WORD) AS STRING
   LOCAL apiguid AS GUIDAPI
   apiguid.Data1 = &Hd5a47fa7 + id
   apiguid.Data2 = &H6d98
   apiguid.Data3 = &H11d1
   apiguid.Data4 = CHR$(&Ha2, &H1a, &H00, &Ha0, &Hc9, &H22, &H31, &H96)
   FUNCTION = apiguid
END FUNCTION

'#define IS_COMPATIBLE_MMREG_MID(guid)\
'    (((guid)->Data1 >= 0xd5a47fa7) &&\
'    ((guid)->Data1 < 0xd5a47fa7 + 0xffff) &&\
'    ((guid)->Data2 == 0x6d98) &&\
'    ((guid)->Data3 == 0x11d1) &&\
'    ((guid)->Data4[0] == 0xa2) &&\
'    ((guid)->Data4[1] == 0x1a) &&\
'    ((guid)->Data4[2] == 0x00) &&\
'    ((guid)->Data4[3] == 0xa0) &&\
'    ((guid)->Data4[4] == 0xc9) &&\
'    ((guid)->Data4[5] == 0x22) &&\
'    ((guid)->Data4[6] == 0x31) &&\
'    ((guid)->Data4[7] == 0x96))

FUNCTION IS_COMPATIBLE_MMREG_MID (BYREF rguid AS GUID) AS LONG
   LOCAL apiguid AS GUIDAPI
   LSET apiguid = rguid
   IF apiguid.Data1 >= &Hd5a47fa7 AND _
      apiguid.Data1 < &Hd5a47fa7 + &Hffff AND _
      apiguid.Data2 = &H6d98 AND _
      apiguid.Data3 = &H11d1 AND _
      ASC(MID$(apiguid.Data4, 1)) = &Ha2 AND _
      ASC(MID$(apiguid.Data4, 2)) = &H1a AND _
      ASC(MID$(apiguid.Data4, 3)) = &H00 AND _
      ASC(MID$(apiguid.Data4, 4)) = &Ha0 AND _
      ASC(MID$(apiguid.Data4, 5)) = &Hc9 AND _
      ASC(MID$(apiguid.Data4, 6)) = &H22 AND _
      ASC(MID$(apiguid.Data4, 7)) = &H31 AND _
      ASC(MID$(apiguid.Data4, 8)) = &H86 THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION
'#endif // !defined(INIT_MMREG_MID)
#ENDIF   ' #IF NOT %DEF(%INIT_MMREG_MID)

#IF NOT %DEF(%INIT_MMREG_PID)
%INIT_MMREG_PID = 1
'#if !defined(INIT_MMREG_PID)
'//{e36dc2ac-6d9a-11d1-a21a-00a0c9223196}
'#define INIT_MMREG_PID(guid, id)\
'{\
'    (guid)->Data1 = 0xe36dc2ac + (USHORT)(id);\
'    (guid)->Data2 = 0x6d9a;\
'    (guid)->Data3 = 0x11d1;\
'    (guid)->Data4[0] = 0xa2;\
'    (guid)->Data4[1] = 0x1a;\
'    (guid)->Data4[2] = 0x00;\
'    (guid)->Data4[3] = 0xa0;\
'    (guid)->Data4[4] = 0xc9;\
'    (guid)->Data4[5] = 0x22;\
'    (guid)->Data4[6] = 0x31;\
'    (guid)->Data4[7] = 0x96;\
'}

SUB INIT_MMREG_PID (BYREF rguid AS GUID, BYVAL id AS WORD)
   LOCAL apiguid AS GUIDAPI
   apiguid.Data1 = &He36dc2ac + id
   apiguid.Data2 = &H6d9a
   apiguid.Data3 = &H11d1
   apiguid.Data4 = CHR$(&Ha2, &H1a, &H00, &Ha0, &Hc9, &H22, &H31, &H96)
   rguid = apiguid
END SUB

'#define EXTRACT_MMREG_PID(guid)\
'    (USHORT)((guid)->Data1 - 0xe36dc2ac)

SUB EXTRACT_MMREG_PID (BYREF rguid AS GUID)
   LOCAL apiguid AS GUIDAPI
   LSET apiguid = rguid
   apiguid.Data1 = apiguid.Data1 - &He36dc2ac
   rguid = apiguid
END SUB

'#define DEFINE_MMREG_PID_GUID(id)\
'    0xe36dc2ac+(USHORT)(id), 0x6d9a, 0x11d1, 0xa2, 0x1a, 0x00, 0xa0, 0xc9, 0x22, 0x31, 0x96

FUNCTION DEFINE_MMREG_PID_GUID (BYVAL id AS WORD) AS STRING
   LOCAL apiguid AS GUIDAPI
   apiguid.Data1 = &He36dc2ac + id
   apiguid.Data2 = &H6d9a
   apiguid.Data3 = &H11d1
   apiguid.Data4 = CHR$(&Ha2, &H1a, &H00, &Ha0, &Hc9, &H22, &H31, &H96)
   FUNCTION = apiguid
END FUNCTION

'#define IS_COMPATIBLE_MMREG_PID(guid)\
'    (((guid)->Data1 >= 0xe36dc2ac) &&\
'    ((guid)->Data1 < 0xe36dc2ac + 0xffff) &&\
'    ((guid)->Data2 == 0x6d9a) &&\
'    ((guid)->Data3 == 0x11d1) &&\
'    ((guid)->Data4[0] == 0xa2) &&\
'    ((guid)->Data4[1] == 0x1a) &&\
'    ((guid)->Data4[2] == 0x00) &&\
'    ((guid)->Data4[3] == 0xa0) &&\
'    ((guid)->Data4[4] == 0xc9) &&\
'    ((guid)->Data4[5] == 0x22) &&\
'    ((guid)->Data4[6] == 0x31) &&\
'    ((guid)->Data4[7] == 0x96))

FUNCTION IS_COMPATIBLE_MMREG_PID (BYREF rguid AS GUID) AS LONG
   LOCAL apiguid AS GUIDAPI
   LSET apiguid = rguid
   IF apiguid.Data1 >= &He36dc2ac AND _
      apiguid.Data1 < &He36dc2ac + &Hffff AND _
      apiguid.Data2 = &H6d9a AND _
      apiguid.Data3 = &H11d1 AND _
      ASC(MID$(apiguid.Data4, 1)) = &Ha2 AND _
      ASC(MID$(apiguid.Data4, 2)) = &H1a AND _
      ASC(MID$(apiguid.Data4, 3)) = &H00 AND _
      ASC(MID$(apiguid.Data4, 4)) = &Ha0 AND _
      ASC(MID$(apiguid.Data4, 5)) = &Hc9 AND _
      ASC(MID$(apiguid.Data4, 6)) = &H22 AND _
      ASC(MID$(apiguid.Data4, 7)) = &H31 AND _
      ASC(MID$(apiguid.Data4, 8)) = &H86 THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION

'#endif // !defined(INIT_MMREG_PID)
'#endif // GUID_DEFINED
#ENDIF   ' #IF %DEF(%INIT_MMREG_PID)
#ENDIF   ' #IF %DEF(%GUID_DEFINED)

'/* MM_MICROSOFT product IDs */

#IF NOT %DEF(%MM_MIDI_MAPPER)
%MM_MIDI_MAPPER     = 1   ' MIDI Mapper
%MM_WAVE_MAPPER     = 2   ' Wave Mapper
%MM_SNDBLST_MIDIOUT = 3   ' Sound Blaster MIDI output port
%MM_SNDBLST_MIDIIN  = 4   ' Sound Blaster MIDI input port
%MM_SNDBLST_SYNTH   = 5   ' Sound Blaster internal synthesizer
%MM_SNDBLST_WAVEOUT = 6   ' Sound Blaster waveform output
%MM_SNDBLST_WAVEIN  = 7   ' Sound Blaster waveform input
%MM_ADLIB           = 9   ' Ad Lib-compatible synthesizer
%MM_MPU401_MIDIOUT  = 10  ' MPU401-compatible MIDI output port
%MM_MPU401_MIDIIN   = 11  ' MPU401-compatible MIDI input port
%MM_PC_JOYSTICK     = 12  ' Joystick adapter
#ENDIF   ' #IF NOT %DEF(%MM_MIDI_MAPPER)

%MM_PCSPEAKER_WAVEOUT           = 13  ' PC speaker waveform output
%MM_MSFT_WSS_WAVEIN             = 14  ' MS Audio Board waveform input
%MM_MSFT_WSS_WAVEOUT            = 15  ' MS Audio Board waveform output
%MM_MSFT_WSS_FMSYNTH_STEREO     = 16  ' MS Audio Board  Stereo FM synth
%MM_MSFT_WSS_MIXER              = 17  ' MS Audio Board Mixer Driver
%MM_MSFT_WSS_OEM_WAVEIN         = 18  ' MS OEM Audio Board waveform input
%MM_MSFT_WSS_OEM_WAVEOUT        = 19  ' MS OEM Audio Board waveform output
%MM_MSFT_WSS_OEM_FMSYNTH_STEREO = 20  ' MS OEM Audio Board Stereo FM Synth
%MM_MSFT_WSS_AUX                = 21  ' MS Audio Board Aux. Port
%MM_MSFT_WSS_OEM_AUX            = 22  ' MS OEM Audio Aux Port
%MM_MSFT_GENERIC_WAVEIN         = 23  ' MS Vanilla driver waveform input
%MM_MSFT_GENERIC_WAVEOUT        = 24  ' MS Vanilla driver wavefrom output
%MM_MSFT_GENERIC_MIDIIN         = 25  ' MS Vanilla driver MIDI in
%MM_MSFT_GENERIC_MIDIOUT        = 26  ' MS Vanilla driver MIDI  external out
%MM_MSFT_GENERIC_MIDISYNTH      = 27  ' MS Vanilla driver MIDI synthesizer
%MM_MSFT_GENERIC_AUX_LINE       = 28  ' MS Vanilla driver aux (line in)
%MM_MSFT_GENERIC_AUX_MIC        = 29  ' MS Vanilla driver aux (mic)
%MM_MSFT_GENERIC_AUX_CD         = 30  ' MS Vanilla driver aux (CD)
%MM_MSFT_WSS_OEM_MIXER          = 31  ' MS OEM Audio Board Mixer Driver
%MM_MSFT_MSACM                  = 32  ' MS Audio Compression Manager
%MM_MSFT_ACM_MSADPCM            = 33  ' MS ADPCM Codec
%MM_MSFT_ACM_IMAADPCM           = 34  ' IMA ADPCM Codec
%MM_MSFT_ACM_MSFILTER           = 35  ' MS Filter
%MM_MSFT_ACM_GSM610             = 36  ' GSM 610 codec
%MM_MSFT_ACM_G711               = 37  ' G.711 codec
%MM_MSFT_ACM_PCM                = 38  ' PCM converter

'   // Microsoft Windows Sound System drivers

%MM_WSS_SB16_WAVEIN            = 39   ' Sound Blaster 16 waveform input
%MM_WSS_SB16_WAVEOUT           = 40   ' Sound Blaster 16  waveform output
%MM_WSS_SB16_MIDIIN            = 41   ' Sound Blaster 16 midi-in
%MM_WSS_SB16_MIDIOUT           = 42   ' Sound Blaster 16 midi out
%MM_WSS_SB16_SYNTH             = 43   ' Sound Blaster 16 FM Synthesis
%MM_WSS_SB16_AUX_LINE          = 44   ' Sound Blaster 16 aux (line in)
%MM_WSS_SB16_AUX_CD            = 45   ' Sound Blaster 16 aux (CD)
%MM_WSS_SB16_MIXER             = 46   ' Sound Blaster 16 mixer device
%MM_WSS_SBPRO_WAVEIN           = 47   ' Sound Blaster Pro waveform input
%MM_WSS_SBPRO_WAVEOUT          = 48   ' Sound Blaster Pro waveform output
%MM_WSS_SBPRO_MIDIIN           = 49   ' Sound Blaster Pro midi in
%MM_WSS_SBPRO_MIDIOUT          = 50   ' Sound Blaster Pro midi out
%MM_WSS_SBPRO_SYNTH            = 51   ' Sound Blaster Pro FM synthesis
%MM_WSS_SBPRO_AUX_LINE         = 52   ' Sound Blaster Pro aux (line in )
%MM_WSS_SBPRO_AUX_CD           = 53   ' Sound Blaster Pro aux (CD)
%MM_WSS_SBPRO_MIXER            = 54   ' Sound Blaster Pro mixer
%MM_MSFT_WSS_NT_WAVEIN         = 55   ' WSS NT wave in
%MM_MSFT_WSS_NT_WAVEOUT        = 56   ' WSS NT wave out
%MM_MSFT_WSS_NT_FMSYNTH_STEREO = 57   ' WSS NT FM synth
%MM_MSFT_WSS_NT_MIXER          = 58   ' WSS NT mixer
%MM_MSFT_WSS_NT_AUX            = 59   ' WSS NT aux
%MM_MSFT_SB16_WAVEIN           = 60   ' Sound Blaster 16 waveform input
%MM_MSFT_SB16_WAVEOUT          = 61   ' Sound Blaster 16  waveform output
%MM_MSFT_SB16_MIDIIN           = 62   ' Sound Blaster 16 midi-in
%MM_MSFT_SB16_MIDIOUT          = 63   ' Sound Blaster 16 midi out
%MM_MSFT_SB16_SYNTH            = 64   ' Sound Blaster 16 FM Synthesis
%MM_MSFT_SB16_AUX_LINE         = 65   ' Sound Blaster 16 aux (line in)
%MM_MSFT_SB16_AUX_CD           = 66   ' Sound Blaster 16 aux (CD)
%MM_MSFT_SB16_MIXER            = 67   ' Sound Blaster 16 mixer device
%MM_MSFT_SBPRO_WAVEIN          = 68   ' Sound Blaster Pro waveform input
%MM_MSFT_SBPRO_WAVEOUT         = 69   ' Sound Blaster Pro waveform output
%MM_MSFT_SBPRO_MIDIIN          = 70   ' Sound Blaster Pro midi in
%MM_MSFT_SBPRO_MIDIOUT         = 71   ' Sound Blaster Pro midi out
%MM_MSFT_SBPRO_SYNTH           = 72   ' Sound Blaster Pro FM synthesis
%MM_MSFT_SBPRO_AUX_LINE        = 73   ' Sound Blaster Pro aux (line in )
%MM_MSFT_SBPRO_AUX_CD          = 74   ' Sound Blaster Pro aux (CD)
%MM_MSFT_SBPRO_MIXER           = 75   ' Sound Blaster Pro mixer

%MM_MSFT_MSOPL_SYNTH           = 76   ' Yamaha OPL2/OPL3 compatible FM synthesis

%MM_MSFT_VMDMS_LINE_WAVEIN     = 80   ' Voice Modem Serial Line Wave Input
%MM_MSFT_VMDMS_LINE_WAVEOUT    = 81   ' Voice Modem Serial Line Wave Output
%MM_MSFT_VMDMS_HANDSET_WAVEIN  = 82   ' Voice Modem Serial Handset Wave Input
%MM_MSFT_VMDMS_HANDSET_WAVEOUT = 83   ' Voice Modem Serial Handset Wave Output
%MM_MSFT_VMDMW_LINE_WAVEIN     = 84   ' Voice Modem Wrapper Line Wave Input
%MM_MSFT_VMDMW_LINE_WAVEOUT    = 85   ' Voice Modem Wrapper Line Wave Output
%MM_MSFT_VMDMW_HANDSET_WAVEIN  = 86   ' Voice Modem Wrapper Handset Wave Input
%MM_MSFT_VMDMW_HANDSET_WAVEOUT = 87   ' Voice Modem Wrapper Handset Wave Output
%MM_MSFT_VMDMW_MIXER           = 88   ' Voice Modem Wrapper Mixer
%MM_MSFT_VMDM_GAME_WAVEOUT     = 89   ' Voice Modem Game Compatible Wave Device
%MM_MSFT_VMDM_GAME_WAVEIN      = 90   ' Voice Modem Game Compatible Wave Device

%MM_MSFT_ACM_MSNAUDIO          = 91
%MM_MSFT_ACM_MSG723            = 92
%MM_MSFT_ACM_MSRT24            = 93

%MM_MSFT_WDMAUDIO_WAVEOUT      = 100  ' Generic id for WDM Audio drivers
%MM_MSFT_WDMAUDIO_WAVEIN       = 101  ' Generic id for WDM Audio drivers
%MM_MSFT_WDMAUDIO_MIDIOUT      = 102  ' Generic id for WDM Audio drivers
%MM_MSFT_WDMAUDIO_MIDIIN       = 103  ' Generic id for WDM Audio drivers
%MM_MSFT_WDMAUDIO_MIXER        = 104  ' Generic id for WDM Audio drivers
%MM_MSFT_WDMAUDIO_AUX          = 105  ' Generic id for WDM Audio drivers */

'/* MM_CREATIVE product IDs */
%MM_CREATIVE_SB15_WAVEIN      = 1    ' SB (r) 1.5 waveform input
%MM_CREATIVE_SB20_WAVEIN      = 2
%MM_CREATIVE_SBPRO_WAVEIN     = 3
%MM_CREATIVE_SBP16_WAVEIN     = 4
%MM_CREATIVE_PHNBLST_WAVEIN   = 5
%MM_CREATIVE_SB15_WAVEOUT     = 101
%MM_CREATIVE_SB20_WAVEOUT     = 102
%MM_CREATIVE_SBPRO_WAVEOUT    = 103
%MM_CREATIVE_SBP16_WAVEOUT    = 104
%MM_CREATIVE_PHNBLST_WAVEOUT  = 105
%MM_CREATIVE_MIDIOUT          = 201  ' SB (r)
%MM_CREATIVE_MIDIIN           = 202  ' SB (r)
%MM_CREATIVE_FMSYNTH_MONO     = 301  ' SB (r)
%MM_CREATIVE_FMSYNTH_STEREO   = 302  ' SB Pro (r) stereo synthesizer
%MM_CREATIVE_MIDI_AWE32       = 303
%MM_CREATIVE_AUX_CD           = 401  ' SB Pro (r) aux (CD)
%MM_CREATIVE_AUX_LINE         = 402  ' SB Pro (r) aux (Line in)
%MM_CREATIVE_AUX_MIC          = 403  ' SB Pro (r) aux (mic)
%MM_CREATIVE_AUX_MASTER       = 404
%MM_CREATIVE_AUX_PCSPK        = 405
%MM_CREATIVE_AUX_WAVE         = 406
%MM_CREATIVE_AUX_MIDI         = 407
%MM_CREATIVE_SBPRO_MIXER      = 408
%MM_CREATIVE_SB16_MIXER       = 409

'/* MM_MEDIAVISION product IDs */

'// Pro Audio Spectrum
%MM_MEDIAVISION_PROAUDIO      = &H10
%MM_PROAUD_MIDIOUT            = (%MM_MEDIAVISION_PROAUDIO+1)
%MM_PROAUD_MIDIIN             = (%MM_MEDIAVISION_PROAUDIO+2)
%MM_PROAUD_SYNTH              = (%MM_MEDIAVISION_PROAUDIO+3)
%MM_PROAUD_WAVEOUT            = (%MM_MEDIAVISION_PROAUDIO+4)
%MM_PROAUD_WAVEIN             = (%MM_MEDIAVISION_PROAUDIO+5)
%MM_PROAUD_MIXER              = (%MM_MEDIAVISION_PROAUDIO+6)
%MM_PROAUD_AUX                = (%MM_MEDIAVISION_PROAUDIO+7)

'// Thunder Board
%MM_MEDIAVISION_THUNDER       = &H20
%MM_THUNDER_SYNTH             = (%MM_MEDIAVISION_THUNDER+3)
%MM_THUNDER_WAVEOUT           = (%MM_MEDIAVISION_THUNDER+4)
%MM_THUNDER_WAVEIN            = (%MM_MEDIAVISION_THUNDER+5)
%MM_THUNDER_AUX               = (%MM_MEDIAVISION_THUNDER+7)

'// Audio Port
%MM_MEDIAVISION_TPORT         = &H40
%MM_TPORT_WAVEOUT             = (%MM_MEDIAVISION_TPORT+1)
%MM_TPORT_WAVEIN              = (%MM_MEDIAVISION_TPORT+2)
%MM_TPORT_SYNTH               = (%MM_MEDIAVISION_TPORT+3)

'// Pro Audio Spectrum Plus
%MM_MEDIAVISION_PROAUDIO_PLUS = &H50
%MM_PROAUD_PLUS_MIDIOUT       = (%MM_MEDIAVISION_PROAUDIO_PLUS+1)
%MM_PROAUD_PLUS_MIDIIN        = (%MM_MEDIAVISION_PROAUDIO_PLUS+2)
%MM_PROAUD_PLUS_SYNTH         = (%MM_MEDIAVISION_PROAUDIO_PLUS+3)
%MM_PROAUD_PLUS_WAVEOUT       = (%MM_MEDIAVISION_PROAUDIO_PLUS+4)
%MM_PROAUD_PLUS_WAVEIN        = (%MM_MEDIAVISION_PROAUDIO_PLUS+5)
%MM_PROAUD_PLUS_MIXER         = (%MM_MEDIAVISION_PROAUDIO_PLUS+6)
%MM_PROAUD_PLUS_AUX           = (%MM_MEDIAVISION_PROAUDIO_PLUS+7)

'// Pro Audio Spectrum 16
%MM_MEDIAVISION_PROAUDIO_16   = &H60
%MM_PROAUD_16_MIDIOUT         = (%MM_MEDIAVISION_PROAUDIO_16+1)
%MM_PROAUD_16_MIDIIN          = (%MM_MEDIAVISION_PROAUDIO_16+2)
%MM_PROAUD_16_SYNTH           = (%MM_MEDIAVISION_PROAUDIO_16+3)
%MM_PROAUD_16_WAVEOUT         = (%MM_MEDIAVISION_PROAUDIO_16+4)
%MM_PROAUD_16_WAVEIN          = (%MM_MEDIAVISION_PROAUDIO_16+5)
%MM_PROAUD_16_MIXER           = (%MM_MEDIAVISION_PROAUDIO_16+6)
%MM_PROAUD_16_AUX             = (%MM_MEDIAVISION_PROAUDIO_16+7)

'// Pro Audio Studio 16
%MM_MEDIAVISION_PROSTUDIO_16  = &H60
%MM_STUDIO_16_MIDIOUT         = (%MM_MEDIAVISION_PROSTUDIO_16+1)
%MM_STUDIO_16_MIDIIN          = (%MM_MEDIAVISION_PROSTUDIO_16+2)
%MM_STUDIO_16_SYNTH           = (%MM_MEDIAVISION_PROSTUDIO_16+3)
%MM_STUDIO_16_WAVEOUT         = (%MM_MEDIAVISION_PROSTUDIO_16+4)
%MM_STUDIO_16_WAVEIN          = (%MM_MEDIAVISION_PROSTUDIO_16+5)
%MM_STUDIO_16_MIXER           = (%MM_MEDIAVISION_PROSTUDIO_16+6)
%MM_STUDIO_16_AUX             = (%MM_MEDIAVISION_PROSTUDIO_16+7)

'// CDPC
%MM_MEDIAVISION_CDPC          = &H70
%MM_CDPC_MIDIOUT              = (%MM_MEDIAVISION_CDPC+1)
%MM_CDPC_MIDIIN               = (%MM_MEDIAVISION_CDPC+2)
%MM_CDPC_SYNTH                = (%MM_MEDIAVISION_CDPC+3)
%MM_CDPC_WAVEOUT              = (%MM_MEDIAVISION_CDPC+4)
%MM_CDPC_WAVEIN               = (%MM_MEDIAVISION_CDPC+5)
%MM_CDPC_MIXER                = (%MM_MEDIAVISION_CDPC+6)
%MM_CDPC_AUX                  = (%MM_MEDIAVISION_CDPC+7)

'// Opus MV 1208 Chipsent
%MM_MEDIAVISION_OPUS1208      = &H80
%MM_OPUS401_MIDIOUT           = (%MM_MEDIAVISION_OPUS1208+1)
%MM_OPUS401_MIDIIN            = (%MM_MEDIAVISION_OPUS1208+2)
%MM_OPUS1208_SYNTH            = (%MM_MEDIAVISION_OPUS1208+3)
%MM_OPUS1208_WAVEOUT          = (%MM_MEDIAVISION_OPUS1208+4)
%MM_OPUS1208_WAVEIN           = (%MM_MEDIAVISION_OPUS1208+5)
%MM_OPUS1208_MIXER            = (%MM_MEDIAVISION_OPUS1208+6)
%MM_OPUS1208_AUX              = (%MM_MEDIAVISION_OPUS1208+7)

'// Opus MV 1216 chipset
%MM_MEDIAVISION_OPUS1216      = &H90
%MM_OPUS1216_MIDIOUT          = (%MM_MEDIAVISION_OPUS1216+1)
%MM_OPUS1216_MIDIIN           = (%MM_MEDIAVISION_OPUS1216+2)
%MM_OPUS1216_SYNTH            = (%MM_MEDIAVISION_OPUS1216+3)
%MM_OPUS1216_WAVEOUT          = (%MM_MEDIAVISION_OPUS1216+4)
%MM_OPUS1216_WAVEIN           = (%MM_MEDIAVISION_OPUS1216+5)
%MM_OPUS1216_MIXER            = (%MM_MEDIAVISION_OPUS1216+6)
%MM_OPUS1216_AUX              = (%MM_MEDIAVISION_OPUS1216+7)

'/* MM_CYRIX product IDs */
%MM_CYRIX_XASYNTH                  = 1
%MM_CYRIX_XAMIDIIN                 = 2
%MM_CYRIX_XAMIDIOUT                = 3
%MM_CYRIX_XAWAVEIN                 = 4
%MM_CYRIX_XAWAVEOUT                = 5
%MM_CYRIX_XAAUX                    = 6
%MM_CYRIX_XAMIXER                  = 7

'/* MM_PHILIPS_SPEECH_PROCESSING products IDs */
%MM_PHILIPS_ACM_LPCBB              = 1

'/* MM_NETXL product IDs */
%MM_NETXL_XLVIDEO                  = 1

'/* MM_ZYXEL product IDs */
%MM_ZYXEL_ACM_ADPCM                = 1

'/* MM_AARDVARK product IDs */
%MM_AARDVARK_STUDIO12_WAVEOUT      = 1
%MM_AARDVARK_STUDIO12_WAVEIN       = 2
%MM_AARDVARK_STUDIO88_WAVEOUT      = 3
%MM_AARDVARK_STUDIO88_WAVEIN       = 4

'/* MM_BINTEC product IDs */
%MM_BINTEC_TAPI_WAVE               = 1

'/* MM_HEWLETT_PACKARD product IDs */
%MM_HEWLETT_PACKARD_CU_CODEC       = 1

'/* MM_MITEL product IDs */
%MM_MITEL_TALKTO_LINE_WAVEOUT      = 100
%MM_MITEL_TALKTO_LINE_WAVEIN       = 101
%MM_MITEL_TALKTO_HANDSET_WAVEOUT   = 102
%MM_MITEL_TALKTO_HANDSET_WAVEIN    = 103
%MM_MITEL_TALKTO_BRIDGED_WAVEOUT   = 104
%MM_MITEL_TALKTO_BRIDGED_WAVEIN    = 105
%MM_MITEL_MPA_HANDSET_WAVEOUT      = 200
%MM_MITEL_MPA_HANDSET_WAVEIN       = 201
%MM_MITEL_MPA_HANDSFREE_WAVEOUT    = 202
%MM_MITEL_MPA_HANDSFREE_WAVEIN     = 203
%MM_MITEL_MPA_LINE1_WAVEOUT        = 204
%MM_MITEL_MPA_LINE1_WAVEIN         = 205
%MM_MITEL_MPA_LINE2_WAVEOUT        = 206
%MM_MITEL_MPA_LINE2_WAVEIN         = 207
%MM_MITEL_MEDIAPATH_WAVEOUT        = 300
%MM_MITEL_MEDIAPATH_WAVEIN         = 301

'/*  MM_SNI product IDs */
%MM_SNI_ACM_G721                   = 1

'/* MM_EMU product IDs */
%MM_EMU_APSSYNTH                   = 1
%MM_EMU_APSMIDIIN                  = 2
%MM_EMU_APSMIDIOUT                 = 3
%MM_EMU_APSWAVEIN                  = 4
%MM_EMU_APSWAVEOUT                 = 5

'/* MM_ARTISOFT product IDs */
%MM_ARTISOFT_SBWAVEIN  = 1   ' Artisoft sounding Board waveform input
%MM_ARTISOFT_SBWAVEOUT = 2   ' Artisoft sounding Board waveform output

'/* MM_TURTLE_BEACH product IDs */
%MM_TBS_TROPEZ_WAVEIN  = 37
%MM_TBS_TROPEZ_WAVEOUT = 38
%MM_TBS_TROPEZ_AUX1    = 39
%MM_TBS_TROPEZ_AUX2    = 40
%MM_TBS_TROPEZ_LINE    = 41

'/* MM_IBM product IDs */
%MM_MMOTION_WAVEAUX    = 1   ' IBM M-Motion Auxiliary Device
%MM_MMOTION_WAVEOUT    = 2   ' IBM M-Motion Waveform output
%MM_MMOTION_WAVEIN     = 3   ' IBM M-Motion  Waveform Input
%MM_IBM_PCMCIA_WAVEIN  = 11  ' IBM waveform input
%MM_IBM_PCMCIA_WAVEOUT = 12  ' IBM Waveform output
%MM_IBM_PCMCIA_SYNTH   = 13  ' IBM Midi Synthesis
%MM_IBM_PCMCIA_MIDIIN  = 14  ' IBM external MIDI in
%MM_IBM_PCMCIA_MIDIOUT = 15  ' IBM external MIDI out
%MM_IBM_PCMCIA_AUX     = 16  ' IBM auxiliary control
%MM_IBM_THINKPAD200    = 17
%MM_IBM_MWAVE_WAVEIN   = 18
%MM_IBM_MWAVE_WAVEOUT  = 19
%MM_IBM_MWAVE_MIXER    = 20
%MM_IBM_MWAVE_MIDIIN   = 21
%MM_IBM_MWAVE_MIDIOUT  = 22
%MM_IBM_MWAVE_AUX      = 23
%MM_IBM_WC_MIDIOUT     = 30
%MM_IBM_WC_WAVEOUT     = 31
%MM_IBM_WC_MIXEROUT    = 33

'/* MM_VOCALTEC product IDs */
%MM_VOCALTEC_WAVEOUT = 1
%MM_VOCALTEC_WAVEIN  = 2

'/* MM_ROLAND product IDs */
%MM_ROLAND_RAP10_MIDIOUT  = 10   ' MM_ROLAND_RAP10
%MM_ROLAND_RAP10_MIDIIN   = 11   ' MM_ROLAND_RAP10
%MM_ROLAND_RAP10_SYNTH    = 12   ' MM_ROLAND_RAP10
%MM_ROLAND_RAP10_WAVEOUT  = 13   ' MM_ROLAND_RAP10
%MM_ROLAND_RAP10_WAVEIN   = 14   ' MM_ROLAND_RAP10
%MM_ROLAND_MPU401_MIDIOUT = 15
%MM_ROLAND_MPU401_MIDIIN  = 16
%MM_ROLAND_SMPU_MIDIOUTA  = 17
%MM_ROLAND_SMPU_MIDIOUTB  = 18
%MM_ROLAND_SMPU_MIDIINA   = 19
%MM_ROLAND_SMPU_MIDIINB   = 20
%MM_ROLAND_SC7_MIDIOUT    = 21
%MM_ROLAND_SC7_MIDIIN     = 22
%MM_ROLAND_SERIAL_MIDIOUT = 23
%MM_ROLAND_SERIAL_MIDIIN  = 24
%MM_ROLAND_SCP_MIDIOUT    = 38
%MM_ROLAND_SCP_MIDIIN     = 39
%MM_ROLAND_SCP_WAVEOUT    = 40
%MM_ROLAND_SCP_WAVEIN     = 41
%MM_ROLAND_SCP_MIXER      = 42
%MM_ROLAND_SCP_AUX        = 48

'/* MM_DSP_SOLUTIONS product IDs */
%MM_DSP_SOLUTIONS_WAVEOUT = 1
%MM_DSP_SOLUTIONS_WAVEIN  = 2
%MM_DSP_SOLUTIONS_SYNTH   = 3
%MM_DSP_SOLUTIONS_AUX     = 4

'/* MM_NEC product IDs */
%MM_NEC_73_86_SYNTH    = 5
%MM_NEC_73_86_WAVEOUT  = 6
%MM_NEC_73_86_WAVEIN   = 7
%MM_NEC_26_SYNTH       = 9
%MM_NEC_MPU401_MIDIOUT = 10
%MM_NEC_MPU401_MIDIIN  = 11
%MM_NEC_JOYSTICK       = 12

'/* MM_WANGLABS product IDs */
%MM_WANGLABS_WAVEIN1  = 1       ' Input audio wave on CPU board models: Exec 4010, 4030, 3450; PC 251/25c, pc 461/25s , pc 461/33c
%MM_WANGLABS_WAVEOUT1 = 2

'/* MM_TANDY product IDs */
%MM_TANDY_VISWAVEIN       = 1
%MM_TANDY_VISWAVEOUT      = 2
%MM_TANDY_VISBIOSSYNTH    = 3
%MM_TANDY_SENS_MMAWAVEIN  = 4
%MM_TANDY_SENS_MMAWAVEOUT = 5
%MM_TANDY_SENS_MMAMIDIIN  = 6
%MM_TANDY_SENS_MMAMIDIOUT = 7
%MM_TANDY_SENS_VISWAVEOUT = 8
%MM_TANDY_PSSJWAVEIN      = 9
%MM_TANDY_PSSJWAVEOUT     = 10

'/* MM_ANTEX product IDs */
%MM_ANTEX_SX12_WAVEIN              = 1
%MM_ANTEX_SX12_WAVEOUT             = 2
%MM_ANTEX_SX15_WAVEIN              = 3
%MM_ANTEX_SX15_WAVEOUT             = 4
%MM_ANTEX_VP625_WAVEIN             = 5
%MM_ANTEX_VP625_WAVEOUT            = 6
%MM_ANTEX_AUDIOPORT22_WAVEIN       = 7
%MM_ANTEX_AUDIOPORT22_WAVEOUT      = 8
%MM_ANTEX_AUDIOPORT22_FEEDTHRU     = 9

'/* MM_INTEL product IDs */
%MM_INTELOPD_WAVEIN        = 1       ' HID2 WaveAudio Driver
%MM_INTELOPD_WAVEOUT      = 101     ' HID2
%MM_INTELOPD_AUX          = 401     ' HID2 for mixing
%MM_INTEL_NSPMODEMLINE    = 501
%MM_INTEL_NSPMODEMLINEOUT = 502

'/* MM_VAL product IDs */
%MM_VAL_MICROKEY_AP_WAVEIN  = 1
%MM_VAL_MICROKEY_AP_WAVEOUT = 2

'/* MM_INTERACTIVE product IDs */
%MM_INTERACTIVE_WAVEIN  = &H45
%MM_INTERACTIVE_WAVEOUT = &H45

'/* MM_YAMAHA product IDs */
%MM_YAMAHA_GSS_SYNTH         = &H01
%MM_YAMAHA_GSS_WAVEOUT       = &H02
%MM_YAMAHA_GSS_WAVEIN        = &H03
%MM_YAMAHA_GSS_MIDIOUT       = &H04
%MM_YAMAHA_GSS_MIDIIN        = &H05
%MM_YAMAHA_GSS_AUX           = &H06
%MM_YAMAHA_SERIAL_MIDIOUT    = &H07
%MM_YAMAHA_SERIAL_MIDIIN     = &H08
%MM_YAMAHA_OPL3SA_WAVEOUT    = &H10
%MM_YAMAHA_OPL3SA_WAVEIN     = &H11
%MM_YAMAHA_OPL3SA_FMSYNTH    = &H12
%MM_YAMAHA_OPL3SA_YSYNTH     = &H13
%MM_YAMAHA_OPL3SA_MIDIOUT    = &H14
%MM_YAMAHA_OPL3SA_MIDIIN     = &H15
%MM_YAMAHA_OPL3SA_MIXER      = &H17
%MM_YAMAHA_OPL3SA_JOYSTICK   = &H18
%MM_YAMAHA_YMF724LEG_MIDIOUT = &H19
%MM_YAMAHA_YMF724LEG_MIDIIN  = &H1a
%MM_YAMAHA_YMF724_WAVEOUT    = &H1b
%MM_YAMAHA_YMF724_WAVEIN     = &H1c
%MM_YAMAHA_YMF724_MIDIOUT    = &H1d
%MM_YAMAHA_YMF724_AUX        = &H1e
%MM_YAMAHA_YMF724_MIXER      = &H1f
%MM_YAMAHA_YMF724LEG_FMSYNTH = &H20
%MM_YAMAHA_YMF724LEG_MIXER   = &H21
%MM_YAMAHA_SXG_MIDIOUT       = &H22
%MM_YAMAHA_SXG_WAVEOUT       = &H23
%MM_YAMAHA_SXG_MIXER         = &H24
%MM_YAMAHA_ACXG_WAVEIN       = &H25
%MM_YAMAHA_ACXG_WAVEOUT      = &H26
%MM_YAMAHA_ACXG_MIDIOUT      = &H27
%MM_YAMAHA_ACXG_MIXER        = &H28
%MM_YAMAHA_ACXG_AUX          = &H29

'/* MM_EVEREX product IDs */
%MM_EVEREX_CARRIER = 1

'/* MM_ECHO product IDs */
%MM_ECHO_SYNTH   = 1
%MM_ECHO_WAVEOUT = 2
%MM_ECHO_WAVEIN  = 3
%MM_ECHO_MIDIOUT = 4
%MM_ECHO_MIDIIN  = 5
%MM_ECHO_AUX     = 6

'/* MM_SIERRA product IDs */
%MM_SIERRA_ARIA_MIDIOUT      = &H14
%MM_SIERRA_ARIA_MIDIIN       = &H15
%MM_SIERRA_ARIA_SYNTH        = &H16
%MM_SIERRA_ARIA_WAVEOUT      = &H17
%MM_SIERRA_ARIA_WAVEIN       = &H18
%MM_SIERRA_ARIA_AUX          = &H19
%MM_SIERRA_ARIA_AUX2         = &H20
%MM_SIERRA_QUARTET_WAVEIN    = &H50
%MM_SIERRA_QUARTET_WAVEOUT   = &H51
%MM_SIERRA_QUARTET_MIDIIN    = &H52
%MM_SIERRA_QUARTET_MIDIOUT   = &H53
%MM_SIERRA_QUARTET_SYNTH     = &H54
%MM_SIERRA_QUARTET_AUX_CD    = &H55
%MM_SIERRA_QUARTET_AUX_LINE  = &H56
%MM_SIERRA_QUARTET_AUX_MODEM = &H57
%MM_SIERRA_QUARTET_MIXER     = &H58

'/* MM_CAT product IDs */
%MM_CAT_WAVEOUT = 1

'/* MM_DSP_GROUP product IDs */
%MM_DSP_GROUP_TRUESPEECH = 1

'/* MM_MELABS product IDs */
%MM_MELABS_MIDI2GO = 1

'/* MM_ESS product IDs */
%MM_ESS_AMWAVEOUT       = &H01
%MM_ESS_AMWAVEIN        = &H02
%MM_ESS_AMAUX           = &H03
%MM_ESS_AMSYNTH         = &H04
%MM_ESS_AMMIDIOUT       = &H05
%MM_ESS_AMMIDIIN        = &H06
%MM_ESS_MIXER           = &H07
%MM_ESS_AUX_CD          = &H08
%MM_ESS_MPU401_MIDIOUT  = &H09
%MM_ESS_MPU401_MIDIIN   = &H0A
%MM_ESS_ES488_WAVEOUT   = &H10
%MM_ESS_ES488_WAVEIN    = &H11
%MM_ESS_ES488_MIXER     = &H12
%MM_ESS_ES688_WAVEOUT   = &H13
%MM_ESS_ES688_WAVEIN    = &H14
%MM_ESS_ES688_MIXER     = &H15
%MM_ESS_ES1488_WAVEOUT  = &H16
%MM_ESS_ES1488_WAVEIN   = &H17
%MM_ESS_ES1488_MIXER    = &H18
%MM_ESS_ES1688_WAVEOUT  = &H19
%MM_ESS_ES1688_WAVEIN   = &H1A
%MM_ESS_ES1688_MIXER    = &H1B
%MM_ESS_ES1788_WAVEOUT  = &H1C
%MM_ESS_ES1788_WAVEIN   = &H1D
%MM_ESS_ES1788_MIXER    = &H1E
%MM_ESS_ES1888_WAVEOUT  = &H1F
%MM_ESS_ES1888_WAVEIN   = &H20
%MM_ESS_ES1888_MIXER    = &H21
%MM_ESS_ES1868_WAVEOUT  = &H22
%MM_ESS_ES1868_WAVEIN   = &H23
%MM_ESS_ES1868_MIXER    = &H24
%MM_ESS_ES1878_WAVEOUT  = &H25
%MM_ESS_ES1878_WAVEIN   = &H26
%MM_ESS_ES1878_MIXER    = &H27

'/* MM_CANOPUS product IDs */
%MM_CANOPUS_ACM_DVREX   = 1

'/* MM_EPSON product IDs */
%MM_EPS_FMSND           = 1

'/* MM_TRUEVISION product IDs */
%MM_TRUEVISION_WAVEIN1  = 1
%MM_TRUEVISION_WAVEOUT1 = 2

'/* MM_AZTECH product IDs */
%MM_AZTECH_MIDIOUT          = 3
%MM_AZTECH_MIDIIN           = 4
%MM_AZTECH_WAVEIN           = 17
%MM_AZTECH_WAVEOUT          = 18
%MM_AZTECH_FMSYNTH          = 20
%MM_AZTECH_MIXER            = 21
%MM_AZTECH_PRO16_WAVEIN     = 33
%MM_AZTECH_PRO16_WAVEOUT    = 34
%MM_AZTECH_PRO16_FMSYNTH    = 38
%MM_AZTECH_DSP16_WAVEIN     = 65
%MM_AZTECH_DSP16_WAVEOUT    = 66
%MM_AZTECH_DSP16_FMSYNTH    = 68
%MM_AZTECH_DSP16_WAVESYNTH  = 70
%MM_AZTECH_NOVA16_WAVEIN    = 71
%MM_AZTECH_NOVA16_WAVEOUT   = 72
%MM_AZTECH_NOVA16_MIXER     = 73
%MM_AZTECH_WASH16_WAVEIN    = 74
%MM_AZTECH_WASH16_WAVEOUT   = 75
%MM_AZTECH_WASH16_MIXER     = 76
%MM_AZTECH_AUX_CD           = 401
%MM_AZTECH_AUX_LINE         = 402
%MM_AZTECH_AUX_MIC          = 403
%MM_AZTECH_AUX              = 404

'/* MM_VIDEOLOGIC product IDs */
%MM_VIDEOLOGIC_MSWAVEIN  = 1
%MM_VIDEOLOGIC_MSWAVEOUT = 2

'/* MM_KORG product IDs */
%MM_KORG_PCIF_MIDIOUT     = 1
%MM_KORG_PCIF_MIDIIN      = 2
%MM_KORG_1212IO_MSWAVEIN  = 3
%MM_KORG_1212IO_MSWAVEOUT = 4

'/* MM_APT product IDs */
%MM_APT_ACE100CD = 1

'/* MM_ICS product IDs */
%MM_ICS_WAVEDECK_WAVEOUT           = 1     ' MS WSS compatible card and driver
%MM_ICS_WAVEDECK_WAVEIN            = 2
%MM_ICS_WAVEDECK_MIXER             = 3
%MM_ICS_WAVEDECK_AUX               = 4
%MM_ICS_WAVEDECK_SYNTH             = 5
%MM_ICS_WAVEDEC_SB_WAVEOUT         = 6
%MM_ICS_WAVEDEC_SB_WAVEIN          = 7
%MM_ICS_WAVEDEC_SB_FM_MIDIOUT      = 8
%MM_ICS_WAVEDEC_SB_MPU401_MIDIOUT  = 9
%MM_ICS_WAVEDEC_SB_MPU401_MIDIIN   = 10
%MM_ICS_WAVEDEC_SB_MIXER           = 11
%MM_ICS_WAVEDEC_SB_AUX             = 12
%MM_ICS_2115_LITE_MIDIOUT          = 13
%MM_ICS_2120_LITE_MIDIOUT          = 14

'/* MM_ITERATEDSYS product IDs */
%MM_ITERATEDSYS_FUFCODEC = 1

'/* MM_METHEUS product IDs */
%MM_METHEUS_ZIPPER = 1

'/* MM_WINNOV product IDs */
%MM_WINNOV_CAVIAR_WAVEIN    = 1
%MM_WINNOV_CAVIAR_WAVEOUT   = 2
%MM_WINNOV_CAVIAR_VIDC      = 3
%MM_WINNOV_CAVIAR_CHAMPAGNE = 4       ' Fourcc is CHAM
%MM_WINNOV_CAVIAR_YUV8      = 5       ' Fourcc is YUV8

'/* MM_NCR product IDs */
%MM_NCR_BA_WAVEIN  = 1
%MM_NCR_BA_WAVEOUT = 2
%MM_NCR_BA_SYNTH   = 3
%MM_NCR_BA_AUX     = 4
%MM_NCR_BA_MIXER   = 5

'/* MM_AST product IDs */
%MM_AST_MODEMWAVE_WAVEIN  = 13
%MM_AST_MODEMWAVE_WAVEOUT = 14

'/* MM_WILLOWPOND product IDs */
%MM_WILLOWPOND_FMSYNTH_STEREO  = 20
%MM_WILLOWPOND_SNDPORT_WAVEIN  = 100
%MM_WILLOWPOND_SNDPORT_WAVEOUT = 101
%MM_WILLOWPOND_SNDPORT_MIXER   = 102
%MM_WILLOWPOND_SNDPORT_AUX     = 103
%MM_WILLOWPOND_PH_WAVEIN       = 104
%MM_WILLOWPOND_PH_WAVEOUT      = 105
%MM_WILLOWPOND_PH_MIXER        = 106
%MM_WILLOWPOND_PH_AUX          = 107
%MM_WILLOPOND_SNDCOMM_WAVEIN   = 108
%MM_WILLOWPOND_SNDCOMM_WAVEOUT = 109
%MM_WILLOWPOND_SNDCOMM_MIXER   = 110
%MM_WILLOWPOND_SNDCOMM_AUX     = 111
%MM_WILLOWPOND_GENERIC_WAVEIN  = 112
%MM_WILLOWPOND_GENERIC_WAVEOUT = 113
%MM_WILLOWPOND_GENERIC_MIXER   = 114
%MM_WILLOWPOND_GENERIC_AUX     = 115

'/* MM_VITEC product IDs */
%MM_VITEC_VMAKER = 1
%MM_VITEC_VMPRO  = 2

'/* MM_MOSCOM product IDs */
%MM_MOSCOM_VPC2400_IN  = 1   ' Four Port Voice Processing / Voice Recognition Board
%MM_MOSCOM_VPC2400_OUT = 2   ' VPC2400

'/* MM_SILICONSOFT product IDs */
%MM_SILICONSOFT_SC1_WAVEIN         = 1   ' Waveform in , high sample rate
%MM_SILICONSOFT_SC1_WAVEOUT        = 2   ' Waveform out , high sample rate
%MM_SILICONSOFT_SC2_WAVEIN         = 3   ' Waveform in 2 channels, high sample rate
%MM_SILICONSOFT_SC2_WAVEOUT        = 4   ' Waveform out 2 channels, high sample rate
%MM_SILICONSOFT_SOUNDJR2_WAVEOUT   = 5   ' Waveform out, self powered, efficient
%MM_SILICONSOFT_SOUNDJR2PR_WAVEIN  = 6   ' Waveform in, self powered, efficient
%MM_SILICONSOFT_SOUNDJR2PR_WAVEOUT = 7   ' Waveform out 2 channels, self powered, efficient
%MM_SILICONSOFT_SOUNDJR3_WAVEOUT   = 8   ' Waveform in 2 channels, self powered, efficient

'/* MM_TERRATEC product IDs */
%MM_TTEWS_WAVEIN                   = 1
%MM_TTEWS_WAVEOUT                  = 2
%MM_TTEWS_MIDIIN                   = 3
%MM_TTEWS_MIDIOUT                  = 4
%MM_TTEWS_MIDISYNTH                = 5
%MM_TTEWS_MIDIMONITOR              = 6
%MM_TTEWS_VMIDIIN                  = 7
%MM_TTEWS_VMIDIOUT                 = 8
%MM_TTEWS_AUX                      = 9
%MM_TTEWS_MIXER                    = 10

'/* MM_MEDIASONIC product IDs */
%MM_MEDIASONIC_ACM_G723            = 1
%MM_MEDIASONIC_ICOM                = 2
%MM_ICOM_WAVEIN                    = 3
%MM_ICOM_WAVEOUT                   = 4
%MM_ICOM_MIXER                     = 5
%MM_ICOM_AUX                       = 6
%MM_ICOM_LINE                      = 7

'/*  MM_SANYO product IDs */
%MM_SANYO_ACM_LD_ADPCM             = 1

'/* MM_AHEAD product IDs */
%MM_AHEAD_MULTISOUND   = 1
%MM_AHEAD_SOUNDBLASTER = 2
%MM_AHEAD_PROAUDIO     = 3
%MM_AHEAD_GENERIC      = 4

'/* MM_OLIVETTI product IDs */
%MM_OLIVETTI_WAVEIN     = 1
%MM_OLIVETTI_WAVEOUT    = 2
%MM_OLIVETTI_MIXER      = 3
%MM_OLIVETTI_AUX        = 4
%MM_OLIVETTI_MIDIIN     = 5
%MM_OLIVETTI_MIDIOUT    = 6
%MM_OLIVETTI_SYNTH      = 7
%MM_OLIVETTI_JOYSTICK   = 8
%MM_OLIVETTI_ACM_GSM    = 9
%MM_OLIVETTI_ACM_ADPCM  = 10
%MM_OLIVETTI_ACM_CELP   = 11
%MM_OLIVETTI_ACM_SBC    = 12
%MM_OLIVETTI_ACM_OPR    = 13

'/* MM_IOMAGIC product IDs */
%MM_IOMAGIC_TEMPO_WAVEOUT = 1
%MM_IOMAGIC_TEMPO_WAVEIN  = 2
%MM_IOMAGIC_TEMPO_SYNTH   = 3
%MM_IOMAGIC_TEMPO_MIDIOUT = 4
%MM_IOMAGIC_TEMPO_MXDOUT  = 5
%MM_IOMAGIC_TEMPO_AUXOUT  = 6

'/* MM_MATSUSHITA product IDs */
%MM_MATSUSHITA_WAVEIN         = 1
%MM_MATSUSHITA_WAVEOUT        = 2
%MM_MATSUSHITA_FMSYNTH_STEREO = 3
%MM_MATSUSHITA_MIXER          = 4
%MM_MATSUSHITA_AUX            = 5

'/* MM_NEWMEDIA product IDs */
%MM_NEWMEDIA_WAVJAMMER = 1       ' WSS Compatible sound card.

'/* MM_LYRRUS product IDs */
%MM_LYRRUS_BRIDGE_GUITAR = 1

'/* MM_OPTI product IDs */
%MM_OPTI_M16_FMSYNTH_STEREO = &H0001
%MM_OPTI_M16_MIDIIN         = &H0002
%MM_OPTI_M16_MIDIOUT        = &H0003
%MM_OPTI_M16_WAVEIN         = &H0004
%MM_OPTI_M16_WAVEOUT        = &H0005
%MM_OPTI_M16_MIXER          = &H0006
%MM_OPTI_M16_AUX            = &H0007
%MM_OPTI_P16_FMSYNTH_STEREO = &H0010
%MM_OPTI_P16_MIDIIN         = &H0011
%MM_OPTI_P16_MIDIOUT        = &H0012
%MM_OPTI_P16_WAVEIN         = &H0013
%MM_OPTI_P16_WAVEOUT        = &H0014
%MM_OPTI_P16_MIXER          = &H0015
%MM_OPTI_P16_AUX            = &H0016
%MM_OPTI_M32_WAVEIN         = &H0020
%MM_OPTI_M32_WAVEOUT        = &H0021
%MM_OPTI_M32_MIDIIN         = &H0022
%MM_OPTI_M32_MIDIOUT        = &H0023
%MM_OPTI_M32_SYNTH_STEREO   = &H0024
%MM_OPTI_M32_MIXER          = &H0025
%MM_OPTI_M32_AUX            = &H0026

'/* MM_COMPAQ product IDs */
%MM_COMPAQ_BB_WAVEIN  = 1
%MM_COMPAQ_BB_WAVEOUT = 2
%MM_COMPAQ_BB_WAVEAUX = 3

'/* MM_MPTUS product IDs */
%MM_MPTUS_SPWAVEOUT = 1       ' Sound Pallette

'/* MM_LERNOUT_AND_HAUSPIE product IDs */
%MM_LERNOUT_ANDHAUSPIE_LHCODECACM  = 1

'/* MM_DIGITAL product IDs */
%MM_DIGITAL_AV320_WAVEIN           = 1      ' /* Digital Audio Video Compression Board */
%MM_DIGITAL_AV320_WAVEOUT          = 2      ' /* Digital Audio Video Compression Board */
%MM_DIGITAL_ACM_G723               = 3
%MM_DIGITAL_ICM_H263               = 4
%MM_DIGITAL_ICM_H261               = 5

'/* MM_MOTU product IDs */
%MM_MOTU_MTP_MIDIOUT_ALL        = 100
%MM_MOTU_MTP_MIDIIN_1           = 101
%MM_MOTU_MTP_MIDIOUT_1          = 101
%MM_MOTU_MTP_MIDIIN_2           = 102
%MM_MOTU_MTP_MIDIOUT_2          = 102
%MM_MOTU_MTP_MIDIIN_3           = 103
%MM_MOTU_MTP_MIDIOUT_3          = 103
%MM_MOTU_MTP_MIDIIN_4           = 104
%MM_MOTU_MTP_MIDIOUT_4          = 104
%MM_MOTU_MTP_MIDIIN_5           = 105
%MM_MOTU_MTP_MIDIOUT_5          = 105
%MM_MOTU_MTP_MIDIIN_6           = 106
%MM_MOTU_MTP_MIDIOUT_6          = 106
%MM_MOTU_MTP_MIDIIN_7           = 107
%MM_MOTU_MTP_MIDIOUT_7          = 107
%MM_MOTU_MTP_MIDIIN_8           = 108
%MM_MOTU_MTP_MIDIOUT_8          = 108

%MM_MOTU_MTPII_MIDIOUT_ALL      = 200
%MM_MOTU_MTPII_MIDIIN_SYNC      = 200
%MM_MOTU_MTPII_MIDIIN_1         = 201
%MM_MOTU_MTPII_MIDIOUT_1        = 201
%MM_MOTU_MTPII_MIDIIN_2         = 202
%MM_MOTU_MTPII_MIDIOUT_2        = 202
%MM_MOTU_MTPII_MIDIIN_3         = 203
%MM_MOTU_MTPII_MIDIOUT_3        = 203
%MM_MOTU_MTPII_MIDIIN_4         = 204
%MM_MOTU_MTPII_MIDIOUT_4        = 204
%MM_MOTU_MTPII_MIDIIN_5         = 205
%MM_MOTU_MTPII_MIDIOUT_5        = 205
%MM_MOTU_MTPII_MIDIIN_6         = 206
%MM_MOTU_MTPII_MIDIOUT_6        = 206
%MM_MOTU_MTPII_MIDIIN_7         = 207
%MM_MOTU_MTPII_MIDIOUT_7        = 207
%MM_MOTU_MTPII_MIDIIN_8         = 208
%MM_MOTU_MTPII_MIDIOUT_8        = 208
%MM_MOTU_MTPII_NET_MIDIIN_1     = 209
%MM_MOTU_MTPII_NET_MIDIOUT_1    = 209
%MM_MOTU_MTPII_NET_MIDIIN_2     = 210
%MM_MOTU_MTPII_NET_MIDIOUT_2    = 210
%MM_MOTU_MTPII_NET_MIDIIN_3     = 211
%MM_MOTU_MTPII_NET_MIDIOUT_3    = 211
%MM_MOTU_MTPII_NET_MIDIIN_4     = 212
%MM_MOTU_MTPII_NET_MIDIOUT_4    = 212
%MM_MOTU_MTPII_NET_MIDIIN_5     = 213
%MM_MOTU_MTPII_NET_MIDIOUT_5    = 213
%MM_MOTU_MTPII_NET_MIDIIN_6     = 214
%MM_MOTU_MTPII_NET_MIDIOUT_6    = 214
%MM_MOTU_MTPII_NET_MIDIIN_7     = 215
%MM_MOTU_MTPII_NET_MIDIOUT_7    = 215
%MM_MOTU_MTPII_NET_MIDIIN_8     = 216
%MM_MOTU_MTPII_NET_MIDIOUT_8    = 216

%MM_MOTU_MXP_MIDIIN_MIDIOUT_ALL = 300
%MM_MOTU_MXP_MIDIIN_SYNC        = 300
%MM_MOTU_MXP_MIDIIN_MIDIIN_1    = 301
%MM_MOTU_MXP_MIDIIN_MIDIOUT_1   = 301
%MM_MOTU_MXP_MIDIIN_MIDIIN_2    = 302
%MM_MOTU_MXP_MIDIIN_MIDIOUT_2   = 302
%MM_MOTU_MXP_MIDIIN_MIDIIN_3    = 303
%MM_MOTU_MXP_MIDIIN_MIDIOUT_3   = 303
%MM_MOTU_MXP_MIDIIN_MIDIIN_4    = 304
%MM_MOTU_MXP_MIDIIN_MIDIOUT_4   = 304
%MM_MOTU_MXP_MIDIIN_MIDIIN_5    = 305
%MM_MOTU_MXP_MIDIIN_MIDIOUT_5   = 305
%MM_MOTU_MXP_MIDIIN_MIDIIN_6    = 306
%MM_MOTU_MXP_MIDIIN_MIDIOUT_6   = 306

%MM_MOTU_MXPMPU_MIDIOUT_ALL     = 400
%MM_MOTU_MXPMPU_MIDIIN_SYNC     = 400
%MM_MOTU_MXPMPU_MIDIIN_1        = 401
%MM_MOTU_MXPMPU_MIDIOUT_1       = 401
%MM_MOTU_MXPMPU_MIDIIN_2        = 402
%MM_MOTU_MXPMPU_MIDIOUT_2       = 402
%MM_MOTU_MXPMPU_MIDIIN_3        = 403
%MM_MOTU_MXPMPU_MIDIOUT_3       = 403
%MM_MOTU_MXPMPU_MIDIIN_4        = 404
%MM_MOTU_MXPMPU_MIDIOUT_4       = 404
%MM_MOTU_MXPMPU_MIDIIN_5        = 405
%MM_MOTU_MXPMPU_MIDIOUT_5       = 405
%MM_MOTU_MXPMPU_MIDIIN_6        = 406
%MM_MOTU_MXPMPU_MIDIOUT_6       = 406

%MM_MOTU_MXN_MIDIOUT_ALL        = 500
%MM_MOTU_MXN_MIDIIN_SYNC        = 500
%MM_MOTU_MXN_MIDIIN_1           = 501
%MM_MOTU_MXN_MIDIOUT_1          = 501
%MM_MOTU_MXN_MIDIIN_2           = 502
%MM_MOTU_MXN_MIDIOUT_2          = 502
%MM_MOTU_MXN_MIDIIN_3           = 503
%MM_MOTU_MXN_MIDIOUT_3          = 503
%MM_MOTU_MXN_MIDIIN_4           = 504
%MM_MOTU_MXN_MIDIOUT_4          = 504

%MM_MOTU_FLYER_MIDI_IN_SYNC     = 600
%MM_MOTU_FLYER_MIDI_IN_A        = 601
%MM_MOTU_FLYER_MIDI_OUT_A       = 601
%MM_MOTU_FLYER_MIDI_IN_B        = 602
%MM_MOTU_FLYER_MIDI_OUT_B       = 602

%MM_MOTU_PKX_MIDI_IN_SYNC       = 700
%MM_MOTU_PKX_MIDI_IN_A          = 701
%MM_MOTU_PKX_MIDI_OUT_A         = 701
%MM_MOTU_PKX_MIDI_IN_B          = 702
%MM_MOTU_PKX_MIDI_OUT_B         = 702

%MM_MOTU_DTX_MIDI_IN_SYNC       = 800
%MM_MOTU_DTX_MIDI_IN_A          = 801
%MM_MOTU_DTX_MIDI_OUT_A         = 801
%MM_MOTU_DTX_MIDI_IN_B          = 802
%MM_MOTU_DTX_MIDI_OUT_B         = 802

%MM_MOTU_MTPAV_MIDIOUT_ALL   = 900
%MM_MOTU_MTPAV_MIDIIN_SYNC   = 900
%MM_MOTU_MTPAV_MIDIIN_1      = 901
%MM_MOTU_MTPAV_MIDIOUT_1     = 901
%MM_MOTU_MTPAV_MIDIIN_2      = 902
%MM_MOTU_MTPAV_MIDIOUT_2     = 902
%MM_MOTU_MTPAV_MIDIIN_3      = 903
%MM_MOTU_MTPAV_MIDIOUT_3     = 903
%MM_MOTU_MTPAV_MIDIIN_4      = 904
%MM_MOTU_MTPAV_MIDIOUT_4     = 904
%MM_MOTU_MTPAV_MIDIIN_5      = 905
%MM_MOTU_MTPAV_MIDIOUT_5     = 905
%MM_MOTU_MTPAV_MIDIIN_6      = 906
%MM_MOTU_MTPAV_MIDIOUT_6     = 906
%MM_MOTU_MTPAV_MIDIIN_7      = 907
%MM_MOTU_MTPAV_MIDIOUT_7     = 907
%MM_MOTU_MTPAV_MIDIIN_8      = 908
%MM_MOTU_MTPAV_MIDIOUT_8     = 908
%MM_MOTU_MTPAV_NET_MIDIIN_1  = 909
%MM_MOTU_MTPAV_NET_MIDIOUT_1 = 909
%MM_MOTU_MTPAV_NET_MIDIIN_2  = 910
%MM_MOTU_MTPAV_NET_MIDIOUT_2 = 910
%MM_MOTU_MTPAV_NET_MIDIIN_3  = 911
%MM_MOTU_MTPAV_NET_MIDIOUT_3 = 911
%MM_MOTU_MTPAV_NET_MIDIIN_4  = 912
%MM_MOTU_MTPAV_NET_MIDIOUT_4 = 912
%MM_MOTU_MTPAV_NET_MIDIIN_5  = 913
%MM_MOTU_MTPAV_NET_MIDIOUT_5 = 913
%MM_MOTU_MTPAV_NET_MIDIIN_6  = 914
%MM_MOTU_MTPAV_NET_MIDIOUT_6 = 914
%MM_MOTU_MTPAV_NET_MIDIIN_7  = 915
%MM_MOTU_MTPAV_NET_MIDIOUT_7 = 915
%MM_MOTU_MTPAV_NET_MIDIIN_8  = 916
%MM_MOTU_MTPAV_NET_MIDIOUT_8 = 916
%MM_MOTU_MTPAV_MIDIIN_ADAT   = 917
%MM_MOTU_MTPAV_MIDIOUT_ADAT  = 917
%MM_MOTU_MXPXT_MIDIIN_SYNC   = 1000
%MM_MOTU_MXPXT_MIDIOUT_ALL   = 1000
%MM_MOTU_MXPXT_MIDIIN_1      = 1001
%MM_MOTU_MXPXT_MIDIOUT_1     = 1001
%MM_MOTU_MXPXT_MIDIOUT_2     = 1002
%MM_MOTU_MXPXT_MIDIIN_2      = 1002
%MM_MOTU_MXPXT_MIDIIN_3      = 1003
%MM_MOTU_MXPXT_MIDIOUT_3     = 1003
%MM_MOTU_MXPXT_MIDIIN_4      = 1004
%MM_MOTU_MXPXT_MIDIOUT_4     = 1004
%MM_MOTU_MXPXT_MIDIIN_5      = 1005
%MM_MOTU_MXPXT_MIDIOUT_5     = 1005
%MM_MOTU_MXPXT_MIDIOUT_6     = 1006
%MM_MOTU_MXPXT_MIDIIN_6      = 1006
%MM_MOTU_MXPXT_MIDIOUT_7     = 1007
%MM_MOTU_MXPXT_MIDIIN_7      = 1007
%MM_MOTU_MXPXT_MIDIOUT_8     = 1008
%MM_MOTU_MXPXT_MIDIIN_8      = 1008

'/* MM_WORKBIT product IDs */
%MM_WORKBIT_MIXER    = 1      ' Harmony Mixer
%MM_WORKBIT_WAVEOUT  = 2      ' Harmony Mixer
%MM_WORKBIT_WAVEIN   = 3      ' Harmony Mixer
%MM_WORKBIT_MIDIIN   = 4      ' Harmony Mixer
%MM_WORKBIT_MIDIOUT  = 5      ' Harmony Mixer
%MM_WORKBIT_FMSYNTH  = 6      ' Harmony Mixer
%MM_WORKBIT_AUX      = 7      ' Harmony Mixer
%MM_WORKBIT_JOYSTICK = 8

'/* MM_OSITECH product IDs */
%MM_OSITECH_TRUMPCARD = 1       ' Trumpcard

'/* MM_MIRO product IDs */
%MM_MIRO_MOVIEPRO     = 1       ' miroMOVIE pro
%MM_MIRO_VIDEOD1      = 2       ' miroVIDEO D1
%MM_MIRO_VIDEODC1TV   = 3       ' miroVIDEO DC1 tv
%MM_MIRO_VIDEOTD      = 4       ' miroVIDEO 10/20 TD
%MM_MIRO_DC30_WAVEOUT = 5
%MM_MIRO_DC30_WAVEIN  = 6
%MM_MIRO_DC30_MIX     = 7

'/* MM_ISOLUTION product IDs */
%MM_ISOLUTION_PASCAL               = 1

'/* MM_ROCKWELL product IDs */
%MM_VOICEMIXER           = 1
%ROCKWELL_WA1_WAVEIN     = 100
%ROCKWELL_WA1_WAVEOUT    = 101
%ROCKWELL_WA1_SYNTH      = 102
%ROCKWELL_WA1_MIXER      = 103
%ROCKWELL_WA1_MPU401_IN  = 104
%ROCKWELL_WA1_MPU401_OUT = 105
%ROCKWELL_WA2_WAVEIN     = 200
%ROCKWELL_WA2_WAVEOUT    = 201
%ROCKWELL_WA2_SYNTH      = 202
%ROCKWELL_WA2_MIXER      = 203
%ROCKWELL_WA2_MPU401_IN  = 204
%ROCKWELL_WA2_MPU401_OUT = 205

'/* MM_VOXWARE product IDs */
%MM_VOXWARE_CODEC        = 1

'/* MM_NORTHERN_TELECOM product IDs */
%MM_NORTEL_MPXAC_WAVEIN  = 1       ' MPX Audio Card Wave Input Device
%MM_NORTEL_MPXAC_WAVEOUT = 2       ' MPX Audio Card Wave Output Device

'/* MM_ADDX product IDs */
%MM_ADDX_PCTV_DIGITALMIX = 1       ' MM_ADDX_PCTV_DIGITALMIX
%MM_ADDX_PCTV_WAVEIN     = 2       ' MM_ADDX_PCTV_WAVEIN
%MM_ADDX_PCTV_WAVEOUT    = 3       ' MM_ADDX_PCTV_WAVEOUT
%MM_ADDX_PCTV_MIXER      = 4       ' MM_ADDX_PCTV_MIXER
%MM_ADDX_PCTV_AUX_CD     = 5       ' MM_ADDX_PCTV_AUX_CD
%MM_ADDX_PCTV_AUX_LINE   = 6       ' MM_ADDX_PCTV_AUX_LINE

'/* MM_WILDCAT product IDs */
%MM_WILDCAT_AUTOSCOREMIDIIN = 1       ' Autoscore

'/* MM_RHETOREX product IDs */
%MM_RHETOREX_WAVEIN  = 1
%MM_RHETOREX_WAVEOUT = 2

'/* MM_BROOKTREE product IDs */
%MM_BTV_WAVEIN          = 1       ' Brooktree PCM Wave Audio In
%MM_BTV_WAVEOUT         = 2       ' Brooktree PCM Wave Audio Out
%MM_BTV_MIDIIN          = 3       ' Brooktree MIDI In
%MM_BTV_MIDIOUT         = 4       ' Brooktree MIDI out
%MM_BTV_MIDISYNTH       = 5       ' Brooktree MIDI FM synth
%MM_BTV_AUX_LINE        = 6       ' Brooktree Line Input
%MM_BTV_AUX_MIC         = 7       ' Brooktree Microphone Input
%MM_BTV_AUX_CD          = 8       ' Brooktree CD Input
%MM_BTV_DIGITALIN       = 9       ' Brooktree PCM Wave in with subcode information
%MM_BTV_DIGITALOUT      = 10      ' Brooktree PCM Wave out with subcode information
%MM_BTV_MIDIWAVESTREAM  = 11      ' Brooktree WaveStream
%MM_BTV_MIXER           = 12      ' Brooktree WSS Mixer driver

'/* MM_ENSONIQ product IDs */
%MM_ENSONIQ_SOUNDSCAPE             = &H10  ' /* ENSONIQ Soundscape */
%MM_SOUNDSCAPE_WAVEOUT             = %MM_ENSONIQ_SOUNDSCAPE+1
%MM_SOUNDSCAPE_WAVEOUT_AUX         = %MM_ENSONIQ_SOUNDSCAPE+2
%MM_SOUNDSCAPE_WAVEIN              = %MM_ENSONIQ_SOUNDSCAPE+3
%MM_SOUNDSCAPE_MIDIOUT             = %MM_ENSONIQ_SOUNDSCAPE+4
%MM_SOUNDSCAPE_MIDIIN              = %MM_ENSONIQ_SOUNDSCAPE+5
%MM_SOUNDSCAPE_SYNTH               = %MM_ENSONIQ_SOUNDSCAPE+6
%MM_SOUNDSCAPE_MIXER               = %MM_ENSONIQ_SOUNDSCAPE+7
%MM_SOUNDSCAPE_AUX                 = %MM_ENSONIQ_SOUNDSCAPE+8

'/* MM_NVIDIA product IDs */
%MM_NVIDIA_WAVEOUT  = 1
%MM_NVIDIA_WAVEIN   = 2
%MM_NVIDIA_MIDIOUT  = 3
%MM_NVIDIA_MIDIIN   = 4
%MM_NVIDIA_GAMEPORT = 5
%MM_NVIDIA_MIXER    = 6
%MM_NVIDIA_AUX      = 7

'/* MM_OKSORI product IDs */
%MM_OKSORI_BASE           = 0                   ' Oksori Base
%MM_OKSORI_OSR8_WAVEOUT   = %MM_OKSORI_BASE+1   ' Oksori 8bit Wave out
%MM_OKSORI_OSR8_WAVEIN    = %MM_OKSORI_BASE+2   ' Oksori 8bit Wave in
%MM_OKSORI_OSR16_WAVEOUT  = %MM_OKSORI_BASE+3   ' Oksori 16 bit Wave out
%MM_OKSORI_OSR16_WAVEIN   = %MM_OKSORI_BASE+4   ' Oksori 16 bit Wave in
%MM_OKSORI_FM_OPL4        = %MM_OKSORI_BASE+5   ' Oksori FM Synth Yamaha OPL4
%MM_OKSORI_MIX_MASTER     = %MM_OKSORI_BASE+6   ' Oksori DSP Mixer - Master Volume
%MM_OKSORI_MIX_WAVE       = %MM_OKSORI_BASE+7   ' Oksori DSP Mixer - Wave Volume
%MM_OKSORI_MIX_FM         = %MM_OKSORI_BASE+8   ' Oksori DSP Mixer - FM Volume
%MM_OKSORI_MIX_LINE       = %MM_OKSORI_BASE+9   ' Oksori DSP Mixer - Line Volume
%MM_OKSORI_MIX_CD         = %MM_OKSORI_BASE+10  ' Oksori DSP Mixer - CD Volume
%MM_OKSORI_MIX_MIC        = %MM_OKSORI_BASE+11  ' Oksori DSP Mixer - MIC Volume
%MM_OKSORI_MIX_ECHO       = %MM_OKSORI_BASE+12  ' Oksori DSP Mixer - Echo Volume
%MM_OKSORI_MIX_AUX1       = %MM_OKSORI_BASE+13  ' Oksori AD1848 - AUX1 Volume
%MM_OKSORI_MIX_LINE1      = %MM_OKSORI_BASE+14  ' Oksori AD1848 - LINE1 Volume
%MM_OKSORI_EXT_MIC1       = %MM_OKSORI_BASE+15  ' Oksori External - One Mic Connect
%MM_OKSORI_EXT_MIC2       = %MM_OKSORI_BASE+16  ' Oksori External - Two Mic Connect
%MM_OKSORI_MIDIOUT        = %MM_OKSORI_BASE+17  ' Oksori MIDI Out Device
%MM_OKSORI_MIDIIN         = %MM_OKSORI_BASE+18  ' Oksori MIDI In Device
%MM_OKSORI_MPEG_CDVISION  = %MM_OKSORI_BASE+19  ' Oksori CD-Vision MPEG Decoder

'/* MM_DIACOUSTICS product IDs */
%MM_DIACOUSTICS_DRUM_ACTION        = 1      ' /* Drum Action */

'/* MM_KAY_ELEMETRICS product IDs */
%MM_KAY_ELEMETRICS_CSL             = &H4300
%MM_KAY_ELEMETRICS_CSL_DAT         = &H4308
%MM_KAY_ELEMETRICS_CSL_4CHANNEL    = &H4309

'/* MM_CRYSTAL product IDs */
%MM_CRYSTAL_CS4232_WAVEIN          = 1
%MM_CRYSTAL_CS4232_WAVEOUT         = 2
%MM_CRYSTAL_CS4232_WAVEMIXER       = 3
%MM_CRYSTAL_CS4232_WAVEAUX_AUX1    = 4
%MM_CRYSTAL_CS4232_WAVEAUX_AUX2    = 5
%MM_CRYSTAL_CS4232_WAVEAUX_LINE    = 6
%MM_CRYSTAL_CS4232_WAVEAUX_MONO    = 7
%MM_CRYSTAL_CS4232_WAVEAUX_MASTER  = 8
%MM_CRYSTAL_CS4232_MIDIIN          = 9
%MM_CRYSTAL_CS4232_MIDIOUT         = 10
%MM_CRYSTAL_CS4232_INPUTGAIN_AUX1  = 13
%MM_CRYSTAL_CS4232_INPUTGAIN_LOOP  = 14
%MM_CRYSTAL_SOUND_FUSION_WAVEIN    = 21
%MM_CRYSTAL_SOUND_FUSION_WAVEOUT   = 22
%MM_CRYSTAL_SOUND_FUSION_MIXER     = 23
%MM_CRYSTAL_SOUND_FUSION_MIDIIN    = 24
%MM_CRYSTAL_SOUND_FUSION_MIDIOUT   = 25
%MM_CRYSTAL_SOUND_FUSION_JOYSTICK  = 26

'/* MM_QUARTERDECK product IDs */
%MM_QUARTERDECK_LHWAVEIN  = 0      ' Quarterdeck L&H Codec Wave In
%MM_QUARTERDECK_LHWAVEOUT = 1      ' Quarterdeck L&H Codec Wave Out

'/* MM_TDK product IDs */
%MM_TDK_MW_MIDI_SYNTH   = 1
%MM_TDK_MW_MIDI_IN      = 2
%MM_TDK_MW_MIDI_OUT     = 3
%MM_TDK_MW_WAVE_IN      = 4
%MM_TDK_MW_WAVE_OUT     = 5
%MM_TDK_MW_AUX          = 6
%MM_TDK_MW_MIXER        = 10
%MM_TDK_MW_AUX_MASTER   = 100
%MM_TDK_MW_AUX_BASS     = 101
%MM_TDK_MW_AUX_TREBLE   = 102
%MM_TDK_MW_AUX_MIDI_VOL = 103
%MM_TDK_MW_AUX_WAVE_VOL = 104
%MM_TDK_MW_AUX_WAVE_RVB = 105
%MM_TDK_MW_AUX_WAVE_CHR = 106
%MM_TDK_MW_AUX_VOL      = 107
%MM_TDK_MW_AUX_RVB      = 108
%MM_TDK_MW_AUX_CHR      = 109

'/* MM_DIGITAL_AUDIO_LABS product IDs */
%MM_DIGITAL_AUDIO_LABS_TC          = &H01
%MM_DIGITAL_AUDIO_LABS_DOC         = &H02
%MM_DIGITAL_AUDIO_LABS_V8          = &H10
%MM_DIGITAL_AUDIO_LABS_CPRO        = &H11
%MM_DIGITAL_AUDIO_LABS_VP          = &H12
%MM_DIGITAL_AUDIO_LABS_CDLX        = &H13
%MM_DIGITAL_AUDIO_LABS_CTDIF       = &H14

'/* MM_SEERSYS product IDs */
%MM_SEERSYS_SEERSYNTH    = 1
%MM_SEERSYS_SEERWAVE     = 2
%MM_SEERSYS_SEERMIX      = 3
%MM_SEERSYS_WAVESYNTH    = 4
%MM_SEERSYS_WAVESYNTH_WG = 5
%MM_SEERSYS_REALITY      = 6

'/* MM_OSPREY product IDs */
%MM_OSPREY_1000WAVEIN  = 1
%MM_OSPREY_1000WAVEOUT = 2

'/* MM_SOUNDESIGNS product IDs */
%MM_SOUNDESIGNS_WAVEIN  = 1
%MM_SOUNDESIGNS_WAVEOUT = 2

'/* MM_SPECTRUM_SIGNAL_PROCESSING product IDs */
%MM_SSP_SNDFESWAVEIN   = 1   ' Sound Festa Wave In Device
%MM_SSP_SNDFESWAVEOUT  = 2   ' Sound Festa Wave Out Device
%MM_SSP_SNDFESMIDIIN   = 3   ' Sound Festa MIDI In Device
%MM_SSP_SNDFESMIDIOUT  = 4   ' Sound Festa MIDI Out Device
%MM_SSP_SNDFESSYNTH    = 5   ' Sound Festa MIDI Synth Device
%MM_SSP_SNDFESMIX      = 6   ' Sound Festa Mixer Device
%MM_SSP_SNDFESAUX      = 7   ' Sound Festa Auxilliary Device

'/* MM_ECS product IDs */
%MM_ECS_AADF_MIDI_IN               = 10
%MM_ECS_AADF_MIDI_OUT              = 11
%MM_ECS_AADF_WAVE2MIDI_IN          = 12

'/* MM_AMD product IDs */
%MM_AMD_INTERWAVE_WAVEIN           = 1
%MM_AMD_INTERWAVE_WAVEOUT          = 2
%MM_AMD_INTERWAVE_SYNTH            = 3
%MM_AMD_INTERWAVE_MIXER1           = 4
%MM_AMD_INTERWAVE_MIXER2           = 5
%MM_AMD_INTERWAVE_JOYSTICK         = 6
%MM_AMD_INTERWAVE_EX_CD            = 7
%MM_AMD_INTERWAVE_MIDIIN           = 8
%MM_AMD_INTERWAVE_MIDIOUT          = 9
%MM_AMD_INTERWAVE_AUX1             = 10
%MM_AMD_INTERWAVE_AUX2             = 11
%MM_AMD_INTERWAVE_AUX_MIC          = 12
%MM_AMD_INTERWAVE_AUX_CD           = 13
%MM_AMD_INTERWAVE_MONO_IN          = 14
%MM_AMD_INTERWAVE_MONO_OUT         = 15
%MM_AMD_INTERWAVE_EX_TELEPHONY     = 16
%MM_AMD_INTERWAVE_WAVEOUT_BASE     = 17
%MM_AMD_INTERWAVE_WAVEOUT_TREBLE   = 18
%MM_AMD_INTERWAVE_STEREO_ENHANCED  = 19

'/* MM_COREDYNAMICS product IDs */
%MM_COREDYNAMICS_DYNAMIXHR           = 1      ' /* DynaMax Hi-Rez */
%MM_COREDYNAMICS_DYNASONIX_SYNTH     = 2      ' /* DynaSonix */
%MM_COREDYNAMICS_DYNASONIX_MIDI_IN   = 3
%MM_COREDYNAMICS_DYNASONIX_MIDI_OUT  = 4
%MM_COREDYNAMICS_DYNASONIX_WAVE_IN   = 5
%MM_COREDYNAMICS_DYNASONIX_WAVE_OUT  = 6
%MM_COREDYNAMICS_DYNASONIX_AUDIO_IN  = 7
%MM_COREDYNAMICS_DYNASONIX_AUDIO_OUT = 8
%MM_COREDYNAMICS_DYNAGRAFX_VGA       = 9      ' /* DynaGrfx */
%MM_COREDYNAMICS_DYNAGRAFX_WAVE_IN   = 10
%MM_COREDYNAMICS_DYNAGRAFX_WAVE_OUT  = 11

'/* MM_CANAM product IDs */
%MM_CANAM_CBXWAVEOUT = 1
%MM_CANAM_CBXWAVEIN  = 2

'/* MM_SOFTSOUND product IDs */
%MM_SOFTSOUND_CODEC = 1

'/* MM_NORRIS product IDs */
%MM_NORRIS_VOICELINK = 1

'/* MM_DDD product IDs */
%MM_DDD_MIDILINK_MIDIIN            = 1
%MM_DDD_MIDILINK_MIDIOUT           = 2

'/* MM_EUPHONICS product IDs */
%MM_EUPHONICS_AUX_CD               = 1
%MM_EUPHONICS_AUX_LINE             = 2
%MM_EUPHONICS_AUX_MASTER           = 3
%MM_EUPHONICS_AUX_MIC              = 4
%MM_EUPHONICS_AUX_MIDI             = 5
%MM_EUPHONICS_AUX_WAVE             = 6
%MM_EUPHONICS_FMSYNTH_MONO         = 7
%MM_EUPHONICS_FMSYNTH_STEREO       = 8
%MM_EUPHONICS_MIDIIN               = 9
%MM_EUPHONICS_MIDIOUT              = 10
%MM_EUPHONICS_MIXER                = 11
%MM_EUPHONICS_WAVEIN               = 12
%MM_EUPHONICS_WAVEOUT              = 13
%MM_EUPHONICS_EUSYNTH              = 14

'/* MM_CRYSTAL_NET product IDs */
%CRYSTAL_NET_SFM_CODEC             = 1

'/* MM_CHROMATIC product IDs */
%MM_CHROMATIC_M1                    = &H0001
%MM_CHROMATIC_M1_WAVEIN             = &H0002
%MM_CHROMATIC_M1_WAVEOUT            = &H0003
%MM_CHROMATIC_M1_FMSYNTH            = &H0004
%MM_CHROMATIC_M1_MIXER              = &H0005
%MM_CHROMATIC_M1_AUX                = &H0006
%MM_CHROMATIC_M1_AUX_CD             = &H0007
%MM_CHROMATIC_M1_MIDIIN             = &H0008
%MM_CHROMATIC_M1_MIDIOUT            = &H0009
%MM_CHROMATIC_M1_WTSYNTH            = &H0010
%MM_CHROMATIC_M1_MPEGWAVEIN         = &H0011
%MM_CHROMATIC_M1_MPEGWAVEOUT        = &H0012
%MM_CHROMATIC_M2                    = &H0013
%MM_CHROMATIC_M2_WAVEIN             = &H0014
%MM_CHROMATIC_M2_WAVEOUT            = &H0015
%MM_CHROMATIC_M2_FMSYNTH            = &H0016
%MM_CHROMATIC_M2_MIXER              = &H0017
%MM_CHROMATIC_M2_AUX                = &H0018
%MM_CHROMATIC_M2_AUX_CD             = &H0019
%MM_CHROMATIC_M2_MIDIIN             = &H0020
%MM_CHROMATIC_M2_MIDIOUT            = &H0021
%MM_CHROMATIC_M2_WTSYNTH            = &H0022
%MM_CHROMATIC_M2_MPEGWAVEIN         = &H0023
%MM_CHROMATIC_M2_MPEGWAVEOUT        = &H0024

'/* MM_VIENNASYS product IDs */
%MM_VIENNASYS_TSP_WAVE_DRIVER = 1

'/* MM_CONNECTIX product IDs */
%MM_CONNECTIX_VIDEC_CODEC          = 1

'/* MM_GADGETLABS product IDs */
%MM_GADGETLABS_WAVE44_WAVEIN       = 1
%MM_GADGETLABS_WAVE44_WAVEOUT      = 2
%MM_GADGETLABS_WAVE42_WAVEIN       = 3
%MM_GADGETLABS_WAVE42_WAVEOUT      = 4
%MM_GADGETLABS_WAVE4_MIDIIN        = 5
%MM_GADGETLABS_WAVE4_MIDIOUT       = 6

'/* MM_FRONTIER product IDs */
%MM_FRONTIER_WAVECENTER_MIDIIN     = 1      ' /* WaveCenter */
%MM_FRONTIER_WAVECENTER_MIDIOUT    = 2
%MM_FRONTIER_WAVECENTER_WAVEIN     = 3
%MM_FRONTIER_WAVECENTER_WAVEOUT    = 4

'/* MM_VIONA product IDs */
%MM_VIONA_QVINPCI_MIXER    = 1       ' Q-Motion PCI II/Bravado 2000
%MM_VIONA_QVINPCI_WAVEIN   = 2
%MM_VIONAQVINPCI_WAVEOUT   = 3
%MM_VIONA_BUSTER_MIXER     = 4       ' Buster
%MM_VIONA_CINEMASTER_MIXER = 5       ' Cinemaster
%MM_VIONA_CONCERTO_MIXER   = 6       ' Concerto

'/* MM_CASIO product IDs */
%MM_CASIO_WP150_MIDIOUT = 1   ' wp150
%MM_CASIO_WP150_MIDIIN  = 2
%MM_CASIO_LSG_MIDIOUT   = 3

'/* MM_DIAMONDMM product IDs */
%MM_DIMD_PLATFORM                  = 0      ' /* Freedom Audio */
%MM_DIMD_DIRSOUND                  = 1
%MM_DIMD_VIRTMPU                   = 2
%MM_DIMD_VIRTSB                    = 3
%MM_DIMD_VIRTJOY                   = 4
%MM_DIMD_WAVEIN                    = 5
%MM_DIMD_WAVEOUT                   = 6
%MM_DIMD_MIDIIN                    = 7
%MM_DIMD_MIDIOUT                   = 8
%MM_DIMD_AUX_LINE                  = 9
%MM_DIMD_MIXER                     = 10
%MM_DIMD_WSS_WAVEIN                = 14
%MM_DIMD_WSS_WAVEOUT               = 15
%MM_DIMD_WSS_MIXER                 = 17
%MM_DIMD_WSS_AUX                   = 21
%MM_DIMD_WSS_SYNTH                 = 76

'/* MM_S3 product IDs */
%MM_S3_WAVEOUT = 1
%MM_S3_WAVEIN  = 2
%MM_S3_MIDIOUT = 3
%MM_S3_MIDIIN  = 4
%MM_S3_FMSYNTH = 5
%MM_S3_MIXER   = 6
%MM_S3_AUX     = 7

'/* MM_VANKOEVERING product IDs */
%MM_VKC_MPU401_MIDIIN              = &H0100
%MM_VKC_SERIAL_MIDIIN              = &H0101
%MM_VKC_MPU401_MIDIOUT             = &H0200
%MM_VKC_SERIAL_MIDIOUT             = &H0201

'/* MM_ZEFIRO product IDs */
%MM_ZEFIRO_ZA2                     = 2

'/* MM_FRAUNHOFER_IIS product IDs */
%MM_FHGIIS_MPEGLAYER3              = 10

'/* MM_QUICKNET product IDs */
%MM_QUICKNET_PJWAVEIN              = 1
%MM_QUICKNET_PJWAVEOUT             = 2

'/* MM_SICRESOURCE product IDs */
%MM_SICRESOURCE_SSO3D              = 2
%MM_SICRESOURCE_SSOW3DI            = 3

'/* MM_NEOMAGIC product IDs */
%MM_NEOMAGIC_SYNTH                 = 1
%MM_NEOMAGIC_WAVEOUT               = 2
%MM_NEOMAGIC_WAVEIN                = 3
%MM_NEOMAGIC_MIDIOUT               = 4
%MM_NEOMAGIC_MIDIIN                = 5
%MM_NEOMAGIC_AUX                   = 6
%MM_NEOMAGIC_MW3DX_WAVEOUT         = 10
%MM_NEOMAGIC_MW3DX_WAVEIN          = 11
%MM_NEOMAGIC_MW3DX_MIDIOUT         = 12
%MM_NEOMAGIC_MW3DX_MIDIIN          = 13
%MM_NEOMAGIC_MW3DX_FMSYNTH         = 14
%MM_NEOMAGIC_MW3DX_GMSYNTH         = 15
%MM_NEOMAGIC_MW3DX_MIXER           = 16
%MM_NEOMAGIC_MW3DX_AUX             = 17
%MM_NEOMAGIC_MWAVE_WAVEOUT         = 20
%MM_NEOMAGIC_MWAVE_WAVEIN          = 21
%MM_NEOMAGIC_MWAVE_MIDIOUT         = 22
%MM_NEOMAGIC_MWAVE_MIDIIN          = 23
%MM_NEOMAGIC_MWAVE_MIXER           = 24
%MM_NEOMAGIC_MWAVE_AUX             = 25

'/* MM_MERGING_TECHNOLOGIES product IDs */
%MM_MERGING_MPEGL3                 = 1

'/* MM_XIRLINK product IDs */
%MM_XIRLINK_VISIONLINK             = 1

'/* MM_OTI product IDs */
%MM_OTI_611WAVEIN                  = 5
%MM_OTI_611WAVEOUT                 = 6
%MM_OTI_611MIXER                   = 7
%MM_OTI_611MIDIN                   = &H12
%MM_OTI_611MIDIOUT                 = &H13

'/* MM_AUREAL product IDs */
%MM_AUREAL_AU8820                  = 16
%MM_AU8820_SYNTH                   = 17
%MM_AU8820_WAVEOUT                 = 18
%MM_AU8820_WAVEIN                  = 19
%MM_AU8820_MIXER                   = 20
%MM_AU8820_AUX                     = 21
%MM_AU8820_MIDIOUT                 = 22
%MM_AU8820_MIDIIN                  = 23
%MM_AUREAL_AU8830                  = 32
%MM_AU8830_SYNTH                   = 33
%MM_AU8830_WAVEOUT                 = 34
%MM_AU8830_WAVEIN                  = 35
%MM_AU8830_MIXER                   = 36
%MM_AU8830_AUX                     = 37
%MM_AU8830_MIDIOUT                 = 38
%MM_AU8830_MIDIIN                  = 39

'/* MM_VIVO product IDs */
%MM_VIVO_AUDIO_CODEC               = 1

'/* MM_SHARP product IDs */
%MM_SHARP_MDC_MIDI_SYNTH           = 1
%MM_SHARP_MDC_MIDI_IN              = 2
%MM_SHARP_MDC_MIDI_OUT             = 3
%MM_SHARP_MDC_WAVE_IN              = 4
%MM_SHARP_MDC_WAVE_OUT             = 5
%MM_SHARP_MDC_AUX                  = 6
%MM_SHARP_MDC_MIXER                = 10
%MM_SHARP_MDC_AUX_MASTER           = 100
%MM_SHARP_MDC_AUX_BASS             = 101
%MM_SHARP_MDC_AUX_TREBLE           = 102
%MM_SHARP_MDC_AUX_MIDI_VOL         = 103
%MM_SHARP_MDC_AUX_WAVE_VOL         = 104
%MM_SHARP_MDC_AUX_WAVE_RVB         = 105
%MM_SHARP_MDC_AUX_WAVE_CHR         = 106
%MM_SHARP_MDC_AUX_VOL              = 107
%MM_SHARP_MDC_AUX_RVB              = 108
%MM_SHARP_MDC_AUX_CHR              = 109

'/* MM_LUCENT product IDs */
%MM_LUCENT_ACM_G723                = 0

'/* MM_ATT product IDs */
%MM_ATT_G729A                      = 1

'/* MM_MARIAN product IDs */
%MM_MARIAN_ARC44WAVEIN             = 1
%MM_MARIAN_ARC44WAVEOUT            = 2
%MM_MARIAN_PRODIF24WAVEIN          = 3
%MM_MARIAN_PRODIF24WAVEOUT         = 4
%MM_MARIAN_ARC88WAVEIN             = 5
%MM_MARIAN_ARC88WAVEOUT            = 6

'/* MM_BCB product IDs */
%MM_BCB_NETBOARD_10                = 1
%MM_BCB_TT75_10                    = 2

'/* MM_MOTIONPIXELS product IDs */
%MM_MOTIONPIXELS_MVI2              = 1

'/* MM_QDESIGN product IDs */
%MM_QDESIGN_ACM_MPEG               = 1
%MM_QDESIGN_ACM_QDESIGN_MUSIC      = 2

'/* MM_NMP product IDs */
%MM_NMP_CCP_WAVEIN                 = 1
%MM_NMP_CCP_WAVEOUT                = 2
%MM_NMP_ACM_AMR                    = 10

'/* MM_DATAFUSION product IDs */
%MM_DF_ACM_G726                    = 1
%MM_DF_ACM_GSM610                  = 2

'/* MM_BERCOS product IDs */
%MM_BERCOS_WAVEIN                  = 1
%MM_BERCOS_MIXER                   = 2
%MM_BERCOS_WAVEOUT                 = 3

'/* MM_ONLIVE product IDs */
%MM_ONLIVE_MPCODEC                 = 1

'/* MM_PHONET product IDs */
%MM_PHONET_PP_WAVEOUT              = 1
%MM_PHONET_PP_WAVEIN               = 2
%MM_PHONET_PP_MIXER                = 3

'/* MM_FTR product IDs */
%MM_FTR_ENCODER_WAVEIN             = 1
%MM_FTR_ACM                        = 2

'/* MM_ENET product IDs */
%MM_ENET_T2000_LINEIN              = 1
%MM_ENET_T2000_LINEOUT             = 2
%MM_ENET_T2000_HANDSETIN           = 3
%MM_ENET_T2000_HANDSETOUT          = 4

'/*  MM_EMAGIC product IDs */
%MM_EMAGIC_UNITOR8                 = 1

'/*  MM_SIPROLAB product IDs */
%MM_SIPROLAB_ACELPNET              = 1

'/*  MM_DICTAPHONE product IDs */
%MM_DICTAPHONE_G726                = 1      ' /* G726 ACM codec (g726pcm.acm) */

'/*  MM_RZS product IDs */
%MM_RZS_ACM_TUBGSM                 = 1      ' /* GSM 06.10 CODEC */

'/*  MM_EES product IDs */
%MM_EES_PCMIDI14                   = 1
%MM_EES_PCMIDI14_IN                = 2
%MM_EES_PCMIDI14_OUT1              = 3
%MM_EES_PCMIDI14_OUT2              = 4
%MM_EES_PCMIDI14_OUT3              = 5
%MM_EES_PCMIDI14_OUT4              = 6

'/*  MM_HAFTMANN product IDs */
%MM_HAFTMANN_LPTDAC2               = 1

'/*  MM_LUCID product IDs */
%MM_LUCID_PCI24WAVEIN              = 1
%MM_LUCID_PCI24WAVEOUT             = 2

'/*  MM_HEADSPACE product IDs */
%MM_HEADSPACE_HAESYNTH             = 1
%MM_HEADSPACE_HAEWAVEOUT           = 2
%MM_HEADSPACE_HAEWAVEIN            = 3
%MM_HEADSPACE_HAEMIXER             = 4

'/*  MM_UNISYS product IDs */
%MM_UNISYS_ACM_NAP                 = 1

'/*  MM_LUMINOSITI product IDs */

%MM_LUMINOSITI_SCWAVEIN            = 1
%MM_LUMINOSITI_SCWAVEOUT           = 2
%MM_LUMINOSITI_SCWAVEMIX           = 3

'/*  MM_ACTIVEVOICE product IDs */
%MM_ACTIVEVOICE_ACM_VOXADPCM       = 1

'/*  MM_DTS product IDs */
%MM_DTS_DS                         = 1

'/*  MM_SOFTLAB_NSK product IDs */
%MM_SOFTLAB_NSK_FRW_WAVEIN         = 1
%MM_SOFTLAB_NSK_FRW_WAVEOUT        = 2
%MM_SOFTLAB_NSK_FRW_MIXER          = 3
%MM_SOFTLAB_NSK_FRW_AUX            = 4

'/*  MM_FORTEMEDIA product IDs */
%MM_FORTEMEDIA_WAVEIN              = 1
%MM_FORTEMEDIA_WAVEOUT             = 2
%MM_FORTEMEDIA_FMSYNC              = 3
%MM_FORTEMEDIA_MIXER               = 4
%MM_FORTEMEDIA_AUX                 = 5

'/*  MM_SONORUS product IDs */
%MM_SONORUS_STUDIO                 = 1

'/*  MM_I_LINK product IDs */
%MM_I_LINK_VOICE_CODER             = 1

'/*  MM_SELSIUS_SYSTEMS product IDs */
%MM_SELSIUS_SYSTEMS_RTPWAVEOUT     = 1
%MM_SELSIUS_SYSTEMS_RTPWAVEIN      = 2

'/*  MM_ADMOS product IDs */
%MM_ADMOS_FM_SYNTH                 = 1
%MM_ADMOS_QS3AMIDIOUT              = 2
%MM_ADMOS_QS3AMIDIIN               = 3
%MM_ADMOS_QS3AWAVEOUT              = 4
%MM_ADMOS_QS3AWAVEIN               = 5

'/* MM_LEXICON product IDs */
%MM_LEXICON_STUDIO_WAVE_OUT        = 1
%MM_LEXICON_STUDIO_WAVE_IN         = 2

'/* MM_SGI product IDs */
%MM_SGI_320_WAVEIN                 = 1
%MM_SGI_320_WAVEOUT                = 2
%MM_SGI_320_MIXER                  = 3
%MM_SGI_540_WAVEIN                 = 4
%MM_SGI_540_WAVEOUT                = 5
%MM_SGI_540_MIXER                  = 6
%MM_SGI_RAD_ADATMONO1_WAVEIN       = 7
%MM_SGI_RAD_ADATMONO2_WAVEIN       = 8
%MM_SGI_RAD_ADATMONO3_WAVEIN       = 9
%MM_SGI_RAD_ADATMONO4_WAVEIN       = 10
%MM_SGI_RAD_ADATMONO5_WAVEIN       = 11
%MM_SGI_RAD_ADATMONO6_WAVEIN       = 12
%MM_SGI_RAD_ADATMONO7_WAVEIN       = 13
%MM_SGI_RAD_ADATMONO8_WAVEIN       = 14
%MM_SGI_RAD_ADATSTEREO12_WAVEIN    = 15
%MM_SGI_RAD_ADATSTEREO34_WAVEIN    = 16
%MM_SGI_RAD_ADATSTEREO56_WAVEIN    = 17
%MM_SGI_RAD_ADATSTEREO78_WAVEIN    = 18
%MM_SGI_RAD_ADAT8CHAN_WAVEIN       = 19
%MM_SGI_RAD_ADATMONO1_WAVEOUT      = 20
%MM_SGI_RAD_ADATMONO2_WAVEOUT      = 21
%MM_SGI_RAD_ADATMONO3_WAVEOUT      = 22
%MM_SGI_RAD_ADATMONO4_WAVEOUT      = 23
%MM_SGI_RAD_ADATMONO5_WAVEOUT      = 24
%MM_SGI_RAD_ADATMONO6_WAVEOUT      = 25
%MM_SGI_RAD_ADATMONO7_WAVEOUT      = 26
%MM_SGI_RAD_ADATMONO8_WAVEOUT      = 27
%MM_SGI_RAD_ADATSTEREO12_WAVEOUT   = 28
%MM_SGI_RAD_ADATSTEREO32_WAVEOUT   = 29
%MM_SGI_RAD_ADATSTEREO56_WAVEOUT   = 30
%MM_SGI_RAD_ADATSTEREO78_WAVEOUT   = 31
%MM_SGI_RAD_ADAT8CHAN_WAVEOUT      = 32
%MM_SGI_RAD_AESMONO1_WAVEIN        = 33
%MM_SGI_RAD_AESMONO2_WAVEIN        = 34
%MM_SGI_RAD_AESSTEREO_WAVEIN       = 35
%MM_SGI_RAD_AESMONO1_WAVEOUT       = 36
%MM_SGI_RAD_AESMONO2_WAVEOUT       = 37
%MM_SGI_RAD_AESSTEREO_WAVEOUT      = 38

'/* MM_IPI product IDs */
%MM_IPI_ACM_HSX                    = 1
%MM_IPI_ACM_RPELP                  = 2
%MM_IPI_WF_ASSS                    = 3
%MM_IPI_AT_WAVEOUT                 = 4
%MM_IPI_AT_WAVEIN                  = 5
%MM_IPI_AT_MIXER                   = 6

'/* MM_ICE product IDs */
%MM_ICE_WAVEOUT                    = 1
%MM_ICE_WAVEIN                     = 2
%MM_ICE_MTWAVEOUT                  = 3
%MM_ICE_MTWAVEIN                   = 4
%MM_ICE_MIDIOUT1                   = 5
%MM_ICE_MIDIIN1                    = 6
%MM_ICE_MIDIOUT2                   = 7
%MM_ICE_MIDIIN2                    = 8
%MM_ICE_SYNTH                      = 9
%MM_ICE_MIXER                      = 10
%MM_ICE_AUX                        = 11

'/* MM_VQST product IDs */
%MM_VQST_VQC1                      = 1
%MM_VQST_VQC2                      = 2

'/* MM_ETEK product IDs */
%MM_ETEK_KWIKMIDI_MIDIIN           = 1
%MM_ETEK_KWIKMIDI_MIDIOUT          = 2

'/* MM_INTERNET product IDs */
%MM_INTERNET_SSW_MIDIOUT           = 10
%MM_INTERNET_SSW_MIDIIN            = 11
%MM_INTERNET_SSW_WAVEOUT           = 12
%MM_INTERNET_SSW_WAVEIN            = 13

'/* MM_SONY product IDs */
%MM_SONY_ACM_SCX                   = 1

'/* MM_UHER_INFORMATIC product IDs */
%MM_UH_ACM_ADPCM                   = 1

'/* MM_SYDEC_NV product IDs */
%MM_SYDEC_NV_WAVEIN                = 1
%MM_SYDEC_NV_WAVEOUT               = 2

'/* MM_FLEXION product IDs */
%MM_FLEXION_X300_WAVEIN            = 1
%MM_FLEXION_X300_WAVEOUT           = 2

'/* MM_VIA product IDs */
%MM_VIA_WAVEOUT                    = 1
%MM_VIA_WAVEIN                     = 2
%MM_VIA_MIXER                      = 3
%MM_VIA_AUX                        = 4
%MM_VIA_MPU401_MIDIOUT             = 5
%MM_VIA_MPU401_MIDIIN              = 6
%MM_VIA_SWFM_SYNTH                 = 7
%MM_VIA_WDM_WAVEOUT                = 8
%MM_VIA_WDM_WAVEIN                 = 9
%MM_VIA_WDM_MIXER                  = 10
%MM_VIA_WDM_MPU401_MIDIOUT         = 11
%MM_VIA_WDM_MPU401_MIDIIN          = 12

'/* MM_MICRONAS product IDs */
%MM_MICRONAS_SC4                   = 1
%MM_MICRONAS_CLP833                = 2

'/* MM_HP product IDs */
%MM_HP_WAVEOUT                     = 1
%MM_HP_WAVEIN                      = 2

'/* MM_QUICKAUDIO product IDs */
%MM_QUICKAUDIO_MINIMIDI            = 1
%MM_QUICKAUDIO_MAXIMIDI            = 2

'/* MM_ICCC product IDs */
%MM_ICCC_UNA3_WAVEIN               = 1
%MM_ICCC_UNA3_WAVEOUT              = 2
%MM_ICCC_UNA3_AUX                  = 3
%MM_ICCC_UNA3_MIXER                = 4

'/* MM_3COM product IDs */
%MM_3COM_CB_MIXER                  = 1
%MM_3COM_CB_WAVEIN                 = 2
%MM_3COM_CB_WAVEOUT                = 3

'/* MM_MINDMAKER product IDs */
%MM_MINDMAKER_GC_WAVEIN            = 1
%MM_MINDMAKER_GC_WAVEOUT           = 2
%MM_MINDMAKER_GC_MIXER             = 3

'/* MM_TELEKOL product IDs */
%MM_TELEKOL_WAVEOUT                = 1
%MM_TELEKOL_WAVEIN                 = 2

'/* MM_ALGOVISION product IDs */
%MM_ALGOVISION_VB80WAVEOUT         = 1
%MM_ALGOVISION_VB80WAVEIN          = 2
%MM_ALGOVISION_VB80MIXER           = 3
%MM_ALGOVISION_VB80AUX             = 4
%MM_ALGOVISION_VB80AUX2            = 5

'#endif  // !NOMMIDS
#ENDIF   ' #IF NOT %DEF(%NOMMIDS)

'/* ------------------------------------------------------------------------------ */

'/*              INFO LIST CHUNKS (from the Multimedia Programmer's Reference
'                                        plus new ones)
'*/
%RIFFINFO_IARL  = &H4C524149  '  mmioFOURCC ('I', 'A', 'R', 'L')     /*Archival location  */
%RIFFINFO_IART  = &H54524149  '  mmioFOURCC ('I', 'A', 'R', 'T')     /*Artist  */
%RIFFINFO_ICMS  = &H534D4349  '  mmioFOURCC ('I', 'C', 'M', 'S')     /*Commissioned  */
%RIFFINFO_ICMT  = &H544D4349  '  mmioFOURCC ('I', 'C', 'M', 'T')     /*Comments  */
%RIFFINFO_ICOP  = &H504F4349  '  mmioFOURCC ('I', 'C', 'O', 'P')     /*Copyright  */
%RIFFINFO_ICRD  = &H44524349  '  mmioFOURCC ('I', 'C', 'R', 'D')     /*Creation date of subject  */
%RIFFINFO_ICRP  = &H50524349  '  mmioFOURCC ('I', 'C', 'R', 'P')     /*Cropped  */
%RIFFINFO_IDIM  = &H4D494449  '  mmioFOURCC ('I', 'D', 'I', 'M')     /*Dimensions  */
%RIFFINFO_IDPI  = &H495D4449  '  mmioFOURCC ('I', 'D', 'P', 'I')     /*Dots per inch  */
%RIFFINFO_IENG  = &H474E4549  '  mmioFOURCC ('I', 'E', 'N', 'G')     /*Engineer  */
%RIFFINFO_IGNR  = &H524E4749  '  mmioFOURCC ('I', 'G', 'N', 'R')     /*Genre  */
%RIFFINFO_IKEY  = &H59454B49  '  mmioFOURCC ('I', 'K', 'E', 'Y')     /*Keywords  */
%RIFFINFO_ILGT  = &H54474C49  '  mmioFOURCC ('I', 'L', 'G', 'T')     /*Lightness settings  */
%RIFFINFO_IMED  = &H44454D49  '  mmioFOURCC ('I', 'M', 'E', 'D')     /*Medium  */
%RIFFINFO_INAM  = &H4D414E49  '  mmioFOURCC ('I', 'N', 'A', 'M')     /*Name of subject  */
%RIFFINFO_IPLT  = &H544C5049  '  mmioFOURCC ('I', 'P', 'L', 'T')     /*Palette Settings. No. of colors requested.   */
%RIFFINFO_IPRD  = &H44525049  '  mmioFOURCC ('I', 'P', 'R', 'D')     /*Product  */
%RIFFINFO_ISBJ  = &H4A425349  '  mmioFOURCC ('I', 'S', 'B', 'J')     /*Subject description  */
%RIFFINFO_ISFT  = &H54465349  '  mmioFOURCC ('I', 'S', 'F', 'T')     /*Software. Name of package used to create file.  */
%RIFFINFO_ISHP  = &H50485349  '  mmioFOURCC ('I', 'S', 'H', 'P')     /*Sharpness.  */
%RIFFINFO_ISRC  = &H43525349  '  mmioFOURCC ('I', 'S', 'R', 'C')     /*Source.   */
%RIFFINFO_ISRF  = &H46525349  '  mmioFOURCC ('I', 'S', 'R', 'F')     /*Source Form. ie slide, paper  */
%RIFFINFO_ITCH  = &H48435449  '  mmioFOURCC ('I', 'T', 'C', 'H')     /*Technician who digitized the subject.  */

'/* New INFO Chunks as of August 30, 1993: */
%RIFFINFO_ISMP  = &H504D5349  '  mmioFOURCC ('I', 'S', 'M', 'P')     /*SMPTE time code  */
'/* ISMP: SMPTE time code of digitization start point expressed as a NULL terminated
'                text string "HH:MM:SS:FF". If performing MCI capture in AVICAP, this
'                chunk will be automatically set based on the MCI start time.
'*/
%RIFFINFO_IDIT  = &H5449449   '  mmioFOURCC ('I', 'D', 'I', 'T')     /*Digitization Time  */
'/* IDIT: "Digitization Time" Specifies the time and date that the digitization commenced.
'                The digitization time is contained in an ASCII string which
'                contains exactly 26 characters and is in the format
'                "Wed Jan 02 02:03:55 1990\n\0".
'                The ctime(), asctime(), functions can be used to create strings
'                in this format. This chunk is automatically added to the capture
'                file based on the current system time at the moment capture is initiated.
'*/

'#define RIFFINFO_ITRK      mmioFOURCC ('I', 'T', 'R', 'K')     /*ASCIIZ representation of the 1-based track number of the content.  */
%RIFFINFO_ITRK = &H48525459
'#define RIFFINFO_ITOC      mmioFOURCC ('I', 'T', 'O', 'C')     /*A dump of the table of contents from the CD the content originated from.  */
%RIFFINFO_ITOC = &H484F5449

'/*Template line for new additions*/
'/*#define RIFFINFO_I      mmioFOURCC ('I', '', '', '')        */

'/* ------------------------------------------------------------------------------ */

#IF NOT %DEF(%NONEWWAVE)

'/* WAVE form wFormatTag IDs */
%WAVE_FORMAT_UNKNOWN                    = &H0000 ' /* Microsoft Corporation */
%WAVE_FORMAT_ADPCM                      = &H0002 ' /* Microsoft Corporation */
%WAVE_FORMAT_IEEE_FLOAT                 = &H0003 ' /* Microsoft Corporation */
%WAVE_FORMAT_VSELP                      = &H0004 ' /* Compaq Computer Corp. */
%WAVE_FORMAT_IBM_CVSD                   = &H0005 ' /* IBM Corporation */
%WAVE_FORMAT_ALAW                       = &H0006 ' /* Microsoft Corporation */
%WAVE_FORMAT_MULAW                      = &H0007 ' /* Microsoft Corporation */
%WAVE_FORMAT_DTS                        = &H0008 ' /* Microsoft Corporation */
%WAVE_FORMAT_DRM                        = &H0009 ' /* Microsoft Corporation */
%WAVE_FORMAT_OKI_ADPCM                  = &H0010 ' /* OKI */
%WAVE_FORMAT_DVI_ADPCM                  = &H0011 ' /* Intel Corporation */
%WAVE_FORMAT_IMA_ADPCM                  = (%WAVE_FORMAT_DVI_ADPCM) ' /*  Intel Corporation */
%WAVE_FORMAT_MEDIASPACE_ADPCM           = &H0012 ' /* Videologic */
%WAVE_FORMAT_SIERRA_ADPCM               = &H0013 ' /* Sierra Semiconductor Corp */
%WAVE_FORMAT_G723_ADPCM                 = &H0014 ' /* Antex Electronics Corporation */
%WAVE_FORMAT_DIGISTD                    = &H0015 ' /* DSP Solutions, Inc. */
%WAVE_FORMAT_DIGIFIX                    = &H0016 ' /* DSP Solutions, Inc. */
%WAVE_FORMAT_DIALOGIC_OKI_ADPCM         = &H0017 ' /* Dialogic Corporation */
%WAVE_FORMAT_MEDIAVISION_ADPCM          = &H0018 ' /* Media Vision, Inc. */
%WAVE_FORMAT_CU_CODEC                   = &H0019 ' /* Hewlett-Packard Company */
%WAVE_FORMAT_YAMAHA_ADPCM               = &H0020 ' /* Yamaha Corporation of America */
%WAVE_FORMAT_SONARC                     = &H0021 ' /* Speech Compression */
%WAVE_FORMAT_DSPGROUP_TRUESPEECH        = &H0022 ' /* DSP Group, Inc */
%WAVE_FORMAT_ECHOSC1                    = &H0023 ' /* Echo Speech Corporation */
%WAVE_FORMAT_AUDIOFILE_AF36             = &H0024 ' /* Virtual Music, Inc. */
%WAVE_FORMAT_APTX                       = &H0025 ' /* Audio Processing Technology */
%WAVE_FORMAT_AUDIOFILE_AF10             = &H0026 ' /* Virtual Music, Inc. */
%WAVE_FORMAT_PROSODY_1612               = &H0027 ' /* Aculab plc */
%WAVE_FORMAT_LRC                        = &H0028 ' /* Merging Technologies S.A. */
%WAVE_FORMAT_DOLBY_AC2                  = &H0030 ' /* Dolby Laboratories */
%WAVE_FORMAT_GSM610                     = &H0031 ' /* Microsoft Corporation */
%WAVE_FORMAT_MSNAUDIO                   = &H0032 ' /* Microsoft Corporation */
%WAVE_FORMAT_ANTEX_ADPCME               = &H0033 ' /* Antex Electronics Corporation */
%WAVE_FORMAT_CONTROL_RES_VQLPC          = &H0034 ' /* Control Resources Limited */
%WAVE_FORMAT_DIGIREAL                   = &H0035 ' /* DSP Solutions, Inc. */
%WAVE_FORMAT_DIGIADPCM                  = &H0036 ' /* DSP Solutions, Inc. */
%WAVE_FORMAT_CONTROL_RES_CR10           = &H0037 ' /* Control Resources Limited */
%WAVE_FORMAT_NMS_VBXADPCM               = &H0038 ' /* Natural MicroSystems */
%WAVE_FORMAT_CS_IMAADPCM                = &H0039 ' /* Crystal Semiconductor IMA ADPCM */
%WAVE_FORMAT_ECHOSC3                    = &H003A ' /* Echo Speech Corporation */
%WAVE_FORMAT_ROCKWELL_ADPCM             = &H003B ' /* Rockwell International */
%WAVE_FORMAT_ROCKWELL_DIGITALK          = &H003C ' /* Rockwell International */
%WAVE_FORMAT_XEBEC                      = &H003D ' /* Xebec Multimedia Solutions Limited */
%WAVE_FORMAT_G721_ADPCM                 = &H0040 ' /* Antex Electronics Corporation */
%WAVE_FORMAT_G728_CELP                  = &H0041 ' /* Antex Electronics Corporation */
%WAVE_FORMAT_MSG723                     = &H0042 ' /* Microsoft Corporation */
%WAVE_FORMAT_MPEG                       = &H0050 ' /* Microsoft Corporation */
%WAVE_FORMAT_RT24                       = &H0052 ' /* InSoft, Inc. */
%WAVE_FORMAT_PAC                        = &H0053 ' /* InSoft, Inc. */
%WAVE_FORMAT_MPEGLAYER3                 = &H0055 ' /* ISO/MPEG Layer3 Format Tag */
%WAVE_FORMAT_LUCENT_G723                = &H0059 ' /* Lucent Technologies */
%WAVE_FORMAT_CIRRUS                     = &H0060 ' /* Cirrus Logic */
%WAVE_FORMAT_ESPCM                      = &H0061 ' /* ESS Technology */
%WAVE_FORMAT_VOXWARE                    = &H0062 ' /* Voxware Inc */
%WAVE_FORMAT_CANOPUS_ATRAC              = &H0063 ' /* Canopus, co., Ltd. */
%WAVE_FORMAT_G726_ADPCM                 = &H0064 ' /* APICOM */
%WAVE_FORMAT_G722_ADPCM                 = &H0065 ' /* APICOM */
%WAVE_FORMAT_DSAT_DISPLAY               = &H0067 ' /* Microsoft Corporation */
%WAVE_FORMAT_VOXWARE_BYTE_ALIGNED       = &H0069 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_AC8                = &H0070 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_AC10               = &H0071 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_AC16               = &H0072 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_AC20               = &H0073 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_RT24               = &H0074 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_RT29               = &H0075 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_RT29HW             = &H0076 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_VR12               = &H0077 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_VR18               = &H0078 ' /* Voxware Inc */
%WAVE_FORMAT_VOXWARE_TQ40               = &H0079 ' /* Voxware Inc */
%WAVE_FORMAT_SOFTSOUND                  = &H0080 ' /* Softsound, Ltd. */
%WAVE_FORMAT_VOXWARE_TQ60               = &H0081 ' /* Voxware Inc */
%WAVE_FORMAT_MSRT24                     = &H0082 ' /* Microsoft Corporation */
%WAVE_FORMAT_G729A                      = &H0083 ' /* AT&T Labs, Inc. */
%WAVE_FORMAT_MVI_MVI2                   = &H0084 ' /* Motion Pixels */
%WAVE_FORMAT_DF_G726                    = &H0085 ' /* DataFusion Systems (Pty) (Ltd) */
%WAVE_FORMAT_DF_GSM610                  = &H0086 ' /* DataFusion Systems (Pty) (Ltd) */
%WAVE_FORMAT_ISIAUDIO                   = &H0088 ' /* Iterated Systems, Inc. */
%WAVE_FORMAT_ONLIVE                     = &H0089 ' /* OnLive! Technologies, Inc. */
%WAVE_FORMAT_SBC24                      = &H0091 ' /* Siemens Business Communications Sys */
%WAVE_FORMAT_DOLBY_AC3_SPDIF            = &H0092 ' /* Sonic Foundry */
%WAVE_FORMAT_MEDIASONIC_G723            = &H0093 ' /* MediaSonic */
%WAVE_FORMAT_PROSODY_8KBPS              = &H0094 ' /* Aculab plc */
%WAVE_FORMAT_ZYXEL_ADPCM                = &H0097 ' /* ZyXEL Communications, Inc. */
%WAVE_FORMAT_PHILIPS_LPCBB              = &H0098 ' /* Philips Speech Processing */
%WAVE_FORMAT_PACKED                     = &H0099 ' /* Studer Professional Audio AG */
%WAVE_FORMAT_MALDEN_PHONYTALK           = &H00A0 ' /* Malden Electronics Ltd. */
%WAVE_FORMAT_RAW_AAC1                   = &H00FF ' /* For Raw AAC, with format block AudioSpecificConfig() (as defined by MPEG-4), that follows WAVEFORMATEX */
%WAVE_FORMAT_RHETOREX_ADPCM             = &H0100 ' /* Rhetorex Inc. */
%WAVE_FORMAT_IRAT                       = &H0101 ' /* BeCubed Software Inc. */
%WAVE_FORMAT_VIVO_G723                  = &H0111 ' /* Vivo Software */
%WAVE_FORMAT_VIVO_SIREN                 = &H0112 ' /* Vivo Software */
%WAVE_FORMAT_DIGITAL_G723               = &H0123 ' /* Digital Equipment Corporation */
%WAVE_FORMAT_SANYO_LD_ADPCM             = &H0125 ' /* Sanyo Electric Co., Ltd. */
%WAVE_FORMAT_SIPROLAB_ACEPLNET          = &H0130 ' /* Sipro Lab Telecom Inc. */
%WAVE_FORMAT_SIPROLAB_ACELP4800         = &H0131 ' /* Sipro Lab Telecom Inc. */
%WAVE_FORMAT_SIPROLAB_ACELP8V3          = &H0132 ' /* Sipro Lab Telecom Inc. */
%WAVE_FORMAT_SIPROLAB_G729              = &H0133 ' /* Sipro Lab Telecom Inc. */
%WAVE_FORMAT_SIPROLAB_G729A             = &H0134 ' /* Sipro Lab Telecom Inc. */
%WAVE_FORMAT_SIPROLAB_KELVIN            = &H0135 ' /* Sipro Lab Telecom Inc. */
%WAVE_FORMAT_G726ADPCM                  = &H0140 ' /* Dictaphone Corporation */
%WAVE_FORMAT_QUALCOMM_PUREVOICE         = &H0150 ' /* Qualcomm, Inc. */
%WAVE_FORMAT_QUALCOMM_HALFRATE          = &H0151 ' /* Qualcomm, Inc. */
%WAVE_FORMAT_TUBGSM                     = &H0155 ' /* Ring Zero Systems, Inc. */
%WAVE_FORMAT_MSAUDIO1                   = &H0160 ' /* Microsoft Corporation */
%WAVE_FORMAT_UNISYS_NAP_ADPCM           = &H0170 ' /* Unisys Corp. */
%WAVE_FORMAT_UNISYS_NAP_ULAW            = &H0171 ' /* Unisys Corp. */
%WAVE_FORMAT_UNISYS_NAP_ALAW            = &H0172 ' /* Unisys Corp. */
%WAVE_FORMAT_UNISYS_NAP_16K             = &H0173 ' /* Unisys Corp. */
%WAVE_FORMAT_CREATIVE_ADPCM             = &H0200 ' /* Creative Labs, Inc */
%WAVE_FORMAT_CREATIVE_FASTSPEECH8       = &H0202 ' /* Creative Labs, Inc */
%WAVE_FORMAT_CREATIVE_FASTSPEECH10      = &H0203 ' /* Creative Labs, Inc */
%WAVE_FORMAT_UHER_ADPCM                 = &H0210 ' /* UHER informatic GmbH */
%WAVE_FORMAT_QUARTERDECK                = &H0220 ' /* Quarterdeck Corporation */
%WAVE_FORMAT_ILINK_VC                   = &H0230 ' /* I-link Worldwide */
%WAVE_FORMAT_RAW_SPORT                  = &H0240 ' /* Aureal Semiconductor */
%WAVE_FORMAT_ESST_AC3                   = &H0241 ' /* ESS Technology, Inc. */
%WAVE_FORMAT_IPI_HSX                    = &H0250 ' /* Interactive Products, Inc. */
%WAVE_FORMAT_IPI_RPELP                  = &H0251 ' /* Interactive Products, Inc. */
%WAVE_FORMAT_CS2                        = &H0260 ' /* Consistent Software */
%WAVE_FORMAT_SONY_SCX                   = &H0270 ' /* Sony Corp. */
%WAVE_FORMAT_FM_TOWNS_SND               = &H0300 ' /* Fujitsu Corp. */
%WAVE_FORMAT_BTV_DIGITAL                = &H0400 ' /* Brooktree Corporation */
%WAVE_FORMAT_QDESIGN_MUSIC              = &H0450 ' /* QDesign Corporation */
%WAVE_FORMAT_VME_VMPCM                  = &H0680 ' /* AT&T Labs, Inc. */
%WAVE_FORMAT_TPC                        = &H0681 ' /* AT&T Labs, Inc. */
%WAVE_FORMAT_OLIGSM                     = &H1000 ' /* Ing C. Olivetti & C., S.p.A. */
%WAVE_FORMAT_OLIADPCM                   = &H1001 ' /* Ing C. Olivetti & C., S.p.A. */
%WAVE_FORMAT_OLICELP                    = &H1002 ' /* Ing C. Olivetti & C., S.p.A. */
%WAVE_FORMAT_OLISBC                     = &H1003 ' /* Ing C. Olivetti & C., S.p.A. */
%WAVE_FORMAT_OLIOPR                     = &H1004 ' /* Ing C. Olivetti & C., S.p.A. */
%WAVE_FORMAT_LH_CODEC                   = &H1100 ' /* Lernout & Hauspie */
%WAVE_FORMAT_NORRIS                     = &H1400 ' /* Norris Communications, Inc. */
%WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS    = &H1500 ' /* AT&T Labs, Inc. */
%WAVE_FORMAT_MPEG_ADTS_AAC              = &H1600 ' /* Microsoft Corporation */
%WAVE_FORMAT_MPEG_RAW_AAC               = &H1601 ' /* Microsoft Corporation */
%WAVE_FORMAT_MPEG_LOAS                  = &H1602 ' /* Microsoft Corporation (MPEG-4 Audio Transport Streams (LOAS/LATM) */
%WAVE_FORMAT_NOKIA_MPEG_ADTS_AAC        = &H1608 ' /* Microsoft Corporation */
%WAVE_FORMAT_NOKIA_MPEG_RAW_AAC         = &H1609 ' /* Microsoft Corporation */
%WAVE_FORMAT_VODAFONE_MPEG_ADTS_AAC     = &H160A ' /* Microsoft Corporation */
%WAVE_FORMAT_VODAFONE_MPEG_RAW_AAC      = &H160B ' /* Microsoft Corporation */
%WAVE_FORMAT_MPEG_HEAAC                 = &H1610 ' /* Microsoft Corporation (MPEG-2 AAC or MPEG-4 HE-AAC v1/v2 streams with any payload (ADTS, ADIF, LOAS/LATM, RAW). Format block includes MP4 AudioSpecificConfig() -- see HEAACWAVEFORMAT below */
%WAVE_FORMAT_DVM                        = &H2000 ' /* FAST Multimedia AG */
%WAVE_FORMAT_DTS2                       = &H2001

#IF NOT %DEF(%WAVE_FORMAT_EXTENSIBLE)
%WAVE_FORMAT_EXTENSIBLE                 = &HFFFE ' /* Microsoft */
#ENDIF

'//
'//  New wave format development should be based on the
'//  WAVEFORMATEXTENSIBLE structure. WAVEFORMATEXTENSIBLE allows you to
'//  avoid having to register a new format tag with Microsoft. However, if
'//  you must still define a new format tag, the WAVE_FORMAT_DEVELOPMENT
'//  format tag can be used during the development phase of a new wave
'//  format.  Before shipping, you MUST acquire an official format tag from
'//  Microsoft.
'//
%WAVE_FORMAT_DEVELOPMENT        = &HFFFF??

'#endif /* NONEWWAVE */
#ENDIF   ' #IF NOT %DEF(%NONEWWAVE)

#IF NOT %DEF(%WAVE_FORMAT_PCM)

'/* general waveform format structure (information common to all formats) */
' // Size = 14 bytes
TYPE WAVEFORMAT BYTE
   wFormatTag      AS WORD    ' WORD    wFormatTag;        /* format type */
   nChannels       AS WORD    ' WORD    nChannels;         /* number of channels (i.e. mono, stereo...) */
   nSamplesPerSec  AS DWORD   ' DWORD   nSamplesPerSec;    /* sample rate */
   nAvgBytesPerSec AS DWORD   ' DWORD   nAvgBytesPerSec;   /* for buffer estimation */
   nBlockAlign     AS WORD    ' WORD    nBlockAlign;       /* block size of data */
END TYPE

'/* flags for wFormatTag field of WAVEFORMAT */
%WAVE_FORMAT_PCM    = 1

'/* specific waveform format structure for PCM data */
' // Size = 16 bytes
TYPE PCMWAVEFORMAT BYTE
   wf             AS WAVEFORMAT   ' WAVEFORMAT  wf
   wBitsPerSample AS WORD         ' WORD        wBitsPerSample
END TYPE

#ENDIF   ' #IF NOT %DEF(%WAVE_FORMAT_PCM)

'/* general extended waveform format structure
'   Use this for all NON PCM formats
'   (information common to all formats)
'*/
#IF NOT %DEF(%WAVEFORMATEX)
    %WAVEFORMATEX = 1

' // Size = 18 bytes
TYPE WAVEFORMATEX BYTE
   wFormatTag      AS WORD    ' WORD    wFormatTag;        /* format type */
   nChannels       AS WORD    ' WORD    nChannels;         /* number of channels (i.e. mono, stereo...) */
   nSamplesPerSec  AS DWORD   ' DWORD   nSamplesPerSec;    /* sample rate */
   nAvgBytesPerSec AS DWORD   ' DWORD   nAvgBytesPerSec;   /* for buffer estimation */
   nBlockAlign     AS WORD    ' WORD    nBlockAlign;       /* block size of data */
   wBitsPerSample  AS WORD    ' WORD    wBitsPerSample;    /* Number of bits per sample of mono data */
   cbSize          AS WORD    ' WORD    cbSize;            /* The count in bytes of the size of extra information (after cbSize) */
END TYPE

#ENDIF   ' #IF NOT %DEF(%WAVEFORMATEX)

#IF %DEF(%GUID_DEFINED)

'#if !defined(_NTRTL_)
'#if !defined( DEFINE_GUIDEX )
'    #ifndef DEFINE_GUIDEX
'        #define DEFINE_GUIDEX(name) EXTERN_C const CDECL GUID name
'    #endif // !defined(DEFINE_GUIDEX)

'    #ifndef STATICGUIDOF
'        #define STATICGUIDOF(guid) STATIC_##guid
'    #endif // !defined(STATICGUIDOF)
'#endif // !defined ( DEFINE_GUIDEX )
'#endif // !defined(_NTRTL_)

'#if !defined( DEFINE_GUIDSTRUCT )
'#if defined(__cplusplus) && _MSC_VER >= 1100
'#define DEFINE_GUIDSTRUCT(g, n) struct __declspec(uuid(g)) n
'#define DEFINE_GUIDNAMED(n) __uuidof(struct n)
'#else // !defined(__cplusplus)
'#define DEFINE_GUIDSTRUCT(g, n) DEFINE_GUIDEX(n)
'#define DEFINE_GUIDNAMED(n) n
'#endif // !defined(__cplusplus)
'#endif

'#if !defined( DEFINE_WAVEFORMATEX_GUID )
'#define DEFINE_WAVEFORMATEX_GUID(x) (USHORT)(x), 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
'#endif

'#if !defined( STATIC_KSDATAFORMAT_SUBTYPE_PCM )
'#define STATIC_KSDATAFORMAT_SUBTYPE_PCM\
'    DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_PCM)
'DEFINE_GUIDSTRUCT("00000001-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_PCM);
'#define KSDATAFORMAT_SUBTYPE_PCM DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_PCM)
'#endif
$KSDATAFORMAT_SUBTYPE_PCM = GUID$("{00000001-0000-0010-8000-00aa00389b71}")

'#if !defined(RC_INVOKED) /* RC complains about long symbols in #ifs */
'#if !defined( STATIC_KSDATAFORMAT_SUBTYPE_IEEE_FLOAT )
'#define STATIC_KSDATAFORMAT_SUBTYPE_IEEE_FLOAT\
'    DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_IEEE_FLOAT)
'DEFINE_GUIDSTRUCT("00000003-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_IEEE_FLOAT);
'#define KSDATAFORMAT_SUBTYPE_IEEE_FLOAT DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
'#endif
$KSDATAFORMAT_SUBTYPE_IEEE_FLOAT = GUID$("{00000003-0000-0010-8000-00aa00389b71}")

'#if !defined( STATIC_KSDATAFORMAT_SUBTYPE_WAVEFORMATEX )
'#define STATIC_KSDATAFORMAT_SUBTYPE_WAVEFORMATEX\
'    0x00000000L, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
'DEFINE_GUIDSTRUCT("00000000-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_WAVEFORMATEX);
'#define KSDATAFORMAT_SUBTYPE_WAVEFORMATEX DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_WAVEFORMATEX)
'#endif
'#endif
$KSDATAFORMAT_SUBTYPE_WAVEFORMATEX = GUID$("{00000000-0000-0010-8000-00aa00389b71}")

'#if !defined( INIT_WAVEFORMATEX_GUID )
'#define INIT_WAVEFORMATEX_GUID(Guid, x)\
'{\
'    *(Guid) = KSDATAFORMAT_SUBTYPE_WAVEFORMATEX;\
'    (Guid)->Data1 = (USHORT)(x);\
'}
'#endif

'#if !defined( EXTRACT_WAVEFORMATEX_ID )
'#define EXTRACT_WAVEFORMATEX_ID(Guid)\
'    (USHORT)((Guid)->Data1)
'#endif

'#if !defined( IS_VALID_WAVEFORMATEX_GUID )
'#define IS_VALID_WAVEFORMATEX_GUID(Guid)\
'    (!memcmp(((PUSHORT)&KSDATAFORMAT_SUBTYPE_WAVEFORMATEX) + 1, ((PUSHORT)(Guid)) + 1, sizeof(GUID) - sizeof(USHORT)))
'#endif

'//
'//  New wave format development should be based on the
'//  WAVEFORMATEXTENSIBLE structure. WAVEFORMATEXTENSIBLE allows you to
'//  avoid having to register a new format tag with Microsoft. Simply
'//  define a new GUID value for the WAVEFORMATEXTENSIBLE.SubFormat field
'//  and use WAVE_FORMAT_EXTENSIBLE in the
'//  WAVEFORMATEXTENSIBLE.Format.wFormatTag field.
'//
#IF NOT %DEF(%WAVEFORMATEXTENSIBLE)
'typedef struct {
'    WAVEFORMATEX    Format;
'    union {
'        WORD wValidBitsPerSample;       /* bits of precision  */
'        WORD wSamplesPerBlock;          /* valid if wBitsPerSample==0 */
'        WORD wReserved;                 /* If neither applies, set to zero. */
'    } Samples;
'    DWORD           dwChannelMask;      /* which channels are */
'                                        /* present in stream  */
'    GUID            SubFormat;
'} WAVEFORMATEXTENSIBLE, *PWAVEFORMATEXTENSIBLE;

' // Size = 2 bytes
UNION WAVEFORMATEXTENSIBLE_Samples_UNION BYTE
   wValidBitsPerSample AS WORD   ' WORD wValidBitsPerSample;       /* bits of precision  */
   wSamplesPerBlock    AS WORD   ' WORD wSamplesPerBlock;          /* valid if wBitsPerSample==0 */
   wReserved           AS WORD   ' WORD wReserved;                 /* If neither applies, set to zero. */
END UNION

' // Size = 40 bytes
TYPE WAVEFORMATEXTENSIBLE BYTE
   Format        AS WAVEFORMATEX
   WAVEFORMATEXTENSIBLE_Samples_UNION
   dwChannelMask AS DWORD     ' DWORD dwChannelMask /* which channels are present in stream  */
   SubFormat     AS GUID      ' UID   SubFormat
END TYPE

#ENDIF   ' #IF NOT %DEF(%WAVEFORMATEXTENSIBLE)

#ENDIF   ' #IF %DEF(%GUID_DEFINED)

#IF NOT %DEF(%SPEAKER_POSITIONS)
    %SPEAKER_POSITIONS = 1

%SPEAKER_FRONT_LEFT              = &H1???
%SPEAKER_FRONT_RIGHT             = &H2???
%SPEAKER_FRONT_CENTER            = &H4???
%SPEAKER_LOW_FREQUENCY           = &H8???
%SPEAKER_BACK_LEFT               = &H10???
%SPEAKER_BACK_RIGHT              = &H20???
%SPEAKER_FRONT_LEFT_OF_CENTER    = &H40???
%SPEAKER_FRONT_RIGHT_OF_CENTER   = &H80???
%SPEAKER_BACK_CENTER             = &H100???
%SPEAKER_SIDE_LEFT               = &H200???
%SPEAKER_SIDE_RIGHT              = &H400???
%SPEAKER_TOP_CENTER              = &H800???
%SPEAKER_TOP_FRONT_LEFT          = &H1000???
%SPEAKER_TOP_FRONT_CENTER        = &H2000???
%SPEAKER_TOP_FRONT_RIGHT         = &H4000???
%SPEAKER_TOP_BACK_LEFT           = &H8000???
%SPEAKER_TOP_BACK_CENTER         = &H10000???
%SPEAKER_TOP_BACK_RIGHT          = &H20000???

'// Bit mask locations reserved for future use
%SPEAKER_RESERVED                = &H7FFC0000???

'// Used to specify that any possible permutation of speaker configurations
%SPEAKER_ALL                     = &H80000000???

#ENDIF   ' #IF NOT %DEF(%SPEAKER_POSITIONS)

#IF NOT %DEF(%NONEWWAVE)

'/* Define data for MS ADPCM */

' // Size = 4 bytes
TYPE ADPCMCOEFSET BYTE
   iCoef1 AS INTEGER   ' short   iCoef1
   iCoef2 AS INTEGER   ' short   iCoef2
END TYPE

'/*
' *  this pragma disables the warning issued by the Microsoft C compiler
' *  when using a zero size array as place holder when compiling for
' *  C++ or with -W4.
' *
' */

'#ifdef _MSC_VER
'#pragma warning(disable:4200)
'#endif

' // Size = 22 bytes
TYPE ADPCMWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
   wNumCoef         AS WORD           ' WORD            wNumCoef
   ' aCoef(0)         AS ADPCMCOEFSET   ' ADPCMCOEFSET    aCoef[1]
END TYPE

'//
'//  Microsoft's DRM structure definitions
'//

' // Size = 42 bytes
TYPE DRMWAVEFORMAT BYTE
   wfx         AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wReserved   AS WORD           ' WORD            wReserved
   ulContentId AS DWORD          ' ULONG           ulContentId
   wfxSecure   AS WAVEFORMATEX   ' WAVEFORMATEX    wfxSecure
END TYPE

'//
'//  Intel's DVI ADPCM structure definitions
'//
'//      for WAVE_FORMAT_DVI_ADPCM   (0x0011)
'//
'//

' // Size = 20 bytes
TYPE DVIADPCMWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'//
'//  IMA endorsed ADPCM structure definitions--note that this is exactly
'//  the same format as Intel's DVI ADPCM.
'//
'//      for WAVE_FORMAT_IMA_ADPCM   (0x0011)
'//
'//

' // Size = 20 bytes
TYPE IMAADPCMWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'/*
'//VideoLogic's Media Space ADPCM Structure definitions
'// for  WAVE_FORMAT_MEDIASPACE_ADPCM    (0x0012)
'//
'//
'*/

' // Size = 20 bytes
TYPE MEDIASPACEADPCMWAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wRevision AS WORD           ' WORD    wRevision
END TYPE

'//
'//  Sierra Semiconductor
'//
'//      for WAVE_FORMAT_SIERRA_ADPCM   (0x0013)
'//
'//

' // Size = 20 bytes
TYPE SIERRAADPCMWAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX  ' WAVEFORMATEX    wfx
   wRevision AS WORD          ' WORD            wRevision
END TYPE

'//
'//  Antex Electronics  structure definitions
'//
'//      for WAVE_FORMAT_G723_ADPCM   (0x0014)
'//
'//

' // Size = 22 bytes
TYPE G723_ADPCMWAVEFORMAT BYTE
   wfx           AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   cbExtraSize   AS WORD           ' WORD            cbExtraSize
   nAuxBlockSize AS WORD           ' WORD            nAuxBlockSize
END TYPE

'//
'//  DSP Solutions (formerly DIGISPEECH) structure definitions
'//
'//      for WAVE_FORMAT_DIGISTD   (0x0015)
'//
'//

' // Size = 18 bytes
TYPE DIGISTDWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX  ' WAVEFORMATEX    wfx
END TYPE

'//
'//  DSP Solutions (formerly DIGISPEECH) structure definitions
'//
'//      for WAVE_FORMAT_DIGIFIX   (0x0016)
'//
'//

' // Size = 18 bytes
TYPE DIGIFIXWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//   Dialogic Corporation
'// WAVEFORMAT_DIALOGIC_OKI_ADPCM   (0x0017)
'//

' // Size = 18 bytes
TYPE DIALOGICOKIADPCMWAVEFORMAT BYTE
   ewf AS WAVEFORMATEX   ' WAVEFORMATEX    ewf
END TYPE

'//
'//  Yamaha Compression's ADPCM structure definitions
'//
'//      for WAVE_FORMAT_YAMAHA_ADPCM   (0x0020)
'//
'//

'typedef struct yamaha_adpmcwaveformat_tag {
'        WAVEFORMATEX    wfx;
'} YAMAHA_ADPCMWAVEFORMAT;

' // Size = 18 bytes
TYPE YAMAHA_ADPCMWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Speech Compression's Sonarc structure definitions
'//
'//      for WAVE_FORMAT_SONARC   (0x0021)
'//
'//

' // Size = 20 bytes
TYPE SONARCWAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wCompType AS WORD           ' WORD            wCompType
END TYPE

'//
'//  DSP Groups's TRUESPEECH structure definitions
'//
'//      for WAVE_FORMAT_DSPGROUP_TRUESPEECH   (0x0022)
'//
'//

' // Size = 50 bytes
TYPE TRUESPEECHWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wRevision        AS WORD           ' WORD            wRevision
   nSamplesPerBlock AS WORD           ' WORD            nSamplesPerBlock
   abReserved(27)   AS BYTE           ' BYTE            abReserved[28]
END TYPE

'//
'//  Echo Speech Corp structure definitions
'//
'//      for WAVE_FORMAT_ECHOSC1   (0x0023)
'//
'//

' // Size = 18 bytes
TYPE ECHOSC1WAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Audiofile Inc.structure definitions
'//
'//      for WAVE_FORMAT_AUDIOFILE_AF36   (0x0024)
'//
'//

' // Size = 18 bytes
TYPE AUDIOFILE_AF36WAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Audio Processing Technology structure definitions
'//
'//      for WAVE_FORMAT_APTX   (0x0025)
'//
'//

' // Size = 18 bytes
TYPE APTXWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Audiofile Inc.structure definitions
'//
'//      for WAVE_FORMAT_AUDIOFILE_AF10   (0x0026)
'//
'//

' // Size = 18 bytes
TYPE AUDIOFILE_AF10WAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'/* Dolby's AC-2 wave format structure definition
'           WAVE_FORMAT_DOLBY_AC2    (0x0030)*/
'//

' // Size = 20 bytes
TYPE DOLBYAC2WAVEFORMAT BYTE
   wfx          AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   nAuxBitsCode AS WORD           ' WORD            nAuxBitsCode
END TYPE

'/*Microsoft's */
'// WAVE_FORMAT_GSM 610           0x0031
'//

' // Size = 20 bytes
TYPE GSM610WAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'//
'//      Antex Electronics Corp
'//
'//      for WAVE_FORMAT_ADPCME                  (0x0033)
'//
'//

'typedef struct adpcmewaveformat_tag {
'        WAVEFORMATEX    wfx;
'        WORD            wSamplesPerBlock;
'} ADPCMEWAVEFORMAT;

' // Size = 20 bytes
TYPE ADPCMEWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX
   wSamplesPerBlock AS WORD
END TYPE

'/*       Control Resources Limited */
'// WAVE_FORMAT_CONTROL_RES_VQLPC                 0x0034
'//
'typedef struct contres_vqlpcwaveformat_tag {

' // Size = 20 bytes
TYPE CONTRESVQLPCWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'//
'//
'//
'//      for WAVE_FORMAT_DIGIREAL                   (0x0035)
'//
'//

' // Size = 20 bytes
TYPE DIGIREALWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'//
'//  DSP Solutions
'//
'//      for WAVE_FORMAT_DIGIADPCM   (0x0036)
'//
'//

' // Size = 20 bytes
TYPE DIGIADPCMWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'/*       Control Resources Limited */
'// WAVE_FORMAT_CONTROL_RES_CR10          0x0037
'//

' // Size = 20 bytes
TYPE CONTRESCR10WAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'//
'//  Natural Microsystems
'//
'//      for WAVE_FORMAT_NMS_VBXADPCM   (0x0038)
'//
'//

' // Size = 20 bytes
TYPE NMS_VBXADPCMWAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wSamplesPerBlock AS WORD           ' WORD            wSamplesPerBlock
END TYPE

'//
'//  Antex Electronics  structure definitions
'//
'//      for WAVE_FORMAT_G721_ADPCM   (0x0040)
'//
'//

' // Size = 20 bytes
TYPE G721_ADPCMWAVEFORMAT BYTE
   wfx           AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   nAuxBlockSize AS WORD           ' WORD            nAuxBlockSize
END TYPE

'//
'//
'// Microsoft MPEG audio WAV definition
'//
'/*  MPEG-1 audio wave format (audio layer only).   (0x0050)   */

' // Size = 40 bytes
TYPE MPEG1WAVEFORMAT BYTE
   wfx           AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   fwHeadLayer   AS WORD           ' WORD            fwHeadLayer
   dwHeadBitrate AS DWORD          ' DWORD           dwHeadBitrate
   fwHeadMode    AS WORD           ' WORD            fwHeadMode
   fwHeadModeExt AS WORD           ' WORD            fwHeadModeExt
   wHeadEmphasis AS WORD           ' WORD            wHeadEmphasis
   fwHeadFlags   AS WORD           ' WORD            fwHeadFlags
   dwPTSLow      AS DWORD          ' DWORD           dwPTSLow
   dwPTSHigh     AS DWORD          ' DWORD           dwPTSHigh
END TYPE

%ACM_MPEG_LAYER1            = &H0001??
%ACM_MPEG_LAYER2            = &H0002??
%ACM_MPEG_LAYER3            = &H0004??
%ACM_MPEG_STEREO            = &H0001??
%ACM_MPEG_JOINTSTEREO       = &H0002??
%ACM_MPEG_DUALCHANNEL       = &H0004??
%ACM_MPEG_SINGLECHANNEL     = &H0008??
%ACM_MPEG_PRIVATEBIT        = &H0001??
%ACM_MPEG_COPYRIGHT         = &H0002??
%ACM_MPEG_ORIGINALHOME      = &H0004??
%ACM_MPEG_PROTECTIONBIT     = &H0008??
%ACM_MPEG_ID_MPEG1          = &H0010??

'//
'// MPEG Layer3 WAVEFORMATEX structure
'// for WAVE_FORMAT_MPEGLAYER3 (0x0055)
'//
%MPEGLAYER3_WFX_EXTRA_BYTES = 12

'// WAVE_FORMAT_MPEGLAYER3 format sructure
'//

' // Size = 30 bytes
TYPE MPEGLAYER3WAVEFORMAT BYTE
   wfx             AS WAVEFORMATEX   ' WAVEFORMATEX  wfx
   wID             AS WORD           ' WORD          wID
   fdwFlags        AS DWORD          ' DWORD         fdwFlags
   nBlockSize      AS WORD           ' WORD          nBlockSize
   nFramesPerBlock AS WORD           ' WORD          nFramesPerBlock
   nCodecDelay     AS WORD           ' WORD          nCodecDelay
END TYPE

'//==========================================================================;

%MPEGLAYER3_ID_UNKNOWN           = 0
%MPEGLAYER3_ID_MPEG              = 1
%MPEGLAYER3_ID_CONSTANTFRAMESIZE = 2

%MPEGLAYER3_FLAG_PADDING_ISO     = &H00000000???
%MPEGLAYER3_FLAG_PADDING_ON      = &H00000001???
%MPEGLAYER3_FLAG_PADDING_OFF     = &H00000002???

'/* ==========================================================================

'      For WAVE_FORMAT_MPEG_HEAAC (0x1610)


' "MPEG-2" in the comments below refers to ISO/IEC 13818-7 (MPEG-2 AAC spec).
' "MPEG-4" in the comments below refers to ISO/IEC 14496-3 (MPEG-4 Audio spec).

' The following defines the format block to be used for MPEG-2 AAC or MPEG-4 HE-AAC v1/v2 streams.
' When setting media type attributes in Media Foundation (MF) objects, this will appear in conjunction with
' major type MFMediaType_Audio and sub type MFAudioFormat_AAC (=MEDIASUBTYPE_MPEG_HEAAC).
' The format block structure HEAACWAVEFORMAT is defined below.  It starts with the structure
' HEAACWAVEINFO (which is an extension of WAVEFORMATEX), followed by AudioSpecificConfig() as
' defined by ISO/IEC 14496-3 (MPEG-4 audio). Since the length of AudioSpecificConfig() may vary
' from one stream to another, this is a variable size format block.

' The WAVEFORMATEX fields describe the properties of the core AAC stream,
' without SBR/PS extensions (if exists). This is the description of the WAVEFORMATEX fields:

' wfx.wFormatTag - Set this to WAVE_FORMAT_MPEG_HEAAC (0x1610).

' wfx.nChannels - Total number of channels in core AAC stream (including LFE if exists).
' This might be different than the decoded number of channels if the MPEG-4 Parametric Stereo (PS)
' tool exists. If unknown, set to zero.

' wfx.nSamplesPerSec - Sampling rate of core AAC stream. This will be one of the 12 supported
' sampling rate between 8000 and 96000 Hz, as defined in MPEG-2.  This might be different than
' the decoded sampling rate if the MPEG-4 Spectral Band Replication (SBR) tool exists.
' If not know in advance, the sampling rate can be extracted from:
' - the 4-bit sampling_frequency_index field in adts_fixed_header(), or
' - program_config_element() in adif_header for MPEG-2 streams, or
' - the 4-bit samplingFrequencyIndex field in AudioSpecificConfig() for MPEG-4 streams.

' wfx.nAvgBytesPerSec - The average bytes per second calculated based on the average bit rate of
' the compressed stream. This value may be used by parsers to seek into a particular time offset
' in the stream. It may also be used by applications to determine roughly how much buffer length to allocate.
' If this is not known in advance, this value can be estimated by parsing some (or all) of the
' compressed HE-AAC frames and calculating bit rate based on average compressed frame size.
' If unknown, set to zero.

' wfx.nBlockAlign - Set this to 1.

' wfx.wBitsPerSample - Desired bit depth of the decoded PCM. If unknown, set to zero.

' wfx.cbSize - Set this to 12 (=sizeof(HEAACWAVEINFO)-sizeof(WAVEFORMATEX)) plus the
' size of AudioSpecificConfig() in bytes.

' ===================================

' How do we parse this format block? assume pbBuff is the address of the first
' byte in the format block. We do the following:

' HEAACWAVEINFO* pwfInfo = (HEAACWAVEINFO *)pbBuff;

' if ( 0 == pwfInfo->wStructType)
' {
'    HEAACWAVEFORMAT* pwf = (HEAACWAVEFORMAT*)pbBuff;

'    // All HEAACWAVEFORMAT fields can now be accessed through pwf
'    // ...

'    //
'    // To parse AudioSpecifiConfig(), write a function such as
'    // ParseAudioSpecificConfig(BYTE *pbASC, DWORD dwASCLen),
'    // and call:
'    //
'    DWORD dwASCLen = pwf->wfInfo.wfx.cbSize - sizeof(HEAACWAVEINFO) + sizeof(WAVEFORMATEX);

'    ParseAudioSpecificConfig(pwf->pbAudioSpecificConfig, dwASCLen);
' }
' else
' {
'    // Reserved
' }
'*/

'typedef struct heaacwaveinfo_tag {

'    // Defines core AAC properties. See description above. WAVEFORMATEX is of size 18 bytes.
'    WAVEFORMATEX wfx;

'    // Defines the payload type
'    // 0-RAW.  The stream contains raw_data_block() elements only.
'    // 1-ADTS. The stream contains an adts_sequence(), as defined by MPEG-2.
'    // 2-ADIF. The stream contains an adif_sequence(), as defined by MPEG-2.
'    // 3-LOAS. The stream contains an MPEG-4 audio transport stream with a
'    //         synchronization layer LOAS and a multiplex layer LATM.
'    // All other codes are reserved.
'    WORD  wPayloadType;

'    // This is the 8-bit field audioProfileLevelIndication available in the
'    // MPEG-4 object descriptor.  It is an indication (as defined in MPEG-4 audio)
'    // of the audio profile and level required to process the content associated
'    // with this stream. For example values 0x28-0x2B correspond to AAC Profile,
'    // values 0x2C-0x2F correspond to HE-AAC profile and 0x30-0x33 for HE-AAC v2 profile.
'    // If unknown, set to zero or 0xFE ("no audio profile specified").
'    WORD  wAudioProfileLevelIndication;

'    // Defines the data that follows this structure. Currently only one data type is supported:
'    // 0- AudioSpecificConfig() (as defined by MPEG-4 Audio, ISO/IEC 14496-3) will follow this structure.
'    //    wfx.cbSize will indicate the total length including AudioSpecificConfig().
'    //    Use HEAACWAVEFORMAT to gain easy access to the address of the first byte of
'    //    AudioSpecificConfig() for parsing.
'    //    Typical values for the size of AudioSpecificConfig (ASC) are:
'    //    - 2 bytes for AAC or HE-AAC v1/v2 with implicit signaling of SBR,
'    //    - 5 bytes for HE-AAC v1 with explicit signaling of SBR,
'    //    - 7 bytes for HE-AAC v2 with explicit signaling of SBR and PS.
'    //    The size may be longer than 7 bytes if the 4-bit channelConfiguration field in ASC is zero,
'    //    which means program_config_element() is present in ASC.
'    //
'    // All other codes are reserved.
'    WORD  wStructType;

'    // Set these to zero
'    WORD  wReserved1;
'    DWORD dwReserved2;

'} HEAACWAVEINFO;  // this structure has a size of 30 bytes

'typedef HEAACWAVEINFO       *PHEAACWAVEINFO;
'typedef HEAACWAVEINFO NEAR *NPHEAACWAVEINFO;
'typedef HEAACWAVEINFO FAR  *LPHEAACWAVEINFO;

' // Size = 30 bytes
TYPE HEAACWAVEINFO BYTE   ' // this structure has a size of 30 bytes
   wfx                          AS WAVEFORMATEX
   wPayloadType                 AS WORD           ' WORD
   wAudioProfileLevelIndication AS WORD           ' WORD
   wStructType                  AS WORD           ' WORD
   wReserved1                   AS WORD           ' WORD
   dwReserved2                  AS DWORD          ' DWORD
END TYPE

'//
'// This structure describes the format block for wStructType=0
'//
' // Size = 31 bytes
TYPE HEAACWAVEFORMAT BYTE   ' // This structure has a size of 31 bytes
   wfInfo                   AS HEAACWAVEINFO   ' // This structure has a size of 30 bytes
   pbAudioSpecificConfig(0) AS BYTE   '  // First byte of AudioSpecificConfig()
END TYPE


'//==========================================================================

'//
'//  Windows Media Audio (common)
'//
'//

%MM_MSFT_ACM_WMAUDIO = 39

%WMAUDIO_BITS_PER_SAMPLE = 16   ' // just an uncompressed size...
%WMAUDIO_MAX_CHANNELS    = 2

'//
'//  Windows Media Audio V1 (a.k.a. "MSAudio")
'//
'//      for WAVE_FORMAT_MSAUDIO1        (0x0160)
'//
'//
%MM_MSFT_ACM_MSAUDIO1 = 39

' // Size = 22 bytes
TYPE MSAUDIO1WAVEFORMAT BYTE
   wfx              AS WAVEFORMATEX
   wSamplesPerBlock AS WORD   ' WORD // only counting "new" samples "= half of what will be used due to overlapping
   wEncodeOptions   AS WORD   ' WORD
END TYPE

%MSAUDIO1_BITS_PER_SAMPLE    = %WMAUDIO_BITS_PER_SAMPLE
%MSAUDIO1_MAX_CHANNELS       = %WMAUDIO_MAX_CHANNELS
'#define MSAUDIO1_WFX_EXTRA_BYTES    = (sizeof(MSAUDIO1WAVEFORMAT) - sizeof(WAVEFORMATEX))

'//
'//  Windows Media Audio V2
'//
'//      for WAVE_FORMAT_WMAUDIO2        (0x0161)
'//
'//

%MM_MSFT_ACM_WMAUDIO2 = 101

' // Size = 28 bytes
TYPE WMAUDIO2WAVEFORMAT BYTE
   wfx AS WAVEFORMATEX
   dwSamplesPerBlock AS DWORD   ' DWORD // only counting "new" samples "= half of what will be used due to overlapping
   wEncodeOptions    AS WORD    ' WORD
   dwSuperBlockAlign AS DWORD   ' DWORD // the big size...  should be multiples of wfx.nBlockAlign.
END TYPE

%WMAUDIO2_BITS_PER_SAMPLE   = %WMAUDIO_BITS_PER_SAMPLE
%WMAUDIO2_MAX_CHANNELS      = %WMAUDIO_MAX_CHANNELS
'#define WMAUDIO2_WFX_EXTRA_BYTES    (sizeof(WMAUDIO2WAVEFORMAT) - sizeof(WAVEFORMATEX))

'//
'//  Windows Media Audio V3
'//
'//      for WAVE_FORMAT_WMAUDIO3        (0x0162)
'//
'//

' // Size = 36 bytes
TYPE WMAUDIO3WAVEFORMAT BYTE
   wfx                 AS WAVEFORMATEX
   wValidBitsPerSample AS WORD   ' WORD // bits of precision
   dwChannelMask       AS DWORD   ' DWORD // which channels are present in stream
   dwReserved1         AS DWORD
   dwReserved2         AS DWORD
   wEncodeOptions      AS WORD
   wReserved3          AS WORD
END TYPE

'#define WMAUDIO3_WFX_EXTRA_BYTES    (sizeof(WMAUDIO3WAVEFORMAT) - sizeof(WAVEFORMATEX))


'//
'//  Creative's ADPCM structure definitions
'//
'//      for WAVE_FORMAT_CREATIVE_ADPCM   (0x0200)
'//
'//

' // Size = 20 bytes
TYPE CREATIVEADPCMWAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wRevision AS WORD           ' WORD            wRevision
END TYPE

'//
'//    Creative FASTSPEECH
'// WAVEFORMAT_CREATIVE_FASTSPEECH8   (0x0202)
'//

' // Size = 20 bytes
TYPE CREATIVEFASTSPEECH8WAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wRevision AS WORD           ' WORD wRevision
END TYPE

'//
'//    Creative FASTSPEECH
'// WAVEFORMAT_CREATIVE_FASTSPEECH10   (0x0203)
'//

' // Size = 20 bytes
TYPE CREATIVEFASTSPEECH10WAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wRevision AS WORD           ' WORD wRevision
END TYPE

'//
'//  Fujitsu FM Towns 'SND' structure
'//
'//      for WAVE_FORMAT_FMMTOWNS_SND   (0x0300)
'//
'//

' // Size = 20 bytes
TYPE FMTOWNS_SND_WAVEFORMAT BYTE
   wfx       AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
   wRevision AS WORD           ' WORD            wRevision
END TYPE

'//
'//  Olivetti structure
'//
'//      for WAVE_FORMAT_OLIGSM   (0x1000)
'//
'//

' // Size = 18 bytes
TYPE OLIGSMWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Olivetti structure
'//
'//      for WAVE_FORMAT_OLIADPCM   (0x1001)
'//
'//

' // Size = 18 bytes
TYPE OLIADPCMWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Olivetti structure
'//
'//      for WAVE_FORMAT_OLICELP   (0x1002)
'//
'//

' // Size = 18 bytes
TYPE OLICELPWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Olivetti structure
'//
'//      for WAVE_FORMAT_OLISBC   (0x1003)
'//
'//

' // Size = 18 bytes
TYPE OLISBCWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Olivetti structure
'//
'//      for WAVE_FORMAT_OLIOPR   (0x1004)
'//
'//

' // Size = 18 bytes
TYPE OLIOPRWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//
'//  Crystal Semiconductor IMA ADPCM format
'//
'//      for WAVE_FORMAT_CS_IMAADPCM   (0x0039)
'//
'//

' // Size = 18 bytes
TYPE CSIMAADPCMWAVEFORMAT BYTE
   wfx AS WAVEFORMATEX   ' WAVEFORMATEX    wfx
END TYPE

'//==========================================================================;
'//
'//  ACM Wave Filters
'//
'//
'//==========================================================================;
#IF NOT %DEF(%ACM_WAVEFILTER)
    %ACM_WAVEFILTER = 1

%WAVE_FILTER_UNKNOWN       = &H0000???
%WAVE_FILTER_DEVELOPMENT   = &HFFFF???

' // Size = 32 bytes
TYPE WAVEFILTER BYTE
   cbStruct      AS DWORD   ' DWORD   cbStruct      /* Size of the filter in bytes */
   dwFilterTag   AS DWORD   ' DWORD   dwFilterTag   /* filter type */
   fdwFilter     AS DWORD   ' DWORD   fdwFilter     /* Flags for the filter (Universal Dfns) */
   dwReserved(4) AS DWORD   ' DWORD   dwReserved[5] /* Reserved for system use */
END TYPE

'#endif  /* _ACM_WAVEFILTER */
#ENDIF   ' #IF NOT %DEF(%ACM_WAVEFILTER)


#IF NOT %DEF(%WAVE_FILTER_VOLUME)
%WAVE_FILTER_VOLUME     = &H0001

' // Size = 36 bytes
TYPE VOLUMEWAVEFILTER BYTE
   wfltr    AS WAVEFILTER   ' WAVEFILTER      wfltr
   dwVolume AS DWORD        ' DWORD           dwVolume
END TYPE

#ENDIF   ' #IF NOT %DEF(%WAVE_FILTER_VOLUME)


#IF NOT %DEF(%WAVE_FILTER_ECHO)
%WAVE_FILTER_ECHO      = &H0002

' // Size = 40 bytes
TYPE ECHOWAVEFILTER BYTE
   wfltr    AS WAVEFILTER   ' WAVEFILTER      wfltr
   dwVolume AS DWORD        ' DWORD           dwVolume
   dwDelay  AS DWORD        ' DWORD           dwDelay
END TYPE

#ENDIF   ' #IF NOT %DEF(%WAVE_FILTER_ECHO)

'/* ------------------------------------------------------------------------------ */
'//
'// New RIFF WAVE Chunks
'//

'#define RIFFWAVE_inst   mmioFOURCC('i','n','s','t')
%RIFFWAVE_inst  = &H74736E69   '  mmioFOURCC('i','n','s','t')

' // Size = 7 bytes
TYPE tag_s_RIFFWAVE_inst BYTE
   bUnshiftedNote AS BYTE         ' BYTE    bUnshiftedNote
   chFineTune     AS STRING * 1   ' char    chFineTune
   chGain         AS STRING * 1   ' char    chGain
   bLowNote       AS BYTE         ' BYTE    bLowNote
   bHighNote      AS BYTE         ' BYTE    bHighNote
   bLowVelocity   AS BYTE         ' BYTE    bLowVelocity
   bHighVelocity  AS BYTE         ' BYTE    bHighVelocity
END TYPE

MACRO s_RIFFWAVE_inst = tag_s_RIFFWAVE_INST

#ENDIF   ' #IF NOT %DEF(%NONEWWAVE)

'/* ------------------------------------------------------------------------------ */
'//
'// New RIFF Forms
'//

#IF NOT %DEF(%NONEWRIFF)

'/* RIFF AVI */

'//
'// AVI file format is specified in a seperate file (AVIFMT.H),
'// which is available in the VfW and Win 32 SDK
'//

'/* RIFF CPPO */

%RIFFCPPO       = &H4F505043  ' mmioFOURCC('C','P','P','O')

%RIFFCPPO_objr  = &H726A626F  ' mmioFOURCC('o','b','j','r')
%RIFFCPPO_obji  = &H696A626F  ' mmioFOURCC('o','b','j','i')

%RIFFCPPO_clsr  = &H72736C63  ' mmioFOURCC('c','l','s','r')
%RIFFCPPO_clsi  = &H69736C63  ' mmioFOURCC('c','l','s','i')

%RIFFCPPO_mbr   = &H2072626D  ' mmioFOURCC('m','b','r',' ')

%RIFFCPPO_char  = &H72616863  ' mmioFOURCC('c','h','a','r')

%RIFFCPPO_byte  = &H65747952  ' mmioFOURCC('b','y','t','e')
%RIFFCPPO_int   = &H20746E69  ' mmioFOURCC('i','n','t',' ')
%RIFFCPPO_word  = &H64726F77  ' mmioFOURCC('w','o','r','d')
%RIFFCPPO_long  = &H676E6F6C  ' mmioFOURCC('l','o','n','g')
%RIFFCPPO_dwrd  = &H64727764  ' mmioFOURCC('d','w','r','d')
%RIFFCPPO_flt   = &H20746C66  ' mmioFOURCC('f','l','t',' ')
%RIFFCPPO_dbl   = &H206C6264  ' mmioFOURCC('d','b','l',' ')
%RIFFCPPO_str   = &H20727473  ' mmioFOURCC('s','t','r',' ')

#ENDIF   ' #IF NOT %DEF(%NONEWRIFF)

'/*
'//////////////////////////////////////////////////////////////////////////
'//
'// DIB Compression Defines
'//
'*/

#IF NOT %DEF(%BI_BITFIELDS)
%BI_BITFIELDS  = 3
#ENDIF

#IF NOT %DEF(%QUERYDIBSUPPORT)

%QUERYDIBSUPPORT = 3073
%QDI_SETDIBITS   = &H0001
%QDI_GETDIBITS   = &H0002
%QDI_DIBTOSCREEN = &H0004
%QDI_STRETCHDIB  = &H0008

#ENDIF   ' #IF NOT %DEF(%QUERYDIBSUPPORT)

#IF NOT %DEF(%NOBITMAP)
'/* Structure definitions */

' // Size = 44 bytes
TYPE EXBMINFOHEADER BYTE
   bmi AS BITMAPINFOHEADER    ' BITMAPINFOHEADER    bmi
   ' /* extended BITMAPINFOHEADER fields */
   biExtDataOffset AS DWORD   ' DWORD   biExtDataOffset
   ' /* Other stuff will go here */
   ' /* ... */
   ' /* Format-specific information */
   ' /* biExtDataOffset points here */
END TYPE

#ENDIF   ' #IF NOT %DEF(%NOBITMAP)

'/* New DIB Compression Defines */

%BICOMP_IBMULTIMOTION   = &H49544C55   ' mmioFOURCC('U', 'L', 'T', 'I')
%BICOMP_IBMPHOTOMOTION  = &H4F4D4850   ' mmioFOURCC('P', 'H', 'M', 'O')
%BICOMP_CREATIVEYUV     = &H76757953   ' mmioFOURCC('c', 'y', 'u', 'v')

#IF NOT %DEF(%NOJPEGDIB)
'#ifndef NOJPEGDIB

'/* New DIB Compression Defines */
%JPEG_DIB               = &H4745504A   ' mmioFOURCC('J','P','E','G')    /* Still image JPEG DIB biCompression */
%MJPG_DIB               = &H47504A4D   ' mmioFOURCC('M','J','P','G')    /* Motion JPEG DIB biCompression     */

'/* JPEGProcess Definitions */
%JPEG_PROCESS_BASELINE         =  0     ' /* Baseline DCT */

'/* AVI File format extensions */
%AVIIF_CONTROLFRAME            =  &H00000200&    ' /* This is a control frame */

'    /* JIF Marker byte pairs in JPEG Interchange Format sequence */
%JIFMK_SOF0    = &HFFC0   ' /* SOF Huff  - Baseline DCT*/
%JIFMK_SOF1    = &HFFC1   ' /* SOF Huff  - Extended sequential DCT*/
%JIFMK_SOF2    = &HFFC2   ' /* SOF Huff  - Progressive DCT*/
%JIFMK_SOF3    = &HFFC3   ' /* SOF Huff  - Spatial (sequential) lossless*/
%JIFMK_SOF5    = &HFFC5   ' /* SOF Huff  - Differential sequential DCT*/
%JIFMK_SOF6    = &HFFC6   ' /* SOF Huff  - Differential progressive DCT*/
%JIFMK_SOF7    = &HFFC7   ' /* SOF Huff  - Differential spatial*/
%JIFMK_JPG     = &HFFC8   ' /* SOF Arith - Reserved for JPEG extensions*/
%JIFMK_SOF9    = &HFFC9   ' /* SOF Arith - Extended sequential DCT*/
%JIFMK_SOF10   = &HFFCA   ' /* SOF Arith - Progressive DCT*/
%JIFMK_SOF11   = &HFFCB   ' /* SOF Arith - Spatial (sequential) lossless*/
%JIFMK_SOF13   = &HFFCD   ' /* SOF Arith - Differential sequential DCT*/
%JIFMK_SOF14   = &HFFCE   ' /* SOF Arith - Differential progressive DCT*/
%JIFMK_SOF15   = &HFFCF   ' /* SOF Arith - Differential spatial*/
%JIFMK_DHT     = &HFFC4   ' /* Define Huffman Table(s) */
%JIFMK_DAC     = &HFFCC   ' /* Define Arithmetic coding conditioning(s) */
%JIFMK_RST0    = &HFFD0   ' /* Restart with modulo 8 count 0 */
%JIFMK_RST1    = &HFFD1   ' /* Restart with modulo 8 count 1 */
%JIFMK_RST2    = &HFFD2   ' /* Restart with modulo 8 count 2 */
%JIFMK_RST3    = &HFFD3   ' /* Restart with modulo 8 count 3 */
%JIFMK_RST4    = &HFFD4   ' /* Restart with modulo 8 count 4 */
%JIFMK_RST5    = &HFFD5   ' /* Restart with modulo 8 count 5 */
%JIFMK_RST6    = &HFFD6   ' /* Restart with modulo 8 count 6 */
%JIFMK_RST7    = &HFFD7   ' /* Restart with modulo 8 count 7 */
%JIFMK_SOI     = &HFFD8   ' /* Start of Image */
%JIFMK_EOI     = &HFFD9   ' /* End of Image */
%JIFMK_SOS     = &HFFDA   ' /* Start of Scan */
%JIFMK_DQT     = &HFFDB   ' /* Define quantization Table(s) */
%JIFMK_DNL     = &HFFDC   ' /* Define Number of Lines */
%JIFMK_DRI     = &HFFDD   ' /* Define Restart Interval */
%JIFMK_DHP     = &HFFDE   ' /* Define Hierarchical progression */
%JIFMK_EXP     = &HFFDF   ' /* Expand Reference Component(s) */
%JIFMK_APP0    = &HFFE0   ' /* Application Field 0*/
%JIFMK_APP1    = &HFFE1   ' /* Application Field 1*/
%JIFMK_APP2    = &HFFE2   ' /* Application Field 2*/
%JIFMK_APP3    = &HFFE3   ' /* Application Field 3*/
%JIFMK_APP4    = &HFFE4   ' /* Application Field 4*/
%JIFMK_APP5    = &HFFE5   ' /* Application Field 5*/
%JIFMK_APP6    = &HFFE6   ' /* Application Field 6*/
%JIFMK_APP7    = &HFFE7   ' /* Application Field 7*/
%JIFMK_JPG0    = &HFFF0   ' /* Reserved for JPEG extensions */
%JIFMK_JPG1    = &HFFF1   ' /* Reserved for JPEG extensions */
%JIFMK_JPG2    = &HFFF2   ' /* Reserved for JPEG extensions */
%JIFMK_JPG3    = &HFFF3   ' /* Reserved for JPEG extensions */
%JIFMK_JPG4    = &HFFF4   ' /* Reserved for JPEG extensions */
%JIFMK_JPG5    = &HFFF5   ' /* Reserved for JPEG extensions */
%JIFMK_JPG6    = &HFFF6   ' /* Reserved for JPEG extensions */
%JIFMK_JPG7    = &HFFF7   ' /* Reserved for JPEG extensions */
%JIFMK_JPG8    = &HFFF8   ' /* Reserved for JPEG extensions */
%JIFMK_JPG9    = &HFFF9   ' /* Reserved for JPEG extensions */
%JIFMK_JPG10   = &HFFFA   ' /* Reserved for JPEG extensions */
%JIFMK_JPG11   = &HFFFB   ' /* Reserved for JPEG extensions */
%JIFMK_JPG12   = &HFFFC   ' /* Reserved for JPEG extensions */
%JIFMK_JPG13   = &HFFFD   ' /* Reserved for JPEG extensions */
%JIFMK_COM     = &HFFFE   ' /* Comment */
%JIFMK_TEM     = &HFF01   ' /* for temp private use arith code */
%JIFMK_RES     = &HFF02   ' /* Reserved */
%JIFMK_00      = &HFF00   ' /* Zero stuffed byte - entropy data */
%JIFMK_FF      = &HFFFF   ' /* Fill byte */

'/* JPEGColorSpaceID Definitions */
%JPEG_Y        = 1       ' /* Y only component of YCbCr */
%JPEG_YCbCr    = 2       ' /* YCbCr as define by CCIR 601 */
%JPEG_RGB      = 3       ' /* 3 component RGB */

'/* Structure definitions */

' // Size = 24 bytes
TYPE JPEGINFOHEADER BYTE
   ' /* compression-specific fields */
   ' /* these fields are defined for 'JPEG' and 'MJPG' */
   JPEGSize          AS DWORD   ' DWORD JPEGSize
   JPEGProcess       AS DWORD   ' DWORD JPEGProcess
   ' /* Process specific fields */
   JPEGColorSpaceID  AS DWORD   ' DWORD JPEGColorSpaceID
   JPEGBitsPerSample AS DWORD   ' DWORD JPEGBitsPerSample
   JPEGHSubSampling  AS DWORD   ' DWORD JPEGHSubSampling
   JPEGVSubSampling  AS DWORD   ' DWORD JPEGVSubSampling
END TYPE

#IF %DEF(%MJPGDHTSEG_STORAGE)

'/* Default DHT Segment */

'MJPGDHTSEG_STORAGE BYTE MJPGDHTSeg[0x1A4] = {
' /* JPEG DHT Segment for YCrCb omitted from MJPG data */
'0xFF,0xC4,0x01,0xA2,
'0x00,0x00,0x01,0x05,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
'0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x01,0x00,0x03,0x01,0x01,0x01,0x01,
'0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
'0x08,0x09,0x0A,0x0B,0x10,0x00,0x02,0x01,0x03,0x03,0x02,0x04,0x03,0x05,0x05,0x04,0x04,0x00,
'0x00,0x01,0x7D,0x01,0x02,0x03,0x00,0x04,0x11,0x05,0x12,0x21,0x31,0x41,0x06,0x13,0x51,0x61,
'0x07,0x22,0x71,0x14,0x32,0x81,0x91,0xA1,0x08,0x23,0x42,0xB1,0xC1,0x15,0x52,0xD1,0xF0,0x24,
'0x33,0x62,0x72,0x82,0x09,0x0A,0x16,0x17,0x18,0x19,0x1A,0x25,0x26,0x27,0x28,0x29,0x2A,0x34,
'0x35,0x36,0x37,0x38,0x39,0x3A,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x53,0x54,0x55,0x56,
'0x57,0x58,0x59,0x5A,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x73,0x74,0x75,0x76,0x77,0x78,
'0x79,0x7A,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,
'0x9A,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,
'0xBA,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,
'0xDA,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,
'0xF8,0xF9,0xFA,0x11,0x00,0x02,0x01,0x02,0x04,0x04,0x03,0x04,0x07,0x05,0x04,0x04,0x00,0x01,
'0x02,0x77,0x00,0x01,0x02,0x03,0x11,0x04,0x05,0x21,0x31,0x06,0x12,0x41,0x51,0x07,0x61,0x71,
'0x13,0x22,0x32,0x81,0x08,0x14,0x42,0x91,0xA1,0xB1,0xC1,0x09,0x23,0x33,0x52,0xF0,0x15,0x62,
'0x72,0xD1,0x0A,0x16,0x24,0x34,0xE1,0x25,0xF1,0x17,0x18,0x19,0x1A,0x26,0x27,0x28,0x29,0x2A,
'0x35,0x36,0x37,0x38,0x39,0x3A,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x53,0x54,0x55,0x56,
'0x57,0x58,0x59,0x5A,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x73,0x74,0x75,0x76,0x77,0x78,
'0x79,0x7A,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x92,0x93,0x94,0x95,0x96,0x97,0x98,
'0x99,0x9A,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,
'0xB9,0xBA,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,
'0xD9,0xDA,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,
'0xF9,0xFA
'};

'/* End DHT default */
#ENDIF   ' #IF %DEF(%MJPGDHTSEG_STORAGE)

'/* End JPEG */
#ENDIF   ' #IF NOT %DEF(%NOJPEGDIB)

'/* ------------------------------------------------------------------------------ */
'//
'// Defined IC types
'//

#IF NOT %DEF(%NONEWIC)

#IF NOT %DEF(%ICTYPE_VIDEO)
%ICTYPE_VIDEO   = &H63646976   ' mmioFOURCC('v', 'i', 'd', 'c')
%ICTYPE_AUDIO   = &H63647561   ' mmioFOURCC('a', 'u', 'd', 'c')
#ENDIF

#ENDIF   ' #IF NOT %DEF(%NONEWIC)

'/*
'//   Misc. FOURCC registration
'*/

'/* Sierra Semiconductor: RDSP- Confidential RIFF file format
'//       for the storage and downloading of DSP
'//       code for Audio and communications devices.
'*/
%FOURCC_RDSP = &H50534452   ' mmioFOURCC('R', 'D', 'S', 'P')

#IF NOT %DEF(%MMNOMIXER)
%MIXERCONTROL_CONTROLTYPE_SRS_MTS         = (%MIXERCONTROL_CONTROLTYPE_BOOLEAN + 6)
%MIXERCONTROL_CONTROLTYPE_SRS_ONOFF       = (%MIXERCONTROL_CONTROLTYPE_BOOLEAN + 7)
%MIXERCONTROL_CONTROLTYPE_SRS_SYNTHSELECT = (%MIXERCONTROL_CONTROLTYPE_BOOLEAN + 8)
#ENDIF
