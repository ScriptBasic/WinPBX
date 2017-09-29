' ########################################################################################
' Microsoft Windows
' File: CertPol.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTPOL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "certmod.inc"

' ########################################################################################
' Interface name = ICertPolicy
' IID = 38BB5A00-7636-11D0-B413-00A0C91BBF8C
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertPolicy_INTERFACE_DEFINED)
    %ICertPolicy_INTERFACE_DEFINED = 1

$IID_ICertPolicy = GUID$("{38BB5A00-7636-11D0-B413-00A0C91BBF8C}")

INTERFACE ICertPolicy $IID_ICertPolicy

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD VerifyRequest ( _                             ' VTable offset = 32
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Context AS LONG _                            ' __in LONG Context
   , BYVAL bNewRequest AS LONG _                        ' __in LONG bNewRequest
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDescription
   ' =====================================================================================
   METHOD ShutDown ( _                                  ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPolicy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertPolicy2
' IID = 3DB4910E-8001-4BF1-AA1B-F43A808317A0
' Inherited interface = ICertPolicy
' ########################################################################################

#IF NOT %DEF(%ICertPolicy2_INTERFACE_DEFINED)
    %ICertPolicy2_INTERFACE_DEFINED = 1

$IID_ICertPolicy2 = GUID$("{3DB4910E-8001-4BF1-AA1B-F43A808317A0}")

INTERFACE ICertPolicy2 $IID_ICertPolicy2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertPolicy methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD VerifyRequest ( _                             ' VTable offset = 32
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Context AS LONG _                            ' __in LONG Context
   , BYVAL bNewRequest AS LONG _                        ' __in LONG bNewRequest
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDescription
   ' =====================================================================================
   METHOD ShutDown ( _                                  ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPolicy2 method
   ' =====================================================================================
   METHOD GetManageModule ( _                           ' VTable offset = 44
   ) AS ICertManageModule                               ' __retval_out ICertManageModule **ppManageModule
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPolicy2_INTERFACE_DEFINED__ */
