' ########################################################################################
' Microsoft Windows
' File: PortableDevice.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PORTABLEDEVICE_INC = 1

'#pragma once
'// Windows XP SP2, Windows Vista, or later (excluding Windows Server 2003)
'#if ((NTDDI_VERSION >= NTDDI_WINXPSP2 && NTDDI_VERSION < NTDDI_WS03) || (NTDDI_VERSION >= NTDDI_WINLH))
#INCLUDE ONCE "propkeydef.inc"
#INCLUDE ONCE "winioctl.inc"

'/****************************************************************************
'* This section declares WPD guids used in PnP
'****************************************************************************/
'//
'// GUID_DEVINTERFACE_WPD
'//   This GUID is used to identify devices / drivers that support the WPD DDI.
'//   The WPD Class Extension component enables this device interface for WPD Drivers that use it. Clients use this PnP interface when registering for PnP device arrival messages for WPD devices.
$GUID_DEVINTERFACE_WPD = GUID$("{6AC27878-A6FA-4155-BA85-F98F491D4F33}")

'//
'// GUID_DEVINTERFACE_WPD_PRIVATE
'//   This GUID is used to identify devices / drivers that can be used only by a specialized WPD client and will not show up in normal WPD enumeration.
'//   Devices identified with this interface cannot be used with normal WPD applications. Generic WPD drivers and clients should not use this interface.
$GUID_DEVINTERFACE_WPD_PRIVATE = GUID$("{BA0C718F-4DED-49B7-BDD3-FABE28661211}")

'//
'// GUID_DEVINTERFACE_WPD_SERVICE
'//   This GUID is used to identify services that support the WPD Services DDI.
'//   The WPD Class Extension component enables this device interface for WPD Services that use it. Clients use this PnP interface when registering for PnP device arrival messages for ALL WPD services.
'//   To register for specific categories of services, client should use the service category or service implements GUID.
$GUID_DEVINTERFACE_WPD_SERVICE = GUID$("{9EF44F80-3D64-4246-A6AA-206F328D1EDC}")

'/****************************************************************************
'* This section declares WPD defines
'****************************************************************************/
'// WPD specific function number used to construct WPD I/O control codes. Drivers should not use this define directly.
'//
%WPD_CONTROL_FUNCTION_GENERIC_MESSAGE = &H42

'// Defines WPD specific IOCTL number used by drivers to detect WPD requests that may require READ and WRITE access to the device.
'//
MACRO IOCTL_WPD_MESSAGE_READWRITE_ACCESS = CTL_CODE(%FILE_DEVICE_WPD, %WPD_CONTROL_FUNCTION_GENERIC_MESSAGE, %METHOD_BUFFERED, (%FILE_READ_ACCESS OR %FILE_WRITE_ACCESS))

'// Defines WPD specific IOCTL number used by drivers to detect WPD requests that require READ-only access to the device.
'//
MACRO IOCTL_WPD_MESSAGE_READ_ACCESS = CTL_CODE(%FILE_DEVICE_WPD, %WPD_CONTROL_FUNCTION_GENERIC_MESSAGE, %METHOD_BUFFERED, %FILE_READ_ACCESS)

'// Drivers can use this macro to detect whether the incoming IOCTL is a WPD message or not.
'//
MACRO IS_WPD_IOCTL(ControlCode) = ((ControlCode = %IOCTL_WPD_MESSAGE_READWRITE_ACCESS) OR (ControlCode = %IOCTL_WPD_MESSAGE_READ_ACCESS))

'// Pre-defined ObjectID for the DEVICE object.
'//
$$WPD_DEVICE_OBJECT_ID = "DEVICE"$$

'// Pre-defined IWMDMDevice for the IWMDRMDeviceApp license/metering APIs.
'//
%WMDRMDEVICEAPP_USE_WPD_DEVICE_PTR = &HFFFFFFFF???   ' ((ULONG_PTR)-1)

'// Pre-defined name of a REG_DWORD value that defines the device type, used for representation purposes only. Functional characteristics of the device are decided through functional objects.
'// This value can be retrieved using IPortableDeviceManager::GetDeviceProperty(...). See WPD_DEVICE_TYPES enumeration for possible values.
$$PORTABLE_DEVICE_TYPE = "PortableDeviceType"$$

'// Pre-defined name of a REG_SZ/REG_EXPAND_SZ/REG_MULTI_SZ value that indicates the location of the device icon file or device icon resource.
'// This value can be retrieved using IPortableDeviceManager::GetDeviceProperty(...). This REG_SZ/REG_EXPAND_SZ/REG_MULTI_SZ value is either in the form "file.dll, resourceID" or a full file path to an icon file. e.g.: "x:\file.ico"
$$PORTABLE_DEVICE_ICON = "Icons"$$

'// Pre-defined name of a REG_DWORD value that indicates the amount of time in milliseconds the WPD Namespace Extension will keep its reference to the device open under idle conditions.
'// This value can be retrieved using IPortableDeviceManager::GetDeviceProperty(...).
$$PORTABLE_DEVICE_NAMESPACE_TIMEOUT = "PortableDeviceNameSpaceTimeout"$$

'// Pre-defined name of a REG_DWORD value that is used as a flag to indicate whether the device should, or should not, be shown in the Explorer view.
'// This value can be retrieved using IPortableDeviceManager::GetDeviceProperty(...). Meaning of values are: 0 = include, 1 = exclude. 0 is assumed if this value doesn't exist.
$$PORTABLE_DEVICE_NAMESPACE_EXCLUDE_FROM_SHELL = "PortableDeviceNameSpaceExcludeFromShell"$$

'// Pre-defined name of a REG_SZ or REG_MULTI_SZ value containing content type guids that are used indicate for what content types the portable device namespace should attempt to automatically generate a thumbnail when placing new content on the device.
'// This value can be retrieved using IPortableDeviceManager::GetDeviceProperty(...). Values should be a string representation of a GUID, in the form '{00000000-0000-0000-0000-000000000000}'. By default the portable device namespace attempts to automatically
'// generate thumbnails for WPD_CONTENT_TYPE_IMAGE, if a device does not want this behavior it can set this value to an empty string.
$$PORTABLE_DEVICE_NAMESPACE_THUMBNAIL_CONTENT_TYPES = "PortableDeviceNameSpaceThumbnailContentTypes"$$

'// Pre-defined name of a REG_DWORD value that indicates whether a Portable Device is a Mass Storage Class (MSC) device. This is used to avoid duplication of the device in certain views and scenarios that include both file system and Portable Devices.
'// This value can be retrieved using IPortableDeviceManager::GetDeviceProperty(...). Meaning of values are: 0 = device is not mass storage, 1 = device is mass storage. 0 is assumed if this value doesn't exist.
$$PORTABLE_DEVICE_IS_MASS_STORAGE = "PortableDeviceIsMassStorage"$$

'// Pre-defined value identifying the "Windows Media Digital Rights Management 10 for Portable Devices" scheme for protecting content.
'// This value can be used by drivers to indicate they support WMDRM10-PD. See WPD_DEVICE_SUPPORTED_DRM_SCHEMES.
$$PORTABLE_DEVICE_DRM_SCHEME_WMDRM10_PD = "WMDRM10-PD"$$

'// Pre-defined value identifying the "Portable Device Digital Rights Management" scheme for protecting content.
'// This value can be used by drivers to indicate they support PDDRM. See WPD_DEVICE_SUPPORTED_DRM_SCHEMES.
$$PORTABLE_DEVICE_DRM_SCHEME_PDDRM = "PDDRM"$$


'/****************************************************************************
'* This section defines flags used in API arguments
'****************************************************************************/

'// Indicates whether the delete request should recursively delete any children.
' enum DELETE_OBJECT_OPTIONS
%PORTABLE_DEVICE_DELETE_NO_RECURSION = 0
%PORTABLE_DEVICE_DELETE_WITH_RECURSION = 1

'// Possible values for PORTABLE_DEVICE_TYPE registry value.
' enum WPD_DEVICE_TYPES
%WPD_DEVICE_TYPE_GENERIC = 0
%WPD_DEVICE_TYPE_CAMERA = 1
%WPD_DEVICE_TYPE_MEDIA_PLAYER = 2
%WPD_DEVICE_TYPE_PHONE = 3
%WPD_DEVICE_TYPE_VIDEO = 4
%WPD_DEVICE_TYPE_PERSONAL_INFORMATION_MANAGER = 5
%WPD_DEVICE_TYPE_AUDIO_RECORDER = 6

'// Possible values for WPD_PROPERTY_ATTRIBUTE_FORM
' enum WpdAttributeForm
%WPD_PROPERTY_ATTRIBUTE_FORM_UNSPECIFIED = 0
%WPD_PROPERTY_ATTRIBUTE_FORM_RANGE = 1
%WPD_PROPERTY_ATTRIBUTE_FORM_ENUMERATION = 2
%WPD_PROPERTY_ATTRIBUTE_FORM_REGULAR_EXPRESSION = 3
%WPD_PROPERTY_ATTRIBUTE_FORM_OBJECT_IDENTIFIER = 4

'// Possible values for WPD_PARAMETER_ATTRIBUTE_FORM
' enum WpdParameterAttributeForm
%WPD_PARAMETER_ATTRIBUTE_FORM_UNSPECIFIED = 0
%WPD_PARAMETER_ATTRIBUTE_FORM_RANGE = 1
%WPD_PARAMETER_ATTRIBUTE_FORM_ENUMERATION = 2
%WPD_PARAMETER_ATTRIBUTE_FORM_REGULAR_EXPRESSION = 3
%WPD_PARAMETER_ATTRIBUTE_FORM_OBJECT_IDENTIFIER = 4

'// Possible values for WPD_DEVICE_TRANSPORT property.
' enum tagWPD_DEVICE_TRANSPORTS
%WPD_DEVICE_TRANSPORT_UNSPECIFIED = 0
%WPD_DEVICE_TRANSPORT_USB = 1
%WPD_DEVICE_TRANSPORT_IP = 2
%WPD_DEVICE_TRANSPORT_BLUETOOTH = 3

'// Indicates the type of storage.
' enum WPD_STORAGE_TYPE_VALUES
%WPD_STORAGE_TYPE_UNDEFINED = 0
%WPD_STORAGE_TYPE_FIXED_ROM = 1
%WPD_STORAGE_TYPE_REMOVABLE_ROM = 2
%WPD_STORAGE_TYPE_FIXED_RAM = 3
%WPD_STORAGE_TYPE_REMOVABLE_RAM = 4

'// Indicates write-protection that globally affects the storage.
' enum WPD_STORAGE_ACCESS_CAPABILITY_VALUES
%WPD_STORAGE_ACCESS_CAPABILITY_READWRITE = 0
%WPD_STORAGE_ACCESS_CAPABILITY_READ_ONLY_WITHOUT_OBJECT_DELETION = 1
%WPD_STORAGE_ACCESS_CAPABILITY_READ_ONLY_WITH_OBJECT_DELETION = 2

'// Possible values for WPD_SMS_ENCODING
' enum WPD_SMS_ENCODING_TYPES
%SMS_ENCODING_7_BIT = 0
%SMS_ENCODING_8_BIT = 1
%SMS_ENCODING_UTF_16 = 2

'// Possible values for WPD_PROPERTY_SMS_MESSAGE_TYPE
' enum SMS_MESSAGE_TYPES
%SMS_TEXT_MESSAGE = 0
%SMS_BINARY_MESSAGE = 1

'// Indicates whether the device is on battery power or external power.
' enum WPD_POWER_SOURCES
%WPD_POWER_SOURCE_BATTERY = 0
%WPD_POWER_SOURCE_EXTERNAL = 1

'// Indicates the way the device weighs color channels.
' enum WPD_WHITE_BALANCE_SETTINGS
%WPD_WHITE_BALANCE_UNDEFINED = 0
%WPD_WHITE_BALANCE_MANUAL = 1
%WPD_WHITE_BALANCE_AUTOMATIC = 2
%WPD_WHITE_BALANCE_ONE_PUSH_AUTOMATIC = 3
%WPD_WHITE_BALANCE_DAYLIGHT = 4
%WPD_WHITE_BALANCE_FLORESCENT = 5
%WPD_WHITE_BALANCE_TUNGSTEN = 6
%WPD_WHITE_BALANCE_FLASH = 7

'// Indicates the focus mode of the device.
' enum WPD_FOCUS_MODES
%WPD_FOCUS_UNDEFINED = 0
%WPD_FOCUS_MANUAL = 1
%WPD_FOCUS_AUTOMATIC = 2
%WPD_FOCUS_AUTOMATIC_MACRO = 3

'// Indicates the metering mode of the device.
' enum WPD_EXPOSURE_METERING_MODES
%WPD_EXPOSURE_METERING_MODE_UNDEFINED = 0
%WPD_EXPOSURE_METERING_MODE_AVERAGE = 1
%WPD_EXPOSURE_METERING_MODE_CENTER_WEIGHTED_AVERAGE = 2
%WPD_EXPOSURE_METERING_MODE_MULTI_SPOT = 3
%WPD_EXPOSURE_METERING_MODE_CENTER_SPOT = 4

'// Indicates the flash mode of the device.
' enum WPD_FLASH_MODES
%WPD_FLASH_MODE_UNDEFINED = 0
%WPD_FLASH_MODE_AUTO = 1
%WPD_FLASH_MODE_OFF = 2
%WPD_FLASH_MODE_FILL = 3
%WPD_FLASH_MODE_RED_EYE_AUTO = 4
%WPD_FLASH_MODE_RED_EYE_FILL = 5
%WPD_FLASH_MODE_EXTERNAL_SYNC = 6

'// Indicates the exposure program mode of the device.
' enum WPD_EXPOSURE_PROGRAM_MODES
%WPD_EXPOSURE_PROGRAM_MODE_UNDEFINED = 0
%WPD_EXPOSURE_PROGRAM_MODE_MANUAL = 1
%WPD_EXPOSURE_PROGRAM_MODE_AUTO = 2
%WPD_EXPOSURE_PROGRAM_MODE_APERTURE_PRIORITY = 3
%WPD_EXPOSURE_PROGRAM_MODE_SHUTTER_PRIORITY = 4
%WPD_EXPOSURE_PROGRAM_MODE_CREATIVE = 5
%WPD_EXPOSURE_PROGRAM_MODE_ACTION = 6
%WPD_EXPOSURE_PROGRAM_MODE_PORTRAIT = 7

'// Indicates the capture mode of the device.
' enum WPD_CAPTURE_MODES
%WPD_CAPTURE_MODE_UNDEFINED = 0
%WPD_CAPTURE_MODE_NORMAL = 1
%WPD_CAPTURE_MODE_BURST = 2
%WPD_CAPTURE_MODE_TIMELAPSE = 3

'// Indicates the effect mode of the capture device.
' enum WPD_EFFECT_MODES
%WPD_EFFECT_MODE_UNDEFINED = 0
%WPD_EFFECT_MODE_COLOR = 1
%WPD_EFFECT_MODE_BLACK_AND_WHITE = 2
%WPD_EFFECT_MODE_SEPIA = 3

'// Indicates the metering mode of the capture device.
' enum WPD_FOCUS_METERING_MODES
%WPD_FOCUS_METERING_MODE_UNDEFINED = 0
%WPD_FOCUS_METERING_MODE_CENTER_SPOT = 1
%WPD_FOCUS_METERING_MODE_MULTI_SPOT = 2

'// Indicates the type of bitrate for the audio/video data.
' enum WPD_BITRATE_TYPES
%WPD_BITRATE_TYPE_UNUSED = 0
%WPD_BITRATE_TYPE_DISCRETE = 1
%WPD_BITRATE_TYPE_VARIABLE = 2
%WPD_BITRATE_TYPE_FREE = 3

'// Qualifies the object data in a contextual way.
' enum WPD_META_GENRES
%WPD_META_GENRE_UNUSED = &H0
%WPD_META_GENRE_GENERIC_MUSIC_AUDIO_FILE = &H1
%WPD_META_GENRE_GENERIC_NON_MUSIC_AUDIO_FILE = &H11
%WPD_META_GENRE_SPOKEN_WORD_AUDIO_BOOK_FILES = &H12
%WPD_META_GENRE_SPOKEN_WORD_FILES_NON_AUDIO_BOOK = &H13
%WPD_META_GENRE_SPOKEN_WORD_NEWS = &H14
%WPD_META_GENRE_SPOKEN_WORD_TALK_SHOWS = &H15
%WPD_META_GENRE_GENERIC_VIDEO_FILE = &H21
%WPD_META_GENRE_NEWS_VIDEO_FILE = &H22
%WPD_META_GENRE_MUSIC_VIDEO_FILE = &H23
%WPD_META_GENRE_HOME_VIDEO_FILE = &H24
%WPD_META_GENRE_FEATURE_FILM_VIDEO_FILE = &H25
%WPD_META_GENRE_TELEVISION_VIDEO_FILE = &H26
%WPD_META_GENRE_TRAINING_EDUCATIONAL_VIDEO_FILE = &H27
%WPD_META_GENRE_PHOTO_MONTAGE_VIDEO_FILE = &H28
%WPD_META_GENRE_GENERIC_NON_AUDIO_NON_VIDEO = &H30
%WPD_META_GENRE_AUDIO_PODCAST = &H40
%WPD_META_GENRE_VIDEO_PODCAST = &H41
%WPD_META_GENRE_MIXED_PODCAST = &H42

'// Indicates the cropped status of an image.
' enum WPD_CROPPED_STATUS_VALUES
%WPD_CROPPED_STATUS_NOT_CROPPED = 0
%WPD_CROPPED_STATUS_CROPPED = 1
%WPD_CROPPED_STATUS_SHOULD_NOT_BE_CROPPED = 2

'// Indicates the color corrected status of an image.
' enum WPD_COLOR_CORRECTED_STATUS_VALUES
%WPD_COLOR_CORRECTED_STATUS_NOT_CORRECTED = 0
%WPD_COLOR_CORRECTED_STATUS_CORRECTED = 1
%WPD_COLOR_CORRECTED_STATUS_SHOULD_NOT_BE_CORRECTED = 2

'// Identifies the video scan-type information.
' enum WPD_VIDEO_SCAN_TYPES
%WPD_VIDEO_SCAN_TYPE_UNUSED = 0
%WPD_VIDEO_SCAN_TYPE_PROGRESSIVE = 1
%WPD_VIDEO_SCAN_TYPE_FIELD_INTERLEAVED_UPPER_FIRST = 2
%WPD_VIDEO_SCAN_TYPE_FIELD_INTERLEAVED_LOWER_FIRST = 3
%WPD_VIDEO_SCAN_TYPE_FIELD_SINGLE_UPPER_FIRST = 4
%WPD_VIDEO_SCAN_TYPE_FIELD_SINGLE_LOWER_FIRST = 5
%WPD_VIDEO_SCAN_TYPE_MIXED_INTERLACE = 6
%WPD_VIDEO_SCAN_TYPE_MIXED_INTERLACE_AND_PROGRESSIVE = 7

'// Indicates the current state of the operation in progress.
' enum WPD_OPERATION_STATES
%WPD_OPERATION_STATE_UNSPECIFIED = 0
%WPD_OPERATION_STATE_STARTED = 1
%WPD_OPERATION_STATE_RUNNING = 2
%WPD_OPERATION_STATE_PAUSED = 3
%WPD_OPERATION_STATE_CANCELLED = 4
%WPD_OPERATION_STATE_FINISHED = 5
%WPD_OPERATION_STATE_ABORTED = 6

'// Indicates the units for a referenced section of data.
' enum WPD_SECTION_DATA_UNITS_VALUES
%WPD_SECTION_DATA_UNITS_BYTES = 0
%WPD_SECTION_DATA_UNITS_MILLISECONDS = 1

'// Indicates whether the rendering information profile entry corresponds to an Object or a Resource.
' enum WPD_RENDERING_INFORMATION_PROFILE_ENTRY_TYPES
%WPD_RENDERING_INFORMATION_PROFILE_ENTRY_TYPE_OBJECT = 0
%WPD_RENDERING_INFORMATION_PROFILE_ENTRY_TYPE_RESOURCE = 1

'// Indicates the type of access the command requires. This is only used internally by the command access lookup table. There is no need to use these values directly.
' enum WPD_COMMAND_ACCESS_TYPES
%WPD_COMMAND_ACCESS_READ = 1
%WPD_COMMAND_ACCESS_READWRITE = 3
%WPD_COMMAND_ACCESS_FROM_PROPERTY_WITH_STGM_ACCESS = 4
%WPD_COMMAND_ACCESS_FROM_PROPERTY_WITH_FILE_ACCESS = 8
%WPD_COMMAND_ACCESS_FROM_ATTRIBUTE_WITH_METHOD_ACCESS = 16

'// Indicates the inheritance relationship to query for this service.
' enum WPD_SERVICE_INHERITANCE_TYPES
%WPD_SERVICE_INHERITANCE_IMPLEMENTATION = 0

'// Indicates the usage of a parameter.
' enum WPD_PARAMETER_USAGE_TYPES
%WPD_PARAMETER_USAGE_RETURN = 0
%WPD_PARAMETER_USAGE_IN = 1
%WPD_PARAMETER_USAGE_OUT = 2
%WPD_PARAMETER_USAGE_INOUT = 3

'/****************************************************************************
'* This section declares WPD specific Errors
'****************************************************************************/
%FACILITY_WPD = 42

'#define E_WPD_DEVICE_ALREADY_OPENED MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 1 ) /* 0x802A0001 */
'#define E_WPD_DEVICE_NOT_OPEN MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 2 ) /* 0x802A0002 */
'#define E_WPD_OBJECT_ALREADY_ATTACHED_TO_DEVICE MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 3 ) /* 0x802A0003 */
'#define E_WPD_OBJECT_NOT_ATTACHED_TO_DEVICE MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 4 ) /* 0x802A0004 */
'#define E_WPD_OBJECT_NOT_COMMITED MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 5 ) /* 0x802A0005 */
'#define E_WPD_DEVICE_IS_HUNG MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 6 ) /* 0x802A0006 */
'#define E_WPD_SMS_INVALID_RECIPIENT MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 100 ) /* 0x802A0064 */
'#define E_WPD_SMS_INVALID_MESSAGE_BODY MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 101 ) /* 0x802A0065 */
'#define E_WPD_SMS_SERVICE_UNAVAILABLE MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 102 ) /* 0x802A0066 */
'#define E_WPD_SERVICE_ALREADY_OPENED MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 200 ) /* 0x802A00C8 */
'#define E_WPD_SERVICE_NOT_OPEN MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 201 ) /* 0x802A00C9 */
'#define E_WPD_OBJECT_ALREADY_ATTACHED_TO_SERVICE MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 202 ) /* 0x802A00CA */
'#define E_WPD_OBJECT_NOT_ATTACHED_TO_SERVICE MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 203 ) /* 0x802A00CB */
'#define E_WPD_SERVICE_BAD_PARAMETER_ORDER MAKE_HRESULT( SEVERITY_ERROR , FACILITY_WPD, 204 ) /* 0x802A00CC */

%E_WPD_DEVICE_ALREADY_OPENED = &H802A0001&
%E_WPD_DEVICE_NOT_OPEN = &H802A0002&
%E_WPD_OBJECT_ALREADY_ATTACHED_TO_DEVICE = &H802A0003&
%E_WPD_OBJECT_NOT_ATTACHED_TO_DEVICE = &H802A0004&
%E_WPD_OBJECT_NOT_COMMITED = &H802A0005&
%E_WPD_DEVICE_IS_HUNG = &H802A0006&
%E_WPD_SMS_INVALID_RECIPIENT = &H802A0064&
%E_WPD_SMS_INVALID_MESSAGE_BODY = &H802A0065&
%E_WPD_SMS_SERVICE_UNAVAILABLE = &H802A0066&
%E_WPD_SERVICE_ALREADY_OPENED = &H802A00C8&
%E_WPD_SERVICE_NOT_OPEN = &H802A00C9&
%E_WPD_OBJECT_ALREADY_ATTACHED_TO_SERVICE = &H802A00CA&
%E_WPD_OBJECT_NOT_ATTACHED_TO_SERVICE = &H802A00CB&
%E_WPD_SERVICE_BAD_PARAMETER_ORDER = &H802A00CC&

'/****************************************************************************
'* This section defines all WPD Events
'****************************************************************************/
'//
'// WPD_EVENT_NOTIFICATION
'//   This GUID is used to identify all WPD driver events to the event sub-system. The driver uses this as the GUID identifier when it queues an event with IWdfDevice::PostEvent(). Applications never use this value.
$WPD_EVENT_NOTIFICATION = GUID$("{2BA2E40A-6B4C-4295-BB43-26322B99AEB2}")

'//
'// WPD_EVENT_OBJECT_ADDED
'//   This event is sent after a new object is available on the device.
$WPD_EVENT_OBJECT_ADDED = GUID$("{A726DA95-E207-4B02-8D44-BEF2E86CBFFC}")

'//
'// WPD_EVENT_OBJECT_REMOVED
'//   This event is sent after a previously existing object has been removed from the device.
$WPD_EVENT_OBJECT_REMOVED = GUID$("{BE82AB88-A52C-4823-96E5-D0272671FC38}")

'//
'// WPD_EVENT_OBJECT_UPDATED
'//   This event is sent after an object has been updated such that any connected client should refresh its view of that object.
$WPD_EVENT_OBJECT_UPDATED = GUID$("{1445A759-2E01-485D-9F27-FF07DAE697AB}")

'//
'// WPD_EVENT_DEVICE_RESET
'//   This event indicates that the device is about to be reset, and all connected clients should close their connection to the device.
$WPD_EVENT_DEVICE_RESET = GUID$("{7755CF53-C1ED-44F3-B5A2-451E2C376B27}")

'//
'// WPD_EVENT_DEVICE_CAPABILITIES_UPDATED
'//   This event indicates that the device capabilities have changed. Clients should re-query the device if they have made any decisions based on device capabilities.
$WPD_EVENT_DEVICE_CAPABILITIES_UPDATED = GUID$("{36885AA1-CD54-4DAA-B3D0-AFB3E03F5999}")

'//
'// WPD_EVENT_STORAGE_FORMAT
'//   This event indicates the progress of a format operation on a storage object.
$WPD_EVENT_STORAGE_FORMAT = GUID$("{3782616B-22BC-4474-A251-3070F8D38857}")

'//
'// WPD_EVENT_OBJECT_TRANSFER_REQUESTED
'//   This event is sent to request an application to transfer a particular object from the device.
$WPD_EVENT_OBJECT_TRANSFER_REQUESTED = GUID$("{8D16A0A1-F2C6-41DA-8F19-5E53721ADBF2}")

'//
'// WPD_EVENT_DEVICE_REMOVED
'//   This event is sent when a driver for a device is being unloaded. This is typically a result of the device being unplugged.
$WPD_EVENT_DEVICE_REMOVED = GUID$("{E4CBCA1B-6918-48B9-85EE-02BE7C850AF9}")

'//
'// WPD_EVENT_SERVICE_METHOD_COMPLETE
'//   This event is sent when a driver has completed invoking a service method. This event must be sent even when the method fails.
$WPD_EVENT_SERVICE_METHOD_COMPLETE = GUID$("{8A33F5F8-0ACC-4D9B-9CC4-112D353B86CA}")

'/****************************************************************************
'* This section defines all WPD content types
'****************************************************************************/
'//
'// WPD_CONTENT_TYPE_FUNCTIONAL_OBJECT
'//   Indicates this object represents a functional object, not content data on the device.
$WPD_CONTENT_TYPE_FUNCTIONAL_OBJECT = GUID$("{99ED0160-17FF-4C44-9D98-1D7A6F941921}")

'//
'// WPD_CONTENT_TYPE_FOLDER
'//   Indicates this object is a folder.
$WPD_CONTENT_TYPE_FOLDER = GUID$("{27E2E392-A111-48E0-AB0C-E17705A05F85}")

'//
'// WPD_CONTENT_TYPE_IMAGE
'//   Indicates this object represents image data (e.g. a JPEG file)
$WPD_CONTENT_TYPE_IMAGE = GUID$("{EF2107D5-A52A-4243-A26B-62D4176D7603}")

'//
'// WPD_CONTENT_TYPE_DOCUMENT
'//   Indicates this object represents document data (e.g. a MS WORD file, TEXT file, etc.)
$WPD_CONTENT_TYPE_DOCUMENT = GUID$("{680ADF52-950A-4041-9B41-65E393648155}")

'//
'// WPD_CONTENT_TYPE_CONTACT
'//   Indicates this object represents contact data (e.g. name/number, or a VCARD file)
$WPD_CONTENT_TYPE_CONTACT = GUID$("{EABA8313-4525-4707-9F0E-87C6808E9435}")

'//
'// WPD_CONTENT_TYPE_CONTACT_GROUP
'//   Indicates this object represents a group of contacts.
$WPD_CONTENT_TYPE_CONTACT_GROUP = GUID$("{346B8932-4C36-40D8-9415-1828291F9DE9}")

'//
'// WPD_CONTENT_TYPE_AUDIO
'//   Indicates this object represents audio data (e.g. a WMA or MP3 file)
$WPD_CONTENT_TYPE_AUDIO = GUID$("{4AD2C85E-5E2D-45E5-8864-4F229E3C6CF0}")

'//
'// WPD_CONTENT_TYPE_VIDEO
'//   Indicates this object represents video data (e.g. a WMV or AVI file)
$WPD_CONTENT_TYPE_VIDEO = GUID$("{9261B03C-3D78-4519-85E3-02C5E1F50BB9}")

'//
'// WPD_CONTENT_TYPE_TELEVISION
'//   Indicates this object represents a television recording.
$WPD_CONTENT_TYPE_TELEVISION = GUID$("{60A169CF-F2AE-4E21-9375-9677F11C1C6E}")

'//
'// WPD_CONTENT_TYPE_PLAYLIST
'//   Indicates this object represents a playlist.
$WPD_CONTENT_TYPE_PLAYLIST = GUID$("{1A33F7E4-AF13-48F5-994E-77369DFE04A3}")

'//
'// WPD_CONTENT_TYPE_MIXED_CONTENT_ALBUM
'//   Indicates this object represents an album, which may contain objects of different content types (typically, MUSIC, IMAGE and VIDEO).
$WPD_CONTENT_TYPE_MIXED_CONTENT_ALBUM = GUID$("{00F0C3AC-A593-49AC-9219-24ABCA5A2563}")

'//
'// WPD_CONTENT_TYPE_AUDIO_ALBUM
'//   Indicates this object represents an audio album.
$WPD_CONTENT_TYPE_AUDIO_ALBUM = GUID$("{AA18737E-5009-48FA-AE21-85F24383B4E6}")

'//
'// WPD_CONTENT_TYPE_IMAGE_ALBUM
'//   Indicates this object represents an image album.
$WPD_CONTENT_TYPE_IMAGE_ALBUM = GUID$("{75793148-15F5-4A30-A813-54ED8A37E226}")

'//
'// WPD_CONTENT_TYPE_VIDEO_ALBUM
'//   Indicates this object represents a video album.
$WPD_CONTENT_TYPE_VIDEO_ALBUM = GUID$("{012B0DB7-D4C1-45D6-B081-94B87779614F}")

'//
'// WPD_CONTENT_TYPE_MEMO
'//   Indicates this object represents memo data
$WPD_CONTENT_TYPE_MEMO = GUID$("{9CD20ECF-3B50-414F-A641-E473FFE45751}")

'//
'// WPD_CONTENT_TYPE_EMAIL
'//   Indicates this object represents e-mail data
$WPD_CONTENT_TYPE_EMAIL = GUID$("{8038044A-7E51-4F8F-883D-1D0623D14533}")

'//
'// WPD_CONTENT_TYPE_APPOINTMENT
'//   Indicates this object represents an appointment in a calendar
$WPD_CONTENT_TYPE_APPOINTMENT = GUID$("{0FED060E-8793-4B1E-90C9-48AC389AC631}")

'//
'// WPD_CONTENT_TYPE_TASK
'//   Indicates this object represents a task for tracking (e.g. a TODO list)
$WPD_CONTENT_TYPE_TASK = GUID$("{63252F2C-887F-4CB6-B1AC-D29855DCEF6C}")

'//
'// WPD_CONTENT_TYPE_PROGRAM
'//   Indicates this object represents a file that can be run. This could be a script, executable and so on.
$WPD_CONTENT_TYPE_PROGRAM = GUID$("{D269F96A-247C-4BFF-98FB-97F3C49220E6}")

'//
'// WPD_CONTENT_TYPE_GENERIC_FILE
'//   Indicates this object represents a file that does not fall into any of the other predefined WPD types for files.
$WPD_CONTENT_TYPE_GENERIC_FILE = GUID$("{0085E0A6-8D34-45D7-BC5C-447E59C73D48}")

'//
'// WPD_CONTENT_TYPE_CALENDAR
'//   Indicates this object represents a calender
$WPD_CONTENT_TYPE_CALENDAR = GUID$("{A1FD5967-6023-49A0-9DF1-F8060BE751B0}")

'//
'// WPD_CONTENT_TYPE_GENERIC_MESSAGE
'//   Indicates this object represents a message (e.g. SMS message, E-Mail message, etc.)
$WPD_CONTENT_TYPE_GENERIC_MESSAGE = GUID$("{E80EAAF8-B2DB-4133-B67E-1BEF4B4A6E5F}")

'//
'// WPD_CONTENT_TYPE_NETWORK_ASSOCIATION
'//   Indicates this object represents an association between a host and a device.
$WPD_CONTENT_TYPE_NETWORK_ASSOCIATION = GUID$("{031DA7EE-18C8-4205-847E-89A11261D0F3}")

'//
'// WPD_CONTENT_TYPE_CERTIFICATE
'//   Indicates this object represents certificate used for authentication.
$WPD_CONTENT_TYPE_CERTIFICATE = GUID$("{DC3876E8-A948-4060-9050-CBD77E8A3D87}")

'//
'// WPD_CONTENT_TYPE_WIRELESS_PROFILE
'//   Indicates this object represents wireless network access information.
$WPD_CONTENT_TYPE_WIRELESS_PROFILE = GUID$("{0BAC070A-9F5F-4DA4-A8F6-3DE44D68FD6C}")

'//
'// WPD_CONTENT_TYPE_MEDIA_CAST
'//   Indicates this object represents a media cast. A media cast object can be though of as a container object that groups related content, similar to how a playlist groups
'//   songs to play. Often, a media cast object is used to group media content originally published online.
$WPD_CONTENT_TYPE_MEDIA_CAST = GUID$("{5E88B3CC-3E65-4E62-BFFF-229495253AB0}")

'//
'// WPD_CONTENT_TYPE_SECTION
'//   Indicates this object describes a section of data contained in another object. The WPD_OBJECT_REFERENCES property indicates which object contains the actual data.
$WPD_CONTENT_TYPE_SECTION = GUID$("{821089F5-1D91-4DC9-BE3C-BBB1B35B18CE}")

'//
'// WPD_CONTENT_TYPE_UNSPECIFIED
'//   Indicates this object doesn't fall into the predefined WPD content types
$WPD_CONTENT_TYPE_UNSPECIFIED = GUID$("{28D8D31E-249C-454E-AABC-34883168E634}")

'//
'// WPD_CONTENT_TYPE_ALL
'//   This content type is only valid as a parameter to API functions and driver commands. It should not be reported as a supported content type by the driver.
$WPD_CONTENT_TYPE_ALL = GUID$("{80E170D2-1055-4A3E-B952-82CC4F8A8689}")

'/****************************************************************************
'* This section defines all WPD Functional Categories
'****************************************************************************/

'#ifndef WPD_SERVICES_STRICT

'//
'// WPD_FUNCTIONAL_CATEGORY_DEVICE
'//   Used for the device object, which is always the top-most object of the device.
$WPD_FUNCTIONAL_CATEGORY_DEVICE = GUID$("{08EA466B-E3A4-4336-A1F3-A44D2B5C438C}")

'//
'// WPD_FUNCTIONAL_CATEGORY_STORAGE
'//   Indicates this object encapsulates storage functionality on the device (e.g. memory cards, internal memory)
$WPD_FUNCTIONAL_CATEGORY_STORAGE = GUID$("{23F05BBC-15DE-4C2A-A55B-A9AF5CE412EF}")

'//
'// WPD_FUNCTIONAL_CATEGORY_STILL_IMAGE_CAPTURE
'//   Indicates this object encapsulates still image capture functionality on the device (e.g. camera or camera attachment)
$WPD_FUNCTIONAL_CATEGORY_STILL_IMAGE_CAPTURE = GUID$("{613CA327-AB93-4900-B4FA-895BB5874B79}")

'//
'// WPD_FUNCTIONAL_CATEGORY_AUDIO_CAPTURE
'//   Indicates this object encapsulates audio capture functionality on the device (e.g. voice recorder or other audio recording component)
$WPD_FUNCTIONAL_CATEGORY_AUDIO_CAPTURE = GUID$("{3F2A1919-C7C2-4A00-855D-F57CF06DEBBB}")

'//
'// WPD_FUNCTIONAL_CATEGORY_VIDEO_CAPTURE
'//   Indicates this object encapsulates video capture functionality on the device (e.g. video recorder or video recording component)
$WPD_FUNCTIONAL_CATEGORY_VIDEO_CAPTURE = GUID$("{E23E5F6B-7243-43AA-8DF1-0EB3D968A918}")

'//
'// WPD_FUNCTIONAL_CATEGORY_SMS
'//   Indicates this object encapsulates SMS sending functionality on the device (not the receiving or saved SMS messages since those are represented as content objects on the device)
$WPD_FUNCTIONAL_CATEGORY_SMS = GUID$("{0044A0B1-C1E9-4AFD-B358-A62C6117C9CF}")

'//
'// WPD_FUNCTIONAL_CATEGORY_RENDERING_INFORMATION
'//   Indicates this object provides information about the rendering characteristics of the device.
$WPD_FUNCTIONAL_CATEGORY_RENDERING_INFORMATION = GUID$("{08600BA4-A7BA-4A01-AB0E-0065D0A356D3}")

'//
'// WPD_FUNCTIONAL_CATEGORY_NETWORK_CONFIGURATION
'//   Indicates this object encapsulates network configuration functionality on the device (e.g. WiFi Profiles, Partnerships).
$WPD_FUNCTIONAL_CATEGORY_NETWORK_CONFIGURATION = GUID$("{48F4DB72-7C6A-4AB0-9E1A-470E3CDBF26A}")

'//
'// WPD_FUNCTIONAL_CATEGORY_ALL
'//   This functional category is only valid as a parameter to API functions and driver commands. It should not be reported as a supported functional category by the driver.
$WPD_FUNCTIONAL_CATEGORY_ALL = GUID$("{2D8A6512-A74C-448E-BA8A-F4AC07C49399}")

'#endif // WPD_SERVICES_STRICT

'/****************************************************************************
'* This section defines all WPD Formats
'****************************************************************************/

'#ifndef WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_FORMAT_PROPERTIES_ONLY
'//   This object has no data stream and is completely specified by properties only.
$WPD_OBJECT_FORMAT_PROPERTIES_ONLY = GUID$("{30010000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_UNSPECIFIED
'//   An undefined object format on the device (e.g. objects that can not be classified by the other defined WPD format codes)
$WPD_OBJECT_FORMAT_UNSPECIFIED = GUID$("{30000000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_SCRIPT
'//   A device model-specific script
$WPD_OBJECT_FORMAT_SCRIPT = GUID$("{30020000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_EXECUTABLE
'//   A device model-specific binary executable
$WPD_OBJECT_FORMAT_EXECUTABLE = GUID$("{30030000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_TEXT
'//   A text file
$WPD_OBJECT_FORMAT_TEXT = GUID$("{30040000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_HTML
'//   A HyperText Markup Language file (text)
$WPD_OBJECT_FORMAT_HTML = GUID$("{30050000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_DPOF
'//   A Digital Print Order File (text)
$WPD_OBJECT_FORMAT_DPOF = GUID$("{30060000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_AIFF
'//   Audio file format
$WPD_OBJECT_FORMAT_AIFF = GUID$("{30070000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_WAVE
'//   Audio file format
$WPD_OBJECT_FORMAT_WAVE = GUID$("{30080000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MP3
'//   Audio file format
$WPD_OBJECT_FORMAT_MP3 = GUID$("{30090000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_AVI
'//   Video file format
$WPD_OBJECT_FORMAT_AVI = GUID$("{300A0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MPEG
'//   Video file format
$WPD_OBJECT_FORMAT_MPEG = GUID$("{300B0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ASF
'//   Video file format (Microsoft Advanced Streaming Format)
$WPD_OBJECT_FORMAT_ASF = GUID$("{300C0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_EXIF
'//   Image file format (Exchangeable File Format), JEIDA standard
$WPD_OBJECT_FORMAT_EXIF = GUID$("{38010000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_TIFFEP
'//   Image file format (Tag Image File Format for Electronic Photography)
$WPD_OBJECT_FORMAT_TIFFEP = GUID$("{38020000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_FLASHPIX
'//   Image file format (Structured Storage Image Format)
$WPD_OBJECT_FORMAT_FLASHPIX = GUID$("{38030000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_BMP
'//   Image file format (Microsoft Windows Bitmap file)
$WPD_OBJECT_FORMAT_BMP = GUID$("{38040000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_CIFF
'//   Image file format (Canon Camera Image File Format)
$WPD_OBJECT_FORMAT_CIFF = GUID$("{38050000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_GIF
'//   Image file format (Graphics Interchange Format)
$WPD_OBJECT_FORMAT_GIF = GUID$("{38070000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_JFIF
'//   Image file format (JPEG Interchange Format)
$WPD_OBJECT_FORMAT_JFIF = GUID$("{38080000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_PCD
'//   Image file format (PhotoCD Image Pac)
$WPD_OBJECT_FORMAT_PCD = GUID$("{38090000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_PICT
'//   Image file format (Quickdraw Image Format)
$WPD_OBJECT_FORMAT_PICT = GUID$("{380A0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_PNG
'//   Image file format (Portable Network Graphics)
$WPD_OBJECT_FORMAT_PNG = GUID$("{380B0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_TIFF
'//   Image file format (Tag Image File Format)
$WPD_OBJECT_FORMAT_TIFF = GUID$("{380D0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_TIFFIT
'//   Image file format (Tag Image File Format for Informational Technology) Graphic Arts
$WPD_OBJECT_FORMAT_TIFFIT = GUID$("{380E0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_JP2
'//   Image file format (JPEG2000 Baseline File Format)
$WPD_OBJECT_FORMAT_JP2 = GUID$("{380F0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_JPX
'//   Image file format (JPEG2000 Extended File Format)
$WPD_OBJECT_FORMAT_JPX = GUID$("{38100000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_WINDOWSIMAGEFORMAT
'//   Image file format
$WPD_OBJECT_FORMAT_WINDOWSIMAGEFORMAT = GUID$("{B8810000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_WMA
'//   Audio file format (Windows Media Audio)
$WPD_OBJECT_FORMAT_WMA = GUID$("{B9010000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_WMV
'//   Video file format (Windows Media Video)
$WPD_OBJECT_FORMAT_WMV = GUID$("{B9810000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_WPLPLAYLIST
'//   Playlist file format
$WPD_OBJECT_FORMAT_WPLPLAYLIST = GUID$("{BA100000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_M3UPLAYLIST
'//   Playlist file format
$WPD_OBJECT_FORMAT_M3UPLAYLIST = GUID$("{BA110000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MPLPLAYLIST
'//   Playlist file format
$WPD_OBJECT_FORMAT_MPLPLAYLIST = GUID$("{BA120000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ASXPLAYLIST
'//   Playlist file format
$WPD_OBJECT_FORMAT_ASXPLAYLIST = GUID$("{BA130000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_PLSPLAYLIST
'//   Playlist file format
$WPD_OBJECT_FORMAT_PLSPLAYLIST = GUID$("{BA140000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ABSTRACT_CONTACT_GROUP
'//   Generic format for contact group objects
$WPD_OBJECT_FORMAT_ABSTRACT_CONTACT_GROUP = GUID$("{BA060000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ABSTRACT_MEDIA_CAST
'//   MediaCast file format
$WPD_OBJECT_FORMAT_ABSTRACT_MEDIA_CAST = GUID$("{BA0B0000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_VCALENDAR1
'//   VCALENDAR file format (VCALENDAR Version 1)
$WPD_OBJECT_FORMAT_VCALENDAR1 = GUID$("{BE020000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ICALENDAR
'//   ICALENDAR file format (VCALENDAR Version 2)
$WPD_OBJECT_FORMAT_ICALENDAR = GUID$("{BE030000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ABSTRACT_CONTACT
'//   Abstract contact file format
$WPD_OBJECT_FORMAT_ABSTRACT_CONTACT = GUID$("{BB810000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_VCARD2
'//   VCARD file format (VCARD Version 2)
$WPD_OBJECT_FORMAT_VCARD2 = GUID$("{BB820000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_VCARD3
'//   VCARD file format (VCARD Version 3)
$WPD_OBJECT_FORMAT_VCARD3 = GUID$("{BB830000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_ICON
'//   Standard Windows ICON format
$WPD_OBJECT_FORMAT_ICON = GUID$("{077232ED-102C-4638-9C22-83F142BFC822}")

'//
'// WPD_OBJECT_FORMAT_XML
'//   XML file format.
$WPD_OBJECT_FORMAT_XML = GUID$("{BA820000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_AAC
'//   Audio file format
$WPD_OBJECT_FORMAT_AAC = GUID$("{B9030000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_AUDIBLE
'//   Audio file format
$WPD_OBJECT_FORMAT_AUDIBLE = GUID$("{B9040000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_FLAC
'//   Audio file format
$WPD_OBJECT_FORMAT_FLAC = GUID$("{B9060000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_OGG
'//   Audio file format
$WPD_OBJECT_FORMAT_OGG = GUID$("{B9020000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MP4
'//   Audio or Video file format
$WPD_OBJECT_FORMAT_MP4 = GUID$("{B9820000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_M4A
'//   Audio file format
$WPD_OBJECT_FORMAT_M4A = GUID$("{30ABA7AC-6FFD-4C23-A359-3E9B52F3F1C8}")

'//
'// WPD_OBJECT_FORMAT_MP2
'//   Audio or Video file format
$WPD_OBJECT_FORMAT_MP2 = GUID$("{B9830000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MICROSOFT_WORD
'//   Microsoft Office Word Document file format.
$WPD_OBJECT_FORMAT_MICROSOFT_WORD = GUID$("{BA830000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MHT_COMPILED_HTML
'//   MHT Compiled HTML Document file format.
$WPD_OBJECT_FORMAT_MHT_COMPILED_HTML = GUID$("{BA840000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MICROSOFT_EXCEL
'//   Microsoft Office Excel Document file format.
$WPD_OBJECT_FORMAT_MICROSOFT_EXCEL = GUID$("{BA850000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MICROSOFT_POWERPOINT
'//   Microsoft Office PowerPoint Document file format.
$WPD_OBJECT_FORMAT_MICROSOFT_POWERPOINT = GUID$("{BA860000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_NETWORK_ASSOCIATION
'//   Network Association file format.
$WPD_OBJECT_FORMAT_NETWORK_ASSOCIATION = GUID$("{B1020000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_X509V3CERTIFICATE
'//   X.509 V3 Certificate file format.
$WPD_OBJECT_FORMAT_X509V3CERTIFICATE = GUID$("{B1030000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_MICROSOFT_WFC
'//   Windows Connect Now file format.
$WPD_OBJECT_FORMAT_MICROSOFT_WFC = GUID$("{B1040000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_3GP
'//   Audio or Video file format
$WPD_OBJECT_FORMAT_3GP = GUID$("{B9840000-AE6C-4804-98BA-C57B46965FE7}")

'//
'// WPD_OBJECT_FORMAT_3GPA
'//   Audio file format
$WPD_OBJECT_FORMAT_3GPA = GUID$("{E5172730-F971-41EF-A10B-2271A0019D7A}")

$WPD_OBJECT_FORMAT_VCALENDAR2 = $WPD_OBJECT_FORMAT_ICALENDAR

'#endif // WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_FORMAT_ALL
'//   This format is only valid as a parameter to API functions and driver commands. It should not be reported as a supported format by the driver.
$WPD_OBJECT_FORMAT_ALL = GUID$("{C1F62EB2-4BB3-479C-9CFA-05B5F3A57B22}")


'#ifndef WPD_SERVICES_STRICT
'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_OBJECT_PROPERTIES_V1
'*
'* This category is for all common object properties.
'****************************************************************************/
$WPD_OBJECT_PROPERTIES_V1 = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}")

'//
'// WPD_OBJECT_ID
'//   [ VT_LPWSTR ] Uniquely identifies object on the Portable Device.
MACRO WPD_OBJECT_ID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(2)

'//
'// WPD_OBJECT_PARENT_ID
'//   [ VT_LPWSTR ] Object identifier indicating the parent object.
MACRO WPD_OBJECT_PARENT_ID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(3)

'//
'// WPD_OBJECT_NAME
'//   [ VT_LPWSTR ] The display name for this object.
MACRO WPD_OBJECT_NAME = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(4)

'//
'// WPD_OBJECT_PERSISTENT_UNIQUE_ID
'//   [ VT_LPWSTR ] Uniquely identifies the object on the Portable Device, similar to WPD_OBJECT_ID, but this ID will not change between sessions.
MACRO WPD_OBJECT_PERSISTENT_UNIQUE_ID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(5)

'//
'// WPD_OBJECT_FORMAT
'//   [ VT_CLSID ] Indicates the format of the object's data.
MACRO WPD_OBJECT_FORMAT = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(6)

'#endif // WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_CONTENT_TYPE
'//   [ VT_CLSID ] The abstract type for the object content, indicating the kinds of properties and data that may be supported on the object.
MACRO WPD_OBJECT_CONTENT_TYPE = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(7)

'#ifndef WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_ISHIDDEN
'//   [ VT_BOOL ] Indicates whether the object should be hidden.
MACRO WPD_OBJECT_ISHIDDEN = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(9)

'//
'// WPD_OBJECT_ISSYSTEM
'//   [ VT_BOOL ] Indicates whether the object represents system data.
MACRO WPD_OBJECT_ISSYSTEM = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(10)

'//
'// WPD_OBJECT_SIZE
'//   [ VT_UI8 ] The size of the object data.
MACRO WPD_OBJECT_SIZE = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(11)

'//
'// WPD_OBJECT_ORIGINAL_FILE_NAME
'//   [ VT_LPWSTR ] Contains the name of the file this object represents.
MACRO WPD_OBJECT_ORIGINAL_FILE_NAME = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(12)

'//
'// WPD_OBJECT_NON_CONSUMABLE
'//   [ VT_BOOL ] This property determines whether or not this object is intended to be understood by the device, or whether it has been placed on the device just for storage.
MACRO WPD_OBJECT_NON_CONSUMABLE = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(13)

'#endif // WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_REFERENCES
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_LPWSTR indicating a list of ObjectIDs.
MACRO WPD_OBJECT_REFERENCES = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(14)

'#ifndef WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_KEYWORDS
'//   [ VT_LPWSTR ] String containing a list of keywords associated with this object.
MACRO WPD_OBJECT_KEYWORDS = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(15)

'//
'// WPD_OBJECT_SYNC_ID
'//   [ VT_LPWSTR ] Opaque string set by client to retain state between sessions without retaining a catalogue of connected device content.
MACRO WPD_OBJECT_SYNC_ID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(16)

'//
'// WPD_OBJECT_IS_DRM_PROTECTED
'//   [ VT_BOOL ] Indicates whether the media data is DRM protected.
MACRO WPD_OBJECT_IS_DRM_PROTECTED = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(17)

'//
'// WPD_OBJECT_DATE_CREATED
'//   [ VT_DATE ] Indicates the date and time the object was created on the device.
MACRO WPD_OBJECT_DATE_CREATED = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(18)

'//
'// WPD_OBJECT_DATE_MODIFIED
'//   [ VT_DATE ] Indicates the date and time the object was modified on the device.
MACRO WPD_OBJECT_DATE_MODIFIED = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(19)

'//
'// WPD_OBJECT_DATE_AUTHORED
'//   [ VT_DATE ] Indicates the date and time the object was authored (e.g. for music, this would be the date the music was recorded).
MACRO WPD_OBJECT_DATE_AUTHORED = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(20)

'//
'// WPD_OBJECT_BACK_REFERENCES
'//   [ VT_LPWSTR ] IPortableDevicePropVariantCollection of type VT_LPWSTR indicating a list of ObjectIDs.
MACRO WPD_OBJECT_BACK_REFERENCES = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(21)

'#endif // WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_CONTAINER_FUNCTIONAL_OBJECT_ID
'//   [ VT_LPWSTR ] Indicates the Object ID of the closest functional object ancestor. For example, objects that represent files/folders under a Storage functional object, will have this property set to the object ID of the storage functional object.
MACRO WPD_OBJECT_CONTAINER_FUNCTIONAL_OBJECT_ID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(23)

'#ifndef WPD_SERVICES_STRICT

'//
'// WPD_OBJECT_GENERATE_THUMBNAIL_FROM_RESOURCE
'//   [ VT_BOOL ] Indicates whether the thumbnail for this object should be generated from the default resource.
MACRO WPD_OBJECT_GENERATE_THUMBNAIL_FROM_RESOURCE = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(24)

'//
'// WPD_OBJECT_HINT_LOCATION_DISPLAY_NAME
'//   [ VT_LPWSTR ] If this object appears as a hint location, this property indicates the hint-specific name to display instead of the object name.
MACRO WPD_OBJECT_HINT_LOCATION_DISPLAY_NAME = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(25)

'//
'// WPD_OBJECT_CAN_DELETE
'//   [ VT_BOOL ] Indicates whether the object can be deleted, or not.
MACRO WPD_OBJECT_CAN_DELETE = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(26)

'//
'// WPD_OBJECT_LANGUAGE_LOCALE
'//   [ VT_LPWSTR ] Identifies the language of this object. If multiple languages are contained in this object, it should identify the primary language (if any).
MACRO WPD_OBJECT_LANGUAGE_LOCALE = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(27)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_FOLDER_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all folder objects.
'****************************************************************************/
$WPD_FOLDER_OBJECT_PROPERTIES_V1 = GUID$("{7E9A7ABF-E568-4B34-AA2F-13BB12AB177D}")

'//
'// WPD_FOLDER_CONTENT_TYPES_ALLOWED
'//   [ VT_UNKNOWN ] Indicates the subset of content types that can be created in this folder directly (i.e. children may have different restrictions).
MACRO WPD_FOLDER_CONTENT_TYPES_ALLOWED = GUID$("{7E9A7ABF-E568-4B34-AA2F-13BB12AB177D}") & MKDWD$(2)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_IMAGE_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all image objects.
'****************************************************************************/
$WPD_IMAGE_OBJECT_PROPERTIES_V1 = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}")

'//
'// WPD_IMAGE_BITDEPTH
'//   [ VT_UI4 ] Indicates the bitdepth of an image
MACRO WPD_IMAGE_BITDEPTH = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(3)

'//
'// WPD_IMAGE_CROPPED_STATUS
'//   [ VT_UI4 ] Signals whether the file has been cropped.
MACRO WPD_IMAGE_CROPPED_STATUS = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(4)

'//
'// WPD_IMAGE_COLOR_CORRECTED_STATUS
'//   [ VT_UI4 ] Signals whether the file has been color corrected.
MACRO WPD_IMAGE_COLOR_CORRECTED_STATUS = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(5)

'//
'// WPD_IMAGE_FNUMBER
'//   [ VT_UI4 ] Identifies the aperture setting of the lens when this image was captured.
MACRO WPD_IMAGE_FNUMBER = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(6)

'//
'// WPD_IMAGE_EXPOSURE_TIME
'//   [ VT_UI4 ] Identifies the shutter speed of the device when this image was captured.
MACRO WPD_IMAGE_EXPOSURE_TIME = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(7)

'//
'// WPD_IMAGE_EXPOSURE_INDEX
'//   [ VT_UI4 ] Identifies the emulation of film speed settings when this image was captured.
MACRO WPD_IMAGE_EXPOSURE_INDEX = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(8)

'//
'// WPD_IMAGE_HORIZONTAL_RESOLUTION
'//   [ VT_R8 ] Indicates the horizontal resolution (DPI) of an image
MACRO WPD_IMAGE_HORIZONTAL_RESOLUTION = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(9)

'//
'// WPD_IMAGE_VERTICAL_RESOLUTION
'//   [ VT_R8 ] Indicates the vertical resolution (DPI) of an image
MACRO WPD_IMAGE_VERTICAL_RESOLUTION = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(10)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_DOCUMENT_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all document objects.
'****************************************************************************/
$WPD_DOCUMENT_OBJECT_PROPERTIES_V1 = GUID$("{0B110203-EB95-4F02-93E0-97C631493AD5}")


'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_MEDIA_PROPERTIES_V1
'*
'* This category is for properties common to media objects (e.g. audio and video).
'****************************************************************************/
$WPD_MEDIA_PROPERTIES_V1 = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}")

'//
'// WPD_MEDIA_TOTAL_BITRATE
'//   [ VT_UI4 ] The total number of bits that one second will consume.
MACRO WPD_MEDIA_TOTAL_BITRATE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(2)

'//
'// WPD_MEDIA_BITRATE_TYPE
'//   [ VT_UI4 ] Further qualifies the bitrate of audio or video data.
MACRO WPD_MEDIA_BITRATE_TYPE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(3)

'//
'// WPD_MEDIA_COPYRIGHT
'//   [ VT_LPWSTR ] Indicates the copyright information.
MACRO WPD_MEDIA_COPYRIGHT = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(4)

'//
'// WPD_MEDIA_SUBSCRIPTION_CONTENT_ID
'//   [ VT_LPWSTR ] Provides additional information to identify a piece of content relative to an online subscription service.
MACRO WPD_MEDIA_SUBSCRIPTION_CONTENT_ID = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(5)

'//
'// WPD_MEDIA_USE_COUNT
'//   [ VT_UI4 ] Indicates the total number of times this media has been played or viewed on the device.
MACRO WPD_MEDIA_USE_COUNT = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(6)

'//
'// WPD_MEDIA_SKIP_COUNT
'//   [ VT_UI4 ] Indicates the total number of times this media was setup to be played or viewed but was manually skipped by the user.
MACRO WPD_MEDIA_SKIP_COUNT = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(7)

'//
'// WPD_MEDIA_LAST_ACCESSED_TIME
'//   [ VT_DATE ] Indicates the date and time the media was last accessed on the device.
MACRO WPD_MEDIA_LAST_ACCESSED_TIME = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(8)

'//
'// WPD_MEDIA_PARENTAL_RATING
'//   [ VT_LPWSTR ] Indicates the parental rating of the media file.
MACRO WPD_MEDIA_PARENTAL_RATING = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(9)

'//
'// WPD_MEDIA_META_GENRE
'//   [ VT_UI4 ] Further qualifies a piece of media in a contextual way.
MACRO WPD_MEDIA_META_GENRE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(10)

'//
'// WPD_MEDIA_COMPOSER
'//   [ VT_LPWSTR ] Identifies the composer when the composer is not the artist who performed it.
MACRO WPD_MEDIA_COMPOSER = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(11)

'//
'// WPD_MEDIA_EFFECTIVE_RATING
'//   [ VT_UI4 ] Contains an assigned rating for media not set by the user, but is generated based upon usage statistics.
MACRO WPD_MEDIA_EFFECTIVE_RATING = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(12)

'//
'// WPD_MEDIA_SUB_TITLE
'//   [ VT_LPWSTR ] Further qualifies the title when the title is ambiguous or general.
MACRO WPD_MEDIA_SUB_TITLE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(13)

'//
'// WPD_MEDIA_RELEASE_DATE
'//   [ VT_DATE ] Indicates when the media was released.
MACRO WPD_MEDIA_RELEASE_DATE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(14)

'//
'// WPD_MEDIA_SAMPLE_RATE
'//   [ VT_UI4 ] Indicates the number of times media selection was sampled per second during encoding.
MACRO WPD_MEDIA_SAMPLE_RATE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(15)

'//
'// WPD_MEDIA_STAR_RATING
'//   [ VT_UI4 ] Indicates the star rating for this media.
MACRO WPD_MEDIA_STAR_RATING = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(16)

'//
'// WPD_MEDIA_USER_EFFECTIVE_RATING
'//   [ VT_UI4 ] Indicates the rating for this media.
MACRO WPD_MEDIA_USER_EFFECTIVE_RATING = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(17)

'//
'// WPD_MEDIA_TITLE
'//   [ VT_LPWSTR ] Indicates the title of this media.
MACRO WPD_MEDIA_TITLE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(18)

'//
'// WPD_MEDIA_DURATION
'//   [ VT_UI8 ] Indicates the duration of this media in milliseconds.
MACRO WPD_MEDIA_DURATION = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(19)

'//
'// WPD_MEDIA_BUY_NOW
'//   [ VT_BOOL ] TBD
MACRO WPD_MEDIA_BUY_NOW = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(20)

'//
'// WPD_MEDIA_ENCODING_PROFILE
'//   [ VT_LPWSTR ] Media codecs may be encoded in accordance with a profile, which defines a particular encoding algorithm or optimization process.
MACRO WPD_MEDIA_ENCODING_PROFILE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(21)

'//
'// WPD_MEDIA_WIDTH
'//   [ VT_UI4 ] Indicates the width of an object in pixels
MACRO WPD_MEDIA_WIDTH = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(22)

'//
'// WPD_MEDIA_HEIGHT
'//   [ VT_UI4 ] Indicates the height of an object in pixels
MACRO WPD_MEDIA_HEIGHT = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(23)

'//
'// WPD_MEDIA_ARTIST
'//   [ VT_LPWSTR ] Indicates the artist for this media.
MACRO WPD_MEDIA_ARTIST = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(24)

'//
'// WPD_MEDIA_ALBUM_ARTIST
'//   [ VT_LPWSTR ] Indicates the artist of the entire album rather than for a particular track.
MACRO WPD_MEDIA_ALBUM_ARTIST = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(25)

'//
'// WPD_MEDIA_OWNER
'//   [ VT_LPWSTR ] Indicates the e-mail address of the owner for this media.
MACRO WPD_MEDIA_OWNER = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(26)

'//
'// WPD_MEDIA_MANAGING_EDITOR
'//   [ VT_LPWSTR ] Indicates the e-mail address of the managing editor for this media.
MACRO WPD_MEDIA_MANAGING_EDITOR = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(27)

'//
'// WPD_MEDIA_WEBMASTER
'//   [ VT_LPWSTR ] Indicates the e-mail address of the Webmaster for this media.
MACRO WPD_MEDIA_WEBMASTER = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(28)

'//
'// WPD_MEDIA_SOURCE_URL
'//   [ VT_LPWSTR ] Identifies the source URL for this object.
MACRO WPD_MEDIA_SOURCE_URL = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(29)

'//
'// WPD_MEDIA_DESTINATION_URL
'//   [ VT_LPWSTR ] Identifies the URL that an object is linked to if a user clicks on it.
MACRO WPD_MEDIA_DESTINATION_URL = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(30)

'//
'// WPD_MEDIA_DESCRIPTION
'//   [ VT_LPWSTR ] Contains a description of the media content for this object.
MACRO WPD_MEDIA_DESCRIPTION = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(31)

'//
'// WPD_MEDIA_GENRE
'//   [ VT_LPWSTR ] A text field indicating the genre this media belongs to.
MACRO WPD_MEDIA_GENRE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(32)

'//
'// WPD_MEDIA_TIME_BOOKMARK
'//   [ VT_UI8 ] Indicates a bookmark (in milliseconds) of the last position played or viewed on media that have duration.
MACRO WPD_MEDIA_TIME_BOOKMARK = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(33)

'//
'// WPD_MEDIA_OBJECT_BOOKMARK
'//   [ VT_LPWSTR ] Indicates a WPD_OBJECT_ID of the last object viewed or played for those objects that refer to a list of objects (such as playlists or media casts).
MACRO WPD_MEDIA_OBJECT_BOOKMARK = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(34)

'//
'// WPD_MEDIA_LAST_BUILD_DATE
'//   [ VT_DATE ] Indicates the last time a series in a media cast was changed or edited.
MACRO WPD_MEDIA_LAST_BUILD_DATE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(35)

'//
'// WPD_MEDIA_BYTE_BOOKMARK
'//   [ VT_UI8 ] Indicates a bookmark (as a zero-based byte offset) of the last position played or viewed on this media object.
MACRO WPD_MEDIA_BYTE_BOOKMARK = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(36)

'//
'// WPD_MEDIA_TIME_TO_LIVE
'//   [ VT_UI8 ] It is the number of minutes that indicates how long a channel can be cached before refreshing from the source. Applies to WPD_CONTENT_TYPE_MEDIA_CAST objects.
MACRO WPD_MEDIA_TIME_TO_LIVE = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(37)

'//
'// WPD_MEDIA_GUID
'//   [ VT_LPWSTR ] A text field indicating the GUID of this media.
MACRO WPD_MEDIA_GUID = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(38)

'//
'// WPD_MEDIA_SUB_DESCRIPTION
'//   [ VT_LPWSTR ] Contains a sub description of the media content for this object.
MACRO WPD_MEDIA_SUB_DESCRIPTION = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(39)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CONTACT_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all contact objects.
'****************************************************************************/
$WPD_CONTACT_OBJECT_PROPERTIES_V1 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}")

'//
'// WPD_CONTACT_DISPLAY_NAME
'//   [ VT_LPWSTR ] Indicates the display name of the contact (e.g "John Doe")
MACRO WPD_CONTACT_DISPLAY_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(2)

'//
'// WPD_CONTACT_FIRST_NAME
'//   [ VT_LPWSTR ] Indicates the first name of the contact (e.g. "John")
MACRO WPD_CONTACT_FIRST_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(3)

'//
'// WPD_CONTACT_MIDDLE_NAMES
'//   [ VT_LPWSTR ] Indicates the middle name of the contact
MACRO WPD_CONTACT_MIDDLE_NAMES = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(4)

'//
'// WPD_CONTACT_LAST_NAME
'//   [ VT_LPWSTR ] Indicates the last name of the contact (e.g. "Doe")
MACRO WPD_CONTACT_LAST_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(5)

'//
'// WPD_CONTACT_PREFIX
'//   [ VT_LPWSTR ] Indicates the prefix of the name of the contact (e.g. "Mr.")
MACRO WPD_CONTACT_PREFIX = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(6)

'//
'// WPD_CONTACT_SUFFIX
'//   [ VT_LPWSTR ] Indicates the suffix of the name of the contact (e.g. "Jr.")
MACRO WPD_CONTACT_SUFFIX = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(7)

'//
'// WPD_CONTACT_PHONETIC_FIRST_NAME
'//   [ VT_LPWSTR ] The phonetic guide for pronouncing the contact's first name.
MACRO WPD_CONTACT_PHONETIC_FIRST_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(8)

'//
'// WPD_CONTACT_PHONETIC_LAST_NAME
'//   [ VT_LPWSTR ] The phonetic guide for pronouncing the contact's last name.
MACRO WPD_CONTACT_PHONETIC_LAST_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(9)

'//
'// WPD_CONTACT_PERSONAL_FULL_POSTAL_ADDRESS
'//   [ VT_LPWSTR ] Indicates the full postal address of the contact (e.g. "555 Dial Drive, PhoneLand, WA 12345")
MACRO WPD_CONTACT_PERSONAL_FULL_POSTAL_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(10)

'//
'// WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_LINE1
'//   [ VT_LPWSTR ] Indicates the first line of a postal address of the contact (e.g. "555 Dial Drive")
MACRO WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_LINE1 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(11)

'//
'// WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_LINE2
'//   [ VT_LPWSTR ] Indicates the second line of a postal address of the contact
MACRO WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_LINE2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(12)

'//
'// WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_CITY
'//   [ VT_LPWSTR ] Indicates the city of a postal address of the contact (e.g. "PhoneLand")
MACRO WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_CITY = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(13)

'//
'// WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_REGION
'//   [ VT_LPWSTR ] Indicates the region of a postal address of the contact
MACRO WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_REGION = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(14)

'//
'// WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_POSTAL_CODE
'//   [ VT_LPWSTR ] Indicates the postal code of the address.
MACRO WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_POSTAL_CODE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(15)

'//
'// WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_COUNTRY
'//   [ VT_LPWSTR ]
MACRO WPD_CONTACT_PERSONAL_POSTAL_ADDRESS_COUNTRY = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(16)

'//
'// WPD_CONTACT_BUSINESS_FULL_POSTAL_ADDRESS
'//   [ VT_LPWSTR ] Indicates the full postal address of the contact (e.g. "555 Dial Drive, PhoneLand, WA 12345")
MACRO WPD_CONTACT_BUSINESS_FULL_POSTAL_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(17)

'//
'// WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_LINE1
'//   [ VT_LPWSTR ] Indicates the first line of a postal address of the contact (e.g. "555 Dial Drive")
MACRO WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_LINE1 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(18)

'//
'// WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_LINE2
'//   [ VT_LPWSTR ] Indicates the second line of a postal address of the contact
MACRO WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_LINE2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(19)

'//
'// WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_CITY
'//   [ VT_LPWSTR ] Indicates the city of a postal address of the contact (e.g. "PhoneLand")
MACRO WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_CITY = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(20)

'//
'// WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_REGION
'//   [ VT_LPWSTR ] Indicates the region of a postal address of the contact
MACRO WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_REGION = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(21)

'//
'// WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_POSTAL_CODE
'//   [ VT_LPWSTR ] Indicates the postal code of the address.
MACRO WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_POSTAL_CODE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(22)

'//
'// WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_COUNTRY
'//   [ VT_LPWSTR ]
MACRO WPD_CONTACT_BUSINESS_POSTAL_ADDRESS_COUNTRY = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(23)

'//
'// WPD_CONTACT_OTHER_FULL_POSTAL_ADDRESS
'//   [ VT_LPWSTR ] Indicates the full postal address of the contact (e.g. "555 Dial Drive, PhoneLand, WA 12345").
MACRO WPD_CONTACT_OTHER_FULL_POSTAL_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(24)

'//
'// WPD_CONTACT_OTHER_POSTAL_ADDRESS_LINE1
'//   [ VT_LPWSTR ] Indicates the first line of a postal address of the contact (e.g. "555 Dial Drive").
MACRO WPD_CONTACT_OTHER_POSTAL_ADDRESS_LINE1 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(25)

'//
'// WPD_CONTACT_OTHER_POSTAL_ADDRESS_LINE2
'//   [ VT_LPWSTR ] Indicates the second line of a postal address of the contact.
MACRO WPD_CONTACT_OTHER_POSTAL_ADDRESS_LINE2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(26)

'//
'// WPD_CONTACT_OTHER_POSTAL_ADDRESS_CITY
'//   [ VT_LPWSTR ] Indicates the city of a postal address of the contact (e.g. "PhoneLand").
MACRO WPD_CONTACT_OTHER_POSTAL_ADDRESS_CITY = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(27)

'//
'// WPD_CONTACT_OTHER_POSTAL_ADDRESS_REGION
'//   [ VT_LPWSTR ] Indicates the region of a postal address of the contact.
MACRO WPD_CONTACT_OTHER_POSTAL_ADDRESS_REGION = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(28)

'//
'// WPD_CONTACT_OTHER_POSTAL_ADDRESS_POSTAL_CODE
'//   [ VT_LPWSTR ] Indicates the postal code of the address.
MACRO WPD_CONTACT_OTHER_POSTAL_ADDRESS_POSTAL_CODE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(29)

'//
'// WPD_CONTACT_OTHER_POSTAL_ADDRESS_POSTAL_COUNTRY
'//   [ VT_LPWSTR ] Indicates the country of the postal address.
MACRO WPD_CONTACT_OTHER_POSTAL_ADDRESS_POSTAL_COUNTRY = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(30)

'//
'// WPD_CONTACT_PRIMARY_EMAIL_ADDRESS
'//   [ VT_LPWSTR ] Indicates the primary email address for the contact e.g. "JohnDoe@PhoneWorld.com"
MACRO WPD_CONTACT_PRIMARY_EMAIL_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(31)

'//
'// WPD_CONTACT_PERSONAL_EMAIL
'//   [ VT_LPWSTR ] Indicates the personal email address for the contact e.g. "JohnDoe@PhoneWorld.com"
MACRO WPD_CONTACT_PERSONAL_EMAIL = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(32)

'//
'// WPD_CONTACT_PERSONAL_EMAIL2
'//   [ VT_LPWSTR ] Indicates an alternate personal email address for the contact e.g. "JohnDoe@PhoneWorld.com"
MACRO WPD_CONTACT_PERSONAL_EMAIL2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(33)

'//
'// WPD_CONTACT_BUSINESS_EMAIL
'//   [ VT_LPWSTR ] Indicates the business email address for the contact e.g. "JohnDoe@PhoneCompany.com"
MACRO WPD_CONTACT_BUSINESS_EMAIL = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(34)

'//
'// WPD_CONTACT_BUSINESS_EMAIL2
'//   [ VT_LPWSTR ] Indicates an alternate business email address for the contact e.g. "JohnDoe@PhoneCompany.com"
MACRO WPD_CONTACT_BUSINESS_EMAIL2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(35)

'//
'// WPD_CONTACT_OTHER_EMAILS
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection of type VT_LPWSTR, where each element is an alternate email addresses for the contact.
MACRO WPD_CONTACT_OTHER_EMAILS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(36)

'//
'// WPD_CONTACT_PRIMARY_PHONE
'//   [ VT_LPWSTR ] Indicates the primary phone number for the contact.
MACRO WPD_CONTACT_PRIMARY_PHONE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(37)

'//
'// WPD_CONTACT_PERSONAL_PHONE
'//   [ VT_LPWSTR ] Indicates the personal phone number for the contact.
MACRO WPD_CONTACT_PERSONAL_PHONE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(38)

'//
'// WPD_CONTACT_PERSONAL_PHONE2
'//   [ VT_LPWSTR ] Indicates an alternate personal phone number for the contact.
MACRO WPD_CONTACT_PERSONAL_PHONE2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(39)

'//
'// WPD_CONTACT_BUSINESS_PHONE
'//   [ VT_LPWSTR ] Indicates the business phone number for the contact.
MACRO WPD_CONTACT_BUSINESS_PHONE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(40)

'//
'// WPD_CONTACT_BUSINESS_PHONE2
'//   [ VT_LPWSTR ] Indicates an alternate business phone number for the contact.
MACRO WPD_CONTACT_BUSINESS_PHONE2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(41)

'//
'// WPD_CONTACT_MOBILE_PHONE
'//   [ VT_LPWSTR ] Indicates the mobile phone number for the contact.
MACRO WPD_CONTACT_MOBILE_PHONE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(42)

'//
'// WPD_CONTACT_MOBILE_PHONE2
'//   [ VT_LPWSTR ] Indicates an alternate mobile phone number for the contact.
MACRO WPD_CONTACT_MOBILE_PHONE2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(43)

'//
'// WPD_CONTACT_PERSONAL_FAX
'//   [ VT_LPWSTR ] Indicates the personal fax number for the contact.
MACRO WPD_CONTACT_PERSONAL_FAX = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(44)

'//
'// WPD_CONTACT_BUSINESS_FAX
'//   [ VT_LPWSTR ] Indicates the business fax number for the contact.
MACRO WPD_CONTACT_BUSINESS_FAX = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(45)

'//
'// WPD_CONTACT_PAGER
'//   [ VT_LPWSTR ] Indicates the pager number for the contact.
MACRO WPD_CONTACT_PAGER = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(46)

'//
'// WPD_CONTACT_OTHER_PHONES
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection of type VT_LPWSTR, where each element is an alternate phone number for the contact.
MACRO WPD_CONTACT_OTHER_PHONES = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(47)

'//
'// WPD_CONTACT_PRIMARY_WEB_ADDRESS
'//   [ VT_LPWSTR ] Indicates the primary web address for the contact.
MACRO WPD_CONTACT_PRIMARY_WEB_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(48)

'//
'// WPD_CONTACT_PERSONAL_WEB_ADDRESS
'//   [ VT_LPWSTR ] Indicates the personal web address for the contact.
MACRO WPD_CONTACT_PERSONAL_WEB_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(49)

'//
'// WPD_CONTACT_BUSINESS_WEB_ADDRESS
'//   [ VT_LPWSTR ] Indicates the business web address for the contact.
MACRO WPD_CONTACT_BUSINESS_WEB_ADDRESS = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(50)

'//
'// WPD_CONTACT_INSTANT_MESSENGER
'//   [ VT_LPWSTR ] Indicates the instant messenger address for the contact.
MACRO WPD_CONTACT_INSTANT_MESSENGER = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(51)

'//
'// WPD_CONTACT_INSTANT_MESSENGER2
'//   [ VT_LPWSTR ] Indicates an alternate instant messenger address for the contact.
MACRO WPD_CONTACT_INSTANT_MESSENGER2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(52)

'//
'// WPD_CONTACT_INSTANT_MESSENGER3
'//   [ VT_LPWSTR ] Indicates an alternate instant messenger address for the contact.
MACRO WPD_CONTACT_INSTANT_MESSENGER3 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(53)

'//
'// WPD_CONTACT_COMPANY_NAME
'//   [ VT_LPWSTR ] Indicates the company name for the contact.
MACRO WPD_CONTACT_COMPANY_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(54)

'//
'// WPD_CONTACT_PHONETIC_COMPANY_NAME
'//   [ VT_LPWSTR ] The phonetic guide for pronouncing the contact's company name.
MACRO WPD_CONTACT_PHONETIC_COMPANY_NAME = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(55)

'//
'// WPD_CONTACT_ROLE
'//   [ VT_LPWSTR ] Indicates the role for the contact e.g. "Software Engineer".
MACRO WPD_CONTACT_ROLE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(56)

'//
'// WPD_CONTACT_BIRTHDATE
'//   [ VT_DATE ] Indicates the birthdate for the contact.
MACRO WPD_CONTACT_BIRTHDATE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(57)

'//
'// WPD_CONTACT_PRIMARY_FAX
'//   [ VT_LPWSTR ] Indicates the primary fax number for the contact.
MACRO WPD_CONTACT_PRIMARY_FAX = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(58)

'//
'// WPD_CONTACT_SPOUSE
'//   [ VT_LPWSTR ] Indicates the full name of the spouse for the contact.
MACRO WPD_CONTACT_SPOUSE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(59)

'//
'// WPD_CONTACT_CHILDREN
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection of type VT_LPWSTR, where each element is the full name of a child of the contact.
MACRO WPD_CONTACT_CHILDREN = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(60)

'//
'// WPD_CONTACT_ASSISTANT
'//   [ VT_LPWSTR ] Indicates the full name of the assistant for the contact.
MACRO WPD_CONTACT_ASSISTANT = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(61)

'//
'// WPD_CONTACT_ANNIVERSARY_DATE
'//   [ VT_DATE ] Indicates the anniversary date for the contact.
MACRO WPD_CONTACT_ANNIVERSARY_DATE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(62)

'//
'// WPD_CONTACT_RINGTONE
'//   [ VT_LPWSTR ] Indicates an object id of a ringtone file on the device.
MACRO WPD_CONTACT_RINGTONE = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(63)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_MUSIC_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all music objects.
'****************************************************************************/
$WPD_MUSIC_OBJECT_PROPERTIES_V1 = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}")

'//
'// WPD_MUSIC_ALBUM
'//   [ VT_LPWSTR ] Indicates the album of the music file.
MACRO WPD_MUSIC_ALBUM = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(3)

'//
'// WPD_MUSIC_TRACK
'//   [ VT_UI4 ] Indicates the track number for the music file.
MACRO WPD_MUSIC_TRACK = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(4)

'//
'// WPD_MUSIC_LYRICS
'//   [ VT_LPWSTR ] Indicates the lyrics for the music file.
MACRO WPD_MUSIC_LYRICS = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(6)

'//
'// WPD_MUSIC_MOOD
'//   [ VT_LPWSTR ] Indicates the mood for the music file.
MACRO WPD_MUSIC_MOOD = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(8)

'//
'// WPD_AUDIO_BITRATE
'//   [ VT_UI4 ] Indicates the bit rate for the audio data, specified in bits per second.
MACRO WPD_AUDIO_BITRATE = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(9)

'//
'// WPD_AUDIO_CHANNEL_COUNT
'//   [ VT_R4 ] Indicates the number of channels in this audio file e.g. 1, 2, 5.1 etc.
MACRO WPD_AUDIO_CHANNEL_COUNT = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(10)

'//
'// WPD_AUDIO_FORMAT_CODE
'//   [ VT_UI4 ] Indicates the registered WAVE format code.
MACRO WPD_AUDIO_FORMAT_CODE = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(11)

'//
'// WPD_AUDIO_BIT_DEPTH
'//   [ VT_UI4 ] This property identifies the bit-depth of the audio.
MACRO WPD_AUDIO_BIT_DEPTH = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(12)

'//
'// WPD_AUDIO_BLOCK_ALIGNMENT
'//   [ VT_UI4 ] TBD
MACRO WPD_AUDIO_BLOCK_ALIGNMENT = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(13)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_VIDEO_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all video objects.
'****************************************************************************/
$WPD_VIDEO_OBJECT_PROPERTIES_V1 = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}")

'//
'// WPD_VIDEO_AUTHOR
'//   [ VT_LPWSTR ] Indicates the author of the video file.
MACRO WPD_VIDEO_AUTHOR = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(2)

'//
'// WPD_VIDEO_RECORDEDTV_STATION_NAME
'//   [ VT_LPWSTR ] Indicates the TV station the video was recorded from.
MACRO WPD_VIDEO_RECORDEDTV_STATION_NAME = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(4)

'//
'// WPD_VIDEO_RECORDEDTV_CHANNEL_NUMBER
'//   [ VT_UI4 ] Indicates the TV channel number the video was recorded from.
MACRO WPD_VIDEO_RECORDEDTV_CHANNEL_NUMBER = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(5)

'//
'// WPD_VIDEO_RECORDEDTV_REPEAT
'//   [ VT_BOOL ] Indicates whether the recorded TV program was a repeat showing.
MACRO WPD_VIDEO_RECORDEDTV_REPEAT = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(7)

'//
'// WPD_VIDEO_BUFFER_SIZE
'//   [ VT_UI4 ] Indicates the video buffer size.
MACRO WPD_VIDEO_BUFFER_SIZE = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(8)

'//
'// WPD_VIDEO_CREDITS
'//   [ VT_LPWSTR ] Indicates the credit text for the video file.
MACRO WPD_VIDEO_CREDITS = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(9)

'//
'// WPD_VIDEO_KEY_FRAME_DISTANCE
'//   [ VT_UI4 ] Indicates the interval between key frames in milliseconds.
MACRO WPD_VIDEO_KEY_FRAME_DISTANCE = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(10)

'//
'// WPD_VIDEO_QUALITY_SETTING
'//   [ VT_UI4 ] Indicates the quality setting for the video file.
MACRO WPD_VIDEO_QUALITY_SETTING = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(11)

'//
'// WPD_VIDEO_SCAN_TYPE
'//   [ VT_UI4 ] This property identifies the video scan information.
MACRO WPD_VIDEO_SCAN_TYPE = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(12)

'//
'// WPD_VIDEO_BITRATE
'//   [ VT_UI4 ] Indicates the bitrate for the video data.
MACRO WPD_VIDEO_BITRATE = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(13)

'//
'// WPD_VIDEO_FOURCC_CODE
'//   [ VT_DWORD ] The registered FourCC code indicating the codec used for the video file.
MACRO WPD_VIDEO_FOURCC_CODE = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(14)

'//
'// WPD_VIDEO_FRAMERATE
'//   [ VT_UI4 ] Indicates the frame rate for the video data.
MACRO WPD_VIDEO_FRAMERATE = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(15)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_COMMON_INFORMATION_OBJECT_PROPERTIES_V1
'*
'* This category is properties that pertain to informational objects such as appointments, tasks, memos and even documents.
'****************************************************************************/
$WPD_COMMON_INFORMATION_OBJECT_PROPERTIES_V1 = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}")

'//
'// WPD_COMMON_INFORMATION_SUBJECT
'//   [ VT_LPWSTR ] Indicates the subject field of this object.
MACRO WPD_COMMON_INFORMATION_SUBJECT = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(2)

'//
'// WPD_COMMON_INFORMATION_BODY_TEXT
'//   [ VT_LPWSTR ] This property contains the body text of an object, in plaintext or HTML format.
MACRO WPD_COMMON_INFORMATION_BODY_TEXT = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(3)

'//
'// WPD_COMMON_INFORMATION_PRIORITY
'//   [ VT_UI4 ] Indicates the priority of this object.
MACRO WPD_COMMON_INFORMATION_PRIORITY = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(4)

'//
'// WPD_COMMON_INFORMATION_START_DATETIME
'//   [ VT_DATE ] For appointments, tasks and similar objects, this indicates the date/time that this item is scheduled to start.
MACRO WPD_COMMON_INFORMATION_START_DATETIME = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(5)

'//
'// WPD_COMMON_INFORMATION_END_DATETIME
'//   [ VT_DATE ] For appointments, tasks and similar objects, this indicates the date/time that this item is scheduled to end.
MACRO WPD_COMMON_INFORMATION_END_DATETIME = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(6)

'//
'// WPD_COMMON_INFORMATION_NOTES
'//   [ VT_LPWSTR ] For appointments, tasks and similar objects, this indicates any notes for this object.
MACRO WPD_COMMON_INFORMATION_NOTES = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(7)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_MEMO_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all memo objects.
'****************************************************************************/
$WPD_MEMO_OBJECT_PROPERTIES_V1 = GUID$("{5FFBFC7B-7483-41AD-AFB9-DA3F4E592B8D}")

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_EMAIL_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all email objects.
'****************************************************************************/
$WPD_EMAIL_OBJECT_PROPERTIES_V1 = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}")

'//
'// WPD_EMAIL_TO_LINE
'//   [ VT_LPWSTR ] Indicates the normal recipients for the message.
MACRO WPD_EMAIL_TO_LINE = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(2)

'//
'// WPD_EMAIL_CC_LINE
'//   [ VT_LPWSTR ] Indicates the copied recipients for the message.
MACRO WPD_EMAIL_CC_LINE = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(3)

'//
'// WPD_EMAIL_BCC_LINE
'//   [ VT_LPWSTR ] Indicates the recipients for the message who receive a "blind copy".
MACRO WPD_EMAIL_BCC_LINE = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(4)

'//
'// WPD_EMAIL_HAS_BEEN_READ
'//   [ VT_BOOL ] Indicates whether the user has read this message.
MACRO WPD_EMAIL_HAS_BEEN_READ = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(7)

'//
'// WPD_EMAIL_RECEIVED_TIME
'//   [ VT_DATE ] Indicates at what time the message was received.
MACRO WPD_EMAIL_RECEIVED_TIME = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(8)

'//
'// WPD_EMAIL_HAS_ATTACHMENTS
'//   [ VT_BOOL ] Indicates whether this message has attachments.
MACRO WPD_EMAIL_HAS_ATTACHMENTS = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(9)

'//
'// WPD_EMAIL_SENDER_ADDRESS
'//   [ VT_LPWSTR ] Indicates who sent the message.
MACRO WPD_EMAIL_SENDER_ADDRESS = GUID$("{41F8F65A-5484-4782-B13D-4740DD7C37C5}") & MKDWD$(10)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_APPOINTMENT_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all appointment objects.
'****************************************************************************/
$WPD_APPOINTMENT_OBJECT_PROPERTIES_V1 = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}")

'//
'// WPD_APPOINTMENT_LOCATION
'//   [ VT_LPWSTR ] Indicates the location of the appointment e.g. "Building 5, Conf. room 7".
MACRO WPD_APPOINTMENT_LOCATION = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(3)

'//
'// WPD_APPOINTMENT_TYPE
'//   [ VT_LPWSTR ] Indicates the type of appointment e.g. "Personal", "Business" etc.
MACRO WPD_APPOINTMENT_TYPE = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(7)

'//
'// WPD_APPOINTMENT_REQUIRED_ATTENDEES
'//   [ VT_LPWSTR ] Semi-colon separated list of required attendees.
MACRO WPD_APPOINTMENT_REQUIRED_ATTENDEES = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(8)

'//
'// WPD_APPOINTMENT_OPTIONAL_ATTENDEES
'//   [ VT_LPWSTR ] Semi-colon separated list of optional attendees.
MACRO WPD_APPOINTMENT_OPTIONAL_ATTENDEES = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(9)

'//
'// WPD_APPOINTMENT_ACCEPTED_ATTENDEES
'//   [ VT_LPWSTR ] Semi-colon separated list of attendees who have accepted the appointment.
MACRO WPD_APPOINTMENT_ACCEPTED_ATTENDEES = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(10)

'//
'// WPD_APPOINTMENT_RESOURCES
'//   [ VT_LPWSTR ] Semi-colon separated list of resources needed for the appointment.
MACRO WPD_APPOINTMENT_RESOURCES = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(11)

'//
'// WPD_APPOINTMENT_TENTATIVE_ATTENDEES
'//   [ VT_LPWSTR ] Semi-colon separated list of attendees who have tentatively accepted the appointment.
MACRO WPD_APPOINTMENT_TENTATIVE_ATTENDEES = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(12)

'//
'// WPD_APPOINTMENT_DECLINED_ATTENDEES
'//   [ VT_LPWSTR ] Semi-colon separated list of attendees who have declined the appointment.
MACRO WPD_APPOINTMENT_DECLINED_ATTENDEES = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(13)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_TASK_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all task objects.
'****************************************************************************/
$WPD_TASK_OBJECT_PROPERTIES_V1 = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}")

'//
'// WPD_TASK_STATUS
'//   [ VT_LPWSTR ] Indicates the status of the task e.g. "In Progress".
MACRO WPD_TASK_STATUS = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(6)

'//
'// WPD_TASK_PERCENT_COMPLETE
'//   [ VT_UI4 ] Indicates how much of the task has been completed.
MACRO WPD_TASK_PERCENT_COMPLETE = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(8)

'//
'// WPD_TASK_REMINDER_DATE
'//   [ VT_DATE ] Indicates the date and time set for the reminder. If this value is 0, then it is assumed that this task has no reminder.
MACRO WPD_TASK_REMINDER_DATE = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(10)

'//
'// WPD_TASK_OWNER
'//   [ VT_LPWSTR ] Indicates the owner of the task.
MACRO WPD_TASK_OWNER = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(11)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_NETWORK_ASSOCIATION_PROPERTIES_V1
'*
'* This category is for properties common to all network association objects.
'****************************************************************************/
$WPD_NETWORK_ASSOCIATION_PROPERTIES_V1 = GUID$("{E4C93C1F-B203-43F1-A100-5A07D11B0274}")

'//
'// WPD_NETWORK_ASSOCIATION_HOST_NETWORK_IDENTIFIERS
'//   [ VT_VECTOR | VT_UI1 ] The list of EUI-64 host identifiers valid for this association.
MACRO WPD_NETWORK_ASSOCIATION_HOST_NETWORK_IDENTIFIERS = GUID$("{E4C93C1F-B203-43F1-A100-5A07D11B0274}") & MKDWD$(2)

'//
'// WPD_NETWORK_ASSOCIATION_X509V3SEQUENCE
'//   [ VT_VECTOR | VT_UI1 ] The sequence of X.509 v3 certificates to be provided for TLS server authentication.
MACRO WPD_NETWORK_ASSOCIATION_X509V3SEQUENCE = GUID$("{E4C93C1F-B203-43F1-A100-5A07D11B0274}") & MKDWD$(3)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_STILL_IMAGE_CAPTURE_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all objects whose functional category is WPD_FUNCTIONAL_CATEGORY_STILL_IMAGE_CAPTURE
'****************************************************************************/
$WPD_STILL_IMAGE_CAPTURE_OBJECT_PROPERTIES_V1 = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}")

'//
'// WPD_STILL_IMAGE_CAPTURE_RESOLUTION
'//   [ VT_LPWSTR ] Controls the size of the image dimensions to capture in pixel width and height.
MACRO WPD_STILL_IMAGE_CAPTURE_RESOLUTION = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(2)

'//
'// WPD_STILL_IMAGE_CAPTURE_FORMAT
'//   [ VT_CLSID ] Controls the format of the image to capture.
MACRO WPD_STILL_IMAGE_CAPTURE_FORMAT = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(3)

'//
'// WPD_STILL_IMAGE_COMPRESSION_SETTING
'//   [ VT_UI8 ] Controls the device-specific quality setting.
MACRO WPD_STILL_IMAGE_COMPRESSION_SETTING = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(4)

'//
'// WPD_STILL_IMAGE_WHITE_BALANCE
'//   [ VT_UI4 ] Controls how the device weights color channels.
MACRO WPD_STILL_IMAGE_WHITE_BALANCE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(5)

'//
'// WPD_STILL_IMAGE_RGB_GAIN
'//   [ VT_LPWSTR ] Controls the RGB gain.
MACRO WPD_STILL_IMAGE_RGB_GAIN = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(6)

'//
'// WPD_STILL_IMAGE_FNUMBER
'//   [ VT_UI4 ] Controls the aperture of the lens.
MACRO WPD_STILL_IMAGE_FNUMBER = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(7)

'//
'// WPD_STILL_IMAGE_FOCAL_LENGTH
'//   [ VT_UI4 ] Controls the 35mm equivalent focal length.
MACRO WPD_STILL_IMAGE_FOCAL_LENGTH = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(8)

'//
'// WPD_STILL_IMAGE_FOCUS_DISTANCE
'//   [ VT_UI4 ] This property corresponds to the focus distance in millimeters
MACRO WPD_STILL_IMAGE_FOCUS_DISTANCE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(9)

'//
'// WPD_STILL_IMAGE_FOCUS_MODE
'//   [ VT_UI4 ] Identifies the focusing mode used by the device for image capture.
MACRO WPD_STILL_IMAGE_FOCUS_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(10)

'//
'// WPD_STILL_IMAGE_EXPOSURE_METERING_MODE
'//   [ VT_UI4 ] Identifies the exposure metering mode used by the device for image capture.
MACRO WPD_STILL_IMAGE_EXPOSURE_METERING_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(11)

'//
'// WPD_STILL_IMAGE_FLASH_MODE
'//   [ VT_UI4 ]
MACRO WPD_STILL_IMAGE_FLASH_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(12)

'//
'// WPD_STILL_IMAGE_EXPOSURE_TIME
'//   [ VT_UI4 ] Controls the shutter speed of the device.
MACRO WPD_STILL_IMAGE_EXPOSURE_TIME = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(13)

'//
'// WPD_STILL_IMAGE_EXPOSURE_PROGRAM_MODE
'//   [ VT_UI4 ] Controls the exposure program mode of the device.
MACRO WPD_STILL_IMAGE_EXPOSURE_PROGRAM_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(14)

'//
'// WPD_STILL_IMAGE_EXPOSURE_INDEX
'//   [ VT_UI4 ] Controls the emulation of film speed settings.
MACRO WPD_STILL_IMAGE_EXPOSURE_INDEX = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(15)

'//
'// WPD_STILL_IMAGE_EXPOSURE_BIAS_COMPENSATION
'//   [ VT_I4 ] Controls the adjustment of the auto exposure control.
MACRO WPD_STILL_IMAGE_EXPOSURE_BIAS_COMPENSATION = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(16)

'//
'// WPD_STILL_IMAGE_CAPTURE_DELAY
'//   [ VT_UI4 ] Controls the amount of time delay between the capture trigger and the actual data capture (in milliseconds).
MACRO WPD_STILL_IMAGE_CAPTURE_DELAY = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(17)

'//
'// WPD_STILL_IMAGE_CAPTURE_MODE
'//   [ VT_UI4 ] Controls the type of still image capture.
MACRO WPD_STILL_IMAGE_CAPTURE_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(18)

'//
'// WPD_STILL_IMAGE_CONTRAST
'//   [ VT_UI4 ] Controls the perceived contrast of captured images.
MACRO WPD_STILL_IMAGE_CONTRAST = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(19)

'//
'// WPD_STILL_IMAGE_SHARPNESS
'//   [ VT_UI4 ] Controls the perceived sharpness of the captured image.
MACRO WPD_STILL_IMAGE_SHARPNESS = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(20)

'//
'// WPD_STILL_IMAGE_DIGITAL_ZOOM
'//   [ VT_UI4 ] Controls the effective zoom ratio of a digital camera's acquired image scaled by a factor of 10.
MACRO WPD_STILL_IMAGE_DIGITAL_ZOOM = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(21)

'//
'// WPD_STILL_IMAGE_EFFECT_MODE
'//   [ VT_UI4 ] Controls the special effect mode of the capture.
MACRO WPD_STILL_IMAGE_EFFECT_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(22)

'//
'// WPD_STILL_IMAGE_BURST_NUMBER
'//   [ VT_UI4 ] Controls the number of images that the device will attempt to capture upon initiation of a burst operation.
MACRO WPD_STILL_IMAGE_BURST_NUMBER = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(23)

'//
'// WPD_STILL_IMAGE_BURST_INTERVAL
'//   [ VT_UI4 ] Controls the time delay between captures upon initiation of a burst operation.
MACRO WPD_STILL_IMAGE_BURST_INTERVAL = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(24)

'//
'// WPD_STILL_IMAGE_TIMELAPSE_NUMBER
'//   [ VT_UI4 ] Controls the number of images that the device will attempt to capture upon initiation of a time-lapse capture.
MACRO WPD_STILL_IMAGE_TIMELAPSE_NUMBER = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(25)

'//
'// WPD_STILL_IMAGE_TIMELAPSE_INTERVAL
'//   [ VT_UI4 ] Controls the time delay between captures upon initiation of a time-lapse operation.
MACRO WPD_STILL_IMAGE_TIMELAPSE_INTERVAL = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(26)

'//
'// WPD_STILL_IMAGE_FOCUS_METERING_MODE
'//   [ VT_UI4 ] Controls which automatic focus mechanism is used by the device.
MACRO WPD_STILL_IMAGE_FOCUS_METERING_MODE = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(27)

'//
'// WPD_STILL_IMAGE_UPLOAD_URL
'//   [ VT_LPWSTR ] Used to describe the URL that the device may use to upload images upon capture.
MACRO WPD_STILL_IMAGE_UPLOAD_URL = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(28)

'//
'// WPD_STILL_IMAGE_ARTIST
'//   [ VT_LPWSTR ] Contains the owner/user of the device, which may be inserted as meta-data into any images that are captured.
MACRO WPD_STILL_IMAGE_ARTIST = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(29)

'//
'// WPD_STILL_IMAGE_CAMERA_MODEL
'//   [ VT_LPWSTR ] Contains the model of the device
MACRO WPD_STILL_IMAGE_CAMERA_MODEL = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(30)

'//
'// WPD_STILL_IMAGE_CAMERA_MANUFACTURER
'//   [ VT_LPWSTR ] Contains the manufacturer of the device
MACRO WPD_STILL_IMAGE_CAMERA_MANUFACTURER = GUID$("{58C571EC-1BCB-42A7-8AC5-BB291573A260}") & MKDWD$(31)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_SMS_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all objects whose functional category is WPD_FUNCTIONAL_CATEGORY_SMS
'****************************************************************************/
$WPD_SMS_OBJECT_PROPERTIES_V1 = GUID$("{7E1074CC-50FF-4DD1-A742-53BE6F093A0D}")

'//
'// WPD_SMS_PROVIDER
'//   [ VT_LPWSTR ] Indicates the service provider name.
MACRO WPD_SMS_PROVIDER = GUID$("{7E1074CC-50FF-4DD1-A742-53BE6F093A0D}") & MKDWD$(2)

'//
'// WPD_SMS_TIMEOUT
'//   [ VT_UI4 ] Indicates the number of milliseconds until a timeout is returned.
MACRO WPD_SMS_TIMEOUT = GUID$("{7E1074CC-50FF-4DD1-A742-53BE6F093A0D}") & MKDWD$(3)

'//
'// WPD_SMS_MAX_PAYLOAD
'//   [ VT_UI4 ] Indicates the maximum number of bytes that can be contained in a message.
MACRO WPD_SMS_MAX_PAYLOAD = GUID$("{7E1074CC-50FF-4DD1-A742-53BE6F093A0D}") & MKDWD$(4)

'//
'// WPD_SMS_ENCODING
'//   [ VT_UI4 ] Indicates how the driver will encode the text message sent by the client.
MACRO WPD_SMS_ENCODING = GUID$("{7E1074CC-50FF-4DD1-A742-53BE6F093A0D}") & MKDWD$(5)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_SECTION_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all objects whose content type is WPD_CONTENT_TYPE_SECTION
'****************************************************************************/
$WPD_SECTION_OBJECT_PROPERTIES_V1 = GUID$("{516AFD2B-C64E-44F0-98DC-BEE1C88F7D66}")

'//
'// WPD_SECTION_DATA_OFFSET
'//   [ VT_UI8 ] Indicates the zero-based offset of the data for the referenced object.
MACRO WPD_SECTION_DATA_OFFSET = GUID$("{516AFD2B-C64E-44F0-98DC-BEE1C88F7D66}") & MKDWD$(2)

'//
'// WPD_SECTION_DATA_LENGTH
'//   [ VT_UI8 ] Indicates the length of data for the referenced object.
MACRO WPD_SECTION_DATA_LENGTH = GUID$("{516AFD2B-C64E-44F0-98DC-BEE1C88F7D66}") & MKDWD$(3)

'//
'// WPD_SECTION_DATA_UNITS
'//   [ VT_UI4 ] Indicates the units for WPD_SECTION_DATA_OFFSET and WPD_SECTION_DATA_LENGTH properties on this object (e.g. offset in bytes, offset in milliseconds etc.).
MACRO WPD_SECTION_DATA_UNITS = GUID$("{516AFD2B-C64E-44F0-98DC-BEE1C88F7D66}") & MKDWD$(4)

'//
'// WPD_SECTION_DATA_REFERENCED_OBJECT_RESOURCE
'//   [ VT_UNKNOWN ] This is an IPortableDeviceKeyCollection containing a single value, which is the key identifying the resource on the referenced object which the WPD_SECTION_DATA_OFFSET and WPD_SECTION_DATA_LENGTH apply to.
MACRO WPD_SECTION_DATA_REFERENCED_OBJECT_RESOURCE = GUID$("{516AFD2B-C64E-44F0-98DC-BEE1C88F7D66}") & MKDWD$(5)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_RENDERING_INFORMATION_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all objects whose functional category is WPD_FUNCTIONAL_CATEGORY_AUDIO_RENDERING_INFORMATION
'****************************************************************************/
$WPD_RENDERING_INFORMATION_OBJECT_PROPERTIES_V1 = GUID$("{C53D039F-EE23-4A31-8590-7639879870B4}")

'//
'// WPD_RENDERING_INFORMATION_PROFILES
'//   [ VT_UNKNOWN ] IPortableDeviceValuesCollection, where each element indicates the property settings for a supported profile.
MACRO WPD_RENDERING_INFORMATION_PROFILES = GUID$("{C53D039F-EE23-4A31-8590-7639879870B4}") & MKDWD$(2)

'//
'// WPD_RENDERING_INFORMATION_PROFILE_ENTRY_TYPE
'//   [ VT_UI4 ] Indicates whether a given entry (i.e. an IPortableDeviceValues) in WPD_RENDERING_INFORMATION_PROFILES relates to an Object or a Resource.
MACRO WPD_RENDERING_INFORMATION_PROFILE_ENTRY_TYPE = GUID$("{C53D039F-EE23-4A31-8590-7639879870B4}") & MKDWD$(3)

'//
'// WPD_RENDERING_INFORMATION_PROFILE_ENTRY_CREATABLE_RESOURCES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceKeyCollection identifying the resources that can be created on an object with this rendering profile.
MACRO WPD_RENDERING_INFORMATION_PROFILE_ENTRY_CREATABLE_RESOURCES = GUID$("{C53D039F-EE23-4A31-8590-7639879870B4}") & MKDWD$(4)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_STORAGE
'*
'* This category is for commands and parameters for storage functional objects.
'****************************************************************************/
$WPD_CATEGORY_STORAGE = GUID$("{D8F907A6-34CC-45FA-97FB-D007FA47EC94}")

'// ======== Commands ========

'//
'// WPD_COMMAND_STORAGE_FORMAT
'//     This command will format the storage.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_STORAGE_OBJECT_ID
'//  Results:
'//     None
MACRO WPD_COMMAND_STORAGE_FORMAT = GUID$("{D8F907A6-34CC-45FA-97FB-D007FA47EC94}") & MKDWD$(2)

'//
'// WPD_COMMAND_STORAGE_EJECT
'//     This will eject the storage, if it is a removable store and is capable of being ejected by the device.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_STORAGE_OBJECT_ID
'//  Results:
'//     None
MACRO WPD_COMMAND_STORAGE_EJECT = GUID$("{D8F907A6-34CC-45FA-97FB-D007FA47EC94}") & MKDWD$(4)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_STORAGE_OBJECT_ID
'//   [ VT_LPWSTR ] Indicates the object to format, move or eject.
MACRO WPD_PROPERTY_STORAGE_OBJECT_ID = GUID$("{D8F907A6-34CC-45FA-97FB-D007FA47EC94}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_STORAGE_DESTINATION_OBJECT_ID
'//   [ VT_LPWSTR ] Indicates the (folder) object destination for a move operation.
MACRO WPD_PROPERTY_STORAGE_DESTINATION_OBJECT_ID = GUID$("{D8F907A6-34CC-45FA-97FB-D007FA47EC94}") & MKDWD$(1002)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_SMS
'*
'* The commands in this category relate to Short-Message-Service functionality, typically exposed on mobile phones.
'****************************************************************************/
$WPD_CATEGORY_SMS = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}")

'// ======== Commands ========

'//
'// WPD_COMMAND_SMS_SEND
'//     This command is used to initiate the sending of an SMS message.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_COMMAND_TARGET
'//     [ Required ] WPD_PROPERTY_SMS_RECIPIENT
'//     [ Required ] WPD_PROPERTY_SMS_MESSAGE_TYPE
'//     [ Optional ] WPD_PROPERTY_SMS_TEXT_MESSAGE
'//     [ Optional ] WPD_PROPERTY_SMS_BINARY_MESSAGE
'//  Results:
'//     None
MACRO WPD_COMMAND_SMS_SEND = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}") & MKDWD$(2)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_SMS_RECIPIENT
'//   [ VT_LPWSTR ] Indicates the recipient's address.
MACRO WPD_PROPERTY_SMS_RECIPIENT = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_SMS_MESSAGE_TYPE
'//   [ VT_UI4 ] Indicates whether the message is binary or text.
MACRO WPD_PROPERTY_SMS_MESSAGE_TYPE = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_SMS_TEXT_MESSAGE
'//   [ VT_LPWSTR ] if WPD_PROPERTY_SMS_MESSAGE_TYPE == SMS_TEXT_MESSAGE, then this will contain the message body.
MACRO WPD_PROPERTY_SMS_TEXT_MESSAGE = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_SMS_BINARY_MESSAGE
'//   [ VT_VECTOR|VT_UI1 ] if WPD_PROPERTY_SMS_MESSAGE_TYPE == SMS_BINARY_MESSAGE, then this will contain the binary message body.
MACRO WPD_PROPERTY_SMS_BINARY_MESSAGE = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}") & MKDWD$(1004)

'// ======== Command Options ========

'//
'// WPD_OPTION_SMS_BINARY_MESSAGE_SUPPORTED
'//   [ VT_BOOL ] Indicates whether the driver can support binary messages as well as text messages.
MACRO WPD_OPTION_SMS_BINARY_MESSAGE_SUPPORTED = GUID$("{AFC25D66-FE0D-4114-9097-970C93E920D1}") & MKDWD$(5001)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_STILL_IMAGE_CAPTURE
'*
'*
'****************************************************************************/
$WPD_CATEGORY_STILL_IMAGE_CAPTURE = GUID$("{4FCD6982-22A2-4B05-A48B-62D38BF27B32}")

'// ======== Commands ========

'//
'// WPD_COMMAND_STILL_IMAGE_CAPTURE_INITIATE
'//     Initiates a still image capture. This is processed as a single command i.e. there is no start or stop required.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_COMMAND_TARGET
'//  Results:
'//     None
MACRO WPD_COMMAND_STILL_IMAGE_CAPTURE_INITIATE = GUID$("{4FCD6982-22A2-4B05-A48B-62D38BF27B32}") & MKDWD$(2)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_MEDIA_CAPTURE
'*
'*
'****************************************************************************/
$WPD_CATEGORY_MEDIA_CAPTURE = GUID$("{59B433BA-FE44-4D8D-808C-6BCB9B0F15E8}")

'// ======== Commands ========

'//
'// WPD_COMMAND_MEDIA_CAPTURE_START
'//     Initiates a media capture operation that will only be ended by a subsequent WPD_COMMAND_MEDIA_CAPTURE_STOP command. Typically used to capture media streams such as audio and video.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_COMMAND_TARGET
'//  Results:
'//     None
MACRO WPD_COMMAND_MEDIA_CAPTURE_START = GUID$("{59B433BA-FE44-4D8D-808C-6BCB9B0F15E8}") & MKDWD$(2)

'//
'// WPD_COMMAND_MEDIA_CAPTURE_STOP
'//     Ends a media capture operation started by a WPD_COMMAND_MEDIA_CAPTURE_START command. Typically used to end capture of media streams such as audio and video.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_COMMAND_TARGET
'//  Results:
'//     None
MACRO WPD_COMMAND_MEDIA_CAPTURE_STOP = GUID$("{59B433BA-FE44-4D8D-808C-6BCB9B0F15E8}") & MKDWD$(3)

'//
'// WPD_COMMAND_MEDIA_CAPTURE_PAUSE
'//     Pauses a media capture operation started by a WPD_COMMAND_MEDIA_CAPTURE_START command. Typically used to pause capture of media streams such as audio and video.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_COMMAND_TARGET
'//  Results:
'//     None
MACRO WPD_COMMAND_MEDIA_CAPTURE_PAUSE = GUID$("{59B433BA-FE44-4D8D-808C-6BCB9B0F15E8}") & MKDWD$(4)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_DEVICE_HINTS
'*
'* The commands in this category relate to hints that a device can provide to improve end-user experience.
'****************************************************************************/
$WPD_CATEGORY_DEVICE_HINTS = GUID$("{0D5FB92B-CB46-4C4F-8343-0BC3D3F17C84}")

'// ======== Commands ========

'//
'// WPD_COMMAND_DEVICE_HINTS_GET_CONTENT_LOCATION
'//     This command is used to retrieve the ObjectIDs of folders that contain the specified content type.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_DEVICE_HINTS_CONTENT_TYPE
'//  Results:
'//     [ Required ] WPD_PROPERTY_DEVICE_HINTS_CONTENT_LOCATIONS
MACRO WPD_COMMAND_DEVICE_HINTS_GET_CONTENT_LOCATION = GUID$("{0D5FB92B-CB46-4C4F-8343-0BC3D3F17C84}") & MKDWD$(2)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_DEVICE_HINTS_CONTENT_TYPE
'//   [ VT_CLSID ] Indicates the WPD content type that the caller is looking for. For example, to get the top-level folder objects that contain images, this parameter would be WPD_CONTENT_TYPE_IMAGE.
MACRO WPD_PROPERTY_DEVICE_HINTS_CONTENT_TYPE = GUID$("{0D5FB92B-CB46-4C4F-8343-0BC3D3F17C84}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_DEVICE_HINTS_CONTENT_LOCATIONS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_LPWSTR indicating a list of folder ObjectIDs.
MACRO WPD_PROPERTY_DEVICE_HINTS_CONTENT_LOCATIONS = GUID$("{0D5FB92B-CB46-4C4F-8343-0BC3D3F17C84}") & MKDWD$(1002)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_NETWORK_CONFIGURATION
'*
'* The commands in this category are used for Network Association and WiFi Configuration.
'****************************************************************************/
$WPD_CATEGORY_NETWORK_CONFIGURATION = GUID$("{78F9C6FC-79B8-473C-9060-6BD23DD072C4}")

'// ======== Commands ========

'//
'// WPD_COMMAND_GENERATE_KEYPAIR
'//     Initiates the generation of a public/private key pair and returns the public key.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_PUBLIC_KEY
MACRO WPD_COMMAND_GENERATE_KEYPAIR = GUID$("{78F9C6FC-79B8-473C-9060-6BD23DD072C4}") & MKDWD$(2)

'//
'// WPD_COMMAND_COMMIT_KEYPAIR
'//     Commits a public/private key pair.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     None
'//  Results:
'//     None
MACRO WPD_COMMAND_COMMIT_KEYPAIR = GUID$("{78F9C6FC-79B8-473C-9060-6BD23DD072C4}") & MKDWD$(3)

'//
'// WPD_COMMAND_PROCESS_WIRELESS_PROFILE
'//     Initiates the processing of a Wireless Profile file.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//  Results:
'//     None
MACRO WPD_COMMAND_PROCESS_WIRELESS_PROFILE = GUID$("{78F9C6FC-79B8-473C-9060-6BD23DD072C4}") & MKDWD$(4)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_PUBLIC_KEY
'//   [ VT_VECTOR|VT_UI1 ] A public key generated for RSA key exchange.
MACRO WPD_PROPERTY_PUBLIC_KEY = GUID$("{78F9C6FC-79B8-473C-9060-6BD23DD072C4}") & MKDWD$(1001)

'#endif // WPD_SERVICES_STRICT

'/****************************************************************************
'* This section defines all Resource keys. Resources are place-holders for
'* binary data.
'*
'****************************************************************************/
'//
'//
'//   Represents the entire object's data. There can be only one default resource on an object.
MACRO WPD_RESOURCE_DEFAULT = GUID$("{E81E79BE-34F0-41BF-B53F-F1A06AE87842}") & MKDWD$(0)

'//
'// WPD_RESOURCE_CONTACT_PHOTO
'//   Represents the contact's photo data.
MACRO WPD_RESOURCE_CONTACT_PHOTO = GUID$("{2C4D6803-80EA-4580-AF9A-5BE1A23EDDCB}") & MKDWD$(0)

'//
'// WPD_RESOURCE_THUMBNAIL
'//   Represents the thumbnail data for an object.
MACRO WPD_RESOURCE_THUMBNAIL = GUID$("{C7C407BA-98FA-46B5-9960-23FEC124CFDE}") & MKDWD$(0)

'//
'// WPD_RESOURCE_ICON
'//   Represents the icon data for an object.
MACRO WPD_RESOURCE_ICON = GUID$("{F195FED8-AA28-4EE3-B153-E182DD5EDC39}") & MKDWD$(0)

'//
'// WPD_RESOURCE_AUDIO_CLIP
'//   Represents an audio sample data for an object.
MACRO WPD_RESOURCE_AUDIO_CLIP = GUID$("{3BC13982-85B1-48E0-95A6-8D3AD06BE117}") & MKDWD$(0)

'//
'// WPD_RESOURCE_ALBUM_ART
'//   Represents the album artwork this media originated from.
MACRO WPD_RESOURCE_ALBUM_ART = GUID$("{F02AA354-2300-4E2D-A1B9-3B6730F7FA21}") & MKDWD$(0)

'//
'// WPD_RESOURCE_GENERIC
'//   Represents an arbitrary binary blob associated with this object.
MACRO WPD_RESOURCE_GENERIC = GUID$("{B9B9F515-BA70-4647-94DC-FA4925E95A07}") & MKDWD$(0)

'//
'// WPD_RESOURCE_VIDEO_CLIP
'//   Represents a video sample for an object.
MACRO WPD_RESOURCE_VIDEO_CLIP = GUID$("{B566EE42-6368-4290-8662-70182FB79F20}") & MKDWD$(0)

'//
'// WPD_RESOURCE_BRANDING_ART
'//   Represents the product branding artwork or logo for an object. This resource is typically found on, but not limited to the device object.
MACRO WPD_RESOURCE_BRANDING_ART = GUID$("{B633B1AE-6CAF-4A87-9589-22DED6DD5899}") & MKDWD$(0)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_NULL
'*
'* This category is used exclusively for the NULL property key define.
'****************************************************************************/
$WPD_CATEGORY_NULL = GUID$("{00000000-0000-0000-0000-000000000000}")

'//
'// WPD_PROPERTY_NULL
'//   [ VT_EMPTY ] A NULL property key.
MACRO WPD_PROPERTY_NULL = GUID$("{00000000-0000-0000-0000-000000000000}") & MKDWD$(0)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_FUNCTIONAL_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all functional objects.
'****************************************************************************/
$WPD_FUNCTIONAL_OBJECT_PROPERTIES_V1 = GUID$("{8F052D93-ABCA-4FC5-A5AC-B01DF4DBE598}")

'//
'// WPD_FUNCTIONAL_OBJECT_CATEGORY
'//   [ VT_CLSID ] Indicates the object's functional category.
MACRO WPD_FUNCTIONAL_OBJECT_CATEGORY = GUID$("{8F052D93-ABCA-4FC5-A5AC-B01DF4DBE598}") & MKDWD$(2)


'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_STORAGE_OBJECT_PROPERTIES_V1
'*
'* This category is for properties common to all objects whose functional category is WPD_FUNCTIONAL_CATEGORY_STORAGE.
'****************************************************************************/
$WPD_STORAGE_OBJECT_PROPERTIES_V1 = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}")

'//
'// WPD_STORAGE_TYPE
'//   [ VT_UI4 ] Indicates the type of storage e.g. fixed, removable etc.
MACRO WPD_STORAGE_TYPE = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(2)

'//
'// WPD_STORAGE_FILE_SYSTEM_TYPE
'//   [ VT_LPWSTR ] Indicates the file system type e.g. "FAT32" or "NTFS" or "My Special File System"
MACRO WPD_STORAGE_FILE_SYSTEM_TYPE = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(3)

'//
'// WPD_STORAGE_CAPACITY
'//   [ VT_UI8 ] Indicates the total storage capacity in bytes.
MACRO WPD_STORAGE_CAPACITY = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(4)

'//
'// WPD_STORAGE_FREE_SPACE_IN_BYTES
'//   [ VT_UI8 ] Indicates the available space in bytes.
MACRO WPD_STORAGE_FREE_SPACE_IN_BYTES = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(5)

'//
'// WPD_STORAGE_FREE_SPACE_IN_OBJECTS
'//   [ VT_UI8 ] Indicates the available space in objects e.g. available slots on a SIM card.
MACRO WPD_STORAGE_FREE_SPACE_IN_OBJECTS = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(6)

'//
'// WPD_STORAGE_DESCRIPTION
'//   [ VT_LPWSTR ] Contains a description of the storage.
MACRO WPD_STORAGE_DESCRIPTION = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(7)

'//
'// WPD_STORAGE_SERIAL_NUMBER
'//   [ VT_LPWSTR ] Contains the serial number of the storage.
MACRO WPD_STORAGE_SERIAL_NUMBER = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(8)

'//
'// WPD_STORAGE_MAX_OBJECT_SIZE
'//   [ VT_UI8 ] Specifies the maximum size of a single object (in bytes) that can be placed on this storage.
MACRO WPD_STORAGE_MAX_OBJECT_SIZE = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(9)

'//
'// WPD_STORAGE_CAPACITY_IN_OBJECTS
'//   [ VT_UI8 ] Indicates the total storage capacity in objects e.g. available slots on a SIM card.
MACRO WPD_STORAGE_CAPACITY_IN_OBJECTS = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(10)

'//
'// WPD_STORAGE_ACCESS_CAPABILITY
'//   [ VT_UI4 ] This property identifies any write-protection that globally affects this storage. This takes precedence over access specified on individual objects.
MACRO WPD_STORAGE_ACCESS_CAPABILITY = GUID$("{01A3057A-74D6-4E80-BEA7-DC4C212CE50A}") & MKDWD$(11)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CLIENT_INFORMATION_PROPERTIES_V1
'*
'*
'****************************************************************************/
$WPD_CLIENT_INFORMATION_PROPERTIES_V1 = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}")

'//
'// WPD_CLIENT_NAME
'//   [ VT_LPWSTR ] Specifies the name the client uses to identify itself.
MACRO WPD_CLIENT_NAME = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(2)

'//
'// WPD_CLIENT_MAJOR_VERSION
'//   [ VT_UI4 ] Specifies the major version of the client.
MACRO WPD_CLIENT_MAJOR_VERSION = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(3)

'//
'// WPD_CLIENT_MINOR_VERSION
'//   [ VT_UI4 ] Specifies the major version of the client.
MACRO WPD_CLIENT_MINOR_VERSION = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(4)

'//
'// WPD_CLIENT_REVISION
'//   [ VT_UI4 ] Specifies the revision (or build number) of the client.
MACRO WPD_CLIENT_REVISION = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(5)

'//
'// WPD_CLIENT_WMDRM_APPLICATION_PRIVATE_KEY
'//   [ VT_VECTOR | VT_UI1 ] Specifies the Windows Media DRM application private key of the client.
MACRO WPD_CLIENT_WMDRM_APPLICATION_PRIVATE_KEY = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(6)

'//
'// WPD_CLIENT_WMDRM_APPLICATION_CERTIFICATE
'//   [ VT_VECTOR | VT_UI1 ] Specifies the Windows Media DRM application certificate of the client.
MACRO WPD_CLIENT_WMDRM_APPLICATION_CERTIFICATE = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(7)

'//
'// WPD_CLIENT_SECURITY_QUALITY_OF_SERVICE
'//   [ VT_UI4 ] Specifies the Security Quality of Service for the connection to the driver. This relates to the Security Quality of Service flags for CreateFile. For example, these allow or disallow a driver to impersonate the client.
MACRO WPD_CLIENT_SECURITY_QUALITY_OF_SERVICE = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(8)

'//
'// WPD_CLIENT_DESIRED_ACCESS
'//   [ VT_UI4 ] Specifies the desired access the client is requesting to this driver. The possible values are the same as for CreateFile (e.g. GENERIC_READ, GENERIC_WRITE etc.).
MACRO WPD_CLIENT_DESIRED_ACCESS = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(9)

'//
'// WPD_CLIENT_SHARE_MODE
'//   [ VT_UI4 ] Specifies the share mode the client is requesting to this driver. The possible values are the same as for CreateFile (e.g. FILE_SHARE_READ, FILE_SHARE_WRITE etc.).
MACRO WPD_CLIENT_SHARE_MODE = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(10)

'//
'// WPD_CLIENT_EVENT_COOKIE
'//   [ VT_LPWSTR ] Client supplied cookie returned by the driver in events posted as a direct result of operations issued by this client.
MACRO WPD_CLIENT_EVENT_COOKIE = GUID$("{204D9F0C-2292-4080-9F42-40664E70F859}") & MKDWD$(11)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_PROPERTY_ATTRIBUTES_V1
'*
'*
'****************************************************************************/
$WPD_PROPERTY_ATTRIBUTES_V1 = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}")

'//
'// WPD_PROPERTY_ATTRIBUTE_FORM
'//   [ VT_UI4 ] Specifies the form of the valid values allowed for this property.
MACRO WPD_PROPERTY_ATTRIBUTE_FORM = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(2)

'//
'// WPD_PROPERTY_ATTRIBUTE_CAN_READ
'//   [ VT_BOOL ] Indicates whether client applications have permission to Read the property.
MACRO WPD_PROPERTY_ATTRIBUTE_CAN_READ = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(3)

'//
'// WPD_PROPERTY_ATTRIBUTE_CAN_WRITE
'//   [ VT_BOOL ] Indicates whether client applications have permission to Write the property.
MACRO WPD_PROPERTY_ATTRIBUTE_CAN_WRITE = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(4)

'//
'// WPD_PROPERTY_ATTRIBUTE_CAN_DELETE
'//   [ VT_BOOL ] Indicates whether client applications have permission to Delete the property.
MACRO WPD_PROPERTY_ATTRIBUTE_CAN_DELETE = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(5)

'//
'// WPD_PROPERTY_ATTRIBUTE_DEFAULT_VALUE
'//   [ VT_XXXX ] Specifies the default value for a write-able property.
MACRO WPD_PROPERTY_ATTRIBUTE_DEFAULT_VALUE = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(6)

'//
'// WPD_PROPERTY_ATTRIBUTE_FAST_PROPERTY
'//   [ VT_BOOL ] If True, then this property belongs to the PORTABLE_DEVICE_FAST_PROPERTIES group.
MACRO WPD_PROPERTY_ATTRIBUTE_FAST_PROPERTY = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(7)

'//
'// WPD_PROPERTY_ATTRIBUTE_RANGE_MIN
'//   [ VT_XXXX ] The minimum value for a property whose form is of WPD_PROPERTY_ATTRIBUTE_FORM_RANGE.
MACRO WPD_PROPERTY_ATTRIBUTE_RANGE_MIN = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(8)

'//
'// WPD_PROPERTY_ATTRIBUTE_RANGE_MAX
'//   [ VT_XXXX ] The maximum value for a property whose form is of WPD_PROPERTY_ATTRIBUTE_FORM_RANGE.
MACRO WPD_PROPERTY_ATTRIBUTE_RANGE_MAX = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(9)

'//
'// WPD_PROPERTY_ATTRIBUTE_RANGE_STEP
'//   [ VT_XXXX ] The step value for a property whose form is of WPD_PROPERTY_ATTRIBUTE_FORM_RANGE.
MACRO WPD_PROPERTY_ATTRIBUTE_RANGE_STEP = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(10)

'//
'// WPD_PROPERTY_ATTRIBUTE_ENUMERATION_ELEMENTS
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection containing the enumeration values.
MACRO WPD_PROPERTY_ATTRIBUTE_ENUMERATION_ELEMENTS = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(11)

'//
'// WPD_PROPERTY_ATTRIBUTE_REGULAR_EXPRESSION
'//   [ VT_LPWSTR ] A regular expression string indicating acceptable values for properties whose form is WPD_PROPERTY_ATTRIBUTE_FORM_REGULAR_EXPRESSION.
MACRO WPD_PROPERTY_ATTRIBUTE_REGULAR_EXPRESSION = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(12)

'//
'// WPD_PROPERTY_ATTRIBUTE_MAX_SIZE
'//   [ VT_UI8 ] This indicates the maximum size (in bytes) for the value of this property.
MACRO WPD_PROPERTY_ATTRIBUTE_MAX_SIZE = GUID$("{AB7943D8-6332-445F-A00D-8D5EF1E96F37}") & MKDWD$(13)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_PROPERTY_ATTRIBUTES_V2
'*
'* This category defines additional property attributes used by device services.
'****************************************************************************/
$WPD_PROPERTY_ATTRIBUTES_V2 = GUID$("{5D9DA160-74AE-43CC-85A9-FE555A80798E}")

'//
'// WPD_PROPERTY_ATTRIBUTE_NAME
'//   [ VT_LPWSTR ] Contains the name of the property.
MACRO WPD_PROPERTY_ATTRIBUTE_NAME = GUID$("{5D9DA160-74AE-43CC-85A9-FE555A80798E}") & MKDWD$(2)

'//
'// WPD_PROPERTY_ATTRIBUTE_VARTYPE
'//   [ VT_UI4 ] Contains the VARTYPE of the property.
MACRO WPD_PROPERTY_ATTRIBUTE_VARTYPE = GUID$("{5D9DA160-74AE-43CC-85A9-FE555A80798E}") & MKDWD$(3)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CLASS_EXTENSION_OPTIONS_V1
'*
'* This category of properties relates to options used for the WPD device class extension
'****************************************************************************/
$WPD_CLASS_EXTENSION_OPTIONS_V1 = GUID$("{6309FFEF-A87C-4CA7-8434-797576E40A96}")

'//
'// WPD_CLASS_EXTENSION_OPTIONS_SUPPORTED_CONTENT_TYPES
'//   [ VT_UNKNOWN ] Indicates the (super-set) list of content types supported by the driver (similar to calling WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_CONTENT_TYPES on WPD_FUNCTIONAL_CATEGORY_ALL).
MACRO WPD_CLASS_EXTENSION_OPTIONS_SUPPORTED_CONTENT_TYPES = GUID$("{6309FFEF-A87C-4CA7-8434-797576E40A96}") & MKDWD$(2)

'//
'// WPD_CLASS_EXTENSION_OPTIONS_DONT_REGISTER_WPD_DEVICE_INTERFACE
'//   [ VT_BOOL ] Indicates that the caller does not want the WPD class extension library to register the WPD Device Class interface. The caller will take responsibility for doing it.
MACRO WPD_CLASS_EXTENSION_OPTIONS_DONT_REGISTER_WPD_DEVICE_INTERFACE = GUID$("{6309FFEF-A87C-4CA7-8434-797576E40A96}") & MKDWD$(3)

'//
'// WPD_CLASS_EXTENSION_OPTIONS_REGISTER_WPD_PRIVATE_DEVICE_INTERFACE
'//   [ VT_BOOL ] Indicates that the caller wants the WPD class extension library to register the private WPD Device Class interface.
MACRO WPD_CLASS_EXTENSION_OPTIONS_REGISTER_WPD_PRIVATE_DEVICE_INTERFACE = GUID$("{6309FFEF-A87C-4CA7-8434-797576E40A96}") & MKDWD$(4)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CLASS_EXTENSION_OPTIONS_V2
'*
'* This category of properties relates to options used for the WPD device class extension
'****************************************************************************/
$WPD_CLASS_EXTENSION_OPTIONS_V2 = GUID$("{3E3595DA-4D71-49FE-A0B4-D4406C3AE93F}")

'//
'// WPD_CLASS_EXTENSION_OPTIONS_MULTITRANSPORT_MODE
'//   [ VT_BOOL ] Indicates that the caller wants the WPD class extension library to go into Multi-Transport mode (if TRUE).
MACRO WPD_CLASS_EXTENSION_OPTIONS_MULTITRANSPORT_MODE = GUID$("{3E3595DA-4D71-49FE-A0B4-D4406C3AE93F}") & MKDWD$(2)

'//
'// WPD_CLASS_EXTENSION_OPTIONS_DEVICE_IDENTIFICATION_VALUES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the device identification values (WPD_DEVICE_MANUFACTURER, WPD_DEVICE_MODEL, WPD_DEVICE_FIRMWARE_VERSION and WPD_DEVICE_FUNCTIONAL_UNIQUE_ID).
'//   Include this with other Class Extension options when initializing.
MACRO WPD_CLASS_EXTENSION_OPTIONS_DEVICE_IDENTIFICATION_VALUES = GUID$("{3E3595DA-4D71-49FE-A0B4-D4406C3AE93F}") & MKDWD$(3)

'//
'// WPD_CLASS_EXTENSION_OPTIONS_TRANSPORT_BANDWIDTH
'//   [ VT_UI4 ] Indicates the theoretical maximum bandwidth of the transport in kilobits per second.
MACRO WPD_CLASS_EXTENSION_OPTIONS_TRANSPORT_BANDWIDTH = GUID$("{3E3595DA-4D71-49FE-A0B4-D4406C3AE93F}") & MKDWD$(4)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_RESOURCE_ATTRIBUTES_V1
'*
'*
'****************************************************************************/
$WPD_RESOURCE_ATTRIBUTES_V1 = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}")

'//
'// WPD_RESOURCE_ATTRIBUTE_TOTAL_SIZE
'//   [ VT_UI8 ] Total size in bytes of the resource data.
MACRO WPD_RESOURCE_ATTRIBUTE_TOTAL_SIZE = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(2)

'//
'// WPD_RESOURCE_ATTRIBUTE_CAN_READ
'//   [ VT_BOOL ] Indicates whether client applications have permission to open the resource for Read access.
MACRO WPD_RESOURCE_ATTRIBUTE_CAN_READ = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(3)

'//
'// WPD_RESOURCE_ATTRIBUTE_CAN_WRITE
'//   [ VT_BOOL ] Indicates whether client applications have permission to open the resource for Write access.
MACRO WPD_RESOURCE_ATTRIBUTE_CAN_WRITE = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(4)

'//
'// WPD_RESOURCE_ATTRIBUTE_CAN_DELETE
'//   [ VT_BOOL ] Indicates whether client applications have permission to Delete a resource from the device.
MACRO WPD_RESOURCE_ATTRIBUTE_CAN_DELETE = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(5)

'//
'// WPD_RESOURCE_ATTRIBUTE_OPTIMAL_READ_BUFFER_SIZE
'//   [ VT_UI4 ] The recommended buffer size a caller should use when doing buffered reads on the resource.
MACRO WPD_RESOURCE_ATTRIBUTE_OPTIMAL_READ_BUFFER_SIZE = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(6)

'//
'// WPD_RESOURCE_ATTRIBUTE_OPTIMAL_WRITE_BUFFER_SIZE
'//   [ VT_UI4 ] The recommended buffer size a caller should use when doing buffered writes on the resource.
MACRO WPD_RESOURCE_ATTRIBUTE_OPTIMAL_WRITE_BUFFER_SIZE = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(7)

'//
'// WPD_RESOURCE_ATTRIBUTE_FORMAT
'//   [ VT_CLSID ] Indicates the format of the resource data.
MACRO WPD_RESOURCE_ATTRIBUTE_FORMAT = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(8)

'//
'// WPD_RESOURCE_ATTRIBUTE_RESOURCE_KEY
'//   [ VT_UNKNOWN ] This is an IPortableDeviceKeyCollection containing a single value, which is the key identifying the resource.
MACRO WPD_RESOURCE_ATTRIBUTE_RESOURCE_KEY = GUID$("{1EB6F604-9278-429F-93CC-5BB8C06656B6}") & MKDWD$(9)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_DEVICE_PROPERTIES_V1
'*
'*
'****************************************************************************/
$WPD_DEVICE_PROPERTIES_V1 = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}")

'//
'// WPD_DEVICE_SYNC_PARTNER
'//   [ VT_LPWSTR ] Indicates a human-readable description of a synchronization partner for the device.
MACRO WPD_DEVICE_SYNC_PARTNER = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(2)

'//
'// WPD_DEVICE_FIRMWARE_VERSION
'//   [ VT_LPWSTR ] Indicates the firmware version for the device.
MACRO WPD_DEVICE_FIRMWARE_VERSION = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(3)

'//
'// WPD_DEVICE_POWER_LEVEL
'//   [ VT_UI4 ] Indicates the power level of the device's battery.
MACRO WPD_DEVICE_POWER_LEVEL = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(4)

'//
'// WPD_DEVICE_POWER_SOURCE
'//   [ VT_UI4 ] Indicates the power source of the device e.g. whether it is battery or external.
MACRO WPD_DEVICE_POWER_SOURCE = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(5)

'//
'// WPD_DEVICE_PROTOCOL
'//   [ VT_LPWSTR ] Identifies the device protocol being used.
MACRO WPD_DEVICE_PROTOCOL = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(6)

'//
'// WPD_DEVICE_MANUFACTURER
'//   [ VT_LPWSTR ] Identifies the device manufacturer.
MACRO WPD_DEVICE_MANUFACTURER = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(7)

'//
'// WPD_DEVICE_MODEL
'//   [ VT_LPWSTR ] Identifies the device model.
MACRO WPD_DEVICE_MODEL = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(8)

'//
'// WPD_DEVICE_SERIAL_NUMBER
'//   [ VT_LPWSTR ] Identifies the serial number of the device.
MACRO WPD_DEVICE_SERIAL_NUMBER = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(9)

'//
'// WPD_DEVICE_SUPPORTS_NON_CONSUMABLE
'//   [ VT_BOOL ] Indicates whether the device supports non-consumable objects.
MACRO WPD_DEVICE_SUPPORTS_NON_CONSUMABLE = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(10)

'//
'// WPD_DEVICE_DATETIME
'//   [ VT_DATE ] Represents the current date and time settings of the device.
MACRO WPD_DEVICE_DATETIME = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(11)

'//
'// WPD_DEVICE_FRIENDLY_NAME
'//   [ VT_LPWSTR ] Represents the friendly name set by the user on the device.
MACRO WPD_DEVICE_FRIENDLY_NAME = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(12)

'//
'// WPD_DEVICE_SUPPORTED_DRM_SCHEMES
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection of VT_LPWSTR values indicating the Digital Rights Management schemes supported by the driver.
MACRO WPD_DEVICE_SUPPORTED_DRM_SCHEMES = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(13)

'//
'// WPD_DEVICE_SUPPORTED_FORMATS_ARE_ORDERED
'//   [ VT_BOOL ] Indicates whether the supported formats returned from the device are in a preferred order. (First format in the list is most preferred by the device, while the last is the least preferred.)
MACRO WPD_DEVICE_SUPPORTED_FORMATS_ARE_ORDERED = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(14)

'//
'// WPD_DEVICE_TYPE
'//   [ VT_UI4 ] Indicates the device type, used for representation purposes only. Functional characteristics of the device are decided through functional objects.
MACRO WPD_DEVICE_TYPE = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(15)

'//
'// WPD_DEVICE_NETWORK_IDENTIFIER
'//   [ VT_UI8 ] Indicates the EUI-64 network identifier of the device, used for out-of-band Network Association operations.
MACRO WPD_DEVICE_NETWORK_IDENTIFIER = GUID$("{26D4979A-E643-4626-9E2B-736DC0C92FDC}") & MKDWD$(16)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_DEVICE_PROPERTIES_V2
'*
'*
'****************************************************************************/
$WPD_DEVICE_PROPERTIES_V2 = GUID$("{463DD662-7FC4-4291-911C-7F4C9CCA9799}")

'//
'// WPD_DEVICE_FUNCTIONAL_UNIQUE_ID
'//   [ VT_VECTOR | VT_UI1 ] Indicates a unique 16 byte identifier common across multiple transports supported by the device.
MACRO WPD_DEVICE_FUNCTIONAL_UNIQUE_ID = GUID$("{463DD662-7FC4-4291-911C-7F4C9CCA9799}") & MKDWD$(2)

'//
'// WPD_DEVICE_MODEL_UNIQUE_ID
'//   [ VT_VECTOR | VT_UI1 ] Indicates a unique 16 byte identifier for cosmetic differentiation among different models of the device.
MACRO WPD_DEVICE_MODEL_UNIQUE_ID = GUID$("{463DD662-7FC4-4291-911C-7F4C9CCA9799}") & MKDWD$(3)

'//
'// WPD_DEVICE_TRANSPORT
'//   [ VT_UI4 ] Indicates the transport type (USB, IP, Bluetooth, etc.).
MACRO WPD_DEVICE_TRANSPORT = GUID$("{463DD662-7FC4-4291-911C-7F4C9CCA9799}") & MKDWD$(4)

'//
'// WPD_DEVICE_USE_DEVICE_STAGE
'//   [ VT_BOOL ] If this property exists and is set to TRUE, the device can be used with Device Stage.
MACRO WPD_DEVICE_USE_DEVICE_STAGE = GUID$("{463DD662-7FC4-4291-911C-7F4C9CCA9799}") & MKDWD$(5)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_SERVICE_PROPERTIES_V1
'*
'*
'****************************************************************************/
$WPD_SERVICE_PROPERTIES_V1 = GUID$("{7510698A-CB54-481C-B8DB-0D75C93F1C06}")

'//
'// WPD_SERVICE_VERSION
'//   [ VT_LPWSTR ] Indicates the implementation version of a service.
MACRO WPD_SERVICE_VERSION = GUID$("{7510698A-CB54-481C-B8DB-0D75C93F1C06}") & MKDWD$(2)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_EVENT_PROPERTIES_V1
'*
'* The properties in this category are for properties that may be needed for event processing, but do not have object property equivalents (i.e. they are not exposed as object properties, but rather, used only as event parameters).
'****************************************************************************/
$WPD_EVENT_PROPERTIES_V1 = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}")

'//
'// WPD_EVENT_PARAMETER_PNP_DEVICE_ID
'//   [ VT_LPWSTR ] Indicates the device that originated the event.
MACRO WPD_EVENT_PARAMETER_PNP_DEVICE_ID = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(2)

'//
'// WPD_EVENT_PARAMETER_EVENT_ID
'//   [ VT_CLSID ] Indicates the event sent.
MACRO WPD_EVENT_PARAMETER_EVENT_ID = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(3)

'//
'// WPD_EVENT_PARAMETER_OPERATION_STATE
'//   [ VT_UI4 ] Indicates the current state of the operation (e.g. started, running, stopped etc.).
MACRO WPD_EVENT_PARAMETER_OPERATION_STATE = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(4)

'//
'// WPD_EVENT_PARAMETER_OPERATION_PROGRESS
'//   [ VT_UI4 ] Indicates the progress of a currently executing operation. Value is from 0 to 100, with 100 indicating that the operation is complete.
MACRO WPD_EVENT_PARAMETER_OPERATION_PROGRESS = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(5)

'//
'// WPD_EVENT_PARAMETER_OBJECT_PARENT_PERSISTENT_UNIQUE_ID
'//   [ VT_LPWSTR ] Uniquely identifies the parent object, similar to WPD_OBJECT_PARENT_ID, but this ID will not change between sessions.
MACRO WPD_EVENT_PARAMETER_OBJECT_PARENT_PERSISTENT_UNIQUE_ID = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(6)

'//
'// WPD_EVENT_PARAMETER_OBJECT_CREATION_COOKIE
'//   [ VT_LPWSTR ] This is the cookie handed back to a client when it requested an object creation using the IPortableDeviceContent::CreateObjectWithPropertiesAndData method.
MACRO WPD_EVENT_PARAMETER_OBJECT_CREATION_COOKIE = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(7)

'//
'// WPD_EVENT_PARAMETER_CHILD_HIERARCHY_CHANGED
'//   [ VT_BOOL ] Indicates that the child hiearchy for the object has changed.
MACRO WPD_EVENT_PARAMETER_CHILD_HIERARCHY_CHANGED = GUID$("{15AB1953-F817-4FEF-A921-5676E838F6E0}") & MKDWD$(8)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_EVENT_PROPERTIES_V2
'*
'* The properties in this category are for properties that may be needed for event processing, but do not have object property equivalents (i.e. they are not exposed as object properties, but rather, used only as event parameters).
'****************************************************************************/
$WPD_EVENT_PROPERTIES_V2 = GUID$("{52807B8A-4914-4323-9B9A-74F654B2B846}")

'//
'// WPD_EVENT_PARAMETER_SERVICE_METHOD_CONTEXT
'//   [ VT_LPWSTR ] Indicates the service method invocation context.
MACRO WPD_EVENT_PARAMETER_SERVICE_METHOD_CONTEXT = GUID$("{52807B8A-4914-4323-9B9A-74F654B2B846}") & MKDWD$(2)


'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_EVENT_OPTIONS_V1
'*
'* The properties in this category describe event options.
'****************************************************************************/
$WPD_EVENT_OPTIONS_V1 = GUID$("{B3D8DAD7-A361-4B83-8A48-5B02CE10713B}")

'//
'// WPD_EVENT_OPTION_IS_BROADCAST_EVENT
'//   [ VT_BOOL ] Indicates that the event is broadcast to all clients.
MACRO WPD_EVENT_OPTION_IS_BROADCAST_EVENT = GUID$("{B3D8DAD7-A361-4B83-8A48-5B02CE10713B}") & MKDWD$(2)

'//
'// WPD_EVENT_OPTION_IS_AUTOPLAY_EVENT
'//   [ VT_BOOL ] Indicates that the event is sent to and handled by Autoplay.
MACRO WPD_EVENT_OPTION_IS_AUTOPLAY_EVENT = GUID$("{B3D8DAD7-A361-4B83-8A48-5B02CE10713B}") & MKDWD$(3)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_EVENT_ATTRIBUTES_V1
'*
'* The properties in this category describe event attributes.
'****************************************************************************/
$WPD_EVENT_ATTRIBUTES_V1 = GUID$("{10C96578-2E81-4111-ADDE-E08CA6138F6D}")

'//
'// WPD_EVENT_ATTRIBUTE_NAME
'//   [ VT_LPWSTR ] Contains the name of the event.
MACRO WPD_EVENT_ATTRIBUTE_NAME = GUID$("{10C96578-2E81-4111-ADDE-E08CA6138F6D}") & MKDWD$(2)

'//
'// WPD_EVENT_ATTRIBUTE_PARAMETERS
'//   [ VT_UNKNOWN ] IPortableDeviceKeyCollection containing the event parameters.
MACRO WPD_EVENT_ATTRIBUTE_PARAMETERS = GUID$("{10C96578-2E81-4111-ADDE-E08CA6138F6D}") & MKDWD$(3)

'//
'// WPD_EVENT_ATTRIBUTE_OPTIONS
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the event options.
MACRO WPD_EVENT_ATTRIBUTE_OPTIONS = GUID$("{10C96578-2E81-4111-ADDE-E08CA6138F6D}") & MKDWD$(4)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_API_OPTIONS_V1
'*
'* The properties in this category describe API options.
'****************************************************************************/
$WPD_API_OPTIONS_V1 = GUID$("{10E54A3E-052D-4777-A13C-DE7614BE2BC4}")

'//
'// WPD_API_OPTION_USE_CLEAR_DATA_STREAM
'//   [ VT_BOOL ] Indicates that the data stream created for data transfer will be clear only (i.e. No DRM will be involved).
MACRO WPD_API_OPTION_USE_CLEAR_DATA_STREAM = GUID$("{10E54A3E-052D-4777-A13C-DE7614BE2BC4}") & MKDWD$(2)

'//
'// WPD_API_OPTION_IOCTL_ACCESS
'//   [ VT_UI4 ] An optional property that clients can add to the IN parameter set of IPortableDevice::SendCommand to specify
'//   the access required for the command. The Portable Device API uses this to identify whether the IOCTL sent to the driver is sent with FILE_READ_ACCESS or (FILE_READ_ACCESS | FILE_WRITE_ACCESS) access flags.
MACRO WPD_API_OPTION_IOCTL_ACCESS = GUID$("{10E54A3E-052D-4777-A13C-DE7614BE2BC4}") & MKDWD$(3)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_FORMAT_ATTRIBUTES_V1
'*
'* The properties in this category describe format attributes.
'****************************************************************************/
$WPD_FORMAT_ATTRIBUTES_V1 = GUID$("{A0A02000-BCAF-4BE8-B3F5-233F231CF58F}")

'//
'// WPD_FORMAT_ATTRIBUTE_NAME
'//   [ VT_LPWSTR ] Contains the name of the format.
MACRO WPD_FORMAT_ATTRIBUTE_NAME = GUID$("{A0A02000-BCAF-4BE8-B3F5-233F231CF58F}") & MKDWD$(2)

'//
'// WPD_FORMAT_ATTRIBUTE_MIMETYPE
'//   [ VT_LPWSTR ] Contains the MIME type of the format.
MACRO WPD_FORMAT_ATTRIBUTE_MIMETYPE = GUID$("{A0A02000-BCAF-4BE8-B3F5-233F231CF58F}") & MKDWD$(3)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_METHOD_ATTRIBUTES_V1
'*
'* The properties in this category describe method attributes.
'****************************************************************************/
$WPD_METHOD_ATTRIBUTES_V1 = GUID$("{F17A5071-F039-44AF-8EFE-432CF32E432A}")

'//
'// WPD_METHOD_ATTRIBUTE_NAME
'//   [ VT_LPWSTR ] Contains the name of the method.
MACRO WPD_METHOD_ATTRIBUTE_NAME = GUID$("{F17A5071-F039-44AF-8EFE-432CF32E432A}") & MKDWD$(2)

'//
'// WPD_METHOD_ATTRIBUTE_ASSOCIATED_FORMAT
'//   [ VT_CLSID ] Contains the format this method applies to. This is GUID_NULL if the method does not apply to a format.
MACRO WPD_METHOD_ATTRIBUTE_ASSOCIATED_FORMAT = GUID$("{F17A5071-F039-44AF-8EFE-432CF32E432A}") & MKDWD$(3)

'//
'// WPD_METHOD_ATTRIBUTE_ACCESS
'//   [ VT_UI4 ] Indicates the required access for a method.
MACRO WPD_METHOD_ATTRIBUTE_ACCESS = GUID$("{F17A5071-F039-44AF-8EFE-432CF32E432A}") & MKDWD$(4)

'//
'// WPD_METHOD_ATTRIBUTE_PARAMETERS
'//   [ VT_UNKNOWN ] This is an IPortableDeviceKeyCollection containing the method parameters.
MACRO WPD_METHOD_ATTRIBUTE_PARAMETERS = GUID$("{F17A5071-F039-44AF-8EFE-432CF32E432A}") & MKDWD$(5)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_PARAMETER_ATTRIBUTES_V1
'*
'* The properties in this category describe parameter attributes.
'****************************************************************************/
$WPD_PARAMETER_ATTRIBUTES_V1 = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}")

'//
'// WPD_PARAMETER_ATTRIBUTE_ORDER
'//   [ VT_UI4 ] The order (starting from 0) of a method parameter.
MACRO WPD_PARAMETER_ATTRIBUTE_ORDER = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(2)

'//
'// WPD_PARAMETER_ATTRIBUTE_USAGE
'//   [ VT_UI4 ] The usage of the method parameter.
MACRO WPD_PARAMETER_ATTRIBUTE_USAGE = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(3)

'//
'// WPD_PARAMETER_ATTRIBUTE_FORM
'//   [ VT_UI4 ] Specifies the form of the valid values allowed for this parameter.
MACRO WPD_PARAMETER_ATTRIBUTE_FORM = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(4)

'//
'// WPD_PARAMETER_ATTRIBUTE_DEFAULT_VALUE
'//   [ VT_XXXX ] Specifies the default value for this parameter.
MACRO WPD_PARAMETER_ATTRIBUTE_DEFAULT_VALUE = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(5)

'//
'// WPD_PARAMETER_ATTRIBUTE_RANGE_MIN
'//   [ VT_XXXX ] The minimum value for a parameter whose form is of WPD_PARAMETER_ATTRIBUTE_FORM_RANGE.
MACRO WPD_PARAMETER_ATTRIBUTE_RANGE_MIN = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(6)

'//
'// WPD_PARAMETER_ATTRIBUTE_RANGE_MAX
'//   [ VT_XXXX ] The maximum value for a parameter whose form is of WPD_PARAMETER_ATTRIBUTE_FORM_RANGE.
MACRO WPD_PARAMETER_ATTRIBUTE_RANGE_MAX = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(7)

'//
'// WPD_PARAMETER_ATTRIBUTE_RANGE_STEP
'//   [ VT_XXXX ] The step value for a parameter whose form is of WPD_PARAMETER_ATTRIBUTE_FORM_RANGE.
MACRO WPD_PARAMETER_ATTRIBUTE_RANGE_STEP = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(8)

'//
'// WPD_PARAMETER_ATTRIBUTE_ENUMERATION_ELEMENTS
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection containing the enumeration values.
MACRO WPD_PARAMETER_ATTRIBUTE_ENUMERATION_ELEMENTS = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(9)

'//
'// WPD_PARAMETER_ATTRIBUTE_REGULAR_EXPRESSION
'//   [ VT_LPWSTR ] A regular expression string indicating acceptable values for parameters whose form is WPD_PARAMETER_ATTRIBUTE_FORM_REGULAR_EXPRESSION.
MACRO WPD_PARAMETER_ATTRIBUTE_REGULAR_EXPRESSION = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(10)

'//
'// WPD_PARAMETER_ATTRIBUTE_MAX_SIZE
'//   [ VT_UI8 ] This indicates the maximum size (in bytes) for the value of this parameter.
MACRO WPD_PARAMETER_ATTRIBUTE_MAX_SIZE = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(11)

'//
'// WPD_PARAMETER_ATTRIBUTE_VARTYPE
'//   [ VT_UI4 ] Contains the VARTYPE of the parameter.
MACRO WPD_PARAMETER_ATTRIBUTE_VARTYPE = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(12)

'//
'// WPD_PARAMETER_ATTRIBUTE_NAME
'//   [ VT_LPWSTR ] Contains the parameter name.
MACRO WPD_PARAMETER_ATTRIBUTE_NAME = GUID$("{E6864DD7-F325-45EA-A1D5-97CF73B6CA58}") & MKDWD$(13)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_COMMON
'*
'*
'****************************************************************************/
$WPD_CATEGORY_COMMON = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}")

'// ======== Commands ========

'//
'// WPD_COMMAND_COMMON_RESET_DEVICE
'//     This command is sent by clients to reset the device.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     None
'//  Results:
'//     None
MACRO WPD_COMMAND_COMMON_RESET_DEVICE = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(2)

'//
'// WPD_COMMAND_COMMON_GET_OBJECT_IDS_FROM_PERSISTENT_UNIQUE_IDS
'//     This command is sent when a client wants to get current ObjectIDs representing objects specified by previously acquired Persistent Unique IDs.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_PERSISTENT_UNIQUE_IDS
'//  Results:
'//     [ Required ] WPD_PROPERTY_COMMON_OBJECT_IDS
MACRO WPD_COMMAND_COMMON_GET_OBJECT_IDS_FROM_PERSISTENT_UNIQUE_IDS = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(3)

'//
'// WPD_COMMAND_COMMON_SAVE_CLIENT_INFORMATION
'//     This command is sent when a client first connects to a device.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_COMMON_CLIENT_INFORMATION
'//  Results:
'//     [ Optional ] WPD_PROPERTY_COMMON_CLIENT_INFORMATION_CONTEXT
MACRO WPD_COMMAND_COMMON_SAVE_CLIENT_INFORMATION = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(4)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_COMMON_COMMAND_CATEGORY
'//   [ VT_CLSID ] Specifies the command Category (i.e. the GUID portion of the PROPERTYKEY indicating the command).
MACRO WPD_PROPERTY_COMMON_COMMAND_CATEGORY = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_COMMON_COMMAND_ID
'//   [ VT_UI4 ] Specifies the command ID, which is the PID portion of the PROPERTYKEY indicating the command.
MACRO WPD_PROPERTY_COMMON_COMMAND_ID = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_COMMON_HRESULT
'//   [ VT_ERROR ] The driver sets this to be the HRESULT of the requested operation.
MACRO WPD_PROPERTY_COMMON_HRESULT = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_COMMON_DRIVER_ERROR_CODE
'//   [ VT_UI4 ] Special driver specific code which driver may return on error. Typically only for use with diagnostic tools or vertical solutions.
MACRO WPD_PROPERTY_COMMON_DRIVER_ERROR_CODE = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_COMMON_COMMAND_TARGET
'//   [ VT_LPWSTR ] Identifies the object which the command is intended for.
MACRO WPD_PROPERTY_COMMON_COMMAND_TARGET = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1006)

'//
'// WPD_PROPERTY_COMMON_PERSISTENT_UNIQUE_IDS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_LPWSTR specifying list of Persistent Unique IDs.
MACRO WPD_PROPERTY_COMMON_PERSISTENT_UNIQUE_IDS = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1007)

'//
'// WPD_PROPERTY_COMMON_OBJECT_IDS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_LPWSTR specifying list of Objects IDs.
MACRO WPD_PROPERTY_COMMON_OBJECT_IDS = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1008)

'//
'// WPD_PROPERTY_COMMON_CLIENT_INFORMATION
'//   [ VT_UNKNOWN ] IPortableDeviceValues used to identify itself to the driver.
MACRO WPD_PROPERTY_COMMON_CLIENT_INFORMATION = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1009)

'//
'// WPD_PROPERTY_COMMON_CLIENT_INFORMATION_CONTEXT
'//   [ VT_LPWSTR ] Driver specified context which will be sent for the particular client on all subsequent operations.
MACRO WPD_PROPERTY_COMMON_CLIENT_INFORMATION_CONTEXT = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(1010)

'// ======== Command Options ========

'//
'// WPD_OPTION_VALID_OBJECT_IDS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_LPWSTR specifying list of Objects IDs of the objects that support the command.
MACRO WPD_OPTION_VALID_OBJECT_IDS = GUID$("{F0422A9C-5DC8-4440-B5BD-5DF28835658A}") & MKDWD$(5001)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_OBJECT_ENUMERATION
'*
'* The commands in this category are used for basic object enumeration.
'****************************************************************************/
$WPD_CATEGORY_OBJECT_ENUMERATION = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}")

'// ======== Commands ========

'//
'// WPD_COMMAND_OBJECT_ENUMERATION_START_FIND
'//     The driver receives this command when a client wishes to start enumeration.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_ENUMERATION_PARENT_ID
'//     [ Optional ] WPD_PROPERTY_OBJECT_ENUMERATION_FILTER
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_ENUMERATION_CONTEXT
MACRO WPD_COMMAND_OBJECT_ENUMERATION_START_FIND = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(2)

'//
'// WPD_COMMAND_OBJECT_ENUMERATION_FIND_NEXT
'//     This command is used when the client requests the next batch of ObjectIDs during enumeration. Only objects that match the constraints set up in WPD_COMMAND_OBJECT_ENUMERATION_START_FIND should be returned.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_ENUMERATION_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_ENUMERATION_NUM_OBJECTS_REQUESTED
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_ENUMERATION_OBJECT_IDS
MACRO WPD_COMMAND_OBJECT_ENUMERATION_FIND_NEXT = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(3)

'//
'// WPD_COMMAND_OBJECT_ENUMERATION_END_FIND
'//     The driver should destroy any resources associated with this enumeration context.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_ENUMERATION_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_ENUMERATION_END_FIND = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(4)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_OBJECT_ENUMERATION_PARENT_ID
'//   [ VT_LPWSTR ] The ObjectID specifying the parent object where enumeration should start.
MACRO WPD_PROPERTY_OBJECT_ENUMERATION_PARENT_ID = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_OBJECT_ENUMERATION_FILTER
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which specifies the properties used to filter on. If the caller does not want filtering, then this value will not be set.
MACRO WPD_PROPERTY_OBJECT_ENUMERATION_FILTER = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_OBJECT_ENUMERATION_OBJECT_IDS
'//   [ VT_UNKNOWN ] This is an IPortableDevicePropVariantCollection of ObjectIDs (of type VT_LPWSTR). If 0 objects are returned, this should be an empty collection, not NULL.
MACRO WPD_PROPERTY_OBJECT_ENUMERATION_OBJECT_IDS = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_OBJECT_ENUMERATION_CONTEXT
'//   [ VT_LPWSTR ] This is a driver-specified identifier for the context associated with this enumeration.
MACRO WPD_PROPERTY_OBJECT_ENUMERATION_CONTEXT = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_OBJECT_ENUMERATION_NUM_OBJECTS_REQUESTED
'//   [ VT_UI4 ] The maximum number of ObjectIDs to return back to the client.
MACRO WPD_PROPERTY_OBJECT_ENUMERATION_NUM_OBJECTS_REQUESTED = GUID$("{B7474E91-E7F8-4AD9-B400-AD1A4B58EEEC}") & MKDWD$(1005)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_OBJECT_PROPERTIES
'*
'* This category of commands is used to perform basic property operations such as Reading/Writing values, listing supported values and so on.
'****************************************************************************/
$WPD_CATEGORY_OBJECT_PROPERTIES = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}")

'// ======== Commands ========

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_GET_SUPPORTED
'//     This command is used when the client requests the list of properties supported by the specified object.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_KEYS
MACRO WPD_COMMAND_OBJECT_PROPERTIES_GET_SUPPORTED = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(2)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_GET_ATTRIBUTES
'//     This command is used when the client requests the property attributes for the specified object properties.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_ATTRIBUTES
MACRO WPD_COMMAND_OBJECT_PROPERTIES_GET_ATTRIBUTES = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(3)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_GET
'//     This command is used when the client requests a set of property values for the specified object.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_VALUES
MACRO WPD_COMMAND_OBJECT_PROPERTIES_GET = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(4)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_SET
'//     This command is used when the client requests to write a set of property values on the specified object.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_VALUES
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_WRITE_RESULTS
MACRO WPD_COMMAND_OBJECT_PROPERTIES_SET = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(5)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_GET_ALL
'//     This command is used when the client requests all property values for the specified object.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_VALUES
MACRO WPD_COMMAND_OBJECT_PROPERTIES_GET_ALL = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(6)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_DELETE
'//     This command is sent when the caller wants to delete properties from the specified object.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_KEYS
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_PROPERTIES_DELETE = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(7)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID
'//   [ VT_LPWSTR ] The ObjectID specifying the object whose properties are being queried/manipulated.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_OBJECT_ID = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_KEYS
'//   [ VT_UNKNOWN ] An IPortableDeviceKeyCollection identifying which specific property values we are querying/manipulating.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_KEYS = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_ATTRIBUTES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the attributes for each property requested.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_ATTRIBUTES = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_VALUES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the values read. For any property whose value could not be read, the type must be set to VT_ERROR, and the 'scode' field must contain the failure HRESULT.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_VALUES = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_WRITE_RESULTS
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the result of each property write operation.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_WRITE_RESULTS = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(1005)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_DELETE_RESULTS
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the result of each property delete operation.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_PROPERTY_DELETE_RESULTS = GUID$("{9E5582E4-0814-44E6-981A-B2998D583804}") & MKDWD$(1006)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_OBJECT_PROPERTIES_BULK
'*
'* This category contains commands and properties for property operations across multiple objects.
'****************************************************************************/
$WPD_CATEGORY_OBJECT_PROPERTIES_BULK = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}")

'// ======== Commands ========

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_START
'//     Initializes the operation to get the property values for all caller-specified objects.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_OBJECT_IDS
'//     [ Optional ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PROPERTY_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_START = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(2)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_NEXT
'//     Get the next set of property values.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_VALUES
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_NEXT = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(3)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_END
'//     Ends the bulk property operation for getting property values by object list.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_END = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(4)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_START
'//     Initializes the operation to get the property values for objects of the specified format
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_OBJECT_FORMAT
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PARENT_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_DEPTH
'//     [ Optional ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PROPERTY_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_START = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(5)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_NEXT
'//     Get the next set of property values.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_VALUES
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_NEXT = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(6)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_END
'//     Ends the bulk property operation for getting property values by object format.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_END = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(7)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_START
'//     Initializes the operation to set the property values for specified objects.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_VALUES
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_START = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(8)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_NEXT
'//     Set the next set of property values.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_WRITE_RESULTS
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_NEXT = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(9)

'//
'// WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_END
'//     Ends the bulk property operation for setting property values by object list.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_END = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(10)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_OBJECT_IDS
'//   [ VT_UNKNOWN ] A collection of ObjectIDs for which supported property list must be returned.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_OBJECT_IDS = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT
'//   [ VT_LPWSTR ] The driver-specified context identifying this particular bulk operation.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_CONTEXT = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_VALUES
'//   [ VT_UNKNOWN ] Contains an IPortableDeviceValuesCollection specifying the next set of IPortableDeviceValues elements.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_VALUES = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PROPERTY_KEYS
'//   [ VT_UNKNOWN ] Contains an IPortableDeviceKeyCollection specifying which properties the caller wants to return. May not exist, which indicates caller wants ALL properties.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PROPERTY_KEYS = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_DEPTH
'//   [ VT_UI4 ] Contains a value specifying the hierarchical depth from the parent to include in this operation.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_DEPTH = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1005)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PARENT_OBJECT_ID
'//   [ VT_LPWSTR ] Contains the ObjectID of the object to start the operation from.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_PARENT_OBJECT_ID = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1006)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_OBJECT_FORMAT
'//   [ VT_CLSID ] Specifies the object format the client is interested in.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_OBJECT_FORMAT = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1007)

'//
'// WPD_PROPERTY_OBJECT_PROPERTIES_BULK_WRITE_RESULTS
'//   [ VT_UNKNOWN ] Contains an IPortableDeviceValuesCollection specifying the set of IPortableDeviceValues elements indicating the write results for each property set.
MACRO WPD_PROPERTY_OBJECT_PROPERTIES_BULK_WRITE_RESULTS = GUID$("{11C824DD-04CD-4E4E-8C7B-F6EFB794D84E}") & MKDWD$(1008)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_OBJECT_RESOURCES
'*
'* The commands in this category are used for basic object resource enumeration and transfer.
'****************************************************************************/
$WPD_CATEGORY_OBJECT_RESOURCES = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}")

'// ======== Commands ========

'//
'// WPD_COMMAND_OBJECT_RESOURCES_GET_SUPPORTED
'//     This command is sent when a client wants to get the list of resources supported on a particular object.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_OBJECT_ID
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_KEYS
MACRO WPD_COMMAND_OBJECT_RESOURCES_GET_SUPPORTED = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(2)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_GET_ATTRIBUTES
'//     This command is used when the client requests the attributes for the specified object resource.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_ATTRIBUTES
MACRO WPD_COMMAND_OBJECT_RESOURCES_GET_ATTRIBUTES = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(3)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_OPEN
'//     This command is sent when a client wants to use a particular resource on an object.
'//  Access:
'//     Dependent on the value of WPD_PROPERTY_OBJECT_RESOURCES_ACCESS_MODE. STGM_READ will indicate FILE_READ_ACCESS for the command, anything else will indicate (FILE_READ_ACCESS | FILE_WRITE_ACCESS).
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_KEYS
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_ACCESS_MODE
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_OPTIMAL_TRANSFER_BUFFER_SIZE
MACRO WPD_COMMAND_OBJECT_RESOURCES_OPEN = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(4)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_READ
'//     This command is sent when a client wants to read the next band of data from a previously opened object resource.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_TO_READ
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_DATA
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_READ
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_DATA
MACRO WPD_COMMAND_OBJECT_RESOURCES_READ = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(5)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_WRITE
'//     This command is sent when a client wants to write the next band of data to a previously opened object resource.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_TO_WRITE
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_DATA
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_WRITTEN
MACRO WPD_COMMAND_OBJECT_RESOURCES_WRITE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(6)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_CLOSE
'//     This command is sent when a client is finished transferring data to a previously opened object resource.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_RESOURCES_CLOSE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(7)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_DELETE
'//     This command is sent when the client wants to delete the data associated with the specified resources from the specified object.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_KEYS
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_RESOURCES_DELETE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(8)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_CREATE_RESOURCE
'//     This command is sent when a client wants to create a new object resource on the device.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_ATTRIBUTES
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_OPTIMAL_TRANSFER_BUFFER_SIZE
MACRO WPD_COMMAND_OBJECT_RESOURCES_CREATE_RESOURCE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(9)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_REVERT
'//     This command is sent when a client wants to cancel the resource creation request that is currently still in progress.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_RESOURCES_REVERT = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(10)

'//
'// WPD_COMMAND_OBJECT_RESOURCES_SEEK
'//     This command is sent when a client wants to seek to a specific offset in the data stream.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_SEEK_OFFSET
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_SEEK_ORIGIN_FLAG
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_RESOURCES_POSITION_FROM_START
MACRO WPD_COMMAND_OBJECT_RESOURCES_SEEK = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(11)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_OBJECT_ID
'//   [ VT_LPWSTR ]
MACRO WPD_PROPERTY_OBJECT_RESOURCES_OBJECT_ID = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_ACCESS_MODE
'//   [ VT_UI4 ] Specifies the type of access the client is requesting for the resource.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_ACCESS_MODE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_KEYS
'//   [ VT_UNKNOWN ]
MACRO WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_KEYS = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_ATTRIBUTES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the attributes for the resource requested.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_RESOURCE_ATTRIBUTES = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT
'//   [ VT_LPWSTR] This is a driver-specified identifier for the context associated with the resource operation.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_CONTEXT = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1005)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_TO_READ
'//   [ VT_UI4 ] Specifies the number of bytes the client is requesting to read.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_TO_READ = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1006)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_READ
'//   [ VT_UI4 ] Specifies the number of bytes actually read from the resource.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_READ = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1007)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_TO_WRITE
'//   [ VT_UI4 ] Specifies the number of bytes the client is requesting to write.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_TO_WRITE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1008)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_WRITTEN
'//   [ VT_UI4 ] Driver sets this to let caller know how many bytes were actually written.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_NUM_BYTES_WRITTEN = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1009)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_DATA
'//   [ VT_VECTOR|VT_UI1 ]
MACRO WPD_PROPERTY_OBJECT_RESOURCES_DATA = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1010)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_OPTIMAL_TRANSFER_BUFFER_SIZE
'//   [ VT_UI4 ] Indicates the optimal transfer buffer size (in bytes) that clients should use when reading/writing this resource.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_OPTIMAL_TRANSFER_BUFFER_SIZE = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1011)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_SEEK_OFFSET
'//   [ VT_I8 ] Displacement to be added to the location indicated by the WPD_PROPERTY_OBJECT_RESOURCES_SEEK_ORIGIN_FLAG parameter.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_SEEK_OFFSET = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1012)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_SEEK_ORIGIN_FLAG
'//   [ VT_UI4 ] Specifies the origin of the displacement for the seek operation.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_SEEK_ORIGIN_FLAG = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1013)

'//
'// WPD_PROPERTY_OBJECT_RESOURCES_POSITION_FROM_START
'//   [ VT_UI8 ] Value of the new seek pointer from the beginning of the data stream.
MACRO WPD_PROPERTY_OBJECT_RESOURCES_POSITION_FROM_START = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(1014)

'// ======== Command Options ========

'//
'// WPD_OPTION_OBJECT_RESOURCES_SEEK_ON_READ_SUPPORTED
'//   [ VT_BOOL ] Indicates whether the driver can Seek on a resource opened for Read access.
MACRO WPD_OPTION_OBJECT_RESOURCES_SEEK_ON_READ_SUPPORTED = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(5001)

'//
'// WPD_OPTION_OBJECT_RESOURCES_SEEK_ON_WRITE_SUPPORTED
'//   [ VT_BOOL ] Indicates whether the driver can Seek on a resource opened for Write access.
MACRO WPD_OPTION_OBJECT_RESOURCES_SEEK_ON_WRITE_SUPPORTED = GUID$("{B3A2B22D-A595-4108-BE0A-FC3C965F3D4A}") & MKDWD$(5002)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_OBJECT_MANAGEMENT
'*
'* The commands specified in this category are used to Create/Delete objects on the device.
'****************************************************************************/
$WPD_CATEGORY_OBJECT_MANAGEMENT = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}")

'// ======== Commands ========

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_CREATE_OBJECT_WITH_PROPERTIES_ONLY
'//     This command is sent when a client wants to create a new object on the device, specified only by properties.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CREATION_PROPERTIES
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_ID
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_CREATE_OBJECT_WITH_PROPERTIES_ONLY = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(2)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_CREATE_OBJECT_WITH_PROPERTIES_AND_DATA
'//     This command is sent when a client wants to create a new object on the device, specified by properties and data.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CREATION_PROPERTIES
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_CREATE_OBJECT_WITH_PROPERTIES_AND_DATA = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(3)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_WRITE_OBJECT_DATA
'//     This command is sent when a client wants to write the next band of data to a newly created object.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_NUM_BYTES_TO_WRITE
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_DATA
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_NUM_BYTES_WRITTEN
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_WRITE_OBJECT_DATA = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(4)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_COMMIT_OBJECT
'//     This command is sent when a client has finished sending all the data associated with an object creation request, and wishes to ensure that the object is saved to the device.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_ID
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_COMMIT_OBJECT = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(5)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_REVERT_OBJECT
'//     This command is sent when a client wants to cancel the object creation request that is currently still in progress.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_REVERT_OBJECT = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(6)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_DELETE_OBJECTS
'//     This command is sent when the client wishes to remove a set of objects from the device.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_DELETE_OPTIONS
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_IDS
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_DELETE_RESULTS
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_DELETE_OBJECTS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(7)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_MOVE_OBJECTS
'//     This command will move the specified objects to the destination folder.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_IDS
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_DESTINATION_FOLDER_OBJECT_ID
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_MOVE_RESULTS
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_MOVE_OBJECTS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(8)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_COPY_OBJECTS
'//     This command will copy the specified objects to the destination folder.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_IDS
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_DESTINATION_FOLDER_OBJECT_ID
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_COPY_RESULTS
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_COPY_OBJECTS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(9)

'//
'// WPD_COMMAND_OBJECT_MANAGEMENT_UPDATE_OBJECT_WITH_PROPERTIES_AND_DATA
'//     This command is sent when a client wants to update the object's data and dependent properties simultaneously.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_UPDATE_PROPERTIES
'//  Results:
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT
'//     [ Required ] WPD_PROPERTY_OBJECT_MANAGEMENT_OPTIMAL_TRANSFER_BUFFER_SIZE
MACRO WPD_COMMAND_OBJECT_MANAGEMENT_UPDATE_OBJECT_WITH_PROPERTIES_AND_DATA = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(10)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_CREATION_PROPERTIES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which specifies the properties used to create the new object.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_CREATION_PROPERTIES = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT
'//   [ VT_LPWSTR ] This is a driver-specified identifier for the context associated with this 'create object' operation.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_CONTEXT = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_NUM_BYTES_TO_WRITE
'//   [ VT_UI4 ] Specifies the number of bytes the client is requesting to write.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_NUM_BYTES_TO_WRITE = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_NUM_BYTES_WRITTEN
'//   [ VT_UI4 ] Indicates the number of bytes written for the object.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_NUM_BYTES_WRITTEN = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_DATA
'//   [ VT_VECTOR|VT_UI1 ] Indicates binary data of the object being created on the device.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_DATA = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1005)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_ID
'//   [ VT_LPWSTR ] Identifies a newly created object on the device.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_ID = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1006)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_DELETE_OPTIONS
'//   [ VT_UI4 ] Indicates if the delete operation should be recursive or not.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_DELETE_OPTIONS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1007)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_OPTIMAL_TRANSFER_BUFFER_SIZE
'//   [ VT_UI4 ] Indicates the optimal transfer buffer size (in bytes) that clients should use when writing this object's data.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_OPTIMAL_TRANSFER_BUFFER_SIZE = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1008)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_IDS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_LPWSTR, containing the ObjectIDs to delete.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_IDS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1009)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_DELETE_RESULTS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_ERROR, where each element is the HRESULT indicating the success or failure of the operation.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_DELETE_RESULTS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1010)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_DESTINATION_FOLDER_OBJECT_ID
'//   [ VT_LPWSTR ] Indicates the destination folder for the move operation.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_DESTINATION_FOLDER_OBJECT_ID = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1011)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_MOVE_RESULTS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_ERROR, where each element is the HRESULT indicating the success or failure of the operation.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_MOVE_RESULTS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1012)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_COPY_RESULTS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of type VT_ERROR, where each element is the HRESULT indicating the success or failure of the operation.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_COPY_RESULTS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1013)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_UPDATE_PROPERTIES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the object properties to update.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_UPDATE_PROPERTIES = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1014)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_PROPERTY_KEYS
'//   [ VT_UNKNOWN ] IPortableDeviceKeyCollection containing the property keys required to update this object.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_PROPERTY_KEYS = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1015)

'//
'// WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_FORMAT
'//   [ VT_CLSID ] Indicates the object format the caller is interested in.
MACRO WPD_PROPERTY_OBJECT_MANAGEMENT_OBJECT_FORMAT = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(1016)

'// ======== Command Options ========

'//
'// WPD_OPTION_OBJECT_MANAGEMENT_RECURSIVE_DELETE_SUPPORTED
'//   [ VT_BOOL ] Indicates whether the driver supports recursive deletion.
MACRO WPD_OPTION_OBJECT_MANAGEMENT_RECURSIVE_DELETE_SUPPORTED = GUID$("{EF1E43DD-A9ED-4341-8BCC-186192AEA089}") & MKDWD$(5001)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_CAPABILITIES
'*
'* This command category is used to query capabilities of the device.
'****************************************************************************/
$WPD_CATEGORY_CAPABILITIES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}")

'// ======== Commands ========

'//
'// WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_COMMANDS
'//     Return all commands supported by this driver. This includes custom commands, if any.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_SUPPORTED_COMMANDS
MACRO WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_COMMANDS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(2)

'//
'// WPD_COMMAND_CAPABILITIES_GET_COMMAND_OPTIONS
'//     Returns the supported options for the specified command.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_COMMAND
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_COMMAND_OPTIONS
MACRO WPD_COMMAND_CAPABILITIES_GET_COMMAND_OPTIONS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(3)

'//
'// WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FUNCTIONAL_CATEGORIES
'//     This command is used by clients to query the functional categories supported by the driver.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORIES
MACRO WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FUNCTIONAL_CATEGORIES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(4)

'//
'// WPD_COMMAND_CAPABILITIES_GET_FUNCTIONAL_OBJECTS
'//     Retrieves the ObjectIDs of the objects belonging to the specified functional category.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORY
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_OBJECTS
MACRO WPD_COMMAND_CAPABILITIES_GET_FUNCTIONAL_OBJECTS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(5)

'//
'// WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_CONTENT_TYPES
'//     Retrieves the list of content types supported by this driver for the specified functional category.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORY
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_CONTENT_TYPES
MACRO WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_CONTENT_TYPES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(6)

'//
'// WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FORMATS
'//     This command is used to query the possible formats supported by the specified content type (e.g. for image objects, the driver may choose to support JPEG and BMP files).
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_CONTENT_TYPE
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FORMATS
MACRO WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FORMATS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(7)

'//
'// WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FORMAT_PROPERTIES
'//     Get the list of properties that an object of the given format supports.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FORMAT
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_PROPERTY_KEYS
MACRO WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FORMAT_PROPERTIES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(8)

'//
'// WPD_COMMAND_CAPABILITIES_GET_FIXED_PROPERTY_ATTRIBUTES
'//     Returns the property attributes that are the same for all objects of the given format.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_FORMAT
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_PROPERTY_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_PROPERTY_ATTRIBUTES
MACRO WPD_COMMAND_CAPABILITIES_GET_FIXED_PROPERTY_ATTRIBUTES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(9)

'//
'// WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_EVENTS
'//     Return all events supported by this driver. This includes custom events, if any.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_SUPPORTED_EVENTS
MACRO WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_EVENTS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(10)

'//
'// WPD_COMMAND_CAPABILITIES_GET_EVENT_OPTIONS
'//     Return extra information about a specified event, such as whether the event is for notification or action purposes.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_EVENT
'//  Results:
'//     [ Required ] WPD_PROPERTY_CAPABILITIES_EVENT_OPTIONS
MACRO WPD_COMMAND_CAPABILITIES_GET_EVENT_OPTIONS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(11)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_CAPABILITIES_SUPPORTED_COMMANDS
'//   [ VT_UNKNOWN ] IPortableDeviceKeyCollection containing all commands a driver supports.
MACRO WPD_PROPERTY_CAPABILITIES_SUPPORTED_COMMANDS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_CAPABILITIES_COMMAND
'//   [ VT_UNKNOWN ] Indicates the command whose options the caller is interested in.
MACRO WPD_PROPERTY_CAPABILITIES_COMMAND = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_CAPABILITIES_COMMAND_OPTIONS
'//   [ VT_UNKNOWN ] Contains an IPortableDeviceValues with the relevant command options.
MACRO WPD_PROPERTY_CAPABILITIES_COMMAND_OPTIONS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORIES
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection of type VT_CLSID which indicates the functional categories supported by the driver.
MACRO WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORIES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORY
'//   [ VT_CLSID ] The category the caller is interested in.
MACRO WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_CATEGORY = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1005)

'//
'// WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_OBJECTS
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection (of type VT_LPWSTR) containing the ObjectIDs of the functional objects who belong to the specified functional category.
MACRO WPD_PROPERTY_CAPABILITIES_FUNCTIONAL_OBJECTS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1006)

'//
'// WPD_PROPERTY_CAPABILITIES_CONTENT_TYPES
'//   [ VT_UNKNOWN ] Indicates list of content types supported for the specified functional category.
MACRO WPD_PROPERTY_CAPABILITIES_CONTENT_TYPES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1007)

'//
'// WPD_PROPERTY_CAPABILITIES_CONTENT_TYPE
'//   [ VT_CLSID ] Indicates the content type whose formats the caller is interested in.
MACRO WPD_PROPERTY_CAPABILITIES_CONTENT_TYPE = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1008)

'//
'// WPD_PROPERTY_CAPABILITIES_FORMATS
'//   [ VT_UNKNOWN ] An IPortableDevicePropVariantCollection of VT_CLSID values indicating the formats supported for the specified content type.
MACRO WPD_PROPERTY_CAPABILITIES_FORMATS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1009)

'//
'// WPD_PROPERTY_CAPABILITIES_FORMAT
'//   [ VT_CLSID ] Specifies the format the caller is interested in.
MACRO WPD_PROPERTY_CAPABILITIES_FORMAT = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1010)

'//
'// WPD_PROPERTY_CAPABILITIES_PROPERTY_KEYS
'//   [ VT_UNKNOWN ] An IPortableDeviceKeyCollection containing the property keys.
MACRO WPD_PROPERTY_CAPABILITIES_PROPERTY_KEYS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1011)

'//
'// WPD_PROPERTY_CAPABILITIES_PROPERTY_ATTRIBUTES
'//   [ VT_UNKNOWN ] An IPortableDeviceValues containing the property attributes.
MACRO WPD_PROPERTY_CAPABILITIES_PROPERTY_ATTRIBUTES = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1012)

'//
'// WPD_PROPERTY_CAPABILITIES_SUPPORTED_EVENTS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection of VT_CLSID values containing all events a driver supports.
MACRO WPD_PROPERTY_CAPABILITIES_SUPPORTED_EVENTS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1013)

'//
'// WPD_PROPERTY_CAPABILITIES_EVENT
'//   [ VT_CLSID ] Indicates the event the caller is interested in.
MACRO WPD_PROPERTY_CAPABILITIES_EVENT = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1014)

'//
'// WPD_PROPERTY_CAPABILITIES_EVENT_OPTIONS
'//   [ VT_UNKNOWN ] Contains an IPortableDeviceValues with the relevant event options.
MACRO WPD_PROPERTY_CAPABILITIES_EVENT_OPTIONS = GUID$("{0CABEC78-6B74-41C6-9216-2639D1FCE356}") & MKDWD$(1015)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CLASS_EXTENSION_V1
'*
'* The commands in this category relate to the WPD device class extension.
'****************************************************************************/
$WPD_CLASS_EXTENSION_V1 = GUID$("{33FB0D11-64A3-4FAC-B4C7-3DFEAA99B051}")

'// ======== Commands ========

'//
'// WPD_COMMAND_CLASS_EXTENSION_WRITE_DEVICE_INFORMATION
'//     This command is used to update the a cache of device-specific information.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_DEVICE_INFORMATION_VALUES
'//  Results:
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_DEVICE_INFORMATION_WRITE_RESULTS
MACRO WPD_COMMAND_CLASS_EXTENSION_WRITE_DEVICE_INFORMATION = GUID$("{33FB0D11-64A3-4FAC-B4C7-3DFEAA99B051}") & MKDWD$(2)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_CLASS_EXTENSION_DEVICE_INFORMATION_VALUES
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the values.
MACRO WPD_PROPERTY_CLASS_EXTENSION_DEVICE_INFORMATION_VALUES = GUID$("{33FB0D11-64A3-4FAC-B4C7-3DFEAA99B051}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_CLASS_EXTENSION_DEVICE_INFORMATION_WRITE_RESULTS
'//   [ VT_UNKNOWN ] This is an IPortableDeviceValues which contains the result of each value write operation.
MACRO WPD_PROPERTY_CLASS_EXTENSION_DEVICE_INFORMATION_WRITE_RESULTS = GUID$("{33FB0D11-64A3-4FAC-B4C7-3DFEAA99B051}") & MKDWD$(1002)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CLASS_EXTENSION_V2
'*
'* The commands in this category relate to the WPD device class extension.
'****************************************************************************/
$WPD_CLASS_EXTENSION_V2 = GUID$("{7F0779B5-FA2B-4766-9CB2-F73BA30B6758}")

'// ======== Commands ========

'//
'// WPD_COMMAND_CLASS_EXTENSION_REGISTER_SERVICE_INTERFACES
'//     This command is used to register a service's Plug and Play interfaces.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_SERVICE_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_SERVICE_INTERFACES
'//  Results:
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_SERVICE_REGISTRATION_RESULTS
MACRO WPD_COMMAND_CLASS_EXTENSION_REGISTER_SERVICE_INTERFACES = GUID$("{7F0779B5-FA2B-4766-9CB2-F73BA30B6758}") & MKDWD$(2)

'//
'// WPD_COMMAND_CLASS_EXTENSION_UNREGISTER_SERVICE_INTERFACES
'//     This command is used to unregister a service's Plug and Play interfaces.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_SERVICE_OBJECT_ID
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_SERVICE_INTERFACES
'//  Results:
'//     [ Required ] WPD_PROPERTY_CLASS_EXTENSION_SERVICE_REGISTRATION_RESULTS
MACRO WPD_COMMAND_CLASS_EXTENSION_UNREGISTER_SERVICE_INTERFACES = GUID$("{7F0779B5-FA2B-4766-9CB2-F73BA30B6758}") & MKDWD$(3)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_CLASS_EXTENSION_SERVICE_OBJECT_ID
'//   [ VT_LPWSTR ] The Object ID of the service.
MACRO WPD_PROPERTY_CLASS_EXTENSION_SERVICE_OBJECT_ID = GUID$("{7F0779B5-FA2B-4766-9CB2-F73BA30B6758}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_CLASS_EXTENSION_SERVICE_INTERFACES
'//   [ VT_UNKNOWN ] This is an IPortablePropVariantCollection of type VT_CLSID which contains the interface GUIDs that this service implements, including the service type GUID.
MACRO WPD_PROPERTY_CLASS_EXTENSION_SERVICE_INTERFACES = GUID$("{7F0779B5-FA2B-4766-9CB2-F73BA30B6758}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_CLASS_EXTENSION_SERVICE_REGISTRATION_RESULTS
'//   [ VT_UNKNOWN ] This is an IPortablePropVariantCollection of type VT_ERROR, where each element is the HRESULT indicating the success or failure of the operation.
MACRO WPD_PROPERTY_CLASS_EXTENSION_SERVICE_REGISTRATION_RESULTS = GUID$("{7F0779B5-FA2B-4766-9CB2-F73BA30B6758}") & MKDWD$(1003)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_SERVICE_COMMON
'*
'* The commands in this category relate to a device service.
'****************************************************************************/
$WPD_CATEGORY_SERVICE_COMMON = GUID$("{322F071D-36EF-477F-B4B5-6F52D734BAEE}")

'// ======== Commands ========

'//
'// WPD_COMMAND_SERVICE_COMMON_GET_SERVICE_OBJECT_ID
'//     This command is used to get the service object identifier.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_OBJECT_ID
MACRO WPD_COMMAND_SERVICE_COMMON_GET_SERVICE_OBJECT_ID = GUID$("{322F071D-36EF-477F-B4B5-6F52D734BAEE}") & MKDWD$(2)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_SERVICE_OBJECT_ID
'//   [ VT_LPWSTR ] Contains the service object identifier.
MACRO WPD_PROPERTY_SERVICE_OBJECT_ID = GUID$("{322F071D-36EF-477F-B4B5-6F52D734BAEE}") & MKDWD$(1001)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_SERVICE_CAPABILITIES
'*
'* The commands in this category relate to capabilities of a device service.
'****************************************************************************/
$WPD_CATEGORY_SERVICE_CAPABILITIES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}")

'// ======== Commands ========

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_METHODS
'//     This command is used to get the methods that apply to a service.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_METHODS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_METHODS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(2)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_METHODS_BY_FORMAT
'//     This command is used to get the methods that apply to a format of a service.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_METHODS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_METHODS_BY_FORMAT = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(3)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_METHOD_ATTRIBUTES
'//     This command is used to get the attributes of a method.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD_ATTRIBUTES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_METHOD_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(4)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_METHOD_PARAMETER_ATTRIBUTES
'//     This command is used to get the attributes of a parameter used in a method.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER_ATTRIBUTES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_METHOD_PARAMETER_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(5)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_FORMATS
'//     This command is used to get formats supported by this service.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMATS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_FORMATS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(6)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_ATTRIBUTES
'//     This command is used to get attributes of a format, such as the format name.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT_ATTRIBUTES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(7)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_FORMAT_PROPERTIES
'//     This command is used to get supported properties of a format.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_KEYS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_FORMAT_PROPERTIES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(8)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_PROPERTY_ATTRIBUTES
'//     This command is used to get the property attributes that are same for all objects of a given format on the service.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_KEYS
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_ATTRIBUTES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_PROPERTY_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(9)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_EVENTS
'//     This command is used to get the supported events of the service.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_EVENTS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_EVENTS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(10)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_EVENT_ATTRIBUTES
'//     This command is used to get the attributes of an event.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT_ATTRIBUTES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_EVENT_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(11)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_EVENT_PARAMETER_ATTRIBUTES
'//     This command is used to get the attributes of a parameter used in an event.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER_ATTRIBUTES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_EVENT_PARAMETER_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(12)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_INHERITED_SERVICES
'//     This command is used to get the inherited services.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_INHERITANCE_TYPE
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_INHERITED_SERVICES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_INHERITED_SERVICES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(13)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_RENDERING_PROFILES
'//     This command is used to get the resource rendering profiles for a format.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_RENDERING_PROFILES
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_RENDERING_PROFILES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(14)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_COMMANDS
'//     Return all commands supported by this driver for a service. This includes custom commands, if any.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     None
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_COMMANDS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_COMMANDS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(15)

'//
'// WPD_COMMAND_SERVICE_CAPABILITIES_GET_COMMAND_OPTIONS
'//     Returns the supported options for the specified command.
'//  Access:
'//     FILE_READ_ACCESS
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_COMMAND
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_CAPABILITIES_COMMAND_OPTIONS
MACRO WPD_COMMAND_SERVICE_CAPABILITIES_GET_COMMAND_OPTIONS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(16)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_METHODS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection (of type VT_CLSID) containing methods that apply to a service.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_METHODS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT
'//   [ VT_CLSID ] Indicates the format the caller is interested in.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD
'//   [ VT_CLSID ] Indicates the method the caller is interested in.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD_ATTRIBUTES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the method attributes.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_METHOD_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER
'//   [ VT_UNKNOWN ] IPortableDeviceKeyCollection containing the parameter the caller is interested in.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1005)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER_ATTRIBUTES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the parameter attributes.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_PARAMETER_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1006)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_FORMATS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection (of type VT_CLSID) containing the formats.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_FORMATS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1007)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT_ATTRIBUTES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the format attributes, such as the format name and MIME Type.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_FORMAT_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1008)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_KEYS
'//   [ VT_UNKNOWN ] IPortableDeviceKeyCollection containing the supported property keys.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_KEYS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1009)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_ATTRIBUTES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the property attributes.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_PROPERTY_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1010)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_EVENTS
'//   [ VT_UNKNOWN ] IPortableDevicePropVariantCollection (of type VT_CLSID) containing all events supported by the service.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_EVENTS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1011)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT
'//   [ VT_CLSID ] Indicates the event the caller is interested in.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1012)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT_ATTRIBUTES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the event attributes.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_EVENT_ATTRIBUTES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1013)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_INHERITANCE_TYPE
'//   [ VT_UI4 ] Indicates the inheritance type the caller is interested in.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_INHERITANCE_TYPE = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1014)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_INHERITED_SERVICES
'//   [ VT_UNKNOWN ] Contains the list of inherited services.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_INHERITED_SERVICES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1015)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_RENDERING_PROFILES
'//   [ VT_UNKNOWN ] Contains the list of format rendering profiles.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_RENDERING_PROFILES = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1016)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_COMMANDS
'//   [ VT_UNKNOWN ] IPortableDeviceKeyCollection containing all commands a driver supports for a service.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_SUPPORTED_COMMANDS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1017)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_COMMAND
'//   [ VT_UNKNOWN ] Indicates the command whose options the caller is interested in.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_COMMAND = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1018)

'//
'// WPD_PROPERTY_SERVICE_CAPABILITIES_COMMAND_OPTIONS
'//   [ VT_UNKNOWN ] Contains an IPortableDeviceValues with the relevant command options.
MACRO WPD_PROPERTY_SERVICE_CAPABILITIES_COMMAND_OPTIONS = GUID$("{24457E74-2E9F-44F9-8C57-1D1BCB170B89}") & MKDWD$(1019)

'/****************************************************************************
'* This section defines all Commands, Parameters and Options associated with:
'* WPD_CATEGORY_SERVICE_METHODS
'*
'* The commands in this category relate to methods of a device service.
'****************************************************************************/
$WPD_CATEGORY_SERVICE_METHODS = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}")

'// ======== Commands ========

'//
'// WPD_COMMAND_SERVICE_METHODS_START_INVOKE
'//     Invokes a service method.
'//  Access:
'//     Dependent on the value of WPD_METHOD_ATTRIBUTE_ACCESS.
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD_PARAMETER_VALUES
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD_CONTEXT
MACRO WPD_COMMAND_SERVICE_METHODS_START_INVOKE = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(2)

'//
'// WPD_COMMAND_SERVICE_METHODS_CANCEL_INVOKE
'//     This command is sent when a client wants to cancel a method that is currently still in progress.
'//  Access:
'//     Dependent on the value of WPD_METHOD_ATTRIBUTE_ACCESS.
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD_CONTEXT
'//  Results:
'//     None
MACRO WPD_COMMAND_SERVICE_METHODS_CANCEL_INVOKE = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(3)

'//
'// WPD_COMMAND_SERVICE_METHODS_END_INVOKE
'//     This command is sent in response to a WPD_EVENT_SERVICE_METHOD_COMPLETE event from the driver to retrieve the method results.
'//  Access:
'//     Dependent on the value of WPD_METHOD_ATTRIBUTE_ACCESS.
'//  Parameters:
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD_CONTEXT
'//  Results:
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD_RESULT_VALUES
'//     [ Required ] WPD_PROPERTY_SERVICE_METHOD_HRESULT
MACRO WPD_COMMAND_SERVICE_METHODS_END_INVOKE = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(4)

'// ======== Command Parameters ========

'//
'// WPD_PROPERTY_SERVICE_METHOD
'//   [ VT_CLSID ] Indicates the method to invoke.
MACRO WPD_PROPERTY_SERVICE_METHOD = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(1001)

'//
'// WPD_PROPERTY_SERVICE_METHOD_PARAMETER_VALUES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the method parameters.
MACRO WPD_PROPERTY_SERVICE_METHOD_PARAMETER_VALUES = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(1002)

'//
'// WPD_PROPERTY_SERVICE_METHOD_RESULT_VALUES
'//   [ VT_UNKNOWN ] IPortableDeviceValues containing the method results.
MACRO WPD_PROPERTY_SERVICE_METHOD_RESULT_VALUES = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(1003)

'//
'// WPD_PROPERTY_SERVICE_METHOD_CONTEXT
'//   [ VT_LPWSTR ] The unique context identifying this method operation.
MACRO WPD_PROPERTY_SERVICE_METHOD_CONTEXT = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(1004)

'//
'// WPD_PROPERTY_SERVICE_METHOD_HRESULT
'//   [ VT_ERROR ] Contains the status HRESULT of this method invocation.
MACRO WPD_PROPERTY_SERVICE_METHOD_HRESULT = GUID$("{2D521CA8-C1B0-4268-A342-CF19321569BC}") & MKDWD$(1005)


'/****************************************************************************
'* This section defines Structures and Macros used by driver writers to
'* simplify Wpd Command Access checks.
'* Sample Usage:
'*
'* - Add table used to lookup the Access required for Wpd Commands
'* BEGIN_WPD_COMMAND_ACCESS_MAP(g_WpdCommandAccessMap)
'*    DECLARE_WPD_STANDARD_COMMAND_ACCESS_ENTRIES
'*    - Add any custom commands here e.g.
'*    WPD_COMMAND_ACCESS_ENTRY(MyCustomCommand, WPD_COMMAND_ACCESS_READWRITE)
'* END_WPD_COMMAND_ACCESS_MAP
'* - This enables the driver to use VERIFY_WPD_COMMAND_ACCESS to check command access function for us.
'* DECLARE_VERIFY_WPD_COMMAND_ACCESS;
'* ...
'* - When the driver receives a WPD IOCTL, it can check that the IOCTL specified matches
'* the command payload with:
'*    hr = VERIFY_WPD_COMMAND_ACCESS(ControlCode, pParams, g_WpdCommandAccessMap);
'****************************************************************************/

'// Structure used as an entry in the Command / Access lookup table.
'typedef struct tagWPD_COMMAND_ACCESS_LOOKUP_ENTRY
'{
'    PROPERTYKEY Command;
'    DWORD AccessType;
'    PROPERTYKEY AccessProperty;
'} WPD_COMMAND_ACCESS_LOOKUP_ENTRY;

'// Used to start a declaration of a WPD Command Access Lookup Map. This macro is usually followed by:
'// DECLARE_WPD_STANDARD_COMMAND_ACCESS_ENTRIES
'// Zero or more WPD_COMMAND_ACCESS_ENTRY or WPD_COMMAND_ACCESS_PROPERTY_ENTRY macros (one for every custom command).
'// The Map is ended with END_WPD_COMMAND_ACCESS_MAP.
'#define BEGIN_WPD_COMMAND_ACCESS_MAP(x) static WPD_COMMAND_ACCESS_LOOKUP_ENTRY x[] = {

'// Ends a WPD Command Access Lookup Map started with BEGIN_WPD_COMMAND_ACCESS_MAP
'#define END_WPD_COMMAND_ACCESS_MAP { WPD_PROPERTY_NULL, 0, WPD_PROPERTY_NULL }, };

'// Adds a custom entry to a WPD Command Access Lookup Map started with BEGIN_WPD_COMMAND_ACCESS_MAP
'#define WPD_COMMAND_ACCESS_ENTRY(WpdCommand, WpdCommandAccessType) { WpdCommand, WpdCommandAccessType, WPD_PROPERTY_NULL },

'// Adds a custom entry to a WPD Command Access Lookup Map started with BEGIN_WPD_COMMAND_ACCESS_MAP
'#define WPD_COMMAND_ACCESS_PROPERTY_ENTRY(WpdCommand, WpdCommandAccessType, WpdAccessProperty) { WpdCommand, WpdCommandAccessType, WpdAccessProperty },

'#ifdef WPD_SERVICES_STRICT
'#define DECLARE_WPD_LEGACY_COMMAND_ACCESS_ENTRIES
'#else
'#define DECLARE_WPD_LEGACY_COMMAND_ACCESS_ENTRIES \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_STORAGE_FORMAT, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_STORAGE_EJECT, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SMS_SEND, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_STILL_IMAGE_CAPTURE_INITIATE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_MEDIA_CAPTURE_START, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_MEDIA_CAPTURE_STOP, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_MEDIA_CAPTURE_PAUSE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_DEVICE_HINTS_GET_CONTENT_LOCATION, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_GENERATE_KEYPAIR, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_COMMIT_KEYPAIR, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_PROCESS_WIRELESS_PROFILE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \

'#endif // WPD_SERVICES_STRICT

'// Declares entries for all the WPD Commands contained in this header file. Used after BEGIN_WPD_COMMAND_ACCESS_MAP.
'#define DECLARE_WPD_STANDARD_COMMAND_ACCESS_ENTRIES \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_COMMON_RESET_DEVICE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_COMMON_GET_OBJECT_IDS_FROM_PERSISTENT_UNIQUE_IDS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_COMMON_SAVE_CLIENT_INFORMATION, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_ENUMERATION_START_FIND, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_ENUMERATION_FIND_NEXT, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_ENUMERATION_END_FIND, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_GET_SUPPORTED, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_GET_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_GET, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_SET, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_GET_ALL, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_DELETE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_START, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_NEXT, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_LIST_END, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_START, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_NEXT, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_GET_VALUES_BY_OBJECT_FORMAT_END, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_START, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_NEXT, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_PROPERTIES_BULK_SET_VALUES_BY_OBJECT_LIST_END, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_GET_SUPPORTED, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_GET_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_OPEN, WPD_COMMAND_ACCESS_FROM_PROPERTY_WITH_STGM_ACCESS, WPD_PROPERTY_OBJECT_RESOURCES_ACCESS_MODE ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_READ, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_WRITE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_CLOSE, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_DELETE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_CREATE_RESOURCE, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_REVERT, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_RESOURCES_SEEK, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_CREATE_OBJECT_WITH_PROPERTIES_ONLY, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_CREATE_OBJECT_WITH_PROPERTIES_AND_DATA, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_WRITE_OBJECT_DATA, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_COMMIT_OBJECT, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_REVERT_OBJECT, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_DELETE_OBJECTS, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_MOVE_OBJECTS, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_COPY_OBJECTS, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_OBJECT_MANAGEMENT_UPDATE_OBJECT_WITH_PROPERTIES_AND_DATA, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_COMMANDS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_COMMAND_OPTIONS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FUNCTIONAL_CATEGORIES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_FUNCTIONAL_OBJECTS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_CONTENT_TYPES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FORMATS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_FORMAT_PROPERTIES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_FIXED_PROPERTY_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_SUPPORTED_EVENTS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CAPABILITIES_GET_EVENT_OPTIONS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CLASS_EXTENSION_WRITE_DEVICE_INFORMATION, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CLASS_EXTENSION_REGISTER_SERVICE_INTERFACES, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_CLASS_EXTENSION_UNREGISTER_SERVICE_INTERFACES, WPD_COMMAND_ACCESS_READWRITE, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_COMMON_GET_SERVICE_OBJECT_ID, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_METHODS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_METHODS_BY_FORMAT, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_METHOD_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_METHOD_PARAMETER_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_FORMATS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_FORMAT_PROPERTIES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_PROPERTY_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_EVENTS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_EVENT_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_EVENT_PARAMETER_ATTRIBUTES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_INHERITED_SERVICES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_FORMAT_RENDERING_PROFILES, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_SUPPORTED_COMMANDS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_CAPABILITIES_GET_COMMAND_OPTIONS, WPD_COMMAND_ACCESS_READ, WPD_PROPERTY_NULL ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_METHODS_START_INVOKE, WPD_COMMAND_ACCESS_FROM_ATTRIBUTE_WITH_METHOD_ACCESS, WPD_METHOD_ATTRIBUTE_ACCESS ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_METHODS_CANCEL_INVOKE, WPD_COMMAND_ACCESS_FROM_ATTRIBUTE_WITH_METHOD_ACCESS, WPD_METHOD_ATTRIBUTE_ACCESS ) \
'   WPD_COMMAND_ACCESS_PROPERTY_ENTRY( WPD_COMMAND_SERVICE_METHODS_END_INVOKE, WPD_COMMAND_ACCESS_FROM_ATTRIBUTE_WITH_METHOD_ACCESS, WPD_METHOD_ATTRIBUTE_ACCESS ) \
'   DECLARE_WPD_LEGACY_COMMAND_ACCESS_ENTRIES


'// Declares an instance of the function used to check whether a WPD Command is in the driver's WPD Command Access Map.
'// Driver writers should not call this function directly, but should instead use the IS_COMMAND_IN_WPD_COMMAND_ACCESS_MAP alias.
'#define DECLARE_IS_COMMAND_IN_WPD_COMMAND_ACCESS_MAP() \
'BOOL IsCommandInWpdCommandAccessMap( \
'    REFPROPERTYKEY                       WpdCommand, \
'    __in WPD_COMMAND_ACCESS_LOOKUP_ENTRY *pCommandAccessLookupMap) \
'{ \
'    BOOL bRet = FALSE; \
'    if(pCommandParams == NULL) \
'    { \
'        return E_POINTER; \
'    } \
'    while(pCommandAccessLookupMap[dwMapIndex++].Command != WPD_PROPERTY_NULL) \
'    { \
'        if(IsEqualPropertyKey(pCommandAccessLookupMap[dwMapIndex].Command), WpdCommand) \
'        { \
'            bRet = TRUE; \
'            break; \
'        } \
'        dwMapIndex++; \
'    } \
'    return bRet; \
'};

'// This macro is an alias for the function used to check whether a WPD Command is in the driver's WPD Command Access Map (see BEGIN_WPD_COMMAND_ACCESS_MAP)
'#define IS_COMMAND_IN_WPD_COMMAND_ACCESS_MAP IsCommandInWpdCommandAccessMap


'// Declares an instance of the function used to verify that WPD Commands are sent with the appropriate Access Flags in the IOCTL.
'// Driver writers should not call this function directly, but should instead use the VERIFY_WPD_COMMAND_ACCESS alias.
'#define DECLARE_VERIFY_WPD_COMMAND_ACCESS \
'HRESULT VerifyWpdCommandAccessFromMap(  \
'    const DWORD                          ControlCode, \
'    __in IPortableDeviceValues           *pCommandParams, \
'    __in WPD_COMMAND_ACCESS_LOOKUP_ENTRY *pCommandAccessLookupMap) \
'{ \
'    HRESULT     hr                      = S_OK; \
'    DWORD       dwMapIndex              = 0; \
'    PROPERTYKEY WpdCommand              = WPD_PROPERTY_NULL; \
'    DWORD       dwExpectedControlCode   = IOCTL_WPD_MESSAGE_READWRITE_ACCESS; \
'    if((pCommandParams == NULL) || (pCommandAccessLookupMap == NULL)) \
'    { \
'        return E_POINTER; \
'    } \
'    if(ControlCode == IOCTL_WPD_MESSAGE_READWRITE_ACCESS) \
'    { \
'        return S_OK; \
'    } \
'    hr = pCommandParams->GetGuidValue(WPD_PROPERTY_COMMON_COMMAND_CATEGORY, &WpdCommand.fmtid); \
'    if(SUCCEEDED(hr)) \
'    { \
'        hr = pCommandParams->GetUnsignedIntegerValue(WPD_PROPERTY_COMMON_COMMAND_ID, &WpdCommand.pid); \
'        if(SUCCEEDED(hr)) \
'        { \
'            while(!IsEqualPropertyKey(pCommandAccessLookupMap[dwMapIndex].Command, WPD_PROPERTY_NULL)) \
'            { \
'                if(IsEqualPropertyKey(pCommandAccessLookupMap[dwMapIndex].Command, WpdCommand)) \
'                { \
'                    switch(pCommandAccessLookupMap[dwMapIndex].AccessType) \
'                    { \
'                        case WPD_COMMAND_ACCESS_READ: \
'                            { \
'                                dwExpectedControlCode = IOCTL_WPD_MESSAGE_READ_ACCESS; \
'                            } \
'                            break; \
'                        case WPD_COMMAND_ACCESS_READWRITE: \
'                            { \
'                                dwExpectedControlCode = IOCTL_WPD_MESSAGE_READWRITE_ACCESS; \
'                            } \
'                            break; \
'                        case WPD_COMMAND_ACCESS_FROM_PROPERTY_WITH_STGM_ACCESS: \
'                            { \
'                                DWORD dwAccessPropVal = STGM_READWRITE; \
'                                HRESULT hrTemp = S_OK; \
'                                hrTemp = pCommandParams->GetUnsignedIntegerValue(pCommandAccessLookupMap[dwMapIndex].AccessProperty, &dwAccessPropVal); \
'                                if(dwAccessPropVal == STGM_READ) \
'                                { \
'                                    dwExpectedControlCode = IOCTL_WPD_MESSAGE_READ_ACCESS; \
'                                } \
'                                else \
'                                { \
'                                    dwExpectedControlCode = IOCTL_WPD_MESSAGE_READWRITE_ACCESS; \
'                                } \
'                            } \
'                            break; \
'                        case WPD_COMMAND_ACCESS_FROM_PROPERTY_WITH_FILE_ACCESS: \
'                            { \
'                                DWORD dwAccessPropVal = FILE_READ_ACCESS; \
'                                HRESULT hrTemp = S_OK; \
'                                hrTemp = pCommandParams->GetUnsignedIntegerValue(pCommandAccessLookupMap[dwMapIndex].AccessProperty, &dwAccessPropVal); \
'                                if(dwAccessPropVal == FILE_READ_ACCESS) \
'                                { \
'                                    dwExpectedControlCode = IOCTL_WPD_MESSAGE_READ_ACCESS; \
'                                } \
'                                else \
'                                { \
'                                    dwExpectedControlCode = IOCTL_WPD_MESSAGE_READWRITE_ACCESS; \
'                                } \
'                            } \
'                            break; \
'                        default: \
'                            { \
'                                dwExpectedControlCode = IOCTL_WPD_MESSAGE_READWRITE_ACCESS; \
'                            } \
'                            break; \
'                    } \
'                    break; \
'                } \
'                dwMapIndex++; \
'            } \
'        } \
'    } \
'    if(SUCCEEDED(hr)) \
'    { \
'        if(ControlCode != dwExpectedControlCode) \
'        { \
'            return E_INVALIDARG; \
'        } \
'    } \
'    return hr; \
'};

'// This macro is an alias for the function used to verify that WPD Commands are sent with the appropriate Access Flags in the IOCTL
'#define VERIFY_WPD_COMMAND_ACCESS VerifyWpdCommandAccessFromMap

'/****************************************************************************
'* This section defines the inline helper functions
'****************************************************************************/

'// This function can be used after IPortableDeviceManager::GetDevices(..) and IPortableDeviceServiceManager::GetDeviceServices(..)
'// to free the elements of the pPnPIDs array. The caller is responsible for freeing pPnPIDs when this function completes.
'inline void FreePortableDevicePnPIDs(__in_ecount(cPnPIDs) LPWSTR* pPnPIDs, DWORD cPnPIDs)
'{
'    if (pPnPIDs != NULL)
'    {
'        for (DWORD i=0; i<cPnPIDs; i++)
'        {
'            CoTaskMemFree(pPnPIDs[i]);
'            pPnPIDs[i] = NULL;
'        }
'    }
'}



'#endif // ((NTDDI_VERSION >= NTDDI_WINXPSP2 && NTDDI_VERSION < NTDDI_WS03) || (NTDDI_VERSION >= NTDDI_WINLH))
