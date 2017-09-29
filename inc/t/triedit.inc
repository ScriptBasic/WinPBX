' ########################################################################################
' Microsoft Windows
' File: triedit.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TRIEDITLib
' Version: 1.0
' Documentation string: triedit 1.0 Type Library
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\Triedit\triedit.dll
' Library GUID: {438DA5D1-F171-11D0-984E-0000F80270F8}
' ########################################################################################

#INCLUDE THIS ONCE
%TRIEDIT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {438DA5E0-F171-11D0-984E-0000F80270F8}
$PROGID_TriEditDocumentTriEditDocument1 = "TriEditDocument.TriEditDocument.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {438DA5E0-F171-11D0-984E-0000F80270F8}
$PROGID_TriEditDocumentTriEditDocument = "TriEditDocument.TriEditDocument"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_TriEditDocument = GUID$("{438DA5E0-F171-11D0-984E-0000F80270F8}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ITriEditDocument = GUID$("{438DA5DF-F171-11D0-984E-0000F80270F8}")

'// dwFlags to indicate what needs to be filtered
%dwFilterDefaults            = &H00000000???
%dwFilterNone                = &H00000001???
%dwFilterDTCs                = &H00000002???
%dwFilterDTCsWithoutMetaTags = &H00000004???
%dwFilterServerSideScripts   = &H00000008???
%dwPreserveSourceCode        = &H00000010???   ' // whitespace & attrib order
%dwFilterSourceCode          = &H00000020???   ' // set by control for FilterSourceCode Method
%dwFilterMultiByteStream     = &H10000000???
%dwFilterUsePstmNew          = &H20000000???

%E_FILTER_FRAMESET           = &H80100001&
%E_FILTER_SERVERSCRIPT       = &H80100002&
%E_FILTER_MULTIPLETAGS       = &H80100004&
%E_FILTER_SCRIPTLISTING      = &H80100008&
%E_FILTER_SCRIPTLABEL        = &H80100010&
%E_FILTER_SCRIPTTEXTAREA     = &H80100020&
%E_FILTER_SCRIPTSELECT       = &H80100040&


' ########################################################################################
' Interface name = ITriEditDocument
' IID = {438DA5DF-F171-11D0-984E-0000F80270F8}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITriEditDocument_INTERFACE_DEFINED)
    %ITriEditDocument_INTERFACE_DEFINED = 1

INTERFACE ITriEditDocument $IID_ITriEditDocument

   INHERIT IDispatch

   ' =====================================================================================
   METHOD FilterIn <1610743808> ( _                     ' VTable offset = 28
     BYVAL pStmOld AS IUnknown _                        ' __in IUnknown *pStmOld
   , BYREF ppStmNew AS IUnknown _                       ' __out IUnknown **ppStmNew
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL bstrBaseURL AS WSTRING _                     ' __in BSTR bstrBaseURL
   )                                                    ' void
   ' =====================================================================================
   METHOD FilterOut <1610743809> ( _                    ' VTable offset = 32
     BYVAL pStmOld AS IUnknown _                        ' __in IUnknown *pStmOld
   , BYREF ppStmNew AS IUnknown _                       ' __out IUnknown **ppStmNew
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL bstrBaseURL AS WSTRING _                     ' __in BSTR bstrBaseURL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITriEditDocument_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDocHostDragDropHandler
' IID = {438DA5DF-F171-11D0-984E-0000F80270F8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDocHostDragDropHandler_INTERFACE_DEFINED)
    %IDocHostDragDropHandler_INTERFACE_DEFINED = 1

$IID_IDocHostDragDropHandler = GUID$("{25188F40-D959-11D1-989F-0000F80270F8}")

INTERFACE IDocHostDragDropHandler $IID_IDocHostDragDropHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DrawDragFeedback ( _                          ' VTable offset = 12
     BYREF pRect AS RECT _                              ' __inout RECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDocHostDragDropHandler_INTERFACE_DEFINED__ */
