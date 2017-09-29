' ########################################################################################
' Microsoft Windows
' File: AdsHlp.inc
' Contents: Public header file for all oleds client code
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADSHLP_INC = 1

#INCLUDE ONCE "iads.inc"

DECLARE FUNCTION ADsGetObject IMPORT "Activeds.dll" ALIAS "ADsGetObject" ( _
   BYREF lpszPathName AS WSTRINGZ _                     ' __in LPCWSTR lpszPathName
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppObject AS ANY _                              ' __out VOID** ppObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsBuildEnumerator IMPORT "Activeds.dll" ALIAS "ADsBuildEnumerator" ( _
   BYVAL pADsContainer AS IADsContainer _               ' __in IADsContainer *pADsContainer
 , BYREF ppEnumVariant AS IEnumVARIANT _                ' __out IEnumVARIANT **ppEnumVariant
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsFreeEnumerator IMPORT "Activeds.dll" ALIAS "ADsFreeEnumerator" ( _
   BYVAL pEnumVariant AS IEnumVARIANT _                 ' __in IEnumVARIANT *pEnumVariant
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsEnumerateNext IMPORT "Activeds.dll" ALIAS "ADsEnumerateNext" ( _
   BYVAL pEnumVariant AS IEnumVARIANT _                 ' __in IEnumVARIANT *pEnumVariant
 , BYVAL cElements AS DWORD _                           ' __in ULONG cElements
 , BYREF pvar AS VARIANT _                              ' __out VARIANT FAR *pvar
 , BYREF pcElementsFetched AS DWORD _                   ' __out ULONG FAR *pcElementsFetched
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsBuildVarArrayStr IMPORT "Activeds.dll" ALIAS "ADsBuildVarArrayStr" ( _
   BYREF lppPathNames AS DWORD _                        ' __in LPWSTR * lppPathNames
 , BYVAL dwPathNames AS DWORD _                         ' __in DWORD dwPathNames
 , BYREF pVar AS VARIANT _                              ' __out VARIANT * pVar
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsBuildVarArrayInt IMPORT "Activeds.dll" ALIAS "ADsBuildVarArrayInt" ( _
   BYREF lpdwObjectTypes AS DWORD _                     ' __in LPDWORD lpdwObjectTypes
 , BYVAL dwObjectTypes AS DWORD _                       ' __in DWORD dwObjectTypes
 , BYREF pVar AS VARIANT _                              ' __out VARIANT * pVar
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsOpenObject IMPORT "Activeds.dll" ALIAS "ADsOpenObject" ( _
   BYREF lpszPathName AS WSTRINGZ _                     ' __in LPCWSTR lpszPathName
 , BYREF lpszUserName AS WSTRINGZ _                     ' __in LPCWSTR lpszUserName
 , BYREF lpszPassword AS WSTRINGZ _                     ' __in LPCWSTR lpszPassword
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD  dwReserved
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppObject AS ANY _                              ' __out void FAR * FAR * ppObject
 ) AS LONG                                              ' HRESULT

'//
'// Helper functions for extended error support
'//

DECLARE FUNCTION ADsGetLastError IMPORT "Activeds.dll" ALIAS "ADsGetLastError" ( _
   BYREF lpError AS DWORD _                             ' __out LPDWORD lpError
 , BYREF lpErrorBuf AS WSTRINGZ _                       ' __out LPWSTR lpErrorBuf
 , BYVAL dwErrorBufLen AS DWORD _                       ' __in DWORD dwErrorBufLen
 , BYREF lpNameBuf AS WSTRINGZ _                        ' __out LPWSTR lpNameBuf
 , BYVAL dwNameBufLen AS DWORD _                        ' __in DWORD dwNameBufLen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ADsSetLastError IMPORT "Activeds.dll" ALIAS "ADsSetLastError" ( _
   BYVAL dwErr AS DWORD _                               ' __in DWORD dwErr
 , BYREF pszError AS WSTRINGZ _                         ' __in LPCWSTR pszError
 , BYREF pszProvider AS WSTRINGZ _                      ' __in LPCWSTR pszProvider
 ) AS LONG                                              ' HRESULT

' Obsolete
DECLARE SUB ADsFreeAllErrorRecords IMPORT "Activeds.dll" ALIAS "ADsFreeAllErrorRecords" ( _
 )                                                      ' VOID

DECLARE FUNCTION AllocADsMem IMPORT "Activeds.dll" ALIAS "AllocADsMem" ( _
   BYVAL cb AS DWORD _                                  ' __in DWORD cb
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION FreeADsMem IMPORT "Activeds.dll" ALIAS "FreeADsMem" ( _
   BYVAL pMem AS DWORD _                                ' __in LPVOID pMem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReallocADsMem IMPORT "Activeds.dll" ALIAS "ReallocADsMem" ( _
   BYVAL pOldMem AS DWORD _                             ' __in LPVOID pOldMem
 , BYVAL cbOld AS DWORD _                               ' __in DWORD cbOld
 , BYVAL cbNew AS DWORD _                               ' __in DWORD cbNew
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION AllocADsStr IMPORT "Activeds.dll" ALIAS "AllocADsStr" ( _
   BYREF pStr AS WSTRINGZ _                             ' __in LPCWSTR pStr
 ) AS DWORD                                             ' LPWSTR

DECLARE FUNCTION FreeADsStr IMPORT "Activeds.dll" ALIAS "FreeADsStr" ( _
   BYREF pStr AS WSTRINGZ _                             ' __in LPCWSTR pStr
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReallocADsStr IMPORT "Activeds.dll" ALIAS "ReallocADsStr" ( _
   BYREF ppStr AS DWORD _                               ' __out LPWSTR *ppStr
 , BYREF pStr AS WSTRINGZ _                             ' __in LPWSTR pStr
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ADsEncodeBinaryData IMPORT "Activeds.dll" ALIAS "ADsEncodeBinaryData" ( _
   BYVAL pbSrcData AS BYTE PTR _                        ' __in PBYTE pbSrcData
 , BYVAL dwSrcLen AS DWORD _                            ' __in DWORD dwSrcLen
 , BYREF ppszDestData AS DWORD _                        ' __out LPWSTR *ppszDestData
 ) AS LONG                                              ' HRESULT

' Obsolete
DECLARE FUNCTION ADsDecodeBinaryData IMPORT "Activeds.dll" ALIAS "ADsDecodeBinaryData" ( _
   BYREF szSrcData AS WSTRINGZ _                        ' __in LPCWSTR szSrcData
 , BYVAL ppbDestData AS BYTE PTR _                      ' __out PBYTE *ppbDestData
 , BYREF pdwDestLen AS DWORD _                          ' __out ULONG *pdwDestLen
 ) AS LONG                                              ' HRESULT

' Obsolete
DECLARE FUNCTION PropVariantToAdsType IMPORT "Activeds.dll" ALIAS "PropVariantToAdsType" ( _
   BYREF pVariant AS VARIANT _                          ' __in VARIANT * pVariant
 , BYVAL dwNumVariant AS DWORD _                        ' __in DWORD dwNumVariant
 , BYREF ppAdsValues AS ADSVALUE _                      ' __out PADSVALUE *ppAdsValues
 , BYREF pdwNumValues AS DWORD _                        ' __out PDWORD pdwNumValues
 ) AS LONG                                              ' HRESULT

' Obsolete
DECLARE FUNCTION AdsTypeToPropVariant IMPORT "Activeds.dll" ALIAS "AdsTypeToPropVariant" ( _
   BYREF ppAdsValues AS ADSVALUE _                      ' __out PADSVALUE *ppAdsValues
 , BYVAL dwNumValues AS DWORD _                         ' __in DWORD dwNumValues
 , BYREF pVariant AS VARIANT _                          ' __out VARIANT * pVariant
 ) AS LONG                                              ' HRESULT

' Obsolete
DECLARE FUNCTION AdsFreeAdsValues IMPORT "Activeds.dll" ALIAS "AdsFreeAdsValues" ( _
   BYREF ppAdsValues AS ADSVALUE _                      ' __out PADSVALUE *ppAdsValues
 , BYVAL dwNumValues AS DWORD _                         ' __in DWORD dwNumValues
 ) AS LONG                                              ' HRESULT

'//
'// Helper routines to convert IADsSecurityDescriptor to a binary
'// security descriptor and also to convert a binary SD to
'// IADsSecurityDescriptor.
'//

DECLARE FUNCTION BinarySDToSecurityDescriptor IMPORT "Activeds.dll" ALIAS "BinarySDToSecurityDescriptor" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF pVarsec AS VARIANT _                           ' __out VARIANT *pVarsec
 , BYREF pszServerName AS WSTRINGZ _                    ' __in LPCWSTR pszServerName
 , BYREF userName AS WSTRINGZ _                         ' __in LPCWSTR userName
 , BYREF passWord AS WSTRINGZ _                         ' __in LPCWSTR passWord
 , BYVAL dwFlags As DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SecurityDescriptorToBinarySD IMPORT "Activeds.dll" ALIAS "SecurityDescriptorToBinarySD" ( _
   BYVAL vVarSecDes AS VARIANT _                        ' __in VARIANT vVarSecDes
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR  pSecurityDescriptor
 , BYREF pdwSDLength AS DWORD _                         ' __out PDWORD pdwSDLength
 , BYREF pszServerName AS WSTRINGZ _                    ' __in LPCWSTR pszServerName
 , BYREF userName AS WSTRINGZ _                         ' __in LPCWSTR userName
 , BYREF passWord AS WSTRINGZ _                         ' __in LPCWSTR passWord
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
