' ########################################################################################
' Microsoft Windows
' File: wmdmlog.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WMDMLOG_INC = 1

'EXTERN_C const IID LIBID_WMDMLogLib;

$CLSID_WMDMLogger = GUID$("{110A3202-5A79-11d3-8D78-444553540000}")

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

%WMDM_LOG_SEV_INFO    = &H00000001???
%WMDM_LOG_SEV_WARN    = &H00000002???
%WMDM_LOG_SEV_ERROR   = &H00000004???
%WMDM_LOG_NOTIMESTAMP = &H00000010???

' ########################################################################################
' IWMDMLogger interface
' IID = 110A3200-5A79-11d3-8D78-444553540000
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDMLogger_INTERFACE_DEFINED)
    %IWMDMLogger_INTERFACE_DEFINED = 1

$IID_IWMDMLogger = GUID$("{110A3200-5A79-11d3-8D78-444553540000}")

INTERFACE IWMDMLogger $IID_IWMDMLogger

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsEnabled ( _                                 ' VTable offset = 12
     BYREF pfEnabled AS LONG _                          ' __out BOOL *pfEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 16
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogFileName ( _                            ' VTable offset = 20
     BYREF pszFilename AS ASCIIZ _                      ' __out_ecount_full_string(( 256 + 1 ) ) LPSTR pszFilename
   , BYVAL nMaxChars AS DWORD _                         ' __in_range(0,256) UINT nMaxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLogFileName ( _                            ' VTable offset = 24
     BYREF pszFilename AS ASCIIZ _                      ' __in LPSTR pszFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogString ( _                                 ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszSrcName AS ASCIIZ _                       ' __in LPSTR pszSrcName
   , BYREF pszLog AS ASCIIZ _                           ' __in LPSTR pszLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogDword ( _                                  ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszSrcName AS ASCIIZ _                       ' __in LPSTR pszSrcName
   , BYREF pszLogFormat AS ASCIIZ _                     ' __in pszLogFormat
   , BYVAL dwLog AS DWORD _                             ' __in DWORD dwLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeParams ( _                             ' VTable offset = 40
     BYREF pdwMaxSize AS DWORD _                        ' __out LPDWORD pdwMaxSize
   , BYREF pdwShrinkToSize AS DWORD _                   ' __out LPDWORD pdwShrinkToSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSizeParams ( _                             ' VTable offset = 44
     BYVAL dwMaxSize AS DWORD _                         ' __in DWORD dwMaxSize
   , BYVAL dwShrinkToSize AS DWORD _                    ' __in DWORD dwShrinkToSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDMLogger_INTERFACE_DEFINED__ */
