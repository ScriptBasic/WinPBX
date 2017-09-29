' ########################################################################################
' Microsoft Windows
' File: DHtmled.inc
' Library name: DHTMLEDLib
' Version: 1.0, Locale ID = 0
' Library GUID: {683364A1-B37D-11D1-ADC5-006008A5848C}
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\Triedit\dhtmled.ocx
' Contents: DHTML Edit Control for IE5
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DHTMLED_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "docobj.inc"
#INCLUDE ONCE "mshtmlc.inc"

$LIBID_DHTMLEDLib = GUID$("{683364A1-B37D-11D1-ADC5-006008A5848C}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_DEGetBlockFmtNamesParam1 = "DEGetBlockFmtNamesParam.DEGetBlockFmtNamesParam.1"
' CLSID = {47B0DFC7-B7A3-11D1-ADC5-006008A5848C}
$PROGID_DEInsertTableParam1 = "DEInsertTableParam.DEInsertTableParam.1"
' CLSID = {2D360200-FFF5-11D1-8D03-00A0C959BC0A}
$PROGID_DHTMLEdit1 = "DHTMLEdit.DHTMLEdit.1"
' CLSID = {2D360201-FFF5-11D1-8D03-00A0C959BC0A}
$PROGID_DHTMLSafe1 = "DHTMLSafe.DHTMLSafe.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {8D91090E-B955-11D1-ADC5-006008A5848C}
$PROGID_DEGetBlockFmtNamesParam = "DEGetBlockFmtNamesParam.DEGetBlockFmtNamesParam"
' CLSID = {47B0DFC7-B7A3-11D1-ADC5-006008A5848C}
$PROGID_DEInsertTableParam = "DEInsertTableParam.DEInsertTableParam"
' CLSID = {2D360200-FFF5-11D1-8D03-00A0C959BC0A}
$PROGID_DHTMLEdit = "DHTMLEdit.DHTMLEdit"
' CLSID = {2D360201-FFF5-11D1-8D03-00A0C959BC0A}
$PROGID_DHTMLSafe = "DHTMLSafe.DHTMLSafe"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DEGetBlockFmtNamesParam = GUID$("{8D91090E-B955-11D1-ADC5-006008A5848C}")
$CLSID_DEInsertTableParam = GUID$("{47B0DFC7-B7A3-11D1-ADC5-006008A5848C}")
$CLSID_DHTMLEdit = GUID$("{2D360200-FFF5-11D1-8D03-00A0C959BC0A}")
$CLSID_DHTMLSafe = GUID$("{2D360201-FFF5-11D1-8D03-00A0C959BC0A}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDEGetBlockFmtNamesParam = GUID$("{8D91090D-B955-11D1-ADC5-006008A5848C}")
$IID_IDEInsertTableParam = GUID$("{47B0DFC6-B7A3-11D1-ADC5-006008A5848C}")
$IID_IDHTMLEdit = GUID$("{CE04B591-2B1F-11D2-8D1E-00A0C959BC0A}")
$IID_IDHTMLSafe = GUID$("{CE04B590-2B1F-11D2-8D1E-00A0C959BC0A}")
$IID__DHTMLEditEvents = GUID$("{588D5040-CF28-11D1-8CD3-00A0C959BC0A}")
$IID__DHTMLSafeEvents = GUID$("{D1FC78E8-B380-11D1-ADC5-006008A5848C}")


%DE_E_INVALIDARG                = %E_INVALIDARG
%DE_E_PATH_NOT_FOUND            = &H80070003&   ' HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)
%DE_E_FILE_NOT_FOUND            = &H80070002&   ' HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)
%DE_E_UNEXPECTED                = %E_UNEXPECTED
%DE_E_DISK_FULL                 = &H80070027&   ' HRESULT_FROM_WIN32(ERROR_HANDLE_DISK_FULL)
%DE_E_NOTSUPPORTED              = %OLECMDERR_E_NOTSUPPORTED
%DE_E_ACCESS_DENIED             = &H80070005&   ' HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)

%DE_E_URL_SYNTAX                = %MK_E_SYNTAX
%DE_E_INVALID_URL               = &H800C0002&
%DE_E_NO_SESSION                = &H800C0003&
%DE_E_CANNOT_CONNECT            = &H800C0004&
%DE_E_RESOURCE_NOT_FOUND        = &H800C0005&
%DE_E_OBJECT_NOT_FOUND          = &H800C0006&
%DE_E_DATA_NOT_AVAILABLE        = &H800C0007&
%DE_E_DOWNLOAD_FAILURE          = &H800C0008&
%DE_E_AUTHENTICATION_REQUIRED   = &H800C0009&
%DE_E_NO_VALID_MEDIA            = &H800C000A&
%DE_E_CONNECTION_TIMEOUT        = &H800C000B&
%DE_E_INVALID_REQUEST           = &H800C000C&
%DE_E_UNKNOWN_PROTOCOL          = &H800C000D&
%DE_E_SECURITY_PROBLEM          = &H800C000E&
%DE_E_CANNOT_LOAD_DATA          = &H800C000F&
%DE_E_CANNOT_INSTANTIATE_OBJECT = &H800C0010&
%DE_E_REDIRECT_FAILED           = &H800C0014&
%DE_E_REDIRECT_TO_DIR           = &H800C0015&
%DE_E_CANNOT_LOCK_REQUEST       = &H800C0016&

%DE_E_FILTER_FRAMESET           = &H80100001&
%DE_E_FILTER_SERVERSCRIPT       = &H80100002&
%DE_E_FILTER_MULTIPLETAGS       = &H80100004&
%DE_E_FILTER_SCRIPTLISTING      = &H80100008&
%DE_E_FILTER_SCRIPTLABEL        = &H80100010&
%DE_E_FILTER_SCRIPTTEXTAREA     = &H80100020&
%DE_E_FILTER_SCRIPTSELECT       = &H80100040&


' ========================================================================================
' DHTMLEDITCMDID enum
' IID: {B23B8AA2-A8B4-11D1-ADC2-006008A5848C}
' ========================================================================================

%DECMD_BOLD             = 5000
%DECMD_COPY             = 5002
%DECMD_CUT              = %DECMD_COPY             + 1
%DECMD_DELETE           = %DECMD_CUT              + 1
%DECMD_DELETECELLS      = %DECMD_DELETE           + 1
%DECMD_DELETECOLS       = %DECMD_DELETECELLS      + 1
%DECMD_DELETEROWS       = %DECMD_DELETECOLS       + 1
%DECMD_FINDTEXT         = %DECMD_DELETEROWS       + 1
%DECMD_FONT             = %DECMD_FINDTEXT         + 1
%DECMD_GETBACKCOLOR     = %DECMD_FONT             + 1
%DECMD_GETBLOCKFMT      = %DECMD_GETBACKCOLOR     + 1
%DECMD_GETBLOCKFMTNAMES = %DECMD_GETBLOCKFMT      + 1
%DECMD_GETFONTNAME      = %DECMD_GETBLOCKFMTNAMES + 1
%DECMD_GETFONTSIZE      = %DECMD_GETFONTNAME      + 1
%DECMD_GETFORECOLOR     = %DECMD_GETFONTSIZE      + 1
%DECMD_HYPERLINK        = %DECMD_GETFORECOLOR     + 1
%DECMD_IMAGE            = %DECMD_HYPERLINK        + 1
%DECMD_INDENT           = %DECMD_IMAGE            + 1
%DECMD_INSERTCELL       = %DECMD_INDENT           + 1
%DECMD_INSERTCOL        = %DECMD_INSERTCELL       + 1
%DECMD_INSERTROW        = %DECMD_INSERTCOL        + 1
%DECMD_INSERTTABLE      = %DECMD_INSERTROW        + 1
%DECMD_ITALIC           = %DECMD_INSERTTABLE      + 1
%DECMD_JUSTIFYCENTER    = %DECMD_ITALIC           + 1
%DECMD_JUSTIFYLEFT      = %DECMD_JUSTIFYCENTER    + 1
%DECMD_JUSTIFYRIGHT     = %DECMD_JUSTIFYLEFT      + 1
%DECMD_LOCK_ELEMENT     = %DECMD_JUSTIFYRIGHT     + 1
%DECMD_MAKE_ABSOLUTE    = %DECMD_LOCK_ELEMENT     + 1
%DECMD_MERGECELLS       = %DECMD_MAKE_ABSOLUTE    + 1
%DECMD_ORDERLIST        = %DECMD_MERGECELLS       + 1
%DECMD_OUTDENT          = %DECMD_ORDERLIST        + 1
%DECMD_PASTE            = %DECMD_OUTDENT          + 1
%DECMD_REDO             = %DECMD_PASTE            + 1
%DECMD_REMOVEFORMAT     = %DECMD_REDO             + 1
%DECMD_SELECTALL        = %DECMD_REMOVEFORMAT     + 1
%DECMD_SEND_BACKWARD    = %DECMD_SELECTALL        + 1
%DECMD_BRING_FORWARD    = %DECMD_SEND_BACKWARD    + 1
%DECMD_SEND_BELOW_TEXT  = %DECMD_BRING_FORWARD    + 1
%DECMD_BRING_ABOVE_TEXT = %DECMD_SEND_BELOW_TEXT  + 1
%DECMD_SEND_TO_BACK     = %DECMD_BRING_ABOVE_TEXT + 1
%DECMD_BRING_TO_FRONT   = %DECMD_SEND_TO_BACK     + 1
%DECMD_SETBACKCOLOR     = %DECMD_BRING_TO_FRONT   + 1
%DECMD_SETBLOCKFMT      = %DECMD_SETBACKCOLOR     + 1
%DECMD_SETFONTNAME      = %DECMD_SETBLOCKFMT      + 1
%DECMD_SETFONTSIZE      = %DECMD_SETFONTNAME      + 1
%DECMD_SETFORECOLOR     = %DECMD_SETFONTSIZE      + 1
%DECMD_SPLITCELL        = %DECMD_SETFORECOLOR     + 1
%DECMD_UNDERLINE        = %DECMD_SPLITCELL        + 1
%DECMD_UNDO             = %DECMD_UNDERLINE        + 1
%DECMD_UNLINK           = %DECMD_UNDO             + 1
%DECMD_UNORDERLIST      = %DECMD_UNLINK           + 1
%DECMD_PROPERTIES       = %DECMD_UNORDERLIST      + 1

' ========================================================================================
' DHTMLEDITCMDF enum
' IID: {BF82426A-B961-11D1-ADC5-006008A5848C}
' ========================================================================================

%DECMDF_NOTSUPPORTED = 0
%DECMDF_DISABLED     = &H1
%DECMDF_ENABLED      = &H3
%DECMDF_LATCHED      = &H7
%DECMDF_NINCHED      = &Hb

' ========================================================================================
' DHTMLEDITAPPEARANCE enum
' IID: {7179FC44-B2E4-11D1-ADC5-006008A5848C}
' ========================================================================================

%DEAPPEARANCE_FLAT = 0
%DEAPPEARANCE_3D   = &H1


' ########################################################################################
' Interface name = IDEGetBlockFmtNamesParam
' IID = {8D91090D-B955-11D1-ADC5-006008A5848C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDEGetBlockFmtNamesParam_INTERFACE_DEFINED)
   %IDEGetBlockFmtNamesParam_INTERFACE_DEFINED = 1

INTERFACE IDEGetBlockFmtNamesParam $IID_IDEGetBlockFmtNamesParam

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Names <1> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET Names <1> ( _                           ' VTable offset = 32
     BYREF IN VARIANT _                                 ' __in VARIANT *newVa
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDEGetBlockFmtNamesParam_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDHTMLSafe
' IID = {CE04B590-2B1F-11D2-8D1E-00A0C959BC0A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDHTMLSafe_INTERFACE_DEFINED)
   %IDHTMLSafe_INTERFACE_DEFINED = 1

INTERFACE IDHTMLSafe $IID_IDHTMLSafe

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ExecCommand <2> ( _                           ' VTable offset = 28
     BYVAL cmdID AS LONG _                              ' __in DHTMLEDITCMDID cmdID
   , OPTIONAL BYVAL cmdexecopt AS LONG _                ' __in_opt OLECMDEXECOPT cmdexecopt
   , OPTIONAL BYREF pInVar AS VARIANT _                 ' __in_opt VARIANT *pInVar
   ) AS VARIANT                                         ' __retval_out VARIANT *pOutVar
   ' =====================================================================================
   METHOD QueryStatus <3> ( _                           ' VTable offset = 32
     BYVAL cmdID AS LONG _                              ' __in DHTMLEDITCMDID cmdID
   ) AS LONG                                            ' __retval_out DHTMLEDITCMDF *retval
   ' =====================================================================================
   METHOD SetContextMenu <5> ( _                        ' VTable offset = 36
     BYREF menuStrings AS VARIANT _                     ' __in VARIANT *menuStrings
   , BYREF menuStates AS VARIANT _                      ' __in VARIANT *menuStates
   )                                                    ' void
   ' =====================================================================================
   METHOD NewDocument <27> ( _                          ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadURL <29> ( _                              ' VTable offset = 44
     BYVAL url AS WSTRING _                             ' __in BSTR url
   )                                                    ' void
   ' =====================================================================================
   METHOD FilterSourceCode <31> ( _                     ' VTable offset = 48
     BYVAL sourceCodeIn AS WSTRING _                    ' __in BSTR sourceCodeIn
   ) AS WSTRING                                         ' __retval_out BSTR *sourceCodeOut
   ' =====================================================================================
   METHOD Refresh <32> ( _                              ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DOM <6> ( _                             ' VTable offset = 56
   ) AS IHTMLDocument2                                  ' __retval_out IHTMLDocument2 **pVal
   ' =====================================================================================
   PROPERTY GET DocumentHTML <17> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *docHTML
   ' =====================================================================================
   PROPERTY SET DocumentHTML <17> ( _                   ' VTable offset = 64
     BYVAL docHTML AS WSTRING _                         ' __in BSTR docHTML
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActivateApplets <7> ( _                 ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ActivateApplets <7> ( _                 ' VTable offset = 72
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActivateActiveXControls <8> ( _         ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ActivateActiveXControls <8> ( _         ' VTable offset = 80
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActivateDTCs <9> ( _                    ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ActivateDTCs <9> ( _                    ' VTable offset = 88
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDetails <11> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ShowDetails <11> ( _                    ' VTable offset = 96
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowBorders <12> ( _                    ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ShowBorders <12> ( _                    ' VTable offset = 104
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <13> ( _                     ' VTable offset = 108
   ) AS LONG                                            ' __retval_out DHTMLEDITAPPEARANCE *pVal
   ' =====================================================================================
   PROPERTY SET Appearance <13> ( _                     ' VTable offset = 112
     BYVAL newVal AS LONG _                             ' __in DHTMLEDITAPPEARANCE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scrollbars <14> ( _                     ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Scrollbars <14> ( _                     ' VTable offset = 120
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollbarAppearance <15> ( _            ' VTable offset = 124
   ) AS LONG                                            ' __retval_out DHTMLEDITAPPEARANCE *pVal
   ' =====================================================================================
   PROPERTY SET ScrollbarAppearance <15> ( _            ' VTable offset = 128
     BYVAL newVal AS LONG _                             ' __in DHTMLEDITAPPEARANCE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceCodePreservation <16> ( _         ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET SourceCodePreservation <16> ( _         ' VTable offset = 136
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsoluteDropMode <18> ( _               ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET AbsoluteDropMode <18> ( _               ' VTable offset = 144
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SnapToGridX <19> ( _                    ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SnapToGridX <19> ( _                    ' VTable offset = 152
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SnapToGridY <20> ( _                    ' VTable offset = 156
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SnapToGridY <20> ( _                    ' VTable offset = 160
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SnapToGrid <21> ( _                     ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET SnapToGrid <21> ( _                     ' VTable offset = 168
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsDirty <22> ( _                        ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET CurrentDocumentPath <23> ( _            ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *docPath
   ' =====================================================================================
   PROPERTY GET BaseURL <24> ( _                        ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *baseURL
   ' =====================================================================================
   PROPERTY SET BaseURL <24> ( _                        ' VTable offset = 184
     BYVAL baseURL AS WSTRING _                         ' __in BSTR baseURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocumentTitle <25> ( _                  ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *docTitle
   ' =====================================================================================
   PROPERTY GET UseDivOnCarriageReturn <30> ( _         ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET UseDivOnCarriageReturn <30> ( _         ' VTable offset = 196
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Busy <33> ( _                           ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDHTMLSafe_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDHTMLEdit
' IID = {CE04B591-2B1F-11D2-8D1E-00A0C959BC0A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDHTMLSafe
' ########################################################################################

#IF NOT %DEF(%IDHTMLEdit_INTERFACE_DEFINED)
    %IDHTMLEdit_INTERFACE_DEFINED = 1

INTERFACE IDHTMLEdit $IID_IDHTMLEdit

   INHERIT IDispatch

   ' =====================================================================================
   ' IDHTMLSafe Methods
   ' =====================================================================================
   METHOD ExecCommand <2> ( _                           ' VTable offset = 28
     BYVAL cmdID AS LONG _                              ' __in DHTMLEDITCMDID cmdID
   , OPTIONAL BYVAL cmdexecopt AS LONG _                ' __in_opt OLECMDEXECOPT cmdexecopt
   , OPTIONAL BYREF pInVar AS VARIANT _                 ' __in_opt VARIANT *pInVar
   ) AS VARIANT                                         ' __retval_out VARIANT *pOutVar
   ' =====================================================================================
   METHOD QueryStatus <3> ( _                           ' VTable offset = 32
     BYVAL cmdID AS LONG _                              ' __in DHTMLEDITCMDID cmdID
   ) AS LONG                                            ' __retval_out DHTMLEDITCMDF *retval
   ' =====================================================================================
   METHOD SetContextMenu <5> ( _                        ' VTable offset = 36
     BYREF menuStrings AS VARIANT _                     ' __in VARIANT *menuStrings
   , BYREF menuStates AS VARIANT _                      ' __in VARIANT *menuStates
   )                                                    ' void
   ' =====================================================================================
   METHOD NewDocument <27> ( _                          ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadURL <29> ( _                              ' VTable offset = 44
     BYVAL url AS WSTRING _                             ' __in BSTR url
   )                                                    ' void
   ' =====================================================================================
   METHOD FilterSourceCode <31> ( _                     ' VTable offset = 48
     BYVAL sourceCodeIn AS WSTRING _                    ' __in BSTR sourceCodeIn
   ) AS WSTRING                                         ' __retval_out BSTR *sourceCodeOut
   ' =====================================================================================
   METHOD Refresh <32> ( _                              ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DOM <6> ( _                             ' VTable offset = 56
   ) AS IHTMLDocument2                                  ' __retval_out IHTMLDocument2 **pVal
   ' =====================================================================================
   PROPERTY GET DocumentHTML <17> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *docHTML
   ' =====================================================================================
   PROPERTY SET DocumentHTML <17> ( _                   ' VTable offset = 64
     BYVAL docHTML AS WSTRING _                         ' __in BSTR docHTML
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActivateApplets <7> ( _                 ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ActivateApplets <7> ( _                 ' VTable offset = 72
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActivateActiveXControls <8> ( _         ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ActivateActiveXControls <8> ( _         ' VTable offset = 80
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActivateDTCs <9> ( _                    ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ActivateDTCs <9> ( _                    ' VTable offset = 88
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDetails <11> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ShowDetails <11> ( _                    ' VTable offset = 96
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowBorders <12> ( _                    ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET ShowBorders <12> ( _                    ' VTable offset = 104
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <13> ( _                     ' VTable offset = 108
   ) AS LONG                                            ' __retval_out DHTMLEDITAPPEARANCE *pVal
   ' =====================================================================================
   PROPERTY SET Appearance <13> ( _                     ' VTable offset = 112
     BYVAL newVal AS LONG _                             ' __in DHTMLEDITAPPEARANCE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scrollbars <14> ( _                     ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Scrollbars <14> ( _                     ' VTable offset = 120
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollbarAppearance <15> ( _            ' VTable offset = 124
   ) AS LONG                                            ' __retval_out DHTMLEDITAPPEARANCE *pVal
   ' =====================================================================================
   PROPERTY SET ScrollbarAppearance <15> ( _            ' VTable offset = 128
     BYVAL newVal AS LONG _                             ' __in DHTMLEDITAPPEARANCE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceCodePreservation <16> ( _         ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET SourceCodePreservation <16> ( _         ' VTable offset = 136
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsoluteDropMode <18> ( _               ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET AbsoluteDropMode <18> ( _               ' VTable offset = 144
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SnapToGridX <19> ( _                    ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SnapToGridX <19> ( _                    ' VTable offset = 152
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SnapToGridY <20> ( _                    ' VTable offset = 156
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SnapToGridY <20> ( _                    ' VTable offset = 160
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SnapToGrid <21> ( _                     ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET SnapToGrid <21> ( _                     ' VTable offset = 168
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsDirty <22> ( _                        ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET CurrentDocumentPath <23> ( _            ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *docPath
   ' =====================================================================================
   PROPERTY GET BaseURL <24> ( _                        ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *baseURL
   ' =====================================================================================
   PROPERTY SET BaseURL <24> ( _                        ' VTable offset = 184
     BYVAL baseURL AS WSTRING _                         ' __in BSTR baseURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocumentTitle <25> ( _                  ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *docTitle
   ' =====================================================================================
   PROPERTY GET UseDivOnCarriageReturn <30> ( _         ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET UseDivOnCarriageReturn <30> ( _         ' VTable offset = 196
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Busy <33> ( _                           ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IDHTMLEdit Methods
   ' =====================================================================================
   METHOD LoadDocument <1> ( _                          ' VTable offset = 204
     BYREF pathIn AS VARIANT _                          ' __in VARIANT *pathIn
   , OPTIONAL BYREF promptUser AS VARIANT _             ' __in_opt VARIANT *promptUser
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveDocument <4> ( _                          ' VTable offset = 208
     BYREF pathIn AS VARIANT _                          ' __in VARIANT *pathIn
   , OPTIONAL BYREF promptUser AS VARIANT _             ' __in_opt VARIANT *promptUser
   )                                                    ' void
   ' =====================================================================================
   METHOD PrintDocument <28> ( _                        ' VTable offset = 212
     OPTIONAL BYREF withUI AS VARIANT _                 ' __in_opt VARIANT *withUI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BrowseMode <26> ( _                     ' VTable offset = 216
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET BrowseMode <26> ( _                     ' VTable offset = 220
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDHTMLEdit_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDEInsertTableParam
' IID = {47B0DFC6-B7A3-11D1-ADC5-006008A5848C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDEInsertTableParam_INTERFACE_DEFINED)
    %IDEInsertTableParam_INTERFACE_DEFINED = 1

INTERFACE IDEInsertTableParam $IID_IDEInsertTableParam

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NumRows <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET NumRows <1> ( _                         ' VTable offset = 32
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumCols <2> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET NumCols <2> ( _                         ' VTable offset = 40
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TableAttrs <3> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET TableAttrs <3> ( _                      ' VTable offset = 48
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CellAttrs <4> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET CellAttrs <4> ( _                       ' VTable offset = 56
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <5> ( _                         ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Caption <5> ( _                         ' VTable offset = 64
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDEInsertTableParam_INTERFACE_DEFINED__ */
