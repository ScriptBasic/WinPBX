' ########################################################################################
' Microsoft Windows
' File: CmnQuery.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CMNQUERY_INC = 1

#INCLUDE ONCE "objidl.inc"

$IID_IQueryForm    = GUID$("{8CFCEE30-39BD-11D0-B8D1-00A024AB2DBB}")
$IID_IPersistQuery = GUID$("{1A3114B8-A62E-11D0-A6C5-00A0C906AF45}")
$CLSID_CommonQuery = GUID$("{83BC5EC0-6F2A-11D0-A1C4-00AA00C16E65}")
$IID_ICommonQuery  = GUID$("{AB50DEC0-6F1D-11D0-A1C4-00AA00C16E65}")

'#IF NOT %DEF(%GUID_DEFS_ONLY)

'//-----------------------------------------------------------------------------
'// IQueryForm
'//-----------------------------------------------------------------------------

'//
'// A query form object is registered under the query handlers CLSID,
'// a list is stored in the registry:
'//
'//  HKCR\CLSID\{CLSID query handler}\Forms
'//
'// For each form object there are server values which can be defined:
'//
'//  Flags           = flags for the form object:
'//                      QUERYFORM_CHANGESFORMLIST
'//                      QUERYFORM_CHANGESOPTFORMLIST
'//
'//  CLSID           = string containing the CLSID of the InProc server to invoke
'//                    to get the IQueryFormObject.
'//
'//  Forms           = a sub key containing the CLSIDs for the forms registered
'//                    by IQueryForm::AddForms (or modified by ::AddPages), if
'//                    the flags are 0, then we scan this list looking for a match
'//                    for the default form specified.
'//

%QUERYFORM_CHANGESFORMLIST       = &H000000001???
%QUERYFORM_CHANGESOPTFORMLIST    = &H000000002???


'//
'// Query Forms
'// ===========
'//  Query forms are registered and have query pages added to them, a form without
'//  pages is not displayed.  Each form has a unique CLSID to allow it to be
'//  selected by invoking the query dialog.
'//

%CQFF_NOGLOBALPAGES  = &H0000001???     ' // = 1 => doesn't have global pages added
%CQFF_ISOPTIONAL     = &H0000002???     ' // = 1 => form is hidden, unless optional forms requested

' // Size = 32 bytes
TYPE CQFORM DWORD
   cbStruct AS DWORD          ' DWORD
   dwFlags  AS DWORD          ' DWORD
   clsid    AS GUID           ' CLSID
   hIcon    AS DWORD          ' HICON
   pszTitle AS WSTRINGZ PTR   ' LPCWSTR
END TYPE


'//
'// Query Form Pages
'// ================
'//  When a query form has been registered the caller can then add pages to it,
'//  any form can have pages appended.
'//


'struct _cqpage;
'typedef struct _cqpage CQPAGE, * LPCQPAGE;
'typedef HRESULT (CALLBACK *LPCQADDPAGESPROC)(LPARAM lParam, REFCLSID clsidForm, LPCQPAGE pPage);
'typedef HRESULT (CALLBACK *LPCQPAGEPROC)(LPCQPAGE pPage, HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

' // Size = 32 bytes
TYPE CQPAGE DWORD
   cbStruct       AS DWORD   ' DWORD
   dwFlags        AS DWORD   ' DWORD
   pPageProc      AS DWORD   ' LPCQPAGEPROC
   hInstance      AS DWORD   ' HINSTANCE
   idPageName     AS LONG    ' INT
   idPageTemplate AS LONG    ' INT
   pDlgProc       AS DWORD   ' DLGPROC
   lParam         AS LONG    ' LPARAM
END TYPE

'FUNCTION CQADDPAGESPROC ( _
'   BYVAL LONG _                               ' LPARAM lParam
' , BYREF GUID _                               ' REFCLSID clsidForm
' , BYREF CQPAGE _                             ' LPCQPAGE pPage
' ) AS LONG                                    ' HRESULT

'FUNCTION CQPAGEPROC ( _
'   BYREF CQPAGE _                             ' LPCQPAGE pPage
' , BYVAL DWORD _                              ' HWND hwnd
' , BYVAL DWORD _                              ' UINT uMsg
' , BYVAL DWORD _                              ' WPARAM wParam
' , BYVAL LONG _                               ' LPARAM lParam
' ) AS LONG                                    ' HRESULT


' ########################################################################################
' Interface name = IQueryForm
' IID = 8CFCEE30-39BD-11D0-B8D1-00A024AB2DBB
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IQueryForm $IID_IQueryForm

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hkForm AS DWORD _                            ' __in HKEY hkForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddForms ( _                                  ' VTable offset = 16
     BYVAL pAddFormsProc AS DWORD _                     ' __in LPCQADDFORMSPROC pAddFormsProc
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPages ( _                                  ' VTable offset = 20
     BYVAL pAddPagesProc AS DWORD _                     ' __in LPCQADDPAGESPROC pAddPagesProc
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//
'// Messages for pages
'//

%CQPM_INITIALIZE             = &H00000001???
%CQPM_RELEASE                = &H00000002???
%CQPM_ENABLE                 = &H00000003??? ' // wParam = TRUE/FALSE (enable, disable), lParam = 0
%CQPM_GETPARAMETERS          = &H00000005??? ' // wParam = 0, lParam = -> receives the LocalAlloc
%CQPM_CLEARFORM              = &H00000006??? ' // wParam, lParam = 0
%CQPM_PERSIST                = &H00000007??? ' // wParam = fRead, lParam -> IPersistQuery
%CQPM_HELP                   = &H00000008??? ' // wParam = 0, lParam -> LPHELPINFO
%CQPM_SETDEFAULTPARAMETERS   = &H00000009??? ' // wParam = 0, lParam -> OPENQUERYWINDOW

%CQPM_HANDLERSPECIFIC        = &H10000000???


' ########################################################################################
' Interface name = IPersistQuery
' IID = 1A3114B8-A62E-11D0-A6C5-00A0C906AF45
' Inherited interface = IPersist
' ########################################################################################

INTERFACE IPersistQuery $IID_IPersistQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID* pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteString ( _                               ' VTable offset = 16
     BYREF pSection AS WSTRINGZ _                       ' __in LPCWSTR pSection
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPCWSTR pValueName
   , BYVAL pValue AS DWORD _                            ' __in LPCWSTR pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadString ( _                                ' VTable offset = 20
     BYREF pSection AS WSTRINGZ _                       ' __in LPCWSTR pSection
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPCWSTR pValueName
   , BYVAL pBuffer AS DWORD _                           ' __out LPCWSTR pBuffer
   , BYVAL cchBuffer AS LONG _                          ' __in INT cchBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteInt ( _                                  ' VTable offset = 24
     BYREF pSection AS WSTRINGZ _                       ' __in LPCWSTR pSection
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPCWSTR pValueName
   , BYVAL value AS LONG _                              ' __in INT     value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadInt ( _                                   ' VTable offset = 24
     BYREF pSection AS WSTRINGZ _                       ' __in LPCWSTR pSection
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPCWSTR pValueName
   , BYREF pValue AS LONG _                             ' __in LPINT   pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteStruct ( _                               ' VTable offset = 28
     BYREF pSection AS WSTRINGZ _                       ' __in LPCWSTR pSection
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPCWSTR pValueName
   , BYVAL pStruct AS DWORD _                           ' __in LPVOID pStruct
   , BYVAL cbStruct AS DWORD _                          ' __in DWORD cbStruct
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadStruct ( _                                ' VTable offset = 32
     BYREF pSection AS WSTRINGZ _                       ' __in LPCWSTR pSection
   , BYREF pValueName AS WSTRINGZ _                     ' __in LPCWSTR pValueName
   , BYVAL pStruct AS DWORD _                           ' __in LPVOID pStruct
   , BYVAL cbStruct AS DWORD _                          ' __in DWORD cbStruct
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//-----------------------------------------------------------------------------
'// ICommonQuery
'//-----------------------------------------------------------------------------

%OQWF_OKCANCEL               = &H00000001???   ' // = 1 => Provide OK/Cancel buttons
%OQWF_DEFAULTFORM            = &H00000002???   ' // = 1 => clsidDefaultQueryForm is valid
%OQWF_SINGLESELECT           = &H00000004???   ' // = 1 => view to have single selection (depends on viewer)
%OQWF_LOADQUERY              = &H00000008???   ' // = 1 => use the IPersistQuery to load the given query
%OQWF_REMOVESCOPES           = &H00000010???   ' // = 1 => remove scope picker from dialog
%OQWF_REMOVEFORMS            = &H00000020???   ' // = 1 => remove form picker from dialog
%OQWF_ISSUEONOPEN            = &H00000040???   ' // = 1 => issue query on opening the dialog
%OQWF_SHOWOPTIONAL           = &H00000080???   ' // = 1 => list optional forms by default
%OQWF_SAVEQUERYONOK          = &H00000200???   ' // = 1 => use the IPersistQuery to write the query on close
%OQWF_HIDEMENUS              = &H00000400???   ' // = 1 => no menu bar displayed
%OQWF_HIDESEARCHUI           = &H00000800???   ' // = 1 => dialog is filter, therefore start, stop, new search etc

%OQWF_PARAMISPROPERTYBAG     = &H80000000???   ' // = 1 => the form parameters ptr is an IPropertyBag (ppbFormParameters)

UNION OPENQUERYWINDOW_UNION DWORD
   pFormParameters    AS DWORD       ' void*
   ppbFormParameters  AS DWORD PTR   ' IPropertyBag*
END UNION

' // Size = 52 bytes
TYPE OPENQUERYWINDOW DWORD
   cbStruct           AS DWORD       ' DWORD  // structure size
   dwFlags            AS DWORD       ' DWORD  // flags (OQFW_*)
   clsidHandler       AS GUID        ' CLSID  // clsid of handler we are using
   pHandlerParameters AS DWORD       ' LPVOID // handler specific structure for initialization
   clsidDefaultForm   AS GUID        ' CLSID  // default form to be selected (if OQF_DEFAULTFORM == 1 )
   pPersistQuery      AS DWORD PTR   ' IPersistQuery* // IPersistQuery used for loading queries
   OPENQUERYWINDOW_UNION
END TYPE


' ########################################################################################
' Interface name = ICommonQuery
' IID = AB50DEC0-6F1D-11D0-A1C4-00AA00C16E65
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ICommonQuery $IID_ICommonQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OpenQueryWindow ( _                           ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pQueryWnd AS OPENQUERYWINDOW _               ' __out LPOPENQUERYWINDOW pQueryWnd
   , BYREF ppDataObject AS IDataObject _                ' __out IDataObject** ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'#ENDIF   ' #IF NOT %DEF(%GUID_DEFS_ONLY)
