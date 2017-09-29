' ########################################################################################
' Microsoft Windows
' File: ComCat.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMCAT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

'//=--------------------------------------------------------------------------=
'// OLE Componet Categories Interfaces.
'//=--------------------------------------------------------------------------=
'//

$CLSID_StdComponentCategoriesMgr = GUID$("{0002E005-0000-C000-0000-000000000046}")

'////////////////////////////////////////////////////////////////////////////
'//  Types
'typedef GUID CATID;
'typedef REFGUID REFCATID;

$CATID_NULL = GUID$("{00000000-0000-0000-0000-000000000000}")
'#define IsEqualCATID(rcatid1rcatid2)       IsEqualGUID(rcatid1rcatid2)

'////////////////////////////////////////////////////////////////////////////
'//  Category IDs (link to uuid3.lib)

$CATID_Insertable                     = GUID$("{40FC6ED3-2438-11CF-A3DB-080036F12502}")
$CATID_Control                        = GUID$("{40FC6ED4-2438-11CF-A3DB-080036F12502}")
$CATID_Programmable                   = GUID$("{40FC6ED5-2438-11CF-A3DB-080036F12502}")
$CATID_IsShortcut                     = GUID$("{40FC6ED6-2438-11CF-A3DB-080036F12502}")
$CATID_NeverShowExt                   = GUID$("{40FC6ED7-2438-11CF-A3DB-080036F12502}")
$CATID_DocObject                      = GUID$("{40FC6ED8-2438-11CF-A3DB-080036F12502}")
$CATID_Printable                      = GUID$("{40FC6ED9-2438-11CF-A3DB-080036F12502}")
$CATID_RequiresDataPathHost           = GUID$("{0DE86A50-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToMoniker              = GUID$("{0DE86A51-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToStorage              = GUID$("{0DE86A52-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToStreamInit           = GUID$("{0DE86A53-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToStream               = GUID$("{0DE86A54-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToMemory               = GUID$("{0DE86A55-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToFile                 = GUID$("{0DE86A56-2BAA-11CF-A229-00AA003D7352}")
$CATID_PersistsToPropertyBag          = GUID$("{0DE86A57-2BAA-11CF-A229-00AA003D7352}")
$CATID_InternetAware                  = GUID$("{0DE86A58-2BAA-11CF-A229-00AA003D7352}")
$CATID_DesignTimeUIActivatableControl = GUID$("{F2BB56D1-DB07-11D1-AA6B-006097DB9539}")


'////////////////////////////////////////////////////////////////////////////
'//  Interface Definitions

' ########################################################################################
' IEnumGUID interface
' IID = 0002E000-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumGUID_INTERFACE_DEFINED)
    %IEnumGUID_INTERFACE_DEFINED = 1

$IID_IEnumGUID = GUID$("{0002E000-0000-0000-C000-000000000046}")
$IID_IEnumCLSID = $IID_IEnumGUID
$IID_IEnumCATID = $IID_IEnumGUID

INTERFACE IEnumGUID $IID_IEnumGUID

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS GUID _                              ' __out GUID *rgelt
   , BYREF pcFetched AS DWORD _                         ' __out ULONG * pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumGUID _                        ' __out IEnumGUID **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumGUID_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumCATEGORYINFO interface
' IID = 0002E011-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumCATEGORYINFO_INTERFACE_DEFINED)
    %IEnumCATEGORYINFO_INTERFACE_DEFINED = 1

' // Size = 276 bytes
TYPE CATEGORYINFO DWORD
   catid         AS GUID             ' CATID catid
   lcid          AS DWORD            ' LCID lcid
   szDescription AS WSTRINGZ * 128   ' OLECHAR szDescription[ 128 ]
END TYPE

$IID_IEnumCATEGORYINFO = GUID$("{0002E011-0000-0000-C000-000000000046}")

INTERFACE IEnumCATEGORYINFO $IID_IEnumCATEGORYINFO

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS CATEGORYINFO _                      ' __out CATEGORYINFO *rgelt
   , BYREF pcFetched AS DWORD _                         ' __out ULONG * pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumCATEGORYINFO _                ' __out IEnumCATEGORYINFO **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCATEGORYINFO_INTERFACE_DEFINED__ */


' ########################################################################################
' ICatRegister interface
' IID = 0002E012-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICatRegister_INTERFACE_DEFINED)
    %ICatRegister_INTERFACE_DEFINED = 1

$IID_ICatRegister = GUID$("{0002E012-0000-0000-C000-000000000046}")

INTERFACE ICatRegister $IID_ICatRegister

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterCategories ( _                        ' VTable offset = 12
     BYVAL cCategories AS DWORD _                       ' __in ULONG cCategories
   , BYREF rgCategoryInfo AS CATEGORYINFO _             ' __in CATEGORYINFO rgCategoryInfo[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterCategories ( _                      ' VTable offset = 16
     BYVAL cCategories AS DWORD _                       ' __in ULONG cCategories
   , BYREF rgcatid AS GUID _                            ' __in CATID rgcatid[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterClassImplCategories ( _               ' VTable offset = 20
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL cCategories AS DWORD _                       ' __in ULONG cCategories
   , BYREF rgcatid AS GUID _                            ' __in CATID rgcatid[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterClassImplCategories ( _             ' VTable offset = 24
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL cCategories AS DWORD _                       ' __in ULONG cCategories
   , BYREF rgcatid AS GUID _                            ' __in CATID rgcatid[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterClassReqCategories ( _                ' VTable offset = 28
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL cCategories AS DWORD _                       ' __in ULONG cCategories
   , BYREF rgcatid AS GUID _                            ' __in CATID rgcatid[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterClassReqCategories ( _              ' VTable offset = 32
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL cCategories AS DWORD _                       ' __in ULONG cCategories
   , BYREF rgcatid AS GUID _                            ' __in CATID rgcatid[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICatRegister_INTERFACE_DEFINED__ */


' ########################################################################################
' ICatInformation interface
' IID = 0002E013-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICatInformation_INTERFACE_DEFINED)
    %ICatInformation_INTERFACE_DEFINED = 1

$IID_ICatInformation = GUID$("{0002E013-0000-0000-C000-000000000046}")

INTERFACE ICatInformation $IID_ICatInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumCategories ( _                            ' VTable offset = 12
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF ppenumCategoryInfo AS IEnumCATEGORYINFO _    ' __out IEnumCATEGORYINFO **ppenumCategoryInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategoryDesc ( _                           ' VTable offset = 16
     BYREF rcatid AS GUID _                             ' __in REFCATID rcatid
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF pszDesc AS DWORD _                           ' __out LPWSTR *pszDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumClassesOfCategories ( _                   ' VTable offset = 20
     BYVAL cImplemented AS DWORD _                      ' __in ULONG cImplemented
   , BYREF rgcatidImpl AS GUID _                        ' __in CATID rgcatidImpl[  ]
   , BYVAL cRequired AS DWORD _                         ' __in ULONG cRequired
   , BYREF rgcatidReq AS GUID _                         ' __in CATID rgcatidReq[  ]
   , BYREF ppenumClsid AS IEnumGUID _                   ' __out IEnumGUID **ppenumClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsClassOfCategories ( _                       ' VTable offset = 24
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL cImplemented AS DWORD _                      ' __in ULONG cImplemented
   , BYREF rgcatidImpl AS GUID _                        ' __in CATID rgcatidImpl[  ]
   , BYVAL cRequired AS DWORD _                         ' __in ULONG cRequired
   , BYREF rgcatidReq AS GUID _                         ' __in CATID rgcatidReq[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumImplCategoriesOfClass ( _                 ' VTable offset = 28
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF ppenumCatid AS IEnumGUID _                   ' __out IEnumGUID **ppenumCatid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumReqCategoriesOfClass ( _                  ' VTable offset = 32
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF ppenumCatid AS IEnumGUID _                   ' __out IEnumGUID **ppenumCatid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICatInformation_INTERFACE_DEFINED__ */
