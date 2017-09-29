' ########################################################################################
' Microsoft Windows
' File: errorrep.inc
' Contents: Functions used to report errors to Microsoft
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ERRORREP_INC = 1

#INCLUDE ONCE "windows.inc"

' enum tagEFaultRepRetVal
%frrvOk                 = 0
%frrvOkManifest         = 1
%frrvOkQueued           = 2
%frrvErr                = 3
%frrvErrNoDW            = 4
%frrvErrTimeout         = 5
%frrvLaunchDebugger     = 6
%frrvOkHeadless         = 7
%frrvErrAnotherInstance = 8

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReportFault LIB "FaultRep.dll" ALIAS "ReportFault" ( _
    BYVAL pep AS EXCEPTION_POINTERS PTR, _
    BYVAL dwOpt AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION ReportFault IMPORT "Faultrep.dll" ALIAS "ReportFault" ( _
   BYREF pep AS EXCEPTION_POINTERS _                    ' __in LPEXCEPTION_POINTERS pep
 , BYVAL dwOpt AS DWORD _                               ' __in DWORD dwOpt
 ) AS LONG                                              ' EFaultRepRetVal
#ENDIF

DECLARE FUNCTION AddERExcludedApplication IMPORT "Faultrep.dll" ALIAS "AddERExcludedApplicationA" ( _
   BYREF szApplication AS ASCIIZ _                      ' __in LPCSTR szApplication
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddERExcludedApplicationW IMPORT "Faultrep.dll" ALIAS "AddERExcludedApplicationW" ( _
   BYREF wszApplication AS WSTRINGZ _                   ' __in LPCWSTR wszApplication
 ) AS LONG                                              ' BOOL

'//
'//+++++++++++++++++++++ Hang reporting api ++++++++++++++++++++++++++++++++
'//

DECLARE FUNCTION WerReportHang IMPORT "Faultrep.dll" ALIAS "WerReportHang" ( _
   BYVAL hwndHungApp AS DWORD _                         ' __in HWND hwndHungApp
 , OPTIONAL BYREF pwzHungApplicationName AS WSTRINGZ _  ' __in_opt PCWSTR pwzHungApplicationName
 ) AS LONG                                              ' HRESULT
