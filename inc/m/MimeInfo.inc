' ########################################################################################
' Microsoft Windows
' File: MimeInfo.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MIMEINFO_INC = 1

#INCLUDE ONCE "ole2.inc"

#IF NOT %DEF(%IMimeInfo_INTERFACE_DEFINED)
    %IMimeInfo_INTERFACE_DEFINED = 1

' ########################################################################################
' Interface name = IMimeInfo
' IID = F77459A0-BF9A-11cf-BA4E-00C04FD70816
' Inherited interface = IUnknown
' ########################################################################################

$IID_IMimeInfo = GUID$("{F77459A0-BF9A-11cf-BA4E-00C04FD70816}")
$SID_IMimeInfo = GUID$("{F77459A0-BF9A-11cf-BA4E-00C04FD70816}")

INTERFACE IMimeInfo $IID_IMimeInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMimeCLSIDMapping ( _                       ' VTable offset = 12
     BYREF pcTypes AS DWORD _                           ' __out UINT *pcTypes
   , BYREF ppszTypes AS ASCIIZ _                        ' __out LPCSTR **ppszTypes
   , BYREF ppclsID AS GUID _                            ' __out CLSID **ppclsID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeInfo_INTERFACE_DEFINED__ */
