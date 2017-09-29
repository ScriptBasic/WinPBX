' ########################################################################################
' Microsoft Windows
' File: bthdef.inc
' Contents: Bluetooth common structures and definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BTHDEF_INC = 1

'//
'// Bluetooth 2.1 support added in KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

'  #define BTH_MAJORVERSION 2
'  #define BTH_MINORVERSION 1

'#elif(NTDDI_VERSION >= NTDDI_WINXPSP2)

'  #define BTH_MAJORVERSION 2
'  #define BTH_MINORVERSION 0

'#endif // >= SP1+KB942567

#IF NOT %DEF(%GUID_DEFS_ONLY)
  #IF NOT %DEF(%NO_BTHSDPDEF_INC)
    #INCLUDE ONCE "bthsdpdef.inc"
  #ENDIF ' // NO_BTHSDPDEF_INC
#ENDIF ' // GUID_DEFS_ONLY

'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning(disable:4201) // nameless struct/union


'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)

#IF NOT %DEF(%NO_GUID_DEFS)

$GUID_BTHPORT_DEVICE_INTERFACE     = GUID$("{0850302A-B344-4fda-9BE9-90576B8D46F0}")
$GUID_BLUETOOTH_RADIO_IN_RANGE     = GUID$("{EA3B5B82-26EE-450E-B0D8-D26FE30A3869}")
$GUID_BLUETOOTH_RADIO_OUT_OF_RANGE = GUID$("{E28867C9-C2AA-4CED-B969-4570866037C4}")
'$GUID_BLUETOOTH_PIN_REQUEST        = GUID$("{BD198B7C-24AB-4B9A-8C0D-A8EA8349AA16}")   ' // Removed in Windows 7 SDK
$GUID_BLUETOOTH_L2CAP_EVENT        = GUID$("{7EAE4030-B709-4AA8-AC55-E953829C9DAA}")
$GUID_BLUETOOTH_HCI_EVENT          = GUID$("{FC240062-1541-49BE-B463-84C4DCD7BF7F}")

'//
'// Support added in KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))
$GUID_BLUETOOTH_AUTHENTICATION_REQUEST = GUID$("{5DC9136D-996C-46DB-84F5-32C0A3F47352}")
$GUID_BLUETOOTH_KEYPRESS_EVENT = GUID$("{D668DFCD-0F4E-4EFC-BFE0-392EEEC5109C}")
$GUID_BLUETOOTH_HCI_VENDOR_EVENT = GUID$("{547247E6-45BB-4C33-AF8C-C00EFE15A71D}")
'#endif // >= SP1+KB942567

'//
'// Bluetooth base UUID for service discovery
'//

$Bluetooth_Base_UUID               = GUID$("{00000000-0000-1000-8000-00805F9B34FB}")

'//
'// UUID for the root of the browse group list
'//

$SDP_PROTOCOL_UUID                 = GUID$("{00000001-0000-1000-8000-00805F9B34FB}")
$UDP_PROTOCOL_UUID                 = GUID$("{00000002-0000-1000-8000-00805F9B34FB}")
$RFCOMM_PROTOCOL_UUID              = GUID$("{00000003-0000-1000-8000-00805F9B34FB}")
$TCP_PROTOCOL_UUID                 = GUID$("{00000004-0000-1000-8000-00805F9B34FB}")
$TCSBIN_PROTOCOL_UUID              = GUID$("{00000005-0000-1000-8000-00805F9B34FB}")
$TCSAT_PROTOCOL_UUID               = GUID$("{00000006-0000-1000-8000-00805F9B34FB}")
$OBEX_PROTOCOL_UUID                = GUID$("{00000008-0000-1000-8000-00805F9B34FB}")
$IP_PROTOCOL_UUID                  = GUID$("{00000009-0000-1000-8000-00805F9B34FB}")
$FTP_PROTOCOL_UUID                 = GUID$("{0000000A-0000-1000-8000-00805F9B34FB}")
$HTTP_PROTOCOL_UUID                = GUID$("{0000000C-0000-1000-8000-00805F9B34FB}")
$WSP_PROTOCOL_UUID                 = GUID$("{0000000E-0000-1000-8000-00805F9B34FB}")
$UPNP_PROTOCOL_UUID                = GUID$("{00000010-0000-1000-8000-00805F9B34FB}")
$HID_PROTOCOL_UUID                 = GUID$("{00000011-0000-1000-8000-00805F9B34FB}")
$HCCC_PROTOCOL_UUID                = GUID$("{00000012-0000-1000-8000-00805F9B34FB}")
$HCDC_PROTOCOL_UUID                = GUID$("{00000014-0000-1000-8000-00805F9B34FB}")
$HN_PROTOCOL_UUID                  = GUID$("{00000016-0000-1000-8000-00805F9B34FB}")
$AVCTP_PROTOCOL_UUID               = GUID$("{00000017-0000-1000-8000-00805F9B34FB}")
$AVDTP_PROTOCOL_UUID               = GUID$("{00000019-0000-1000-8000-00805F9B34FB}")
$CMPT_PROTOCOL_UUID                = GUID$("{0000001B-0000-1000-8000-00805F9B34FB}")
$UDI_C_PLANE_PROTOCOL_UUID         = GUID$("{0000001D-0000-1000-8000-00805F9B34FB}")
$L2CAP_PROTOCOL_UUID               = GUID$("{00000100-0000-1000-8000-00805F9B34FB}")

%SDP_PROTOCOL_UUID16                 = &H0001??
%UDP_PROTOCOL_UUID16                 = &H0002??
%RFCOMM_PROTOCOL_UUID16              = &H0003??
%TCP_PROTOCOL_UUID16                 = &H0004??
%TCSBIN_PROTOCOL_UUID16              = &H0005??
%TCSAT_PROTOCOL_UUID16               = &H0006??
%OBEX_PROTOCOL_UUID16                = &H0008??
%IP_PROTOCOL_UUID16                  = &H0009??
%FTP_PROTOCOL_UUID16                 = &H000A??
%HTTP_PROTOCOL_UUID16                = &H000C??
%WSP_PROTOCOL_UUID16                 = &H000E??
%BNEP_PROTOCOL_UUID16                = &H000F??
%UPNP_PROTOCOL_UUID16                = &H0010??
%HID_PROTOCOL_UUID16                 = &H0011??
%HCCC_PROTOCOL_UUID16                = &H0012??
%HCDC_PROTOCOL_UUID16                = &H0014??
%HCN_PROTOCOL_UUID16                 = &H0016??
%AVCTP_PROTOCOL_UUID16               = &H0017??
%AVDTP_PROTOCOL_UUID16               = &H0019??
%CMPT_PROTOCOL_UUID16                = &H001B??
%UDI_C_PLANE_PROTOCOL_UUID16         = &H001D??
%L2CAP_PROTOCOL_UUID16               = &H0100??

$ServiceDiscoveryServerServiceClassID_UUID       = GUID$("{00001001-0000-1000-8000-00805F9B34FB}")
$PublicBrowseGroupServiceClass_UUID              = GUID$("{00001002-0000-1000-8000-00805F9B34FB}")
$SerialPortServiceClass_UUID                     = GUID$("{00001101-0000-1000-8000-00805F9B34FB}")
$LANAccessUsingPPPServiceClass_UUID              = GUID$("{00001102-0000-1000-8000-00805F9B34FB}")
$DialupNetworkingServiceClass_UUID               = GUID$("{00001103-0000-1000-8000-00805F9B34FB}")
$IrMCSyncServiceClass_UUID                       = GUID$("{00001104-0000-1000-8000-00805F9B34FB}")
$OBEXObjectPushServiceClass_UUID                 = GUID$("{00001105-0000-1000-8000-00805F9B34FB}")
$OBEXFileTransferServiceClass_UUID               = GUID$("{00001106-0000-1000-8000-00805F9B34FB}")
$IrMCSyncCommandServiceClass_UUID                = GUID$("{00001107-0000-1000-8000-00805F9B34FB}")
$HeadsetServiceClass_UUID                        = GUID$("{00001108-0000-1000-8000-00805F9B34FB}")
$CordlessTelephonyServiceClass_UUID              = GUID$("{00001109-0000-1000-8000-00805F9B34FB}")
$AudioSourceServiceClass_UUID                    = GUID$("{0000110A-0000-1000-8000-00805F9B34FB}")
$AudioSinkServiceClass_UUID                      = GUID$("{0000110B-0000-1000-8000-00805F9B34FB}")
$AVRemoteControlTargetServiceClass_UUID          = GUID$("{0000110C-0000-1000-8000-00805F9B34FB}")
$AdvancedAudioDistributionServiceClass_UUID      = GUID$("{0000110D-0000-1000-8000-00805F9B34FB}")
$AVRemoteControlServiceClass_UUID                = GUID$("{0000110E-0000-1000-8000-00805F9B34FB}")
'$VideoConferencingServiceClass_UUID              = GUID$("{0000110F-0000-1000-8000-00805F9B34FB}")   ' // Name changed to AVRemoteControlControllerServiceClass_UUID in Windows 7 SDK
$AVRemoteControlControllerServiceClass_UUID      = GUID$("{0000110F-0000-1000-8000-00805F9B34FB}")
$IntercomServiceClass_UUID                       = GUID$("{00001110-0000-1000-8000-00805F9B34FB}")
$FaxServiceClass_UUID                            = GUID$("{00001111-0000-1000-8000-00805F9B34FB}")
$HeadsetAudioGatewayServiceClass_UUID            = GUID$("{00001112-0000-1000-8000-00805F9B34FB}")
$WAPServiceClass_UUID                            = GUID$("{00001113-0000-1000-8000-00805F9B34FB}")
$WAPClientServiceClass_UUID                      = GUID$("{00001114-0000-1000-8000-00805F9B34FB}")
$PANUServiceClass_UUID                           = GUID$("{00001115-0000-1000-8000-00805F9B34FB}")
$NAPServiceClass_UUID                            = GUID$("{00001116-0000-1000-8000-00805F9B34FB}")
$GNServiceClass_UUID                             = GUID$("{00001117-0000-1000-8000-00805F9B34FB}")
$DirectPrintingServiceClass_UUID                 = GUID$("{00001118-0000-1000-8000-00805F9B34FB}")
$ReferencePrintingServiceClass_UUID              = GUID$("{00001119-0000-1000-8000-00805F9B34FB}")
$ImagingServiceClass_UUID                        = GUID$("{0000111A-0000-1000-8000-00805F9B34FB}")
$ImagingResponderServiceClass_UUID               = GUID$("{0000111B-0000-1000-8000-00805F9B34FB}")
$ImagingAutomaticArchiveServiceClass_UUID        = GUID$("{0000111C-0000-1000-8000-00805F9B34FB}")
$ImagingReferenceObjectsServiceClass_UUID        = GUID$("{0000111D-0000-1000-8000-00805F9B34FB}")
$HandsfreeServiceClass_UUID                      = GUID$("{0000111E-0000-1000-8000-00805F9B34FB}")
$HandsfreeAudioGatewayServiceClass_UUID          = GUID$("{0000111F-0000-1000-8000-00805F9B34FB}")
$DirectPrintingReferenceObjectsServiceClass_UUID = GUID$("{00001120-0000-1000-8000-00805F9B34FB}")
$ReflectedUIServiceClass_UUID                    = GUID$("{00001121-0000-1000-8000-00805F9B34FB}")
$BasicPringingServiceClass_UUID                  = GUID$("{00001122-0000-1000-8000-00805F9B34FB}")
$PrintingStatusServiceClass_UUID                 = GUID$("{00001123-0000-1000-8000-00805F9B34FB}")
$HumanInterfaceDeviceServiceClass_UUID           = GUID$("{00001124-0000-1000-8000-00805F9B34FB}")
$HardcopyCableReplacementServiceClass_UUID       = GUID$("{00001125-0000-1000-8000-00805F9B34FB}")
$HCRPrintServiceClass_UUID                       = GUID$("{00001126-0000-1000-8000-00805F9B34FB}")
$HCRScanServiceClass_UUID                        = GUID$("{00001127-0000-1000-8000-00805F9B34FB}")
$CommonISDNAccessServiceClass_UUID               = GUID$("{00001128-0000-1000-8000-00805F9B34FB}")
$VideoConferencingGWServiceClass_UUID            = GUID$("{00001129-0000-1000-8000-00805F9B34FB}")
$UDIMTServiceClass_UUID                          = GUID$("{0000112A-0000-1000-8000-00805F9B34FB}")
$UDITAServiceClass_UUID                          = GUID$("{0000112B-0000-1000-8000-00805F9B34FB}")
$AudioVideoServiceClass_UUID                     = GUID$("{0000112C-0000-1000-8000-00805F9B34FB}")
$SimAccessServiceClass_UUID                      = GUID$("{0000112D-0000-1000-8000-00805F9B34FB}")
$PhonebookAccessPceServiceClass_UUID             = GUID$("{0000112E-0000-1000-8000-00805F9B34FB}")
$PhonebookAccessPseServiceClass_UUID             = GUID$("{0000112F-0000-1000-8000-00805F9B34FB}")
$PnPInformationServiceClass_UUID                 = GUID$("{00001200-0000-1000-8000-00805F9B34FB}")
$GenericNetworkingServiceClass_UUID              = GUID$("{00001201-0000-1000-8000-00805F9B34FB}")
$GenericFileTransferServiceClass_UUID            = GUID$("{00001202-0000-1000-8000-00805F9B34FB}")
$GenericAudioServiceClass_UUID                   = GUID$("{00001203-0000-1000-8000-00805F9B34FB}")
$GenericTelephonyServiceClass_UUID               = GUID$("{00001204-0000-1000-8000-00805F9B34FB}")
$UPnpServiceClass_UUID                           = GUID$("{00001205-0000-1000-8000-00805F9B34FB}")
$UPnpIpServiceClass_UUID                         = GUID$("{00001206-0000-1000-8000-00805F9B34FB}")
$ESdpUpnpIpPanServiceClass_UUID                  = GUID$("{00001300-0000-1000-8000-00805F9B34FB}")
$ESdpUpnpIpLapServiceClass_UUID                  = GUID$("{00001301-0000-1000-8000-00805F9B34FB}")
$ESdpUpnpL2capServiceClass_UUID                  = GUID$("{00001302-0000-1000-8000-00805F9B34FB}")
$VideoSourceServiceClass_UUID                    = GUID$("{00001303-0000-1000-8000-00805F9B34FB}")
$VideoSinkServiceClass_UUID                      = GUID$("{00001304-0000-1000-8000-00805F9B34FB}")
$VideoDistributionServiceClass_UUID              = GUID$("{00001305-0000-1000-8000-00805F9B34FB}")

%ServiceDiscoveryServerServiceClassID_UUID16         = &H1000??
%BrowseGroupDescriptorServiceClassID_UUID16          = &H1001??
%PublicBrowseGroupServiceClassID_UUID16              = &H1002??
%SerialPortServiceClassID_UUID16                     = &H1101??
%LANAccessUsingPPPServiceClassID_UUID16              = &H1102??
%DialupNetworkingServiceClassID_UUID16               = &H1103??
%IrMCSyncServiceClassID_UUID16                       = &H1104??
%OBEXObjectPushServiceClassID_UUID16                 = &H1105??
%OBEXFileTransferServiceClassID_UUID16               = &H1106??
%IrMcSyncCommandServiceClassID_UUID16                = &H1107??
%HeadsetServiceClassID_UUID16                        = &H1108??
%CordlessServiceClassID_UUID16                       = &H1109??
%AudioSourceServiceClassID_UUID16                    = &H110A??
%AudioSinkSourceServiceClassID_UUID16                = &H110B??
%AVRemoteControlTargetServiceClassID_UUID16          = &H110C??
%AdvancedAudioDistributionServiceClassID_UUID16      = &H110D??
%AVRemoteControlServiceClassID_UUID16                = &H110E??
'%VideoConferencingServiceClassID_UUID16              = &H110F??   ' // Name changed to AVRemoteControlControllerServiceClass_UUID16 in Windows 7 SDK
%AVRemoteControlControllerServiceClass_UUID16        = &H110F??
%IntercomServiceClassID_UUID16                       = &H1110??
%FaxServiceClassID_UUID16                            = &H1111??
%HeadsetAudioGatewayServiceClassID_UUID16            = &H1112??
%WAPServiceClassID_UUID16                            = &H1113??
%WAPClientServiceClassID_UUID16                      = &H1114??
%PANUServiceClassID_UUID16                           = &H1115??
%NAPServiceClassID_UUID16                            = &H1116??
%GNServiceClassID_UUID16                             = &H1117??
%DirectPrintingServiceClassID_UUID16                 = &H1118??
%ReferencePrintingServiceClassID_UUID16              = &H1119??
%ImagingServiceClassID_UUID16                        = &H111A??
%ImagingResponderServiceClassID_UUID16               = &H111B??
%ImagingAutomaticArchiveServiceClassID_UUID16        = &H111C??
%ImagingReferenceObjectsServiceClassID_UUID16        = &H111D??
%HandsfreeServiceClassID_UUID16                      = &H111E??
%HandsfreeAudioGatewayServiceClassID_UUID16          = &H111F??
%DirectPrintingReferenceObjectsServiceClassID_UUID16 = &H1120??
%ReflectsUIServiceClassID_UUID16                     = &H1121??
%BasicPrintingServiceClassID_UUID16                  = &H1122??
%PrintingStatusServiceClassID_UUID16                 = &H1123??
%HumanInterfaceDeviceServiceClassID_UUID16           = &H1124??
%HardcopyCableReplacementServiceClassID_UUID16       = &H1125??
%HCRPrintServiceClassID_UUID16                       = &H1126??
%HCRScanServiceClassID_UUID16                        = &H1127??
%CommonISDNAccessServiceClass_UUID16                 = &H1128??
%VideoConferencingGWServiceClass_UUID16              = &H1129??
%UDIMTServiceClass_UUID16                            = &H112A??
%UDITAServiceClass_UUID16                            = &H112B??
%AudioVideoServiceClass_UUID16                       = &H112C??

%PnPInformationServiceClassID_UUID16                 = &H1200??
%GenericNetworkingServiceClassID_UUID16              = &H1201??
%GenericFileTransferServiceClassID_UUID16            = &H1202??
%GenericAudioServiceClassID_UUID16                   = &H1203??
%GenericTelephonyServiceClassID_UUID16               = &H1204??

'//
'// The SIG renamed the uuid for VideoConferencingServiceClass
'//
$VideoConferencingServiceClass_UUID     = $AVRemoteControlControllerServiceClass_UUID
%VideoConferencingServiceClassID_UUID16 = %AVRemoteControlControllerServiceClass_UUID16

#ENDIF ' //  NO_GUID_DEFS

#IF NOT %DEF(%GUID_DEFS_ONLY)

'//
'// max length of device friendly name.
'//
%BTH_MAX_NAME_SIZE              = 248

%BTH_MAX_PIN_SIZE               = 16
%BTH_LINK_KEY_LENGTH            = 16

%BTH_MFG_ERICSSON               = 0
%BTH_MFG_NOKIA                  = 1
%BTH_MFG_INTEL                  = 2
%BTH_MFG_IBM                    = 3
%BTH_MFG_TOSHIBA                = 4
%BTH_MFG_3COM                   = 5
%BTH_MFG_MICROSOFT              = 6
%BTH_MFG_LUCENT                 = 7
%BTH_MFG_MOTOROLA               = 8
%BTH_MFG_INFINEON               = 9
%BTH_MFG_CSR                    = 10
%BTH_MFG_SILICONWAVE            = 11
%BTH_MFG_DIGIANSWER             = 12
%BTH_MFG_TI                     = 13
%BTH_MFG_PARTHUS                = 14
%BTH_MFG_BROADCOM               = 15
%BTH_MFG_MITEL                  = 16
%BTH_MFG_WIDCOMM                = 17
%BTH_MFG_ZEEVO                  = 18
%BTH_MFG_ATMEL                  = 19
%BTH_MFG_MITSIBUSHI             = 20
%BTH_MFG_RTX_TELECOM            = 21
%BTH_MFG_KC_TECHNOLOGY          = 22
%BTH_MFG_NEWLOGIC               = 23
%BTH_MFG_TRANSILICA             = 24
%BTH_MFG_ROHDE_SCHWARZ          = 25
%BTH_MFG_TTPCOM                 = 26
%BTH_MFG_SIGNIA                 = 27
%BTH_MFG_CONEXANT               = 28
%BTH_MFG_QUALCOMM               = 29
%BTH_MFG_INVENTEL               = 30
%BTH_MFG_AVM_BERLIN             = 31
%BTH_MFG_BANDSPEED              = 32
%BTH_MFG_MANSELLA               = 33
%BTH_MFG_NEC                    = 34
%BTH_MFG_WAVEPLUS_TECHNOLOGY_CO = 35
%BTH_MFG_ALCATEL                = 36
%BTH_MFG_PHILIPS_SEMICONDUCTOR  = 37
%BTH_MFG_C_TECHNOLOGIES         = 38
%BTH_MFG_OPEN_INTERFACE         = 39
%BTH_MFG_RF_MICRO_DEVICES       = 40
%BTH_MFG_HITACHI                = 41
%BTH_MFG_SYMBOL_TECHNOLOGIES    = 42
%BTH_MFG_TENOVIS                = 43
%BTH_MFG_MACRONIX_INTERNATIONAL = 44
%BTH_MFG_INTERNAL_USE           = 65535

'typedef ULONGLONG BTH_ADDR, *PBTH_ADDR;
'typedef ULONG BTH_COD, *PBTH_COD;
'typedef ULONG BTH_LAP, *PBTH_LAP;

%BTH_ADDR_NULL                  = &H0000000000000000&&   ' ULONGLONG

%NAP_MASK                       = &HFFFF00000000&&       ' ULONGLONG
%SAP_MASK                       = &H0000FFFFFFFF&&       ' ULONGLONG

%NAP_BIT_OFFSET                 = 8 * 4
%SAP_BIT_OFFSET                 = 0

'#define GET_NAP(_bth_addr)  ((USHORT) (((_bth_addr) & NAP_MASK) >> NAP_BIT_OFFSET))

FUNCTION GET_NAP (BYVAL bth_addr_ AS QUAD) AS WORD
   LOCAL qtmp AS QUAD
   qtmp = bth_addr_ AND %NAP_MASK
   SHIFT RIGHT qtmp, %NAP_BIT_OFFSET
   FUNCTION = qtmp
END FUNCTION

'#define GET_SAP(_bth_addr)  ((ULONG)  (((_bth_addr) & SAP_MASK) >> SAP_BIT_OFFSET))

FUNCTION GET_SAP (BYVAL bth_addr_ AS QUAD) AS DWORD
   LOCAL qtmp AS QUAD
   qtmp = bth_addr_ AND %SAP_MASK
   SHIFT RIGHT qtmp, %SAP_BIT_OFFSET
   FUNCTION = qtmp
END FUNCTION

'#define SET_NAP(_nap) (((ULONGLONG) ((USHORT) (_nap))) << NAP_BIT_OFFSET)

FUNCTION SET_NAP (BYVAL nap_ AS QUAD) AS QUAD
   SHIFT LEFT nap_, %NAP_BIT_OFFSET
   FUNCTION = nap_
END FUNCTION

'#define SET_SAP(_sap) (((ULONGLONG) ((ULONG)  (_sap))) << SAP_BIT_OFFSET)

FUNCTION SET_SAP (BYVAL sap_ AS QUAD) AS QUAD
   SHIFT LEFT sap_, %SAP_BIT_OFFSET
   FUNCTION = sap_
END FUNCTION

'#define SET_NAP_SAP(_nap, _sap) (SET_NAP(_nap) | SET_SAP(_sap))

FUNCTION SET_NAP_SAP (BYVAL nap_ AS QUAD, BYVAL sap_ AS QUAD) AS QUAD
   FUNCTION = SET_NAP(nap_) OR SET_SAP(sap_)
END FUNCTION

%COD_FORMAT_BIT_OFFSET   = 0
%COD_MINOR_BIT_OFFSET    = 2
%COD_MAJOR_BIT_OFFSET    = 8 * 1
%COD_SERVICE_BIT_OFFSET  = 8 * 1 + 5

%COD_FORMAT_MASK         = &H000003???
%COD_MINOR_MASK          = &H0000FC???
%COD_MAJOR_MASK          = &H001F00???
%COD_SERVICE_MASK        = &HFFE000???

'#define GET_COD_FORMAT(_cod)    ( (_cod) & COD_FORMAT_MASK   >> COD_FORMAT_BIT_OFFSET)

FUNCTION GET_COD_FORMAT (BYVAL cod_ AS DWORD) AS DWORD
   LOCAL dwtmp AS DWORD
   dwtmp = cod_ AND %COD_FORMAT_MASK
   SHIFT RIGHT dwtmp, %COD_FORMAT_BIT_OFFSET
   FUNCTION = dwtmp
END FUNCTION

'#define GET_COD_MINOR(_cod)     (((_cod) & COD_MINOR_MASK)   >> COD_MINOR_BIT_OFFSET)

FUNCTION GET_COD_MINOR (BYVAL cod_ AS DWORD) AS DWORD
   LOCAL dwtmp AS DWORD
   dwtmp = cod_ AND %COD_MINOR_MASK
   SHIFT RIGHT dwtmp, %COD_MINOR_BIT_OFFSET
   FUNCTION = dwtmp
END FUNCTION

'#define GET_COD_MAJOR(_cod)     (((_cod) & COD_MAJOR_MASK)   >> COD_MAJOR_BIT_OFFSET)

FUNCTION GET_COD_MAJOR (BYVAL cod_ AS DWORD) AS DWORD
   LOCAL dwtmp AS DWORD
   dwtmp = cod_ AND %COD_MAJOR_MASK
   SHIFT RIGHT dwtmp, %COD_MAJOR_BIT_OFFSET
   FUNCTION = dwtmp
END FUNCTION

'#define GET_COD_SERVICE(_cod)   (((_cod) & COD_SERVICE_MASK) >> COD_SERVICE_BIT_OFFSET)

FUNCTION GET_COD_SERVICE (BYVAL cod_ AS DWORD) AS DWORD
   LOCAL dwtmp AS DWORD
   dwtmp = cod_ AND %COD_SERVICE_MASK
   SHIFT RIGHT dwtmp, %COD_SERVICE_BIT_OFFSET
   FUNCTION = dwtmp
END FUNCTION

'#define SET_COD_MINOR(_cod, _minor) (_cod) = ((_cod) & ~COD_MINOR_MASK) | ((_minor) << COD_MINOR_BIT_OFFSET)

FUNCTION SET_COD_MINOR (BYVAL cod_ AS DWORD, BYVAL minor_ AS DWORD) AS DWORD
   cod_ = (cod_ AND NOT %COD_MINOR_MASK)
   SHIFT LEFT minor_, %COD_MINOR_BIT_OFFSET
   FUNCTION = cod_ OR minor_
END FUNCTION

'#define SET_COD_MAJOR(_cod, _major) (_cod) = ((_cod) & ~COD_MAJOR_MASK) | ((_major) << COD_MAJOR_BIT_OFFSET)

FUNCTION SET_COD_MAJOR (BYVAL cod_ AS DWORD, BYVAL major_ AS DWORD) AS DWORD
   cod_ = (cod_ AND NOT %COD_MAJOR_MASK)
   SHIFT LEFT major_, %COD_MAJOR_BIT_OFFSET
   FUNCTION = cod_ OR major_
END FUNCTION

'#define SET_COD_SERVICE(_cod, _service) (_cod) = ((_cod) & ~COD_SERVICE_MASK) | ((_service) << COD_SERVICE_BIT_OFFSET)

FUNCTION SET_COD_SERVICE (BYVAL cod_ AS DWORD, BYVAL service_ AS DWORD) AS DWORD
   cod_ = (cod_ AND NOT %COD_SERVICE_MASK)
   SHIFT LEFT service_, %COD_SERVICE_BIT_OFFSET
   FUNCTION = cod_ OR service_
END FUNCTION

%COD_VERSION                         = &H0

%COD_SERVICE_LIMITED                 = &H0001
%COD_SERVICE_POSITIONING             = &H0008
%COD_SERVICE_NETWORKING              = &H0010
%COD_SERVICE_RENDERING               = &H0020
%COD_SERVICE_CAPTURING               = &H0040
%COD_SERVICE_OBJECT_XFER             = &H0080
%COD_SERVICE_AUDIO                   = &H0100
%COD_SERVICE_TELEPHONY               = &H0200
%COD_SERVICE_INFORMATION             = &H0400

%COD_SERVICE_VALID_MASK              = %COD_SERVICE_LIMITED     OR _
                                       %COD_SERVICE_POSITIONING OR _
                                       %COD_SERVICE_NETWORKING  OR _
                                       %COD_SERVICE_RENDERING   OR _
                                       %COD_SERVICE_CAPTURING   OR _
                                       %COD_SERVICE_OBJECT_XFER OR _
                                       %COD_SERVICE_AUDIO       OR _
                                       %COD_SERVICE_TELEPHONY   OR _
                                       %COD_SERVICE_INFORMATION

%OD_SERVICE_MAX_COUNT                = 9

'//
'// Major class codes
'//
%COD_MAJOR_MISCELLANEOUS                    = &H00
%COD_MAJOR_COMPUTER                         = &H01
%COD_MAJOR_PHONE                            = &H02
%COD_MAJOR_LAN_ACCESS                       = &H03
%COD_MAJOR_AUDIO                            = &H04
%COD_MAJOR_PERIPHERAL                       = &H05
%COD_MAJOR_IMAGING                          = &H06
%COD_MAJOR_UNCLASSIFIED                     = &H1F

'//
'// Minor class codes specific to each major class
'//
%COD_COMPUTER_MINOR_UNCLASSIFIED            = &H00
%COD_COMPUTER_MINOR_DESKTOP                 = &H01
%COD_COMPUTER_MINOR_SERVER                  = &H02
%COD_COMPUTER_MINOR_LAPTOP                  = &H03
%COD_COMPUTER_MINOR_HANDHELD                = &H04
%COD_COMPUTER_MINOR_PALM                    = &H05
%COD_COMPUTER_MINOR_WEARABLE                = &H06

%COD_PHONE_MINOR_UNCLASSIFIED               = &H00
%COD_PHONE_MINOR_CELLULAR                   = &H01
%COD_PHONE_MINOR_CORDLESS                   = &H02
%COD_PHONE_MINOR_SMART                      = &H03
%COD_PHONE_MINOR_WIRED_MODEM                = &H04

%COD_AUDIO_MINOR_UNCLASSIFIED               = &H00
%COD_AUDIO_MINOR_HEADSET                    = &H01
%COD_AUDIO_MINOR_HANDS_FREE                 = &H02
%COD_AUDIO_MINOR_HEADSET_HANDS_FREE         = &H03
%COD_AUDIO_MINOR_MICROPHONE                 = &H04
%COD_AUDIO_MINOR_LOUDSPEAKER                = &H05
%COD_AUDIO_MINOR_HEADPHONES                 = &H06
%COD_AUDIO_MINOR_PORTABLE_AUDIO             = &H07
%COD_AUDIO_MINOR_CAR_AUDIO                  = &H08
%COD_AUDIO_MINOR_SET_TOP_BOX                = &H09
%COD_AUDIO_MINOR_HIFI_AUDIO                 = &H0A
%COD_AUDIO_MINOR_VCR                        = &H0B
%COD_AUDIO_MINOR_VIDEO_CAMERA               = &H0C
%COD_AUDIO_MINOR_CAMCORDER                  = &H0D
%COD_AUDIO_MINOR_VIDEO_MONITOR              = &H0E
%COD_AUDIO_MINOR_VIDEO_DISPLAY_LOUDSPEAKER  = &H0F
%COD_AUDIO_MINOR_VIDEO_DISPLAY_CONFERENCING = &H10
'// %COD_AUDIO_MINOR_RESERVED = &H11
%COD_AUDIO_MINOR_GAMING_TOY                 = &H12

%COD_PERIPHERAL_MINOR_KEYBOARD_MASK         = &H10
%COD_PERIPHERAL_MINOR_POINTER_MASK          = &H20

%COD_PERIPHERAL_MINOR_NO_CATEGORY           = &H00
%COD_PERIPHERAL_MINOR_JOYSTICK              = &H01
%COD_PERIPHERAL_MINOR_GAMEPAD               = &H02
%COD_PERIPHERAL_MINOR_REMOTE_CONTROL        = &H03
%COD_PERIPHERAL_MINOR_SENSING               = &H04

%COD_IMAGING_MINOR_DISPLAY_MASK             = &H04
%COD_IMAGING_MINOR_CAMERA_MASK              = &H08
%COD_IMAGING_MINOR_SCANNER_MASK             = &H10
%COD_IMAGING_MINOR_PRINTER_MASK             = &H20

'//
'// Cannot use GET_COD_MINOR for this b/c it is embedded in a different manner
'// than the rest of the major classes
'//

%COD_LAN_ACCESS_BIT_OFFSET = 5???

%COD_LAN_MINOR_MASK        = &H00001C???
%COD_LAN_ACCESS_MASK       = &H0000E0???

'#define GET_COD_LAN_MINOR(_cod)         (((_cod) & COD_LAN_MINOR_MASK) >> COD_MINOR_BIT_OFFSET)

FUNCTION GET_COD_LAN_MINOR (BYVAL cod_ AS DWORD) AS DWORD
   cod_ = (cod_ AND %COD_LAN_MINOR_MASK)
   SHIFT RIGHT cod_, %COD_MINOR_BIT_OFFSET
   FUNCTION = cod_
END FUNCTION

'#define GET_COD_LAN_ACCESS(_cod)         (((_cod) & COD_LAN_ACCESS_MASK) >> COD_LAN_ACCESS_BIT_OFFSET)

FUNCTION GET_COD_LAN_ACCESS (BYVAL cod_ AS DWORD) AS DWORD
   cod_ = (cod_ AND %COD_LAN_ACCESS_MASK)
   SHIFT RIGHT cod_, %COD_LAN_ACCESS_BIT_OFFSET
   FUNCTION = cod_
END FUNCTION

'//
'// LAN access percent usage subcodes
'//
%COD_LAN_MINOR_UNCLASSIFIED    = &H00

%COD_LAN_ACCESS_0_USED         = &H00
%COD_LAN_ACCESS_17_USED        = &H01
%COD_LAN_ACCESS_33_USED        = &H02
%COD_LAN_ACCESS_50_USED        = &H03
%COD_LAN_ACCESS_67_USED        = &H04
%COD_LAN_ACCESS_83_USED        = &H05
%COD_LAN_ACCESS_99_USED        = &H06
%COD_LAN_ACCESS_FULL           = &H07

'//
'// Extended Inquiry Response (EIR) defines.
'//
%BTH_EIR_FLAGS_ID                = &H01
%BTH_EIR_16_UUIDS_PARTIAL_ID     = &H02
%BTH_EIR_16_UUIDS_COMPLETE_ID    = &H03
%BTH_EIR_32_UUIDS_PARTIAL_ID     = &H04
%BTH_EIR_32_UUIDS_COMPLETE_ID    = &H05
%BTH_EIR_128_UUIDS_PARTIAL_ID    = &H06
%BTH_EIR_128_UUIDS_COMPLETE_ID   = &H07
%BTH_EIR_LOCAL_NAME_PARTIAL_ID   = &H08
%BTH_EIR_LOCAL_NAME_COMPLETE_ID  = &H09
%BTH_EIR_TX_POWER_LEVEL_ID       = &H0A
%BTH_EIR_OOB_OPT_DATA_LEN_ID     = &H0B   ' // OOB only.
%BTH_EIR_OOB_BD_ADDR_ID          = &H0C   ' // OOB only.
%BTH_EIR_OOB_COD_ID              = &H0D   ' // OOB only.
%BTH_EIR_OOB_SP_HASH_ID          = &H0E   ' // OOB only.
%BTH_EIR_OOB_SP_RANDOMIZER_ID    = &H0F   ' // OOB only.
%BTH_EIR_MANUFACTURER_ID         = &HFF

'//
'// Extended Inquiry Response (EIR) size.
'//
%BTH_EIR_SIZE                    = 240

'//
'// Used as an initializer of LAP_DATA
'//
MACRO LAP_GIAC_INIT            = &H33, &H8B, &H9E   ' { 0x33, 0x8B, 0x9E }
MACRO LAP_LIAC_INIT            = &H00, &H8B, &H9E   ' { 0x00, 0x8B, 0x9E }

'//
'// General Inquiry Access Code.
'//
%LAP_GIAC_VALUE                = &H009E8B33???

'//
'// Limited Inquiry Access Code.
'//
%LAP_LIAC_VALUE                = &H009E8B00???

%BTH_ADDR_IAC_FIRST            = &H9E8B00???
%BTH_ADDR_IAC_LAST             = &H9E8B3f???
%BTH_ADDR_LIAC                 = &H9E8B00???
%BTH_ADDR_GIAC                 = &H9E8B33???

'typedef UCHAR BTHSTATUS, *PBTHSTATUS;

MACRO BTH_ERROR(btStatus_) = (btStatus_ <> %BTH_ERROR_SUCCESS)
MACRO BTH_SUCCESS(btStatus_) = (btStatus_ = %BTH_ERROR_SUCCESS)

%BTH_ERROR_SUCCESS                                     = &H00?
%BTH_ERROR_UNKNOWN_HCI_COMMAND                         = &H01?
%BTH_ERROR_NO_CONNECTION                               = &H02?
%BTH_ERROR_HARDWARE_FAILURE                            = &H03?
%BTH_ERROR_PAGE_TIMEOUT                                = &H04?
%BTH_ERROR_AUTHENTICATION_FAILURE                      = &H05?
%BTH_ERROR_KEY_MISSING                                 = &H06?
%BTH_ERROR_MEMORY_FULL                                 = &H07?
%BTH_ERROR_CONNECTION_TIMEOUT                          = &H08?
%BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS                   = &H09?
%BTH_ERROR_MAX_NUMBER_OF_SCO_CONNECTIONS               = &H0a?
%BTH_ERROR_ACL_CONNECTION_ALREADY_EXISTS               = &H0b?
%BTH_ERROR_COMMAND_DISALLOWED                          = &H0c?
%BTH_ERROR_HOST_REJECTED_LIMITED_RESOURCES             = &H0d?
%BTH_ERROR_HOST_REJECTED_SECURITY_REASONS              = &H0e?
%BTH_ERROR_HOST_REJECTED_PERSONAL_DEVICE               = &H0f?
%BTH_ERROR_HOST_TIMEOUT                                = &H10?
%BTH_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER            = &H11?
%BTH_ERROR_INVALID_HCI_PARAMETER                       = &H12?
%BTH_ERROR_REMOTE_USER_ENDED_CONNECTION                = &H13?
%BTH_ERROR_REMOTE_LOW_RESOURCES                        = &H14?
%BTH_ERROR_REMOTE_POWERING_OFF                         = &H15?
%BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION            = &H16?
%BTH_ERROR_REPEATED_ATTEMPTS                           = &H17?
%BTH_ERROR_PAIRING_NOT_ALLOWED                         = &H18?
%BTH_ERROR_UKNOWN_LMP_PDU                              = &H19?
%BTH_ERROR_UNSUPPORTED_REMOTE_FEATURE                  = &H1a?
%BTH_ERROR_SCO_OFFSET_REJECTED                         = &H1b?
%BTH_ERROR_SCO_INTERVAL_REJECTED                       = &H1c?
%BTH_ERROR_SCO_AIRMODE_REJECTED                        = &H1d?
%BTH_ERROR_INVALID_LMP_PARAMETERS                      = &H1e?
%BTH_ERROR_UNSPECIFIED_ERROR                           = &H1f?
%BTH_ERROR_UNSUPPORTED_LMP_PARM_VALUE                  = &H20?
%BTH_ERROR_ROLE_CHANGE_NOT_ALLOWED                     = &H21?
%BTH_ERROR_LMP_RESPONSE_TIMEOUT                        = &H22?
%BTH_ERROR_LMP_TRANSACTION_COLLISION                   = &H23?
%BTH_ERROR_LMP_PDU_NOT_ALLOWED                         = &H24?
%BTH_ERROR_ENCRYPTION_MODE_NOT_ACCEPTABLE              = &H25?
%BTH_ERROR_UNIT_KEY_NOT_USED                           = &H26?
%BTH_ERROR_QOS_IS_NOT_SUPPORTED                        = &H27?
%BTH_ERROR_INSTANT_PASSED                              = &H28?
%BTH_ERROR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED         = &H29?
%BTH_ERROR_DIFFERENT_TRANSACTION_COLLISION             = &H2a?
%BTH_ERROR_QOS_UNACCEPTABLE_PARAMETER                  = &H2c?
%BTH_ERROR_QOS_REJECTED                                = &H2d?
%BTH_ERROR_CHANNEL_CLASSIFICATION_NOT_SUPPORTED        = &H2e?
%BTH_ERROR_INSUFFICIENT_SECURITY                       = &H2f?
%BTH_ERROR_PARAMETER_OUT_OF_MANDATORY_RANGE            = &H30?
%BTH_ERROR_ROLE_SWITCH_PENDING                         = &H32?
%BTH_ERROR_RESERVED_SLOT_VIOLATION                     = &H34?
%BTH_ERROR_ROLE_SWITCH_FAILED                          = &H35?
%BTH_ERROR_EXTENDED_INQUIRY_RESPONSE_TOO_LARGE         = &H36?
%BTH_ERROR_SECURE_SIMPLE_PAIRING_NOT_SUPPORTED_BY_HOST = &H37?
%BTH_ERROR_HOST_BUSY_PAIRING                           = &H38?

%BTH_ERROR_UNSPECIFIED                                 = &HFF?

'//
'// Min, max, and default L2cap MTU.
'//
%L2CAP_MIN_MTU                       = 48
%L2CAP_MAX_MTU                       = &HFFFF
%L2CAP_DEFAULT_MTU                   = 672

'//
'// Max l2cap signal size (48 - size of signal header (4))
'//
%MAX_L2CAP_PING_DATA_LENGTH          = 44
%MAX_L2CAP_INFO_DATA_LENGTH          = 44

'//
'// the following structures provide information about
'// discovered remote radios.
'//

%BDIF_ADDRESS            = &H00000001???
%BDIF_COD                = &H00000002???
%BDIF_NAME               = &H00000004???
%BDIF_PAIRED             = &H00000008???
%BDIF_PERSONAL           = &H00000010???
%BDIF_CONNECTED          = &H00000020???

'//
'// Support added in KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

%BDIF_SHORT_NAME         = &H00000040???
%BDIF_VISIBLE            = &H00000080???
%BDIF_SSP_SUPPORTED      = &H00000100???
%BDIF_SSP_PAIRED         = &H00000200???
%BDIF_SSP_MITM_PROTECTED = &H00000400???
%BDIF_RSSI               = &H00001000???
%BDIF_EIR                = &H00002000???

'#define BDIF_VALID_FLAGS                                                    \
'    (BDIF_ADDRESS | BDIF_COD | BDIF_NAME | BDIF_PAIRED | BDIF_PERSONAL |    \
'     BDIF_CONNECTED | BDIF_SHORT_NAME | BDIF_VISIBLE | BDIF_RSSI | BDIF_EIR | BDIF_SSP_PAIRED | BDIF_SSP_MITM_PROTECTED)

%BDIF_VALID_FLAGS = %BDIF_ADDRESS OR %BDIF_COD OR %BDIF_NAME OR %BDIF_PAIRED OR %BDIF_PERSONAL OR _
                    %BDIF_CONNECTED OR %BDIF_SHORT_NAME OR %BDIF_VISIBLE OR %BDIF_RSSI OR %BDIF_EIR OR %BDIF_SSP_PAIRED OR %BDIF_SSP_MITM_PROTECTED

'#else // <= SP1

'#define BDIF_VALID_FLAGS                                                    \
'    (BDIF_ADDRESS | BDIF_COD | BDIF_NAME | BDIF_PAIRED | BDIF_PERSONAL |    \
'     BDIF_CONNECTED)

'%BDIF_VALID_FLAGS = %BDIF_ADDRESS OR %BDIF_COD OR %BDIF_NAME OR %BDIF_PAIRED OR %BDIF_PERSONAL OR %BDIF_CONNECTED

'#endif // >= SP1+KB942567


'typedef struct _BTH_DEVICE_INFO {
'    //
'    // Combination BDIF_Xxx flags
'    //
'    ULONG flags;

'    //
'    // Address of remote device.
'    //
'    BTH_ADDR address;

'    //
'    // Class Of Device.
'    //
'    BTH_COD classOfDevice;

'    //
'    // name of the device
'    //
'    CHAR name[BTH_MAX_NAME_SIZE];

'} BTH_DEVICE_INFO, *PBTH_DEVICE_INFO;

' // Size = 272 bytes
TYPE BTH_DEVICE_INFO QWORD   ' Must be 8 byte aligned
   flags         AS DWORD                         ' ULONG
   address       AS QUAD                          ' BTH_ADDR
   classOfDevice AS DWORD                         ' BTH_COD
   name          AS ASCIIZ * %BTH_MAX_NAME_SIZE   ' CHAR - UTF8 encoded
END TYPE

'//
'// Buffer associated with GUID_BLUETOOTH_RADIO_IN_RANGE
'//
'typedef struct _BTH_RADIO_IN_RANGE {
'    //
'    // Information about the remote radio
'    //
'    BTH_DEVICE_INFO deviceInfo;

'    //
'    // The previous flags value for the BTH_DEVICE_INFO.  The receiver of this
'    // notification can compare the deviceInfo.flags and previousDeviceFlags
'    // to determine what has changed about this remote radio.
'    //
'    // For instance, if BDIF_NAME is set in deviceInfo.flags and not in
'    // previousDeviceFlags, the remote radio's has just been retrieved.
'    //
'    ULONG previousDeviceFlags;

'} BTH_RADIO_IN_RANGE, *PBTH_RADIO_IN_RANGE;

' // Size = 280 bytes
TYPE BTH_RADIO_IN_RANGE QWORD   ' Must be 8 byte aligned
   deviceInfo          AS BTH_DEVICE_INFO   ' BTH_DEVICE_INFO
   previousDeviceFlags AS DWORD             ' ULONG
END TYPE

'//
'// Buffer associated with GUID_BLUETOOTH_L2CAP_EVENT
'//
'typedef struct _BTH_L2CAP_EVENT_INFO {
'    //
'    // Remote radio address which the L2CAP event is associated with
'    //
'    BTH_ADDR bthAddress;

'    //
'    // The PSM that is either being connected to or disconnected from
'    //
'    USHORT psm;

'    //
'    // If != 0, then the channel has just been established.  If == 0, then the
'    // channel has been destroyed.  Notifications for a destroyed channel will
'    // only be sent for channels successfully established.
'    //
'    UCHAR connected;

'    //
'    // If != 0, then the local host iniated the l2cap connection.  If == 0, then
'    // the remote host initated the connection.  This field is only valid if
'    // connect is != 0.
'    //
'    UCHAR initiated;

'} BTH_L2CAP_EVENT_INFO, *PBTH_L2CAP_EVENT_INFO;

' // Size = 16 bytes
TYPE BTH_L2CAP_EVENT_INFO  ' Must be 8 byte aligned
   bthAddress AS QUAD   ' BTH_ADDR
   psm        AS WORD   ' USHORT
   connected  AS BYTE   ' UCHAR
   initiated  AS BYTE   ' UCHAR
   filler_    AS DWORD  ' // To keep 8 bytes alignment
END TYPE

%HCI_CONNECTION_TYPE_ACL = 1
%HCI_CONNECTION_TYPE_SCO = 2

'//
'// Fix typos
'//

%HCI_CONNNECTION_TYPE_ACL = %HCI_CONNECTION_TYPE_ACL
%HCI_CONNNECTION_TYPE_SCO = %HCI_CONNECTION_TYPE_SCO

'//
'// Buffer associated with GUID_BLUETOOTH_HCI_EVENT
'//
'typedef struct _BTH_HCI_EVENT_INFO {
'    //
''    // Remote radio address which the HCI event is associated with
'    //
'    BTH_ADDR bthAddress;

'    //
'    // HCI_CONNNECTION_TYPE_XXX value
'    //
'    UCHAR connectionType;

'    //
'    // If != 0, then the underlying connection to the remote radio has just
'    // been estrablished.  If == 0, then the underlying conneciton has just been
'    // destroyed.
'    //
'    UCHAR  connected;

'} BTH_HCI_EVENT_INFO, *PBTH_HCI_EVENT_INFO;

' // Size = 16 bytes
TYPE BTH_HCI_EVENT_INFO   ' Must be 8 byte aligned
   bthAddress     AS QUAD   ' BTH_ADDR
   connectionType AS BYTE   ' UCHAR
   connected      AS BYTE   ' UCHAR
   filler_(5)     AS BYTE   ' // To keep 8 bytes alignment
END TYPE

'//
'// Support added in KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

'//
'// Buffer associated with GUID_BLUETOOTH_KEYPRESS_EVENT
'//

' enum BTH_KEYPRESS_NOTIFICATION_TYPE
MACRO BTH_KEYPRESS_NOTIFICATION_TYPE_ENUM = LONG
%BTH_KEYPRESS_NOTIFICATION_PASSKEY_STARTED = &H0
%BTH_KEYPRESS_NOTIFICATION_PASSKEY_DIGIT_ENTERED = &H1
%BTH_KEYPRESS_NOTIFICATION_PASSKEY_DIGIT_ERASED = &H2
%BTH_KEYPRESS_NOTIFICATION_PASSKEY_CLEARED = &H3
%BTH_KEYPRESS_NOTIFICATION_PASSKEY_ENTRY_COMPLETED = &H4

' // Size = 16 bytes
TYPE BTH_HCI_KEYPRESS_INFO QWORD
   BTH_ADDR         AS QUAD   ' BTH_ADDR
   ' // HCI_KEYPRESS_XXX value
   NotificationType AS BYTE   ' UCHAR
END TYPE

' enum _BTH_AUTH_METHOD
MACRO BTH_AUTH_METHOD_ENUM = LONG
%BTH_AUTH_METHOD_UNDEFINED            = &H0
%BTH_AUTH_METHOD_LEGACY               = &H1
%BTH_AUTH_METHOD_OOB                  = &H2
%BTH_AUTH_METHOD_NUMERIC_COMPARISON   = &H3
%BTH_AUTH_METHOD_PASSKEY_NOTIFICATION = &H4
%BTH_AUTH_METHOD_PASSKEY              = &H5

%BTH_AUTH_METHOD_MAX = %BTH_AUTH_METHOD_PASSKEY

' enum IO_CAPABILITY
MACRO IO_CAPABILITY_ENUM = LONG
%IoCaps_DisplayOnly     = &H00
%IoCaps_DisplayYesNo    = &H01
%IoCaps_KeyboardOnly    = &H02
%IoCaps_NoInputNoOutput = &H03
%IoCaps_Undefined       = &Hff

' enum OOB_DATA_PRESENT
MACRO OOB_DATA_PRESENT_ENUM = LONG
%OOBAuthenticationDataNotPresent              = &H00
%OOBAuthenticationDataFromRemoteDevicePresent = &H01

' enum AUTHENTICATION_REQUIREMENTS
MACRO AUTHENTICATION_REQUIREMENTS_ENUM = LONG
%MITMProtectionNotRequired               = &H00
%MITMProtectionRequired                  = &H01
%MITMProtectionNotRequiredBonding        = &H02
%MITMProtectionRequiredBonding           = &H03
%MITMProtectionNotRequiredGeneralBonding = &H04
%MITMProtectionRequiredGeneralBonding    = &H05
%MITMProtectionNotDefined                = &Hff

'#define IsMITMProtectionRequired(requirements) \
'        ((MITMProtectionRequired == requirements) || (MITMProtectionRequiredBonding == requirements) || (MITMProtectionRequiredGeneralBonding == requirements))
MACRO IsMITMProtectionRequired(requirements) = ((%MITMProtectionRequired = requirements) OR (%MITMProtectionRequiredBonding = requirements) OR (%MITMProtectionRequiredGeneralBonding = requirements))

'//
'// Buffer associated with GUID_BLUETOOTH_AUTHENTICATION_REQUEST
'//
'typedef struct _BTH_AUTHENTICATION_REQUEST {
'    BTH_DEVICE_INFO             deviceInfo;
'    BTH_AUTH_METHOD             authenticationMethod;
'    IO_CAPABILITY               IoCapability;
'    AUTHENTICATION_REQUIREMENTS AuthenticationRequirements;  // max(local,remote)

'    ULONG                       flag; // Reserved

'    union{
'        ULONG   Numeric_Value;
'        ULONG   Passkey;
'    };
'}BTH_AUTHENTICATION_REQUEST, *PBTH_AUTHENTICATION_REQUEST;

UNION BTH_AUTHENTICATION_REQUEST_UNION DWORD
   Numeric_Value AS DWORD   ' ULONG
   Passkey       AS DWORD   ' ULONG
END UNION

' // Size = 296 bytes
TYPE BTH_AUTHENTICATION_REQUEST   ' Must be 8 byte aligned
   deviceInfo                 AS BTH_DEVICE_INFO   ' Size = 272 bytes
   authenticationMethod       AS LONG              ' BTH_AUTH_METHOD - Size = 4 bytes
   IoCapability               AS LONG              ' IO_CAPABILITY - Size = 4 bytes
   AuthenticationRequirements AS LONG              ' AUTHENTICATION_REQUIREMENTS // max(local,remote)
   flag                       AS DWORD             ' ULONG // Reserved
   BTH_AUTHENTICATION_REQUEST_UNION
   filler_                    AS DWORD             ' // To keep 8 bytes alignment
END TYPE

'#endif // >= SP1+KB942567

'//
'// max length we allow for ServiceName in the remote SDP records
'//
%BTH_MAX_SERVICE_NAME_SIZE            = 256

%MAX_UUIDS_IN_QUERY                   = 12

%BTH_VID_DEFAULT_VALUE                = &HFFFF??

%SDP_ERROR_INVALID_SDP_VERSION        = &H0001??
%SDP_ERROR_INVALID_RECORD_HANDLE      = &H0002??
%SDP_ERROR_INVALID_REQUEST_SYNTAX     = &H0003??
%SDP_ERROR_INVALID_PDU_SIZE           = &H0004??
%SDP_ERROR_INVALID_CONTINUATION_STATE = &H0005??
%SDP_ERROR_INSUFFICIENT_RESOURCES     = &H0006??

'//
'// Defined by windows to handle server errors that are not described by the
'// above errors.  Start at 0x0100 so we don't go anywhere near the spec
'// defined values.
'//

'//
'// Success, nothing went wrong
'//
%SDP_ERROR_SUCCESS                              = &H0000??   ' SDP_ERROR

'//
'// The SDP PDU or parameters other than the SDP stream response was not correct
'//
%SDP_ERROR_SERVER_INVALID_RESPONSE              = &H0100??   ' SDP_ERROR

'//
'// The SDP response stream did not parse correctly.
'//
%SDP_ERROR_SERVER_RESPONSE_DID_NOT_PARSE        = &H0200??   ' SDP_ERROR

'//
'// The SDP response stream was successfully parsed, but did not match the
'// required format for the query.
'//
%SDP_ERROR_SERVER_BAD_FORMAT                    = &H0300??   ' SDP_ERROR

'//
'// SDP was unable to send a continued query back to the server
'//
%SDP_ERROR_COULD_NOT_SEND_CONTINUE              = &H0400??   ' SDP_ERROR

'//
'// Server sent a response that was too large to fit in the caller's buffer.
'//
%SDP_ERROR_RESPONSE_TOO_LARGE                   = &H0500??   ' SDP_ERROR


%SDP_ATTRIB_RECORD_HANDLE                       = &H0000??
%SDP_ATTRIB_CLASS_ID_LIST                       = &H0001??
%SDP_ATTRIB_RECORD_STATE                        = &H0002??
%SDP_ATTRIB_SERVICE_ID                          = &H0003??
%SDP_ATTRIB_PROTOCOL_DESCRIPTOR_LIST            = &H0004??
%SDP_ATTRIB_BROWSE_GROUP_LIST                   = &H0005??
%SDP_ATTRIB_LANG_BASE_ATTRIB_ID_LIST            = &H0006??
%SDP_ATTRIB_INFO_TIME_TO_LIVE                   = &H0007??
%SDP_ATTRIB_AVAILABILITY                        = &H0008??
%SDP_ATTRIB_PROFILE_DESCRIPTOR_LIST             = &H0009??
%SDP_ATTRIB_DOCUMENTATION_URL                   = &H000A??
%SDP_ATTRIB_CLIENT_EXECUTABLE_URL               = &H000B??
%SDP_ATTRIB_ICON_URL                            = &H000C??
%SDP_ATTRIB_ADDITIONAL_PROTOCOL_DESCRIPTOR_LIST = &H000D??

'//
'// Attribute IDs in the range of 0x000D - 0x01FF are reserved for future use
'//
%SDP_ATTRIB_PROFILE_SPECIFIC                    = &H0200??

%LANG_BASE_LANGUAGE_INDEX                       = &H0000??
%LANG_BASE_ENCODING_INDEX                       = &H0001??
%LANG_BASE_OFFSET_INDEX                         = &H0002??
%LANG_DEFAULT_ID                                = &H0100??

%STRING_NAME_OFFSET                             = &H0000??
%STRING_DESCRIPTION_OFFSET                      = &H0001??
%STRING_PROVIDER_NAME_OFFSET                    = &H0002??

%SDP_ATTRIB_SDP_VERSION_NUMBER_LIST             = &H0200??
%SDP_ATTRIB_SDP_DATABASE_STATE                  = &H0201??

%SDP_ATTRIB_BROWSE_GROUP_ID                     = &H0200??

%SDP_ATTRIB_CORDLESS_EXTERNAL_NETWORK           = &H0301??

%SDP_ATTRIB_FAX_CLASS_1_SUPPORT                 = &H0302??
%SDP_ATTRIB_FAX_CLASS_2_0_SUPPORT               = &H0303??
%SDP_ATTRIB_FAX_CLASS_2_SUPPORT                 = &H0304??
%SDP_ATTRIB_FAX_AUDIO_FEEDBACK_SUPPORT          = &H0305??

%SDP_ATTRIB_HEADSET_REMOTE_AUDIO_VOLUME_CONTROL = &H0302??

%SDP_ATTRIB_LAN_LPSUBNET                        = &H0200??

%SDP_ATTRIB_OBJECT_PUSH_SUPPORTED_FORMATS_LIST  = &H0303??

%SDP_ATTRIB_SYNCH_SUPPORTED_DATA_STORES_LIST    = &H0301??

'//  this is in the assigned numbers doc, but it does not show up in any profile
%SDP_ATTRIB_SERVICE_VERSION                     = &H0300??

%SDP_ATTRIB_PAN_NETWORK_ADDRESS                 = &H0306??
%SDP_ATTRIB_PAN_WAP_GATEWAY                     = &H0307??
%SDP_ATTRIB_PAN_HOME_PAGE_URL                   = &H0308??
%SDP_ATTRIB_PAN_WAP_STACK_TYPE                  = &H0309??
%SDP_ATTRIB_PAN_SECURITY_DESCRIPTION            = &H030A??
%SDP_ATTRIB_PAN_NET_ACCESS_TYPE                 = &H030B??
%SDP_ATTRIB_PAN_MAX_NET_ACCESS_RATE             = &H030C??

%SDP_ATTRIB_IMAGING_SUPPORTED_CAPABILITIES      = &H0310??
%SDP_ATTRIB_IMAGING_SUPPORTED_FEATURES          = &H0311??
%SDP_ATTRIB_IMAGING_SUPPORTED_FUNCTIONS         = &H0312??
%SDP_ATTRIB_IMAGING_TOTAL_DATA_CAPACITY         = &H0313??

%SDP_ATTRIB_DI_SPECIFICATION_ID                 = &H0200??
%SDP_ATTRIB_DI_VENDOR_ID                        = &H0201??
%SDP_ATTRIB_DI_PRODUCT_ID                       = &H0202??
%SDP_ATTRIB_DI_VERSION                          = &H0203??
%SDP_ATTRIB_DI_PRIMARY_RECORD                   = &H0204??
%SDP_ATTRIB_DI_VENDOR_ID_SOURCE                 = &H0205??

%SDP_ATTRIB_HID_DEVICE_RELEASE_NUMBER           = &H0200??
%SDP_ATTRIB_HID_PARSER_VERSION                  = &H0201??
%SDP_ATTRIB_HID_DEVICE_SUBCLASS                 = &H0202??
%SDP_ATTRIB_HID_COUNTRY_CODE                    = &H0203??
%SDP_ATTRIB_HID_VIRTUAL_CABLE                   = &H0204??
%SDP_ATTRIB_HID_RECONNECT_INITIATE              = &H0205??
%SDP_ATTRIB_HID_DESCRIPTOR_LIST                 = &H0206??
%SDP_ATTRIB_HID_LANG_ID_BASE_LIST               = &H0207??
%SDP_ATTRIB_HID_SDP_DISABLE                     = &H0208??
%SDP_ATTRIB_HID_BATTERY_POWER                   = &H0209??
%SDP_ATTRIB_HID_REMOTE_WAKE                     = &H020A??
'%SDP_ATTRIB_HID_REPORT_LIST                     = &H020B??   ' // Name changed in the Windows 7 SDK
%SDP_ATTRIB_HID_PROFILE_VERSION                 = &H020B??
%SDP_ATTRIB_HID_SUPERVISION_TIMEOUT             = &H020C??
%SDP_ATTRIB_HID_NORMALLY_CONNECTABLE            = &H020D??
%SDP_ATTRIB_HID_BOOT_DEVICE                     = &H020E??
%SDP_ATTRIB_HID_SSR_HOST_MAX_LATENCY            = &H020F??
%SDP_ATTRIB_HID_SSR_HOST_MIN_TIMEOUT            = &H0210??

'//
'// Profile specific values
'//
%CORDLESS_EXTERNAL_NETWORK_PSTN                 = &H01?
%CORDLESS_EXTERNAL_NETWORK_ISDN                 = &H02?
%CORDLESS_EXTERNAL_NETWORK_GSM                  = &H03?
%CORDLESS_EXTERNAL_NETWORK_CDMA                 = &H04?
%CORDLESS_EXTERNAL_NETWORK_ANALOG_CELLULAR      = &H05?
%CORDLESS_EXTERNAL_NETWORK_PACKET_SWITCHED      = &H06?
%CORDLESS_EXTERNAL_NETWORK_OTHER                = &H07?

%OBJECT_PUSH_FORMAT_VCARD_2_1                   = &H01?
%OBJECT_PUSH_FORMAT_VCARD_3_0                   = &H02?
%OBJECT_PUSH_FORMAT_VCAL_1_0                    = &H03?
%OBJECT_PUSH_FORMAT_ICAL_2_0                    = &H04?
%OBJECT_PUSH_FORMAT_VNOTE                       = &H05?
%OBJECT_PUSH_FORMAT_VMESSAGE                    = &H06?
%OBJECT_PUSH_FORMAT_ANY                         = &HFF?

%SYNCH_DATA_STORE_PHONEBOOK                     = &H01?
%SYNCH_DATA_STORE_CALENDAR                      = &H03?
%SYNCH_DATA_STORE_NOTES                         = &H05?
%SYNCH_DATA_STORE_MESSAGES                      = &H06?

%DI_VENDOR_ID_SOURCE_BLUETOOTH_SIG              = &H0001??
%DI_VENDOR_ID_SOURCE_USB_IF                     = &H0002??

%PSM_SDP                                        = &H0001??
%PSM_RFCOMM                                     = &H0003??
%PSM_TCS_BIN                                    = &H0005??
%PSM_TCS_BIN_CORDLESS                           = &H0007??
%PSM_BNEP                                       = &H000F??
%PSM_HID_CONTROL                                = &H0011??
%PSM_HID_INTERRUPT                              = &H0013??
%PSM_AVCTP                                      = &H0017??
%PSM_AVDTP                                      = &H0019??
%PSM_UDI_C_PLANE                                = &H001D??

'//
'// Strings
'//
'#define STR_ADDR_FMTA          "(%02x:%02x:%02x:%02x:%02x:%02x)"
'#define STR_ADDR_FMTW          L"(%02x:%02x:%02x:%02x:%02x:%02x)"
$STR_ADDR_FMTA = "(%02x:%02x:%02x:%02x:%02x:%02x)"
$$STR_ADDR_FMTW = "(%02x:%02x:%02x:%02x:%02x:%02x)"$$
#IF %DEF(%UNICODE)
MACRO STR_ADDR_FMT = $$STR_ADDR_FMTW
#ELSE
MACRO STR_ADDR_FMT = $STR_ADDR_FMTA
#ENDIF

'#define STR_ADDR_SHORT_FMTA     "%04x%08x"
'#define STR_ADDR_SHORT_FMTW     L"%04x%08x"
$STR_ADDR_SHORT_FMTA = "%04x%08x"
$$STR_ADDR_SHORT_FMTW = "%04x%08x"$$
#IF %DEF(%UNICODE)
MACRO STR_ADDR_SHORT_FMT = $STR_ADDR_SHORT_FMTA
#ELSE
MACRO STR_ADDR_SHORT_FMT = $$STR_ADDR_SHORT_FMTW
#ENDIF

'#define GET_BITS(field,offset,mask)         ( ( (field) >> (offset) ) & (mask) )

FUNCTION GET_BITS (BYVAL dwfield AS DWORD, BYVAL dwoffset AS DWORD, BYVAL dwmask AS DWORD) AS DWORD
   SHIFT RIGHT dwfield, dwoffset
   FUNCTION = dwfield AND dwmask
END FUNCTION

'#define GET_BIT(field,offset)               ( GET_BITS(field,offset,0x1) )

FUNCTION GET_BIT (BYVAL dwfield AS DWORD, BYVAL dwoffset AS DWORD) AS DWORD
   FUNCTION = GET_BITS(dwfield, dwoffset, &H1)
END FUNCTION

'#define LMP_3_SLOT_PACKETS(x)               (GET_BIT(x, 0))
FUNCTION LMP_3_SLOT_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 0)
END FUNCTION

'#define LMP_5_SLOT_PACKETS(x)               (GET_BIT(x, 1))
FUNCTION LMP_5_SLOT_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 1)
END FUNCTION

'#define LMP_ENCRYPTION(x)                   (GET_BIT(x, 2))
FUNCTION LMP_ENCRYPTION (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 2)
END FUNCTION

'#define LMP_SLOT_OFFSET(x)                  (GET_BIT(x, 3))
FUNCTION LMP_SLOT_OFFSET (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 3)
END FUNCTION

'#define LMP_TIMING_ACCURACY(x)              (GET_BIT(x, 4))
FUNCTION LMP_TIMING_ACCURACY (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 4)
END FUNCTION

'#define LMP_SWITCH(x)                       (GET_BIT(x, 5))
FUNCTION LMP_SWITCH (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 5)
END FUNCTION

'#define LMP_HOLD_MODE(x)                    (GET_BIT(x, 6))
FUNCTION LMP_HOLD_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 6)
END FUNCTION

'#define LMP_SNIFF_MODE(x)                   (GET_BIT(x, 7))
FUNCTION LMP_SNIFF_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 7)
END FUNCTION

'#define LMP_PARK_MODE(x)                    (GET_BIT(x, 8))
FUNCTION LMP_PARK_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 8)
END FUNCTION

'#define LMP_RSSI(x)                         (GET_BIT(x, 9))
FUNCTION LMP_RSSI(BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 9)
END FUNCTION

'#define LMP_CHANNEL_QUALITY_DRIVEN_MODE(x)  (GET_BIT(x,10))
FUNCTION LMP_CHANNEL_QUALITY_DRIVEN_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 10)
END FUNCTION

'#define LMP_SCO_LINK(x)                     (GET_BIT(x,11))
FUNCTION LMP_SCO_LINK (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 11)
END FUNCTION

'#define LMP_HV2_PACKETS(x)                  (GET_BIT(x,12))
FUNCTION LMP_HV2_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 12)
END FUNCTION

'#define LMP_HV3_PACKETS(x)                  (GET_BIT(x,13))
FUNCTION LMP_HV3_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 13)
END FUNCTION

'#define LMP_MU_LAW_LOG(x)                   (GET_BIT(x,14))
FUNCTION LMP_MU_LAW_LOG (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 14)
END FUNCTION

'#define LMP_A_LAW_LOG(x)                    (GET_BIT(x,15))
FUNCTION LMP_A_LAW_LOG (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 15)
END FUNCTION

'#define LMP_CVSD(x)                         (GET_BIT(x,16))
FUNCTION LMP_CVSD (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 16)
END FUNCTION

'#define LMP_PAGING_SCHEME(x)                (GET_BIT(x,17))
FUNCTION LMP_PAGING_SCHEME (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 17)
END FUNCTION

'#define LMP_POWER_CONTROL(x)                (GET_BIT(x,18))
FUNCTION LMP_POWER_CONTROL (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 18)
END FUNCTION

'#define LMP_TRANSPARENT_SCO_DATA(x)         (GET_BIT(x,19))
FUNCTION LMP_TRANSPARENT_SCO_DATA (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 19)
END FUNCTION

'#define LMP_FLOW_CONTROL_LAG(x)             (GET_BITS(x,20,0x3))
FUNCTION LMP_FLOW_CONTROL_LAG (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BITS(x, 20, &H3)
END FUNCTION

'#define LMP_BROADCAST_ENCRYPTION(x)         (GET_BIT(x,23))
FUNCTION LMP_BROADCAST_ENCRYPTION (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 23)
END FUNCTION

'#define LMP_ENHANCED_DATA_RATE_ACL_2MBPS_MODE(x) (GET_BIT(x,25))
FUNCTION LMP_ENHANCED_DATA_RATE_ACL_2MBPS_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 25)
END FUNCTION

'#define LMP_ENHANCED_DATA_RATE_ACL_3MBPS_MODE(x) (GET_BIT(x,26))
FUNCTION LMP_ENHANCED_DATA_RATE_ACL_3MBPS_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 26)
END FUNCTION

'#define LMP_ENHANCED_INQUIRY_SCAN(x)        (GET_BIT(x,27))
FUNCTION LMP_ENHANCED_INQUIRY_SCAN (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 27)
END FUNCTION

'#define LMP_INTERLACED_INQUIRY_SCAN(x)      (GET_BIT(x,28))
FUNCTION LMP_INTERLACED_INQUIRY_SCAN (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 28)
END FUNCTION

'#define LMP_INTERLACED_PAGE_SCAN(x)         (GET_BIT(x,29))
FUNCTION LMP_INTERLACED_PAGE_SCAN (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 29)
END FUNCTION

'#define LMP_RSSI_WITH_INQUIRY_RESULTS(x)    (GET_BIT(x,30))
FUNCTION LMP_RSSI_WITH_INQUIRY_RESULTS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 30)
END FUNCTION

'#define LMP_ESCO_LINK(x)                    (GET_BIT(x,31))
FUNCTION LMP_ESCO_LINK (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 31)
END FUNCTION

'#define LMP_EV4_PACKETS(x)                  (GET_BIT(x,32))
FUNCTION LMP_EV4_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 32)
END FUNCTION

'#define LMP_EV5_PACKETS(x)                  (GET_BIT(x,33))
FUNCTION LMP_EV5_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 33)
END FUNCTION

'#define LMP_AFH_CAPABLE_SLAVE(x)            (GET_BIT(x,35))
FUNCTION LMP_AFH_CAPABLE_SLAVE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 35)
END FUNCTION

'#define LMP_AFH_CLASSIFICATION_SLAVE(x)     (GET_BIT(x,36))
FUNCTION LMP_AFH_CLASSIFICATION_SLAVE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 36)
END FUNCTION

'#define LMP_3SLOT_EDR_ACL_PACKETS(x)        (GET_BIT(x,39))
FUNCTION LMP_3SLOT_EDR_ACL_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 39)
END FUNCTION

'#define LMP_5SLOT_EDR_ACL_PACKETS(x)        (GET_BIT(x,40))
FUNCTION LMP_5SLOT_EDR_ACL_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 40)
END FUNCTION

'#define LMP_SNIFF_SUBRATING(x)              (GET_BIT(x,41))
FUNCTION LMP_SNIFF_SUBRATING (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 41)
END FUNCTION

'#define LMP_PAUSE_ENCRYPTION(x)             (GET_BIT(x,42))
FUNCTION LMP_PAUSE_ENCRYPTION (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 42)
END FUNCTION

'#define LMP_AFH_CAPABLE_MASTER(x)           (GET_BIT(x,43))
FUNCTION LMP_AFH_CAPABLE_MASTER (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 43)
END FUNCTION

'#define LMP_AFH_CLASSIFICATION_MASTER(x)    (GET_BIT(x,44))
FUNCTION LMP_AFH_CLASSIFICATION_MASTER (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 44)
END FUNCTION

'#define LMP_EDR_ESCO_2MBPS_MODE(x)          (GET_BIT(x,45))
FUNCTION LMP_EDR_ESCO_2MBPS_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 45)
END FUNCTION

'#define LMP_EDR_ESCO_3MBPS_MODE(x)          (GET_BIT(x,46))
FUNCTION LMP_EDR_ESCO_3MBPS_MODE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 46)
END FUNCTION

'#define LMP_3SLOT_EDR_ESCO_PACKETS(x)       (GET_BIT(x,47))
FUNCTION LMP_3SLOT_EDR_ESCO_PACKETS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 47)
END FUNCTION

'#define LMP_EXTENDED_INQUIRY_RESPONSE(x)    (GET_BIT(x,48))
FUNCTION LMP_EXTENDED_INQUIRY_RESPONSE (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 48)
END FUNCTION

'#define LMP_SECURE_SIMPLE_PAIRING(x)        (GET_BIT(x,51))
FUNCTION LMP_SECURE_SIMPLE_PAIRING (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 51)
END FUNCTION

'#define LMP_ENCAPSULATED_PDU(x)             (GET_BIT(x,52))
FUNCTION LMP_ENCAPSULATED_PDU (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 52)
END FUNCTION

'#define LMP_ERRONEOUS_DATA_REPORTING(x)     (GET_BIT(x,53))
FUNCTION LMP_ERRONEOUS_DATA_REPORTING (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 53)
END FUNCTION

'#define LMP_NON_FLUSHABLE_PACKET_BOUNDARY_FLAG(x) (GET_BIT(x,54))
FUNCTION LMP_NON_FLUSHABLE_PACKET_BOUNDARY_FLAG (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 54)
END FUNCTION

'#define LMP_LINK_SUPERVISION_TIMEOUT_CHANGED_EVENT(x) (GET_BIT(x,56))
FUNCTION LMP_LINK_SUPERVISION_TIMEOUT_CHANGED_EVENT (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 56)
END FUNCTION

'#define LMP_INQUIRY_RESPONSE_TX_POWER_LEVEL(x)(GET_BIT(x,57))
FUNCTION LMP_INQUIRY_RESPONSE_TX_POWER_LEVEL (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 57)
END FUNCTION

'#define LMP_EXTENDED_FEATURES(x)            (GET_BIT(x,63))
FUNCTION LMP_EXTENDED_FEATURES (BYVAL x AS DWORD) AS DWORD
   FUNCTION = GET_BIT(x, 63)
END FUNCTION

#ENDIF ' // GUID_DEFS_ONLY

'#endif // (NTDDI_VERSION >= NTDDI_WINXPSP2)

'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning(default:4201)
'#endif
