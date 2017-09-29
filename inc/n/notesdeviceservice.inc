' ########################################################################################
' Microsoft Windows
' File: NotesDeviceService.inc
' Contents: Declarations for the Notes Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NOTESDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"
#INCLUDE ONCE "MessageDeviceService.inc"

'/*****************************************************************************/
'/*  Notes Service Info                                                       */
'/*****************************************************************************/

$SERVICE_Notes = GUID$("{5c017aea-e706-4719-8cc0-a303836fd321}")

$$NAME_NotesSvc                      = "Notes"$$
%TYPE_NotesSvc                       = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Notes Service Object Formats                                             */
'/*****************************************************************************/

'/*  FORMAT_AbstractNote
' */

$FORMAT_AbstractNote = GUID$("{b3d1b688-39f6-4703-b339-c69b7d2abb3f}")

$$NAME_AbstractNote                  = "AbstractNote"$$


'/*****************************************************************************/
'/*  Notes Service Object Property Keys                                       */
'/*****************************************************************************/

$NAMESPACE_NotesObj = GUID$("{5FFBFC7B-7483-41AD-AFB9-DA3F4E592B8D}")
