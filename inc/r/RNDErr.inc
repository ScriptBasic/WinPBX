' ########################################################################################
' Microsoft Windows
' File: RNDErr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RNDERR_INC = 1

#INCLUDE ONCE "blberr.inc"

'// rendezvous component error codes

'// First four bits - SEVERITY(11), CUSTOMER FLAG(1), RESERVED(0)
%RND_INVALID_TIME                  = &He0000200&
%RND_NULL_SERVER_NAME              = &He0000201&
%RND_ALREADY_CONNECTED             = &He0000202&
%RND_NOT_CONNECTED                 = &He0000203&
