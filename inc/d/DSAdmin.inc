' ########################################################################################
' Microsoft Windows
' File: DSAdmin.inc
' Contents: DS Admin Object Creation public header
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSADMIN_INC = 1

#INCLUDE ONCE "IAds.inc"

'//
'// CoClass for the Object creation dialog object
'//
$CLSID_DsAdminCreateObj        = GUID$("{E301A009-F901-11D2-82B9-00C04F68928B}")

'//
'// Interface GUIDs
'//

$IID_IDsAdminCreateObj         = GUID$("{53554A38-F902-11D2-82B9-00C04F68928B}")
$IID_IDsAdminNewObj            = GUID$("{F2573587-E6FC-11D2-82AF-00C04F68928B}")
$IID_IDsAdminNewObjPrimarySite = GUID$("{BE2B487E-F904-11D2-82B9-00C04F68928B}")
$IID_IDsAdminNewObjExt         = GUID$("{6088EAE2-E7BF-11D2-82AF-00C04F68928B}")
$IID_IDsAdminNotifyHandler     = GUID$("{E4A2B8B3-5A18-11D2-97C1-00A0C9A06D2D}")


' ########################################################################################
' Interface name = IDsAdminCreateObj
' IID = 53554A38-F902-11D2-82B9-00C04F68928B
' Inherited interface = IUnknown
' Implemented by the object (implemented by the system) CLSID_DsAdminCreateObj
' Used by: any client needing to invoke the creation UI
' ########################################################################################

INTERFACE IDsAdminCreateObj $IID_IDsAdminCreateObj

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pADsContainerObj AS IADsContainer _          ' __in IADsContainer* pADsContainerObj
   , BYVAL pADsCopySource AS IADs _                     ' __in IADs* pADsCopySource
   , BYREF lpszClassName AS WSTRINGZ _                  ' __in LPCWSTR lpszClassName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateModal ( _                               ' VTable offset = 16
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF ppADsObj AS IADs _                           ' __out IADs** ppADsObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDsAdminNewObj
' IID = F2573587-E6FC-11D2-82AF-00C04F68928B
' Inherited interface = IUnknown
' Implemented by: DS Admin
' Used by: creation extension in proc server (both primary and regular)
' ########################################################################################

INTERFACE IDsAdminNewObj $IID_IDsAdminNewObj

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetButtons ( _                                ' VTable offset = 12
     BYVAL nCurrIndex AS DWORD _                        ' __in ULONG nCurrIndex
   , BYVAL bValid AS LONG _                             ' __in BOOL bValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageCounts ( _                             ' VTable offset = 16
     BYREF pnTotal AS LONG _                            ' __out LONG* pnTotal
   , BYREF pnStartIndex AS LONG _                       ' __out LONG* pnStartIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDsAdminNewObjPrimarySite
' IID = BE2B487E-F904-11D2-82B9-00C04F68928B
' Inherited interface = IUnknown
' Implemented by: DS Admin
' Used by: creation extension in proc server (primary only)
' ########################################################################################

INTERFACE IDsAdminNewObjPrimarySite $IID_IDsAdminNewObjPrimarySite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateNew ( _                                 ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//
'// struct passed to IDsAdminNewObjExt::Initialize()
'//
'// it contains information regarding UI look
'//

' // Size = 16 bytes
TYPE DSA_NEWOBJ_DISPINFO DWORD
   dwSize              AS DWORD          ' DWORD  // size of struct, for versioning
   hObjClassIcon       AS DWORD          ' HICON  // class icon for the object to be created
   lpszWizTitle        AS WSTRINGZ PTR   ' LPWSTR // title of the wizard
   lpszContDisplayName AS WSTRINGZ PTR   ' LPWSTR // container display name (canonical name)
END TYPE

'//
'// context flags passed to IDsAdminNewObjExt::OnError() and to IDsAdminNewObjExt::WriteData()
'//

%DSA_NEWOBJ_CTX_PRECOMMIT      = &H00000001  ' // before SetInfo()
%DSA_NEWOBJ_CTX_COMMIT         = &H00000002  ' // SetInfo(), commit phase
%DSA_NEWOBJ_CTX_POSTCOMMIT     = &H00000003  ' // after SetInfo()
%DSA_NEWOBJ_CTX_CLEANUP        = &H00000004  ' // on post commit fail



' ########################################################################################
' Interface name = IDsAdminNewObjExt
' IID = 6088EAE2-E7BF-11D2-82AF-00C04F68928B
' Inherited interface = IUnknown
' Implemented by: creation extension in proc server (both primary and regular)
' Used by: DS Admin
' ########################################################################################

INTERFACE IDsAdminNewObjExt $IID_IDsAdminNewObjExt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pADsContainerObj AS IADsContainer _          ' __in IADsContainer* pADsContainerObj
   , BYVAL pADsCopySource AS IADs _                     ' __in IADs* pADsCopySource
   , BYREF lpszClassName AS WSTRINGZ _                  ' __in LPCWSTR lpszClassName
   , BYVAL pDsAdminNewObj AS IDsAdminNewObj _           ' __in IDsAdminNewObj* pDsAdminNewObj
   , BYREF pDispInfo AS DSA_NEWOBJ_DISPINFO _           ' __in LPDSA_NEWOBJ_DISPINFO pDispInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPages ( _                                  ' VTable offset = 16
     BYVAL lpfnAddPage AS DWORD _                       ' __in LPFNADDPROPSHEETPAGE lpfnAddPage
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObject ( _                                 ' VTable offset = 20
     BYVAL pADsObj AS IADs _                            ' __in IADs* pADsObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteData ( _                                 ' VTable offset = 24
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL uContext AS DWORD _                          ' __in ULONG uContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnError ( _                                   ' VTable offset = 28
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL uContext AS DWORD _                          ' __in ULONG uContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSummaryInfo ( _                            ' VTable offset = 32
     BYREF pBstrText AS WSTRING _                       ' __out BSTR* pBstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//
'// Notification opcodes for IDsAdminNotifyHandler
'//

%DSA_NOTIFY_DEL      = &H00000001  ' // delete
%DSA_NOTIFY_REN      = &H00000002  ' // rename
%DSA_NOTIFY_MOV      = &H00000004  ' // move
%DSA_NOTIFY_PROP     = &H00000008  ' // property change

%DSA_NOTIFY_ALL = (%DSA_NOTIFY_DEL OR %DSA_NOTIFY_REN OR %DSA_NOTIFY_MOV OR %DSA_NOTIFY_PROP)

'//
'// TODO: add explaination
'//
'// flags to handle additional data
'//

%DSA_NOTIFY_FLAG_ADDITIONAL_DATA        = &H00000002   ' // process additional extension data?
%DSA_NOTIFY_FLAG_FORCE_ADDITIONAL_DATA  = &H00000001   ' // operation forced


' ########################################################################################
' Interface name = IDsAdminNotifyHandler
' IID = E4A2B8B3-5A18-11D2-97C1-00A0C9A06D2D
' Inherited interface = IUnknown
' Implemented by: notification handler in proc server
' Used by: DS Admin
' ########################################################################################

INTERFACE IDsAdminNotifyHandler $IID_IDsAdminNotifyHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pExtraInfo AS IDataObject _                  ' __in IDataObject* pExtraInfo
   , BYREF puEventFlags AS DWORD _                      ' __out ULONG* puEventFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 16
     BYVAL uEvent AS DWORD _                            ' __in ULONG uEvent
   , BYVAL pArg1 AS IDataObject _                       ' __in IDataObject* pArg1
   , BYVAL pArg2 AS IDataObject  _                      ' __in IDataObject* pArg2
   , BYREF puFlags AS DWORD _                           ' __out ULONG* puFlags
   , BYREF pBstr AS WSTRING _                           ' __out BSTR* pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 20
     BYVAL nItem AS DWORD _                             ' __in ULONG nItem
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
