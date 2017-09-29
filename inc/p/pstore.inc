' ########################################################################################
' Microsoft Windows
' File: pstore.inc
' Contents: Protected Storage COM interface and associated data structures.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PSTORE_INC = 1

'/*
'    Typedefs, values
'*/

'// provider flags

'// provider capabilities
'typedef DWORD PST_PROVIDERCAPABILITIES;

%PST_PC_PFX                   = &H00000001???
%PST_PC_HARDWARE              = &H00000002???
%PST_PC_SMARTCARD             = &H00000004???
%PST_PC_PCMCIA                = &H00000008???
%PST_PC_MULTIPLE_REPOSITORIES = &H00000010???
%PST_PC_ROAMABLE              = &H00000020???


'// NYI (not yet implemented)
'typedef DWORD PST_REPOSITORYCAPABILITIES;

%PST_RC_REMOVABLE        = &H80000000???


'// provider storage area
'typedef DWORD PST_KEY;

%PST_KEY_CURRENT_USER    = &H00000000???
%PST_KEY_LOCAL_MACHINE   = &H00000001???



'/*
'    dwDefaultConfirmationStyle flags
'*/

'//
'// allows user to choose confirmation style
'//
%PST_CF_DEFAULT              = &H00000000???

'//
'// forces silent item creation
'//
%PST_CF_NONE                 = &H00000001???



'/*
'    dwPromptFlags
'*/

'//
'// app forces confirmation to be shown
'//
%PST_PF_ALWAYS_SHOW          = &H00000001???


'//
'// RSABase rqmt: determine if item has ui attached
'//
%PST_PF_NEVER_SHOW           = &H00000002???

'/*
'    dwFlags values
'*/

'//
'// Allows caller to specify creation not overwrite
'// of item during WriteItem call
'//
%PST_NO_OVERWRITE            = &H00000002???

'//
'// specifies insecure data stream to be written/read
'// there is no protection or guarantees for this data
'// flag only valid during item read/write calls
'// default: item calls are secure
'//
%PST_UNRESTRICTED_ITEMDATA   = &H00000004???


'//
'// on ReadItem call
'// return value on success without UI on item is PST_E_OK
'// return value on success with UI on item is PST_E_ITEM_EXISTS
'// return value on failure is a different error code
'//
%PST_PROMPT_QUERY            = &H00000008???

'//
'// on ReadItem, DeleteItem, for data migration purposes:
'// Avoid displaying UI on ReadItem unless a custom password is required (highsecurity).
'// Avoid displaying UI on DeleteItem, period.
'//
%PST_NO_UI_MIGRATION         = &H00000010???



'/*
'    Security masks, rule modifiers
'*/

'//
'// models access after NT access mask
'//

'// read, write
'typedef DWORD PST_ACCESSMODE;

%PST_READ                = &H0001???
%PST_WRITE               = &H0002???


'// PST_ACCESSCLAUSETYPE

'// memhash, diskhash, authenticode, etc
'typedef DWORD PST_ACCESSCLAUSETYPE;

'//
'// pbClauseData points to PST_AUTHENTICODEDATA structure.
'//
%PST_AUTHENTICODE            = 1???

'//
'// pbClauseData points to PST_BINARYCHECKDATA structure.
'//
%PST_BINARY_CHECK            = 2???

'//
'// pbClauseData points to valid Windows NT security descriptor.
'// note that performance is improved on Set operations if the security
'// descriptor is in self-relative format, with valid owner and group Sids
'// (non-NULL).
'//
%PST_SECURITY_DESCRIPTOR     = 4???

'//
'// pbClauseData is in self-relative format
'// (for internal use only)
'//
%PST_SELF_RELATIVE_CLAUSE    = &H80000000???

'//
'// currently access clause modifiers - NOT to be or'd together
'//


'//
'// specified image is the immediate caller, and is an application (.exe)
'//

%PST_AC_SINGLE_CALLER        = 0???

'//
'// specified image is not necessary the immediate caller, and is an
'// application (.exe)
'//

%PST_AC_TOP_LEVEL_CALLER    = 1???

'//
'// specified image is the immediate caller.  May be
'// an application (.exe) or a .dll
'//

%PST_AC_IMMEDIATE_CALLER    = 2???


'/*
'    Provider Parameters
'*/
'//
'// flush the internal cache of passwords -- temporary?
'//
%PST_PP_FLUSH_PW_CACHE       = &H1???




'/*
'    Provider Defns
'*/

'//
'// Microsoft Base Provider (MS_BASE_PSTPROVIDER...)
'//
$$MS_BASE_PSTPROVIDER_NAME           = "System Protected Storage"$$

'// {8A078C30-3755-11d0-A0BD-00AA0061426A}
$MS_BASE_PSTPROVIDER_ID              = GUID$("{8A078C30-3755-11d0-A0BD-00AA0061426A}")
$$MS_BASE_PSTPROVIDER_SZID           = "8A078C30-3755-11d0-A0BD-00AA0061426A"$$

'//
'// Microsoft PFX Provider (MS_PFX_PSTPROVIDER...)
'//
$$MS_PFX_PSTPROVIDER_NAME            = "PFX Storage Provider"$$

'// {3ca94f30-7ac1-11d0-8c42-00c04fc299eb}
$MS_PFX_PSTPROVIDER_ID               = GUID$("{3ca94f30-7ac1-11d0-8c42-00c04fc299eb}")
$$MS_PFX_PSTPROVIDER_SZID            = "3ca94f30-7ac1-11d0-8c42-00c04fc299eb"$$



'/*
'    Globally registered Type/Subtype guid/name pairs
'*/

$$PST_CONFIGDATA_TYPE_STRING             = "Configuration Data"$$
'// 8ec99652-8909-11d0-8c4d-00c04fc297eb
$PST_CONFIGDATA_TYPE_GUID                = GUID$("{8ec99652-8909-11d0-8c4d-00c04fc297eb}")

$$PST_PROTECTEDSTORAGE_SUBTYPE_STRING    = "Protected Storage"$$
'// d3121b8e-8a7d-11d0-8c4f-00c04fc297eb
$PST_PROTECTEDSTORAGE_SUBTYPE_GUID       = GUID$("{d3121b8e-8a7d-11d0-8c4f-00c04fc297eb}")

$$PST_PSTORE_PROVIDERS_SUBTYPE_STRING    = "Protected Storage Provider List"$$
'// 8ed17a64-91d0-11d0-8c43-00c04fc2c621
$PST_PSTORE_PROVIDERS_SUBTYPE_GUID       = GUID$("{8ed17a64-91d0-11d0-8c43-00c04fc2c621}")


'//
'// error codes
'//


#IF NOT %DEF(%PST_E_OK)
%PST_E_OK                        = &H00000000&

%PST_E_FAIL                      = &H800C0001&
%PST_E_PROV_DLL_NOT_FOUND        = &H800C0002&
%PST_E_INVALID_HANDLE            = &H800C0003&
%PST_E_TYPE_EXISTS               = &H800C0004&
%PST_E_TYPE_NO_EXISTS            = &H800C0005&
%PST_E_INVALID_RULESET           = &H800C0006&
%PST_E_NO_PERMISSIONS            = &H800C0007&
%PST_E_STORAGE_ERROR             = &H800C0008&
%PST_E_CALLER_NOT_VERIFIED       = &H800C0009&
%PST_E_WRONG_PASSWORD            = &H800C000A&
%PST_E_DISK_IMAGE_MISMATCH       = &H800C000B&
'// 000C pending
%PST_E_UNKNOWN_EXCEPTION         = &H800C000D&
%PST_E_BAD_FLAGS                 = &H800C000E&
%PST_E_ITEM_EXISTS               = &H800C000F&
%PST_E_ITEM_NO_EXISTS            = &H800C0010&
%PST_E_SERVICE_UNAVAILABLE       = &H800C0011&
%PST_E_NOTEMPTY                  = &H800C0012&
%PST_E_INVALID_STRING            = &H800C0013&
%PST_E_STATE_INVALID             = &H800C0014&
%PST_E_NOT_OPEN                  = &H800C0015&
%PST_E_ALREADY_OPEN              = &H800C0016&
%PST_E_NYI                       = &H800C0F00&


%MIN_PST_ERROR                   = &H800C0001&
%MAX_PST_ERROR                   = &H800C0F00&

#ENDIF   ' // !PST_OK



' /* header files for imported files */
#INCLUDE ONCE "wtypes.inc"

'/****************************************
' * Generated header for interface: __MIDL__intf_0000
' * at Wed Apr 23 23:56:10 1997
' * using MIDL 3.00.44
' ****************************************/

'typedef DWORD PST_PROVIDERCAPABILITIES;
'typedef DWORD PST_REPOSITORYCAPABILITIES;
'typedef DWORD PST_KEY;
'typedef DWORD PST_ACCESSMODE;
'typedef DWORD PST_ACCESSCLAUSETYPE;
'typedef GUID UUID;
'typedef ULARGE_INTEGER PST_PROVIDER_HANDLE;
'typedef GUID PST_PROVIDERID;
'typedef PST_PROVIDERID __RPC_FAR *PPST_PROVIDERID;

' // Size = 28 bytes
TYPE PST_PROVIDERINFO DWORD
   cbSize         AS DWORD          ' DWORD
   ID             AS GUID           ' PST_PROVIDERID
   Capabilities   AS DWORD          ' PST_PROVIDERCAPABILITIES
   szProviderName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 8 bytes
TYPE PST_TYPEINFO DWORD
   cbSize        AS DWORD          ' DWORD
   szDisplayName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 16 bytes
TYPE PST_PROMPTINFO DWORD
   cbSize        AS DWORD          ' DWORD
   dwPromptFlags AS DWORD          ' DWORD
   hwndApp       AS DWORD          ' HWND
   szPrompt      AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 16 bytes
TYPE PST_ACCESSCLAUSE DWORD
   cbSize       AS DWORD   ' DWORD
   ClauseType   AS DWORD   ' PST_ACCESSCLAUSETYPE
   cbClauseData AS DWORD   ' DWORD
   pbClauseData AS DWORD   ' /* [size_is] */ VOID __RPC_FAR *
END TYPE

' // Size = 16 bytes
TYPE PST_ACCESSRULE DWORD
   cbSize          AS DWORD   ' DWORD
   AccessModeFlags AS DWORD   ' PST_ACCESSMODE
   cClauses        AS DWORD   ' DWORD
   rgClauses       AS DWORD   ' /* [size_is] */ PST_ACCESSCLAUSE __RPC_FAR *
END TYPE

' // Size = 12 bytes
TYPE PST_ACCESSRULESET DWORD
   cbSize  AS DWORD   ' DWORD
   cRules  AS DWORD   ' DWORD
   rgRules AS DWORD   ' /* [size_is] */ PST_ACCESSRULE __RPC_FAR *
END TYPE

' // Size = 24 bytes
TYPE PST_AUTHENTICODEDATA DWORD
   cbSize        AS DWORD          ' DWORD
   dwModifiers   AS DWORD          ' DWORD
   szRootCA      AS WSTRINGZ PTR   ' LPCWSTR
   szIssuer      AS WSTRINGZ PTR   ' LPCWSTR
   szPublisher   AS WSTRINGZ PTR   ' LPCWSTR
   szProgramName AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 12 bytes
TYPE PST_BINARYCHECKDATA DWORD
   cbSize      AS DWORD          ' DWORD
   dwModifiers AS DWORD          ' DWORD
   szFilePath  AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

#IF NOT %DEF(%PSTORECLib_LIBRARY_DEFINED)
   %PSTORECLib_LIBRARY_DEFINED = 1

$LIBID_PSTORECLib = GUID$("{5A6F1EBD-2DB1-11D0-8C39-00C04FD9126B}")
$CLSID_CPStore = GUID$("{5A6F1EC3-2DB1-11D0-8C39-00C04FD9126B}")
$CLSID_CEnumTypes = GUID$("{09BB61E7-31EC-11D0-8C39-00C04FD9126B}")
$CLSID_CEnumItems = GUID$("{09BB61E6-31EC-11D0-8C39-00C04FD9126B}")

#ENDIF   ' /* __PSTORECLib_LIBRARY_DEFINED__ */

' ########################################################################################
' IEnumPStoreItems interface
' IID = 5A6F1EC1-2DB1-11D0-8C39-00C04FD9126B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPStoreItems_INTERFACE_DEFINED)
    %IEnumPStoreItems_INTERFACE_DEFINED = 1

$IID_IEnumPStoreItems = GUID$("{5A6F1EC1-2DB1-11D0-8C39-00C04FD9126B}")

INTERFACE IEnumPStoreItems $IID_IEnumPStoreItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in DWORD celt
   , BYREF rgelt AS DWORD _                             ' __out LPWSTR *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out DWORD *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in DWORD celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumPStoreItems _                 ' __out IEnumPStoreItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPStoreItems_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumPStoreTypes interface
' IID = 789C1CBF-31EE-11D0-8C39-00C04FD9126B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPStoreTypes_INTERFACE_DEFINED)
   %IEnumPStoreTypes_INTERFACE_DEFINED = 1

$IID_IEnumPStoreTypes = GUID$("{789C1CBF-31EE-11D0-8C39-00C04FD9126B}")

INTERFACE IEnumPStoreTypes $IID_IEnumPStoreTypes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in DWORD celt
   , BYREF rgelt AS GUID _                              ' __out GUID *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out DWORD *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in DWORD celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumPStoreTypes _                 ' __out IEnumPStoreItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPStoreTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' IPStore interface
' IID = 5A6F1EC0-2DB1-11D0-8C39-00C04FD9126B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPStore_INTERFACE_DEFINED)
    %IPStore_INTERFACE_DEFINED = 1

$IID_IPStore = GUID$("{5A6F1EC0-2DB1-11D0-8C39-00C04FD9126B}")

INTERFACE IPStore $IID_IPStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF ppProperties AS PST_PROVIDERINFO _           ' __out PPST_PROVIDERINFO *ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProvParam ( _                              ' VTable offset = 16
     BYVAL dwParam AS DWORD _                           ' __in DWORD dwParam
   , BYREF pcbData AS DWORD _                           ' __out DWORD *pcbData
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProvParam ( _                              ' VTable offset = 20
     BYVAL dwParam AS DWORD _                           ' __in DWORD dwParam
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL pbData AS BYTE PTR _                         ' __in BYTE *pbData
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateType ( _                                ' VTable offset = 24
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF pInfo AS PST_TYPEINFO _                      ' __in PPST_TYPEINFO pInfo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfo ( _                               ' VTable offset = 28
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF ppInfo AS PST_TYPEINFO _                     ' __out PPST_TYPEINFO *ppInfo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteType ( _                                ' VTable offset = 32
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSubtype ( _                             ' VTable offset = 36
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF pSubtype AS GUID _                           ' __in const GUID *pSubtype
   , BYREF pInfo AS PST_TYPEINFO _                      ' __in PPST_TYPEINFO pInfo
   , BYREF pRules AS PST_ACCESSRULESET _                ' __in PPST_ACCESSRULESET pRules
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubtypeInfo ( _                            ' VTable offset = 40
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF pSubtype AS GUID _                           ' __in const GUID *pSubtype
   , BYREF ppInfo AS PST_TYPEINFO _                     ' __out PPST_TYPEINFO *ppInfo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteSubtype ( _                             ' VTable offset = 44
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF pSubtype AS GUID _                           ' __in const GUID *pSubtype
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadAccessRuleset ( _                         ' VTable offset = 48
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF pSubtype AS GUID _                           ' __in const GUID *pSubtype
   , BYREF ppRules AS PST_ACCESSRULESET _               ' __out PPST_ACCESSRULESET *ppRules
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteAccessRuleset ( _                        ' VTable offset = 52
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYREF pSubtype AS GUID _                           ' __in const GUID *pSubtype
   , BYREF pRules AS PST_ACCESSRULESET _                ' __in PPST_ACCESSRULESET pRules
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumTypes ( _                                 ' VTable offset = 56
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppenum AS IEnumPStoreTypes _                 ' __out IEnumPStoreTypes **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSubtypes ( _                              ' VTable offset = 60
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pType AS GUID _                              ' __in const GUID *pType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppenum AS IEnumPStoreTypes _                 ' __out IEnumPStoreTypes **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 64
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pItemType AS GUID _                          ' __in const GUID *pItemType
   , BYREF pItemSubtype AS GUID _                       ' __in const GUID *pItemSubtype
   , BYREF szItemName AS WSTRINGZ _                     ' __in LPCWSTR szItemName
   , BYREF pPromptInfo AS PST_PROMPTINFO _              ' __in PPST_PROMPTINFO pPromptInfo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadItem ( _                                  ' VTable offset = 68
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pItemType AS GUID _                          ' __in const GUID *pItemType
   , BYREF pItemSubtype AS GUID _                       ' __in const GUID *pItemSubtype
   , BYREF szItemName AS WSTRINGZ _                     ' __in LPCWSTR szItemName
   , BYREF pcbData AS DWORD _                           ' __out DWORD *pcbData
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pPromptInfo AS PST_PROMPTINFO _              ' __in PPST_PROMPTINFO pPromptInfo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteItem ( _                                 ' VTable offset = 72
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pItemType AS GUID _                          ' __in const GUID *pItemType
   , BYREF pItemSubtype AS GUID _                       ' __in const GUID *pItemSubtype
   , BYREF szItemName AS WSTRINGZ _                     ' __in LPCWSTR szItemName
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL pbData AS BYTE PTR _                         ' __in BYTE *pbData
   , BYREF pPromptInfo AS PST_PROMPTINFO _              ' __in PPST_PROMPTINFO pPromptInfo
   , BYVAL dwDefaultConfirmationStyle AS DWORD _        ' __in DWORD dwDefaultConfirmationStyle
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenItem ( _                                  ' VTable offset = 76
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pItemType AS GUID _                          ' __in const GUID *pItemType
   , BYREF pItemSubtype AS GUID _                       ' __in const GUID *pItemSubtype
   , BYREF szItemName AS WSTRINGZ _                     ' __in LPCWSTR szItemName
   , BYVAL ModeFlags AS DWORD _                         ' __in PST_ACCESSMODE ModeFlags
   , BYREF pPromptInfo AS PST_PROMPTINFO _              ' __in PPST_PROMPTINFO pPromptInfo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseItem ( _                                 ' VTable offset = 80
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pItemType AS GUID _                          ' __in const GUID *pItemType
   , BYREF pItemSubtype AS GUID _                       ' __in const GUID *pItemSubtype
   , BYREF szItemName AS WSTRINGZ _                     ' __in LPCWSTR szItemName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumItems ( _                                 ' VTable offset = 84
     BYVAL Key AS DWORD _                               ' __in PST_KEY Key
   , BYREF pItemType AS GUID _                          ' __in const GUID *pItemType
   , BYREF pItemSubtype AS GUID _                       ' __in const GUID *pItemSubtype
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppenum AS IEnumPStoreItems _                 ' __out IEnumPStoreItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPStore_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumPStoreProviders interface
' IID = 5A6F1EBF-2DB1-11D0-8C39-00C04FD9126B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPStoreProviders_INTERFACE_DEFINED)
    %IEnumPStoreProviders_INTERFACE_DEFINED = 1

$IID_IEnumPStoreProviders = GUID$("{5A6F1EBF-2DB1-11D0-8C39-00C04FD9126B}")

INTERFACE IEnumPStoreProviders $IID_IEnumPStoreProviders

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in DWORD celt
   , BYREF rgelt AS PST_PROVIDERINFO _                  ' __out PST_PROVIDERINFO *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out DWORD *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in DWORD celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumPStoreProviders _             ' __out IEnumPStoreItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPStoreProviders_INTERFACE_DEFINED__ */

'HRESULT __stdcall PStoreCreateInstance(
'    IPStore __RPC_FAR *__RPC_FAR *ppProvider,
'    PST_PROVIDERID __RPC_FAR *pProviderID,
'    void __RPC_FAR *pReserved,
'    DWORD dwFlags);

FUNCTION PStoreCreateInstance (BYREF ppProvider AS IPStore, BYREF pProviderID AS GUID, BYVAL pReserved AS DWORD, BYVAL dwFlags AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Pstorec.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "PStoreCreateInstance")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING PStoreCreateInstance(ppProvider, pProviderID, pReserved, dwFlags) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

'HRESULT __stdcall PStoreEnumProviders(
'    DWORD dwFlags,
'    IEnumPStoreProviders __RPC_FAR *__RPC_FAR *ppenum);

FUNCTION PStoreEnumProviders (BYVAL dwFlags AS DWORD, BYREF ppenum AS IEnumPStoreProviders) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Pstorec.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "PStoreEnumProviders")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING PStoreEnumProviders(dwFlags, ppenum) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION
