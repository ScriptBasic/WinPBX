' ########################################################################################
' Microsoft Windows
' File: iisrsta.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IISRSTA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "winsvc.inc"

$IID_IIisServiceControl  = GUID$("{E8FB8620-588F-11D2-9D61-00C04F79C5FE}")
$CLSID_IisServiceControl = GUID$("{E8FB8621-588F-11D2-9D61-00C04F79C5FE}")
$LIBID_IISRSTALib        = GUID$("{E8FB8614-588F-11D2-9D61-00C04F79C5FE}")

' ########################################################################################
' Interface name = IIisServiceControl
' IID = E8FB8620-588F-11D2-9D61-00C04F79C5FE
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IIisServiceControl_INTERFACE_DEFINED)
    %IIisServiceControl_INTERFACE_DEFINED = 1

INTERFACE IIisServiceControl $IID_IIisServiceControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 28
     BYVAL dwTimeoutMsecs AS DWORD _                    ' __in DWORD dwTimeoutMsecs
   , BYVAL dwForce AS DWORD _                           ' __in DWORD dwForce
   )                                                    ' void
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 32
     BYVAL dwTimeoutMsecs AS DWORD _                    ' __in DWORD dwTimeoutMsecs
   )                                                    ' void
   ' =====================================================================================
   METHOD Reboot ( _                                    ' VTable offset = 36
     BYVAL dwTimeouMsecs AS DWORD _                     ' __in DWORD dwTimeouMsecs
   , BYVAL dwForceAppsClosed AS DWORD _                 ' __in DWORD dwForceAppsClosed
   )                                                    ' void
   ' =====================================================================================
   METHOD Status ( _                                    ' VTable offset = 40
     BYVAL dwBufferSize AS DWORD _                      ' __in  DWORD dwBufferSize
   , BYVAL pbBuffer AS DWORD _                          ' __out unsigned char *pbBuffer
   , BYREF pdwMDRequiredBufferSize AS DWORD _           ' __out DWORD *pdwMDRequiredBufferSize
   , BYREF pdwNumServices AS DWORD _                    ' __out DWORD *pdwNumServices
   )                                                    ' void
   ' =====================================================================================
   METHOD Kill ( _                                      ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIisServiceControl_INTERFACE_DEFINED__ */

' // Size = 36 bytes
TYPE SERIALIZED_ENUM_SERVICE_STATUS DWORD
   iServiceName  AS DWORD            ' DWORD
   iDisplayName  AS DWORD            ' DWORD
   ServiceStatus AS SERVICE_STATUS   ' SERVICE_STATUS
END TYPE
