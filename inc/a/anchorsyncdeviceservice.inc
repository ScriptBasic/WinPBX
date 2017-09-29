' ########################################################################################
' Microsoft Windows
' File: AnchorSyncDeviceService.inc
' Contents: Contains definitions for the Anchor Sync Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ANCHORSYNCDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"
#INCLUDE ONCE "SyncDeviceService.inc"

'/*****************************************************************************/
'/*  Anchor Sync Service Info                                                 */
'/*****************************************************************************/

$SERVICE_AnchorSync = GUID$("{056d8b9e-ad7a-44fc-946f-1d63a25cda9a}")

$$NAME_AnchorSyncSvc                 = "AnchorSync"$$
%TYPE_AnchorSyncSvc                  = %DEVSVCTYPE_ABSTRACT

'/*****************************************************************************/
'/*  Anchor Sync Service Properties                                           */
'/*****************************************************************************/

$NAMESPACE_AnchorSyncSvc = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}")

'/*  PKEY_AnchorSyncSvc_VersionProps
' *
' *  Provides information about change units and version properties.  The
' *  format for the dataset is
' *
' *      UINT32      Number of change units
' *      UINT128     Namespace GUID for first change unit property key
' *      UINT32      Namespace ID for the first change unit property key
' *      UINT32      Number of properties associated with this change unit
' *      UINT128     Namespace GUID for first property key in change unit
' *      UINT32      Namespace ID for first property key in change unit
' *                  ...  Repeat for number of property keys
' *                  ...  Repeat for number of change units
' *
' *  NOTE: If all change units use the same property key specify a namespace
' *  GUID of GUID_NULL (all 0's) and a namespace ID of 0.
' *
' *  Type: AUInt8
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorSyncSvc_VersionProps,
'    0xe65b8fb7, 0x8fc7, 0x4278, 0xb9, 0xa3, 0xba, 0x14, 0xc2, 0xdb, 0x40, 0xfa,
'    2);
MACRO PKEY_AnchorSyncSvc_VersionProps = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}") & MKDWD$(2)

$$NAME_AnchorSyncSvc_VersionProps         = "AnchorVersionProps"$$


'/*  PKEY_AnchorSyncSvc_ReplicaID
' *
' *  Contains the GUID representing this replica in the sync community.
' *
' *  Type: UInt128
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorSyncSvc_ReplicaID,
'    0xe65b8fb7, 0x8fc7, 0x4278, 0xb9, 0xa3, 0xba, 0x14, 0xc2, 0xdb, 0x40, 0xfa,
'    3);
MACRO PKEY_AnchorSyncSvc_ReplicaID = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}") & MKDWD$(3)

$$NAME_AnchorSyncSvc_ReplicaID            = "AnchorReplicaID"$$


'/*  PKEY_AnchorSyncSvc_KnowledgeObjectID
' *
' *  Object ID to be used for the knowledge object
' *
' *  Type: UInt32
' *  Form: Object ID
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorSyncSvc_KnowledgeObjectID,
'    0xe65b8fb7, 0x8fc7, 0x4278, 0xb9, 0xa3, 0xba, 0x14, 0xc2, 0xdb, 0x40, 0xfa,
'    4);
MACRO PKEY_AnchorSyncSvc_KnowledgeObjectID = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}") & MKDWD$(4)

$$NAME_AnchorSyncSvc_KnowledgeObjectID    = "AnchorKnowledgeObjectID"$$


'/*  PKEY_AnchorSyncSvc_LastSyncProxyID
' *
' *  Contains a GUID indicating the last sync proxy to perform a sync operation
' *
' *  Type: UInt128
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorSyncSvc_LastSyncProxyID,
'    0xe65b8fb7, 0x8fc7, 0x4278, 0xb9, 0xa3, 0xba, 0x14, 0xc2, 0xdb, 0x40, 0xfa,
'    5);
MACRO PKEY_AnchorSyncSvc_LastSyncProxyID = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}") & MKDWD$(5)

$$NAME_AnchorSyncSvc_LastSyncProxyID      = "AnchorLastSyncProxyID"$$


'/*  PKEY_AnchorSyncSvc_CurrentAnchor
' *
' *  Contains a blob of data representing the current anchor for the device.
' *  As the anchor may be transient depending on the current state of the sync
' *  the value of PKEY_AnchorSyncSvc_CurrentAnchor may not reflect the current
' *  state of the database unless the current session holds a lock (via the
' *  BeginSync method) on the service.
' *
' *  Type: AUInt8
' *  Form: BinaryArray
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorSyncSvc_CurrentAnchor,
'    0xe65b8fb7, 0x8fc7, 0x4278, 0xb9, 0xa3, 0xba, 0x14, 0xc2, 0xdb, 0x40, 0xfa,
'    6);
MACRO PKEY_AnchorSyncSvc_CurrentAnchor = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}") & MKDWD$(6)

$$NAME_AnchorSyncSvc_CurrentAnchor        = "AnchorCurrentAnchor"$$


'/*  PKEY_AnchorSyncSvc_ProviderVersion
' *
' *  Contains a device defined value giving the version of the provider
' *  currently in use on the device.  This version must be incremented whenever
' *  new properties are added to the device implementation so that they will
' *  be recognized and managed as part of synchronization.  0 is reserved.
' *
' *  Type: UInt16
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorSyncSvc_ProviderVersion,
'    0xe65b8fb7, 0x8fc7, 0x4278, 0xb9, 0xa3, 0xba, 0x14, 0xc2, 0xdb, 0x40, 0xfa,
'    7);
MACRO PKEY_AnchorSyncSvc_ProviderVersion = GUID$("{e65b8fb7-8fc7-4278-b9a3-ba14c2db40fa}") & MKDWD$(7)

$$NAME_AnchorSyncSvc_ProviderVersion      = "AnchorProviderVersion"$$


'/*  PKEY_AnchorSyncSvc_SyncFormat
' *
' *  Indicates the format GUID for the object format that is to be used in the
' *  sync operation.
' *
' *  Type: UInt128
' *  Form: None
' */

MACRO PKEY_AnchorSyncSvc_SyncFormat           = PKEY_SyncSvc_SyncFormat
$$NAME_AnchorSyncSvc_SyncFormat               = $$NAME_SyncSvc_SyncFormat


'/*  PKEY_AnchorSyncSvc_LocalOnlyDelete
' *
' *  Boolean flag indicating whether deletes of objects on the service host
' *  should be treated as "local only" and not propogated to other sync
' *  participants.  The alternative is "true sync" in which deletes on the
' *  service host are propogated to all other sync participants.
' *
' *  Type: UInt8
' *  Form: None
' */

MACRO PKEY_AnchorSyncSvc_LocalOnlyDelete      = PKEY_SyncSvc_LocalOnlyDelete
$$NAME_AnchorSyncSvc_LocalOnlyDelete          = $$NAME_SyncSvc_LocalOnlyDelete

'/*  PKEY_AnchorSyncSvc_FilterType
' *
' *  Boolean flag indicating whether the default filter is being applied to
' *  this endpoint.  Note that the meaning of the default filter is determined
' *  by the content type service.
' *
' *  Type: UInt8
' *  Form: None
' */

MACRO PKEY_AnchorSyncSvc_FilterType           = PKEY_SyncSvc_FilterType
$$NAME_AnchorSyncSvc_FilterType               = $$NAME_SyncSvc_FilterType

'/*****************************************************************************/
'/*  Anchor Sync Service Object Formats                                       */
'/*****************************************************************************/

'/*  FORMAT_AnchorSyncKnowledge
' */

$FORMAT_AnchorSyncKnowledge = GUID$("{37c550bc-f231-4727-bbbc-4cb33a3f3ecd}")

$$NAME_AnchorSyncKnowledge            = "AnchorSyncKnowledge"$$

'/*  FORMAT_AnchorSyncSvc_AnchorResults
' *
' *  GetChangesSinceAnchor results format
' */

$FORMAT_AnchorSyncSvc_AnchorResults = GUID$("{f35527c1-ce4a-487a-9d29-93833569321e}")

$$NAME_AnchorResults                  = "AnchorResults"$$

'/*****************************************************************************/
'/*  Anchor Sync Service Object Property Keys                                 */
'/*****************************************************************************/


$NAMESPACE_AnchorResults = GUID$("{516b5dce-8d45-430f-805c-25e5106d8b1f}")

'/*  PKEY_AnchorResults_AnchorState
' *
' *  Output parameter from GetChangesSinceAnchor method.  Contains the state
' *  of the current anchor result:
' *
' *  Type: UInt32
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorResults_AnchorState,
'    0x516b5dce, 0x8d45, 0x430f, 0x80, 0x5c, 0x25, 0xe5, 0x10, 0x6d, 0x8b, 0x1f,
'    2);
MACRO PKEY_AnchorResults_AnchorState = GUID$("{516b5dce-8d45-430f-805c-25e5106d8b1f}") & MKDWD$(2)

$$NAME_AnchorResults_AnchorState      = "AnchorState"$$

%ENUM_AnchorResults_AnchorStateNormal    = &H00000000
%ENUM_AnchorResults_AnchorStateInvalid   = &H00000001
%ENUM_AnchorResults_AnchorStateOld       = &H00000002


'/*  PKEY_AnchorResults_Anchor
' *
' *  Input parameter for GetChangesSinceAnchor method.  Contains the anchor for
' *  which data is being requested.
' *
' *  Type: AUInt8
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorResults_Anchor,
'    0x516b5dce, 0x8d45, 0x430f, 0x80, 0x5c, 0x25, 0xe5, 0x10, 0x6d, 0x8b, 0x1f,
'    3);
MACRO PKEY_AnchorResults_Anchor = GUID$("{516b5dce-8d45-430f-805c-25e5106d8b1f}") & MKDWD$(3)

$$NAME_AnchorResults_Anchor           = "Anchor"$$


'/*  PKEY_AnchorResults_ResultObjectID
' *
' *  Output parameter from GetChangesSinceAnchor method.  Contains the object
' *  ID of the AnchorResults object that has the results of the
' *  GetChangesSinceAnchor operation.
' *
' *  Type: UInt32
' *  Form: Object ID
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AnchorResults_ResultObjectID,
'    0x516b5dce, 0x8d45, 0x430f, 0x80, 0x5c, 0x25, 0xe5, 0x10, 0x6d, 0x8b, 0x1f,
'    4);
MACRO PKEY_AnchorResults_ResultObjectID = GUID$("{516b5dce-8d45-430f-805c-25e5106d8b1f}") & MKDWD$(4)

$$NAME_AnchorResults_ResultObjectID   = "ResultObjectID"$$


'/*****************************************************************************/
'/*  Anchor Sync Service Methods                                              */
'/*****************************************************************************/

'/*  METHOD_AnchorSyncSvc_GetChangesSinceAnchor
' */

$METHOD_AnchorSyncSvc_GetChangesSinceAnchor = GUID$("{37c550bc-f231-4727-bbbc-4cb33a3f3ecd}")

$$NAME_AnchorSyncSvc_GetChangesSinceAnchor    = "GetChangesSinceAnchor"$$

'/*  Inherited methods
' */

$METHOD_AnchorSyncSvc_BeginSync      = $METHOD_SyncSvc_BeginSync
$$NAME_AnchorSyncSvc_BeginSync       = $$NAME_SyncSvc_BeginSync

$METHOD_AnchorSyncSvc_EndSync        = $METHOD_SyncSvc_EndSync
$$NAME_AnchorSyncSvc_EndSync         = $$NAME_SyncSvc_EndSync


'/*****************************************************************************/
'/*  Anchor Sync Service Additional Defines                                   */
'/*****************************************************************************/

'/*  ENUM_AnchorResults_ItemState*
' *
' *  This enum is used when encoding the Anchor results stream.  It defines the
' *  current state of an object.  If a device is capable of distinguishing
' *  between item update and create operations the *_ItemStateCreated and
' *  *_ItemStateUpdated enumerations should be used.  If the device cannot
' *  distinuish between a create and an up updated the *_ItemStateChanged result
' *  should be used.
' *
' *  Type: UInt32
' *  Form: Enum
' */

%ENUM_AnchorResults_ItemStateInvalid = &H00000000
%ENUM_AnchorResults_ItemStateDeleted = &H00000001
%ENUM_AnchorResults_ItemStateCreated = &H00000002
%ENUM_AnchorResults_ItemStateUpdated = &H00000003
%ENUM_AnchorResults_ItemStateChanged = &H00000004
