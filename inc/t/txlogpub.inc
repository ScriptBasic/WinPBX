' ########################################################################################
' Microsoft Windows
' File: txlogpub.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TXLOGPUB_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

'//+-------------------------------------------------------------------------
'//
'//  Microsoft Windows
'//  Copyright (c) Microsoft Corporation. All rights reserved.
'//
'//--------------------------------------------------------------------------


'// LSN
'// LSN is the fundamental cookie returned from the log as the name of a
'// newly-written  log record. LSNs from successively written records to a
'// given log are always monotonically increasing. LSNs are directly
'// comparable: lsn2 is later in the log than lsn1 if and only if as integers
'// lsn2 > lsn1.
'//
'// Neither the value zero nor the value MAXLSN are ever used as the value of
'// an actual LSN.

'typedef LARGE_INTEGER LSN;

%MAXLSN = &H7FFFFFFFFFFFFFFF&&


'// RECORD_READING_POLICY
'// The RECORD_READING_POLICY enumeration values specify a hint about the
'// order in which records will be read from a log.  It is used by
'// ILog::SetAccessPolicyHint.

' enum RECORD_READING_POLICY
%RECORD_READING_POLICY_FORWARD  = 1
%RECORD_READING_POLICY_BACKWARD = 2
%RECORD_READING_POLICY_RANDOM   = 3

'// ILog
'// An interface to the lowest level of a log implementation. This level
'// takes care of writing the records to disk in a stable manner. Recovery
'// protocols, transaction awareness, and the like are provided by a higher
'// semantic level.

$CLSID_SimpleFileBasedLog = GUID$("{E16C0593-128F-11D1-97E4-00C04FB9618A}")

' ########################################################################################
' ILog interface
' IID = FF222117-0C6C-11D2-B89A-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILog_INTERFACE_DEFINED)
    %ILog_INTERFACE_DEFINED = 1

$IID_ILog = GUID$("{FF222117-0C6C-11D2-B89A-00C04FB9618A}")

INTERFACE ILog $IID_ILog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Force ( _                                     ' VTable offset = 12
     BYVAL lsnMinToForce AS QUAD _                      ' __in LSN lsnMinToForce
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRecord ( _                              ' VTable offset = 16
     BYREF rgBlob AS BLOB _                             ' __in BLOB *rgBlob
   , BYVAL cBlob AS DWORD _                             ' __in ULONG cBlob
   , BYVAL fForceNow AS LONG _                          ' __in BOOL fForceNow
   , BYREF plsn AS QUAD _                               ' __in_out LSN *plsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadRecord ( _                                ' VTable offset = 20
     BYVAL lsnToRead AS QUAD _                          ' __in LSN lsnToRead
   , BYREF plsnPrev AS QUAD _                           ' __in_out LSN *plsnPrev
   , BYREF plsnNext AS QUAD _                           ' __in_out LSN *plsnNext
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pcbData AS DWORD _                           ' __out ULONG *pcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadRecordPrefix ( _                          ' VTable offset = 24
     BYVAL lsnToRead AS QUAD _                          ' __in LSN lsnToRead
   , BYREF plsnPrev AS QUAD _                           ' __out LSN *plsnPrev
   , BYREF plsnNext AS QUAD _                           ' __in_out LSN *plsnNext
   , BYREF pbData AS DWORD _                            ' __out BYTE *pbData
   , BYREF pcbData AS DWORD _                           ' __in_out ULONG *pcbData
   , BYREF pcbRecord AS DWORD _                         ' __out ULONG *pcbRecord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogLimits ( _                              ' VTable offset = 28
     BYREF plsnFirst AS QUAD _                          ' __in_out LSN *plsnFirst
   , BYREF plsnLast AS QUAD _                           ' __in_out LSN *plsnLast
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TruncatePrefix ( _                            ' VTable offset = 32
     BYVAL lsnFirstToKeep AS QUAD _                     ' __in LSN lsnFirstToKeep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccessPolicyHint ( _                       ' VTable offset = 36
     BYVAL policy AS LONG _                             ' __in RECORD_READING_POLICY policy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILog_INTERFACE_DEFINED__ */


'// IFileBasedLogInit
'// An interface used to initialize an instance of a file based implementation of
'// ILog.  This interface defines the single method InitNew, which is used to
'// create a log on a new log file.  Objects that implement IFileBasedLogInit
'// should also implement IPersistFile, to allow existing log files to be opened.

' ########################################################################################
' IFileBasedLogInit interface
' IID = 00951E8C-1294-11D1-97E4-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileBasedLogInit_INTERFACE_DEFINED)
    %IFileBasedLogInit_INTERFACE_DEFINED = 1

$IID_IFileBasedLogInit = GUID$("{00951E8C-1294-11D1-97E4-00C04FB9618A}")

INTERFACE IFileBasedLogInit $IID_IFileBasedLogInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 12
     BYREF filename AS WSTRINGZ _                       ' __in LPCWSTR filename
   , BYVAL cbCapacityHint AS DWORD _                    ' __in ULONG cbCapacityHint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileBasedLogInit_INTERFACE_DEFINED__ */
