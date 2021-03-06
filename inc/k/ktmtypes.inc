' ########################################################################################
' Microsoft Windows
' File: ktmtypes.inc
' Contents: Common types for KTM exposed at both the Nt- and Win32-layer
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%KTMTYPES_INC = 1

'typedef GUID UOW, *PUOW;
'typedef GUID CRM_PROTOCOL_ID, *PCRM_PROTOCOL_ID;

'//
'// Define the TransactionManager option values
'//

%TRANSACTION_MANAGER_VOLATILE              = &H00000001???
%TRANSACTION_MANAGER_COMMIT_DEFAULT        = &H00000000???
%TRANSACTION_MANAGER_COMMIT_SYSTEM_VOLUME  = &H00000002???
%TRANSACTION_MANAGER_COMMIT_SYSTEM_HIVES   = &H00000004???
%TRANSACTION_MANAGER_COMMIT_LOWEST         = &H00000008???
%TRANSACTION_MANAGER_CORRUPT_FOR_RECOVERY  = &H00000010???
%TRANSACTION_MANAGER_CORRUPT_FOR_PROGRESS  = &H00000020???
%TRANSACTION_MANAGER_MAXIMUM_OPTION        = &H0000003F???

'//
'// Define the Transaction option values
'//

%TRANSACTION_DO_NOT_PROMOTE        = &H00000001???
%TRANSACTION_MAXIMUM_OPTION        = &H00000001???

'//
'// Define the ResourceManager option values
'//

%RESOURCE_MANAGER_VOLATILE            = &H00000001???
%RESOURCE_MANAGER_COMMUNICATION       = &H00000002???
%RESOURCE_MANAGER_MAXIMUM_OPTION      = &H00000003???

'//
'// Define the RegisterProtocol option values
'//

%CRM_PROTOCOL_EXPLICIT_MARSHAL_ONLY      = &H00000001???
%CRM_PROTOCOL_DYNAMIC_MARSHAL_INFO       = &H00000002???
%CRM_PROTOCOL_MAXIMUM_OPTION             = &H00000003???

'//
'// Define the Enlistment option values
'//

%ENLISTMENT_SUPERIOR                  = &H00000001???
%ENLISTMENT_MAXIMUM_OPTION            = &H00000001???

'typedef ULONG NOTIFICATION_MASK;
%TRANSACTION_NOTIFY_MASK                 = &H3FFFFFFF???
%TRANSACTION_NOTIFY_PREPREPARE           = &H00000001???
%TRANSACTION_NOTIFY_PREPARE              = &H00000002???
%TRANSACTION_NOTIFY_COMMIT               = &H00000004???
%TRANSACTION_NOTIFY_ROLLBACK             = &H00000008???
%TRANSACTION_NOTIFY_PREPREPARE_COMPLETE  = &H00000010???
%TRANSACTION_NOTIFY_PREPARE_COMPLETE     = &H00000020???
%TRANSACTION_NOTIFY_COMMIT_COMPLETE      = &H00000040???
%TRANSACTION_NOTIFY_ROLLBACK_COMPLETE    = &H00000080???
%TRANSACTION_NOTIFY_RECOVER              = &H00000100???
%TRANSACTION_NOTIFY_SINGLE_PHASE_COMMIT  = &H00000200???
%TRANSACTION_NOTIFY_DELEGATE_COMMIT      = &H00000400???
%TRANSACTION_NOTIFY_RECOVER_QUERY        = &H00000800???
%TRANSACTION_NOTIFY_ENLIST_PREPREPARE    = &H00001000???
%TRANSACTION_NOTIFY_LAST_RECOVER         = &H00002000???
%TRANSACTION_NOTIFY_INDOUBT              = &H00004000???
%TRANSACTION_NOTIFY_PROPAGATE_PULL       = &H00008000???
%TRANSACTION_NOTIFY_PROPAGATE_PUSH       = &H00010000???
%TRANSACTION_NOTIFY_MARSHAL              = &H00020000???
%TRANSACTION_NOTIFY_ENLIST_MASK          = &H00040000???
' --- Removed from the SDK for Windows Server 2008 ---
'%TRANSACTION_NOTIFY_SAVEPOINT            = &H00080000???
'%TRANSACTION_NOTIFY_SAVEPOINT_COMPLETE   = &H00100000???
'%TRANSACTION_NOTIFY_CLEAR_SAVEPOINT      = &H00200000???
'%TRANSACTION_NOTIFY_CLEAR_ALL_SAVEPOINTS = &H00400000???
'%TRANSACTION_NOTIFY_ROLLBACK_SAVEPOINT   = &H00800000???
' ----------------------------------------------------
%TRANSACTION_NOTIFY_RM_DISCONNECTED      = &H01000000???
%TRANSACTION_NOTIFY_TM_ONLINE            = &H02000000???
%TRANSACTION_NOTIFY_COMMIT_REQUEST       = &H04000000???
%TRANSACTION_NOTIFY_PROMOTE              = &H08000000???
%TRANSACTION_NOTIFY_PROMOTE_NEW          = &H10000000???
%TRANSACTION_NOTIFY_REQUEST_OUTCOME      = &H20000000???
'//
'//  Note that this flag is not included in the TRANSACTION_NOTIFY_MASK.
'//  The reason being that KTM does not understand this flag yet. This
'//  flag is strictly for the use of filter manager. In fact we mask it
'//  out before enlisting in any transaction.
'//
%TRANSACTION_NOTIFY_COMMIT_FINALIZE      = &H40000000???

'//
'// Path to the transaction manager objects in the NT
'// object namespace.
'//
$$TRANSACTIONMANAGER_OBJECT_PATH  = "\TransactionManager\"$$
$$TRANSACTION_OBJECT_PATH         = "\Transaction\"$$
$$ENLISTMENT_OBJECT_PATH          = "\Enlistment\"$$
$$RESOURCE_MANAGER_OBJECT_PATH    = "\ResourceManager\"$$

'//
'// The following three defines are here to ease the allocation
'// of string buffers which are to contain a fully qualified
'// transaction manager object name, e.g., \Transaction\{GUID}
'//
'#define TRANSACTIONMANAGER_OBJECT_NAME_LENGTH_IN_BYTES      (sizeof(TRANSACTIONMANAGER_OBJECT_PATH)+(38*sizeof(WCHAR)))
'#define TRANSACTION_OBJECT_NAME_LENGTH_IN_BYTES      (sizeof(TRANSACTION_OBJECT_PATH)+(38*sizeof(WCHAR)))
'#define ENLISTMENT_OBJECT_NAME_LENGTH_IN_BYTES       (sizeof(ENLISTMENT_OBJECT_PATH)+(38*sizeof(WCHAR)))
'#define RESOURCE_MANAGER_OBJECT_NAME_LENGTH_IN_BYTES (sizeof(RESOURCE_MANAGER_OBJECT_PATH)+(38*sizeof(WCHAR)))

' // Size = 24 bytes
TYPE TRANSACTION_NOTIFICATION   ' Must be 8 bytes aligned
   TransactionKey          AS DWORD   ' PVOID
   TransactionNotification AS DWORD   ' ULONG
   TmVirtualClock          AS QUAD    ' LARGE_INTEGER
   ArgumentLength          AS DWORD   ' ULONG
   alignment__             AS DWORD
END TYPE

' // Size = 32 bytes
TYPE TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT DWORD
   EnlistmentId AS GUID   ' GUID
   UOW          AS GUID   ' UOW
END TYPE

%TRANSACTION_NOTIFICATION_TM_ONLINE_FLAG_IS_CLUSTERED = &H1

' // Size = 20 bytes
TYPE TRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT DWORD
   TmIdentity AS GUID    ' GUID
   Flags      AS DWORD   ' ULONG
END TYPE

'typedef ULONG SAVEPOINT_ID, *PSAVEPOINT_ID;

' // Size = 20 bytes
TYPE TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT DWORD
   SavepointId AS DWORD   ' SAVEPOINT_ID
END TYPE

' // Size = 40 bytes
TYPE TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT DWORD
   PropagationCookie AS DWORD   ' ULONG
   UOW               AS GUID    ' GUID
   TmIdentity        AS GUID    ' GUID
   BufferLength      AS DWORD   ' ULONG
   ' // Bufferlength bytes of Buffer follow
END TYPE

' // Size = 20 bytes
TYPE TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT DWORD
   MarshalCookie AS DWORD   ' ULONG
   UOW           AS GUID   ' GUID
END TYPE

%KTM_MARSHAL_BLOB_VERSION_MAJOR = 1
%KTM_MARSHAL_BLOB_VERSION_MINOR = 1

%MAX_TRANSACTION_DESCRIPTION_LENGTH     = 64
%MAX_RESOURCEMANAGER_DESCRIPTION_LENGTH = 64

' // Size = 16 bytes
TYPE KCRM_MARSHAL_HEADER DWORD
   VersionMajor AS DWORD   ' ULONG
   VersionMinor AS DWORD   ' ULONG
   NumProtocols AS DWORD   ' ULONG
   Unused       AS DWORD   ' ULONG // for alignment purposes
END TYPE

' // Size = 172 bytes
TYPE KCRM_TRANSACTION_BLOB DWORD
   UOW            AS GUID    ' UOW
   TmIdentity     AS GUID    ' GUID
   IsolationLevel AS DWORD   ' ULONG
   IsolationFlags AS DWORD   ' ULONG
   Timeout        AS DWORD   ' ULONG
   Description    AS WSTRINGZ * %MAX_TRANSACTION_DESCRIPTION_LENGTH   ' WCHAR
END TYPE

' // Size = 32 bytes
TYPE KCRM_PROTOCOL_BLOB DWORD
   ProtocolId              AS GUID    ' CRM_PROTOCOL_ID
   StaticInfoLength        AS DWORD   ' __in_range (0,ULONG_MAX/2) ULONG
   TransactionIdInfoLength AS DWORD   ' ULONG //??? ProtocolDynamicInfoLength;
   Unused1                 AS DWORD   ' ULONG // for alignment purposes
   Unused2                 AS DWORD   ' ULONG // for alignment purposes
END TYPE
