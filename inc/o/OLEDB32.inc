' ########################################################################################
' Microsoft Windows
' File: oledb32.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEDB32_INC = 1

#INCLUDE ONCE "oledb.inc"
#INCLUDE ONCE "oledberr.inc"
#INCLUDE ONCE "cmdtree.inc"
#INCLUDE ONCE "oledbdep.inc"
#INCLUDE ONCE "msdasc.inc"       ' // MS OLE DB Service Component
#INCLUDE ONCE "msdaguid.inc"     ' // ODBC provider include files
#INCLUDE ONCE "msdasql.inc"
#INCLUDE ONCE "jetoledb.inc"     ' // MS JET provider files
#INCLUDE ONCE "MsJetOleDb.inc"
#INCLUDE ONCE "sqloledb.inc"     ' // MS OLE DB Provider for SQL Server

' ========================================================================================
' Helper function to retrieve detailed contextual error information.
' Return values: S_OK (Success), S_FALSE (no error object to return).
' ========================================================================================
FUNCTION OleDbGetErrorInfo ( _
   BYREF bstrDescription AS WSTRING _            ' Textual description of the error
 , OPTIONAL BYREF bstrSource AS WSTRING _        ' ProgID for the class or application that returned the error
 , OPTIONAL BYREF pguid AS GUID _                ' GUID for the interface that defined the error
 , OPTIONAL BYREF bstrHelpFile AS WSTRING _      ' Path of the Help file that describes the error
 , OPTIONAL BYREF dwHelpContext AS DWORD _       ' Help context identifier for the error
   ) AS LONG

   LOCAL hr AS LONG
   LOCAL pIErrorInfo AS IErrorInfo

   hr = GetErrorInfo(0, pIErrorInfo)
   IF hr THEN FUNCTION = hr : EXIT FUNCTION
   ' GetErrorInfo can succeed and return a null pointer in pIErrorInfo,
   ' so test the returned pointer to make sure it is valid.
   IF ISFALSE ISOBJECT(pIErrorInfo) THEN FUNCTION = %S_FALSE : EXIT FUNCTION
   IF VARPTR(bstrDescription) THEN
      pIErrorInfo.GetDescription(bstrDescription)
   END IF
   IF VARPTR(pguid) THEN
      pIErrorInfo.GetGUID(pguid)
   END IF
   IF VARPTR(bstrSource) THEN
      pIErrorInfo.GetSource(bstrSource)
   END IF
   IF VARPTR(bstrHelpFile) THEN
      pIErrorInfo.GetHelpFile(bstrHelpFile)
   END IF
   IF VARPTR(dwHelpContext) THEN
      pIErrorInfo.GetHelpContext(dwHelpContext)
   END IF
   pIErrorInfo = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays error information.
' ========================================================================================
SUB OleDbShowErrorInfo (BYVAL nErrorCode AS LONG)

   LOCAL bstrMsg AS WSTRING
   LOCAL bstrErrorDescription AS WSTRING
   LOCAL ErrorGuid AS GUID
   LOCAL bstrErrorSource AS WSTRING
   LOCAL bstrHelpFile AS WSTRING
   LOCAL dwHelpContext AS DWORD

   IF nErrorCode = 0 THEN EXIT SUB
   IF OleDbGetErrorInfo(bstrErrorDescription, bstrErrorSource, ErrorGuid, bstrHelpFile, dwHelpContext) = %S_OK THEN
      bstrMsg = "Error code: &H" & HEX$(nErrorCode) & " [" & FORMAT$(nErrorCode) & "]" & $CRLF
      IF LEN(bstrErrorDescription) THEN bstrMsg = bstrMsg & "Description: " & bstrErrorDescription & $CRLF
      IF ErrorGuid <> $IID_NULL THEN bstrMsg = bstrMsg & "GUID: " & GUIDTXT$(ErrorGuid) & $CRLF
      IF LEN(bstrErrorSource) THEN bstrMsg = bstrMsg & "Source: " & bstrErrorSource
      IF LEN(bstrHelpFile) THEN bstrMsg = bstrMsg & $CRLF & "Help file: " & bstrHelpFile
      IF dwHelpContext THEN bstrMsg = bstrMsg & $CRLF & "Help context: " & FORMAT$(dwHelpContext)
   ELSE
      bstrMsg = "Error code: " & FORMAT$(nErrorCode) & " [&H" & HEX$(nErrorCode, 8) & "] " & OBJRESULT$(nErrorCode)
   END IF
   IF LEN(bstrMsg) = 0 THEN bstrMsg = "Error code: &H" & HEX$(nErrorCode) & " [" & FORMAT$(nErrorCode) & "]"
   #IF %DEF(%PB_CC32)
      STDOUT bstrMsg
   #ELSE
      MSGBOX bstrMsg, &H00001000& ' %MB_SYSTEMMODAL
   #ENDIF

END SUB
' ========================================================================================
