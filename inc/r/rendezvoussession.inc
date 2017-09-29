' ########################################################################################
' Microsoft Windows
' File: RendezvousSession.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' The Rendezvous API consists of the Component Object Model (COM) interfaces
' IRendezvousApplication, IRendezvousSession and DRendezvousSessionEvents. A peer-to-peer
' application like Windows Remote Assistance implements the IRendezvousApplication
' interface. An IM application implements the IRendezvousSession and
' DRendezvousSessionEvents interface.
' ########################################################################################

#INCLUDE THIS ONCE
%RENDEZVOUSSESSION_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

%DISPID_EVENT_ON_STATE_CHANGED = 5
%DISPID_EVENT_ON_TERMINATION   = 6
%DISPID_EVENT_ON_CONTEXT_DATA  = 7
%DISPID_EVENT_ON_SEND_ERROR    = 8

' enum RENDEZVOUS_SESSION_STATE
%RSS_UNKNOWN    = 0
%RSS_READY      = %RSS_UNKNOWN    + 1
%RSS_INVITATION = %RSS_READY      + 1
%RSS_ACCEPTED   = %RSS_INVITATION + 1
%RSS_CONNECTED  = %RSS_ACCEPTED   + 1
%RSS_CANCELLED  = %RSS_CONNECTED  + 1
%RSS_DECLINED   = %RSS_CANCELLED  + 1
%RSS_TERMINATED = %RSS_DECLINED   + 1

' enum RENDEZVOUS_SESSION_FLAGS
%RSF_NONE                 = 0&
%RSF_INVITER              = &H1&
%RSF_INVITEE              = &H2&
%RSF_ORIGINAL_INVITER     = &H4&
%RSF_REMOTE_LEGACYSESSION = &H8&
%RSF_REMOTE_WIN7SESSION   = &H10&

$CLSID_RendezvousApplication = GUID$("{0B7E019A-B5DE-47FA-8966-9082F82FB192}")
$IID_DRendezvousSessionEvents = GUID$("{3FA19CF8-64C4-4F53-AE60-635B3806ECA6}")

' ########################################################################################
' Interface name = IRendezvousSession
' IID = 9BA4B1DD-8B0C-48B7-9E7C-2F25857C8DF5
' /* [unique][oleautomation][helpstring][uuid][object] */
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRendezvousSession_INTERFACE_DEFINED)
    %IRendezvousSession_INTERFACE_DEFINED = 1

$IID_IRendezvousSession = GUID$("{9BA4B1DD-8B0C-48B7-9E7C-2F25857C8DF5}")

INTERFACE IRendezvousSession $IID_IRendezvousSession

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 12
   ) AS LONG                                            ' __retval_out RENDEZVOUS_SESSION_STATE *pSessionState
   ' =====================================================================================
   PROPERTY GET RemoteUser ( _                          ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *bstrUserName
   ' =====================================================================================
   PROPERTY GET Flags ( _                               ' VTable offset = 20
   ) AS LONG                                            ' __retval_out LONG *pFlags
   ' =====================================================================================
   METHOD SendContextData ( _                           ' VTable offset = 24
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 28
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL bstrAppData AS WSTRING _                     ' __in BSTR bstrAppData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRendezvousSession_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRendezvousApplication
' IID = 4F4D070B-A275-49FB-B10D-8EC26387B50D
' /* [unique][oleautomation][uuid][object] */
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRendezvousApplication_INTERFACE_DEFINED)
    %IRendezvousApplication_INTERFACE_DEFINED = 1

$IID_IRendezvousApplication = GUID$("{4F4D070B-A275-49FB-B10D-8EC26387B50D}")

INTERFACE IRendezvousApplication $IID_IRendezvousApplication

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetRendezvousSession (_                       ' VTable offset = 12
     BYVAL pRendezvousSession AS IUnknown _             ' __in IUnknown *pRendezvousSession
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRendezvousApplication_INTERFACE_DEFINED__ */
