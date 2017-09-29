' ########################################################################################
' Microsoft Windows
' File: CertBCli.inc
' Contents: Cert Server backup client APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTBCLI_INC = 1

'#define szBACKUPANNOTATION   "Cert Server Backup Interface"
'#define wszBACKUPANNOTATION  TEXT(szBACKUPANNOTATION)
$szBACKUPANNOTATION = "Cert Server Backup Interface"
$$wszBACKUPANNOTATION = "Cert Server Backup Interface"$$

'#define szRESTOREANNOTATION  "Cert Server Restore Interface"
'#define wszRESTOREANNOTATION TEXT(szRESTOREANNOTATION)
$szRESTOREANNOTATION = "Cert Server Restore Interface"
$$wszRESTOREANNOTATION = "Cert Server Restore Interface"$$


'// Type of Backup passed to CertSrvBackupPrepare:
'// CSBACKUP_TYPE_FULL: Requesting backup of the complete DB (DB & Log files)
'// CSBACKUP_TYPE_LOGS_ONLY: Requesting backup of only the log files
'// CSBACKUP_TYPE_INCREMENTAL: Requesting incremental backup

'// CertSrvBackupPrepare flags:
%CSBACKUP_TYPE_FULL      = &H00000001???
%CSBACKUP_TYPE_LOGS_ONLY = &H00000002???
'//#define CSBACKUP_TYPE_INCREMENTAL   0x00000004   // not yet supported
%CSBACKUP_TYPE_MASK      = &H00000003???   ' // valid flags

'// Type of Restore passed to CertSrvRestorePrepare:
'// CSRESTORE_TYPE_FULL: Requesting restore of the complete DB (DB & Log files)
'// CSRESTORE_TYPE_ONLINE: Restoration is done when Cert Server is online.

%CSRESTORE_TYPE_FULL    = &H00000001???    ' // else incremental
%CSRESTORE_TYPE_ONLINE  = &H00000002???    ' // not yet supported
%CSRESTORE_TYPE_CATCHUP = &H00000004???    ' // not yet supported
%CSRESTORE_TYPE_MASK    = &H00000005???    ' // valid flags


'// Setting the current log # to this value would disable incremental backup
%CSBACKUP_DISABLE_INCREMENTAL = &Hffffffff???


'// BFT is the bit flag used to represent file types (directory/dit/logfile/etc.)
'// We keep them as a character so that we can append/prepend them to the actual
'// file path. The code in the Backup API's rely on the fact that values 0-256
'// in 8 bit ascii map to the values 0-256 in unicode.

'typedef WCHAR CSBFT;


'// Bit flags:
'//  CSBFT_DIRECTORY               - path specified is a directory
'//  CSBFT_DATABASE_DIRECTORY      - that file goes into database directory
'//  CSBFT_LOG_DIRECTORY           - that the file goes into log directory

%CSBFT_DIRECTORY          = &H80???
%CSBFT_DATABASE_DIRECTORY = &H40???
%CSBFT_LOG_DIRECTORY      = &H20???

'// Following combinations are defined for easy use of the filetype and the
'// directory into into which it goes

'#define   CSBFT_LOG        ((CSBFT) (TEXT('\x01') | CSBFT_LOG_DIRECTORY))
'#define   CSBFT_LOG_DIR        ((CSBFT) (TEXT('\x02') | CSBFT_DIRECTORY))
'#define   CSBFT_CHECKPOINT_DIR     ((CSBFT) (TEXT('\x03') | CSBFT_DIRECTORY))
'#define   CSBFT_CERTSERVER_DATABASE ((CSBFT) (TEXT('\x04') | CSBFT_DATABASE_DIRECTORY))
'#define   CSBFT_PATCH_FILE     ((CSBFT) (TEXT('\x05') | CSBFT_LOG_DIRECTORY))
'#define   CSBFT_UNKNOWN        ((CSBFT) (TEXT('\x0f')))


'// Backup Context Handle
'typedef void *HCSBC;

#IF NOT %DEF(%CSEDB_RSTMAP)
%CSEDB_RSTMAP = 1
' // Size = 8 bytes
TYPE CSEDB_RSTMAPW DWORD
   pwszDatabaseName    AS WSTRINGZ PTR   ' RPC_STRING WCHAR *
   pwszNewDatabaseName AS WSTRINGZ PTR   ' RPC_STRING WCHAR *
END TYPE

MACRO CSEDB_RSTMAP = CSEDB_RSTMAPW
#ENDIF   ' // CSEDB_RSTMAP

'//+--------------------------------------------------------------------------
'// CertSrvIsServerOnline -- check to see if the Cert Server is Online on the
'//   given server. This call is guaranteed to return quickly.
'//
'// Parameters:
'//   [in]  pwszServerName - name or config string of the server to check
'//   [out] pfServerOnline - pointer to receive the bool result
'//      (TRUE if Cert Server is online; FALSE, otherwise)
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//+--------------------------------------------------------------------------

' There is not an ansi version
DECLARE FUNCTION CertSrvIsServerOnlineW IMPORT "Certadm.dll" ALIAS "CertSrvIsServerOnlineW" ( _
   BYREF pwszServerName AS WSTRINGZ _                   ' __in  WCHAR const *pwszServerName
 , BYREF pfServerOnline AS LONG _                       ' __out BOOL *pfServerOnline
 ) AS LONG                                              ' HRESULT

MACRO CertSrvIsServerOnline = CertSrvIsServerOnlineW

'//+--------------------------------------------------------------------------
'// CertSrvBackupGetDynamicFileList -- return the list of dynamic files that
'//   need to be backed up in addition to database files.
'//
'// Parameters:
'//   [in]  hbc - backup context handle
'//   [out] ppwszzFileList - pointer to receive the pointer to the file list;
'//      allocated memory should be freed using CertSrvBackupFree() API
'//      by the caller when it is no longer needed; The file list info
'//      is an array of null-terminated filenames and the list is
'//      terminated by two L'\0's.
'//   [out] pcbSize - will receive the number of bytes returned
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not an ansi version
DECLARE FUNCTION CertSrvBackupGetDynamicFileListW IMPORT "Certadm.dll" ALIAS "CertSrvBackupGetDynamicFileListW" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 , BYREF ppwszzFileList AS DWORD _                      ' __out PWSTR *ppwszzFileList
 , BYREF pcbSize AS DWORD _                             ' __out DWORD *pcbSize
 ) AS LONG                                              ' HRESULT

MACRO CertSrvBackupGetDynamicFileList = CertSrvBackupGetDynamicFileListW

'//+--------------------------------------------------------------------------
'// CertSrvBackupPrepare -- prepare the DB for the online backup and return a
'//   Backup Context Handle to be used for subsequent calls to backup
'//   functions.
'//
'// Parameters:
'//   [in]  pwszServerName - name or config string of the server to check
'//   [in]  grbitJet - flag to be passed to jet while backing up dbs
'//   [in]  dwBackupFlags - CSBACKUP_TYPE_FULL or CSBACKUP_TYPE_LOGS_ONLY
'//   [out] phbc - pointer that will receive the backup context handle
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not an ansi version
DECLARE FUNCTION CertSrvBackupPrepareW IMPORT "Certadm.dll" ALIAS "CertSrvBackupPrepareW" ( _
   BYREF pwszServerName AS WSTRINGZ _                   ' __in WCHAR const *pwszServerName
 , BYVAL grbitJet AS DWORD _                            ' __in ULONG grbitJet
 , BYVAL dwBackupFlags AS DWORD _                       ' __in ULONG dwBackupFlags // CSBACKUP_TYPE_*
 , BYREF phbc AS DWORD _                                ' __out HCSBC *phbc
 ) AS LONG                                              ' HRESULT

MACRO CertSrvBackupPrepare = CertSrvBackupPrepareW

'//+--------------------------------------------------------------------------
'// CertSrvBackupGetDatabaseNames -- return the list of data bases that need to
'//   be backed up for the given backup context
'//
'// Parameters:
'//   [in]  hbc - backup context handle
'//   [out] ppwszzAttachmentInformation - pointer to receive the pointer to
'//      the attachment info; allocated memory should be freed using
'//      CertSrvBackupFree() API by the caller when it is no longer
'//      needed; Attachment info is an array of null-terminated
'//      filenames and the list is terminated by two L'\0's.
'//   [out] pcbSize - will receive the number of bytes returned
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not an ansi version
DECLARE FUNCTION CertSrvBackupGetDatabaseNamesW IMPORT "Certadm.dll" ALIAS "CertSrvBackupGetDatabaseNamesW" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 , BYREF ppwszzAttachmentInformation AS DWORD _         ' __out PWSTR *ppwszzAttachmentInformation
 , BYREF pcbSize AS DWORD _                             ' __out DWORD *pcbSize
 ) AS LONG                                              ' HRESULT

MACRO CertSrvBackupGetDatabaseNames = CertSrvBackupGetDatabaseNamesW


'//+--------------------------------------------------------------------------
'// CertSrvBackupOpenFile -- open the given attachment for read.
'//
'// Parameters:
'//   [in]  hbc - backup context handle
'//   [in]  pwszAttachmentName - name of the attachment to be opened for read
'//   [in]  cbReadHintSize - suggested size in bytes that might be used
'//      during the subsequent reads on this attachment
'//   [out] pliFileSize - pointer to a large integer that would receive the
'//      size in bytes of the given attachment
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not an ansi version
DECLARE FUNCTION CertSrvBackupOpenFileW IMPORT "Certadm.dll" ALIAS "CertSrvBackupOpenFileW" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 , BYREF pwszAttachmentName AS WSTRINGZ _               ' __in WCHAR const *pwszAttachmentName
 , BYVAL cbReadHintSize AS DWORD _                      ' __in DWORD cbReadHintSize
 , BYREF pliFileSize AS QUAD _                          ' __out LARGE_INTEGER *pliFileSize
 ) AS LONG                                              ' HRESULT

MACRO CertSrvBackupOpenFile = CertSrvBackupOpenFileW

'//+--------------------------------------------------------------------------
'// CertSrvBackupRead -- read the currently open attachment bytes into the given
'//   buffer.  The client application is expected to call this function
'//   repeatedly until it gets the entire file (the application would have
'//   received the file size through the CertSrvBackupOpenFile call before.
'//
'// Parameters:
'//   [in]  hbc - backup context handle
'//   [out] pvBuffer - pointer to the buffer that would receive the read data.
'//   [in]  cbBuffer - specifies the size of the above buffer
'//   [out] pcbRead - pointer to receive the actual number of bytes read.
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvBackupRead IMPORT "Certadm.dll" ALIAS "CertSrvBackupRead" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 , BYREF pvBuffer AS ANY _                              ' __out VOID *pvBuffer
 , BYVAL cbBuffer AS DWORD _                            ' __in DWORD cbBuffer
 , BYREF pcbRead AS DWORD _                             '__out DWORD *pcbRead
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvBackupClose -- called by the application after it completes reading all
'//   the data in the currently opened attachement.
'//
'// Parameters:
'//   [in] hbc - backup context handle
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvBackupClose IMPORT "Certadm.dll" ALIAS "CertSrvBackupClose" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvBackupGetBackupLogs -- return the list of log files that need to be
'//   backed up for the given backup context
'//
'// Parameters:
'//   [in]  hbc - backup context handle
'//   [out] pwszzBackupLogFiles - pointer that will receive the pointer to
'//      the list of log files; allocated memory should be freed using
'//      CertSrvBackupFree() API by the caller when it is no
'//      longer needed; Log files are returned in an array of
'//      null-terminated filenames and the list is terminated by two
'//      L'\0's
'//   [out] pcbSize - will receive the number of bytes returned
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not ansi version
DECLARE FUNCTION CertSrvBackupGetBackupLogsW IMPORT "Certadm.dll" ALIAS "CertSrvBackupGetBackupLogsW" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 , BYREF ppwszzBackupLogFiles AS DWORD _                ' __out PWSTR *ppwszzBackupLogFiles
 , BYREF pcbSize AS DWORD _                             ' __out DWORD *pcbSize
 ) AS LONG                                              ' HRESULT

MACRO CertSrvBackupGetBackupLogs = CertSrvBackupGetBackupLogsW

'//+--------------------------------------------------------------------------
'// CertSrvBackupTruncateLogs -- called to truncate the already read backup logs.
'//
'// Parameters:
'//   [in] hbc - backup context handle
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvBackupTruncateLogs IMPORT "Certadm.dll" ALIAS "CertSrvBackupTruncateLogs" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvBackupEnd -- called to end the current backup session.
'//
'// Parameters:
'//   [in] hbc - backup context handle of the backup session
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvBackupEnd IMPORT "Certadm.dll" ALIAS "CertSrvBackupEnd" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvBackupFree -- free any buffer allocated by certbcli.dll APIs.
'//
'// Parameters:
'//   [in] pv - pointer to the buffer that is to be freed.
'//
'// Returns:
'//   None.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvBackupFree IMPORT "Certadm.dll" ALIAS "CertSrvBackupFree" ( _
   BYVAL pv AS DWORD _                                  ' __in VOID *pv
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvRestoreGetDatabaseLocations -- called both at backup time as well as
'//   at restorate time to get data base locations for different types of
'//   files.
'//
'// Parameters:
'//   [in]  hbc - backup context handle which would have been obtained
'//      through CertSrvBackupPrepare in the backup case and through
'//      CertSrvRestorePrepare in the restore case.
'//   [out] ppwszzDatabaseLocationList - pointer that will receive the
'//      pointer to the list of database locations; allocated memory
'//      should be freed using CertSrvBackupFree() API by the caller
'//      when it is no longer needed; locations are returned in an array
'//      of null-terminated names and and the list is terminated by
'//      two L'\0's.  The first character of each name is the BFT
'//      character that indicates the type of the file and the rest of
'//      the name tells gives the path into which that particular type
'//      of file should be restored.
'//   [out] pcbSize - will receive the number of bytes returned
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not ansi version
DECLARE FUNCTION CertSrvRestoreGetDatabaseLocationsW IMPORT "Certadm.dll" ALIAS "CertSrvRestoreGetDatabaseLocationsW" ( _
   BYVAL hbc AS DWORD _                                 ' __in  HCSBC hbc
 , BYREF ppwszzDatabaseLocationList AS DWORD _          ' __out PWSTR *ppwszzDatabaseLocationList
 , BYREF pcbSize AS DWORD _                             ' __out DWORD *pcbSize
 ) AS LONG                                              ' HRESULT

MACRO CertSrvRestoreGetDatabaseLocations = CertSrvRestoreGetDatabaseLocationsW

'//+--------------------------------------------------------------------------
'// CertSrvRestorePrepare -- indicate beginning of a restore session.
'//
'// Parameters:
'//   [in]  pwszServerName - name or config string of the server into which
'//      the restore operation is going to be performed.
'//   [in]  dwRestoreFlags -  Or'ed combination of CSRESTORE_TYPE_* flags;
'//      0 if no special flags are to be specified
'//   [out] phbc - pointer to receive the backup context handle which is to
'//      be passed to the subsequent restore APIs
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not ansi version
DECLARE FUNCTION CertSrvRestorePrepareW IMPORT "Certadm.dll" ALIAS "CertSrvRestorePrepareW" ( _
   BYREF pwszServerName AS WSTRINGZ _                   ' __in WCHAR const *pwszServerName
 , BYVAL dwRestoreFlags AS DWORD _                      ' __in ULONG dwRestoreFlags // CSRESTORE_TYPE_*
 , BYREF phbc AS DWORD _                                ' __out HCSBC *phbc
 ) AS LONG                                              ' HRESULT

MACRO CertSrvRestorePrepare = CertSrvRestorePrepareW

'//+--------------------------------------------------------------------------
'// CertSrvRestoreRegister -- register a restore operation. It will interlock
'//   all subsequent restore operations, and will prevent the restore target
'//   from starting until the call to CertSrvRestoreRegisterComplete is made.
'//
'// Parameters:
'//   [in] hbc - backup context handle for the restore session.
'//   [in] pwszCheckPointFilePath - path to restore the check point files
'//   [in] pwszLogPath - path where the log files are restored
'//   [in] rgrstmap - restore map
'//   [in] crstmap - tells if there is a new restore map
'//   [in] pwszBackupLogPath - path where the backup logs are located
'//   [in] genLow - Lowest log# that was restored in this restore session
'//   [in] genHigh - Highest log# that was restored in this restore session
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

' There is not ansi version
DECLARE FUNCTION CertSrvRestoreRegisterW IMPORT "Certadm.dll" ALIAS "CertSrvRestoreRegisterW" ( _
   BYVAL hbc AS DWORD _                                 ' __in_opt HCSBC hbc
 , BYREF pwszCheckPointFilePath AS WSTRINGZ _           ' __in_opt WCHAR const *pwszCheckPointFilePath
 , BYREF pwszLogPath AS WSTRINGZ _                      ' __in_opt WCHAR const *pwszLogPath
 , BYREF rgrstmap AS CSEDB_RSTMAPW _                    ' __in_opt CSEDB_RSTMAPW rgrstmap[]
 , BYVAL crstmap AS LONG _                              ' __in LONG crstmap
 , BYREF pwszBackupLogPath AS WSTRINGZ _                ' __in_opt WCHAR const *pwszBackupLogPath
 , BYVAL genLow AS DWORD _                              ' __in ULONG genLow
 , BYVAL genHigh AS DWORD _                             ' __in ULONG genHigh
 ) AS LONG                                              ' HRESULT

MACRO CertSrvRestoreRegister = CertSrvRestoreRegisterW

DECLARE FUNCTION CertSrvRestoreRegisterThroughFile IMPORT "Certadm.dll" ALIAS "CertSrvRestoreRegisterThroughFile" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 , BYREF pwszCheckPointFilePath AS WSTRINGZ _           ' __in_opt WCHAR const *pwszCheckPointFilePath
 , BYREF pwszLogPath AS WSTRINGZ _                      ' __in_opt WCHAR const *pwszLogPath
 , BYREF rgrstmap AS CSEDB_RSTMAPW _                    ' __in_opt CSEDB_RSTMAPW rgrstmap[]
 , BYVAL crstmap AS LONG _                              ' __in LONG crstmap
 , BYREF pwszBackupLogPath AS WSTRINGZ _                ' __in_opt WCHAR const *pwszBackupLogPath
 , BYVAL genLow AS DWORD _                              ' __in ULONG genLow
 , BYVAL genHigh AS DWORD _                             ' __in ULONG genHigh
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvRestoreRegisterComplete -- indicate that a previously registered
'//   restore is complete.
'//
'// Parameters:
'//   [in] hbc - backup context handle
'//   [in] hrRestoreState - success code if the restore was successful
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvRestoreRegisterComplete IMPORT "Certadm.dll" ALIAS "CertSrvRestoreRegisterComplete" ( _
   BYVAL hbc AS DWORD _                                 ' __in_opt HCSBC hbc
 , BYVAL hrRestoreState AS LONG _                       ' __in HRESULT hrRestoreState
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvRestoreEnd -- end a restore session
'//
'// Parameters:
'//   [in] hbc - backup context handle
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

DECLARE FUNCTION CertSrvRestoreEnd IMPORT "Certadm.dll" ALIAS "CertSrvRestoreEnd" ( _
   BYVAL hbc AS DWORD _                                 ' __in HCSBC hbc
 ) AS LONG                                              ' HRESULT


'//+--------------------------------------------------------------------------
'// CertSrvServerControl -- send a control command to the cert server.
'//
'// Parameters:
'//   [in]  pwszServerName - name or config string of the server to control
'//   [in]  dwControlFlags - control command and flags
'//   [out] pcbOut - pointer to receive the size of command output data
'//   [out] ppbOut - pointer to receive command output data.  Use the
'//      CertSrvBackupFree() API to free the buffer.
'//
'// Returns:
'//   S_OK if the call executed successfully;
'//   Failure code otherwise.
'//---------------------------------------------------------------------------

%CSCONTROL_SHUTDOWN = &H000000001???
%CSCONTROL_SUSPEND  = &H000000002???
%CSCONTROL_RESTART  = &H000000003???

' There is not ansi version
DECLARE FUNCTION CertSrvServerControlW IMPORT "Certadm.dll" ALIAS "CertSrvServerControlW" ( _
   BYREF pwszServerName AS WSTRINGZ _                   ' __in WCHAR const *pwszServerName
 , BYVAL dwControlFlags AS DWORD _                      ' __in DWORD dwControlFlags
 , OPTIONAL BYREF pcbOut AS DWORD _                     ' __out_opt DWORD *pcbOut
 , OPTIONAL BYVAL ppbOut AS DWORD _                     ' __out_opt BYTE **ppbOut
 ) AS LONG                                              ' HRESULT

MACRO CertSrvServerControl = CertSrvServerControlW
