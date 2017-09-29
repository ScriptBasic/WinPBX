' ########################################################################################
' Microsoft Windows
' File: atscpsipparser.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ATSCPSIPPARSER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mpeg2structs.inc"
#INCLUDE ONCE "mpeg2data.inc"
#INCLUDE ONCE "mpeg2psiparser.inc"

%ATSC_ETM_LOCATION_NOT_PRESENT        = &H00
%ATSC_ETM_LOCATION_IN_PTC_FOR_PSIP    = &H01
%ATSC_ETM_LOCATION_IN_PTC_FOR_EVENT   = &H02
%ATSC_ETM_LOCATION_RESERVED           = &H03


' ########################################################################################
' Interface name = IAtscPsipParser
' IID = B2C98995-5EB2-4FB1-B406-F3E8E2026A9A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAtscPsipParser_INTERFACE_DEFINED)
    %IAtscPsipParser_INTERFACE_DEFINED = 1

$IID_IAtscPsipParser = GUID$("{B2C98995-5EB2-4FB1-B406-F3E8E2026A9A}")

INTERFACE IAtscPsipParser $IID_IAtscPsipParser

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
   , BYREF pwProgramNumber AS WORD _                    ' __in WORD *pwProgramNumber
   , BYREF ppPMT AS IPMT _                              ' __out IPMT **ppPMT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTSDT ( _                                   ' VTable offset = 28
     BYREF ppTSDT AS ITSDT _                            ' __out ITSDT **ppTSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMGT ( _                                    ' VTable offset = 32
     BYREF ppMGT AS IATSC_MGT _                         ' __out IATSC_MGT **ppMGT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVCT ( _                                    ' VTable offset = 36
     BYVAL tableId AS BYTE _                            ' __in TID tableId
   , BYVAL fGetNextTable AS LONG _                      ' __in BOOL fGetNextTable
   , BYREF ppVCT AS IATSC_VCT _                         ' __out IATSC_VCT **ppVCT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEIT ( _                                    ' VTable offset = 40
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYREF pwSourceId AS WORD _                         ' __in WORD *pwSourceId
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppEIT AS IATSC_EIT _                         ' __out IATSC_EIT **ppEIT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetETT ( _                                    ' VTable offset = 44
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYREF wSourceId AS WORD _                          ' __in WORD *wSourceId
   , BYREF pwEventId AS WORD _                          ' __in WORD *pwEventId
   , BYREF ppETT AS IATSC_ETT _                         ' __out IATSC_ETT **ppETT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSTT ( _                                    ' VTable offset = 48
     BYREF ppSTT AS IATSC_STT _                         ' __out IATSC_STT **ppSTT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEAS ( _                                    ' VTable offset = 52
     BYVAL pid AS WORD _                                ' __in PID pid
   , BYREF ppEAS AS ISCTE_EAS _                         ' __out ISCTE_EAS **ppEAS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAtscPsipParser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IATSC_MGT
' IID = 8877DABD-C137-4073-97E3-779407A5D87A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IATSC_MGT_INTERFACE_DEFINED)
    %IATSC_MGT_INTERFACE_DEFINED = 1

$IID_IATSC_MGT = GUID$("{8877DABD-C137-4073-97E3-779407A5D87A}")

INTERFACE IATSC_MGT $IID_IATSC_MGT

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
   METHOD GetProtocolVersion ( _                        ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordType ( _                             ' VTable offset = 28
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTypePid ( _                          ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF ppidVal AS WORD _                            ' __out PID *ppidVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordVersionNumber ( _                    ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
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
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 52
     BYREF pdwVal AS DWORD _                            ' __in DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 56
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 60
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSC_MGT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IATSC_VCT
' IID = 26879A18-32F9-46C6-91F0-FB6479270E8C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IATSC_VCT_INTERFACE_DEFINED)
    %IATSC_VCT_INTERFACE_DEFINED = 1

$IID_IATSC_VCT = GUID$("{26879A18-32F9-46C6-91F0-FB6479270E8C}")

INTERFACE IATSC_VCT $IID_IATSC_VCT

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
   METHOD GetProtocolVersion ( _                        ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 28
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordName ( _                             ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwsName AS DWORD _                           ' __out WCHAR **pwsName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordMajorChannelNumber ( _               ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordMinorChannelNumber ( _               ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordModulationMode ( _                   ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCarrierFrequency ( _                 ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTransportStreamId ( _                ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordProgramNumber ( _                    ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEtmLocation ( _                      ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordIsAccessControlledBitSet ( _         ' VTable offset = 64
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordIsHiddenBitSet ( _                   ' VTable offset = 68
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordIsPathSelectBitSet ( _               ' VTable offset = 72
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordIsOutOfBandBitSet ( _                ' VTable offset = 76
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordIsHideGuideBitSet ( _                ' VTable offset = 80
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pfVal AS LONG _                              ' __out BOOL *pfVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordServiceType ( _                      ' VTable offset = 84
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordSourceId ( _                         ' VTable offset = 88
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 92
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 96
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 100
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 104
     BYREF pdwVal AS DWORD _                            ' __in DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 108
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 112
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSC_VCT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IATSC_EIT
' IID = D7C212D7-76A2-4B4B-AA56-846879A80096
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IATSC_EIT_INTERFACE_DEFINED)
    %IATSC_EIT_INTERFACE_DEFINED = 1

$IID_IATSC_EIT = GUID$("{D7C212D7-76A2-4B4B-AA56-846879A80096}")

INTERFACE IATSC_EIT $IID_IATSC_EIT

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
   METHOD GetSourceId ( _                               ' VTable offset = 20
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtocolVersion ( _                        ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 28
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEventId ( _                          ' VTable offset = 32
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordStartTime ( _                        ' VTable offset = 36
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdtVal AS MPEG_DATE_AND_TIME _              ' __out MPEG_DATE_AND_TIME *pmdtVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordEtmLocation ( _                      ' VTable offset = 40
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDuration ( _                         ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pmdVal AS MPEG_DURATION _                    ' __out MPEG_DURATION *pmdVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordTitleText ( _                        ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   , BYREF ppText AS DWORD _                            ' __out BYTE **ppText
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
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 100
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSC_EIT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IATSC_ETT
' IID = 5A142CC9-B8CF-4A86-A040-E9CADF3EF3E7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IATSC_ETT_INTERFACE_DEFINED)
    %IATSC_ETT_INTERFACE_DEFINED = 1

$IID_IATSC_ETT = GUID$("{5A142CC9-B8CF-4A86-A040-E9CADF3EF3E7}")

INTERFACE IATSC_ETT $IID_IATSC_ETT

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
   METHOD GetProtocolVersion ( _                        ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEtmId ( _                                  ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedMessageText ( _                    ' VTable offset = 28
     BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   , BYREF ppText AS DWORD _                            ' __out BYTE **ppText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSC_ETT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IATSC_STT
' IID = 6BF42423-217D-4D6F-81E1-3A7B360EC896
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IATSC_STT_INTERFACE_DEFINED)
    %IATSC_STT_INTERFACE_DEFINED = 1

$IID_IATSC_STT = GUID$("{6BF42423-217D-4D6F-81E1-3A7B360EC896}")

INTERFACE IATSC_STT $IID_IATSC_STT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtocolVersion ( _                        ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSystemTime ( _                             ' VTable offset = 20
     BYREF pmdtSystemTime AS MPEG_DATE_AND_TIME _       ' __out MPEG_DATE_AND_TIME *pmdtSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGpsUtcOffset ( _                           ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDaylightSavings ( _                        ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 32
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 36
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 40
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSC_STT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISCTE_EAS
' IID = 1FF544D6-161D-4FAE-9FAA-4F9F492AE999
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISCTE_EAS_INTERFACE_DEFINED)
    %ISCTE_EAS_INTERFACE_DEFINED = 1

$IID_ISCTE_EAS = GUID$("{1FF544D6-161D-4FAE-9FAA-4F9F492AE999}")

INTERFACE ISCTE_EAS $IID_ISCTE_EAS

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
   METHOD GetSequencyNumber ( _                         ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtocolVersion ( _                        ' VTable offset = 24
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEASEventID ( _                             ' VTable offset = 28
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginatorCode ( _                         ' VTable offset = 32
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEASEventCodeLen ( _                        ' VTable offset = 36
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEASEventCode ( _                           ' VTable offset = 40
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRawNatureOfActivationTextLen ( _           ' VTable offset = 44
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRawNatureOfActivationText ( _              ' VTable offset = 48
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNatureOfActivationText ( _                 ' VTable offset = 52
     BYVAL bstrIS0639code AS WSTRING _                  ' __in BSTR bstrIS0639code
   , BYREF pbstrString AS WSTRING _                     ' __out BSTR *pbstrString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeRemaining ( _                          ' VTable offset = 56
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartTime ( _                              ' VTable offset = 60
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 64
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlertPriority ( _                          ' VTable offset = 68
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDetailsOOBSourceID ( _                     ' VTable offset = 72
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDetailsMajor ( _                           ' VTable offset = 76
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDetailsMinor ( _                           ' VTable offset = 80
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDetailsAudioOOBSourceID ( _                ' VTable offset = 84
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlertText ( _                              ' VTable offset = 88
     BYVAL bstrIS0639code AS WSTRING _                  ' __in BSTR bstrIS0639code
   , BYREF pbstrString AS WSTRING _                     ' __out BSTR *pbstrString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRawAlertTextLen ( _                        ' VTable offset = 92
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRawAlertText ( _                           ' VTable offset = 96
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocationCount ( _                          ' VTable offset = 100
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocationCodes ( _                          ' VTable offset = 104
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbState AS BYTE _                            ' __out BYTE *pbState
   , BYREF pbCountySubdivision AS BYTE _                ' __out BYTE *pbCountySubdivision
   , BYREF pwCounty AS WORD _                           ' __out WORD *pwCounty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExceptionCount ( _                         ' VTable offset = 108
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExceptionService ( _                       ' VTable offset = 112
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbIBRef AS BYTE _                            ' __out BYTE *pbIBRef
   , BYREF pwFirst AS WORD _                            ' __out WORD *pwFirst
   , BYREF pwSecond AS WORD _                           ' __out WORD *pwSecond
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfTableDescriptors ( _                ' VTable offset = 116
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByIndex ( _                 ' VTable offset = 120
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDescriptorByTag ( _                   ' VTable offset = 124
     BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __inout DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCTE_EAS_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAtscContentAdvisoryDescriptor
' IID = FF76E60C-0283-43EA-BA32-B422238547EE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAtscContentAdvisoryDescriptor_INTERFACE_DEFINED)
    %IAtscContentAdvisoryDescriptor_INTERFACE_DEFINED = 1

$IID_IAtscContentAdvisoryDescriptor = GUID$("{FF76E60C-0283-43EA-BA32-B422238547EE}")

INTERFACE IAtscContentAdvisoryDescriptor $IID_IAtscContentAdvisoryDescriptor

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
   METHOD GetRatingRegionCount ( _                      ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRatingRegion ( _                     ' VTable offset = 24
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRatedDimensions ( _                  ' VTable offset = 28
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRatingDimension ( _                  ' VTable offset = 32
     BYVAL bIndexOuter AS BYTE _                        ' __in BYTE bIndexOuter
   , BYVAL bIndexInner AS BYTE _                        ' __in BYTE bIndexInner
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRatingValue ( _                      ' VTable offset = 36
     BYVAL bIndexOuter AS BYTE _                        ' __in BYTE bIndexOuter
   , BYVAL bIndexInner AS BYTE _                        ' __in BYTE bIndexInner
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordRatingDescriptionText ( _            ' VTable offset = 40
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbLength AS BYTE _                           ' __out BYTE *pbLength
   , BYREF ppText AS DWORD _                            ' __out BYTE **ppText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAtscContentAdvisoryDescriptor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICaptionServiceDescriptor
' IID = 40834007-6834-46F0-BD45-D5F6A6BE258C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICaptionServiceDescriptor_INTERFACE_DEFINED)
    %ICaptionServiceDescriptor_INTERFACE_DEFINED = 1

$IID_ICaptionServiceDescriptor = GUID$("{40834007-6834-46F0-BD45-D5F6A6BE258C}")

INTERFACE ICaptionServiceDescriptor $IID_ICaptionServiceDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfServices ( _                       ' VTable offset = 12
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageCode ( _                           ' VTable offset = 16
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF LangCode AS BYTE _                           ' __out BYTE LangCode[ 3 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaptionServiceNumber ( _                   ' VTable offset = 20
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCCType ( _                                 ' VTable offset = 24
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEasyReader ( _                             ' VTable offset = 28
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWideAspectRatio ( _                        ' VTable offset = 32
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICaptionServiceDescriptor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceLocationDescriptor
' IID = 58C3C827-9D91-4215-BFF3-820A49F0904C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceLocationDescriptor_INTERFACE_DEFINED)
    %IServiceLocationDescriptor_INTERFACE_DEFINED = 1

$IID_IServiceLocationDescriptor = GUID$("{58C3C827-9D91-4215-BFF3-820A49F0904C}")

INTERFACE IServiceLocationDescriptor $IID_IServiceLocationDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPCR_PID ( _                                ' VTable offset = 12
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfElements ( _                       ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetElementStreamType ( _                      ' VTable offset = 20
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetElementPID ( _                             ' VTable offset = 24
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetElementLanguageCode ( _                    ' VTable offset = 28
     BYVAL bIndex AS BYTE _                             ' __in BYTE bIndex
   , BYREF LangCode AS BYTE _                           ' __out BYTE LangCode[ 3 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceLocationDescriptor_INTERFACE_DEFINED__ */
