' ########################################################################################
' Microsoft Windows
' File: RingtoneDeviceService.inc
' Contents: Declarations for the Ringtone Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RINGTONEDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"
#INCLUDE ONCE "MessageDeviceService.inc"


'/*****************************************************************************/
'/*  Ringtone Service Info                                                    */
'/*****************************************************************************/

$SERVICE_Ringtones = GUID$("{d0eace0e-707d-4106-8d38-4f560e6a9f8e}")

$$NAME_RingtonesSvc                  = "Ringtones"$$
%TYPE_RingtonesSvc                   = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Ringtone Service Properties                                              */
'/*****************************************************************************/

$NAMESPACE_RingtonesSvc = GUID$("{7d05d925-32e6-4790-9205-54764bb3cb74}")

'/*  PKEY_RingtonesSvc_DefaultRingtone
' *
' *  Indicates the objectID of the default ringtone for incoming calls
' *
' *  Type: UInt32
' *  Form: ObjectID
' */

MACRO PKEY_RingtonesSvc_DefaultRingtone = GUID$("{7d05d925-32e6-4790-9205-54764bb3cb74}") & MKDWD$(2)

$$NAME_RingtonesSvc_DefaultRingtone = "DefaultRingtone"$$


'/*****************************************************************************/
'/*  Ringtone Service Object Properties                                       */
'/*****************************************************************************/

$NAMESPACE_RingtonesObj = GUID$("{8d943c78-2c7d-4c74-945a-42d83cb58b5a}")
