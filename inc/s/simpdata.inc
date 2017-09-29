' ########################################################################################
' Microsoft Windows
' File: simpdata.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSDAOSP
' Version: 1.5
' Documentation string: Microsoft OLE DB Simple Provider 1.5 Library
' Type library: simpdata.tlb
' Library GUID: {E0E270C2-C0BE-11D0-8FE4-00A0C90A6341}
' ########################################################################################

#INCLUDE THIS ONCE
%SIMPDATA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$LIBID_MSDAOSP = GUID$("{E0E270C2-C0BE-11D0-8FE4-00A0C90A6341}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_OLEDBSimpleProvider = GUID$("{E0E270C0-C0BE-11D0-8FE4-00A0C90A6341}")
$IID_OLEDBSimpleProviderListener = GUID$("{E0E270C1-C0BE-11D0-8FE4-00A0C90A6341}")

'#ifdef _WIN64
'typedef LONGLONG      DBROWCOUNT;
'typedef LONGLONG      DB_LORDINAL;
'#else
'typedef LONG DBROWCOUNT;
'typedef LONG DB_LORDINAL;
'#endif   // _WIN64

'#define OSP_IndexLabel      (0)
'#define OSP_IndexAll        (~0)
'#define OSP_IndexUnknown    (~0)

%OSP_IndexLabel      = 0
%OSP_IndexAll        = NOT 0
%OSP_IndexUnknown    = NOT 0

' ========================================================================================
' OSPFORMAT enum
' ========================================================================================

%OSPFORMAT_RAW       = 0
%OSPFORMAT_DEFAULT   = 0
%OSPFORMAT_FORMATTED = 1
%OSPFORMAT_HTML      = 2

' ========================================================================================
' OSPRW enum
' ========================================================================================

%OSPRW_DEFAULT   = 1
%OSPRW_READONLY  = 0
%OSPRW_READWRITE = 1
%OSPRW_MIXED     = 2

' ========================================================================================
' OSPFIND enum
' ========================================================================================

%OSPFIND_DEFAULT         = 0
%OSPFIND_UP              = 1
%OSPFIND_CASESENSITIVE   = 2
%OSPFIND_UPCASESENSITIVE = 3

' ========================================================================================
' OSPCOMP enum
' ========================================================================================

%OSPCOMP_EQ      = 1
%OSPCOMP_DEFAULT = 1
%OSPCOMP_LT      = 2
%OSPCOMP_LE      = 3
%OSPCOMP_GE      = 4
%OSPCOMP_GT      = 5
%OSPCOMP_NE      = 6

' ========================================================================================
' OSPXFER enum
' ========================================================================================

%OSPXFER_COMPLETE = 0
%OSPXFER_ABORT    = 1
%OSPXFER_ERROR    = 2


' ########################################################################################
' Interface name = OLEDBSimpleProviderListener
' IID = {E0E270C1-C0BE-11D0-8FE4-00A0C90A6341}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%OLEDBSimpleProviderListener_INTERFACE_DEFINED)
    %OLEDBSimpleProviderListener_INTERFACE_DEFINED = 1

INTERFACE OLEDBSimpleProviderListener $IID_OLEDBSimpleProviderListener

   INHERIT IAutomation

   ' =====================================================================================
   METHOD aboutToChangeCell ( _                         ' VTable offset = 12
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL iColumn AS LONG _                            ' __in DB_LORDINAL iColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD cellChanged ( _                               ' VTable offset = 16
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL iColumn AS LONG _                            ' __in DB_LORDINAL iColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD aboutToDeleteRows ( _                         ' VTable offset = 20
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   )                                                    ' void
   ' =====================================================================================
   METHOD deletedRows ( _                               ' VTable offset = 24
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   )                                                    ' void
   ' =====================================================================================
   METHOD aboutToInsertRows ( _                         ' VTable offset = 28
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   )                                                    ' void
   ' =====================================================================================
   METHOD insertedRows ( _                              ' VTable offset = 32
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   )                                                    ' void
   ' =====================================================================================
   METHOD rowsAvailable ( _                             ' VTable offset = 36
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   )                                                    ' void
   ' =====================================================================================
   METHOD transferComplete ( _                          ' VTable offset = 40
     BYVAL xfer AS LONG _                               ' __in OSPXFER xfer
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __OLEDBSimpleProviderListener_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = OLEDBSimpleProvider
' IID = {E0E270C0-C0BE-11D0-8FE4-00A0C90A6341}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%OLEDBSimpleProvider_INTERFACE_DEFINED)
    %OLEDBSimpleProvider_INTERFACE_DEFINED = 1

INTERFACE OLEDBSimpleProvider $IID_OLEDBSimpleProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD getRowCount ( _                               ' VTable offset = 12
   ) AS LONG                                            ' __retval_out DBROWCOUNT *pcRowsHRESULT
   ' =====================================================================================
   METHOD getColumnCount ( _                            ' VTable offset = 16
   ) AS LONG                                            ' __retval_out DB_LORDINAL *pcColumns
   ' =====================================================================================
   METHOD getRWStatus ( _                               ' VTable offset = 20
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL iColumn AS LONG _                            ' __in DB_LORDINAL iColumn
   ) AS LONG                                            ' __retval_out OSPRW *prwStatus
   ' =====================================================================================
   METHOD getVariant ( _                                ' VTable offset = 24
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL iColumn AS LONG _                            ' __in DB_LORDINAL iColumn
   , BYVAL format AS LONG _                             ' __in OSPFORMAT format
   ) AS VARIANT                                         ' __retval_out VARIANT *pVar
   ' =====================================================================================
   METHOD setVariant ( _                                ' VTable offset = 28
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL iColumn AS LONG _                            ' __in DB_LORDINAL iColumn
   , BYVAL format AS LONG _                             ' __in OSPFORMAT format
   , BYVAL Var AS VARIANT _                             ' __in VARIANT Var
   )                                                    ' void
   ' =====================================================================================
   METHOD getLocale ( _                                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLocale
   ' =====================================================================================
   METHOD deleteRows ( _                                ' VTable offset = 36
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   ) AS LONG                                            ' __retval_out DBROWCOUNT *pcRowsDeleted
   ' =====================================================================================
   METHOD insertRows ( _                                ' VTable offset = 40
     BYVAL iRow AS LONG _                               ' __in DBROWCOUNT iRow
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   ) AS LONG                                            ' __retval_out DBROWCOUNT *pcRowsInserted
   ' =====================================================================================
   METHOD find ( _                                      ' VTable offset = 44
     BYVAL iRowStart AS LONG _                          ' __in DBROWCOUNT iRowStart
   , BYVAL iColumn AS LONG _                            ' __in DB_LORDINAL iColumn
   , BYVAL val AS VARIANT _                             ' __in VARIANT val
   , BYVAL findFlags AS LONG _                          ' __in OSPFIND findFlags
   , BYVAL compType AS LONG _                           ' __in OSPCOMP compType
   ) AS LONG                                            ' __retval_out DBROWCOUNT *piRowFound
   ' =====================================================================================
   METHOD addOLEDBSimpleProviderListener ( _            ' VTable offset = 48
     BYVAL pospIListener AS OLEDBSimpleProviderListener _ ' __in OLEDBSimpleProviderListener *pospIListener
   )                                                    ' void
   ' =====================================================================================
   METHOD removeOLEDBSimpleProviderListener ( _         ' VTable offset = 52
     BYVAL pospIListener AS OLEDBSimpleProviderListener _ ' __in OLEDBSimpleProviderListener *pospIListener
   )                                                    ' void
   ' =====================================================================================
   METHOD isAsync ( _                                   ' VTable offset = 56
   ) AS LONG                                            ' __retval_out BOOL *pbAsynch
   ' =====================================================================================
   METHOD getEstimatedRows ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DBROWCOUNT *piRows
   ' =====================================================================================
   METHOD stopTransfer ( _                              ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __OLEDBSimpleProvider_INTERFACE_DEFINED__ */
