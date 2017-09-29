' ########################################################################################
' Microsoft Windows
' File: evcoll.inc
' Contents: Event Collector API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVCOLL_INC = 1

'typedef HANDLE EC_HANDLE;
'typedef HANDLE EC_OBJECT_ARRAY_PROPERTY_HANDLE;


'//
'// Access Control Permissions
'//

'/*--------------------------------------------------------------------------
'  Subscription Definitions
'  --------------------------------------------------------------------------*/

' enum EC_SUBSCRIPTION_PROPERTY_ID
%EcSubscriptionEnabled                      = 0    ' // EcVarTypeBoolean
%EcSubscriptionEventSources                 = 1    ' // EcVarObjectArrayPropertyHandle
%EcSubscriptionEventSourceAddress           = 2    ' // EcVarTypeString
%EcSubscriptionEventSourceEnabled           = 3    ' // EcVarTypeBoolean
%EcSubscriptionEventSourceUserName          = 4    ' // EcVarTypeString
%EcSubscriptionEventSourcePassword          = 5    ' // EcVarTypeString
%EcSubscriptionDescription                  = 6    ' // EcVarTypeString
%EcSubscriptionURI                          = 7    ' // EcVarTypeString
%EcSubscriptionConfigurationMode            = 8    ' // EcVarTypeUInt32 EC_SUBSCRIPTION_CONFIGURATION_MODE
%EcSubscriptionExpires                      = 9    ' // EcVarTypeDateTime
%EcSubscriptionQuery                        = 10   ' // EcVarTypeString
%EcSubscriptionTransportName                = 11   ' // EcVarTypeString
%EcSubscriptionTransportPort                = 12   ' // EcVarTypeUInt32
%EcSubscriptionDeliveryMode                 = 13   ' // EcVarTypeUInt32 EC_SUBSCRIPTION_DELIVERY_MODE
%EcSubscriptionDeliveryMaxItems             = 14   ' // EcVarTypeUInt32
%EcSubscriptionDeliveryMaxLatencyTime       = 15   ' // EcVarTypeUInt32
%EcSubscriptionHeartbeatInterval            = 16   ' // EcVarTypeUInt32
%EcSubscriptionLocale                       = 17   ' // EcVarTypeString
%EcSubscriptionContentFormat                = 18   ' // EcVarTypeUInt32 EC_SUBSCRIPTION_CONTENT_FORMAT
%EcSubscriptionLogFile                      = 19   ' // EcVarTypeString
%EcSubscriptionPublisherName                = 20   ' // EcVarTypeString
%EcSubscriptionCredentialsType              = 21   ' // EcVarTypeUInt32 EC_SUBSCRIPTION_CREDENTIALS_TYPE
%EcSubscriptionCommonUserName               = 22   ' // EcVarTypeString
%EcSubscriptionCommonPassword               = 23   ' // EcVarTypeString
%EcSubscriptionHostName                     = 24   ' // EcVarTypeString
%EcSubscriptionReadExistingEvents           = 25   ' // EcVarTypeBoolean
%EcSubscriptionDialect                      = 26   ' // EcVarTypeString
%EcSubscriptionType                         = 27   ' // EcVarTypeUInt32 EC_SUBSCRIPTION_TYPE
%EcSubscriptionAllowedIssuerCAs             = 28   ' // EcVarTypeString  | EcArrayBitMask
%EcSubscriptionAllowedSubjects              = 29   ' // EcVarTypeString  | EcArrayBitMask
%EcSubscriptionDeniedSubjects               = 30   ' // EcVarTypeString  | EcArrayBitMask
%EcSubscriptionAllowedSourceDomainComputers = 31   ' // EcVarTypeString SDDL
%EcSubscriptionPropertyIdEND                = 32

' enum EC_SUBSCRIPTION_CREDENTIALS_TYPE
%EcSubscriptionCredDefault      = 0
%EcSubscriptionCredNegotiate    = 1
%EcSubscriptionCredDigest       = 2
%EcSubscriptionCredBasic        = 3
%EcSubscriptionCredLocalMachine = 4

' enum EC_SUBSCRIPTION_TYPE {
%EcSubscriptionTypeSourceInitiated    = 0
%EcSubscriptionTypeCollectorInitiated = 1

' enum EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID
%EcSubscriptionRunTimeStatusActive            = 0   ' // EcVarTypeUInt32 EC_SUBSCRIPTION_RUNTIME_STATUS_ACTIVE_STATUS
%EcSubscriptionRunTimeStatusLastError         = 1   ' // EcVarTypeUInt32
%EcSubscriptionRunTimeStatusLastErrorMessage  = 2   ' // EcVarTypeString
%EcSubscriptionRunTimeStatusLastErrorTime     = 3   ' // EcVarTypeDateTime
%EcSubscriptionRunTimeStatusNextRetryTime     = 4   ' // EcVarTypeDateTime
%EcSubscriptionRunTimeStatusEventSources      = 5   ' // EcVarTypeString | ArrayBitMask
%EcSubscriptionRunTimeStatusLastHeartbeatTime = 6   ' // EcVarTypeDateTime
%EcSubscriptionRunTimeStatusInfoIdEND         = 7

' enum EC_VARIANT_TYPE
%EcVarTypeNull                  = 0
%EcVarTypeBoolean               = 1
%EcVarTypeUInt32                = 2
%EcVarTypeDateTime              = 3
%EcVarTypeString                = 4
%EcVarObjectArrayPropertyHandle = 5

%EC_VARIANT_TYPE_MASK  = &H7f???
%EC_VARIANT_TYPE_ARRAY = 128

UNION EC_VARIANT_UNION
   BooleanVal        AS LONG           ' BOOL
   UInt32Val         AS DWORD          ' UINT32
   DateTimeVal       AS QUAD           ' ULONGLONG
   StringVal         AS WSTRINGZ PTR   ' LPCWSTR
   BinaryVal         AS BYTE PTR       ' PBYTE
   BooleanArr        AS LONG PTR       ' BOOL *
   Int32Arr          AS LONG PTR       ' INT32 *
   StringArr         AS WSTRINGZ PTR   ' LPWSTR *
   PropertyHandleVal AS DWORD          ' EC_OBJECT_ARRAY_PROPERTY_HANDLE
END UNION

TYPE EC_VARIANT
   EC_VARIANT_UNION
   ount AS DWORD   ' DWORD // number of elements not length in bytes.  Used for arrays and binary/string types.
   Type AS DWORD   ' DWORD
END TYPE


%EC_READ_ACCESS  = 1
%EC_WRITE_ACCESS = 2

%EC_OPEN_ALWAYS   = 0
%EC_CREATE_NEW    = 1
%EC_OPEN_EXISTING = 2

' enum EC_SUBSCRIPTION_CONFIGURATION_MODE
%EcConfigurationModeNormal       = 0
%EcConfigurationModeCustom       = 1
%EcConfigurationModeMinLatency   = 2
%EcConfigurationModeMinBandwidth = 3

' enum EC_SUBSCRIPTION_DELIVERY_MODE
%EcDeliveryModePull = 1
%EcDeliveryModePush = 2

' enum EC_SUBSCRIPTION_CONTENT_FORMAT
%EcContentFormatEvents       = 1
%EcContentFormatRenderedText = 2

' enum EC_SUBSCRIPTION_RUNTIME_STATUS_ACTIVE_STATUS
%EcRuntimeStatusActiveStatusDisabled = 1
%EcRuntimeStatusActiveStatusActive   = 2
%EcRuntimeStatusActiveStatusInactive = 3
%EcRuntimeStatusActiveStatusTrying   = 4

DECLARE FUNCTION EcOpenSubscriptionEnum IMPORT "Wecapi.dll" ALIAS "EcOpenSubscriptionEnum" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EC_HANDLE

DECLARE FUNCTION EcEnumNextSubscription IMPORT "Wecapi.dll" ALIAS "EcEnumNextSubscription" ( _
   BYVAL SubscriptionEnum AS DWORD _                    ' __in EC_HANDLE SubscriptionEnum
 , BYVAL SubscriptionNameBufferSize AS DWORD _          ' __in DWORD SubscriptionNameBufferSize
 , BYREF SubscriptionNameBuffer AS WSTRINGZ _           ' __out LPWSTR SubscriptionNameBuffer
 , BYREF SubscriptionNameBufferUsed AS DWORD _          ' __out PDWORD SubscriptionNameBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcOpenSubscription IMPORT "Wecapi.dll" ALIAS "EcOpenSubscription" ( _
   BYREF SubscriptionName AS WSTRINGZ _                 ' __in LPCWSTR SubscriptionName
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EC_HANDLE

DECLARE FUNCTION EcSetSubscriptionProperty IMPORT "Wecapi.dll" ALIAS "EcSetSubscriptionProperty" ( _
   BYVAL Subscription AS DWORD _                        ' __in EC_HANDLE Subscription
 , BYVAL PropertyId AS LONG _                           ' __in EC_SUBSCRIPTION_PROPERTY_ID PropertyId
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF PropertyValue AS EC_VARIANT _                  ' __in PEC_VARIANT PropertyValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcGetSubscriptionProperty IMPORT "Wecapi.dll" ALIAS "EcGetSubscriptionProperty" ( _
   BYVAL Subscription AS DWORD _                        ' __in EC_HANDLE Subscription
 , BYVAL PropertyId AS LONG _                           ' __in EC_SUBSCRIPTION_PROPERTY_ID PropertyId
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EC_VARIANT _            ' __in PEC_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed AS DWORD _             ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcSaveSubscription IMPORT "Wecapi.dll" ALIAS "EcSaveSubscription" ( _
   BYVAL Subscription AS DWORD _                        ' __in EC_HANDLE Subscription
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcDeleteSubscription IMPORT "Wecapi.dll" ALIAS "EcDeleteSubscription" ( _
   BYREF SubscriptionName AS WSTRINGZ _                 ' __in LPCWSTR SubscriptionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcGetObjectArraySize IMPORT "Wecapi.dll" ALIAS "EcGetObjectArraySize" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EC_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYREF ObjectArraySize AS DWORD _                     ' __out PDWORD ObjectArraySize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcSetObjectArrayProperty IMPORT "Wecapi.dll" ALIAS "EcSetObjectArrayProperty" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EC_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYVAL PropertyId AS LONG _                           ' __in EC_SUBSCRIPTION_PROPERTY_ID PropertyId
 , BYVAL ArrayIndex AS DWORD _                          ' __in DWORD ArrayIndex
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF PropertyValue AS EC_VARIANT _                  ' __in  PEC_VARIANT PropertyValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcGetObjectArrayProperty IMPORT "Wecapi.dll" ALIAS "EcGetObjectArrayProperty" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EC_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYVAL PropertyId AS LONG _                           ' __in EC_SUBSCRIPTION_PROPERTY_ID PropertyId
 , BYVAL ArrayIndex AS DWORD _                          ' __in DWORD ArrayIndex
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EC_VARIANT _            ' __in  PEC_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed  AS DWORD _            ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcInsertObjectArrayElement IMPORT "Wecapi.dll" ALIAS "EcInsertObjectArrayElement" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EC_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYVAL ArrayIndex AS DWORD _                          ' __in DWORD ArrayIndex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcRemoveObjectArrayElement IMPORT "Wecapi.dll" ALIAS "EcRemoveObjectArrayElement" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EC_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYVAL ArrayIndex AS DWORD _                          ' __in DWORD ArrayIndex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcGetSubscriptionRunTimeStatus IMPORT "Wecapi.dll" ALIAS "EcGetSubscriptionRunTimeStatus" ( _
   BYREF SubscriptionName AS WSTRINGZ _                 ' __in LPCWSTR SubscriptionName
 , BYVAL StatusInfoId AS LONG _                         ' __in EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID StatusInfoId
 , BYREF EventSourceName AS WSTRINGZ _                  ' __in LPCWSTR EventSourceName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL StatusValueBufferSize AS DWORD _               ' __in DWORD StatusValueBufferSize
 , BYREF StatusValueBuffer AS EC_VARIANT _              ' __in PEC_VARIANT StatusValueBuffer
 , BYREF StatusValueBufferUsed AS DWORD _               ' __out PDWORD StatusValueBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcRetrySubscription IMPORT "Wecapi.dll" ALIAS "EcRetrySubscription" ( _
   BYREF SubscriptionName AS WSTRINGZ _                 ' __in LPCWSTR SubscriptionName
 , BYREF EventSourceName AS WSTRINGZ _                  ' __in LPCWSTR EventSourceName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EcClose IMPORT "Wecapi.dll" ALIAS "EcClose" ( _
   BYVAL Object AS DWORD _                              ' __in EC_HANDLE Object
 ) AS LONG                                              ' BOOL
