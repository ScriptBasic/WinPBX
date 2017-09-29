' ########################################################################################
' Microsoft Windows
' File: PdhMsg.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PDHMSG_INC = 1

$S_PDH = GUID$("{04D66358-C4A1-419B-8023-23B73902DE2C}")
%S_PDH_CHANNEL_Application = &H9
%MSG_Publisher_Name        = &H90000001&

'//
'//     PDH DLL messages
'//
'//
'//      Success Messages
'//
'//         the Win32 error value ERROR_SUCCESS is used for success returns
'//
'//      MESSAGE NAME FORMAT
'//
'//          PDH_CSTATUS_...   messages are data item status message and
'//                     are returned in reference to the status of a data
'//                     item
'//          PDH_...           messages are returned by FUNCTIONS only and
'//                     not used as data item status values
'//
'//      Success Messages
'//         These messages are normally returned when the operation completed
'//         successfully.
'//
'//
'//  Values are 32 bit values layed out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//


'//
'// Define the severity codes
'//

%STATUS_SEVERITY_WARNING          = &H2
%STATUS_SEVERITY_SUCCESS          = &H0
%STATUS_SEVERITY_INFORMATIONAL    = &H1
%STATUS_SEVERITY_ERROR            = &H3


'//
'// MessageId: PDH_CSTATUS_VALID_DATA
'//
'// MessageText:
'//
'//  The returned data is valid.
'//

%PDH_CSTATUS_VALID_DATA           = &H00000000&

'//
'// MessageId: PDH_CSTATUS_NEW_DATA
'//
'// MessageText:
'//
'//  The return data value is valid and different from the last sample.
'//

%PDH_CSTATUS_NEW_DATA             = &H00000001&

'//
'//        Informational messages
'//
'//  None
'//
'//      Warning Messages
'//         These messages are returned when the function has completed
'//         successfully but the results may be different than expected.
'//
'//
'// MessageId: PDH_CSTATUS_NO_MACHINE
'//
'// MessageText:
'//
'//  Unable to connect to specified machine or machine is off line.
'//

%PDH_CSTATUS_NO_MACHINE           = &H800007D0&

'//
'// MessageId: PDH_CSTATUS_NO_INSTANCE
'//
'// MessageText:
'//
'//  The specified instance is not present.
'//

%PDH_CSTATUS_NO_INSTANCE          = &H800007D1&

'//
'// MessageId: PDH_MORE_DATA
'//
'// MessageText:
'//
'//  There is more data to return than would fit in the supplied buffer. Allocate
'//  a larger buffer and call the function again.
'//

%PDH_MORE_DATA                    = &H800007D2&

'//
'// MessageId: PDH_CSTATUS_ITEM_NOT_VALIDATED
'//
'// MessageText:
'//
'//  The data item has been added to the query, but has not been validated nor
'//  accessed. No other status information on this data item is available.
'//

%PDH_CSTATUS_ITEM_NOT_VALIDATED   = &H800007D3&

'//
'// MessageId: PDH_RETRY
'//
'// MessageText:
'//
'//  The selected operation should be retried.
'//

%PDH_RETRY                        = &H800007D4&

'//
'// MessageId: PDH_NO_DATA
'//
'// MessageText:
'//
'//  No data to return.
'//

%PDH_NO_DATA                      = &H800007D5&

'//
'// MessageId: PDH_CALC_NEGATIVE_DENOMINATOR
'//
'// MessageText:
'//
'//  A counter with a negative denominator value was detected.
'//

%PDH_CALC_NEGATIVE_DENOMINATOR    = &H800007D6&

'//
'// MessageId: PDH_CALC_NEGATIVE_TIMEBASE
'//
'// MessageText:
'//
'//  A counter with a negative timebase value was detected.
'//

%PDH_CALC_NEGATIVE_TIMEBASE       = &H800007D7&

'//
'// MessageId: PDH_CALC_NEGATIVE_VALUE
'//
'// MessageText:
'//
'//  A counter with a negative value was detected.
'//

%PDH_CALC_NEGATIVE_VALUE          = &H800007D8&

'//
'// MessageId: PDH_DIALOG_CANCELLED
'//
'// MessageText:
'//
'//  The user cancelled the dialog box.
'//

%PDH_DIALOG_CANCELLED             = &H800007D9&

'//
'// MessageId: PDH_END_OF_LOG_FILE
'//
'// MessageText:
'//
'//  The end of the log file was reached.
'//

%PDH_END_OF_LOG_FILE              = &H800007DA&

'//
'// MessageId: PDH_ASYNC_QUERY_TIMEOUT
'//
'// MessageText:
'//
'//  Time out while waiting for asynchronous counter collection thread to end.
'//

%PDH_ASYNC_QUERY_TIMEOUT          = &H800007DB&

'//
'// MessageId: PDH_CANNOT_SET_DEFAULT_REALTIME_DATASOURCE
'//
'// MessageText:
'//
'//  Cannot change default real-time data source. There are real-time query
'//  sessions collecting counter data.
'//

%PDH_CANNOT_SET_DEFAULT_REALTIME_DATASOURCE = &H800007DC&

'//
'//     Error Messages
'//        These messages are returned when the function could not complete
'//        as requested and some corrective action may be required by the
'//        the caller or the user.
'//
'//
'// MessageId: PDH_CSTATUS_NO_OBJECT
'//
'// MessageText:
'//
'//  The specified object is not found on the system.
'//

%PDH_CSTATUS_NO_OBJECT            = &HC0000BB8&

'//
'// MessageId: PDH_CSTATUS_NO_COUNTER
'//
'// MessageText:
'//
'//  The specified counter could not be found.
'//

%PDH_CSTATUS_NO_COUNTER           = &HC0000BB9&

'//
'// MessageId: PDH_CSTATUS_INVALID_DATA
'//
'// MessageText:
'//
'//  The returned data is not valid.
'//

%PDH_CSTATUS_INVALID_DATA         = &HC0000BBA&

'//
'// MessageId: PDH_MEMORY_ALLOCATION_FAILURE
'//
'// MessageText:
'//
'//  A PDH function could not allocate enough temporary memory to complete the
'//  operation. Close some applications or extend the pagefile and retry the
'//  function.
'//

%PDH_MEMORY_ALLOCATION_FAILURE    = &HC0000BBB&

'//
'// MessageId: PDH_INVALID_HANDLE
'//
'// MessageText:
'//
'//  The handle is not a valid PDH object.
'//

%PDH_INVALID_HANDLE               = &HC0000BBC&

'//
'// MessageId: PDH_INVALID_ARGUMENT
'//
'// MessageText:
'//
'//  A required argument is missing or incorrect.
'//

%PDH_INVALID_ARGUMENT             = &HC0000BBD&

'//
'// MessageId: PDH_FUNCTION_NOT_FOUND
'//
'// MessageText:
'//
'//  Unable to find the specified function.
'//

%PDH_FUNCTION_NOT_FOUND           = &HC0000BBE&

'//
'// MessageId: PDH_CSTATUS_NO_COUNTERNAME
'//
'// MessageText:
'//
'//  No counter was specified.
'//

%PDH_CSTATUS_NO_COUNTERNAME       = &HC0000BBF&

'//
'// MessageId: PDH_CSTATUS_BAD_COUNTERNAME
'//
'// MessageText:
'//
'//  Unable to parse the counter path. Check the format and syntax of the
'//  specified path.
'//

%PDH_CSTATUS_BAD_COUNTERNAME      = &HC0000BC0&

'//
'// MessageId: PDH_INVALID_BUFFER
'//
'// MessageText:
'//
'//  The buffer passed by the caller is invalid.
'//

%PDH_INVALID_BUFFER               = &HC0000BC1&

'//
'// MessageId: PDH_INSUFFICIENT_BUFFER
'//
'// MessageText:
'//
'//  The requested data is larger than the buffer supplied. Unable to return the
'//  requested data.
'//

%PDH_INSUFFICIENT_BUFFER          = &HC0000BC2&

'//
'// MessageId: PDH_CANNOT_CONNECT_MACHINE
'//
'// MessageText:
'//
'//  Unable to connect to the requested machine.
'//

%PDH_CANNOT_CONNECT_MACHINE       = &HC0000BC3&

'//
'// MessageId: PDH_INVALID_PATH
'//
'// MessageText:
'//
'//  The specified counter path could not be interpreted.
'//

%PDH_INVALID_PATH                 = &HC0000BC4&

'//
'// MessageId: PDH_INVALID_INSTANCE
'//
'// MessageText:
'//
'//  The instance name could not be read from the specified counter path.
'//

%PDH_INVALID_INSTANCE             = &HC0000BC5&

'//
'// MessageId: PDH_INVALID_DATA
'//
'// MessageText:
'//
'//  The data is not valid.
'//

%PDH_INVALID_DATA                 = &HC0000BC6&

'//
'// MessageId: PDH_NO_DIALOG_DATA
'//
'// MessageText:
'//
'//  The dialog box data block was missing or invalid.
'//

%PDH_NO_DIALOG_DATA               = &HC0000BC7&

'//
'// MessageId: PDH_CANNOT_READ_NAME_STRINGS
'//
'// MessageText:
'//
'//  Unable to read the counter and/or explain text from the specified machine.
'//

%PDH_CANNOT_READ_NAME_STRINGS     = &HC0000BC8&

'//
'// MessageId: PDH_LOG_FILE_CREATE_ERROR
'//
'// MessageText:
'//
'//  Unable to create the specified log file.
'//

%PDH_LOG_FILE_CREATE_ERROR        = &HC0000BC9&

'//
'// MessageId: PDH_LOG_FILE_OPEN_ERROR
'//
'// MessageText:
'//
'//  Unable to open the specified log file.
'//

%PDH_LOG_FILE_OPEN_ERROR          = &HC0000BCA&

'//
'// MessageId: PDH_LOG_TYPE_NOT_FOUND
'//
'// MessageText:
'//
'//  The specified log file type has not been installed on this system.
'//

%PDH_LOG_TYPE_NOT_FOUND           = &HC0000BCB&

'//
'// MessageId: PDH_NO_MORE_DATA
'//
'// MessageText:
'//
'//  No more data is available.
'//

%PDH_NO_MORE_DATA                 = &HC0000BCC&

'//
'// MessageId: PDH_ENTRY_NOT_IN_LOG_FILE
'//
'// MessageText:
'//
'//  The specified record was not found in the log file.
'//

%PDH_ENTRY_NOT_IN_LOG_FILE        = &HC0000BCD&

'//
'// MessageId: PDH_DATA_SOURCE_IS_LOG_FILE
'//
'// MessageText:
'//
'//  The specified data source is a log file.
'//

%PDH_DATA_SOURCE_IS_LOG_FILE      = &HC0000BCE&

'//
'// MessageId: PDH_DATA_SOURCE_IS_REAL_TIME
'//
'// MessageText:
'//
'//  The specified data source is the current activity.
'//

%PDH_DATA_SOURCE_IS_REAL_TIME     = &HC0000BCF&

'//
'// MessageId: PDH_UNABLE_READ_LOG_HEADER
'//
'// MessageText:
'//
'//  The log file header could not be read.
'//

%PDH_UNABLE_READ_LOG_HEADER       = &HC0000BD0&

'//
'// MessageId: PDH_FILE_NOT_FOUND
'//
'// MessageText:
'//
'//  Unable to find the specified file.
'//

%PDH_FILE_NOT_FOUND               = &HC0000BD1&

'//
'// MessageId: PDH_FILE_ALREADY_EXISTS
'//
'// MessageText:
'//
'//  There is already a file with the specified file name.
'//

%PDH_FILE_ALREADY_EXISTS          = &HC0000BD2&

'//
'// MessageId: PDH_NOT_IMPLEMENTED
'//
'// MessageText:
'//
'//  The function referenced has not been implemented.
'//

%PDH_NOT_IMPLEMENTED              = &HC0000BD3&

'//
'// MessageId: PDH_STRING_NOT_FOUND
'//
'// MessageText:
'//
'//  Unable to find the specified string in the list of performance name and
'//  explain text strings.
'//

%PDH_STRING_NOT_FOUND             = &HC0000BD4&

'//
'// MessageId: PDH_UNABLE_MAP_NAME_FILES
'//
'// MessageText:
'//
'//  Unable to map to the performance counter name data files. The data
'//  will be read from the registry and stored locally.
'//

%PDH_UNABLE_MAP_NAME_FILES        = &H80000BD5&

'//
'// MessageId: PDH_UNKNOWN_LOG_FORMAT
'//
'// MessageText:
'//
'//  The format of the specified log file is not recognized by the PDH DLL.
'//

%PDH_UNKNOWN_LOG_FORMAT           = &HC0000BD6&

'//
'// MessageId: PDH_UNKNOWN_LOGSVC_COMMAND
'//
'// MessageText:
'//
'//  The specified Log Service command value is not recognized.
'//

%PDH_UNKNOWN_LOGSVC_COMMAND       = &HC0000BD7&

'//
'// MessageId: PDH_LOGSVC_QUERY_NOT_FOUND
'//
'// MessageText:
'//
'//  The specified Query from the Log Service could not be found or could not
'//  be opened.
'//

%PDH_LOGSVC_QUERY_NOT_FOUND       = &HC0000BD8&

'//
'// MessageId: PDH_LOGSVC_NOT_OPENED
'//
'// MessageText:
'//
'//  The Performance Data Log Service key could not be opened. This may be due
'//  to insufficient privilege or because the service has not been installed.
'//

%PDH_LOGSVC_NOT_OPENED            = &HC0000BD9&

'//
'// MessageId: PDH_WBEM_ERROR
'//
'// MessageText:
'//
'//  An error occurred while accessing the WBEM data store.
'//

%PDH_WBEM_ERROR                   = &HC0000BDA&

'//
'// MessageId: PDH_ACCESS_DENIED
'//
'// MessageText:
'//
'//  Unable to access the desired machine or service. Check the permissions and
'//  authentication of the log service or the interactive user session against
'//  those on the machine or service being monitored.
'//

%PDH_ACCESS_DENIED                = &HC0000BDB&

'//
'// MessageId: PDH_LOG_FILE_TOO_SMALL
'//
'// MessageText:
'//
'//  The maximum log file size specified is too small to log the selected counters.
'//  No data will be recorded in this log file. Specify a smaller set of counters
'//  to log or a larger file size and retry this call.
'//

%PDH_LOG_FILE_TOO_SMALL           = &HC0000BDC&

'//
'// MessageId: PDH_INVALID_DATASOURCE
'//
'// MessageText:
'//
'//  Cannot connect to ODBC DataSource Name.
'//

%PDH_INVALID_DATASOURCE           = &HC0000BDD&

'//
'// MessageId: PDH_INVALID_SQLDB
'//
'// MessageText:
'//
'//  SQL Database does not contain a valid set of tables for Perfmon, use PdhCreateSQLTables.
'//

%PDH_INVALID_SQLDB                = &HC0000BDE&

'//
'// MessageId: PDH_NO_COUNTERS
'//
'// MessageText:
'//
'//  No counters were found for this Perfmon SQL Log Set.
'//

%PDH_NO_COUNTERS                  = &HC0000BDF&

'//
'// MessageId: PDH_SQL_ALLOC_FAILED
'//
'// MessageText:
'//
'//  Call to SQLAllocStmt failed with %1.
'//

%PDH_SQL_ALLOC_FAILED             = &HC0000BE0&

'//
'// MessageId: PDH_SQL_ALLOCCON_FAILED
'//
'// MessageText:
'//
'//  Call to SQLAllocConnect failed with %1.
'//

%PDH_SQL_ALLOCCON_FAILED          = &HC0000BE1&

'//
'// MessageId: PDH_SQL_EXEC_DIRECT_FAILED
'//
'// MessageText:
'//
'//  Call to SQLExecDirect failed with %1.
'//

%PDH_SQL_EXEC_DIRECT_FAILED       = &HC0000BE2&

'//
'// MessageId: PDH_SQL_FETCH_FAILED
'//
'// MessageText:
'//
'//  Call to SQLFetch failed with %1.
'//

%PDH_SQL_FETCH_FAILED             = &HC0000BE3&

'//
'// MessageId: PDH_SQL_ROWCOUNT_FAILED
'//
'// MessageText:
'//
'//  Call to SQLRowCount failed with %1.
'//

%PDH_SQL_ROWCOUNT_FAILED          = &HC0000BE4&

'//
'// MessageId: PDH_SQL_MORE_RESULTS_FAILED
'//
'// MessageText:
'//
'//  Call to SQLMoreResults failed with %1.
'//

%PDH_SQL_MORE_RESULTS_FAILED      = &HC0000BE5&

'//
'// MessageId: PDH_SQL_CONNECT_FAILED
'//
'// MessageText:
'//
'//  Call to SQLConnect failed with %1.
'//

%PDH_SQL_CONNECT_FAILED           = &HC0000BE6&

'//
'// MessageId: PDH_SQL_BIND_FAILED
'//
'// MessageText:
'//
'//  Call to SQLBindCol failed with %1.
'//

%PDH_SQL_BIND_FAILED              = &HC0000BE7&

'//
'// MessageId: PDH_CANNOT_CONNECT_WMI_SERVER
'//
'// MessageText:
'//
'//  Unable to connect to the WMI server on requested machine.
'//

%PDH_CANNOT_CONNECT_WMI_SERVER    = &HC0000BE8&

'//
'// MessageId: PDH_PLA_COLLECTION_ALREADY_RUNNING
'//
'// MessageText:
'//
'//  Collection "%1!s!" is already running.
'//

%PDH_PLA_COLLECTION_ALREADY_RUNNING = &HC0000BE9&

'//
'// MessageId: PDH_PLA_ERROR_SCHEDULE_OVERLAP
'//
'// MessageText:
'//
'//  The specified start time is after the end time.
'//

%PDH_PLA_ERROR_SCHEDULE_OVERLAP   = &HC0000BEA&

'//
'// MessageId: PDH_PLA_COLLECTION_NOT_FOUND
'//
'// MessageText:
'//
'//  Collection "%1!s!" does not exist.
'//

%PDH_PLA_COLLECTION_NOT_FOUND     = &HC0000BEB&

'//
'// MessageId: PDH_PLA_ERROR_SCHEDULE_ELAPSED
'//
'// MessageText:
'//
'//  The specified end time has already elapsed.
'//

%PDH_PLA_ERROR_SCHEDULE_ELAPSED   = &HC0000BEC&

'//
'// MessageId: PDH_PLA_ERROR_NOSTART
'//
'// MessageText:
'//
'//  Collection "%1!s!" did not start, check the application event log for any errors.
'//

%PDH_PLA_ERROR_NOSTART            = &HC0000BED&

'//
'// MessageId: PDH_PLA_ERROR_ALREADY_EXISTS
'//
'// MessageText:
'//
'//  Collection "%1!s!" already exists.
'//

%PDH_PLA_ERROR_ALREADY_EXISTS     = &HC0000BEE&

'//
'// MessageId: PDH_PLA_ERROR_TYPE_MISMATCH
'//
'// MessageText:
'//
'//  There is a mismatch in the settings type.
'//

%PDH_PLA_ERROR_TYPE_MISMATCH      = &HC0000BEF&

'//
'// MessageId: PDH_PLA_ERROR_FILEPATH
'//
'// MessageText:
'//
'//  The information specified does not resolve to a valid path name.
'//

%PDH_PLA_ERROR_FILEPATH           = &HC0000BF0&

'//
'// MessageId: PDH_PLA_SERVICE_ERROR
'//
'// MessageText:
'//
'//  The "Performance Logs & Alerts" service did not respond.
'//

%PDH_PLA_SERVICE_ERROR            = &HC0000BF1&

'//
'// MessageId: PDH_PLA_VALIDATION_ERROR
'//
'// MessageText:
'//
'//  The information passed is not valid.
'//

%PDH_PLA_VALIDATION_ERROR         = &HC0000BF2&

'//
'// MessageId: PDH_PLA_VALIDATION_WARNING
'//
'// MessageText:
'//
'//  The information passed is not valid.
'//

%PDH_PLA_VALIDATION_WARNING       = &H80000BF3&

'//
'// MessageId: PDH_PLA_ERROR_NAME_TOO_LONG
'//
'// MessageText:
'//
'//  The name supplied is too long.
'//

%PDH_PLA_ERROR_NAME_TOO_LONG      = &HC0000BF4&

'//
'// MessageId: PDH_INVALID_SQL_LOG_FORMAT
'//
'// MessageText:
'//
'//  SQL log format is incorrect. Correct format is "SQL:<DSN-name>!<LogSet-Name>".
'//

%PDH_INVALID_SQL_LOG_FORMAT       = &HC0000BF5&

'//
'// MessageId: PDH_COUNTER_ALREADY_IN_QUERY
'//
'// MessageText:
'//
'//  Performance counter in PdhAddCounter() call has already been added
'//  in the performance query. This counter is ignored.
'//

%PDH_COUNTER_ALREADY_IN_QUERY     = &HC0000BF6&

'//
'// MessageId: PDH_BINARY_LOG_CORRUPT
'//
'// MessageText:
'//
'//  Unable to read counter information and data from input binary log files.
'//

%PDH_BINARY_LOG_CORRUPT           = &HC0000BF7&

'//
'// MessageId: PDH_LOG_SAMPLE_TOO_SMALL
'//
'// MessageText:
'//
'//  At least one of the input binary log files contain fewer than two data samples.
'//

%PDH_LOG_SAMPLE_TOO_SMALL         = &HC0000BF8&

'//
'// MessageId: PDH_OS_LATER_VERSION
'//
'// MessageText:
'//
'//  The version of the operating system on the computer named %1 is later than that on the local computer. This operation is not available from the local computer.
'//

%PDH_OS_LATER_VERSION             = &HC0000BF9&

'//
'// MessageId: PDH_OS_EARLIER_VERSION
'//
'// MessageText:
'//
'//  %1 supports %2 or later. Check the operating system version on the computer named %3.
'//

%PDH_OS_EARLIER_VERSION           = &HC0000BFA&

'//
'// MessageId: PDH_INCORRECT_APPEND_TIME
'//
'// MessageText:
'//
'//  The output file must contain earlier data than the file to be appended.
'//

%PDH_INCORRECT_APPEND_TIME        = &HC0000BFB&

'//
'// MessageId: PDH_UNMATCHED_APPEND_COUNTER
'//
'// MessageText:
'//
'//  Both files must have identical counters in order to append.
'//

%PDH_UNMATCHED_APPEND_COUNTER     = &HC0000BFC&

'//
'// MessageId: PDH_SQL_ALTER_DETAIL_FAILED
'//
'// MessageText:
'//
'//  Cannot alter CounterDetail table layout in SQL database.
'//

%PDH_SQL_ALTER_DETAIL_FAILED      = &HC0000BFD&

'//
'// MessageId: PDH_QUERY_PERF_DATA_TIMEOUT
'//
'// MessageText:
'//
'//  System is busy. Timeout when collecting counter data. Please retry later or increase "CollectTime" registry value.
'//

%PDH_QUERY_PERF_DATA_TIMEOUT      = &HC0000BFE&
