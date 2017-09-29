' ########################################################################################
' Microsoft Windows
' File: netprov.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: NETPROVLib
' Version: 1.0, Locale ID = 0
' Documentation string: NETPROV 1.0 Type Library
' Library GUID: {789ED9B3-4873-49B9-87E0-55F51FCD5420}
' ########################################################################################

#INCLUDE THIS ONCE
%NETPROV_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "prsht.inc"
#INCLUDE ONCE "msxml.inc"

$LIBID_NETPROVLib = GUID$("{789ED9B3-4873-49B9-87E0-55F51FCD5420}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_NetProvisioning = GUID$("{2AA2B5FE-B846-4D07-810C-B21EE45320E3}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IProvisioningDomain = GUID$("{C96FBD50-24DD-11D8-89FB-00904B2EA9C6}")
$IID_IProvisioningProfileWireless = GUID$("{C96FBD51-24DD-11D8-89FB-00904B2EA9C6}")

' ########################################################################################
' Interface name = IProvisioningDomain
' IID = {C96FBD50-24DD-11D8-89FB-00904B2EA9C6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvisioningDomain_INTERFACE_DEFINED)
    %IProvisioningDomain_INTERFACE_DEFINED = 1

INTERFACE IProvisioningDomain $IID_IProvisioningDomain

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYREF pszwPathToFolder AS WSTRINGZ _               ' __in LPCWSTR pszwPathToFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 16
     BYREF pszwDomain AS WSTRINGZ _                     ' __in LPCWSTR pszwDomain
   , BYREF pszwLanguage AS WSTRINGZ _                   ' __in LPCWSTR pszwLanguage
   , BYREF pszwXPathQuery AS WSTRINGZ _                 ' __in LPCWSTR pszwXPathQuery
   , BYREF Nodes AS IXMLDOMNodeList _                   ' __out IXMLDOMNodeList **Nodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvisioningDomain_INTERFACE_DEFINED__ */


'//
'// WZC Wireless CreateProfile private error codes (returned in *pulStatus)
'// WZC_PROFILE_SUCCESS is applicable only if the HRESULT returned is also
'// S_OK
'//

%WZC_PROFILE_SUCCESS                                       = 0
%WZC_PROFILE_XML_ERROR_NO_VERSION                          = 1
%WZC_PROFILE_XML_ERROR_BAD_VERSION                         = 2
%WZC_PROFILE_XML_ERROR_UNSUPPORTED_VERSION                 = 3
%WZC_PROFILE_XML_ERROR_SSID_NOT_FOUND                      = 4
%WZC_PROFILE_XML_ERROR_BAD_SSID                            = 5
%WZC_PROFILE_XML_ERROR_CONNECTION_TYPE                     = 6
%WZC_PROFILE_XML_ERROR_AUTHENTICATION                      = 7
%WZC_PROFILE_XML_ERROR_ENCRYPTION                          = 8
%WZC_PROFILE_XML_ERROR_KEY_PROVIDED_AUTOMATICALLY          = 9
%WZC_PROFILE_XML_ERROR_1X_ENABLED                          = 10
%WZC_PROFILE_XML_ERROR_EAP_METHOD                          = 11
%WZC_PROFILE_XML_ERROR_BAD_KEY_INDEX                       = 12
%WZC_PROFILE_XML_ERROR_KEY_INDEX_RANGE                     = 13
%WZC_PROFILE_XML_ERROR_BAD_NETWORK_KEY                     = 14
%WZC_PROFILE_CONFIG_ERROR_INVALID_AUTH_FOR_CONNECTION_TYPE = 15
%WZC_PROFILE_CONFIG_ERROR_INVALID_ENCRYPTION_FOR_AUTHMODE  = 16
%WZC_PROFILE_CONFIG_ERROR_KEY_REQUIRED                     = 17
%WZC_PROFILE_CONFIG_ERROR_KEY_INDEX_REQUIRED               = 18
%WZC_PROFILE_CONFIG_ERROR_KEY_INDEX_NOT_APPLICABLE         = 19
%WZC_PROFILE_CONFIG_ERROR_1X_NOT_ALLOWED                   = 20
%WZC_PROFILE_CONFIG_ERROR_1X_NOT_ALLOWED_KEY_REQUIRED      = 21
%WZC_PROFILE_CONFIG_ERROR_1X_NOT_ENABLED_KEY_PROVIDED      = 22
%WZC_PROFILE_CONFIG_ERROR_EAP_METHOD_REQUIRED              = 23
%WZC_PROFILE_CONFIG_ERROR_EAP_METHOD_NOT_APPLICABLE        = 24
%WZC_PROFILE_CONFIG_ERROR_WPA_NOT_SUPPORTED                = 25
%WZC_PROFILE_CONFIG_ERROR_WPA_ENCRYPTION_NOT_SUPPORTED     = 26
%WZC_PROFILE_SET_ERROR_DUPLICATE_NETWORK                   = 27
%WZC_PROFILE_SET_ERROR_MEMORY_ALLOCATION                   = 28
%WZC_PROFILE_SET_ERROR_READING_1X_CONFIG                   = 29
%WZC_PROFILE_SET_ERROR_WRITING_1X_CONFIG                   = 30
%WZC_PROFILE_SET_ERROR_WRITING_WZC_CFG                     = 31
%WZC_PROFILE_API_ERROR_NOT_SUPPORTED                       = 32
%WZC_PROFILE_API_ERROR_FAILED_TO_LOAD_XML                  = 33
%WZC_PROFILE_API_ERROR_FAILED_TO_LOAD_SCHEMA               = 34
%WZC_PROFILE_API_ERROR_XML_VALIDATION_FAILED               = 35
%WZC_PROFILE_API_ERROR_INTERNAL                            = 36

' ########################################################################################
' Interface name = IProvisioningProfileWireless
' IID = {C96FBD51-24DD-11D8-89FB-00904B2EA9C6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvisioningProfileWireless_INTERFACE_DEFINED)
    %IProvisioningProfileWireless_INTERFACE_DEFINED = 1

INTERFACE IProvisioningProfileWireless $IID_IProvisioningProfileWireless

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateProfile ( _                             ' VTable offset = 12
     BYVAL bstrXMLWirelessConfigProfile AS WSTRING _    ' __in BSTR bstrXMLWirelessConfigProfile
   , BYVAL bstrXMLConnectionConfigProfile AS WSTRING _  ' __in BSTR bstrXMLConnectionConfigProfile
   , BYREF pAdapterInstanceGuid AS GUID _               ' __in GUID *pAdapterInstanceGuid
   , BYREF pulStatus AS DWORD _                         ' __out ULONG *pulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvisioningProfileWireless_INTERFACE_DEFINED__ */
