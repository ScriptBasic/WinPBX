' ########################################################################################
' Microsoft Windows
' File: l2cmn.inc
' Contents: Definitions and data strcutures for common layer 2
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%L2CMN_INC = 1

'// Profile name max length, in characters
%L2_PROFILE_MAX_NAME_LENGTH = 256

'// If a notification needs to be private that is only consumed by internal components
'// then it should be part of l2cmnpriv.h


'// the types of notification
'// This signifies what kind of notification is to be passed on , the
'// 0X0000FFFF  signifies all public notifications , so all notfications that need to be public
'// should be in this range and have a single bit set as these flags can be combined.
%L2_NOTIFICATION_SOURCE_NONE             = 0???
%L2_NOTIFICATION_SOURCE_DOT3_AUTO_CONFIG = &H00000001???
%L2_NOTIFICATION_SOURCE_SECURITY         = &H00000002???
%L2_NOTIFICATION_SOURCE_ONEX             = &H00000004???
%L2_NOTIFICATION_SOURCE_WLAN_ACM         = &H00000008???
%L2_NOTIFICATION_SOURCE_WLAN_MSM         = &H00000010???
%L2_NOTIFICATION_SOURCE_WLAN_SECURITY    = &H00000020???
%L2_NOTIFICATION_SOURCE_WLAN_IHV         = &H00000040???
%L2_NOTIFICATION_SOURCE_WLAN_HNWK        = &H00000080???

%L2_NOTIFICATION_SOURCE_ALL              = &H0000FFFF???
%L2_NOTIFICATION_CODE_PUBLIC_BEGIN       = &H00000000???
%L2_NOTIFICATION_CODE_GROUP_SIZE         = &H00001000???
%L2_NOTIFICATION_CODE_V2_BEGIN           = (%L2_NOTIFICATION_CODE_PUBLIC_BEGIN+%L2_NOTIFICATION_CODE_GROUP_SIZE)

'// L2 reason code
'// reason code bases
%L2_REASON_CODE_GROUP_SIZE            = &H10000???
%L2_REASON_CODE_GEN_BASE              = &H10000???
%L2_REASON_CODE_DOT11_AC_BASE         = (%L2_REASON_CODE_GEN_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_DOT11_MSM_BASE        = (%L2_REASON_CODE_DOT11_AC_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_DOT11_SECURITY_BASE   = (%L2_REASON_CODE_DOT11_MSM_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_ONEX_BASE             = (%L2_REASON_CODE_DOT11_SECURITY_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_DOT3_AC_BASE          = (%L2_REASON_CODE_ONEX_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_DOT3_MSM_BASE         = (%L2_REASON_CODE_DOT3_AC_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_PROFILE_BASE          = (%L2_REASON_CODE_DOT3_MSM_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_IHV_BASE              = (%L2_REASON_CODE_PROFILE_BASE+%L2_REASON_CODE_GROUP_SIZE)
%L2_REASON_CODE_WIMAX_BASE            = (%L2_REASON_CODE_IHV_BASE+%L2_REASON_CODE_GROUP_SIZE)

'// the common reason codes
%L2_REASON_CODE_SUCCESS               =  0

'// general reason code
%L2_REASON_CODE_UNKNOWN               = (%L2_REASON_CODE_GEN_BASE+1)

'// common profile section missing
%L2_REASON_CODE_PROFILE_MISSING       = &H00000001???

'// This structure is the notification structure which needs to be filled in by each component
'// The interface guid is filled in only by the AC
'// The NotificationSource signifies the type above
'// and NotificationCode is one of the enum values

' // Size = 32 bytes
TYPE L2_NOTIFICATION_DATA DWORD
   NotificationSource AS DWORD   ' DWORD
   NotificationCode   AS DWORD   ' DWORD
   InterfaceGuid      AS GUID    ' GUID
   dwDataSize         AS DWORD   ' DWORD
#IF %DEF(%USEPBDECL)
   pData              AS BYTE PTR
#ELSE
   pData              AS DWORD   ' PVOID
#ENDIF
END TYPE
