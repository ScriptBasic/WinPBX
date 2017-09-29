' ########################################################################################
' Microsoft Windows
' File: ConfPriv.inc
' Library name: IPConfMSPLib
' Version: 1.0, Locale ID = 0
' Contents: Microsoft IP Conferencing Service Provider 1.0 Type Library
' Library GUID: {E36489BB-45C9-11D2-831F-00A0244D2298}
' Path: C:\WINDOWS\system32\confmsp.dll
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CONFPRIV_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ipmsp.inc"

' enum MULTICAST_LOOPBACK_MODE
%MM_NO_LOOPBACK        = 0
%MM_FULL_LOOPBACK      = %MM_NO_LOOPBACK   + 1
%MM_SELECTIVE_LOOPBACK = %MM_FULL_LOOPBACK + 1


' ########################################################################################
' Interface name = IDummy
' IID = {0D7CA54A-D252-4FCB-9104-F6DDD310B3F9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDummy_INTERFACE_DEFINED)
    %IDummy_INTERFACE_DEFINED = 1

$IID_IDummy = GUID$("{0D7CA54A-D252-4FCB-9104-F6DDD310B3F9}")

INTERFACE IDummy $IID_IDummy

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IDummy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLocalParticipant
' IID = {39CBF055-F77A-11D2-A824-00C04F8EF6E3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITLocalParticipant_INTERFACE_DEFINED)
    %ITLocalParticipant_INTERFACE_DEFINED = 1

$IID_ITLocalParticipant = GUID$("{39CBF055-F77A-11D2-A824-00C04F8EF6E3}")

INTERFACE ITLocalParticipant $IID_ITLocalParticipant

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LocalParticipantTypedInfo <1> ( _       ' VTable offset = 28
     BYVAL InfoType AS LONG _                           ' __in PARTICIPANT_TYPED_INFO InfoType
   ) AS WSTRING                                         ' __retval_out BSTR *ppInfo
   ' =====================================================================================
   PROPERTY SET LocalParticipantTypedInfo <1> ( _       ' VTable offset = 32
     BYVAL InfoType AS LONG _                           ' __in PARTICIPANT_TYPED_INFO InfoType
   , BYVAL pInfo AS WSTRING _                           ' __in BSTR pInfo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLocalParticipant_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumParticipant
' IID = {0A91B56C-5A35-11D2-95A0-00A0244D2298}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumParticipant_INTERFACE_DEFINED)
    %IEnumParticipant_INTERFACE_DEFINED = 1

$IID_IEnumParticipant = GUID$("{0A91B56C-5A35-11D2-95A0-00A0244D2298}")

INTERFACE IEnumParticipant $IID_IEnumParticipant

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITParticipant _                ' __out ITParticipant **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __in_out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumParticipant _                 ' __retval_out IEnumParticipant **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumParticipant_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITParticipantControl
' IID = {D2EE6684-5A34-11D2-95A0-00A0244D2298}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITParticipantControl_INTERFACE_DEFINED)
    %ITParticipantControl_INTERFACE_DEFINED = 1

$IID_ITParticipantControl = GUID$("{D2EE6684-5A34-11D2-95A0-00A0244D2298}")

INTERFACE ITParticipantControl $IID_ITParticipantControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EnumerateParticipants <1> ( _                 ' VTable offset = 28
   ) AS IEnumParticipant                                ' __retval_out IEnumParticipant **ppEnumParticipants
   ' =====================================================================================
   PROPERTY GET Participants <2> ( _                    ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITParticipantControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITParticipantSubStreamControl
' IID = {2C679108-5A35-11D2-95A0-00A0244D2298}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITParticipantSubStreamControl_INTERFACE_DEFINED)
    %ITParticipantSubStreamControl_INTERFACE_DEFINED = 1

$IID_ITParticipantSubStreamControl = GUID$("{2C679108-5A35-11D2-95A0-00A0244D2298}")

INTERFACE ITParticipantSubStreamControl $IID_ITParticipantSubStreamControl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SubStreamFromParticipant <1> ( _        ' VTable offset = 28
     BYVAL pParticipant AS ITParticipant _              ' __in ITParticipant *pParticipant
   ) AS ITSubStream                                     ' __retval_out ITSubStream **ppITSubStream
   ' =====================================================================================
   PROPERTY GET ParticipantFromSubStream <2> ( _        ' VTable offset = 32
     BYVAL pITSubStream AS ITSubStream _                ' __in ITSubStream *pITSubStream
   ) AS ITParticipant                                   ' __retval_out ITParticipant **ppParticipant
   ' =====================================================================================
   METHOD SwitchTerminalToSubStream <3> ( _             ' VTable offset = 36
     BYVAL pITTerminal AS ITTerminal _                  ' __in ITTerminal *pITTerminal
   , BYVAL pITSubStream AS ITSubStream _                ' __in ITSubStream *pITSubStream
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITParticipantSubStreamControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITParticipantEvent
' IID = {8BB35070-2DAD-11D3-A580-00C04F8EF6E3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITParticipantEvent_INTERFACE_DEFINED)
    %ITParticipantEvent_INTERFACE_DEFINED = 1

$IID_ITParticipantEvent = GUID$("{8BB35070-2DAD-11D3-A580-00C04F8EF6E3}")

INTERFACE ITParticipantEvent $IID_ITParticipantEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out PARTICIPANT_EVENT *pParticipantEvent
   ' =====================================================================================
   PROPERTY GET Participant <3> ( _                     ' VTable offset = 32
   ) AS ITParticipant                                   ' __retval_out ITParticipant **ppParticipant
   ' =====================================================================================
   PROPERTY GET SubStream <4> ( _                       ' VTable offset = 36
   ) AS ITSubStream                                     ' __retval_out ITSubStream **ppSubStream
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITParticipantEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMulticastControl
' IID = {410FA507-4DC6-415A-9014-633875D5406E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMulticastControl_INTERFACE_DEFINED)
    %IMulticastControl_INTERFACE_DEFINED = 1

$IID_IMulticastControl = GUID$("{410FA507-4DC6-415A-9014-633875D5406E}")

INTERFACE IMulticastControl $IID_IMulticastControl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LoopbackMode <1> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out MULTICAST_LOOPBACK_MODE *pMode
   ' =====================================================================================
   PROPERTY SET LoopbackMode <1> ( _                    ' VTable offset = 32
     BYVAL mode AS LONG _                               ' __in MULTICAST_LOOPBACK_MODE mode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMulticastControl_INTERFACE_DEFINED__ */
