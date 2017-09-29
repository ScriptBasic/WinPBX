' ########################################################################################
' Microsoft Windows
' File: adsdb.inc
' Contents: Definitions for the OLE DB provider for ADSI
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADSDB_INC = 1

'// Most of the constants have been moved into an enum in adstype.inc and
'// are available publicly in iads.inc. This file has been left here so that
'// old references to adsdb.inc do not break compiles.

%DBPROPFLAGS_ADSISEARCH = &H0000C000???
