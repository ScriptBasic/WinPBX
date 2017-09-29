' ########################################################################################
' Microsoft Windows
' File: QosPol.inc
' Contents: QOS policy elements
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%QOSPOL_INC = 1

%PE_TYPE_APPID      = 3      ' // policy element contains Application Identity

'// Policy Location attribute carries sub application attributes
%PE_ATTRIB_TYPE_POLICY_LOCATOR          = 1

%POLICY_LOCATOR_SUB_TYPE_ASCII_DN       = 1
%POLICY_LOCATOR_SUB_TYPE_UNICODE_DN     = 2
%POLICY_LOCATOR_SUB_TYPE_ASCII_DN_ENC   = 3
%POLICY_LOCATOR_SUB_TYPE_UNICODE_DN_ENC = 4


'// Credentials attribute carries the application identity
%PE_ATTRIB_TYPE_CREDENTIAL        = 2

%CREDENTIAL_SUB_TYPE_ASCII_ID     = 1
%CREDENTIAL_SUB_TYPE_UNICODE_ID   = 2
%CREDENTIAL_SUB_TYPE_KERBEROS_TKT = 3
%CREDENTIAL_SUB_TYPE_X509_V3_CERT = 4
%CREDENTIAL_SUB_TYPE_PGP_CERT     = 5


'// Identity Policy Element attribute structure
' // Size = 8 bytes
TYPE IDPE_ATTR BYTE
   PeAttribLength   AS WORD   ' USHORT
   PeAttribType     AS BYTE   ' UCHAR // Use the #defines from above
   PeAttribSubType  AS BYTE   ' UCHAR // Use the #defines from above
   PeAttribValue(3) AS BYTE   ' UCHAR
END TYPE

'#define IDPE_ATTR_HDR_LEN    (sizeof(USHORT)+sizeof(UCHAR)+sizeof(UCHAR))
%IDPE_ATTR_HDR_LEN = 2 + 1 + 1

'#define RSVP_BYTE_MULTIPLE(x)       (((x+3) / 4) * 4)
MACRO RSVP_BYTE_MULTIPLE(x) = (((x+3) \ 4) * 4)
