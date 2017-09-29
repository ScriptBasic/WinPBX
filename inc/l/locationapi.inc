' ########################################################################################
' Microsoft Windows
' File: LocationApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: LocationApiLib
' Version: 1.0, Locale ID = 0
' Description: LocationApi 1.0 Type Library
' Path: C:\Windows\System32\LocationApi.dll
' Library GUID: {4486DF98-22A5-4F6B-BD5C-8CADCEC0A6DE}
' ########################################################################################

#INCLUDE THIS ONCE
%LOCATIONAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "SensorsApi.inc"
#INCLUDE ONCE "SensorsApi.inc"
#INCLUDE ONCE "initguid.inc"
#INCLUDE ONCE "propkeydef.inc

%LOCATION_API_VERSION = 1

$LIBID_LocationApiLib = GUID$("{4486DF98-22A5-4F6B-BD5C-8CADCEC0A6DE}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {D39E7BDD-7D05-46B8-8721-80CF035F57D7}
$PROGID_CivicAddressReport1 = "CivicAddressReport.1"
' CLSID = {8B7FBFE0-5CD7-494A-AF8C-283A65707506}
$PROGID_DefaultLocation1 = "DefaultLocationApi.1"
' CLSID = {ED81C073-1F84-4CA8-A161-183C776BC651}
$PROGID_LatLongReport1 = "LatLongReport.1"
' CLSID = {E5B8E079-EE6D-4E33-A438-C87F2E959254}
$PROGID_Location1 = "LocationApi.1"
' CLSID = {2A11F42C-3E81-4AD4-9CBE-45579D89671A}
$PROGID_CivicAddressReportFactory1 = "LocationDisp.CivicAddressReportFactory.1"
' CLSID = {4C596AEC-8544-4082-BA9F-EB0A7D8E65C6}
$PROGID_DispCivicAddressReport1 = "LocationDisp.DispCivicAddressReport.1"
' CLSID = {7A7C3277-8F84-4636-95B2-EBB5507FF77E}
$PROGID_DispLatLongReport1 = "LocationDisp.DispLatLongReport.1"
' CLSID = {9DCC3CC8-8609-4863-BAD4-03601F4C65E8}
$PROGID_LatLongReportFactory1 = "LocationDisp.LatLongReportFactory.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {D39E7BDD-7D05-46B8-8721-80CF035F57D7}
$PROGID_CivicAddressReport = "CivicAddressReport"
' CLSID = {8B7FBFE0-5CD7-494A-AF8C-283A65707506}
$PROGID_DefaultLocation = "DefaultLocationApi"
' CLSID = {ED81C073-1F84-4CA8-A161-183C776BC651}
$PROGID_LatLongReport = "LatLongReport"
' CLSID = {E5B8E079-EE6D-4E33-A438-C87F2E959254}
$PROGID_Location = "LocationApi"
' CLSID = {2A11F42C-3E81-4AD4-9CBE-45579D89671A}
$PROGID_CivicAddressReportFactory = "LocationDisp.CivicAddressReportFactory"
' CLSID = {4C596AEC-8544-4082-BA9F-EB0A7D8E65C6}
$PROGID_DispCivicAddressReport = "LocationDisp.DispCivicAddressReport"
' CLSID = {7A7C3277-8F84-4636-95B2-EBB5507FF77E}
$PROGID_DispLatLongReport = "LocationDisp.DispLatLongReport"
' CLSID = {9DCC3CC8-8609-4863-BAD4-03601F4C65E8}
$PROGID_LatLongReportFactory = "LocationDisp.LatLongReportFactory"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CivicAddressReport = GUID$("{D39E7BDD-7D05-46B8-8721-80CF035F57D7}")
$CLSID_CivicAddressReportFactory = GUID$("{2A11F42C-3E81-4AD4-9CBE-45579D89671A}")
$CLSID_DefaultLocation = GUID$("{8B7FBFE0-5CD7-494A-AF8C-283A65707506}")
$CLSID_DispCivicAddressReport = GUID$("{4C596AEC-8544-4082-BA9F-EB0A7D8E65C6}")
$CLSID_DispLatLongReport = GUID$("{7A7C3277-8F84-4636-95B2-EBB5507FF77E}")
$CLSID_LatLongReport = GUID$("{ED81C073-1F84-4CA8-A161-183C776BC651}")
$CLSID_LatLongReportFactory = GUID$("{9DCC3CC8-8609-4863-BAD4-03601F4C65E8}")
$CLSID_Location = GUID$("{E5B8E079-EE6D-4E33-A438-C87F2E959254}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICivicAddressReport = GUID$("{C0B19F70-4ADF-445D-87F2-CAD8FD711792}")
$IID_ICivicAddressReportFactory = GUID$("{BF773B93-C64F-4BEE-BEB2-67C0B8DF66E0}")
$IID_IDefaultLocation = GUID$("{A65AF77E-969A-4A2E-8ACA-33BB7CBB1235}")
$IID_IDispCivicAddressReport = GUID$("{16FF1A34-9E30-42C3-B44D-E22513B5767A}")
$IID_IDispLatLongReport = GUID$("{8AE32723-389B-4A11-9957-5BDD48FC9617}")
$IID_ILatLongReport = GUID$("{7FED806D-0EF8-4F07-80AC-36A0BEAE3134}")
$IID_ILatLongReportFactory = GUID$("{3F0804CB-B114-447D-83DD-390174EBB082}")
$IID_ILocation = GUID$("{AB2ECE69-56D9-4F28-B525-DE1B0EE44237}")
$IID_ILocationEvents = GUID$("{CAE02BBF-798B-4508-A207-35A7906DC73D}")
$IID_ILocationReport = GUID$("{C8B7F7EE-75D0-4DB9-B62D-7A0F369CA456}")
$IID_ILocationReportFactory = GUID$("{2DAEC322-90B2-47E4-BB08-0DA841935A6B}")
$IID__ICivicAddressReportFactoryEvents = GUID$("{C96039FF-72EC-4617-89BD-84D88BEDC722}")
$IID__ILatLongReportFactoryEvents = GUID$("{16EE6CB7-AB3C-424B-849F-269BE551FCBC}")

' ========================================================================================
' LOCATION_REPORT_STATUS enum
' ========================================================================================

%REPORT_NOT_SUPPORTED                                   = 0
%REPORT_ERROR                                           = 1
%REPORT_ACCESS_DENIED                                   = 2
%REPORT_INITIALIZING                                    = 3
%REPORT_RUNNING                                         = 4

' ########################################################################################
' Interface name = ILocationReport
' IID = {C8B7F7EE-75D0-4DB9-B62D-7A0F369CA456}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILocationReport_INTERFACE_DEFINED)
    %ILocationReport_INTERFACE_DEFINED = 1

INTERFACE ILocationReport $IID_ILocationReport

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSensorID ( _                               ' VTable offset = 12
   ) AS GUID                                            ' __retval_out SENSOR_ID *pSensorID
   ' =====================================================================================
   METHOD GetTimestamp ( _                              ' VTable offset = 16
   ) AS SYSTEMTIME                                      ' __retval_out SYSTEMTIME *pCreationTime
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYREF pKey AS PROPERTYKEY _                        ' __in REFPROPERTYKEY *pKey
   ) AS PROPVARIANT                                     ' __retval_out PROPVARIANT *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILocationReport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILatLongReport
' IID = {7FED806D-0EF8-4F07-80AC-36A0BEAE3134}
' Inherited interface = ILocationReport
' ########################################################################################

#IF NOT %DEF(%ILatLongReport_INTERFACE_DEFINED)
    %ILatLongReport_INTERFACE_DEFINED = 1

INTERFACE ILatLongReport $IID_ILatLongReport

   INHERIT IAutomation

   ' =====================================================================================
   ' ILocationReport Methods
   ' =====================================================================================
   METHOD GetSensorID ( _                               ' VTable offset = 12
   ) AS GUID                                            ' __retval_out SENSOR_ID *pSensorID
   ' =====================================================================================
   METHOD GetTimestamp ( _                              ' VTable offset = 16
   ) AS SYSTEMTIME                                      ' __retval_out SYSTEMTIME *pCreationTime
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYREF pKey AS PROPERTYKEY _                        ' __in REFPROPERTYKEY *pKey
   ) AS PROPVARIANT                                     ' __retval_out PROPVARIANT *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' ILatLongReport Methods
   ' =====================================================================================
   METHOD GetLatitude ( _                               ' VTable offset = 24
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pLatitude
   ' =====================================================================================
   METHOD GetLongitude ( _                              ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pLongitude
   ' =====================================================================================
   METHOD GetErrorRadius ( _                            ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pErrorRadius
   ' =====================================================================================
   METHOD GetAltitude ( _                               ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pAltitude
   ' =====================================================================================
   METHOD GetAltitudeError ( _                          ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pAltitudeError
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILatLongReport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICivicAddressReport
' IID = {C0B19F70-4ADF-445D-87F2-CAD8FD711792}
' Inherited interface = ILocationReport
' ########################################################################################

#IF NOT %DEF(%ICivicAddressReport_INTERFACE_DEFINED)
    %ICivicAddressReport_INTERFACE_DEFINED = 1

INTERFACE ICivicAddressReport $IID_ICivicAddressReport

   INHERIT IAutomation

   ' =====================================================================================
   ' ILocationReport Methods
   ' =====================================================================================
   METHOD GetSensorID ( _                               ' VTable offset = 12
   ) AS GUID                                            ' __retval_out SENSOR_ID *pSensorID
   ' =====================================================================================
   METHOD GetTimestamp ( _                              ' VTable offset = 16
   ) AS SYSTEMTIME                                      ' __retval_out SYSTEMTIME *pCreationTime
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYREF pKey AS PROPERTYKEY _                        ' __in REFPROPERTYKEY *pKey
   ) AS PROPVARIANT                                     ' __retval_out PROPVARIANT *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' ICivicAddressReport Methods
   ' =====================================================================================
   METHOD GetAddressLine1 ( _                           ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAddress1
   ' =====================================================================================
   METHOD GetAddressLine2 ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAddress2
   ' =====================================================================================
   METHOD GetCity ( _                                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCity
   ' =====================================================================================
   METHOD GetStateProvince ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStateProvince
   ' =====================================================================================
   METHOD GetPostalCode ( _                             ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPostalCode
   ' =====================================================================================
   METHOD GetCountryRegion ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCountryRegion
   ' =====================================================================================
   METHOD GetDetailLevel ( _                            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out DWORD *pDetailLevel
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICivicAddressReport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILocation
' IID = {AB2ECE69-56D9-4F28-B525-DE1B0EE44237}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILocation_INTERFACE_DEFINED)
    %ILocation_INTERFACE_DEFINED = 1

INTERFACE ILocation $IID_ILocation

   INHERIT IAutomation

   ' =====================================================================================
   METHOD RegisterForReport ( _                         ' VTable offset = 12
     BYVAL pEvents AS ILocationEvents _                 ' __in ILocationEvents *pEvents
   , BYREF reportType AS GUID _                         ' __in REFIID *reportType
   , BYVAL dwRequestedReportInterval AS DWORD _         ' __in DWORD dwRequestedReportInterval
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterForReport ( _                       ' VTable offset = 16
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   )                                                    ' void
   ' =====================================================================================
   METHOD GetReport ( _                                 ' VTable offset = 20
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   ) AS ILocationReport                                 ' __retval_out ILocationReport **ppLocationReport
   ' =====================================================================================
   METHOD GetReportStatus ( _                           ' VTable offset = 24
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   ) AS LONG                                            ' __retval_out LOCATION_REPORT_STATUS *pStatus
   ' =====================================================================================
   METHOD GetReportInterval ( _                         ' VTable offset = 28
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   ) AS DWORD                                           ' __retval_out DWORD *pMilliseconds
   ' =====================================================================================
   METHOD SetReportInterval ( _                         ' VTable offset = 32
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   , BYVAL millisecondsRequested AS DWORD _             ' __in DWORD millisecondsRequested
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesiredAccuracy ( _                        ' VTable offset = 36
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   ) AS LONG                                            ' __retval_out LOCATION_DESIRED_ACCURACY *pDesiredAccuracy
   ' =====================================================================================
   METHOD SetDesiredAccuracy ( _                        ' VTable offset = 40
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   , BYVAL desiredAccuracy AS LONG _                    ' __in LOCATION_DESIRED_ACCURACY desiredAccuracy
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestPermissions ( _                        ' VTable offset = 44
     BYVAL hParent AS DWORD _                           ' __in HWND hParent
   , BYREF pReportTypes AS GUID _                       ' __in IID *pReportTypes
   , BYVAL count AS DWORD _                             ' __in ULONG count
   , BYVAL fModal AS LONG _                             ' __in BOOL fModal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILocation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDefaultLocation
' IID = {A65AF77E-969A-4A2E-8ACA-33BB7CBB1235}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDefaultLocation_INTERFACE_DEFINED)
    %IDefaultLocation_INTERFACE_DEFINED = 1

INTERFACE IDefaultLocation $IID_IDefaultLocation

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetReport ( _                                 ' VTable offset = 12
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   , BYVAL pLocationReport AS ILocationReport _         ' __in ILocationReport *pLocationReport
   )                                                    ' void
   ' =====================================================================================
   METHOD GetReport ( _                                 ' VTable offset = 16
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   ) AS ILocationReport                                 ' __retval_out ILocationReport **ppLocationReport
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDefaultLocation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILocationEvents
' IID = {CAE02BBF-798B-4508-A207-35A7906DC73D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILocationEvents_INTERFACE_DEFINED)
    %ILocationEvents_INTERFACE_DEFINED = 1

INTERFACE ILocationEvents $IID_ILocationEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnLocationChanged ( _                         ' VTable offset = 12
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   , BYVAL pLocationReport AS ILocationReport _         ' __in ILocationReport *pLocationReport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStatusChanged ( _                           ' VTable offset = 16
     BYREF reportType AS GUID _                         ' __in REFIID *reportType
   , BYVAL newStatus AS LONG _                          ' __in LOCATION_REPORT_STATUS newStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILocationEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDispLatLongReport
' IID = {8AE32723-389B-4A11-9957-5BDD48FC9617}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDispLatLongReport_INTERFACE_DEFINED)
    %IDispLatLongReport_INTERFACE_DEFINED = 1

INTERFACE IDispLatLongReport $IID_IDispLatLongReport

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Latitude <1> ( _                        ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pVal
   ' =====================================================================================
   PROPERTY GET Longitude <2> ( _                       ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pVal
   ' =====================================================================================
   PROPERTY GET ErrorRadius <3> ( _                     ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pVal
   ' =====================================================================================
   PROPERTY GET Altitude <4> ( _                        ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pVal
   ' =====================================================================================
   PROPERTY GET AltitudeError <5> ( _                   ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pVal
   ' =====================================================================================
   PROPERTY GET Timestamp <6> ( _                       ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispLatLongReport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDispCivicAddressReport
' IID = {16FF1A34-9E30-42C3-B44D-E22513B5767A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDispCivicAddressReport_INTERFACE_DEFINED)
    %IDispCivicAddressReport_INTERFACE_DEFINED = 1

INTERFACE IDispCivicAddressReport $IID_IDispCivicAddressReport

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AddressLine1 <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pAddress1
   ' =====================================================================================
   PROPERTY GET AddressLine2 <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pAddress2
   ' =====================================================================================
   PROPERTY GET City <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pCity
   ' =====================================================================================
   PROPERTY GET StateProvince <4> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pStateProvince
   ' =====================================================================================
   PROPERTY GET PostalCode <5> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pPostalCode
   ' =====================================================================================
   PROPERTY GET CountryRegion <6> ( _                   ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pCountryRegion
   ' =====================================================================================
   PROPERTY GET DetailLevel <7> ( _                     ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out ULONG *pDetailLevel
   ' =====================================================================================
   PROPERTY GET Timestamp <8> ( _                       ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispCivicAddressReport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILocationReportFactory
' IID = {2DAEC322-90B2-47E4-BB08-0DA841935A6B}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILocationReportFactory_INTERFACE_DEFINED)
    %ILocationReportFactory_INTERFACE_DEFINED = 1

INTERFACE ILocationReportFactory $IID_ILocationReportFactory

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ListenForReports <1> ( _                      ' VTable offset = 28
     OPTIONAL BYVAL requestedReportInterval AS DWORD _  ' __in_opt ULONG requestedReportInterval = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD StopListeningForReports <2> ( _               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET status <3> ( _                          ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY GET ReportInterval <4> ( _                  ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out ULONG *pMilliseconds
   ' =====================================================================================
   PROPERTY SET ReportInterval <4> ( _                  ' VTable offset = 44
     BYVAL pMilliseconds AS DWORD _                     ' __in ULONG pMilliseconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET desiredAccuracy <5> ( _                 ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG *pDesiredAccuracy
   ' =====================================================================================
   PROPERTY SET desiredAccuracy <5> ( _                 ' VTable offset = 52
     BYVAL pDesiredAccuracy AS DWORD _                  ' __in ULONG pDesiredAccuracy
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestPermissions <6> ( _                    ' VTable offset = 56
     BYREF hWnd AS DWORD _                              ' __in ULONG *hWnd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILocationReportFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILatLongReportFactory
' IID = {3F0804CB-B114-447D-83DD-390174EBB082}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILocationReportFactory
' ########################################################################################

#IF NOT %DEF(%ILatLongReportFactory_INTERFACE_DEFINED)
    %ILatLongReportFactory_INTERFACE_DEFINED = 1

INTERFACE ILatLongReportFactory $IID_ILatLongReportFactory

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocationReportFactory Methods
   ' =====================================================================================
   METHOD ListenForReports <1> ( _                      ' VTable offset = 28
     OPTIONAL BYVAL requestedReportInterval AS DWORD _  ' __in_opt ULONG requestedReportInterval = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD StopListeningForReports <2> ( _               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET status <3> ( _                          ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY GET ReportInterval <4> ( _                  ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out ULONG *pMilliseconds
   ' =====================================================================================
   PROPERTY SET ReportInterval <4> ( _                  ' VTable offset = 44
     BYVAL pMilliseconds AS DWORD _                     ' __in ULONG pMilliseconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET desiredAccuracy <5> ( _                 ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG *pDesiredAccuracy
   ' =====================================================================================
   PROPERTY SET desiredAccuracy <5> ( _                 ' VTable offset = 52
     BYVAL pDesiredAccuracy AS DWORD _                  ' __in ULONG pDesiredAccuracy
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestPermissions <6> ( _                    ' VTable offset = 56
     BYREF hWnd AS DWORD _                              ' __in ULONG *hWnd
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ILatLongReportFactory Methods
   ' =====================================================================================
   PROPERTY GET LatLongReport <7> ( _                   ' VTable offset = 60
   ) AS IDispLatLongReport                              ' __retval_out IDispLatLongReport **pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILatLongReportFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICivicAddressReportFactory
' IID = {BF773B93-C64F-4BEE-BEB2-67C0B8DF66E0}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILocationReportFactory
' ########################################################################################

#IF NOT %DEF(%ICivicAddressReportFactory_INTERFACE_DEFINED)
    %ICivicAddressReportFactory_INTERFACE_DEFINED = 1

INTERFACE ICivicAddressReportFactory $IID_ICivicAddressReportFactory

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocationReportFactory Methods
   ' =====================================================================================
   METHOD ListenForReports <1> ( _                      ' VTable offset = 28
     OPTIONAL BYVAL requestedReportInterval AS DWORD _  ' __in_opt ULONG requestedReportInterval = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD StopListeningForReports <2> ( _               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET status <3> ( _                          ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY GET ReportInterval <4> ( _                  ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out ULONG *pMilliseconds
   ' =====================================================================================
   PROPERTY SET ReportInterval <4> ( _                  ' VTable offset = 44
     BYVAL pMilliseconds AS DWORD _                     ' __in ULONG pMilliseconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET desiredAccuracy <5> ( _                 ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG *pDesiredAccuracy
   ' =====================================================================================
   PROPERTY SET desiredAccuracy <5> ( _                 ' VTable offset = 52
     BYVAL pDesiredAccuracy AS DWORD _                  ' __in ULONG pDesiredAccuracy
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestPermissions <6> ( _                    ' VTable offset = 56
     BYREF hWnd AS DWORD _                              ' __in ULONG *hWnd
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICivicAddressReportFactory Methods
   ' =====================================================================================
   PROPERTY GET CivicAddressReport <7> ( _              ' VTable offset = 60
   ) AS IDispCivicAddressReport                         ' __retval_out IDispCivicAddressReport **pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICivicAddressReportFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CILatLongReportFactoryEvents
' Interface name = _ILatLongReportFactoryEvents
' IID = {16EE6CB7-AB3C-424B-849F-269BE551FCBC}
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CILatLongReportFactoryEvents GUID$("{6BC28C44-C01A-4B45-BB7B-DA19E6659F18}") AS EVENT

'INTERFACE ILatLongReportFactoryEventsImpl GUID$("{16EE6CB7-AB3C-424B-849F-269BE551FCBC}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD NewLatLongReport <1> ( _
'     BYVAL newReport AS IDispLatLongReport _            ' __in IDispLatLongReport *newReport
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StatusChanged <2> ( _
'     BYVAL status AS DWORD _                            ' __in ULONG status
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CICivicAddressReportFactoryEvents
' Interface name = _ICivicAddressReportFactoryEvents
' IID = {C96039FF-72EC-4617-89BD-84D88BEDC722}
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CICivicAddressReportFactoryEvents GUID$("{D4D15B73-50CC-4629-893E-F47C7C3494B2}") AS EVENT

'INTERFACE ICivicAddressReportFactoryEventsImpl GUID$("{C96039FF-72EC-4617-89BD-84D88BEDC722}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD NewCivicAddressReport <1> ( _
'     BYVAL newReport AS IDispCivicAddressReport _       ' __in IDispCivicAddressReport *newReport
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StatusChanged <2> ( _
'     BYVAL status AS DWORD _                            ' __in ULONG status
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
