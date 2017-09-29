' ########################################################################################
' Microsoft Windows
' File: vsadmin.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VSADMIN_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vss.inc"

' ########################################################################################
' Interface name = IVssAdmin
' IID = {77ED5996-2F63-11D3-8A39-00C04F72D8E3}
' Inherited interface = IUnknown
' ########################################################################################
#IF NOT %DEF(%IVssAdmin_INTERFACE_DEFINED)
    %IVssAdmin_INTERFACE_DEFINED = 1

$IID_IVssAdmin = GUID$("{77ED5996-2F63-11D3-8A39-00C04F72D8E3}")

INTERFACE IVssAdmin $IID_IVssAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterProvider ( _                          ' VTable offset = 12
     BYVAL pProviderId AS GUID _                        ' __in VSS_ID pProviderId
   , BYVAL ClassId AS GUID _                            ' __in CLSID ClassId
   , BYREF pwszProviderName AS WSTRINGZ _               ' __in VSS_PWSZ pwszProviderName
   , BYVAL eProviderType AS LONG _                      ' __in VSS_PROVIDER_TYPE eProviderType
   , BYREF pwszProviderVersion AS WSTRINGZ _            ' __in VSS_PWSZ pwszProviderVersion
   , BYVAL ProviderVersionId AS GUID _                  ' __in VSS_ID ProviderVersionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterProvider ( _                        ' VTable offset = 16
     BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProviders ( _                            ' VTable offset = 20
     BYREF ppenum AS IVssEnumObject _                   ' __out IVssEnumObject** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortAllSnapshotsInProgress ( _               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssAdmin_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVssAdminEx
' IID = {7858A9F8-B1FA-41A6-964F-B9B36B8CD8D8}
' Inherited interface = IVssAdmin
' ########################################################################################

#IF NOT %DEF(%IVssAdminEx_INTERFACE_DEFINED)
    %IVssAdminEx_INTERFACE_DEFINED = 1

$IID_IVssAdminEx = GUID$("{7858A9F8-B1FA-41A6-964F-B9B36B8CD8D8}")

INTERFACE IVssAdminEx $IID_IVssAdminEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IVssAdmin Methods
   ' =====================================================================================
   METHOD RegisterProvider ( _                          ' VTable offset = 12
     BYVAL pProviderId AS GUID _                        ' __in VSS_ID pProviderId
   , BYVAL ClassId AS GUID _                            ' __in CLSID ClassId
   , BYREF pwszProviderName AS WSTRINGZ _               ' __in VSS_PWSZ pwszProviderName
   , BYVAL eProviderType AS LONG _                      ' __in VSS_PROVIDER_TYPE eProviderType
   , BYREF pwszProviderVersion AS WSTRINGZ _            ' __in VSS_PWSZ pwszProviderVersion
   , BYVAL ProviderVersionId AS GUID _                  ' __in VSS_ID ProviderVersionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterProvider ( _                        ' VTable offset = 16
     BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProviders ( _                            ' VTable offset = 20
     BYREF ppenum AS IVssEnumObject _                   ' __out IVssEnumObject** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortAllSnapshotsInProgress ( _               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IVssAdminEx Methods
   ' =====================================================================================
   METHOD GetProviderCapability ( _                     ' VTable offset = 28
     BYVAL pProviderId AS GUID _                        ' __in VSS_ID pProviderId
   , BYREF pllOriginalCapabilityMask AS QUAD _          ' __out ULONGLONG *pllOriginalCapabilityMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProviderContext ( _                        ' VTable offset = 32
     BYVAL pProviderId AS GUID _                        ' __in VSS_ID pProviderId
   , BYREF plContext AS LONG _                          ' __out LONG *plContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProviderContext ( _                        ' VTable offset = 36
     BYVAL pProviderId AS GUID _                        ' __in VSS_ID pProviderId
   , BYVAL lContext AS LONG _                           ' __in LONG lContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssAdminEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Library name: VSS
' Version: 1.0, Locale ID = 0
' Description: Volume Shadow Copy Service 1.0 Type Library
' Path: C:\WINDOWS\system32\vssvc.exe
' Library GUID: {97AEFDD8-2F60-11D3-8A39-00C04F72D8E3}
' ########################################################################################

$LIBID_VSSAdmin = GUID$("{97AEFDD8-2F60-11D3-8A39-00C04F72D8E3}")

' CLSID = {E579AB5F-1CC4-44B4-BED9-DE0991FF0623}
$PROGID_VSSCoordinator1 = "VSS.VSSCoordinator.1"

' CLSID = {E579AB5F-1CC4-44B4-BED9-DE0991FF0623}
$PROGID_VSSCoordinator = "VSS.VSSCoordinator"

$CLSID_VSSCoordinator = GUID$("{E579AB5F-1CC4-44B4-BED9-DE0991FF0623}")

' ########################################################################################
' Interface name = IVssCoordinator
' IID = {93BA4344-AA56-403E-87F2-819650FEDACD}
' IVssCoordinator interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVssCoordinator_INTERFACE_DEFINED)
    %IVssCoordinator_INTERFACE_DEFINED = 1

$IID_IVssCoordinator = GUID$("{93BA4344-AA56-403E-87F2-819650FEDACD}")

INTERFACE IVssCoordinator $IID_IVssCoordinator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetContext ( _                                ' VTable offset = 12
     BYVAL lContext AS LONG _                           ' __in long lContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartSnapshotSet ( _                          ' VTable offset = 16
     BYREF pSnapshotSetId AS GUID _                     ' __out VSS_ID* pSnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddToSnapshotSet ( _                          ' VTable offset = 20
     BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   , BYREF pSnapshotId AS GUID _                        ' __out VSS_ID* pSnapshotId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoSnapshotSet ( _                             ' VTable offset = 24
     BYVAL pWriterCallback AS IDispatch _               ' __in IDispatch* pWriterCallback
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync** ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSnapshotProperties ( _                     ' VTable offset = 28
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF pProp AS VSS_SNAPSHOT_PROP _                 ' __out VSS_SNAPSHOT_PROP* pProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExposeSnapshot ( _                            ' VTable offset = 32
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF wszPathFromRoot AS WSTRINGZ _                ' __in VSS_PWSZ wszPathFromRoot
   , BYVAL lAttributes AS LONG _                        ' __in long lAttributes
   , BYREF wszExpose AS WSTRINGZ _                      ' __in VSS_PWSZ wszExpose
   , BYREF pwszExposed AS DWORD _                       ' __out VSS_PWSZ* pwszExposed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemountReadWrite ( _                          ' VTable offset = 36
     BYVAL SnapshotId AS GUID _                         ' __in VSS_ID SnapshotId
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync** ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ImportSnapshots ( _                           ' VTable offset = 40
     BYVAL bstrXMLSnapshotSet AS WSTRING _              ' __in BSTR bstrXMLSnapshotSet
   , BYREF ppAsync AS IVssAsync _                       ' __out IVssAsync** ppAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 44
     BYVAL QueriedObjectId AS GUID _                    ' __in VSS_ID QueriedObjectId
   , BYVAL eQueriedObjectType AS LONG _                 ' __in VSS_OBJECT_TYPE eQueriedObjectType
   , BYVAL eReturnedObjectsType AS LONG _               ' __in VSS_OBJECT_TYPE eReturnedObjectsType
   , BYREF ppenum AS IVssEnumObject _                   ' __out IVssEnumObject** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteSnapshots ( _                           ' VTable offset = 48
     BYVAL SourceObjectId AS GUID _                     ' __in VSS_ID SourceObjectId
   , BYVAL eSourceObjectType AS LONG _                  ' __in VSS_OBJECT_TYPE eSourceObjectType
   , BYVAL bForceDelete AS LONG _                       ' __in long bForceDelete
   , BYREF plDeletedSnapshots AS LONG _                 ' __out long* plDeletedSnapshots
   , BYREF pNondeletedSnapshotID AS GUID _              ' __out VSS_ID* pNondeletedSnapshotID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BreakSnapshotSet ( _                          ' VTable offset = 52
     BYVAL SnapshotSetId AS GUID _                      ' __in VSS_ID SnapshotSetId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsVolumeSupported ( _                         ' VTable offset = 56
     BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   , BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pbSupportedByThisProvider AS LONG _          ' __out long* pbSupportedByThisProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsVolumeSnapshotted ( _                       ' VTable offset = 60
     BYVAL ProviderId AS GUID _                         ' __in VSS_ID ProviderId
   , BYREF pwszVolumeName AS WSTRINGZ _                 ' __in VSS_PWSZ pwszVolumeName
   , BYREF pbSnapshotsPresent AS LONG _                 ' __out long* pbSnapshotsPresent
   , BYREF plSnapshotCompatibility AS LONG _            ' __out long* plSnapshotCompatibility
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWriterInstances ( _                        ' VTable offset = 64
     BYVAL lWriterInstanceIdCount AS LONG _             ' __in long lWriterInstanceIdCount
   , BYREF rgWriterInstanceId AS GUID _                 ' __in VSS_ID* rgWriterInstanceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVssCoordinator_INTERFACE_DEFINED__ */
