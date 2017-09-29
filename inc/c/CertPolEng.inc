' ########################################################################################
' Microsoft Windows
' File: CertPolEng.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTPOLENG_INC = 1

#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "schannel.inc"
#INCLUDE ONCE "Ntsecpkg.inc"

DECLARE FUNCTION PstGetTrustAnchors IMPORT "Certpoleng.dll" ALIAS "PstGetTrustAnchors" ( _
   BYREF pTargetName AS UNICODE_STRING _                ' __in PUNICODE_STRING pTargetName
 , BYVAL cCriteria AS DWORD _                           ' __in DWORD cCriteria
 , BYREF rgpCriteria AS CERT_SELECT_CRITERIA _          ' __in PCCERT_SELECT_CRITERIA rgpCriteria
 , BYREF ppTrustedIssuers AS SecPkgContext_IssuerListInfoEx _ ' __out PSecPkgContext_IssuerListInfoEx* ppTrustedIssuers
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION PstGetCertificates IMPORT "Certpoleng.dll" ALIAS "PstGetCertificates" ( _
   BYREF pTargetName AS UNICODE_STRING _                ' __in PUNICODE_STRING pTargetName
 , BYVAL cCriteria AS DWORD _                           ' __in DWORD cCriteria
 , BYREF rgpCriteria AS CERT_SELECT_CRITERIA _          ' __in PCCERT_SELECT_CRITERIA rgpCriteria
 , BYVAL bIsClient AS LONG _                            ' __in BOOL bIsClient
 , BYREF pdwCertChainContextCount AS DWORD _            ' __out PDWORD pdwCertChainContextCount
 , BYREF ppCertChainContexts AS CERT_CHAIN_CONTEXT _    ' __out PCCERT_CHAIN_CONTEXT** ppCertChainContexts
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION PstAcquirePrivateKey IMPORT "Certpoleng.dll" ALIAS "PstAcquirePrivateKey" ( _
   BYREF pCert AS CERT_CONTEXT _                        ' __in PCCERT_CONTEXT pCert
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION PstValidate IMPORT "Certpoleng.dll" ALIAS "PstValidate" ( _
   BYREF pTargetName AS UNICODE_STRING _                ' __in_opt PUNICODE_STRING pTargetName
 , BYVAL bIsClient AS LONG _                            ' __in BOOL bIsClient
 , BYREF pRequestedIssuancePolicy AS CERT_USAGE_MATCH _ ' __in_opt CERT_USAGE_MATCH* pRequestedIssuancePolicy
 , BYVAL phAdditionalCertStore AS DWORD _               ' __in_opt HCERTSTORE* phAdditionalCertStore
 , BYREF pCert AS CERT_CONTEXT _                        ' __in PCCERT_CONTEXT pCert
 , OPTIONAL BYREF pProvGUID AS GUID _                   ' __out_opt GUID* pProvGUID
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION PstMapCertificate IMPORT "Certpoleng.dll" ALIAS "PstMapCertificate" ( _
   BYREF pCert AS CERT_CONTEXT _                        ' __in PCCERT_CONTEXT pCert
 , BYREF pTokenInformationType AS LONG _                ' __out LSA_TOKEN_INFORMATION_TYPE* pTokenInformationType
 , BYREF ppTokenInformation AS ANY _                    ' __out PVOID* ppTokenInformation
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION PstGetUserNameForCertificate IMPORT "Certpoleng.dll" ALIAS "PstGetUserNameForCertificate" ( _
   BYREF pCertContext AS CERT_CONTEXT _                 ' __in PCCERT_CONTEXT pCertContext
 , BYREF UserName AS UNICODE_STRING _                   ' __out PUNICODE_STRING UserName
 ) AS LONG                                              ' NTSTATUS
