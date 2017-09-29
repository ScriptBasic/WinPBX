' ########################################################################################
' Microsoft Windows
' File: EmptyVC.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EMPTYVC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#include ONCE "oleidl.inc"
#include ONCE "oaidl.inc"

'//---------------------------------------------------------------------------=
'// Empty Volume Cache Interfaces.


'// IEmptyVolumeCache Flags
%EVCF_HASSETTINGS             = &H0001???
%EVCF_ENABLEBYDEFAULT         = &H0002???
%EVCF_REMOVEFROMLIST          = &H0004???
%EVCF_ENABLEBYDEFAULT_AUTO    = &H0008???
%EVCF_DONTSHOWIFZERO          = &H0010???
%EVCF_SETTINGSMODE            = &H0020???
%EVCF_OUTOFDISKSPACE          = &H0040???

'// IEmptyVolumeCacheCallBack Flags
%EVCCBF_LASTNOTIFICATION      = &H0001???

'////////////////////////////////////////////////////////////////////////////
'//  Interface Definitions

' ########################################################################################
' IEmptyVolumeCacheCallBack interface
' IID = 6E793361-73C6-11D0-8469-00AA00442901
' Inherited interface = IUnknown
' Minimum operating system: Windows 2000, Millennium, Windows 98
' ########################################################################################

#IF NOT %DEF(%IEmptyVolumeCacheCallBack_INTERFACE_DEFINED)
   %IEmptyVolumeCacheCallBack_INTERFACE_DEFINED = 1

$IID_IEmptyVolumeCacheCallBack = GUID$("{6E793361-73C6-11D0-8469-00AA00442901}")

INTERFACE IEmptyVolumeCacheCallBack $IID_IEmptyVolumeCacheCallBack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ScanProgress ( _                              ' VTable offset = 12
     BYVAL dwlSpaceUsed AS QUAD _                       ' __in DWORDLONG dwlSpaceUsed
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pcwszStatus AS WSTRINGZ _                    ' __in LPCWSTR pcwszStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PurgeProgress ( _                             ' VTable offset = 16
     BYVAL dwlSpaceFreed AS QUAD _                      ' __in DWORDLONG dwlSpaceFreed
   , BYVAL dwlSpaceToFree AS QUAD _                     ' __in DWORDLONG dwlSpaceToFree
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pcwszStatus AS WSTRINGZ _                    ' __in LPCWSTR pcwszStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEmptyVolumeCacheCallBack_INTERFACE_DEFINED__ */


' ########################################################################################
' IEmptyVolumeCache interface
' IID = 8FCE5227-04DA-11D1-A004-00805F8ABE06
' Inherited interface = IUnknown
' Minimum operating system: Windows 2000, Millennium, Windows 98
' ########################################################################################

#IF NOT %DEF(%IEmptyVolumeCache_INTERFACE_DEFINED)
   %IEmptyVolumeCache_INTERFACE_DEFINED = 1

$IID_IEmptyVolumeCache = GUID$("{8FCE5227-04DA-11D1-A004-00805F8ABE06}")

INTERFACE IEmptyVolumeCache $IID_IEmptyVolumeCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hkRegKey AS DWORD _                          ' __in HKEY hkRegKey
   , BYREF pcwszVolume AS WSTRINGZ _                    ' __in LPCWSTR pcwszVolume
   , BYREF ppwszDisplayName AS DWORD _                  ' __out LPWSTR *ppwszDisplayName
   , BYREF ppwszDescription AS DWORD _                  ' __out LPWSTR *ppwszDescription
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpaceUsed ( _                              ' VTable offset = 16
     BYREF pdwlSpaceUsed AS QUAD _                      ' __out DWORDLONG *pdwlSpaceUsed
   , BYVAL picb AS IEmptyVolumeCacheCallBack _          ' __in IEmptyVolumeCacheCallBack *picb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Purge ( _                                     ' VTable offset = 20
     BYVAL dwlSpaceToFree AS QUAD _                     ' __in DWORDLONG dwlSpaceToFree
   , BYVAL picb AS IEmptyVolumeCacheCallBack _          ' __in IEmptyVolumeCacheCallBack *picb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowProperties ( _                            ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 28
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEmptyVolumeCache_INTERFACE_DEFINED__ */


' ########################################################################################
' IEmptyVolumeCache2 interface
' IID = 8FCE5227-04DA-11D1-A004-00805F8ABE06
' Inherited interface = IEmptyVolumeCache
' Minimum operating system: Windows 2000, Millennium, Windows 98
' ########################################################################################

#IF NOT %DEF(%IEmptyVolumeCache2_INTERFACE_DEFINED)
   %IEmptyVolumeCache2_INTERFACE_DEFINED = 1

$IID_IEmptyVolumeCache2 = GUID$("{02B7E3BA-4DB3-11D2-B2D9-00C04F8EEC8C}")

INTERFACE IEmptyVolumeCache2 $IID_IEmptyVolumeCache2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hkRegKey AS DWORD _                          ' __in HKEY hkRegKey
   , BYREF pcwszVolume AS WSTRINGZ _                    ' __in LPCWSTR pcwszVolume
   , BYREF ppwszDisplayName AS DWORD _                  ' __out LPWSTR *ppwszDisplayName
   , BYREF ppwszDescription AS DWORD _                  ' __out LPWSTR *ppwszDescription
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpaceUsed ( _                              ' VTable offset = 16
     BYREF pdwlSpaceUsed AS QUAD _                      ' __out DWORDLONG *pdwlSpaceUsed
   , BYVAL picb AS IEmptyVolumeCacheCallBack _          ' __in IEmptyVolumeCacheCallBack *picb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Purge ( _                                     ' VTable offset = 20
     BYVAL dwlSpaceToFree AS QUAD _                     ' __in DWORDLONG dwlSpaceToFree
   , BYVAL picb AS IEmptyVolumeCacheCallBack _          ' __in IEmptyVolumeCacheCallBack *picb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowProperties ( _                            ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 28
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeEx ( _                              ' VTable offset = 32
     BYVAL hkRegKey AS DWORD _                          ' __in HKEY hkRegKey
   , BYREF pcwszVolume AS WSTRINGZ _                    ' __in LPCWSTR pcwszVolume
   , BYREF pcwszKeyName AS WSTRINGZ _                   ' __in LPCWSTR pcwszKeyName
   , BYREF ppwszDisplayName AS DWORD _                  ' __out LPWSTR *ppwszDisplayName
   , BYREF ppwszDescription AS DWORD _                  ' __out LPWSTR *ppwszDescription
   , BYREF ppwszBtnText AS DWORD _                      ' __out LPWSTR *ppwszBtnText
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEmptyVolumeCache2_INTERFACE_DEFINED__ */
