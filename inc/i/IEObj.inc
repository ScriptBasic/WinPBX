' ########################################################################################
' Microsoft Windows
' File: IEObj.inc
' Contents: Defines the IEFRAME API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IEOBJ_INC = 1

'//
'// Internet Explorer suppresses script-initiated dialog boxes and other UI
'// elements if the calling thread is not the thread for the active tab or is not
'// associated with the thread for the active tab.
'//
'// This method enables any thread to be associated with the specified tab thread
'// so that the dialog suppression and other logic treats code running on the
'// specified thread the same way that it does for the tab thread.
'//
'// Parameters:
'//
'//   dwTabThreadID - ID of the tab thread
'//   dwAssociatedThreadID - ID of the thread to associate with the tab thread.
'//

DECLARE FUNCTION IEAssociateThreadWithTab IMPORT "ieframe.dll" ALIAS "IEAssociateThreadWithTab" ( _
   BYVAL dwTabThreadID AS DWORD _                       ' __in DWORD dwTabThreadID
 , BYVAL dwAssociatedThreadID AS DWORD _                ' __in DWORD dwAssociatedThreadID
 ) AS LONG                                              ' HRESULT

'//
'// This method unassociates a thread previously associated with IEAssociateThreadWithTab.
'//
'// Parameters:
'//
'//   dwTabThreadID - ID of the tab thread
'//   dwAssociatedThreadID - ID of the thread to disassociate with the tab thread.
'//

DECLARE FUNCTION IEDisassociateThreadWithTab IMPORT "ieframe.dll" ALIAS "IEDisassociateThreadWithTab" ( _
   BYVAL dwTabThreadID AS DWORD _                       ' __in DWORD dwTabThreadID
 , BYVAL dwAssociatedThreadID AS DWORD _                ' __in DWORD dwAssociatedThreadID
 ) AS LONG                                              ' HRESULT

'// This method returns Internet Explorer's InPrivate Browsing status.
'//
'// Return values:
'// TRUE- InPrivate Browsing is enabled.
'// FALSE - InPrivate Browsing is not enabled.
'//

DECLARE FUNCTION IEIsInPrivateBrowsing IMPORT "ieframe.dll" ALIAS "IEIsInPrivateBrowsing" ( _
 ) AS LONG                                              ' BOOL

'// This method returns Internet Explorer's InPrivate Browsing status.
'//
'// Return values:
'// TRUE- InPrivate Blocking is enabled.
'// FALSE - InPrivate Blocking is not enabled.
'//

DECLARE FUNCTION IEInPrivateFilteringEnabled IMPORT "ieframe.dll" ALIAS "IEInPrivateFilteringEnabled" ( _
 ) AS LONG                                              ' BOOL
