' ########################################################################################
' Microsoft Windows
' File: ActiveDs.inc
' Contents: Master include file for Ole Ds
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACTIVEDS_INC = 1

'//
'// Interface definitions and well known GUIDS for Ole Ds
'//

#INCLUDE ONCE "iads.inc"

'//
'// Helper function prototypes for Ole Ds
'//

#INCLUDE ONCE "adshlp.inc"

'//
'// Error codes for Ole Ds - generated from ..\..\errmsg
'//

#INCLUDE ONCE "adserr.inc"

'//
'// Globally accessible GUIDS
'//

'#INCLUDE "adsiid.h"

'//
'// Status codes for ads objects
'//

#INCLUDE ONCE "adssts.inc"

'//
'// Schema class names and other schema related definitions
'//

#INCLUDE ONCE "adsnms.inc"

'//
'// Definitions in the OLE DB provider for ADSI
'//

#INCLUDE ONCE "adsdb.inc"
