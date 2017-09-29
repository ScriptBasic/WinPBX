' ########################################################################################
' Microsoft Windows
' File: LogParser.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSUtil
' Version: 1.0
' Documentation string: MS Utility 1.0 Type Library - LogParser Interfaces collection
' Path: C:\Archivos de programa\Log Parser 2.2\LogParser.dll\1
' Library GUID: {A7E75D86-41CD-4B6E-B4BD-CC2ED34B3FB0}
' ########################################################################################

#INCLUDE THIS ONCE
%LOGPARSER_INC = 1

#INCLUDE ONCE "oaidl.inc"   ' For IEnumVARIANT interface

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {8CFEBA94-3FC2-45CA-B9A5-9EDACF704F66}
$PROGID_MSUtilLogQuery1 = "MSUtil.LogQuery.1"
' CLSID = {F2455538-58A0-45FF-B16C-5F5DBA8D811C}
$PROGID_MSUtilLogQueryADSInputFormat1 = "MSUtil.LogQuery.ADSInputFormat.1"
' CLSID = {2C4C2DB5-61C5-4D45-A66F-2071EC069328}
$PROGID_MSUtilLogQueryChartOutputFormat1 = "MSUtil.LogQuery.ChartOutputFormat.1"
' CLSID = {4A1AAA95-FD08-449B-BD16-E87083D8F087}
$PROGID_MSUtilLogQueryCSVInputFormat1 = "MSUtil.LogQuery.CSVInputFormat.1"
' CLSID = {80C997CD-A676-4028-8860-BB5F2F8278F6}
$PROGID_MSUtilLogQueryCSVOutputFormat1 = "MSUtil.LogQuery.CSVOutputFormat.1"
' CLSID = {8F054D20-354E-4A4D-92E4-10CDBA47D848}
$PROGID_MSUtilLogQueryDataGridOutputFormat1 = "MSUtil.LogQuery.DataGridOutputFormat.1"
' CLSID = {3B942793-EEB0-41B8-BF12-4CD3EDDC9205}
$PROGID_MSUtilLogQueryETWInputFormat1 = "MSUtil.LogQuery.ETWInputFormat.1"
' CLSID = {9BE3E5B2-BBC3-40BB-AAFE-C94DDA631D32}
$PROGID_MSUtilLogQueryEventLogInputFormat1 = "MSUtil.LogQuery.EventLogInputFormat.1"
' CLSID = {BA8BAB06-715C-49F5-A94F-3E70B1CE38C6}
$PROGID_MSUtilLogQueryFileSystemInputFormat1 = "MSUtil.LogQuery.FileSystemInputFormat.1"
' CLSID = {F6751CB0-4CE6-4033-A489-5CC2D8C9D716}
$PROGID_MSUtilLogQueryHttpErrorInputFormat1 = "MSUtil.LogQuery.HttpErrorInputFormat.1"
' CLSID = {A5BFDB31-5D80-4496-AF9C-79549E2F7BEC}
$PROGID_MSUtilLogQueryIISBINInputFormat1 = "MSUtil.LogQuery.IISBINInputFormat.1"
' CLSID = {252A24E7-067F-4875-8510-7533F8B6915E}
$PROGID_MSUtilLogQueryIISIISInputFormat1 = "MSUtil.LogQuery.IISIISInputFormat.1"
' CLSID = {4E1AD8B6-39B6-4802-90EF-B5D86774D815}
$PROGID_MSUtilLogQueryIISIISMSIDInputFormat1 = "MSUtil.LogQuery.IISIISMSIDInputFormat.1"
' CLSID = {C13EDD32-5280-4F40-B002-A21F05219371}
$PROGID_MSUtilLogQueryIISNCSAInputFormat1 = "MSUtil.LogQuery.IISNCSAInputFormat.1"
' CLSID = {B331653F-522E-4FBD-BEA2-D47ED26DA8CC}
$PROGID_MSUtilLogQueryIISODBCInputFormat1 = "MSUtil.LogQuery.IISODBCInputFormat.1"
' CLSID = {88937009-2404-483D-B6A7-49AA184426B9}
$PROGID_MSUtilLogQueryIISOutputFormat1 = "MSUtil.LogQuery.IISOutputFormat.1"
' CLSID = {6120A3D1-AD55-41F9-ADB0-7266E2623364}
$PROGID_MSUtilLogQueryIISW3CInputFormat1 = "MSUtil.LogQuery.IISW3CInputFormat.1"
' CLSID = {DEA6399C-EA9F-4864-BABB-0F6720A92CE1}
$PROGID_MSUtilLogQueryNativeOutputFormat1 = "MSUtil.LogQuery.NativeOutputFormat.1"
' CLSID = {0173E9B3-19C1-4A25-995B-4B19EBD68025}
$PROGID_MSUtilLogQueryNetMonInputFormat1 = "MSUtil.LogQuery.NetMonInputFormat.1"
' CLSID = {C17BDE3A-CDBD-45E0-9BCF-FD286A344EE8}
$PROGID_MSUtilLogQueryRegistryInputFormat1 = "MSUtil.LogQuery.RegistryInputFormat.1"
' CLSID = {0FFF4843-4EAD-447C-8AA4-2D3BF639F5FC}
$PROGID_MSUtilLogQuerySQLOutputFormat1 = "MSUtil.LogQuery.SQLOutputFormat.1"
' CLSID = {342148B3-7F11-4F39-A287-6829F83FABDA}
$PROGID_MSUtilLogQuerySYSLOGOutputFormat1 = "MSUtil.LogQuery.SYSLOGOutputFormat.1"
' CLSID = {8235D6A5-AAFD-4D39-BFE8-EF1641AB9257}
$PROGID_MSUtilLogQueryTemplateOutputFormat1 = "MSUtil.LogQuery.TemplateOutputFormat.1"
' CLSID = {E17FE5B0-C2BC-4C97-8EBF-8EF2F763FCA8}
$PROGID_MSUtilLogQueryTextLineInputFormat1 = "MSUtil.LogQuery.TextLineInputFormat.1"
' CLSID = {0A402C88-0CEB-42C6-A15B-32AA45052706}
$PROGID_MSUtilLogQueryTextWordInputFormat1 = "MSUtil.LogQuery.TextWordInputFormat.1"
' CLSID = {FFB760AB-4ACA-4070-99D5-194D9272B47D}
$PROGID_MSUtilLogQueryTSVInputFormat1 = "MSUtil.LogQuery.TSVInputFormat.1"
' CLSID = {38E8C317-D7A1-49EE-8437-8DFE91462B1E}
$PROGID_MSUtilLogQueryTSVOutputFormat1 = "MSUtil.LogQuery.TSVOutputFormat.1"
' CLSID = {9A6E2BE0-96E4-4985-87AF-BDC668EA15A5}
$PROGID_MSUtilLogQueryURLScanLogInputFormat1 = "MSUtil.LogQuery.URLScanLogInputFormat.1"
' CLSID = {3ED0372B-4117-4CA3-A638-EF9BF3720248}
$PROGID_MSUtilLogQueryW3CInputFormat1 = "MSUtil.LogQuery.W3CInputFormat.1"
' CLSID = {DC691F49-FD32-4E17-8C5F-F7C31F46FDF5}
$PROGID_MSUtilLogQueryW3COutputFormat1 = "MSUtil.LogQuery.W3COutputFormat.1"
' CLSID = {0776E95A-34E3-4488-886E-094BA16BB6BD}
$PROGID_MSUtilLogQueryXMLInputFormat1 = "MSUtil.LogQuery.XMLInputFormat.1"
' CLSID = {29467682-1CFC-46EA-B64D-EB31A56B321D}
$PROGID_MSUtilLogQueryXMLOutputFormat1 = "MSUtil.LogQuery.XMLOutputFormat.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {8CFEBA94-3FC2-45CA-B9A5-9EDACF704F66}
$PROGID_MSUtilLogQuery = "MSUtil.LogQuery"
' CLSID = {F2455538-58A0-45FF-B16C-5F5DBA8D811C}
$PROGID_MSUtilLogQueryADSInputFormat = "MSUtil.LogQuery.ADSInputFormat"
' CLSID = {2C4C2DB5-61C5-4D45-A66F-2071EC069328}
$PROGID_MSUtilLogQueryChartOutputFormat = "MSUtil.LogQuery.ChartOutputFormat"
' CLSID = {4A1AAA95-FD08-449B-BD16-E87083D8F087}
$PROGID_MSUtilLogQueryCSVInputFormat = "MSUtil.LogQuery.CSVInputFormat"
' CLSID = {80C997CD-A676-4028-8860-BB5F2F8278F6}
$PROGID_MSUtilLogQueryCSVOutputFormat = "MSUtil.LogQuery.CSVOutputFormat"
' CLSID = {8F054D20-354E-4A4D-92E4-10CDBA47D848}
$PROGID_MSUtilLogQueryDataGridOutputFormat = "MSUtil.LogQuery.DataGridOutputFormat"
' CLSID = {3B942793-EEB0-41B8-BF12-4CD3EDDC9205}
$PROGID_MSUtilLogQueryETWInputFormat = "MSUtil.LogQuery.ETWInputFormat"
' CLSID = {9BE3E5B2-BBC3-40BB-AAFE-C94DDA631D32}
$PROGID_MSUtilLogQueryEventLogInputFormat = "MSUtil.LogQuery.EventLogInputFormat"
' CLSID = {BA8BAB06-715C-49F5-A94F-3E70B1CE38C6}
$PROGID_MSUtilLogQueryFileSystemInputFormat = "MSUtil.LogQuery.FileSystemInputFormat"
' CLSID = {F6751CB0-4CE6-4033-A489-5CC2D8C9D716}
$PROGID_MSUtilLogQueryHttpErrorInputFormat = "MSUtil.LogQuery.HttpErrorInputFormat"
' CLSID = {A5BFDB31-5D80-4496-AF9C-79549E2F7BEC}
$PROGID_MSUtilLogQueryIISBINInputFormat = "MSUtil.LogQuery.IISBINInputFormat"
' CLSID = {252A24E7-067F-4875-8510-7533F8B6915E}
$PROGID_MSUtilLogQueryIISIISInputFormat = "MSUtil.LogQuery.IISIISInputFormat"
' CLSID = {4E1AD8B6-39B6-4802-90EF-B5D86774D815}
$PROGID_MSUtilLogQueryIISIISMSIDInputFormat = "MSUtil.LogQuery.IISIISMSIDInputFormat"
' CLSID = {C13EDD32-5280-4F40-B002-A21F05219371}
$PROGID_MSUtilLogQueryIISNCSAInputFormat = "MSUtil.LogQuery.IISNCSAInputFormat"
' CLSID = {B331653F-522E-4FBD-BEA2-D47ED26DA8CC}
$PROGID_MSUtilLogQueryIISODBCInputFormat = "MSUtil.LogQuery.IISODBCInputFormat"
' CLSID = {88937009-2404-483D-B6A7-49AA184426B9}
$PROGID_MSUtilLogQueryIISOutputFormat = "MSUtil.LogQuery.IISOutputFormat"
' CLSID = {6120A3D1-AD55-41F9-ADB0-7266E2623364}
$PROGID_MSUtilLogQueryIISW3CInputFormat = "MSUtil.LogQuery.IISW3CInputFormat"
' CLSID = {DEA6399C-EA9F-4864-BABB-0F6720A92CE1}
$PROGID_MSUtilLogQueryNativeOutputFormat = "MSUtil.LogQuery.NativeOutputFormat"
' CLSID = {0173E9B3-19C1-4A25-995B-4B19EBD68025}
$PROGID_MSUtilLogQueryNetMonInputFormat = "MSUtil.LogQuery.NetMonInputFormat"
' CLSID = {C17BDE3A-CDBD-45E0-9BCF-FD286A344EE8}
$PROGID_MSUtilLogQueryRegistryInputFormat = "MSUtil.LogQuery.RegistryInputFormat"
' CLSID = {0FFF4843-4EAD-447C-8AA4-2D3BF639F5FC}
$PROGID_MSUtilLogQuerySQLOutputFormat = "MSUtil.LogQuery.SQLOutputFormat"
' CLSID = {342148B3-7F11-4F39-A287-6829F83FABDA}
$PROGID_MSUtilLogQuerySYSLOGOutputFormat = "MSUtil.LogQuery.SYSLOGOutputFormat"
' CLSID = {8235D6A5-AAFD-4D39-BFE8-EF1641AB9257}
$PROGID_MSUtilLogQueryTemplateOutputFormat = "MSUtil.LogQuery.TemplateOutputFormat"
' CLSID = {E17FE5B0-C2BC-4C97-8EBF-8EF2F763FCA8}
$PROGID_MSUtilLogQueryTextLineInputFormat = "MSUtil.LogQuery.TextLineInputFormat"
' CLSID = {0A402C88-0CEB-42C6-A15B-32AA45052706}
$PROGID_MSUtilLogQueryTextWordInputFormat = "MSUtil.LogQuery.TextWordInputFormat"
' CLSID = {FFB760AB-4ACA-4070-99D5-194D9272B47D}
$PROGID_MSUtilLogQueryTSVInputFormat = "MSUtil.LogQuery.TSVInputFormat"
' CLSID = {38E8C317-D7A1-49EE-8437-8DFE91462B1E}
$PROGID_MSUtilLogQueryTSVOutputFormat = "MSUtil.LogQuery.TSVOutputFormat"
' CLSID = {9A6E2BE0-96E4-4985-87AF-BDC668EA15A5}
$PROGID_MSUtilLogQueryURLScanLogInputFormat = "MSUtil.LogQuery.URLScanLogInputFormat"
' CLSID = {3ED0372B-4117-4CA3-A638-EF9BF3720248}
$PROGID_MSUtilLogQueryW3CInputFormat = "MSUtil.LogQuery.W3CInputFormat"
' CLSID = {DC691F49-FD32-4E17-8C5F-F7C31F46FDF5}
$PROGID_MSUtilLogQueryW3COutputFormat = "MSUtil.LogQuery.W3COutputFormat"
' CLSID = {0776E95A-34E3-4488-886E-094BA16BB6BD}
$PROGID_MSUtilLogQueryXMLInputFormat = "MSUtil.LogQuery.XMLInputFormat"
' CLSID = {29467682-1CFC-46EA-B64D-EB31A56B321D}
$PROGID_MSUtilLogQueryXMLOutputFormat = "MSUtil.LogQuery.XMLOutputFormat"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_LogQueryClass = GUID$("{8CFEBA94-3FC2-45CA-B9A5-9EDACF704F66}")
$CLSID_COMADSInputContextClass = GUID$("{F2455538-58A0-45FF-B16C-5F5DBA8D811C}")
$CLSID_COMChartOutputContextClass = GUID$("{2C4C2DB5-61C5-4D45-A66F-2071EC069328}")
$CLSID_COMCSVInputContextClass = GUID$("{4A1AAA95-FD08-449B-BD16-E87083D8F087}")
$CLSID_COMCSVOutputContextClass = GUID$("{80C997CD-A676-4028-8860-BB5F2F8278F6}")
$CLSID_COMDataGridOutputContextClass = GUID$("{8F054D20-354E-4A4D-92E4-10CDBA47D848}")
$CLSID_COMETWInputContextClass = GUID$("{3B942793-EEB0-41B8-BF12-4CD3EDDC9205}")
$CLSID_COMEventLogInputContextClass = GUID$("{9BE3E5B2-BBC3-40BB-AAFE-C94DDA631D32}")
$CLSID_COMFileSystemInputContextClass = GUID$("{BA8BAB06-715C-49F5-A94F-3E70B1CE38C6}")
$CLSID_COMHttpErrorInputContextClass = GUID$("{F6751CB0-4CE6-4033-A489-5CC2D8C9D716}")
$CLSID_COMIISBINInputContextClass = GUID$("{A5BFDB31-5D80-4496-AF9C-79549E2F7BEC}")
$CLSID_COMIISIISInputContextClass = GUID$("{252A24E7-067F-4875-8510-7533F8B6915E}")
$CLSID_COMIISIISMSIDInputContextClass = GUID$("{4E1AD8B6-39B6-4802-90EF-B5D86774D815}")
$CLSID_COMIISNCSAInputContextClass = GUID$("{C13EDD32-5280-4F40-B002-A21F05219371}")
$CLSID_COMIISODBCInputContextClass = GUID$("{B331653F-522E-4FBD-BEA2-D47ED26DA8CC}")
$CLSID_COMIISOutputContextClass = GUID$("{88937009-2404-483D-B6A7-49AA184426B9}")
$CLSID_COMIISW3CInputContextClass = GUID$("{6120A3D1-AD55-41F9-ADB0-7266E2623364}")
$CLSID_COMNativeOutputContextClass = GUID$("{DEA6399C-EA9F-4864-BABB-0F6720A92CE1}")
$CLSID_COMNetMonInputContextClass = GUID$("{0173E9B3-19C1-4A25-995B-4B19EBD68025}")
$CLSID_COMRegistryInputContextClass = GUID$("{C17BDE3A-CDBD-45E0-9BCF-FD286A344EE8}")
$CLSID_COMSQLOutputContextClass = GUID$("{0FFF4843-4EAD-447C-8AA4-2D3BF639F5FC}")
$CLSID_COMSYSLOGOutputContextClass = GUID$("{342148B3-7F11-4F39-A287-6829F83FABDA}")
$CLSID_COMTemplateOutputContextClass = GUID$("{8235D6A5-AAFD-4D39-BFE8-EF1641AB9257}")
$CLSID_COMTextLineInputContextClass = GUID$("{E17FE5B0-C2BC-4C97-8EBF-8EF2F763FCA8}")
$CLSID_COMTextWordInputContextClass = GUID$("{0A402C88-0CEB-42C6-A15B-32AA45052706}")
$CLSID_COMTSVInputContextClass = GUID$("{FFB760AB-4ACA-4070-99D5-194D9272B47D}")
$CLSID_COMTSVOutputContextClass = GUID$("{38E8C317-D7A1-49EE-8437-8DFE91462B1E}")
$CLSID_COMURLScanLogInputContextClass = GUID$("{9A6E2BE0-96E4-4985-87AF-BDC668EA15A5}")
$CLSID_COMW3CInputContextClass = GUID$("{3ED0372B-4117-4CA3-A638-EF9BF3720248}")
$CLSID_COMW3COutputContextClass = GUID$("{DC691F49-FD32-4E17-8C5F-F7C31F46FDF5}")
$CLSID_COMXMLInputContextClass = GUID$("{0776E95A-34E3-4488-886E-094BA16BB6BD}")
$CLSID_COMXMLOutputContextClass = GUID$("{29467682-1CFC-46EA-B64D-EB31A56B321D}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICOMADSInputContext = GUID$("{85B21BA3-4271-4B10-A837-B715FDF3B0A1}")
$IID_ICOMChartOutputContext = GUID$("{C0D19115-1C4F-4A49-A02C-60BF913BEFF9}")
$IID_ICOMCSVInputContext = GUID$("{80206B7F-6424-41FA-984C-7DBD92CE0C48}")
$IID_ICOMCSVOutputContext = GUID$("{FB96582A-63D4-4564-A65A-26EB352734FA}")
$IID_ICOMDataGridOutputContext = GUID$("{2690326C-0A98-41A0-A53A-BE0D58F0E936}")
$IID_ICOMETWInputContext = GUID$("{B53E5AF6-3D61-42B1-8F65-4F4F7368EC59}")
$IID_ICOMEventLogInputContext = GUID$("{1D8AD32F-4DF0-41A7-AD76-8B3345EB1144}")
$IID_ICOMFileSystemInputContext = GUID$("{76DDDBC5-5DFF-4A2B-9E09-4E1C26C6A938}")
$IID_ICOMHttpErrorInputContext = GUID$("{3A698D1E-D6AE-46B0-B9F5-FA1C6F9092F4}")
$IID_ICOMIISBINInputContext = GUID$("{F0FF3746-6CA6-4AB6-AE64-79A26FA82950}")
$IID_ICOMIISIISInputContext = GUID$("{CB6A017F-69ED-48D2-8ED7-42B1BCB80844}")
$IID_ICOMIISIISMSIDInputContext = GUID$("{55FCA9B8-56BB-479C-92C7-388011A6E45B}")
$IID_ICOMIISNCSAInputContext = GUID$("{C0B28DCB-F1D8-48A3-B4F4-FC28BEBA5EBA}")
$IID_ICOMIISODBCInputContext = GUID$("{ADE25553-5361-44BA-9270-31B08B4A8D6F}")
$IID_ICOMIISOutputContext = GUID$("{7A5A3711-A707-4381-9C86-9ECADFB88975}")
$IID_ICOMIISW3CInputContext = GUID$("{CC00A85E-22A3-4E73-8FA8-088EE78B1DC5}")
$IID_ICOMNativeOutputContext = GUID$("{1979F191-21AA-489D-BCDC-8CB6DC60AF42}")
$IID_ICOMNetMonInputContext = GUID$("{3837E95F-07DB-4D09-99CD-586B4E094208}")
$IID_ICOMRegistryInputContext = GUID$("{09631558-6E49-4D0D-927F-628BA883CB1D}")
$IID_ICOMSQLOutputContext = GUID$("{023D89CA-32BE-44DC-B442-478EC7478D62}")
$IID_ICOMSYSLOGOutputContext = GUID$("{B0936B89-8035-42CE-A33C-9E2E22DEADD2}")
$IID_ICOMTemplateOutputContext = GUID$("{2547428D-535E-4467-9C0C-77511E47BE0D}")
$IID_ICOMTextLineInputContext = GUID$("{AF3F77B5-028D-4DE3-BDE7-8D84C30573C0}")
$IID_ICOMTextWordInputContext = GUID$("{BCE40C1E-DEE2-477A-B479-7E817D5446F3}")
$IID_ICOMTSVInputContext = GUID$("{84C54BEB-D3C1-4E89-A868-F6F40B184D68}")
$IID_ICOMTSVOutputContext = GUID$("{8819BA1E-1931-4CCF-9F71-64547651AA54}")
$IID_ICOMURLScanLogInputContext = GUID$("{9EBC373B-4E35-455A-8611-8A9ECE6689F5}")
$IID_ICOMW3CInputContext = GUID$("{6642B90C-5D0B-4547-A67D-C844746E7C1C}")
$IID_ICOMW3COutputContext = GUID$("{9F3A6096-C1A3-428D-BE12-EEA7CDB3627F}")
$IID_ICOMXMLInputContext = GUID$("{72B09A81-FB17-4187-B5F8-AD7E9592548E}")
$IID_ICOMXMLOutputContext = GUID$("{5481A119-1977-4190-B585-C62373A6A024}")
$IID_ILogQuery = GUID$("{3BDE06BC-89E4-42FD-BE64-832A5F33D7D3}")
$IID_ILogRecord = GUID$("{185FFF88-E24A-4984-9621-AA41BEAE8513}")
$IID_ILogRecordset = GUID$("{C9452B1B-093C-4842-ABD1-F81410926874}")
$IID_ILogStringCollection = GUID$("{DA56E00E-E07C-4AB0-954E-0F901E9179A0}")

' ########################################################################################
' Interface name = ILogQuery
' IID = {3BDE06BC-89E4-42FD-BE64-832A5F33D7D3}
' Executes the SQL query, using the specified Input Format (if specified)
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILogQuery_INTERFACE_DEFINED)
    %ILogQuery_INTERFACE_DEFINED = 1

INTERFACE ILogQuery $IID_ILogQuery

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Execute <1> ( _                               ' VTable offset = 28
     BYVAL szQuery AS WSTRING _                         ' __in BSTR szQuery
   , OPTIONAL BYVAL pObjectInputContext AS IUnknown _   ' __in_opt IUnknown* pObjectInputContext
   ) AS ILogRecordset                                   ' __retval_out ILogRecordset** result
   ' =====================================================================================
   METHOD ExecuteBatch <2> ( _                          ' VTable offset = 32
     BYVAL szQuery AS WSTRING _                         ' __in BSTR szQuery
   , OPTIONAL BYVAL pObjectInputContext AS IUnknown _   ' __in_opt IUnknown* pObjectInputContext
   , OPTIONAL BYVAL pObjectOutputContext AS IUnknown _  ' __in_opt IUnknown* pObjectOutputContext
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbResult
   ' =====================================================================================
   PROPERTY GET maxParseErrors <1610743810> ( _         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* maxParseErrors
   ' =====================================================================================
   PROPERTY SET maxParseErrors <1610743810> ( _         ' VTable offset = 40
     BYVAL maxParseErrors AS LONG _                     ' __in int maxParseErrors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET lastError <1610743812> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* lastError
   ' =====================================================================================
   PROPERTY GET inputUnitsProcessed <1610743813> ( _    ' VTable offset = 48
   ) AS LONG                                            ' __retval_out int* pnInputUnitsProcessed
   ' =====================================================================================
   PROPERTY GET outputUnitsProcessed <1610743814> ( _   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pnOutputUnitsProcessed
   ' =====================================================================================
   PROPERTY GET errorMessages <1610743815> ( _          ' VTable offset = 56
   ) AS ILogStringCollection                            ' __retval_out ILogStringCollection** ppILogStringCollection
   ' =====================================================================================
   PROPERTY GET versionMin <1610743816> ( _             ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int* pnversionMin
   ' =====================================================================================
   PROPERTY GET versionMaj <1610743817> ( _             ' VTable offset = 64
   ) AS LONG                                            ' __retval_out int* pnversionMaj
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogQuery_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogRecordset
' IID = {C9452B1B-093C-4842-ABD1-F81410926874}
' Log Parser Recordset, composed of ILogRecord items
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILogRecordset_INTERFACE_DEFINED)
    %ILogRecordset_INTERFACE_DEFINED = 1

INTERFACE ILogRecordset $IID_ILogRecordset

   INHERIT IDispatch

   ' =====================================================================================
   METHOD moveNext <1> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD getRecord <2> ( _                             ' VTable offset = 32
   ) AS ILogRecord                                      ' __retval_out ILogRecord** record
   ' =====================================================================================
   METHOD atEnd <3> ( _                                 ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* bAtEnd
   ' =====================================================================================
   METHOD close <4> ( _                                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD getColumnCount <5> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* nColumnCount
   ' =====================================================================================
   METHOD getColumnName <6> ( _                         ' VTable offset = 48
     BYVAL index AS LONG _                              ' __in int index
   ) AS WSTRING                                         ' __retval_out BSTR* columnName
   ' =====================================================================================
   METHOD getColumnType <7> ( _                         ' VTable offset = 52
     BYVAL index AS LONG _                              ' __in int index
   ) AS LONG                                            ' __retval_out int* columnType
   ' =====================================================================================
   PROPERTY GET lastError <1610743815> ( _              ' VTable offset = 56
   ) AS LONG                                            ' __retval_out int* lastError
   ' =====================================================================================
   PROPERTY GET inputUnitsProcessed <1610743816> ( _    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int* pnInputUnitsProcessed
   ' =====================================================================================
   PROPERTY GET errorMessages <1610743817> ( _          ' VTable offset = 64
   ) AS ILogStringCollection                            ' __retval_out ILogStringCollection** ppILogStringCollection
   ' =====================================================================================
   PROPERTY GET STRING_TYPE <1610743818> ( _            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* stringType
   ' =====================================================================================
   PROPERTY GET REAL_TYPE <1610743819> ( _              ' VTable offset = 72
   ) AS LONG                                            ' __retval_out int* realType
   ' =====================================================================================
   PROPERTY GET INTEGER_TYPE <1610743820> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out int* integerType
   ' =====================================================================================
   PROPERTY GET TIMESTAMP_TYPE <1610743821> ( _         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out int* timestampType
   ' =====================================================================================
   PROPERTY GET NULL_TYPE <1610743822> ( _              ' VTable offset = 84
   ) AS LONG                                            ' __retval_out int* nullType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogRecordset_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogRecord
' IID = {185FFF88-E24A-4984-9621-AA41BEAE8513}
' Log Parser result record, composed of fields
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILogRecord_INTERFACE_DEFINED)
    %ILogRecord_INTERFACE_DEFINED = 1

INTERFACE ILogRecord $IID_ILogRecord

   INHERIT IDispatch

   ' =====================================================================================
   METHOD getValue <1> ( _                              ' VTable offset = 28
     BYVAL nIndexOrName AS VARIANT _                    ' __in VARIANT nIndexOrName
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   METHOD isNull <2> ( _                                ' VTable offset = 32
     BYVAL nIndexOrName AS VARIANT _                    ' __in VARIANT nIndexOrName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbIsNull
   ' =====================================================================================
   METHOD toNativeString <3> ( _                        ' VTable offset = 36
     BYVAL separatorStringOrIndex AS VARIANT _          ' __in VARIANT separatorStringOrIndex
   ) AS WSTRING                                         ' __retval_out BSTR* pString
   ' =====================================================================================
   METHOD getValueEx <4> ( _                            ' VTable offset = 40
     BYVAL nIndexOrName AS VARIANT _                    ' __in VARIANT nIndexOrName
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogRecord_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogStringCollection
' IID = {DA56E00E-E07C-4AB0-954E-0F901E9179A0}
' Log Parser String collection for Error messages and Locale names
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILogStringCollection_INTERFACE_DEFINED)
    %ILogStringCollection_INTERFACE_DEFINED = 1

INTERFACE ILogStringCollection $IID_ILogStringCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT** ppIEnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogStringCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISW3CInputContext
' IID = {CC00A85E-22A3-4E73-8FA8-088EE78B1DC5}
' IIS W3C Extended Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISW3CInputContext_INTERFACE_DEFINED)
    %ICOMIISW3CInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISW3CInputContext $IID_ICOMIISW3CInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743812> ( _                ' VTable offset = 48
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET useDoubleQuotes <1610743814> ( _        ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDoubleQuotes
   ' =====================================================================================
   PROPERTY SET useDoubleQuotes <1610743814> ( _        ' VTable offset = 56
     BYVAL pbuseDoubleQuotes AS INTEGER _               ' __in VARIANT_BOOL pbuseDoubleQuotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dQuotes <1610743816> ( _                ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDoubleQuotes
   ' =====================================================================================
   PROPERTY SET dQuotes <1610743816> ( _                ' VTable offset = 64
     BYVAL pbuseDoubleQuotes AS INTEGER _               ' __in VARIANT_BOOL pbuseDoubleQuotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET useDirectiveDateTime <1610743818> ( _   ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDirectiveDateTime
   ' =====================================================================================
   PROPERTY SET useDirectiveDateTime <1610743818> ( _   ' VTable offset = 72
     BYVAL pbuseDirectiveDateTime AS INTEGER _          ' __in VARIANT_BOOL pbuseDirectiveDateTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dirTime <1610743820> ( _                ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDirectiveDateTime
   ' =====================================================================================
   PROPERTY SET dirTime <1610743820> ( _                ' VTable offset = 80
     BYVAL pbuseDirectiveDateTime AS INTEGER _          ' __in VARIANT_BOOL pbuseDirectiveDateTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET consolidateLogs <1610743822> ( _        ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbconsolidateLogs
   ' =====================================================================================
   PROPERTY SET consolidateLogs <1610743822> ( _        ' VTable offset = 88
     BYVAL pbconsolidateLogs AS INTEGER _               ' __in VARIANT_BOOL pbconsolidateLogs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743824> ( _            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743824> ( _            ' VTable offset = 96
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET minDateMod <1610743826> ( _             ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* pszminDateMod
   ' =====================================================================================
   PROPERTY SET minDateMod <1610743826> ( _             ' VTable offset = 104
     BYVAL pszminDateMod AS WSTRING _                   ' __in BSTR pszminDateMod
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMIISW3CInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISNCSAInputContext
' IID = {C0B28DCB-F1D8-48A3-B4F4-FC28BEBA5EBA}
' IIS NCSA Common Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISNCSAInputContext_INTERFACE_DEFINED)
    %ICOMIISNCSAInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISNCSAInputContext $IID_ICOMIISNCSAInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743812> ( _                ' VTable offset = 48
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743814> ( _            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743814> ( _            ' VTable offset = 56
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET minDateMod <1610743816> ( _             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszminDateMod
   ' =====================================================================================
   PROPERTY SET minDateMod <1610743816> ( _             ' VTable offset = 64
     BYVAL pszminDateMod AS WSTRING _                   ' __in BSTR pszminDateMod
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMIISNCSAInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISIISInputContext
' IID = {CB6A017F-69ED-48D2-8ED7-42B1BCB80844}
' Microsoft IIS Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISIISInputContext_INTERFACE_DEFINED)
    %ICOMIISIISInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISIISInputContext $IID_ICOMIISIISInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743812> ( _                ' VTable offset = 48
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET locale <1610743814> ( _                 ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pszlocale
   ' =====================================================================================
   PROPERTY SET locale <1610743814> ( _                 ' VTable offset = 56
     BYVAL pszlocale AS WSTRING _                       ' __in BSTR pszlocale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743816> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743816> ( _            ' VTable offset = 64
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET minDateMod <1610743818> ( _             ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pszminDateMod
   ' =====================================================================================
   PROPERTY SET minDateMod <1610743818> ( _             ' VTable offset = 72
     BYVAL pszminDateMod AS WSTRING _                   ' __in BSTR pszminDateMod
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMIISIISInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISODBCInputContext
' IID = {ADE25553-5361-44BA-9270-31B08B4A8D6F}
' IIS ODBC Log Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISODBCInputContext_INTERFACE_DEFINED)
    %ICOMIISODBCInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISODBCInputContext $IID_ICOMIISODBCInputContext

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __ICOMIISODBCInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISBINInputContext
' IID = {F0FF3746-6CA6-4AB6-AE64-79A26FA82950}
' IIS Binary Log Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISBINInputContext_INTERFACE_DEFINED)
    %ICOMIISBINInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISBINInputContext $IID_ICOMIISBINInputContext

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __ICOMIISBINInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISIISMSIDInputContext
' IID = {55FCA9B8-56BB-479C-92C7-388011A6E45B}
' Microsoft IIS Input Format with MSID Filter
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISIISMSIDInputContext_INTERFACE_DEFINED)
    %ICOMIISIISMSIDInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISIISMSIDInputContext $IID_ICOMIISIISMSIDInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743812> ( _                ' VTable offset = 48
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET locale <1610743814> ( _                 ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pszlocale
   ' =====================================================================================
   PROPERTY SET locale <1610743814> ( _                 ' VTable offset = 56
     BYVAL pszlocale AS WSTRING _                       ' __in BSTR pszlocale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cLogFilt <1610743816> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbcLogFilt
   ' =====================================================================================
   PROPERTY SET cLogFilt <1610743816> ( _               ' VTable offset = 64
     BYVAL pbcLogFilt AS INTEGER _                      ' __in VARIANT_BOOL pbcLogFilt
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fMode <1610743818> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pbszfieldMode
   ' =====================================================================================
   PROPERTY SET fMode <1610743818> ( _                  ' VTable offset = 72
     BYVAL pbszfieldMode AS WSTRING _                   ' __in BSTR pbszfieldMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743820> ( _            ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743820> ( _            ' VTable offset = 80
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET minDateMod <1610743822> ( _             ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pszminDateMod
   ' =====================================================================================
   PROPERTY SET minDateMod <1610743822> ( _             ' VTable offset = 88
     BYVAL pszminDateMod AS WSTRING _                   ' __in BSTR pszminDateMod
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMIISIISMSIDInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMHttpErrorInputContext
' IID = {3A698D1E-D6AE-46B0-B9F5-FA1C6F9092F4}
' HttpError Log Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMHttpErrorInputContext_INTERFACE_DEFINED)
    %ICOMHttpErrorInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMHttpErrorInputContext $IID_ICOMHttpErrorInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET dirTime <1610743808> ( _                ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDirectiveDateTime
   ' =====================================================================================
   PROPERTY SET dirTime <1610743808> ( _                ' VTable offset = 32
     BYVAL pbuseDirectiveDateTime AS INTEGER _          ' __in VARIANT_BOOL pbuseDirectiveDateTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743810> ( _               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743810> ( _               ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743812> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743812> ( _              ' VTable offset = 48
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743814> ( _            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743814> ( _            ' VTable offset = 56
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET minDateMod <1610743816> ( _             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszminDateMod
   ' =====================================================================================
   PROPERTY SET minDateMod <1610743816> ( _             ' VTable offset = 64
     BYVAL pszminDateMod AS WSTRING _                   ' __in BSTR pszminDateMod
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMHttpErrorInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMEventLogInputContext
' IID = {1D8AD32F-4DF0-41A7-AD76-8B3345EB1144}
' Event Log Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMEventLogInputContext_INTERFACE_DEFINED)
    %ICOMEventLogInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMEventLogInputContext $IID_ICOMEventLogInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET fullText <1610743808> ( _               ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbfullText
   ' =====================================================================================
   PROPERTY SET fullText <1610743808> ( _               ' VTable offset = 32
     BYVAL pbfullText AS INTEGER _                      ' __in VARIANT_BOOL pbfullText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET resolveSIDs <1610743810> ( _            ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbresolveSIDs
   ' =====================================================================================
   PROPERTY SET resolveSIDs <1610743810> ( _            ' VTable offset = 40
     BYVAL pbresolveSIDs AS INTEGER _                   ' __in VARIANT_BOOL pbresolveSIDs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET formatMessage <1610743812> ( _          ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbformatMessage
   ' =====================================================================================
   PROPERTY SET formatMessage <1610743812> ( _          ' VTable offset = 48
     BYVAL pbformatMessage AS INTEGER _                 ' __in VARIANT_BOOL pbformatMessage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET formatMsg <1610743814> ( _              ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbformatMessage
   ' =====================================================================================
   PROPERTY SET formatMsg <1610743814> ( _              ' VTable offset = 56
     BYVAL pbformatMessage AS INTEGER _                 ' __in VARIANT_BOOL pbformatMessage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreMessageErrors <1610743816> ( _    ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreMessageErrors
   ' =====================================================================================
   PROPERTY SET ignoreMessageErrors <1610743816> ( _    ' VTable offset = 64
     BYVAL pbignoreMessageErrors AS INTEGER _           ' __in VARIANT_BOOL pbignoreMessageErrors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET msgErrorMode <1610743818> ( _           ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pbszmsgErrorMode
   ' =====================================================================================
   PROPERTY SET msgErrorMode <1610743818> ( _           ' VTable offset = 72
     BYVAL pbszmsgErrorMode AS WSTRING _                ' __in BSTR pbszmsgErrorMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fullEventCode <1610743820> ( _          ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbfullEventCode
   ' =====================================================================================
   PROPERTY SET fullEventCode <1610743820> ( _          ' VTable offset = 80
     BYVAL pbfullEventCode AS INTEGER _                 ' __in VARIANT_BOOL pbfullEventCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET direction <1610743822> ( _              ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pszDirection
   ' =====================================================================================
   PROPERTY SET direction <1610743822> ( _              ' VTable offset = 88
     BYVAL pszDirection AS WSTRING _                    ' __in BSTR pszDirection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET stringsSep <1610743824> ( _             ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pszstringsSep
   ' =====================================================================================
   PROPERTY SET stringsSep <1610743824> ( _             ' VTable offset = 96
     BYVAL pszstringsSep AS WSTRING _                   ' __in BSTR pszstringsSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743826> ( _            ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743826> ( _            ' VTable offset = 104
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET binaryFormat <1610743828> ( _           ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR* pszbinaryFormat
   ' =====================================================================================
   PROPERTY SET binaryFormat <1610743828> ( _           ' VTable offset = 112
     BYVAL pszbinaryFormat AS WSTRING _                 ' __in BSTR pszbinaryFormat
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMEventLogInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMURLScanLogInputContext
' IID = {9EBC373B-4E35-455A-8611-8A9ECE6689F5}
' URLScan Log Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMURLScanLogInputContext_INTERFACE_DEFINED)
    %ICOMURLScanLogInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMURLScanLogInputContext $IID_ICOMURLScanLogInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743808> ( _            ' VTable offset = 32
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMURLScanLogInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMTextLineInputContext
' IID = {AF3F77B5-028D-4DE3-BDE7-8D84C30573C0}
' Line-by-Line Text File
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMTextLineInputContext_INTERFACE_DEFINED)
    %ICOMTextLineInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMTextLineInputContext $IID_ICOMTextLineInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743812> ( _                ' VTable offset = 48
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET splitLongLines <1610743814> ( _         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbsplitLongLines
   ' =====================================================================================
   PROPERTY SET splitLongLines <1610743814> ( _         ' VTable offset = 56
     BYVAL pbsplitLongLines AS INTEGER _                ' __in VARIANT_BOOL pbsplitLongLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743816> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743816> ( _            ' VTable offset = 64
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMTextLineInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMTextWordInputContext
' IID = {BCE40C1E-DEE2-477A-B479-7E817D5446F3}
' Word-by-Word Text File
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMTextWordInputContext_INTERFACE_DEFINED)
    %ICOMTextWordInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMTextWordInputContext $IID_ICOMTextWordInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743812> ( _                ' VTable offset = 48
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743814> ( _            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743814> ( _            ' VTable offset = 56
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMTextWordInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMFileSystemInputContext
' IID = {76DDDBC5-5DFF-4A2B-9E09-4E1C26C6A938}
' Files Information
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMFileSystemInputContext_INTERFACE_DEFINED)
    %ICOMFileSystemInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMFileSystemInputContext $IID_ICOMFileSystemInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET recurse <1610743808> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743808> ( _                ' VTable offset = 32
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET preserveLastAccTime <1610743810> ( _    ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbpreserveLastAccTime
   ' =====================================================================================
   PROPERTY SET preserveLastAccTime <1610743810> ( _    ' VTable offset = 40
     BYVAL pbpreserveLastAccTime AS INTEGER _           ' __in VARIANT_BOOL pbpreserveLastAccTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET useLocalTime <1610743812> ( _           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseLocalTime
   ' =====================================================================================
   PROPERTY SET useLocalTime <1610743812> ( _           ' VTable offset = 48
     BYVAL pbuseLocalTime AS INTEGER _                  ' __in VARIANT_BOOL pbuseLocalTime
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMFileSystemInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMCSVInputContext
' IID = {80206B7F-6424-41FA-984C-7DBD92CE0C48}
' CSV Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMCSVInputContext_INTERFACE_DEFINED)
    %ICOMCSVInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMCSVInputContext $IID_ICOMCSVInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET headerRow <1610743808> ( _              ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbheaderRow
   ' =====================================================================================
   PROPERTY SET headerRow <1610743808> ( _              ' VTable offset = 32
     BYVAL pbheaderRow AS INTEGER _                     ' __in VARIANT_BOOL pbheaderRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET headerFile <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszheaderFile
   ' =====================================================================================
   PROPERTY SET headerFile <1610743810> ( _             ' VTable offset = 40
     BYVAL pszheaderFile AS WSTRING _                   ' __in BSTR pszheaderFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iHeaderFile <1610743812> ( _            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pszheaderFile
   ' =====================================================================================
   PROPERTY SET iHeaderFile <1610743812> ( _            ' VTable offset = 48
     BYVAL pszheaderFile AS WSTRING _                   ' __in BSTR pszheaderFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iDQuotes <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psziDQuotes
   ' =====================================================================================
   PROPERTY SET iDQuotes <1610743814> ( _               ' VTable offset = 56
     BYVAL psziDQuotes AS WSTRING _                     ' __in BSTR psziDQuotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fixedFields <1610743816> ( _            ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbfixedFields
   ' =====================================================================================
   PROPERTY SET fixedFields <1610743816> ( _            ' VTable offset = 64
     BYVAL pbfixedFields AS INTEGER _                   ' __in VARIANT_BOOL pbfixedFields
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nFields <1610743818> ( _                ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* pnnFields
   ' =====================================================================================
   PROPERTY SET nFields <1610743818> ( _                ' VTable offset = 72
     BYVAL pnnFields AS LONG _                          ' __in int pnnFields
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET detectTypesLines <1610743820> ( _       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out int* pndetectTypesLines
   ' =====================================================================================
   PROPERTY SET detectTypesLines <1610743820> ( _       ' VTable offset = 80
     BYVAL pndetectTypesLines AS LONG _                 ' __in int pndetectTypesLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dtLines <1610743822> ( _                ' VTable offset = 84
   ) AS LONG                                            ' __retval_out int* pndetectTypesLines
   ' =====================================================================================
   PROPERTY SET dtLines <1610743822> ( _                ' VTable offset = 88
     BYVAL pndetectTypesLines AS LONG _                 ' __in int pndetectTypesLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nSkipLines <1610743824> ( _             ' VTable offset = 92
   ) AS LONG                                            ' __retval_out int* pnSkipLines
   ' =====================================================================================
   PROPERTY SET nSkipLines <1610743824> ( _             ' VTable offset = 96
     BYVAL pnSkipLines AS LONG _                        ' __in int pnSkipLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET comment <1610743826> ( _                ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* pszComment
   ' =====================================================================================
   PROPERTY SET comment <1610743826> ( _                ' VTable offset = 104
     BYVAL pszComment AS WSTRING _                      ' __in BSTR pszComment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743828> ( _               ' VTable offset = 112
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743830> ( _              ' VTable offset = 116
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743830> ( _              ' VTable offset = 120
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timestampFormat <1610743832> ( _        ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET timestampFormat <1610743832> ( _        ' VTable offset = 128
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iTsFormat <1610743834> ( _              ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET iTsFormat <1610743834> ( _              ' VTable offset = 136
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743836> ( _            ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743836> ( _            ' VTable offset = 144
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMCSVInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMW3CInputContext
' IID = {6642B90C-5D0B-4547-A67D-C844746E7C1C}
' W3C Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMW3CInputContext_INTERFACE_DEFINED)
    %ICOMW3CInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMW3CInputContext $IID_ICOMW3CInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET codepage <1610743808> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743808> ( _               ' VTable offset = 32
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743810> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743810> ( _              ' VTable offset = 40
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET detectTypesLines <1610743812> ( _       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pndetectTypesLines
   ' =====================================================================================
   PROPERTY SET detectTypesLines <1610743812> ( _       ' VTable offset = 48
     BYVAL pndetectTypesLines AS LONG _                 ' __in int pndetectTypesLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dtLines <1610743814> ( _                ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pndetectTypesLines
   ' =====================================================================================
   PROPERTY SET dtLines <1610743814> ( _                ' VTable offset = 56
     BYVAL pndetectTypesLines AS LONG _                 ' __in int pndetectTypesLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET doubleQuotedStrings <1610743816> ( _    ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbdoubleQuotedStrings
   ' =====================================================================================
   PROPERTY SET doubleQuotedStrings <1610743816> ( _    ' VTable offset = 64
     BYVAL pbdoubleQuotedStrings AS INTEGER _           ' __in VARIANT_BOOL pbdoubleQuotedStrings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dQuotes <1610743818> ( _                ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbdoubleQuotedStrings
   ' =====================================================================================
   PROPERTY SET dQuotes <1610743818> ( _                ' VTable offset = 72
     BYVAL pbdoubleQuotedStrings AS INTEGER _           ' __in VARIANT_BOOL pbdoubleQuotedStrings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET separator <1610743820> ( _              ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparator
   ' =====================================================================================
   PROPERTY SET separator <1610743820> ( _              ' VTable offset = 80
     BYVAL pszseparator AS WSTRING _                    ' __in BSTR pszseparator
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMW3CInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMETWInputContext
' IID = {B53E5AF6-3D61-42B1-8F65-4F4F7368EC59}
' ETW Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMETWInputContext_INTERFACE_DEFINED)
    %ICOMETWInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMETWInputContext $IID_ICOMETWInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET providers <1610743808> ( _              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pszpf
   ' =====================================================================================
   PROPERTY SET providers <1610743808> ( _              ' VTable offset = 32
     BYVAL pszpf AS WSTRING _                           ' __in BSTR pszpf
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dtEventsLog <1610743810> ( _            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pndtEventsLog
   ' =====================================================================================
   PROPERTY SET dtEventsLog <1610743810> ( _            ' VTable offset = 40
     BYVAL pndtEventsLog AS LONG _                      ' __in int pndtEventsLog
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dtEventsLive <1610743812> ( _           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pndtEventsLive
   ' =====================================================================================
   PROPERTY SET dtEventsLive <1610743812> ( _           ' VTable offset = 48
     BYVAL pndtEventsLive AS LONG _                     ' __in int pndtEventsLive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET flushPeriod <1610743814> ( _            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pnflushPeriod
   ' =====================================================================================
   PROPERTY SET flushPeriod <1610743814> ( _            ' VTable offset = 56
     BYVAL pnflushPeriod AS LONG _                      ' __in int pnflushPeriod
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreEventTrace <1610743816> ( _       ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreEventTraceEvents
   ' =====================================================================================
   PROPERTY SET ignoreEventTrace <1610743816> ( _       ' VTable offset = 64
     BYVAL pbignoreEventTraceEvents AS INTEGER _        ' __in VARIANT_BOOL pbignoreEventTraceEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fMode <1610743818> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pszfMode
   ' =====================================================================================
   PROPERTY SET fMode <1610743818> ( _                  ' VTable offset = 72
     BYVAL pszfMode AS WSTRING _                        ' __in BSTR pszfMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET compactModeSep <1610743820> ( _         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pszcompactModeSep
   ' =====================================================================================
   PROPERTY SET compactModeSep <1610743820> ( _         ' VTable offset = 80
     BYVAL pszcompactModeSep AS WSTRING _               ' __in BSTR pszcompactModeSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET expandEnums <1610743822> ( _            ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbExpandEnums
   ' =====================================================================================
   PROPERTY SET expandEnums <1610743822> ( _            ' VTable offset = 88
     BYVAL pbExpandEnums AS INTEGER _                   ' __in VARIANT_BOOL pbExpandEnums
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreLostEvents <1610743824> ( _       ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreLostEvents
   ' =====================================================================================
   PROPERTY SET ignoreLostEvents <1610743824> ( _       ' VTable offset = 96
     BYVAL pbignoreLostEvents AS INTEGER _              ' __in VARIANT_BOOL pbignoreLostEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET schemaServer <1610743826> ( _           ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* pszschemaServer
   ' =====================================================================================
   PROPERTY SET schemaServer <1610743826> ( _           ' VTable offset = 104
     BYVAL pszschemaServer AS WSTRING _                 ' __in BSTR pszschemaServer
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMETWInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMRegistryInputContext
' IID = {09631558-6E49-4D0D-927F-628BA883CB1D}
' Registry Information
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMRegistryInputContext_INTERFACE_DEFINED)
    %ICOMRegistryInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMRegistryInputContext $IID_ICOMRegistryInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET recurse <1610743808> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743808> ( _                ' VTable offset = 32
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET multiSZSep <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszmultiSZSep
   ' =====================================================================================
   PROPERTY SET multiSZSep <1610743810> ( _             ' VTable offset = 40
     BYVAL pszmultiSZSep AS WSTRING _                   ' __in BSTR pszmultiSZSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET binaryFormat <1610743812> ( _           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pszbinaryFormat
   ' =====================================================================================
   PROPERTY SET binaryFormat <1610743812> ( _           ' VTable offset = 48
     BYVAL pszbinaryFormat AS WSTRING _                 ' __in BSTR pszbinaryFormat
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMRegistryInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMTSVInputContext
' IID = {84C54BEB-D3C1-4E89-A868-F6F40B184D68}
' TSV Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMTSVInputContext_INTERFACE_DEFINED)
    %ICOMTSVInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMTSVInputContext $IID_ICOMTSVInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET nSeparators <1610743808> ( _            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnSep
   ' =====================================================================================
   PROPERTY SET nSeparators <1610743808> ( _            ' VTable offset = 32
     BYVAL pnSep AS LONG _                              ' __in int pnSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nSep <1610743810> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pnSep
   ' =====================================================================================
   PROPERTY SET nSep <1610743810> ( _                   ' VTable offset = 40
     BYVAL pnSep AS LONG _                              ' __in int pnSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fixedSep <1610743812> ( _               ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbfixedSep
   ' =====================================================================================
   PROPERTY SET fixedSep <1610743812> ( _               ' VTable offset = 48
     BYVAL pbfixedSep AS INTEGER _                      ' __in VARIANT_BOOL pbfixedSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743814> ( _               ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743814> ( _               ' VTable offset = 56
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCodepage <1610743816> ( _              ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET iCodepage <1610743816> ( _              ' VTable offset = 64
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET detectTypesLines <1610743818> ( _       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* pndetectTypesLines
   ' =====================================================================================
   PROPERTY SET detectTypesLines <1610743818> ( _       ' VTable offset = 72
     BYVAL pndetectTypesLines AS LONG _                 ' __in int pndetectTypesLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dtLines <1610743820> ( _                ' VTable offset = 76
   ) AS LONG                                            ' __retval_out int* pndetectTypesLines
   ' =====================================================================================
   PROPERTY SET dtLines <1610743820> ( _                ' VTable offset = 80
     BYVAL pndetectTypesLines AS LONG _                 ' __in int pndetectTypesLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET headerRow <1610743822> ( _              ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbheaderRow
   ' =====================================================================================
   PROPERTY SET headerRow <1610743822> ( _              ' VTable offset = 88
     BYVAL pbheaderRow AS INTEGER _                     ' __in VARIANT_BOOL pbheaderRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET headerFile <1610743824> ( _             ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pszheaderFile
   ' =====================================================================================
   PROPERTY SET headerFile <1610743824> ( _             ' VTable offset = 96
     BYVAL pszheaderFile AS WSTRING _                   ' __in BSTR pszheaderFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iHeaderFile <1610743826> ( _            ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* pszheaderFile
   ' =====================================================================================
   PROPERTY SET iHeaderFile <1610743826> ( _            ' VTable offset = 104
     BYVAL pszheaderFile AS WSTRING _                   ' __in BSTR pszheaderFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nFields <1610743828> ( _                ' VTable offset = 108
   ) AS LONG                                            ' __retval_out int* pnnFields
   ' =====================================================================================
   PROPERTY SET nFields <1610743828> ( _                ' VTable offset = 112
     BYVAL pnnFields AS LONG _                          ' __in int pnnFields
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nSkipLines <1610743830> ( _             ' VTable offset = 116
   ) AS LONG                                            ' __retval_out int* pnSkipLines
   ' =====================================================================================
   PROPERTY SET nSkipLines <1610743830> ( _             ' VTable offset = 120
     BYVAL pnSkipLines AS LONG _                        ' __in int pnSkipLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET separator <1610743832> ( _              ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparator
   ' =====================================================================================
   PROPERTY SET separator <1610743832> ( _              ' VTable offset = 128
     BYVAL pszseparator AS WSTRING _                    ' __in BSTR pszseparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iSeparator <1610743834> ( _             ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparator
   ' =====================================================================================
   PROPERTY SET iSeparator <1610743834> ( _             ' VTable offset = 136
     BYVAL pszseparator AS WSTRING _                    ' __in BSTR pszseparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET lineFilter <1610743836> ( _             ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR* pszlineFilter
   ' =====================================================================================
   PROPERTY SET lineFilter <1610743836> ( _             ' VTable offset = 144
     BYVAL pszlineFilter AS WSTRING _                   ' __in BSTR pszlineFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timestampFormat <1610743838> ( _        ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET timestampFormat <1610743838> ( _        ' VTable offset = 152
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iTsFormat <1610743840> ( _              ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET iTsFormat <1610743840> ( _              ' VTable offset = 160
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iCheckpoint <1610743842> ( _            ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR* psziCheckpoint
   ' =====================================================================================
   PROPERTY SET iCheckpoint <1610743842> ( _            ' VTable offset = 168
     BYVAL psziCheckpoint AS WSTRING _                  ' __in BSTR psziCheckpoint
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMTSVInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMADSInputContext
' IID = {85B21BA3-4271-4B10-A837-B715FDF3B0A1}
' ADS Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMADSInputContext_INTERFACE_DEFINED)
    %ICOMADSInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMADSInputContext $IID_ICOMADSInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET objClass <1610743808> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pszclass
   ' =====================================================================================
   PROPERTY SET objClass <1610743808> ( _               ' VTable offset = 32
     BYVAL pszclass AS WSTRING _                        ' __in BSTR pszclass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET username <1610743810> ( _               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszusername
   ' =====================================================================================
   PROPERTY SET username <1610743810> ( _               ' VTable offset = 40
     BYVAL pszusername AS WSTRING _                     ' __in BSTR pszusername
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET password <1610743812> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pszpassword
   ' =====================================================================================
   PROPERTY SET password <1610743812> ( _               ' VTable offset = 48
     BYVAL pszpassword AS WSTRING _                     ' __in BSTR pszpassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET recurse <1610743814> ( _                ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pnrecurse
   ' =====================================================================================
   PROPERTY SET recurse <1610743814> ( _                ' VTable offset = 56
     BYVAL pnrecurse AS LONG _                          ' __in int pnrecurse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET multiValuedSep <1610743816> ( _         ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszmultiValuedSep
   ' =====================================================================================
   PROPERTY SET multiValuedSep <1610743816> ( _         ' VTable offset = 64
     BYVAL pszmultiValuedSep AS WSTRING _               ' __in BSTR pszmultiValuedSep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreDSErrors <1610743818> ( _         ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreDSErrors
   ' =====================================================================================
   PROPERTY SET ignoreDSErrors <1610743818> ( _         ' VTable offset = 72
     BYVAL pbignoreDSErrors AS INTEGER _                ' __in VARIANT_BOOL pbignoreDSErrors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET parseBinary <1610743820> ( _            ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbparseBinary
   ' =====================================================================================
   PROPERTY SET parseBinary <1610743820> ( _            ' VTable offset = 80
     BYVAL pbparseBinary AS INTEGER _                   ' __in VARIANT_BOOL pbparseBinary
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET binaryFormat <1610743822> ( _           ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pszbinaryFormat
   ' =====================================================================================
   PROPERTY SET binaryFormat <1610743822> ( _           ' VTable offset = 88
     BYVAL pszbinaryFormat AS WSTRING _                 ' __in BSTR pszbinaryFormat
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMADSInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMNetMonInputContext
' IID = {3837E95F-07DB-4D09-99CD-586B4E094208}
' NetMon Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMNetMonInputContext_INTERFACE_DEFINED)
    %ICOMNetMonInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMNetMonInputContext $IID_ICOMNetMonInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET fMode <1610743808> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pszfMode
   ' =====================================================================================
   PROPERTY SET fMode <1610743808> ( _                  ' VTable offset = 32
     BYVAL pszfMode AS WSTRING _                        ' __in BSTR pszfMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET binaryFormat <1610743810> ( _           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszbinaryFormat
   ' =====================================================================================
   PROPERTY SET binaryFormat <1610743810> ( _           ' VTable offset = 40
     BYVAL pszbinaryFormat AS WSTRING _                 ' __in BSTR pszbinaryFormat
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMNetMonInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMXMLInputContext
' IID = {72B09A81-FB17-4187-B5F8-AD7E9592548E}
' XML Input Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMXMLInputContext_INTERFACE_DEFINED)
    %ICOMXMLInputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMXMLInputContext $IID_ICOMXMLInputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET rootXPath <1610743808> ( _              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pszrootXPath
   ' =====================================================================================
   PROPERTY SET rootXPath <1610743808> ( _              ' VTable offset = 32
     BYVAL pszrootXPath AS WSTRING _                    ' __in BSTR pszrootXPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fMode <1610743810> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszfMode
   ' =====================================================================================
   PROPERTY SET fMode <1610743810> ( _                  ' VTable offset = 40
     BYVAL pszfMode AS WSTRING _                        ' __in BSTR pszfMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET iTsFormat <1610743812> ( _              ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET iTsFormat <1610743812> ( _              ' VTable offset = 48
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dtNodes <1610743814> ( _                ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pndtNodes
   ' =====================================================================================
   PROPERTY SET dtNodes <1610743814> ( _                ' VTable offset = 56
     BYVAL pndtNodes AS LONG _                          ' __in int pndtNodes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fNames <1610743816> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszfNames
   ' =====================================================================================
   PROPERTY SET fNames <1610743816> ( _                 ' VTable offset = 64
     BYVAL pszfNames AS WSTRING _                       ' __in BSTR pszfNames
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMXMLInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMNativeOutputContext
' IID = {1979F191-21AA-489D-BCDC-8CB6DC60AF42}
' Native Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMNativeOutputContext_INTERFACE_DEFINED)
    %ICOMNativeOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMNativeOutputContext $IID_ICOMNativeOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET printHeaders <1610743808> ( _           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbprintHeaders
   ' =====================================================================================
   PROPERTY SET printHeaders <1610743808> ( _           ' VTable offset = 32
     BYVAL pbprintHeaders AS INTEGER _                  ' __in VARIANT_BOOL pbprintHeaders
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET headers <1610743810> ( _                ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbprintHeaders
   ' =====================================================================================
   PROPERTY SET headers <1610743810> ( _                ' VTable offset = 40
     BYVAL pbprintHeaders AS INTEGER _                  ' __in VARIANT_BOOL pbprintHeaders
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rowsToPrint <1610743812> ( _            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rowsToPrint <1610743812> ( _            ' VTable offset = 48
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rtp <1610743814> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rtp <1610743814> ( _                    ' VTable offset = 56
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET columnSpacing <1610743816> ( _          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbcolumnSpacing
   ' =====================================================================================
   PROPERTY SET columnSpacing <1610743816> ( _          ' VTable offset = 64
     BYVAL pbcolumnSpacing AS INTEGER _                 ' __in VARIANT_BOOL pbcolumnSpacing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET spaceCol <1610743818> ( _               ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbcolumnSpacing
   ' =====================================================================================
   PROPERTY SET spaceCol <1610743818> ( _               ' VTable offset = 72
     BYVAL pbcolumnSpacing AS INTEGER _                 ' __in VARIANT_BOOL pbcolumnSpacing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rightAlignment <1610743820> ( _         ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbrightAlignment
   ' =====================================================================================
   PROPERTY SET rightAlignment <1610743820> ( _         ' VTable offset = 80
     BYVAL pbrightAlignment AS INTEGER _                ' __in VARIANT_BOOL pbrightAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rAlign <1610743822> ( _                 ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbrightAlignment
   ' =====================================================================================
   PROPERTY SET rAlign <1610743822> ( _                 ' VTable offset = 88
     BYVAL pbrightAlignment AS INTEGER _                ' __in VARIANT_BOOL pbrightAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET separatorString <1610743824> ( _        ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparatorString
   ' =====================================================================================
   PROPERTY SET separatorString <1610743824> ( _        ' VTable offset = 96
     BYVAL pszseparatorString AS WSTRING _              ' __in BSTR pszseparatorString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET colSep <1610743826> ( _                 ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparatorString
   ' =====================================================================================
   PROPERTY SET colSep <1610743826> ( _                 ' VTable offset = 104
     BYVAL pszseparatorString AS WSTRING _              ' __in BSTR pszseparatorString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET direct <1610743828> ( _                 ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbdirect
   ' =====================================================================================
   PROPERTY SET direct <1610743828> ( _                 ' VTable offset = 112
     BYVAL pbdirect AS INTEGER _                        ' __in VARIANT_BOOL pbdirect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743830> ( _               ' VTable offset = 116
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743830> ( _               ' VTable offset = 120
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743832> ( _              ' VTable offset = 124
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743832> ( _              ' VTable offset = 128
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743834> ( _               ' VTable offset = 132
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743834> ( _               ' VTable offset = 136
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMNativeOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMW3COutputContext
' IID = {9F3A6096-C1A3-428D-BE12-EEA7CDB3627F}
' W3C Extended Log Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMW3COutputContext_INTERFACE_DEFINED)
    %ICOMW3COutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMW3COutputContext $IID_ICOMW3COutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET rowsToPrint <1610743808> ( _            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rowsToPrint <1610743808> ( _            ' VTable offset = 32
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rtp <1610743810> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rtp <1610743810> ( _                    ' VTable offset = 40
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743812> ( _               ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743812> ( _               ' VTable offset = 48
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743814> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743814> ( _              ' VTable offset = 56
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET useDoubleQuotes <1610743816> ( _        ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDoubleQuotes
   ' =====================================================================================
   PROPERTY SET useDoubleQuotes <1610743816> ( _        ' VTable offset = 64
     BYVAL pbuseDoubleQuotes AS INTEGER _               ' __in VARIANT_BOOL pbuseDoubleQuotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oDQuotes <1610743818> ( _               ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbuseDoubleQuotes
   ' =====================================================================================
   PROPERTY SET oDQuotes <1610743818> ( _               ' VTable offset = 72
     BYVAL pbuseDoubleQuotes AS INTEGER _               ' __in VARIANT_BOOL pbuseDoubleQuotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oDirTime <1610743820> ( _               ' VTable offset = 76
   ) AS WSTRING                                         '__retval_out BSTR* pszdirTime
   ' =====================================================================================
   PROPERTY SET oDirTime <1610743820> ( _               ' VTable offset = 80
     BYVAL pszdirTim AS WSTRING _                       ' __in BSTR pszdirTim
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET encodeDelim <1610743822> ( _            ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbencodeDelim
   ' =====================================================================================
   PROPERTY SET encodeDelim <1610743822> ( _            ' VTable offset = 88
     BYVAL pbencodeDelim AS INTEGER _                   ' __in VARIANT_BOOL pbencodeDelim
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743824> ( _               ' VTable offset = 96
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMW3COutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMIISOutputContext
' IID = {7A5A3711-A707-4381-9C86-9ECADFB88975}
' IIS Log Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMIISOutputContext_INTERFACE_DEFINED)
    %ICOMIISOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMIISOutputContext $IID_ICOMIISOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET rowsToPrint <1610743808> ( _            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rowsToPrint <1610743808> ( _            ' VTable offset = 32
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rtp <1610743810> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rtp <1610743810> ( _                    ' VTable offset = 40
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743812> ( _               ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743812> ( _               ' VTable offset = 48
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743814> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743814> ( _              ' VTable offset = 56
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743816> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743816> ( _               ' VTable offset = 64
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMIISOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMSQLOutputContext
' IID = {023D89CA-32BE-44DC-B442-478EC7478D62}
' SQL Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMSQLOutputContext_INTERFACE_DEFINED)
    %ICOMSQLOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMSQLOutputContext $IID_ICOMSQLOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET oConnString <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pszconnString
   ' =====================================================================================
   PROPERTY SET oConnString <1610743808> ( _            ' VTable offset = 32
     BYVAL pszconnString AS WSTRING _                   ' __in BSTR pszconnString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DSNname <1610743810> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszDSNName
   ' =====================================================================================
   PROPERTY SET DSNname <1610743810> ( _                ' VTable offset = 40
     BYVAL pszDSNName AS WSTRING _                      ' __in BSTR pszDSNName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dsn <1610743812> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pszDSNName
   ' =====================================================================================
   PROPERTY SET dsn <1610743812> ( _                    ' VTable offset = 48
     BYVAL pszDSNName AS WSTRING _                      ' __in BSTR pszDSNName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET server <1610743814> ( _                 ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pszserver
   ' =====================================================================================
   PROPERTY SET server <1610743814> ( _                 ' VTable offset = 56
     BYVAL pszserver AS WSTRING _                       ' __in BSTR pszserver
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET driver <1610743816> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszdriver
   ' =====================================================================================
   PROPERTY SET driver <1610743816> ( _                 ' VTable offset = 64
     BYVAL pszdriver AS WSTRING _                       ' __in BSTR pszdriver
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET database <1610743818> ( _               ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pszdatabase
   ' =====================================================================================
   PROPERTY SET database <1610743818> ( _               ' VTable offset = 72
     BYVAL pszdatabase AS WSTRING _                     ' __in BSTR pszdatabase
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET username <1610743820> ( _               ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pszusername
   ' =====================================================================================
   PROPERTY SET username <1610743820> ( _               ' VTable offset = 80
     BYVAL pszusername AS WSTRING _                     ' __in BSTR pszusername
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET password <1610743822> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pszpassword
   ' =====================================================================================
   PROPERTY SET password <1610743822> ( _               ' VTable offset = 88
     BYVAL pszpassword AS WSTRING _                     ' __in BSTR pszpassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET createTable <1610743824> ( _            ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbcreateTable
   ' =====================================================================================
   PROPERTY SET createTable <1610743824> ( _            ' VTable offset = 96
     BYVAL pbcreateTable AS INTEGER _                   ' __in VARIANT_BOOL pbcreateTable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET clearTable <1610743826> ( _             ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbclearTable
   ' =====================================================================================
   PROPERTY SET clearTable <1610743826> ( _             ' VTable offset = 104
     BYVAL pbclearTable AS INTEGER _                    ' __in VARIANT_BOOL pbclearTable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fixColNames <1610743828> ( _            ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbFixColNames
   ' =====================================================================================
   PROPERTY SET fixColNames <1610743828> ( _            ' VTable offset = 112
     BYVAL pbFixColNames AS INTEGER _                   ' __in VARIANT_BOOL pbFixColNames
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET maxStrFieldLen <1610743830> ( _         ' VTable offset = 116
   ) AS LONG                                            ' __retval_out int* pnmaxStrFieldLen
   ' =====================================================================================
   PROPERTY SET maxStrFieldLen <1610743830> ( _         ' VTable offset = 120
     BYVAL pnmaxStrFieldLen AS LONG _                   ' __in int pnmaxStrFieldLen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET transactionRowCount <1610743832> ( _    ' VTable offset = 124
   ) AS LONG                                            ' __retval_out int* pntransactionRowCount
   ' =====================================================================================
   PROPERTY SET transactionRowCount <1610743832> ( _    ' VTable offset = 128
     BYVAL pntransactionRowCount AS LONG _              ' __in int pntransactionRowCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreMinWarns <1610743834> ( _         ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreMinorWarns
   ' =====================================================================================
   PROPERTY SET ignoreMinWarns <1610743834> ( _         ' VTable offset = 136
     BYVAL pbignoreMinorWarns AS INTEGER _              ' __in VARIANT_BOOL pbignoreMinorWarns
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreIdCols <1610743836> ( _           ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreIdCols
   ' =====================================================================================
   PROPERTY SET ignoreIdCols <1610743836> ( _           ' VTable offset = 144
     BYVAL pbignoreIdCols AS INTEGER _                  ' __in VARIANT_BOOL pbignoreIdCols
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMSQLOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMCSVOutputContext
' IID = {FB96582A-63D4-4564-A65A-26EB352734FA}
' CSV Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMCSVOutputContext_INTERFACE_DEFINED)
    %ICOMCSVOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMCSVOutputContext $IID_ICOMCSVOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET headers <1610743808> ( _                ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT* pVaHeaders
   ' =====================================================================================
   PROPERTY SET headers <1610743808> ( _                ' VTable offset = 32
     BYVAL pVaHeaders AS VARIANT _                      ' __in VARIANT pVaHeaders
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oDQuotes <1610743810> ( _               ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT* pVaoDQuotes
   ' =====================================================================================
   PROPERTY SET oDQuotes <1610743810> ( _               ' VTable offset = 40
     BYVAL pVaoDQuotes AS VARIANT _                     ' __in VARIANT pVaoDQuotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET tabs <1610743812> ( _                   ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbtabs
   ' =====================================================================================
   PROPERTY SET tabs <1610743812> ( _                   ' VTable offset = 48
     BYVAL pbtabs AS INTEGER _                          ' __in VARIANT_BOOL pbtabs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timestampFormat <1610743814> ( _        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET timestampFormat <1610743814> ( _        ' VTable offset = 56
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oTsFormat <1610743816> ( _              ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET oTsFormat <1610743816> ( _              ' VTable offset = 64
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743818> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743818> ( _               ' VTable offset = 72
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743820> ( _              ' VTable offset = 76
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743820> ( _              ' VTable offset = 80
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743822> ( _               ' VTable offset = 88
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMCSVOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMXMLOutputContext
' IID = {5481A119-1977-4190-B585-C62373A6A024}
' XML Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMXMLOutputContext_INTERFACE_DEFINED)
    %ICOMXMLOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMXMLOutputContext $IID_ICOMXMLOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET structure <1610743808> ( _              ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnstructure
   ' =====================================================================================
   PROPERTY SET structure <1610743808> ( _              ' VTable offset = 32
     BYVAL pnstructure AS LONG _                        ' __in int pnstructure
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rootName <1610743810> ( _               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszrootName
   ' =====================================================================================
   PROPERTY SET rootName <1610743810> ( _               ' VTable offset = 40
     BYVAL pszrootName AS WSTRING _                     ' __in BSTR pszrootName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rowName <1610743812> ( _                ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pszrowName
   ' =====================================================================================
   PROPERTY SET rowName <1610743812> ( _                ' VTable offset = 48
     BYVAL pszrowName AS WSTRING _                      ' __in BSTR pszrowName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fieldName <1610743814> ( _              ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pszfieldName
   ' =====================================================================================
   PROPERTY SET fieldName <1610743814> ( _              ' VTable offset = 56
     BYVAL pszfieldName AS WSTRING _                    ' __in BSTR pszfieldName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET xslLink <1610743816> ( _                ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszxslLink
   ' =====================================================================================
   PROPERTY SET xslLink <1610743816> ( _                ' VTable offset = 64
     BYVAL pszxslLink AS WSTRING _                      ' __in BSTR pszxslLink
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET schemaType <1610743818> ( _             ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* pnschemaType
   ' =====================================================================================
   PROPERTY SET schemaType <1610743818> ( _             ' VTable offset = 72
     BYVAL pnschemaType AS LONG _                       ' __in int pnschemaType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET compact <1610743820> ( _                ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbcompact
   ' =====================================================================================
   PROPERTY SET compact <1610743820> ( _                ' VTable offset = 80
     BYVAL pbcompact AS INTEGER _                       ' __in VARIANT_BOOL pbcompact
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET noEmptyField <1610743822> ( _           ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbnoEmptyField
   ' =====================================================================================
   PROPERTY SET noEmptyField <1610743822> ( _           ' VTable offset = 88
     BYVAL pbnoEmptyField AS INTEGER _                  ' __in VARIANT_BOOL pbnoEmptyField
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET standAlone <1610743824> ( _             ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbstandAlone
   ' =====================================================================================
   PROPERTY SET standAlone <1610743824> ( _             ' VTable offset = 96
     BYVAL pbstandAlone AS INTEGER _                    ' __in VARIANT_BOOL pbstandAlone
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743826> ( _               ' VTable offset = 100
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743826> ( _               ' VTable offset = 104
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743828> ( _               ' VTable offset = 112
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743830> ( _              ' VTable offset = 116
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743830> ( _              ' VTable offset = 120
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMXMLOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMTemplateOutputContext
' IID = {2547428D-535E-4467-9C0C-77511E47BE0D}
' Template Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMTemplateOutputContext_INTERFACE_DEFINED)
    %ICOMTemplateOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMTemplateOutputContext $IID_ICOMTemplateOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET tpl <1610743808> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* psztpl
   ' =====================================================================================
   PROPERTY SET tpl <1610743808> ( _                    ' VTable offset = 32
     BYVAL psztpl AS WSTRING _                          ' __in BSTR psztpl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET tplHeader <1610743810> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* psztplHeader
   ' =====================================================================================
   PROPERTY SET tplHeader <1610743810> ( _              ' VTable offset = 40
     BYVAL psztplHeader AS WSTRING _                    ' __in BSTR psztplHeader
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET tplFooter <1610743812> ( _              ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* psztplFooter
   ' =====================================================================================
   PROPERTY SET tplFooter <1610743812> ( _              ' VTable offset = 48
     BYVAL psztplFooter AS WSTRING _                    ' __in BSTR psztplFooter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET noEmptyFile <1610743814> ( _            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbnoEmptyFile
   ' =====================================================================================
   PROPERTY SET noEmptyFile <1610743814> ( _            ' VTable offset = 56
     BYVAL pbnoEmptyFile AS INTEGER _                   ' __in VARIANT_BOOL pbnoEmptyFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743816> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743816> ( _               ' VTable offset = 64
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743818> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743818> ( _               ' VTable offset = 72
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743820> ( _              ' VTable offset = 76
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743820> ( _              ' VTable offset = 80
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMTemplateOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMDataGridOutputContext
' IID = {2690326C-0A98-41A0-A53A-BE0D58F0E936}
' DataGrid Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMDataGridOutputContext_INTERFACE_DEFINED)
    %ICOMDataGridOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMDataGridOutputContext $IID_ICOMDataGridOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET rowsToPrint <1610743808> ( _            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rowsToPrint <1610743808> ( _            ' VTable offset = 32
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rtp <1610743810> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int* pnrowsToPrint
   ' =====================================================================================
   PROPERTY SET rtp <1610743810> ( _                    ' VTable offset = 40
     BYVAL pnrowsToPrint AS LONG _                      ' __in int pnrowsToPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET autoScroll <1610743812> ( _             ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbautoScroll
   ' =====================================================================================
   PROPERTY SET autoScroll <1610743812> ( _             ' VTable offset = 48
     BYVAL pbautoScroll AS INTEGER _                    ' __in VARIANT_BOOL pbautoScroll
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMDataGridOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMChartOutputContext
' IID = {C0D19115-1C4F-4A49-A02C-60BF913BEFF9}
' Chart Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMChartOutputContext_INTERFACE_DEFINED)
    %ICOMChartOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMChartOutputContext $IID_ICOMChartOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET chartType <1610743808> ( _              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* psztype
   ' =====================================================================================
   PROPERTY SET chartType <1610743808> ( _              ' VTable offset = 32
     BYVAL psztype AS WSTRING _                         ' __in BSTR psztype
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET categories <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszcategories
   ' =====================================================================================
   PROPERTY SET categories <1610743810> ( _             ' VTable offset = 40
     BYVAL pszcategories AS WSTRING _                   ' __in BSTR pszcategories
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET maxCategoryLabels <1610743812> ( _      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pnmaxCategoryLabels
   ' =====================================================================================
   PROPERTY SET maxCategoryLabels <1610743812> ( _      ' VTable offset = 48
     BYVAL pnmaxCategoryLabels AS LONG _                ' __in int pnmaxCategoryLabels
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET legend <1610743814> ( _                 ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pszlegend
   ' =====================================================================================
   PROPERTY SET legend <1610743814> ( _                 ' VTable offset = 56
     BYVAL pszlegend AS WSTRING _                       ' __in BSTR pszlegend
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET values <1610743816> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pszvalues
   ' =====================================================================================
   PROPERTY SET values <1610743816> ( _                 ' VTable offset = 64
     BYVAL pszvalues AS WSTRING _                       ' __in BSTR pszvalues
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET groupSize <1610743818> ( _              ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pszgroupSize
   ' =====================================================================================
   PROPERTY SET groupSize <1610743818> ( _              ' VTable offset = 72
     BYVAL pszgroupSize AS WSTRING _                    ' __in BSTR pszgroupSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileType <1610743820> ( _               ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pszfileType
   ' =====================================================================================
   PROPERTY SET fileType <1610743820> ( _               ' VTable offset = 80
     BYVAL pszfileType AS WSTRING _                     ' __in BSTR pszfileType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET config <1610743822> ( _                 ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pszconfig
   ' =====================================================================================
   PROPERTY SET config <1610743822> ( _                 ' VTable offset = 88
     BYVAL pszconfig AS WSTRING _                       ' __in BSTR pszconfig
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET chartTitle <1610743824> ( _             ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pszchartTitle
   ' =====================================================================================
   PROPERTY SET chartTitle <1610743824> ( _             ' VTable offset = 96
     BYVAL pszchartTitle AS WSTRING _                   ' __in BSTR pszchartTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timestampFormat <1610743826> ( _        ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET timestampFormat <1610743826> ( _        ' VTable offset = 104
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oTsFormat <1610743828> ( _              ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET oTsFormat <1610743828> ( _              ' VTable offset = 112
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET view <1610743830> ( _                   ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbview
   ' =====================================================================================
   PROPERTY SET view <1610743830> ( _                   ' VTable offset = 120
     BYVAL pbview AS INTEGER _                          ' __in VARIANT_BOOL pbview
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMChartOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMSYSLOGOutputContext
' IID = {B0936B89-8035-42CE-A33C-9E2E22DEADD2}
' SYSLOG Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMSYSLOGOutputContext_INTERFACE_DEFINED)
    %ICOMSYSLOGOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMSYSLOGOutputContext $IID_ICOMSYSLOGOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET conf <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pszconf
   ' =====================================================================================
   PROPERTY SET conf <1610743808> ( _                   ' VTable offset = 32
     BYVAL pszconf AS WSTRING _                         ' __in BSTR pszconf
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET severity <1610743810> ( _               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbszSeverity
   ' =====================================================================================
   PROPERTY SET severity <1610743810> ( _               ' VTable offset = 40
     BYVAL pbszSeverity AS WSTRING _                    ' __in BSTR pbszSeverity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET facility <1610743812> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbszFacility
   ' =====================================================================================
   PROPERTY SET facility <1610743812> ( _               ' VTable offset = 48
     BYVAL pbszFacility AS WSTRING _                    ' __in BSTR pbszFacility
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timestampFormat <1610743814> ( _        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET timestampFormat <1610743814> ( _        ' VTable offset = 56
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oTsFormat <1610743816> ( _              ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET oTsFormat <1610743816> ( _              ' VTable offset = 64
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hostName <1610743818> ( _               ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pszhostName
   ' =====================================================================================
   PROPERTY SET hostName <1610743818> ( _               ' VTable offset = 72
     BYVAL pszhostName AS WSTRING _                     ' __in BSTR pszhostName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET processName <1610743820> ( _            ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pszprocessName
   ' =====================================================================================
   PROPERTY SET processName <1610743820> ( _            ' VTable offset = 80
     BYVAL pszprocessName AS WSTRING _                  ' __in BSTR pszprocessName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET separator <1610743822> ( _              ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparator
   ' =====================================================================================
   PROPERTY SET separator <1610743822> ( _              ' VTable offset = 88
     BYVAL pszseparator AS WSTRING _                    ' __in BSTR pszseparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET maxPacketSize <1610743824> ( _          ' VTable offset = 92
   ) AS LONG                                            ' __retval_out int* pnmaxPacketSize
   ' =====================================================================================
   PROPERTY SET maxPacketSize <1610743824> ( _          ' VTable offset = 96
     BYVAL pnmaxPacketSize AS LONG _                    ' __in int pnmaxPacketSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET protocol <1610743826> ( _               ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* pszprotocol
   ' =====================================================================================
   PROPERTY SET protocol <1610743826> ( _               ' VTable offset = 104
     BYVAL pszprotocol AS WSTRING _                     ' __in BSTR pszprotocol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET sourcePort <1610743828> ( _             ' VTable offset = 108
   ) AS LONG                                            ' __retval_out int* pnsourcePort
   ' =====================================================================================
   PROPERTY SET sourcePort <1610743828> ( _             ' VTable offset = 112
     BYVAL pnsourcePort AS LONG _                       ' __in int pnsourcePort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ignoreDspchErrs <1610743830> ( _        ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbignoreDspchErrs
   ' =====================================================================================
   PROPERTY SET ignoreDspchErrs <1610743830> ( _        ' VTable offset = 120
     BYVAL pbignoreDspchErrs AS INTEGER _               ' __in VARIANT_BOOL pbignoreDspchErrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET discardOversized <1610743832> ( _       ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbdiscardOversized
   ' =====================================================================================
   PROPERTY SET discardOversized <1610743832> ( _       ' VTable offset = 128
     BYVAL pbdiscardOversized AS INTEGER _              ' __in VARIANT_BOOL pbdiscardOversized
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743834> ( _              ' VTable offset = 132
   ) AS LONG                                            ' __retval_out int* pncodepag
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743834> ( _              ' VTable offset = 136
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMSYSLOGOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICOMTSVOutputContext
' IID = {8819BA1E-1931-4CCF-9F71-64547651AA54}
' TSV Output Format
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICOMTSVOutputContext_INTERFACE_DEFINED)
    %ICOMTSVOutputContext_INTERFACE_DEFINED = 1

INTERFACE ICOMTSVOutputContext $IID_ICOMTSVOutputContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET headers <1610743808> ( _                ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT* pVaHeaders
   ' =====================================================================================
   PROPERTY SET headers <1610743808> ( _                ' VTable offset = 32
     BYVAL pVaHeaders AS VARIANT _                      ' __in VARIANT pVaHeaders
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET separator <1610743810> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparator
   ' =====================================================================================
   PROPERTY SET separator <1610743810> ( _              ' VTable offset = 40
     BYVAL pszseparator AS WSTRING _                    ' __in BSTR pszseparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oSeparator <1610743812> ( _             ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pszseparator
   ' =====================================================================================
   PROPERTY SET oSeparator <1610743812> ( _             ' VTable offset = 48
     BYVAL pszseparator AS WSTRING _                    ' __in BSTR pszseparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timestampFormat <1610743814> ( _        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET timestampFormat <1610743814> ( _        ' VTable offset = 56
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oTsFormat <1610743816> ( _              ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* psztimestampFormat
   ' =====================================================================================
   PROPERTY SET oTsFormat <1610743816> ( _              ' VTable offset = 64
     BYVAL psztimestampFormat AS WSTRING _              ' __in BSTR psztimestampFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET codepage <1610743818> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET codepage <1610743818> ( _               ' VTable offset = 72
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET oCodepage <1610743820> ( _              ' VTable offset = 76
   ) AS LONG                                            ' __retval_out int* pncodepage
   ' =====================================================================================
   PROPERTY SET oCodepage <1610743820> ( _              ' VTable offset = 80
     BYVAL pncodepage AS LONG _                         ' __in int pncodepage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fileMode <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out int* pnfilemode
   ' =====================================================================================
   PROPERTY SET fileMode <1610743822> ( _               ' VTable offset = 88
     BYVAL pnfilemode AS LONG _                         ' __in int pnfilemode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMTSVOutputContext_INTERFACE_DEFINED__ */
