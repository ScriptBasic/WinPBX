' ########################################################################################
' Microsoft Windows
' File: DavClnt.inc
' Contents: DAV specific functions that are exposed to the user.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DAVCLNT_INC = 1

'#define OPAQUE_HANDLE DWORD

'// Certificates or other Auth types will be sent through this structure
' // Size = 12 bytes
TYPE DAV_CALLBACK_AUTH_BLOB DWORD
   pBuffer AS DWORD   ' PVOID
   ulSize  AS DWORD   ' ULONG // Size of AuthBlob,
   ulType  AS DWORD   ' ULONG // Type of Cred sent in ppBuffer. Currently the only value it supports is 1 for PCCERT_CONTEXT.
END TYPE

'// Username and password will be sent through this structure
' // Size = 16 bytes
TYPE DAV_CALLBACK_AUTH_UNP DWORD
   pszUserName      AS WSTRINGZ PTR   ' LPWSTR // UserName . Memory to be allocated by the callback
   ulUserNameLength AS DWORD          ' ULONG // Length in WCHAR(Doesnt include terminating NULL)
   pszPassword      AS WSTRINGZ PTR   ' LPWSTR // Password . Memory to be allocated by the callback
   ulPasswordLength AS DWORD          ' ULONG // Length in WCHAR(Doesnt include terminating NULL)
END TYPE

' // Size = 36 bytes
TYPE DAV_CALLBACK_CRED DWORD
   AuthBlob       AS DAV_CALLBACK_AUTH_BLOB
   UNPBlob        AS DAV_CALLBACK_AUTH_UNP
   bAuthBlobValid AS LONG                     ' BOOL // Indicates if AuthBlob contents is valid. If false UNPBlob is valid
   bSave          AS LONG                     ' BOOL // Indicates the value of bsave flag. True indicates that the creds were written to credman false indicates that creds were not written to credman
END TYPE

%DAV_AUTHN_SCHEME_BASIC      = &H00000001???
%DAV_AUTHN_SCHEME_NTLM       = &H00000002???
%DAV_AUTHN_SCHEME_PASSPORT   = &H00000004???
%DAV_AUTHN_SCHEME_DIGEST     = &H00000008???
%DAV_AUTHN_SCHEME_NEGOTIATE  = &H00000010???
%DAV_AUTHN_SCHEME_CERT       = &H00010000???
%DAV_AUTHN_SCHEME_FBA        = &H00100000???

' enum AUTHNEXTSTEP
%DefaultBehavior = 0   ' // Try the default behaviour. Dont use callback
%RetryRequest    = 1   ' // Retry the connection with the newly gathered creds
%CancelRequest   = 2   ' // Cancel connection

'//  Function signature for the callback to delete the memory allocated by the creds
'typedef DWORD (*PFNDAVAUTHCALLBACK_FREECRED)(__in PVOID pbuffer);

'//  Function signature for the Callback that will harvest the credentials
'typedef DWORD (*PFNDAVAUTHCALLBACK)(
'    __in LPWSTR lpwzServerName,     // Server Name
'    __in LPWSTR lpwzRemoteName,     // Remote Name
'    __in DWORD  dwAuthScheme,       // Bitmap of DAV_AUTHN_SCHEME* values
'    __in DWORD  dwFlags,            // The flags that was passed to NPADDConnection
'    __inout PDAV_CALLBACK_CRED pCallbackCred,       // Creds collected by the callback
'    __inout AUTHNEXTSTEP *NextStep,                 // Next step for DavClnt
'    __out PFNDAVAUTHCALLBACK_FREECRED *pFreeCred    // Callback to free the memory allocated for creds by the callback
');

'FUNCTION DAVAUTHCALLBACK ( _
'   BYREF lpwzServerName AS WSTRINGZ _                   ' __in LPWSTR lpwzServerName // Server Name
' , BYREF lpwzRemoteName AS WSTRINGZ _                   ' __in LPWSTR lpwzRemoteName // Remote Name
' , BYVAL dwAuthScheme AS DWORD _                        ' __in DWORD  dwAuthScheme // Bitmap of DAV_AUTHN_SCHEME* values
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags // The flags that was passed to NPADDConnection
' , BYREF pCallbackCred AS DAV_CALLBACK_CRED _           ' __inout PDAV_CALLBACK_CRED pCallbackCred // Creds collected by the callback
' , BYREF NextStep AS LONG _                             ' __inout AUTHNEXTSTEP *NextStep // Next step for DavClnt
' , BYREF pFreeCred AS DWORD _                           ' __out PFNDAVAUTHCALLBACK_FREECRED *pFreeCred // Callback to free the memory allocated for creds by the callback
' ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavAddConnection IMPORT "Netapi32.dll" ALIAS "DavAddConnection" ( _
   BYREF ConnectionHandle AS DWORD _                    ' __inout HANDLE *ConnectionHandle
 , BYREF RemoteName AS WSTRINGZ _                       ' __in LPCWSTR RemoteName
 , BYREF UserName AS WSTRINGZ _                         ' __in_opt LPCWSTR UserName
 , BYREF Password AS WSTRINGZ _                         ' __in_opt LPCWSTR Password
 , BYVAL ClientCert AS BYTE PTR _                       ' __in_bcount(CertSize) PBYTE ClientCert
 , BYVAL CertSize AS DWORD _                            ' __in DWORD CertSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavDeleteConnection IMPORT "Netapi32.dll" ALIAS "DavDeleteConnection" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in HANDLE ConnectionHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavGetUNCFromHTTPPath IMPORT "Netapi32.dll" ALIAS "DavGetUNCFromHTTPPath" ( _
   BYREF HttpPath AS WSTRINGZ _                         ' __in LPCWSTR  HttpPath
 , BYVAL UncPath AS DWORD _                             ' __out_ecount(*lpSize) LPWSTR UncPath
 , BYREF lpSize AS DWORD _                              ' __inout LPDWORD lpSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavGetHTTPFromUNCPath IMPORT "Netapi32.dll" ALIAS "DavGetHTTPFromUNCPath" ( _
   BYREF UncPath AS WSTRINGZ _                          ' __in LPCWSTR  UncPath
 , BYVAL HttpPath AS DWORD _                            ' __out_ecount(*lpSize) LPWSTR HttpPath
 , BYREF lpSize AS DWORD _                              ' __inout LPDWORD lpSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavGetTheLockOwnerOfTheFile IMPORT "Davclnt.dll" ALIAS "DavGetTheLockOwnerOfTheFile" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in LPCWSTR FileName
 , BYVAL LockOwnerName AS DWORD _                       ' __out_bcount_opt(*LockOwnerNameLengthInBytes) PWSTR LockOwnerName
 , BYREF LockOwnerNameLengthInBytes AS DWORD _          ' __inout PULONG LockOwnerNameLengthInBytes
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavGetExtendedError IMPORT "Netapi32.dll" ALIAS "DavGetExtendedError" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF ExtError AS DWORD _                            ' __out DWORD *ExtError
 , BYVAL ExtErrorString AS DWORD _                      ' __out_ecount(*cChSize) LPWSTR ExtErrorString
 , BYREF cChSize AS DWORD _                             ' __inout DWORD *cChSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavFlushFile IMPORT "Netapi32.dll" ALIAS "DavFlushFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavInvalidateCache IMPORT "Davclnt.dll" ALIAS "DavInvalidateCache" ( _
   BYREF URLName AS WSTRINGZ _                          ' __in LPWSTR URLName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavCancelConnectionsToServer IMPORT "Davclnt.dll" ALIAS "DavCancelConnectionsToServer" ( _
   BYREF URLName AS WSTRINGZ _                          ' __in LPWSTR lpName
 , BYVAL fForce AS LONG _                               ' __in BOOL fForce
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DavRegisterAuthCallback IMPORT "Davclnt.dll" ALIAS "DavRegisterAuthCallback" ( _
   BYVAL pCallBack AS DWORD _                           ' __in PFNDAVAUTHCALLBACK CallBack
 , BYVAL Version AS DWORD _                             ' __in ULONG Version
 ) AS DWORD                                             ' OPAQUE_HANDLE

DECLARE SUB DavUnregisterAuthCallback IMPORT "Davclnt.dll" ALIAS "DavUnregisterAuthCallback" ( _
   BYVAL hCallback AS DWORD _                           ' __in OPAQUE_HANDLE hCallback
 )                                                      ' VOID
