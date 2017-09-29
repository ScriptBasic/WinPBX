' ########################################################################################
' Microsoft Windows
' File: sti.inc
' Contents: This module contains the user mode still image APIs in COM format
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STI_INC = 1

' //
' // Set packing
' //
'#include <pshpack8.h>

' //
' // Only use UNICODE STI interfaces
' //
%STI_UNICODE = 1

' //
' // Include COM definitions
' //
#INCLUDE ONCE "ole2.inc"
#INCLUDE ONCE "objbase.inc"

#INCLUDE ONCE "stireg.inc"
#INCLUDE ONCE "stierr.inc"

'/*
' * Class IID's
' */

$CLSID_Sti                = GUID$("{B323F8E0-2E68-11D0-90EA-00AA0060F86C}")

'/*
' * Interface IID's
' */

$IID_IStillImageW         = GUID$("{641BD880-2DC8-11D0-90EA-00AA0060F86C}")
$IID_IStillImageA         = GUID$("{A7B1F740-1D7F-11D1-ACA9-00A02438AD48}")
$IID_IStillImage          = GUID$("{A7B1F740-1D7F-11D1-ACA9-00A02438AD48}")
$IID_IStiDevice           = GUID$("{6CFA5A80-2DC8-11D0-90EA-00AA0060F86C}")

'/*
' * Standard event GUIDs
' */

$GUID_DeviceArrivedLaunch = GUID$("{740D9EE6-70F1-11d1-AD10-00A02438AD48}")
$GUID_ScanImage           = GUID$("{A6C5A715-8C6E-11d2-977A-0000F87A926F}")
$GUID_ScanPrintImage      = GUID$("{B441F425-8C6E-11d2-977A-0000F87A926F}")
$GUID_ScanFaxImage        = GUID$("{C00EB793-8C6E-11d2-977A-0000F87A926F}")
$GUID_STIUserDefined1     = GUID$("{C00EB795-8C6E-11d2-977A-0000F87A926F}")
$GUID_STIUserDefined2     = GUID$("{C77AE9C5-8C6E-11d2-977A-0000F87A926F}")
$GUID_STIUserDefined3     = GUID$("{C77AE9C6-8C6E-11d2-977A-0000F87A926F}")

' //
' // Generic constants and definitions
' //
%STI_VERSION_FLAG_MASK       = &Hff000000???
%STI_VERSION_FLAG_UNICODE    = &H01000000???

'#define GET_STIVER_MAJOR(dwVersion)   (HIWORD(dwVersion) & ~STI_VERSION_FLAG_MASK)
'#define GET_STIVER_MINOR(dwVersion)   LOWORD(dwVersion)
MACRO GET_STIVER_MAJOR(dwVersion) = (HI(WORD, dwVersion) AND NOT %STI_VERSION_FLAG_MASK)
MACRO GET_STIVER_MINOR(dwVersion) = LO(WORD, dwVersion)

%STI_VERSION_REAL            = &H00000002???

'#if (_WIN32_WINNT >= 0x0600) // Windows Vista and later
%STI_VERSION_3               = &H00000003??? OR %STI_VERSION_FLAG_UNICODE
'#endif //#if (_WIN32_WINNT >= 0x0600)

%STI_VERSION_MIN_ALLOWED     = &H00000002???

'#ifdef UNICODE
'#define STI_VERSION                 (STI_VERSION_REAL | STI_VERSION_FLAG_UNICODE)
'#else
'#define STI_VERSION                 (STI_VERSION_REAL)
'#endif

' //
' // Maximum length of internal device name
' //
%STI_MAX_INTERNAL_NAME_LENGTH   = 128

' // begin sti_device_information

' //
' //  Device information definitions and prototypes
' // ----------------------------------------------
' //

' //
' //  Following information is used for enumerating still image devices , currently configured
' //  in the system. Presence of the device in the enumerated list does not mean availability
' // of the device, it only means that device was installed at least once and had not been removed since.
' //

' //
' // Type of device ( scanner, camera) is represented by DWORD value with
' // hi word containing generic device type , and lo word containing sub-type
' //
' enum STI_DEVICE_MJ_TYPE {
%StiDeviceTypeDefault          = 0
%StiDeviceTypeScanner          = 1
'#if (_WIN32_WINNT >= 0x0501) // Windows XP and later
%StiDeviceTypeDigitalCamera    = 2
%StiDeviceTypeStreamingVideo   = 3
'#else
'    StiDeviceTypeDigitalCamera    = 2
'#endif //#if (_WIN32_WINNT >= 0x0501)

'typedef DWORD STI_DEVICE_TYPE;

' //
' // Macros to extract device type/subtype from single type field
' //
'#define GET_STIDEVICE_TYPE(dwDevType)   HIWORD(dwDevType)
'#define GET_STIDEVICE_SUBTYPE(dwDevType)   LOWORD(dwDevType)

MACRO GET_STIDEVICE_TYPE(dwDevType) = HI(WORD, dwDevType)
MACRO GET_STIDEVICE_SUBTYPE(dwDevType) = LO(WORD, dwDevType)

' //
' // Device capabilities bits.
' // Various capabilities are grouped into separate bitmasks
' //

' // Size = 4 bytes
TYPE STI_DEV_CAPS DWORD
   dwGeneric AS DWORD
END TYPE

' //
' // Generic capabilities mask contain 16 bits , common for all devices, maintained by MS
' // and 16 bits , which USD can use for proprietary capbailities reporting.
' //

'#define GET_STIDCOMMON_CAPS(dwGenericCaps)   LOWORD(dwGenericCaps)
'#define GET_STIVENDOR_CAPS(dwGenericCaps)    HIWORD(dwGenericCaps)

MACRO GET_STIDCOMMON_CAPS(dwGenericCaps) = LO(WORD, dwGenericCaps)
MACRO GET_STIVENDOR_CAPS(dwGenericCaps) = HI(WORD, dwGenericCaps)

'#define STI_GENCAP_COMMON_MASK  (DWORD)0x00ff
%STI_GENCAP_COMMON_MASK = &H00ff???

' //
' // Notifications are supported.
' // If this capability set , device can be subscribed to .
' //
%STI_GENCAP_NOTIFICATIONS    = &H00000001???

' //
' // Polling required .
' // This capability is used when previous is set to TRUE. Presence of it means
' // that device is not capable of issuing "truly" asyncronous notifications, but can
' // be polled to determine the moment when event happened
%STI_GENCAP_POLLING_NEEDED   = &H00000002???

' //
' // Generate event on device arrival
' // If this capability is set, still image service will generate event when device
' // instance is successfully initialized ( typically in response to PnP arrival)

' //
' // Note: on initial service enumeration events will nto be generated to avoid
' // end-user confusion.
' //
%STI_GENCAP_GENERATE_ARRIVALEVENT    = &H00000004???

' //
' // Auto port selection on non-PnP buses
' // This capability indicates that USD is able to detect non-PnP device on a
' // bus , device is supposed to be attached to.
' //
%STI_GENCAP_AUTO_PORTSELECT   = &H00000008???

'#if (_WIN32_WINNT >= 0x0501) // Windows XP and later

' //
' // WIA capability bit.
' // This capability indicates that USD is WIA capable.
' //
%STI_GENCAP_WIA              = &H00000010???

' //
' // Subset driver bit.
' // This capability indicates that there is more featured driver exists. All
' // of inbox driver has this bit set. Fully featured (IHV) driver shouldn't have
' // this bit set.
' //
%STI_GENCAP_SUBSET           = &H00000020???

'#endif //#if (_WIN32_WINNT >= 0x0501)

'#if (_WIN32_WINNT >= 0x0600) // Windows Vista and later
#IF %WINVER >= &H0600
%WIA_INCOMPAT_XP             = &H00000001???
#ENDIF
'#endif //#if (_WIN32_WINNT >= 0x0600)

' //
' //
' // Type of bus connection for those in need to know
' //
%STI_HW_CONFIG_UNKNOWN   = &H0001??
%STI_HW_CONFIG_SCSI      = &H0002??
%STI_HW_CONFIG_USB       = &H0004??
%STI_HW_CONFIG_SERIAL    = &H0008??
%STI_HW_CONFIG_PARALLEL  = &H0010??

' //
' // Device information structure, this is not configurable. This data is returned from
' // device enumeration API and is used for populating UI or selecting which device
' // should be used in current session
' //
' // Size = 292 bytes
TYPE STI_DEVICE_INFORMATIONW DWORD
   dwSize                  AS DWORD                                      ' DWORD
   DeviceType              AS DWORD                                      ' STI_DEVICE_TYPE enum
   szDeviceInternalName    AS WSTRINGZ * %STI_MAX_INTERNAL_NAME_LENGTH   ' WCHAR
   DeviceCapabilities      AS STI_DEV_CAPS                               ' STI_DEV_CAPS
   dwHardwareConfiguration AS DWORD                                      ' DWORD
   pszVendorDescription    AS WSTRINGZ PTR                               ' LPWSTR
   pszDeviceDescription    AS WSTRINGZ PTR                               ' LPWSTR
   pszPortName             AS WSTRINGZ PTR                               ' LPWSTR
   pszPropProvider         AS WSTRINGZ PTR                               ' LPWSTR
   pszLocalName            AS WSTRINGZ PTR                               ' LPWSTR
END TYPE

'typedef struct _STI_DEVICE_INFORMATIONA {
'    DWORD   dwSize;

'    ' // Type of the hardware imaging device
'    STI_DEVICE_TYPE   DeviceType;

'    ' // Device identifier for reference when creating device object
'    CHAR    szDeviceInternalName[STI_MAX_INTERNAL_NAME_LENGTH];

'    ' // Set of capabilities flags
'    STI_DEV_CAPS   DeviceCapabilities;

'    ' // This includes bus type
'    DWORD   dwHardwareConfiguration;

'    ' // Vendor description string
'    LPCSTR    pszVendorDescription;

'    ' // Device description , provided by vendor
'    LPCSTR    pszDeviceDescription;

'    ' // String , representing port on which device is accessible.
'    LPCSTR    pszPortName;

'    ' // Control panel propery provider
'    LPCSTR    pszPropProvider;

'    ' // Local specific ("friendly") name of the device, mainly used for showing in the UI
'    LPCSTR    pszLocalName;

'} STI_DEVICE_INFORMATIONA, *PSTI_DEVICE_INFORMATIONA;

' // Size = 164 bytes
'TYPE STI_DEVICE_INFORMATIONA DWORD
'   dwSize                  AS DWORD                                    ' DWORD
'   DeviceType              AS DWORD                                    ' STI_DEVICE_TYPE enum
'   szDeviceInternalName    AS ASCIIZ * %STI_MAX_INTERNAL_NAME_LENGTH   ' CHAR
'   DeviceCapabilities      AS STI_DEV_CAPS                             ' STI_DEV_CAPS
'   dwHardwareConfiguration AS DWORD                                    ' DWORD
'   pszVendorDescription    AS ASCIIZ PTR                               ' LPCSTR
'   pszDeviceDescription    AS ASCIIZ PTR                               ' LPCSTR
'   pszPortName             AS ASCIIZ PTR                               ' LPCSTR
'   pszPropProvider         AS ASCIIZ PTR                               ' LPCSTR
'   pszLocalName            AS ASCIIZ PTR                               ' LPCSTR
'END TYPE
'MACRO STI_DEVICE_INFORMATION = STI_DEVICE_INFORMATIONA

MACRO STI_DEVICE_INFORMATION = STI_DEVICE_INFORMATIONW

' //
' // EXTENDED STI INFORMATION TO COVER WIA
' //

'typedef struct _STI_WIA_DEVICE_INFORMATIONW {
'    DWORD   dwSize;

'    ' // Type of the hardware imaging device
'    STI_DEVICE_TYPE   DeviceType;

'    ' // Device identifier for reference when creating device object
'    WCHAR   szDeviceInternalName[STI_MAX_INTERNAL_NAME_LENGTH];

'    ' // Set of capabilities flags
'    STI_DEV_CAPS   DeviceCapabilities;

'    ' // This includes bus type
'    DWORD   dwHardwareConfiguration;

'    ' // Vendor description string
'    LPWSTR    pszVendorDescription;

'    ' // Device description , provided by vendor
'    LPWSTR    pszDeviceDescription;

'    ' // String , representing port on which device is accessible.
'    LPWSTR    pszPortName;

'    ' // Control panel propery provider
'    LPWSTR    pszPropProvider;

'    ' // Local specific ("friendly") name of the device, mainly used for showing in the UI
'    LPWSTR    pszLocalName;

'    ' //
'    ' // WIA values
'    ' //

'    LPWSTR    pszUiDll;
'    LPWSTR    pszServer;

'} STI_WIA_DEVICE_INFORMATIONW, *PSTI_WIA_DEVICE_INFORMATIONW;


' // Size = 300 bytes
TYPE STI_WIA_DEVICE_INFORMATIONW DWORD
   dwSize                  AS DWORD                                      ' DWORD
   DeviceType              AS DWORD                                      ' STI_DEVICE_TYPE
   szDeviceInternalName    AS WSTRINGZ * %STI_MAX_INTERNAL_NAME_LENGTH   ' WCHAR
   DeviceCapabilities      AS STI_DEV_CAPS                               ' STI_DEV_CAPS
   dwHardwareConfiguration AS DWORD                                      ' DWORD
   pszVendorDescription    AS WSTRINGZ PTR                               ' LPWSTR
   pszDeviceDescription    AS WSTRINGZ PTR                               ' LPWSTR
   pszPortName             AS WSTRINGZ PTR                               ' LPWSTR
   pszPropProvider         AS WSTRINGZ PTR                               ' LPWSTR
   pszLocalName            AS WSTRINGZ PTR                               ' LPWSTR
   pszUiDll                AS WSTRINGZ PTR                               ' LPWSTR
   pszServer               AS WSTRINGZ PTR                               ' LPWSTR
END TYPE

'typedef struct _STI_WIA_DEVICE_INFORMATIONA {
'    DWORD   dwSize;

'    ' // Type of the hardware imaging device
'    STI_DEVICE_TYPE   DeviceType;

'    ' // Device identifier for reference when creating device object
'    CHAR    szDeviceInternalName[STI_MAX_INTERNAL_NAME_LENGTH];

'    ' // Set of capabilities flags
'    STI_DEV_CAPS   DeviceCapabilities;

'    ' // This includes bus type
'    DWORD   dwHardwareConfiguration;

'    ' // Vendor description string
'    LPCSTR    pszVendorDescription;

'    ' // Device description , provided by vendor
'    LPCSTR    pszDeviceDescription;

'    ' // String , representing port on which device is accessible.
'    LPCSTR    pszPortName;

'    ' // Control panel propery provider
'    LPCSTR    pszPropProvider;

'    ' // Local specific ("friendly") name of the device, mainly used for showing in the UI
'    LPCSTR    pszLocalName;

'    ' //
'    ' // WIA values
'    ' //

'    LPCSTR    pszUiDll;
'    LPCSTR    pszServer;

'} STI_WIA_DEVICE_INFORMATIONA, *PSTI_WIA_DEVICE_INFORMATIONA;


' // Size = 172 bytes
'TYPE STI_WIA_DEVICE_INFORMATIONA DWORD
'   dwSize                  AS DWORD                                    ' DWORD
'   DeviceType              AS DWORD                                    ' STI_DEVICE_TYPE
'   szDeviceInternalName    AS ASCIIZ * %STI_MAX_INTERNAL_NAME_LENGTH   ' CHAR
'   DeviceCapabilities      AS STI_DEV_CAPS                             ' STI_DEV_CAPS
'   dwHardwareConfiguration AS DWORD                                    ' DWORD
'   pszVendorDescription    AS ASCIIZ PTR                               ' LPCSTR
'   pszDeviceDescription    AS ASCIIZ PTR                               ' LPCSTR
'   pszPortName             AS ASCIIZ PTR                               ' LPCSTR
'   pszPropProvider         AS ASCIIZ PTR                               ' LPCSTR
'   pszLocalName            AS ASCIIZ PTR                               ' LPCSTR
'   pszUiDll                AS ASCIIZ PTR                               ' LPCSTR
'   pszServer               AS ASCIIZ PTR                               ' LPCSTR
'END TYPE
'MACRO STI_WIA_DEVICE_INFORMATION = STI_WIA_DEVICE_INFORMATIONA

MACRO STI_WIA_DEVICE_INFORMATION = STI_WIA_DEVICE_INFORMATIONW

' // end sti_device_information

' //
' // Device state information.
' // ------------------------
' //
' // Following types  are used to inquire state characteristics of the device after
' // it had been opened.
' //
' // Device configuration structure contains configurable parameters reflecting
' // current state of the device
' //
' //
' // Device hardware status.
' //

' //
' // Individual bits for state acquiring  through StatusMask
' //

' // State of hardware as known to USD
%STI_DEVSTATUS_ONLINE_STATE      = &H0001???

' // State of pending events ( as known to USD)
%STI_DEVSTATUS_EVENTS_STATE      = &H0002???

' //
' // Online state values
' //
%STI_ONLINESTATE_OPERATIONAL         = &H00000001???
%STI_ONLINESTATE_PENDING             = &H00000002???
%STI_ONLINESTATE_ERROR               = &H00000004???
%STI_ONLINESTATE_PAUSED              = &H00000008???
%STI_ONLINESTATE_PAPER_JAM           = &H00000010???
%STI_ONLINESTATE_PAPER_PROBLEM       = &H00000020???
%STI_ONLINESTATE_OFFLINE             = &H00000040???
%STI_ONLINESTATE_IO_ACTIVE           = &H00000080???
%STI_ONLINESTATE_BUSY                = &H00000100???
%STI_ONLINESTATE_TRANSFERRING        = &H00000200???
%STI_ONLINESTATE_INITIALIZING        = &H00000400???
%STI_ONLINESTATE_WARMING_UP          = &H00000800???
%STI_ONLINESTATE_USER_INTERVENTION   = &H00001000???
%STI_ONLINESTATE_POWER_SAVE          = &H00002000???

' //
' // Event processing parameters
' //
%STI_EVENTHANDLING_ENABLED           = &H00000001???
%STI_EVENTHANDLING_POLLING           = &H00000002???
%STI_EVENTHANDLING_PENDING           = &H00000004???

'typedef struct _STI_DEVICE_STATUS {

'    DWORD   dwSize;

'    ' // Request field - bits of status to verify
'    DWORD   StatusMask;

'    ' //
'    ' // Fields are set when status mask contains STI_DEVSTATUS_ONLINE_STATE bit set
'    ' //
'    ' // Bitmask describing  device state
'    DWORD   dwOnlineState;

'    ' // Device status code as defined by vendor
'    DWORD   dwHardwareStatusCode;

'    ' //
'    ' // Fields are set when status mask contains STI_DEVSTATUS_EVENTS_STATE bit set
'    ' //

'    ' // State of device notification processing (enabled, pending)
'    DWORD   dwEventHandlingState;

'    ' // If device is polled, polling interval in ms
'    DWORD   dwPollingInterval;

'} STI_DEVICE_STATUS,*PSTI_DEVICE_STATUS;

' // Size = 24 bytes
TYPE STI_DEVICE_STATUS DWORD
   dwSize               AS DWORD
   StatusMask           AS DWORD
   dwOnlineState        AS DWORD
   dwHardwareStatusCode AS DWORD
   dwEventHandlingState AS DWORD
   dwPollingInterval    AS DWORD
END TYPE

' //
' // Structure to describe diagnostic ( test ) request to be processed by USD
' //

' // Basic test for presence of associated hardware
%STI_DIAGCODE_HWPRESENCE         = &H00000001???

' //
' // Status bits for diagnostic
' //

' //
' // generic diagnostic errors
' //

' // Size = 524 bytes
TYPE STI_ERROR_INFOW DWORD
   dwSize              AS DWORD            ' DWORD
   dwGenericError      AS DWORD            ' DWORD
   dwVendorError       AS DWORD            ' DWORD
   szExtendedErrorText AS WSTRINGZ * 255   ' WCHAR
END TYPE

'typedef struct _ERROR_INFOA {

'    DWORD   dwSize;

'    DWORD   dwGenericError;
'    DWORD   dwVendorError;

'    CHAR   szExtendedErrorText[255];

'} STI_ERROR_INFOA,*PSTI_ERROR_INFOA;

' // Size = 268 bytes
'TYPE STI_ERROR_INFOA DWORD
'   dwSize              AS DWORD          ' DWORD
'   dwGenericError      AS DWORD          ' DWORD
'   dwVendorError       AS DWORD          ' DWORD
'   szExtendedErrorText AS ASCIIZ * 255   ' CHAR
'END TYPE
'MACRO STI_ERROR_INFO = STI_ERROR_INFOA

MACRO STI_ERROR_INFO = STI_ERROR_INFOW

'typedef struct _STI_DIAG {

'    DWORD   dwSize;

'    ' // Diagnostic request fields. Are set on request by caller

'    ' // One of the
'    DWORD   dwBasicDiagCode;
'    DWORD   dwVendorDiagCode;

'    ' // Response fields
'    DWORD   dwStatusMask;

'    STI_ERROR_INFO  sErrorInfo;

'} STI_DIAG,*LPSTI_DIAG;

' //
'typedef STI_DIAG    DIAG;
'typedef LPSTI_DIAG  LPDIAG;

' // Size = 540 bytes
TYPE STI_DIAG DWORD
   dwSize           AS DWORD            ' DWORD
   dwBasicDiagCode  AS DWORD            ' DWORD
   dwVendorDiagCode AS DWORD            ' DWORD
   dwStatusMask     AS DWORD            ' DWORD
   sErrorInfo       AS STI_ERROR_INFO   ' STI_ERROR_INFO
END TYPE

' // end device state information.

' //
' // Flags passed to WriteToErrorLog call in a first parameter, indicating type of the message
' // which needs to be logged
' //
%STI_TRACE_INFORMATION       = &H00000001???
%STI_TRACE_WARNING           = &H00000002???
%STI_TRACE_ERROR             = &H00000004???

' //
' // Event notification mechansims.
' // ------------------------------
' //
' // Those are used to inform last subscribed caller of the changes in device state, initiated by
' // device.
' //
' // The only supported discipline of notification is stack. The last caller to subscribe will be notified
' // and will receive notification data. After caller unsubscribes , the previously subscribed caller will
' // become active.
' //

' // Notifications are sent to subscriber via window message. Window handle is passed as
' // parameter
%STI_SUBSCRIBE_FLAG_WINDOW   = &H0001

' // Device notification is signalling Win32 event ( auto-set event). Event handle
' // is passed as a parameter
%STI_SUBSCRIBE_FLAG_EVENT    = &H0002

'typedef struct _STISUBSCRIBE {

'    DWORD   dwSize;

'    DWORD   dwFlags;

'    ' // Not used . Will be used for subscriber to set bit mask filtering different events
'    DWORD   dwFilter;

'    ' // When STI_SUBSCRIBE_FLAG_WINDOW bit is set, following fields should be set
'    ' // Handle of the window which will receive notification message
'    HWND    hWndNotify;

'    ' // Handle of Win32 auto-reset event , which will be signalled whenever device has
'    ' // notification pending
'    HANDLE  hEvent;

'    ' // Code of notification message, sent to window
'    UINT    uiNotificationMessage;

'} STISUBSCRIBE,*LPSTISUBSCRIBE;

' // Size = 24 bytes
TYPE STISUBSCRIBE DWORD
   dwSize                AS DWORD   ' DWORD
   dwFlags               AS DWORD   ' DWORD
   dwFilter              AS DWORD   ' DWORD
   hWndNotify            AS DWORD   ' HWND
   hEvent                AS DWORD   ' HANDLE
   uiNotificationMessage AS DWORD   ' UINT
END TYPE

%MAX_NOTIFICATION_DATA = 64


' //
' // Structure to describe notification information
' //
'typedef struct _STINOTIFY {

'    DWORD   dwSize;                 ' // Total size of the notification structure

'    ' // GUID of the notification being retrieved
'    GUID    guidNotificationCode;

'    ' // Vendor specific notification description
'    BYTE    abNotificationData[MAX_NOTIFICATION_DATA];     ' // USD specific

'} STINOTIFY,*LPSTINOTIFY;

' // Size = 84 bytes
TYPE STINOTIFY DWORD
   dwSize               AS DWORD                             ' // Total size of the notification structure
   guidNotificationCode AS GUID
   abNotificationData(%MAX_NOTIFICATION_DATA -  1) AS BYTE   ' // USD specific
END TYPE

' // end event_mechanisms

' //
' // STI device broadcasting
' //

' //
' // When STI Device is being added or removed, PnP broadacst is being sent , but it is not obvious
' // for application code to recognize if it is STI device and if so, what is the name of the
' // device. STI subsystem will analyze PnP broadcasts and rebroadcast another message via
' // BroadcastSystemMessage / WM_DEVICECHANGE / DBT_USERDEFINED .

' // String passed as user defined message contains STI prefix, action and device name

'#define STI_ADD_DEVICE_BROADCAST_ACTION     "Arrival"
'#define STI_REMOVE_DEVICE_BROADCAST_ACTION  "Removal"

$STI_ADD_DEVICE_BROADCAST_ACTION    = "Arrival"
$STI_REMOVE_DEVICE_BROADCAST_ACTION = "Removal"

'#define STI_ADD_DEVICE_BROADCAST_STRING     "STI\\" STI_ADD_DEVICE_BROADCAST_ACTION "\\%s"
'#define STI_REMOVE_DEVICE_BROADCAST_STRING  "STI\\" STI_REMOVE_DEVICE_BROADCAST_ACTION "\\%s"

$STI_ADD_DEVICE_BROADCAST_STRING    = "STI\Arrival\%s"
$STI_REMOVE_DEVICE_BROADCAST_STRING = "STI\Removal\%s"

' // end STI broadcasting


' //
' // Device create modes
' //

' // Device is being opened only for status querying and notifications receiving
%STI_DEVICE_CREATE_STATUS         = &H00000001???

' // Device is being opened for data transfer ( supersedes status mode)
%STI_DEVICE_CREATE_DATA           = &H00000002???

%STI_DEVICE_CREATE_BOTH           = &H00000003???

' //
' // Bit mask for legitimate mode bits, which can be used when calling CreateDevice
' //
%STI_DEVICE_CREATE_MASK           = &H0000FFFF???

' //
' // Flags controlling device enumeration
' //
%STIEDFL_ALLDEVICES               = &H00000000???
%STIEDFL_ATTACHEDONLY             = &H00000001???

' //
' // Control code , sent to the device through raw control interface
' //
'typedef  DWORD STI_RAW_CONTROL_CODE;

' //
' // All raw codes below this one are reserved for future use.
' //
%STI_RAW_RESERVED    = &H1000

' /*
'  * COM Interfaces to STI
'  */

'STDMETHODIMP StiCreateInstanceW(HINSTANCE hinst, DWORD dwVer, interface IStillImageW **ppSti, LPUNKNOWN punkOuter);

'#if defined(UNICODE) || defined(STI_UNICODE)
'#define IID_IStillImage     IID_IStillImageW
'#define IStillImage         IStillImageW
'#define StiCreateInstance   StiCreateInstanceW
'#endif

DECLARE FUNCTION StiCreateInstanceW IMPORT "STI.DLL" ALIAS "StiCreateInstanceW" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL dwVer AS DWORD _                               ' __in  DWORD dwVer
 , BYREF ppSti AS IStillImageW _                        ' __out IStillImageW **ppSti
 , BYVAL punkOuter AS IUnknown _                        ' __in  LPUNKNOWN punkOuter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StiCreateInstance IMPORT "STI.DLL" ALIAS "StiCreateInstanceW" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL dwVer AS DWORD _                               ' __in  DWORD dwVer
 , BYREF ppSti AS IStillImage _                         ' __out IStillImage **ppSti
 , BYVAL punkOuter AS IUnknown _                        ' __in  LPUNKNOWN punkOuter
 ) AS LONG                                              ' HRESULT

'/*
' * IStillImage interface
' *
' * Top level STI access interface.
' *
' */

' ########################################################################################
' Interface name = IStillImageW
' IID = 641BD880-2DC8-11D0-90EA-00AA0060F86C
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IStillImageW $IID_IStillImageW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD     dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceList ( _                             ' VTable offset = 16
     BYVAL dwType AS DWORD _                            ' __in  DWORD   dwType
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD   dwFlags
   , BYREF pdwItemsReturned AS DWORD _                  ' __out DWORD  *pdwItemsReturned
   , BYREF ppBuffer AS DWORD _                          ' __out LPVOID *ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 20
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in  LPWSTR  pwszDeviceName
   , BYREF ppBuffer AS DWORD _                          ' __out LPVOID *ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 24
     BYVAL pwszDeviceName AS DWORD _                    ' __in  LPWSTR      pwszDeviceName
   , BYVAL dwMode AS DWORD _                            ' __in  DWORD       dwMode
   , BYREF pDevice AS IStiDevice _                      ' __out PSTIDEVICE *pDevice
   , BYVAL punkOuter AS IUnknown _                      ' __in  LPUNKNOWN   punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceValue ( _                            ' VTable offset = 28
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in  LPWSTR  pwszDeviceName
   , BYREF pValueName AS WSTRINGZ _                     ' __in  LPWSTR  pValueName
   , BYREF pType AS DWORD _                             ' __out LPDWORD pType
   , BYVAL pData AS DWORD _                             ' __out LPBYTE  pData
   , BYREF cbData AS DWORD _                            ' __out LPDWORD cbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeviceValue ( _                            ' VTable offset = 32
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in LPWSTR  pwszDeviceName
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPWSTR  pValueName
   , BYVAL Type AS DWORD _                              ' __in DWORD   Type
   , BYVAL pData AS DWORD _                             ' __in LPBYTE  pData
   , BYVAL cbData AS DWORD _                            ' __in DWORD   cbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSTILaunchInformation ( _                   ' VTable offset = 36
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in  LPWSTR  pwszDeviceName
   , BYREF pdwEventCode AS DWORD _                      ' __out DWORD  *pdwEventCode
   , BYREF pwszEventName AS WSTRINGZ _                  ' __in  LPWSTR  pwszEventName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterLaunchApplication ( _                 ' VTable offset = 40
     BYREF pwszAppName AS WSTRINGZ _                    ' __in LPWSTR  pwszAppName
   , BYREF pwszCommandLine AS WSTRINGZ _                ' __in LPWSTR  pwszCommandLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterLaunchApplication ( _               ' VTable offset = 44
     BYREF pwszAppName AS WSTRINGZ _                    ' __in LPWSTR  pwszAppName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableHwNotifications ( _                     ' VTable offset = 48
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in LPWSTR  pwszDeviceName
   , BYVAL bNewState AS LONG _                          ' __in BOOL    bNewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHwNotificationState ( _                    ' VTable offset = 52
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in  LPWSTR  pwszDeviceName
   , BYREF pbCurrentState AS LONG _                     ' __out BOOL   *pbCurrentState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RefreshDeviceBus ( _                          ' VTable offset = 56
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in LPCWSTR  pwszDeviceName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LaunchApplicationForDevice ( _                ' VTable offset = 60
     BYREF pwszDeviceName AS WSTRINGZ _                 ' __in  LPCWSTR     pwszDeviceName
   , BYREF pwszAppName AS WSTRINGZ _                    ' __in  LPWSTR      pwszAppName
   , BYREF pStiNotify AS STINOTIFY _                    ' __out LPSTINOTIFY pStiNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetupDeviceParameters ( _                     ' VTable offset = 64
     BYREF pDevInfo AS STI_DEVICE_INFORMATION _         ' __in PSTI_DEVICE_INFORMATIONW pDevInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteToErrorLog ( _                           ' VTable offset = 68
     BYVAL dwMessageType AS DWORD _                     ' __in DWORD dwMessageType
   , BYREF pszMessage AS WSTRINGZ _                     ' __in LPCWSTR pszMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IStillImageA
' IID = A7B1F740-1D7F-11D1-ACA9-00A02438AD48
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IStillImage $IID_IStillImage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD     dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceList ( _                             ' VTable offset = 16
     BYVAL dwType AS DWORD _                            ' __in  DWORD   dwType
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD   dwFlags
   , BYREF pdwItemsReturned AS DWORD _                  ' __out DWORD  *pdwItemsReturned
   , BYREF ppBuffer AS DWORD _                          ' __out LPVOID *ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 20
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in  LPSTR   pwszDeviceName
   , BYREF ppBuffer AS DWORD _                          ' __out LPVOID *ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 24
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in  LPSTR       pwszDeviceName
   , BYVAL dwMode AS DWORD _                            ' __in  DWORD       dwMode
   , BYREF pDevice AS IStiDevice _                      ' __out PSTIDEVICE *pDevice
   , BYVAL punkOuter AS IUnknown _                      ' __in  LPUNKNOWN   punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceValue ( _                            ' VTable offset = 28
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in  LPSTR   pwszDeviceName
   , BYREF pValueName AS ASCIIZ _                       ' __in  LPSTR   pValueName
   , BYREF pType AS DWORD _                             ' __out LPDWORD pType
   , BYVAL pData AS DWORD _                             ' __out LPBYTE  pData
   , BYREF cbData AS DWORD _                            ' __out LPDWORD cbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeviceValue ( _                            ' VTable offset = 32
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in LPSTR   pwszDeviceName
   , BYREF pValueName AS ASCIIZ _                       ' __in LPSTR   pValueName
   , BYVAL Type AS DWORD _                              ' __in DWORD   Type
   , BYVAL pData AS DWORD _                             ' __in LPBYTE  pData
   , BYVAL cbData AS DWORD _                            ' __in DWORD   cbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSTILaunchInformation ( _                   ' VTable offset = 36
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in  LPCSTR  pwszDeviceName
   , BYREF pdwEventCode AS DWORD _                      ' __out DWORD  *pdwEventCode
   , BYREF pwszEventName AS ASCIIZ _                    ' __in  LPCSTR  pwszEventName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterLaunchApplication ( _                 ' VTable offset = 40
     BYREF pwszAppName AS ASCIIZ _                      ' __in LPSTR   pwszAppName
   , BYREF pwszCommandLine AS ASCIIZ _                  ' __in LPSTR   pwszCommandLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterLaunchApplication ( _               ' VTable offset = 44
     BYREF pwszAppName AS ASCIIZ _                      ' __in LPSTR   pwszAppName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableHwNotifications ( _                     ' VTable offset = 48
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in LPSTR   pwszDeviceName
   , BYVAL bNewState AS LONG _                          ' __in BOOL    bNewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHwNotificationState ( _                    ' VTable offset = 52
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in  LPSTR   pwszDeviceName
   , BYREF pbCurrentState AS LONG _                     ' __out BOOL   *pbCurrentState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RefreshDeviceBus ( _                          ' VTable offset = 56
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in LPCSTR  pwszDeviceName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LaunchApplicationForDevice ( _                ' VTable offset = 60
     BYREF pwszDeviceName AS ASCIIZ _                   ' __in  LPCSTR     pwszDeviceName
   , BYREF pwszAppName AS ASCIIZ _                      ' __in  LPSTR      pwszAppName
   , BYREF pStiNotify AS STINOTIFY _                    ' __out LPSTINOTIFY pStiNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetupDeviceParameters ( _                     ' VTable offset = 64
     BYREF pDevInfo AS STI_DEVICE_INFORMATION _         ' __in PSTI_DEVICE_INFORMATION pDevInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteToErrorLog ( _                           ' VTable offset = 68
     BYVAL dwMessageType AS DWORD _                     ' __in DWORD dwMessageType
   , BYREF pszMessage AS ASCIIZ _                       ' __in LPCSTR pszMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/*
' * IStillImage_Device interface
' *
' * This is generic per device interface. Specialized interfaces are also
' * available
' */

' ########################################################################################
' Interface name = IStiDevice
' IID = 6CFA5A80-2DC8-11D0-90EA-00AA0060F86C
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IStiDevice $IID_IStiDevice

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYREF pwszDeviceName AS WSTRINGZ _                 ' __in LPCWSTR   pwszDeviceName
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD     dwVersion
   , BYVAL dwMode AS DWORD _                            ' __in DWORD     dwMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 16
     BYREF pDevCaps AS STI_DEV_CAPS _                   ' __out PSTI_DEV_CAPS pDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 20
     BYREF pDevStatus AS STI_DEVICE_STATUS _            ' __out PSTI_DEV_CAPS pDevStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceReset ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Diagnostic ( _                                ' VTable offset = 28
     BYREF pBuffer AS STI_DIAG _                        ' __in LPSTI_DIAG pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 32
     BYVAL EscapeFunction AS DWORD _                    ' __in  STI_RAW_CONTROL_CODE EscapeFunction
   , BYVAL lpInData AS DWORD _                          ' __in  LPVOID  lpInData
   , BYVAL cbInDataSize AS DWORD _                      ' __in  DWORD   cbInDataSize
   , BYVAL pOutData AS DWORD _                          ' __in  LPVOID  pOutData
   , BYVAL dwOutDataSize AS DWORD _                     ' __in  DWORD   dwOutDataSize
   , BYREF pdwActualData AS DWORD _                     ' __out LPDWORD pdwActualData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 36
     BYREF pdwLastDeviceError AS DWORD _                ' __out LPDWORD pdwLastDeviceError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockDevice ( _                                ' VTable offset = 40
     BYVAL dwTimeOut AS DWORD _                         ' __in DWORD dwTimeOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnLockDevice ( _                              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RawReadData ( _                               ' VTable offset = 48
     BYVAL lpBuffer AS DWORD _                          ' __in  LPVOID lpBuffer
   , BYREF lpdwNumberOfBytes AS DWORD _                 ' __out LPDWORD lpdwNumberOfBytes
   , BYREF lpOverlapped AS OVERLAPPED _                 ' __out LPOVERLAPPED lpOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RawWriteData ( _                              ' VTable offset = 52
     BYVAL lpBuffer AS DWORD _                          ' __in LPVOID lpBuffer
   , BYVAL nNumberOfBytes AS DWORD _                    ' __in DWORD nNumberOfBytes
   , BYREF lpOverlapped AS OVERLAPPED _                 ' __in LPOVERLAPPED lpOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RawReadCommand ( _                            ' VTable offset = 56
     BYVAL lpBuffer AS DWORD _                          ' __in  LPVOID lpBuffer
   , BYREF lpdwNumberOfBytes AS DWORD _                 ' __out LPDWORD lpdwNumberOfBytes
   , BYREF lpOverlapped AS OVERLAPPED _                 ' __out LPOVERLAPPED lpOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RawWriteCommand ( _                           ' VTable offset = 60
     BYVAL lpBuffer AS DWORD _                          ' __in LPVOID lpBuffer
   , BYVAL nNumberOfBytes AS DWORD _                    ' __in DWORD nNumberOfBytes
   , BYREF lpOverlapped AS OVERLAPPED _                 ' __in LPOVERLAPPED lpOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Subscribe ( _                                 ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastNotificationData ( _                   ' VTable offset = 68
     BYREF lpNotify AS STINOTIFY _                      ' __out LPSTINOTIFY lpNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnSubscribe ( _                               ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastErrorInfo ( _                          ' VTable offset = 76
     BYREF pLastErrorInfo AS STI_ERROR_INFO _           ' __out STI_ERROR_INFO *pLastErrorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' //
' // Reset packing
' //
'#include <poppack.h>
