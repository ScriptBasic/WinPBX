' ########################################################################################
' Microsoft Windows
' File: corpub.inc
' Library name: CorpubProcessLib
' Version: 1.0, Locale ID = 0
' Library GUID: {E97CA460-657D-11D3-8D5B-00104B35E7EF}
' Contents: Common Language Runtime Process Publishing Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CORPUB_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

$LIBID_CorpubProcessLib = GUID$("{E97CA460-657D-11D3-8D5B-00104B35E7EF}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {047A9A40-657E-11D3-8D5B-00104B35E7EF}
$PROGID_CorpubPublish1 = "ComPlusDebug.CorpubPublish.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {047A9A40-657E-11D3-8D5B-00104B35E7EF}
$PROGID_CorpubPublish = "ComPlusDebug.CorpubPublish"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CorpubPublish = GUID$("{047A9A40-657E-11D3-8D5B-00104B35E7EF}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICorPublish = GUID$("{9613A0E7-5A68-11D3-8F84-00A0C9B4D50C}")
$IID_ICorPublishAppDomain = GUID$("{D6315C8F-5A6A-11D3-8F84-00A0C9B4D50C}")
$IID_ICorPublishAppDomainEnum = GUID$("{9F0C98F5-5A6A-11D3-8F84-00A0C9B4D50C}")
$IID_ICorPublishEnum = GUID$("{C0B22967-5A69-11D3-8F84-00A0C9B4D50C}")
$IID_ICorPublishProcess = GUID$("{18D87AF1-5A6A-11D3-8F84-00A0C9B4D50C}")
$IID_ICorPublishProcessEnum = GUID$("{A37FBD41-5A69-11D3-8F84-00A0C9B4D50C}")

' ========================================================================================
' COR_PUB_ENUMPROCESS enum <alias> __MIDL___MIDL_itf_corpub_0000_0000_0001
' ========================================================================================

%COR_PUB_MANAGEDONLY = &H1

' ########################################################################################
' Interface name = ICorPublish
' IID = {9613A0E7-5A68-11D3-8F84-00A0C9B4D50C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorPublish_INTERFACE_DEFINED)
    %ICorPublish_INTERFACE_DEFINED = 1

INTERFACE ICorPublish $IID_ICorPublish

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumProcesses ( _                             ' VTable offset = 12
     BYVAL Type AS LONG _                               ' __in COR_PUB_ENUMPROCESS Type
   , BYREF ppIEnum AS ICorPublishProcessEnum _          ' __out ICorPublishProcessEnum **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcess ( _                                ' VTable offset = 16
     BYVAL pid AS DWORD _                               ' __in unsigned int pid
   , BYREF ppProcess AS ICorPublishProcess _            ' __out ICorPublishProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorPublish_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorPublishEnum
' IID = {C0B22967-5A69-11D3-8F84-00A0C9B4D50C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorPublishEnum_INTERFACE_DEFINED)
    %ICorPublishEnum_INTERFACE_DEFINED = 1

INTERFACE ICorPublishEnum $IID_ICorPublishEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorPublishEnum _                  ' __out ICorPublishEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorPublishEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorPublishProcess
' IID = {18D87AF1-5A6A-11D3-8F84-00A0C9B4D50C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorPublishProcess_INTERFACE_DEFINED)
    %ICorPublishProcess_INTERFACE_DEFINED = 1

INTERFACE ICorPublishProcess $IID_ICorPublishProcess

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsManaged ( _                                 ' VTable offset = 12
     BYREF pbManaged AS LONG _                          ' __out BOOL *pbManaged
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAppDomains ( _                            ' VTable offset = 16
     BYREF ppEnum AS ICorPublishAppDomainEnum _         ' __out ICorPublishAppDomainEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcessID ( _                              ' VTable offset = 20
     BYREF pid AS DWORD _                               ' __out unsigned int *pid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR *szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorPublishProcess_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorPublishAppDomain
' IID = {D6315C8F-5A6A-11D3-8F84-00A0C9B4D50C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorPublishAppDomain_INTERFACE_DEFINED)
    %ICorPublishAppDomain_INTERFACE_DEFINED = 1

INTERFACE ICorPublishAppDomain $IID_ICorPublishAppDomain

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 12
     BYREF puId AS DWORD _                              ' __out ULONG32 *puId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR *szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorPublishAppDomain_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorPublishProcessEnum
' IID = {A37FBD41-5A69-11D3-8F84-00A0C9B4D50C}
' Inherited interface = ICorPublishEnum
' ########################################################################################

#IF NOT %DEF(%ICorPublishProcessEnum_INTERFACE_DEFINED)
    %ICorPublishProcessEnum_INTERFACE_DEFINED = 1

INTERFACE ICorPublishProcessEnum $IID_ICorPublishProcessEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorPublishEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorPublishEnum _                  ' __out ICorPublishEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorPublishProcessEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in LONG celt
   , BYREF objects AS ICorPublishProcess _              ' __out ICorPublishProcess **objects
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorPublishProcessEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorPublishAppDomainEnum
' IID = {9F0C98F5-5A6A-11D3-8F84-00A0C9B4D50C}
' Inherited interface = ICorPublishEnum
' ########################################################################################

#IF NOT %DEF(%ICorPublishAppDomainEnum_INTERFACE_DEFINED)
    %ICorPublishAppDomainEnum_INTERFACE_DEFINED = 1

INTERFACE ICorPublishAppDomainEnum $IID_ICorPublishAppDomainEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorPublishEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorPublishEnum _                  ' __out ICorPublishEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorPublishAppDomainEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF objects AS ICorPublishAppDomain _            ' __out ICorPublishAppDomain **objects
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorPublishAppDomainEnum_INTERFACE_DEFINED__ */
