' ########################################################################################
' Microsoft Windows
' File: blberr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BLBERR_INC = 1

#INCLUDE ONCE "sdperr.inc"

'// First four bits - SEVERITY(11), CUSTOMER FLAG(1), RESERVED(0)
%SDPBLB_CONF_BLOB_DESTROYED = &HE0000300&
