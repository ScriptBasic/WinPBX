' ########################################################################################
' Microsoft Windows
' File: Pla.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: PlaLibrary
' Version: 1.0, Locale ID = 0
' Description: Performance Data Service
' Path: C:\Windows\system32\pla.dll
' Library GUID: {03837500-098B-11D8-9414-505054503030}
' ########################################################################################

#INCLUDE THIS ONCE
%PLA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"

DECLARE FUNCTION PlaExpandTaskArguments IMPORT "PLA.DLL" ALIAS "PlaExpandTaskArguments" ( _
   BYVAL vDataSet AS VARIANT _                          ' __in  VARIANT vDataSet
 , BYREF args AS WSTRING _                              ' __out BSTR* args
 ) AS LONG                                              ' HRESULT

%PLA_CAPABILITY_LOCAL          = &H10000000???
%PLA_CAPABILITY_V1_SVC         = &H00000001???
%PLA_CAPABILITY_V1_SESSION     = &H00000002???
%PLA_CAPABILITY_V1_SYSTEM      = &H00000004???
%PLA_CAPABILITY_LEGACY_SESSION = &H00000008???
%PLA_CAPABILITY_LEGACY_SVC     = &H00000010???
%PLA_CAPABILITY_AUTOLOGGER     = &H00000020???

%PLAL_ALERT_CMD_LINE_SINGLE    = &H00000100???
%PLAL_ALERT_CMD_LINE_A_NAME    = &H00000200???
%PLAL_ALERT_CMD_LINE_C_NAME    = &H00000400???
%PLAL_ALERT_CMD_LINE_D_TIME    = &H00000800???
%PLAL_ALERT_CMD_LINE_L_VAL     = &H00001000???
%PLAL_ALERT_CMD_LINE_M_VAL     = &H00002000???
%PLAL_ALERT_CMD_LINE_U_TEXT    = &H00004000???
%PLAL_ALERT_CMD_LINE_MASK      = &H00007F00???

DECLARE FUNCTION PlaGetServerCapabilities IMPORT "PLA.DLL" ALIAS "PlaGetServerCapabilities" ( _
   BYVAL Server AS WSTRING _                            ' __in_opt BSTR   Server
 , BYREF Capabilites AS DWORD _                         ' __out    PDWORD Capabilites
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PlaGetLegacyAlertActionsStringFromFlags IMPORT "PLA.DLL" ALIAS "PlaGetLegacyAlertActionsStringFromFlags" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD  dwFlags
 , BYREF pbstrAlertStr AS WSTRING _                     ' __out BSTR   *pbstrAlertStr
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PlaGetLegacyAlertActionsFlagsFromString IMPORT "PLA.DLL" ALIAS "PlaGetLegacyAlertActionsFlagsFromString" ( _
   BYREF pszArguments AS WSTRINGZ _                      ' __in  PCWSTR  pszArguments
 , BYREF pdwFlags AS DWORD _                            ' __out LPDWORD pdwFlags
 ) AS LONG                                              ' HRESULT

'typedef VOID (*PLA_CABEXTRACT_CALLBACK)(PCWSTR FileName, PVOID Context);

DECLARE FUNCTION PlaExtractCabinet IMPORT "PLA.DLL" ALIAS "PlaExtractCabinet" ( _
   BYREF CabFileName AS WSTRINGZ _                      ' __in     PCWSTR                  CabFileName
 , BYREF DestPath AS WSTRINGZ _                         ' __in     PCWSTR                  DestPath
 , BYVAL Callback AS DWORD _                            ' __in_opt PLA_CABEXTRACT_CALLBACK Callback
 , BYVAL Context AS DWORD _                             ' __in_opt PVOID                   Context
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PlaDeleteReport IMPORT "PLA.DLL" ALIAS "PlaDeleteReport" ( _
   BYREF Folder AS WSTRINGZ _                           ' __in PCWSTR Folder
 ) AS LONG                                              ' HRESULT


' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {03837538-098B-11D8-9414-505054503030}
$PROGID_PLA_BootTraceSession1 = "PLA.BootTraceSession.1"
' CLSID = {03837539-098B-11D8-9414-505054503030}
$PROGID_PLA_BootTraceSessionCollection1 = "PLA.BootTraceSessionCollection.1"
' CLSID = {03837521-098B-11D8-9414-505054503030}
$PROGID_PLA_DataCollectorSet1 = "PLA.DataCollectorSet.1"
' CLSID = {03837525-098B-11D8-9414-505054503030}
$PROGID_PLA_DataCollectorSetCollection1 = "PLA.DataCollectorSetCollection.1"
' CLSID = {03837526-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyDataCollectorSet1 = "PLA.LegacyDataCollectorSet.1"
' CLSID = {03837527-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyDataCollectorSetCollection1 = "PLA.LegacyDataCollectorSetCollection.1"
' CLSID = {03837528-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyTraceSession1 = "PLA.LegacyTraceSession.1"
' CLSID = {03837529-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyTraceSessionCollection1 = "PLA.LegacyTraceSessionCollection.1"
' CLSID = {03837531-098B-11D8-9414-505054503030}
$PROGID_PLA_ServerDataCollectorSet1 = "PLA.ServerDataCollectorSet.1"
' CLSID = {03837532-098B-11D8-9414-505054503030}
$PROGID_PLA_ServerDataCollectorSetCollection1 = "PLA.ServerDataCollectorSetCollection.1"
' CLSID = {03837546-098B-11D8-9414-505054503030}
$PROGID_PLA_SystemDataCollectorSet1 = "PLA.SystemDataCollectorSet.1"
' CLSID = {03837547-098B-11D8-9414-505054503030}
$PROGID_PLA_SystemDataCollectorSetCollection1 = "PLA.SystemDataCollectorSetCollection.1"
' CLSID = {03837513-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceDataProvider1 = "PLA.TraceDataProvider.1"
' CLSID = {03837511-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceDataProviderCollection1 = "PLA.TraceDataProviderCollection.1"
' CLSID = {0383751C-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceSession1 = "PLA.TraceSession.1"
' CLSID = {03837530-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceSessionCollection1 = "PLA.TraceSessionCollection.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {03837538-098B-11D8-9414-505054503030}
$PROGID_PLA_BootTraceSession = "PLA.BootTraceSession"
' CLSID = {03837539-098B-11D8-9414-505054503030}
$PROGID_PLA_BootTraceSessionCollection = "PLA.BootTraceSessionCollection"
' CLSID = {03837521-098B-11D8-9414-505054503030}
$PROGID_PLA_DataCollectorSet = "PLA.DataCollectorSet"
' CLSID = {03837525-098B-11D8-9414-505054503030}
$PROGID_PLA_DataCollectorSetCollection = "PLA.DataCollectorSetCollection"
' CLSID = {03837526-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyDataCollectorSet = "PLA.LegacyDataCollectorSet"
' CLSID = {03837527-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyDataCollectorSetCollection = "PLA.LegacyDataCollectorSetCollection"
' CLSID = {03837528-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyTraceSession = "PLA.LegacyTraceSession"
' CLSID = {03837529-098B-11D8-9414-505054503030}
$PROGID_PLA_LegacyTraceSessionCollection = "PLA.LegacyTraceSessionCollection"
' CLSID = {03837531-098B-11D8-9414-505054503030}
$PROGID_PLA_ServerDataCollectorSet = "PLA.ServerDataCollectorSet"
' CLSID = {03837532-098B-11D8-9414-505054503030}
$PROGID_PLA_ServerDataCollectorSetCollection = "PLA.ServerDataCollectorSetCollection"
' CLSID = {03837546-098B-11D8-9414-505054503030}
$PROGID_PLA_SystemDataCollectorSet = "PLA.SystemDataCollectorSet"
' CLSID = {03837547-098B-11D8-9414-505054503030}
$PROGID_PLA_SystemDataCollectorSetCollection = "PLA.SystemDataCollectorSetCollection"
' CLSID = {03837513-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceDataProvider = "PLA.TraceDataProvider"
' CLSID = {03837511-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceDataProviderCollection = "PLA.TraceDataProviderCollection"
' CLSID = {0383751C-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceSession = "PLA.TraceSession"
' CLSID = {03837530-098B-11D8-9414-505054503030}
$PROGID_PLA_TraceSessionCollection = "PLA.TraceSessionCollection"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_PLA_BootTraceSession = GUID$("{03837538-098B-11D8-9414-505054503030}")
$CLSID_PLA_BootTraceSessionCollection = GUID$("{03837539-098B-11D8-9414-505054503030}")
$CLSID_PLA_DataCollectorSet = GUID$("{03837521-098B-11D8-9414-505054503030}")
$CLSID_PLA_DataCollectorSetCollection = GUID$("{03837525-098B-11D8-9414-505054503030}")
$CLSID_PLA_LegacyDataCollectorSet = GUID$("{03837526-098B-11D8-9414-505054503030}")
$CLSID_PLA_LegacyDataCollectorSetCollection = GUID$("{03837527-098B-11D8-9414-505054503030}")
$CLSID_PLA_LegacyTraceSession = GUID$("{03837528-098B-11D8-9414-505054503030}")
$CLSID_PLA_LegacyTraceSessionCollection = GUID$("{03837529-098B-11D8-9414-505054503030}")
$CLSID_PLA_ServerDataCollectorSet = GUID$("{03837531-098B-11D8-9414-505054503030}")
$CLSID_PLA_ServerDataCollectorSetCollection = GUID$("{03837532-098B-11D8-9414-505054503030}")
$CLSID_PLA_SystemDataCollectorSet = GUID$("{03837546-098B-11D8-9414-505054503030}")
$CLSID_PLA_SystemDataCollectorSetCollection = GUID$("{03837547-098B-11D8-9414-505054503030}")
$CLSID_PLA_TraceDataProvider = GUID$("{03837513-098B-11D8-9414-505054503030}")
$CLSID_PLA_TraceDataProviderCollection = GUID$("{03837511-098B-11D8-9414-505054503030}")
$CLSID_PLA_TraceSession = GUID$("{0383751C-098B-11D8-9414-505054503030}")
$CLSID_PLA_TraceSessionCollection = GUID$("{03837530-098B-11D8-9414-505054503030}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_PLA_IAlertDataCollector = GUID$("{03837516-098B-11D8-9414-505054503030}")
$IID_PLA_IApiTracingDataCollector = GUID$("{0383751A-098B-11D8-9414-505054503030}")
$IID_PLA_IConfigurationDataCollector = GUID$("{03837514-098B-11D8-9414-505054503030}")
$IID_PLA_IDataCollector = GUID$("{038374FF-098B-11D8-9414-505054503030}")
$IID_PLA_IDataCollectorCollection = GUID$("{03837502-098B-11D8-9414-505054503030}")
$IID_PLA_IDataCollectorSet = GUID$("{03837520-098B-11D8-9414-505054503030}")
$IID_PLA_IDataCollectorSetCollection = GUID$("{03837524-098B-11D8-9414-505054503030}")
$IID_PLA_IDataManager = GUID$("{03837541-098B-11D8-9414-505054503030}")
$IID_PLA_IFolderAction = GUID$("{03837543-098B-11D8-9414-505054503030}")
$IID_PLA_IFolderActionCollection = GUID$("{03837544-098B-11D8-9414-505054503030}")
$IID_PLA_IPerformanceCounterDataCollector = GUID$("{03837506-098B-11D8-9414-505054503030}")
$IID_PLA_ISchedule = GUID$("{0383753A-098B-11D8-9414-505054503030}")
$IID_PLA_IScheduleCollection = GUID$("{0383753D-098B-11D8-9414-505054503030}")
$IID_PLA_ITraceDataCollector = GUID$("{0383750B-098B-11D8-9414-505054503030}")
$IID_PLA_ITraceDataProvider = GUID$("{03837512-098B-11D8-9414-505054503030}")
$IID_PLA_ITraceDataProviderCollection = GUID$("{03837510-098B-11D8-9414-505054503030}")
$IID_PLA_IValueMap = GUID$("{03837534-098B-11D8-9414-505054503030}")
$IID_PLA_IValueMapItem = GUID$("{03837533-098B-11D8-9414-505054503030}")

' ========================================================================================
' DataCollectorType enum
' ========================================================================================

%plaPerformanceCounter                                  = 0
%plaTrace                                               = 1
%plaConfiguration                                       = 2
%plaAlert                                               = 3
%plaApiTrace                                            = 4

' ========================================================================================
' AutoPathFormat
' ========================================================================================

%plaNone                                                = 0
%plaPattern                                             = &H1
%plaComputer                                            = &H2
%plaMonthDayHour                                        = &H100
%plaSerialNumber                                        = &H200
%plaYearDayOfYear                                       = &H400
%plaYearMonth                                           = &H800
%plaYearMonthDay                                        = &H1000
%plaYearMonthDayHour                                    = &H2000
%plaMonthDayHourMinute                                  = &H4000

' ========================================================================================
' ValueMapType enum
' ========================================================================================

%plaIndex                                               = 1
%plaFlag                                                = 2
%plaFlagArray                                           = 3
%plaValidation                                          = 4

' ========================================================================================
' DataCollectorSetStatus
' ========================================================================================

%plaStopped                                             = 0
%plaRunning                                             = 1
%plaCompiling                                           = 2
%plaPending                                             = 3
%plaUndefined                                           = 4

' ========================================================================================
' WeekDays enum
' ========================================================================================

%plaRunOnce                                             = 0
%plaSunday                                              = &H1
%plaMonday                                              = &H2
%plaTuesday                                             = &H4
%plaWednesday                                           = &H8
%plaThursday                                            = &H10
%plaFriday                                              = &H20
%plaSaturday                                            = &H40
%plaEveryday                                            = &H7F

' ========================================================================================
' ResourcePolicy enum
' ========================================================================================

%plaDeleteLargest                                       = 0
%plaDeleteOldest                                        = 1

' ========================================================================================
' FolderActionSteps
' ========================================================================================

%plaCreateCab                                           = &H1
%plaDeleteData                                          = &H2
%plaSendCab                                             = &H4
%plaDeleteCab                                           = &H8
%plaDeleteReport                                        = &H10

' ========================================================================================
' DataManagerSteps
' ========================================================================================

%plaCreateReport                                        = &H1
%plaRunRules                                            = &H2
%plaCreateHtml                                          = &H4
%plaFolderActions                                       = &H8
%plaResourceFreeing                                     = &H10

' ========================================================================================
' CommitMode enum
' ========================================================================================

%plaCreateNew                                           = &H1
%plaModify                                              = &H2
%plaCreateOrModify                                      = &H3
%plaUpdateRunningInstance                               = &H10
%plaFlushTrace                                          = &H20
%plaValidateOnly                                        = &H1000

' ========================================================================================
' FileFormat enum
' ========================================================================================

%plaCommaSeparated                                      = 0
%plaTabSeparated                                        = 1
%plaSql                                                 = 2
%plaBinary                                              = 3

' ========================================================================================
' ClockType enum
' ========================================================================================

%plaTimeStamp                                           = 0
%plaPerformance                                         = 1
%plaSystem                                              = 2
%plaCycle                                               = 3

' ========================================================================================
' StreamMode enum
' ========================================================================================

%plaFile                                                = &H1
%plaRealTime                                            = &H2
%plaBoth                                                = &H3
%plaBuffering                                           = &H4

' ########################################################################################
' Interface name = IDataCollectorSet
' IID = {03837520-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IDataCollectorSet_INTERFACE_DEFINED)
    %PLA_IDataCollectorSet_INTERFACE_DEFINED = 1

INTERFACE PLA_IDataCollectorSet $IID_PLA_IDataCollectorSet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataCollectors <1610743808> ( _         ' VTable offset = 28
   ) AS PLA_IDataCollectorCollection                    ' __retval_out IDataCollectorCollection **collectors
   ' =====================================================================================
   PROPERTY GET Duration <1610743809> ( _               ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out unsigned long *seconds
   ' =====================================================================================
   PROPERTY SET Duration <1610743809> ( _               ' VTable offset = 36
     BYVAL seconds AS DWORD _                           ' __in unsigned long seconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743811> ( _            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY SET Description <1610743811> ( _            ' VTable offset = 44
     BYVAL description AS WSTRING _                     ' __in BSTR description
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DescriptionUnresolved <1610743813> ( _  ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Descr
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743814> ( _            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *DisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <1610743814> ( _            ' VTable offset = 56
     BYVAL DisplayName AS WSTRING _                     ' __in BSTR DisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayNameUnresolved <1610743816> ( _  ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY GET Keywords <1610743817> ( _               ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *keywords
   ' =====================================================================================
   PROPERTY SET Keywords <1610743817> ( _               ' VTable offset = 68
     BYVAL keywords AS DWORD _                          ' __in SAFEARRAY * keywords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743819> ( _   ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743819> ( _   ' VTable offset = 76
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <0> ( _                            ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743822> ( _         ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET RootPath <1610743823> ( _               ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *folder
   ' =====================================================================================
   PROPERTY SET RootPath <1610743823> ( _               ' VTable offset = 92
     BYVAL folder AS WSTRING _                          ' __in BSTR folder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Segment <1610743825> ( _                ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *segment
   ' =====================================================================================
   PROPERTY SET Segment <1610743825> ( _                ' VTable offset = 100
     BYVAL segment AS INTEGER _                         ' __in VARIANT_BOOL segment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SegmentMaxDuration <1610743827> ( _     ' VTable offset = 104
   ) AS DWORD                                           ' __retval_out unsigned long *seconds
   ' =====================================================================================
   PROPERTY SET SegmentMaxDuration <1610743827> ( _     ' VTable offset = 108
     BYVAL seconds AS DWORD _                           ' __in unsigned long seconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SegmentMaxSize <1610743829> ( _         ' VTable offset = 112
   ) AS DWORD                                           ' __retval_out unsigned long *size
   ' =====================================================================================
   PROPERTY SET SegmentMaxSize <1610743829> ( _         ' VTable offset = 116
     BYVAL size AS DWORD _                              ' __in unsigned long size
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SerialNumber <1610743831> ( _           ' VTable offset = 120
   ) AS DWORD                                           ' __retval_out unsigned long *index
   ' =====================================================================================
   PROPERTY SET SerialNumber <1610743831> ( _           ' VTable offset = 124
     BYVAL index AS DWORD _                             ' __in unsigned long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Server <1610743833> ( _                 ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *server
   ' =====================================================================================
   PROPERTY GET Status <1610743834> ( _                 ' VTable offset = 132
   ) AS LONG                                            ' __retval_out DataCollectorSetStatus *status
   ' =====================================================================================
   PROPERTY GET Subdirectory <1610743835> ( _           ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *folder
   ' =====================================================================================
   PROPERTY SET Subdirectory <1610743835> ( _           ' VTable offset = 140
     BYVAL folder AS WSTRING _                          ' __in BSTR folder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubdirectoryFormat <1610743837> ( _     ' VTable offset = 144
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET SubdirectoryFormat <1610743837> ( _     ' VTable offset = 148
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubdirectoryFormatPattern <1610743839> ( _ ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET SubdirectoryFormatPattern <1610743839> ( _ ' VTable offset = 156
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Task <1610743841> ( _                   ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *task
   ' =====================================================================================
   PROPERTY SET Task <1610743841> ( _                   ' VTable offset = 164
     BYVAL task AS WSTRING _                            ' __in BSTR task
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TaskRunAsSelf <1610743843> ( _          ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RunAsSelf
   ' =====================================================================================
   PROPERTY SET TaskRunAsSelf <1610743843> ( _          ' VTable offset = 172
     BYVAL RunAsSelf AS INTEGER _                       ' __in VARIANT_BOOL RunAsSelf
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TaskArguments <1610743845> ( _          ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *task
   ' =====================================================================================
   PROPERTY SET TaskArguments <1610743845> ( _          ' VTable offset = 180
     BYVAL task AS WSTRING _                            ' __in BSTR task
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TaskUserTextArguments <1610743847> ( _  ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *UserText
   ' =====================================================================================
   PROPERTY SET TaskUserTextArguments <1610743847> ( _  ' VTable offset = 188
     BYVAL UserText AS WSTRING _                        ' __in BSTR UserText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Schedules <1610743849> ( _              ' VTable offset = 192
   ) AS PLA_IScheduleCollection                         ' __retval_out IScheduleCollection **ppSchedules
   ' =====================================================================================
   PROPERTY GET SchedulesEnabled <1610743850> ( _       ' VTable offset = 196
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET SchedulesEnabled <1610743850> ( _       ' VTable offset = 200
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserAccount <1610743852> ( _            ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *user
   ' =====================================================================================
   PROPERTY GET Xml <1610743853> ( _                    ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *xml
   ' =====================================================================================
   PROPERTY GET Security <1610743854> ( _               ' VTable offset = 212
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSecurity
   ' =====================================================================================
   PROPERTY SET Security <1610743854> ( _               ' VTable offset = 216
     BYVAL bstrSecurity AS WSTRING _                    ' __in BSTR bstrSecurity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopOnCompletion <1610743856> ( _       ' VTable offset = 220
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Stop
   ' =====================================================================================
   PROPERTY SET StopOnCompletion <1610743856> ( _       ' VTable offset = 224
     BYVAL Stop AS INTEGER _                            ' __in VARIANT_BOOL Stop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataManager <1610743858> ( _            ' VTable offset = 228
   ) AS PLA_IDataManager                                ' __retval_out IDataManager **DataManager
   ' =====================================================================================
   METHOD SetCredentials <1610743859> ( _               ' VTable offset = 232
     BYVAL user AS WSTRING _                            ' __in BSTR user
   , BYVAL password AS WSTRING _                        ' __in BSTR password
   )                                                    ' void
   ' =====================================================================================
   METHOD Query <1610743860> ( _                        ' VTable offset = 236
     BYVAL name AS WSTRING _                            ' __in BSTR name
   , BYVAL server AS WSTRING _                          ' __in BSTR server
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <1610743861> ( _                       ' VTable offset = 240
     BYVAL name AS WSTRING _                            ' __in BSTR name
   , BYVAL server AS WSTRING _                          ' __in BSTR server
   , BYVAL mode AS LONG _                               ' __in CommitMode mode
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **validation
   ' =====================================================================================
   METHOD Delete <1610743862> ( _                       ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD start <1610743863> ( _                        ' VTable offset = 248
     BYVAL Synchronous AS INTEGER _                     ' __in VARIANT_BOOL Synchronous
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743864> ( _                         ' VTable offset = 252
     BYVAL Synchronous AS INTEGER _                     ' __in VARIANT_BOOL Synchronous
   )                                                    ' void
   ' =====================================================================================
   METHOD SetXml <1610743865> ( _                       ' VTable offset = 256
     BYVAL xml AS WSTRING _                             ' __in BSTR xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **validation
   ' =====================================================================================
   METHOD SetValue <1610743866> ( _                     ' VTable offset = 260
     BYVAL key AS WSTRING _                             ' __in BSTR key
   , BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetValue <1610743867> ( _                     ' VTable offset = 264
     BYVAL key AS WSTRING _                             ' __in BSTR key
   ) AS WSTRING                                         ' __retval_out BSTR *value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IDataCollectorSet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataManager
' IID = {03837541-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IDataManager_INTERFACE_DEFINED)
    %PLA_IDataManager_INTERFACE_DEFINED = 1

INTERFACE PLA_IDataManager $IID_PLA_IDataManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Enabled <1610743808> ( _                ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <1610743808> ( _                ' VTable offset = 32
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckBeforeRunning <1610743810> ( _     ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCheck
   ' =====================================================================================
   PROPERTY SET CheckBeforeRunning <1610743810> ( _     ' VTable offset = 40
     BYVAL fCheck AS INTEGER _                          ' __in VARIANT_BOOL fCheck
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinFreeDisk <1610743812> ( _            ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG *MinFreeDisk
   ' =====================================================================================
   PROPERTY SET MinFreeDisk <1610743812> ( _            ' VTable offset = 48
     BYVAL MinFreeDisk AS DWORD _                       ' __in ULONG MinFreeDisk
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxSize <1610743814> ( _                ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out ULONG *pulMaxSize
   ' =====================================================================================
   PROPERTY SET MaxSize <1610743814> ( _                ' VTable offset = 56
     BYVAL ulMaxSize AS DWORD _                         ' __in ULONG ulMaxSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxFolderCount <1610743816> ( _         ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out ULONG *pulMaxFolderCount
   ' =====================================================================================
   PROPERTY SET MaxFolderCount <1610743816> ( _         ' VTable offset = 64
     BYVAL ulMaxFolderCount AS DWORD _                  ' __in ULONG ulMaxFolderCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResourcePolicy <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out ResourcePolicy *pPolicy
   ' =====================================================================================
   PROPERTY SET ResourcePolicy <1610743818> ( _         ' VTable offset = 72
     BYVAL Policy AS LONG _                             ' __in ResourcePolicy Policy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FolderActions <1610743820> ( _          ' VTable offset = 76
   ) AS PLA_IFolderActionCollection                     ' __retval_out IFolderActionCollection **Actions
   ' =====================================================================================
   PROPERTY GET ReportSchema <1610743821> ( _           ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *ReportSchema
   ' =====================================================================================
   PROPERTY SET ReportSchema <1610743821> ( _           ' VTable offset = 84
     BYVAL ReportSchema AS WSTRING _                    ' __in BSTR ReportSchema
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReportFileName <1610743823> ( _         ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFilename
   ' =====================================================================================
   PROPERTY SET ReportFileName <1610743823> ( _         ' VTable offset = 92
     BYVAL pbstrFilename AS WSTRING _                   ' __in BSTR pbstrFilename
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RuleTargetFileName <1610743825> ( _     ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *Filename
   ' =====================================================================================
   PROPERTY SET RuleTargetFileName <1610743825> ( _     ' VTable offset = 100
     BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventsFileName <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFilename
   ' =====================================================================================
   PROPERTY SET EventsFileName <1610743827> ( _         ' VTable offset = 108
     BYVAL pbstrFilename AS WSTRING _                   ' __in BSTR pbstrFilename
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rules <1610743829> ( _                  ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrXml
   ' =====================================================================================
   PROPERTY SET Rules <1610743829> ( _                  ' VTable offset = 116
     BYVAL bstrXml AS WSTRING _                         ' __in BSTR bstrXml
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <1610743831> ( _                          ' VTable offset = 120
     BYVAL Steps AS LONG _                              ' __in DataManagerSteps Steps
   , BYVAL bstrFolder AS WSTRING _                      ' __in BSTR bstrFolder
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Errors
   ' =====================================================================================
   METHOD Extract <1610743832> ( _                      ' VTable offset = 124
     BYVAL CabFilename AS WSTRING _                     ' __in BSTR CabFilename
   , BYVAL DestinationPath AS WSTRING _                 ' __in BSTR DestinationPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IDataManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFolderAction
' IID = {03837543-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IFolderAction_INTERFACE_DEFINED)
    %PLA_IFolderAction_INTERFACE_DEFINED = 1

INTERFACE PLA_IFolderAction $IID_PLA_IFolderAction

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Age <1610743808> ( _                    ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG *pulAge
   ' =====================================================================================
   PROPERTY SET Age <1610743808> ( _                    ' VTable offset = 32
     BYVAL ulAge AS DWORD _                             ' __in ULONG ulAge
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET size <1610743810> ( _                   ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *pulAge
   ' =====================================================================================
   PROPERTY SET size <1610743810> ( _                   ' VTable offset = 40
     BYVAL ulAge AS DWORD _                             ' __in ULONG ulAge
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Actions <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out FolderActionSteps *Steps
   ' =====================================================================================
   PROPERTY SET Actions <1610743812> ( _                ' VTable offset = 48
     BYVAL Steps AS LONG _                              ' __in FolderActionSteps Steps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendCabTo <1610743814> ( _              ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDestination
   ' =====================================================================================
   PROPERTY SET SendCabTo <1610743814> ( _              ' VTable offset = 56
     BYVAL bstrDestination AS WSTRING _                 ' __in BSTR bstrDestination
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IFolderAction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFolderActionCollection
' IID = {03837544-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IFolderActionCollection_INTERFACE_DEFINED)
    %PLA_IFolderActionCollection_INTERFACE_DEFINED = 1

INTERFACE PLA_IFolderActionCollection $IID_PLA_IFolderActionCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG *Count
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS PLA_IFolderAction                               ' __retval_out IFolderAction **Action
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **Enum
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL Action AS PLA_IFolderAction _                ' __in IFolderAction *Action
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743814> ( _                     ' VTable offset = 52
     BYVAL Actions AS PLA_IFolderActionCollection _     ' __in IFolderActionCollection *Actions
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateFolderAction <1610743815> ( _           ' VTable offset = 56
   ) AS PLA_IFolderAction                               ' __retval_out IFolderAction **FolderAction
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IFolderActionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataCollector
' IID = {038374FF-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IDataCollector_INTERFACE_DEFINED)
    %PLA_IDataCollector_INTERFACE_DEFINED = 1

INTERFACE PLA_IDataCollector $IID_PLA_IDataCollector

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataCollectorSet <1610743808> ( _       ' VTable offset = 28
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **group
   ' =====================================================================================
   PROPERTY SET DataCollectorSet <1610743808> ( _       ' VTable offset = 32
     BYVAL group AS PLA_IDataCollectorSet _             ' __in IDataCollectorSet *group
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataCollectorType <1610743810> ( _      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DataCollectorType *type
   ' =====================================================================================
   PROPERTY GET FileName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET FileName <1610743811> ( _               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormat <1610743813> ( _         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET FileNameFormat <1610743813> ( _         ' VTable offset = 52
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 60
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743817> ( _   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743817> ( _   ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogAppend <1610743819> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *append
   ' =====================================================================================
   PROPERTY SET LogAppend <1610743819> ( _              ' VTable offset = 76
     BYVAL append AS INTEGER _                          ' __in VARIANT_BOOL append
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogCircular <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *circular
   ' =====================================================================================
   PROPERTY SET LogCircular <1610743821> ( _            ' VTable offset = 84
     BYVAL circular AS INTEGER _                        ' __in VARIANT_BOOL circular
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOverwrite <1610743823> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *overwrite
   ' =====================================================================================
   PROPERTY SET LogOverwrite <1610743823> ( _           ' VTable offset = 92
     BYVAL overwrite AS INTEGER _                       ' __in VARIANT_BOOL overwrite
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <1610743825> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET name <1610743825> ( _                   ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Index <1610743828> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *index
   ' =====================================================================================
   PROPERTY SET Index <1610743828> ( _                  ' VTable offset = 112
     BYVAL index AS LONG _                              ' __in long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Xml <1610743830> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *Xml
   ' =====================================================================================
   METHOD SetXml <1610743831> ( _                       ' VTable offset = 120
     BYVAL Xml AS WSTRING _                             ' __in BSTR Xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Validation
   ' =====================================================================================
   METHOD CreateOutputLocation <1610743832> ( _         ' VTable offset = 124
     BYVAL Latest AS INTEGER _                          ' __in VARIANT_BOOL Latest
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IDataCollector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPerformanceCounterDataCollector
' IID = {03837506-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDataCollector
' ########################################################################################

#IF NOT %DEF(%PLA_IPerformanceCounterDataCollector_INTERFACE_DEFINED)
    %PLA_IPerformanceCounterDataCollector_INTERFACE_DEFINED = 1

INTERFACE PLA_IPerformanceCounterDataCollector $IID_PLA_IPerformanceCounterDataCollector

   INHERIT IDispatch

   ' =====================================================================================
   ' IDataCollector Methods
   ' =====================================================================================
   PROPERTY GET DataCollectorSet <1610743808> ( _       ' VTable offset = 28
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **group
   ' =====================================================================================
   PROPERTY SET DataCollectorSet <1610743808> ( _       ' VTable offset = 32
     BYVAL group AS PLA_IDataCollectorSet _             ' __in IDataCollectorSet *group
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataCollectorType <1610743810> ( _      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DataCollectorType *type
   ' =====================================================================================
   PROPERTY GET FileName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET FileName <1610743811> ( _               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormat <1610743813> ( _         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET FileNameFormat <1610743813> ( _         ' VTable offset = 52
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 60
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743817> ( _   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743817> ( _   ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogAppend <1610743819> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *append
   ' =====================================================================================
   PROPERTY SET LogAppend <1610743819> ( _              ' VTable offset = 76
     BYVAL append AS INTEGER _                          ' __in VARIANT_BOOL append
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogCircular <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *circular
   ' =====================================================================================
   PROPERTY SET LogCircular <1610743821> ( _            ' VTable offset = 84
     BYVAL circular AS INTEGER _                        ' __in VARIANT_BOOL circular
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOverwrite <1610743823> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *overwrite
   ' =====================================================================================
   PROPERTY SET LogOverwrite <1610743823> ( _           ' VTable offset = 92
     BYVAL overwrite AS INTEGER _                       ' __in VARIANT_BOOL overwrite
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <1610743825> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET name <1610743825> ( _                   ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Index <1610743828> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *index
   ' =====================================================================================
   PROPERTY SET Index <1610743828> ( _                  ' VTable offset = 112
     BYVAL index AS LONG _                              ' __in long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Xml <1610743830> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *Xml
   ' =====================================================================================
   METHOD SetXml <1610743831> ( _                       ' VTable offset = 120
     BYVAL Xml AS WSTRING _                             ' __in BSTR Xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Validation
   ' =====================================================================================
   METHOD CreateOutputLocation <1610743832> ( _         ' VTable offset = 124
     BYVAL Latest AS INTEGER _                          ' __in VARIANT_BOOL Latest
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================

   ' =====================================================================================
   ' IPerformanceCounterDataCollector Methods
   ' =====================================================================================
   PROPERTY GET DataSourceName <1610809344> ( _         ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *dsn
   ' =====================================================================================
   PROPERTY SET DataSourceName <1610809344> ( _         ' VTable offset = 132
     BYVAL dsn AS WSTRING _                             ' __in BSTR dsn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PerformanceCounters <1610809346> ( _    ' VTable offset = 136
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *counters
   ' =====================================================================================
   PROPERTY SET PerformanceCounters <1610809346> ( _    ' VTable offset = 140
     BYVAL counters AS DWORD _                          ' __in SAFEARRAY * counters
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogFileFormat <1610809348> ( _          ' VTable offset = 144
   ) AS LONG                                            ' __retval_out FileFormat *format
   ' =====================================================================================
   PROPERTY SET LogFileFormat <1610809348> ( _          ' VTable offset = 148
     BYVAL format AS LONG _                             ' __in FileFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SampleInterval <1610809350> ( _         ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out unsigned long *interval
   ' =====================================================================================
   PROPERTY SET SampleInterval <1610809350> ( _         ' VTable offset = 156
     BYVAL interval AS DWORD _                          ' __in unsigned long interval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SegmentMaxRecords <1610809352> ( _      ' VTable offset = 160
   ) AS DWORD                                           ' __retval_out unsigned long *records
   ' =====================================================================================
   PROPERTY SET SegmentMaxRecords <1610809352> ( _      ' VTable offset = 164
     BYVAL records AS DWORD _                           ' __in unsigned long records
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IPerformanceCounterDataCollector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITraceDataCollector
' IID = {0383750B-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDataCollector
' ########################################################################################

#IF NOT %DEF(%PLA_ITraceDataCollector_INTERFACE_DEFINED)
    %PLA_ITraceDataCollector_INTERFACE_DEFINED = 1

INTERFACE PLA_ITraceDataCollector $IID_PLA_ITraceDataCollector

   INHERIT IDispatch

   ' =====================================================================================
   ' IDataCollector Methods
   ' =====================================================================================
   PROPERTY GET DataCollectorSet <1610743808> ( _       ' VTable offset = 28
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **group
   ' =====================================================================================
   PROPERTY SET DataCollectorSet <1610743808> ( _       ' VTable offset = 32
     BYVAL group AS PLA_IDataCollectorSet _             ' __in IDataCollectorSet *group
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataCollectorType <1610743810> ( _      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DataCollectorType *type
   ' =====================================================================================
   PROPERTY GET FileName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET FileName <1610743811> ( _               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormat <1610743813> ( _         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET FileNameFormat <1610743813> ( _         ' VTable offset = 52
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 60
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743817> ( _   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743817> ( _   ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogAppend <1610743819> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *append
   ' =====================================================================================
   PROPERTY SET LogAppend <1610743819> ( _              ' VTable offset = 76
     BYVAL append AS INTEGER _                          ' __in VARIANT_BOOL append
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogCircular <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *circular
   ' =====================================================================================
   PROPERTY SET LogCircular <1610743821> ( _            ' VTable offset = 84
     BYVAL circular AS INTEGER _                        ' __in VARIANT_BOOL circular
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOverwrite <1610743823> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *overwrite
   ' =====================================================================================
   PROPERTY SET LogOverwrite <1610743823> ( _           ' VTable offset = 92
     BYVAL overwrite AS INTEGER _                       ' __in VARIANT_BOOL overwrite
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <1610743825> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET name <1610743825> ( _                   ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Index <1610743828> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *index
   ' =====================================================================================
   PROPERTY SET Index <1610743828> ( _                  ' VTable offset = 112
     BYVAL index AS LONG _                              ' __in long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Xml <1610743830> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *Xml
   ' =====================================================================================
   METHOD SetXml <1610743831> ( _                       ' VTable offset = 120
     BYVAL Xml AS WSTRING _                             ' __in BSTR Xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Validation
   ' =====================================================================================
   METHOD CreateOutputLocation <1610743832> ( _         ' VTable offset = 124
     BYVAL Latest AS INTEGER _                          ' __in VARIANT_BOOL Latest
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================

   ' =====================================================================================
   ' ITraceDataCollector Methods
   ' =====================================================================================
   PROPERTY GET BufferSize <1610809344> ( _             ' VTable offset = 128
   ) AS DWORD                                           ' __retval_out unsigned long *size
   ' =====================================================================================
   PROPERTY SET BufferSize <1610809344> ( _             ' VTable offset = 132
     BYVAL size AS DWORD _                              ' __in unsigned long size
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BuffersLost <1610809346> ( _            ' VTable offset = 136
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET BuffersLost <1610809346> ( _            ' VTable offset = 140
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BuffersWritten <1610809348> ( _         ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET BuffersWritten <1610809348> ( _         ' VTable offset = 148
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClockType <1610809350> ( _              ' VTable offset = 152
   ) AS LONG                                            ' __retval_out ClockType *clock
   ' =====================================================================================
   PROPERTY SET ClockType <1610809350> ( _              ' VTable offset = 156
     BYVAL clock AS LONG _                              ' __in ClockType clock
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventsLost <1610809352> ( _             ' VTable offset = 160
   ) AS DWORD                                           ' __retval_out unsigned long *events
   ' =====================================================================================
   PROPERTY SET EventsLost <1610809352> ( _             ' VTable offset = 164
     BYVAL events AS DWORD _                            ' __in unsigned long events
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExtendedModes <1610809354> ( _          ' VTable offset = 168
   ) AS DWORD                                           ' __retval_out unsigned long *mode
   ' =====================================================================================
   PROPERTY SET ExtendedModes <1610809354> ( _          ' VTable offset = 172
     BYVAL mode AS DWORD _                              ' __in unsigned long mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FlushTimer <1610809356> ( _             ' VTable offset = 176
   ) AS DWORD                                           ' __retval_out unsigned long *seconds
   ' =====================================================================================
   PROPERTY SET FlushTimer <1610809356> ( _             ' VTable offset = 180
     BYVAL seconds AS DWORD _                           ' __in unsigned long seconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FreeBuffers <1610809358> ( _            ' VTable offset = 184
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET FreeBuffers <1610809358> ( _            ' VTable offset = 188
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Guid <1610809360> ( _                   ' VTable offset = 192
   ) AS GUID                                            ' __retval_out GUID *guid
   ' =====================================================================================
   PROPERTY SET Guid <1610809360> ( _                   ' VTable offset = 196
     BYVAL guid AS GUID _                               ' __in GUID guid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsKernelTrace <1610809362> ( _          ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *kernel
   ' =====================================================================================
   PROPERTY GET MaximumBuffers <1610809363> ( _         ' VTable offset = 204
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET MaximumBuffers <1610809363> ( _         ' VTable offset = 208
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinimumBuffers <1610809365> ( _         ' VTable offset = 212
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET MinimumBuffers <1610809365> ( _         ' VTable offset = 216
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumberOfBuffers <1610809367> ( _        ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET NumberOfBuffers <1610809367> ( _        ' VTable offset = 224
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreallocateFile <1610809369> ( _        ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allocate
   ' =====================================================================================
   PROPERTY SET PreallocateFile <1610809369> ( _        ' VTable offset = 232
     BYVAL allocate AS INTEGER _                        ' __in VARIANT_BOOL allocate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProcessMode <1610809371> ( _            ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *process
   ' =====================================================================================
   PROPERTY SET ProcessMode <1610809371> ( _            ' VTable offset = 240
     BYVAL process AS INTEGER _                         ' __in VARIANT_BOOL process
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RealTimeBuffersLost <1610809373> ( _    ' VTable offset = 244
   ) AS DWORD                                           ' __retval_out unsigned long *buffers
   ' =====================================================================================
   PROPERTY SET RealTimeBuffersLost <1610809373> ( _    ' VTable offset = 248
     BYVAL buffers AS DWORD _                           ' __in unsigned long buffers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SessionId <1610809375> ( _              ' VTable offset = 252
   ) AS QUAD                                            ' __retval_out ULONG64 *id
   ' =====================================================================================
   PROPERTY SET SessionId <1610809375> ( _              ' VTable offset = 256
     BYVAL id AS QUAD _                                 ' __in ULONG64 id
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SessionName <1610809377> ( _            ' VTable offset = 260
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET SessionName <1610809377> ( _            ' VTable offset = 264
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SessionThreadId <1610809379> ( _        ' VTable offset = 268
   ) AS DWORD                                           ' __retval_out unsigned long *tid
   ' =====================================================================================
   PROPERTY SET SessionThreadId <1610809379> ( _        ' VTable offset = 272
     BYVAL tid AS DWORD _                               ' __in unsigned long tid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StreamMode <1610809381> ( _             ' VTable offset = 276
   ) AS LONG                                            ' __retval_out StreamMode *mode
   ' =====================================================================================
   PROPERTY SET StreamMode <1610809381> ( _             ' VTable offset = 280
     BYVAL mode AS LONG _                               ' __in StreamMode mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TraceDataProviders <1610809383> ( _     ' VTable offset = 284
   ) AS PLA_ITraceDataProviderCollection                ' __retval_out ITraceDataProviderCollection **providers
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_ITraceDataCollector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IConfigurationDataCollector
' IID = {03837514-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDataCollector
' ########################################################################################

#IF NOT %DEF(%PLA_IConfigurationDataCollector_INTERFACE_DEFINED)
    %PLA_IConfigurationDataCollector_INTERFACE_DEFINED = 1

INTERFACE PLA_IConfigurationDataCollector $IID_PLA_IConfigurationDataCollector

   INHERIT IDispatch

   ' =====================================================================================
   ' IDataCollector Methods
   ' =====================================================================================
   PROPERTY GET DataCollectorSet <1610743808> ( _       ' VTable offset = 28
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **group
   ' =====================================================================================
   PROPERTY SET DataCollectorSet <1610743808> ( _       ' VTable offset = 32
     BYVAL group AS PLA_IDataCollectorSet _             ' __in IDataCollectorSet *group
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataCollectorType <1610743810> ( _      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DataCollectorType *type
   ' =====================================================================================
   PROPERTY GET FileName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET FileName <1610743811> ( _               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormat <1610743813> ( _         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET FileNameFormat <1610743813> ( _         ' VTable offset = 52
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 60
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743817> ( _   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743817> ( _   ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogAppend <1610743819> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *append
   ' =====================================================================================
   PROPERTY SET LogAppend <1610743819> ( _              ' VTable offset = 76
     BYVAL append AS INTEGER _                          ' __in VARIANT_BOOL append
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogCircular <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *circular
   ' =====================================================================================
   PROPERTY SET LogCircular <1610743821> ( _            ' VTable offset = 84
     BYVAL circular AS INTEGER _                        ' __in VARIANT_BOOL circular
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOverwrite <1610743823> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *overwrite
   ' =====================================================================================
   PROPERTY SET LogOverwrite <1610743823> ( _           ' VTable offset = 92
     BYVAL overwrite AS INTEGER _                       ' __in VARIANT_BOOL overwrite
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <1610743825> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET name <1610743825> ( _                   ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Index <1610743828> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *index
   ' =====================================================================================
   PROPERTY SET Index <1610743828> ( _                  ' VTable offset = 112
     BYVAL index AS LONG _                              ' __in long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Xml <1610743830> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *Xml
   ' =====================================================================================
   METHOD SetXml <1610743831> ( _                       ' VTable offset = 120
     BYVAL Xml AS WSTRING _                             ' __in BSTR Xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Validation
   ' =====================================================================================
   METHOD CreateOutputLocation <1610743832> ( _         ' VTable offset = 124
     BYVAL Latest AS INTEGER _                          ' __in VARIANT_BOOL Latest
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================

   ' =====================================================================================
   ' IConfigurationDataCollector Methods
   ' =====================================================================================
   PROPERTY GET FileMaxCount <1610809344> ( _           ' VTable offset = 128
   ) AS DWORD                                           ' __retval_out unsigned long *count
   ' =====================================================================================
   PROPERTY SET FileMaxCount <1610809344> ( _           ' VTable offset = 132
     BYVAL count AS DWORD _                             ' __in unsigned long count
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileMaxRecursiveDepth <1610809346> ( _  ' VTable offset = 136
   ) AS DWORD                                           ' __retval_out unsigned long *depth
   ' =====================================================================================
   PROPERTY SET FileMaxRecursiveDepth <1610809346> ( _  ' VTable offset = 140
     BYVAL depth AS DWORD _                             ' __in unsigned long depth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileMaxTotalSize <1610809348> ( _       ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out unsigned long *size
   ' =====================================================================================
   PROPERTY SET FileMaxTotalSize <1610809348> ( _       ' VTable offset = 148
     BYVAL size AS DWORD _                              ' __in unsigned long size
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Files <1610809350> ( _                  ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *Files
   ' =====================================================================================
   PROPERTY SET Files <1610809350> ( _                  ' VTable offset = 156
     BYVAL Files AS DWORD _                             ' __in SAFEARRAY * Files
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ManagementQueries <1610809352> ( _      ' VTable offset = 160
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *Queries
   ' =====================================================================================
   PROPERTY SET ManagementQueries <1610809352> ( _      ' VTable offset = 164
     BYVAL Queries AS DWORD _                           ' __in SAFEARRAY * Queries
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QueryNetworkAdapters <1610809354> ( _   ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *network
   ' =====================================================================================
   PROPERTY SET QueryNetworkAdapters <1610809354> ( _   ' VTable offset = 172
     BYVAL network AS INTEGER _                         ' __in VARIANT_BOOL network
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegistryKeys <1610809356> ( _           ' VTable offset = 176
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *query
   ' =====================================================================================
   PROPERTY SET RegistryKeys <1610809356> ( _           ' VTable offset = 180
     BYVAL query AS DWORD _                             ' __in SAFEARRAY * query
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegistryMaxRecursiveDepth <1610809358> ( _ ' VTable offset = 184
   ) AS DWORD                                           ' __retval_out unsigned long *depth
   ' =====================================================================================
   PROPERTY SET RegistryMaxRecursiveDepth <1610809358> ( _ ' VTable offset = 188
     BYVAL depth AS DWORD _                             ' __in unsigned long depth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SystemStateFile <1610809360> ( _        ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *FileName
   ' =====================================================================================
   PROPERTY SET SystemStateFile <1610809360> ( _        ' VTable offset = 196
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IConfigurationDataCollector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAlertDataCollector
' IID = {03837516-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDataCollector
' ########################################################################################

#IF NOT %DEF(%PLA_IAlertDataCollector_INTERFACE_DEFINED)
    %PLA_IAlertDataCollector_INTERFACE_DEFINED = 1

INTERFACE PLA_IAlertDataCollector $IID_PLA_IAlertDataCollector

   INHERIT IDispatch

   ' =====================================================================================
   ' IDataCollector Methods
   ' =====================================================================================
   PROPERTY GET DataCollectorSet <1610743808> ( _       ' VTable offset = 28
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **group
   ' =====================================================================================
   PROPERTY SET DataCollectorSet <1610743808> ( _       ' VTable offset = 32
     BYVAL group AS PLA_IDataCollectorSet _             ' __in IDataCollectorSet *group
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataCollectorType <1610743810> ( _      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DataCollectorType *type
   ' =====================================================================================
   PROPERTY GET FileName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET FileName <1610743811> ( _               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormat <1610743813> ( _         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET FileNameFormat <1610743813> ( _         ' VTable offset = 52
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 60
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743817> ( _   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743817> ( _   ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogAppend <1610743819> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *append
   ' =====================================================================================
   PROPERTY SET LogAppend <1610743819> ( _              ' VTable offset = 76
     BYVAL append AS INTEGER _                          ' __in VARIANT_BOOL append
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogCircular <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *circular
   ' =====================================================================================
   PROPERTY SET LogCircular <1610743821> ( _            ' VTable offset = 84
     BYVAL circular AS INTEGER _                        ' __in VARIANT_BOOL circular
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOverwrite <1610743823> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *overwrite
   ' =====================================================================================
   PROPERTY SET LogOverwrite <1610743823> ( _           ' VTable offset = 92
     BYVAL overwrite AS INTEGER _                       ' __in VARIANT_BOOL overwrite
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <1610743825> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET name <1610743825> ( _                   ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Index <1610743828> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *index
   ' =====================================================================================
   PROPERTY SET Index <1610743828> ( _                  ' VTable offset = 112
     BYVAL index AS LONG _                              ' __in long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Xml <1610743830> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *Xml
   ' =====================================================================================
   METHOD SetXml <1610743831> ( _                       ' VTable offset = 120
     BYVAL Xml AS WSTRING _                             ' __in BSTR Xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Validation
   ' =====================================================================================
   METHOD CreateOutputLocation <1610743832> ( _         ' VTable offset = 124
     BYVAL Latest AS INTEGER _                          ' __in VARIANT_BOOL Latest
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================

   ' =====================================================================================
   ' IAlertDataCollector Methods
   ' =====================================================================================
   PROPERTY GET AlertThresholds <1610809344> ( _        ' VTable offset = 128
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *alerts
   ' =====================================================================================
   PROPERTY SET AlertThresholds <1610809344> ( _        ' VTable offset = 132
     BYVAL alerts AS DWORD _                            ' __in SAFEARRAY * alerts
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventLog <1610809346> ( _               ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *log
   ' =====================================================================================
   PROPERTY SET EventLog <1610809346> ( _               ' VTable offset = 140
     BYVAL log AS INTEGER _                             ' __in VARIANT_BOOL log
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SampleInterval <1610809348> ( _         ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out unsigned long *interval
   ' =====================================================================================
   PROPERTY SET SampleInterval <1610809348> ( _         ' VTable offset = 148
     BYVAL interval AS DWORD _                          ' __in unsigned long interval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Task <1610809350> ( _                   ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *task
   ' =====================================================================================
   PROPERTY SET Task <1610809350> ( _                   ' VTable offset = 156
     BYVAL task AS WSTRING _                            ' __in BSTR task
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TaskRunAsSelf <1610809352> ( _          ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RunAsSelf
   ' =====================================================================================
   PROPERTY SET TaskRunAsSelf <1610809352> ( _          ' VTable offset = 164
     BYVAL RunAsSelf AS INTEGER _                       ' __in VARIANT_BOOL RunAsSelf
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TaskArguments <1610809354> ( _          ' VTable offset = 168
   ) AS WSTRING                                         '  __retval_out BSTR *task
   ' =====================================================================================
   PROPERTY SET TaskArguments <1610809354> ( _          ' VTable offset = 172
     BYVAL task AS WSTRING _                            ' __in BSTR task
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TaskUserTextArguments <1610809356> ( _  ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *task
   ' =====================================================================================
   PROPERTY SET TaskUserTextArguments <1610809356> ( _  ' VTable offset = 180
     BYVAL task AS WSTRING _                            ' __in BSTR task
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TriggerDataCollectorSet <1610809358> ( _ ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET TriggerDataCollectorSet <1610809358> ( _ ' VTable offset = 188
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IAlertDataCollector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IApiTracingDataCollector
' IID = {0383751A-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDataCollector
' ########################################################################################

#IF NOT %DEF(%PLA_IApiTracingDataCollector_INTERFACE_DEFINED)
    %PLA_IApiTracingDataCollector_INTERFACE_DEFINED = 1

INTERFACE PLA_IApiTracingDataCollector $IID_PLA_IApiTracingDataCollector

   INHERIT IDispatch

   ' =====================================================================================
   ' IDataCollector Methods
   ' =====================================================================================
   PROPERTY GET DataCollectorSet <1610743808> ( _       ' VTable offset = 28
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **group
   ' =====================================================================================
   PROPERTY SET DataCollectorSet <1610743808> ( _       ' VTable offset = 32
     BYVAL group AS PLA_IDataCollectorSet _             ' __in IDataCollectorSet *group
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataCollectorType <1610743810> ( _      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DataCollectorType *type
   ' =====================================================================================
   PROPERTY GET FileName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET FileName <1610743811> ( _               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormat <1610743813> ( _         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AutoPathFormat *format
   ' =====================================================================================
   PROPERTY SET FileNameFormat <1610743813> ( _         ' VTable offset = 52
     BYVAL format AS LONG _                             ' __in AutoPathFormat format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pattern
   ' =====================================================================================
   PROPERTY SET FileNameFormatPattern <1610743815> ( _  ' VTable offset = 60
     BYVAL pattern AS WSTRING _                         ' __in BSTR pattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LatestOutputLocation <1610743817> ( _   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY SET LatestOutputLocation <1610743817> ( _   ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogAppend <1610743819> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *append
   ' =====================================================================================
   PROPERTY SET LogAppend <1610743819> ( _              ' VTable offset = 76
     BYVAL append AS INTEGER _                          ' __in VARIANT_BOOL append
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogCircular <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *circular
   ' =====================================================================================
   PROPERTY SET LogCircular <1610743821> ( _            ' VTable offset = 84
     BYVAL circular AS INTEGER _                        ' __in VARIANT_BOOL circular
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOverwrite <1610743823> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *overwrite
   ' =====================================================================================
   PROPERTY SET LogOverwrite <1610743823> ( _           ' VTable offset = 92
     BYVAL overwrite AS INTEGER _                       ' __in VARIANT_BOOL overwrite
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET name <1610743825> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET name <1610743825> ( _                   ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputLocation <1610743827> ( _         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Index <1610743828> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *index
   ' =====================================================================================
   PROPERTY SET Index <1610743828> ( _                  ' VTable offset = 112
     BYVAL index AS LONG _                              ' __in long index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Xml <1610743830> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *Xml
   ' =====================================================================================
   METHOD SetXml <1610743831> ( _                       ' VTable offset = 120
     BYVAL Xml AS WSTRING _                             ' __in BSTR Xml
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **Validation
   ' =====================================================================================
   METHOD CreateOutputLocation <1610743832> ( _         ' VTable offset = 124
     BYVAL Latest AS INTEGER _                          ' __in VARIANT_BOOL Latest
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================

   ' =====================================================================================
   ' IApiTracingDataCollector Methods
   ' =====================================================================================
   PROPERTY GET LogApiNamesOnly <1610809344> ( _        ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *logapinames
   ' =====================================================================================
   PROPERTY SET LogApiNamesOnly <1610809344> ( _        ' VTable offset = 132
     BYVAL logapinames AS INTEGER _                     ' __in VARIANT_BOOL logapinames
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogApisRecursively <1610809346> ( _     ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *logrecursively
   ' =====================================================================================
   PROPERTY SET LogApisRecursively <1610809346> ( _     ' VTable offset = 140
     BYVAL logrecursively AS INTEGER _                  ' __in VARIANT_BOOL logrecursively
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExePath <1610809348> ( _                ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *exepath
   ' =====================================================================================
   PROPERTY SET ExePath <1610809348> ( _                ' VTable offset = 148
     BYVAL exepath AS WSTRING _                         ' __in BSTR exepath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogFilePath <1610809350> ( _            ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *logfilepath
   ' =====================================================================================
   PROPERTY SET LogFilePath <1610809350> ( _            ' VTable offset = 156
     BYVAL logfilepath AS WSTRING _                     ' __in BSTR logfilepath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IncludeModules <1610809352> ( _         ' VTable offset = 160
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *includemodules
   ' =====================================================================================
   PROPERTY SET IncludeModules <1610809352> ( _         ' VTable offset = 164
     BYVAL includemodules AS DWORD _                    ' __in SAFEARRAY * includemodules
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IncludeApis <1610809354> ( _            ' VTable offset = 168
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *includeapis
   ' =====================================================================================
   PROPERTY SET IncludeApis <1610809354> ( _            ' VTable offset = 172
     BYVAL includeapis AS DWORD _                       ' __in SAFEARRAY * includeapis
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExcludeApis <1610809356> ( _            ' VTable offset = 176
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *excludeapis
   ' =====================================================================================
   PROPERTY SET ExcludeApis <1610809356> ( _            ' VTable offset = 180
     BYVAL excludeapis AS DWORD _                       ' __in SAFEARRAY * excludeapis
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IApiTracingDataCollector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataCollectorCollection
' IID = {03837502-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IDataCollectorCollection_INTERFACE_DEFINED)
    %PLA_IDataCollectorCollection_INTERFACE_DEFINED = 1

INTERFACE PLA_IDataCollectorCollection $IID_PLA_IDataCollectorCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS PLA_IDataCollector                              ' __retval_out IDataCollector **collector
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL collector AS PLA_IDataCollector _            ' __in IDataCollector *collector
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL collector AS VARIANT _                       ' __in VARIANT collector
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743814> ( _                     ' VTable offset = 52
     BYVAL collectors AS PLA_IDataCollectorCollection _ ' __in IDataCollectorCollection *collectors
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDataCollectorFromXml <1610743815> ( _   ' VTable offset = 56
     BYVAL bstrXml AS WSTRING _                         ' __in BSTR bstrXml
   , BYREF pValidation AS PLA_IValueMap _               ' __out IValueMap **pValidation
   ) AS PLA_IDataCollector                              ' __retval_out IDataCollector **pCollector
   ' =====================================================================================
   METHOD CreateDataCollector <1610743816> ( _          ' VTable offset = 60
     BYVAL Type AS LONG _                               ' __in DataCollectorType Type
   ) AS PLA_IDataCollector                              ' __retval_out IDataCollector **Collector
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IDataCollectorCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataCollectorSetCollection
' IID = {03837524-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IDataCollectorSetCollection_INTERFACE_DEFINED)
    %PLA_IDataCollectorSetCollection_INTERFACE_DEFINED = 1

INTERFACE PLA_IDataCollectorSetCollection $IID_PLA_IDataCollectorSetCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS PLA_IDataCollectorSet                           ' __retval_out IDataCollectorSet **set
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL set AS PLA_IDataCollectorSet _               ' __in IDataCollectorSet *set
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL set AS VARIANT _                             ' __in VARIANT set
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743814> ( _                     ' VTable offset = 52
     BYVAL sets AS PLA_IDataCollectorSetCollection _    ' __in IDataCollectorSetCollection *sets
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDataCollectorSets <1610743815> ( _         ' VTable offset = 56
     BYVAL server AS WSTRING _                          ' __in BSTR server
   , BYVAL filter AS WSTRING _                          ' __in BSTR filter
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IDataCollectorSetCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITraceDataProvider
' IID = {03837512-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_ITraceDataProvider_INTERFACE_DEFINED)
    %PLA_ITraceDataProvider_INTERFACE_DEFINED = 1

INTERFACE PLA_ITraceDataProvider $IID_PLA_ITraceDataProvider

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayName <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET DisplayName <1610743808> ( _            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Guid <1610743810> ( _                   ' VTable offset = 36
   ) AS GUID                                            ' __retval_out GUID *guid
   ' =====================================================================================
   PROPERTY SET Guid <1610743810> ( _                   ' VTable offset = 40
     BYVAL guid AS GUID _                               ' __in GUID guid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Level <1610743812> ( _                  ' VTable offset = 44
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **ppLevel
   ' =====================================================================================
   PROPERTY GET KeywordsAny <1610743813> ( _            ' VTable offset = 48
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **ppKeywords
   ' =====================================================================================
   PROPERTY GET KeywordsAll <1610743814> ( _            ' VTable offset = 52
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **ppKeywords
   ' =====================================================================================
   PROPERTY GET Properties <1610743815> ( _             ' VTable offset = 56
   ) AS PLA_IValueMap                                   ' __retval_out IValueMap **ppProperties
   ' =====================================================================================
   PROPERTY GET FilterEnabled <1610743816> ( _          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FilterEnabled
   ' =====================================================================================
   PROPERTY SET FilterEnabled <1610743816> ( _          ' VTable offset = 64
     BYVAL FilterEnabled AS INTEGER _                   ' __in VARIANT_BOOL FilterEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterType <1610743818> ( _             ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out ULONG *pulType
   ' =====================================================================================
   PROPERTY SET FilterType <1610743818> ( _             ' VTable offset = 72
     BYVAL ulType AS DWORD _                            ' __in ULONG ulType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterData <1610743820> ( _             ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppData
   ' =====================================================================================
   PROPERTY SET FilterData <1610743820> ( _             ' VTable offset = 80
     BYVAL pData AS DWORD _                             ' __in SAFEARRAY * pData
   )                                                    ' void
   ' =====================================================================================
   METHOD Query <1610743822> ( _                        ' VTable offset = 84
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrServer AS WSTRING _                      ' __in BSTR bstrServer
   )                                                    ' void
   ' =====================================================================================
   METHOD Resolve <1610743823> ( _                      ' VTable offset = 88
     BYVAL pFrom AS IDispatch _                         ' __in IDispatch *pFrom
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSecurity <1610743824> ( _                  ' VTable offset = 92
     BYVAL Sddl AS WSTRING _                            ' __in BSTR Sddl
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSecurity <1610743825> ( _                  ' VTable offset = 96
     BYVAL SecurityInfo AS DWORD _                      ' __in ULONG SecurityInfo
   ) AS WSTRING                                         ' __retval_out BSTR *Sddl
   ' =====================================================================================
   METHOD GetRegisteredProcesses <1610743826> ( _       ' VTable offset = 100
     BYREF Processes AS PLA_IValueMap _                 ' __out IValueMap **Processes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_ITraceDataProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITraceDataProviderCollection
' IID = {03837510-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_ITraceDataProviderCollection_INTERFACE_DEFINED)
    %ITraceDataProviderCollection_INTERFACE_DEFINED = 1

INTERFACE PLA_ITraceDataProviderCollection $IID_PLA_ITraceDataProviderCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS PLA_ITraceDataProvider                          ' __retval_out ITraceDataProvider **ppProvider
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL pProvider AS PLA_ITraceDataProvider _        ' __in ITraceDataProvider *pProvider
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL vProvider AS VARIANT _                       ' __in VARIANT vProvider
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743814> ( _                     ' VTable offset = 52
     BYVAL providers AS PLA_ITraceDataProviderCollection _ ' __in ITraceDataProviderCollection *providers
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTraceDataProvider <1610743815> ( _      ' VTable offset = 56
   ) AS PLA_ITraceDataProvider                          ' __retval_out ITraceDataProvider **Provider
   ' =====================================================================================
   METHOD GetTraceDataProviders <1610743816> ( _        ' VTable offset = 60
     BYVAL server AS WSTRING _                          ' __in BSTR server
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTraceDataProvidersByProcess <1610743817> ( _ ' VTable offset = 64
     BYVAL Server AS WSTRING _                          ' __in BSTR Server
   , BYVAL Pid AS DWORD _                               ' __in ULONG Pid
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_ITraceDataProviderCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISchedule
' IID = {0383753A-098B-11D8-9414-505054503030}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_ISchedule_INTERFACE_DEFINED)
    %PLA_ISchedule_INTERFACE_DEFINED = 1

INTERFACE PLA_ISchedule $IID_PLA_ISchedule

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StartDate <1610743808> ( _              ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *start
   ' =====================================================================================
   PROPERTY SET StartDate <1610743808> ( _              ' VTable offset = 32
     BYVAL start AS VARIANT _                           ' __in VARIANT start
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndDate <1610743810> ( _                ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *end
   ' =====================================================================================
   PROPERTY SET EndDate <1610743810> ( _                ' VTable offset = 40
     BYVAL end AS VARIANT _                             ' __in VARIANT end
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <1610743812> ( _              ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *start
   ' =====================================================================================
   PROPERTY SET StartTime <1610743812> ( _              ' VTable offset = 48
     BYVAL start AS VARIANT _                           ' __in VARIANT start
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Days <1610743814> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out WeekDays *days
   ' =====================================================================================
   PROPERTY SET Days <1610743814> ( _                   ' VTable offset = 56
     BYVAL days AS LONG _                               ' __in WeekDays days
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_ISchedule_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScheduleCollection
' IID = {0383753D-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IScheduleCollection_INTERFACE_DEFINED)
    %PLA_IScheduleCollection_INTERFACE_DEFINED = 1

INTERFACE PLA_IScheduleCollection $IID_PLA_IScheduleCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS PLA_ISchedule                                   ' __retval_out ISchedule **ppSchedule
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ienum
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL pSchedule AS PLA_ISchedule _                 ' __in ISchedule *pSchedule
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL vSchedule AS VARIANT _                       ' __in VARIANT vSchedule
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743814> ( _                     ' VTable offset = 52
     BYVAL pSchedules AS PLA_IScheduleCollection _      ' __in IScheduleCollection *pSchedules
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateSchedule <1610743815> ( _               ' VTable offset = 56
   ) AS PLA_ISchedule                                   ' __retval_out ISchedule **Schedule
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IScheduleCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IValueMapItem
' IID = {03837533-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IValueMapItem_INTERFACE_DEFINED)
    %PLA_IValueMapItem_INTERFACE_DEFINED = 1

INTERFACE PLA_IValueMapItem $IID_PLA_IValueMapItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Description <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY SET Description <1610743808> ( _            ' VTable offset = 32
     BYVAL description AS WSTRING _                     ' __in BSTR description
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <1610743810> ( _                ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <1610743810> ( _                ' VTable offset = 40
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <1610743812> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *key
   ' =====================================================================================
   PROPERTY SET Key <1610743812> ( _                    ' VTable offset = 48
     BYVAL key AS WSTRING _                             ' __in BSTR key
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1610743814> ( _                  ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================
   PROPERTY SET Value <1610743814> ( _                  ' VTable offset = 56
     BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValueMapType <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out ValueMapType *type
   ' =====================================================================================
   PROPERTY SET ValueMapType <1610743816> ( _           ' VTable offset = 64
     BYVAL type AS LONG _                               ' __in ValueMapType type
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IValueMapItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IValueMap
' IID = {03837534-098B-11D8-9414-505054503030}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%PLA_IValueMap_INTERFACE_DEFINED)
    %PLA_IValueMap_INTERFACE_DEFINED = 1

INTERFACE PLA_IValueMap $IID_PLA_IValueMap

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS PLA_IValueMapItem                               ' __retval_out IValueMapItem **value
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Description <1610743811> ( _            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY SET Description <1610743811> ( _            ' VTable offset = 44
     BYVAL description AS WSTRING _                     ' __in BSTR description
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1610743813> ( _                  ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================
   PROPERTY SET Value <1610743813> ( _                  ' VTable offset = 52
     BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValueMapType <1610743815> ( _           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out ValueMapType *type
   ' =====================================================================================
   PROPERTY SET ValueMapType <1610743815> ( _           ' VTable offset = 60
     BYVAL type AS LONG _                               ' __in ValueMapType type
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <1610743817> ( _                          ' VTable offset = 64
     BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743818> ( _                       ' VTable offset = 68
     BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743819> ( _                        ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743820> ( _                     ' VTable offset = 76
     BYVAL map AS PLA_IValueMap _                       ' __in IValueMap *map
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateValueMapItem <1610743821> ( _           ' VTable offset = 80
   ) AS PLA_IValueMapItem                               ' __retval_out IValueMapItem **Item
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __PLA_IValueMap_INTERFACE_DEFINED__ */
