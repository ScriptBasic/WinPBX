' ########################################################################################
' Microsoft Windows
' File: IContact.inc
' Library name: CONTACT
' Version: 1.0, Locale ID = 0
' Library GUID: {FFB3DF4D-F600-473E-92C1-CF9A1F4CCCC5}
' Contents: Microsoft Contact Objects
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ICONTACT_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {61B68808-8EEE-4FD1-ACB8-3D804C8DB056}
$PROGID_CONTACT1 = "Windows.Contact.1"
' CLSID = {7165C8AB-AF88-42BD-86FD-5310B4285A02}
$PROGID_ContactManager1 = "Windows.ContactManager.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {61B68808-8EEE-4FD1-ACB8-3D804C8DB056}
$PROGID_CONTACT = "Windows.Contact"
' CLSID = {7165C8AB-AF88-42BD-86FD-5310B4285A02}
$PROGID_ContactManager = "Windows.ContactManager"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Contact = GUID$("{61B68808-8EEE-4FD1-ACB8-3D804C8DB056}")
$CLSID_ContactManager = GUID$("{7165C8AB-AF88-42BD-86FD-5310B4285A02}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IContact = GUID$("{F941B671-BDA7-4F77-884A-F46462F226A7}")
$IID_IContactCollection = GUID$("{B6AFA338-D779-11D9-8BDE-F66BAD1E3F3A}")
$IID_IContactManager = GUID$("{AD553D98-DEB1-474A-8E17-FC0C2075B738}")
$IID_IContactProperties = GUID$("{70DD27DD-5CBD-46E8-BEF0-23B6B346288F}")
$IID_IContactPropertyCollection = GUID$("{FFD3ADF8-FA64-4328-B1B6-2E0DB509CB3C}")

' ########################################################################################
' IContactManager interface
' IID = AD553D98-DEB1-474A-8E17-FC0C2075B738
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContactManager_INTERFACE_DEFINED)
    %IContactManager_INTERFACE_DEFINED = 1

INTERFACE IContactManager $IID_IContactManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszAppName AS WSTRINGZ _                     ' __in LPCWSTR pszAppName
   , BYREF pszAppVersion AS WSTRINGZ _                  ' __in LPCWSTR pszAppVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 16
     BYREF pszContactID AS WSTRINGZ _                   ' __in LPCWSTR pszContactID
   , BYREF ppContact AS IContact _                      ' __out IContact **ppContact
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MergeContactIDs ( _                           ' VTable offset = 20
     BYREF pszNewContactID AS WSTRINGZ _                ' __in LPCWSTR pszNewContactID
   , BYREF pszOldContactID AS WSTRINGZ _                ' __in LPCWSTR pszOldContactID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMeContact ( _                              ' VTable offset = 24
     BYREF ppMeContact AS IContact _                    ' __out IContact **ppMeContact
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMeContact ( _                              ' VTable offset = 28
     BYVAL pMeContact AS IContact _                     ' __in IContact *pMeContact
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContactCollection ( _                      ' VTable offset = 32
     BYREF ppContactCollection AS IContactCollection _  ' __out IContactCollection **ppContactCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContactManager_INTERFACE_DEFINED__ */

' ########################################################################################
' IContactCollection interface
' IID = B6AFA338-D779-11D9-8BDE-F66BAD1E3F3A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContactCollection_INTERFACE_DEFINED)
    %IContactCollection_INTERFACE_DEFINED = 1

INTERFACE IContactCollection $IID_IContactCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrent ( _                                ' VTable offset = 20
     BYREF ppContact AS IContact _                      ' __out IContact **ppContact
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContactCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' IContactProperties interface
' IID = 70DD27DD-5CBD-46E8-BEF0-23B6B346288F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContactProperties_INTERFACE_DEFINED)
    %IContactProperties_INTERFACE_DEFINED = 1

%CGD_DEFAULT = &H00000000???

INTERFACE IContactProperties $IID_IContactProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 12
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pszValue AS DWORD _                          ' __in_out LPWSTR pszValue
   , BYVAL cchValue AS DWORD _                          ' __in DWORD cchValue
   , BYREF pdwcchPropertyValueRequired AS DWORD _       ' __out DWORD *pdwcchPropertyValueRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDate ( _                                   ' VTable offset = 16
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pftDateTime AS FILETIME _                    ' __out FILETIME *pftDateTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBinary ( _                                 ' VTable offset = 20
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYREF dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszContentType AS WSTRINGZ _                 ' __in_out LPWSTR pszContentType
   , BYVAL cchContentType AS DWORD _                    ' __in DWORD cchContentType
   , BYREF pdwcchContentTypeRequired AS DWORD _         ' __out DWORD *pdwcchContentTypeRequired
   , BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLabels ( _                                 ' VTable offset = 24
     BYREF pszArrayElementName AS WSTRINGZ _            ' __in LPCWSTR pszArrayElementName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszLabels AS WSTRINGZ _                      ' __in_out LPWSTR pszLabels
   , BYVAL cchLabels AS DWORD _                         ' __in DWORD cchLabels
   , BYREF pdwcchLabelsRequired AS DWORD _              ' __out DWORD *pdwcchLabelsRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 28
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDate ( _                                   ' VTable offset = 32
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ftDateTime AS FILETIME _                     ' __in FILETIME ftDateTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBinary ( _                                 ' VTable offset = 36
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszContentType AS WSTRINGZ _                 ' __in LPCWSTR pszContentType
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLabels ( _                                 ' VTable offset = 40
     BYREF pszArrayElementName AS WSTRINGZ _            ' __in LPCWSTR pszArrayElementName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwLabelCount AS DWORD _                      ' __in DWORD dwLabelCount
   , BYREF ppszLabels AS WSTRINGZ _                     ' __in LPCWSTR ppszLabels[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateArrayNode ( _                           ' VTable offset = 44
     BYREF pszArrayName AS WSTRINGZ _                   ' __in LPCWSTR pszArrayName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL fAppend AS LONG _                            ' __in BOOL fAppend
   , BYREF pszNewArrayElementName AS WSTRINGZ _         ' __in_out LPWSTR pszNewArrayElementName
   , BYVAL cchNewArrayElementName AS DWORD _            ' __in DWORD cchNewArrayElementName
   , BYREF pdwcchNewArrayElementNameRequired AS DWORD _ ' __out DWORD *pdwcchNewArrayElementNameRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProperty ( _                            ' VTable offset = 48
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteArrayNode ( _                           ' VTable offset = 52
     BYREF pszArrayElementName AS WSTRINGZ _            ' __in LPCWSTR pszArrayElementName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteLabels ( _                              ' VTable offset = 56
     BYREF pszArrayElementName AS WSTRINGZ _            ' __in LPCWSTR pszArrayElementName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyCollection ( _                     ' VTable offset = 60
     BYREF ppPropertyCollection AS IContactPropertyCollection _ ' __out IContactPropertyCollection **ppPropertyCollection
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszMultiValueName AS WSTRINGZ _              ' __in LPCWSTR pszMultiValueName
   , BYVAL dwLabelCount AS DWORD _                      ' __in DWORD dwLabelCount
   , BYREF ppszLabels AS WSTRINGZ _                     ' __in LPCWSTR ppszLabels[  ]
   , BYVAL fAnyLabelMatches AS LONG _                   ' __in BOOL fAnyLabelMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContactProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' IContact interface
' IID = F941B671-BDA7-4F77-884A-F46462F226A7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContact_INTERFACE_DEFINED)
    %IContact_INTERFACE_DEFINED = 1

INTERFACE IContact $IID_IContact

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContactID ( _                              ' VTable offset = 12
     BYREF pszContactID AS WSTRINGZ _                   ' __in_out LPWSTR pszContactID
   , BYVAL cchContactID AS DWORD _                      ' __in DWORD cchContactID
   , BYREF pdwcchContactIDRequired AS DWORD _           ' __out DWORD *pdwcchContactIDRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 16
     BYREF pszPath AS WSTRINGZ _                        ' __in_out LPWSTR pszPath
   , BYVAL cchPath AS DWORD _                           ' __in DWORD cchPath
   , BYREF pdwcchPathRequired AS DWORD _                ' __out DWORD *pdwcchPathRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 20
     BYVAL dwCommitFlags AS DWORD _                     ' __in DWORD dwCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContact_INTERFACE_DEFINED__ */

' ########################################################################################
' IContactPropertyCollection interface
' IID = FFD3ADF8-FA64-4328-B1B6-2E0DB509CB3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContactPropertyCollection_INTERFACE_DEFINED)
    %IContactPropertyCollection_INTERFACE_DEFINED = 1

%CGD_UNKNOWN_PROPERTY     = &H00000000???
%CGD_STRING_PROPERTY      = &H00000001???
%CGD_DATE_PROPERTY        = &H00000002???
%CGD_BINARY_PROPERTY      = &H00000004???
%CGD_ARRAY_NODE           = &H00000008???

INTERFACE IContactPropertyCollection $IID_IContactPropertyCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyName ( _                           ' VTable offset = 20
     BYREF pszPropertyName AS WSTRINGZ _                ' __in_out LPWSTR pszPropertyName
   , BYVAL cchPropertyName AS DWORD _                   ' __in DWORD cchPropertyName
   , BYREF pdwcchPropertyNameRequired AS DWORD _        ' __out DWORD *pdwcchPropertyNameRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyType ( _                           ' VTable offset = 24
     BYREF pdwType AS DWORD _                           ' __out DWORD *pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyVersion ( _                        ' VTable offset = 28
     BYREF pdwVersion AS DWORD _                        ' __out DWORD *pdwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyModificationDate ( _               ' VTable offset = 32
     BYREF pftModificationDate AS FILETIME _            ' __out FILETIME *pftModificationDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyArrayElementID ( _                 ' VTable offset = 36
     BYREF pszArrayElementID AS WSTRINGZ _              ' __in_out LPWSTR pszArrayElementID
   , BYVAL cchArrayElementID AS DWORD _                 ' __in DWORD cchArrayElementID
   , BYREF pdwcchArrayElementIDRequired AS DWORD _      ' __out DWORD *pdwcchArrayElementIDRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContactPropertyCollection_INTERFACE_DEFINED__ */
