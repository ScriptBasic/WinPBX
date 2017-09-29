' ########################################################################################
' Microsoft Windows
' File: naptypes.inc
' Copyright (c) 2012 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NAPTYPES_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

#IF NOT %DEF(%INapTypes_INTERFACE_DEFINED)
%INapTypes_INTERFACE_DEFINED = 1

%maxSoHAttributeCount          = 100
%maxSoHAttributeSize           = 4000
%minNetworkSoHSize             = 12
%maxNetworkSoHSize             = 4000
%maxDwordCountPerSoHAttribute  =  (%maxSoHAttributeSize / 4)
%maxIpv4CountPerSoHAttribute   =  (%maxSoHAttributeSize / 4 )
%maxIpv6CountPerSoHAttribute   = (%maxSoHAttributeSize / 16 )
%maxStringLength               = 1024
%maxStringLengthInBytes        = ((%maxStringLength + 1) * 2)
%maxSystemHealthEntityCount    = 20
%maxEnforcerCount              = 20
%maxPrivateDataSize            = 200
%maxConnectionCountPerEnforcer = 20
%maxCachedSoHCount             = ((%maxSystemHealthEntityCount * %maxEnforcerCount) * %maxConnectionCountPerEnforcer)
%freshSoHRequest               = &H1
%shaFixup                      = &H1

'enum tagIsolationState
%isolationStateNotRestricted    = 1
%isolationStateInProbation      = 2
%isolationStateRestrictedAccess = 3

'enum tagExtendedIsolationState
%extendedIsolationStateNoData     = 0
%extendedIsolationStateTransition = &H1
%extendedIsolationStateInfected   = &H2
%extendedIsolationStateUnknown    = &H3

'enum tagNapTracingLevel
%tracingLevelUndefined = 0
%tracingLevelBasic     = 1
%tracingLevelAdvanced  = 2
%tracingLevelDebug     = 3

MACRO ProbationTime = FILETIME

' // Size = 8 bytes
TYPE CountedString DWORD
    length  AS WORD           ' UINT16
    cstring AS WSTRINGZ PTR   ' WCHAR*
END TYPE

' // Size = 20 bytes
TYPE IsolationInfo DWORD
   isolationState AS LONG            ' IsolationState enum
   probEndTime    AS ProbationTime   ' ProbationTime
   failureUrl     AS CountedString   ' CountedString
END TYPE

' // Size = 24 bytes
TYPE IsolationInfoEx DWORD
   isolationState         AS LONG            ' IsolationState enum
   extendedIsolationState AS LONG            ' ExtendedIsolationState enum
   probEndTime            AS ProbationTime   ' ProbationTime
   failureUrl             AS CountedString   ' CountedString
END TYPE

%failureCategoryCount = 5

'enum tagFailureCategory
%failureCategoryNone                = 0
%failureCategoryOther               = 1
%failureCategoryClientComponent     = 2
%failureCategoryClientCommunication = 3
%failureCategoryServerComponent     = 4
%failureCategoryServerCommunication = 5

' // Size = 20 bytes
TYPE FailureCategoryMapping DWORD
   mappingCompliance(4) AS LONG   ' BOOL mappingCompliance[ 5 ]
END TYPE

'typedef UINT32 NapComponentId;
'typedef NapComponentId SystemHealthEntityId;
'typedef NapComponentId EnforcementEntityId;

%ComponentTypeEnforcementClientSoH = &H1
%ComponentTypeEnforcementClientRp  = &H2

'typedef /* [range] */ __RPC__range(0,maxSystemHealthEntityCount) UINT16 SystemHealthEntityCount;

'typedef /* [range] */ __RPC__range(0,maxEnforcerCount) UINT16 EnforcementEntityCount;

' // Size = 24 bytes
TYPE CorrelationId DWORD
   connId    AS GUID       ' GUID
   timeStamp AS FILETIME   ' FILETIME
END TYPE

'typedef CountedString StringCorrelationId;
MACRO StringCorrelationId = CountedString

'typedef GUID ConnectionId;

%percentageNotSupported = 101

'typedef /* [range] */ __RPC__range(0,percentageNotSupported) UINT8 Percentage;

'typedef UINT32 MessageId;

' // Size = 8 bytes
TYPE ResultCodes DWORD
   count   AS WORD       ' UINT16
   results AS LONG PTR   ' HRESULT*
END TYPE

' // Size = 4 bytes
TYPE Ipv4Address BYTE
   addr(3) AS BYTE   ' BYTE addr[ 4 ]
END TYPE

' // Size = 16 bytes
TYPE Ipv6Address BYTE
   addr(15) AS BYTE   ' BYTE addr[ 16 ]
END TYPE

'enum tagFixupState
%fixupStateSuccess        = 0
%fixupStateInProgress     = 1
%fixupStateCouldNotUpdate = 2

' // Size = 20 bytes
TYPE FixupInfo DWORD
   state       AS LONG          ' FixupState enum
   percentage  AS BYTE          ' Percentage = UINT8
   resultCodes AS ResultCodes   ' ResultCodes
   fixupMsgId  AS DWORD         ' MessageId = UINT32
END TYPE
MACRO FixupInfo_type = FixupInfo   ' // For compatibility with PB includes

'enum tagNapNotifyType
%napNotifyTypeUnknown      = 0
%napNotifyTypeServiceState = 1
%napNotifyTypeQuarState    = 2

' // Size = 36 bytes
TYPE SystemHealthAgentState DWORD
   id              AS DWORD         ' SystemHealthEntityId = UINT32
   shaResultCodes  AS ResultCodes   ' ResultCodes
   failureCategory AS LONG          ' FailureCategory enum
   fixupInfo       AS FixupInfo     ' FixupInfo
END TYPE

TYPE SoHAttribute_STRUCT WORD
   type  AS WORD       ' UINT16
   size  AS WORD       ' UINT16
   value AS BYTE PTR   ' BYTE*
END TYPE

TYPE SoHAttribute_PBSTRUCT WORD
   ' // For compatibility with PB includes
   ntype  AS WORD
   nsize  AS WORD
   nvalue AS BYTE PTR
END TYPE

' // Size = 8 bytes
UNION SoHAttribute WORD
   SoHAttribute_STRUCT
   SoHAttribute_PBSTRUCT
END UNION

' // Size = 8 bytes
TYPE SoH DWORD
   count      AS WORD               ' UINT16
   attributes AS SoHAttribute PTR   ' SoHAttribute *
END TYPE

'typedef struct tagSoH SoHRequest;
'typedef struct tagSoH SoHResponse;
MACRO SoHRequest = SoH
MACRO SoHResponse = SoH

TYPE NetworkSoH_STRUCT DWORD
   size AS WORD       ' UINT16
   data AS BYTE PTR   ' BYTE*
END TYPE

TYPE NetworkSoH_PBSTRUCT DWORD
   ' // For compatibility with PB includes
   nsize AS WORD
   ndata AS BYTE PTR
END TYPE

' // Size = 8 bytes
UNION NetworkSoH DWORD
   NetworkSoH_STRUCT
   NetworkSoH_PBSTRUCT
END UNION

'typedef struct tagNetworkSoH NetworkSoHRequest;
'typedef struct tagNetworkSoH NetworkSoHResponse;
MACRO NetworkSoHRequest = NetworkSoH
MACRO NetworkSoHResponse = NetworkSoH

TYPE PrivateData_STRUCT DWORD
   size AS WORD       ' UINT16
   data AS BYTE PTR   ' BYTE*
END TYPE

TYPE PrivateData_PBSTRUCT DWORD
   ' // For compatibility with PB includes
   nsize AS WORD
   ndata AS BYTE PTR
END TYPE

' // Size = 8 bytes
UNION PrivateData
   PrivateData_STRUCT
   PrivateData_PBSTRUCT
END UNION

' // Size = 80 bytes
TYPE NapComponentRegistrationInfo DWORD
    id               AS DWORD           ' NapComponentId = UINT32
    friendlyName     AS CountedString   ' CountedString
    description      AS CountedString   ' CountedString
    version          AS CountedString   ' CountedString
    vendorName       AS CountedString   ' CountedString
    infoClsid        AS GUID            ' CLSID
    configClsid      AS GUID            ' CLSID
    registrationDate AS FILETIME        ' FILETIME
    componentType    AS DWORD           ' UINT32
END TYPE

'enum tagRemoteConfigurationType
%remoteConfigTypeMachine = 1
%remoteConfigTypeConfigBlob = %remoteConfigTypeMachine + 1

#ENDIF   ' /* __INapTypes_INTERFACE_DEFINED__ */
