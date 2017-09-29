' ########################################################################################
' Microsoft Windows
' File: vsmgmt.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: VSMGMT
' Version: 1.0, Locale ID = 0
' Documentation string: Shadow Copy Mgmt 1.0 Type Library
' Library GUID: {84015C41-291D-49E6-BF7F-DD40AE93632B}
' ########################################################################################

#INCLUDE THIS ONCE
%VSMGMT_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vss.inc"

' enum _VSS_MGMT_OBJECT_TYPE
%VSS_MGMT_OBJECT_UNKNOWN     = 0
%VSS_MGMT_OBJECT_VOLUME      = %VSS_MGMT_OBJECT_UNKNOWN     + 1
%VSS_MGMT_OBJECT_DIFF_VOLUME = %VSS_MGMT_OBJECT_VOLUME      + 1
%VSS_MGMT_OBJECT_DIFF_AREA   = %VSS_MGMT_OBJECT_DIFF_VOLUME + 1

%VSS_ASSOC_NO_MAX_SPACE = -1

%VSS_ASSOC_REMOVE = 0

' // Size = 8 bytes
TYPE VSS_VOLUME_PROP DWORD FILL
   m_pwszVolumeName        AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszVolumeDisplayName AS WSTRINGZ PTR   ' VSS_PWSZ
END TYPE

' // Size = 24 bytes
TYPE VSS_DIFF_VOLUME_PROP QWORD FILL
   m_pwszVolumeName        AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszVolumeDisplayName AS WSTRINGZ PTR   ' VSS_PWSZ
   m_llVolumeFreeSpace     AS QUAD           ' LONGLONG
   m_llVolumeTotalSpace    AS QUAD           ' LONGLONG
END TYPE

' // Size = 32 bytes
TYPE VSS_DIFF_AREA_PROP QWORD FILL
   m_pwszVolumeName         AS WSTRINGZ PTR   ' VSS_PWSZ
   m_pwszDiffAreaVolumeName AS WSTRINGZ PTR   ' VSS_PWSZ
   m_llMaximumDiffSpace     AS QUAD           ' LONGLONG
   m_llAllocatedDiffSpace   AS QUAD           ' LONGLONG
   m_llUsedDiffSpace        AS QUAD           ' LONGLONG
END TYPE

UNION VSS_MGMT_OBJECT_UNION QWORD FILL
   Vol      AS VSS_VOLUME_PROP
   DiffVol  AS VSS_DIFF_VOLUME_PROP
   DiffArea AS VSS_DIFF_AREA_PROP
   ' /* Empty union arm */
END UNION

' // Size = 40 bytes
TYPE VSS_MGMT_OBJECT_PROP QWORD FILL
   Type AS LONG   ' VSS_MGMT_OBJECT_TYPE
   Obj  AS VSS_MGMT_OBJECT_UNION
END TYPE

' enum VSS_PROTECTION_LEVEL
%VSS_PROTECTION_LEVEL_ORIGINAL_VOLUME = 0
%VSS_PROTECTION_LEVEL_SNAPSHOT        = %VSS_PROTECTION_LEVEL_ORIGINAL_VOLUME + 1

' enum VSS_PROTECTION_FAULT
%VSS_PROTECTION_FAULT_NONE                         = 0
%VSS_PROTECTION_FAULT_DIFF_AREA_MISSING            = %VSS_PROTECTION_FAULT_NONE                      + 1
%VSS_PROTECTION_FAULT_IO_FAILURE_DURING_ONLINE     = %VSS_PROTECTION_FAULT_DIFF_AREA_MISSING         + 1
%VSS_PROTECTION_FAULT_META_DATA_CORRUPTION         = %VSS_PROTECTION_FAULT_IO_FAILURE_DURING_ONLINE  + 1
%VSS_PROTECTION_FAULT_MEMORY_ALLOCATION_FAILURE    = %VSS_PROTECTION_FAULT_META_DATA_CORRUPTION      + 1
%VSS_PROTECTION_FAULT_MAPPED_MEMORY_FAILURE        = %VSS_PROTECTION_FAULT_MEMORY_ALLOCATION_FAILURE + 1
%VSS_PROTECTION_FAULT_COW_READ_FAILURE             = %VSS_PROTECTION_FAULT_MAPPED_MEMORY_FAILURE     + 1
%VSS_PROTECTION_FAULT_COW_WRITE_FAILURE            = %VSS_PROTECTION_FAULT_COW_READ_FAILURE          + 1
%VSS_PROTECTION_FAULT_DIFF_AREA_FULL               = %VSS_PROTECTION_FAULT_COW_WRITE_FAILURE         + 1
%VSS_PROTECTION_FAULT_GROW_TOO_SLOW                = %VSS_PROTECTION_FAULT_DIFF_AREA_FULL            + 1
%VSS_PROTECTION_FAULT_GROW_FAILED                  = %VSS_PROTECTION_FAULT_GROW_TOO_SLOW             + 1
%VSS_PROTECTION_FAULT_DESTROY_ALL_SNAPSHOTS        = %VSS_PROTECTION_FAULT_GROW_FAILED               + 1
%VSS_PROTECTION_FAULT_FILE_SYSTEM_FAILURE          = %VSS_PROTECTION_FAULT_DESTROY_ALL_SNAPSHOTS     + 1
%VSS_PROTECTION_FAULT_IO_FAILURE                   = %VSS_PROTECTION_FAULT_FILE_SYSTEM_FAILURE       + 1
%VSS_PROTECTION_FAULT_DIFF_AREA_REMOVED            = %VSS_PROTECTION_FAULT_IO_FAILURE                + 1
%VSS_PROTECTION_FAULT_EXTERNAL_WRITER_TO_DIFF_AREA = %VSS_PROTECTION_FAULT_DIFF_AREA_REMOVED         + 1

' // Size = 24 bytes
TYPE VSS_VOLUME_PROTECTION_INFO DWORD
   m_protectionLevel              AS LONG    ' VSS_PROTECTION_LEVEL
   m_volumeIsOfflineForProtection AS LONG    ' BOOL
   m_protectionFault              AS LONG    ' VSS_PROTECTION_FAULT
   m_failureStatus                AS LONG    ' LONG
   m_volumeHasUnusedDiffArea      AS LONG    ' BOOL
   m_reserved                     AS DWORD   ' DWORD
END TYPE


' ########################################################################################
' Interface name = IVssSnapshotMgmt
' IID = FA7DF749-66E7-4986-A27F-E2F04AE53772
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssSnapshotMgmt_INTERFACE_DEFINED)
    %IVssSnapshotMgmt_INTERFACE_DEFINED = 1

$IID_IVssSnapshotMgmt = GUID$("{FA7DF749-66E7-4986-A27F-E2F04AE53772}")

INTERFACE IVssSnapshotMgmt $IID_IVssSnapshotMgmt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProviderMgmtInterface ( _                  ' VTable offset = 12
     BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   , BYREF InterfaceId AS GUID _                        ' __in REFIID InterfaceId
   , BYREF ppItf AS IUnknown _                          ' __out IUnknown **ppItf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVolumesSupportedForSnapshots ( _         ' VTable offset = 16
     BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   , BYVAL lContext AS LONG _                           ' __in LONG lContext
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySnapshotsByVolume ( _                    ' VTable offset = 20
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   , BYREF ppEnum AS IVssEnumObject _                   ' __out IVssEnumObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssSnapshotMgmt_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVssSnapshotMgmt2
' IID = 0F61EC39-FE82-45F2-A3F0-768B5D427102
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssSnapshotMgmt2_INTERFACE_DEFINED)
    %IVssSnapshotMgmt2_INTERFACE_DEFINED = 1

$IID_IVssSnapshotMgmt2 = GUID$("{0F61EC39-FE82-45F2-A3F0-768B5D427102}")

INTERFACE IVssSnapshotMgmt2 $IID_IVssSnapshotMgmt2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMinDiffAreaSize ( _                        ' VTable offset = 12
     BYREF pllMinDiffAreaSize AS QUAD _                 ' __out LONGLONG *pllMinDiffAreaSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssSnapshotMgmt2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVssDifferentialSoftwareSnapshotMgmt
' IID = 214A0F28-B737-4026-B847-4F9E37D79529
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssDifferentialSoftwareSnapshotMgmt_INTERFACE_DEFINED)
    %IVssDifferentialSoftwareSnapshotMgmt_INTERFACE_DEFINED = 1

$IID_IVssDifferentialSoftwareSnapshotMgmt = GUID$("{214A0F28-B737-4026-B847-4F9E37D79529}")

INTERFACE IVssDifferentialSoftwareSnapshotMgmt $IID_IVssDifferentialSoftwareSnapshotMgmt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddDiffArea ( _                               ' VTable offset = 12
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeDiffAreaMaximumSize ( _                 ' VTable offset = 16
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVolumesSupportedForDiffAreas ( _         ' VTable offset = 20
     BYREF pwszOriginalVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszOriginalVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasForVolume ( _                   ' VTable offset = 24
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasOnVolume ( _                    ' VTable offset = 28
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasForSnapshot ( _                 ' VTable offset = 32
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssDifferentialSoftwareSnapshotMgmt_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVssDifferentialSoftwareSnapshotMgmt2
' IID = 949D7353-675F-4275-8969-F044C6277815
' Inherited interface = IVssDifferentialSoftwareSnapshotMgmt
' ########################################################################################

#IF NOT %DEF(%IVssDifferentialSoftwareSnapshotMgmt2_INTERFACE_DEFINED)
    %IVssDifferentialSoftwareSnapshotMgmt2_INTERFACE_DEFINED = 1

$IID_IVssDifferentialSoftwareSnapshotMgmt2 = GUID$("{949D7353-675F-4275-8969-F044C6277815}")

INTERFACE IVssDifferentialSoftwareSnapshotMgmt2 $IID_IVssDifferentialSoftwareSnapshotMgmt2

   INHERIT IUnknown

   ' =====================================================================================
   ' IVssDifferentialSoftwareSnapshotMgmt Methods
   ' =====================================================================================
   METHOD AddDiffArea ( _                               ' VTable offset = 12
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeDiffAreaMaximumSize ( _                 ' VTable offset = 16
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVolumesSupportedForDiffAreas ( _         ' VTable offset = 20
     BYREF pwszOriginalVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszOriginalVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasForVolume ( _                   ' VTable offset = 24
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasOnVolume ( _                    ' VTable offset = 28
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasForSnapshot ( _                 ' VTable offset = 32
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IVssDifferentialSoftwareSnapshotMgmt2 Methods
   ' =====================================================================================
   METHOD ChangeDiffAreaMaximumSizeEx ( _               ' VTable offset = 36
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   , BYVAL bVolatile AS LONG _                          ' __in BOOL bVolatile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MigrateDiffAreas ( _                          ' VTable offset = 40
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYREF pwszNewDiffAreaVolumeName AS WSTRINGZ _      ' __in VSS_PWSZ pwszNewDiffAreaVolumeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryMigrationStatus ( _                      ' VTable offset = 44
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync **ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSnapshotPriority ( _                       ' VTable offset = 48
     BYVAL idSnapshot AS GUID _                         ' __in VSS_ID idSnapshot
   , BYVAL priority AS BYTE _                           ' __in BYTE priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssDifferentialSoftwareSnapshotMgmt2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVssDifferentialSoftwareSnapshotMgmt3
' IID = 383F7E71-A4C5-401F-B27F-F826289F8458
' Inherited interface = IVssDifferentialSoftwareSnapshotMgmt2
' ########################################################################################

#IF NOT %DEF(%IVssDifferentialSoftwareSnapshotMgmt3_INTERFACE_DEFINED)
    %IVssDifferentialSoftwareSnapshotMgmt3_INTERFACE_DEFINED = 1

$IID_IVssDifferentialSoftwareSnapshotMgmt3 = GUID$("{383F7E71-A4C5-401F-B27F-F826289F8458}")

INTERFACE IVssDifferentialSoftwareSnapshotMgmt3 $IID_IVssDifferentialSoftwareSnapshotMgmt3

   INHERIT IUnknown

   ' =====================================================================================
   ' IVssDifferentialSoftwareSnapshotMgmt Methods
   ' =====================================================================================
   METHOD AddDiffArea ( _                               ' VTable offset = 12
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeDiffAreaMaximumSize ( _                 ' VTable offset = 16
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVolumesSupportedForDiffAreas ( _         ' VTable offset = 20
     BYREF pwszOriginalVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszOriginalVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasForVolume ( _                   ' VTable offset = 24
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasOnVolume ( _                    ' VTable offset = 28
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDiffAreasForSnapshot ( _                 ' VTable offset = 32
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF ppEnum AS IVssEnumMgmtObject _               ' __out IVssEnumMgmtObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IVssDifferentialSoftwareSnapshotMgmt2 Methods
   ' =====================================================================================
   METHOD ChangeDiffAreaMaximumSizeEx ( _               ' VTable offset = 36
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYVAL llMaximumDiffSpace AS QUAD _                 ' __in LONGLONG llMaximumDiffSpace
   , BYVAL bVolatile AS LONG _                          ' __in BOOL bVolatile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MigrateDiffAreas ( _                          ' VTable offset = 40
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYREF pwszNewDiffAreaVolumeName AS WSTRINGZ _      ' __in VSS_PWSZ pwszNewDiffAreaVolumeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryMigrationStatus ( _                      ' VTable offset = 44
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync **ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSnapshotPriority ( _                       ' VTable offset = 48
     BYVAL idSnapshot AS GUID _                         ' __in VSS_ID idSnapshot
   , BYVAL priority AS BYTE _                           ' __in BYTE priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IVssDifferentialSoftwareSnapshotMgmt3 Methods
   ' =====================================================================================
   METHOD SetVolumeProtectLevel ( _                     ' VTable offset = 52
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYVAL protectionLevel AS LONG _                    ' __in VSS_PROTECTION_LEVEL protectionLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolumeProtectLevel ( _                     ' VTable offset = 56
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF protectionLevel AS VSS_VOLUME_PROTECTION_INFO _ ' __out VSS_VOLUME_PROTECTION_INFO *protectionLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearVolumeProtectFault ( _                   ' VTable offset = 60
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteUnusedDiffAreas ( _                     ' VTable offset = 64
     BYREF pwszDiffAreaVolumeName AS WSTRINGZ _         ' __in VSS_PWSZ pwszDiffAreaVolumeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySnapshotDeltaBitmap ( _                  ' VTable offset = 68
     BYREF idSnapshotOlder AS GUID _                    ' __in VSS_ID idSnapshotOlder
   , BYREF idSnapshotYounger AS GUID _                  ' __in VSS_ID idSnapshotYounger
   , BYREF pcBlockSizePerBit AS DWORD _                 ' __out LONG *pcBlockSizePerBit
   , BYREF pcBitmapLength AS DWORD _                    ' __out ULONG *pcBitmapLength
   , BYREF ppbBitmap AS DWORD _                         ' __out BYTE **ppbBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssDifferentialSoftwareSnapshotMgmt3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVssEnumMgmtObject
' IID = 01954E6B-9254-4E6E-808C-C9E05D007696
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssEnumMgmtObject_INTERFACE_DEFINED)
    %IVssEnumMgmtObject_INTERFACE_DEFINED = 1

$IID_IVssEnumMgmtObject = GUID$("{01954E6B-9254-4E6E-808C-C9E05D007696}")

INTERFACE IVssEnumMgmtObject $IID_IVssEnumMgmtObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS VSS_MGMT_OBJECT_PROP _              ' __out VSS_MGMT_OBJECT_PROP *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppenum AS IVssEnumMgmtObject _               ' __in_out IVssEnumMgmtObject **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssEnumMgmtObject_INTERFACE_DEFINED__ */

$LIBID_VSMGMT = GUID$("{84015C41-291D-49E6-BF7F-DD40AE93632B}")

$PROGID_VssSnapshotMgmt1 = "VSMGMT.VssSnapshotMgmt.1"
$PROGID_VssSnapshotMgmt = "VSMGMT.VssSnapshotMgmt"

$CLSID_VssSnapshotMgmt = GUID$("{0B5A2C52-3EB9-470A-96E2-6C6D4570E40F}")
