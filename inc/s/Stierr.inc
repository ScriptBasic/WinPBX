' ########################################################################################
' Microsoft Windows
' File: Stierr.inc
' Contents: This module contains the user mode still image APIs error and status codes
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STIERR_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "winerror.inc"

'//
'// Generic test for success on any status value (non-negative numbers
'// indicate success).
'//

'#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
MACRO NT_SUCCESS (nStatus) = (-(BITS(LONG, nStatus) >= 0))

'//
'// Generic test for information on any status value.
'//

'#define NT_INFORMATION(Status) ((ULONG)(Status) >> 30 == 1)
FUNCTION NT_INFORMATION(BYVAL dwStatus AS DWORD) AS LONG
   SHIFT RIGHT dwStatus, 30
   FUNCTION = (dwStatus = 1)
END FUNCTION

'//
'// Generic test for warning on any status value.
'//

'#define NT_WARNING(Status) ((ULONG)(Status) >> 30 == 2)
FUNCTION NT_WARNING(BYVAL dwStatus AS DWORD) AS LONG
   SHIFT RIGHT dwStatus, 30
   FUNCTION = (dwStatus = 2)
END FUNCTION

'//
'// Generic test for error on any status value.
'//

'#define NT_ERROR(Status) ((ULONG)(Status) >> 30 == 3)
FUNCTION NT_ERROR(BYVAL dwStatus AS DWORD) AS LONG
   SHIFT RIGHT dwStatus, 30
   FUNCTION = (dwStatus = 3)
END FUNCTION

'//
'// Error codes are constructed as compound COM status codes
'//

'/*
' * The operation completed successfully
' */
%STI_OK             = %S_OK
%STI_ERROR_NO_ERROR = %STI_OK

'/*
' * The device exists but not currently attached to the system
' */
%STI_NOTCONNECTED            = %S_FALSE

'/*
' * The requested change in device mode settings had no effect
' */
%STI_CHANGENOEFFECT          = %S_FALSE

'/*
' * The application requires newer version
' */
'#define STIERR_OLD_VERSION      \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_OLD_WIN_VERSION)

%STIERR_OLD_VERSION = &H8007047E&

'/*
' * The application was written for pre-release version of provider DLL
' */
'#define STIERR_BETA_VERSION     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_RMODE_APP)

%STIERR_BETA_VERSION = &H80070481&

'/*
' * The requested object could not be created due to incompatible or mismatched driver
' */
'#define STIERR_BADDRIVER        \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_BAD_DRIVER_LEVEL)

%STIERR_BADDRIVER = &H80070077&

'/*
' * The device is not registered
' */
%STIERR_DEVICENOTREG     = %REGDB_E_CLASSNOTREG

'/*
' * The requested container does not exist
' */
'#define STIERR_OBJECTNOTFOUND \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_FILE_NOT_FOUND)

%STIERR_OBJECTNOTFOUND = &H80070002&

'/*
' * An invalid or not state matching parameter was passed to the API
' */
%STIERR_INVALID_PARAM    = %E_INVALIDARG

'/*
' * The specified interface is not supported
' */
%STIERR_NOINTERFACE      = %E_NOINTERFACE

'/*
' * The undetermined error occured
' */
%STIERR_GENERIC          = %E_FAIL

'/*
' * There is not enough memory to perform requested operation
' */
%STIERR_OUTOFMEMORY      = %E_OUTOFMEMORY

'/*
' * The application called unsupported (at this time)function
' */
%STIERR_UNSUPPORTED      = %E_NOTIMPL

'/*
' * The application requires newer version
' */
'#define STIERR_NOT_INITIALIZED     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_NOT_READY)

%STIERR_NOT_INITIALIZED = &H80070015&

'/*
' * The application requires newer version
' */
'#define STIERR_ALREADY_INITIALIZED     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_ALREADY_INITIALIZED)

%STIERR_ALREADY_INITIALIZED = &H800704DF&

'/*
' * The operation can not performed while device is locked
' */
'#define STIERR_DEVICE_LOCKED    \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_LOCK_VIOLATION)

%STIERR_DEVICE_LOCKED = &H80070021

'/*
' * The specified propery can not be changed for this device
' */
%STIERR_READONLY         = %E_ACCESSDENIED

'/*
' * The device already has notification handle associated with it
' */
%STIERR_NOTINITIALIZED   = %E_ACCESSDENIED


'/*
' * The device needs to be locked before attempting this operation
' */
'#define STIERR_NEEDS_LOCK    \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_NOT_LOCKED)

%STIERR_NEEDS_LOCK = &H8007009E&

'/*
' * The device is opened by another application in data mode
' */
'#define STIERR_SHARING_VIOLATION    \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_SHARING_VIOLATION)

%STIERR_SHARING_VIOLATION = &H80070020&

'/*
' * Handle already set for this context
' */
'#define STIERR_HANDLEEXISTS     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_ALREADY_EXISTS)

%STIERR_HANDLEEXISTS = &H800700B7&

' /*
'  * Device name is not recognized
'  */
'#define STIERR_INVALID_DEVICE_NAME     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_INVALID_NAME)

%STIERR_INVALID_DEVICE_NAME = &H8007007B&

' /*
'  * Device hardware type is not valid
'  */
'#define STIERR_INVALID_HW_TYPE     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_INVALID_DATA)

%STIERR_INVALID_HW_TYPE = &H8007000D&

' /*
'  * No events available
'  */
'#define STIERR_NOEVENTS     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_NO_MORE_ITEMS)

%STIERR_NOEVENTS = &H80070103&

' /*
'  * Device appears as not ready
'  */
'#define STIERR_DEVICE_NOTREADY     \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_NOT_READY)

%STIERR_DEVICE_NOTREADY = &H80070015&

'//#define STIERR_
