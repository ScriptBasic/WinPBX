' ########################################################################################
' Microsoft Windows
' File: AqAdmin.inc
' Library name: AQAdmin
' Version: 1.0, Locale ID = 0
' Contents: Advanced Queueing Admin 1.0 Type Library
' Library GUID: {83866CAC-740D-11D2-94E4-00C04FA379F1}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AQADMIN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "aqadmtyp.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AQAdmin = GUID$("{83866CAD-740D-11D2-94E4-00C04FA379F1}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAQAdmin = GUID$("{476D70A6-1A90-11D3-BFCB-00C04FA3490A}")
$IID_IAQEnumMessages = GUID$("{BA7AF302-7373-11D2-94E4-00C04FA379F1}")
$IID_IAQMessage = GUID$("{BA7AF305-7373-11D2-94E4-00C04FA379F1}")
$IID_IEnumLinkQueues = GUID$("{BA7AF303-7373-11D2-94E4-00C04FA379F1}")
$IID_IEnumVSAQLinks = GUID$("{BA7AF300-7373-11D2-94E4-00C04FA379F1}")
$IID_ILinkQueue = GUID$("{FF9A1BB6-1E96-11D3-BFCC-00C04FA3490A}")
$IID_ISequentialStream = GUID$("{0C733A30-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IStream = GUID$("{0000000C-0000-0000-C000-000000000046}")
$IID_IVSAQAdmin = GUID$("{E2ED3340-1E96-11D3-BFCC-00C04FA3490A}")
$IID_IVSAQLink = GUID$("{3F962F94-1ECD-11D3-BFCC-00C04FA3490A}")

' ########################################################################################
' Interface name = IAQAdmin
' IID = {476D70A6-1A90-11D3-BFCB-00C04FA3490A}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAQAdmin_INTERFACE_DEFINED)
    %IAQAdmin_INTERFACE_DEFINED = 1

INTERFACE IAQAdmin $IID_IAQAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVirtualServerAdminITF ( _                  ' VTable offset = 12
     BYREF wszComputer AS WSTRINGZ _                    ' __in LPCWSTR wszComputer
   , BYREF wszVirtualServer AS WSTRINGZ _               ' __in LPCWSTR wszVirtualServer
   , BYREF ppivsaqadmin AS IVSAQAdmin _                 ' __out IVSAQAdmin **ppivsaqadmin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAQAdmin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVSAQAdmin
' IID = {E2ED3340-1E96-11D3-BFCC-00C04FA3490A}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVSAQAdmin_INTERFACE_DEFINED)
    %IVSAQAdmin_INTERFACE_DEFINED = 1

INTERFACE IVSAQAdmin $IID_IVSAQAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLinkEnum ( _                               ' VTable offset = 12
     BYREF ppenum AS IEnumVSAQLinks _                   ' __out IEnumVSAQLinks **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopAllLinks ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartAllLinks ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlobalLinkState ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVSAQAdmin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumVSAQLinks
' IID = {BA7AF300-7373-11D2-94E4-00C04FA379F1}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumVSAQLinks_INTERFACE_DEFINED)
    %IEnumVSAQLinks_INTERFACE_DEFINED = 1

INTERFACE IEnumVSAQLinks $IID_IEnumVSAQLinks

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgelt AS IVSAQLink _                         ' __out IVSAQLink **rgelt
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumVSAQLinks _                   ' __out IEnumVSAQLinks **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumVSAQLinks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVSAQLink
' IID = {3F962F94-1ECD-11D3-BFCC-00C04FA3490A}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVSAQLink_INTERFACE_DEFINED)
    %IVSAQLink_INTERFACE_DEFINED = 1

INTERFACE IVSAQLink $IID_IVSAQLink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF pli AS LINK_INFO _                           ' __inout LINK_INFO *pli
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLinkState ( _                              ' VTable offset = 16
     BYVAL la AS LINK_ACTION_ENUM _                     ' __in LINK_ACTION la
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueueEnum ( _                              ' VTable offset = 20
     BYREF ppenum AS IEnumLinkQueues _                  ' __out IEnumLinkQueues **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVSAQLink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumLinkQueues
' IID = {BA7AF303-7373-11D2-94E4-00C04FA379F1}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumLinkQueues_INTERFACE_DEFINED)
    %IEnumLinkQueues_INTERFACE_DEFINED = 1

INTERFACE IEnumLinkQueues $IID_IEnumLinkQueues

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgelt AS ILinkQueue _                        ' __out ILinkQueue **rgelt
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumLinkQueues _                  ' __out IEnumLinkQueues **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumLinkQueues_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILinkQueue
' IID = {FF9A1BB6-1E96-11D3-BFCC-00C04FA3490A}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILinkQueue_INTERFACE_DEFINED)
    %ILinkQueue_INTERFACE_DEFINED = 1

INTERFACE ILinkQueue $IID_ILinkQueue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF pqi AS QUEUE_INFO _                          ' __inout QUEUE_INFO *pqi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageEnum ( _                            ' VTable offset = 16
     BYREF pFilter AS MESSAGE_ENUM_FILTER _             ' __in MESSAGE_ENUM_FILTER *pFilter
   , BYREF ppenum AS IAQEnumMessages _                  ' __out IAQEnumMessages **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILinkQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAQEnumMessages
' IID = {BA7AF302-7373-11D2-94E4-00C04FA379F1}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAQEnumMessages_INTERFACE_DEFINED)
    %IAQEnumMessages_INTERFACE_DEFINED = 1

INTERFACE IAQEnumMessages $IID_IAQEnumMessages

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgelt AS IAQMessage _                        ' __out IAQMessage **rgelt
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IAQEnumMessages _                  ' __out IAQEnumMessages **ppenum
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAQEnumMessages_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAQMessage
' IID = {BA7AF305-7373-11D2-94E4-00C04FA379F1}
' Advanced Queue Administration Object
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAQMessage_INTERFACE_DEFINED)
    %IAQMessage_INTERFACE_DEFINED = 1

INTERFACE IAQMessage $IID_IAQMessage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF pmi AS MESSAGE_INFO _                        ' __inout MESSAGE_INFO *pmi
   )                                                    ' void
   ' =====================================================================================
   METHOD GetContentStream ( _                          ' VTable offset = 16
     BYREF ppIStream AS IStream _                       ' __out IStream **ppIStream IStream
   , BYREF pwszContentType AS DWORD _                   ' __out LPWSTR *pwszContentType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAQMessage_INTERFACE_DEFINED__ */
