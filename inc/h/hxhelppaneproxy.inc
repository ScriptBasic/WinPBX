' ########################################################################################
' Microsoft Windows
' File: HxHelpPaneProxy.inc
' Library name: HelpPane
' Version: 1.0, Locale ID = 0
' Library GUID: {8CEC5857-07A1-11D9-B15E-000D56BFE6EE}
' Path: C:\Windows\System32\HelpPaneProxy.dll
' Contents: AP Client 1.0 HelpPane Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HXHELPPANEPROXY_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$LIBID_HelpPane = GUID$("{8CEC5857-07A1-11D9-B15E-000D56BFE6EE}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_HxHelpPane = GUID$("{8CEC58E7-07A1-11D9-B15E-000D56BFE6EE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IHxHelpPane = GUID$("{8CEC5884-07A1-11D9-B15E-000D56BFE6EE}")
$IID_IHxInteractiveUser = GUID$("{8CEC595B-07A1-11D9-B15E-000D56BFE6EE}")

' ########################################################################################
' Interface name = IHxHelpPane
' IID = {8CEC5884-07A1-11D9-B15E-000D56BFE6EE}
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHxHelpPane_INTERFACE_DEFINED)
    %IHxHelpPane_INTERFACE_DEFINED = 1

INTERFACE IHxHelpPane $IID_IHxHelpPane

   INHERIT IAutomation

   ' =====================================================================================
   METHOD DisplayTask ( _                               ' VTable offset = 12
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayContents ( _                           ' VTable offset = 16
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplaySearchResults ( _                      ' VTable offset = 20
     BYVAL bstrSearchQuery AS WSTRING _                 ' __in BSTR bstrSearchQuery
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxHelpPane_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxInteractiveUser
' IID = {8CEC595B-07A1-11D9-B15E-000D56BFE6EE}
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHxInteractiveUser_INTERFACE_DEFINED)
    %IHxInteractiveUser_INTERFACE_DEFINED = 1

INTERFACE IHxInteractiveUser $IID_IHxInteractiveUser

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 12
     BYREF pcUrl AS WSTRINGZ _                          ' __in LPCWSTR pcUrl
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxInteractiveUser_INTERFACE_DEFINED__ */
