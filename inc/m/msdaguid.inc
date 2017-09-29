' ########################################################################################
' Microsoft Windows
' File: msdaguid.inc
' Contents: Microsoft Data Access GUID defintions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSDAGUID_INC = 1

'#ifdef DBINITCONSTANTS
$CLSID_OLEDB_ENUMERATOR                = GUID$("{C8B522D0-5CF3-11CE-ADE5-00AA0044773D}")
$CLSID_EXTENDEDERRORINFO               = GUID$("{C8B522CF-5CF3-11CE-ADE5-00AA0044773D}")
$CLSID_MSDAVTM                         = GUID$("{0C733A8E-2A1C-11CE-ADE5-00AA0044773D}")
$CLSID_OLEDB_CONVERSIONLIBRARY         = GUID$("{C8B522D1-5CF3-11CE-ADE5-00AA0044773D}")
$CLSID_OLEDB_ROWPOSITIONLIBRARY        = GUID$("{2048EEE6-7FA2-11D0-9E6A-00A0C9138C29}")
$CLSID_OLEDB_SVC_DSLPropertyPages      = GUID$("{51740C02-7E8E-11D2-A02D-00C04FA37348}")
'#endif
