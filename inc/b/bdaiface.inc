' ########################################################################################
' Microsoft Windows
' File: bdaiface.inc
' Contents: Broadcast Driver Architecture (BDA).
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BDAIFACE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "bdatypes.inc"

' enum SmartCardStatusType
MACRO SMARTCARDSTATUSTYPE_ENUM = LONG
%SmartCardStatusType_CardInserted        = 0
%SmartCardStatusType_CardRemoved         = %SmartCardStatusType_CardInserted    + 1
%SmartCardStatusType_CardError           = %SmartCardStatusType_CardRemoved     + 1
%SmartCardStatusType_CardDataChanged     = %SmartCardStatusType_CardError       + 1
%SmartCardStatusType_CardFirmwareUpgrade = %SmartCardStatusType_CardDataChanged + 1

' enum SmartCardAssociationType
MACRO SMARTCARDASSOCIATIONTYPE_ENUM = LONG
%SmartCardAssociationType_NotAssociated      = 0
%SmartCardAssociationType_Associated         = %SmartCardAssociationType_NotAssociated + 1
%SmartCardAssociationType_AssociationUnknown = %SmartCardAssociationType_Associated    + 1

' enum LocationCodeSchemeType
MACRO LOCATIONCODESCHEMETYPE_ENUM = LONG
%LocationCodeSchemeType_SCTE_18 = 0

' // Size = 8 bytes
TYPE EALocationCodeType BYTE
   LocationCodeScheme AS LOCATIONCODESCHEMETYPE_ENUM   ' LocationCodeSchemeType
   state_code         AS BYTE                          ' BYTE
   county_subdivision AS BYTE                          ' BYTE
   county_code        AS WORD                          ' WORD
END TYPE

' enum EntitlementType
MACRO ENTITLEMENTTYPE_ENUM = LONG
%EntitlementType_Entitled         = 0
%EntitlementType_NotEntitled      = %EntitlementType_Entitled    + 1
%EntitlementType_TechnicalFailure = %EntitlementType_NotEntitled + 1

' enum UICloseReasonType
MACRO UICLOSEREASONTYPE_ENUM = LONG
%UICloseReasonType_NotReady     = 0
%UICloseReasonType_UserClosed   = %UICloseReasonType_NotReady     + 1
%UICloseReasonType_SystemClosed = %UICloseReasonType_UserClosed   + 1
%UICloseReasonType_DeviceClosed = %UICloseReasonType_SystemClosed + 1
%UICloseReasonType_ErrorClosed  = %UICloseReasonType_DeviceClosed + 1

' // Size = 16 bytes
TYPE SmartCardApplication DWORD FILL
   ApplicationType      AS LONG          ' ApplicationTypeType
   ApplicationVersion   AS WORD          ' USHORT
   pbstrApplicationName AS WSTRING PTR   ' BSTR
   pbstrApplicationURL  AS WSTRING PTR   ' BSTR
END TYPE

' enum BDA_DrmPairingError
MACRO BDA_DRMPAIRINGERROR_ENUM = LONG
%BDA_DrmPairing_Succeeded          = 0
%BDA_DrmPairing_HardwareFailure    = %BDA_DrmPairing_Succeeded          + 1
%BDA_DrmPairing_NeedRevocationData = %BDA_DrmPairing_HardwareFailure    + 1
%BDA_DrmPairing_NeedIndiv          = %BDA_DrmPairing_NeedRevocationData + 1
%BDA_DrmPairing_Other              = %BDA_DrmPairing_NeedIndiv          + 1
%BDA_DrmPairing_DrmInitFailed      = %BDA_DrmPairing_Other              + 1
%BDA_DrmPairing_DrmNotPaired       = %BDA_DrmPairing_DrmInitFailed      + 1
%BDA_DrmPairing_DrmRePairSoon      = %BDA_DrmPairing_DrmNotPaired       + 1
%BDA_DrmPairing_Aborted            = %BDA_DrmPairing_DrmRePairSoon      + 1
%BDA_DrmPairing_NeedSDKUpdate      = %BDA_DrmPairing_Aborted            + 1


' ########################################################################################
' IBDA_NetworkProvider interface
' IID = FD501041-8EBE-11CE-8183-00AA00577DA2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_NetworkProvider_INTERFACE_DEFINED)
    %IBDA_NetworkProvider_INTERFACE_DEFINED = 1

$IID_IBDA_NetworkProvider = GUID$("{FD501041-8EBE-11CE-8183-00AA00577DA2}")

INTERFACE IBDA_NetworkProvider $IID_IBDA_NetworkProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PutSignalSource ( _                           ' VTable offset = 12
     BYVAL ulSignalSource AS DWORD _                    ' __in ULONG ulSignalSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignalSource ( _                           ' VTable offset = 16
     BYREF pulSignalSource AS DWORD _                   ' __in_out ULONG *pulSignalSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkType ( _                            ' VTable offset = 20
     BYREF pguidNetworkType AS GUID _                   ' __in_out GUID *pguidNetworkType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutTuningSpace ( _                            ' VTable offset = 24
     BYREF guidTuningSpace AS GUID _                    ' __in REFGUID guidTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTuningSpace ( _                            ' VTable offset = 28
     BYREF pguidTuingSpace AS GUID _                    ' __in_out GUID *pguidTuingSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterDeviceFilter ( _                      ' VTable offset = 32
     BYVAL pUnkFilterControl AS IUnknown _              ' __in IUnknown *pUnkFilterControl
   , BYREF ppvRegisitrationContext AS DWORD _           ' __in_out ULONG *ppvRegisitrationContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterDeviceFilter ( _                    ' VTable offset = 36
     BYVAL pvRegistrationContext AS DWORD _             ' __in ULONG pvRegistrationContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_NetworkProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_EthernetFilter interface
' IID = 71985F43-1CA1-11D3-9CC8-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_EthernetFilter_INTERFACE_DEFINED)
    %IBDA_EthernetFilter_INTERFACE_DEFINED = 1

$IID_IBDA_EthernetFilter = GUID$("{71985F43-1CA1-11D3-9CC8-00C04F7971E0}")

INTERFACE IBDA_EthernetFilter $IID_IBDA_EthernetFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMulticastListSize ( _                      ' VTable offset = 12
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMulticastList ( _                          ' VTable offset = 16
     BYVAL ulcbAddresses AS DWORD _                     ' __in ULONG ulcbAddresses
   , BYVAL pAddressList AS BYTE PTR _                   ' __in BYTE pAddressList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMulticastList ( _                          ' VTable offset = 20
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   , BYVAL pAddressList AS BYTE PTR _                   ' __out BYTE pAddressList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMulticastMode ( _                          ' VTable offset = 24
     BYVAL ulModeMask AS DWORD _                        ' __in ULONG ulModeMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMulticastMode ( _                          ' VTable offset = 28
     BYREF pulModeMask AS DWORD _                       ' __out ULONG *pulModeMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_EthernetFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_IPV4Filter interface
' IID = 71985F44-1CA1-11D3-9CC8-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_IPV4Filter_INTERFACE_DEFINED)
    %IBDA_IPV4Filter_INTERFACE_DEFINED = 1

$IID_IBDA_IPV4Filter = GUID$("{71985F44-1CA1-11D3-9CC8-00C04F7971E0}")

INTERFACE IBDA_IPV4Filter $IID_IBDA_IPV4Filter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMulticastListSize ( _                      ' VTable offset = 12
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMulticastList ( _                          ' VTable offset = 16
     BYVAL ulcbAddresses AS DWORD _                     ' __in ULONG ulcbAddresses
   , BYVAL pAddressList AS BYTE PTR _                   ' __in BYTE pAddressList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMulticastList ( _                          ' VTable offset = 20
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   , BYVAL pAddressList AS BYTE PTR _                   ' __out BYTE pAddressList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMulticastMode ( _                          ' VTable offset = 24
     BYVAL ulModeMask AS DWORD _                        ' __in ULONG ulModeMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMulticastMode ( _                          ' VTable offset = 28
     BYREF pulModeMask AS DWORD _                       ' __out ULONG *pulModeMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_IPV4Filter_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_IPV6Filter interface
' IID = E1785A74-2A23-4FB3-9245-A8F88017EF33
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_IPV6Filter_INTERFACE_DEFINED)
    %IBDA_IPV6Filter_INTERFACE_DEFINED = 1

$IID_IBDA_IPV6Filter = GUID$("{E1785A74-2A23-4FB3-9245-A8F88017EF33}")

INTERFACE IBDA_IPV6Filter $IID_IBDA_IPV6Filter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMulticastListSize ( _                      ' VTable offset = 12
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMulticastList ( _                          ' VTable offset = 16
     BYVAL ulcbAddresses AS DWORD _                     ' __in ULONG ulcbAddresses
   , BYVAL pAddressList AS BYTE PTR _                   ' __in BYTE pAddressList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMulticastList ( _                          ' VTable offset = 20
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   , BYVAL pAddressList AS BYTE PTR _                   ' __out BYTE pAddressList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMulticastMode ( _                          ' VTable offset = 24
     BYVAL ulModeMask AS DWORD _                        ' __in ULONG ulModeMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMulticastMode ( _                          ' VTable offset = 28
     BYREF pulModeMask AS DWORD _                       ' __out ULONG *pulModeMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_IPV6Filter_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_DeviceControl interface
' IID = FD0A5AF3-B41D-11D2-9C95-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DeviceControl_INTERFACE_DEFINED)
    %IBDA_DeviceControl_INTERFACE_DEFINED = 1

$IID_IBDA_DeviceControl = GUID$("{FD0A5AF3-B41D-11D2-9C95-00C04F7971E0}")

INTERFACE IBDA_DeviceControl $IID_IBDA_DeviceControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartChanges ( _                              ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckChanges ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChangeState ( _                            ' VTable offset = 24
     BYREF pState AS DWORD _                            ' __in_out ULONG *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DeviceControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_PinControl interface
' IID = 0DED49D5-A8B7-4D5D-97A1-12B0C195874D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_PinControl_INTERFACE_DEFINED)
    %IBDA_PinControl_INTERFACE_DEFINED = 1

$IID_IBDA_PinControl = GUID$("{0DED49D5-A8B7-4D5D-97A1-12B0C195874D}")

INTERFACE IBDA_PinControl $IID_IBDA_PinControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPinID ( _                                  ' VTable offset = 12
     BYREF pulPinID AS DWORD _                          ' __in_out ULONG *pulPinID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPinType ( _                                ' VTable offset = 16
     BYREF pulPinType AS DWORD _                        ' __in_out ULONG *pulPinType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegistrationContext ( _                       ' VTable offset = 20
     BYREF pulRegistrationCtx AS DWORD _                ' __in_out ULONG *pulRegistrationCtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_PinControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_SignalProperties interface
' IID = D2F1644B-B409-11D2-BC69-00A0C9EE9E16
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_SignalProperties_INTERFACE_DEFINED)
    %IBDA_SignalProperties_INTERFACE_DEFINED = 1

$IID_IBDA_SignalProperties = GUID$("{D2F1644B-B409-11D2-BC69-00A0C9EE9E16}")

INTERFACE IBDA_SignalProperties $IID_IBDA_SignalProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PutNetworkType ( _                            ' VTable offset = 12
     BYREF guidNetworkType AS GUID _                    ' __in REFGUID guidNetworkType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkType ( _                            ' VTable offset = 16
     BYREF pguidNetworkType AS GUID _                   ' __in_out GUID *pguidNetworkType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutSignalSource ( _                           ' VTable offset = 20
     BYVAL ulSignalSource AS DWORD _                    ' __in ULONG ulSignalSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignalSource ( _                           ' VTable offset = 24
     BYREF pulSignalSource AS DWORD _                   ' __in_out ULONG *pulSignalSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutTuningSpace ( _                            ' VTable offset = 28
     BYREF guidTuningSpace AS GUID _                    ' __in REFGUID guidTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTuningSpace ( _                            ' VTable offset = 32
     BYREF pguidTuingSpace AS GUID _                    ' __in_out GUID *pguidTuingSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_SignalProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_SignalStatistics interface
' IID = 1347D106-CF3A-428A-A5CB-AC0D9A2A4338
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_SignalStatistics_INTERFACE_DEFINED)
    %IBDA_SignalStatistics_INTERFACE_DEFINED = 1

$IID_IBDA_SignalStatistics = GUID$("{1347D106-CF3A-428A-A5CB-AC0D9A2A4338}")

INTERFACE IBDA_SignalStatistics $IID_IBDA_SignalStatistics

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_SignalStrength ( _                        ' VTable offset = 12
     BYVAL lDbStrength AS LONG _                        ' __in LONG lDbStrength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SignalStrength ( _                        ' VTable offset = 16
     BYREF plDbStrength AS DWORD _                      ' __in_out LONG *plDbStrength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SignalQuality ( _                         ' VTable offset = 20
     BYVAL lPercentQuality AS LONG _                    ' __in LONG lPercentQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SignalQuality ( _                         ' VTable offset = 24
     BYREF plPercentQuality AS LONG _                   ' __in_out LONG *plPercentQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SignalPresent ( _                         ' VTable offset = 28
     BYVAL fPresent AS BYTE _                           ' __in BOOLEAN fPresent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SignalPresent ( _                         ' VTable offset = 32
     BYREF pfPresent AS BYTE _                          ' __in_out BOOLEAN *pfPresent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SignalLocked ( _                          ' VTable offset = 36
     BYVAL fLocked AS BYTE _                            ' __in BOOLEAN fLocked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SignalLocked ( _                          ' VTable offset = 36
     BYREF pfLocked AS BYTE _                           ' __in_out BOOLEAN *pfLocked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SampleTime ( _                            ' VTable offset = 40
     BYVAL lmsSampleTime AS LONG _                      ' __in LONG lmsSampleTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SampleTime ( _                            ' VTable offset = 44
     BYREF plmsSampleTime AS LONG _                     ' __in_out LONG *plmsSampleTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_SignalStatistics_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_Topology interface
' IID = 79B56888-7FEA-4690-B45D-38FD3C7849BE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_Topology_INTERFACE_DEFINED)
    %IBDA_Topology_INTERFACE_DEFINED = 1

$IID_IBDA_Topology = GUID$("{79B56888-7FEA-4690-B45D-38FD3C7849BE}")

INTERFACE IBDA_Topology $IID_IBDA_Topology

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNodeTypes ( _                              ' VTable offset = 12
     BYREF pulcNodeTypes AS DWORD _                     ' __in_out ULONG *pulcNodeTypes
   , BYVAL ulcNodeTypesMax AS DWORD _                   ' __in ULONG ulcNodeTypesMax
   , BYREF rgulNodeTypes AS DWORD _                     ' __in_out ULONG rgulNodeTypes[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeDescriptors ( _                        ' VTable offset = 16
     BYREF ulcNodeDescriptors AS DWORD _                ' __in_out ULONG *ulcNodeDescriptors
   , BYVAL ulcNodeDescriptorsMax AS DWORD _             ' __in ULONG ulcNodeDescriptorsMax
   , BYREF rgNodeDescriptors AS BDANODE_DESCRIPTOR _    ' __in_out BDANODE_DESCRIPTOR rgNodeDescriptors[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeInterfaces ( _                         ' VTable offset = 20
     BYVAL ulNodeType AS DWORD _                        ' __in ULONG ulNodeType
   , BYREF pulcInterfaces AS DWORD _                    ' __in_out ULONG *pulcInterfaces
   , BYVAL ulcInterfacesMax AS DWORD _                  ' __in ULONG ulcInterfacesMax
   , BYREF rgguidInterfaces AS GUID _                   ' __in_out GUID rgguidInterfaces[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPinTypes ( _                               ' VTable offset = 24
     BYREF pulcPinTypes AS DWORD _                      ' __in_out ULONG *pulcPinTypes
   , BYVAL ulcPinTypesMax AS DWORD _                    ' __in ULONG ulcPinTypesMax
   , BYREF rgulPinTypes AS DWORD _                      ' __in_out ULONG rgulPinTypes[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTemplateConnections ( _                    ' VTable offset = 28
     BYREF pulcConnections AS DWORD _                   ' __in_out ULONG *pulcConnections
   , BYVAL ulcConnectionsMax AS DWORD _                 ' __in ULONG ulcConnectionsMax
   , BYREF rgConnections AS BDA_TEMPLATE_CONNECTION _   ' __in_out BDA_TEMPLATE_CONNECTION rgConnections[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePin ( _                                 ' VTable offset = 32
     BYVAL ulPinType AS DWORD _                         ' __in ULONG ulPinType
   , BYREF pulPinId AS DWORD _                          ' __in_out ULONG *pulPinId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePin ( _                                 ' VTable offset = 36
     BYVAL ulPinId AS DWORD _                           ' __in ULONG ulPinId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 40
     BYVAL ulPinId AS DWORD _                           ' __in ULONG ulPinId
   , BYREF pMediaType AS AM_MEDIA_TYPE _                ' __in AM_MEDIA_TYPE *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMedium ( _                                 ' VTable offset = 44
     BYVAL ulPinId AS DWORD _                           ' __in ULONG ulPinId
   , BYREF pMedium AS REGPINMEDIUM _                    ' __in REGPINMEDIUM *pMedium
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTopology ( _                            ' VTable offset = 48
     BYVAL ulInputPinId AS DWORD _                      ' __in ULONG ulInputPinId
   , BYVAL ulOutputPinId AS DWORD _                     ' __in ULONG ulOutputPinId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlNode ( _                            ' VTable offset = 52
     BYVAL ulInputPinId AS DWORD _                      ' __in ULONG ulInputPinId
   , BYVAL ulOutputPinId AS DWORD _                     ' __in ULONG ulOutputPinId
   , BYVAL ulNodeType AS DWORD _                        ' __in ULONG ulNodeType
   , BYREF ppControlNode AS IUnknown _                  ' __in_out IUnknown **ppControlNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_Topology_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_VoidTransform interface
' IID = 71985F46-1CA1-11D3-9CC8-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_VoidTransform_INTERFACE_DEFINED)
    %IBDA_VoidTransform_INTERFACE_DEFINED = 1

$IID_IBDA_VoidTransform = GUID$("{71985F46-1CA1-11D3-9CC8-00C04F7971E0}")

INTERFACE IBDA_VoidTransform $IID_IBDA_VoidTransform

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_VoidTransform_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_NullTransform interface
' IID = 71985F46-1CA1-11D3-9CC8-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_NullTransform_INTERFACE_DEFINED)
    %IBDA_NullTransform_INTERFACE_DEFINED = 1

$IID_IBDA_NullTransform = GUID$("{71985F46-1CA1-11D3-9CC8-00C04F7971E0}")

INTERFACE IBDA_NullTransform $IID_IBDA_NullTransform

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_NullTransform_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_FrequencyFilter interface
' IID = 71985F47-1CA1-11D3-9CC8-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_FrequencyFilter_INTERFACE_DEFINED)
    %IBDA_FrequencyFilter_INTERFACE_DEFINED = 1

$IID_IBDA_FrequencyFilter = GUID$("{71985F47-1CA1-11D3-9CC8-00C04F7971E0}")

INTERFACE IBDA_FrequencyFilter $IID_IBDA_FrequencyFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_Autotune ( _                              ' VTable offset = 12
     BYVAL ulTransponder AS DWORD _                     ' __in ULONG ulTransponder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Autotune ( _                              ' VTable offset = 16
     BYREF pulTransponder AS DWORD _                    ' __in_out ULONG *pulTransponder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Frequency ( _                             ' VTable offset = 20
     BYVAL ulFrequency AS DWORD _                       ' __in ULONG ulFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Frequency ( _                             ' VTable offset = 24
     BYREF pulFrequency AS DWORD _                      ' __in_out ULONG *pulFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Polarity ( _                              ' VTable offset = 28
     BYVAL Polarity AS POLARISATION_ENUM _              ' __in Polarisation Polarity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Polarity ( _                              ' VTable offset = 32
     BYREF pPolarity AS POLARISATION_ENUM _             ' __in_out Polarisation *pPolarity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Range ( _                                 ' VTable offset = 36
     BYVAL ulRange AS DWORD _                           ' __in ULONG ulRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Range ( _                                 ' VTable offset = 40
     BYREF pulRange AS DWORD _                          ' __in_out ULONG *pulRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Bandwidth ( _                             ' VTable offset = 44
     BYVAL ulBandwidth AS DWORD _                       ' __in ULONG ulBandwidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Bandwidth ( _                             ' VTable offset = 48
     BYREF pulBandwidth AS DWORD _                      ' __in_out ULONG *pulBandwidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_FrequencyMultiplier ( _                   ' VTable offset = 52
     BYVAL ulMultiplier AS DWORD _                      ' __in ULONG ulMultiplier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_FrequencyMultiplier ( _                   ' VTable offset = 56
     BYREF pulMultiplier AS DWORD _                     ' __in_out ULONG *pulMultiplier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_FrequencyFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_LNBInfo interface
' IID = 992CF102-49F9-4719-A664-C4F23E2408F4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_LNBInfo_INTERFACE_DEFINED)
    %IBDA_LNBInfo_INTERFACE_DEFINED = 1

$IID_IBDA_LNBInfo = GUID$("{992CF102-49F9-4719-A664-C4F23E2408F4}")

INTERFACE IBDA_LNBInfo $IID_IBDA_LNBInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_LocalOscilatorFrequencyLowBand ( _        ' VTable offset = 12
     BYVAL ulLOFLow AS DWORD _                          ' __in ULONG ulLOFLow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_LocalOscilatorFrequencyLowBand ( _        ' VTable offset = 16
     BYREF pulLOFLow AS DWORD _                         ' __in_out ULONG *pulLOFLow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_LocalOscilatorFrequencyHighBand ( _       ' VTable offset = 20
     BYVAL ulLOFHigh AS DWORD _                         ' __in ULONG ulLOFHigh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_LocalOscilatorFrequencyHighBand ( _       ' VTable offset = 24
     BYREF pulLOFHigh AS DWORD _                        ' __in_out ULONG *pulLOFHigh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HighLowSwitchFrequency ( _                ' VTable offset = 28
     BYVAL ulSwitchFrequency AS DWORD _                 ' __in ULONG ulSwitchFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HighLowSwitchFrequency ( _                ' VTable offset = 32
     BYREF pulSwitchFrequency AS DWORD _                ' __in_out ULONG *pulSwitchFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_LNBInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_DiseqCommand interface
' IID = F84E2AB0-3C6B-45E3-A0FC-8669D4B81F11
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DiseqCommand_INTERFACE_DEFINED)
    %IBDA_DiseqCommand_INTERFACE_DEFINED = 1

$IID_IBDA_DiseqCommand = GUID$("{F84E2AB0-3C6B-45E3-A0FC-8669D4B81F11}")

INTERFACE IBDA_DiseqCommand $IID_IBDA_DiseqCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_EnableDiseqCommands ( _                   ' VTable offset = 12
     BYVAL bEnable AS BYTE _                            ' __in BOOLEAN bEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DiseqLNBSource ( _                        ' VTable offset = 16
     BYVAL ulLNBSource AS DWORD _                       ' __in ULONG ulLNBSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DiseqUseToneBurst ( _                     ' VTable offset = 20
     BYVAL bUseToneBurst AS BYTE _                      ' __in BOOLEAN bUseToneBurst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DiseqRepeats ( _                          ' VTable offset = 24
     BYVAL ulRepeats AS DWORD _                         ' __in ULONG ulRepeats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DiseqSendCommand ( _                      ' VTable offset = 28
     BYVAL ulRequestId AS DWORD _                       ' __in ULONG ulRequestId
   , BYVAL ulcbCommandLen AS DWORD _                    ' __in ULONG ulcbCommandLen
   , BYVAL pbCommand AS BYTE PTR _                      ' __in BYTE *pbCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DiseqResponse ( _                         ' VTable offset = 32
     BYVAL ulRequestId AS DWORD _                       ' __in ULONG ulRequestId
   , BYREF pulcbResponseLen AS DWORD _                  ' __inout ULONG *pulcbResponseLen
   , BYVAL pbResponse AS BYTE PTR _                     ' __inout BYTE pbResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DiseqCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_AutoDemodulate interface
' IID = DDF15B12-BD25-11D2-9CA0-00C04F7971E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_AutoDemodulate_INTERFACE_DEFINED)
    %IBDA_AutoDemodulate_INTERFACE_DEFINED = 1

$IID_IBDA_AutoDemodulate = GUID$("{DDF15B12-BD25-11D2-9CA0-00C04F7971E0}")

INTERFACE IBDA_AutoDemodulate $IID_IBDA_AutoDemodulate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_AutoDemodulate ( _                        ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_AutoDemodulate_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_AutoDemodulateEx interface
' IID = 34518D13-1182-48E6-B28F-B24987787326
' Inherited interface = IBDA_AutoDemodulate
' ########################################################################################

#IF NOT %DEF(%IBDA_AutoDemodulateEx_INTERFACE_DEFINED)
    %IBDA_AutoDemodulateEx_INTERFACE_DEFINED = 1

$IID_IBDA_AutoDemodulateEx = GUID$("{34518D13-1182-48E6-B28F-B24987787326}")

INTERFACE IBDA_AutoDemodulateEx $IID_IBDA_AutoDemodulateEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IBDA_AutoDemodulate methods
   ' =====================================================================================
   METHOD put_AutoDemodulate ( _                        ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBDA_AutoDemodulateEx methods
   ' =====================================================================================
   METHOD get_SupportedDeviceNodeTypes ( _              ' VTable offset = 16
     BYVAL ulcDeviceNodeTypesMax AS DWORD _             ' __in ULONG ulcDeviceNodeTypesMax
   , BYREF pulcDeviceNodeTypes AS DWORD _               ' __out ULONG *pulcDeviceNodeTypes
   , BYREF pguidDeviceNodeTypes AS GUID _               ' __in_out GUID *pguidDeviceNodeTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SupportedVideoFormats ( _                 ' VTable offset = 20
     BYREF pulAMTunerModeType AS DWORD _                ' __out ULONG *pulAMTunerModeType
   , BYREF pulAnalogVideoStandard AS DWORD _            ' __out ULONG *pulAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AuxInputCount ( _                         ' VTable offset = 24
     BYREF pulCompositeCount AS DWORD _                 ' __in_out ULONG *pulCompositeCount
   , BYREF pulSvideoCount AS DWORD _                    ' __in_out ULONG *pulSvideoCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_AutoDemodulateEx_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_DigitalDemodulator interface
' IID = EF30F379-985B-4D10-B640-A79D5E04E1E0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DigitalDemodulator_INTERFACE_DEFINED)
    %IBDA_DigitalDemodulator_INTERFACE_DEFINED = 1

$IID_IBDA_DigitalDemodulator = GUID$("{EF30F379-985B-4D10-B640-A79D5E04E1E0}")

INTERFACE IBDA_DigitalDemodulator $IID_IBDA_DigitalDemodulator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_ModulationType ( _                        ' VTable offset = 12
     BYVAL pModulationType AS MODULATIONTYPE_ENUM _     ' __in ModulationType *pModulationType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ModulationType ( _                        ' VTable offset = 16
     BYREF pModulationType AS MODULATIONTYPE_ENUM _     ' __in_out ModulationType *pModulationType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InnerFECMethod ( _                        ' VTable offset = 20
     BYVAL pFECMethod AS FECMETHOD_ENUM _               ' __in FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InnerFECMethod ( _                        ' VTable offset = 24
     BYREF pFECMethod AS FECMETHOD_ENUM _               ' __in_out FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InnerFECRate ( _                          ' VTable offset = 28
     BYVAL pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InnerFECRate ( _                          ' VTable offset = 32
     BYREF pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in_out BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OuterFECMethod ( _                        ' VTable offset = 36
     BYVAL pFECMethod AS FECMETHOD_ENUM _               ' __in FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OuterFECMethod ( _                        ' VTable offset = 40
     BYREF pFECMethod AS FECMETHOD_ENUM _               ' __in_out FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OuterFECRate ( _                          ' VTable offset = 44
     BYVAL pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OuterFECRate ( _                          ' VTable offset = 48
     BYREF pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in_out BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SymbolRate ( _                            ' VTable offset = 52
     BYVAL pSymbolRate AS DWORD _                       ' __in ULONG *pSymbolRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SymbolRate ( _                            ' VTable offset = 56
     BYREF pSymbolRate AS DWORD _                       ' __in_out ULONG *pSymbolRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SpectralInversion ( _                     ' VTable offset = 60
     BYVAL pSpectralInversion AS SPECTRALINVERSION_ENUM _ ' __in SpectralInversion *pSpectralInversion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SpectralInversion ( _                     ' VTable offset = 64
     BYREF pSpectralInversion AS SPECTRALINVERSION_ENUM _ ' __in_out SpectralInversion *pSpectralInversion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DigitalDemodulator_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_DigitalDemodulator2 interface
' IID = 525ED3EE-5CF3-4E1E-9A06-5368A84F9A6E
' Inherited interface = IBDA_DigitalDemodulator
' ########################################################################################

#IF NOT %DEF(%IBDA_DigitalDemodulator2_INTERFACE_DEFINED)
    %IBDA_DigitalDemodulator2_INTERFACE_DEFINED = 1

$IID_IBDA_DigitalDemodulator2 = GUID$("{525ED3EE-5CF3-4E1E-9A06-5368A84F9A6E}")

INTERFACE IBDA_DigitalDemodulator2 $IID_IBDA_DigitalDemodulator2

   INHERIT IUnknown

   ' =====================================================================================
   ' IBDA_DigitalDemodulator Methods
   ' =====================================================================================
   METHOD put_ModulationType ( _                        ' VTable offset = 12
     BYVAL pModulationType AS MODULATIONTYPE_ENUM _     ' __in ModulationType *pModulationType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ModulationType ( _                        ' VTable offset = 16
     BYREF pModulationType AS MODULATIONTYPE_ENUM _     ' __in_out ModulationType *pModulationType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InnerFECMethod ( _                        ' VTable offset = 20
     BYVAL pFECMethod AS FECMETHOD_ENUM _               ' __in FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InnerFECMethod ( _                        ' VTable offset = 24
     BYREF pFECMethod AS FECMETHOD_ENUM _               ' __in_out FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InnerFECRate ( _                          ' VTable offset = 28
     BYVAL pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InnerFECRate ( _                          ' VTable offset = 32
     BYREF pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in_out BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OuterFECMethod ( _                        ' VTable offset = 36
     BYVAL pFECMethod AS FECMETHOD_ENUM _               ' __in FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OuterFECMethod ( _                        ' VTable offset = 40
     BYREF pFECMethod AS FECMETHOD_ENUM _               ' __in_out FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OuterFECRate ( _                          ' VTable offset = 44
     BYVAL pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OuterFECRate ( _                          ' VTable offset = 48
     BYREF pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in_out BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SymbolRate ( _                            ' VTable offset = 52
     BYVAL pSymbolRate AS DWORD _                       ' __in ULONG *pSymbolRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SymbolRate ( _                            ' VTable offset = 56
     BYREF pSymbolRate AS DWORD _                       ' __in_out ULONG *pSymbolRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SpectralInversion ( _                     ' VTable offset = 60
     BYVAL pSpectralInversion AS SPECTRALINVERSION_ENUM _ ' __in SpectralInversion *pSpectralInversion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SpectralInversion ( _                     ' VTable offset = 64
     BYREF pSpectralInversion AS SPECTRALINVERSION_ENUM _ ' __in_out SpectralInversion *pSpectralInversion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBDA_DigitalDemodulator2 Methods
   ' =====================================================================================
   METHOD put_GuardInterval ( _                         ' VTable offset = 68
     BYVAL pGuardInterval AS GUARDINTERVAL_ENUM _       ' __in GuardInterval *pGuardInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_GuardInterval ( _                         ' VTable offset = 72
     BYREF pGuardInterval AS GUARDINTERVAL_ENUM _       ' __inout GuardInterval *pGuardInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TransmissionMode ( _                      ' VTable offset = 76
     BYVAL pTransmissionMode AS TRANSMISSIONMODE_ENUM _ ' __in TransmissionMode *pTransmissionMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TransmissionMode ( _                      ' VTable offset = 80
     BYREF pTransmissionMode AS TRANSMISSIONMODE_ENUM _ ' __inout TransmissionMode *pTransmissionMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RollOff ( _                               ' VTable offset = 84
     BYVAL pRollOff AS ROLLOFF_ENUM _                   ' __in RollOff *pRollOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RollOff ( _                               ' VTable offset = 88
     BYREF pRollOff AS ROLLOFF_ENUM _                   ' __inout RollOff *pRollOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Pilot ( _                                 ' VTable offset = 92
     BYVAL pPilot AS PILOT_ENUM _                       ' __in Pilot *pPilot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Pilot ( _                                 ' VTable offset = 96
     BYVAL pPilot AS PILOT_ENUM _                       ' __inout Pilot *pPilot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DigitalDemodulator2_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_DigitalDemodulator3 interface
' IID = 13F19604-7D32-4359-93A2-A05205D90AC9
' Inherited interface = IBDA_DigitalDemodulator2
' ########################################################################################

#IF NOT %DEF(%IBDA_DigitalDemodulator3_INTERFACE_DEFINED)
    %IBDA_DigitalDemodulator3_INTERFACE_DEFINED = 1

$IID_IBDA_DigitalDemodulator3 = GUID$("{13F19604-7D32-4359-93A2-A05205D90AC9}")

INTERFACE IBDA_DigitalDemodulator3 $IID_IBDA_DigitalDemodulator3

   INHERIT IUnknown

   ' =====================================================================================
   ' IBDA_DigitalDemodulator Methods
   ' =====================================================================================
   METHOD put_ModulationType ( _                        ' VTable offset = 12
     BYVAL pModulationType AS MODULATIONTYPE_ENUM _     ' __in ModulationType *pModulationType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ModulationType ( _                        ' VTable offset = 16
     BYREF pModulationType AS MODULATIONTYPE_ENUM _     ' __in_out ModulationType *pModulationType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InnerFECMethod ( _                        ' VTable offset = 20
     BYVAL pFECMethod AS FECMETHOD_ENUM _               ' __in FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InnerFECMethod ( _                        ' VTable offset = 24
     BYREF pFECMethod AS FECMETHOD_ENUM _               ' __in_out FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InnerFECRate ( _                          ' VTable offset = 28
     BYVAL pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InnerFECRate ( _                          ' VTable offset = 32
     BYREF pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in_out BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OuterFECMethod ( _                        ' VTable offset = 36
     BYVAL pFECMethod AS FECMETHOD_ENUM _               ' __in FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OuterFECMethod ( _                        ' VTable offset = 40
     BYREF pFECMethod AS FECMETHOD_ENUM _               ' __in_out FECMethod *pFECMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OuterFECRate ( _                          ' VTable offset = 44
     BYVAL pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OuterFECRate ( _                          ' VTable offset = 48
     BYREF pFECRate AS BINARYCONVOLUTIONCODERATE_ENUM _ ' __in_out BinaryConvolutionCodeRate *pFECRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SymbolRate ( _                            ' VTable offset = 52
     BYVAL pSymbolRate AS DWORD _                       ' __in ULONG *pSymbolRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SymbolRate ( _                            ' VTable offset = 56
     BYREF pSymbolRate AS DWORD _                       ' __in_out ULONG *pSymbolRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SpectralInversion ( _                     ' VTable offset = 60
     BYVAL pSpectralInversion AS SPECTRALINVERSION_ENUM _ ' __in SpectralInversion *pSpectralInversion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SpectralInversion ( _                     ' VTable offset = 64
     BYREF pSpectralInversion AS SPECTRALINVERSION_ENUM _ ' __in_out SpectralInversion *pSpectralInversion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBDA_DigitalDemodulator2 Methods
   ' =====================================================================================
   METHOD put_GuardInterval ( _                         ' VTable offset = 68
     BYVAL pGuardInterval AS GUARDINTERVAL_ENUM _       ' __in GuardInterval *pGuardInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_GuardInterval ( _                         ' VTable offset = 72
     BYREF pGuardInterval AS GUARDINTERVAL_ENUM _       ' __inout GuardInterval *pGuardInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TransmissionMode ( _                      ' VTable offset = 76
     BYVAL pTransmissionMode AS TRANSMISSIONMODE_ENUM _ ' __in TransmissionMode *pTransmissionMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TransmissionMode ( _                      ' VTable offset = 80
     BYREF pTransmissionMode AS TRANSMISSIONMODE_ENUM _ ' __inout TransmissionMode *pTransmissionMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RollOff ( _                               ' VTable offset = 84
     BYVAL pRollOff AS ROLLOFF_ENUM _                   ' __in RollOff *pRollOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RollOff ( _                               ' VTable offset = 88
     BYREF pRollOff AS ROLLOFF_ENUM _                   ' __inout RollOff *pRollOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Pilot ( _                                 ' VTable offset = 92
     BYVAL pPilot AS PILOT_ENUM _                       ' __in Pilot *pPilot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Pilot ( _                                 ' VTable offset = 96
     BYVAL pPilot AS PILOT_ENUM _                       ' __inout Pilot *pPilot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBDA_DigitalDemodulator3 Methods
   ' =====================================================================================
   METHOD put_SignalTimeouts ( _                        ' VTable offset = 100
     BYREF pSignalTimeouts AS BDA_SIGNAL_TIMEOUTS _     ' __in BDA_SIGNAL_TIMEOUTS *pSignalTimeouts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SignalTimeouts ( _                        ' VTable offset = 104
     BYREF pSignalTimeouts AS BDA_SIGNAL_TIMEOUTS _     ' __inout BDA_SIGNAL_TIMEOUTS *pSignalTimeouts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PLPNumber ( _                             ' VTable offset = 108
     BYVAL pPLPNumber AS DWORD _                        ' __in ULONG *pPLPNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PLPNumber ( _                             ' VTable offset = 112
     BYREF pPLPNumber AS DWORD _                        ' __inout ULONG *pPLPNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DigitalDemodulator3_INTERFACE_DEFINED__ */

' ########################################################################################

' KSPROPERTY_IPSINK enum
%KSPROPERTY_IPSINK_MULTICASTLIST       = 0
%KSPROPERTY_IPSINK_ADAPTER_DESCRIPTION = %KSPROPERTY_IPSINK_MULTICASTLIST       + 1
%KSPROPERTY_IPSINK_ADAPTER_ADDRESS     = %KSPROPERTY_IPSINK_ADAPTER_DESCRIPTION + 1

' ########################################################################################
' ICCSubStreamFiltering interface
' IID = 4B2BD7EA-8347-467B-8DBF-62F784929CC3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICCSubStreamFiltering_INTERFACE_DEFINED)
    %ICCSubStreamFiltering_INTERFACE_DEFINED = 1

$IID_ICCSubStreamFiltering = GUID$("{4B2BD7EA-8347-467B-8DBF-62F784929CC3}")

INTERFACE ICCSubStreamFiltering $IID_ICCSubStreamFiltering

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_SubstreamTypes ( _                        ' VTable offset = 12
     BYREF pTypes AS LONG _                             ' __retval_out long *pTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SubstreamTypes ( _                        ' VTable offset = 16
     BYVAL Types AS LONG _                              ' __in long Types
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICCSubStreamFiltering_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_IPSinkControl interface
' IID = 3F4DC8E2-4050-11D3-8F4B-00C04F7971E2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_IPSinkControl_INTERFACE_DEFINED)
    %IBDA_IPSinkControl_INTERFACE_DEFINED = 1

$IID_IBDA_IPSinkControl = GUID$("{3F4DC8E2-4050-11D3-8F4B-00C04F7971E2}")

INTERFACE IBDA_IPSinkControl $IID_IBDA_IPSinkControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMulticastList ( _                          ' VTable offset = 12
     BYREF pulcbSize AS DWORD _                         ' __in_out unsigned long *pulcbSize
   , BYREF pbBuffer AS DWORD _                          ' __in_out BYTE **pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterIPAddress ( _                       ' VTable offset = 16
     BYREF pulcbSize AS DWORD _                         ' __in_out unsigned long *pulcbSize
   , BYREF pbBuffer AS DWORD _                          ' __in_out BYTE **pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_IPSinkControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_IPSinkInfo interface
' IID = A750108F-492E-4D51-95F7-649B23FF7AD7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_IPSinkInfo_INTERFACE_DEFINED)
    %IBDA_IPSinkInfo_INTERFACE_DEFINED = 1

$IID_IBDA_IPSinkInfo = GUID$("{A750108F-492E-4D51-95F7-649B23FF7AD7}")

INTERFACE IBDA_IPSinkInfo $IID_IBDA_IPSinkInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_MulticastList ( _                         ' VTable offset = 12
     BYREF pulcbAddresses AS DWORD _                    ' __in_out ULONG *pulcbAddresses
   , BYREF ppbAddressList AS DWORD _                    ' __out BYTE **ppbAddressList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AdapterIPAddress ( _                      ' VTable offset = 16
     BYREF pbstrBuffer AS WSTRING _                     ' __out BSTR *pbstrBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AdapterDescription ( _                    ' VTable offset = 20
     BYREF pbstrBuffer AS WSTRING _                     ' __out BSTR *pbstrBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_IPSinkInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumPIDMap interface
' IID = AFB6C2A2-2C41-11D3-8A60-0000F81E0E4A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPIDMap_INTERFACE_DEFINED)
    %IEnumPIDMap_INTERFACE_DEFINED = 1

$IID_IEnumPIDMap = GUID$("{AFB6C2A2-2C41-11D3-8A60-0000F81E0E4A}")

INTERFACE IEnumPIDMap $IID_IEnumPIDMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   , BYREF pPIDMap AS PID_MAP _                         ' __in_out PID_MAP *pPIDMap
   , BYREF pcReceived AS DWORD _                        ' __out ULONG *pcReceived
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cRecords AS DWORD _                          ' __in ULONG cRecords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnumPIDMap AS IEnumPIDMap _               ' __out IEnumPIDMap **ppIEnumPIDMap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPIDMap_INTERFACE_DEFINED__ */


' ########################################################################################
' IMPEG2PIDMap interface
' IID = AFB6C2A1-2C41-11D3-8A60-0000F81E0E4A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMPEG2PIDMap_INTERFACE_DEFINED)
    %IMPEG2PIDMap_INTERFACE_DEFINED = 1

$IID_IMPEG2PIDMap = GUID$("{AFB6C2A1-2C41-11D3-8A60-0000F81E0E4A}")

INTERFACE IMPEG2PIDMap $IID_IMPEG2PIDMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MapPID ( _                                    ' VTable offset = 12
     BYVAL culPID AS DWORD _                            ' __in ULONG culPID
   , BYVAL pulPID AS DWORD _                            ' __in ULONG *pulPID
   , BYVAL MediaSampleContent AS LONG _                 ' __in MEDIA_SAMPLE_CONTENT MediaSampleContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnmapPID ( _                                  ' VTable offset = 16
     BYVAL culPID AS DWORD _                            ' __in ULONG culPID
   , BYVAL pulPID AS DWORD _                            ' __in ULONG *pulPID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumPIDMap ( _                                ' VTable offset = 20
     BYREF pIEnumPIDMap AS IEnumPIDMap _                ' __out IEnumPIDMap **pIEnumPIDMap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2PIDMap_INTERFACE_DEFINED__ */


' ########################################################################################
' IFrequencyMap interface
' IID = 06FB45C1-693C-4EA7-B79F-7A6A54D8DEF2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFrequencyMap_INTERFACE_DEFINED)
    %IFrequencyMap_INTERFACE_DEFINED = 1

$IID_IFrequencyMap = GUID$("{06FB45C1-693C-4EA7-B79F-7A6A54D8DEF2}")

INTERFACE IFrequencyMap $IID_IFrequencyMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_FrequencyMapping ( _                      ' VTable offset = 12
     BYREF ulCount AS DWORD _                           ' __out ULONG *ulCount
   , BYREF ppulList AS DWORD _                          ' __out ULONG **ppulList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_FrequencyMapping ( _                      ' VTable offset = 16
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pList AS DWORD _                             ' __in ULONG pList[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CountryCode ( _                           ' VTable offset = 20
     BYREF pulCountryCode AS DWORD _                    ' __out ULONG *pulCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CountryCode ( _                           ' VTable offset = 24
     BYVAL ulCountryCode AS DWORD _                     ' __in ULONG ulCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DefaultFrequencyMapping ( _               ' VTable offset = 28
     BYVAL ulCountryCode AS DWORD _                     ' __in ULONG ulCountryCode
   , BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   , BYREF ppulList AS DWORD _                          ' __out ULONG **ppulList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CountryCodeList ( _                       ' VTable offset = 32
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   , BYREF ppulList AS DWORD _                          ' __out ULONG **ppulList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFrequencyMap_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_EasMessage interface
' IID = D806973D-3EBE-46DE-8FBB-6358FE784208
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_EasMessage_INTERFACE_DEFINED)
    %IBDA_EasMessage_INTERFACE_DEFINED = 1

$IID_IBDA_EasMessage = GUID$("{D806973D-3EBE-46DE-8FBB-6358FE784208}")
$SID_IBDA_EasMessage = GUID$("{D806973D-3EBE-46DE-8FBB-6358FE784208}")

INTERFACE IBDA_EasMessage $IID_IBDA_EasMessage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_EasMessage ( _                            ' VTable offset = 12
     BYVAL ulEventID AS DWORD _                         ' __in ULONG ulEventID
   , BYREF ppEASObject AS IUnknown _                    ' __in_out IUnknown **ppEASObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_EasMessage_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_TransportStreamInfo interface
' IID = 8E882535-5F86-47AB-86CF-C281A72A0549
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_TransportStreamInfo_INTERFACE_DEFINED)
    %IBDA_TransportStreamInfo_INTERFACE_DEFINED = 1

$IID_IBDA_TransportStreamInfo = GUID$("{8E882535-5F86-47AB-86CF-C281A72A0549}")
$SID_IBDA_TransportStreamInfo = GUID$("{8E882535-5F86-47AB-86CF-C281A72A0549}")

INTERFACE IBDA_TransportStreamInfo $IID_IBDA_TransportStreamInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_PatTableTickCount ( _                     ' VTable offset = 12
     BYREF pPatTickCount AS DWORD _                     ' __out ULONG *pPatTickCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_TransportStreamInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_ConditionalAccess interface
' IID = CD51F1E0-7BE9-4123-8482-A2A796C0A6B0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_ConditionalAccess_INTERFACE_DEFINED)
    %IBDA_ConditionalAccess_INTERFACE_DEFINED = 1

$IID_IBDA_ConditionalAccess = GUID$("{CD51F1E0-7BE9-4123-8482-A2A796C0A6B0}")
$SID_IBDA_ConditionalAccess = GUID$("{CD51F1E0-7BE9-4123-8482-A2A796C0A6B0}")

INTERFACE IBDA_ConditionalAccess $IID_IBDA_ConditionalAccess

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_SmartCardStatus ( _                       ' VTable offset = 12
     BYREF pCardStatus AS SMARTCARDSTATUSTYPE_ENUM _    ' __out SmartCardStatusType *pCardStatus
   , BYREF pCardAssociation AS SMARTCARDASSOCIATIONTYPE_ENUM _ ' __out SmartCardAssociationType *pCardAssociation
   , BYREF pbstrCardError AS WSTRING _                  ' __out BSTR *pbstrCardError
   , BYREF pfOOBLocked AS INTEGER _                     ' __out VARIANT_BOOL *pfOOBLocked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SmartCardInfo ( _                         ' VTable offset = 16
     BYREF pbstrCardName AS WSTRING _                   ' __out BSTR *pbstrCardName
   , BYREF pbstrCardManufacturer AS WSTRING _           ' __out BSTR *pbstrCardManufacturer
   , BYREF pfDaylightSavings AS INTEGER _               ' __out VARIANT_BOOL *pfDaylightSavings
   , BYREF pbyRatingRegion AS BYTE _                    ' __out BYTE *pbyRatingRegion
   , BYREF plTimeZoneOffsetMinutes AS LONG _            ' __out LONG *plTimeZoneOffsetMinutes
   , BYREF pbstrLanguage AS WSTRING _                   ' __out BSTR *pbstrLanguage
   , BYREF pEALocationCode AS LONG _                    ' __out EALocationCodeType *pEALocationCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SmartCardApplications ( _                 ' VTable offset = 20
     BYREF pulcApplications AS DWORD _                  ' __in_out ULONG *pulcApplications
   , BYVAL ulcApplicationsMax AS DWORD _                ' __in ULONG ulcApplicationsMax
   , BYREF rgApplications AS LONG _                     ' __in_out (ulcApplicationsMax) SmartCardApplication rgApplications[  ])
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Entitlement ( _                           ' VTable offset = 24
     BYVAL usVirtualChannel AS WORD _                   ' __in USHORT usVirtualChannel
   , BYREF pEntitlement AS ENTITLEMENTTYPE_ENUM _       ' __out EntitlementType *pEntitlement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TuneByChannel ( _                             ' VTable offset = 28
     BYVAL usVirtualChannel AS WORD _                   ' __in USHORT usVirtualChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgram ( _                                ' VTable offset = 32
     BYVAL usProgramNumber AS WORD _                    ' __in USHORT usProgramNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddProgram ( _                                ' VTable offset = 36
     BYVAL usProgramNumber AS WORD _                    ' __in USHORT usProgramNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveProgram ( _                             ' VTable offset = 40
     BYVAL usProgramNumber AS WORD _                    ' __in USHORT usProgramNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModuleUI ( _                               ' VTable offset = 44
     BYVAL byDialogNumber AS BYTE _                     ' __in BYTE byDialogNumber
   , BYREF pbstrURL AS WSTRING _                        ' __out BSTR *pbstrURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InformUIClosed ( _                            ' VTable offset = 48
     BYVAL byDialogNumber AS BYTE _                     ' __in BYTE byDialogNumber
   , BYVAL CloseReason AS UICLOSEREASONTYPE_ENUM _      ' __in UICloseReasonType CloseReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_ConditionalAccess_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_DiagnosticProperties interface
' IID = 20E80CB5-C543-4C1B-8EB3-49E719EEE7D4
' Inherited interface = IPropertyBag
' ########################################################################################

#IF NOT %DEF(%IBDA_DiagnosticProperties_INTERFACE_DEFINED)
    %IBDA_DiagnosticProperties_INTERFACE_DEFINED = 1

$IID_IBDA_DiagnosticProperties = GUID$("{20E80CB5-C543-4C1B-8EB3-49E719EEE7D4}")
$SID_IBDA_DiagnosticProperties = GUID$("{20E80CB5-C543-4C1B-8EB3-49E719EEE7D4}")

INTERFACE IBDA_DiagnosticProperties $IID_IBDA_DiagnosticProperties

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyBag methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pVar AS VARIANT _                            ' __in_out VARIANT *pVar
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pVar AS VARIANT _                            ' __in VARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DiagnosticProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_DRM interface
' IID = F98D88B0-1992-4CD6-A6D9-B9AFAB99330D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DRM_INTERFACE_DEFINED)
    %IBDA_DRM_INTERFACE_DEFINED = 1

$IID_IBDA_DRM = GUID$("{F98D88B0-1992-4CD6-A6D9-B9AFAB99330D}")
$SID_IBDA_DRM = GUID$("{F98D88B0-1992-4CD6-A6D9-B9AFAB99330D}")

INTERFACE IBDA_DRM $IID_IBDA_DRM

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDRMPairingStatus ( _                       ' VTable offset = 12
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   , BYREF phError AS LONG _                            ' __out HRESULT *phError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PerformDRMPairing ( _                         ' VTable offset = 16
     BYVAL fSync AS LONG _                              ' __in BOOL fSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DRM_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_NameValueService interface
' IID = 7F0B3150-7B81-4AD4-98E3-7E9097094301
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_NameValueService_INTERFACE_DEFINED)
    %IBDA_NameValueService_INTERFACE_DEFINED = 1

$IID_IBDA_NameValueService = GUID$("{7F0B3150-7B81-4AD4-98E3-7E9097094301}")
$SID_IBDA_NameValueService = GUID$("{7F0B3150-7B81-4AD4-98E3-7E9097094301}")

INTERFACE IBDA_NameValueService $IID_IBDA_NameValueService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetValueNameByIndex ( _                       ' VTable offset = 12
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 16
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYREF pbstrValue AS WSTRING _                      ' __out BSTR *pbstrValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 20
     BYVAL ulDialogRequest AS DWORD _                   ' __in ULONG ulDialogRequest
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   , BYVAL ulReserved AS DWORD _                        ' __in ULONG ulReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_NameValueService_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_ConditionalAccessEx interface
' IID = 7F0B3150-7B81-4AD4-98E3-7E9097094301
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_ConditionalAccessEx_INTERFACE_DEFINED)
    %IBDA_ConditionalAccessEx_INTERFACE_DEFINED = 1

$IID_IBDA_ConditionalAccessEx = GUID$("{7F0B3150-7B81-4AD4-98E3-7E9097094301}")
$SID_IBDA_ConditionalAccessEx = GUID$("{7F0B3150-7B81-4AD4-98E3-7E9097094301}")

INTERFACE IBDA_ConditionalAccessEx $IID_IBDA_ConditionalAccessEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CheckEntitlementToken ( _                     ' VTable offset = 12
     BYVAL ulDialogRequest AS DWORD _                   ' __in ULONG ulDialogRequest
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL RequestType AS LONG _                        ' __in BDA_CONDITIONALACCESS_REQUESTTYPE RequestType
   , BYVAL ulcbEntitlementTokenLen AS DWORD _           ' __in ULONG ulcbEntitlementTokenLen
   , BYVAL pbEntitlementToken AS BYTE PTR _             ' __in BYTE *pbEntitlementToken
   , BYREF pulDescrambleStatus AS DWORD _               ' __out ULONG *pulDescrambleStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCaptureToken ( _                           ' VTable offset = 16
     BYVAL ulcbCaptureTokenLen AS DWORD _               ' __in ULONG ulcbCaptureTokenLen
   , BYVAL pbCaptureToken AS BYTE PTR _                 ' __in BYTE *pbCaptureToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenBroadcastMmi ( _                          ' VTable offset = 20
     BYVAL ulDialogRequest AS DWORD _                   ' __in ULONG ulDialogRequest
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL EventId AS DWORD _                           ' __in ULONG EventId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseMmiDialog ( _                            ' VTable offset = 24
     BYVAL ulDialogRequest AS DWORD _                   ' __in ULONG ulDialogRequest
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL ulDialogNumber AS LONG _                     ' __in ULONG ulDialogNumber
   , BYVAL ReasonCode AS LONG _                         ' __in BDA_CONDITIONALACCESS_MMICLOSEREASON ReasonCode
   , BYREF pulSessionResult AS DWORD _                  ' __out ULONG *pulSessionResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDialogRequestNumber ( _                 ' VTable offset = 28
     BYREF pulDialogRequestNumber AS DWORD _            ' __out ULONG *pulDialogRequestNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_ConditionalAccessEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_ISDBConditionalAccess interface
' IID = 5E68C627-16C2-4E6C-B1E2-D00170CDAA0F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_ISDBConditionalAccess_INTERFACE_DEFINED)
    %IBDA_ISDBConditionalAccess_INTERFACE_DEFINED = 1

$IID_IBDA_ISDBConditionalAccess = GUID$("{5E68C627-16C2-4E6C-B1E2-D00170CDAA0F}")
$SID_IBDA_ISDBConditionalAccess = GUID$("{5E68C627-16C2-4E6C-B1E2-D00170CDAA0F}")

INTERFACE IBDA_ISDBConditionalAccess $IID_IBDA_ISDBConditionalAccess

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetIsdbCasRequest ( _                         ' VTable offset = 12
     BYVAL ulRequestId AS DWORD _                       ' __in ULONG ulRequestId
   , BYVAL ulcbRequestBufferLen AS DWORD _              ' __in ULONG ulcbRequestBufferLen
   , BYVAL pbRequestBuffer AS BYTE PTR _                ' __in BYTE *pbRequestBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_ISDBConditionalAccess_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_EventingService interface
' IID = 207C413F-00DC-4C61-BAD6-6FEE1FF07064
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_EventingService_INTERFACE_DEFINED)
    %IBDA_EventingService_INTERFACE_DEFINED = 1

$IID_IBDA_EventingService = GUID$("{207C413F-00DC-4C61-BAD6-6FEE1FF07064}")
$SID_IBDA_EventingService = GUID$("{207C413F-00DC-4C61-BAD6-6FEE1FF07064}")

INTERFACE IBDA_EventingService $IID_IBDA_EventingService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CompleteEvent ( _                             ' VTable offset = 12
     BYVAL ulEventID AS DWORD _                         ' __in ULONG ulEventID
   , BYVAL ulEventResult AS DWORD _                     ' __in ULONG ulEventResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_EventingService_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_AUX interface
' IID = 7DEf4C09-6E66-4567-A819-F0E17F4A81AB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_AUX_INTERFACE_DEFINED)
    %IBDA_AUX_INTERFACE_DEFINED = 1

$IID_IBDA_AUX = GUID$("{7DEf4C09-6E66-4567-A819-F0E17F4A81AB}")
$SID_IBDA_AUX = GUID$("{7DEf4C09-6E66-4567-A819-F0E17F4A81AB}")

INTERFACE IBDA_AUX $IID_IBDA_AUX

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryCapabilities ( _                         ' VTable offset = 12
     BYREF pdwNumAuxInputsBSTR AS DWORD _               ' __out DWORD *pdwNumAuxInputsBSTR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCapability ( _                            ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF dwInputID AS DWORD _                         ' __out DWORD *dwInputID
   , BYREF pConnectorType AS GUID _                     ' __out GUID *pConnectorType
   , BYREF ConnTypeNum AS DWORD _                       ' __out DWORD *ConnTypeNum
   , BYREF NumVideoStds AS DWORD _                      ' __out DWORD *NumVideoStds
   , BYREF AnalogStds AS QUAD _                         ' __out ULONGLONG *AnalogStds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_AUX_INTERFACE_DEFINED__ */

$PBDA_AUX_CONNECTOR_TYPE_SVideo = GUID$("{a0e905f4-24c9-4a54-b761-213355efc13A}")
$PBDA_AUX_CONNECTOR_TYPE_Composite = GUID$("{f6298b4c-c725-4d42-849b-410bbb14ea62}")
$CLSID_PBDA_AUX_DATA_TYPE = GUID$("{fd456373-3323-4090-adca-8ed45f55cf10}")

' ########################################################################################
' IBDA_Encoder interface
' IID = 3A8BAD59-59FE-4559-A0BA-396CFAA98AE3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_Encoder_INTERFACE_DEFINED)
    %IBDA_Encoder_INTERFACE_DEFINED = 1

$IID_IBDA_Encoder = GUID$("{3A8BAD59-59FE-4559-A0BA-396CFAA98AE3}")
$SID_IBDA_Encoder = GUID$("{3A8BAD59-59FE-4559-A0BA-396CFAA98AE3}")

INTERFACE IBDA_Encoder $IID_IBDA_Encoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryCapabilities ( _                         ' VTable offset = 12
     BYREF NumAudioFmts AS DWORD _                      ' __out DWORD *NumAudioFmts
   , BYREF NumVideoFmts AS DWORD _                      ' __out DWORD *NumVideoFmts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAudioCapability ( _                       ' VTable offset = 16
     BYVAL FmtIndex AS DWORD _                          ' __in DWORD FmtIndex
   , BYREF MethodID AS DWORD _                          ' __out DWORD *MethodID
   , BYREF AlgorithmType AS DWORD _                     ' __out DWORD *AlgorithmType
   , BYREF SamplingRate AS DWORD _                      ' __out DWORD *SamplingRate
   , BYREF BitDepth AS DWORD _                          ' __out DWORD *BitDepth
   , BYREF NumChannels AS DWORD _                       ' __out DWORD *NumChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumVideoCapability ( _                       ' VTable offset = 20
     BYVAL FmtIndex AS DWORD _                          ' __in DWORD FmtIndex
   , BYREF MethodID AS DWORD _                          ' __out DWORD *MethodID
   , BYREF AlgorithmType AS DWORD _                     ' __out DWORD *AlgorithmType
   , BYREF VerticalSize AS DWORD _                      ' __out DWORD *VerticalSize
   , BYREF HorizontalSize AS DWORD _                    ' __out DWORD *HorizontalSize
   , BYREF AspectRatio AS DWORD _                       ' __out DWORD *AspectRatio
   , BYREF FrameRateCode AS DWORD _                     ' __out DWORD *FrameRateCode
   , BYREF ProgressiveSequence AS DWORD _               ' __out DWORD *ProgressiveSequence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameters ( _                             ' VTable offset = 24
     BYVAL AudioBitrateMode AS DWORD _                  ' __in DWORD AudioBitrateMode
   , BYVAL AudioBitrate AS DWORD _                      ' __in DWORD AudioBitrate
   , BYVAL AudioMethodID AS DWORD _                     ' __in DWORD AudioMethodID
   , BYVAL AudioProgram AS DWORD _                      ' __in DWORD AudioProgram
   , BYVAL VideoBitrateMode AS DWORD _                  ' __in DWORD VideoBitrateMode
   , BYVAL VideoBitrate AS DWORD _                      ' __in DWORD VideoBitrate
   , BYVAL VideoMethodID AS DWORD _                     ' __in DWORD VideoMethodID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 28
     BYREF AudioBitrateMax AS DWORD _                   ' __out DWORD *AudioBitrateMax
   , BYREF AudioBitrateMin AS DWORD _                   ' __out DWORD *AudioBitrateMin
   , BYREF AudioBitrateMode AS DWORD _                  ' __out DWORD *AudioBitrateMode
   , BYREF AudioBitrateStepping AS DWORD _              ' __out DWORD *AudioBitrateStepping
   , BYREF AudioBitrate AS DWORD _                      ' __out DWORD *AudioBitrate
   , BYREF AudioMethodID AS DWORD _                     ' __out DWORD *AudioMethodID
   , BYREF AvailableAudioPrograms AS DWORD _            ' __out DWORD *AvailableAudioPrograms
   , BYREF AudioProgram AS DWORD _                      ' __out DWORD *AudioProgram
   , BYREF VideoBitrateMax AS DWORD _                   ' __out DWORD *VideoBitrateMax
   , BYREF VideoBitrateMin AS DWORD _                   ' __out DWORD *VideoBitrateMin
   , BYREF VideoBitrateMode AS DWORD _                  ' __out DWORD *VideoBitrateMode
   , BYREF VideoBitrate AS DWORD _                      ' __out DWORD *VideoBitrate
   , BYREF VideoBitrateStepping AS DWORD _              ' __out DWORD *VideoBitrateStepping
   , BYREF VideoMethodID AS DWORD _                     ' __out DWORD *VideoMethodID
   , BYREF SignalSourceID AS DWORD _                    ' __out DWORD *SignalSourceID
   , BYREF SignalFormat AS QUAD _                       ' __out ULONGLONG *SignalFormat
   , BYREF SignalLock AS LONG _                         ' __out BOOL *SignalLock
   , BYREF SignalLevel AS LONG _                        ' __out LONG *SignalLevel
   , BYREF SignalToNoiseRatio AS DWORD _                ' __out DWORD *SignalToNoiseRatio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_Encoder_INTERFACE_DEFINED__ */

$CLSID_PBDA_Encoder_DATA_TYPE = GUID$("{728fd6bc-5546-4716-b103-f899f5a1fa68}")

%PBDA_Encoder_Audio_AlgorithmType_MPEG1LayerII    = &H00000000???
%PBDA_Encoder_Audio_AlgorithmType_AC3             = &H00000001???
%PBDA_Encoder_Video_MPEG2PartII                   = &H00000000???
%PBDA_Encoder_Video_MPEG4Part10                   = &H00000001???
%PBDA_Encoder_Video_AVC                           = &H00000001???
%PBDA_Encoder_Video_H264                          = &H00000001???
%PBDA_Encoder_BitrateMode_Constant                = &H00000001???
%PBDA_Encoder_BitrateMode_Variable                = &H00000002???
%PBDA_Encoder_BitrateMode_Average                 = &H00000003???

' ########################################################################################
' IBDA_FDC interface
' IID = 138ADC7E-58AE-437F-B0B4-C9FE19D5B4AC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_FDC_INTERFACE_DEFINED)
    %IBDA_FDC_INTERFACE_DEFINED = 1

$IID_IBDA_FDC = GUID$("{138ADC7E-58AE-437F-B0B4-C9FE19D5B4AC}")
$SID_IBDA_FDC = GUID$("{138ADC7E-58AE-437F-B0B4-C9FE19D5B4AC}")

INTERFACE IBDA_FDC $IID_IBDA_FDC

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF CurrentBitrate AS DWORD _                    ' __out DWORD *CurrentBitrate
   , BYREF CarrierLock AS LONG _                        ' __out BOOL *CarrierLock
   , BYREF CurrentFrequency AS DWORD _                  ' __out DWORD *CurrentFrequency
   , BYREF CurrentSpectrumInversion AS LONG _           ' __out BOOL *CurrentSpectrumInversion
   , BYREF CurrentPIDList AS WSTRING _                  ' __out BSTR *CurrentPIDList
   , BYREF CurrentTIDList AS WSTRING _                  ' __out BSTR *CurrentTIDList
   , BYREF Overflow AS LONG _                           ' __out BOOL *Overflow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestTables ( _                             ' VTable offset = 16
     BYVAL TableIDs AS WSTRING _                        ' __in BSTR TableIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPid ( _                                    ' VTable offset = 20
     BYVAL PidsToAdd AS WSTRING _                       ' __in BSTR PidsToAdd
   , BYREF RemainingFilterEntries AS DWORD _            ' __out DWORD *RemainingFilterEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTid ( _                                    ' VTable offset = 24
     BYVAL TidsToAdd AS WSTRING _                       ' __in BSTR TidsToAdd
   , BYREF CurrentTidList AS WSTRING _                  ' __out BSTR *CurrentTidList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
  METHOD RemoveTid ( _                                  ' VTable offset = 28
     BYVAL TidsToRemove AS WSTRING _                    ' __in BSTR TidsToRemove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
  METHOD GetTableSection ( _                            ' VTable offset = 32
     BYREF Pid AS DWORD _                               ' __out DWORD *Pid
   , BYVAL MaxBufferSize AS DWORD _                     ' __in DWORD MaxBufferSize
   , BYREF ActualSize AS DWORD _                        ' __out DWORD *ActualSize
   , BYVAL SecBuffer AS BYTE PTR _                      ' __out BYTE *SecBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_FDC_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_GuideDataDeliveryService interface
' IID = C0AFCB73-23E7-4BC6-BAFA-FDC167B4719F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_GuideDataDeliveryService_INTERFACE_DEFINED)
    %IBDA_GuideDataDeliveryService_INTERFACE_DEFINED = 1

$IID_IBDA_GuideDataDeliveryService = GUID$("{C0AFCB73-23E7-4BC6-BAFA-FDC167B4719F}")
$SID_IBDA_GuideDataDeliveryService = GUID$("{C0AFCB73-23E7-4BC6-BAFA-FDC167B4719F}")

INTERFACE IBDA_GuideDataDeliveryService $IID_IBDA_GuideDataDeliveryService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGuideDataType ( _                          ' VTable offset = 12
     BYREF pguidDataType AS GUID _                      ' __out GUID *pguidDataType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuideData ( _                              ' VTable offset = 16
     BYREF pulcbBufferLen AS DWORD _                    ' __inout ULONG *pulcbBufferLen
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   , BYREF pulGuideDataPercentageProgress AS DWORD _    ' __out ULONG *pulGuideDataPercentageProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestGuideDataUpdate ( _                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTuneXmlFromServiceIdx ( _                  ' VTable offset = 24
     BYVAL ul64ServiceIdx AS QUAD _                     ' __in ULONG64 ul64ServiceIdx
   , BYREF pbstrTuneXml AS WSTRING _                    ' __out BSTR *pbstrTuneXml
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServices ( _                               ' VTable offset = 28
     BYREF pulcbBufferLen AS DWORD _                    ' __inout ULONG *pulcbBufferLen
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceInfoFromTuneXml ( _                 ' VTable offset = 32
     BYVAL bstrTuneXml AS WSTRING _                     ' __in BSTR bstrTuneXml
   , BYREF pbstrServiceDescription AS WSTRING _         ' __out BSTR *pbstrServiceDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_GuideDataDeliveryService_INTERFACE_DEFINED__ */

$CLSID_PBDA_GDDS_DATA_TYPE = GUID$("{C80C0DF3-6052-4c16-9F56-C44C21F73C45}")

' ########################################################################################
' IBDA_DRMService interface
' IID = BFF6B5BB-B0AE-484C-9DCA-73528FB0B46E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DRMService_INTERFACE_DEFINED)
    %IBDA_DRMService_INTERFACE_DEFINED = 1

$IID_IBDA_DRMService = GUID$("{BFF6B5BB-B0AE-484C-9DCA-73528FB0B46E}")
$SID_IBDA_DRMService = GUID$("{BFF6B5BB-B0AE-484C-9DCA-73528FB0B46E}")

INTERFACE IBDA_DRMService $IID_IBDA_DRMService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDRM ( _                                    ' VTable offset = 12
     BYREF puuidNewDrm AS GUID _                        ' __in GUID *puuidNewDrm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDRMStatus ( _                              ' VTable offset = 16
     BYREF pbstrDrmUuidList AS WSTRING _                ' __out BSTR *pbstrDrmUuidList
   , BYREF DrmUuid AS GUID _                            ' __out GUID *DrmUuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DRMService_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_WMDRMSession interface
' IID = 4BE6FA3D-07CD-4139-8B80-8C18BA3AEC88
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_WMDRMSession_INTERFACE_DEFINED)
    %IBDA_WMDRMSession_INTERFACE_DEFINED = 1

$IID_IBDA_WMDRMSession = GUID$("{4BE6FA3D-07CD-4139-8B80-8C18BA3AEC88}")
$SID_IBDA_WMDRMSession = GUID$("{4BE6FA3D-07CD-4139-8B80-8C18BA3AEC88}")

INTERFACE IBDA_WMDRMSession $IID_IBDA_WMDRMSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF MaxCaptureToken AS DWORD _                   ' __out ULONG *MaxCaptureToken
   , BYREF MaxStreamingPid AS DWORD _                   ' __out ULONG *MaxStreamingPid
   , BYREF MaxLicense AS DWORD _                        ' __out ULONG *MaxLicense
   , BYREF MinSecurityLevel AS DWORD _                  ' __out ULONG *MinSecurityLevel
   , BYREF RevInfoSequenceNumber AS DWORD _             ' __out ULONG *RevInfoSequenceNumber
   , BYREF RevInfoIssuedTime AS QUAD _                  ' __out ULONGLONG *RevInfoIssuedTime
   , BYREF RevInfoTTL AS DWORD _                        ' __out ULONG *RevInfoTTL
   , BYREF RevListVersion AS DWORD _                    ' __out ULONG *RevListVersion
   , BYREF ulState AS DWORD _                           ' __out ULONG *ulState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRevInfo ( _                                ' VTable offset = 16
     BYVAL ulRevInfoLen AS DWORD _                      ' __in ULONG ulRevInfoLen
   , BYVAL pbRevInfo AS BYTE PTR _                      ' __in BYTE *pbRevInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCrl ( _                                    ' VTable offset = 20
     BYVAL ulCrlLen AS DWORD _                          ' __in ULONG ulCrlLen
   , BYVAL pbCrlLen AS BYTE PTR _                       ' __in BYTE *pbCrlLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransactMessage ( _                           ' VTable offset = 24
     BYVAL ulcbRequest AS DWORD _                       ' __in ULONG ulcbRequest
   , BYVAL pbRequest AS BYTE PTR _                      ' __in BYTE *pbRequest
   , BYREF pulcbResponse AS DWORD _                     ' __inout ULONG *pulcbResponse
   , BYVAL pbResponse AS BYTE PTR _                     ' __inout BYTE *pbResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLicense ( _                                ' VTable offset = 28
     BYREF uuidKey AS GUID _                            ' __in GUID *uuidKey
   , BYREF pulPackageLen AS DWORD _                     ' __inout ULONG *pulPackageLen
   , BYVAL pbPackage AS BYTE PTR _                      ' __inout BYTE *pbPackage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReissueLicense ( _                            ' VTable offset = 32
     BYREF uuidKey AS GUID _                            ' __in GUID *uuidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenewLicense ( _                              ' VTable offset = 36
     BYVAL ulInXmrLicenseLen AS DWORD _                 ' __in ULONG ulInXmrLicenseLen
   , BYVAL pbInXmrLicense AS BYTE PTR _                 ' __in BYTE *pbInXmrLicense
   , BYVAL ulEntitlementTokenLen AS DWORD _             ' __in ULONG ulEntitlementTokenLen
   , BYVAL pbEntitlementToken AS BYTE PTR _             ' __in BYTE *pbEntitlementToken
   , BYREF pulDescrambleStatus AS DWORD _               ' __out ULONG *pulDescrambleStatus
   , BYREF pulOutXmrLicenseLen AS DWORD _               ' __inout ULONG *pulOutXmrLicenseLen
   , BYVAL pbOutXmrLicense AS BYTE PTR _                ' __inout BYTE *pbOutXmrLicense
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyInfo ( _                                ' VTable offset = 40
     BYREF pulKeyInfoLen AS DWORD _                     ' __inout ULONG *pulKeyInfoLen
   , BYVAL pbKeyInfo AS BYTE PTR _                      ' __inout BYTE *pbKeyInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_WMDRMSession_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_WMDRMTuner interface
' IID = 4BE6FA3D-07CD-4139-8B80-8C18BA3AEC88
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_WMDRMTuner_INTERFACE_DEFINED)
    %IBDA_WMDRMTuner_INTERFACE_DEFINED = 1

$IID_IBDA_WMDRMTuner = GUID$("{4BE6FA3D-07CD-4139-8B80-8C18BA3AEC88}")
$SID_IBDA_WMDRMTuner = GUID$("{4BE6FA3D-07CD-4139-8B80-8C18BA3AEC88}")

INTERFACE IBDA_WMDRMTuner $IID_IBDA_WMDRMTuner

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PurchaseEntitlement ( _                       ' VTable offset = 12
     BYVAL ulDialogRequest AS DWORD _                   ' __in ULONG ulDialogRequest
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL ulPurchaseTokenLen AS DWORD _                ' __in ULONG ulPurchaseTokenLen
   , BYVAL pbPurchaseToken AS BYTE PTR _                ' __in BYTE *pbPurchaseToken
   , BYREF pulDescrambleStatus AS DWORD _               ' __out ULONG *pulDescrambleStatus
   , BYREF pulCaptureTokenLen AS DWORD _                ' __inout ULONG *pulCaptureTokenLen
   , BYVAL pbCaptureToken AS BYTE PTR _                 ' __inout BYTE *pbCaptureToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelCaptureToken ( _                        ' VTable offset = 16
     BYVAL ulCaptureTokenLen AS DWORD _                 ' __in ULONG ulCaptureTokenLen
   , BYVAL pbCaptureToken AS BYTE PTR _                 ' __in BYTE *pbCaptureToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPidProtection ( _                          ' VTable offset = 20
     BYVAL ulPid AS DWORD _                             ' __in ULONG ulPid
   , BYREF uuidKey AS GUID _                            ' __in GUID *uuidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPidProtection ( _                          ' VTable offset = 24
     BYVAL ulPid AS DWORD _                             ' __in ULONG ulPid
   , BYREF uuidKey AS GUID _                            ' __out GUID *uuidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncValue ( _                              ' VTable offset = 28
     BYVAL ulSyncValue AS DWORD _                       ' __in ULONG ulSyncValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartCodeProfile ( _                       ' VTable offset = 32
     BYREF pulStartCodeProfileLen AS DWORD _            ' __inout ULONG *pulStartCodeProfileLen
   , BYVAL pbStartCodeProfile AS BYTE PTR _             ' __inout BYTE *pbStartCodeProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_WMDRMTuner_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_DRIDRMService interface
' IID = 1F9BC2A5-44A3-4C52-AAB1-0BBCE5A1381D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DRIDRMService_INTERFACE_DEFINED)
    %IBDA_DRIDRMService_INTERFACE_DEFINED = 1

$IID_IBDA_DRIDRMService = GUID$("{1F9BC2A5-44A3-4C52-AAB1-0BBCE5A1381D}")
$SID_IBDA_DRIDRMService = GUID$("{1F9BC2A5-44A3-4C52-AAB1-0BBCE5A1381D}")

INTERFACE IBDA_DRIDRMService $IID_IBDA_DRIDRMService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDRM ( _                                    ' VTable offset = 12
     BYVAL bstrNewDrm AS WSTRING _                      ' __in BSTR bstrNewDrm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDRMStatus ( _                              ' VTable offset = 16
     BYREF pbstrDrmUuidList AS WSTRING _                ' __out  BSTR *pbstrDrmUuidList
   , BYREF DrmUuid AS GUID _                            ' __out GUID *DrmUuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPairingStatus ( _                          ' VTable offset = 20
     BYVAL BDA_DrmPairingError AS BDA_DRMPAIRINGERROR_ENUM _ ' __inout BDA_DrmPairingError *penumPairingStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DRIDRMService_INTERFACE_DEFINED__ */

' ########################################################################################
' IBDA_DRIWMDRMSession interface
' IID = 05C690F8-56DB-4BB2-B053-79C12098BB26
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_DRIWMDRMSession_INTERFACE_DEFINED)
    %IBDA_DRIWMDRMSession_INTERFACE_DEFINED = 1

$IID_IBDA_DRIWMDRMSession = GUID$("{05C690F8-56DB-4BB2-B053-79C12098BB26}")
$SID_IBDA_DRIWMDRMSession = GUID$("{05C690F8-56DB-4BB2-B053-79C12098BB26}")

INTERFACE IBDA_DRIWMDRMSession $IID_IBDA_DRIWMDRMSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AcknowledgeLicense ( _                        ' VTable offset = 12
     BYVAL hrLicenseAck AS LONG _                       ' __in HRESULT hrLicenseAck
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessLicenseChallenge ( _                   ' VTable offset = 16
     BYVAL dwcbLicenseMessage AS DWORD _                ' __in DWORD dwcbLicenseMessage
   , BYVAL pbLicenseMessage AS BYTE PTR _               ' __in BYTE *pbLicenseMessage
   , BYREF pdwcbLicenseResponse AS DWORD _              ' __inout DWORD *pdwcbLicenseResponse
   , BYVAL ppbLicenseResponse AS BYTE PTR _             ' __inout BYTE **ppbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessRegistrationChallenge ( _              ' VTable offset = 20
     BYVAL dwcbRegistrationMessage AS DWORD _           ' __in DWORD dwcbRegistrationMessage
   , BYVAL pbRegistrationMessage AS BYTE PTR _          ' __in BYTE *pbRegistrationMessage
   , BYREF pdwcbRegistrationResponse AS DWORD _         ' __inout DWORD *pdwcbRegistrationResponse
   , BYVAL ppbRegistrationResponse AS BYTE PTR _        ' __inout_opt BYTE **ppbRegistrationResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRevInfo ( _                                ' VTable offset = 24
     BYVAL dwRevInfoLen AS DWORD _                      ' __in DWORD dwRevInfoLen
   , BYVAL pbRevInfo AS BYTE PTR _                      ' __in BYTE *pbRevInfo
   , BYREF pdwResponse AS DWORD _                       ' __inout DWORD *pdwResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCrl ( _                                    ' VTable offset = 28
     BYVAL dwCrlLen AS DWORD _                          ' __in DWORD dwCrlLen
   , BYVAL pbCrlLen AS BYTE PTR _                       ' __in BYTE *pbCrlLen
   , BYREF pdwResponse AS DWORD _                       ' __inout DWORD *pdwResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHMSAssociationData ( _                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastCardeaError ( _                        ' VTable offset = 36
     BYREF pdwError AS DWORD _                          ' __inout DWORD *pdwError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_DRIWMDRMSession_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_MUX interface
' IID = 942AAFEC-4C05-4C74-B8EB-8706C2A4943F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_MUX_INTERFACE_DEFINED)
    %IBDA_MUX_INTERFACE_DEFINED = 1

$IID_IBDA_MUX = GUID$("{942AAFEC-4C05-4C74-B8EB-8706C2A4943F}")
$SID_IBDA_MUX = GUID$("{942AAFEC-4C05-4C74-B8EB-8706C2A4943F}")

INTERFACE IBDA_MUX $IID_IBDA_MUX

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPidList ( _                                ' VTable offset = 12
     BYVAL ulPidListCount AS DWORD _                    ' __in ULONG ulPidListCount
   , BYREF pbPidListBuffer AS BDA_MUX_PIDLISTITEM _     ' __in BDA_MUX_PIDLISTITEM *pbPidListBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPidList ( _                                ' VTable offset = 16
     BYREF pulPidListCount AS DWORD _                   ' __inout ULONG *pulPidListCount
   , BYVAL pbPidListBuffer AS BDA_MUX_PIDLISTITEM _     ' __inout BDA_MUX_PIDLISTITEM *pbPidListBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_MUX_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_TransportStreamSelector interface
' IID = 1DCFAFE9-B45E-41B3-BB2A-561EB129AE98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_TransportStreamSelector_INTERFACE_DEFINED)
    %IBDA_TransportStreamSelector_INTERFACE_DEFINED = 1

$IID_IBDA_TransportStreamSelector = GUID$("{1DCFAFE9-B45E-41B3-BB2A-561EB129AE98}")
$SID_IBDA_TransportStreamSelector = GUID$("{1DCFAFE9-B45E-41B3-BB2A-561EB129AE98}")

INTERFACE IBDA_TransportStreamSelector $IID_IBDA_TransportStreamSelector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTSID ( _                                   ' VTable offset = 12
     BYVAL usTSID AS WORD _                             ' __in USHORT usTSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSInformation ( _                          ' VTable offset = 16
     BYREF pulTSInformationBufferLen AS DWORD _         ' __inout ULONG *pulTSInformationBufferLen
   , BYVAL pbTSInformationBuffer AS BYTE PTR _          ' __out BYTE *pbTSInformationBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_TransportStreamSelector_INTERFACE_DEFINED__ */


' ########################################################################################
' IBDA_UserActivityService interface
' IID = 1DCFAFE9-B45E-41B3-BB2A-561EB129AE98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_UserActivityService_INTERFACE_DEFINED)
    %IBDA_UserActivityService_INTERFACE_DEFINED = 1

$IID_IBDA_UserActivityService = GUID$("{1DCFAFE9-B45E-41B3-BB2A-561EB129AE98}")
$SID_IBDA_UserActivityService = GUID$("{1DCFAFE9-B45E-41B3-BB2A-561EB129AE98}")

INTERFACE IBDA_UserActivityService $IID_IBDA_UserActivityService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCurrentTunerUseReason ( _                  ' VTable offset = 12
     BYVAL dwUseReason AS DWORD _                       ' __in DWORD dwUseReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserActivityInterval ( _                   ' VTable offset = 16
     BYREF pdwActivityInterval AS DWORD _               ' __out DWORD *pdwActivityInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UserActivityDetected ( _                      ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_UserActivityService_INTERFACE_DEFINED__ */
