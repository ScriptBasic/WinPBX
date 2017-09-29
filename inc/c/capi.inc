' ########################################################################################
' Microsoft Windows
' File: capi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAPI_INC = 1

#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "sipbase.inc"
#INCLUDE ONCE "mscat.inc"
#INCLUDE ONCE "mssip.inc"
#INCLUDE ONCE "wintrust.inc"

#IF NOT %DEF(%JAVA_TRUST_PROVIDER)

'// New guids for Java Policy Provider
'// {E6F795B1-F738-11d0-A72F-00A0C903B83D}
'#define JAVA_POLICY_PROVIDER_DOWNLOAD \
'{ 0xe6f795b1, 0xf738, 0x11d0, {0xa7, 0x2f, 0x0, 0xa0, 0xc9, 0x3, 0xb8, 0x3d } }
$JAVA_POLICY_PROVIDER_DOWNLOAD = GUID$("{E6F795B1-F738-11d0-A72F-00A0C903B83D}")

'// {E6F795B2-F738-11d0-A72F-00A0C903B83D}
'#define JAVA_POLICY_PROVIDER_CHECK \
'{ 0xe6f795b2, 0xf738, 0x11d0, {0xa7, 0x2f, 0x0, 0xa0, 0xc9, 0x3, 0xb8, 0x3d } }
$JAVA_POLICY_PROVIDER_CHECK = GUID$("{E6F795B2-F738-11d0-A72F-00A0C903B83D}")

' // Size = 60 bytes
TYPE JAVA_TRUST DWORD
   cbSize                 AS DWORD          ' DWORD // Size of structure
   flag                   AS DWORD          ' DWORD // Reserved
   fAllActiveXPermissions AS LONG           ' BOOL // ActiveX explicitly asked for all (must have been signed)
   fAllPermissions        AS LONG           ' BOOL // Java permissions, explicit ask for all
   dwEncodingType         AS DWORD          ' DWORD // Encoding type
   pbJavaPermissions      AS BYTE PTR       ' PBYTE // Encoded java permission blob
   cbJavaPermissions      AS DWORD          ' DWORD
   pbSigner               AS BYTE PTR       ' PBYTE // Encoded signer.
   cbSigner               AS DWORD          ' DWORD
   pwszZone               AS WSTRINGZ PTR   ' LPCWSTR // Zone index (copied from action data)
   guidZone               AS GUID           ' GUID // Not used currently
   hVerify                AS LONG           ' HRESULT // Authenticode policy return
END TYPE

' // Size = 36 bytes
TYPE JAVA_POLICY_PROVIDER DWORD
   cbSize             AS DWORD            ' DWORD // Size of policy provider
   pZoneManager       AS DWORD            ' LPVOID // Zone interface manager
   pwszZone           AS WSTRINGZ PTR     ' LPCWSTR // Zone index
   fNoBadUI           AS LONG             ' BOOL // Optional bad ui
   pbJavaTrust        AS JAVA_TRUST PTR   ' PJAVA_TRUST // Returned java information (CoTaskMemAlloc)
   cbJavaTrust        AS DWORD            ' DWORD // Total allocated size of pJavaTrust
   dwActionID         AS DWORD            ' DWORD // Optional ActionID ID
   dwUnsignedActionID AS DWORD            ' DWORD // Optional ActionID ID
   VMBased            AS LONG             ' BOOL // Called from VM (FALSE by DEFAULT)
END TYPE

'#ifdef __cplusplus
'}
'#endif

#ENDIF   ' // !defined(JAVA_TRUST_PROVIDER)
