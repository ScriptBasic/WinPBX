' ########################################################################################
' Microsoft Windows
' File: sliddefs.inc
' Contents: Software Licensing GUID definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SLIDDEFS_INC = 1

#IF NOT %DEF(%WINDOWS_SLID)
%WINDOWS_SLID = 1
$WINDOWS_SLID = GUID$("{55C92734-D682-4D71-983E-D6EC3F16059F}")
#ENDIF
