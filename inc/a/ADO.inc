' ########################################################################################
' Microsoft Windows
' File: ADO.inc
' Contents: Master include file for ADO.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADO_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "adodef.inc"
#INCLUDE ONCE "adoint.inc"
#INCLUDE ONCE "adoctint.inc"
#INCLUDE ONCE "adojet.inc"
#INCLUDE ONCE "adomd.inc"
#INCLUDE ONCE "msadco.inc"
#INCLUDE ONCE "msadcf.inc"

' ########################################################################################
' Helper functions to retrieve error information.
' ########################################################################################

' ========================================================================================
' Returns the description of an ADO runtime error
' ========================================================================================
FUNCTION AdoGetRuntimeErrorInfo (BYVAL wError AS WORD) AS WSTRING

   LOCAL s AS WSTRING

   SELECT CASE AS LONG wError
      CASE 3000 ' &HBB8 - %adErrProviderFailed
         s = "Provider failed to perform the requested operation."
      CASE 3001 ' &HBB9 - %adErrInvalidArgument
         s = "Arguments are of the wrong type, are out of acceptable range, or are in conflict with one another."
      CASE 3002 ' &HBBA - %adErrOpeningFile
         s = "File could not be opened."
      CASE 3003 ' &HBBB - %adErrReadFile
         s = "File could not be read."
      CASE 3004 ' &HBBC - %adErrWriteFile
         s = "Write to file failed."
      CASE 3021 ' &HBCD - %adErrNoCurrentRecord
         s = "Either BOF or EOF is True, or the current record has been deleted. Requested operation requires a current record."
      CASE 3219 ' &HC93 - %adErrIllegalOperation
         s = "Operation is not allowed in this context."
      CASE 3220 ' &HC94 - %adErrCantChangeProvider
         s = "Supplied provider is different from the one already in use."
      CASE 3246 ' &HCAE - %adErrInTransaction
         s = "Connection object cannot be explicitly closed while in a transaction."
      CASE 3251 ' &HCB3 - %adErrFeatureNotAvailable
         s = "Object or provider is not capable of performing requested operation."
      CASE 3265 ' &HCC1 - %adErrItemNotFound
         s = "Item cannot be found in the collection corresponding to the requested name or ordinal."
      CASE 3367 ' &HD27 - %adErrObjectInCollection
         s = "Object is already in collection. Cannot append."
      CASE 3420 ' &HD5C - %adErrObjectNotSet
         s = "Object is no longer valid."
      CASE 3421 ' &HD5D - %adErrDataConversion
         s = "Application uses a value of the wrong type for the current operation."
      CASE 3704 ' &HE78 - %adErrObjectClosed
         s = "Operation is not allowed when the object is closed. "
      CASE 3705 ' &HE79 - %adErrObjectOpen
         s = "Operation is not allowed when the object is open. "
      CASE 3706 ' &HE7A - %adErrProviderNotFound
         s = "Provider cannot be found. It may not be properly installed."
      CASE 3707 ' &HE7B - %adErrBoundToCommand
         s = "Cannot change the ActiveConnection property of a Recordset object which has a Command object as its source."
      CASE 3708 ' &HE7C - %adErrInvalidParamInfo
         s = "Parameter object is improperly defined. Inconsistent or incomplete information was provided."
      CASE 3709 ' &HE7D - %adErrInvalidConnection
         s = "The connection cannot be used to perform this operation. It is either closed or invalid in this context."
      CASE 3710 ' &HE7E - %adErrNotReentrant
         s = "Operation cannot be performed while processing event. "
      CASE 3711 ' &HE7F - %adErrStillExecuting
         s = "Operation cannot be performed while executing asynchronously."
      CASE 3712 ' &HE80 - %adErrOperationCancelled
         s = "Operation has been cancelled by the user."
      CASE 3713 ' &HE81 - %adErrStillConnecting
         s = "Operation cannot be performed while connecting aynchronously. "
      CASE 3714 ' &HE82 - %adErrInvalidTransaction
         s = "Coordinating transaction is invalid or has not started."
      CASE 3715 ' &HE83 - %adErrNotExecuting
         s = "Operation cannot be performed while not executing."
      CASE 3716 ' &HE84 - %adErrUnsafeOperation
         s = "Safety settings on this computer prohibit accessing a data source on another domain."
'      CASE 3717 ' &HE85 - %adwrnSecurityDialog
'         For internal use only. Don't use.
'      CASE 3718 ' &HE86 - %adwrnSecurityDialogHeader
'         For internal use only. Don't use.
      CASE 3719 ' &HE87 - %adErrIntegrityViolation
         s = "Data value conflicts with the integrity constraints of the field."
      CASE 3720 ' &HE88 - %adErrPermissionDenied
         s = "Insufficent permission prevents writing to the field."
      CASE 3721 ' &HE89 - %adErrDataOverflow
         s = "Data value is too large to be represented by the field data type."
      CASE 3722 ' &HE8A - %adErrSchemaViolation
         s = "Data value conflicts with the data type or constraints of the field."
      CASE 3723 ' &HE8B - %adErrSignMismatch
         s = "Conversion failed because the data value was signed and the field data type used by the provider was unsigned."
      CASE 3724 ' &HE8C - %adErrCantConvertvalue
         s = "Data value cannot be converted for reasons other than sign mismatch or data overflow. For example, conversion would have truncated data."
      CASE 3725 ' &HE8D - %adErrCantCreate
         s = "Data value cannot be set or retrieved because the field data type was unknown, or the provider had insufficient resources to perform the operation."
      CASE 3726 ' &HE8E - %adErrColumnNotOnThisRow
         s = "Record does not contain this field."
      CASE 3727 ' &HE8F - %adErrURLDoesNotExist
         s = "Either the source URL or the parent of the destination URL does not exist."
      CASE 3728 ' &HE90 - %adErrTreePermissionDenied
         s = "Permissions are insufficient to access tree or subtree. "
      CASE 3729 ' &HE91 - %adErrInvalidURL
         s = "URL contains invalid characters. Make sure the URL is typed correctly."
      CASE 3730 ' &HE92 - %adErrResourceLocked
         s = "Object represented by the specified URL is locked by one or more other processes. Wait until the process has finished and attempt the operation again."
      CASE 3731 ' &HE93 - %adErrResourceExists
         s = "Copy operation cannot be performed. Object named by destination URL already exists. Specify adCopyOverwrite to replace the object."
      CASE 3732 ' &HE94 - %adErrCannotComplete
         s = "Server cannot complete the operation."
      CASE 3733 ' &HE95 - %adErrVolumeNotFound
         s = "Provider cannot locate the storage device indicated by the URL. Make sure the URL is typed correctly."
      CASE 3734 ' &HE96 - %adErrOutOfSpace
         s = "Operation cannot be performed. Provider cannot obtain enough storage space."
      CASE 3735 ' &HE97 - %adErrResourceOutOfScope
         s = "Source or destination URL is outside the scope of the current record."
      CASE 3736 ' &HE98 - %adErrUnavailable
         s = "Operation failed to complete and the status is unavailable. The field may be unavailable or the operation was not attempted."
      CASE 3737 ' &HE99 - %adErrURLNamedRowDoesNotExist
         s = "Record named by this URL does not exist."
      CASE 3738 ' &HE9A - %adErrDelResOutOfScope
         s = "URL of the object to be deleted is outside the scope of the current record."
      CASE 3739 ' &HE9B - %adErrPropInvalidColumn
         s = "Cannot apply property to field"
      CASE 3740 ' &HE9C - %adErrPropInvalidOption
         s = "Attribute property invalid"
      CASE 3741 ' &HE9D - %adErrPropInvalidValue
         s = "Invalid property value"
      CASE 3742 ' &HE9E - %adErrPropConflicting
         s = "Property values conflict with each other"
      CASE 3743 ' &HE9F - %adErrPropNotAllSettable
         s = "Cannot set property or read-only"
      CASE 3744 ' &HEA0 - %adErrPropNotSet
         s = "Optional property value not set"
      CASE 3745 ' &HEA1 - %adErrPropNotSettable
         s = "Read-only property cannot be set"
      CASE 3746 ' &HEA2 - %adErrPropNotSupported
         s = "Property not supported by provider"
      CASE 3747 ' &HEA3 - %adErrCatalogNotSet
         s = "Operation requires a valid ParentCatalog."
      CASE 3748 ' &HEA4 - %adErrCantChangeConnection
         s = "Connection was denied. New connection you requested has different characteristics than the one already in use."
      CASE 3749 ' &HEA5 - %adErrFieldsUpdateFailed
         s = "Fields update failed. For further information, examine the Status property of individual field objects."
      CASE 3750 ' &HEA6 - %adErrDenyNotSupported
         s = "Provider does not support sharing restrictions."
      CASE 3751 ' &HEA7 - %adErrDenyTypeNotSupported
         s = "Provider does not support the requested kind of sharing restriction."
      CASE 3753 ' 3753 - %adErrProviderNotSpecified
         s = "Provider not specified"
      CASE 3754 ' &HEAA - %adErrConnectionStringTooLong
         s = "Connection string too long"
   END SELECT

   FUNCTION = s

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information from the ADO Errors collection.
' ========================================================================================
FUNCTION AdoGetErrorInfo (BYVAL pConnection AS ADOConnection, BYVAL dwError AS DWORD) AS WSTRING

   LOCAL hr              AS DWORD          ' // Result code
   LOCAL pErrors         AS ADOErrors      ' // Reference to the Errors collection
   LOCAL pError          AS ADOError       ' // Reference to the Error object
   LOCAL wError          AS WORD           ' // ADO runtime error
   LOCAL i               AS LONG           ' // Loop counter
   LOCAL nCount          AS LONG           ' // Number of errors
   LOCAL eNumber         AS LONG           ' // Error number
   LOCAL eSource         AS WSTRING        ' // Source of the error
   LOCAL eDescription    AS WSTRING        ' // Description of the error
   LOCAL eHelpFile       AS WSTRING        ' // Help file
   LOCAL eHelpContext    AS LONG           ' // Help context
   LOCAL eSQLState       AS WSTRING        ' // SQlState
   LOCAL eNativeError    AS LONG           ' // Native error
   LOCAL bstrErrorText   AS WSTRING        ' // String to return the result
   LOCAL cbMsgLen        AS DWORD          ' // Length of the returned message
   LOCAL pBuffer         AS WSTRINGZ PTR   ' // Pointer to the buffer
   LOCAL bstrDescription AS WSTRING        ' // Description of the ADO runtime error

   IF ISNOTHING(pConnection) THEN EXIT FUNCTION
   IF dwError = 0 THEN EXIT FUNCTION

   ' Get a reference to the errors collection
   pErrors = pConnection.Errors
   IF ISOBJECT(pErrors) THEN
      ' Get the number of errors
      nCount = pErrors.Count
      ' The errors collection is zero based
      FOR i = 0 TO nCount - 1
         ' Get a reference to the error object
         pError = pErrors.Item(i)
         IF ISOBJECT(pError) THEN
            eNumber = pError.Number
            eDescription = pError.Description
            eSource = pError.Source
            eSqlState = pError.SQLState
            eNativeError = pError.NativeError
            eHelpFile = pError.HelpFile
            eHelpContext = pError.HelpContext
            bstrErrorText += "OLE DB provider error" & $CRLF
            bstrErrorText += "Error number: " & FORMAT$(eNumber) & " [&H" & HEX$(eNumber, 8) & "]" & $CRLF
            IF LEN(eDescription) THEN bstrErrorText += "Description: " & eDescription & $CRLF
            IF LEN(eSource) THEN bstrErrorText += "Source: " & eSource & $CRLF
            IF LEN(eSqlState) THEN bstrErrorText += "SQLState: " & eSqlState & $CRLF
            IF eNativeError THEN bstrErrorText += "Native error: " & FORMAT$(eNativeError) & " [&H" & HEX$(eNativeError, 8) & "]" & $CRLF
            IF LEN(eHelpFile) THEN bstrErrorText += "Help file: " & eHelpFile & $CRLF
            IF eHelpContext THEN bstrErrorText += "Help context: " & FORMAT$(eHelpContext)
            ' Release the error object
            pError = NOTHING
         END IF
      NEXT
      ' Clear the errors collection
      pErrors.Clear
      ' Release the errors collection
      pErrors = NOTHING
      IF nCount THEN
         FUNCTION = bstrErrorText
         EXIT FUNCTION
      END IF
   END IF

   ' Must be an ADO runtime error
   wError = dwError
   bstrDescription = AdoGetRuntimeErrorInfo(wError)
   IF LEN(bstrDescription) THEN
      bstrErrorText += "ADO runtime error" & $CRLF
      bstrErrorText += "Error code: " & FORMAT$(dwError) & " [&H" & HEX$(dwError, 8) & "]" & $CRLF
      bstrErrorText += "Description: " & bstrDescription
   ELSE
      ' If it is not a Provider or an ADO runtime error then must be a Windows error
      cbMsgLen = FormatMessageW(%FORMAT_MESSAGE_ALLOCATE_BUFFER OR _
                 %FORMAT_MESSAGE_FROM_SYSTEM OR %FORMAT_MESSAGE_IGNORE_INSERTS, _
                 BYVAL %NULL, dwError, BYVAL MAKELANGID(%LANG_NEUTRAL, %SUBLANG_DEFAULT), _
                 BYVAL VARPTR(pBuffer), 0, BYVAL %NULL)
      IF cbMsgLen THEN
         bstrErrorText += "Windows error" & $CRLF
         bstrErrorText += "Error code:" & FORMAT$(dwError) & " [&H" & HEX$(dwError, 8) & "]"
         bstrErrorText += "Description: " & @pBuffer
         LocalFree pBuffer
      END IF
   END IF

   FUNCTION = bstrErrorText

END FUNCTION
' ========================================================================================
