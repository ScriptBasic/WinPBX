' ########################################################################################
' Microsoft Windows
' File: jetoledb.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%JETOLEDB_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "oledb.inc"

'typedef DWORD DBOBJTYPE;

' enum DBTYPE_ENUM
%DBJETOBJECT_TABLE   = &H1???
%DBJETOBJECT_INDEX   = &H2???
%DBJETOBJECT_VIEWS   = &H4???

'typedef DWORD USERATTRIBUTESFLAGS;

'enum USERATTRIBUTESFLAGS_ENUM
%DBJETOLEDB_USERATTRIBUTES_ALLCOLLECTIONS = 1???
%DBJETOLEDB_USERATTRIBUTES_INHERITED      = 2???


' ########################################################################################
' IDBUserAttributes interface
' IID = CB9497B0-20B8-11D2-A4DC-00C04F991C78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBUserAttributes_INTERFACE_DEFINED)
    %IDBUserAttributes_INTERFACE_DEFINED = 1

$IID_IDBUserAttributes = GUID$("{CB9497B0-20B8-11D2-A4DC-00C04F991C78}")

INTERFACE IDBUserAttributes $IID_IDBUserAttributes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateObject ( _                              ' VTable offset = 12
     BYREF pParentID AS DBID _                          ' __in DBID *pParentID
   , BYREF pObjectID AS DBID _                          ' __in DBID *pObjectID
   , BYVAL dwType AS DWORD _                            ' __in DBOBJTYPE dwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteObject ( _                              ' VTable offset = 16
     BYREF pParentID AS DBID _                          ' __in DBID *pParentID
   , BYREF pObjectID AS DBID _                          ' __in DBID *pObjectID
   , BYVAL dwType AS DWORD _                            ' __in DBOBJTYPE dwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameObject ( _                              ' VTable offset = 20
     BYREF pParentID AS DBID _                          ' __in DBID *pParentID
   , BYREF pObjectID AS DBID _                          ' __in DBID *pObjectID
   , BYREF dwType AS WSTRINGZ _                         ' __in LPWSTR pwszNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttribute ( _                           ' VTable offset = 24
     BYREF pParentID AS DBID _                          ' __in DBID *pParentID
   , BYREF pObjectID AS DBID _                          ' __in DBID *pObjectID
   , BYREF pSubObjectID AS DBID _                       ' __in DBID *pSubObjectID
   , BYREF pAttributeID AS DBID _                       ' __in DBID *pAttributeID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttributeValue ( _                         ' VTable offset = 28
     BYREF pParentID AS DBID _                          ' __in DBID *pParentID
   , BYREF pObjectID AS DBID _                          ' __in DBID *pObjectID
   , BYREF pSubObjectID AS DBID _                       ' __in DBID *pSubObjectID
   , BYREF pAttributeID AS DBID _                       ' __in DBID *pAttributeID
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   , BYVAL grbit AS DWORD _                             ' __in ULONG grbit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeValue ( _                         ' VTable offset = 32
     BYREF pParentID AS DBID _                          ' __in DBID *pParentID
   , BYREF pObjectID AS DBID _                          ' __in DBID *pObjectID
   , BYREF pSubObjectID AS DBID _                       ' __in DBID *pSubObjectID
   , BYREF pAttributeID AS DBID _                       ' __in DBID *pAttributeID
   , BYREF pvValue AS VARIANT _                         ' __inout VARIANT *pvValue
   , BYVAL grbit AS DWORD _                             ' __in ULONG grbit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeRowset ( _                        ' VTable offset = 36
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL pwszParentID AS DWORD _                      ' __in WCHAR *pwszParentID
   , BYVAL pwszObjectID AS DWORD _                      ' __in WCHAR *pwszObjectID
   , BYVAL pwszSubObjectID AS DWORD _                   ' __in WCHAR *pwszSubObjectID
   , BYVAL pwszAttributeID AS DWORD _                   ' __in WCHAR *pwszAttributeID
   , BYVAL dwFlags AS DWORD _                           ' __in ULONG dwFlags
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET *rgPropertySets
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBUserAttributes_INTERFACE_DEFINED__ */


' ########################################################################################
' IJetCompact interface
' IID = 2A4B6284-EEB4-11D1-A4D9-00C04F991C78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IJetCompact_INTERFACE_DEFINED)
    %IJetCompact_INTERFACE_DEFINED = 1

$IID_IJetCompact = GUID$("{2A4B6284-EEB4-11D1-A4D9-00C04F991C78}")

INTERFACE IJetCompact $IID_IJetCompact

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 12
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IJetCompact_INTERFACE_DEFINED__ */


' ########################################################################################
' IIdle interface
' IID = F497CFC8-8ED8-11D1-9F09-00C04FC2C2E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIdle_INTERFACE_DEFINED)
    %IIdle_INTERFACE_DEFINED = 1

$IID_IIdle = GUID$("{F497CFC8-8ED8-11D1-9F09-00C04FC2C2E0}")

INTERFACE IIdle $IID_IIdle

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Idle ( _                                      ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in ULONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdle_INTERFACE_DEFINED__ */
