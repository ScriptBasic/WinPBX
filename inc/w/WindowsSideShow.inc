' ########################################################################################
' Microsoft Windows
' File: WindowsSideShow.inc
' Contents: This file defines supporting structures and values used in the Windows
' SideShow platform.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINDOWSSIDESHOW_INC = 1

'#pragma once
'#if (_WIN32_WINNT >= 0x0600) // Windows Vista and later

#INCLUDE ONCE "propkeydef.inc"

'/****************************************************************************
' * This section defines platform constants
' ****************************************************************************/

'const   CONTENT_ID      CONTENT_ID_GLANCE = 0;
%CONTENT_ID_GLANCE = 0???

'// Event IDs for ApplicationEvents fired by the device when the user enters/exits
'// an application on the device.
'const   DWORD           SIDESHOW_EVENTID_APPLICATION_ENTER  = 0xFFFF0000;
'const   DWORD           SIDESHOW_EVENTID_APPLICATION_EXIT   = 0xFFFF0001;
%SIDESHOW_EVENTID_APPLICATION_ENTER  = &HFFFF0000???
%SIDESHOW_EVENTID_APPLICATION_EXIT   = &HFFFF0001???


'/****************************************************************************
' * This section defines well-known device endpoints
' ****************************************************************************/

'// {A9A5353F-2D4B-47ce-93EE-759F3A7DDA4F}
'DEFINE_GUID(SIDESHOW_ENDPOINT_SIMPLE_CONTENT_FORMAT,    0xa9a5353f, 0x2d4b, 0x47ce, 0x93, 0xee, 0x75, 0x9f, 0x3a, 0x7d, 0xda, 0x4f);
$SIDESHOW_ENDPOINT_SIMPLE_CONTENT_FORMAT = GUID$("{A9A5353F-2D4B-47ce-93EE-759F3A7DDA4F}")

'// {4DFF36B5-9DDE-4F76-9A2A-96435047063D}
'DEFINE_GUID(SIDESHOW_ENDPOINT_ICAL,                     0x4dff36b5, 0x9dde, 0x4f76, 0x9a, 0x2a, 0x96, 0x43, 0x50, 0x47, 0x06, 0x3d);
$SIDESHOW_ENDPOINT_ICAL = GUID$("{4DFF36B5-9DDE-4F76-9A2A-96435047063D}")


'/****************************************************************************
' * This section defines well-known device capabilities
' ****************************************************************************/

'// {8ABC88A8-857B-4ad7-A35A-B5942F492B99}
'DEFINE_GUID(SIDESHOW_CAPABILITY_DEVICE_PROPERTIES,          0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99);
$SIDESHOW_CAPABILITY_DEVICE_PROPERTIES = GUID$("{8ABC88A8-857B-4ad7-A35A-B5942F492B99}")

'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_DEVICE_ID,           0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 1); // [ VT_LPWSTR ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SCREEN_TYPE,         0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 2); // [ VT_I4 ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SCREEN_WIDTH,        0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 3); // [ VT_UI2 ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SCREEN_HEIGHT,       0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 4); // [ VT_UI2 ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_COLOR_DEPTH,         0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 5); // [ VT_UI2 ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_COLOR_TYPE,          0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 6); // [ VT_I4 ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_DATA_CACHE,          0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 7); // [ VT_BOOL ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SUPPORTED_LANGUAGES, 0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 8); // [ VT_LPWSTR ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_CURRENT_LANGUAGE,    0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 9); // [ VT_LPWSTR ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SUPPORTED_THEMES,    0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 10);// [ VT_LPWSTR ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_SUPPORTED_IMAGE_FORMATS, 0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 14);// [ VT_LPWSTR ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_CLIENT_AREA_WIDTH,   0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 15);// [ VT_UI2 ]
'DEFINE_PROPERTYKEY(SIDESHOW_CAPABILITY_CLIENT_AREA_HEIGHT,  0x8abc88a8, 0x857b, 0x4ad7, 0xa3, 0x5a, 0xb5, 0x94, 0x2f, 0x49, 0x2b, 0x99, 16);// [ VT_UI2 ]

MACRO SIDESHOW_CAPABILITY_DEVICE_ID               = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(1)
MACRO SIDESHOW_CAPABILITY_SCREEN_TYPE             = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(2)
MACRO SIDESHOW_CAPABILITY_SCREEN_WIDTH            = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(3)
MACRO SIDESHOW_CAPABILITY_SCREEN_HEIGHT           = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(4)
MACRO SIDESHOW_CAPABILITY_COLOR_DEPTH             = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(5)
MACRO SIDESHOW_CAPABILITY_COLOR_TYPE              = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(6)
MACRO SIDESHOW_CAPABILITY_DATA_CACHE              = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(7)
MACRO SIDESHOW_CAPABILITY_SUPPORTED_LANGUAGES     = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(8)
MACRO SIDESHOW_CAPABILITY_CURRENT_LANGUAGE        = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(9)
MACRO SIDESHOW_CAPABILITY_SUPPORTED_THEMES        = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(10)
MACRO SIDESHOW_CAPABILITY_SUPPORTED_IMAGE_FORMATS = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(14)
MACRO SIDESHOW_CAPABILITY_CLIENT_AREA_WIDTH       = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(15)
MACRO SIDESHOW_CAPABILITY_CLIENT_AREA_HEIGHT      = GUID$("{8abc88a8-857b-4ad7-a35a-b5942f492b99}") & MKDWD$(16)

'/****************************************************************************
' * This section defines enumerations used by the device capabilities
' ****************************************************************************/

'// Used with SIDESHOW_CAPABILITY_SCREEN_TYPE
' enum SIDESHOW_SCREEN_TYPE
%SIDESHOW_SCREEN_TYPE_BITMAP = 0
%SIDESHOW_SCREEN_TYPE_TEXT   = 1

'// Used with SIDESHOW_CAPABILITY_COLOR_TYPE
' enum SIDESHOW_COLOR_TYPE
%SIDESHOW_COLOR_TYPE_COLOR           = 0
%SIDESHOW_COLOR_TYPE_GREYSCALE       = 1
%SIDESHOW_COLOR_TYPE_BLACK_AND_WHITE = 2


'/****************************************************************************
' * This section defines constants, structures and enumerations relating to
' * the Simple Content Format
' ****************************************************************************/

'// The content id of the home page for a Simple Content Format application
'const CONTENT_ID    CONTENT_ID_HOME     = 1;
%CONTENT_ID_HOME = 1

'// The ApplicationEvent event ids from the Simple Content Format device application
' enum SCF_EVENT_IDS
%SCF_EVENT_NAVIGATION  = 1
%SCF_EVENT_MENUACTION  = 2
%SCF_EVENT_CONTEXTMENU = 3

'// The button ids used in the Simple Content Format events
' enum SCF_BUTTON_IDS
%SCF_BUTTON_MENU        = 1
%SCF_BUTTON_SELECT      = 2
%SCF_BUTTON_UP          = 3
%SCF_BUTTON_DOWN        = 4
%SCF_BUTTON_LEFT        = 5
%SCF_BUTTON_RIGHT       = 6
%SCF_BUTTON_PLAY        = 7
%SCF_BUTTON_PAUSE       = 8
%SCF_BUTTON_FASTFORWARD = 9
%SCF_BUTTON_REWIND      = 10
%SCF_BUTTON_STOP        = 11
%SCF_BUTTON_BACK        = 65280   ' // 0xFF00

'// A header structure that is common amongst all Simple Content Format event structures
' // Size = 8 bytes
TYPE SCF_EVENT_HEADER DWORD
   PreviousPage AS DWORD   ' CONTENT_ID
   TargetPage   AS DWORD   ' CONTENT_ID
END TYPE

'// The data passed with an SCF_EVENT_NAVIGATION ApplicationEvent
' // Size = 12 bytes
TYPE SCF_NAVIGATION_EVENT DWORD
   PreviousPage AS DWORD   ' CONTENT_ID
   TargetPage   AS DWORD   ' CONTENT_ID
   Button       AS DWORD   ' UINT32
END TYPE

'// The data passed with an SCF_EVENT_MENUACTION ApplicationEvent
' // Size = 16 bytes
TYPE SCF_MENUACTION_EVENT DWORD
   PreviousPage AS DWORD   ' CONTENT_ID
   TargetPage   AS DWORD   ' CONTENT_ID
   Button       AS DWORD   ' UINT32
   ItemId       AS DWORD   ' UINT32
END TYPE

'// The data passed with an SCF_EVENT_CONTEXTMENU ApplicationEvent
' // Size = 20 bytes
TYPE SCF_CONTEXTMENU_EVENT DWORD
   PreviousPage   AS DWORD   ' CONTENT_ID
   TargetPage     AS DWORD   ' CONTENT_ID
   PreviousItemId AS DWORD   ' UINT32
   MenuPage       AS DWORD   ' CONTENT_ID
   MenuItemId     AS DWORD   ' UINT32
END TYPE

'#endif // (_WIN32_WINNT >= 0x0600)
