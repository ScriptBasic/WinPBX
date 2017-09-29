' ########################################################################################
' Microsoft Windows
' File: mpeg2psiparser.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPEG2PSIPARSER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mpeg2structs.inc"
#INCLUDE ONCE "mpeg2data.inc"

' ########################################################################################
' Interface name = IGenericDescriptor
' IID = 6A5918F8-A77A-4F61-AED0-5702BDCDA3E6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGenericDescriptor_INTERFACE_DEFINED)
    %IGenericDescriptor_INTERFACE_DEFINED = 1

$IID_IGenericDescriptor = GUID$("{6A5918F8-A77A-4F61-AED0-5702BDCDA3E6}")

INTERFACE IGenericDescriptor $IID_IGenericDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pbDesc AS BYTE PTR _                         ' __in *pbDesc
   , BYVAL bCount AS BYTE _                             ' __in BYTE bCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 24
     BYREF ppbVal AS DWORD _                            ' __out BYTE **ppbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGenericDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGenericDescriptor2
' IID = BF02FB7E-9792-4E10-A68D-033A2CC246A5
' Inherited interface = IGenericDescriptor
' ########################################################################################

#IF NOT %DEF(%IGenericDescriptor2_INTERFACE_DEFINED)
    %IGenericDescriptor2_INTERFACE_DEFINED = 1

$IID_IGenericDescriptor2 = GUID$("{BF02FB7E-9792-4E10-A68D-033A2CC246A5}")

INTERFACE IGenericDescriptor2 $IID_IGenericDescriptor2

   INHERIT IUnknown

   ' =====================================================================================
   ' IGenericDescriptor Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pbDesc AS BYTE PTR _                         ' __in *pbDesc
   , BYVAL bCount AS BYTE _                             ' __in BYTE bCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 16
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 24
     BYREF ppbVal AS DWORD _                            ' __out BYTE **ppbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IGenericDescriptor2 Methods
   ' Names changed from Initialize to Initialize2 and from GetLength to GetLength2 because
   ' they conflict with the Initialize and GetLength methods of the inherited
   ' IGenericDescriptor interface.
   ' =====================================================================================
   METHOD Initialize2 ( _                               ' VTable offset = 28
     BYVAL pbDesc AS BYTE PTR _                         ' __in BYTE *pbDesc
   , BYVAL wCount AS WORD _                             ' __in WORD wCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength2 ( _                                ' VTable offset = 32
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGenericDescriptor2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPAT
' IID = 6623B511-4B5F-43C3-9A01-E8FF84188060
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPAT_INTERFACE_DEFINED)
    %IPAT_INTERFACE_DEFINED = 1

' // Size = 4 bytes
TYPE ProgramElement WORD
   wProgramNumber AS WORD
   wProgramMapPID AS WORD
END TYPE

$IID_IPAT = GUID$("{6623B511-4B5F-43C3-9A01-E8FF84188060}")

INTERFACE IPAT $IID_IPAT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportStreamId ( _                      ' VTable offset = 16
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 24
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordProgramNumber ( _                    ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordProgramMapPid ( _                    ' VTable offset = 32
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindRecordProgramMapPid ( _                   ' VTable offset = 36
     BYVAL wProgramNumber AS WORD _                     ' __in WORD wProgramNumber
   , BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 40
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 44
     BYREF ppPAT AS IPAT _                              ' __out IPAT **ppPAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 48
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPAT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICAT
' IID = 7C6995FB-2A31-4BD7-953E-B1AD7FB7D31C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICAT_INTERFACE_DEFINED)
    %ICAT_INTERFACE_DEFINED = 1

$IID_ICAT = GUID$("{7C6995FB-2A31-4BD7-953E-B1AD7FB7D31C}")

INTERFACE ICAT $IID_ICAT

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
   , BYREF pdwCookie AS DWORD _                         ' __out_in DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 32
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 36
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF ppCAT AS ICAT _                              ' __out ICAT **ppCAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 40
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICAT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPMT
' IID = 01F3B398-9527-4736-94DB-5195878E97A8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPMT_INTERFACE_DEFINED)
    %IPMT_INTERFACE_DEFINED = 1

$IID_IPMT = GUID$("{01F3B398-9527-4736-94DB-5195878E97A8}")

INTERFACE IPMT $IID_IPMT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSectionList AS ISectionList _               ' __in ISectionList *pSectionList
   , BYVAL pMPEGData AS IMpeg2Data _                    ' __in IMpeg2Data *pMPEGData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgramNumber ( _                          ' VTable offset = 16
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 20
     BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPcrPid ( _                                 ' VTable offset = 24
     BYREF pPidVal AS WORD _                            ' __out PID *pPidVal
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
   , BYREF pdwCookie AS DWORD _                         ' __out_in DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfRecords ( _                         ' VTable offset = 40
     BYREF pwVal AS WORD _                              ' __out WORD *pwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordStreamType ( _                       ' VTable offset = 44
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pbVal AS BYTE _                              ' __out BYTE *pbVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordElementaryPid ( _                    ' VTable offset = 48
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pPidVal AS WORD _                            ' __out PID *pPidVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCountOfDescriptors ( _               ' VTable offset = 52
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByIndex ( _                ' VTable offset = 56
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL dwDescIndex AS DWORD _                       ' __in DWORD dwDescIndex
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordDescriptorByTag ( _                  ' VTable offset = 60
     BYVAL dwRecordIndex AS DWORD _                     ' __in DWORD dwRecordIndex
   , BYVAL bTag AS BYTE _                               ' __in BYTE bTag
   , BYREF pdwCookie AS DWORD _                         ' __out_in DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryServiceGatewayInfo ( _                   ' VTable offset = 64
     BYREF ppDSMCCList AS DSMCC_ELEMENT _               ' __out DSMCC_ELEMENT **ppDSMCCList
   , BYREF puiCount AS DWORD _                          ' __out UINT *puiCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryMPEInfo ( _                              ' VTable offset = 68
     BYREF ppMPEList AS MPE_ELEMENT _                   ' __out MPE_ELEMENT **ppMPEList
   , BYREF puiCount AS DWORD _                          ' __out UINT *puiCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 72
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 76
     BYREF ppPMT AS IPMT _                              ' __out IPMT **ppPMT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 80
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPMT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITSDT
' IID = D19BDB43-405B-4A7C-A791-C89110C33165
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITSDT_INTERFACE_DEFINED)
    %ITSDT_INTERFACE_DEFINED = 1

$IID_ITSDT = GUID$("{D19BDB43-405B-4A7C-A791-C89110C33165}")

INTERFACE ITSDT $IID_ITSDT

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
   , BYREF pdwCookie AS DWORD _                         ' __out_in DWORD *pdwCookie
   , BYREF ppDescriptor AS IGenericDescriptor _         ' __out IGenericDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForNextTable ( _                      ' VTable offset = 32
     BYVAL hNextTableAvailable AS DWORD _               ' __in HANDLE hNextTableAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTable ( _                              ' VTable offset = 36
     BYREF ppTSDT AS ITSDT _                            ' __out IPMT **ppTSDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForWhenCurrent ( _                    ' VTable offset = 40
     BYVAL hNextTableIsCurrent AS DWORD _               ' __in HANDLE hNextTableIsCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertNextToCurrent ( _                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITSDT_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPSITables
' IID = 919F24C5-7B14-42AC-A4B0-2AE08DAF00AC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPSITables_INTERFACE_DEFINED)
    %IPSITables_INTERFACE_DEFINED = 1

$IID_IPSITables = GUID$("{919F24C5-7B14-42AC-A4B0-2AE08DAF00AC}")

INTERFACE IPSITables $IID_IPSITables

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTable ( _                                  ' VTable offset = 12
     BYVAL dwTSID AS DWORD _                            ' __in DWORD dwTSID
   , BYVAL dwTID_PID AS DWORD _                         ' __in DWORD dwTID_PID
   , BYVAL dwHashedVer AS DWORD _                       ' __in DWORD dwHashedVer
   , BYVAL dwPara4 AS DWORD _                           ' __in DWORD dwPara4
   , BYREF ppIUnknown AS IUnknown _                     ' __out IUnknown **ppIUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPSITables_INTERFACE_DEFINED__ */
