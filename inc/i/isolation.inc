' ########################################################################################
' Microsoft Windows
' File: isolation.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ISOLATION_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"

' // Size = 12 bytes
TYPE IDENTITY_ATTRIBUTE DWORD
   pszNamespace AS WSTRINGZ PTR   ' LPCWSTR
   pszName      AS WSTRINGZ PTR   ' LPCWSTR
   pszValue     AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' ########################################################################################
' Interface name = IReferenceIdentity
' IID = 6EAF5ACE-7917-4F3C-B129-E046A9704766
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IReferenceIdentity_INTERFACE_DEFINED)
   %IReferenceIdentity_INTERFACE_DEFINED = 1

$IID_IReferenceIdentity = GUID$("{6EAF5ACE-7917-4F3C-B129-E046A9704766}")

INTERFACE IReferenceIdentity $IID_IReferenceIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 12
     BYREF pszNamespace AS WSTRINGZ _                   ' __in LPCWSTR pszNamespace
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF ppszValue AS DWORD _                         ' __out LPWSTR *ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttribute ( _                              ' VTable offset = 16
     BYREF pszNamespace AS WSTRINGZ _                   ' __in LPCWSTR pszNamespace
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttributes ( _                            ' VTable offset = 20
     BYREF ppIEnumIDENTITY_ATTRIBUTE AS IEnumIDENTITY_ATTRIBUTE _ ' __out IEnumIDENTITY_ATTRIBUTE **ppIEnumIDENTITY_ATTRIBUTE
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYVAL cDeltas AS DWORD _                           ' __in SIZE_T cDeltas
   , BYREF rgDeltas AS IDENTITY_ATTRIBUTE _             ' __in const IDENTITY_ATTRIBUTE rgDeltas[  ]
   , BYREF ppIReferenceIdentity AS IReferenceIdentity _ ' __out IReferenceIdentity **ppIReferenceIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReferenceIdentity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDefinitionIdentity
' IID = 587BF538-4D90-4A3C-9EF1-58A200A8A9E7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDefinitionIdentity_INTERFACE_DEFINED)
   %IDefinitionIdentity_INTERFACE_DEFINED = 1

$IID_IDefinitionIdentity = GUID$("{587BF538-4D90-4A3C-9EF1-58A200A8A9E7}")

INTERFACE IDefinitionIdentity $IID_IDefinitionIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 12
     BYREF pszNamespace AS WSTRINGZ _                   ' __in LPCWSTR pszNamespace
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF ppszValue AS DWORD _                         ' __out LPWSTR *ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttribute ( _                              ' VTable offset = 16
     BYREF pszNamespace AS WSTRINGZ _                   ' __in LPCWSTR pszNamespace
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttributes ( _                            ' VTable offset = 20
     BYREF ppIEnumIDENTITY_ATTRIBUTE AS IEnumIDENTITY_ATTRIBUTE _ ' __out IEnumIDENTITY_ATTRIBUTE **ppIEnumIDENTITY_ATTRIBUTE
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYVAL cDeltas AS DWORD _                           ' __in SIZE_T cDeltas
   , BYREF prgDeltas AS IDENTITY_ATTRIBUTE _            ' __in const IDENTITY_ATTRIBUTE prgDeltas[  ]
   , BYREF ppIDefinitionIdentity AS IDefinitionIdentity _ ' __out IDefinitionIdentity **ppIDefinitionIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDefinitionIdentity_INTERFACE_DEFINED__ */

' // Size = 12 bytes
TYPE IDENTITY_ATTRIBUTE_BLOB DWORD
   ofsNamespace AS DWORD
   ofsName      AS DWORD
   ofsValue     AS DWORD
END TYPE

' ########################################################################################
' Interface name = IEnumIDENTITY_ATTRIBUTE
' IID = 9CDAAE75-246E-4B00-A26D-B9AEC137A3EB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumIDENTITY_ATTRIBUTE_INTERFACE_DEFINED)
   %IEnumIDENTITY_ATTRIBUTE_INTERFACE_DEFINED = 1

$IID_IEnumIDENTITY_ATTRIBUTE = GUID$("{9CDAAE75-246E-4B00-A26D-B9AEC137A3EB}")

INTERFACE IEnumIDENTITY_ATTRIBUTE $IID_IEnumIDENTITY_ATTRIBUTE

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgAttributes AS IDENTITY_ATTRIBUTE _         ' __out IDENTITY_ATTRIBUTE rgAttributes[  ]
   , BYREF pceltWritten AS DWORD _                      ' __out_opt ULONG *pceltWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CurrentIntoBuffer ( _                         ' VTable offset = 16
     BYVAL cbAvailable AS DWORD _                       ' __in SIZE_T cbAvailable
   , BYVAL pbData AS BYTE PTR _                         ' __inout BYTE pbData[  ]
   , BYREF pcbUsed AS DWORD _                           ' __out SIZE_T *pcbUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 28
     BYREF ppIEnumIDENTITY_ATTRIBUTE AS IEnumIDENTITY_ATTRIBUTE _ ' __out IEnumIDENTITY_ATTRIBUTE **ppIEnumIDENTITY_ATTRIBUTE
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumIDENTITY_ATTRIBUTE_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumDefinitionIdentity
' IID = F3549D9C-FC73-4793-9C00-1CD204254C0C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDefinitionIdentity_INTERFACE_DEFINED)
   %IEnumDefinitionIdentity_INTERFACE_DEFINED = 1

$IID_IEnumDefinitionIdentity = GUID$("{F3549D9C-FC73-4793-9C00-1CD204254C0C}")

INTERFACE IEnumDefinitionIdentity $IID_IEnumDefinitionIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgpIDefinitionIdentity AS IDefinitionIdentity _ ' __out IDefinitionIdentity *rgpIDefinitionIdentity[  ]
   , BYREF pceltWritten AS DWORD _                      ' __out ULONG *pceltWritten
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
     BYREF ppIEnumDefinitionIdentity AS IEnumDefinitionIdentity _ ' __out IEnumDefinitionIdentity **ppIEnumDefinitionIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDefinitionIdentity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumReferenceIdentity
' IID = B30352CF-23DA-4577-9B3F-B4E6573BE53B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumReferenceIdentity_INTERFACE_DEFINED)
   %IEnumReferenceIdentity_INTERFACE_DEFINED = 1

$IID_IEnumReferenceIdentity = GUID$("{B30352CF-23DA-4577-9B3F-B4E6573BE53B}")

INTERFACE IEnumReferenceIdentity $IID_IEnumReferenceIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF prgpIReferenceIdentity AS IReferenceIdentity _ ' __out IReferenceIdentity **prgpIReferenceIdentity
   , BYREF pceltWritten AS DWORD _                      ' __out ULONG *pceltWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnumReferenceIdentity AS IEnumReferenceIdentity _ ' IEnumReferenceIdentity **ppIEnumReferenceIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumReferenceIdentity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDefinitionAppId
' IID = D91E12D8-98ED-47FA-9936-39421283D59B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDefinitionAppId_INTERFACE_DEFINED)
   %IDefinitionAppId_INTERFACE_DEFINED = 1

$IID_IDefinitionAppId = GUID$("{D91E12D8-98ED-47FA-9936-39421283D59B}")

INTERFACE IDefinitionAppId $IID_IDefinitionAppId

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_SubscriptionId ( _                        ' VTable offset = 12
     BYREF ppszSubscription AS DWORD _                  ' __out LPWSTR *ppszSubscription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SubscriptionId ( _                        ' VTable offset = 16
     BYREF pszSubscription AS WSTRINGZ _                ' __in LPCWSTR pszSubscription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Codebase ( _                              ' VTable offset = 20
     BYREF ppszCodebase AS DWORD _                      ' __out LPWSTR *ppszCodebase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Codebase ( _                              ' VTable offset = 24
     BYREF pszCodebase AS WSTRINGZ _                    ' __in LPCWSTR pszCodebase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAppPath ( _                               ' VTable offset = 28
     BYREF ppIEnumDefinitionIdentity AS IEnumDefinitionIdentity _ ' __out IEnumDefinitionIdentity **ppIEnumDefinitionIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAppPath ( _                                ' VTable offset = 32
     BYVAL cIDefinitionIdentity AS DWORD _              ' __in ULONG cIDefinitionIdentity
   , BYREF rgIDefinitionIdentity AS IDefinitionIdentity _ ' __in IDefinitionIdentity *rgIDefinitionIdentity[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDefinitionAppId_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IReferenceAppId
' IID = 054F0BEF-9E45-4363-8F5A-2F8E142D9A3B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IReferenceAppId_INTERFACE_DEFINED)
   %IReferenceAppId_INTERFACE_DEFINED = 1

$IID_IReferenceAppId = GUID$("{054F0BEF-9E45-4363-8F5A-2F8E142D9A3B}")

INTERFACE IReferenceAppId $IID_IReferenceAppId

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_SubscriptionId ( _                        ' VTable offset = 12
     BYREF ppszSubscription AS DWORD _                  ' __out LPWSTR *ppszSubscription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SubscriptionId ( _                        ' VTable offset = 16
     BYREF pszSubscription AS WSTRINGZ _                ' __in LPCWSTR pszSubscription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Codebase ( _                              ' VTable offset = 20
     BYREF ppszCodebase AS DWORD _                      ' __out LPWSTR *ppszCodebase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Codebase ( _                              ' VTable offset = 24
     BYREF pszCodebase AS WSTRINGZ _                    ' __in LPCWSTR pszCodebase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAppPath ( _                               ' VTable offset = 28
     BYREF ppIReferenceAppId AS IEnumReferenceIdentity _ ' __out IEnumReferenceIdentity **ppIReferenceAppId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReferenceAppId_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIdentityAuthority
' IID = 261A6983-C35D-4D0D-AA5B-7867259E77BC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIdentityAuthority_INTERFACE_DEFINED)
   %IIdentityAuthority_INTERFACE_DEFINED = 1

' enum _TEXT_TO_DEFINITION_IDENTITY_FLAGS
%TEXT_TO_DEFINITION_IDENTITY_FLAG_ALLOW_UNKNOWN_ATTRIBUTES_IN_NULL_NAMESPACE = &H1???

' enum _TEXT_TO_REFERENCE_IDENTITY_FLAGS
%TEXT_TO_REFERENCE_IDENTITY_FLAG_ALLOW_UNKNOWN_ATTRIBUTES_IN_NULL_NAMESPACE = &H1???

' enum _DEFINITION_IDENTITY_TO_TEXT_FLAGS
%DEFINITION_IDENTITY_TO_TEXT_FLAG_CANONICAL = &H1???

' enum _REFERENCE_IDENTITY_TO_TEXT_FLAGS
%REFERENCE_IDENTITY_TO_TEXT_FLAG_CANONICAL = &H1???

' enum _IIDENTITYAUTHORITY_DOES_DEFINITION_MATCH_REFERENCE_FLAGS
%IIDENTITYAUTHORITY_DOES_DEFINITION_MATCH_REFERENCE_FLAG_EXACT_MATCH_REQUIRED = &H1???

' enum _IIDENTITYAUTHORITY_DOES_TEXTUAL_DEFINITION_MATCH_TEXTUAL_REFERENCE_FLAGS
%IIDENTITYAUTHORITY_DOES_TEXTUAL_DEFINITION_MATCH_TEXTUAL_REFERENCE_FLAG_EXACT_MATCH_REQUIRED = &H1???

$IID_IIdentityAuthority = GUID$("{261A6983-C35D-4D0D-AA5B-7867259E77BC}")

INTERFACE IIdentityAuthority $IID_IIdentityAuthority

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TextToDefinition ( _                          ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszIdentity AS WSTRINGZ _                    ' __in LPCWSTR pszIdentity
   , BYREF ppIDefinitionIdentity AS IDefinitionIdentity _ ' __out IDefinitionIdentity **ppIDefinitionIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TextToReference ( _                           ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszIdentity AS WSTRINGZ _                    ' __in LPCWSTR pszIdentity
   , BYREF ppIReferenceIdentity AS IReferenceIdentity _ ' __out IReferenceIdentity **ppIReferenceIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefinitionToText ( _                          ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionIdentity _ ' __in IDefinitionIdentity *pIDefinitionIdentity
   , BYREF ppszFormattedIdentity AS DWORD _             ' __out LPWSTR *ppszFormattedIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefinitionToTextBuffer ( _                    ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionIdentity _ ' __in IDefinitionIdentity *pIDefinitionIdentity
   , BYVAL cchBufferSize AS DWORD _                     ' __in ULONG cchBufferSize
   , BYREF wchBuffer AS WSTRINGZ _                      ' __inout WCHAR wchBuffer[  ]
   , BYREF pcchBufferRequired AS DWORD _                ' __out ULONG *pcchBufferRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReferenceToText ( _                           ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceIdentity AS IReferenceIdentity _  ' __in IReferenceIdentity *pIReferenceIdentity
   , BYREF ppszFormattedIdentity AS DWORD _             ' __out LPWSTR *ppszFormattedIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReferenceToTextBuffer ( _                     ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceIdentity AS IReferenceIdentity _  ' __in IReferenceIdentity *pIReferenceIdentity
   , BYVAL cchBufferSize AS DWORD _                     ' __in ULONG cchBufferSize
   , BYREF wchBuffer AS WSTRINGZ _                      ' __inout WCHAR wchBuffer[  ]
   , BYREF pcchBufferRequired AS DWORD _                ' __out ULONG *pcchBufferRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreDefinitionsEqual ( _                       ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pDefinition1 AS IDefinitionIdentity _        ' __in IDefinitionIdentity *pDefinition1
   , BYVAL pDefinition2 AS IDefinitionIdentity _        ' __in IDefinitionIdentity *pDefinition2
   , BYREF LONG _                                       ' __out BOOL *pfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreReferencesEqual ( _                        ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pReference1 AS IReferenceIdentity _          ' __in IReferenceIdentity *pReference1
   , BYVAL pReference2 AS IReferenceIdentity _          ' __in IReferenceIdentity *pReference2
   , BYREF LONG _                                       ' __out BOOL *pfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreTextualDefinitionsEqual ( _                ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszIdentityLeft AS WSTRINGZ _                ' __in LPCWSTR pszIdentityLeft
   , BYREF pszIdentityRight AS WSTRINGZ _               ' __in LPCWSTR pszIdentityRight
   , BYREF pfEqual AS LONG _                            ' __out BOOL *pfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreTextualReferencesEqual ( _                 ' VTable offset = 48
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszIdentityLeft AS WSTRINGZ _                ' __in LPCWSTR pszIdentityLeft
   , BYREF pszIdentityRight AS WSTRINGZ _               ' __in LPCWSTR pszIdentityRight
   , BYREF pfEqual AS LONG _                            ' __out BOOL *pfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesDefinitionMatchReference ( _              ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionIdentity _ ' __in IDefinitionIdentity *pIDefinitionIdentity
   , BYVAL pIReferenceIdentity AS IReferenceIdentity _  ' __in IReferenceIdentity *pIReferenceIdentity
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesTextualDefinitionMatchTextualReference ( _ ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszDefinition AS WSTRINGZ _                  ' __in LPCWSTR pszDefinition
   , BYREF pszReference AS WSTRINGZ _                   ' __in LPCWSTR pszReference
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HashReference ( _                             ' VTable offset = 60
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceIdentity AS IReferenceIdentity _  ' __in IReferenceIdentity *pIReferenceIdentity
   , BYREF pullPseudoKey AS QUAD _                      ' __out ULONGLONG *pullPseudoKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HashDefinition ( _                            ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionIdentity _ ' __in IDefinitionIdentity *pIDefinitionIdentity
   , BYREF pullPseudoKey AS QUAD _                      ' __out ULONGLONG *pullPseudoKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateDefinitionKey ( _                     ' VTable offset = 68
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionIdentity _ ' __in IDefinitionIdentity *pIDefinitionIdentity
   , BYREF ppszKeyForm AS DWORD _                       ' __out LPWSTR *ppszKeyForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateReferenceKey ( _                      ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceIdentity AS IReferenceIdentity _  ' __in IReferenceIdentity *pIReferenceIdentity
   , BYREF ppszKeyForm AS DWORD _                       ' __out LPWSTR *ppszKeyForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDefinition ( _                          ' VTable offset = 76
     BYREF ppNewIdentity AS IDefinitionIdentity _       ' __out IDefinitionIdentity **ppNewIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateReference ( _                           ' VTable offset = 80
     BYREF ppNewIdentity AS IDefinitionIdentity _       ' __out IDefinitionIdentity **ppNewIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdentityAuthority_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppIdAuthority
' IID = 8C87810C-2541-4F75-B2D0-9AF515488E23
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppIdAuthority_INTERFACE_DEFINED)
   %IAppIdAuthority_INTERFACE_DEFINED = 1

' enum IAPPIDAUTHORITY_ARE_DEFINITIONS_EQUAL_FLAGS
%IAPPIDAUTHORITY_ARE_DEFINITIONS_EQUAL_FLAG_IGNORE_VERSION = &H1???

' enum IAPPIDAUTHORITY_ARE_REFERENCES_EQUAL_FLAGS
%IAPPIDAUTHORITY_ARE_REFERENCES_EQUAL_FLAG_IGNORE_VERSION = &H1???

$IID_IAppIdAuthority = GUID$("{8C87810C-2541-4F75-B2D0-9AF515488E23}")

INTERFACE IAppIdAuthority $IID_IAppIdAuthority

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TextToDefinition ( _                          ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszIdentity AS WSTRINGZ _                    ' __in LPCWSTR pszIdentity
   , BYREF ppIDefinitionAppId AS IDefinitionAppId _     ' __out IDefinitionAppId **ppIDefinitionAppId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TextToReference ( _                           ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszIdentity AS WSTRINGZ _                    ' __in LPCWSTR pszIdentity
   , BYREF ppIReferenceAppId AS IReferenceAppId _       ' __out IReferenceAppId **ppIReferenceAppId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefinitionToText ( _                          ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionAppId AS IDefinitionAppId _      ' __in IDefinitionAppId *pIDefinitionAppId
   , BYREF ppszFormattedIdentity AS DWORD _             ' __out LPWSTR *ppszFormattedIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReferenceToText ( _                           ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceAppId AS IReferenceAppId _        ' __in IReferenceAppId *pIReferenceAppId
   , BYREF ppszFormattedIdentity AS DWORD _             ' __out LPWSTR *ppszFormattedIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreDefinitionsEqual ( _                       ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pDefinition1 AS IDefinitionAppId _           ' __in IDefinitionAppId *pDefinition1
   , BYVAL pDefinition2 AS IDefinitionAppId _           ' __in IDefinitionAppId *pDefinition2
   , BYREF LONG _                                       ' __out BOOL *pfAreEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreReferencesEqual ( _                        ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pReference1 AS IReferenceAppId _             ' __in IReferenceAppId *pReference1
   , BYVAL pReference2 AS IReferenceAppId _             ' __in IReferenceAppId *pReference2
   , BYREF pfAreEqual AS LONG _                         ' __out BOOL *pfAreEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreTextualDefinitionsEqual ( _                ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszAppIdLeft AS WSTRINGZ _                   ' __in LPCWSTR pszAppIdLeft
   , BYREF pszAppIdRight AS WSTRINGZ _                  ' __in LPCWSTR pszAppIdRight
   , BYREF pfAreEqual AS LONG _                         ' __out BOOL *pfAreEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreTextualReferencesEqual ( _                 ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszAppIdLeft AS WSTRINGZ _                   ' __in LPCWSTR pszAppIdLeft
   , BYREF pszAppIdRight AS WSTRINGZ _                  ' __in LPCWSTR pszAppIdRight
   , BYREF pfAreEqual AS LONG _                         ' __out BOOL *pfAreEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesDefinitionMatchReference ( _              ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionAppId _   ' __in IDefinitionAppId *pIDefinitionIdentity
   , BYVAL pIReferenceIdentity AS IReferenceAppId _     ' __in IReferenceAppId *pIReferenceIdentity
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesTextualDefinitionMatchTextualReference ( _ ' VTable offset = 48
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszDefinition AS WSTRINGZ _                  ' __in LPCWSTR pszDefinition
   , BYREF pszReference AS WSTRINGZ _                   ' __in LPCWSTR pszReference
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HashReference ( _                             ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceIdentity AS IReferenceAppId _     ' __in IReferenceAppId *pIReferenceIdentity
   , BYREF pullPseudoKey AS QUAD _                      ' __out ULONGLONG *pullPseudoKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HashDefinition ( _                            ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionAppId _   ' __in IDefinitionAppId *pIDefinitionIdentity
   , BYREF pullPseudoKey AS QUAD _                      ' __out ULONGLONG *pullPseudoKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateDefinitionKey ( _                     ' VTable offset = 60
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIDefinitionIdentity AS IDefinitionAppId _   ' __in IDefinitionAppId *pIDefinitionIdentity
   , BYREF ppszKeyForm AS DWORD _                       ' __out LPWSTR *ppszKeyForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateReferenceKey ( _                      ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pIReferenceIdentity AS IReferenceAppId _     ' __in IReferenceAppId *pIReferenceIdentity
   , BYREF ppszKeyForm AS DWORD _                       ' __out LPWSTR *ppszKeyForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDefinition ( _                          ' VTable offset = 68
     BYREF ppNewIdentity AS IDefinitionAppId _          ' __out IDefinitionAppId **ppNewIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateReference ( _                           ' VTable offset = 72
     BYREF ppNewIdentity AS IDefinitionAppId _          ' __out IDefinitionAppId **ppNewIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppIdAuthority_INTERFACE_DEFINED__ */

' Not exported. Library: Library: mscorwks.dll
'/* [local] */ HRESULT __stdcall GetAppIdAuthority(
'    __out IAppIdAuthority **ppIAppIdAuthority);

' Not exported. Library: Library: mscorwks.dll
'/* [local] */ HRESULT __stdcall GetIdentityAuthority(
'    __out IIdentityAuthority **ppIIdentityAuthority);
