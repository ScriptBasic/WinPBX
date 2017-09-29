' ########################################################################################
' Microsoft Windows
' File: dtsmsg.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DTSMSG_INC = 1

' ////////////////////////////////////////////////////////////////////////////
' //     Copyright (c) 2005 Microsoft Corporation
' //
' //     This file contains all the US english event messages and
' //     HRESULTs for the SQL Data Transformation Services
' //     Runtime, Pipeline, stock tasks, and stock transforms.
' //
' //
' //
' //   Message and HRESULT naming convention
' //
' //   Error HRESULTs -
' //        Begin with DTS_E_
' //        End with the description of the failed operation
' //
' //   Warning HRESULTs -
' //        Begin with DTS_W_
' //        End with the description of the warning operation
' //
' //   Information HRESULTs -
' //        Begin with DTS_I_
' //        End with the description of the operation
' //
' //   Success HRESULTs -
' //        Begin with DTS_S_
' //        End with the description of the successful operation
' //
' //   Messages for the event log -
' //        Begin with DTS_MSG_
' //        End with the description of the message
' //
' //
' //
' //    Values are 32 bit values layed out as follows:
' //
' //     3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
' //     1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
' //    +---+-+-+-----------------------+-------------------------------+
' //    |Sev|C|R|     Facility          |               Code            |
' //    +---+-+-+-----------------------+-------------------------------+
' //
' //    where
' //
' //        Sev - is the severity code
' //
' //            00 - Success
' //            01 - Informational
' //            10 - Warning
' //            11 - Error
' //
' //        C - is the Customer code flag
' //
' //        R - is a reserved bit
' //
' //        Facility - is the facility code
' //
' //        Code - is the facility's status code
' //
' //
' //   Define the facility codes
' //
%DTS_FACILITY_TOOLS               = &H10&
%DTS_FACILITY_TASK                = &H2&
%DTS_FACILITY_SQL                 = &HA&
%DTS_FACILITY_SCRIPTING           = &H8&
%DTS_FACILITY_RUNTIME             = &H1&
%DTS_FACILITY_GENERIC             = &H0&
%DTS_FACILITY_PIPELINE            = &H4&
%DTS_FACILITY_CONNECTION          = &HF&
%DTS_FACILITY_COMPONENT           = &H20&
%DTS_FACILITY_BASECLASS           = &H800&


' //
' //   Define the severity codes
' //
%DTS_SEVERITY_WARNING             = &H2&
%DTS_SEVERITY_SUCCESS             = &H0&
%DTS_SEVERITY_INFORMATIONAL       = &H1&
%DTS_SEVERITY_ERROR               = &H3&


' //
' //   MessageId: DTSBC_E_INCORRECTEXACTNUMBEROFTOTALOUTPUTS
' //
' //   MessageText:
' //
' //    The total number of outputs and error outputs, %1!lu!, is incorrect. There must be exactly %2!lu!.
' //
%DTSBC_E_INCORRECTEXACTNUMBEROFTOTALOUTPUTS = &HC8000002&

' //
' //   MessageId: DTSBC_E_FAILEDTOGETOUTPUTBYINDEX
' //
' //   MessageText:
' //
' //    Cannot retrieve output with index %1!lu!.
' //
%DTSBC_E_FAILEDTOGETOUTPUTBYINDEX = &HC8000003&

' //
' //   MessageId: DTSBC_E_INCORRECTEXACTNUMBEROFERROROUTPUTS
' //
' //   MessageText:
' //
' //    The number of error outputs, %1!lu!,  is incorrect. There must be exactly %2!lu!.
' //
%DTSBC_E_INCORRECTEXACTNUMBEROFERROROUTPUTS = &HC8000005&

' //
' //   MessageId: DTSBC_E_INVALIDVALIDATIONSTATUSVALUE
' //
' //   MessageText:
' //
' //    Incorrect validation status value, "%1!lu! ".  It must be one of the values found in the DTSValidationStatus enumeration.
' //
%DTSBC_E_INVALIDVALIDATIONSTATUSVALUE = &HC8000006&

' //
' //   MessageId: DTSBC_E_INPUTHASNOOUTPUT
' //
' //   MessageText:
' //
' //    The input "%1!lu!" has no synchronous output.
' //
%DTSBC_E_INPUTHASNOOUTPUT         = &HC8000007&

' //
' //   MessageId: DTSBC_E_INPUTHASNOERROROUTPUT
' //
' //   MessageText:
' //
' //    The input "%1!lu!" has no synchronous error output.
' //
%DTSBC_E_INPUTHASNOERROROUTPUT    = &HC8000008&

' //
' //   MessageId: DTSBC_E_INVALIDHTPIVALUE
' //
' //   MessageText:
' //
' //    The HowToProcessInput value, %1!lu!, is not valid. It must be one of the values from the HowToProcessInput enumeration.
' //
%DTSBC_E_INVALIDHTPIVALUE         = &HC8000009&

' //
' //   MessageId: DTSBC_E_FAILEDTOGETCOLINFO
' //
' //   MessageText:
' //
' //    Failed to get information for row "%1!ld!", column "%2!ld!" from the buffer.  The error code returned was 0x%3!8.8X!.
' //
%DTSBC_E_FAILEDTOGETCOLINFO       = &HC800000A&

' //
' //   MessageId: DTSBC_E_FAILEDTOSETCOLINFO
' //
' //   MessageText:
' //
' //    Failed to set information for row "%1!ld!", column "%2!ld!" into the buffer.  The error code returned was 0x%3!8.8X!.
' //
%DTSBC_E_FAILEDTOSETCOLINFO       = &HC800000B&

' //
' //   MessageId: DTSBC_E_INVALIDPROPERTY
' //
' //   MessageText:
' //
' //    The property "%1!s!" is not valid.
' //
%DTSBC_E_INVALIDPROPERTY          = &HC800000C&

' //
' //   MessageId: DTSBC_E_PROPERTYNOTFOUND
' //
' //   MessageText:
' //
' //    The property "%1!s!" was not found.
' //
%DTSBC_E_PROPERTYNOTFOUND         = &HC800000D&

' //
' //   MessageId: DTSBC_E_READONLYPROPERTY
' //
' //   MessageText:
' //
' //    Error assigning a value to the read-only property "%1!s!".
' //
%DTSBC_E_READONLYPROPERTY         = &HC8000010&

' //
' //   MessageId: DTSBC_E_CANTINSERTOUTPUTCOLUMN
' //
' //   MessageText:
' //
' //    The %1!s! does not allow the insertion of output columns.
' //
%DTSBC_E_CANTINSERTOUTPUTCOLUMN   = &HC8000011&

' //
' //   MessageId: DTSBC_E_OUTPUTCOLUMNSMETADATAMISMATCH
' //
' //   MessageText:
' //
' //    The output columns' metadata does not match the associated input columns' metadata.  The output columns' metadata will be updated.
' //
%DTSBC_E_OUTPUTCOLUMNSMETADATAMISMATCH = &HC8000012&

' //
' //   MessageId: DTSBC_E_OUTPUTCOLUMNSMISSING
' //
' //   MessageText:
' //
' //    There are input columns that do not have associated output columns. The output columns will be added.
' //
%DTSBC_E_OUTPUTCOLUMNSMISSING     = &HC8000013&

' //
' //   MessageId: DTSBC_E_TOOMANYOUTPUTCOLUMNS
' //
' //   MessageText:
' //
' //    There are output columns that do not have associated input columns. The output columns will be removed.
' //
%DTSBC_E_TOOMANYOUTPUTCOLUMNS     = &HC8000014&

' //
' //   MessageId: DTSBC_E_OUTPUTCOLUMNSMETADATAMISMATCHUNMAP
' //
' //   MessageText:
' //
' //    The output columns' metadata does not match the associated input columns' metadata.  The input columns will be unmapped.
' //
%DTSBC_E_OUTPUTCOLUMNSMETADATAMISMATCHUNMAP = &HC8000015&

' //
' //   MessageId: DTSBC_E_UNMAPINPUTCOLUMNS
' //
' //   MessageText:
' //
' //    There are input columns that do not have associated output columns. The input columns will be unmapped.
' //
%DTSBC_E_UNMAPINPUTCOLUMNS        = &HC8000016&

' //
' //   MessageId: DTSBC_E_MULTIPLEINCOLSTOOUTCOL
' //
' //   MessageText:
' //
' //    There is an input column associated with an output column, and that output column is already associated with another input column on the same input.
' //
%DTSBC_E_MULTIPLEINCOLSTOOUTCOL   = &HC8000017&

' //
' //   MessageId: DTSBC_E_CANTINSERTEXTERNALMETADATACOLUMN
' //
' //   MessageText:
' //
' //    The %1!s! does not allow the insertion of external metadata columns.
' //
%DTSBC_E_CANTINSERTEXTERNALMETADATACOLUMN = &HC8000018&

' ////////////////////////////////////////////////////////////////////////////
' //   Check SQLCommand property object.

' //
' //   MessageId: DTS_E_MISSINGSQLCOMMAND
' //
' //   MessageText:
' //
' //    The SQL command has not been set correctly. Check SQLCommand property.
' //
%DTS_E_MISSINGSQLCOMMAND          = &HC0202001&

' //
' //   MessageId: DTS_E_COMERROR
' //
' //   MessageText:
' //
' //    COM error object information is available.  Source: "%1!s!"  error code: 0x%2!8.8X!  Description: "%3!s!".
' //
%DTS_E_COMERROR                   = &HC0202002&

' //
' //   MessageId: DTS_E_ACQUIREDCONNECTIONUNAVAILABLE
' //
' //   MessageText:
' //
' //    Unable to access the acquired connections.
' //
%DTS_E_ACQUIREDCONNECTIONUNAVAILABLE = &HC0202003&

' //
' //   MessageId: DTS_E_INCORRECTCOLUMNCOUNT
' //
' //   MessageText:
' //
' //    The number of columns is incorrect.
' //
%DTS_E_INCORRECTCOLUMNCOUNT       = &HC0202004&

' //
' //   MessageId: DTS_E_COLUMNNOTFOUND
' //
' //   MessageText:
' //
' //    Column "%1!s!" cannot be found at the datasource.
' //
%DTS_E_COLUMNNOTFOUND             = &HC0202005&

' //
' //   MessageId: DTS_E_OLEDBRECORD
' //
' //   MessageText:
' //
' //    An OLE DB record is available.  Source: "%1!s!"  Hresult: 0x%2!8.8X!  Description: "%3!s!".
' //
%DTS_E_OLEDBRECORD                = &HC0202007&

' //
' //   MessageId: DTS_E_OLEDBERROR
' //
' //   MessageText:
' //
' //    An OLE DB error has occurred. Error code: 0x%1!8.8X!.
' //
%DTS_E_OLEDBERROR                 = &HC0202009&

' ////////////////////////////////////////////////////////////////////////////
' //   Need to call disconnect before calling connect.

' //
' //   MessageId: DTS_E_ALREADYCONNECTED
' //
' //   MessageText:
' //
' //    Component is already connected. The component needs to be disconnected before attempting to connect it.
' //
%DTS_E_ALREADYCONNECTED           = &HC020200A&

' //
' //   MessageId: DTS_E_INCORRECTSTOCKPROPERTYVALUE
' //
' //   MessageText:
' //
' //    The value of the property "%1!s!" is incorrect.
' //
%DTS_E_INCORRECTSTOCKPROPERTYVALUE = &HC020200B&

' //
' //   MessageId: DTS_E_CANNOTOPENDATAFILE
' //
' //   MessageText:
' //
' //    Cannot open the datafile "%1!s!".
' //
%DTS_E_CANNOTOPENDATAFILE         = &HC020200E&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure the flat file connection manager is configured with a connection string.  If the flat file connection manager is used by multiple components, the connection string may not contain enough file names.

' //
' //   MessageId: DTS_E_DESTINATIONFLATFILEREQUIRED
' //
' //   MessageText:
' //
' //    No destination flat file name was provided. Make sure the flat file connection manager is configured with a connection string. If the flat file connection manager is used by multiple components,
' // ensure that the connection string contains enough file names.
' //
%DTS_E_DESTINATIONFLATFILEREQUIRED = &HC0202010&

' //
' //   MessageId: DTS_E_TEXTQUALIFIERNOTFOUND
' //
' //   MessageText:
' //
' //    The text qualifier for column "%1!s!" cannot be found.
' //
%DTS_E_TEXTQUALIFIERNOTFOUND      = &HC0202011&

' //
' //   MessageId: DTS_E_CANNOTCONVERTTYPES
' //
' //   MessageText:
' //
' //    Conversion from "%1!s!" to "%2!s!" is not supported.
' //
%DTS_E_CANNOTCONVERTTYPES         = &HC0202014&

' //
' //   MessageId: DTS_E_PROBLEMDETECTINGTYPECOMPATIBILITY
' //
' //   MessageText:
' //
' //    The error code 0x%1!8.8X! was returned when validating type conversion from %2!s! to %3!s!.
' //
%DTS_E_PROBLEMDETECTINGTYPECOMPATIBILITY = &HC0202015&

' ////////////////////////////////////////////////////////////////////////////
' //   Check SourceInputColumnLineageID custom property of the output column.

' //
' //   MessageId: DTS_E_CANNOTMAPINPUTCOLUMNTOOUTPUTCOLUMN
' //
' //   MessageText:
' //
' //    Cannot find input column with lineage ID "%1!d!" which is needed by "%2!s!". Check SourceInputColumnLineageID custom property of the output column.
' //
%DTS_E_CANNOTMAPINPUTCOLUMNTOOUTPUTCOLUMN = &HC0202016&

' //
' //   MessageId: DTS_E_INCORRECTMINIMUMNUMBEROFOUTPUTS
' //
' //   MessageText:
' //
' //    The number of outputs is incorrect. There must be at least %1!d! outputs.
' //
%DTS_E_INCORRECTMINIMUMNUMBEROFOUTPUTS = &HC0202017&

' //
' //   MessageId: DTS_E_INCORRECTEXACTNUMBEROFOUTPUTS
' //
' //   MessageText:
' //
' //    The number of outputs is incorrect. There must be exactly %1!d! output(s).
' //
%DTS_E_INCORRECTEXACTNUMBEROFOUTPUTS = &HC0202018&

' ////////////////////////////////////////////////////////////////////////////
' //   A string was found to be longer than Windows can safely convert.

' //
' //   MessageId: DTS_E_STRINGCONVERSIONTOOLONG
' //
' //   MessageText:
' //
' //    A string was too long to be converted.
' //
%DTS_E_STRINGCONVERSIONTOOLONG    = &HC0202019&

' //
' //   MessageId: DTS_E_INCORRECTEXACTNUMBEROFINPUTS
' //
' //   MessageText:
' //
' //    The number of inputs is incorrect. There must be exactly %1!d! inputs.
' //
%DTS_E_INCORRECTEXACTNUMBEROFINPUTS = &HC020201A&

' //
' //   MessageId: DTS_E_CANNOTHAVEZEROINPUTCOLUMNS
' //
' //   MessageText:
' //
' //    The number of input columns for %1!s! cannot be zero.
' //
%DTS_E_CANNOTHAVEZEROINPUTCOLUMNS = &HC020201B&

' //
' //   MessageId: DTS_E_CANNOTHAVEINPUTS
' //
' //   MessageText:
' //
' //    This component has %1!d! inputs.  No input is allowed on this component.
' //
%DTS_E_CANNOTHAVEINPUTS           = &HC020201C&

' //
' //   MessageId: DTS_E_PROCESSINPUTCALLEDWITHINVALIDINPUTID
' //
' //   MessageText:
' //
' //    ProcessInput was called with an invalid input ID of %1!d!.
' //
%DTS_E_PROCESSINPUTCALLEDWITHINVALIDINPUTID = &HC020201D&

' //
' //   MessageId: DTS_E_INCORRECTCUSTOMPROPERTYTYPE
' //
' //   MessageText:
' //
' //    The custom property "%1!s!" needs to be of type %2!s!.
' //
%DTS_E_INCORRECTCUSTOMPROPERTYTYPE = &HC020201F&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure the Pipeline layout and all components pass validation.

' //
' //   MessageId: DTS_E_INVALIDBUFFERTYPE
' //
' //   MessageText:
' //
' //    The buffer type is not valid. Make sure the Pipeline layout and all components pass validation.
' //
%DTS_E_INVALIDBUFFERTYPE          = &HC0202020&

' //
' //   MessageId: DTS_E_INCORRECTCUSTOMPROPERTYVALUE
' //
' //   MessageText:
' //
' //    The value for custom property "%1!s!" is incorrect.
' //
%DTS_E_INCORRECTCUSTOMPROPERTYVALUE = &HC0202021&

' //
' //   MessageId: DTS_E_CONNECTIONREQUIREDFORMETADATA
' //
' //   MessageText:
' //
' //    An error occurred due to no connection. A connection is required when requesting metadata.
' //
%DTS_E_CONNECTIONREQUIREDFORMETADATA = &HC0202022&

' //
' //   MessageId: DTS_E_CANTCREATECUSTOMPROPERTY
' //
' //   MessageText:
' //
' //    The custom property "%1!s!" cannot be created.
' //
%DTS_E_CANTCREATECUSTOMPROPERTY   = &HC0202023&

' //
' //   MessageId: DTS_E_CANTGETCUSTOMPROPERTYCOLLECTION
' //
' //   MessageText:
' //
' //    The custom property collection cannot be retrieved for initialization.
' //
%DTS_E_CANTGETCUSTOMPROPERTYCOLLECTION = &HC0202024&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure column metadata is valid.

' //
' //   MessageId: DTS_E_CANNOTCREATEACCESSOR
' //
' //   MessageText:
' //
' //    Cannot create an OLE DB accessor. Verify that the column metadata is valid.
' //
%DTS_E_CANNOTCREATEACCESSOR       = &HC0202025&

' //
' //   MessageId: DTS_E_PRIMEOUTPUTCALLEDWITHINVALIDOUTPUTID
' //
' //   MessageText:
' //
' //    PrimeOutput was called with an invalid output ID of %1!d!.
' //
%DTS_E_PRIMEOUTPUTCALLEDWITHINVALIDOUTPUTID = &HC0202026&

' //
' //   MessageId: DTS_E_INCORRECTSTOCKPROPERTY
' //
' //   MessageText:
' //
' //    The value for property "%1!s!" on "%2!s!" is not valid.
' //
%DTS_E_INCORRECTSTOCKPROPERTY     = &HC0202027&

' //
' //   MessageId: DTS_E_CONNECTIONREQUIREDFORREAD
' //
' //   MessageText:
' //
' //    A connection is required to read data.
' //
%DTS_E_CONNECTIONREQUIREDFORREAD  = &HC0202028&

' //
' //   MessageId: DTS_E_ERRORWHILEREADINGHEADERROWS
' //
' //   MessageText:
' //
' //    An error occurred while reading header rows.
' //
%DTS_E_ERRORWHILEREADINGHEADERROWS = &HC020202C&

' //
' //   MessageId: DTS_E_DUPLICATECOLUMNNAME
' //
' //   MessageText:
' //
' //    Duplicate column name "%1!s!".
' //
%DTS_E_DUPLICATECOLUMNNAME        = &HC020202D&

' //
' //   MessageId: DTS_E_CANNOTGETCOLUMNNAME
' //
' //   MessageText:
' //
' //    Cannot get the name of the column with ID %1!d!.
' //
%DTS_E_CANNOTGETCOLUMNNAME        = &HC0202030&

' //
' //   MessageId: DTS_E_CANTDIRECTROW
' //
' //   MessageText:
' //
' //    Direct row to output "%1!s!" (%2!d!) failed.
' //
%DTS_E_CANTDIRECTROW              = &HC0202031&

' //
' //   MessageId: DTS_E_CANNOTCREATEBULKINSERTHREAD
' //
' //   MessageText:
' //
' //    Cannot create the bulk insert thread due to error "%1!s!".
' //
%DTS_E_CANNOTCREATEBULKINSERTHREAD = &HC020203A&

' //
' //   MessageId: DTS_E_BULKINSERTHREADINITIALIZATIONFAILED
' //
' //   MessageText:
' //
' //    The thread for the SSIS Bulk Insert task failed initialization.
' //
%DTS_E_BULKINSERTHREADINITIALIZATIONFAILED = &HC020203B&

' //
' //   MessageId: DTS_E_BULKINSERTTHREADALREADYRUNNING
' //
' //   MessageText:
' //
' //    The thread for the SSIS Bulk Insert task is already running.
' //
%DTS_E_BULKINSERTTHREADALREADYRUNNING = &HC020203E&

' //
' //   MessageId: DTS_E_BULKINSERTTHREADABNORMALCOMPLETION
' //
' //   MessageText:
' //
' //    The thread for the SSIS Bulk Insert task terminated with errors or warnings.
' //
%DTS_E_BULKINSERTTHREADABNORMALCOMPLETION = &HC020203F&

' ////////////////////////////////////////////////////////////////////////////
' //   Check that the object exists in the database.

' //
' //   MessageId: DTS_E_CANNOTGETIROWSETFASTLOAD
' //
' //   MessageText:
' //
' //    Failed to open a fastload rowset for "%1!s!". Check that the object exists in the database.
' //
%DTS_E_CANNOTGETIROWSETFASTLOAD   = &HC0202040&

' //
' //   MessageId: DTS_E_CONNECTREQUIREDFORMETADATAVALIDATION
' //
' //   MessageText:
' //
' //    Error due to no connection. A connection is required before metadata validation can proceed.
' //
%DTS_E_CONNECTREQUIREDFORMETADATAVALIDATION = &HC0202041&

' //
' //   MessageId: DTS_E_DESTINATIONTABLENAMENOTPROVIDED
' //
' //   MessageText:
' //
' //    A destination table name has not been provided.
' //
%DTS_E_DESTINATIONTABLENAMENOTPROVIDED = &HC0202042&

' ////////////////////////////////////////////////////////////////////////////
' //   Set the adapter's ValidateColumnMetaData property to false.

' //
' //   MessageId: DTS_E_ICONVERTTYPEUNAVAILABLE
' //
' //   MessageText:
' //
' //    The OLE DB provider used by the OLE DB adapter does not support IConvertType. Set the adapter's ValidateColumnMetaData property to FALSE.
' //
%DTS_E_ICONVERTTYPEUNAVAILABLE    = &HC0202043&

' //
' //   MessageId: DTS_E_OLEDBPROVIDERDATATYPECONVERSIONUNSUPPORTED
' //
' //   MessageText:
' //
' //    The OLE DB provider used by the OLE DB adapter cannot convert between types "%1!s!" and "%2!s!" for "%3!s!".
' //
%DTS_E_OLEDBPROVIDERDATATYPECONVERSIONUNSUPPORTED = &HC0202044&

' //
' //   MessageId: DTS_E_VALIDATECOLUMNMETADATAFAILED
' //
' //   MessageText:
' //
' //    Column metadata validation failed.
' //
%DTS_E_VALIDATECOLUMNMETADATAFAILED = &HC0202045&

' //
' //   MessageId: DTS_E_ATTEMPTINGTOINSERTINTOAROWIDCOLUMN
' //
' //   MessageText:
' //
' //    "%1!s!" is a row ID column and cannot be included in a data insertion operation.
' //
%DTS_E_ATTEMPTINGTOINSERTINTOAROWIDCOLUMN = &HC0202047&

' //
' //   MessageId: DTS_E_ATTEMPTINGTOINSERTINTOAROWVERCOLUMN
' //
' //   MessageText:
' //
' //    Attempting insertion into the row version column "%1!s!". Cannot insert into a row version column.
' //
%DTS_E_ATTEMPTINGTOINSERTINTOAROWVERCOLUMN = &HC0202048&

' //
' //   MessageId: DTS_E_ATTEMPTINGTOINSERTINTOAREADONLYCOLUMN
' //
' //   MessageText:
' //
' //    Failure inserting into the read-only column "%1!s!".
' //
%DTS_E_ATTEMPTINGTOINSERTINTOAREADONLYCOLUMN = &HC0202049&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure your target table in the database is available.

' //
' //   MessageId: DTS_E_UNABLETORETRIEVECOLUMNINFO
' //
' //   MessageText:
' //
' //    Unable to retrieve column information from the data source. Make sure your target table in the database is available.
' //
%DTS_E_UNABLETORETRIEVECOLUMNINFO = &HC020204A&

' ////////////////////////////////////////////////////////////////////////////
' //   The system is out of memory, or the buffer manager has reached its quota.

' //
' //   MessageId: DTS_E_CANTLOCKBUFFER
' //
' //   MessageText:
' //
' //    A buffer could not be locked. The system is out of memory or the buffer manager has reached its quota.
' //
%DTS_E_CANTLOCKBUFFER             = &HC020204B&

' //
' //   MessageId: DTS_E_INVALIDCOMPARISONFLAGS
' //
' //   MessageText:
' //
' //    The %1!s! has a ComparisonFlags property that includes extra flags with the value %2!d!.
' //
%DTS_E_INVALIDCOMPARISONFLAGS     = &HC020204C&

' //
' //   MessageId: DTS_E_COLUMNMETADATAUNAVAILABLEFORVALIDATION
' //
' //   MessageText:
' //
' //    The column metadata was unavailable for validation.
' //
%DTS_E_COLUMNMETADATAUNAVAILABLEFORVALIDATION = &HC020204D&

' //
' //   MessageId: DTS_E_CANNOTWRITETODATAFILE
' //
' //   MessageText:
' //
' //    Cannot write to the data file.
' //
%DTS_E_CANNOTWRITETODATAFILE      = &HC0202053&

' //
' //   MessageId: DTS_E_COLUMNDELIMITERNOTFOUND
' //
' //   MessageText:
' //
' //    The column delimiter for column "%1!s!" was not found.
' //
%DTS_E_COLUMNDELIMITERNOTFOUND    = &HC0202055&

' //
' //   MessageId: DTS_E_COLUMNPARSEFAILED
' //
' //   MessageText:
' //
' //    Failed to parse the column "%1!s!" in the data file.
' //
%DTS_E_COLUMNPARSEFAILED          = &HC0202058&

' ////////////////////////////////////////////////////////////////////////////
' //   Need a file name to read from or write to!

' //
' //   MessageId: DTS_E_RAWFILENAMEREQUIRED
' //
' //   MessageText:
' //
' //    The file name is not properly specified.  Supply the path and name to the raw file either directly in the FileName property or by specifying a variable in the FileNameVariable property.
' //
%DTS_E_RAWFILENAMEREQUIRED        = &HC020205A&

' ////////////////////////////////////////////////////////////////////////////
' //   No priveleges or disk full.

' //
' //   MessageId: DTS_E_RAWFILECANTOPEN
' //
' //   MessageText:
' //
' //    File "%1!s!" cannot be opened for writing. Error may occur when there are no file privileges or the disk is full.
' //
%DTS_E_RAWFILECANTOPEN            = &HC020205B&

' //
' //   MessageId: DTS_E_RAWFILECANTBUFFER
' //
' //   MessageText:
' //
' //    An I/O buffer cannot be created for the output file. Error may occur when there are no file privileges or the disk is full.
' //
%DTS_E_RAWFILECANTBUFFER          = &HC020205C&

' ////////////////////////////////////////////////////////////////////////////
' //   The cause of the failure should have been previously reported.

' //
' //   MessageId: DTS_E_RAWCANTWRITE
' //
' //   MessageText:
' //
' //    Cannot write %1!d! bytes to file "%2!s!". See previous error messages for details.
' //
%DTS_E_RAWCANTWRITE               = &HC020205D&

' ////////////////////////////////////////////////////////////////////////////
' //   The file is corrupt or not a SSIS-produced raw data file.

' //
' //   MessageId: DTS_E_RAWBADHEADER
' //
' //   MessageText:
' //
' //    Encountered bad metadata in file header. The file is damaged or not a SSIS-produced raw data file.
' //
%DTS_E_RAWBADHEADER               = &HC020205E&

' ////////////////////////////////////////////////////////////////////////////
' //   The file exists and the WriteOption property is set to CreateOnce.

' //
' //   MessageId: DTS_E_RAWEXISTSCREATEONCE
' //
' //   MessageText:
' //
' //    Error occurred because the output file already exists and the WriteOption is set to Create Once. Set the WriteOption property to Create Always, or delete the file.
' //
%DTS_E_RAWEXISTSCREATEONCE        = &HC020205F&

' ////////////////////////////////////////////////////////////////////////////
' //   Can't have both properties set.

' //
' //   MessageId: DTS_E_RAWCANTAPPENDTRUNCATE
' //
' //   MessageText:
' //
' //    Error caused by conflicting property settings. Both the AllowAppend property and the ForceTruncate property are set to TRUE. Both properties cannot be set to TRUE. Set one of the two properties to FALSE.
' //
%DTS_E_RAWCANTAPPENDTRUNCATE      = &HC0202060&

' ////////////////////////////////////////////////////////////////////////////
' //   The file is corrupt or not a SSIS-produced raw data file.

' //
' //   MessageId: DTS_E_RAWBADVERSION
' //
' //   MessageText:
' //
' //    The file had bad version and flags information. The file is damaged or not a SSIS-produced raw data file.
' //
%DTS_E_RAWBADVERSION              = &HC0202061&

' ////////////////////////////////////////////////////////////////////////////
' //   Old file with a format we don't understand.

' //
' //   MessageId: DTS_E_RAWVERSIONINCOMPATIBLEAPPEND
' //
' //   MessageText:
' //
' //    The output file was written by an incompatible version and cannot be appended. The file may be an older file format that is no longer useable.
' //
%DTS_E_RAWVERSIONINCOMPATIBLEAPPEND = &HC0202062&

' ////////////////////////////////////////////////////////////////////////////
' //   Old file doesn't match in metadata.

' //
' //   MessageId: DTS_E_RAWMETADATAMISMATCH
' //
' //   MessageText:
' //
' //    Cannot append output file because no column in the existing file matches column "%1!s!" from the input. Old file does not match in metadata.
' //
%DTS_E_RAWMETADATAMISMATCH        = &HC0202064&

' //
' //   MessageId: DTS_E_RAWMETADATACOUNTMISMATCH
' //
' //   MessageText:
' //
' //    Cannot append output file because the number of columns in the output file does not match the number of columns in this destination. The old file does not match in metadata.
' //
%DTS_E_RAWMETADATACOUNTMISMATCH   = &HC0202065&

' //
' //   MessageId: DTS_E_ERRORRETRIEVINGCOLUMNCODEPAGE
' //
' //   MessageText:
' //
' //    There was an error retrieving column code page information.
' //
%DTS_E_ERRORRETRIEVINGCOLUMNCODEPAGE = &HC0202067&

' ////////////////////////////////////////////////////////////////////////////
' //   The cause of the failure should have been previously reported.

' //
' //   MessageId: DTS_E_RAWCANTREAD
' //
' //   MessageText:
' //
' //    Cannot read %1!d! bytes from file "%2!s!". The cause of the failure should have been previously reported.
' //
%DTS_E_RAWCANTREAD                = &HC0202068&

' ////////////////////////////////////////////////////////////////////////////
' //   The file ended prematurely because it has an invalid format.

' //
' //   MessageId: DTS_E_RAWUNEXPECTEDEOF
' //
' //   MessageText:
' //
' //    Unexpected end-of-file encountered while reading %1!d! bytes from file "%2!s!". The file ended prematurely because of an invalid file format.
' //
%DTS_E_RAWUNEXPECTEDEOF           = &HC0202069&

' //
' //   MessageId: DTS_E_RAWNOLONGTYPES
' //
' //   MessageText:
' //
' //    The raw adapters do not support image, text, or ntext data.
' //
%DTS_E_RAWNOLONGTYPES             = &HC020206A&

' ////////////////////////////////////////////////////////////////////////////
' //   Corrupt input file (source) or completely invalid buffer type (dest).

' //
' //   MessageId: DTS_E_RAWUNEXPECTEDTYPE
' //
' //   MessageText:
' //
' //    The adapter encountered an unrecognized data type of %1!d!. This could be caused by a damaged input file (source) or by an invalid buffer type (destination).
' //
%DTS_E_RAWUNEXPECTEDTYPE          = &HC020206B&

' ////////////////////////////////////////////////////////////////////////////
' //   Corrupt input file. The file showed a string length that was too big for the buffer column we've got.

' //
' //   MessageId: DTS_E_RAWSTRINGTOOLONG
' //
' //   MessageText:
' //
' //    String too long. The adapter read a string that was %1!d! bytes long, and expected a string no longer than %2!d! bytes, at offset %3!d!. This could indicate a damaged input file. The file shows a string length that is too large for the buffer column.
' //
%DTS_E_RAWSTRINGTOOLONG           = &HC020206C&

' ////////////////////////////////////////////////////////////////////////////
' //   The error returned from the OS should have been previously reported.

' //
' //   MessageId: DTS_E_RAWSKIPFAILED
' //
' //   MessageText:
' //
' //    The raw adapter attempted to skip %1!d! bytes in the input file for unreferenced column "%2!s!" with lineage ID %3!d!, but there was an error. The error returned from the operating system should have been previously reported.
' //
%DTS_E_RAWSKIPFAILED              = &HC020206E&

' //
' //   MessageId: DTS_E_RAWREADFAILED
' //
' //   MessageText:
' //
' //    The raw adapter attempted to read %1!d! bytes in the input file for column "%2!s!" with lineage ID %3!d!, but there was an error. The error returned from the operating system should have been previously reported.
' //
%DTS_E_RAWREADFAILED              = &HC020206F&

' ////////////////////////////////////////////////////////////////////////////
' //   The file name was a device, or contained invalid characters.

' //
' //   MessageId: DTS_E_RAWFILENAMEINVALID
' //
' //   MessageText:
' //
' //    The file name property is not valid. The file name is a device or contains invalid characters.
' //
%DTS_E_RAWFILENAMEINVALID         = &HC0202070&

' //
' //   MessageId: DTS_E_BULKINSERTAPIPREPARATIONFAILED
' //
' //   MessageText:
' //
' //    Unable to prepare the SSIS bulk insert for data insertion.
' //
%DTS_E_BULKINSERTAPIPREPARATIONFAILED = &HC0202071&

' //
' //   MessageId: DTS_E_INVALIDDATABASEOBJECTNAME
' //
' //   MessageText:
' //
' //    Database object name "%1!s!" is not valid.
' //
%DTS_E_INVALIDDATABASEOBJECTNAME  = &HC0202072&

' //
' //   MessageId: DTS_E_INVALIDORDERCLAUSE
' //
' //   MessageText:
' //
' //    Order clause is not valid.
' //
%DTS_E_INVALIDORDERCLAUSE         = &HC0202073&

' ////////////////////////////////////////////////////////////////////////////
' //   No priveleges or file not found. Exact cause reported in previous error.

' //
' //   MessageId: DTS_E_RAWFILECANTOPENREAD
' //
' //   MessageText:
' //
' //    File "%1!s!" cannot be opened for reading. Error may occur when there are no privileges or the file is not found. Exact cause is reported in previous error message.
' //
%DTS_E_RAWFILECANTOPENREAD        = &HC0202074&

' //
' //   MessageId: DTS_E_TIMEGENCANTCREATE
' //
' //   MessageText:
' //
' //    Unable to create the Microsoft.AnalysisServices.TimeDimGenerator.TimeDimGenerator.
' //
%DTS_E_TIMEGENCANTCREATE          = &HC0202075&

' //
' //   MessageId: DTS_E_TIMEGENCANTCONFIGURE
' //
' //   MessageText:
' //
' //    Unable to configure the Microsoft.AnalysisServices.TimeDimGenerator.
' //
%DTS_E_TIMEGENCANTCONFIGURE       = &HC0202076&

' //
' //   MessageId: DTS_E_TIMEGENCANTCONVERT
' //
' //   MessageText:
' //
' //    Unsupported datatype for column %1!d!.
' //
%DTS_E_TIMEGENCANTCONVERT         = &HC0202077&

' //
' //   MessageId: DTS_E_TIMEGENCANTREAD
' //
' //   MessageText:
' //
' //    The attempt to read from the Microsoft.AnalysisServices.TimeDimGenerator failed with error code 0x%1!8.8X!.
' //
%DTS_E_TIMEGENCANTREAD            = &HC0202079&

' //
' //   MessageId: DTS_E_TIMEGENCANTREADCOLUMN
' //
' //   MessageText:
' //
' //    The attempt to read column "%2!d!" data from the Microsoft.AnalysisServices.TimeDimGenerator failed with error code 0x%2!8.8X!.
' //
%DTS_E_TIMEGENCANTREADCOLUMN      = &HC020207A&

' ////////////////////////////////////////////////////////////////////////////
' //   Need a runtime variable name to write to!]

' //
' //   MessageId: DTS_E_RSTDESTBADVARIABLENAME
' //
' //   MessageText:
' //
' //    The VariableName property is not set to the name of a valid variable. Need a runtime variable name to write to.
' //
%DTS_E_RSTDESTBADVARIABLENAME     = &HC020207B&

' //
' //   MessageId: DTS_E_RSTDESTRSTCONFIGPROBLEM
' //
' //   MessageText:
' //
' //    Unable to create or configure the ADODB.Recordset object.
' //
%DTS_E_RSTDESTRSTCONFIGPROBLEM    = &HC020207C&

' //
' //   MessageId: DTS_E_RSTDESTRSTWRITEPROBLEM
' //
' //   MessageText:
' //
' //    Error writing to the ADODB.Recordset object.
' //
%DTS_E_RSTDESTRSTWRITEPROBLEM     = &HC020207D&

' ////////////////////////////////////////////////////////////////////////////
' //   The file name was a device, or contained invalid characters.

' //
' //   MessageId: DTS_E_FILENAMEINVALID
' //
' //   MessageText:
' //
' //    The file name is not valid. The file name is a device or contains invalid characters.
' //
%DTS_E_FILENAMEINVALID            = &HC020207E&

' //
' //   MessageId: DTS_E_FILENAMEINVALIDWITHPARAM
' //
' //   MessageText:
' //
' //    The file name "%1!s!" is not valid. The file name is a device or contains invalid characters.
' //
%DTS_E_FILENAMEINVALIDWITHPARAM   = &HC020207F&

' //
' //   MessageId: DTS_E_CMDDESTNOPARAMS
' //
' //   MessageText:
' //
' //    Unable to retrieve destination column descriptions from the parameters of the SQL command.
' //
%DTS_E_CMDDESTNOPARAMS            = &HC0202080&

' //
' //   MessageId: DTS_E_CMDDESTNOTBOUND
' //
' //   MessageText:
' //
' //    Parameters are not bound. All parameters in the SQL command must be bound to input columns.
' //
%DTS_E_CMDDESTNOTBOUND            = &HC0202081&

' //
' //   MessageId: DTS_E_TXPIVOTBADUSAGE
' //
' //   MessageText:
' //
' //    The PivotUsage value for the input column "%1!s!" (%2!d!) is not valid.
' //
%DTS_E_TXPIVOTBADUSAGE            = &HC0202082&

' //
' //   MessageId: DTS_E_TXPIVOTTOOMANYPIVOTKEYS
' //
' //   MessageText:
' //
' //    Too many Pivot Keys found. Only one input column can be used as the Pivot Key.
' //
%DTS_E_TXPIVOTTOOMANYPIVOTKEYS    = &HC0202083&

' //
' //   MessageId: DTS_E_TXPIVOTNOPIVOTKEY
' //
' //   MessageText:
' //
' //    No Pivot Key found. One input column must be used as the Pivot Key.
' //
%DTS_E_TXPIVOTNOPIVOTKEY          = &HC0202084&

' //
' //   MessageId: DTS_E_TXPIVOTINPUTALREADYMAPPED
' //
' //   MessageText:
' //
' //    More than one output column (such as "%1!s!" (%2!d!)) is mapped to input column "%3!s!" (%4!d!).
' //
%DTS_E_TXPIVOTINPUTALREADYMAPPED  = &HC0202085&

' //
' //   MessageId: DTS_E_TXPIVOTCANTMAPPIVOTKEY
' //
' //   MessageText:
' //
' //    Output column "%1!s!" (%2!d!) cannot be mapped to PivotKey input column.
' //
%DTS_E_TXPIVOTCANTMAPPIVOTKEY     = &HC0202086&

' //
' //   MessageId: DTS_E_TXPIVOTCANTMAPPINGNOTFOUND
' //
' //   MessageText:
' //
' //    Output column "%1!s!" (%2!d!) has a SourceColumn %3!d! that is not a valid input column lineage ID.
' //
%DTS_E_TXPIVOTCANTMAPPINGNOTFOUND = &HC0202087&

' //
' //   MessageId: DTS_E_TXPIVOTEMPTYPIVOTKEYVALUE
' //
' //   MessageText:
' //
' //    Output column "%1!s!" (%2!d!) is mapped to a Pivoted Value input column, but its PivotKeyValue property value is missing.
' //
%DTS_E_TXPIVOTEMPTYPIVOTKEYVALUE  = &HC0202088&

' //
' //   MessageId: DTS_E_TXPIVOTDUPLICATEPIVOTKEYVALUE
' //
' //   MessageText:
' //
' //    Output column "%1!s!" (%2!d!) is mapped to a Pivoted Value input column with a non-unique PivotKeyValue property value.
' //
%DTS_E_TXPIVOTDUPLICATEPIVOTKEYVALUE = &HC0202089&

' //
' //   MessageId: DTS_E_TXPIVOTOUTPUTNOTMAPPED
' //
' //   MessageText:
' //
' //    Input column "%1!s!" (%2!d!) is not mapped to any output column.
' //
%DTS_E_TXPIVOTOUTPUTNOTMAPPED     = &HC020208A&

' //
' //   MessageId: DTS_E_TXPIVOTCANTCOMPARESETKEYS
' //
' //   MessageText:
' //
' //    Failure occurred while comparing values for the set keys.
' //
%DTS_E_TXPIVOTCANTCOMPARESETKEYS  = &HC020208B&

' //
' //   MessageId: DTS_E_TXPIVOTNOBLOB
' //
' //   MessageText:
' //
' //    The Input column "%1!s!" (%2!d!) cannot be used as a Set Key, Pivot Key, or Pivot Value because it contains long data.
' //
%DTS_E_TXPIVOTNOBLOB              = &HC020208D&

' //
' //   MessageId: DTS_E_TXPIVOTBADOUTPUTTYPE
' //
' //   MessageText:
' //
' //    Incorrect output type. The output column "%1!s!" (%2!d!) must have the same data type and metadata as the input column to which it is mapped.
' //
%DTS_E_TXPIVOTBADOUTPUTTYPE       = &HC020208E&

' //
' //   MessageId: DTS_E_TXPIVOTPROCESSERROR
' //
' //   MessageText:
' //
' //    Failure when trying to pivot the source records.
' //
%DTS_E_TXPIVOTPROCESSERROR        = &HC020208F&

' //
' //   MessageId: DTS_E_TXPIVOTBADPIVOTKEYVALUE
' //
' //   MessageText:
' //
' //    The pivot key value "%1!s!" is not valid.
' //
%DTS_E_TXPIVOTBADPIVOTKEYVALUE    = &HC0202090&

' //
' //   MessageId: DTS_E_ERRORWHILESKIPPINGDATAROWS
' //
' //   MessageText:
' //
' //    An error occurred while skipping data rows.
' //
%DTS_E_ERRORWHILESKIPPINGDATAROWS = &HC0202091&

' //
' //   MessageId: DTS_E_ERRORWHILEREADINGDATAROWS
' //
' //   MessageText:
' //
' //    An error occurred while processing file "%1!s!" on data row %2!I64d!.
' //
%DTS_E_ERRORWHILEREADINGDATAROWS  = &HC0202092&

' //
' //   MessageId: DTS_E_FAILEDTOINITIALIZEFLATFILEPARSER
' //
' //   MessageText:
' //
' //    An error occurred while initializing the flat file parser.
' //
%DTS_E_FAILEDTOINITIALIZEFLATFILEPARSER = &HC0202093&

' //
' //   MessageId: DTS_E_UNABLETORETRIEVECOLUMNINFOFROMFLATFILECONNECTIONMANAGER
' //
' //   MessageText:
' //
' //    Unable to retrieve column information from the flat file connection manager.
' //
%DTS_E_UNABLETORETRIEVECOLUMNINFOFROMFLATFILECONNECTIONMANAGER = &HC0202094&

' //
' //   MessageId: DTS_E_FAILEDTOWRITEOUTCOLUMNNAME
' //
' //   MessageText:
' //
' //    Failed to write out column name for column "%1!s!".
' //
%DTS_E_FAILEDTOWRITEOUTCOLUMNNAME = &HC0202095&

' //
' //   MessageId: DTS_E_INVALIDFLATFILECOLUMNTYPE
' //
' //   MessageText:
' //
' //    The column type for column "%1!s!" is incorrect. It is type "%2!s!". It can only be either "%3!s!" or "%4!s!".
' //
%DTS_E_INVALIDFLATFILECOLUMNTYPE  = &HC0202096&

' //
' //   MessageId: DTS_E_DISKIOBUFFEROVERFLOW
' //
' //   MessageText:
' //
' //    The attempt to write data of %1!d! bytes into the disk I/O failed. The disk I/O buffer has %2!d! free bytes.
' //
%DTS_E_DISKIOBUFFEROVERFLOW       = &HC0202097&

' //
' //   MessageId: DTS_E_FAILEDTOWRITEOUTHEADER
' //
' //   MessageText:
' //
' //    An error occurred while writing out the file header.
' //
%DTS_E_FAILEDTOWRITEOUTHEADER     = &HC0202098&

' //
' //   MessageId: DTS_E_FAILEDTOGETFILESIZE
' //
' //   MessageText:
' //
' //    An error occurred while getting the file size for file "%1!s!".
' //
%DTS_E_FAILEDTOGETFILESIZE        = &HC0202099&

' //
' //   MessageId: DTS_E_FAILEDTOSETFILEPOINTER
' //
' //   MessageText:
' //
' //    An error occurred while setting the file pointer for file "%1!s!".
' //
%DTS_E_FAILEDTOSETFILEPOINTER     = &HC020209A&

' //
' //   MessageId: DTS_E_UNABLETOSETUPDISKIOBUFFER
' //
' //   MessageText:
' //
' //    An error occurred while setting up the disk I/O buffer.
' //
%DTS_E_UNABLETOSETUPDISKIOBUFFER  = &HC020209B&

' //
' //   MessageId: DTS_E_COLUMNDATAOVERFLOWDISKIOBUFFER
' //
' //   MessageText:
' //
' //    The column data for column "%1!s!" overflowed the disk I/O buffer.
' //
%DTS_E_COLUMNDATAOVERFLOWDISKIOBUFFER = &HC020209C&

' //
' //   MessageId: DTS_E_DISKIOFAILED
' //
' //   MessageText:
' //
' //    An unexpected disk I/O error occurred while reading the file.
' //
%DTS_E_DISKIOFAILED               = &HC020209D&

' //
' //   MessageId: DTS_E_DISKIOTIMEDOUT
' //
' //   MessageText:
' //
' //    An disk I/O time out occurred while reading the file.
' //
%DTS_E_DISKIOTIMEDOUT             = &HC020209E&

' //
' //   MessageId: DTS_E_INPUTSNOTREADONLY
' //
' //   MessageText:
' //
' //    The Usage Type specified for the input columns to this transform cannot be read/write. Change the Usage Type to be read-only.
' //
%DTS_E_INPUTSNOTREADONLY          = &HC020209F&

' //
' //   MessageId: DTS_E_CANNOTCOPYORCONVERTFLATFILEDATA
' //
' //   MessageText:
' //
' //    Cannot copy or convert flat file data for column "%1!s!".
' //
%DTS_E_CANNOTCOPYORCONVERTFLATFILEDATA = &HC02020A0&

' //
' //   MessageId: DTS_E_FAILEDCOLUMNDATACONVERSIONSTATUS
' //
' //   MessageText:
' //
' //    Data conversion failed. The data conversion for column "%1!s!" returned status value %2!d! and status text "%3!s!".
' //
%DTS_E_FAILEDCOLUMNDATACONVERSIONSTATUS = &HC02020A1&

' //
' //   MessageId: DTS_E_VARIABLESCOLLECTIONUNAVAILABLE
' //
' //   MessageText:
' //
' //    The Variables collection is not available.
' //
%DTS_E_VARIABLESCOLLECTIONUNAVAILABLE = &HC02020A2&

' //
' //   MessageId: DTS_E_TXUNPIVOTDUPLICATEPIVOTKEYVALUE
' //
' //   MessageText:
' //
' //    Duplicate PivotKeyValue. Input column "%1!s!" (%2!d!) is mapped to a Pivoted Value output column and has a non-unique PivotKeyValue.
' //
%DTS_E_TXUNPIVOTDUPLICATEPIVOTKEYVALUE = &HC02020A3&

' //
' //   MessageId: DTS_E_TXUNPIVOTNOUNPIVOTDESTINATION
' //
' //   MessageText:
' //
' //    No unpivot destination found. At least one input column must be mapped with a PivotKeyValue to an DestinationColumn in the output.
' //
%DTS_E_TXUNPIVOTNOUNPIVOTDESTINATION = &HC02020A4&

' //
' //   MessageId: DTS_E_TXUNPIVOTBADKEYLIST
' //
' //   MessageText:
' //
' //    PivotKeyValue is not valid. In an UnPivot transform with more than one unpivoted DestinationColumn, the set of PivotKeyValues per destination must match exactly.
' //
%DTS_E_TXUNPIVOTBADKEYLIST        = &HC02020A5&

' //
' //   MessageId: DTS_E_TXUNPIVOTBADUNPIVOTMETADATA
' //
' //   MessageText:
' //
' //    Incorrect UnPivot metadata. In an UnPivot transform, all input columns with a PivotKeyValue that is set, and are pointing to the same DestinationColumn, must have metadata that exactly matches the DestinationColumn.
' //
%DTS_E_TXUNPIVOTBADUNPIVOTMETADATA = &HC02020A6&

' //
' //   MessageId: DTS_E_TXPIVOTBADPIVOTKEYCONVERT
' //
' //   MessageText:
' //
' //    Cannot convert the pivot key value "%1!s!" to the data type of the pivot key column.
' //
%DTS_E_TXPIVOTBADPIVOTKEYCONVERT  = &HC02020A7&

' //
' //   MessageId: DTS_E_TXUNPIVOTTOOMANYPIVOTKEYS
' //
' //   MessageText:
' //
' //    Too many Pivot Keys specified. Only one output column can be used as the Pivot Key.
' //
%DTS_E_TXUNPIVOTTOOMANYPIVOTKEYS  = &HC02020A8&

' //
' //   MessageId: DTS_E_TXUNPIVOTUNMAPPEDOUTPUT
' //
' //   MessageText:
' //
' //    Output column "%1!s!" (%2!d!) is not mapped by any input column's DestinationColumn property.
' //
%DTS_E_TXUNPIVOTUNMAPPEDOUTPUT    = &HC02020A9&

' //
' //   MessageId: DTS_E_TXUNPIVOTNOPIVOT
' //
' //   MessageText:
' //
' //    No output column is marked as the PivotKey.
' //
%DTS_E_TXUNPIVOTNOPIVOT           = &HC02020AA&

' //
' //   MessageId: DTS_E_TXUNPIVOTNOTINPUTMAP
' //
' //   MessageText:
' //
' //    Input column "%1!s!" (%2!d!) has a DestinationColumn property value that does not refer to a valid output column LineageID.
' //
%DTS_E_TXUNPIVOTNOTINPUTMAP       = &HC02020AB&

' //
' //   MessageId: DTS_E_TXUNPIVOTDUPLICATEDESTINATION
' //
' //   MessageText:
' //
' //    Duplicate destination error. More than one non-pivoted input column is mapped to the same destination output column.
' //
%DTS_E_TXUNPIVOTDUPLICATEDESTINATION = &HC02020AC&

' ////////////////////////////////////////////////////////////////////////////
' //   This happens when no input columns have been mapped to output columns.

' //
' //   MessageId: DTS_E_TOTALINPUTCOLSCANNOTBEZERO
' //
' //   MessageText:
' //
' //    No input columns found. At least one input column must be mapped to an output column.
' //
%DTS_E_TOTALINPUTCOLSCANNOTBEZERO = &HC02020AD&

' //
' //   MessageId: DTS_E_TXMERGEJOINMUSTHAVESAMENUMBEROFINPUTANDOUTPUTCOLS
' //
' //   MessageText:
' //
' //    The number of input and output columns are not equal. The total number of input columns on all inputs must be the same as the total number of output columns.
' //
%DTS_E_TXMERGEJOINMUSTHAVESAMENUMBEROFINPUTANDOUTPUTCOLS = &HC02020AE&

' //
' //   MessageId: DTS_E_INPUTMUSTBESORTED
' //
' //   MessageText:
' //
' //    The input is not sorted. The "%1!s!" must be sorted.
' //
%DTS_E_INPUTMUSTBESORTED          = &HC02020AF&

' //
' //   MessageId: DTS_E_TXMERGEJOININVALIDJOINTYPE
' //
' //   MessageText:
' //
' //    The JoinType custom property for the %1!s! contains a value of %2!ld!, which is not valid. Valid values are 0 (ful&, 1 (left), or 2 (inner).
' //
%DTS_E_TXMERGEJOININVALIDJOINTYPE = &HC02020B0&

' //
' //   MessageId: DTS_E_TXMERGEJOININVALIDNUMKEYCOLS
' //
' //   MessageText:
' //
' //    The NumKeyColumns value is not valid. In the %1!s!, the value for the NumKeyColumns custom property must be between 1 and %2!lu!.
' //
%DTS_E_TXMERGEJOININVALIDNUMKEYCOLS = &HC02020B1&

' //
' //   MessageId: DTS_E_NOKEYCOLS
' //
' //   MessageText:
' //
' //    No key columns are found. The %1!s! must have at least one column with a SortKeyPosition that is non-zero.
' //
%DTS_E_NOKEYCOLS                  = &HC02020B2&

' //
' //   MessageId: DTS_E_TXMERGEJOINNOTENOUGHKEYCOLS
' //
' //   MessageText:
' //
' //    Not enough key columns. The %1!s! must have at least %2!ld! columns with non-zero SortKeyPosition values.
' //
%DTS_E_TXMERGEJOINNOTENOUGHKEYCOLS = &HC02020B3&

' //
' //   MessageId: DTS_E_TXMERGEJOINDATATYPEMISMATCH
' //
' //   MessageText:
' //
' //    Datatype mismatch occurred. The datatypes for the columns with SortKeyPosition value %1!ld! do not match.
' //
%DTS_E_TXMERGEJOINDATATYPEMISMATCH = &HC02020B4&

' //
' //   MessageId: DTS_E_TXMERGEJOININVALIDSORTKEYPOS
' //
' //   MessageText:
' //
' //    The column with the SortKeyPosition value of %1!ld! is not valid. It should be %2!ld!.
' //
%DTS_E_TXMERGEJOININVALIDSORTKEYPOS = &HC02020B5&

' //
' //   MessageId: DTS_E_TXMERGEJOINSORTDIRECTIONMISMATCH
' //
' //   MessageText:
' //
' //    Sort direction mismatch. The sort directions for the columns with SortKeyPosition value %1!ld! do not match.
' //
%DTS_E_TXMERGEJOINSORTDIRECTIONMISMATCH = &HC02020B6&

' //
' //   MessageId: DTS_E_TXMERGEJOINOUTPUTCOLMUSTHAVEASSOCIATEDINPUTCOL
' //
' //   MessageText:
' //
' //    Missing column. The %1!s! must have an associated input column.
' //
%DTS_E_TXMERGEJOINOUTPUTCOLMUSTHAVEASSOCIATEDINPUTCOL = &HC02020B7&

' //
' //   MessageId: DTS_E_TXMERGEJOINREADONLYINPUTCOLSWITHNOOUTPUTCOL
' //
' //   MessageText:
' //
' //    Input columns must have ouput columns. There are input columns with a usage type of read-only that do not have associated output columns.
' //
%DTS_E_TXMERGEJOINREADONLYINPUTCOLSWITHNOOUTPUTCOL = &HC02020B8&

' //
' //   MessageId: DTS_E_TXMERGEJOINNONSTRINGCOMPARISONFLAGSNOTZERO
' //
' //   MessageText:
' //
' //    The comparison flags are not zero. The comparison flags for non-string columns must be zero.
' //
%DTS_E_TXMERGEJOINNONSTRINGCOMPARISONFLAGSNOTZERO = &HC02020B9&

' //
' //   MessageId: DTS_E_TXMERGEJOINCOMPARISONFLAGSMISMATCH
' //
' //   MessageText:
' //
' //    The comparison flags for the columns with SortKeyPosition value %1!ld! do not match.
' //
%DTS_E_TXMERGEJOINCOMPARISONFLAGSMISMATCH = &HC02020BA&

' //
' //   MessageId: DTS_E_TXPIVOTBADPIVOTKEYVALUENOSTRING
' //
' //   MessageText:
' //
' //    Unrecognized pivot key value.
' //
%DTS_E_TXPIVOTBADPIVOTKEYVALUENOSTRING = &HC02020BB&

' //
' //   MessageId: DTS_E_TXLINEAGEINVALIDLINEAGEITEM
' //
' //   MessageText:
' //
' //    Lineage item value %1!ld! is not valid. The valid range is between %2!ld! and %3!ld!.
' //
%DTS_E_TXLINEAGEINVALIDLINEAGEITEM = &HC02020BC&

' //
' //   MessageId: DTS_E_CANNOTHAVEANYINPUTCOLUMNS
' //
' //   MessageText:
' //
' //    Input columns not allowed. The number of input columns must be zero.
' //
%DTS_E_CANNOTHAVEANYINPUTCOLUMNS  = &HC02020BD&

' //
' //   MessageId: DTS_E_TXLINEAGEDATATYPEMISMATCH
' //
' //   MessageText:
' //
' //    The datatype for "%1!s!" is not valid for the specified lineage item.
' //
%DTS_E_TXLINEAGEDATATYPEMISMATCH  = &HC02020BE&

' //
' //   MessageId: DTS_E_TXLINEAGEINVALIDLENGTH
' //
' //   MessageText:
' //
' //    The length for "%1!s!" is not valid for the specified lineage item.
' //
%DTS_E_TXLINEAGEINVALIDLENGTH     = &HC02020BF&

' ////////////////////////////////////////////////////////////////////////////
' //   The input column's metadata does not match the metadata of the output column it is associated with.

' //
' //   MessageId: DTS_E_METADATAMISMATCHWITHOUTPUTCOLUMN
' //
' //   MessageText:
' //
' //    The metadata for "%1!s!" does not match the metadata for the associated output column.
' //
%DTS_E_METADATAMISMATCHWITHOUTPUTCOLUMN = &HC02020C1&

' //
' //   MessageId: DTS_E_TXMERGESORTKEYPOSMISMATCH
' //
' //   MessageText:
' //
' //    There are output columns that have SortKeyPosition values that don't match the associated input columns' SortKeyPosition.
' //
%DTS_E_TXMERGESORTKEYPOSMISMATCH  = &HC02020C3&

' //
' //   MessageId: DTS_E_ADDROWTOBUFFERFAILED
' //
' //   MessageText:
' //
' //    The attempt to add a row to the Data Flow task buffer failed with error code 0x%1!8.8X!.
' //
%DTS_E_ADDROWTOBUFFERFAILED       = &HC02020C4&

' //
' //   MessageId: DTS_E_DATACONVERSIONFAILED
' //
' //   MessageText:
' //
' //    Data conversion failed while converting column "%1!s!" (%2!d!) to column "%3!s!" (%4!d!).  The conversion returned status value %5!d! and status text "%6!s!".
' //
%DTS_E_DATACONVERSIONFAILED       = &HC02020C5&

' //
' //   MessageId: DTS_E_FAILEDTOALLOCATEROWHANDLEBUFFER
' //
' //   MessageText:
' //
' //    The attempt to allocate a row handle buffer failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOALLOCATEROWHANDLEBUFFER = &HC02020C6&

' //
' //   MessageId: DTS_E_FAILEDTOSENDROWTOSQLSERVER
' //
' //   MessageText:
' //
' //    The attempt to send a row to SQL Server failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOSENDROWTOSQLSERVER = &HC02020C7&

' //
' //   MessageId: DTS_E_FAILEDTOPREPAREBUFFERSTATUS
' //
' //   MessageText:
' //
' //    The attempt to prepare the buffer status failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOPREPAREBUFFERSTATUS = &HC02020C8&

' //
' //   MessageId: DTS_E_FAILEDTOBUFFERROWSTARTS
' //
' //   MessageText:
' //
' //    The attempt to retrieve the start of the buffer row failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOBUFFERROWSTARTS    = &HC02020C9&

' ////////////////////////////////////////////////////////////////////////////
' //   Try increasing the bulk insert thread timeout.

' //
' //   MessageId: DTS_E_BULKINSERTTHREADTERMINATED
' //
' //   MessageText:
' //
' //    The thread for the SSIS Bulk Insert is no longer running.  No more rows can be inserted. Try increasing the bulk insert thread timeout.
' //
%DTS_E_BULKINSERTTHREADTERMINATED = &HC02020CA&

' ////////////////////////////////////////////////////////////////////////////
' //   The source file wasn't produced by the raw file destination.

' //
' //   MessageId: DTS_E_RAWTOOMANYCOLUMNS
' //
' //   MessageText:
' //
' //    The source file is not valid. The source file is returning a count of more than 131,072 columns. This usually occurs when the source file is not produced by the raw file destination.
' //
%DTS_E_RAWTOOMANYCOLUMNS          = &HC02020CB&

' //
' //   MessageId: DTS_E_TXUNIONALL_EXTRADANGLINGINPUT
' //
' //   MessageText:
' //
' //    The %1!s! is an extra unattached input and will be removed.
' //
%DTS_E_TXUNIONALL_EXTRADANGLINGINPUT = &HC02020CC&

' //
' //   MessageId: DTS_E_TXUNIONALL_NONDANGLINGUNATTACHEDINPUT
' //
' //   MessageText:
' //
' //    The %1!s! is not attached but is not marked as dangling.  It will be marked as dangling.
' //
%DTS_E_TXUNIONALL_NONDANGLINGUNATTACHEDINPUT = &HC02020CD&

' //
' //   MessageId: DTS_E_TXPIVOTRUNTIMEDUPLICATEPIVOTKEYVALUE
' //
' //   MessageText:
' //
' //    Duplicate pivot key value "%1!s!".
' //
%DTS_E_TXPIVOTRUNTIMEDUPLICATEPIVOTKEYVALUE = &HC02020CF&

' //
' //   MessageId: DTS_E_TXPIVOTRUNTIMEDUPLICATEPIVOTKEYVALUENOSTRING
' //
' //   MessageText:
' //
' //    Duplicate pivot key value.
' //
%DTS_E_TXPIVOTRUNTIMEDUPLICATEPIVOTKEYVALUENOSTRING = &HC02020D0&

' //
' //   MessageId: DTS_E_FAILEDTOGETCOMPONENTLOCALEID
' //
' //   MessageText:
' //
' //    Failure retrieving component locale ID. Error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOGETCOMPONENTLOCALEID = &HC02020D1&

' //
' //   MessageId: DTS_E_MISMATCHCOMPONENTCONNECTIONMANAGERLOCALEID
' //
' //   MessageText:
' //
' //    Mismatched locale IDs. The component locale ID (%1!d!) does not match the connection manager locale ID (%2!d!).
' //
%DTS_E_MISMATCHCOMPONENTCONNECTIONMANAGERLOCALEID = &HC02020D2&

' ////////////////////////////////////////////////////////////////////////////
' //   Flat file adapters need to have the locale ID on the flat file connection manager set

' //
' //   MessageId: DTS_E_LOCALEIDNOTSET
' //
' //   MessageText:
' //
' //    The component locale ID has not been set. Flat file adapters need to have the locale ID on the flat file connection manager set.
' //
%DTS_E_LOCALEIDNOTSET             = &HC02020D3&

' ////////////////////////////////////////////////////////////////////////////
' //   Corrupt input file. The file showed a string length that was too big for the buffer column we've got.

' //
' //   MessageId: DTS_E_RAWBYTESTOOLONG
' //
' //   MessageText:
' //
' //   The binary field is too large. The adapter attempted to read a binary field that was %1!d! bytes long, but expected a field no longer than %2!d! bytes at offset %3!d!. This usually occurs when the input file is not valid.
' //   The file contains a string length that is too large for the buffer column.
' //
%DTS_E_RAWBYTESTOOLONG            = &HC02020D4&

' //
' //   MessageId: DTS_E_TXSAMPLINGINVALIDPCT
' //
' //   MessageText:
' //
' //    The percentage, %2!ld!, is not valid for the "%1!s!" property. It must be between 0 and 100.
' //
%DTS_E_TXSAMPLINGINVALIDPCT       = &HC02020D5&

' //
' //   MessageId: DTS_E_TXSAMPLINGINVALIDROWS
' //
' //   MessageText:
' //
' //    The number of rows, %2!ld!, is not valid for the "%1!s!" property. It must be greater than 0.
' //
%DTS_E_TXSAMPLINGINVALIDROWS      = &HC02020D6&

' ////////////////////////////////////////////////////////////////////////////
' //   Somehow, a very long string entered the pipeline.

' //
' //   MessageId: DTS_E_RAWSTRINGINPUTTOOLONG
' //
' //   MessageText:
' //
' //    The adapter was asked to write a string that was %1!I64d! bytes long, but all data must be less than 4294967295 bytes in length.
' //
%DTS_E_RAWSTRINGINPUTTOOLONG      = &HC02020D7&

' ////////////////////////////////////////////////////////////////////////////
' //   This happens when no input columns have been mapped to output columns.

' //
' //   MessageId: DTS_E_ATLEASTONEINPUTMUSTBEMAPPEDTOOUTPUT
' //
' //   MessageText:
' //
' //    No inputs were mapped to an output. The "%1!s!" must have at least one input column mapped to an output column.
' //
%DTS_E_ATLEASTONEINPUTMUSTBEMAPPEDTOOUTPUT = &HC02020D9&

' //
' //   MessageId: DTS_E_CANNOTCONVERTDATATYPESWITHDIFFERENTCODEPAGES
' //
' //   MessageText:
' //
' //    Conversion from "%1!s!" with code page %2!d! to "%3!s!" with code page %4!d! is not supported.
' //
%DTS_E_CANNOTCONVERTDATATYPESWITHDIFFERENTCODEPAGES = &HC02020DB&

' //
' //   MessageId: DTS_E_COLUMNNOTMAPPEDTOEXTERNALMETADATACOLUMN
' //
' //   MessageText:
' //
' //    The external metadata column mapping for %1!s! is not valid.  The external metadata column ID cannot be zero.
' //
%DTS_E_COLUMNNOTMAPPEDTOEXTERNALMETADATACOLUMN = &HC02020DC&

' //
' //   MessageId: DTS_E_COLUMNMAPPEDTONONEXISTENTEXTERNALMETADATACOLUMN
' //
' //   MessageText:
' //
' //    The %1!s! is mapped to an external metadata column that does not exist.
' //
%DTS_E_COLUMNMAPPEDTONONEXISTENTEXTERNALMETADATACOLUMN = &HC02020DD&

' //
' //   MessageId: DTS_E_UNABLETOWRITELOBDATATOBUFFER
' //
' //   MessageText:
' //
' //    Writing long object data of type DT_TEXT, DT_NTEXT, or DT_IMAGE to Data Flow task buffer failed for column "%1!s!".
' //
%DTS_E_UNABLETOWRITELOBDATATOBUFFER = &HC02020E5&

' ////////////////////////////////////////////////////////////////////////////
' //   Check that the object exists in the database.

' //
' //   MessageId: DTS_E_CANNOTGETIROWSET
' //
' //   MessageText:
' //
' //    Opening a rowset for "%1!s!" failed. Check that the object exists in the database.
' //
%DTS_E_CANNOTGETIROWSET           = &HC02020E8&

' //
' //   MessageId: DTS_E_VARIABLEACCESSFAILED
' //
' //   MessageText:
' //
' //    Acessing variable "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_VARIABLEACCESSFAILED       = &HC02020E9&

' ////////////////////////////////////////////////////////////////////////////
' //   A component failed to find the CM in Connections collection.

' //
' //   MessageId: DTS_E_CONNECTIONMANAGERNOTFOUND
' //
' //   MessageText:
' //
' //    The connection manager "%1!s!" is not found. A component failed to find the connection manager in the Connections collection.
' //
%DTS_E_CONNECTIONMANAGERNOTFOUND  = &HC02020EA&

' //
' //   MessageId: DTS_E_VERSIONUPGRADEFAILED
' //
' //   MessageText:
' //
' //    The upgrade from version "%1!s!" to version %2!d! failed.
' //
%DTS_E_VERSIONUPGRADEFAILED       = &HC02020EB&

' //
' //   MessageId: DTS_E_RSTDESTBIGBLOB
' //
' //   MessageText:
' //
' //    A value in an input column is too large to be stored in the ADODB.Recordset object.
' //
%DTS_E_RSTDESTBIGBLOB             = &HC02020EC&

' //
' //   MessageId: DTS_E_CANNOTCONVERTBETWEENUNICODEANDNONUNICODESTRINGCOLUMNS
' //
' //   MessageText:
' //
' //    Columns "%1!s!" and "%2!s!" cannot convert between unicode and non-unicode string data types.
' //
%DTS_E_CANNOTCONVERTBETWEENUNICODEANDNONUNICODESTRINGCOLUMNS = &HC02020ED&

' ////////////////////////////////////////////////////////////////////////////
' //   Need a runtime variable name to write to

' //
' //   MessageId: DTS_E_ROWCOUNTBADVARIABLENAME
' //
' //   MessageText:
' //
' //    The variable "%1!s!" specified by VariableName property is not a valid variable. Need a valid variable name to write to.
' //
%DTS_E_ROWCOUNTBADVARIABLENAME    = &HC02020EE&

' ////////////////////////////////////////////////////////////////////////////
' //   Need the runtime variable to be of type VT_I4, VT_UI4, VT_I8 or VT_UI8

' //
' //   MessageId: DTS_E_ROWCOUNTBADVARIABLETYPE
' //
' //   MessageText:
' //
' //    The variable "%1!s!" specified by VariableName property is not an integer. Change the variable to be of type VT_I4, VT_UI4, VT_I8, or VT_UI8.
' //
%DTS_E_ROWCOUNTBADVARIABLETYPE    = &HC02020EF&

' //
' //   MessageId: DTS_E_NOCOLUMNADVANCETHROUGHFILE
' //
' //   MessageText:
' //
' //    No column was specified to allow the component to advance through the file.
' //
%DTS_E_NOCOLUMNADVANCETHROUGHFILE = &HC02020F0&

' //
' //   MessageId: DTS_E_MERGEJOINSORTEDOUTPUTHASNOSORTKEYPOSITIONS
' //
' //   MessageText:
' //
' //    The "%1!s!" has IsSorted set to TRUE, but the SortKeyPosition on all output columns are zero. Either change the IsSorted to FALSE, or select at least one output column to contain a non-zero SortKeyPosition.
' //
%DTS_E_MERGEJOINSORTEDOUTPUTHASNOSORTKEYPOSITIONS = &HC02020F1&

' ////////////////////////////////////////////////////////////////////////////
' //   The input column's metadata does not match the metadata of the output column it is associated with.

' //
' //   MessageId: DTS_E_METADATAMISMATCHWITHINPUTCOLUMN
' //
' //   MessageText:
' //
' //    The "%1!s!" metadata does not match the metadata of the input column.
' //
%DTS_E_METADATAMISMATCHWITHINPUTCOLUMN = &HC02020F2&

' //
' //   MessageId: DTS_E_RSTDESTBADVARIABLE
' //
' //   MessageText:
' //
' //    The value of the specified variable cannot be located, locked, or set.
' //
%DTS_E_RSTDESTBADVARIABLE         = &HC02020F3&

' //
' //   MessageId: DTS_E_CANTPROCESSCOLUMNTYPECODEPAGE
' //
' //   MessageText:
' //
' //    The column "%1!s!" cannot be processed because more than one code page (%2!d! and %3!d!) are specified for it.
' //
%DTS_E_CANTPROCESSCOLUMNTYPECODEPAGE = &HC02020F4&

' //
' //   MessageId: DTS_E_CANTINSERTCOLUMNTYPE
' //
' //   MessageText:
' //
' //    The column "%1!s!" can't be inserted because the conversion between types %2!s! and %3!s! is not supported.
' //
%DTS_E_CANTINSERTCOLUMNTYPE       = &HC02020F5&

' //
' //   MessageId: DTS_E_CANNOTCONVERTBETWEENUNICODEANDNONUNICODESTRINGCOLUMN
' //
' //   MessageText:
' //
' //    Column "%1!s!" cannot convert between unicode and non-unicode string data types.
' //
%DTS_E_CANNOTCONVERTBETWEENUNICODEANDNONUNICODESTRINGCOLUMN = &HC02020F6&

' //
' //   MessageId: DTS_E_COULDNOTFINDINPUTBUFFERCOLUMNBYLINEAGE
' //
' //   MessageText:
' //
' //    The %1!s! cannot find the column with LineageID %2!ld! in its input buffer.
' //
%DTS_E_COULDNOTFINDINPUTBUFFERCOLUMNBYLINEAGE = &HC02020F8&

' //
' //   MessageId: DTS_E_COULDNOTGETCOLUMNINFOFORINPUTBUFFER
' //
' //   MessageText:
' //
' //    The %1!s! cannot get the column information for column %2!lu! from its input buffer.
' //
%DTS_E_COULDNOTGETCOLUMNINFOFORINPUTBUFFER = &HC02020F9&

' //
' //   MessageId: DTS_E_COULDNOTGETCOLUMNINFOFORCOPYBUFFER
' //
' //   MessageText:
' //
' //    The %1!s! cannot get the column information for column "%2!lu!" from its copy buffer.
' //
%DTS_E_COULDNOTGETCOLUMNINFOFORCOPYBUFFER = &HC02020FA&

' //
' //   MessageId: DTS_E_COULDNOTREGISTERCOPYBUFFER
' //
' //   MessageText:
' //
' //    The %1!s! cannot register a buffer type for its copy buffer.
' //
%DTS_E_COULDNOTREGISTERCOPYBUFFER = &HC02020FB&

' //
' //   MessageId: DTS_E_COULDNOTCREATECOPYBUFFER
' //
' //   MessageText:
' //
' //    The %1!s! cannot create a buffer to copy its data into for sorting.
' //
%DTS_E_COULDNOTCREATECOPYBUFFER   = &HC02020FC&

' //
' //   MessageId: DTS_E_DATAREADERDESTREADFAILED
' //
' //   MessageText:
' //
' //    DataReader client has failed to call Read or has closed the DataReader.
' //
%DTS_E_DATAREADERDESTREADFAILED   = &HC02020FD&

' ////////////////////////////////////////////////////////////////////////////
' //   The property being set is not supported on the specified object. Check the property name, case, and spelling.

' //
' //   MessageId: DTS_E_PROPERTYNOTSUPPORTED
' //
' //   MessageText:
' //
' //    The property "%1!s!" cannot be set on "%2!s!". The property being set is not supported on the specified object. Check the property name, case, and spelling.
' //
%DTS_E_PROPERTYNOTSUPPORTED       = &HC0204000&

' //
' //   MessageId: DTS_E_CANTCHANGEPROPERTYTYPE
' //
' //   MessageText:
' //
' //    The property type cannot be changed from the type that was set by the component.
' //
%DTS_E_CANTCHANGEPROPERTYTYPE     = &HC0204002&

' ////////////////////////////////////////////////////////////////////////////
' //   Inserting the output failed.  The new output was not created.

' //
' //   MessageId: DTS_E_CANTADDOUTPUTID
' //
' //   MessageText:
' //
' //    Output ID %1!d! failed during insert. The new output was not created.
' //
%DTS_E_CANTADDOUTPUTID            = &HC0204003&

' ////////////////////////////////////////////////////////////////////////////
' //   The output could not be deleted from the output collection.  The ID might have been invalid, or it might have been the default or error output.

' //
' //   MessageId: DTS_E_CANTDELETEOUTPUTID
' //
' //   MessageText:
' //
' //    Cannot delete output ID %1!d! from the output collection.  The ID may not be valid, or the ID may have been the default or error output.
' //
%DTS_E_CANTDELETEOUTPUTID         = &HC0204004&

' ////////////////////////////////////////////////////////////////////////////
' //   The property could not be set for an unknown reason.

' //
' //   MessageId: DTS_E_FAILEDTOSETPROPERTY
' //
' //   MessageText:
' //
' //    Failed to set property "%1!s!" on "%2!s!".
' //
%DTS_E_FAILEDTOSETPROPERTY        = &HC0204006&

' ////////////////////////////////////////////////////////////////////////////
' //   Failed to set the type of the output column to the result type of the expression on the column.

' //
' //   MessageId: DTS_E_FAILEDTOSETOUTPUTCOLUMNTYPE
' //
' //   MessageText:
' //
' //    Failed to set the type of %1!s! to type: "%2!s!", length: %3!d!, precision: %4!d!, scale: %5!d!, codepage: %6!d!.
' //
%DTS_E_FAILEDTOSETOUTPUTCOLUMNTYPE = &HC0204007&

' //
' //   MessageId: DTS_E_MORETHANONEERROROUTPUTFOUND
' //
' //   MessageText:
' //
' //    More than one error output was found on the component, and there can be only one.
' //
%DTS_E_MORETHANONEERROROUTPUTFOUND = &HC0204008&

' //
' //   MessageId: DTS_E_CANTSETOUTPUTCOLUMNPROPERTY
' //
' //   MessageText:
' //
' //    The property on an output column cannot be set.
' //
%DTS_E_CANTSETOUTPUTCOLUMNPROPERTY = &HC020400A&

' //
' //   MessageId: DTS_E_CANTMODIFYERROROUTPUTCOLUMNDATATYPE
' //
' //   MessageText:
' //
' //    The data type for "%1!s!" cannot be modified in the error "%2!s!".
' //
%DTS_E_CANTMODIFYERROROUTPUTCOLUMNDATATYPE = &HC020400B&


' ////////////////////////////////////////////////////////////////////////////
' //   A source output has a SynchronousInputID value of zero.

' //
' //   MessageId: DTS_E_CANONLYSETISSORTEDONSOURCE
' //
' //   MessageText:
' //
' //    The "%1!s!" cannot have its IsSorted property set to TRUE because it is not a source output. A source output has a SynchronousInputID value of zero.
' //
%DTS_E_CANONLYSETISSORTEDONSOURCE = &HC020400E&

' ////////////////////////////////////////////////////////////////////////////
' //   The output column "colname" (ID) cannot have its SortKeyPosition property set to non-zero because its output "outputname" (ID) is not a source output.

' //
' //   MessageId: DTS_E_CANONLYSETSORTKEYONSOURCE
' //
' //   MessageText:
' //
' //    The "%1!s!" cannot have a SortKeyPosition property set to non-zero because "%2!s!" is not a source output. The output column "colname" (ID) cannot have its SortKeyPosition property set to non-zero because
' //    its output "outputname" (ID) is not a source output.
' //
%DTS_E_CANONLYSETSORTKEYONSOURCE  = &HC020400F&

' ////////////////////////////////////////////////////////////////////////////
' //   The output column "colname" (ID) cannot have its ComparisonFlags property set to non-zero because its output "outputname" (ID) is not a source output.

' //
' //   MessageId: DTS_E_CANONLYSETCOMPFLAGSONSOURCE
' //
' //   MessageText:
' //
' //    The ComparisonFlags property cannot be set to a non-zero value for "%1!s!" because the "%2!s!" is not a source output. The output column "colname" (ID) cannot have a ComparisonFlags property set to non-zero because
' //    its output "outputname" (ID) is not a source output.
' //
%DTS_E_CANONLYSETCOMPFLAGSONSOURCE = &HC0204010&

' ////////////////////////////////////////////////////////////////////////////
' //   ComparisonFlags can only be non zero for string type columns.

' //
' //   MessageId: DTS_E_NONSTRINGCOMPARISONFLAGSNOTZERO
' //
' //   MessageText:
' //
' //    The comparison flags for "%1!s!" must be zero because its type is not a string type. ComparisonFlags can only be non-zero for string type columns.
' //
%DTS_E_NONSTRINGCOMPARISONFLAGSNOTZERO = &HC0204011&

' ////////////////////////////////////////////////////////////////////////////
' //   An output column's ComparisonFlags can only be non-zero if its SortKeyPosition is also non zero.

' //
' //   MessageId: DTS_E_COMPFLAGSONLYONSORTCOL
' //
' //   MessageText:
' //
' //    The "%1!s!" cannot have a ComparisonFlags property set to non-zero because its SortKeyPosition is set to zero. An output column's ComparisonFlags can only be non-zero if its SortKeyPosition is also non-zero.
' //
%DTS_E_COMPFLAGSONLYONSORTCOL     = &HC0204012&

' //
' //   MessageId: DTS_E_READONLYSTOCKPROPERTY
' //
' //   MessageText:
' //
' //    The property is read-only.
' //
%DTS_E_READONLYSTOCKPROPERTY      = &HC0204013&

' //
' //   MessageId: DTS_E_INVALIDDATATYPE
' //
' //   MessageText:
' //
' //    The %1!s! had an invalid datatype value (%2!ld!) set.
' //
%DTS_E_INVALIDDATATYPE            = &HC0204014&

' //
' //   MessageId: DTS_E_CODEPAGEREQUIRED
' //
' //   MessageText:
' //
' //    The "%1!s!" requires a code page to be set but the value passed was zero.
' //
%DTS_E_CODEPAGEREQUIRED           = &HC0204015&

' //
' //   MessageId: DTS_E_INVALIDSTRINGLENGTH
' //
' //   MessageText:
' //
' //    The "%1!s!" has a length that is not valid. The length must be between %2!ld! and %3!ld!.
' //
%DTS_E_INVALIDSTRINGLENGTH        = &HC0204016&

' //
' //   MessageId: DTS_E_INVALIDSCALE
' //
' //   MessageText:
' //
' //    The "%1!s!" has a scale that is not valid. The scale must be between %2!ld! and %3!ld!.
' //
%DTS_E_INVALIDSCALE               = &HC0204017&

' //
' //   MessageId: DTS_E_INVALIDPRECISION
' //
' //   MessageText:
' //
' //    The "%1!s!" has a precision that is not valid. The precision must be between %2!ld! and %3!ld!.
' //
%DTS_E_INVALIDPRECISION           = &HC0204018&

' //
' //   MessageId: DTS_E_PROPVALUEIGNORED
' //
' //   MessageText:
' //
' //    The "%1!s!" has a value set for length, precision, scale, or code page that is a value other than zero, but the data type requires the value to be zero.
' //
%DTS_E_PROPVALUEIGNORED           = &HC0204019&

' //
' //   MessageId: DTS_E_CANTSETOUTPUTCOLUMNDATATYPEPROPERTIES
' //
' //   MessageText:
' //
' //    The %1!s! does not allow setting output column datatype properties.
' //
%DTS_E_CANTSETOUTPUTCOLUMNDATATYPEPROPERTIES = &HC020401A&

' //
' //   MessageId: DTS_E_INVALIDDATATYPEFORERRORCOLUMNS
' //
' //   MessageText:
' //
' //    The "%1!s!" contains an invalid data type. "%1!s! " is a special error column,  and the only valid data type is DT_I4.
' //
%DTS_E_INVALIDDATATYPEFORERRORCOLUMNS = &HC020401B&

' //
' //   MessageId: DTS_E_NOERRORDESCFORCOMPONENT
' //
' //   MessageText:
' //
' //    The component does not supply error code descriptions.
' //
%DTS_E_NOERRORDESCFORCOMPONENT    = &HC020401C&

' //
' //   MessageId: DTS_E_UNRECOGNIZEDERRORCODE
' //
' //   MessageText:
' //
' //    The specified error code is not associated with this component.
' //
%DTS_E_UNRECOGNIZEDERRORCODE      = &HC020401D&

' //
' //   MessageId: DTS_E_TRUNCATIONTRIGGEREDREDIRECTION
' //
' //   MessageText:
' //
' //    A truncation caused a row to be redirected, based on the truncation disposition settings.
' //
%DTS_E_TRUNCATIONTRIGGEREDREDIRECTION = &HC020401F&

' ////////////////////////////////////////////////////////////////////////////
' //   A attempt was made to change the usage type of an input column to a type (UT_READWRITE) that is not supported on this component.

' //
' //   MessageId: DTS_E_CANTSETUSAGETYPETOREADWRITE
' //
' //   MessageText:
' //
' //    The "%1!s!" is unable to make the column with lineage ID %2!d! read/write because that usage type is not allowed on this column. An attempt was made to change the usage type of an input column to a type,
' //    UT_READWRITE, that is not supported on this component.
' //
%DTS_E_CANTSETUSAGETYPETOREADWRITE = &HC0204020&

' ////////////////////////////////////////////////////////////////////////////
' //   An attempt was made to set the usage type of an input column to a type that is not allowed on this component.

' //
' //   MessageId: DTS_E_CANTSETUSAGETYPE
' //
' //   MessageText:
' //
' //    The %1!s! has forbidden the requested use of the input column with lineage ID %2!d!.
' //
%DTS_E_CANTSETUSAGETYPE           = &HC0204023&

' ////////////////////////////////////////////////////////////////////////////
' //   The specified error occurred while attempting to set the usage type of an input column.

' //
' //   MessageId: DTS_E_FAILEDTOSETUSAGETYPE
' //
' //   MessageText:
' //
' //    The "%1!s!" was unable to make the requested change to the input column with lineage ID %2!d!. The request failed with error code 0x%3!8.8X!. The specified error occurred while attempting to set the usage type of an input column.
' //
%DTS_E_FAILEDTOSETUSAGETYPE       = &HC0204024&

' ////////////////////////////////////////////////////////////////////////////
' //   The specified error occurred while attempting to set one or more of the data type properties of the output column.

' //
' //   MessageId: DTS_E_FAILEDTOSETOUTPUTCOLUMNDATATYPEPROPERTIES
' //
' //   MessageText:
' //
' //    Attempt to set the data type properties on "%1!s!" failed with error code 0x%2!8.8X!. The error occurred while attempting to set one or more of the data type properties of the output column.
' //
%DTS_E_FAILEDTOSETOUTPUTCOLUMNDATATYPEPROPERTIES = &HC0204025&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure the object name is valid and the object exists.

' //
' //   MessageId: DTS_E_UNABLETORETRIEVEMETADATA
' //
' //   MessageText:
' //
' //    The metadata for "%1!s!" cannot be retrieved. Make sure the object name is correct and the object exists.
' //
%DTS_E_UNABLETORETRIEVEMETADATA   = &HC0204026&

' //
' //   MessageId: DTS_E_CANNOTMAPOUTPUTCOLUMN
' //
' //   MessageText:
' //
' //    The output column cannot be mapped to an external metadata column.
' //
%DTS_E_CANNOTMAPOUTPUTCOLUMN      = &HC0204027&

' //
' //   MessageId: DTS_E_UNSUPPORTEDVARIABLETYPE
' //
' //   MessageText:
' //
' //    The variable %1!s! is required to be of type "%2!s!".
' //
%DTS_E_UNSUPPORTEDVARIABLETYPE    = &HC0204028&

' //
' //   MessageId: DTS_E_CANTSETEXTERNALMETADATACOLUMNDATATYPEPROPERTIES
' //
' //   MessageText:
' //
' //    The %1!s! does not allow setting external metadata column datatype properties.
' //
%DTS_E_CANTSETEXTERNALMETADATACOLUMNDATATYPEPROPERTIES = &HC020402A&

' ////////////////////////////////////////////////////////////////////////////
' //   The specified ID must be the input ID or the output ID that the external metadata collection is associated with.

' //
' //   MessageId: DTS_E_IDNOTINPUTNOROUTPUT
' //
' //   MessageText:
' //
' //    The ID, %1!lu!, is neither an input ID nor an output ID. The specified ID must be the input ID or the output ID that the external metadata collection is associated with.
' //
%DTS_E_IDNOTINPUTNOROUTPUT        = &HC020402B&

' //
' //   MessageId: DTS_E_METADATACOLLECTIONNOTUSED
' //
' //   MessageText:
' //
' //    The external metadata collection on "%1!s!" is marked as not used, so no operations can be performed on it.
' //
%DTS_E_METADATACOLLECTIONNOTUSED  = &HC020402C&

' ////////////////////////////////////////////////////////////////////////////
' //   Cannot get a buffer type on a sync output

' //
' //   MessageId: DTS_E_NOBUFFERTYPEONSYNCOUTPUT
' //
' //   MessageText:
' //
' //    The %1!s! is a synchronous output and the buffer type cannot be retrieved for a synchronous output.
' //
%DTS_E_NOBUFFERTYPEONSYNCOUTPUT   = &HC020402D&

' ////////////////////////////////////////////////////////////////////////////
' //   The input column has a usage type other than read only, which is not allowed here.

' //
' //   MessageId: DTS_E_INPUTCOLUMNUSAGETYPENOTREADONLY
' //
' //   MessageText:
' //
' //    The input column "%1!s!" must be read-only. The input column has a usage type other than read-only, which is not allowed.
' //
%DTS_E_INPUTCOLUMNUSAGETYPENOTREADONLY = &HC0207000&

' ////////////////////////////////////////////////////////////////////////////
' //   The object is required to have the specified custom property.

' //
' //   MessageId: DTS_E_MISSINGCUSTOMPROPERTY
' //
' //   MessageText:
' //
' //    The "%1!s!" is missing the required property "%2!s!". The object is required to have the specified custom property.
' //
%DTS_E_MISSINGCUSTOMPROPERTY      = &HC0207001&

' ////////////////////////////////////////////////////////////////////////////
' //   The output is not allowed to have the specified property.

' //
' //   MessageId: DTS_E_ILLEGALCUSTOMOUTPUTPROPERTY
' //
' //   MessageText:
' //
' //    The output %1!s! cannot not have property "%2!s!", but currently has that property assigned.
' //
%DTS_E_ILLEGALCUSTOMOUTPUTPROPERTY = &HC0207002&

' ////////////////////////////////////////////////////////////////////////////
' //   All outputs must be in the specified exclusion group.

' //
' //   MessageId: DTS_E_INVALIDOUTPUTEXCLUSIONGROUP
' //
' //   MessageText:
' //
' //    The %1!s! must be in exclusion group %2!d!. All outputs must be in the specified exclusion group.
' //
%DTS_E_INVALIDOUTPUTEXCLUSIONGROUP = &HC0207003&

' ////////////////////////////////////////////////////////////////////////////
' //   The property is not allowed to be empty.

' //
' //   MessageId: DTS_E_PROPERTYISEMPTY
' //
' //   MessageText:
' //
' //    The property "%1!s!" is empty. The property cannot be empty.
' //
%DTS_E_PROPERTYISEMPTY            = &HC0207004&

' ////////////////////////////////////////////////////////////////////////////
' //   Out of memory creating internal object to hold the expression.

' //
' //   MessageId: DTS_E_CREATEEXPRESSIONOBJECTFAILED
' //
' //   MessageText:
' //
' //    Memory cannot be allocated for the expression "%1!s!". There was an out-of-memory error while creating an internal object to hold the expression.
' //
%DTS_E_CREATEEXPRESSIONOBJECTFAILED = &HC0207005&

' ////////////////////////////////////////////////////////////////////////////
' //   Expression was invalid, or we ran out of memory.

' //
' //   MessageId: DTS_E_EXPRESSIONPARSEFAILED
' //
' //   MessageText:
' //
' //    Cannot parse the expression "%1!s!". The expression was not valid, or there is an out-of-memory error.
' //
%DTS_E_EXPRESSIONPARSEFAILED      = &HC0207006&

' ////////////////////////////////////////////////////////////////////////////
' //   Failed to compute the expression.  The expression may have errors (such as divide by zero) that could not be detected at parse time, or we may have run out of memory.

' //
' //   MessageId: DTS_E_EXPRESSIONCOMPUTEFAILED
' //
' //   MessageText:
' //
' //    Computing the expression "%1!s!" failed with error code 0x%2!8.8X!. The expression may have errors, such as divide by zero, that cannot be detected at parse time, or there may be an out-of-memory error.
' //
%DTS_E_EXPRESSIONCOMPUTEFAILED    = &HC0207007&

' ////////////////////////////////////////////////////////////////////////////
' //   Out of memory creating the array of Expression object pointers.

' //
' //   MessageId: DTS_E_FAILEDTOCREATEEXPRESSIONARRAY
' //
' //   MessageText:
' //
' //    Memory cannot be allocated for the Expression objects. An out-of-memory error occurred while creating the array of Expression object pointers.
' //
%DTS_E_FAILEDTOCREATEEXPRESSIONARRAY = &HC0207008&

' ////////////////////////////////////////////////////////////////////////////
' //   The specified error occurred creating the Expression Manager object.

' //
' //   MessageId: DTS_E_FAILEDTOCREATEEXPRESSIONMANANGER
' //
' //   MessageText:
' //
' //    The %1!s! failed with error code 0x%2!8.8X! while creating the Expression Manager.
' //
%DTS_E_FAILEDTOCREATEEXPRESSIONMANANGER = &HC020700A&

' ////////////////////////////////////////////////////////////////////////////
' //   The result type of the expression must be Boolean.

' //
' //   MessageId: DTS_E_SPLITEXPRESSIONNOTBOOLEAN
' //
' //   MessageText:
' //
' //    The expression "%1!s!" is not Boolean. The result type of the expression must be Boolean.
' //
%DTS_E_SPLITEXPRESSIONNOTBOOLEAN  = &HC020700B&

' ////////////////////////////////////////////////////////////////////////////
' //   The expression failed validation.

' //
' //   MessageId: DTS_E_EXPRESSIONVALIDATIONFAILED
' //
' //   MessageText:
' //
' //    The expression "%1!s!" on "%2!s!" is not valid.
' //
%DTS_E_EXPRESSIONVALIDATIONFAILED = &HC020700C&

' ////////////////////////////////////////////////////////////////////////////
' //   The name provided on the output column or input column object couldn't be found in the file.

' //
' //   MessageId: DTS_E_COLUMNNOTMATCHED
' //
' //   MessageText:
' //
' //    The column "%1!s!" (%2!d!) cannot be matched to any input file column. The output column name or input column name cannot be found in the file.
' //
%DTS_E_COLUMNNOTMATCHED           = &HC020700E&

' ////////////////////////////////////////////////////////////////////////////
' //   The input or output column that was to receive the result of the expression could not be determined, or the expression result could not be cast to the column type.

' //
' //   MessageId: DTS_E_SETRESULTCOLUMNFAILED
' //
' //   MessageText:
' //
' //    Attempting to set the result column for the expression "%1!s!" on %2!s! failed with error code 0x%3!8.8X!. The input or output column that was to receive the result of the expression cannot be determined,
' //    or the expression result cannot be cast to the column type.
' //
%DTS_E_SETRESULTCOLUMNFAILED      = &HC020700F&

' ////////////////////////////////////////////////////////////////////////////
' //   The component failed to get the locale ID from the package because the variables collection was not available.

' //
' //   MessageId: DTS_E_FAILEDTOGETLOCALEIDFROMPACKAGE
' //
' //   MessageText:
' //
' //    The %1!s! failed to get the locale ID from the package.
' //
%DTS_E_FAILEDTOGETLOCALEIDFROMPACKAGE = &HC0207011&

' ////////////////////////////////////////////////////////////////////////////
' //   The format is: "<parameter name>",variableID;"<parameter name2>",variableID2;

' //
' //   MessageId: DTS_E_INCORRECTPARAMETERMAPPINGFORMAT
' //
' //   MessageText:
' //
' //    The parameter mapping string is not in the correct format.
' //
%DTS_E_INCORRECTPARAMETERMAPPINGFORMAT = &HC0207012&

' //
' //   MessageId: DTS_E_NOTENOUGHPARAMETERSPROVIDED
' //
' //   MessageText:
' //
' //    The SQL command requires %1!d! parameters, but the parameter mapping only has %2!d! parameters.
' //
%DTS_E_NOTENOUGHPARAMETERSPROVIDED = &HC0207013&

' //
' //   MessageId: DTS_E_PARAMETERNOTFOUNDINMAPPING
' //
' //   MessageText:
' //
' //    The SQL command requires a parameter named "%1!s!", which is not found in the parameter mapping.
' //
%DTS_E_PARAMETERNOTFOUNDINMAPPING = &HC0207014&

' //
' //   MessageId: DTS_E_DUPLICATEDATASOURCECOLUMNNAME
' //
' //   MessageText:
' //
' //    There is more than one data source column with the name "%1!s!".  The data source column names must be unique.
' //
%DTS_E_DUPLICATEDATASOURCECOLUMNNAME = &HC0207015&

' //
' //   MessageId: DTS_E_DATASOURCECOLUMNWITHNONAMEFOUND
' //
' //   MessageText:
' //
' //    There is a data source column with no name.  All data source column must have a name.
' //
%DTS_E_DATASOURCECOLUMNWITHNONAMEFOUND = &HC0207016&

' //
' //   MessageId: DTS_E_DISCONNECTEDCOMPONENT
' //
' //   MessageText:
' //
' //    A component is disconnected from the layout.
' //
%DTS_E_DISCONNECTEDCOMPONENT      = &HC0208001&

' //
' //   MessageId: DTS_E_INVALIDCOMPONENTID
' //
' //   MessageText:
' //
' //    The ID for a layout component is not valid.
' //
%DTS_E_INVALIDCOMPONENTID         = &HC0208002&

' //
' //   MessageId: DTS_E_INVALIDINPUTCOUNT
' //
' //   MessageText:
' //
' //    A component has an invalid number of inputs.
' //
%DTS_E_INVALIDINPUTCOUNT          = &HC0208003&

' //
' //   MessageId: DTS_E_INVALIDOUTPUTCOUNT
' //
' //   MessageText:
' //
' //    A component has an invalid number of outputs.
' //
%DTS_E_INVALIDOUTPUTCOUNT         = &HC0208004&

' //
' //   MessageId: DTS_E_NOINPUTSOROUTPUTS
' //
' //   MessageText:
' //
' //    A component does not have any inputs or outputs.
' //
%DTS_E_NOINPUTSOROUTPUTS          = &HC0208005&

' //
' //   MessageId: DTS_E_CANTALLOCATECOLUMNINFO
' //
' //   MessageText:
' //
' //    Not enough memory was available to allocate a list of the columns that are being manipulated by this component.
' //
%DTS_E_CANTALLOCATECOLUMNINFO     = &HC0208007&

' //
' //   MessageId: DTS_E_OUTPUTCOLUMNNOTININPUT
' //
' //   MessageText:
' //
' //    Output column "%1!s!" (%2!d!) references input column with lineage ID %3!d!, but no input could be found with that lineage ID.
' //
%DTS_E_OUTPUTCOLUMNNOTININPUT     = &HC0208008&

' //
' //   MessageId: DTS_E_SORTNEEDSONEKEY
' //
' //   MessageText:
' //
' //    At least one input column must be marked as a sort key, but no keys were found.
' //
%DTS_E_SORTNEEDSONEKEY            = &HC0208009&

' //
' //   MessageId: DTS_E_SORTDUPLICATEKEYWEIGHT
' //
' //   MessageText:
' //
' //    Both column "%1!s!" (%2!d!) and column "%3!s!" (%4!d!) were marked with sort key weight %5!d!.
' //
%DTS_E_SORTDUPLICATEKEYWEIGHT     = &HC020800A&

' //
' //   MessageId: DTS_E_CANTMODIFYINVALID
' //
' //   MessageText:
' //
' //    The component cannot perform the requested metadata change until the validation problem is fixed.
' //
%DTS_E_CANTMODIFYINVALID          = &HC020800D&

' //
' //   MessageId: DTS_E_CANTADDINPUT
' //
' //   MessageText:
' //
' //    An input cannot be added to the inputs collection.
' //
%DTS_E_CANTADDINPUT               = &HC020800E&

' //
' //   MessageId: DTS_E_CANTADDOUTPUT
' //
' //   MessageText:
' //
' //    An output cannot be added to the outputs collection.
' //
%DTS_E_CANTADDOUTPUT              = &HC020800F&

' //
' //   MessageId: DTS_E_CANTDELETEINPUT
' //
' //   MessageText:
' //
' //    An input cannot be deleted from the inputs collection.
' //
%DTS_E_CANTDELETEINPUT            = &HC0208010&

' //
' //   MessageId: DTS_E_CANTDELETEOUTPUT
' //
' //   MessageText:
' //
' //    An output cannot be removed from the outputs collection.
' //
%DTS_E_CANTDELETEOUTPUT           = &HC0208011&

' //
' //   MessageId: DTS_E_CANTCHANGEUSAGETYPE
' //
' //   MessageText:
' //
' //    The usage type of the column cannot be changed.
' //
%DTS_E_CANTCHANGEUSAGETYPE        = &HC0208014&

' ////////////////////////////////////////////////////////////////////////////
' //   The input or output column had the specified custom property, but was not read/write. Resolution: remove the property, or make the column read/write.

' //
' //   MessageId: DTS_E_INVALIDUSAGETYPEFORCUSTOMPROPERTY
' //
' //   MessageText:
' //
' //    The %1!s! must be read/write to have custom property "%2!s!". The input or output column has the specified custom property, but is not read/write. Remove the property, or make the column read/write.
' //
%DTS_E_INVALIDUSAGETYPEFORCUSTOMPROPERTY = &HC0208016&

' ////////////////////////////////////////////////////////////////////////////
' //   The input or output column was read/write, so it requires the presence of the specified custom property. Resolution: add the property, or make the column not read/write.

' //
' //   MessageId: DTS_E_READWRITECOLUMNMISSINGREQUIREDCUSTOMPROPERTY
' //
' //   MessageText:
' //
' //    The %1!s! is read/write and is required to have custom property "%2!s!". Add the property, or make remove the read/write attribute from the column.
' //
%DTS_E_READWRITECOLUMNMISSINGREQUIREDCUSTOMPROPERTY = &HC0208017&

' ////////////////////////////////////////////////////////////////////////////
' //   The component does not allow deleting columns from this input or output.

' //
' //   MessageId: DTS_E_CANTDELETECOLUMN
' //
' //   MessageText:
' //
' //    The column cannot be deleted. The component does not allow columns to be deleted from this input or output.
' //
%DTS_E_CANTDELETECOLUMN           = &HC0208018&

' ////////////////////////////////////////////////////////////////////////////
' //   The component does not allow adding columns to this input or output.

' //
' //   MessageId: DTS_E_CANTADDCOLUMN
' //
' //   MessageText:
' //
' //    The component does not allow adding columns to this input or output.
' //
%DTS_E_CANTADDCOLUMN              = &HC0208019&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure the component's runtime connection collection has an object with that name

' //
' //   MessageId: DTS_E_CANNOTTFINDRUNTIMECONNECTIONOBJECT
' //
' //   MessageText:
' //
' //    The connection "%1!s!" cannot be found. Verify that the connection manager has a connection with that name.
' //
%DTS_E_CANNOTTFINDRUNTIMECONNECTIONOBJECT = &HC020801A&

' ////////////////////////////////////////////////////////////////////////////
' //   Make sure the runtime connection manager collection has an object with that ID

' //
' //   MessageId: DTS_E_CANNOTFINDRUNTIMECONNECTIONMANAGER
' //
' //   MessageText:
' //
' //    The runtime connection manager with the ID "%1!s!" cannot be found. Verify that the connection manager collection has a connection manager with that ID.
' //
%DTS_E_CANNOTFINDRUNTIMECONNECTIONMANAGER = &HC020801B&

' //
' //   MessageId: DTS_E_CANNOTACQUIRECONNECTIONFROMCONNECTIONMANAGER
' //
' //   MessageText:
' //
' //    The AcquireConnection method call to the connection manager "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_CANNOTACQUIRECONNECTIONFROMCONNECTIONMANAGER = &HC020801C&

' //
' //   MessageId: DTS_E_ACQUIREDCONNECTIONISINVALID
' //
' //   MessageText:
' //
' //    The connection acquired from the connection manager "%1!s!" is not valid.
' //
%DTS_E_ACQUIREDCONNECTIONISINVALID = &HC020801D&

' //
' //   MessageId: DTS_E_INCORRECTCONNECTIONMANAGERTYPE
' //
' //   MessageText:
' //
' //    The connection manager "%1!s!" is an incorrect type.  The type required is "%2!s!". The type available to the component is "%3!s!".
' //
%DTS_E_INCORRECTCONNECTIONMANAGERTYPE = &HC020801E&

' //
' //   MessageId: DTS_E_CANNOTACQUIREMANAGEDCONNECTIONFROMCONNECTIONMANAGER
' //
' //   MessageText:
' //
' //    Cannot acquire a managed connection from the run-time connection manager.
' //
%DTS_E_CANNOTACQUIREMANAGEDCONNECTIONFROMCONNECTIONMANAGER = &HC020801F&

' //
' //   MessageId: DTS_E_CANTINITINPUT
' //
' //   MessageText:
' //
' //    An input cannot be created to initialize the inputs collection.
' //
%DTS_E_CANTINITINPUT              = &HC0208020&

' //
' //   MessageId: DTS_E_CANTINITOUTPUT
' //
' //   MessageText:
' //
' //    An output cannot be created to initialize the outputs collection.
' //
%DTS_E_CANTINITOUTPUT             = &HC0208021&

' ////////////////////////////////////////////////////////////////////////////
' //   The error code was previously reported.

' //
' //   MessageId: DTS_E_EXTRACTORCANTWRITE
' //
' //   MessageText:
' //
' //    Writing to the file "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXTRACTORCANTWRITE         = &HC0208023&

' //
' //   MessageId: DTS_E_INCORRECTCONNECTIONOBJECTTYPE
' //
' //   MessageText:
' //
' //    The connection manager "%1!s!" returned an object of an  incorrect type from the AcquireConnection method.
' //
%DTS_E_INCORRECTCONNECTIONOBJECTTYPE = &HC0208024&

' ////////////////////////////////////////////////////////////////////////////
' //   The missing property should be added.

' //
' //   MessageId: DTS_E_INPUTCOLPROPERTYNOTFOUND
' //
' //   MessageText:
' //
' //    The "%3!s!" property is required on input column "%1!s!" (%2!d!), but is not found. The missing property should be added.
' //
%DTS_E_INPUTCOLPROPERTYNOTFOUND   = &HC0208025&

' ////////////////////////////////////////////////////////////////////////////
' //   Unreferenced columns are not allowed.

' //
' //   MessageId: DTS_E_EXTRACTORUNREFERENCED
' //
' //   MessageText:
' //
' //    The "%1!s!" is marked read-only, but is not referenced by any other column. Unreferenced columns are not allowed.
' //
%DTS_E_EXTRACTORUNREFERENCED      = &HC0208026&

' ////////////////////////////////////////////////////////////////////////////
' //   A reference points to a non-existant column.

' //
' //   MessageId: DTS_E_EXTRACTORREFERENCEDCOLUMNNOTFOUND
' //
' //   MessageText:
' //
' //    The "%1!s!" references column ID %2!d!, and that column is not found on the input. A reference points to a non-existant column.
' //
%DTS_E_EXTRACTORREFERENCEDCOLUMNNOTFOUND = &HC0208027&

' ////////////////////////////////////////////////////////////////////////////
' //   A reference points to a column that isn't BLOB.

' //
' //   MessageId: DTS_E_EXTRACTORDATACOLUMNNOTBLOB
' //
' //   MessageText:
' //
' //    The "%1!s!" references "%2!s!", and that column is not of a BLOB type.
' //
%DTS_E_EXTRACTORDATACOLUMNNOTBLOB = &HC0208028&

' ////////////////////////////////////////////////////////////////////////////
' //   A reference points to a non-existant output column.

' //
' //   MessageId: DTS_E_INSERTERREFERENCEDCOLUMNNOTFOUND
' //
' //   MessageText:
' //
' //    The "%1!s!" references output column ID %2!d!, and that column is not found on the output.
' //
%DTS_E_INSERTERREFERENCEDCOLUMNNOTFOUND = &HC0208029&

' ////////////////////////////////////////////////////////////////////////////
' //   The error code was previously reported.

' //
' //   MessageId: DTS_E_INSERTERCANTREAD
' //
' //   MessageText:
' //
' //    Reading from the file "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_INSERTERCANTREAD           = &HC020802A&

' ////////////////////////////////////////////////////////////////////////////
' //   At least one column must be FixedAttribute, ChangingAttribute or HistoricalAttribute.

' //
' //   MessageId: DTS_E_TXSCD_NOTYPEDCOLUMNSATINPUT
' //
' //   MessageText:
' //
' //    There must be at least one column of Fixed, Changing, or Historical type on the input of a Slowly Changing Dimension transform. Verify that at least one column is a FixedAttribute, ChangingAttribute, or HistoricalAttribute.
' //
%DTS_E_TXSCD_NOTYPEDCOLUMNSATINPUT = &HC020802B&

' ////////////////////////////////////////////////////////////////////////////
' //   The current value of the property is outside the range of legal values.

' //
' //   MessageId: DTS_E_TXSCD_INVALIDINPUTCOLUMNTYPE
' //
' //   MessageText:
' //
' //    The ColumnType property of "%1!s!" is not valid. The current value is outside the range of acceptable values.
' //
%DTS_E_TXSCD_INVALIDINPUTCOLUMNTYPE = &HC020802C&

' ////////////////////////////////////////////////////////////////////////////
' //   SCD doesn't allow mapping between column of different types except for DT_STR and DT_WSTR.

' //
' //   MessageId: DTS_E_TXSCD_CANNOTMAPDIFFERENTTYPES
' //
' //   MessageText:
' //
' //    The input column "%1!s!" cannot be mapped to external column "%2!s!" because they have different data types. The Slowly Changing Dimension transform does not allow mapping between column of different types except for DT_STR and DT_WSTR.
' //
%DTS_E_TXSCD_CANNOTMAPDIFFERENTTYPES = &HC020802D&

' ////////////////////////////////////////////////////////////////////////////
' //   Use DT_TEXT instead and then convert the data to DT_NTEXT using the data conversion component.

' //
' //   MessageId: DTS_E_NTEXTDATATYPENOTSUPPORTEDWITHANSIFILES
' //
' //   MessageText:
' //
' //    The data type for "%1!s!" is DT_NTEXT, which is not supported with ANSI files. Use DT_TEXT instead and convert the data to DT_NTEXT using the data conversion component.
' //
%DTS_E_NTEXTDATATYPENOTSUPPORTEDWITHANSIFILES = &HC020802E&

' ////////////////////////////////////////////////////////////////////////////
' //   Use DT_NTEXT instead and then convert the data to DT_TEXT using the data conversion component.

' //
' //   MessageId: DTS_E_TEXTDATATYPENOTSUPPORTEDWITHUNICODEFILES
' //
' //   MessageText:
' //
' //    The data type for "%1!s!" is DT_TEXT, which is not supported with Unicode files. Use DT_NTEXT instead and convert the data to DT_TEXT using the data conversion component.
' //
%DTS_E_TEXTDATATYPENOTSUPPORTEDWITHUNICODEFILES = &HC020802F&

' ////////////////////////////////////////////////////////////////////////////
' //   Use DT_TEXT or DT_NTEXT instead and then convert the data from or to DT_IMAGE using the data conversion component.

' //
' //   MessageId: DTS_E_IMAGEDATATYPENOTSUPPORTED
' //
' //   MessageText:
' //
' //    The data type for "%1!s!" is DT_IMAGE, which is not supported. Use DT_TEXT or DT_NTEXT instead and convert the data from, or to, DT_IMAGE using the data conversion component.
' //
%DTS_E_IMAGEDATATYPENOTSUPPORTED  = &HC0208030&

' //
' //   MessageId: DTS_E_FLATFILEFORMATNOTSUPPORTED
' //
' //   MessageText:
' //
' //    Format "%1!s!" is not supported by Flat File Connection Manager. Supported formats are Delimited, FixedWidth, RaggedRight, and Mixed.
' //
%DTS_E_FLATFILEFORMATNOTSUPPORTED = &HC0208031&

' ////////////////////////////////////////////////////////////////////////////
' //   A referencing column is not of string type.

' //
' //   MessageId: DTS_E_EXTRACTORFILENAMECOLUMNNOTSTRING
' //
' //   MessageText:
' //
' //    The "%1!s!" should contain a file name, but it is not of a String type.
' //
%DTS_E_EXTRACTORFILENAMECOLUMNNOTSTRING = &HC0208032&

' ////////////////////////////////////////////////////////////////////////////
' //   Cannot have both properties set.

' //
' //   MessageId: DTS_E_EXTRACTORCANTAPPENDTRUNCATE
' //
' //   MessageText:
' //
' //    Error caused by conflicting property settings. The "%1!s!" has both the AllowAppend property and the ForceTruncate property set to TRUE. Both properties cannot be set to TRUE. Set one of the two properties to FALSE.
' //
%DTS_E_EXTRACTORCANTAPPENDTRUNCATE = &HC0208033&

' ////////////////////////////////////////////////////////////////////////////
' //   A reference points to an already-referenced column.

' //
' //   MessageId: DTS_E_EXTRACTORCOLUMNALREADYREFERENCED
' //
' //   MessageText:
' //
' //    The %1!s! references column ID %2!d!, but that column is already referenced by %3!s!. Remove one of the two reference to the column.
' //
%DTS_E_EXTRACTORCOLUMNALREADYREFERENCED = &HC0208034&

' //
' //   MessageId: DTS_E_CONNECTIONMANANGERNOTASSIGNED
' //
' //   MessageText:
' //
' //    A connection manager has not been assigned to the %1!s!.
' //
%DTS_E_CONNECTIONMANANGERNOTASSIGNED = &HC0208035&

' ////////////////////////////////////////////////////////////////////////////
' //   A reference points to an already-referenced column.

' //
' //   MessageId: DTS_E_INSERTERCOLUMNALREADYREFERENCED
' //
' //   MessageText:
' //
' //    The %1!s! references the output column with ID %2!d!, but that column is already referenced by %3!s!.
' //
%DTS_E_INSERTERCOLUMNALREADYREFERENCED = &HC0208036&

' ////////////////////////////////////////////////////////////////////////////
' //   Each output column must be referenced by exactly one input column.

' //
' //   MessageId: DTS_E_INSERTERCOLUMNNOTREFERENCED
' //
' //   MessageText:
' //
' //    The "%1!s!" is not referenced by any input column. Each output column must be referenced by exactly one input column.
' //
%DTS_E_INSERTERCOLUMNNOTREFERENCED = &HC0208037&

' ////////////////////////////////////////////////////////////////////////////
' //   A reference points to a column that isn't BLOB as required.

' //
' //   MessageId: DTS_E_INSERTERDATACOLUMNNOTBLOB
' //
' //   MessageText:
' //
' //    The "%1!s!" references "%2!s!", and that column is not the correct type. It must be DT_TEXT, DT_NTEXT, or DT_IMAGE. A reference points to a column that must be a BLOB.
' //
%DTS_E_INSERTERDATACOLUMNNOTBLOB  = &HC0208038&

' ////////////////////////////////////////////////////////////////////////////
' //   A referencing column is not of string type.

' //
' //   MessageId: DTS_E_INSERTERFILENAMECOLUMNNOTSTRING
' //
' //   MessageText:
' //
' //    The "%1!s!" should contain a file name, but it is not a String type.
' //
%DTS_E_INSERTERFILENAMECOLUMNNOTSTRING = &HC0208039&

' ////////////////////////////////////////////////////////////////////////////
' //   ExpectBOM can only be set to TRUE for DT_NTEXT output columns.

' //
' //   MessageId: DTS_E_INSERTEREXPECTBOMINVALIDTYPE
' //
' //   MessageText:
' //
' //    The "%1!s!" has the ExpectBOM property set to TRUE for %2!s!, but the column is not NT_NTEXT. The ExpectBOM specifies that the Import Column transformation expects a byte-order mark (BOM). Either set the ExpectBOM property to
' //    false or change the output column data type to DT_NTEXT.
' //
%DTS_E_INSERTEREXPECTBOMINVALIDTYPE = &HC020803A&

' ////////////////////////////////////////////////////////////////////////////
' //   The data output column may only be set to a BLOB type.

' //
' //   MessageId: DTS_E_INSERTERINVALIDDATACOLUMNSETTYPE
' //
' //   MessageText:
' //
' //    Data output columns must be DT_TEXT, DT_NTEXT, or DT_IMAGE. The data output column may only be set to a BLOB type.
' //
%DTS_E_INSERTERINVALIDDATACOLUMNSETTYPE = &HC020803B&

' ////////////////////////////////////////////////////////////////////////////
' //   The transform will fail when a FixedAttribute change is detected if you set FailOnFixedAttribute to true. To direct the rows to Fixed Attribute Output set FailOnFixedAttribute to false

' //
' //   MessageId: DTS_E_TXSCD_FIXEDATTRIBUTECHANGE
' //
' //   MessageText:
' //
' //    If the FailOnFixedAttributeChange property is set to TRUE, the transformation will fail when a fixed attribute change is detected. To send rows to the Fixed Attribute output, set the FailOnFixedAttributeChange property to FALSE.
' //
%DTS_E_TXSCD_FIXEDATTRIBUTECHANGE = &HC020803C&

' ////////////////////////////////////////////////////////////////////////////
' //   The transform will fail when a FailOnLookupFailure is set to true.

' //
' //   MessageId: DTS_E_TXSCD_LOOKUPFAILURE
' //
' //   MessageText:
' //
' //    The Lookup transformation failed to retrieve any rows. The transform fails when the FailOnLookupFailure is set to TRUE and no rows are retrieved.
' //
%DTS_E_TXSCD_LOOKUPFAILURE        = &HC020803D&

' ////////////////////////////////////////////////////////////////////////////
' //   At least one column must be Key.

' //
' //   MessageId: DTS_E_TXSCD_INVALIDNUMBERSOFPARAMETERS
' //
' //   MessageText:
' //
' //    There must be at least one column type of Key on the input of a Slowly Changing Dimension transformation. Set at least one column type to Key.
' //
%DTS_E_TXSCD_INVALIDNUMBERSOFPARAMETERS = &HC020803E&

' //
' //   MessageId: DTS_E_TXSCD_CANNOTFINDEXTERNALCOLUMN
' //
' //   MessageText:
' //
' //    Cannot find external column with name "%1!s!".
' //
%DTS_E_TXSCD_CANNOTFINDEXTERNALCOLUMN = &HC020803F&

' //
' //   MessageId: DTS_E_TXSCD_INFFEREDINDICATORNOTBOOL
' //
' //   MessageText:
' //
' //    Inferred indicator column "%1!s!" must be of type DT_BOOL.
' //
%DTS_E_TXSCD_INFFEREDINDICATORNOTBOOL = &HC0208040&

' //
' //   MessageId: DTS_E_ERRORROWDISPMUSTBENOTUSED
' //
' //   MessageText:
' //
' //    The %1!s! must have its error row disposition value set to RD_NotUsed.
' //
%DTS_E_ERRORROWDISPMUSTBENOTUSED  = &HC0208107&

' //
' //   MessageId: DTS_E_TRUNCROWDISPMUSTBENOTUSED
' //
' //   MessageText:
' //
' //    The %1!s! must have its truncation row disposition value set to RD_NotUsed.
' //
%DTS_E_TRUNCROWDISPMUSTBENOTUSED  = &HC0208108&

' //
' //   MessageId: DTS_E_TXAGG_INPUTNOTFOUNDFOROUTPUT
' //
' //   MessageText:
' //
' //    Cannot find input column with lineage ID %1!d! needed by output column with ID %2!d!.
' //
%DTS_E_TXAGG_INPUTNOTFOUNDFOROUTPUT = &HC0208201&

' //
' //   MessageId: DTS_E_TXAGG_INVALIDOUTPUTDATATYPEFORAGGREGATE
' //
' //   MessageText:
' //
' //    Invalid output data type for aggregate type specified at output column ID %1!d!.
' //
%DTS_E_TXAGG_INVALIDOUTPUTDATATYPEFORAGGREGATE = &HC0208202&

' //
' //   MessageId: DTS_E_TXAGG_INVALIDINPUTDATATYPEFORAGGREGATE
' //
' //   MessageText:
' //
' //    Invalid input data type for %1!s! used for the specified aggregate at %2!s!.
' //
%DTS_E_TXAGG_INVALIDINPUTDATATYPEFORAGGREGATE = &HC0208203&

' //
' //   MessageId: DTS_E_TXAGG_INPUTOUTPUTDATATYPEMISMATCH
' //
' //   MessageText:
' //
' //    Data types of input column lineage ID %1!d! and output column ID %2!d! do not match.
' //
%DTS_E_TXAGG_INPUTOUTPUTDATATYPEMISMATCH = &HC0208204&

' //
' //   MessageId: DTS_E_UNABLETOGETINPUTBUFFERHANDLE
' //
' //   MessageText:
' //
' //    Cannot get input buffer handle for input ID %1!d!.
' //
%DTS_E_UNABLETOGETINPUTBUFFERHANDLE = &HC0208205&

' //
' //   MessageId: DTS_E_UNABLETOGETOUTPUTBUFFERHANDLE
' //
' //   MessageText:
' //
' //    Cannot get output buffer handle for output ID %1!d!.
' //
%DTS_E_UNABLETOGETOUTPUTBUFFERHANDLE = &HC0208206&

' //
' //   MessageId: DTS_E_UNABLETOFINDCOLUMNHANDLEINOUTPUTBUFFER
' //
' //   MessageText:
' //
' //    Cannot find column with lineage ID %1!d! in output buffer.
' //
%DTS_E_UNABLETOFINDCOLUMNHANDLEINOUTPUTBUFFER = &HC0208207&

' //
' //   MessageId: DTS_E_UNABLETOFINDCOLUMNHANDLEININPUTBUFFER
' //
' //   MessageText:
' //
' //    Cannot find column with lineage ID %1!d! in input buffer.
' //
%DTS_E_UNABLETOFINDCOLUMNHANDLEININPUTBUFFER = &HC0208208&

' //
' //   MessageId: DTS_E_CANNOTHAVEZEROOUTPUTCOLUMNS
' //
' //   MessageText:
' //
' //    The number of output columns for %1!s! cannot be zero.
' //
%DTS_E_CANNOTHAVEZEROOUTPUTCOLUMNS = &HC0208209&

' //
' //   MessageId: DTS_E_CONNECTIONMANAGERCOLUMNCOUNTMISMATCH
' //
' //   MessageText:
' //
' //    The number of columns in the flat file connection manager must be the same as the number of columns in the flat file adapter. The number of columns for the flat file connection manager is %1!d!,
' //    while the number of columns for the flat file adapter is %2!d!.
' //
%DTS_E_CONNECTIONMANAGERCOLUMNCOUNTMISMATCH = &HC020820A&

' //
' //   MessageId: DTS_E_MISMATCHCONNECTIONMANAGERCOLUMN
' //
' //   MessageText:
' //
' //    The column "%1!s!" at index %2!d! in the flat file connection manager was not found at index %3!d! in the column collection of the flat file adapter.
' //
%DTS_E_MISMATCHCONNECTIONMANAGERCOLUMN = &HC020820B&

' //
' //   MessageId: DTS_E_EXTERNALMETADATACOLUMNISALREADYMAPPED
' //
' //   MessageText:
' //
' //    The external metadata column with ID %1!d! has already been mapped to %2!s!.
' //
%DTS_E_EXTERNALMETADATACOLUMNISALREADYMAPPED = &HC020820D&

' ////////////////////////////////////////////////////////////////////////////
' //   A row given to the transform as a key was too large to convert or store.

' //
' //   MessageId: DTS_E_TXAGG_STRING_TOO_LONG
' //
' //   MessageText:
' //
' //    The transform encountered a key column that was larger than %1!u! characters.
' //
%DTS_E_TXAGG_STRING_TOO_LONG      = &HC020820E&

' //
' //   MessageId: DTS_E_DERIVEDRESULT_TOO_LONG
' //
' //   MessageText:
' //
' //    The transform encountered a result value that was longer than %1!u! bytes.
' //
%DTS_E_DERIVEDRESULT_TOO_LONG     = &HC020820F&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERROUTPUTDESCRIPTORS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERROUTPUTDESCRIPTORS = &HC0208210&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRWORKSPACEDESCRIPTORS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRWORKSPACEDESCRIPTORS = &HC0208211&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRSORTORDERDESCRIPTORS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRSORTORDERDESCRIPTORS = &HC0208212&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRNUMERICDESCRIPTORS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRNUMERICDESCRIPTORS = &HC0208213&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRCOUNTDISTINCTDESCRIPTOR
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRCOUNTDISTINCTDESCRIPTOR = &HC0208214&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRWORKSPACESORTORDERDESCRIPTORS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRWORKSPACESORTORDERDESCRIPTORS = &HC0208215&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRWORKSPACENUMERICDESCRIPTORS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRWORKSPACENUMERICDESCRIPTORS = &HC0208216&

' //
' //   MessageId: DTS_E_TXAGG_MEMALLOCERRWORKSPACEBUFFCOLS
' //
' //   MessageText:
' //
' //    Unable to allocate memory.
' //
%DTS_E_TXAGG_MEMALLOCERRWORKSPACEBUFFCOLS = &HC0208217&

' //
' //   MessageId: DTS_E_UNREFERENCEDINPUTCOLUMN
' //
' //   MessageText:
' //
' //    The input column "%1!s!" is not referenced.
' //
%DTS_E_UNREFERENCEDINPUTCOLUMN    = &HC0208218&

' ////////////////////////////////////////////////////////////////////////////
' //   Not enough memory was available.

' //
' //   MessageId: DTS_E_CANTBUILDTHREADPOOL
' //
' //   MessageText:
' //
' //    The Sort transformation could not create a thread pool with %1!d! threads. Not enough memory is available.
' //
%DTS_E_CANTBUILDTHREADPOOL        = &HC0208219&

' ////////////////////////////////////////////////////////////////////////////
' //   There isn't enough memory available.

' //
' //   MessageId: DTS_E_QUEUEWORKITEMFAILED
' //
' //   MessageText:
' //
' //    The Sort transformation cannot queue a work item to its thread pool. There is not enough memory available.
' //
%DTS_E_QUEUEWORKITEMFAILED        = &HC020821A&

' ////////////////////////////////////////////////////////////////////////////
' //   A catastrophic error was encountered while sorting a buffer; that error should be repoted separately.

' //
' //   MessageId: DTS_E_SORTTHREADSTOPPED
' //
' //   MessageText:
' //
' //    A worker thread in the Sort transformation stopped with error code 0x%1!8.8X!. A catastrophic error was encountered while sorting a buffer.
' //
%DTS_E_SORTTHREADSTOPPED          = &HC020821B&

' ////////////////////////////////////////////////////////////////////////////
' //   TxSort was told to use an unreasonable number of threads. The MaxThreads property was not valid.

' //
' //   MessageId: DTS_E_SORTBADTHREADCOUNT
' //
' //   MessageText:
' //
' //    MaxThreads was %1!ld!, and should be between 1 and %2!ld!, inclusive or -1 to default to the number of CPUs.
' //
%DTS_E_SORTBADTHREADCOUNT         = &HC020821E&

' //
' //   MessageId: DTS_E_DTPXMLLOADFAILURE
' //
' //   MessageText:
' //
' //    Unable to load from XML.
' //
%DTS_E_DTPXMLLOADFAILURE          = &HC020821F&

' //
' //   MessageId: DTS_E_DTPXMLSAVEFAILURE
' //
' //   MessageText:
' //
' //    Unable to save to XML.
' //
%DTS_E_DTPXMLSAVEFAILURE          = &HC0208220&

' //
' //   MessageId: DTS_E_DTPXMLINT32CONVERTERR
' //
' //   MessageText:
' //
' //    Unable to convert the value "%1!s!" to an integer.
' //
%DTS_E_DTPXMLINT32CONVERTERR      = &HC0208221&

' //
' //   MessageId: DTS_E_DTPXMLBOOLCONVERTERR
' //
' //   MessageText:
' //
' //    Unable to convert the value "%1!s!" to a Boolean.
' //
%DTS_E_DTPXMLBOOLCONVERTERR       = &HC0208222&

' ////////////////////////////////////////////////////////////////////////////
' //   something went wrong when loading/setting an object of this ID in the xml file

' //
' //   MessageId: DTS_E_DTPXMLPARSEERRORNEARID
' //
' //   MessageText:
' //
' //    Load error encountered near object with ID %1!d!.
' //
%DTS_E_DTPXMLPARSEERRORNEARID     = &HC0208223&

' ////////////////////////////////////////////////////////////////////////////
' //   encountered bad property datatype token value when loading xml

' //
' //   MessageId: DTS_E_DTPXMLPROPERTYTYPEERR
' //
' //   MessageText:
' //
' //    The value "%1!s!" is not valid for the attribute "%2!s!".
' //
%DTS_E_DTPXMLPROPERTYTYPEERR      = &HC0208226&

' ////////////////////////////////////////////////////////////////////////////
' //   encountered bad usagetype token value when loading xml

' //
' //   MessageId: DTS_E_DTPXMLSETUSAGETYPEERR
' //
' //   MessageText:
' //
' //    The value "%1!s!" is not valid for the attribute "%2!s!".
' //
%DTS_E_DTPXMLSETUSAGETYPEERR      = &HC0208228&

' ////////////////////////////////////////////////////////////////////////////
' //   encountered bad datatype token value when loading xml

' //
' //   MessageId: DTS_E_DTPXMLDATATYPEERR
' //
' //   MessageText:
' //
' //    The value "%1!s!" is not valid for the attribute "%2!s!".
' //
%DTS_E_DTPXMLDATATYPEERR          = &HC0208229&

' ////////////////////////////////////////////////////////////////////////////
' //   Map it or remove it.

' //
' //   MessageId: DTS_E_UNMAPPEDINPUTCOLUMN
' //
' //   MessageText:
' //
' //    The %1!s! is not mapped to an output column.
' //
%DTS_E_UNMAPPEDINPUTCOLUMN        = &HC020822A&

' //
' //   MessageId: DTS_E_INPUTCOLUMNBADMAP
' //
' //   MessageText:
' //
' //    The %1!s! has a mapping that is not valid.  An output column with an ID of %2!ld! does not exist on this component.
' //
%DTS_E_INPUTCOLUMNBADMAP          = &HC020822B&

' //
' //   MessageId: DTS_W_UNMAPPEDOUTPUTCOLUMN
' //
' //   MessageText:
' //
' //    The %1!s! has no input column mapped to it.
' //
%DTS_W_UNMAPPEDOUTPUTCOLUMN       = &HC020822C&

' //
' //   MessageId: DTS_E_MULTIPLYMAPPEDOUTCOL
' //
' //   MessageText:
' //
' //    The %1!s! is mapped to an output column that already has a mapping on this input.
' //
%DTS_E_MULTIPLYMAPPEDOUTCOL       = &HC020822D&

' //
' //   MessageId: DTS_E_TXAGG_STRINGPROMOTIONFAILED
' //
' //   MessageText:
' //
' //    Could not convert input column with Lineage ID %1!ld! to DT_WSTR due to error 0x%2!8.8X!.
' //
%DTS_E_TXAGG_STRINGPROMOTIONFAILED = &HC020822E&

' ////////////////////////////////////////////////////////////////////////////
' //   Can't find an object id in the layout, bad error when loading paths from the xml

' //
' //   MessageId: DTS_E_DTPXMLIDLOOKUPERR
' //
' //   MessageText:
' //
' //    Referenced object with ID %1!d! not found in package.
' //
%DTS_E_DTPXMLIDLOOKUPERR          = &HC0208230&

' ////////////////////////////////////////////////////////////////////////////
' //   one of the properties required for the pipelinexml module was not provided by the pipeline, bad internal error

' //
' //   MessageId: DTS_E_DTPXMLINVALIDXMLPERSISTPROPERTY
' //
' //   MessageText:
' //
' //    Cannot read a persistance property required for the pipelinexml module. The property was not provided by the pipeline.
' //
%DTS_E_DTPXMLINVALIDXMLPERSISTPROPERTY = &HC0208231&

' ////////////////////////////////////////////////////////////////////////////
' //   propertyState attribute of a property node has invalid value

' //
' //   MessageId: DTS_E_DTPXMLPROPERTYSTATEERR
' //
' //   MessageText:
' //
' //    The value "%1!s!" is not valid for the attribute "%2!s!".
' //
%DTS_E_DTPXMLPROPERTYSTATEERR     = &HC0208232&

' //
' //   MessageId: DTS_E_CANTGETCUSTOMPROPERTY
' //
' //   MessageText:
' //
' //    Cannot retrieve custom property "%1!s!".
' //
%DTS_E_CANTGETCUSTOMPROPERTY      = &HC0208233&

' //
' //   MessageId: DTS_E_UNABLETOLOCATEINPUTCOLUMNID
' //
' //   MessageText:
' //
' //    An input column with the lineage ID %1!d!, referenced in the ParameterMap custom property with the parameter on position number %2!d!, cannot be found in the input columns collection.
' //
%DTS_E_UNABLETOLOCATEINPUTCOLUMNID = &HC0208234&

' //
' //   MessageId: DTS_E_TXLOOKUP_UNABLETOLOCATEREFCOLUMN
' //
' //   MessageText:
' //
' //    Unable to locate reference column "%1!s!".
' //
%DTS_E_TXLOOKUP_UNABLETOLOCATEREFCOLUMN = &HC0208235&

' //
' //   MessageId: DTS_E_TXLOOKUP_INCOMPATIBLEDATATYPES
' //
' //   MessageText:
' //
' //    %1!s! and reference column named "%2!s!" have incompatible data types.
' //
%DTS_E_TXLOOKUP_INCOMPATIBLEDATATYPES = &HC0208236&

' //
' //   MessageId: DTS_E_TXLOOKUP_PARAMMETADATAMISMATCH
' //
' //   MessageText:
' //
' //    The parameterized SQL statement yields metadata which does not match the main SQL statement.
' //
%DTS_E_TXLOOKUP_PARAMMETADATAMISMATCH = &HC0208237&

' //
' //   MessageId: DTS_E_TXLOOKUP_INCORRECTNUMOFPARAMETERS
' //
' //   MessageText:
' //
' //    The parameterized SQL statement contains an incorrect number of parameters. Expected %1!d!, but found %2!d!.
' //
%DTS_E_TXLOOKUP_INCORRECTNUMOFPARAMETERS = &HC0208238&

' //
' //   MessageId: DTS_E_TXLOOKUP_INVALIDJOINTYPE
' //
' //   MessageText:
' //
' //    %1!s! has a datatype which cannot be joined on.
' //
%DTS_E_TXLOOKUP_INVALIDJOINTYPE   = &HC0208239&

' //
' //   MessageId: DTS_E_TXLOOKUP_INVALIDCOPYTYPE
' //
' //   MessageText:
' //
' //    %1!s! has a datatype which cannot be copied.
' //
%DTS_E_TXLOOKUP_INVALIDCOPYTYPE   = &HC020823A&

' ////////////////////////////////////////////////////////////////////////////
' //   The specified column has a data type that is not supported here.

' //
' //   MessageId: DTS_E_INSERTERINVALIDCOLUMNDATATYPE
' //
' //   MessageText:
' //
' //    The %1!s! has an unsupported datatype. It must be DT_STR or DT_WSTR.
' //
%DTS_E_INSERTERINVALIDCOLUMNDATATYPE = &HC020823B&

' //
' //   MessageId: DTS_E_EXTRACTORINVALIDCOLUMNDATATYPE
' //
' //   MessageText:
' //
' //    The %1!s! has an unsupported datatype. It must be DT_STR, DT_WSTR, DT_TEXT, DT_NTEXT, or DT_IMAGE.
' //
%DTS_E_EXTRACTORINVALIDCOLUMNDATATYPE = &HC020823C&

' //
' //   MessageId: DTS_E_TXCHARMAPINVALIDCOLUMNDATATYPE
' //
' //   MessageText:
' //
' //    The %1!s! has an unsupported datatype. It must be DT_STR, DT_WSTR, DT_TEXT, or DT_NTEXT.
' //
%DTS_E_TXCHARMAPINVALIDCOLUMNDATATYPE = &HC020823D&

' ////////////////////////////////////////////////////////////////////////////
' //   Not enough system handles are available to TxSort.

' //
' //   MessageId: DTS_E_SORTCANTCREATEEVENT
' //
' //   MessageText:
' //
' //    The Sort transformation cannot create an event to communicate with its worker threads. Not enough system handles are available to the Sort transformation.
' //
%DTS_E_SORTCANTCREATEEVENT        = &HC020823E&

' ////////////////////////////////////////////////////////////////////////////
' //   Not enough memory is available to TxSort.

' //
' //   MessageId: DTS_E_SORTCANTCREATETHREAD
' //
' //   MessageText:
' //
' //    The Sort transformation cannot create a worker thread. Not enough memory is available to Sort transformation.
' //
%DTS_E_SORTCANTCREATETHREAD       = &HC020823F&

' ////////////////////////////////////////////////////////////////////////////
' //   An internal error in TxSort -- comparison should never fail.

' //
' //   MessageId: DTS_E_SORTCANTCOMPARE
' //
' //   MessageText:
' //
' //    The Sort transformation failed to compare row %1!d! in buffer ID %2!d! to row %3!d! in buffer ID %4!d!.
' //
%DTS_E_SORTCANTCOMPARE            = &HC0208240&

' ////////////////////////////////////////////////////////////////////////////
' //   Check the SQLCommand property, the select statement must yield at least one column.

' //
' //   MessageId: DTS_E_TXLOOKUP_TOOFEWREFERENCECOLUMNS
' //
' //   MessageText:
' //
' //    The Lookup transformation reference metadata contains too few columns. Check the SQLCommand property. The SELECT statement must return at least one column.
' //
%DTS_E_TXLOOKUP_TOOFEWREFERENCECOLUMNS = &HC0208242&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate an array of ColumnInfo structs

' //
' //   MessageId: DTS_E_TXLOOKUP_MALLOCERR_REFERENCECOLUMNINFO
' //
' //   MessageText:
' //
' //    Unable to allocate memory for an array of ColumnInfo structures.
' //
%DTS_E_TXLOOKUP_MALLOCERR_REFERENCECOLUMNINFO = &HC0208243&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate an array of ColumnPair structs

' //
' //   MessageId: DTS_E_TXLOOKUP_MALLOCERR_REFERENCECOLUMNPAIR
' //
' //   MessageText:
' //
' //    Could not allocate memory for an array of ColumnPair structures.
' //
%DTS_E_TXLOOKUP_MALLOCERR_REFERENCECOLUMNPAIR = &HC0208244&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate an array of BUFFCOL structs for creation of main workspace

' //
' //   MessageId: DTS_E_TXLOOKUP_MALLOCERR_BUFFCOL
' //
' //   MessageText:
' //
' //    Unable to allocate memory for an array of BUFFCOL structures for the creation of a main workspace.
' //
%DTS_E_TXLOOKUP_MALLOCERR_BUFFCOL = &HC0208245&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not create main workspace buffer

' //
' //   MessageId: DTS_E_TXLOOKUP_MAINWORKSPACE_CREATEERR
' //
' //   MessageText:
' //
' //    Unable to create a main workspace buffer.
' //
%DTS_E_TXLOOKUP_MAINWORKSPACE_CREATEERR = &HC0208246&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate memory for hash table

' //
' //   MessageId: DTS_E_TXLOOKUP_HASHTABLE_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for hash table.
' //
%DTS_E_TXLOOKUP_HASHTABLE_MALLOCERR = &HC0208247&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not create a heap for hash nodes.

' //
' //   MessageId: DTS_E_TXLOOKUP_HASHNODEHEAP_CREATEERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory to create a heap for hash nodes.
' //
%DTS_E_TXLOOKUP_HASHNODEHEAP_CREATEERR = &HC0208248&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate memory for hash node heap

' //
' //   MessageId: DTS_E_TXLOOKUP_HASHNODEHEAP_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for a hash node heap.
' //
%DTS_E_TXLOOKUP_HASHNODEHEAP_MALLOCERR = &HC0208249&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not create a heap for LRU nodes.

' //
' //   MessageId: DTS_E_TXLOOKUP_LRUNODEHEAP_CREATEERR
' //
' //   MessageText:
' //
' //    Unable to create a heap for LRU nodes. An out-of-memory condition occurred.
' //
%DTS_E_TXLOOKUP_LRUNODEHEAP_CREATEERR = &HC020824A&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate memory for LRU node heap

' //
' //   MessageId: DTS_E_TXLOOKUP_LRUNODEHEAP_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for the LRU node heap. An out-of-memory condition occurred.
' //
%DTS_E_TXLOOKUP_LRUNODEHEAP_MALLOCERR = &HC020824B&

' ////////////////////////////////////////////////////////////////////////////
' //   Check SQLCommand and SqlCommandParam properties

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_LOADCOLUMNMETADATA
' //
' //   MessageText:
' //
' //    OLE DB error occurred while loading column metadata. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_LOADCOLUMNMETADATA = &HC020824C&

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_GETIROWSET
' //
' //   MessageText:
' //
' //    OLE DB error occurred while fetching rowset. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_GETIROWSET = &HC020824D&

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_FILLBUFFER
' //
' //   MessageText:
' //
' //    OLE DB error occurred while populating internal cache. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_FILLBUFFER = &HC020824E&

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_BINDPARAMETERS
' //
' //   MessageText:
' //
' //    OLE DB error occurred while binding parameters. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_BINDPARAMETERS = &HC020824F&

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_CREATEBINDING
' //
' //   MessageText:
' //
' //    OLE DB error occurred while creating bindings. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_CREATEBINDING = &HC0208250&

' ////////////////////////////////////////////////////////////////////////////
' //   This is a very bad error, we got an unexpected case in a switch statement

' //
' //   MessageId: DTS_E_TXLOOKUP_INVALID_CASE
' //
' //   MessageText:
' //
' //    An invalid case was encountered in a switch statement during runtime.
' //
%DTS_E_TXLOOKUP_INVALID_CASE      = &HC0208251&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate new row for main workspace buffer

' //
' //   MessageId: DTS_E_TXLOOKUP_MAINWORKSPACE_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for a new row for the main workspace buffer. An out-of-memory condition occurred.
' //
%DTS_E_TXLOOKUP_MAINWORKSPACE_MALLOCERR = &HC0208252&

' ////////////////////////////////////////////////////////////////////////////
' //   Check SQLCommand and SqlCommandParam properties

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_GETPARAMIROWSET
' //
' //   MessageText:
' //
' //    OLE DB error occurred while fetching parameterized rowset. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_GETPARAMIROWSET = &HC0208253&

' //
' //   MessageId: DTS_E_TXLOOKUP_OLEDBERR_GETPARAMSINGLEROW
' //
' //   MessageText:
' //
' //    OLE DB error occurred while fetching parameterized row. Check SQLCommand and SqlCommandParam properties.
' //
%DTS_E_TXLOOKUP_OLEDBERR_GETPARAMSINGLEROW = &HC0208254&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate new row for main workspace buffer

' //
' //   MessageId: DTS_E_TXAGG_MAINWORKSPACE_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for a new row for the main workspace buffer. An out-of-memory condition occurred.
' //
%DTS_E_TXAGG_MAINWORKSPACE_MALLOCERR = &HC0208255&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not create main workspace buffer

' //
' //   MessageId: DTS_E_TXAGG_MAINWORKSPACE_CREATEERR
' //
' //   MessageText:
' //
' //    Unable to create a main workspace buffer.
' //
%DTS_E_TXAGG_MAINWORKSPACE_CREATEERR = &HC0208256&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate memory for hash table

' //
' //   MessageId: DTS_E_TXAGG_HASHTABLE_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for the hash table.
' //
%DTS_E_TXAGG_HASHTABLE_MALLOCERR  = &HC0208257&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not create a heap for hash nodes.

' //
' //   MessageId: DTS_E_TXAGG_HASHNODEHEAP_CREATEERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory to create a heap for the hash nodes.
' //
%DTS_E_TXAGG_HASHNODEHEAP_CREATEERR = &HC0208258&

' ////////////////////////////////////////////////////////////////////////////
' //   Could not allocate memory for hash node heap

' //
' //   MessageId: DTS_E_TXAGG_HASHNODEHEAP_MALLOCERR
' //
' //   MessageText:
' //
' //    Unable to allocate memory for the hash node heap.
' //
%DTS_E_TXAGG_HASHNODEHEAP_MALLOCERR = &HC0208259&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not create a heap for Count Distinct nodes.

' //
' //  MessageId: DTS_E_TXAGG_CDNODEHEAP_CREATEERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory to create a heap for CountDistinct nodes.
' //
%DTS_E_TXAGG_CDNODEHEAP_CREATEERR = &HC020825A&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate memory for Count Distinct node heap

' //
' //  MessageId: DTS_E_TXAGG_CDNODEHEAP_MALLOCERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory for CountDistinct node heap.
' //
%DTS_E_TXAGG_CDNODEHEAP_MALLOCERR = &HC020825B&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not create a heap for Count Distinct chains .

' //
' //  MessageId: DTS_E_TXAGG_CDCHAINHEAP_CREATEERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory to create a heap for CountDistinct chains.
' //
%DTS_E_TXAGG_CDCHAINHEAP_CREATEERR = &HC020825C&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate memory for count distinct hash table

' //
' //  MessageId: DTS_E_TXAGG_CDHASHTABLE_CREATEERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory for CountDistinct hash table.
' //
%DTS_E_TXAGG_CDHASHTABLE_CREATEERR = &HC020825D&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate new row for Count Distinct workspace buffer

' //
' //  MessageId: DTS_E_TXAGG_CDWORKSPACE_MALLOCERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory for a new row for the CountDistinct workspace buffer.
' //
%DTS_E_TXAGG_CDWORKSPACE_MALLOCERR = &HC020825E&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not create Count Distinct workspace buffer

' //
' //  MessageId: DTS_E_TXAGG_CDWORKSPACE_CREATEERR
' //
' //  MessageText:
' //
' //   Unable to create a CountDistinct workspace buffer.
' //
%DTS_E_TXAGG_CDWORKSPACE_CREATEERR = &HC020825F&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate memory for Count Distinct Collapse array

' //
' //  MessageId: DTS_E_TXAGG_CDCOLLASSEARRAY_MALLOCERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory for CountDistinct Collapse array.
' //
%DTS_E_TXAGG_CDCOLLASSEARRAY_MALLOCERR = &HC0208260&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate memory for Count Distinct chains .

' //
' //  MessageId: DTS_E_TXAGG_CDCHAINHEAP_MALLOCERR
' //
' //  MessageText:
' //
' //   Unable to allocate memory for CountDistinct chains.
' //
%DTS_E_TXAGG_CDCHAINHEAP_MALLOCERR = &HC0208261&

' ////////////////////////////////////////////////////////////////////////////
' //  The input column mapped to an output column for copymap don't have the same metadata (datatype, precision, scale, length or codepage

' //
' //  MessageId: DTS_E_TXCOPYMAP_MISMATCHED_COLUMN_METADATA
' //
' //  MessageText:
' //
' //   Columns with lineage IDs %1!d! and %2!d! have mismatched metadata. The input column that is mapped to an output column for copymap does not have the same metadata (datatype, precision, scale, length, or codepage).
' //
%DTS_E_TXCOPYMAP_MISMATCHED_COLUMN_METADATA = &HC0208262&

' ////////////////////////////////////////////////////////////////////////////
' //  The copyColumnID property of the output column is incorrect

' //
' //  MessageId: DTS_E_TXCOPYMAP_INCORRECT_OUTPUT_COLUMN_MAPPING
' //
' //  MessageText:
' //
' //   The output column with lineage ID "%1!d!" is incorrectly mapped to an input column. The CopyColumnId property of the output column is not correct.
' //
%DTS_E_TXCOPYMAP_INCORRECT_OUTPUT_COLUMN_MAPPING = &HC0208263&

' ////////////////////////////////////////////////////////////////////////////
' //  Error should have been previously reported.]

' //
' //  MessageId: DTS_E_CANTGETBLOBDATA
' //
' //  MessageText:
' //
' //   Failed to retrieve long data for column "%1!s!".
' //
%DTS_E_CANTGETBLOBDATA            = &HC0208265&

' ////////////////////////////////////////////////////////////////////////////
' //  Error should have been previously reported.

' //
' //  MessageId: DTS_E_CANTADDBLOBDATA
' //
' //  MessageText:
' //
' //   Long data was retrieved for a column but cannot be added to the Data Flow task buffer.
' //
%DTS_E_CANTADDBLOBDATA            = &HC0208266&

' ////////////////////////////////////////////////////////////////////////////
' //  The package is bad -- the output columns should not be there.

' //
' //  MessageId: DTS_E_MCASTOUTPUTCOLUMNS
' //
' //  MessageText:
' //
' //   Output "%1!s!" (%2!d!) has output columns, but multicast outputs do not declare columns. The package is damaged.
' //
%DTS_E_MCASTOUTPUTCOLUMNS         = &HC0208267&

' ////////////////////////////////////////////////////////////////////////////
' //  Check to see if the rll file is present

' //
' //  MessageId: DTS_E_UNABLETOGETLOCALIZEDRESOURCE
' //
' //  MessageText:
' //
' //   Unable to load a localized resource ID %1!d!. Verify that the RLL file is present.
' //
%DTS_E_UNABLETOGETLOCALIZEDRESOURCE = &HC0208273&

' ////////////////////////////////////////////////////////////////////////////
' //  Invalid Events interface passed to the pipelinexml module

' //
' //  MessageId: DTS_E_DTPXMLEVENTSCACHEERR
' //
' //  MessageText:
' //
' //   Cannot acquire Events Interface. An invalid Events interface was passed to the data flow module for persisting to XML.
' //
%DTS_E_DTPXMLEVENTSCACHEERR       = &HC0208274&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting a path object during xml load

' //
' //  MessageId: DTS_E_DTPXMLPATHLOADERR
' //
' //  MessageText:
' //
' //   An error occurred while setting a path object during XML load.
' //
%DTS_E_DTPXMLPATHLOADERR          = &HC0208275&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting an input object during xml load

' //
' //  MessageId: DTS_E_DTPXMLINPUTLOADERR
' //
' //  MessageText:
' //
' //   Error setting input object during XML load.
' //
%DTS_E_DTPXMLINPUTLOADERR         = &HC0208276&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting an output object during xml load

' //
' //  MessageId: DTS_E_DTPXMLOUTPUTLOADERR
' //
' //  MessageText:
' //
' //   Error setting output object during XML load.
' //
%DTS_E_DTPXMLOUTPUTLOADERR        = &HC0208277&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting an input column object during xml load

' //
' //  MessageId: DTS_E_DTPXMLINPUTCOLUMNLOADERR
' //
' //  MessageText:
' //
' //   Error setting input column object during XML load.
' //
%DTS_E_DTPXMLINPUTCOLUMNLOADERR   = &HC0208278&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting an output column object during xml load

' //
' //  MessageId: DTS_E_DTPXMLOUTPUTCOLUMNLOADERR
' //
' //  MessageText:
' //
' //   Error setting output column object during XML load.
' //
%DTS_E_DTPXMLOUTPUTCOLUMNLOADERR  = &HC0208279&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting a property object during xml load

' //
' //  MessageId: DTS_E_DTPXMLPROPERTYLOADERR
' //
' //  MessageText:
' //
' //   Error setting property object during XML load.
' //
%DTS_E_DTPXMLPROPERTYLOADERR      = &HC0208280&

' ////////////////////////////////////////////////////////////////////////////
' //  Something went wrong when setting a connection object during xml load

' //
' //  MessageId: DTS_E_DTPXMLCONNECTIONLOADERR
' //
' //  MessageText:
' //
' //   Error setting connection object during XML load.
' //
%DTS_E_DTPXMLCONNECTIONLOADERR    = &HC0208281&

' //
' //  MessageId: DTS_E_FG_MISSING_OUTPUT_COLUMNS
' //
' //  MessageText:
' //
' //   Special transformation-specific columns are either missing or have incorrect types.
' //
%DTS_E_FG_MISSING_OUTPUT_COLUMNS  = &HC0208282&

' //
' //  MessageId: DTS_E_FG_PREPARE_TABLES_AND_ACCESSORS
' //
' //  MessageText:
' //
' //   Fuzzy Grouping transformation failed to create required tables and accessors.
' //
%DTS_E_FG_PREPARE_TABLES_AND_ACCESSORS = &HC0208283&

' //
' //  MessageId: DTS_E_FG_COPY_INPUT
' //
' //  MessageText:
' //
' //   Fuzzy Grouping transformation failed to copy input.
' //
%DTS_E_FG_COPY_INPUT              = &HC0208284&

' //
' //  MessageId: DTS_E_FG_GENERATE_GROUPS
' //
' //  MessageText:
' //
' //   Fuzzy Grouping transformation failed to generate groups.
' //
%DTS_E_FG_GENERATE_GROUPS         = &HC0208285&

' //
' //  MessageId: DTS_E_FG_LEADING_TRAILING
' //
' //  MessageText:
' //
' //   An unexpected error occurred in Fuzzy Grouping when applying the settings of property '%1!s!'.
' //
%DTS_E_FG_LEADING_TRAILING        = &HC0208286&

' //
' //  MessageId: DTS_E_FG_PICK_CANONICAL
' //
' //  MessageText:
' //
' //   The Fuzzy Grouping transformation failed to pick a canonical row of data to use in standardizing the data.
' //
%DTS_E_FG_PICK_CANONICAL          = &HC0208287&

' //
' //  MessageId: DTS_E_FG_NOBLOBS
' //
' //  MessageText:
' //
' //   Fuzzy Grouping does not support input columns of type IMAGE, TEXT, or NTEXT.
' //
%DTS_E_FG_NOBLOBS                 = &HC0208288&

' //
' //  MessageId: DTS_E_FG_FUZZY_MATCH_ON_NONSTRING
' //
' //  MessageText:
' //
' //   A fuzzy match is specified on column "%1!s!" (%2!d!) that is not a data type of DT_STR or DT_WSTR.
' //
%DTS_E_FG_FUZZY_MATCH_ON_NONSTRING = &HC0208289&

' //
' //  MessageId: DTS_E_FUZZYGROUPINGINTERNALPIPELINEERROR
' //
' //  MessageText:
' //
' //   A Fuzzy Grouping transformation pipeline error occurred and returned error code 0x%1!8.8X!: "%2!s!".
' //
%DTS_E_FUZZYGROUPINGINTERNALPIPELINEERROR = &HC020828A&

' ////////////////////////////////////////////////////////////////////////////
' //  Generally, this arises because we need to persist DT_STR data to SQL and there is no easy way to map the given codepage to a SQL Collation

' //
' //  MessageId: DTS_E_CODE_PAGE_NOT_SUPPORTED
' //
' //  MessageText:
' //
' //   The code page %1!d! specified on column "%2!s!" (%3!d!) is not supported.  You must first convert this column to DT_WSTR which can be done by inserting a Data Conversion Transform before this one.
' //
%DTS_E_CODE_PAGE_NOT_SUPPORTED    = &HC020828B&

' //
' //  MessageId: DTS_E_SETEODFAILED
' //
' //  MessageText:
' //
' //   Failure encountered while setting end of data flag for the buffer driving output "%1!s!" (%2!d!).
' //
%DTS_E_SETEODFAILED               = &HC0208294&

' ////////////////////////////////////////////////////////////////////////////
' //  Out of memory or internal error. Internal error should have been previously reported.

' //
' //  MessageId: DTS_E_CANTCLONE
' //
' //  MessageText:
' //
' //   The input buffer could not be cloned. An out-of-memory condition occurred or there was an internal error.
' //
%DTS_E_CANTCLONE                  = &HC0208296&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTKATAKANAHIRAGANA
' //
' //  MessageText:
' //
' //   Column "%1!s!" requests that Katakana and Hiragana characters be produced at the same time.
' //
%DTS_E_TXCHARMAP_CANTKATAKANAHIRAGANA = &HC02082F9&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTSIMPLECOMPLEX
' //
' //  MessageText:
' //
' //   Column "%1!s!" requests that Simple Chinese and Traditional Chinese characters be produced at the same time.
' //
%DTS_E_TXCHARMAP_CANTSIMPLECOMPLEX = &HC02082FA&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTFULLHALF
' //
' //  MessageText:
' //
' //   Column "%1!s!" requests operations to generate both full width and half width characters.
' //
%DTS_E_TXCHARMAP_CANTFULLHALF     = &HC02082FB&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTCHINAJAPAN
' //
' //  MessageText:
' //
' //   Column "%1!s!" combines operations on Japanese characters with operations for Chinese characters.
' //
%DTS_E_TXCHARMAP_CANTCHINAJAPAN   = &HC02082FC&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTCASECHINESE
' //
' //  MessageText:
' //
' //   Column "%1!s!" combines operations on Chinese characters with uppercase and lowercase operations.
' //
%DTS_E_TXCHARMAP_CANTCASECHINESE  = &HC02082FD&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTCASEJAPANESE
' //
' //  MessageText:
' //
' //   Column "%1!s!" combines operations on Japanese characters with uppercase and lowercase operations.
' //
%DTS_E_TXCHARMAP_CANTCASEJAPANESE = &HC02082FE&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTBOTHCASE
' //
' //  MessageText:
' //
' //   Column "%1!s!" maps the column to both uppercase and lowercase.
' //
%DTS_E_TXCHARMAP_CANTBOTHCASE     = &HC02082FF&

' //
' //  MessageId: DTS_E_TXCHARMAP_CANTLINGUISTIC
' //
' //  MessageText:
' //
' //   Column "%1!s!" combines flags other than uppercase and lowercase with the linguistic casing operation.
' //
%DTS_E_TXCHARMAP_CANTLINGUISTIC   = &HC0208300&

' //
' //  MessageId: DTS_E_TXCHARMAP_INVALIDMAPFLAGANDDATATYPE
' //
' //  MessageText:
' //
' //   The data type of column "%1!s!" cannot be mapped as specified.
' //
%DTS_E_TXCHARMAP_INVALIDMAPFLAGANDDATATYPE = &HC0208301&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if the version persisted in the index metadata does not match that which the current code was built for.  Fix by rebuilding the index with the current version of the code.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_UNSUPPORTED_MATCH_INDEX_VERSION
' //
' //  MessageText:
' //
' //   The version (%1!s!) of the pre-existing match index "%2!s!" is not supported. The version expected is "%3!s!". This error occurrs if the version persisted in the index metadata does not match the version which the
' //   current code was built for. Fix the error by rebuilding the index with the current version of the code.
' //
%DTS_E_TXFUZZYLOOKUP_UNSUPPORTED_MATCH_INDEX_VERSION = &HC0208302&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if we can't load the metadata record from the specified pre-built index

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INVALID_MATCH_INDEX
' //
' //  MessageText:
' //
' //   The table "%1!s!" does not appear to be a valid pre-built match index. This error occurrs the metadata record cannot be loaded from the specified pre-built index.
' //
%DTS_E_TXFUZZYLOOKUP_INVALID_MATCH_INDEX = &HC0208303&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if there is a failure when loading the index metadata via OLEDB

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_UNABLE_TO_READ_MATCH_INDEX
' //
' //  MessageText:
' //
' //   Unable to read specified pre-built match index "%1!s!".  OLEDB Error code: 0x%2!8.8X!.
' //
%DTS_E_TXFUZZYLOOKUP_UNABLE_TO_READ_MATCH_INDEX = &HC0208304&

' ////////////////////////////////////////////////////////////////////////////
' //  There were no input columns with valid joins to reference table columns.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_NO_JOIN_COLUMNS
' //
' //  MessageText:
' //
' //   There were no input columns with a valid join to a reference table column.  Make sure that there is at least one join defined using the input column properties JoinToReferenceColumn and JoinType.
' //
%DTS_E_TXFUZZYLOOKUP_NO_JOIN_COLUMNS = &HC0208305&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens when the index was built with the column not being a fuzzy join column

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INDEX_DOES_NOT_CONTAIN_COLUMN
' //
' //  MessageText:
' //
' //   The specified pre-existing match index "%1!s!" was not originally built with fuzzy match information for column "%2!s!".  It must be rebuilt to include this information. This error occurs when the index was built
' //   with the column not being a fuzzy join column.
' //
%DTS_E_TXFUZZYLOOKUP_INDEX_DOES_NOT_CONTAIN_COLUMN = &HC0208306&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if the name for the property does not conform to the specs for a valid SQL identifier name

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_IDENTIFIER_PROPERTY
' //
' //  MessageText:
' //
' //   The name "%1!s!" given for property "%2!s!" is not a valid SQL identifier name. This error occurs if the name for the property does not conform to the specifications for a valid SQL identifier name.
' //
%DTS_E_TXFUZZYLOOKUP_IDENTIFIER_PROPERTY = &HC0208307&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_MINSIMILARITY_INVALID
' //
' //  MessageText:
' //
' //   The MinSimilarity threshold property on the Fuzzy Lookup transformation must be a value greater than or equal to 0.0 but less than 1.0.
' //
%DTS_E_TXFUZZYLOOKUP_MINSIMILARITY_INVALID = &HC0208309&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INVALID_PROPERTY_VALUE
' //
' //  MessageText:
' //
' //   The value "%1!s!" for property "%2!s!" is not valid.
' //
%DTS_E_TXFUZZYLOOKUP_INVALID_PROPERTY_VALUE = &HC020830A&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens because we can only support fuzzy join between string columns

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_FUZZY_JOIN_DATATYPES
' //
' //  MessageText:
' //
' //   The fuzzy lookup specified between input column "%1!s!" and reference column "%2!s!" is not valid because fuzzy joins are only supported between string columns, types DT_STR and DT_WSTR.
' //
%DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_FUZZY_JOIN_DATATYPES = &HC020830B&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens because we can only support exact join between columns with equal data types or a DT_STR/DT_WSTR combination

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_EXACT_JOIN_DATATYPES
' //
' //  MessageText:
' //
' //   The exact lookup columns, "%1!s!" and "%2!s!", do not have equal data types or are not comparable string types. Exact joins are supported between columns with equal data types or a DT_STR and DT_WSTR combination.
' //
%DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_EXACT_JOIN_DATATYPES = &HC020830C&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens because we can only support copying from ref to output between columns with equal data types or a DT_STR/DT_WSTR combination

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_COPYCOLUMN_DATATYPES
' //
' //  MessageText:
' //
' //   The copy columns, "%1!s!" and "%2!s!", do not have equal data types or are not trivially convertible string types. This occurs because copying from reference to output between columns with equal data types,
' //   or a DT_STR and DT_WSTR combination, is supported, but other types are not.
' //
%DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_COPYCOLUMN_DATATYPES = &HC020830D&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens because we can only support passthru from input to output between columns with equal data types

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_PASSTHRUCOLUMN_DATATYPES
' //
' //  MessageText:
' //
' //   The passthrough columns, "%1!s!" and "%2!s!", do not have equal data types. Only columns with equal data types are supported as passthrough columns from input to output.
' //
%DTS_E_TXFUZZYLOOKUP_INCOMPATIBLE_PASSTHRUCOLUMN_DATATYPES = &HC020830E&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_UNABLETOLOCATEREFCOLUMN
' //
' //  MessageText:
' //
' //   Cannot locate reference column "%1!s!".
' //
%DTS_E_TXFUZZYLOOKUP_UNABLETOLOCATEREFCOLUMN = &HC020830F&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens when neither or both CopyColumn and PassThruColumn are set to non empty values

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_OUTPUT_COLUMN_MUST_BE_PASSTHRU_COLUMN_OR_A_COPY_COLUMN
' //
' //  MessageText:
' //
' //   An output column must have exactly one CopyColumn or PassThruColumn property specified. This error occurs when neither the CopyColumn or the PassThruColumn properties, or both the CopyColumn and PassThruColumn properties, are set to non-empty values.
' //
%DTS_E_TXFUZZYLOOKUP_OUTPUT_COLUMN_MUST_BE_PASSTHRU_COLUMN_OR_A_COPY_COLUMN = &HC0208311&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens when the input column id specified on an output column as a passthru column is not found in the set of inputs

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_PASSTHRU_COLUMN_NOT_FOUND
' //
' //  MessageText:
' //
' //   The source lineage id '%1!d!' specified for property '%2!s!' on output column '%3!s!' was not found in the input column collection. This occurs when the input column id specified on an output column
' //   as a passthrough column is not found in the set of inputs.
' //
%DTS_E_TXFUZZYLOOKUP_PASSTHRU_COLUMN_NOT_FOUND = &HC0208312&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if the schema/query of the reference table has changed since the pre-existing match index was built.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INDEXED_COLUMN_NOT_FOUND_IN_REF_TABLE
' //
' //  MessageText:
' //
' //   The column "%1!s!" in the pre-built index "%2!s!" was not found in the reference table/query. This happens if the schema/query of the reference table has changed since the pre-existing match index was built.
' //
%DTS_E_TXFUZZYLOOKUP_INDEXED_COLUMN_NOT_FOUND_IN_REF_TABLE = &HC0208313&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_TOKEN_TOO_LONG
' //
' //  MessageText:
' //
' //   The component encountered a token that was larger than 2147483647 characters.
' //
%DTS_E_TXFUZZYLOOKUP_TOKEN_TOO_LONG = &HC0208314&

' ////////////////////////////////////////////////////////////////////////////
' //  The metadata for the named column doesn't match on datatype.

' //
' //  MessageId: DTS_E_RAWMETADATAMISMATCHTYPE
' //
' //  MessageText:
' //
' //   The output file cannot be appended. Column "%1!s!" matches by name, but the column in the file has type %2!s! and the input column has type %3!s!. The metadata for the column does not match on data type.
' //
%DTS_E_RAWMETADATAMISMATCHTYPE    = &HC0208315&

' ////////////////////////////////////////////////////////////////////////////
' //  The metadata for the named column doesn't match in length.

' //
' //  MessageId: DTS_E_RAWMETADATAMISMATCHSIZE
' //
' //  MessageText:
' //
' //   The output file cannot be appended. Column "%1!s!" matches by name, but the column in the file has maximum length %2!d! and the input column has type %3!d!. The metadata for the column does not match in length.
' //
%DTS_E_RAWMETADATAMISMATCHSIZE    = &HC0208316&

' ////////////////////////////////////////////////////////////////////////////
' //  The metadata for the named column doesn't match on code page.

' //
' //  MessageId: DTS_E_RAWMETADATAMISMATCHCODEPAGE
' //
' //  MessageText:
' //
' //   The output file cannot be appended. Column "%1!s!" matches by name, but the column in the file has code page %2!d! and the input column has code page %3!d!. The metadata for the named column does not match on code page.
' //
%DTS_E_RAWMETADATAMISMATCHCODEPAGE = &HC0208317&

' ////////////////////////////////////////////////////////////////////////////
' //  The metadata for the named column doesn't match on precision.

' //
' //  MessageId: DTS_E_RAWMETADATAMISMATCHPRECISION
' //
' //  MessageText:
' //
' //   The output file cannot be appended. Column "%1!s!" matches by name, but the column in the file has precision %2!d! and the input column has precision %3!d!. The metadata for the named column does not match on precision.
' //
%DTS_E_RAWMETADATAMISMATCHPRECISION = &HC0208318&

' ////////////////////////////////////////////////////////////////////////////
' //  The metadata for the named column doesn't match on scale.

' //
' //  MessageId: DTS_E_RAWMETADATAMISMATCHSCALE
' //
' //  MessageText:
' //
' //   The output file cannot be appended. Column "%1!s!" matches by name, but the column in the file has scale %2!d! and the input column has scale %3!d!.  The metadata for the named column does not match on scale.
' //
%DTS_E_RAWMETADATAMISMATCHSCALE   = &HC0208319&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if IDBProperties on the connection didn't give us back the information we needed to verify the DBMS name & version.

' //
' //  MessageId: DTS_E_COULD_NOT_DETERMINE_DATASOURCE_DBMSNAME
' //
' //  MessageText:
' //
' //   Unable to determine the DBMS name and version on "%1!s!". This occurs if the IDBProperties on the connection did not return information needed to verify the DBMS name and version.
' //
%DTS_E_COULD_NOT_DETERMINE_DATASOURCE_DBMSNAME = &HC020831A&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if IDBProperties on the connection didn't return a the correct SQL version.

' //
' //  MessageId: DTS_E_INCORRECT_SQL_SERVER_VERSION
' //
' //  MessageText:
' //
' //   The DBMS type or version of "%1!s!" is not supported.  A connection to Microsoft SQL Server version 8.0 or later is required. This occurs if IDBProperties on the connection did not return a the correct version.
' //
%DTS_E_INCORRECT_SQL_SERVER_VERSION = &HC020831B&

' //
' //  MessageId: DTS_E_CANTDELETEERRORCOLUMNS
' //
' //  MessageText:
' //
' //   The %1!s! is a special error output column and cannot be deleted.
' //
%DTS_E_CANTDELETEERRORCOLUMNS     = &HC020831D&

' ////////////////////////////////////////////////////////////////////////////
' //  Unexpected column datatype.  There is likely another custom property on the column that is fixing the type to be a certain expected type.

' //
' //  MessageId: DTS_E_UNEXPECTEDCOLUMNDATATYPE
' //
' //  MessageText:
' //
' //   The data type specified for column "%1!s!" is not the expected type "%2!s!".
' //
%DTS_E_UNEXPECTEDCOLUMNDATATYPE   = &HC020831E&

' ////////////////////////////////////////////////////////////////////////////
' //  The referenced input column was not found in the input column collection.

' //
' //  MessageId: DTS_E_INPUTCOLUMNNOTFOUND
' //
' //  MessageText:
' //
' //   The input column lineage ID "%1!s!" referenced by property "%2!s!" on output column "%3!s!" could not be located in the input column collection.
' //
%DTS_E_INPUTCOLUMNNOTFOUND        = &HC020831F&

' ////////////////////////////////////////////////////////////////////////////
' //  The input column referenced by the output column is not a join column.

' //
' //  MessageId: DTS_E_TXGROUPDUPS_INPUTCOLUMNNOTJOINED
' //
' //  MessageText:
' //
' //   The input column "%1!s!" referenced by the "%2!s!" property on output column "%3!s!" must have property ToBeCleaned=True and have a valid ExactFuzzy property value.
' //
%DTS_E_TXGROUPDUPS_INPUTCOLUMNNOTJOINED = &HC0208320&

' ////////////////////////////////////////////////////////////////////////////
' //  If CopyRefTable is false, the Reference Table must have a clustered index on an integer identity column.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_REF_TABLE_MISSING_IDENTITY_INDEX
' //
' //  MessageText:
' //
' //   The reference table '%1!s!' does not have a clustered index on an integer identity column, which is required if the property 'CopyRefTable' is set to FALSE. If CopyRefTable is false, the reference
' //   table must have a clustered index on an integer identity column.
' //
%DTS_E_TXFUZZYLOOKUP_REF_TABLE_MISSING_IDENTITY_INDEX = &HC0208322&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens because when we make a copy of the reference table we need to add our own integer identity column to it - and only one identity column is allowed per table.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_REF_CONTAINS_NON_INTEGER_IDENT_COLUMN
' //
' //  MessageText:
' //
' //   The reference table '%1!s!' contains a non-integer type identity column which is not supported. Use a view of the table without the column '%2!s!'.  This error occurs  because when a copy is made of the reference table,
' //   an integer identity column is added, and only one identity column is allowed per table.
' //
%DTS_E_TXFUZZYLOOKUP_REF_CONTAINS_NON_INTEGER_IDENT_COLUMN = &HC0208323&

' ////////////////////////////////////////////////////////////////////////////
' //  Not allowed because they are both weighing factors for score

' //
' //  MessageId: DTS_E_TXFUZZY_MATCHCONTRIBUTION_AND_HIERARCHY_SPECIFIED
' //
' //  MessageText:
' //
' //   Both MatchContribution and hierarchy information cannot be specified at the same time. This is not allowed because these properties are both weighing factors for scoring.
' //
%DTS_E_TXFUZZY_MATCHCONTRIBUTION_AND_HIERARCHY_SPECIFIED = &HC0208324&

' ////////////////////////////////////////////////////////////////////////////
' //  Overlaps and gaps are not allowed for simplicity.

' //
' //  MessageId: DTS_E_TXFUZZY_HIERARCHY_INCORRECT
' //
' //  MessageText:
' //
' //   Levels in hierarchy should be unique numbers . Valid  level in hierarchy values are integers greater than or equal to 1. The smaller the number is, the lower the column is in the hierarchy.
' //   The default value is 0, indicating that the column is not part of a hierarchy. Overlaps and gaps are not allowed.
' //
%DTS_E_TXFUZZY_HIERARCHY_INCORRECT = &HC0208325&

' ////////////////////////////////////////////////////////////////////////////
' //  There must be at least one fuzzy join column defined.

' //
' //  MessageId: DTS_E_TXFUZZYGROUPING_INSUFFICIENT_FUZZY_JOIN_COLUMNS
' //
' //  MessageText:
' //
' //   No columns to fuzzy group on were defined.  There must be at least one input column with column properties ToBeCleaned=true and ExactFuzzy=2.
' //
%DTS_E_TXFUZZYGROUPING_INSUFFICIENT_FUZZY_JOIN_COLUMNS = &HC0208326&

' ////////////////////////////////////////////////////////////////////////////
' //  pColumn->IsValid returned false

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_COLUMNINVALID
' //
' //  MessageText:
' //
' //   The column with ID '%1!d!' was not valid for an undetermined reason.
' //
%DTS_E_TXFUZZYLOOKUP_COLUMNINVALID = &HC0208329&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_UNSUPPORTEDDATATYPE
' //
' //  MessageText:
' //
' //   The data type of column '%1!s!' is not supported.
' //
%DTS_E_TXFUZZYLOOKUP_UNSUPPORTEDDATATYPE = &HC020832A&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_OUTPUTLENGTHMISMATCH
' //
' //  MessageText:
' //
' //   The length of output column '%1!s!' is less than that of its source column '%2!s!'.
' //
%DTS_E_TXFUZZYLOOKUP_OUTPUTLENGTHMISMATCH = &HC020832C&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTEXACTNUMBEROFINPUTCOLUMNS
' //
' //  MessageText:
' //
' //   There should be only one input column.
' //
%DTS_E_TERMEXTRACTION_INCORRECTEXACTNUMBEROFINPUTCOLUMNS = &HC020832F&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTEXACTNUMBEROFOUTPUTCOLUMNS
' //
' //  MessageText:
' //
' //   There should be exactly two output columns.
' //
%DTS_E_TERMEXTRACTION_INCORRECTEXACTNUMBEROFOUTPUTCOLUMNS = &HC0208330&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTDATATYPEOFINPUTCOLUMN
' //
' //  MessageText:
' //
' //   The input column can only have DT_WSTR or DT_NTEXT as its data type.
' //
%DTS_E_TERMEXTRACTION_INCORRECTDATATYPEOFINPUTCOLUMN = &HC0208331&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTDATATYPEOFOUTPUTCOLUMN
' //
' //  MessageText:
' //
' //   The output column [%1!d!] can only have '%2!s!' as its data type.
' //
%DTS_E_TERMEXTRACTION_INCORRECTDATATYPEOFOUTPUTCOLUMN = &HC0208332&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTDATATYPEOFREFERENCECOLUMN
' //
' //  MessageText:
' //
' //   The reference column can only have DT_STR or DT_WSTR as its data type.
' //
%DTS_E_TERMEXTRACTION_INCORRECTDATATYPEOFREFERENCECOLUMN = &HC0208333&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_UNABLETOLOCATEREFCOLUMN
' //
' //  MessageText:
' //
' //   An error occurred while locating the reference column '%1!s!'.
' //
%DTS_E_TERMEXTRACTION_UNABLETOLOCATEREFCOLUMN = &HC0208334&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTTERMTYPE
' //
' //  MessageText:
' //
' //   The Term Type of the transformation can only be WordOnly, PhraseOnly or WordPhrase.
' //
%DTS_E_TERMEXTRACTION_INCORRECTTERMTYPE = &HC0208335&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTFREQUENCYTHRESHOLD
' //
' //  MessageText:
' //
' //   The value of Frequency Threshold should not be lower than '%1!d!'.
' //
%DTS_E_TERMEXTRACTION_INCORRECTFREQUENCYTHRESHOLD = &HC0208336&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTMAXLENOFTERM
' //
' //  MessageText:
' //
' //   The value of Max Length of Term should not be lower than '%1!d!'.
' //
%DTS_E_TERMEXTRACTION_INCORRECTMAXLENOFTERM = &HC0208337&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_TOOFEWREFERENCECOLUMNS
' //
' //  MessageText:
' //
' //   Term Extraction reference metadata contains too few columns.
' //
%DTS_E_TERMEXTRACTION_TOOFEWREFERENCECOLUMNS = &HC0208338&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate an array of ColumnInfo structs

' //
' //  MessageId: DTS_E_TERMEXTRACTION_MALLOCERR_REFERENCECOLUMNINFO
' //
' //  MessageText:
' //
' //   An error occurred while allocating memory.
' //
%DTS_E_TERMEXTRACTION_MALLOCERR_REFERENCECOLUMNINFO = &HC0208339&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not create main workspace buffer

' //
' //  MessageId: DTS_E_TERMEXTRACTION_MAINWORKSPACE_CREATEERR
' //
' //  MessageText:
' //
' //   An error occurred while creating a workspace buffer.
' //
%DTS_E_TERMEXTRACTION_MAINWORKSPACE_CREATEERR = &HC020833A&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_OLEDBERR_CREATEBINDING
' //
' //  MessageText:
' //
' //   An OLEDB error occurred while creating bindings.
' //
%DTS_E_TERMEXTRACTION_OLEDBERR_CREATEBINDING = &HC020833B&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_OLEDBERR_GETIROWSET
' //
' //  MessageText:
' //
' //   An OLEDB error occurred while fetching rowsets.
' //
%DTS_E_TERMEXTRACTION_OLEDBERR_GETIROWSET = &HC020833C&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_OLEDBERR_FILLBUFFER
' //
' //  MessageText:
' //
' //   An OLEDB error occurred while populating internal cache.
' //
%DTS_E_TERMEXTRACTION_OLEDBERR_FILLBUFFER = &HC020833D&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_PROCESSERR
' //
' //  MessageText:
' //
' //   An error occurred while extracting terms on row %1!ld!, column %2!ld!. The error code returned was 0x%3!8.8X!. Please remove it from the input as a work-around.
' //
%DTS_E_TERMEXTRACTION_PROCESSERR  = &HC020833E&

' //
' //  MessageId: DTS_E_TERMEXTRACTIONORLOOKUP_PROCESSERR_DEPOSITFULL
' //
' //  MessageText:
' //
' //   The number of the term candidates exceeds its limit, 4G.
' //
%DTS_E_TERMEXTRACTIONORLOOKUP_PROCESSERR_DEPOSITFULL = &HC020833F&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INVALIDOUTTERMTABLEORCOLUMN
' //
' //  MessageText:
' //
' //   The reference table, view, or column that is used for Exclusion Terms is not valid.
' //
%DTS_E_TERMEXTRACTION_INVALIDOUTTERMTABLEORCOLUMN = &HC0208340&

' ////////////////////////////////////////////////////////////////////////////
' //  A conversion from DT_STR to DT_WSTR is required and so DT_STR column must not be longer that 4000 characters.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_STRINGCOLUMNTOOLONG
' //
' //  MessageText:
' //
' //   The length of string column '%1!s!' exceeds 4000 characters.  A conversion from DT_STR to DT_WSTR is necessary, so a truncation would occur.  Either reduce the column width or use only DT_WSTR column types.
' //
%DTS_E_TXFUZZYLOOKUP_STRINGCOLUMNTOOLONG = &HC0208341&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_OUTTERMTABLEANDCOLUMNNOTSET
' //
' //  MessageText:
' //
' //   The reference table, view, or column to be used for an Exclusion Terms has not been set.
' //
%DTS_E_TERMEXTRACTION_OUTTERMTABLEANDCOLUMNNOTSET = &HC0208342&

' //
' //  MessageId: DTS_E_TERMLOOKUP_TOOFEWOUTPUTCOLUMNS
' //
' //  MessageText:
' //
' //   Term Lookup contains too few output columns.
' //
%DTS_E_TERMLOOKUP_TOOFEWOUTPUTCOLUMNS = &HC0208343&

' //
' //  MessageId: DTS_E_TERMLOOKUP_INCORRECTDATATYPEOFREFERENCECOLUMN
' //
' //  MessageText:
' //
' //   The reference column can only have DT_STR or DT_WSTR as its data type.
' //
%DTS_E_TERMLOOKUP_INCORRECTDATATYPEOFREFERENCECOLUMN = &HC0208344&

' //
' //  MessageId: DTS_E_TERMLOOKUP_UNABLETOLOCATEREFCOLUMN
' //
' //  MessageText:
' //
' //   An error occurred while locating the reference column '%1!s!'.
' //
%DTS_E_TERMLOOKUP_UNABLETOLOCATEREFCOLUMN = &HC0208345&

' //
' //  MessageId: DTS_E_TERMLOOKUP_TOOFEWREFERENCECOLUMNS
' //
' //  MessageText:
' //
' //   Term Lookup reference metadata contains too few columns.
' //
%DTS_E_TERMLOOKUP_TOOFEWREFERENCECOLUMNS = &HC0208346&

' //
' //  MessageId: DTS_E_TERMEXTRACTIONORLOOKUP_TESTOFFSETERROR
' //
' //  MessageText:
' //
' //   An error occurred while normalizing words.
' //
%DTS_E_TERMEXTRACTIONORLOOKUP_TESTOFFSETERROR = &HC0208347&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not create main workspace buffer

' //
' //  MessageId: DTS_E_TERMLOOKUP_MAINWORKSPACE_CREATEERR
' //
' //  MessageText:
' //
' //   An error occurred while creating a workspace buffer.
' //
%DTS_E_TERMLOOKUP_MAINWORKSPACE_CREATEERR = &HC0208348&

' //
' //  MessageId: DTS_E_TERMLOOKUP_OLEDBERR_CREATEBINDING
' //
' //  MessageText:
' //
' //   An OLEDB error occurred while creating bindings.
' //
%DTS_E_TERMLOOKUP_OLEDBERR_CREATEBINDING = &HC0208349&

' //
' //  MessageId: DTS_E_TERMLOOKUP_OLEDBERR_GETIROWSET
' //
' //  MessageText:
' //
' //   An OLEDB error occurred while fetching rowsets.
' //
%DTS_E_TERMLOOKUP_OLEDBERR_GETIROWSET = &HC020834A&

' //
' //  MessageId: DTS_E_TERMLOOKUP_OLEDBERR_FILLBUFFER
' //
' //  MessageText:
' //
' //   An OLEDB error occurred while populating internal cache.
' //
%DTS_E_TERMLOOKUP_OLEDBERR_FILLBUFFER = &HC020834B&

' //
' //  MessageId: DTS_E_TERMLOOKUP_PROCESSERR
' //
' //  MessageText:
' //
' //   An error occurred while looking up terms on row %1!ld!, column %2!ld!. The error code returned was 0x%3!8.8X!. Please remove it from the input as a work-around.
' //
%DTS_E_TERMLOOKUP_PROCESSERR      = &HC020834C&

' //
' //  MessageId: DTS_E_TERMLOOKUP_TEXTIDINPUTCOLUMNNOTMAPPEDWITHOUTPUTCOLUMN
' //
' //  MessageText:
' //
' //   At least one Passthrough column is not mapped to an output column.
' //
%DTS_E_TERMLOOKUP_TEXTIDINPUTCOLUMNNOTMAPPEDWITHOUTPUTCOLUMN = &HC020834D&

' //
' //  MessageId: DTS_E_TERMLOOKUP_INCORRECTEXACTNUMBEROFTEXTCOLUMNS
' //
' //  MessageText:
' //
' //   There should be exactly one input column mapped to one reference column.
' //
%DTS_E_TERMLOOKUP_INCORRECTEXACTNUMBEROFTEXTCOLUMNS = &HC020834E&

' //
' //  MessageId: DTS_E_TERMLOOKUP_TEXTINPUTCOLUMNHAVEINCORRECTDATATYPE
' //
' //  MessageText:
' //
' //   The input column mapped to a reference column can only have DT_NTXT or DT_WSTR as its data type.
' //
%DTS_E_TERMLOOKUP_TEXTINPUTCOLUMNHAVEINCORRECTDATATYPE = &HC020834F&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens if we can't parse the table name from the input string.  There may be unquoted spaces in the name.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_INVALID_MATCH_INDEX_NAME
' //
' //  MessageText:
' //
' //   The reference table name "%1!s!" is not a valid SQL identifier. This error occurs the the table name cannot be parsed from the input string. There may be unquoted spaces in the name. Verify that the name is correctly quoted.
' //
%DTS_E_TXFUZZYLOOKUP_INVALID_MATCH_INDEX_NAME = &HC0208354&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_TERMFILTERSTARTITERATIONERROR
' //
' //  MessageText:
' //
' //   An error occurred while the Term Filter was starting its iteration.
' //
%DTS_E_TERMEXTRACTION_TERMFILTERSTARTITERATIONERROR = &HC0208355&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_EMPTYTERMRESULTERROR
' //
' //  MessageText:
' //
' //   An error occurred while reclaiming the buffer used for caching terms. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_EMPTYTERMRESULTERROR = &HC0208356&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_STDLENGTHERROR
' //
' //  MessageText:
' //
' //   An std::length_error occurred from the STL containers.
' //
%DTS_E_TERMEXTRACTION_STDLENGTHERROR = &HC0208357&

' //
' //  MessageId: DTS_E_TERMLOOKUP_SAVEWORDWITHPUNCTERROR
' //
' //  MessageText:
' //
' //   An error occurred while saving words with punctuation characters. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_SAVEWORDWITHPUNCTERROR = &HC0208358&

' //
' //  MessageId: DTS_E_TERMLOOKUP_ADDREFERENCETERM
' //
' //  MessageText:
' //
' //   An error occurred while processing the %1!ld!th reference term. The error code returned was 0x%2!8.8X!. Please remove the reference term from your reference table as a work-around.
' //
%DTS_E_TERMLOOKUP_ADDREFERENCETERM = &HC0208359&

' //
' //  MessageId: DTS_E_TERMLOOKUP_SORREFERENCETERM
' //
' //  MessageText:
' //
' //   An error occurred while sorting reference terms. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_SORREFERENCETERM = &HC020835A&

' //
' //  MessageId: DTS_E_TERMLOOKUP_COUNTTERM
' //
' //  MessageText:
' //
' //   An error occurred while counting term candidates. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_COUNTTERM       = &HC020835B&

' ////////////////////////////////////////////////////////////////////////////
' //  If Exhautive was set to true, the entire reference table must fit in main memory and/or the memory limit specified by MaxMemoryUsage.  We ran out of memory budget.

' //
' //  MessageId: DTS_E_FUZZYLOOKUP_REFERENCECACHEFULL
' //
' //  MessageText:
' //
' //   Fuzzy Lookup was unable to load the entire reference table into main memory as is required when the Exhaustive property is enabled.  Either we ran out of system memory or a limit was specified
' //   for MaxMemoryUsage which was not sufficient to load the reference table.  Either set MaxMemoryUsage to 0 or increase it significantly.  Alternatively, disable Exhaustive.
' //
%DTS_E_FUZZYLOOKUP_REFERENCECACHEFULL = &HC020835C&

' //
' //  MessageId: DTS_E_TERMLOOKUP_INITIALIZE
' //
' //  MessageText:
' //
' //   An error occurred while initialzing the engine of Term Lookup. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_INITIALIZE      = &HC020835D&

' //
' //  MessageId: DTS_E_TERMLOOKUP_PROCESSSENTENCE
' //
' //  MessageText:
' //
' //   An error occurred while processing sentences. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_PROCESSSENTENCE = &HC020835E&

' //
' //  MessageId: DTS_E_TEXTMININGBASE_APPENDTOTEMPBUFFER
' //
' //  MessageText:
' //
' //   An error occurred while adding strings to an internal buffer. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TEXTMININGBASE_APPENDTOTEMPBUFFER = &HC020835F&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_SAVEPOSTAG
' //
' //  MessageText:
' //
' //   An error occurred while saving part-of-speech tags from an internal buffer. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_SAVEPOSTAG  = &HC0208360&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_COUNTTERM
' //
' //  MessageText:
' //
' //   An error occurred while counting term candidates. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_COUNTTERM   = &HC0208361&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INITPOSPROCESSOR
' //
' //  MessageText:
' //
' //   An error occurred while initializing the part-of-speech processor. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_INITPOSPROCESSOR = &HC0208362&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INITFSA
' //
' //  MessageText:
' //
' //   An error occurred while loading the finite state automata. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_INITFSA     = &HC0208363&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INITIALIZE
' //
' //  MessageText:
' //
' //   An error occurred while initalizing the engine of Term Extraction. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_INITIALIZE  = &HC0208364&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_PROCESSSENTENCE
' //
' //  MessageText:
' //
' //   An error occurred while processing within a sentence. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_PROCESSSENTENCE = &HC0208365&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INITPOSTAGVECTOR
' //
' //  MessageText:
' //
' //   An error occurred while initalizing the part-of-speech processor. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_INITPOSTAGVECTOR = &HC0208366&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_SAVEPTRSTRING
' //
' //  MessageText:
' //
' //   An error occurred while adding strings to an internal buffer. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_SAVEPTRSTRING = &HC0208367&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_ADDWORDTODECODER
' //
' //  MessageText:
' //
' //   An error occurred while adding words to a statistical decoder. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_ADDWORDTODECODER = &HC0208368&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_DECODE
' //
' //  MessageText:
' //
' //   An error occurred while decoding for a sentence. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_DECODE      = &HC0208369&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_SETEXCLUDEDTERM
' //
' //  MessageText:
' //
' //   An error occurred while setting exclusion terms. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_SETEXCLUDEDTERM = &HC020836A&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_PROCESSDOCUMENT
' //
' //  MessageText:
' //
' //   An error occurred while processing a document in the input. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMEXTRACTION_PROCESSDOCUMENT = &HC020836B&

' //
' //  MessageId: DTS_E_TEXTMININGBASE_TESTPERIOD
' //
' //  MessageText:
' //
' //   An error occurred while testing whether a dot is a part of an acronym. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TEXTMININGBASE_TESTPERIOD  = &HC020836C&

' //
' //  MessageId: DTS_E_TERMLOOKUP_ENGINEADDREFERENCETERM
' //
' //  MessageText:
' //
' //   An error occurred while setting reference terms. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_ENGINEADDREFERENCETERM = &HC020836D&

' //
' //  MessageId: DTS_E_TERMLOOKUP_PROCESSDOCUMENT
' //
' //  MessageText:
' //
' //   An error occurred while processing a document in the input. The error code returned was 0x%1!8.8X!.
' //
%DTS_E_TERMLOOKUP_PROCESSDOCUMENT = &HC020836E&

' //
' //  MessageId: DTS_E_INVALIDBULKINSERTPROPERTYVALUE
' //
' //  MessageText:
' //
' //   The value for the property %1!s! is %2!d!, which is not allowed.  The value must be greater than or equal to %3!d!.
' //
%DTS_E_INVALIDBULKINSERTPROPERTYVALUE = &HC020836F&

' //
' //  MessageId: DTS_E_INVALIDBULKINSERTFIRSTROWLASTROWVALUES
' //
' //  MessageText:
' //
' //   The value for the property %1!s! is %2!d!, which must be less than or equal to the value of %3!d! for property %4!s!.
' //
%DTS_E_INVALIDBULKINSERTFIRSTROWLASTROWVALUES = &HC0208370&

' //
' //  MessageId: DTS_E_FUZZYLOOKUPUNABLETODELETEEXISTINGMATCHINDEX
' //
' //  MessageText:
' //
' //   An error was encountered when trying to delete the existing fuzzy match index named "%1!s!". It is possible that this table was not created by Fuzzy Lookup (or this version of Fuzzy Lookup),
' //   it has been damaged, or there is another problem. Try manually deleting the table named "%2!s!" or specify a different name for the MatchIndexName property.
' //
%DTS_E_FUZZYLOOKUPUNABLETODELETEEXISTINGMATCHINDEX = &HC0208371&

' //
' //  MessageId: DTS_E_TERMEXTRACTION_INCORRECTSCORETYPE
' //
' //  MessageText:
' //
' //   The Score Type of the transformation can only be Frequency or TFIDF.
' //
%DTS_E_TERMEXTRACTION_INCORRECTSCORETYPE = &HC0208372&

' //
' //  MessageId: DTS_E_FUZZYLOOKUPREFTABLETOOBIG
' //
' //  MessageText:
' //
' //   The reference table specified has too many rows. Fuzzy Lookup only works with reference tables having less than 1 billion rows. Consider using a smaller view of your reference table.
' //
%DTS_E_FUZZYLOOKUPREFTABLETOOBIG  = &HC0208373&

' //
' //  MessageId: DTS_E_FUZZYLOOKUPUNABLETODETERMINEREFERENCETABLESIZE
' //
' //  MessageText:
' //
' //   Unable to determine the size of the reference table '%1!s!'.  It is possible that this object is a view and not a table.  Fuzzy Lookup does not support views when CopyReferentaceTable=false.
' //   Make sure that the table exists and that CopyReferenceTable=true.
' //
%DTS_E_FUZZYLOOKUPUNABLETODETERMINEREFERENCETABLESIZE = &HC0208374&

' ////////////////////////////////////////////////////////////////////////////
' //  The output column has an unsupported data type.

' //
' //  MessageId: DTS_E_XMLSRCOUTPUTCOLUMNDATATYPENOTSUPPORTED
' //
' //  MessageText:
' //
' //   The SSIS Data Flow Task data type "%1!s!" on the %2!s! is not supported for the %3!s!.
' //
%DTS_E_XMLSRCOUTPUTCOLUMNDATATYPENOTSUPPORTED = &HC0208377&

' ////////////////////////////////////////////////////////////////////////////
' //  The attempt to set the data type properties of the specified output column failed. Either the output ID or the output column ID was invalid.

' //
' //  MessageId: DTS_E_XMLSRCCANNOTFINDCOLUMNTOSETDATATYPE
' //
' //  MessageText:
' //
' //   Unable to set data type properties for the output colum with ID %1!d! on the output with ID %2!d!. The output or column could not be found.
' //
%DTS_E_XMLSRCCANNOTFINDCOLUMNTOSETDATATYPE = &HC0208378&

' ////////////////////////////////////////////////////////////////////////////
' //  The property is read only.

' //
' //  MessageId: DTS_E_CUSTOMPROPERTYISREADONLY
' //
' //  MessageText:
' //
' //   The value of custom property "%1!s!" on the %2!s! cannot be changed.
' //
%DTS_E_CUSTOMPROPERTYISREADONLY   = &HC0208379&

' //
' //  MessageId: DTS_E_OUTPUTCOLUMNHASNOERRORCOLUMN
' //
' //  MessageText:
' //
' //   The %1!s! on the non-error output has no corresponding output column on the error output.
' //
%DTS_E_OUTPUTCOLUMNHASNOERRORCOLUMN = &HC020837A&

' //
' //  MessageId: DTS_E_ERRORCOLUMNHASNOOUTPUTCOLUMN
' //
' //  MessageText:
' //
' //   The %1!s! on the error output has no corresponding output column on the non-error output.
' //
%DTS_E_ERRORCOLUMNHASNOOUTPUTCOLUMN = &HC020837B&

' //
' //  MessageId: DTS_E_ERRORCOLUMNHASINCORRECTPROPERTIES
' //
' //  MessageText:
' //
' //   The %1!s! on the error output has properties that do not match the properties of its corresponding data source column.
' //
%DTS_E_ERRORCOLUMNHASINCORRECTPROPERTIES = &HC020837C&

' ////////////////////////////////////////////////////////////////////////////
' //  Output column types cannot be changed from the default that was chosen based on the source type.

' //
' //  MessageId: DTS_E_ADOSRCOUTPUTCOLUMNDATATYPECANNOTBECHANGED
' //
' //  MessageText:
' //
' //   The data type of output columns on the %1!s! cannot be changed.
' //
%DTS_E_ADOSRCOUTPUTCOLUMNDATATYPECANNOTBECHANGED = &HC020837D&

' ////////////////////////////////////////////////////////////////////////////
' //  The source column on the DataReader has an unsupported data type.

' //
' //  MessageId: DTS_E_ADOSRCDATATYPENOTSUPPORTED
' //
' //  MessageText:
' //
' //   The data type "%1!s!" found on column "%2!s!" is not supported for the %3!s!.
' //
%DTS_E_ADOSRCDATATYPENOTSUPPORTED = &HC020837E&

' ////////////////////////////////////////////////////////////////////////////
' //  The type of the output column does not match the type of the source column on the DataReader.

' //
' //  MessageId: DTS_E_ADOSRCDATATYPEMISMATCH
' //
' //  MessageText:
' //
' //   The data type of "%1!s!" does not match the data type "%2!s!" of the source column "%3!s!".
' //
%DTS_E_ADOSRCDATATYPEMISMATCH     = &HC020837F&

' ////////////////////////////////////////////////////////////////////////////
' //  The output column does not match any source column.

' //
' //  MessageId: DTS_E_ADOSRCCOLUMNNOTINSCHEMAROWSET
' //
' //  MessageText:
' //
' //   The %1!s! does not have a matching source column in the DataReader schema.
' //
%DTS_E_ADOSRCCOLUMNNOTINSCHEMAROWSET = &HC0208380&

' //
' //  MessageId: DTS_E_TERMLOOKUP_INVALIDREFERENCETERMTABLEORCOLUMN
' //
' //  MessageText:
' //
' //   The reference table/view or column used for the reference terms is invalid.
' //
%DTS_E_TERMLOOKUP_INVALIDREFERENCETERMTABLEORCOLUMN = &HC0208381&

' //
' //  MessageId: DTS_E_TERMLOOKUP_REFERENCETERMTABLEANDCOLUMNNOTSET
' //
' //  MessageText:
' //
' //   The reference table/view or column used for the reference terms has not been set.
' //
%DTS_E_TERMLOOKUP_REFERENCETERMTABLEANDCOLUMNNOTSET = &HC0208382&

' ////////////////////////////////////////////////////////////////////////////
' //  This column is mapped to an external metadata column that already has another column mapped to it

' //
' //  MessageId: DTS_E_COLUMNMAPPEDTOALREADYMAPPEDEXTERNALMETADATACOLUMN
' //
' //  MessageText:
' //
' //   The %1!s! is mapped to the external metadata column with ID %2!ld!, which is already mapped to another column.
' //
%DTS_E_COLUMNMAPPEDTOALREADYMAPPEDEXTERNALMETADATACOLUMN = &HC0208383&

' ////////////////////////////////////////////////////////////////////////////
' //  The specified multi-part SQL identifier has too many prefixes.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_TOOMANYPREFIXES
' //
' //  MessageText:
' //
' //   The SQL object name '%1!s!' specified for property '%2!s!' contains more than the maximum number of prefixes.  The maximum is 2.
' //
%DTS_E_TXFUZZYLOOKUP_TOOMANYPREFIXES = &HC0208384&

' ////////////////////////////////////////////////////////////////////////////
' //  The value was too large to fit in the type of the destination column.

' //
' //  MessageId: DTS_E_MGDSRCSTATIC_OVERFLOW
' //
' //  MessageText:
' //
' //   The value was too large to fit in the column.
' //
%DTS_E_MGDSRCSTATIC_OVERFLOW      = &HC0208385&

' //
' //  MessageId: DTS_E_DATAREADERDESTREADERISCLOSED
' //
' //  MessageText:
' //
' //   The SSIS IDataReader is closed.
' //
%DTS_E_DATAREADERDESTREADERISCLOSED = &HC0208386&

' //
' //  MessageId: DTS_E_DATAREADERDESTREADERISATEND
' //
' //  MessageText:
' //
' //   The SSIS IDataReader is past the end of the result set.
' //
%DTS_E_DATAREADERDESTREADERISATEND = &HC0208387&

' //
' //  MessageId: DTS_E_DATAREADERDESTINVALIDCOLUMNORDINAL
' //
' //  MessageText:
' //
' //   The ordinal position of the column is not valid.
' //
%DTS_E_DATAREADERDESTINVALIDCOLUMNORDINAL = &HC0208388&

' //
' //  MessageId: DTS_E_DATAREADERDESTCANNOTCONVERT
' //
' //  MessageText:
' //
' //   Cannot convert the %1!s! from data type "%2!s!" to data type "%3!s!".
' //
%DTS_E_DATAREADERDESTCANNOTCONVERT = &HC0208389&

' //
' //  MessageId: DTS_E_DATAREADERDESTINVALIDCODEPAGE
' //
' //  MessageText:
' //
' //   The %1!s! has unsupported code page %2!d!.
' //
%DTS_E_DATAREADERDESTINVALIDCODEPAGE = &HC020838A&

' ////////////////////////////////////////////////////////////////////////////
' //  There is an output column in the external metadata column collection that does not exist in the XML schema.

' //
' //  MessageId: DTS_E_XMLSRCEXTERNALMETADATACOLUMNNOTINSCHEMA
' //
' //  MessageText:
' //
' //   The %1!s! has no mapping to the XML schema.
' //
%DTS_E_XMLSRCEXTERNALMETADATACOLUMNNOTINSCHEMA = &HC020838B&

' ////////////////////////////////////////////////////////////////////////////
' //  There is no column in the external metadata column collection for a column in the XML schema.

' //
' //  MessageId: DTS_E_XMLSRCSCHEMACOLUMNNOTINEXTERNALMETADATA
' //
' //  MessageText:
' //
' //   The column %1!s! in table %2!s! in the XML schema does not have a mapping in the external metadata column collection.
' //
%DTS_E_XMLSRCSCHEMACOLUMNNOTINEXTERNALMETADATA = &HC020838C&

' ////////////////////////////////////////////////////////////////////////////
' //  The input column mapped to an output column doesn't have the same metadata (datatype, precision, scale, length or codepage).

' //
' //  MessageId: DTS_E_TXTERMLOOKUP_MISMATCHED_COLUMN_METADATA
' //
' //  MessageText:
' //
' //   Columns with lineage IDs %1!d! and %2!d! have mismatched metadata. The input column that is mapped to an output column does not have the same metadata (datatype, precision, scale, length, or codepage).
' //
%DTS_E_TXTERMLOOKUP_MISMATCHED_COLUMN_METADATA = &HC020838D&

' ////////////////////////////////////////////////////////////////////////////
' //  Read was not called before the time specified in the ReadTimeout property.

' //
' //  MessageId: DTS_E_DATAREADERDESTREADERTIMEOUT
' //
' //  MessageText:
' //
' //   The SSIS IDataReader is closed. The read timeout has expired.
' //
%DTS_E_DATAREADERDESTREADERTIMEOUT = &HC020838E&

' ////////////////////////////////////////////////////////////////////////////
' //  The SQL command provided could not be executed.

' //
' //  MessageId: DTS_E_ADOSRCINVALIDSQLCOMMAND
' //
' //  MessageText:
' //
' //   An error occurred executing the provided SQL command.
' //
%DTS_E_ADOSRCINVALIDSQLCOMMAND    = &HC020838F&

' ////////////////////////////////////////////////////////////////////////////
' //  When reusing a match index, the JoinType for the input column must be the same as the join type used when the match index was first created.

' //
' //  MessageId: DTS_E_JOINTYPEDOESNTMATCHETI
' //
' //  MessageText:
' //
' //   The JoinType property specified for input column '%1!s!' differs from the JoinType specified for the corresponding reference table column when the Match Index was initially created.  Either rebuild
' //   the Match Index with the given JoinType or change the JoinType to match the type used when the Match Index was created.
' //
%DTS_E_JOINTYPEDOESNTMATCHETI     = &HC0208390&

' //
' //  MessageId: DTS_E_FAILEDTOFINDCOLUMNINBUFFER
' //
' //  MessageText:
' //
' //   Failed to find column "%1!s!" with lineage ID %2!d! in the buffer. The buffer manager returned error code 0x%3!8.8X!.
' //
%DTS_E_FAILEDTOFINDCOLUMNINBUFFER = &HC0209001&

' //
' //  MessageId: DTS_E_FAILEDTOGETCOLUMNINFOFROMBUFFER
' //
' //  MessageText:
' //
' //   Failed to get information for column "%1!s!" (%2!d!) from the buffer. The error code returned was 0x%3!8.8X!.
' //
%DTS_E_FAILEDTOGETCOLUMNINFOFROMBUFFER = &HC0209002&

' //
' //  MessageId: DTS_E_TXAGG_ARITHMETICOVERFLOW
' //
' //  MessageText:
' //
' //   Arithmetic overflow encountered while aggregating "%1!s!".
' //
%DTS_E_TXAGG_ARITHMETICOVERFLOW   = &HC0209011&

' //
' //  MessageId: DTS_E_FAILEDTOGETCOLINFO
' //
' //  MessageText:
' //
' //   Failed to get information for row %1!ld!, column %2!ld! from the buffer. The error code returned was 0x%3!8.8X!.
' //
%DTS_E_FAILEDTOGETCOLINFO         = &HC0209012&

' //
' //  MessageId: DTS_E_FAILEDTOSETCOLINFO
' //
' //  MessageText:
' //
' //   Failed to set information for row %1!ld!, column %2!ld! into the buffer. The error code returned was 0x%3!8.8X!.
' //
%DTS_E_FAILEDTOSETCOLINFO         = &HC0209013&

' //
' //  MessageId: DTS_E_REQUIREDBUFFERISNOTAVAILBLE
' //
' //  MessageText:
' //
' //   A required buffer is not available.
' //
%DTS_E_REQUIREDBUFFERISNOTAVAILBLE = &HC0209015&

' //
' //  MessageId: DTS_E_FAILEDTOGETBUFFERBOUNDARYINFO
' //
' //  MessageText:
' //
' //   The attempt to get buffer boundary information failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOGETBUFFERBOUNDARYINFO = &HC0209016&

' //
' //  MessageId: DTS_E_FAILEDTOSETBUFFERENDOFROWSET
' //
' //  MessageText:
' //
' //   Setting the end of rowset for the buffer failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOSETBUFFERENDOFROWSET = &HC0209017&

' //
' //  MessageId: DTS_E_FAILEDTOGETDATAFORERROROUTPUTBUFFER
' //
' //  MessageText:
' //
' //   Failed to get data for the error output buffer.
' //
%DTS_E_FAILEDTOGETDATAFORERROROUTPUTBUFFER = &HC0209018&

' //
' //  MessageId: DTS_E_FAILEDTOREMOVEROWFROMBUFFER
' //
' //  MessageText:
' //
' //   Removing a row from the buffer failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOREMOVEROWFROMBUFFER = &HC0209019&

' //
' //  MessageId: DTS_E_FAILEDTOSETBUFFERERRORINFO
' //
' //  MessageText:
' //
' //   The attempt to set buffer error information failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOSETBUFFERERRORINFO = &HC020901B&

' //
' //  MessageId: DTS_E_COLUMNSTATUSERROR
' //
' //  MessageText:
' //
' //   There was an error with %1!s! on %2!s!. The column status returned was: "%3!s!".
' //
%DTS_E_COLUMNSTATUSERROR          = &HC020901C&

' //
' //  MessageId: DTS_E_TXLOOKUP_METADATAXMLCACHEERR
' //
' //  MessageText:
' //
' //   Unable to cache reference metadata.
' //
%DTS_E_TXLOOKUP_METADATAXMLCACHEERR = &HC020901D&

' //
' //  MessageId: DTS_E_TXLOOKUP_ROWLOOKUPERROR
' //
' //  MessageText:
' //
' //   Row yielded no match during lookup.
' //
%DTS_E_TXLOOKUP_ROWLOOKUPERROR    = &HC020901E&

' //
' //  MessageId: DTS_E_INVALIDERRORDISPOSITION
' //
' //  MessageText:
' //
' //   The %1!s! has an invalid error or truncation row disposition.
' //
%DTS_E_INVALIDERRORDISPOSITION    = &HC020901F&

' //
' //  MessageId: DTS_E_FAILEDTODIRECTERRORROW
' //
' //  MessageText:
' //
' //   Directing the row to the error output failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTODIRECTERRORROW     = &HC0209022&

' //
' //  MessageId: DTS_E_FAILEDTOPREPARECOLUMNSTATUSESFORINSERT
' //
' //  MessageText:
' //
' //   Preparing column statuses for insert failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOPREPARECOLUMNSTATUSESFORINSERT = &HC0209023&

' //
' //  MessageId: DTS_E_FAILEDTOFINDCOLUMNBYLINEAGEID
' //
' //  MessageText:
' //
' //   An attempt to find %1!s! with lineage ID %2!d! in the Data Flow Task buffer failed with error code 0x%3!8.8X!.
' //
%DTS_E_FAILEDTOFINDCOLUMNBYLINEAGEID = &HC0209024&

' //
' //  MessageId: DTS_E_FAILEDTOFINDNONSPECIALERRORCOLUMN
' //
' //  MessageText:
' //
' //   Failed to find any non-special error column in %1!s!.
' //
%DTS_E_FAILEDTOFINDNONSPECIALERRORCOLUMN = &HC0209025&

' ////////////////////////////////////////////////////////////////////////////
' //  An error occurred on the specified object of the specified component.  That object's error row disposition directed the component to fail on error.

' //
' //  MessageId: DTS_E_INDUCEDTRANSFORMFAILUREONERROR
' //
' //  MessageText:
' //
' //   The "%1!s!" failed because error code 0x%2!8.8X! occurred, and the error row disposition on "%3!s!" specifies failure on error. An error occurred on the specified object of the specified component.
' //
%DTS_E_INDUCEDTRANSFORMFAILUREONERROR = &HC0209029&

' ////////////////////////////////////////////////////////////////////////////
' //  A truncation error occurred on the specified object of the specified component.  That object's truncation row disposition directed the component to fail on a truncation error.

' //
' //  MessageId: DTS_E_INDUCEDTRANSFORMFAILUREONTRUNCATION
' //
' //  MessageText:
' //
' //   The "%1!s!" failed because truncation occurred, and the truncation row disposition on "%2!s!" specifies failure on truncation. A truncation error occurred on the specified object of the specified component.
' //
%DTS_E_INDUCEDTRANSFORMFAILUREONTRUNCATION = &HC020902A&

' ////////////////////////////////////////////////////////////////////////////
' //  Expression results must be Boolean for Conditional Split.  A NULL expression result is an error.

' //
' //  MessageId: DTS_E_TXSPLITEXPRESSIONEVALUATEDTONULL
' //
' //  MessageText:
' //
' //   The expression "%1!s!" on "%2!s!" evaluated to NULL, but the "%3!s!" requires a Boolean results. Modify the error row disposition on the output to treat this result as False (Ignore Failure) or to redirect this
' //   row to the error output (Redirect Row).  The expression results must be Boolean for a Conditional Split.  A NULL expression result is an error.
' //
%DTS_E_TXSPLITEXPRESSIONEVALUATEDTONULL = &HC020902B&

' //
' //  MessageId: DTS_E_TXSPLITSTATIC_EXPRESSIONEVALUATEDTONULL
' //
' //  MessageText:
' //
' //   The expression evaluated to NULL, but a Boolean result is required. Modify the error row disposition on the output to treat this result as False (Ignore Failure) or to redirect this row to the
' //   error output (Redirect Row). The expression results must be Boolean for a Conditional Split.  A NULL expression result is an error.
' //
%DTS_E_TXSPLITSTATIC_EXPRESSIONEVALUATEDTONULL = &HC020902C&

' ////////////////////////////////////////////////////////////////////////////
' //  Only UTF-16 little endian format is supported.

' //
' //  MessageId: DTS_E_UTF16BIGENDIANFORMATNOTSUPPORTED
' //
' //  MessageText:
' //
' //   The file format of UTF-16 big endian is not supported.  Only UTF-16 little endian format is supported.
' //
%DTS_E_UTF16BIGENDIANFORMATNOTSUPPORTED = &HC020902D&

' //
' //  MessageId: DTS_E_UTF8FORMATNOTSUPPORTEDASUNICODE
' //
' //  MessageText:
' //
' //   The file format of UTF-8 is not supported as Unicode.
' //
%DTS_E_UTF8FORMATNOTSUPPORTEDASUNICODE = &HC020902E&

' //
' //  MessageId: DTS_E_DTPXMLCANTREADIDATTR
' //
' //  MessageText:
' //
' //   Cannot read ID attribute.
' //
%DTS_E_DTPXMLCANTREADIDATTR       = &HC020902F&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_CANTCONVERTVALUE
' //
' //  MessageText:
' //
' //   The data value cannot be converted for reasons other than sign mismatch or data overflow.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_CANTCONVERTVALUE = &HC0209069&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_SCHEMAVIOLATION
' //
' //  MessageText:
' //
' //   The data value violated the schema constraint.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_SCHEMAVIOLATION = &HC020906A&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_TRUNCATED
' //
' //  MessageText:
' //
' //   The data was truncated.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_TRUNCATED = &HC020906B&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_SIGNMISMATCH
' //
' //  MessageText:
' //
' //   Conversion failed because the data value was signed and the type used by the provider was unsigned.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_SIGNMISMATCH = &HC020906C&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_DATAOVERFLOW
' //
' //  MessageText:
' //
' //   Conversion failed because the data value overflowed the type used by the provider.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_DATAOVERFLOW = &HC020906D&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_UNAVAILABLE
' //
' //  MessageText:
' //
' //   No status is available.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_UNAVAILABLE = &HC020906E&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_PERMISSIONDENIED
' //
' //  MessageText:
' //
' //   The user did not have the correct permissions to write to the column.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_PERMISSIONDENIED = &HC020906F&

' //
' //  MessageId: DTS_E_COMMANDDESTINATIONADAPTERSTATIC_INTEGRITYVIOLATION
' //
' //  MessageText:
' //
' //   The data value violated the integrity constraints for the column.
' //
%DTS_E_COMMANDDESTINATIONADAPTERSTATIC_INTEGRITYVIOLATION = &HC0209070&

' //
' //  MessageId: DTS_E_OLEDBSOURCEADAPTERSTATIC_UNAVAILABLE
' //
' //  MessageText:
' //
' //   No status is available.
' //
%DTS_E_OLEDBSOURCEADAPTERSTATIC_UNAVAILABLE = &HC0209071&

' //
' //  MessageId: DTS_E_OLEDBSOURCEADAPTERSTATIC_CANTCONVERTVALUE
' //
' //  MessageText:
' //
' //   The data value cannot be converted for reasons other than sign mismatch or data overflow.
' //
%DTS_E_OLEDBSOURCEADAPTERSTATIC_CANTCONVERTVALUE = &HC0209072&

' //
' //  MessageId: DTS_E_OLEDBSOURCEADAPTERSTATIC_TRUNCATED
' //
' //  MessageText:
' //
' //   The data was truncated.
' //
%DTS_E_OLEDBSOURCEADAPTERSTATIC_TRUNCATED = &HC0209073&

' //
' //  MessageId: DTS_E_OLEDBSOURCEADAPTERSTATIC_SIGNMISMATCH
' //
' //  MessageText:
' //
' //   Conversion failed because the data value was signed and the type used by the provider was unsigned.
' //
%DTS_E_OLEDBSOURCEADAPTERSTATIC_SIGNMISMATCH = &HC0209074&

' //
' //  MessageId: DTS_E_OLEDBSOURCEADAPTERSTATIC_DATAOVERFLOW
' //
' //  MessageText:
' //
' //   Conversion failed because the data value overflowed the type used by the provider.
' //
%DTS_E_OLEDBSOURCEADAPTERSTATIC_DATAOVERFLOW = &HC0209075&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_SCHEMAVIOLATION
' //
' //  MessageText:
' //
' //   The data value violated the schema constraint.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_SCHEMAVIOLATION = &HC0209076&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_CANTCONVERTVALUE
' //
' //  MessageText:
' //
' //   The data value cannot be converted for reasons other than sign mismatch or data overflow.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_CANTCONVERTVALUE = &HC0209077&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_TRUNCATED
' //
' //  MessageText:
' //
' //   The data was truncated.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_TRUNCATED = &HC0209078&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_SIGNMISMATCH
' //
' //  MessageText:
' //
' //   Conversion failed because the data value was signed and the type used by the provider was unsigned.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_SIGNMISMATCH = &HC0209079&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_DATAOVERFLOW
' //
' //  MessageText:
' //
' //   Conversion failed because the data value overflowed the type used by the provider.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_DATAOVERFLOW = &HC020907A&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_UNAVAILABLE
' //
' //  MessageText:
' //
' //   No status is available.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_UNAVAILABLE = &HC020907B&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_PERMISSIONDENIED
' //
' //  MessageText:
' //
' //   Ther user did not have the correct permissions to write to the column.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_PERMISSIONDENIED = &HC020907C&

' //
' //  MessageId: DTS_E_OLEDBDESTINATIONADAPTERSTATIC_INTEGRITYVIOLATION
' //
' //  MessageText:
' //
' //   The data value violates integrity constraints.
' //
%DTS_E_OLEDBDESTINATIONADAPTERSTATIC_INTEGRITYVIOLATION = &HC020907D&

' //
' //  MessageId: DTS_E_TXDATACONVERTSTATIC_CANTCONVERTVALUE
' //
' //  MessageText:
' //
' //   The data value cannot be converted for reasons other than sign mismatch or data overflow.
' //
%DTS_E_TXDATACONVERTSTATIC_CANTCONVERTVALUE = &HC020907F&

' //
' //  MessageId: DTS_E_TXDATACONVERTSTATIC_TRUNCATED
' //
' //  MessageText:
' //
' //   The data was truncated.
' //
%DTS_E_TXDATACONVERTSTATIC_TRUNCATED = &HC0209080&

' //
' //  MessageId: DTS_E_TXDATACONVERTSTATIC_SIGNMISMATCH
' //
' //  MessageText:
' //
' //   Conversion failed because the data value was signed and the type used by the provider was unsigned.
' //
%DTS_E_TXDATACONVERTSTATIC_SIGNMISMATCH = &HC0209081&

' //
' //  MessageId: DTS_E_TXDATACONVERTSTATIC_DATAOVERFLOW
' //
' //  MessageText:
' //
' //   Conversion failed because the data value overflowed the type used by the data conversion transform.
' //
%DTS_E_TXDATACONVERTSTATIC_DATAOVERFLOW = &HC0209082&

' //
' //  MessageId: DTS_E_FLATFILESOURCEADAPTERSTATIC_UNAVAILABLE
' //
' //  MessageText:
' //
' //   No status is available.
' //
%DTS_E_FLATFILESOURCEADAPTERSTATIC_UNAVAILABLE = &HC0209083&

' //
' //  MessageId: DTS_E_FLATFILESOURCEADAPTERSTATIC_CANTCONVERTVALUE
' //
' //  MessageText:
' //
' //   The data value cannot be converted for reasons other than sign mismatch or data overflow.
' //
%DTS_E_FLATFILESOURCEADAPTERSTATIC_CANTCONVERTVALUE = &HC0209084&

' //
' //  MessageId: DTS_E_FLATFILESOURCEADAPTERSTATIC_TRUNCATED
' //
' //  MessageText:
' //
' //   The data was truncated.
' //
%DTS_E_FLATFILESOURCEADAPTERSTATIC_TRUNCATED = &HC0209085&

' //
' //  MessageId: DTS_E_FLATFILESOURCEADAPTERSTATIC_SIGNMISMATCH
' //
' //  MessageText:
' //
' //   Conversion failed because the data value was signed and the type used by the flat file source adapter was unsigned.
' //
%DTS_E_FLATFILESOURCEADAPTERSTATIC_SIGNMISMATCH = &HC0209086&

' //
' //  MessageId: DTS_E_FLATFILESOURCEADAPTERSTATIC_DATAOVERFLOW
' //
' //  MessageText:
' //
' //   Conversion failed because the data value overflowed the type used by the flat file source adapter.
' //
%DTS_E_FLATFILESOURCEADAPTERSTATIC_DATAOVERFLOW = &HC0209087&

' //
' //  MessageId: DTS_E_TXDATACONVERTSTATIC_UNAVAILABLE
' //
' //  MessageText:
' //
' //   No status is available.
' //
%DTS_E_TXDATACONVERTSTATIC_UNAVAILABLE = &HC020908E&

' ////////////////////////////////////////////////////////////////////////////
' //  The error code was previously reported.

' //
' //  MessageId: DTS_E_FILEOPENERR_FORREAD
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for reading failed with error code 0x%2!8.8X!.
' //
%DTS_E_FILEOPENERR_FORREAD        = &HC0209090&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD
' //
' //  MessageText:
' //
' //   Failed to open file for reading.
' //
%DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD = &HC0209091&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORWRITE
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed with error code 0x%2!8.8X!.
' //
%DTS_E_FILEOPENERR_FORWRITE       = &HC0209092&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE
' //
' //  MessageText:
' //
' //   Failed to open file for writing.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE = &HC0209093&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_INSERTERCANTREAD
' //
' //  MessageText:
' //
' //   Failed to read from file.
' //
%DTS_E_TXFILEINSERTERSTATIC_INSERTERCANTREAD = &HC0209094&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_EXTRACTORCANTWRITE
' //
' //  MessageText:
' //
' //   Failed to write to file.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_EXTRACTORCANTWRITE = &HC0209095&

' //
' //  MessageId: DTS_E_DTPXMLINVALIDPROPERTYARRAYTOOMANYVALUES
' //
' //  MessageText:
' //
' //   Too many array elements were found when parsing a property of type array. The elementCount is less than the number of array elements found.
' //
%DTS_E_DTPXMLINVALIDPROPERTYARRAYTOOMANYVALUES = &HC0209099&

' //
' //  MessageId: DTS_E_DTPXMLINVALIDPROPERTYARRAYNOTENOUGHVALUES
' //
' //  MessageText:
' //
' //   Too few array elements were found when parsing a property of type array. The elementCount is more than the number of array elements found.
' //
%DTS_E_DTPXMLINVALIDPROPERTYARRAYNOTENOUGHVALUES = &HC020909A&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORWRITE_FILENOTFOUND
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed. The file cannot be found.
' //
%DTS_E_FILEOPENERR_FORWRITE_FILENOTFOUND = &HC020909E&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_FILENOTFOUND
' //
' //  MessageText:
' //
' //   Opening the file for writing failed. The file cannot be found.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_FILENOTFOUND = &HC020909F&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORWRITE_PATHNOTFOUND
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed. The path cannot be found.
' //
%DTS_E_FILEOPENERR_FORWRITE_PATHNOTFOUND = &HC02090A0&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_PATHNOTFOUND
' //
' //  MessageText:
' //
' //   Opening the file for writing failed. The path cannot be found.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_PATHNOTFOUND = &HC02090A1&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORWRITE_TOOMANYOPENFILES
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed. There are too many files open.
' //
%DTS_E_FILEOPENERR_FORWRITE_TOOMANYOPENFILES = &HC02090A2&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_TOOMANYOPENFILES
' //
' //  MessageText:
' //
' //   Opening the file for writing failed. There are too many files open.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_TOOMANYOPENFILES = &HC02090A3&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORWRITE_ACCESSDENIED
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed. You do not have the correct permissions.
' //
%DTS_E_FILEOPENERR_FORWRITE_ACCESSDENIED = &HC02090A4&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_ACCESSDENIED
' //
' //  MessageText:
' //
' //   Opening the file for writing failed. You do not have the correct permissions.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_ACCESSDENIED = &HC02090A5&

' ////////////////////////////////////////////////////////////////////////////
' //  If AllowAppend and ForceTruncate are both false, an existing file will cause this failure.

' //
' //  MessageId: DTS_E_FILEOPENERR_FORWRITE_FILEEXISTS
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed. The file exists and cannot be overwritten. If the AllowAppend property is FALSE and the ForceTruncate property is set to FALSE, the existance of the file will cause this failure.
' //
%DTS_E_FILEOPENERR_FORWRITE_FILEEXISTS = &HC02090A6&

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_FILEEXISTS
' //
' //  MessageText:
' //
' //   Opening a file for writing failed. The file already exists and cannot be overwritten. If both the AllowAppend property and the ForceTruncate property are set to FALSE, the existance of the file will cause this failure.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEOPENERR_FORWRITE_FILEEXISTS = &HC02090A7&

' //
' //  MessageId: DTS_E_INCORRECTCUSTOMPROPERTYVALUEFOROBJECT
' //
' //  MessageText:
' //
' //   The value for custom property "%1!s!" on %2!s! is incorrect.
' //
%DTS_E_INCORRECTCUSTOMPROPERTYVALUEFOROBJECT = &HC02090A8&

' //
' //  MessageId: DTS_E_COLUMNSHAVEINCOMPATIBLEMETADATA
' //
' //  MessageText:
' //
' //   Columns "%1!s!" and "%2!s!" have incompatible metadata.
' //
%DTS_E_COLUMNSHAVEINCOMPATIBLEMETADATA = &HC02090A9&

' ////////////////////////////////////////////////////////////////////////////
' //  There was not enough disk space available to write the specified file.

' //
' //  MessageId: DTS_E_FILEWRITEERR_DISKFULL
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for writing failed because the disk is full. There is not sufficient disk space to save this file.
' //
%DTS_E_FILEWRITEERR_DISKFULL      = &HC02090AD&

' ////////////////////////////////////////////////////////////////////////////
' //  There was not enough disk space available to write the file.

' //
' //  MessageId: DTS_E_TXFILEEXTRACTORSTATIC_FILEWRITEERR_DISKFULL
' //
' //  MessageText:
' //
' //   Attempting to open the file for writing failed because the disk is full.
' //
%DTS_E_TXFILEEXTRACTORSTATIC_FILEWRITEERR_DISKFULL = &HC02090AE&

' ////////////////////////////////////////////////////////////////////////////
' //  ComparisonFlags are enabled, and generating sortkey with LCMapString failed with this specific error code.

' //
' //  MessageId: DTS_E_TXAGG_SORTKEYGENFAILED
' //
' //  MessageText:
' //
' //   Generating a sort key failed with error 0x%1!8.8X!. The ComparisonFlags are enabled, and generating a sortkey with LCMapString failed.
' //
%DTS_E_TXAGG_SORTKEYGENFAILED     = &HC02090B9&

' ////////////////////////////////////////////////////////////////////////////
' //  LCMapString failed with this specific error code.

' //
' //  MessageId: DTS_E_TXCHARMAPLCMAPFAILED
' //
' //  MessageText:
' //
' //   Transform failed to map string and returned error 0x%1!8.8X!. The LCMapString failed.
' //
%DTS_E_TXCHARMAPLCMAPFAILED       = &HC02090BA&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORREAD_FILENOTFOUND
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for reading failed. The file was not found.
' //
%DTS_E_FILEOPENERR_FORREAD_FILENOTFOUND = &HC02090BB&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_FILENOTFOUND
' //
' //  MessageText:
' //
' //   Opening a file for reading failed. The file was not found.
' //
%DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_FILENOTFOUND = &HC02090BC&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORREAD_PATHNOTFOUND
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for reading failed. The path cannot be found.
' //
%DTS_E_FILEOPENERR_FORREAD_PATHNOTFOUND = &HC02090BD&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_PATHNOTFOUND
' //
' //  MessageText:
' //
' //   Opening a file for reading failed. The path was not found.
' //
%DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_PATHNOTFOUND = &HC02090BE&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORREAD_TOOMANYOPENFILES
' //
' //  MessageText:
' //
' //   Opening the file "%1!s!" for reading failed. There are too many files open.
' //
%DTS_E_FILEOPENERR_FORREAD_TOOMANYOPENFILES = &HC02090BF&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_TOOMANYOPENFILES
' //
' //  MessageText:
' //
' //   Opening the file for reading failed. There are too many files open.
' //
%DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_TOOMANYOPENFILES = &HC02090C0&

' //
' //  MessageId: DTS_E_FILEOPENERR_FORREAD_ACCESSDENIED
' //
' //  MessageText:
' //
' //   Attempting to open the file "%1!s!" for reading failed. Access is denied.
' //
%DTS_E_FILEOPENERR_FORREAD_ACCESSDENIED = &HC02090C1&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_ACCESSDENIED
' //
' //  MessageText:
' //
' //   Opening the file for reading failed. You do not have the correct permissions.
' //
%DTS_E_TXFILEINSERTERSTATIC_FILEOPENERR_FORREAD_ACCESSDENIED = &HC02090C2&

' ////////////////////////////////////////////////////////////////////////////
' //  The ExpectBOM property was set for this file, but the BOM value in the file is missing or invalid.

' //
' //  MessageId: DTS_E_INSERTERINVALIDBOM
' //
' //  MessageText:
' //
' //   The byte order mark (BOM) value for the file "%1!s!" is 0x%2!4.4X!, but the expected value is 0x%3!4.4X!. The ExpectBOM property was set for this file, but the BOM value in the file is missing or not valid.
' //
%DTS_E_INSERTERINVALIDBOM         = &HC02090C3&

' //
' //  MessageId: DTS_E_TXFILEINSERTERSTATIC_INSERTERINVALIDBOM
' //
' //  MessageText:
' //
' //   The byte order mark (BOM) value for the file is not valid. The ExpectBOM property was set for this file, but the BOM value in the file is missing or not valid.
' //
%DTS_E_TXFILEINSERTERSTATIC_INSERTERINVALIDBOM = &HC02090C4&

' //
' //  MessageId: DTS_E_NOCOMPONENTATTACHED
' //
' //  MessageText:
' //
' //   The %1!s! is not attached to a component.  It is required that a component be attached.
' //
%DTS_E_NOCOMPONENTATTACHED        = &HC02090C5&

' //
' //  MessageId: DTS_E_TXLOOKUP_INVALIDMAXMEMORYPROP
' //
' //  MessageText:
' //
' //   The value for custom property %1!s! is incorrect.  It should be a number between %2!d! and %3!I64d!.
' //
%DTS_E_TXLOOKUP_INVALIDMAXMEMORYPROP = &HC02090C9&

' ////////////////////////////////////////////////////////////////////////////
' //  The comparison flags custom property can only be specified for group by and count distinct aggregation types

' //
' //  MessageId: DTS_E_TXAGG_COMPFLAGS_BADAGGREGATIONTYPE
' //
' //  MessageText:
' //
' //   The custom property "%1!s!" cannot be specified for the aggregation type selected for this column. The comparison flags custom property can only be specified for group by and count distinct aggregation types.
' //
%DTS_E_TXAGG_COMPFLAGS_BADAGGREGATIONTYPE = &HC02090CA&

' ////////////////////////////////////////////////////////////////////////////
' //  The comparison flags custom property can only be specified for columns with datatype DT_STR or DT_WSTR

' //
' //  MessageId: DTS_E_TXAGG_COMPFLAGS_BADDATATYPE
' //
' //  MessageText:
' //
' //   The comparison flags custom property "%1!s!" can only be specified for columns of with datatype DT_STR or DT_WSTR.
' //
%DTS_E_TXAGG_COMPFLAGS_BADDATATYPE = &HC02090CB&

' //
' //  MessageId: DTS_E_TXAGG_AGGREGATION_FAILURE
' //
' //  MessageText:
' //
' //   Aggregation on %1!s! failed with error code 0x%2!8.8X!.
' //
%DTS_E_TXAGG_AGGREGATION_FAILURE  = &HC02090CD&

' //
' //  MessageId: DTS_E_MAPPINGSETUPERROR
' //
' //  MessageText:
' //
' //   There was an error setting up the mapping. %1!s!
' //
%DTS_E_MAPPINGSETUPERROR          = &HC02090CF&

' ////////////////////////////////////////////////////////////////////////////
' //  The file name or variable that should point to the XML data might be invalid.

' //
' //  MessageId: DTS_E_XMLSRCUNABLETOREADXMLDATA
' //
' //  MessageText:
' //
' //   The %1!s! was unable to read the XML data.
' //
%DTS_E_XMLSRCUNABLETOREADXMLDATA  = &HC02090D0&

' ////////////////////////////////////////////////////////////////////////////
' //  The variable specified by the custom property was invalid or could not be locked for read.

' //
' //  MessageId: DTS_E_XMLSRCUNABLETOGETXMLDATAVARIABLE
' //
' //  MessageText:
' //
' //   The %1!s! was unable to get the variable specified by the "%2!s!" property.
' //
%DTS_E_XMLSRCUNABLETOGETXMLDATAVARIABLE = &HC02090D1&

' //
' //  MessageId: DTS_E_NODATATABLEMATCHROWID
' //
' //  MessageText:
' //
' //   The %1!s! contains a RowsetID with a value of %2!s! that does not reference a data table in the schema.
' //
%DTS_E_NODATATABLEMATCHROWID      = &HC02090D2&

' ////////////////////////////////////////////////////////////////////////////
' //  Keys or CountDistinctKeys property has a invalid value, it should be a number between 0 and ULONG_MAX, inclusive, or not set at all

' //
' //  MessageId: DTS_E_TXAGG_BADKEYSVALUE
' //
' //  MessageText:
' //
' //   The property %1!s! must either be empty, or a number between %2!u! and %3!u!. The Keys or CountDistinctKeys property has a invalid value. The property should be a number between 0 and ULONG_MAX, inclusive, or not be set.
' //
%DTS_E_TXAGG_BADKEYSVALUE         = &HC02090D6&

' ////////////////////////////////////////////////////////////////////////////
' //  We saw more than ULONG_MAX distinct key values in the main workspace

' //
' //  MessageId: DTS_E_TXAGG_TOOMANYKEYS
' //
' //  MessageText:
' //
' //   The aggregate component encountered too many distinct key combinations. It cannot accomodate more than %1!u! distinct key values. There is more than ULONG_MAX distinct key values in the main workspace.
' //
%DTS_E_TXAGG_TOOMANYKEYS          = &HC02090D7&

' ////////////////////////////////////////////////////////////////////////////
' //  We saw more than ULONG_MAX distinct values while calculating the count distinct aggregation

' //
' //  MessageId: DTS_E_TXAGG_TOOMANYCOUNTDISTINCTVALUES
' //
' //  MessageText:
' //
' //   The aggregate component encountered too many distinct values while calculating the count distinct aggregate. It cannot accomodate more than %1!u! distinct values. There were more than
' //   ULONG_MAX distinct values while calculating the count distinct aggregation.
' //
%DTS_E_TXAGG_TOOMANYCOUNTDISTINCTVALUES = &HC02090D8&

' //
' //  MessageId: DTS_E_FAILEDTOWRITETOTHEFILENAMECOLUMN
' //
' //  MessageText:
' //
' //   The attempt to write to the filename column failed with error code 0x%1!8.8X!.
' //
%DTS_E_FAILEDTOWRITETOTHEFILENAMECOLUMN = &HC02090D9&

' //
' //  MessageId: DTS_E_FAILEDTOFINDERRORCOLUMN
' //
' //  MessageText:
' //
' //   An error occurred, but the column that caused the error cannot be determined.
' //
%DTS_E_FAILEDTOFINDERRORCOLUMN    = &HC02090DC&

' ////////////////////////////////////////////////////////////////////////////
' //  Lookup transform was unable to upgrade metadata from the existing version number in a call to PerformUpgrade().

' //
' //  MessageId: DTS_E_TXLOOKUP_FAILEDUPGRADE_BAD_VERSION
' //
' //  MessageText:
' //
' //   Unable to upgrade lookup metadata from version %1!d! to %2!d!. The Lookup transform was unable to upgrade metadata from the existing version number in a call to PerformUpgrade().
' //
%DTS_E_TXLOOKUP_FAILEDUPGRADE_BAD_VERSION = &HC02090E3&

' //
' //  MessageId: DTS_E_TERMEXTRACTIONORLOOKUP_NTEXTSPLITED
' //
' //  MessageText:
' //
' //   Failed to locate the ending boundary of a sentence.
' //
%DTS_E_TERMEXTRACTIONORLOOKUP_NTEXTSPLITED = &HC02090E5&

' ////////////////////////////////////////////////////////////////////////////
' //  The sentence is segmented into several sentences.

' //
' //  MessageId: DTS_E_TERMEXTRACTION_EXCEED_MAXWORDNUM
' //
' //  MessageText:
' //
' //   The Term Extraction transformation is unable to process the input text because a sentence from the input text is too long. The sentence is segmented into several sentences.
' //
%DTS_E_TERMEXTRACTION_EXCEED_MAXWORDNUM = &HC02090E6&

' //
' //  MessageId: DTS_E_XMLSRCFAILEDTOCREATEREADER
' //
' //  MessageText:
' //
' //   The %1!s! was unable to read the XML data. %2!s!
' //
%DTS_E_XMLSRCFAILEDTOCREATEREADER = &HC02090E7&

' ////////////////////////////////////////////////////////////////////////////
' //  More detailed errors have already been posted .

' //
' //  MessageId: DTS_E_TXLOOKUP_REINITMETADATAFAILED
' //
' //  MessageText:
' //
' //   The call to Lookup transform method, ReinitializeMetadata, failed.
' //
%DTS_E_TXLOOKUP_REINITMETADATAFAILED = &HC02090F0&

' ////////////////////////////////////////////////////////////////////////////
' //  The user must specify at least one join column.

' //
' //  MessageId: DTS_E_TXLOOKUP_NOJOINS
' //
' //  MessageText:
' //
' //   The lookup transform must contain at least one input column joined to a reference column, and none were specified. You must specify at least one join column.
' //
%DTS_E_TXLOOKUP_NOJOINS           = &HC02090F1&

' ////////////////////////////////////////////////////////////////////////////
' //  Internal Error: Message string that was being posted by the managed error infrastructure contains bad format specification.

' //
' //  MessageId: DTS_E_MANAGEDERR_BADFORMATSPECIFICATION
' //
' //  MessageText:
' //
' //   The message string being posted by the managed error infrastructure contains a bad format specification. This is an internal error.
' //
%DTS_E_MANAGEDERR_BADFORMATSPECIFICATION = &HC02090F2&

' ////////////////////////////////////////////////////////////////////////////
' //  Internal Error: While formatting a message string via the managed error infrastructure, we saw a variant type that we don't support formatting.

' //
' //  MessageId: DTS_E_MANAGEDERR_UNSUPPORTEDTYPE
' //
' //  MessageText:
' //
' //   While formatting a message string using the managed error infrastructure, there was a variant type that does not have formatting support. This is an internal error.
' //
%DTS_E_MANAGEDERR_UNSUPPORTEDTYPE = &HC02090F3&

' ////////////////////////////////////////////////////////////////////////////
' //  An error occurred reading the data.

' //
' //  MessageId: DTS_E_DATAREADERSRCUNABLETOPROCESSDATA
' //
' //  MessageText:
' //
' //   The %1!s! was unable to process the data.
' //
%DTS_E_DATAREADERSRCUNABLETOPROCESSDATA = &HC02090F5&

' ////////////////////////////////////////////////////////////////////////////
' //  The value for the property was empty, but a non-empty string was expected.

' //
' //  MessageId: DTS_E_XMLSRCEMPTYPROPERTY
' //
' //  MessageText:
' //
' //   The property "%1!s!" on the %2!s! was empty.
' //
%DTS_E_XMLSRCEMPTYPROPERTY        = &HC02090F6&

' ////////////////////////////////////////////////////////////////////////////
' //  The name does not conform to the naming conventions for output names. It might contain invalid characters.

' //
' //  MessageId: DTS_E_XMLSRCINVALIDOUTPUTNAME
' //
' //  MessageText:
' //
' //   Attempting to create an output with the name "%1!s!" for the XML table with the path "%2!s!" failed because the name is invalid.
' //
%DTS_E_XMLSRCINVALIDOUTPUTNAME    = &HC02090F7&

' ////////////////////////////////////////////////////////////////////////////
' //  The value was too large to fit in the type of the destination column.

' //
' //  MessageId: DTS_E_MGDSRC_OVERFLOW
' //
' //  MessageText:
' //
' //   The value was too large to fit in the %1!s!.
' //
%DTS_E_MGDSRC_OVERFLOW            = &HC02090F8&

' //
' //  MessageId: DTS_E_DATAREADERDESTUNABLETOPROCESSDATA
' //
' //  MessageText:
' //
' //   The %1!s! was unable to process the data.
' //
%DTS_E_DATAREADERDESTUNABLETOPROCESSDATA = &HC02090F9&

' //
' //  MessageId: DTS_E_SQLCEDESTSTATIC_FAILEDTOSETVALUES
' //
' //  MessageText:
' //
' //   The SQLCE destination could not set the column values for the row.
' //
%DTS_E_SQLCEDESTSTATIC_FAILEDTOSETVALUES = &HC0209291&

' //
' //  MessageId: DTS_E_SQLCEDESTSTATIC_FAILEDTOINSERT
' //
' //  MessageText:
' //
' //   The SQLCE destination could not insert the row.
' //
%DTS_E_SQLCEDESTSTATIC_FAILEDTOINSERT = &HC0209292&

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_OLEDBERR_LOADCOLUMNMETADATA
' //
' //  MessageText:
' //
' //   Encountered OLEDB error while loading column metadata.
' //
%DTS_E_TXFUZZYLOOKUP_OLEDBERR_LOADCOLUMNMETADATA = &HC0209293&

' ////////////////////////////////////////////////////////////////////////////
' //  Check the SQLCommand property, the select statement must yield at least one column.

' //
' //  MessageId: DTS_E_TXFUZZYLOOKUP_TOOFEWREFERENCECOLUMNS
' //
' //  MessageText:
' //
' //   Lookup reference metadata contains too few columns.
' //
%DTS_E_TXFUZZYLOOKUP_TOOFEWREFERENCECOLUMNS = &HC0209294&

' //
' //  MessageId: DTS_E_TXSCD_OLEDBERR_LOADCOLUMNMETADATA
' //
' //  MessageText:
' //
' //   Encountered OLEDB error while loading column metadata.
' //
%DTS_E_TXSCD_OLEDBERR_LOADCOLUMNMETADATA = &HC0209295&

' ////////////////////////////////////////////////////////////////////////////
' //  Check the SQLCommand property, the select statement must yield at least one column.

' //
' //  MessageId: DTS_E_TXSCD_TOOFEWREFERENCECOLUMNS
' //
' //  MessageText:
' //
' //   Lookup reference metadata contains too few columns.
' //
%DTS_E_TXSCD_TOOFEWREFERENCECOLUMNS = &HC0209296&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate an array of ColumnInfo structs

' //
' //  MessageId: DTS_E_TXSCD_MALLOCERR_REFERENCECOLUMNINFO
' //
' //  MessageText:
' //
' //   Unable to allocate memory.
' //
%DTS_E_TXSCD_MALLOCERR_REFERENCECOLUMNINFO = &HC0209297&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not allocate an array of BUFFCOL structs for creation of main workspace

' //
' //  MessageId: DTS_E_TXSCD_MALLOCERR_BUFFCOL
' //
' //  MessageText:
' //
' //   Unable to allocate memory.
' //
%DTS_E_TXSCD_MALLOCERR_BUFFCOL    = &HC0209298&

' ////////////////////////////////////////////////////////////////////////////
' //  Could not create main workspace buffer

' //
' //  MessageId: DTS_E_TXSCD_MAINWORKSPACE_CREATEERR
' //
' //  MessageText:
' //
' //   Unable to create workspace buffer.
' //
%DTS_E_TXSCD_MAINWORKSPACE_CREATEERR = &HC0209299&

' //
' //  MessageId: DTS_E_DTPXMLDOMCREATEERROR
' //
' //  MessageText:
' //
' //   Unable to instantiate XML DOM document, please verify that MSXML binaries are properly installed and registered.
' //
%DTS_E_DTPXMLDOMCREATEERROR       = &HC020929A&

' ////////////////////////////////////////////////////////////////////////////
' //  Internal error, this will happen if the runtime is giving the pipeline xml module bad/malformed XML to load from.

' //
' //  MessageId: DTS_E_DTPXMLDOMLOADERROR
' //
' //  MessageText:
' //
' //   Unable to load XML data into a local DOM for processing.
' //
%DTS_E_DTPXMLDOMLOADERROR         = &HC020929B&

' ////////////////////////////////////////////////////////////////////////////
' //  The runtime variable must be of type Object

' //
' //  MessageId: DTS_E_RSTDESTBADVARIABLETYPE
' //
' //  MessageText:
' //
' //   The type of the runtime variable "%1!s!" is incorrect. The runtime variable type must be Object.
' //
%DTS_E_RSTDESTBADVARIABLETYPE     = &HC020929C&

' ////////////////////////////////////////////////////////////////////////////
' //  The XML source contains multiple inline schema nodes.

' //
' //  MessageId: DTS_E_XMLDATAREADERMULTIPLEINLINEXMLSCHEMASNOTSUPPORTED
' //
' //  MessageText:
' //
' //   The XML Source Adapter was unable to process the XML data. Multiple inline schemas are not supported.
' //
%DTS_E_XMLDATAREADERMULTIPLEINLINEXMLSCHEMASNOTSUPPORTED = &HC020929E&

' ////////////////////////////////////////////////////////////////////////////
' //  The XSD specified uses 'anyType', which is not supported and should be changed to a specific type that is supported.

' //
' //  MessageId: DTS_E_XMLDATAREADERANYTYPENOTSUPPORTED
' //
' //  MessageText:
' //
' //   The XML Source Adapter was unable to process the XML data. The content of an element can not be declared as anyType.
' //
%DTS_E_XMLDATAREADERANYTYPENOTSUPPORTED = &HC020929F&

' //
' //  MessageId: DTS_E_XMLDATAREADERGROUPREFNOTSUPPORTED
' //
' //  MessageText:
' //
' //   The XML Source Adapter was unable to process the XML data. The content of an element can not contain a reference (ref) to a group.
' //
%DTS_E_XMLDATAREADERGROUPREFNOTSUPPORTED = &HC02092A0&

' //
' //  MessageId: DTS_E_XMLDATAREADERMIXEDCONTENTFORCOMPLEXTYPESNOTSUPPORTED
' //
' //  MessageText:
' //
' //   The XML Source Adapter does not support mixed content model on Complex Types.
' //
%DTS_E_XMLDATAREADERMIXEDCONTENTFORCOMPLEXTYPESNOTSUPPORTED = &HC02092A1&

' ////////////////////////////////////////////////////////////////////////////
' //  The XML source contains an inline schema that is not the first child node.

' //
' //  MessageId: DTS_E_XMLDATAREADERINLINESCHEMAFOUNDINSOURCEXML
' //
' //  MessageText:
' //
' //   The XML Source Adapter was unable to process the XML data. An inline schema must be the first child node in the source Xml.
' //
%DTS_E_XMLDATAREADERINLINESCHEMAFOUNDINSOURCEXML = &HC02092A2&

' ////////////////////////////////////////////////////////////////////////////
' //  The XML source does not contain an inline schema, but an inline schema was expected.

' //
' //  MessageId: DTS_E_XMLDATAREADERNOINLINESCHEMAFOUND
' //
' //  MessageText:
' //
' //   The XML Source Adapter was unable to process the XML data. No inline schema was found in the source XML, but the "UseInlineSchema" property was set to true.
' //
%DTS_E_XMLDATAREADERNOINLINESCHEMAFOUND = &HC02092A3&

' //
' //  MessageId: DTS_E_CONNECTIONMANAGERTRANSACTEDANDRETAINEDINBULKINSERT
' //
' //  MessageText:
' //
' //   The component cannot use a connection manager that retains its connection in a transaction with fastload or bulk insert.
' //
%DTS_E_CONNECTIONMANAGERTRANSACTEDANDRETAINEDINBULKINSERT = &HC02092A4&

' //
' //  MessageId: DTS_E_OUTPUTREDIRECTINTRANSACTIONNOTALLOWED
' //
' //  MessageText:
' //
' //   The %1!s! cannot be set to redirect on error using a connection in a transaction.
' //
%DTS_E_OUTPUTREDIRECTINTRANSACTIONNOTALLOWED = &HC02092A5&

' ////////////////////////////////////////////////////////////////////////////
' //  No input or output column was found with an external metadata column ID corresponding to an external metadata column.

' //
' //  MessageId: DTS_E_FOUNDORPHANEDEXTERNALMETADATACOLUMN
' //
' //  MessageText:
' //
' //   The %1!s! does not have a corresponding input or output column.
' //
%DTS_E_FOUNDORPHANEDEXTERNALMETADATACOLUMN = &HC02092A6&

' ////////////////////////////////////////////////////////////////////////////
' //  No columns are selected or mapped

' //
' //  MessageId: DTS_E_RAWDESTNOINPUTCOLUMNS
' //
' //  MessageText:
' //
' //   There is no selected column to be written to the file.
' //
%DTS_E_RAWDESTNOINPUTCOLUMNS      = &HC02092A9&

' ////////////////////////////////////////////////////////////////////////////
' //  Blob data type used

' //
' //  MessageId: DTS_E_RAWDESTBLOBDATATYPE
' //
' //  MessageText:
' //
' //   The %1!s! has an invalid data type. Columns with data types DT_IMAGE, DT_TEXT and DT_NTEXT cannot be written to raw files.
' //
%DTS_E_RAWDESTBLOBDATATYPE        = &HC02092AA&

' ////////////////////////////////////////////////////////////////////////////
' //  Write Option and IsUsed flag mismatch

' //
' //  MessageId: DTS_E_RAWDESTWRONGEXTERNALMETADATAUSAGE
' //
' //  MessageText:
' //
' //   The external metadata collection is inproperly used by this component. The component should use external metadata when appending or truncating an existing file. Otherwise, the external metadata is not needed.
' //
%DTS_E_RAWDESTWRONGEXTERNALMETADATAUSAGE = &HC02092AB&

' ////////////////////////////////////////////////////////////////////////////
' //  Mapped input column when Write Option is  Create Always

' //
' //  MessageId: DTS_E_RAWDESTMAPPEDINPUTCOLUMN
' //
' //  MessageText:
' //
' //   The %1!s! is mapped to an external metadata column with the id %2!d!. Input columns should not be mapped to external metadata columns when selected Write Option value is Create Always.
' //
%DTS_E_RAWDESTMAPPEDINPUTCOLUMN   = &HC02092AC&

' ////////////////////////////////////////////////////////////////////////////
' //  The file cannot be opened for reading the metadata.

' //
' //  MessageId: DTS_E_RAWFILECANTOPENFORMETADATA
' //
' //  MessageText:
' //
' //   The file  cannot be opened for reading the metadata. If the file does not exist, and the component has already defined external metadata, you can set the "ValidateExternalMetadata" property to "false" and the file will be created at the runtime.
' //
%DTS_E_RAWFILECANTOPENFORMETADATA = &HC02092AD&

' ////////////////////////////////////////////////////////////////////////////
' //  Failed to access LOB data from a column in the data flow buffer.

' //
' //  MessageId: DTS_E_FAILEDTOACCESSLOBCOLUMN
' //
' //  MessageText:
' //
' //   Failed to access LOB data from the data flow buffer for data source column "%1!s!" with error code 0x%2!8.8X!.
' //
%DTS_E_FAILEDTOACCESSLOBCOLUMN    = &HC02092AE&

' ////////////////////////////////////////////////////////////////////////////
' //  An error occurred parsing the XML data or the XSD.

' //
' //  MessageId: DTS_E_XMLSRCUNABLETOPROCESSXMLDATA
' //
' //  MessageText:
' //
' //   The %1!s! was unable to process the XML data. %2!s!
' //
%DTS_E_XMLSRCUNABLETOPROCESSXMLDATA = &HC02092AF&

' //
' //  MessageId: DTS_E_XMLSRCSTATIC_UNABLETOPROCESSXMLDATA
' //
' //  MessageText:
' //
' //   The XML Source Adapter was unable to process the XML data.
' //
%DTS_E_XMLSRCSTATIC_UNABLETOPROCESSXMLDATA = &HC02092B0&

' ////////////////////////////////////////////////////////////////////////////
' //  Invalid access mode

' //
' //  MessageId: DTS_E_RAWINVALIDACCESSMODE
' //
' //  MessageText:
' //
' //   The value %1!d! is not recognized as a valid access mode.
' //
%DTS_E_RAWINVALIDACCESSMODE       = &HC02092B1&

' ////////////////////////////////////////////////////////////////////////////
' //  There are columns that do not exist in the data source or created with missing metadata.

' //
' //  MessageId: DTS_E_INCOMPLETEDATASOURCECOLUMNFOUND
' //
' //  MessageText:
' //
' //   Complete metadata information for the data source column "%1!s!" is not available.  Make sure the column is correctly defined in the data source.
' //
%DTS_E_INCOMPLETEDATASOURCECOLUMNFOUND = &HC02092B2&

' ////////////////////////////////////////////////////////////////////////////
' //  SetOutputColumnDataTypeProperties was called to change something other than the length for a username audit column

' //
' //  MessageId: DTS_E_TXAUDIT_ONLYUSERNAMELENGTHCHANGEALLOWED
' //
' //  MessageText:
' //
' //   Only a username audit column's length can be changed.  All other audit column datatype information is read only.
' //
%DTS_E_TXAUDIT_ONLYUSERNAMELENGTHCHANGEALLOWED = &HC02092B3&

' ////////////////////////////////////////////////////////////////////////////
' //  The OLE DB provider did not return a rowset after executing a SQL command.

' //
' //  MessageId: DTS_E_ROWSETUNAVAILABLE
' //
' //  MessageText:
' //
' //   A rowset based on the SQL command was not returned by the OLE DB provider.
' //
%DTS_E_ROWSETUNAVAILABLE          = &HC02092B4&

' ////////////////////////////////////////////////////////////////////////////
' //  Corrupt file or we really have zero columns and therefore no data.

' //
' //  MessageId: DTS_I_RAWSOURCENOCOLUMNS
' //
' //  MessageText:
' //
' //   The raw source adapter opened a file, but the file contains no columns. The adapter will not produce data. This could indicate a damaged file, or that there are zero columns and, therefore, no data.
' //
%DTS_I_RAWSOURCENOCOLUMNS         = &H4020206D&

' //
' //  MessageId: DTS_I_OLEDBINFORMATIONALMESSAGE
' //
' //  MessageText:
' //
' //   An OLE DB informational message is available.
' //
%DTS_I_OLEDBINFORMATIONALMESSAGE  = &H402020DA&

' //
' //  MessageId: DTS_I_TXFUZZYLOOKUP_EXACT_MATCH_PERF_COLLATIONS_DONT_MATCH
' //
' //  MessageText:
' //
' //   Fuzzy match performance can be improved if the exact join FuzzyComparisonFlags on the input column "%1!s!" are set to match with the default SQL collation for reference table column "%2!s!".
' //   It is also necessary that no fold flags are set in FuzzyComparisonFlagsEx.
' //
%DTS_I_TXFUZZYLOOKUP_EXACT_MATCH_PERF_COLLATIONS_DONT_MATCH = &H40208327&

' //
' //  MessageId: DTS_I_TXFUZZYLOOKUP_EXACT_MATCH_PERF_INDEX_MISSING
' //
' //  MessageText:
' //
' //   Fuzzy match performance can be improved if an index is created upon the reference table across all of the specified exact match columns.
' //
%DTS_I_TXFUZZYLOOKUP_EXACT_MATCH_PERF_INDEX_MISSING = &H40208328&

' ////////////////////////////////////////////////////////////////////////////
' //  There is more than one error output and there are one or more dispositions set to redirect

' //
' //  MessageId: DTS_I_DISPSNOTREVIEWED
' //
' //  MessageText:
' //
' //   Error and truncation dispositions were not reviewed. Make sure this component is configured to redirect rows to error outputs, if you wish to further transform those rows.
' //
%DTS_I_DISPSNOTREVIEWED           = &H40208387&

' //
' //  MessageId: DTS_I_TXAGG_WORKSPACE_REHASH
' //
' //  MessageText:
' //
' //   The Aggregate transformation has encountered %1!d! key combinations. It has to re-hash data because the number of key combinations is more than expected. The component can be configured
' //   to avoid data re-hash by adjusting the Keys, KeyScale, and AutoExtendFactor properties.
' //
%DTS_I_TXAGG_WORKSPACE_REHASH     = &H402090DA&

' //
' //  MessageId: DTS_I_TXAGG_COUNTDISTINCT_REHASH
' //
' //  MessageText:
' //
' //   The Aggregate transformation has encountered %1!d! distinct values while performing a "count distinct" aggregation on "%2!s!". The transformation will re-hash data because the number of distinct
' //   values is more than expected. The component can be configured to avoid data re-hash by adjusting the CountDistinctKeys,
' //   CountDistinctKeyScale, and AutoExtendFactor properties.
' //
%DTS_I_TXAGG_COUNTDISTINCT_REHASH = &H402090DB&

' //
' //  MessageId: DTS_I_STARTPROCESSINGFILE
' //
' //  MessageText:
' //
' //   The processing of file "%1!s!" has started.
' //
%DTS_I_STARTPROCESSINGFILE        = &H402090DC&

' //
' //  MessageId: DTS_I_FINISHPROCESSINGFILE
' //
' //  MessageText:
' //
' //   The processing of file "%1!s!" has ended.
' //
%DTS_I_FINISHPROCESSINGFILE       = &H402090DD&

' //
' //  MessageId: DTS_I_TOTALDATAROWSPROCESSEDFORFILE
' //
' //  MessageText:
' //
' //   The total number of data rows processed for file "%1!s!" is %2!I64d!.
' //
%DTS_I_TOTALDATAROWSPROCESSEDFORFILE = &H402090DE&

' //
' //  MessageId: DTS_I_FINALCOMMITSTARTED
' //
' //  MessageText:
' //
' //   The final commit for the data insertion has started.
' //
%DTS_I_FINALCOMMITSTARTED         = &H402090DF&

' //
' //  MessageId: DTS_I_FINALCOMMITENDED
' //
' //  MessageText:
' //
' //   The final commit for the data insertion has ended.
' //
%DTS_I_FINALCOMMITENDED           = &H402090E0&

' ////////////////////////////////////////////////////////////////////////////
' //  Trucation occurred at some point during the evaluation of the expression, including, possibly, at an intermediate step.

' //
' //  MessageId: DTS_S_EXPREVALTRUNCATIONOCCURRED
' //
' //  MessageText:
' //
' //   A truncation occurred during evaluation of the expression. The trunctation occurred during evaluation, which may include any point in an intermediate step.
' //
%DTS_S_EXPREVALTRUNCATIONOCCURRED = &H00200001&

' //
' //  MessageId: DTS_W_PARTIALROWFOUNDATENDOFFILE
' //
' //  MessageText:
' //
' //   There is a partial row at the end of the file.
' //
%DTS_W_PARTIALROWFOUNDATENDOFFILE = &H8020200F&

' ////////////////////////////////////////////////////////////////////////////
' //  Make sure the header row delimiter and the number of header rows to skip are correct.

' //
' //  MessageId: DTS_W_ENDOFFILEREACHWHILEREADINGHEADERROWS
' //
' //  MessageText:
' //
' //   The end of the data file was reached while reading header rows. Make sure the header row delimiter and the number of header rows to skip are correct.
' //
%DTS_W_ENDOFFILEREACHWHILEREADINGHEADERROWS = &H8020202B&

' //
' //  MessageId: DTS_W_CANTRETRIEVECODEPAGEFROMOLEDBPROVIDER
' //
' //  MessageText:
' //
' //   Cannot retrieve the column code page info from the OLE DB provider.  If the component supports the "%1!s!" property, the code page from that property will be used.  Change the value of the property
' //   if the current string code page values are incorrect.  If the component does not support the property, the code page from the component's locale ID will be used.
' //
%DTS_W_CANTRETRIEVECODEPAGEFROMOLEDBPROVIDER = &H80202066&

' //
' //  MessageId: DTS_W_TXSORTSORTISTHESAME
' //
' //  MessageText:
' //
' //   The data is already sorted as specified so the transform can be removed.
' //
%DTS_W_TXSORTSORTISTHESAME        = &H802020F7&

' //
' //  MessageId: DTS_W_NOPIPELINEDATATYPEMAPPINGAVAILABLE
' //
' //  MessageText:
' //
' //   The %1!s! references an external data type that cannot be mapped to a Data Flow task data type. The Data Flow task data type DT_WSTR will be used instead.
' //
%DTS_W_NOPIPELINEDATATYPEMAPPINGAVAILABLE = &H8020400D&

' ////////////////////////////////////////////////////////////////////////////
' //  The expression contains a static truncation (truncation of a fixed value).

' //
' //  MessageId: DTS_W_STATICTRUNCATIONINEXPRESSION
' //
' //  MessageText:
' //
' //   The expression "%1!s!" will always result in a truncation of data. The expression contains a static truncation (the truncation of a fixed value).
' //
%DTS_W_STATICTRUNCATIONINEXPRESSION = &H802070CC&

' //
' //  MessageId: DTS_W_UNMAPPEDINPUTCOLUMN
' //
' //  MessageText:
' //
' //   The input column "%1!s!" with ID %2!d! at index %3!d! is unmapped. The lineage ID for the column is zero.
' //
%DTS_W_UNMAPPEDINPUTCOLUMN        = &H8020820C&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens when the delimiters used to tokenize fields don't match - this can have unknown effects on the matching behavior/results.

' //
' //  MessageId: DTS_W_TXFUZZYLOOKUP_DELIMITERS_DONT_MATCH
' //
' //  MessageText:
' //
' //   The specified delimiters do not match the delimiters used to build the pre-existing match index "%1!s!". This error occurs when the delimiters used to tokenize fields do not match. This can have unknown effects on the matching behavior or results.
' //
%DTS_W_TXFUZZYLOOKUP_DELIMITERS_DONT_MATCH = &H80208305&

' //
' //  MessageId: DTS_W_TXFUZZYLOOKUP_MAXRESULTS_IS_ZERO
' //
' //  MessageText:
' //
' //   The MaxOutputMatchesPerInput property on the Fuzzy Lookup transformation is zero. No results will be produced.
' //
%DTS_W_TXFUZZYLOOKUP_MAXRESULTS_IS_ZERO = &H80208308&

' ////////////////////////////////////////////////////////////////////////////
' //  Either there are no joins specified or all joins are of type 'Exact'.

' //
' //  MessageId: DTS_W_TXFUZZYLOOKUP_NO_FUZZY_JOIN_COLUMNS
' //
' //  MessageText:
' //
' //   There were no valid input columns with JoinType column property set to Fuzzy.  Performance on Exact joins may be improved by using the Lookup transform instead of FuzzyLookup.
' //
%DTS_W_TXFUZZYLOOKUP_NO_FUZZY_JOIN_COLUMNS = &H80208310&

' ////////////////////////////////////////////////////////////////////////////
' //  Happens because timestamps are rather variable database fields with semantics that might cause the user to expect certain behavior.

' //
' //  MessageId: DTS_W_TXFUZZYLOOKUP_TIMESTAMPCAVEAT
' //
' //  MessageText:
' //
' //   The reference column "%1!s!" may be a SQL timestamp column. When the fuzzy match index is built, and a copy of the reference table is made, all reference table timestamps will reflect the current state
' //   of the table at the time of the copy. Unexpected behavior may occur if the CopyReferenceTable is set to false.
' //
%DTS_W_TXFUZZYLOOKUP_TIMESTAMPCAVEAT = &H8020831C&

' //
' //  MessageId: DTS_W_MATCHINDEXALREADYEXISTS
' //
' //  MessageText:
' //
' //   A table with the name '%1!s!' given for MatchIndexName already exists and DropExistingMatchIndex is set to FALSE.  Transform execution will fail unless this table is dropped, a different name is specified, or DropExisitingMatchIndex is set to TRUE.
' //
%DTS_W_MATCHINDEXALREADYEXISTS    = &H80208321&

' //
' //  MessageId: DTS_W_TXFUZZYLOOKUP_JOINLENGTHMISMATCH
' //
' //  MessageText:
' //
' //   The length of input column '%1!s!' is not equal to the length of the reference column '%2!s!' that it is being matched against.
' //
%DTS_W_TXFUZZYLOOKUP_JOINLENGTHMISMATCH = &H8020832B&

' //
' //  MessageId: DTS_W_TXFUZZYLOOKUP_CODEPAGE_MISMATCH
' //
' //  MessageText:
' //
' //   The code pages of the DT_STR source column "%1!s!" and the DT_STR dest column "%2!s!" do not match.  This may cause unexpected results.
' //
%DTS_W_TXFUZZYLOOKUP_CODEPAGE_MISMATCH = &H8020832D&

' ////////////////////////////////////////////////////////////////////////////
' //  SQL has a limit of 16 columns per index, so we will revert back to using the inverted index for all lookups

' //
' //  MessageId: DTS_W_FUZZYLOOKUP_TOOMANYEXACTMATCHCOLUMNS
' //
' //  MessageText:
' //
' //   There are more than 16 exact match joins, so performance may not be optimal. Reduce the number of exact match joins to improve performance. SQL Server has a limit of 16 columns per index, the inverted index will be used for all lookups.
' //
%DTS_W_FUZZYLOOKUP_TOOMANYEXACTMATCHCOLUMNS = &H8020832E&

' ////////////////////////////////////////////////////////////////////////////
' //  If Exhaustive property is true, then we require that the entire reference table fit in memory.  Since a memory limit was specified, we may run out of memory.

' //
' //  MessageId: DTS_W_FUZZYLOOKUP_MEMLIMITANDEXHAUSTIVESPECIFIED
' //
' //  MessageText:
' //
' //   The Exhaustive option requires that the entire reference be loaded into main memory.  Since a memory limit has been specified for the MaxMemoryUsage property, it is possible that the entire reference table will not
' //   fit within this bound and that the match operation will fail at runtime.
' //
%DTS_W_FUZZYLOOKUP_MEMLIMITANDEXHAUSTIVESPECIFIED = &H80208350&

' //
' //  MessageId: DTS_W_FUZZYLOOKUP_EXACTMATCHCOLUMNSEXCEEDBYTELIMIT
' //
' //  MessageText:
' //
' //   The cumulative lengths of the columns specified in the exact match joins exceeds the 900 byte limit for index keys.  Fuzzy Lookup creates an index on the exact match columns to increase lookup performance
' //   and there is a possibility that creation of this index may fail and the lookup will fall back to an alternative, possibly slower, method of finding matches. If performance is a problem, try removing some
' //   exact match join columns or reduce the maximum lengths of variable length exact match columns.
' //
%DTS_W_FUZZYLOOKUP_EXACTMATCHCOLUMNSEXCEEDBYTELIMIT = &H80208351&

' //
' //  MessageId: DTS_W_FUZZYLOOKUP_EXACTMATCHINDEXCREATIONFAILED
' //
' //  MessageText:
' //
' //   Failed to create an index for exact match columns. Reverting to alternative fuzzy lookup method.
' //
%DTS_W_FUZZYLOOKUP_EXACTMATCHINDEXCREATIONFAILED = &H80208352&

' //
' //  MessageId: DTS_W_FUZZYGROUPINGINTERNALPIPELINEWARNING
' //
' //  MessageText:
' //
' //   The following Fuzzy Grouping internal pipeline warning occurred with warning code 0x%1!8.8X!: "%2!s!".
' //
%DTS_W_FUZZYGROUPINGINTERNALPIPELINEWARNING = &H80208353&

' ////////////////////////////////////////////////////////////////////////////
' //  The XSD did not specify a length for the column, so a default value is being used.

' //
' //  MessageId: DTS_W_XMLSRCOUTPUTCOLUMNLENGTHSETTODEFAULT
' //
' //  MessageText:
' //
' //   No maximum length was specified for the %1!s! with external data type %2!s!. The SSIS Data Flow Task data type "%3!s!" with a length of %4!d! will be used.
' //
%DTS_W_XMLSRCOUTPUTCOLUMNLENGTHSETTODEFAULT = &H80208375&

' ////////////////////////////////////////////////////////////////////////////
' //  The XSD specified an unrecognized type. The column type will be set to string by default.

' //
' //  MessageId: DTS_W_XMLSRCOUTPUTCOLUMNDATATYPEMAPPEDTOSTRING
' //
' //  MessageText:
' //
' //   The %1!s! references external data type %2!s!, which cannot be mapped to a SSIS Data Flow Task data type.  The SSIS Data Flow Task data type DT_WSTR with a length of %3!d! will be used instead.
' //
%DTS_W_XMLSRCOUTPUTCOLUMNDATATYPEMAPPEDTOSTRING = &H80208376&

' ////////////////////////////////////////////////////////////////////////////
' //  A component had an attached error output but didn't specify any dispositions to redirect

' //
' //  MessageId: DTS_W_NOREDIRECTWITHATTACHEDERROROUTPUTS
' //
' //  MessageText:
' //
' //   No rows will be sent to error output(s). Configure error or truncation dispositions to redirect rows to the error output(s), or delete data flow transformations or destinations that are attached to the error output(s).
' //
%DTS_W_NOREDIRECTWITHATTACHEDERROROUTPUTS = &H80208385&

' ////////////////////////////////////////////////////////////////////////////
' //  Redirect dispositions were specified but no error outputs are attached

' //
' //  MessageId: DTS_W_REDIRECTWITHNOATTACHEDERROROUTPUTS
' //
' //  MessageText:
' //
' //   Rows sent to the error output(s) will be lost. Add new data flow transformations or destinations to receive error rows, or reconfigure the component to stop redirecting rows to the error output(s).
' //
%DTS_W_REDIRECTWITHNOATTACHEDERROROUTPUTS = &H80208386&

' ////////////////////////////////////////////////////////////////////////////
' //  Lookup found duplicate key values when caching metadata in PreExecute.  Can only happen in Full Cache mode.

' //
' //  MessageId: DTS_W_TXLOOKUP_DUPLICATE_KEYS
' //
' //  MessageText:
' //
' //   The Lookup transformation encountered duplicate reference key values when caching reference data. The Lookup transformation found duplicate key values when caching metadata in PreExecute. This error occurs
' //   in Full Cache mode only. Either remove the duplicate key values, or change the cache mode to PARTIAL or NO_CACHE.
' //
%DTS_W_TXLOOKUP_DUPLICATE_KEYS    = &H802090E4&

' ////////////////////////////////////////////////////////////////////////////
' //  Data insertion is attempted for a column that has a wider length in the data flow than in the database.

' //
' //  MessageId: DTS_W_POTENTIALTRUNCATIONFROMDATAINSERTION
' //
' //  MessageText:
' //
' //   Truncation may occur due to inserting data from data flow column "%1!s!" with a length of %2!d! to database column "%3!s!" with a length of %4!d!.
' //
%DTS_W_POTENTIALTRUNCATIONFROMDATAINSERTION = &H802092A7&

' ////////////////////////////////////////////////////////////////////////////
' //  Data retrieval is attempted for a column that has a wider length in the database than in the data flow.

' //
' //  MessageId: DTS_W_POTENTIALTRUNCATIONFROMDATARETRIEVAL
' //
' //  MessageText:
' //
' //   Truncation may occur due to retrieving data from database column "%1!s!" with a length of %2!d! to data flow column "%3!s!" with a length of %4!d!.
' //
%DTS_W_POTENTIALTRUNCATIONFROMDATARETRIEVAL = &H802092A8&

' //
' //  MessageId: DTS_E_CYCLEINEXECUTIONTREE
' //
' //  MessageText:
' //
' //   An execution tree contains a cycle.
' //
%DTS_E_CYCLEINEXECUTIONTREE       = &HC0047000&

' //
' //  MessageId: DTS_E_DISCONNECTEDOBJECT
' //
' //  MessageText:
' //
' //   The %1!s! object "%2!s!" (%3!d!) is disconnected from the layout.
' //
%DTS_E_DISCONNECTEDOBJECT         = &HC0047001&

' //
' //  MessageId: DTS_E_INVALIDOBJECTID
' //
' //  MessageText:
' //
' //   The ID for the layout object is not valid.
' //
%DTS_E_INVALIDOBJECTID            = &HC0047002&

' //
' //  MessageId: DTS_E_INPUTWITHOUTPATHS
' //
' //  MessageText:
' //
' //   A required input object is not connected to a path object.
' //
%DTS_E_INPUTWITHOUTPATHS          = &HC0047003&

' //
' //  MessageId: DTS_E_INVALIDSYNCHRONOUSINPUT
' //
' //  MessageText:
' //
' //   %1!s! has an invalid synchronous input ID %2!d!.
' //
%DTS_E_INVALIDSYNCHRONOUSINPUT    = &HC0047005&

' //
' //  MessageId: DTS_E_INVALIDOUTPUTLINEAGEID
' //
' //  MessageText:
' //
' //   %1!s! has lineage ID %2!d!, but should have had %3!d!.
' //
%DTS_E_INVALIDOUTPUTLINEAGEID     = &HC0047006&

' //
' //  MessageId: DTS_E_DUPLICATENAMESINCOLLECTION
' //
' //  MessageText:
' //
' //   The package contains two objects with the duplicate name of "%1!s!" and "%2!s!".
' //
%DTS_E_DUPLICATENAMESINCOLLECTION = &HC0047008&

' //
' //  MessageId: DTS_E_INVALIDEXCLUSIONGROUP
' //
' //  MessageText:
' //
' //   The "%1!s!" and the "%2!s!" are in the same exclusion group, but they do not have the same synchronous input.
' //
%DTS_E_INVALIDEXCLUSIONGROUP      = &HC0047009&

' //
' //  MessageId: DTS_E_DUPLICATELINEAGEIDSINCOLLECTION
' //
' //  MessageText:
' //
' //   Two objects in the same collection have a duplicate lineage ID of %1!d!. The objects are %2!s! and %3!s!.
' //
%DTS_E_DUPLICATELINEAGEIDSINCOLLECTION = &HC004700A&

' //
' //  MessageId: DTS_E_VALIDATIONFAILEDONLAYOUT
' //
' //  MessageText:
' //
' //   The layout failed validation.
' //
%DTS_E_VALIDATIONFAILEDONLAYOUT   = &HC004700B&

' //
' //  MessageId: DTS_E_VALIDATIONFAILEDONCOMPONENTS
' //
' //  MessageText:
' //
' //   One or more component failed validation.
' //
%DTS_E_VALIDATIONFAILEDONCOMPONENTS = &HC004700C&

' //
' //  MessageId: DTS_E_VALIDATIONFAILED
' //
' //  MessageText:
' //
' //   The layout and one or more components failed validation.
' //
%DTS_E_VALIDATIONFAILED           = &HC004700D&

' //
' //  MessageId: DTS_E_THREADSTARTUPFAILED
' //
' //  MessageText:
' //
' //   The Data Flow task engine failed at startup because it cannot create one or more required threads.
' //
%DTS_E_THREADSTARTUPFAILED        = &HC004700E&

' //
' //  MessageId: DTS_E_CANTGETMUTEX
' //
' //  MessageText:
' //
' //   A thread failed to create a mutex at initialization.
' //
%DTS_E_CANTGETMUTEX               = &HC004700F&

' //
' //  MessageId: DTS_E_CANTGETSEMAPHORE
' //
' //  MessageText:
' //
' //   A thread failed to create a semaphore at initialization.
' //
%DTS_E_CANTGETSEMAPHORE           = &HC0047010&

' //
' //  MessageId: DTS_E_BUFFERFAILUREDETAILS
' //
' //  MessageText:
' //
' //   The system reports %1!d! percent memory load. There are %2!s! bytes of physical memory with %3!s! bytes free. There are %4!s! bytes of virtual memory with %5!s! bytes free. The paging file has %6!s! bytes with %7!s! bytes free.
' //
%DTS_E_BUFFERFAILUREDETAILS       = &HC0047011&

' //
' //  MessageId: DTS_E_BUFFERALLOCFAILED
' //
' //  MessageText:
' //
' //   A buffer failed while allocating %1!d! bytes.
' //
%DTS_E_BUFFERALLOCFAILED          = &HC0047012&

' ////////////////////////////////////////////////////////////////////////////
' //  This is an unexpected internal error; we couldn't create a required COM object.

' //
' //  MessageId: DTS_E_CANTCREATEBUFFERMANAGER
' //
' //  MessageText:
' //
' //   The Buffer Manager could not be created.
' //
%DTS_E_CANTCREATEBUFFERMANAGER    = &HC0047013&

' ////////////////////////////////////////////////////////////////////////////
' //  The size was too large or too small.

' //
' //  MessageId: DTS_E_BUFFERBADSIZE
' //
' //  MessageText:
' //
' //   Buffer Type %1!d! had a size of %2!I64d! bytes.
' //
%DTS_E_BUFFERBADSIZE              = &HC0047015&

' //
' //  MessageId: DTS_E_DANGLINGWITHPATH
' //
' //  MessageText:
' //
' //   %1!s! is marked as dangling, but has a path attached to it.
' //
%DTS_E_DANGLINGWITHPATH           = &HC0047016&

' //
' //  MessageId: DTS_E_INDIVIDUALVALIDATIONFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed validation and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALVALIDATIONFAILED = &HC0047017&

' //
' //  MessageId: DTS_E_INDIVIDUALPOSTEXECUTEFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed the post-execute phase and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPOSTEXECUTEFAILED = &HC0047018&

' //
' //  MessageId: DTS_E_INDIVIDUALPREPAREFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed the prepare phase and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPREPAREFAILED    = &HC0047019&

' //
' //  MessageId: DTS_E_INDIVIDUALPREEXECUTEFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed the pre-execute phase and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPREEXECUTEFAILED = &HC004701A&

' //
' //  MessageId: DTS_E_INDIVIDUALCLEANUPFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed the cleanup phase and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALCLEANUPFAILED    = &HC004701B&

' //
' //  MessageId: DTS_E_INVALIDINPUTLINEAGEID
' //
' //  MessageText:
' //
' //   %1!s! has lineage ID %2!d! that was not previously used in the Data Flow task.
' //
%DTS_E_INVALIDINPUTLINEAGEID      = &HC004701C&

' //
' //  MessageId: DTS_E_EXECUTIONTREECYCLE
' //
' //  MessageText:
' //
' //   Cannot connect %1!s! to %2!s! because a cycle would be created.
' //
%DTS_E_EXECUTIONTREECYCLE         = &HC004701E&

' ////////////////////////////////////////////////////////////////////////////
' //  Comparison of that data type is not supported, so it cannot be sorted or used as a key.

' //
' //  MessageId: DTS_E_CANTCOMPARE
' //
' //  MessageText:
' //
' //   The data type "%1!s!" cannot be compared. Comparison of that data type is not supported, so it cannot be sorted or used as a key.
' //
%DTS_E_CANTCOMPARE                = &HC004701F&

' //
' //  MessageId: DTS_E_REFUSEDFORSHUTDOWN
' //
' //  MessageText:
' //
' //   This thread has shut down and is not accepting buffers for input.
' //
%DTS_E_REFUSEDFORSHUTDOWN         = &HC0047020&

' //
' //  MessageId: DTS_E_THREADFAILED
' //
' //  MessageText:
' //
' //   Thread "%1!s!" has exited with error code 0x%2!8.8X!.
' //
%DTS_E_THREADFAILED               = &HC0047021&

' ////////////////////////////////////////////////////////////////////////////
' //  The identified component returned an error from its ProcessInput method. The meaning of the error is specific to the component, but it is fatal and will cause the Data Flow Task to stop execution.

' //
' //  MessageId: DTS_E_PROCESSINPUTFAILED
' //
' //  MessageText:
' //
' //   The ProcessInput method on component "%1!s!" (%2!d!) failed with error code 0x%3!8.8X!. The identified component returned an error from the ProcessInput method. The error is specific to the component,
' //   but the error is fatal and will cause the Data Flow task to stop running.
' //
%DTS_E_PROCESSINPUTFAILED         = &HC0047022&

' //
' //  MessageId: DTS_E_CANTREALIZEVIRTUALBUFFERS
' //
' //  MessageText:
' //
' //   A set of virtual buffers cannot be realized.
' //
%DTS_E_CANTREALIZEVIRTUALBUFFERS  = &HC0047023&

' ////////////////////////////////////////////////////////////////////////////
' //  The pipeline requires too many threads as configured. There are either too many asynchronous outputs, or EngineThreads is too high.

' //
' //  MessageId: DTS_E_PIPELINETOOCOMPLEX
' //
' //  MessageText:
' //
' //   The number of threads required for this pipeline is %1!d!, which is more than the system limit of %2!d!. The pipeline requires too many threads as configured. There are either too many asynchronous outputs,
' //   or EngineThreads property is set too high. Split the pipeline into multiple packages, or reduce the value of the EngineThreads property.
' //
%DTS_E_PIPELINETOOCOMPLEX         = &HC0047024&

' //
' //  MessageId: DTS_E_SCHEDULERCOULDNOTCOUNTSOURCES
' //
' //  MessageText:
' //
' //   The Data FLow engine scheduler cannot obtain a count of the sources in the layout.
' //
%DTS_E_SCHEDULERCOULDNOTCOUNTSOURCES = &HC0047028&

' //
' //  MessageId: DTS_E_SCHEDULERCOULDNOTCOUNTDESTINATIONS
' //
' //  MessageText:
' //
' //   The Data Flow engine scheduler cannot obtain a count of the destinations in the layout.
' //
%DTS_E_SCHEDULERCOULDNOTCOUNTDESTINATIONS = &HC0047029&

' ////////////////////////////////////////////////////////////////////////////
' //  Make sure the component view has been created.

' //
' //  MessageId: DTS_E_COMPONENTVIEWISUNAVAILABLE
' //
' //  MessageText:
' //
' //   The component view is unavailable. Make sure the component view has been created.
' //
%DTS_E_COMPONENTVIEWISUNAVAILABLE = &HC004702A&

' ////////////////////////////////////////////////////////////////////////////
' //  The component view may be out of synch.  Try releasing the component view and recreating it.

' //
' //  MessageId: DTS_E_INCORRECTCOMPONENTVIEWID
' //
' //  MessageText:
' //
' //   The component view ID is incorrect. The component view may be out of synchronization. Try releasing the component view and recreating it.
' //
%DTS_E_INCORRECTCOMPONENTVIEWID   = &HC004702B&

' //
' //  MessageId: DTS_E_BUFFERNOTLOCKED
' //
' //  MessageText:
' //
' //   This buffer is not locked and cannot be manipulated.
' //
%DTS_E_BUFFERNOTLOCKED            = &HC004702C&

' //
' //  MessageId: DTS_E_CANTBUILDBUFFERTYPE
' //
' //  MessageText:
' //
' //   The Data Flow task cannot allocate memory to build a buffer definition. The buffer definition had %1!d! columns.
' //
%DTS_E_CANTBUILDBUFFERTYPE        = &HC004702D&

' //
' //  MessageId: DTS_E_CANTREGISTERBUFFERTYPE
' //
' //  MessageText:
' //
' //   The Data Flow task cannot register a buffer type. The type had %1!d! columns and was for execution tree %2!d!.
' //
%DTS_E_CANTREGISTERBUFFERTYPE     = &HC004702E&

' ////////////////////////////////////////////////////////////////////////////
' //  This happens when the XML is edited and the UsesDispositions value is changed.  This value is not allowed to change and is set by the component when it is added to the package.

' //
' //  MessageId: DTS_E_INVALIDUSESDISPOSITIONSVALUE
' //
' //  MessageText:
' //
' //   The UsesDispositions property cannot be changed from its initial value. This occurs when the XML is edited and the UsesDispositions value is modified. This value is set by the component when it is added to the package and is not allowed to change.
' //
%DTS_E_INVALIDUSESDISPOSITIONSVALUE = &HC004702F&

' ////////////////////////////////////////////////////////////////////////////
' //  The thread previously reported a specific error.

' //
' //  MessageId: DTS_E_THREADFAILEDINITIALIZE
' //
' //  MessageText:
' //
' //   The Data Flow task failed to initialize a required thread and cannot begin execution. The thread previously reported a specific error.
' //
%DTS_E_THREADFAILEDINITIALIZE     = &HC0047030&

' ////////////////////////////////////////////////////////////////////////////
' //  Out of memory, most likely.

' //
' //  MessageId: DTS_E_THREADFAILEDCREATE
' //
' //  MessageText:
' //
' //   The Data Flow task failed to create a required thread and cannot begin running. The usually occurs when there is an out-of-memory state.
' //
%DTS_E_THREADFAILEDCREATE         = &HC0047031&

' //
' //  MessageId: DTS_E_EXECUTIONTREECYCLEADDINGSYNCHRONOUSINPUT
' //
' //  MessageText:
' //
' //   The synchronous input of "%1!s!" cannot be set to "%2!s!" because a cycle would be created.
' //
%DTS_E_EXECUTIONTREECYCLEADDINGSYNCHRONOUSINPUT = &HC0047032&

' ////////////////////////////////////////////////////////////////////////////
' //  A custom property can't have the same name as a stock property on the same object.

' //
' //  MessageId: DTS_E_INVALIDCUSTOMPROPERTYNAME
' //
' //  MessageText:
' //
' //   A custom property named "%1!s!" is invalid because there is a stock property with that name. A custom property cannot have the same name as a stock property on the same object.
' //
%DTS_E_INVALIDCUSTOMPROPERTYNAME  = &HC0047033&

' ////////////////////////////////////////////////////////////////////////////
' //  The buffer was already unlocked.

' //
' //  MessageId: DTS_E_BUFFERLOCKUNDERFLOW
' //
' //  MessageText:
' //
' //   The buffer was already unlocked.
' //
%DTS_E_BUFFERLOCKUNDERFLOW        = &HC0047035&

' ////////////////////////////////////////////////////////////////////////////
' //  A component failed its CacheInterfaces call.

' //
' //  MessageId: DTS_E_INDIVIDUALCACHEINTERFACESFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed initialization and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALCACHEINTERFACESFAILED = &HC0047036&

' ////////////////////////////////////////////////////////////////////////////
' //  A component failed its ReleaseInterfaces call.

' //
' //  MessageId: DTS_E_INDIVIDUALRELEASEINTERFACESFAILED
' //
' //  MessageText:
' //
' //   %1!s! failed during shut down and returned error code 0x%2!8.8X!. A component failed to release its interfaces.
' //
%DTS_E_INDIVIDUALRELEASEINTERFACESFAILED = &HC0047037&

' ////////////////////////////////////////////////////////////////////////////
' //  The identified component returned a failure code when the pipeline engine called PrimeOutput(). The meaning of the failure code is defined by the component, but the error is fatal and the pipeline will stop execution.

' //
' //  MessageId: DTS_E_PRIMEOUTPUTFAILED
' //
' //  MessageText:
' //
' //   The PrimeOutput method on %1!s! returned error code 0x%2!8.8X!.  The component returned a failure code when the pipeline engine called PrimeOutput(). The meaning of the failure code is defined
' //   by the component, but the error is fatal and the pipeline stopped executing.
' //
%DTS_E_PRIMEOUTPUTFAILED          = &HC0047038&

' ////////////////////////////////////////////////////////////////////////////
' //  The user requested a shutdown, or an error in another thread is causing the pipeline to shutdown.

' //
' //  MessageId: DTS_E_THREADCANCELLED
' //
' //  MessageText:
' //
' //   Thread "%1!s!" received a shutdown signal and is terminating. The user requested a shutdown, or an error in another thread is causing the pipeline to shutdown.
' //
%DTS_E_THREADCANCELLED            = &HC0047039&

' ////////////////////////////////////////////////////////////////////////////
' //  The distributor couldn't initialize the component's property, and can't continue execution.

' //
' //  MessageId: DTS_E_DISTRIBUTORCANTSETPROPERTY
' //
' //  MessageText:
' //
' //   Distributor for thread "%1!s!" failed to initialize property "%2!s!" on component "%3!s!" because of error 0x%8.8X. The distributor could not initialize the component's property and cannot continue running.
' //
%DTS_E_DISTRIBUTORCANTSETPROPERTY = &HC004703A&

' //
' //  MessageId: DTS_E_CANTREGISTERVIEWBUFFERTYPE
' //
' //  MessageText:
' //
' //   The Data Flow task cannot register a view buffer type. The type had %1!d! columns and was for input ID %2!d!.
' //
%DTS_E_CANTREGISTERVIEWBUFFERTYPE = &HC004703B&

' //
' //  MessageId: DTS_E_CANTCREATEEXECUTIONTREE
' //
' //  MessageText:
' //
' //   There is not enough memory to create an execution tree.
' //
%DTS_E_CANTCREATEEXECUTIONTREE    = &HC004703F&

' //
' //  MessageId: DTS_E_CANTINSERTINTOHASHTABLE
' //
' //  MessageText:
' //
' //   There is not enough memory to insert an object into the hash table.
' //
%DTS_E_CANTINSERTINTOHASHTABLE    = &HC0047040&

' //
' //  MessageId: DTS_E_OBJECTNOTINHASHTABLE
' //
' //  MessageText:
' //
' //   The object is not in the hash table.
' //
%DTS_E_OBJECTNOTINHASHTABLE       = &HC0047041&

' ////////////////////////////////////////////////////////////////////////////
' //  Only one component view can exist at a time.

' //
' //  MessageId: DTS_E_CANTCREATECOMPONENTVIEW
' //
' //  MessageText:
' //
' //   Cannot create a component view because another one already exists. Only one component view can exist at a time.
' //
%DTS_E_CANTCREATECOMPONENTVIEW    = &HC0047043&

' //
' //  MessageId: DTS_E_LAYOUTCANTSETUSAGETYPE
' //
' //  MessageText:
' //
' //   At input "%1!s!" (%2!d!), the virtual input column collection does not contain a virtual input column with lineage ID %3!d!.
' //
%DTS_E_LAYOUTCANTSETUSAGETYPE     = &HC0047046&

' //
' //  MessageId: DTS_E_WRONGOBJECTTYPE
' //
' //  MessageText:
' //
' //   The requested object has the incorrect object type.
' //
%DTS_E_WRONGOBJECTTYPE            = &HC0047047&

' ////////////////////////////////////////////////////////////////////////////
' //  Invalid file name or no rights. The Win32 error should have been reported separately.

' //
' //  MessageId: DTS_E_CANTCREATESPOOLFILE
' //
' //  MessageText:
' //
' //   The buffer manager cannot create a temporary storage file on any path in the BufferTempStoragePath property. There is an incorrect file name or no permission.
' //
%DTS_E_CANTCREATESPOOLFILE        = &HC0047048&

' ////////////////////////////////////////////////////////////////////////////
' //  File got corrupted. The Win32 error should have been reported separately.

' //
' //  MessageId: DTS_E_SEEKFAILED
' //
' //  MessageText:
' //
' //   The buffer manager could not seek to offset %1!d! in file "%2!s!". The file is damaged.
' //
%DTS_E_SEEKFAILED                 = &HC0047049&

' ////////////////////////////////////////////////////////////////////////////
' //  Out of disk space. The Win32 error should have been reported separately.

' //
' //  MessageId: DTS_E_EXTENDFAILED
' //
' //  MessageText:
' //
' //   The buffer manager cannot extend the file "%1!s!" to length %2!lu!.  There was insufficient disk space.
' //
%DTS_E_EXTENDFAILED               = &HC004704A&

' ////////////////////////////////////////////////////////////////////////////
' //  Out of disk space or quota. The Win32 error should have been reported separately.

' //
' //  MessageId: DTS_E_FILEWRITEFAILED
' //
' //  MessageText:
' //
' //   The buffer manager cannot write %1!d! bytes to file "%2!s!". There was insufficient disk space or quota.
' //
%DTS_E_FILEWRITEFAILED            = &HC004704B&

' ////////////////////////////////////////////////////////////////////////////
' // File got corrupted. The Win32 error should have been reported separately.

' //
' // MessageId: DTS_E_FILEREADFAILED
' //
' // MessageText:
' //
' //  The buffer manager cannot read %1!d! bytes from file "%2!s!". The file is damaged.
' //
%DTS_E_FILEREADFAILED             = &HC004704C&

' ////////////////////////////////////////////////////////////////////////////
' // Called SetSequentialMode() on a buffer that supports virtual buffers.

' //
' // MessageId: DTS_E_VIRTUALNOTSEQUENTIAL
' //
' // MessageText:
' //
' //  Buffer ID %1!d! supports other virtual buffers and cannot be placed into sequential mode. IDTSBuffer90.SetSequentialMode was called on a buffer that supports virtual buffers.
' //
%DTS_E_VIRTUALNOTSEQUENTIAL       = &HC004704D&

' ////////////////////////////////////////////////////////////////////////////
' // Can't change a read-only buffer.

' //
' // MessageId: DTS_E_BUFFERISREADONLY
' //
' // MessageText:
' //
' //  This operation could not be performed because buffer is in read-only mode. A read-only buffer cannot be modified.
' //
%DTS_E_BUFFERISREADONLY           = &HC004704E&

' //
' // MessageId: DTS_E_EXECUTIONTREECYCLESETTINGID
' //
' // MessageText:
' //
' //  ID %1!s! cannot be set to %2!d! because a cycle would be created.
' //
%DTS_E_EXECUTIONTREECYCLESETTINGID = &HC004704F&

' ////////////////////////////////////////////////////////////////////////////
' // Out of memory.

' //
' // MessageId: DTS_E_NOMOREBUFFERTYPES
' //
' // MessageText:
' //
' //  The buffer manager ran out of memory while trying to extend the table of buffer types. This is caused by an out-of-memory condition.
' //
%DTS_E_NOMOREBUFFERTYPES          = &HC0047050&

' //
' // MessageId: DTS_E_CANTCREATENEWTYPE
' //
' // MessageText:
' //
' //  The buffer manager failed to create a new buffer type.
' //
%DTS_E_CANTCREATENEWTYPE          = &HC0047051&

' ////////////////////////////////////////////////////////////////////////////
' // Internal error: the scehduler thinks there are more execution trees than there really are.

' //
' // MessageId: DTS_E_SCHEDULERBADTREE
' //
' // MessageText:
' //
' //  The Data Flow engine scheduler failed to retrieve the execution tree with index %1!d! from the layout. The scehduler received a count containing more execution trees than actually exist.
' //
%DTS_E_SCHEDULERBADTREE           = &HC0047053&

' ////////////////////////////////////////////////////////////////////////////
' // Probably out of memory; a previous message should indicate the actual cause of the failure.

' //
' // MessageId: DTS_E_CANTCREATEPRIMEOUTPUTBUFFER
' //
' // MessageText:
' //
' //  The Data Flow task failed to create a buffer to call PrimeOutput for output "%3!s!" (%4!d!) on component "%1!s!" (%2!d!). This error usually occurs due to an out-of-memory condition.
' //
%DTS_E_CANTCREATEPRIMEOUTPUTBUFFER = &HC0047056&

' ////////////////////////////////////////////////////////////////////////////
' // Out of memory.

' //
' // MessageId: DTS_E_SCHEDULERTHREADMEMORY
' //
' // MessageText:
' //
' //  The Data Flow engine scheduler failed to create a thread object because not enough memory is available. This is caused by an out-of-memory condition.
' //
%DTS_E_SCHEDULERTHREADMEMORY      = &HC0047057&

' ////////////////////////////////////////////////////////////////////////////
' // The scheduler previously saw an object, but then it disappeared. This is an internal error the pipeline.

' //
' // MessageId: DTS_E_SCHEDULEROBJECT
' //
' // MessageText:
' //
' //  The Data Flow engine scheduler cannot retrieve object with ID %1!d! from the layout. The Data Flow engine scheduler previously located an object that is now no longer available.
' //
%DTS_E_SCHEDULEROBJECT            = &HC004705A&

' ////////////////////////////////////////////////////////////////////////////
' // There should be a previous message which indicates the specific cause of failure.

' //
' // MessageId: DTS_E_PREPARETREENODEFAILED
' //
' // MessageText:
' //
' //  The Data Flow task failed to prepare buffers for the execution tree node beginning at output "%1!s!" (%2!d!).
' //
%DTS_E_PREPARETREENODEFAILED      = &HC004705B&

' //
' // MessageId: DTS_E_CANTCREATEVIRTUALBUFFER
' //
' // MessageText:
' //
' //  The Data Flow task cannot create a virtual buffer to prepare for execution.
' //
%DTS_E_CANTCREATEVIRTUALBUFFER    = &HC004705C&

' //
' // MessageId: DTS_E_NOMOREIDS
' //
' // MessageText:
' //
' //  The maximum ID has been reached. There are no more IDs available to assign to objects.
' //
%DTS_E_NOMOREIDS                  = &HC004705E&

' //
' // MessageId: DTS_E_ALREADYATTACHED
' //
' // MessageText:
' //
' //  The %1!s! is already attached and cannot be attached again.  Detach it and try again.
' //
%DTS_E_ALREADYATTACHED            = &HC004705F&

' //
' // MessageId: DTS_E_OUTPUTCOLUMNNAMECONFLICT
' //
' // MessageText:
' //
' //  Column name "%1!s!" on output "%2!s!" cannot be used because it conflicts with a column of the same name on synchronous input "%3!s!".
' //
%DTS_E_OUTPUTCOLUMNNAMECONFLICT   = &HC0047060&

' ////////////////////////////////////////////////////////////////////////////
' // The buffer manager should have posted an error describing the cause.

' //
' // MessageId: DTS_E_EOFANNOUNCEMENTFAILED
' //
' // MessageText:
' //
' //  The Data Flow task cannot to create a buffer to mark the end of the rowset.
' //
%DTS_E_EOFANNOUNCEMENTFAILED      = &HC0047061&

' ////////////////////////////////////////////////////////////////////////////
' // An invocation of managed user component resulted in an exception.

' //
' // MessageId: DTS_E_USERCOMPONENTEXCEPTION
' //
' // MessageText:
' //
' //  A managed user component has thrown exception "%1!s!".
' //
%DTS_E_USERCOMPONENTEXCEPTION     = &HC0047062&

' ////////////////////////////////////////////////////////////////////////////
' // Low on memory before execution even started.

' //
' // MessageId: DTS_E_SCHEDULERMEMORY
' //
' // MessageText:
' //
' //  The Data Flow engine scheduler cannot allocate enough memory for the execution structures. The system was low on memory before execution started.
' //
%DTS_E_SCHEDULERMEMORY            = &HC0047063&

' ////////////////////////////////////////////////////////////////////////////
' // Couldn't allocate C++ object for a buffer. Very low on memory!

' //
' // MessageId: DTS_E_BUFFERNOOBJECTMEMORY
' //
' // MessageText:
' //
' //  An out-of-memory condition prevented the creation of the buffer object.
' //
%DTS_E_BUFFERNOOBJECTMEMORY       = &HC0047064&

' ////////////////////////////////////////////////////////////////////////////
' // Couldn't allocate internal storage for a buffer. Very low on memory!

' //
' // MessageId: DTS_E_BUFFERNOMAPMEMORY
' //
' // MessageText:
' //
' //  An out-of-memory condition prevents the mapping of a buffer's lineage IDs to DTP_HCOL indexes.
' //
%DTS_E_BUFFERNOMAPMEMORY          = &HC0047065&

' ////////////////////////////////////////////////////////////////////////////
' // A component failed its put_Variables call.

' //
' // MessageId: DTS_E_INDIVIDUALPUTVARIABLESFAILED
' //
' // MessageText:
' //
' //  The "%1!s!" cannot cache the Variables collection and returned error code 0x%2!8.8X.
' //
%DTS_E_INDIVIDUALPUTVARIABLESFAILED = &HC0047066&

' ////////////////////////////////////////////////////////////////////////////
' // A component failed its put_ComponentMetaData call.

' //
' // MessageId: DTS_E_INDIVIDUALPUTCOMPONENTMETADATAFAILED
' //
' // MessageText:
' //
' //  The "%1!s!" failed to cache the component metadata object and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPUTCOMPONENTMETADATAFAILED = &HC0047067&

' //
' // MessageId: DTS_E_SORTEDOUTPUTHASINVALIDSORTKEYPOSITION
' //
' // MessageText:
' //
' //  "%1!s!" has a non-zero SortKeyPosition, but its value (%2!ld!) is too large. It must be less than or equal to the number of columns.
' //
%DTS_E_SORTEDOUTPUTHASINVALIDSORTKEYPOSITION = &HC0047068&

' //
' // MessageId: DTS_E_SORTEDOUTPUTHASINVALIDSORTKEYPOSITIONS
' //
' // MessageText:
' //
' //  The IsSorted property of %1!s! is set to TRUE, but the absolute values of the non-zero output column SortKeyPositions do not form a monotonically increasing sequence, starting at one.
' //
%DTS_E_SORTEDOUTPUTHASINVALIDSORTKEYPOSITIONS = &HC004706A&

' //
' // MessageId: DTS_E_INDIVIDUALVALIDATIONSTATUSFAILED
' //
' // MessageText:
' //
' //  "%1!s!" failed validation and returned validation status "%2!s!".
' //
%DTS_E_INDIVIDUALVALIDATIONSTATUSFAILED = &HC004706B&

' //
' // MessageId: DTS_E_CANTCREATECOMPONENT
' //
' // MessageText:
' //
' //  Component "%1!s!" could not be created and returned error code 0x%2!8.8X!. Make sure that the component is registered correctly.
' //
%DTS_E_CANTCREATECOMPONENT        = &HC004706C&

' //
' // MessageId: DTS_E_COMPONENTNOTREGISTERED
' //
' // MessageText:
' //
' //  The module containing "%1!s!" is not registered or installed correctly.
' //
%DTS_E_COMPONENTNOTREGISTERED     = &HC004706D&

' //
' // MessageId: DTS_E_COMPONENTNOTFOUND
' //
' // MessageText:
' //
' //  The module containing "%1!s!" cannot be located, even though it is registered.
' //
%DTS_E_COMPONENTNOTFOUND          = &HC004706E&

' ////////////////////////////////////////////////////////////////////////////
' // IDE was not visited after PreCompile property was set to True

' //
' // MessageId: DTS_E_BINARYCODENOTFOUND
' //
' // MessageText:
' //
' //  The script component is configured to pre-compile the script, but binary code is not found. Please visit the IDE in Script Component Editor by clicking Design Script button to cause binary code to be generated.
' //
%DTS_E_BINARYCODENOTFOUND         = &HC004706F&

' ////////////////////////////////////////////////////////////////////////////
' // Invalid file name or no rights. The Win32 error should have been reported separately.

' //
' // MessageId: DTS_E_CANTCREATEBLOBFILE
' //
' // MessageText:
' //
' //  The buffer manager cannot create a file to spool a long object on the directories named in the BLOBTempStoragePath property.  Either an incorrect file name was provided, or there are no permissions.
' //
%DTS_E_CANTCREATEBLOBFILE         = &HC0047070&

' //
' // MessageId: DTS_E_SYNCHRONOUSIDMISMATCH
' //
' // MessageText:
' //
' //  The SynchronousInputID property on "%1!s!" was %2!d!, and %3!d! was expected.
' //
%DTS_E_SYNCHRONOUSIDMISMATCH      = &HC0047071&

' //
' // MessageId: DTS_E_OBJECTIDNOTFOUND
' //
' // MessageText:
' //
' //  No object exists with the ID %1!d!.
' //
%DTS_E_OBJECTIDNOTFOUND           = &HC0047072&

' //
' // MessageId: DTS_E_OBJECTIDLOOKUPFAILED
' //
' // MessageText:
' //
' //  Unable to locate an object with ID %1!d! because of the error code 0x%2!8.8X!.
' //
%DTS_E_OBJECTIDLOOKUPFAILED       = &HC0047073&

' ////////////////////////////////////////////////////////////////////////////
' // Pick one that's valid.

' //
' // MessageId: DTS_E_INVALIDCODEPAGE
' //
' // MessageText:
' //
' //  The code page %1!d! specified on output column "%2!s!" (%3!d!) is not valid. Select a different code page for output column "%2!s!".
' //
%DTS_E_INVALIDCODEPAGE            = &HC0047074&

' ////////////////////////////////////////////////////////////////////////////
' // A component failed its put_EventInfos call.

' //
' // MessageId: DTS_E_INDIVIDUALPUTEVENTINFOSFAILED
' //
' // MessageText:
' //
' //  The EventInfos collection could not be cached by "%1!s!" and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPUTEVENTINFOSFAILED = &HC0047075&

' //
' // MessageId: DTS_E_DUPLICATEOUTPUTCOLUMNNAMES
' //
' // MessageText:
' //
' //  The name for "%1!s!" is a duplicate.  All names must be unique.
' //
%DTS_E_DUPLICATEOUTPUTCOLUMNNAMES = &HC0047077&

' //
' // MessageId: DTS_E_NOOUTPUTCOLUMNFORINPUTCOLUMN
' //
' // MessageText:
' //
' //  There is no output column associated with input column "%1!s!" (%2!d!).
' //
%DTS_E_NOOUTPUTCOLUMNFORINPUTCOLUMN = &HC0047078&

' ////////////////////////////////////////////////////////////////////////////
' // There is an exclusion group that isn't zero with a synchronous input that is zero.

' //
' // MessageId: DTS_E_EXCLGRPNOSYNCINP
' //
' // MessageText:
' //
' //  "%1!s!" has a virtual buffer extending from a root source. There is an exclusion group that is not zero with a synchronous input that is zero.
' //
%DTS_E_EXCLGRPNOSYNCINP           = &HC0047079&

' //
' // MessageId: DTS_E_ERROROUTCANTBEONSYNCNONEXCLUSIVEOUTPUT
' //
' // MessageText:
' //
' //  "%1!s!" cannot be an error output because error outputs cannot be placed on synchronous, non-exclusive outputs.
' //
%DTS_E_ERROROUTCANTBEONSYNCNONEXCLUSIVEOUTPUT = &HC004707A&

' //
' // MessageId: DTS_E_EXPREVALDIVBYZERO
' //
' // MessageText:
' //
' //  A divide-by-zero error occurred. The right side operand evaluates to zero in the expression "%1!s!".
' //
%DTS_E_EXPREVALDIVBYZERO          = &HC004707B&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the literal value specified overflows the type requested.

' //
' // MessageId: DTS_E_EXPREVALLITERALOVERFLOW
' //
' // MessageText:
' //
' //  The literal "%1!s!" is too large to fit into type %2!s!. The magnitude of the literal overflows the type.
' //
%DTS_E_EXPREVALLITERALOVERFLOW    = &HC004707C&

' ////////////////////////////////////////////////////////////////////////////
' // The operand types could not be implicitly cast into a numeric (DT_NUMERIC) result without loss of precision or scale. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALBINARYOPNUMERICOVERFLOW
' //
' // MessageText:
' //
' //  The result of the binary operation "%1!s!" on data types %2!s! and %3!s! exceeds the maximum size for numeric types. The operand types could not be implicitly cast into a numeric (DT_NUMERIC) result without
' //  loss of precision or scale. To perform this operation, one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALBINARYOPNUMERICOVERFLOW = &HC004707D&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the result of the operation overflows the type of the result

' //
' // MessageId: DTS_E_EXPREVALBINARYOPOVERFLOW
' //
' // MessageText:
' //
' //  The result of the binary operation "%1!s!" exceeds the maximum size for result data type "%2!s!". The magnitude of the result of the operation overflows the type of the result.
' //
%DTS_E_EXPREVALBINARYOPOVERFLOW   = &HC004707E&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the result of the function call overflows the type of the operand. An explicit cast to a larger type may be required.

' //
' // MessageId: DTS_E_EXPREVALFUNCTIONOVERFLOW
' //
' // MessageText:
' //
' //  The result of the function call "%1!s!" is too large to fit in type "%2!s!". The magnitude of the result of the function call overflows the type of the operand. An explicit cast to a larger type may be required.
' //
%DTS_E_EXPREVALFUNCTIONOVERFLOW   = &HC004707F&

' ////////////////////////////////////////////////////////////////////////////
' // The operand types could not be implicitly cast into compatible types for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALBINARYTYPEMISMATCH
' //
' // MessageText:
' //
' //  The data types "%1!s!" and "%2!s!" are incompatible for binary operator "%3!s!". The operand types could not be implicitly cast into compatible types for the operation. To perform this operation,
' //  one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALBINARYTYPEMISMATCH = &HC0047080&

' ////////////////////////////////////////////////////////////////////////////
' // The type of one or both of the operands is not supported for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALUNSUPPORTEDBINARYTYPE
' //
' // MessageText:
' //
' //  The data type "%1!s!" cannot be used with binary operator "%2!s!". The type of one or both of the operands is not supported for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALUNSUPPORTEDBINARYTYPE = &HC0047081&

' ////////////////////////////////////////////////////////////////////////////
' // The operands for this operator must be both positive or both negative.

' //
' // MessageId: DTS_E_EXPREVALBINARYSIGNMISMATCH
' //
' // MessageText:
' //
' //  There is a sign mismatch for the bitwise binary operator "%1!s!" in operation "%2!s!". Both operands for this operator must be positive or negative.
' //
%DTS_E_EXPREVALBINARYSIGNMISMATCH = &HC0047082&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error occurred, or out of memory.

' //
' // MessageId: DTS_E_EXPREVALBINARYOPERATIONFAILED
' //
' // MessageText:
' //
' //  The binary operation "%1!s!" failed with error code 0x%2!8.8X!. An internal error occurred, or an out-of-memory condition exists.
' //
%DTS_E_EXPREVALBINARYOPERATIONFAILED = &HC0047083&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while trying to set the result type of a binary operation.

' //
' // MessageId: DTS_E_EXPREVALBINARYOPERATIONSETTYPEFAILED
' //
' // MessageText:
' //
' //  Attempt to set the result type of binary operation "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALBINARYOPERATIONSETTYPEFAILED = &HC0047084&

' ////////////////////////////////////////////////////////////////////////////
' // Unable to compare the strings.

' //
' // MessageId: DTS_E_EXPREVALSTRINGCOMPARISONFAILED
' //
' // MessageText:
' //
' //  Comparing "%1!s!" to string "%2!s!" failed.
' //
%DTS_E_EXPREVALSTRINGCOMPARISONFAILED = &HC0047085&

' ////////////////////////////////////////////////////////////////////////////
' // The operand type is not supported for the operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALUNSUPPORTEDUNNARYTYPE
' //
' // MessageText:
' //
' //  The data type "%1!s!" cannot be used with unary operator "%2!s!". This operand type is not supported for the operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALUNSUPPORTEDUNNARYTYPE = &HC0047086&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error occurred, or out of memory.

' //
' // MessageId: DTS_E_EXPREVALUNARYOPERATIONFAILED
' //
' // MessageText:
' //
' //  The unary operation "%1!s!" failed with error code 0x%2!8.8X!. An internal error occurred, or there is an out-of-memory condition.
' //
%DTS_E_EXPREVALUNARYOPERATIONFAILED = &HC0047087&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while trying to set the result type of a unary operation.

' //
' // MessageId: DTS_E_EXPREVALUNARYOPERATIONSETTYPEFAILED
' //
' // MessageText:
' //
' //  Attempt to set the result type of unary operation "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALUNARYOPERATIONSETTYPEFAILED = &HC0047088&

' ////////////////////////////////////////////////////////////////////////////
' // The type of the parameter could not be implicitly cast into a compatible type for the function. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALPARAMTYPEMISMATCH
' //
' // MessageText:
' //
' //  The function "%1!s!" does not support the data type "%2!s!" for parameter number %3!d!. The type of the parameter could not be implicitly cast into a compatible type for the function. To perform this operation,
' //  the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALPARAMTYPEMISMATCH  = &HC0047089&

' ////////////////////////////////////////////////////////////////////////////
' // The function name is incorrect or does not exist.

' //
' // MessageId: DTS_E_EXPREVALINVALIDFUNCTION
' //
' // MessageText:
' //
' //  The function "%1!s!" was not recognized. Either the function name is incorrect or does not exist.
' //
%DTS_E_EXPREVALINVALIDFUNCTION    = &HC004708A&

' ////////////////////////////////////////////////////////////////////////////
' // The length parameter cannot be negative.

' //
' // MessageId: DTS_E_EXPREVALFNSUBSTRINGINVALIDLENGTH
' //
' // MessageText:
' //
' //  The length %1!d! is not valid for function "%2!s!". The length parameter cannot be negative. Change the length parameter to zero or a positive value.
' //
%DTS_E_EXPREVALFNSUBSTRINGINVALIDLENGTH = &HC004708B&

' ////////////////////////////////////////////////////////////////////////////
' // Start index is 1-based, not 0-based.

' //
' // MessageId: DTS_E_EXPREVALFNSUBSTRINGINVALIDSTARTINDEX
' //
' // MessageText:
' //
' //  The start index %1!d! is not valid for function "%2!s!". The start index value must be an integer greater than 0. Start index is one-based, not zero-based.
' //
%DTS_E_EXPREVALFNSUBSTRINGINVALIDSTARTINDEX = &HC004708C&

' ////////////////////////////////////////////////////////////////////////////
' // The attempt to perform the character mapping failed.

' //
' // MessageId: DTS_E_EXPREVALCHARMAPPINGFAILED
' //
' // MessageText:
' //
' //  The function "%1!s!" cannot perform the character mapping on string "%2!s!".
' //
%DTS_E_EXPREVALCHARMAPPINGFAILED  = &HC004708E&

' ////////////////////////////////////////////////////////////////////////////
' // The date part specified for the function was not recognized.

' //
' // MessageId: DTS_E_EXPREVALINVALIDDATEPART
' //
' // MessageText:
' //
' //  "%1!s!" is not a valid date part for function "%2!s!".
' //
%DTS_E_EXPREVALINVALIDDATEPART    = &HC004708F&

' ////////////////////////////////////////////////////////////////////////////
' // Parameters of NULL() must be static.  That is, they cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNULLPARAM
' //
' // MessageText:
' //
' //  Parameter number %1!d! of the function NULL with data type "%2!s!" is not valid. The parameters of NULL() must be static, and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALINVALIDNULLPARAM   = &HC0047090&

' ////////////////////////////////////////////////////////////////////////////
' // A parameter of NULL() must be an integer or a type that can be converted to an integer.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNULLPARAMTYPE
' //
' // MessageText:
' //
' //  Parameter number %1!d! of the function NULL with data type "%2!s!" is not an integer. A parameter of NULL() must be an integer or a type that can be converted to an integer.
' //
%DTS_E_EXPREVALINVALIDNULLPARAMTYPE = &HC0047091&

' ////////////////////////////////////////////////////////////////////////////
' // This parameter must be static.  That is, it cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALFUNCTIONPARAMNOTSTATIC
' //
' // MessageText:
' //
' //  Parameter number %1!d! of the function "%2!s!" is not static. This parameter must be static, and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALFUNCTIONPARAMNOTSTATIC = &HC0047092&

' ////////////////////////////////////////////////////////////////////////////
' // Parameters of cast operators must be static.  That is, they cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCASTPARAM
' //
' // MessageText:
' //
' //  Parameter number %1!d! of the cast to data type "%2!s!" is not valid. The parameters of cast operators must be static, and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALINVALIDCASTPARAM   = &HC0047093&

' ////////////////////////////////////////////////////////////////////////////
' // A parameter of a cast operator must be an integer or a type that can be converted to an integer.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCASTPARAMTYPE
' //
' // MessageText:
' //
' //  Parameter number %1!d! of the cast to data type "%2!s!" is not an integer. A parameter of a cast operator must be an integer or a type that can be converted to an integer.
' //
%DTS_E_EXPREVALINVALIDCASTPARAMTYPE = &HC0047094&

' ////////////////////////////////////////////////////////////////////////////
' // The requested cast is not supported.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCAST
' //
' // MessageText:
' //
' //  Cannot cast expression "%1!s!" from data type "%2!s!" to data type "%3!s!". The requested cast is not supported.
' //
%DTS_E_EXPREVALINVALIDCAST        = &HC0047095&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed because it contains invalid elements at the location specified.

' //
' // MessageId: DTS_E_EXPREVALINVALIDTOKEN
' //
' // MessageText:
' //
' //  Attempt to parse the expression "%1!s!" failed.  The token "%2!s!" at line number "%3!s!", character number "%4!s!" was not recognized. The expression cannot be parsed because it contains invalid elements at the location specified.
' //
%DTS_E_EXPREVALINVALIDTOKEN       = &HC0047096&

' ////////////////////////////////////////////////////////////////////////////
' // The expression failed to parse for an unknown reason.

' //
' // MessageId: DTS_E_EXPREVALUNEXPECTEDPARSEERROR
' //
' // MessageText:
' //
' //  An error occurred when parsing the expression "%1!s!". The expression failed to parse for an unknown reason.
' //
%DTS_E_EXPREVALUNEXPECTEDPARSEERROR = &HC0047097&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed. It might contain invalid elements, or it might not be well-formed. We may have run out of memory.

' //
' // MessageId: DTS_E_EXPREVALFAILEDTOPARSEEXPRESSIONWITHHR
' //
' // MessageText:
' //
' //  Attempt to parse the expression "%1!s!" failed and returned error code 0x%2!8.8X!. The expression cannot be parsed. It might contain invalid elements or it might not be well-formed. There may also be an out-of-memory error.
' //
%DTS_E_EXPREVALFAILEDTOPARSEEXPRESSIONWITHHR = &HC0047098&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed. It might contain invalid elements, or it might not be well-formed.

' //
' // MessageId: DTS_E_EXPREVALFAILEDTOPARSEEXPRESSION
' //
' // MessageText:
' //
' //  The expression "%1!s!" is not valid and cannot be parsed. The expression may contain invalid elements or it may not be well-formed.
' //
%DTS_E_EXPREVALFAILEDTOPARSEEXPRESSION = &HC0047099&

' ////////////////////////////////////////////////////////////////////////////
' // Attempted to compute or get the string of an empty expression.

' //
' // MessageId: DTS_E_EXPREVALEXPRESSIONEMPTY
' //
' // MessageText:
' //
' //  There was no expression to compute. An attempt was made to compute or get the string of an empty expression.
' //
%DTS_E_EXPREVALEXPRESSIONEMPTY    = &HC004709A&

' ////////////////////////////////////////////////////////////////////////////
' // Expression computation failed.

' //
' // MessageId: DTS_E_EXPREVALCOMPUTEFAILED
' //
' // MessageText:
' //
' //  Attempt to compute the expression "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALCOMPUTEFAILED      = &HC004709B&

' ////////////////////////////////////////////////////////////////////////////
' // Failed when attempting to generate a displayable string that represents the expression.

' //
' // MessageId: DTS_E_EXPREVALBUILDSTRINGFAILED
' //
' // MessageText:
' //
' //  Attempt to generate a string representation of the expression failed with error code 0x%1!8.8X!. Failed when attempting to generate a displayable string that represents the expression.
' //
%DTS_E_EXPREVALBUILDSTRINGFAILED  = &HC004709C&

' ////////////////////////////////////////////////////////////////////////////
' // The result of the expression should be written to an input/output column, but the data type of the expression cannot be converted to the data type of the column.

' //
' // MessageId: DTS_E_EXPREVALCANNOTCONVERTRESULT
' //
' // MessageText:
' //
' //  Cannot convert the expression result data type "%1!s!" to the column data type "%2!s!". The result of the expression should be written to an input/output column, but the data type of the expression cannot be converted to the data type of the column.
' //
%DTS_E_EXPREVALCANNOTCONVERTRESULT = &HC004709D&

' ////////////////////////////////////////////////////////////////////////////
' // The conditional expression of the conditional operator must be of type DT_BOOL.

' //
' // MessageId: DTS_E_EXPREVALCONDITIONALOPINVALIDCONDITIONTYPE
' //
' // MessageText:
' //
' //  The conditional expression "%1!s!" of the conditional operator has an invalid data type of "%2!s!". The conditional expression of the conditional operator must return a Boolean, which is type DT_BOOL.
' //
%DTS_E_EXPREVALCONDITIONALOPINVALIDCONDITIONTYPE = &HC004709E&

' ////////////////////////////////////////////////////////////////////////////
' // The operand types could not be implicitly cast into compatible types for the conditional operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALCONDITIONALOPTYPEMISMATCH
' //
' // MessageText:
' //
' //  The data types "%1!s!" and "%2!s!" are incompatible for the conditional operator. The operand types cannot be implicitly cast into compatible types for the conditional operation. To perform this operation,
' //  one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALCONDITIONALOPTYPEMISMATCH = &HC004709F&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while trying to set the result type of a conditional expression.

' //
' // MessageId: DTS_E_EXPREVALCONDITIONALOPSETTYPEFAILED
' //
' // MessageText:
' //
' //  Attempt to set the result type of conditional operation "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALCONDITIONALOPSETTYPEFAILED = &HC00470A0&

' ////////////////////////////////////////////////////////////////////////////
' // The buffer manager shutdown leaving this outstanding buffer, which would have been leaked. The owner of this buffer has overstayed their welcome.

' //
' // MessageId: DTS_E_BUFFERORPHANED
' //
' // MessageText:
' //
' //  This buffer has been orphaned. The buffer manager has shut down, leaving an outstanding buffer and no cleanup will occur for the buffer. There is a potential for memory leaks and other problems.
' //
%DTS_E_BUFFERORPHANED             = &HC00470A1&

' ////////////////////////////////////////////////////////////////////////////
' // The input column specified was not found in the input column collection.

' //
' // MessageId: DTS_E_EXPREVALINPUTCOLUMNNAMENOTFOUND
' //
' // MessageText:
' //
' //  Attempt to find the input column named "%1!s!" failed with error code 0x%2!8.8X!. The input column specified was not found in the input column collection.
' //
%DTS_E_EXPREVALINPUTCOLUMNNAMENOTFOUND = &HC00470A2&

' //
' // MessageId: DTS_E_EXPREVALINPUTCOLUMNIDNOTFOUND
' //
' // MessageText:
' //
' //  Attempt to find the input column with lineage ID %1!d! failed with error code 0x%2!8.8X!. The input column was not found in the input column collection.
' //
%DTS_E_EXPREVALINPUTCOLUMNIDNOTFOUND = &HC00470A3&

' ////////////////////////////////////////////////////////////////////////////
' // The specifed token is invalid. If the token was intended to be a variable name, it should be prefixed with the @ symbol.

' //
' // MessageId: DTS_E_EXPREVALNOINPUTCOLUMNCOLLECTIONFORCOLUMNNAME
' //
' // MessageText:
' //
' //  The expression contains unrecognized token "%1!s!". If "%1!s!" is a variable, it should be expressed as "@%1!s!". The specifed token is not valid. If the token is intended to be a variable name, it should be prefixed with the @ symbol.
' //
%DTS_E_EXPREVALNOINPUTCOLUMNCOLLECTIONFORCOLUMNNAME = &HC00470A4&

' ////////////////////////////////////////////////////////////////////////////
' // The token appears to be an input column lineage ID reference, but the input column collection has not been provided to the expression evaluator in this context (as is the case for runtime expressions).

' //
' // MessageId: DTS_E_EXPREVALNOINPUTCOLUMNCOLLECTIONFORCOLUMNID
' //
' // MessageText:
' //
' //  The expression contains unrecognized token "#%1!d!".
' //
%DTS_E_EXPREVALNOINPUTCOLUMNCOLLECTIONFORCOLUMNID = &HC00470A5&

' ////////////////////////////////////////////////////////////////////////////
' // The variable specified was not found in the variable collection. It might not exist in the correct scope.

' //
' // MessageId: DTS_E_EXPREVALVARIABLENOTFOUND
' //
' // MessageText:
' //
' //  The variable "%1!s!" was not found in the Variables collection. The variable might not exist in the correct scope.
' //
%DTS_E_EXPREVALVARIABLENOTFOUND   = &HC00470A6&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed. It might contain invalid elements, or be missing part of a required element (such as unmatched parentheses), or might not be well-formed.

' //
' // MessageId: DTS_E_EXPREVALINVALIDTOKENSTATE
' //
' // MessageText:
' //
' //  Attempt to parse the expression "%1!s!" failed. The expression might contain an invalid token, an incomplete token, or an invalid element. It might not be well-formed, or might be missing part of a required element such as a parenthesis.
' //
%DTS_E_EXPREVALINVALIDTOKENSTATE  = &HC00470A7&

' //
' // MessageId: DTS_E_BLANKOUTPUTCOLUMNNAME
' //
' // MessageText:
' //
' //  The name for "%1!s!" is blank, and names cannot be blank.
' //
%DTS_E_BLANKOUTPUTCOLUMNNAME      = &HC00470A8&

' ////////////////////////////////////////////////////////////////////////////
' // Set HasSideEffects to false

' //
' // MessageId: DTS_E_HASSIDEEFFECTSWITHSYNCINP
' //
' // MessageText:
' //
' //  The "%1!s!" has the HasSideEffects property set to TRUE, but "%1!s!" is synchronous and cannot have side effects. Set the HasSideEffects property to FALSE.
' //
%DTS_E_HASSIDEEFFECTSWITHSYNCINP  = &HC00470A9&

' ////////////////////////////////////////////////////////////////////////////
' // The specified code page is not installed on the machine.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCASTCODEPAGE
' //
' // MessageText:
' //
' //  The value, %1!d!, specified for the code page parameter of the cast to data type "%2!s!", is not valid. The code page is not installed on the machine.
' //
%DTS_E_EXPREVALINVALIDCASTCODEPAGE = &HC00470AA&

' ////////////////////////////////////////////////////////////////////////////
' // The specified precision was out of range for the type cast.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCASTPRECISION
' //
' // MessageText:
' //
' //  The value %1!d! specified for the precision parameter of the cast to data type "%2!s!" is not valid. Precision must be in the range %3!d! to %4!d! and the precision value is out of range for the type cast.
' //
%DTS_E_EXPREVALINVALIDCASTPRECISION = &HC00470AB&

' ////////////////////////////////////////////////////////////////////////////
' // The specified scale was out of range for the type cast. Scale must not exceed precision and must not be negative.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCASTSCALE
' //
' // MessageText:
' //
' //  The value %1!d! specified for the scale parameter of the cast to data type "%2!s!" is not valid. The scale must be in the range %3!d! to %4!d! and the scale value is out of range for the type cast. Scale must not exceed precision and must be positive.
' //
%DTS_E_EXPREVALINVALIDCASTSCALE   = &HC00470AC&

' //
' // MessageId: DTS_E_NONSORTEDOUTPUTHASSORTKEYPOSITIONS
' //
' // MessageText:
' //
' //  The IsSorted property for "%1!s!" is false, but %2!lu! of its output columns' SortKeyPositions are non-zero.
' //
%DTS_E_NONSORTEDOUTPUTHASSORTKEYPOSITIONS = &HC00470AD&

' ////////////////////////////////////////////////////////////////////////////
' // The code page of the left operand does not match the code page of the right operand.  For the conditional operator on the specified type, the code pages must be the same.

' //
' // MessageId: DTS_E_EXPREVALCONDITIONALOPCODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  The code pages must match for operands of conditional operation "%1!s!" for type %2!s!. The code page of the left operand does not match the code page of the right operand. For the conditional operator
' //  on the specified type, the code pages must be the same.
' //
%DTS_E_EXPREVALCONDITIONALOPCODEPAGEMISMATCH = &HC00470AF&

' //
' // MessageId: DTS_E_REFERENCEDMETADATABADCOUNT
' //
' // MessageText:
' //
' //  Input "%1!s!" (%2!d!) references input "%3!s!" (%4!d!), but they do not have the same number of columns. Input %5!d! has %6!d! columns, while input %7!d! has %8!d! columns.
' //
%DTS_E_REFERENCEDMETADATABADCOUNT = &HC00470B1&

' //
' // MessageId: DTS_E_OBJECTLINEAGEIDNOTFOUND
' //
' // MessageText:
' //
' //  No object exists with a lineage ID of %1!d!.
' //
%DTS_E_OBJECTLINEAGEIDNOTFOUND    = &HC00470B2&

' //
' // MessageId: DTS_E_FILENAMEOUTPUTCOLUMNOTFOUND
' //
' // MessageText:
' //
' //  The output column for the file name cannot be found.
' //
%DTS_E_FILENAMEOUTPUTCOLUMNOTFOUND = &HC00470B3&

' //
' // MessageId: DTS_E_FILENAMEOUTPUTCOLUMNINVALIDDATATYPE
' //
' // MessageText:
' //
' //  The output column for the file name is not a null-terminated Unicode character string, which is data type DT_WSTR.
' //
%DTS_E_FILENAMEOUTPUTCOLUMNINVALIDDATATYPE = &HC00470B4&

' ////////////////////////////////////////////////////////////////////////////
' // The target thread is probably shutting down.

' //
' // MessageId: DTS_E_DISTRIBUTORADDFAILED
' //
' // MessageText:
' //
' //  A distributor failed to give a buffer to thread "%1!s!" because of error 0x%2!8.8X!. The target thread is probably shutting down.
' //
%DTS_E_DISTRIBUTORADDFAILED       = &HC00470B5&

' //
' // MessageId: DTS_E_LOCALENOTINSTALLED
' //
' // MessageText:
' //
' //  The LocaleID %1!ld! is not installed on this system.
' //
%DTS_E_LOCALENOTINSTALLED         = &HC00470B6&

' ////////////////////////////////////////////////////////////////////////////
' // The specified escape sequence is not supported in string literals in the expression evaluator. Hexadecimal escape sequences must be of the form \xhhhh where h is a valid hexadecimal digit.

' //
' // MessageId: DTS_E_EXPREVALILLEGALHEXESCAPEINSTRINGLITERAL
' //
' // MessageText:
' //
' //  The string literal "%1!s!" contains an illegal hexadecimal escape sequence of  "\x%2!s!". The escape sequence is not supported in string literals in the expression evaluator. The hexadecimal escape sequences
' //  must be of the form \xhhhh where h is a valid hexadecimal digit.
' //
%DTS_E_EXPREVALILLEGALHEXESCAPEINSTRINGLITERAL = &HC00470B7&

' ////////////////////////////////////////////////////////////////////////////
' // The specified escape sequence is not supported in string literals in the expression evaluator. If the user is just trying to put a backslash in the string, "\\" will achieve that.

' //
' // MessageId: DTS_E_EXPREVALILLEGALESCAPEINSTRINGLITERAL
' //
' // MessageText:
' //
' //  The string literal "%1!s!" contains an illegal escape sequence of "\%2!c!". The escape sequence is not supported in string literals in the expression evaluator. If a backslash is needed in the string, use a double backslash, "\\".
' //
%DTS_E_EXPREVALILLEGALESCAPEINSTRINGLITERAL = &HC00470B8&

' ////////////////////////////////////////////////////////////////////////////
' // We found an asynchronous output with no output columns, and that's not allowed.

' //
' // MessageId: DTS_E_NOOUTPUTCOLUMNS
' //
' // MessageText:
' //
' //  "%1!s!" contains no output columns. An asynchronous output must contain output columns.
' //
%DTS_E_NOOUTPUTCOLUMNS            = &HC00470B9&

' //
' // MessageId: DTS_E_LOBDATATYPENOTSUPPORTED
' //
' // MessageText:
' //
' //  The "%1!s!" has a long object data type of DT_TEXT, DT_NTEXT, or DT_IMAGE, which is not supported.
' //
%DTS_E_LOBDATATYPENOTSUPPORTED    = &HC00470BA&

' ////////////////////////////////////////////////////////////////////////////
' // This is an internal error. This situation should never occur, but if it does, we have this error message to help us research why it might have happened.

' //
' // MessageId: DTS_E_OUTPUTWITHMULTIPLEERRORS
' //
' // MessageText:
' //
' //  Output ID %1!d! was given multiple error output configurations. First %2!d! and %3!d!, then %4!d! and %5!d!.
' //
%DTS_E_OUTPUTWITHMULTIPLEERRORS   = &HC00470BB&

' //
' // MessageId: DTS_E_FAILEDDURINGOLEDBDATATYPECONVERSIONCHECK
' //
' // MessageText:
' //
' //  The OLE DB provider failed during the data type conversion verification for "%1!s!".
' //
%DTS_E_FAILEDDURINGOLEDBDATATYPECONVERSIONCHECK = &HC00470BC&

' ////////////////////////////////////////////////////////////////////////////
' // Called AddRow or RemoveRow on a buffer that has the end of rowset flag.

' //
' // MessageId: DTS_E_BUFFERISEOR
' //
' // MessageText:
' //
' //  This buffer represents the end of the rowset and its row count cannot be altered.  An attempt was made to call AddRow or RemoveRow on a buffer that has the end of rowset flag.
' //
%DTS_E_BUFFERISEOR                = &HC00470BD&

' ////////////////////////////////////////////////////////////////////////////
' // The specified type is not supported or was not recognized.

' //
' // MessageId: DTS_E_EXPREVALUNSUPPORTEDTYPE
' //
' // MessageText:
' //
' //  The data type "%1!s!" is not supported in an expression. The specified type is not supported or is not valid.
' //
%DTS_E_EXPREVALUNSUPPORTEDTYPE    = &HC00470BE&

' ////////////////////////////////////////////////////////////////////////////
' // There's an error in the component. It should have reported EOR. The pipeline will shut down execution to avoid unpredictable results.

' //
' // MessageId: DTS_E_PRIMEOUTPUTNOEOR
' //
' // MessageText:
' //
' //  The PrimeOutput method on "%1!s!" returned success, but did not report an end of the rowset. There is an error in the component. It should have reported an end-of-row. The pipeline will shut down execution to avoid unpredictable results.
' //
%DTS_E_PRIMEOUTPUTNOEOR           = &HC00470BF&

' ////////////////////////////////////////////////////////////////////////////
' // The source type was too large to fit in the destination type.

' //
' // MessageId: DTS_E_EXPREVALDATACONVERSIONOVERFLOW
' //
' // MessageText:
' //
' //  An overflow occurred while converting from data type "%1!s!" to data type "%2!s!". The source type is too large for the destination type.
' //
%DTS_E_EXPREVALDATACONVERSIONOVERFLOW = &HC00470C0&

' ////////////////////////////////////////////////////////////////////////////
' // The source type could not be converted to the destination type.

' //
' // MessageId: DTS_E_EXPREVALDATACONVERSIONNOTSUPPORTED
' //
' // MessageText:
' //
' //  Conversion from data type "%1!s!" to data type "%2!s!" is unsupported. The source type cannot be converted to the destination type.
' //
%DTS_E_EXPREVALDATACONVERSIONNOTSUPPORTED = &HC00470C1&

' ////////////////////////////////////////////////////////////////////////////
' // The source type could not be converted to the destination type due to the specified error.

' //
' // MessageId: DTS_E_EXPREVALDATACONVERSIONFAILED
' //
' // MessageText:
' //
' //  Error code 0x%1!8.8X! occurred attempting to convert from data type %2!s! to data type %3!s!.
' //
%DTS_E_EXPREVALDATACONVERSIONFAILED = &HC00470C2&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error occurred, or out of memory.

' //
' // MessageId: DTS_E_EXPREVALCONDITIONALOPERATIONFAILED
' //
' // MessageText:
' //
' //  The conditional operation "%1!s!" failed with error code 0x%2!8.8X!. There was an internal error or an out-of-memory error.
' //
%DTS_E_EXPREVALCONDITIONALOPERATIONFAILED = &HC00470C3&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while attempting to perform the cast.

' //
' // MessageId: DTS_E_EXPREVALCASTFAILED
' //
' // MessageText:
' //
' //  Casting expression "%1!s!" from data type "%2!s!" to data type "%3!s!" failed with error code 0x%4!8.8X!.
' //
%DTS_E_EXPREVALCASTFAILED         = &HC00470C4&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while attempting to evaluate the function.

' //
' // MessageId: DTS_E_EXPREVALFUNCTIONCOMPUTEFAILED
' //
' // MessageText:
' //
' //  Evaluating function "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALFUNCTIONCOMPUTEFAILED = &HC00470C5&

' ////////////////////////////////////////////////////////////////////////////
' // The parameter could not be converted into a static value (typically, an integer).

' //
' // MessageId: DTS_E_EXPREVALFUNCTIONCONVERTPARAMTOMEMBERFAILED
' //
' // MessageText:
' //
' //  Parameter number %1!d! of the function "%2!s!" cannot be converted to a static value.
' //
%DTS_E_EXPREVALFUNCTIONCONVERTPARAMTOMEMBERFAILED = &HC00470C6&

' //
' // MessageId: DTS_E_REDIRECTROWUNAVAILABLEWITHFASTLOADANDZEROMAXINSERTCOMMITSIZE
' //
' // MessageText:
' //
' //  The error row disposition on "%1!s!" cannot be set to redirect the row when the fast load option is turned on, and the maximum insert commit size is set to zero.
' //
%DTS_E_REDIRECTROWUNAVAILABLEWITHFASTLOADANDZEROMAXINSERTCOMMITSIZE = &HC00470C7&

' ////////////////////////////////////////////////////////////////////////////
' // The code page of the left operand does not match the code page of the right operand.  For the specified binary operator on the specified type, the code pages must be the same.

' //
' // MessageId: DTS_E_EXPREVALBINARYOPERATORCODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  The code pages for operands of binary operator "%1!s!" for type "%2!s!" must match. Currently, the code page of the left operand does not match the code page of the right operand. For the specified binary
' //  operator on the specified type, the code pages must be the same.
' //
%DTS_E_EXPREVALBINARYOPERATORCODEPAGEMISMATCH = &HC00470CE&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while attempting to get the value of the variable.

' //
' // MessageId: DTS_E_EXPREVALVARIABLECOMPUTEFAILED
' //
' // MessageText:
' //
' //  Retrieving the value of Variable "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALVARIABLECOMPUTEFAILED = &HC00470CF&

' ////////////////////////////////////////////////////////////////////////////
' // The variable specified is of an unsupported type.

' //
' // MessageId: DTS_E_EXPREVALVARIABLETYPENOTSUPPORTED
' //
' // MessageText:
' //
' //  The data type of variable "%1!s!" is not supported in an expression.
' //
%DTS_E_EXPREVALVARIABLETYPENOTSUPPORTED = &HC00470D0&

' ////////////////////////////////////////////////////////////////////////////
' // The code page of the source must match the code page requested for the destination.

' //
' // MessageId: DTS_E_EXPREVALCASTCODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  Unable to cast expression "%1!s!" from data type "%2!s!" to data type "%3!s!" because the code page of the value being cast (%4!d!) does not match the requested result code page (%5!d!). The code page
' //  of the source must match the code page requested for the destination.
' //
%DTS_E_EXPREVALCASTCODEPAGEMISMATCH = &HC00470D1&

' ////////////////////////////////////////////////////////////////////////////
' // An attempt was made to set the DefaultBufferSize property to a value that's too small or too large.

' //
' // MessageId: DTS_E_BUFFERSIZEOUTOFRANGE
' //
' // MessageText:
' //
' //  The default buffer size must be between %1!d! and %2!d! bytes. An attempt was made to set the DefaultBufferSize property to a value that is too small or too large.
' //
%DTS_E_BUFFERSIZEOUTOFRANGE       = &HC00470D2&

' ////////////////////////////////////////////////////////////////////////////
' // An attempt was made to set the DefaultBufferMaxRows property to a value that's too small.

' //
' // MessageId: DTS_E_BUFFERMAXROWSIZEOUTOFRANGE
' //
' // MessageText:
' //
' //  The default buffer maximum rows must be larger than %1!d! rows. An attempt was made to set the DefaultBufferMaxRows property to a value that is too small.
' //
%DTS_E_BUFFERMAXROWSIZEOUTOFRANGE = &HC00470D3&

' //
' // MessageId: DTS_E_EXTERNALCOLUMNMETADATACODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  The code page on %1!s! is %2!d! and is required to be %3!d!.
' //
%DTS_E_EXTERNALCOLUMNMETADATACODEPAGEMISMATCH = &HC00470D4&

' ////////////////////////////////////////////////////////////////////////////
' // An attempt was made to set the property to a value that's too small.

' //
' // MessageId: DTS_E_THREADCOUNTOUTOFRANGE
' //
' // MessageText:
' //
' //  The EngineThreads property of the Data Flow task must be between %1!d! and %2!d!. An attempt was made to set the property to a value that is too small.
' //
%DTS_E_THREADCOUNTOUTOFRANGE      = &HC00470D5&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed because it contains invalid elements (a single quoation mark) at the location specified. A double quotation mark might be required there.

' //
' // MessageId: DTS_E_EXPREVALINVALIDTOKENSINGLEQUOTE
' //
' // MessageText:
' //
' //  Parsing the expression "%1!s!" failed. The single quotation mark at line number "%2!s!", character number "%3!s!", was not expected.
' //
%DTS_E_EXPREVALINVALIDTOKENSINGLEQUOTE = &HC00470D6&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed because it contains invalid elements (a single equal sign) at the location specified. A double equals might be required there.

' //
' // MessageId: DTS_E_EXPREVALINVALIDTOKENSINGLEEQUAL
' //
' // MessageText:
' //
' //  Parsing the expression "%1!s!" failed. The equal sign (=) at line number "%2!s!", character number "%3!s!", was not expected. A double equals sign (==) may be required at the location specified.
' //
%DTS_E_EXPREVALINVALIDTOKENSINGLEEQUAL = &HC00470D7&

' ////////////////////////////////////////////////////////////////////////////
' // A component failed its put_ReferenceTracker call.

' //
' // MessageId: DTS_E_INDIVIDUALPUTREFTRACKERFAILED
' //
' // MessageText:
' //
' //  Component "%1!s!" failed to cache the runtime object reference tracker collection and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPUTREFTRACKERFAILED = &HC00470DA&

' ////////////////////////////////////////////////////////////////////////////
' // The input column specified exists on more than one component.

' //
' // MessageId: DTS_E_EXPREVALAMBIGUOUSINPUTCOLUMNNAME
' //
' // MessageText:
' //
' //  There are multiple input columns with the name "%1!s!". The desired input column must be specified uniquely as [Component Name].[%2!s!] or referenced by lineage ID. Currently, the input column specified exists on more than one component.
' //
%DTS_E_EXPREVALAMBIGUOUSINPUTCOLUMNNAME = &HC00470DB&

' ////////////////////////////////////////////////////////////////////////////
' // The input column specified was not found in the input column collection.

' //
' // MessageId: DTS_E_EXPREVALDOTTEDINPUTCOLUMNNAMENOTFOUND
' //
' // MessageText:
' //
' //  Locating the input column named "[%1!s!].[%2!s!]" failed with error code 0x%3!8.8X!. The input column was not found in the input column collection.
' //
%DTS_E_EXPREVALDOTTEDINPUTCOLUMNNAMENOTFOUND = &HC00470DC&

' ////////////////////////////////////////////////////////////////////////////
' // The variable specified exists in more than one namespace.

' //
' // MessageId: DTS_E_EXPREVALAMBIGUOUSVARIABLENNAME
' //
' // MessageText:
' //
' //  There are multiple variables with the name "%1!s!". The desired variable must be specified uniquely as @[Namespace::%2!s!]. The variable exists in more than one namespace.
' //
%DTS_E_EXPREVALAMBIGUOUSVARIABLENNAME = &HC00470DD&

' ////////////////////////////////////////////////////////////////////////////
' // Internal pipeline error. Try running with the OptimizedMode property set false.

' //
' // MessageId: DTS_E_REDUCTIONFAILED
' //
' // MessageText:
' //
' //  The Data Flow engine scheduler failed to reduce the execution plan for the pipeline. Set the OptimizedMode property to false.
' //
%DTS_E_REDUCTIONFAILED            = &HC00470DE&

' ////////////////////////////////////////////////////////////////////////////
' // A negative value was passed to the SQRT function.

' //
' // MessageId: DTS_E_EXPREVALSQRTINVALIDPARAM
' //
' // MessageText:
' //
' //  The function SQRT cannot operate on negative values, and a negative value was passed to the SQRT function.
' //
%DTS_E_EXPREVALSQRTINVALIDPARAM   = &HC00470DF&

' ////////////////////////////////////////////////////////////////////////////
' // A zero or negative value was passed to the LN function.

' //
' // MessageId: DTS_E_EXPREVALLNINVALIDPARAM
' //
' // MessageText:
' //
' //  The function LN cannot operate on zero or negative values, and a zero or negative value was passed to the LN function.
' //
%DTS_E_EXPREVALLNINVALIDPARAM     = &HC00470E0&

' ////////////////////////////////////////////////////////////////////////////
' // A zero or negative value was passed to the LOG function.

' //
' // MessageId: DTS_E_EXPREVALLOGINVALIDPARAM
' //
' // MessageText:
' //
' //  The function LOG cannot operate on zero or negative values, and a zero or negative value was passed to the LOG function.
' //
%DTS_E_EXPREVALLOGINVALIDPARAM    = &HC00470E1&

' ////////////////////////////////////////////////////////////////////////////
' // The values passed in to the POWER function cannot be evaluated.

' //
' // MessageId: DTS_E_EXPREVALPOWERINVALIDPARAM
' //
' // MessageText:
' //
' //  The parameters passed to the function POWER cannot be evaluated and yield an indeterminate result.
' //
%DTS_E_EXPREVALPOWERINVALIDPARAM  = &HC00470E2&

' ////////////////////////////////////////////////////////////////////////////
' // Something is wrong with the runtime.

' //
' // MessageId: DTS_E_NOCANCELEVENT
' //
' // MessageText:
' //
' //  The runtime cannot provide a cancel event because of error 0x%1!8.8X!.
' //
%DTS_E_NOCANCELEVENT              = &HC00470E3&

' ////////////////////////////////////////////////////////////////////////////
' // Somebody set the cancel event.

' //
' // MessageId: DTS_E_CANCELRECEIVED
' //
' // MessageText:
' //
' //  The pipeline received a request to cancel and is shutting down.
' //
%DTS_E_CANCELRECEIVED             = &HC00470E4&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the result of the operation overflows the type of the result

' //
' // MessageId: DTS_E_EXPREVALUNARYOPOVERFLOW
' //
' // MessageText:
' //
' //  The result of the unary minus (negation) operation "%1!s!" exceeds the maximum size for result data type "%2!s!". The magnitude of the result of the operation overflows the type of the result.
' //
%DTS_E_EXPREVALUNARYOPOVERFLOW    = &HC00470E5&

' ////////////////////////////////////////////////////////////////////////////
' // A placeholder function parameter or operand was found in the expression.

' //
' // MessageId: DTS_E_EXPREVALPLACEHOLDERINEXPRESSION
' //
' // MessageText:
' //
' //  The placeholder "%1!s!" was found in an expression. This must be replaced with an actual parameter or operand.
' //
%DTS_E_EXPREVALPLACEHOLDERINEXPRESSION = &HC00470E6&

' ////////////////////////////////////////////////////////////////////////////
' // The length parameter cannot be negative.

' //
' // MessageId: DTS_E_EXPREVALFNRIGHTINVALIDLENGTH
' //
' // MessageText:
' //
' //  The length %1!d! specified for function "%2!s!" is negative, and is not valid. The length parameter must be positive.
' //
%DTS_E_EXPREVALFNRIGHTINVALIDLENGTH = &HC00470E7&

' ////////////////////////////////////////////////////////////////////////////
' // The repeat count parameter cannot be negative.

' //
' // MessageId: DTS_E_EXPREVALFNREPLICATEINVALIDREPEATCOUNT
' //
' // MessageText:
' //
' //  The repeat count %1!d! is negative and is not valid for function "%2!s!". The repeat count parameter cannot be negative.
' //
%DTS_E_EXPREVALFNREPLICATEINVALIDREPEATCOUNT = &HC00470E8&

' ////////////////////////////////////////////////////////////////////////////
' // Attempting to read the variable failed with the specified error.

' //
' // MessageId: DTS_E_EXPREVALVARIABLECOULDNOTBEREAD
' //
' // MessageText:
' //
' //  Reading the variable "%1!s!" failed with error code 0x%2!8.8X!.
' //
%DTS_E_EXPREVALVARIABLECOULDNOTBEREAD = &HC00470EA&

' ////////////////////////////////////////////////////////////////////////////
' // A DT_STR operand that is not an input column or the result of a cast cannot be used in a binary operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALBINARYOPDTSTRNOTSUPPORTED
' //
' // MessageText:
' //
' //  For operands of a binary operation, the data type DT_STR is supported only for input columns and cast operations. The expression "%1!s!" has a DT_STR operand that is not an input column or the result of a cast,
' //  and cannot be used in a binary operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALBINARYOPDTSTRNOTSUPPORTED = &HC00470EC&

' ////////////////////////////////////////////////////////////////////////////
' // A DT_STR operand that is not an input column or the result of a cast cannot be used with the conditional operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALCONDITIONALOPDTSTRNOTSUPPORTED
' //
' // MessageText:
' //
' //  For operands of the conditional operator, the data type DT_STR is supported only for input columns and cast operations. The expression "%1!s!" has a DT_STR operand that is not an input column or the result
' //  of a cast, and cannot be used with the conditional operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALCONDITIONALOPDTSTRNOTSUPPORTED = &HC00470ED&

' ////////////////////////////////////////////////////////////////////////////
' // The occurrence count parameter must be positive.

' //
' // MessageId: DTS_E_EXPREVALFNFINDSTRINGINVALIDOCCURRENCECOUNT
' //
' // MessageText:
' //
' //  The occurrence count %1!d! is not valid for function "%2!s!". This parameter must be greater than zero.
' //
%DTS_E_EXPREVALFNFINDSTRINGINVALIDOCCURRENCECOUNT = &HC00470EE&

' ////////////////////////////////////////////////////////////////////////////
' // A component failed its put_LogEntryInfos call.

' //
' // MessageId: DTS_E_INDIVIDUALPUTLOGENTRYINFOS
' //
' // MessageText:
' //
' //  "%1!s!" failed to cache the LogEntryInfos collection and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALPUTLOGENTRYINFOS = &HC00470EF&

' ////////////////////////////////////////////////////////////////////////////
' // Date part parameters must be static strings.  That is, they cannot contain dynamic elements such as input columns, and must be of type DT_WSTR.

' //
' // MessageId: DTS_E_EXPREVALINVALIDDATEPARTNODE
' //
' // MessageText:
' //
' //  The date part parameter specified for function "%1!s!" is not valid. It must be a static string.  The date part parameter cannot contain dynamic elements, such as input columns, and must be of type DT_WSTR.
' //
%DTS_E_EXPREVALINVALIDDATEPARTNODE = &HC00470F0&

' ////////////////////////////////////////////////////////////////////////////
' // The specified length for the type cast is negative.

' //
' // MessageId: DTS_E_EXPREVALINVALIDCASTLENGTH
' //
' // MessageText:
' //
' //  The value %1!d! specified for the length parameter of the cast to data type %2!s! is negative and not valid. The length must be positive.
' //
%DTS_E_EXPREVALINVALIDCASTLENGTH  = &HC00470F1&

' ////////////////////////////////////////////////////////////////////////////
' // The specified code page is not installed on the machine.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNULLCODEPAGE
' //
' // MessageText:
' //
' //  The value %1!d! specified for the code page parameter of the NULL function with data type "%2!s!" is not valid. The code page is not installed on the computer.
' //
%DTS_E_EXPREVALINVALIDNULLCODEPAGE = &HC00470F2&

' ////////////////////////////////////////////////////////////////////////////
' // The specified precision was out of range for the NULL function type.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNULLPRECISION
' //
' // MessageText:
' //
' //  The value %1!d! specified for the precision parameter of the NULL function with data type "%2!s!" is out of range. Precision must be in the range %3!d! to %4!d!.
' //
%DTS_E_EXPREVALINVALIDNULLPRECISION = &HC00470F3&

' ////////////////////////////////////////////////////////////////////////////
' // The specified scale was out of range for the NULL function type. Scale must not exceed precision and must not be negative.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNULLSCALE
' //
' // MessageText:
' //
' //  The value %1!d! specified for the scale parameter of the NULL function with data type %2!s! is out of range. Scale must be in the range %3!d! to %4!d!. Scale must not exceed precision and must not be negative.
' //
%DTS_E_EXPREVALINVALIDNULLSCALE   = &HC00470F4&

' ////////////////////////////////////////////////////////////////////////////
' // The specified length parameter for the NULL function is negative.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNULLLENGTH
' //
' // MessageText:
' //
' //  The value %1!d! specified for the length parameter of the "NULL" function with data type %2!s! is negative and not valid. The length must be positive.
' //
%DTS_E_EXPREVALINVALIDNULLLENGTH  = &HC00470F5&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when user assigns a negative value to a property that should be only positive.

' //
' // MessageId: DTS_E_NEGATIVESNOTALLOWED
' //
' // MessageText:
' //
' //  The %1!s! can't be assigned a negative value.
' //
%DTS_E_NEGATIVESNOTALLOWED        = &HC00470F6&

' ////////////////////////////////////////////////////////////////////////////
' // The column data type has to be one of DT_I1, DT_I2, DT_I4, DT_I8, DT_UI1, DT_UI2, DT_UI4, DT_UI8, DT_R4, DT_R8, DT_DBTIMESTAMP, DT_DBDATE, DT_DBTIME, or DT_FILETIME.

' //
' // MessageId: DTS_E_FASTPARSENOTALLOWED
' //
' // MessageText:
' //
' //  The "%1!s!" custom property for "%2!s!" cannot be set to true.  The column data type must be one of the following:  DT_I1, DT_I2, DT_I4, DT_I8, DT_UI1, DT_UI2, DT_UI4, DT_UI8, DT_R4, DT_R8, DT_DBTIMESTAMP, DT_DBDATE, DT_DBTIME, or DT_FILETIME.
' //
%DTS_E_FASTPARSENOTALLOWED        = &HC00470F7&

' ////////////////////////////////////////////////////////////////////////////
' // Delete the path, add a new one, and attach it.

' //
' // MessageId: DTS_E_CANNOTREATTACHPATH
' //
' // MessageText:
' //
' //  The "%1!s!" cannot be reattached. Delete the path, add a new one, and attach it.
' //
%DTS_E_CANNOTREATTACHPATH         = &HC00470F8&

' ////////////////////////////////////////////////////////////////////////////
' // The function name was recognized, but the number of parameters was incorrect.

' //
' // MessageId: DTS_E_EXPREVALINVALIDNUMBEROFPARAMSPLURALSINGULAR
' //
' // MessageText:
' //
' //  The function "%1!s!" requires %2!d! parameters, not %3!d! parameter. The function name was recognized, but the number of parameters is not valid.
' //
%DTS_E_EXPREVALINVALIDNUMBEROFPARAMSPLURALSINGULAR = &HC00470F9&

' //
' // MessageId: DTS_E_EXPREVALINVALIDNUMBEROFPARAMSSINGULARPLURAL
' //
' // MessageText:
' //
' //  The function "%1!s!" requires %2!d! parameter, not %3!d! parameters. The function name was recognized, but the number of parameters is not valid.
' //
%DTS_E_EXPREVALINVALIDNUMBEROFPARAMSSINGULARPLURAL = &HC00470FA&

' //
' // MessageId: DTS_E_EXPREVALINVALIDNUMBEROFPARAMSPLURALPLURAL
' //
' // MessageText:
' //
' //  The function "%1!s!" requires %2!d! parameters, not %3!d! parameters. The function name was recognized, but the number of parameters is not valid.
' //
%DTS_E_EXPREVALINVALIDNUMBEROFPARAMSPLURALPLURAL = &HC00470FB&

' ////////////////////////////////////////////////////////////////////////////
' // Out of memory.

' //
' // MessageId: DTS_E_EXPREVALFAILEDTOPARSEEXPRESSIONOUTOFMEMORY
' //
' // MessageText:
' //
' //  Attempt to parse the expression "%1!s!" failed because there was an out-of-memory error.
' //
%DTS_E_EXPREVALFAILEDTOPARSEEXPRESSIONOUTOFMEMORY = &HC00470FC&

' //
' // MessageId: DTS_E_INDIVIDUALCHECKPRODUCTLEVELFAILED
' //
' // MessageText:
' //
' //  The %1!s! failed to be able to perform its required product level check and returned error code 0x%2!8.8X!.
' //
%DTS_E_INDIVIDUALCHECKPRODUCTLEVELFAILED = &HC00470FD&

' ////////////////////////////////////////////////////////////////////////////
' // The product level is to low for the component

' //
' // MessageId: DTS_E_PRODUCTLEVELTOLOW
' //
' // MessageText:
' //
' //  The product level is insufficient for %1!s!.
' //
%DTS_E_PRODUCTLEVELTOLOW          = &HC00470FE&

' ////////////////////////////////////////////////////////////////////////////
' // The string literal exceeds the maximum length allowed in an expression.

' //
' // MessageId: DTS_E_EXPREVALSTRINGLITERALTOOLONG
' //
' // MessageText:
' //
' //  A string literal in the expression exceeds the maximum allowed length of %1!d! characters.
' //
%DTS_E_EXPREVALSTRINGLITERALTOOLONG = &HC00470FF&

' ////////////////////////////////////////////////////////////////////////////
' // The string in the variable exceeds the maximum length allowed in an expression.

' //
' // MessageId: DTS_E_EXPREVALSTRINGVARIABLETOOLONG
' //
' // MessageText:
' //
' //  The variable %1!s! contains a string that exceeds the maximum allowed length of %2!d! characters.
' //
%DTS_E_EXPREVALSTRINGVARIABLETOOLONG = &HC0047100&

' //
' // MessageId: DTS_E_CANNOTOPENREGISTRYKEY
' //
' // MessageText:
' //
' //  The registry key "%1!s!" cannot be opened.
' //
%DTS_E_CANNOTOPENREGISTRYKEY      = &HC0048000&

' ////////////////////////////////////////////////////////////////////////////
' // Make sure the component is registered properly or the CLS ID is correct.

' //
' // MessageId: DTS_E_INVALIDCOMPONENTFILENAME
' //
' // MessageText:
' //
' //  Cannot get the file name for the component with a CLSID of "%1!s!". Verify that the component is registered properly or that the CLSID provided is correct.
' //
%DTS_E_INVALIDCOMPONENTFILENAME   = &HC0048001&

' ////////////////////////////////////////////////////////////////////////////
' // Make sure all components in the Pipeline have valid CLS ID's.

' //
' // MessageId: DTS_E_UNKNOWNCOMPONENTHASINVALIDCLSID
' //
' // MessageText:
' //
' //  The CLSID for one of the components is not valid. Verify that all the components in the pipeline have valid CLSIDs.
' //
%DTS_E_UNKNOWNCOMPONENTHASINVALIDCLSID = &HC0048002&

' //
' // MessageId: DTS_E_COMPONENTHASINVALIDCLSID
' //
' // MessageText:
' //
' //  The CLSID for one of the components with ID %1!d! is not valid.
' //
%DTS_E_COMPONENTHASINVALIDCLSID   = &HC0048003&

' //
' // MessageId: DTS_E_INVALIDINDEX
' //
' // MessageText:
' //
' //  The index is not valid.
' //
%DTS_E_INVALIDINDEX               = &HC0048004&

' ////////////////////////////////////////////////////////////////////////////
' // Make sure dts.dll is accessible.

' //
' // MessageId: DTS_E_CANNOTACCESSDTSAPPLICATIONOBJECT
' //
' // MessageText:
' //
' //  The Application object cannot be accessed. Verify that SSIS is correctly installed.
' //
%DTS_E_CANNOTACCESSDTSAPPLICATIONOBJECT = &HC0048005&

' //
' // MessageId: DTS_E_ERROROCCURREDWHILERETRIEVINGFILENAME
' //
' // MessageText:
' //
' //  Retrieving the file name for a component failed with error code 0x%1!8.8X!.
' //
%DTS_E_ERROROCCURREDWHILERETRIEVINGFILENAME = &HC0048006&

' //
' // MessageId: DTS_E_CANNOTRETRIEVEPROPERTYFORCOMPONENT
' //
' // MessageText:
' //
' //  Cannot retrieve property "%1!s!" from component with ID %2!d!.
' //
%DTS_E_CANNOTRETRIEVEPROPERTYFORCOMPONENT = &HC0048007&

' //
' // MessageId: DTS_E_DUPLICATEIDFOUND
' //
' // MessageText:
' //
' //  Attempting to use ID %1!d! more than once in the Data Flow Task.
' //
%DTS_E_DUPLICATEIDFOUND           = &HC0048008&

' //
' // MessageId: DTS_E_CANNOTRETRIEVEBYLINEAGE
' //
' // MessageText:
' //
' //  Cannot retrieve an item by lineage ID from a collection that does not contain columns.
' //
%DTS_E_CANNOTRETRIEVEBYLINEAGE    = &HC0048009&

' ////////////////////////////////////////////////////////////////////////////
' // Make sure a connection manager in the runtime's connection manager collection has been created with that ID.

' //
' // MessageId: DTS_E_CANNOTMAPRUNTIMECONNECTIONMANAGER
' //
' // MessageText:
' //
' //  Cannot find the connection manager with ID "%1!s!" in the connection manager collection due to error code 0x%2!8.8X!. That connection manager is needed by "%3!s!" in the connection manager collection of "%4!s!".
' //  Verify that a connection manager in the connection manager collection, Connections, has been created with that ID.
' //
%DTS_E_CANNOTMAPRUNTIMECONNECTIONMANAGER = &HC004800B&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error in the scheduler has built a bad execution plan.

' //
' // MessageId: DTS_E_INPUTNOTKNOWN
' //
' // MessageText:
' //
' //  Thread "%1!s!" received a buffer for input %2!d!, but this thread is not responsible for that input. An error occurred, causing the Data Flow engine scheduler to build a bad execution plan.
' //
%DTS_E_INPUTNOTKNOWN              = &HC004800E&

' ////////////////////////////////////////////////////////////////////////////
' // The component is broken.

' //
' // MessageId: DTS_E_GETRTINTERFACEFAILED
' //
' // MessageText:
' //
' //  The component "%1!s!" (%2!d!) cannot provide an IDTSRuntimeComponent90 interface.
' //
%DTS_E_GETRTINTERFACEFAILED       = &HC004800F&

' ////////////////////////////////////////////////////////////////////////////
' // The cause was previously reported.

' //
' // MessageId: DTS_E_CANTGIVEAWAYBUFFER
' //
' // MessageText:
' //
' //  The Data Flow task engine attempted to copy a buffer to assign another thread, but failed.
' //
%DTS_E_CANTGIVEAWAYBUFFER         = &HC0048011&

' //
' // MessageId: DTS_E_CANTCREATEVIEWBUFFER
' //
' // MessageText:
' //
' //  The Data Flow task engine failed to create a view buffer of type %1!d! over type %2!d! for buffer %3!d.
' //
%DTS_E_CANTCREATEVIEWBUFFER       = &HC0048012&

' //
' // MessageId: DTS_E_UNUSABLETEMPORARYPATH
' //
' // MessageText:
' //
' //  The buffer manager could not create a temporary file on the path "%1!s!". The path will not be considered for temporary storage again.
' //
%DTS_E_UNUSABLETEMPORARYPATH      = &HC0048013&

' ////////////////////////////////////////////////////////////////////////////
' // Someone called DirectErrorRow() on an output that isn't an error output.

' //
' // MessageId: DTS_E_DIRECTTONONERROROUTPUT
' //
' // MessageText:
' //
' //  The buffer manager attempted to push an error row to an output that was not registered as an error output. There was a call to DirectErrorRow on an output that does not have the IsErrorOut property set to TRUE.
' //
%DTS_E_DIRECTTONONERROROUTPUT     = &HC0048014&

' ////////////////////////////////////////////////////////////////////////////
' // A call was made to a buffer method on a private buffer, and private buffers do not support that method.

' //
' // MessageId: DTS_E_BUFFERISPRIVATE
' //
' // MessageText:
' //
' //  A call was made to a buffer method on a private buffer and private buffers do not support this operation.
' //
%DTS_E_BUFFERISPRIVATE            = &HC0048015&

' //
' // MessageId: DTS_E_BUFFERISFLAT
' //
' // MessageText:
' //
' //  Private mode buffers do not support this operation.
' //
%DTS_E_BUFFERISFLAT               = &HC0048016&

' ////////////////////////////////////////////////////////////////////////////
' // A call was made to a buffer method during PrimeOutput, but that call is not allowed during PrimeOutput.

' //
' // MessageId: DTS_E_BUFFERISPRIMEOUTPUT
' //
' // MessageText:
' //
' //  This operation cannot be called on a buffer passed to PrimeOutput. A call was made to a buffer method during PrimeOutput, but that call is not allowed during PrimeOutput.
' //
%DTS_E_BUFFERISPRIMEOUTPUT        = &HC0048017&

' ////////////////////////////////////////////////////////////////////////////
' // A call was made to a buffer method during ProcessInput, but that call is not allowed during ProcessInput.

' //
' // MessageId: DTS_E_BUFFERISPROCESSINPUT
' //
' // MessageText:
' //
' //  This operation cannot be called on a buffer passed to ProcessInput. A call was made to a buffer method during ProcessInput, but that call is not allowed during ProcessInput.
' //
%DTS_E_BUFFERISPROCESSINPUT       = &HC0048018&

' ////////////////////////////////////////////////////////////////////////////
' // A call to GetTempFileName failed. We don't know how to handle that!

' //
' // MessageId: DTS_E_BUFFERGETTEMPFILENAME
' //
' // MessageText:
' //
' //  The buffer manager could not get a temporary file name. The call to GetTempFileName failed.
' //
%DTS_E_BUFFERGETTEMPFILENAME      = &HC0048019&

' //
' // MessageId: DTS_E_REFERENCECOLUMNTOOWIDE
' //
' // MessageText:
' //
' //  The code encountered a column that was too wide.
' //
%DTS_E_REFERENCECOLUMNTOOWIDE     = &HC004801A&

' ////////////////////////////////////////////////////////////////////////////
' // Make sure the ConnectionManagerID property of the runtime connection object has been set for the component.

' //
' // MessageId: DTS_E_CANNOTGETRUNTIMECONNECTIONMANAGERID
' //
' // MessageText:
' //
' //  Cannot get the ID of the runtime connection manager specified by "%1!s!" in the connection manager collection, Connectons, of "%2!s!" due to error code 0x%3!8.8X!. Verify that the ConnectionManager.ID property
' //  of the runtime connection object has been set for the component.
' //
%DTS_E_CANNOTGETRUNTIMECONNECTIONMANAGERID = &HC004801B&

' //
' // MessageId: DTS_E_EMPTYRUNTIMECONNECTIONMANAGERID
' //
' // MessageText:
' //
' //  The "%1!s!" in the connection manager collection, Connections, of "%2!s!" does not have a value for the ID property. Verify that the ConnectionManagerID property of the runtime connection object has been set for the component.
' //
%DTS_E_EMPTYRUNTIMECONNECTIONMANAGERID = &HC004801C&

' //
' // MessageId: DTS_E_METADATAREADONLY
' //
' // MessageText:
' //
' //  Metadata cannot be changed during execution.
' //
%DTS_E_METADATAREADONLY           = &HC004801D&

' ////////////////////////////////////////////////////////////////////////////
' // The PerformUpgrade method failed.

' //
' // MessageId: DTS_E_UPGRADEFAILED
' //
' // MessageText:
' //
' //  The component metadata for "%1!s!" could not be upgraded to the newer version of the component. The PerformUpgrade method failed.
' //
%DTS_E_UPGRADEFAILED              = &HC004801F&

' ////////////////////////////////////////////////////////////////////////////
' // The version or pipeline version or both for the specified component is higher than the current version.  This package was probably created on a newer version of SSIS or the component than is installed on the current PC.

' //
' // MessageId: DTS_E_COMPONENTVERSIONMISMATCH
' //
' // MessageText:
' //
' //  The version of %1!s! is not compatible with this version of the DataFlow.
' //
%DTS_E_COMPONENTVERSIONMISMATCH   = &HC0048020&

' ////////////////////////////////////////////////////////////////////////////
' // The component is missing, not registered, not upgradeable, missing needed interfaces and can not be instantiated on this computer so the contact information for the component is displayed.

' //
' // MessageId: DTS_E_ERRORCOMPONENT
' //
' // MessageText:
' //
' //  The component is missing, not registered, not upgradeable, or missing required interfaces. The contact information for this component is "%1!s!".
' //
%DTS_E_ERRORCOMPONENT             = &HC0048021&

' ////////////////////////////////////////////////////////////////////////////
' // Someone called a method on a buffer that's not the right buffer -- calling SetEndOfRowset on a private buffer, for example.

' //
' // MessageId: DTS_E_BUFFERISNOTPRIMEOUTPUT
' //
' // MessageText:
' //
' //  The method was called on the wrong buffer. Buffers that are not used for component output do not support this operation.
' //
%DTS_E_BUFFERISNOTPRIMEOUTPUT     = &HC0048022&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be computed

' //
' // MessageId: DTS_E_EXPREVALSTATIC_COMPUTATIONFAILED
' //
' // MessageText:
' //
' //  An error occurred during computation of the expression.
' //
%DTS_E_EXPREVALSTATIC_COMPUTATIONFAILED = &HC0049014&

' //
' // MessageId: DTS_E_EXPREVALSTATIC_DIVBYZERO
' //
' // MessageText:
' //
' //  Division by zero occurred in the expression.
' //
%DTS_E_EXPREVALSTATIC_DIVBYZERO   = &HC0049030&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of a literal value overflowed the type requested.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_LITERALOVERFLOW
' //
' // MessageText:
' //
' //  The magnitude of the literal value was too big to fit in the type requested.
' //
%DTS_E_EXPREVALSTATIC_LITERALOVERFLOW = &HC0049031&

' ////////////////////////////////////////////////////////////////////////////
' // The operand types could not be implicitly cast into a numeric (DT_NUMERIC) result without loss of precision or scale. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYOPNUMERICOVERFLOW
' //
' // MessageText:
' //
' //  The result of a binary operation was too big for the maximum size for numeric types. The operand types could not be implicitly cast into a numeric (DT_NUMERIC) result without loss of precision or scale.
' //  To perform this operation, one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_BINARYOPNUMERICOVERFLOW = &HC0049032&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the result of the operation overflows the type of the result

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYOPOVERFLOW
' //
' // MessageText:
' //
' //  The magnitude of the result of a binary operation overflows the maximum size for result data type.
' //
%DTS_E_EXPREVALSTATIC_BINARYOPOVERFLOW = &HC0049033&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the result of the function call overflowed the type of the operand. An explicit cast to a larger type may be required.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FUNCTIONOVERFLOW
' //
' // MessageText:
' //
' //  The magnitude of the result of a function call was too big to fit in the result type, and overflowed the type of the operand. An explicit cast to a larger type may be required.
' //
%DTS_E_EXPREVALSTATIC_FUNCTIONOVERFLOW = &HC0049034&

' ////////////////////////////////////////////////////////////////////////////
' // The operand types could not be implicitly cast into compatible types for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYTYPEMISMATCH
' //
' // MessageText:
' //
' //  Incompatible data types were used with a binary operator. The operand types could not be implicitly cast into compatible types for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_BINARYTYPEMISMATCH = &HC0049035&

' ////////////////////////////////////////////////////////////////////////////
' // The type of one or both of the operands is not supported for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_UNSUPPORTEDBINARYTYPE
' //
' // MessageText:
' //
' //  An unsupported data type was used with a binary operator. The type of one, or both, of the operands is not supported for the operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_UNSUPPORTEDBINARYTYPE = &HC0049036&

' ////////////////////////////////////////////////////////////////////////////
' // The operands for this operator must be both positive or both negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYSIGNMISMATCH
' //
' // MessageText:
' //
' //  There is a sign mismatch for the bitwise binary operator. The operands for this operator must be both positive or both negative.
' //
%DTS_E_EXPREVALSTATIC_BINARYSIGNMISMATCH = &HC0049037&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error occurred, or out of memory.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYOPERATIONFAILED
' //
' // MessageText:
' //
' //  A binary operation failed. There was an out-of-memory condition, or an internal error occurred.
' //
%DTS_E_EXPREVALSTATIC_BINARYOPERATIONFAILED = &HC0049038&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while trying to set the result type of a binary operation.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYOPERATIONSETTYPEFAILED
' //
' // MessageText:
' //
' //  Setting the result type of a binary operation failed.
' //
%DTS_E_EXPREVALSTATIC_BINARYOPERATIONSETTYPEFAILED = &HC0049039&

' ////////////////////////////////////////////////////////////////////////////
' // Unable to compare two strings.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_STRINGCOMPARISONFAILED
' //
' // MessageText:
' //
' //  Cannot compare two strings.
' //
%DTS_E_EXPREVALSTATIC_STRINGCOMPARISONFAILED = &HC004903A&

' ////////////////////////////////////////////////////////////////////////////
' // The operand type is not supported for the operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_UNSUPPORTEDUNNARYTYPE
' //
' // MessageText:
' //
' //  An unsupported data type is used with a unary operator. The operand type is not supported for the operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_UNSUPPORTEDUNNARYTYPE = &HC004903B&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error occurred, or out of memory.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_UNARYOPERATIONFAILED
' //
' // MessageText:
' //
' //  A unary operation failed. An out-of-memory condition occurred, or there was an internal error.
' //
%DTS_E_EXPREVALSTATIC_UNARYOPERATIONFAILED = &HC004903C&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while trying to set the result type of a unary operation.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_UNARYOPERATIONSETTYPEFAILED
' //
' // MessageText:
' //
' //  Setting the result type of a unary operation failed.
' //
%DTS_E_EXPREVALSTATIC_UNARYOPERATIONSETTYPEFAILED = &HC004903D&

' ////////////////////////////////////////////////////////////////////////////
' // The type of the parameter could not be implicitly cast into a compatible type for the function. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_PARAMTYPEMISMATCH
' //
' // MessageText:
' //
' //  A function has a parameter with an unsupported data type. The type of the parameter cannot be implicitly cast into a compatible type for the function. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_PARAMTYPEMISMATCH = &HC004903E&

' ////////////////////////////////////////////////////////////////////////////
' // The function name is incorrect or does not exist.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDFUNCTION
' //
' // MessageText:
' //
' //  An invalid function name appeared in the expression. Verify that the function name is correct and does exist.
' //
%DTS_E_EXPREVALSTATIC_INVALIDFUNCTION = &HC004903F&

' ////////////////////////////////////////////////////////////////////////////
' // The length parameter cannot be negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FNSUBSTRINGINVALIDLENGTH
' //
' // MessageText:
' //
' //  The length parameter was not valid for function SUBSTRING. The length parameter cannot be negative.
' //
%DTS_E_EXPREVALSTATIC_FNSUBSTRINGINVALIDLENGTH = &HC0049040&

' ////////////////////////////////////////////////////////////////////////////
' // Start index is 1-based, not 0-based.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FNSUBSTRINGINVALIDSTARTINDEX
' //
' // MessageText:
' //
' //  The start index was not valid for function SUBSTRING. The start index value must be an integer greater than zero. The start index is 1-based, not 0-based.
' //
%DTS_E_EXPREVALSTATIC_FNSUBSTRINGINVALIDSTARTINDEX = &HC0049041&

' ////////////////////////////////////////////////////////////////////////////
' // The function name was recognized, but the number of parameters was incorrect.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNUMBEROFPARAMS
' //
' // MessageText:
' //
' //  An incorrect number of parameters was given to a function. The function name was recognized, but the number of parameters was not correct.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNUMBEROFPARAMS = &HC0049042&

' ////////////////////////////////////////////////////////////////////////////
' // The attempt to perform the character mapping failed.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CHARMAPPINGFAILED
' //
' // MessageText:
' //
' //  A character mapping function failed.
' //
%DTS_E_EXPREVALSTATIC_CHARMAPPINGFAILED = &HC0049043&

' ////////////////////////////////////////////////////////////////////////////
' // The date part specified for the function was not recognized.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDDATEPART
' //
' // MessageText:
' //
' //  An unrecognized date part parameter was specified for a date function.
' //
%DTS_E_EXPREVALSTATIC_INVALIDDATEPART = &HC0049044&

' ////////////////////////////////////////////////////////////////////////////
' // Parameters of NULL() must be static.  That is, they cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNULLPARAM
' //
' // MessageText:
' //
' //  An invalid parameter was given for function NULL. The parameters of NULL must be static, and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNULLPARAM = &HC0049045&

' ////////////////////////////////////////////////////////////////////////////
' // A parameter of NULL() must be an integer or a type that can be converted to an integer.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNULLPARAMTYPE
' //
' // MessageText:
' //
' //  An invalid parameter was given for function NULL. A parameter of NULL must be an integer, or a type that can be converted to an integer.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNULLPARAMTYPE = &HC0049046&

' ////////////////////////////////////////////////////////////////////////////
' // This parameter must be static.  That is, it cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FUNCTIONPARAMNOTSTATIC
' //
' // MessageText:
' //
' //  An invalid parameter was given for a function. This parameter must be static and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALSTATIC_FUNCTIONPARAMNOTSTATIC = &HC0049047&

' ////////////////////////////////////////////////////////////////////////////
' // Parameters of cast operators must be static.  That is, they cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCASTPARAM
' //
' // MessageText:
' //
' //  An invalid parameter was given for a cast operation. Parameters of cast operators must be static, and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCASTPARAM = &HC0049048&

' ////////////////////////////////////////////////////////////////////////////
' // A parameter of a cast operator must be an integer or a type that can be converted to an integer.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCASTPARAMTYPE
' //
' // MessageText:
' //
' //  An invalid parameter was given for a cast operation. A parameter of a cast operator must be an integer, or a type that can be converted to an integer.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCASTPARAMTYPE = &HC0049049&

' ////////////////////////////////////////////////////////////////////////////
' // The requested cast is not supported.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCAST
' //
' // MessageText:
' //
' //  The expression contained an unsupported type cast.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCAST = &HC004904A&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed because it contains invalid elements.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDTOKEN
' //
' // MessageText:
' //
' //  The expression contained a token that was not recognized. The expression could not be parsed because it contains invalid elements.
' //
%DTS_E_EXPREVALSTATIC_INVALIDTOKEN = &HC004904B&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed. It might contain invalid elements, or it might not be well-formed.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FAILEDTOPARSEEXPRESSION
' //
' // MessageText:
' //
' //  The expression is not valid and could not be parsed. It might contain invalid elements, or it might not be well-formed.
' //
%DTS_E_EXPREVALSTATIC_FAILEDTOPARSEEXPRESSION = &HC004904C&

' ////////////////////////////////////////////////////////////////////////////
' // The magnitude of the result of the operation overflows the type of the result

' //
' // MessageId: DTS_E_EXPREVALSTATIC_UNARYOPOVERFLOW
' //
' // MessageText:
' //
' //  The result of a unary minus (negation) operation overflowed the maximum size for result data type. The magnitude of the result of the operation overflows the type of the result.
' //
%DTS_E_EXPREVALSTATIC_UNARYOPOVERFLOW = &HC004904D&

' ////////////////////////////////////////////////////////////////////////////
' // Expression computation failed.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_COMPUTEFAILED
' //
' // MessageText:
' //
' //  Attempt to compute the expression failed.
' //
%DTS_E_EXPREVALSTATIC_COMPUTEFAILED = &HC004904E&

' ////////////////////////////////////////////////////////////////////////////
' // Failed when attempting to generate a displayable string that represents the expression.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BUILDSTRINGFAILED
' //
' // MessageText:
' //
' //  Attempt to generate a string representation of the expression failed.
' //
%DTS_E_EXPREVALSTATIC_BUILDSTRINGFAILED = &HC004904F&

' ////////////////////////////////////////////////////////////////////////////
' // The result of the expression should be written to an input/output column, but the data type of the expression cannot be converted to the data type of the column.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CANNOTCONVERTRESULT
' //
' // MessageText:
' //
' //  Cannot convert the expression result data type to the column data type. The result of the expression should be written to an input/output column, but the data type of the expression cannot be converted to the data type of the column.
' //
%DTS_E_EXPREVALSTATIC_CANNOTCONVERTRESULT = &HC0049050&

' ////////////////////////////////////////////////////////////////////////////
' // The conditional expression of the conditional operator must be of type DT_BOOL.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CONDITIONALOPINVALIDCONDITIONTYPE
' //
' // MessageText:
' //
' //  The conditional expression of the conditional operator has invalid data type. The conditional expression must be of type DT_BOOL.
' //
%DTS_E_EXPREVALSTATIC_CONDITIONALOPINVALIDCONDITIONTYPE = &HC0049051&

' ////////////////////////////////////////////////////////////////////////////
' // The operand types could not be implicitly cast into compatible types for the conditional operation. To perform this operation, one or both operands need to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CONDITIONALOPTYPEMISMATCH
' //
' // MessageText:
' //
' //  The data types of the operands of the conditional operator were incompatible. The operand types could not be implicitly cast into compatible types for the conditional operation. To perform this operation,
' //  one or both operands need to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_CONDITIONALOPTYPEMISMATCH = &HC0049052&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while trying to set the result type of a conditional expression.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CONDITIONALOPSETTYPEFAILED
' //
' // MessageText:
' //
' //  Setting the result type of a conditional operation failed.
' //
%DTS_E_EXPREVALSTATIC_CONDITIONALOPSETTYPEFAILED = &HC0049053&

' ////////////////////////////////////////////////////////////////////////////
' // The input column specified was not found in the input column collection.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INPUTCOLUMNNAMENOTFOUND
' //
' // MessageText:
' //
' //  The input column specified was not found in the input column collection.
' //
%DTS_E_EXPREVALSTATIC_INPUTCOLUMNNAMENOTFOUND = &HC0049054&

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INPUTCOLUMNIDNOTFOUND
' //
' // MessageText:
' //
' //  Attempt to find an input column by lineage ID failed. The input column was not found in the input column collection.
' //
%DTS_E_EXPREVALSTATIC_INPUTCOLUMNIDNOTFOUND = &HC0049055&

' ////////////////////////////////////////////////////////////////////////////
' // The input column collection has not been provided to the expression evaluator, but an input column was included in the expression.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_NOINPUTCOLUMNCOLLECTION
' //
' // MessageText:
' //
' //  The expression contains an unrecognized token that appears to be an input column reference, but the input column collection is not available to process input columns. The input column collection
' //  has not been provided to the expression evaluator, but an input column was included in the expression.
' //
%DTS_E_EXPREVALSTATIC_NOINPUTCOLUMNCOLLECTION = &HC0049056&

' ////////////////////////////////////////////////////////////////////////////
' // The variable specified was not found in the variable collection. It might not exist in the correct scope.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_VARIABLENOTFOUND
' //
' // MessageText:
' //
' //  A variable specified was not found in the collection. It might not exist in the correct scope. Verify that the variable exists and that the scope is correct.
' //
%DTS_E_EXPREVALSTATIC_VARIABLENOTFOUND = &HC0049057&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed. It may contain invalid elements, or be missing part of a required element (such as unmatched parentheses), or may not be well formed.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDTOKENSTATE
' //
' // MessageText:
' //
' //  Attempt to parse the expression failed. The expression contains an invalid or incomplete token. It may contain invalid elements, be missing part of a required element such as closing parentheses, or may not be well formed.
' //
%DTS_E_EXPREVALSTATIC_INVALIDTOKENSTATE = &HC0049058&

' ////////////////////////////////////////////////////////////////////////////
' // The specified code page is not installed on the machine.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCASTCODEPAGE
' //
' // MessageText:
' //
' //  The value specified for the code page parameter of the cast to data type DT_STR or DT_TEXT is not valid. The specified code page is not installed on the computer.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCASTCODEPAGE = &HC0049059&

' ////////////////////////////////////////////////////////////////////////////
' // The specified precision was out of range for the type cast.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCASTPRECISION
' //
' // MessageText:
' //
' //  The value specified for the precision parameter of a cast operation is out of range for the type cast.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCASTPRECISION = &HC004905A&

' ////////////////////////////////////////////////////////////////////////////
' // The specified scale was out of range for the type cast. Scale must not exceed precision and must not be negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCASTSCALE
' //
' // MessageText:
' //
' //  The value specified for the scale parameter of a cast operation is out of range for the type cast. Scale must not exceed precision and must not be negative.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCASTSCALE = &HC004905B&

' ////////////////////////////////////////////////////////////////////////////
' // The code page of the left operand does not match the code page of the right operand.  For the conditional operator of that type (probably DT_TEXT), the code pages must be the same.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CONDITIONALOPCODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  The code pages do not match in a conditional operation. The code page of the left operand does not match the code page of the right operand. For the conditional operator of that type, the code pages must be the same.
' //
%DTS_E_EXPREVALSTATIC_CONDITIONALOPCODEPAGEMISMATCH = &HC004905C&

' ////////////////////////////////////////////////////////////////////////////
' // The specified escape sequence is not supported in string literals in the expression evaluator. Hexadecimal escape sequences must be of the form \xhhhh where h is a valid hexadecimal digit.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_ILLEGALHEXESCAPEINSTRINGLITERAL
' //
' // MessageText:
' //
' //  A string literal contains an illegal hexadecimal escape sequence. The escape sequence is not supported in string literals in the expression evaluator. Hexadecimal escape sequences must be of the form \xhhhh where h is a valid hexadecimal digit.
' //
%DTS_E_EXPREVALSTATIC_ILLEGALHEXESCAPEINSTRINGLITERAL = &HC004905D&

' ////////////////////////////////////////////////////////////////////////////
' // The specified escape sequence is not supported in string literals in the expression evaluator. If the user is just trying to put a backslash in the string, "\\" will achieve that.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_ILLEGALESCAPEINSTRINGLITERAL
' //
' // MessageText:
' //
' //  The string literal contains an illegal escape sequence. The escape sequence is not supported in string literals in the expression evaluator. If a backslash is needed in the string, format it as a double backslash, "\\".
' //
%DTS_E_EXPREVALSTATIC_ILLEGALESCAPEINSTRINGLITERAL = &HC004905E&

' ////////////////////////////////////////////////////////////////////////////
' // The specified type is not supported or was not recognized.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_UNSUPPORTEDTYPE
' //
' // MessageText:
' //
' //  An unsupported or unrecognized data type was used in the expression.
' //
%DTS_E_EXPREVALSTATIC_UNSUPPORTEDTYPE = &HC004905F&

' ////////////////////////////////////////////////////////////////////////////
' // The source type was too large to fit in the destination type.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_DATACONVERSIONOVERFLOW
' //
' // MessageText:
' //
' //  An overflow occurred while converting between data types. The source type is too large to fit in the destination type.
' //
%DTS_E_EXPREVALSTATIC_DATACONVERSIONOVERFLOW = &HC0049060&

' ////////////////////////////////////////////////////////////////////////////
' // The source type could not be converted to the destination type.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_DATACONVERSIONNOTSUPPORTED
' //
' // MessageText:
' //
' //  The expression contains an unsupported data type conversion. The source type cannot be converted to the destination type.
' //
%DTS_E_EXPREVALSTATIC_DATACONVERSIONNOTSUPPORTED = &HC0049061&

' //
' // MessageId: DTS_E_EXPREVALSTATIC_DATACONVERSIONFAILED
' //
' // MessageText:
' //
' //  An error occurred while attempting to perform data conversion. The source type could not be converted to the destination type.
' //
%DTS_E_EXPREVALSTATIC_DATACONVERSIONFAILED = &HC0049062&

' ////////////////////////////////////////////////////////////////////////////
' // An internal error occurred, or out of memory.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CONDITIONALOPERATIONFAILED
' //
' // MessageText:
' //
' //  The conditional operation failed.
' //
%DTS_E_EXPREVALSTATIC_CONDITIONALOPERATIONFAILED = &HC0049063&

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CASTFAILED
' //
' // MessageText:
' //
' //  An error occurred while attempting to perform a type cast.
' //
%DTS_E_EXPREVALSTATIC_CASTFAILED  = &HC0049064&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while attempting to perform the implicit conversion on the input column.

' //
' // MessageId: DTS_E_EXPREVALFAILEDTOCONVERTSTRCOLUMNTOWSTR
' //
' // MessageText:
' //
' //  Converting "%1!s!" from type DT_STR to type DT_WSTR failed with error code 0x%2!8.8X!. An error occurred while performing the implicit conversion on the input column.
' //
%DTS_E_EXPREVALFAILEDTOCONVERTSTRCOLUMNTOWSTR = &HC0049065&

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FAILEDTOCONVERTSTRCOLUMNTOWSTR
' //
' // MessageText:
' //
' //  Converting an input column from type DT_STR to type DT_WSTR failed. An error occurred while performing the  implicit conversion on the input column.
' //
%DTS_E_EXPREVALSTATIC_FAILEDTOCONVERTSTRCOLUMNTOWSTR = &HC0049066&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while attempting to evaluate the function.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FUNCTIONCOMPUTEFAILED
' //
' // MessageText:
' //
' //  An error occurred while evaluating the function.
' //
%DTS_E_EXPREVALSTATIC_FUNCTIONCOMPUTEFAILED = &HC0049067&

' ////////////////////////////////////////////////////////////////////////////
' // The parameter could not be converted into a static value (typically, an integer). The parameter must be static.  That is, it cannot contain dynamic elements such as input columns.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FUNCTIONCONVERTPARAMTOMEMBERFAILED
' //
' // MessageText:
' //
' //  A function parameter cannot be converted to a static value. The parameter must be static and cannot contain dynamic elements such as input columns.
' //
%DTS_E_EXPREVALSTATIC_FUNCTIONCONVERTPARAMTOMEMBERFAILED = &HC0049068&

' ////////////////////////////////////////////////////////////////////////////
' // The length parameter cannot be negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FNRIGHTINVALIDLENGTH
' //
' // MessageText:
' //
' //  The length parameter is not valid for function RIGHT. The length parameter cannot be negative.
' //
%DTS_E_EXPREVALSTATIC_FNRIGHTINVALIDLENGTH = &HC0049088&

' ////////////////////////////////////////////////////////////////////////////
' // The repeat count parameter cannot be negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FNREPLICATEINVALIDREPEATCOUNT
' //
' // MessageText:
' //
' //  The repeat count parameter is not valid for function REPLICATE. This parameter cannot be negative.
' //
%DTS_E_EXPREVALSTATIC_FNREPLICATEINVALIDREPEATCOUNT = &HC0049089&

' ////////////////////////////////////////////////////////////////////////////
' // The code page of the left operand does not match the code page of the right operand.  For this binary operation, the code pages must be the same.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYOPERATORCODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  The code pages do not match in a binary operation. The code page of the left operand does not match the code page of the right operand. For this binary operation, the code pages must be the same.
' //
%DTS_E_EXPREVALSTATIC_BINARYOPERATORCODEPAGEMISMATCH = &HC0049096&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred while attempting to get the value of the variable.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_VARIABLECOMPUTEFAILED
' //
' // MessageText:
' //
' //  Retrieving the value for a variable failed.
' //
%DTS_E_EXPREVALSTATIC_VARIABLECOMPUTEFAILED = &HC0049097&

' ////////////////////////////////////////////////////////////////////////////
' // The variable is of an unsupported type.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_VARIABLETYPENOTSUPPORTED
' //
' // MessageText:
' //
' //  The expression contains a variable with an unsupported data type.
' //
%DTS_E_EXPREVALSTATIC_VARIABLETYPENOTSUPPORTED = &HC0049098&

' ////////////////////////////////////////////////////////////////////////////
' // The code page of the source must match the code page requested for the destination.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CASTCODEPAGEMISMATCH
' //
' // MessageText:
' //
' //  Unable to cast the expression because the code page of the value being cast does not match the requested result code page. The code page of the source must match the code page requested for the destination.
' //
%DTS_E_EXPREVALSTATIC_CASTCODEPAGEMISMATCH = &HC004909B&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed because it contains invalid elements (a single quoation mark) at the location specified. A double quotation mark might be required there.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDTOKENSINGLEQUOTE
' //
' // MessageText:
' //
' //  The expression contains an unexpected single quotation mark. A double quotation mark may be required.
' //
%DTS_E_EXPREVALSTATIC_INVALIDTOKENSINGLEQUOTE = &HC004909C&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could not be parsed because it contains invalid elements (a single equal sign) at the location specified. A double equals might be required there.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDTOKENSINGLEEQUAL
' //
' // MessageText:
' //
' //  The expression contains an unexpected equal sign (=). This error usually occurs when a double equals sign (==) is needed.
' //
%DTS_E_EXPREVALSTATIC_INVALIDTOKENSINGLEEQUAL = &HC004909D&

' ////////////////////////////////////////////////////////////////////////////
' // The input column specified exists on more than one component.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_AMBIGUOUSINPUTCOLUMNNAME
' //
' // MessageText:
' //
' //  An ambiguous input column name was specified.  The column must be qualified as [Component Name].[Column Name] or referenced by lineage ID. This error occurs when the input column exists
' //  on more than one component, and must be differentiated by the addition of component name or by using the lineage ID.
' //
%DTS_E_EXPREVALSTATIC_AMBIGUOUSINPUTCOLUMNNAME = &HC00490AA&

' ////////////////////////////////////////////////////////////////////////////
' // A placeholder function parameter or operand was found in the expression.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_PLACEHOLDERINEXPRESSION
' //
' // MessageText:
' //
' //  A placeholder function parameter or operand was found in an expression. This should be replaced with an actual parameter or operand.
' //
%DTS_E_EXPREVALSTATIC_PLACEHOLDERINEXPRESSION = &HC00490AB&

' ////////////////////////////////////////////////////////////////////////////
' // The variable specified exists in more than one namespace.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_AMBIGUOUSVARIABLENNAME
' //
' // MessageText:
' //
' //  An ambiguous variable name was specifed. The desired variable must be qualifed as @[Namespace::Variable]. This error occurs when the variable exists in more than one namespace.
' //
%DTS_E_EXPREVALSTATIC_AMBIGUOUSVARIABLENNAME = &HC00490AC&

' ////////////////////////////////////////////////////////////////////////////
' // A DT_STR operand that is not an input column or the result of a cast cannot be used with a binary operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_BINARYOPDTSTRNOTSUPPORTED
' //
' // MessageText:
' //
' //  For operands of binary operation, the data type DT_STR is only supported for input columns and cast operations. A DT_STR operand that is not an input column or the result of a cast cannot be used with
' //  a binary operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_BINARYOPDTSTRNOTSUPPORTED = &HC00490D3&

' ////////////////////////////////////////////////////////////////////////////
' // A DT_STR operand that is not an input column or the result of a cast cannot be used with the conditional operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_CONDITIONALOPDTSTRNOTSUPPORTED
' //
' // MessageText:
' //
' //  For operands of the conditional operator, the data type DT_STR is only supported for input columns and cast operations. A DT_STR operand that is not an input column or the result of a cast
' //  cannot be used with the conditional operation. To perform this operation, the operand needs to be explicitly cast with a cast operator.
' //
%DTS_E_EXPREVALSTATIC_CONDITIONALOPDTSTRNOTSUPPORTED = &HC00490D4&

' ////////////////////////////////////////////////////////////////////////////
' // The occurrence count parameter must be positive.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_FNFINDSTRINGINVALIDOCCURRENCECOUNT
' //
' // MessageText:
' //
' //  The occurrence count parameter is not valid for function FINDSTRING. This parameter must be greater than zero.
' //
%DTS_E_EXPREVALSTATIC_FNFINDSTRINGINVALIDOCCURRENCECOUNT = &HC00490D5&

' ////////////////////////////////////////////////////////////////////////////
' // Date part parameters must be static strings.  That is, they cannot contain dynamic elements such as input columns, and must be of type DT_WSTR.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDDATEPARTNODE
' //
' // MessageText:
' //
' //  The "date part" parameter specified for a date function is not valid. "Date part" parameters must be static strings, and cannot contain dynamic elements such as input columns. They must be of type DT_WSTR.
' //
%DTS_E_EXPREVALSTATIC_INVALIDDATEPARTNODE = &HC00490DD&

' ////////////////////////////////////////////////////////////////////////////
' // The specified length for the type cast is negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDCASTLENGTH
' //
' // MessageText:
' //
' //  The value specified for the length parameter of a cast operation is not valid. The length must be positive. The length specified for the type cast is negative. Change to a positive value.
' //
%DTS_E_EXPREVALSTATIC_INVALIDCASTLENGTH = &HC00490DE&

' ////////////////////////////////////////////////////////////////////////////
' // The specified length for the NULL function is negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNULLLENGTH
' //
' // MessageText:
' //
' //  The value specified for the length parameter of a NULL function is not valid. The length must be positive. The length specified for the NULL function is negative. Change to a positive value.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNULLLENGTH = &HC00490DF&

' ////////////////////////////////////////////////////////////////////////////
' // The specified code page is not installed on the machine.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNULLCODEPAGE
' //
' // MessageText:
' //
' //  The value specified for the code page parameter of the NULL function with data type DT_STR or DT_TEXT is not valid. The code page specified is not installed on the computer. Either change the
' //  code page that is specified, or install the code page on the computer.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNULLCODEPAGE = &HC00490E0&

' ////////////////////////////////////////////////////////////////////////////
' // The specified precision was out of range for the NULL function.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNULLPRECISION
' //
' // MessageText:
' //
' //  The value specified for the precision parameter of a NULL function is not valid. The precision that was specified is out of range for the NULL function.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNULLPRECISION = &HC00490E1&

' ////////////////////////////////////////////////////////////////////////////
' // The specified scale was out of range for the NULL function. Scale must not exceed precision and must not be negative.

' //
' // MessageId: DTS_E_EXPREVALSTATIC_INVALIDNULLSCALE
' //
' // MessageText:
' //
' //  The value specified for the scale parameter of a NULL function is not valid. The scale that was specified is out of range for the NULL function. Scale must not exceed precision and must be positive.
' //
%DTS_E_EXPREVALSTATIC_INVALIDNULLSCALE = &HC00490E2&

' //
' // MessageId: DTS_E_TXLOOKUP_CANCEL_REQUESTED
' //
' // MessageText:
' //
' //  Lookup transform has received a cancel request from the user.
' //
%DTS_E_TXLOOKUP_CANCEL_REQUESTED  = &HC00490F5&

' //
' // MessageId: DTS_I_EXECUTIONPHASE_PREPAREFOREXECUTE
' //
' // MessageText:
' //
' //  Prepare for Execute phase is beginning.
' //
%DTS_I_EXECUTIONPHASE_PREPAREFOREXECUTE = &H40043006&

' //
' // MessageId: DTS_I_EXECUTIONPHASE_PREEXECUTE
' //
' // MessageText:
' //
' //  Pre-Execute phase is beginning.
' //
%DTS_I_EXECUTIONPHASE_PREEXECUTE  = &H40043007&

' //
' // MessageId: DTS_I_EXECUTIONPHASE_POSTEXECUTE
' //
' // MessageText:
' //
' //  Post Execute phase is beginning.
' //
%DTS_I_EXECUTIONPHASE_POSTEXECUTE = &H40043008&

' //
' // MessageId: DTS_I_EXECUTIONPHASE_CLEANUP
' //
' // MessageText:
' //
' //  Cleanup phase is beginning.
' //
%DTS_I_EXECUTIONPHASE_CLEANUP     = &H40043009&

' //
' // MessageId: DTS_I_EXECUTIONPHASE_VALIDATE
' //
' // MessageText:
' //
' //  Validation phase is beginning.
' //
%DTS_I_EXECUTIONPHASE_VALIDATE    = &H4004300A&

' //
' // MessageId: DTS_I_ROWS_WRITTEN
' //
' // MessageText:
' //
' //  "%1!s!" wrote %2!ld! rows.
' //
%DTS_I_ROWS_WRITTEN               = &H4004300B&

' //
' // MessageId: DTS_I_EXECUTIONPHASE_EXECUTE
' //
' // MessageText:
' //
' //  Execute phase is beginning.
' //
%DTS_I_EXECUTIONPHASE_EXECUTE     = &H4004300C&

' ////////////////////////////////////////////////////////////////////////////
' // Either not enough memory is available to the pipeline (either not enough installed, or some other process is using it), or too many buffers are locked.

' //
' // MessageId: DTS_I_CANTRELIEVEPRESSURE
' //
' // MessageText:
' //
' //  The buffer manager detected that the system was low on virtual memory, but was unable to swap out any buffers. %1!d! buffers were considered and %2!d! were locked. Either not enough memory is available
' //  to the pipeline because not enough is installed, other processes are using it, or too many buffers are locked.
' //
%DTS_I_CANTRELIEVEPRESSURE        = &H4004800C&

' //
' // MessageId: DTS_I_CANTALLOCATEMEMORYPRESSURE
' //
' // MessageText:
' //
' //  The buffer manager failed a memory allocation call for %3!d! bytes, but was unable to swap out any buffers to relieve memory pressure. %1!d! buffers were considered and %2!d! were locked. Either not enough
' //  memory is available to the pipeline because not enough are installed, other processes were using it, or too many buffers are locked.
' //
%DTS_I_CANTALLOCATEMEMORYPRESSURE = &H4004800D&

' //
' // MessageId: DTS_I_TXLOOKUP_CACHE_PROGRESS
' //
' // MessageText:
' //
' //  %1!s! has cached %2!d! rows.
' //
%DTS_I_TXLOOKUP_CACHE_PROGRESS    = &H400490F4&

' //
' // MessageId: DTS_S_NULLDATA
' //
' // MessageText:
' //
' //  The value is NULL.
' //
%DTS_S_NULLDATA                   = &H00040003&

' ////////////////////////////////////////////////////////////////////////////
' // Somebody gave the buffer a string that was too long for the column in the buffer, and the buffer truncated it.

' //
' // MessageId: DTS_S_TRUNCATED
' //
' // MessageText:
' //
' //  The string value was truncated. The buffer received a string that was too long for the column, and the string was truncated by the buffer.
' //
%DTS_S_TRUNCATED                  = &H00040005&

' //
' // MessageId: DTS_W_NOLINEAGEVALIDATION
' //
' // MessageText:
' //
' //  The lineage IDs of the input columns cannot be validated because the execution trees contain cycles.
' //
%DTS_W_NOLINEAGEVALIDATION        = &H80047007&

' ////////////////////////////////////////////////////////////////////////////
' // Add some components or remove the task.

' //
' // MessageId: DTS_W_EMPTYDATAFLOW
' //
' // MessageText:
' //
' //  The DataFlow task has no components. Add components or remove the task.
' //
%DTS_W_EMPTYDATAFLOW              = &H80047034&

' //
' // MessageId: DTS_W_SORTEDOUTPUTHASNOSORTKEYPOSITIONS
' //
' // MessageText:
' //
' //  The IsSorted property of %1!s! is set to TRUE, but all of its output columns' SortKeyPositions are set to zero.
' //
%DTS_W_SORTEDOUTPUTHASNOSORTKEYPOSITIONS = &H80047069&

' //
' // MessageId: DTS_W_SOURCEREMOVED
' //
' // MessageText:
' //
' //  Source "%1!s!" (%2!d!) will not be read because none of its data ever becomes visible outside the Data Flow Task.
' //
%DTS_W_SOURCEREMOVED              = &H8004706F&

' //
' // MessageId: DTS_W_UNUSEDOUTPUTDATA
' //
' // MessageText:
' //
' //  The output column "%1!s!" (%2!d!) on output "%3!s!" (%4!d!) and component "%5!s!" (%6!d!) is not subsequently used in the Data Flow task. Removing this unused output column can increase Data Flow task performance.
' //
%DTS_W_UNUSEDOUTPUTDATA           = &H80047076&

' ////////////////////////////////////////////////////////////////////////////
' // If the component is required, then HasSideEffects on at least one of its inputs should be set to true, or its output should be connected to something.

' //
' // MessageId: DTS_W_COMPONENTREMOVED
' //
' // MessageText:
' //
' //  Component "%1!s!" (%2!d!) has been removed from the Data Flow task because its output is not used and its inputs have no side effects. If the component is required, then the HasSideEffects property on at least
' //  one of its inputs should be set to true, or its output should be connected to something.
' //
%DTS_W_COMPONENTREMOVED           = &H800470AE&

' ////////////////////////////////////////////////////////////////////////////
' // Running the pipeline with RunInOptimizedMode set to TRUE will be faster, and will relieve this warning.

' //
' // MessageId: DTS_W_NOWORKTODO
' //
' // MessageText:
' //
' //  Rows were given to a thread, but that thread has no work to do. The layout has a disconnected output. Running the pipeline with the RunInOptimizedMode property set to TRUE will be faster, and prevents this warning.
' //
%DTS_W_NOWORKTODO                 = &H800470B0&

' //
' // MessageId: DTS_W_EXTERNALMETADATACOLUMNSOUTOFSYNC
' //
' // MessageText:
' //
' //  The external metadata column collection is out of synchronization with the data source columns. %1!s!
' //
%DTS_W_EXTERNALMETADATACOLUMNSOUTOFSYNC = &H800470C8&

' //
' // MessageId: DTS_W_EXTERNALMETADATACOLUMNCOLLECTIONNEEDSADDITION
' //
' // MessageText:
' //
' //  The column "%1!s!" needs to be added to the external metadata column collection.
' //
%DTS_W_EXTERNALMETADATACOLUMNCOLLECTIONNEEDSADDITION = &H800470C9&

' //
' // MessageId: DTS_W_EXTERNALMETADATACOLUMNCOLLECTIONNEEDSUPDATE
' //
' // MessageText:
' //
' //  The column "%1!s!" needs to be updated in the external metadata column collection.
' //
%DTS_W_EXTERNALMETADATACOLUMNCOLLECTIONNEEDSUPDATE = &H800470CA&

' //
' // MessageId: DTS_W_EXTERNALMETADATACOLUMNCOLLECTIONNEEDSREMOVAL
' //
' // MessageText:
' //
' //  The "%1!s!" needs to be removed from the external metadata column collection.
' //
%DTS_W_EXTERNALMETADATACOLUMNCOLLECTIONNEEDSREMOVAL = &H800470CB&

' ////////////////////////////////////////////////////////////////////////////
' // The expression could potentially have a result value that exceeds the maximum size of a DT_WSTR.

' //
' // MessageId: DTS_W_EXPREVALPOTENTIALSTRINGTRUNCATION
' //
' // MessageText:
' //
' //  The result string for expression "%1!s!" may be truncated if it exceeds the maximum length of %2!d! characters. The expression could have a result value that exceeds the maximum size of a DT_WSTR.
' //
%DTS_W_EXPREVALPOTENTIALSTRINGTRUNCATION = &H800470D8&

' ////////////////////////////////////////////////////////////////////////////
' // The component is keeping references to buffers it shouldn't. If it needs to keep the buffer, it should make a copy of the buffer for itself by calling the Clone method.

' //
' // MessageId: DTS_W_COMPONENTLEAKPROCESSINPUT
' //
' // MessageText:
' //
' //  A call to the ProcessInput method for input %1!d! on %2!s! unexpectedly kept a reference to the buffer it was passed. The refcount on that buffer was %3!d! before the call, and %4!d! after the call returned.
' //
%DTS_W_COMPONENTLEAKPROCESSINPUT  = &H800470E9&

' ////////////////////////////////////////////////////////////////////////////
' // The specified input column does not appear in any expression.

' //
' // MessageId: DTS_W_EXPREVALUNREFERENCEDINPUTCOLUMN
' //
' // MessageText:
' //
' //  The "%1!s!" on "%2!s!" has usage type READONLY, but is not referenced by an expression. Remove the column from the list of available input columns, or reference it in an expression.
' //
%DTS_W_EXPREVALUNREFERENCEDINPUTCOLUMN = &H800470EB&

' ////////////////////////////////////////////////////////////////////////////
' // Could not find the CurrentVersion value for component {c200e360-38c5-11ce-ae62-08002b2b79ef}.

' //
' // MessageId: DTS_W_COULDNOTFINDCURRENTVERSION
' //
' // MessageText:
' //
' //  Cannot find the "%1!s!" value for component %2!s!. The CurrentVersion value for the component cannot be located. This error occurs if the component has not set its registry information
' //  to contain a CurrentVersion value in the DTSInfo section. This message occurs during component development, or when the component is used in a package, if the component is not registered properly.
' //
%DTS_W_COULDNOTFINDCURRENTVERSION = &H8004801E&

' ////////////////////////////////////////////////////////////////////////////
' // The user should never get this.  This is a bug.  It is returned when a variable should have had a valid value but doesn't

' //
' // MessageId: DTS_E_NOTINITIALIZED
' //
' // MessageText:
' //
' //  An internal object or variable was not initialized. This is an internal product error.  This error is returned when a variable should have a valid value but does not.
' //
%DTS_E_NOTINITIALIZED             = &HC0000032&

' //
' // MessageId: DTS_E_EXPIRED
' //
' // MessageText:
' //
' //  Data Transformation Services evaluation period has expired.
' //
%DTS_E_EXPIRED                    = &HC0000033&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when user assigns a negative value to a property that should be only positivie like count properties.

' //
' // MessageId: DTS_E_NEGATIVEVALUESNOTALLOWED
' //
' // MessageText:
' //
' //  This property cannot be assigned a negative value. This error occurs when a negative value is assigned to a property that can only contain positive values, such as the COUNT property.
' //
%DTS_E_NEGATIVEVALUESNOTALLOWED   = &HC0000034&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when user uses a negative value as an index to a collection.

' //
' // MessageId: DTS_E_NEGATIVEINDEXNOTALLOWED
' //
' // MessageText:
' //
' //  Indexes cannot be negative. This error occurs when a negative value is used as an index to a collection.
' //
%DTS_E_NEGATIVEINDEXNOTALLOWED    = &HC0000035&

' ////////////////////////////////////////////////////////////////////////////
' // The user specified the server name which contains invalid characters, usually slash (we don't support multiinstancing, so slash is not allowed)

' //
' // MessageId: DTS_E_INVALIDSSISSERVERNAME
' //
' // MessageText:
' //
' //  Invalid server name "%1!s!". SSIS service does not support multi-instance, use just server name instead of "server name\instance".
' //
%DTS_E_INVALIDSSISSERVERNAME      = &HC00060AB&

' //
' // MessageId: DTS_MSG_CATEGORY_SERVICE_CONTROL
' //
' // MessageText:
' //
' //  Service Control
' //
%DTS_MSG_CATEGORY_SERVICE_CONTROL = &H00000001&

' //
' // MessageId: DTS_MSG_CATEGORY_RUNNING_PACKAGE_MANAGEMENT
' //
' // MessageText:
' //
' //  Running Package Management
' //
%DTS_MSG_CATEGORY_RUNNING_PACKAGE_MANAGEMENT = &H00000002&

' //
' // MessageId: DTS_MSG_SERVER_STARTING
' //
' // MessageText:
' //
' //  Starting Microsoft SSIS Service.%nServer version %1
' //
%DTS_MSG_SERVER_STARTING          = &H00000100&

' //
' // MessageId: DTS_MSG_SERVER_STARTED
' //
' // MessageText:
' //
' //  Microsoft SSIS Service started.%nServer version %1
' //
%DTS_MSG_SERVER_STARTED           = &H00000101&

' //
' // MessageId: DTS_MSG_SERVER_STOPPING
' //
' // MessageText:
' //
' //  Stopping Microsoft SSIS Service.%n%nStop all running packages on exit: %1
' //
%DTS_MSG_SERVER_STOPPING          = &H00000102&

' //
' // MessageId: DTS_MSG_SERVER_STOPPED
' //
' // MessageText:
' //
' //  Microsoft SSIS Service stopped.%nServer version %1
' //
%DTS_MSG_SERVER_STOPPED           = &H00000103&

' //
' // MessageId: DTS_MSG_SERVER_START_FAILED
' //
' // MessageText:
' //
' //  Microsoft SSIS Service failed to start.%nError: %1
' //
%DTS_MSG_SERVER_START_FAILED      = &H00000104&

' //
' // MessageId: DTS_MSG_SERVER_STOP_ERROR
' //
' // MessageText:
' //
' //  Error stopping Microsoft SSIS Service.%nError: %1
' //
%DTS_MSG_SERVER_STOP_ERROR        = &H00000105&

' //
' // MessageId: DTS_MSG_SERVER_MISSING_CONFIG
' //
' // MessageText:
' //
' //  Microsoft SSIS Service configuration file does not exist.%nLoading with default settings.
' //
%DTS_MSG_SERVER_MISSING_CONFIG    = &H00000110&

' //
' // MessageId: DTS_MSG_SERVER_BAD_CONFIG
' //
' // MessageText:
' //
' //  Microsoft SSIS Service configuration file is incorrect.%nError reading config file: %1%n%nLoading server with default settings.
' //
%DTS_MSG_SERVER_BAD_CONFIG        = &H00000111&

' //
' // MessageId: DTS_MSG_SERVER_MISSING_CONFIG_REG
' //
' // MessageText:
' //
' //  Microsoft SSIS Service: %nRegistry setting specifying configuration file does not exist. %nAttempting to load default config file.
' //
%DTS_MSG_SERVER_MISSING_CONFIG_REG = &H00000112&

' //
' // MessageId: DTS_MSG_SERVER_STOPPING_PACKAGE
' //
' // MessageText:
' //
' //  Microsoft SSIS Service: stopping running package.%nPackage instance ID: %1%nPackage ID: %2%nPackage name: %3%nPackage description: %4%nPackage started by: %5.
' //
%DTS_MSG_SERVER_STOPPING_PACKAGE  = &H00000150&

' //
' // MessageId: DTS_W_COUNTDOWN
' //
' // MessageText:
' //
' //  There are %1!lu! days left in the evaluation. When it expires, packages will not be able to be executed.
' //
%DTS_W_COUNTDOWN                  = &H80000036&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client tries to retrieve a variable from a variables collection on a container during execution of the package and the variable isn't there.  A variable name may have changed,
' // or the client may think that a variable is getting created and it isn't.

' //
' // MessageId: DTS_E_VARIABLENOTFOUND
' //
' // MessageText:
' //
' //  The variable cannot be found. This occurs when an attempt is made to retrieve a variable from the Variables collection on a container during execution of the package, and the variable is not there.
' //  The variable name may have changed or the variable is not being created.
' //
%DTS_E_VARIABLENOTFOUND           = &HC0010001&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client calls put_Value on a read only variable.

' //
' // MessageId: DTS_E_VARIABLEREADONLY
' //
' // MessageText:
' //
' //  Error trying to write to a read-only variable, "%1".
' //
%DTS_E_VARIABLEREADONLY           = &HC0010003&

' ////////////////////////////////////////////////////////////////////////////
' // Check integrity of your installation.

' //
' // MessageId: DTS_E_MANAGEDCOMPONENTSTORENOTFOUND
' //
' // MessageText:
' //
' //  Unable to find the directories containing Tasks and Data Flow Task components. Check the integrity of your installation.
' //
%DTS_E_MANAGEDCOMPONENTSTORENOTFOUND = &HC0010004&

' ////////////////////////////////////////////////////////////////////////////
' // Try shortening the package name.

' //
' // MessageId: DTS_E_PACKAGENAMETOOLONG
' //
' // MessageText:
' //
' //  Package name is too long. The limit is 128 characters. Shorten the package name.
' //
%DTS_E_PACKAGENAMETOOLONG         = &HC0010006&

' ////////////////////////////////////////////////////////////////////////////
' // Try shortening the package description.

' //
' // MessageId: DTS_E_PACKAGEDESCRIPTIONTOOLONG
' //
' // MessageText:
' //
' //  Package description is too long.The limit is 1024 characters. Shorten the package description.
' //
%DTS_E_PACKAGEDESCRIPTIONTOOLONG  = &HC0010007&

' ////////////////////////////////////////////////////////////////////////////
' // Try shortening the value of VersionComments.

' //
' // MessageId: DTS_E_VERCOMMENTSTOOLONG
' //
' // MessageText:
' //
' //  VersionComments property is too long. The limit is 1024 characters. Try shortening the VersionComments.
' //
%DTS_E_VERCOMMENTSTOOLONG         = &HC0010008&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client tries to retrieve an element from a collection on a container during execution of the package and the element isn't there.

' //
' // MessageId: DTS_E_ELEMENTNOTFOUND
' //
' // MessageText:
' //
' //  The element cannot be found in a collection. This error happens when you try to retrieve an element from a collection on a container during execution of the package and the element is not there.
' //
%DTS_E_ELEMENTNOTFOUND            = &HC0010009&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client tries to load a package from a SQL Server and that package does not exist or the database is in an older version database.

' //
' // MessageId: DTS_E_PACKAGENOTFOUND
' //
' // MessageText:
' //
' //  The specified package could not be loaded from the SQL Server database.
' //
%DTS_E_PACKAGENOTFOUND            = &HC001000A&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client or a task assigned a runtime object to a variable value.

' //
' // MessageId: DTS_E_INVALIDVARIABLEVALUE
' //
' // MessageText:
' //
' //  The variable value assignment is not valid. This error happens when the client or a task assigns a runtime object to a variable value.
' //
%DTS_E_INVALIDVARIABLEVALUE       = &HC001000C&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client or a task trys to create a variable with a namespace of "System".

' //
' // MessageId: DTS_E_RESERVEDNAMESPACE
' //
' // MessageText:
' //
' //  Error assigning namespace to the variable. The namespace "System" is reserved for system use. This error happens when a component or task attempts to create a variable with a namespace of "System".
' //
%DTS_E_RESERVEDNAMESPACE          = &HC001000D&

' ////////////////////////////////////////////////////////////////////////////
' // This error is posted by Connections collection when an element is not found.

' //
' // MessageId: DTS_E_CONNECTIONNOTFOUND
' //
' // MessageText:
' //
' //  The connection "%1!s!" is not found. This error is thrown by Connections collection when the specific connection element is not found.
' //
%DTS_E_CONNECTIONNOTFOUND         = &HC001000E&

' ////////////////////////////////////////////////////////////////////////////
' // Variables of type VT_I8 and VT_UI8 are not supported on W2K.

' //
' // MessageId: DTS_E_64BITVARIABLERECAST
' //
' // MessageText:
' //
' //  The variable "%1!s!" is a 64-bit integer variable, which is not supported on this operating system.The variable has been recast to 32-bit integer. Variables of type VT_I8 and VT_UI8 are not supported on Microsoft Windows 2000.
' //
%DTS_E_64BITVARIABLERECAST        = &HC001000F&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when a variable's readonly attribute is being changed at runtime.

' //
' // MessageId: DTS_E_CANTCHANGEREADONLYATRUNTIME
' //
' // MessageText:
' //
' //  An attempt change to a read-only attribute on variable "%1" occurred. This error happens when a read-only attribute for a variable is being changed at runtime. Read-only attributes can be changed only at design time.
' //
%DTS_E_CANTCHANGEREADONLYATRUNTIME = &HC0010010&

' ////////////////////////////////////////////////////////////////////////////
' // Variables are not allows to reference containers.

' //
' // MessageId: DTS_E_VARIABLEINVALIDCONTAINERREF
' //
' // MessageText:
' //
' //  Invalid attempt to set a variable to a container reference.  Variables are not allowed to reference containers.
' //
%DTS_E_VARIABLEINVALIDCONTAINERREF = &HC0010011&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when a variable value is not allowed for variables.

' //
' // MessageId: DTS_E_INVALIDVARVALUE
' //
' // MessageText:
' //
' //  Assigning invalid value or object to variable "%1!s!". This error happens when a value is not appropriate for variables.
' //
%DTS_E_INVALIDVARVALUE            = &HC0010013&

' ////////////////////////////////////////////////////////////////////////////
' // This is used as a return value from functions that encountered errors

' //
' // MessageId: DTS_E_GENERICERROR
' //
' // MessageText:
' //
' //  One or more error occurred. There should be more specific errors preceding this one that explains the details of the errors. This message is used as a return value from functions that encounter errors.
' //
%DTS_E_GENERICERROR               = &HC0010014&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when unpersisting an array into a vriable.

' //
' // MessageId: DTS_E_INVALIDARRAYVALUE
' //
' // MessageText:
' //
' //  Error getting or setting an array value. The type "%1!s!" is not allowed. This occurs when loading an array into a variable.
' //
%DTS_E_INVALIDARRAYVALUE          = &HC0010016&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when persisting an array of unspported types into a vriable.

' //
' // MessageId: DTS_E_UNSUPPORTEDARRAYTYPE
' //
' // MessageText:
' //
' //  Unsupported type in array. This happens when saving an array of unsupported types into a variable.
' //
%DTS_E_UNSUPPORTEDARRAYTYPE       = &HC0010017&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when persistence fails.

' //
' // MessageId: DTS_E_PERSISTENCEERROR
' //
' // MessageText:
' //
' //  Error loading value "%1!s!" from node "%2!s!".
' //
%DTS_E_PERSISTENCEERROR           = &HC0010018&

' //
' // MessageId: DTS_E_INVALIDNODE
' //
' // MessageText:
' //
' //  Node "%1!s!" is not a valid node. This happens when saving fails.
' //
%DTS_E_INVALIDNODE                = &HC0010019&

' //
' // MessageId: DTS_E_ERRORLOADINGTASK
' //
' // MessageText:
' //
' //  Error loading a task. The contact information for the task is "%1!s!". This happens when loading a task fails.
' //
%DTS_E_ERRORLOADINGTASK           = &HC0010020&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when referring to nonexistent element in collection.

' //
' // MessageId: DTS_E_ERRORELEMENTNOTINCOLL
' //
' // MessageText:
' //
' //  Element "%1!s!" does not exist in collection "%2!s!".
' //
%DTS_E_ERRORELEMENTNOTINCOLL      = &HC0010021&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when we get bad XML.

' //
' // MessageId: DTS_E_MISSINGOBJECTDATA
' //
' // MessageText:
' //
' //  The ObjectData element is missing in the XML block of a hosted object. This occurs when the XML parser attempts to locate the data element for an object and it cannot be found.
' //
%DTS_E_MISSINGOBJECTDATA          = &HC0010022&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client tries to retrieve a variable from a variables collection on a container during execution of the package and the variable isn't there.  A variable name may have changed,
' // or the client may think that a variable is getting created and it isn't.

' //
' // MessageId: DTS_E_VARIABLENOTFOUNDINCOLL
' //
' // MessageText:
' //
' //  The variable "%1!s!" cannot be found. This error occurs when an attempt to retrieve a variable from a variables collection on a container during execution of the package occurs, and the variable is not there.
' //  A variable name may have changed or the variable is not being created.
' //
%DTS_E_VARIABLENOTFOUNDINCOLL     = &HC0010023&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when there are empty task hosts.

' //
' // MessageId: DTS_E_HASEMPTYTASKHOSTS
' //
' // MessageText:
' //
' //  The package cannot execute because it contains tasks that failed to load.
' //
%DTS_E_HASEMPTYTASKHOSTS          = &HC0010025&

' ////////////////////////////////////////////////////////////////////////////
' // An empty task is put in place of a task that failed to load.

' //
' // MessageId: DTS_E_TASKISEMPTY
' //
' // MessageText:
' //
' //  The task has failed to load. The contact information for this task is "%1!s!".
' //
%DTS_E_TASKISEMPTY                = &HC0010026&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when persistence fails.

' //
' // MessageId: DTS_E_ERRORLOADINGTASKNOCONTACT
' //
' // MessageText:
' //
' //  Error loading task "%1!s!".
' //
%DTS_E_ERRORLOADINGTASKNOCONTACT  = &HC0010027&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when loading a task from xml fails.

' //
' // MessageId: DTS_E_ERRORATLOADTASK
' //
' // MessageText:
' //
' //  Error loading task. This happens when loading a task from XML fails.
' //
%DTS_E_ERRORATLOADTASK            = &HC0010028&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when trying to load a package (or other object) from an XML node that is not of that type, such as a non-SSIS xml node.

' //
' // MessageId: DTS_E_CANTLOADFROMNODE
' //
' // MessageText:
' //
' //  The runtime object cannot be loaded from the specified XML node.  This happens when trying to load a package or other object from an XML node that is not of the correct type, such as a non-SSIS XML node.
' //
%DTS_E_CANTLOADFROMNODE           = &HC0011001&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when trying to load a package and the file could not be opened or loaded correctly into XML Document.  Typically, it means an invalid file name was specified when calling LoadPackage, check
' // the filename for correct spelling. Or the XML file specified has invalid format.

' //
' // MessageId: DTS_E_OPENPACKAGEFILE
' //
' // MessageText:
' //
' //  Failed to open package file "%1!s!" due to error 0x%2!8.8X! "%3!s!".  This happens when loading a package and the file cannot be opened or loaded correctly into the XML document.
' //  This can be the result of either providing an incorrect file name was specified when calling LoadPackage or the XML file was specified and has an incorrect format.
' //
%DTS_E_OPENPACKAGEFILE            = &HC0011002&

' //
' // MessageId: DTS_E_LOADPACKAGEXML
' //
' // MessageText:
' //
' //  Failed to load XML due to error 0x%1!8.8X! "%2!s!". This happens when loading a package and the file cannot be opened or loaded correctly into XML document.  This can be the result of either providing
' //  an incorrect file name to the LoadPackage method or the XML file specified having an incorrect format.
' //
%DTS_E_LOADPACKAGEXML             = &HC0011003&

' //
' // MessageId: DTS_E_LOADPACKAGEXMLFILE
' //
' // MessageText:
' //
' //  Failed to load XML from package file "%1!s!" due to error 0x%2!8.8X! "%3!s!".  This happens when loading a package and the file cannot be opened or loaded correctly into an XML document.
' //  This can be the result of either providing an incorrect file name to the LoadPackage method or the XML file specified having an incorrect format.
' //
%DTS_E_LOADPACKAGEXMLFILE         = &HC0011004&

' //
' // MessageId: DTS_E_OPENFILE
' //
' // MessageText:
' //
' //  Failed to open package file. This happens when loading a package and the file cannot be opened or loaded correctly into an XML document. This can be the result of either providing an incorrect file name
' //  to the LoadPackage method or the XML file specified having an incorrect format.
' //
%DTS_E_OPENFILE                   = &HC0011005&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when failing to decode a binary format in the package.

' //
' // MessageId: DTS_E_UNABLETODECODEBINARYFORMAT
' //
' // MessageText:
' //
' //  Unable to decode a binary format in the package.
' //
%DTS_E_UNABLETODECODEBINARYFORMAT = &HC0011006&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when The package does not have a valid xml format and could not be loaded as xml.

' //
' // MessageId: DTS_E_FUNDAMENTALLOADINGERROR
' //
' // MessageText:
' //
' //  Unable to load the package as XML because of package does not have a valid XML format. A specific XML parser error will be posted.
' //
%DTS_E_FUNDAMENTALLOADINGERROR    = &HC0011007&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when there is an error loading from XML and user did not pass in a valid Events object where a detailed error can be specified.

' //
' // MessageId: DTS_E_LOADFROMXML
' //
' // MessageText:
' //
' //  Error loading from XML. No further detailed error information can be specified for this problem because no Events object was passed where detailed error information can be stored.
' //
%DTS_E_LOADFROMXML                = &HC0011008&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when there is an error creating an XML DOM object. XML may not be registered.

' //
' // MessageId: DTS_E_XMLDOMERROR
' //
' // MessageText:
' //
' //  Cannot create an instance of the XML Document Object Model. MSXML may not be registered.
' //
%DTS_E_XMLDOMERROR                = &HC0011009&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when attempting to load an older SSIS version package, or the package file refers to an invalid structured object.

' //
' // MessageId: DTS_E_CANNOTLOADOLDPACKAGES
' //
' // MessageText:
' //
' //  The package cannot be loaded. This occurs when attempting to load an older version package, or the package file refers to an invalid structured object.
' //
%DTS_E_CANNOTLOADOLDPACKAGES      = &HC001100D&

' //
' // MessageId: DTS_E_SAVEFILE
' //
' // MessageText:
' //
' //  Failed to save package file.
' //
%DTS_E_SAVEFILE                   = &HC001100E&

' //
' // MessageId: DTS_E_SAVEPACKAGEFILE
' //
' // MessageText:
' //
' //  Failed to save package file "%1!s!" with error 0x%2!8.8X! "%3!s!".
' //
%DTS_E_SAVEPACKAGEFILE            = &HC001100F&

' ////////////////////////////////////////////////////////////////////////////
' // The runtime was expecting the object to implement IDTSName90, but it didn't.  The object should support IDTSName90.

' //
' // MessageId: DTS_E_IDTSNAMENOTSUPPORTED
' //
' // MessageText:
' //
' //  The object must inherit from IDTSName90 and does not.
' //
%DTS_E_IDTSNAMENOTSUPPORTED       = &HC001200D&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when one of the configuration file configuration entries has an invalid format: There was no \package delimiter

' //
' // MessageId: DTS_E_CONFIGFORMATINVALID_PACKAGEDELIMITER
' //
' // MessageText:
' //
' //  The configuration entry, "%1!s!", has an incorrect format because it does not begin with package delimiter. There was no "\package" delimiter.
' //
%DTS_E_CONFIGFORMATINVALID_PACKAGEDELIMITER = &HC0012018&

' ////////////////////////////////////////////////////////////////////////////
' // Returned for various formatting errors like invalid array delimiter or missing delimiter

' //
' // MessageId: DTS_E_CONFIGFORMATINVALID
' //
' // MessageText:
' //
' //  The configuration entry "%1!s!" had an incorrect format. This can occur because of a missing delimiter or formatting errors, like an invalid array delimiter.
' //
%DTS_E_CONFIGFORMATINVALID        = &HC0012019&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when trying to export configurations, usually preceded by more descriptive errors

' //
' // MessageId: DTS_E_CONFIGFILEFAILEDEXPORT
' //
' // MessageText:
' //
' //  Failure exporting configuration file.
' //
%DTS_E_CONFIGFILEFAILEDEXPORT     = &HC001201B&

' ////////////////////////////////////////////////////////////////////////////
' // The properties collection is read only and cannot be modified.

' //
' // MessageId: DTS_E_PROPERTIESCOLLECTIONREADONLY
' //
' // MessageText:
' //
' //  Properties collection cannot be modified.
' //
%DTS_E_PROPERTIESCOLLECTIONREADONLY = &HC0012021&

' //
' // MessageId: DTS_E_DTRXMLSAVEFAILURE
' //
' // MessageText:
' //
' //  Unable to save configuration file. The file may be read only.
' //
%DTS_E_DTRXMLSAVEFAILURE          = &HC0012022&

' ////////////////////////////////////////////////////////////////////////////
' // FailPackageOnFailure property is not applicable to the package container.

' //
' // MessageId: DTS_E_FAILPACKAGEONFAILURENA
' //
' // MessageText:
' //
' //  FailPackageOnFailure property is not applicable to the package container.
' //
%DTS_E_FAILPACKAGEONFAILURENA     = &HC0012023&

' ////////////////////////////////////////////////////////////////////////////
' // The product level required by the task is higher than the current product level.

' //
' // MessageId: DTS_E_TASKPRODUCTLEVEL
' //
' // MessageText:
' //
' //  The task "%1!s!" cannot run on this edition of Integration Services. It requires a higher level edition.
' //
%DTS_E_TASKPRODUCTLEVEL           = &HC0012024&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when a user attempts to save a configuration to a file and the XML document save operation fails to write to the file. The file maybe read only.

' //
' // MessageId: DTS_E_UNABLETOSAVETOFILE
' //
' // MessageText:
' //
' //  Unable to save xml to "%1!s!". The file may be read only.
' //
%DTS_E_UNABLETOSAVETOFILE         = &HC0012029&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when a configuration value cannot be converted from a string to the appropriate destination type.  Check the configuration value to ensure it can be converted to the type of the destination property or variable.

' //
' // MessageId: DTS_E_CONFIGTYPECONVERSIONFAILED
' //
' // MessageText:
' //
' //  Failed to convert a type in the configuration "%1!s!" for the package path "%2!s!".  This happens when a configuration value cannot be converted from a string to the appropriate destination type.
' //  Check the configuration value to ensure it can be converted to the type of the destination property or variable.
' //
%DTS_E_CONFIGTYPECONVERSIONFAILED = &HC0012037&

' //
' // MessageId: DTS_E_CONFIGFAILED
' //
' // MessageText:
' //
' //  Configuration failure. This is a generic warning for all configuration types. Other warnings should precede this with more information.
' //
%DTS_E_CONFIGFAILED               = &HC0012049&

' ////////////////////////////////////////////////////////////////////////////
' // There is a problem with package being executed.

' //
' // MessageId: DTS_E_REMOTEPACKAGEVALIDATION
' //
' // MessageText:
' //
' //  Package failed validation from the ExecutePackage task. The package cannot run.
' //
%DTS_E_REMOTEPACKAGEVALIDATION    = &HC0012050&

' ////////////////////////////////////////////////////////////////////////////
' // Should never happen, but when it does means that internally the wrapper has an invalid pointer to a task

' //
' // MessageId: DTS_E_INVALIDTASKPOINTER
' //
' // MessageText:
' //
' //  The wrappers task pointer is not valid. The wrapper has an invalid pointer to a task.
' //
%DTS_E_INVALIDTASKPOINTER         = &HC0014003&

' ////////////////////////////////////////////////////////////////////////////
' // This will happen anytime a client tries to add an executable to more than one executables collection, resolution: remove the executable from it's current executables collection before adding it

' //
' // MessageId: DTS_E_ALREADYADDED
' //
' // MessageText:
' //
' //  The executable has been added to the Executables collection of another container. This occurs when a client tries to add an executable to more than one Executables collection.
' //  You need to remove the executable from the current Executables collection before attempting to add it.
' //
%DTS_E_ALREADYADDED               = &HC0014004&

' ////////////////////////////////////////////////////////////////////////////
' // This error is returned when an attempt is made to create a connection manager for unknown connection type. The typical cause is a typo in connection type name

' //
' // MessageId: DTS_E_UNKNOWNCONNECTIONMANAGERTYPE
' //
' // MessageText:
' //
' //  The connection type "%1!s!" specified for connection manager "%2!s!" is not recognized as a valid connection manager type. This error is returned when an attempt is made to create a connection manager
' // for an unknown connection type. Check the spelling in the connection type name.
' //
%DTS_E_UNKNOWNCONNECTIONMANAGERTYPE = &HC0014005&

' ////////////////////////////////////////////////////////////////////////////
' // This is typically, but not always, caused by out of memory condition

' //
' // MessageId: DTS_E_COLLECTIONCOULDNTADD
' //
' // MessageText:
' //
' //  An object was created but the attempt to add it to a collection failed. This can occur due to an out-of-memory condition.
' //
%DTS_E_COLLECTIONCOULDNTADD       = &HC0014006&

' //
' // MessageId: DTS_E_ODBCERRORENV
' //
' // MessageText:
' //
' //  There was an error creating an Open Database Connectivity (ODBC) environment.
' //
%DTS_E_ODBCERRORENV               = &HC0014007&

' //
' // MessageId: DTS_E_ODBCERRORDBC
' //
' // MessageText:
' //
' //   There was an error creating an Open Database Connectivity (ODBC) database connection.
' //
%DTS_E_ODBCERRORDBC               = &HC0014008&

' //
' // MessageId: DTS_E_ODBCERRORCONNECT
' //
' // MessageText:
' //
' //  There was an error trying to establish an Open Database Connectivity (ODBC) connection with the database server.
' //
%DTS_E_ODBCERRORCONNECT           = &HC0014009&

' //
' // MessageId: DTS_E_CONNECTIONMANAGERQUALIFIERALREADYSET
' //
' // MessageText:
' //
' //  The qualifier is already set on this instance of the connection manager. The qualifier may be set once per instance.
' //
%DTS_E_CONNECTIONMANAGERQUALIFIERALREADYSET = &HC001400A&

' //
' // MessageId: DTS_E_CONNECTIONMANAGERQUALIFIERNOTSET
' //
' // MessageText:
' //
' //  The qualifier has not been set on this instance of the connection manager. Setting the qualifier is required to complete initialization.
' //
%DTS_E_CONNECTIONMANAGERQUALIFIERNOTSET = &HC001400B&

' //
' // MessageId: DTS_E_CONNECTIONMANAGERQUALIFIERNOTSUPPORTED
' //
' // MessageText:
' //
' //  This connection manager does not support specification of qualifiers.
' //
%DTS_E_CONNECTIONMANAGERQUALIFIERNOTSUPPORTED = &HC001400C&

' //
' // MessageId: DTS_E_CANNOTCLONECONNECTIONMANAGER
' //
' // MessageText:
' //
' //  Connection manager "0x%1!s!" cannot be cloned for out-of-process execution.
' //
%DTS_E_CANNOTCLONECONNECTIONMANAGER = &HC001400D&

' //
' // MessageId: DTS_E_NOSQLPROFILERDLL
' //
' // MessageText:
' //
' //  The log provider for SQL Profiler was unable to load pfclnt90.dll. Please check that the SQL Profiler is installed.
' //
%DTS_E_NOSQLPROFILERDLL           = &HC001400E&

' ////////////////////////////////////////////////////////////////////////////
' // This indicates logging error that is not attributable to a specific log provider.

' //
' // MessageId: DTS_E_LOGFAILED
' //
' // MessageText:
' //
' //  The SSIS logging infrastructure failed with error code 0x%1!8.8X!. This error indicates that this logging error is not attributable to a specific log provider.
' //
%DTS_E_LOGFAILED                  = &HC001400F&

' ////////////////////////////////////////////////////////////////////////////
' // This indicates logging error attributed to a specified log provider.

' //
' // MessageId: DTS_E_LOGPROVIDERFAILED
' //
' // MessageText:
' //
' //  The SSIS logging provider "%1!s!" failed with error code 0x%2!8.8X! (%3!s!).  This indicates a logging error attributable to the specified log provider.
' //
%DTS_E_LOGPROVIDERFAILED          = &HC0014010&

' ////////////////////////////////////////////////////////////////////////////
' // We issued a SQL statement and it has failed.

' //
' // MessageId: DTS_E_SAVETOSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The SaveToSQLServer method has encountered OLE DB error code 0x%1!8.8X! (%2!s!).  The SQL statement that was issued has failed.
' //
%DTS_E_SAVETOSQLSERVER_OLEDB      = &HC0014011&

' //
' // MessageId: DTS_E_LOADFROMSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The LoadFromSQLServer method has encountered OLE DB error code 0x%1!8.8X! (%2!s!).  The SQL statement that was issued has failed.
' //
%DTS_E_LOADFROMSQLSERVER_OLEDB    = &HC0014012&

' //
' // MessageId: DTS_E_REMOVEFROMSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The RemoveFromSQLServer method encountered OLE DB error code 0x%1!8.8X! (%2!s!) The SQL statement that was issued has failed.
' //
%DTS_E_REMOVEFROMSQLSERVER_OLEDB  = &HC0014013&

' //
' // MessageId: DTS_E_EXISTSONSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The ExistsOnSQLServer method has encountered OLE DB error code 0x%1!8.8X! (%2!s!). The SQL statement issued has failed.
' //
%DTS_E_EXISTSONSQLSERVER_OLEDB    = &HC0014014&

' ////////////////////////////////////////////////////////////////////////////
' // We called IDataInitialize::GetDataSource and it returned DB_E_ERRORSOCCURRED.

' //
' // MessageId: DTS_E_CONNECTIONSTRING
' //
' // MessageText:
' //
' //  OLE DB has failed making a database connection when using the supplied connection string.
' //
%DTS_E_CONNECTIONSTRING           = &HC0014015&

' ////////////////////////////////////////////////////////////////////////////
' // When adding a precedence constraint the user specified "From" executable which is not a child of this container.

' //
' // MessageId: DTS_E_FROMEXECISNOTCHILD
' //
' // MessageText:
' //
' //  When adding a precedence constraint, a From executable was specified that is not a child of this container.
' //
%DTS_E_FROMEXECISNOTCHILD         = &HC0014016&

' ////////////////////////////////////////////////////////////////////////////
' // When adding a precedence constraint the user specified "To" executable which is not a child of this container.

' //
' // MessageId: DTS_E_TOEXECISNOTCHILD
' //
' // MessageText:
' //
' //  When adding a precedence constraint, the To executable specified is not a child of this container.
' //
%DTS_E_TOEXECISNOTCHILD           = &HC0014017&

' ////////////////////////////////////////////////////////////////////////////
' // SQLSetConnectAttr failed to set SQL_ATTR_ENLIST_IN_DTC attribute

' //
' // MessageId: DTS_E_ODBCTRANSACTIONENLIST
' //
' // MessageText:
' //
' //  There was an error trying enlist an ODBC connection in a transaction. The SQLSetConnectAttr failed to set the SQL_ATTR_ENLIST_IN_DTC attribute.
' //
%DTS_E_ODBCTRANSACTIONENLIST      = &HC0014018&

' ////////////////////////////////////////////////////////////////////////////
' // When OfflineMode is True, it means that connections cannot be acquired.

' //
' // MessageId: DTS_E_CONNECTIONOFFLINE
' //
' // MessageText:
' //
' //  The connection manager "%1!s!" will not acquire a connection because the package OfflineMode property is TRUE. When the OfflineMode is TRUE, connections cannot be acquired.
' //
%DTS_E_CONNECTIONOFFLINE          = &HC0014019&

' ////////////////////////////////////////////////////////////////////////////
' // DTC tx failed to start, e.g. msdtc service is not running

' //
' // MessageId: DTS_E_BEGINTRANSACTION
' //
' // MessageText:
' //
' //  The SSIS Runtime has failed to start the distributed transaction due to error 0x%1!8.8X! "%2!s!". The DTC transaction failed to start. This could occur because the MSDTC Service is not running.
' //
%DTS_E_BEGINTRANSACTION           = &HC001401A&

' ////////////////////////////////////////////////////////////////////////////
' // Design time only method

' //
' // MessageId: DTS_E_SETQUALIFIERDESIGNTIMEONLY
' //
' // MessageText:
' //
' //  The SetQualifier method cannot be called on a connection manager during package execution. This method is used at design-time only.
' //
%DTS_E_SETQUALIFIERDESIGNTIMEONLY = &HC001401B&

' ////////////////////////////////////////////////////////////////////////////
' // Not supported on earlier versions of servers

' //
' // MessageId: DTS_E_SQLPERSISTENCEVERSION
' //
' // MessageText:
' //
' //  Storing packages in SQL Server requires database server version 9.0 or higher. Storing packages in SQL Server is not supported on earlier versions of servers.
' //
%DTS_E_SQLPERSISTENCEVERSION      = &HC001401C&

' //
' // MessageId: DTS_E_CONNECTIONVALIDATIONFAILED
' //
' // MessageText:
' //
' //  Connection "%1!s!" failed validation.
' //
%DTS_E_CONNECTIONVALIDATIONFAILED = &HC001401D&

' //
' // MessageId: DTS_E_INVALIDFILENAMEINCONNECTION
' //
' // MessageText:
' //
' //  The file name "%1!s!" specified in the connection was not valid.
' //
%DTS_E_INVALIDFILENAMEINCONNECTION = &HC001401E&

' ////////////////////////////////////////////////////////////////////////////
' // Vertical bars found on connection string and Retain is True.

' //
' // MessageId: DTS_E_MULTIPLEFILESONRETAINEDCONNECTION
' //
' // MessageText:
' //
' //  Multiple file names cannot be specified on a connection when the Retain property is TRUE. Vertical bars were found on the connection string, meaning multiple file names are being specified and, in addition, the Retain property is TRUE.
' //
%DTS_E_MULTIPLEFILESONRETAINEDCONNECTION = &HC001401F&

' ////////////////////////////////////////////////////////////////////////////
' // Some ODBC error has occurred. A later message will provide context

' //
' // MessageId: DTS_E_ODBCERROR
' //
' // MessageText:
' //
' //  An ODBC error %1!d! has occurred.
' //
%DTS_E_ODBCERROR                  = &HC0014020&

' //
' // MessageId: DTS_E_PRECEDENCECONSTRAINT
' //
' // MessageText:
' //
' //  There was an error in the precedence constraint between "%1!s!" and "%2!s!".
' //
%DTS_E_PRECEDENCECONSTRAINT       = &HC0014021&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when attempting to populate foreachenumerators that are native.

' //
' // MessageId: DTS_E_FAILEDPOPNATIVEFEE
' //
' // MessageText:
' //
' //  Failed to populate the ForEachEnumeratorInfos collection with native ForEachEnumerators with the following error code: %1!s!.
' //
%DTS_E_FAILEDPOPNATIVEFEE         = &HC0014022&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when ForEach Enumerator cannot enumerate.

' //
' // MessageId: DTS_E_GETENUMERATOR
' //
' // MessageText:
' //
' //  The GetEnumerator method of the ForEach Enumerator has failed with error 0x%1!8.8X! "%2!s!". This occurs when the ForEach Enumerator cannot enumerate.
' //
%DTS_E_GETENUMERATOR              = &HC0014023&

' ////////////////////////////////////////////////////////////////////////////
' // This occurs when CPackage::put_CertificateObject can't instantiate Managed Helper object, when Managed Helper fails or when Managed Helper returns a malformed array (really unexpected).

' //
' // MessageId: DTS_E_CANTGETCERTDATA
' //
' // MessageText:
' //
' //  The raw certificate data cannot be obtained from the supplied certificate object (error: %1!s!). This occurs when CPackage::put_CertificateObject cannot instantiate the ManagedHelper object,
' //  when the ManagedHelper object fails, or when the ManagedHelper object returns a malformed array.
' //
%DTS_E_CANTGETCERTDATA            = &HC0014024&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs in CPackage::put_CertificateObject or CPackage::LoadFromXML when corresponding CryptoAPI function fails.

' //
' // MessageId: DTS_E_CANTCREATECERTCONTEXT
' //
' // MessageText:
' //
' //  Failed to create certificate context (error: %1!s!). This occurs in CPackage::put_CertificateObject or CPackage::LoadFromXML when the corresponding CryptoAPI function fails.
' //
%DTS_E_CANTCREATECERTCONTEXT      = &HC0014025&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs in CPackage::LoadUserCertificateByName and CPackage::LoadUserCertificateByHash.

' //
' // MessageId: DTS_E_CANTOPENCERTSTORE
' //
' // MessageText:
' //
' //  Opening MY certificate store failed with error "%1!s!".This occurs in CPackage::LoadUserCertificateByName and CPackage::LoadUserCertificateByHash.
' //
%DTS_E_CANTOPENCERTSTORE          = &HC0014026&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs in CPackage::LoadUserCertificateByName.

' //
' // MessageId: DTS_E_CANTFINDCERTBYNAME
' //
' // MessageText:
' //
' //  The certificate specified by name in MY store cannot be found (error: %1!s!). This occurs in CPackage::LoadUserCertificateByName.
' //
%DTS_E_CANTFINDCERTBYNAME         = &HC0014027&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs in CPackage::LoadUserCertificateByHash.

' //
' // MessageId: DTS_E_CANTFINDCERTBYHASH
' //
' // MessageText:
' //
' //  Unable to find the specified certificate by hash in "MY" store (error: %1!s!). Occurs in CPackage::LoadUserCertificateByHash.
' //
%DTS_E_CANTFINDCERTBYHASH         = &HC0014028&

' //
' // MessageId: DTS_E_INVALIDCERTHASHFORMAT
' //
' // MessageText:
' //
' //  The hash value is not a one-dimensional array of bytes (error: %1!s!). This occurs in CPackage::LoadUserCertificateByHash.
' //
%DTS_E_INVALIDCERTHASHFORMAT      = &HC0014029&

' ////////////////////////////////////////////////////////////////////////////
' // Could occur wherever GetDataFromSafeArray is called.

' //
' // MessageId: DTS_E_CANTACCESSARRAYDATA
' //
' // MessageText:
' //
' //  The data in the array cannot be accessed (error: %1!s!). This error can occur wherever GetDataFromSafeArray is called.
' //
%DTS_E_CANTACCESSARRAYDATA        = &HC001402A&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs whenever CoCreateInstance CLSID_DTSManagedHelper fails.

' //
' // MessageId: DTS_E_CREATEMANAGEDHELPERFAILED
' //
' // MessageText:
' //
' //  The SSIS managed helper object failed during creation with error 0x%1!8.8X! "%2!s!". This occurs whenever CoCreateInstance CLSID_DTSManagedHelper fails.
' //
%DTS_E_CREATEMANAGEDHELPERFAILED  = &HC001402B&

' //
' // MessageId: DTS_E_OLEDBTRANSACTIONENLIST
' //
' // MessageText:
' //
' //  The SSIS Runtime has failed to enlist the OLE DB connection in a distributed transaction with error 0x%1!8.8X! "%2!s!".
' //
%DTS_E_OLEDBTRANSACTIONENLIST     = &HC001402C&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when managed helper's SignDocument fails.

' //
' // MessageId: DTS_E_SIGNPACKAGEFAILED
' //
' // MessageText:
' //
' //  Package signing failed with error 0x%1!8.8X! "%2!s!". This occurs when the ManagedHelper.SignDocument method fails.
' //
%DTS_E_SIGNPACKAGEFAILED          = &HC001402D&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs in CPackage::LoadFromXML

' //
' // MessageId: DTS_E_CHECKENVELOPEFAILED
' //
' // MessageText:
' //
' //  Failed to check for XML signature envelope in package XML with error 0x%1!8.8X! "%2!s!". This occurs in CPackage::LoadFromXML.
' //
%DTS_E_CHECKENVELOPEFAILED        = &HC001402E&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when IXMLDOMDocument::get_xml fails

' //
' // MessageId: DTS_E_GETXMLSOURCEFAILED
' //
' // MessageText:
' //
' //  Failed to obtain XML source from XML DOM object with error 0x%1!8.8X! "%2!s!". This occurs when IXMLDOMDocument::get_xml fails.
' //
%DTS_E_GETXMLSOURCEFAILED         = &HC001402F&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when signature verification operation fails.

' //
' // MessageId: DTS_E_PACKAGEVERIFICATIONFAILED
' //
' // MessageText:
' //
' //  The cryptographic signature of the package failed verification due to error 0x%1!8.8X! "%2!s!". This occurs when the signature verification operation fails.
' //
%DTS_E_PACKAGEVERIFICATIONFAILED  = &HC0014030&

' ////////////////////////////////////////////////////////////////////////////
' // This usually occurs when trying to sign a document using a certificate for which the person does not have the private key.

' //
' // MessageId: DTS_E_GETKEYFROMCERTFAILED
' //
' // MessageText:
' //
' //  Failed to obtain cryptographic key pair associated with the specified certificate with error 0x%1!8.8X! "%2!s!". Verify that you have the key pair for which the certificate was issued.
' //  This error usually occurs when trying to sign a document using a certificate for which the person does not have the private key.
' //
%DTS_E_GETKEYFROMCERTFAILED       = &HC0014031&

' //
' // MessageId: DTS_E_INVALIDSIGNATURE
' //
' // MessageText:
' //
' //  The digital signature is not valid. The contents of the package have been modified.
' //
%DTS_E_INVALIDSIGNATURE           = &HC0014032&

' //
' // MessageId: DTS_E_UNTRUSTEDSIGNATURE
' //
' // MessageText:
' //
' //  The digital signature is valid; however the signer is not trusted and, therefore, authenticity cannot be guaranteed.
' //
%DTS_E_UNTRUSTEDSIGNATURE         = &HC0014033&

' //
' // MessageId: DTS_E_TRANSACTIONENLISTNOTSUPPORTED
' //
' // MessageText:
' //
' //  The connection does not support enlisting in distributed transaction.
' //
%DTS_E_TRANSACTIONENLISTNOTSUPPORTED = &HC0014034&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when saving to Xml

' //
' // MessageId: DTS_E_PACKAGEPROTECT
' //
' // MessageText:
' //
' //  Failed to apply package protection with error 0x%1!8.8X! "%2!s!". This error occurs when saving to Xml.
' //
%DTS_E_PACKAGEPROTECT             = &HC0014035&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs in CPackage::LoadFromXML

' //
' // MessageId: DTS_E_PACKAGEUNPROTECT
' //
' // MessageText:
' //
' //  Failed to remove package protection with error 0x%1!8.8X! "%2!s!". This occurs in the CPackage::LoadFromXML method.
' //
%DTS_E_PACKAGEUNPROTECT           = &HC0014036&

' //
' // MessageId: DTS_E_PACKAGEPASSWORD
' //
' // MessageText:
' //
' //  The package is encrypted with a password. The password was not specified, or is not correct.
' //
%DTS_E_PACKAGEPASSWORD            = &HC0014037&

' ////////////////////////////////////////////////////////////////////////////
' // We do not allow more than one PC.

' //
' // MessageId: DTS_E_DUPLICATECONSTRAINT
' //
' // MessageText:
' //
' //  A precedence constraint already exists between the specified executables. More than one precedence constraint is not allowed.
' //
%DTS_E_DUPLICATECONSTRAINT        = &HC0014038&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when CPackage::LoadFromXML fails.

' //
' // MessageId: DTS_E_PACKAGELOADFAILED
' //
' // MessageText:
' //
' //  The package failed to load due to error 0x%1!8.8X! "%2!s!". This occurs when CPackage::LoadFromXML fails.
' //
%DTS_E_PACKAGELOADFAILED          = &HC0014039&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when signed XML doesn't contain SSIS package as expected.

' //
' // MessageId: DTS_E_PACKAGEOBJECTNOTENVELOPED
' //
' // MessageText:
' //
' //  Failed to find package object in signed XML envelope with error 0x%1!8.8X! "%2!s!". This occurs when signed XML does not contain a SSIS package, as expected.
' //
%DTS_E_PACKAGEOBJECTNOTENVELOPED  = &HC001403A&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when lengths of arrays are mismatched, there should be one entry per parameter in each array.

' //
' // MessageId: DTS_E_JAGGEDEVENTINFO
' //
' // MessageText:
' //
' //  The lengths of parameter names, types, and descriptions arrays are not equal. The lengths must be equal. This occurs when the lengths of the arrays are mismatched. There should be one entry per parameter in each array.
' //
%DTS_E_JAGGEDEVENTINFO            = &HC001403B&

' ////////////////////////////////////////////////////////////////////////////
' // We issued a SQL statement and it has failed.

' //
' // MessageId: DTS_E_GETPACKAGEINFOS
' //
' // MessageText:
' //
' //  An OLE DB error 0x%1!8.8X! (%2!s!) occurred while enumerating packages. A SQL statement was issued and failed.
' //
%DTS_E_GETPACKAGEINFOS            = &HC001403C&

' ////////////////////////////////////////////////////////////////////////////
' // This error is returned when an attempt is made to create a log provider for unknown log provider type. The typical cause is a typo in log provider type name

' //
' // MessageId: DTS_E_UNKNOWNLOGPROVIDERTYPE
' //
' // MessageText:
' //
' //  The log provider type "%1!s!" specified for log provider "%2!s!" is not recognized as a valid log provider type. This error occurs when an attempt is made to create a log provider for unknown log provider type.
' //  Verify the spelling in the log provider type name.
' //
%DTS_E_UNKNOWNLOGPROVIDERTYPE     = &HC001403D&

' //
' // MessageId: DTS_E_UNKNOWNLOGPROVIDERTYPENOSUBS
' //
' // MessageText:
' //
' //  The log provider type is not recognized as a valid log provider type. This error occurs when an attempt is made to create a log provider for unknown log provider type. Verify the spelling in the log provider type name.
' //
%DTS_E_UNKNOWNLOGPROVIDERTYPENOSUBS = &HC001403E&

' ////////////////////////////////////////////////////////////////////////////
' // This error is returned when an attempt is made to create a connection manager for unknown connection type. The typical cause is a typo in connection type name

' //
' // MessageId: DTS_E_UNKNOWNCONNECTIONMANAGERTYPENOSUBS
' //
' // MessageText:
' //
' //  The connection type specified for connection manager is not a valid connection manager type. This error occurs when an attempt is made to create a connection manager for unknown connection type. Verify the spelling of the connection type name.
' //
%DTS_E_UNKNOWNCONNECTIONMANAGERTYPENOSUBS = &HC001403F&

' //
' // MessageId: DTS_E_PACKAGEREMOVEFAILED
' //
' // MessageText:
' //
' //  An error was encountered when trying to remove the package "%1!s!" from SQL Server.
' //
%DTS_E_PACKAGEREMOVEFAILED        = &HC0014040&

' //
' // MessageId: DTS_E_FOLDERADDFAILED
' //
' // MessageText:
' //
' //  An error was encountered when trying to create a folder on SQL Server named "%1!s!" in folder "%2!s!".
' //
%DTS_E_FOLDERADDFAILED            = &HC0014042&

' ////////////////////////////////////////////////////////////////////////////
' // We issued a SQL statement and it has failed.

' //
' // MessageId: DTS_E_CREATEFOLDERONSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The CreateFolderOnSQLServer method has encountered OLE DB error code 0x%1!8.8X! (%2!s!) The SQL statement issued has failed.
' //
%DTS_E_CREATEFOLDERONSQLSERVER_OLEDB = &HC0014043&

' //
' // MessageId: DTS_E_FOLDERRENAMEFAILED
' //
' // MessageText:
' //
' //  An error occurred when renaming folder " %1!s!\\%2!s!" to "%1!s!\\%3!s!" on SQL Server.
' //
%DTS_E_FOLDERRENAMEFAILED         = &HC0014044&

' ////////////////////////////////////////////////////////////////////////////
' // We issued a SQL statement and it has failed.

' //
' // MessageId: DTS_E_RENAMEFOLDERONSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The RenameFolderOnSQLServer method encountered OLE DB error code 0x%1!8.8X! (%2!s!). The SQL statement issued has failed.
' //
%DTS_E_RENAMEFOLDERONSQLSERVER_OLEDB = &HC0014045&

' //
' // MessageId: DTS_E_FOLDERDELETEFAILED
' //
' // MessageText:
' //
' //  Error deleting SQL Server folder "%1!s!".
' //
%DTS_E_FOLDERDELETEFAILED         = &HC0014046&

' ////////////////////////////////////////////////////////////////////////////
' // We issued a SQL statement and it has failed.

' //
' // MessageId: DTS_E_REMOVEFOLDERFROMSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  The RemoveFolderOnSQLServer method encountered OLE DB error code 0x%1!8.8X! (%2!s!). The SQL statement issued has failed.
' //
%DTS_E_REMOVEFOLDERFROMSQLSERVER_OLEDB = &HC0014047&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when the path does not contain at least one back or forward slash.

' //
' // MessageId: DTS_E_INVALIDPATHTOPACKAGE
' //
' // MessageText:
' //
' //  The specified package path does not contain a package name. This occurs when the path does not contain at least one backslash or one forward slash.
' //
%DTS_E_INVALIDPATHTOPACKAGE       = &HC0014048&

' //
' // MessageId: DTS_E_FOLDERNOTFOUND
' //
' // MessageText:
' //
' //  Cannot find folder "%1!s!".
' //
%DTS_E_FOLDERNOTFOUND             = &HC0014049&

' ////////////////////////////////////////////////////////////////////////////
' // We issued a SQL statement and it has failed.

' //
' // MessageId: DTS_E_FINDFOLDERONSQLSERVER_OLEDB
' //
' // MessageText:
' //
' //  While trying to find a folder on SQL an OLE DB error was encountered with error code 0x%1!8.8X! (%2!s!).
' //
%DTS_E_FINDFOLDERONSQLSERVER_OLEDB = &HC001404A&

' //
' // MessageId: DTS_E_OPENLOGFAILED
' //
' // MessageText:
' //
' //  The SSIS logging provider has failed to open the log. Error code: 0x%1!8.8X!.
' //
%DTS_E_OPENLOGFAILED              = &HC001404B&

' ////////////////////////////////////////////////////////////////////////////
' // IDTSApplication90::get_ConnectionInfos failed

' //
' // MessageId: DTS_E_GETCONNECTIONINFOS
' //
' // MessageText:
' //
' //  Failed to get ConnectionInfos collection with error 0x%1!8.8X! "%2!s!". This error occurs when the call to IDTSApplication90::get_ConnectionInfos fails.
' //
%DTS_E_GETCONNECTIONINFOS         = &HC001404C&

' ////////////////////////////////////////////////////////////////////////////
' // We couldn't acquire all the locks after 16 attempts; they all timed out

' //
' // MessageId: DTS_E_VARIABLEDEADLOCK
' //
' // MessageText:
' //
' //  Deadlock detected while trying to lock variables. The locks cannot be acquired after 16 attempts. The locks timed out.
' //
%DTS_E_VARIABLEDEADLOCK           = &HC001404D&

' ////////////////////////////////////////////////////////////////////////////
' // An operation was attempted that is only allowed on dispensed collections.

' //
' // MessageId: DTS_E_NOTDISPENSED
' //
' // MessageText:
' //
' //  The Variables collection has not been returned from the VariableDispenser. An operation was attempted that is only allowed on dispensed collections.
' //
%DTS_E_NOTDISPENSED               = &HC001404E&

' ////////////////////////////////////////////////////////////////////////////
' // Unlock can be called at most once on a dispensed Variables collection.

' //
' // MessageId: DTS_E_VARIABLESALREADYUNLOCKED
' //
' // MessageText:
' //
' //  This Variables collection has already been unlocked. The Unlock method is called only once on a dispensed Variables collection.
' //
%DTS_E_VARIABLESALREADYUNLOCKED   = &HC001404F&

' ////////////////////////////////////////////////////////////////////////////
' // We failed to unlock some variables; dunno why, very unexpected

' //
' // MessageId: DTS_E_VARIABLEUNLOCKFAILED
' //
' // MessageText:
' //
' //  One or more variables failed to unlock.
' //
%DTS_E_VARIABLEUNLOCKFAILED       = &HC0014050&

' ////////////////////////////////////////////////////////////////////////////
' // Items cannot be added to or removed from dispensed collections.

' //
' // MessageId: DTS_E_DISPENSEDREADONLY
' //
' // MessageText:
' //
' //  The Variables collection was returned the from VariableDispenser and cannot be modified. Items cannot be added to or removed from dispensed collections.
' //
%DTS_E_DISPENSEDREADONLY          = &HC0014051&

' ////////////////////////////////////////////////////////////////////////////
' // A variable may only be added once to either read lock list or write lock list.

' //
' // MessageId: DTS_E_VARIABLEALREADYONREADLIST
' //
' // MessageText:
' //
' //  The variable "%1!s!" is already on the read list. A variable may only be added once to either the read lock list or the write lock list.
' //
%DTS_E_VARIABLEALREADYONREADLIST  = &HC0014052&

' //
' // MessageId: DTS_E_VARIABLEALREADYONWRITELIST
' //
' // MessageText:
' //
' //  The variable "%1!s!" is already on the write list. A variable may only be added once to either the read lock list or the write lock list.
' //
%DTS_E_VARIABLEALREADYONWRITELIST = &HC0014053&

' //
' // MessageId: DTS_E_LOCKVARIABLEFORREAD
' //
' // MessageText:
' //
' //  Failed to lock variable "%1!s!" for read access with error 0x%2!8.8X! "%3!s!".
' //
%DTS_E_LOCKVARIABLEFORREAD        = &HC0014054&

' //
' // MessageId: DTS_E_LOCKVARIABLEFORWRITE
' //
' // MessageText:
' //
' //  Failed to lock variable "%1!s!" for read/write access with error 0x%2!8.8X! "%3!s!".
' //
%DTS_E_LOCKVARIABLEFORWRITE       = &HC0014055&

' ////////////////////////////////////////////////////////////////////////////
' // A task is trying to declare custom event which another task has already declared with a different parameter list.

' //
' // MessageId: DTS_E_CUSTOMEVENTCONFLICT
' //
' // MessageText:
' //
' //  The custom event "%1!s!" is already declared with a different parameter list. A task is trying to declare a custom event, which another task has already declared with a different parameter list.
' //
%DTS_E_CUSTOMEVENTCONFLICT        = &HC0014056&

' ////////////////////////////////////////////////////////////////////////////
' // The custom event was declared with AllowEventHandlers = False.

' //
' // MessageId: DTS_E_EVENTHANDLERNOTALLOWED
' //
' // MessageText:
' //
' //  The task providing the custom event "%1!s!" does not allow this event to be handled in the package. The custom event was declared with AllowEventHandlers = FALSE.
' //
%DTS_E_EVENTHANDLERNOTALLOWED     = &HC0014057&

' ////////////////////////////////////////////////////////////////////////////
' // SetUnsafeVariables called more than once.

' //
' // MessageId: DTS_E_UNSAFEVARIABLESALREADYSET
' //
' // MessageText:
' //
' //  The VariableDspenser received an unsafe Variables collection. This operation cannot be repeated.
' //
%DTS_E_UNSAFEVARIABLESALREADYSET  = &HC0014059&

' ////////////////////////////////////////////////////////////////////////////
' // Call ForEachEnumeratorHost SetParentPackagePath before calling GetPackagePath.

' //
' // MessageId: DTS_E_INVALIDPARENTPACKAGEPATH
' //
' // MessageText:
' //
' //  GetPackagePath was called on the ForEachEnumerator but there was no ForEachLoop package path specified.
' //
%DTS_E_INVALIDPARENTPACKAGEPATH   = &HC001405A&

' ////////////////////////////////////////////////////////////////////////////
' // We couldn't acquire all the locks after 16 attempts; they all timed out

' //
' // MessageId: DTS_E_VARIABLEDEADLOCK_READ
' //
' // MessageText:
' //
' //  A deadlock was detected while trying to lock variable "%1!s!" for read access. A lock could not be acquired after 16 attempts and timed out.
' //
%DTS_E_VARIABLEDEADLOCK_READ      = &HC001405B&

' //
' // MessageId: DTS_E_VARIABLEDEADLOCK_READWRITE
' //
' // MessageText:
' //
' //  A deadlock was detected while trying to lock variables "%1!s!" for read/write access. A lock cannot be acquired after 16 attempts. The locks timed out.
' //
%DTS_E_VARIABLEDEADLOCK_READWRITE = &HC001405C&

' //
' // MessageId: DTS_E_VARIABLEDEADLOCK_BOTH
' //
' // MessageText:
' //
' //  A deadlock was detected while trying to lock variables "%1!s!" for read access and variables "%2!s!" for read/write access. A lock cannot be acquired after 16 attempts. The locks timed out.
' //
%DTS_E_VARIABLEDEADLOCK_BOTH      = &HC001405D&

' //
' // MessageId: DTS_E_PACKAGEPASSWORDEMPTY
' //
' // MessageText:
' //
' //  The protection level of the package requires a password, but PackagePassword property is empty.
' //
%DTS_E_PACKAGEPASSWORDEMPTY       = &HC001405E&

' //
' // MessageId: DTS_E_DECRYPTXML_PASSWORD
' //
' // MessageText:
' //
' //  Failed to decrypt an encrypted XML node because the password was not specified or not correct. Package load will attempt to continue without the encrypted information.
' //
%DTS_E_DECRYPTXML_PASSWORD        = &HC001405F&

' //
' // MessageId: DTS_E_DECRYPTPACKAGE_USERKEY
' //
' // MessageText:
' //
' //  Failed to decrypt a package that is encrypted with a user key. You may not be the user who encrypted this package, or you are not using the same machine that was used to save the package.
' //
%DTS_E_DECRYPTPACKAGE_USERKEY     = &HC0014060&

' //
' // MessageId: DTS_E_SERVERSTORAGEDISALLOWED
' //
' // MessageText:
' //
' //  The protection level, ServerStorage, cannot be used when saving to this destination. The system could not verify that the destination supports secure storage capability.
' //
%DTS_E_SERVERSTORAGEDISALLOWED    = &HC0014061&

' ////////////////////////////////////////////////////////////////////////////
' // There was a problem loading the package from SQL Server. Previously posted errors should have detailed information.

' //
' // MessageId: DTS_E_LOADFROMSQLSERVER
' //
' // MessageText:
' //
' //  LoadFromSQLServer method has failed.
' //
%DTS_E_LOADFROMSQLSERVER          = &HC0014062&

' ////////////////////////////////////////////////////////////////////////////
' // Use a different name to resolve

' //
' // MessageId: DTS_E_NAMEALREADYADDED
' //
' // MessageText:
' //
' //  The object cannot be added because another object with the same name already exists in the collection. Use a different name to resolve this error.
' //
%DTS_E_NAMEALREADYADDED           = &HC0014100&

' //
' // MessageId: DTS_E_NAMEALREADYEXISTS
' //
' // MessageText:
' //
' //  The object name cannot be changed from "%1!s!" to "%2!s!" because another object in the collection already uses that name. Use a different name to resolve this error.
' //
%DTS_E_NAMEALREADYEXISTS          = &HC0014101&

' ////////////////////////////////////////////////////////////////////////////
' // This happens anytime there was an error enumerating dependencies, look at the other messages that proceed this one for more information

' //
' // MessageId: DTS_E_FAILEDDEPENDENCIES
' //
' // MessageText:
' //
' //  There was an error enumerating the package dependencies. Check other messages for more information.
' //
%DTS_E_FAILEDDEPENDENCIES         = &HC0014103&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when a task calls CreateBreakpoint with the same ID multiple times.  It is possible to create a breakpoint with the same ID multiple times if the task calls RemoveBreakpoint on the first creation before creating the second one.

' //
' // MessageId: DTS_E_BPDUPLICATE
' //
' // MessageText:
' //
' //  The specified breakpoint ID already exists. This error occurs when a task calls CreateBreakpoint with the same ID multiple times. It is possible to create a breakpoint with the same ID multiple times
' //  if the task calls RemoveBreakpoint on the first creation before creating the second one.
' //
%DTS_E_BPDUPLICATE                = &HC0015001&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when a task references a breakpoint that does not exist.

' //
' // MessageId: DTS_E_BPUNKNOWNID
' //
' // MessageText:
' //
' //  The specified breakpoint ID does not exist. This error occurs when a task references a breakpoint that does not exist.
' //
%DTS_E_BPUNKNOWNID                = &HC0015002&

' ////////////////////////////////////////////////////////////////////////////
' // No privileges, or file is readonly.

' //
' // MessageId: DTS_E_CANTWRITETOFILE
' //
' // MessageText:
' //
' //  The file, "%1!s!", could not be opened for writing. The file could be read-only, or you do not have the correct permissions.
' //
%DTS_E_CANTWRITETOFILE            = &HC0015004&

' ////////////////////////////////////////////////////////////////////////////
' // The result is not correctly specified.

' //
' // MessageId: DTS_E_NOROWSETRETURNED
' //
' // MessageText:
' //
' //  No result rowset is associated with the execution of this query. The result is not correctly specified.
' //
%DTS_E_NOROWSETRETURNED           = &HC0015005&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the server or proxy URL is either null or of invalid format. Valid URL format - http:' //ServerName:Port/ResourcePath or https:' //ServerName:Port/ResourcePath

' //
' // MessageId: DTS_E_INVALIDURL
' //
' // MessageText:
' //
' //  The URL specified is not valid. This can happen when the server or proxy URL is null, or in an incorrect format. A valid URL format is in the form of http:' //ServerName:Port/ResourcePath or https:' //ServerName:Port/ResourcePath.
' //
%DTS_E_INVALIDURL                 = &HC0016001&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when a scheme other than http or https was specified or the URL is of invalid format. Valid URL format - http:' //ServerName:Port/ResourcePath or https:' //ServerName:Port/ResourcePath.

' //
' // MessageId: DTS_E_INVALIDSCHEME
' //
' // MessageText:
' //
' //  The URL %1!s! is not valid. This can happen when a scheme other than http or https is specified, or the URL is in an incorrect format. A valid URL format is in the form of http:' //ServerName:Port/ResourcePath or https:' //ServerName:Port/ResourcePath.
' //
%DTS_E_INVALIDSCHEME              = &HC0016002&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the server doesn't exist or the proxy settings are incorrect.

' //
' // MessageId: DTS_E_WINHTTPCANNOTCONNECT
' //
' // MessageText:
' //
' //  Connection to server %1!s! cannot be established. This error can occur when the server does not exist, or the proxy settings are incorrect.
' //
%DTS_E_WINHTTPCANNOTCONNECT       = &HC0016003&

' //
' // MessageId: DTS_E_CONNECTIONTERMINATED
' //
' // MessageText:
' //
' //  The connection with the server has been reset or terminated. Try again later.
' //
%DTS_E_CONNECTIONTERMINATED       = &HC0016004&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the login credentials provided are incorrect.

' //
' // MessageId: DTS_E_LOGINFAILURE
' //
' // MessageText:
' //
' //  The login attempt failed for "%1!s!". This error occurs when the login credentials provided are incorrect. Verify the login credentials.
' //
%DTS_E_LOGINFAILURE               = &HC0016005&

' //
' // MessageId: DTS_E_INVALIDSERVERNAME
' //
' // MessageText:
' //
' //  The server name specified in the URL %1!s! cannot be resolved.
' //
%DTS_E_INVALIDSERVERNAME          = &HC0016006&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the user has not provided login credentials or the credentials are wrong.

' //
' // MessageId: DTS_E_PROXYAUTH
' //
' // MessageText:
' //
' //  Proxy authentication failed. This error occurs when login credentials are not provided, or the credentials are incorrect.
' //
%DTS_E_PROXYAUTH                  = &HC0016007&

' //
' // MessageId: DTS_E_SECUREFAILURE
' //
' // MessageText:
' //
' //  SSL certificate response obtained from the server was not valid. Cannot process the request.
' //
%DTS_E_SECUREFAILURE              = &HC0016008&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the timeout specified was too less or a connection to the server/proxy could not be established. Make sure that the server and proxy url's are proper.

' //
' // MessageId: DTS_E_TIMEOUT
' //
' // MessageText:
' //
' //  The request has timed out.This error can occur when the timeout specified was too short, or a connection to the server or proxy cannot be established. Ensure that the server and proxy URL are corrrect.
' //
%DTS_E_TIMEOUT                    = &HC0016009&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the server is expecting a SSL client certificate and user has either provided an invalid certificate or has not provided a certificate. Please configure a client certificate for this connection and retry.

' //
' // MessageId: DTS_E_CLIENTAUTH
' //
' // MessageText:
' //
' //  Client certificate is missing. This error occurs when the server is expecting an SSL client certificate and the user has provided an invalid certificate, or has not provided a certificate. A client certificate must be configured for this connection.
' //
%DTS_E_CLIENTAUTH                 = &HC001600A&

' //
' // MessageId: DTS_E_REDIRECTFAILURE
' //
' // MessageText:
' //
' //  The specified server, URL %1!s!, has a redirect and the redirect request failed.
' //
%DTS_E_REDIRECTFAILURE            = &HC001600B&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the user has not provided login credentials or the credentials are wrong.

' //
' // MessageId: DTS_E_SERVERAUTH
' //
' // MessageText:
' //
' //  Server authentication failed. This error occurs when login credentials are not provided, or the credentials are incorrect.
' //
%DTS_E_SERVERAUTH                 = &HC001600C&

' //
' // MessageId: DTS_E_WINHTTPUNKNOWNERROR
' //
' // MessageText:
' //
' //  Request cannot be processed. Try again later.
' //
%DTS_E_WINHTTPUNKNOWNERROR        = &HC001600D&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the server is experiencing some problems.

' //
' // MessageId: DTS_E_UNKNOWNSTATUSCODE
' //
' // MessageText:
' //
' //  Server returned status code - %1!u! : %2!s!. This error occurs when the server is experiencing problems.
' //
%DTS_E_UNKNOWNSTATUSCODE          = &HC001600E&

' //
' // MessageId: DTS_E_WINHTTPNOTSUPPORTED
' //
' // MessageText:
' //
' //  This platform is not supported by WinHttp services.
' //
%DTS_E_WINHTTPNOTSUPPORTED        = &HC001600F&

' ////////////////////////////////////////////////////////////////////////////
' // Timeout should be in the range %1!d! to %2!d! (in seconds).

' //
' // MessageId: DTS_E_INVALIDTIMEOUT
' //
' // MessageText:
' //
' //  Timeout value is not valid. Timeout should be in the range of %1!d! to %2!d! (in seconds).
' //
%DTS_E_INVALIDTIMEOUT             = &HC0016010&

' ////////////////////////////////////////////////////////////////////////////
' // Chunksize should be in the range %1!d! to %2!d! (in kb).

' //
' // MessageId: DTS_E_INVALIDCHUNKSIZE
' //
' // MessageText:
' //
' //  The chunk size is not valid. The ChunkSize property should be in the range of %1!d! to %2!d! (in KB).
' //
%DTS_E_INVALIDCHUNKSIZE           = &HC0016011&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the client certificate provided was not found in the Personal certificate store. Please try again with a valid client certificate.

' //
' // MessageId: DTS_E_CERTERROR
' //
' // MessageText:
' //
' //  Error processing client certificate. This error can occur when the client certificate provided was not found in the Personal Certificate Store. Verify that the client certificate is valid.
' //
%DTS_E_CERTERROR                  = &HC0016012&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when - 1. The specified resource needs "https" access. 2. The certificate validity period has expired. 3. Certificate has been revoked or revocation could not be checked. 4. Certificate is not valid for requested usage.].

' //
' // MessageId: DTS_E_FORBIDDEN
' //
' // MessageText:
' //
' //  Server returned error code "403 - Forbidden". This error can occur when the specified resource needs "https" access, but the certificate validity period has expired, the certificate is not valid for the use requested,
' //  or the certificate has been revoked or revocation can not be checked.
' //
%DTS_E_FORBIDDEN                  = &HC0016013&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when an invalid proxy was specified. HTTP Connection Manager only supports CERN type proxies.

' //
' // MessageId: DTS_E_WINHTTPOPEN
' //
' // MessageText:
' //
' //  Error initializing HTTP session with proxy "%1!s!". This error can occur when an invalid proxy was specified. HTTP connection manager only supports CERN-type proxies.
' //
%DTS_E_WINHTTPOPEN                = &HC0016014&

' //
' // MessageId: DTS_E_OPENCERTSTORE
' //
' // MessageText:
' //
' //  Error opening certificate store.
' //
%DTS_E_OPENCERTSTORE              = &HC0016015&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when there is a cryptographic error, most often when the right key is not available

' //
' // MessageId: DTS_E_UNPROTECTXMLFAILED
' //
' // MessageText:
' //
' //  Failed to decrypt protected XML node "%1!s!" with error 0x%2!8.8X! "%3!s!". You may not be authorized to access this information. This error occurs when there is a cryptographic error. Verify that the correct key is available.
' //
%DTS_E_UNPROTECTXMLFAILED         = &HC0016016&

' //
' // MessageId: DTS_E_UNPROTECTCONNECTIONSTRINGFAILED
' //
' // MessageText:
' //
' //  Failed to decrypt protected connection string for server "%1!s!" with error 0x%2!8.8X! "%3!s!". You may not be authorized to access this information. This error occurs when there is a cryptographic error. Verify that the correct key is available.
' //
%DTS_E_UNPROTECTCONNECTIONSTRINGFAILED = &HC0016017&

' ////////////////////////////////////////////////////////////////////////////
' // Occurs when VersionMajor, VersionMinor or VersionBuild properties of the package are set to negative value

' //
' // MessageId: DTS_E_NEGATIVEVERSION
' //
' // MessageText:
' //
' //  The version number cannot be negative. This error occurs when the VersionMajor, VersionMinor, or VersionBuild property of the package is set to a negative value.
' //
%DTS_E_NEGATIVEVERSION            = &HC0016018&

' ////////////////////////////////////////////////////////////////////////////
' // Internal error code, shouldn't be ever returned to user.

' //
' // MessageId: DTS_E_PACKAGEMIGRATED
' //
' // MessageText:
' //
' //  The package has been migrated to a later version during loading. It must be reloaded to complete the process. This is an internal error code.
' //
%DTS_E_PACKAGEMIGRATED            = &HC0016019&

' //
' // MessageId: DTS_E_PACKAGEMIGRATIONFAILED
' //
' // MessageText:
' //
' //  Package migration from version %1!d! to version %2!d! failed with error 0x%3!8.8X! "%4!s!".
' //
%DTS_E_PACKAGEMIGRATIONFAILED     = &HC0016020&

' //
' // MessageId: DTS_E_PACKAGEMIGRATIONMODULELOAD
' //
' // MessageText:
' //
' //  Package migration module has failed to load.
' //
%DTS_E_PACKAGEMIGRATIONMODULELOAD = &HC0016021&

' //
' // MessageId: DTS_E_PACKAGEMIGRATIONMODULE
' //
' // MessageText:
' //
' //  Package migration module has failed.
' //
%DTS_E_PACKAGEMIGRATIONMODULE     = &HC0016022&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when default persistence is unable to determine which objects are on the hosted object

' //
' // MessageId: DTS_E_CANTDETERMINEWHICHPROPTOPERSIST
' //
' // MessageText:
' //
' //  Unable to persist object using default persistence. This error occurs when the default persistence is unable to determine which objects are on the hosted object.
' //
%DTS_E_CANTDETERMINEWHICHPROPTOPERSIST = &HC0016023&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when there is an attempt to add or remove an object from a collection while the package is executing.

' //
' // MessageId: DTS_E_CANTADDREMOVEWHENEXECUTING
' //
' // MessageText:
' //
' //  Cannot add or remove an element from a package in runtime mode. This error occurs when an attempt is made to add or remove an object from a collection while the package is executing.
' //
%DTS_E_CANTADDREMOVEWHENEXECUTING = &HC0016024&

' ////////////////////////////////////////////////////////////////////////////
' // This happens if the default saved xml of an extensible object was changed in such a way that a saved object is no longer found. Or if the extensible object itself changed.

' //
' // MessageId: DTS_E_NODENOTFOUND
' //
' // MessageText:
' //
' //  Node cannot be found in custom default persistence. This error occurs if the default saved XML of an extensible object was changed in a way that a saved object is no longer found, or if the extensible object itself changed.
' //
%DTS_E_NODENOTFOUND               = &HC0016025&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when certain collections are modified while the package is validating or executing. These collections should only be modified during package design time to avoid possible race conditions.

' //
' // MessageId: DTS_E_COLLECTIONLOCKED
' //
' // MessageText:
' //
' //  This collection cannot be modified during package validation or execution.
' //
%DTS_E_COLLECTIONLOCKED           = &HC0016026&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when users try to modify a collection at execution time.

' //
' // MessageId: DTS_E_COLLOCKED
' //
' // MessageText:
' //
' //  The "%1!s!" collection cannot be modified during package validation or execution. "%2!s!" cannot be added to the collection.
' //
%DTS_E_COLLOCKED                  = &HC0016027&

' //
' // MessageId: DTS_E_FTPNOTCONNECTED
' //
' // MessageText:
' //
' //  Connection with the FTP server has not been established.
' //
%DTS_E_FTPNOTCONNECTED            = &HC0016029&

' //
' // MessageId: DTS_E_FTPERROR
' //
' // MessageText:
' //
' //  An error occurred in the requested FTP operation. Detailed error description: %1!s!.
' //
%DTS_E_FTPERROR                   = &HC001602A&

' //
' // MessageId: DTS_E_FTPINVALIDRETRIES
' //
' // MessageText:
' //
' //  The number of retries is not valid. The number of retries should be between %1!d! and %2!d!.
' //
%DTS_E_FTPINVALIDRETRIES          = &HC001602B&

' ////////////////////////////////////////////////////////////////////////////
' // FTP Connection Manager needs the named DLL for it's functioning

' //
' // MessageId: DTS_E_LOADWININET
' //
' // MessageText:
' //
' //  The FTP connection manager needs the following DLL to function: %1!s!.
' //
%DTS_E_LOADWININET                = &HC001602C&

' ////////////////////////////////////////////////////////////////////////////
' // ConnectionString is of the format ServerName:Port. Port should be an integer value between %1!d! and %2!d!.

' //
' // MessageId: DTS_E_FTPINVALIDCONNECTIONSTRING
' //
' // MessageText:
' //
' //  The port specified in the connection string is not valid. The ConnectionString format is ServerName:Port. Port should be an integer value between %1!d! and %2!d!.
' //
%DTS_E_FTPINVALIDCONNECTIONSTRING = &HC001602D&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the specified path is invalid or the folder already exists or you do not have sufficient permissions.

' //
' // MessageId: DTS_E_FTPCREATEFOLDER
' //
' // MessageText:
' //
' //  Creating folder "%1!s!" ... %2!s!.
' //
%DTS_E_FTPCREATEFOLDER            = &HC001602E&

' ////////////////////////////////////////////////////////////////////////////
' // This could happend when the specified path is invalid or the folder does not exist or you do not have sufficient permissions.

' //
' // MessageId: DTS_E_FTPDELETEFOLDER
' //
' // MessageText:
' //
' //  Deleting folder "%1!s!" ... %2!s!.
' //
%DTS_E_FTPDELETEFOLDER            = &HC001602F&

' ////////////////////////////////////////////////////////////////////////////
' // This could happend when the specified path is invalid or you do not have sufficient permissions.

' //
' // MessageId: DTS_E_FTPCHANGEFOLDER
' //
' // MessageText:
' //
' //  Changing current directory to "%1!s!". %2!s!.
' //
%DTS_E_FTPCHANGEFOLDER            = &HC0016030&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when performing a Send or Receive operation with no files specified for transfer.

' //
' // MessageId: DTS_E_FTPFILESEMPTY
' //
' // MessageText:
' //
' //  No files to transfer. This error can occur when performing a Send or Receive operation and no files are specified for the transfer.
' //
%DTS_E_FTPFILESEMPTY              = &HC0016031&

' ////////////////////////////////////////////////////////////////////////////
' // This could happend when the local path specified is null.

' //
' // MessageId: DTS_E_FTPINVALIDLOCALPATH
' //
' // MessageText:
' //
' //  Specified local path is not valid. Specify a valid local path. This can occur when the specified local path is null.
' //
%DTS_E_FTPINVALIDLOCALPATH        = &HC0016032&

' //
' // MessageId: DTS_E_FTPNOFILESTODELETE
' //
' // MessageText:
' //
' //  No files specified to delete.
' //
%DTS_E_FTPNOFILESTODELETE         = &HC0016033&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when persisted certificate data is corrupted.

' //
' // MessageId: DTS_E_WINHTTPCERTDECODE
' //
' // MessageText:
' //
' //  Internal error occurred while loading the certificate. This error could occur when the certificate data is invalid.
' //
%DTS_E_WINHTTPCERTDECODE          = &HC0016034&

' ////////////////////////////////////////////////////////////////////////////
' // No other information available.

' //
' // MessageId: DTS_E_WINHTTPCERTENCODE
' //
' // MessageText:
' //
' //  Internal error occurred while saving the certificate data.
' //
%DTS_E_WINHTTPCERTENCODE          = &HC0016035&

' ////////////////////////////////////////////////////////////////////////////
' // ID of the package and ID in the checkpoint file do not match.

' //
' // MessageId: DTS_E_CHECKPOINTMISMATCH
' //
' // MessageText:
' //
' //  Checkpoint file "%1!s!" does not match this package. The ID of the package and the ID in the checkpoint file do not match.
' //
%DTS_E_CHECKPOINTMISMATCH         = &HC0016049&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when checkpoint file exists, the package is set to NOT use checkpoint and it is set to save checkpoints. We refuse to overwrite existing file.

' //
' // MessageId: DTS_E_CHECKPOINTFILEALREADYEXISTS
' //
' // MessageText:
' //
' //  An existing checkpoint file is found with contents that do not appear to be for this package, so the file cannot be overwritten to start saving new checkpoints. Remove the existing checkpoint file and try again.
' //  This error occurs when a checkpoint file exists, the package is set to not use a checkpoint file, but to save checkpoints. The existing checkpoint file will not be overwritten.
' //
%DTS_E_CHECKPOINTFILEALREADYEXISTS = &HC001604A&

' //
' // MessageId: DTS_E_CHECKPOINTFILELOCKED
' //
' // MessageText:
' //
' //  The checkpoint file "%1!s!" is locked by another process. This may occur if another instance of this package is currently executing.
' //
%DTS_E_CHECKPOINTFILELOCKED       = &HC001604B&

' //
' // MessageId: DTS_E_OPENCHECKPOINTFILE
' //
' // MessageText:
' //
' //  Checkpoint file "%1!s!" failed to open due to error 0x%2!8.8X! "%3!s!".
' //
%DTS_E_OPENCHECKPOINTFILE         = &HC001604C&

' //
' // MessageId: DTS_E_CREATECHECKPOINTFILE
' //
' // MessageText:
' //
' //  Checkpoint file "%1!s!" failed during creation due to error 0x%2!8.8X! "%3!s!".
' //
%DTS_E_CREATECHECKPOINTFILE       = &HC001604D&

' //
' // MessageId: DTS_E_FTPINVALIDPORT
' //
' // MessageText:
' //
' //  The FTP Port contains an invalid value. The FTP Port value should be an integer between %1!d! and %2!d!.
' //
%DTS_E_FTPINVALIDPORT             = &HC0016050&

' ////////////////////////////////////////////////////////////////////////////
' // Please verify the SSIS Service is installed and enabled

' //
' // MessageId: DTS_E_CONNECTTOSERVERFAILED
' //
' // MessageText:
' //
' //  Connect to SSIS Service on machine "%1!s!" failed:%n %2!s!.
' //
%DTS_E_CONNECTTOSERVERFAILED      = &HC00160AA&

' //
' // MessageId: DTS_E_PROPERTYEXPRESSIONSDISABLEDONVARIABLES
' //
' // MessageText:
' //
' //  The Expression property is not supported on Variable objects. Use the EvaluateAsExpression property instead.
' //
%DTS_E_PROPERTYEXPRESSIONSDISABLEDONVARIABLES = &HC0017002&

' ////////////////////////////////////////////////////////////////////////////
' // User should change the expression.

' //
' // MessageId: DTS_E_PROPERTYEXPRESSIONEVAL
' //
' // MessageText:
' //
' //  The expression "%1!s!" on property "%2!s!" cannot be evaluated. Modify the expression to be valid.
' //
%DTS_E_PROPERTYEXPRESSIONEVAL     = &HC0017003&

' ////////////////////////////////////////////////////////////////////////////
' // Expression evaluated, but could not be set.

' //
' // MessageId: DTS_E_PROPERTYEXPRESSIONSET
' //
' // MessageText:
' //
' //  The result of the expression "%1!s!" on property "%2!s!" cannot be written to the property. The expression was evaluated, but cannot be set on the property.
' //
%DTS_E_PROPERTYEXPRESSIONSET      = &HC0017004&

' ////////////////////////////////////////////////////////////////////////////
' // User should change the expression.

' //
' // MessageId: DTS_E_FORLOOPEVALEXPRESSIONINVALID
' //
' // MessageText:
' //
' //  The evaluation expression for the loop is not valid. The expression needs to be modified. There should be additional error messages.
' //
%DTS_E_FORLOOPEVALEXPRESSIONINVALID = &HC0017005&

' ////////////////////////////////////////////////////////////////////////////
' // The expression must evaluate to true or false, make it a boolean expression.

' //
' // MessageId: DTS_E_EXPRESSIONNOTBOOLEAN
' //
' // MessageText:
' //
' //  The expression "%1!s!" must evaluate to True or False. Change the expression to evaluate to a Boolean value.
' //
%DTS_E_EXPRESSIONNOTBOOLEAN       = &HC0017006&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the expression on the for loop is empty. User should add an expression.

' //
' // MessageId: DTS_E_FORLOOPHASNOEXPRESSION
' //
' // MessageText:
' //
' //  There is no expression for the loop to evaluate. This error occurs when the expression on the For Loop is empty. Add an expression.
' //
%DTS_E_FORLOOPHASNOEXPRESSION     = &HC0017007&

' ////////////////////////////////////////////////////////////////////////////
' // User should change the expression.

' //
' // MessageId: DTS_E_FORLOOPASSIGNEXPRESSIONINVALID
' //
' // MessageText:
' //
' //  The assignment expression for the loop is not valid and needs to be modified. There should be additional error messages.
' //
%DTS_E_FORLOOPASSIGNEXPRESSIONINVALID = &HC0017008&

' //
' // MessageId: DTS_E_FORLOOPINITEXPRESSIONINVALID
' //
' // MessageText:
' //
' //  The initialization expression for the loop is not valid and needs to be modified. There should be additional error messages.
' //
%DTS_E_FORLOOPINITEXPRESSIONINVALID = &HC0017009&

' ////////////////////////////////////////////////////////////////////////////
' // SSIS version number can not be greater than current version number.

' //
' // MessageId: DTS_E_INVALIDVERSIONNUMBER
' //
' // MessageText:
' //
' //  The version number in the package is not valid. The version number cannot be greater than current version number.
' //
%DTS_E_INVALIDVERSIONNUMBER       = &HC001700A&

' ////////////////////////////////////////////////////////////////////////////
' // SSIS version number is negative.

' //
' // MessageId: DTS_E_INVALIDVERNUMCANTBENEGATIVE
' //
' // MessageText:
' //
' //  The version number in the package is not valid. The version number is negative.
' //
%DTS_E_INVALIDVERNUMCANTBENEGATIVE = &HC001700C&

' //
' // MessageId: DTS_E_PACKAGEUPDATEDISABLED
' //
' // MessageText:
' //
' //  The package has an older format version, but automatic package format upgrading is disabled.
' //
%DTS_E_PACKAGEUPDATEDISABLED      = &HC001700D&

' ////////////////////////////////////////////////////////////////////////////
' // A string contenation or other operation caused a result value that is greater than the maximum size allowed.

' //
' // MessageId: DTS_E_EXPREVALTRUNCATIONASERROR
' //
' // MessageText:
' //
' //  A truncation occurred during evaluation of the expression.
' //
%DTS_E_EXPREVALTRUNCATIONASERROR  = &HC001700E&

' ////////////////////////////////////////////////////////////////////////////
' // Wrapper has a property called ExecutionValueVariable.  It get's set by the package designer at design time to point to a SSIS Variable.  When a task completes execution, it set's a property
' // called ExecutionValue that the wrapper get's.  It then tries to set the value of the SSIS Variable defined in ExecutionValueVariable to the value in this property.  This error happens when the set on the variable fails.

' //
' // MessageId: DTS_E_FAILEDSETEXECVALVARIABLE
' //
' // MessageText:
' //
' //  The wrapper was unable to set the value of the variable specified in the ExecutionValueVariable property.
' //
%DTS_E_FAILEDSETEXECVALVARIABLE   = &HC0019001&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the expression on a variable fails evaluation

' //
' // MessageId: DTS_E_VARIABLEEXPRESSIONERROR
' //
' // MessageText:
' //
' //  The expression for variable "%1!s!" failed evaluation. There was an error in the expression.
' //
%DTS_E_VARIABLEEXPRESSIONERROR    = &HC0019004&

' ////////////////////////////////////////////////////////////////////////////
' // Retain was true on Connection Manager, but AcquireConnection was called with non-NULL pTxn parameter.

' //
' // MessageId: DTS_E_TXNSPECINVALID
' //
' // MessageText:
' //
' //  Transaction cannot be specified when a retained connection is used. This error occurs when Retain is set to TRUE on the connection manager, but AcquireConnection was called with a non-null transaction parameter.
' //
%DTS_E_TXNSPECINVALID             = &HC001A003&

' ////////////////////////////////////////////////////////////////////////////
' // Retained connections can be used under exactly one transaction context.

' //
' // MessageId: DTS_E_INCOMPATIBLETRANSACTIONCONTEXT
' //
' // MessageText:
' //
' //  Incompatible transaction context was specified for a retained connection. This connection has been established under a different transaction context. Retained connections can be used under exactly one transaction context.
' //
%DTS_E_INCOMPATIBLETRANSACTIONCONTEXT = &HC001A004&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the client calls resume but the package is not suspended.

' //
' // MessageId: DTS_E_NOTSUSPENDED
' //
' // MessageText:
' //
' //  Resume call failed because the package is not suspended. This occurs when the client calls resume, but the package is not suspended.
' //
%DTS_E_NOTSUSPENDED               = &HC001B001&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the client calls Execute on a container that is still executing from the last Execute call.

' //
' // MessageId: DTS_E_ALREADYEXECUTING
' //
' // MessageText:
' //
' //  Execute call failed because the executable is already executing. This error occurs when the client calls Execute on a container that is still executing from the last Execute call.
' //
%DTS_E_ALREADYEXECUTING           = &HC001B002&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the client calls Suspend or Resume on an executable that is not currently processing an Execute call.

' //
' // MessageId: DTS_E_NOTEXECUTING
' //
' // MessageText:
' //
' //  Suspend or Resume call failed because the executable is not executing, or is not the top-level executable. This occurs when the client calls Suspend or Resume on an executable that is not currently processing an Execute call.
' //
%DTS_E_NOTEXECUTING               = &HC001B003&

' ////////////////////////////////////////////////////////////////////////////
' // Invalid or non-existant file specified in the ForEachFileEnumerator.

' //
' // MessageId: DTS_E_INVALIDFILE
' //
' // MessageText:
' //
' //  The file specified in the For Each File enumerator is not valid. Check that the file specified in the For Each File enumerator exists.
' //
%DTS_E_INVALIDFILE                = &HC001C002&

' //
' // MessageId: DTS_E_VALUEINDEXNOTINTEGER
' //
' // MessageText:
' //
' //  The value index is not an integer . Mapping a For Each Variable number %1!d! to the variable "%2!s!".
' //
%DTS_E_VALUEINDEXNOTINTEGER       = &HC001C010&

' //
' // MessageId: DTS_E_VALUEINDEXNEGATIVE
' //
' // MessageText:
' //
' //  The value index is negative. The ForEach Variable Mapping number %1!d! to variable "%2!s!".
' //
%DTS_E_VALUEINDEXNEGATIVE         = &HC001C011&

' //
' // MessageId: DTS_E_FOREACHVARIABLEMAPPING
' //
' // MessageText:
' //
' //  ForEach Variable Mapping number %1!d! to variable "%2!s!" cannot be applied.
' //
%DTS_E_FOREACHVARIABLEMAPPING     = &HC001C012&

' //
' // MessageId: DTS_E_OBJECTNOTINFOREACHLOOP
' //
' // MessageText:
' //
' //  Failure when adding an object to a ForEachPropertyMapping that is not a direct child of the FoEachLoop container.
' //
%DTS_E_OBJECTNOTINFOREACHLOOP     = &HC001C013&

' ////////////////////////////////////////////////////////////////////////////
' // If a user attempts to remove a variable that is a required variable, this error will occur.  Required variables are variables that are created by the runtime as communication mechanisms between tasks and the runtime.
' // For example, EventHandlers have variables that hold the values of the parameters to the event.  They're created so that tasks within the event handler can have access to the parameters.

' //
' // MessageId: DTS_E_FAILEDSYSTEMVARIABLEREMOVE
' //
' // MessageText:
' //
' //  Failed to remove a system variable. This error occurs when removing a variable that is a required variable.  Required variables are variables that are created by the runtime for communicating between tasks and the runtime.
' //
%DTS_E_FAILEDSYSTEMVARIABLEREMOVE = &HC001F001&

' ////////////////////////////////////////////////////////////////////////////
' // The user cannot change system variable read only.

' //
' // MessageId: DTS_E_CHANGESYSTEMVARIABLEREADONLYFAILED
' //
' // MessageText:
' //
' //  Changing the property of a variable failed because it is a system variable. System variables are read-only.
' //
%DTS_E_CHANGESYSTEMVARIABLEREADONLYFAILED = &HC001F002&

' ////////////////////////////////////////////////////////////////////////////
' // The user cannot change system variable names.

' //
' // MessageId: DTS_E_CHANGESYSTEMVARIABLENAMEFAILED
' //
' // MessageText:
' //
' //  Changing the name of a variable failed because it is a system variable. System variables are read-only.
' //
%DTS_E_CHANGESYSTEMVARIABLENAMEFAILED = &HC001F003&

' ////////////////////////////////////////////////////////////////////////////
' // The user cannot change system variable namespaces.

' //
' // MessageId: DTS_E_CHANGESYSTEMVARIABLENAMESPACEFAILED
' //
' // MessageText:
' //
' //  Changing the namespace of a variable failed because it is a system variable. System variables are read-only.
' //
%DTS_E_CHANGESYSTEMVARIABLENAMESPACEFAILED = &HC001F004&

' ////////////////////////////////////////////////////////////////////////////
' // Event handler names are read only.  Attempting to change the name of an event handler results in this error

' //
' // MessageId: DTS_E_EVENTHANDLERNAMEREADONLY
' //
' // MessageText:
' //
' //  Changing the event handler name failed. Event handler names are read-only.
' //
%DTS_E_EVENTHANDLERNAMEREADONLY   = &HC001F006&

' ////////////////////////////////////////////////////////////////////////////
' // The default failure when calling IDTSPath90.GetPath.  System error that cannot be remedied by the user

' //
' // MessageId: DTS_E_PATHUNKNOWN
' //
' // MessageText:
' //
' //  Cannot retrieve path to object. This is a system error.
' //
%DTS_E_PATHUNKNOWN                = &HC001F008&

' ////////////////////////////////////////////////////////////////////////////
' // Variable types are strict, except for variables of type Object.

' //
' // MessageId: DTS_E_RUNTIMEVARIABLETYPECHANGE
' //
' // MessageText:
' //
' //  The type of the value being assigned to variable "%1!s!" differs from the current variable type. Variables may not change type during execution. Variable types are strict, except for variables of type Object.
' //
%DTS_E_RUNTIMEVARIABLETYPECHANGE  = &HC001F009&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the client supplies a string for a property value that contains unprintable characters.

' //
' // MessageId: DTS_E_INVALIDSTRING
' //
' // MessageText:
' //
' //  Invalid characters in string: "%1!s!". This occurs when a string supplied for a property value contains unprintable characters.
' //
%DTS_E_INVALIDSTRING              = &HC001F010&

' ////////////////////////////////////////////////////////////////////////////
' // Different kinds of objects impose different rules. See ObjectNames.doc for details.

' //
' // MessageId: DTS_E_INVALIDOBJECTNAME
' //
' // MessageText:
' //
' //  SSIS object name is invalid. More specific errors would have been raised explaining the exact naming problem.
' //
%DTS_E_INVALIDOBJECTNAME          = &HC001F011&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when someone tries to change a property that is read only

' //
' // MessageId: DTS_E_PROPERTYREADONLY
' //
' // MessageText:
' //
' //  The property "%1!s!" is read only. This occurs when a change to a read-only property is attempted.
' //
%DTS_E_PROPERTYREADONLY           = &HC001F021&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the runtime attempts to get the type information from an object to populate the Properties collection.  The object must support type information

' //
' // MessageId: DTS_E_FAILEDGETTYPEINFO
' //
' // MessageText:
' //
' //  The object does not support type information. This occurs when the runtime attempts to get the type information from an object to populate the Properties collection.  The object must support type information.
' //
%DTS_E_FAILEDGETTYPEINFO          = &HC001F022&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the properties provider attempts to retrieve the value for a property on an object and fails, this can be caused by not having a correct IDispatch implementation or not supporting a property in the dispatch interface that is specified in IDL.

' //
' // MessageId: DTS_E_FAILEDPROPERTYGET
' //
' // MessageText:
' //
' //  An error occurred while retrieving the value of property "%1!s!". The error code is 0x%2!8.8X!.
' //
%DTS_E_FAILEDPROPERTYGET          = &HC001F023&

' //
' // MessageId: DTS_E_FAILEDPROPERTYGET_ERRORINFO
' //
' // MessageText:
' //
' //  An error occurred while retrieving the value of property "%1!s!". The error code is 0x%2!8.8X! "%3!s!".
' //
%DTS_E_FAILEDPROPERTYGET_ERRORINFO = &HC001F024&

' //
' // MessageId: DTS_E_FAILEDPROPERTYSET
' //
' // MessageText:
' //
' //  An error occurred while settting the value of property "%1!s!". The error returned is 0x%2!8.8X!.
' //
%DTS_E_FAILEDPROPERTYSET          = &HC001F025&

' //
' // MessageId: DTS_E_FAILEDPROPERTYSET_ERRORINFO
' //
' // MessageText:
' //
' //  An error occurred while setting the value of property "%1!s!". The error returned is 0x%2!8.8X! "%3!s!".
' //
%DTS_E_FAILEDPROPERTYSET_ERRORINFO = &HC001F026&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when client attempts to get the value of a property through a property object when the property is write only.

' //
' // MessageId: DTS_E_PROPERTYWRITEONLY
' //
' // MessageText:
' //
' //  The property "%1!s!" is write-only. This error occurs when trying to retreive the value of a property through a property object, but the property is write-only.
' //
%DTS_E_PROPERTYWRITEONLY          = &HC001F027&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when property object or properties collection attempts to access an IDispatch interface on an object

' //
' // MessageId: DTS_E_NODISPATCH
' //
' // MessageText:
' //
' //  The object does not implement IDispatch. This error occurs when a property object or properties collection attempts to access an IDispatch interface on an object.
' //
%DTS_E_NODISPATCH                 = &HC001F028&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when properties collection attempts to retrieve the type library for an object through its IDispatch interface

' //
' // MessageId: DTS_E_NOCONTAININGTYPELIB
' //
' // MessageText:
' //
' //  Unable to retrieve the type library of the object. This error occurs when the Properties collection attempts to retrieve the type library for an object through its IDispatch interface.
' //
%DTS_E_NOCONTAININGTYPELIB        = &HC001F029&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the runtime is unable to resolve the given name to create a task, check the name to ensure that it's correct

' //
' // MessageId: DTS_E_INVALIDTASKMONIKER
' //
' // MessageText:
' //
' //  Cannot create a task with the name "%1!s!". Verify that the name is correct.
' //
%DTS_E_INVALIDTASKMONIKER         = &HC001F02A&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when CoCreating an XML Document

' //
' // MessageId: DTS_E_FAILEDCREATEXMLDOCUMENT
' //
' // MessageText:
' //
' //  Failed to create an XML document "%1!s!".
' //
%DTS_E_FAILEDCREATEXMLDOCUMENT    = &HC001F02C&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when there is a property mapping from a variable with a value of a certain type to a property of a different type.  The property type must match the variable's type.

' //
' // MessageId: DTS_E_PMVARPROPTYPESDIFFERENT
' //
' // MessageText:
' //
' //  An error occurred because there is a property mapping from a variable to a property with a different type. The property type must match the variable type.
' //
%DTS_E_PMVARPROPTYPESDIFFERENT    = &HC001F02D&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when passing an unsupported object type to a property mapping

' //
' // MessageId: DTS_E_PMINVALIDPROPMAPTARGET
' //
' // MessageText:
' //
' //  Attempted to set property mapping to target unsupported object type. This error occurs when passing an unsupported object type to a property mapping.
' //
%DTS_E_PMINVALIDPROPMAPTARGET     = &HC001F02E&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when unsuccessfully attempting to resolve a package path to an object in the package, check the package path to ensure it's valid

' //
' // MessageId: DTS_E_COULDNOTRESOLVEPACKAGEPATH
' //
' // MessageText:
' //
' //  Cannot resolve a package path to an object in the package "%1!s!".  Verify that the package path is valid.
' //
%DTS_E_COULDNOTRESOLVEPACKAGEPATH = &HC001F02F&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when destination property on a property map is empty string, set the destination property name

' //
' // MessageId: DTS_E_PMNODESTPROPERTY
' //
' // MessageText:
' //
' //  The destination property for the property map is empty. Set the destination property name.
' //
%DTS_E_PMNODESTPROPERTY           = &HC001F030&

' ////////////////////////////////////////////////////////////////////////////
' // Posted by the package when not all is well with property mappings.

' //
' // MessageId: DTS_E_INVALIDPROPERTYMAPPINGSFOUND
' //
' // MessageText:
' //
' //  The package failed to restore at least one property mapping.
' //
%DTS_E_INVALIDPROPERTYMAPPINGSFOUND = &HC001F031&

' ////////////////////////////////////////////////////////////////////////////
' // Posted when getting a variable from variables collection using ambiguous name.

' //
' // MessageId: DTS_E_AMBIGUOUSVARIABLENAME
' //
' // MessageText:
' //
' //  The variable name is ambiguous because multiple variables with this name exist in different namespaces. Specify namespace-qualified name to prevent ambiguity.
' //
%DTS_E_AMBIGUOUSVARIABLENAME      = &HC001F032&

' ////////////////////////////////////////////////////////////////////////////
' // Posted when destination object is not a child of any sequence container.

' //
' // MessageId: DTS_E_DESTINATIONOBJECTPARENTLESS
' //
' // MessageText:
' //
' //  The destination object in a property mapping has no parent. The destination object is not a child of any sequence container. It may have been removed from the package.
' //
%DTS_E_DESTINATIONOBJECTPARENTLESS = &HC001F033&

' ////////////////////////////////////////////////////////////////////////////
' // An operation involved a property mapping that was invalid. The mapping was ignored.

' //
' // MessageId: DTS_E_INVALIDPROPERTYMAPPING
' //
' // MessageText:
' //
' //  The property mapping is not valid. The mapping is ignored.
' //
%DTS_E_INVALIDPROPERTYMAPPING     = &HC001F036&

' ////////////////////////////////////////////////////////////////////////////
' // Top level error that is returned on any failed result when removing a potential property mapping target.

' //
' // MessageId: DTS_E_PMFAILALERTREMOVE
' //
' // MessageText:
' //
' //  Failure when alerting property mappings that a target is being removed.
' //
%DTS_E_PMFAILALERTREMOVE          = &HC001F038&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when For Each property mapping fails to restore

' //
' // MessageId: DTS_E_INVALIDFOREACHPROPERTYMAPPING
' //
' // MessageText:
' //
' //  An invalid property mapping is found on the For Each Loop. This occurs when the ForEach property mapping fails to restore.
' //
%DTS_E_INVALIDFOREACHPROPERTYMAPPING = &HC001F03A&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when specifying a property on a destination object that isn't found on that object.

' //
' // MessageId: DTS_E_PMPROPERTYINVALID
' //
' // MessageText:
' //
' //  A destination property was specified on a property mapping that is invalid. This occurs when a property is specified on a destination object that in not found on that object.
' //
%DTS_E_PMPROPERTYINVALID          = &HC001F040&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the runtime is unable to resolve the given name to create a task, check the name to ensure that it's correct

' //
' // MessageId: DTS_E_INVALIDTASKMONIKERNOPARAM
' //
' // MessageText:
' //
' //  Cannot create a task from XML. This occurs when the runtime is unable to resolve the name to create a task. Verify that the name is correct.
' //
%DTS_E_INVALIDTASKMONIKERNOPARAM  = &HC001F041&

' ////////////////////////////////////////////////////////////////////////////
' // Checkpoint was successfully created in a temporary file, but the final MoveFile operation has failed.

' //
' // MessageId: DTS_E_COULDNOTREPLACECHECKPOINTFILE
' //
' // MessageText:
' //
' //  Cannot replace the existing checkpoint file with the updated checkpoint file. The checkpoint was successfully created in a temporary file, but overwriting the existing file with the new file failed.
' //
%DTS_E_COULDNOTREPLACECHECKPOINTFILE = &HC001F080&

' ////////////////////////////////////////////////////////////////////////////
' // CheckpointUsage == DTSCU_ALWAYS, but CheckpointFileName == NULL or ""

' //
' // MessageId: DTS_E_CHECKPOINTFILENOTSPECIFIED
' //
' // MessageText:
' //
' //  The package is configured to always restart from a checkpoint, but checkpoint file is not specified.
' //
%DTS_E_CHECKPOINTFILENOTSPECIFIED = &HC001F081&

' ////////////////////////////////////////////////////////////////////////////
' // Failed to load checkpoint XML file

' //
' // MessageId: DTS_E_CHECKPOINTLOADXML
' //
' // MessageText:
' //
' //  The attempt to load the XML checkpoint file "%1!s!" failed with error 0x%2!8.8X! "%3!s!". Check that the file name specified is correct, and that the file exists.
' //
%DTS_E_CHECKPOINTLOADXML          = &HC001F082&

' ////////////////////////////////////////////////////////////////////////////
' // Further execution requires checkpoint file, perhaps because CheckpointUsage = DTSCU_ALWAYS

' //
' // MessageId: DTS_E_LOADCHECKPOINT
' //
' // MessageText:
' //
' //  The package failed during execution because the checkpoint file cannot be loaded. Further execution of the package requires a checkpoint file. This error usually occurs when the
' //  CheckpointUsage property is set to ALWAYS, which specifies that the package always restarts.
' //
%DTS_E_LOADCHECKPOINT             = &HC001F083&

' ////////////////////////////////////////////////////////////////////////////
' // The Evaluation condition expression is empty.  There must be a boolean evaluation expression in the for loop

' //
' // MessageId: DTS_E_NOEVALEXPRESSION
' //
' // MessageText:
' //
' //  The evaluation condition expression on the For Loop "%1!s!" is empty. There must be a Boolean evaluation expression in the For Loop.
' //
%DTS_E_NOEVALEXPRESSION           = &HC001F185&

' ////////////////////////////////////////////////////////////////////////////
' // The expression result type could not be converted to the type of the variable to which it was to be assigned.

' //
' // MessageId: DTS_E_EXPREVALASSIGNMENTTYPEMISMATCH
' //
' // MessageText:
' //
' //  The result of the assignment expression "%1!s!" cannot be converted to a type that is compatible with the variable that it was assigned to.
' //
%DTS_E_EXPREVALASSIGNMENTTYPEMISMATCH = &HC001F186&

' ////////////////////////////////////////////////////////////////////////////
' // The expression result cannot be assigned to the variable becuase the variable is read only.

' //
' // MessageId: DTS_E_EXPREVALASSIGNMENTTOREADONLYVARIABLE
' //
' // MessageText:
' //
' //  Error using a read-only variable "%1!s!" in an assignment expression. The expression result cannot be assigned to the variable because the variable is read only. Choose a variable that can be written to, or remove the expression from this variable.
' //
%DTS_E_EXPREVALASSIGNMENTTOREADONLYVARIABLE = &HC001F187&

' ////////////////////////////////////////////////////////////////////////////
' // The expression result cannot be assigned to the variable becuase the variable was not found, or could not be locked for write access.

' //
' // MessageId: DTS_E_EXPREVALASSIGNMENTVARIABLELOCKFORWRITEFAILED
' //
' // MessageText:
' //
' //  Cannot evaluate expression "%1!s!" because the variable "%2!s!" does not exist or cannot be accessed for writing. The expression result cannot be assigned to the variable because the variable was not found, or could not be locked for write access.
' //
%DTS_E_EXPREVALASSIGNMENTVARIABLELOCKFORWRITEFAILED = &HC001F188&

' ////////////////////////////////////////////////////////////////////////////
' // The expression result type could not be converted to a type supported by the runtime engine.

' //
' // MessageId: DTS_E_EXPREVALRESULTTYPENOTSUPPORTED
' //
' // MessageText:
' //
' //  The expression "%1!s!" has a result type of "%2!s!", which cannot be converted to a supported type.
' //
%DTS_E_EXPREVALRESULTTYPENOTSUPPORTED = &HC001F189&

' ////////////////////////////////////////////////////////////////////////////
' // An unexpected error occurred when trying to convert the expression result to a type supported by the runtime engine, even though the type conversion is supported.

' //
' // MessageId: DTS_E_EXPREVALRESULTTYPECONVERSIONFAILED
' //
' // MessageText:
' //
' //  The conversion of the result of the expression"%1!s!" from type "%2!s!" to a supported type failed with error code 0x%3!8.8X!. An unexpected error occurred when trying to convert the expression result
' //  to a type supported by the runtime engine, even though the type conversion is supported.
' //
%DTS_E_EXPREVALRESULTTYPECONVERSIONFAILED = &HC001F18A&

' //
' // MessageId: DTS_E_DTSNAME_NOTNULL
' //
' // MessageText:
' //
' //  The object name is not valid. The name cannot be set to NULL.
' //
%DTS_E_DTSNAME_NOTNULL            = &HC001F200&

' //
' // MessageId: DTS_E_DTSNAME_NOTEMPTY
' //
' // MessageText:
' //
' //  The object name is not valid. The name cannot be empty.
' //
%DTS_E_DTSNAME_NOTEMPTY           = &HC001F201&

' //
' // MessageId: DTS_E_DTSNAME_LEGAL
' //
' // MessageText:
' //
' //  The object name "%1!s!" is not valid. The name cannot contain any of the following characters: / \ : [ ] . =
' //
%DTS_E_DTSNAME_LEGAL              = &HC001F202&

' //
' // MessageId: DTS_E_DTSNAME_PRINTABLE
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. The name cannot contain control characters that render it unprintable.
' //
%DTS_E_DTSNAME_PRINTABLE          = &HC001F203&

' //
' // MessageId: DTS_E_DTSNAME_NOLEADWHITESP
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. Name cannot begin with a whitespace.
' //
%DTS_E_DTSNAME_NOLEADWHITESP      = &HC001F204&

' //
' // MessageId: DTS_E_DTSNAME_NOTRAILWHITESP
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. Name cannot end with a whitespace.
' //
%DTS_E_DTSNAME_NOTRAILWHITESP     = &HC001F205&

' //
' // MessageId: DTS_E_DTSNAME_BEGINSWITHALPHA
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. Name must begin with an alphabetical character.
' //
%DTS_E_DTSNAME_BEGINSWITHALPHA    = &HC001F206&

' //
' // MessageId: DTS_E_DTSNAME_BEGINSWITHALPHAUNDERBAR
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. Name must begin with an alphabetical character or underscore "_".
' //
%DTS_E_DTSNAME_BEGINSWITHALPHAUNDERBAR = &HC001F207&

' //
' // MessageId: DTS_E_DTSNAME_ALPHADIGITUNDERBAR
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. Name must contain only alphanumeric characters or underscores "_".
' //
%DTS_E_DTSNAME_ALPHADIGITUNDERBAR = &HC001F208&

' //
' // MessageId: DTS_E_DTSNAME_VALIDFILENAME
' //
' // MessageText:
' //
' //  Object name "%1!s!" is not valid. The name cannot contain any of the following characters: / \ : ? " < > |
' //
%DTS_E_DTSNAME_VALIDFILENAME      = &HC001F209&

' //
' // MessageId: DTS_I_STARTINGTRANSACTION
' //
' // MessageText:
' //
' //  Starting distributed transaction for this container.
' //
%DTS_I_STARTINGTRANSACTION        = &H4001100A&

' //
' // MessageId: DTS_I_COMMITTINGTRANSACTION
' //
' // MessageText:
' //
' //  Committing distributed transaction started by this container.
' //
%DTS_I_COMMITTINGTRANSACTION      = &H4001100B&

' //
' // MessageId: DTS_I_ABORTINGTRANSACTION
' //
' // MessageText:
' //
' //  Aborting the current distributed transaction.
' //
%DTS_I_ABORTINGTRANSACTION        = &H4001100C&

' //
' // MessageId: DTS_MSG_PACKAGESTART
' //
' // MessageText:
' //
' //  Package "%1!s!" started.
' //
%DTS_MSG_PACKAGESTART             = &H40013000&

' //
' // MessageId: DTS_MSG_PACKAGESUCCESS
' //
' // MessageText:
' //
' //  Package "%1!s!" finished successfully.
' //
%DTS_MSG_PACKAGESUCCESS           = &H40013001&

' //
' // MessageId: DTS_MSG_PACKAGECANCEL
' //
' // MessageText:
' //
' //  Package "%1!s!" has been cancelled.
' //
%DTS_MSG_PACKAGECANCEL            = &H40013002&

' //
' // MessageId: DTS_MSG_PACKAGEFAILURE
' //
' // MessageText:
' //
' //  Package "%1!s!" failed.
' //
%DTS_MSG_PACKAGEFAILURE           = &H40013003&

' ////////////////////////////////////////////////////////////////////////////
' // The named DLL could not be found on the path, and the product requires that DLL to run.

' //
' // MessageId: DTS_MSG_CANTDELAYLOADDLL
' //
' // MessageText:
' //
' //  Module %1 cannot load DLL %2 to call entry point %3 because of error %4. The product requires that DLL to run, but the DLL could not be found on the path.
' //
%DTS_MSG_CANTDELAYLOADDLL         = &H40013004&

' //
' // MessageId: DTS_MSG_CANTDELAYLOADDLLFUNCTION
' //
' // MessageText:
' //
' //  Module %1 loaded DLL %2, but cannot find entry point %3 because of error %4. The named DLL could not be found on the path, and the product requires that DLL to run.
' //
%DTS_MSG_CANTDELAYLOADDLLFUNCTION = &H40013005&

' //
' // MessageId: DTS_I_PACKAGEMIGRATED
' //
' // MessageText:
' //
' //  The package was successfully migrated from version %1!d! to version %2!d!. It must be saved to retain migration changes.
' //
%DTS_I_PACKAGEMIGRATED            = &H40016019&

' //
' // MessageId: DTS_I_FTPRECEIVEFILE
' //
' // MessageText:
' //
' //  Receiving file "%1!s!".
' //
%DTS_I_FTPRECEIVEFILE             = &H40016025&

' //
' // MessageId: DTS_I_FTPSENDFILE
' //
' // MessageText:
' //
' //  Sending file "%1!s!".
' //
%DTS_I_FTPSENDFILE                = &H40016026&

' //
' // MessageId: DTS_I_FTPFILEEXISTS
' //
' // MessageText:
' //
' //  File "%1!s!" already exists.
' //
%DTS_I_FTPFILEEXISTS              = &H40016027&

' //
' // MessageId: DTS_I_FTPERRORLOADINGMSG
' //
' // MessageText:
' //
' //  Cannot get extra error information due to an internal error.
' //
%DTS_I_FTPERRORLOADINGMSG         = &H40016028&

' ////////////////////////////////////////////////////////////////////////////
' // This could happen when the file doesnot exist or you do not have permissions to delete the file.

' //
' // MessageId: DTS_I_FTPDELETEFILE
' //
' // MessageText:
' //
' //  The attempt to delete file "%1!s!" failed. This may occur when the file does not exist, the file name was spelled incorrectly, or you do not have permissions to delete the file.
' //
%DTS_I_FTPDELETEFILE              = &H40016036&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to configure from a registry entry.

' //
' // MessageId: DTS_I_CONFIGFROMREG
' //
' // MessageText:
' //
' //  The package is attempting to configure from a registry entry using the registry key "%1!s!".
' //
%DTS_I_CONFIGFROMREG              = &H40016037&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to configure from an environment variable.

' //
' // MessageId: DTS_I_CONFIGFROMENVVAR
' //
' // MessageText:
' //
' //  The package is attempting to configure from the environment variable "%1!s!".
' //
%DTS_I_CONFIGFROMENVVAR           = &H40016038&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to configure from an INI file.

' //
' // MessageId: DTS_I_CONFIGFROMINIFILE
' //
' // MessageText:
' //
' //  The package is attempting to configure from the .ini file "%1!s!".
' //
%DTS_I_CONFIGFROMINIFILE          = &H40016039&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to configure from an SQL server.

' //
' // MessageId: DTS_I_CONFIGFROMSQLSERVER
' //
' // MessageText:
' //
' //  The package is attempting to configure from SQL Server using the configuration string "%1!s!".
' //
%DTS_I_CONFIGFROMSQLSERVER        = &H40016040&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to configure from an XML file.

' //
' // MessageId: DTS_I_CONFIGFROMFILE
' //
' // MessageText:
' //
' //  The package is attempting to configure from the XML file "%1!s!".
' //
%DTS_I_CONFIGFROMFILE             = &H40016041&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to configure from a parent variable.

' //
' // MessageId: DTS_I_CONFIGFROMPARENTVARIABLE
' //
' // MessageText:
' //
' //  The package is attempting to configure from the parent variable "%1!s!".
' //
%DTS_I_CONFIGFROMPARENTVARIABLE   = &H40016042&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to upgrade the runtime.

' //
' // MessageId: DTS_I_ATTEMPTINGUPGRADEOFDTS
' //
' // MessageText:
' //
' //  Attempting an upgrade of SSIS from version "%1!s!" to version "%2!s!". The package is attempting to upgrade the runtime.
' //
%DTS_I_ATTEMPTINGUPGRADEOFDTS     = &H40016043&

' ////////////////////////////////////////////////////////////////////////////
' // Package is attempting to upgrade an extensible object.

' //
' // MessageId: DTS_I_ATTEMPTINGUPGRADEOFANEXTOBJ
' //
' // MessageText:
' //
' //  Attempting to upgrade "%1!s!". The package is attempting to upgrade an extensible object.
' //
%DTS_I_ATTEMPTINGUPGRADEOFANEXTOBJ = &H40016044&

' ////////////////////////////////////////////////////////////////////////////
' // Package is configured to save checkpoints.

' //
' // MessageId: DTS_I_SAVECHECKPOINTSTOFILE
' //
' // MessageText:
' //
' //  The package will be saving checkpoints to file "%1!s!" during execution. The package is configured to save checkpoints.
' //
%DTS_I_SAVECHECKPOINTSTOFILE      = &H40016045&

' ////////////////////////////////////////////////////////////////////////////
' // Package was configured to restart from checkpoint and it did.

' //
' // MessageId: DTS_I_RESTARTFROMCHECKPOINTFILE
' //
' // MessageText:
' //
' //  The package restarted from checkpoint file "%1!s!". The package was configured to restart from checkpoint.
' //
%DTS_I_RESTARTFROMCHECKPOINTFILE  = &H40016046&

' //
' // MessageId: DTS_I_CHECKPOINTSAVEDTOFILE
' //
' // MessageText:
' //
' //  Checkpoint file "%1!s!" was updated to record completion of this container.
' //
%DTS_I_CHECKPOINTSAVEDTOFILE      = &H40016047&

' //
' // MessageId: DTS_I_CHECKPOINTFILEDELETED
' //
' // MessageText:
' //
' //  Checkpoint file "%1!s!" was deleted after successful completion of the package.
' //
%DTS_I_CHECKPOINTFILEDELETED      = &H40016048&

' //
' // MessageId: DTS_I_CHECKPOINTSAVINGTOFILE
' //
' // MessageText:
' //
' //  Checkpoint file "%1!s!" update starting.
' //
%DTS_I_CHECKPOINTSAVINGTOFILE     = &H40016049&

' //
' // MessageId: DTS_I_CHOSENMAXEXECUTABLES
' //
' // MessageText:
' //
' //  Based on the system configuration, the maximum concurrent executables are set to %1!d!.
' //
%DTS_I_CHOSENMAXEXECUTABLES       = &H40016051&

' //
' // MessageId: DTS_I_MAXEXECUTABLES
' //
' // MessageText:
' //
' //  Maximum concurrent executables are set to %1!d!.
' //
%DTS_I_MAXEXECUTABLES             = &H40016052&

' //
' // MessageId: DTS_I_PACKAGESTART
' //
' // MessageText:
' //
' //  Beginning of package execution.
' //
%DTS_I_PACKAGESTART               = &H40016053&

' //
' // MessageId: DTS_I_PACKAGEEND
' //
' // MessageText:
' //
' //  End of package execution.
' //
%DTS_I_PACKAGEEND                 = &H40016054&

' ////////////////////////////////////////////////////////////////////////////
' // This is used as a return value from functions that encountered warnings

' //
' // MessageId: DTS_W_GENERICWARNING
' //
' // MessageText:
' //
' //  Warning(s) raised. There should be more specific warnings preceding this one that explains the specifics of the warning(s).
' //
%DTS_W_GENERICWARNING             = &H80010015&

' ////////////////////////////////////////////////////////////////////////////
' // Happens we are unable to CoCreate an instance of CLSIDDOM_Document.  Check to see that the DOM is installed and registered correctly.

' //
' // MessageId: DTS_W_FAILEDXMLDOCCREATION
' //
' // MessageText:
' //
' //  Cannot create an XML document object instance. Verify that MSXML is installed and registered correctly.
' //
%DTS_W_FAILEDXMLDOCCREATION       = &H80012010&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the IXMLDOMDoc::Load call fails.  Check the XML configuration file, may be malformed or invalid

' //
' // MessageId: DTS_W_FAILEDCONFIGLOAD
' //
' // MessageText:
' //
' //  Cannot load the XML configuration file. The XML configuration file may be malformed or not valid.
' //
%DTS_W_FAILEDCONFIGLOAD           = &H80012011&

' ////////////////////////////////////////////////////////////////////////////
' // The filename specified in the configuration was invalid.  Check the configuration filename.

' //
' // MessageId: DTS_W_CONFIGFILENAMEINVALID
' //
' // MessageText:
' //
' //  The configuration file name "%1" is not valid. Check the configuration file name.
' //
%DTS_W_CONFIGFILENAMEINVALID      = &H80012012&

' ////////////////////////////////////////////////////////////////////////////
' // Happens after the configuration file successfully loads, but for some reason is not formatted correctly.  An element may be missing or corrupt

' //
' // MessageId: DTS_W_CONFIGFILEINVALID
' //
' // MessageText:
' //
' //  The configuration file loaded, but is not valid. The file is not formatted correctly, may be missing an element, or may be damaged.
' //
%DTS_W_CONFIGFILEINVALID          = &H80012013&

' ////////////////////////////////////////////////////////////////////////////
' // The configuration specified a file that could not be found.  Check the directory and file name.

' //
' // MessageId: DTS_W_CONFIGFILENOTFOUND
' //
' // MessageText:
' //
' //  The configuration file "%1!s!" cannot be found. Check the directory and file name.
' //
%DTS_W_CONFIGFILENOTFOUND         = &H80012014&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when one of the configuration entries specifies a registry key that isn't available.  Check the registry to ensure that the key is there.

' //
' // MessageId: DTS_W_CONFIGKEYNOTFOUND
' //
' // MessageText:
' //
' //  Configuration registry key "%1!s!" was not found. A configuration entry specifies a registry key that is not available. Check the registry to ensure that the key is there.
' //
%DTS_W_CONFIGKEYNOTFOUND          = &H80012015&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when one of the configuration file configuration entries has an invalid ConfiguredType specified

' //
' // MessageId: DTS_W_CONFIGTYPEINVALID
' //
' // MessageText:
' //
' //  The configuration type in one of the the configuration entries was not valid. Valid types are listed in the DTSConfigurationType enumeration.
' //
%DTS_W_CONFIGTYPEINVALID          = &H80012016&

' ////////////////////////////////////////////////////////////////////////////
' // Returned when attempting to resolve a package path to an object that can not be found

' //
' // MessageId: DTS_W_CANNOTFINDOBJECT
' //
' // MessageText:
' //
' //  The package path referenced an object that cannot be found: "%1!s!". This occurs when an attempt is made to resolve a package path to an object that cannot be found.
' //
%DTS_W_CANNOTFINDOBJECT           = &H80012017&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when one of the configuration file configuration entries has an invalid format: There was no \package delimiter

' //
' // MessageId: DTS_W_CONFIGFORMATINVALID_PACKAGEDELIMITER
' //
' // MessageText:
' //
' //  The configuration entry, "%1!s!", has an incorrect format because it does not begin with the package delimiter. Prepend "\package" to the package path.
' //
%DTS_W_CONFIGFORMATINVALID_PACKAGEDELIMITER = &H80012018&

' ////////////////////////////////////////////////////////////////////////////
' // Returned for various formatting errors like invalid array delimiter or missing delimiter

' //
' // MessageId: DTS_W_CONFIGFORMATINVALID
' //
' // MessageText:
' //
' //  The configuration entry "%1!s!" had an incorrect format. This can occur because of a missing delimiter or formatting errors, like an invalid array delimiter.
' //
%DTS_W_CONFIGFORMATINVALID        = &H80012019&

' //
' // MessageId: DTS_W_NOPARENTVARIABLES
' //
' // MessageText:
' //
' //  Configuration from a parent variable "%1!s!" did not occur because there was no parent variable collection.
' //
%DTS_W_NOPARENTVARIABLES          = &H8001201A&

' ////////////////////////////////////////////////////////////////////////////
' // Happens after the configuration file fails to load

' //
' // MessageId: DTS_W_CONFIGFILEFAILEDIMPORT
' //
' // MessageText:
' //
' //  Failure importing configuration file: "%1!s!".
' //
%DTS_W_CONFIGFILEFAILEDIMPORT     = &H8001201B&

' //
' // MessageId: DTS_W_PARENTVARIABLENOTFOUND
' //
' // MessageText:
' //
' //  Configuration from a parent variable "%1!s!" did not occur because there was no parent variable. Error code: 0x%2!8.8X!.
' //
%DTS_W_PARENTVARIABLENOTFOUND     = &H8001201C&

' ////////////////////////////////////////////////////////////////////////////
' // There were no configurations in the configuration file

' //
' // MessageId: DTS_W_CONFIGFILEEMPTY
' //
' // MessageText:
' //
' //  The configuration file was empty and contained no configuration entries.
' //
%DTS_W_CONFIGFILEEMPTY            = &H8001201D&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when a user attempts to set a configuration object's type property to an invalid configuration type

' //
' // MessageId: DTS_W_INVALIDCONFIGURATIONTYPE
' //
' // MessageText:
' //
' //  The configuration type for configuration "%1!s!" is not valid. This may occur when an attempt is made to set the type property of a configuration object to an invalid configuration type.
' //
%DTS_W_INVALIDCONFIGURATIONTYPE   = &H80012023&

' ////////////////////////////////////////////////////////////////////////////
' // Add a value called ConfigType to the registry key and should have a string value of one of the following "Variable", "Property", "ConnectionManager", "LoggingProvider", or "ForEachEnumerator"

' //
' // MessageId: DTS_W_REGISTRYCONFIGURATIONTYPENOTFOUND
' //
' // MessageText:
' //
' //  The configuration type for the registry configuration was not found in key "%1!s!". Add a value called ConfigType to the registry key and give it a a string value of  "Variable", "Property", "ConnectionManager", "LoggingProvider", or "ForEachEnumerator".
' //
%DTS_W_REGISTRYCONFIGURATIONTYPENOTFOUND = &H80012025&

' ////////////////////////////////////////////////////////////////////////////
' // Add a value called Value to the registry key and should be of type DWORD or string

' //
' // MessageId: DTS_W_REGISTRYCONFIGURATIONVALUENOTFOUND
' //
' // MessageText:
' //
' //  The configuration value for the registry configuration was not found in key "%1!s!". Add a value called Value to the registry key of type DWORD or String.
' //
%DTS_W_REGISTRYCONFIGURATIONVALUENOTFOUND = &H80012026&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when attempting to set the destination property or variable fails.  Check the destination property or variable.

' //
' // MessageId: DTS_W_PROCESSCONFIGURATIONFAILEDSET
' //
' // MessageText:
' //
' //  Process configuration failed to set the destination at the package path of "%1!s!". This occurs when attempting to set the destination property or variable fails. Check the destination property or variable.
' //
%DTS_W_PROCESSCONFIGURATIONFAILEDSET = &H80012028&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when attempting to retrieve the configured value from an ini file.  Check the section in the ini file.

' //
' // MessageId: DTS_W_CONFIGUREDVALUESECTIONEMPTY
' //
' // MessageText:
' //
' //  Failed to retrieve value from the .ini file. The ConfiguredValue section is either empty, or does not exist: "%1!s!".
' //
%DTS_W_CONFIGUREDVALUESECTIONEMPTY = &H80012032&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when attempting to retrieve the configured type from an ini file.  Check the section in the ini file.

' //
' // MessageId: DTS_W_CONFIGUREDTYPESECTIONEMPTY
' //
' // MessageText:
' //
' //  Failed to retrieve value from the .ini file. The ConfiguredType section is either empty, or does not exist: "%1!s!".
' //
%DTS_W_CONFIGUREDTYPESECTIONEMPTY = &H80012033&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when attempting to retrieve the package path from an ini file.  Check the section in the ini file.

' //
' // MessageId: DTS_W_PACKAGEPATHSECTIONEMPTY
' //
' // MessageText:
' //
' //  Failed to retrieve value from the .ini file. The PackagePath section is either empty, or does not exist: "%1!s!".
' //
%DTS_W_PACKAGEPATHSECTIONEMPTY    = &H80012034&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when attempting to retrieve the configured value type from an ini file.  Check the section in the ini file.

' //
' // MessageId: DTS_W_CONFIGUREDVALUETYPE
' //
' // MessageText:
' //
' //  Failed to retrieve value from the .ini file. The ConfiguredValueType section is either empty, or does not exist: "%1!s!".
' //
%DTS_W_CONFIGUREDVALUETYPE        = &H80012035&

' ////////////////////////////////////////////////////////////////////////////
' // Happens after the configuration file fails to load

' //
' // MessageId: DTS_W_SQLSERVERFAILEDIMPORT
' //
' // MessageText:
' //
' //  Configuration from SQL Server was not successfully imported: "%1!s!".
' //
%DTS_W_SQLSERVERFAILEDIMPORT      = &H80012051&

' ////////////////////////////////////////////////////////////////////////////
' // Happens if some INI fields are empty or missing

' //
' // MessageId: DTS_W_INICONFIGURATIONPROBLEM
' //
' // MessageText:
' //
' //  The .ini configuration file is not valid due to empty or missing fields.
' //
%DTS_W_INICONFIGURATIONPROBLEM    = &H80012052&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when configuring from a Sql server table that has no records for configuration

' //
' // MessageId: DTS_W_NORECORDSFOUNDINTABLE
' //
' // MessageText:
' //
' //  Table "%1!s!" does not have any records for configuration. This occurs when configuring from a SQL Server table that has no records for the configuration.
' //
%DTS_W_NORECORDSFOUNDINTABLE      = &H80012054&

' ////////////////////////////////////////////////////////////////////////////
' // Different custom events used the same name

' //
' // MessageId: DTS_W_DUPLICATECUSTOMEVENT
' //
' // MessageText:
' //
' //  Error using same name for different custom events. The custom event "%1!s!" was defined differently by different children of this container. There may be an error when executing the event handler.
' //
%DTS_W_DUPLICATECUSTOMEVENT       = &H80012055&

' ////////////////////////////////////////////////////////////////////////////
' // This error happens when the client tries to configure a read only variable.

' //
' // MessageId: DTS_W_CONFIGREADONLYVARIABLE
' //
' // MessageText:
' //
' //  The configuration attempted to change a read-only variable. The variable is at the package path "%1".
' //
%DTS_W_CONFIGREADONLYVARIABLE     = &H80012057&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when calling ProcessConfiguration on the package and it fails

' //
' // MessageId: DTS_W_CONFIGPROCESSCONFIGURATIONFAILED
' //
' // MessageText:
' //
' //  Calling ProcessConfiguration on the package failed. The configuration attempted to change the property at the package path "%1".
' //
%DTS_W_CONFIGPROCESSCONFIGURATIONFAILED = &H80012058&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when one of the configuration settings on the package fails to load.  Check configurations entries and previous warnings to see which configuration failed.  Should be preceeded by another warning describing the configuration that failed.

' //
' // MessageId: DTS_W_ONEORMORECONFIGLOADFAILED
' //
' // MessageText:
' //
' //  Failed to load at least one of the configuration entries for the package. Check configurations entries and previous warnings to see descriptions of which configuration failed.
' //
%DTS_W_ONEORMORECONFIGLOADFAILED  = &H80012059&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when one of the configuration file entries either was invalid or failed to configure the variable.  The name indicates which entry failed, in some cases the name will be unknown

' //
' // MessageId: DTS_W_CONFIGNODEINVALID
' //
' // MessageText:
' //
' //  The configuration entry "%1!s!" in the configuration file was not valid, or failed to configure the variable.  The name indicates which entry failed. In some cases, the name will not be available.
' //
%DTS_W_CONFIGNODEINVALID          = &H8001205A&

' ////////////////////////////////////////////////////////////////////////////
' // Posted when SaveCheckpoints package property is True and the said condition exists.

' //
' // MessageId: DTS_W_FAILURENOTRESTARTABLE
' //
' // MessageText:
' //
' //  This task or container has failed, but because FailPackageOnFailure property is FALSE, the package will continue. This warning is posted when the SaveCheckpoints property of the package is set to TRUE and the task or container fails.
' //
%DTS_W_FAILURENOTRESTARTABLE      = &H80014058&

' ////////////////////////////////////////////////////////////////////////////
' // The path is empty

' //
' // MessageId: DTS_W_EMPTYPATH
' //
' // MessageText:
' //
' //  The path is empty.
' //
%DTS_W_EMPTYPATH                  = &H80017101&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the number of errors reaches the number specified in MaximumErrorCount.  Either change the MaximumErrorCount or fix errors.

' //
' // MessageId: DTS_W_MAXIMUMERRORCOUNTREACHED
' //
' // MessageText:
' //
' //  The Execution method succeeded, but the number of errors raised (%1!d!) reached the maximum allowed (%2!d!); resulting in failure. This occurs when the number of errors reaches the number specified in MaximumErrorCount.
' //  Change the MaximumErrorCount or fix the errors.
' //
%DTS_W_MAXIMUMERRORCOUNTREACHED   = &H80019002&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when a package specifies an environment variable for a configuration setting but the runtime can't find it.  Check the configurations collection on the package a verify that the specified environment variable is available and valid

' //
' // MessageId: DTS_W_CONFIGENVVARNOTFOUND
' //
' // MessageText:
' //
' //  The configuration environment variable was not found.  The environment variable was: "%1!s!". This occurs when a package specifies an environment variable for a configuration setting but it cannot be found.
' //  Check the configurations collection in the package and verify that the specified environment variable is available and valid.
' //
%DTS_W_CONFIGENVVARNOTFOUND       = &H80019003&

' ////////////////////////////////////////////////////////////////////////////
' // The for each file enumerator either didn't find any files that match the file pattern or the specified directory was empty

' //
' // MessageId: DTS_W_FILEENUMEMPTY
' //
' // MessageText:
' //
' //  The For Each File enumerator is empty. The For Each File enumerator did not find any files that matched the file pattern, or the specified directory was empty.
' //
%DTS_W_FILEENUMEMPTY              = &H8001C004&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when unsuccessfully attempting to resolve a package path to an object in the package, check the package path to ensure it's valid

' //
' // MessageId: DTS_W_COULDNOTRESOLVEPACKAGEPATH
' //
' // MessageText:
' //
' //  Cannot resolve a package path to an object in the package "%1!s!". Verify that the package path is valid.
' //
%DTS_W_COULDNOTRESOLVEPACKAGEPATH = &H8001F02F&

' ////////////////////////////////////////////////////////////////////////////
' // Given when the expression in the assignment expression on the ForLoop are boolean.

' //
' // MessageId: DTS_W_ITERATIONEXPRESSIONISBOOLEAN
' //
' // MessageText:
' //
' //  The iteration expression is Boolean. The expressions found in this position are not usually Boolean: "%1!s!". This error usually usually occurs when the expression in the assignment expression on the ForLoop is Boolean.
' //
%DTS_W_ITERATIONEXPRESSIONISBOOLEAN = &H8001F203&

' ////////////////////////////////////////////////////////////////////////////
' // Given when the expression in the iterate expressions on the ForLoop are boolean.

' //
' // MessageId: DTS_W_INITIALIZATIONEXPRESSIONISBOOLEAN
' //
' // MessageText:
' //
' //  Initialization expression is Boolean.  The expressions found in this position are not usually Boolean: "%1!s!". This error usually occurs when the expression in the iterate expressions on the ForLoop is Boolean.
' //
%DTS_W_INITIALIZATIONEXPRESSIONISBOOLEAN = &H8001F204&

' //
' // MessageId: DTS_E_TKEXECPACKAGE_UNABLETOLOADFILE
' //
' // MessageText:
' //
' //  Error 0x%1!8.8X! while loading package file "%3!s!". %2!s!.
' //
%DTS_E_TKEXECPACKAGE_UNABLETOLOADFILE = &HC00220DE&

' //
' // MessageId: DTS_E_TKEXECPACKAGE_UNSPECIFIEDPACKAGE
' //
' // MessageText:
' //
' //  The package is not specified.
' //
%DTS_E_TKEXECPACKAGE_UNSPECIFIEDPACKAGE = &HC00220DF&

' //
' // MessageId: DTS_E_TKEXECPACKAGE_UNSPECIFIEDCONNECTION
' //
' // MessageText:
' //
' //  The connection is not specified.
' //
%DTS_E_TKEXECPACKAGE_UNSPECIFIEDCONNECTION = &HC00220E0&

' //
' // MessageId: DTS_E_TKEXECPACKAGE_INCORRECTCONNECTIONMANAGERTYPE
' //
' // MessageText:
' //
' //  The connection manager "%1!s!" has an unsupported type "%2!s!". Only "FILE" and "OLEDB" connection managers are supported.
' //
%DTS_E_TKEXECPACKAGE_INCORRECTCONNECTIONMANAGERTYPE = &HC00220E2&

' //
' // MessageId: DTS_E_TKEXECPACKAGE_UNABLETOLOADXML
' //
' // MessageText:
' //
' //  Error 0x%1!8.8X! while loading package file "%3!s!" into an XML document. %2!s!.
' //
%DTS_E_TKEXECPACKAGE_UNABLETOLOADXML = &HC00220E3&

' //
' // MessageId: DTS_E_TKEXECPACKAGE_UNABLETOLOAD
' //
' // MessageText:
' //
' //  Error 0x%1!8.8X! while preparing to load the package. %2!s!.
' //
%DTS_E_TKEXECPACKAGE_UNABLETOLOAD = &HC00220E4&

' ////////////////////////////////////////////////////////////////////////////
' // Normally, task's Validate method must succeed and indicate the result via an out parameter. In this case, Validate failed.

' //
' // MessageId: DTS_E_TASKVALIDATIONFAILED
' //
' // MessageText:
' //
' //  The Validate method on the task failed, and returned error code 0x%1!8.8X! (%2!s!). The Validate method must succeed and indicate the result using an "out" parameter.
' //
%DTS_E_TASKVALIDATIONFAILED       = &HC0024102&

' ////////////////////////////////////////////////////////////////////////////
' // Normally, task's Execute method must succeed and indicate the result via an out parameter. In this case, Execute failed.

' //
' // MessageId: DTS_E_TASKEXECUTEFAILED
' //
' // MessageText:
' //
' //  The Execute method on the task returned error code 0x%1!8.8X! (%2!s!). The Execute method must succeed, and indicate the result using an "out" parameter.
' //
%DTS_E_TASKEXECUTEFAILED          = &HC0024104&

' ////////////////////////////////////////////////////////////////////////////
' // The runtime was trying to retrieve dependencies from the tasks dependencies collection when the error occurred, the task may have incorrectly implemented one of the dependency interfaces

' //
' // MessageId: DTS_E_RETRIEVINGDEPENDENCIES
' //
' // MessageText:
' //
' //  A failure occurred on task "%1!s!": 0x%2!8.8X! while retrieving dependencies. The runtime was retrieving dependencies from the task's dependencies collection when the error occurred.
' //  The task may have incorrectly implemented one of the dependency interfaces.
' //
%DTS_E_RETRIEVINGDEPENDENCIES     = &HC0024105&

' //
' // MessageId: DTS_E_TASKVALIDATIONERROR
' //
' // MessageText:
' //
' //  There were errors during task validation.
' //
%DTS_E_TASKVALIDATIONERROR        = &HC0024107&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when connection string with zero components is set on database connection manager.

' //
' // MessageId: DTS_E_CONNECTIONSTRINGFORMAT
' //
' // MessageText:
' //
' //  The connection string format is not valid. It must consist of one or more components of the form X=Y, separated by semicolons. This error occurs when a connection string with zero components is set on database connection manager.
' //
%DTS_E_CONNECTIONSTRINGFORMAT     = &HC0024108&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when e.g. InitialCatalog property of a connection contains unquoted semicolon.

' //
' // MessageId: DTS_E_UNQUOTEDSEMICOLON
' //
' // MessageText:
' //
' //  The connection string components cannot contain unquoted semicolons. If the value must contain a semicolon, enclose the entire value in quotes. This error occurs when values in the connection string contain
' //  unquoted semicolons, such as the InitialCatalog property.
' //
%DTS_E_UNQUOTEDSEMICOLON          = &HC0024109&

' ////////////////////////////////////////////////////////////////////////////
' // We refuse to execute if log providers fail to validate.

' //
' // MessageId: DTS_E_LOGPROVIDERVALIDATIONFAILED
' //
' // MessageText:
' //
' //  Validation of one or more log providers failed. The package cannot execute. The package does not execute when a log provider fails validation.
' //
%DTS_E_LOGPROVIDERVALIDATIONFAILED = &HC002410A&

' ////////////////////////////////////////////////////////////////////////////
' // This happens when a value of the array of values in a variable is invalid (possibly out of range).

' //
' // MessageId: DTS_E_INVALIDVALUEINARRAY
' //
' // MessageText:
' //
' //  Invalid value in array.
' //
%DTS_E_INVALIDVALUEINARRAY        = &HC002410B&

' //
' // MessageId: DTS_E_ENUMERATIONELEMENTNOTENUMERABLE
' //
' // MessageText:
' //
' //  An element of the enumerator returned by the ForEach Enumerator does not implement IEnumerator, contradicting the CollectionEnumerator property of the ForEach Enumerator.
' //
%DTS_E_ENUMERATIONELEMENTNOTENUMERABLE = &HC002410C&

' //
' // MessageId: DTS_E_AXTASK_MISSING_ENTRY_METHOD_NAME
' //
' // MessageText:
' //
' //  Function not found.
' //
%DTS_E_AXTASK_MISSING_ENTRY_METHOD_NAME = &HC0029100&

' //
' // MessageId: DTS_E_AXTASK_EMPTY_SCRIPT
' //
' // MessageText:
' //
' //  Function not found.
' //
%DTS_E_AXTASK_EMPTY_SCRIPT        = &HC0029101&

' //
' // MessageId: DTS_E_AXTASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  ActiveX Script Task was initiated with a wrong XML element.
' //
%DTS_E_AXTASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT = &HC0029102&

' //
' // MessageId: DTS_E_AXTASK_HANDLER_NOT_FOUND
' //
' // MessageText:
' //
' //  Handler not found.
' //
%DTS_E_AXTASK_HANDLER_NOT_FOUND   = &HC0029105&

' //
' // MessageId: DTS_E_AXTASKUTIL_ENUMERATE_LANGUAGES_FAILED
' //
' // MessageText:
' //
' //  An error occurred while attempting to retrieve the scripting languages installed on the system.
' //
%DTS_E_AXTASKUTIL_ENUMERATE_LANGUAGES_FAILED = &HC0029106&

' //
' // MessageId: DTS_E_AXTASKUTIL_SCRIPTHOST_CREATE_FAILED
' //
' // MessageText:
' //
' //  An error occurred while creating the ActiveX script host. Verify that you have the script host installed properly.
' //
%DTS_E_AXTASKUTIL_SCRIPTHOST_CREATE_FAILED = &HC0029107&

' //
' // MessageId: DTS_E_AXTASKUTIL_SCRIPTHOSTINIT_FAILED
' //
' // MessageText:
' //
' //  An error occurred while trying to instantiate the script host for the chosen language. Verify that the script language you have chosen is installed on your system.
' //
%DTS_E_AXTASKUTIL_SCRIPTHOSTINIT_FAILED = &HC0029108&

' //
' // MessageId: DTS_E_AXTASKUTIL_ADDVARIABLES_FAILED
' //
' // MessageText:
' //
' //  An error occurred while adding the SSIS variables to the script host namespace. This might prevent the task from using SSIS variables in the script.
' //
%DTS_E_AXTASKUTIL_ADDVARIABLES_FAILED = &HC0029109&

' //
' // MessageId: DTS_E_AXTASKUTIL_SCRIPT_PARSING_FAILED
' //
' // MessageText:
' //
' //  A fatal error occurred while trying to parse the script text. Verify that the script engine for the chosen language is installed properly.
' //
%DTS_E_AXTASKUTIL_SCRIPT_PARSING_FAILED = &HC002910A&

' //
' // MessageId: DTS_E_AXTASKUTIL_MSG_BAD_FUNCTION
' //
' // MessageText:
' //
' //  The function name entered is not valid. Verify that a valid function name has been specified.
' //
%DTS_E_AXTASKUTIL_MSG_BAD_FUNCTION = &HC002910B&

' //
' // MessageId: DTS_E_AXTASKUTIL_EXECUTION_FAILED
' //
' // MessageText:
' //
' //  An error occurred while executing the script. Verify that the script engine for the selected language is installed properly.
' //
%DTS_E_AXTASKUTIL_EXECUTION_FAILED = &HC002910C&

' //
' // MessageId: DTS_E_AXTASKUTIL_ADDTYPELIB_FAILED
' //
' // MessageText:
' //
' //  An error occurred while adding the managed type library to the script host. Verify that the DTS 2000 runtime is installed.
' //
%DTS_E_AXTASKUTIL_ADDTYPELIB_FAILED = &HC002910D&

' //
' // MessageId: DTS_E_BITASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  Bulk Insert Task was initiated with a wrong XML element.
' //
%DTS_E_BITASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT = &HC002910E&

' //
' // MessageId: DTS_E_BITASK_DATA_FILE_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  Data file name not specified.
' //
%DTS_E_BITASK_DATA_FILE_NOT_SPECIFIED = &HC002910F&

' //
' // MessageId: DTS_E_BITASK_HANDLER_NOT_FOUND
' //
' // MessageText:
' //
' //  Handler not found.
' //
%DTS_E_BITASK_HANDLER_NOT_FOUND   = &HC0029110&

' //
' // MessageId: DTS_E_BITASK_CANNOT_ACQUIRE_CONNECTION
' //
' // MessageText:
' //
' //  Failed to acquire the specified connection: "%1!s!".
' //
%DTS_E_BITASK_CANNOT_ACQUIRE_CONNECTION = &HC0029111&

' //
' // MessageId: DTS_E_BITASK_NO_CONNECTION_MANAGER_SPECIFIED
' //
' // MessageText:
' //
' //  Attempt to obtain the Connection Manager failed.
' //
%DTS_E_BITASK_NO_CONNECTION_MANAGER_SPECIFIED = &HC0029112&

' //
' // MessageId: DTS_E_BITASK_INVALID_CONNECTION
' //
' // MessageText:
' //
' //  The connection is not valid.
' //
%DTS_E_BITASK_INVALID_CONNECTION  = &HC0029113&

' //
' // MessageId: DTS_E_BITASK_NULL_CONNECTION
' //
' // MessageText:
' //
' //  The connection is null.
' //
%DTS_E_BITASK_NULL_CONNECTION     = &HC0029114&

' //
' // MessageId: DTS_E_BITASK_EXECUTE_FAILED
' //
' // MessageText:
' //
' //  Execution failed.
' //
%DTS_E_BITASK_EXECUTE_FAILED      = &HC0029115&

' //
' // MessageId: DTS_E_BITASK_CANNOT_RETRIEVE_TABLES
' //
' // MessageText:
' //
' //  An error occurred while retrieving the tables from the database.
' //
%DTS_E_BITASK_CANNOT_RETRIEVE_TABLES = &HC0029116&

' //
' // MessageId: DTS_E_BITASK_CANNOT_RETRIEVE_COLUMN_INFO
' //
' // MessageText:
' //
' //  An error occurred while retrieving the columns of the table.
' //
%DTS_E_BITASK_CANNOT_RETRIEVE_COLUMN_INFO = &HC0029117&

' //
' // MessageId: DTS_E_BITASK_ERROR_IN_DB_OPERATION
' //
' // MessageText:
' //
' //  An error occurred in the database operation.
' //
%DTS_E_BITASK_ERROR_IN_DB_OPERATION = &HC0029118&

' //
' // MessageId: DTS_E_BITASK_INVALIDSOURCECONNECTIONNAME
' //
' // MessageText:
' //
' //  The specified connection "%1!s!" is either not valid, or points to an invalid object. To continue, specify a valid connection.
' //
%DTS_E_BITASK_INVALIDSOURCECONNECTIONNAME = &HC0029119&

' //
' // MessageId: DTS_E_BITASK_INVALIDDESTCONNECTIONNAME
' //
' // MessageText:
' //
' //  The destination connection specified is not valid. Supply a valid connection to continue.
' //
%DTS_E_BITASK_INVALIDDESTCONNECTIONNAME = &HC002911A&

' //
' // MessageId: DTS_E_BITASK_DESTINATION_TABLE_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  You must specify a table name to continue.
' //
%DTS_E_BITASK_DESTINATION_TABLE_NOT_SPECIFIED = &HC002911B&

' //
' // MessageId: DTS_E_BITASK_ERROR_IN_LOAD_FROM_XML
' //
' // MessageText:
' //
' //  Error occurred in LoadFromXML at the tag "%1!s!".
' //
%DTS_E_BITASK_ERROR_IN_LOAD_FROM_XML = &HC002911C&

' //
' // MessageId: DTS_E_BITASK_ERROR_IN_SAVE_TO_XML
' //
' // MessageText:
' //
' //  Error occurred in SaveToXML at the tag "%1!s!".
' //
%DTS_E_BITASK_ERROR_IN_SAVE_TO_XML = &HC002911D&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_INVALID_CONNECTION
' //
' // MessageText:
' //
' //  The connection is not valid.
' //
%DTS_E_BITASKUNMANCONNECTION_INVALID_CONNECTION = &HC002911E&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_EXECUTE_FAILED
' //
' // MessageText:
' //
' //  Execution failed.
' //
%DTS_E_BITASKUNMANCONNECTION_EXECUTE_FAILED = &HC002911F&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_CANNOT_RETRIEVE_TABLES
' //
' // MessageText:
' //
' //  Error occurred while retrieving the tables from the database.
' //
%DTS_E_BITASKUNMANCONNECTION_CANNOT_RETRIEVE_TABLES = &HC0029120&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_CANNOT_RETRIEVE_COLUMN_INFO
' //
' // MessageText:
' //
' //  Error occurred while retrieving the columns of the table.
' //
%DTS_E_BITASKUNMANCONNECTION_CANNOT_RETRIEVE_COLUMN_INFO = &HC0029121&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_CANNOT_OPEN_FILE
' //
' // MessageText:
' //
' //  Error occurred while trying to open the data file.
' //
%DTS_E_BITASKUNMANCONNECTION_CANNOT_OPEN_FILE = &HC0029122&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_OEM_CONVERSION_FAILED
' //
' // MessageText:
' //
' //  Cannot convert the input OEM file to the specified format.
' //
%DTS_E_BITASKUNMANCONNECTION_OEM_CONVERSION_FAILED = &HC0029123&

' //
' // MessageId: DTS_E_BITASKUNMANCONNECTION_ERROR_IN_DB_OPERATION
' //
' // MessageText:
' //
' //  Error in database operation.
' //
%DTS_E_BITASKUNMANCONNECTION_ERROR_IN_DB_OPERATION = &HC0029124&

' //
' // MessageId: DTS_E_DTSPROCTASK_NOCONNECTIONSPECIFIED
' //
' // MessageText:
' //
' //  No connection manager specified.
' //
%DTS_E_DTSPROCTASK_NOCONNECTIONSPECIFIED = &HC0029125&

' //
' // MessageId: DTS_E_DTSPROCTASK_CONNECTIONMANAGERNOTOLAP
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not an Analysis Services connection.
' //
%DTS_E_DTSPROCTASK_CONNECTIONMANAGERNOTOLAP = &HC0029126&

' //
' // MessageId: DTS_E_DTSPROCTASK_UNABLETOLOCATECONNECTIONMANAGER
' //
' // MessageText:
' //
' //  Unable to locate connection "%1!s!".
' //
%DTS_E_DTSPROCTASK_UNABLETOLOCATECONNECTIONMANAGER = &HC0029127&

' //
' // MessageId: DTS_E_DTSPROCTASK_INVALIDTASKDATANODEEXE
' //
' // MessageText:
' //
' //  Analysis Services Execute DDL task received an invalid task data node.
' //
%DTS_E_DTSPROCTASK_INVALIDTASKDATANODEEXE = &HC0029128&

' //
' // MessageId: DTS_E_DTSPROCTASK_INVALIDTASKDATANODEPROC
' //
' // MessageText:
' //
' //  Analysis Services Processing task received an invalid task data node.
' //
%DTS_E_DTSPROCTASK_INVALIDTASKDATANODEPROC = &HC0029129&

' //
' // MessageId: DTS_E_DTSPROCTASK_INVALIDDDL
' //
' // MessageText:
' //
' //  The DDL is not valid.
' //
%DTS_E_DTSPROCTASK_INVALIDDDL     = &HC002912A&

' //
' // MessageId: DTS_E_DTSPROCTASK_INVALIDDDLPROCESSINGCOMMANDS
' //
' // MessageText:
' //
' //  The DDL found in ProcessingCommands is not valid.
' //
%DTS_E_DTSPROCTASK_INVALIDDDLPROCESSINGCOMMANDS = &HC002912B&

' //
' // MessageId: DTS_E_DTSPROCTASK_CANNOTWRITEINAREADONLYVARIABLE
' //
' // MessageText:
' //
' //  The Execution result cannot be saved in a read-only variable.
' //
%DTS_E_DTSPROCTASK_CANNOTWRITEINAREADONLYVARIABLE = &HC002912C&

' //
' // MessageId: DTS_E_DTSPROCTASK_INVALIDVARIABLE
' //
' // MessageText:
' //
' //  Variable "%1!s!" it's not defined.
' //
%DTS_E_DTSPROCTASK_INVALIDVARIABLE = &HC002912D&

' //
' // MessageId: DTS_E_DTSPROCTASK_CONNECTIONNOTFOUND
' //
' // MessageText:
' //
' //  Connection Manager "%1!s!" it's not defined.
' //
%DTS_E_DTSPROCTASK_CONNECTIONNOTFOUND = &HC002912E&

' //
' // MessageId: DTS_E_DTSPROCTASK_INVALIDCONNECTION
' //
' // MessageText:
' //
' //  Connection Manager "%1!s!" it's not a FILE Connection Manager.
' //
%DTS_E_DTSPROCTASK_INVALIDCONNECTION = &HC002912F&

' //
' // MessageId: DTS_E_DTSPROCTASK_NONEXISTENTATTRIBUTE
' //
' // MessageText:
' //
' //  "%1!s!" was not found during deserialization.
' //
%DTS_E_DTSPROCTASK_NONEXISTENTATTRIBUTE = &HC0029130&

' //
' // MessageId: DTS_E_DTSPROCTASK_TRACEHASBEENSTOPPED
' //
' // MessageText:
' //
' //  The trace has been stopped due to an exception.
' //
%DTS_E_DTSPROCTASK_TRACEHASBEENSTOPPED = &HC0029131&

' //
' // MessageId: DTS_E_DTSPROCTASK_DDLEXECUTIONFAILED
' //
' // MessageText:
' //
' //  Execution of DDL failed.
' //
%DTS_E_DTSPROCTASK_DDLEXECUTIONFAILED = &HC0029132&

' //
' // MessageId: DTS_E_DTSPROCTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  There is no file associated with connection "%1!s!".
' //
%DTS_E_DTSPROCTASK_FILEDOESNOTEXIST = &HC0029133&

' //
' // MessageId: DTS_E_DTSPROCTASK_VARIABLENOTDEFINED
' //
' // MessageText:
' //
' //  Variable "%1!s!" is not defined.
' //
%DTS_E_DTSPROCTASK_VARIABLENOTDEFINED = &HC0029134&

' //
' // MessageId: DTS_E_DTSPROCTASK_FILECONNECTIONNOTDEFINED
' //
' // MessageText:
' //
' //  File connection "%1!s!" is not defined.
' //
%DTS_E_DTSPROCTASK_FILECONNECTIONNOTDEFINED = &HC0029135&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  Execute DTS 2000 Package task is initiated with a wrong XML element.
' //
%DTS_E_EXEC2000PKGTASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT = &HC0029136&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_HANDLER_NOT_FOUND
' //
' // MessageText:
' //
' //  Handler not found.
' //
%DTS_E_EXEC2000PKGTASK_HANDLER_NOT_FOUND = &HC0029137&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_PACKAGE_NAME_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  Package name is not specified.
' //
%DTS_E_EXEC2000PKGTASK_PACKAGE_NAME_NOT_SPECIFIED = &HC0029138&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_PACKAGE_ID_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  Package ID is not specified.
' //
%DTS_E_EXEC2000PKGTASK_PACKAGE_ID_NOT_SPECIFIED = &HC0029139&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_PACKAGE_VERSIONGUID_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  Package version GUID is not specified.
' //
%DTS_E_EXEC2000PKGTASK_PACKAGE_VERSIONGUID_NOT_SPECIFIED = &HC002913A&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_SQLSERVER_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  SQL Server is not specified.
' //
%DTS_E_EXEC2000PKGTASK_SQLSERVER_NOT_SPECIFIED = &HC002913B&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_SQL_USERNAME_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  SQL Server user name not specified.
' //
%DTS_E_EXEC2000PKGTASK_SQL_USERNAME_NOT_SPECIFIED = &HC002913C&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_FILE_NAME_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  Storage file name not specified.
' //
%DTS_E_EXEC2000PKGTASK_FILE_NAME_NOT_SPECIFIED = &HC002913D&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_DTS2000CANTBEEMPTY
' //
' // MessageText:
' //
' //  The DTS 2000 package property is empty.
' //
%DTS_E_EXEC2000PKGTASK_DTS2000CANTBEEMPTY = &HC002913E&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_ERROR_IN_PACKAGE_EXECUTE
' //
' // MessageText:
' //
' //  An error occurred while executing the DTS 2000 package.
' //
%DTS_E_EXEC2000PKGTASK_ERROR_IN_PACKAGE_EXECUTE = &HC002913F&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_SQLSERVER_NOT_AVAILABLE_NETWORK
' //
' // MessageText:
' //
' //  Cannot load the available SQL Servers from the network. Check the network connection.
' //
%DTS_E_EXEC2000PKGTASK_SQLSERVER_NOT_AVAILABLE_NETWORK = &HC0029140&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_DATATYPE_NULL
' //
' // MessageText:
' //
' //  The data type cannot be null. Please specify the correct data type to use for validating the value.
' //
%DTS_E_EXEC2000PKGTASK_DATATYPE_NULL = &HC0029141&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_NULL_VALUE
' //
' // MessageText:
' //
' //  Cannot validate a null against any data type.
' //
%DTS_E_EXEC2000PKGTASK_NULL_VALUE = &HC0029142&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_NULL_VALUE_ARGUMENT
' //
' // MessageText:
' //
' //  A required argument is null.
' //
%DTS_E_EXEC2000PKGTASK_NULL_VALUE_ARGUMENT = &HC0029143&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_CLS_NOT_REGISTRED_EXCEPTION
' //
' // MessageText:
' //
' //  To execute the DTS 2000 Package task, start SQL Server Setup and use the Advanced button from the Components to Install dialog to select Data Transformation Services 2000 Runtime.
' //
%DTS_E_EXEC2000PKGTASK_CLS_NOT_REGISTRED_EXCEPTION = &HC0029144&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_NOT_PRIMITIVE_TYPE
' //
' // MessageText:
' //
' //  "%1!s!" is not a value type.
' //
%DTS_E_EXEC2000PKGTASK_NOT_PRIMITIVE_TYPE = &HC0029145&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_CONVERT_FAILED
' //
' // MessageText:
' //
' //  Could not convert "%1!s!" to "%2!s!".
' //
%DTS_E_EXEC2000PKGTASK_CONVERT_FAILED = &HC0029146&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_ERROR_IN_VALIDATE
' //
' // MessageText:
' //
' //  Could not validate "%1!s!" against "%2!s!".
' //
%DTS_E_EXEC2000PKGTASK_ERROR_IN_VALIDATE = &HC0029147&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_ERROR_IN_LOAD_FROM_XML
' //
' // MessageText:
' //
' //  Error occurred in LoadFromXML at the tag "%1!s!".
' //
%DTS_E_EXEC2000PKGTASK_ERROR_IN_LOAD_FROM_XML = &HC0029148&

' //
' // MessageId: DTS_E_EXEC2000PKGTASK_ERROR_IN_SAVE_TO_XML
' //
' // MessageText:
' //
' //  Error occurred in SaveToXML at the tag "%1!s!".
' //
%DTS_E_EXEC2000PKGTASK_ERROR_IN_SAVE_TO_XML = &HC0029149&

' //
' // MessageId: DTS_E_EXECPROCTASK_INVALIDTIMEOUT
' //
' // MessageText:
' //
' //  The time-out value provided is not valid. Specify the number of seconds that the task allows the process to run. The minimum time-out is 0, which indicates that no time-out value is used and
' //  the process runs to completion or until an error occurs. The maximum time-out is 2147483 (((2^31) - 1)/1000).
' //
%DTS_E_EXECPROCTASK_INVALIDTIMEOUT = &HC002914A&

' //
' // MessageId: DTS_E_EXECPROCTASK_CANTREDIRECTIO
' //
' // MessageText:
' //
' //  Cannot redirect streams if the process can continue executing beyond the lifetime of the task.
' //
%DTS_E_EXECPROCTASK_CANTREDIRECTIO = &HC002914B&

' //
' // MessageId: DTS_E_EXECPROCTASK_PROCESSHASTIMEDOUT
' //
' // MessageText:
' //
' //  The process timed out.
' //
%DTS_E_EXECPROCTASK_PROCESSHASTIMEDOUT = &HC002914C&

' //
' // MessageId: DTS_E_EXECPROCTASK_EXECUTABLENOTSPECIFIED
' //
' // MessageText:
' //
' //  The executable is not specified.
' //
%DTS_E_EXECPROCTASK_EXECUTABLENOTSPECIFIED = &HC002914D&

' //
' // MessageId: DTS_E_EXECPROCTASK_STDOUTVARREADONLY
' //
' // MessageText:
' //
' //  The standard out variable is read-only.
' //
%DTS_E_EXECPROCTASK_STDOUTVARREADONLY = &HC002914E&

' //
' // MessageId: DTS_E_EXECPROCTASK_STDERRVARREADONLY
' //
' // MessageText:
' //
' //  The standard error variable is read-only.
' //
%DTS_E_EXECPROCTASK_STDERRVARREADONLY = &HC002914F&

' //
' // MessageId: DTS_E_EXECPROCTASK_RECEIVEDINVALIDTASKDATANODE
' //
' // MessageText:
' //
' //  The Execute Process task received a task data node that is not valid.
' //
%DTS_E_EXECPROCTASK_RECEIVEDINVALIDTASKDATANODE = &HC0029150&

' //
' // MessageId: DTS_E_EXECPROCTASK_PROCESSEXITCODEEXCEEDS
' //
' // MessageText:
' //
' //  In Executing "%2!s!" "%3!s!" at "%1!s!", The process exit code was "%4!s!" while the expected was "%5!s!".
' //
%DTS_E_EXECPROCTASK_PROCESSEXITCODEEXCEEDS = &HC0029151&

' //
' // MessageId: DTS_E_EXECPROCTASK_WORKINGDIRDOESNOTEXIST
' //
' // MessageText:
' //
' //  The directory "%1!s!" does not exist.
' //
%DTS_E_EXECPROCTASK_WORKINGDIRDOESNOTEXIST = &HC0029152&

' //
' // MessageId: DTS_E_EXECPROCTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  File/Process "%1!s!" does not exist in directory "%2!s!".
' //
%DTS_E_EXECPROCTASK_FILEDOESNOTEXIST = &HC0029153&

' //
' // MessageId: DTS_E_EXECPROCTASK_FILENOTINPATH
' //
' // MessageText:
' //
' //  File/Process "%1!s!" is not in path.
' //
%DTS_E_EXECPROCTASK_FILENOTINPATH = &HC0029154&

' //
' // MessageId: DTS_E_EXECPROCTASK_WORKINGDIRECTORYDOESNOTEXIST
' //
' // MessageText:
' //
' //  Working Directory "%1!s!" does not exist.
' //
%DTS_E_EXECPROCTASK_WORKINGDIRECTORYDOESNOTEXIST = &HC0029156&

' //
' // MessageId: DTS_E_EXECPROCTASK_ERROREXECUTIONVALUE
' //
' // MessageText:
' //
' //  The process exited with return code "%1!s!". However, "%2!s!" was expected.
' //
%DTS_E_EXECPROCTASK_ERROREXECUTIONVALUE = &HC0029157&

' //
' // MessageId: DTS_E_FSTASK_SYNCFAILED
' //
' // MessageText:
' //
' //  Synchronization object failed.
' //
%DTS_E_FSTASK_SYNCFAILED          = &HC0029158&

' //
' // MessageId: DTS_E_FSTASK_INVALIDDATA
' //
' // MessageText:
' //
' //  The File System task received an invalid task data node.
' //
%DTS_E_FSTASK_INVALIDDATA         = &HC0029159&

' //
' // MessageId: DTS_E_FSTASK_DIRECTORYEXISTS
' //
' // MessageText:
' //
' //  The Directory already exists.
' //
%DTS_E_FSTASK_DIRECTORYEXISTS     = &HC002915A&

' //
' // MessageId: DTS_E_FSTASK_PATHNOTVALID
' //
' // MessageText:
' //
' //  "%1!s!" is not valid on operation type "%2!s!".
' //
%DTS_E_FSTASK_PATHNOTVALID        = &HC002915B&

' //
' // MessageId: DTS_E_FSTASK_DESTINATIONNOTSET
' //
' // MessageText:
' //
' //  Destination property of operation "%1!s!" not set.
' //
%DTS_E_FSTASK_DESTINATIONNOTSET   = &HC002915C&

' //
' // MessageId: DTS_E_FSTASK_SOURCENOTSET
' //
' // MessageText:
' //
' //  Source property of operation "%1!s!" not set.
' //
%DTS_E_FSTASK_SOURCENOTSET        = &HC002915D&

' //
' // MessageId: DTS_E_FSTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  Type of Connection "%1!s!" is not a file.
' //
%DTS_E_FSTASK_CONNECTIONTYPENOTFILE = &HC002915E&

' //
' // MessageId: DTS_E_FSTASK_VARIABLEDOESNTEXIST
' //
' // MessageText:
' //
' //  Variable "%1!s!" does not exist.
' //
%DTS_E_FSTASK_VARIABLEDOESNTEXIST = &HC002915F&

' //
' // MessageId: DTS_E_FSTASK_VARIABLENOTASTRING
' //
' // MessageText:
' //
' //  Variable "%1!s!" is not a string.
' //
%DTS_E_FSTASK_VARIABLENOTASTRING  = &HC0029160&

' //
' // MessageId: DTS_E_FSTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  File or directory "%1!s!" represented by connection "%2!s!" does not exist.
' //
%DTS_E_FSTASK_FILEDOESNOTEXIST    = &HC0029163&

' //
' // MessageId: DTS_E_FSTASK_DESTCONNUSAGETYPEINVALID
' //
' // MessageText:
' //
' //  The destination file connection manager "%1!s!" has an invalid usage type: "%2!s!".
' //
%DTS_E_FSTASK_DESTCONNUSAGETYPEINVALID = &HC0029165&

' //
' // MessageId: DTS_E_FSTASK_SRCCONNUSAGETYPEINVALID
' //
' // MessageText:
' //
' //  The source file connection manager "%1!s!" has an invalid usage type "%2!s!".
' //
%DTS_E_FSTASK_SRCCONNUSAGETYPEINVALID = &HC0029166&

' //
' // MessageId: DTS_E_FSTASK_LOGENTRYGETTINGFILEOPERATION
' //
' // MessageText:
' //
' //  FileSystemOperation
' //
%DTS_E_FSTASK_LOGENTRYGETTINGFILEOPERATION = &HC0029167&

' //
' // MessageId: DTS_E_FSTASK_LOGENTRYGETTINGFILEOPERATIONDESC
' //
' // MessageText:
' //
' //  Provides information regarding File System operations.
' //
%DTS_E_FSTASK_LOGENTRYGETTINGFILEOPERATIONDESC = &HC0029168&

' //
' // MessageId: DTS_E_FSTASK_TASKDISPLAYNAME
' //
' // MessageText:
' //
' //  File System Task
' //
%DTS_E_FSTASK_TASKDISPLAYNAME     = &HC0029169&

' //
' // MessageId: DTS_E_FSTASK_TASKDESCRIPTION
' //
' // MessageText:
' //
' //  Perform file system operations, such as copying and deleting files.
' //
%DTS_E_FSTASK_TASKDESCRIPTION     = &HC002916A&

' //
' // MessageId: DTS_E_FTPTASK_SYNCOBJFAILED
' //
' // MessageText:
' //
' //  Synchronization object failed.
' //
%DTS_E_FTPTASK_SYNCOBJFAILED      = &HC002916B&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOOBTAINFILELIST
' //
' // MessageText:
' //
' //  Unable to obtain the file list.
' //
%DTS_E_FTPTASK_UNABLETOOBTAINFILELIST = &HC002916C&

' //
' // MessageId: DTS_E_FTPTASK_LOCALPATHEMPTY
' //
' // MessageText:
' //
' //  The local path is empty.
' //
%DTS_E_FTPTASK_LOCALPATHEMPTY     = &HC002916D&

' //
' // MessageId: DTS_E_FTPTASK_REMOTEPATHEMPTY
' //
' // MessageText:
' //
' //  The remote path is empty.
' //
%DTS_E_FTPTASK_REMOTEPATHEMPTY    = &HC002916E&

' //
' // MessageId: DTS_E_FTPTASK_LOCALVARIBALEEMPTY
' //
' // MessageText:
' //
' //  The local variable is empty.
' //
%DTS_E_FTPTASK_LOCALVARIBALEEMPTY = &HC002916F&

' //
' // MessageId: DTS_E_FTPTASK_REMOTEVARIBALEEMPTY
' //
' // MessageText:
' //
' //  The remote variable is empty.
' //
%DTS_E_FTPTASK_REMOTEVARIBALEEMPTY = &HC0029170&

' //
' // MessageId: DTS_E_FTPTASK_FTPRCVDINVLDDATANODE
' //
' // MessageText:
' //
' //  The FTP task received an invalid task data node.
' //
%DTS_E_FTPTASK_FTPRCVDINVLDDATANODE = &HC0029171&

' //
' // MessageId: DTS_E_FTPTASK_CONNECTION_NAME_NULL
' //
' // MessageText:
' //
' //  The connection is empty. Verify that a valid FTP connection is provided.
' //
%DTS_E_FTPTASK_CONNECTION_NAME_NULL = &HC0029172&

' //
' // MessageId: DTS_E_FTPTASK_CONNECTION_NOT_FTP
' //
' // MessageText:
' //
' //  The connection specified is not an FTP connection. Verify that a valid FTP connection is provided.
' //
%DTS_E_FTPTASK_CONNECTION_NOT_FTP = &HC0029173&

' //
' // MessageId: DTS_E_FTPTASK__INITIALIZATION_WITH_NULL_XML_ELEMENT
' //
' // MessageText:
' //
' //  Cannot initialize the task with a null XML element.
' //
%DTS_E_FTPTASK__INITIALIZATION_WITH_NULL_XML_ELEMENT = &HC0029175&

' //
' // MessageId: DTS_E_FTPTASK_SAVE_TO_NULL_XML_ELEMENT
' //
' // MessageText:
' //
' //  Cannot save the task to a null XML document.
' //
%DTS_E_FTPTASK_SAVE_TO_NULL_XML_ELEMENT = &HC0029176&

' //
' // MessageId: DTS_E_FTPTASK_ERROR_IN_LOAD_FROM_XML
' //
' // MessageText:
' //
' //  Error occurred in LoadFromXML at the tag "%1!s!".
' //
%DTS_E_FTPTASK_ERROR_IN_LOAD_FROM_XML = &HC0029177&

' //
' // MessageId: DTS_E_FTPTASK_NOFILESATLOCATION
' //
' // MessageText:
' //
' //  There are no files at "%1!s!".
' //
%DTS_E_FTPTASK_NOFILESATLOCATION  = &HC0029178&

' //
' // MessageId: DTS_E_FTPTASK_LOCALVARIABLEISEMPTY
' //
' // MessageText:
' //
' //  The variable "%1!s!" is empty.
' //
%DTS_E_FTPTASK_LOCALVARIABLEISEMPTY = &HC0029179&

' //
' // MessageId: DTS_E_FTPTASK_REMOTEVARIABLEISEMPTY
' //
' // MessageText:
' //
' //  The variable "%1!s!" is empty.
' //
%DTS_E_FTPTASK_REMOTEVARIABLEISEMPTY = &HC002917A&

' //
' // MessageId: DTS_E_FTPTASK_NOFILESINCONNMGR
' //
' // MessageText:
' //
' //  The File "%1!s!" doesn't contain file path(s).
' //
%DTS_E_FTPTASK_NOFILESINCONNMGR   = &HC002917B&

' //
' // MessageId: DTS_E_FTPTASK_NOFILEPATHSINLOCALVAR
' //
' // MessageText:
' //
' //  The variable "%1!s!" doesn't contain file path(s).
' //
%DTS_E_FTPTASK_NOFILEPATHSINLOCALVAR = &HC002917C&

' //
' // MessageId: DTS_E_FTPTASK_VARIABLENOTASTRING
' //
' // MessageText:
' //
' //  Variable "%1!s!" is not a string.
' //
%DTS_E_FTPTASK_VARIABLENOTASTRING = &HC002917D&

' //
' // MessageId: DTS_E_FTPTASK_VARIABLENOTFOUND
' //
' // MessageText:
' //
' //  Variable "%1!s!" does not exist.
' //
%DTS_E_FTPTASK_VARIABLENOTFOUND   = &HC002917E&

' //
' // MessageId: DTS_E_FTPTASK_INVALIDPATHONOPERATION
' //
' // MessageText:
' //
' //  Invalid path on operation "%1!s!".
' //
%DTS_E_FTPTASK_INVALIDPATHONOPERATION = &HC002917F&

' //
' // MessageId: DTS_E_FTPTASK_DIRECTORYEXISTS
' //
' // MessageText:
' //
' //  "%1!s!" already exists.
' //
%DTS_E_FTPTASK_DIRECTORYEXISTS    = &HC0029180&

' //
' // MessageId: DTS_E_FTPTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  Type of Connection "%1!s!" is Not a file.
' //
%DTS_E_FTPTASK_CONNECTIONTYPENOTFILE = &HC0029182&

' //
' // MessageId: DTS_E_FTPTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  File represented by "%1!s!" does not exist.
' //
%DTS_E_FTPTASK_FILEDOESNOTEXIST   = &HC0029183&

' //
' // MessageId: DTS_E_FTPTASK_INVALIDDIRECTORY
' //
' // MessageText:
' //
' //  Directory is not specified in the variable "%1!s!".
' //
%DTS_E_FTPTASK_INVALIDDIRECTORY   = &HC0029184&

' //
' // MessageId: DTS_E_FTPTASK_NOFILESFOUND
' //
' // MessageText:
' //
' //  No files found in "%1!s!".
' //
%DTS_E_FTPTASK_NOFILESFOUND       = &HC0029185&

' //
' // MessageId: DTS_E_FTPTASK_NODIRECTORYPATHINCONMGR
' //
' // MessageText:
' //
' //  Directory is not specified in the file connection manager "%1!s!".
' //
%DTS_E_FTPTASK_NODIRECTORYPATHINCONMGR = &HC0029186&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETODELETELOCALEFILE
' //
' // MessageText:
' //
' //  Unable to delete local file "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETODELETELOCALEFILE = &HC0029187&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOREMOVELOCALDIRECTORY
' //
' // MessageText:
' //
' //  Unable to remove local directory "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETOREMOVELOCALDIRECTORY = &HC0029188&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOCREATELOCALDIRECTORY
' //
' // MessageText:
' //
' //  Unable to create local directory "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETOCREATELOCALDIRECTORY = &HC0029189&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETORECEIVEFILES
' //
' // MessageText:
' //
' //  Unable to receive files using "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETORECEIVEFILES = &HC002918A&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOSENDFILES
' //
' // MessageText:
' //
' //  Unable to send files using "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETOSENDFILES  = &HC002918B&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOMAKEDIRREMOTE
' //
' // MessageText:
' //
' //  Unable to create remote directory using "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETOMAKEDIRREMOTE = &HC002918C&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOREMOVEDIRREMOTE
' //
' // MessageText:
' //
' //  Unable to remove remote directory using "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETOREMOVEDIRREMOTE = &HC002918D&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETODELETEREMOTEFILES
' //
' // MessageText:
' //
' //  Unable to delete remote files using "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETODELETEREMOTEFILES = &HC002918E&

' //
' // MessageId: DTS_E_FTPTASK_UNABLETOCONNECTTOSERVER
' //
' // MessageText:
' //
' //  Unable to connect to FTP server using "%1!s!".
' //
%DTS_E_FTPTASK_UNABLETOCONNECTTOSERVER = &HC002918F&

' //
' // MessageId: DTS_E_FTPTASK_INVALIDVARIABLEVALUE
' //
' // MessageText:
' //
' //  Variable "%1!s!" doesn't start with "/".
' //
%DTS_E_FTPTASK_INVALIDVARIABLEVALUE = &HC0029190&

' //
' // MessageId: DTS_E_FTPTASK_INVALIDREMOTEPATH
' //
' // MessageText:
' //
' //  Remote path "%1!s!" doesn't start with "/".
' //
%DTS_E_FTPTASK_INVALIDREMOTEPATH  = &HC0029191&

' //
' // MessageId: DTS_E_DTS_E_FTPTASK_CANNOT_ACQUIRE_CONNECTION
' //
' // MessageText:
' //
' //  There was an error acquiring the FTP connection. Please check if you have specified a valid connection type "%1!s!".
' //
%DTS_E_DTS_E_FTPTASK_CANNOT_ACQUIRE_CONNECTION = &HC0029192&

' //
' // MessageId: DTS_E_MSGQTASKUTIL_CERT_OPEN_STORE_FAILED
' //
' // MessageText:
' //
' //  Opening the certificate store failed.
' //
%DTS_E_MSGQTASKUTIL_CERT_OPEN_STORE_FAILED = &HC0029193&

' //
' // MessageId: DTS_E_MSGQTASKUTIL_CERT_FAILED_GETTING_DISPLAY_NAME
' //
' // MessageText:
' //
' //  An error occurred while retrieving the display name of the certificate.
' //
%DTS_E_MSGQTASKUTIL_CERT_FAILED_GETTING_DISPLAY_NAME = &HC0029194&

' //
' // MessageId: DTS_E_MSGQTASKUTIL_CERT_FAILED_GETTING_ISSUER_NAME
' //
' // MessageText:
' //
' //  An error occurred while retrieving the issuer name of the certificate.
' //
%DTS_E_MSGQTASKUTIL_CERT_FAILED_GETTING_ISSUER_NAME = &HC0029195&

' //
' // MessageId: DTS_E_MSGQTASKUTIL_CERT_FAILED_GETTING_FRIENDLY_NAME
' //
' // MessageText:
' //
' //  An error occurred while retrieving the friendly name of the certificate.
' //
%DTS_E_MSGQTASKUTIL_CERT_FAILED_GETTING_FRIENDLY_NAME = &HC0029196&

' //
' // MessageId: DTS_E_MSMQTASK_NO_CONNECTION
' //
' // MessageText:
' //
' //  The MSMQ connection name is not set.
' //
%DTS_E_MSMQTASK_NO_CONNECTION     = &HC0029197&

' //
' // MessageId: DTS_E_MSMQTASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  Task was initialized with the wrong XML element.
' //
%DTS_E_MSMQTASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT = &HC0029198&

' //
' // MessageId: DTS_E_MSMQTASK_DATA_FILE_NAME_EMPTY
' //
' // MessageText:
' //
' //  Data file name is empty.
' //
%DTS_E_MSMQTASK_DATA_FILE_NAME_EMPTY = &HC0029199&

' //
' // MessageId: DTS_E_MSMQTASK_DATA_FILE_SAVE_NAME_EMPTY
' //
' // MessageText:
' //
' //  The name specified for the data file to save is empty.
' //
%DTS_E_MSMQTASK_DATA_FILE_SAVE_NAME_EMPTY = &HC002919A&

' //
' // MessageId: DTS_E_MSMQTASK_DATA_FILE_SIZE_ERROR
' //
' // MessageText:
' //
' //  File size should be less than 4 MB.
' //
%DTS_E_MSMQTASK_DATA_FILE_SIZE_ERROR = &HC002919B&

' //
' // MessageId: DTS_E_MSMQTASK_DATA_FILE_SAVE_FAILED
' //
' // MessageText:
' //
' //  Saving the data file failed.
' //
%DTS_E_MSMQTASK_DATA_FILE_SAVE_FAILED = &HC002919C&

' //
' // MessageId: DTS_E_MSMQTASK_STRING_COMPARE_VALUE_MISSING
' //
' // MessageText:
' //
' //  String filter value is empty.
' //
%DTS_E_MSMQTASK_STRING_COMPARE_VALUE_MISSING = &HC002919D&

' //
' // MessageId: DTS_E_MSMQTASK_INVALID_QUEUE_PATH
' //
' // MessageText:
' //
' //  Queue path is not valid.
' //
%DTS_E_MSMQTASK_INVALID_QUEUE_PATH = &HC002919E&

' //
' // MessageId: DTS_E_MSMQTASK_QUEUE_NOT_TRANSACTIONAL
' //
' // MessageText:
' //
' //  Message is part of a transaction, but the queue is not transactional.
' //
%DTS_E_MSMQTASK_QUEUE_NOT_TRANSACTIONAL = &HC002919F&

' //
' // MessageId: DTS_E_MSMQTASK_INVALID_MESSAGE_TYPE
' //
' // MessageText:
' //
' //  The message type is not valid.
' //
%DTS_E_MSMQTASK_INVALID_MESSAGE_TYPE = &HC00291A0&

' //
' // MessageId: DTS_E_MSMQTASK_TASK_TIMEOUT
' //
' // MessageText:
' //
' //  The message queue timed out. No message has been received.
' //
%DTS_E_MSMQTASK_TASK_TIMEOUT      = &HC00291A1&

' //
' // MessageId: DTS_E_MSMQTASK_INVALID_PROPERTY_VALUE
' //
' // MessageText:
' //
' //  The property specified is not valid.Verify that the argument type is correct.
' //
%DTS_E_MSMQTASK_INVALID_PROPERTY_VALUE = &HC00291A2&

' //
' // MessageId: DTS_E_MSMQTASK_MESSAGE_NON_AUTHENTICATED
' //
' // MessageText:
' //
' //  Message is not authenticated.
' //
%DTS_E_MSMQTASK_MESSAGE_NON_AUTHENTICATED = &HC00291A3&

' //
' // MessageId: DTS_E_MSMQTASK_INVALID_ENCRYPTION_ALGO_WRAPPER
' //
' // MessageText:
' //
' //  You are trying to set the value of Encryption Algorithm with an invalid object.
' //
%DTS_E_MSMQTASK_INVALID_ENCRYPTION_ALGO_WRAPPER = &HC00291A4&

' //
' // MessageId: DTS_E_MSMQTASK_VARIABLE_TO_RECEIVE_STRING_MSG_EMPTY
' //
' // MessageText:
' //
' //  The variable to receive string message is empty.
' //
%DTS_E_MSMQTASK_VARIABLE_TO_RECEIVE_STRING_MSG_EMPTY = &HC00291A5&

' //
' // MessageId: DTS_E_MSMQTASK_RECEIVE_VARIABLE_EMPTY
' //
' // MessageText:
' //
' //  Variable to receive variable message is empty.
' //
%DTS_E_MSMQTASK_RECEIVE_VARIABLE_EMPTY = &HC00291A6&

' //
' // MessageId: DTS_E_MSMQTASK_CONNECTIONTYPENOTMSMQ
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type MSMQ.
' //
%DTS_E_MSMQTASK_CONNECTIONTYPENOTMSMQ = &HC00291A7&

' //
' // MessageId: DTS_E_MSMQTASK_DATAFILE_ALREADY_EXISTS
' //
' // MessageText:
' //
' //  The data file "%1!s!" already exists at the specified location. Cannot overwrite the file as the Overwrite option is set to false.
' //
%DTS_E_MSMQTASK_DATAFILE_ALREADY_EXISTS = &HC00291A8&

' //
' // MessageId: DTS_E_MSMQTASK_STRING_MSG_TO_VARIABLE_NOT_FOUND
' //
' // MessageText:
' //
' //  The specified variable "%1!s!" to receive string message is not found in the package variable collection.
' //
%DTS_E_MSMQTASK_STRING_MSG_TO_VARIABLE_NOT_FOUND = &HC00291A9&

' //
' // MessageId: DTS_E_MSMQTASK_CONNMNGRNULL
' //
' // MessageText:
' //
' //  The connection manager "%1!s!" is empty.
' //
%DTS_E_MSMQTASK_CONNMNGRNULL      = &HC00291AA&

' //
' // MessageId: DTS_E_MSMQTASK_CONNMNGRDOESNOTEXIST
' //
' // MessageText:
' //
' //  The connection manager "%1!s!" does not exist.
' //
%DTS_E_MSMQTASK_CONNMNGRDOESNOTEXIST = &HC00291AB&

' //
' // MessageId: DTS_E_SCRIPTTASK_COMPILEERRORMSG
' //
' // MessageText:
' //
' //  Error "%1!s!": "%2!s!"\r\nLine "%3!s!"   Column "%4!s!" through "%5!s!".
' //
%DTS_E_SCRIPTTASK_COMPILEERRORMSG = &HC00291AC&

' //
' // MessageId: DTS_E_SCRIPTTASK_COMPILEERRORMSG2
' //
' // MessageText:
' //
' //  There was an error compiling the script: "%1!s!".
' //
%DTS_E_SCRIPTTASK_COMPILEERRORMSG2 = &HC00291AD&

' //
' // MessageId: DTS_E_SCRIPTTASK_COMPILEERRORMSG3
' //
' // MessageText:
' //
' //  Error "%1!s!": "%2!s!"\r\nLine "%3!s!" Columns "%4!s!"-"%5!s!"\r\nLine Text: "%6!s!".
' //
%DTS_E_SCRIPTTASK_COMPILEERRORMSG3 = &HC00291AE&

' //
' // MessageId: DTS_E_SCRIPTTASK_SCRIPTREPORTEDFAILURE
' //
' // MessageText:
' //
' //  User script returned a failure result.
' //
%DTS_E_SCRIPTTASK_SCRIPTREPORTEDFAILURE = &HC00291AF&

' //
' // MessageId: DTS_E_SCRIPTTASK_SCRIPTFILESFAILEDTOLOAD
' //
' // MessageText:
' //
' //  User script files failed to load.
' //
%DTS_E_SCRIPTTASK_SCRIPTFILESFAILEDTOLOAD = &HC00291B0&

' //
' // MessageId: DTS_E_SCRIPTTASK_SCRIPTTHREWEXCEPTION
' //
' // MessageText:
' //
' //  User script threw an exception: "%1!s!".
' //
%DTS_E_SCRIPTTASK_SCRIPTTHREWEXCEPTION = &HC00291B1&

' //
' // MessageId: DTS_E_SCRIPTTASK_COULDNOTCREATEENTRYPOINTCLASS
' //
' // MessageText:
' //
' //  Could not create an instance of entrypoint class "%1!s!".
' //
%DTS_E_SCRIPTTASK_COULDNOTCREATEENTRYPOINTCLASS = &HC00291B2&

' //
' // MessageId: DTS_E_SCRIPTTASK_LOADFROMXMLEXCEPTION
' //
' // MessageText:
' //
' //  There was an exception while loading Script Task from XML: "%1!s!".
' //
%DTS_E_SCRIPTTASK_LOADFROMXMLEXCEPTION = &HC00291B3&

' //
' // MessageId: DTS_E_SCRIPTTASK_SOURCEITEMNOTFOUNDEXCEPTION
' //
' // MessageText:
' //
' //  Source item "%1!s!" was not found in the package.
' //
%DTS_E_SCRIPTTASK_SOURCEITEMNOTFOUNDEXCEPTION = &HC00291B4&

' //
' // MessageId: DTS_E_SCRIPTTASK_BINARYITEMNOTFOUNDEXCEPTION
' //
' // MessageText:
' //
' //  Binary item "%1!s!" was not found in the package.
' //
%DTS_E_SCRIPTTASK_BINARYITEMNOTFOUNDEXCEPTION = &HC00291B5&

' //
' // MessageId: DTS_E_SCRIPTTASK_UNRECOGNIZEDSCRIPTLANGUAGEEXCEPTION
' //
' // MessageText:
' //
' //  "%1!s!" was not recognized as a valid script language.
' //
%DTS_E_SCRIPTTASK_UNRECOGNIZEDSCRIPTLANGUAGEEXCEPTION = &HC00291B6&

' //
' // MessageId: DTS_E_SCRIPTTASK_ILLEGALSCRIPTNAME
' //
' // MessageText:
' //
' //  The script name is not valid. It cannot contain spaces, slashes, special characters, or begin with a number.
' //
%DTS_E_SCRIPTTASK_ILLEGALSCRIPTNAME = &HC00291B7&

' //
' // MessageId: DTS_E_SCRIPTTASK_INVALIDSCRIPTLANGUAGE
' //
' // MessageText:
' //
' //  The script language specified is not valid.
' //
%DTS_E_SCRIPTTASK_INVALIDSCRIPTLANGUAGE = &HC00291B8&

' //
' // MessageId: DTS_E_SCRIPTTASK_CANTINITNULLTASK
' //
' // MessageText:
' //
' //  Cannot initialize to a null task.
' //
%DTS_E_SCRIPTTASK_CANTINITNULLTASK = &HC00291B9&

' //
' // MessageId: DTS_E_SCRIPTTASK_MUSTINITWITHRIGHTTASK
' //
' // MessageText:
' //
' //  The Script Task user interface must initialize to an Script Task.
' //
%DTS_E_SCRIPTTASK_MUSTINITWITHRIGHTTASK = &HC00291BA&

' //
' // MessageId: DTS_E_SCRIPTTASK_WASNOTINITED
' //
' // MessageText:
' //
' //  The Script Task user interface is not initialized.
' //
%DTS_E_SCRIPTTASK_WASNOTINITED    = &HC00291BB&

' //
' // MessageId: DTS_E_SCRIPTTASK_HOST_NAME_CANT_EMPTY
' //
' // MessageText:
' //
' //  Name cannot be empty.
' //
%DTS_E_SCRIPTTASK_HOST_NAME_CANT_EMPTY = &HC00291BC&

' //
' // MessageId: DTS_E_SCRIPTTASK_INVALID_SCRIPT_NAME
' //
' // MessageText:
' //
' //  The project name is not valid. It cannot contain spaces, slashes, special characters, or begin with a number.
' //
%DTS_E_SCRIPTTASK_INVALID_SCRIPT_NAME = &HC00291BD&

' //
' // MessageId: DTS_E_SCRIPTTASK_INVALID_SCRIPT_LANGUAGE
' //
' // MessageText:
' //
' //  The script language specified is not valid.
' //
%DTS_E_SCRIPTTASK_INVALID_SCRIPT_LANGUAGE = &HC00291BE&

' //
' // MessageId: DTS_E_SCRIPTTASK_INVALID_ENTRY_POINT
' //
' // MessageText:
' //
' //  Entry point not found.
' //
%DTS_E_SCRIPTTASK_INVALID_ENTRY_POINT = &HC00291BF&

' //
' // MessageId: DTS_E_SCRIPTTASK_LANGUAGE_EMPTY
' //
' // MessageText:
' //
' //  The script language is not specified. Verify that a valid script language is specified.
' //
%DTS_E_SCRIPTTASK_LANGUAGE_EMPTY  = &HC00291C0&

' //
' // MessageId: DTS_E_SCRIPTTASK_INITIALIZATION_WITH_NULL_TASK
' //
' // MessageText:
' //
' //  User interface initialization: The task is null.
' //
%DTS_E_SCRIPTTASK_INITIALIZATION_WITH_NULL_TASK = &HC00291C1&

' //
' // MessageId: DTS_E_SCRIPTTASK_UI_INITIALIZATION_WITH_WRONG_TASK
' //
' // MessageText:
' //
' //  The Script Task user interface is initialized with an incorrect task.
' //
%DTS_E_SCRIPTTASK_UI_INITIALIZATION_WITH_WRONG_TASK = &HC00291C2&

' //
' // MessageId: DTS_E_SENDMAILTASK_RECIPIENT_EMPTY
' //
' // MessageText:
' //
' //  No recipient is specified.
' //
%DTS_E_SENDMAILTASK_RECIPIENT_EMPTY = &HC00291C3&

' //
' // MessageId: DTS_E_SENDMAILTASK_SMTP_SERVER_NOT_SPECIFIED
' //
' // MessageText:
' //
' //  The Simple Mail Transfer Protocol (SMTP) server is not specified. Provide a valid name or IP address of the SMTP server.
' //
%DTS_E_SENDMAILTASK_SMTP_SERVER_NOT_SPECIFIED = &HC00291C4&

' //
' // MessageId: DTS_E_SENDMAILTASK_TASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  Send Mail task is initiaited with an incorrect XML element.
' //
%DTS_E_SENDMAILTASK_TASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT = &HC00291C5&

' //
' // MessageId: DTS_E_SENDMAILTASK_INVALIDATTACHMENT
' //
' // MessageText:
' //
' //  Either the file "%1!s!" does not exist or you do not have permissions to access the file.
' //
%DTS_E_SENDMAILTASK_INVALIDATTACHMENT = &HC00291CB&

' //
' // MessageId: DTS_E_SENDMAILTASK_CHECK_VALID_SMTP_SERVER
' //
' // MessageText:
' //
' //  Verify that the Simple Mail Transfer Protocol (SMTP) server specified is valid.
' //
%DTS_E_SENDMAILTASK_CHECK_VALID_SMTP_SERVER = &HC00291CD&

' //
' // MessageId: DTS_E_SENDMAILTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type File.
' //
%DTS_E_SENDMAILTASK_CONNECTIONTYPENOTFILE = &HC00291CE&

' //
' // MessageId: DTS_E_SENDMAILTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  On operation "%1!s!", file "%2!s!" does not exist.
' //
%DTS_E_SENDMAILTASK_FILEDOESNOTEXIST = &HC00291CF&

' //
' // MessageId: DTS_E_SENDMAILTASK_VARIABLETYPEISNOTSTRING
' //
' // MessageText:
' //
' //  Variable "%1!s!" is not of type string.
' //
%DTS_E_SENDMAILTASK_VARIABLETYPEISNOTSTRING = &HC00291D0&

' //
' // MessageId: DTS_E_SENDMAILTASK_CONNECTIONTYPENOTSMTP
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type SMTP.
' //
%DTS_E_SENDMAILTASK_CONNECTIONTYPENOTSMTP = &HC00291D1&

' //
' // MessageId: DTS_E_SENDMAILTASK_CONNMNGRNULL
' //
' // MessageText:
' //
' //  Connection "%1!s!" is empty.
' //
%DTS_E_SENDMAILTASK_CONNMNGRNULL  = &HC00291D2&

' //
' // MessageId: DTS_E_SENDMAILTASK_NOCONNMNGR
' //
' // MessageText:
' //
' //  The specified connection "%1!s!" does not exist.
' //
%DTS_E_SENDMAILTASK_NOCONNMNGR    = &HC00291D3&

' //
' // MessageId: DTS_E_SQLTASK_NOSTATEMENTSPECIFIED
' //
' // MessageText:
' //
' //  No Transact-SQL statement specified.
' //
%DTS_E_SQLTASK_NOSTATEMENTSPECIFIED = &HC00291D4&

' //
' // MessageId: DTS_E_SQLTASK_NOXMLSUPPORT
' //
' // MessageText:
' //
' //  The connection does not support XML result sets.
' //
%DTS_E_SQLTASK_NOXMLSUPPORT       = &HC00291D5&

' //
' // MessageId: DTS_E_SQLTASK_NOHANDLERFORCONNECTION
' //
' // MessageText:
' //
' //  Cannot locate a handler for the specified connection type.
' //
%DTS_E_SQLTASK_NOHANDLERFORCONNECTION = &HC00291D6&

' //
' // MessageId: DTS_E_SQLTASK_NOCONNECTIONMANAGER
' //
' // MessageText:
' //
' //  No connection manager is specified.
' //
%DTS_E_SQLTASK_NOCONNECTIONMANAGER = &HC00291D7&

' //
' // MessageId: DTS_E_SQLTASK_CANNOTACQUIRECONNMANAGER
' //
' // MessageText:
' //
' //  Cannot aquire a connection from the connection manager.
' //
%DTS_E_SQLTASK_CANNOTACQUIRECONNMANAGER = &HC00291D8&

' //
' // MessageId: DTS_E_SQLTASK_NULLPARAMETERNAME
' //
' // MessageText:
' //
' //  Cannot have a null parameter name.
' //
%DTS_E_SQLTASK_NULLPARAMETERNAME  = &HC00291D9&

' //
' // MessageId: DTS_E_SQLTASK_INVALIDPARAMETERNAME
' //
' // MessageText:
' //
' //  The parameter name is not valid.
' //
%DTS_E_SQLTASK_INVALIDPARAMETERNAME = &HC00291DA&

' //
' // MessageId: DTS_E_SQLTASK_VALIDPARAMETERTYPES
' //
' // MessageText:
' //
' //  Valid parameter names are of type Int or String.
' //
%DTS_E_SQLTASK_VALIDPARAMETERTYPES = &HC00291DB&

' //
' // MessageId: DTS_E_SQLTASK_READONLYVARIABLE
' //
' // MessageText:
' //
' //  Variable "%1!s!" cannot be used in a result binding because it is read-only.
' //
%DTS_E_SQLTASK_READONLYVARIABLE   = &HC00291DC&

' //
' // MessageId: DTS_E_SQLTASK_INDESNOTINCOLLECTION
' //
' // MessageText:
' //
' //  The index is not assigned in this collection.
' //
%DTS_E_SQLTASK_INDESNOTINCOLLECTION = &HC00291DD&

' //
' // MessageId: DTS_E_SQLTASK_ROVARINOUTPARAMETER
' //
' // MessageText:
' //
' //  The variable "%1!s!" cannot be used as an "out" parameter or return value in a parameter binding because it is read-only.
' //
%DTS_E_SQLTASK_ROVARINOUTPARAMETER = &HC00291DE&

' //
' // MessageId: DTS_E_SQLTASK_OBJECTNOTINCOLLECTION
' //
' // MessageText:
' //
' //  The object does not exist in this collection.
' //
%DTS_E_SQLTASK_OBJECTNOTINCOLLECTION = &HC00291DF&

' //
' // MessageId: DTS_E_SQLTASK_UNABLETOACQUIREMANAGEDCONN
' //
' // MessageText:
' //
' //  Cannot acquire a managed connection.
' //
%DTS_E_SQLTASK_UNABLETOACQUIREMANAGEDCONN = &HC00291E0&

' //
' // MessageId: DTS_E_UNABLETOPOPRESULT
' //
' // MessageText:
' //
' //  Cannot populate the result columns for a single row result type. The query returned an empty result set.
' //
%DTS_E_UNABLETOPOPRESULT          = &HC00291E1&

' //
' // MessageId: DTS_E_SQLTASK_INVALIDNUMOFRESULTBINDINGS
' //
' // MessageText:
' //
' //  There is an invalid number of result bindings returned for the ResultSetType: "%1!s!".
' //
%DTS_E_SQLTASK_INVALIDNUMOFRESULTBINDINGS = &HC00291E2&

' //
' // MessageId: DTS_E_SQLTASK_RESULTBINDTYPEFORROWSETXML
' //
' // MessageText:
' //
' //  The result binding name must be set to zero for full result set and XML results.
' //
%DTS_E_SQLTASK_RESULTBINDTYPEFORROWSETXML = &HC00291E3&

' //
' // MessageId: DTS_E_SQLTASK_INVALIDEPARAMDIRECTIONFALG
' //
' // MessageText:
' //
' //  The parameter directions flag is not valid.
' //
%DTS_E_SQLTASK_INVALIDEPARAMDIRECTIONFALG = &HC00291E4&

' //
' // MessageId: DTS_E_SQLTASK_NOSQLTASKDATAINXMLFRAGMENT
' //
' // MessageText:
' //
' //  The XML fragment does not contain SQL Task data.
' //
%DTS_E_SQLTASK_NOSQLTASKDATAINXMLFRAGMENT = &HC00291E5&

' //
' // MessageId: DTS_E_SQLTASK_MULTIPLERETURNVALUEPARAM
' //
' // MessageText:
' //
' //  A parameter with type return value is not the first parameter, or there are more than one parameter of type return value.
' //
%DTS_E_SQLTASK_MULTIPLERETURNVALUEPARAM = &HC00291E6&

' //
' // MessageId: DTS_E_SQLTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not a file connection manager.
' //
%DTS_E_SQLTASK_CONNECTIONTYPENOTFILE = &HC00291E7&

' //
' // MessageId: DTS_E_SQLTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  File represented by "%1!s!" does not exist.
' //
%DTS_E_SQLTASK_FILEDOESNOTEXIST   = &HC00291E8&

' //
' // MessageId: DTS_E_SQLTASK_VARIABLETYPEISNOTSTRING
' //
' // MessageText:
' //
' //  Type of variable "%1!s!" is not string.
' //
%DTS_E_SQLTASK_VARIABLETYPEISNOTSTRING = &HC00291E9&

' //
' // MessageId: DTS_E_SQLTASK_VARIABLENOTFOUND
' //
' // MessageText:
' //
' //  Variable "%1!s!" does not exist or could not be locked.
' //
%DTS_E_SQLTASK_VARIABLENOTFOUND   = &HC00291EA&

' //
' // MessageId: DTS_E_SQLTASK_CANNOTLOCATECONNMANAGER
' //
' // MessageText:
' //
' //  Connection manager "%1!s!" does not exist.
' //
%DTS_E_SQLTASK_CANNOTLOCATECONNMANAGER = &HC00291EB&

' //
' // MessageId: DTS_E_SQLTASK_FAILEDTOACQUIRECONNECTION
' //
' // MessageText:
' //
' //  Failed to acquire connection "%1!s!". Connection may not be configured correctly or you may not have the right permissions on this connection.
' //
%DTS_E_SQLTASK_FAILEDTOACQUIRECONNECTION = &HC00291EC&

' //
' // MessageId: DTS_E_SQLTASK_RESULTBYNAMENOTSUPPORTED
' //
' // MessageText:
' //
' //  Result binding by name "%1!s!" is not supported for this connection type.
' //
%DTS_E_SQLTASK_RESULTBYNAMENOTSUPPORTED = &HC00291ED&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_NO_ROWS
' //
' // MessageText:
' //
' //  A result set type of single row is specified, but no rows were returned.
' //
%DTS_E_SQLTASKCONN_ERR_NO_ROWS    = &HC00291EE&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_NO_DISCONNECTED_RS
' //
' // MessageText:
' //
' //  No disconnected record set is available for the Transact-SQL statement.
' //
%DTS_E_SQLTASKCONN_ERR_NO_DISCONNECTED_RS = &HC00291EF&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_UNSUPPORTED_TYPE
' //
' // MessageText:
' //
' //  Unsupported type.
' //
%DTS_E_SQLTASKCONN_ERR_UNSUPPORTED_TYPE = &HC00291F0&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_UNKNOWN_TYPE
' //
' // MessageText:
' //
' //  Unknown type.
' //
%DTS_E_SQLTASKCONN_ERR_UNKNOWN_TYPE = &HC00291F1&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_PARAM_DATA_TYPE
' //
' // MessageText:
' //
' //  Unsupported data type on parameter binding \"%s\".
' //
%DTS_E_SQLTASKCONN_ERR_PARAM_DATA_TYPE = &HC00291F2&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_PARAM_NAME_MIX
' //
' // MessageText:
' //
' //  Parameter names cannot be an mix of ordinal and named types.
' //
%DTS_E_SQLTASKCONN_ERR_PARAM_NAME_MIX = &HC00291F3&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_PARAM_DIR
' //
' // MessageText:
' //
' //  The parameter direction on parameter binding \"%s\" is not valid.
' //
%DTS_E_SQLTASKCONN_ERR_PARAM_DIR  = &HC00291F4&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_RESULT_DATA_TYPE
' //
' // MessageText:
' //
' //  The data type on result set binding \"%s\" is not supported.
' //
%DTS_E_SQLTASKCONN_ERR_RESULT_DATA_TYPE = &HC00291F5&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_RESULT_COL_INDEX
' //
' // MessageText:
' //
' //  The result column index %d is not valid.
' //
%DTS_E_SQLTASKCONN_ERR_RESULT_COL_INDEX = &HC00291F6&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_UNKNOWN_RESULT_COL
' //
' // MessageText:
' //
' //  Cannot find column \"%s\" in the result set.
' //
%DTS_E_SQLTASKCONN_ERR_UNKNOWN_RESULT_COL = &HC00291F7&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_NOROWSET
' //
' // MessageText:
' //
' //  No result rowset is associated with the execution of this query.
' //
%DTS_E_SQLTASKCONN_ERR_NOROWSET   = &HC00291F9&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_ODBC_DISCONNECTED
' //
' // MessageText:
' //
' //  Disconnected recordsets are not available from ODBC connections.
' //
%DTS_E_SQLTASKCONN_ERR_ODBC_DISCONNECTED = &HC00291FA&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_RESULT_SET_DATA_TYPE
' //
' // MessageText:
' //
' //  The data type in the result set, column %hd, is not supported.
' //
%DTS_E_SQLTASKCONN_ERR_RESULT_SET_DATA_TYPE = &HC00291FB&

' //
' // MessageId: DTS_E_SQLTASKCONN_ERR_CANT_LOAD_XML
' //
' // MessageText:
' //
' //  Cannot load XML with query result.
' //
%DTS_E_SQLTASKCONN_ERR_CANT_LOAD_XML = &HC00291FC&

' //
' // MessageId: DTS_E_TTGENTASK_NOCONNORVARIABLE
' //
' // MessageText:
' //
' //  A connection name or variable name for the package must be specified.
' //
%DTS_E_TTGENTASK_NOCONNORVARIABLE = &HC00291FD&

' //
' // MessageId: DTS_E_TTGENTASK_FAILEDCREATE
' //
' // MessageText:
' //
' //  Failed to create the package.
' //
%DTS_E_TTGENTASK_FAILEDCREATE     = &HC00291FE&

' //
' // MessageId: DTS_E_TTGENTASK_BADTABLEMETADATA
' //
' // MessageText:
' //
' //  The TableMetaDataNode is not an XMLNode.
' //
%DTS_E_TTGENTASK_BADTABLEMETADATA = &HC00291FF&

' //
' // MessageId: DTS_E_TTGENTASK_FAILEDCREATEPIPELINE
' //
' // MessageText:
' //
' //  Failed to create the pipeline.
' //
%DTS_E_TTGENTASK_FAILEDCREATEPIPELINE = &HC0029200&

' //
' // MessageId: DTS_E_TTGENTASK_BADVARIABLETYPE
' //
' // MessageText:
' //
' //  The variable is not the correct type.
' //
%DTS_E_TTGENTASK_BADVARIABLETYPE  = &HC0029201&

' //
' // MessageId: DTS_E_TTGENTASK_NOTFILECONNECTION
' //
' // MessageText:
' //
' //  The connection manager specified is not a FILE connection manager.
' //
%DTS_E_TTGENTASK_NOTFILECONNECTION = &HC0029202&

' //
' // MessageId: DTS_E_TTGENTASK_BADFILENAME
' //
' // MessageText:
' //
' //  Invalid file name specified on the connection manager "%1!s!".
' //
%DTS_E_TTGENTASK_BADFILENAME      = &HC0029203&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CONNECTION_NAME_NULL
' //
' // MessageText:
' //
' //  The connection is empty. Verify that a valid HTTP connection is specified.
' //
%DTS_E_WEBSERVICETASK_CONNECTION_NAME_NULL = &HC0029204&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CONNECTION_NOT_FOUND
' //
' // MessageText:
' //
' //  The connection does not exist. Verify that a valid, existing HTTP connection is specified.
' //
%DTS_E_WEBSERVICETASK_CONNECTION_NOT_FOUND = &HC0029205&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CONNECTION_NOT_HTTP
' //
' // MessageText:
' //
' //  The connection specified is not a HTTP connection. Verify that a valid HTTP connection is specified.
' //
%DTS_E_WEBSERVICETASK_CONNECTION_NOT_HTTP = &HC0029206&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SERVICE_NULL
' //
' // MessageText:
' //
' //  The Web Service name is empty. Verify that a valid web service name is specified.
' //
%DTS_E_WEBSERVICETASK_SERVICE_NULL = &HC0029207&

' //
' // MessageId: DTS_E_WEBSERVICETASK_METHODNAME_NULL
' //
' // MessageText:
' //
' //  The web method name is empty. Verify that a valid web method is specified.
' //
%DTS_E_WEBSERVICETASK_METHODNAME_NULL = &HC0029208&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WEBMETHODINFO_NULL
' //
' // MessageText:
' //
' //  The web method is empty or may not exist. Verify that there is an existing web method to specify.
' //
%DTS_E_WEBSERVICETASK_WEBMETHODINFO_NULL = &HC0029209&

' //
' // MessageId: DTS_E_WEBSERVICETASK_OUTPUTLOC_NULL
' //
' // MessageText:
' //
' //  The output location is empty. Verify that an existing file connection or variable is specified.
' //
%DTS_E_WEBSERVICETASK_OUTPUTLOC_NULL = &HC002920A&

' //
' // MessageId: DTS_E_WEBSERVICETASK_VARIABLE_NOT_FOUND
' //
' // MessageText:
' //
' //  The variable cannot be found. Verify that the variable exists in the package.
' //
%DTS_E_WEBSERVICETASK_VARIABLE_NOT_FOUND = &HC002920B&

' //
' // MessageId: DTS_E_WEBSERVICETASK_VARIABLE_READONLY
' //
' // MessageText:
' //
' //  Cannot save the result. Verify that the variable is not read-only.
' //
%DTS_E_WEBSERVICETASK_VARIABLE_READONLY = &HC002920C&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ERROR_IN_LOAD_FROM_XML
' //
' // MessageText:
' //
' //  Error occurred in LoadFromXML at the tag "%1!s!".
' //
%DTS_E_WEBSERVICETASK_ERROR_IN_LOAD_FROM_XML = &HC002920D&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ERROR_IN_SAVE_TO_XML
' //
' // MessageText:
' //
' //  Error occurred in SaveToXML at the tag "%1!s!".
' //
%DTS_E_WEBSERVICETASK_ERROR_IN_SAVE_TO_XML = &HC002920E&

' //
' // MessageId: DTS_E_WEBSERVICETASK_TASK_SAVE_TO_NULL_XML_ELEMENT
' //
' // MessageText:
' //
' //  Cannot save the task to a null XML document.
' //
%DTS_E_WEBSERVICETASK_TASK_SAVE_TO_NULL_XML_ELEMENT = &HC002920F&

' //
' // MessageId: DTS_E_WEBSERVICETASK_TASK_INITIALIZATION_WITH_NULL_XML_ELEMENT
' //
' // MessageText:
' //
' //  Cannot initialize the task with a null XML element.
' //
%DTS_E_WEBSERVICETASK_TASK_INITIALIZATION_WITH_NULL_XML_ELEMENT = &HC0029210&

' //
' // MessageId: DTS_E_WEBSERVICETASK_TASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  The Web Service Task is initiated with an incorrect XML element.
' //
%DTS_E_WEBSERVICETASK_TASK_INITIALIZATION_WITH_WRONG_XML_ELEMENT = &HC0029211&

' //
' // MessageId: DTS_E_WEBSERVICETASK_UNEXPECTED_XML_ELEMENT
' //
' // MessageText:
' //
' //  Unexpected XML element found.
' //
%DTS_E_WEBSERVICETASK_UNEXPECTED_XML_ELEMENT = &HC0029212&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CANNOT_ACQUIRE_CONNECTION
' //
' // MessageText:
' //
' //  There was an error acquiring the HTTP connection. Verify that a valid connection type is specified.
' //
%DTS_E_WEBSERVICETASK_CANNOT_ACQUIRE_CONNECTION = &HC0029213&

' //
' // MessageId: DTS_E_WEBSERVICETASK_FILE_CONN_NOT_FOUND
' //
' // MessageText:
' //
' //  Cannot save the result. Verify that there is an existing file connection.
' //
%DTS_E_WEBSERVICETASK_FILE_CONN_NOT_FOUND = &HC0029214&

' //
' // MessageId: DTS_E_WEBSERVICETASK_FILE_NOT_FOUND
' //
' // MessageText:
' //
' //  Cannot save the result. Verify that the file exists.
' //
%DTS_E_WEBSERVICETASK_FILE_NOT_FOUND = &HC0029215&

' //
' // MessageId: DTS_E_WEBSERVICETASK_FILE_NULL
' //
' // MessageText:
' //
' //  Cannot save the result. The file name is empty or the file is in use by another proccess.
' //
%DTS_E_WEBSERVICETASK_FILE_NULL   = &HC0029216&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CANNOT_ACQUIRE_FILE_CONNECTION
' //
' // MessageText:
' //
' //  There was an error in acquiring the file connection. Verify that a valid file connection is specified.
' //
%DTS_E_WEBSERVICETASK_CANNOT_ACQUIRE_FILE_CONNECTION = &HC0029217&

' //
' // MessageId: DTS_E_WEBSERVICETASK_DATATYPE_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  Only Complex Types with Primitive values, Primitive Arrays, and Enumerations are supported.
' //
%DTS_E_WEBSERVICETASK_DATATYPE_NOT_SUPPORTED = &HC0029218&

' //
' // MessageId: DTS_E_WEBSERVICETASK_PARAMTYPE_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  Only Primitive, Enum, Complex, PrimitiveArray, and ComplexArray types are supported.
' //
%DTS_E_WEBSERVICETASK_PARAMTYPE_NOT_SUPPORTED = &HC0029219&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WSDL_VERSION_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  This version of WSDL is not supported.
' //
%DTS_E_WEBSERVICETASK_WSDL_VERSION_NOT_SUPPORTED = &HC002921A&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WRONG_XML_ELEMENT
' //
' // MessageText:
' //
' //  Initiailized with an incorrrect XML element.
' //
%DTS_E_WEBSERVICETASK_WRONG_XML_ELEMENT = &HC002921B&

' //
' // MessageId: DTS_E_WEBSERVICETASK_XML_ATTRIBUTE_NOT_FOUND
' //
' // MessageText:
' //
' //  A mandatory attribute is not found.
' //
%DTS_E_WEBSERVICETASK_XML_ATTRIBUTE_NOT_FOUND = &HC002921C&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ENUM_NO_VALUES
' //
' // MessageText:
' //
' //  The enum "%1!s!" does not have any values. The WSDL is corrupted.
' //
%DTS_E_WEBSERVICETASK_ENUM_NO_VALUES = &HC002921D&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CONNECTIONNOTFOUND
' //
' // MessageText:
' //
' //  The connection cannot be found.
' //
%DTS_E_WEBSERVICETASK_CONNECTIONNOTFOUND = &HC002921E&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CONNECTION_ALREADY_EXISTS
' //
' // MessageText:
' //
' //  Connection by this name already exists.
' //
%DTS_E_WEBSERVICETASK_CONNECTION_ALREADY_EXISTS = &HC002921F&

' //
' // MessageId: DTS_E_WEBSERVICETASK_NULL_CONNECTION
' //
' // MessageText:
' //
' //  Connection cannot be null or empty.
' //
%DTS_E_WEBSERVICETASK_NULL_CONNECTION = &HC0029220&

' //
' // MessageId: DTS_E_WEBSERVICETASK_NOT_HTTP_CONNECTION
' //
' // MessageText:
' //
' //  The connection specified is not a HTTP connection. Verify that a valid HTTP connection is specified.
' //
%DTS_E_WEBSERVICETASK_NOT_HTTP_CONNECTION = &HC0029221&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WSDL_NOT_FOUND
' //
' // MessageText:
' //
' //  The specified Uniform Resource Identifier (URI) does not contain a valid WSDL.
' //
%DTS_E_WEBSERVICETASK_WSDL_NOT_FOUND = &HC0029222&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ERROR_IN_DOWNLOAD
' //
' // MessageText:
' //
' //  Could not read the WSDL file. The input WSDL file is not valid. The reader threw the following error: "%1!s!".
' //
%DTS_E_WEBSERVICETASK_ERROR_IN_DOWNLOAD = &HC0029223&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SERVICE_DESC_NULL
' //
' // MessageText:
' //
' //  Service Description cannot be null.
' //
%DTS_E_WEBSERVICETASK_SERVICE_DESC_NULL = &HC0029224&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SERVICENULL
' //
' // MessageText:
' //
' //  Service name cannot be null.
' //
%DTS_E_WEBSERVICETASK_SERVICENULL = &HC0029225&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WSDL_NULL
' //
' // MessageText:
' //
' //  URL cannot be null.
' //
%DTS_E_WEBSERVICETASK_WSDL_NULL   = &HC0029226&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SERVICE_NOT_FOUND
' //
' // MessageText:
' //
' //  The service is not currently available.
' //
%DTS_E_WEBSERVICETASK_SERVICE_NOT_FOUND = &HC0029227&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SOAPPORT_NOT_FOUND
' //
' // MessageText:
' //
' //  The service is not available on the SOAP port.
' //
%DTS_E_WEBSERVICETASK_SOAPPORT_NOT_FOUND = &HC0029228&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SOAPBINDING_NOT_FOUND
' //
' // MessageText:
' //
' //  Failed to parse the Web Services Description Language (WSD&. Cannot find the Binding that corresponds to the SOAP port.
' //
%DTS_E_WEBSERVICETASK_SOAPBINDING_NOT_FOUND = &HC0029229&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SOAPPORTTYPE_NOT_FOUND
' //
' // MessageText:
' //
' //  Failed to parse the Web Services Description Language (WSD&. Cannot find a PortType that corresponds to the SOAP port.
' //
%DTS_E_WEBSERVICETASK_SOAPPORTTYPE_NOT_FOUND = &HC002922A&

' //
' // MessageId: DTS_E_WEBSERVICETASK_MSG_NOT_FOUND
' //
' // MessageText:
' //
' //  Cannot find the message that corresponds to the method specified.
' //
%DTS_E_WEBSERVICETASK_MSG_NOT_FOUND = &HC002922B&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CANNOT_GEN_PROXY
' //
' // MessageText:
' //
' //  Could not generate the proxy for the given web service. The following errors were encountered while generating the proxy "%1!s!".
' //
%DTS_E_WEBSERVICETASK_CANNOT_GEN_PROXY = &HC002922C&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CANNOT_LOAD_PROXY
' //
' // MessageText:
' //
' //  Could not load the proxy for the given web service. The exact error is as follows: "%1!s!".
' //
%DTS_E_WEBSERVICETASK_CANNOT_LOAD_PROXY = &HC002922D&

' //
' // MessageId: DTS_E_WEBSERVICETASK_INVALID_SERVICE
' //
' // MessageText:
' //
' //  Could not find the specified service. The exact error is as follows: "%1!s!".
' //
%DTS_E_WEBSERVICETASK_INVALID_SERVICE = &HC002922E&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WEBMETHOD_INVOKE_FAILED
' //
' // MessageText:
' //
' //  The Web Service threw the following error during method execution: "%1!s!".
' //
%DTS_E_WEBSERVICETASK_WEBMETHOD_INVOKE_FAILED = &HC002922F&

' //
' // MessageId: DTS_E_WEBSERVICETASK_INVOKE_ERR
' //
' // MessageText:
' //
' //  Could not execute the web method. The exact error is as follows: "%1!s!".
' //
%DTS_E_WEBSERVICETASK_INVOKE_ERR  = &HC0029230&

' //
' // MessageId: DTS_E_WEBSERVICETASK_METHODINFO_NULL
' //
' // MessageText:
' //
' //  MethodInfo cannot be null.
' //
%DTS_E_WEBSERVICETASK_METHODINFO_NULL = &HC0029231&

' //
' // MessageId: DTS_E_WEBSERVICETASK_VALUE_NOT_PRIMITIVE
' //
' // MessageText:
' //
' //  The specified WebMethodInfo is not correct. The ParamValue supplied does not match the ParamType. The DTSParamValue is not of type PrimitiveValue.
' //
%DTS_E_WEBSERVICETASK_VALUE_NOT_PRIMITIVE = &HC0029232&

' //
' // MessageId: DTS_E_WEBSERVICETASK_VALUE_NOT_ENUM
' //
' // MessageText:
' //
' //  The WebMethodInfo specified is not correct. The ParamValue supplied does not match the ParamType. The DTSParamValue found is not of type EnumValue.
' //
%DTS_E_WEBSERVICETASK_VALUE_NOT_ENUM = &HC0029233&

' //
' // MessageId: DTS_E_VALUE_WEBSERVICETASK_NOT_COMPLEX
' //
' // MessageText:
' //
' //  The WebMethodInfo specified is not correct. The ParamValue supplied does not match the ParamType. The DTSParamValue found is not of type ComplexValue.
' //
%DTS_E_VALUE_WEBSERVICETASK_NOT_COMPLEX = &HC0029234&

' //
' // MessageId: DTS_E_WEBSERVICETASK_VALUE_NOT_ARRAY
' //
' // MessageText:
' //
' //  The WebMethodInfo specified is not correct. The ParamValue supplied does not match the ParamType. The DTSParamValue found is not of type ArrayValue.
' //
%DTS_E_WEBSERVICETASK_VALUE_NOT_ARRAY = &HC0029235&

' //
' // MessageId: DTS_E_WEBSERVICETASK_TYPE_NOT_PRIMITIVE
' //
' // MessageText:
' //
' //  The WebMethodInfo you have specified is wrong. "%1!s!" is not Primitive Type.
' //
%DTS_E_WEBSERVICETASK_TYPE_NOT_PRIMITIVE = &HC0029236&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ARRAY_VALUE_INVALID
' //
' // MessageText:
' //
' //  The format of the ArrayValue is not valid. There should be at least one element in the array.
' //
%DTS_E_WEBSERVICETASK_ARRAY_VALUE_INVALID = &HC0029237&

' //
' // MessageId: DTS_E_WEBSERVICETASK_SELECTED_VALUE_NULL
' //
' // MessageText:
' //
' //  The value of the enumeration cannot be null. Select a default value for the enumeration.
' //
%DTS_E_WEBSERVICETASK_SELECTED_VALUE_NULL = &HC0029238&

' //
' // MessageId: DTS_E_WEBSERVICETASK_NULL_VALUE
' //
' // MessageText:
' //
' //  Cannot validate a null against any datatype.
' //
%DTS_E_WEBSERVICETASK_NULL_VALUE  = &HC0029239&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ENUM_VALUE_NOT_FOUND
' //
' // MessageText:
' //
' //  The enumeration Value is not correct.
' //
%DTS_E_WEBSERVICETASK_ENUM_VALUE_NOT_FOUND = &HC002923A&

' //
' // MessageId: DTS_E_WEBSERVICETASK_PROP_NOT_EXISTS
' //
' // MessageText:
' //
' //  The class specified does not contain a public property by the name "%1!s!".
' //
%DTS_E_WEBSERVICETASK_PROP_NOT_EXISTS = &HC002923B&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CONVERT_FAILED
' //
' // MessageText:
' //
' //  Could not convert "%1!s!" to "%2!s!".
' //
%DTS_E_WEBSERVICETASK_CONVERT_FAILED = &HC002923C&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CLEANUP_FAILED
' //
' // MessageText:
' //
' //  Cleanup failed. The proxy that was created for the web service may not have been deleted.
' //
%DTS_E_WEBSERVICETASK_CLEANUP_FAILED = &HC002923D&

' //
' // MessageId: DTS_E_WEBSERVICETASK_CREATE_INSTANCE_FAILED
' //
' // MessageText:
' //
' //  Could not create an object of type "%1!s!". Please check whether the default constructor exists.
' //
%DTS_E_WEBSERVICETASK_CREATE_INSTANCE_FAILED = &HC002923E&

' //
' // MessageId: DTS_E_WEBSERVICETASK_NOT_PRIMITIVE_TYPE
' //
' // MessageText:
' //
' //  "%1!s!" is not a value type.
' //
%DTS_E_WEBSERVICETASK_NOT_PRIMITIVE_TYPE = &HC002923F&

' //
' // MessageId: DTS_E_WEBSERVICETASK_ERROR_IN_VALIDATE
' //
' // MessageText:
' //
' //  Could not validate "%1!s!" against "%1!s!".
' //
%DTS_E_WEBSERVICETASK_ERROR_IN_VALIDATE = &HC0029240&

' //
' // MessageId: DTS_E_WEBSERVICETASK_DATATYPE_NULL
' //
' // MessageText:
' //
' //  The data type cannot be null. Specify the value of the data type to validate.
' //
%DTS_E_WEBSERVICETASK_DATATYPE_NULL = &HC0029241&

' //
' // MessageId: DTS_E_WEBSERVICETASK_INDEX_OUT_OF_BOUNDS
' //
' // MessageText:
' //
' //  The ParamValue cannot be inserted at this position. The index specified might be lesser than zero or greater than the length.
' //
%DTS_E_WEBSERVICETASK_INDEX_OUT_OF_BOUNDS = &HC0029242&

' //
' // MessageId: DTS_E_WEBSERVICETASK_WRONG_WSDL
' //
' // MessageText:
' //
' //  The input WSDL file is not valid.
' //
%DTS_E_WEBSERVICETASK_WRONG_WSDL  = &HC0029243&

' //
' // MessageId: DTS_E_WMIDRTASK_SYNCOBJECTFAILED
' //
' // MessageText:
' //
' //  Synchronization object failed.
' //
%DTS_E_WMIDRTASK_SYNCOBJECTFAILED = &HC0029244&

' //
' // MessageId: DTS_E_WMIDRTASK_MISSINGWQLQUERY
' //
' // MessageText:
' //
' //  The WQL query is missing.
' //
%DTS_E_WMIDRTASK_MISSINGWQLQUERY  = &HC0029245&

' //
' // MessageId: DTS_E_WMIDRTASK_DESTINATIONMUSTBESET
' //
' // MessageText:
' //
' //  The destination must be set.
' //
%DTS_E_WMIDRTASK_DESTINATIONMUSTBESET = &HC0029246&

' //
' // MessageId: DTS_E_WMIDRTASK_MISSINGCONNECTION
' //
' // MessageText:
' //
' //  No WMI connection is set.
' //
%DTS_E_WMIDRTASK_MISSINGCONNECTION = &HC0029247&

' //
' // MessageId: DTS_E_WMIDRTASK_INVALIDDATANODE
' //
' // MessageText:
' //
' //  WMI Data Reader Task received an invalid task data node.
' //
%DTS_E_WMIDRTASK_INVALIDDATANODE  = &HC0029248&

' //
' // MessageId: DTS_E_WMIDRTASK_FAILEDVALIDATION
' //
' // MessageText:
' //
' //  The task failed validation.
' //
%DTS_E_WMIDRTASK_FAILEDVALIDATION = &HC0029249&

' //
' // MessageId: DTS_E_WMIDRTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  File "%1!s!" does not exist.
' //
%DTS_E_WMIDRTASK_FILEDOESNOTEXIST = &HC002924A&

' //
' // MessageId: DTS_E_WMIDRTASK_CONNECTIONMNGRDOESNTEXIST
' //
' // MessageText:
' //
' //  Connection manager "%1!s!" does not exist.
' //
%DTS_E_WMIDRTASK_CONNECTIONMNGRDOESNTEXIST = &HC002924B&

' //
' // MessageId: DTS_E_WMIDRTASK_VARIABLETYPEISNOTSTRINGOROBJECT
' //
' // MessageText:
' //
' //  Variable "%1!s!" is not of type string or object.
' //
%DTS_E_WMIDRTASK_VARIABLETYPEISNOTSTRINGOROBJECT = &HC002924C&

' //
' // MessageId: DTS_E_WMIDRTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type "FILE".
' //
%DTS_E_WMIDRTASK_CONNECTIONTYPENOTFILE = &HC002924D&

' //
' // MessageId: DTS_E_WMIDRTASK_CONNECTIONTYPENOTWMI
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type "WMI".
' //
%DTS_E_WMIDRTASK_CONNECTIONTYPENOTWMI = &HC002924E&

' //
' // MessageId: DTS_E_WMIDRTASK_FILEALREADYEXISTS
' //
' // MessageText:
' //
' //  File "%1!s!" already exists.
' //
%DTS_E_WMIDRTASK_FILEALREADYEXISTS = &HC002924F&

' //
' // MessageId: DTS_E_WMIDRTASK_CONNECTIONMANAGEREMPTY
' //
' // MessageText:
' //
' //  Connection manager "%1!s!" is empty.
' //
%DTS_E_WMIDRTASK_CONNECTIONMANAGEREMPTY = &HC0029250&

' //
' // MessageId: DTS_E_WMIDRTASK_VARNOTOBJECT
' //
' // MessageText:
' //
' //  Variable "%1!s!" should be of type object to be assigned a data table.
' //
%DTS_E_WMIDRTASK_VARNOTOBJECT     = &HC0029251&

' //
' // MessageId: DTS_E_WMIDRTASK_TASKFAILURE
' //
' // MessageText:
' //
' //  Task failed due to invalid WMI query: "%1!s!".
' //
%DTS_E_WMIDRTASK_TASKFAILURE      = &HC0029252&

' //
' // MessageId: DTS_E_WMIDRTASK_CANTWRITETOVAR
' //
' // MessageText:
' //
' //  Unable to write to variable "%1!s!" since it set to keep its original value.
' //
%DTS_E_WMIDRTASK_CANTWRITETOVAR   = &HC0029253&

' //
' // MessageId: DTS_E_WMIEWTASK_SYNCOBJECTFAILED
' //
' // MessageText:
' //
' //  Synchronization object failed.
' //
%DTS_E_WMIEWTASK_SYNCOBJECTFAILED = &HC0029254&

' //
' // MessageId: DTS_E_WMIEWTASK_MISSINGWQLQUERY
' //
' // MessageText:
' //
' //  The WQL query is missing.
' //
%DTS_E_WMIEWTASK_MISSINGWQLQUERY  = &HC0029255&

' //
' // MessageId: DTS_E_WMIEWTASK_MISSINGCONNECTION
' //
' // MessageText:
' //
' //  The WMI connection is missing.
' //
%DTS_E_WMIEWTASK_MISSINGCONNECTION = &HC0029256&

' //
' // MessageId: DTS_E_WMIEWTASK_QUERYFAILURE
' //
' // MessageText:
' //
' //  The task failed to execute the WMI query.
' //
%DTS_E_WMIEWTASK_QUERYFAILURE     = &HC0029257&

' //
' // MessageId: DTS_E_WMIEWTASK_INVALIDDATANODE
' //
' // MessageText:
' //
' //  The WMI Event Watcher Task received a task data node that is not valid.
' //
%DTS_E_WMIEWTASK_INVALIDDATANODE  = &HC0029258&

' //
' // MessageId: DTS_E_WMIEWTASK_CONNECTIONMNGRDOESNTEXIST
' //
' // MessageText:
' //
' //  Connection manager "%1!s!" does not exist.
' //
%DTS_E_WMIEWTASK_CONNECTIONMNGRDOESNTEXIST = &HC0029259&

' //
' // MessageId: DTS_E_WMIEWTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  File "%1!s!" does not exist.
' //
%DTS_E_WMIEWTASK_FILEDOESNOTEXIST = &HC002925A&

' //
' // MessageId: DTS_E_WMIEWTASK_VARIABLETYPEISNOTSTRING
' //
' // MessageText:
' //
' //  Variable "%1!s!" is not of type string.
' //
%DTS_E_WMIEWTASK_VARIABLETYPEISNOTSTRING = &HC002925B&

' //
' // MessageId: DTS_E_WMIEWTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type "FILE".
' //
%DTS_E_WMIEWTASK_CONNECTIONTYPENOTFILE = &HC002925C&

' //
' // MessageId: DTS_E_WMIEWTASK_CONNECTIONTYPENOTWMI
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type "WMI".
' //
%DTS_E_WMIEWTASK_CONNECTIONTYPENOTWMI = &HC002925D&

' //
' // MessageId: DTS_E_WMIEWTASK_FILEALREADYEXISTS
' //
' // MessageText:
' //
' //  File "%1!s!" already exists.
' //
%DTS_E_WMIEWTASK_FILEALREADYEXISTS = &HC002925E&

' //
' // MessageId: DTS_E_WMIEWTASK_CONNECTIONMANAGEREMPTY
' //
' // MessageText:
' //
' //  Connection manager "%1!s!" is empty.
' //
%DTS_E_WMIEWTASK_CONNECTIONMANAGEREMPTY = &HC002925F&

' //
' // MessageId: DTS_E_WMIEWTASK_TIMEOUTOCCURRED
' //
' // MessageText:
' //
' //  Timeout of "%1!s!" second(s) occurred before event represented by "%2!s!".
' //
%DTS_E_WMIEWTASK_TIMEOUTOCCURRED  = &HC0029260&

' //
' // MessageId: DTS_E_WMIEWTASK_ERRMESSAGE
' //
' // MessageText:
' //
' //  Watching for the Wql query caused the following system exception: "%1!s!". Check the query for errors or WMI connection for access rights/permissions.
' //
%DTS_E_WMIEWTASK_ERRMESSAGE       = &HC0029261&

' //
' // MessageId: DTS_E_XMLTASK_NODEFAULTOPERTION
' //
' // MessageText:
' //
' //  The Operations specified is not defined.
' //
%DTS_E_XMLTASK_NODEFAULTOPERTION  = &HC0029262&

' //
' // MessageId: DTS_E_XMLTASK_CONNECTIONTYPENOTFILE
' //
' // MessageText:
' //
' //  The connection type is not File.
' //
%DTS_E_XMLTASK_CONNECTIONTYPENOTFILE = &HC0029263&

' //
' // MessageId: DTS_E_XMLTASK_CANTGETREADERFROMSOURCE
' //
' // MessageText:
' //
' //  Cannot get an XmlReader from the source XML document.
' //
%DTS_E_XMLTASK_CANTGETREADERFROMSOURCE = &HC0029264&

' //
' // MessageId: DTS_E_XMLTASK_CANTGETREADERFROMDEST
' //
' // MessageText:
' //
' //  Cannot get an XmlReader from the changed XML document.
' //
%DTS_E_XMLTASK_CANTGETREADERFROMDEST = &HC0029265&

' //
' // MessageId: DTS_E_XMLTASK_CANTGETREADERFROMDIFFGRAM
' //
' // MessageText:
' //
' //  Cannot get the XDL diffgram reader from the XDL diffgram XML.
' //
%DTS_E_XMLTASK_CANTGETREADERFROMDIFFGRAM = &HC0029266&

' //
' // MessageId: DTS_E_XMLTASK_EMPTYNODELIST
' //
' // MessageText:
' //
' //  The node list is empty.
' //
%DTS_E_XMLTASK_EMPTYNODELIST      = &HC0029268&

' //
' // MessageId: DTS_E_XMLTASK_NOELEMENTFOUND
' //
' // MessageText:
' //
' //  The element was not found.
' //
%DTS_E_XMLTASK_NOELEMENTFOUND     = &HC0029269&

' //
' // MessageId: DTS_E_XMLTASK_UNDEFINEDOPERATION
' //
' // MessageText:
' //
' //  The Operations specified is not defined.
' //
%DTS_E_XMLTASK_UNDEFINEDOPERATION = &HC002926A&

' //
' // MessageId: DTS_E_XMLTASK_XPATHNAVERROR
' //
' // MessageText:
' //
' //  Unexpected content item in XPathNavigator.
' //
%DTS_E_XMLTASK_XPATHNAVERROR      = &HC002926B&

' //
' // MessageId: DTS_E_XMLTASK_NOSCHEMAFOUND
' //
' // MessageText:
' //
' //  No schema found to enforce validation.
' //
%DTS_E_XMLTASK_NOSCHEMAFOUND      = &HC002926C&

' //
' // MessageId: DTS_E_XMLTASK_VALIDATIONERROR
' //
' // MessageText:
' //
' //  A validation error occurred when validating the instance document.
' //
%DTS_E_XMLTASK_VALIDATIONERROR    = &HC002926D&

' //
' // MessageId: DTS_E_XMLTASK_SYNCOBJECTFAILED
' //
' // MessageText:
' //
' //  Synchronization object failed.
' //
%DTS_E_XMLTASK_SYNCOBJECTFAILED   = &HC002926E&

' //
' // MessageId: DTS_E_XMLTASK_ROOTNOODESNOTMATCHED
' //
' // MessageText:
' //
' //  The root nodes do not match.
' //
%DTS_E_XMLTASK_ROOTNOODESNOTMATCHED = &HC002926F&

' //
' // MessageId: DTS_E_XMLTASK_INVALIDEDITSCRIPT
' //
' // MessageText:
' //
' //  The Edit Script Operation type in the final Edit Script is not valid.
' //
%DTS_E_XMLTASK_INVALIDEDITSCRIPT  = &HC0029270&

' //
' // MessageId: DTS_E_XMLTASK_CDATANODESISSUE
' //
' // MessageText:
' //
' //  CDATA nodes should be added with DiffgramAddSubtrees class.
' //
%DTS_E_XMLTASK_CDATANODESISSUE    = &HC0029271&

' //
' // MessageId: DTS_E_XMLTASK_COMMENTSNODEISSUE
' //
' // MessageText:
' //
' //  Comment nodes should be added with DiffgramAddSubtrees class.
' //
%DTS_E_XMLTASK_COMMENTSNODEISSUE  = &HC0029272&

' //
' // MessageId: DTS_E_XMLTASK_TEXTNODEISSUES
' //
' // MessageText:
' //
' //  Text nodes should be added with DiffgramAddSubtrees class.
' //
%DTS_E_XMLTASK_TEXTNODEISSUES     = &HC0029273&

' //
' // MessageId: DTS_E_XMLTASK_WHITESPACEISSUE
' //
' // MessageText:
' //
' //  Significant white space nodes should be added with DiffgramAddSubtrees class.
' //
%DTS_E_XMLTASK_WHITESPACEISSUE    = &HC0029274&

' //
' // MessageId: DTS_E_XMLTASK_DIFFENUMISSUE
' //
' // MessageText:
' //
' //  Correct the OperationCost array so that it reflects the XmlDiffOperation enumumeration.
' //
%DTS_E_XMLTASK_DIFFENUMISSUE      = &HC0029275&

' //
' // MessageId: DTS_E_XMLTASK_TASKISEMPTY
' //
' // MessageText:
' //
' //  There are no operations in the task.
' //
%DTS_E_XMLTASK_TASKISEMPTY        = &HC0029276&

' //
' // MessageId: DTS_E_XMLTASK_DOCUMENTHASDATA
' //
' // MessageText:
' //
' //  The document already contains data and should not be used again.
' //
%DTS_E_XMLTASK_DOCUMENTHASDATA    = &HC0029277&

' //
' // MessageId: DTS_E_XMLTASK_INVALIDENODETYPE
' //
' // MessageText:
' //
' //  The node type is not valid.
' //
%DTS_E_XMLTASK_INVALIDENODETYPE   = &HC0029278&

' //
' // MessageId: DTS_E_XMLTASK_INVALIDDATANODE
' //
' // MessageText:
' //
' //  The XML Task received a task data node that is not valid.
' //
%DTS_E_XMLTASK_INVALIDDATANODE    = &HC0029279&

' //
' // MessageId: DTS_E_XMLTASK_VARIABLETYPEISNOTSTRING
' //
' // MessageText:
' //
' //  Variable data type is not a String.
' //
%DTS_E_XMLTASK_VARIABLETYPEISNOTSTRING = &HC002927B&

' //
' // MessageId: DTS_E_XMLTASK_COULDNOTGETENCODINGFROMDOCUMENT
' //
' // MessageText:
' //
' //  Cannot get encoding from XML.
' //
%DTS_E_XMLTASK_COULDNOTGETENCODINGFROMDOCUMENT = &HC002927C&

' //
' // MessageId: DTS_E_XMLTASK_MISSINGSOURCE
' //
' // MessageText:
' //
' //  Source is not specified.
' //
%DTS_E_XMLTASK_MISSINGSOURCE      = &HC002927D&

' //
' // MessageId: DTS_E_XMLTASK_MISSINGSECONDOPERAND
' //
' // MessageText:
' //
' //  Second operand is not specified.
' //
%DTS_E_XMLTASK_MISSINGSECONDOPERAND = &HC002927E&

' //
' // MessageId: DTS_E_XMLTASK_INVALIDPATHDESCRIPTOR
' //
' // MessageText:
' //
' //  Invalid XDL diffgram. "%1!s!" is an invalid path descriptor.
' //
%DTS_E_XMLTASK_INVALIDPATHDESCRIPTOR = &HC002927F&

' //
' // MessageId: DTS_E_XMLTASK_NOMATCHINGNODE
' //
' // MessageText:
' //
' //  Invalid XDL diffgram. No node matches the path descriptor "%1!s!".
' //
%DTS_E_XMLTASK_NOMATCHINGNODE     = &HC0029280&

' //
' // MessageId: DTS_E_XMLTASK_EXPECTINGDIFFGRAMELEMENT
' //
' // MessageText:
' //
' //  Invalid XDL diffgram. Expecting xd:xmldiff as a root element with namespace URI "%1!s!".
' //
%DTS_E_XMLTASK_EXPECTINGDIFFGRAMELEMENT = &HC0029281&

' //
' // MessageId: DTS_E_XMLTASK_MISSINGSRCDOCATTRIBUTE
' //
' // MessageText:
' //
' //  The XDL diffgram is not valid. The srcDocHash attribute on the xd:xmldiff element is missing.
' //
%DTS_E_XMLTASK_MISSINGSRCDOCATTRIBUTE = &HC0029282&

' //
' // MessageId: DTS_E_XMLTASK_MISSINGOPTIONSATTRIBUTE
' //
' // MessageText:
' //
' //  The XDL diffgram is not valid. The options attribute on the xd:xmldiff element is missing.
' //
%DTS_E_XMLTASK_MISSINGOPTIONSATTRIBUTE = &HC0029283&

' //
' // MessageId: DTS_E_XMLTASK_INVALIDSRCDOCATTRIBUTE
' //
' // MessageText:
' //
' //  The XDL diffgram is not valid. The srcDocHash attribute has an invalid value.
' //
%DTS_E_XMLTASK_INVALIDSRCDOCATTRIBUTE = &HC0029284&

' //
' // MessageId: DTS_E_XMLTASK_INVALIDOPTIONSATTRIBUTE
' //
' // MessageText:
' //
' //  The XDL diffgram is not valid. The options attribute has an invalid value.
' //
%DTS_E_XMLTASK_INVALIDOPTIONSATTRIBUTE = &HC0029285&

' //
' // MessageId: DTS_E_XMLTASK_SRCDOCMISMATCH
' //
' // MessageText:
' //
' //  The XDL diffgram is not applicable to this XML document. The rcDocHash value does not match.
' //
%DTS_E_XMLTASK_SRCDOCMISMATCH     = &HC0029286&

' //
' // MessageId: DTS_E_XMLTASK_MORETHANONENODEMATCHED
' //
' // MessageText:
' //
' //  Invalid XDL diffgram; more than one node matches the "%1!s!" path descriptor on the xd:node or xd:change element.
' //
%DTS_E_XMLTASK_MORETHANONENODEMATCHED = &HC0029287&

' //
' // MessageId: DTS_E_XMLTASK_XMLDECLMISMATCH
' //
' // MessageText:
' //
' //  The XDL diffgram is not applicable to this XML document. A new XML declaration cannot be added.
' //
%DTS_E_XMLTASK_XMLDECLMISMATCH    = &HC0029288&

' //
' // MessageId: DTS_E_XMLTASK_INTERNALERRORMORETHANONENODEINLIST
' //
' // MessageText:
' //
' //  Internal Error. XmlDiffPathSingleNodeList can contain only one node.
' //
%DTS_E_XMLTASK_INTERNALERRORMORETHANONENODEINLIST = &HC0029289&

' //
' // MessageId: DTS_E_XMLTASK_INTERNALERRORMORETHANONENODELEFT
' //
' // MessageText:
' //
' //  Internal Error. "%1!s!" nodes left after patch, expecting 1.
' //
%DTS_E_XMLTASK_INTERNALERRORMORETHANONENODELEFT = &HC002928A&

' //
' // MessageId: DTS_E_XMLTASK_XSLTRESULTFILEISNOTXML
' //
' // MessageText:
' //
' //  The File/Text Produced by the XSLT is not a valid XmlDocument, thus can not be set as result of operation: "%1!s!".
' //
%DTS_E_XMLTASK_XSLTRESULTFILEISNOTXML = &HC002928B&

' //
' // MessageId: DTS_E_XMLTASK_FILEDOESNOTEXIST
' //
' // MessageText:
' //
' //  There is no file associated with connection "%1!s!".
' //
%DTS_E_XMLTASK_FILEDOESNOTEXIST   = &HC002928E&

' //
' // MessageId: DTS_E_XMLTASK_XMLTEXTEMPTY
' //
' // MessageText:
' //
' //  Property "%1!s!" has no source Xml text; Xml Text is either invalid, null or empty string.
' //
%DTS_E_XMLTASK_XMLTEXTEMPTY       = &HC002928F&

' //
' // MessageId: DTS_E_XMLTASK_FILEALREADYEXISTS
' //
' // MessageText:
' //
' //  File "%1!s!" already exists.
' //
%DTS_E_XMLTASK_FILEALREADYEXISTS  = &HC0029290&

' ////////////////////////////////////////////////////////////////////////////
' // The source connection was blank

' //
' // MessageId: DTS_E_TRANSFERTASKS_SRCCONNECTIONREQUIRED
' //
' // MessageText:
' //
' //  A source connection must be specified.
' //
%DTS_E_TRANSFERTASKS_SRCCONNECTIONREQUIRED = &HC0029293&

' ////////////////////////////////////////////////////////////////////////////
' // The destination connection can not be blank

' //
' // MessageId: DTS_E_TRANSFERTASKS_DESTCONNECTIONREQUIRED
' //
' // MessageText:
' //
' //  A destination connection must be specified.
' //
%DTS_E_TRANSFERTASKS_DESTCONNECTIONREQUIRED = &HC0029294&

' ////////////////////////////////////////////////////////////////////////////
' // The connection can not be found in the connections collection

' //
' // MessageId: DTS_E_TRANSFERTASKS_CONNECTIONNOTFOUND
' //
' // MessageText:
' //
' //  The connection "%1!s!" could not be found in the package.
' //
%DTS_E_TRANSFERTASKS_CONNECTIONNOTFOUND = &HC0029295&

' ////////////////////////////////////////////////////////////////////////////
' // Must be version 7 or later for transfer

' //
' // MessageId: DTS_E_TRANSFERTASKS_SERVERVERSIONNOTALLOWED
' //
' // MessageText:
' //
' //  The connection "%1!s!" specifies a SQL server with a version that is not supported for transfer.  Only version 7, 2000, and 2005 are supported.
' //
%DTS_E_TRANSFERTASKS_SERVERVERSIONNOTALLOWED = &HC0029296&

' ////////////////////////////////////////////////////////////////////////////
' // The src version must be less than or equal to the dest version

' //
' // MessageId: DTS_E_TRANSFERTASKS_SRCSERVERLESSEQUALDESTSERVER
' //
' // MessageText:
' //
' //  The source connection "%1!s!" must specify a SQL server with a version less than or equal to the destination connection "%2!s!".
' //
%DTS_E_TRANSFERTASKS_SRCSERVERLESSEQUALDESTSERVER = &HC0029297&

' ////////////////////////////////////////////////////////////////////////////
' // The source database is blank

' //
' // MessageId: DTS_E_TRANSFERTASKS_SRCDBREQUIRED
' //
' // MessageText:
' //
' //  A source database must be specified.
' //
%DTS_E_TRANSFERTASKS_SRCDBREQUIRED = &HC0029298&

' ////////////////////////////////////////////////////////////////////////////
' // The source server does not have the specified database name

' //
' // MessageId: DTS_E_TRANSFERTASKS_SRCDBMUSTEXIST
' //
' // MessageText:
' //
' //  The source database "%1!s!" must exist on the source server.
' //
%DTS_E_TRANSFERTASKS_SRCDBMUSTEXIST = &HC0029299&

' ////////////////////////////////////////////////////////////////////////////
' // The destination database name cannot be blank

' //
' // MessageId: DTS_E_TRANSFERTASKS_DESTDBREQUIRED
' //
' // MessageText:
' //
' //  A destination database must be specified.
' //
%DTS_E_TRANSFERTASKS_DESTDBREQUIRED = &HC002929A&

' ////////////////////////////////////////////////////////////////////////////
' // The source database name and the destination database name are the same and the source and destination connection specify the same SQL Server

' //
' // MessageId: DTS_E_TRANSFERTASKS_SRCDBANDDESTDBTHESAME
' //
' // MessageText:
' //
' //  The source database and the destination database can not be the same.
' //
%DTS_E_TRANSFERTASKS_SRCDBANDDESTDBTHESAME = &HC002929B&

' ////////////////////////////////////////////////////////////////////////////
' // The filename part of the fileinfo is missing

' //
' // MessageId: DTS_E_TRANSFERDBTASK_FILENAMEREQUIRED
' //
' // MessageText:
' //
' //  The transfer file information %1!s! is missing the filename.
' //
%DTS_E_TRANSFERDBTASK_FILENAMEREQUIRED = &HC002929C&

' ////////////////////////////////////////////////////////////////////////////
' // The folder part of the fileinfo is missing

' //
' // MessageId: DTS_E_TRANSFERDBTASK_FOLDERREQUIRED
' //
' // MessageText:
' //
' //  The transfer file information %1!s! is missing the folder part.
' //
%DTS_E_TRANSFERDBTASK_FOLDERREQUIRED = &HC002929D&

' ////////////////////////////////////////////////////////////////////////////
' // The network share part of the fileinfo is missing

' //
' // MessageId: DTS_E_TRANSFERTASKS_NETSHAREREQUIRED
' //
' // MessageText:
' //
' //  The transfer file information %1!s! is missing the network share part.
' //
%DTS_E_TRANSFERTASKS_NETSHAREREQUIRED = &HC002929E&

' ////////////////////////////////////////////////////////////////////////////
' // The two transfer files lists have different number of files

' //
' // MessageId: DTS_E_TRANSFERTASKS_FILELISTSCOUNTMISMATCH
' //
' // MessageText:
' //
' //  The number of source transfer files and the number of destination transfer files must be the same.
' //
%DTS_E_TRANSFERTASKS_FILELISTSCOUNTMISMATCH = &HC002929F&

' ////////////////////////////////////////////////////////////////////////////
' // A transaction was specified but this task does not support enlisting in transactions

' //
' // MessageId: DTS_E_DOESNOTSUPPORTTRANSACTIONS
' //
' // MessageText:
' //
' //  Enlisting in transactions is not supported.
' //
%DTS_E_DOESNOTSUPPORTTRANSACTIONS = &HC00292A0&

' ////////////////////////////////////////////////////////////////////////////
' // The shown exception occurred during an offline transfer

' //
' // MessageId: DTS_E_TRANSFERDBTASK_OFFLINEERROR
' //
' // MessageText:
' //
' //  The following exception occurred during an offline database transfer: %1!s!.
' //
%DTS_E_TRANSFERDBTASK_OFFLINEERROR = &HC00292A1&

' ////////////////////////////////////////////////////////////////////////////
' // The share specified for for copying from or to could does not exist

' //
' // MessageId: DTS_E_TRANSFERDBTASK_NETSHAREDOESNOTEXIST
' //
' // MessageText:
' //
' //  The network share "%1!s!" could not be found.
' //
%DTS_E_TRANSFERDBTASK_NETSHAREDOESNOTEXIST = &HC00292A2&

' ////////////////////////////////////////////////////////////////////////////
' // There was an error accessing the share.  This is usally due to permissions

' //
' // MessageId: DTS_E_TRANSFERDBTASK_NETSHARENOACCESS
' //
' // MessageText:
' //
' //  The network share "%1!s! could not be accessed.  The error is: %2!s!.
' //
%DTS_E_TRANSFERDBTASK_NETSHARENOACCESS = &HC00292A3&

' ////////////////////////////////////////////////////////////////////////////
' // The user is not a sysadmin or dbo for the specified database

' //
' // MessageId: DTS_E_TRANSFERDBTASK_USERMUSTBEDBOORSYSADMIN
' //
' // MessageText:
' //
' //  The user "%1!s!" must be a DBO or a sysadmin for "%2!s!" in order to perform an online database transfer.
' //
%DTS_E_TRANSFERDBTASK_USERMUSTBEDBOORSYSADMIN = &HC00292A4&

' ////////////////////////////////////////////////////////////////////////////
' // The user must be a sysadmin to detach and attach a database and that is what is done in an offline transfer

' //
' // MessageId: DTS_E_TRANSFERDBTASK_USERMUSTBESYSADMIN
' //
' // MessageText:
' //
' //  The user "%1!s!" must be a sysadmin on "%2!s!" to perform an offline database transfer.
' //
%DTS_E_TRANSFERDBTASK_USERMUSTBESYSADMIN = &HC00292A5&

' ////////////////////////////////////////////////////////////////////////////
' // Full text catalogs transfers can only be included when doing an offline transfer between 2 yukon servers

' //
' // MessageId: DTS_E_TRANSFERDBTASK_FTCATALOGSOFFLINEYUKONONLY
' //
' // MessageText:
' //
' //  Full text catalogs can only be included when performing an offline database transfer between 2 SQL Server 2005 servers.
' //
%DTS_E_TRANSFERDBTASK_FTCATALOGSOFFLINEYUKONONLY = &HC00292A6&

' ////////////////////////////////////////////////////////////////////////////
' // The destination database already exists on the destination server

' //
' // MessageId: DTS_E_TRANSFERDBTASK_NOOVERWRITEDB
' //
' // MessageText:
' //
' //  The database "%1!s!" already exists on the destination server "%2!s!".
' //
%DTS_E_TRANSFERDBTASK_NOOVERWRITEDB = &HC00292A7&

' ////////////////////////////////////////////////////////////////////////////
' // No source files were specified

' //
' // MessageId: DTS_E_TRANSFERDBTASK_MUSTHAVESOURCEFILES
' //
' // MessageText:
' //
' //  At least one source file must be specified.
' //
%DTS_E_TRANSFERDBTASK_MUSTHAVESOURCEFILES = &HC00292A8&

' ////////////////////////////////////////////////////////////////////////////
' // A file was specified to be transferred but it no longer exists on the source database

' //
' // MessageId: DTS_E_TRANSFERDBTASKS_SRCFILENOTFOUND
' //
' // MessageText:
' //
' //  Could not find the file "%1!s!" in the source database "%2!s!".
' //
%DTS_E_TRANSFERDBTASKS_SRCFILENOTFOUND = &HC00292A9&

' //
' // MessageId: DTS_E_MSMQTASK_FIPS1402COMPLIANCE
' //
' // MessageText:
' //
' //  The operation requested is not allowed in systems compliant with U.S. FIPS 140-2.
' //
%DTS_E_MSMQTASK_FIPS1402COMPLIANCE = &HC00292B3&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the task is not configure correctly (ResultSet property or parameter types are incorrect), or if there is a problem executing the query.

' //
' // MessageId: DTS_E_SQLTASK_ERROREXECUTINGTHEQUERY
' //
' // MessageText:
' //
' //  Executing the query "%1!s!" failed with the following error: "%2!s!". Possible failure reasons: Problems with the query, "ResultSet" property not set correctly, parameters not set correctly, or connection not established correctly.
' //
%DTS_E_SQLTASK_ERROREXECUTINGTHEQUERY = &HC002F210&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the format of the persisted stored procedures is corrupted and cannot be loaded into the stored procedure names's string collection of the task

' //
' // MessageId: DTS_E_TRANSFERSPTASK_ERRORREADINGSPNAMES
' //
' // MessageText:
' //
' //  Error reading stored procedure names from the xml file.
' //
%DTS_E_TRANSFERSPTASK_ERRORREADINGSPNAMES = &HC002F300&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the xml of Transfer Stored Procedure task's main node's name is corrupted and cannot be loaded into the task.

' //
' // MessageId: DTS_E_TRANSFERSPTASK_INVALIDDATANODE
' //
' // MessageText:
' //
' //  Invalid data node for the Transfer Stored Procedure task.
' //
%DTS_E_TRANSFERSPTASK_INVALIDDATANODE = &HC002F301&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when the connection manager specified is not of type "SMOServer"

' //
' // MessageId: DTS_E_TRANSFERTASKS_CONNECTIONTYPEISNOTSMOSERVER
' //
' // MessageText:
' //
' //  Connection "%1!s!" is not of type "SMOServer".
' //
%DTS_E_TRANSFERTASKS_CONNECTIONTYPEISNOTSMOSERVER = &HC002F302&

' ////////////////////////////////////////////////////////////////////////////
' // Happens when some infra structure functionality used by the task failes. The error from the system is wrapped in this message and printed out.

' //
' // MessageId: DTS_E_TRANSFERSPTASK_EXECUTIONFAILED
' //
' // MessageText:
' //
' //  Execution failed with the following error "%1!s!".
' //
%DTS_E_TRANSFERSPTASK_EXECUTIONFAILED = &HC002F303&

' //
' // MessageId: DTS_E_ERROROCCURREDWITHFOLLOWINGMESSAGE
' //
' // MessageText:
' //
' //  An error occurred with the following error message: "%1!s!".
' //
%DTS_E_ERROROCCURREDWITHFOLLOWINGMESSAGE = &HC002F304&

' //
' // MessageId: DTS_E_BITASK_EXECUTION_FAILED
' //
' // MessageText:
' //
' //  Bulk insert execution failed.
' //
%DTS_E_BITASK_EXECUTION_FAILED    = &HC002F305&

' //
' // MessageId: DTS_E_FSTASK_INVALIDDESTPATH
' //
' // MessageText:
' //
' //  Invalid destination path.
' //
%DTS_E_FSTASK_INVALIDDESTPATH     = &HC002F306&

' //
' // MessageId: DTS_E_FSTASK_CANTCREATEDIR
' //
' // MessageText:
' //
' //  Can not create directory. User chose to fail the task if directory exists.
' //
%DTS_E_FSTASK_CANTCREATEDIR       = &HC002F307&

' //
' // MessageId: DTS_E_SQLTASK_ODBCNOSUPPORTTRANSACTION
' //
' // MessageText:
' //
' //  The task has a transaction option of "Required" and connection "%1!s!" is of type "ODBC". ODBC connections don't support transactions.
' //
%DTS_E_SQLTASK_ODBCNOSUPPORTTRANSACTION = &HC002F308&

' //
' // MessageId: DTS_E_SQLTASK_ERRORASSIGINGVALUETOVAR
' //
' // MessageText:
' //
' //  An error occurred while assigning a value to variable "%1!s!": "%2!s!".
' //
%DTS_E_SQLTASK_ERRORASSIGINGVALUETOVAR = &HC002F309&

' //
' // MessageId: DTS_E_FSTASK_SOURCEISEMPTY
' //
' // MessageText:
' //
' //  The source is empty.
' //
%DTS_E_FSTASK_SOURCEISEMPTY       = &HC002F30A&

' //
' // MessageId: DTS_E_FSTASK_DESTINATIONISEMPTY
' //
' // MessageText:
' //
' //  The destination is empty.
' //
%DTS_E_FSTASK_DESTINATIONISEMPTY  = &HC002F30B&

' //
' // MessageId: DTS_E_FSTASK_FILEDIRNOTFOUND
' //
' // MessageText:
' //
' //  File or directory "%1!s!" does not exist.
' //
%DTS_E_FSTASK_FILEDIRNOTFOUND     = &HC002F30C&

' //
' // MessageId: DTS_E_FSTASK_VARSRCORDESTISEMPTY
' //
' // MessageText:
' //
' //  Variable "%1!s!" is used as a source or destination and is empty.
' //
%DTS_E_FSTASK_VARSRCORDESTISEMPTY = &HC002F30D&

' //
' // MessageId: DTS_E_FSTASK_FILEDELETED
' //
' // MessageText:
' //
' //  File or directory "%1!s!" was deleted.
' //
%DTS_E_FSTASK_FILEDELETED         = &HC002F30E&

' //
' // MessageId: DTS_E_FSTASK_DIRECTORYDELETED
' //
' // MessageText:
' //
' //  Directory "%1!s!" was deleted.
' //
%DTS_E_FSTASK_DIRECTORYDELETED    = &HC002F30F&

' //
' // MessageId: DTS_E_WMIDRTASK_VARIABLETYPEISNOTOBJECT
' //
' // MessageText:
' //
' //  The variable "%1!s!" should be of type object to be assigned a data table.
' //
%DTS_E_WMIDRTASK_VARIABLETYPEISNOTOBJECT = &HC002F310&

' //
' // MessageId: DTS_E_WMIDRTASK_VARIABLETYPEISNOTSTRING
' //
' // MessageText:
' //
' //  The variable "%1!s!" does not have a string data type.
' //
%DTS_E_WMIDRTASK_VARIABLETYPEISNOTSTRING = &HC002F311&

' //
' // MessageId: DTS_E_FTPTASK_CANNOTACQUIRECONNECTION
' //
' // MessageText:
' //
' //  There was an error acquiring the FTP connection. Verify that a valid connection type is specified in "%1!s!".
' //
%DTS_E_FTPTASK_CANNOTACQUIRECONNECTION = &HC002F312&

' //
' // MessageId: DTS_E_FTPTASK_CONNECTIONNOTFOUND
' //
' // MessageText:
' //
' //  Connection manager "%1!s!" can not be found.
' //
%DTS_E_FTPTASK_CONNECTIONNOTFOUND = &HC002F313&

' //
' // MessageId: DTS_E_FTPTASK_FILEUSAGETYPEERROR
' //
' // MessageText:
' //
' //  File usage type of connection "%1!s!" should be "%2!s!" for operation "%3!s!".
' //
%DTS_E_FTPTASK_FILEUSAGETYPEERROR = &HC002F314&

' //
' // MessageId: DTS_E_TRANSFERTASKS_SOURCECANTBESAMEASDESTINATION
' //
' // MessageText:
' //
' //  The source server can not be the same as the destination server.
' //
%DTS_E_TRANSFERTASKS_SOURCECANTBESAMEASDESTINATION = &HC002F315&

' //
' // MessageId: DTS_E_ERRMSGTASK_EMPTYSOURCELIST
' //
' // MessageText:
' //
' //  There are no Error Messages to transfer.
' //
%DTS_E_ERRMSGTASK_EMPTYSOURCELIST = &HC002F316&

' //
' // MessageId: DTS_E_ERRMSGTASK_DIFFERENTMESSAGEANDLANGUAGESIZES
' //
' // MessageText:
' //
' //  The lists of error messages and their corresponding languages are of different sizes.
' //
%DTS_E_ERRMSGTASK_DIFFERENTMESSAGEANDLANGUAGESIZES = &HC002F317&

' //
' // MessageId: DTS_E_ERRMSGTASK_ERRORMESSAGEOUTOFRANGE
' //
' // MessageText:
' //
' //  The error message id "%1!s!" is out of the allowed range of user defined error messages. User defined error message ids are between 50000 and 2147483647.
' //
%DTS_E_ERRMSGTASK_ERRORMESSAGEOUTOFRANGE = &HC002F318&

' //
' // MessageId: DTS_E_TRANSFERTASKS_NOTRANSACTIONSUPPORT
' //
' // MessageText:
' //
' //  This task can not participate in a transaction.
' //
%DTS_E_TRANSFERTASKS_NOTRANSACTIONSUPPORT = &HC002F319&

' //
' // MessageId: DTS_E_ERRMSGTASK_FAILEDTOTRANSFERERRORMESSAGES
' //
' // MessageText:
' //
' //  Failed to transfer some or all of the Error Messages.
' //
%DTS_E_ERRMSGTASK_FAILEDTOTRANSFERERRORMESSAGES = &HC002F320&

' //
' // MessageId: DTS_E_ERRMSGTASK_ERRORMESSAGEALREADYEXISTS
' //
' // MessageText:
' //
' //  The error message "%1!s!" already exists at destination server.
' //
%DTS_E_ERRMSGTASK_ERRORMESSAGEALREADYEXISTS = &HC002F321&

' //
' // MessageId: DTS_E_ERRMSGTASK_ERRORMESSAGECANTBEFOUND
' //
' // MessageText:
' //
' //  The error message "%1!s!" can not be found at source server.
' //
%DTS_E_ERRMSGTASK_ERRORMESSAGECANTBEFOUND = &HC002F324&

' //
' // MessageId: DTS_E_TRANSFERTASKS_EXECUTIONFAILED
' //
' // MessageText:
' //
' //  Execution failed with the following error: "%1!s!".
' //
%DTS_E_TRANSFERTASKS_EXECUTIONFAILED = &HC002F325&

' //
' // MessageId: DTS_E_JOBSTASK_FAILEDTOTRANSFERJOBS
' //
' // MessageText:
' //
' //  Failed to transfer the Job(s).
' //
%DTS_E_JOBSTASK_FAILEDTOTRANSFERJOBS = &HC002F327&

' //
' // MessageId: DTS_E_JOBSTASK_EMPTYSOURCELIST
' //
' // MessageText:
' //
' //  There are no Jobs to transfer.
' //
%DTS_E_JOBSTASK_EMPTYSOURCELIST   = &HC002F330&

' //
' // MessageId: DTS_E_JOBSTASK_JOBEXISTSATDEST
' //
' // MessageText:
' //
' //  The job "%1!s!" already exists at destination server.
' //
%DTS_E_JOBSTASK_JOBEXISTSATDEST   = &HC002F331&

' //
' // MessageId: DTS_E_JOBSTASK_JOBCANTBEFOUND
' //
' // MessageText:
' //
' //  The job "%1!s!" can not be found at source server.
' //
%DTS_E_JOBSTASK_JOBCANTBEFOUND    = &HC002F334&

' //
' // MessageId: DTS_E_LOGINSTASK_EMPTYLIST
' //
' // MessageText:
' //
' //  The list of "Logins" to transfer is empty.
' //
%DTS_E_LOGINSTASK_EMPTYLIST       = &HC002F337&

' //
' // MessageId: DTS_E_LOGINSTASK_CANTGETLOGINSNAMELIST
' //
' // MessageText:
' //
' //  Can not get the list of "Logins" from source server.
' //
%DTS_E_LOGINSTASK_CANTGETLOGINSNAMELIST = &HC002F338&

' //
' // MessageId: DTS_E_LOGINSTASK_ERRORLOGINEXISTS
' //
' // MessageText:
' //
' //  Login "%1!s!" already exists at destination server.
' //
%DTS_E_LOGINSTASK_ERRORLOGINEXISTS = &HC002F340&

' //
' // MessageId: DTS_E_LOGINSTASK_LOGINNOTFOUND
' //
' // MessageText:
' //
' //  Login "%1!s!" does not exist at source.
' //
%DTS_E_LOGINSTASK_LOGINNOTFOUND   = &HC002F342&

' //
' // MessageId: DTS_E_LOGINSTASK_FAILEDTOTRANSFERLOGINS
' //
' // MessageText:
' //
' //  Failed to transfer some or all of the logins.
' //
%DTS_E_LOGINSTASK_FAILEDTOTRANSFERLOGINS = &HC002F344&

' //
' // MessageId: DTS_E_STOREDPROCSTASK_FAILEDTOTRANSFERSPS
' //
' // MessageText:
' //
' //  Failed to transfer the stored procedure(s). More informative error should have been raised.
' //
%DTS_E_STOREDPROCSTASK_FAILEDTOTRANSFERSPS = &HC002F345&

' //
' // MessageId: DTS_E_STOREDPROCSTASK_STOREDPROCNOTFOUND
' //
' // MessageText:
' //
' //  Stored Procedure "%1!s!" is not found at the source.
' //
%DTS_E_STOREDPROCSTASK_STOREDPROCNOTFOUND = &HC002F346&

' //
' // MessageId: DTS_E_STOREDPROCSTASK_ERRORSTOREDPROCEDUREEXISTS
' //
' // MessageText:
' //
' //  Stored procedure "%1!s!" already exists at destination server.
' //
%DTS_E_STOREDPROCSTASK_ERRORSTOREDPROCEDUREEXISTS = &HC002F349&

' //
' // MessageId: DTS_E_STOREDPROCSTASK_EMPTYSOURCELIST
' //
' // MessageText:
' //
' //  There are no stored procedures to transfer.
' //
%DTS_E_STOREDPROCSTASK_EMPTYSOURCELIST = &HC002F350&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_FAILEDTOTRANSFEROBJECTS
' //
' // MessageText:
' //
' //  Failed to transfer the object(s).
' //
%DTS_E_TRANSOBJECTSTASK_FAILEDTOTRANSFEROBJECTS = &HC002F353&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_EMPTYLIST
' //
' // MessageText:
' //
' //  The list of "Objects" to transfer is empty.
' //
%DTS_E_TRANSOBJECTSTASK_EMPTYLIST = &HC002F354&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOSPATSOURCE
' //
' // MessageText:
' //
' //  Stored procedure "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOSPATSOURCE = &HC002F355&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_SPALREADYATDEST
' //
' // MessageText:
' //
' //  Stored procedure "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_SPALREADYATDEST = &HC002F356&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGSPS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Stored Procedures list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGSPS = &HC002F357&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NORULEATSOURCE
' //
' // MessageText:
' //
' //  Rule "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NORULEATSOURCE = &HC002F359&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_RULEALREADYATDEST
' //
' // MessageText:
' //
' //  Rule "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_RULEALREADYATDEST = &HC002F360&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGRULES
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Rules list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGRULES = &HC002F361&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOTABLEATSOURCE
' //
' // MessageText:
' //
' //  Table "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOTABLEATSOURCE = &HC002F363&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_TABLEALREADYATDEST
' //
' // MessageText:
' //
' //  Table "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_TABLEALREADYATDEST = &HC002F364&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGTABLES
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Tables list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGTABLES = &HC002F365&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOVIEWATSOURCE
' //
' // MessageText:
' //
' //  View "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOVIEWATSOURCE = &HC002F367&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_VIEWALREADYATDEST
' //
' // MessageText:
' //
' //  View "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_VIEWALREADYATDEST = &HC002F368&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGVIEWS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Views list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGVIEWS = &HC002F369&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOUDFATSOURCE
' //
' // MessageText:
' //
' //  User Defined Function "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOUDFATSOURCE = &HC002F371&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_UDFALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Function "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_UDFALREADYATDEST = &HC002F372&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGUDFS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the User Defined Functions list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGUDFS = &HC002F373&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NODEFAULTATSOURCE
' //
' // MessageText:
' //
' //  Default "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NODEFAULTATSOURCE = &HC002F375&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_DEFAULTALREADYATDEST
' //
' // MessageText:
' //
' //  Default "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_DEFAULTALREADYATDEST = &HC002F376&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGDEFAULTS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Defaults list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGDEFAULTS = &HC002F377&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOUDDTATSOURCE
' //
' // MessageText:
' //
' //  User Defined Data Type "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOUDDTATSOURCE = &HC002F379&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_UDDTALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Data Type "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_UDDTALREADYATDEST = &HC002F380&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGUDDTS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the User Defined Data Types list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGUDDTS = &HC002F381&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOPFATSOURCE
' //
' // MessageText:
' //
' //  Partition Function "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOPFATSOURCE = &HC002F383&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_PFALREADYATDEST
' //
' // MessageText:
' //
' //  Partition Function "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_PFALREADYATDEST = &HC002F384&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGPFS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Partition Functions list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGPFS = &HC002F385&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOPSATSOURCE
' //
' // MessageText:
' //
' //  Partition Scheme "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOPSATSOURCE = &HC002F387&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_PSALREADYATDEST
' //
' // MessageText:
' //
' //  Partition Scheme "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_PSALREADYATDEST = &HC002F388&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGPSS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Partition Schemes list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGPSS = &HC002F389&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOSCHEMAATSOURCE
' //
' // MessageText:
' //
' //  Schema "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOSCHEMAATSOURCE = &HC002F391&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_SCHEMAALREADYATDEST
' //
' // MessageText:
' //
' //  Schema "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_SCHEMAALREADYATDEST = &HC002F392&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGSCHEMAS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Schemas list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGSCHEMAS = &HC002F393&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOSQLASSEMBLYATSOURCE
' //
' // MessageText:
' //
' //  SqlAssembly "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOSQLASSEMBLYATSOURCE = &HC002F395&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_SQLASSEMBLYALREADYATDEST
' //
' // MessageText:
' //
' //  SqlAssembly "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_SQLASSEMBLYALREADYATDEST = &HC002F396&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGSQLASSEMBLIES
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the SqlAssemblys list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGSQLASSEMBLIES = &HC002F397&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOAGGREGATEATSOURCE
' //
' // MessageText:
' //
' //  User Defined Aggregate "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOAGGREGATEATSOURCE = &HC002F399&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_AGGREGATEALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Aggregate "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_AGGREGATEALREADYATDEST = &HC002F400&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGAGGREGATES
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the User Defined Aggregates list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGAGGREGATES = &HC002F401&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOTYPEATSOURCE
' //
' // MessageText:
' //
' //  User Defined Type "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOTYPEATSOURCE = &HC002F403&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_TYPEALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Type "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_TYPEALREADYATDEST = &HC002F404&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGTYPES
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the User Defined Types list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGTYPES = &HC002F405&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOXMLSCHEMACOLLECTIONATSOURCE
' //
' // MessageText:
' //
' //  XmlSchemaCollection "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOXMLSCHEMACOLLECTIONATSOURCE = &HC002F407&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_XMLSCHEMACOLLECTIONALREADYATDEST
' //
' // MessageText:
' //
' //  XmlSchemaCollection "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_XMLSCHEMACOLLECTIONALREADYATDEST = &HC002F408&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGXMLSCHEMACOLLECTIONS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the XmlSchemaCollections list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGXMLSCHEMACOLLECTIONS = &HC002F409&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_SUPPORTEDONYUKONONLY
' //
' // MessageText:
' //
' //  Objects of type "%1!s!" are only supported between SQL Server 2005 servers.
' //
%DTS_E_TRANSOBJECTSTASK_SUPPORTEDONYUKONONLY = &HC002F411&

' //
' // MessageId: DTS_E_LOGINSTASK_EMPTYDATABASELIST
' //
' // MessageText:
' //
' //  The databases list is empty.
' //
%DTS_E_LOGINSTASK_EMPTYDATABASELIST = &HC002F413&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOLOGINATSOURCE
' //
' // MessageText:
' //
' //  Login "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOLOGINATSOURCE = &HC002F414&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_LOGINALREADYATDEST
' //
' // MessageText:
' //
' //  Login "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_LOGINALREADYATDEST = &HC002F416&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGLOGINS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Logins list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGLOGINS = &HC002F417&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_NOUSERATSOURCE
' //
' // MessageText:
' //
' //  User "%1!s!" does not exist at the source.
' //
%DTS_E_TRANSOBJECTSTASK_NOUSERATSOURCE = &HC002F419&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_USERALREADYATDEST
' //
' // MessageText:
' //
' //  User "%1!s!" already exists at destination.
' //
%DTS_E_TRANSOBJECTSTASK_USERALREADYATDEST = &HC002F41B&

' //
' // MessageId: DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGUSERS
' //
' // MessageText:
' //
' //  An error occurred while trying to get set the Users list to transfer: "%1!s!".
' //
%DTS_E_TRANSOBJECTSTASK_ERRORHANDLINGUSERS = &HC002F41C&

' //
' // MessageId: DTS_E_BITASK_CANNOTRETAINCONNINTRANSACTION
' //
' // MessageText:
' //
' //  The task can not have a retained connection manager in a transaction.
' //
%DTS_E_BITASK_CANNOTRETAINCONNINTRANSACTION = &HC002F41F&

' //
' // MessageId: DTS_I_FSTASK_DIRECTORYDELETED
' //
' // MessageText:
' //
' //  Directory "%1!s!" was deleted.
' //
%DTS_I_FSTASK_DIRECTORYDELETED    = &H40029161&

' //
' // MessageId: DTS_I_FSTASK_FILEDELETED
' //
' // MessageText:
' //
' //  File or directory "%1!s!" was deleted.
' //
%DTS_I_FSTASK_FILEDELETED         = &H40029162&

' ////////////////////////////////////////////////////////////////////////////
' // The database on the destination is being overwritten because it exists and overwrite is set to true

' //
' // MessageId: DTS_I_TRANSFERDBTASK_OVERWRITEDB
' //
' // MessageText:
' //
' //  Overwriting the database "%1!s!" on the destination server "%2!s!".
' //
%DTS_I_TRANSFERDBTASK_OVERWRITEDB = &H400292A8&

' //
' // MessageId: DTS_I_SOMETHINGHAPPENED
' //
' // MessageText:
' //
' //  "%1!s!".
' //
%DTS_I_SOMETHINGHAPPENED          = &H4002F304&

' //
' // MessageId: DTS_I_ERRMSGTASK_SKIPPINGERRORMESSAGEALREADYEXISTS
' //
' // MessageText:
' //
' //  Skipping error message "%1!s!" since it already exists on the destination server.
' //
%DTS_I_ERRMSGTASK_SKIPPINGERRORMESSAGEALREADYEXISTS = &H4002F323&

' //
' // MessageId: DTS_I_ERRMSGTASK_TRANSFEREDNERRORMESSAGES
' //
' // MessageText:
' //
' //  "%1!s!" Error Messages were transferred.
' //
%DTS_I_ERRMSGTASK_TRANSFEREDNERRORMESSAGES = &H4002F326&

' //
' // MessageId: DTS_I_STOREDPROCSTASKS_TRANSFEREDNSPS
' //
' // MessageText:
' //
' //  The task transferred "%1!s!" Stored Procedures.
' //
%DTS_I_STOREDPROCSTASKS_TRANSFEREDNSPS = &H4002F351&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_TRANSFEREDNOBJECTS
' //
' // MessageText:
' //
' //  Transferred "%1!s!" objects.
' //
%DTS_I_TRANSOBJECTSTASK_TRANSFEREDNOBJECTS = &H4002F352&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOSPSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Stored Procedures to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOSPSTOTRANSFER = &H4002F358&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NORULESTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Rules to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NORULESTOTRANSFER = &H4002F362&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOTABLESTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Tables to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOTABLESTOTRANSFER = &H4002F366&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOVIEWSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Views to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOVIEWSTOTRANSFER = &H4002F370&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOUDFSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no User Defined Functions to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOUDFSTOTRANSFER = &H4002F374&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NODEFAULTSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Defaults to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NODEFAULTSTOTRANSFER = &H4002F378&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOUDDTSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no User Defined Data Types to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOUDDTSTOTRANSFER = &H4002F382&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOPFSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Partition Functions to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOPFSTOTRANSFER = &H4002F386&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOPSSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Partition Schemes to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOPSSTOTRANSFER = &H4002F390&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOSCHEMASTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Schemas to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOSCHEMASTOTRANSFER = &H4002F394&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOSQLASSEMBLIESTOTRANSFER
' //
' // MessageText:
' //
' //  There are no SqlAssemblys to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOSQLASSEMBLIESTOTRANSFER = &H4002F398&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOAGGREGATESTOTRANSFER
' //
' // MessageText:
' //
' //  There are no User Defined Aggregates to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOAGGREGATESTOTRANSFER = &H4002F402&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOTYPESTOTRANSFER
' //
' // MessageText:
' //
' //  There are no User Defined Types to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOTYPESTOTRANSFER = &H4002F406&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOXMLSCHEMACOLLECTIONSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no XmlSchemaCollections to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOXMLSCHEMACOLLECTIONSTOTRANSFER = &H4002F410&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOLOGINSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Logins to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOLOGINSTOTRANSFER = &H4002F418&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_NOUSERSTOTRANSFER
' //
' // MessageText:
' //
' //  There are no Users to transfer.
' //
%DTS_I_TRANSOBJECTSTASK_NOUSERSTOTRANSFER = &H4002F41D&

' //
' // MessageId: DTS_I_TRANSOBJECTSTASK_TRUNCATINGTABLE
' //
' // MessageText:
' //
' //  Truncating table "%1!s!"
' //
%DTS_I_TRANSOBJECTSTASK_TRUNCATINGTABLE = &H4002F41E&

' //
' // MessageId: DTS_W_FTPTASK_OPERATIONFAILURE
' //
' // MessageText:
' //
' //  Operation "%1!s!" failed.
' //
%DTS_W_FTPTASK_OPERATIONFAILURE   = &H80020918&

' //
' // MessageId: DTS_W_FSTASK_OPERATIONFAILURE
' //
' // MessageText:
' //
' //  Task failed to execute operation "%1!s!".
' //
%DTS_W_FSTASK_OPERATIONFAILURE    = &H80029164&

' //
' // MessageId: DTS_W_EXECPROCTASK_FILENOTINPATH
' //
' // MessageText:
' //
' //  File/Process "%1!s!" is not in path.
' //
%DTS_W_EXECPROCTASK_FILENOTINPATH = &H80029185&

' //
' // MessageId: DTS_W_SENDMAILTASK_SUBJECT_MISSING
' //
' // MessageText:
' //
' //  The subject is empty.
' //
%DTS_W_SENDMAILTASK_SUBJECT_MISSING = &H800291C6&

' //
' // MessageId: DTS_W_SENDMAILTASK_ERROR_IN_TO_LINE
' //
' // MessageText:
' //
' //  The address in the "To" line is malformed. It is either missing the "@" symbol or is not valid.
' //
%DTS_W_SENDMAILTASK_ERROR_IN_TO_LINE = &H800291C7&

' //
' // MessageId: DTS_W_SENDMAILTASK_AT_MISSING_IN_FROM
' //
' // MessageText:
' //
' //  The address in the "From" line is malformed. It is either missing the "@" symbol or is not valid.
' //
%DTS_W_SENDMAILTASK_AT_MISSING_IN_FROM = &H800291C8&

' //
' // MessageId: DTS_w_SENDMAILTASK_ERROR_IN_CC_LINE
' //
' // MessageText:
' //
' //  The address in the "Cc" line is malformed. It is either missing the "@" symbol or is not valid.
' //
%DTS_w_SENDMAILTASK_ERROR_IN_CC_LINE = &H800291C9&

' //
' // MessageId: DTS_w_SENDMAILTASK_ERROR_IN_BCC_LINE
' //
' // MessageText:
' //
' //  The address in the "Bcc" line is malformed. It is either missing the "@" symbol or is not valid.
' //
%DTS_w_SENDMAILTASK_ERROR_IN_BCC_LINE = &H800291CA&

' //
' // MessageId: DTS_W_XMLTASK_DIFFFAILURE
' //
' // MessageText:
' //
' //  The two XML documents are different.
' //
%DTS_W_XMLTASK_DIFFFAILURE        = &H8002927A&

' //
' // MessageId: DTS_W_XMLTASK_DTDVALIDATIONWARNING
' //
' // MessageText:
' //
' //  DTD Validation will use the DTD file defined in the DOCTYPE line in the XML document. It will not use what is assigned to the property "%1!s!".
' //
%DTS_W_XMLTASK_DTDVALIDATIONWARNING = &H8002928C&

' //
' // MessageId: DTS_W_XMLTASK_VALIDATIONFAILURE
' //
' // MessageText:
' //
' //  Task failed to validate "%1!s!".
' //
%DTS_W_XMLTASK_VALIDATIONFAILURE  = &H8002928D&

' ////////////////////////////////////////////////////////////////////////////
' // The value in the XML was invalid so it is being set to copy

' //
' // MessageId: DTS_W_TRANSFERDBTASK_ACTIONSETTOCOPY
' //
' // MessageText:
' //
' //  The transfer action value was invalid.  It is being set to copy.
' //
%DTS_W_TRANSFERDBTASK_ACTIONSETTOCOPY = &H80029291&

' ////////////////////////////////////////////////////////////////////////////
' // The value in the XML was invalid and it is being set to an online transfer

' //
' // MessageId: DTS_W_TRANSFERDBTASK_METHODSETTOONLINE
' //
' // MessageText:
' //
' //  The transfer method value was invalid.  It is being set to an online transfer.
' //
%DTS_W_TRANSFERDBTASK_METHODSETTOONLINE = &H80029292&

' //
' // MessageId: DTS_W_PROBLEMOCCURREDWITHFOLLOWINGMESSAGE
' //
' // MessageText:
' //
' //  A problem occurred with the following messages: "%1!s!".
' //
%DTS_W_PROBLEMOCCURREDWITHFOLLOWINGMESSAGE = &H8002F304&

' //
' // MessageId: DTS_W_ERRMSGTASK_ERRORMESSAGEALREADYEXISTS
' //
' // MessageText:
' //
' //  The error message "%1!s!" already exists at destination server.
' //
%DTS_W_ERRMSGTASK_ERRORMESSAGEALREADYEXISTS = &H8002F322&

' //
' // MessageId: DTS_W_JOBSTASK_JOBEXISTSATDEST
' //
' // MessageText:
' //
' //  The job "%1!s!" already exists at destination server.
' //
%DTS_W_JOBSTASK_JOBEXISTSATDEST   = &H8002F331&

' //
' // MessageId: DTS_W_JOBSTASK_SKIPPINGJOBEXISTSATDEST
' //
' // MessageText:
' //
' //  Skipping the transfer of job "%1!s!" since it already exists at destination.
' //
%DTS_W_JOBSTASK_SKIPPINGJOBEXISTSATDEST = &H8002F332&

' //
' // MessageId: DTS_W_JOBSTASK_OVERWRITINGJOB
' //
' // MessageText:
' //
' //  Overwriting the job "%1!s!" at destination server.
' //
%DTS_W_JOBSTASK_OVERWRITINGJOB    = &H8002F333&

' //
' // MessageId: DTS_W_LOGINSTASK_ENUMVALUEINCORRECT
' //
' // MessageText:
' //
' //  Persisted enumeration value of property "FailIfExists" was changed and rendered invalid. Resetting to default.
' //
%DTS_W_LOGINSTASK_ENUMVALUEINCORRECT = &H8002F339&

' //
' // MessageId: DTS_W_LOGINSTASK_OVERWRITINGLOGINATDEST
' //
' // MessageText:
' //
' //  Overwriting Login "%1!s!" at destination.
' //
%DTS_W_LOGINSTASK_OVERWRITINGLOGINATDEST = &H8002F343&

' //
' // MessageId: DTS_E_STOREDPROCSTASK_OVERWRITINGSPATDESTINATION
' //
' // MessageText:
' //
' //  Overwriting Stored Procedure "%1!s!" at destination.
' //
%DTS_E_STOREDPROCSTASK_OVERWRITINGSPATDESTINATION = &H8002F347&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_SPALREADYATDEST
' //
' // MessageText:
' //
' //  Stored procedure "{0}" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_SPALREADYATDEST = &H8002F356&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_RULEALREADYATDEST
' //
' // MessageText:
' //
' //  Rule "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_RULEALREADYATDEST = &H8002F360&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_TABLEALREADYATDEST
' //
' // MessageText:
' //
' //  Table "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_TABLEALREADYATDEST = &H8002F364&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_VIEWALREADYATDEST
' //
' // MessageText:
' //
' //  View "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_VIEWALREADYATDEST = &H8002F368&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_UDFALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Function "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_UDFALREADYATDEST = &H8002F372&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_DEFAULTALREADYATDEST
' //
' // MessageText:
' //
' //  Default "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_DEFAULTALREADYATDEST = &H8002F376&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_UDDTALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Data Type "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_UDDTALREADYATDEST = &H8002F380&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_PFALREADYATDEST
' //
' // MessageText:
' //
' //  Partition Function "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_PFALREADYATDEST = &H8002F384&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_PSALREADYATDEST
' //
' // MessageText:
' //
' //  Partition Scheme "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_PSALREADYATDEST = &H8002F388&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_SCHEMAALREADYATDEST
' //
' // MessageText:
' //
' //  Schema "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_SCHEMAALREADYATDEST = &H8002F391&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_SQLASSEMBLYALREADYATDEST
' //
' // MessageText:
' //
' //  SqlAssembly "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_SQLASSEMBLYALREADYATDEST = &H8002F396&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_AGGREGATEALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Aggregate "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_AGGREGATEALREADYATDEST = &H8002F400&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_TYPEALREADYATDEST
' //
' // MessageText:
' //
' //  User Defined Type "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_TYPEALREADYATDEST = &H8002F404&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_XMLSCHEMACOLLECTIONALREADYATDEST
' //
' // MessageText:
' //
' //  XmlSchemaCollection "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_XMLSCHEMACOLLECTIONALREADYATDEST = &H8002F408&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_NOELEMENTSPECIFIEDTOTRANSFER
' //
' // MessageText:
' //
' //  There are no elements specified to transfer.
' //
%DTS_W_TRANSOBJECTSTASK_NOELEMENTSPECIFIEDTOTRANSFER = &H8002F412&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_LOGINALREADYATDEST
' //
' // MessageText:
' //
' //  Login "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_LOGINALREADYATDEST = &H8002F415&

' //
' // MessageId: DTS_W_TRANSOBJECTSTASK_USERALREADYATDEST
' //
' // MessageText:
' //
' //  User "%1!s!" already exists at destination.
' //
%DTS_W_TRANSOBJECTSTASK_USERALREADYATDEST = &H8002F41A&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY            = &H40103100&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_PREEXECUTE
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_PREEXECUTE = &H40103101&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_POSTEXECUTE
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_POSTEXECUTE = &H40103102&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_PREVALIDATE
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_PREVALIDATE = &H40103103&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_POSTVALIDATE
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_POSTVALIDATE = &H40103104&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_WARNING
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_WARNING    = &H40103105&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_ERROR
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_ERROR      = &H40103106&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_TASKFAILED
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_TASKFAILED = &H40103107&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_PROGRESS
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_PROGRESS   = &H40103108&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_EXECSTATCHANGE
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_EXECSTATCHANGE = &H40103109&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_VARVALCHANGE
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_VARVALCHANGE = &H4010310A&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_CUSTOMEVENT
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_CUSTOMEVENT = &H4010310B&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_PACKAGESTART
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_PACKAGESTART = &H4010310C&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_PACKAGEEND
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_PACKAGEEND = &H4010310D&

' //
' // MessageId: DTS_MSG_EVENTLOGENTRY_INFORMATION
' //
' // MessageText:
' //
' //    Event Name: %1%r Message: %9%r Operator: %2%r Source Name: %3%r Source ID: %4%r Execution ID: %5%r Start Time: %6%r End Time: %7%r Data Code: %8
' //
%DTS_MSG_EVENTLOGENTRY_INFORMATION = &H4010310E&

