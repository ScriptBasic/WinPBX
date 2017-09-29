' ########################################################################################
' Microsoft Windows
' File: natupnp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: NATUPNPLib
' Version: 1.0, Locale ID = 0
' Description: NATUPnP 1.0 Type Library
' Path: C:\WINDOWS\system32\hnetcfg.dll\2
' Library GUID: {1C565858-F302-471E-B409-F180AA4ABEC6}
' ########################################################################################

#INCLUDE THIS ONCE
%NATUPNP_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_NATUPNPLib = GUID$("{1C565858-F302-471E-B409-F180AA4ABEC6}")

$PROGID_UPnPNAT1 = "HNetCfg.NATUPnP.1"
$PROGID_UPnPNAT = "HNetCfg.NATUPnP"

$CLSID_UPnPNAT = GUID$("{AE1E00AA-3FD5-403C-8A27-2BBDC30CD0E1}")

' ########################################################################################
' Interface name = IUPnPNAT
' IID = {B171C812-CC76-485A-94D8-B6B3A2794E99}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPNAT_INTERFACE_DEFINED)
    %IUPnPNAT_INTERFACE_DEFINED = 1

$IID_IUPnPNAT = GUID$("{B171C812-CC76-485A-94D8-B6B3A2794E99}")

INTERFACE IUPnPNAT $IID_IUPnPNAT

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StaticPortMappingCollection <1> ( _     ' VTable offset = 28
   ) AS IStaticPortMappingCollection                    ' __retval_out IStaticPortMappingCollection **ppSPMs
   ' =====================================================================================
   PROPERTY GET DynamicPortMappingCollection <2> ( _    ' VTable offset = 32
   ) AS IDynamicPortMappingCollection                   ' __retval_out IDynamicPortMappingCollection **ppDPMs
   ' =====================================================================================
   PROPERTY GET NATEventManager <3> ( _                 ' VTable offset = 36
   ) AS INATEventManager                                ' __retval_out INATEventManager **ppNEM
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPNAT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INATEventManager
' IID = {624BD588-9060-4109-B0B0-1ADBBCAC32DF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INATEventManager_INTERFACE_DEFINED)
    %INATEventManager_INTERFACE_DEFINED = 1

$IID_INATEventManager = GUID$("{624BD588-9060-4109-B0B0-1ADBBCAC32DF}")

INTERFACE INATEventManager $IID_INATEventManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET ExternalIPAddressCallback <1> ( _       ' VTable offset = 28
     BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET NumberOfEntriesCallback <2> ( _         ' VTable offset = 32
     BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INATEventManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INATExternalIPAddressCallback
' IID = 9C416740-A34E-446F-BA06-ABD04C3149AE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INATExternalIPAddressCallback_INTERFACE_DEFINED)
    %INATExternalIPAddressCallback_INTERFACE_DEFINED = 1

$IID_INATExternalIPAddressCallback = GUID$("{9C416740-A34E-446F-BA06-ABD04C3149AE}")

INTERFACE INATExternalIPAddressCallback $IID_INATExternalIPAddressCallback

   INHERIT IDispatch

   ' =====================================================================================
   METHOD NewExternalIPAddress ( _                      ' VTable offset = 12
     BYVAL bstrNewExternalIPAddress AS WSTRING _        ' __in BSTR bstrNewExternalIPAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INATExternalIPAddressCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INATNumberOfEntriesCallback
' IID = C83A0A74-91EE-41B6-B67A-67E0F00BBD78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INATNumberOfEntriesCallback_INTERFACE_DEFINED)
    %INATNumberOfEntriesCallback_INTERFACE_DEFINED = 1

$IID_INATNumberOfEntriesCallback = GUID$("{C83A0A74-91EE-41B6-B67A-67E0F00BBD78}")

INTERFACE INATNumberOfEntriesCallback $IID_INATNumberOfEntriesCallback

   INHERIT IDispatch

   ' =====================================================================================
   METHOD NewNumberOfEntries ( _                        ' VTable offset = 12
     BYVAL lNewNumberOfEntries AS LONG _                ' __in long lNewNumberOfEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INATNumberOfEntriesCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDynamicPortMappingCollection
' IID = {B60DE00F-156E-4E8D-9EC1-3A2342C10899}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDynamicPortMappingCollection_INTERFACE_DEFINED)
    %IDynamicPortMappingCollection_INTERFACE_DEFINED = 1

$IID_IDynamicPortMappingCollection = GUID$("{B60DE00F-156E-4E8D-9EC1-3A2342C10899}")

INTERFACE IDynamicPortMappingCollection $IID_IDynamicPortMappingCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL bstrRemoteHost AS WSTRING _                  ' __in BSTR bstrRemoteHost
   , BYVAL lExternalPort AS LONG _                      ' __in long lExternalPort
   , BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS IDynamicPortMapping                             ' __retval_out IDynamicPortMapping **ppDPM
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD Remove <2> ( _                                ' VTable offset = 40
     BYVAL bstrRemoteHost AS WSTRING _                  ' __in BSTR bstrRemoteHost
   , BYVAL lExternalPort AS LONG _                      ' __in long lExternalPort
   , BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 44
     BYVAL bstrRemoteHost AS WSTRING _                  ' __in BSTR bstrRemoteHost
   , BYVAL lExternalPort AS LONG _                      ' __in long lExternalPort
   , BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL lInternalPort AS LONG _                      ' __in long lInternalPort
   , BYVAL bstrInternalClient AS WSTRING _              ' __in BSTR bstrInternalClient
   , BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   , BYVAL lLeaseDuration AS LONG _                     ' __in long lLeaseDuration
   ) AS IDynamicPortMapping                             ' __retval_out IDynamicPortMapping **ppDPM
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDynamicPortMappingCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDynamicPortMapping
' IID = {4FC80282-23B6-4378-9A27-CD8F17C9400C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDynamicPortMapping_INTERFACE_DEFINED)
    %IDynamicPortMapping_INTERFACE_DEFINED = 1

$IID_IDynamicPortMapping = GUID$("{4FC80282-23B6-4378-9A27-CD8F17C9400C}")

INTERFACE IDynamicPortMapping $IID_IDynamicPortMapping

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ExternalIPAddress <1> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RemoteHost <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ExternalPort <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Protocol <4> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET InternalPort <5> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET InternalClient <6> ( _                  ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET Description <8> ( _                     ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET LeaseDuration <9> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD RenewLease <10> ( _                           ' VTable offset = 64
     BYVAL lLeaseDurationDesired AS LONG _              ' __in long lLeaseDurationDesired
   ) AS LONG                                            ' __retval_out long *pLeaseDurationReturned
   ' =====================================================================================
   METHOD EditInternalClient <11> ( _                   ' VTable offset = 68
     BYVAL bstrInternalClient AS WSTRING _              ' __in BSTR bstrInternalClient
   )                                                    ' void
   ' =====================================================================================
   METHOD Enable <12> ( _                               ' VTable offset = 72
     BYVAL vb AS INTEGER _                              ' __in VARIANT_BOOL vb
   )                                                    ' void
   ' =====================================================================================
   METHOD EditDescription <13> ( _                      ' VTable offset = 76
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD EditInternalPort <14> ( _                     ' VTable offset = 80
     BYVAL lInternalPort AS LONG _                      ' __in long lInternalPort
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDynamicPortMapping_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStaticPortMappingCollection
' IID = {CD1F3E77-66D6-4664-82C7-36DBB641D0F1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IStaticPortMappingCollection_INTERFACE_DEFINED)
    %IStaticPortMappingCollection_INTERFACE_DEFINED = 1

$IID_IStaticPortMappingCollection = GUID$("{CD1F3E77-66D6-4664-82C7-36DBB641D0F1}")

INTERFACE IStaticPortMappingCollection $IID_IStaticPortMappingCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lExternalPort AS LONG _                      ' __in long lExternalPort
   , BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS IStaticPortMapping                              ' __retval_out IStaticPortMapping **ppSPM
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD Remove <2> ( _                                ' VTable offset = 40
     BYVAL lExternalPort AS LONG _                      ' __in long lExternalPort
   , BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 44
     BYVAL lExternalPort AS LONG _                      ' __in long lExternalPort
   , BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL lInternalPort AS LONG _                      ' __in long lInternalPort
   , BYVAL bstrInternalClient AS WSTRING _              ' __in BSTR bstrInternalClient
   , BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IStaticPortMapping                              ' __retval_out IStaticPortMapping **ppSPM
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStaticPortMappingCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStaticPortMapping
' IID = {6F10711F-729B-41E5-93B8-F21D0F818DF1}
' IStaticPortMapping Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IStaticPortMapping_INTERFACE_DEFINED)
    %IStaticPortMapping_INTERFACE_DEFINED = 1

$IID_IStaticPortMapping = GUID$("{6F10711F-729B-41E5-93B8-F21D0F818DF1}")

INTERFACE IStaticPortMapping $IID_IStaticPortMapping

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ExternalIPAddress <1> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ExternalPort <2> ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET InternalPort <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Protocol <4> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET InternalClient <5> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Enabled <6> ( _                         ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET Description <7> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD EditInternalClient <8> ( _                    ' VTable offset = 56
     BYVAL bstrInternalClient AS WSTRING _              ' __in BSTR bstrInternalClient
   )                                                    ' void
   ' =====================================================================================
   METHOD Enable <9> ( _                                ' VTable offset = 60
     BYVAL vb AS INTEGER _                              ' __in VARIANT_BOOL vb
   )                                                    ' void
   ' =====================================================================================
   METHOD EditDescription <10> ( _                      ' VTable offset = 64
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD EditInternalPort <11> ( _                     ' VTable offset = 68
     BYVAL lInternalPort AS LONG _                      ' __in long lInternalPort
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStaticPortMapping_INTERFACE_DEFINED__ */
