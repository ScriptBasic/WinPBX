' ########################################################################################
' Microsoft Windows
' File: downloadmgr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DOWNLOADMGR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "ocidl.inc"

'//---------------------------------------------------------------------------=
'// Internet Explorer Download Manager Interfaces

'// --------------------------------------------------------------------------------
'// GUIDS
'// --------------------------------------------------------------------------------
$IID_IDownloadManager = GUID$("{988934A4-064B-11D3-BB80-00104B35E7F9}")
$SID_SDownloadManager = $IID_IDownloadManager

' ########################################################################################
' IDownloadManager interface
' IID = 988934A4-064B-11D3-BB80-00104B35E7F9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDownloadManager_INTERFACE_DEFINED)
    %IDownloadManager_INTERFACE_DEFINED = 1

INTERFACE IDownloadManager $IID_IDownloadManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 12
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYVAL dwBindVerb AS DWORD _                        ' __in DWORD dwBindVerb
   , BYVAL grfBINDF AS LONG _                           ' __in LONG grfBINDF
   , BYREF pBindInfo AS BINDINFO _                      ' __in BINDINFO *pBindInfo
   , BYREF pszHeaders AS WSTRINGZ _                     ' __in LPCOLESTR pszHeaders
   , BYREF pszRedir AS WSTRINGZ _                       ' __in LPCOLESTR pszRedir
   , BYVAL uiCP AS DWORD _                              ' __in UINT uiCP
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDownloadManager_INTERFACE_DEFINED__ */
