' ########################################################################################
' Microsoft Windows
' File: BDATypes.inc
' Contents: Typedefs and enums needed by both the WDM drivers and the user mode COM interfaces.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BDATYPES_INC = 1

%MIN_DIMENSION = 1

'//===========================================================================
'//
'//  BDA Topology Structures
'//
'//===========================================================================

' // Size = 16 bytes
' The BDA_TEMPLATE_CONNECTION structure describes the template for a BDA connection in
' terms of where it begins and ends.

' // Size = 16 bytes
TYPE BDA_TEMPLATE_CONNECTION DWORD
   FromNodeType    AS DWORD   ' ULONG
   FromNodePinType AS DWORD   ' ULONG
   ToNodeType      AS DWORD   ' ULONG
   ToNodePinType   AS DWORD   ' ULONG
END TYPE


' // Size = 8 bytes
' The BDA_TEMPLATE_PIN_JOINT structure describes a joint in a template topology.
TYPE BDA_TEMPLATE_PIN_JOINT DWORD
   uliTemplateConnection AS DWORD   ' ULONG
   ulcInstancesMax       AS DWORD   ' ULONG
END TYPE

'//===========================================================================
'//
'//  BDA Events
'//
'//===========================================================================

'//  In-band Event IDs
'//
' ENUM BDA_EVENT_ID
MACRO BDA_EVENT_ID_ENUM = LONG
%BDA_EVENT_SIGNAL_LOSS               = 0
%BDA_EVENT_SIGNAL_LOCK               = 1
%BDA_EVENT_DATA_START                = 2
%BDA_EVENT_DATA_STOP                 = 3
%BDA_EVENT_CHANNEL_ACQUIRED          = 4
%BDA_EVENT_CHANNEL_LOST              = 5
%BDA_EVENT_CHANNEL_SOURCE_CHANGED    = 6
%BDA_EVENT_CHANNEL_ACTIVATED         = 7
%BDA_EVENT_CHANNEL_DEACTIVATED       = 8
%BDA_EVENT_SUBCHANNEL_ACQUIRED       = 9
%BDA_EVENT_SUBCHANNEL_LOST           = 10
%BDA_EVENT_SUBCHANNEL_SOURCE_CHANGED = 11
%BDA_EVENT_SUBCHANNEL_ACTIVATED      = 12
%BDA_EVENT_SUBCHANNEL_DEACTIVATED    = 13
%BDA_EVENT_ACCESS_GRANTED            = 14
%BDA_EVENT_ACCESS_DENIED             = 15
%BDA_EVENT_OFFER_EXTENDED            = 16
%BDA_EVENT_PURCHASE_COMPLETED        = 17
%BDA_EVENT_SMART_CARD_INSERTED       = 18
%BDA_EVENT_SMART_CARD_REMOVE         = 19

'//===========================================================================
'//
'//  KSSTREAM_HEADER extensions for BDA
'//
'//===========================================================================

' // Size = 24 bytes
' The KS_BDA_FRAME_INFO structure describes BDA extensions to the KSSTREAM_HEADER
' structure, which describes a packet of data to be read from or written to a streaming
' driver pin.

' // Size = 24 bytes
TYPE KS_BDA_FRAME_INFO DWORD
   ExtendedHeaderSize AS DWORD   ' ULONG / / Size of this extended header
   dwFrameFlags       AS DWORD   ' DWORD
   ulEvent            AS DWORD   ' ULONG
   ulChannelNumber    AS DWORD   ' ULONG
   ulSubchannelNumber AS DWORD   ' ULONG
   ulReason           AS DWORD   ' ULONG
END TYPE


'//------------------------------------------------------------
'//
'//  BDA Network Ethernet Filter Property Set
'//
'// {71985F43-1CA1-11d3-9CC8-00C04F7971E0}
'//

' // Size = 6 bytes
TYPE BDA_ETHERNET_ADDRESS BYTE
   rgbAddress(5) AS BYTE   ' BYTE[6]
END TYPE

' // Size = 12 bytes
TYPE BDA_ETHERNET_ADDRESS_LIST DWORD
   ulcAddresses                   AS DWORD                  ' ULONG
   rgAddressl(%MIN_DIMENSION - 1) AS BDA_ETHERNET_ADDRESS   ' BDA_ETHERNET_ADDRESS[MIN_DIMENSION]
END TYPE

' ENUM BDA_MULTICAST_MODE
MACRO BDA_MULTICAST_MODE_ENUM = LONG
%BDA_PROMISCUOUS_MULTICAST = 0
%BDA_FILTERED_MULTICAST    = 1
%BDA_NO_MULTICAST          = 2

'//------------------------------------------------------------
'//
'//  BDA Network IPv4 Filter Property Set
'//
'// {71985F44-1CA1-11d3-9CC8-00C04F7971E0}
'//

' // Size = 4 bytes
TYPE BDA_IPv4_ADDRESS BYTE
   rgbAddress(3) AS BYTE   ' BYTE[4]
END TYPE

' // Size = 8 bytes
TYPE BDA_IPv4_ADDRESS_LIST DWORD
   ulcAddresses                   AS DWORD              ' ULONG
   rgAddressl(%MIN_DIMENSION - 1) AS BDA_IPv4_ADDRESS   ' BDA_IPv4_ADDRESS[MIN_DIMENSION]
END TYPE

'//------------------------------------------------------------
'//
'//  BDA Network IPv4 Filter Property Set
'//
'// {E1785A74-2A23-4fb3-9245-A8F88017EF33}
'//

' // Size = 6 bytes
TYPE BDA_IPv6_ADDRESS BYTE
   rgbAddress(5) AS BYTE   ' BYTE[6]
END TYPE

' // Size = 12 bytes
TYPE BDA_IPv6_ADDRESS_LIST DWORD
   ulcAddresses                   AS DWORD              ' ULONG
   rgAddressl(%MIN_DIMENSION - 1) AS BDA_IPv6_ADDRESS   ' BDA_IPv6_ADDRESS[MIN_DIMENSION]
END TYPE

'//------------------------------------------------------------
'//
'//
'//  BDA Signal Property Set
'//
'//  {D2F1644B-B409-11d2-BC69-00A0C9EE9E16}
'//

' ENUM BDA_SIGNAL_STATE
MACRO BDA_SIGNAL_STATE_ENUM = LONG
%BDA_SIGNAL_UNAVAILABLE = 0
%BDA_SIGNAL_INACTIVE    = 1
%BDA_SIGNAL_ACTIVE      = 2

'//------------------------------------------------------------
'//
'//
'//  BDA Change Sync Method Set
'//
'// {FD0A5AF3-B41D-11d2-9C95-00C04F7971E0}
'//

' ENUM BDA_CHANGE_STATE
MACRO BDA_CHANGE_STATE_ENUM = LONG
%BDA_CHANGES_COMPLETE = 0
%BDA_CHANGES_PENDING  = 1

'//------------------------------------------------------------
'//
'//
'//  BDA Device Configuration Method Set
'//
'// {71985F45-1CA1-11d3-9CC8-00C04F7971E0}
'//


'//------------------------------------------------------------
'//
'//
'//  BDA Topology Property Set
'//
'// {A14EE835-0A23-11d3-9CC7-00C04F7971E0}
'//

' // Size = 36 bytes
TYPE BDANODE_DESCRIPTOR DWORD
   ulBdaNodeType AS DWORD  ' ULONG // The node type as it is used in the BDA template topology
   guidFunction  AS GUID   ' GUID  // GUID from BdaMedia.h describing the node's function (e.g. KSNODE_BDA_RF_TUNER)
   guidName      AS GUID   ' GUID  // GUID that can be use to look up a displayable name for the node.
END TYPE


'//------------------------------------------------------------
'//
'//
'//  BDA Void Transform Property Set
'//
'// {71985F46-1CA1-11d3-9CC8-00C04F7971E0}
'//


'//------------------------------------------------------------
'//
'//
'//  BDA Null Transform Property Set
'//
'// {DDF15B0D-BD25-11d2-9CA0-00C04F7971E0}
'//


'//------------------------------------------------------------
'//
'//
'//  BDA Frequency Filter Property Set
'//
'// {71985F47-1CA1-11d3-9CC8-00C04F7971E0}
'//


'//------------------------------------------------------------
'//
'//
'//  BDA Autodemodulate Property Set
'//
'// {DDF15B12-BD25-11d2-9CA0-00C04F7971E0}
'//


'//------------------------------------------------------------
'//
'//
'//  BDA Table Section Property Set
'//
'// {516B99C5-971C-4aaf-B3F3-D9FDA8A15E16}
'//

' // Size = 16 bytes
TYPE BDA_TABLE_SECTION DWORD
   ulPrimarySectionId                  AS DWORD   ' ULONG
   ulSecondarySectionId                AS DWORD   ' ULONG
   ulcbSectionLength                   AS DWORD   ' ULONG
   argbSectionData(%MIN_DIMENSION - 1) AS DWORD   ' ULONG[MIN_DIMENSION]
END TYPE

'//------------------------------------------------------------
'//
'//
'//  BDA Diseq Command Property Set
'//
'// {F84E2AB0-3C6B-45e3-A0FC-8669D4B81F11}
'//

' // Size = 16 bytes
TYPE BDA_DISEQC_SEND DWORD
   ulRequestId       AS DWORD   ' ULONG
   ulPacketLength    AS DWORD   ' ULONG
   argbPacketData(7) AS BYTE    ' BYTE[8]
END TYPE

' // Size = 16 bytes
TYPE BDA_DISEQC_RESPONSE DWORD
   ulRequestId       AS DWORD   ' ULONG
   ulPacketLength    AS DWORD   ' ULONG
   argbPacketData(7) AS BYTE    ' BYTE[8]
END TYPE


'//------------------------------------------------------------
'//
'//
'//  BDA PID Filter Property Set
'//
'// {D0A67D65-08DF-4fec-8533-E5B550410B85}
'//

'//---------------------------------------------------------------------
'// From IEnumPIDMap interface
'//---------------------------------------------------------------------

' ENUM MEDIA_SAMPLE_CONTENT
MACRO MEDIA_SAMPLE_CONTENT_ENUM = LONG
%MEDIA_TRANSPORT_PACKET  = 0   ' //  complete TS packet e.g. pass-through mode
%MEDIA_ELEMENTARY_STREAM = 1   ' //  PES payloads; audio/video only
%MEDIA_MPEG2_PSI         = 2   ' //  PAT, PMT, CAT, Private
%MEDIA_TRANSPORT_PAYLOAD = 3   ' //  gathered TS packet payloads (PES packets, etc...)

' // Size = 8 bytes
TYPE PID_MAP DWORD
   ulPID              AS DWORD                       ' ULONG
   MediaSampleContent AS MEDIA_SAMPLE_CONTENT_ENUM   ' MEDIA_SAMPLE_CONTENT
END TYPE

' // Size = 12 bytes
TYPE BDA_PID_MAP DWORD
   MediaSampleContent          AS MEDIA_SAMPLE_CONTENT_ENUM   ' MEDIA_SAMPLE_CONTENT
   ulcPIDs                     AS DWORD                       ' ULONG
   aulPIDs(%MIN_DIMENSION - 1) AS DWORD                       ' ULONG[MIN_DIMENSION]
END TYPE

' // Size = 8 bytes
TYPE BDA_PID_UNMAP DWORD
   ulcPIDs                     AS DWORD   ' ULONG
   aulPIDs(%MIN_DIMENSION - 1) AS DWORD   ' ULONG[MIN_DIMENSION]
END TYPE


'//------------------------------------------------------------
'//
'//
'//  BDA CA Property Set
'//
'// {B0693766-5278-4ec6-B9E1-3CE40560EF5A}
'//

' // Size = 12 bytes
TYPE BDA_CA_MODULE_UI DWORD
   ulFormat                   AS DWORD   ' ULONG
   ulbcDesc                   AS DWORD   ' ULONG
   ulDesc(%MIN_DIMENSION - 1) AS DWORD   ' ULONG[MIN_DIMENSION]
END TYPE

' // Size = 12 bytes
TYPE BDA_PROGRAM_PID_LIST
   ulProgramNumber           AS DWORD   ' ULONG
   ulcPIDs                   AS DWORD   ' ULONG
   ulPID(%MIN_DIMENSION - 1) AS DWORD   ' ULONG[MIN_DIMENSION]
END TYPE

'//------------------------------------------------------------
'//
'//
'//  BDA CA Event Set
'//
'// {488C4CCC-B768-4129-8EB1-B00A071F9068}
'//


'//=============================================================
'// PBDA RESULT parameter definition
'//=============================================================
'typedef LONG PBDARESULT;

'//=============================================================
'//  BDA_DRM_STATUS used by the DRMService
'//=============================================================

' // Size = 40 bytes
TYPE BDA_DRM_DRMSTATUS DWORD
   lResult                                   AS LONG    ' PBDARESULT
   DRMuuid                                   AS GUID    ' GUID
   ulDrmUuidListStringSize                   AS DWORD   ' ULONG
   argbDrmUuidListString(%MIN_DIMENSION - 1) AS GUID    ' GUID[MIN_DIMENSION]
END TYPE


'//=============================================================
'// PBDA_WMDRM and PBDA_WMDRMTuner structures
'//=============================================================

' // Size = 48 bytes
TYPE BDA_WMDRM_STATUS   ' // Must be 8 bytes aligned
   lResult                 AS LONG    ' PBDARESULT
   ulMaxCaptureTokenSize   AS DWORD   ' ULONG
   uMaxStreamingPid        AS DWORD   ' ULONG
   ulMaxLicense            AS DWORD   ' ULONG
   ulMinSecurityLevel      AS DWORD   ' ULONG
   ulRevInfoSequenceNumber AS DWORD   ' ULONG
   ulRevInfoIssuedTime     AS QUAD    ' ULONGLONG
   ulRevListVersion        AS DWORD   ' ULONG
   ulRevInfoTTL            AS DWORD   ' ULONG
   ulState                 AS DWORD   ' ULONG
   filler_                 AS DWORD   ' // To keep QWORD alignment
END TYPE

' // Size = 24 bytes
TYPE BDA_WMDRM_KEYINFOLIST DWORD
   lResult                              AS LONG    ' PBDARESULT
   ulKeyuuidBufferLen                   AS DWORD   ' ULONG
   argKeyuuidBuffer(%MIN_DIMENSION - 1) AS GUID    ' GUID
END TYPE

' // Size = 12 bytes
TYPE BDA_BUFFER DWORD
   lResult                        AS LONG    ' PBDARESULT
   ulBufferSize                   AS DWORD   ' ULONG
   argbBuffer(%MIN_DIMENSION - 1) AS BYTE    ' BYTE
END TYPE

'//=============================================================
'// PBDA - DRM structures used in methods
'//=============================================================

' // Size = 16 bytes
TYPE BDA_WMDRM_RENEWLICENSE DWORD
   lResult                                        AS LONG    ' PBDARESULT
   ulDescrambleStatus                             AS DWORD   ' ULONG
   ulXmrLicenseOutputLength                       AS DWORD   ' ULONG
   argbXmrLicenceOutputBuffer(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION] //License and Entitlement Token Buffer
END TYPE

' // Size = 20 bytes
TYPE BDA_WMDRMTUNER_PIDPROTECTION DWORD
   lResult   AS LONG   ' PBDARESULT
   uuidKeyID AS GUID   ' GUID
END TYPE

' // Size = 16 bytes
TYPE BDA_WMDRMTUNER_PURCHASEENTITLEMENT DWORD
   lResult                                    AS LONG    ' PBDARESULT
   ulDescrambleStatus                         AS DWORD   ' ULONG
   ulCaptureTokenLength                       AS DWORD   ' ULONG
   argbCaptureTokenBuffer(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION]
END TYPE

'//=============================================================
'// PBDA - TUNER structures used in methods
'//=============================================================

' // Size = 12 bytes
TYPE BDA_TUNER_TUNERSTATE DWORD
   lResult                          AS LONG    ' PBDARESULT
   ulTuneLength                     AS DWORD   ' ULONG
   argbTuneData(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION]
END TYPE

' // Size = 16 bytes
TYPE BDA_TUNER_DIAGNOSTICS DWORD
   lResult              AS LONG    ' PBDARESULT
   ulSignalLevel        AS DWORD   ' ULONG
   ulSignalLevelQuality AS DWORD   ' ULONG
   ulSignalNoiseRatio   AS DWORD   ' ULONG
END TYPE

'//=============================================================
'// PBDA - STRING structure used in methods
'//=============================================================

' // Size = 12 bytes
TYPE BDA_STRING DWORD
   lResult                        AS LONG    ' PBDARESULT
   ulStringSize                   AS DWORD   ' ULONG
   argbString(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION]
END TYPE


'//=============================================================
'// PBDA - SCANNING structures used in methods
'//=============================================================

' // Size = 16 bytes
TYPE BDA_SCAN_CAPABILTIES QWORD   ' // Must be 8 bytes aligned
   lResult                      AS LONG    ' PBDARESULT
   ul64AnalogStandardsSupported AS QUAD    ' UINT64
END TYPE

' // Size = 16 bytes
TYPE BDA_SCAN_STATE DWORD
   lResult            AS LONG    ' PBDARESULT
   ulSignalLock       AS DWORD   ' ULONG
   ulSecondsLeft      AS DWORD   ' ULONG
   ulCurrentFrequency AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE BDA_SCAN_START DWORD
   lResult        AS LONG    ' PBDARESULT
   LowerFrequency AS DWORD   ' ULONG
   HigerFrequency AS DWORD   ' ULONG
END TYPE


'//=============================================================
'// PBDA - GUIDE DATA structures used in methods
'//=============================================================

' // Size = 20 bytes
TYPE BDA_GDDS_DATATYPE DWORD
   lResult      AS LONG   ' PBDARESULT
   uuidDataType AS GUID   ' GUID
END TYPE

' // Size = 16 bytes
TYPE BDA_GDDS_DATA DWORD
   lResult                      AS LONG    ' PBDARESULT
   ulDataLength                 AS DWORD   ' ULONG
   ulPercentageProgress         AS DWORD   ' ULONG
   argbData(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION]
END TYPE


'//=============================================================
'// PBDA - USER ACTIVITY structures used in methods
'//=============================================================

' // Size = 8 bytes
TYPE BDA_USERACTIVITY_INTERVAL DWORD
   lResult            AS LONG    ' PBDARESULT
   ulActivityInterval AS DWORD   ' ULONG
END TYPE


'//=============================================================
'// PBDA - CAS structures used in methods
'//=============================================================

' // Size = 8 bytes
TYPE BDA_CAS_CHECK_ENTITLEMENTTOKEN DWORD
   lResult            AS LONG    ' PBDARESULT
   ulDescrambleStatus AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE BDA_CAS_CLOSE_MMIDIALOG DWORD
   lResult       AS LONG    ' PBDARESULT
   SessionResult AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE BDA_CAS_REQUESTTUNERDATA DWORD FILL
   ucRequestPriority     AS BYTE    ' UCHAR
   ucRequestReason       AS BYTE    ' UCHAR
   ucRequestConsequences AS BYTE    ' UCHAR
   ulEstimatedTime       AS DWORD   ' ULONG
END TYPE

' // Size = 28 bytes
TYPE BDA_CAS_OPENMMIDATA   ' Must be 4 bytes aligned
   ulDialogNumber                 AS DWORD   ' ULONG
   ulDialogRequest                AS DWORD   ' ULONG
   uuidDialogType                 AS GUID    ' GUID
   usDialogDataLength             AS WORD    ' USHORT
   argbDialogData(%MIN_DIMENSION) AS BYTE    ' BYTE[MIN_DIMENSION]
   ' Note: We are using MIN_DIMENSION instead of MIN_DIMENSION - 1 to keep DWORD alignment
END TYPE

' // Size = 4 bytes
TYPE BDA_CAS_CLOSEMMIDATA DWORD
   ulDialogNumber AS DWORD   ' ULONG
END TYPE

'//=============================================================
'// PBDA - ISDB CAS structures used in methods
'//=============================================================

'#pragma pack(push, 1)
' // Begin byte alignmentg

' ENUM ISDBCAS_REQUEST_ID
MACRO ISDBCAS_REQUEST_ID_ENUM = BYTE
%ISDBCAS_REQUEST_ID_EMG = &H38?
%ISDBCAS_REQUEST_ID_EMD = &H3A?

' // Size = 9 bytes
TYPE BDA_ISDBCAS_REQUESTHEADER BYTE
   bInstruction                        AS BYTE    ' BYTE // EMD/EMG
   bReserved(2)                        AS BYTE    ' BYTE[3] // future use
   ulDataLength                        AS DWORD   ' ULONG // byte size of argbIsdbCommand
   argbIsdbCommand(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION]
END TYPE

' // Size = 17 bytes
TYPE BDA_ISDBCAS_RESPONSEDATA BYTE
   lResult                                 AS LONG    ' PBDARESULT
   ulRequestID                             AS DWORD   ' ULONG
   ulIsdbStatus                            AS DWORD   ' ULONG
   ulIsdbDataSize                          AS DWORD   ' ULONG
   argbIsdbCommandData(%MIN_DIMENSION - 1) AS BYTE    ' BYTE[MIN_DIMENSION]
END TYPE

' // Size = 15 bytes
TYPE BDA_ISDBCAS_EMG_REQ BYTE
   bCLA                             AS BYTE   ' BYTE // 0x90
   bINS                             AS BYTE   ' BYTE // 0x38
   bP1                              AS BYTE   ' BYTE // 0x00
   bP2                              AS BYTE   ' BYTE // 0x00
   bLC                              AS BYTE   ' BYTE // Following bytes - 1(LE)
   bCardId(5)                       AS BYTE   ' BYTE // from EMM message packet
   bProtocol                        AS BYTE   ' BYTE // from EMM message packet
   bCABroadcasterGroupId            AS BYTE   ' BYTE // from EMM message packet
   bMessageControl                  AS BYTE   ' BYTE // from EMM message packet
   bMessageCode(%MIN_DIMENSION - 1) AS BYTE   ' BYTE[MIN_DIMENSION] // Last byte is reserved as 'LE'
END TYPE

'#pragma pack(pop)
' // End byte alignment

'//=============================================================
'// PBDA - MUX structures used in methods
'//=============================================================

' ENUM MUX_PID_TYPE
MACRO MUX_PID_TYPE_ENUM = LONG
%PID_OTHER                = -1
%PID_ELEMENTARY_STREAM    = 0    ' //  PES payloads
%PID_MPEG2_SECTION_PSI_SI = 1    ' //  ISO 13818_1 Sections PAT, PMT, CAT, Private. Service Information Sections e.g SDT, NIT, EIT, BAT

'#pragma pack(push, 2)
' // Begin 2 byte alignment
' // Size = 8 bytes
TYPE BDA_MUX_PIDLISTITEM WORD
   usPIDNumber     AS WORD                ' USHORT //PID number of the stream
   usProgramNumber AS WORD                ' USHORT //associated Service Id, if applicable
   ePIDType        AS MUX_PID_TYPE_ENUM   ' MUX_PID_TYPE //PID Type of the stream if applicable
END TYPE
'#pragma pack(pop)
' // End 2 byte alignment

'//=============================================================
'// BDA - TS Selector structures used in methods
'//=============================================================

'//  |<-------------- bTSInfolength ---------------------->|
'//  |                                                     |
'//  |                     |                               |
'//  | BDA_TS_SELECTORINFO | BDA_TS_SELECTORINFO_ISDBS_EXT |
'//  |                     | (for ISDB-S extension)        |
'//  |                     |                               |

'#pragma pack(push, 1)
' // Begin byte alignment
' // Size = 22 bytes
TYPE BDA_TS_SELECTORINFO BYTE
   bTSInfolength              AS BYTE   ' BYTE // buffer length including extension
   bReserved(1)               AS BYTE   ' BYTE
   guidNetworkType            AS GUID   ' GUID // current type of tuning
   bTSIDCount                 AS BYTE   ' BYTE // number of usTSID
   usTSID(%MIN_DIMENSION - 1) AS WORD   ' USHORT[MIN_DIMENSION]
END TYPE

' // Size = 48 bytes
TYPE BDA_TS_SELECTORINFO_ISDBS_EXT BYTE
   bTMCC(47) AS BYTE   ' BYTE[48]
END TYPE
'#pragma pack(pop)
' // End byte alignment

'//DVB-T2 related L1 signalling information returned in _GETTSINFORMATION

' // Size = 26 bytes
TYPE BDA_DVBT2_L1_SIGNALLING_DATA BYTE
   L1Pre_TYPE                            AS BYTE   ' BYTE
   L1Pre_BWT_S1_S2                       AS BYTE   ' BYTE
   L1Pre_REPETITION_GUARD_PAPR           AS BYTE   ' BYTE
   L1Pre_MOD_COD_FEC                     AS BYTE   ' BYTE
   L1Pre_POSTSIZE_INFO_PILOT(4)          AS BYTE   ' BYTE[5]
   L1Pre_TX_ID_AVAIL                     AS BYTE   ' BYTE
   L1Pre_CELL_ID(1)                      AS BYTE   ' BYTE[2]
   L1Pre_NETWORK_ID(1)                   AS BYTE   ' BYTE[2]
   L1Pre_T2SYSTEM_ID(1)                  AS BYTE   ' BYTE[2]
   L1Pre_NUM_T2_FRAMES                   AS BYTE   ' BYTE
   L1Pre_NUM_DATA_REGENFLAG_L1POSTEXT(1) AS BYTE   ' BYTE[2]
   L1Pre_NUMRF_CURRENTRF_RESERVED(1)     AS BYTE   ' BYTE[2]
   L1Pre_CRC32(3)                        AS BYTE   ' BYTE[4]
   L1PostData(%MIN_DIMENSION - 1)        AS BYTE   ' BYTE[MIN_DIMENSION]
END TYPE


'//=============================================================
'// PBDA - RATING structures used in methods
'//=============================================================

' // Size = 2 bytes
TYPE BDA_RATING_PINRESET BYTE
   bPinLength                     AS BYTE   ' BYTE //Buffer size including a null termination
   argbNewPin(%MIN_DIMENSION - 1) AS BYTE   ' BYTE[MIN_DIMENSION] //Null terminated UTF8. Use empty string if disable pin
END TYPE


'//=============================================================
'//
'//
'//  BDA Tuning Model enumerations
'//
'//
'//=============================================================

'// system type for particular DVB Tuning Space instance

' ENUM DVBSystemType
MACRO DVBSYSTEMTYPE_ENUM = LONG
%DVB_Cable        = 0
%DVB_Terrestrial  = 1
%DVB_Satellite    = 2
%ISDB_Terrestrial = 3
%ISDB_Satellite   = 4

'//------------------------------------------------------------
'//
'//  BDA Channel Tune Request

' ENUM  BDA_Channel
MACRO BDA_CHANNEL_ENUM = LONG
%BDA_UNDEFINED_CHANNEL = -1

'//------------------------------------------------------------
'//
'//  BDA Component(substream)
'//  Note: Persistent TS remember preferred component categories by their number.
'//        Please update the rgs files at multimedia\dshow\vidctl\msvidctl\res
'//        and multimedia\dshow\vidctl\manifests\Video-TVVideoControl.man accordingly
'//        if the order/value changes.
'//        Also make sure ehiProxy.asmmeta, ehiVidCtl.asmmeta and bdatunepia.asmmeta
'//        are properly updated.
'//

' ENUM ComponentCategory
MACRO COMPONENTCATEGORY_ENUM = LONG
%ComponentCategory_CategoryNotSet      = -1
%ComponentCategory_CategoryOther       = 0
%ComponentCategory_CategoryVideo       = 1
%ComponentCategory_CategoryAudio       = 2
%ComponentCategory_CategoryText        = 3
%ComponentCategory_CategorySubtitles   = 4
%ComponentCategory_CategoryCaptions    = 5
%ComponentCategory_CategorySuperimpose = 6
%ComponentCategory_CategoryData        = 7
%ComponentCategory_CATEGORY_COUNT      = 8

'// Component Status

' ENUM ComponentStatus
MACRO COMPONENTSTATUS_ENUM = LONG
%ComponentStatus_StatusActive      = 0
%ComponentStatus_StatusInactive    = 1
%ComponentStatus_StatusUnavailable = 2

'//------------------------------------------------------------
'//
'//  BDA MPEG2 Component Type
'//
'// from the MPEG2 specification

' ENUM MPEG2StreamType
MACRO MPEG2STREAMTYPE_ENUM = LONG
%BDA_UNITIALIZED_MPEG2STREAMTYPE = -1
%MPEG2StreamType_Reserved1       = &H0
%ISO_IEC_11172_2_VIDEO           = &H01
%ISO_IEC_13818_2_VIDEO           = &H02
%ISO_IEC_11172_3_AUDIO           = &H03
%ISO_IEC_13818_3_AUDIO           = &H04
%ISO_IEC_13818_1_PRIVATE_SECTION = &H05
%ISO_IEC_13818_1_PES             = &H06
%ISO_IEC_13522_MHEG              = &H07
%ANNEX_A_DSM_CC                  = &H08
%ITU_T_REC_H_222_1               = &H09
%ISO_IEC_13818_6_TYPE_A          = &H0A
%ISO_IEC_13818_6_TYPE_B          = &H0B
%ISO_IEC_13818_6_TYPE_C          = &H0C
%ISO_IEC_13818_6_TYPE_D          = &H0D
%ISO_IEC_13818_1_AUXILIARY       = &H0E
%ISO_IEC_13818_7_AUDIO           = &H0F
%ISO_IEC_14496_2_VISUAL          = &H10
%ISO_IEC_14496_3_AUDIO           = &H11
%ISO_IEC_14496_1_IN_PES          = &H12
%ISO_IEC_14496_1_IN_SECTION      = &H13
%ISO_IEC_13818_6_DOWNLOAD        = &H14
%METADATA_IN_PES                 = &H15
%METADATA_IN_SECTION             = &H16
%METADATA_IN_DATA_CAROUSEL       = &H17
%METADATA_IN_OBJECT_CAROUSEL     = &H18
%METADATA_IN_DOWNLOAD_PROTOCOL   = &H19
%IRPM_STREAMM                    = &H1A
%ITU_T_H264                      = &H1B
%ISO_IEC_13818_1_RESERVED        = &H1C  ' // continues until &H7F
%USER_PRIVATE                    = &H10  ' // standard says &H80, retaining for backwards compatibility
%ISO_IEC_USER_PRIVATE            = &H80
%DOLBY_AC3_AUDIO                 = &H81
%DOLBY_DIGITAL_PLUS_AUDIO_ATSC   = &H87

'//------------------------------------------------------------
'//
'//  mpeg-2 transport stride format block; associated with media
'//   types MEDIATYPE_Stream/MEDIASUBTYPE_MPEG2_TRANSPORT_STRIDE;
'//   *all* format blocks associated with above media type *must*
'//   start with the MPEG2_TRANSPORT_STRIDE structure
'//

' // Size = 12 bytes
TYPE MPEG2_TRANSPORT_STRIDE DWORD
   dwOffset       AS DWORD
   dwPacketLength AS DWORD
   dwStride       AS DWORD
END TYPE

'//------------------------------------------------------------
'//
'//  BDA ATSC Component Type
'//
'//
'// ATSC made AC3 Audio a descriptor instead of
'// defining a user private stream type.

' FLAGS ATSCComponentTypeFlags
' // bit flags for various component type properties
%ATSCCT_AC3 = &H00000001???


'//------------------------------------------------------------
'//
'//  BDA Locators
'//

' ENUM BinaryConvolutionCodeRate
MACRO BINARYCONVOLUTIONCODERATE_ENUM = LONG
%BDA_BCC_RATE_NOT_SET     = -1
%BDA_BCC_RATE_NOT_DEFINED = 0
%BDA_BCC_RATE_1_2         = 1    ' // 1/2
%BDA_BCC_RATE_2_3         = 2    ' // 2/3
%BDA_BCC_RATE_3_4         = 3    ' // 3/4
%BDA_BCC_RATE_3_5         = 4    ' // 3/5
%BDA_BCC_RATE_4_5         = 5    ' // 4/5
%BDA_BCC_RATE_5_6         = 6    ' // 5/6
%BDA_BCC_RATE_5_11        = 7    ' // 5/11
%BDA_BCC_RATE_7_8         = 8    ' // 7/8
%BDA_BCC_RATE_1_4         = 9    ' // 1/4
%BDA_BCC_RATE_1_3         = 10   ' // 1/3
%BDA_BCC_RATE_2_5         = 11   ' // 2/5
%BDA_BCC_RATE_6_7         = 12   ' // 6/7
%BDA_BCC_RATE_8_9         = 13   ' // 8/9
%BDA_BCC_RATE_9_10        = 14   ' // 9/10
%BDA_BCC_RATE_MAX         = 15

' ENUM FECMethod
MACRO FECMETHOD_ENUM = LONG
%BDA_FEC_METHOD_NOT_SET     = -1
%BDA_FEC_METHOD_NOT_DEFINED = 0
%BDA_FEC_VITERBI            = 1    ' // FEC is a Viterbi Binary Convolution.
%BDA_FEC_RS_204_188         = 2    ' // The FEC is Reed-Solomon 204/188 (outer FEC)
%BDA_FEC_LDPC               = 3    ' // Low Density Parity Check error correction code
%BDA_FEC_BCH                = 4    ' // Bose-Chaudhuri-Hocquenghem multiple error correction binary block code
%BDA_FEC_RS_147_130         = 5    ' // The FEC is Reed-Solomon 147/130 (outer FEC) DirecTV-DSS
%BDA_FEC_MAX                = 6

' ENUM ModulationType
MACRO MODULATIONTYPE_ENUM = LONG
%BDA_MOD_NOT_SET          = -1
%BDA_MOD_NOT_DEFINED      = 0
%BDA_MOD_16QAM            = 1
%BDA_MOD_32QAM            = 2
%BDA_MOD_64QAM            = 3
%BDA_MOD_80QAM            = 4
%BDA_MOD_96QAM            = 5
%BDA_MOD_112QAM           = 6
%BDA_MOD_128QAM           = 7
%BDA_MOD_160QAM           = 8
%BDA_MOD_192QAM           = 9
%BDA_MOD_224QAM           = 10
%BDA_MOD_256QAM           = 11
%BDA_MOD_320QAM           = 12
%BDA_MOD_384QAM           = 13
%BDA_MOD_448QAM           = 14
%BDA_MOD_512QAM           = 15
%BDA_MOD_640QAM           = 16
%BDA_MOD_768QAM           = 17
%BDA_MOD_896QAM           = 18
%BDA_MOD_1024QAM          = 19
%BDA_MOD_QPSK             = 20   ' // Quadrature Phase Shift Keying (including backwards compatible mode)
%BDA_MOD_BPSK             = 21   ' // Binary Phase Shift Keying
%BDA_MOD_OQPSK            = 22   ' // Offset QPSK
%BDA_MOD_8VSB             = 23   ' // 8-Level Vestigial Sideband
%BDA_MOD_16VSB            = 24   ' // 16-Level Vestigial Sideband
%BDA_MOD_ANALOG_AMPLITUDE = 25   ' // std am
%BDA_MOD_ANALOG_FREQUENCY = 26   ' // std fm
%BDA_MOD_8PSK             = 27   ' // 8 Phase Shift Keying (including backwards compatible mode)
%BDA_MOD_RF               = 28   ' // analog TV (Video standards such as NTSC/PAL/SECAM specified in IAnalogLocator VideoStandard property)
%BDA_MOD_16APSK           = 29   ' // DVB-S2 modulation 16-Level APSK
%BDA_MOD_32APSK           = 30   ' // DVB-S2 modulation 32-Level APSK
%BDA_MOD_NBC_QPSK         = 31   ' // Non-Backwards Compatible Quadrature Phase Shift Keying
%BDA_MOD_NBC_8PSK         = 32   ' // Non-Backwards Compatible 8 Phase Shift Keying
%BDA_MOD_DIRECTV          = 33   ' // DIRECTV DSS
%BDA_MOD_ISDB_T_TMCC      = 34   ' // Automatic demodulation by Transmission and Multiplexing Configuration Control signal for ISDB-T
%BDA_MOD_ISDB_S_TMCC      = 35   ' // Automatic demodulation by Transmission and Multiplexing Configuration Control signal for ISDB-S
%BDA_MOD_MAX              = 36

' ENUM ScanModulationTypes
MACRO SCANMODULATIONTYPES_ENUM = LONG
%BDA_SCAN_MOD_16QAM    = &H00000001???
%BDA_SCAN_MOD_32QAM    = &H00000002???
%BDA_SCAN_MOD_64QAM    = &H00000004???
%BDA_SCAN_MOD_80QAM    = &H00000008???
%BDA_SCAN_MOD_96QAM    = &H00000010???
%BDA_SCAN_MOD_112QAM   = &H00000020???
%BDA_SCAN_MOD_128QAM   = &H00000040???
%BDA_SCAN_MOD_160QAM   = &H00000080???
%BDA_SCAN_MOD_192QAM   = &H00000100???
%BDA_SCAN_MOD_224QAM   = &H00000200???
%BDA_SCAN_MOD_256QAM   = &H00000400???
%BDA_SCAN_MOD_320QAM   = &H00000800???
%BDA_SCAN_MOD_384QAM   = &H00001000???
%BDA_SCAN_MOD_448QAM   = &H00002000???
%BDA_SCAN_MOD_512QAM   = &H00004000???
%BDA_SCAN_MOD_640QAM   = &H00008000???
%BDA_SCAN_MOD_768QAM   = &H00010000???
%BDA_SCAN_MOD_896QAM   = &H00020000???
%BDA_SCAN_MOD_1024QAM  = &H00040000???
%BDA_SCAN_MOD_QPSK     = &H00080000???
%BDA_SCAN_MOD_BPSK     = &H00100000???
%BDA_SCAN_MOD_OQPSK    = &H00200000???
%BDA_SCAN_MOD_8VSB     = &H00400000???
%BDA_SCAN_MOD_16VSB    = &H00800000???
%BDA_SCAN_MOD_AM_RADIO = &H01000000???
%BDA_SCAN_MOD_FM_RADIO = &H02000000???
%BDA_SCAN_MOD_8PSK     = &H04000000???
%BDA_SCAN_MOD_RF       = &H08000000???  ' // analog TV
%ScanModulationTypesMask_MCE_DigitalCable = %BDA_MOD_64QAM OR %BDA_MOD_256QAM
%ScanModulationTypesMask_MCE_TerrestrialATSC = %BDA_MOD_8VSB
%ScanModulationTypesMask_MCE_AnalogTv = %BDA_MOD_RF
%ScanModulationTypesMask_MCE_All_TV = &Hffffffff???
%ScanModulationTypesMask_DVBC = %BDA_MOD_64QAM OR %BDA_SCAN_MOD_128QAM OR %BDA_MOD_256QAM
%BDA_SCAN_MOD_16APSK   = &H10000000???
%BDA_SCAN_MOD_32APSK   = &H20000000???

' ENUM SpectralInversion
MACRO SPECTRALINVERSION_ENUM = LONG
%BDA_SPECTRAL_INVERSION_NOT_SET     = -1
%BDA_SPECTRAL_INVERSION_NOT_DEFINED = 0
%BDA_SPECTRAL_INVERSION_AUTOMATIC   = 1
%BDA_SPECTRAL_INVERSION_NORMAL      = 2
%BDA_SPECTRAL_INVERSION_INVERTED    = 3
%BDA_SPECTRAL_INVERSION_MAX         = 4

' ENUM Polarisation
MACRO POLARISATION_ENUM = LONG
%BDA_POLARISATION_NOT_SET     = -1
%BDA_POLARISATION_NOT_DEFINED = 0
%BDA_POLARISATION_LINEAR_H    = 1    ' // Linear horizontal polarisation
%BDA_POLARISATION_LINEAR_V    = 2    ' // Linear vertical polarisation
%BDA_POLARISATION_CIRCULAR_L  = 3    ' // Circular left polarisation
%BDA_POLARISATION_CIRCULAR_R  = 4    ' // Circular right polarisation
%BDA_POLARISATION_MAX         = 5

'ENUM LNB_Source
MACRO LNB_SOURCE_ENUM = LONG
%BDA_LNB_SOURCE_NOT_SET     = -1
%BDA_LNB_SOURCE_NOT_DEFINED = 0
%BDA_LNB_SOURCE_A           = 1
%BDA_LNB_SOURCE_B           = 2
%BDA_LNB_SOURCE_C           = 3
%BDA_LNB_SOURCE_D           = 4
%BDA_LNB_SOURCE_MAX         = 5

' ENUM GuardInterval
MACRO GUARDINTERVAL_ENUM = LONG
%BDA_GUARD_NOT_SET     = -1
%BDA_GUARD_NOT_DEFINED = 0
%BDA_GUARD_1_32        = 1    ' // Guard interval is 1/32
%BDA_GUARD_1_16        = 2    ' // Guard interval is 1/16
%BDA_GUARD_1_8         = 3    ' // Guard interval is 1/8
%BDA_GUARD_1_4         = 4    ' // Guard interval is 1/4
%BDA_GUARD_1_128       = 5    ' // Guard interval is 1/128 (DVB-T2)
%BDA_GUARD_19_128      = 6    ' // Guard interval is 19/128 (DVB-T2)
%BDA_GUARD_19_256      = 7    ' // Guard interval is 19/256 (DVB-T2)
%BDA_GUARD_MAX         = 8

' ENUM HierarchyAlpha
MACRO HIERARCHYALPHA_ENUM = LONG
%BDA_HALPHA_NOT_SET     = -1
%BDA_HALPHA_NOT_DEFINED = 0
%BDA_HALPHA_1           = 1    ' // Hierarchy alpha is 1.
%BDA_HALPHA_2           = 2    ' // Hierarchy alpha is 2.
%BDA_HALPHA_4           = 3    ' // Hierarchy alpha is 4.
%BDA_XMIT_MODE_1K       = 4    ' //DVB-T2 (use 1K FFT)
%BDA_XMIT_MODE_16K      = 5    ' //DVB-T2 (use 16K FFT)
%BDA_XMIT_MODE_32K      = 6    ' //DVB-T2 (use 32K FFT)
%BDA_HALPHA_MAX         = 7

' ENUM TransmissionMode
MACRO TRANSMISSIONMODE_ENUM = LONG
%BDA_XMIT_MODE_NOT_SET        = -1
%BDA_XMIT_MODE_NOT_DEFINED    = 0
%BDA_XMIT_MODE_2K             = 1    ' // Transmission uses 1705 carriers (use a 2K FFT)
%BDA_XMIT_MODE_8K             = 2    ' // Transmission uses 6817 carriers (use an 8K FFT)
%BDA_XMIT_MODE_4K             = 3
%BDA_XMIT_MODE_2K_INTERLEAVED = 4
%BDA_XMIT_MODE_4K_INTERLEAVED = 5
%BDA_XMIT_MODE_MAX            = 6

' ENUM RollOff
MACRO ROLLOFF_ENUM = LONG
%BDA_ROLL_OFF_NOT_SET     = -1
%BDA_ROLL_OFF_NOT_DEFINED = 0
%BDA_ROLL_OFF_20          = 1    ' // .20 Roll Off (DVB-S2 Only)
%BDA_ROLL_OFF_25          = 2    ' // .25 Roll Off (DVB-S2 Only)
%BDA_ROLL_OFF_35          = 3    ' // .35 Roll Off (DVB-S2 Only)
%BDA_ROLL_OFF_MAX         = 4

' ENUM Pilot
MACRO PILOT_ENUM = LONG
%BDA_PILOT_NOT_SET     = -1
%BDA_PILOT_NOT_DEFINED = 0
%BDA_PILOT_OFF         = 1    ' // Pilot Off (DVB-S2 Only)
%BDA_PILOT_ON          = 2    ' // Pilot On  (DVB-S2 Only)
%BDA_PILOT_MAX         = 3

' // Size = 12 bytes
TYPE BDA_SIGNAL_TIMEOUTS DWORD
   ulCarrierTimeoutMs  AS DWORD   ' ULONG
   ulScanningTimeoutMs AS DWORD   ' ULONG
   ulTuningTimeoutMs   AS DWORD   ' ULONG
END TYPE

'//  Settings for Tuner Frequency
'//

' ENUM BDA_Frequency
MACRO BDA_FREQUENCY_ENUM = LONG
%BDA_FREQUENCY_NOT_SET     = -1
%BDA_FREQUENCY_NOT_DEFINED = 0

'//  Settings for Tuner Range
'//
'//  Tuner range refers to the setting of LNB High/Low as well as the
'//  selection of a satellite on a multiple satellite switch.
'//

' ENUM BDA_Range
MACRO BDA_RANGE_ENUM = LONG
%BDA_RANGE_NOT_SET     = -1
%BDA_RANGE_NOT_DEFINED = 0

'//  Settings for Tuner Channel Bandwidth
'//

' ENUM BDA_Channel_Bandwidth
MACRO BDA_CHANNEL_BANDWIDTH_ENUM = LONG
%BDA_CHAN_BANDWITH_NOT_SET     = -1
%BDA_CHAN_BANDWITH_NOT_DEFINED = 0

'//  Settings for Tuner Frequency Multiplier
'//

' ENUM BDA_Frequency_Multiplier
MACRO BDA_FREQUENCY_MULTIPLIER_ENUM = LONG
%BDA_FREQUENCY_MULTIPLIER_NOT_SET     = -1
%BDA_FREQUENCY_MULTIPLIER_NOT_DEFINED = 0

' FLAGS BDA_Comp_Flags
' // equiv comparison rule overrides, default behavior is type specific
%BDACOMP_NOT_DEFINED              = &H00000000???
%BDACOMP_EXCLUDE_TS_FROM_TR       = &H00000001???   ' // never put TS in TR equiv comparison
%BDACOMP_INCLUDE_LOCATOR_IN_TR    = &H00000002???   ' // always include loc in TR equiv comparison
%BDACOMP_INCLUDE_COMPONENTS_IN_TR = &H00000004???   ' // always include components in TR equiv comparison

' ENUM ApplicationTypeType
MACRO APPLICATIONTYPETYPE_ENUM = LONG
%SCTE28_ConditionalAccess            = 0
%SCTE28_POD_Host_Binding_Information = 1
%SCTE28_IPService                    = 2
%SCTE28_NetworkInterface_SCTE55_2    = 3
%SCTE28_NetworkInterface_SCTE55_1    = 4
%SCTE28_CopyProtection               = 5
%SCTE28_Diagnostic                   = 6
%SCTE28_Undesignated                 = 7
%SCTE28_Reserved                     = 8

' ENUM BDA_CONDITIONALACCESS_REQUESTTYPE
MACRO BDA_CONDITIONALACCESS_REQUESTTYPE_ENUM = LONG
%CONDITIONALACCESS_ACCESS_UNSPECIFIED                      = 0
%CONDITIONALACCESS_ACCESS_NOT_POSSIBLE                     = 1
%CONDITIONALACCESS_ACCESS_POSSIBLE                         = 2
%CONDITIONALACCESS_ACCESS_POSSIBLE_NO_STREAMING_DISRUPTION = 3

' ENUM BDA_CONDITIONALACCESS_MMICLOSEREASON
MACRO BDA_CONDITIONALACCESS_MMICLOSEREASON_ENUM = LONG
%CONDITIONALACCESS_UNSPECIFIED               = 0
%CONDITIONALACCESS_CLOSED_ITSELF             = 1
%CONDITIONALACCESS_TUNER_REQUESTED_CLOSE     = 2
%CONDITIONALACCESS_DIALOG_TIMEOUT            = 3
%CONDITIONALACCESS_DIALOG_FOCUS_CHANGE       = 4
%CONDITIONALACCESS_DIALOG_USER_DISMISSED     = 5
%CONDITIONALACCESS_DIALOG_USER_NOT_AVAILABLE = 6

' ENUM BDA_CONDITIONALACCESS_SESSION_RESULT
MACRO BDA_CONDITIONALACCESS_SESSION_RESULT_ENUM = LONG
%CONDITIONALACCESS_SUCCESSFULL    = 0
%CONDITIONALACCESS_ENDED_NOCHANGE = 1
%CONDITIONALACCESS_ABORTED        = 2

' ENUM BDA_DISCOVERY_STATE
MACRO BDA_DISCOVERY_STATE_ENUM = LONG
%BDA_DISCOVERY_UNSPECIFIED = 0
%BDA_DISCOVERY_REQUIRED    = 1
%BDA_DISCOVERY_COMPLETE    = 2

'// Digital Demodulator for DVBT2 Physical Layer Pipe
%BDA_PLP_ID_NOT_SET = -1
