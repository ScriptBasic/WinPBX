' ########################################################################################
' Microsoft Windows
' File: xprtdefs.inc (derived from edevdefs.inc)
' Contents: External Device (like a VCR) control interface parameter and value definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XPRTDEFS_INC = 1

%ED_BASE                        = &H1000&

'// this is used to tell the device communications object which
'// physical communications port to use.
%DEV_PORT_SIM  = 1
%DEV_PORT_COM1 = 2               '// standard serial ports
%DEV_PORT_COM2 = 3
%DEV_PORT_COM3 = 4
%DEV_PORT_COM4 = 5
%DEV_PORT_DIAQ = 6               '// Diaquest driver
%DEV_PORT_ARTI = 7               '// ARTI driver
%DEV_PORT_1394 = 8               '// IEEE 1394 Serial Bus
%DEV_PORT_USB  = 9               '// Universal Serial Bus
%DEV_PORT_MIN  = %DEV_PORT_SIM
%DEV_PORT_MAX  = %DEV_PORT_USB


'// IAMExtDevice Capability Items:  unless otherwise specified, these items return
'//    OATRUE or OAFALSE.  All return values are in pdwValue unless otherwise specified:

%ED_DEVCAP_CAN_RECORD           = %ED_BASE+1&
%ED_DEVCAP_CAN_RECORD_STROBE    = %ED_BASE+2&    '// for multitrack devices:
                                                 '// switches currently recording tracks off
                                                 '// and selected non-recording tracks into record
%ED_DEVCAP_HAS_AUDIO            = %ED_BASE+3&
%ED_DEVCAP_HAS_VIDEO            = %ED_BASE+4&
%ED_DEVCAP_USES_FILES           = %ED_BASE+5&
%ED_DEVCAP_CAN_SAVE             = %ED_BASE+6&

%ED_DEVCAP_DEVICE_TYPE          = %ED_BASE+7&    '// returns one of the following:
%ED_DEVTYPE_VCR                 = %ED_BASE+8&
%ED_DEVTYPE_LASERDISK           = %ED_BASE+9&
%ED_DEVTYPE_ATR                 = %ED_BASE+10&
%ED_DEVTYPE_DDR                 = %ED_BASE+11&
%ED_DEVTYPE_ROUTER              = %ED_BASE+12&
%ED_DEVTYPE_KEYER               = %ED_BASE+13&
%ED_DEVTYPE_MIXER_VIDEO         = %ED_BASE+14&
%ED_DEVTYPE_DVE                 = %ED_BASE+15&
%ED_DEVTYPE_WIPEGEN             = %ED_BASE+16&
%ED_DEVTYPE_MIXER_AUDIO         = %ED_BASE+17&
%ED_DEVTYPE_CG                  = %ED_BASE+18&
%ED_DEVTYPE_TBC                 = %ED_BASE+19&
%ED_DEVTYPE_TCG                 = %ED_BASE+20&
%ED_DEVTYPE_GPI                 = %ED_BASE+21&
%ED_DEVTYPE_JOYSTICK            = %ED_BASE+22&
%ED_DEVTYPE_KEYBOARD            = %ED_BASE+23&

'// returns mfr-specific ID from external device.
%ED_DEVCAP_EXTERNAL_DEVICE_ID   = %ED_BASE+24&

%ED_DEVCAP_TIMECODE_READ        = %ED_BASE+25&
%ED_DEVCAP_TIMECODE_WRITE       = %ED_BASE+26&
'//    used for seekable non-timecode enabled devices
%ED_DEVCAP_CTLTRK_READ          = %ED_BASE+27&
'//    used for seekable non-timecode enabled devices
%ED_DEVCAP_INDEX_READ           = %ED_BASE+28&

'// returns device preroll time in current time format
%ED_DEVCAP_PREROLL              = %ED_BASE+29&
'// returns device postroll time in current time format
%ED_DEVCAP_POSTROLL             = %ED_BASE+30&

'// returns indication of device's synchronization accuracy.
%ED_DEVCAP_SYNC_ACCURACY        = %ED_BASE+31&    '// returns one of the following:
%ED_SYNCACC_PRECISE             = %ED_BASE+32&
%ED_SYNCACC_FRAME               = %ED_BASE+33&
%ED_SYNCACC_ROUGH               = %ED_BASE+34&

'// returns device's normal framerate.
%ED_DEVCAP_NORMAL_RATE          = %ED_BASE+35&    '// returns one of the following:
%ED_RATE_24                     = %ED_BASE+36&
%ED_RATE_25                     = %ED_BASE+37&
%ED_RATE_2997                   = %ED_BASE+38&
%ED_RATE_30                     = %ED_BASE+39&

%ED_DEVCAP_CAN_PREVIEW          = %ED_BASE+40&
%ED_DEVCAP_CAN_MONITOR_SOURCES  = %ED_BASE+41&

'// indicates implementation allows testing of methods/parameters by
'// setting the hi bit of a parm that makes sense - see individual methods
'// for details.
%ED_DEVCAP_CAN_TEST             = %ED_BASE+42&

'// indicates device accepts video as an input.
%ED_DEVCAP_VIDEO_INPUTS         = %ED_BASE+43&

'// indicates device accepts audio as an input.
%ED_DEVCAP_AUDIO_INPUTS         = %ED_BASE+44&

%ED_DEVCAP_NEEDS_CALIBRATING    = %ED_BASE+45&

%ED_DEVCAP_SEEK_TYPE            = %ED_BASE+46&    '// returns one of the following:
%ED_SEEK_PERFECT                = %ED_BASE+47&    '// indicates device can execute seek
                                                  '// within 1 video frames without signal
                                                  '//    break (like a DDR)
%ED_SEEK_FAST                   = %ED_BASE+48&    '// indicates device can move pretty quick
                                                  '//  with short break in signal
%ED_SEEK_SLOW                   = %ED_BASE+49&    '// seeks like a tape transport

%ED_POWER_ON                    = %ED_BASE+50&
%ED_POWER_OFF                   = %ED_BASE+51&
%ED_POWER_STANDBY               = %ED_BASE+52&

%ED_POWER_DEVICE_DEPENDENT      = %ED_BASE+1033&  '// Power is on with limited functions

%ED_ACTIVE                      = %ED_BASE+53&
%ED_INACTIVE                    = %ED_BASE+54&
%ED_ALL                         = %ED_BASE+55&
%ED_TEST                        = %ED_BASE+56&

'//    IAMExtTransport Capability Items:  unless otherwise specified, these items return
'//       OATRUE or OAFALSE.  All return values are in pdwValue unless otherwise specified:

%ED_TRANSCAP_CAN_EJECT          = %ED_BASE+100&
%ED_TRANSCAP_CAN_BUMP_PLAY      = %ED_BASE+101&    '// variable speed for synchronizing
%ED_TRANSCAP_CAN_PLAY_BACKWARDS = %ED_BASE+102&    '// servo locked for use during an edit
%ED_TRANSCAP_CAN_SET_EE         = %ED_BASE+103&    '// show device's input on its output
%ED_TRANSCAP_CAN_SET_PB         = %ED_BASE+104&    '// show media playback on device's output
%ED_TRANSCAP_CAN_DELAY_VIDEO_IN = %ED_BASE+105&    '// transport can do delayed-in video edits
%ED_TRANSCAP_CAN_DELAY_VIDEO_OUT = %ED_BASE+106&   '// transport can do delayed-out video edits
%ED_TRANSCAP_CAN_DELAY_AUDIO_IN = %ED_BASE+107&    '// transport can do delayed-in audio edits
%ED_TRANSCAP_CAN_DELAY_AUDIO_OUT = %ED_BASE+108&   '// transport can do delayed-out audio edits
%ED_TRANSCAP_FWD_VARIABLE_MAX   = %ED_BASE+109&    '// max forward speed (multiple of play speed)
                                                       '//  in pdblValue
%ED_TRANSCAP_FWD_VARIABLE_MIN   = %ED_BASE+800&    '// min forward speed (multiple of play speed)
                                                       '//  in pdblValue
%ED_TRANSCAP_REV_VARIABLE_MAX   = %ED_BASE+110&    '// max reverse speed (multiple of play speed) in
                                                       '//  pdblValue
%ED_TRANSCAP_REV_VARIABLE_MIN   = %ED_BASE+801&    '// min reverse speed (multiple of play speed)
                                                       '//  in pdblValue
%ED_TRANSCAP_FWD_SHUTTLE_MAX    = %ED_BASE+802&    '// max forward speed in Shuttle mode (multiple
                                                       '//  of play speed) in pdblValue
%ED_TRANSCAP_FWD_SHUTTLE_MIN    = %ED_BASE+803&    '// min forward speed in Shuttle mode (multiple
                                                       '//  of play speed) in pdblValue
%ED_TRANSCAP_REV_SHUTTLE_MAX    = %ED_BASE+804&    '// max reverse speed in Shuttle mode (multiple
                                                       '//  of play speed) in pdblValue
%ED_TRANSCAP_REV_SHUTTLE_MIN    = %ED_BASE+805&    '// min reverse speed in Shuttle mode (multiple
                                                       '//  of play speed) in pdblValue
%ED_TRANSCAP_NUM_AUDIO_TRACKS   = %ED_BASE+111&    '// returns number of audio tracks
%ED_TRANSCAP_LTC_TRACK          = %ED_BASE+112&    '// returns track number of LTC timecode track.
                                                       '//  ED_ALL means no dedicated timecode track
%ED_TRANSCAP_NEEDS_TBC          = %ED_BASE+113&    '// device's output not stable
%ED_TRANSCAP_NEEDS_CUEING       = %ED_BASE+114&    '// device must be cued prior to performing edit
%ED_TRANSCAP_CAN_INSERT         = %ED_BASE+115&
%ED_TRANSCAP_CAN_ASSEMBLE       = %ED_BASE+116&
%ED_TRANSCAP_FIELD_STEP         = %ED_BASE+117&    '// device responds to Frame Advance command by
                                                       '//  advancing one field
%ED_TRANSCAP_CLOCK_INC_RATE     = %ED_BASE+118&    '// VISCA command - keep for compatibility
%ED_TRANSCAP_CAN_DETECT_LENGTH  = %ED_BASE+119&
%ED_TRANSCAP_CAN_FREEZE         = %ED_BASE+120&
%ED_TRANSCAP_HAS_TUNER          = %ED_BASE+121&
%ED_TRANSCAP_HAS_TIMER          = %ED_BASE+122&
%ED_TRANSCAP_HAS_CLOCK          = %ED_BASE+123&
%ED_TRANSCAP_MULTIPLE_EDITS     = %ED_BASE+806&    '// OATRUE means device/filter can support
                                                       '//  multiple edit events
%ED_TRANSCAP_IS_MASTER          = %ED_BASE+807&    '// OATRUE means device is the master clock
                                                       '//  for synchronizing (this sets timecode-to-
                                                       '//  reference clock offset for editing)
%ED_TRANSCAP_HAS_DT             = %ED_BASE+814&    '// OATRUE means device has Dynamic Tracking

'//    IAMExtTransport Media States
%ED_MEDIA_SPIN_UP               = %ED_BASE+130&
%ED_MEDIA_SPIN_DOWN             = %ED_BASE+131&
%ED_MEDIA_UNLOAD                = %ED_BASE+132&

'//    IAMExtTransport Modes
%ED_MODE_PLAY                   = %ED_BASE+200&    '// Forward playback at normal speed
%ED_MODE_STOP                   = %ED_BASE+201&
%ED_MODE_FREEZE                 = %ED_BASE+202&    '// Forward pause
%ED_MODE_THAW                   = %ED_BASE+203&
%ED_MODE_FF                     = %ED_BASE+204&    '// Fast forward
%ED_MODE_REW                    = %ED_BASE+205&    '// Fast rewind
%ED_MODE_RECORD                 = %ED_BASE+206&
%ED_MODE_RECORD_STROBE          = %ED_BASE+207&
%ED_MODE_RECORD_FREEZE          = %ED_BASE+808&    '// Pause recording
%ED_MODE_STEP                   = %ED_BASE+208&    '// same as "jog"
%ED_MODE_STEP_FWD               = %ED_BASE+208&    '// same as ED_MODE_STEP - next frame
%ED_MODE_STEP_REV               = %ED_BASE+809&    '// Previous frame
%ED_MODE_SHUTTLE                = %ED_BASE+209&
%ED_MODE_EDIT_CUE               = %ED_BASE+210&
%ED_MODE_VAR_SPEED              = %ED_BASE+211&
%ED_MODE_PERFORM                = %ED_BASE+212&    '// returned status only
%ED_MODE_LINK_ON                = %ED_BASE+280&
%ED_MODE_LINK_OFF               = %ED_BASE+281&
%ED_MODE_NOTIFY_ENABLE          = %ED_BASE+810&
%ED_MODE_NOTIFY_DISABLE         = %ED_BASE+811&
%ED_MODE_SHOT_SEARCH            = %ED_BASE+812&


'//    IAMTimecodeReader/Generator/Display defines
'//
'// Timecode Generator Mode params and values:
'//
%ED_TCG_TIMECODE_TYPE           = %ED_BASE+400&    '// can be one of the following:
%ED_TCG_SMPTE_LTC               = %ED_BASE+401&
%ED_TCG_SMPTE_VITC              = %ED_BASE+402&
%ED_TCG_MIDI_QF                 = %ED_BASE+403&
%ED_TCG_MIDI_FULL               = %ED_BASE+404&

%ED_TCG_FRAMERATE               = %ED_BASE+405&    '// can be one of the following:
%ED_FORMAT_SMPTE_30             = %ED_BASE+406&
%ED_FORMAT_SMPTE_30DROP         = %ED_BASE+407&
%ED_FORMAT_SMPTE_25             = %ED_BASE+408&
%ED_FORMAT_SMPTE_24             = %ED_BASE+409&

%ED_TCG_SYNC_SOURCE             = %ED_BASE+410&    '// can be one of the following:
%ED_TCG_VIDEO                   = %ED_BASE+411&
%ED_TCG_READER                  = %ED_BASE+412&
%ED_TCG_FREE                    = %ED_BASE+413&

%ED_TCG_REFERENCE_SOURCE        = %ED_BASE+414&    '// can have one these values:
                                                       '//    ED_TCG_FREE || ED_TCG_READER
                                                       '//    (for regen/jamsync)

'// TimeCodeReader Mode params and values:
%ED_TCR_SOURCE                  = %ED_BASE+416&    '// can be one of the following:
'// ED_TCG (already defined)
%ED_TCR_LTC                     = %ED_BASE+417&
%ED_TCR_VITC                    = %ED_BASE+418&
%ED_TCR_CT                      = %ED_BASE+419&    '// Control Track
%ED_TCR_FTC                     = %ED_BASE+420&    '// File TimeCode - for file-based devices
                                                '//  that wish they were transports
'// ED_MODE_NOTIFY_ENABLE can be OATRUE or OAFALSE (defined in transport mode
'//  section of this file).
%ED_TCR_LAST_VALUE              = %ED_BASE+421&    '// for notification mode -
                                                '//  successive calls to GetTimecode
                                                '//  return the last read value
'// TimeCode Display Mode params and values:
'//
%ED_TCD_SOURCE                  = %ED_BASE+422&    '// can be one of the following:
%ED_TCR                         = %ED_BASE+423&
%ED_TCG                         = %ED_BASE+424&

%ED_TCD_SIZE                    = %ED_BASE+425&    '// can be one of the following:
%ED_SMALL                       = %ED_BASE+426&
%ED_MED                         = %ED_BASE+427&
%ED_LARGE                       = %ED_BASE+428&

%ED_TCD_POSITION                = %ED_BASE+429&    '// can be one of the following:
%ED_TOP                         = &H0001&
%ED_MIDDLE                      = &H0002&
%ED_BOTTOM                      = &H0004&          '// or'd  with
%ED_LEFT                        = &H0100&
%ED_CENTER                      = &H0200&
%ED_RIGHT                       = &H0400&

%ED_TCD_INTENSITY               = %ED_BASE+436&    '// can be one of the following:
%ED_HIGH                        = %ED_BASE+437&
%ED_LOW                         = %ED_BASE+438&

%ED_TCD_TRANSPARENCY            = %ED_BASE+439&    '// 0-4, 0 is opaque

%ED_TCD_INVERT                  = %ED_BASE+440&    '// OATRUE=black on white
                                                       '// OAFALSE=white on black
'//    IAMExtTransport defines
'//
'// Transport status, params and values
'//

'// IAMExtTransport Status items and and values:
%ED_MODE                        = %ED_BASE+500&    '// see ED_MODE_xxx values above
%ED_ERROR                       = %ED_BASE+501&
%ED_LOCAL                       = %ED_BASE+502&
%ED_RECORD_INHIBIT              = %ED_BASE+503&
%ED_SERVO_LOCK                  = %ED_BASE+504&
%ED_MEDIA_PRESENT               = %ED_BASE+505&
%ED_MEDIA_LENGTH                = %ED_BASE+506&
%ED_MEDIA_SIZE                  = %ED_BASE+507&
%ED_MEDIA_TRACK_COUNT           = %ED_BASE+508&
%ED_MEDIA_TRACK_LENGTH          = %ED_BASE+509&
%ED_MEDIA_SIDE                  = %ED_BASE+510&

%ED_MEDIA_TYPE                  = %ED_BASE+511&    '// can be one of the following:
%ED_MEDIA_VHS                   = %ED_BASE+512&
%ED_MEDIA_SVHS                  = %ED_BASE+513&
%ED_MEDIA_HI8                   = %ED_BASE+514&
%ED_MEDIA_UMATIC                = %ED_BASE+515&
%ED_MEDIA_DVC                   = %ED_BASE+516&
%ED_MEDIA_1_INCH                = %ED_BASE+517&
%ED_MEDIA_D1                    = %ED_BASE+518&
%ED_MEDIA_D2                    = %ED_BASE+519&
%ED_MEDIA_D3                    = %ED_BASE+520&
%ED_MEDIA_D5                    = %ED_BASE+521&
%ED_MEDIA_DBETA                 = %ED_BASE+522&
%ED_MEDIA_BETA                  = %ED_BASE+523&
%ED_MEDIA_8MM                   = %ED_BASE+524&
%ED_MEDIA_DDR                   = %ED_BASE+525&
%ED_MEDIA_SX                    = %ED_BASE+813&
%ED_MEDIA_OTHER                 = %ED_BASE+526&
%ED_MEDIA_CLV                   = %ED_BASE+527&
%ED_MEDIA_CAV                   = %ED_BASE+528&
%ED_MEDIA_POSITION              = %ED_BASE+529&

%ED_MEDIA_NEO                   = %ED_BASE+531&    '// Mini digital tape for MPEG2TS signal
%ED_MEDIA_MICROMV               = %ED_MEDIA_NEO

%ED_LINK_MODE                   = %ED_BASE+530&    '// OATRUE if transport controls
                                                   '// are linked to graph's RUN,
                                                   '// STOP, and PAUSE methods

'// IAMExtTransport Basic Parms
%ED_TRANSBASIC_TIME_FORMAT      = %ED_BASE+540&    '// can be one of the following:
%ED_FORMAT_MILLISECONDS         = %ED_BASE+541&
%ED_FORMAT_FRAMES               = %ED_BASE+542&
%ED_FORMAT_REFERENCE_TIME       = %ED_BASE+543&

%ED_FORMAT_HMSF                 = %ED_BASE+547&
%ED_FORMAT_TMSF                 = %ED_BASE+548&

%ED_TRANSBASIC_TIME_REFERENCE   = %ED_BASE+549&    '// can be one of the following:
%ED_TIMEREF_TIMECODE            = %ED_BASE+550&
%ED_TIMEREF_CONTROL_TRACK       = %ED_BASE+551&
%ED_TIMEREF_INDEX               = %ED_BASE+552&

%ED_TRANSBASIC_SUPERIMPOSE      = %ED_BASE+553&    '// enable/disable onscreen display
%ED_TRANSBASIC_END_STOP_ACTION  = %ED_BASE+554&    '// can be one of: ED_MODE_STOP |
                                                   '//    ED_MODE_REWIND | ED_MODE_FREEZE
%ED_TRANSBASIC_RECORD_FORMAT    = %ED_BASE+555&    '// can be one of the following:
%ED_RECORD_FORMAT_SP            = %ED_BASE+556&
%ED_RECORD_FORMAT_LP            = %ED_BASE+557&
%ED_RECORD_FORMAT_EP            = %ED_BASE+558&

%ED_TRANSBASIC_STEP_COUNT       = %ED_BASE+559&
%ED_TRANSBASIC_STEP_UNIT        = %ED_BASE+560&    '// can be one of the following:
%ED_STEP_FIELD                  = %ED_BASE+561&
%ED_STEP_FRAME                  = %ED_BASE+562&
%ED_STEP_3_2                    = %ED_BASE+563&

%ED_TRANSBASIC_PREROLL          = %ED_BASE+564&
%ED_TRANSBASIC_RECPREROLL       = %ED_BASE+565&
%ED_TRANSBASIC_POSTROLL         = %ED_BASE+566&
%ED_TRANSBASIC_EDIT_DELAY       = %ED_BASE+567&
%ED_TRANSBASIC_PLAYTC_DELAY     = %ED_BASE+568&
%ED_TRANSBASIC_RECTC_DELAY      = %ED_BASE+569&
%ED_TRANSBASIC_EDIT_FIELD       = %ED_BASE+570&
%ED_TRANSBASIC_FRAME_SERVO      = %ED_BASE+571&
%ED_TRANSBASIC_CF_SERVO         = %ED_BASE+572&
%ED_TRANSBASIC_SERVO_REF        = %ED_BASE+573&    '// can be one of the following:
%ED_REF_EXTERNAL                = %ED_BASE+574&
%ED_REF_INPUT                   = %ED_BASE+575&
%ED_REF_INTERNAL                = %ED_BASE+576&
%ED_REF_AUTO                    = %ED_BASE+577&

%ED_TRANSBASIC_WARN_GL          = %ED_BASE+578&
%ED_TRANSBASIC_SET_TRACKING     = %ED_BASE+579&    '// can be one of the following:
%ED_TRACKING_PLUS               = %ED_BASE+580&
%ED_TRACKING_MINUS              = %ED_BASE+581&
%ED_TRACKING_RESET              = %ED_BASE+582&

%ED_TRANSBASIC_SET_FREEZE_TIMEOUT = %ED_BASE+583&
%ED_TRANSBASIC_VOLUME_NAME      = %ED_BASE+584&
%ED_TRANSBASIC_BALLISTIC_1      = %ED_BASE+585&    '// space for proprietary data
%ED_TRANSBASIC_BALLISTIC_2      = %ED_BASE+586&
%ED_TRANSBASIC_BALLISTIC_3      = %ED_BASE+587&
%ED_TRANSBASIC_BALLISTIC_4      = %ED_BASE+588&
%ED_TRANSBASIC_BALLISTIC_5      = %ED_BASE+589&
%ED_TRANSBASIC_BALLISTIC_6      = %ED_BASE+590&
%ED_TRANSBASIC_BALLISTIC_7      = %ED_BASE+591&
%ED_TRANSBASIC_BALLISTIC_8      = %ED_BASE+592&
%ED_TRANSBASIC_BALLISTIC_9      = %ED_BASE+593&
%ED_TRANSBASIC_BALLISTIC_10     = %ED_BASE+594&
%ED_TRANSBASIC_BALLISTIC_11     = %ED_BASE+595&
%ED_TRANSBASIC_BALLISTIC_12     = %ED_BASE+596&
%ED_TRANSBASIC_BALLISTIC_13     = %ED_BASE+597&
%ED_TRANSBASIC_BALLISTIC_14     = %ED_BASE+598&
%ED_TRANSBASIC_BALLISTIC_15     = %ED_BASE+599&
%ED_TRANSBASIC_BALLISTIC_16     = %ED_BASE+600&
%ED_TRANSBASIC_BALLISTIC_17     = %ED_BASE+601&
%ED_TRANSBASIC_BALLISTIC_18     = %ED_BASE+602&
%ED_TRANSBASIC_BALLISTIC_19     = %ED_BASE+603&
%ED_TRANSBASIC_BALLISTIC_20     = %ED_BASE+604&

'// consumer VCR items
%ED_TRANSBASIC_SETCLOCK         = %ED_BASE+605&
%ED_TRANSBASIC_SET_COUNTER_FORMAT = %ED_BASE+606&    '// uses time format flags
%ED_TRANSBASIC_SET_COUNTER_VALUE = %ED_BASE+607&

%ED_TRANSBASIC_SETTUNER_CH_UP   = %ED_BASE+608&
%ED_TRANSBASIC_SETTUNER_CH_DN   = %ED_BASE+609&
%ED_TRANSBASIC_SETTUNER_SK_UP   = %ED_BASE+610&
%ED_TRANSBASIC_SETTUNER_SK_DN   = %ED_BASE+611&
%ED_TRANSBASIC_SETTUNER_CH      = %ED_BASE+612&
%ED_TRANSBASIC_SETTUNER_NUM     = %ED_BASE+613&

%ED_TRANSBASIC_SETTIMER_EVENT   = %ED_BASE+614&
%ED_TRANSBASIC_SETTIMER_STARTDAY = %ED_BASE+615&
%ED_TRANSBASIC_SETTIMER_STARTTIME = %ED_BASE+616&
%ED_TRANSBASIC_SETTIMER_STOPDAY = %ED_BASE+617&
%ED_TRANSBASIC_SETTIMER_STOPTIME = %ED_BASE+618&

'// IAMExtTransport video parameters
%ED_TRANSVIDEO_SET_OUTPUT       = %ED_BASE+630&    '// can be one of the following:
%ED_E2E                         = %ED_BASE+631&
%ED_PLAYBACK                    = %ED_BASE+632&
%ED_OFF                         = %ED_BASE+633&

%ED_TRANSVIDEO_SET_SOURCE       = %ED_BASE+634&

'// IAMExtTransport audio parameters
%ED_TRANSAUDIO_ENABLE_OUTPUT    = %ED_BASE+640&    '// can be the following:
%ED_AUDIO_ALL                   = &H10000000&    '//    or any of the following OR'd together
%ED_AUDIO_1                     = &H0000001&
%ED_AUDIO_2                     = &H0000002&
%ED_AUDIO_3                     = &H0000004&
%ED_AUDIO_4                     = &H0000008&
%ED_AUDIO_5                     = &H0000010&
%ED_AUDIO_6                     = &H0000020&
%ED_AUDIO_7                     = &H0000040&
%ED_AUDIO_8                     = &H0000080&
%ED_AUDIO_9                     = &H0000100&
%ED_AUDIO_10                    = &H0000200&
%ED_AUDIO_11                    = &H0000400&
%ED_AUDIO_12                    = &H0000800&
%ED_AUDIO_13                    = &H0001000&
%ED_AUDIO_14                    = &H0002000&
%ED_AUDIO_15                    = &H0004000&
%ED_AUDIO_16                    = &H0008000&
%ED_AUDIO_17                    = &H0010000&
%ED_AUDIO_18                    = &H0020000&
%ED_AUDIO_19                    = &H0040000&
%ED_AUDIO_20                    = &H0080000&
%ED_AUDIO_21                    = &H0100000&
%ED_AUDIO_22                    = &H0200000&
%ED_AUDIO_23                    = &H0400000&
%ED_AUDIO_24                    = &H0800000&
%ED_VIDEO                       = &H2000000&    '// for Edit props below

%ED_TRANSAUDIO_ENABLE_RECORD    = %ED_BASE+642&
%ED_TRANSAUDIO_ENABLE_SELSYNC   = %ED_BASE+643&
%ED_TRANSAUDIO_SET_SOURCE       = %ED_BASE+644&
%ED_TRANSAUDIO_SET_MONITOR      = %ED_BASE+645&


'// Edit Property Set-related defs

'// The following values reflect (and control) the state of an
'// edit property set
%ED_INVALID                     = %ED_BASE+652&
%ED_EXECUTING                   = %ED_BASE+653&
%ED_REGISTER                    = %ED_BASE+654&
%ED_DELETE                      = %ED_BASE+655&

'// Edit property set parameters and values
%ED_EDIT_HEVENT                 = %ED_BASE+656&    '// event handle to signal event
                                                   '// completion
%ED_EDIT_TEST                   = %ED_BASE+657&    '// returns OAFALSE if filter thinks
                                                   '//  edit can be done, OATRUE if not
%ED_EDIT_IMMEDIATE              = %ED_BASE+658&    '// OATRUE means start put the
                                                   '// device into edit mode (editing
                                                   '// "on the fly") immediately upon
                                                   '//  execution of Mode(ED_MODE_EDIT_CUE)
%ED_EDIT_MODE                   = %ED_BASE+659&
'// can be one of the following values:
%ED_EDIT_MODE_ASSEMBLE          = %ED_BASE+660&
%ED_EDIT_MODE_INSERT            = %ED_BASE+661&
%ED_EDIT_MODE_CRASH_RECORD      = %ED_BASE+662&
%ED_EDIT_MODE_BOOKMARK_TIME     = %ED_BASE+663&    '// these two are for
%ED_EDIT_MODE_BOOKMARK_CHAPTER  = %ED_BASE+664&    '// laserdisks

%ED_EDIT_MASTER                 = %ED_BASE+666&    '// OATRUE causes device
                                                       '//  not to synchronize

%ED_EDIT_TRACK        = %ED_BASE+667&
'// can be one of the following possible OR'd values:
'//    ED_VIDEO, ED_AUDIO_1 thru ED_AUDIO_24 (or ED_AUDIO_ALL)

%ED_EDIT_SRC_INPOINT            = %ED_BASE+668&    '// in current time format
%ED_EDIT_SRC_OUTPOINT           = %ED_BASE+669&    '// in current time format
%ED_EDIT_REC_INPOINT            = %ED_BASE+670&    '// in current time format
%ED_EDIT_REC_OUTPOINT           = %ED_BASE+671&    '// in current time format

%ED_EDIT_REHEARSE_MODE          = %ED_BASE+672&
'// can be one of the following possible values:
%ED_EDIT_BVB                    = %ED_BASE+673&    '// means rehearse the edit with
                                                   '//  "black-video-black"
%ED_EDIT_VBV                    = %ED_BASE+674&
%ED_EDIT_VVV                    = %ED_BASE+675&
%ED_EDIT_PERFORM                = %ED_BASE+676&    '// means perform the edit with no
                                                   '//  rehearsal.

'// Set this property to OATRUE to kill the edit if in progress
%ED_EDIT_ABORT                  = %ED_BASE+677&
'// how long to wait for edit to complete
%ED_EDIT_TIMEOUT                = %ED_BASE+678&        '// in current time format

'// This property causes the device to seek to a point specified by
'// ED_EDIT_SEEK_MODE (see below).  NOTE: Only one event at a time can seek.
%ED_EDIT_SEEK                   = %ED_BASE+679&    '// OATRUE means do it now.
%ED_EDIT_SEEK_MODE              = %ED_BASE+680&
'//possible values:
%ED_EDIT_SEEK_EDIT_IN           = %ED_BASE+681&    '// seek to edit's inpoint
%ED_EDIT_SEEK_EDIT_OUT          = %ED_BASE+682&    '// seek to edit's outpoint
%ED_EDIT_SEEK_PREROLL           = %ED_BASE+683&    '// seek to edit's
                                                   '//  inpoint-preroll
%ED_EDIT_SEEK_PREROLL_CT        = %ED_BASE+684&    '// seek to preroll point
                                                   '// using control track (used for tapes with
                                                   '// discontinuoustimecode before edit point: seek
                                                   '// to inpoint using timecode, then backup to
                                                   '// preroll point using control track)
%ED_EDIT_SEEK_BOOKMARK          = %ED_BASE+685&    '// seek to bookmark (just like
                                                   '//  timecode search)
'// This property is used for multiple-VCR systems where each machine must
'// cue to a different location relative to the graph's reference clock.  The
'// basic idea is that an edit event is setup with an ED_EDIT_OFFSET property
'// that tells the VCR what offset to maintain between it's timecode (converted
'// to reference clock units) and the reference clock.
%ED_EDIT_OFFSET                 = %ED_BASE+686&    '// in current time format

%ED_EDIT_PREREAD                = %ED_BASE+815&    '// OATRUE means device supports
                                                   '//  pre-read (recorder can also be
                                                   '//  player

'//
'// Some error codes:
'//
'// device could be in local mode
%ED_ERR_DEVICE_NOT_READY        = %ED_BASE+700&

'// **************************************************
'//
'// New constants
'//
'// **************************************************


'//
'// Additional Device type
'//
%ED_DEVTYPE_CAMERA              = %ED_BASE+900&

%ED_DEVTYPE_TUNER               = %ED_BASE+901&

%ED_DEVTYPE_DVHS                = %ED_BASE+902&     '// Digital VHS

%ED_DEVTYPE_UNKNOWN             = %ED_BASE+903&     '// Driver cannot determine the device type

%ED_DEVTYPE_CAMERA_STORAGE      = %ED_BASE+1034&    '// Storage for digital still images, short video files, etc.

%ED_DEVTYPE_DTV                 = %ED_BASE+1035&    '// DTV with serial bus interface

%ED_DEVTYPE_PC_VIRTUAL          = %ED_BASE+1036&    '// Emulated device (virtual) on a PC



'//
'// Unknownn capability
'//     Instead of return E_NOTIMPL, or S_OK with OAFALSE, it may return S_OK with _UNKNOWN
'//
%ED_CAPABILITY_UNKNOWN          = %ED_BASE+910&


'//
'// Send raw 1394/AVC extenal device command via GetTransportBasicParameters()
'// This is specifically for a 1394 AVC device connected with DEV_PORT_1394.
'//
%ED_RAW_EXT_DEV_CMD             = %ED_BASE+920&


'//
'// MEDIUM INFO
'//
%ED_MEDIA_VHSC                  = %ED_BASE+925&  '// New media type
%ED_MEDIA_UNKNOWN               = %ED_BASE+926&  '// Unknown media
%ED_MEDIA_NOT_PRESENT           = %ED_BASE+927&


'//
'// Device Control command that can result in pending state.
'//
%ED_CONTROL_HEVENT_GET          = %ED_BASE+928&  '// To get a sychronous event handle
%ED_CONTROL_HEVENT_RELEASE      = %ED_BASE+929&  '// To release sychronous event handle must match what it got

%ED_DEV_REMOVED_HEVENT_GET      = %ED_BASE+960&  '// To be a notify event and will be signal if device is removed.
%ED_DEV_REMOVED_HEVENT_RELEASE  = %ED_BASE+961&  '// Release this event handle


'//
'// TRANSPORT STATE
'//
%ED_NOTIFY_HEVENT_GET           = %ED_BASE+930&  '// To get a sychronous event handle
%ED_NOTIFY_HEVENT_RELEASE       = %ED_BASE+931&  '// To release sychronous event handle must match what it got
%ED_MODE_CHANGE_NOTIFY          = %ED_BASE+932&  '// This is asynchronous operation, wait for event.

%ED_MODE_PLAY_FASTEST_FWD       = %ED_BASE+933&
%ED_MODE_PLAY_SLOWEST_FWD       = %ED_BASE+934&
%ED_MODE_PLAY_FASTEST_REV       = %ED_BASE+935&
%ED_MODE_PLAY_SLOWEST_REV       = %ED_BASE+936&

%ED_MODE_WIND                   = %ED_BASE+937&
%ED_MODE_REW_FASTEST            = %ED_BASE+938&  '// High speed rewind

%ED_MODE_REV_PLAY               = %ED_BASE+939&  '// x1 speed reverse play

'//
'// Additional play modes (added post Windows XP)
'//

%ED_MODE_PLAY_SLOW_FWD_6        = %ED_BASE+1001&  '// Slow forward
%ED_MODE_PLAY_SLOW_FWD_5        = %ED_BASE+1002&
%ED_MODE_PLAY_SLOW_FWD_4        = %ED_BASE+1003&
%ED_MODE_PLAY_SLOW_FWD_3        = %ED_BASE+1004&
%ED_MODE_PLAY_SLOW_FWD_2        = %ED_BASE+1005&
%ED_MODE_PLAY_SLOW_FWD_1        = %ED_BASE+1006&

%ED_MODE_PLAY_FAST_FWD_1        = %ED_BASE+1007&  '// Fast forward
%ED_MODE_PLAY_FAST_FWD_2        = %ED_BASE+1008&
%ED_MODE_PLAY_FAST_FWD_3        = %ED_BASE+1009&
%ED_MODE_PLAY_FAST_FWD_4        = %ED_BASE+1010&
%ED_MODE_PLAY_FAST_FWD_5        = %ED_BASE+1011&
%ED_MODE_PLAY_FAST_FWD_6        = %ED_BASE+1012&

%ED_MODE_PLAY_SLOW_REV_6        = %ED_BASE+1013&  '// Slow reverse
%ED_MODE_PLAY_SLOW_REV_5        = %ED_BASE+1014&
%ED_MODE_PLAY_SLOW_REV_4        = %ED_BASE+1015&
%ED_MODE_PLAY_SLOW_REV_3        = %ED_BASE+1016&
%ED_MODE_PLAY_SLOW_REV_2        = %ED_BASE+1017&
%ED_MODE_PLAY_SLOW_REV_1        = %ED_BASE+1018&

%ED_MODE_PLAY_FAST_REV_1        = %ED_BASE+1019&  '// Fast reverse
%ED_MODE_PLAY_FAST_REV_2        = %ED_BASE+1020&
%ED_MODE_PLAY_FAST_REV_3        = %ED_BASE+1021&
%ED_MODE_PLAY_FAST_REV_4        = %ED_BASE+1022&
%ED_MODE_PLAY_FAST_REV_5        = %ED_BASE+1023&
%ED_MODE_PLAY_FAST_REV_6        = %ED_BASE+1024&

%ED_MODE_REVERSE                = %ED_MODE_REV_PLAY '// Same as Reverse playback
%ED_MODE_REVERSE_FREEZE         = %ED_BASE+1025&    '// Pause at reverse playback

%ED_MODE_PLAY_SLOW_FWD_X        = %ED_BASE+1026&    '// Possible response for a trick play
%ED_MODE_PLAY_FAST_FWD_X        = %ED_BASE+1027&    '// Possible response for a trick play
%ED_MODE_PLAY_SLOW_REV_X        = %ED_BASE+1028&    '// Possible response for a trick play
%ED_MODE_PLAY_FAST_REV_X        = %ED_BASE+1029&    '// Possible response for a trick play

%ED_MODE_STOP_START             = %ED_BASE+1030&    '// Indicate stopping at the begin of a tape
%ED_MODE_STOP_END               = %ED_BASE+1031&    '// Indicate stopping at the end of a tape
%ED_MODE_STOP_EMERGENCY         = %ED_BASE+1032&    '// Indicate stopping due to an emergency

'//
'// TRANSPOSRTBASIC: input and output signal
'//
%ED_TRANSBASIC_INPUT_SIGNAL        = %ED_BASE+940&
%ED_TRANSBASIC_OUTPUT_SIGNAL       = %ED_BASE+941&

%ED_TRANSBASIC_SIGNAL_525_60_SD    = %ED_BASE+942&
%ED_TRANSBASIC_SIGNAL_525_60_SDL   = %ED_BASE+943&
%ED_TRANSBASIC_SIGNAL_625_50_SD    = %ED_BASE+944&
%ED_TRANSBASIC_SIGNAL_625_50_SDL   = %ED_BASE+945&

%ED_TRANSBASIC_SIGNAL_625_60_HD    = %ED_BASE+947&
%ED_TRANSBASIC_SIGNAL_625_50_HD    = %ED_BASE+948&

%ED_TRANSBASIC_SIGNAL_MPEG2TS      = %ED_BASE+946&

%ED_TRANSBASIC_SIGNAL_2500_60_MPEG = %ED_BASE+980&
%ED_TRANSBASIC_SIGNAL_1250_60_MPEG = %ED_BASE+981&
%ED_TRANSBASIC_SIGNAL_0625_60_MPEG = %ED_BASE+982&

%ED_TRANSBASIC_SIGNAL_2500_50_MPEG = %ED_BASE+985&
%ED_TRANSBASIC_SIGNAL_1250_50_MPEG = %ED_BASE+986&
%ED_TRANSBASIC_SIGNAL_0625_50_MPEG = %ED_BASE+987&

%ED_TRANSBASIC_SIGNAL_UNKNOWN      = %ED_BASE+990&

%ED_TRANSBASIC_SIGNAL_525_60_DV25  = %ED_BASE+991&
%ED_TRANSBASIC_SIGNAL_625_50_DV25  = %ED_BASE+992&

%ED_TRANSBASIC_SIGNAL_525_60_DV50  = %ED_BASE+993&
%ED_TRANSBASIC_SIGNAL_625_50_DV50  = %ED_BASE+994&

%ED_TRANSBASIC_SIGNAL_HD_60_DVH1   = %ED_BASE+995&  '// DVCPRO 100: 1080i or 720p
%ED_TRANSBASIC_SIGNAL_HD_50_DVH1   = %ED_BASE+996&  '// DVCPRO 100: 1080i only



'//
'// TIMECODE/AbsoluteTrackNumber/RealTimeCounter read/seek/write
'//
%ED_DEVCAP_TIMECODE_SEEK        = %ED_BASE+950&

%ED_DEVCAP_ATN_READ             = %ED_BASE+951&
%ED_DEVCAP_ATN_SEEK             = %ED_BASE+952&
%ED_DEVCAP_ATN_WRITE            = %ED_BASE+953&

%ED_DEVCAP_RTC_READ             = %ED_BASE+954&
%ED_DEVCAP_RTC_SEEK             = %ED_BASE+955&
%ED_DEVCAP_RTC_WRITE            = %ED_BASE+956&

'//
'// Basic parameter
'//
%ED_TIMEREF_ATN                 = %ED_BASE+958&


'//
'// GUID used to identify a class driver
'//

'#ifndef OUR_GUID_ENTRY
'    %OUR_GUID_ENTRY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
'    DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8);
'#endif

#IF NOT %DEF(%OUR_GUID_ENTRY)
%OUR_GUID_ENTRY = 1
MACRO OUR_GUID_ENTRY(guidName, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
    guidName.Data1    = l
    guidName.Data2    = w1
    guidName.Data3    = w2
    guidName.Data4(0) = b1
    guidName.Data4(1) = b2
    guidName.Data4(2) = b3
    guidName.Data4(3) = b4
    guidName.Data4(4) = b5
    guidName.Data4(5) = b6
    guidName.Data4(6) = b7
    guidName.Data4(7) = b8
END MACRO
#ENDIF

'// 8C0F6AF2-0EDB-44c1-8AEB-59040BD830ED  MSTapeDeviceGUID
$MSTapeDeviceGUID = GUID$("{8C0F6AF2-0EDB-44c1-8AEB-59040BD830ED}")
