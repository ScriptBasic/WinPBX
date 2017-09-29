' ########################################################################################
' Microsoft Windows
' File: Wab.inc
' Contents: Windows Address Book
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WAB_INC = 1

'/*
' * WAB.H
' *
' * Top level public header for WAB API functions.
' *
' */

'#include <wabdefs.h>
'#include <wabcode.h>
'#include <wabtags.h>
'#include <wabutil.h>
'#include <wabiab.h>
'#include <wabapi.h>
'#include <wabmem.h>
'#include <wabnot.h>


' NOTE: Most of the constants and interfaces are the same than MAPIX, so we are
' going to reuse them by including the MAPI include files and only listing the
' differences.

' ========================================================================================
' WABDEFS.H
' ========================================================================================

#INCLUDE ONCE "mapidefs.inc"

'/* GetContentsTable() */
%WAB_LOCAL_CONTAINERS = &H00100000???
%WAB_PROFILE_CONTENTS = &H00200000???

'/* ResolveNames() - ulFlags */
%WAB_IGNORE_PROFILES = &H00800000???

' ========================================================================================
' WABCODE.H
' ========================================================================================

#INCLUDE ONCE "mapicode.inc"

' ========================================================================================
' WABTAGS.H
' ========================================================================================

#INCLUDE ONCE "mapitags.inc"

'#define PR_USER_X509_CERTIFICATE                    PROP_TAG( PT_MV_BINARY, 0x3A70)
'#define PR_SEND_INTERNET_ENCODING                   PROP_TAG( PT_LONG,      0x3A71)

%PR_USER_X509_CERTIFICATE  = &H3A701102
%PR_SEND_INTERNET_ENCODING = &H3A710003

'/* These are the bits that show up in PR_SEND_INTERNET_ENCODING */

'/* whether or not an encoding preference is specified
'   1 - pay attention to the rest of the bits for the encoding preferences
'   0 - let the mail system choose what's best for it
' */
%ENCODING_PREFERENCE = &H00020000???

'/*
'   1 - message in MIME;
'   0 - plain text/uuencode attachments
' */
%ENCODING_TEXT = &H00000000???
%ENCODING_MIME = &H00040000???


'/*  Specifies how the body of the message is encoded.
'    00 - Body encoded as text
'        01 - body encoded as HTML (only valid if message in MIME)
'        10 - (actualy 1X) Text and HTML as multipart alternative (only valid if message in MIME)
' */
%BODY_ENCODING_MASK = &H00180000???
%BODY_ENCODING_TEXT = &H00000000???   ' /* for completeness */
%BODY_ENCODING_HTML = &H00080000???
%BODY_ENCODING_TEXT_AND_HTML = &H00100000???

'/*  Specifies how to handle Mac attachments
'    00 - BinHex
'        01 - UUENCODED (not valid if message in MIME - will be ignored, BinHex used instead)
'        10 - Apple Single (only valid if message in MIME)
'        11 - Apple Double (only valid if message in MIME)
' */
%MAC_ATTACH_ENCODING_MASK = &H00600000???
%MAC_ATTACH_ENCODING_BINHEX = &H00000000???
%MAC_ATTACH_ENCODING_UUENCODE = &H00200000???
%MAC_ATTACH_ENCODING_APPLESINGLE = &H00400000???
%MAC_ATTACH_ENCODING_APPLEDOUBLE = &H0600000???


'// Values for PR_GENDER property

%genderUnspecified = 0
%genderFemale = 1
%genderMale = 2

' ========================================================================================
' WABUTIL.H
' ========================================================================================

#INCLUDE ONCE "mapiutil.inc"

' ========================================================================================
' WABIAB.H
' ========================================================================================

'// These are WAB only flags for IAdrBook::ResolveName
%WAB_RESOLVE_LOCAL_ONLY          = &H80000000???
%WAB_RESOLVE_ALL_EMAILS          = &H40000000???
%WAB_RESOLVE_NO_ONE_OFFS         = &H20000000???
%WAB_RESOLVE_NEED_CERT           = &H10000000???
%WAB_RESOLVE_NO_NOT_FOUND_UI     = &H08000000???
%WAB_RESOLVE_USE_CURRENT_PROFILE = &H04000000???
%WAB_RESOLVE_FIRST_MATCH         = &H02000000???
%WAB_RESOLVE_UNICODE             = &H01000000???
'// %MAPI_DIALOG                     = &H00000008???


' ========================================================================================
' WABAPI.H
' ========================================================================================

#INCLUDE ONCE "wabapi.inc"

' ========================================================================================
' WABMEM.H
' ========================================================================================

DECLARE FUNCTION WABAllocateBuffer IMPORT "MAPI32.DLL" ALIAS "MAPIAllocateBuffer" ( _
   BYVAL cbSize AS DWORD _                              ' __in ULONG cbSize
 , BYREF lppBuffer AS ANY _                             ' __out LPVOID FAR * lppBuffer
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION WABAllocateMore IMPORT "MAPI32.DLL" ALIAS "MAPIAllocateMore" ( _
   BYVAL cbSize AS DWORD _                              ' __in ULONG cbSize
 , BYVAL lpObject AS DWORD _                            ' __in LPVOID lpObject
 , BYREF lppBuffer AS ANY _                             ' __out LPVOID FAR * lppBuffer
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION WABFreeBuffer IMPORT "MAPI32.DLL" ALIAS "MAPIFreeBuffer" ( _
   BYVAL lpBuffer AS DWORD _                            ' __in LPVOID lpBuffer
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' WABNOT.H
' ========================================================================================

#INCLUDE ONCE "mapispi.inc"
