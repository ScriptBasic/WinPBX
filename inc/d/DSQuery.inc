' ########################################################################################
' Microsoft Windows
' File: DSQuery.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSQUERY_INC = 1

#INCLUDE ONCE "CmnQuery.inc"

' //
' // query handler ID for dsquery.
' //

$CLSID_DsQuery                = GUID$("{8A23E65E-31C2-11D0-891C-00A024AB2DBB}")

' //
' // standard forms shipped in dsquery.dll
' //

$CLSID_DsFindObjects          = GUID$("{83EE3FE1-57D9-11D0-B932-00A024AB2DBB}")
$CLSID_DsFindPeople           = GUID$("{83EE3FE2-57D9-11D0-B932-00A024AB2DBB}")
$CLSID_DsFindPrinter          = GUID$("{B577F070-7EE2-11D0-913F-00AA00C16E65}")
$CLSID_DsFindComputer         = GUID$("{16006700-87AD-11D0-9140-00AA00C16E65}")
$CLSID_DsFindVolume           = GUID$("{C1B3CBF1-886A-11D0-9140-00AA00C16E65}")
$CLSID_DsFindContainer        = GUID$("{C1B3CBF2-886A-11D0-9140-00AA00C16E65}")
$CLSID_DsFindAdvanced         = GUID$("{83EE3FE3-57D9-11D0-B932-00A024AB2DBB}")

' //
' // admin forms
' //

$CLSID_DsFindDomainController = GUID$("{538C7B7E-D25E-11D0-9742-00A0C906AF45}")
$CLSID_DsFindWriteableDomainController = GUID$("{7CBEF079-AA84-444B-BC70-68E41283EABC}")
$CLSID_DsFindFrsMembers       = GUID$("{94CE4B18-B3D3-11D1-B9B4-00C04FD8D5B0}")

' //
' // DSQUERYINITPARAMS
' // -----------------
' //  This structure is used when creating a new query view.
' //

%DSQPF_NOSAVE                 = &H00000001???  ' // = 1 => remove save verb
%DSQPF_SAVELOCATION           = &H00000002???  ' // = 1 => pSaveLocation contains directory to save queries into
%DSQPF_SHOWHIDDENOBJECTS      = &H00000004???  ' // = 1 => show objects marked as "hidden" in results
%DSQPF_ENABLEADMINFEATURES    = &H00000008???  ' // = 1 => show admin verbs, property pages etc
%DSQPF_ENABLEADVANCEDFEATURES = &H00000010???  ' // = 1 => set the advanced flag for the property pages
%DSQPF_HASCREDENTIALS         = &H00000020???  ' // = 1 => pServer, pUserName & pPassword are valid
%DSQPF_NOCHOOSECOLUMNS        = &H00000040???  ' // = 1 => remove choose columns from view

' // Size = 28 bytes
TYPE DSQUERYINITPARAMS DWORD
   cbStruct             AS DWORD
   dwFlags              AS DWORD
   pDefaultScope        AS WSTRINGZ PTR   ' LPWSTR // -> Active Directory path to use as scope / == NULL for none
   pDefaultSaveLocation AS WSTRINGZ PTR   ' LPWSTR // -> Directory to save queries into / == NULL default location
   pUserName            AS WSTRINGZ PTR   ' LPWSTR // -> user name to authenticate with
   pPassword            AS WSTRINGZ PTR   ' LPWSTR // -> password for authentication
   pServer              AS WSTRINGZ PTR   ' LPWSTR // -> server to use for obtaining trusts etc
END TYPE


' //
' // DSQUERYPARAMS
' // -------------
' //  The DS query handle takes a packed structure which contains the
' //  columns and query to be issued.
' //

'#define CFSTR_DSQUERYPARAMS         TEXT("DsQueryParameters")
$$CFSTR_DSQUERYPARAMS         = "DsQueryParameters"$$

%DSCOLUMNPROP_ADSPATH        = -1   ' ((LONG)(-1))
%DSCOLUMNPROP_OBJECTCLASS    = -2   ' ((LONG)(-2))

' // Size = 24 bytes
TYPE DSCOLUMN DWORD
   dwFlags        AS DWORD   ' DWORD // flags for this column
   fmt            AS LONG    ' INT   // list view form information
   cx             AS LONG    ' INT   // default column width
   idsName        AS LONG    ' INT   // resource ID for the column dispaly name
   offsetProperty AS LONG    ' LONG  // offset to BSTR defining column ADs property name
   dwReserved     AS DWORD   ' DWORD // reserved field
END TYPE

' // Size = 48 bytes
TYPE DSQUERYPARAMS DWORD
   cbStruct    AS DWORD
   dwFlags     AS DWORD
   hInstance   AS DWORD      ' HINSTANCE // instance handle used for string extraction
   offsetQuery AS LONG       ' LONG      // offset to LDAP filter string
   iColumns    AS LONG       ' LONG      // column count
   dwReserved  AS DWORD      ' DWORD     // reserved field for this query
   aColumns(0) AS DSCOLUMN   ' DSCOLUMN  // array of column descriptions
END TYPE


' //
' // CF_DSQUERYSCOPE
' // ---------------
' //  A clipboard format the puts a string version of the scope into a
' //  storage medium via GlobalAlloc.
' //
'#define CFSTR_DSQUERYSCOPE         TEXT("DsQueryScope")
$$CFSTR_DSQUERYSCOPE         = "DsQueryScope"$$


' //
' // DSQPM_GETCLASSLIST
' // ------------------
' //  This page message is sent to the form pages to retrieve the list of classes
' //  that the pages are going to query from.  This is used by the feild selector
' //  and the property well to build its list of display classes.
' //

' // Size = 12 bytes
TYPE DSQUERYCLASSLIST DWORD
   cbStruct       AS DWORD
   cClasses       AS LONG    ' LONG  // number of classes in array
   offsetClass(0) AS DWORD   ' DWORD // offset to the class names (UNICODE)
END TYPE

%DSQPM_GETCLASSLIST          = (%CQPM_HANDLERSPECIFIC+0) ' // wParam == flags, lParam = LPLPDSQUERYCLASSLIST

' //
' // DSQPM_HELPTOPICS
' // ----------------
' //  This page message is sent to the form pages to allow them to handle the
' //  "Help Topics" verb.
' //

%DSQPM_HELPTOPICS            = (%CQPM_HANDLERSPECIFIC+1) ' // wParam = 0, lParam = hWnd parent
