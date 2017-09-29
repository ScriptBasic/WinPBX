' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryError.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERYERROR_INC = 1

#INCLUDE ONCE "winerror.inc"

'// Error codes
'//
'//

'// MessageId: E_FDPAIRING_NOCONNECTION
'//
'// MessageText:
'//
'// The device has rejected the connection.
'//
%E_FDPAIRING_NOCONNECTION        = &H8FD00001&

'// MessageId: E_FDPAIRING_NOCONNECTION
'//
'// MessageText:
'//
'// The device has indicated a hardware failure.
'//
%E_FDPAIRING_HWFAILURE           = &H8FD00002&

'// MessageId: E_FDPAIRING_AUTHFAILURE
'//
'// MessageText:
'//
'// The device authentication has failed.  Either the device has rejected the authentication or you rejected the authentication.
'//
%E_FDPAIRING_AUTHFAILURE         = &H8FD00003&

'// MessageId: E_FDPAIRING_CONNECTTIMEOUT
'//
'// MessageText:
'//
'// The time to finish the authentication has expired on the device.
'//
%E_FDPAIRING_CONNECTTIMEOUT      = &H8FD00004&

'// MessageId: E_FDPAIRING_TOOMANYCONNECTIONS
'//
'// MessageText:
'//
'// The device has indicated that it cannot accept more incoming connections.
'//
%E_FDPAIRING_TOOMANYCONNECTIONS  = &H8FD00005&

'// MessageId: E_FDPAIRING_AUTHNOTALLOWED
'//
'// MessageText:
'//
'// The device has indicated that the authentication is not allowed.
'//
%E_FDPAIRING_AUTHNOTALLOWED      = &H8FD00006&

'// MessageId: E_FDPAIRING_AUTHNOTALLOWED
'//
'// MessageText:
'//
'// The Pnp-X Bus Enumerator service is disabled.
'//
%E_FDPAIRING_IPBUSDISABLED      = &H8FD00007&

'// MessageId: E_FDPAIRING_NOPROFILES
'//
'// MessageText:
'//
'// Windows does not have any network profiles for this device to use.
'//
%E_FDPAIRING_NOPROFILES         = &H8FD00008&
