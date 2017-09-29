' ########################################################################################
' Microsoft Windows
' File: mpeg2data.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPEG2DATA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "bdaiface.inc"
#INCLUDE ONCE "mpeg2structs.inc"

'#pragma pack(push)
'#pragma pack(1)

%MPEG_PAT_PID                = &H0000??
%MPEG_PAT_TID                = &H00?
%MPEG_CAT_PID                = &H0001??
%MPEG_CAT_TID                = &H01?
%MPEG_PMT_TID                = &H02?
%MPEG_TSDT_PID               = &H0002??
%MPEG_TSDT_TID               = &H03?
%ATSC_MGT_PID                = &H1FFB??
%ATSC_MGT_TID                = &HC7?
%ATSC_VCT_PID                = &H1FFB??
%ATSC_VCT_TERR_TID           = &HC8?
%ATSC_VCT_CABL_TID           = &HC9?
%ATSC_EIT_TID                = &HCB?
%ATSC_ETT_TID                = &HCC?
%ATSC_RRT_TID                = &HCA?
%ATSC_RRT_PID                = &H1FFB??
%ATSC_STT_PID                = &H1FFB??
%ATSC_STT_TID                = &HCD?
%ATSC_PIT_TID                = &HD0?
%DVB_NIT_PID                 = &H0010??
%DVB_NIT_ACTUAL_TID          = &H40?
%DVB_NIT_OTHER_TID           = &H41?
%DVB_SDT_PID                 = &H0011??
%DVB_SDT_ACTUAL_TID          = &H42?
%DVB_SDT_OTHER_TID           = &H46?
%DVB_BAT_PID                 = &H0011??
%DVB_BAT_TID                 = &H4A?
%DVB_EIT_PID                 = &H0012??
%DVB_EIT_ACTUAL_TID          = &H4E?
%DVB_EIT_OTHER_TID           = &H4F?
%DVB_RST_PID                 = &H0013??
%DVB_RST_TID                 = &H71?
%DVB_TDT_PID                 = &H0014??
%DVB_TDT_TID                 = &H70?
%DVB_ST_PID_16               = &H0010??
%DVB_ST_PID_17               = &H0011??
%DVB_ST_PID_18               = &H0012??
%DVB_ST_PID_19               = &H0013??
%DVB_ST_PID_20               = &H0014??
%DVB_ST_TID                  = &H72?
%ISDB_ST_TID                 = &H72?
%DVB_TOT_PID                 = &H0014??
%DVB_TOT_TID                 = &H73?
%DVB_DIT_PID                 = &H001E??
%DVB_DIT_TID                 = &H7E?
%DVB_SIT_PID                 = &H001F??
%DVB_SIT_TID                 = &H7F?
'%ISDB_DCT_PID                = &H0017??   ' // Removed in the Windows 7 SDK
'%ISDB_DCT_TID                = &HC0?      ' // Removed in the Windows 7 SDK
'%ISDB_LIT_PID                = &H0020??   ' // Removed in the Windows 7 SDK
'%ISDB_LIT_TID                = &HD0?      ' // Removed in the Windows 7 SDK
'%ISDB_ERT_PID                = &H0021??   ' // Removed in the Windows 7 SDK
'%ISDB_ERT_TID                = &HD1?      ' // Removed in the Windows 7 SDK
'%ISDB_ITT_TID                = &HD2?      ' // Removed in the Windows 7 SDK
'%ISDB_DLT_TID                = &HC1?      ' // Removed in the Windows 7 SDK
'%ISDB_PCAT_PID               = &H0022??   ' // Removed in the Windows 7 SDK
'%ISDB_PCAT_TID               = &HC2?      ' // Removed in the Windows 7 SDK
%DVB_SIT_TID                 = &H7F?
%ISDB_EMM_TID                = &H85?
%ISDB_BIT_PID                = &H0024??
%ISDB_BIT_TID                = &HC4?
%ISDB_NBIT_PID               = &H0025??
%ISDB_NBIT_MSG_TID           = &HC5?
%ISDB_NBIT_REF_TID           = &HC6?
%ISDB_LDT_PID                = &H0025??
%ISDB_LDT_TID                = &HC7?
%ISDB_SDTT_PID               = &H0023??
%ISDB_SDTT_ALT_PID           = &H0028??
%ISDB_SDTT_TID               = &HC3?
%ISDB_CDT_PID                = &H0029??
%ISDB_CDT_TID                = &HC8?
%SCTE_EAS_TID                = &HD8?
%SCTE_EAS_IB_PID             = &H1FFB??
%SCTE_EAS_OOB_PID            = &H1FFC??


' ########################################################################################
' Interface name = IMpeg2TableFilter
' IID = BDCDD913-9ECD-4FB2-81AE-ADF747EA75A5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMpeg2TableFilter_INTERFACE_DEFINED)
    %IMpeg2TableFilter_INTERFACE_DEFINED = 1

$IID_IMpeg2TableFilter = GUID$("{BDCDD913-9ECD-4FB2-81AE-ADF747EA75A5}")

INTERFACE IMpeg2TableFilter $IID_IMpeg2TableFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddPID ( _                                    ' VTable offset = 12
     BYVAL p AS WORD _                                  ' __in PID p
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTable ( _                                  ' VTable offset = 16
     BYVAL p AS WORD _                                  ' __in PID p
   , BYVAL t AS BYTE _                                  ' __in TID t
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddExtension ( _                              ' VTable offset = 20
     BYVAL p AS WORD _                                  ' __in PID p
   , BYVAL t AS BYTE _                                  ' __in TID t
   , BYVAL e AS WORD _                                  ' __in TEID e
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemovePID ( _                                 ' VTable offset = 24
     BYVAL p AS WORD _                                  ' __in PID p
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveTable ( _                               ' VTable offset = 28
     BYVAL p AS WORD _                                  ' __in PID p
   , BYVAL t AS BYTE _                                  ' __in TID t
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveExtension ( _                           ' VTable offset = 32
     BYVAL p AS WORD _                                  ' __in PID p
   , BYVAL t AS BYTE _                                  ' __in TID t
   , BYVAL e AS WORD _                                  ' __in TEID e
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMpeg2TableFilter_INTERFACE_DEFINED__ */


' // Size = 8 bytes
TYPE Mpeg2TableSampleHdr BYTE
   SectionCount      AS BYTE   ' BYTE
   Reserved(2)       AS BYTE   ' BYTE[3]
   SectionOffsets(0) AS LONG   ' long[1]
END TYPE

$CLSID_Mpeg2TableFilter = GUID$("{752845F1-758F-4C83-A043-4270C593308E}")
$LIBID_Mpeg2DataLib = GUID$("{DBAF6C1B-B6A4-4898-AE65-204F0D9509A1}")

$CLSID_SectionList = GUID$("{73DA5D04-4347-45D3-A9DC-FAE9DDBE558D}")
$CLSID_Mpeg2Stream = GUID$("{F91D96C7-8509-4D0B-AB26-A0DD10904BB7}")
$CLSID_Mpeg2Data = GUID$("{C666E115-BB62-4027-A113-82D643FE2D99}")

' ########################################################################################
' Interface name = IMpeg2Data
' IID = 9B396D40-F380-4E3C-A514-1A82BF6EBFE6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMpeg2Data_INTERFACE_DEFINED)
   %IMpeg2Data_INTERFACE_DEFINED = 1

$IID_IMpeg2Data = GUID$("{9B396D40-F380-4E3C-A514-1A82BF6EBFE6}")

INTERFACE IMpeg2Data $IID_IMpeg2Data

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSection ( _                                ' VTable offset = 12
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL tid AS BYTE _                                ' __in TID tid
   , BYREF pFilter AS MPEG2_FILTER _                    ' __in PMPEG2_FILTER pFilter
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppSectionList AS ISectionList _              ' __out ISectionList **ppSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTable ( _                                  ' VTable offset = 16
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL tid AS BYTE _                                ' __in TID tid
   , BYREF pFilter AS MPEG2_FILTER _                    ' __in PMPEG2_FILTER pFilter
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppSectionList AS ISectionList _              ' __out ISectionList **ppSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamOfSections ( _                       ' VTable offset = 20
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL tid AS BYTE _                                ' __in TID tid
   , BYREF pFilter AS MPEG2_FILTER _                    ' __in PMPEG2_FILTER pFilter
   , BYVAL hDataReadyEvent AS DWORD _                   ' __in HANDLE hDataReadyEvent
   , BYREF ppMpegStream AS IMpeg2Stream _               ' __out IMpeg2Stream **ppMpegStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMpeg2Data_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISectionList
' IID = AFEC1EB5-2A64-46C6-BF4B-AE3CCB6AFDB0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISectionList_INTERFACE_DEFINED)
    %ISectionList_INTERFACE_DEFINED = 1

$IID_ISectionList = GUID$("{AFEC1EB5-2A64-46C6-BF4B-AE3CCB6AFDB0}")

INTERFACE ISectionList $IID_ISectionList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL requestType AS LONG _                        ' __in MPEG_REQUEST_TYPE requestType
   , BYVAL pMpeg2Data AS IMpeg2Data _                   ' __in IMpeg2Data *pMpeg2Data
   , BYREF pContext AS MPEG_CONTEXT _                   ' __in PMPEG_CONTEXT pContext
   , BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL tid AS BYTE _                                ' __in TID tid
   , BYREF pFilter AS MPEG2_FILTER _                    ' __in PMPEG2_FILTER pFilter
   , BYVAL timeout AS DWORD _                           ' __in DWORD timeout
   , BYVAL hDoneEvent AS DWORD _                        ' __in HANDLE hDoneEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeWithRawSections ( _                 ' VTable offset = 16
     BYREF pmplSections AS MPEG_PACKET_LIST _           ' __in PMPEG_PACKET_LIST pmplSections
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelPendingRequest ( _                      ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfSections ( _                       ' VTable offset = 24
     BYREF pCount AS WORD _                             ' __out WORD *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSectionData ( _                            ' VTable offset = 28
     BYVAL sectionNumber AS WORD _                      ' __in WORD sectionNumber
   , BYREF pdwRawPacketLength AS DWORD _                ' __out DWORD *pdwRawPacketLength
   , BYREF ppSection AS SECTION _                       ' __out PSECTION *ppSection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgramIdentifier ( _                      ' VTable offset = 32
     BYREF pPid AS WORD _                               ' __out PID *pPid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableIdentifier ( _                        ' VTable offset = 36
     BYREF pTableId AS BYTE _                           ' __out TID *pTableId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISectionList_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMpeg2Stream
' IID = 400CC286-32A0-4CE4-9041-39571125A635
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMpeg2Stream_INTERFACE_DEFINED)
    %IMpeg2Stream_INTERFACE_DEFINED = 1

$IID_IMpeg2Stream = GUID$("{400CC286-32A0-4CE4-9041-39571125A635}")

INTERFACE IMpeg2Stream $IID_IMpeg2Stream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL requestType AS LONG _                        ' __in MPEG_REQUEST_TYPE requestType
   , BYVAL pMpeg2Data AS IMpeg2Data _                   ' __in IMpeg2Data *pMpeg2Data
   , BYREF pContext AS MPEG_CONTEXT _                   ' __in PMPEG_CONTEXT pContext
   , BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL tid AS BYTE _                                ' __in TID tid
   , BYREF pFilter AS MPEG2_FILTER _                    ' __in PMPEG2_FILTER pFilter
   , BYVAL hDataReadyEven AS DWORD _                    ' __in HANDLE hDataReadyEven
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SupplyDataBuffer ( _                          ' VTable offset = 16
     BYREF pStreamBuffer AS MPEG_STREAM_BUFFER _        ' __in PMPEG_STREAM_BUFFER pStreamBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMpeg2Stream_INTERFACE_DEFINED__ */

'#pragma pack(pop)
