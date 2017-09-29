' ########################################################################################
' Microsoft Windows
' File: persist.inc
' Contents: MSPersist external constants GUIDS and other things users need
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PERSIST_INC = 1

'// Persist Properties
%DBPROPFLAGS_PERSIST    = &H2000

%DBPROPVAL_PERSIST_ADTG = 0
%DBPROPVAL_PERSIST_XML  = 1
%DBPROP_PersistFormat   = 2
%DBPROP_PersistSchema   = 3
%DBPROP_HCHAPTER        = 4
%DBPROP_MAINTAINPROPS   = 5

'// XML writing only properties
%DBPROP_Unicode         = 6

'// internal property (read-only)
%DBPROP_INTERLEAVEDROWS = 8

$CLSID_MSPersist   = GUID$("{7C07E0D0-4418-11D2-921200C04FBBBFB3}")
$DBPROPSET_PERSIST = GUID$("{4D7839A0-5B8E-11D1-A6B3-00A0C9138C66}")

$MS_PERSIST_PROGID        = "MSPersist"
$PROGID_MSPersist         = "MSPersist"
$PROGID_MSPersist_Version = "MSPersist.1"

$$PROGID_MSPersist_W         = "MSPersist"$$
$$PROGID_MSPersist_Version_W = "MSPersist.1"$$
