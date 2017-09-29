' ########################################################################################
' Microsoft Windows
' File: dvbsiparser.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DVBSIPARSER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mpeg2structs.inc"
#INCLUDE ONCE "mpeg2data.inc"
#INCLUDE ONCE "mpeg2psiparser.inc"

' enum DVB_STRCONV_MODE
%STRCONV_MODE_DVB                  = 0
%STRCONV_MODE_DVB_EMPHASIS         = %STRCONV_MODE_DVB                  + 1
%STRCONV_MODE_DVB_WITHOUT_EMPHASIS = %STRCONV_MODE_DVB_EMPHASIS         + 1
%STRCONV_MODE_ISDB                 = %STRCONV_MODE_DVB_WITHOUT_EMPHASIS + 1

' ########################################################################################
' Interface name = IDvbSiParser
' IID = B758A7BD-14DC-449d-B828-35909ACB3B1E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbSiParser_INTERFACE_DEFINED)
    %IDvbSiParser_INTERFACE_DEFINED = 1

$IID_IDvbSiParser = GUID$("{B758A7BD-14DC-449d-B828-35909ACB3B1E}")

INTERFACE IDvbSiParser $IID_IDvbSiParser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL punkMpeg2Data AS IUnknown _                  ' __in IUnknown *punkMpeg2Data
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPAT ( _                                    ' VTable offset = 16
     BYREF ppPAT AS IPAT _                              ' __out IPAT **ppPAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCAT ( _                                    ' VTable offset = 20
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppCAT AS ICAT _                              ' __out ICAT **ppCAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPMT ( _                                    ' VTable offset = 24
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYREF pwProgramNumber AS WORD _                    ' __in_opt WORD *pwProgramNumber
   , BYREF ppPMT AS IPMT _                              ' __out IPMT **ppPMT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSDT ( _                                   ' VTable offset = 28
     BYREF ppTSDT AS ITSDT _                            ' __out ITSDT **ppTSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNIT ( _                                    ' VTable offset = 32
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwNetworkId AS WORD _                        ' __in_opt WORD *pwNetworkId
   , BYREF ppNIT AS IDVB_NIT _                          ' __out IDVB_NIT **ppNIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSDT ( _                                    ' VTable offset = 36
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwTransportStreamId AS WORD _                ' __in_opt WORD *pwTransportStreamId
   , BYREF ppSDT AS IDVB_SDT _                          ' __out IDVB_SDT **ppSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEIT ( _                                    ' VTable offset = 40
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwServiceId AS WORD _                        ' __in_opt WORD *pwServiceId
   , BYREF ppEIT AS IDVB_EIT _                          ' __out IDVB_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBAT ( _                                    ' VTable offset = 44
     BYREF pwBouquetId AS WORD _                        ' __in_opt WORD *pwBouquetId
   , BYREF ppBAT AS IDVB_BAT _                          ' __out IDVB_BAT **ppBAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRST ( _                                    ' VTable offset = 48
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppRST AS IDVB_RST _                          ' __out IDVB_RST **ppRST
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetST ( _                                     ' VTable offset = 52
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppST AS IDVB_ST _                            ' __out IDVB_ST **ppST
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTDT ( _                                    ' VTable offset = 56
     BYREF ppTDT AS IDVB_TDT _                          ' __out IDVB_TDT **ppTDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTOT ( _                                    ' VTable offset = 60
     BYREF ppTOT AS IDVB_TOT _                          ' __out IDVB_TOT **ppTOT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDIT ( _                                    ' VTable offset = 64
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppDIT AS IDVB_DIT _                          ' __out IDVB_DIT **ppDIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSIT ( _                                    ' VTable offset = 68
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppSIT AS IDVB_SIT _                          ' __out IDVB_SIT **ppSIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbSiParser_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbSiParser2
' IID = 0AC5525F-F816-42F4-93BA-4C0F32F46E54
' Inherited interface = IDvbSiParser
' ########################################################################################

#IF NOT %DEF(%IDvbSiParser2_INTERFACE_DEFINED)
    %IDvbSiParser2_INTERFACE_DEFINED = 1

$IID_IDvbSiParser2 = GUID$("{0AC5525F-F816-42F4-93BA-4C0F32F46E54}")

INTERFACE IDvbSiParser2 $IID_IDvbSiParser2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDvbSiParser methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL punkMpeg2Data AS IUnknown _                  ' __in IUnknown *punkMpeg2Data
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPAT ( _                                    ' VTable offset = 16
     BYREF ppPAT AS IPAT _                              ' __out IPAT **ppPAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCAT ( _                                    ' VTable offset = 20
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppCAT AS ICAT _                              ' __out ICAT **ppCAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPMT ( _                                    ' VTable offset = 24
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYREF pwProgramNumber AS WORD _                    ' __in_opt WORD *pwProgramNumber
   , BYREF ppPMT AS IPMT _                              ' __out IPMT **ppPMT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSDT ( _                                   ' VTable offset = 28
     BYREF ppTSDT AS ITSDT _                            ' __out ITSDT **ppTSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNIT ( _                                    ' VTable offset = 32
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwNetworkId AS WORD _                        ' __in_opt WORD *pwNetworkId
   , BYREF ppNIT AS IDVB_NIT _                          ' __out IDVB_NIT **ppNIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSDT ( _                                    ' VTable offset = 36
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwTransportStreamId AS WORD _                ' __in_opt WORD *pwTransportStreamId
   , BYREF ppSDT AS IDVB_SDT _                          ' __out IDVB_SDT **ppSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEIT ( _                                    ' VTable offset = 40
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwServiceId AS WORD _                        ' __in_opt WORD *pwServiceId
   , BYREF ppEIT AS IDVB_EIT _                          ' __out IDVB_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBAT ( _                                    ' VTable offset = 44
     BYREF pwBouquetId AS WORD _                        ' __in_opt WORD *pwBouquetId
   , BYREF ppBAT AS IDVB_BAT _                          ' __out IDVB_BAT **ppBAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRST ( _                                    ' VTable offset = 48
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppRST AS IDVB_RST _                          ' __out IDVB_RST **ppRST
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetST ( _                                     ' VTable offset = 52
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppST AS IDVB_ST _                            ' __out IDVB_ST **ppST
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTDT ( _                                    ' VTable offset = 56
     BYREF ppTDT AS IDVB_TDT _                          ' __out IDVB_TDT **ppTDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTOT ( _                                    ' VTable offset = 60
     BYREF ppTOT AS IDVB_TOT _                          ' __out IDVB_TOT **ppTOT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDIT ( _                                    ' VTable offset = 64
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppDIT AS IDVB_DIT _                          ' __out IDVB_DIT **ppDIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSIT ( _                                    ' VTable offset = 68
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppSIT AS IDVB_SIT _                          ' __out IDVB_SIT **ppSIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbSiParser2 method
   ' =====================================================================================
   METHOD GetEIT2 ( _                                   ' VTable offset = 72
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwServiceId AS WORD _                        ' __in_opt WORD *pwServiceId
   , BYREF pbSegment AS BYTE _                          ' __in_opt BYTE *pbSegment
   , BYREF ppEIT AS  IDVB_EIT2 _                        ' __out IDVB_EIT2 **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbSiParser2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbSiParser2
' IID = 900E4BB7-18CD-453F-98BE-3BE6AA211772
' Inherited interface = IDvbSiParser2
' ########################################################################################

#IF NOT %DEF(%IIsdbSiParser2_INTERFACE_DEFINED)
    %IIsdbSiParser2_INTERFACE_DEFINED = 1

$IID_IIsdbSiParser2 = GUID$("{900E4BB7-18CD-453F-98BE-3BE6AA211772}")

INTERFACE IIsdbSiParser2 $IID_IIsdbSiParser2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDvbSiParser methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL punkMpeg2Data AS IUnknown _                  ' __in IUnknown *punkMpeg2Data
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPAT ( _                                    ' VTable offset = 16
     BYREF ppPAT AS IPAT _                              ' __out IPAT **ppPAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCAT ( _                                    ' VTable offset = 20
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppCAT AS ICAT _                              ' __out ICAT **ppCAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPMT ( _                                    ' VTable offset = 24
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYREF pwProgramNumber AS WORD _                    ' __in_opt WORD *pwProgramNumber
   , BYREF ppPMT AS IPMT _                              ' __out IPMT **ppPMT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSDT ( _                                   ' VTable offset = 28
     BYREF ppTSDT AS ITSDT _                            ' __out ITSDT **ppTSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNIT ( _                                    ' VTable offset = 32
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwNetworkId AS WORD _                        ' __in_opt WORD *pwNetworkId
   , BYREF ppNIT AS IDVB_NIT _                          ' __out IDVB_NIT **ppNIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSDT ( _                                    ' VTable offset = 36
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwTransportStreamId AS WORD _                ' __in_opt WORD *pwTransportStreamId
   , BYREF ppSDT AS IDVB_SDT _                          ' __out IDVB_SDT **ppSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEIT ( _                                    ' VTable offset = 40
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwServiceId AS WORD _                        ' __in_opt WORD *pwServiceId
   , BYREF ppEIT AS IDVB_EIT _                          ' __out IDVB_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBAT ( _                                    ' VTable offset = 44
     BYREF pwBouquetId AS WORD _                        ' __in_opt WORD *pwBouquetId
   , BYREF ppBAT AS IDVB_BAT _                          ' __out IDVB_BAT **ppBAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRST ( _                                    ' VTable offset = 48
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppRST AS IDVB_RST _                          ' __out IDVB_RST **ppRST
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetST ( _                                     ' VTable offset = 52
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppST AS IDVB_ST _                            ' __out IDVB_ST **ppST
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTDT ( _                                    ' VTable offset = 56
     BYREF ppTDT AS IDVB_TDT _                          ' __out IDVB_TDT **ppTDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTOT ( _                                    ' VTable offset = 60
     BYREF ppTOT AS IDVB_TOT _                          ' __out IDVB_TOT **ppTOT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDIT ( _                                    ' VTable offset = 64
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppDIT AS IDVB_DIT _                          ' __out IDVB_DIT **ppDIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSIT ( _                                    ' VTable offset = 68
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppSIT AS IDVB_SIT _                          ' __out IDVB_SIT **ppSIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbSiParser2 method
   ' =====================================================================================
   METHOD GetEIT2 ( _                                   ' VTable offset = 72
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwServiceId AS WORD _                        ' __in_opt WORD *pwServiceId
   , BYREF pbSegment AS BYTE _                          ' __in_opt BYTE *pbSegment
   , BYREF ppEIT AS  IDVB_EIT2 _                        ' __out IDVB_EIT2 **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IIsdbSiParser2 method
   ' =====================================================================================
   ' In the inherited IDvbSiParser2 interface there is already a method called GetSDT.
   ' =====================================================================================
   METHOD GetSDT_ ( _                                   ' VTable offset = 76
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwTransportStreamId AS WORD _                ' __in_opt WORD *pwTransportStreamId
   , BYREF ppSDT AS IISDB_SDT _                         ' __out IISDB_SDT **ppSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBIT ( _                                    ' VTable offset = 80
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwOriginalNetworkId AS WORD _                ' __in_opt WORD *pwOriginalNetworkId
   , BYREF ppBIT AS IISDB_BIT _                         ' __out IISDB_BIT **ppBIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNBIT ( _                                   ' VTable offset = 84
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwOriginalNetworkId AS WORD _                ' __in_opt WORD *pwOriginalNetworkId
   , BYREF ppNBIT AS IISDB_NBIT _                       ' __out IISDB_NBIT **ppNBIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLDT ( _                                    ' VTable offset = 88
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwOriginalServiceId AS WORD _                ' __in_opt WORD *pwOriginalServiceId
   , BYREF ppLDT AS IISDB_LDT _                         ' __out IISDB_LDT **ppLDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSDTT ( _                                   ' VTable offset = 92
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYREF pwTableIdExt AS WORD _                       ' __in_opt WORD *pwTableIdExt
   , BYREF ppSDTT AS IISDB_SDTT _                       ' __out IISDB_SDTT **ppSDTT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCDT ( _                                    ' VTable offset = 96
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYVAL bSectionNumber AS BYTE _                     ' __in BYTE bSectionNumber
   , BYREF pwDownloadDataId AS WORD _                   ' __in_opt WORD *pwDownloadDataId
   , BYREF ppCDT AS IISDB_CDT _                         ' __out IISDB_CDT **ppCDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEMM ( _                                    ' VTable offset = 100
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYVAL wTableIdExt AS WORD _                        ' __in WORD wTableIdExt
   , BYREF ppEMM AS IISDB_EMM _                         ' __out IISDB_EMM **ppEMM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbSiParser2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_NIT
' IID = C64935F4-29E4-4e22-911A-63F7F55CB097
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_NIT_INTERFACE_DEFINED)
    %IDVB_NIT_INTERFACE_DEFINED = 1

$IID_IDVB_NIT = GUID$("{C64935F4-29E4-4e22-911A-63F7F55CB097}")

INTERFACE IDVB_NIT $IID_IDVB_NIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkId ( _                              ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 32
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 36
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTransportStreamId ( _                ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordOriginalNetworkId ( _                ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 60
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 64
     BYREF ppNIT AS IDVB_NIT _                          ' __out IDVB_NIT **ppNIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 68
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 76
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_NIT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_SDT
' IID = 02CAD8D3-FE43-48e2-90BD-450ED9A8A5FD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_SDT_INTERFACE_DEFINED)
    %IDVB_SDT_INTERFACE_DEFINED = 1

$IID_IDVB_SDT = GUID$("{02CAD8D3-FE43-48e2-90BD-450ED9A8A5FD}")

INTERFACE IDVB_SDT $IID_IDVB_SDT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportStreamId ( _                      ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 28
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEITScheduleFlag ( _                  ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEITPresentFollowingFlag ( _          ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRunningStatus ( _                    ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordFreeCAMode ( _                       ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 64
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 68
     BYREF ppSDT AS IDVB_SDT _                          ' __out IDVB_SDT **ppSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 72
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 80
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_SDT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDB_SDT
' IID = 3F3DC9A2-BB32-4FB9-AE9E-D856848927A3
' Inherited interface = IDVB_SDT
' ########################################################################################

#IF NOT %DEF(%IISDB_SDT_INTERFACE_DEFINED)
    %IISDB_SDT_INTERFACE_DEFINED = 1

$IID_IISDB_SDT = GUID$("{3F3DC9A2-BB32-4FB9-AE9E-D856848927A3}")

INTERFACE IISDB_SDT $IID_IISDB_SDT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRecordEITUserDefinedFlags ( _              ' VTable offset = 12
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_SDT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_EIT
' IID = 442DB029-02CB-4495-8B92-1C13375BCE99
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_EIT_INTERFACE_DEFINED)
    %IDVB_EIT_INTERFACE_DEFINED = 1

$IID_IDVB_EIT = GUID$("{442DB029-02CB-4495-8B92-1C13375BCE99}")

INTERFACE IDVB_EIT $IID_IDVB_EIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceId ( _                              ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportStreamId ( _                      ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentLastSectionNumber ( _               ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastTableId ( _                            ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 40
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEventId ( _                          ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordStartTime ( _                        ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDuration ( _                         ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdVal AS MPEG_DURATION _                    ' __out MPEG_DURATION *pmdVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRunningStatus ( _                    ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordFreeCAMode ( _                       ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 64
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 68
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 72
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 76
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 80
     BYREF ppEIT AS IDVB_EIT _                          ' __out IDVB_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 84
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 88
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 92
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_EIT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_EIT2
' IID = 61A389E0-9B9E-4ba0-AEEA-5DDD159820EA
' Inherited interface = IDVB_EIT
' ########################################################################################

#IF NOT %DEF(%IDVB_EIT2_INTERFACE_DEFINED)
    %IDVB_EIT2_INTERFACE_DEFINED = 1

$IID_IDVB_EIT2 = GUID$("{61A389E0-9B9E-4ba0-AEEA-5DDD159820EA}")

INTERFACE IDVB_EIT2 $IID_IDVB_EIT2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDVB_EIT methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceId ( _                              ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportStreamId ( _                      ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentLastSectionNumber ( _               ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastTableId ( _                            ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 40
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEventId ( _                          ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordStartTime ( _                        ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDuration ( _                         ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdVal AS MPEG_DURATION _                    ' __out MPEG_DURATION *pmdVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRunningStatus ( _                    ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordFreeCAMode ( _                       ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 64
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 68
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 72
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 76
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 80
     BYREF ppEIT AS IDVB_EIT _                          ' __out IDVB_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 84
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 88
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 92
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDVB_EIT2 methods
   ' =====================================================================================
   METHOD GetSegmentInfo ( _                            ' VTable offset = 96
     BYREF pbTid AS BYTE _                              ' __out BYTE *pbTid
   , BYREF pbSegment AS BYTE _                          ' __out BYTE *pbSegment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordSection ( _                          ' VTable offset = 100
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_EIT2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_BAT
' IID = ECE9BB0C-43B6-4558-A0EC-1812C34CD6CA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_BAT_INTERFACE_DEFINED)
    %IDVB_BAT_INTERFACE_DEFINED = 1

$IID_IDVB_BAT = GUID$("{ECE9BB0C-43B6-4558-A0EC-1812C34CD6CA}")

INTERFACE IDVB_BAT $IID_IDVB_BAT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBouquetId ( _                              ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __in IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 32
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 36
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTransportStreamId ( _                ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordOriginalNetworkId ( _                ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex  ( _               ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag  ( _                 ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable  ( _                     ' VTable offset = 60
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable  ( _                             ' VTable offset = 64
     BYREF ppBAT AS IDVB_BAT _                          ' __out IDVB_BAT **ppBAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent  ( _                   ' VTable offset = 68
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent  ( _                     ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_BAT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_RST
' IID = F47DCD04-1E23-4fb7-9F96-B40EEAD10B2B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_RST_INTERFACE_DEFINED)
    %IDVB_RST_INTERFACE_DEFINED = 1

$IID_IDVB_RST = GUID$("{F47DCD04-1E23-4fb7-9F96-B40EEAD10B2B}")

INTERFACE IDVB_RST $IID_IDVB_RST

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 16
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTransportStreamId ( _                ' VTable offset = 20
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordOriginalNetworkId ( _                ' VTable offset = 24
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 28
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEventId ( _                          ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRunningStatus ( _                    ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_RST_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_ST
' IID = 4D5B9F23-2A02-45de-BCDA-5D5DBFBFBE62
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_ST_INTERFACE_DEFINED)
    %IDVB_ST_INTERFACE_DEFINED = 1

$IID_IDVB_ST = GUID$("{4D5B9F23-2A02-45de-BCDA-5D5DBFBFBE62}")

INTERFACE IDVB_ST $IID_IDVB_ST

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataLength ( _                             ' VTable offset = 16
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 20
     BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_ST_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_TDT
' IID = 0780DC7D-D55C-4aef-97E6-6B75906E2796
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_TDT_INTERFACE_DEFINED)
    %IDVB_TDT_INTERFACE_DEFINED = 1

$IID_IDVB_TDT = GUID$("{0780DC7D-D55C-4aef-97E6-6B75906E2796}")

INTERFACE IDVB_TDT $IID_IDVB_TDT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUTCTime ( _                                ' VTable offset = 16
     BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_TDT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_TOT
' IID = 83295D6A-FABA-4ee1-9B15-8067696910AE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_TOT_INTERFACE_DEFINED)
    %IDVB_TOT_INTERFACE_DEFINED = 1

$IID_IDVB_TOT = GUID$("{83295D6A-FABA-4ee1-9B15-8067696910AE}")

INTERFACE IDVB_TOT $IID_IDVB_TOT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUTCTime ( _                                ' VTable offset = 16
     BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 20
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 24
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 28
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_TOT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDVB_DIT
' IID = 91BFFDF9-9432-410f-86EF-1C228ED0AD70
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_DIT_INTERFACE_DEFINED)
    %IDVB_DIT_INTERFACE_DEFINED = 1

$IID_IDVB_DIT = GUID$("{91BFFDF9-9432-410f-86EF-1C228ED0AD70}")

INTERFACE IDVB_DIT $IID_IDVB_DIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransitionFlag ( _                         ' VTable offset = 16
     BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_DIT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVB_SIT
' IID = 68CDCE53-8BEA-45c2-9D9D-ACF575A089B5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVB_SIT_INTERFACE_DEFINED)
    %IDVB_SIT_INTERFACE_DEFINED = 1

$IID_IDVB_SIT = GUID$("{68CDCE53-8BEA-45c2-9D9D-ACF575A089B5}")

INTERFACE IDVB_SIT $IID_IDVB_SIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 20
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 24
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 28
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 32
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRunningStatus ( _                    ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 56
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 60
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppSIT AS IDVB_SIT _                          ' __out IDVB_SIT **ppSIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 64
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVB_SIT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISDB_BIT
' IID = 537CD71E-0E46-4173-9001-BA043F3E49E2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IISDB_BIT_INTERFACE_DEFINED)
    %IISDB_BIT_INTERFACE_DEFINED = 1

$IID_IISDB_BIT = GUID$("{537CD71E-0E46-4173-9001-BA043F3E49E2}")

INTERFACE IISDB_BIT $IID_IISDB_BIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBroadcastViewPropriety ( _                 ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 28
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 32
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 36
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 40
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordBroadcasterId ( _                    ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 60
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_BIT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDB_NBIT
' IID = 1B1863EF-08F1-40B7-A559-3B1EFF8CAFA6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IISDB_NBIT_INTERFACE_DEFINED)
    %IISDB_NBIT_INTERFACE_DEFINED = 1

$IID_IISDB_NBIT = GUID$("{1B1863EF-08F1-40B7-A559-3B1EFF8CAFA6}")

INTERFACE IISDB_NBIT $IID_IISDB_NBIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordInformationId ( _                    ' VTable offset = 28
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordInformationType ( _                  ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptionBodyLocation ( _          ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordMessageSectionNumber ( _             ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordUserDefined ( _                      ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordNumberOfKeys ( _                     ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordKeys ( _                             ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbKeys AS DWORD _                            ' __out BYTE **pbKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 64
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 68
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_NBIT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDB_LDT
' IID = 141A546B-02FF-4FB9-A3A3-2F074B74A9A9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IISDB_LDT_INTERFACE_DEFINED)
    %IISDB_LDT_INTERFACE_DEFINED = 1

$IID_IISDB_LDT = GUID$("{141A546B-02FF-4FB9-A3A3-2F074B74A9A9}")

INTERFACE IISDB_LDT $IID_IISDB_LDT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalServiceId ( _                      ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportStreamId ( _                      ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 32
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptionId ( _                    ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 52
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_LDT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDB_SDTT
' IID = EE60EF2D-813A-4DC7-BF92-EA13DAC85313
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IISDB_SDTT_INTERFACE_DEFINED)
    %IISDB_SDTT_INTERFACE_DEFINED = 1

$IID_IISDB_SDTT = GUID$("{EE60EF2D-813A-4DC7-BF92-EA13DAC85313}")

INTERFACE IISDB_SDTT $IID_IISDB_SDTT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableIdExt ( _                             ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportStreamId ( _                      ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceId ( _                              ' VTable offset = 32
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 36
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordGroup ( _                            ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTargetVersion ( _                    ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordNewVersion ( _                       ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDownloadLevel ( _                    ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordVersionIndicator ( _                 ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordScheduleTimeShiftInformation ( _     ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfSchedules ( _                 ' VTable offset = 64
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordStartTimeByIndex ( _                 ' VTable offset = 68
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDurationByIndex ( _                  ' VTable offset = 72
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pmdVal AS MPEG_DURATION _                    ' __out MPEG_DURATION *pmdVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 76
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 80
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 84
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 88
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_SDTT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDB_CDT
' IID = 25FA92C2-8B80-4787-A841-3A0E8F17984B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IISDB_CDT_INTERFACE_DEFINED)
    %IISDB_CDT_INTERFACE_DEFINED = 1

$IID_IISDB_CDT = GUID$("{25FA92C2-8B80-4787-A841-3A0E8F17984B}")

INTERFACE IISDB_CDT $IID_IISDB_CDT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   , BYVAL bSectionNumber AS BYTE _                     ' __in BYTE bSectionNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDownloadDataId ( _                         ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSectionNumber ( _                          ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalNetworkId ( _                      ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataType ( _                               ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 36
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 40
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 44
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout_opt DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeOfDataModule ( _                       ' VTable offset = 48
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataModule ( _                             ' VTable offset = 52
     BYREF pbData AS DWORD _                            ' __out BYTE **pbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 56
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_CDT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDB_EMM
' IID = 0EDB556D-43AD-4938-9668-321B2FFECFD3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IISDB_EMM_INTERFACE_DEFINED)
    %IISDB_EMM_INTERFACE_DEFINED = 1

$IID_IISDB_EMM = GUID$("{0EDB556D-43AD-4938-9668-321B2FFECFD3}")

INTERFACE IISDB_EMM $IID_IISDB_EMM

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableIdExtension ( _                       ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataBytes ( _                              ' VTable offset = 24
     BYREF pwBufferLength AS WORD _                     ' __inout WORD *pwBufferLength
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSharedEmmMessage ( _                       ' VTable offset = 28
     BYREF pwLength AS WORD _                           ' __inout WORD *pwLength
   , BYREF ppbMessage AS DWORD _                        ' __out BYTE **ppbMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndividualEmmMessage ( _                   ' VTable offset = 32
     BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   , BYREF pwLength AS WORD _                           ' __out WORD *pwLength
   , BYREF ppbMessage AS DWORD _                        ' __out BYTE **ppbMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionHash ( _                            ' VTable offset = 36
     BYREF pdwVersionHash AS DWORD _                    ' __out DWORD *pdwVersionHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDB_EMM_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbServiceAttributeDescriptor
' IID = 0F37BD92-D6A1-4854-B950-3A969D27F30E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbServiceAttributeDescriptor_INTERFACE_DEFINED)
    %IDvbServiceAttributeDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbServiceAttributeDescriptor = GUID$("{0F37BD92-D6A1-4854-B950-3A969D27F30E}")

INTERFACE IDvbServiceAttributeDescriptor $IID_IDvbServiceAttributeDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordNumericSelectionFlag ( _             ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordVisibleServiceFlag ( _               ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbServiceAttributeDescriptor_INTERFACE_DEFINED__ */


' enum CRID_LOCATION
%CRID_LOCATION_IN_DESCRIPTOR = 0?
%CRID_LOCATION_IN_CIT        = &H1?
%CRID_LOCATION_DVB_RESERVED1 = &H2?
%CRID_LOCATION_DVB_RESERVED2 = &H3?


' ########################################################################################
' Interface name = IDvbContentIdentifierDescriptor
' IID = 05E0C1EA-F661-4053-9FBF-D93B28359838
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbContentIdentifierDescriptor_INTERFACE_DEFINED)
    %IDvbContentIdentifierDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbContentIdentifierDescriptor = GUID$("{05E0C1EA-F661-4053-9FBF-D93B28359838}")

INTERFACE IDvbContentIdentifierDescriptor $IID_IDvbContentIdentifierDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCrid ( _                             ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbType AS BYTE _                             ' __out BYTE *pbType
   , BYREF pbLocation AS BYTE _                         ' __out BYTE *pbLocation
   , BYREF pbLength AS BYTE _                           ' __out BYTE *pbLength
   , BYREF ppbBytes AS DWORD _                          ' __out BYTE **ppbBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbContentIdentifierDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbDefaultAuthorityDescriptor
' IID = 05EC24D1-3A31-44E7-B408-67C60A352276
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbDefaultAuthorityDescriptor_INTERFACE_DEFINED)
    %IDvbDefaultAuthorityDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbDefaultAuthorityDescriptor = GUID$("{05EC24D1-3A31-44E7-B408-67C60A352276}")

INTERFACE IDvbDefaultAuthorityDescriptor $IID_IDvbDefaultAuthorityDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultAuthority ( _                       ' VTable offset = 20
     BYREF pbLength AS BYTE _                           ' __out BYTE *pbLength
   , BYREF ppbBytes AS BYTE _                           ' __out BYTE **ppbBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbDefaultAuthorityDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbSatelliteDeliverySystemDescriptor
' IID = 02F2225A-805B-4EC5-A9A6-F9B5913CD470
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbSatelliteDeliverySystemDescriptor_INTERFACE_DEFINED)
    %IDvbSatelliteDeliverySystemDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbSatelliteDeliverySystemDescriptor = GUID$("{02F2225A-805B-4EC5-A9A6-F9B5913CD470}")

INTERFACE IDvbSatelliteDeliverySystemDescriptor $IID_IDvbSatelliteDeliverySystemDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrequency ( _                              ' VTable offset = 20
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOrbitalPosition ( _                        ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWestEastFlag ( _                           ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolarization ( _                           ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModulation ( _                             ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSymbolRate ( _                             ' VTable offset = 40
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFECInner ( _                               ' VTable offset = 44
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbSatelliteDeliverySystemDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbCableDeliverySystemDescriptor
' IID = DFB98E36-9E1A-4862-9946-993A4E59017B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbCableDeliverySystemDescriptor_INTERFACE_DEFINED)
    %IDvbCableDeliverySystemDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbCableDeliverySystemDescriptor = GUID$("{DFB98E36-9E1A-4862-9946-993A4E59017B}")

INTERFACE IDvbCableDeliverySystemDescriptor $IID_IDvbCableDeliverySystemDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrequency ( _                              ' VTable offset = 20
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFECOuter ( _                               ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModulation ( _                             ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSymbolRate ( _                             ' VTable offset = 32
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFECInner ( _                               ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbCableDeliverySystemDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbTerrestrialDeliverySystemDescriptor
' IID = ED7E1B91-D12E-420c-B41D-A49D84FE1823
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED)
    %IDvbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbTerrestrialDeliverySystemDescriptor = GUID$("{ED7E1B91-D12E-420c-B41D-A49D84FE1823}")

INTERFACE IDvbTerrestrialDeliverySystemDescriptor $IID_IDvbTerrestrialDeliverySystemDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCentreFrequency ( _                        ' VTable offset = 20
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandwidth ( _                              ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstellation ( _                          ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHierarchyInformation ( _                   ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodeRateHPStream ( _                       ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodeRateLPStream ( _                       ' VTable offset = 40
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuardInterval ( _                          ' VTable offset = 44
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransmissionMode ( _                       ' VTable offset = 48
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOtherFrequencyFlag ( _                     ' VTable offset = 52
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbTerrestrial2DeliverySystemDescriptor
' IID = 20EE9BE9-CD57-49AB-8F6E-1D07AEB8E482
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbTerrestrial2DeliverySystemDescriptor_INTERFACE_DEFINED)
    %IDvbTerrestrial2DeliverySystemDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbTerrestrial2DeliverySystemDescriptor = GUID$("{20EE9BE9-CD57-49AB-8F6E-1D07AEB8E482}")

INTERFACE IDvbTerrestrial2DeliverySystemDescriptor $IID_IDvbTerrestrial2DeliverySystemDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTagExtension ( _                           ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCentreFrequency ( _                        ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPLPId ( _                                  ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetT2SystemId ( _                             ' VTable offset = 32
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMultipleInputMode ( _                      ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandwidth ( _                              ' VTable offset = 40
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuardInterval ( _                          ' VTable offset = 44
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransmissionMode ( _                       ' VTable offset = 48
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCellId ( _                                 ' VTable offset = 52
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOtherFrequencyFlag ( _                     ' VTable offset = 56
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTFSFlag ( _                                ' VTable offset = 60
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbTerrestrial2DeliverySystemDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbFrequencyListDescriptor
' IID = 1CADB613-E1DD-4512-AFA8-BB7A007EF8B1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbFrequencyListDescriptor_INTERFACE_DEFINED)
    %IDvbFrequencyListDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbFrequencyListDescriptor = GUID$("{1CADB613-E1DD-4512-AFA8-BB7A007EF8B1}")

INTERFACE IDvbFrequencyListDescriptor $IID_IDvbFrequencyListDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodingType ( _                             ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCentreFrequency ( _                  ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbFrequencyListDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbPrivateDataSpecifierDescriptor
' IID = 5660A019-E75A-4b82-9B4C-ED2256D165A2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbPrivateDataSpecifierDescriptor_INTERFACE_DEFINED)
    %IDvbPrivateDataSpecifierDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbPrivateDataSpecifierDescriptor = GUID$("{5660A019-E75A-4b82-9B4C-ED2256D165A2}")

INTERFACE IDvbPrivateDataSpecifierDescriptor $IID_IDvbPrivateDataSpecifierDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateDataSpecifier ( _                   ' VTable offset = 20
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbPrivateDataSpecifierDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbLogicalChannelDescriptor
' IID = CF1EDAFF-3FFD-4cf7-8201-35756ACBF85F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbLogicalChannelDescriptor_INTERFACE_DEFINED)
    %IDvbLogicalChannelDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbLogicalChannelDescriptor = GUID$("{CF1EDAFF-3FFD-4cf7-8201-35756ACBF85F}")

INTERFACE IDvbLogicalChannelDescriptor $IID_IDvbLogicalChannelDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLogicalChannelNumber ( _             ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbLogicalChannelDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbLogicalChannelDescriptor2
' IID = 43ACA974-4BE8-4b98-BC17-9EAFD788B1D7
' Inherited interface = IDvbLogicalChannelDescriptor
' ########################################################################################

#IF NOT %DEF(%IDvbLogicalChannelDescriptor2_INTERFACE_DEFINED)
    %IDvbLogicalChannelDescriptor2_INTERFACE_DEFINED = 1

$IID_IDvbLogicalChannelDescriptor2 = GUID$("{43ACA974-4BE8-4b98-BC17-9EAFD788B1D7}")

INTERFACE IDvbLogicalChannelDescriptor2 $IID_IDvbLogicalChannelDescriptor2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDvbLogicalChannelDescriptor methods
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLogicalChannelNumber ( _             ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbLogicalChannelDescriptor2 method
   ' =====================================================================================
   METHOD GetRecordLogicalChannelAndVisibility ( _      ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbLogicalChannelDescriptor2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbLogicalChannel2Descriptor
' IID = F69C3747-8A30-4980-998C-01FE7F0BA35A
' Inherited interface = IDvbLogicalChannelDescriptor2
' ########################################################################################

#IF NOT %DEF(%IDvbLogicalChannel2Descriptor_INTERFACE_DEFINED)
    %IDvbLogicalChannel2Descriptor_INTERFACE_DEFINED = 1

$IID_IDvbLogicalChannel2Descriptor = GUID$("{F69C3747-8A30-4980-998C-01FE7F0BA35A}")

INTERFACE IDvbLogicalChannel2Descriptor $IID_IDvbLogicalChannel2Descriptor

   INHERIT IUnknown

   ' =====================================================================================
   ' IDvbLogicalChannelDescriptor methods
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLogicalChannelNumber ( _             ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbLogicalChannelDescriptor2 method
   ' =====================================================================================
   METHOD GetRecordLogicalChannelAndVisibility ( _      ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbLogicalChannel2Descriptor methods
   ' =====================================================================================
   METHOD GetCountOfLists ( _                           ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListId ( _                                 ' VTable offset = 40
     BYVAL bListIndex AS BYTE _                         ' __in BYTE bListIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListNameW ( _                              ' VTable offset = 44
     BYVAL bListIndex AS BYTE _                         ' __in BYTE bListIndex
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListCountryCode ( _                        ' VTable offset = 48
     BYVAL bListIndex AS BYTE _                         ' __in BYTE bListIndex
   , BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4)  char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListCountOfRecords ( _                     ' VTable offset = 52
     BYVAL bChannelListIndex AS BYTE _                  ' __in BYTE bChannelListIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListRecordServiceId ( _                    ' VTable offset = 56
     BYVAL bListIndex AS BYTE _                         ' __in BYTE bListIndex
   , BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListRecordLogicalChannelNumber ( _         ' VTable offset = 60
     BYVAL bListIndex AS BYTE _                         ' __in BYTE bListIndex
   , BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListRecordLogicalChannelAndVisibility ( _  ' VTable offset = 64
     BYVAL bListIndex AS BYTE _                         ' __in BYTE bListIndex
   , BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbLogicalChannel2Descriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbHDSimulcastLogicalChannelDescriptor
' IID = 1EA8B738-A307-4680-9E26-D0A908C824F4
' Inherited interface = IDvbLogicalChannelDescriptor2
' ########################################################################################

#IF NOT %DEF(%IDvbHDSimulcastLogicalChannelDescriptor_INTERFACE_DEFINED)
    %IDvbHDSimulcastLogicalChannelDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbHDSimulcastLogicalChannelDescriptor = GUID$("{1EA8B738-A307-4680-9E26-D0A908C824F4}")

INTERFACE IDvbHDSimulcastLogicalChannelDescriptor $IID_IDvbHDSimulcastLogicalChannelDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   ' IDvbLogicalChannelDescriptor methods
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLogicalChannelNumber ( _             ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbLogicalChannelDescriptor2 method
   ' =====================================================================================
   METHOD GetRecordLogicalChannelAndVisibility ( _      ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbHDSimulcastLogicalChannelDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbDataBroadcastIDDescriptor
' IID = 1EA8B738-A307-4680-9E26-D0A908C824F4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbDataBroadcastIDDescriptor_INTERFACE_DEFINED)
    %IDvbDataBroadcastIDDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbDataBroadcastIDDescriptor = GUID$("{5F26F518-65C8-4048-91F2-9290F59F7B90}")

INTERFACE IDvbDataBroadcastIDDescriptor $IID_IDvbDataBroadcastIDDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataBroadcastID ( _                        ' VTable offset = 20
     BYREF pwVal AS DWORD _                             ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDSelectorBytes ( _                        ' VTable offset = 24
     BYREF pbLen AS BYTE _                              ' __inout BYTE *pbLen
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbDataBroadcastIDDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbDataBroadcastDescriptor
' IID = D1EBC1D6-8B60-4c20-9CAF-E59382E7C400
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbDataBroadcastDescriptor_INTERFACE_DEFINED)
    %IDvbDataBroadcastDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbDataBroadcastDescriptor = GUID$("{D1EBC1D6-8B60-4c20-9CAF-E59382E7C400}")

INTERFACE IDvbDataBroadcastDescriptor $IID_IDvbDataBroadcastDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataBroadcastID ( _                        ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentTag ( _                           ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectorLength ( _                         ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectorBytes ( _                          ' VTable offset = 32
     BYREF pbLen AS BYTE _                              ' __inout BYTE *pbLen
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLangID ( _                                 ' VTable offset = 36
     BYREF pulVal AS DWORD _                            ' __out ULONG *pulVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextLength ( _                             ' VTable offset = 40
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 44
     BYREF pbLen AS BYTE _                              ' __inout BYTE *pbLen
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbDataBroadcastDescriptor_INTERFACE_DEFINED__ */


' enum DESC_LINKAGE_TYPE
%DESC_LINKAGE_RESERVED0               = 0?
%DESC_LINKAGE_INFORMATION             = %DESC_LINKAGE_RESERVED0               + 1
%DESC_LINKAGE_EPG                     = %DESC_LINKAGE_INFORMATION             + 1
%DESC_LINKAGE_CA_REPLACEMENT          = %DESC_LINKAGE_EPG                     + 1
%DESC_LINKAGE_COMPLETE_NET_BOUQUET_SI = %DESC_LINKAGE_CA_REPLACEMENT          + 1
%DESC_LINKAGE_REPLACEMENT             = %DESC_LINKAGE_COMPLETE_NET_BOUQUET_SI + 1
%DESC_LINKAGE_DATA                    = %DESC_LINKAGE_REPLACEMENT             + 1
%DESC_LINKAGE_RESERVED1               = &H7?
%DESC_LINKAGE_USER                    = &H8?
%DESC_LINKAGE_RESERVED2               = &Hff?


' ########################################################################################
' Interface name = IDvbLinkageDescriptor
' IID = 1CDF8B31-994A-46fc-ACFD-6A6BE8934DD5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbLinkageDescriptor_INTERFACE_DEFINED)
    %IDvbLinkageDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbLinkageDescriptor = GUID$("{1CDF8B31-994A-46fc-ACFD-6A6BE8934DD5}")

INTERFACE IDvbLinkageDescriptor $IID_IDvbLinkageDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSId ( _                                   ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetONId ( _                                   ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceId ( _                              ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkageType ( _                            ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateDataLength ( _                      ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 40
     BYREF pbLen AS BYTE _                              ' __inout BYTE *pbLen
   , BYVAL pbData AS BYTE PTR _                         ' __out BYTE *pbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbLinkageDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbTeletextDescriptor
' IID = 9CD29D47-69C6-4f92-98A9-210AF1B7303A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbTeletextDescriptor_INTERFACE_DEFINED)
    %IDvbTeletextDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbTeletextDescriptor = GUID$("{9CD29D47-69C6-4f92-98A9-210AF1B7303A}")

INTERFACE IDvbTeletextDescriptor $IID_IDvbTeletextDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLangId ( _                           ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pulVal AS DWORD _                            ' __out ULONG *pulVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTeletextType ( _                     ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordMagazineNumber ( _                   ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordPageNumber ( _                       ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbTeletextDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbSubtitlingDescriptor
' IID = 9B25FE1D-FA23-4e50-9784-6DF8B26F8A49
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbSubtitlingDescriptor_INTERFACE_DEFINED)
    %IDvbSubtitlingDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbSubtitlingDescriptor = GUID$("{9B25FE1D-FA23-4e50-9784-6DF8B26F8A49}")

INTERFACE IDvbSubtitlingDescriptor $IID_IDvbSubtitlingDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLangId ( _                           ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pulVal AS DWORD _                            ' __out ULONG *pulVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordSubtitlingType ( _                   ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCompositionPageID ( _                ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordAncillaryPageID ( _                  ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbSubtitlingDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbServiceDescriptor
' IID = F9C7FBCF-E2D6-464d-B32D-2EF526E49290
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbServiceDescriptor_INTERFACE_DEFINED)
    %IDvbServiceDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbServiceDescriptor = GUID$("{F9C7FBCF-E2D6-464d-B32D-2EF526E49290}")

INTERFACE IDvbServiceDescriptor $IID_IDvbServiceDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceType ( _                            ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceProviderName ( _                    ' VTable offset = 24
     BYREF pszName AS DWORD _                           ' __out char **pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceProviderNameW ( _                   ' VTable offset = 28
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceName ( _                            ' VTable offset = 32
     BYREF pszName AS DWORD _                           ' __out char **pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcessedServiceName ( _                   ' VTable offset = 36
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceNameEmphasized ( _                  ' VTable offset = 36
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbServiceDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbServiceDescriptor2
' IID = D6C76506-85AB-487C-9B2B-36416511E4A2
' Inherited interface = IDvbServiceDescriptor
' ########################################################################################

#IF NOT %DEF(%IDvbServiceDescriptor2_INTERFACE_DEFINED)
    %IDvbServiceDescriptor2_INTERFACE_DEFINED = 1

$IID_IDvbServiceDescriptor2 = GUID$("{D6C76506-85AB-487C-9B2B-36416511E4A2}")

INTERFACE IDvbServiceDescriptor2 $IID_IDvbServiceDescriptor2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDvbServiceDescriptor methods
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceType ( _                            ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceProviderName ( _                    ' VTable offset = 24
     BYREF pszName AS DWORD _                           ' __out char **pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceProviderNameW ( _                   ' VTable offset = 28
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceName ( _                            ' VTable offset = 32
     BYREF pszName AS DWORD _                           ' __out char **pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcessedServiceName ( _                   ' VTable offset = 36
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceNameEmphasized ( _                  ' VTable offset = 36
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDvbServiceDescriptor2 methods
   ' =====================================================================================
   METHOD GetServiceProviderNameW_ ( _                  ' VTable offset = 40
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceNameW ( _                           ' VTable offset = 44
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbServiceDescriptor2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbServiceListDescriptor
' IID = 05DB0D8F-6008-491a-ACD3-7090952707D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbServiceListDescriptor_INTERFACE_DEFINED)
    %IDvbServiceListDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbServiceListDescriptor = GUID$("{05DB0D8F-6008-491a-ACD3-7090952707D0}")

INTERFACE IDvbServiceListDescriptor $IID_IDvbServiceListDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceId ( _                        ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceType ( _                      ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbServiceListDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbMultilingualServiceNameDescriptor
' IID = 2D80433B-B32C-47ef-987F-E78EBB773E34
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbMultilingualServiceNameDescriptor_INTERFACE_DEFINED)
    %IDvbMultilingualServiceNameDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbMultilingualServiceNameDescriptor = GUID$("{2D80433B-B32C-47ef-987F-E78EBB773E34}")

INTERFACE IDvbMultilingualServiceNameDescriptor $IID_IDvbMultilingualServiceNameDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordLangId ( _                           ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF ulVal AS LONG _                              ' __out ULONG *ulVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceProviderNameW ( _             ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceNameW ( _                     ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbMultilingualServiceNameDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbNetworkNameDescriptor
' IID = 5B2A80CF-35B9-446C-B3E4-048B761DBC51
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbNetworkNameDescriptor_INTERFACE_DEFINED)
    %IDvbNetworkNameDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbNetworkNameDescriptor = GUID$("{5B2A80CF-35B9-446C-B3E4-048B761DBC51}")

INTERFACE IDvbNetworkNameDescriptor $IID_IDvbNetworkNameDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkName ( _                            ' VTable offset = 20
     BYREF pszName AS DWORD _                           ' __out char **pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkNameW ( _                           ' VTable offset = 24
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbNetworkNameDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbShortEventDescriptor
' IID = B170BE92-5B75-458E-9C6E-B0008231491A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbShortEventDescriptor_INTERFACE_DEFINED)
    %IDvbShortEventDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbShortEventDescriptor = GUID$("{B170BE92-5B75-458E-9C6E-B0008231491A}")

INTERFACE IDvbShortEventDescriptor $IID_IDvbShortEventDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode ( _                           ' VTable offset = 20
     BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4) char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventNameW ( _                             ' VTable offset = 24
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextW ( _                                  ' VTable offset = 28
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbShortEventDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbExtendedEventDescriptor
' IID = C9B22ECA-85F4-499F-B1DB-EFA93A91EE5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbExtendedEventDescriptor_INTERFACE_DEFINED)
    %IDvbExtendedEventDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbExtendedEventDescriptor = GUID$("{C9B22ECA-85F4-499F-B1DB-EFA93A91EE57}")

INTERFACE IDvbExtendedEventDescriptor $IID_IDvbExtendedEventDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptorNumber ( _                       ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastDescriptorNumber ( _                   ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode ( _                           ' VTable offset = 28
     BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4) char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordItemW ( _                            ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrDesc AS WSTRING _                       ' __out BSTR *pbstrDesc
   , BYREF pbstrItem AS WSTRING _                       ' __out BSTR *pbstrItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConcatenatedItemW ( _                      ' VTable offset = 40
     BYVAL pFollowingDescriptor AS IDvbExtendedEventDescriptor _ ' __in IDvbExtendedEventDescriptor *pFollowingDescriptor
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrDesc AS WSTRING _                       ' __out BSTR *pbstrDesc
   , BYREF pbstrItem AS WSTRING _                       ' __out BSTR *pbstrItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextW ( _                                  ' VTable offset = 44
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConcatenatedTextW ( _                      ' VTable offset = 48
     BYVAL FollowingDescriptor AS IDvbExtendedEventDescriptor _ ' __in IDvbExtendedEventDescriptor *FollowingDescriptor
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordItemRawBytes ( _                     ' VTable offset = 52
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF ppbRawItem AS DWORD _                        ' __out BYTE **ppbRawItem
   , BYREF pbItemLength AS BYTE _                       ' __out BYTE *pbItemLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbExtendedEventDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbComponentDescriptor
' IID = 91E405CF-80E7-457F-9096-1B9D1CE32141
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbComponentDescriptor_INTERFACE_DEFINED)
    %IDvbComponentDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbComponentDescriptor = GUID$("{91E405CF-80E7-457F-9096-1B9D1CE32141}")

INTERFACE IDvbComponentDescriptor $IID_IDvbComponentDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamContent ( _                          ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentTag ( _                           ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode ( _                           ' VTable offset = 32
     BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4) char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextW ( _                                  ' VTable offset = 44
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbComponentDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbContentDescriptor
' IID = 2E883881-A467-412A-9D63-6F2B6DA05BF0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbContentDescriptor_INTERFACE_DEFINED)
    %IDvbContentDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbContentDescriptor = GUID$("{2E883881-A467-412A-9D63-6F2B6DA05BF0}")

INTERFACE IDvbContentDescriptor $IID_IDvbContentDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordContentNibbles ( _                   ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbValLevel1 AS BYTE _                        ' __out BYTE *pbValLevel1
   , BYREF pbValLevel2 AS BYTE _                        ' __out BYTE *pbValLevel2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordUserNibbles ( _                      ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal1 AS BYTE _                             ' __out BYTE *pbVal1
   , BYREF pbVal2 AS BYTE _                             ' __out BYTE *pbVal2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbContentDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDvbParentalRatingDescriptor
' IID = 3AD9DDE1-FB1B-4186-937F-22E6B5A72A10
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvbParentalRatingDescriptor_INTERFACE_DEFINED)
    %IDvbParentalRatingDescriptor_INTERFACE_DEFINED = 1

$IID_IDvbParentalRatingDescriptor = GUID$("{3AD9DDE1-FB1B-4186-937F-22E6B5A72A10}")

INTERFACE IDvbParentalRatingDescriptor $IID_IDvbParentalRatingDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRating ( _                           ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pszCountryCode AS ASCIIZ _                   ' __out_ecount(4) char *pszCountryCode
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvbParentalRatingDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbTerrestrialDeliverySystemDescriptor
' IID = 39FAE0A6-D151-44DD-A28A-765DE5991670
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED)
    %IIsdbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbTerrestrialDeliverySystemDescriptor = GUID$("{39FAE0A6-D151-44DD-A28A-765DE5991670}")

INTERFACE IIsdbTerrestrialDeliverySystemDescriptor $IID_IIsdbTerrestrialDeliverySystemDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAreaCode ( _                               ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuardInterval ( _                          ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransmissionMode ( _                       ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordFrequency ( _                        ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbTSInformationDescriptor
' IID = D7AD183E-38F5-4210-B55F-EC8D601BBD47
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbTSInformationDescriptor_INTERFACE_DEFINED)
    %IIsdbTSInformationDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbTSInformationDescriptor = GUID$("{D7AD183E-38F5-4210-B55F-EC8D601BBD47}")

INTERFACE IIsdbTSInformationDescriptor $IID_IIsdbTSInformationDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRemoteControlKeyId ( _                     ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSNameW ( _                                ' VTable offset = 24
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTransmissionTypeInfo ( _             ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordNumberOfServices ( _                 ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceIdByIndex ( _                 ' VTable offset = 40
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL bServiceIndex AS BYTE _                      ' __in BYTE bServiceIndex
   , BYREF pdwVal AS WORD _                             ' __out WORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbTSInformationDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbDigitalCopyControlDescriptor
' IID = 1A28417E-266A-4BB8-A4BD-D782BCFB8161
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbDigitalCopyControlDescriptor_INTERFACE_DEFINED)
    %IIsdbDigitalCopyControlDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbDigitalCopyControlDescriptor = GUID$("{1A28417E-266A-4BB8-A4BD-D782BCFB8161}")

INTERFACE IIsdbDigitalCopyControlDescriptor $IID_IIsdbDigitalCopyControlDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCopyControl ( _                            ' VTable offset = 20
     BYREF pbDigitalRecordingControlData AS BYTE _      ' __out BYTE *pbDigitalRecordingControlData
   , BYREF pbCopyControlType AS BYTE _                  ' __out BYTE *pbCopyControlType
   , BYREF pbAPSControlData AS BYTE _                   ' __out BYTE *pbAPSControlData
   , BYREF pbMaximumBitrate AS BYTE _                   ' __out BYTE *pbMaximumBitrate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCopyControl ( _                      ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbComponentTag AS BYTE _                     ' __out BYTE *pbComponentTag
   , BYREF pbDigitalRecordingControlData AS BYTE _      ' __out BYTE *pbDigitalRecordingControlData
   , BYREF pbCopyControlType AS BYTE _                  ' __out BYTE *pbCopyControlType
   , BYREF pbAPSControlData AS BYTE _                   ' __out BYTE *pbAPSControlData
   , BYREF pbMaximumBitrate AS BYTE _                   ' __out BYTE *pbMaximumBitrate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbDigitalCopyControlDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbAudioComponentDescriptor
' IID = 679D2002-2425-4BE4-A4C7-D6632A574F4D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbAudioComponentDescriptor_INTERFACE_DEFINED)
    %IIsdbAudioComponentDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbAudioComponentDescriptor = GUID$("{679D2002-2425-4BE4-A4C7-D6632A574F4D}")

INTERFACE IIsdbAudioComponentDescriptor $IID_IIsdbAudioComponentDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamContent ( _                          ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentTag ( _                           ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamType ( _                             ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSimulcastGroupTag ( _                      ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetESMultiLingualFlag ( _                     ' VTable offset = 40
     BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMainComponentFlag ( _                      ' VTable offset = 44
     BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQualityIndicator ( _                       ' VTable offset = 48
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSamplingRate ( _                           ' VTable offset = 52
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode ( _                           ' VTable offset = 56
     BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4) char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode2 ( _                          ' VTable offset = 60
     BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4) char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextW ( _                                  ' VTable offset = 64
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbAudioComponentDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbDataContentDescriptor
' IID = A428100A-E646-4BD6-AA14-6087BDC08CD5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbDataContentDescriptor_INTERFACE_DEFINED)
    %IIsdbDataContentDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbDataContentDescriptor = GUID$("{A428100A-E646-4BD6-AA14-6087BDC08CD5}")

INTERFACE IIsdbDataContentDescriptor $IID_IIsdbDataContentDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataComponentId ( _                        ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEntryComponent ( _                         ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectorLength ( _                         ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectorBytes ( _                          ' VTable offset = 32
     BYVAL bBufLength AS BYTE _                         ' _in BYTE bBufLength
   , BYREF pbBuf AS BYTE _                              ' __out BYTE *pbBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordComponentRef ( _                     ' VTable offset = 40
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode ( _                           ' VTable offset = 44
     BYREF pszCode AS ASCIIZ _                          ' __out_ecount(4) char *pszCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextW ( _                                  ' VTable offset = 48
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbDataContentDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbCAContractInformationDescriptor
' IID = 08E18B25-A28F-4E92-821E-4FCED5CC2291
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbCAContractInformationDescriptor_INTERFACE_DEFINED)
    %IIsdbCAContractInformationDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbCAContractInformationDescriptor = GUID$("{08E18B25-A28F-4E92-821E-4FCED5CC2291}")

INTERFACE IIsdbCAContractInformationDescriptor $IID_IIsdbCAContractInformationDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCASystemId ( _                             ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCAUnitId ( _                               ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordComponentTag ( _                     ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContractVerificationInfoLength ( _         ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContractVerificationInfo ( _               ' VTable offset = 40
     BYVAL bBufLength AS BYTE _                         ' __in BYTE bBufLength
   , BYVAL pbBuf AS BYTE PTR _                          ' __out BYTE *pbBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeeNameW ( _                               ' VTable offset = 44
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbCAContractInformationDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbEventGroupDescriptor
' IID = 94B06780-2E2A-44DC-A966-CC56FDABC6C2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbEventGroupDescriptor_INTERFACE_DEFINED)
    %IIsdbEventGroupDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbEventGroupDescriptor = GUID$("{94B06780-2E2A-44DC-A966-CC56FDABC6C2}")

INTERFACE IIsdbEventGroupDescriptor $IID_IIsdbEventGroupDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupType ( _                              ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEvent ( _                            ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwServiceId AS WORD _                        ' __out WORD *pwServiceId
   , BYREF pwEventId AS WORD _                          ' __out WORD *pwEventId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRefRecords ( _                      ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRefRecordEvent ( _                         ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwOriginalNetworkId AS WORD _                ' __out WORD *pwOriginalNetworkId
   , BYREF pwTransportStreamId AS WORD _                ' __out WORD *pwTransportStreamId
   , BYREF pwServiceId AS WORD _                        ' __out WORD *pwServiceId
   , BYREF pwEventId AS WORD _                          ' __out WORD *pwEventId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbEventGroupDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbComponentGroupDescriptor
' IID = A494F17F-C592-47D8-8943-64C9A34BE7B9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbComponentGroupDescriptor_INTERFACE_DEFINED)
    %IIsdbComponentGroupDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbComponentGroupDescriptor = GUID$("{A494F17F-C592-47D8-8943-64C9A34BE7B9}")

INTERFACE IIsdbComponentGroupDescriptor $IID_IIsdbComponentGroupDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentGroupType ( _                     ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordGroupId ( _                          ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordNumberOfCAUnit ( _                   ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCAUnitCAUnitId ( _                   ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL bCAUnitIndex AS BYTE _                       ' __in BYTE bCAUnitIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCAUnitNumberOfComponents ( _         ' VTable offset = 40
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL bCAUnitIndex AS BYTE _                       ' __in BYTE bCAUnitIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCAUnitComponentTag ( _               ' VTable offset = 44
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL bCAUnitIndex AS BYTE _                       ' __in BYTE bCAUnitIndex
   , BYVAL bComponentIndex AS BYTE _                    ' __in BYTE bComponentIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTotalBitRate ( _                     ' VTable offset = 48
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTextW ( _                            ' VTable offset = 52
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbComponentGroupDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbSeriesDescriptor
' IID = 07EF6370-1660-4F26-87FC-614ADAB24B11
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbSeriesDescriptor_INTERFACE_DEFINED)
    %IIsdbSeriesDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbSeriesDescriptor = GUID$("{07EF6370-1660-4F26-87FC-614ADAB24B11}")

INTERFACE IIsdbSeriesDescriptor $IID_IIsdbSeriesDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSeriesId ( _                               ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRepeatLabel ( _                            ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgramPattern ( _                         ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExpireDate ( _                             ' VTable offset = 32
     BYREF pfValid AS LONG _                            ' __out BOOL *pfValid
   , BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEpisodeNumber ( _                          ' VTable offset = 36
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastEpisodeNumber ( _                      ' VTable offset = 40
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSeriesNameW ( _                            ' VTable offset = 44
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       '__out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbSeriesDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbDownloadContentDescriptor
' IID = 5298661E-CB88-4F5F-A1DE-5F440C185B92
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbDownloadContentDescriptor_INTERFACE_DEFINED)
    %IIsdbDownloadContentDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbDownloadContentDescriptor = GUID$("{5298661E-CB88-4F5F-A1DE-5F440C185B92}")

INTERFACE IIsdbDownloadContentDescriptor $IID_IIsdbDownloadContentDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 20
     BYREF pfReboot AS LONG _                           ' __out BOOL *pfReboot
   , BYREF pfAddOn AS LONG _                            ' __out BOOL *pfAddOn
   , BYREF pfCompatibility AS LONG _                    ' __out BOOL *pfCompatibility
   , BYREF pfModuleInfo AS LONG _                       ' __out BOOL *pfModuleInfo
   , BYREF pfTextInfo AS LONG _                         ' __out BOOL *pfTextInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentSize ( _                          ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDownloadId ( _                             ' VTable offset = 28
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeOutValueDII ( _                        ' VTable offset = 32
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLeakRate ( _                               ' VTable offset = 36
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentTag ( _                           ' VTable offset = 40
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompatiblityDescriptorLength ( _           ' VTable offset = 44
     BYREF pwLength AS WORD _                           ' __out WORD *pwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompatiblityDescriptor ( _                 ' VTable offset = 48
     BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 52
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordModuleId ( _                         ' VTable offset = 56
     BYVAL wRecordIndex AS WORD _                       ' __in WORD wRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordModuleSize ( _                       ' VTable offset = 60
     BYVAL wRecordIndex AS WORD _                       ' __in WORD wRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordModuleInfoLength ( _                 ' VTable offset = 64
     BYVAL wRecordIndex AS WORD _                       ' __in WORD wRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordModuleInfo ( _                       ' VTable offset = 68
     BYVAL wRecordIndex AS WORD _                       ' __in WORD wRecordIndex
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextLanguageCode ( _                       ' VTable offset = 72
     BYREF szCode AS ASCIIZ _                           ' __out_ecount(4) char *szCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextW ( _                                  ' VTable offset = 76
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbDownloadContentDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbLogoTransmissionDescriptor
' IID = E0103F49-4AE1-4F07-9098-756DB1FA88CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbLogoTransmissionDescriptor_INTERFACE_DEFINED)
    %IIsdbLogoTransmissionDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbLogoTransmissionDescriptor = GUID$("{E0103F49-4AE1-4F07-9098-756DB1FA88CD}")

INTERFACE IIsdbLogoTransmissionDescriptor $IID_IIsdbLogoTransmissionDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogoTransmissionType ( _                   ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogoId ( _                                 ' VTable offset = 24
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogoVersion ( _                            ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDownloadDataId ( _                         ' VTable offset = 32
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogoCharW ( _                              ' VTable offset = 36
     BYVAL convMode AS LONG _                           ' __in DVB_STRCONV_MODE convMode
   , BYREF pbstrChar AS WSTRING _                       ' __out BSTR *pbstrChar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbLogoTransmissionDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbSIParameterDescriptor
' IID = F837DC36-867C-426a-9111-F62093951A45
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbSIParameterDescriptor_INTERFACE_DEFINED)
    %IIsdbSIParameterDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbSIParameterDescriptor = GUID$("{F837DC36-867C-426a-9111-F62093951A45}")

INTERFACE IIsdbSIParameterDescriptor $IID_IIsdbSIParameterDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterVersion ( _                       ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUpdateTime ( _                             ' VTable offset = 24
     BYREF pbVal AS MPEG_DATE _                         ' __out MPEG_DATE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordNumberOfTable ( _                    ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableId ( _                                ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptionLength ( _                 ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptionBytes ( _                  ' VTable offset = 40
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbBufferLength AS BYTE _                     ' __inout BYTE *pbBufferLength
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbSIParameterDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbEmergencyInformationDescriptor
' IID = BA6FA681-B973-4da1-9207-AC3E7F0341EB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbEmergencyInformationDescriptor_INTERFACE_DEFINED)
    %IIsdbEmergencyInformationDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbEmergencyInformationDescriptor = GUID$("{BA6FA681-B973-4da1-9207-AC3E7F0341EB}")

INTERFACE IIsdbEmergencyInformationDescriptor $IID_IIsdbEmergencyInformationDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceId ( _                              ' VTable offset = 24
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartEndFlag ( _                           ' VTable offset = 28
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pVal AS BYTE _                               ' __out BYTE *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignalLevel ( _                            ' VTable offset = 32
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAreaCode ( _                               ' VTable offset = 36
     BYVAL bRecordIndex AS BYTE _                       ' __in BYTE bRecordIndex
   , BYREF ppwVal AS WORD _                             ' __out WORD **ppwVal
   , BYREF pbNumAreaCodes AS BYTE _                     ' __out BYTE *pbNumAreaCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbEmergencyInformationDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbCADescriptor
' IID = 0570AA47-52BC-42ae-8CA5-969F41E81AEA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbCADescriptor_INTERFACE_DEFINED)
    %IIsdbCADescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbCADescriptor = GUID$("{0570AA47-52BC-42ae-8CA5-969F41E81AEA}")

INTERFACE IIsdbCADescriptor $IID_IIsdbCADescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCASystemId ( _                             ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReservedBits ( _                           ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCAPID ( _                                  ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateDataBytes ( _                       ' VTable offset = 32
     BYREF pbBufferLength AS BYTE _                     ' __inout BYTE *pbBufferLength
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbCADescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbCAServiceDescriptor
' IID = 39CBEB97-FF0B-42a7-9AB9-7B9CFE70A77A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbCAServiceDescriptor_INTERFACE_DEFINED)
    %IIsdbCAServiceDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbCAServiceDescriptor = GUID$("{39CBEB97-FF0B-42a7-9AB9-7B9CFE70A77A}")

INTERFACE IIsdbCAServiceDescriptor $IID_IIsdbCAServiceDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCASystemId ( _                             ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCABroadcasterGroupId ( _                   ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageControl ( _                         ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceIds ( _                             ' VTable offset = 32
     BYREF pbNumServiceIds AS BYTE _                    ' __inout BYTE *pbNumServiceIds
   , BYREF pwServiceIds AS WORD _                       ' __out WORD *pwServiceIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbCAServiceDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsdbHierarchicalTransmissionDescriptor
' IID = B7B3AE90-EE0B-446d-8769-F7E2AA266AA6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIsdbHierarchicalTransmissionDescriptor_INTERFACE_DEFINED)
    %IIsdbHierarchicalTransmissionDescriptor_INTERFACE_DEFINED = 1

$IID_IIsdbHierarchicalTransmissionDescriptor = GUID$("{B7B3AE90-EE0B-446d-8769-F7E2AA266AA6}")

INTERFACE IIsdbHierarchicalTransmissionDescriptor $IID_IIsdbHierarchicalTransmissionDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFutureUse1 ( _                             ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQualityLevel ( _                           ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFutureUse2 ( _                             ' VTable offset = 28
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferencePid ( _                           ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsdbHierarchicalTransmissionDescriptor_INTERFACE_DEFINED__ */


%COMPONENT_TAG_CAPTION_MIN     = &H30?
%COMPONENT_TAG_CAPTION_MAX     = &H37?
%COMPONENT_TAG_SUPERIMPOSE_MIN = &H38?
%COMPONENT_TAG_SUPERIMPOSE_MAX = &H3F?


' ########################################################################################
' Interface name = IPBDASiParser
' IID = 9DE49A74-ABA2-4a18-93E1-21F17F95C3C3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPBDASiParser_INTERFACE_DEFINED)
    %IPBDASiParser_INTERFACE_DEFINED = 1

$IID_IPBDASiParser = GUID$("{9DE49A74-ABA2-4a18-93E1-21F17F95C3C3}")

INTERFACE IPBDASiParser $IID_IPBDASiParser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEIT ( _                                    ' VTable offset = 16
     BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   , BYREF ppEIT AS IPBDA_EIT _                         ' __out IPBDA_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServices ( _                               ' VTable offset = 16
     BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   , BYREF ppServices AS IPBDA_Services _               ' __out IPBDA_Services **ppServices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPBDASiParser_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPBDA_EIT
' IID = A35F2DEA-098F-4ebd-984C-2BD4C3C8CE0A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPBDA_EIT_INTERFACE_DEFINED)
    %IPBDA_EIT_INTERFACE_DEFINED = 1

$IID_IPBDA_EIT = GUID$("{A35F2DEA-098F-4ebd-984C-2BD4C3C8CE0A}")

INTERFACE IPBDA_EIT $IID_IPBDA_EIT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL size AS DWORD _                              ' __in DWORD size
   , BYVAL pBuffer AS BYTE PTR _                        ' __in const BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableId ( _                                ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceIdx ( _                             ' VTable offset = 24
     BYREF plwVal AS QUAD _                             ' __out ULONG64 *plwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 28
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEventId ( _                          ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF plwVal AS QUAD _                             ' __out ULONG64 *plwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordStartTime ( _                        ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDuration ( _                         ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdVal AS MPEG_DURATION _                    ' __out MPEG_DURATION *pmdVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPBDA_EIT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPBDA_Services
' IID = 944EAB37-EED4-4850-AFD2-77E7EFEB4427
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPBDA_Services_INTERFACE_DEFINED)
    %IPBDA_Services_INTERFACE_DEFINED = 1

$IID_IPBDA_Services = GUID$("{944EAB37-EED4-4850-AFD2-77E7EFEB4427}")

INTERFACE IPBDA_Services $IID_IPBDA_Services

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL size AS DWORD _                              ' __in DWORD size
   , BYVAL pBuffer AS BYTE PTR _                        ' __in const BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 16
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordByIndex ( _                          ' VTable offset = 20
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pul64ServiceIdx AS QUAD _                    ' __out ULONG64 *pul64ServiceIdx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPBDA_Services_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPBDAEntitlementDescriptor
' IID = 22632497-0DE3-4587-AADC-D8D99017E760
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPBDAEntitlementDescriptor_INTERFACE_DEFINED)
    %IPBDAEntitlementDescriptor_INTERFACE_DEFINED = 1

$IID_IPBDAEntitlementDescriptor = GUID$("{22632497-0DE3-4587-AADC-D8D99017E760}")

INTERFACE IPBDAEntitlementDescriptor $IID_IPBDAEntitlementDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 20
     BYREF ppbTokenBuffer AS DWORD _                    ' __out BYTE **ppbTokenBuffer
   , BYREF pdwTokenLength AS DWORD _                    ' __out DWORD *pdwTokenLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPBDAEntitlementDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPBDAAttributesDescriptor
' IID = 313B3620-3263-45a6-9533-968BEFBEAC03
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPBDAAttributesDescriptor_INTERFACE_DEFINED)
    %IPBDAAttributesDescriptor_INTERFACE_DEFINED = 1

$IID_IPBDAAttributesDescriptor = GUID$("{313B3620-3263-45a6-9533-968BEFBEAC03}")

INTERFACE IPBDAAttributesDescriptor $IID_IPBDAAttributesDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 20
     BYREF ppbAttributeBuffer AS DWORD _                ' __out BYTE **ppbAttributeBuffer
   , BYREF pdwAttributeLength AS DWORD _                ' __out DWORD *pdwAttributeLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPBDAAttributesDescriptor_INTERFACE_DEFINED__ */
