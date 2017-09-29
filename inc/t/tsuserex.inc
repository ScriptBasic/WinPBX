' ########################################################################################
' Microsoft Windows
' File: tsuserex.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TSUSEREXLib
' Version: 1.0, Locale ID = 0
' Documentation string: tsexusrm 1.0 Type Library
' Path: C:\Archivos de programa\Microsoft Platform SDK for Windows Server 2003 R2\Lib\tsuserex.tlb
' Library GUID: {45413F04-DF86-11D1-AE27-00C04FA35813}
' ########################################################################################

#INCLUDE THIS ONCE
%TSUSEREX_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mmc.inc"

$LIBID_TSUSEREXLib = GUID$("{45413F04-DF86-11D1-AE27-00C04FA35813}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {E2E9CAE6-1E7B-4B8E-BABD-E9BF6292AC29}
$PROGID_ADsTSUserEx = "tsuserex.ADsTSUserEx.1"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ADsTSUserEx = GUID$("{E2E9CAE6-1E7B-4B8E-BABD-E9BF6292AC29}")
$CLSID_TSUserExInterfaces = GUID$("{0910DD01-DF8C-11D1-AE27-00C04FA35813}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IADsTSUserEx = GUID$("{C4930E79-2989-4462-8A60-2FCF2F2955EF}")

' ########################################################################################
' Interface name = IADsTSUserEx
' IID = {C4930E79-2989-4462-8A60-2FCF2F2955EF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsTSUserEx_INTERFACE_DEFINED)
    %IADsTSUserEx_INTERFACE_DEFINED = 1

INTERFACE IADsTSUserEx $IID_IADsTSUserEx

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TerminalServicesProfilePath <1> ( _     ' VTable offset = 28
   ) AS WSTRING                                         ' _retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET TerminalServicesProfilePath <1> ( _     ' VTable offset = 32
     BYVAL pNewVal AS WSTRING _                         ' __in BSTR pNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TerminalServicesHomeDirectory <2> ( _   ' VTable offset = 36
   ) AS WSTRING                                         ' _retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET TerminalServicesHomeDirectory <2> ( _   ' VTable offset = 40
     BYVAL pNewVal AS WSTRING _                         ' __in BSTR pNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TerminalServicesHomeDrive <3> ( _       ' VTable offset = 44
   ) AS WSTRING                                         ' _retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET TerminalServicesHomeDrive <3> ( _       ' VTable offset = 48
     BYVAL pNewVal AS WSTRING _                         ' __in BSTR pNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowLogon <4> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET AllowLogon <4> ( _                      ' VTable offset = 56
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableRemoteControl <5> ( _             ' VTable offset = 60
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET EnableRemoteControl <5> ( _             ' VTable offset = 64
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxDisconnectionTime <6> ( _            ' VTable offset = 68
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET MaxDisconnectionTime <6> ( _            ' VTable offset = 72
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxConnectionTime <7> ( _               ' VTable offset = 76
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET MaxConnectionTime <7> ( _               ' VTable offset = 80
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxIdleTime <8> ( _                     ' VTable offset = 84
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET MaxIdleTime <8> ( _                     ' VTable offset = 88
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReconnectionAction <9> ( _              ' VTable offset = 92
   ) AS LONG                                            ' _retval_out LONG *pNewVal
   ' =====================================================================================
   PROPERTY SET ReconnectionAction <9> ( _              ' VTable offset = 96
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BrokenConnectionAction <10> ( _         ' VTable offset = 100
   ) AS LONG                                            ' _retval_out LONG *pNewVal
   ' =====================================================================================
   PROPERTY SET BrokenConnectionAction <10> ( _         ' VTable offset = 104
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectClientDrivesAtLogon <11> ( _     ' VTable offset = 108
   ) AS LONG                                            ' _retval_out LONG *pNewVal
   ' =====================================================================================
   PROPERTY SET ConnectClientDrivesAtLogon <11> ( _     ' VTable offset = 112
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectClientPrintersAtLogon <12> ( _   ' VTable offset = 116
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET ConnectClientPrintersAtLogon <12> ( _   ' VTable offset = 120
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultToMainPrinter <13> ( _           ' VTable offset = 124
   ) AS LONG                                            ' _retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET DefaultToMainPrinter <13> ( _           ' VTable offset = 128
     BYVAL NewVal AS LONG _                             ' __in LONG NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TerminalServicesWorkDirectory <14> ( _  ' VTable offset = 132
   ) AS WSTRING                                         ' _retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET TerminalServicesWorkDirectory <14> ( _  ' VTable offset = 136
     BYVAL pNewVal AS WSTRING _                         ' __in BSTR pNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TerminalServicesInitialProgram <15> ( _ ' VTable offset = 140
   ) AS WSTRING                                         ' _retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET TerminalServicesInitialProgram <15> ( _ ' VTable offset = 144
     BYVAL pNewVal AS WSTRING _                         ' __in pVal BSTR pNewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsTSUserEx_INTERFACE_DEFINED__ */
