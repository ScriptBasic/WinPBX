' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryAPI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUNCTIONDISVOERYAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"

'enum tagPropertyConstraint
'    {   QC_EQUALS   = 0,
'   QC_NOTEQUAL   = 1,
'   QC_LESSTHAN   = 2,
'   QC_LESSTHANOREQUAL   = 3,
'   QC_GREATERTHAN   = 4,
'   QC_GREATERTHANOREQUAL   = 5,
'   QC_STARTSWITH   = 6,
'   QC_EXISTS   = 7,
'   QC_DOESNOTEXIST   = 8,
'   QC_CONTAINS   = 9
'    }    PropertyConstraint;

'//#if ( WINVER >= 0x0600 )
'#ifndef FD_LONGHORN
'#define FD_LONGHORN 1
'#endif
'#ifndef FDPropertyConstraint
'#define FDPropertyConstraint
'#endif

#IF NOT %DEF(%FDPropertyConstraint)
%FDPropertyConstraint = 1
' enum PropertyConstraint alias tagQueryUpdateAction
%QC_EQUALS             = 0
%QC_NOTEQUAL           = 1
%QC_LESSTHAN           = 2
%QC_LESSTHANOREQUAL    = 3
%QC_GREATERTHAN        = 4
%QC_GREATERTHANOREQUAL = 5
%QC_STARTSWITH         = 6   ' // Strings only
%QC_EXISTS             = 7
%QC_DOESNOTEXIST       = 8
%QC_CONTAINS           = 9   ' // Strings and VT_VECTOR only
#ENDIF

#INCLUDE ONCE "FunctionDiscoveryCategories.inc"
#INCLUDE ONCE "FunctionDiscoveryError.inc"
#INCLUDE ONCE "FunctionDiscoveryKeys.inc"
#INCLUDE ONCE "FunctionDiscoveryServiceIDs.inc"
#INCLUDE ONCE "FunctionDiscoveryConstraints.inc"

'typedef DWORDLONG FDQUERYCONTEXT;

' enum SystemVisibilityFlags
%SVF_SYSTEM = 0
%SVF_USER   = 1

' enum QueryUpdateAction
%QUA_ADD    = 0
%QUA_REMOVE = 1
%QUA_CHANGE = 2

' enum QueryCategoryType
%QCT_PROVIDER = 0
%QCT_LAYERED  = 1

$IID_IFunctionDiscovery = GUID$("{4DF99B70-E148-4432-B004-4C9EEB535A5E}")
$IID_IFunctionDiscoveryNotification = GUID$("{5F6C1BA8-5330-422E-A368-572B244D3F87}")
$IID_IFunctionInstance = GUID$("{33591C10-0BED-4F02-B0AB-1530D5533EE9}")
$IID_IFunctionInstanceCollection = GUID$("{F0A3D895-855C-42A2-948D-2F97D450ECB1}")
$IID_IFunctionInstanceCollectionQuery = GUID$("{57CC6FD2-C09A-4289-BB72-25F04142058E}")
$IID_IFunctionInstanceQuery = GUID$("{6242BC6B-90EC-4B37-BB46-E229FD84ED95}")
$IID_IPropertyStoreCollection = GUID$("{D14D9C30-12D2-42D8-BCE4-C60C2BB226FA}")


' ########################################################################################
' Interface name = IFunctionDiscoveryNotification
' IID = 5F6C1BA8-5330-422E-A368-572B244D3F87
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionDiscoveryNotification_INTERFACE_DEFINED)
    %IFunctionDiscoveryNotification_INTERFACE_DEFINED = 1

INTERFACE IFunctionDiscoveryNotification $IID_IFunctionDiscoveryNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnUpdate ( _                                  ' VTable offset = 12
     BYVAL enumQueryUpdateAction AS LONG _              ' __in tagQueryUpdateAction enumQueryUpdateAction
   , BYVAL fdqcQueryContext AS QUAD _                   ' __in FDQUERYCONTEXT fdqcQueryContext
   , BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnError ( _                                   ' VTable offset = 16
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL fdqcQueryContext AS QUAD _                   ' __in FDQUERYCONTEXT fdqcQueryContext
   , BYREF pszProvider AS WSTRINGZ _                    ' __in WCHAR pszProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 20
     BYVAL dwEventID AS DWORD _                         ' __in DWORD dwEventID
   , BYVAL fdqcQueryContext AS QUAD _                   ' __in FDQUERYCONTEXT fdqcQueryContext
   , BYREF pszProvider AS WSTRINGZ _                    ' __in WCHAR pszProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionDiscoveryNotification_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionDiscovery
' IID = 4DF99B70-E148-4432-B004-4C9EEB535A5E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionDiscovery_INTERFACE_DEFINED)
    %IFunctionDiscovery_INTERFACE_DEFINED = 1

INTERFACE IFunctionDiscovery $IID_IFunctionDiscovery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInstanceCollection ( _                     ' VTable offset = 12
     BYREF pszCategory AS WSTRINGZ _                    ' __in WCHAR pszCategory
   , BYREF pszSubCategory AS WSTRINGZ _                 ' __in WCHAR pszSubCategory
   , BYVAL fIncludeAllSubCategories AS LONG _           ' __in BOOL fIncludeAllSubCategories
   , BYREF ppIFunctionInstanceCollection AS IFunctionInstanceCollection _ ' __retval_out IFunctionInstanceCollection **ppIFunctionInstanceCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInstance ( _                               ' VTable offset = 16
     BYREF pszFunctionInstanceIdentity AS WSTRINGZ _    ' __in WCHAR pszFunctionInstanceIdentity
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __retval_out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceCollectionQuery ( _             ' VTable offset = 20
     BYREF pszCategory AS WSTRINGZ _                    ' __in WCHAR pszCategory
   , BYREF pszSubCategory AS WSTRINGZ _                 ' __in WCHAR pszSubCategory
   , BYVAL fIncludeAllSubCategories AS LONG _           ' __in BOOL fIncludeAllSubCategories
   , BYVAL pIFunctionDiscoveryNotification AS IFunctionDiscoveryNotification _ ' __in IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification
   , BYREF pfdqcQueryContext AS QUAD _                  ' __in__out FDQUERYCONTEXT *pfdqcQueryContext
   , BYREF ppIFunctionInstanceCollectionQuery AS IFunctionInstanceCollectionQuery _ ' __retval_out IFunctionInstanceCollectionQuery **ppIFunctionInstanceCollectionQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceQuery ( _                       ' VTable offset = 24
     BYREF pszFunctionInstanceIdentity AS WSTRINGZ _    ' __in WCHAR pszFunctionInstanceIdentity
   , BYVAL pIFunctionDiscoveryNotification AS IFunctionDiscoveryNotification _ ' __in IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification
   , BYREF pfdqcQueryContext AS QUAD _                  ' __in__out FDQUERYCONTEXT *pfdqcQueryContext
   , BYREF ppIFunctionInstanceQuery AS IFunctionInstanceQuery _ ' __retval_out IFunctionInstanceQuery **ppIFunctionInstanceQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddInstance ( _                               ' VTable offset = 28
     BYVAL enumSystemVisibility AS LONG _               ' __in tagSystemVisibilityFlags enumSystemVisibility
   , BYREF pszCategory AS WSTRINGZ _                    ' __in WCHAR pszCategory
   , BYREF pszSubCategory AS WSTRINGZ _                 ' __in WCHAR pszSubCategory
   , BYREF pszCategoryIdentity AS WSTRINGZ _            ' __in WCHAR pszCategoryIdentity
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __retval_out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveInstance ( _                            ' VTable offset = 32
     BYVAL enumSystemVisibility AS LONG _               ' __in tagSystemVisibilityFlags enumSystemVisibility
   , BYREF pszCategory AS WSTRINGZ _                    ' __in WCHAR pszCategory
   , BYREF pszSubCategory AS WSTRINGZ _                 ' __in WCHAR pszSubCategory
   , BYREF pszCategoryIdentity AS WSTRINGZ _            ' __in WCHAR pszCategoryIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionDiscovery_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionInstance
' IID = 33591C10-0BED-4F02-B0AB-1530D5533EE9
' Inherited interface = IServiceProvider
' ########################################################################################

#IF NOT %DEF(%IFunctionInstance_INTERFACE_DEFINED)
    %IFunctionInstance_INTERFACE_DEFINED = 1

INTERFACE IFunctionInstance $IID_IFunctionInstance

   INHERIT IUnknown

   ' =====================================================================================
   ' IServiceProvider Methods
   ' =====================================================================================
   METHOD QueryService ( _                              ' VTable offset = 12
     BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFGUID riid GUID
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFunctionInstance Methods
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 16
     BYREF ppszCoMemIdentity AS WSTRINGZ _              ' __retval_out WCHAR *ppszCoMemIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProviderInstanceID ( _                     ' VTable offset = 20
     BYREF ppszCoMemProviderInstanceIdentity AS WSTRINGZ _ ' __retval_out WCHAR *ppszCoMemProviderInstanceIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenPropertyStore ( _                         ' VTable offset = 24
     BYVAL dwStgAccess AS DWORD _                       ' __in DWORD dwStgAccess
   , BYREF ppIPropertyStore AS IPropertyStore _         ' __retval_out IPropertyStore **ppIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 28
     BYREF ppszCoMemCategory AS WSTRINGZ _              ' __out WCHAR *ppszCoMemCategory
   , BYREF ppszCoMemSubCategory AS WSTRINGZ _           ' __out WCHAR *ppszCoMemSubCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionInstance_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionInstanceCollection
' IID = F0A3D895-855C-42A2-948D-2F97D450ECB1
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionInstanceCollection_INTERFACE_DEFINED)
    %IFunctionInstanceCollection_INTERFACE_DEFINED = 1

INTERFACE IFunctionInstanceCollection $IID_IFunctionInstanceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __retval_out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF pszInstanceIdentity AS WSTRINGZ _            ' __in const WCHAR pszInstanceIdentity
   , BYREF pdwIndex AS DWORD _                          ' __out DWORD *pdwIndex
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __retval_out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __retval_out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 24
     BYVAL pIFunctionInstance AS IFunctionInstance _    ' __in IFunctionInstance *pIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppIFunctionInstance AS IFunctionInstance _   ' __retval_out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 32
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAll ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionInstanceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyStoreCollection
' IID = D14D9C30-12D2-42D8-BCE4-C60C2BB226FA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyStoreCollection_INTERFACE_DEFINED)
    %IPropertyStoreCollection_INTERFACE_DEFINED = 1

INTERFACE IPropertyStoreCollection $IID_IPropertyStoreCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __retval_out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF pszInstanceIdentity AS WSTRINGZ _            ' __in const WCHAR pszInstanceIdentity
   , BYREF pdwIndex AS DWORD _                          ' __out DWORD *pdwIndex
   , BYREF ppIPropertyStore AS IPropertyStore _         ' __retval_out IPropertyStore **ppIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppIPropertyStore AS IPropertyStore _         ' __retval_out IFunctionInstance **ppIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 24
     BYVAL pIPropertyStore AS IPropertyStore _          ' __in IPropertyStore *pIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pIPropertyStore AS IPropertyStore _          ' __retval_out IPropertyStore **pIPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 32
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAll ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyStoreCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionInstanceQuery
' IID = 6242BC6B-90EC-4B37-BB46-E229FD84ED95
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionInstanceQuery_INTERFACE_DEFINED)
    %IFunctionInstanceQuery_INTERFACE_DEFINED = 1

INTERFACE IFunctionInstanceQuery $IID_IFunctionInstanceQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 12
     BYREF ppIFunctionInstance AS IFunctionInstance _   ' __retval_out IFunctionInstance **ppIFunctionInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionInstanceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFunctionInstanceCollectionQuery
' IID = 57CC6FD2-C09A-4289-BB72-25F04142058E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFunctionInstanceCollectionQuery_INTERFACE_DEFINED)
    %IFunctionInstanceCollectionQuery_INTERFACE_DEFINED = 1

INTERFACE IFunctionInstanceCollectionQuery $IID_IFunctionInstanceCollectionQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddQueryConstraint ( _                        ' VTable offset = 12
     BYREF pszConstraintName AS WSTRINGZ _              ' __in WCHAR pszConstraintName
   , BYREF pszConstraintValue AS WSTRINGZ _             ' __in WCHAR pszConstraintValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPropertyConstraint ( _                     ' VTable offset = 16
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY *key
   , BYREF pv AS PROPVARIANT _                          ' __in PROPVARIANT *pv
   , BYVAL enumPropertyConstraint AS LONG _             ' __in tagPropertyConstraint enumPropertyConstraint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 20
     BYREF ppIFunctionInstanceCollection AS IFunctionInstanceCollection _ ' __out IFunctionInstanceCollection **ppIFunctionInstanceCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFunctionInstanceCollectionQuery_INTERFACE_DEFINED__ */

'#INCLUDE ONCE "FunctionDiscoveryNotification.inc"
