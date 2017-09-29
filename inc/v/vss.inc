' ########################################################################################
' Microsoft Windows
' File: vss.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VSS_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

'#pragma pack(push, 8)
#INCLUDE ONCE "vsserror.inc"

' ========================================================================================
' enum VSS_OBJECT_TYPE
' ========================================================================================

%VSS_OBJECT_UNKNOWN      = 0
%VSS_OBJECT_NONE         = %VSS_OBJECT_UNKNOWN      + 1
%VSS_OBJECT_SNAPSHOT_SET = %VSS_OBJECT_NONE         + 1
%VSS_OBJECT_SNAPSHOT     = %VSS_OBJECT_SNAPSHOT_SET + 1
%VSS_OBJECT_PROVIDER     = %VSS_OBJECT_SNAPSHOT     + 1
%VSS_OBJECT_TYPE_COUNT   = %VSS_OBJECT_PROVIDER     + 1

' ========================================================================================
' enum VSS_SNAPSHOT_STATE
' ========================================================================================

%VSS_SS_UNKNOWN                    = 0
%VSS_SS_PREPARING                  = %VSS_SS_UNKNOWN                    + 1
%VSS_SS_PROCESSING_PREPARE         = %VSS_SS_PREPARING                  + 1
%VSS_SS_PREPARED                   = %VSS_SS_PROCESSING_PREPARE         + 1
%VSS_SS_PROCESSING_PRECOMMIT       = %VSS_SS_PREPARED                   + 1
%VSS_SS_PRECOMMITTED               = %VSS_SS_PROCESSING_PRECOMMIT       + 1
%VSS_SS_PROCESSING_COMMIT          = %VSS_SS_PRECOMMITTED               + 1
%VSS_SS_COMMITTED                  = %VSS_SS_PROCESSING_COMMIT          + 1
%VSS_SS_PROCESSING_POSTCOMMIT      = %VSS_SS_COMMITTED                  + 1
%VSS_SS_PROCESSING_PREFINALCOMMIT  = %VSS_SS_PROCESSING_POSTCOMMIT      + 1
%VSS_SS_PREFINALCOMMITTED          = %VSS_SS_PROCESSING_PREFINALCOMMIT  + 1
%VSS_SS_PROCESSING_POSTFINALCOMMIT = %VSS_SS_PREFINALCOMMITTED          + 1
%VSS_SS_CREATED                    = %VSS_SS_PROCESSING_POSTFINALCOMMIT + 1
%VSS_SS_ABORTED                    = %VSS_SS_CREATED                    + 1
%VSS_SS_DELETED                    = %VSS_SS_ABORTED                    + 1
%VSS_SS_POSTCOMMITTED              = %VSS_SS_DELETED                    + 1
%VSS_SS_COUNT                      = %VSS_SS_POSTCOMMITTED              + 1

' ========================================================================================
' enum VSS_VOLUME_SNAPSHOT_ATTRIBUTES
' ========================================================================================

%VSS_VOLSNAP_ATTR_PERSISTENT           = &H1???
%VSS_VOLSNAP_ATTR_NO_AUTORECOVERY      = &H2???
%VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE    = &H4???
%VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE      = &H8???
%VSS_VOLSNAP_ATTR_NO_WRITERS           = &H10???
%VSS_VOLSNAP_ATTR_TRANSPORTABLE        = &H20???
%VSS_VOLSNAP_ATTR_NOT_SURFACED         = &H40???
%VSS_VOLSNAP_ATTR_NOT_TRANSACTED       = &H80???
%VSS_VOLSNAP_ATTR_HARDWARE_ASSISTED    = &H10000???
%VSS_VOLSNAP_ATTR_DIFFERENTIAL         = &H20000???
%VSS_VOLSNAP_ATTR_PLEX                 = &H40000???
%VSS_VOLSNAP_ATTR_IMPORTED             = &H80000???
%VSS_VOLSNAP_ATTR_EXPOSED_LOCALLY      = &H100000???
%VSS_VOLSNAP_ATTR_EXPOSED_REMOTELY     = &H200000???
%VSS_VOLSNAP_ATTR_AUTORECOVER          = &H400000???
%VSS_VOLSNAP_ATTR_ROLLBACK_RECOVERY    = &H800000???
%VSS_VOLSNAP_ATTR_DELAYED_POSTSNAPSHOT = &H1000000???
%VSS_VOLSNAP_ATTR_TXF_RECOVERY         = &H2000000???

' ========================================================================================
' enum VSS_SNAPSHOT_CONTEXT
' ========================================================================================

%VSS_CTX_BACKUP                    = 0
%VSS_CTX_FILE_SHARE_BACKUP         = %VSS_VOLSNAP_ATTR_NO_WRITERS
%VSS_CTX_NAS_ROLLBACK              = (%VSS_VOLSNAP_ATTR_PERSISTENT  OR %VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE)   OR %VSS_VOLSNAP_ATTR_NO_WRITERS
%VSS_CTX_APP_ROLLBACK              = %VSS_VOLSNAP_ATTR_PERSISTENT   OR %VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE
%VSS_CTX_CLIENT_ACCESSIBLE         = ((%VSS_VOLSNAP_ATTR_PERSISTENT OR %VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE) OR %VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE) OR %VSS_VOLSNAP_ATTR_NO_WRITERS
%VSS_CTX_CLIENT_ACCESSIBLE_WRITERS = (%VSS_VOLSNAP_ATTR_PERSISTENT  OR %VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE) OR %VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE
%VSS_CTX_ALL                       = &Hffffffff???

' ========================================================================================
' enum VSS_PROVIDER_CAPABILITIES
' ========================================================================================

%VSS_PRV_CAPABILITY_LEGACY           = &H1
%VSS_PRV_CAPABILITY_COMPLIANT        = &H2
%VSS_PRV_CAPABILITY_LUN_REPOINT      = &H4
%VSS_PRV_CAPABILITY_LUN_RESYNC       = &H8
%VSS_PRV_CAPABILITY_OFFLINE_CREATION = &H10
%VSS_PRV_CAPABILITY_MULTIPLE_IMPORT  = &H20
%VSS_PRV_CAPABILITY_RECYCLING        = &H40
%VSS_PRV_CAPABILITY_PLEX             = &H80
%VSS_PRV_CAPABILITY_DIFFERENTIAL     = &H100
%VSS_PRV_CAPABILITY_CLUSTERED        = &H200

' ========================================================================================
' enum VSS_FASTRECOVERY_OPTIONS
' Note: Removed from the SDK for Windows Server 2008
' ========================================================================================

%VSS_BREAK_FLAG_MASK_LUNS       = &H1
%VSS_BREAK_FLAG_MAKE_READ_WRITE = &H2
%VSS_FAST_RECOVERY_LUN_REPOINT  = &H4
%VSS_FAST_RECOVERY_LUN_RESYNC   = &H8

' ========================================================================================
' enum VSS_HARDWARE_OPTIONS
' ========================================================================================
%VSS_BREAKEX_FLAG_MASK_LUNS                    = &H1
%VSS_BREAKEX_FLAG_MAKE_READ_WRITE              = &H2
%VSS_BREAKEX_FLAG_REVERT_IDENTITY_ALL          = &H4
%VSS_BREAKEX_FLAG_REVERT_IDENTITY_NONE         = &H8
%VSS_ONLUNSTATECHANGE_NOTIFY_READ_WRITE        = &H100
%VSS_ONLUNSTATECHANGE_NOTIFY_LUN_PRE_RECOVERY  = &H200
%VSS_ONLUNSTATECHANGE_NOTIFY_LUN_POST_RECOVERY = &H400
%VSS_ONLUNSTATECHANGE_DO_MASK_LUNS             = &H800

' ========================================================================================
' enum VSS_RECOVERY_OPTIONS
' ========================================================================================
%VSS_RECOVERY_REVERT_IDENTITY_ALL = &H100
%VSS_RECOVERY_NO_VOLUME_CHECK     = &H200

' ========================================================================================
' enum VSS_WRITER_STATE
' ========================================================================================

%VSS_WS_UNKNOWN                     = 0
%VSS_WS_STABLE                      = %VSS_WS_UNKNOWN                     + 1
%VSS_WS_WAITING_FOR_FREEZE          = %VSS_WS_STABLE                      + 1
%VSS_WS_WAITING_FOR_THAW            = %VSS_WS_WAITING_FOR_FREEZE          + 1
%VSS_WS_WAITING_FOR_POST_SNAPSHOT   = %VSS_WS_WAITING_FOR_THAW            + 1
%VSS_WS_WAITING_FOR_BACKUP_COMPLETE = %VSS_WS_WAITING_FOR_POST_SNAPSHOT   + 1
%VSS_WS_FAILED_AT_IDENTIFY          = %VSS_WS_WAITING_FOR_BACKUP_COMPLETE + 1
%VSS_WS_FAILED_AT_PREPARE_BACKUP    = %VSS_WS_FAILED_AT_IDENTIFY          + 1
%VSS_WS_FAILED_AT_PREPARE_SNAPSHOT  = %VSS_WS_FAILED_AT_PREPARE_BACKUP    + 1
%VSS_WS_FAILED_AT_FREEZE            = %VSS_WS_FAILED_AT_PREPARE_SNAPSHOT  + 1
%VSS_WS_FAILED_AT_THAW              = %VSS_WS_FAILED_AT_FREEZE            + 1
%VSS_WS_FAILED_AT_POST_SNAPSHOT     = %VSS_WS_FAILED_AT_THAW              + 1
%VSS_WS_FAILED_AT_BACKUP_COMPLETE   = %VSS_WS_FAILED_AT_POST_SNAPSHOT     + 1
%VSS_WS_FAILED_AT_PRE_RESTORE       = %VSS_WS_FAILED_AT_BACKUP_COMPLETE   + 1
%VSS_WS_FAILED_AT_POST_RESTORE      = %VSS_WS_FAILED_AT_PRE_RESTORE       + 1
%VSS_WS_FAILED_AT_BACKUPSHUTDOWN    = %VSS_WS_FAILED_AT_POST_RESTORE      + 1
%VSS_WS_COUNT                       = %VSS_WS_FAILED_AT_BACKUPSHUTDOWN    + 1

' ========================================================================================
' enum VSS_BACKUP_TYPE
' ========================================================================================

%VSS_BT_UNDEFINED    = 0
%VSS_BT_FULL         = %VSS_BT_UNDEFINED    + 1
%VSS_BT_INCREMENTAL  = %VSS_BT_FULL         + 1
%VSS_BT_DIFFERENTIAL = %VSS_BT_INCREMENTAL  + 1
%VSS_BT_LOG          = %VSS_BT_DIFFERENTIAL + 1
%VSS_BT_COPY         = %VSS_BT_LOG          + 1
%VSS_BT_OTHER        = %VSS_BT_COPY         + 1

' ========================================================================================
' enum VSS_RESTORE_TYPE
' ========================================================================================

%VSS_RTYPE_UNDEFINED = 0
%VSS_RTYPE_BY_COPY   = %VSS_RTYPE_UNDEFINED + 1
%VSS_RTYPE_IMPORT    = %VSS_RTYPE_BY_COPY   + 1
%VSS_RTYPE_OTHER     = %VSS_RTYPE_IMPORT    + 1

' ========================================================================================
' enum VSS_ROLLFORWARD_TYPE
' ========================================================================================

%VSS_RF_UNDEFINED = 0
%VSS_RF_NONE      = %VSS_RF_UNDEFINED + 1
%VSS_RF_ALL       = %VSS_RF_NONE      + 1
%VSS_RF_PARTIAL   = %VSS_RF_ALL       + 1

' ========================================================================================
' enum VSS_PROVIDER_TYPE
' ========================================================================================

%VSS_PROV_UNKNOWN  = 0
%VSS_PROV_SYSTEM   = 1
%VSS_PROV_SOFTWARE = 2
%VSS_PROV_HARDWARE = 3

' ========================================================================================
' enum VSS_APPLICATION_LEVEL
' ========================================================================================

%VSS_APP_UNKNOWN   = 0
%VSS_APP_SYSTEM    = 1
%VSS_APP_BACK_END  = 2
%VSS_APP_FRONT_END = 3
%VSS_APP_SYSTEM_RM = 4
%VSS_APP_AUTO      = -1

' ========================================================================================
' enum _VSS_SNAPSHOT_COMPATIBILITY
' ========================================================================================

%VSS_SC_DISABLE_DEFRAG       = &H1
%VSS_SC_DISABLE_CONTENTINDEX = &H2

' ========================================================================================
' enum VSS_SNAPSHOT_PROPERTY_ID
' ========================================================================================

%VSS_SPROPID_UNKNOWN             = 0
%VSS_SPROPID_SNAPSHOT_ID         = &H1
%VSS_SPROPID_SNAPSHOT_SET_ID     = &H2
%VSS_SPROPID_SNAPSHOTS_COUNT     = &H3
%VSS_SPROPID_SNAPSHOT_DEVICE     = &H4
%VSS_SPROPID_ORIGINAL_VOLUME     = &H5
%VSS_SPROPID_ORIGINATING_MACHINE = &H6
%VSS_SPROPID_SERVICE_MACHINE     = &H7
%VSS_SPROPID_EXPOSED_NAME        = &H8
%VSS_SPROPID_EXPOSED_PATH        = &H9
%VSS_SPROPID_PROVIDER_ID         = &Ha
%VSS_SPROPID_SNAPSHOT_ATTRIBUTES = &Hb
%VSS_SPROPID_CREATION_TIMESTAMP  = &Hc
%VSS_SPROPID_STATUS              = &Hd

' ========================================================================================
' enum VSS_FILE_SPEC_BACKUP_TYPE
' ========================================================================================

%VSS_FSBT_FULL_BACKUP_REQUIRED           = &H1
%VSS_FSBT_DIFFERENTIAL_BACKUP_REQUIRED   = &H2
%VSS_FSBT_INCREMENTAL_BACKUP_REQUIRED    = &H4
%VSS_FSBT_LOG_BACKUP_REQUIRED            = &H8
%VSS_FSBT_FULL_SNAPSHOT_REQUIRED         = &H100
%VSS_FSBT_DIFFERENTIAL_SNAPSHOT_REQUIRED = &H200
%VSS_FSBT_INCREMENTAL_SNAPSHOT_REQUIRED  = &H400
%VSS_FSBT_LOG_SNAPSHOT_REQUIRED          = &H800
%VSS_FSBT_ALL_BACKUP_REQUIRED            = &Hf
%VSS_FSBT_ALL_SNAPSHOT_REQUIRED          = &Hf00

' ========================================================================================
' enum VSS_BACKUP_SCHEMA
' ========================================================================================

%VSS_BS_UNDEFINED                          = 0
%VSS_BS_DIFFERENTIAL                       = &H1
%VSS_BS_INCREMENTAL                        = &H2
%VSS_BS_EXCLUSIVE_INCREMENTAL_DIFFERENTIAL = &H4
%VSS_BS_LOG                                = &H8
%VSS_BS_COPY                               = &H10
%VSS_BS_TIMESTAMPED                        = &H20
%VSS_BS_LAST_MODIFY                        = &H40
%VSS_BS_LSN                                = &H80
%VSS_BS_WRITER_SUPPORTS_NEW_TARGET         = &H100
%VSS_BS_WRITER_SUPPORTS_RESTORE_WITH_MOVE  = &H200
%VSS_BS_INDEPENDENT_SYSTEM_STATE           = &H400
%VSS_BS_ROLLFORWARD_RESTORE                = &H1000
%VSS_BS_RESTORE_RENAME                     = &H2000
%VSS_BS_AUTHORITATIVE_RESTORE              = &H4000
%VSS_BS_WRITER_SUPPORTS_PARALLEL_RESTORES  = &H8000

'typedef GUID VSS_ID;

'typedef /* [string][unique] */  __RPC_unique_pointer  __RPC_string WCHAR *VSS_PWSZ;

'typedef LONGLONG VSS_TIMESTAMP;

' ========================================================================================
' VSS_SNAPSHOT_PROP structure
' ========================================================================================

' // Size = 96 bytes
TYPE VSS_SNAPSHOT_PROP   ' Must be 8 byte aligned
   m_SnapshotId               AS GUID           ' VSS_ID
   m_SnapshotSetId            AS GUID           ' VSS_ID
   m_lSnapshotsCount          AS LONG           ' LONG
   m_pwszSnapshotDeviceObject AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszOriginalVolumeName   AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszOriginatingMachine   AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszServiceMachine       AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszExposedName          AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszExposedPath          AS WSTRINGZ PTR   ' VSS_PWSZ
   m_ProviderId               AS GUID           ' VSS_ID
   m_lSnapshotAttributes      AS LONG           ' LONG
   m_tsCreationTimestamp      AS QUAD           ' VSS_TIMESTAMP
   m_eStatus                  AS LONG           ' VSS_SNAPSHOT_STATE
   alignment__                AS DWORD          ' // To keep 8 byte alignment
END TYPE

' ========================================================================================
' VSS_PROVIDER_PROP structure
' ========================================================================================

' // Size = 60 bytes
TYPE VSS_PROVIDER_PROP DWORD
   m_ProviderId          AS GUID           ' VSS_ID
   m_pwszProviderName    AS WSTRINGZ PTR   ' VSS_PWSZ
   m_eProviderType       AS LONG           ' VSS_PROVIDER_TYPE
   m_pwszProviderVersion AS WSTRINGZ PTR   ' VSS_PWSZ
   m_ProviderVersionId   AS GUID           ' VSS_ID
   m_ClassId             AS GUID           ' CLSID
END TYPE

' ========================================================================================
' VSS_OBJECT_UNION union
' ========================================================================================

' // Size = 96 bytes
UNION VSS_OBJECT_UNION   ' Must be 8 byte aligned
   Snap AS VSS_SNAPSHOT_PROP
   Prov AS VSS_SNAPSHOT_PROP
END UNION

' ========================================================================================
' VSS_OBJECT_PROP structure
' ========================================================================================

' // Size = 104 bytes
TYPE VSS_OBJECT_PROP   ' Must be 8 byte aligned
   Type       AS LONG     ' VSS_OBJECT_TYPE
   alignment_ AS DWORD
   Obj        AS VSS_OBJECT_UNION
END TYPE


' ########################################################################################
' Interface name = IVssEnumObject
' IID = {AE1C7110-2F60-11D3-8A39-00C04F72D8E3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssEnumObject_INTERFACE_DEFINED)
    %IVssEnumObject_INTERFACE_DEFINED = 1

$IID_IVssEnumObject = GUID$("{AE1C7110-2F60-11D3-8A39-00C04F72D8E3}")

INTERFACE IVssEnumObject $IID_IVssEnumObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS VSS_OBJECT_PROP _                   ' __out VSS_OBJECT_PROP* rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IVssEnumObject _                   ' __in_out IVssEnumObject** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssEnumObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVssAsync
' IID = {C7B98A22-222D-4E62-B875-1A44980634AF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssAsync_INTERFACE_DEFINED)
    %IVssAsync_INTERFACE_DEFINED = 1

$IID_IVssAsync = GUID$("{C7B98A22-222D-4E62-B875-1A44980634AF}")

INTERFACE IVssAsync $IID_IVssAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 16
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds = &Hffffffff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryStatus ( _                               ' VTable offset = 20
     BYREF pHrResult AS LONG _                          ' __out HRESULT* pHrResult
   , BYREF pReserved AS LONG _                          ' __in_out INT* pReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssAsync_INTERFACE_DEFINED__ */

'#pragma pack(pop)
