' #####################################################################################
' Microsoft Windows
' File: COdbcDesc.inc
' Contents: ODBC descriptor class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CODBCSTMT_INC = 1

#INCLUDE ONCE "ODBC.INC"

$CLSID_COdbcDescriptor = GUID$("{57EF9B1B-EE7B-4EEB-8507-094B251BD06B}")
$IID_IOdbcDescriptor = GUID$("{776208D4-50BE-4117-BCE2-26B6A1E160B5}")

CLASS COdbcDescriptor $CLSID_COdbcDescriptor

   INSTANCE m_hDesc AS DWORD

   ' =====================================================================================
   ' Frees the descriptor handle
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_hDesc THEN SQLFreeHandle (%SQL_HANDLE_DESC, m_hDesc)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   INTERFACE IOdbcDescriptor $IID_IOdbcDescriptor : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the descriptor handle
   ' =====================================================================================
   PROPERTY GET Handle () AS DWORD
      PROPERTY = m_hDesc
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current value of a field of a record of the diagnostic data structure
   ' (associated with a specific handle) that contains error, warning, and status information.
   ' =====================================================================================
   METHOD GetDiagField (BYVAL RecNumber AS INTEGER, BYVAL DiagIdentifier AS INTEGER, BYVAL DiagInfo AS DWORD, _
   BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDiagField(%SQL_HANDLE_DBC, m_hDesc, RecNumber, DiagIdentifier, BYVAL DiagInfo, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current values of multiple fields of a diagnostic record that contains
   ' error, warning and status information. Unlike GetDiagField, which returns one
   ' diagnostic call per call, GetDiagRec returns several commonly used fields of a
   ' diagnostic record, including the SQLSTATE, the native error code, and the
   ' diagnostic message text.
   ' =====================================================================================
   METHOD GetDiagRec (BYVAL RecNumber AS INTEGER, BYREF Sqlstate AS ASCIIZ, BYREF NativeError AS LONG, _
   BYREF MessageText AS ASCIIZ, BYVAL BufferLength AS INTEGER, BYREF TextLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDiagRec(%SQL_HANDLE_DBC, m_hDesc, RecNumber, Sqlstate, NativeError, MessageText, BufferLength, TextLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' ========================================================================================
   ' Uses SQLGetDiagRec to retrieve an error description.
   ' iErrorCode is an optional parameter that allows to set the value returned by
   ' OdbcResult to the desired value.
   ' ========================================================================================
   PROPERTY GET ErrorInfo (OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING

      LOCAL iResult AS INTEGER
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL strErrMsg AS STRING
      LOCAL cbbytes AS INTEGER
      LOCAL ErrorCount AS LONG
      LOCAL i AS LONG

      iResult = SQLGetDiagField(%SQL_HANDLE_DBC, m_hDesc, 0, %SQL_DIAG_NUMBER, ErrorCount, %SQL_IS_INTEGER, cbbytes)

      IF ErrorCount THEN
         FOR i = 1 TO ErrorCount
            iResult = SQLGetDiagRec(%SQL_HANDLE_DBC, m_hDesc, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
            IF iResult <> %SQL_SUCCESS AND iResult <> %SQL_SUCCESS_WITH_INFO THEN EXIT FOR
            strErrMsg = szErrMsg & $CRLF & "SqlState: " & szSqlState & $CRLF & _
                        "Native error: " & FORMAT$(lNativeError) & $CRLF
         NEXT
      ELSEIF iErrorCode THEN
         SELECT CASE AS LONG iErrorCode
            CASE  -1 : strErrMsg = "SQL error" ' "SQL_ERROR"
            CASE   2 : strErrMsg = "Still executing" ' "SQL_STILL_EXECUTING"
            CASE  -2 : strErrMsg = "Invalid handle" '"SQL_INVALID_HANDLE"
            CASE  99 : strErrMsg = "Need data" ' "SQL_NEED_DATA"
            CASE 100 : strErrMsg = "No data" '"SQL_NO_DATA"
            CASE ELSE
               strErrMsg = "Error " & FORMAT$(iErrorCode)
         END SELECT
      END IF

      PROPERTY = strErrMsg

   END PROPERTY
   ' ========================================================================================

   ' =====================================================================================
   ' Gets the SqlState for the descriptor handle
   ' =====================================================================================
   PROPERTY GET SqlState () AS STRING
      LOCAL r AS INTEGER
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL cbbytes AS INTEGER
      r = SQLGetDiagRec(%SQL_HANDLE_DESC, m_hDesc, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szSqlState
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Allocates a descriptor handle
   ' =====================================================================================
   METHOD AllocDesc (BYVAL hDbc AS DWORD) AS DWORD
      LOCAL r AS INTEGER
      IF m_hDesc THEN SQLFreeHandle (%SQL_HANDLE_DESC, m_hDesc)
      r = SQLAllocHandle (%SQL_HANDLE_DESC, hDbc, m_hDesc)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = m_hDesc
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies descriptor information from one descriptor handle to another.
   ' =====================================================================================
   METHOD CopyDesc (BYVAL TargetDescHandle AS DWORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLCopyDesc(m_hDesc, TargetDescHandle)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current settings or values or multiple fields of the descriptor
   ' record. The fields returned describe the name, data type, and storage of column or
   ' parameter data.
   ' =====================================================================================
   METHOD GetDescRec (BYVAL RecNumber AS INTEGER, BYREF szName AS ASCIIZ, _
   BYREF StringLength AS INTEGER, BYREF nType AS INTEGER, BYREF nSubType AS INTEGER, BYREF nLength AS LONG, _
   BYREF nPrecision AS INTEGER, BYREF nScale AS INTEGER, BYREF nNullable AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDescRec(m_hDesc, RecNumber, szName, SIZEOF(szName), StringLength, nType, nSubType, nLength, nPrecision, nScale, nNullable)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets multiple descriptor fields that affect the data type and buffer bound to a
   ' column or parameter data.
   ' =====================================================================================
   METHOD SetDescRec (BYVAL RecNumber AS INTEGER, BYVAL nType AS INTEGER, BYVAL nSubType AS INTEGER, _
   BYVAL nLength AS LONG, BYVAL nPrecision AS INTEGER, BYVAL nScale AS INTEGER, BYVAL DataPtr AS DWORD, _
   BYREF StringLength AS LONG, BYREF Indicator AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetDescRec(m_hDesc, RecNumber, nType, nSubType, nLength, nPrecision, nScale, BYVAL DataPtr, StringLength, Indicator)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current setting or value of a single field of a descriptor record.
   ' =====================================================================================
   METHOD GetDescField (BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, _
      BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDescField(m_hDesc, RecNumber, FieldIdentifier, BYVAL ValuePtr, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the value of a single field of a descriptor record.
   ' =====================================================================================
   METHOD SetDescField (BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetDescField(m_hDesc, RecNumber, FieldIdentifier, BYVAL ValuePtr, BufferLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcDescriptor, "IODBCDESCRIPTOR." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
