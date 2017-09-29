' ########################################################################################
' Microsoft Windows
' File: wlantypes.inc
' Contents: Structures used to hold wlan information
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WLANTYPES_INC = 1

' enum _DOT11_BSS_TYPE
%dot11_BSS_type_infrastructure = 1
%dot11_BSS_type_independent    = 2
%dot11_BSS_type_any            = 3

%DOT11_SSID_MAX_LENGTH = 32    ' // 32 bytes

UNION DOT11_SSID_ucSSID_UNION
   ucSSID(%DOT11_SSID_MAX_LENGTH - 1) AS BYTE   ' UCHAR
   ' // For compatibility with the PB declares
   ucSSID AS STRING * %DOT11_SSID_MAX_LENGTH
END UNION

' // Size = 36 bytes
TYPE DOT11_SSID DWORD
   uSSIDLength AS DWORD   ' ULONG
   DOT11_SSID_ucSSID_UNION
END TYPE


'// DOT11_AUTH_ALGO_LIST
' enum _DOT11_AUTH_ALGORITHM
%DOT11_AUTH_ALGO_80211_OPEN       = 1???
%DOT11_AUTH_ALGO_80211_SHARED_KEY = 2???
%DOT11_AUTH_ALGO_WPA              = 3???
%DOT11_AUTH_ALGO_WPA_PSK          = 4???
%DOT11_AUTH_ALGO_WPA_NONE         = 5???   ' // used in NatSTA only
%DOT11_AUTH_ALGO_RSNA             = 6???
%DOT11_AUTH_ALGO_RSNA_PSK         = 7???
%DOT11_AUTH_ALGO_IHV_START        = &H80000000???
%DOT11_AUTH_ALGO_IHV_END          = &Hffffffff???

%DOT11_AUTH_ALGORITHM_OPEN_SYSTEM = %DOT11_AUTH_ALGO_80211_OPEN
%DOT11_AUTH_ALGORITHM_SHARED_KEY  = %DOT11_AUTH_ALGO_80211_SHARED_KEY
%DOT11_AUTH_ALGORITHM_WPA         = %DOT11_AUTH_ALGO_WPA
%DOT11_AUTH_ALGORITHM_WPA_PSK     = %DOT11_AUTH_ALGO_WPA_PSK
%DOT11_AUTH_ALGORITHM_WPA_NONE    = %DOT11_AUTH_ALGO_WPA_NONE
%DOT11_AUTH_ALGORITHM_RSNA        = %DOT11_AUTH_ALGO_RSNA
%DOT11_AUTH_ALGORITHM_RSNA_PSK    = %DOT11_AUTH_ALGO_RSNA_PSK

'// Cipher algorithm Ids (for little endian platform)
' enum _DOT11_CIPHER_ALGORITHM
%DOT11_CIPHER_ALGO_NONE           = &H00???
%DOT11_CIPHER_ALGO_WEP40          = &H01???
%DOT11_CIPHER_ALGO_TKIP           = &H02???
%DOT11_CIPHER_ALGO_CCMP           = &H04???
%DOT11_CIPHER_ALGO_WEP104         = &H05???
%DOT11_CIPHER_ALGO_WPA_USE_GROUP  = &H100???
%DOT11_CIPHER_ALGO_RSN_USE_GROUP  = &H100???
%DOT11_CIPHER_ALGO_WEP            = &H101???
%DOT11_CIPHER_ALGO_IHV_START      = &H80000000???
%DOT11_CIPHER_ALGO_IHV_END        = &Hffffffff???

' // Size = 8 bytes
TYPE DOT11_AUTH_CIPHER_PAIR DWORD
   AuthAlgoId   AS LONG   ' DOT11_AUTH_ALGORITHM
   CipherAlgoId AS LONG   ' DOT11_CIPHER_ALGORITHM
END TYPE
