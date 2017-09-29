' ########################################################################################
' Microsoft Windows
' File: Pdh.inc
' Contents: Header file for the Performance Data Helper (PDH) DLL functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PDH_INC = 1

'// system include files required for datatype and constant definitions
#INCLUDE ONCE "windows.inc"   ' // necessary for data types used in this file
#INCLUDE ONCE "winperf.inc"   ' // necessary for the Detail Level definitions
#INCLUDE ONCE "pdhmsg.inc"

'typedef LONG            PDH_STATUS;

'// version info
%PDH_CVERSION_WIN40 = &H0400???
%PDH_CVERSION_WIN50 = &H0500???

'// v1.1 revision of PDH -- basic log functions
'// v1.2 of the PDH -- adds variable instance counters
'// v1.3 of the PDH -- adds log service control & stubs for NT5/PDH v2 fn's
'// v2.0 of the PDH -- is the NT v 5.0 B2 version

%PDH_VERSION        = %PDH_CVERSION_WIN50 + &H0003???

'// define severity masks
'#define IsSuccessSeverity(ErrorCode)       ((((DWORD)(ErrorCode) & (0xC0000000L)) == 0x00000000L) ? TRUE : FALSE)
'#define IsInformationalSeverity(ErrorCode) ((((DWORD)(ErrorCode) & (0xC0000000L)) == 0x40000000L) ? TRUE : FALSE)
'#define IsWarningSeverity(ErrorCode)       ((((DWORD)(ErrorCode) & (0xC0000000L)) == 0x80000000L) ? TRUE : FALSE)
'#define IsErrorSeverity(ErrorCode)         ((((DWORD)(ErrorCode) & (0xC0000000L)) == 0xC0000000L) ? TRUE : FALSE)

MACRO IsSuccessSeverity(ErrorCode) = IIF&((ErrorCode AND &HC0000000???) = &H00000000???, %TRUE, %FALSE)
MACRO IsInformationalSeverity(ErrorCode) = IIF&((ErrorCode AND &HC0000000???) = &H40000000???, %TRUE, %FALSE)
MACRO IsWarningSeverity(ErrorCode) = IIF&((ErrorCode AND &HC0000000???) = &H80000000???, %TRUE, %FALSE)
MACRO IsErrorSeverity(ErrorCode) = IIF&((ErrorCode AND &HC0000000???) = &HC0000000???), %TRUE, %FALSE)

%MAX_COUNTER_PATH        = 256   ' // Maximum counter path length. This is an obsolute constance.

%PDH_MAX_COUNTER_NAME    = 1024  ' // Maximum counter name length.
%PDH_MAX_INSTANCE_NAME   = 1024  ' // Maximum counter instance name length.
%PDH_MAX_COUNTER_PATH    = 2048  ' // Maximum full counter path length.
%PDH_MAX_DATASOURCE_PATH = 1024  ' // MAximum full counter log name length.

%PDH_OBJECT_HAS_INSTANCES = &H00000001???

'// data type definitions

'typedef HANDLE       PDH_HCOUNTER;
'typedef HANDLE       PDH_HQUERY;
'typedef HANDLE       PDH_HLOG;

'typedef PDH_HCOUNTER HCOUNTER;
'typedef PDH_HQUERY   HQUERY;
'#ifndef _LMHLOGDEFINED_
'typedef PDH_HLOG     HLOG;
'#endif

'#ifdef INVALID_HANDLE_VALUE
'#undef INVALID_HANDLE_VALUE
'#define INVALID_HANDLE_VALUE  ((HANDLE)((LONG_PTR)-1))
'#endif

'#define H_REALTIME_DATASOURCE NULL
'#define H_WBEM_DATASOURCE     INVALID_HANDLE_VALUE

%H_REALTIME_DATASOURCE = %NULL
%H_WBEM_DATASOURCE     = %INVALID_HANDLE_VALUE

' // Size = 40 bytes
TYPE PDH_RAW_COUNTER QWORD
   CStatus     AS DWORD      ' DWORD
   TimeStamp   AS FILETIME   ' FILETIME
   FirstValue  AS QUAD       ' LONGLONG
   SecondValue AS QUAD       ' LONGLONG
   MultiCount  AS DWORD      ' DWORD
END TYPE

' // Size = 48 bytes
TYPE PDH_RAW_COUNTER_ITEM_A QWORD
   szName   AS ASCIIZ PTR        ' LPSTR
   RawValue AS PDH_RAW_COUNTER   ' PDH_RAW_COUNTER
END TYPE

' // Size = 48 bytes
TYPE PDH_RAW_COUNTER_ITEM_W QWORD
   szName   AS WSTRINGZ PTR      ' LPWSTR
   RawValue AS PDH_RAW_COUNTER   ' PDH_RAW_COUNTER
END TYPE

MACRO PDH_RAW_COUNTER_ITEM = PDH_RAW_COUNTER_ITEMA

' // Size = 8 bytes
UNION PDH_FMT_COUNTERVALUE_UNION QWORD
   longValue       AS LONG           ' LONG
   doubleValue     AS DOUBLE         ' double
   largeValue      AS QUAD           ' LONGLONG
   AnsiStringValue AS ASCIIZ PTR     ' LPCSTR
   WideStringValue AS WSTRINGZ PTR   ' LPCWSTR
END UNION

' // Size = 16 bytes
TYPE PDH_FMT_COUNTERVALUE QWORD
   CStatus AS DWORD   ' DWORD
   PDH_FMT_COUNTERVALUE_UNION
END TYPE

' // Size = 24 bytes
TYPE PDH_FMT_COUNTERVALUE_ITEM_A QWORD
   szName   AS ASCIIZ PTR   ' LPSTR
   FmtValue AS PDH_FMT_COUNTERVALUE
END TYPE

' // Size = 24 bytes
TYPE PDH_FMT_COUNTERVALUE_ITEM_W QWORD
   szName   AS WSTRINGZ PTR   ' LPWSTR
   FmtValue AS PDH_FMT_COUNTERVALUE
END TYPE

MACRO PDH_FMT_COUNTERVALUE_ITEM = PDH_FMT_COUNTERVALUE_ITEM_A

' // Size = 56 bytes
TYPE PDH_STATISTICS QWORD FILL
   dwFormat AS DWORD   ' DWORD
   count    AS DWORD   ' DWORD
   min      AS PDH_FMT_COUNTERVALUE
   max      AS PDH_FMT_COUNTERVALUE
   mean     AS PDH_FMT_COUNTERVALUE
END TYPE

' // Size = 24 bytes
TYPE PDH_COUNTER_PATH_ELEMENTS_A DWORD
   szMachineName    AS ASCIIZ PTR   ' LPSTR
   szObjectName     AS ASCIIZ PTR   ' LPSTR
   szInstanceName   AS ASCIIZ PTR   ' LPSTR
   szParentInstance AS ASCIIZ PTR   ' LPSTR
   dwInstanceIndex  AS DWORD        ' DWORD
   szCounterName    AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 24 bytes
TYPE PDH_COUNTER_PATH_ELEMENTS_W DWORD
   szMachineName    AS WSTRINGZ PTR   ' LPWSTR
   szObjectName     AS WSTRINGZ PTR   ' LPWSTR
   szInstanceName   AS WSTRINGZ PTR   ' LPWSTR
   szParentInstance AS WSTRINGZ PTR   ' LPWSTR
   dwInstanceIndex  AS DWORD          ' DWORD
   szCounterName    AS WSTRINGZ PTR   ' LPWSTR
END TYPE

MACRO PDH_COUNTER_PATH_ELEMENTS = PDH_COUNTER_PATH_ELEMENTS_A

' // Size = 28 bytes
TYPE PDH_DATA_ITEM_PATH_ELEMENTS_A DWORD
   szMachineName  AS ASCIIZ PTR   ' LPSTR
   ObjectGUID     AS GUID         ' GUID
   dwItemId       AS DWORD        ' DWORD
   szInstanceName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 28 bytes
TYPE PDH_DATA_ITEM_PATH_ELEMENTS_W DWORD
   szMachineName  AS WSTRINGZ PTR   ' LPWSTR
   ObjectGUID     AS GUID           ' GUID
   dwItemId       AS DWORD          ' DWORD
   szInstanceName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

MACRO PDH_DATA_ITEM_PATH_ELEMENTS = PDH_DATA_ITEM_PATH_ELEMENTS_A

' // Size = 24 bytes
TYPE PDH_COUNTER_INFO_A_UNION_STRUCT
   szMachineName    AS ASCIIZ PTR   ' LPSTR
   szObjectName     AS ASCIIZ PTR   ' LPSTR
   szInstanceName   AS ASCIIZ PTR   ' LPSTR
   szParentInstance AS ASCIIZ PTR   ' LPSTR
   dwInstanceIndex  AS DWORD        ' DWORD
   szCounterName    AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 28 bytes
UNION PDH_COUNTER_INFO_A_UNION
   DataItemPath AS PDH_DATA_ITEM_PATH_ELEMENTS_A
   CounterPath  AS PDH_COUNTER_PATH_ELEMENTS_A
   PDH_COUNTER_INFO_A_UNION_STRUCT
END UNION

' // Size = 72 bytes
TYPE PDH_COUNTER_INFO_A DWORD
   dwLength        AS DWORD        ' DWORD
   dwType          AS DWORD        ' DWORD
   CVersion        AS DWORD        ' DWORD
   CStatus         AS DWORD        ' DWORD
   lScale          AS LONG         ' LONG
   lDefaultScale   AS LONG         ' LONG
   dwUserData      AS DWORD        ' DWORD_PTR
   dwQueryUserData AS DWORD        ' DWORD_PTR
   szFullPath      AS ASCIIZ PTR   ' LPSTR
   PDH_COUNTER_INFO_A_UNION
   szExplainText   AS ASCIIZ PTR   ' LPSTR
   DataBuffer(0)   AS DWORD        ' DWORD
END TYPE

' // Size = 24 bytes
TYPE PDH_COUNTER_INFO_W_UNION_STRUCT DWORD
   szMachineName    AS WSTRINGZ PTR   ' LPWSTR
   szObjectName     AS WSTRINGZ PTR   ' LPWSTR
   szInstanceName   AS WSTRINGZ PTR   ' LPWSTR
   szParentInstance AS WSTRINGZ PTR   ' LPWSTR
   dwInstanceIndex  AS DWORD          ' DWORD
   szCounterName    AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 28 bytes
UNION PDH_COUNTER_INFO_W_UNION
   DataItemPath AS PDH_DATA_ITEM_PATH_ELEMENTS_W
   CounterPath  AS PDH_COUNTER_PATH_ELEMENTS_W
   PDH_COUNTER_INFO_W_UNION_STRUCT
END UNION

' // Size = 72 bytes
TYPE PDH_COUNTER_INFO_W DWORD
   dwLength        AS DWORD          ' DWORD
   dwType          AS DWORD          ' DWORD
   CVersion        AS DWORD          ' DWORD
   CStatus         AS DWORD          ' DWORD
   lScale          AS LONG           ' LONG
   lDefaultScale   AS LONG           ' LONG
   dwUserData      AS DWORD          ' DWORD_PTR
   dwQueryUserData AS DWORD          ' DWORD_PTR
   szFullPath      AS WSTRINGZ PTR   ' LPWSTR
   PDH_COUNTER_INFO_A_UNION
   szExplainText   AS WSTRINGZ PTR   ' LPWSTR
   DataBuffer(0)   AS DWORD          ' DWORD
END TYPE

MACRO PDH_COUNTER_INFO = PDH_COUNTER_INFO_A

' // Size = 24 bytes
TYPE PDH_TIME_INFO QWORD
   StartTime   AS QUAD    ' LONGLONG
   EndTime     AS QUAD    ' LONGLONG
   SampleCount AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE PDH_RAW_LOG_RECORD DWORD
   dwStructureSize AS DWORD   ' DWORD
   dwRecordType    AS DWORD   ' DWORD
   dwItems         AS DWORD   ' DWORD
   RawBytes(0)     AS BYTE    ' UCHAR
END TYPE

' // Size = 40 bytes
TYPE PDH_LOG_SERVICE_QUERY_INFO_A_UNION_STRUCT1 DWORD
   PdlAutoNameInterval AS DWORD        ' DWORD
   PdlAutoNameUnits    AS DWORD        ' DWORD
   PdlCommandFilename  AS ASCIIZ PTR   ' LPSTR
   PdlCounterList      AS ASCIIZ PTR   ' LPSTR
   PdlAutoNameFormat   AS DWORD        ' DWORD
   PdlSampleInterval   AS DWORD        ' DWORD
   PdlLogStartTime     AS FILETIME     ' FILETIME
   PdlLogEndTime       AS FILETIME     ' FILETIME
END TYPE

' // Size = 40 bytes
TYPE PDH_LOG_SERVICE_QUERY_INFO_A_UNION_STRUCT2 DWORD
   TlNumberOfBuffers AS DWORD        ' DWORD
   TlMinimumBuffers  AS DWORD        ' DWORD
   TlMaximumBuffers  AS DWORD        ' DWORD
   TlFreeBuffers     AS DWORD        ' DWORD
   TlBufferSize      AS DWORD        ' DWORD
   TlEventsLost      AS DWORD        ' DWORD
   TlLoggerThreadId  AS DWORD        ' DWORD
   TlBuffersWritten  AS DWORD        ' DWORD
   TlLogHandle       AS DWORD        ' DWORD
   TlLogFileName     AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 40 bytes
UNION PDH_LOG_SERVICE_QUERY_INFO_A_UNION
   PDH_LOG_SERVICE_QUERY_INFO_A_UNION_STRUCT1
   PDH_LOG_SERVICE_QUERY_INFO_A_UNION_STRUCT2
END UNION

' // Size = 72 bytes
TYPE PDH_LOG_SERVICE_QUERY_INFO_A DWORD
   dwSize           AS DWORD        ' DWORD
   dwFlags          AS DWORD        ' DWORD
   dwLogQuota       AS DWORD        ' DWORD
   szLogFileCaption AS ASCIIZ PTR   ' LPSTR
   szDefaultDir     AS ASCIIZ PTR   ' LPSTR
   szBaseFileName   AS ASCIIZ PTR   ' LPSTR
   dwFileType       AS DWORD        ' DWORD
   dwReserved       AS DWORD        ' DWORD
   PDH_LOG_SERVICE_QUERY_INFO_A_UNION
END TYPE

' // Size = 40 bytes
TYPE PDH_LOG_SERVICE_QUERY_INFO_W_UNION_STRUCT1 DWORD
   PdlAutoNameInterval AS DWORD          ' DWORD
   PdlAutoNameUnits    AS DWORD          ' DWORD
   PdlCommandFilename  AS WSTRINGZ PTR   ' LPWSTR
   PdlCounterList      AS WSTRINGZ PTR   ' LPWSTR
   PdlAutoNameFormat   AS DWORD          ' DWORD
   PdlSampleInterval   AS DWORD          ' DWORD
   PdlLogStartTime     AS FILETIME       ' FILETIME
   PdlLogEndTime       AS FILETIME       ' FILETIME
END TYPE

' // Size = 40 bytes
TYPE PDH_LOG_SERVICE_QUERY_INFO_W_UNION_STRUCT2 DWORD
   TlNumberOfBuffers AS DWORD          ' DWORD
   TlMinimumBuffers  AS DWORD          ' DWORD
   TlMaximumBuffers  AS DWORD          ' DWORD
   TlFreeBuffers     AS DWORD          ' DWORD
   TlBufferSize      AS DWORD          ' DWORD
   TlEventsLost      AS DWORD          ' DWORD
   TlLoggerThreadId  AS DWORD          ' DWORD
   TlBuffersWritten  AS DWORD          ' DWORD
   TlLogHandle       AS DWORD          ' DWORD
   TlLogFileName     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 40 bytes
UNION PDH_LOG_SERVICE_QUERY_INFO_W_UNION
   PDH_LOG_SERVICE_QUERY_INFO_W_UNION_STRUCT1
   PDH_LOG_SERVICE_QUERY_INFO_W_UNION_STRUCT2
END UNION

' // Size = 72 bytes
TYPE PDH_LOG_SERVICE_QUERY_INFO_W DWORD
   dwSize           AS DWORD          ' DWORD
   dwFlags          AS DWORD          ' DWORD
   dwLogQuota       AS DWORD          ' DWORD
   szLogFileCaption AS WSTRINGZ PTR   ' LPWSTR
   szDefaultDir     AS WSTRINGZ PTR   ' LPWSTR
   szBaseFileName   AS WSTRINGZ PTR   ' LPWSTR
   dwFileType       AS DWORD          ' DWORD
   dwReserved       AS DWORD          ' DWORD
   PDH_LOG_SERVICE_QUERY_INFO_W_UNION
END TYPE

MACRO PDH_LOG_SERVICE_QUERY_INFO = PDH_LOG_SERVICE_QUERY_INFOA

'//
'//  Time value constants
'//
'#define MAX_TIME_VALUE ((LONGLONG) 0x7FFFFFFFFFFFFFFF)
'#define MIN_TIME_VALUE ((LONGLONG) 0)

%MAX_TIME_VALUE = &H7FFFFFFFFFFFFFFF&&
%MIN_TIME_VALUE = 0&&

'// function definitions

' Returns the version of the currently installed Pdh.dll file.
' Note  This function is obsolete and no longer supported.
DECLARE FUNCTION PdhGetDllVersion IMPORT "PDH.DLL" ALIAS "PdhGetDllVersion" ( _
   BYREF lpdwVersion AS DWORD _                         ' __out LPDWORD lpdwVersion
 ) AS LONG                                              ' PDH_STATUS

'//
'//  Query Functions
'//

' Creates a new query that is used to manage the collection of performance data.
' To use handles to data sources, use the PdhOpenQueryH function.
DECLARE FUNCTION PdhOpenQueryW IMPORT "PDH.DLL" ALIAS "PdhOpenQueryW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR dwUserData
 , BYREF phQuery AS DWORD _                             ' __out PDH_HQUERY* phQuery
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhOpenQueryA IMPORT "PDH.DLL" ALIAS "PdhOpenQueryA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR szDataSource
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR dwUserData
 , BYREF phQuery AS DWORD _                             ' __out PDH_HQUERY* phQuery
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhOpenQuery = PdhOpenQueryW
#ELSE
   MACRO PdhOpenQuery = PdhOpenQueryA
#ENDIF

' Adds the specified counter to the query.
DECLARE FUNCTION PdhAddCounterW IMPORT "PDH.DLL" ALIAS "PdhAddCounterW" ( _
   BYVAL hQuery AS DWORD _                              ' __in  PDH_HQUERY hQuery
 , BYREF szFullCounterPath AS WSTRINGZ _                ' __in  LPCWSTR szFullCounterPath
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR dwUserData
 , BYREF phCounter AS DWORD _                           ' __out PDH_HCOUNTER* phCounter
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhAddCounterA IMPORT "PDH.DLL" ALIAS "PdhAddCounterA" ( _
   BYVAL hQuery AS DWORD _                              ' __in  PDH_HQUERY hQuery
 , BYREF szFullCounterPath AS ASCIIZ _                  ' __in  LPCSTR szFullCounterPath
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR dwUserData
 , BYREF phCounter AS DWORD _                           ' __out PDH_HCOUNTER* phCounter
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhAddCounter = PdhAddCounterW
#ELSE
   MACRO PdhAddCounter = PdhAddCounterA
#ENDIF

'#if (_WIN32_WINDOWS >= 0x0600 || _WIN32_WINNT >= 0x0600 || (defined(NTDDI_VERSION) && NTDDI_VERSION >= NTDDI_VISTA))
DECLARE FUNCTION PdhAddEnglishCounterW IMPORT "PDH.DLL" ALIAS "PdhAddEnglishCounterW" ( _
   BYVAL hQuery AS DWORD _                              ' __in  PDH_HQUERY     hQuery
 , BYREF szFullCounterPath AS WSTRINGZ _                ' __in  LPCWSTR        szFullCounterPath
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR      dwUserData
 , BYREF phCounter AS DWORD _                           ' __out PDH_HCOUNTER * phCounter
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhAddEnglishCounterA IMPORT "PDH.DLL" ALIAS "PdhAddEnglishCounterA" ( _
   BYVAL hQuery AS DWORD _                              ' __in  PDH_HQUERY     hQuery
 , BYREF szFullCounterPath AS ASCIIZ _                  ' __in  LPCSTR         szFullCounterPath
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR      dwUserData
 , BYREF phCounter AS DWORD _                           ' __out PDH_HCOUNTER * phCounter
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhAddEnglishCounter = PdhAddEnglishCounterW
#ELSE
   MACRO PdhAddEnglishCounter = PdhAddEnglishCounterA
#ENDIF

DECLARE FUNCTION PdhCollectQueryDataWithTime IMPORT "PDH.DLL" ALIAS "PdhCollectQueryDataWithTime" ( _
   BYVAL hQuery AS DWORD _                              ' __inout PDH_HQUERY   hQuery
 , BYREF pllTimeStamp AS QUAD _                         ' __out   LONGLONG   * pllTimeStamp
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhValidatePathExW IMPORT "PDH.DLL" ALIAS "PdhValidatePathExW" ( _
   BYVAL hDataSource AS DWORD _                         ' __in_opt PDH_HLOG hDataSource
 , BYREF szFullPathBuffer AS WSTRINGZ _                 ' __in     LPCWSTR  szFullPathBuffer
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhValidatePathExA IMPORT "PDH.DLL" ALIAS "PdhValidatePathExA" ( _
   BYVAL hDataSource AS DWORD _                         ' __in_opt PDH_HLOG hDataSource
 , BYREF szFullPathBuffer AS ASCIIZ _                   ' __in     LPCSTR  szFullPathBuffer
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhValidatePathEx = PdhValidatePathExW
#ELSE
   MACRO PdhValidatePathEx = PdhValidatePathExA
#ENDIF

'#endif


' Removes a counter from a query.
DECLARE FUNCTION PdhRemoveCounter IMPORT "PDH.DLL" ALIAS "PdhRemoveCounter" ( _
   BYVAL hCounter AS DWORD _                            ' __in PDH_HCOUNTER hCounter
 ) AS LONG                                              ' PDH_STATUS

' Collects the current raw data value for all counters in the specified query and updates the status code of each counter.
DECLARE FUNCTION PdhCollectQueryData IMPORT "PDH.DLL" ALIAS "PdhCollectQueryData" ( _
   BYVAL hQuery AS DWORD _                              ' __in PDH_HQUERY hQuery
 ) AS LONG                                              ' PDH_STATUS

' Closes all counters contained in the specified query, closes all handles related to the query, and frees all memory associated with the query.
DECLARE FUNCTION PdhCloseQuery IMPORT "PDH.DLL" ALIAS "PdhCloseQuery" ( _
   BYVAL hQuery AS DWORD _                              ' __in PDH_HQUERY hQuery
 ) AS LONG                                              ' PDH_STATUS

'//
'//  Counter Functions
'//

' Computes a displayable value for the specified counter.
DECLARE FUNCTION PdhGetFormattedCounterValue IMPORT "PDH.DLL" ALIAS "PdhGetFormattedCounterValue" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL dwFormat AS DWORD _                            ' __in  DWORD dwFormat
 , BYREF lpdwType AS DWORD _                            ' __out LPDWORD lpdwType
 , BYREF pValue AS PDH_FMT_COUNTERVALUE _               ' __out PPDH_FMT_COUNTERVALUE pValue
 ) AS LONG                                              ' PDH_STATUS

' Returns an array of formatted counter values. Use this function when you want to format
' the counter values of a counter that contains a wildcard character for the instance name.
DECLARE FUNCTION PdhGetFormattedCounterArrayA IMPORT "PDH.DLL" ALIAS "PdhGetFormattedCounterArrayA" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL dwFormat AS DWORD _                            ' __in  DWORD dwFormat
 , BYREF lpdwBufferSize AS DWORD _                      ' __in_out LPDWORD lpdwBufferSize
 , BYREF lpdwBufferCount AS DWORD _                     ' __out LPDWORD lpdwBufferCount
 , BYREF ItemBuffer AS PDH_FMT_COUNTERVALUE_ITEM_A _    ' __out PPDH_FMT_COUNTERVALUE_ITEM_A ItemBuffer
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetFormattedCounterArrayW IMPORT "PDH.DLL" ALIAS "PdhGetFormattedCounterArrayW" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL dwFormat AS DWORD _                            ' __in  DWORD dwFormat
 , BYREF lpdwBufferSize AS DWORD _                      ' __in_out LPDWORD lpdwBufferSize
 , BYREF lpdwBufferCount AS DWORD _                     ' __out LPDWORD lpdwBufferCount
 , BYREF ItemBuffer AS PDH_FMT_COUNTERVALUE_ITEM_W _    ' __out PPDH_FMT_COUNTERVALUE_ITEM_W ItemBuffer
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetFormattedCounterArray = PdhGetFormattedCounterArrayW
#ELSE
   MACRO PdhGetFormattedCounterArray = PdhGetFormattedCounterArrayA
#ENDIF

'// dwFormat flag values
'//
%PDH_FMT_RAW          = &H00000010???
%PDH_FMT_ANSI         = &H00000020???
%PDH_FMT_UNICODE      = &H00000040???
%PDH_FMT_LONG         = &H00000100???
%PDH_FMT_DOUBLE       = &H00000200???
%PDH_FMT_LARGE        = &H00000400???
%PDH_FMT_NOSCALE      = &H00001000???
%PDH_FMT_1000         = &H00002000???
%PDH_FMT_NODATA       = &H00004000???
%PDH_FMT_NOCAP100     = &H00008000???
%PERF_DETAIL_COSTLY   = &H00010000???
%PERF_DETAIL_STANDARD = &H0000FFFF???

' Returns the current raw value of the counter.
DECLARE FUNCTION PdhGetRawCounterValue IMPORT "PDH.DLL" ALIAS "PdhGetRawCounterValue" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYREF lpdwType AS DWORD _                            ' __out LPDWORD lpdwType
 , BYREF pValue AS PDH_RAW_COUNTER _                    ' __out PPDH_RAW_COUNTER pValue
 ) AS LONG                                              ' PDH_STATUS

' Returns an array of raw values from the specified counter. Use this function when you want to
' retrieve the raw counter values of a counter that contains a wildcard character for the instance name.
DECLARE FUNCTION PdhGetRawCounterArrayA IMPORT "PDH.DLL" ALIAS "PdhGetRawCounterArrayA" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYREF lpdwBufferSize AS DWORD _                      ' __in_out LPDWORD lpdwBufferSize
 , BYREF lpdwItemCount AS DWORD _                       ' __out LPDWORD lpdwItemCount
 , BYREF ItemBuffer AS PDH_RAW_COUNTER_ITEM_A _         ' __out PPDH_RAW_COUNTER_ITEM_A ItemBuffer
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetRawCounterArrayW IMPORT "PDH.DLL" ALIAS "PdhGetRawCounterArrayW" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYREF lpdwBufferSize AS DWORD _                      ' __in_out LPDWORD lpdwBufferSize
 , BYREF lpdwItemCount AS DWORD _                       ' __out LPDWORD lpdwItemCount
 , BYREF ItemBuffer AS PDH_RAW_COUNTER_ITEM_W _         ' __out PPDH_RAW_COUNTER_ITEM_W ItemBuffer
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetRawCounterArray = PdhGetRawCounterArrayW
#ELSE
   MACRO PdhGetRawCounterArray = PdhGetRawCounterArrayA
#ENDIF

' Calculates the displayable value of two raw counter values
DECLARE FUNCTION PdhCalculateCounterFromRawValue IMPORT "PDH.DLL" ALIAS "PdhCalculateCounterFromRawValue" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL dwFormat AS DWORD _                            ' __in  DWORD dwFormat
 , BYVAL rawValue1 AS DWORD _                           ' __in  PPDH_RAW_COUNTER rawValue1
 , BYVAL rawValue2 AS DWORD _                           ' __in  PPDH_RAW_COUNTER rawValue2
 , BYREF fmtValue AS PDH_FMT_COUNTERVALUE _             ' __out PPDH_FMT_COUNTERVALUE fmtValue
 ) AS LONG                                              ' PDH_STATUS

' Computes statistics for a counter from an array of raw values.
DECLARE FUNCTION PdhComputeCounterStatistics IMPORT "PDH.DLL" ALIAS "PdhComputeCounterStatistics" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL dwFormat AS DWORD _                            ' __in  DWORD dwFormat
 , BYVAL dwFirstEntry AS DWORD _                        ' __in  DWORD dwFirstEntry
 , BYVAL dwNumEntries AS DWORD _                        ' __in  DWORD dwNumEntries
 , BYREF lpRawValueArray AS PDH_RAW_COUNTER _           ' __in  PPDH_RAW_COUNTER lpRawValueArray
 , BYREF data AS PDH_STATISTICS _                       ' __out PPDH_STATISTICS data
 ) AS LONG                                              ' PDH_STATUS

' Retrieves information about a counter, such as data size, counter type, path, and user-supplied data values.
DECLARE FUNCTION PdhGetCounterInfoW IMPORT "PDH.DLL" ALIAS "PdhGetCounterInfoW" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL bRetrieveExplainText AS BYTE _                 ' __in  BOOLEAN bRetrieveExplainText
 , BYREF pdwBufferSize AS DWORD _                       ' __in_out LPDWORD pdwBufferSize
 , BYREF lpBuffer AS PDH_COUNTER_INFO_W _               ' __out PPDH_COUNTER_INFO_W lpBuffer
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetCounterInfoA IMPORT "PDH.DLL" ALIAS "PdhGetCounterInfoA" ( _
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER hCounter
 , BYVAL bRetrieveExplainText AS BYTE _                 ' __in  BOOLEAN bRetrieveExplainText
 , BYREF pdwBufferSize AS DWORD _                       ' __in_out LPDWORD pdwBufferSize
 , BYREF lpBuffer AS PDH_COUNTER_INFO_A _               ' __out PPDH_COUNTER_INFO_A lpBuffer
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetCounterInfo = PdhGetCounterInfoW
#ELSE
   MACRO PdhGetCounterInfo = PdhGetCounterInfoA
#ENDIF

%PDH_MAX_SCALE = 7&
%PDH_MIN_SCALE = -7&

' Sets the scale factor that is applied to the calculated value of the specified counter
' when you request the formatted counter value. If the PDH_FMT_NOSCALE flag is set, then
' this scale factor is ignored.
DECLARE FUNCTION PdhSetCounterScaleFactor IMPORT "PDH.DLL" ALIAS "PdhSetCounterScaleFactor" ( _
   BYVAL hCounter AS DWORD _                            ' __in PDH_HCOUNTER hCounter
 , BYVAL lFactor AS LONG _                              ' __in LONG lFactor
 ) AS LONG                                              ' PDH_STATUS

'//
'//   Browsing and enumeration functions
'//

' Connects to the specified computer.
DECLARE FUNCTION PdhConnectMachineW IMPORT "PDH.DLL" ALIAS "PdhConnectMachineW" ( _
   BYREF szMachineName AS WSTRINGZ _                    ' __in LPCWSTR szMachineName
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhConnectMachineA IMPORT "PDH.DLL" ALIAS "PdhConnectMachineA" ( _
   BYREF szMachineName AS ASCIIZ _                      ' __in LPCSTR szMachineName
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhConnectMachine = PdhConnectMachineW
#ELSE
   MACRO PdhConnectMachine = PdhConnectMachineA
#ENDIF

' Returns a list of the computer names associated with counters in a log file. The computer
' names were either specified when adding counters to the query or when calling the
' PdhConnectMachine function. The computers listed include those that are currently
' connected and online, in addition to those that are offline or not returning performance data.
' To use handles to data sources, use the PdhEnumMachinesH function.
DECLARE FUNCTION PdhEnumMachinesW IMPORT "PDH.DLL" ALIAS "PdhEnumMachinesW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF mszMachineNameList AS WSTRINGZ _               ' __out LPWSTR mszMachineNameList
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumMachinesA IMPORT "PDH.DLL" ALIAS "PdhEnumMachinesA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR szDataSource
 , BYVAL mszMachineNameList AS DWORD _                  ' __out LPSTR mszMachineNameList
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumMachines = PdhEnumMachinesW
#ELSE
   MACRO PdhEnumMachines = PdhEnumMachinesA
#ENDIF

' Returns a list of objects available on the specified computer or in the specified log file.
' To use handles to data sources, use the PdhEnumObjectsH function.
DECLARE FUNCTION PdhEnumObjectsW IMPORT "PDH.DLL" ALIAS "PdhEnumObjectsW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR szMachineName
 , BYREF mszObjectList AS WSTRINGZ _                    ' __out LPWSTR mszObjectList
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD dwDetailLevel
 , BYVAL bRefresh AS LONG _                             ' __in  BOOL bRefresh
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumObjectsA IMPORT "PDH.DLL" ALIAS "PdhEnumObjectsA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR szDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR szMachineName
 , BYVAL mszObjectList AS DWORD _                       ' __out LPSTR mszObjectList
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD dwDetailLevel
 , BYVAL bRefresh AS LONG _                             ' __in  BOOL bRefresh
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumObjects = PdhEnumObjectsW
#ELSE
   MACRO PdhEnumObjects = PdhEnumObjectsA
#ENDIF

' Returns the specified object's counter and instance names that exist on the
' specified computer or in the specified log file.
' To use handles to data sources, use the PdhEnumObjectItemsH function.
DECLARE FUNCTION PdhEnumObjectItemsW IMPORT "PDH.DLL" ALIAS "PdhEnumObjectItemsW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR szMachineName
 , BYREF szObjectName AS WSTRINGZ _                     ' __in  LPCWSTR szObjectName
 , BYREF mszCounterList AS WSTRINGZ _                   ' __out LPWSTR mszCounterList
 , BYREF pcchCounterListLength AS DWORD _               ' __in_out LPDWORD pcchCounterListLength
 , BYREF mszInstanceList AS WSTRINGZ _                  ' __out LPWSTR mszInstanceList
 , BYREF pcchInstanceListLength AS DWORD _              ' __in_out LPDWORD pcchInstanceListLength
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD dwDetailLevel
 , BYVAL dwFlags AS LONG _                              ' __in  DWORD dwFlags
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumObjectItemsA IMPORT "PDH.DLL" ALIAS "PdhEnumObjectItemsA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR szDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR szMachineName
 , BYREF szObjectName AS ASCIIZ _                       ' __in  LPCSTR szObjectName
 , BYVAL mszCounterList AS DWORD _                      ' __out LPSTR mszCounterList
 , BYREF pcchCounterListLength AS DWORD _               ' __in_out LPDWORD pcchCounterListLength
 , BYVAL mszInstanceList AS DWORD _                     ' __out LPSTR mszInstanceList
 , BYREF pcchInstanceListLength AS DWORD _              ' __in_out LPDWORD pcchInstanceListLength
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD dwDetailLevel
 , BYVAL dwFlags AS LONG _                              ' __in  DWORD dwFlags
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumObjectItems = PdhEnumObjectItemsW
#ELSE
   MACRO PdhEnumObjectItems = PdhEnumObjectItemsA
#ENDIF

%PDH_OBJECT_HAS_INSTANCES    = &H00000001???

' Creates a full counter path using the members specified in the PDH_COUNTER_PATH_ELEMENTS structure.
DECLARE FUNCTION PdhMakeCounterPathW IMPORT "PDH.DLL" ALIAS "PdhMakeCounterPathW" ( _
   BYREF pCounterPathElements AS PDH_COUNTER_PATH_ELEMENTS_W _ ' __in  PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements
 , BYREF szFullPathBuffer AS WSTRINGZ _                 ' __out LPWSTR szFullPathBuffer
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD pcchBufferSize
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhMakeCounterPathA IMPORT "PDH.DLL" ALIAS "PdhMakeCounterPathA" ( _
   BYREF pCounterPathElements AS PDH_COUNTER_PATH_ELEMENTS_A _ ' __in  PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements
 , BYREF szFullPathBuffer AS ASCIIZ _                   ' __out LPSTR szFullPathBuffer
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD pcchBufferSize
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhMakeCounterPath = PdhMakeCounterPathW
#ELSE
   MACRO PdhMakeCounterPath = PdhMakeCounterPathA
#ENDIF

' Parses the elements of the counter path and stores the results in the PDH_COUNTER_PATH_ELEMENTS structure.
DECLARE FUNCTION PdhParseCounterPathW IMPORT "PDH.DLL" ALIAS "PdhParseCounterPathW" ( _
   BYREF szFullPathBuffer AS WSTRINGZ _                 ' __in  LPCWSTR szFullPathBuffer
 , BYREF pCounterPathElements AS PDH_COUNTER_PATH_ELEMENTS_W _ ' __out PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements
 , BYREF pdwBufferSize AS DWORD _                       ' __in_out LPDWORD pdwBufferSize
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhParseCounterPathA IMPORT "PDH.DLL" ALIAS "PdhParseCounterPathA" ( _
   BYREF szFullPathBuffer AS ASCIIZ _                   ' __in  LPCSTR szFullPathBuffer
 , BYREF pCounterPathElements AS PDH_COUNTER_PATH_ELEMENTS_A _ ' __out PPDH_COUNTER_PATH_ELEMENTS_A pCounterPathElements
 , BYREF pdwBufferSize AS DWORD _                       ' __in_out LPDWORD pdwBufferSize
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhParseCounterPath = PdhParseCounterPathW
#ELSE
   MACRO PdhParseCounterPath = PdhParseCounterPathA
#ENDIF

%PDH_PATH_WBEM_RESULT = &H00000001???
%PDH_PATH_WBEM_INPUT  = &H00000002???

'#define PDH_PATH_LANG_FLAGS(LangId, Flags)  ((DWORD)(((LangId & 0x0000FFFF) << 16) | (Flags & 0x0000FFFF)))
MACRO PDH_PATH_LANG_FLAGS(LangId, Flags) = LO(DWORD,((LangId AND &H0000FFFF???) * 65536) OR (Flags AND &H0000FFFF???))

' Parses the elements of an instance string.
DECLARE FUNCTION PdhParseInstanceNameW IMPORT "PDH.DLL" ALIAS "PdhParseInstanceNameW" ( _
   BYREF szInstanceString AS WSTRINGZ _                 ' __in  LPCWSTR szInstanceString
 , BYREF szInstanceName AS WSTRINGZ _                   ' __out LPWSTR  szInstanceName
 , BYREF pcchInstanceNameLength AS DWORD _              ' __in_out LPDWORD pcchInstanceNameLength
 , BYREF szParentName AS WSTRINGZ _                     ' __out LPWSTR  szParentName
 , BYREF pcchParentNameLength AS DWORD _                ' __in_out IN  LPDWORD pcchParentNameLength
 , BYREF lpIndex AS DWORD _                             ' __out LPDWORD lpIndex
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhParseInstanceNameA IMPORT "PDH.DLL" ALIAS "PdhParseInstanceNameA" ( _
   BYREF szInstanceString AS ASCIIZ _                   ' __in  LPCSTR  szInstanceString
 , BYREF szInstanceName AS ASCIIZ _                     ' __out LPSTR   szInstanceName
 , BYREF pcchInstanceNameLength AS DWORD _              ' __in_out LPDWORD pcchInstanceNameLength
 , BYREF szParentName AS ASCIIZ _                       ' __out LPSTR   szParentName
 , BYREF pcchParentNameLength AS DWORD _                ' __in_out IN  LPDWORD pcchParentNameLength
 , BYREF lpIndex AS DWORD _                             ' __out LPDWORD lpIndex
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhParseInstanceName = PdhParseInstanceNameW
#ELSE
   MACRO PdhParseInstanceName = PdhParseInstanceNameA
#ENDIF

' Validates that the counter is present on the computer specified in the counter path.
DECLARE FUNCTION PdhValidatePathW IMPORT "PDH.DLL" ALIAS "PdhValidatePathW" ( _
   BYREF szFullPathBuffer AS WSTRINGZ _                 ' __in LPCWSTR szFullPathBuffer
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhValidatePathA IMPORT "PDH.DLL" ALIAS "PdhValidatePathA" ( _
   BYREF szFullPathBuffer AS ASCIIZ _                   ' __in LPCSTR szFullPathBuffer
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhValidatePath = PdhValidatePathW
#ELSE
   MACRO PdhValidatePath = PdhValidatePathA
#ENDIF

' Retrieves the name of the default object. This name can be used to set
' the initial object selection in the Browse Counter dialog box.
' To use handles to data sources, use the PdhGetDefaultPerfObjectH function.
DECLARE FUNCTION PdhGetDefaultPerfObjectW IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfObjectW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR szMachineName
 , BYREF szDefaultObjectName AS WSTRINGZ _              ' __out LPWSTR szDefaultObjectName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetDefaultPerfObjectA IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfObjectA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR szDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR szMachineName
 , BYREF szDefaultObjectName AS ASCIIZ _                ' __out LPSTR szDefaultObjectName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetDefaultPerfObject = PdhGetDefaultPerfObjectW
#ELSE
   MACRO PdhGetDefaultPerfObject = PdhGetDefaultPerfObjectA
#ENDIF

' Retrieves the name of the default counter for the specified object. This name can be
' used to set the initial counter selection in the Browse Counter dialog box.
' This function is identical to PdhGetDefaultPerfCounter, except that it supports the use of handles to data sources.
DECLARE FUNCTION PdhGetDefaultPerfCounterW IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfCounterW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR szMachineName
 , BYREF szObjectName AS WSTRINGZ _                     ' __in  LPCWSTR szObjectName
 , BYREF szDefaultCounterName AS WSTRINGZ _             ' __out LPWSTR  szDefaultCounterName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetDefaultPerfCounterA IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfCounterA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR  szDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR  szMachineName
 , BYREF szObjectName AS ASCIIZ _                       ' __in  LPCSTR  szObjectName
 , BYREF szDefaultCounterName AS ASCIIZ _               ' __out LPSTR   szDefaultCounterName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetDefaultPerfCounter = PdhGetDefaultPerfCounterW
#ELSE
   MACRO PdhGetDefaultPerfCounter = PdhGetDefaultPerfCounterA
#ENDIF

'typedef PDH_STATUS (__stdcall * CounterPathCallBack)(DWORD_PTR);
'FUNCTION CounterPathCallBack (BYVAL dwArg AS DWORD) AS LONG
'END FUNCTION

' // Size = 40 bytes
TYPE PDH_BROWSE_DLG_CONFIG_HW DWORD
   bIncludeInstanceIndex    AS BIT * 1 IN DWORD
   bSingleCounterPerAdd     AS BIT * 1
   bSingleCounterPerDialog  AS BIT * 1
   bLocalCountersOnly       AS BIT * 1
   bWildCardInstances       AS BIT * 1
   bHideDetailBox           AS BIT * 1
   bInitializePath          AS BIT * 1
   bDisableMachineSelection AS BIT * 1
   bIncludeCostlyObjects    AS BIT * 1
   bShowObjectBrowser       AS BIT * 1
   bReserved                AS BIT * 22
   hWndOwner                AS DWORD          ' HWND
   hDataSource              AS DWORD          ' PDH_HLOG
   szReturnPathBuffer       AS WSTRINGZ PTR   ' LPWSTR
   cchReturnPathLength      AS DWORD          ' DWORD
   pCallBack                AS DWORD          ' CounterPathCallBack
   dwCallBackArg            AS DWORD          ' DWORD_PTR
   CallBackStatus           AS LONG           ' PDH_STATUS
   dwDefaultDetailLevel     AS DWORD          ' DWORD
   szDialogBoxCaption       AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 40 bytes
TYPE PDH_BROWSE_DLG_CONFIG_HA DWORD
   bIncludeInstanceIndex    AS BIT * 1 IN DWORD
   bSingleCounterPerAdd     AS BIT * 1
   bSingleCounterPerDialog  AS BIT * 1
   bLocalCountersOnly       AS BIT * 1
   bWildCardInstances       AS BIT * 1
   bHideDetailBox           AS BIT * 1
   bInitializePath          AS BIT * 1
   bDisableMachineSelection AS BIT * 1
   bIncludeCostlyObjects    AS BIT * 1
   bShowObjectBrowser       AS BIT * 1
   bReserved                AS BIT * 22
   hWndOwner                AS DWORD        ' HWND
   hDataSource              AS DWORD        ' PDH_HLOG
   szReturnPathBuffer       AS ASCIIZ PTR   ' LPSTR
   cchReturnPathLength      AS DWORD        ' DWORD
   pCallBack                AS DWORD        ' CounterPathCallBack
   dwCallBackArg            AS DWORD        ' DWORD_PTR
   CallBackStatus           AS LONG         ' PDH_STATUS
   dwDefaultDetailLevel     AS DWORD        ' DWORD
   szDialogBoxCaption       AS ASCIIZ PTR   ' LPSTR
END TYPE

MACRO PDH_BROWSE_DLG_CONFIG_H = PDH_BROWSE_DLG_CONFIG_HA

' // Size = 40 bytes
TYPE PDH_BROWSE_DLG_CONFIG_W DWORD
   bIncludeInstanceIndex    AS BIT * 1 IN DWORD
   bSingleCounterPerAdd     AS BIT * 1
   bSingleCounterPerDialog  AS BIT * 1
   bLocalCountersOnly       AS BIT * 1
   bWildCardInstances       AS BIT * 1
   bHideDetailBox           AS BIT * 1
   bInitializePath          AS BIT * 1
   bDisableMachineSelection AS BIT * 1
   bIncludeCostlyObjects    AS BIT * 1
   bShowObjectBrowser       AS BIT * 1
   bReserved                AS BIT * 22
   hWndOwner                AS DWORD          ' HWND
   szDataSource             AS WSTRINGZ PTR   ' LPWSTR
   szReturnPathBuffer       AS WSTRINGZ PTR   ' LPWSTR
   cchReturnPathLength      AS DWORD          ' DWORD
   pCallBack                AS DWORD          ' CounterPathCallBack
   dwCallBackArg            AS DWORD          ' DWORD_PTR
   CallBackStatus           AS LONG           ' PDH_STATUS
   dwDefaultDetailLevel     AS DWORD          ' DWORD
   szDialogBoxCaption       AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 40 bytes
TYPE PDH_BROWSE_DLG_CONFIG_A DWORD
   bIncludeInstanceIndex    AS BIT * 1 IN DWORD
   bSingleCounterPerAdd     AS BIT * 1
   bSingleCounterPerDialog  AS BIT * 1
   bLocalCountersOnly       AS BIT * 1
   bWildCardInstances       AS BIT * 1
   bHideDetailBox           AS BIT * 1
   bInitializePath          AS BIT * 1
   bDisableMachineSelection AS BIT * 1
   bIncludeCostlyObjects    AS BIT * 1
   bShowObjectBrowser       AS BIT * 1
   bReserved                AS BIT * 22
   hWndOwner                AS DWORD        ' HWND
   szDataSource             AS ASCIIZ PTR   ' LPSTR
   szReturnPathBuffer       AS ASCIIZ PTR   ' LPSTR
   cchReturnPathLength      AS DWORD        ' DWORD
   pCallBack                AS DWORD        ' CounterPathCallBack
   dwCallBackArg            AS DWORD        ' DWORD_PTR
   CallBackStatus           AS LONG         ' PDH_STATUS
   dwDefaultDetailLevel     AS DWORD        ' DWORD
   szDialogBoxCaption       AS ASCIIZ PTR   ' LPSTR
END TYPE

MACRO PDH_BROWSE_DLG_CONFIG = PDH_BROWSE_DLG_CONFIG_A

' Displays a Browse Counters dialog box that the user can use to select one
' or more counters that they want to add to the query.
' To use handles to data sources, use the PdhBrowseCountersH function.
DECLARE FUNCTION PdhBrowseCountersW IMPORT "PDH.DLL" ALIAS "PdhBrowseCountersW" ( _
   BYREF pBrowseDlgData AS PDH_BROWSE_DLG_CONFIG_W _    ' __in PPDH_BROWSE_DLG_CONFIG_W pBrowseDlgData
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhBrowseCountersA IMPORT "PDH.DLL" ALIAS "PdhBrowseCountersA" ( _
   BYREF pBrowseDlgData AS PDH_BROWSE_DLG_CONFIG_A _    ' __in PPDH_BROWSE_DLG_CONFIG_A pBrowseDlgData
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhBrowseCounters = PdhBrowseCountersW
#ELSE
   MACRO PdhBrowseCounters = PdhBrowseCountersA
#ENDIF

' Examines the specified computer (or local computer if none is specified) for
' counters and instances of counters that match the wildcard strings in the counter path.
' Note  This function is superseded by the PdhExpandWildCardPath function.
DECLARE FUNCTION PdhExpandCounterPathW IMPORT "PDH.DLL" ALIAS "PdhExpandCounterPathW" (_
   BYREF szWildCardPath AS WSTRINGZ _                   ' __in  LPCWSTR szWildCardPath
 , BYREF mszExpandedPathList AS WSTRINGZ _              ' __out LPWSTR  mszExpandedPathList
 , BYREF pcchPathListLength AS DWORD _                  ' __in_out LPDWORD pcchPathListLength
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhExpandCounterPathA IMPORT "PDH.DLL" ALIAS "PdhExpandCounterPathA" (_
   BYREF szWildCardPath AS ASCIIZ _                     ' __in  LPCSTR  szWildCardPath
 , BYREF mszExpandedPathList AS ASCIIZ _                ' __out LPSTR   mszExpandedPathList
 , BYREF pcchPathListLength AS DWORD _                  ' __in_out LPDWORD pcchPathListLength
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhExpandCounterPath = PdhExpandCounterPathW
#ELSE
   MACRO PdhExpandCounterPath = PdhExpandCounterPathA
#ENDIF

'//
'//  v2.0 functions
'//

' Returns the performance object name or counter name corresponding to the specified index.
DECLARE FUNCTION PdhLookupPerfNameByIndexW IMPORT "PDH.DLL" ALIAS "PdhLookupPerfNameByIndexW" (_
   BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR szMachineName
 , BYVAL dwNameIndex AS DWORD _                         ' __in  DWORD   dwNameIndex
 , BYREF szNameBuffer AS WSTRINGZ _                     ' __out LPWSTR  szNameBuffer
 , BYREF pcchNameBufferSize AS DWORD _                  ' __in_out LPDWORD pcchNameBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhLookupPerfNameByIndexA IMPORT "PDH.DLL" ALIAS "PdhLookupPerfNameByIndexA" (_
   BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR  szMachineName
 , BYVAL dwNameIndex AS DWORD _                         ' __in  DWORD   dwNameIndex
 , BYREF szNameBuffer AS ASCIIZ _                       ' __out LPSTR   szNameBuffer
 , BYREF pcchNameBufferSize AS DWORD _                  ' __in_out LPDWORD pcchNameBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhLookupPerfNameByIndex = PdhLookupPerfNameByIndexW
#ELSE
   MACRO PdhLookupPerfNameByIndex = PdhLookupPerfNameByIndexA
#ENDIF

' Returns the counter index corresponding to the specified counter name.
DECLARE FUNCTION PdhLookupPerfIndexByNameW IMPORT "PDH.DLL" ALIAS "PdhLookupPerfIndexByNameW" (_
   BYREF szMachineName AS WSTRINGZ _                    ' __in LPCWSTR szMachineName
 , BYREF szNameBuffer AS WSTRINGZ _                     ' __in LPCWSTR szNameBuffer
 , BYREF pdwIndex AS DWORD _                            ' __out LPDWORD pdwIndex
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhLookupPerfIndexByNameA IMPORT "PDH.DLL" ALIAS "PdhLookupPerfIndexByNameA" (_
   BYREF szMachineName AS ASCIIZ _                      ' __in LPCSTR  szMachineName
 , BYREF szNameBuffer AS ASCIIZ _                       ' __in LPCSTR  szNameBuffer
 , BYREF pdwIndex AS DWORD _                            ' __out LPDWORD pdwIndex
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhLookupPerfIndexByName = PdhLookupPerfIndexByNameW
#ELSE
   MACRO PdhLookupPerfIndexByName = PdhLookupPerfIndexByNameA
#ENDIF

%PDH_NOEXPANDCOUNTERS  = 1
%PDH_NOEXPANDINSTANCES = 2
'#if (_WIN32_WINDOWS >= 0x0502 || _WIN32_WINNT >= 0x0502 || (defined(NTDDI_VERSION) && NTDDI_VERSION >= NTDDI_WIN2003))
%PDH_REFRESHCOUNTERS   = 4
'#endif

' Examines the specified computer or log file and returns those counter paths
' that match the given counter path which contains wildcard characters.
' To use handles to data sources, use the PdhExpandWildCardPathH function.
DECLARE FUNCTION PdhExpandWildCardPathA IMPORT "PDH.DLL" ALIAS "PdhExpandWildCardPathA" (_
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR  szDataSource
 , BYREF szWildCardPath AS ASCIIZ _                     ' __in  LPCSTR  szWildCardPath
 , BYREF mszExpandedPathList AS ASCIIZ _                ' __out LPSTR   mszExpandedPathList
 , BYREF pcchPathListLength AS DWORD _                  ' __in_out LPDWORD pcchPathListLength
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhExpandWildCardPathW IMPORT "PDH.DLL" ALIAS "PdhExpandWildCardPathW" (_
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF szWildCardPath AS WSTRINGZ _                   ' __in  LPCWSTR szWildCardPath
 , BYREF mszExpandedPathList AS WSTRINGZ _              ' __out LPWSTR  mszExpandedPathList
 , BYREF pcchPathListLength AS DWORD _                  ' __in_out LPDWORD pcchPathListLength
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhExpandWildCardPath = PdhExpandWildCardPathW
#ELSE
   MACRO PdhExpandWildCardPath = PdhExpandWildCardPathA
#ENDIF

'//
'//   Logging Functions
'//

%PDH_LOG_READ_ACCESS        = &H00010000???
%PDH_LOG_WRITE_ACCESS       = &H00020000???
%PDH_LOG_UPDATE_ACCESS      = &H00040000???
%PDH_LOG_ACCESS_MASK        = &H000F0000???

%PDH_LOG_CREATE_NEW         = &H00000001???
%PDH_LOG_CREATE_ALWAYS      = &H00000002???
%PDH_LOG_OPEN_ALWAYS        = &H00000003???
%PDH_LOG_OPEN_EXISTING      = &H00000004???
%PDH_LOG_CREATE_MASK        = &H0000000F???

%PDH_LOG_OPT_USER_STRING    = &H01000000???
%PDH_LOG_OPT_CIRCULAR       = &H02000000???
%PDH_LOG_OPT_MAX_IS_BYTES   = &H04000000???
'#if (_WIN32_WINDOWS >= 0x0501 || _WIN32_WINNT >= 0x0501 || (defined(NTDDI_VERSION) && NTDDI_VERSION >= NTDDI_WINXP))
%PDH_LOG_OPT_APPEND         = &H08000000???
'#endif
%PDH_LOG_OPT_MASK           = &H0F000000???

%PDH_LOG_TYPE_UNDEFINED     = 0
%PDH_LOG_TYPE_CSV           = 1
%PDH_LOG_TYPE_TSV           = 2
%PDH_LOG_TYPE_TRACE_KERNEL  = 4
%PDH_LOG_TYPE_TRACE_GENERIC = 5
%PDH_LOG_TYPE_PERFMON       = 6
'%PDH_LOG_TYPE_BINARY        = 3 ' // this is the retired binary format
%PDH_LOG_TYPE_SQL           = 7
%PDH_LOG_TYPE_BINARY        = 8

' Opens the specified log file for reading or writing.
DECLARE FUNCTION PdhOpenLogW IMPORT "PDH.DLL" ALIAS "PdhOpenLogW" (_
   BYREF szLogFileName AS WSTRINGZ _                    ' __in  LPCWSTR     szLogFileName
 , BYVAL dwAccessFlags AS DWORD _                       ' __in  DWORD       dwAccessFlags
 , BYREF lpdwLogType AS DWORD _                         ' __in_out LPDWORD  lpdwLogType
 , BYVAL hQuery AS DWORD _                              ' __in  PDH_HQUERY  hQuery
 , BYVAL dwMaxSize AS DWORD _                           ' __in  DWORD       dwMaxSize
 , BYREF szUserCaption AS WSTRINGZ  _                   ' __in  LPCWSTR     szUserCaption
 , BYREF phLog AS DWORD _                               ' __out PDH_HLOG  * phLog
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhOpenLogA IMPORT "PDH.DLL" ALIAS "PdhOpenLogA" (_
   BYREF szLogFileName AS ASCIIZ _                      ' __in  LPCSTR      szLogFileName
 , BYVAL dwAccessFlags AS DWORD _                       ' __in  DWORD       dwAccessFlags
 , BYREF lpdwLogType AS DWORD _                         ' __in_out LPDWORD  lpdwLogType
 , BYVAL hQuery AS DWORD _                              ' __in  PDH_HQUERY  hQuery
 , BYVAL dwMaxSize AS DWORD _                           ' __in  DWORD       dwMaxSize
 , BYREF szUserCaption AS ASCIIZ _                      ' __in  LPCSTR      szUserCaption
 , BYREF phLog AS DWORD _                               ' __out PDH_HLOG  * phLog
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhOpenLog = PdhOpenLogW
#ELSE
   MACRO PdhOpenLog = PdhOpenLogA
#ENDIF

' Collects counter data for the current query and writes the data to the log file.
DECLARE FUNCTION PdhUpdateLogW IMPORT "PDH.DLL" ALIAS "PdhUpdateLogW" (_
   BYVAL hLog AS DWORD _                                ' __in PDH_HLOG hLog
 , BYREF szUserString AS WSTRINGZ _                     ' __in LPCWSTR  szUserString
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhUpdateLogA IMPORT "PDH.DLL" ALIAS "PdhUpdateLogA" (_
   BYVAL hLog AS DWORD _                                ' __in PDH_HLOG hLog
 , BYREF szUserString AS ASCIIZ _                       ' __in LPCSTR   szUserString
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhUpdateLog = PdhUpdateLogW
#ELSE
   MACRO PdhUpdateLog = PdhUpdateLogA
#ENDIF

' Synchronizes the information in the log file catalog with the performance data in the log file.
' Note  This function is obsolete.
DECLARE FUNCTION PdhUpdateLogFileCatalog IMPORT "PDH.DLL" ALIAS "PdhUpdateLogFileCatalog" (_
   BYVAL hLog AS DWORD _                                ' __in PDH_HLOG hLog
 ) AS LONG                                              ' PDH_STATUS

' Returns the size of the specified log file.
DECLARE FUNCTION PdhGetLogFileSize IMPORT "PDH.DLL" ALIAS "PdhGetLogFileSize" (_
   BYVAL hLog AS DWORD _                                ' __in  PDH_HLOG   hLog
 , BYREF llSize AS QUAD _                               ' __out LONGLONG * llSize
 ) AS LONG                                              ' PDH_STATUS

' Closes the specified log file.
DECLARE FUNCTION PdhCloseLog IMPORT "PDH.DLL" ALIAS "PdhCloseLog" (_
   BYVAL hLog AS DWORD _                                ' __in PDH_HLOG hLog
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD    dwFlags
 ) AS LONG                                              ' PDH_STATUS

%PDH_FLAGS_CLOSE_QUERY = &H00000001???

'//
'//  Data source selection dialog
'//

%PDH_FLAGS_FILE_BROWSER_ONLY = &H00000001???

' Displays a dialog window that prompts the user to specify the source of the performance data.
DECLARE FUNCTION PdhSelectDataSourceW IMPORT "PDH.DLL" ALIAS "PdhSelectDataSourceW" (_
   BYVAL hWndOwner AS DWORD _                           ' __in  HWND    hWndOwner
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 , BYREF szDataSource AS WSTRINGZ _                     ' __out LPWSTR  szDataSource
 , BYREF pcchBufferLength As DWORD _                    ' __in_out LPDWORD pcchBufferLength
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhSelectDataSourceA IMPORT "PDH.DLL" ALIAS "PdhSelectDataSourceA" (_
   BYVAL hWndOwner AS DWORD _                           ' __in  HWND    hWndOwner
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 , BYREF szDataSource AS ASCIIZ _                       ' __out LPSTR   szDataSource
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhSelectDataSource = PdhSelectDataSourceW
#ELSE
   MACRO PdhSelectDataSource = PdhSelectDataSourceA
#ENDIF

' Determines if the specified query is a real-time query.
DECLARE FUNCTION PdhIsRealTimeQuery IMPORT "PDH.DLL" ALIAS "PdhIsRealTimeQuery" (_
   BYVAL hQuery AS DWORD _                              ' __in PDH_HQUERY hQuery
 ) AS LONG                                              ' BOOL

' Limits the samples that you can read from a log file to those within the specified time range, inclusively.
DECLARE FUNCTION PdhSetQueryTimeRange IMPORT "PDH.DLL" ALIAS "PdhSetQueryTimeRange" (_
   BYVAL hQuery AS DWORD _                              ' __in PDH_HQUERY     hQuery
 , BYREF pInfo AS PDH_TIME_INFO _                       ' __in PPDH_TIME_INFO pInfo
 ) AS LONG                                              ' PDH_STATUS

' Determines the time range, number of entries and, if applicable, the size
' of the buffer containing the performance data from the specified input source.
' To use handles to data sources, use the PdhGetDataSourceTimeRangeH function.
DECLARE FUNCTION PdhGetDataSourceTimeRangeW IMPORT "PDH.DLL" ALIAS "PdhGetDataSourceTimeRangeW" (_
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR        szDataSource
 , BYREF pdwNumEntries AS DWORD _                       ' __out LPDWORD        pdwNumEntries
 , BYREF pInfo AS PDH_TIME_INFO _                       ' __out PPDH_TIME_INFO pInfo
 , BYVAL pdwBufferSize AS DWORD _                       ' __in  LPDWORD        pdwBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetDataSourceTimeRangeA IMPORT "PDH.DLL" ALIAS "PdhGetDataSourceTimeRangeA" (_
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR         szDataSource
 , BYREF pdwNumEntries AS DWORD _                       ' __out LPDWORD        pdwNumEntries
 , BYREF pInfo AS PDH_TIME_INFO _                       ' __out PPDH_TIME_INFO pInfo
 , BYVAL pdwBufferSize As DWORD _                       ' __in  LPDWORD        pdwBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetDataSourceTimeRange = PdhGetDataSourceTimeRangeW
#ELSE
   MACRO PdhGetDataSourceTimeRange = PdhGetDataSourceTimeRangeA
#ENDIF

' Uses a separate thread to collect the current raw data value for all counters in the specified query.
' The function then signals the application-defined event and waits the specified time interval before returning.
DECLARE FUNCTION PdhCollectQueryDataEx IMPORT "PDH.DLL" ALIAS "PdhCollectQueryDataEx" (_
   BYVAL hQuery AS DWORD _                              ' __in PDH_HQUERY hQuery
 , BYVAL dwIntervalTime AS DWORD _                      ' __in DWORD      dwIntervalTime
 , BYVAL hNewDataEvent AS DWORD _                       ' __in HANDLE     hNewDataEvent
 ) AS LONG                                              ' PDH_STATUS

' Computes a displayable value for the given raw counter values.
DECLARE FUNCTION PdhFormatFromRawValue IMPORT "PDH.DLL" ALIAS "PdhFormatFromRawValue" (_
   BYVAL dwCounterType AS DWORD _                       ' __in  DWORD                   dwCounterType
 , BYVAL dwFormat AS DWORD _                            ' __in  DWORD                   dwFormat
 , BYVAL pTimeBase AS QUAD _                            ' __in  LONGLONG              * pTimeBase
 , BYREF pRawValue1 AS PDH_RAW_COUNTER _                ' __in  PPDH_RAW_COUNTER        pRawValue1
 , BYREF pRawValue2 AS PDH_RAW_COUNTER _                ' __in  PPDH_RAW_COUNTER        pRawValue2
 , BYREF pFmtValue AS PDH_FMT_COUNTERVALUE _            ' __out PPDH_FMT_COUNTERVALUE   pFmtValue
 ) AS LONG                                              ' PDH_STATUS

' Returns the time base of the specified counter.
DECLARE FUNCTION PdhGetCounterTimeBase IMPORT "PDH.DLL" ALIAS "PdhGetCounterTimeBase" (_
   BYVAL hCounter AS DWORD _                            ' __in  PDH_HCOUNTER   hCounter
 , BYREF pTimeBase AS QUAD _                            ' __out LONGLONG     * pTimeBase
 ) AS LONG                                              ' PDH_STATUS

' Reads the information in the specified binary trace log file.
DECLARE FUNCTION PdhReadRawLogRecord IMPORT "PDH.DLL" ALIAS "PdhReadRawLogRecord" (_
   BYVAL hLog AS DWORD _                                ' __in  PDH_HLOG            hLog
 , BYVAL ftRecord AS FILETIME _                         ' __in  FILETIME            ftRecord
 , BYREF pRawLogRecord AS PDH_RAW_LOG_RECORD _          ' __out PPDH_RAW_LOG_RECORD pRawLogRecord
 , BYREF pdwBufferLength AS DWORD _                     ' __in_out LPDWORD          pdwBufferLength
 ) AS LONG                                              ' PDH_STATUS

%DATA_SOURCE_REGISTRY = &H00000001???
%DATA_SOURCE_LOGFILE  = &H00000002???
%DATA_SOURCE_WBEM     = &H00000004???

' Specifies the source of the real-time data.
DECLARE FUNCTION PdhSetDefaultRealTimeDataSource IMPORT "PDH.DLL" ALIAS "PdhSetDefaultRealTimeDataSource" (_
   BYVAL dwDataSourceId AS DWORD _                      ' __in DWORD dwDataSourceId
 ) AS LONG                                              ' PDH_STATUS

'#if (_WIN32_WINDOWS >= 0x0501 || _WIN32_WINNT >= 0x0501 || (defined(NTDDI_VERSION) && NTDDI_VERSION >= NTDDI_WINXP))
'// Extended API for WMI event trace logfile format
'//

' Binds one or more binary log files together for reading log data.
DECLARE FUNCTION PdhBindInputDataSourceW IMPORT "PDH.DLL" ALIAS "PdhBindInputDataSourceW" (_
   BYREF phDataSource AS DWORD _                        ' __out PDH_HLOG * phDataSource
 , BYREF LogFileNameList AS WSTRINGZ _                  ' __in  LPCWSTR    LogFileNameList
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhBindInputDataSourceA IMPORT "PDH.DLL" ALIAS "PdhBindInputDataSourceA" (_
   BYREF phDataSource AS DWORD _                        ' __out PDH_HLOG * phDataSource
 , BYREF LogFileNameList AS ASCIIZ _                    ' __in  LPCSTR     LogFileNameList
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhBindInputDataSource = PdhBindInputDataSourceW
#ELSE
   MACRO PdhBindInputDataSource = PdhBindInputDataSourceA
#ENDIF

' Creates a new query that is used to manage the collection of performance data.
' This function is identical to the PdhOpenQuery function, except that it supports
' the use of handles to data sources.
DECLARE FUNCTION PdhOpenQueryH IMPORT "PDH.DLL" ALIAS "PdhOpenQueryH" (_
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG     hDataSource
 , BYVAL dwUserData AS DWORD _                          ' __in  DWORD_PTR    dwUserData
 , BYREF phQuery AS DWORD _                             ' __out PDH_HQUERY * phQuery
 ) AS LONG                                              ' PDH_STATUS

' Returns a list of the computer names associated with counters in a log file.
' The computer names were either specified when adding counters to the query or when
' calling the PdhConnectMachine function. The computers listed include those that
' are currently connected and online, in addition to those that are offline or
' not returning performance data.
' This function is identical to the PdhEnumMachines function, except that it supports
' the use of handles to data sources.
DECLARE FUNCTION PdhEnumMachinesHW IMPORT "PDH.DLL" ALIAS "PdhEnumMachinesHW" (_
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF mszMachineList AS WSTRINGZ _                   ' __out LPWSTR   mszMachineList
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumMachinesHA IMPORT "PDH.DLL" ALIAS "PdhEnumMachinesHA" (_
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF mszMachineList AS ASCIIZ _                     ' __out LPSTR    mszMachineList
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumMachinesH = PdhEnumMachinesHW
#ELSE
   MACRO PdhEnumMachinesH = PdhEnumMachinesHA
#ENDIF

' Returns a list of objects available on the specified computer or in the specified log file.
' This function is identical to PdhEnumObjects, except that it supports the use of handles to data sources.
DECLARE FUNCTION PdhEnumObjectsHW IMPORT "PDH.DLL" ALIAS "PdhEnumObjectsHW" (_
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR  szMachineName
 , BYREF mszObjectList AS WSTRINGZ _                    ' __out LPWSTR   mszObjectList
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD    dwDetailLevel
 , BYVAL bRefresh AS LONG _                             ' __in  BOOL     bRefresh
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumObjectsHA IMPORT "PDH.DLL" ALIAS "PdhEnumObjectsHA" (_
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR   szMachineName
 , BYREF mszObjectList AS ASCIIZ _                      ' __out LPSTR    mszObjectList
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD    dwDetailLevel
 , BYVAL bRefresh AS LONG _                             ' __in  BOOL     bRefresh
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumObjectsH = PdhEnumObjectsHW
#ELSE
   MACRO PdhEnumObjectsH = PdhEnumObjectsHA
#ENDIF

' Returns the specified object's counter and instance names that exist on the
' specified computer or in the specified log file.
' This function is identical to the PdhEnumObjectItems function, except that
' it supports the use of handles to data sources.
DECLARE FUNCTION PdhEnumObjectItemsHW IMPORT "PDH.DLL" ALIAS "PdhEnumObjectItemsHW" ( _
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR  szMachineName
 , BYREF szObjectName AS WSTRINGZ _                     ' __in  LPCWSTR  szObjectName
 , BYREF mszCounterList AS WSTRINGZ _                   ' __out LPWSTR   mszCounterList
 , BYREF pcchCounterListLength AS DWORD _               ' __in_out LPDWORD  pcchCounterListLength
 , BYREF mszInstanceList AS WSTRINGZ _                  ' __out LPWSTR   mszInstanceList
 , BYREF pcchInstanceListLength AS DWORD _              ' __in_out LPDWORD  pcchInstanceListLength
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  DWORD    dwDetailLevel
 , BYVAL dwFlags AS LONG _                              ' __in  DWORD    dwFlags
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumObjectItemsHA IMPORT "PDH.DLL" ALIAS "PdhEnumObjectItemsHA" ( _
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR   szMachineName
 , BYREF szObjectName AS ASCIIZ _                       ' __in  LPCSTR   szObjectName
 , BYVAL mszCounterList AS DWORD _                      ' __out LPSTR    mszCounterList
 , BYREF pcchCounterListLength AS DWORD _               ' __in_out pcchCounterListLength
 , BYVAL mszInstanceList AS DWORD _                     ' __out mszInstanceList
 , BYREF pcchInstanceListLength AS DWORD _              ' __in_out pcchInstanceListLength
 , BYVAL dwDetailLevel AS DWORD _                       ' __in  dwDetailLevel
 , BYVAL dwFlags AS LONG _                              ' __in  dwFlags
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumObjectItemsH = PdhEnumObjectItemsHW
#ELSE
   MACRO PdhEnumObjectItemsH = PdhEnumObjectItemsHA
#ENDIF

' Examines the specified computer or log file and returns those counter paths that
' match the given counter path which contains wildcard characters.
' This function is identical to the PdhExpandWildCardPath function, except that
' it supports the use of handles to data sources.
DECLARE FUNCTION PdhExpandWildCardPathHW IMPORT "PDH.DLL" ALIAS "PdhExpandWildCardPathHW" (_
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szWildCardPath AS WSTRINGZ _                   ' __in  LPCWSTR  szWildCardPath
 , BYREF mszExpandedPathList AS WSTRINGZ _              ' __out LPWSTR   mszExpandedPathList
 , BYREF pcchPathListLength AS DWORD _                  ' __in_out LPDWORD  pcchPathListLength
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhExpandWildCardPathHA IMPORT "PDH.DLL" ALIAS "PdhExpandWildCardPathHA" (_
   BYREF hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szWildCardPath AS ASCIIZ _                     ' __in  LPCSTR   szWildCardPath
 , BYREF mszExpandedPathList AS ASCIIZ _                ' __out LPSTR    mszExpandedPathList
 , BYREF pcchPathListLength AS DWORD _                  ' __in_out LPDWORD  pcchPathListLength
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhExpandWildCardPathH = PdhExpandWildCardPathHW
#ELSE
   MACRO PdhExpandWildCardPathH = PdhExpandWildCardPathHA
#ENDIF

' Determines the time range, number of entries and, if applicable, the size of the
' buffer containing the performance data from the specified input source.
' This function is identical to the PdhGetDataSourceTimeRange function, except that
' it supports the use of handles to data sources.
DECLARE FUNCTION PdhGetDataSourceTimeRangeH IMPORT "PDH.DLL" ALIAS "PdhGetDataSourceTimeRangeH" (_
   BYREF hDataSource AS DWORD _                         ' __in  PDH_HLOG       hDataSource
 , BYREF pdwNumEntries AS DWORD _                       ' __out LPDWORD        pdwNumEntries
 , BYREF pInfo AS PDH_TIME_INFO _                       ' __out PPDH_TIME_INFO pInfo
 , BYVAL pdwBufferSize AS DWORD _                       ' __in  LPDWORD        pdwBufferSize
 ) AS LONG                                              ' PDH_STATUS

' Retrieves the name of the default object. This name can be used to set the initial
' object selection in the Browse Counter dialog box.
' To use handles to data sources, use the PdhGetDefaultPerfObjectH function.
DECLARE FUNCTION PdhGetDefaultPerfObjectHW IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfObjectHW" ( _
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR  szMachineName
 , BYREF szDefaultObjectName AS WSTRINGZ _              ' __out LPWSTR   szDefaultObjectName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetDefaultPerfObjectHA IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfObjectHA" ( _
   BYREF hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR   szMachineName
 , BYREF szDefaultObjectName AS ASCIIZ _                ' __out LPSTR    szDefaultObjectName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetDefaultPerfObjectH = PdhGetDefaultPerfObjectHW
#ELSE
   MACRO PdhGetDefaultPerfObjectH = PdhGetDefaultPerfObjectHA
#ENDIF

' Retrieves the name of the default counter for the specified object. This name
' can be used to set the initial counter selection in the Browse Counter dialog box.
' To use handles to data sources, use the PdhGetDefaultPerfCounterH function.
DECLARE FUNCTION PdhGetDefaultPerfCounterHW IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfCounterHW" ( _
   BYVAL hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS WSTRINGZ _                    ' __in  LPCWSTR  szMachineName
 , BYREF szObjectName AS WSTRINGZ _                     ' __in  LPCWSTR  szObjectName
 , BYREF szDefaultCounterName AS WSTRINGZ _             ' __out LPWSTR   szDefaultCounterName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhGetDefaultPerfCounterHA IMPORT "PDH.DLL" ALIAS "PdhGetDefaultPerfCounterHA" ( _
   BYREF hDataSource AS DWORD _                         ' __in  PDH_HLOG hDataSource
 , BYREF szMachineName AS ASCIIZ _                      ' __in  LPCSTR   szMachineName
 , BYREF szObjectName AS ASCIIZ _                       ' __in  LPCSTR   szObjectName
 , BYREF szDefaultCounterName AS ASCIIZ _               ' __out LPSTR    szDefaultCounterName
 , BYREF pcchBufferSize AS DWORD _                      ' __in_out LPDWORD  pcchBufferSize
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhGetDefaultPerfCounterH = PdhGetDefaultPerfCounterHW
#ELSE
   MACRO PdhGetDefaultPerfCounterH = PdhGetDefaultPerfCounterHA
#ENDIF

' Displays a Browse Counters dialog box that the user can use to select one
' or more counters that they want to add to the query.
' This function is identical to the PdhBrowseCounters function, except that it supports the use of handles to data sources.
DECLARE FUNCTION PdhBrowseCountersHW IMPORT "PDH.DLL" ALIAS "PdhBrowseCountersHW" ( _
   BYREF pBrowseDlgData AS PDH_BROWSE_DLG_CONFIG_HW _   ' __in PPDH_BROWSE_DLG_CONFIG_HW pBrowseDlgData
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhBrowseCountersHA IMPORT "PDH.DLL" ALIAS "PdhBrowseCountersHA" ( _
   BYREF pBrowseDlgData AS PDH_BROWSE_DLG_CONFIG_HA _   ' __in PPDH_BROWSE_DLG_CONFIG_HA pBrowseDlgData
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhBrowseCountersH = PdhBrowseCountersHW
#ELSE
   MACRO PdhBrowseCountersH = PdhBrowseCountersHA
#ENDIF

'//Check that a DSN points to a database that contains the correct Perfmon tables.

DECLARE FUNCTION PdhVerifySQLDBW IMPORT "PDH.DLL" ALIAS "PdhVerifySQLDBW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in LPCWSTR szDataSource
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhVerifySQLDBA IMPORT "PDH.DLL" ALIAS "PdhVerifySQLDBA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in LPCSTR szDataSource
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhVerifySQLDB = PdhVerifySQLDBW
#ELSE
   MACRO PdhVerifySQLDB = PdhVerifySQLDBA
#ENDIF

'//Create the correct perfmon tables in the database pointed to by a DSN.

DECLARE FUNCTION PdhCreateSQLTablesW IMPORT "PDH.DLL" ALIAS "PdhCreateSQLTablesW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in LPCWSTR szDataSource
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhCreateSQLTablesA IMPORT "PDH.DLL" ALIAS "PdhCreateSQLTablesA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in LPCSTR szDataSource
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhCreateSQLTables = PdhCreateSQLTablesW
#ELSE
   MACRO PdhCreateSQLTables = PdhCreateSQLTablesA
#ENDIF

'//Return the list of Log set names in the database pointed to by the DSN.

DECLARE FUNCTION PdhEnumLogSetNamesW IMPORT "PDH.DLL" ALIAS "PdhEnumLogSetNamesW" ( _
   BYREF szDataSource AS WSTRINGZ _                     ' __in  LPCWSTR szDataSource
 , BYREF mszDataSetNameList AS WSTRINGZ _               ' __out LPWSTR  mszDataSetNameList
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 ) AS LONG                                              ' PDH_STATUS

DECLARE FUNCTION PdhEnumLogSetNamesA IMPORT "PDH.DLL" ALIAS "PdhEnumLogSetNamesA" ( _
   BYREF szDataSource AS ASCIIZ _                       ' __in  LPCSTR  szDataSource
 , BYREF mszDataSetNameList AS ASCIIZ _                 ' __out LPSTR   mszDataSetNameList
 , BYREF pcchBufferLength AS DWORD _                    ' __in_out LPDWORD pcchBufferLength
 ) AS LONG                                              ' PDH_STATUS

#IF %DEF(%UNICODE)
   MACRO PdhEnumLogSetNames = PdhEnumLogSetNamesW
#ELSE
   MACRO PdhEnumLogSetNames = PdhEnumLogSetNamesA
#ENDIF

'//Retrieve the GUID for an open Log Set

DECLARE FUNCTION PdhGetLogSetGUID IMPORT "PDH.DLL" ALIAS "PdhGetLogSetGUID" ( _
   BYVAL hLog AS DWORD _                                ' __in  PDH_HLOG   hLog
 , BYREF pGuid AS GUID _                                ' __out GUID     * pGuid
 , BYVAL pRunId AS LONG _                               ' __in  int      * pRunId
 ) AS LONG                                              ' PDH_STATUS

'//Set the RunID for an open Log Set

DECLARE FUNCTION PdhSetLogSetRunID IMPORT "PDH.DLL" ALIAS "PdhSetLogSetRunID" ( _
   BYVAL hLog AS DWORD _                                ' __in PDH_HLOG hLog
 , BYVAL RunId AS LONG _                                ' __in int      RunId
 ) AS LONG                                              ' PDH_STATUS

'#endif
