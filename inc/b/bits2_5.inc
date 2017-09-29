' ########################################################################################
' Microsoft Windows
' File: bits2_5.inc
' Contents: IBackgroundCopyJobHttpOptions interface
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITS2_5_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "bits.inc"
#INCLUDE ONCE "bits1_5.inc"
#INCLUDE ONCE "bits2_0.inc"

$CLSID_BackgroundCopyManager2_5 = GUID$("{03CA98D6-FF5D-49B8-ABC6-03DD84127020}")

' ########################################################################################
' IBackgroundCopyJobHttpOptions interface
' IID = F1BD1079-9F01-4BDC-8036-F09B70095066
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyJobHttpOptions_INTERFACE_DEFINED)
   %IBackgroundCopyJobHttpOptions_INTERFACE_DEFINED = 1

' enum BG_CERT_STORE_LOCATION
MACRO BG_CERT_STORE_LOCATION_ENUM = LONG
%BG_CERT_STORE_LOCATION_CURRENT_USER               = 0
%BG_CERT_STORE_LOCATION_LOCAL_MACHINE              = %BG_CERT_STORE_LOCATION_CURRENT_USER               + 1
%BG_CERT_STORE_LOCATION_CURRENT_SERVICE            = %BG_CERT_STORE_LOCATION_LOCAL_MACHINE              + 1
%BG_CERT_STORE_LOCATION_SERVICES                   = %BG_CERT_STORE_LOCATION_CURRENT_SERVICE            + 1
%BG_CERT_STORE_LOCATION_USERS                      = %BG_CERT_STORE_LOCATION_SERVICES                   + 1
%BG_CERT_STORE_LOCATION_CURRENT_USER_GROUP_POLICY  = %BG_CERT_STORE_LOCATION_USERS                      + 1
%BG_CERT_STORE_LOCATION_LOCAL_MACHINE_GROUP_POLICY = %BG_CERT_STORE_LOCATION_CURRENT_USER_GROUP_POLICY  + 1
%BG_CERT_STORE_LOCATION_LOCAL_MACHINE_ENTERPRISE   = %BG_CERT_STORE_LOCATION_LOCAL_MACHINE_GROUP_POLICY + 1

$IID_IBackgroundCopyJobHttpOptions = GUID$("{F1BD1079-9F01-4BDC-8036-F09B70095066}")

INTERFACE IBackgroundCopyJobHttpOptions $IID_IBackgroundCopyJobHttpOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetClientCertificateByID ( _                  ' VTable offset = 12
     BYVAL StoreLocation AS BG_CERT_STORE_LOCATION_ENUM _ ' __in BG_CERT_STORE_LOCATION StoreLocation
   , BYREF StoreName AS WSTRINGZ _                      ' __in LPCWSTR StoreName
   , BYVAL pCertHashBlob AS BYTE PTR _                  ' __in byte *pCertHashBlob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClientCertificateByName ( _                ' VTable offset = 16
     BYVAL StoreLocation AS BG_CERT_STORE_LOCATION_ENUM _ ' __in BG_CERT_STORE_LOCATION StoreLocation
   , BYREF StoreName AS WSTRINGZ _                      ' __in LPCWSTR StoreName
   , BYREF SubjectName AS WSTRINGZ _                    ' __in LPCWSTR SubjectName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveClientCertificate ( _                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClientCertificate ( _                      ' VTable offset = 24
     BYREF pStoreLocation AS BG_CERT_STORE_LOCATION_ENUM _ ' __out BG_CERT_STORE_LOCATION *pStoreLocation
   , BYREF pStoreName AS DWORD _                        ' __out LPWSTR *pStoreName
   , BYREF ppCertHashBlob AS DWORD _                    ' __out byte **ppCertHashBlob
   , BYREF pSubjectName AS DWORD _                      ' __out LPWSTR *pSubjectName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCustomHeaders ( _                          ' VTable offset = 28
     BYREF RequestHeaders AS WSTRINGZ _                 ' __in LPCWSTR RequestHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomHeaders ( _                          ' VTable offset = 32
     BYREF pRequestHeaders AS DWORD _                   ' __out LPWSTR *pRequestHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSecurityFlags ( _                          ' VTable offset = 36
     BYVAL Flags AS DWORD _                             ' __in ULONG Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityFlags ( _                          ' VTable offset = 40
     BYREF pFlags AS DWORD _                            ' __out ULONG *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyJobHttpOptions_INTERFACE_DEFINED__ */

%BG_SSL_ENABLE_CRL_CHECK                     = &H0001
%BG_SSL_IGNORE_CERT_CN_INVALID               = &H0002
%BG_SSL_IGNORE_CERT_DATE_INVALID             = &H0004
%BG_SSL_IGNORE_UNKNOWN_CA                    = &H0008
%BG_SSL_IGNORE_CERT_WRONG_USAGE              = &H0010
%BG_HTTP_REDIRECT_POLICY_MASK                = &H0700
%BG_HTTP_REDIRECT_POLICY_ALLOW_SILENT        = &H0000
%BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT        = &H0100
%BG_HTTP_REDIRECT_POLICY_DISALLOW            = &H0200
%BG_HTTP_REDIRECT_POLICY_ALLOW_HTTPS_TO_HTTP = &H0800

#INCLUDE ONCE "bits3_0.inc"
