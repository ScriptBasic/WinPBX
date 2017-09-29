' ########################################################################################
' Microsoft Windows
' File: CredentialProvider.inc
' Library name: CredentialProviders
' Version: 0.0, Locale ID = 0
' Library GUID: {D545DB01-E522-4A63-AF83-D8DDF954004F}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CREDENTIALPROVIDER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "shobjidl.inc"

$LIBID_CredentialProviders = GUID$("{D545DB01-E522-4A63-AF83-D8DDF954004F}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_GenericCredentialProvider = GUID$("{25CBB996-92ED-457E-B28C-4774084BD562}")
$CLSID_NPCredentialProvider = GUID$("{3DD6BEC0-8193-4FFE-AE25-E08E39EA4063}")
$CLSID_OnexCredentialProvider = GUID$("{07AA0886-CC8D-4E19-A410-1C75AF686E62}")
$CLSID_OnexPlapSmartcardCredentialProvider = GUID$("{33C86CD6-705F-4BA1-9ADB-67070B837775}")
$CLSID_PasswordCredentialProvider = GUID$("{6F45DC1E-5384-457A-BC13-2CD81B0D28ED}")
$CLSID_RASProvider = GUID$("{5537E283-B1E7-4EF8-9C6E-7AB0AFE5056D}")
$CLSID_SmartcardCredentialProvider = GUID$("{8BF9A910-A8FF-457F-999F-A5CA10B4A885}")
$CLSID_SmartcardPinProvider = GUID$("{94596C7E-3744-41CE-893E-BBF09122F76A}")
$CLSID_VaultProvider = GUID$("{503739D0-4C5E-4CFD-B3BA-D881334F0DF2}")
$CLSID_WinBioCredentialProvider = GUID$("{AC3AC249-E820-4343-A65B-377AC634DC09}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICredentialProvider = GUID$("{D27C3481-5A1C-45B2-8AAA-C20EBBE8229E}")
$IID_ICredentialProviderCredential = GUID$("{63913A93-40C1-481A-818D-4072FF8C70CC}")
$IID_ICredentialProviderCredentialEvents = GUID$("{FA6FA76B-66B7-4B11-95F1-86171118E816}")
$IID_ICredentialProviderEvents = GUID$("{34201E5A-A787-41A3-A5A4-BD6DCF2A854E}")

$IID_IQueryContinueWithStatus = GUID$("{9090be5b-502b-41fb-bccc-0049a6c7254b}")
$IID_IConnectableCredentialProviderCredential = GUID$("{9387928b-ac75-4bf9-8ab2-2b93c4a55290}")
$IID_ICredentialProviderFilter = GUID$("{a5da53f9-d475-4080-a120-910c4a739880}")

' ========================================================================================
' CREDENTIAL_PROVIDER_USAGE_SCENARIO enum
' ========================================================================================

%CPUS_INVALID            = 0
%CPUS_LOGON              = %CPUS_INVALID            + 1
%CPUS_UNLOCK_WORKSTATION = %CPUS_LOGON              + 1
%CPUS_CHANGE_PASSWORD    = %CPUS_UNLOCK_WORKSTATION + 1
%CPUS_CREDUI             = %CPUS_CHANGE_PASSWORD    + 1
%CPUS_PLAP               = %CPUS_CREDUI             + 1

' ========================================================================================
' CREDENTIAL_PROVIDER_FIELD_TYPE enum
' ========================================================================================

%CPFT_INVALID       = 0
%CPFT_LARGE_TEXT    = %CPFT_INVALID       + 1
%CPFT_SMALL_TEXT    = %CPFT_LARGE_TEXT    + 1
%CPFT_COMMAND_LINK  = %CPFT_SMALL_TEXT    + 1
%CPFT_EDIT_TEXT     = %CPFT_COMMAND_LINK  + 1
%CPFT_PASSWORD_TEXT = %CPFT_EDIT_TEXT     + 1
%CPFT_TILE_IMAGE    = %CPFT_PASSWORD_TEXT + 1
%CPFT_CHECKBOX      = %CPFT_TILE_IMAGE    + 1
%CPFT_COMBOBOX      = %CPFT_CHECKBOX      + 1
%CPFT_SUBMIT_BUTTON = %CPFT_COMBOBOX      + 1

' ========================================================================================
' CREDENTIAL_PROVIDER_FIELD_STATE enum
' ========================================================================================

%CPFS_HIDDEN                     = 0
%CPFS_DISPLAY_IN_SELECTED_TILE   = %CPFS_HIDDEN                     + 1
%CPFS_DISPLAY_IN_DESELECTED_TILE = %CPFS_DISPLAY_IN_SELECTED_TILE   + 1
%CPFS_DISPLAY_IN_BOTH            = %CPFS_DISPLAY_IN_DESELECTED_TILE + 1

' ========================================================================================
' CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE enum
' ========================================================================================

%CPFIS_NONE     = 0
%CPFIS_READONLY = %CPFIS_NONE     + 1
%CPFIS_DISABLED = %CPFIS_READONLY + 1
%CPFIS_FOCUSED  = %CPFIS_DISABLED + 1

' ========================================================================================
' CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR record
' ========================================================================================

' // Size = 28 bytes
TYPE CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR DWORD
   dwFieldID     AS DWORD          ' DWORD
   cpft          AS LONG           ' CREDENTIAL_PROVIDER_FIELD_TYPE
   pszLabel      AS WSTRINGZ PTR   ' LPWSTR
   guidFieldType AS GUID           ' GUID
END TYPE

' ========================================================================================
' CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE enum
' ========================================================================================

%CPGSR_NO_CREDENTIAL_NOT_FINISHED = 0
%CPGSR_NO_CREDENTIAL_FINISHED     = %CPGSR_NO_CREDENTIAL_NOT_FINISHED + 1
%CPGSR_RETURN_CREDENTIAL_FINISHED = %CPGSR_NO_CREDENTIAL_FINISHED     + 1

' ========================================================================================
' CREDENTIAL_PROVIDER_STATUS_ICON enum
' ========================================================================================

%CPSI_NONE    = 0
%CPSI_ERROR   = %CPSI_NONE    + 1
%CPSI_WARNING = %CPSI_ERROR   + 1
%CPSI_SUCCESS = %CPSI_WARNING + 1

' ========================================================================================
' CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION record
' ========================================================================================

' // Size = 28 bytes
TYPE CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION DWORD
   ulAuthenticationPackage AS DWORD      ' ULONG
   clsidCredentialProvider AS GUID       ' GUID
   cbSerialization         AS DWORD      ' ULONG
   rgbSerialization        AS BYTE PTR   ' byte *
END TYPE

'typedef LONG NTSTATUS;

%CREDENTIAL_PROVIDER_NO_DEFAULT = &HFFFFFFFF???   ' ((DWORD)-1)

' ########################################################################################
' Interface name = ICredentialProviderCredential
' IID = {63913A93-40C1-481A-818D-4072FF8C70CC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICredentialProviderCredential_INTERFACE_DEFINED)
    %ICredentialProviderCredential_INTERFACE_DEFINED = 1

INTERFACE ICredentialProviderCredential $IID_ICredentialProviderCredential

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL pcpce AS ICredentialProviderCredentialEvents _ ' __in *pcpce ICredentialProviderCredentialEvents <interface>
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnAdvise ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelected ( _                               ' VTable offset = 20
     BYREF pbAutoLogon AS LONG _                        ' __out BOOL *pbAutoLogon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeselected ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldState ( _                             ' VTable offset = 28
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pcpfs AS LONG _                              ' __out CREDENTIAL_PROVIDER_FIELD_STATE *pcpfs
   , BYREF pcpfis AS LONG _                             ' __out CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE *pcpfis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 32
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmapValue ( _                            ' VTable offset = 36
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF phbmp AS DWORD _                             ' __out HBITMAP *phbmp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCheckboxValue ( _                          ' VTable offset = 40
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pbChecked AS LONG _                          ' __out BOOLL *pbChecked
   , BYREF ppszLabel AS DWORD _                         ' __out LPWSTR *ppszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubmitButtonValue ( _                      ' VTable offset = 44
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pdwAdjacentTo AS DWORD _                     ' __out DWORD *pdwAdjacentTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComboBoxValueCount ( _                     ' VTable offset = 48
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pcItems AS DWORD _                           ' __out DWORD *pcItems
   , BYREF pdwSelectedItem AS DWORD _                   ' __out DWORD *pdwSelectedItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComboBoxValueAt ( _                        ' VTable offset = 52
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwItem AS DWORD _                            ' __in DWORD dwItem
   , BYREF ppszItem AS DWORD _                          ' __out LPWSTR *ppszItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 56
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF psz AS WSTRINGZ _                            ' __in LPWSTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckboxValue ( _                          ' VTable offset = 60
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL bChecked AS LONG _                           ' __in BOOL bChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetComboBoxSelectedValue ( _                  ' VTable offset = 64
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwSelectedItem AS DWORD _                    ' __in DWORD dwSelectedItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommandLinkClicked ( _                        ' VTable offset = 68
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerialization ( _                          ' VTable offset = 72
     BYREF pcpgsr AS LONG _                             ' __out CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE *pcpgsr
   , BYREF pcpcs AS CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION _ ' __out CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION *pcpcs
   , BYREF ppszOptionalStatusText AS DWORD _            ' __out LPWSTR *ppszOptionalStatusText
   , BYREF pcpsiOptionalStatusIcon AS LONG _            ' __out CREDENTIAL_PROVIDER_STATUS_ICON *pcpsiOptionalStatusIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportResult ( _                              ' VTable offset = 76
     BYVAL ntsStatus AS LONG _                          ' __in NTSTATUS ntsStatus
   , BYVAL ntsSubstatus AS LONG _                       ' __in NTSTATUS ntsSubstatus
   , BYREF ppszOptionalStatusText AS DWORD _            ' __out LPWSTR *ppszOptionalStatusText
   , BYREF pcpsiOptionalStatusIcon AS LONG _            ' __out CREDENTIAL_PROVIDER_STATUS_ICON *pcpsiOptionalStatusIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICredentialProviderCredential_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQueryContinueWithStatus
' IID = 9090be5b-502b-41fb-bccc-0049a6c7254b
' Inherited interface = IQueryContinue
' ########################################################################################

#IF NOT %DEF(%IQueryContinueWithStatus_INTERFACE_DEFINED)
    %IQueryContinueWithStatus_INTERFACE_DEFINED = 1

INTERFACE IQueryContinueWithStatus $IID_IQueryContinueWithStatus

   INHERIT IUnknown

   ' =====================================================================================
   ' IQueryContinue method
   ' =====================================================================================
   METHOD QueryContinue ( _                             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IQueryContinueWithStatus method
   ' =====================================================================================
   METHOD SetStatusMessage ( _                          ' VTable offset = 16
     BYREF psz AS WSTRINGZ _                            ' __in LPCWSTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryContinueWithStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IConnectableCredentialProviderCredential
' IID = {9387928b-ac75-4bf9-8ab2-2b93c4a55290}
' Inherited interface = ICredentialProviderCredential
' ########################################################################################

#IF NOT %DEF(%IConnectableCredentialProviderCredential_INTERFACE_DEFINED)
    %IConnectableCredentialProviderCredential_INTERFACE_DEFINED = 1

INTERFACE IConnectableCredentialProviderCredential $IID_IConnectableCredentialProviderCredential

   INHERIT IUnknown

   ' =====================================================================================
   ' ICredentialProviderCredential methods
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL pcpce AS ICredentialProviderCredentialEvents _ ' __in *pcpce ICredentialProviderCredentialEvents <interface>
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnAdvise ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelected ( _                               ' VTable offset = 20
     BYREF pbAutoLogon AS LONG _                        ' __out BOOL *pbAutoLogon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeselected ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldState ( _                             ' VTable offset = 28
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pcpfs AS LONG _                              ' __out CREDENTIAL_PROVIDER_FIELD_STATE *pcpfs
   , BYREF pcpfis AS LONG _                             ' __out CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE *pcpfis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 32
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmapValue ( _                            ' VTable offset = 36
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF phbmp AS DWORD _                             ' __out HBITMAP *phbmp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCheckboxValue ( _                          ' VTable offset = 40
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pbChecked AS LONG _                          ' __out BOOLL *pbChecked
   , BYREF ppszLabel AS DWORD _                         ' __out LPWSTR *ppszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubmitButtonValue ( _                      ' VTable offset = 44
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pdwAdjacentTo AS DWORD _                     ' __out DWORD *pdwAdjacentTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComboBoxValueCount ( _                     ' VTable offset = 48
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pcItems AS DWORD _                           ' __out DWORD *pcItems
   , BYREF pdwSelectedItem AS DWORD _                   ' __out DWORD *pdwSelectedItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComboBoxValueAt ( _                        ' VTable offset = 52
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwItem AS DWORD _                            ' __in DWORD dwItem
   , BYREF ppszItem AS DWORD _                          ' __out LPWSTR *ppszItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 56
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF psz AS WSTRINGZ _                            ' __in LPWSTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckboxValue ( _                          ' VTable offset = 60
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL bChecked AS LONG _                           ' __in BOOL bChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetComboBoxSelectedValue ( _                  ' VTable offset = 64
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwSelectedItem AS DWORD _                    ' __in DWORD dwSelectedItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommandLinkClicked ( _                        ' VTable offset = 68
     BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerialization ( _                          ' VTable offset = 72
     BYREF pcpgsr AS LONG _                             ' __out CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE *pcpgsr
   , BYREF pcpcs AS CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION _ ' __out CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION *pcpcs
   , BYREF ppszOptionalStatusText AS DWORD _            ' __out LPWSTR *ppszOptionalStatusText
   , BYREF pcpsiOptionalStatusIcon AS LONG _            ' __out CREDENTIAL_PROVIDER_STATUS_ICON *pcpsiOptionalStatusIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportResult ( _                              ' VTable offset = 76
     BYVAL ntsStatus AS LONG _                          ' __in NTSTATUS ntsStatus
   , BYVAL ntsSubstatus AS LONG _                       ' __in NTSTATUS ntsSubstatus
   , BYREF ppszOptionalStatusText AS DWORD _            ' __out LPWSTR *ppszOptionalStatusText
   , BYREF pcpsiOptionalStatusIcon AS LONG _            ' __out CREDENTIAL_PROVIDER_STATUS_ICON *pcpsiOptionalStatusIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConnectableCredentialProviderCredential methods
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 80
     BYVAL pqcws AS IQueryContinueWithStatus _          ' __in IQueryContinueWithStatus *pqcws
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConnectableCredentialProviderCredential_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICredentialProviderCredentialEvents
' IID = {FA6FA76B-66B7-4B11-95F1-86171118E816}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICredentialProviderCredentialEvents_INTERFACE_DEFINED)
    %ICredentialProviderCredentialEvents_INTERFACE_DEFINED = 1

INTERFACE ICredentialProviderCredentialEvents $IID_ICredentialProviderCredentialEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFieldState ( _                             ' VTable offset = 12
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL cpfs AS LONG _                               ' __in CREDENTIAL_PROVIDER_FIELD_STATE cpfs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFieldInteractiveState ( _                  ' VTable offset = 16
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL cpfis AS LONG _                              ' __in CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE cpfis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFieldString ( _                            ' VTable offset = 20
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF psz AS WSTRINGZ _                            ' __in LPCWSTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFieldCheckbox ( _                          ' VTable offset = 24
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL bChecked AS LONG _                           ' __in BOOL bChecked
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFieldBitmap ( _                            ' VTable offset = 28
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL hbmp AS DWORD _                              ' __in HBITMAP hbmp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFieldComboBoxSelectedItem ( _              ' VTable offset = 32
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwSelectedItem AS DWORD _                    ' __in DWORD dwSelectedItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteFieldComboBoxItem ( _                   ' VTable offset = 36
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwItem AS DWORD _                            ' __in DWORD dwItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendFieldComboBoxItem ( _                   ' VTable offset = 40
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYREF pszItem AS WSTRINGZ _                        ' __in LPCWSTR pszItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFieldSubmitButton ( _                      ' VTable offset = 44
     BYVAL pcpc AS ICredentialProviderCredential _      ' __in ICredentialProviderCredential *pcpc
   , BYVAL dwFieldID AS DWORD _                         ' __in DWORD dwFieldID
   , BYVAL dwAdjacentTo AS DWORD _                      ' __in DWORD dwAdjacentTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreatingWindow ( _                          ' VTable offset = 48
     BYREF phwndOwner AS DWORD _                        ' __out HWND *phwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICredentialProviderCredentialEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICredentialProvider
' IID = {D27C3481-5A1C-45B2-8AAA-C20EBBE8229E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICredentialProvider_INTERFACE_DEFINED)
    %ICredentialProvider_INTERFACE_DEFINED = 1

INTERFACE ICredentialProvider $IID_ICredentialProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetUsageScenario ( _                          ' VTable offset = 12
     BYVAL cpus AS LONG _                               ' __in CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSerialization ( _                          ' VTable offset = 16
     BYREF pcpcs AS CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION _ ' __in CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION *pcpcs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 20
     BYVAL pcpe AS ICredentialProviderEvents _          ' __in ICredentialProviderEvents *pcpe
   , BYVAL upAdviseContext AS DWORD _                   ' __in UINT_PTR upAdviseContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnAdvise ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldDescriptorCount ( _                   ' VTable offset = 28
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldDescriptorAt ( _                      ' VTable offset = 32
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppcpfd AS CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR _ ' __out CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR **ppcpfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCredentialCount ( _                        ' VTable offset = 36
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   , BYREF pdwDefault AS DWORD _                        ' __out DWORD *pdwDefault
   , BYREF pbAutoLogonWithDefault AS LONG _             ' __out BOOL *pbAutoLogonWithDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCredentialAt ( _                           ' VTable offset = 40
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppcpc AS ICredentialProviderCredential _     ' __out ICredentialProviderCredential **ppcpc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICredentialProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICredentialProviderEvents
' IID = {34201E5A-A787-41A3-A5A4-BD6DCF2A854E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICredentialProviderEvents_INTERFACE_DEFINED)
    %ICredentialProviderEvents_INTERFACE_DEFINED = 1

INTERFACE ICredentialProviderEvents $IID_ICredentialProviderEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CredentialsChanged ( _                        ' VTable offset = 12
     BYVAL upAdviseContext AS DWORD _                   ' __in UINT_PTR upAdviseContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICredentialProviderEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICredentialProviderFilter
' IID = {a5da53f9-d475-4080-a120-910c4a739880}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICredentialProviderFilter_INTERFACE_DEFINED)
    %ICredentialProviderFilter_INTERFACE_DEFINED = 1

INTERFACE ICredentialProviderFilter $IID_ICredentialProviderFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Filter ( _                                    ' VTable offset = 12
     BYVAL cpus AS LONG _                               ' __in CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF rgclsidProviders AS GUID _                   ' __in GUID *rgclsidProviders
   , BYREF rgbAllow AS LONG _                           ' __inout BOOL *rgbAllow
   , BYVAL cProviders AS DWORD _                        ' __in DWORD cProviders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateRemoteCredential ( _                    ' VTable offset = 16
     BYREF pcpcsIn AS CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION _ ' __in const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION *pcpcsIn
   , BYREF pcpcsOut AS CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION _ ' __out CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION *pcpcsOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICredentialProviderFilter_INTERFACE_DEFINED__ */
