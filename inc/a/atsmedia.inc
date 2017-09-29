' ########################################################################################
' Microsoft Windows
' File: ATSMedia.inc
' Contents: Broadcast Driver Architecture Media Definitions for ATSC
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ATSMEDIA_INC = 1

'#if !defined(_KSMEDIA_)
'#error KSMEDIA.H must be included before BDAMEDIA.H
'#endif // !defined(_KSMEDIA_)

'#if !defined(_BDAMEDIA_)
'#error BDAMEDIA.H must be included before ATSCMEDIA.H
'#endif // !defined(_KSMEDIA_)

'#if !defined(_ATSCMEDIA_)
'#define _ATSCMEDIA_


'//===========================================================================
'//
'//  ATSC Network Type
'//
'//===========================================================================

'#define STATIC_BDANETWORKTYPE_ATSC\
'    0x71985f51, 0x1ca1, 0x11d3, 0x9c, 0xc8, 0x0, 0xc0, 0x4f, 0x79, 0x71, 0xe0
'DEFINE_GUIDSTRUCT("71985F51-1CA1-11d3-9CC8-00C04F7971E0", BDANETWORKTYPE_ATSC);
'#define BDANETWORKTYPE_ATSC DEFINE_GUIDNAMED(BDANETWORKTYPE_ATSC)


'#endif // _ATSCMEDIA_

$BDANETWORKTYPE_ATSC = GUID$("{71985F51-1CA1-11d3-9CC8-00C04F7971E0}")
