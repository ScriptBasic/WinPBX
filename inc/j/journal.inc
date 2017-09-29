' ########################################################################################
' Microsoft Windows
' File: journal.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: JournalLib
' Version: 1.0, Locale ID = 0
' Description: Journal Reader 1.0 Type Library
' Path: C:\Program Files\Common Files\Microsoft Shared\Ink\Journal.dll
' Library GUID: {EABAA706-4A6D-4E45-A255-A6E86C403ADB}
' ########################################################################################

#INCLUDE THIS ONCE
%JOURNAL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_JournalLib = GUID$("{EABAA706-4A6D-4E45-A255-A6E86C403ADB}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {B4124623-FC0E-47CE-BCA9-126A6104ADA1}
$PROGID_JournalReader1 = "Journal.JournalReader.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {B4124623-FC0E-47CE-BCA9-126A6104ADA1}
$PROGID_JournalReader = "Journal.JournalReader"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_JournalReader = GUID$("{B4124623-FC0E-47CE-BCA9-126A6104ADA1}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IJournalReader = GUID$("{26213A0B-5A6C-4472-923D-9F29EFF608B2}")

'#define GUID_STROKE_TIMESTAMP                    L"{04EA66C4-F33A-461B-B8FE-68070D9C7575}"
'#define GUID_STROKE_TIMEID                       L"{050B6BC8-3B7D-4816-8C61-BC7E905B2132}"
'#define GUID_HIGHLIGHTER                         L"{9B6267B8-3968-4048-AB74-F490406A2DFA}"
'#define GUID_INK_STYLE_BOLD                      L"{E02FB5C1-9693-4312-A434-00DE7F3AD493}"
'#define GUID_INK_STYLE_ITALICS                   L"{05253b51-49C6-4A04-8993-64DD9ABD842A}"

$$GUID_STROKE_TIMESTAMP                    = "{04EA66C4-F33A-461B-B8FE-68070D9C7575}"$$
$$GUID_STROKE_TIMEID                       = "{050B6BC8-3B7D-4816-8C61-BC7E905B2132}"$$
$$GUID_HIGHLIGHTER                         = "{9B6267B8-3968-4048-AB74-F490406A2DFA}"$$
$$GUID_INK_STYLE_BOLD                      = "{E02FB5C1-9693-4312-A434-00DE7F3AD493}"$$
$$GUID_INK_STYLE_ITALICS                   = "{05253b51-49C6-4A04-8993-64DD9ABD842A}"$$

' ########################################################################################
' Interface name = IJournalReader
' IID = {26213A0B-5A6C-4472-923D-9F29EFF608B2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IJournalReader_INTERFACE_DEFINED)
    %IJournalReader_INTERFACE_DEFINED = 1

INTERFACE IJournalReader $IID_IJournalReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadFromStream ( _                            ' VTable offset = 12
     BYVAL pJntFile AS IStream _                        ' __in IStream *pJntFile
   , BYREF ppJntXml AS IStream _                        ' __retval_out IStream **ppJntXml
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IJournalReader_INTERFACE_DEFINED__ */
