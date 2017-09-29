' ########################################################################################
' Microsoft Windows
' File: opmapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OPMAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "dxva2api.inc"

'#ifndef OPM_API_DEFINED
'#define OPM_API_DEFINED
'#pragma pack( push, 1  )

$OPM_GET_CURRENT_HDCP_SRM_VERSION = GUID$("{99c5ceff-5f1d-4879-81c1-c52443c9482b}")
$OPM_GET_CONNECTED_HDCP_DEVICE_INFORMATION = GUID$("{0db59d74-a992-492e-a0bd-c23fda564e00}")
$OPM_GET_ACP_AND_CGMSA_SIGNALING = GUID$("{6629a591-3b79-4cf3-924a-11e8e7811671}")
$OPM_GET_CONNECTOR_TYPE = GUID$("{81d0bfd5-6afe-48c2-99c0-95a08f97c5da}")
$OPM_GET_SUPPORTED_PROTECTION_TYPES = GUID$("{38f2a801-9a6c-48bb-9107-b6696e6f1797}")
$OPM_GET_VIRTUAL_PROTECTION_LEVEL = GUID$("{b2075857-3eda-4d5d-88db-748f8c1a0549}")
$OPM_GET_ACTUAL_PROTECTION_LEVEL = GUID$("{1957210a-7766-452a-b99a-d27aed54f03a}")
$OPM_GET_ACTUAL_OUTPUT_FORMAT = GUID$("{d7bf1ba3-ad13-4f8e-af98-0dcb3ca204cc}")
$OPM_GET_ADAPTER_BUS_TYPE = GUID$("{c6f4d673-6174-4184-8e35-f6db5200bcba}")
$OPM_GET_OUTPUT_ID = GUID$("{72cb6df3-244f-40ce-b09e-20506af6302f}")
$OPM_GET_DVI_CHARACTERISTICS = GUID$("{a470b3bb-5dd7-4172-839c-3d3776e0ebf5}")
$OPM_GET_CODEC_INFO = GUID$("{4f374491-8f5f-4445-9dba-95588f6b58b4}")
$OPM_SET_PROTECTION_LEVEL = GUID$("{9bb9327c-4eb5-4727-9f00-b42b0919c0da}")
$OPM_SET_ACP_AND_CGMSA_SIGNALING = GUID$("{09a631a5-d684-4c60-8e4d-d3bb0f0be3ee}")
$OPM_SET_HDCP_SRM = GUID$("{8b5ef5d1-c30d-44ff-84a5-ea71dce78f13}")
$OPM_SET_PROTECTION_LEVEL_ACCORDING_TO_CSS_DVD = GUID$("{39ce333e-4cc0-44ae-bfcc-da50b5f82e72}")

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0001
%OPM_OMAC_SIZE                                = 16
%OPM_128_BIT_RANDOM_NUMBER_SIZE               = 16
%OPM_ENCRYPTED_INITIALIZATION_PARAMETERS_SIZE = 256
%OPM_CONFIGURE_SETTING_DATA_SIZE              = 4056
%OPM_GET_INFORMATION_PARAMETERS_SIZE          = 4056
%OPM_REQUESTED_INFORMATION_SIZE               = 4076
%OPM_HDCP_KEY_SELECTION_VECTOR_SIZE           = 5
%OPM_PROTECTION_TYPE_SIZE                     = 4
%OPM_BUS_TYPE_MASK                            = &Hffff???
%OPM_BUS_IMPLEMENTATION_MODIFIER_MASK         = &H7fff???

'enum OPM_VIDEO_OUTPUT_SEMANTICS
%OPM_VOS_COPP_SEMANTICS = 0
%OPM_VOS_OPM_SEMANTICS  = 1

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0002
%OPM_HDCP_FLAG_NONE     = 0???
%OPM_HDCP_FLAG_REPEATER = &H1???

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0003
%OPM_STATUS_NORMAL                       = 0???
%OPM_STATUS_LINK_LOST                    = &H1???
%OPM_STATUS_RENEGOTIATION_REQUIRED       = &H2???
%OPM_STATUS_TAMPERING_DETECTED           = &H4???
%OPM_STATUS_REVOKED_HDCP_DEVICE_ATTACHED = &H8???

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0004
%OPM_CONNECTOR_TYPE_OTHER                    = -1
%OPM_CONNECTOR_TYPE_VGA                      = 0
%OPM_CONNECTOR_TYPE_SVIDEO                   = 1
%OPM_CONNECTOR_TYPE_COMPOSITE_VIDEO          = 2
%OPM_CONNECTOR_TYPE_COMPONENT_VIDEO          = 3
%OPM_CONNECTOR_TYPE_DVI                      = 4
%OPM_CONNECTOR_TYPE_HDMI                     = 5
%OPM_CONNECTOR_TYPE_LVDS                     = 6
%OPM_CONNECTOR_TYPE_D_JPN                    = 8
%OPM_CONNECTOR_TYPE_SDI                      = 9
%OPM_CONNECTOR_TYPE_DISPLAYPORT_EXTERNAL     = 10
%OPM_CONNECTOR_TYPE_DISPLAYPORT_EMBEDDED     = 11
%OPM_CONNECTOR_TYPE_UDI_EXTERNAL             = 12
%OPM_CONNECTOR_TYPE_UDI_EMBEDDED             = 13
%OPM_COPP_COMPATIBLE_CONNECTOR_TYPE_INTERNAL = &H80000000???

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0005
%OPM_DVI_CHARACTERISTIC_1_0          = 1
%OPM_DVI_CHARACTERISTIC_1_1_OR_ABOVE = 2

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0006
%OPM_BUS_TYPE_OTHER                                                      = 0???
%OPM_BUS_TYPE_PCI                                                        = &H1???
%OPM_BUS_TYPE_PCIX                                                       = &H2???
%OPM_BUS_TYPE_PCIEXPRESS                                                 = &H3???
%OPM_BUS_TYPE_AGP                                                        = &H4???
%OPM_BUS_IMPLEMENTATION_MODIFIER_INSIDE_OF_CHIPSET                       = &H10000???
%OPM_BUS_IMPLEMENTATION_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP          = &H20000???
%OPM_BUS_IMPLEMENTATION_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_SOCKET        = &H30000???
%OPM_BUS_IMPLEMENTATION_MODIFIER_DAUGHTER_BOARD_CONNECTOR                = &H40000???
%OPM_BUS_IMPLEMENTATION_MODIFIER_DAUGHTER_BOARD_CONNECTOR_INSIDE_OF_NUAE = &H50000???
%OPM_BUS_IMPLEMENTATION_MODIFIER_NON_STANDARD                            = &H80000000???
%OPM_COPP_COMPATIBLE_BUS_TYPE_INTEGRATED                                 = &H80000000???

'enum OPM_DPCP_PROTECTION_LEVEL
%OPM_DPCP_OFF         = 0???
%OPM_DPCP_ON          = 1???
%OPM_DPCP_FORCE_ULONG = &H7fffffff???

'enum OPM_HDCP_PROTECTION_LEVEL
%OPM_HDCP_OFF         = 0???
%OPM_HDCP_ON          = 1???
%OPM_HDCP_FORCE_ULONG = &H7fffffff???

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0007
%OPM_CGMSA_OFF                             = 0???
%OPM_CGMSA_COPY_FREELY                     = &H1???
%OPM_CGMSA_COPY_NO_MORE                    = &H2???
%OPM_CGMSA_COPY_ONE_GENERATION             = &H3???
%OPM_CGMSA_COPY_NEVER                      = &H4???
%OPM_CGMSA_REDISTRIBUTION_CONTROL_REQUIRED = &H8???

'enum OPM_ACP_PROTECTION_LEVEL
%OPM_ACP_OFF         = 0???
%OPM_ACP_LEVEL_ONE   = 1???
%OPM_ACP_LEVEL_TWO   = 2???
%OPM_ACP_LEVEL_THREE = 3???
%OPM_ACP_FORCE_ULONG = &H7fffffff???

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0008
%OPM_PROTECTION_TYPE_OTHER                = &H80000000???
%OPM_PROTECTION_TYPE_NONE                 = 0???
%OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP = &H1???
%OPM_PROTECTION_TYPE_ACP                  = &H2???
%OPM_PROTECTION_TYPE_CGMSA                = &H4???
%OPM_PROTECTION_TYPE_HDCP                 = &H8???
%OPM_PROTECTION_TYPE_DPCP                 = &H10???

'enum __MIDL___MIDL_itf_opmapi_0000_0000_0009
%OPM_PROTECTION_STANDARD_OTHER               = &H80000000???
%OPM_PROTECTION_STANDARD_NONE                = 0???
%OPM_PROTECTION_STANDARD_IEC61880_525I       = &H1???
%OPM_PROTECTION_STANDARD_IEC61880_2_525I     = &H2???
%OPM_PROTECTION_STANDARD_IEC62375_625P       = &H4???
%OPM_PROTECTION_STANDARD_EIA608B_525         = &H8???
%OPM_PROTECTION_STANDARD_EN300294_625I       = &H10???
%OPM_PROTECTION_STANDARD_CEA805A_TYPEA_525P  = &H20???
%OPM_PROTECTION_STANDARD_CEA805A_TYPEA_750P  = &H40???
%OPM_PROTECTION_STANDARD_CEA805A_TYPEA_1125I = &H80???
%OPM_PROTECTION_STANDARD_CEA805A_TYPEB_525P  = &H100???
%OPM_PROTECTION_STANDARD_CEA805A_TYPEB_750P  = &H200???
%OPM_PROTECTION_STANDARD_CEA805A_TYPEB_1125I = &H400???
%OPM_PROTECTION_STANDARD_ARIBTRB15_525I      = &H800???
%OPM_PROTECTION_STANDARD_ARIBTRB15_525P      = &H1000???
%OPM_PROTECTION_STANDARD_ARIBTRB15_750P      = &H2000???
%OPM_PROTECTION_STANDARD_ARIBTRB15_1125I     = &H4000???

'enum OPM_IMAGE_ASPECT_RATIO_EN300294
%OPM_ASPECT_RATIO_EN300294_FULL_FORMAT_4_BY_3                  = 0???
%OPM_ASPECT_RATIO_EN300294_BOX_14_BY_9_CENTER                  = 1???
%OPM_ASPECT_RATIO_EN300294_BOX_14_BY_9_TOP                     = 2???
%OPM_ASPECT_RATIO_EN300294_BOX_16_BY_9_CENTER                  = 3???
%OPM_ASPECT_RATIO_EN300294_BOX_16_BY_9_TOP                     = 4???
%OPM_ASPECT_RATIO_EN300294_BOX_GT_16_BY_9_CENTER               = 5???
%OPM_ASPECT_RATIO_EN300294_FULL_FORMAT_4_BY_3_PROTECTED_CENTER = 6???
%OPM_ASPECT_RATIO_EN300294_FULL_FORMAT_16_BY_9_ANAMORPHIC      = 7???
%OPM_ASPECT_RATIO_FORCE_ULONG                                  = &H7fffffff???

TYPE OPM_RANDOM_NUMBER
   abRandomNumber(15) AS BYTE   ' BYTE[16]
END TYPE

TYPE OPM_OMAC
   abOMAC(15) AS BYTE   ' BYTE[16]
END TYPE

TYPE OPM_ENCRYPTED_INITIALIZATION_PARAMETERS
   abEncryptedInitializationParameters(255) AS BYTE   ' BYTE[256]
END TYPE

TYPE OPM_GET_INFO_PARAMETERS
   omac               AS OPM_OMAC            ' OPM_OMAC
   rnRandomNumber     AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   guidInformation    AS GUID                ' GUID
   ulSequenceNumber   AS DWORD               ' ULONG
   cbParametersSize   AS DWORD               ' ULONG
   abParameters(4055) AS BYTE                ' BYTE[4056]
END TYPE

TYPE OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS
   rnRandomNumber     AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   guidInformation    AS GUID                ' GUID
   ulSequenceNumber   AS DWORD               ' ULONG
   cbParametersSize   AS DWORD               ' ULONG
   abParameters(4055) AS BYTE                ' BYTE[4056]
END TYPE

TYPE OPM_HDCP_KEY_SELECTION_VECTOR
   abKeySelectionVector(4) AS BYTE   ' BYTE[5]
END TYPE

TYPE OPM_CONNECTED_HDCP_DEVICE_INFORMATION
   rnRandomNumber AS OPM_RANDOM_NUMBER               ' OPM_RANDOM_NUMBER
   ulStatusFlags  AS DWORD                           ' ULONG
   ulHDCPFlags    AS DWORD                           ' ULONG
   ksvB           AS OPM_HDCP_KEY_SELECTION_VECTOR   ' OPM_HDCP_KEY_SELECTION_VECTOR
   Reserved(10)   AS BYTE                            ' BYTE[11]
   Reserved2(15)  AS BYTE                            ' BYTE[16]
   Reserved3(15)  AS BYTE                            ' BYTE[16]
END TYPE

TYPE OPM_REQUESTED_INFORMATION
   omac                         AS OPM_OMAC   ' OPM_OMAC
   cbRequestedInformationSize   AS DWORD      ' ULONG
   abRequestedInformation(4075) AS BYTE       ' BYTE[4076]
END TYPE

TYPE OPM_STANDARD_INFORMATION
   rnRandomNumber AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   ulStatusFlags  AS DWORD               ' ULONG
   ulInformation  AS DWORD               ' ULONG
   ulReserved     AS DWORD               ' ULONG
   ulReserved2    AS DWORD               ' ULONG
END TYPE

'#ifndef DO_NOT_USE_DIRECTX_OR_DXVA2
TYPE OPM_ACTUAL_OUTPUT_FORMAT
   rnRandomNumber            AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   ulStatusFlags             AS DWORD               ' ULONG
   ulDisplayWidth            AS DWORD               ' ULONG
   ulDisplayHeight           AS DWORD               ' ULONG
   dsfSampleInterleaveFormat AS LONG                ' DXVA2_SampleFormat
   d3dFormat                 AS DWORD               ' D3DFORMAT
   ulFrequencyNumerator      AS DWORD               ' ULONG
   ulFrequencyDenominator    AS DWORD               ' ULONG
END TYPE

'#endif // DO_NOT_USE_DIRECTX_OR_DXVA2

TYPE OPM_ACP_AND_CGMSA_SIGNALING
   rnRandomNumber                   AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   ulStatusFlags                    AS DWORD               ' ULONG
   ulAvailableTVProtectionStandards AS DWORD               ' ULONG
   ulActiveTVProtectionStandard     AS DWORD               ' ULONG
   ulReserved                       AS DWORD               ' ULONG
   ulAspectRatioValidMask1          AS DWORD               ' ULONG
   ulAspectRatioData1               AS DWORD               ' ULONG
   ulAspectRatioValidMask2          AS DWORD               ' ULONG
   ulAspectRatioData2               AS DWORD               ' ULONG
   ulAspectRatioValidMask3          AS DWORD               ' ULONG
   ulAspectRatioData3               AS DWORD               ' ULONG
   ulReserved2(3)                   AS DWORD               ' ULONG[4]
   ulReserved3(3)                   AS DWORD               ' ULONG[4]
END TYPE

TYPE OPM_OUTPUT_ID_DATA
   rnRandomNumber AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   ulStatusFlags  AS DWORD               ' ULONG
   OutputId       AS QUAD                ' UINT64
END TYPE

TYPE OPM_CONFIGURE_PARAMETERS
   omac               AS OPM_OMAC   ' OPM_OMAC
   guidSetting        AS GUID       ' GUID
   ulSequenceNumber   AS DWORD      ' ULONG
   cbParametersSize   AS DWORD      ' ULONG
   abParameters(4055) AS BYTE       ' BYTE[4056]
END TYPE

TYPE OPM_SET_PROTECTION_LEVEL_PARAMETERS
   ulProtectionType  AS DWORD   ' ULONG
   ulProtectionLevel AS DWORD   ' ULONG
   Reserved          AS DWORD   ' ULONG
   Reserved2         AS DWORD   ' ULONG
END TYPE

TYPE OPM_SET_ACP_AND_CGMSA_SIGNALING_PARAMETERS
   ulNewTVProtectionStandard AS DWORD   ' ULONG
   ulAspectRatioChangeMask1  AS DWORD   ' ULONG
   ulAspectRatioData1        AS DWORD   ' ULONG
   ulAspectRatioChangeMask2  AS DWORD   ' ULONG
   ulAspectRatioData2        AS DWORD   ' ULONG
   ulAspectRatioChangeMask3  AS DWORD   ' ULONG
   ulAspectRatioData3        AS DWORD   ' ULONG
   ulReserved(3)             AS DWORD   ' ULONG[4]
   ulReserved2(3)            AS DWORD   ' ULONG[4]
   ulReserved3               AS DWORD   ' ULONG
END TYPE

TYPE OPM_SET_HDCP_SRM_PARAMETERS
   ulSRMVersion AS DWORD   ' ULONG
END TYPE

TYPE OPM_GET_CODEC_INFO_PARAMETERS
   cbVerifier     AS DWORD   ' DWORD
   Verifier(4051) AS BYTE    ' BYTE[4052]
END TYPE

TYPE OPM_GET_CODEC_INFO_INFORMATION
   rnRandomNumber AS OPM_RANDOM_NUMBER   ' OPM_RANDOM_NUMBER
   Merit          AS DWORD               ' DWORD
END TYPE

'#if defined( _WIN32 ) && !defined( _NO_COM )
$IID_IOPMVideoOutput = GUID$("{0A15159D-41C7-4456-93E1-284CD61D4E8D}")
'#endif // defined( _WIN32 ) && !defined( _NO_COM )

' ########################################################################################
' IOPMVideoOutput interface
' IID = 0A15159D-41C7-4456-93E1-284CD61D4E8D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOPMVideoOutput_INTERFACE_DEFINED)
    %IOPMVideoOutput_INTERFACE_DEFINED = 1

INTERFACE IOPMVideoOutput $IID_IOPMVideoOutput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartInitialization ( _                       ' VTable offset = 12
     BYREF prnRandomNumber AS OPM_RANDOM_NUMBER _       ' __out OPM_RANDOM_NUMBER *prnRandomNumber
   , BYREF ppbCertificate AS DWORD _                    ' __deref_out_bcount(*pulCertificateLength) BYTE **ppbCertificate
   , BYREF pulCertificateLength AS DWORD _              ' __out ULONG *pulCertificateLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinishInitialization ( _                      ' VTable offset = 16
     BYREF pParameters AS OPM_ENCRYPTED_INITIALIZATION_PARAMETERS _ '__in const OPM_ENCRYPTED_INITIALIZATION_PARAMETERS *pParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInformation ( _                            ' VTable offset = 20
     BYREF pParameters AS OPM_GET_INFO_PARAMETERS _     ' __in const OPM_GET_INFO_PARAMETERS *pParameters
   , BYREF pRequestedInformation AS OPM_REQUESTED_INFORMATION _ ' __out OPM_REQUESTED_INFORMATION *pRequestedInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD COPPCompatibleGetInformation ( _              ' VTable offset = 24
     BYREF pParameters AS OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS _ ' __in const OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS *pParameters
   , BYREF pRequestedInformation AS OPM_REQUESTED_INFORMATION _ ' __out OPM_REQUESTED_INFORMATION *pRequestedInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Configure ( _                                 ' VTable offset = 28
     BYREF pParameters AS OPM_CONFIGURE_PARAMETERS _    ' __in  const OPM_CONFIGURE_PARAMETERS *pParameters
   , BYVAL ulAdditionalParametersSize AS DWORD _        ' __in ULONG ulAdditionalParametersSize
   , BYVAL pbAdditionalParameters AS BYTE PTR _         ' __in_bcount_opt(ulAdditionalParametersSize) const BYTE *pbAdditionalParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOPMVideoOutput_INTERFACE_DEFINED__ */


'#ifdef DEFINE_GUIDSTRUCT
'#define STATIC_KSPROPSETID_OPMVideoOutput                                                       \
'0x6f414bb, 0xf43a, 0x4fe2, 0xa5, 0x66, 0x77, 0x4b, 0x4c, 0x81, 0xf0, 0xdb
'DEFINE_GUIDSTRUCT("06F414BB-F43A-4fe2-A566-774B4C81F0DB", KSPROPSETID_OPMVideoOutput);
'#define KSPROPSETID_OPMVideoOutput DEFINE_GUIDNAMED(KSPROPSETID_OPMVideoOutput)

$KSPROPSETID_OPMVideoOutput = GUID$("{06F414BB-F43A-4fe2-A566-774B4C81F0DB}")

'enum KSMETHOD_OPMVIDEOOUTPUT
'//  Output is OPM_RANDOM_NUMBER followed by certifiate
%KSMETHOD_OPMVIDEOOUTPUT_STARTINITIALIZATION  = 0

'//  Input OPM_ENCRYPTED_INITIALIZATION_PARAMETERS
'//  Output OPM_STANDARD_INFORMATION
%KSMETHOD_OPMVIDEOOUTPUT_FINISHINITIALIZATION = 1

'//  Input is OPM_GET_INFO_PARAMETERS, output is OPM_REQUESTED_INFORMATION
'//  Use KsMethod - both input and output in the buffer (not after the KSMETHOD structure)
%KSMETHOD_OPMVIDEOOUTPUT_GETINFORMATION       = 2

'#endif

'#define GetBusType( ulBusTypeAndImplementation )                        ((ulBusTypeAndImplementation) & OPM_BUS_TYPE_MASK)
'#define GetBusImplementation( ulBusTypeAndImplementation )              (((ulBusTypeAndImplementation) & OPM_BUS_IMPLEMENTATION_MODIFIER_MASK) >> 16)
'#define IsNonStandardBusImplementation( ulBusTypeAndImplementation )    ((ulBusTypeAndImplementation) & OPM_BUS_IMPLEMENTATION_MODIFIER_NON_STANDARD)

MACRO GetBusType(ulBusTypeAndImplementation) = (ulBusTypeAndImplementation AND %OPM_BUS_TYPE_MASK)
MACRO FUNCTION GetBusImplementation(ulBusTypeAndImplementation)
   MACROTEMP x
   LOCAL x AS DWORD
   x = (ulBusTypeAndImplementation AND %OPM_BUS_IMPLEMENTATION_MODIFIER_MASK)
   SHIFT RIGHT x, 16
END MACRO = x
MACRO IsNonStandardBusImplementation(ulBusTypeAndImplementation) = (ulBusTypeAndImplementation AND %OPM_BUS_IMPLEMENTATION_MODIFIER_NON_STANDARD)

DECLARE FUNCTION OPMGetVideoOutputsFromHMONITOR IMPORT "Dxva2.dll" ALIAS "OPMGetVideoOutputsFromHMONITOR" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HMONITOR hMonitor
 , BYVAL vos AS LONG _                                  ' __in OPM_VIDEO_OUTPUT_SEMANTICS vos
 , BYREF pulNumVideoOutputs AS DWORD _                  ' __out ULONG* pulNumVideoOutputs
 , BYREF pppOPMVideoOutputArray AS ANY _                ' __deref_out_ecount(*pulNumVideoOutputs) IOPMVideoOutput*** pppOPMVideoOutputArray
 ) AS LONG                                              ' HRESULT

'#ifndef DO_NOT_USE_DIRECTX_OR_DXVA2
DECLARE FUNCTION OPMGetVideoOutputsFromIDirect3DDevice9Object IMPORT "Dxva2.dll" ALIAS "OPMGetVideoOutputsFromIDirect3DDevice9Object" ( _
   BYVAL pDirect3DDevice9 AS IDirect3DDevice9 _         ' __in IDirect3DDevice9* pDirect3DDevice9
 , BYVAL vos AS LONG _                                  ' __in OPM_VIDEO_OUTPUT_SEMANTICS vos
 , BYREF pulNumVideoOutputs AS DWORD _                  ' __out ULONG* pulNumVideoOutputs
 , BYREF pppOPMVideoOutputArray AS ANY _                ' __deref_out_ecount(*pulNumVideoOutputs) IOPMVideoOutput*** pppOPMVideoOutputArray
 ) AS LONG                                              ' HRESULT
'#endif // DO_NOT_USE_DIRECTX_OR_DXVA2
'#pragma pack( pop )
