' ########################################################################################
' Microsoft Windows
' File: adodef.inc
' Contents: ADO version definition.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADODEF_INC = 1

'// TYPELIB MAJOR VERSIONS
%ADO_MAJOR          = 6
%ADOR_MAJOR         = 2
%ADOX_MAJOR         = 6
%ADOMD_MAJOR        = 6
%JRO_MAJOR          = 2

'// TYPELIB MINOR VERSION
%ADO_MINOR          = 0
%ADOR_MINOR         = 8
%ADOX_MINOR         = 0
%ADOMD_MINOR        = 0
%JRO_MINOR          = 6

$ADO_VERSION        = "6.0"
$ADOR_VERSION       = "2.8"
$ADOX_VERSION       = "6.0"
$ADOMD_VERSION      = "6.0"
$JRO_VERSION        = "2.6"

$ADO_HELPFILE       = "ado270.chm"
$ADOX_HELPFILE      = "ado270.chm"
$ADOMD_HELPFILE     = "ado270.chm"
$JRO_HELPFILE       = "msjro.chm"

$ADO_LIBRARYNAME    = "Microsoft ActiveX Data Objects 6.0 Library"
$ADOR_LIBRARYNAME   = "Microsoft ActiveX Data Objects Recordset 2.8 Library"
$ADOX_LIBRARYNAME   = "Microsoft ADO Ext. 6.0 for DDL and Security"
$ADOMD_LIBRARYNAME  = "Microsoft ActiveX Data Objects (Multi-dimensional) 6.0 Library"
$JRO_LIBRARYNAME    = "Microsoft Jet and Replication Objects 2.6 Library"

$ADOMD_TYPELIB_UUID = GUID$("{22813728-8BD3-11D0-B4EF-00A0C9138CA4}")
$JRO_TYPELIB_UUID   = GUID$("{AC3B8B4C-B6CA-11d1-9F31-00C04FC29D52}")
