' ########################################################################################
' Microsoft Windows
' File: SoftPub.inc
' Contents: Microsoft Internet Security Authenticode Policy Provider
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SOFTPUB_INC = 1

#INCLUDE ONCE "wintrust.inc"

'#include <pshpack8.h>

'//////////////////////////////////////////////////////////////////////////////
'//
'// Softpub Policy Provider defines
'//----------------------------------------------------------------------------
'//  The following are definitions of the Microsoft Authenticode Policy Provider
'//  (WINTRUST.DLL's Policy Provider)
'//

$$SP_POLICY_PROVIDER_DLL_NAME         = "WINTRUST.DLL"$$

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_ACTION_GENERIC_VERIFY_V2 Guid  (Authenticode)
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to verify the
'//  authenticity of a file/object using the Microsoft Authenticode
'//  Policy Provider,
'//
'//          {00AAC56B-CD44-11d0-8CC2-00C04FC295EE}
'//

$WINTRUST_ACTION_GENERIC_VERIFY_V2 = GUID$("{00AAC56B-CD44-11D0-8CC2-00C04FC295EE}")

$$SP_INIT_FUNCTION                    = "SoftpubInitialize"$$
$$SP_OBJTRUST_FUNCTION                = "SoftpubLoadMessage"$$
$$SP_SIGTRUST_FUNCTION                = "SoftpubLoadSignature"$$
$$SP_CHKCERT_FUNCTION                 = "SoftpubCheckCert"$$
$$SP_FINALPOLICY_FUNCTION             = "SoftpubAuthenticode"$$
$$SP_CLEANUPPOLICY_FUNCTION           = "SoftpubCleanup"$$

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_ACTION_TRUSTPROVIDER_TEST (Authenticode TEST)
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to dump
'//  the CRYPT_PROVIDER_DATA structure to a file after calling the
'//  Authenticode Policy Provider.
'//
'//          {573E31F8-DDBA-11d0-8CCB-00C04FC295EE}
'//
$WINTRUST_ACTION_TRUSTPROVIDER_TEST = GUID$("{573E31F8-DDBA-11D0-8CCB-00C04FC295EE}")

$$SP_TESTDUMPPOLICY_FUNCTION_TEST     = "SoftpubDumpStructure"$$


'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_ACTION_GENERIC_CERT_VERIFY
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to verify
'//  a certificate chain only.  This is only valid when passing in a
'//  certificate context in the WinVerifyTrust input structures.
'//
'//          {189A3842-3041-11d1-85E1-00C04FC295EE}
'//
$WINTRUST_ACTION_GENERIC_CERT_VERIFY = GUID$("{189A3842-3041-11D1-85E1-00C04FC295EE}")

$$SP_GENERIC_CERT_INIT_FUNCTION       = "SoftpubDefCertInit"$$


'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_ACTION_GENERIC_CHAIN_VERIFY
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to verify
'//  certificate chains created from any object type: file, cert, signer, ...
'//  A callback is provided to implement the final chain policy using
'//  the chain context for each signer and counter signer.
'//
'//          {fc451c16-ac75-11d1-b4b8-00c04fb66ea0}
'//
$WINTRUST_ACTION_GENERIC_CHAIN_VERIFY = GUID$("{FC451C16-AC75-11D1-B4B8-00C04FB66EA0}")

$$GENERIC_CHAIN_FINALPOLICY_FUNCTION      = "GenericChainFinalProv"$$
$$GENERIC_CHAIN_CERTTRUST_FUNCTION        = "GenericChainCertificateTrust"$$

' // Size = 4 bytes
UNION WTD_GENERIC_CHAIN_POLICY_SIGNER_INFO_UNION DWORD
   cbStruct AS DWORD   ' DWORD
   cbSize   AS DWORD   ' DWORD
END UNION

' // Size = 28 bytes
TYPE WTD_GENERIC_CHAIN_POLICY_SIGNER_INFO DWORD
   WTD_GENERIC_CHAIN_POLICY_SIGNER_INFO_UNION
   pChainContext    AS CERT_CHAIN_CONTEXT PTR                     ' PCCERT_CHAIN_CONTEXT
   dwSignerType     AS DWORD                                      ' DWORD
   pMsgSignerInfo   AS CMSG_SIGNER_INFO PTR                       ' PCMSG_SIGNER_INFO
   dwError          AS DWORD                                      ' DWORD
   cCounterSigner   AS DWORD                                      ' DWORD
   rgpCounterSigner AS WTD_GENERIC_CHAIN_POLICY_SIGNER_INFO PTR   ' PWTD_GENERIC_CHAIN_POLICY_SIGNER_INFO
END TYPE

'typedef HRESULT (WINAPI *PFN_WTD_GENERIC_CHAIN_POLICY_CALLBACK)(
'    IN PCRYPT_PROVIDER_DATA pProvData,
'    IN DWORD dwStepError,
'    IN DWORD dwRegPolicySettings,
'    IN DWORD cSigner,
'    IN PWTD_GENERIC_CHAIN_POLICY_SIGNER_INFO *rgpSigner,
'    IN void *pvPolicyArg
'    );

'FUNCTION WTD_GENERIC_CHAIN_POLICY_CALLBACK ( _
'   BYREF pProvData AS CRYPT_PROVIDER_DATA _
' , BYVAL dwStepError AS DWORD _
' , BYVAL dwRegPolicySettings AS DWORD _
' , BYVAL cSigner AS DWORD _
' , BYREF rgpSigner AS WTD_GENERIC_CHAIN_POLICY_SIGNER_INFO _
' , BYVAL pvPolicyArg AS DWORD _
' ) AS LONG

'// The fields in the following data structure are passed to
'// CertGetCertificateChain().
' // Size = 4 bytes
UNION WTD_GENERIC_CHAIN_POLICY_CREATE_INFO_UNION DWORD
   cbStruct AS DWORD   ' DWORD
   cbSize   AS DWORD   ' DWORD
END UNION

' // Size = 20 bytes
TYPE WTD_GENERIC_CHAIN_POLICY_CREATE_INFO DWORD
   WTD_GENERIC_CHAIN_POLICY_CREATE_INFO_UNION
   hChainEngine AS DWORD                 ' HCERTCHAINENGINE
   pChainPara   AS CERT_CHAIN_PARA PTR   ' PCERT_CHAIN_PARA
   dwFlags      AS DWORD                 ' DWORD
   pvReserved   AS DWORD                 ' void
END TYPE

' // Size = 4 bytes
UNION WTD_GENERIC_CHAIN_POLICY_DATA_UNION DWORD
   cbStruct AS DWORD   ' DWORD
   cbSize   AS DWORD   ' DWORD
END UNION

' // Size = 20 bytes
TYPE WTD_GENERIC_CHAIN_POLICY_DATA DWORD
   WTD_GENERIC_CHAIN_POLICY_DATA_UNION
   pSignerChainInfo        AS WTD_GENERIC_CHAIN_POLICY_CREATE_INFO PTR   ' PWTD_GENERIC_CHAIN_POLICY_CREATE_INFO
   pCounterSignerChainInfo AS WTD_GENERIC_CHAIN_POLICY_CREATE_INFO PTR   ' PWTD_GENERIC_CHAIN_POLICY_CREATE_INFO
   pfnPolicyCallback       AS DWORD                                      ' PFN_WTD_GENERIC_CHAIN_POLICY_CALLBACK
   pvPolicyArg             AS DWORD                                      ' void
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'//
'// HTTPSPROV_ACTION Guid  (Authenticode add-on)
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to verify the
'//  SSL/PCT connections through IE.
'//
'//          {573E31F8-AABA-11d0-8CCB-00C04FC295EE}
'//
$HTTPSPROV_ACTION = GUID$("{573E31F8-AABA-11D0-8CCB-00C04FC295EE}")

$$HTTPS_FINALPOLICY_FUNCTION          = "HTTPSFinalProv"$$
$$HTTPS_CHKCERT_FUNCTION              = "HTTPSCheckCertProv"$$
$$HTTPS_CERTTRUST_FUNCTION            = "HTTPSCertificateTrust"$$


'//////////////////////////////////////////////////////////////////////////////
'//
'// OFFICESIGN_ACTION_VERIFY Guid  (Authenticode add-on)
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to verify the
'//  authenticity of a Structured Storage file using the Microsoft Office
'//  Authenticode add-on Policy Provider,
'//
'//          {5555C2CD-17FB-11d1-85C4-00C04FC295EE}
'//
$OFFICESIGN_ACTION_VERIFY = GUID$("{5555C2CD-17FB-11D1-85C4-00C04FC295EE}")

$$OFFICE_POLICY_PROVIDER_DLL_NAME             = $$SP_POLICY_PROVIDER_DLL_NAME
$$OFFICE_INITPROV_FUNCTION                    = "OfficeInitializePolicy"$$
$$OFFICE_CLEANUPPOLICY_FUNCTION               = "OfficeCleanupPolicy"$$

'//////////////////////////////////////////////////////////////////////////////
'//
'// DRIVER_ACTION_VERIFY Guid  (Authenticode add-on)
'//----------------------------------------------------------------------------
'//  Assigned to the pgActionID parameter of WinVerifyTrust to verify the
'//  authenticity of a WHQL signed driver.  This is an Authenticode add-on
'//  Policy Provider,
'//
'//          {F750E6C3-38EE-11d1-85E5-00C04FC295EE}
'//
$DRIVER_ACTION_VERIFY = GUID$("{F750E6C3-38EE-11D1-85E5-00C04FC295EE}")

$$DRIVER_INITPROV_FUNCTION                    = "DriverInitializePolicy"$$
$$DRIVER_FINALPOLPROV_FUNCTION                = "DriverFinalPolicy"$$
$$DRIVER_CLEANUPPOLICY_FUNCTION               = "DriverCleanupPolicy"$$

' // Size = 8 bytes
TYPE DRIVER_VER_MAJORMINOR DWORD
   dwMajor AS DWORD   ' DWORD
   dwMinor AS DWORD   ' DWORD
END TYPE

' // Size = 1088 bytes
TYPE DRIVER_VER_INFO DWORD
   cbStruct            AS DWORD                   ' DWORD
   dwReserved1         AS DWORD                   ' ULONG_PTR
   dwReserved2         AS DWORD                   ' ULONG_PTR
   dwPlatform          AS DWORD                   ' DWORD
   dwVersion           AS DWORD                   ' DWORD
   wszVersion          AS WSTRINGZ * %MAX_PATH    ' WCHAR[MAX_PATH]
   wszSignedBy         AS WSTRINGZ * %MAX_PATH    ' WCHAR[MAX_PATH]
   pcSignerCertContext AS CERT_CONTEXT PTR        ' PCCERT_CONTEXT
   sOSVersionLow       AS DRIVER_VER_MAJORMINOR   ' DRIVER_VER_MAJORMINOR
   sOSVersionHigh      AS DRIVER_VER_MAJORMINOR   ' DRIVER_VER_MAJORMINOR
   dwBuildNumberLow    AS DWORD                   ' DWORD
   dwBuildNumberHigh   AS DWORD                   ' DWORD
END TYPE

'#include <poppack.h>
