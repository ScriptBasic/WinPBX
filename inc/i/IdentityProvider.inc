' ########################################################################################
' Microsoft Windows
' File: IdentityProvider.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IDENTITYPROVIDER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "IdentityCommon.inc"

' enum tag_IdentityUpdateEvent
%IDENTITY_ASSOCIATED    = &H1
%IDENTITY_DISASSOCIATED = &H2
%IDENTITY_CREATED       = &H4
%IDENTITY_IMPORTED      = &H8
%IDENTITY_DELETED       = &H10
%IDENTITY_PROPCHANGED   = &H20

$$IDENTITY_KEYWORD_ASSOCIATED = "associated"$$
$$IDENTITY_KEYWORD_LOCAL      = "local"$$
$$IDENTITY_KEYWORD_HOMEGROUP  = "homegroup"$$

$OID_OAssociatedIdentityProviderObject = GUID$("{98c5a3dd-db68-4f1a-8d2b-9079cdfeaf61}")

' ########################################################################################
' IIdentityAdvise interface
' IID = 4e982fed-d14b-440c-b8d6-bb386453d386
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIdentityAdvise_INTERFACE_DEFINED)
    %IIdentityAdvise_INTERFACE_DEFINED = 1

$IID_IIdentityAdvise = GUID$("{4e982fed-d14b-440c-b8d6-bb386453d386}")

INTERFACE IIdentityAdvise $IID_IIdentityAdvise

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IdentityUpdated ( _                           ' VTable offset = 12
     BYVAL dwIdentityUpdateEvents AS DWORD _            ' __in DWORD dwIdentityUpdateEvents
   , BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdentityAdvise_INTERFACE_DEFINED__ */

' ########################################################################################
' AsyncIIdentityAdvise interface
' IID = 3ab4c8da-d038-4830-8dd9-3253c55a127f
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIIdentityAdvise_INTERFACE_DEFINED)
    %AsyncIIdentityAdvise_INTERFACE_DEFINED = 1

$IID_AsyncIIdentityAdvise = GUID$("{3ab4c8da-d038-4830-8dd9-3253c55a127f}")

INTERFACE AsyncIIdentityAdvise $IID_AsyncIIdentityAdvise

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_IdentityUpdated ( _                     ' VTable offset = 12
     BYVAL dwIdentityUpdateEvents AS DWORD _            ' __in DWORD dwIdentityUpdateEvents
   , BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_IdentityUpdated ( _                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIIdentityAdvise_INTERFACE_DEFINED__ */

' ########################################################################################
' IIdentityProvider interface
' IID = 0d1b9e0c-e8ba-4f55-a81b-bce934b948f5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIdentityProvider_INTERFACE_DEFINED)
    %IIdentityProvider_INTERFACE_DEFINED = 1

$IID_IIdentityProvider = GUID$("{0d1b9e0c-e8ba-4f55-a81b-bce934b948f5}")

INTERFACE IIdentityProvider $IID_IIdentityProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIdentityEnum ( _                           ' VTable offset = 12
     BYVAL eIdentityType AS LONG _                      ' __in const IDENTITY_TYPE eIdentityType
   , BYREF pFilterkey AS PROPERTYKEY _                  ' __in const PROPERTYKEY *pFilterkey
   , BYREF pFilterPropVarValue AS PROPVARIANT _         ' __in const PROPVARIANT *pFilterPropVarValue
   , BYREF ppIdentityEnum AS IEnumUnknown _             ' __out IEnumUnknown **ppIdentityEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 16
     BYREF lpszUserName AS WSTRINGZ _                   ' __in LPCWSTR lpszUserName
   , BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   , BYREF pKeywordsToAdd AS PROPVARIANT _              ' __in const PROPVARIANT *pKeywordsToAdd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Import ( _                                    ' VTable offset = 20
     BYVAL pPropertyStore AS IPropertyStore _           ' __in IPropertyStore *pPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 24
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF pKeywordsToDelete AS PROPVARIANT _           ' __in const PROPVARIANT *pKeywordsToDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindByUniqueID ( _                            ' VTable offset = 28
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProviderPropertyStore ( _                  ' VTable offset = 32
     BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 36
     BYVAL pIdentityAdvise AS IIdentityAdvise _         ' __in IIdentityAdvise *pIdentityAdvise
   , BYVAL dwIdentityUpdateEvents AS DWORD _            ' __in DWORD dwIdentityUpdateEvents
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnAdvise ( _                                  ' VTable offset = 40
     BYVAL dwCookie AS DWORD _                          ' __in const DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdentityProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' AsyncIIdentityProvider interface
' IID = c6fc9901-c433-4646-8f48-4e4687aae2a0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIIdentityProvider_INTERFACE_DEFINED)
    %AsyncIIdentityProvider_INTERFACE_DEFINED = 1

$IID_AsyncIIdentityProvider = GUID$("{c6fc9901-c433-4646-8f48-4e4687aae2a0}")

INTERFACE AsyncIIdentityProvider $IID_AsyncIIdentityProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_GetIdentityEnum ( _                     ' VTable offset = 12
     BYVAL eIdentityType AS LONG _                      ' __in const IDENTITY_TYPE eIdentityType
   , BYREF pFilterkey AS PROPERTYKEY _                  ' __in const PROPERTYKEY *pFilterkey
   , BYREF pFilterPropVarValue AS PROPVARIANT _         ' __in const PROPVARIANT *pFilterPropVarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_GetIdentityEnum ( _                    ' VTable offset = 16
     BYREF ppIdentityEnum AS IEnumUnknown _             ' __out IEnumUnknown **ppIdentityEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Create ( _                              ' VTable offset = 20
     BYREF lpszUserName AS WSTRINGZ _                   ' __in LPCWSTR lpszUserName
   , BYREF pKeywordsToAdd AS PROPVARIANT _              ' __in const PROPVARIANT *pKeywordsToAdd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Create ( _                             ' VTable offset = 24
     BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Import ( _                              ' VTable offset = 28
     BYVAL pPropertyStore AS IPropertyStore _           ' __in IPropertyStore *pPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Import ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Delete ( _                              ' VTable offset = 36
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF pKeywordsToDelete AS PROPVARIANT _           ' __in const PROPVARIANT *pKeywordsToDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Delete ( _                             ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_FindByUniqueID ( _                      ' VTable offset = 44
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_FindByUniqueID ( _                     ' VTable offset = 48
     BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_GetProviderPropertyStore ( _            ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_GetProviderPropertyStore ( _           ' VTable offset = 56
     BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Advise ( _                              ' VTable offset = 60
     BYVAL pIdentityAdvise AS IIdentityAdvise _         ' __in_opt IIdentityAdvise *pIdentityAdvise
   , BYVAL dwIdentityUpdateEvents AS DWORD _            ' __in DWORD dwIdentityUpdateEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Advise ( _                             ' VTable offset = 64
     BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_UnAdvise ( _                            ' VTable offset = 68
     BYVAL dwCookie AS DWORD _                          ' __in const DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_UnAdvise ( _                           ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIIdentityProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' IAssociatedIdentityProvider interface
' IID = 2af066b3-4cbb-4cba-a798-204b6af68cc0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssociatedIdentityProvider_INTERFACE_DEFINED)
    %IAssociatedIdentityProvider_INTERFACE_DEFINED = 1

$IID_IAssociatedIdentityProvider = GUID$("{2af066b3-4cbb-4cba-a798-204b6af68cc0}")

INTERFACE IAssociatedIdentityProvider $IID_IAssociatedIdentityProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AssociateIdentity ( _                         ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisassociateIdentity ( _                      ' VTable offset = 16
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeCredential ( _                          ' VTable offset = 20
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssociatedIdentityProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' AsyncIAssociatedIdentityProvider interface
' IID = 2834d6ed-297e-4e72-8a51-961e86f05152
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIAssociatedIdentityProvider_INTERFACE_DEFINED)
    %AsyncIAssociatedIdentityProvider_INTERFACE_DEFINED = 1

$IID_AsyncIAssociatedIdentityProvider = GUID$("{2834d6ed-297e-4e72-8a51-961e86f05152}")

INTERFACE AsyncIAssociatedIdentityProvider $IID_AsyncIAssociatedIdentityProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_AssociateIdentity ( _                   ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_AssociateIdentity ( _                  ' VTable offset = 16
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF ppPropertyStore AS IPropertyStore _          ' __out IPropertyStore **ppPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_DisassociateIdentity ( _                ' VTable offset = 20
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_DisassociateIdentity ( _               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_ChangeCredential ( _                    ' VTable offset = 28
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_ChangeCredential ( _                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIAssociatedIdentityProvider_INTERFACE_DEFINED__ */
