' ########################################################################################
' Microsoft Windows
' File: AfxBase64.inc
' Contents: Base64 encoding/decoding.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXBASE64_INC = 1

#INCLUDE ONCE "AfxWin.inc"
#INCLUDE ONCE "MSXML.INC"

' ========================================================================================
' Base64 is a group of similar encoding schemes that represent binary data in an ASCII
' string format by translating it into a radix-64 representation. The Base64 term
' originates from a specific MIME content transfer encoding.
' Base64 encoding schemes are commonly used when there is a need to encode binary data
' that needs be stored and transferred over media that are designed to deal with textual
' data. This is to ensure that the data remains intact without modification during
' transport. Base64 is used commonly in a number of applications including email via MIME,
' and storing complex data in XML.
' ========================================================================================

' ========================================================================================
' Base64 mime encoding
' ========================================================================================
FUNCTION AfxBase64Encode (BYVAL bstrData AS WSTRING) AS WSTRING

   LOCAL pXmlDocument AS IXMLDOMDocument
   LOCAL pXmlElement AS IXMLDOMElement
   LOCAL vData AS VARIANT
   DIM   rgData(0) AS BYTE

   AfxStringToByteArray(bstrData, rgData())
   vData = rgData()

   TRY
      pXmlDocument = NEWCOM "Msxml2.DOMDocument"
      pXmlElement = pXmlDocument.createElement("b64")
      pXmlElement.dataType = "bin.base64"
      pXmlElement.nodeTypedValue = vData
      FUNCTION = pXmlElement.Text
   CATCH
'      MSGBOX HEX$(OBJRESULT, 8)
   END TRY

END FUNCTION
' ========================================================================================

' ========================================================================================
' Base64 mime decoding
' ========================================================================================
FUNCTION AfxBase64Decode (BYVAL bstrData AS WSTRING) AS WSTRING

   LOCAL pXmlDocument AS IXMLDOMDocument
   LOCAL pXmlElement AS IXMLDOMElement
   LOCAL vData AS VARIANT
   DIM   rgData(0) AS BYTE

   TRY
      pXmlDocument = NEWCOM "Msxml2.DOMDocument"
      pXmlElement = pXmlDocument.createElement("b64")
      pXmlElement.dataType = "bin.base64"
      pXmlElement.Text = bstrData
      vData = pXmlElement.nodeTypedValue
      rgData() = vData
      FUNCTION = AfxByteArrayToString(rgData())
   CATCH
'      MSGBOX HEX$(OBJRESULT, 8)
   END TRY

END FUNCTION
' ========================================================================================

' ========================================================================================
' Base64 mime encoding
' ========================================================================================
FUNCTION AfxBase64EncodeArray (BYREF rgData() AS BYTE) AS WSTRING

   LOCAL pXmlDocument AS IXMLDOMDocument
   LOCAL pXmlElement AS IXMLDOMElement
   LOCAL vData AS VARIANT

   vData = rgData()

   TRY
      pXmlDocument = NEWCOM "Msxml2.DOMDocument"
      pXmlElement = pXmlDocument.createElement("b64")
      pXmlElement.dataType = "bin.base64"
      pXmlElement.nodeTypedValue = vData
      FUNCTION = pXmlElement.Text
   CATCH
'      MSGBOX HEX$(OBJRESULT, 8)
   END TRY

END FUNCTION
' ========================================================================================
