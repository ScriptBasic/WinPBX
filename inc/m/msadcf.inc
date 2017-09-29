' ########################################################################################
' Microsoft Windows
' File: msadcf.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: RDSServer
' Version: 1.5, Locale ID = 0
' Documentation string: Microsoft Remote Data Services Server 2.7 Library
' Path: C:\Archivos de programa\Archivos comunes\System\msadc\msadcf.dll
' Library GUID: {9381D8F6-0288-11D0-9501-00AA00B911A5}
' Help file: C:\Archivos de programa\Archivos comunes\System\msadc\ado210.chm
' ########################################################################################

#INCLUDE THIS ONCE
%MSADCF_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {9381D8F5-0288-11D0-9501-00AA00B911A5}
$PROGID_RDSServer_DataFactory281 = "RDSServer.DataFactory.2.81"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {9381D8F5-0288-11D0-9501-00AA00B911A5}
$PROGID_RDSServer_DataFactory = "RDSServer.DataFactory"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_RDSServer_DataFactory = GUID$("{9381D8F5-0288-11D0-9501-00AA00B911A5}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_RDSServer_DIDataFactory  = GUID$("{0EAC4843-8763-11CF-A743-00AA00A3F00D}")
$IID_RDSServer_DIDataFactory2 = GUID$("{070669EC-B52F-11D1-9270-00C04FBBBFB3}")
$IID_RDSServer_DIDataFactory3 = GUID$("{4639DB2B-BFC5-11D2-9318-00C04FBBBFB3}")
$IID_RDSServer_IDataFactory   = GUID$("{0EAC4842-8763-11CF-A743-00AA00A3F00D}")
$IID_RDSServer_IDataFactory2  = GUID$("{070669EB-B52F-11D1-9270-00C04FBBBFB3}")
$IID_RDSServer_IDataFactory3  = GUID$("{4639DB2A-BFC5-11D2-9318-00C04FBBBFB3}")

' ########################################################################################
' Interface name = IDataFactory
' IID = {0EAC4842-8763-11CF-A743-00AA00A3F00D}
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%RDSServer_IDataFactory_INTERFACE_DEFINED)
    %RDSServer_IDataFactory_INTERFACE_DEFINED = 1

INTERFACE RDSServer_IDataFactory $IID_RDSServer_IDataFactory

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 12
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL bstrQuery AS WSTRING _                       ' __in BSTR bstrQuery
   , OPTIONAL BYVAL lMarshalOptions AS LONG _           ' __in_opt long lMarshalOptions [default value = 0]
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecordset
   ' =====================================================================================
   METHOD SubmitChanges ( _                             ' VTable offset = 16
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL pRecordset AS IDispatch _                    ' __in IDispatch *pRecordset
   )                                                    ' void
   ' =====================================================================================
   METHOD ConvertToString ( _                           ' VTable offset = 20
     BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInline
   ' =====================================================================================
   METHOD CreateRecordSet ( _                           ' VTable offset = 24
     BYVAL varColumnInfos AS VARIANT _                  ' __in VARIANT varColumnInfos
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDispatch
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __RDSServer_IDataFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataFactory2
' IID = {070669EB-B52F-11D1-9270-00C04FBBBFB3}
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IDataFactory
' ########################################################################################

#IF NOT %DEF(%RDSServer_IDataFactory2_INTERFACE_DEFINED)
    %RDSServer_IDataFactory2_INTERFACE_DEFINED = 1

INTERFACE RDSServer_IDataFactory2 $IID_RDSServer_IDataFactory2

   INHERIT IAutomation

   ' =====================================================================================
   ' IDataFactory Methods
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 12
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL bstrQuery AS WSTRING _                       ' __in BSTR bstrQuery
   , OPTIONAL BYVAL lMarshalOptions AS LONG _           ' __in_opt long lMarshalOptions [default value = 0]
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecordset
   ' =====================================================================================
   METHOD SubmitChanges ( _                             ' VTable offset = 16
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL pRecordset AS IDispatch _                    ' __in IDispatch *pRecordset
   )                                                    ' void
   ' =====================================================================================
   METHOD ConvertToString ( _                           ' VTable offset = 20
     BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInline
   ' =====================================================================================
   METHOD CreateRecordSet ( _                           ' VTable offset = 24
     BYVAL varColumnInfos AS VARIANT _                  ' __in VARIANT varColumnInfos
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDispatch
   ' =====================================================================================

   ' =====================================================================================
   ' IDataFactory2 Methods
   ' =====================================================================================
   METHOD Execute21 ( _                                 ' VTable offset = 28
     BYVAL ConnectionString AS WSTRING _                ' __in BSTR ConnectionString
   , BYVAL HandlerString AS WSTRING _                   ' __in BSTR HandlerString
   , BYVAL QueryString AS WSTRING _                     ' __in BSTR QueryString
   , BYVAL lMarshalOptions AS LONG _                    ' __in long lMarshalOptions
   , BYVAL Properties AS VARIANT _                      ' __in VARIANT Properties
   , BYVAL TableId AS VARIANT _                         ' __in VARIANT TableId
   , BYVAL lExecuteOptions AS LONG _                    ' __in long lExecuteOptions
   , BYREF pParameters AS VARIANT _                     ' __in_out VARIANT *pParameters
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecordset
   ' =====================================================================================
   METHOD Synchronize21 ( _                             ' VTable offset = 32
     BYVAL ConnectionString AS WSTRING _                ' __in BSTR ConnectionString
   , BYVAL HandlerString AS WSTRING _                   ' __in BSTR HandlerString
   , BYVAL lSynchronizeOptions AS LONG _                ' __in long lSynchronizeOptions
   , BYREF ppRecordset AS IDispatch _                   ' __in_out IDispatch **ppRecordset
   , BYREF pStatusArray AS VARIANT _                    ' __in_out VARIANT *pStatusArray
   ) AS VARIANT                                         ' __retval_out VARIANT *pResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __RDSServer_IDataFactory2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataFactory3
' IID = {4639DB2A-BFC5-11D2-9318-00C04FBBBFB3}
' Definition of interface IDataFactory3
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IDataFactory2
' ########################################################################################

#IF NOT %DEF(%RDSServer_IDataFactory3_INTERFACE_DEFINED)
    %RDSServer_IDataFactory3_INTERFACE_DEFINED = 1

INTERFACE RDSServer_IDataFactory3 $IID_RDSServer_IDataFactory3

   INHERIT IAutomation

   ' =====================================================================================
   ' IDataFactory Methods
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 12
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL bstrQuery AS WSTRING _                       ' __in BSTR bstrQuery
   , OPTIONAL BYVAL lMarshalOptions AS LONG _           ' __in_opt long lMarshalOptions [default value = 0]
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecordset
   ' =====================================================================================
   METHOD SubmitChanges ( _                             ' VTable offset = 16
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL pRecordset AS IDispatch _                    ' __in IDispatch *pRecordset
   )                                                    ' void
   ' =====================================================================================
   METHOD ConvertToString ( _                           ' VTable offset = 20
     BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInline
   ' =====================================================================================
   METHOD CreateRecordSet ( _                           ' VTable offset = 24
     BYVAL varColumnInfos AS VARIANT _                  ' __in VARIANT varColumnInfos
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDispatch
   ' =====================================================================================

   ' =====================================================================================
   ' IDataFactory2 Methods
   ' =====================================================================================
   METHOD Execute21 ( _                                 ' VTable offset = 28
     BYVAL ConnectionString AS WSTRING _                ' __in BSTR ConnectionString
   , BYVAL HandlerString AS WSTRING _                   ' __in BSTR HandlerString
   , BYVAL QueryString AS WSTRING _                     ' __in BSTR QueryString
   , BYVAL lMarshalOptions AS LONG _                    ' __in long lMarshalOptions
   , BYVAL Properties AS VARIANT _                      ' __in VARIANT Properties
   , BYVAL TableId AS VARIANT _                         ' __in VARIANT TableId
   , BYVAL lExecuteOptions AS LONG _                    ' __in long lExecuteOptions
   , BYREF pParameters AS VARIANT _                     ' __in_out VARIANT *pParameters
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecordset
   ' =====================================================================================
   METHOD Synchronize21 ( _                             ' VTable offset = 32
     BYVAL ConnectionString AS WSTRING _                ' __in BSTR ConnectionString
   , BYVAL HandlerString AS WSTRING _                   ' __in BSTR HandlerString
   , BYVAL lSynchronizeOptions AS LONG _                ' __in long lSynchronizeOptions
   , BYREF ppRecordset AS IDispatch _                   ' __in_out IDispatch **ppRecordset
   , BYREF pStatusArray AS VARIANT _                    ' __in_out VARIANT *pStatusArray
   ) AS VARIANT                                         ' __retval_out VARIANT *pResult
   ' =====================================================================================

   ' =====================================================================================
   ' IDataFactory3 Methods
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 36
     BYVAL ConnectionString AS WSTRING _                ' __in BSTR ConnectionString
   , BYVAL HandlerString AS WSTRING _                   ' __in BSTR HandlerString
   , BYVAL QueryString AS WSTRING _                     ' __in BSTR QueryString
   , BYVAL lMarshalOptions AS LONG _                    ' __in long lMarshalOptions
   , BYVAL Properties AS VARIANT _                      ' __in VARIANT Properties
   , BYVAL TableId AS VARIANT _                         ' __in VARIANT TableId
   , BYVAL lExecuteOptions AS LONG _                    ' __in long lExecuteOptions
   , BYREF pParameters AS VARIANT _                     ' __in_out VARIANT *pParameters
   , OPTIONAL BYVAL lcid AS LONG _                      ' __in_opt long lcid
   , OPTIONAL BYREF pInformation AS VARIANT _           ' __in_out_opt VARIANT *pInformation
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecordset
   ' =====================================================================================
   METHOD Synchronize ( _                               ' VTable offset = 40
     BYVAL ConnectionString AS WSTRING _                ' __in BSTR ConnectionString
   , BYVAL HandlerString AS WSTRING _                   ' __in BSTR HandlerString
   , BYVAL lSynchronizeOptions AS LONG _                ' __in long lSynchronizeOptions
   , BYREF ppRecordset AS IDispatch _                   ' __in_out IDispatch **ppRecordset
   , BYREF pStatusArray AS VARIANT _                    ' __in_out VARIANT *pStatusArray
   , OPTIONAL BYVAL lcid AS LONG _                      ' __in_opt long lcid
   , OPTIONAL BYREF pInformation AS VARIANT _           ' __in_out_opt VARIANT *pInformation
   ) AS VARIANT                                         ' __retval_out VARIANT *pResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __RDSServer_IDataFactory3_INTERFACE_DEFINED__ */
