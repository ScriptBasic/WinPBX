' ########################################################################################
' Microsoft Windows
' File: TCGuid.inc
' Contents: QoS guid definitions for use by the Traffic Control users.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TCGUID_INC = 1

'//
'//   Remaining Bandwidth guid
'//
$GUID_QOS_REMAINING_BANDWIDTH = GUID$("{C4C51720-40EC-11D1-2C91-00AA00574915}")

'//
'//   Best Effort Bandwidth guid
'//
$GUID_QOS_BESTEFFORT_BANDWIDTH = GUID$("{ED885290-40EC-11D1-2C91-00AA00574915}")

'//
'//   Latency guid
'//
$GUID_QOS_LATENCY = GUID$("{FC408EF0-40EC-11D1-2C91-00AA00574915}")

'//
'//   Flow Count guid
'//
$GUID_QOS_FLOW_COUNT = GUID$("{1147F880-40ED-11D1-2C91-00AA00574915}")

'//
'//   Non Best Effort Limit guid
'//
$GUID_QOS_NON_BESTEFFORT_LIMIT = GUID$("{185C44E0-40ED-11D1-2C91-00AA00574915}")

'//
'//   Maximum Outstanding Sends guid
'//
$GUID_QOS_MAX_OUTSTANDING_SENDS = GUID$("{161FFA86-6120-11D1-2C91-00AA00574915}")

'//
'// Packet scheduler statistics
'//
$GUID_QOS_STATISTICS_BUFFER = GUID$("{BB2C0980-E900-11D1-B07E-0080C71382BF}")

'//
'// Packet Scheduler Flow Mode
'//
$GUID_QOS_FLOW_MODE = GUID$("{5C82290A-515A-11D2-8E58-00C04FC9BFCB}")

'//
'// ISSLOW Flow
'//
$GUID_QOS_ISSLOW_FLOW = GUID$("{ABF273A4-EE07-11D2-BE1B-00A0C99EE63B}")

'//
'// Timer Resolution
'//
$GUID_QOS_TIMER_RESOLUTION = GUID$("{BA10CC88-F13E-11D2-BE1B-00A0C99EE63B}")

'//
'// The conforming IP Precedence value for this flow.
'//
$GUID_QOS_FLOW_IP_CONFORMING = GUID$("{07F99A8B-FCD2-11D2-BE1E-00A0C99EE63B}")

'//
'// The non-conforming IP Precedence value for this flow.
'//
$GUID_QOS_FLOW_IP_NONCONFORMING = GUID$("{087A5987-FCD2-11D2-BE1E-00A0C99EE63B}")

'//
'// The conforming 802.1p value for this flow.
'//
$GUID_QOS_FLOW_8021P_CONFORMING = GUID$("{08C1E013-FCD2-11D2-BE1E-00A0C99EE63B}")

'//
'// The non-conforming 802.1p value for this flow.
'//
$GUID_QOS_FLOW_8021P_NONCONFORMING = GUID$("{09023F91-FCD2-11D2-BE1E-00A0C99EE63B}")

'//
'// This will enable the Averaging statistics in Packet scheduler. (eg: Avg. number of packets in shaper)
'//
$GUID_QOS_ENABLE_AVG_STATS = GUID$("{BAFB6D11-27C4-4801-A46F-EF8080C188C8}")

'//
'// This will enable Window size adjustment for TCP connections on a slow link, running ICS
'//
$GUID_QOS_ENABLE_WINDOW_ADJUSTMENT = GUID$("{AA966725-D3E9-4C55-B335-2A00279A1E64}")
