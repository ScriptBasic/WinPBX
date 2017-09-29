' ########################################################################################
' Microsoft Windows
' File: DeviceTopology.inc
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DEVICETOPOLOGY_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"

$CLSID_DeviceTopology = GUID$("{1DF639D0-5EC1-47AA-9379-828DC1AA8C59}")

'#define E_NOTFOUND HRESULT_FROM_WIN32(ERROR_NOT_FOUND)
%E_NOTFOUND = -2147023728&

'//
'//   Flag for clients of IControlChangeNotify::OnNotify to allow those clients to identify hardware initiated notifications
'//
$DEVTOPO_HARDWARE_INITIATED_EVENTCONTEXT = "draH"

'/* E2C2E9DE-09B1-4B04-84E5-07931225EE04 */
'DEFINE_GUID(EVENTCONTEXT_VOLUMESLIDER, 0xE2C2E9DE,0x09B1,0x4B04,0x84, 0xE5, 0x07, 0x93, 0x12, 0x25, 0xEE, 0x04);
$EVENTCONTEXT_VOLUMESLIDER = GUID$("{E2C2E9DE-09B1-4B04-84E5-07931225EE04}")

'#define _IKsControl_
'#include "ks.h"
'#include "ksmedia.h"

'#ifndef _KS_
' // Size = 64 bytes
TYPE KSDATAFORMAT DWORD
   FormatSize  AS DWORD   ' ULONG
   Flags       AS DWORD   ' ULONG
   SampleSize  AS DWORD   ' ULONG
   Reserved    AS DWORD   ' ULONG
   MajorFormat AS GUID    ' GUID
   SubFormat   AS GUID    ' GUID
   Specifier   AS GUID    ' GUID
END TYPE

'typedef /* [public][public][public][public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_devicetopology_0000_0000_0002
'    {
'    union
'        {
'        struct
'            {
'            GUID Set;
'            ULONG Id;
'            ULONG Flags;
'            }    ;
'        LONGLONG Alignment;
'        }    ;
'    }    KSIDENTIFIER;

' // Size = 24 bytes
TYPE KSIDENTIFIER_STRUCT DWORD
   Set   AS GUID    ' GUID
   Id    AS DWORD   ' ULONG
   Flags AS DWORD   ' ULONG
END TYPE

' // Size = 24 bytes
UNION KSIDENTIFIER DWORD
   KSIDENTIFIER_STRUCT
   Alignment AS QUAD
END UNION

'typedef struct __MIDL___MIDL_itf_devicetopology_0000_0000_0002 *PKSIDENTIFIER;

'typedef KSIDENTIFIER KSPROPERTY;
'typedef KSIDENTIFIER *PKSPROPERTY;
'typedef KSIDENTIFIER KSMETHOD;
'typedef KSIDENTIFIER *PKSMETHOD;
'typedef KSIDENTIFIER KSEVENT;
'typedef KSIDENTIFIER *PKSEVENT;

' *** Removed in the Windows 7 SDK ***
' EChannelMapping enum
'%ePcxChanMap_FL_FR   = 0
'%ePcxChanMap_FC_LFE  = %ePcxChanMap_FL_FR   + 1
'%ePcxChanMap_BL_BR   = %ePcxChanMap_FC_LFE  + 1
'%ePcxChanMap_FLC_FRC = %ePcxChanMap_BL_BR   + 1
'%ePcxChanMap_SL_SR   = %ePcxChanMap_FLC_FRC + 1
'%ePcxChanMap_Unknown = %ePcxChanMap_SL_SR   + 1

' EPcxConnectionType enum
%eConnTypeUnknown               = 0
%eConnType3Point5mm             = %eConnTypeUnknown               + 1
%eConnTypeQuarter               = %eConnType3Point5mm             + 1
%eConnTypeAtapiInternal         = %eConnTypeQuarter               + 1
%eConnTypeRCA                   = %eConnTypeAtapiInternal         + 1
%eConnTypeOptical               = %eConnTypeRCA                   + 1
%eConnTypeOtherDigital          = %eConnTypeOptical               + 1
%eConnTypeOtherAnalog           = %eConnTypeOtherDigital          + 1
%eConnTypeMultichannelAnalogDIN = %eConnTypeOtherAnalog           + 1
%eConnTypeXlrProfessional       = %eConnTypeMultichannelAnalogDIN + 1
%eConnTypeRJ11Modem             = %eConnTypeXlrProfessional       + 1
%eConnTypeCombination           = %eConnTypeRJ11Modem             + 1

' EPcxGeoLocation enum
%eGeoLocRear             = &H1
%eGeoLocFront            = %eGeoLocRear             + 1
%eGeoLocLeft             = %eGeoLocFront            + 1
%eGeoLocRight            = %eGeoLocLeft             + 1
%eGeoLocTop              = %eGeoLocRight            + 1
%eGeoLocBottom           = %eGeoLocTop              + 1
%eGeoLocRearPanel        = %eGeoLocBottom           + 1
%eGeoLocRiser            = %eGeoLocRearPanel        + 1
%eGeoLocInsideMobileLid  = %eGeoLocRiser            + 1
%eGeoLocDrivebay         = %eGeoLocInsideMobileLid  + 1
%eGeoLocHDMI             = %eGeoLocDrivebay         + 1
%eGeoLocOutsideMobileLid = %eGeoLocHDMI             + 1
%eGeoLocATAPI            = %eGeoLocOutsideMobileLid + 1
%eGeoLocReserved5        = %eGeoLocATAPI            + 1
%eGeoLocReserved6        = %eGeoLocReserved5        + 1

' EPcxGenLocation enum
%eGenLocPrimaryBox = 0
%eGenLocInternal   = %eGenLocPrimaryBox + 1
%eGenLocSeparate   = %eGenLocInternal   + 1
%eGenLocOther      = %eGenLocSeparate   + 1

' EPxcPortConnection enum
%ePortConnJack                  = 0
%ePortConnIntegratedDevice      = %ePortConnJack                  + 1
%ePortConnBothIntegratedAndJack = %ePortConnIntegratedDevice      + 1
%ePortConnUnknown               = %ePortConnBothIntegratedAndJack + 1

' // Size = 28 bytes
TYPE KSJACK_DESCRIPTION DWORD
   ChannelMapping AS DWORD   ' DWORD
   Color          AS DWORD   ' COLORREF
   ConnectionType AS LONG    ' EPcxConnectionType
   GeoLocation    AS LONG    ' EPcxGeoLocation
   GenLocation    AS LONG    ' EPcxGenLocation
   PortConnection AS LONG    ' EPxcPortConnection
   IsConnected    AS LONG    ' BOOL
END TYPE

'typedef struct __MIDL___MIDL_itf_devicetopology_0000_0000_0010 *PKSJACK_DESCRIPTION;

#IF NOT %DEF(%LUID_DEFINED)
%LUID_DEFINED = 1
' // Size = 8 bytes
TYPE LUID_STRUCT DWORD
  LowPart  AS DWORD
  HighPart AS LONG
END TYPE
UNION LUID
   LUID_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF

'typedef struct _LUID *PLUID;

' enum KSJACK_SINK_CONNECTIONTYPE
%KSJACK_SINK_CONNECTIONTYPE_HDMI        = 0
%KSJACK_SINK_CONNECTIONTYPE_DISPLAYPORT = %KSJACK_SINK_CONNECTIONTYPE_HDMI + 1

' // Size = 96 bytes
TYPE KSJACK_SINK_INFORMATION DWORD FILL
   ConnType              AS LONG            ' KSJACK_SINK_CONNECTIONTYPE
   ManufacturerId        AS WORD            ' WORD
   ProductId             AS WORD            ' WORD
   AudioLatency          AS WORD            ' WORD
   HDCPCapable           AS LONG            ' BOOL
   AICapable             AS LONG            ' BOOL
   SinkDescriptionLength AS BYTE            ' UCHAR
   SinkDescription       AS WSTRINGZ * 32   ' WCHAR
   PortId                AS QUAD            ' LUID
END TYPE

' // Size = 8 bytes
TYPE KSJACK_DESCRIPTION2 DWORD
   DeviceStateInfo  AS DWORD   ' DWORD
   JackCapabilities AS DWORD   ' DWORD
END TYPE

'typedef struct _tagKSJACK_DESCRIPTION2 *PKSJACK_DESCRIPTION2;

'#endif

'typedef /* [public][public] */
'enum __MIDL___MIDL_itf_devicetopology_0000_0000_0011
'   {  In   = 0,
'      Out   = ( In + 1 )
'   }   DataFlow;

' DataFlow enum
%DataFlow_In  = 0
%DataFlow_Out = %DataFlow_In + 1

' PartType enum
%PartType_Connector = 0
%PartType_Subunit   = %PartType_Connector + 1

' *** Removed in the Windows 7 SDK ***
'%PARTTYPE_FLAG_CONNECTOR = &H00010000???
'%PARTTYPE_FLAG_SUBUNIT   = &H00020000???
'%PARTTYPE_MASK           = &H00030000???
'%PARTID_MASK             = &H0000ffff???

' ConnectorType enum
%ConnectorType_Unknown_Connector = 0
%ConnectorType_Physical_Internal = %ConnectorType_Unknown_Connector + 1
%ConnectorType_Physical_External = %ConnectorType_Physical_Internal + 1
%ConnectorType_Software_IO       = %ConnectorType_Physical_External + 1
%ConnectorType_Software_Fixed    = %ConnectorType_Software_IO       + 1
%ConnectorType_Network           = %ConnectorType_Software_Fixed    + 1


' ########################################################################################
' Interface name = IKsControl
' IID = 28F54685-06FD-11D2-B27A-00A0C9223196
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsControl_INTERFACE_DEFINED)
    %IKsControl_INTERFACE_DEFINED = 1

$IID_IKsControl = GUID$("{28F54685-06FD-11D2-B27A-00A0C9223196}")

INTERFACE IKsControl $IID_IKsControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD KsProperty ( _                                ' VTable offset = 12
     BYREF Property AS KSIDENTIFIER _                   ' __in PKSPROPERTY Property
   , BYVAL PropertyLength AS DWORD _                    ' __in ULONG PropertyLength
   , BYVAL PropertyData AS DWORD _                      ' __inout void *PropertyData
   , BYVAL DataLength AS DWORD _                        ' __in ULONG DataLength
   , BYREF BytesReturned AS DWORD _                     ' __out ULONG *BytesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KsMethod ( _                                  ' VTable offset = 16
     BYREF Method AS KSIDENTIFIER _                     ' __in PKSMETHOD Method
   , BYVAL MethodLength AS DWORD _                      ' __in ULONG MethodLength
   , BYVAL MethodData AS DWORD _                        ' __inout void *MethodData
   , BYVAL DataLength AS DWORD _                        ' __in ULONG DataLength
   , BYREF BytesReturned AS DWORD _                     ' __out ULONG *BytesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KsEvent ( _                                   ' VTable offset = 20
     BYREF Event AS KSIDENTIFIER _                      ' __in PKSEVENT Event
   , BYVAL EventLength AS DWORD _                       ' __in ULONG EventLength
   , BYVAL EventData AS DWORD _                         ' __inout void *EventData
   , BYVAL DataLength AS DWORD _                        ' __in ULONG DataLength
   , BYREF BytesReturned AS DWORD _                     ' __out ULONG *BytesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPerChannelDbLevel
' IID = C2F8E001-F205-4BC9-99BC-C13B1E048CCB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPerChannelDbLevel_INTERFACE_DEFINED)
    %IPerChannelDbLevel_INTERFACE_DEFINED = 1

$IID_IPerChannelDbLevel = GUID$("{C2F8E001-F205-4BC9-99BC-C13B1E048CCB}")

INTERFACE IPerChannelDbLevel $IID_IPerChannelDbLevel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pcChannels AS DWORD _                        ' __out UINT *pcChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevelRange ( _                             ' VTable offset = 16
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfMinLevelDB AS SINGLE _                     ' __out float *pfMinLevelDB
   , BYREF pfMaxLevelDB AS SINGLE _                     ' __out float *pfMaxLevelDB
   , BYREF pfStepping AS SINGLE _                       ' __out float *pfStepping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 20
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevel ( _                                  ' VTable offset = 24
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelUniform ( _                           ' VTable offset = 28
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelAllChannels ( _                       ' VTable offset = 32
     BYREF aLevelsDB AS SINGLE _                        ' __in ecount(cChannels)  float aLevelsDB[  ]
   , BYVAL cChannels AS DWORD _                         ' __in ULONG cChannels
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPerChannelDbLevel_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioVolumeLevel
' IID = 7FB7B48F-531D-44A2-BCB3-5AD5A134B3DC
' Inherited interface = IPerChannelDbLevel
' ########################################################################################

#IF NOT %DEF(%IAudioVolumeLevel_INTERFACE_DEFINED)
    %IAudioVolumeLevel_INTERFACE_DEFINED = 1

$IID_IAudioVolumeLevel = GUID$("{7FB7B48F-531D-44A2-BCB3-5AD5A134B3DC}")

INTERFACE IAudioVolumeLevel $IID_IAudioVolumeLevel

   INHERIT IUnknown

   ' =====================================================================================
   ' IPerChannelDbLevel methods
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pcChannels AS DWORD _                        ' __out UINT *pcChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevelRange ( _                             ' VTable offset = 16
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfMinLevelDB AS SINGLE _                     ' __out float *pfMinLevelDB
   , BYREF pfMaxLevelDB AS SINGLE _                     ' __out float *pfMaxLevelDB
   , BYREF pfStepping AS SINGLE _                       ' __out float *pfStepping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 20
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevel ( _                                  ' VTable offset = 24
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelUniform ( _                           ' VTable offset = 28
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelAllChannels ( _                       ' VTable offset = 32
     BYREF aLevelsDB AS SINGLE _                        ' __in ecount(cChannels)  float aLevelsDB[  ]
   , BYVAL cChannels AS DWORD _                         ' __in ULONG cChannels
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioVolumeLevel_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioChannelConfig
' IID = BB11C46F-EC28-493C-B88A-5DB88062CE98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioChannelConfig_INTERFACE_DEFINED)
    %IAudioChannelConfig_INTERFACE_DEFINED = 1

$IID_IAudioChannelConfig = GUID$("{BB11C46F-EC28-493C-B88A-5DB88062CE98}")

INTERFACE IAudioChannelConfig $IID_IAudioChannelConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetChannelConfig ( _                          ' VTable offset = 12
     BYVAL dwConfig AS DWORD _                          ' __in DWORD dwConfig
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelConfig ( _                          ' VTable offset = 16
     BYREF pdwConfig AS DWORD _                         ' __retval_out DWORD *pdwConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioChannelConfig_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioLoudness
' IID = 7D8B1437-DD53-4350-9C1B-1EE2890BD938
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioLoudness_INTERFACE_DEFINED)
    %IAudioLoudness_INTERFACE_DEFINED = 1

$IID_IAudioLoudness = GUID$("{7D8B1437-DD53-4350-9C1B-1EE2890BD938}")

INTERFACE IAudioLoudness $IID_IAudioLoudness

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEnabled ( _                                ' VTable offset = 12
     BYREF pbEnabled AS LONG _                          ' __out BOOL *pbEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEnabled ( _                                ' VTable offset = 16
     BYVAL bEnable AS LONG _                            ' __in BOOL bEnable
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioLoudness_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioInputSelector
' IID = 4F03DC02-5E6E-4653-8F72-A030C123D598
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioInputSelector_INTERFACE_DEFINED)
    %IAudioInputSelector_INTERFACE_DEFINED = 1

$IID_IAudioInputSelector = GUID$("{4F03DC02-5E6E-4653-8F72-A030C123D598}")

INTERFACE IAudioInputSelector $IID_IAudioInputSelector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 12
     BYREF pnIdSelected AS DWORD _                      ' __out UINT *pnIdSelected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelection ( _                              ' VTable offset = 16
     BYVAL nIdSelect AS DWORD _                         ' __in UINT nIdSelect
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioInputSelector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioOutputSelector
' IID = BB515F69-94A7-429E-8B9C-271B3F11A3AB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioOutputSelector_INTERFACE_DEFINED)
    %IAudioOutputSelector_INTERFACE_DEFINED = 1

$IID_IAudioOutputSelector = GUID$("{BB515F69-94A7-429E-8B9C-271B3F11A3AB}")

INTERFACE IAudioOutputSelector $IID_IAudioOutputSelector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 12
     BYREF pnIdSelected AS DWORD _                      ' __out UINT *pnIdSelected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelection ( _                              ' VTable offset = 16
     BYVAL nIdSelect AS DWORD _                         ' __in UINT nIdSelect
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioOutputSelector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioMute
' IID = DF45AEEA-B74A-4B6B-AFAD-2366B6AA012E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioMute_INTERFACE_DEFINED)
    %IAudioMute_INTERFACE_DEFINED = 1

$IID_IAudioMute = GUID$("{DF45AEEA-B74A-4B6B-AFAD-2366B6AA012E}")

INTERFACE IAudioMute $IID_IAudioMute

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMute ( _                                   ' VTable offset = 12
     BYVAL bMuted AS LONG _                             ' __in BOOL bMuted
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMute ( _                                   ' VTable offset = 16
     BYREF pbMuted AS LONG _                            ' __out BOOL *pbMuted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioMute_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioBass
' IID = A2B1A1D9-4DB3-425D-A2B2-BD335CB3E2E5
' Inherited interface = IPerChannelDbLevel
' ########################################################################################

#IF NOT %DEF(%IAudioBass_INTERFACE_DEFINED)
    %IAudioBass_INTERFACE_DEFINED = 1

$IID_IAudioBass = GUID$("{A2B1A1D9-4DB3-425D-A2B2-BD335CB3E2E5}")

INTERFACE IAudioBass $IID_IAudioBass

   INHERIT IUnknown

   ' =====================================================================================
   ' IPerChannelDbLevel methods
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pcChannels AS DWORD _                        ' __out UINT *pcChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevelRange ( _                             ' VTable offset = 16
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfMinLevelDB AS SINGLE _                     ' __out float *pfMinLevelDB
   , BYREF pfMaxLevelDB AS SINGLE _                     ' __out float *pfMaxLevelDB
   , BYREF pfStepping AS SINGLE _                       ' __out float *pfStepping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 20
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevel ( _                                  ' VTable offset = 24
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelUniform ( _                           ' VTable offset = 28
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelAllChannels ( _                       ' VTable offset = 32
     BYREF aLevelsDB AS SINGLE _                        ' __in ecount(cChannels)  float aLevelsDB[  ]
   , BYVAL cChannels AS DWORD _                         ' __in ULONG cChannels
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioBass_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioMidrange
' IID = 5E54B6D7-B44B-40D9-9A9E-E691D9CE6EDF
' Inherited interface = IPerChannelDbLevel
' ########################################################################################

#IF NOT %DEF(%IAudioMidrange_INTERFACE_DEFINED)
    %IAudioMidrange_INTERFACE_DEFINED = 1

$IID_IAudioMidrange = GUID$("{5E54B6D7-B44B-40D9-9A9E-E691D9CE6EDF}")

INTERFACE IAudioMidrange $IID_IAudioMidrange

   INHERIT IUnknown

   ' =====================================================================================
   ' IPerChannelDbLevel methods
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pcChannels AS DWORD _                        ' __out UINT *pcChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevelRange ( _                             ' VTable offset = 16
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfMinLevelDB AS SINGLE _                     ' __out float *pfMinLevelDB
   , BYREF pfMaxLevelDB AS SINGLE _                     ' __out float *pfMaxLevelDB
   , BYREF pfStepping AS SINGLE _                       ' __out float *pfStepping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 20
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevel ( _                                  ' VTable offset = 24
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelUniform ( _                           ' VTable offset = 28
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelAllChannels ( _                       ' VTable offset = 32
     BYREF aLevelsDB AS SINGLE _                        ' __in ecount(cChannels)  float aLevelsDB[  ]
   , BYVAL cChannels AS DWORD _                         ' __in ULONG cChannels
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioMidrange_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioTreble
' IID = 0A717812-694E-4907-B74B-BAFA5CFDCA7B
' Inherited interface = IPerChannelDbLevel
' ########################################################################################

#IF NOT %DEF(%IAudioTreble_INTERFACE_DEFINED)
    %IAudioTreble_INTERFACE_DEFINED = 1

$IID_IAudioTreble = GUID$("{0A717812-694E-4907-B74B-BAFA5CFDCA7B}")

INTERFACE IAudioTreble $IID_IAudioTreble

   INHERIT IUnknown

   ' =====================================================================================
   ' IPerChannelDbLevel methods
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pcChannels AS DWORD _                        ' __out UINT *pcChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevelRange ( _                             ' VTable offset = 16
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfMinLevelDB AS SINGLE _                     ' __out float *pfMinLevelDB
   , BYREF pfMaxLevelDB AS SINGLE _                     ' __out float *pfMaxLevelDB
   , BYREF pfStepping AS SINGLE _                       ' __out float *pfStepping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 20
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevel ( _                                  ' VTable offset = 24
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelUniform ( _                           ' VTable offset = 28
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLevelAllChannels ( _                       ' VTable offset = 32
     BYREF aLevelsDB AS SINGLE _                        ' __in ecount(cChannels)  float aLevelsDB[  ]
   , BYVAL cChannels AS DWORD _                         ' __in ULONG cChannels
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioTreble_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioAutoGainControl
' IID = 85401FD4-6DE4-4B9D-9869-2D6753A82F3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioAutoGainControl_INTERFACE_DEFINED)
    %IAudioAutoGainControl_INTERFACE_DEFINED = 1

$IID_IAudioAutoGainControl = GUID$("{85401FD4-6DE4-4B9D-9869-2D6753A82F3C}")

INTERFACE IAudioAutoGainControl $IID_IAudioAutoGainControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEnabled ( _                                ' VTable offset = 12
     BYREF pbEnabled AS LONG _                          ' __out BOOL *pbEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEnabled ( _                                ' VTable offset = 16
     BYVAL bEnable AS LONG _                            ' __in BOOL bEnable
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioAutoGainControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioPeakMeter
' IID = DD79923C-0599-45E0-B8B6-C8DF7DB6E796
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioPeakMeter_INTERFACE_DEFINED)
    %IAudioPeakMeter_INTERFACE_DEFINED = 1

$IID_IAudioPeakMeter = GUID$("{DD79923C-0599-45E0-B8B6-C8DF7DB6E796}")

INTERFACE IAudioPeakMeter $IID_IAudioPeakMeter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pcChannels AS DWORD _                        ' __out UINT *pcChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 16
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioPeakMeter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceSpecificProperty
' IID = 3B22BCBF-2586-4AF0-8583-205D391B807C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDeviceSpecificProperty_INTERFACE_DEFINED)
    %IDeviceSpecificProperty_INTERFACE_DEFINED = 1

$IID_IDeviceSpecificProperty = GUID$("{3B22BCBF-2586-4AF0-8583-205D391B807C}")

INTERFACE IDeviceSpecificProperty $IID_IDeviceSpecificProperty

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pVType AS WORD _                             ' __out VARTYPE *pVType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 16
     BYREF pvValue AS DWORD _                           ' __out void *pvValue
   , BYREF pcbValue AS DWORD _                          ' __inout DWORD *pcbValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 20
     BYVAL pvValue AS DWORD _                           ' __in void *pvValue
   , BYVAL cbValue AS DWORD _                           ' __in DWORD cbValue
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get4BRange ( _                                ' VTable offset = 24
     BYREF plMin AS LONG _                              ' __out LONG *plMin
   , BYREF plMax AS LONG _                              ' __out LONG *plMax
   , BYREF plStepping AS LONG _                         ' __out LONG *plStepping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeviceSpecificProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IKsFormatSupport
' IID = 3CB4A69D-BB6F-4D2B-95B7-452D2C155DB5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsFormatSupport_INTERFACE_DEFINED)
    %IKsFormatSupport_INTERFACE_DEFINED = 1

$IID_IKsFormatSupport = GUID$("{3CB4A69D-BB6F-4D2B-95B7-452D2C155DB5}")

INTERFACE IKsFormatSupport $IID_IKsFormatSupport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsFormatSupported ( _                         ' VTable offset = 12
     BYREF pKsFormat AS KSDATAFORMAT _                  ' __in PKSDATAFORMAT pKsFormat
   , BYVAL cbFormat AS DWORD _                          ' __in DWORD cbFormat
   , BYREF pbSupported AS LONG _                        ' __out BOOL *pbSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevicePreferredFormat ( _                  ' VTable offset = 16
     BYREF ppKsFormat AS KSDATAFORMAT _                 ' __out PKSDATAFORMAT *ppKsFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsFormatSupport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IKsJackDescription
' IID = 4509F757-2D46-4637-8E62-CE7DB944F57B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsJackDescription_INTERFACE_DEFINED)
    %IKsJackDescription_INTERFACE_DEFINED = 1

$IID_IKsJackDescription = GUID$("{4509F757-2D46-4637-8E62-CE7DB944F57B}")

INTERFACE IKsJackDescription $IID_IKsJackDescription

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetJackCount ( _                              ' VTable offset = 12
     BYREF pcJacks AS DWORD _                           ' __out UINT *pcJacks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJackDescription ( _                        ' VTable offset = 16
     BYVAL nJack AS DWORD _                             ' __in UINT nJack
   , BYREF pDescription AS KSJACK_DESCRIPTION _         ' __out KSJACK_DESCRIPTION *pDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsJackDescription_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IKsJackDescription2
' IID = 478F3A9B-E0C9-4827-9228-6F5505FFE76A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsJackDescription2_INTERFACE_DEFINED)
    %IKsJackDescription2_INTERFACE_DEFINED = 1

$IID_IKsJackDescription2 = GUID$("{478F3A9B-E0C9-4827-9228-6F5505FFE76A}")

INTERFACE IKsJackDescription2 $IID_IKsJackDescription2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetJackCount ( _                              ' VTable offset = 12
     BYREF pcJacks AS DWORD _                           ' __out UINT *pcJacks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJackDescription2 ( _                       ' VTable offset = 16
     BYVAL nJack AS DWORD _                             ' __in UINT nJack
   , BYREF pDescription AS KSJACK_DESCRIPTION2 _        ' __out KSJACK_DESCRIPTION2 *pDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsJackDescription2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IKsJackSinkInformation
' IID = D9BD72ED-290F-4581-9FF3-61027A8FE532
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsJackSinkInformation_INTERFACE_DEFINED)
    %IKsJackSinkInformation_INTERFACE_DEFINED = 1

$IID_IKsJackSinkInformation = GUID$("{D9BD72ED-290F-4581-9FF3-61027A8FE532}")

INTERFACE IKsJackSinkInformation $IID_IKsJackSinkInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetJackSinkInformation ( _                    ' VTable offset = 12
     BYREF pJackSinkInformation AS KSJACK_SINK_INFORMATION _ ' __out  KSJACK_SINK_INFORMATION *pJackSinkInformation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsJackSinkInformation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPartsList
' IID = 6DAA848C-5EB0-45CC-AEA5-998A2CDA1FFB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPartsList_INTERFACE_DEFINED)
    %IPartsList_INTERFACE_DEFINED = 1

$IID_IPartsList = GUID$("{6DAA848C-5EB0-45CC-AEA5-998A2CDA1FFB}")

INTERFACE IPartsList $IID_IPartsList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPart ( _                                   ' VTable offset = 16
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppPart AS IPart _                            ' __out IPart **ppPart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPartsList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPart
' IID = AE2DE0E4-5BCA-4F2D-AA46-5D13F8FDB3A9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPart_INTERFACE_DEFINED)
    %IPart_INTERFACE_DEFINED = 1

$IID_IPart = GUID$("{AE2DE0E4-5BCA-4F2D-AA46-5D13F8FDB3A9}")

INTERFACE IPart $IID_IPart

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF ppwstrName AS DWORD _                        ' __out LPWSTR *ppwstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalId ( _                                ' VTable offset = 16
     BYREF pnId AS DWORD _                              ' __out UINT *pnId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlobalId ( _                               ' VTable offset = 20
     BYREF ppwstrGlobalId AS DWORD _                    ' __out LPWSTR *ppwstrGlobalId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPartType ( _                               ' VTable offset = 24
     BYREF pPartType AS LONG _                          ' __out PartType *pPartType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubType ( _                                ' VTable offset = 28
     BYREF pSubType AS GUID _                           ' __out GUID *pSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlInterfaceCount ( _                  ' VTable offset = 32
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlInterface ( _                       ' VTable offset = 36
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppInterfaceDesc AS IControlInterface _       ' __out IControlInterface **ppInterfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumPartsIncoming ( _                         ' VTable offset = 40
     BYREF ppParts AS IPartsList _                      ' __out IPartsList **ppParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumPartsOutgoing ( _                         ' VTable offset = 44
     BYREF ppParts AS IPartsList _                      ' __out IPartsList **ppParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTopologyObject ( _                         ' VTable offset = 48
     BYREF ppTopology AS IDeviceTopology _              ' __out IDeviceTopology **ppTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 52
     BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF refiid AS GUID _                             ' __in REFIID refiid
   , BYREF ppvObject AS IUnknown _                      ' __inout void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterControlChangeCallback ( _             ' VTable offset = 56
     BYREF riid AS GUID _                               ' __in REFGUID riid
   , BYVAL pNotify AS IControlChangeNotify _            ' __in IControlChangeNotify *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterControlChangeCallback ( _           ' VTable offset = 60
     BYVAL pNotify AS IControlChangeNotify _            ' __in IControlChangeNotify *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPart_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IConnector
' IID = 9C2C4058-23F5-41DE-877A-DF3AF236A09E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConnector_INTERFACE_DEFINED)
    %IConnector_INTERFACE_DEFINED = 1

$IID_IConnector = GUID$("{9C2C4058-23F5-41DE-877A-DF3AF236A09E}")

INTERFACE IConnector $IID_IConnector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS LONG _                              ' __out ConnectorType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataFlow ( _                               ' VTable offset = 16
     BYREF pFlow AS LONG _                              ' __out DataFlow *pFlow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectTo ( _                                 ' VTable offset = 20
     BYVAL pConnectTo AS IConnector _                   ' __in IConnector *pConnectTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
     BYREF pbConnected AS LONG _                        ' __out BOOL *pbConnected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectedTo ( _                            ' VTable offset = 32
     BYREF ppConTo AS IConnector _                      ' __out IConnector **ppConTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectorIdConnectedTo ( _                 ' VTable offset = 36
     BYREF ppwstrConnectorId AS DWORD _                 ' __out LPWSTR *ppwstrConnectorId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIdConnectedTo ( _                    ' VTable offset = 40
     BYREF ppwstrDeviceId AS DWORD _                    ' __out LPWSTR *ppwstrDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISubunit
' IID = 82149A85-DBA6-4487-86BB-EA8F7FEFCC71
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISubunit_INTERFACE_DEFINED)
    %ISubunit_INTERFACE_DEFINED = 1

$IID_ISubunit = GUID$("{82149A85-DBA6-4487-86BB-EA8F7FEFCC71}")

INTERFACE ISubunit $IID_ISubunit

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __ISubunit_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IControlInterface
' IID = 45D37C3F-5140-444A-AE24-400789F3CBF3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IControlInterface_INTERFACE_DEFINED)
    %IControlInterface_INTERFACE_DEFINED = 1

$IID_IControlInterface = GUID$("{45D37C3F-5140-444A-AE24-400789F3CBF3}")

INTERFACE IControlInterface $IID_IControlInterface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF ppwstrName AS DWORD _                        ' __out LPWSTR *ppwstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIID ( _                                    ' VTable offset = 16
     BYREF pIID AS GUID _                               ' __out GUID *pIID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IControlInterface_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IControlChangeNotify
' IID = A09513ED-C709-4D21-BD7B-5F34C47F3947
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IControlChangeNotify_INTERFACE_DEFINED)
    %IControlChangeNotify_INTERFACE_DEFINED = 1

$IID_IControlChangeNotify = GUID$("{A09513ED-C709-4D21-BD7B-5F34C47F3947}")

INTERFACE IControlChangeNotify $IID_IControlChangeNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNotify ( _                                  ' VTable offset = 12
     BYVAL dwSenderProcessId AS DWORD _                 ' __in DWORD dwSenderProcessId
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IControlChangeNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceTopology
' IID = 2A07407E-6497-4A18-9787-32F79BD0D98F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDeviceTopology_INTERFACE_DEFINED)
    %IDeviceTopology_INTERFACE_DEFINED = 1

$IID_IDeviceTopology = GUID$("{2A07407E-6497-4A18-9787-32F79BD0D98F}")

INTERFACE IDeviceTopology $IID_IDeviceTopology

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetConnectorCount ( _                         ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnector ( _                              ' VTable offset = 16
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppConnector AS IConnector _                  ' __out IConnector **ppConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubunitCount ( _                           ' VTable offset = 20
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubunit ( _                                ' VTable offset = 20
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppSubunit AS ISubunit _                      ' __out ISubunit **ppSubunit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPartById ( _                               ' VTable offset = 24
     BYVAL nId AS DWORD _                               ' __in UINT nId
   , BYREF ppPart AS IPart _                            ' __out IPart **ppPart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceId ( _                               ' VTable offset = 28
     BYREF ppwstrDeviceId AS DWORD _                    ' __out LPWSTR *ppwstrDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignalPath ( _                             ' VTable offset = 32
     BYVAL pIPartFrom AS IPart _                        ' __in IPart *pIPartFrom
   , BYVAL pIPartTo AS IPart _                          ' __in IPart *pIPartTo
   , BYVAL bRejectMixedPaths AS LONG _                  ' __in BOOL bRejectMixedPaths
   , BYREF ppParts AS IPartsList _                      ' __out IPartsList **ppParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeviceTopology_INTERFACE_DEFINED__ */
