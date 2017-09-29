' ########################################################################################
' Microsoft Windows
' File: xpsprint.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XPSPRINT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

'#if (NTDDI_VERSION >= NTDDI_WIN7)

'#ifndef __XpsPrint_LIBRARY_DEFINED__
'#define __XpsPrint_LIBRARY_DEFINED__

' enum XPS_JOB_COMPLETION
%XPS_JOB_IN_PROGRESS = 0
%XPS_JOB_COMPLETED   = %XPS_JOB_IN_PROGRESS + 1
%XPS_JOB_CANCELLED   = %XPS_JOB_COMPLETED   + 1
%XPS_JOB_FAILED      = %XPS_JOB_CANCELLED   + 1

TYPE XPS_JOB_STATUS DWORD
   jobId            AS DWORD   ' UINT32
   currentDocument  AS LONG    ' INT32
   currentPage      AS LONG    ' INT32
   currentPageTotal AS LONG    ' INT32
   completion       AS LONG    ' XPS_JOB_COMPLETION
   jobStatus        AS LONG    ' HRESULT
END TYPE

'EXTERN_C const IID LIBID_XpsPrint;

' ########################################################################################
' Interface name = IXpsPrintJobStream
' IID = 7a77dc5f-45d6-4dff-9307-d8cb846347ca
' Inherited interface = ISequentialStream
' ########################################################################################

#IF NOT %DEF(%IXpsPrintJobStream_INTERFACE_DEFINED)
    %IXpsPrintJobStream_INTERFACE_DEFINED = 1

$IID_IXpsPrintJobStream = GUID$("{7a77dc5f-45d6-4dff-9307-d8cb846347ca}")

INTERFACE IXpsPrintJobStream $IID_IXpsPrintJobStream

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsPrintJobStream methods
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsPrintJobStream_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsPrintJob
' IID = 5ab89b06-8194-425f-ab3b-d7a96e350161
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsPrintJob_INTERFACE_DEFINED)
    %IXpsPrintJob_INTERFACE_DEFINED = 1

$IID_IXpsPrintJob = GUID$("{5ab89b06-8194-425f-ab3b-d7a96e350161}")

INTERFACE IXpsPrintJob $IID_IXpsPrintJob

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJobStatus ( _                              ' VTable offset = 16
     BYREF jobStatus AS XPS_JOB_STATUS _                ' __retval_out XPS_JOB_STATUS *jobStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsPrintJob_INTERFACE_DEFINED__ */

'#ifndef __XpsPrint_MODULE_DEFINED__
'#define __XpsPrint_MODULE_DEFINED__

DECLARE FUNCTION StartXpsPrintJob IMPORT "XpsPrint.dll" ALIAS "StartXpsPrintJob" ( _
   BYREF printerName AS WSTRINGZ _                      ' __in LPCWSTR printerName
 , BYREF jobName AS WSTRINGZ _                          ' __in LPCWSTR jobName
 , BYREF outputFileName AS WSTRINGZ _                   ' __in LPCWSTR outputFileName
 , BYVAL progressEvent AS DWORD _                       ' __in HANDLE progressEvent
 , BYVAL completionEvent AS DWORD _                     ' __in HANDLE completionEvent
 , BYREF printablePagesOn AS BYTE _                     ' __in UINT8 *printablePagesOn
 , BYVAL printablePagesOnCount AS DWORD _               ' __in UINT32 printablePagesOnCount
 , BYREF xpsPrintJob AS IXpsPrintJob _                  ' __out_opt IXpsPrintJob **xpsPrintJob
 , BYREF documentStream AS IXpsPrintJobStream _         ' __out_opt IXpsPrintJobStream **documentStream
 , BYREF printTicketStream AS IXpsPrintJobStream _      ' __out_opt IXpsPrintJobStream **printTicketStream
 ) AS LONG                                              ' HRESULT

'#endif /* __XpsPrint_MODULE_DEFINED__ */
'#endif /* __XpsPrint_LIBRARY_DEFINED__ */

'#endif //(NTDDI_VERSION >= NTDDI_WIN7)
