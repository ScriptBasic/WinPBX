' ########################################################################################
' Microsoft Windows
' File: DSClient.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSCLIENT_INC = 1

'//---------------------------------------------------------------------------//
'// CLSIDs exposed for the dsclient.
'//---------------------------------------------------------------------------//

'// this CLSID is used to signal that the DSOBJECTNAMEs structure originated
'// for the Microsoft DS.

$CLSID_MicrosoftDS         = GUID$("{FE1290F0-CFBD-11CF-A330-00AA00C16E65}")
$CLSID_DsFolder            = $CLSID_MicrosoftDS

'// this is the CLSID used by clients to get the IShellExtInit, IPropSheetExt
'// and IContextMenus exposed from dsuiext.dll.

$CLSID_DsPropertyPages     = GUID$("{0D45D530-764B-11D0-A1CA-00AA00C16E65}")
$CLSID_DsDomainTreeBrowser = GUID$("{1698790A-E2B4-11D0-B0B1-00C04FD8DCA6}")
$IID_IDsBrowseDomainTree   = GUID$("{7CABCF1E-78F5-11D2-960C-00C04FA31A86}")
$CLSID_DsDisplaySpecifier  = GUID$("{1AB4A8C0-6A0B-11D2-AD49-00C04FA31A86}")
$IID_IDsDisplaySpecifier   = $CLSID_DsDisplaySpecifier
$CLSID_DsFolderProperties  = GUID$("{9E51E0D0-6E0F-11D2-9601-00C04FA31A86}")

#INCLUDE ONCE "activeds.inc"

'//---------------------------------------------------------------------------//
'// Clipboard formats used within DSUI
'//---------------------------------------------------------------------------//

'//
'// CF_DSOBJECTS
'// ------------
'//  This clipboard format defines the seleciton for an DS IShellFolder to the
'//  shell extensions.   All strings are stored as BSTR's, and an offset == 0
'//  is used to indicate that the string is not present.
'//

%DSOBJECT_ISCONTAINER            = &H00000001???  ' // = 1 => object is a container
%DSOBJECT_READONLYPAGES          = &H80000000???  ' // = 1 => read only pages

%DSPROVIDER_UNUSED_0             = &H00000001???
%DSPROVIDER_UNUSED_1             = &H00000002???
%DSPROVIDER_UNUSED_2             = &H00000004???
%DSPROVIDER_UNUSED_3             = &H00000008???
%DSPROVIDER_ADVANCED             = &H00000010???  ' // = 1 => advanced mode
%DSPROVIDER_AD_LDS               = &H00000020???  ' // = 1 => talking to an AD LDS instance

'#define CFSTR_DSOBJECTNAMES TEXT("DsObjectNames")
$CFSTR_DSOBJECTNAMES = "DsObjectNames"

' // Size = 16 bytes
TYPE DSOBJECT DWORD
   dwFlags         AS DWORD   ' // item flags
   dwProviderFlags AS DWORD   ' // flags for item provider
   offsetName      AS DWORD   ' // offset to ADS path of the object
   offsetClass     AS DWORD   ' // offset to object class name / == 0 not known
END TYPE

' // Size = 36 bytes
TYPE DSOBJECTNAMES DWORD
   clsidNamespace AS GUID       ' CLSID // namespace identifier (indicates which namespace selection from)
   cItems         AS DWORD      ' UINT  // number of objects
   aObjects(0)    AS DSOBJECT   ' // array of objects
END TYPE


'//
'// CF_DSDISPLAYSPECOPTIONS
'// -----------------------
'//  When invoking an object referenced by a display specifier (context menu, property
'//  page, etc) we call the IShellExtInit interface passing a IDataObject.  This data
'//  object supports the CF_DSDISPLAYSPECOPTIONS format to give out configuration
'//  informaiton about admin/shell invocation.
'//
'//  When interacting with dsuiext.dll the interfaces uses this clipboard format
'//  to determine which display specifier attributes to address (admin/shell)
'//  and pick up the values accordingly.  If no format is suppoted then
'//  dsuiext.dll defaults to shell.
'//

'#define CFSTR_DS_DISPLAY_SPEC_OPTIONS TEXT("DsDisplaySpecOptions")
'#define CFSTR_DSDISPLAYSPECOPTIONS CFSTR_DS_DISPLAY_SPEC_OPTIONS

$CFSTR_DS_DISPLAY_SPEC_OPTIONS = "DsDisplaySpecOptions"
$CFSTR_DSDISPLAYSPECOPTIONS = $CFSTR_DS_DISPLAY_SPEC_OPTIONS

' // Size = 28 bytes
TYPE DSDISPLAYSPECOPTIONS DWORD
   dwSize                 AS DWORD   ' // size of struct, for versioning
   dwFlags                AS DWORD   ' // invocation flags
   offsetAttribPrefix     AS DWORD   ' // offset to attribute prefix string.
   offsetUserName         AS DWORD   ' // offset to UNICODE user name
   offsetPassword         AS DWORD   ' // offset to UNICODE password
   offsetServer           AS DWORD
   offsetServerConfigPath AS DWORD
END TYPE

'#define DS_PROP_SHELL_PREFIX L"shell"
'#define DS_PROP_ADMIN_PREFIX L"admin"

$DS_PROP_SHELL_PREFIX = "shell"
$DS_PROP_ADMIN_PREFIX = "admin"

%DSDSOF_HASUSERANDSERVERINFO     = &H00000001???      ' // = 1 => user name/password are valid
%DSDSOF_SIMPLEAUTHENTICATE       = &H00000002???      ' // = 1 => don't use secure authentication to DS
%DSDSOF_DONTSIGNSEAL             = &H00000004???      ' // = 1 => don't sign+seal when opening DS objects
%DSDSOF_DSAVAILABLE              = &H40000000???      ' // = 1 => ignore DS available checks

'//
'// CF_DSPROPERTYPAGEINFO
'// ---------------------
'//  When the property pages for an object are being displayed the parsed
'//  display specifier string is passed to the page object via the IDataObject
'//  in the following clipboard format.
'//
'//  Within the display specifier for a property page, the format for a
'//  Win32 extension is "n,{clsid}[,bla...]" we take the "bla" section and
'//  pass it down.
'//

'#define CFSTR_DSPROPERTYPAGEINFO TEXT("DsPropPageInfo")
$CFSTR_DSPROPERTYPAGEINFO = "DsPropPageInfo"

' // Size = 4 bytes
TYPE DSPROPERTYPAGEINFO DWORD
   offsetString AS DWORD   ' // offset to UNICODE string
END TYPE


'//
'// To sync property pages and the admin tools this message is broadcast
'//

'#define DSPROP_ATTRCHANGED_MSG  TEXT("DsPropAttrChanged")
$DSPROP_ATTRCHANGED_MSG = "DsPropAttrChanged"

'//---------------------------------------------------------------------------//


'//---------------------------------------------------------------------------//
'//
'// IDsBrowseDomainTree
'// ===================
'//  This interface returns a list of the domains from a given computer name
'//  (or the current computer name if none is specified).
'//
'//  NOTES:
'//    1) The structure returned by ::GetDomains should be free'd using
'//       FreeDomains.
'//
'//    2) ::BrowseTo allocates a string on exit, this is allocated using
'//       CoTaskMemAlloc, and therefore should be free'd using CoTaskMemFree.
'//
'//---------------------------------------------------------------------------//

%DBDTF_RETURNFQDN          = &H00000001???  ' // if not set, pszNCName will be blank
%DBDTF_RETURNMIXEDDOMAINS  = &H00000002???  ' // set it if you want downlevel trust domains too
%DBDTF_RETURNEXTERNAL      = &H00000004???  ' // set it if you want external trust domains too
%DBDTF_RETURNINBOUND       = &H00000008???  ' // set it if you want trusting domains
%DBDTF_RETURNINOUTBOUND    = &H00000010???  ' // set it if you want both trusted and trusting domains

' // Size = 36 bytes
TYPE DOMAINDESC DWORD
   pszName        AS WSTRINGZ PTR     ' LPWSTR // domain name (if no dns, use netbios)
   pszPath        AS WSTRINGZ PTR     ' LPWSTR // set to blank
   pszNCName      AS WSTRINGZ PTR     ' LPWSTR // FQDN, e.g.,DC=mydomain,DC=microsoft,DC=com
   pszTrustParent AS WSTRINGZ PTR     ' LPWSTR // parent domain name (if no dns, use netbios)
   pszObjectClass AS WSTRINGZ PTR     ' LPWSTR // Object class of the domain object referenced
   ulFlags        AS DWORD            ' ULONG  // Flags, from DS_TRUSTED_DOMAINS.Flags
   fDownLevel     AS LONG             ' BOOL   // == 1 if downlevel domain
   pdChildList    AS DOMAINDESC PTR   ' struct _DOMAINDESC * // Children of this node
   pdNextSibling  AS DOMAINDESC PTR   ' struct _DOMAINDESC * // Siblings of this node
END TYPE

MACRO DOMAIN_DESC = DOMAINDESC

' // Size = 44 bytes
TYPE DOMAINTREE DWORD
   dsSize      AS DWORD
   dwCount     AS DWORD
   aDomains(0) AS DOMAINDESC
END TYPE

MACRO DOMAIN_TREE = DOMAINTREE


' ########################################################################################
' Interface name = IDsBrowseDomainTree
' IID = 7CABCF1E-78F5-11D2-960C-00C04FA31A86
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDsBrowseDomainTree $IID_IDsBrowseDomainTree

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BrowseTo ( _                                  ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in  HWND hwndParent
   , BYREF ppszTargetPath AS DWORD _                    ' __out LPWSTR *ppszTargetPath
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDomains ( _                                ' VTable offset = 16
     BYREF ppDomainTree AS DOMAINTREE _                 ' __in_out PDOMAIN_TREE *ppDomainTree
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeDomains ( _                               ' VTable offset = 20
     BYREF ppDomainTree AS DOMAINTREE _                 ' __in PDOMAIN_TREE *ppDomainTree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlushCachedDomains ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetComputer ( _                               ' VTable offset = 28
     BYREF pszComputerName AS WSTRINGZ _                ' __in LPCWSTR pszComputerName
   , BYREF pszUserName AS WSTRINGZ _                    ' __in LPCWSTR pszUserName
   , BYREF pszPassword AS WSTRINGZ _                    ' __in LPCWSTR pszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//---------------------------------------------------------------------------//
'//
'// IDsDisplaySpecifier
'// ===================
'//  This interface gives client UI access to the display specifiers for
'//  specific attributes.
'//
'//---------------------------------------------------------------------------//

'//
'// IDsDisplaySpecifier::SetServer flags
'//
%DSSSF_SIMPLEAUTHENTICATE        = &H00000001???  ' // = 1 => don't use secure authentication to DS
%DSSSF_DONTSIGNSEAL              = &H00000002???  ' // = 1 => don't use sign+seal when opening objects in the DS
%DSSSF_DSAVAILABLE               = &H80000000???  ' // = 1 => ignore DS available checks

'//
'// Flags for IDsDisplaySpecifier::GetIcon / GetIconLocation
'//
%DSGIF_ISNORMAL                  = &H0000000???   ' // = icon is in normal state (default)
%DSGIF_ISOPEN                    = &H0000001???   ' // = icon is in open state
%DSGIF_ISDISABLED                = &H0000002???   ' // = icon is in a disabled state
%DSGIF_ISMASK                    = &H000000f???
%DSGIF_GETDEFAULTICON            = &H0000010???   ' // = 1 => if no icon then get default (from shell32.dll)
%DSGIF_DEFAULTISCONTAINER        = &H0000020???   ' // = 1 => if returning default icon, return it as a container

'//
'// Flags for IDsDisplaySpecifier::IsClassContainer
'//
%DSICCF_IGNORETREATASLEAF        = &H00000001???  ' // = 1 => igore the "treatAsLeaf" and use only schema information

'//
'// Callback function used for IDsDisplaySpecifier::EnumClassAttributes
'//

%DSECAF_NOTLISTED                = &H00000001???  ' // = 1 => hide from the field drop down in the query UI

'typedef HRESULT (CALLBACK *LPDSENUMATTRIBUTES)(LPARAM lParam, LPCWSTR pszAttributeName, LPCWSTR pszDisplayName, DWORD dwFlags);
'FUNCTION DSENUMATTRIBUTES ( _
'   BYVAL lParam AS LONG _                              ' LPARAM lParam
' , BYREF pszAttributeName AS WSTRINGZ _                ' LPCWSTR pszAttributeName
' , BYREF pszDisplayName AS WSTRINGZ _                  ' LPCWSTR pszDisplayName
' , BYVAL dwFlags AS DWORD _                            ' DWORD   dwFlags
' ) AS LONG                                             ' HRESULT

'//
'// IDsDisplaySpecifier::GetClassCreationInfo information
'//

%DSCCIF_HASWIZARDDIALOG          = &H00000001???  ' // = 1 => return the wizard dialog CLSID
%DSCCIF_HASWIZARDPRIMARYPAGE     = &H00000002???  ' // = 1 => returning a primary wizard dlg CLSID

' // Size = 56 bytes
TYPE DSCLASSCREATIONINFO DWORD
   dwFlags                AS DWORD
   clsidWizardDialog      AS GUID   ' CLSID
   clsidWizardPrimaryPage AS GUID   ' CLSID
   cWizardExtensions      AS DWORD   ' // how many extension CLSIDs?
   aWizardExtensions(0)   AS GUID   ' CLSID
END TYPE

'//
'// IDsDisplaySpecifier - a COM object for interacting with display specifiers
'//

' ########################################################################################
' Interface name = IDsDisplaySpecifier
' IID = 1AB4A8C0-6A0B-11D2-AD49-00C04FA31A86
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDsDisplaySpecifier $IID_IDsDisplaySpecifier

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetServer ( _                                 ' VTable offset = 12
     BYREF pszServer AS WSTRINGZ _                      ' __in LPCWSTR pszServer
   , BYREF pszUserName AS WSTRINGZ _                    ' __in LPCWSTR pszUserName
   , BYREF pszPassword AS WSTRINGZ _                    ' __in LPCWSTR pszPassword
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD   dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguageID ( _                             ' VTable offset = 16
     BYVAL langid AS WORD _                             ' __in LANGID langid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplaySpecifier ( _                       ' VTable offset = 20
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in  LPCWSTR pszObjectClass
   , BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconLocation ( _                           ' VTable offset = 24
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in  LPCWSTR pszObjectClass
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD   dwFlags
   , BYREF pszBuffer AS WSTRINGZ _                      ' __in  LPWSTR pszBuffer
   , BYVAL cchBuffer AS LONG _                          ' __in  INT cchBuffer
   , BYREF presid AS LONG _                             ' __out INT *presid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIcon ( _                                   ' VTable offset = 28
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in LPCWSTR pszObjectClass
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD   dwFlags
   , BYVAL cxIcon AS LONG _                             ' __in INT     cxIcon
   , BYVAL cyIcon AS LONG _                             ' __in INT     cyIcon
   ) AS DWORD                                           ' HICON
   ' =====================================================================================
   METHOD GetFriendlyClassName ( _                      ' VTable offset = 28
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in LPCWSTR pszObjectClass
   , BYREF pszBuffer AS WSTRINGZ _                      ' __in_out LPWSTR pszBuffer
   , BYVAL cchBuffer AS LONG _                          ' __in INT cchBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyAttributeName ( _                  ' VTable offset = 32
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in LPCWSTR pszObjectClass
   , BYREF pszAttributeName AS WSTRINGZ _               ' __in LPCWSTR pszAttributeName
   , BYREF pszBuffer AS WSTRINGZ _                      ' __in_out LPWSTR pszBuffer
   , BYVAL cchBuffer AS DWORD _                         ' __in UINT cchBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsClassContainer ( _                          ' VTable offset = 36
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in LPCWSTR pszObjectClass
   , BYREF pszADsPath AS WSTRINGZ _                     ' __in LPCWSTR pszADsPath
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD   dwFlags
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetClassCreationInfo ( _                      ' VTable offset = 40
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in LPCWSTR pszObjectClass
   , BYREF ppdscci AS DSCLASSCREATIONINFO _             ' __in_out LPDSCLASSCREATIONINFO* ppdscci
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD EnumClassAttributes ( _                       ' VTable offset = 44
     BYREF pszObjectClass AS WSTRINGZ _                 ' __in LPCWSTR pszObjectClass
   , BYVAL pcbEnum AS DWORD _                           ' __in LPDSENUMATTRIBUTES pcbEnum
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeADsType ( _                       ' VTable offset = 48
     BYREF pszAttributeName AS WSTRINGZ _               ' __in LPCWSTR pszAttributeName
   ) AS LONG                                            ' ADSTYPE
   ' =====================================================================================

END INTERFACE


'//---------------------------------------------------------------------------//
'//
'// DsBrowseForContainer
'// --------------------
'//  Provides a container browser similar to the SHBrowseForFolder, except
'//  targetting the DS.
'//
'// In:
'//  pInfo -> DSBROWSEINFO structure
'//
'// Out:
'//  == IDOK/IDCANCEL depending on buttons, -1 if error
'//
'//---------------------------------------------------------------------------//

' // Size = 60 bytes
TYPE DSBROWSEINFOW DWORD
   cbStruct       AS DWORD           ' DWORD  // size of structure in bytes
   hwndOwner      AS DWORD           ' HWND   // dialog owner
   pszCaption     AS WSTRINGZ PTR    ' LPCWSTR // dialog caption text (can be NULL)
   pszTitle       AS WSTRINGZ PTR    ' LPCWSTR // displayed above the tree view control (can be NULL)
   pszRoot        AS WSTRINGZ PTR    ' LPCWSTR // ADS path to root (NULL == root of DS namespace)
   pszPath        AS WSTRINGZ PTR    ' LPCWSTR // [in/out] initial selection & returned path (required)
   cchPath        AS DWORD           ' ULONG   // size of pszPath buffer in characters
   dwFlags        AS DWORD           ' DWORD
   pfnCallback    AS DWORD           ' BFFCALLBACK // callback function (see SHBrowseForFolder)
   lParam         AS LONG            ' LPARAM // passed to pfnCallback as lpUserData
   dwReturnFormat AS DWORD           ' DWORD  // ADS_FORMAT_* (default is ADS_FORMAT_X500_NO_SERVER)
   pUserName      AS WSTRINGZ PTR    ' LPCWSTR // Username and Password to authenticate against DS with
   pPassword      AS WSTRINGZ PTR    ' LPCWSTR
   pszObjectClass AS WSTRINGZ PTR    ' LPWSTR // UNICODE string for the object class
   cchObjectClass AS DWORD           ' ULONG
END TYPE

' // Size = 60 bytes
TYPE DSBROWSEINFOA DWORD
   cbStruct       AS DWORD           ' DWORD  // size of structure in bytes
   hwndOwner      AS DWORD           ' HWND   // dialog owner
   pszCaption     AS ASCIIZ PTR      ' LPCSTR // dialog caption text (can be NULL)
   pszTitle       AS ASCIIZ PTR      ' LPCSTR // displayed above the tree view control (can be NULL)
   pszRoot        AS WSTRINGZ PTR    ' LPCWSTR // ADS path to root (NULL == root of DS namespace)
   pszPath        AS WSTRINGZ PTR    ' LPCWSTR // [in/out] initial selection & returned path (required)
   cchPath        AS DWORD           ' ULONG   // size of pszPath buffer in characters
   dwFlags        AS DWORD           ' DWORD
   pfnCallback    AS DWORD           ' BFFCALLBACK // callback function (see SHBrowseForFolder)
   lParam         AS LONG            ' LPARAM // passed to pfnCallback as lpUserData
   dwReturnFormat AS DWORD           ' DWORD  // ADS_FORMAT_* (default is ADS_FORMAT_X500_NO_SERVER)
   pUserName      AS WSTRINGZ PTR    ' LPCWSTR // Username and Password to authenticate against DS with
   pPassword      AS WSTRINGZ PTR    ' LPCWSTR
   pszObjectClass AS WSTRINGZ PTR    ' LPWSTR // UNICODE string for the object class
   cchObjectClass AS DWORD           ' ULONG
END TYPE

#IF %DEF(%UNICODE)
   MACRO DSBROWSEINFO = DSBROWSEINFOW
#ELSE
   MACRO DSBROWSEINFO = DSBROWSEINFOA
#ENDIF

'// DSBROWSEINFO flags
%DSBI_NOBUTTONS          = &H00000001???  ' // NOT TVS_HASBUTTONS
%DSBI_NOLINES            = &H00000002???  ' // NOT TVS_HASLINES
%DSBI_NOLINESATROOT      = &H00000004???  ' // NOT TVS_LINESATROOT
%DSBI_CHECKBOXES         = &H00000100???  ' // TVS_CHECKBOXES
%DSBI_NOROOT             = &H00010000???  ' // don't include pszRoot in tree (its children become top level nodes)
%DSBI_INCLUDEHIDDEN      = &H00020000???  ' // display hidden objects
%DSBI_EXPANDONOPEN       = &H00040000???  ' // expand to the path specified in pszPath when opening the dialog
%DSBI_ENTIREDIRECTORY    = &H00090000???  ' // browse the entire directory (defaults to having DSBI_NOROOT set)
%DSBI_RETURN_FORMAT      = &H00100000???  ' // dwReturnFormat field is valid
%DSBI_HASCREDENTIALS     = &H00200000???  ' // pUserName & pPassword are valid
%DSBI_IGNORETREATASLEAF  = &H00400000???  ' // ignore the treat as leaf flag when calling IsClassContainer
%DSBI_SIMPLEAUTHENTICATE = &H00800000???  ' // don't use secure authentication to DS
%DSBI_RETURNOBJECTCLASS  = &H01000000???  ' // return object class of selected object
%DSBI_DONTSIGNSEAL       = &H02000000???  ' // don't sign+seal communication with DS

%DSB_MAX_DISPLAYNAME_CHARS = 64

' // Size = 676 bytes
TYPE DSBITEMW DWORD
   cbStruct       AS DWORD                                   ' DWORD
   pszADsPath     AS WSTRINGZ PTR                            ' LPCWSTR // ADS paths are always Unicode
   pszClass       AS WSTRINGZ PTR                            ' LPCWSTR // ADS properties are always Unicode
   dwMask         AS DWORD                                   ' DWORD
   dwState        AS DWORD                                   ' DWORD
   dwStateMask    AS DWORD                                   ' DWORD
   szDisplayName  AS WSTRINGZ * %DSB_MAX_DISPLAYNAME_CHARS   ' WCHAR
   szIconLocation AS WSTRINGZ * %MAX_PATH                    ' WCHAR
   iIconResID     AS LONG                                    ' INT
END TYPE

' // Size = 352 bytes
TYPE DSBITEMA DWORD
   cbStruct       AS DWORD                                 ' DWORD
   pszADsPath     AS WSTRINGZ PTR                          ' LPCWSTR // ADS paths are always Unicode
   pszClass       AS WSTRINGZ PTR                          ' LPCWSTR // ADS properties are always Unicode
   dwMask         AS DWORD                                 ' DWORD
   dwState        AS DWORD                                 ' DWORD
   dwStateMask    AS DWORD                                 ' DWORD
   szDisplayName  AS ASCIIZ * %DSB_MAX_DISPLAYNAME_CHARS   ' CHAR
   szIconLocation AS ASCIIZ * %MAX_PATH                    ' CHAR
   iIconResID     AS LONG                                  ' INT
END TYPE

#IF %DEF(%UNICODE)
   MACRO DSBITEM = DSBITEMW
#ELSE
   MACRO DSBITEM = DSBITEMA
#ENDIF

'// DSBITEM mask flags
%DSBF_STATE              = &H00000001???
%DSBF_ICONLOCATION       = &H00000002???
%DSBF_DISPLAYNAME        = &H00000004???

'// DSBITEM state flags
%DSBS_CHECKED            = &H00000001???
%DSBS_HIDDEN             = &H00000002???
%DSBS_ROOT               = &H00000004???

'//
'// this message is sent to the callback to see if it wants to insert or modify
'// the item that is about to be inserted into the view.
'//

%DSBM_QUERYINSERTW       = 100  ' // lParam = PDSBITEMW (state, icon & name may be modified). Return TRUE if handled.
%DSBM_QUERYINSERTA       = 101  ' // lParam = PDSBITEMA (state, icon & name may be modified). Return TRUE if handled.

'//
'// Called before we change the state of the icon (on tree collapse/expand)
'//

%DSBM_CHANGEIMAGESTATE   = 102  ' // lParam = adspath.  Return TRUE/FALSE top allow/disallow

'//
'// The dialog receives a WM_HELP
'//

%DSBM_HELP               = 103  ' // lParam == LPHELPINFO structure

'//
'// The dialog receives a WM_CONTEXTMENU, DSBID_xxx are the control ID's for this
'// dialog so that you can display suitable help.
'//

%DSBM_CONTEXTMENU        = 104  ' // lParam == window handle to retrieve help for


'//
'// These are the control IDs for the controls in the dialog.   The callback can use
'// these to modify the contents of the dialog as required.
'//

%DSBID_BANNER            = 256
%DSBID_CONTAINERLIST     = 257

'//
'// API exported for browsing for containers.
'//

DECLARE FUNCTION DsBrowseForContainerW IMPORT "DSUIEXT.DLL" ALIAS "DsBrowseForContainerW" ( _
   BYREF pInfo AS DSBROWSEINFOW _                       ' __in PDSBROWSEINFOW pInfo
 ) AS LONG                                              ' int

DECLARE FUNCTION DsBrowseForContainerA IMPORT "DSUIEXT.DLL" ALIAS "DsBrowseForContainerA" ( _
   BYREF pInfo AS DSBROWSEINFOA _                       ' __in PDSBROWSEINFOA pInfo
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO DsBrowseForContainer = DsBrowseForContainerW
#ELSE
   MACRO DsBrowseForContainer = DsBrowseForContainerA
#ENDIF

'// NOTE: these are here to keep old clients building - remove soon

DECLARE FUNCTION DsGetIcon IMPORT "DSUIEXT.DLL" ALIAS "DsGetIcon" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszObjectClass AS WSTRINGZ _                   ' __in LPWSTR pszObjectClass
 , BYVAL cxImage AS LONG _                              ' __in INT cxImage
 , BYVAL cyImage AS LONG _                              ' __in INT cyImage
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION DsGetFriendlyClassName IMPORT "DSUIEXT.DLL" ALIAS "DsGetFriendlyClassName" ( _
   BYREF pszObjectClass AS WSTRINGZ _                   ' __in LPWSTR pszObjectClass
 , BYREF pszBuffer AS WSTRINGZ _                        ' __in_out LPWSTR pszBuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in UINT cchBuffer
 ) AS LONG                                              ' HRESULT
