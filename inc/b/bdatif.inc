' ########################################################################################
' Microsoft Windows
' File: bdatif.inc
' Library name: PSISLOADLib
' Version: 1.0, Locale ID = 0
' Library GUID: {8224A083-7F8C-432D-B83E-3C5E9BDE3528}
' Contents: psisload 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BDATIF_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "tuner.inc"
#INCLUDE ONCE "dvbsiparser.inc"

$LIBID_PSISLOADLib = GUID$("{8224A083-7F8C-432D-B83E-3C5E9BDE3528}")
$CLSID_TIFLoad = GUID$("{14EB8748-1753-4393-95AE-4F7E7A87AAD6}")

' ########################################################################################
' Interface name = IBDA_TIF_REGISTRATION
' IID = DFEF4A68-EE61-415F-9CCB-CD95F2F98A3A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDA_TIF_REGISTRATION_INTERFACE_DEFINED)
    %IBDA_TIF_REGISTRATION_INTERFACE_DEFINED = 1

$IID_IBDA_TIF_REGISTRATION = GUID$("{DFEF4A68-EE61-415F-9CCB-CD95F2F98A3A}")

INTERFACE IBDA_TIF_REGISTRATION $IID_IBDA_TIF_REGISTRATION

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterTIFEx ( _                             ' VTable offset = 12
     BYVAL pTIFInputPin AS IPin _                       ' __in IPin *pTIFInputPin
   , BYREF ppvRegistrationContext AS DWORD _            ' __out_in ULONG *ppvRegistrationContext
   , BYREF ppMpeg2DataControl AS IUnknown _             ' __out_in IUnknown **ppMpeg2DataControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterTIF ( _                             ' VTable offset = 16
     BYVAL pvRegistrationContext AS DWORD _             ' __in ULONG pvRegistrationContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDA_TIF_REGISTRATION_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMPEG2_TIF_CONTROL
' IID = F9BAC2F9-4149-4916-B2EF-FAA202326862
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMPEG2_TIF_CONTROL_INTERFACE_DEFINED)
    %IMPEG2_TIF_CONTROL_INTERFACE_DEFINED = 1

$IID_IMPEG2_TIF_CONTROL = GUID$("{F9BAC2F9-4149-4916-B2EF-FAA202326862}")

INTERFACE IMPEG2_TIF_CONTROL $IID_IMPEG2_TIF_CONTROL

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterTIF ( _                               ' VTable offset = 12
     BYVAL pUnkTIF AS IUnknown _                        ' __in IUnknown *pUnkTIF
   , BYREF ppvRegistrationContext AS DWORD _            ' __out_in ULONG *ppvRegistrationContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterTIF ( _                             ' VTable offset = 16
     BYVAL pvRegistrationContext AS DWORD _             ' __in ULONG pvRegistrationContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPIDs ( _                                   ' VTable offset = 20
     BYVAL ulcPIDs AS DWORD _                           ' __in ULONG ulcPIDs
   , BYREF pulPIDs AS DWORD _                           ' __in ULONG *pulPIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePIDs ( _                                ' VTable offset = 24
     BYVAL ulcPIDs AS DWORD _                           ' __in ULONG ulcPIDs
   , BYREF pulPIDs AS DWORD _                           ' __in ULONG *pulPIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPIDCount ( _                               ' VTable offset = 28
     BYREF pulcPIDs AS DWORD _                          ' __out ULONG *pulcPIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPIDs ( _                                   ' VTable offset = 32
     BYREF pulcPIDs AS DWORD _                          ' __out ULONG *pulcPIDs
   , BYREF pulPIDs AS DWORD _                           ' __out ULONG *pulPIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2_TIF_CONTROL_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITuneRequestInfo
' IID = A3B152DF-7A90-4218-AC54-9830BEE8C0B6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITuneRequestInfo_INTERFACE_DEFINED)
    %ITuneRequestInfo_INTERFACE_DEFINED = 1

$IID_ITuneRequestInfo = GUID$("{A3B152DF-7A90-4218-AC54-9830BEE8C0B6}")

INTERFACE ITuneRequestInfo $IID_ITuneRequestInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLocatorData ( _                            ' VTable offset = 12
     BYVAL Request AS ITuneRequest _                    ' __in ITuneRequest *Request
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentData ( _                          ' VTable offset = 16
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponentList ( _                       ' VTable offset = 20
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextProgram ( _                            ' VTable offset = 24
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviousProgram ( _                        ' VTable offset = 28
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextLocator ( _                            ' VTable offset = 32
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviousLocator ( _                        ' VTable offset = 36
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuneRequestInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITuneRequestInfoEx
' IID = EE957C52-B0D0-4E78-8DD1-B87A08BFD893
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITuneRequestInfoEx_INTERFACE_DEFINED)
    %ITuneRequestInfoEx_INTERFACE_DEFINED = 1

$IID_ITuneRequestInfoEx = GUID$("{EE957C52-B0D0-4E78-8DD1-B87A08BFD893}")

INTERFACE ITuneRequestInfoEx $IID_ITuneRequestInfoEx

   INHERIT IUnknown

   ' =====================================================================================
   ' ITuneRequestInfo methods
   ' =====================================================================================
   METHOD GetLocatorData ( _                            ' VTable offset = 12
     BYVAL Request AS ITuneRequest _                    ' __in ITuneRequest *Request
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentData ( _                          ' VTable offset = 16
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponentList ( _                       ' VTable offset = 20
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextProgram ( _                            ' VTable offset = 24
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviousProgram ( _                        ' VTable offset = 28
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextLocator ( _                            ' VTable offset = 32
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviousLocator ( _                        ' VTable offset = 36
     BYVAL CurrentRequest AS ITuneRequest _             ' __in ITuneRequest *CurrentRequest
   , BYREF TuneRequest AS ITuneRequest _                ' __retval_out ITuneRequest **TuneRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITuneRequestInfoEx methods
   ' =====================================================================================
   METHOD CreateComponentListEx ( _                     ' VTable offset = 40
     OPTIONAL BYVAL CurrentRequest AS ITuneRequest _    ' __in_opt ITuneRequest *CurrentRequest
   , OPTIONAL BYREF ppCurPMT AS IUnknown _              ' __out_opt IUnknown **ppCurPMT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuneRequestInfoEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISIInbandEPGEvent
' IID = 7E47913A-5A89-423D-9A2B-E15168858934
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISIInbandEPGEvent_INTERFACE_DEFINED)
    %ISIInbandEPGEvent_INTERFACE_DEFINED = 1

$IID_ISIInbandEPGEvent = GUID$("{7E47913A-5A89-423D-9A2B-E15168858934}")

INTERFACE ISIInbandEPGEvent $IID_ISIInbandEPGEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SIObjectEvent ( _                             ' VTable offset = 12
     BYVAL pIDVB_EIT AS IDVB_EIT2 _                     ' __in IDVB_EIT2 *pIDVB_EIT
   , BYVAL dwTable_ID AS DWORD _                        ' __in DWORD dwTable_ID
   , BYVAL dwService_ID AS DWORD _                      ' __in DWORD dwService_ID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISIInbandEPGEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISIInbandEPG
' IID = F90AD9D0-B854-4b68-9CC1-B2CC96119D85
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISIInbandEPG_INTERFACE_DEFINED)
    %ISIInbandEPG_INTERFACE_DEFINED = 1

$IID_ISIInbandEPG = GUID$("{F90AD9D0-B854-4b68-9CC1-B2CC96119D85}")

INTERFACE ISIInbandEPG $IID_ISIInbandEPG

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartSIEPGScan ( _                            ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopSIEPGScan ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSIEPGScanRunning ( _                        ' VTable offset = 20
     BYREF bRunning AS LONG _                           ' _retval_out BOOL *bRunning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISIInbandEPG_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGuideDataEvent
' IID = EFDA0C80-F395-42C3-9B3C-56B37DEC7BB7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGuideDataEvent_INTERFACE_DEFINED)
    %IGuideDataEvent_INTERFACE_DEFINED = 1

$IID_IGuideDataEvent = GUID$("{EFDA0C80-F395-42C3-9B3C-56B37DEC7BB7}")

INTERFACE IGuideDataEvent $IID_IGuideDataEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GuideDataAcquired ( _                         ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProgramChanged ( _                            ' VTable offset = 16
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ServiceChanged ( _                            ' VTable offset = 20
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScheduleEntryChanged ( _                      ' VTable offset = 24
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProgramDeleted ( _                            ' VTable offset = 28
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ServiceDeleted ( _                            ' VTable offset = 32
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScheduleDeleted ( _                           ' VTable offset = 36
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGuideDataEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGuideDataProperty
' IID = 88EC5E58-BB73-41D6-99CE-66C524B8B591
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGuideDataProperty_INTERFACE_DEFINED)
    %IGuideDataProperty_INTERFACE_DEFINED = 1

$IID_IGuideDataProperty = GUID$("{88EC5E58-BB73-41D6-99CE-66C524B8B591}")

INTERFACE IGuideDataProperty $IID_IGuideDataProperty

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Name ( _                                  ' VTable offset = 12
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Language ( _                              ' VTable offset = 16
     BYREF idLang AS LONG _                             ' __out long *idLang
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Value ( _                                 ' VTable offset = 20
     BYREF pvar AS VARIANT _                            ' __out VARIANT *pvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGuideDataProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumGuideDataProperties
' IID = AE44423B-4571-475C-AD2C-F40A771D80EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumGuideDataProperties_INTERFACE_DEFINED)
    %IEnumGuideDataProperties_INTERFACE_DEFINED = 1

$IID_IEnumGuideDataProperties = GUID$("{AE44423B-4571-475C-AD2C-F40A771D80EF}")

INTERFACE IEnumGuideDataProperties $IID_IEnumGuideDataProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppprop AS IGuideDataProperty _               ' __out IGuideDataProperty **ppprop
   , BYREF pcelt AS DWORD _                             ' __out unsigned long *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumGuideDataProperties _         ' __out IEnumGuideDataProperties **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumGuideDataProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumTuneRequests
' IID = 1993299C-CED6-4788-87A3-420067DCE0C7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumTuneRequests_INTERFACE_DEFINED)
    %IEnumTuneRequests_INTERFACE_DEFINED = 1

$IID_IEnumTuneRequests = GUID$("{1993299C-CED6-4788-87A3-420067DCE0C7}")

INTERFACE IEnumTuneRequests $IID_IEnumTuneRequests

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppprop AS ITuneRequest _                     ' __out ITuneRequest **ppprop
   , BYREF pcelt AS DWORD _                             ' __out unsigned long *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumTuneRequests _                ' __out IEnumTuneRequests **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumTuneRequests_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGuideData
' IID = 61571138-5B01-43CD-AEAF-60B784A0BF93
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGuideData_INTERFACE_DEFINED)
    %IGuideData_INTERFACE_DEFINED = 1

$IID_IGuideData = GUID$("{61571138-5B01-43CD-AEAF-60B784A0BF93}")

INTERFACE IGuideData $IID_IGuideData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetServices ( _                               ' VTable offset = 12
     BYREF ppEnumTuneRequests AS IEnumTuneRequests _    ' __retval_out IEnumTuneRequests **ppEnumTuneRequests
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceProperties ( _                      ' VTable offset = 16
     BYVAL pTuneRequest AS ITuneRequest _               ' __in ITuneRequest *pTuneRequest
   , BYREF ppEnumProperties AS IEnumGuideDataProperties _ ' __retval_out IEnumGuideDataProperties **ppEnumProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuideProgramIDs ( _                        ' VTable offset = 20
     BYREF pEnumPrograms AS IEnumVARIANT _              ' __retval_out IEnumVARIANT **pEnumPrograms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgramProperties ( _                      ' VTable offset = 24
     BYVAL varProgramDescriptionID AS VARIANT _         ' __in VARIANT varProgramDescriptionID
   , BYREF ppEnumProperties AS IEnumGuideDataProperties _ ' __retval_out IEnumGuideDataProperties **ppEnumProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScheduleEntryIDs ( _                       ' VTable offset = 28
     BYREF pEnumScheduleEntries AS IEnumVARIANT _       ' __retval_out IEnumVARIANT **pEnumScheduleEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScheduleEntryProperties ( _                ' VTable offset = 32
     BYVAL varScheduleEntryDescriptionID AS VARIANT _   ' __in VARIANT varScheduleEntryDescriptionID
   , BYREF ppEnumProperties AS IEnumGuideDataProperties _ ' __retval_out IEnumGuideDataProperties **ppEnumProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGuideData_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGuideDataLoader
' IID = 4764FF7C-FA95-4525-AF4D-D32236DB9E38
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGuideDataLoader_INTERFACE_DEFINED)
    %IGuideDataLoader_INTERFACE_DEFINED = 1

$IID_IGuideDataLoader = GUID$("{4764FF7C-FA95-4525-AF4D-D32236DB9E38}")

INTERFACE IGuideDataLoader $IID_IGuideDataLoader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL pGuideStore AS IGuideData _                  ' __in IGuideData *pGuideStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGuideDataLoader_INTERFACE_DEFINED__ */
