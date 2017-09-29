' ########################################################################################
' Microsoft Windows
' File: LM.inc
' Contents: This is the top level include file that includes all the files necessary for
' writing Lan Manager Application.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LM_INC = 1

#INCLUDE ONCE "WINDOWS.INC"

#INCLUDE ONCE "LMCONS.INC"        ' // LAN Manager common definitions
#INCLUDE ONCE "LMERR.INC"         ' // LAN Manager network error definitions

#INCLUDE ONCE "LMACCESS.INC"      ' // Access, Domain, Group and User classes
#INCLUDE ONCE "LMALERT.INC"       ' // Alerter
#INCLUDE ONCE "LMSHARE.INC"       ' // Connection, File, Session and Share classes
#INCLUDE ONCE "LMMSG.INC"         ' // Message class
#INCLUDE ONCE "LMREMUTL.INC"      ' // Remote Utility class
#INCLUDE ONCE "LMREPL.INC"        ' // Replicator class
#INCLUDE ONCE "LMSERVER.INC"      ' // Server class
#INCLUDE ONCE "LMSVC.INC"         ' // Service class
#INCLUDE ONCE "LMUSE.INC"         ' // Use class
#INCLUDE ONCE "LMAPIBUF.INC"      ' // NetApiBuffer class
#INCLUDE ONCE "LMWKSTA.INC"       ' // Workstation class
#INCLUDE ONCE "LMERRLOG.INC"      ' // NetErrorLog class
#INCLUDE ONCE "LMCONFIG.INC"      ' // NetConfig class
#INCLUDE ONCE "LMSTATS.INC"       ' // NetStats class
#INCLUDE ONCE "LMAUDIT.INC"       ' // NetAudit class
#INCLUDE ONCE "LMJOIN.INC"        ' // NetJoinDomain class
