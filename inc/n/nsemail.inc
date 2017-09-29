' ########################################################################################
' Microsoft Windows
' File: nsemail.inc
' Contents: NS_EMAIL namespace related definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NSEMAIL_INC = 1

' enum NAPI_PROVIDER_TYPE
%ProviderType_Application = 1
%ProviderType_Service     = 2

' enum NAPI_PROVIDER_LEVEL
%ProviderLevel_None       = 0
%ProviderLevel_Secondary  = 1
%ProviderLevel_Primary    = 2

'//-----------------------------------------------------------------------------
'//
'// Layout of Installation Blob for Email Naming NSPv2 Providers:
'//
'// +-------------------------------------------------------------------------+
'// |                     NAPI_PROVIDER_INSTALLATION_BLOB                     |
'// | - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
'// | dwVersion                                                               |
'// | dwProviderType                                                          |
'// | fSupportsWildCard                                                       |
'// | cDomains (equal to N in this example)                                   |
'// | OffsetFirstDomain (aligned offset of NAPI_DOMAIN_DESCRIPTION_BLOB # 1)  |
'// | +---------------------------------------------------------------------+ |
'// | |                   NAPI_DOMAIN_DESCRIPTION_BLOB # 1                  | |
'// | | - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - + |
'// | | AuthLevel                                                           | |
'// | | cchDomainName                                                       | |
'// | | OffsetNextDomainDescription (aligned offset of Domain Blob # 2)     | |
'// | | OffsetThisDomainName (aligned offset of Domain Name 1)              | |
'// | +---------------------------------------------------------------------+ |
'// | +---------------------------------------------------------------------+ |
'// | |                   NAPI_DOMAIN_DESCRIPTION_BLOB # 2                  | |
'// | | - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - + |
'// | | AuthLevel                                                           | |
'// | | cchDomainName                                                       | |
'// | | OffsetNextDomainDescription (aligned offset of Domain Blob # 3)     | |
'// | | OffsetThisDomainName (aligned offset of Domain Name 2)              | |
'// | +---------------------------------------------------------------------+ |
'// | ... ... ...                                                             |
'// | ... ... ...                                                             |
'// | ... ... ...                                                             |
'// | +---------------------------------------------------------------------+ |
'// | |                   NAPI_DOMAIN_DESCRIPTION_BLOB # N                  | |
'// | | - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - + |
'// | | AuthLevel                                                           | |
'// | | cchDomainName                                                       | |
'// | | OffsetNextDomainDescription (should be 0 if N is the last domain)   | |
'// | | OffsetThisDomainName (aligned offset of Domain Name N)              | |
'// | +---------------------------------------------------------------------+ |
'// | Domain Name 1                                                           |
'// | Domain Name 2                                                           |
'// | ... ... ...                                                             |
'// | Domain Name N                                                           |
'// +-------------------------------------------------------------------------+
'//
'// Notes: - The above NAPI_PROVIDER_INSTALLATION_BLOB must be passed to
'//          WSCInstallNameSpaceEx encapsulated in a winsock2.h's BLOB
'//          (typedef struct _BLOB { ULONG  cbSize; BYTE * pBlobData;} BLOB;)
'//          by storing its address in pBlobData, and its total size in
'//          cbSize.
'//        - The NAPI_PROVIDER_INSTALLATION_BLOB must be at an address at
'//          least 4-bytes aligned, better if machine-pointer-size aligned.
'//        - Domain Blob (NAPI_DOMAIN_DESCRIPTION_BLOB) offsets need to be
'//          4-bytes aligned.
'//        - Domain Name offsets need to be 2-bytes aligned.
'//        - Domain Names are strings of UNICODE chars and they must be at
'//          least cchDomainName UNICODE chars long. Zero-termination is
'//          recommended but not required.
'//        - Domain Blobs (NAPI_DOMAIN_DESCRIPTION_BLOBs) do not need to be
'//          contiguous and Domain Name strings do not need to be in order
'//          or grouped after the Domain Blobs, as in the example above.
'//          They may appear in any order and also interleaved with Domain
'//          Blobs, as long as the alignment rules are respected.
'//
'//-----------------------------------------------------------------------------

' // Size = 16 bytes
TYPE NAPI_DOMAIN_DESCRIPTION_BLOB DWORD
   AuthLevel                   AS DWORD   ' DWORD
   cchDomainName               AS DWORD   ' DWORD
   OffsetNextDomainDescription AS DWORD   ' DWORD
   OffsetThisDomainName        AS DWORD   ' DWORD
END TYPE

' // Size = 20 bytes
TYPE NAPI_PROVIDER_INSTALLATION_BLOB DWORD
   dwVersion         AS DWORD   ' DWORD
   dwProviderType    AS DWORD   ' DWORD
   fSupportsWildCard AS DWORD   ' DWORD
   cDomains          AS DWORD   ' ULONG
   OffsetFirstDomain AS DWORD   ' ULONG
END TYPE
