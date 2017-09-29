' ########################################################################################
' Microsoft Windows
' File: tlbref.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TLBREF_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$IID_ITypeLibResolver = GUID$("{8F026EDB-785E-4470-A8E1-B4E84E9D1779}")

' ########################################################################################
' Interface name = ITypeLibResolver
' IID = 8F026EDB-785E-4470-A8E1-B4E84E9D1779
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeLibResolver_INTERFACE_DEFINED)
    %ITypeLibResolver_INTERFACE_DEFINED = 1

INTERFACE ITypeLibResolver $IID_ITypeLibResolver

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResolveTypeLib ( _                            ' VTable offset = 12
     BYVAL bstrSimpleName AS WSTRING _                  ' __in BSTR bstrSimpleName
   , BYVAL tlbid AS GUID _                              ' __in GUID tlbid
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL wMajorVersion AS WORD _                      ' __in USHORT wMajorVersion
   , BYVAL wMinorVersion AS WORD _                      ' __in USHORT wMinorVersion
   , BYVAL syskind AS LONG _                            ' __in SYSKIND syskind
   , BYREF pbstrResolvedTlbName AS WSTRING _            ' __out BSTR *pbstrResolvedTlbName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeLibResolver_INTERFACE_DEFINED__ */

DECLARE FUNCTION LoadTypeLibWithResolver IMPORT "tlbref.dll" ALIAS "LoadTypeLibWithResolver" ( _
   BYREF szFile AS WSTRINGZ _                           ' __in LPCOLESTR szFile
 , BYVAL regkind AS LONG _                              ' __in REGKIND regkind
 , BYVAL pTlbResolver AS ITypeLibResolver _             ' __in ITypeLibResolver *pTlbResolver
 , BYREF pptlib AS ITypeLib _                           ' __out ITypeLib **pptlib
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetTypeLibInfo IMPORT "tlbref.dll" ALIAS "GetTypeLibInfo" ( _
   BYREF szFile AS WSTRINGZ _                           ' __in LPWSTR szFile
 , BYREF pTypeLibID AS GUID _                           ' __out GUID *pTypeLibID
 , BYREF pTypeLibLCID AS DWORD _                        ' __out LCID *pTypeLibLCID
 , BYREF pTypeLibPlatform AS LONG _                     ' __out SYSKIND *pTypeLibPlatform
 , BYREF pTypeLibMajorVer AS WORD _                     ' __out USHORT *pTypeLibMajorVer
 , BYREF pTypeLibMinorVer AS WORD _                     ' __out USHORT *pTypeLibMinorVer
 ) AS LONG                                              ' HRESULT
