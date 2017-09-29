' ########################################################################################
' Microsoft Windows
' File: MSAdodc.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSAdodcLib
' Version: 6.0, Locale ID = 0
' Documentation string: Microsoft ADO Data Control 6.0 (SP4) (OLEDB)
' Path: C:\WINDOWS\system32\MSADODC.OCX
' Library GUID: {67397AA1-7FB1-11D0-B148-00A0C922E820}
' Help file: C:\WINDOWS\HELP\adodc98.chm
' License key: C4145310-469C-11d1-B182-00A0C922E820
' ########################################################################################

#INCLUDE THIS ONCE
%MSADODC_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "ADO.INC"

$RTLKEY_ADODC = "C4145310-469C-11d1-B182-00A0C922E820"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_Adodc6 = "MSAdodcLib.Adodc.6"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Adodc = GUID$("{67397AA3-7FB1-11D0-B148-00A0C922E820}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DAdodcEvents = GUID$("{67397AA2-7FB1-11D0-B148-00A0C922E820}")
$IID_IAdodc = GUID$("{47A738F1-7FAF-11D0-B148-00A0C922E820}")

' ========================================================================================
' BOFActionEnum enum
' BOFAction constants
' ========================================================================================

%adDoMoveFirst                                          = 0            ' &H0
%adStayBOF                                              = 1            ' &H1

' ========================================================================================
' EOFActionEnum enum
' EOFAction constants
' ========================================================================================

%adDoMoveLast                                           = 0            ' &H0
%adStayEOF                                              = 1            ' &H1
%adDoAddNew                                             = 2            ' &H2

' ========================================================================================
' AppearanceEnum enum
' Appearance constants
' ========================================================================================

%adFlatBevel                                            = 0            ' &H0
%ad3DBevel                                              = 1            ' &H1

' ========================================================================================
' OrientationEnum enum
' Orientation constants
' ========================================================================================

%adHorizontal                                           = 0            ' &H0
%adVertical                                             = 1            ' &H1

' ========================================================================================
' ConnectStringTypeEnum enum
' ConnectStringType constants
' ========================================================================================

%adConnectTypeUnknown                                   = 0            ' &H0
%adConnectTypeOledb                                     = 1            ' &H1
%adConnectTypeOledbFile                                 = 2            ' &H2
%adConnectTypeOdbc                                      = 3            ' &H3

' ========================================================================================
' AdodcErrorEnum enum
' ADODC Error Constants
' ========================================================================================

%ERRADODC_ERRORINFO                                     = 25020        ' &H61BC
%ERRADODC_SETMODE                                       = 25021        ' &H61BD
%ERRADODC_SETCONNECTTIMEOUT                             = 25022        ' &H61BE
%ERRADODC_SETCURSORLOCATION                             = 25023        ' &H61BF
%ERRADODC_SETCOMMANDTIMEOUT                             = 25024        ' &H61C0
%ERRADODC_SETCACHESIZE                                  = 25025        ' &H61C1
%ERRADODC_SETMAXRECORDS                                 = 25026        ' &H61C2

' ========================================================================================
' CursorTypeEnum enum
' CursorType constants
' ========================================================================================

'%adOpenKeyset                                           = 1            ' &H1
'%adOpenDynamic                                          = 2            ' &H2
'%adOpenStatic                                           = 3            ' &H3

' ========================================================================================
' CursorLocationEnum enum
' CursorLocation constants
' ========================================================================================

'%adUseServer                                            = 2            ' &H2
'%adUseClient                                            = 3            ' &H3

' ========================================================================================
' CommandTypeEnum enum
' CommandTypeConstants
' ========================================================================================

'%adCmdUnknown                                           = 8            ' &H8
'%adCmdText                                              = 1            ' &H1
'%adCmdTable                                             = 2            ' &H2
'%adCmdStoredProc                                        = 4            ' &H4

' ########################################################################################
' Interface name = IAdodc
' IID = {47A738F1-7FAF-11D0-B148-00A0C922E820}
' Microsoft ADO Data Control 6.0 (SP4) (OLEDB)
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAdodc_INTERFACE_DEFINED)
    %IAdodc_INTERFACE_DEFINED = 1

INTERFACE IAdodc $IID_IAdodc

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConnectionString <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* bstrConnect
   ' =====================================================================================
   PROPERTY SET ConnectionString <1> ( _                ' VTable offset = 32
     BYVAL bstrConnect AS WSTRING _                     ' __in BSTR bstrConnect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDBString <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* bstrOLEDBString
   ' =====================================================================================
   PROPERTY SET OLEDBString <2> ( _                     ' VTable offset = 40
     BYVAL bstrOLEDBString AS WSTRING _                 ' __in BSTR bstrOLEDBString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDBFile <3> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* bstrOLEDBFile
   ' =====================================================================================
   PROPERTY SET OLEDBFile <3> ( _                       ' VTable offset = 48
     BYVAL bstrOLEDBFile AS WSTRING _                   ' __in BSTR bstrOLEDBFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSourceName <4> ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDataSourceName
   ' =====================================================================================
   PROPERTY SET DataSourceName <4> ( _                  ' VTable offset = 56
     BYVAL pbstrDataSourceName AS WSTRING _             ' __in BSTR pbstrDataSourceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OtherAttributes <5> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* bstrOtherAttributes
   ' =====================================================================================
   PROPERTY SET OtherAttributes <5> ( _                 ' VTable offset = 64
     BYVAL bstrOtherAttributes AS WSTRING _             ' __in BSTR bstrOtherAttributes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectStringType <6> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out ConnectStringTypeEnum* pnType
   ' =====================================================================================
   PROPERTY SET ConnectStringType <6> ( _               ' VTable offset = 72
     BYVAL pnType AS LONG _                             ' __in ConnectStringTypeEnum pnType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserName <7> ( _                        ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrUserName
   ' =====================================================================================
   PROPERTY SET UserName <7> ( _                        ' VTable offset = 80
     BYVAL pbstrUserName AS WSTRING _                   ' __in BSTR pbstrUserName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Password <8> ( _                        ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPassword
   ' =====================================================================================
   PROPERTY SET Password <8> ( _                        ' VTable offset = 88
     BYVAL pbstrPassword AS WSTRING _                   ' __in BSTR pbstrPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <9> ( _                            ' VTable offset = 92
   ) AS LONG                                            ' __retval_out ConnectModeEnum* pnMode
   ' =====================================================================================
   PROPERTY SET Mode <9> ( _                            ' VTable offset = 96
     BYVAL pnMode AS LONG _                             ' __in ConnectModeEnum pnMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <10> ( _                 ' VTable offset = 100
   ) AS LONG                                            ' __retval_out CursorLocationEnum* pnCursorLocation
   ' =====================================================================================
   PROPERTY SET CursorLocation <10> ( _                 ' VTable offset = 104
     BYVAL pnCursorLocation AS LONG _                   ' __in CursorLocationEnum pnCursorLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsolationLevel <11> ( _                 ' VTable offset = 108
   ) AS LONG                                            ' __retval_out IsolationLevelEnum* pnIsolationLevel
   ' =====================================================================================
   PROPERTY SET IsolationLevel <11> ( _                 ' VTable offset = 112
     BYVAL pnIsolationLevel AS LONG _                   ' __in IsolationLevelEnum pnIsolationLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectionTimeout <12> ( _              ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long* pnConnectionTimeout
   ' =====================================================================================
   PROPERTY SET ConnectionTimeout <12> ( _              ' VTable offset = 120
     BYVAL pnConnectionTimeout AS LONG _                ' __in long pnConnectionTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandTimeout <13> ( _                 ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long* pnCommandTimeout
   ' =====================================================================================
   PROPERTY SET CommandTimeout <13> ( _                 ' VTable offset = 128
     BYVAL pnCommandTimeout AS LONG _                   ' __in long pnCommandTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordSource <14> ( _                   ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrRecordSource
   ' =====================================================================================
   PROPERTY SET RecordSource <14> ( _                   ' VTable offset = 136
     BYVAL pbstrRecordSource AS WSTRING _               ' __in BSTR pbstrRecordSource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorType <15> ( _                     ' VTable offset = 140
   ) AS LONG                                            ' __retval_out CursorTypeEnum* pnCursorType
   ' =====================================================================================
   PROPERTY SET CursorType <15> ( _                     ' VTable offset = 144
     BYVAL pnCursorType AS LONG _                       ' __in CursorTypeEnum pnCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LockType <16> ( _                       ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LockTypeEnum* pnLockType
   ' =====================================================================================
   PROPERTY SET LockType <16> ( _                       ' VTable offset = 152
     BYVAL pnLockType AS LONG _                         ' __in LockTypeEnum pnLockType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandType <17> ( _                    ' VTable offset = 156
   ) AS LONG                                            ' __retval_out CommandTypeEnum* pnCommandType
   ' =====================================================================================
   PROPERTY SET CommandType <17> ( _                    ' VTable offset = 160
     BYVAL pnCommandType AS LONG _                      ' __in CommandTypeEnum pnCommandType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorOptions <18> ( _                  ' VTable offset = 164
   ) AS LONG                                            ' __retval_out CursorOptionEnum* pnOptions
   ' =====================================================================================
   PROPERTY GET CacheSize <19> ( _                      ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long* pnCacheSize
   ' =====================================================================================
   PROPERTY SET CacheSize <19> ( _                      ' VTable offset = 172
     BYVAL pnCacheSize AS LONG _                        ' __in long pnCacheSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxRecords <20> ( _                     ' VTable offset = 176
   ) AS LONG                                            ' __retval_out long* pnMaxRecords
   ' =====================================================================================
   PROPERTY SET MaxRecords <20> ( _                     ' VTable offset = 180
     BYVAL pnMaxRecords AS LONG _                       ' __in long pnMaxRecords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BOFAction <21> ( _                      ' VTable offset = 184
   ) AS LONG                                            ' __retval_out BOFActionEnum* pnBOFAction
   ' =====================================================================================
   PROPERTY SET BOFAction <21> ( _                      ' VTable offset = 188
     BYVAL pnBOFAction AS LONG _                        ' __in BOFActionEnum pnBOFAction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EOFAction <22> ( _                      ' VTable offset = 192
   ) AS LONG                                            ' __retval_out EOFActionEnum* nEOFAction
   ' =====================================================================================
   PROPERTY SET EOFAction <22> ( _                      ' VTable offset = 196
     BYVAL nEOFAction AS LONG _                         ' __in EOFActionEnum nEOFAction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <-518> ( _                      ' VTable offset = 200
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCaption
   ' =====================================================================================
   PROPERTY SET Caption <-518> ( _                      ' VTable offset = 204
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out AppearanceEnum* pnAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 212
     BYVAL pnAppearance AS LONG _                       ' __in AppearanceEnum pnAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 216
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 220
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 224
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 228
     BYVAL pocForeColor AS DWORD _                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <23> ( _                    ' VTable offset = 232
   ) AS LONG                                            ' __retval_out OrientationEnum* pnOrientation
   ' =====================================================================================
   PROPERTY SET Orientation <23> ( _                    ' VTable offset = 236
     BYVAL pnOrientation AS LONG _                      ' __in OrientationEnum pnOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Recordset <24> ( _                      ' VTable offset = 240
   ) AS ADORecordset                                    ' __retval_out _Recordset** ppADORecordset
   ' =====================================================================================
   PROPERTY SET putref_Recordset <24> ( _               ' VTable offset = 244
     BYVAL ppADORecordset AS ADORecordset _             ' __in _Recordset* ppADORecordset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 248
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppdispFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 252
     BYVAL ppdispFont AS IFontDisp _                    ' __in IFontDisp* ppdispFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 256
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 260
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <25> ( _                              ' VTable offset = 264
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 268
   )                                                    ' void
   ' =====================================================================================
   METHOD FireErrorInfo <26> ( _                        ' VTable offset = 272
     BYVAL sc AS LONG _                                 ' __in SCODE sc
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown* pUnknown
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAdodc_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CDAdodcEvents
' Interface name = DAdodcEvents
' IID = {67397AA2-7FB1-11D0-B148-00A0C922E820}
' Event interface for ADODC control
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Code generated by the TypeLib Browser 4.0.12 (c) 2008 by José Roca
' Date: 13 nov 2008   Time: 17:30:56
' ########################################################################################

'CLASS CDAdodcEvents GUID$("{4C9CB2DC-B0CB-4D2E-B10C-A0A2A0704818}") AS EVENT

'INTERFACE DAdodcEventsImpl GUID$("{67397AA2-7FB1-11D0-B148-00A0C922E820}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD WillMove <200> ( _
'     BYVAL adReason AS LONG _                           ' __in  EventReasonEnum adReason
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum* adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset *pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MoveComplete <201> ( _
'     BYVAL adReason AS LONG _                           ' __in adReason EventReasonEnum <enum>
'   , BYVAL pError AS ADOError _                         ' __in *pError Error <dispinterface>
'   , BYREF adStatus AS LONG _                           ' [out] *adStatus EventStatusEnum <enum>
'   , BYVAL pRecordset AS ADORecordset _                 ' __in *pRecordset _Recordset <dispinterface>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD WillChangeField <202> ( _
'     BYVAL cFields AS LONG _                            ' __in  long cFields
'   , BYREF Fields AS VARIANT _                          ' __in  VARIANT* Fields
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum* adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset *pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FieldChangeComplete <203> ( _
'     BYVAL cFields AS LONG _                            ' __in  long cFields
'   , BYREF Fields AS VARIANT _                          ' __in  VARIANT *Fields
'   , BYVAL pError AS ADOError _                         ' __in  Error *pError
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum* adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset *pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD WillChangeRecord <204> ( _
'     BYVAL adReason AS LONG _                           ' __in  EventReasonEnum adReason
'   , BYVAL cRecords AS LONG _                           ' __in  long cRecords
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum* adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset *pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecordChangeComplete <205> ( _
'     BYVAL adReason AS LONG _                           ' __in  EventReasonEnum adReason
'   , BYVAL cRecords AS LONG _                           ' __in  long cRecords
'   , BYVAL pError AS ADOError _                         ' __in  Error* pError
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum* adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset *pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD WillChangeRecordset <206> ( _
'     BYVAL adReason AS LONG _                           ' __in  EventReasonEnum adReason
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum *adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset *pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecordsetChangeComplete <207> ( _
'     BYVAL adReason AS LONG _                           ' __in  EventReasonEnum adReason
'   , BYVAL pError AS ADOError _                         ' __in  Error* pError
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum *adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in  _Recordset* pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EndOfRecordset <208> ( _
'     BYREF fMoreData AS INTEGER _                       ' __in  VARIANT_BOOL* fMoreData
'   , BYREF adStatus AS LONG _                           ' __out EventStatusEnum *adStatus
'   , BYVAL pRecordset AS ADORecordset _                 ' __in _Recordset* pRecordset
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Error <211> ( _
'     BYVAL ErrorNumber AS LONG _                        ' __in long ErrorNumber
'   , BYREF Description AS WSTRING _                     ' __in BSTR* Description
'   , BYVAL Scode AS LONG _                              ' __in long Scode
'   , BYVAL bstrSource AS WSTRING _                      ' __in BSTR Source
'   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
'   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
'   , BYREF fCancelDisplay AS INTEGER _                  ' __in VARIANT_BOOL *fCancelDisplay
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
