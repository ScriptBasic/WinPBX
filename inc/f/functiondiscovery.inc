' ########################################################################################
' Microsoft Windows
' File: FunctionDiscovery.inc
' Library name: FctnDiscLib
' Version: 1.0, Locale ID = 0
' Library GUID: {A1CCFEB3-EBFA-44B7-9D53-CAF2D18A1782}
' Library name: fundisc.dll
' Contents: Function Discovery 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERY_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "FunctionDiscoveryAPI.inc"

$LIBID_FctnDiscLib = GUID$("{A1CCFEB3-EBFA-44B7-9D53-CAF2D18A1782}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {C72BE2EC-8E90-452C-B29A-AB8FF1C071FC}
$PROGID_FunctionDiscovery1 = "FunctionDiscovery.Discovery.1"
' CLSID = {BA818CE5-B55F-443F-AD39-2FE89BE6191F}
$PROGID_FunctionInstanceCollection1 = "FunctionDiscovery.FunctionInstanceCollection.1"
' CLSID = {E4796550-DF61-448B-9193-13FC1341B163}
$PROGID_PropertyStore1 = "FunctionDiscovery.PropertyStore.1"
' CLSID = {EDD36029-D753-4862-AA5B-5BCCAD2A4D29}
$PROGID_PropertyStoreCollection1 = "FunctionDiscovery.PropertyStoreCollection.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {C72BE2EC-8E90-452C-B29A-AB8FF1C071FC}
$PROGID_FunctionDiscovery = "FunctionDiscovery.Discovery"
' CLSID = {BA818CE5-B55F-443F-AD39-2FE89BE6191F}
$PROGID_FunctionInstanceCollection = "FunctionDiscovery.FunctionInstanceCollection"
' CLSID = {E4796550-DF61-448B-9193-13FC1341B163}
$PROGID_PropertyStore = "FunctionDiscovery.PropertyStore"
' CLSID = {EDD36029-D753-4862-AA5B-5BCCAD2A4D29}
$PROGID_PropertyStoreCollection = "FunctionDiscovery.PropertyStoreCollection"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_FunctionDiscovery = GUID$("{C72BE2EC-8E90-452C-B29A-AB8FF1C071FC}")
$CLSID_FunctionInstanceCollection = GUID$("{BA818CE5-B55F-443F-AD39-2FE89BE6191F}")
$CLSID_PropertyStore = GUID$("{E4796550-DF61-448B-9193-13FC1341B163}")
$CLSID_PropertyStoreCollection = GUID$("{EDD36029-D753-4862-AA5B-5BCCAD2A4D29}")
