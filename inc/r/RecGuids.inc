' ########################################################################################
' Microsoft Windows
' File: RecGuids.inc
' Contents: OLE reconciliation interface GUID definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RECGUIDS_INC = 1

'/* GUIDs
' ********/

$IID_IReconcileInitiator = GUID$("{99180161-DA16-101A-935C-444553540000}")
$IID_IReconcilableObject = GUID$("{99180162-DA16-101A-935C-444553540000}")
$IID_INotifyReplica      = GUID$("{99180163-DA16-101A-935C-444553540000}")
$IID_IBriefcaseInitiator = GUID$("{99180164-DA16-101A-935C-444553540000}")
