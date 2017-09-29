' ########################################################################################
' Microsoft Windows
' File: msadco.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: RDS
' Version: 1.5
' Documentation string: Microsoft Remote Data Services 2.7 Library
' ########################################################################################

#INCLUDE THIS ONCE
%MSADCO_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {BD96C556-65A3-11D0-983A-00C04FC29E33}
$PROGID_RDSDataControl281 = "RDS.DataControl.2.81"
' CLSID = {BD96C556-65A3-11D0-983A-00C04FC29E36}
$PROGID_RDSDataSpace281 = "RDS.DataSpace.2.81"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {BD96C556-65A3-11D0-983A-00C04FC29E33}
$PROGID_RDSDataControl = "RDS.DataControl"
' CLSID = {BD96C556-65A3-11D0-983A-00C04FC29E36}
$PROGID_RDSDataSpace = "RDS.DataSpace"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_RDSDataControl = GUID$("{BD96C556-65A3-11D0-983A-00C04FC29E33}")
$CLSID_RDSDataSpace   = GUID$("{BD96C556-65A3-11D0-983A-00C04FC29E36}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_RDS_IADCEvents   = GUID$("{24785B20-135E-11D1-A2A7-00A0C9082766}")
$IID_RDS_IBindMgr     = GUID$("{49278A16-7447-11D2-ACCB-0000F87A37D8}")
$IID_RDS_IBindMgr21   = GUID$("{BD96C556-65A3-11D0-983A-00C04FC29E31}")
$IID_RDS_IDataspace   = GUID$("{BD96C556-65A3-11D0-983A-00C04FC29E34}")

' ========================================================================================
' ADCExecuteOptionEnum enum
' ========================================================================================

%adcExecSync                                            = 1
%adcExecAsync                                           = 2

' ========================================================================================
' ADCFetchOptionEnum enum
' ========================================================================================

%adcFetchUpFront                                        = 1
%adcFetchBackground                                     = 2
%adcFetchAsync                                          = 3

' ========================================================================================
' ADCReadyStateEnum enum
' ========================================================================================

%adcReadyStateLoaded                                    = 2
%adcReadyStateInteractive                               = 3
%adcReadyStateComplete                                  = 4


' ########################################################################################
' Interface name = IBindMgr21
' IID = {BD96C556-65A3-11D0-983A-00C04FC29E31}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE RDS_IBindMgr21 $IID_RDS_IBindMgr21

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SQL <0> ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrQuery
   ' =====================================================================================
   PROPERTY SET SQL <0> ( _                             ' VTable offset = 32
     BYVAL pbstrQuery AS WSTRING _                      ' __in BSTR pbstrQuery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Server <1> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrServer
   ' =====================================================================================
   PROPERTY SET Server <1> ( _                          ' VTable offset = 40
     BYVAL pbstrServer AS WSTRING _                     ' __in BSTR pbstrServer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSpace <144> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDs
   ' =====================================================================================
   PROPERTY SET DataSpace <144> ( _                     ' VTable offset = 48
     BYVAL pbstrDs AS WSTRING _                         ' __in BSTR pbstrDs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SourceRecordset <146> ( _               ' VTable offset = 52
     BYVAL rhs AS IDispatch _                           ' __in IDispatch* rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_SourceRecordset <146> ( _        ' VTable offset = 56
     BYVAL rhs AS IDispatch _                           ' __in IDispatch* rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Recordset <149> ( _                     ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch** pdispRecordset
   ' =====================================================================================
   PROPERTY GET Connect <148> ( _                       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrConnect
   ' =====================================================================================
   PROPERTY SET Connect <148> ( _                       ' VTable offset = 68
     BYVAL pbstrConnect AS WSTRING _                    ' __in BSTR pbstrConnect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecuteOptions <18> ( _                 ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short* pshExecuteOptions
   ' =====================================================================================
   PROPERTY SET ExecuteOptions <18> ( _                 ' VTable offset = 76
     BYVAL pshExecuteOptions AS INTEGER _               ' __in short pshExecuteOptions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FetchOptions <20> ( _                   ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short* pshFetchOptions
   ' =====================================================================================
   PROPERTY SET FetchOptions <20> ( _                   ' VTable offset = 84
     BYVAL pshFetchOptions AS INTEGER _                 ' __in short pshFetchOptions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long* plState
   ' =====================================================================================
   PROPERTY GET SortColumn <11> ( _                     ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSortColumn
   ' =====================================================================================
   PROPERTY SET SortColumn <11> ( _                     ' VTable offset = 96
     BYVAL pbstrSortColumn AS WSTRING _                 ' __in BSTR pbstrSortColumn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SortDirection <12> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfSortAscending
   ' =====================================================================================
   PROPERTY SET SortDirection <12> ( _                  ' VTable offset = 104
     BYVAL pfSortAscending AS INTEGER _                 ' __in VARIANT_BOOL pfSortAscending
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterValue <15> ( _                    ' VTable offset = 108
   ) AS WSTRING                                          ' __retval_out BSTR* pbstrFilterValue
   ' =====================================================================================
   PROPERTY SET FilterValue <15> ( _                    ' VTable offset = 112
     BYVAL pbstrFilterValue AS WSTRING _                ' __in BSTR pbstrFilterValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterCriterion <14> ( _                ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterCriterion
   ' =====================================================================================
   PROPERTY SET FilterCriterion <14> ( _                ' VTable offset = 120
     BYVAL pbstrFilterCriterion AS WSTRING _            ' __in BSTR pbstrFilterCriterion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterColumn <13> ( _                   ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterColumn
   ' =====================================================================================
   PROPERTY SET FilterColumn <13> ( _                   ' VTable offset = 128
     BYVAL pbstrFilterColumn AS WSTRING _               ' __in BSTR pbstrFilterColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <6> ( _                               ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD SubmitChanges <7> ( _                         ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <8> ( _                          ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateRecordSet <10> ( _                      ' VTable offset = 144
     BYVAL varColumnInfos AS VARIANT _                  ' __in VARIANT varColumnInfos
   ) AS IDispatch                                       ' __retval_out IDispatch** ppRecordSet
   ' =====================================================================================
   METHOD Reset <16> ( _                                ' VTable offset = 148
     OPTIONAL BYVAL fRefilter AS LONG _                 ' __in_opt long fRefilter [defaultvalue = 1]
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <17> ( _                               ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Handler <21> ( _                        ' VTable offset = 156
   ) AS WSTRING                                          ' __retval_out BSTR* pbstrHandler
   ' =====================================================================================
   PROPERTY SET Handler <21> ( _                        ' VTable offset = 160
     BYVAL pbstrHandler AS WSTRING _                    ' __in BSTR pbstrHandler
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InternetTimeout <22> ( _                ' VTable offset = 164
   ) AS LONG                                            ' __retval_out long* plInetTimeout
   ' =====================================================================================
   PROPERTY SET InternetTimeout <22> ( _                ' VTable offset = 168
     BYVAL plInetTimeout AS LONG _                      ' __in long plInetTimeout
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IBindMgr
' IID = {49278A16-7447-11D2-ACCB-0000F87A37D8}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IBindMgr21
' ########################################################################################

INTERFACE RDS_IBindMgr $IID_RDS_IBindMgr

   INHERIT IDispatch

   ' =====================================================================================
   ' IBindMgr21 Methods
   ' =====================================================================================
   PROPERTY GET SQL <0> ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrQuery
   ' =====================================================================================
   PROPERTY SET SQL <0> ( _                             ' VTable offset = 32
     BYVAL pbstrQuery AS WSTRING _                      ' __in BSTR pbstrQuery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Server <1> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrServer
   ' =====================================================================================
   PROPERTY SET Server <1> ( _                          ' VTable offset = 40
     BYVAL pbstrServer AS WSTRING _                     ' __in BSTR pbstrServer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSpace <144> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDs
   ' =====================================================================================
   PROPERTY SET DataSpace <144> ( _                     ' VTable offset = 48
     BYVAL pbstrDs AS WSTRING _                         ' __in BSTR pbstrDs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SourceRecordset <146> ( _               ' VTable offset = 52
     BYVAL rhs AS IDispatch _                           ' __in IDispatch* rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_SourceRecordset <146> ( _        ' VTable offset = 56
     BYVAL rhs AS IDispatch _                           ' __in IDispatch* rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Recordset <149> ( _                     ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch** pdispRecordset
   ' =====================================================================================
   PROPERTY GET Connect <148> ( _                       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrConnect
   ' =====================================================================================
   PROPERTY SET Connect <148> ( _                       ' VTable offset = 68
     BYVAL pbstrConnect AS WSTRING _                    ' __in BSTR pbstrConnect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecuteOptions <18> ( _                 ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short* pshExecuteOptions
   ' =====================================================================================
   PROPERTY SET ExecuteOptions <18> ( _                 ' VTable offset = 76
     BYVAL pshExecuteOptions AS INTEGER _               ' __in short pshExecuteOptions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FetchOptions <20> ( _                   ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short* pshFetchOptions
   ' =====================================================================================
   PROPERTY SET FetchOptions <20> ( _                   ' VTable offset = 84
     BYVAL pshFetchOptions AS INTEGER _                 ' __in short pshFetchOptions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long* plState
   ' =====================================================================================
   PROPERTY GET SortColumn <11> ( _                     ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSortColumn
   ' =====================================================================================
   PROPERTY SET SortColumn <11> ( _                     ' VTable offset = 96
     BYVAL pbstrSortColumn AS WSTRING _                 ' __in BSTR pbstrSortColumn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SortDirection <12> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfSortAscending
   ' =====================================================================================
   PROPERTY SET SortDirection <12> ( _                  ' VTable offset = 104
     BYVAL pfSortAscending AS INTEGER _                 ' __in VARIANT_BOOL pfSortAscending
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterValue <15> ( _                    ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterValue
   ' =====================================================================================
   PROPERTY SET FilterValue <15> ( _                    ' VTable offset = 112
     BYVAL pbstrFilterValue AS WSTRING _                ' __in BSTR pbstrFilterValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterCriterion <14> ( _                ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterCriterion
   ' =====================================================================================
   PROPERTY SET FilterCriterion <14> ( _                ' VTable offset = 120
     BYVAL pbstrFilterCriterion AS WSTRING _            ' __in BSTR pbstrFilterCriterion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterColumn <13> ( _                   ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterColumn
   ' =====================================================================================
   PROPERTY SET FilterColumn <13> ( _                   ' VTable offset = 128
     BYVAL pbstrFilterColumn AS WSTRING _               ' __in BSTR pbstrFilterColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <6> ( _                               ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD SubmitChanges <7> ( _                         ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <8> ( _                          ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateRecordSet <10> ( _                      ' VTable offset = 144
     BYVAL varColumnInfos AS VARIANT _                  ' __in VARIANT varColumnInfos
   ) AS IDispatch                                       ' __retval_out IDispatch** ppRecordSet
   ' =====================================================================================
   METHOD Reset <16> ( _                                ' VTable offset = 148
     OPTIONAL BYVAL fRefilter AS LONG _                 ' __in_opt long fRefilter [defaultvalue = 1]
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <17> ( _                               ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Handler <21> ( _                        ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrHandler
   ' =====================================================================================
   PROPERTY SET Handler <21> ( _                        ' VTable offset = 160
     BYVAL pbstrHandler AS WSTRING _                    ' __in BSTR pbstrHandler
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InternetTimeout <22> ( _                ' VTable offset = 164
   ) AS LONG                                            ' __retval_out long* plInetTimeout
   ' =====================================================================================
   PROPERTY SET InternetTimeout <22> ( _                ' VTable offset = 168
     BYVAL plInetTimeout AS LONG _                      ' __in long plInetTimeout
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IBindMgr Methods
   ' =====================================================================================
   PROPERTY GET URL <23> ( _                            ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <23> ( _                            ' VTable offset = 176
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IDataspace
' IID = {BD96C556-65A3-11D0-983A-00C04FC29E34}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE RDS_IDataspace $IID_RDS_IDataspace

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateObject <1> ( _                          ' VTable offset = 28
     BYVAL bstrProgid AS WSTRING _                      ' __in BSTR bstrProgid
   , BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarResult
   ' =====================================================================================
   PROPERTY GET InternetTimeout <222> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* plInetTimeout
   ' =====================================================================================
   PROPERTY SET InternetTimeout <222> ( _               ' VTable offset = 36
     BYVAL plInetTimeout AS LONG _                      ' __in long plInetTimeout
   )                                                    ' void
   ' =====================================================================================

END INTERFACE
