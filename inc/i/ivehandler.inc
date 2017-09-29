' ########################################################################################
' Microsoft Windows
' File: ivehandler.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: VEHandlerLib
' Version: 1.0, Locale ID = 0
' Documentation string: Common Language Runtime Verification Event Handler 1.0 Type Library
' Library GUID: {856CA1B0-7DAB-11D3-ACEC-00C04F86C309}
' ########################################################################################

#INCLUDE THIS ONCE
%IVEHANDLER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

$LIBID_VEHandlerLib = GUID$("{856CA1B0-7DAB-11D3-ACEC-00C04F86C309}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_VEHandlerClass = GUID$("{856CA1B1-7DAB-11D3-ACEC-00C04F86C309}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IVEHandler = GUID$("{856CA1B2-7DAB-11D3-ACEC-00C04F86C309}")

' ========================================================================================
' VerError record
' ========================================================================================

' // Size = 32 bytes
TYPE VerError DWORD
   Flags       AS DWORD       ' unsigned long flags
   opcode      AS DWORD       ' unsigned long opcode
   uOffset     AS DWORD       ' unsigned long uOffset
   Token       AS DWORD       ' unsigned long Token
   item1_flags AS DWORD       ' unsigned long item1_flags
   item1_data  AS LONG PTR    ' int *item1_data
   item2_flags AS DWORD       ' unsigned long item2_flags
   item2_data  AS LONG PTR    ' int *item2_data
END TYPE

'typedef _VerError VEContext;
MACRO VEContext = VerError

' ########################################################################################
' Interface name = IVEHandler
' IID = {856CA1B2-7DAB-11D3-ACEC-00C04F86C309}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVEHandler_INTERFACE_DEFINED)
    %IVEHandler_INTERFACE_DEFINED = 1

INTERFACE IVEHandler $IID_IVEHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD VEHandler ( _                                 ' VTable offset = 12
     BYVAL VECode AS LONG _                             ' __in HRESULT VECode
   , BYVAL Context AS VerError _                        ' __in VEContext Context
   , BYVAL psa AS DWORD _                               ' __in SAFEARRAY * psa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReporterFtn ( _                            ' VTable offset = 16
     BYVAL lFnPtr AS QUAD _                             ' __in __int64 lFnPtr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVEHandler_INTERFACE_DEFINED__ */
