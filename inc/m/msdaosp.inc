' ########################################################################################
' Microsoft Windows
' File: msdaosp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSDAOSPT
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft OLE DB Simple Provider Toolkit Definitions
' Library GUID: {0AE9A4E0-18D4-11D1-B3B3-00AA00C1A924}
' ########################################################################################

#INCLUDE THIS ONCE
%MSDAOSP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "msdatsrc.inc"
#INCLUDE ONCE "simpdata.inc"

$CLSID_MSDAOSP = GUID$("{dfc8bdc0-e378-11d0-9b30-0080c7e9fe95}")
$DBPROPSET_PWROWSET = GUID$("{e6e478db-f226-11d0-94ee-00c04fb66a50}")

%PWPROP_OSPVALUE = 2

#IF NOT %DEF(%DataSourceObject_DISPINTERFACE_DEFINED)
    %DataSourceObject_DISPINTERFACE_DEFINED = 1

$DIID_DataSourceObject = GUID$("{0ae9a4e4-18d4-11d1-b3b3-00aa00c1a924}")

INTERFACE DataSourceObject $DIID_DataSourceObject

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __DataSourceObject_DISPINTERFACE_DEFINED__ */
