' ########################################################################################
' Microsoft Windows
' File: OledbErr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEDBERR_INC = 1

#IF NOT %DEF(%FACILITY_WINDOWS)
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

%FACILITY_WINDOWS                = &H8
%FACILITY_STORAGE                = &H3
%FACILITY_ITF                    = &H4


'//
'// Define the severity codes
'//
%STATUS_SEVERITY_SUCCESS         = &H0
%STATUS_SEVERITY_COERROR         = &H2


'//
'// MessageId: DB_E_BOGUS
'//
'// MessageText:
'//
'//  Dummy error - need this error so that mc puts the above defines
'//  inside the FACILITY_WINDOWS guard, instead of leaving it empty
'//
%DB_E_BOGUS                       = &H80040EFF&

#ENDIF   ' // FACILITY_WINDOWS

'//
'// Codes 0x0e00-0x0eff are reserved for the OLE DB group of
'// interfaces.
'//
'// Free codes are:
'//
'//      Error:
'//
'//
'//      Success:
'//         0x0eea
'//
'//


'//
'// OLEDBVER
'//   OLE DB version number (0x0270); this can be overridden with an older
'// version number if necessary
'//

'// If OLEDBVER is not defined, assume version 2.7
#IF NOT %DEF(%OLEDBVER)
%OLEDBVER = &H0270
#ENDIF

'//
'// MessageId: DB_E_BADACCESSORHANDLE
'//
'// MessageText:
'//
'//  Accessor is invalid.
'//
%DB_E_BADACCESSORHANDLE           = &H80040E00&

'//
'// MessageId: DB_E_ROWLIMITEXCEEDED
'//
'// MessageText:
'//
'//  Row could not be inserted into the rowset without exceeding provider's maximum number of active rows.
'//
%DB_E_ROWLIMITEXCEEDED            = &H80040E01&

'//
'// MessageId: DB_E_READONLYACCESSOR
'//
'// MessageText:
'//
'//  Accessor is read-only. Operation failed.
'//
%DB_E_READONLYACCESSOR            = &H80040E02&

'//
'// MessageId: DB_E_SCHEMAVIOLATION
'//
'// MessageText:
'//
'//  Values violate the database schema.
'//
%DB_E_SCHEMAVIOLATION             = &H80040E03&

'//
'// MessageId: DB_E_BADROWHANDLE
'//
'// MessageText:
'//
'//  Row handle is invalid.
'//
%DB_E_BADROWHANDLE                = &H80040E04&

'//
'// MessageId: DB_E_OBJECTOPEN
'//
'// MessageText:
'//
'//  Object was open.
'//
%DB_E_OBJECTOPEN                  = &H80040E05&

'//@@@+ V1.5
'#if( OLEDBVER >= 0x0150 )
'//
'// MessageId: DB_E_BADCHAPTER
'//
'// MessageText:
'//
'//  Chapter is invalid.
'//
%DB_E_BADCHAPTER                  = &H80040E06&

'#endif // OLEDBVER >= 0x0150
'//@@@- V1.5

'//
'// MessageId: DB_E_CANTCONVERTVALUE
'//
'// MessageText:
'//
'//  Data or literal value could not be converted to the type of the column in the data source, and the provider was unable to determine which columns could not be converted.  Data overflow or sign mismatch was not the cause.
'//
%DB_E_CANTCONVERTVALUE            = &H80040E07&

'//
'// MessageId: DB_E_BADBINDINFO
'//
'// MessageText:
'//
'//  Binding information is invalid.
'//
%DB_E_BADBINDINFO                 = &H80040E08&

'//
'// MessageId: DB_SEC_E_PERMISSIONDENIED
'//
'// MessageText:
'//
'//  Permission denied.
'//
%DB_SEC_E_PERMISSIONDENIED        = &H80040E09&

'//
'// MessageId: DB_E_NOTAREFERENCECOLUMN
'//
'// MessageText:
'//
'//  Column does not contain bookmarks or chapters.
'//
%DB_E_NOTAREFERENCECOLUMN         = &H80040E0A&

'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_E_LIMITREJECTED
'//
'// MessageText:
'//
'//  Cost limits were rejected.
'//
%DB_E_LIMITREJECTED               = &H80040E0B&

'#endif // OLEDBVER >= 0x0250
'//@@@- V2.5

'//
'// MessageId: DB_E_NOCOMMAND
'//
'// MessageText:
'//
'//  Command text was not set for the command object.
'//
%DB_E_NOCOMMAND                   = &H80040E0C&

'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_E_COSTLIMIT
'//
'// MessageText:
'//
'//  Query plan within the cost limit cannot be found.
'//
%DB_E_COSTLIMIT                   = &H80040E0D&

'#endif // OLEDBVER >= 0x0250
'//@@@- V2.5

'//
'// MessageId: DB_E_BADBOOKMARK
'//
'// MessageText:
'//
'//  Bookmark is invalid.
'//
%DB_E_BADBOOKMARK                 = &H80040E0E&

'//
'// MessageId: DB_E_BADLOCKMODE
'//
'// MessageText:
'//
'//  Lock mode is invalid.
'//
%DB_E_BADLOCKMODE                 = &H80040E0F&

'//
'// MessageId: DB_E_PARAMNOTOPTIONAL
'//
'// MessageText:
'//
'//  No value given for one or more required parameters.
'//
%DB_E_PARAMNOTOPTIONAL            = &H80040E10&

'//
'// MessageId: DB_E_BADCOLUMNID
'//
'// MessageText:
'//
'//  Column ID is invalid.
'//
%DB_E_BADCOLUMNID                 = &H80040E11&

'//
'// MessageId: DB_E_BADRATIO
'//
'// MessageText:
'//
'//  Numerator was greater than denominator. Values must express ratio between zero and 1.
'//
%DB_E_BADRATIO                    = &H80040E12&

'//@@@+ V2.0
'#if( OLEDBVER >= 0x0200 )
'//
'// MessageId: DB_E_BADVALUES
'//
'// MessageText:
'//
'//  Value is invalid.
'//
%DB_E_BADVALUES                   = &H80040E13&

'#endif // OLEDBVER >= 0x0200
'//@@@- V2.0

'//
'// MessageId: DB_E_ERRORSINCOMMAND
'//
'// MessageText:
'//
'//  One or more errors occurred during processing of command.
'//
%DB_E_ERRORSINCOMMAND             = &H80040E14&

'//
'// MessageId: DB_E_CANTCANCEL
'//
'// MessageText:
'//
'//  Command cannot be canceled.
'//
%DB_E_CANTCANCEL                  = &H80040E15&

'//
'// MessageId: DB_E_DIALECTNOTSUPPORTED
'//
'// MessageText:
'//
'//  Command dialect is not supported by this provider.
'//
%DB_E_DIALECTNOTSUPPORTED         = &H80040E16&

'//
'// MessageId: DB_E_DUPLICATEDATASOURCE
'//
'// MessageText:
'//
'//  Data source object could not be created because the named data source already exists.
'//
%DB_E_DUPLICATEDATASOURCE         = &H80040E17&

'//
'// MessageId: DB_E_CANNOTRESTART
'//
'// MessageText:
'//
'//  Rowset position cannot be restarted.
'//
%DB_E_CANNOTRESTART               = &H80040E18&

'//
'// MessageId: DB_E_NOTFOUND
'//
'// MessageText:
'//
'//  Object or data matching the name, range, or selection criteria was not found within the scope of this operation.
'//
%DB_E_NOTFOUND                    = &H80040E19&

'//
'// MessageId: DB_E_NEWLYINSERTED
'//
'// MessageText:
'//
'//  Identity cannot be determined for newly inserted rows.
'//
%DB_E_NEWLYINSERTED               = &H80040E1B&

'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_E_CANNOTFREE
'//
'// MessageText:
'//
'//  Provider has ownership of this tree.
'//
%DB_E_CANNOTFREE                  = &H80040E1A&

'//
'// MessageId: DB_E_GOALREJECTED
'//
'// MessageText:
'//
'//  Goal was rejected because no nonzero weights were specified for any goals supported. Current goal was not changed.
'//
%DB_E_GOALREJECTED                = &H80040E1C&

'#endif // OLEDBVER >= 0x0250
'//@@@- V2.5

'//
'// MessageId: DB_E_UNSUPPORTEDCONVERSION
'//
'// MessageText:
'//
'//  Requested conversion is not supported.
'//
%DB_E_UNSUPPORTEDCONVERSION       = &H80040E1D&

'//
'// MessageId: DB_E_BADSTARTPOSITION
'//
'// MessageText:
'//
'//  No rows were returned because the offset value moves the position before the beginning or after the end of the rowset.
'//
%DB_E_BADSTARTPOSITION            = &H80040E1E&

'//@@@+ V2.0
'#if( OLEDBVER >= 0x0200 )
'//
'// MessageId: DB_E_NOQUERY
'//
'// MessageText:
'//
'//  Information was requested for a query and the query was not set.
'//
%DB_E_NOQUERY                     = &H80040E1F&

'#endif // OLEDBVER >= 0x0200
'//@@@- V2.0

'//
'// MessageId: DB_E_NOTREENTRANT
'//
'// MessageText:
'//
'//  Consumer's event handler called a non-reentrant method in the provider.
'//
%DB_E_NOTREENTRANT                = &H80040E20&

'//
'// MessageId: DB_E_ERRORSOCCURRED
'//
'// MessageText:
'//
'//  Multiple-step OLE DB operation generated errors. Check each OLE DB status value, if available. No work was done.
'//
%DB_E_ERRORSOCCURRED              = &H80040E21&

'//
'// MessageId: DB_E_NOAGGREGATION
'//
'// MessageText:
'//
'//  Non-NULL controlling IUnknown was specified, and either the requested interface was not
'//  IUnknown, or the provider does not support COM aggregation.
'//
%DB_E_NOAGGREGATION               = &H80040E22&

'//
'// MessageId: DB_E_DELETEDROW
'//
'// MessageText:
'//
'//  Row handle referred to a deleted row or a row marked for deletion.
'//
%DB_E_DELETEDROW                  = &H80040E23&

'//
'// MessageId: DB_E_CANTFETCHBACKWARDS
'//
'// MessageText:
'//
'//  Rowset does not support fetching backward.
'//
%DB_E_CANTFETCHBACKWARDS          = &H80040E24&

'//
'// MessageId: DB_E_ROWSNOTRELEASED
'//
'// MessageText:
'//
'//  Row handles must all be released before new ones can be obtained.
'//
%DB_E_ROWSNOTRELEASED             = &H80040E25&

'//
'// MessageId: DB_E_BADSTORAGEFLAG
'//
'// MessageText:
'//
'//  One or more storage flags are not supported.
'//
%DB_E_BADSTORAGEFLAG              = &H80040E26&

'//@@@+ V1.5
'#if( OLEDBVER >= 0x0150 )
'//
'// MessageId: DB_E_BADCOMPAREOP
'//
'// MessageText:
'//
'//  Comparison operator is invalid.
'//
%DB_E_BADCOMPAREOP                = &H80040E27&

'#endif // OLEDBVER >= 0x0150
'//@@@- V1.5

'//
'// MessageId: DB_E_BADSTATUSVALUE
'//
'// MessageText:
'//
'//  Status flag was neither DBCOLUMNSTATUS_OK nor
'//  DBCOLUMNSTATUS_ISNULL.
'//
%DB_E_BADSTATUSVALUE              = &H80040E28&

'//
'// MessageId: DB_E_CANTSCROLLBACKWARDS
'//
'// MessageText:
'//
'//  Rowset does not support scrolling backward.
'//
%DB_E_CANTSCROLLBACKWARDS         = &H80040E29&

'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_E_BADREGIONHANDLE
'//
'// MessageText:
'//
'//  Region handle is invalid.
'//
%DB_E_BADREGIONHANDLE             = &H80040E2A&

'//
'// MessageId: DB_E_NONCONTIGUOUSRANGE
'//
'// MessageText:
'//
'//  Set of rows is not contiguous to, or does not overlap, the rows in the watch region.
'//
%DB_E_NONCONTIGUOUSRANGE          = &H80040E2B&

'//
'// MessageId: DB_E_INVALIDTRANSITION
'//
'// MessageText:
'//
'//  Transition from ALL* to MOVE* or EXTEND* was specified.
'//
%DB_E_INVALIDTRANSITION           = &H80040E2C&

'//
'// MessageId: DB_E_NOTASUBREGION
'//
'// MessageText:
'//
'//  Region is not a proper subregion of the region identified by the watch region handle.
'//
%DB_E_NOTASUBREGION               = &H80040E2D&

'#endif // OLEDBVER >= 0x0250
'//@@@- V2.5

'//
'// MessageId: DB_E_MULTIPLESTATEMENTS
'//
'// MessageText:
'//
'//  Multiple-statement commands are not supported by this provider.
'//
%DB_E_MULTIPLESTATEMENTS          = &H80040E2E&

'//
'// MessageId: DB_E_INTEGRITYVIOLATION
'//
'// MessageText:
'//
'//  Value violated the integrity constraints for a column or table.
'//
%DB_E_INTEGRITYVIOLATION          = &H80040E2F&

'//
'// MessageId: DB_E_BADTYPENAME
'//
'// MessageText:
'//
'//  Type name is invalid.
'//
%DB_E_BADTYPENAME                 = &H80040E30&

'//
'// MessageId: DB_E_ABORTLIMITREACHED
'//
'// MessageText:
'//
'//  Execution stopped because a resource limit was reached. No results were returned.
'//
%DB_E_ABORTLIMITREACHED           = &H80040E31&

'//@@@+ V2.0
'#if( OLEDBVER >= 0x0200 )
'//
'// MessageId: DB_E_ROWSETINCOMMAND
'//
'// MessageText:
'//
'//  Command object whose command tree contains a rowset or rowsets cannot be cloned.
'//
%DB_E_ROWSETINCOMMAND             = &H80040E32&

'//
'// MessageId: DB_E_CANTTRANSLATE
'//
'// MessageText:
'//
'//  Current tree cannot be represented as text.
'//
%DB_E_CANTTRANSLATE               = &H80040E33&

'#endif '// OLEDBVER >= 0x0200
'//@@@- V2.0

'//
'// MessageId: DB_E_DUPLICATEINDEXID
'//
'// MessageText:
'//
'//  Index already exists.
'//
%DB_E_DUPLICATEINDEXID            = &H80040E34&

'//
'// MessageId: DB_E_NOINDEX
'//
'// MessageText:
'//
'//  Index does not exist.
'//
%DB_E_NOINDEX                     = &H80040E35&

'//
'// MessageId: DB_E_INDEXINUSE
'//
'// MessageText:
'//
'//  Index is in use.
'//
%DB_E_INDEXINUSE                  = &H80040E36&

'//
'// MessageId: DB_E_NOTABLE
'//
'// MessageText:
'//
'//  Table does not exist.
'//
%DB_E_NOTABLE                     = &H80040E37&

'//
'// MessageId: DB_E_CONCURRENCYVIOLATION
'//
'// MessageText:
'//
'//  Rowset used optimistic concurrency and the value of a column has changed since it was last read.
'//
%DB_E_CONCURRENCYVIOLATION        = &H80040E38&

'//
'// MessageId: DB_E_BADCOPY
'//
'// MessageText:
'//
'//  Errors detected during the copy.
'//
%DB_E_BADCOPY                     = &H80040E39&

'//
'// MessageId: DB_E_BADPRECISION
'//
'// MessageText:
'//
'//  Precision is invalid.
'//
%DB_E_BADPRECISION                = &H80040E3A&

'//
'// MessageId: DB_E_BADSCALE
'//
'// MessageText:
'//
'//  Scale is invalid.
'//
%DB_E_BADSCALE                    = &H80040E3B&

'//
'// MessageId: DB_E_BADTABLEID
'//
'// MessageText:
'//
'//  Table ID is invalid.
'//
%DB_E_BADTABLEID                  = &H80040E3C&

'// DB_E_BADID is deprecated; use DB_E_BADTABLEID instead
%DB_E_BADID = %DB_E_BADTABLEID

'//
'// MessageId: DB_E_BADTYPE
'//
'// MessageText:
'//
'//  Type is invalid.
'//
%DB_E_BADTYPE                     = &H80040E3D&

'//
'// MessageId: DB_E_DUPLICATECOLUMNID
'//
'// MessageText:
'//
'//  Column ID already exists or occurred more than once in the array of columns.
'//
%DB_E_DUPLICATECOLUMNID           = &H80040E3E&

'//
'// MessageId: DB_E_DUPLICATETABLEID
'//
'// MessageText:
'//
'//  Table already exists.
'//
%DB_E_DUPLICATETABLEID            = &H80040E3F&

'//
'// MessageId: DB_E_TABLEINUSE
'//
'// MessageText:
'//
'//  Table is in use.
'//
%DB_E_TABLEINUSE                  = &H80040E40&

'//
'// MessageId: DB_E_NOLOCALE
'//
'// MessageText:
'//
'//  Locale ID is not supported.
'//
%DB_E_NOLOCALE                    = &H80040E41&

'//
'// MessageId: DB_E_BADRECORDNUM
'//
'// MessageText:
'//
'//  Record number is invalid.
'//
%DB_E_BADRECORDNUM                = &H80040E42&

'//
'// MessageId: DB_E_BOOKMARKSKIPPED
'//
'// MessageText:
'//
'//  Form of bookmark is valid, but no row was found to match it.
'//
%DB_E_BOOKMARKSKIPPED             = &H80040E43&

'//
'// MessageId: DB_E_BADPROPERTYVALUE
'//
'// MessageText:
'//
'//  Property value is invalid.
'//
%DB_E_BADPROPERTYVALUE            = &H80040E44&

'//
'// MessageId: DB_E_INVALID
'//
'// MessageText:
'//
'//  Rowset is not chaptered.
'//
%DB_E_INVALID                     = &H80040E45&

'//
'// MessageId: DB_E_BADACCESSORFLAGS
'//
'// MessageText:
'//
'//  One or more accessor flags were invalid.
'//
%DB_E_BADACCESSORFLAGS            = &H80040E46&

'//
'// MessageId: DB_E_BADSTORAGEFLAGS
'//
'// MessageText:
'//
'//  One or more storage flags are invalid.
'//
%DB_E_BADSTORAGEFLAGS             = &H80040E47&

'//
'// MessageId: DB_E_BYREFACCESSORNOTSUPPORTED
'//
'// MessageText:
'//
'//  Reference accessors are not supported by this provider.
'//
%DB_E_BYREFACCESSORNOTSUPPORTED   = &H80040E48&

'//
'// MessageId: DB_E_NULLACCESSORNOTSUPPORTED
'//
'// MessageText:
'//
'//  Null accessors are not supported by this provider.
'//
%DB_E_NULLACCESSORNOTSUPPORTED    = &H80040E49&

'//
'// MessageId: DB_E_NOTPREPARED
'//
'// MessageText:
'//
'//  Command was not prepared.
'//
%DB_E_NOTPREPARED                 = &H80040E4A&

'//
'// MessageId: DB_E_BADACCESSORTYPE
'//
'// MessageText:
'//
'//  Accessor is not a parameter accessor.
'//
%DB_E_BADACCESSORTYPE             = &H80040E4B&

'//
'// MessageId: DB_E_WRITEONLYACCESSOR
'//
'// MessageText:
'//
'//  Accessor is write-only.
'//
%DB_E_WRITEONLYACCESSOR           = &H80040E4C&

'//
'// MessageId: DB_SEC_E_AUTH_FAILED
'//
'// MessageText:
'//
'//  Authentication failed.
'//
%DB_SEC_E_AUTH_FAILED             = &H80040E4D&

'//
'// MessageId: DB_E_CANCELED
'//
'// MessageText:
'//
'//  Operation was canceled.
'//
%DB_E_CANCELED                    = &H80040E4E&

'//@@@+ V2.0
'#if( OLEDBVER >= 0x0200 )
'//
'// MessageId: DB_E_CHAPTERNOTRELEASED
'//
'// MessageText:
'//
'//  Rowset is single-chaptered. The chapter was not released.
'//
%DB_E_CHAPTERNOTRELEASED          = &H80040E4F&

'#endif '// OLEDBVER >= 0x0200
'//@@@- V2.0

'//
'// MessageId: DB_E_BADSOURCEHANDLE
'//
'// MessageText:
'//
'//  Source handle is invalid.
'//
%DB_E_BADSOURCEHANDLE             = &H80040E50&

'//
'// MessageId: DB_E_PARAMUNAVAILABLE
'//
'// MessageText:
'//
'//  Provider cannot derive parameter information and SetParameterInfo has not been called.
'//
%DB_E_PARAMUNAVAILABLE            = &H80040E51&

'//
'// MessageId: DB_E_ALREADYINITIALIZED
'//
'// MessageText:
'//
'//  Data source object is already initialized.
'//
%DB_E_ALREADYINITIALIZED          = &H80040E52&

'//
'// MessageId: DB_E_NOTSUPPORTED
'//
'// MessageText:
'//
'//  Method is not supported by this provider.
'//
%DB_E_NOTSUPPORTED                = &H80040E53&

'//
'// MessageId: DB_E_MAXPENDCHANGESEXCEEDED
'//
'// MessageText:
'//
'//  Number of rows with pending changes exceeded the limit.
'//
%DB_E_MAXPENDCHANGESEXCEEDED      = &H80040E54&

'//
'// MessageId: DB_E_BADORDINAL
'//
'// MessageText:
'//
'//  Column does not exist.
'//
%DB_E_BADORDINAL                  = &H80040E55&

'//
'// MessageId: DB_E_PENDINGCHANGES
'//
'// MessageText:
'//
'//  Pending changes exist on a row with a reference count of zero.
'//
%DB_E_PENDINGCHANGES              = &H80040E56&

'//
'// MessageId: DB_E_DATAOVERFLOW
'//
'// MessageText:
'//
'//  Literal value in the command exceeded the range of the type of the associated column.
'//
%DB_E_DATAOVERFLOW                = &H80040E57&

'//
'// MessageId: DB_E_BADHRESULT
'//
'// MessageText:
'//
'//  HRESULT is invalid.
'//
%DB_E_BADHRESULT                  = &H80040E58&

'//
'// MessageId: DB_E_BADLOOKUPID
'//
'// MessageText:
'//
'//  Lookup ID is invalid.
'//
%DB_E_BADLOOKUPID                 = &H80040E59&

'//
'// MessageId: DB_E_BADDYNAMICERRORID
'//
'// MessageText:
'//
'//  DynamicError ID is invalid.
'//
%DB_E_BADDYNAMICERRORID           = &H80040E5A&

'//
'// MessageId: DB_E_PENDINGINSERT
'//
'// MessageText:
'//
'//  Most recent data for a newly inserted row could not be retrieved because the insert is pending.
'//
%DB_E_PENDINGINSERT               = &H80040E5B&

'//
'// MessageId: DB_E_BADCONVERTFLAG
'//
'// MessageText:
'//
'//  Conversion flag is invalid.
'//
%DB_E_BADCONVERTFLAG              = &H80040E5C&

'//
'// MessageId: DB_E_BADPARAMETERNAME
'//
'// MessageText:
'//
'//  Parameter name is unrecognized.
'//
%DB_E_BADPARAMETERNAME            = &H80040E5D&

'//
'// MessageId: DB_E_MULTIPLESTORAGE
'//
'// MessageText:
'//
'//  Multiple storage objects cannot be open simultaneously.
'//
%DB_E_MULTIPLESTORAGE             = &H80040E5E&

'//
'// MessageId: DB_E_CANTFILTER
'//
'// MessageText:
'//
'//  Filter cannot be opened.
'//
%DB_E_CANTFILTER                  = &H80040E5F&

'//
'// MessageId: DB_E_CANTORDER
'//
'// MessageText:
'//
'//  Order cannot be opened.
'//
%DB_E_CANTORDER                   = &H80040E60&

'//@@@+ V2.0
'#if( OLEDBVER >= 0x0200 )
'//
'// MessageId: MD_E_BADTUPLE
'//
'// MessageText:
'//
'//  Tuple is invalid.
'//
%MD_E_BADTUPLE                    = &H80040E61&

'//
'// MessageId: MD_E_BADCOORDINATE
'//
'// MessageText:
'//
'//  Coordinate is invalid.
'//
%MD_E_BADCOORDINATE               = &H80040E62&

'//
'// MessageId: MD_E_INVALIDAXIS
'//
'// MessageText:
'//
'//  Axis is invalid.
'//
%MD_E_INVALIDAXIS                 = &H80040E63&

'//
'// MessageId: MD_E_INVALIDCELLRANGE
'//
'// MessageText:
'//
'//  One or more cell ordinals is invalid.
'//
%MD_E_INVALIDCELLRANGE            = &H80040E64&

'//
'// MessageId: DB_E_NOCOLUMN
'//
'// MessageText:
'//
'//  Column ID is invalid.
'//
%DB_E_NOCOLUMN                    = &H80040E65&

'//
'// MessageId: DB_E_COMMANDNOTPERSISTED
'//
'// MessageText:
'//
'//  Command does not have a DBID.
'//
%DB_E_COMMANDNOTPERSISTED         = &H80040E67&

'//
'// MessageId: DB_E_DUPLICATEID
'//
'// MessageText:
'//
'//  DBID already exists.
'//
%DB_E_DUPLICATEID                 = &H80040E68&

'//
'// MessageId: DB_E_OBJECTCREATIONLIMITREACHED
'//
'// MessageText:
'//
'//  Session cannot be created because maximum number of active sessions was already reached. Consumer must release one or more sessions before creating a new session object.
'//
%DB_E_OBJECTCREATIONLIMITREACHED  = &H80040E69&

'//
'// MessageId: DB_E_BADINDEXID
'//
'// MessageText:
'//
'//  Index ID is invalid.
'//
%DB_E_BADINDEXID                  = &H80040E72&

'//
'// MessageId: DB_E_BADINITSTRING
'//
'// MessageText:
'//
'//  Format of the initialization string does not conform to the OLE DB specification.
'//
%DB_E_BADINITSTRING               = &H80040E73&

'//
'// MessageId: DB_E_NOPROVIDERSREGISTERED
'//
'// MessageText:
'//
'//  No OLE DB providers of this source type are registered.
'//
%DB_E_NOPROVIDERSREGISTERED       = &H80040E74&

'//
'// MessageId: DB_E_MISMATCHEDPROVIDER
'//
'// MessageText:
'//
'//  Initialization string specifies a provider that does not match the active provider.
'//
%DB_E_MISMATCHEDPROVIDER          = &H80040E75&

'//
'// MessageId: DB_E_BADCOMMANDID
'//
'// MessageText:
'//
'//  DBID is invalid.
'//
%DB_E_BADCOMMANDID                = &H80040E76&

'#endif '// OLEDBVER >= 0x0200
'//@@@- V2.0
'//@@@+ V2.1
'#if( OLEDBVER >= 0x0210 )
%SEC_E_PERMISSIONDENIED = %DB_SEC_E_PERMISSIONDENIED
'//
'// MessageId: SEC_E_BADTRUSTEEID
'//
'// MessageText:
'//
'//  Trustee is invalid.
'//
%SEC_E_BADTRUSTEEID               = &H80040E6A&

'//
'// MessageId: SEC_E_NOTRUSTEEID
'//
'// MessageText:
'//
'//  Trustee was not recognized for this data source.
'//
%SEC_E_NOTRUSTEEID                = &H80040E6B&

'//
'// MessageId: SEC_E_NOMEMBERSHIPSUPPORT
'//
'// MessageText:
'//
'//  Trustee does not support memberships or collections.
'//
%SEC_E_NOMEMBERSHIPSUPPORT        = &H80040E6C&

'//
'// MessageId: SEC_E_INVALIDOBJECT
'//
'// MessageText:
'//
'//  Object is invalid or unknown to the provider.
'//
%SEC_E_INVALIDOBJECT              = &H80040E6D&

'//
'// MessageId: SEC_E_NOOWNER
'//
'// MessageText:
'//
'//  Object does not have an owner.
'//
%SEC_E_NOOWNER                    = &H80040E6E&

'//
'// MessageId: SEC_E_INVALIDACCESSENTRYLIST
'//
'// MessageText:
'//
'//  Access entry list is invalid.
'//
%SEC_E_INVALIDACCESSENTRYLIST     = &H80040E6F&

'//
'// MessageId: SEC_E_INVALIDOWNER
'//
'// MessageText:
'//
'//  Trustee supplied as owner is invalid or unknown to the provider.
'//
%SEC_E_INVALIDOWNER               = &H80040E70&

'//
'// MessageId: SEC_E_INVALIDACCESSENTRY
'//
'// MessageText:
'//
'//  Permission in the access entry list is invalid.
'//
%SEC_E_INVALIDACCESSENTRY         = &H80040E71&

'//
'// MessageId: DB_E_BADCONSTRAINTTYPE
'//
'// MessageText:
'//
'//  ConstraintType is invalid or not supported by the provider.
'//
%DB_E_BADCONSTRAINTTYPE           = &H80040E77&

'//
'// MessageId: DB_E_BADCONSTRAINTFORM
'//
'// MessageText:
'//
'//  ConstraintType is not DBCONSTRAINTTYPE_FOREIGNKEY and cForeignKeyColumns is not zero.
'//
%DB_E_BADCONSTRAINTFORM           = &H80040E78&

'//
'// MessageId: DB_E_BADDEFERRABILITY
'//
'// MessageText:
'//
'//  Specified deferrability flag is invalid or not supported by the provider.
'//
%DB_E_BADDEFERRABILITY            = &H80040E79&

'//
'// MessageId: DB_E_BADMATCHTYPE
'//
'// MessageText:
'//
'//  MatchType is invalid or the value is not supported by the provider.
'//
%DB_E_BADMATCHTYPE                = &H80040E80&

'//
'// MessageId: DB_E_BADUPDATEDELETERULE
'//
'// MessageText:
'//
'//  Constraint update rule or delete rule is invalid.
'//
%DB_E_BADUPDATEDELETERULE         = &H80040E8A&

'//
'// MessageId: DB_E_BADCONSTRAINTID
'//
'// MessageText:
'//
'//  Constraint ID is invalid.
'//
%DB_E_BADCONSTRAINTID             = &H80040E8B&

'//
'// MessageId: DB_E_BADCOMMANDFLAGS
'//
'// MessageText:
'//
'//  Command persistence flag is invalid.
'//
%DB_E_BADCOMMANDFLAGS             = &H80040E8C&

'//
'// MessageId: DB_E_OBJECTMISMATCH
'//
'// MessageText:
'//
'//  rguidColumnType points to a GUID that does not match the object type of this column, or this column was not set.
'//
%DB_E_OBJECTMISMATCH              = &H80040E8D&

'//
'// MessageId: DB_E_NOSOURCEOBJECT
'//
'// MessageText:
'//
'//  Source row does not exist.
'//
%DB_E_NOSOURCEOBJECT              = &H80040E91&

'//
'// MessageId: DB_E_RESOURCELOCKED
'//
'// MessageText:
'//
'//  OLE DB object represented by this URL is locked by one or more other processes.
'//
%DB_E_RESOURCELOCKED              = &H80040E92&

'//
'// MessageId: DB_E_NOTCOLLECTION
'//
'// MessageText:
'//
'//  Client requested an object type that is valid only for a collection.
'//
%DB_E_NOTCOLLECTION               = &H80040E93&

'//
'// MessageId: DB_E_READONLY
'//
'// MessageText:
'//
'//  Caller requested write access to a read-only object.
'//
%DB_E_READONLY                    = &H80040E94&

'//
'// MessageId: DB_E_ASYNCNOTSUPPORTED
'//
'// MessageText:
'//
'//  Asynchronous binding is not supported by this provider.
'//
%DB_E_ASYNCNOTSUPPORTED           = &H80040E95&

'//
'// MessageId: DB_E_CANNOTCONNECT
'//
'// MessageText:
'//
'//  Connection to the server for this URL cannot be established.
'//
%DB_E_CANNOTCONNECT               = &H80040E96&

'//
'// MessageId: DB_E_TIMEOUT
'//
'// MessageText:
'//
'//  Timeout occurred when attempting to bind to the object.
'//
%DB_E_TIMEOUT                     = &H80040E97&

'//
'// MessageId: DB_E_RESOURCEEXISTS
'//
'// MessageText:
'//
'//  Object cannot be created at this URL because an object named by this URL already exists.
'//
%DB_E_RESOURCEEXISTS              = &H80040E98&

'//
'// MessageId: DB_E_RESOURCEOUTOFSCOPE
'//
'// MessageText:
'//
'//  URL is outside of scope.
'//
%DB_E_RESOURCEOUTOFSCOPE          = &H80040E8E&

'//
'// MessageId: DB_E_DROPRESTRICTED
'//
'// MessageText:
'//
'//  Column or constraint could not be dropped because it is referenced by a dependent view or constraint.
'//
%DB_E_DROPRESTRICTED              = &H80040E90&

'//
'// MessageId: DB_E_DUPLICATECONSTRAINTID
'//
'// MessageText:
'//
'//  Constraint already exists.
'//
%DB_E_DUPLICATECONSTRAINTID       = &H80040E99&

'//
'// MessageId: DB_E_OUTOFSPACE
'//
'// MessageText:
'//
'//  Object cannot be created at this URL because the server is out of physical storage.
'//
%DB_E_OUTOFSPACE                  = &H80040E9A&

%SEC_E_PERMISSIONDENIED = %DB_SEC_E_PERMISSIONDENIED
'#endif '// OLEDBVER >= 0x0210
'//@@@- V2.1
'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_SEC_E_SAFEMODE_DENIED
'//
'// MessageText:
'//
'//  Safety settings on this computer prohibit accessing a data source on another domain.
'//
%DB_SEC_E_SAFEMODE_DENIED         = &H80040E9B&

'#endif '// OLEDBVER >= 0x0250
'//@@@- V2.5

'//@@@+ V2.6
'#if( OLEDBVER >= 0x0260 )
'//
'// MessageId: DB_E_NOSTATISTIC
'//
'// MessageText:
'//
'//  The specified statistic does not exist in the current data source or did not apply to the specified table or it does not support a histogram.
'//
%DB_E_NOSTATISTIC                 = &H80040E9C&

'//
'// MessageId: DB_E_ALTERRESTRICTED
'//
'// MessageText:
'//
'//  Column or table could not be altered because it is referenced by a constraint.
'//
%DB_E_ALTERRESTRICTED             = &H80040E9D&

'//
'// MessageId: DB_E_RESOURCENOTSUPPORTED
'//
'// MessageText:
'//
'//  Requested object type is not supported by the provider.
'//
%DB_E_RESOURCENOTSUPPORTED        = &H80040E9E&

'//
'// MessageId: DB_E_NOCONSTRAINT
'//
'// MessageText:
'//
'//  Constraint does not exist.
'//
%DB_E_NOCONSTRAINT                = &H80040E9F&

'//
'// MessageId: DB_E_COLUMNUNAVAILABLE
'//
'// MessageText:
'//
'//  Requested column is valid, but could not be retrieved. This could be due to a forward only cursor attempting to go backwards in a row.
'//
%DB_E_COLUMNUNAVAILABLE           = &H80040EA0&

'#endif '// OLEDBVER >= 0x0260
'//@@@- V2.6
'//
'// MessageId: DB_S_ROWLIMITEXCEEDED
'//
'// MessageText:
'//
'//  Fetching requested number of rows will exceed total number of active rows supported by the rowset.
'//
%DB_S_ROWLIMITEXCEEDED            = &H00040EC0&

'//
'// MessageId: DB_S_COLUMNTYPEMISMATCH
'//
'// MessageText:
'//
'//  One or more column types are incompatible. Conversion errors will occur during copying.
'//
%DB_S_COLUMNTYPEMISMATCH          = &H00040EC1&

'//
'// MessageId: DB_S_TYPEINFOOVERRIDDEN
'//
'// MessageText:
'//
'//  Parameter type information was overridden by caller.
'//
%DB_S_TYPEINFOOVERRIDDEN          = &H00040EC2&

'//
'// MessageId: DB_S_BOOKMARKSKIPPED
'//
'// MessageText:
'//
'//  Bookmark was skipped for deleted or nonmember row.
'//
%DB_S_BOOKMARKSKIPPED             = &H00040EC3&

'//@@@+ V2.0
'#if( OLEDBVER >= 0x0200 )
'//
'// MessageId: DB_S_NONEXTROWSET
'//
'// MessageText:
'//
'//  No more rowsets.
'//
%DB_S_NONEXTROWSET                = &H00040EC5&

'#endif '// OLEDBVER >= 0x0200
'//@@@- V2.0

'//
'// MessageId: DB_S_ENDOFROWSET
'//
'// MessageText:
'//
'//  Start or end of rowset or chapter was reached.
'//
%DB_S_ENDOFROWSET                 = &H00040EC6&

'//
'// MessageId: DB_S_COMMANDREEXECUTED
'//
'// MessageText:
'//
'//  Command was reexecuted.
'//
%DB_S_COMMANDREEXECUTED           = &H00040EC7&

'//
'// MessageId: DB_S_BUFFERFULL
'//
'// MessageText:
'//
'//  Operation succeeded, but status array or string buffer could not be allocated.
'//
%DB_S_BUFFERFULL                  = &H00040EC8&

'//
'// MessageId: DB_S_NORESULT
'//
'// MessageText:
'//
'//  No more results.
'//
%DB_S_NORESULT                    = &H00040EC9&

'//
'// MessageId: DB_S_CANTRELEASE
'//
'// MessageText:
'//
'//  Server cannot release or downgrade a lock until the end of the transaction.
'//
%DB_S_CANTRELEASE                 = &H00040ECA&

'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_S_GOALCHANGED
'//
'// MessageText:
'//
'//  Weight is not supported or exceeded the supported limit, and was set to 0 or the supported limit.
'//
%DB_S_GOALCHANGED                 = &H00040ECB&

'#endif '// OLEDBVER >= 0x0250
'//@@@- V2.5

'//@@@+ V1.5
'#if( OLEDBVER >= 0x0150 )
'//
'// MessageId: DB_S_UNWANTEDOPERATION
'//
'// MessageText:
'//
'//  Consumer does not want to receive further notification calls for this operation.
'//
%DB_S_UNWANTEDOPERATION           = &H00040ECC&

'#endif '// OLEDBVER >= 0x0150
'//@@@- V1.5

'//
'// MessageId: DB_S_DIALECTIGNORED
'//
'// MessageText:
'//
'//  Input dialect was ignored and command was processed using default dialect.
'//
%DB_S_DIALECTIGNORED              = &H00040ECD&

'//
'// MessageId: DB_S_UNWANTEDPHASE
'//
'// MessageText:
'//
'//  Consumer does not want to receive further notification calls for this phase.
'//
%DB_S_UNWANTEDPHASE               = &H00040ECE&

'//
'// MessageId: DB_S_UNWANTEDREASON
'//
'// MessageText:
'//
'//  Consumer does not want to receive further notification calls for this reason.
'//
%DB_S_UNWANTEDREASON              = &H00040ECF&

'//@@@+ V1.5
'#if( OLEDBVER >= 0x0150 )
'//
'// MessageId: DB_S_ASYNCHRONOUS
'//
'// MessageText:
'//
'//  Operation is being processed asynchronously.
'//
%DB_S_ASYNCHRONOUS                = &H00040ED0&

'#endif '// OLEDBVER >= 0x0150
'//@@@- V1.5

'//
'// MessageId: DB_S_COLUMNSCHANGED
'//
'// MessageText:
'//
'//  Command was executed to reposition to the start of the rowset. Either the order of the columns changed, or columns were added to or removed from the rowset.
'//
%DB_S_COLUMNSCHANGED              = &H00040ED1&

'//
'// MessageId: DB_S_ERRORSRETURNED
'//
'// MessageText:
'//
'//  Method had some errors, which were returned in the error array.
'//
%DB_S_ERRORSRETURNED              = &H00040ED2&

'//
'// MessageId: DB_S_BADROWHANDLE
'//
'// MessageText:
'//
'//  Row handle is invalid.
'//
%DB_S_BADROWHANDLE                = &H00040ED3&

'//
'// MessageId: DB_S_DELETEDROW
'//
'// MessageText:
'//
'//  Row handle referred to a deleted row.
'//
%DB_S_DELETEDROW                  = &H00040ED4&

'//@@@+ V2.5
'#if( OLEDBVER >= 0x0250 )
'//
'// MessageId: DB_S_TOOMANYCHANGES
'//
'// MessageText:
'//
'//  Provider cannot keep track of all the changes. Client must refetch the data associated with the watch region by using another method.
'//
%DB_S_TOOMANYCHANGES              = &H00040ED5&

'#endif '// OLEDBVER >= 0x0250
'//@@@- V2.5

'//
'// MessageId: DB_S_STOPLIMITREACHED
'//
'// MessageText:
'//
'//  Execution stopped because a resource limit was reached. Results obtained so far were returned, but execution cannot resume.
'//
%DB_S_STOPLIMITREACHED            = &H00040ED6&

'//
'// MessageId: DB_S_LOCKUPGRADED
'//
'// MessageText:
'//
'//  Lock was upgraded from the value specified.
'//
%DB_S_LOCKUPGRADED                = &H00040ED8&

'//
'// MessageId: DB_S_PROPERTIESCHANGED
'//
'// MessageText:
'//
'//  One or more properties were changed as allowed by provider.
'//
%DB_S_PROPERTIESCHANGED           = &H00040ED9&

'//
'// MessageId: DB_S_ERRORSOCCURRED
'//
'// MessageText:
'//
'//  Multiple-step operation completed with one or more errors. Check each status value.
'//
%DB_S_ERRORSOCCURRED              = &H00040EDA&

'//
'// MessageId: DB_S_PARAMUNAVAILABLE
'//
'// MessageText:
'//
'//  Parameter is invalid.
'//
%DB_S_PARAMUNAVAILABLE            = &H00040EDB&

'//
'// MessageId: DB_S_MULTIPLECHANGES
'//
'// MessageText:
'//
'//  Updating a row caused more than one row to be updated in the data source.
'//
%DB_S_MULTIPLECHANGES             = &H00040EDC&

'//@@@+ V2.1
'#if( OLEDBVER >= 0x0210 )
'//
'// MessageId: DB_S_NOTSINGLETON
'//
'// MessageText:
'//
'//  Row object was requested on a non-singleton result. First row was returned.
'//
%DB_S_NOTSINGLETON                = &H00040ED7&

'//
'// MessageId: DB_S_NOROWSPECIFICCOLUMNS
'//
'// MessageText:
'//
'//  Row has no row-specific columns.
'//
%DB_S_NOROWSPECIFICCOLUMNS        = &H00040EDD&

'#endif '// OLEDBVER >= 0x0210
'//@@@- V2.1
'// To help DSL display more meaningful error message, we need to overwrite system error message
'// in the following two cases.
'NOTE: Also defined in winerror.h

#IF %DEF(%MESSAGESANDHEADERS)
'//(0x80030002&STG_E_FILENOTFOUND
'//
'// MessageId: STG_E_FILENOTFOUND
'//
'// MessageText:
'//
'//  The file could not be found.
'//
%STG_E_FILENOTFOUND               = &H80030002&

'//(0x80030003&STG_E_PATHNOTFOUND
'//
'// MessageId: STG_E_PATHNOTFOUND
'//
'// MessageText:
'//
'//  The path could not be found.
'//
%STG_E_PATHNOTFOUND               = &H80030003&

'//(0x80030050&STG_E_FILEALREADYEXISTS
'//
'// MessageId: STG_E_FILEALREADYEXISTS
'//
'// MessageText:
'//
'//  The file already exists.
'//
%STG_E_FILEALREADYEXISTS          = &H80030050&

'//(0x800300fB&STG_E_INVALIDHEADER
'//
'// MessageId: STG_E_INVALIDHEADER
'//
'// MessageText:
'//
'//  The file is not a valid compound file.
'//
%STG_E_INVALIDHEADER              = &H800300FB&

'//(0x800300fC&STG_E_INVALIDNAME
'//
'// MessageId: STG_E_INVALIDNAME
'//
'// MessageText:
'//
'//  The name is not valid.
'//
%STG_E_INVALIDNAME                = &H800300FC&

'//(0x80030104&STG_E_OLDFORMAT
'//
'// MessageId: STG_E_OLDFORMAT
'//
'// MessageText:
'//
'//  The compound file was produced with an incompatible version of storage.
'//
%STG_E_OLDFORMAT                  = &H80030104&

'//(0x80030105&STG_E_OLDDLL
'//
'// MessageId: STG_E_OLDDLL
'//
'// MessageText:
'//
'//  The compound file was produced with an incompatible version of storage.
'//
%STG_E_OLDDLL                     = &H80030105&

#ENDIF   ' //MESSAGESANDHEADERS
