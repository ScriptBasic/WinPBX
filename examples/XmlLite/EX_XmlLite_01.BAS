' ########################################################################################
' Microsoft Windows
' File: EX_XmlLite_01.bas
' Contents: XmlLite example
' The following example demonstrates how to parse an XML file using XmlLite.
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

FUNCTION PBMAIN () AS LONG

   LOCAL hr AS LONG

   ' // Open read-only input stream
   LOCAL pFileStream AS IStream
   hr = SHCreateStreamOnFile("books.xml", %STGM_READ, pFileStream)
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
      STDOUT "IXmlReader.SetProperty error &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF

   ' // Set the input source of the XML document to be parsed
   hr = pReader.SetInput(pFileStream)
   IF FAILED(hr) THEN
      STDOUT "IXmlReader.SetInput error &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF

   LOCAL nodeType AS LONG
   LOCAL pwszPrefix AS DWORD
   LOCAL cwchPrefix AS DWORD
   LOCAL pwszLocalName AS WSTRINGZ PTR
   LOCAL pwszValue AS WSTRINGZ PTR
   LOCAL nCount AS LONG

   ' // Parse the xml file
   DO
      hr = pReader.Read(nodeType)
      IF hr <> %S_OK THEN EXIT DO
      SELECT CASE AS LONG nodeType
         CASE %XmlNodeType_XmlDeclaration
            STDOUT "XmlDeclaration"
         CASE %XmlNodeType_Element
            IF pReader.IsEmptyElement THEN
               STDOUT "Empty"
            ELSE
               hr = pReader.GetLocalName(pwszLocalName)
               IF FAILED(hr) THEN
                  STDOUT "Error getting local name &H" & HEX$(hr)
               ELSE
                  IF pwszLocalName THEN STDOUT "Element: " & @pwszLocalName
               END IF
            END IF
         CASE %XmlNodeType_EndElement
            IF pReader.IsEmptyElement THEN
               STDOUT "Empty"
            ELSE
               hr = pReader.GetLocalName(pwszLocalName)
               IF FAILED(hr) THEN
                  STDOUT "Error getting local name &H" & HEX$(hr)
               ELSE
                  IF pwszLocalName THEN STDOUT "Element: " & @pwszLocalName
               END IF
            END IF
         CASE %XmlNodeType_Text
            hr = pReader.GetValue(pwszValue)
            IF FAILED(hr) THEN
               STDOUT "Error getting value &H" & HEX$(hr)
            ELSE
               IF pwszValue THEN STDOUT "Text: " & @pwszValue
            END IF
      END SELECT
   LOOP

   WAITKEY$

END FUNCTION
