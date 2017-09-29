' ########################################################################################
' Microsoft Windows
' File: vsprov.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VSPROV_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vss.inc"
#INCLUDE ONCE "vdslun.inc"

' ########################################################################################
' Interface name = IVssSoftwareSnapshotProvider
' IID = 609E123E-2C5A-44D3-8F01-0B1D9A47D1FF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssSoftwareSnapshotProvider_INTERFACE_DEFINED)
    %IVssSoftwareSnapshotProvider_INTERFACE_DEFINED = 1

$IID_IVssSoftwareSnapshotProvider = GUID$("{609E123E-2C5A-44D3-8F01-0B1D9A47D1FF}")

INTERFACE IVssSoftwareSnapshotProvider $IID_IVssSoftwareSnapshotProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetContext ( _                                ' VTable offset = 12
     BYVAL lContext AS LONG _                           ' __in LONG lContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSnapshotProperties ( _                     ' VTable offset = 16
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF pProp AS VSS_SNAPSHOT_PROP _                 ' __out VSS_SNAPSHOT_PROP *pProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 20
     BYVAL QueriedObjectId AS GUID _                    ' __in VSS_ID QueriedObjectId
   , BYVAL eQueriedObjectType AS LONG _                 ' __in VSS_OBJECT_TYPE eQueriedObjectType
   , BYVAL eReturnedObjectsType AS LONG _               ' __in VSS_OBJECT_TYPE eReturnedObjectsType
   , BYREF ppEnum AS IVssEnumObject _                   ' __out IVssEnumObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteSnapshots ( _                           ' VTable offset = 24
     BYVAL SourceObjectId AS GUID _                     ' __in VSS_ID SourceObjectId
   , BYVAL eSourceObjectType AS LONG _                  ' __in VSS_OBJECT_TYPE eSourceObjectType
   , BYVAL bForceDelete AS LONG _                       ' __in BOOL bForceDelete
   , BYREF plDeletedSnapshots AS LONG _                 ' __out LONG *plDeletedSnapshots
   , BYREF pNondeletedSnapshotID AS GUID _              ' __out VSS_ID *pNondeletedSnapshotID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginPrepareSnapshot ( _                      ' VTable offset = 28
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   , BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYVAL lNewContext AS LONG _                        ' __in LONG lNewContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsVolumeSupported ( _                         ' VTable offset = 32
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pbSupportedByThisProvider AS LONG _          ' __out BOOL *pbSupportedByThisProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsVolumeSnapshotted ( _                       ' VTable offset = 36
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pbSnapshotsPresent AS LONG _                 ' __out BOOL *pbSnapshotsPresent
   , BYREF plSnapshotCompatibility AS LONG _            ' __out LONG *plSnapshotCompatibility
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSnapshotProperty ( _                       ' VTable offset = 40
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYVAL eSnapshotPropertyId AS LONG _                ' __in VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId
   , BYVAL vProperty AS VARIANT _                       ' __in VARIANT vProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevertToSnapshot ( _                          ' VTable offset = 44
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryRevertStatus ( _                         ' VTable offset = 48
     BYREF pwszVolume AS WSTRINGZ _                     ' __in VSS_PWSZ pwszVolume
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync **ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVssProviderCreateSnapshotSet
' IID = 5F894E5B-1E39-4778-8E23-9ABAD9F0E08C"
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssProviderCreateSnapshotSet_INTERFACE_DEFINED)
    %IVssProviderCreateSnapshotSet_INTERFACE_DEFINED = 1

$IID_IVssProviderCreateSnapshotSet = GUID$("{5F894E5B-1E39-4778-8E23-9ABAD9F0E08C}")

INTERFACE IVssProviderCreateSnapshotSet $IID_IVssProviderCreateSnapshotSet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EndPrepareSnapshots ( _                       ' VTable offset = 12
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreCommitSnapshots ( _                        ' VTable offset = 16
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitSnapshots ( _                           ' VTable offset = 20
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostCommitSnapshots ( _                       ' VTable offset = 24
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   , BYVAL LONG _                                       ' __in LONG lSnapshotsCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreFinalCommitSnapshots ( _                   ' VTable offset = 28
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostFinalCommitSnapshots ( _                  ' VTable offset = 32
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortSnapshots ( _                            ' VTable offset = 36
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVssProviderNotifications
' IID = E561901F-03A5-4AFE-86D0-72BAEECE7004
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssProviderNotifications_INTERFACE_DEFINED)
    %IVssProviderNotifications_INTERFACE_DEFINED = 1

$IID_IVssProviderNotifications = GUID$("{E561901F-03A5-4AFE-86D0-72BAEECE7004}")

INTERFACE IVssProviderNotifications $IID_IVssProviderNotifications

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnLoad ( _                                    ' VTable offset = 12
     BYVAL pCallback AS IUnknown _                      ' __in IUnknown *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUnload ( _                                  ' VTable offset = 16
     BYVAL bForceUnload AS LONG _                       ' __in BOOL bForceUnload
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssProviderNotifications_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVssHardwareSnapshotProvider
' IID = 9593A157-44E9-4344-BBEB-44FBF9B06B10
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssHardwareSnapshotProvider_INTERFACE_DEFINED)
    %IVssHardwareSnapshotProvider_INTERFACE_DEFINED = 1

$IID_IVssHardwareSnapshotProvider = GUID$("{9593A157-44E9-4344-BBEB-44FBF9B06B10}")

INTERFACE IVssHardwareSnapshotProvider $IID_IVssHardwareSnapshotProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AreLunsSupported ( _                          ' VTable offset = 12
     BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYVAL lContext AS LONG _                           ' __in LONG lContext
   , BYREF rgwszDevices AS WSTRINGZ _                   ' __in VSS_PWSZ *rgwszDevices
   , BYREF pLunInformation AS VDS_LUN_INFORMATION _     ' __in_out VDS_LUN_INFORMATION *pLunInformation
   , BYREF pbIsSupported AS LONG _                      ' __out BOOL *pbIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillInLunInfo ( _                             ' VTable offset = 16
     BYREF wszDeviceName AS WSTRINGZ _                  ' __in VSS_PWSZ wszDeviceName
   , BYREF pLunInfo AS VDS_LUN_INFORMATION _            ' __in_out VDS_LUN_INFORMATION *pLunInfo
   , BYREF pbIsSupported AS LONG _                      ' __out BOOL *pbIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginPrepareSnapshot ( _                      ' VTable offset = 20
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   , BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYVAL lContext AS LONG _                           ' __in LONG lContext
   , BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYREF rgDeviceNames AS WSTRINGZ _                  ' __in VSS_PWSZ *rgDeviceNames
   , BYREF rgLunInformation AS VDS_LUN_INFORMATION _    ' __in_out VDS_LUN_INFORMATION *rgLunInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTargetLuns ( _                             ' VTable offset = 24
     BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYREF rgDeviceNames AS WSTRINGZ _                  ' __in VSS_PWSZ *rgDeviceNames
   , BYREF rgSourceLuns AS VDS_LUN_INFORMATION _        ' __in VDS_LUN_INFORMATION *rgSourceLuns
   , BYREF rgDestinationLuns AS VDS_LUN_INFORMATION _   ' __in_out VDS_LUN_INFORMATION *rgDestinationLuns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocateLuns ( _                                ' VTable offset = 28
     BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYREF rgSourceLuns AS VDS_LUN_INFORMATION _        ' __in VDS_LUN_INFORMATION *rgSourceLuns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLunEmpty ( _                                ' VTable offset = 32
     BYREF wszDeviceName AS WSTRINGZ _                  ' __in VSS_PWSZ wszDeviceName
   , BYREF pInformation AS VDS_LUN_INFORMATION _        ' __in VDS_LUN_INFORMATION *pInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVssHardwareSnapshotProviderEx
' IID = 7F5BA925-CDB1-4D11-A71F-339EB7E709FD
' Inherited interface = IVssHardwareSnapshotProvider
' ########################################################################################

#IF NOT %DEF(%IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED)
    %IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED = 1

$IID_IVssHardwareSnapshotProviderEx = GUID$("{7F5BA925-CDB1-4D11-A71F-339EB7E709FD}")

INTERFACE IVssHardwareSnapshotProviderEx $IID_IVssHardwareSnapshotProviderEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IVssHardwareSnapshotProvider Methods
   ' =====================================================================================
   METHOD AreLunsSupported ( _                          ' VTable offset = 12
     BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYVAL lContext AS LONG _                           ' __in LONG lContext
   , BYREF rgwszDevices AS WSTRINGZ _                   ' __in VSS_PWSZ *rgwszDevices
   , BYREF pLunInformation AS VDS_LUN_INFORMATION _     ' __in_out VDS_LUN_INFORMATION *pLunInformation
   , BYREF pbIsSupported AS LONG _                      ' __out BOOL *pbIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillInLunInfo ( _                             ' VTable offset = 16
     BYREF wszDeviceName AS WSTRINGZ _                  ' __in VSS_PWSZ wszDeviceName
   , BYREF pLunInfo AS VDS_LUN_INFORMATION _            ' __in_out VDS_LUN_INFORMATION *pLunInfo
   , BYREF pbIsSupported AS LONG _                      ' __out BOOL *pbIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginPrepareSnapshot ( _                      ' VTable offset = 20
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   , BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYVAL lContext AS LONG _                           ' __in LONG lContext
   , BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYREF rgDeviceNames AS WSTRINGZ _                  ' __in VSS_PWSZ *rgDeviceNames
   , BYREF rgLunInformation AS VDS_LUN_INFORMATION _    ' __in_out VDS_LUN_INFORMATION *rgLunInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTargetLuns ( _                             ' VTable offset = 24
     BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYREF rgDeviceNames AS WSTRINGZ _                  ' __in VSS_PWSZ *rgDeviceNames
   , BYREF rgSourceLuns AS VDS_LUN_INFORMATION _        ' __in VDS_LUN_INFORMATION *rgSourceLuns
   , BYREF rgDestinationLuns AS VDS_LUN_INFORMATION _   ' __in_out VDS_LUN_INFORMATION *rgDestinationLuns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocateLuns ( _                                ' VTable offset = 28
     BYVAL lLunCount AS LONG _                          ' __in LONG lLunCount
   , BYREF rgSourceLuns AS VDS_LUN_INFORMATION _        ' __in VDS_LUN_INFORMATION *rgSourceLuns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLunEmpty ( _                                ' VTable offset = 32
     BYREF wszDeviceName AS WSTRINGZ _                  ' __in VSS_PWSZ wszDeviceName
   , BYREF pInformation AS VDS_LUN_INFORMATION _        ' __in VDS_LUN_INFORMATION *pInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IVssHardwareSnapshotProviderEx Methods
   ' =====================================================================================
   METHOD GetProviderCapabilities ( _                   ' VTable offset = 36
     BYREF pllOriginalCapabilityMask AS QUAD _          ' __out ULONGLONG *pllOriginalCapabilityMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLunStateChange ( _                          ' VTable offset = 40
     BYREF pSnapshotLuns AS VDS_LUN_INFORMATION _       ' __in VDS_LUN_INFORMATION *pSnapshotLuns
   , BYREF pOriginalLuns AS VDS_LUN_INFORMATION _       ' __in VDS_LUN_INFORMATION *pOriginalLuns
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResyncLuns ( _                                ' VTable offset = 44
     BYREF pSourceLuns AS VDS_LUN_INFORMATION _         ' __in VDS_LUN_INFORMATION *pSourceLuns
   , BYREF pTargetLuns AS VDS_LUN_INFORMATION _         ' __in VDS_LUN_INFORMATION *pTargetLuns
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync **ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnReuseLuns ( _                               ' VTable offset = 48
     BYREF pSnapshotLuns AS VDS_LUN_INFORMATION _       ' __in VDS_LUN_INFORMATION *pSnapshotLuns
   , BYREF pOriginalLuns AS VDS_LUN_INFORMATION _       ' __in VDS_LUN_INFORMATION *pOriginalLuns
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__ */

#IF NOT %DEF(%VSSProvider_LIBRARY_DEFINED)
    %VSSProvider_LIBRARY_DEFINED = 1

'EXTERN_C const IID LIBID_VSSProvider;

#ENDIF   ' /* __VSSProvider_LIBRARY_DEFINED__ */
