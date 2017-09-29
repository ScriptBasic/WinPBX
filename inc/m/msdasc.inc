' ########################################################################################
' Microsoft Windows
' File: msdasc.inc
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSDASC
' Version: 1.0
' Documentation string: Microsoft OLE DB Service Component 1.0 Type Library
' Path: C:\Archivos de programa\Archivos comunes\system\ole db\oledb32.dll
' Library GUID: {2206CEB0-19C1-11D1-89E0-00C04FD7A829}
' ########################################################################################

#INCLUDE THIS ONCE
%MSDASC_INC = 1

#INCLUDE ONCE "ole2.inc"

'#ifdef _WIN64
'typedef LONGLONG         COMPATIBLE_LONG;
'#else
'typedef LONG COMPATIBLE_LONG;
'#endif   // _WIN64

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {2206CDB2-19C1-11D1-89E0-00C04FD7A829}
$PROGID_DataLinks = "DataLinks"
' CLSID = {2206CDB0-19C1-11D1-89E0-00C04FD7A829}
$PROGID_MSDASCMSDAINITIALIZE1 = "MSDASC.MSDAINITIALIZE.1"
' CLSID = {CCB4EC60-B9DC-11D1-AC80-00A0C9034873}
$PROGID_MSDASCPDPO1 = "MSDASC.PDPO.1"
' CLSID = {FF151822-B0BF-11D1-A80D-000000000000}
$PROGID_MSDAURLBinder1 = "MSDAURL.Binder.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {2206CDB0-19C1-11D1-89E0-00C04FD7A829}
$PROGID_MSDASCMSDAINITIALIZE = "MSDASC.MSDAINITIALIZE"
' CLSID = {CCB4EC60-B9DC-11D1-AC80-00A0C9034873}
$PROGID_MSDASCPDPO = "MSDASC.PDPO"
' CLSID = {FF151822-B0BF-11D1-A80D-000000000000}
$PROGID_MSDAURLBinder = "MSDAURL.Binder"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DataLinks = GUID$("{2206CDB2-19C1-11D1-89E0-00C04FD7A829}")
$CLSID_MSDAINITIALIZE = GUID$("{2206CDB0-19C1-11D1-89E0-00C04FD7A829}")
$CLSID_PDPO = GUID$("{CCB4EC60-B9DC-11D1-AC80-00A0C9034873}")
$CLSID_RootBinder = GUID$("{FF151822-B0BF-11D1-A80D-000000000000}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IService = GUID$("{06210E88-01F5-11D1-B512-0080C781C384}")
$IID_IDBPromptInitialize = GUID$("{2206CCB0-19C1-11D1-89E0-00C04FD7A829}")
$IID_IDataInitialize = GUID$("{2206CCB1-19C1-11D1-89E0-00C04FD7A829}")
$IID_IDataSourceLocator = GUID$("{2206CCB2-19C1-11D1-89E0-00C04FD7A829}")

' EBindInfoOptions
%BIO_BINDER = &H1

%STGM_COLLECTION = &H00002000???
%STGM_OUTPUT     = &H00008000???
%STGM_OPEN       = &H80000000???
%STGM_RECURSIVE  = &H01000000???
%STGM_STRICTOPEN = &H40000000???


' ########################################################################################
' IService interface
' IID = 06210E88-01F5-11D1-B512-0080C781C384
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IService_INTERFACE_DEFINED)
    %IService_INTERFACE_DEFINED = 1

INTERFACE IService $IID_IService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InvokeService ( _                             ' VTable offset = 12
     BYVAL pUnkInner AS IUnknown _                      ' __in IUnknown *pUnkInner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IService_INTERFACE_DEFINED__ */


'typedef DWORD DBPROMPTOPTIONS;

' DBPROMPTOPTIONSENUM
%DBPROMPTOPTIONS_NONE                       = 0
%DBPROMPTOPTIONS_WIZARDSHEET                = &H1
%DBPROMPTOPTIONS_PROPERTYSHEET              = &H2
%DBPROMPTOPTIONS_BROWSEONLY                 = &H8
%DBPROMPTOPTIONS_DISABLE_PROVIDER_SELECTION = &H10
%DBPROMPTOPTIONS_DISABLESAVEPASSWORD        = &H20

#IF NOT %DEF(%IDBPromptInitialize_INTERFACE_DEFINED)
%IDBPromptInitialize_INTERFACE_DEFINED = 1

' ########################################################################################
' IDBPromptInitialize interface
' IID = 2206CCB0-19C1-11D1-89E0-00C04FD7A829
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDBPromptInitialize $IID_IDBPromptInitialize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PromptDataSource ( _                          ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYVAL dwPromptOptions AS DWORD _                   ' __in DBPROMPTOPTIONS dwPromptOptions
   , BYVAL cSourceTypeFilter AS DWORD _                 ' __in ULONG cSourceTypeFilter
   , BYVAL rgSourceTypeFilter AS DWORD _                ' __in DBSOURCETYPE *rgSourceTypeFilter
   , BYREF pwszszzProviderFilter AS WSTRINGZ _          ' __in LPCOLESTR pwszszzProviderFilter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDataSource AS IUnknown _                   ' __in_out IUnknown **ppDataSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PromptFileName ( _                            ' VTable offset = 16
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYVAL dwPromptOptions AS DWORD _                   ' __in DBPROMPTOPTIONS dwPromptOptions
   , BYREF pwszInitialDirectory AS WSTRINGZ _           ' __in LPCOLESTR pwszInitialDirectory
   , BYREF pwszInitialFile AS WSTRINGZ _                ' __in LPCOLESTR pwszInitialFile
   , BYREF ppwszSelectedFile AS DWORD _                 ' __out LPOLESTR *ppwszSelectedFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBPromptInitialize_INTERFACE_DEFINED__ */


' ########################################################################################
' IDataInitialize interface
' IID = 2206CCB1-19C1-11D1-89E0-00C04FD7A829
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDataInitialize_INTERFACE_DEFINED)
%IDataInitialize_INTERFACE_DEFINED = 1

INTERFACE IDataInitialize $IID_IDataInitialize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDataSource ( _                             ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsCtx AS DWORD _                          ' __in DWORD dwClsCtx
   , BYREF pwszInitializationString AS WSTRINGZ _       ' __in LPCOLESTR pwszInitializationString
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDataSource AS IUnknown _                   ' __in_out IUnknown **ppDataSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInitializationString ( _                   ' VTable offset = 16
     BYVAL pDataSource AS IUnknown _                    ' __in IUnknown *pDataSource
   , BYVAL fIncludePassword AS LONG _                   ' __in boolean fIncludePassword
   , BYREF ppwszInitString AS DWORD _                   ' __out LPOLESTR *ppwszInitString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDBInstance ( _                          ' VTable offset = 20
     BYREF clsidProvider AS GUID _                      ' __in REFCLSID clsidProvider
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsCtx AS DWORD _                          ' __in DWORD dwClsCtx
   , BYREF pwszReserved AS WSTRINGZ _                   ' __in LPOLESTR pwszReserved
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDataSource AS IUnknown _                   ' __out IUnknown **ppDataSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDBInstanceEx ( _                        ' VTable offset = 24
     BYREF clsidProvider AS GUID _                      ' __in REFCLSID clsidProvider
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsCtx AS DWORD _                          ' __in DWORD dwClsCtx
   , BYREF pwszReserved AS WSTRINGZ _                   ' __in LPOLESTR pwszReserved
   , BYREF COSERVERINFO _                               ' __in COSERVERINFO *pServerInfo
   , BYVAL riid AS DWORD _                              ' __in ULONG cmq
   , BYREF rgmqResults AS MULTI_QI _                    ' __in_out MULTI_QI *rgmqResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadStringFromStorage ( _                     ' VTable offset = 28
     BYREF pwszFileName AS WSTRINGZ _                   ' __in LPCOLESTR pwszFileName
   , BYREF ppwszInitializationString AS DWORD _         ' __out LPOLESTR *ppwszInitializationString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteStringToStorage ( _                      ' VTable offset = 32
     BYREF pwszFileName AS WSTRINGZ _                   ' __in LPCOLESTR pwszFileName
   , BYREF ppwszInitializationString AS WSTRINGZ _      ' __in LPCOLESTR pwszInitializationString
   , BYVAL dwCreationDisposition AS DWORD _             ' __in DWORD dwCreationDisposition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataInitialize_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDataSourceLocator
' IID = {2206CCB2-19C1-11D1-89E0-00C04FD7A829}
' Microsoft OLE DB Service Component Automation Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDataSourceLocator_INTERFACE_DEFINED)
%IDataSourceLocator_INTERFACE_DEFINED = 1

INTERFACE IDataSourceLocator $IID_IDataSourceLocator

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET hWnd ( _                                ' VTable offset = 28
   ) AS LONG                                            ' retval_out long* phwndParent
   ' =====================================================================================
   PROPERTY SET hWnd ( _                                ' VTable offset = 32
     BYVAL phwndParent AS LONG _                        ' __in long phwndParent
   )                                                    ' void
   ' =====================================================================================
   METHOD PromptNew ( _                                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out ppADOConnection** IDispatch
   ' =====================================================================================
   METHOD PromptEdit ( _                                ' VTable offset = 40
     BYREF ppADOConnection AS IDispatch _               ' __in_out IDispatch* ppADOConnection
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbSuccess
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataSourceLocator_INTERFACE_DEFINED__ */
