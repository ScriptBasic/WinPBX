' ########################################################################################
' Microsoft Windows
' File: wlanihvtypes.inc
' Contents: Structures used to hold information for IHV.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WLANIHVTYPES_INC = 1

#INCLUDE ONCE "EapTypes.inc"
#INCLUDE ONCE "WlanTypes.inc"

'// Select MS Security settings
'// as may be needed by the IHVs
' // Size = 36 bytes
TYPE DOT11_MSSECURITY_SETTINGS DWORD
   dot11AuthAlgorithm     AS LONG              ' DOT11_AUTH_ALGORITHM
   dot11CipherAlgorithm   AS LONG              ' DOT11_CIPHER_ALGORITHM
   fOneXEnabled           AS LONG              ' BOOL
   eapMethodType          AS EAP_METHOD_TYPE
   dwEapConnectionDataLen AS DWORD             ' DWORD
   pEapConnectionData     AS BYTE PTR          ' BYTE*
END TYPE

' // Size = 40 bytes
TYPE DOT11EXT_IHV_SSID_LIST DWORD
   ulCount  AS DWORD   ' ULONG
   SSIDs(0) AS DOT11_SSID
END TYPE

'// Data structure to hold
'// additional information regarding
'// IHV profile.
' // Size = 12 bytes
TYPE DOT11EXT_IHV_PROFILE_PARAMS DWORD
   pSsidList           AS DOT11EXT_IHV_SSID_LIST PTR      ' PDOT11EXT_IHV_SSID_LIST
   BssType             AS LONG                            ' DOT11_BSS_TYPE
   pMSSecuritySettings AS DOT11_MSSECURITY_SETTINGS PTR   ' PDOT11_MSSECURITY_SETTINGS
END TYPE

'// the following shoud be the same as WLAN_MAX_NAME_LENGTH
%MS_MAX_PROFILE_NAME_LENGTH = 256

'// profile flags
%MS_PROFILE_GROUP_POLICY = &H00000001???
%MS_PROFILE_USER         = &H00000002???

'// Data structure to hold
'// all params passed to IHV
'// for the UI extension
' // Size = 544 bytes
TYPE DOT11EXT_IHV_PARAMS DWORD
   dot11ExtIhvProfileParams AS DOT11EXT_IHV_PROFILE_PARAMS
   wstrProfileName          AS WSTRINGZ * %MS_MAX_PROFILE_NAME_LENGTH   ' WCHAR
   dwProfileTypeFlags       AS DWORD   ' DWORD
   interfaceGuid            AS GUID    ' GUID
END TYPE
