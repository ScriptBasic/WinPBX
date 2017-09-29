' ########################################################################################
' Microsoft Windows
' File: MSClus.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSClusterLib
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft Cluster Service Automation Classes.
' Library name: msclus.dll
' Library GUID: {F2E606E0-2631-11D1-89F1-00A0C90D061E}
' ########################################################################################

#INCLUDE THIS ONCE
%MSCLUS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "basetsd.inc"
#INCLUDE ONCE "oaidl.inc"

$LIBID_MSClusterLib = GUID$("{F2E606E0-2631-11D1-89F1-00A0C90D061E}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ClusApplication = GUID$("{F2E606E5-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusCryptoKeys = GUID$("{F2E6072B-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusDisk = GUID$("{F2E60723-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusDisks = GUID$("{F2E60725-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNetInterface = GUID$("{F2E606ED-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNetInterfaces = GUID$("{F2E606EF-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNetwork = GUID$("{F2E606F1-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNetworkNetInterfaces = GUID$("{F2E606F5-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNetworks = GUID$("{F2E606F3-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNode = GUID$("{F2E606F7-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNodeNetInterfaces = GUID$("{F2E606FB-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusNodes = GUID$("{F2E606F9-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusPartition = GUID$("{F2E6071F-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusPartitions = GUID$("{F2E60721-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusProperties = GUID$("{F2E606FF-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusProperty = GUID$("{F2E606FD-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusPropertyValue = GUID$("{F2E60719-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusPropertyValueData = GUID$("{F2E6071D-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusPropertyValues = GUID$("{F2E6071B-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusRefObject = GUID$("{F2E60701-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusRegistryKeys = GUID$("{F2E60729-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResDependencies = GUID$("{F2E60703-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResDependents = GUID$("{F2E6072D-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResGroup = GUID$("{F2E60705-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResGroupPreferredOwnerNodes = GUID$("{F2E606E7-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResGroupResources = GUID$("{F2E606E9-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResGroups = GUID$("{F2E60707-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResource = GUID$("{F2E60709-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResources = GUID$("{F2E6070B-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResPossibleOwnerNodes = GUID$("{F2E6070D-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResType = GUID$("{F2E6070F-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResTypePossibleOwnerNodes = GUID$("{F2E60717-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResTypeResources = GUID$("{F2E60713-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusResTypes = GUID$("{F2E60711-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusScsiAddress = GUID$("{F2E60727-2631-11D1-89F1-00A0C90D061E}")
$CLSID_Cluster = GUID$("{F2E606E3-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusterNames = GUID$("{F2E606EB-2631-11D1-89F1-00A0C90D061E}")
$CLSID_ClusVersion = GUID$("{F2E60715-2631-11D1-89F1-00A0C90D061E}")
$CLSID_DomainNames = GUID$("{F2E606E1-2631-11D1-89F1-00A0C90D061E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISClusApplication = GUID$("{F2E606E6-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusCryptoKeys = GUID$("{F2E6072C-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusDisk = GUID$("{F2E60724-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusDisks = GUID$("{F2E60726-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNetInterface = GUID$("{F2E606EE-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNetInterfaces = GUID$("{F2E606F0-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNetwork = GUID$("{F2E606F2-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNetworkNetInterfaces = GUID$("{F2E606F6-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNetworks = GUID$("{F2E606F4-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNode = GUID$("{F2E606F8-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNodeNetInterfaces = GUID$("{F2E606FC-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusNodes = GUID$("{F2E606FA-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusPartition = GUID$("{F2E60720-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusPartitionEx = GUID$("{8802D4FE-B32E-4AD1-9DBD-64F18E1166CE}")
$IID_ISClusPartitions = GUID$("{F2E60722-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusProperties = GUID$("{F2E60700-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusProperty = GUID$("{F2E606FE-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusPropertyValue = GUID$("{F2E6071A-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusPropertyValueData = GUID$("{F2E6071E-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusPropertyValues = GUID$("{F2E6071C-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusRefObject = GUID$("{F2E60702-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusRegistryKeys = GUID$("{F2E6072A-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResDependencies = GUID$("{F2E60704-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResDependents = GUID$("{F2E6072E-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResGroup = GUID$("{F2E60706-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResGroupPreferredOwnerNodes = GUID$("{F2E606E8-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResGroupResources = GUID$("{F2E606EA-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResGroups = GUID$("{F2E60708-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResource = GUID$("{F2E6070A-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResources = GUID$("{F2E6070C-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResPossibleOwnerNodes = GUID$("{F2E6070E-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResType = GUID$("{F2E60710-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResTypePossibleOwnerNodes = GUID$("{F2E60718-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResTypeResources = GUID$("{F2E60714-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusResTypes = GUID$("{F2E60712-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusScsiAddress = GUID$("{F2E60728-2631-11D1-89F1-00A0C90D061E}")
$IID_ISCluster = GUID$("{F2E606E4-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusterNames = GUID$("{F2E606EC-2631-11D1-89F1-00A0C90D061E}")
$IID_ISClusVersion = GUID$("{F2E60716-2631-11D1-89F1-00A0C90D061E}")
$IID_ISDomainNames = GUID$("{F2E606E2-2631-11D1-89F1-00A0C90D061E}")

' enum CLUSTER_QUORUM_TYPE enum
%OperationalQuorum = 0
%ModifyQuorum      = %OperationalQuorum + 1

' enum NODE_CLUSTER_STATE
%ClusterStateNotInstalled  = 0
%ClusterStateNotConfigured = &H1
%ClusterStateNotRunning    = &H1  OR &H2
%ClusterStateRunning       = (&H1 OR &H2) OR &H10

' enum CLUSTER_RESOURCE_STATE_CHANGE_REASON
%eResourceStateChangeReasonUnknown    = 0
%eResourceStateChangeReasonMove       = %eResourceStateChangeReasonUnknown    + 1
%eResourceStateChangeReasonFailover   = %eResourceStateChangeReasonMove       + 1
%eResourceStateChangeReasonFailedMove = %eResourceStateChangeReasonFailover   + 1
%eResourceStateChangeReasonShutdown   = %eResourceStateChangeReasonFailedMove + 1
%eResourceStateChangeReasonRundown    = %eResourceStateChangeReasonShutdown   + 1

' enum CLUSTER_REG_COMMAND
%CLUSREG_COMMAND_NONE     = 0
%CLUSREG_SET_VALUE        = 1
%CLUSREG_CREATE_KEY       = %CLUSREG_SET_VALUE        + 1
%CLUSREG_DELETE_KEY       = %CLUSREG_CREATE_KEY       + 1
%CLUSREG_DELETE_VALUE     = %CLUSREG_DELETE_KEY       + 1
%CLUSREG_SET_KEY_SECURITY = %CLUSREG_DELETE_VALUE     + 1
%CLUSREG_VALUE_DELETED    = %CLUSREG_SET_KEY_SECURITY + 1
%CLUSREG_LAST_COMMAND     = %CLUSREG_VALUE_DELETED    + 1

' // Size = 24 bytes
TYPE CLUSTER_ENUM_ITEM DWORD
   dwVersion AS DWORD          ' DWORD
   dwType    AS DWORD          ' DWORD
   cbId      AS DWORD          ' DWORD
   lpszId    AS WSTRINGZ PTR   ' LPWSTR
   cbName    AS DWORD          ' DWORD
   lpszName  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' enum CLUSTER_QUORUM_VALUE
%CLUSTER_QUORUM_MAINTAINED = 0
%CLUSTER_QUORUM_LOST       = 1

' enum CLUSTER_CHANGE
%CLUSTER_CHANGE_NODE_STATE             = &H1???
%CLUSTER_CHANGE_NODE_DELETED           = &H2???
%CLUSTER_CHANGE_NODE_ADDED             = &H4???
%CLUSTER_CHANGE_NODE_PROPERTY          = &H8???
%CLUSTER_CHANGE_REGISTRY_NAME          = &H10???
%CLUSTER_CHANGE_REGISTRY_ATTRIBUTES    = &H20???
%CLUSTER_CHANGE_REGISTRY_VALUE         = &H40???
%CLUSTER_CHANGE_REGISTRY_SUBTREE       = &H80???
%CLUSTER_CHANGE_RESOURCE_STATE         = &H100???
%CLUSTER_CHANGE_RESOURCE_DELETED       = &H200???
%CLUSTER_CHANGE_RESOURCE_ADDED         = &H400???
%CLUSTER_CHANGE_RESOURCE_PROPERTY      = &H800???
%CLUSTER_CHANGE_GROUP_STATE            = &H1000???
%CLUSTER_CHANGE_GROUP_DELETED          = &H2000???
%CLUSTER_CHANGE_GROUP_ADDED            = &H4000???
%CLUSTER_CHANGE_GROUP_PROPERTY         = &H8000???
%CLUSTER_CHANGE_RESOURCE_TYPE_DELETED  = &H10000???
%CLUSTER_CHANGE_RESOURCE_TYPE_ADDED    = &H20000???
%CLUSTER_CHANGE_RESOURCE_TYPE_PROPERTY = &H40000???
%CLUSTER_CHANGE_CLUSTER_RECONNECT      = &H80000???
%CLUSTER_CHANGE_NETWORK_STATE          = &H100000???
%CLUSTER_CHANGE_NETWORK_DELETED        = &H200000???
%CLUSTER_CHANGE_NETWORK_ADDED          = &H400000???
%CLUSTER_CHANGE_NETWORK_PROPERTY       = &H800000???
%CLUSTER_CHANGE_NETINTERFACE_STATE     = &H1000000???
%CLUSTER_CHANGE_NETINTERFACE_DELETED   = &H2000000???
%CLUSTER_CHANGE_NETINTERFACE_ADDED     = &H4000000???
%CLUSTER_CHANGE_NETINTERFACE_PROPERTY  = &H8000000???
%CLUSTER_CHANGE_QUORUM_STATE           = &H10000000???
%CLUSTER_CHANGE_CLUSTER_STATE          = &H20000000???
%CLUSTER_CHANGE_CLUSTER_PROPERTY       = &H40000000???
%CLUSTER_CHANGE_HANDLE_CLOSE           = &H80000000???

%CLUSTER_CHANGE_ALL = %CLUSTER_CHANGE_NODE_STATE OR %CLUSTER_CHANGE_NODE_DELETED OR _
                      %CLUSTER_CHANGE_NODE_ADDED OR %CLUSTER_CHANGE_NODE_PROPERTY OR _
                      %CLUSTER_CHANGE_REGISTRY_NAME OR %CLUSTER_CHANGE_REGISTRY_ATTRIBUTES OR _
                      %CLUSTER_CHANGE_REGISTRY_VALUE OR %CLUSTER_CHANGE_REGISTRY_SUBTREE OR _
                      %CLUSTER_CHANGE_RESOURCE_STATE OR %CLUSTER_CHANGE_RESOURCE_DELETED OR _
                      %CLUSTER_CHANGE_RESOURCE_ADDED OR %CLUSTER_CHANGE_RESOURCE_PROPERTY OR _
                      %CLUSTER_CHANGE_GROUP_STATE OR %CLUSTER_CHANGE_GROUP_DELETED OR _
                      %CLUSTER_CHANGE_GROUP_ADDED OR %CLUSTER_CHANGE_GROUP_PROPERTY OR _
                      %CLUSTER_CHANGE_RESOURCE_TYPE_DELETED OR %CLUSTER_CHANGE_RESOURCE_TYPE_ADDED OR _
                      %CLUSTER_CHANGE_RESOURCE_TYPE_PROPERTY OR %CLUSTER_CHANGE_NETWORK_STATE OR _
                      %CLUSTER_CHANGE_NETWORK_DELETED OR %CLUSTER_CHANGE_NETWORK_ADDED OR _
                      %CLUSTER_CHANGE_NETWORK_PROPERTY OR %CLUSTER_CHANGE_NETINTERFACE_STATE OR _
                      %CLUSTER_CHANGE_NETINTERFACE_DELETED OR %CLUSTER_CHANGE_NETINTERFACE_ADDED OR _
                      %CLUSTER_CHANGE_NETINTERFACE_PROPERTY OR %CLUSTER_CHANGE_QUORUM_STATE OR _
                      %CLUSTER_CHANGE_CLUSTER_STATE OR %CLUSTER_CHANGE_CLUSTER_PROPERTY OR _
                      %CLUSTER_CHANGE_CLUSTER_RECONNECT OR %CLUSTER_CHANGE_HANDLE_CLOSE

' enum CLUSTER_ENUM
%CLUSTER_ENUM_NODE                   = &H1???
%CLUSTER_ENUM_RESTYPE                = &H2???
%CLUSTER_ENUM_RESOURCE               = &H4???
%CLUSTER_ENUM_GROUP                  = &H8???
%CLUSTER_ENUM_NETWORK                = &H10???
%CLUSTER_ENUM_NETINTERFACE           = &H20???
%CLUSTER_ENUM_SHARED_VOLUME_RESOURCE = &H40000000???
%CLUSTER_ENUM_INTERNAL_NETWORK       = &H80000000???

%CLUSTER_ENUM_ALL   = %CLUSTER_ENUM_NODE OR %CLUSTER_ENUM_RESTYPE OR _
                      %CLUSTER_ENUM_RESOURCE OR %CLUSTER_ENUM_GROUP OR _
                      %CLUSTER_ENUM_NETWORK OR %CLUSTER_ENUM_NETINTERFACE

' enum CLUSTER_NODE_ENUM
%CLUSTER_NODE_ENUM_NETINTERFACES = &H1
%CLUSTER_NODE_ENUM_GROUPS        = &H2
%CLUSTER_NODE_ENUM_ALL           = %CLUSTER_NODE_ENUM_NETINTERFACES OR %CLUSTER_NODE_ENUM_GROUPS

' enum CLUSTER_NODE_STATE
%ClusterNodeStateUnknown = -1
%ClusterNodeUp           = %ClusterNodeStateUnknown + 1
%ClusterNodeDown         = %ClusterNodeUp + 1
%ClusterNodePaused       = %ClusterNodeDown + 1
%ClusterNodeJoining      = %ClusterNodePaused + 1

' enum CLUSTER_GROUP_ENUM
%CLUSTER_GROUP_ENUM_CONTAINS = &H1
%CLUSTER_GROUP_ENUM_NODES    = &H2
%CLUSTER_GROUP_ENUM_ALL      = %CLUSTER_GROUP_ENUM_CONTAINS OR %CLUSTER_GROUP_ENUM_NODES

' enum CLUSTER_GROUP_STATE
%ClusterGroupStateUnknown  = -1
%ClusterGroupOnline        = %ClusterGroupStateUnknown + 1
%ClusterGroupOffline       = %ClusterGroupOnline + 1
%ClusterGroupFailed        = %ClusterGroupOffline + 1
%ClusterGroupPartialOnline = %ClusterGroupFailed + 1
%ClusterGroupPending       = %ClusterGroupPartialOnline + 1

' enum CLUSTER_GROUP_AUTOFAILBACK_TYPE
%ClusterGroupPreventFailback   = 0
%ClusterGroupAllowFailback     = %ClusterGroupPreventFailback + 1
%ClusterGroupFailbackTypeCount = %ClusterGroupAllowFailback   + 1

'typedef enum CLUSTER_GROUP_AUTOFAILBACK_TYPE CGAFT;

' enum CLUSTER_RESOURCE_STATE enum
%ClusterResourceStateUnknown   = -1
%ClusterResourceInherited      = %ClusterResourceStateUnknown  + 1
%ClusterResourceInitializing   = %ClusterResourceInherited     + 1
%ClusterResourceOnline         = %ClusterResourceInitializing  + 1
%ClusterResourceOffline        = %ClusterResourceOnline        + 1
%ClusterResourceFailed         = %ClusterResourceOffline       + 1
%ClusterResourcePending        = 128
%ClusterResourceOnlinePending  = %ClusterResourcePending       + 1
%ClusterResourceOfflinePending = %ClusterResourceOnlinePending + 1

' enum CLUSTER_RESOURCE_RESTART_ACTION
%ClusterResourceDontRestart                      = 0
%ClusterResourceRestartNoNotify                  = %ClusterResourceDontRestart     + 1
%ClusterResourceRestartNotify                    = %ClusterResourceRestartNoNotify + 1
%ClusterResourceRestartActionCount               = %ClusterResourceRestartNotify   + 1

'typedef enum CLUSTER_RESOURCE_RESTART_ACTION CRRA;

' enum CLUSTER_RESOURCE_CREATE_FLAGS
%CLUSTER_RESOURCE_DEFAULT_MONITOR  = 0
%CLUSTER_RESOURCE_SEPARATE_MONITOR = 1
%CLUSTER_RESOURCE_VALID_FLAGS      = %CLUSTER_RESOURCE_SEPARATE_MONITOR

' enum CLUSTER_PROPERTY_TYPE
%CLUSPROP_TYPE_UNKNOWN           = -1
%CLUSPROP_TYPE_ENDMARK           = 0
%CLUSPROP_TYPE_LIST_VALUE        = %CLUSPROP_TYPE_ENDMARK           + 1
%CLUSPROP_TYPE_RESCLASS          = %CLUSPROP_TYPE_LIST_VALUE        + 1
%CLUSPROP_TYPE_RESERVED1         = %CLUSPROP_TYPE_RESCLASS          + 1
%CLUSPROP_TYPE_NAME              = %CLUSPROP_TYPE_RESERVED1         + 1
%CLUSPROP_TYPE_SIGNATURE         = %CLUSPROP_TYPE_NAME              + 1
%CLUSPROP_TYPE_SCSI_ADDRESS      = %CLUSPROP_TYPE_SIGNATURE         + 1
%CLUSPROP_TYPE_DISK_NUMBER       = %CLUSPROP_TYPE_SCSI_ADDRESS      + 1
%CLUSPROP_TYPE_PARTITION_INFO    = %CLUSPROP_TYPE_DISK_NUMBER       + 1
%CLUSPROP_TYPE_FTSET_INFO        = %CLUSPROP_TYPE_PARTITION_INFO    + 1
%CLUSPROP_TYPE_DISK_SERIALNUMBER = %CLUSPROP_TYPE_FTSET_INFO        + 1
%CLUSPROP_TYPE_DISK_GUID         = %CLUSPROP_TYPE_DISK_SERIALNUMBER + 1
%CLUSPROP_TYPE_DISK_SIZE         = %CLUSPROP_TYPE_DISK_GUID         + 1
%CLUSPROP_TYPE_PARTITION_INFO_EX = %CLUSPROP_TYPE_DISK_SIZE         + 1
%CLUSPROP_TYPE_USER              = 32768

' enum CLUSTER_PROPERTY_FORMAT
%CLUSPROP_FORMAT_UNKNOWN             = 0
%CLUSPROP_FORMAT_BINARY              = %CLUSPROP_FORMAT_UNKNOWN             + 1
%CLUSPROP_FORMAT_DWORD               = %CLUSPROP_FORMAT_BINARY              + 1
%CLUSPROP_FORMAT_SZ                  = %CLUSPROP_FORMAT_DWORD               + 1
%CLUSPROP_FORMAT_EXPAND_SZ           = %CLUSPROP_FORMAT_SZ                  + 1
%CLUSPROP_FORMAT_MULTI_SZ            = %CLUSPROP_FORMAT_EXPAND_SZ           + 1
%CLUSPROP_FORMAT_ULARGE_INTEGER      = %CLUSPROP_FORMAT_MULTI_SZ            + 1
%CLUSPROP_FORMAT_LONG                = %CLUSPROP_FORMAT_ULARGE_INTEGER      + 1
%CLUSPROP_FORMAT_EXPANDED_SZ         = %CLUSPROP_FORMAT_LONG                + 1
%CLUSPROP_FORMAT_SECURITY_DESCRIPTOR = %CLUSPROP_FORMAT_EXPANDED_SZ         + 1
%CLUSPROP_FORMAT_LARGE_INTEGER       = %CLUSPROP_FORMAT_SECURITY_DESCRIPTOR + 1
%CLUSPROP_FORMAT_WORD                = %CLUSPROP_FORMAT_LARGE_INTEGER       + 1
%CLUSPROP_FORMAT_FILETIME            = %CLUSPROP_FORMAT_WORD                + 1
%CLUSPROP_FORMAT_USER                = 32768

'typedef
'enum CLUSTER_PROPERTY_SYNTAX
'{   CLUSPROP_SYNTAX_ENDMARK   = ( DWORD  )(( ( CLUSPROP_TYPE_ENDMARK << 16 )  | CLUSPROP_FORMAT_UNKNOWN ) ),
'CLUSPROP_SYNTAX_NAME   = ( DWORD  )(( ( CLUSPROP_TYPE_NAME << 16 )  | CLUSPROP_FORMAT_SZ ) ),
'CLUSPROP_SYNTAX_RESCLASS   = ( DWORD  )(( ( CLUSPROP_TYPE_RESCLASS << 16 )  | CLUSPROP_FORMAT_DWORD ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_SZ   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_SZ ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_EXPAND_SZ   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_EXPAND_SZ ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_DWORD   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_DWORD ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_BINARY   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_BINARY ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_MULTI_SZ   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_MULTI_SZ ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_LONG   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_LONG ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_EXPANDED_SZ   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_EXPANDED_SZ ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_SECURITY_DESCRIPTOR   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_SECURITY_DESCRIPTOR ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_LARGE_INTEGER   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_LARGE_INTEGER ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_ULARGE_INTEGER   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_ULARGE_INTEGER ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_WORD   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_WORD ) ),
'CLUSPROP_SYNTAX_DISK_SIGNATURE   = ( DWORD  )(( ( CLUSPROP_TYPE_SIGNATURE << 16 )  | CLUSPROP_FORMAT_DWORD ) ),
'CLUSPROP_SYNTAX_SCSI_ADDRESS   = ( DWORD  )(( ( CLUSPROP_TYPE_SCSI_ADDRESS << 16 )  | CLUSPROP_FORMAT_DWORD ) ),
'CLUSPROP_SYNTAX_DISK_NUMBER   = ( DWORD  )(( ( CLUSPROP_TYPE_DISK_NUMBER << 16 )  | CLUSPROP_FORMAT_DWORD ) ),
'CLUSPROP_SYNTAX_PARTITION_INFO   = ( DWORD  )(( ( CLUSPROP_TYPE_PARTITION_INFO << 16 )  | CLUSPROP_FORMAT_BINARY ) ),
'CLUSPROP_SYNTAX_FTSET_INFO   = ( DWORD  )(( ( CLUSPROP_TYPE_FTSET_INFO << 16 )  | CLUSPROP_FORMAT_BINARY ) ),
'CLUSPROP_SYNTAX_DISK_SERIALNUMBER   = ( DWORD  )(( ( CLUSPROP_TYPE_DISK_SERIALNUMBER << 16 )  | CLUSPROP_FORMAT_SZ ) ),
'CLUSPROP_SYNTAX_DISK_GUID   = ( DWORD  )(( ( CLUSPROP_TYPE_DISK_GUID << 16 )  | CLUSPROP_FORMAT_SZ ) ),
'CLUSPROP_SYNTAX_DISK_SIZE   = ( DWORD  )(( ( CLUSPROP_TYPE_DISK_SIZE << 16 )  | CLUSPROP_FORMAT_ULARGE_INTEGER ) ),
'CLUSPROP_SYNTAX_PARTITION_INFO_EX   = ( DWORD  )(( ( CLUSPROP_TYPE_PARTITION_INFO_EX << 16 )  | CLUSPROP_FORMAT_BINARY ) ),
'CLUSPROP_SYNTAX_LIST_VALUE_FILETIME   = ( DWORD  )(( ( CLUSPROP_TYPE_LIST_VALUE << 16 )  | CLUSPROP_FORMAT_FILETIME ) )
'}    CLUSTER_PROPERTY_SYNTAX;

%CLUSPROP_SYNTAX_ENDMARK                        = &H00000000???
%CLUSPROP_SYNTAX_NAME                           = &H00040003???
%CLUSPROP_SYNTAX_RESCLASS                       = &H00020002???
%CLUSPROP_SYNTAX_LIST_VALUE_SZ                  = &H00010003???
%CLUSPROP_SYNTAX_LIST_VALUE_EXPAND_SZ           = &H00010004???
%CLUSPROP_SYNTAX_LIST_VALUE_DWORD               = &H00010002???
%CLUSPROP_SYNTAX_LIST_VALUE_BINARY              = &H00010001???
%CLUSPROP_SYNTAX_LIST_VALUE_MULTI_SZ            = &H00010005???
%CLUSPROP_SYNTAX_LIST_VALUE_LONG                = &H00010007???
%CLUSPROP_SYNTAX_LIST_VALUE_EXPANDED_SZ         = &H00010008???
%CLUSPROP_SYNTAX_LIST_VALUE_SECURITY_DESCRIPTOR = &H00010009???
%CLUSPROP_SYNTAX_LIST_VALUE_LARGE_INTEGER       = &H0001000a???
%CLUSPROP_SYNTAX_LIST_VALUE_ULARGE_INTEGER      = &H00010006???
%CLUSPROP_SYNTAX_LIST_VALUE_WORD                = &H0001000b???
%CLUSPROP_SYNTAX_DISK_SIGNATURE                 = &H00050002???
%CLUSPROP_SYNTAX_SCSI_ADDRESS                   = &H00060002???
%CLUSPROP_SYNTAX_DISK_NUMBER                    = &H00070002???
%CLUSPROP_SYNTAX_PARTITION_INFO                 = &H00080001???
%CLUSPROP_SYNTAX_DISK_SERIALNUMBER              = &H000a0003???
%CLUSPROP_SYNTAX_DISK_GUID                      = &H000b0003???
%CLUSPROP_SYNTAX_DISK_SIZE                      = &H000c0006???
%CLUSPROP_SYNTAX_PARTITION_INFO_EX              = &H000d0001???
%CLUSPROP_SYNTAX_LIST_VALUE_FILETIME            = &H0001000c???

' enum CLUSTER_CONTROL_OBJECT
%CLUS_OBJECT_INVALID       = 0
%CLUS_OBJECT_RESOURCE      = %CLUS_OBJECT_INVALID       + 1
%CLUS_OBJECT_RESOURCE_TYPE = %CLUS_OBJECT_RESOURCE      + 1
%CLUS_OBJECT_GROUP         = %CLUS_OBJECT_RESOURCE_TYPE + 1
%CLUS_OBJECT_NODE          = %CLUS_OBJECT_GROUP         + 1
%CLUS_OBJECT_NETWORK       = %CLUS_OBJECT_NODE          + 1
%CLUS_OBJECT_NETINTERFACE  = %CLUS_OBJECT_NETWORK       + 1
%CLUS_OBJECT_CLUSTER       = %CLUS_OBJECT_NETINTERFACE  + 1
%CLUS_OBJECT_USER          = 128

'typedef
'enum CLCTL_CODES
' {   CLCTL_UNKNOWN   = ( ( ( 0 << 0 )  | ( ( 0 + 0 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_CHARACTERISTICS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 1 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_FLAGS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 2 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_CLASS_INFO   = ( ( ( 0x1 << 0 )  | ( ( 0 + 3 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_REQUIRED_DEPENDENCIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 4 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_ARB_TIMEOUT   = ( ( ( 0x1 << 0 )  | ( ( 0 + 5 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_NAME   = ( ( ( 0x1 << 0 )  | ( ( 0 + 10 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_RESOURCE_TYPE   = ( ( ( 0x1 << 0 )  | ( ( 0 + 11 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_NODE   = ( ( ( 0x1 << 0 )  | ( ( 0 + 12 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_NETWORK   = ( ( ( 0x1 << 0 )  | ( ( 0 + 13 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_ID   = ( ( ( 0x1 << 0 )  | ( ( 0 + 14 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_FQDN   = ( ( ( 0x1 << 0 )  | ( ( 0 + 15 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_CLUSTER_SERVICE_ACCOUNT_NAME   = ( ( ( 0x1 << 0 )  | ( ( 0 + 16 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_CHECK_VOTER_EVICT   = ( ( ( 0x1 << 0 )  | ( ( 0 + 17 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_CHECK_VOTER_DOWN   = ( ( ( 0x1 << 0 )  | ( ( 0 + 18 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_SHUTDOWN   = ( ( ( 0x1 << 0 )  | ( ( 0 + 19 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_ENUM_COMMON_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 20 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_RO_COMMON_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 21 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_COMMON_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 22 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_SET_COMMON_PROPERTIES   = ( ( ( 0x2 << 0 )  | ( ( 0 + 23 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_VALIDATE_COMMON_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 24 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_COMMON_PROPERTY_FMTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 25 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_COMMON_RESOURCE_PROPERTY_FMTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 26 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_ENUM_PRIVATE_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 30 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_RO_PRIVATE_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 31 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_PRIVATE_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 32 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_SET_PRIVATE_PROPERTIES   = ( ( ( 0x2 << 0 )  | ( ( 0 + 33 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_VALIDATE_PRIVATE_PROPERTIES   = ( ( ( 0x1 << 0 )  | ( ( 0 + 34 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_PRIVATE_PROPERTY_FMTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 35 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_PRIVATE_RESOURCE_PROPERTY_FMTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 36 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_ADD_REGISTRY_CHECKPOINT   = ( ( ( 0x2 << 0 )  | ( ( 0 + 40 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_DELETE_REGISTRY_CHECKPOINT   = ( ( ( 0x2 << 0 )  | ( ( 0 + 41 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_GET_REGISTRY_CHECKPOINTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 42 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_ADD_CRYPTO_CHECKPOINT   = ( ( ( 0x2 << 0 )  | ( ( 0 + 43 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_DELETE_CRYPTO_CHECKPOINT   = ( ( ( 0x2 << 0 )  | ( ( 0 + 44 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_GET_CRYPTO_CHECKPOINTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 45 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_RESOURCE_UPGRADE_DLL   = ( ( ( 0x2 << 0 )  | ( ( 0 + 46 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_ADD_REGISTRY_CHECKPOINT_64BIT   = ( ( ( 0x2 << 0 )  | ( ( 0 + 47 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_ADD_REGISTRY_CHECKPOINT_32BIT   = ( ( ( 0x2 << 0 )  | ( ( 0 + 48 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_GET_LOADBAL_PROCESS_LIST   = ( ( ( 0x1 << 0 )  | ( ( 0 + 50 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_NETWORK_NAME   = ( ( ( 0x1 << 0 )  | ( ( 0 + 90 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_GET_VIRTUAL_SERVER_TOKEN   = ( ( ( 0x1 << 0 )  | ( ( 0 + 91 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_REGISTER_DNS_RECORDS   = ( ( ( 0x2 << 0 )  | ( ( 0 + 92 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_GET_DNS_NAME   = ( ( ( 0x1 << 0 )  | ( ( 0 + 93 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_SET_PWD_INFO   = ( ( ( 0x2 << 0 )  | ( ( 0 + 94 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_DELETE_CO   = ( ( ( 0x2 << 0 )  | ( ( 0 + 95 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_VALIDATE_VCO   = ( ( ( 0x1 << 0 )  | ( ( 0 + 96 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_RESET_VCO   = ( ( ( 0x1 << 0 )  | ( ( 0 + 97 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_NETNAME_CREDS_UPDATED   = ( ( ( ( 0x2 << 0 )  | ( ( 0 + 98 )  << 2 )  )  | ( 0x1 << 22 )  )  | ( 1 << 23 )  ) ,
'CLCTL_STORAGE_GET_DISK_INFO   = ( ( ( 0x1 << 0 )  | ( ( 0 + 100 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_GET_AVAILABLE_DISKS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 101 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_IS_PATH_VALID   = ( ( ( 0x1 << 0 )  | ( ( 0 + 102 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_SYNC_CLUSDISK_DB   = ( ( ( 0x2 << 0 )  | ( ( 0 + 103 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_QUERY_DELETE   = ( ( ( 0x1 << 0 )  | ( ( 0 + 110 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_IPADDRESS_RENEW_LEASE   = ( ( ( 0x2 << 0 )  | ( ( 0 + 111 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_IPADDRESS_RELEASE_LEASE   = ( ( ( 0x2 << 0 )  | ( ( 0 + 112 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_QUERY_MAINTENANCE_MODE   = ( ( ( 0x1 << 0 )  | ( ( 0 + 120 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_SET_MAINTENANCE_MODE   = ( ( ( 0x2 << 0 )  | ( ( 0 + 121 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STORAGE_SET_DRIVELETTER   = ( ( ( 0x2 << 0 )  | ( ( 0 + 122 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STORAGE_GET_DRIVELETTERS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 123 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_GET_DISK_INFO_EX   = ( ( ( 0x1 << 0 )  | ( ( 0 + 124 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_GET_AVAILABLE_DISKS_EX   = ( ( ( 0x1 << 0 )  | ( ( 0 + 125 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_REMAP_DRIVELETTER   = ( ( ( 0x1 << 0 )  | ( ( 0 + 128 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_GET_DISKID   = ( ( ( 0x1 << 0 )  | ( ( 0 + 129 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_IS_CLUSTERABLE   = ( ( ( 0x1 << 0 )  | ( ( 0 + 130 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_REMOVE_VM_OWNERSHIP   = ( ( ( 0x2 << 0 )  | ( ( 0 + 131 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STORAGE_GET_MOUNTPOINTS   = ( ( ( 0x1 << 0 )  | ( ( 0 + 132 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_CLUSTER_DISK   = ( ( ( ( 0x2 << 0 )  | ( ( 0 + 132 )  << 2 )  )  | ( 0x1 << 22 )  )  | ( 1 << 23 )  ) ,
'CLCTL_STORAGE_GET_DIRTY   = ( ( ( 0x1 << 0 )  | ( ( 0 + 134 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_GET_SHARED_VOLUME_INFO   = ( ( ( 0x1 << 0 )  | ( ( 0 + 137 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_IS_CSV_FILE   = ( ( ( 0x1 << 0 )  | ( ( 0 + 138 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_VALIDATE_PATH   = ( ( ( 0x1 << 0 )  | ( ( 0 + 140 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_VALIDATE_NETNAME   = ( ( ( 0x1 << 0 )  | ( ( 0 + 141 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_VALIDATE_DIRECTORY   = ( ( ( 0x1 << 0 )  | ( ( 0 + 142 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_BATCH_BLOCK_KEY   = ( ( ( 0x2 << 0 )  | ( ( 0 + 143 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_BATCH_UNBLOCK_KEY   = ( ( ( 0x1 << 0 )  | ( ( 0 + 144 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_FILESERVER_SHARE_ADD   = ( ( ( 0x1 << 0 )  | ( ( 0 + 145 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FILESERVER_SHARE_DEL   = ( ( ( 0x1 << 0 )  | ( ( 0 + 146 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FILESERVER_SHARE_MODIFY   = ( ( ( 0x1 << 0 )  | ( ( 0 + 147 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FILESERVER_SHARE_REPORT   = ( ( ( 0x1 << 0 )  | ( ( 0 + 148 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_ENABLE_SHARED_VOLUME_DIRECTIO   = ( ( ( 0x2 << 0 )  | ( ( 0 + 162 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_DISABLE_SHARED_VOLUME_DIRECTIO   = ( ( ( 0x2 << 0 )  | ( ( 0 + 163 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_GET_SHARED_VOLUME_ID   = ( ( ( 0x1 << 0 )  | ( ( 0 + 164 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_SET_CSV_MAINTENANCE_MODE   = ( ( ( 0x2 << 0 )  | ( ( 0 + 165 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_SET_SHARED_VOLUME_BACKUP_MODE   = ( ( ( 0x2 << 0 )  | ( ( 0 + 166 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_DELETE   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 1 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_INSTALL_NODE   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 2 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_EVICT_NODE   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 3 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_ADD_DEPENDENCY   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 4 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_REMOVE_DEPENDENCY   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 5 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_ADD_OWNER   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 6 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_REMOVE_OWNER   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 7 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_SET_NAME   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 9 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_CLUSTER_NAME_CHANGED   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 10 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_CLUSTER_VERSION_CHANGED   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 11 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FIXUP_ON_UPGRADE   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 12 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STARTING_PHASE1   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 13 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STARTING_PHASE2   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 14 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_HOLD_IO   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 15 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_RESUME_IO   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 16 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FORCE_QUORUM   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 17 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_INITIALIZE   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 18 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STATE_CHANGE_REASON   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 19 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_PROVIDER_STATE_CHANGE   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 20 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_LEAVING_GROUP   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 21 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_JOINING_GROUP   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 22 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FSWITNESS_GET_EPOCH_INFO   = ( ( ( ( 0x1 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 23 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_FSWITNESS_SET_EPOCH_INFO   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 24 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_FSWITNESS_RELEASE_LOCK   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 25 )  << 2 )  )  | ( 0x1 << 22 )  )
'CLCTL_NETNAME_CREDS_NOTIFYCAM   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 26 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_STORAGE_GET_DISK_NUMBER   = ( ( ( ( 0x1 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 27 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_STORAGE_GET_CSV_DISK_INFO   = ( ( ( ( 0x1 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 28 )  << 2 )  )  | ( 0 << 22 )  ) ,
'CLCTL_SET_CLUSTER_MEMBERSHIP   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 29 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_SET_SHARED_PR_KEY   = ( ( ( ( 0x2 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 30 )  << 2 )  )  | ( 0x1 << 22 )  ) ,
'CLCTL_QUERY_CSV_MAINTENANCE_MODE   = ( ( ( ( 0x1 << 0 )  | ( 1 << 20 )  )  | ( ( 0 + 31 )  << 2 )  )  | ( 0 << 22 )  )
'}  CLCTL_CODES;

' enum CLCTL_CODES
%CLCTL_UNKNOWN                            = &H00000000???
%CLCTL_GET_CHARACTERISTICS                = &H00000005???
%CLCTL_GET_FLAGS                          = &H00000009???
%CLCTL_GET_CLASS_INFO                     = &H0000000d???
%CLCTL_GET_REQUIRED_DEPENDENCIES          = &H00000011???
%CLCTL_GET_ARB_TIMEOUT                    = &H00000015???
%CLCTL_GET_NAME                           = &H00000029???
%CLCTL_GET_RESOURCE_TYPE                  = &H0000002d???
%CLCTL_GET_NODE                           = &H00000031???
%CLCTL_GET_NETWORK                        = &H00000035???
%CLCTL_GET_ID                             = &H00000039???
%CLCTL_GET_FQDN                           = &H0000003d???
%CLCTL_GET_CLUSTER_SERVICE_ACCOUNT_NAME   = &H00000041???
%CLCTL_CHECK_VOTER_EVICT                  = &H00000045???
%CLCTL_CHECK_VOTER_DOWN                   = &H00000049???
%CLCTL_SHUTDOWN                           = &H0000004d???
%CLCTL_ENUM_COMMON_PROPERTIES             = &H00000051???
%CLCTL_GET_RO_COMMON_PROPERTIES           = &H00000055???
%CLCTL_GET_COMMON_PROPERTIES              = &H00000059???
%CLCTL_SET_COMMON_PROPERTIES              = &H0040005e???
%CLCTL_VALIDATE_COMMON_PROPERTIES         = &H00000061???
%CLCTL_GET_COMMON_PROPERTY_FMTS           = &H00000065???
%CLCTL_GET_COMMON_RESOURCE_PROPERTY_FMTS  = &H00000069???
%CLCTL_ENUM_PRIVATE_PROPERTIES            = &H00000079???
%CLCTL_GET_RO_PRIVATE_PROPERTIES          = &H0000007d???
%CLCTL_GET_PRIVATE_PROPERTIES             = &H00000081???
%CLCTL_SET_PRIVATE_PROPERTIES             = &H00400086???
%CLCTL_VALIDATE_PRIVATE_PROPERTIES        = &H00000089???
%CLCTL_GET_PRIVATE_PROPERTY_FMTS          = &H0000008d???
%CLCTL_GET_PRIVATE_RESOURCE_PROPERTY_FMTS = &H00000091???
%CLCTL_ADD_REGISTRY_CHECKPOINT            = &H004000a2???
%CLCTL_DELETE_REGISTRY_CHECKPOINT         = &H004000a6???
%CLCTL_GET_REGISTRY_CHECKPOINTS           = &H000000a9???
%CLCTL_ADD_CRYPTO_CHECKPOINT              = &H004000ae???
%CLCTL_DELETE_CRYPTO_CHECKPOINT           = &H004000b2???
%CLCTL_GET_CRYPTO_CHECKPOINTS             = &H000000b5???
%CLCTL_RESOURCE_UPGRADE_DLL               = &H004000ba???
%CLCTL_ADD_REGISTRY_CHECKPOINT_64BIT      = &H004000be???
%CLCTL_ADD_REGISTRY_CHECKPOINT_32BIT      = &H004000c2???
%CLCTL_GET_LOADBAL_PROCESS_LIST           = &H000000c9???
%CLCTL_GET_NETWORK_NAME                   = &H00000169???
%CLCTL_NETNAME_GET_VIRTUAL_SERVER_TOKEN   = &H0000016d???
%CLCTL_NETNAME_REGISTER_DNS_RECORDS       = &H00000172???
%CLCTL_GET_DNS_NAME                       = &H00000175???
%CLCTL_NETNAME_SET_PWD_INFO               = &H0000017a???
%CLCTL_NETNAME_DELETE_CO                  = &H0000017e???
%CLCTL_NETNAME_VALIDATE_VCO               = &H00000181???
%CLCTL_NETNAME_RESET_VCO                  = &H00000185???
%CLCTL_NETNAME_CREDS_UPDATED              = &H00c0018a???
%CLCTL_STORAGE_GET_DISK_INFO              = &H00000191???
%CLCTL_STORAGE_GET_AVAILABLE_DISKS        = &H00000195???
%CLCTL_STORAGE_IS_PATH_VALID              = &H00000199???
'%CLCTL_STORAGE_GET_ALL_AVAILABLE_DISKS    = &H0000019d???   ' Removed in the SDK for Windows Server 2008
%CLCTL_STORAGE_SYNC_CLUSDISK_DB           = &H0040019e???
%CLCTL_QUERY_DELETE                       = &H000001b9???
%CLCTL_IPADDRESS_RENEW_LEASE              = &H004001be???
%CLCTL_IPADDRESS_RELEASE_LEASE            = &H004001c2???
%CLCTL_QUERY_MAINTENANCE_MODE             = &H000001e1???
%CLCTL_SET_MAINTENANCE_MODE               = &H004001e6???
%CLCTL_STORAGE_SET_DRIVELETTER            = &H004001ea???
%CLCTL_STORAGE_GET_DRIVELETTERS           = &H000001ed???
%CLCTL_STORAGE_GET_DISK_INFO_EX           = &H000001f1???
%CLCTL_STORAGE_GET_AVAILABLE_DISKS_EX     = &H000001f5???
%CLCTL_STORAGE_REMAP_DRIVELETTER          = &H00000201???
%CLCTL_STORAGE_GET_DISKID                 = &H00000205???
%CLCTL_STORAGE_IS_CLUSTERABLE             = &H00000209???
%CLCTL_STORAGE_REMOVE_VM_OWNERSHIP        = &H0000020e???
%CLCTL_STORAGE_GET_MOUNTPOINTS            = &H00000211???
%CLCTL_STORAGE_CLUSTER_DISK               = &H00c00212???
%CLCTL_STORAGE_GET_DIRTY                  = &H00000219???
%CLCTL_STORAGE_GET_SHARED_VOLUME_INFO     = &H00000225???
%CLCTL_STORAGE_IS_CSV_FILE                = &H00000229???
%CLCTL_VALIDATE_PATH                      = &H00000231???
%CLCTL_VALIDATE_NETNAME                   = &H00000235???
%CLCTL_VALIDATE_DIRECTORY                 = &H00000239???
%CLCTL_BATCH_BLOCK_KEY                    = &H0000023e???
%CLCTL_BATCH_UNBLOCK_KEY                  = &H00000241???
%CLCTL_FILESERVER_SHARE_ADD               = &H00400245???
%CLCTL_FILESERVER_SHARE_DEL               = &H00400249???
%CLCTL_FILESERVER_SHARE_MODIFY            = &H0040024d???
%CLCTL_FILESERVER_SHARE_REPORT            = &H00400251???
%CLCTL_ENABLE_SHARED_VOLUME_DIRECTIO      = &H0040028a???
%CLCTL_DISABLE_SHARED_VOLUME_DIRECTIO     = &H0040028e???
%CLCTL_GET_SHARED_VOLUME_ID               = &H00000291???
%CLCTL_SET_CSV_MAINTENANCE_MODE           = &H00400296???
%CLCTL_SET_SHARED_VOLUME_BACKUP_MODE      = &H0040029a???
%CLCTL_DELETE                             = &H00500006???
%CLCTL_INSTALL_NODE                       = &H0050000a???
%CLCTL_EVICT_NODE                         = &H0050000e???
%CLCTL_ADD_DEPENDENCY                     = &H00500012???
%CLCTL_REMOVE_DEPENDENCY                  = &H00500016???
%CLCTL_ADD_OWNER                          = &H0050001a???
%CLCTL_REMOVE_OWNER                       = &H0050001e???
%CLCTL_SET_NAME                           = &H00500026???
%CLCTL_CLUSTER_NAME_CHANGED               = &H0050002a???
%CLCTL_CLUSTER_VERSION_CHANGED            = &H0050002e???
%CLCTL_FIXUP_ON_UPGRADE                   = &H00500032???
%CLCTL_STARTING_PHASE1                    = &H00500036???
%CLCTL_STARTING_PHASE2                    = &H0050003a???
%CLCTL_HOLD_IO                            = &H0050003e???
%CLCTL_RESUME_IO                          = &H00500042???
%CLCTL_FORCE_QUORUM                       = &H00500046???
%CLCTL_INITIALIZE                         = &H0050004a???
%CLCTL_STATE_CHANGE_REASON                = &H0050004e???
%CLCTL_PROVIDER_STATE_CHANGE              = &H00500052???
%CLCTL_LEAVING_GROUP                      = &H00500056???
%CLCTL_JOINING_GROUP                      = &H0050005a???
%CLCTL_FSWITNESS_GET_EPOCH_INFO           = &H0010005d???
%CLCTL_FSWITNESS_SET_EPOCH_INFO           = &H00500062???
%CLCTL_FSWITNESS_RELEASE_LOCK             = &H00500066???
%CLCTL_NETNAME_CREDS_NOTIFYCAM            = &H0050006a???
%CLCTL_STORAGE_GET_DISK_NUMBER            = &H0010006d???
%CLCTL_STORAGE_GET_CSV_DISK_INFO          = &H00100071???
%CLCTL_SET_CLUSTER_MEMBERSHIP             = &H00500076???
%CLCTL_SET_SHARED_PR_KEY                  = &H0050007A???
%CLCTL_QUERY_CSV_MAINTENANCE_MODE         = &H0010007d???

'typedef
'enum CLUSCTL_RESOURCE_CODES
'{   CLUSCTL_RESOURCE_UNKNOWN   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_RESOURCE_GET_CHARACTERISTICS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_CHARACTERISTICS ) ,
'CLUSCTL_RESOURCE_GET_FLAGS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_FLAGS ) ,
'CLUSCTL_RESOURCE_GET_CLASS_INFO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_CLASS_INFO ) ,
'CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_REQUIRED_DEPENDENCIES ) ,
'CLUSCTL_RESOURCE_GET_NAME   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_NAME ) ,
'CLUSCTL_RESOURCE_GET_ID   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_ID ) ,
'CLUSCTL_RESOURCE_GET_RESOURCE_TYPE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_RESOURCE_TYPE ) ,
'CLUSCTL_RESOURCE_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_RESOURCE_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS ) ,
'CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ADD_REGISTRY_CHECKPOINT ) ,
'CLUSCTL_RESOURCE_DELETE_REGISTRY_CHECKPOINT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_DELETE_REGISTRY_CHECKPOINT ) ,
'CLUSCTL_RESOURCE_GET_REGISTRY_CHECKPOINTS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_REGISTRY_CHECKPOINTS ) ,
'CLUSCTL_RESOURCE_ADD_CRYPTO_CHECKPOINT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ADD_CRYPTO_CHECKPOINT ) ,
'CLUSCTL_RESOURCE_DELETE_CRYPTO_CHECKPOINT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_DELETE_CRYPTO_CHECKPOINT ) ,
'CLUSCTL_RESOURCE_GET_CRYPTO_CHECKPOINTS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_CRYPTO_CHECKPOINTS ) ,
'CLUSCTL_RESOURCE_GET_LOADBAL_PROCESS_LIST   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_LOADBAL_PROCESS_LIST ) ,
'CLUSCTL_RESOURCE_GET_NETWORK_NAME   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_NETWORK_NAME ) ,
'CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_GET_VIRTUAL_SERVER_TOKEN ) ,
'CLUSCTL_RESOURCE_NETNAME_SET_PWD_INFO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_SET_PWD_INFO ) ,
'CLUSCTL_RESOURCE_NETNAME_DELETE_CO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_DELETE_CO ) ,
'CLUSCTL_RESOURCE_NETNAME_VALIDATE_VCO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_VALIDATE_VCO ) ,
'CLUSCTL_RESOURCE_NETNAME_RESET_VCO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_RESET_VCO ) ,
'CLUSCTL_RESOURCE_NETNAME_REGISTER_DNS_RECORDS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_REGISTER_DNS_RECORDS ) ,
'CLUSCTL_RESOURCE_GET_DNS_NAME   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_GET_DNS_NAME ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_DISK_INFO ) ,
'CLUSCTL_RESOURCE_STORAGE_IS_PATH_VALID   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_IS_PATH_VALID ) ,
'CLUSCTL_RESOURCE_QUERY_DELETE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_QUERY_DELETE ) ,
'CLUSCTL_RESOURCE_UPGRADE_DLL   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_RESOURCE_UPGRADE_DLL ) ,
'CLUSCTL_RESOURCE_IPADDRESS_RENEW_LEASE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_IPADDRESS_RENEW_LEASE ) ,
'CLUSCTL_RESOURCE_IPADDRESS_RELEASE_LEASE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_IPADDRESS_RELEASE_LEASE ) ,
'CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_64BIT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ADD_REGISTRY_CHECKPOINT_64BIT ) ,
'CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_32BIT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ADD_REGISTRY_CHECKPOINT_32BIT ) ,
'CLUSCTL_RESOURCE_QUERY_MAINTENANCE_MODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_QUERY_MAINTENANCE_MODE ) ,
'CLUSCTL_RESOURCE_SET_MAINTENANCE_MODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_MAINTENANCE_MODE ) ,
'CLUSCTL_RESOURCE_STORAGE_SET_DRIVELETTER   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_SET_DRIVELETTER ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO_EX   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_DISK_INFO_EX ) ,
'CLUSCTL_RESOURCE_FILESERVER_SHARE_ADD   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_FILESERVER_SHARE_ADD ) ,
'CLUSCTL_RESOURCE_FILESERVER_SHARE_DEL   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_FILESERVER_SHARE_DEL ) ,
'CLUSCTL_RESOURCE_FILESERVER_SHARE_MODIFY   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_FILESERVER_SHARE_MODIFY ) ,
'CLUSCTL_RESOURCE_FILESERVER_SHARE_REPORT   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_FILESERVER_SHARE_REPORT ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_MOUNTPOINTS   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_MOUNTPOINTS ) ,
'CLUSCTL_RESOURCE_STORAGE_CLUSTER_DISK   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_CLUSTER_DISK ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_DIRTY   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_DIRTY ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_SHARED_VOLUME_INFO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_SHARED_VOLUME_INFO ) ,
'CLUSCTL_RESOURCE_SET_CSV_MAINTENANCE_MODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_CSV_MAINTENANCE_MODE ) ,
'CLUSCTL_RESOURCE_ENABLE_SHARED_VOLUME_DIRECTIO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ENABLE_SHARED_VOLUME_DIRECTIO ) ,
'CLUSCTL_RESOURCE_DISABLE_SHARED_VOLUME_DIRECTIO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_DISABLE_SHARED_VOLUME_DIRECTIO ) ,
'CLUSCTL_RESOURCE_SET_SHARED_VOLUME_BACKUP_MODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_SHARED_VOLUME_BACKUP_MODE ) ,
'CLUSCTL_RESOURCE_DELETE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_DELETE ) ,
'CLUSCTL_RESOURCE_INSTALL_NODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_INSTALL_NODE ) ,
'CLUSCTL_RESOURCE_EVICT_NODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_EVICT_NODE ) ,
'CLUSCTL_RESOURCE_ADD_DEPENDENCY   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ADD_DEPENDENCY ) ,
'CLUSCTL_RESOURCE_REMOVE_DEPENDENCY   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_REMOVE_DEPENDENCY ) ,
'CLUSCTL_RESOURCE_ADD_OWNER   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_ADD_OWNER ) ,
'CLUSCTL_RESOURCE_REMOVE_OWNER   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_REMOVE_OWNER ) ,
'CLUSCTL_RESOURCE_SET_NAME   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_NAME ) ,
'CLUSCTL_RESOURCE_CLUSTER_NAME_CHANGED   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_CLUSTER_NAME_CHANGED ) ,
'CLUSCTL_RESOURCE_CLUSTER_VERSION_CHANGED   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_CLUSTER_VERSION_CHANGED ) ,
'CLUSCTL_RESOURCE_FORCE_QUORUM   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_FORCE_QUORUM ) ,
'CLUSCTL_RESOURCE_INITIALIZE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_INITIALIZE ) ,
'CLUSCTL_RESOURCE_STATE_CHANGE_REASON   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STATE_CHANGE_REASON ) ,
'CLUSCTL_RESOURCE_PROVIDER_STATE_CHANGE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_PROVIDER_STATE_CHANGE )
'CLUSCTL_RESOURCE_NETNAME_CREDS_NOTIFYCAM   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_NETNAME_CREDS_NOTIFYCAM ) ,
'CLUSCTL_RESOURCE_SET_CLUSTER_MEMBERSHIP   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_CLUSTER_MEMBERSHIP ) ,
'CLUSCTL_RESOURCE_SET_SHARED_PR_KEY   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_SET_SHARED_PR_KEY ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_DISK_NUMBER   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_DISK_NUMBER ) ,
'CLUSCTL_RESOURCE_STORAGE_GET_CSV_DISK_INFO   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_GET_CSV_DISK_INFO ) ,
'CLUSCTL_RESOURCE_QUERY_CSV_MAINTENANCE_MODE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_QUERY_CSV_MAINTENANCE_MODE )
'}    CLUSCTL_RESOURCE_CODES;

%CLUSCTL_RESOURCE_UNKNOWN                            = &H01000000???
%CLUSCTL_RESOURCE_GET_CHARACTERISTICS                = &H01000005???
%CLUSCTL_RESOURCE_GET_FLAGS                          = &H01000009???
%CLUSCTL_RESOURCE_GET_CLASS_INFO                     = &H0100000d???
%CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES          = &H01000011???
%CLUSCTL_RESOURCE_GET_NAME                           = &H01000029???
%CLUSCTL_RESOURCE_GET_ID                             = &H01000039???
%CLUSCTL_RESOURCE_GET_RESOURCE_TYPE                  = &H0100002d???
%CLUSCTL_RESOURCE_ENUM_COMMON_PROPERTIES             = &H01000051???
%CLUSCTL_RESOURCE_GET_RO_COMMON_PROPERTIES           = &H01000055???
%CLUSCTL_RESOURCE_GET_COMMON_PROPERTIES              = &H01000059???
%CLUSCTL_RESOURCE_SET_COMMON_PROPERTIES              = &H0140005e???
%CLUSCTL_RESOURCE_VALIDATE_COMMON_PROPERTIES         = &H01000061???
%CLUSCTL_RESOURCE_GET_COMMON_PROPERTY_FMTS           = &H01000065???
%CLUSCTL_RESOURCE_ENUM_PRIVATE_PROPERTIES            = &H01000079???
%CLUSCTL_RESOURCE_GET_RO_PRIVATE_PROPERTIES          = &H0100007d???
%CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTIES             = &H01000081???
%CLUSCTL_RESOURCE_SET_PRIVATE_PROPERTIES             = &H01400086???
%CLUSCTL_RESOURCE_VALIDATE_PRIVATE_PROPERTIES        = &H01000089???
%CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTY_FMTS          = &H0100008d???
%CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT            = &H014000a2???
%CLUSCTL_RESOURCE_DELETE_REGISTRY_CHECKPOINT         = &H014000a6???
%CLUSCTL_RESOURCE_GET_REGISTRY_CHECKPOINTS           = &H010000a9???
%CLUSCTL_RESOURCE_ADD_CRYPTO_CHECKPOINT              = &H014000ae???
%CLUSCTL_RESOURCE_DELETE_CRYPTO_CHECKPOINT           = &H014000b2???
%CLUSCTL_RESOURCE_GET_CRYPTO_CHECKPOINTS             = &H010000b5???
%CLUSCTL_RESOURCE_GET_LOADBAL_PROCESS_LIST           = &H010000c9???
%CLUSCTL_RESOURCE_GET_NETWORK_NAME                   = &H01000169???
%CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN   = &H0100016d???
%CLUSCTL_RESOURCE_NETNAME_SET_PWD_INFO               = &H0100017a???
%CLUSCTL_RESOURCE_NETNAME_DELETE_CO                  = &H0100017e???
%CLUSCTL_RESOURCE_NETNAME_VALIDATE_VCO               = &H01000181???
%CLUSCTL_RESOURCE_NETNAME_RESET_VCO                  = &H01000185???
%CLUSCTL_RESOURCE_NETNAME_REGISTER_DNS_RECORDS       = &H01000172???
%CLUSCTL_RESOURCE_GET_DNS_NAME                       = &H01000175???
%CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO              = &H01000191???
%CLUSCTL_RESOURCE_STORAGE_IS_PATH_VALID              = &H01000199???
%CLUSCTL_RESOURCE_QUERY_DELETE                       = &H010001b9???
%CLUSCTL_RESOURCE_UPGRADE_DLL                        = &H014000ba???
%CLUSCTL_RESOURCE_IPADDRESS_RENEW_LEASE              = &H014001be???
%CLUSCTL_RESOURCE_IPADDRESS_RELEASE_LEASE            = &H014001c2???
%CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_64BIT      = &H014000be???
%CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_32BIT      = &H014000c2???
%CLUSCTL_RESOURCE_QUERY_MAINTENANCE_MODE             = &H010001e1???
%CLUSCTL_RESOURCE_SET_MAINTENANCE_MODE               = &H014001e6???
%CLUSCTL_RESOURCE_STORAGE_SET_DRIVELETTER            = &H014001ea???
%CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO_EX           = &H010001f1???
%CLUSCTL_RESOURCE_FILESERVER_SHARE_ADD               = &H01400245???
%CLUSCTL_RESOURCE_FILESERVER_SHARE_DEL               = &H01400249???
%CLUSCTL_RESOURCE_FILESERVER_SHARE_MODIFY            = &H0140024d???
%CLUSCTL_RESOURCE_FILESERVER_SHARE_REPORT            = &H01400251???
%CLUSCTL_RESOURCE_STORAGE_GET_MOUNTPOINTS            = &H01000211???
%CLUSCTL_RESOURCE_STORAGE_CLUSTER_DISK               = &H01c00212???
%CLUSCTL_RESOURCE_STORAGE_GET_DIRTY                  = &H01000219???
%CLUSCTL_RESOURCE_STORAGE_GET_SHARED_VOLUME_INFO     = &H01000225???
%CLUSCTL_RESOURCE_SET_CSV_MAINTENANCE_MODE           = &H01400296???
%CLUSCTL_RESOURCE_ENABLE_SHARED_VOLUME_DIRECTIO      = &H0140028a???
%CLUSCTL_RESOURCE_DISABLE_SHARED_VOLUME_DIRECTIO     = &H0140028e???
%CLUSCTL_RESOURCE_SET_SHARED_VOLUME_BACKUP_MODE      = &H0140029a???
%CLUSCTL_RESOURCE_DELETE                             = &H01500006???
%CLUSCTL_RESOURCE_INSTALL_NODE                       = &H0150000a???
%CLUSCTL_RESOURCE_EVICT_NODE                         = &H0150000e???
%CLUSCTL_RESOURCE_ADD_DEPENDENCY                     = &H01500012???
%CLUSCTL_RESOURCE_REMOVE_DEPENDENCY                  = &H01500016???
%CLUSCTL_RESOURCE_ADD_OWNER                          = &H0150001a???
%CLUSCTL_RESOURCE_REMOVE_OWNER                       = &H0150001e???
%CLUSCTL_RESOURCE_SET_NAME                           = &H01500026???
%CLUSCTL_RESOURCE_CLUSTER_NAME_CHANGED               = &H0150002a???
%CLUSCTL_RESOURCE_CLUSTER_VERSION_CHANGED            = &H0150002e???
%CLUSCTL_RESOURCE_FORCE_QUORUM                       = &H01500046???
%CLUSCTL_RESOURCE_INITIALIZE                         = &H0150004a???
%CLUSCTL_RESOURCE_STATE_CHANGE_REASON                = &H0150004e???
%CLUSCTL_RESOURCE_PROVIDER_STATE_CHANGE              = &H01500052???
%CLUSCTL_RESOURCE_LEAVING_GROUP                      = &H01500056???
%CLUSCTL_RESOURCE_JOINING_GROUP                      = &H0150005a???
%CLUSCTL_RESOURCE_FSWITNESS_GET_EPOCH_INFO           = &H0110005d???
%CLUSCTL_RESOURCE_FSWITNESS_SET_EPOCH_INFO           = &H01500062???
%CLUSCTL_RESOURCE_FSWITNESS_RELEASE_LOCK             = &H01500066???
%CLUSCTL_RESOURCE_NETNAME_CREDS_UPDATED              = &H01c0018a???
%CLUSCTL_RESOURCE_NETNAME_CREDS_NOTIFYCAM            = &H0150006a???
%CLUSCTL_RESOURCE_SET_CLUSTER_MEMBERSHIP             = &H01500076???
%CLUSCTL_RESOURCE_SET_SHARED_PR_KEY                  = &H0150007A???
%CLUSCTL_RESOURCE_STORAGE_GET_DISK_NUMBER            = &H0110006d???
%CLUSCTL_RESOURCE_STORAGE_GET_CSV_DISK_INFO          = &H01100071???
%CLUSCTL_RESOURCE_QUERY_CSV_MAINTENANCE_MODE         = &H0110007d???

'typedef
'enum CLUSCTL_RESOURCE_TYPE_CODES
'{   CLUSCTL_RESOURCE_TYPE_UNKNOWN   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_RESOURCE_TYPE_GET_CHARACTERISTICS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_CHARACTERISTICS ) ,
'CLUSCTL_RESOURCE_TYPE_GET_FLAGS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_FLAGS ) ,
'CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_CLASS_INFO ) ,
'CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_REQUIRED_DEPENDENCIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_ARB_TIMEOUT   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_ARB_TIMEOUT ) ,
'CLUSCTL_RESOURCE_TYPE_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_RESOURCE_TYPE_GET_COMMON_RESOURCE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_COMMON_RESOURCE_PROPERTY_FMTS ) ,
'CLUSCTL_RESOURCE_TYPE_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS ) ,
'CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_RESOURCE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_PRIVATE_RESOURCE_PROPERTY_FMTS ) ,
'CLUSCTL_RESOURCE_TYPE_GET_REGISTRY_CHECKPOINTS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_REGISTRY_CHECKPOINTS ) ,
'CLUSCTL_RESOURCE_TYPE_GET_CRYPTO_CHECKPOINTS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_GET_CRYPTO_CHECKPOINTS ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_GET_AVAILABLE_DISKS ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_SYNC_CLUSDISK_DB   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_SYNC_CLUSDISK_DB ) ,
'CLUSCTL_RESOURCE_TYPE_NETNAME_VALIDATE_NETNAME   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_NETNAME ) ,
'CLUSCTL_RESOURCE_TYPE_GEN_APP_VALIDATE_PATH   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_PATH ) ,
'CLUSCTL_RESOURCE_TYPE_GEN_APP_VALIDATE_DIRECTORY   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_DIRECTORY ) ,
'CLUSCTL_RESOURCE_TYPE_GEN_SCRIPT_VALIDATE_PATH   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_PATH ) ,
'CLUSCTL_RESOURCE_TYPE_QUERY_DELETE   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_QUERY_DELETE ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DRIVELETTERS   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_GET_DRIVELETTERS ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_GET_AVAILABLE_DISKS_EX ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_REMAP_DRIVELETTER   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_REMAP_DRIVELETTER ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DISKID   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_GET_DISKID ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_IS_CLUSTERABLE   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_IS_CLUSTERABLE ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_REMOVE_VM_OWNERSHIP   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STORAGE_REMOVE_VM_OWNERSHIP ) ,
'CLUSCTL_RESOURCE_TYPE_STORAGE_IS_CSV_FILE   = ( ( CLUS_OBJECT_RESOURCE << 24 )  | CLCTL_STORAGE_IS_CSV_FILE ) ,
'CLUSCTL_RESOURCE_TYPE_WITNESS_VALIDATE_PATH   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_VALIDATE_PATH ) ,
'CLUSCTL_RESOURCE_TYPE_INSTALL_NODE   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_INSTALL_NODE ) ,
'CLUSCTL_RESOURCE_TYPE_EVICT_NODE   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_EVICT_NODE ) ,
'CLUSCTL_RESOURCE_TYPE_CLUSTER_VERSION_CHANGED   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_CLUSTER_VERSION_CHANGED ) ,
'CLUSCTL_RESOURCE_TYPE_FIXUP_ON_UPGRADE   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_FIXUP_ON_UPGRADE ) ,
'CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STARTING_PHASE1 ) ,
'CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_STARTING_PHASE2 ) ,
'CLUSCTL_RESOURCE_TYPE_HOLD_IO   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_HOLD_IO ) ,
'CLUSCTL_RESOURCE_TYPE_RESUME_IO   = ( ( CLUS_OBJECT_RESOURCE_TYPE << 24 )  | CLCTL_RESUME_IO )
'}    CLUSCTL_RESOURCE_TYPE_CODES;

%CLUSCTL_RESOURCE_TYPE_UNKNOWN                              = &H02000000???
%CLUSCTL_RESOURCE_TYPE_GET_CHARACTERISTICS                  = &H02000005???
%CLUSCTL_RESOURCE_TYPE_GET_FLAGS                            = &H02000009???
%CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO                       = &H0200000d???
%CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES            = &H02000011???
%CLUSCTL_RESOURCE_TYPE_GET_ARB_TIMEOUT                      = &H02000015???
%CLUSCTL_RESOURCE_TYPE_ENUM_COMMON_PROPERTIES               = &H02000051???
%CLUSCTL_RESOURCE_TYPE_GET_RO_COMMON_PROPERTIES             = &H02000055???
%CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTIES                = &H02000059???
%CLUSCTL_RESOURCE_TYPE_VALIDATE_COMMON_PROPERTIES           = &H02000061???
%CLUSCTL_RESOURCE_TYPE_SET_COMMON_PROPERTIES                = &H0240005e???
%CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTY_FMTS             = &H02000065???
%CLUSCTL_RESOURCE_TYPE_GET_COMMON_RESOURCE_PROPERTY_FMTS    = &H02000069???
%CLUSCTL_RESOURCE_TYPE_ENUM_PRIVATE_PROPERTIES              = &H02000079???
%CLUSCTL_RESOURCE_TYPE_GET_RO_PRIVATE_PROPERTIES            = &H0200007d???
%CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTIES               = &H02000081???
%CLUSCTL_RESOURCE_TYPE_SET_PRIVATE_PROPERTIES               = &H02400086???
%CLUSCTL_RESOURCE_TYPE_VALIDATE_PRIVATE_PROPERTIES          = &H02000089???
%CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTY_FMTS            = &H0200008d???
%CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_RESOURCE_PROPERTY_FMTS   = &H02000091???
%CLUSCTL_RESOURCE_TYPE_GET_REGISTRY_CHECKPOINTS             = &H020000a9???
%CLUSCTL_RESOURCE_TYPE_GET_CRYPTO_CHECKPOINTS               = &H020000b5???
%CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS          = &H02000195???
%CLUSCTL_RESOURCE_TYPE_STORAGE_SYNC_CLUSDISK_DB             = &H0240019e???
%CLUSCTL_RESOURCE_TYPE_NETNAME_VALIDATE_NETNAME             = &H02000235???
%CLUSCTL_RESOURCE_TYPE_GEN_APP_VALIDATE_PATH                = &H02000231???
%CLUSCTL_RESOURCE_TYPE_GEN_APP_VALIDATE_DIRECTORY           = &H02000239???
%CLUSCTL_RESOURCE_TYPE_GEN_SCRIPT_VALIDATE_PATH             = &H02000231???
%CLUSCTL_RESOURCE_TYPE_QUERY_DELETE                         = &H020001b9???
%CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DRIVELETTERS             = &H020001ed???
%CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX       = &H020001f5???
%CLUSCTL_RESOURCE_TYPE_STORAGE_REMAP_DRIVELETTER            = &H02000201???
%CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DISKID                   = &H02000205???
%CLUSCTL_RESOURCE_TYPE_STORAGE_IS_CLUSTERABLE               = &H02000209???
%CLUSCTL_RESOURCE_TYPE_STORAGE_REMOVE_VM_OWNERSHIP          = &H0200020e???
%CLUSCTL_RESOURCE_TYPE_STORAGE_IS_CSV_FILE                  = &H01000229???
%CLUSCTL_RESOURCE_TYPE_WITNESS_VALIDATE_PATH                = &H02000231???
%CLUSCTL_RESOURCE_TYPE_INSTALL_NODE                         = &H0250000a???
%CLUSCTL_RESOURCE_TYPE_EVICT_NODE                           = &H0250000e???
%CLUSCTL_RESOURCE_TYPE_CLUSTER_VERSION_CHANGED              = &H0250002e???
%CLUSCTL_RESOURCE_TYPE_FIXUP_ON_UPGRADE                     = &H02500032???
%CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1                      = &H02500036???
%CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2                      = &H0250003a???
%CLUSCTL_RESOURCE_TYPE_HOLD_IO                              = &H0250003e???
%CLUSCTL_RESOURCE_TYPE_RESUME_IO                            = &H02500042???

'typedef
'enum CLUSCTL_GROUP_CODES
'{   CLUSCTL_GROUP_UNKNOWN   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_GROUP_GET_CHARACTERISTICS   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_CHARACTERISTICS ) ,
'CLUSCTL_GROUP_GET_FLAGS   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_FLAGS ) ,
'CLUSCTL_GROUP_GET_NAME   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_NAME ) ,
'CLUSCTL_GROUP_GET_ID   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_ID ) ,
'CLUSCTL_GROUP_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_GROUP_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_GROUP_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_GROUP_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_GROUP_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_GROUP_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_GROUP_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_GROUP_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_GROUP_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_GROUP_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_GROUP_QUERY_DELETE   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_QUERY_DELETE ) ,
'CLUSCTL_GROUP_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_GROUP_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_GROUP << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS )
'}    CLUSCTL_GROUP_CODES;

%CLUSCTL_GROUP_UNKNOWN                       = &H03000000???
%CLUSCTL_GROUP_GET_CHARACTERISTICS           = &H03000005???
%CLUSCTL_GROUP_GET_FLAGS                     = &H03000009???
%CLUSCTL_GROUP_GET_NAME                      = &H03000029???
%CLUSCTL_GROUP_GET_ID                        = &H03000039???
%CLUSCTL_GROUP_ENUM_COMMON_PROPERTIES        = &H03000051???
%CLUSCTL_GROUP_GET_RO_COMMON_PROPERTIES      = &H03000055???
%CLUSCTL_GROUP_GET_COMMON_PROPERTIES         = &H03000059???
%CLUSCTL_GROUP_SET_COMMON_PROPERTIES         = &H0340005e???
%CLUSCTL_GROUP_VALIDATE_COMMON_PROPERTIES    = &H03000061???
%CLUSCTL_GROUP_ENUM_PRIVATE_PROPERTIES       = &H03000079???
%CLUSCTL_GROUP_GET_RO_PRIVATE_PROPERTIES     = &H0300007d???
%CLUSCTL_GROUP_GET_PRIVATE_PROPERTIES        = &H03000081???
%CLUSCTL_GROUP_SET_PRIVATE_PROPERTIES        = &H03400086???
%CLUSCTL_GROUP_VALIDATE_PRIVATE_PROPERTIES   = &H03000089???
%CLUSCTL_GROUP_QUERY_DELETE                  = &H030001b9???
%CLUSCTL_GROUP_GET_COMMON_PROPERTY_FMTS      = &H03000065???
%CLUSCTL_GROUP_GET_PRIVATE_PROPERTY_FMTS     = &H0300008d???

'typedef
'enum CLUSCTL_NODE_CODES
'{   CLUSCTL_NODE_UNKNOWN   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_NODE_GET_CHARACTERISTICS   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_CHARACTERISTICS ) ,
'CLUSCTL_NODE_GET_FLAGS   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_FLAGS ) ,
'CLUSCTL_NODE_GET_NAME   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_NAME ) ,
'CLUSCTL_NODE_GET_ID   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_ID ) ,
'CLUSCTL_NODE_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_NODE_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_NODE_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_NODE_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_NODE_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_NODE_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NODE_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NODE_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NODE_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NODE_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NODE_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_NODE_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS ) ,
'CLUSCTL_NODE_GET_CLUSTER_SERVICE_ACCOUNT_NAME   = ( ( CLUS_OBJECT_NODE << 24 )  | CLCTL_GET_CLUSTER_SERVICE_ACCOUNT_NAME )
'}    CLUSCTL_NODE_CODES;

%CLUSCTL_NODE_UNKNOWN                            = &H04000000???
%CLUSCTL_NODE_GET_CHARACTERISTICS                = &H04000005???
%CLUSCTL_NODE_GET_FLAGS                          = &H04000009???
%CLUSCTL_NODE_GET_NAME                           = &H04000029???
%CLUSCTL_NODE_GET_ID                             = &H04000039???
%CLUSCTL_NODE_ENUM_COMMON_PROPERTIES             = &H04000051???
%CLUSCTL_NODE_GET_RO_COMMON_PROPERTIES           = &H04000055???
%CLUSCTL_NODE_GET_COMMON_PROPERTIES              = &H04000059???
%CLUSCTL_NODE_SET_COMMON_PROPERTIES              = &H0440005e???
%CLUSCTL_NODE_VALIDATE_COMMON_PROPERTIES         = &H04000061???
%CLUSCTL_NODE_ENUM_PRIVATE_PROPERTIES            = &H04000079???
%CLUSCTL_NODE_GET_RO_PRIVATE_PROPERTIES          = &H0400007d???
%CLUSCTL_NODE_GET_PRIVATE_PROPERTIES             = &H04000081???
%CLUSCTL_NODE_SET_PRIVATE_PROPERTIES             = &H04400086???
%CLUSCTL_NODE_VALIDATE_PRIVATE_PROPERTIES        = &H04000089???
%CLUSCTL_NODE_GET_COMMON_PROPERTY_FMTS           = &H04000065???
%CLUSCTL_NODE_GET_PRIVATE_PROPERTY_FMTS          = &H0400008d???
%CLUSCTL_NODE_GET_CLUSTER_SERVICE_ACCOUNT_NAME   = &H04000041???

'typedef
'enum CLUSCTL_NETWORK_CODES
'{   CLUSCTL_NETWORK_UNKNOWN   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_NETWORK_GET_CHARACTERISTICS   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_CHARACTERISTICS ) ,
'CLUSCTL_NETWORK_GET_FLAGS   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_FLAGS ) ,
'CLUSCTL_NETWORK_GET_NAME   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_NAME ) ,
'CLUSCTL_NETWORK_GET_ID   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_ID ) ,
'CLUSCTL_NETWORK_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_NETWORK_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_NETWORK_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_NETWORK_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_NETWORK_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_NETWORK_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETWORK_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETWORK_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETWORK_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETWORK_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETWORK_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_NETWORK_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_NETWORK << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS )
'}    CLUSCTL_NETWORK_CODES;

%CLUSCTL_NETWORK_UNKNOWN                       = &H05000000???
%CLUSCTL_NETWORK_GET_CHARACTERISTICS           = &H05000005???
%CLUSCTL_NETWORK_GET_FLAGS                     = &H05000009???
%CLUSCTL_NETWORK_GET_NAME                      = &H05000029???
%CLUSCTL_NETWORK_GET_ID                        = &H05000039???
%CLUSCTL_NETWORK_ENUM_COMMON_PROPERTIES        = &H05000051???
%CLUSCTL_NETWORK_GET_RO_COMMON_PROPERTIES      = &H05000055???
%CLUSCTL_NETWORK_GET_COMMON_PROPERTIES         = &H05000059???
%CLUSCTL_NETWORK_SET_COMMON_PROPERTIES         = &H0540005e???
%CLUSCTL_NETWORK_VALIDATE_COMMON_PROPERTIES    = &H05000061???
%CLUSCTL_NETWORK_ENUM_PRIVATE_PROPERTIES       = &H05000079???
%CLUSCTL_NETWORK_GET_RO_PRIVATE_PROPERTIES     = &H0500007d???
%CLUSCTL_NETWORK_GET_PRIVATE_PROPERTIES        = &H05000081???
%CLUSCTL_NETWORK_SET_PRIVATE_PROPERTIES        = &H05400086???
%CLUSCTL_NETWORK_VALIDATE_PRIVATE_PROPERTIES   = &H05000089???
%CLUSCTL_NETWORK_GET_COMMON_PROPERTY_FMTS      = &H05000065???
%CLUSCTL_NETWORK_GET_PRIVATE_PROPERTY_FMTS     = &H0500008d???

'typedef
'enum CLUSCTL_NETINTERFACE_CODES
'{   CLUSCTL_NETINTERFACE_UNKNOWN   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_NETINTERFACE_GET_CHARACTERISTICS   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_CHARACTERISTICS ) ,
'CLUSCTL_NETINTERFACE_GET_FLAGS   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_FLAGS ) ,
'CLUSCTL_NETINTERFACE_GET_NAME   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_NAME ) ,
'CLUSCTL_NETINTERFACE_GET_ID   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_ID ) ,
'CLUSCTL_NETINTERFACE_GET_NODE   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_NODE ) ,
'CLUSCTL_NETINTERFACE_GET_NETWORK   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_NETWORK ) ,
'CLUSCTL_NETINTERFACE_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_NETINTERFACE_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_NETINTERFACE_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_NETINTERFACE << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS )
'}    CLUSCTL_NETINTERFACE_CODES;

%CLUSCTL_NETINTERFACE_UNKNOWN                       = &H06000000???
%CLUSCTL_NETINTERFACE_GET_CHARACTERISTICS           = &H06000005???
%CLUSCTL_NETINTERFACE_GET_FLAGS                     = &H06000009???
%CLUSCTL_NETINTERFACE_GET_NAME                      = &H06000029???
%CLUSCTL_NETINTERFACE_GET_ID                        = &H06000039???
%CLUSCTL_NETINTERFACE_GET_NODE                      = &H06000031???
%CLUSCTL_NETINTERFACE_GET_NETWORK                   = &H06000035???
%CLUSCTL_NETINTERFACE_ENUM_COMMON_PROPERTIES        = &H06000051???
%CLUSCTL_NETINTERFACE_GET_RO_COMMON_PROPERTIES      = &H06000055???
%CLUSCTL_NETINTERFACE_GET_COMMON_PROPERTIES         = &H06000059???
%CLUSCTL_NETINTERFACE_SET_COMMON_PROPERTIES         = &H0640005e???
%CLUSCTL_NETINTERFACE_VALIDATE_COMMON_PROPERTIES    = &H06000061???
%CLUSCTL_NETINTERFACE_ENUM_PRIVATE_PROPERTIES       = &H06000079???
%CLUSCTL_NETINTERFACE_GET_RO_PRIVATE_PROPERTIES     = &H0600007d???
%CLUSCTL_NETINTERFACE_GET_PRIVATE_PROPERTIES        = &H06000081???
%CLUSCTL_NETINTERFACE_SET_PRIVATE_PROPERTIES        = &H06400086???
%CLUSCTL_NETINTERFACE_VALIDATE_PRIVATE_PROPERTIES   = &H06000089???
%CLUSCTL_NETINTERFACE_GET_COMMON_PROPERTY_FMTS      = &H06000065???
%CLUSCTL_NETINTERFACE_GET_PRIVATE_PROPERTY_FMTS     = &H0600008d???

'typedef
'enum CLUSCTL_CLUSTER_CODES
'{   CLUSCTL_CLUSTER_UNKNOWN   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_UNKNOWN ) ,
'CLUSCTL_CLUSTER_GET_FQDN   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_FQDN ) ,
'CLUSCTL_CLUSTER_ENUM_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_ENUM_COMMON_PROPERTIES ) ,
'CLUSCTL_CLUSTER_GET_RO_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_RO_COMMON_PROPERTIES ) ,
'CLUSCTL_CLUSTER_GET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_COMMON_PROPERTIES ) ,
'CLUSCTL_CLUSTER_SET_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_SET_COMMON_PROPERTIES ) ,
'CLUSCTL_CLUSTER_VALIDATE_COMMON_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_VALIDATE_COMMON_PROPERTIES ) ,
'CLUSCTL_CLUSTER_ENUM_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_ENUM_PRIVATE_PROPERTIES ) ,
'CLUSCTL_CLUSTER_GET_RO_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_RO_PRIVATE_PROPERTIES ) ,
'CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_CLUSTER_SET_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_SET_PRIVATE_PROPERTIES ) ,
'CLUSCTL_CLUSTER_VALIDATE_PRIVATE_PROPERTIES   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_VALIDATE_PRIVATE_PROPERTIES ) ,
'CLUSCTL_CLUSTER_GET_COMMON_PROPERTY_FMTS   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_COMMON_PROPERTY_FMTS ) ,
'CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTY_FMTS   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_PRIVATE_PROPERTY_FMTS ) ,
'CLUSCTL_CLUSTER_CHECK_VOTER_EVICT   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_CHECK_VOTER_EVICT ) ,
'CLUSCTL_CLUSTER_CHECK_VOTER_DOWN   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_CHECK_VOTER_DOWN ) ,
'CLUSCTL_CLUSTER_SHUTDOWN   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_SHUTDOWN ) ,
'CLUSCTL_CLUSTER_BATCH_BLOCK_KEY   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_BATCH_BLOCK_KEY ) ,
'CLUSCTL_CLUSTER_BATCH_UNBLOCK_KEY   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_BATCH_UNBLOCK_KEY )
'CLUSCTL_CLUSTER_GET_SHARED_VOLUME_ID   = ( ( CLUS_OBJECT_CLUSTER << 24 )  | CLCTL_GET_SHARED_VOLUME_ID )
'}    CLUSCTL_CLUSTER_CODES;

%CLUSCTL_CLUSTER_UNKNOWN                       = &H07000000???
%CLUSCTL_CLUSTER_GET_FQDN                      = &H0700003d???
%CLUSCTL_CLUSTER_ENUM_COMMON_PROPERTIES        = &H07000051???
%CLUSCTL_CLUSTER_GET_RO_COMMON_PROPERTIES      = &H07000055???
%CLUSCTL_CLUSTER_GET_COMMON_PROPERTIES         = &H07000059???
%CLUSCTL_CLUSTER_SET_COMMON_PROPERTIES         = &H0740005e???
%CLUSCTL_CLUSTER_VALIDATE_COMMON_PROPERTIES    = &H07000061???
%CLUSCTL_CLUSTER_ENUM_PRIVATE_PROPERTIES       = &H07000079???
%CLUSCTL_CLUSTER_GET_RO_PRIVATE_PROPERTIES     = &H0700007d???
%CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTIES        = &H07000081???
%CLUSCTL_CLUSTER_SET_PRIVATE_PROPERTIES        = &H07400086???
%CLUSCTL_CLUSTER_VALIDATE_PRIVATE_PROPERTIES   = &H07000089???
%CLUSCTL_CLUSTER_GET_COMMON_PROPERTY_FMTS      = &H07000065???
%CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTY_FMTS     = &H0700008d???
%CLUSCTL_CLUSTER_CHECK_VOTER_EVICT             = &H07000045???
%CLUSCTL_CLUSTER_CHECK_VOTER_DOWN              = &H07000049???
%CLUSCTL_CLUSTER_SHUTDOWN                      = &H0700004d???
%CLUSCTL_CLUSTER_BATCH_BLOCK_KEY               = &H0700023e???
%CLUSCTL_CLUSTER_BATCH_UNBLOCK_KEY             = &H07000241???
%CLUSCTL_CLUSTER_GET_SHARED_VOLUME_ID          = &H07000291???

' enum CLUSTER_RESOURCE_CLASS enum
%CLUS_RESCLASS_UNKNOWN   = 0
%CLUS_RESCLASS_STORAGE   = %CLUS_RESCLASS_UNKNOWN + 1
%CLUS_RESCLASS_NETWORK   = %CLUS_RESCLASS_STORAGE + 1
%CLUS_RESCLASS_USER      = 32768

' enum CLUS_RESSUBCLASS
%CLUS_RESSUBCLASS_SHARED = &H80000000???

' enum CLUS_RESSUBCLASS_STORAGE
%CLUS_RESSUBCLASS_STORAGE_SHARED_BUS = &H80000000???

' enum CLUS_RESSUBCLASS_NETWORK
%CLUS_RESSUBCLASS_NETWORK_INTERNET_PROTOCOL = &H80000000???

' enum CLUS_CHARACTERISTICS
%CLUS_CHAR_UNKNOWN                      = 0
%CLUS_CHAR_QUORUM                       = &H1
%CLUS_CHAR_DELETE_REQUIRES_ALL_NODES    = &H2
%CLUS_CHAR_LOCAL_QUORUM                 = &H4
%CLUS_CHAR_LOCAL_QUORUM_DEBUG           = &H8
%CLUS_CHAR_REQUIRES_STATE_CHANGE_REASON = &H10
%CLUS_CHAR_BROADCAST_DELETE             = &H20
%CLUS_CHAR_SINGLE_CLUSTER_INSTANCE      = &H40
%CLUS_CHAR_SINGLE_GROUP_INSTANCE        = &H80

' enum CLUS_FLAGS
%CLUS_FLAG_CORE = &H1

' enum CLUSPROP_PIFLAGS
%CLUSPROP_PIFLAG_STICKY         = &H1
%CLUSPROP_PIFLAG_REMOVABLE      = &H2
%CLUSPROP_PIFLAG_USABLE         = &H4
%CLUSPROP_PIFLAG_DEFAULT_QUORUM = &H8

' enum CLUSTER_RESOURCE_ENUM
%CLUSTER_RESOURCE_ENUM_DEPENDS  = &H1
%CLUSTER_RESOURCE_ENUM_PROVIDES = &H2
%CLUSTER_RESOURCE_ENUM_NODES    = &H4
%CLUSTER_RESOURCE_ENUM_ALL      = %CLUSTER_RESOURCE_ENUM_DEPENDS OR %CLUSTER_RESOURCE_ENUM_PROVIDES OR %CLUSTER_RESOURCE_ENUM_NODES

' enum CLUSTER_RESOURCE_TYPE_ENUM
%CLUSTER_RESOURCE_TYPE_ENUM_NODES = &H1
%CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES   = &H2
%CLUSTER_RESOURCE_TYPE_ENUM_ALL   = %CLUSTER_RESOURCE_TYPE_ENUM_NODES OR %CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES

' enum CLUSTER_NETWORK_ENUM
%CLUSTER_NETWORK_ENUM_NETINTERFACES = &H1
%CLUSTER_NETWORK_ENUM_ALL           = %CLUSTER_NETWORK_ENUM_NETINTERFACES

' enum CLUSTER_NETWORK_STATE
%ClusterNetworkStateUnknown = -1
%ClusterNetworkUnavailable  = %ClusterNetworkStateUnknown + 1
%ClusterNetworkDown         = %ClusterNetworkUnavailable  + 1
%ClusterNetworkPartitioned  = %ClusterNetworkDown         + 1
%ClusterNetworkUp           = %ClusterNetworkPartitioned  + 1

' enum CLUSTER_NETWORK_ROLE
%ClusterNetworkRoleNone              = 0
%ClusterNetworkRoleInternalUse       = &H1
%ClusterNetworkRoleClientAccess      = &H2
%ClusterNetworkRoleInternalAndClient = &H3

' enum CLUSTER_NETINTERFACE_STATE
%ClusterNetInterfaceStateUnknown = -1
%ClusterNetInterfaceUnavailable  = %ClusterNetInterfaceStateUnknown + 1
%ClusterNetInterfaceFailed       = %ClusterNetInterfaceUnavailable  + 1
%ClusterNetInterfaceUnreachable  = %ClusterNetInterfaceFailed       + 1
%ClusterNetInterfaceUp           = %ClusterNetInterfaceUnreachable  + 1

' ########################################################################################
' Interface name = ISClusApplication
' IID = {F2E606E6-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusApplication_INTERFACE_DEFINED)
    %ISClusApplication_INTERFACE_DEFINED = 1

INTERFACE ISClusApplication $IID_ISClusApplication

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DomainNames <1> ( _                     ' VTable offset = 28
   ) AS ISDomainNames                                   ' __retval_out ISDomainNames **ppDomains
   ' =====================================================================================
   PROPERTY GET ClusterNames <2> ( _                    ' VTable offset = 32
     BYVAL bstrDomainName AS WSTRING _                  ' __in BSTR bstrDomainName
   ) AS ISClusterNames                                  ' __retval_out ISClusterNames **ppClusters
   ' =====================================================================================
   METHOD OpenCluster <3> ( _                           ' VTable offset = 36
     BYVAL bstrClusterName AS WSTRING _                 ' __in BSTR bstrClusterName
   ) AS ISCluster                                       ' __retval_out ISCluster **pCluster
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISDomainNames
' IID = {F2E606E2-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISDomainNames_INTERFACE_DEFINED)
    %ISDomainNames_INTERFACE_DEFINED = 1

INTERFACE ISDomainNames $IID_ISDomainNames

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDomainName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISDomainNames_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusterNames
' IID = {F2E606EC-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusterNames_INTERFACE_DEFINED)
    %ISClusterNames_INTERFACE_DEFINED = 1

INTERFACE ISClusterNames $IID_ISClusterNames

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrClusterName
   ' =====================================================================================
   PROPERTY GET DomainName <3> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDomainName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusterNames_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusRefObject
' IID = {F2E60702-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusRefObject_INTERFACE_DEFINED)
    %ISClusRefObject_INTERFACE_DEFINED = 1

INTERFACE ISClusRefObject $IID_ISClusRefObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Handle <1> ( _                          ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusRefObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusVersion
' IID = {F2E60716-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusVersion_INTERFACE_DEFINED)
    %ISClusVersion_INTERFACE_DEFINED = 1

INTERFACE ISClusVersion $IID_ISClusVersion

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrClusterName
   ' =====================================================================================
   PROPERTY GET MajorVersion <2> ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pnMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pnMinorVersion
   ' =====================================================================================
   PROPERTY GET BuildNumber <4> ( _                     ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out SHORT *pnBuildNumber
   ' =====================================================================================
   PROPERTY GET VendorId <5> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVendorId
   ' =====================================================================================
   PROPERTY GET CSDVersion <6> ( _                      ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSDVersion
   ' =====================================================================================
   PROPERTY GET ClusterHighestVersion <7> ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pnClusterHighestVersion
   ' =====================================================================================
   PROPERTY GET ClusterLowestVersion <8> ( _            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pnClusterLowestVersion
   ' =====================================================================================
   PROPERTY GET Flags <9> ( _                           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pnFlags
   ' =====================================================================================
   PROPERTY GET MixedVersion <10> ( _                   ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMixedVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusVersion_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISCluster
' IID = {F2E606E4-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCluster_INTERFACE_DEFINED)
    %ISCluster_INTERFACE_DEFINED = 1

INTERFACE ISCluster $IID_ISCluster

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Handle <5> ( _                          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================
   METHOD Open <6> ( _                                  ' VTable offset = 48
     BYVAL bstrClusterName AS WSTRING _                 ' __in BSTR bstrClusterName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <7> ( _                            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <7> ( _                            ' VTable offset = 56
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <8> ( _                         ' VTable offset = 60
   ) AS ISClusVersion                                   ' __retval_out ISClusVersion **ppClusVersion
   ' =====================================================================================
   PROPERTY SET QuorumResource <9> ( _                  ' VTable offset = 64
     BYVAL pClusterResource AS ISClusResource _         ' __in ISClusResource *pClusterResource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QuorumResource <9> ( _                  ' VTable offset = 68
   ) AS ISClusResource                                  ' __retval_out ISClusResource **pClusterResource
   ' =====================================================================================
   PROPERTY GET QuorumLogSize <10> ( _                  ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *pnLogSize
   ' =====================================================================================
   PROPERTY SET QuorumLogSize <10> ( _                  ' VTable offset = 76
     BYVAL pnLogSize AS LONG _                          ' __in long pnLogSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QuorumPath <11> ( _                     ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *ppPath
   ' =====================================================================================
   PROPERTY SET QuorumPath <11> ( _                     ' VTable offset = 84
     BYVAL ppPath AS WSTRING _                          ' __in BSTR ppPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Nodes <12> ( _                          ' VTable offset = 88
   ) AS ISClusNodes                                     ' __retval_out ISClusNodes **ppNodes
   ' =====================================================================================
   PROPERTY GET ResourceGroups <13> ( _                 ' VTable offset = 92
   ) AS ISClusResGroups                                 ' __retval_out ISClusResGroups **ppClusterResourceGroups
   ' =====================================================================================
   PROPERTY GET Resources <14> ( _                      ' VTable offset = 96
   ) AS ISClusResources                                 ' __retval_out ISClusResources **ppClusterResources
   ' =====================================================================================
   PROPERTY GET ResourceTypes <15> ( _                  ' VTable offset = 100
   ) AS ISClusResTypes                                  ' __retval_out ISClusResTypes **ppResourceTypes
   ' =====================================================================================
   PROPERTY GET Networks <16> ( _                       ' VTable offset = 104
   ) AS ISClusNetworks                                  ' __retval_out ISClusNetworks **ppNetworks
   ' =====================================================================================
   PROPERTY GET NetInterfaces <17> ( _                  ' VTable offset = 108
   ) AS ISClusNetInterfaces                             ' __retval_out ISClusNetInterfaces **ppNetInterfaces
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCluster_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNode
' IID = {F2E606F8-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNode_INTERFACE_DEFINED)
    %ISClusNode_INTERFACE_DEFINED = 1

INTERFACE ISClusNode $IID_ISClusNode

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Name <5> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Handle <6> ( _                          ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================
   PROPERTY GET NodeID <7> ( _                          ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNodeID
   ' =====================================================================================
   PROPERTY GET State <8> ( _                           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out CLUSTER_NODE_STATE *dwState
   ' =====================================================================================
   METHOD Pause <9> ( _                                 ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <10> ( _                               ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD Evict <11> ( _                                ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResourceGroups <12> ( _                 ' VTable offset = 72
   ) AS ISClusResGroups                                 ' __retval_out ISClusResGroups **ppResourceGroups
   ' =====================================================================================
   PROPERTY GET Cluster <13> ( _                        ' VTable offset = 76
   ) AS ISCluster                                       ' __retval_out ISCluster **ppCluster
   ' =====================================================================================
   PROPERTY GET NetInterfaces <14> ( _                  ' VTable offset = 80
   ) AS ISClusNodeNetInterfaces                         ' __retval_out ISClusNodeNetInterfaces **ppClusNetInterfaces
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNode_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNodes
' IID = {F2E606FA-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNodes_INTERFACE_DEFINED)
    %ISClusNodes_INTERFACE_DEFINED = 1

INTERFACE ISClusNodes $IID_ISClusNodes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNode                                      ' __retval_out ISClusNode **ppNode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNetwork
' IID = {F2E606F2-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNetwork_INTERFACE_DEFINED)
    %ISClusNetwork_INTERFACE_DEFINED = 1

INTERFACE ISClusNetwork $IID_ISClusNetwork

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Handle <5> ( _                          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================
   PROPERTY GET Name <6> ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <6> ( _                            ' VTable offset = 52
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkID <7> ( _                       ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNetworkID
   ' =====================================================================================
   PROPERTY GET State <8> ( _                           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CLUSTER_NETWORK_STATE *dwState
   ' =====================================================================================
   PROPERTY GET NetInterfaces <9> ( _                   ' VTable offset = 64
   ) AS ISClusNetworkNetInterfaces                      ' __retval_out ISClusNetworkNetInterfaces **ppClusNetInterfaces
   ' =====================================================================================
   PROPERTY GET Cluster <10> ( _                        ' VTable offset = 68
   ) AS ISCluster                                       ' __retval_out ISCluster **ppCluster
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNetwork_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNetworks
' IID = {F2E606F4-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNetworks_INTERFACE_DEFINED)
    %ISClusNetworks_INTERFACE_DEFINED = 1

INTERFACE ISClusNetworks $IID_ISClusNetworks

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNetwork                                   ' __retval_out ISClusNetwork **ppClusNetwork
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNetworks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNetInterface
' IID = {F2E606EE-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNetInterface_INTERFACE_DEFINED)
    %ISClusNetInterface_INTERFACE_DEFINED = 1

INTERFACE ISClusNetInterface $IID_ISClusNetInterface

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Name <5> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Handle <6> ( _                          ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================
   PROPERTY GET State <7> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out CLUSTER_NETINTERFACE_STATE *dwState
   ' =====================================================================================
   PROPERTY GET Cluster <8> ( _                         ' VTable offset = 56
   ) AS ISCluster                                       ' __retval_out ISCluster **ppCluster
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNetInterface_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNetInterfaces
' IID = {F2E606F0-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNetInterfaces_INTERFACE_DEFINED)
    %ISClusNetInterfaces_INTERFACE_DEFINED = 1

INTERFACE ISClusNetInterfaces $IID_ISClusNetInterfaces

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNetInterface                              ' __retval_out ISClusNetInterface **ppClusNetInterface
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNetInterfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNodeNetInterfaces
' IID = {F2E606FC-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNodeNetInterfaces_INTERFACE_DEFINED)
    %ISClusNodeNetInterfaces_INTERFACE_DEFINED = 1

INTERFACE ISClusNodeNetInterfaces $IID_ISClusNodeNetInterfaces

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNetInterface                              ' __retval_out ISClusNetInterface **ppClusNetInterface
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNodeNetInterfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusNetworkNetInterfaces
' IID = {F2E606F6-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusNetworkNetInterfaces_INTERFACE_DEFINED)
    %ISClusNetworkNetInterfaces_INTERFACE_DEFINED = 1

INTERFACE ISClusNetworkNetInterfaces $IID_ISClusNetworkNetInterfaces

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNetInterface                              ' __retval_out ISClusNetInterface **ppClusNetInterface
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusNetworkNetInterfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResGroup
' IID = {F2E60706-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResGroup_INTERFACE_DEFINED)
    %ISClusResGroup_INTERFACE_DEFINED = 1

INTERFACE ISClusResGroup $IID_ISClusResGroup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Handle <5> ( _                          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================
   PROPERTY GET Name <6> ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <6> ( _                            ' VTable offset = 52
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <7> ( _                           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out CLUSTER_GROUP_STATE *dwState
   ' =====================================================================================
   PROPERTY GET OwnerNode <8> ( _                       ' VTable offset = 60
   ) AS ISClusNode                                      ' __retval_out ISClusNode **ppOwnerNode
   ' =====================================================================================
   PROPERTY GET Resources <9> ( _                       ' VTable offset = 64
   ) AS ISClusResGroupResources                         ' __retval_out ISClusResGroupResources **ppClusterGroupResources
   ' =====================================================================================
   PROPERTY GET PreferredOwnerNodes <10> ( _            ' VTable offset = 68
   ) AS ISClusResGroupPreferredOwnerNodes               ' __retval_out ISClusResGroupPreferredOwnerNodes **ppOwnerNodes
   ' =====================================================================================
   METHOD Delete <11> ( _                               ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD Online <12> ( _                               ' VTable offset = 76
     BYVAL varTimeout AS VARIANT _                      ' __in VARIANT varTimeout
   , OPTIONAL BYVAL varNode AS VARIANT _                ' __in_opt VARIANT varNode
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPending
   ' =====================================================================================
   METHOD Move <13> ( _                                 ' VTable offset = 80
     BYVAL varTimeout AS VARIANT _                      ' __in VARIANT varTimeout
   , OPTIONAL BYVAL varNode AS VARIANT _                ' __in_opt VARIANT varNode
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPending
   ' =====================================================================================
   METHOD Offline <14> ( _                              ' VTable offset = 84
     BYVAL varTimeout AS VARIANT _                      ' __in VARIANT varTimeout
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPending
   ' =====================================================================================
   PROPERTY GET Cluster <15> ( _                        ' VTable offset = 88
   ) AS ISCluster                                       ' __retval_out ISCluster **ppCluster
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResGroups
' IID = {F2E60708-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResGroups_INTERFACE_DEFINED)
    %ISClusResGroups_INTERFACE_DEFINED = 1

INTERFACE ISClusResGroups $IID_ISClusResGroups

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResGroup                                  ' __retval_out ISClusResGroup **ppClusResGroup
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceGroupName AS WSTRING _           ' __in BSTR bstrResourceGroupName
   ) AS ISClusResGroup                                  ' __retval_out ISClusResGroup **ppResourceGroup
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResGroups_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResource
' IID = {F2E6070A-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResource_INTERFACE_DEFINED)
    %ISClusResource_INTERFACE_DEFINED = 1

INTERFACE ISClusResource $IID_ISClusResource

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Handle <5> ( _                          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG_PTR *phandle
   ' =====================================================================================
   PROPERTY GET Name <6> ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <6> ( _                            ' VTable offset = 52
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <7> ( _                           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out CLUSTER_RESOURCE_STATE *dwState
   ' =====================================================================================
   PROPERTY GET CoreFlag <8> ( _                        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CLUS_FLAGS *dwCoreFlag
   ' =====================================================================================
   METHOD BecomeQuorumResource <9> ( _                  ' VTable offset = 64
     BYVAL bstrDevicePath AS WSTRING _                  ' __in BSTR bstrDevicePath
   , BYVAL lMaxLogSize AS LONG _                        ' __in long lMaxLogSize
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <10> ( _                               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD Fail <11> ( _                                 ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD Online <12> ( _                               ' VTable offset = 76
     BYVAL nTimeout AS LONG _                           ' __in long nTimeout
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPending
   ' =====================================================================================
   METHOD Offline <13> ( _                              ' VTable offset = 80
     BYVAL nTimeout AS LONG _                           ' __in long nTimeout
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPending
   ' =====================================================================================
   METHOD ChangeResourceGroup <14> ( _                  ' VTable offset = 84
     BYVAL pResourceGroup AS ISClusResGroup _           ' __in ISClusResGroup *pResourceGroup
   )                                                    ' void
   ' =====================================================================================
   METHOD AddResourceNode <15> ( _                      ' VTable offset = 88
     BYVAL pNode AS ISClusNode _                        ' __in ISClusNode *pNode
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveResourceNode <16> ( _                   ' VTable offset = 92
     BYVAL pNode AS ISClusNode _                        ' __in ISClusNode *pNode
   )                                                    ' void
   ' =====================================================================================
   METHOD CanResourceBeDependent <17> ( _               ' VTable offset = 96
     BYVAL pResource AS ISClusResource _                ' __in ISClusResource *pResource
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDependent
   ' =====================================================================================
   PROPERTY GET PossibleOwnerNodes <18> ( _             ' VTable offset = 100
   ) AS ISClusResPossibleOwnerNodes                     ' __retval_out ISClusResPossibleOwnerNodes **ppOwnerNodes
   ' =====================================================================================
   PROPERTY GET Dependencies <19> ( _                   ' VTable offset = 104
   ) AS ISClusResDependencies                           ' __retval_out ISClusResDependencies **ppResDependencies
   ' =====================================================================================
   PROPERTY GET Dependents <20> ( _                     ' VTable offset = 108
   ) AS ISClusResDependents                             ' __retval_out ISClusResDependents **ppResDependents
   ' =====================================================================================
   PROPERTY GET Group <21> ( _                          ' VTable offset = 112
   ) AS ISClusResGroup                                  ' __retval_out ISClusResGroup **ppResGroup
   ' =====================================================================================
   PROPERTY GET OwnerNode <22> ( _                      ' VTable offset = 116
   ) AS ISClusNode                                      ' __retval_out ISClusNode **ppOwnerNode
   ' =====================================================================================
   PROPERTY GET Cluster <23> ( _                        ' VTable offset = 120
   ) AS ISCluster                                       ' __retval_out ISCluster **ppCluster
   ' =====================================================================================
   PROPERTY GET ClassInfo <24> ( _                      ' VTable offset = 124
   ) AS LONG                                            ' __retval_out CLUSTER_RESOURCE_CLASS *prcClassInfo
   ' =====================================================================================
   PROPERTY GET Disk <25> ( _                           ' VTable offset = 128
   ) AS ISClusDisk                                      ' __retval_out ISClusDisk **ppDisk
   ' =====================================================================================
   PROPERTY GET RegistryKeys <26> ( _                   ' VTable offset = 132
   ) AS ISClusRegistryKeys                              ' __retval_out ISClusRegistryKeys **ppRegistryKeys
   ' =====================================================================================
   PROPERTY GET CryptoKeys <27> ( _                     ' VTable offset = 136
   ) AS ISClusCryptoKeys                                ' __retval_out ISClusCryptoKeys **ppCryptoKeys
   ' =====================================================================================
   PROPERTY GET TypeName <28> ( _                       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET Type <29> ( _                           ' VTable offset = 144
   ) AS ISClusResType                                   ' __retval_out ISClusResType **ppResourceType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResDependencies
' IID = {F2E60704-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResDependencies_INTERFACE_DEFINED)
    %ISClusResDependencies_INTERFACE_DEFINED = 1

INTERFACE ISClusResDependencies $IID_ISClusResDependencies

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusResource
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceName AS WSTRING _                ' __in BSTR bstrResourceName
   , BYVAL bstrResourceType AS WSTRING _                ' __in BSTR bstrResourceType
   , BYVAL dwFlags AS LONG _                            ' __in CLUSTER_RESOURCE_CREATE_FLAGS dwFlags
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusterResource
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD AddItem <5> ( _                               ' VTable offset = 52
     BYVAL pResource AS ISClusResource _                ' __in ISClusResource *pResource
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveItem <6> ( _                            ' VTable offset = 56
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResDependencies_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResGroupResources
' IID = {F2E606EA-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResGroupResources_INTERFACE_DEFINED)
    %ISClusResGroupResources_INTERFACE_DEFINED = 1

INTERFACE ISClusResGroupResources $IID_ISClusResGroupResources

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusResource
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceName AS WSTRING _                ' __in BSTR bstrResourceName
   , BYVAL bstrResourceType AS WSTRING _                ' __in BSTR bstrResourceType
   , BYVAL dwFlags AS LONG _                            ' __in CLUSTER_RESOURCE_CREATE_FLAGS dwFlags
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusterResource
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResGroupResources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResTypeResources
' IID = {F2E60714-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResTypeResources_INTERFACE_DEFINED)
    %ISClusResTypeResources_INTERFACE_DEFINED = 1

INTERFACE ISClusResTypeResources $IID_ISClusResTypeResources

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusResource
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceName AS WSTRING _                ' __in BSTR bstrResourceName
   , BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , BYVAL dwFlags AS LONG _                            ' __in CLUSTER_RESOURCE_CREATE_FLAGS dwFlags
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusterResource
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResTypeResources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResources
' IID = {F2E6070C-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResources_INTERFACE_DEFINED)
    %ISClusResources_INTERFACE_DEFINED = 1

INTERFACE ISClusResources $IID_ISClusResources

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusResource
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceName AS WSTRING _                ' __in BSTR bstrResourceName
   , BYVAL bstrResourceType AS WSTRING _                ' __in BSTR bstrResourceType
   , BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , BYVAL dwFlags AS LONG _                            ' __in CLUSTER_RESOURCE_CREATE_FLAGS dwFlags
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusterResource
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResGroupPreferredOwnerNodes
' IID = {F2E606E8-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResGroupPreferredOwnerNodes_INTERFACE_DEFINED)
    %ISClusResGroupPreferredOwnerNodes_INTERFACE_DEFINED = 1

INTERFACE ISClusResGroupPreferredOwnerNodes $IID_ISClusResGroupPreferredOwnerNodes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNode                                      ' __retval_out ISClusNode **ppNode
   ' =====================================================================================
   METHOD InsertItem <3> ( _                            ' VTable offset = 44
     BYVAL pNode AS ISClusNode _                        ' __in ISClusNode *pNode
   , BYVAL nPosition AS LONG _                          ' __in long nPosition
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modified <5> ( _                        ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModified
   ' =====================================================================================
   METHOD SaveChanges <6> ( _                           ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD AddItem <7> ( _                               ' VTable offset = 60
     BYVAL pNode AS ISClusNode _                        ' __in ISClusNode *pNode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResGroupPreferredOwnerNodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResPossibleOwnerNodes
' IID = {F2E6070E-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResPossibleOwnerNodes_INTERFACE_DEFINED)
    %ISClusResPossibleOwnerNodes_INTERFACE_DEFINED = 1

INTERFACE ISClusResPossibleOwnerNodes $IID_ISClusResPossibleOwnerNodes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNode                                      ' __retval_out ISClusNode **ppNode
   ' =====================================================================================
   METHOD AddItem <3> ( _                               ' VTable offset = 44
     BYVAL pNode AS ISClusNode _                        ' __in ISClusNode *pNode
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modified <5> ( _                        ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModified
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResPossibleOwnerNodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResTypePossibleOwnerNodes
' IID = {F2E60718-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResTypePossibleOwnerNodes_INTERFACE_DEFINED)
    %ISClusResTypePossibleOwnerNodes_INTERFACE_DEFINED = 1

INTERFACE ISClusResTypePossibleOwnerNodes $IID_ISClusResTypePossibleOwnerNodes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusNode                                      ' __retval_out ISClusNode **ppNode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResTypePossibleOwnerNodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResType
' IID = {F2E60710-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResType_INTERFACE_DEFINED)
    %ISClusResType_INTERFACE_DEFINED = 1

INTERFACE ISClusResType $IID_ISClusResType

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommonProperties <1> ( _                ' VTable offset = 28
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateProperties <2> ( _               ' VTable offset = 32
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET CommonROProperties <3> ( _              ' VTable offset = 36
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET PrivateROProperties <4> ( _             ' VTable offset = 40
   ) AS ISClusProperties                                ' __retval_out ISClusProperties **ppProperties
   ' =====================================================================================
   PROPERTY GET Name <5> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   METHOD Delete <6> ( _                                ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Cluster <7> ( _                         ' VTable offset = 52
   ) AS ISCluster                                       ' __retval_out ISCluster **ppCluster
   ' =====================================================================================
   PROPERTY GET Resources <8> ( _                       ' VTable offset = 56
   ) AS ISClusResTypeResources                          ' __retval_out ISClusResTypeResources **ppClusterResTypeResources
   ' =====================================================================================
   PROPERTY GET PossibleOwnerNodes <9> ( _              ' VTable offset = 60
   ) AS ISClusResTypePossibleOwnerNodes                 ' __retval_out ISClusResTypePossibleOwnerNodes **ppOwnerNodes
   ' =====================================================================================
   PROPERTY GET AvailableDisks <10> ( _                 ' VTable offset = 64
   ) AS ISClusDisks                                     ' __retval_out ISClusDisks **ppAvailableDisks
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResTypes
' IID = {F2E60712-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResTypes_INTERFACE_DEFINED)
    %ISClusResTypes_INTERFACE_DEFINED = 1

INTERFACE ISClusResTypes $IID_ISClusResTypes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResType                                   ' __retval_out ISClusResType **ppClusResType
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceTypeName AS WSTRING _            ' __in BSTR bstrResourceTypeName
   , BYVAL bstrDisplayName AS WSTRING _                 ' __in BSTR bstrDisplayName
   , BYVAL bstrResourceTypeDll AS WSTRING _             ' __in BSTR bstrResourceTypeDll
   , BYVAL dwLooksAlivePollInterval AS LONG _           ' __in long dwLooksAlivePollInterval
   , BYVAL dwIsAlivePollInterval AS LONG _              ' __in long dwIsAlivePollInterval
   ) AS ISClusResType                                   ' __retval_out ISClusResType **ppResourceType
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusProperty
' IID = {F2E606FE-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusProperty_INTERFACE_DEFINED)
    %ISClusProperty_INTERFACE_DEFINED = 1

INTERFACE ISClusProperty $IID_ISClusProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Length <2> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pLength
   ' =====================================================================================
   PROPERTY GET ValueCount <3> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   PROPERTY GET Values <4> ( _                          ' VTable offset = 40
   ) AS ISClusPropertyValues                            ' __retval_out ISClusPropertyValues **ppClusterPropertyValues
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 48
     BYVAL pvarValue AS VARIANT _                       ' __in VARIANT pvarValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <5> ( _                            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out CLUSTER_PROPERTY_TYPE *pType
   ' =====================================================================================
   PROPERTY SET Type <5> ( _                            ' VTable offset = 56
     BYVAL pType AS LONG _                              ' __in CLUSTER_PROPERTY_TYPE pType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Format <6> ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CLUSTER_PROPERTY_FORMAT *pFormat
   ' =====================================================================================
   PROPERTY SET Format <6> ( _                          ' VTable offset = 64
     BYVAL pFormat AS LONG _                            ' __in CLUSTER_PROPERTY_FORMAT pFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadOnly <7> ( _                        ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReadOnly
   ' =====================================================================================
   PROPERTY GET Private <8> ( _                         ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPrivate
   ' =====================================================================================
   PROPERTY GET Common <9> ( _                          ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCommon
   ' =====================================================================================
   PROPERTY GET Modified <10> ( _                       ' VTable offset = 80
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModified
   ' =====================================================================================
   METHOD UseDefaultValue <11> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusPropertyValue
' IID = {F2E6071A-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusPropertyValue_INTERFACE_DEFINED)
    %ISClusPropertyValue_INTERFACE_DEFINED = 1

INTERFACE ISClusPropertyValue $IID_ISClusPropertyValue

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL pvarValue AS VARIANT _                       ' __in VARIANT pvarValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CLUSTER_PROPERTY_TYPE *pType
   ' =====================================================================================
   PROPERTY SET Type <2> ( _                            ' VTable offset = 40
     BYVAL pType AS LONG _                              ' __in CLUSTER_PROPERTY_TYPE pType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Format <3> ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out CLUSTER_PROPERTY_FORMAT *pFormat
   ' =====================================================================================
   PROPERTY SET Format <3> ( _                          ' VTable offset = 48
     BYVAL pFormat AS LONG _                            ' __in CLUSTER_PROPERTY_FORMAT pFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Length <4> ( _                          ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pLength
   ' =====================================================================================
   PROPERTY GET DataCount <5> ( _                       ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   PROPERTY GET Data <6> ( _                            ' VTable offset = 60
   ) AS ISClusPropertyValueData                         ' __retval_out ISClusPropertyValueData **ppClusterPropertyValueData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusPropertyValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusPropertyValues
' IID = {F2E6071C-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusPropertyValues_INTERFACE_DEFINED)
    %ISClusPropertyValues_INTERFACE_DEFINED = 1

INTERFACE ISClusPropertyValues $IID_ISClusPropertyValues

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusPropertyValue                             ' __retval_out ISClusPropertyValue **ppPropertyValue
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 40
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   ) AS ISClusPropertyValue                             ' __retval_out ISClusPropertyValue **ppPropertyValue
   ' =====================================================================================
   METHOD RemoveItem <4> ( _                            ' VTable offset = 44
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusPropertyValues_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusProperties
' IID = {F2E60700-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusProperties_INTERFACE_DEFINED)
    %ISClusProperties_INTERFACE_DEFINED = 1

INTERFACE ISClusProperties $IID_ISClusProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusProperty                                  ' __retval_out ISClusProperty **ppClusProperty
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   ) AS ISClusProperty                                  ' __retval_out ISClusProperty **pProperty
   ' =====================================================================================
   METHOD UseDefaultValue <4> ( _                       ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveChanges <5> ( _                           ' VTable offset = 52
     OPTIONAL BYREF pvarStatusCode AS VARIANT _         ' __out_opt VARIANT *pvarStatusCode [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadOnly <6> ( _                        ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReadOnly
   ' =====================================================================================
   PROPERTY GET Private <7> ( _                         ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPrivate
   ' =====================================================================================
   PROPERTY GET Common <8> ( _                          ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCommon
   ' =====================================================================================
   PROPERTY GET Modified <9> ( _                        ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModified
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusPropertyValueData
' IID = {F2E6071E-2631-11D1-89F1-00A0C90D061E}
' ISClusPropertyValueData collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusPropertyValueData_INTERFACE_DEFINED)
    %ISClusPropertyValueData_INTERFACE_DEFINED = 1

INTERFACE ISClusPropertyValueData $IID_ISClusPropertyValueData

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 40
     BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarData
   ' =====================================================================================
   METHOD RemoveItem <4> ( _                            ' VTable offset = 44
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusPropertyValueData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusPartition
' IID = {F2E60720-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusPartition_INTERFACE_DEFINED)
    %ISClusPartition_INTERFACE_DEFINED = 1

INTERFACE ISClusPartition $IID_ISClusPartition

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Flags <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plFlags
   ' =====================================================================================
   PROPERTY GET DeviceName <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET VolumeLabel <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVolumeLabel
   ' =====================================================================================
   PROPERTY GET SerialNumber <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plSerialNumber
   ' =====================================================================================
   PROPERTY GET MaximumComponentLength <5> ( _          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plMaximumComponentLength
   ' =====================================================================================
   PROPERTY GET FileSystemFlags <6> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plFileSystemFlags
   ' =====================================================================================
   PROPERTY GET FileSystem <7> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileSystem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusPartition_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusPartitionEx
' IID = {8802D4FE-B32E-4AD1-9DBD-64F18E1166CE}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISClusPartition
' ########################################################################################

#IF NOT %DEF(%ISClusPartitionEx_INTERFACE_DEFINED)
    %ISClusPartitionEx_INTERFACE_DEFINED = 1

INTERFACE ISClusPartitionEx $IID_ISClusPartitionEx

   INHERIT IDispatch

   ' =====================================================================================
   ' ISClusPartition Methods
   ' =====================================================================================
   PROPERTY GET Flags <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plFlags
   ' =====================================================================================
   PROPERTY GET DeviceName <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET VolumeLabel <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVolumeLabel
   ' =====================================================================================
   PROPERTY GET SerialNumber <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out log *plSerialNumber
   ' =====================================================================================
   PROPERTY GET MaximumComponentLength <5> ( _          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plMaximumComponentLength
   ' =====================================================================================
   PROPERTY GET FileSystemFlags <6> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plFileSystemFlags
   ' =====================================================================================
   PROPERTY GET FileSystem <7> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileSystem
   ' =====================================================================================

   ' =====================================================================================
   ' ISClusPartitionEx Methods
   ' =====================================================================================
   PROPERTY GET TotalSize ( _                           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plTotalSize
   ' =====================================================================================
   PROPERTY GET FreeSpace ( _                           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plFreeSpace
   ' =====================================================================================
   PROPERTY GET DeviceNumber ( _                        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plDeviceNumber
   ' =====================================================================================
   PROPERTY GET PartitionNumber ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPartitionNumber
   ' =====================================================================================
   PROPERTY GET VolumeGuid ( _                          ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVolumeGuid
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusPartitionEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusPartitions
' IID = {F2E60722-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusPartitions_INTERFACE_DEFINED)
    %ISClusPartitions_INTERFACE_DEFINED = 1

INTERFACE ISClusPartitions $IID_ISClusPartitions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusPartition                                 ' __retval_out ISClusPartition **ppPartition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusPartitions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusDisk
' IID = {F2E60724-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusDisk_INTERFACE_DEFINED)
    %ISClusDisk_INTERFACE_DEFINED = 1

INTERFACE ISClusDisk $IID_ISClusDisk

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Signature <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plSignature
   ' =====================================================================================
   PROPERTY GET ScsiAddress <2> ( _                     ' VTable offset = 32
   ) AS ISClusScsiAddress                               ' __retval_out ISClusScsiAddress **ppScsiAddress
   ' =====================================================================================
   PROPERTY GET DiskNumber <3> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plDiskNumber
   ' =====================================================================================
   PROPERTY GET Partitions <4> ( _                      ' VTable offset = 40
   ) AS ISClusPartitions                                ' __retval_out ISClusPartitions **ppPartitions
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusDisk_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusDisks
' IID = {F2E60726-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusDisks_INTERFACE_DEFINED)
    %ISClusDisks_INTERFACE_DEFINED = 1

INTERFACE ISClusDisks $IID_ISClusDisks

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusDisk                                      ' __retval_out ISClusDisk **ppDisk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusDisks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusScsiAddress
' IID = {F2E60728-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusScsiAddress_INTERFACE_DEFINED)
    %ISClusScsiAddress_INTERFACE_DEFINED = 1

INTERFACE ISClusScsiAddress $IID_ISClusScsiAddress

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PortNumber <1> ( _                      ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPortNumber
   ' =====================================================================================
   PROPERTY GET PathId <2> ( _                          ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPathId
   ' =====================================================================================
   PROPERTY GET TargetId <3> ( _                        ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarTargetId
   ' =====================================================================================
   PROPERTY GET Lun <4> ( _                             ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarLun
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusScsiAddress_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusRegistryKeys
' IID = {F2E6072A-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusRegistryKeys_INTERFACE_DEFINED)
    %ISClusRegistryKeys_INTERFACE_DEFINED = 1

INTERFACE ISClusRegistryKeys $IID_ISClusRegistryKeys

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRegistryKey
   ' =====================================================================================
   METHOD AddItem <3> ( _                               ' VTable offset = 44
     BYVAL bstrRegistryKey AS WSTRING _                 ' __in BSTR bstrRegistryKey
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusRegistryKeys_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusCryptoKeys
' IID = {F2E6072C-2631-11D1-89F1-00A0C90D061E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusCryptoKeys_INTERFACE_DEFINED)
    %ISClusCryptoKeys_INTERFACE_DEFINED = 1

INTERFACE ISClusCryptoKeys $IID_ISClusCryptoKeys

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCyrptoKey
   ' =====================================================================================
   METHOD AddItem <3> ( _                               ' VTable offset = 44
     BYVAL bstrCryptoKey AS WSTRING _                   ' __in BSTR bstrCryptoKey
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusCryptoKeys_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISClusResDependents
' IID = {F2E6072E-2631-11D1-89F1-00A0C90D061E}
' Resource Dependencts for a resource
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISClusResDependents_INTERFACE_DEFINED)
    %ISClusResDependents_INTERFACE_DEFINED = 1

INTERFACE ISClusResDependents $IID_ISClusResDependents

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusResource
   ' =====================================================================================
   METHOD CreateItem <3> ( _                            ' VTable offset = 44
     BYVAL bstrResourceName AS WSTRING _                ' __in BSTR bstrResourceName
   , BYVAL bstrResourceType AS WSTRING _                ' __in BSTR bstrResourceType
   , BYVAL dwFlags AS LONG _                            ' __in CLUSTER_RESOURCE_CREATE_FLAGS dwFlags
   ) AS ISClusResource                                  ' __retval_out ISClusResource **ppClusterResource
   ' =====================================================================================
   METHOD DeleteItem <4> ( _                            ' VTable offset = 48
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD AddItem <5> ( _                               ' VTable offset = 52
     BYVAL pResource AS ISClusResource _                ' __in ISClusResource *pResource
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveItem <6> ( _                            ' VTable offset = 56
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISClusResDependents_INTERFACE_DEFINED__ */
