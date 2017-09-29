' ########################################################################################
' Microsoft Windows
' File: ivalidator.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IVALIDATOR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ivehandler.inc"

' enum ValidatorFlags
%VALIDATOR_EXTRA_VERBOSE       = &H1
%VALIDATOR_SHOW_SOURCE_LINES   = &H2
%VALIDATOR_CHECK_ILONLY        = &H4
%VALIDATOR_CHECK_PEFORMAT_ONLY = &H8
%VALIDATOR_NOCHECK_PEFORMAT    = &H10
%VALIDATOR_TRANSPARENT_ONLY    = &H20

' ########################################################################################
' Interface name = IValidator
' IID = {63DF8730-DC81-4062-84A2-1FF943F59FAC}
' Inherited interface = IUnknown
' Provides methods for validating portable executable (PE) images and reporting
' validation errors.
' ########################################################################################

#IF NOT %DEF(%IValidator_INTERFACE_DEFINED)
    %IValidator_INTERFACE_DEFINED = 1

$IID_IValidator = GUID$("{63DF8730-DC81-4062-84A2-1FF943F59FAC}")

INTERFACE IValidator $IID_IValidator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Validate ( _                                  ' VTable offset = 12
     BYVAL veh AS IVEHandler _                          ' __in IVEHandler *veh
   , BYVAL pAppDomain AS IUnknown _                     ' __in IUnknown *pAppDomain
   , BYVAL ulFlags AS DWORD _                           ' __in unsigned long ulFlags
   , BYVAL ulMaxError AS DWORD _                        ' __in unsigned long ulMaxError
   , BYVAL token AS DWORD _                             ' __in unsigned long token
   , BYREF fileName AS WSTRINGZ _                       ' __in LPWSTR fileName
   , BYREF pe AS BYTE _                                 ' __in BYTE *pe
   , BYVAL ulSize AS DWORD _                            ' __in unsigned long ulSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatEventInfo ( _                           ' VTable offset = 16
     BYVAL hVECode AS LONG _                            ' __in HRESULT hVECode
   , BYVAL Context AS VEContext _                       ' __in VEContext Context
   , BYREF msg AS WSTRINGZ _                            ' __inout LPWSTR msg
   , BYVAL ulMaxLength AS DWORD _                       ' __in unsigned long ulMaxLength
   , BYVAL psa AS DWORD _                               ' __in SAFEARRAY * psa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IValidator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRValidator
' IID = {63DF8730-DC81-4062-84A2-1FF943F59FDD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRValidator_INTERFACE_DEFINED)
    %ICLRValidator_INTERFACE_DEFINED = 1

$IID_ICLRValidator = GUID$("{63DF8730-DC81-4062-84A2-1FF943F59FDD}")

INTERFACE ICLRValidator $IID_ICLRValidator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Validate ( _                                  ' VTable offset = 12
     BYVAL veh AS IVEHandler _                          ' __in IVEHandler *veh
   , BYVAL ulAppDomainId AS DWORD _                     ' __in unsigned long ulAppDomainId
   , BYVAL ulFlags AS DWORD _                           ' __in unsigned long ulFlags
   , BYVAL ulMaxError AS DWORD _                        ' __in unsigned long ulMaxError
   , BYVAL token AS DWORD _                             ' __in unsigned long token
   , BYREF fileName AS WSTRINGZ _                       ' __in LPWSTR fileName
   , BYREF pe AS BYTE _                                 ' __in BYTE *pe
   , BYVAL ulSize AS DWORD _                            ' __in unsigned long ulSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatEventInfo ( _                           ' VTable offset = 16
     BYVAL hVECode AS LONG _                            ' __in HRESULT hVECode
   , BYVAL Context AS VEContext _                       ' __in VEContext Context
   , BYREF msg AS WSTRINGZ _                            ' __inout LPWSTR msg
   , BYVAL ulMaxLength AS DWORD _                       ' __in unsigned long ulMaxLength
   , BYVAL psa AS DWORD _                               ' __in SAFEARRAY * psa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRValidator_INTERFACE_DEFINED__ */
