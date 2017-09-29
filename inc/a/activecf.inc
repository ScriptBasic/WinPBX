' ########################################################################################
' Microsoft Windows
' File: ActiveCf.inc
' Contents: Contains the data formats for the transfer of VfW4 filters via the clipboard.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACTIVECF_INC = 1

$CFSTR_VFW_FILTERLIST = "Video for Windows 4 Filters"

' // Size = 20 bytes
TYPE VFW_FILTERLIST DWORD
   cFilters AS DWORD   ' UINT  // number of CLSIDs in aClsId
   aClsId(0) AS GUID   ' CLSID // ClsId of each filter
END TYPE
