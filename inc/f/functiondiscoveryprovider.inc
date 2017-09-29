' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryProvider.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERYPROVIDER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "FunctionDiscoveryAPI.inc"

' ########################################################################################
' Interface name = IFunctionDiscoveryProvider
' IID = DCDE394F-1478-4813-A402-F6FB10657222
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionDiscoveryProvider_INTERFACE_DEFINED)
    %IFunctionDiscoveryProvider_INTERFACE_DEFINED = 1

$IID_IFunctionDiscoveryProvider = GUID$("{DCDE394F-1478-4813-A402-F6FB10657222}")

INTERFACE IFunctionDiscoveryProvider $IID_IFunctionDiscoveryProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pIFunctionDiscoveryProviderFactory AS IFunctionDiscoveryProviderFactory _ ' __in IFunctionDiscoveryProviderFactory *pIFunctionDiscoveryProviderFactory
   , BYVAL pIFunctionDiscoveryNotification AS IFunctionDiscoveryNotification _ ' __in IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification
   , BYVAL lcidUserDefault AS DWORD _                   ' __in LCID lcidUserDefault
   , BYREF pdwStgAccessCapabilities AS DWORD _          ' __out DWORD *pdwStgAccessCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 16
     BYVAL pIFunctionDiscoveryProviderQuery AS IFunctionDiscoveryProviderQuery _ ' __in IFunctionDiscoveryProviderQuery *pIFunctionDiscoveryProviderQuery
   , BYREF ppIFunctionInstanceCollection AS IFunctionInstanceCollection _ ' __out IFunctionInstanceCollection **ppIFunctionInstanceCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndQuery ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstancePropertyStoreValidateAccess ( _       ' VTable offset = 24
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYVAL dwStgAccess AS DWORD _                       ' __in const DWORD dwStgAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstancePropertyStoreOpen ( _                 ' VTable offset = 28
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYVAL dwStgAccess AS DWORD _                       ' __in const DWORD dwStgAccess
   , BYREF ppIPropertyStore AS IPropertyStore _         ' __out IPropertyStore **ppIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstancePropertyStoreFlush ( _                ' VTable offset = 32
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstanceQueryService ( _                      ' VTable offset = 36
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppIUnknown AS IUnknown _                     ' __out IUnknown **ppIUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstanceReleased ( _                          ' VTable offset = 40
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionDiscoveryProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProviderProperties
' IID = CF986EA6-3B5F-4C5F-B88A-2F8B20CEEF17
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProviderProperties_INTERFACE_DEFINED)
    %IProviderProperties_INTERFACE_DEFINED = 1

$IID_IProviderProperties = GUID$("{CF986EA6-3B5F-4C5F-B88A-2F8B20CEEF17}")

INTERFACE IProviderProperties $IID_IProviderProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pKey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYREF Key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY Key
   , BYREF ppropVar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 24
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYREF Key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY Key
   , BYREF ppropVar AS PROPVARIANT _                    ' __in const PROPVARIANT *ppropVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProviderProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProviderPublishing
' IID = CD1B9A04-206C-4A05-A0C8-1635A21A2B7C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProviderPublishing_INTERFACE_DEFINED)
    %IProviderPublishing_INTERFACE_DEFINED = 1

$IID_IProviderPublishing = GUID$("{CD1B9A04-206C-4A05-A0C8-1635A21A2B7C}")

INTERFACE IProviderPublishing $IID_IProviderPublishing

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYVAL enumVisibilityFlags AS LONG _                ' __in SystemVisibilityFlags enumVisibilityFlags
   , BYREF pszSubCategory AS WSTRINGZ _                 ' __in const WCHAR *pszSubCategory
   , BYREF pszProviderInstanceIdentity AS WSTRINGZ _    ' __in const WCHAR *pszProviderInstanceIdentity
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveInstance ( _                            ' VTable offset = 16
     BYVAL enumVisibilityFlags AS LONG _                ' __in SystemVisibilityFlags enumVisibilityFlags
   , BYREF pszSubCategory AS WSTRINGZ _                 ' __in const WCHAR *pszSubCategory
   , BYREF pszProviderInstanceIdentity AS WSTRINGZ _    ' __in const WCHAR *pszProviderInstanceIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProviderPublishing_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionDiscoveryProviderFactory
' IID = 86443FF0-1AD5-4E68-A45A-40C2C329DE3B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionDiscoveryProviderFactory_INTERFACE_DEFINED)
    %IFunctionDiscoveryProviderFactory_INTERFACE_DEFINED = 1

$IID_IFunctionDiscoveryProviderFactory = GUID$("{86443FF0-1AD5-4E68-A45A-40C2C329DE3B}")

INTERFACE IFunctionDiscoveryProviderFactory $IID_IFunctionDiscoveryProviderFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePropertyStore ( _                       ' VTable offset = 12
     BYREF ppIPropertyStore AS IPropertyStore _         ' __out IPropertyStore **ppIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 16
     BYREF pszSubCategory AS WSTRINGZ _                 ' __in const WCHAR *pszSubCategory
   , BYREF pszProviderInstanceIdentity AS WSTRINGZ _    ' __in const WCHAR *pszProviderInstanceIdentity
   , BYVAL iProviderInstanceContext AS DWORD _          ' __in INT_PTR iProviderInstanceContext
   , BYVAL pIPropertyStore AS IPropertyStore _          ' __in IPropertyStore *pIPropertyStore
   , BYVAL pIFunctionDiscoveryProvider AS IFunctionDiscoveryProvider _ ' __in IFunctionDiscoveryProvider *pIFunctionDiscoveryProvider
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFunctionInstanceCollection ( _          ' VTable offset = 20
     BYREF ppIFunctionInstanceCollection AS IFunctionInstanceCollection _ ' __out IFunctionInstanceCollection **ppIFunctionInstanceCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionDiscoveryProviderFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionDiscoveryProviderQuery
' IID = 6876EA98-BAEC-46DB-BC20-75A76E267A3A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionDiscoveryProviderQuery_INTERFACE_DEFINED)
    %IFunctionDiscoveryProviderQuery_INTERFACE_DEFINED = 1

$IID_IFunctionDiscoveryProviderQuery = GUID$("{6876EA98-BAEC-46DB-BC20-75A76E267A3A}")

INTERFACE IFunctionDiscoveryProviderQuery $IID_IFunctionDiscoveryProviderQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsInstanceQuery ( _                           ' VTable offset = 12
     BYREF pisInstanceQuery AS LONG _                   ' __out BOOL *pisInstanceQuery
   , BYREF ppszConstraintValue AS WSTRINGZ _            ' __out WCHAR **ppszConstraintValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSubcategoryQuery ( _                        ' VTable offset = 16
     BYREF pisSubcategoryQuery AS LONG _                ' __out BOOL *pisSubcategoryQuery
   , BYREF ppszConstraintValue AS WSTRINGZ _            ' __out WCHAR **ppszConstraintValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueryConstraints ( _                       ' VTable offset = 20
     BYREF ppIProviderQueryConstraints AS IProviderQueryConstraintCollection _ ' __out IProviderQueryConstraintCollection **ppIProviderQueryConstraints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyConstraints ( _                    ' VTable offset = 24
     BYREF ppIProviderPropertyConstraints AS IProviderPropertyConstraintCollection _ ' __out IProviderPropertyConstraintCollection **ppIProviderPropertyConstraints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionDiscoveryProviderQuery_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProviderQueryConstraintCollection
' IID = 9C243E11-3261-4BCD-B922-84A873D460AE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProviderQueryConstraintCollection_INTERFACE_DEFINED)
    %IProviderQueryConstraintCollection_INTERFACE_DEFINED = 1

$IID_IProviderQueryConstraintCollection = GUID$("{9C243E11-3261-4BCD-B922-84A873D460AE}")

INTERFACE IProviderQueryConstraintCollection $IID_IProviderQueryConstraintCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF pszConstraintName AS WSTRINGZ _              ' __in const WCHAR *pszConstraintName
   , BYREF ppszConstraintValue AS WSTRINGZ _            ' __out WCHAR **ppszConstraintValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppszConstraintName AS WSTRINGZ _             ' __out WCHAR **ppszConstraintName
   , BYREF ppszConstraintValue AS WSTRINGZ _            ' __out WCHAR **ppszConstraintValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 24
     BYREF ppszConstraintName AS WSTRINGZ _             ' __out WCHAR **ppszConstraintName
   , BYREF ppszConstraintValue AS WSTRINGZ _            ' __out WCHAR **ppszConstraintValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProviderQueryConstraintCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProviderPropertyConstraintCollection
' IID = F4FAE42F-5778-4A13-8540-B5FD8C1398DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProviderPropertyConstraintCollection_INTERFACE_DEFINED)
    %IProviderPropertyConstraintCollection_INTERFACE_DEFINED = 1

$IID_IProviderPropertyConstraintCollection = GUID$("{F4FAE42F-5778-4A13-8540-B5FD8C1398DD}")

INTERFACE IProviderPropertyConstraintCollection $IID_IProviderPropertyConstraintCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF Key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY Key
   , BYREF pPropVar AS PROPVARIANT _                    ' __out PROPVARIANT *pPropVar
   , BYREF pdwPropertyConstraint AS DWORD _             ' __out DWORD *pdwPropertyConstraint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pKey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pKey
   , BYREF pPropVar AS PROPVARIANT _                    ' __out PROPVARIANT *pPropVar
   , BYREF pdwPropertyConstraint AS DWORD _             ' __out DWORD *pdwPropertyConstraint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 24
     BYREF pKey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pKey
   , BYREF pPropVar AS PROPVARIANT _                    ' __out PROPVARIANT *pPropVar
   , BYREF pdwPropertyConstraint AS DWORD _             ' __out DWORD *pdwPropertyConstraint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProviderPropertyConstraintCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionDiscoveryServiceProvider
' IID = 4C81ED02-1B04-43F2-A451-69966CBCD1C2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionDiscoveryServiceProvider_INTERFACE_DEFINED)
    %IFunctionDiscoveryServiceProvider_INTERFACE_DEFINED = 1

$IID_IFunctionDiscoveryServiceProvider = GUID$("{4C81ED02-1B04-43F2-A451-69966CBCD1C2}")

INTERFACE IFunctionDiscoveryServiceProvider $IID_IFunctionDiscoveryServiceProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __retval_out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionDiscoveryServiceProvider_INTERFACE_DEFINED__ */
