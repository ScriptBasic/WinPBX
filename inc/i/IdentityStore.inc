' ########################################################################################
' Microsoft Windows
' File: IdentityStore.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IDENTITYSTORE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "IdentityCommon.inc"

'EXTERN_C const IID LIBID_IdentityStoreLib;

$CLSID_CoClassIdentityStore = GUID$("{30d49246-d217-465f-b00b-ac9ddd652eb7}")
$CLSID_CIdentityProfileHandler = GUID$("{ecf5bf46-e3b6-449a-b56b-43f58f867814}")

' ########################################################################################
' IIdentityStore interface
' IID = df586fa5-6f35-44f1-b209-b38e169772eb
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIdentityStore_INTERFACE_DEFINED)
    %IIdentityStore_INTERFACE_DEFINED = 1

$IID_IIdentityStore = GUID$("{df586fa5-6f35-44f1-b209-b38e169772eb}")

INTERFACE IIdentityStore $IID_IIdentityStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pdwProviders AS DWORD _                      ' __out DWORD *pdwProviders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL dwProvider AS DWORD _                        ' __in const DWORD dwProvider
   , BYREF pProvGuid AS GUID _                          ' __inout GUID *pProvGuid
   , BYREF ppIdentityProvider AS IUnknown _             ' __out IUnknown **ppIdentityProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddToCache ( _                                ' VTable offset = 20
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF ProviderGUID AS GUID _                       ' __in REFGUID ProviderGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertToSid ( _                              ' VTable offset = 24
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF ProviderGUID AS GUID _                       ' __in REFGUID ProviderGUID
   , BYVAL cbSid AS WORD _                              ' __in USHORT cbSid
   , BYVAL pSid AS BYTE PTR _                           ' __inout BYTE *pSid
   , BYREF pcbRequiredSid AS WORD _                     ' __out USHORT *pcbRequiredSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateIdentities ( _                       ' VTable offset = 28
     BYVAL eIdentityType AS LONG _                      ' __in const IDENTITY_TYPE eIdentityType
   , BYREF pFilterkey AS PROPERTYKEY _                  ' __in const PROPERTYKEY *pFilterkey
   , BYREF pFilterPropVarValue AS PROPVARIANT _         ' __in const PROPVARIANT *pFilterPropVarValue
   , BYREF ppIdentityEnum AS IEnumUnknown _             ' __out IEnumUnknown **ppIdentityEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdentityStore_INTERFACE_DEFINED__ */

' ########################################################################################
' AsyncIIdentityStore interface
' IID = eefa1616-48de-4872-aa64-6e6206535a51
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIIdentityStore_INTERFACE_DEFINED)
    %AsyncIIdentityStore_INTERFACE_DEFINED = 1

$IID_AsyncIIdentityStore = GUID$("{eefa1616-48de-4872-aa64-6e6206535a51}")

INTERFACE AsyncIIdentityStore $IID_AsyncIIdentityStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_GetCount ( _                            ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_GetCount ( _                           ' VTable offset = 16
     BYREF pdwProviders AS DWORD _                      ' __out DWORD *pdwProviders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_GetAt ( _                               ' VTable offset = 20
     BYVAL dwProvider AS DWORD _                        ' __in const DWORD dwProvider
   , BYREF pProvGuid AS GUID _                          ' __inout GUID *pProvGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_GetAt ( _                              ' VTable offset = 24
     BYREF pProvGuid AS GUID _                          ' __inout GUID *pProvGuid
   , BYREF ppIdentityProvider AS IUnknown _             ' __out IUnknown **ppIdentityProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_AddToCache ( _                          ' VTable offset = 28
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF ProviderGUID AS GUID _                       ' __in REFGUID ProviderGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_AddToCache ( _                         ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_ConvertToSid ( _                        ' VTable offset = 36
     BYREF lpszUniqueID AS WSTRINGZ _                   ' __in LPCWSTR lpszUniqueID
   , BYREF ProviderGUID AS GUID _                       ' __in REFGUID ProviderGUID
   , BYVAL cbSid AS WORD _                              ' __in USHORT cbSid
   , BYVAL pSid AS BYTE PTR _                           ' __inout BYTE *pSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_ConvertToSid ( _                       ' VTable offset = 40
     BYVAL pSid AS BYTE PTR _                           ' __inout BYTE *pSid
   , BYREF pcbRequiredSid AS WORD _                     ' __out USHORT *pcbRequiredSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_EnumerateIdentities ( _                 ' VTable offset = 44
     BYVAL eIdentityType AS LONG _                      ' __in const IDENTITY_TYPE eIdentityType
   , BYREF pFilterkey AS PROPERTYKEY _                  ' __in const PROPERTYKEY *pFilterkey
   , BYREF pFilterPropVarValue AS PROPVARIANT _         ' __in const PROPVARIANT *pFilterPropVarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_EnumerateIdentities ( _                ' VTable offset = 48
     BYREF ppIdentityEnum AS IEnumUnknown _             ' __out IEnumUnknown **ppIdentityEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Reset ( _                               ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Reset ( _                              ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIIdentityStore_INTERFACE_DEFINED__ */
