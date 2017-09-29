' ########################################################################################
' Microsoft Windows
' File: SensEvts.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SensEvents
' Version: 2.0
' Documentation string: SENS Events Type Library
' Path: C:\WINDOWS\system32\SENS.DLL
' Library GUID: {D597DEED-5B9F-11D1-8DD2-00AA004ABD5E}
' ########################################################################################

#INCLUDE THIS ONCE
%SENSEVTS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"

$LIBID_SensEvents = GUID$("{D597DEED-5B9F-11D1-8DD2-00AA004ABD5E}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SENS = GUID$("{D597CAFE-5B9F-11D1-8DD2-00AA004ABD5E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISensLogon = GUID$("{D597BAB3-5B9F-11D1-8DD2-00AA004ABD5E}")
$IID_ISensLogon2 = GUID$("{D597BAB4-5B9F-11D1-8DD2-00AA004ABD5E}")
$IID_ISensNetwork = GUID$("{D597BAB1-5B9F-11D1-8DD2-00AA004ABD5E}")
$IID_ISensOnNow = GUID$("{D597BAB2-5B9F-11D1-8DD2-00AA004ABD5E}")

' ========================================================================================
' SENS_QOCINFO record
' IID = {D597FAD1-5B9F-11D1-8DD2-00AA004ABD5E}
' ========================================================================================

' // Size = 16 bytes
TYPE SENS_QOCINFO DWORD
   dwSize     AS DWORD
   dwFlags    AS DWORD
   dwOutSpeed AS DWORD
   dwInSpeed  AS DWORD
END TYPE


' ########################################################################################
' Interface name = ISensNetwork
' IID = {D597BAB1-5B9F-11D1-8DD2-00AA004ABD5E}
' SENS Network Events
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISensNetwork_INTERFACE_DEFINED)
    %ISensNetwork_INTERFACE_DEFINED = 1

INTERFACE ISensNetwork $IID_ISensNetwork

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ConnectionMade ( _                            ' VTable offset = 28
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL ulType AS DWORD _                            ' __in ULONG ulType
   , BYREF lpQOCInfo AS SENS_QOCINFO _                  ' __in LPSENS_QOCINFO lpQOCInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectionMadeNoQOCInfo ( _                   ' VTable offset = 32
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL ulType AS DWORD _                            ' __in ULONG ulType
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectionLost ( _                            ' VTable offset = 36
     BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL ulType AS DWORD _                            ' __in ULONG ulType
   )                                                    ' void
   ' =====================================================================================
   METHOD DestinationReachable ( _                      ' VTable offset = 40
     BYVAL bstrDestination AS WSTRING _                 ' __in BSTR bstrDestination
   , BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL ulType AS DWORD _                            ' __in ULONG ulType
   , BYREF lpQOCInfo AS SENS_QOCINFO _                  ' __in LPSENS_QOCINFO lpQOCInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD DestinationReachableNoQOCInfo ( _             ' VTable offset = 44
     BYVAL bstrDestination AS WSTRING _                 ' __in BSTR bstrDestination
   , BYVAL bstrConnection AS WSTRING _                  ' __in BSTR bstrConnection
   , BYVAL ulType AS DWORD _                            ' __in ULONG ulType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensNetwork_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISensOnNow
' IID = {D597BAB2-5B9F-11D1-8DD2-00AA004ABD5E}
' SENS OnNow Events
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISensOnNow_INTERFACE_DEFINED)
    %ISensOnNow_INTERFACE_DEFINED = 1

INTERFACE ISensOnNow $IID_ISensOnNow

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnACPower ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD OnBatteryPower ( _                            ' VTable offset = 32
     BYVAL dwBatteryLifePercent AS DWORD _              ' __in DWORD dwBatteryLifePercent
   )                                                    ' void
   ' =====================================================================================
   METHOD BatteryLow ( _                                ' VTable offset = 36
     BYVAL dwBatteryLifePercent AS DWORD _              ' __in DWORD dwBatteryLifePercent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensOnNow_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISensLogon
' IID = {D597BAB3-5B9F-11D1-8DD2-00AA004ABD5E}
' SENS WinLogon Events
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISensLogon_INTERFACE_DEFINED)
    %ISensLogon_INTERFACE_DEFINED = 1

INTERFACE ISensLogon $IID_ISensLogon

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 28
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD Logoff ( _                                    ' VTable offset = 32
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD StartShell ( _                                ' VTable offset = 36
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayLock ( _                               ' VTable offset = 40
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayUnlock ( _                             ' VTable offset = 44
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD StartScreenSaver ( _                          ' VTable offset = 48
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD StopScreenSaver ( _                           ' VTable offset = 52
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensLogon_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISensLogon2
' IID = {D597BAB4-5B9F-11D1-8DD2-00AA004ABD5E}
' SENS WinLogon2 Events
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISensLogon2_INTERFACE_DEFINED)
    %ISensLogon2_INTERFACE_DEFINED = 1

INTERFACE ISensLogon2 $IID_ISensLogon2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 28
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL dwSessionId AS DWORD _                       ' __in DWORD dwSessionId
   )                                                    ' void
   ' =====================================================================================
   METHOD Logoff ( _                                    ' VTable offset = 32
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL dwSessionId AS DWORD _                       ' __in DWORD dwSessionId
   )                                                    ' void
   ' =====================================================================================
   METHOD SessionDisconnect ( _                         ' VTable offset = 36
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL dwSessionId AS DWORD _                       ' __in DWORD dwSessionId
   )                                                    ' void
   ' =====================================================================================
   METHOD SessionReconnect ( _                          ' VTable offset = 40
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL dwSessionId AS DWORD _                       ' __in DWORD dwSessionId
   )                                                    ' void
   ' =====================================================================================
   METHOD PostShell ( _                                 ' VTable offset = 44
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL dwSessionId AS DWORD _                       ' __in DWORD dwSessionId
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensLogon2_INTERFACE_DEFINED__ */
