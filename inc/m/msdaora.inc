' ########################################################################################
' Microsoft Windows
' File: msdaora.inc
' Contents: Internal GUIDS
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSDAORA_INC = 1

'#ifndef __MSDAORAGUIDS_DEFINED__
'#define __MSDAORAGUIDS_DEFINED__

'#undef MSDAORADECLSPEC
'#if _MSC_VER >= 1100 && (!defined(SHx) || (defined(SHx) && _MSC_VER >= 1200))
'#define MSDAORADECLSPEC __declspec(selectany)
'#else
'#define MSDAORADECLSPEC
'#endif //_MSC_VER

$CLSID_MSDAORA = GUID$("{E8CC4CBE-FDFF-11D0-B865-00A0C9081C1D}")
$CLSID_MSDAORA_ERROR = GUID$("{E8CC4CBF-FDFF-11D0-B865-00A0C9081C1D}")
$CLSID_MSDAORA8 = GUID$("{7F06A373-DD6A-43DB-B4E0-1FC121E5E62B}")
$CLSID_MSDAORA8_ERROR = GUID$("{7F06A374-DD6A-43DB-B4E0-1FC121E5E62B}")

'//----------------------------------------------------------------------------
'// MSDAORA specific properties
'//

$DBPROPSET_MSDAORA_ROWSET = GUID$("{E8CC4CBD-FDFF-11D0-B865-00A0C9081C1D}")
$DBPROPSET_MSDAORA8_ROWSET = GUID$("{7F06A375-DD6A-43DB-B4E0-1FC121E5E62B}")

'// PropIds under DBPROPSET_MSDAORA_ROWSET
%DBPROP_MSDAORA_DETERMINEKEYCOLUMNS  = 1
%DBPROP_MSDAORA8_DETERMINEKEYCOLUMNS = 2

'#endif // __MSDAORAGUIDS_DEFINED__
