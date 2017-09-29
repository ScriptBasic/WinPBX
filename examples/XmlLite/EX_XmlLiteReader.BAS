' ########################################################################################
' Microsoft Windows
' File: EX_XmlLiteReader.bas
' Contents: XmlLite example
' This example provides details of how to read an XML document by using XmlLite.
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers III+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' CSED_PBCC - Use the console compiler
#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "shlwapi.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "xmllite.inc"

' ========================================================================================
' Display the attributes
' ========================================================================================
FUNCTION WriteAttributes (BYVAL pReader AS IXmlReader) AS LONG

   LOCAL hr AS LONG
   LOCAL pwszPrefix AS WSTRINGZ PTR
   LOCAL pwszLocalName AS WSTRINGZ PTR
   LOCAL pwszValue AS WSTRINGZ PTR

   hr = pReader.MoveToFirstAttribute
   IF hr = %S_FALSE THEN
      FUNCTION = hr
      EXIT FUNCTION
   END IF

   IF hr <> %S_OK THEN
      STDOUT "Error moving to first attribute &H" & HEX$(hr)
      FUNCTION = -1
   END IF

   DO
      IF ISFALSE pReader.IsDefault THEN
         hr = pReader.GetPrefix(pwszPrefix)
         IF FAILED(hr) THEN
            STDOUT "Error getting prefix &H" & HEX$(hr)
            hr = -1
            EXIT DO
         END IF
         hr = pReader.GetLocalName(pwszLocalName)
         IF FAILED(hr) THEN
            STDOUT "Error getting local name &H" & HEX$(hr)
            hr = -1
            EXIT DO
         END IF
         hr = pReader.GetValue(pwszValue)
         IF FAILED(hr) THEN
            STDOUT "Error getting value &H" & HEX$(hr)
            hr = -1
            EXIT DO
         END IF
         IF pwszPrefix THEN
            STDOUT "Attr: " & @pwszPrefix & " " & @pwszLocalName
         ELSE
            STDOUT "Attr: " & @pwszLocalName & " " & @pwszValue
         END IF
      END IF
      hr = pReader.MoveToNextAttribute
      IF hr <> %S_OK THEN EXIT DO
   LOOP

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL hr AS LONG
   LOCAL pFileStream AS IStream
   LOCAL nodeType AS LONG
   LOCAL pwszPrefix AS WSTRINGZ PTR
   LOCAL pwszLocalName AS WSTRINGZ PTR
   LOCAL pwszValue AS WSTRINGZ PTR
   LOCAL nCount AS LONG

   ' // Open read-only input stream
   hr = SHCreateStreamOnFile("stocks.xml", %STGM_READ, pFileStream)
   IF FAILED(hr) THEN
      STDOUT "SHCreateStreamOnFile error &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF

   ' // Create the reader
   LOCAL pReader AS IXmlReader
   hr = CreateXmlReader($IID_IXmlReader, pReader, NOTHING)
   IF FAILED(hr) THEN
      STDOUT "CreateXmlReader error &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF

   ' // Set the DtdProcessing_Prohibit property
   hr = pReader.SetProperty(%XmlReaderProperty_DtdProcessing, %DtdProcessing_Prohibit)
   IF FAILED(hr) THEN
      STDOUT "Error setting XmlReaderProperty_DtdProcessing &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF

   ' // Set the input source of the XML document to be parsed
   hr = pReader.SetInput(pFileStream)
   IF FAILED(hr) THEN
      STDOUT "Error setting input for reader &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF

   ' // Parse the xml file
   DO
      hr = pReader.Read(nodeType)
      IF hr <> %S_OK THEN EXIT DO
      SELECT CASE AS LONG nodeType
         CASE %XmlNodeType_XmlDeclaration
            STDOUT "XmlDeclaration"
            hr = WriteAttributes(pReader)
            IF FAILED(hr) THEN
               STDOUT "Error writing attributes &H" & HEX$(hr)
               EXIT DO
            END IF
         CASE %XmlNodeType_Element
            hr = pReader.GetPrefix(pwszPrefix)
            IF FAILED(hr) THEN
               STDOUT "Error getting prefix &H" & HEX$(hr)
               EXIT DO
            END IF
            hr = pReader.GetLocalName(pwszLocalName)
            IF FAILED(hr) THEN
               STDOUT "Error getting local name &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pwszPrefix THEN
               STDOUT "Element: " & @pwszPrefix & @pwszLocalName
            ELSE
               STDOUT "Element: " & @pwszLocalName & @pwszValue
            END IF
            hr = WriteAttributes(pReader)
            IF FAILED(hr) THEN
               STDOUT "Error writing attributes &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pReader.IsEmptyElement THEN
               STDOUT "Empty"
            END IF
         CASE %XmlNodeType_EndElement
            hr = pReader.GetPrefix(pwszPrefix)
            IF FAILED(hr) THEN
               STDOUT "Error getting prefix &H" & HEX$(hr)
               EXIT DO
            END IF
            hr = pReader.GetLocalName(pwszLocalName)
            IF FAILED(hr) THEN
               STDOUT "Error getting local name &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pwszPrefix THEN
               STDOUT "End element: " & @pwszPrefix & " " & @pwszLocalName
            ELSE
               STDOUT "End element: " & @pwszLocalName & " " & @pwszValue
            END IF
            hr = WriteAttributes(pReader)
            IF FAILED(hr) THEN
               STDOUT "Error writing attributes &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pReader.IsEmptyElement THEN
               STDOUT "Empty"
            END IF
         CASE %XmlNodeType_Text, %XmlNodeType_Whitespace
            hr = pReader.GetValue(pwszValue)
            IF FAILED(hr) THEN
               STDOUT "Error getting value &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pwszValue THEN STDOUT "Text: " & @pwszValue
         CASE %XmlNodeType_CDATA
            hr = pReader.GetValue(pwszValue)
            IF FAILED(hr) THEN
               STDOUT "Error getting value &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pwszValue THEN STDOUT "CDATA: " & @pwszValue
         CASE %XmlNodeType_ProcessingInstruction
            hr = pReader.GetLocalName(pwszLocalName)
            IF FAILED(hr) THEN
               STDOUT "Error getting local name &H" & HEX$(hr)
               EXIT DO
            END IF
            hr = pReader.GetValue(pwszValue)
            IF FAILED(hr) THEN
               STDOUT "Error getting value &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pwszValue THEN STDOUT "Processing Instruction name: " & @pwszLocalName & " value " & @pwszValue
         CASE %XmlNodeType_Comment
            hr = pReader.GetValue(pwszValue)
            IF FAILED(hr) THEN
               STDOUT "Error getting value &H" & HEX$(hr)
               EXIT DO
            END IF
            IF pwszValue THEN STDOUT "Comment: " & @pwszValue
         CASE %XmlNodeType_DocumentType
            STDOUT "DOCTYPE is not printed"
      END SELECT
   LOOP

   WAITKEY$

END FUNCTION
' ========================================================================================
