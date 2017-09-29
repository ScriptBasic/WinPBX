' ########################################################################################
' Microsoft Windows
' File: imapi2.inc
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: IMAPI2
' Version: 1.0, Locale ID = 0
' Description: Microsoft IMAPI2 Base Functionality
' Path: C:\Windows\system32\imapi2.dll
' Library GUID: {2735412F-7F64-5B0F-8F00-5D77AFBE261E}
' ########################################################################################

#INCLUDE THIS ONCE
%IMAPI2_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"

'//
'// IMAPIv2 version information for TYPELib loading
'//
%IMAPILib2_MajorVersion = 1
%IMAPILib2_MinorVersion = 0
$LIBID_IMAPI2 = GUID$("{2735412F-7F64-5B0F-8F00-5D77AFBE261E}")
$LIBID_IMAPILib2 = $LIBID_IMAPI2

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {2735412A-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2Data1 = "IMAPI2.MsftDiscFormat2Data.1"
' CLSID = {2735412B-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2Erase1 = "IMAPI2.MsftDiscFormat2Erase.1"
' CLSID = {27354128-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2RawCD1 = "IMAPI2.MsftDiscFormat2RawCD.1"
' CLSID = {27354129-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2TrackAtOnce1 = "IMAPI2.MsftDiscFormat2TrackAtOnce.1"
' CLSID = {2735412E-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscMaster21 = "IMAPI2.MsftDiscMaster2.1"
' CLSID = {2735412D-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscRecorder21 = "IMAPI2.MsftDiscRecorder2.1"
' CLSID = {25983561-9D65-49CE-B335-40630D901227}
$PROGID_MsftRawCDImageCreator1 = "IMAPI2.MsftRawCDImageCreator.1"
' CLSID = {27354125-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamConcatenate1 = "IMAPI2.MsftStreamConcatenate.1"
' CLSID = {27354124-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamInterleave1 = "IMAPI2.MsftStreamInterleave.1"
' CLSID = {27354126-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamPrng0011 = "IMAPI2.MsftStreamPrng001.1"
' CLSID = {27354127-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamZero1 = "IMAPI2.MsftStreamZero.1"
' CLSID = {2735412C-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftWriteEngine21 = "IMAPI2.MsftWriteEngine2.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {2735412A-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2Data = "IMAPI2.MsftDiscFormat2Data"
' CLSID = {2735412B-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2Erase = "IMAPI2.MsftDiscFormat2Erase"
' CLSID = {27354128-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2RawCD = "IMAPI2.MsftDiscFormat2RawCD"
' CLSID = {27354129-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscFormat2TrackAtOnce = "IMAPI2.MsftDiscFormat2TrackAtOnce"
' CLSID = {2735412E-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscMaster2 = "IMAPI2.MsftDiscMaster2"
' CLSID = {2735412D-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftDiscRecorder2 = "IMAPI2.MsftDiscRecorder2"
' CLSID = {25983561-9D65-49CE-B335-40630D901227}
$PROGID_MsftRawCDImageCreator = "IMAPI2.MsftRawCDImageCreator"
' CLSID = {27354125-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamConcatenate = "IMAPI2.MsftStreamConcatenate"
' CLSID = {27354124-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamInterleave = "IMAPI2.MsftStreamInterleave"
' CLSID = {27354126-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamPrng001 = "IMAPI2.MsftStreamPrng001"
' CLSID = {27354127-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftStreamZero = "IMAPI2.MsftStreamZero"
' CLSID = {2735412C-7F64-5B0F-8F00-5D77AFBE261E}
$PROGID_MsftWriteEngine2 = "IMAPI2.MsftWriteEngine2"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MsftMultisessionRandomWrite = GUID$("{B507CA24-2204-11DD-966A-001AA01BBC58}")
$CLSID_MsftMultisessionSequential = GUID$("{27354122-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftWriteSpeedDescriptor = GUID$("{27354123-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftDiscFormat2Data = GUID$("{2735412A-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftDiscFormat2Erase = GUID$("{2735412B-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftDiscFormat2RawCD = GUID$("{27354128-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftDiscFormat2TrackAtOnce = GUID$("{27354129-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftDiscMaster2 = GUID$("{2735412E-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftDiscRecorder2 = GUID$("{2735412D-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftRawCDImageCreator = GUID$("{25983561-9D65-49CE-B335-40630D901227}")
$CLSID_MsftStreamConcatenate = GUID$("{27354125-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftStreamInterleave = GUID$("{27354124-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftStreamPrng001 = GUID$("{27354126-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftStreamZero = GUID$("{27354127-7F64-5B0F-8F00-5D77AFBE261E}")
$CLSID_MsftWriteEngine2 = GUID$("{2735412C-7F64-5B0F-8F00-5D77AFBE261E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DDiscFormat2DataEvents = GUID$("{2735413C-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_DDiscFormat2EraseEvents = GUID$("{2735413A-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_DDiscFormat2RawCDEvents = GUID$("{27354142-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_DDiscFormat2TrackAtOnceEvents = GUID$("{2735413F-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_DDiscMaster2Events = GUID$("{27354131-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_DWriteEngine2Events = GUID$("{27354137-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IBlockRange = GUID$("{B507CA25-2204-11DD-966A-001AA01BBC58}")
$IID_IBlockRangeList = GUID$("{B507CA26-2204-11DD-966A-001AA01BBC58}")
$IID_IBurnVerification = GUID$("{D2FFD834-958B-426D-8470-2A13879C6A91}")
$IID_IDiscFormat2 = GUID$("{27354152-8F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2Data = GUID$("{27354153-9F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2DataEventArgs = GUID$("{2735413D-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2Erase = GUID$("{27354156-8F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2RawCD = GUID$("{27354155-8F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2RawCDEventArgs = GUID$("{27354143-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2TrackAtOnce = GUID$("{27354154-8F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscFormat2TrackAtOnceEventArgs = GUID$("{27354140-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscMaster2 = GUID$("{27354130-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscRecorder2 = GUID$("{27354133-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IDiscRecorder2Ex = GUID$("{27354132-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IMultisession = GUID$("{27354150-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IMultisessionRandomWrite = GUID$("{B507CA23-2204-11DD-966A-001AA01BBC58}")
$IID_IMultisessionSequential = GUID$("{27354151-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IMultisessionSequential2 = GUID$("{B507CA22-2204-11DD-966A-001AA01BBC58}")
$IID_IRawCDImageCreator = GUID$("{25983550-9D65-49CE-B335-40630D901227}")
$IID_IRawCDImageTrackInfo = GUID$("{25983551-9D65-49CE-B335-40630D901227}")
$IID_IStreamConcatenate = GUID$("{27354146-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IStreamInterleave = GUID$("{27354147-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IStreamPseudoRandomBased = GUID$("{27354145-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IWriteEngine2 = GUID$("{27354135-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IWriteEngine2EventArgs = GUID$("{27354136-7F64-5B0F-8F00-5D77AFBE261E}")
$IID_IWriteSpeedDescriptor = GUID$("{27354144-7F64-5B0F-8F00-5D77AFBE261E}")

%IMAPI_SECTOR_SIZE = 2048

%IMAPI2_DEFAULT_COMMAND_TIMEOUT = 10

' ========================================================================================
' IMAPI_MEDIA_PHYSICAL_TYPE enum
' Physical type of the optical media
' ========================================================================================

%IMAPI_MEDIA_TYPE_UNKNOWN                               = 0
%IMAPI_MEDIA_TYPE_CDROM                                 = &H1
%IMAPI_MEDIA_TYPE_CDR                                   = &H2
%IMAPI_MEDIA_TYPE_CDRW                                  = &H3
%IMAPI_MEDIA_TYPE_DVDROM                                = &H4
%IMAPI_MEDIA_TYPE_DVDRAM                                = &H5
%IMAPI_MEDIA_TYPE_DVDPLUSR                              = &H6
%IMAPI_MEDIA_TYPE_DVDPLUSRW                             = &H7
%IMAPI_MEDIA_TYPE_DVDPLUSR_DUALLAYER                    = &H8
%IMAPI_MEDIA_TYPE_DVDDASHR                              = &H9
%IMAPI_MEDIA_TYPE_DVDDASHRW                             = &HA
%IMAPI_MEDIA_TYPE_DVDDASHR_DUALLAYER                    = &HB
%IMAPI_MEDIA_TYPE_DISK                                  = &HC
%IMAPI_MEDIA_TYPE_DVDPLUSRW_DUALLAYER                   = &HD
%IMAPI_MEDIA_TYPE_HDDVDROM                              = &HE
%IMAPI_MEDIA_TYPE_HDDVDR                                = &HF
%IMAPI_MEDIA_TYPE_HDDVDRAM                              = &H10
%IMAPI_MEDIA_TYPE_BDROM                                 = &H11
%IMAPI_MEDIA_TYPE_BDR                                   = &H12
%IMAPI_MEDIA_TYPE_BDRE                                  = &H13
%IMAPI_MEDIA_TYPE_MAX                                   = &H13

' ========================================================================================
' IMAPI_MEDIA_WRITE_PROTECT_STATE enum
' Detected write protection type of the media
' ========================================================================================

%IMAPI_WRITEPROTECTED_UNTIL_POWERDOWN                   = &H1
%IMAPI_WRITEPROTECTED_BY_CARTRIDGE                      = &H2
%IMAPI_WRITEPROTECTED_BY_MEDIA_SPECIFIC_REASON          = &H4
%IMAPI_WRITEPROTECTED_BY_SOFTWARE_WRITE_PROTECT         = &H8
%IMAPI_WRITEPROTECTED_BY_DISC_CONTROL_BLOCK             = &H10
%IMAPI_WRITEPROTECTED_READ_ONLY_MEDIA                   = &H4000

' ========================================================================================
' IMAPI_READ_TRACK_ADDRESS_TYPE enum
' Address type provided for reading track information
' ========================================================================================

%IMAPI_READ_TRACK_ADDRESS_TYPE_LBA                      = 0
%IMAPI_READ_TRACK_ADDRESS_TYPE_TRACK                    = 1
%IMAPI_READ_TRACK_ADDRESS_TYPE_SESSION                  = 2

' ========================================================================================
' IMAPI_MODE_PAGE_REQUEST_TYPE enum
' Mode page data type to request
' ========================================================================================

%IMAPI_MODE_PAGE_REQUEST_TYPE_CURRENT_VALUES            = 0
%IMAPI_MODE_PAGE_REQUEST_TYPE_CHANGEABLE_VALUES         = 1
%IMAPI_MODE_PAGE_REQUEST_TYPE_DEFAULT_VALUES            = 2
%IMAPI_MODE_PAGE_REQUEST_TYPE_SAVED_VALUES              = 3

' ========================================================================================
' IMAPI_MODE_PAGE_TYPE enum
' Type of the mode page data
' ========================================================================================

%IMAPI_MODE_PAGE_TYPE_READ_WRITE_ERROR_RECOVERY         = &H1
%IMAPI_MODE_PAGE_TYPE_MRW                               = &H3
%IMAPI_MODE_PAGE_TYPE_WRITE_PARAMETERS                  = &H5
%IMAPI_MODE_PAGE_TYPE_CACHING                           = &H8
%IMAPI_MODE_PAGE_TYPE_INFORMATIONAL_EXCEPTIONS          = &H1C
%IMAPI_MODE_PAGE_TYPE_TIMEOUT_AND_PROTECT               = &H1D
%IMAPI_MODE_PAGE_TYPE_POWER_CONDITION                   = &H1A
%IMAPI_MODE_PAGE_TYPE_LEGACY_CAPABILITIES               = &H2A

' ========================================================================================
' IMAPI_FEATURE_PAGE_TYPE enum
' Type of the feature page data
' ========================================================================================

%IMAPI_FEATURE_PAGE_TYPE_PROFILE_LIST                   = 0
%IMAPI_FEATURE_PAGE_TYPE_CORE                           = &H1
%IMAPI_FEATURE_PAGE_TYPE_MORPHING                       = &H2
%IMAPI_FEATURE_PAGE_TYPE_REMOVABLE_MEDIUM               = &H3
%IMAPI_FEATURE_PAGE_TYPE_WRITE_PROTECT                  = &H4
%IMAPI_FEATURE_PAGE_TYPE_RANDOMLY_READABLE              = &H10
%IMAPI_FEATURE_PAGE_TYPE_CD_MULTIREAD                   = &H1D
%IMAPI_FEATURE_PAGE_TYPE_CD_READ                        = &H1E
%IMAPI_FEATURE_PAGE_TYPE_DVD_READ                       = &H1F
%IMAPI_FEATURE_PAGE_TYPE_RANDOMLY_WRITABLE              = &H20
%IMAPI_FEATURE_PAGE_TYPE_INCREMENTAL_STREAMING_WRITABLE = &H21
%IMAPI_FEATURE_PAGE_TYPE_SECTOR_ERASABLE                = &H22
%IMAPI_FEATURE_PAGE_TYPE_FORMATTABLE                    = &H23
%IMAPI_FEATURE_PAGE_TYPE_HARDWARE_DEFECT_MANAGEMENT     = &H24
%IMAPI_FEATURE_PAGE_TYPE_WRITE_ONCE                     = &H25
%IMAPI_FEATURE_PAGE_TYPE_RESTRICTED_OVERWRITE           = &H26
%IMAPI_FEATURE_PAGE_TYPE_CDRW_CAV_WRITE                 = &H27
%IMAPI_FEATURE_PAGE_TYPE_MRW                            = &H28
%IMAPI_FEATURE_PAGE_TYPE_ENHANCED_DEFECT_REPORTING      = &H29
%IMAPI_FEATURE_PAGE_TYPE_DVD_PLUS_RW                    = &H2A
%IMAPI_FEATURE_PAGE_TYPE_DVD_PLUS_R                     = &H2B
%IMAPI_FEATURE_PAGE_TYPE_RIGID_RESTRICTED_OVERWRITE     = &H2C
%IMAPI_FEATURE_PAGE_TYPE_CD_TRACK_AT_ONCE               = &H2D
%IMAPI_FEATURE_PAGE_TYPE_CD_MASTERING                   = &H2E
%IMAPI_FEATURE_PAGE_TYPE_DVD_DASH_WRITE                 = &H2F
%IMAPI_FEATURE_PAGE_TYPE_DOUBLE_DENSITY_CD_READ         = &H30
%IMAPI_FEATURE_PAGE_TYPE_DOUBLE_DENSITY_CD_R_WRITE      = &H31
%IMAPI_FEATURE_PAGE_TYPE_DOUBLE_DENSITY_CD_RW_WRITE     = &H32
%IMAPI_FEATURE_PAGE_TYPE_LAYER_JUMP_RECORDING           = &H33
%IMAPI_FEATURE_PAGE_TYPE_CD_RW_MEDIA_WRITE_SUPPORT      = &H37
%IMAPI_FEATURE_PAGE_TYPE_BD_PSEUDO_OVERWRITE            = &H38
%IMAPI_FEATURE_PAGE_TYPE_DVD_PLUS_R_DUAL_LAYER          = &H3B
%IMAPI_FEATURE_PAGE_TYPE_BD_READ                        = &H40
%IMAPI_FEATURE_PAGE_TYPE_BD_WRITE                       = &H41
%IMAPI_FEATURE_PAGE_TYPE_HD_DVD_READ                    = &H50
%IMAPI_FEATURE_PAGE_TYPE_HD_DVD_WRITE                   = &H51
%IMAPI_FEATURE_PAGE_TYPE_POWER_MANAGEMENT               = &H100
%IMAPI_FEATURE_PAGE_TYPE_SMART                          = &H101
%IMAPI_FEATURE_PAGE_TYPE_EMBEDDED_CHANGER               = &H102
%IMAPI_FEATURE_PAGE_TYPE_CD_ANALOG_PLAY                 = &H103
%IMAPI_FEATURE_PAGE_TYPE_MICROCODE_UPDATE               = &H104
%IMAPI_FEATURE_PAGE_TYPE_TIMEOUT                        = &H105
%IMAPI_FEATURE_PAGE_TYPE_DVD_CSS                        = &H106
%IMAPI_FEATURE_PAGE_TYPE_REAL_TIME_STREAMING            = &H107
%IMAPI_FEATURE_PAGE_TYPE_LOGICAL_UNIT_SERIAL_NUMBER     = &H108
%IMAPI_FEATURE_PAGE_TYPE_MEDIA_SERIAL_NUMBER            = &H109
%IMAPI_FEATURE_PAGE_TYPE_DISC_CONTROL_BLOCKS            = &H10A
%IMAPI_FEATURE_PAGE_TYPE_DVD_CPRM                       = &H10B
%IMAPI_FEATURE_PAGE_TYPE_FIRMWARE_INFORMATION           = &H10C
%IMAPI_FEATURE_PAGE_TYPE_AACS                           = &H10D
%IMAPI_FEATURE_PAGE_TYPE_VCPS                           = &H110

' ========================================================================================
' IMAPI_PROFILE_TYPE enum
' Type of the profile in feature page data
' ========================================================================================

%IMAPI_PROFILE_TYPE_INVALID                             = 0
%IMAPI_PROFILE_TYPE_NON_REMOVABLE_DISK                  = &H1
%IMAPI_PROFILE_TYPE_REMOVABLE_DISK                      = &H2
%IMAPI_PROFILE_TYPE_MO_ERASABLE                         = &H3
%IMAPI_PROFILE_TYPE_MO_WRITE_ONCE                       = &H4
%IMAPI_PROFILE_TYPE_AS_MO                               = &H5
%IMAPI_PROFILE_TYPE_CDROM                               = &H8
%IMAPI_PROFILE_TYPE_CD_RECORDABLE                       = &H9
%IMAPI_PROFILE_TYPE_CD_REWRITABLE                       = &HA
%IMAPI_PROFILE_TYPE_DVDROM                              = &H10
%IMAPI_PROFILE_TYPE_DVD_DASH_RECORDABLE                 = &H11
%IMAPI_PROFILE_TYPE_DVD_RAM                             = &H12
%IMAPI_PROFILE_TYPE_DVD_DASH_REWRITABLE                 = &H13
%IMAPI_PROFILE_TYPE_DVD_DASH_RW_SEQUENTIAL              = &H14
%IMAPI_PROFILE_TYPE_DVD_DASH_R_DUAL_SEQUENTIAL          = &H15
%IMAPI_PROFILE_TYPE_DVD_DASH_R_DUAL_LAYER_JUMP          = &H16
%IMAPI_PROFILE_TYPE_DVD_PLUS_RW                         = &H1A
%IMAPI_PROFILE_TYPE_DVD_PLUS_R                          = &H1B
%IMAPI_PROFILE_TYPE_DDCDROM                             = &H20
%IMAPI_PROFILE_TYPE_DDCD_RECORDABLE                     = &H21
%IMAPI_PROFILE_TYPE_DDCD_REWRITABLE                     = &H22
%IMAPI_PROFILE_TYPE_DVD_PLUS_RW_DUAL                    = &H2A
%IMAPI_PROFILE_TYPE_DVD_PLUS_R_DUAL                     = &H2B
%IMAPI_PROFILE_TYPE_BD_ROM                              = &H40
%IMAPI_PROFILE_TYPE_BD_R_SEQUENTIAL                     = &H41
%IMAPI_PROFILE_TYPE_BD_R_RANDOM_RECORDING               = &H42
%IMAPI_PROFILE_TYPE_BD_REWRITABLE                       = &H43
%IMAPI_PROFILE_TYPE_HD_DVD_ROM                          = &H50
%IMAPI_PROFILE_TYPE_HD_DVD_RECORDABLE                   = &H51
%IMAPI_PROFILE_TYPE_HD_DVD_RAM                          = &H52
%IMAPI_PROFILE_TYPE_NON_STANDARD                        = &HFFFF

' ========================================================================================
' IMAPI_FORMAT2_DATA_WRITE_ACTION enum
' The current action being performed for the data write
' ========================================================================================

%IMAPI_FORMAT2_DATA_WRITE_ACTION_VALIDATING_MEDIA       = 0
%IMAPI_FORMAT2_DATA_WRITE_ACTION_FORMATTING_MEDIA       = &H1
%IMAPI_FORMAT2_DATA_WRITE_ACTION_INITIALIZING_HARDWARE  = &H2
%IMAPI_FORMAT2_DATA_WRITE_ACTION_CALIBRATING_POWER      = &H3
%IMAPI_FORMAT2_DATA_WRITE_ACTION_WRITING_DATA           = &H4
%IMAPI_FORMAT2_DATA_WRITE_ACTION_FINALIZATION           = &H5
%IMAPI_FORMAT2_DATA_WRITE_ACTION_COMPLETED              = &H6
%IMAPI_FORMAT2_DATA_WRITE_ACTION_VERIFYING              = &H7

' ========================================================================================
' IMAPI_FORMAT2_DATA_MEDIA_STATE enum
' Set of flags to indicate current media state
' ========================================================================================

%IMAPI_FORMAT2_DATA_MEDIA_STATE_UNKNOWN                 = 0
%IMAPI_FORMAT2_DATA_MEDIA_STATE_INFORMATIONAL_MASK      = &HF
%IMAPI_FORMAT2_DATA_MEDIA_STATE_UNSUPPORTED_MASK        = &HFC00
%IMAPI_FORMAT2_DATA_MEDIA_STATE_OVERWRITE_ONLY          = &H1
%IMAPI_FORMAT2_DATA_MEDIA_STATE_RANDOMLY_WRITABLE       = &H1
%IMAPI_FORMAT2_DATA_MEDIA_STATE_BLANK                   = &H2
%IMAPI_FORMAT2_DATA_MEDIA_STATE_APPENDABLE              = &H4
%IMAPI_FORMAT2_DATA_MEDIA_STATE_FINAL_SESSION           = &H8
%IMAPI_FORMAT2_DATA_MEDIA_STATE_DAMAGED                 = &H400
%IMAPI_FORMAT2_DATA_MEDIA_STATE_ERASE_REQUIRED          = &H800
%IMAPI_FORMAT2_DATA_MEDIA_STATE_NON_EMPTY_SESSION       = &H1000
%IMAPI_FORMAT2_DATA_MEDIA_STATE_WRITE_PROTECTED         = &H2000
%IMAPI_FORMAT2_DATA_MEDIA_STATE_FINALIZED               = &H4000
%IMAPI_FORMAT2_DATA_MEDIA_STATE_UNSUPPORTED_MEDIA       = &H8000

' ========================================================================================
' IMAPI_FORMAT2_TAO_WRITE_ACTION enum
' Current action when writing to CD in Track-at-Once mode
' ========================================================================================

%IMAPI_FORMAT2_TAO_WRITE_ACTION_UNKNOWN                 = 0
%IMAPI_FORMAT2_TAO_WRITE_ACTION_PREPARING               = &H1
%IMAPI_FORMAT2_TAO_WRITE_ACTION_WRITING                 = &H2
%IMAPI_FORMAT2_TAO_WRITE_ACTION_FINISHING               = &H3
%IMAPI_FORMAT2_TAO_WRITE_ACTION_VERIFYING               = &H4

' ========================================================================================
' IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE enum
' Data sector type to use when writing to CD in Disc-At-Once (RAW) mode
' ========================================================================================

%IMAPI_FORMAT2_RAW_CD_SUBCODE_PQ_ONLY                   = &H1
%IMAPI_FORMAT2_RAW_CD_SUBCODE_IS_COOKED                 = &H2
%IMAPI_FORMAT2_RAW_CD_SUBCODE_IS_RAW                    = &H3

' ========================================================================================
' IMAPI_FORMAT2_RAW_CD_WRITE_ACTION enum
' Current action when writing to the CD in Disc-At-Once (RAW) mode
' ========================================================================================

%IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_UNKNOWN              = 0
%IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_PREPARING            = &H1
%IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_WRITING              = &H2
%IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_FINISHING            = &H3

' ========================================================================================
' IMAPI_CD_SECTOR_TYPE enum
' The CD sector type for provided data
' ========================================================================================

%IMAPI_CD_SECTOR_AUDIO                                  = 0
%IMAPI_CD_SECTOR_MODE_ZERO                              = &H1
%IMAPI_CD_SECTOR_MODE1                                  = &H2
%IMAPI_CD_SECTOR_MODE2FORM0                             = &H3
%IMAPI_CD_SECTOR_MODE2FORM1                             = &H4
%IMAPI_CD_SECTOR_MODE2FORM2                             = &H5
%IMAPI_CD_SECTOR_MODE1RAW                               = &H6
%IMAPI_CD_SECTOR_MODE2FORM0RAW                          = &H7
%IMAPI_CD_SECTOR_MODE2FORM1RAW                          = &H8
%IMAPI_CD_SECTOR_MODE2FORM2RAW                          = &H9

' ========================================================================================
' IMAPI_CD_TRACK_DIGITAL_COPY_SETTING enum
' The audio track digital copy setting
' ========================================================================================

%IMAPI_CD_TRACK_DIGITAL_COPY_PERMITTED                  = 0
%IMAPI_CD_TRACK_DIGITAL_COPY_PROHIBITED                 = &H1
%IMAPI_CD_TRACK_DIGITAL_COPY_SCMS                       = &H2

' ========================================================================================
' IMAPI_BURN_VERIFICATION_LEVEL enum
' Burn verification level
' ========================================================================================

%IMAPI_BURN_VERIFICATION_NONE                           = 0
%IMAPI_BURN_VERIFICATION_QUICK                          = 1
%IMAPI_BURN_VERIFICATION_FULL                           = 2

'// begin_wpp config
'// CUSTOM_TYPE(IMAPI_MEDIA_PHYSICAL_TYPE,            ItemEnum(_IMAPI_MEDIA_PHYSICAL_TYPE));
'// CUSTOM_TYPE(IMAPI_MEDIA_WRITE_PROTECT_STATE,      ItemEnum(_IMAPI_MEDIA_WRITE_PROTECT_STATE));
'// CUSTOM_TYPE(IMAPI_READ_TRACK_ADDRESS_TYPE,        ItemEnum(_IMAPI_READ_TRACK_ADDRESS_TYPE));
'// CUSTOM_TYPE(IMAPI_MODE_PAGE_REQUEST_TYPE,         ItemEnum(_IMAPI_MODE_PAGE_REQUEST_TYPE));
'// CUSTOM_TYPE(IMAPI_MODE_PAGE_TYPE,                 ItemEnum(_IMAPI_MODE_PAGE_TYPE));
'// CUSTOM_TYPE(IMAPI_FEATURE_PAGE_TYPE,              ItemEnum(_IMAPI_FEATURE_PAGE_TYPE));
'// CUSTOM_TYPE(IMAPI_PROFILE_TYPE,                   ItemEnum(_IMAPI_PROFILE_TYPE));
'// CUSTOM_TYPE(IMAPI_FORMAT2_DATA_WRITE_ACTION,      ItemEnum(_IMAPI_FORMAT2_DATA_WRITE_ACTION));
'// CUSTOM_TYPE(IMAPI_FORMAT2_DATA_MEDIA_STATE,       ItemEnum(_IMAPI_FORMAT2_DATA_MEDIA_STATE));
'// CUSTOM_TYPE(IMAPI_FORMAT2_TAO_WRITE_ACTION,       ItemEnum(_IMAPI_FORMAT2_TAO_WRITE_ACTION));
'// CUSTOM_TYPE(IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE, ItemEnum(_IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE));
'// CUSTOM_TYPE(IMAPI_FORMAT2_RAW_CD_WRITE_ACTION,    ItemEnum(_IMAPI_FORMAT2_RAW_CD_WRITE_ACTION));
'// CUSTOM_TYPE(IMAPI_CD_SECTOR_DATA_TYPE,            ItemEnum(_IMAPI_CD_SECTOR_TYPE));
'// CUSTOM_TYPE(IMAPI_CD_TRACK_DIGITAL_COPY_SETTING,  ItemEnum(_IMAPI_CD_TRACK_DIGITAL_COPY_SETTING));
'// CUSTOM_TYPE(IMAPI_BURN_VERIFICATION_LEVEL,        ItemEnum(_IMAPI_BURN_VERIFICATION_LEVEL));
'// end_wpp

' ########################################################################################
' Interface name = IDiscMaster2
' IID = {27354130-7F64-5B0F-8F00-5D77AFBE261E}
' IDiscMaster2 is used to get an enumerator for the set of CD/DVD (optical) devices on the system
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDiscMaster2_INTERFACE_DEFINED)
    %IDiscMaster2_INTERFACE_DEFINED = 1

INTERFACE IDiscMaster2 $IID_IDiscMaster2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IEnumVARIANT **ppunk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in LONG index
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET IsSupportedEnvironment <2> ( _          ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscMaster2_INTERFACE_DEFINED__ */

'typedef /* [range] */ ULONG ULONG_IMAPI2_DVD_STRUCTURE;
'typedef /* [range] */ ULONG ULONG_IMAPI2_ADAPTER_DESCRIPTOR;
'typedef /* [range] */ ULONG ULONG_IMAPI2_DEVICE_DESCRIPTOR;
'typedef /* [range] */ ULONG ULONG_IMAPI2_DISC_INFORMATION;
'typedef /* [range] */ ULONG ULONG_IMAPI2_TRACK_INFORMATION;
'typedef /* [range] */ ULONG ULONG_IMAPI2_FEATURE_PAGE;
'typedef /* [range] */ ULONG ULONG_IMAPI2_MODE_PAGE;
'typedef /* [range] */ ULONG ULONG_IMAPI2_ALL_FEATURE_PAGES;
'typedef /* [range] */ ULONG ULONG_IMAPI2_ALL_PROFILES;
'typedef /* [range] */ ULONG ULONG_IMAPI2_ALL_MODE_PAGES;
'typedef /* [range] */ ULONG ULONG_IMAPI2_NONZERO;
'typedef /* [range] */ ULONG ULONG_IMAPI2_NOT_NEGATIVE;

' ########################################################################################
' Interface name = IDiscRecorder2Ex
' IID = {27354132-7F64-5B0F-8F00-5D77AFBE261E}
' Represents a single CD/DVD type device, enabling additional commands requiring advanced marshalling code.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDiscRecorder2Ex_INTERFACE_DEFINED)
    %IDiscRecorder2Ex_INTERFACE_DEFINED = 1

INTERFACE IDiscRecorder2Ex $IID_IDiscRecorder2Ex

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SendCommandNoData ( _                         ' VTable offset = 12
     BYREF Cdb AS BYTE _                                ' __in BYTE *Cdb
   , BYVAL CdbSize AS DWORD _                           ' __in ULONG CdbSize
   , BYREF SenseBuffer AS BYTE _                        ' __out BYTE SenseBuffer[ 18 ]
   , BYVAL Timeout AS DWORD _                           ' __in ULONG Timeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendCommandSendDataToDevice ( _               ' VTable offset = 16
     BYREF Cdb AS BYTE _                                ' __in BYTE *Cdb
   , BYVAL CdbSize AS DWORD _                           ' __in ULONG CdbSize
   , BYREF SenseBuffer AS BYTE _                        ' __out BYTE SenseBuffer[ 18 ]
   , BYVAL Timeout AS DWORD _                           ' __in ULONG Timeout
   , BYREF Buffer AS BYTE _                             ' __in BYTE *Buffer
   , BYVAL BufferSize AS DWORD _                        ' __in ULONG_IMAPI2_NONZERO BufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendCommandGetDataFromDevice ( _              ' VTable offset = 20
     BYREF Cdb AS BYTE _                                ' __in BYTE *Cdb
   , BYVAL CdbSize AS DWORD _                           ' __in ULONG CdbSize
   , BYREF SenseBuffer AS BYTE _                        ' __out BYTE SenseBuffer[ 18 ]
   , BYVAL Timeout AS DWORD _                           ' __in ULONG Timeout
   , BYREF Buffer AS BYTE _                             ' __out BYTE *Buffer
   , BYVAL BufferSize AS DWORD _                        ' __in ULONG BufferSize
   , BYREF BufferFetched AS DWORD _                     ' __out ULONG_IMAPI2_NOT_NEGATIVE *BufferFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadDvdStructure ( _                          ' VTable offset = 24
     BYVAL format AS DWORD _                            ' __in ULONG format
   , BYVAL address AS DWORD _                           ' __in ULONG address
   , BYVAL layer AS DWORD _                             ' __in ULONG layer
   , BYVAL agid AS DWORD _                              ' __in ULONG agid
   , BYREF data AS DWORD _                              ' __out BYTE **data
   , BYREF count AS DWORD _                             ' __out ULONG_IMAPI2_DVD_STRUCTURE *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDvdStructure ( _                          ' VTable offset = 28
     BYVAL format AS DWORD _                            ' __in ULONG format
   , BYREF data AS BYTE _                               ' __in BYTE *data
   , BYVAL count AS DWORD _                             ' __in ULONG_IMAPI2_DVD_STRUCTURE count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterDescriptor ( _                      ' VTable offset = 32
     BYREF data AS DWORD _                              ' __out BYTE **data
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_ADAPTER_DESCRIPTOR *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceDescriptor ( _                       ' VTable offset = 36
     BYREF data AS DWORD _                              ' __out BYTE **data
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_DEVICE_DESCRIPTOR *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDiscInformation ( _                        ' VTable offset = 40
     BYREF discInformation AS DWORD _                   ' __out BYTE **discInformation
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_DISC_INFORMATION *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTrackInformation ( _                       ' VTable offset = 44
     BYVAL address AS DWORD _                           ' __in ULONG address
   , BYVAL addressType AS LONG _                        ' __in IMAPI_READ_TRACK_ADDRESS_TYPE addressType
   , BYREF trackInformation AS DWORD _                  ' __out BYTE **trackInformation
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_TRACK_INFORMATION *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeaturePage ( _                            ' VTable offset = 48
     BYVAL requestedFeature AS LONG _                   ' __in IMAPI_FEATURE_PAGE_TYPE requestedFeature
   , BYVAL currentFeatureOnly AS BYTE _                 ' __in BOOLEAN currentFeatureOnly
   , BYREF featureData AS DWORD _                       ' __out BYTE **featureData
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_FEATURE_PAGE *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModePage ( _                               ' VTable offset = 52
     BYVAL requestedModePage AS LONG _                  ' __in IMAPI_MODE_PAGE_TYPE requestedModePage
   , BYVAL requestType AS LONG _                        ' __in IMAPI_MODE_PAGE_REQUEST_TYPE requestType
   , BYREF modePageData AS DWORD _                      ' __out BYTE **modePageData
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_MODE_PAGE *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetModePage ( _                               ' VTable offset = 56
     BYVAL requestType AS LONG _                        ' __in IMAPI_MODE_PAGE_REQUEST_TYPE requestType
   , BYREF data AS BYTE _                               ' __in BYTE *data
   , BYVAL byteSize AS DWORD _                          ' __in ULONG_IMAPI2_MODE_PAGE byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedFeaturePages ( _                  ' VTable offset = 60
     BYVAL currentFeatureOnly AS BYTE _                 ' __in BOOLEAN currentFeatureOnly
   , BYREF featureData AS LONG _                        ' __out IMAPI_FEATURE_PAGE_TYPE **featureData
   , BYREF byteSize AS DWORD _                          ' __out ULONG_IMAPI2_ALL_FEATURE_PAGES *byteSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedProfiles ( _                      ' VTable offset = 64
     BYVAL currentOnly AS BYTE _                        ' __in BOOLEAN currentOnly
   , BYREF profileTypes AS LONG _                       ' __out IMAPI_PROFILE_TYPE **profileTypes
   , BYREF validProfiles AS DWORD _                     ' __out ULONG_IMAPI2_ALL_PROFILES *validProfiles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedModePages ( _                     ' VTable offset = 68
     BYVAL requestType AS LONG _                        ' __in IMAPI_MODE_PAGE_REQUEST_TYPE requestType
   , BYREF modePageTypes AS LONG _                      ' __out IMAPI_MODE_PAGE_TYPE **modePageTypes
   , BYREF validPages AS DWORD _                        ' __out ULONG_IMAPI2_ALL_MODE_PAGES *validPages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByteAlignmentMask ( _                      ' VTable offset = 72
     BYREF value AS DWORD _                             ' __retval_out ULONG *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaximumNonPageAlignedTransferSize ( _      ' VTable offset = 76
     BYREF value AS DWORD _                             ' __retval_out ULONG *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaximumPageAlignedTransferSize ( _         ' VTable offset = 80
     BYREF value AS DWORD _                             ' __retval_out ULONG *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscRecorder2Ex_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscRecorder2
' IID = {27354133-7F64-5B0F-8F00-5D77AFBE261E}
' Represents a single CD/DVD type device, and enables many common operations via a simplified API.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IDISCRECORDER2_EJECTMEDIA             = &H100
%DISPID_IDISCRECORDER2_CLOSETRAY              = &H101
%DISPID_IDISCRECORDER2_ACQUIREEXCLUSIVEACCESS = &H102
%DISPID_IDISCRECORDER2_RELEASEEXCLUSIVEACCESS = &H103
%DISPID_IDISCRECORDER2_DISABLEMCN             = &H104
%DISPID_IDISCRECORDER2_ENABLEMCN              = &H105
%DISPID_IDISCRECORDER2_INITIALIZEDISCRECORDER = &H106
%DISPID_IDISCRECORDER2_ACTIVEDISCRECORDER     = %DISPID_VALUE
%DISPID_IDISCRECORDER2_VENDORID               = &H201
%DISPID_IDISCRECORDER2_PRODUCTID              = &H202
%DISPID_IDISCRECORDER2_PRODUCTREVISION        = &H203
%DISPID_IDISCRECORDER2_VOLUMENAME             = &H204
%DISPID_IDISCRECORDER2_VOLUMEPATHNAMES        = &H205
%DISPID_IDISCRECORDER2_DEVICECANLOADMEDIA     = &H206
%DISPID_IDISCRECORDER2_LEGACYDEVICENUMBER     = &H207
%DISPID_IDISCRECORDER2_SUPPORTEDFEATUREPAGES  = &H208
%DISPID_IDISCRECORDER2_CURRENTFEATUREPAGES    = &H209
%DISPID_IDISCRECORDER2_SUPPORTEDPROFILES      = &H20A
%DISPID_IDISCRECORDER2_CURRENTPROFILES        = &H20B
%DISPID_IDISCRECORDER2_SUPPORTEDMODEPAGES     = &H20C
%DISPID_IDISCRECORDER2_EXCLUSIVEACCESSOWNER   = &H20D

#IF NOT %DEF(%IDiscRecorder2_INTERFACE_DEFINED)
    %IDiscRecorder2_INTERFACE_DEFINED = 1

INTERFACE IDiscRecorder2 $IID_IDiscRecorder2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EjectMedia <256> ( _                          ' VTable offset = 28
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CloseTray <257> ( _                           ' VTable offset = 32
   )                                                    ' VOID
   ' =====================================================================================
   METHOD AcquireExclusiveAccess <258> ( _              ' VTable offset = 36
     BYVAL force AS INTEGER _                           ' __in VARIANT_BOOL force
   , BYVAL ClientName AS WSTRING _                      ' __in BSTR ClientName
   )                                                    ' VOID
   ' =====================================================================================
   METHOD ReleaseExclusiveAccess <259> ( _              ' VTable offset = 40
   )                                                    ' VOID
   ' =====================================================================================
   METHOD DisableMcn <260> ( _                          ' VTable offset = 44
   )                                                    ' VOID
   ' =====================================================================================
   METHOD EnableMcn <261> ( _                           ' VTable offset = 48
   )                                                    ' VOID
   ' =====================================================================================
   METHOD InitializeDiscRecorder <262> ( _              ' VTable offset = 52
     BYVAL recorderUniqueId AS WSTRING _                ' __in BSTR recorderUniqueId
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ActiveDiscRecorder <0> ( _              ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET VendorId <513> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET ProductId <514> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET ProductRevision <515> ( _               ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET VolumeName <516> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET VolumePathNames <517> ( _               ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET DeviceCanLoadMedia <518> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET LegacyDeviceNumber <519> ( _            ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *legacyDeviceNumber
   ' =====================================================================================
   PROPERTY GET SupportedFeaturePages <520> ( _         ' VTable offset = 88
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET CurrentFeaturePages <521> ( _           ' VTable offset = 92
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET SupportedProfiles <522> ( _             ' VTable offset = 96
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET CurrentProfiles <523> ( _               ' VTable offset = 100
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET SupportedModePages <524> ( _            ' VTable offset = 104
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET ExclusiveAccessOwner <525> ( _          ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscRecorder2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWriteEngine2
' IID = {27354135-7F64-5B0F-8F00-5D77AFBE261E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IWRITEENGINE2_WRITESECTION              = &H200
%DISPID_IWRITEENGINE2_CANCELWRITE               = &H201
%DISPID_IWRITEENGINE2_DISCRECORDER              = &H100
%DISPID_IWRITEENGINE2_USESTREAMINGWRITE12       = &H101
%DISPID_IWRITEENGINE2_STARTINGSECTORSPERSECOND  = &H102
%DISPID_IWRITEENGINE2_ENDINGSECTORSPERSECOND    = &H103
%DISPID_IWRITEENGINE2_BYTESPERSECTOR            = &H104
%DISPID_IWRITEENGINE2_WRITEINPROGRESS           = &H105

#IF NOT %DEF(%IWriteEngine2_INTERFACE_DEFINED)
    %IWriteEngine2_INTERFACE_DEFINED = 1

INTERFACE IWriteEngine2 $IID_IWriteEngine2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD WriteSection <512> ( _                        ' VTable offset = 28
     BYVAL data AS IStream _                            ' __in IStream *data
   , BYVAL startingBlockAddress AS LONG _               ' __in LONG startingBlockAddress
   , BYVAL numberOfBlocks AS LONG _                     ' __in LONG numberOfBlocks
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelWrite <513> ( _                         ' VTable offset = 32
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY SET Recorder <256> ( _                      ' VTable offset = 36
     BYVAL value AS IDiscRecorder2Ex _                  ' __in IDiscRecorder2Ex *value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Recorder <256> ( _                      ' VTable offset = 40
   ) AS IDiscRecorder2Ex                                ' __retval_out IDiscRecorder2Ex **value
   ' =====================================================================================
   PROPERTY SET UseStreamingWrite12 <257> ( _           ' VTable offset = 44
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET UseStreamingWrite12 <257> ( _           ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET StartingSectorsPerSecond <258> ( _      ' VTable offset = 52
     BYVAL value AS LONG _                              ' __in LONG value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET StartingSectorsPerSecond <258> ( _      ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY SET EndingSectorsPerSecond <259> ( _        ' VTable offset = 60
     BYVAL value AS LONG _                              ' __in LONG value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET EndingSectorsPerSecond <259> ( _        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY SET BytesPerSector <260> ( _                ' VTable offset = 68
     BYVAL value AS LONG _                              ' __in LONG value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET BytesPerSector <260> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET WriteInProgress <261> ( _               ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWriteEngine2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWriteEngine2EventArgs
' IID = {27354136-7F64-5B0F-8F00-5D77AFBE261E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IWRITEENGINE2EVENTARGS_STARTLBA             = &H100
%DISPID_IWRITEENGINE2EVENTARGS_SECTORCOUNT          = &H101
%DISPID_IWRITEENGINE2EVENTARGS_LASTREADLBA          = &H102
%DISPID_IWRITEENGINE2EVENTARGS_LASTWRITTENLBA       = &H103
%DISPID_IWRITEENGINE2EVENTARGS_TOTALDEVICEBUFFER    = &H104
%DISPID_IWRITEENGINE2EVENTARGS_USEDDEVICEBUFFER     = &H105
%DISPID_IWRITEENGINE2EVENTARGS_TOTALSYSTEMBUFFER    = &H106
%DISPID_IWRITEENGINE2EVENTARGS_USEDSYSTEMBUFFER     = &H107
%DISPID_IWRITEENGINE2EVENTARGS_FREESYSTEMBUFFER     = &H108

#IF NOT %DEF(%IWriteEngine2EventArgs_INTERFACE_DEFINED)
    %IWriteEngine2EventArgs_INTERFACE_DEFINED = 1

INTERFACE IWriteEngine2EventArgs $IID_IWriteEngine2EventArgs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StartLba <256> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET SectorCount <257> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastReadLba <258> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenLba <259> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalSystemBuffer <262> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET UsedSystemBuffer <263> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSystemBuffer <264> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWriteEngine2EventArgs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDiscFormat2
' IID = {27354152-8F64-5B0F-8F00-5D77AFBE261E}
' Common Disc Format (writer) Operations
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IDISCFORMAT2_RECORDERSUPPORTED        = &H800
%DISPID_IDISCFORMAT2_MEDIASUPPORTED           = &H801
%DISPID_IDISCFORMAT2_MEDIAPHYSICALLYBLANK     = &H700
%DISPID_IDISCFORMAT2_MEDIAHEURISTICALLYBLANK  = &H701
%DISPID_IDISCFORMAT2_SUPPORTEDMEDIATYPES      = &H702

#IF NOT %DEF(%IDiscFormat2_INTERFACE_DEFINED)
    %IDiscFormat2_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2 $IID_IDiscFormat2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD IsRecorderSupported <2048> ( _                ' VTable offset = 28
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   METHOD IsCurrentMediaSupported <2049> ( _            ' VTable offset = 32
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaPhysicallyBlank <1792> ( _         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaHeuristicallyBlank <1793> ( _      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedMediaTypes <1794> ( _          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2Erase
' IID = {27354156-8F64-5B0F-8F00-5D77AFBE261E}
' Optical media erase
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDiscFormat2
' ########################################################################################

%DISPID_IDISCFORMAT2ERASE_RECORDER            = &H100
%DISPID_IDISCFORMAT2ERASE_FULLERASE           = &H101
%DISPID_IDISCFORMAT2ERASE_MEDIATYPE           = &H102
%DISPID_IDISCFORMAT2ERASE_CLIENTNAME          = &H103
%DISPID_IDISCFORMAT2ERASE_ERASEMEDIA          = &H201

#IF NOT %DEF(%IDiscFormat2Erase_INTERFACE_DEFINED)
    %IDiscFormat2Erase_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2Erase $IID_IDiscFormat2Erase

   INHERIT IDispatch

   ' =====================================================================================
   ' IDiscFormat2 Methods
   ' =====================================================================================
   METHOD IsRecorderSupported <2048> ( _                ' VTable offset = 28
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   METHOD IsCurrentMediaSupported <2049> ( _            ' VTable offset = 32
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaPhysicallyBlank <1792> ( _         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaHeuristicallyBlank <1793> ( _      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedMediaTypes <1794> ( _          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2Erase Methods
   ' =====================================================================================
   PROPERTY SET Recorder <256> ( _                      ' VTable offset = 48
     BYVAL value AS IDiscRecorder2 _                    ' __in IDiscRecorder2 *value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Recorder <256> ( _                      ' VTable offset = 52
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================
   PROPERTY SET FullErase <257> ( _                     ' VTable offset = 56
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET FullErase <257> ( _                     ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET CurrentPhysicalMediaType <258> ( _      ' VTable offset = 64
   ) AS LONG                                            ' __retval_out IMAPI_MEDIA_PHYSICAL_TYPE *value
   ' =====================================================================================
   PROPERTY SET ClientName <259> ( _                    ' VTable offset = 68
     BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ClientName <259> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   METHOD EraseMedia <513> ( _                          ' VTable offset = 76
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2Erase_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2Data
' IID = {27354153-9F64-5B0F-8F00-5D77AFBE261E}
' Data Writer
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDiscFormat2
' ########################################################################################

%DISPID_IDISCFORMAT2DATA_RECORDER                         = &H100
%DISPID_IDISCFORMAT2DATA_BUFFERUNDERRUNFREEDISABLED       = &H101
%DISPID_IDISCFORMAT2DATA_POSTGAPALREADYINIMAGE            = &H104
%DISPID_IDISCFORMAT2DATA_CURRENTMEDIASTATUS               = &H106
%DISPID_IDISCFORMAT2DATA_WRITEPROTECTSTATUS               = &H107
%DISPID_IDISCFORMAT2DATA_TOTALSECTORS                     = &H108
%DISPID_IDISCFORMAT2DATA_FREESECTORS                      = &H109
%DISPID_IDISCFORMAT2DATA_NEXTWRITABLEADDRESS              = &H10A
%DISPID_IDISCFORMAT2DATA_STARTSECTOROFPREVIOUSSESSION     = &H10B
%DISPID_IDISCFORMAT2DATA_LASTSECTOROFPREVIOUSSESSION      = &H10C
%DISPID_IDISCFORMAT2DATA_FORCEMEDIATOBECLOSED             = &H10D
%DISPID_IDISCFORMAT2DATA_DISABLEDVDCOMPATIBILITYMODE      = &H10E
%DISPID_IDISCFORMAT2DATA_CURRENTMEDIATYPE                 = &H10F
%DISPID_IDISCFORMAT2DATA_CLIENTNAME                       = &H110
%DISPID_IDISCFORMAT2DATA_REQUESTEDWRITESPEED              = &H111
%DISPID_IDISCFORMAT2DATA_REQUESTEDROTATIONTYPEISPURECAV   = &H112
%DISPID_IDISCFORMAT2DATA_CURRENTWRITESPEED                = &H113
%DISPID_IDISCFORMAT2DATA_CURRENTROTATIONTYPEISPURECAV     = &H114
%DISPID_IDISCFORMAT2DATA_SUPPORTEDWRITESPEEDS             = &H115
%DISPID_IDISCFORMAT2DATA_SUPPORTEDWRITESPEEDDESCRIPTORS   = &H116
%DISPID_IDISCFORMAT2DATA_FORCEOVERWRITE                   = &H117
%DISPID_IDISCFORMAT2DATA_MUTLISESSIONINTERFACES           = &H118
%DISPID_IDISCFORMAT2DATA_WRITE                            = &H200
%DISPID_IDISCFORMAT2DATA_CANCELWRITE                      = &H201
%DISPID_IDISCFORMAT2DATA_SETWRITESPEED                    = &H202

#IF NOT %DEF(%IDiscFormat2Data_INTERFACE_DEFINED)
    %IDiscFormat2Data_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2Data $IID_IDiscFormat2Data

   INHERIT IDispatch

   ' =====================================================================================
   ' IDiscFormat2 Methods
   ' =====================================================================================
   METHOD IsRecorderSupported <2048> ( _                ' VTable offset = 28
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   METHOD IsCurrentMediaSupported <2049> ( _            ' VTable offset = 32
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaPhysicallyBlank <1792> ( _         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaHeuristicallyBlank <1793> ( _      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedMediaTypes <1794> ( _          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2Data Methods
   ' =====================================================================================
   PROPERTY SET Recorder <256> ( _                      ' VTable offset = 48
     BYVAL value AS IDiscRecorder2 _                    ' __in IDiscRecorder2 *value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Recorder <256> ( _                      ' VTable offset = 52
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================
   PROPERTY SET BufferUnderrunFreeDisabled <257> ( _    ' VTable offset = 56
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET BufferUnderrunFreeDisabled <257> ( _    ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET PostgapAlreadyInImage <260> ( _         ' VTable offset = 64
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET PostgapAlreadyInImage <260> ( _         ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET CurrentMediaStatus <262> ( _            ' VTable offset = 72
   ) AS LONG                                            ' __retval_out IMAPI_FORMAT2_DATA_MEDIA_STATE *value
   ' =====================================================================================
   PROPERTY GET WriteProtectStatus <263> ( _            ' VTable offset = 76
   ) AS LONG                                            ' __retval_out IMAPI_MEDIA_WRITE_PROTECT_STATE *value
   ' =====================================================================================
   PROPERTY GET TotalSectorsOnMedia <264> ( _           ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSectorsOnMedia <265> ( _            ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET NextWritableAddress <266> ( _           ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET StartAddressOfPreviousSession <267> ( _ ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenAddressOfPreviousSession <268> ( _ ' VTable offset = 96
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY SET ForceMediaToBeClosed <269> ( _          ' VTable offset = 100
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ForceMediaToBeClosed <269> ( _          ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET DisableConsumerDvdCompatibilityMode <270> ( _ ' VTable offset = 108
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DisableConsumerDvdCompatibilityMode <270> ( _ ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET CurrentPhysicalMediaType <271> ( _      ' VTable offset = 116
   ) AS LONG                                            ' __retval_out IMAPI_MEDIA_PHYSICAL_TYPE *value
   ' =====================================================================================
   PROPERTY SET ClientName <272> ( _                    ' VTable offset = 120
     BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ClientName <272> ( _                    ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET RequestedWriteSpeed <273> ( _           ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET RequestedRotationTypeIsPureCAV <274> ( _ ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET CurrentWriteSpeed <275> ( _             ' VTable offset = 136
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET CurrentRotationTypeIsPureCAV <276> ( _  ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedWriteSpeeds <277> ( _          ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *supportedSpeeds
   ' =====================================================================================
   PROPERTY GET SupportedWriteSpeedDescriptors <278> ( _ ' VTable offset = 148
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *supportedSpeedDescriptors
   ' =====================================================================================
   PROPERTY SET ForceOverwrite <279> ( _                ' VTable offset = 152
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ForceOverwrite <279> ( _                ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MultisessionInterfaces <280> ( _        ' VTable offset = 160
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   METHOD Write <512> ( _                               ' VTable offset = 164
     BYVAL data AS IStream _                            ' __in IStream *data
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelWrite <513> ( _                         ' VTable offset = 168
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetWriteSpeed <514> ( _                       ' VTable offset = 172
     BYVAL RequestedSectorsPerSecond AS LONG _          ' __in LONG RequestedSectorsPerSecond
   , BYVAL RotationTypeIsPureCAV AS INTEGER _           ' __in VARIANT_BOOL RotationTypeIsPureCAV
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2Data_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2DataEventArgs
' IID = {2735413D-7F64-5B0F-8F00-5D77AFBE261E}
' Track-at-once Data Writer
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWriteEngine2EventArgs
' ########################################################################################

%DISPID_IDISCFORMAT2DATAEVENTARGS_ELAPSEDTIME            = &H300
%DISPID_IDISCFORMAT2DATAEVENTARGS_ESTIMATEDREMAININGTIME = &H301
%DISPID_IDISCFORMAT2DATAEVENTARGS_ESTIMATEDTOTALTIME     = &H302
%DISPID_IDISCFORMAT2DATAEVENTARGS_CURRENTACTION          = &H303

#IF NOT %DEF(%IDiscFormat2DataEventArgs_INTERFACE_DEFINED)
    %IDiscFormat2DataEventArgs_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2DataEventArgs $IID_IDiscFormat2DataEventArgs

   INHERIT IDispatch

   ' =====================================================================================
   ' IWriteEngine2EventArgs Methods
   ' =====================================================================================
   PROPERTY GET StartLba <256> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET SectorCount <257> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastReadLba <258> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenLba <259> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalSystemBuffer <262> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET UsedSystemBuffer <263> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSystemBuffer <264> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2DataEventArgs Methods
   ' =====================================================================================
   PROPERTY GET ElapsedTime <768> ( _                   ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET RemainingTime <769> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalTime <770> ( _                     ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET CurrentAction <771> ( _                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out IMAPI_FORMAT2_DATA_WRITE_ACTION *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2DataEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2TrackAtOnce
' IID = {27354154-8F64-5B0F-8F00-5D77AFBE261E}
' CD Track-at-Once Audio Writer
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDiscFormat2
' ########################################################################################

%DISPID_IDISCFORMAT2TAO_RECORDER                          = &H100
%DISPID_IDISCFORMAT2TAO_BUFFERUNDERRUNFREEDISABLED        = &H102
%DISPID_IDISCFORMAT2TAO_NUMBEROFEXISTINGTRACKS            = &H103
%DISPID_IDISCFORMAT2TAO_TOTALSECTORSONMEDIA               = &H104
%DISPID_IDISCFORMAT2TAO_FREESECTORSONMEDIA                = &H105
%DISPID_IDISCFORMAT2TAO_USEDSECTORSONMEDIA                = &H106
%DISPID_IDISCFORMAT2TAO_DONOTFINALIZEMEDIA                = &H107
%DISPID_IDISCFORMAT2TAO_EXPECTEDTABLEOFCONTENTS           = &H10A
%DISPID_IDISCFORMAT2TAO_CURRENTMEDIATYPE                  = &H10B
%DISPID_IDISCFORMAT2TAO_CLIENTNAME                        = &H10E
%DISPID_IDISCFORMAT2TAO_REQUESTEDWRITESPEED               = &H10F
%DISPID_IDISCFORMAT2TAO_REQUESTEDROTATIONTYPEISPURECAV    = &H110
%DISPID_IDISCFORMAT2TAO_CURRENTWRITESPEED                 = &H111
%DISPID_IDISCFORMAT2TAO_CURRENTROTATIONTYPEISPURECAV      = &H112
%DISPID_IDISCFORMAT2TAO_SUPPORTEDWRITESPEEDS              = &H113
%DISPID_IDISCFORMAT2TAO_SUPPORTEDWRITESPEEDDESCRIPTORS    = &H114
%DISPID_IDISCFORMAT2TAO_PREPAREMEDIA                      = &H200
%DISPID_IDISCFORMAT2TAO_ADDAUDIOTRACK                     = &H201
%DISPID_IDISCFORMAT2TAO_CANCELADDTRACK                    = &H202
%DISPID_IDISCFORMAT2TAO_FINISHMEDIA                       = &H203
%DISPID_IDISCFORMAT2TAO_SETWRITESPEED                     = &H204

#IF NOT %DEF(%IDiscFormat2TrackAtOnce_INTERFACE_DEFINED)
    %IDiscFormat2TrackAtOnce_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2TrackAtOnce $IID_IDiscFormat2TrackAtOnce

   INHERIT IDispatch

   ' =====================================================================================
   ' IDiscFormat2 Methods
   ' =====================================================================================
   METHOD IsRecorderSupported <2048> ( _                ' VTable offset = 28
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   METHOD IsCurrentMediaSupported <2049> ( _            ' VTable offset = 32
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaPhysicallyBlank <1792> ( _         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaHeuristicallyBlank <1793> ( _      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedMediaTypes <1794> ( _          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2TrackAtOnce Methods
   ' =====================================================================================
   METHOD PrepareMedia <512> ( _                        ' VTable offset = 48
   )                                                    ' VOID
   ' =====================================================================================
   METHOD AddAudioTrack <513> ( _                       ' VTable offset = 52
     BYVAL data AS IStream _                            ' __in IStream *data
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelAddTrack <514> ( _                      ' VTable offset = 56
   )                                                    ' VOID
   ' =====================================================================================
   METHOD ReleaseMedia <515> ( _                        ' VTable offset = 60
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetWriteSpeed <516> ( _                       ' VTable offset = 64
     BYVAL RequestedSectorsPerSecond AS LONG _          ' __in LONG RequestedSectorsPerSecond
   , BYVAL RotationTypeIsPureCAV AS INTEGER _           ' __in VARIANT_BOOL RotationTypeIsPureCAV
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY SET Recorder <256> ( _                      ' VTable offset = 68
     BYVAL value AS IDiscRecorder2 _                    ' __in IDiscRecorder2 *value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Recorder <256> ( _                      ' VTable offset = 72
   ) AS IDiscRecorder2                                  ' [out][retval] **value /* **IDiscRecorder2 <dispinterface> */
   ' =====================================================================================
   PROPERTY SET BufferUnderrunFreeDisabled <258> ( _    ' VTable offset = 76
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET BufferUnderrunFreeDisabled <258> ( _    ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET NumberOfExistingTracks <259> ( _        ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalSectorsOnMedia <260> ( _           ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSectorsOnMedia <261> ( _            ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET UsedSectorsOnMedia <262> ( _            ' VTable offset = 96
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY SET DoNotFinalizeMedia <263> ( _            ' VTable offset = 100
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DoNotFinalizeMedia <263> ( _            ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET ExpectedTableOfContents <266> ( _       ' VTable offset = 108
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY GET CurrentPhysicalMediaType <267> ( _      ' VTable offset = 112
   ) AS LONG                                            ' __retval_out IMAPI_MEDIA_PHYSICAL_TYPE *value
   ' =====================================================================================
   PROPERTY SET ClientName <270> ( _                    ' VTable offset = 116
     BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ClientName <270> ( _                    ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET RequestedWriteSpeed <271> ( _           ' VTable offset = 124
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET RequestedRotationTypeIsPureCAV <272> ( _ ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET CurrentWriteSpeed <273> ( _             ' VTable offset = 132
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET CurrentRotationTypeIsPureCAV <274> ( _  ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedWriteSpeeds <275> ( _          ' VTable offset = 140
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *supportedSpeeds
   ' =====================================================================================
   PROPERTY GET SupportedWriteSpeedDescriptors <276> ( _ ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *supportedSpeedDescriptors
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2TrackAtOnce_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2TrackAtOnceEventArgs
' IID = {27354140-7F64-5B0F-8F00-5D77AFBE261E}
' CD Track-at-once Audio Writer Event Arguments
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWriteEngine2EventArgs
' ########################################################################################

%DISPID_IDISCFORMAT2TAOEVENTARGS_CURRENTTRACKNUMBER     = &H300
%DISPID_IDISCFORMAT2TAOEVENTARGS_CURRENTACTION          = &H301
%DISPID_IDISCFORMAT2TAOEVENTARGS_ELAPSEDTIME            = &H302
%DISPID_IDISCFORMAT2TAOEVENTARGS_ESTIMATEDREMAININGTIME = &H303
%DISPID_IDISCFORMAT2TAOEVENTARGS_ESTIMATEDTOTALTIME     = &H304

#IF NOT %DEF(%IDiscFormat2TrackAtOnceEventArgs_INTERFACE_DEFINED)
    %IDiscFormat2TrackAtOnceEventArgs_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2TrackAtOnceEventArgs $IID_IDiscFormat2TrackAtOnceEventArgs

   INHERIT IDispatch

   ' =====================================================================================
   ' IWriteEngine2EventArgs Methods
   ' =====================================================================================
   PROPERTY GET StartLba <256> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET SectorCount <257> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastReadLba <258> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenLba <259> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalSystemBuffer <262> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET UsedSystemBuffer <263> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSystemBuffer <264> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2TrackAtOnceEventArgs Methods
   ' =====================================================================================
   PROPERTY GET CurrentTrackNumber <768> ( _            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET CurrentAction <769> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __retval_out IMAPI_FORMAT2_TAO_WRITE_ACTION *value
   ' =====================================================================================
   PROPERTY GET ElapsedTime <770> ( _                   ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET RemainingTime <771> ( _                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2TrackAtOnceEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2RawCD
' IID = {27354155-8F64-5B0F-8F00-5D77AFBE261E}
' CD Disc-At-Once RAW Writer
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDiscFormat2
' ########################################################################################

%DISPID_IDISCFORMAT2RAWCD_RECORDER                        = &H100
%DISPID_IDISCFORMAT2RAWCD_BUFFERUNDERRUNFREEDISABLED      = &H102
%DISPID_IDISCFORMAT2RAWCD_STARTOFNEXTSESSION              = &H103
%DISPID_IDISCFORMAT2RAWCD_LASTPOSSIBLESTARTOFLEADOUT      = &H104
%DISPID_IDISCFORMAT2RAWCD_CURRENTMEDIATYPE                = &H105
%DISPID_IDISCFORMAT2RAWCD_SUPPORTEDDATASECTORTYPES        = &H108
%DISPID_IDISCFORMAT2RAWCD_REQUESTEDDATASECTORTYPE         = &H109
%DISPID_IDISCFORMAT2RAWCD_CLIENTNAME                      = &H10A
%DISPID_IDISCFORMAT2RAWCD_REQUESTEDWRITESPEED             = &H10B
%DISPID_IDISCFORMAT2RAWCD_REQUESTEDROTATIONTYPEISPURECAV  = &H10C
%DISPID_IDISCFORMAT2RAWCD_CURRENTWRITESPEED               = &H10D
%DISPID_IDISCFORMAT2RAWCD_CURRENTROTATIONTYPEISPURECAV    = &H10E
%DISPID_IDISCFORMAT2RAWCD_SUPPORTEDWRITESPEEDS            = &H10F
%DISPID_IDISCFORMAT2RAWCD_SUPPORTEDWRITESPEEDDESCRIPTORS  = &H110
%DISPID_IDISCFORMAT2RAWCD_PREPAREMEDIA                    = &H200
%DISPID_IDISCFORMAT2RAWCD_WRITEMEDIA                      = &H201
%DISPID_IDISCFORMAT2RAWCD_WRITEMEDIAWITHVALIDATION        = &H202
%DISPID_IDISCFORMAT2RAWCD_CANCELWRITE                     = &H203
%DISPID_IDISCFORMAT2RAWCD_RELEASEMEDIA                    = &H204
%DISPID_IDISCFORMAT2RAWCD_SETWRITESPEED                   = &H205

#IF NOT %DEF(%IDiscFormat2RawCD_INTERFACE_DEFINED)
    %IDiscFormat2RawCD_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2RawCD $IID_IDiscFormat2RawCD

   INHERIT IDispatch

   ' =====================================================================================
   ' IDiscFormat2 Methods
   ' =====================================================================================
   METHOD IsRecorderSupported <2048> ( _                ' VTable offset = 28
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   METHOD IsCurrentMediaSupported <2049> ( _            ' VTable offset = 32
     BYVAL recorder AS IDiscRecorder2 _                 ' __in IDiscRecorder2 *recorder
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaPhysicallyBlank <1792> ( _         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET MediaHeuristicallyBlank <1793> ( _      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedMediaTypes <1794> ( _          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2RawCD Methods
   ' =====================================================================================
   METHOD PrepareMedia <512> ( _                        ' VTable offset = 48
   )                                                    ' VOID
   ' =====================================================================================
   METHOD WriteMedia <513> ( _                          ' VTable offset = 52
     BYVAL data AS IStream _                            ' __in IStream *data
   )                                                    ' VOID
   ' =====================================================================================
   METHOD WriteMedia2 <514> ( _                         ' VTable offset = 56
     BYVAL data AS IStream _                            ' __in IStream *data
   , BYVAL streamLeadInSectors AS LONG _                ' __in LONG streamLeadInSectors
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelWrite <515> ( _                         ' VTable offset = 60
   )                                                    ' VOID
   ' =====================================================================================
   METHOD ReleaseMedia <516> ( _                        ' VTable offset = 64
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetWriteSpeed <517> ( _                       ' VTable offset = 68
     BYVAL RequestedSectorsPerSecond AS LONG _          ' __in LONG RequestedSectorsPerSecond
   , BYVAL RotationTypeIsPureCAV AS INTEGER _           ' __in VARIANT_BOOL RotationTypeIsPureCAV
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY SET Recorder <256> ( _                      ' VTable offset = 72
     BYVAL value AS IDiscRecorder2 _                    ' __in IDiscRecorder2 *value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Recorder <256> ( _                      ' VTable offset = 76
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================
   PROPERTY SET BufferUnderrunFreeDisabled <258> ( _    ' VTable offset = 80
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET BufferUnderrunFreeDisabled <258> ( _    ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET StartOfNextSession <259> ( _            ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastPossibleStartOfLeadout <260> ( _    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET CurrentPhysicalMediaType <261> ( _      ' VTable offset = 96
   ) AS LONG                                            ' __retval_out IMAPI_MEDIA_PHYSICAL_TYPE *value
   ' =====================================================================================
   PROPERTY GET SupportedSectorTypes <264> ( _          ' VTable offset = 100
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *value
   ' =====================================================================================
   PROPERTY SET RequestedSectorType <265> ( _           ' VTable offset = 104
     BYVAL value AS LONG _                              ' __in IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET RequestedSectorType <265> ( _           ' VTable offset = 108
   ) AS LONG                                            ' __retval_out IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE *value
   ' =====================================================================================
   PROPERTY SET ClientName <266> ( _                    ' VTable offset = 112
     BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET ClientName <266> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY GET RequestedWriteSpeed <267> ( _           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET RequestedRotationTypeIsPureCAV <268> ( _ ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET CurrentWriteSpeed <269> ( _             ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET CurrentRotationTypeIsPureCAV <270> ( _  ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET SupportedWriteSpeeds <271> ( _          ' VTable offset = 136
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *supportedSpeeds
   ' =====================================================================================
   PROPERTY GET SupportedWriteSpeedDescriptors <272> ( _ ' VTable offset = 140
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *supportedSpeedDescriptors
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2RawCD_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiscFormat2RawCDEventArgs
' IID = {27354143-7F64-5B0F-8F00-5D77AFBE261E}
' CD Disc-At-Once RAW Writer Event Arguments
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWriteEngine2EventArgs
' ########################################################################################

%DISPID_IDISCFORMAT2RAWCDEVENTARGS_CURRENTTRACKNUMBER     = &H300
%DISPID_IDISCFORMAT2RAWCDEVENTARGS_CURRENTACTION          = &H301
%DISPID_IDISCFORMAT2RAWCDEVENTARGS_ELAPSEDTIME            = &H300
%DISPID_IDISCFORMAT2RAWCDEVENTARGS_ESTIMATEDREMAININGTIME = &H301
%DISPID_IDISCFORMAT2RAWCDEVENTARGS_ESTIMATEDTOTALTIME     = &H302

#IF NOT %DEF(%IDiscFormat2RawCDEventArgs_INTERFACE_DEFINED)
    %IDiscFormat2RawCDEventArgs_INTERFACE_DEFINED = 1

INTERFACE IDiscFormat2RawCDEventArgs $IID_IDiscFormat2RawCDEventArgs

   INHERIT IDispatch

   ' =====================================================================================
   ' IWriteEngine2EventArgs Methods
   ' =====================================================================================
   PROPERTY GET StartLba <256> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET SectorCount <257> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastReadLba <258> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenLba <259> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalSystemBuffer <262> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET UsedSystemBuffer <263> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSystemBuffer <264> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

   ' =====================================================================================
   ' IDiscFormat2RawCDEventArgs Methods
   ' =====================================================================================
   PROPERTY GET CurrentAction <769> ( _                 ' VTable offset = 56
   ) AS LONG                                            ' __retval_out IMAPI_FORMAT2_RAW_CD_WRITE_ACTION *value
   ' =====================================================================================
   PROPERTY GET ElapsedTime <770> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET RemainingTime <771> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiscFormat2RawCDEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBurnVerification
' IID = {D2FFD834-958B-426D-8470-2A13879C6A91}
' An interface to control burn verification for a burning object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBurnVerification_INTERFACE_DEFINED)
    %IBurnVerification_INTERFACE_DEFINED = 1

INTERFACE IBurnVerification $IID_IBurnVerification

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY SET BurnVerificationLevel ( _               ' VTable offset = 12
     BYVAL value AS LONG _                              ' __in IMAPI_BURN_VERIFICATION_LEVEL value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BurnVerificationLevel ( _               ' VTable offset = 16
   ) AS LONG                                            ' __retval_out IMAPI_BURN_VERIFICATION_LEVEL *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBurnVerification_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWriteSpeedDescriptor
' IID = {27354144-7F64-5B0F-8F00-5D77AFBE261E}
' A single optical drive Write Speed Configuration
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%IMAPI_SECTORS_PER_SECOND_AT_1X_CD     = 75
%IMAPI_SECTORS_PER_SECOND_AT_1X_DVD    = 680
%IMAPI_SECTORS_PER_SECOND_AT_1X_BD     = 2195
%IMAPI_SECTORS_PER_SECOND_AT_1X_HD_DVD = 4568

#IF NOT %DEF(%IWriteSpeedDescriptor_INTERFACE_DEFINED)
    %IWriteSpeedDescriptor_INTERFACE_DEFINED = 1

INTERFACE IWriteSpeedDescriptor $IID_IWriteSpeedDescriptor

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MediaType <257> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out IMAPI_MEDIA_PHYSICAL_TYPE *value
   ' =====================================================================================
   PROPERTY GET RotationTypeIsPureCAV <258> ( _         ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET WriteSpeed <259> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWriteSpeedDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMultisession
' IID = {27354150-7F64-5B0F-8F00-5D77AFBE261E}
' Generic multisession support interface.
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IMULTISESSION_SUPPORTEDONCURRENTMEDIA = &H100
%DISPID_IMULTISESSION_INUSE                   = &H101
%DISPID_IMULTISESSION_IMPORTRECORDER          = &H102

#IF NOT %DEF(%IMultisession_INTERFACE_DEFINED)
    %IMultisession_INTERFACE_DEFINED = 1

INTERFACE IMultisession $IID_IMultisession

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsSupportedOnCurrentMediaState <256> ( _ ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET InUse <257> ( _                         ' VTable offset = 32
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET InUse <257> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET ImportRecorder <258> ( _                ' VTable offset = 40
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultisession_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMultisessionSequential
' IID = {27354151-7F64-5B0F-8F00-5D77AFBE261E}
' Sequential multisession support interface.
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IMultisession
' ########################################################################################

%DISPID_IMULTISESSION_FIRSTDATASESSION             = &H200
%DISPID_IMULTISESSION_STARTSECTOROFPREVIOUSSESSION = &H201
%DISPID_IMULTISESSION_LASTSECTOROFPREVIOUSSESSION  = &H202
%DISPID_IMULTISESSION_NEXTWRITABLEADDRESS          = &H203
%DISPID_IMULTISESSION_FREESECTORS                  = &H204

#IF NOT %DEF(%IMultisessionSequential_INTERFACE_DEFINED)
    %IMultisessionSequential_INTERFACE_DEFINED = 1

INTERFACE IMultisessionSequential $IID_IMultisessionSequential

   INHERIT IDispatch

   ' =====================================================================================
   ' IMultisession Methods
   ' =====================================================================================
   PROPERTY GET IsSupportedOnCurrentMediaState <256> ( _ ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET InUse <257> ( _                         ' VTable offset = 32
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET InUse <257> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET ImportRecorder <258> ( _                ' VTable offset = 40
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================

   ' =====================================================================================
   ' IMultisessionSequential Methods
   ' =====================================================================================
   PROPERTY GET IsFirstDataSession <512> ( _            ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET StartAddressOfPreviousSession <513> ( _ ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenAddressOfPreviousSession <514> ( _ ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET NextWritableAddress <515> ( _           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSectorsOnMedia <516> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultisessionSequential_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMultisessionSequential2
' IID = {B507CA22-2204-11DD-966A-001AA01BBC58}
' Sequential multisession support interface (rev.2)
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMultisessionSequential
' ########################################################################################

#IF NOT %DEF(%IMultisessionSequential2_INTERFACE_DEFINED)
    %IMultisessionSequential2_INTERFACE_DEFINED = 1

INTERFACE IMultisessionSequential2 $IID_IMultisessionSequential2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMultisession Methods
   ' =====================================================================================
   PROPERTY GET IsSupportedOnCurrentMediaState <256> ( _  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET InUse <257> ( _                         ' VTable offset = 32
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InUse <257> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET ImportRecorder <258> ( _                ' VTable offset = 40
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================

   ' =====================================================================================
   ' IMultisessionSequential Methods
   ' =====================================================================================
   PROPERTY GET IsFirstDataSession <512> ( _            ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET StartAddressOfPreviousSession <513> ( _  ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenAddressOfPreviousSession <514> ( _  ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET NextWritableAddress <515> ( _           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET FreeSectorsOnMedia <516> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

   ' =====================================================================================
   ' IMultisessionSequential2 Methods
   ' =====================================================================================
   PROPERTY GET WriteUnitSize <517> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultisessionSequential2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMultisessionRandomWrite
' IID = {B507CA23-2204-11DD-966A-001AA01BBC58}
' Random write multisession support interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMultisession
' ########################################################################################

%DISPID_IMULTISESSION_LASTWRITTENADDRESS           = &H206
%DISPID_IMULTISESSION_SECTORSONMEDIA               = &H207

#IF NOT %DEF(%IMultisessionRandomWrite_INTERFACE_DEFINED)
    %IMultisessionRandomWrite_INTERFACE_DEFINED = 1

INTERFACE IMultisessionRandomWrite $IID_IMultisessionRandomWrite

   INHERIT IDispatch

   ' =====================================================================================
   ' IMultisession Methods
   ' =====================================================================================
   PROPERTY GET IsSupportedOnCurrentMediaState <256> ( _  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET InUse <257> ( _                         ' VTable offset = 32
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InUse <257> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY GET ImportRecorder <258> ( _                ' VTable offset = 40
   ) AS IDiscRecorder2                                  ' __retval_out IDiscRecorder2 **value
   ' =====================================================================================

   ' =====================================================================================
   ' IMultisessionRandomWrite Methods
   ' =====================================================================================
   PROPERTY GET WriteUnitSize <517> ( _                 ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastWrittenAddress <518> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TotalSectorsOnMedia <519> ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultisessionRandomWrite_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStreamPseudoRandomBased
' IID = {27354145-7F64-5B0F-8F00-5D77AFBE261E}
' Pseudo-random based IStream data (implementation dependent)
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%IStreamPseudoRandomBased_INTERFACE_DEFINED)
    %IStreamPseudoRandomBased_INTERFACE_DEFINED = 1

INTERFACE IStreamPseudoRandomBased $IID_IStreamPseudoRandomBased

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IUnknown _                           ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamPseudoRandomBased Methods
   ' =====================================================================================
   METHOD put_Seed ( _                                  ' VTable offset = 56
     BYVAL value AS DWORD _                             ' __in ULONG value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Seed ( _                                  ' VTable offset = 60
     BYREF value AS DWORD _                             ' __out ULONG *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ExtendedSeed ( _                          ' VTable offset = 64
     BYREF values AS DWORD _                            ' __in ULONG *values
   , BYVAL eCount AS DWORD _                            ' __in ULONG eCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ExtendedSeed ( _                          ' VTable offset = 68
     BYREF values AS DWORD _                            ' __out ULONG **values
   , BYREF eCount AS DWORD _                            ' __out ULONG *eCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamPseudoRandomBased_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStreamConcatenate
' IID = {27354146-7F64-5B0F-8F00-5D77AFBE261E}
' Stream concatenation
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%IStreamConcatenate_INTERFACE_DEFINED)
    %IStreamConcatenate_INTERFACE_DEFINED = 1

INTERFACE IStreamConcatenate $IID_IStreamConcatenate

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IUnknown _                           ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamConcatenate Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 56
     BYVAL stream1 AS IStream _                         ' __in IStream *stream1
   , BYVAL stream2 AS IStream _                         ' __in IStream *stream2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize2 ( _                               ' VTable offset = 60
     BYREF streams AS IStream _                         ' __in IStream **streams
   , BYVAL streamCount AS DWORD _                       ' __in ULONG streamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 64
     BYVAL stream AS IStream _                          ' __in IStream *stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append2 ( _                                   ' VTable offset = 68
     BYREF streams AS IStream _                         ' __in IStream **streams
   , BYVAL streamCount AS DWORD _                       ' __in ULONG streamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamConcatenate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStreamInterleave
' IID = {27354147-7F64-5B0F-8F00-5D77AFBE261E}
' Stream interleave: each stream gets interleaveSize bytes, then cycles to the next stream
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%IStreamInterleave_INTERFACE_DEFINED)
    %IStreamInterleave_INTERFACE_DEFINED = 1

INTERFACE IStreamInterleave $IID_IStreamInterleave

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IUnknown _                           ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamInterleave Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 56
     BYREF streams AS IStream _                         ' __in IStream **streams
   , BYREF interleaveSizes AS DWORD _                   ' __in ULONG *interleaveSizes
   , BYVAL streamCount AS DWORD _                       ' __in ULONG streamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamInterleave_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRawCDImageCreator
' IID = {25983550-9D65-49CE-B335-40630D901227}
' CD Raw CD (Disc-at-Once) Image Creator
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IRAWCDIMAGECREATOR_CREATERESULTIMAGE        = &H200
%DISPID_IRAWCDIMAGECREATOR_ADDTRACK                 = &H201
%DISPID_IRAWCDIMAGECREATOR_ADDSPECIALPREGAP         = &H202
%DISPID_IRAWCDIMAGECREATOR_ADDSUBCODERWGENERATOR    = &H203
%DISPID_IRAWCDIMAGECREATOR_RESULTINGIMAGETYPE       = &H100
%DISPID_IRAWCDIMAGECREATOR_STARTOFLEADOUT           = &H101
%DISPID_IRAWCDIMAGECREATOR_STARTOFLEADOUTLIMIT      = &H102
%DISPID_IRAWCDIMAGECREATOR_DISABLEGAPLESSAUDIO      = &H103
%DISPID_IRAWCDIMAGECREATOR_MEDIACATALOGNUMBER       = &H104
%DISPID_IRAWCDIMAGECREATOR_STARTINGTRACKNUMBER      = &H105
%DISPID_IRAWCDIMAGECREATOR_TRACKINFO                = &H106
%DISPID_IRAWCDIMAGECREATOR_NUMBEROFEXISTINGTRACKS   = &H107
%DISPID_IRAWCDIMAGECREATOR_USEDSECTORSONDISC        = &H108
%DISPID_IRAWCDIMAGECREATOR_EXPECTEDTABLEOFCONTENTS  = &H109

#IF NOT %DEF(%IRawCDImageCreator_INTERFACE_DEFINED)
    %IRawCDImageCreator_INTERFACE_DEFINED = 1

INTERFACE IRawCDImageCreator $IID_IRawCDImageCreator

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateResultImage <512> ( _                   ' VTable offset = 28
   ) AS IStream                                         ' __retval_out IStream **resultStream
   ' =====================================================================================
   METHOD AddTrack <513> ( _                            ' VTable offset = 32
     BYVAL dataType AS LONG _                           ' __in IMAPI_CD_SECTOR_TYPE dataType
   , BYVAL data AS IStream _                            ' __in IStream *data
   ) AS LONG                                            ' __retval_out LONG *trackIndex
   ' =====================================================================================
   METHOD AddSpecialPregap <514> ( _                    ' VTable offset = 36
     BYVAL data AS IStream _                            ' __in IStream *data IStream
   )                                                    ' void
   ' =====================================================================================
   METHOD AddSubcodeRWGenerator <515> ( _               ' VTable offset = 40
     BYVAL subcode AS IStream _                         ' __in IStream *subcode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ResultingImageType <256> ( _            ' VTable offset = 44
     BYVAL value AS LONG _                              ' __in IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResultingImageType <256> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE *value
   ' =====================================================================================
   PROPERTY GET StartOfLeadout <257> ( _                ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY SET StartOfLeadoutLimit <258> ( _           ' VTable offset = 56
     BYVAL value AS LONG _                              ' __in LONG value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartOfLeadoutLimit <258> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY SET DisableGaplessAudio <259> ( _           ' VTable offset = 64
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisableGaplessAudio <259> ( _           ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET MediaCatalogNumber <260> ( _            ' VTable offset = 72
     BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaCatalogNumber <260> ( _            ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY SET StartingTrackNumber <261> ( _           ' VTable offset = 80
     BYVAL value AS LONG _                              ' __in LONG value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartingTrackNumber <261> ( _           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TrackInfo <262> ( _                     ' VTable offset = 88
     BYVAL trackIndex AS LONG _                         ' __in LONG trackIndex
   ) AS IRawCDImageTrackInfo                            ' __retval_out IRawCDImageTrackInfo **value
   ' =====================================================================================
   PROPERTY GET NumberOfExistingTracks <263> ( _        ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET LastUsedUserSectorInImage <264> ( _     ' VTable offset = 96
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET ExpectedTableOfContents <265> ( _       ' VTable offset = 100
   ) AS DWORD                                           ' __retval_out SAFEARRAY **value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRawCDImageCreator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRawCDImageTrackInfo
' IID = {25983551-9D65-49CE-B335-40630D901227}
' CD Raw CD (Disc-at-Once) Per-Track Information
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IRAWCDTRACKINFO_STARTINGLBA              = &H100
%DISPID_IRAWCDTRACKINFO_SECTORCOUNT              = &H101
%DISPID_IRAWCDTRACKINFO_TRACKNUMBER              = &H102
%DISPID_IRAWCDTRACKINFO_SECTORTYPE               = &H103
%DISPID_IRAWCDTRACKINFO_ISRC                     = &H104
%DISPID_IRAWCDTRACKINFO_DIGITALAUDIOCOPYSETTING  = &H105
%DISPID_IRAWCDTRACKINFO_AUDIOHASPREEMPHASIS      = &H106

#IF NOT %DEF(%IRawCDImageTrackInfo_INTERFACE_DEFINED)
    %IRawCDImageTrackInfo_INTERFACE_DEFINED = 1

INTERFACE IRawCDImageTrackInfo $IID_IRawCDImageTrackInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StartingLba <256> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET SectorCount <257> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET TrackNumber <258> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET SectorType <259> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out IMAPI_CD_SECTOR_TYPE *value
   ' =====================================================================================
   PROPERTY GET ISRC <260> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================
   PROPERTY SET ISRC <260> ( _                          ' VTable offset = 48
     BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DigitalAudioCopySetting <261> ( _       ' VTable offset = 52
   ) AS LONG                                            ' __retval_out IMAPI_CD_TRACK_DIGITAL_COPY_SETTING *value
   ' =====================================================================================
   PROPERTY SET DigitalAudioCopySetting <261> ( _       ' VTable offset = 56
     BYVAL value AS LONG _                              ' __in IMAPI_CD_TRACK_DIGITAL_COPY_SETTING value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioHasPreemphasis <262> ( _           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *value
   ' =====================================================================================
   PROPERTY SET AudioHasPreemphasis <262> ( _           ' VTable offset = 64
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TrackIndexes <263> ( _                  ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out SAFEARRAY **value
   ' =====================================================================================
   METHOD AddTrackIndex <512> ( _                       ' VTable offset = 72
     BYVAL lbaOffset AS LONG _                          ' __in LONG lbaOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearTrackIndex <513> ( _                     ' VTable offset = 76
     BYVAL lbaOffset AS LONG _                          ' __in LONG lbaOffset
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRawCDImageTrackInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBlockRange
' IID = {B507CA25-2204-11DD-966A-001AA01BBC58}
' A continuous LBA range
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IBLOCKRANGE_STARTLBA                       = &H100
%DISPID_IBLOCKRANGE_ENDLBA                         = &H101

#IF NOT %DEF(%IBlockRange_INTERFACE_DEFINED)
    %IBlockRange_INTERFACE_DEFINED = 1

INTERFACE IBlockRange $IID_IBlockRange

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StartLba <256> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================
   PROPERTY GET EndLba <257> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBlockRange_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBlockRangeList
' IID = {B507CA26-2204-11DD-966A-001AA01BBC58}
' A list of continuous LBA ranges
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

%DISPID_IBLOCKRANGELIST_BLOCKRANGES                = &H100

#IF NOT %DEF(%IBlockRangeList_INTERFACE_DEFINED)
    %IBlockRangeList_INTERFACE_DEFINED = 1

INTERFACE IBlockRangeList $IID_IBlockRangeList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BlockRanges <256> ( _                   ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out SAFEARRAY **value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBlockRangeList_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDDiscMaster2Events
' Interface name = DDiscMaster2Events
' IID = {27354131-7F64-5B0F-8F00-5D77AFBE261E}
' Provides notification of the arrival/removal of CD/DVD (optical) devices.
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DDISCMASTER2EVENTS_DEVICEADDED   = &H100
'%DISPID_DDISCMASTER2EVENTS_DEVICEREMOVED = &H101

'CLASS CDDiscMaster2Events GUID$("{4CCFFA5E-F433-400F-AA68-1A38701AF243}") AS EVENT

'INTERFACE DDiscMaster2EventsImpl GUID$("{27354131-7F64-5B0F-8F00-5D77AFBE261E}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD NotifyDeviceAdded <256> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL uniqueId AS WSTRING _                        ' __in BSTR uniqueId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NotifyDeviceRemoved <257> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL uniqueId AS WSTRING _                        ' __in BSTR uniqueId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDWriteEngine2Events
' Interface name = DWriteEngine2Events
' IID = {27354137-7F64-5B0F-8F00-5D77AFBE261E}
' Provides notification of the progress of the WriteEngine2 writing.
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DWRITEENGINE2EVENTS_UPDATE     = &H100

'CLASS CDWriteEngine2Events GUID$("{B7CC08FB-8DB2-44C4-AF3C-69AD991CFAF6}") AS EVENT

'INTERFACE DWriteEngine2EventsImpl GUID$("{27354137-7F64-5B0F-8F00-5D77AFBE261E}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Update <256> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL progress AS IDispatch _                      ' __in IDispatch *progress
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDDiscFormat2EraseEvents
' Interface name = DDiscFormat2EraseEvents
' IID = {2735413A-7F64-5B0F-8F00-5D77AFBE261E}
' Provides notification of media erase progress.
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_IDISCFORMAT2ERASEEVENTS_UPDATE = &H200

'CLASS CDDiscFormat2EraseEvents GUID$("{9377F4D1-0052-40EF-BF60-5BD8D73BBF61}") AS EVENT

'INTERFACE DDiscFormat2EraseEventsImpl GUID$("{2735413A-7F64-5B0F-8F00-5D77AFBE261E}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Update <512> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL elapsedSeconds AS LONG _                     ' __in LONG elapsedSeconds
'   , BYVAL estimatedTotalSeconds AS LONG _              ' __in LONG estimatedTotalSeconds
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDDiscFormat2DataEvents
' Interface name = DDiscFormat2DataEvents
' IID = {2735413C-7F64-5B0F-8F00-5D77AFBE261E}
' Data Writer
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DDISCFORMAT2DATAEVENTS_UPDATE  = &H200

'CLASS CDDiscFormat2DataEvents GUID$("{D1943E2F-4D94-4EC4-879A-DB913A074847}") AS EVENT

'INTERFACE DDiscFormat2DataEventsImpl GUID$("{2735413C-7F64-5B0F-8F00-5D77AFBE261E}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Update <512> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL progress AS IDispatch _                      ' __in IDispatch *progress
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDDiscFormat2TrackAtOnceEvents
' Interface name = DDiscFormat2TrackAtOnceEvents
' IID = {2735413F-7F64-5B0F-8F00-5D77AFBE261E}
' CD Track-at-Once Audio Writer Events
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DDISCFORMAT2TAOEVENTS_UPDATE   = &H200

'CLASS CDDiscFormat2TrackAtOnceEvents GUID$("{517194A8-680E-496A-9DB0-45683AFE04DC}") AS EVENT

'INTERFACE DDiscFormat2TrackAtOnceEventsImpl GUID$("{2735413F-7F64-5B0F-8F00-5D77AFBE261E}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Update <512> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL progress AS IDispatch _                      ' __in IDispatch *progress
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDDiscFormat2RawCDEvents
' Interface name = DDiscFormat2RawCDEvents
' IID = {27354142-7F64-5B0F-8F00-5D77AFBE261E}
' CD Disc-At-Once RAW Writer Events
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DDISCFORMAT2RAWCDEVENTS_UPDATE = &H200

'CLASS CDDiscFormat2RawCDEvents GUID$("{D9EF5635-6445-4891-B400-10C37E808D5F}") AS EVENT

'INTERFACE DDiscFormat2RawCDEventsImpl GUID$("{27354142-7F64-5B0F-8F00-5D77AFBE261E}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Update <512> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL progress AS IDispatch _                      ' __in IDispatch *progress
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
