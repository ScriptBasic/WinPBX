' ########################################################################################
' Microsoft Windows
' File: dshowasf.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSHOWASF_INC = 1

#IF NOT %DEF(%EC_PREPROCESS_COMPLETE)
%EC_PREPROCESS_COMPLETE = &H56
#ENDIF

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "wmsdkidl.inc"

$IID_IConfigAsfWriter = GUID$("{45086030-F7E4-486A-B504-826BB5792A3B}")
$IID_IConfigAsfWriter2 = GUID$("{7989CCAA-53F0-44f0-884A-F3B03F6AE066}")
$IID_IAMWMBufferPass = GUID$("{6DD816D7-E740-4123-9E24-2444412644D8}")
$IID_IAMWMBufferPassCallback = GUID$("{B25B8372-D2D2-44b2-8653-1B8DAE332489}")


' ########################################################################################
' Interface name = IAMWMBufferPass
' IID = 6DD816D7-E740-4123-9E24-2444412644D8
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAMWMBufferPass $IID_IAMWMBufferPass

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetNotify ( _                                 ' VTable offset = 12
     BYVAL pCallback AS IUnknown _                      ' __in IAMWMBufferPassCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IAMWMBufferPassCallback
' IID = B25B8372-D2D2-44b2-8653-1B8DAE332489
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAMWMBufferPassCallback $IID_IAMWMBufferPassCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
     BYVAL pNSSBuffer3 AS INSSBuffer3 _                 ' __in INSSBuffer3 *pNSSBuffer3
   , BYVAL pPin AS IPin _                               ' __in IPin *pPin
   , BYREF prtStart AS QUAD _                           ' __in REFERENCE_TIME *prtStart
   , BYREF prtEnd AS QUAD _                             ' __in REFERENCE_TIME *prtEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' enum AM_ASFWRITERCONFIG_PARAM
%AM_CONFIGASFWRITER_PARAM_AUTOINDEX    = 1
%AM_CONFIGASFWRITER_PARAM_MULTIPASS    = %AM_CONFIGASFWRITER_PARAM_AUTOINDEX + 1
%AM_CONFIGASFWRITER_PARAM_DONTCOMPRESS = %AM_CONFIGASFWRITER_PARAM_MULTIPASS + 1


' ########################################################################################
' Interface name = IConfigAsfWriter
' IID = 45086030-F7E4-486A-B504-826BB5792A3B
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IConfigAsfWriter $IID_IConfigAsfWriter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConfigureFilterUsingProfileId ( _             ' VTable offset = 12
     BYVAL dwProfileId AS DWORD _                       ' __in DWORD dwProfileId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProfileId ( _                       ' VTable offset = 16
     BYREF pdwProfileId AS DWORD _                      ' __out DWORD *pdwProfileId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureFilterUsingProfileGuid ( _           ' VTable offset = 20
     BYREF guidProfile AS GUID _                        ' __in REFGUID guidProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProfileGuid ( _                     ' VTable offset = 24
     BYREF pProfileGuid AS GUID _                       ' __out GUID *pProfileGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureFilterUsingProfile ( _               ' VTable offset = 28
     BYVAL pProfile AS IWMProfile _                     ' __in IWMProfile *pProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProfile ( _                         ' VTable offset = 32
     BYREF ppProfile AS IWMProfile _                    ' __out IWMProfile **ppProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndexMode ( _                              ' VTable offset = 36
     BYVAL bIndexFile AS LONG _                         ' __in BOOL bIndexFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexMode ( _                              ' VTable offset = 40
     BYREF pbIndexFile AS LONG _                        ' __out BOOL *pbIndexFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IConfigAsfWriter2
' IID = 7989CCAA-53F0-44F0-884A-F3B03F6AE066
' Inherited interface = IConfigAsfWriter
' ########################################################################################

INTERFACE IConfigAsfWriter2 $IID_IConfigAsfWriter2

   INHERIT IUnknown

   ' =====================================================================================
   ' IConfigAsfWriter methods
   ' =====================================================================================
   METHOD ConfigureFilterUsingProfileId ( _             ' VTable offset = 12
     BYVAL dwProfileId AS DWORD _                       ' __in DWORD dwProfileId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProfileId ( _                       ' VTable offset = 16
     BYREF pdwProfileId AS DWORD _                      ' __out DWORD *pdwProfileId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureFilterUsingProfileGuid ( _           ' VTable offset = 20
     BYREF guidProfile AS GUID _                        ' __in REFGUID guidProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProfileGuid ( _                     ' VTable offset = 24
     BYREF pProfileGuid AS GUID _                       ' __out GUID *pProfileGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureFilterUsingProfile ( _               ' VTable offset = 28
     BYVAL pProfile AS IWMProfile _                     ' __in IWMProfile *pProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProfile ( _                         ' VTable offset = 32
     BYREF ppProfile AS IWMProfile _                    ' __out IWMProfile **ppProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndexMode ( _                              ' VTable offset = 36
     BYVAL bIndexFile AS LONG _                         ' __in BOOL bIndexFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexMode ( _                              ' VTable offset = 40
     BYREF pbIndexFile AS LONG _                        ' __out BOOL *pbIndexFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConfigAsfWriter2 methods
   ' =====================================================================================
   METHOD StreamNumFromPin ( _                          ' VTable offset = 44
     BYVAL pPin AS IPin _                               ' __in IPin *pPin
   , BYREF pwStreamNum AS WSTRINGZ _                    ' __out WORD *pwStreamNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParam ( _                                  ' VTable offset = 48
     BYVAL dwParam AS DWORD _                           ' __in DWORD dwParam
   , BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam1
   , BYVAL dwParam2 AS DWORD _                          ' __in DWORD dwParam2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParam ( _                                  ' VTable offset = 52
     BYVAL dwParam AS DWORD _                           ' __in DWORD dwParam
   , BYREF pdwParam1 AS DWORD _                         ' __out DWORD *pdwParam1
   , BYREF pdwParam2 AS DWORD _                         ' __out DWORD *pdwParam2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetMultiPassState ( _                       ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'////////////////////////////////////////////////////////////////
'//
'// Windows Media Filters compatibility option flags
'//
%EXCLUDE_SCRIPT_STREAM_DELIVERY_SYNCHRONIZATION = &H00000001???

'////////////////////////////////////////////////////////////////
'//
'// ATOM strings to match compatibility option flags above for certain applications that don't want to (or not allowed to) update registry entries
'// These need to be setup by the application using the WM filters to enable the particular functionality
'//
'static const WCHAR* g_wszExcludeScriptStreamDeliverySynchronization = L"ExcludeScriptStreamDeliverySynchronization";
$$g_wszExcludeScriptStreamDeliverySynchronization = "ExcludeScriptStreamDeliverySynchronization"$$
