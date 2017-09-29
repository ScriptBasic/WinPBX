' ########################################################################################
' Microsoft Windows
' File: EncDec.inc
' Library name: EncDec
' Version: 1.0, Locale ID = 0
' Library GUID: {C4C4C400-0049-4E2B-98FB-9537F6CE516D}
' Contents: Microsoft Encypter-Tagger/Decrypter-Detagger Filters
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ENCDEC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "TvRatings.inc"

$LIBID_EncDec = GUID$("{C4C4C400-0049-4E2B-98FB-9537F6CE516D}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CXDSData = GUID$("{C4C4C4F4-0049-4E2B-98FB-9537F6CE516D}")
$CLSID_DTFilter = GUID$("{C4C4C4F2-0049-4E2B-98FB-9537F6CE516D}")
$CLSID_ETFilter = GUID$("{C4C4C4F1-0049-4E2B-98FB-9537F6CE516D}")
$CLSID_XDSCodec = GUID$("{C4C4C4F3-0049-4E2B-98FB-9537F6CE516D}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDTFilter = GUID$("{C4C4C4B2-0049-4E2B-98FB-9537F6CE516D}")
$IID_IDTFilter2 = GUID$("{C4C4C4B4-0049-4E2B-98FB-9537F6CE516D}")
$IID_IDTFilter3 = GUID$("{513998CC-E929-4CDF-9FBD-BAD1E0314866}")
$IID_IDTFilterConfig = GUID$("{C4C4C4D2-0049-4E2B-98FB-9537F6CE516D}")
$IID_IDTFilterEvents = GUID$("{C4C4C4C2-0049-4E2B-98FB-9537F6CE516D}")
$IID_IETFilter = GUID$("{C4C4C4B1-0049-4E2B-98FB-9537F6CE516D}")
$IID_IETFilterConfig = GUID$("{C4C4C4D1-0049-4E2B-98FB-9537F6CE516D}")
$IID_IETFilterEvents = GUID$("{C4C4C4C1-0049-4E2B-98FB-9537F6CE516D}")
$IID_IXDSCodec = GUID$("{C4C4C4B3-0049-4E2B-98FB-9537F6CE516D}")
$IID_IXDSCodecConfig = GUID$("{C4C4C4D3-0049-4E2B-98FB-9537F6CE516D}")
$IID_IXDSCodecEvents = GUID$("{C4C4C4C3-0049-4E2B-98FB-9537F6CE516D}")


'// {C4C4C4C4-0049-4E2B-98FB-9537F6CE516D}
$SID_DRMSecureServiceChannel = GUID$("{C4C4C4C4-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C481-0049-4E2B-98FB-9537F6CE516D}
$CLSID_ETFilterEncProperties = GUID$("{C4C4C481-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C491-0049-4E2B-98FB-9537F6CE516D}
$CLSID_ETFilterTagProperties = GUID$("{C4C4C491-0049-4E2B-98FB-9537F6CE516D}")
'// {9CD31617-B303-4f96-8330-2EB173EA4DC6}
$CLSID_PTFilter = GUID$("{9CD31617-B303-4f96-8330-2EB173EA4DC6}")
'// {C4C4C482-0049-4E2B-98FB-9537F6CE516D}
$CLSID_DTFilterEncProperties = GUID$("{C4C4C482-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C492-0049-4E2B-98FB-9537F6CE516D}
$CLSID_DTFilterTagProperties = GUID$("{C4C4C492-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C483-0049-4E2B-98FB-9537F6CE516D}
$CLSID_XDSCodecProperties = GUID$("{C4C4C483-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C493-0049-4E2B-98FB-9537F6CE516D}
$CLSID_XDSCodecTagProperties = GUID$("{C4C4C493-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4FC-0049-4E2B-98FB-9537F6CE516D}
$CLSID_CPCAFiltersCategory = GUID$("{C4C4C4FC-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E0-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_XDSCodecNewXDSRating = GUID$("{C4C4C4E0-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4DF-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_XDSCodecDuplicateXDSRating = GUID$("{C4C4C4DF-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E1-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_XDSCodecNewXDSPacket = GUID$("{C4C4C4E1-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E2-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterRatingChange = GUID$("{C4C4C4E2-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E3-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterRatingsBlock = GUID$("{C4C4C4E3-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E4-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterRatingsUnblock = GUID$("{C4C4C4E5-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E5-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterXDSPacket = GUID$("{C4C4C4E5-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E6-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_ETFilterEncryptionOn = GUID$("{C4C4C4E6-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E7-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_ETFilterEncryptionOff = GUID$("{C4C4C4E7-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E8-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterCOPPUnblock = GUID$("{C4C4C4E8-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4E9-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_EncDecFilterError = GUID$("{C4C4C4E9-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4EA-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterCOPPBlock = GUID$("{C4C4C4EA-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4EB-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_ETFilterCopyOnce = GUID$("{C4C4C4EB-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4F0-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_ETFilterCopyNever = GUID$("{C4C4C4F0-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4EC-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterDataFormatOK = GUID$("{C4C4C4EC-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4ED-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_DTFilterDataFormatFailure = GUID$("{C4C4C4ED-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4EE-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_ETDTFilterLicenseOK = GUID$("{C4C4C4EE-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4EF-0049-4E2B-98FB-9537F6CE516D}
$EVENTID_ETDTFilterLicenseFailure = GUID$("{C4C4C4EF-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4D0-0049-4E2B-98FB-9537F6CE516D}
$MEDIASUBTYPE_ETDTFilter_Tagged = GUID$("{C4C4C4D0-0049-4E2B-98FB-9537F6CE516D}")
'// {C4C4C4D1-0049-4E2B-98FB-9537F6CE516D}
$FORMATTYPE_ETDTFilter_Tagged = GUID$("{C4C4C4D1-0049-4E2B-98FB-9537F6CE516D}")
'// {46adbd28-6fd0-4796-93b2-155c51dc048d}
$MEDIASUBTYPE_CPFilters_Processed = GUID$("{46adbd28-6fd0-4796-93b2-155c51dc048d}")
'// {6739b36f-1d5f-4ac2-8192-28bb0e73d16a}
$FORMATTYPE_CPFilters_Processed = GUID$("{6739b36f-1d5f-4ac2-8192-28bb0e73d16a}")
'// {4A1B465B-0FB9-4159-AFBD-E33006A0F9F4}
$EVENTID_EncDecFilterEvent = GUID$("{4A1B465B-0FB9-4159-AFBD-E33006A0F9F4}")

' enum FormatNotSupportedEvents
%FORMATNOTSUPPORTED_CLEAR        = 0
%FORMATNOTSUPPORTED_NOTSUPPORTED = 1

'// {24B2280A-B2AA-4777-BF65-63F35E7B024A}
$EVENTID_FormatNotSupportedEvent = GUID$("{24B2280A-B2AA-4777-BF65-63F35E7B024A}")
'// {16155770-AED5-475c-BB98-95A33070DF0C}
$EVENTID_DemultiplexerFilterDiscontinuity = GUID$("{16155770-AED5-475c-BB98-95A33070DF0C}")
'// {40749583-6b9d-4eec-b43c-67a1801e1a9b}
$DSATTRIB_WMDRMProtectionInfo = GUID$("{40749583-6b9d-4eec-b43c-67a1801e1a9b}")
'// {e4846dda-5838-42b4-b897-6f7e5faa2f2f}
$DSATTRIB_BadSampleInfo = GUID$("{e4846dda-5838-42b4-b897-6f7e5faa2f2f}")

'#pragma pack(push, 1)
' // Size = 67 bytes
TYPE WMDRMProtectionInfo BYTE
   wszKID(24) AS WORD   ' unsigned short wszKID[25]
   qwCounter  AS QUAD   ' unsigned __int64 qwCounter
   qwIndex    AS QUAD   ' unsigned __int64 qwIndex
   bOffset    AS BYTE   ' unsigned char bOffset
END TYPE

TYPE BadSampleInfo DWORD
   hrReason AS LONG   ' HRESULT
END TYPE

'#pragma pack(pop)

'typedef LONGLONG REFERENCE_TIME;

'typedef LONG PackedTvRating;

'DECLSPEC_UUID("25AEE876-3D61-4486-917E-7C0CB3D9983C")
'enum ProtType
%PROT_COPY_FREE              = 1
%PROT_COPY_ONCE              = 2
%PROT_COPY_NEVER             = 3
%PROT_COPY_NEVER_REALLY      = 4
%PROT_COPY_NO_MORE           = 5
%PROT_COPY_FREE_CIT          = 6
%PROT_COPY_BF                = 7
%PROT_COPY_CN_RECORDING_STOP = 8
%PROT_COPY_FREE_SECURE       = 9
%PROT_COPY_INVALID           = 50

'enum EncDecEvents
%ENCDEC_CPEVENT          = 0
%ENCDEC_RECORDING_STATUS = %ENCDEC_CPEVENT + 1

'enum CPRecordingStatus
%RECORDING_STOPPED = 0
%RECORDING_STARTED = 1

'enum CPEventBitShift
%CPEVENT_BITSHIFT_RATINGS             = 0
%CPEVENT_BITSHIFT_COPP                = %CPEVENT_BITSHIFT_RATINGS             + 1
%CPEVENT_BITSHIFT_LICENSE             = %CPEVENT_BITSHIFT_COPP                + 1
%CPEVENT_BITSHIFT_ROLLBACK            = %CPEVENT_BITSHIFT_LICENSE             + 1
%CPEVENT_BITSHIFT_SAC                 = %CPEVENT_BITSHIFT_ROLLBACK            + 1
%CPEVENT_BITSHIFT_DOWNRES             = %CPEVENT_BITSHIFT_SAC                 + 1
%CPEVENT_BITSHIFT_STUBLIB             = %CPEVENT_BITSHIFT_DOWNRES             + 1
%CPEVENT_BITSHIFT_UNTRUSTEDGRAPH      = %CPEVENT_BITSHIFT_STUBLIB             + 1
%CPEVENT_BITSHIFT_PENDING_CERTIFICATE = %CPEVENT_BITSHIFT_UNTRUSTEDGRAPH      + 1
%CPEVENT_BITSHIFT_NO_PLAYREADY        = %CPEVENT_BITSHIFT_PENDING_CERTIFICATE + 1

'enum CPEvents
%CPEVENT_NONE            = 0
%CPEVENT_RATINGS         = %CPEVENT_NONE           + 1
%CPEVENT_COPP            = %CPEVENT_RATINGS        + 1
%CPEVENT_LICENSE         = %CPEVENT_COPP           + 1
%CPEVENT_ROLLBACK        = %CPEVENT_LICENSE        + 1
%CPEVENT_SAC             = %CPEVENT_ROLLBACK       + 1
%CPEVENT_DOWNRES         = %CPEVENT_SAC            + 1
%CPEVENT_STUBLIB         = %CPEVENT_DOWNRES        + 1
%CPEVENT_UNTRUSTEDGRAPH  = %CPEVENT_STUBLIB        + 1
%CPEVENT_PROTECTWINDOWED = %CPEVENT_UNTRUSTEDGRAPH + 1

'enum RevokedComponent
%REVOKED_COPP            = 0
%REVOKED_SAC             = %REVOKED_COPP            + 1
%REVOKED_APP_STUB        = %REVOKED_SAC             + 1
%REVOKED_SECURE_PIPELINE = %REVOKED_APP_STUB        + 1
%REVOKED_MAX_TYPES       = %REVOKED_SECURE_PIPELINE + 1

'enum EnTag_Mode
%EnTag_Remove = 0
%EnTag_Once   = &H1
%EnTag_Repeat = &H2

'DECLSPEC_UUID("6F8C2442-2BFB-4180-9EE5-EA1FB47AE35C")
'enum COPPEventBlockReason
%COPP_Unknown                 = -1
%COPP_BadDriver               = 0
%COPP_NoCardHDCPSupport       = 1
%COPP_NoMonitorHDCPSupport    = 2
%COPP_BadCertificate          = 3
%COPP_InvalidBusProtection    = 4
%COPP_AeroGlassOff            = 5
%COPP_RogueApp                = 6
%COPP_ForbiddenVideo          = 7
%COPP_Activate                = 8
%COPP_DigitalAudioUnprotected = 9

'DECLSPEC_UUID("57BCA1BE-DF7A-434e-8B89-26D6A0541FDA")
'enum LicenseEventBlockReason
%LIC_BadLicense      = 0
%LIC_NeedIndiv       = 1
%LIC_Expired         = 2
%LIC_NeedActivation  = 3
%LIC_ExtenderBlocked = 4

'DECLSPEC_UUID("D5CC1CDC-EF31-48dc-95B8-AFD34C08036B")
'enum DownResEventParam
%DOWNRES_Always       = 0
%DOWNRES_InWindowOnly = 1
%DOWNRES_Undefined    = 2

' ########################################################################################
' Interface name = IETFilterConfig
' IID = {C4C4C4D1-0049-4E2B-98FB-9537F6CE516D}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IETFilterConfig_INTERFACE_DEFINED)
    %IETFilterConfig_INTERFACE_DEFINED = 1

INTERFACE IETFilterConfig $IID_IETFilterConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitLicense ( _                               ' VTable offset = 12
     BYVAL LicenseId AS LONG _                          ' __in int LicenseId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecureChannelObject ( _                    ' VTable offset = 16
     BYREF ppUnkDRMSecureChannel AS IUnknown _          ' __out IUnknown **ppUnkDRMSecureChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IETFilterConfig_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTFilterConfig
' IID = {C4C4C4D2-0049-4E2B-98FB-9537F6CE516D}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTFilterConfig_INTERFACE_DEFINED)
    %IDTFilterConfig_INTERFACE_DEFINED = 1

INTERFACE IDTFilterConfig $IID_IDTFilterConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSecureChannelObject ( _                    ' VTable offset = 12
     BYREF ppUnkDRMSecureChannel AS IUnknown _          ' __out Iunknown **ppUnkDRMSecureChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTFilterConfig_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXDSCodecConfig
' IID = {C4C4C4D3-0049-4E2B-98FB-9537F6CE516D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXDSCodecConfig_INTERFACE_DEFINED)
    %IXDSCodecConfig_INTERFACE_DEFINED = 1

INTERFACE IXDSCodecConfig $IID_IXDSCodecConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSecureChannelObject ( _                    ' VTable offset = 12
     BYREF ppUnkDRMSecureChannel AS IUnknown _          ' __out IUnknown **ppUnkDRMSecureChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPauseBufferTime ( _                        ' VTable offset = 16
     BYVAL dwPauseBufferTime AS DWORD _                 ' __in DWORD dwPauseBufferTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXDSCodecConfig_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTFilterLicenseRenewal
' IID = 8A78B317-E405-4a43-994A-620D8F5CE25E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTFilterLicenseRenewal_INTERFACE_DEFINED)
    %IDTFilterLicenseRenewal_INTERFACE_DEFINED = 1

$IID_IDTFilterLicenseRenewal = GUID$("{8A78B317-E405-4a43-994A-620D8F5CE25E}")

INTERFACE IDTFilterLicenseRenewal $IID_IDTFilterLicenseRenewal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLicenseRenewalData ( _                     ' VTable offset = 12
     BYREF ppwszFileName AS WSTRINGZ _                  ' __out WCHAR **ppwszFileName
   , BYREF ppwszExpiredKid AS WSTRINGZ _                ' __out WCHAR **ppwszExpiredKid
   , BYREF ppwszTunerId AS WSTRINGZ _                   ' __out WCHAR **ppwszTunerId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTFilterLicenseRenewal_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPTFilterLicenseRenewal
' IID = 26D836A5-0C15-44c7-AC59-B0DA8728F240
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPTFilterLicenseRenewal_INTERFACE_DEFINED)
    %IPTFilterLicenseRenewal_INTERFACE_DEFINED = 1

$IID_IPTFilterLicenseRenewal = GUID$("{26D836A5-0C15-44c7-AC59-B0DA8728F240}")

INTERFACE IPTFilterLicenseRenewal $IID_IPTFilterLicenseRenewal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RenewLicenses ( _                             ' VTable offset = 12
     BYREF wszFileName AS WSTRINGZ _                    ' __in WCHAR *wszFileName
   , BYREF wszExpiredKid AS WSTRINGZ _                  ' __in WCHAR *wszExpiredKid
   , BYVAL dwCallersId AS DWORD _                       ' __in DWORD dwCallersId
   , BYVAL bHighPriority AS LONG _                      ' __in BOOL bHighPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelLicenseRenewal ( _                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPTFilterLicenseRenewal_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMceBurnerControl
' IID = 5A86B91A-E71E-46c1-88A9-9BB338710552
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMceBurnerControl_INTERFACE_DEFINED)
    %IMceBurnerControl_INTERFACE_DEFINED = 1

$IID_IMceBurnerControl = GUID$("{5A86B91A-E71E-46c1-88A9-9BB338710552}")

INTERFACE IMceBurnerControl $IID_IMceBurnerControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBurnerNoDecryption ( _                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMceBurnerControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMceBurnerControlTest
' IID = 462334C4-3D61-4527-8263-7A41046CD60A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMceBurnerControlTest_INTERFACE_DEFINED)
    %IMceBurnerControlTest_INTERFACE_DEFINED = 1

$IID_IMceBurnerControlTest = GUID$("{462334C4-3D61-4527-8263-7A41046CD60A}")

INTERFACE IMceBurnerControlTest $IID_IMceBurnerControlTest

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBurnerNoDecryption ( _                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMceBurnerControlTest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IETFilter
' IID = {C4C4C4B1-0049-4E2B-98FB-9537F6CE516D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IETFilter_INTERFACE_DEFINED)
    %IETFilter_INTERFACE_DEFINED = 1

INTERFACE IETFilter $IID_IETFilter

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET EvalRatObjOK ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out HRESULT *pHrCoCreateRetVal
   ' =====================================================================================
   METHOD GetCurrRating ( _                             ' VTable offset = 16
     BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnRating AS LONG _                          ' __out EnTvRat_GenericLevel *pEnRating
   , BYREF plbfEnAttr AS LONG _                         ' __out LONG *plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrLicenseExpDate ( _                     ' VTable offset = 20
     BYREF ProtType AS LONG _                           ' __in ProtType *ProtType
   , BYREF lpDateTime AS LONG _                         ' __out long *lpDateTime
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLastErrorCode ( _                          ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRecordingOn ( _                            ' VTable offset = 28
     BYVAL fRecState AS LONG _                          ' __in BOOL fRecState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IETFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IETFilterEvents
' IID = C4C4C4C1-0049-4E2B-98FB-9537F6CE516D
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IETFilterEvents_DISPINTERFACE_DEFINED)
    %IETFilterEvents_DISPINTERFACE_DEFINED = 1

INTERFACE IETFilterEvents $IID_IETFilterEvents

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IETFilterEvents_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTFilter
' IID = {C4C4C4B2-0049-4E2B-98FB-9537F6CE516D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTFilter_INTERFACE_DEFINED)
    %IDTFilter_INTERFACE_DEFINED = 1

INTERFACE IDTFilter $IID_IDTFilter

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET EvalRatObjOK ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out HRESULT *pHrCoCreateRetVal
   ' =====================================================================================
   METHOD GetCurrRating ( _                             ' VTable offset = 16
     BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnRating AS LONG _                          ' __out EnTvRat_GenericLevel *pEnRating
   , BYREF plbfEnAttr AS LONG _                         ' __out LONG *plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockedRatingAttributes ( _             ' VTable offset = 20
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   ) AS LONG                                            ' __retval_out LONG *plbfEnAttr
   ' =====================================================================================
   PROPERTY SET BlockedRatingAttributes ( _             ' VTable offset = 24
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   , BYVAL plbfEnAttr AS LONG _                         ' __in LONG plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRated ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *pfBlockUnRatedShows
   ' =====================================================================================
   PROPERTY SET BlockUnRated ( _                        ' VTable offset = 32
     BYVAL pfBlockUnRatedShows AS LONG _                ' __in BOOL pfBlockUnRatedShows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRatedDelay ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *pmsecsDelayBeforeBlock
   ' =====================================================================================
   PROPERTY SET BlockUnRatedDelay ( _                   ' VTable offset = 40
     BYVAL pmsecsDelayBeforeBlock AS LONG _             ' __in BOOL pmsecsDelayBeforeBlock
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTFilter2
' IID = {C4C4C4B4-0049-4E2B-98FB-9537F6CE516D}
' IDTFilter2 Interface
' Inherited interface = IDTFilter
' ########################################################################################

#IF NOT %DEF(%IDTFilter2_INTERFACE_DEFINED)
    %IDTFilter2_INTERFACE_DEFINED = 1

INTERFACE IDTFilter2 $IID_IDTFilter2

   INHERIT IAutomation

   ' =====================================================================================
   ' IDTFilter Methods
   ' =====================================================================================
   PROPERTY GET EvalRatObjOK ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out HRESULT *pHrCoCreateRetVal
   ' =====================================================================================
   METHOD GetCurrRating ( _                             ' VTable offset = 16
     BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnRating AS LONG _                          ' __out EnTvRat_GenericLevel *pEnRating
   , BYREF plbfEnAttr AS LONG _                         ' __out LONG *plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockedRatingAttributes ( _             ' VTable offset = 20
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   ) AS LONG                                            ' __retval_out LONG *plbfEnAttr
   ' =====================================================================================
   PROPERTY SET BlockedRatingAttributes ( _             ' VTable offset = 24
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   , BYVAL plbfEnAttr AS LONG _                         ' __in LONG plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRated ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *pfBlockUnRatedShows
   ' =====================================================================================
   PROPERTY SET BlockUnRated ( _                        ' VTable offset = 32
     BYVAL pfBlockUnRatedShows AS LONG _                ' __in BOOL pfBlockUnRatedShows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRatedDelay ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *pmsecsDelayBeforeBlock
   ' =====================================================================================
   PROPERTY SET BlockUnRatedDelay ( _                   ' VTable offset = 40
     BYVAL pmsecsDelayBeforeBlock AS LONG _             ' __in BOOL pmsecsDelayBeforeBlock
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDTFilter2 Methods
   ' =====================================================================================
   PROPERTY GET ChallengeUrl ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __out BSTR *pbstrChallengeUrl
   ' =====================================================================================
   METHOD GetCurrLicenseExpDate ( _                     ' VTable offset = 48
     BYREF ProtType AS LONG _                           ' __in ProtType *ProtType
   , BYREF lpDateTime AS LONG _                         ' __out long *lpDateTime
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLastErrorCode ( _                          ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTFilter2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTFilter3
' IID = {513998CC-E929-4CDF-9FBD-BAD1E0314866}
' Inherited interface = IDTFilter2
' ########################################################################################

#IF NOT %DEF(%IDTFilter3_INTERFACE_DEFINED)
    %IDTFilter3_INTERFACE_DEFINED = 1

INTERFACE IDTFilter3 $IID_IDTFilter3

   INHERIT IAutomation

   ' =====================================================================================
   ' IDTFilter Methods
   ' =====================================================================================
   PROPERTY GET EvalRatObjOK ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out HRESULT *pHrCoCreateRetVal
   ' =====================================================================================
   METHOD GetCurrRating ( _                             ' VTable offset = 16
     BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnRating AS LONG _                          ' __out EnTvRat_GenericLevel *pEnRating
   , BYREF plbfEnAttr AS LONG _                         ' __out LONG *plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockedRatingAttributes ( _             ' VTable offset = 20
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   ) AS LONG                                            ' __retval_out LONG *plbfEnAttr
   ' =====================================================================================
   PROPERTY SET BlockedRatingAttributes ( _             ' VTable offset = 24
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   , BYVAL plbfEnAttr AS LONG _                         ' __in LONG plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRated ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *pfBlockUnRatedShows
   ' =====================================================================================
   PROPERTY SET BlockUnRated ( _                        ' VTable offset = 32
     BYVAL pfBlockUnRatedShows AS LONG _                ' __in BOOL pfBlockUnRatedShows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRatedDelay ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *pmsecsDelayBeforeBlock
   ' =====================================================================================
   PROPERTY SET BlockUnRatedDelay ( _                   ' VTable offset = 40
     BYVAL pmsecsDelayBeforeBlock AS LONG _             ' __in BOOL pmsecsDelayBeforeBlock
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDTFilter2 Methods
   ' =====================================================================================
   PROPERTY GET ChallengeUrl ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __out BSTR *pbstrChallengeUrl
   ' =====================================================================================
   METHOD GetCurrLicenseExpDate ( _                     ' VTable offset = 48
     BYREF ProtType AS LONG _                           ' __in ProtType *ProtType
   , BYREF lpDateTime AS LONG _                         ' __out long *lpDateTime
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLastErrorCode ( _                          ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDTFilter3 Methods
   ' =====================================================================================
   METHOD GetProtectionType ( _                         ' VTable offset = 56
     BYREF pProtectionType AS LONG _                    ' __out ProtType *pProtectionType
   )                                                    ' void
   ' =====================================================================================
   METHOD LicenseHasExpirationDate ( _                  ' VTable offset = 60
     BYREF pfLicenseHasExpirationDate AS LONG _         ' __out BOOL *pfLicenseHasExpirationDate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRights ( _                                 ' VTable offset = 64
     BYVAL bstrRights AS WSTRING _                      ' __in BSTR bstrRights
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTFilter3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDTFilterEvents
' IID = C4C4C4C1-0049-4E2B-98FB-9537F6CE516D
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTFilterEvents_DISPINTERFACE_DEFINED)
    %IDTFilterEvents_DISPINTERFACE_DEFINED = 1

INTERFACE IDTFilterEvents $IID_IDTFilterEvents

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IDTFilterEvents_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXDSCodec
' IID = {C4C4C4B3-0049-4E2B-98FB-9537F6CE516D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXDSCodec_INTERFACE_DEFINED)
    %IXDSCodec_INTERFACE_DEFINED = 1

INTERFACE IXDSCodec $IID_IXDSCodec

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET XDSToRatObjOK ( _                       ' VTable offset = 12
   ) AS LONG                                            ' __retval_out HRESULT *pHrCoCreateRetVal
   ' =====================================================================================
   PROPERTY SET CCSubstreamService ( _                  ' VTable offset = 16
     BYVAL pSubstreamMask AS LONG _                     ' __in long pSubstreamMask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CCSubstreamService ( _                  ' VTable offset = 20
   ) AS LONG                                            ' __retval_out long *pSubstreamMask
   ' =====================================================================================
   METHOD GetContentAdvisoryRating ( _                  ' VTable offset = 24
     BYREF pRat AS LONG _                               ' __out PackedTvRating *pRat
   , BYREF pPktSeqID AS LONG _                          ' __out long *pPktSeqID
   , BYREF pCallSeqID AS LONG _                         ' __out long *pCallSeqID
   , BYREF pTimeStart AS QUAD _                         ' __out REFERENCE_TIME *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out REFERENCE_TIME *pTimeEnd
   )                                                    ' void
   ' =====================================================================================
   METHOD GetXDSPacket ( _                              ' VTable offset = 28
     BYREF pXDSClassPkt AS LONG _                       ' __out long *pXDSClassPkt
   , BYREF pXDSTypePkt AS LONG _                        ' __out long *pXDSTypePkt
   , BYREF pBstrXDSPkt AS WSTRING _                     ' __out BSTR *pBstrXDSPkt
   , BYREF pPktSeqID AS LONG _                          ' __out long *pPktSeqID
   , BYREF pCallSeqID AS LONG _                         ' __out long *pCallSeqID
   , BYREF pTimeStart AS QUAD _                         ' __out REFERENCE_TIME *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out REFERENCE_TIME *pTimeEnd
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrLicenseExpDate ( _                     ' VTable offset = 32
     BYREF ProtType AS LONG _                           ' __in ProtType *ProtType
   , BYREF lpDateTime AS LONG _                         ' __out long *lpDateTime
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLastErrorCode ( _                          ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXDSCodec_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXDSCodecEvents
' IID = C4C4C4C3-0049-4E2B-98FB-9537F6CE516D
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IXDSCodecEvents_DISPINTERFACE_DEFINED)
    %IXDSCodecEvents_DISPINTERFACE_DEFINED = 1

INTERFACE IXDSCodecEvents $IID_IXDSCodecEvents

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IXDSCodecEvents_DISPINTERFACE_DEFINED__ */
