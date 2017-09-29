' ########################################################################################
' Microsoft Windows
' File: wiadef.inc
' Contents: WIA constant definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WIADEF_INC = 1

'//
'// Set packing
'//
'#include <pshpack8.h>

#INCLUDE ONCE "objbase.inc"

'//
'// WIA property ID and string constants
'//

%WIA_DIP_DEV_ID                              = 2 ' // 0x2
$$WIA_DIP_DEV_ID_STR                         = "Unique Device ID"$$

%WIA_DIP_VEND_DESC                           = 3 ' // 0x3
$$WIA_DIP_VEND_DESC_STR                      = "Manufacturer"$$

%WIA_DIP_DEV_DESC                            = 4 ' // 0x4
$$WIA_DIP_DEV_DESC_STR                       = "Description"$$

%WIA_DIP_DEV_TYPE                            = 5 ' // 0x5
$$WIA_DIP_DEV_TYPE_STR                       = "Type"$$

%WIA_DIP_PORT_NAME                           = 6 ' // 0x6
$$WIA_DIP_PORT_NAME_STR                      = "Port"$$

%WIA_DIP_DEV_NAME                            = 7 ' // 0x7
$$WIA_DIP_DEV_NAME_STR                       = "Name"$$

%WIA_DIP_SERVER_NAME                         = 8 ' // 0x8
$$WIA_DIP_SERVER_NAME_STR                    = "Server"$$

%WIA_DIP_REMOTE_DEV_ID                       = 9 ' // 0x9
$$WIA_DIP_REMOTE_DEV_ID_STR                  = "Remote Device ID"$$

%WIA_DIP_UI_CLSID                            = 10 ' // 0xa
$$WIA_DIP_UI_CLSID_STR                       = "UI Class ID"$$

%WIA_DIP_HW_CONFIG                           = 11 ' // 0xb
$$WIA_DIP_HW_CONFIG_STR                      = "Hardware Configuration"$$

%WIA_DIP_BAUDRATE                            = 12 ' // 0xc
$$WIA_DIP_BAUDRATE_STR                       = "BaudRate"$$

%WIA_DIP_STI_GEN_CAPABILITIES                = 13 ' // 0xd
$$WIA_DIP_STI_GEN_CAPABILITIES_STR           = "STI Generic Capabilities"$$

%WIA_DIP_WIA_VERSION                         = 14 ' // 0xe
$$WIA_DIP_WIA_VERSION_STR                    = "WIA Version"$$

%WIA_DIP_DRIVER_VERSION                      = 15 ' // 0xf
$$WIA_DIP_DRIVER_VERSION_STR                 = "Driver Version"$$

%WIA_DIP_PNP_ID                              = 16 ' // 0x10
$$WIA_DIP_PNP_ID_STR                         = "PnP ID String"$$

%WIA_DIP_STI_DRIVER_VERSION                  = 17 ' // 0x11
$$WIA_DIP_STI_DRIVER_VERSION_STR             = "STI Driver Version"$$

%WIA_DPA_FIRMWARE_VERSION                    = 1026 ' // 0x402
$$WIA_DPA_FIRMWARE_VERSION_STR               = "Firmware Version"$$

%WIA_DPA_CONNECT_STATUS                      = 1027 ' // 0x403
$$WIA_DPA_CONNECT_STATUS_STR                 = "Connect Status"$$

%WIA_DPA_DEVICE_TIME                         = 1028 ' // 0x404
$$WIA_DPA_DEVICE_TIME_STR                    = "Device Time"$$

%WIA_DPC_PICTURES_TAKEN                      = 2050 ' // 0x802
$$WIA_DPC_PICTURES_TAKEN_STR                 = "Pictures Taken"$$

%WIA_DPC_PICTURES_REMAINING                  = 2051 ' // 0x803
$$WIA_DPC_PICTURES_REMAINING_STR             = "Pictures Remaining"$$

%WIA_DPC_EXPOSURE_MODE                       = 2052 ' // 0x804
$$WIA_DPC_EXPOSURE_MODE_STR                  = "Exposure Mode"$$

%WIA_DPC_EXPOSURE_COMP                       = 2053 ' // 0x805
$$WIA_DPC_EXPOSURE_COMP_STR                  = "Exposure Compensation"$$

%WIA_DPC_EXPOSURE_TIME                       = 2054 ' // 0x806
$$WIA_DPC_EXPOSURE_TIME_STR                  = "Exposure Time"$$

%WIA_DPC_FNUMBER                             = 2055 ' // 0x807
$$WIA_DPC_FNUMBER_STR                        = "F Number"$$

%WIA_DPC_FLASH_MODE                          = 2056 ' // 0x808
$$WIA_DPC_FLASH_MODE_STR                     = "Flash Mode"$$

%WIA_DPC_FOCUS_MODE                          = 2057 ' // 0x809
$$WIA_DPC_FOCUS_MODE_STR                     = "Focus Mode"$$

%WIA_DPC_FOCUS_MANUAL_DIST                   = 2058 ' // 0x80a
$$WIA_DPC_FOCUS_MANUAL_DIST_STR              = "Focus Manual Dist"$$

%WIA_DPC_ZOOM_POSITION                       = 2059 ' // 0x80b
$$WIA_DPC_ZOOM_POSITION_STR                  = "Zoom Position"$$

%WIA_DPC_PAN_POSITION                        = 2060 ' // 0x80c
$$WIA_DPC_PAN_POSITION_STR                   = "Pan Position"$$

%WIA_DPC_TILT_POSITION                       = 2061 ' // 0x80d
$$WIA_DPC_TILT_POSITION_STR                  = "Tilt Position"$$

%WIA_DPC_TIMER_MODE                          = 2062 ' // 0x80e
$$WIA_DPC_TIMER_MODE_STR                     = "Timer Mode"$$

%WIA_DPC_TIMER_VALUE                         = 2063 ' // 0x80f
$$WIA_DPC_TIMER_VALUE_STR                    = "Timer Value"$$

%WIA_DPC_POWER_MODE                          = 2064 ' // 0x810
$$WIA_DPC_POWER_MODE_STR                     = "Power Mode"$$

%WIA_DPC_BATTERY_STATUS                      = 2065 ' // 0x811
$$WIA_DPC_BATTERY_STATUS_STR                 = "Battery Status"$$

%WIA_DPC_THUMB_WIDTH                         = 2066 ' // 0x812
$$WIA_DPC_THUMB_WIDTH_STR                    = "Thumbnail Width"$$

%WIA_DPC_THUMB_HEIGHT                        = 2067 ' // 0x813
$$WIA_DPC_THUMB_HEIGHT_STR                   = "Thumbnail Height"$$

%WIA_DPC_PICT_WIDTH                          = 2068 ' // 0x814
$$WIA_DPC_PICT_WIDTH_STR                     = "Picture Width"$$

%WIA_DPC_PICT_HEIGHT                         = 2069 ' // 0x815
$$WIA_DPC_PICT_HEIGHT_STR                    = "Picture Height"$$

%WIA_DPC_DIMENSION                           = 2070 ' // 0x816
$$WIA_DPC_DIMENSION_STR                      = "Dimension"$$

%WIA_DPC_COMPRESSION_SETTING                 = 2071 ' // 0x817
$$WIA_DPC_COMPRESSION_SETTING_STR            = "Compression Setting"$$

%WIA_DPC_FOCUS_METERING                      = 2072 ' // 0x818
$$WIA_DPC_FOCUS_METERING_STR                 = "Focus Metering Mode"$$

%WIA_DPC_TIMELAPSE_INTERVAL                  = 2073 ' // 0x819
'#define WIA_DPC_TIMELAPSE_INTERVAL_STR             L"Timelapse Interval"
$$WIA_DPC_TIMELAPSE_INTERVAL_STR             = "Timelapse Interval"$$

%WIA_DPC_TIMELAPSE_NUMBER                    = 2074 ' // 0x81a
$$WIA_DPC_TIMELAPSE_NUMBER_STR               = "Timelapse Number"$$

%WIA_DPC_BURST_INTERVAL                      = 2075 ' // 0x81b
$$WIA_DPC_BURST_INTERVAL_STR                 = "Burst Interval"$$

%WIA_DPC_BURST_NUMBER                        = 2076 ' // 0x81c
$$WIA_DPC_BURST_NUMBER_STR                   = "Burst Number"$$

%WIA_DPC_EFFECT_MODE                         = 2077 ' // 0x81d
$$WIA_DPC_EFFECT_MODE_STR                    = "Effect Mode"$$

%WIA_DPC_DIGITAL_ZOOM                        = 2078 ' // 0x81e
$$WIA_DPC_DIGITAL_ZOOM_STR                   = "Digital Zoom"$$

%WIA_DPC_SHARPNESS                           = 2079 ' // 0x81f
$$WIA_DPC_SHARPNESS_STR                      = "Sharpness"$$

%WIA_DPC_CONTRAST                            = 2080 ' // 0x820
$$WIA_DPC_CONTRAST_STR                       = "Contrast"$$

%WIA_DPC_CAPTURE_MODE                        = 2081 ' // 0x821
$$WIA_DPC_CAPTURE_MODE_STR                   = "Capture Mode"$$

%WIA_DPC_CAPTURE_DELAY                       = 2082 ' // 0x822
$$WIA_DPC_CAPTURE_DELAY_STR                  = "Capture Delay"$$

%WIA_DPC_EXPOSURE_INDEX                      = 2083 ' // 0x823
$$WIA_DPC_EXPOSURE_INDEX_STR                 = "Exposure Index"$$

%WIA_DPC_EXPOSURE_METERING_MODE              = 2084 ' // 0x824
$$WIA_DPC_EXPOSURE_METERING_MODE_STR         = "Exposure Metering Mode"$$

%WIA_DPC_FOCUS_METERING_MODE                 = 2085 ' // 0x825
$$WIA_DPC_FOCUS_METERING_MODE_STR            = "Focus Metering Mode"$$

%WIA_DPC_FOCUS_DISTANCE                      = 2086 ' // 0x826
$$WIA_DPC_FOCUS_DISTANCE_STR                 = "Focus Distance"$$

%WIA_DPC_FOCAL_LENGTH                        = 2087 ' // 0x827
$$WIA_DPC_FOCAL_LENGTH_STR                   = "Focus Length"$$

%WIA_DPC_RGB_GAIN                            = 2088 ' // 0x828
$$WIA_DPC_RGB_GAIN_STR                       = "RGB Gain"$$

%WIA_DPC_WHITE_BALANCE                       = 2089 ' // 0x829
$$WIA_DPC_WHITE_BALANCE_STR                  = "White Balance"$$

%WIA_DPC_UPLOAD_URL                          = 2090 ' // 0x82a
$$WIA_DPC_UPLOAD_URL_STR                     = "Upload URL"$$

%WIA_DPC_ARTIST                              = 2091 ' // 0x82b
$$WIA_DPC_ARTIST_STR                         = "Artist"$$

%WIA_DPC_COPYRIGHT_INFO                      = 2092 ' // 0x82c
$$WIA_DPC_COPYRIGHT_INFO_STR                 = "Copyright Info"$$

%WIA_DPS_HORIZONTAL_BED_SIZE                 = 3074 ' // 0xc02
$$WIA_DPS_HORIZONTAL_BED_SIZE_STR            = "Horizontal Bed Size"$$

%WIA_DPS_VERTICAL_BED_SIZE                   = 3075 ' // 0xc03
$$WIA_DPS_VERTICAL_BED_SIZE_STR              = "Vertical Bed Size"$$

%WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE          = 3076 ' // 0xc04
$$WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE_STR     = "Horizontal Sheet Feed Size"$$

%WIA_DPS_VERTICAL_SHEET_FEED_SIZE            = 3077 ' // 0xc05
$$WIA_DPS_VERTICAL_SHEET_FEED_SIZE_STR       = "Vertical Sheet Feed Size"$$

%WIA_DPS_SHEET_FEEDER_REGISTRATION           = 3078 ' // 0xc06
$$WIA_DPS_SHEET_FEEDER_REGISTRATION_STR      = "Sheet Feeder Registration"$$

%WIA_DPS_HORIZONTAL_BED_REGISTRATION         = 3079 ' // 0xc07
$$WIA_DPS_HORIZONTAL_BED_REGISTRATION_STR    = "Horizontal Bed Registration"$$

%WIA_DPS_VERTICAL_BED_REGISTRATION           = 3080 ' // 0xc08
$$WIA_DPS_VERTICAL_BED_REGISTRATION_STR      = "Vertical Bed Registration"$$

%WIA_DPS_PLATEN_COLOR                        = 3081 ' // 0xc09
$$WIA_DPS_PLATEN_COLOR_STR                   = "Platen Color"$$

%WIA_DPS_PAD_COLOR                           = 3082 ' // 0xc0a
$$WIA_DPS_PAD_COLOR_STR                      = "Pad Color"$$

%WIA_DPS_FILTER_SELECT                       = 3083 ' // 0xc0b
$$WIA_DPS_FILTER_SELECT_STR                  = "Filter Select"$$

%WIA_DPS_DITHER_SELECT                       = 3084 ' // 0xc0c
$$WIA_DPS_DITHER_SELECT_STR                  = "Dither Select"$$

%WIA_DPS_DITHER_PATTERN_DATA                 = 3085 ' // 0xc0d
$$WIA_DPS_DITHER_PATTERN_DATA_STR            = "Dither Pattern Data"$$

%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES      = 3086 ' // 0xc0e
$$WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_STR = "Document Handling Capabilities"$$

%WIA_DPS_DOCUMENT_HANDLING_STATUS            = 3087 ' // 0xc0f
$$WIA_DPS_DOCUMENT_HANDLING_STATUS_STR       = "Document Handling Status"$$

%WIA_DPS_DOCUMENT_HANDLING_SELECT            = 3088 ' // 0xc10
$$WIA_DPS_DOCUMENT_HANDLING_SELECT_STR       = "Document Handling Select"$$

%WIA_DPS_DOCUMENT_HANDLING_CAPACITY          = 3089 ' // 0xc11
$$WIA_DPS_DOCUMENT_HANDLING_CAPACITY_STR     = "Document Handling Capacity"$$

%WIA_DPS_OPTICAL_XRES                        = 3090 ' // 0xc12
$$WIA_DPS_OPTICAL_XRES_STR                   = "Horizontal Optical Resolution"$$

%WIA_DPS_OPTICAL_YRES                        = 3091 ' // 0xc13
$$WIA_DPS_OPTICAL_YRES_STR                   = "Vertical Optical Resolution"$$

%WIA_DPS_ENDORSER_CHARACTERS                 = 3092 ' // 0xc14
$$WIA_DPS_ENDORSER_CHARACTERS_STR            = "Endorser Characters"$$

%WIA_DPS_ENDORSER_STRING                     = 3093 ' // 0xc15
$$WIA_DPS_ENDORSER_STRING_STR                = "Endorser String"$$

%WIA_DPS_SCAN_AHEAD_PAGES                    = 3094 ' // 0xc16
$$WIA_DPS_SCAN_AHEAD_PAGES_STR               = "Scan Ahead Pages"$$

%WIA_DPS_MAX_SCAN_TIME                       = 3095 ' // 0xc17
$$WIA_DPS_MAX_SCAN_TIME_STR                  = "Max Scan Time"$$

%WIA_DPS_PAGES                               = 3096 ' // 0xc18
$$WIA_DPS_PAGES_STR                          = "Pages"$$

%WIA_DPS_PAGE_SIZE                           = 3097 ' // 0xc19
$$WIA_DPS_PAGE_SIZE_STR                      = "Page Size"$$

%WIA_DPS_PAGE_WIDTH                          = 3098 ' // 0xc1a
$$WIA_DPS_PAGE_WIDTH_STR                     = "Page Width"$$

%WIA_DPS_PAGE_HEIGHT                         = 3099 ' // 0xc1b
$$WIA_DPS_PAGE_HEIGHT_STR                    = "Page Height"$$

%WIA_DPS_PREVIEW                             = 3100 ' // 0xc1c
$$WIA_DPS_PREVIEW_STR                        = "Preview"$$

%WIA_DPS_TRANSPARENCY                        = 3101 ' // 0xc1d
$$WIA_DPS_TRANSPARENCY_STR                   = "Transparency Adapter"$$

%WIA_DPS_TRANSPARENCY_SELECT                 = 3102 ' // 0xc1e
$$WIA_DPS_TRANSPARENCY_SELECT_STR            = "Transparency Adapter Select"$$

%WIA_DPS_SHOW_PREVIEW_CONTROL                = 3103 ' // 0xc1f
$$WIA_DPS_SHOW_PREVIEW_CONTROL_STR           = "Show preview control"$$

%WIA_DPS_MIN_HORIZONTAL_SHEET_FEED_SIZE      = 3104 ' // 0xc20
$$WIA_DPS_MIN_HORIZONTAL_SHEET_FEED_SIZE_STR = "Minimum Horizontal Sheet Feed Size"$$

%WIA_DPS_MIN_VERTICAL_SHEET_FEED_SIZE        = 3105 ' // 0xc21
$$WIA_DPS_MIN_VERTICAL_SHEET_FEED_SIZE_STR   = "Minimum Vertical Sheet Feed Size"$$

%WIA_DPS_TRANSPARENCY_CAPABILITIES           = 3106 ' // 0xc22
$$WIA_DPS_TRANSPARENCY_CAPABILITIES_STR      = "Transparency Adapter Capabilities"$$

%WIA_DPS_TRANSPARENCY_STATUS                 = 3107 ' // 0xc23
$$WIA_DPS_TRANSPARENCY_STATUS_STR            = "Transparency Adapter Status"$$

%WIA_DPF_MOUNT_POINT                         = 3330 ' // 0xd02
$$WIA_DPF_MOUNT_POINT_STR                    = "Directory mount point"$$

%WIA_DPV_LAST_PICTURE_TAKEN                  = 3586 ' // 0xe02
$$WIA_DPV_LAST_PICTURE_TAKEN_STR             = "Last Picture Taken"$$

%WIA_DPV_IMAGES_DIRECTORY                    = 3587 ' // 0xe03
$$WIA_DPV_IMAGES_DIRECTORY_STR               = "Images Directory"$$

%WIA_DPV_DSHOW_DEVICE_PATH                   = 3588 ' // 0xe04
$$WIA_DPV_DSHOW_DEVICE_PATH_STR              = "Directshow Device Path"$$

%WIA_IPA_ITEM_NAME                           = 4098 ' // 0x1002
$$WIA_IPA_ITEM_NAME_STR                      = "Item Name"$$

%WIA_IPA_FULL_ITEM_NAME                      = 4099 ' // 0x1003
$$WIA_IPA_FULL_ITEM_NAME_STR                 = "Full Item Name"$$

%WIA_IPA_ITEM_TIME                           = 4100 ' // 0x1004
$$WIA_IPA_ITEM_TIME_STR                      = "Item Time Stamp"$$

%WIA_IPA_ITEM_FLAGS                          = 4101 ' // 0x1005
$$WIA_IPA_ITEM_FLAGS_STR                     = "Item Flags"$$

%WIA_IPA_ACCESS_RIGHTS                       = 4102 ' // 0x1006
$$WIA_IPA_ACCESS_RIGHTS_STR                  = "Access Rights"$$

%WIA_IPA_DATATYPE                            = 4103 ' // 0x1007
$$WIA_IPA_DATATYPE_STR                       = "Data Type"$$

%WIA_IPA_DEPTH                               = 4104 ' // 0x1008
$$WIA_IPA_DEPTH_STR                          = "Bits Per Pixel"$$

%WIA_IPA_PREFERRED_FORMAT                    = 4105 ' // 0x1009
$$WIA_IPA_PREFERRED_FORMAT_STR               = "Preferred Format"$$

%WIA_IPA_FORMAT                              = 4106 ' // 0x100a
$$WIA_IPA_FORMAT_STR                         = "Format"$$

%WIA_IPA_COMPRESSION                         = 4107 ' // 0x100b
$$WIA_IPA_COMPRESSION_STR                    = "Compression"$$

%WIA_IPA_TYMED                               = 4108 ' // 0x100c
$$WIA_IPA_TYMED_STR                          = "Media Type"$$

%WIA_IPA_CHANNELS_PER_PIXEL                  = 4109 ' // 0x100d
$$WIA_IPA_CHANNELS_PER_PIXEL_STR             = "Channels Per Pixel"$$

%WIA_IPA_BITS_PER_CHANNEL                    = 4110 ' // 0x100e
$$WIA_IPA_BITS_PER_CHANNEL_STR               = "Bits Per Channel"$$

%WIA_IPA_PLANAR                              = 4111 ' // 0x100f
$$WIA_IPA_PLANAR_STR                         = "Planar"$$

%WIA_IPA_PIXELS_PER_LINE                     = 4112 ' // 0x1010
$$WIA_IPA_PIXELS_PER_LINE_STR                = "Pixels Per Line"$$

%WIA_IPA_BYTES_PER_LINE                      = 4113 ' // 0x1011
$$WIA_IPA_BYTES_PER_LINE_STR                 = "Bytes Per Line"$$

%WIA_IPA_NUMBER_OF_LINES                     = 4114 ' // 0x1012
$$WIA_IPA_NUMBER_OF_LINES_STR                = "Number of Lines"$$

%WIA_IPA_GAMMA_CURVES                        = 4115 ' // 0x1013
$$WIA_IPA_GAMMA_CURVES_STR                   = "Gamma Curves"$$

%WIA_IPA_ITEM_SIZE                           = 4116 ' // 0x1014
$$WIA_IPA_ITEM_SIZE_STR                      = "Item Size"$$

%WIA_IPA_COLOR_PROFILE                       = 4117 ' // 0x1015
$$WIA_IPA_COLOR_PROFILE_STR                  = "Color Profiles"$$

%WIA_IPA_MIN_BUFFER_SIZE                     = 4118 ' // 0x1016
$$WIA_IPA_MIN_BUFFER_SIZE_STR                = "Buffer Size"$$

%WIA_IPA_BUFFER_SIZE                         = 4118 ' // 0x1016
$$WIA_IPA_BUFFER_SIZE_STR                    = "Buffer Size"$$

%WIA_IPA_REGION_TYPE                         = 4119 ' // 0x1017
$$WIA_IPA_REGION_TYPE_STR                    = "Region Type"$$

%WIA_IPA_ICM_PROFILE_NAME                    = 4120 ' // 0x1018
$$WIA_IPA_ICM_PROFILE_NAME_STR               = "Color Profile Name"$$

%WIA_IPA_APP_COLOR_MAPPING                   = 4121 ' // 0x1019
$$WIA_IPA_APP_COLOR_MAPPING_STR              = "Application Applies Color Mapping"$$

%WIA_IPA_PROP_STREAM_COMPAT_ID               = 4122 ' // 0x101a
$$WIA_IPA_PROP_STREAM_COMPAT_ID_STR          = "Stream Compatibility ID"$$

%WIA_IPA_FILENAME_EXTENSION                  = 4123 ' // 0x101b
$$WIA_IPA_FILENAME_EXTENSION_STR             = "Filename extension"$$

%WIA_IPA_SUPPRESS_PROPERTY_PAGE              = 4124 ' // 0x101c
$$WIA_IPA_SUPPRESS_PROPERTY_PAGE_STR         = "Suppress a property page"$$

%WIA_IPC_THUMBNAIL                           = 5122 ' // 0x1402
$$WIA_IPC_THUMBNAIL_STR                      = "Thumbnail Data"$$

%WIA_IPC_THUMB_WIDTH                         = 5123 ' // 0x1403
$$WIA_IPC_THUMB_WIDTH_STR                    = "Thumbnail Width"$$

%WIA_IPC_THUMB_HEIGHT                        = 5124 ' // 0x1404
$$WIA_IPC_THUMB_HEIGHT_STR                   = "Thumbnail Height"$$

%WIA_IPC_AUDIO_AVAILABLE                     = 5125 ' // 0x1405
$$WIA_IPC_AUDIO_AVAILABLE_STR                = "Audio Available"$$

%WIA_IPC_AUDIO_DATA_FORMAT                   = 5126 ' // 0x1406
$$WIA_IPC_AUDIO_DATA_FORMAT_STR              = "Audio Format"$$

%WIA_IPC_AUDIO_DATA                          = 5127 ' // 0x1407
$$WIA_IPC_AUDIO_DATA_STR                     = "Audio Data"$$

%WIA_IPC_NUM_PICT_PER_ROW                    = 5128 ' // 0x1408
$$WIA_IPC_NUM_PICT_PER_ROW_STR               = "Pictures per Row"$$

%WIA_IPC_SEQUENCE                            = 5129 ' // 0x1409
$$WIA_IPC_SEQUENCE_STR                       = "Sequence Number"$$

%WIA_IPC_TIMEDELAY                           = 5130 ' // 0x140a
$$WIA_IPC_TIMEDELAY_STR                      = "Time Delay"$$

%WIA_IPS_CUR_INTENT                          = 6146 ' // 0x1802
$$WIA_IPS_CUR_INTENT_STR                     = "Current Intent"$$

%WIA_IPS_XRES                                = 6147 ' // 0x1803
$$WIA_IPS_XRES_STR                           = "Horizontal Resolution"$$

%WIA_IPS_YRES                                = 6148 ' // 0x1804
$$WIA_IPS_YRES_STR                           = "Vertical Resolution"$$

%WIA_IPS_XPOS                                = 6149 ' // 0x1805
$$WIA_IPS_XPOS_STR                           = "Horizontal Start Position"$$

%WIA_IPS_YPOS                                = 6150 ' // 0x1806
$$WIA_IPS_YPOS_STR                           = "Vertical Start Position"$$

%WIA_IPS_XEXTENT                             = 6151 ' // 0x1807
$$WIA_IPS_XEXTENT_STR                        = "Horizontal Extent"$$

%WIA_IPS_YEXTENT                             = 6152 ' // 0x1808
$$WIA_IPS_YEXTENT_STR                        = "Vertical Extent"$$

%WIA_IPS_PHOTOMETRIC_INTERP                  = 6153 ' // 0x1809
$$WIA_IPS_PHOTOMETRIC_INTERP_STR             = "Photometric Interpretation"$$

%WIA_IPS_BRIGHTNESS                          = 6154 ' // 0x180a
$$WIA_IPS_BRIGHTNESS_STR                     = "Brightness"$$

%WIA_IPS_CONTRAST                            = 6155 ' // 0x180b
$$WIA_IPS_CONTRAST_STR                       = "Contrast"$$

%WIA_IPS_ORIENTATION                         = 6156 ' // 0x180c
$$WIA_IPS_ORIENTATION_STR                    = "Orientation"$$

%WIA_IPS_ROTATION                            = 6157 ' // 0x180d
$$WIA_IPS_ROTATION_STR                       = "Rotation"$$

%WIA_IPS_MIRROR                              = 6158 ' // 0x180e
$$WIA_IPS_MIRROR_STR                         = "Mirror"$$

%WIA_IPS_THRESHOLD                           = 6159 ' // 0x180f
$$WIA_IPS_THRESHOLD_STR                      = "Threshold"$$

%WIA_IPS_INVERT                              = 6160 ' // 0x1810
$$WIA_IPS_INVERT_STR                         = "Invert"$$

%WIA_IPS_WARM_UP_TIME                        = 6161 ' // 0x1811
$$WIA_IPS_WARM_UP_TIME_STR                   = "Lamp Warm up Time"$$

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

' //
' // New properties, property names and values introduced in Windows Vista:
' //

%WIA_DPS_USER_NAME                           = 3112 ' // 0xc28
$$WIA_DPS_USER_NAME_STR                      = "User Name"$$

%WIA_DPS_SERVICE_ID                          = 3113 ' // 0xc29
$$WIA_DPS_SERVICE_ID_STR                     = "Service ID"$$

%WIA_DPS_DEVICE_ID                           = 3114 ' // 0xc2a
$$WIA_DPS_DEVICE_ID_STR                      = "Device ID"$$

%WIA_DPS_GLOBAL_IDENTITY                     = 3115 ' // 0xc2b
$$WIA_DPS_GLOBAL_IDENTITY_STR                = "Global Identity"$$

%WIA_DPS_SCAN_AVAILABLE_ITEM                 = 3116 ' // 0xc2c
$$WIA_DPS_SCAN_AVAILABLE_ITEM_STR            = "Scan Available Item"$$

%WIA_IPS_DESKEW_X                            = 6162 ' // 0x1812
$$WIA_IPS_DESKEW_X_STR                       = "DeskewX"$$

%WIA_IPS_DESKEW_Y                            = 6163 ' // 0x1813
$$WIA_IPS_DESKEW_Y_STR                       = "DeskewY"$$

%WIA_IPS_SEGMENTATION                        = 6164 ' // 0x1814
$$WIA_IPS_SEGMENTATION_STR                   = "Segmentation"$$

$$WIA_SEGMENTATION_FILTER_STR                = "SegmentationFilter"$$
$$WIA_IMAGEPROC_FILTER_STR                   = "ImageProcessingFilter"$$

%WIA_IPS_MAX_HORIZONTAL_SIZE                 = 6165 ' // 0x1815
$$WIA_IPS_MAX_HORIZONTAL_SIZE_STR            = "Maximum Horizontal Scan Size"$$

%WIA_IPS_MAX_VERTICAL_SIZE                   = 6166 ' // 0x1816
$$WIA_IPS_MAX_VERTICAL_SIZE_STR              = "Maximum Vertical Scan Size"$$

%WIA_IPS_MIN_HORIZONTAL_SIZE                 = 6167 ' // 0x1817
$$WIA_IPS_MIN_HORIZONTAL_SIZE_STR            = "Minimum Horizontal Scan Size"$$

%WIA_IPS_MIN_VERTICAL_SIZE                   = 6168 ' // 0x1818
$$WIA_IPS_MIN_VERTICAL_SIZE_STR              = "Minimum Vertical Scan Size"$$

%WIA_IPS_TRANSFER_CAPABILITIES               = 6169 ' // 0x1819
$$WIA_IPS_TRANSFER_CAPABILITIES_STR          = "Transfer Capabilities"$$

%WIA_IPS_SHEET_FEEDER_REGISTRATION           = 3078 ' // 0xc06
$$WIA_IPS_SHEET_FEEDER_REGISTRATION_STR      = "Sheet Feeder Registration"$$

%WIA_IPS_DOCUMENT_HANDLING_SELECT            = 3088 ' // 0xc10
$$WIA_IPS_DOCUMENT_HANDLING_SELECT_STR       = "Document Handling Select"$$

%WIA_IPS_OPTICAL_XRES                        = 3090 ' // 0xc12
$$WIA_IPS_OPTICAL_XRES_STR                   = "Horizontal Optical Resolution"$$

%WIA_IPS_OPTICAL_YRES                        = 3091 ' // 0xc13
$$WIA_IPS_OPTICAL_YRES_STR                   = "Vertical Optical Resolution"$$

%WIA_IPS_PAGES                               = 3096 ' // 0xc18
$$WIA_IPS_PAGES_STR                          = "Pages"$$

%WIA_IPS_PAGE_SIZE                           = 3097 ' // 0xc19
$$WIA_IPS_PAGE_SIZE_STR                      = "Page Size"$$

%WIA_IPS_PAGE_WIDTH                          = 3098 ' // 0xc1a
$$WIA_IPS_PAGE_WIDTH_STR                     = "Page Width"$$

%WIA_IPS_PAGE_HEIGHT                         = 3099 ' // 0xc1b
$$WIA_IPS_PAGE_HEIGHT_STR                    = "Page Height"$$

%WIA_IPS_PREVIEW                             = 3100 ' // 0xc1c
$$WIA_IPS_PREVIEW_STR                        = "Preview"$$

%WIA_IPS_SHOW_PREVIEW_CONTROL                = 3103 ' // 0xc1f
$$WIA_IPS_SHOW_PREVIEW_CONTROL_STR           = "Show preview control"$$

%WIA_IPS_FILM_SCAN_MODE                      = 3104 ' // 0xc20
$$WIA_IPS_FILM_SCAN_MODE_STR                 = "Film Scan Mode"$$

%WIA_IPS_LAMP                                = 3105 ' // 0xc21
$$WIA_IPS_LAMP_STR                           = "Lamp"$$

%WIA_IPS_LAMP_AUTO_OFF                       = 3106 ' // 0xc22
$$WIA_IPS_LAMP_AUTO_OFF_STR                  = "Lamp Auto Off"$$

%WIA_IPS_AUTO_DESKEW                         = 3107 ' // 0xc23
$$WIA_IPS_AUTO_DESKEW_STR                    = "Automatic Deskew"$$

%WIA_IPS_SUPPORTS_CHILD_ITEM_CREATION        = 3108 ' // 0xc24
$$WIA_IPS_SUPPORTS_CHILD_ITEM_CREATION_STR   = "Supports Child Item Creation"$$

%WIA_IPS_XSCALING                            = 3109 ' // 0xc25
$$WIA_IPS_XSCALING_STR                       = "Horizontal Scaling"$$

%WIA_IPS_YSCALING                            = 3110 ' // 0xc26
$$WIA_IPS_YSCALING_STR                       = "Vertical Scaling"$$

%WIA_IPS_PREVIEW_TYPE                        = 3111 ' // 0xc27
$$WIA_IPS_PREVIEW_TYPE_STR                   = "Preview Type"$$

%WIA_IPA_ITEM_CATEGORY                       = 4125 ' // 0x101d
$$WIA_IPA_ITEM_CATEGORY_STR                  = "Item Category"$$

%WIA_IPA_UPLOAD_ITEM_SIZE                    = 4126 ' // 0x101e
$$WIA_IPA_UPLOAD_ITEM_SIZE_STR               = "Upload Item Size"$$

%WIA_IPA_ITEMS_STORED                        = 4127 ' // 0x101f
$$WIA_IPA_ITEMS_STORED_STR                   = "Items Stored"$$

%WIA_IPA_RAW_BITS_PER_CHANNEL                = 4128 ' // 0x1020
$$WIA_IPA_RAW_BITS_PER_CHANNEL_STR           = "Raw Bits Per Channel"$$

%WIA_IPS_FILM_NODE_NAME                      = 4129 ' // 0x1021
$$WIA_IPS_FILM_NODE_NAME_STR                 = "Film Node Name"$$

'//
'// WIA_IPA_ITEM_CATEGORY constants
'//
$WIA_CATEGORY_FINISHED_FILE = GUID$("{ff2b77ca-cf84-432b-a735-3a130dde2a88}")
$WIA_CATEGORY_FLATBED       = GUID$("{fb607b1f-43f3-488b-855b-fb703ec342a6}")
$WIA_CATEGORY_FEEDER        = GUID$("{fe131934-f84c-42ad-8da4-6129cddd7288}")
$WIA_CATEGORY_FILM          = GUID$("{fcf65be7-3ce3-4473-af85-f5d37d21b68a}")
$WIA_CATEGORY_ROOT          = GUID$("{f193526f-59b8-4a26-9888-e16e4f97ce10}")
$WIA_CATEGORY_FOLDER        = GUID$("{c692a446-6f5a-481d-85bb-92e2e86fd30a}")
$WIA_CATEGORY_FEEDER_FRONT  = GUID$("{4823175c-3b28-487b-a7e6-eebc17614fd1}")
$WIA_CATEGORY_FEEDER_BACK   = GUID$("{61ca74d4-39db-42aa-89b1-8c19c9cd4c23}")
$WIA_CATEGORY_AUTO          = GUID$("{defe5fd8-6c97-4dde-b11e-cb509b270e11}")

'//
'// GUID for Default Segmentation Filter
'//
$CLSID_WiaDefaultSegFilter  = GUID$("{D4F4D30B-0B29-4508-8922-0C5797D42765}")

'//
'// WIA_IPS_TRANSFER_CAPABILITIES flags:
'//
%WIA_TRANSFER_CHILDREN_SINGLE_SCAN = &H00000001???

'//
'// WIA_IPS_SEGMENTATION_FILTER constants
'//
%WIA_USE_SEGMENTATION_FILTER      = 0
%WIA_DONT_USE_SEGMENTATION_FILTER = 1

'//
'// WIA_IPS_FILM_SCAN_MODE constants
'//
%WIA_FILM_COLOR_SLIDE             = 0
%WIA_FILM_COLOR_NEGATIVE          = 1
%WIA_FILM_BW_NEGATIVE             = 2

'//
'// WIA_IPS_LAMP constants
'//
%WIA_LAMP_ON                      = 0
%WIA_LAMP_OFF                     = 1

'//
'// WIA_IPS_AUTO_DESKEW constants:
'//
%WIA_AUTO_DESKEW_ON               = 0
%WIA_AUTO_DESKEW_OFF              = 1

'//
'// WIA_IPS_PREVIEW_TYPE constants:
'//
%WIA_ADVANCED_PREVIEW             = 0
%WIA_BASIC_PREVIEW                = 1

'//
'// WIA Raw Format header:
'//
' // Size = 80 bytes
TYPE WIA_RAW_HEADER DWORD
   Tag               AS DWORD
   Version           AS DWORD
   HeaderSize        AS DWORD
   XRes              AS DWORD
   YRes              AS DWORD
   XExtent           AS DWORD
   YExtent           AS DWORD
   BytesPerLine      AS DWORD
   BitsPerPixel      AS DWORD
   ChannelsPerPixel  AS DWORD
   DataType          AS DWORD
   BitsPerChannel(7) AS BYTE
   Compression       AS DWORD
   PhotometricInterp AS DWORD
   LineOrder         AS DWORD
   RawDataOffset     AS DWORD
   RawDataSize       AS DWORD
   PaletteOffset     AS DWORD
   PaletteSize       AS DWORD
END TYPE

#ENDIF ' //#if (_WIN32_WINNT >= 0x0600)

'//
'// Use the WIA property offsets to define private WIA properties.
'//
'// Example: (Creating a private WIA property)
'//
'// #define WIA_THE_PROP         (WIA_PRIVATE_DEVPROP + 1000)
'// #define WIA_THE_PROP_STR     L"The Property")
'//

'//
'// Private property offset constants
'//

%WIA_PRIVATE_DEVPROP  = 38914  ' // offset for private device (root) item properties
%WIA_PRIVATE_ITEMPROP = 71682  ' // offset for private item properties

'//
'// WIA image format constants
'//

$WiaImgFmt_UNDEFINED = GUID$("{b96b3ca9-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_RAWRGB    = GUID$("{bca48b55-f272-4371-b0f1-4a150d057bb4}")
$WiaImgFmt_MEMORYBMP = GUID$("{b96b3caa-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_BMP       = GUID$("{b96b3cab-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_EMF       = GUID$("{b96b3cac-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_WMF       = GUID$("{b96b3cad-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_JPEG      = GUID$("{b96b3cae-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_PNG       = GUID$("{b96b3caf-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_GIF       = GUID$("{b96b3cb0-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_TIFF      = GUID$("{b96b3cb1-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_EXIF      = GUID$("{b96b3cb2-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_PHOTOCD   = GUID$("{b96b3cb3-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_FLASHPIX  = GUID$("{b96b3cb4-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_ICO       = GUID$("{b96b3cb5-0728-11d3-9d7b-0000f81ef32e}")
$WiaImgFmt_CIFF      = GUID$("{9821a8ab-3a7e-4215-94e0-d27a460c03b2}")
$WiaImgFmt_PICT      = GUID$("{a6bc85d8-6b3e-40ee-a95c-25d482e41adc}")
$WiaImgFmt_JPEG2K    = GUID$("{344ee2b2-39db-4dde-8173-c4b75f8f1e49}")
$WiaImgFmt_JPEG2KX   = GUID$("{43e14614-c80a-4850-baf3-4b152dc8da27}")
'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
$WiaImgFmt_RAW       = GUID$("{6f120719-f1a8-4e07-9ade-9b64c63a3dcc}")
$WiaImgFmt_JBIG      = GUID$("{41e8dd92-2f0a-43d4-8636-f1614ba11e46}")
#ENDIF ' //#if (_WIN32_WINNT >= 0x0600)

'//
'// WIA document format constants
'//

$WiaImgFmt_RTF       = GUID$("{573dd6a3-4834-432d-a9b5-e198dd9e890d}")
$WiaImgFmt_XML       = GUID$("{b9171457-dac8-4884-b393-15b471d5f07e}")
$WiaImgFmt_HTML      = GUID$("{c99a4e62-99de-4a94-acca-71956ac2977d}")
$WiaImgFmt_TXT       = GUID$("{fafd4d82-723f-421f-9318-30501ac44b59}")
'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
$WiaImgFmt_PDFA      = GUID$("{9980bd5b-3463-43c7-bdca-3caa146f229f}")
$WiaImgFmt_XPS       = GUID$("{700b4a0f-2011-411c-b430-d1e0b2e10b28}")
#ENDIF ' //#if (_WIN32_WINNT >= 0x0600)

'//
'// WIA video format constants
'//

$WiaImgFmt_MPG       = GUID$("{ecd757e4-d2ec-4f57-955d-bcf8a97c4e52}")
$WiaImgFmt_AVI       = GUID$("{32f8ca14-087c-4908-b7c4-6757fe7e90ab}")

'//
'// WIA audio format constants
'//

$WiaAudFmt_WAV       = GUID$("{f818e146-07af-40ff-ae55-be8f2c065dbe}")
$WiaAudFmt_MP3       = GUID$("{0fbc71fb-43bf-49f2-9190-e6fecff37e54}")
$WiaAudFmt_AIFF      = GUID$("{66e2bf4f-b6fc-443f-94c8-2f33c8a65aaf}")
$WiaAudFmt_WMA       = GUID$("{d61d6413-8bc2-438f-93ad-21bd484db6a1}")

'//
'// WIA misc format constants
'//

$WiaImgFmt_ASF       = GUID$("{8d948ee9-d0aa-4a12-9d9a-9cc5de36199b}")
$WiaImgFmt_SCRIPT    = GUID$("{fe7d6c53-2dac-446a-b0bd-d73e21e924c9}")
$WiaImgFmt_EXEC      = GUID$("{485da097-141e-4aa5-bb3b-a5618d95d02b}")
$WiaImgFmt_UNICODE16 = GUID$("{1b7639b6-6357-47d1-9a07-12452dc073e9}")
$WiaImgFmt_DPOF      = GUID$("{369eeeab-a0e8-45ca-86a6-a83ce5697e28}")

'//
'// WIA event constants
'//

$WIA_EVENT_DEVICE_DISCONNECTED = GUID$("{143e4e83-6497-11d2-a231-00c04fa31809}")
$WIA_EVENT_DEVICE_CONNECTED    = GUID$("{a28bbade-64b6-11d2-a231-00c04fa31809}")
$WIA_EVENT_ITEM_DELETED        = GUID$("{1d22a559-e14f-11d2-b326-00c04f68ce61}")
$WIA_EVENT_ITEM_CREATED        = GUID$("{4c8f4ef5-e14f-11d2-b326-00c04f68ce61}")
$WIA_EVENT_TREE_UPDATED        = GUID$("{c9859b91-4ab2-4cd6-a1fc-582eec55e585}")
$WIA_EVENT_VOLUME_INSERT       = GUID$("{9638bbfd-d1bd-11d2-b31f-00c04f68ce61}")
$WIA_EVENT_SCAN_IMAGE          = GUID$("{a6c5a715-8c6e-11d2-977a-0000f87a926f}")
$WIA_EVENT_SCAN_PRINT_IMAGE    = GUID$("{b441f425-8c6e-11d2-977a-0000f87a926f}")
$WIA_EVENT_SCAN_FAX_IMAGE      = GUID$("{c00eb793-8c6e-11d2-977a-0000f87a926f}")
$WIA_EVENT_SCAN_OCR_IMAGE      = GUID$("{9d095b89-37d6-4877-afed-62a297dc6dbe}")
$WIA_EVENT_SCAN_EMAIL_IMAGE    = GUID$("{c686dcee-54f2-419e-9a27-2fc7f2e98f9e}")
$WIA_EVENT_SCAN_FILM_IMAGE     = GUID$("{9b2b662c-6185-438c-b68b-e39ee25e71cb}")
$WIA_EVENT_SCAN_IMAGE2         = GUID$("{fc4767c1-c8b3-48a2-9cfa-2e90cb3d3590}")
$WIA_EVENT_SCAN_IMAGE3         = GUID$("{154e27be-b617-4653-acc5-0fd7bd4c65ce}")
$WIA_EVENT_SCAN_IMAGE4         = GUID$("{a65b704a-7f3c-4447-a75d-8a26dfca1fdf}")
$WIA_EVENT_STORAGE_CREATED     = GUID$("{353308b2-fe73-46c8-895e-fa4551ccc85a}")
$WIA_EVENT_STORAGE_DELETED     = GUID$("{5e41e75e-9390-44c5-9a51-e47019e390cf}")
$WIA_EVENT_STI_PROXY           = GUID$("{d711f81f-1f0d-422d-8641-927d1b93e5e5}")
$WIA_EVENT_CANCEL_IO           = GUID$("{c860f7b8-9ccd-41ea-bbbf-4dd09c5b1795}")

'//
'// Power management event GUIDs, sent by the WIA service to drivers
'//

$WIA_EVENT_POWER_SUSPEND       = GUID$("{a0922ff9-c3b4-411c-9e29-03a66993d2be}")
$WIA_EVENT_POWER_RESUME        = GUID$("{618f153e-f686-4350-9634-4115a304830c}")

'//
'// No action handler and prompt handler
'//

$WIA_EVENT_HANDLER_NO_ACTION   = GUID$("{e0372b7d-e115-4525-bc55-b629e68c745a}")
$WIA_EVENT_HANDLER_PROMPT      = GUID$("{5f4baad0-4d59-4fcd-b213-783ce7a92f22}")

'//
'// WIA command constants
'//

$WIA_CMD_SYNCHRONIZE           = GUID$("{9b26b7b2-acad-11d2-a093-00c04f72dc3c}")
$WIA_CMD_TAKE_PICTURE          = GUID$("{af933cac-acad-11d2-a093-00c04f72dc3c}")
$WIA_CMD_DELETE_ALL_ITEMS      = GUID$("{e208c170-acad-11d2-a093-00c04f72dc3c}")
$WIA_CMD_CHANGE_DOCUMENT       = GUID$("{04e725b0-acae-11d2-a093-00c04f72dc3c}")
$WIA_CMD_UNLOAD_DOCUMENT       = GUID$("{1f3b3d8e-acae-11d2-a093-00c04f72dc3c}")
$WIA_CMD_DIAGNOSTIC            = GUID$("{10ff52f5-de04-4cf0-a5ad-691f8dce0141}")
$WIA_CMD_FORMAT                = GUID$("{c3a693aa-f788-4d34-a5b0-be7190759a24}")

'//
'// WIA command constants used for debugging only
'//

$WIA_CMD_DELETE_DEVICE_TREE    = GUID$("{73815942-dbea-11d2-8416-00c04fa36145}")
$WIA_CMD_BUILD_DEVICE_TREE     = GUID$("{9cba5ce0-dbea-11d2-8416-00c04fa36145}")

'/**************************************************************************
'*
'* WIA Errors
'*
'***************************************************************************/

'//
'// Define the facility code. Move this to sdk\inc???
'//

%FACILITY_WIA = 33

'//
'// Definitions for WIA_ERRORs and WIA_STATUSs. Applications can test for these returns
'// on API return, to keep users informed of conditions which a user
'// could correct.
'//

%BASE_VAL_WIA_ERROR   = &H00000000&
%BASE_VAL_WIA_SUCCESS = &H00000000&

'#define WIA_ERROR_GENERAL_ERROR              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 1))
'#define WIA_ERROR_PAPER_JAM                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 2))
'#define WIA_ERROR_PAPER_EMPTY                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 3))
'#define WIA_ERROR_PAPER_PROBLEM              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 4))
'#define WIA_ERROR_OFFLINE                    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 5))
'#define WIA_ERROR_BUSY                       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 6))
'#define WIA_ERROR_WARMING_UP                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 7))
'#define WIA_ERROR_USER_INTERVENTION          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 8))
'#define WIA_ERROR_ITEM_DELETED               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 9))
'#define WIA_ERROR_DEVICE_COMMUNICATION       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 10))
'#define WIA_ERROR_INVALID_COMMAND            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 11))
'#define WIA_ERROR_INCORRECT_HARDWARE_SETTING MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 12))
'#define WIA_ERROR_DEVICE_LOCKED              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 13))
'#define WIA_ERROR_EXCEPTION_IN_DRIVER        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 14))
'#define WIA_ERROR_INVALID_DRIVER_RESPONSE    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 15))
'#define WIA_ERROR_COVER_OPEN                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, 16)
'#define WIA_ERROR_LAMP_OFF                   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, 17)
'#define WIA_ERROR_DESTINATION                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, 18)
'#define WIA_ERROR_NETWORK_RESERVATION_FAILED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, 19)
'#define WIA_STATUS_END_OF_MEDIA              MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 1)

'//
'// Returned by SelectDeviceDlg and SelectDeviceDlgId when there are no devices avaiable
'//
'#define WIA_S_NO_DEVICE_AVAILABLE            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 21))

%WIA_ERROR_GENERAL_ERROR              = &H80210001&
%WIA_ERROR_PAPER_JAM                  = &H80210002&
%WIA_ERROR_PAPER_EMPTY                = &H80210003&
%WIA_ERROR_PAPER_PROBLEM              = &H80210004&
%WIA_ERROR_OFFLINE                    = &H80210005&
%WIA_ERROR_BUSY                       = &H80210006&
%WIA_ERROR_WARMING_UP                 = &H80210007&
%WIA_ERROR_USER_INTERVENTION          = &H80210008&
%WIA_ERROR_ITEM_DELETED               = &H80210009&
%WIA_ERROR_DEVICE_COMMUNICATION       = &H8021000A&
%WIA_ERROR_INVALID_COMMAND            = &H8021000B&
%WIA_ERROR_INCORRECT_HARDWARE_SETTING = &H8021000C&
%WIA_ERROR_DEVICE_LOCKED              = &H8021000D&
%WIA_ERROR_EXCEPTION_IN_DRIVER        = &H8021000E&
%WIA_ERROR_INVALID_DRIVER_RESPONSE    = &H8021000F&
%WIA_ERROR_COVER_OPEN                 = &H80210010&
%WIA_ERROR_LAMP_OFF                   = &H80210011&
%WIA_ERROR_DESTINATION                = &H80210012&
%WIA_ERROR_NETWORK_RESERVATION_FAILED = &H80210013&
%WIA_STATUS_END_OF_MEDIA              = &H00210013&

'//
'// Definitions for errors and status codes passed to IWiaDataTransfer::BandedDataCallback as the lReason parameter.
'// These codes are in addition to the errors defined above; in some cases the SEVERITY_SUCCESS version of
'// an error is meant to replace the SEVERITY_ERROR version listed above.
'//

'#define WIA_STATUS_WARMING_UP                MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 2)
'#define WIA_STATUS_CALIBRATING               MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 3)
'#define WIA_STATUS_RESERVING_NETWORK_DEVICE  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 6)
'#define WIA_STATUS_NETWORK_DEVICE_RESERVED   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 7)
'#define WIA_STATUS_CLEAR                     MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 8)
'#define WIA_STATUS_SKIP_ITEM                 MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 9)
'#define WIA_STATUS_NOT_HANDLED               MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 10)

%WIA_STATUS_WARMING_UP                = &H00210002&
%WIA_STATUS_CALIBRATING               = &H00210003&
%WIA_STATUS_RESERVING_NETWORK_DEVICE  = &H00210006&
%WIA_STATUS_NETWORK_DEVICE_RESERVED   = &H00210007&
%WIA_STATUS_CLEAR                     = &H00210008&
%WIA_STATUS_SKIP_ITEM                 = &H00210009&
%WIA_STATUS_NOT_HANDLED               = &H0021000A&

'//
'// The value is returned by Scansetting.dll when the user chooses to change the scanner in scandialog
'//
'#define WIA_S_CHANGE_DEVICE                  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_WIA, 11)
%WIA_S_CHANGE_DEVICE                  = &H0021000B&

'//
'// SelectDeviceDlg and SelectDeviceDlgID status code when there are no devices available
'//

'#define WIA_S_NO_DEVICE_AVAILABLE            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, 21)
%WIA_S_NO_DEVICE_AVAILABLE            = &H00210015&


'//
'// SelectDeviceDlg & GetImageDlg flags
'//

%WIA_SELECT_DEVICE_NODEFAULT          = &H00000001???

'//
'// GetImageDlg & DeviceDlg flags
'//

%WIA_DEVICE_DIALOG_SINGLE_IMAGE       = &H00000002??? ' // Only allow one image to be selected
%WIA_DEVICE_DIALOG_USE_COMMON_UI      = &H00000004??? ' // Give preference to the system-provided UI, if available

'//
'// RegisterEventCallbackInterface and RegisterEventCallbackCLSID flag constants
'//

%WIA_REGISTER_EVENT_CALLBACK        = &H00000001???
%WIA_UNREGISTER_EVENT_CALLBACK      = &H00000002???
%WIA_SET_DEFAULT_HANDLER            = &H00000004???

'//
'// WIA event type constants
'//

%WIA_NOTIFICATION_EVENT             = &H00000001???
%WIA_ACTION_EVENT                   = &H00000002???

'//
'// Additional WIA raw format constants
'//

%WIA_LINE_ORDER_TOP_TO_BOTTOM       = &H00000001???
%WIA_LINE_ORDER_BOTTOM_TO_TOP       = &H00000002???

'//
'// WIA event persistent handler flag constants
'//

%WIA_IS_DEFAULT_HANDLER             = &H00000001???

'//
'// WIA connected and disconnected event description strings
'//

$$WIA_EVENT_DEVICE_DISCONNECTED_STR = "Device Disconnected"$$
$$WIA_EVENT_DEVICE_CONNECTED_STR    = "Device Connected"$$

'//
'// WIA event and command icon resource identifier constants
'//
'// Events   : -1000 to -1499 (Standard), -1500 to -1999 (Custom)
'// Commands : -2000 to -2499 (Standard), -2500 to -2999 (Custom)
'//

$$WIA_ICON_DEVICE_DISCONNECTED    = "sti.dll,-1001"$$
$$WIA_ICON_DEVICE_CONNECTED       = "sti.dll,-1001"$$
$$WIA_ICON_ITEM_DELETED           = "sti.dll,-1001"$$
$$WIA_ICON_ITEM_CREATED           = "sti.dll,-1001"$$
$$WIA_ICON_VOLUME_INSERT          = "sti.dll,-1001"$$
$$WIA_ICON_SCAN_BUTTON_PRESS      = "sti.dll,-1001"$$
$$WIA_ICON_SYNCHRONIZE            = "sti.dll,-2000"$$
$$WIA_ICON_TAKE_PICTURE           = "sti.dll,-2001"$$
$$WIA_ICON_DELETE_ALL_ITEMS       = "sti.dll,-2002"$$
$$WIA_ICON_CHANGE_DOCUMENT        = "sti.dll,-2003"$$
$$WIA_ICON_UNLOAD_DOCUMENT        = "sti.dll,-2004"$$
$$WIA_ICON_DELETE_DEVICE_TREE     = "sti.dll,-2005"$$
$$WIA_ICON_BUILD_DEVICE_TREE      = "sti.dll,-2006"$$

'//
'// WIA TYMED constants
'//

%TYMED_CALLBACK                    = 128
%TYMED_MULTIPAGE_FILE              = 256
%TYMED_MULTIPAGE_CALLBACK          = 512

'//
'// IWiaDataCallback and IWiaMiniDrvCallBack message ID constants
'//

%IT_MSG_DATA_HEADER                = &H0001
%IT_MSG_DATA                       = &H0002
%IT_MSG_STATUS                     = &H0003
%IT_MSG_TERMINATION                = &H0004
%IT_MSG_NEW_PAGE                   = &H0005
%IT_MSG_FILE_PREVIEW_DATA          = &H0006
%IT_MSG_FILE_PREVIEW_DATA_HEADER   = &H0007

'//
'// IWiaDataCallback and IWiaMiniDrvCallBack status flag constants
'//

%IT_STATUS_TRANSFER_FROM_DEVICE    = &H0001???
%IT_STATUS_PROCESSING_DATA         = &H0002???
%IT_STATUS_TRANSFER_TO_CLIENT      = &H0004???
%IT_STATUS_MASK                    = &H0007???  ' // any status value that doesn't
                                             ' // fit the mask is an HRESULT

'//
'// IWiaTransfer flags
'//

%WIA_TRANSFER_ACQUIRE_CHILDREN     = &H0001???

'//
'// IWiaTransferCallback Message types
'//

%WIA_TRANSFER_MSG_STATUS           = &H00001
%WIA_TRANSFER_MSG_END_OF_STREAM    = &H00002
%WIA_TRANSFER_MSG_END_OF_TRANSFER  = &H00003
%WIA_TRANSFER_MSG_DEVICE_STATUS    = &H00005
%WIA_TRANSFER_MSG_NEW_PAGE         = &H00006

'//
'// IWiaEventCallback code constants
'//

%WIA_MAJOR_EVENT_DEVICE_CONNECT    = &H01
%WIA_MAJOR_EVENT_DEVICE_DISCONNECT = &H02
%WIA_MAJOR_EVENT_PICTURE_TAKEN     = &H03
%WIA_MAJOR_EVENT_PICTURE_DELETED   = &H04

'//
'// WIA device connection status constants
'//

%WIA_DEVICE_NOT_CONNECTED          = 0
%WIA_DEVICE_CONNECTED              = 1


'//
'// EnumDeviceCapabilities and drvGetCapabilities flags
'//

%WIA_DEVICE_COMMANDS               = 1???
%WIA_DEVICE_EVENTS                 = 2???

'//
'// EnumDeviceInfo Flags
'//

%WIA_DEVINFO_ENUM_ALL              = &H0000000F???
%WIA_DEVINFO_ENUM_LOCAL            = &H00000010???


'//
'// WIA item type constants
'//

%WiaItemTypeFree                   = &H00000000???
%WiaItemTypeImage                  = &H00000001???
%WiaItemTypeFile                   = &H00000002???
%WiaItemTypeFolder                 = &H00000004???
%WiaItemTypeRoot                   = &H00000008???
%WiaItemTypeAnalyze                = &H00000010???
%WiaItemTypeAudio                  = &H00000020???
%WiaItemTypeDevice                 = &H00000040???
%WiaItemTypeDeleted                = &H00000080???
%WiaItemTypeDisconnected           = &H00000100???
%WiaItemTypeHPanorama              = &H00000200???
%WiaItemTypeVPanorama              = &H00000400???
%WiaItemTypeBurst                  = &H00000800???
%WiaItemTypeStorage                = &H00001000???
%WiaItemTypeTransfer               = &H00002000???
%WiaItemTypeGenerated              = &H00004000???
%WiaItemTypeHasAttachments         = &H00008000???
%WiaItemTypeVideo                  = &H00010000???
%WiaItemTypeRemoved                = &H80000000???

'//
'// = &H00020000 has been reserved for the TWAIN compatiblity layer
'// pass-through feature.
'//

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%WiaItemTypeDocument               = &H00040000???
%WiaItemTypeProgrammableDataSource = &H00080000???
%WiaItemTypeMask                   = &H800FFFFF???
#ELSE
%WiaItemTypeMask                   = &H8003FFFF???
#ENDIF

'//
'// Big max device specific item context
'//

%WIA_MAX_CTX_SIZE                  = &H01000000???


'//
'// WIA property access flag constants
'//

%WIA_PROP_READ            = &H01???
%WIA_PROP_WRITE           = &H02???
%WIA_PROP_RW              = %WIA_PROP_READ OR %WIA_PROP_WRITE
%WIA_PROP_SYNC_REQUIRED   = &H04???

%WIA_PROP_NONE            = &H08???
%WIA_PROP_RANGE           = &H10???
%WIA_PROP_LIST            = &H20???
%WIA_PROP_FLAG            = &H40???

%WIA_PROP_CACHEABLE       = &H10000???

'//
'// IWiaItem2 CreateChildItem flag constants
'//

%COPY_PARENT_PROPERTY_VALUES = &H40000000???

'//
'// WIA item access flag constants
'//

%WIA_ITEM_CAN_BE_DELETED  = &H80???
%WIA_ITEM_READ            = %WIA_PROP_READ
%WIA_ITEM_WRITE           = %WIA_PROP_WRITE
%WIA_ITEM_RD              = %WIA_ITEM_READ OR %WIA_ITEM_CAN_BE_DELETED
%WIA_ITEM_RWD             = %WIA_ITEM_READ OR %WIA_ITEM_WRITE OR %WIA_ITEM_CAN_BE_DELETED

'//
'// WIA property container constants
'//

%WIA_RANGE_MIN                         = 0
%WIA_RANGE_NOM                         = 1
%WIA_RANGE_MAX                         = 2
%WIA_RANGE_STEP                        = 3
%WIA_RANGE_NUM_ELEMS                   = 4

%WIA_LIST_COUNT                        = 0
%WIA_LIST_NOM                          = 1
%WIA_LIST_VALUES                       = 2
%WIA_LIST_NUM_ELEMS                    = 2

%WIA_FLAG_NOM                          = 0
%WIA_FLAG_VALUES                       = 1
%WIA_FLAG_NUM_ELEMS                    = 2

'//
'// WIA property LIST container MACROS
'//

'#define WIA_PROP_LIST_COUNT(ppv) (((PROPVARIANT*)ppv)->cal.cElems - WIA_LIST_VALUES)

'#define WIA_PROP_LIST_VALUE(ppv, index)                              \\
'     ((index > ((PROPVARIANT*) ppv)->cal.cElems - WIA_LIST_VALUES) || (index < -WIA_LIST_NOM)) ?\\
'     NULL :                                                          \\
'     (((PROPVARIANT*) ppv)->vt == VT_UI1) ?                          \\
'     ((PROPVARIANT*) ppv)->caub.pElems[WIA_LIST_VALUES + index] :    \\
'     (((PROPVARIANT*) ppv)->vt == VT_UI2) ?                          \\
'     ((PROPVARIANT*) ppv)->caui.pElems[WIA_LIST_VALUES + index] :    \\
'     (((PROPVARIANT*) ppv)->vt == VT_UI4) ?                          \\
'     ((PROPVARIANT*) ppv)->caul.pElems[WIA_LIST_VALUES + index] :    \\
'     (((PROPVARIANT*) ppv)->vt == VT_I2) ?                           \\
'     ((PROPVARIANT*) ppv)->cai.pElems[WIA_LIST_VALUES + index] :     \\
'     (((PROPVARIANT*) ppv)->vt == VT_I4) ?                           \\
'     ((PROPVARIANT*) ppv)->cal.pElems[WIA_LIST_VALUES + index] :     \\
'     (((PROPVARIANT*) ppv)->vt == VT_R4) ?                           \\
'     ((PROPVARIANT*) ppv)->caflt.pElems[WIA_LIST_VALUES + index] :   \\
'     (((PROPVARIANT*) ppv)->vt == VT_R8) ?                           \\
'     ((PROPVARIANT*) ppv)->cadbl.pElems[WIA_LIST_VALUES + index] :   \\
'     (((PROPVARIANT*) ppv)->vt == VT_BSTR) ?                         \\
'     (LONG)(((PROPVARIANT*) ppv)->cabstr.pElems[WIA_LIST_VALUES + index]) : \\
'     NULL

'//
'// Microsoft defined WIA property offset constants
'//

%WIA_DIP_FIRST                   = 2
%WIA_IPA_FIRST                   = 4098
%WIA_DPF_FIRST                   = 3330
%WIA_IPS_FIRST                   = 6146
%WIA_DPS_FIRST                   = 3074
%WIA_IPC_FIRST                   = 5122
%WIA_NUM_IPC                     =    9
%WIA_RESERVED_FOR_NEW_PROPS      = 1024

'//
'// WIA_DPC_WHITE_BALANCE constants
'//

%WIA_DPC_WHITEBALANCE_MANUAL       = 1
%WIA_DPC_WHITEBALANCE_AUTO         = 2
%WIA_DPC_WHITEBALANCE_ONEPUSH_AUTO = 3
%WIA_DPC_WHITEBALANCE_DAYLIGHT     = 4
%WIA_DPC_WHITEBALANCE_FLORESCENT   = 5
%WIA_DPC_WHITEBALANCE_TUNGSTEN     = 6
%WIA_DPC_WHITEBALANCE_FLASH        = 7

'//
'// WIA_DPC_FOCUS_MODE constants
'//

%WIA_DPC_FOCUSMODE_MANUAL       = 1
%WIA_DPC_FOCUSMODE_AUTO         = 2
%WIA_DPC_FOCUSMODE_MACROAUTO    = 3

'//
'// WIA_DPC_EXPOSURE_METERING_MODE constants
'//

%WIA_DPC_EXPOSUREMETERING_AVERAGE      = 1
%WIA_DPC_EXPOSUREMETERING_CENTERWEIGHT = 2
%WIA_DPC_EXPOSUREMETERING_MULTISPOT    = 3
%WIA_DPC_EXPOSUREMETERING_CENTERSPOT   = 4

'//
'// WIA_DPC_FLASH_MODE constants
'//

%WIA_DPC_FLASHMODE_AUTO         = 1
%WIA_DPC_FLASHMODE_OFF          = 2
%WIA_DPC_FLASHMODE_FILL         = 3
%WIA_DPC_FLASHMODE_REDEYE_AUTO  = 4
%WIA_DPC_FLASHMODE_REDEYE_FILL  = 5
%WIA_DPC_FLASHMODE_EXTERNALSYNC = 6

'//
'// WIA_DPC_EXPOSURE_MODE constants
'//

%WIA_DPC_EXPOSUREMODE_MANUAL            = 1
%WIA_DPC_EXPOSUREMODE_AUTO              = 2
%WIA_DPC_EXPOSUREMODE_APERTURE_PRIORITY = 3
%WIA_DPC_EXPOSUREMODE_SHUTTER_PRIORITY  = 4
%WIA_DPC_EXPOSUREMODE_PROGRAM_CREATIVE  = 5
%WIA_DPC_EXPOSUREMODE_PROGRAM_ACTION    = 6
%WIA_DPC_EXPOSUREMODE_PORTRAIT          = 7

'//
'// WIA_DPC_CAPTURE_MODE constants
'//

%WIA_DPC_CAPTUREMODE_NORMAL    = 1
%WIA_DPC_CAPTUREMODE_BURST     = 2
%WIA_DPC_CAPTUREMODE_TIMELAPSE = 3

'//
'// WIA_DPC_EFFECT_MODE constants
'//

%WIA_DPC_EFFECTMODE_STANDARD = 1
%WIA_DPC_EFFECTMODE_BW       = 2
%WIA_DPC_EFFECTMODE_SEPIA    = 3

'//
'// WIA_DPC_FOCUS_METERING_MODE constants
'//

%WIA_DPC_FOCUSMETERING_CENTERSPOT = 1
%WIA_DPC_FOCUSMETERING_MULTISPOT  = 2

'//
'// WIA_DPC_POWER_MODE constants
'//

%WIA_DPC_POWERMODE_LINE    = 1
%WIA_DPC_POWERMODE_BATTERY = 2

'//
'// WIA_DPS_SHEET_FEEDER_REGISTRATION and
'// WIA_DPS_HORIZONTAL_BED_REGISTRATION constants
'//

%WIA_DPS_SHEET_FEEDER_REGISTRATION_LEFT_JUSTIFIED  = 0
%WIA_DPS_SHEET_FEEDER_REGISTRATION_CENTERED        = 1
%WIA_DPS_SHEET_FEEDER_REGISTRATION_RIGHT_JUSTIFIED = 2

%WIA_DPS_HORIZONTAL_BED_REGISTRATION_LEFT_JUSTIFIED  = 0
%WIA_DPS_HORIZONTAL_BED_REGISTRATION_CENTERED        = 1
%WIA_DPS_HORIZONTAL_BED_REGISTRATION_RIGHT_JUSTIFIED = 2

'//
'// WIA_DPS_VERTICAL_BED_REGISTRATION constants
'//

%WIA_DPS_VERTICAL_BED_REGISTRATION_TOP_JUSTIFIED    = 0
%WIA_DPS_VERTICAL_BED_REGISTRATION_CENTERED         = 1
%WIA_DPS_VERTICAL_BED_REGISTRATION_BOTTOM_JUSTIFIED = 2

'//
'// WIA_DPS_ORIENTATION and WIA_DPS_ROTATION constants
'//

%WIA_DPS_ORIENTATION_PORTRAIT  = 0
'#if (_WIN32_WINNT >= 0x0600)
%WIA_DPS_ORIENTATION_LANSCAPE  = 1
%WIA_DPS_ORIENTATION_LANDSCAPE = %WIA_DPS_ORIENTATION_LANSCAPE
'#endif
%WIA_DPS_ROTATION_ROT180    = 2
%WIA_DPS_ROTATION_ROT270    = 3

'//
'// WIA_DPS_MIRROR flags
'//

%WIA_DPS_MIRROR_MIRRORED                   = &H01???

'//
'// WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES flags
'//

%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_FEED                       = &H01???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_FLAT                       = &H02???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DUP                        = &H04???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_FLAT                = &H08???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_SCAN                = &H10???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_FEED                = &H20???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_DUP                 = &H40???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_FEED_AVAIL          = &H80???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_DUP_AVAIL           = &H100???
'#if (_WIN32_WINNT >= 0x0600)
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_FILM_TPA                   = &H200???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_FILM_TPA            = &H400???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_STOR                       = &H800???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_DETECT_STOR                = &H1000???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_ADVANCED_DUP               = &H2000???
%WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_AUTO_SOURCE                = &H8000???
'#endif

'//
'// WIA_DPS_DOCUMENT_HANDLING_STATUS flags
'//

%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_READY                      = &H01???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_FLAT_READY                 = &H02???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_DUP_READY                  = &H04???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_FLAT_COVER_UP              = &H08???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_PATH_COVER_UP              = &H10???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_PAPER_JAM                  = &H20???
'#if (_WIN32_WINNT >= 0x0600)
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_FILM_TPA_READY             = &H40???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_STORAGE_READY              = &H80???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_STORAGE_FULL               = &H100???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_MULTIPLE_FEED              = &H200???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_DEVICE_ATTENTION           = &H400???
%WIA_DPS_DOCUMENT_HANDLING_STATUS_FEED_LAMP_ERR                   = &H800???
'#endif

'//
'// WIA_DPS_DOCUMENT_HANDLING_SELECT flags
'//

%WIA_DPS_DOCUMENT_HANDLING_SELECT_FEEDER                     = &H001???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_FLATBED                    = &H002???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_DUPLEX                     = &H004???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_FRONT_FIRST                = &H008???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_BACK_FIRST                 = &H010???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_FRONT_ONLY                 = &H020???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_BACK_ONLY                  = &H040???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_NEXT_PAGE                  = &H080???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_PREFEED                    = &H100???
%WIA_DPS_DOCUMENT_HANDLING_SELECT_AUTO_ADVANCE               = &H200???

'#if (_WIN32_WINNT >= 0x0600)
'//
'// New WIA_IPS_DOCUMENT_HANDLING_SELECT flag
'//
%WIA_IPS_DOCUMENT_HANDLING_SELECT_ADVANCED_DUPLEX            = &H400???
'#endif //#if (_WIN32_WINNT >= 0x0600)

'//
'// WIA_DPS_TRANSPARENCY / WIA_DPS_TRANSPARENCY_STATUS flags
'//

%LIGHT_SOURCE_PRESENT_DETECT = &H01???
%LIGHT_SOURCE_PRESENT        = &H02???
%LIGHT_SOURCE_DETECT_READY   = &H04???
%LIGHT_SOURCE_READY          = &H08???

'//
'// WIA_DPS_TRANSPARENCY_CAPABILITIES
'//

%TRANSPARENCY_DYNAMIC_FRAME_SUPPORT = &H01
%TRANSPARENCY_STATIC_FRAME_SUPPORT  = &H02

'//
'// WIA_DPS_TRANSPARENCY_SELECT flags
'//

%LIGHT_SOURCE_SELECT           = &H001???  ' // currently not used
%LIGHT_SOURCE_POSITIVE         = &H002???
%LIGHT_SOURCE_NEGATIVE         = &H004???

'//
'// WIA_DPS_SCAN_AHEAD_PAGES constants
'//

%WIA_SCAN_AHEAD_ALL         = 0

'//
'// WIA_DPS_PAGES constants
'//

%WIA_DPS_PAGES_ALL_PAGES                  = 0

'//
'// WIA_DPS_PREVIEW constants
'//

%WIA_FINAL_SCAN             = 0
%WIA_PREVIEW_SCAN           = 1

'//
'// WIA_DPS_SHOW_PREVIEW_CONTROL constants
'//

%WIA_SHOW_PREVIEW_CONTROL      = 0
%WIA_DONT_SHOW_PREVIEW_CONTROL = 1

'//
'// Predefined strings for WIA_DPS_ENDORSER_STRING
'//

$$WIA_ENDORSER_TOK_DATE       = "$$DATE$$"$$
$$WIA_ENDORSER_TOK_TIME       = "$$TIME$$"$$
$$WIA_ENDORSER_TOK_PAGE_COUNT = "$$PAGE_COUNT$$"$$
$$WIA_ENDORSER_TOK_DAY        = "$$DAY$$"$$
$$WIA_ENDORSER_TOK_MONTH      = "$$MONTH$$"$$
$$WIA_ENDORSER_TOK_YEAR       = "$$YEAR$$"$$

'//
'// WIA_DPS_PAGE_SIZE/WIA_IPS_PAGE_SIZE constants
'// Dimensions are defined as (WIDTH x HEIGHT) in 1/1000ths of an inch
'//

%WIA_PAGE_A4            = 0  ' //  8267 x 11692
%WIA_PAGE_LETTER        = 1  ' //  8500 x 11000
%WIA_PAGE_CUSTOM        = 2  ' // (current extent settings)

%WIA_PAGE_USLEGAL       = 3  ' //  8500 x 14000
%WIA_PAGE_USLETTER      = %WIA_PAGE_LETTER
%WIA_PAGE_USLEDGER      = 4  ' // 11000 x 17000
%WIA_PAGE_USSTATEMENT   = 5  ' //  5500 x  8500
%WIA_PAGE_BUSINESSCARD  = 6  ' //  3543 x  2165

'//
'// ISO A page size constants
'//

%WIA_PAGE_ISO_A0       =  7 '// 33110 x 46811
%WIA_PAGE_ISO_A1       =  8 '// 23385 x 33110
%WIA_PAGE_ISO_A2       =  9 '// 16535 x 23385
%WIA_PAGE_ISO_A3       = 10 '// 11692 x 16535
%WIA_PAGE_ISO_A4       = %WIA_PAGE_A4
%WIA_PAGE_ISO_A5       = 11 '//  5826 x  8267
%WIA_PAGE_ISO_A6       = 12 '//  4133 x  5826
%WIA_PAGE_ISO_A7       = 13 '//  2913 x  4133
%WIA_PAGE_ISO_A8       = 14 '//  2047 x  2913
%WIA_PAGE_ISO_A9       = 15 '//  1456 x  2047
%WIA_PAGE_ISO_A10      = 16 '//  1023 x  1456

'//
'// ISO B page size constants
'//

%WIA_PAGE_ISO_B0       = 17 '//  39370 x 55669
%WIA_PAGE_ISO_B1       = 18 '//  27834 x 39370
%WIA_PAGE_ISO_B2       = 19 '//  19685 x 27834
%WIA_PAGE_ISO_B3       = 20 '//  13897 x 19685
%WIA_PAGE_ISO_B4       = 21 '//   9842 x 13897
%WIA_PAGE_ISO_B5       = 22 '//   6929 x  9842
%WIA_PAGE_ISO_B6       = 23 '//   4921 x  6929
%WIA_PAGE_ISO_B7       = 24 '//   3464 x  4921
%WIA_PAGE_ISO_B8       = 25 '//   2440 x  3464
%WIA_PAGE_ISO_B9       = 26 '//   1732 x  2440
%WIA_PAGE_ISO_B10      = 27 '//   1220 x  1732

'//
'// ISO C page size constants
'//

%WIA_PAGE_ISO_C0       = 28 '//  36102 x 51062
%WIA_PAGE_ISO_C1       = 29 '//  25511 x 36102
%WIA_PAGE_ISO_C2       = 30 '//  18031 x 25511
%WIA_PAGE_ISO_C3       = 31 '//  12755 x 18031
%WIA_PAGE_ISO_C4       = 32 '//   9015 x 12755 (unfolded)
%WIA_PAGE_ISO_C5       = 33 '//   6377 x  9015 (folded once)
%WIA_PAGE_ISO_C6       = 34 '//   4488 x  6377 (folded twice)
%WIA_PAGE_ISO_C7       = 35 '//   3188 x  4488
%WIA_PAGE_ISO_C8       = 36 '//   2244 x  3188
%WIA_PAGE_ISO_C9       = 37 '//   1574 x  2244
%WIA_PAGE_ISO_C10      = 38 '//   1102 x  1574

'//
'// JIS B page size constants
'//

%WIA_PAGE_JIS_B0       = 39 '//  40551 x 57322
%WIA_PAGE_JIS_B1       = 40 '//  28661 x 40551
%WIA_PAGE_JIS_B2       = 41 '//  20275 x 28661
%WIA_PAGE_JIS_B3       = 42 '//  14330 x 20275
%WIA_PAGE_JIS_B4       = 43 '//  10118 x 14330
%WIA_PAGE_JIS_B5       = 44 '//   7165 x 10118
%WIA_PAGE_JIS_B6       = 45 '//   5039 x  7165
%WIA_PAGE_JIS_B7       = 46 '//   3582 x  5039
%WIA_PAGE_JIS_B8       = 47 '//   2519 x  3582
%WIA_PAGE_JIS_B9       = 48 '//   1771 x  2519
%WIA_PAGE_JIS_B10      = 49 '//   1259 x  1771

'//
'// JIS A page size constants
'//

%WIA_PAGE_JIS_2A       = 50 '//  46811 x 66220
%WIA_PAGE_JIS_4A       = 51 '//  66220 x  93622

'//
'// DIN B page size constants
'//

%WIA_PAGE_DIN_2B       = 52 '//  55669 x 78740
%WIA_PAGE_DIN_4B       = 53 '//  78740 x 111338

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
'//
'// Additional WIA_IPS_PAGE_SIZE constants:
'//
%WIA_PAGE_AUTO         = 100
%WIA_PAGE_CUSTOM_BASE  = &H8000
#ENDIF '//#if (_WIN32_WINNT >= 0x0600)

'//
'// WIA_IPA_COMPRESSION constants
'//

%WIA_COMPRESSION_NONE    = 0
%WIA_COMPRESSION_BI_RLE4 = 1
%WIA_COMPRESSION_BI_RLE8 = 2
%WIA_COMPRESSION_G3      = 3
%WIA_COMPRESSION_G4      = 4
%WIA_COMPRESSION_JPEG    = 5
'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%WIA_COMPRESSION_JBIG    = 6
%WIA_COMPRESSION_JPEG2K  = 7
%WIA_COMPRESSION_PNG     = 8
#ENDIF ' //#if (_WIN32_WINNT >= 0x0600)

'//
'// WIA_IPA_PLANAR constants
'//

%WIA_PACKED_PIXEL = 0
%WIA_PLANAR       = 1

'//
'// WIA_IPA_DATATYPE constants
'//

%WIA_DATA_THRESHOLD       = 0
%WIA_DATA_DITHER          = 1
%WIA_DATA_GRAYSCALE       = 2
%WIA_DATA_COLOR           = 3
%WIA_DATA_COLOR_THRESHOLD = 4
%WIA_DATA_COLOR_DITHER    = 5
'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%WIA_DATA_RAW_RGB         = 6
%WIA_DATA_RAW_BGR         = 7
%WIA_DATA_RAW_YUV         = 8
%WIA_DATA_RAW_YUVK        = 9
%WIA_DATA_RAW_CMY         = 10
%WIA_DATA_RAW_CMYK        = 11
#ENDIF ' //#if (_WIN32_WINNT >= 0x0600)

'//
'// WIA_IPS_PHOTOMETRIC_INTERP constants
'//

%WIA_PHOTO_WHITE_1        = 0  ' // white is 1, black is 0
%WIA_PHOTO_WHITE_0        = 1  ' // white is 0, black is 1

'//
'// WIA_IPA_SUPPRESS_PROPERTY_PAGE flags
'//

%WIA_PROPPAGE_SCANNER_ITEM_GENERAL = &H00000001???
%WIA_PROPPAGE_CAMERA_ITEM_GENERAL  = &H00000002???
%WIA_PROPPAGE_DEVICE_GENERAL       = &H00000004???

'//
'// WIA_IPS_CUR_INTENT flags
'//
%WIA_INTENT_NONE                 = &H00000000???
%WIA_INTENT_IMAGE_TYPE_COLOR     = &H00000001???
%WIA_INTENT_IMAGE_TYPE_GRAYSCALE = &H00000002???
%WIA_INTENT_IMAGE_TYPE_TEXT      = &H00000004???
%WIA_INTENT_IMAGE_TYPE_MASK      = &H0000000F???
%WIA_INTENT_MINIMIZE_SIZE        = &H00010000???
%WIA_INTENT_MAXIMIZE_QUALITY     = &H00020000???
%WIA_INTENT_BEST_PREVIEW         = &H00040000???
%WIA_INTENT_SIZE_MASK            = &H000F0000???

'//
'// global WIA device informationproperty array
'//

%WIA_NUM_DIP = 16

'#ifdef WIA_DECLARE_DEVINFO_PROP_ARRAY

'PROPSPEC g_psDeviceInfo[WIA_NUM_DIP] =
'{
'    {PRSPEC_PROPID, WIA_DIP_DEV_ID},
'    {PRSPEC_PROPID, WIA_DIP_VEND_DESC},
'    {PRSPEC_PROPID, WIA_DIP_DEV_DESC},
'    {PRSPEC_PROPID, WIA_DIP_DEV_TYPE},
'    {PRSPEC_PROPID, WIA_DIP_PORT_NAME},
'    {PRSPEC_PROPID, WIA_DIP_DEV_NAME},
'    {PRSPEC_PROPID, WIA_DIP_SERVER_NAME},
'    {PRSPEC_PROPID, WIA_DIP_REMOTE_DEV_ID},
'    {PRSPEC_PROPID, WIA_DIP_UI_CLSID},
'    {PRSPEC_PROPID, WIA_DIP_HW_CONFIG},
'    {PRSPEC_PROPID, WIA_DIP_BAUDRATE},
'    {PRSPEC_PROPID, WIA_DIP_STI_GEN_CAPABILITIES},
'    {PRSPEC_PROPID, WIA_DIP_WIA_VERSION},
'    {PRSPEC_PROPID, WIA_DIP_DRIVER_VERSION},
'    {PRSPEC_PROPID, WIA_DIP_PNP_ID},
'    {PRSPEC_PROPID, WIA_DIP_STI_DRIVER_VERSION},
'};

'PROPID g_piDeviceInfo[WIA_NUM_DIP] =
'{
'    WIA_DIP_DEV_ID,
'    WIA_DIP_VEND_DESC,
'    WIA_DIP_DEV_DESC,
'    WIA_DIP_DEV_TYPE,
'    WIA_DIP_PORT_NAME,
'    WIA_DIP_DEV_NAME,
'    WIA_DIP_SERVER_NAME,
'    WIA_DIP_REMOTE_DEV_ID,
'    WIA_DIP_UI_CLSID,
'    WIA_DIP_HW_CONFIG,
'    WIA_DIP_BAUDRATE,
'    WIA_DIP_STI_GEN_CAPABILITIES,
'    WIA_DIP_WIA_VERSION,
'    WIA_DIP_DRIVER_VERSION,
'    WIA_DIP_PNP_ID,
'    WIA_DIP_STI_DRIVER_VERSION,
'};

'LPOLESTR g_pszDeviceInfo[WIA_NUM_DIP] =
'{
'    WIA_DIP_DEV_ID_STR,
'    WIA_DIP_VEND_DESC_STR,
'    WIA_DIP_DEV_DESC_STR,
'    WIA_DIP_DEV_TYPE_STR,
'    WIA_DIP_PORT_NAME_STR,
'    WIA_DIP_DEV_NAME_STR,
'    WIA_DIP_SERVER_NAME_STR,
'    WIA_DIP_REMOTE_DEV_ID_STR,
'    WIA_DIP_UI_CLSID_STR,
'    WIA_DIP_HW_CONFIG_STR,
'    WIA_DIP_BAUDRATE_STR,
'    WIA_DIP_STI_GEN_CAPABILITIES_STR,
'    WIA_DIP_WIA_VERSION_STR,
'    WIA_DIP_DRIVER_VERSION_STR,
'    WIA_DIP_PNP_ID_STR,
'    WIA_DIP_STI_DRIVER_VERSION_STR,
'};

'#else

'extern PROPSPEC g_psDeviceInfo[WIA_NUM_DIP];
'extern PROPID   g_piDeviceInfo[WIA_NUM_DIP];
'extern LPOLESTR g_pszDeviceInfo[WIA_NUM_DIP];

'#endif

'//
'// global WIA property ID to property name array
'//

'#ifdef DEFINE_WIA_PROPID_TO_NAME

'WIA_PROPID_TO_NAME g_wiaPropIdToName[] =
'{
'    {WIA_DIP_DEV_ID,                          WIA_DIP_DEV_ID_STR},
'    {WIA_DIP_VEND_DESC,                       WIA_DIP_VEND_DESC_STR},
'    {WIA_DIP_DEV_DESC,                        WIA_DIP_DEV_DESC_STR},
'    {WIA_DIP_DEV_TYPE,                        WIA_DIP_DEV_TYPE_STR},
'    {WIA_DIP_PORT_NAME,                       WIA_DIP_PORT_NAME_STR},
'    {WIA_DIP_DEV_NAME,                        WIA_DIP_DEV_NAME_STR},
'    {WIA_DIP_SERVER_NAME,                     WIA_DIP_SERVER_NAME_STR},
'    {WIA_DIP_REMOTE_DEV_ID,                   WIA_DIP_REMOTE_DEV_ID_STR},
'    {WIA_DIP_UI_CLSID,                        WIA_DIP_UI_CLSID_STR},
'    {WIA_DIP_HW_CONFIG,                       WIA_DIP_HW_CONFIG_STR},
'    {WIA_DIP_BAUDRATE,                        WIA_DIP_BAUDRATE_STR},
'    {WIA_DIP_STI_GEN_CAPABILITIES,            WIA_DIP_STI_GEN_CAPABILITIES_STR},
'    {WIA_DIP_WIA_VERSION,                     WIA_DIP_WIA_VERSION_STR},
'    {WIA_DIP_DRIVER_VERSION,                  WIA_DIP_DRIVER_VERSION_STR},
'    {WIA_DIP_PNP_ID,                          WIA_DIP_PNP_ID_STR},
'    {WIA_DIP_STI_DRIVER_VERSION,              WIA_DIP_STI_DRIVER_VERSION_STR},
'    {WIA_DPA_FIRMWARE_VERSION,                WIA_DPA_FIRMWARE_VERSION_STR},
'    {WIA_DPA_CONNECT_STATUS,                  WIA_DPA_CONNECT_STATUS_STR},
'    {WIA_DPA_DEVICE_TIME,                     WIA_DPA_DEVICE_TIME_STR},
'    {WIA_DPC_PICTURES_TAKEN,                  WIA_DPC_PICTURES_TAKEN_STR},
'    {WIA_DPC_PICTURES_REMAINING,              WIA_DPC_PICTURES_REMAINING_STR},
'    {WIA_DPC_EXPOSURE_MODE,                   WIA_DPC_EXPOSURE_MODE_STR},
'    {WIA_DPC_EXPOSURE_COMP,                   WIA_DPC_EXPOSURE_COMP_STR},
'    {WIA_DPC_EXPOSURE_TIME,                   WIA_DPC_EXPOSURE_TIME_STR},
'    {WIA_DPC_FNUMBER,                         WIA_DPC_FNUMBER_STR},
'    {WIA_DPC_FLASH_MODE,                      WIA_DPC_FLASH_MODE_STR},
'    {WIA_DPC_FOCUS_MODE,                      WIA_DPC_FOCUS_MODE_STR},
'    {WIA_DPC_FOCUS_MANUAL_DIST,               WIA_DPC_FOCUS_MANUAL_DIST_STR},
'    {WIA_DPC_ZOOM_POSITION,                   WIA_DPC_ZOOM_POSITION_STR},
'    {WIA_DPC_PAN_POSITION,                    WIA_DPC_PAN_POSITION_STR},
'    {WIA_DPC_TILT_POSITION,                   WIA_DPC_TILT_POSITION_STR},
'    {WIA_DPC_TIMER_MODE,                      WIA_DPC_TIMER_MODE_STR},
'    {WIA_DPC_TIMER_VALUE,                     WIA_DPC_TIMER_VALUE_STR},
'    {WIA_DPC_POWER_MODE,                      WIA_DPC_POWER_MODE_STR},
'    {WIA_DPC_BATTERY_STATUS,                  WIA_DPC_BATTERY_STATUS_STR},
'    {WIA_DPC_DIMENSION,                       WIA_DPC_DIMENSION_STR},
'    {WIA_DPS_HORIZONTAL_BED_SIZE,             WIA_DPS_HORIZONTAL_BED_SIZE_STR},
'    {WIA_DPS_VERTICAL_BED_SIZE,               WIA_DPS_VERTICAL_BED_SIZE_STR},
'    {WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE,      WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE_STR},
'    {WIA_DPS_VERTICAL_SHEET_FEED_SIZE,        WIA_DPS_VERTICAL_SHEET_FEED_SIZE_STR},
'    {WIA_DPS_SHEET_FEEDER_REGISTRATION,       WIA_DPS_SHEET_FEEDER_REGISTRATION_STR},
'    {WIA_DPS_HORIZONTAL_BED_REGISTRATION,     WIA_DPS_HORIZONTAL_BED_REGISTRATION_STR},
'    {WIA_DPS_VERTICAL_BED_REGISTRATION,       WIA_DPS_VERTICAL_BED_REGISTRATION_STR},
'    {WIA_DPS_PLATEN_COLOR,                    WIA_DPS_PLATEN_COLOR_STR},
'    {WIA_DPS_PAD_COLOR,                       WIA_DPS_PAD_COLOR_STR},
'    {WIA_DPS_FILTER_SELECT,                   WIA_DPS_FILTER_SELECT_STR},
'    {WIA_DPS_DITHER_SELECT,                   WIA_DPS_DITHER_SELECT_STR},
'    {WIA_DPS_DITHER_PATTERN_DATA,             WIA_DPS_DITHER_PATTERN_DATA_STR},
'    {WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES,  WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_STR},
'    {WIA_DPS_DOCUMENT_HANDLING_STATUS,        WIA_DPS_DOCUMENT_HANDLING_STATUS_STR},
'    {WIA_DPS_DOCUMENT_HANDLING_SELECT,        WIA_DPS_DOCUMENT_HANDLING_SELECT_STR},
'    {WIA_DPS_DOCUMENT_HANDLING_CAPACITY,      WIA_DPS_DOCUMENT_HANDLING_CAPACITY_STR},
'    {WIA_DPS_OPTICAL_XRES,                    WIA_DPS_OPTICAL_XRES_STR},
'    {WIA_DPS_OPTICAL_YRES,                    WIA_DPS_OPTICAL_YRES_STR},
'    {WIA_DPS_ENDORSER_CHARACTERS,             WIA_DPS_ENDORSER_CHARACTERS_STR},
'    {WIA_DPS_ENDORSER_STRING,                 WIA_DPS_ENDORSER_STRING_STR},
'    {WIA_DPS_SCAN_AHEAD_PAGES,                WIA_DPS_SCAN_AHEAD_PAGES_STR},
'    {WIA_DPS_MAX_SCAN_TIME,                   WIA_DPS_MAX_SCAN_TIME_STR},
'    {WIA_DPS_PAGES,                           WIA_DPS_PAGES_STR},
'    {WIA_DPS_PAGE_SIZE,                       WIA_DPS_PAGE_SIZE_STR},
'    {WIA_DPS_PAGE_WIDTH,                      WIA_DPS_PAGE_WIDTH_STR},
'    {WIA_DPS_PAGE_HEIGHT,                     WIA_DPS_PAGE_HEIGHT_STR},
'    {WIA_DPS_PREVIEW,                         WIA_DPS_PREVIEW_STR},
'    {WIA_DPS_TRANSPARENCY,                    WIA_DPS_TRANSPARENCY_STR},
'    {WIA_DPS_TRANSPARENCY_SELECT,             WIA_DPS_TRANSPARENCY_SELECT_STR},
'    {WIA_DPS_SHOW_PREVIEW_CONTROL,            WIA_DPS_SHOW_PREVIEW_CONTROL_STR},
'    {WIA_DPS_MIN_HORIZONTAL_SHEET_FEED_SIZE,  WIA_DPS_MIN_HORIZONTAL_SHEET_FEED_SIZE_STR},
'    {WIA_DPS_MIN_VERTICAL_SHEET_FEED_SIZE,    WIA_DPS_MIN_VERTICAL_SHEET_FEED_SIZE_STR},
'    {WIA_DPS_USER_NAME,                       WIA_DPS_USER_NAME_STR},
'    {WIA_DPV_LAST_PICTURE_TAKEN,              WIA_DPV_LAST_PICTURE_TAKEN_STR},
'    {WIA_DPV_IMAGES_DIRECTORY,                WIA_DPV_IMAGES_DIRECTORY_STR},
'    {WIA_DPV_DSHOW_DEVICE_PATH,               WIA_DPV_DSHOW_DEVICE_PATH_STR},
'    {WIA_DPF_MOUNT_POINT,                     WIA_DPF_MOUNT_POINT_STR},
'    {WIA_IPA_ITEM_NAME,                       WIA_IPA_ITEM_NAME_STR},
'    {WIA_IPA_FULL_ITEM_NAME,                  WIA_IPA_FULL_ITEM_NAME_STR},
'    {WIA_IPA_ITEM_TIME,                       WIA_IPA_ITEM_TIME_STR},
'    {WIA_IPA_ITEM_FLAGS,                      WIA_IPA_ITEM_FLAGS_STR},
'    {WIA_IPA_ACCESS_RIGHTS,                   WIA_IPA_ACCESS_RIGHTS_STR},
'    {WIA_IPA_DATATYPE,                        WIA_IPA_DATATYPE_STR},
'    {WIA_IPA_DEPTH,                           WIA_IPA_DEPTH_STR},
'    {WIA_IPA_PREFERRED_FORMAT,                WIA_IPA_PREFERRED_FORMAT_STR},
'    {WIA_IPA_FORMAT,                          WIA_IPA_FORMAT_STR},
'    {WIA_IPA_COMPRESSION,                     WIA_IPA_COMPRESSION_STR},
'    {WIA_IPA_TYMED,                           WIA_IPA_TYMED_STR},
'    {WIA_IPA_CHANNELS_PER_PIXEL,              WIA_IPA_CHANNELS_PER_PIXEL_STR},
'    {WIA_IPA_BITS_PER_CHANNEL,                WIA_IPA_BITS_PER_CHANNEL_STR},
'    {WIA_IPA_PLANAR,                          WIA_IPA_PLANAR_STR},
'    {WIA_IPA_PIXELS_PER_LINE,                 WIA_IPA_PIXELS_PER_LINE_STR},
'    {WIA_IPA_BYTES_PER_LINE,                  WIA_IPA_BYTES_PER_LINE_STR},
'    {WIA_IPA_NUMBER_OF_LINES,                 WIA_IPA_NUMBER_OF_LINES_STR},
'    {WIA_IPA_GAMMA_CURVES,                    WIA_IPA_GAMMA_CURVES_STR},
'    {WIA_IPA_ITEM_SIZE,                       WIA_IPA_ITEM_SIZE_STR},
'    {WIA_IPA_COLOR_PROFILE,                   WIA_IPA_COLOR_PROFILE_STR},
'    {WIA_IPA_MIN_BUFFER_SIZE,                 WIA_IPA_MIN_BUFFER_SIZE_STR},
'    {WIA_IPA_REGION_TYPE,                     WIA_IPA_REGION_TYPE_STR},
'    {WIA_IPA_ICM_PROFILE_NAME,                WIA_IPA_ICM_PROFILE_NAME_STR},
'    {WIA_IPA_APP_COLOR_MAPPING,               WIA_IPA_APP_COLOR_MAPPING_STR},
'    {WIA_IPA_PROP_STREAM_COMPAT_ID,           WIA_IPA_PROP_STREAM_COMPAT_ID_STR},
'    {WIA_IPA_FILENAME_EXTENSION,              WIA_IPA_FILENAME_EXTENSION_STR},
'    {WIA_IPA_SUPPRESS_PROPERTY_PAGE,          WIA_IPA_SUPPRESS_PROPERTY_PAGE_STR},
'    {WIA_IPC_THUMBNAIL,                       WIA_IPC_THUMBNAIL_STR},
'    {WIA_IPC_THUMB_WIDTH,                     WIA_IPC_THUMB_WIDTH_STR},
'    {WIA_IPC_THUMB_HEIGHT,                    WIA_IPC_THUMB_HEIGHT_STR},
'    {WIA_IPC_AUDIO_AVAILABLE,                 WIA_IPC_AUDIO_AVAILABLE_STR},
'    {WIA_IPC_AUDIO_DATA_FORMAT,               WIA_IPC_AUDIO_DATA_FORMAT_STR},
'    {WIA_IPC_AUDIO_DATA,                      WIA_IPC_AUDIO_DATA_STR},
'    {WIA_IPC_NUM_PICT_PER_ROW,                WIA_IPC_NUM_PICT_PER_ROW_STR},
'    {WIA_IPC_SEQUENCE,                        WIA_IPC_SEQUENCE_STR},
'    {WIA_IPC_TIMEDELAY,                       WIA_IPC_TIMEDELAY_STR},
'    {WIA_IPS_CUR_INTENT,                      WIA_IPS_CUR_INTENT_STR},
'    {WIA_IPS_XRES,                            WIA_IPS_XRES_STR},
'    {WIA_IPS_YRES,                            WIA_IPS_YRES_STR},
'    {WIA_IPS_XPOS,                            WIA_IPS_XPOS_STR},
'    {WIA_IPS_YPOS,                            WIA_IPS_YPOS_STR},
'    {WIA_IPS_XEXTENT,                         WIA_IPS_XEXTENT_STR},
'    {WIA_IPS_YEXTENT,                         WIA_IPS_YEXTENT_STR},
'    {WIA_IPS_PHOTOMETRIC_INTERP,              WIA_IPS_PHOTOMETRIC_INTERP_STR},
'    {WIA_IPS_BRIGHTNESS,                      WIA_IPS_BRIGHTNESS_STR},
'    {WIA_IPS_CONTRAST,                        WIA_IPS_CONTRAST_STR},
'    {WIA_IPS_ORIENTATION,                     WIA_IPS_ORIENTATION_STR},
'    {WIA_IPS_ROTATION,                        WIA_IPS_ROTATION_STR},
'    {WIA_IPS_MIRROR,                          WIA_IPS_MIRROR_STR},
'    {WIA_IPS_THRESHOLD,                       WIA_IPS_THRESHOLD_STR},
'    {WIA_IPS_INVERT,                          WIA_IPS_INVERT_STR},
'    {WIA_IPS_WARM_UP_TIME,                    WIA_IPS_WARM_UP_TIME_STR},
'#if (_WIN32_WINNT >= 0x0600)
'    {WIA_IPA_ITEM_CATEGORY,                   WIA_IPA_ITEM_CATEGORY_STR},
'    {WIA_IPA_RAW_BITS_PER_CHANNEL,            WIA_IPA_RAW_BITS_PER_CHANNEL_STR},
'    {WIA_IPS_DESKEW_X,                        WIA_IPS_DESKEW_X_STR},
'    {WIA_IPS_DESKEW_Y,                        WIA_IPS_DESKEW_Y_STR},
'    {WIA_IPS_SEGMENTATION,                    WIA_IPS_SEGMENTATION_STR},
'    {WIA_IPS_MAX_HORIZONTAL_SIZE,             WIA_IPS_MAX_HORIZONTAL_SIZE_STR},
'    {WIA_IPS_MAX_VERTICAL_SIZE,               WIA_IPS_MAX_VERTICAL_SIZE_STR},
'    {WIA_IPS_MIN_HORIZONTAL_SIZE,             WIA_IPS_MIN_HORIZONTAL_SIZE_STR},
'    {WIA_IPS_MIN_VERTICAL_SIZE,               WIA_IPS_MIN_VERTICAL_SIZE_STR},
'    {WIA_IPS_SHEET_FEEDER_REGISTRATION,       WIA_IPS_SHEET_FEEDER_REGISTRATION_STR},
'    {WIA_IPS_DOCUMENT_HANDLING_SELECT,        WIA_IPS_DOCUMENT_HANDLING_SELECT_STR},
'    {WIA_IPS_OPTICAL_XRES,                    WIA_IPS_OPTICAL_XRES_STR},
'    {WIA_IPS_OPTICAL_YRES,                    WIA_IPS_OPTICAL_YRES_STR},
'    {WIA_IPS_PAGES,                           WIA_IPS_PAGES_STR},
'    {WIA_IPS_PAGE_SIZE,                       WIA_IPS_PAGE_SIZE_STR},
'    {WIA_IPS_PAGE_WIDTH,                      WIA_IPS_PAGE_WIDTH_STR},
'    {WIA_IPS_PAGE_HEIGHT,                     WIA_IPS_PAGE_HEIGHT_STR},
'    {WIA_IPS_PREVIEW,                         WIA_IPS_PREVIEW_STR},
'    {WIA_IPS_SHOW_PREVIEW_CONTROL,            WIA_IPS_SHOW_PREVIEW_CONTROL_STR},
'    {WIA_IPS_TRANSFER_CAPABILITIES,           WIA_IPS_TRANSFER_CAPABILITIES_STR},
'    {WIA_IPS_FILM_SCAN_MODE,                  WIA_IPS_FILM_SCAN_MODE_STR},
'    {WIA_IPS_LAMP,                            WIA_IPS_LAMP_STR},
'    {WIA_IPS_LAMP_AUTO_OFF,                   WIA_IPS_LAMP_AUTO_OFF_STR},
'    {WIA_IPS_AUTO_DESKEW,                     WIA_IPS_AUTO_DESKEW_STR},
'    {WIA_IPS_SUPPORTS_CHILD_ITEM_CREATION,    WIA_IPS_SUPPORTS_CHILD_ITEM_CREATION_STR},
'    {WIA_IPS_PREVIEW_TYPE,                    WIA_IPS_PREVIEW_TYPE_STR},
'    {WIA_IPS_XSCALING,                        WIA_IPS_XSCALING_STR},
'    {WIA_IPS_YSCALING,                        WIA_IPS_YSCALING_STR},
'    {WIA_IPA_UPLOAD_ITEM_SIZE,                WIA_IPA_UPLOAD_ITEM_SIZE_STR},
'    {WIA_IPA_ITEMS_STORED,                    WIA_IPA_ITEMS_STORED_STR},
'#endif
'    {0,                                       L"Not a WIA property"}
'};

'#else

'extern WIA_PROPID_TO_NAME g_wiaPropIdToName[];

'#endif

'#include <poppack.h>
