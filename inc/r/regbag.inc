' ########################################################################################
' Microsoft Windows
' File: regbag.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%REGBAG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ########################################################################################
' Interface name = ICreatePropBagOnRegKey
' IID = 8A674B48-1F63-11D3-B64C-00C04F79498E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreatePropBagOnRegKey_INTERFACE_DEFINED)
    %ICreatePropBagOnRegKey_INTERFACE_DEFINED = 1

$IID_ICreatePropBagOnRegKey = GUID$("{8A674B48-1F63-11D3-B64C-00C04F79498E}")

INTERFACE ICreatePropBagOnRegKey $IID_ICreatePropBagOnRegKey

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL hkey AS DWORD _                              ' __in  HKEY hkey
   , BYREF subkey AS WSTRINGZ _                         ' __in  LPCOLESTR subkey
   , BYVAL ulOptions AS DWORD _                         ' __in  DWORD ulOptions
   , BYVAL samDesired AS DWORD _                        ' __in  DWORD samDesired
   , BYREF iid AS GUID _                                ' __in  REFIID iid
   , BYREF ppBag AS IUnknown _                          ' __out LPVOID *ppBag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' #IF NOT %DEF(%ICreatePropBagOnRegKey_INTERFACE_DEFINED)
