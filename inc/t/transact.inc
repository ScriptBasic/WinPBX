' ########################################################################################
' Microsoft Windows
' File: Transact.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TRANSACT_INC = 1

#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "winerror.inc"

#IF NOT %DEF(%BasicTransactionTypes_INTERFACE_DEFINED)
%BasicTransactionTypes_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE BOID BYTE
   rgb(15) AS BYTE   ' byte rgb[ 16 ]
END TYPE

'#define BOID_NULL (*((BOID*)(&IID_NULL)))
$BOID_NULL = $IID_NULL

#IF NOT %DEF(%MAX_TRAN_DESC_DEFINED)
%MAX_TRAN_DESC_DEFINED = 1
' enum TX_MISC_CONSTANTS
%MAX_TRAN_DESC = 40
#ENDIF

'typedef BOID XACTUOW;
'typedef LONG ISOLEVEL;

' enum ISOLATIONLEVEL
%ISOLATIONLEVEL_UNSPECIFIED     = &Hffffffff&
%ISOLATIONLEVEL_CHAOS           = &H10&
%ISOLATIONLEVEL_READUNCOMMITTED = &H100&
%ISOLATIONLEVEL_BROWSE          = &H100&
%ISOLATIONLEVEL_CURSORSTABILITY = &H1000&
%ISOLATIONLEVEL_READCOMMITTED   = &H1000&
%ISOLATIONLEVEL_REPEATABLEREAD  = &H10000&
%ISOLATIONLEVEL_SERIALIZABLE    = &H100000&
%ISOLATIONLEVEL_ISOLATED        = &H100000&

' // Size = 40 bytes
TYPE XACTTRANSINFO DWORD
   uow                     AS GUID    ' XACTUOW
   isoLevel                AS LONG    ' ISOLEVEL
   isoFlags                AS DWORD   ' ULONG
   grfTCSupported          AS DWORD   ' DWORD
   grfRMSupported          AS DWORD   ' DWORD
   grfTCSupportedRetaining AS DWORD   ' DWORD
   grfRMSupportedRetaining AS DWORD   ' DWORD
END TYPE

' // Size = 36 bytes
TYPE XACTSTATS DWORD
   cOpen              AS DWORD       ' ULONG
   cCommitting        AS DWORD       ' ULONG
   cCommitted         AS DWORD       ' ULONG
   cAborting          AS DWORD       ' ULONG
   cAborted           AS DWORD       ' ULONG
   cInDoubt           AS DWORD       ' ULONG
   cHeuristicDecision AS DWORD       ' ULONG
   timeTransactionsUp AS FILETIME    ' FILETIME
END TYPE

' enum ISOFLAG
%ISOFLAG_RETAIN_COMMIT_DC  = 1
%ISOFLAG_RETAIN_COMMIT     = 2
%ISOFLAG_RETAIN_COMMIT_NO  = 3
%ISOFLAG_RETAIN_ABORT_DC   = 4
%ISOFLAG_RETAIN_ABORT      = 8
%ISOFLAG_RETAIN_ABORT_NO   = 12
%ISOFLAG_RETAIN_DONTCARE   = %ISOFLAG_RETAIN_COMMIT_DC OR %ISOFLAG_RETAIN_ABORT_DC
%ISOFLAG_RETAIN_BOTH       = %ISOFLAG_RETAIN_COMMIT    OR %ISOFLAG_RETAIN_ABORT
%ISOFLAG_RETAIN_NONE       = %ISOFLAG_RETAIN_COMMIT_NO OR %ISOFLAG_RETAIN_ABORT_NO
%ISOFLAG_OPTIMISTIC        = 16
%ISOFLAG_READONLY          = 32

' enum XACTTC
%XACTTC_NONE               = 0
%XACTTC_SYNC_PHASEONE      = 1
%XACTTC_SYNC_PHASETWO      = 2
%XACTTC_SYNC               = 2
%XACTTC_ASYNC_PHASEONE     = 4
%XACTTC_ASYNC              = 4

' enum XACTRM
%XACTRM_OPTIMISTICLASTWINS = 1
%XACTRM_NOREADONLYPREPARES = 2

' enum XACTCONST
%XACTCONST_TIMEOUTINFINITE = 0

' enum XACTHEURISTIC
%XACTHEURISTIC_ABORT       = 1
%XACTHEURISTIC_COMMIT      = 2
%XACTHEURISTIC_DAMAGE      = 3
%XACTHEURISTIC_DANGER      = 4

' enum XACTSTAT
%XACTSTAT_NONE             = 0
%XACTSTAT_OPENNORMAL       = &H1
%XACTSTAT_OPENREFUSED      = &H2
%XACTSTAT_PREPARING        = &H4
%XACTSTAT_PREPARED         = &H8
%XACTSTAT_PREPARERETAINING = &H10
%XACTSTAT_PREPARERETAINED  = &H20
%XACTSTAT_COMMITTING       = &H40
%XACTSTAT_COMMITRETAINING  = &H80
%XACTSTAT_ABORTING         = &H100
%XACTSTAT_ABORTED          = &H200
%XACTSTAT_COMMITTED        = &H400
%XACTSTAT_HEURISTIC_ABORT  = &H800
%XACTSTAT_HEURISTIC_COMMIT = &H1000
%XACTSTAT_HEURISTIC_DAMAGE = &H2000
%XACTSTAT_HEURISTIC_DANGER = &H4000
%XACTSTAT_FORCED_ABORT     = &H8000
%XACTSTAT_FORCED_COMMIT    = &H10000
%XACTSTAT_INDOUBT          = &H20000
%XACTSTAT_CLOSED           = &H40000
%XACTSTAT_OPEN             = &H3
%XACTSTAT_NOTPREPARED      = &H7ffc3
%XACTSTAT_ALL              = &H7ffff

' // Size = 44 bytes
TYPE XACTOPT DWORD
   ulTimeout     AS DWORD
   szDescription AS ASCIIZ * 40
END TYPE

#ENDIF   ' /* __BasicTransactionTypes_INTERFACE_DEFINED__ */

$IID_ITransaction              = GUID$("{0FB15084-AF41-11CE-BD2B-204C4F4F5020}")
$IID_ITransactionCloner        = GUID$("{02656950-2152-11d0-944C-00A0C905416E}")
$IID_ITransaction2             = GUID$("{34021548-0065-11d3-bac1-00c04f797be2}")
$IID_ITransactionDispenser     = GUID$("{3A6AD9E1-23B9-11cf-AD60-00AA00A74CCD}")
$IID_ITransactionOptions       = GUID$("{3A6AD9E0-23B9-11CF-AD60-00AA00A74CCD}")
$IID_ITransactionOutcomeEvents = GUID$("{3A6AD9E2-23B9-11cf-AD60-00AA00A74CCD}")
$IID_ITmNodeName               = GUID$("{30274F88-6EE4-474e-9B95-7807BC9EF8CF}")
$IID_IKernelTransaction        = GUID$("{79427A2B-F895-40E0-BE79-B57DC82ED231}")


' ########################################################################################
' ITransaction interface
' IID = 0FB15084-AF41-11CE-BD2B-204C4F4F5020
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransaction_INTERFACE_DEFINED)
    %ITransaction_INTERFACE_DEFINED = 1

INTERFACE ITransaction $IID_ITransaction

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfTC AS DWORD _                             ' __in DWORD grfTC
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
     BYVAL pboidReason AS DWORD _                       ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL fAsync AS LONG _                             ' __in BOOL fAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionInfo ( _                        ' VTable offset = 20
     BYREF pinfo AS XACTTRANSINFO _                     ' __out XACTTRANSINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransaction_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionCloner interface
' IID = 02656950-2152-11d0-944C-00A0C905416E
' Inherited interface = ITransaction
' ########################################################################################

#IF NOT %DEF(%ITransactionCloner_INTERFACE_DEFINED)
    %ITransactionCloner_INTERFACE_DEFINED = 1

INTERFACE ITransactionCloner $IID_ITransactionCloner

   INHERIT IUnknown

   ' =====================================================================================
   ' ITransaction methods
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfTC AS DWORD _                             ' __in DWORD grfTC
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
     BYVAL pboidReason AS DWORD _                       ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL fAsync AS LONG _                             ' __in BOOL fAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionInfo ( _                        ' VTable offset = 20
     BYREF pinfo AS XACTTRANSINFO _                     ' __out XACTTRANSINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITransactionCloner methods
   ' =====================================================================================
   METHOD CloneWithCommitDisabled ( _                   ' VTable offset = 24
     BYREF ppITransaction AS ITransaction _             ' __out ITransaction **ppITransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionCloner_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransaction2 interface
' IID = 34021548-0065-11d3-bac1-00c04f797be2
' Inherited interface = ITransaction
' ########################################################################################

#IF NOT %DEF(%ITransaction2_INTERFACE_DEFINED)
    %ITransaction2_INTERFACE_DEFINED = 1

INTERFACE ITransaction2 $IID_ITransaction2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITransaction methods
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfTC AS DWORD _                             ' __in DWORD grfTC
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
     BYVAL pboidReason AS DWORD _                       ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL fAsync AS LONG _                             ' __in BOOL fAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionInfo ( _                        ' VTable offset = 20
     BYREF pinfo AS XACTTRANSINFO _                     ' __out XACTTRANSINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITransaction2 methods
   ' =====================================================================================
   METHOD GetTransactionInfo2 ( _                       ' VTable offset = 24
     BYREF pinfo AS XACTTRANSINFO _                     ' __out XACTTRANSINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransaction2_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionDispenser interface
' IID = 3A6AD9E1-23B9-11cf-AD60-00AA00A74CCD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionDispenser_INTERFACE_DEFINED)
    %ITransactionDispenser_INTERFACE_DEFINED = 1

INTERFACE ITransactionDispenser $IID_ITransactionDispenser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOptionsObject ( _                          ' VTable offset = 12
      BYREF ppOptions AS ITransactionOptions _          ' __out ITransactionOptions **ppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginTransaction ( _                          ' VTable offset = 16
     BYVAL punkOuter AS IUnknown _                      ' __in IUnknown *punkOuter
   , BYVAL isoLevel AS LONG _                           ' __in ISOLEVEL isoLevel
   , BYVAL isoFlags AS DWORD _                          ' __in ULONG isoFlags
   , BYVAL pOptions AS ITransactionOptions _            ' __in ITransactionOptions *pOptions
   , BYREF ppTransaction AS ITransaction _              ' __out ITransaction **ppTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionDispenser_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionOptions interface
' IID = 3A6AD9E0-23B9-11cf-AD60-00AA00A74CCD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionOptions_INTERFACE_DEFINED)
    %ITransactionOptions_INTERFACE_DEFINED = 1

INTERFACE ITransactionOptions $IID_ITransactionOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 12
     BYREF pOptions AS XACTOPT _                        ' __in XACTOPT *pOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 16
     BYREF pOptions AS XACTOPT _                        ' __inout XACTOPT *pOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionOptions_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionOutcomeEvents interface
' IID = 3A6AD9E2-23B9-11cf-AD60-00AA00A74CCD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionOutcomeEvents_INTERFACE_DEFINED)
    %ITransactionOutcomeEvents_INTERFACE_DEFINED = 1

INTERFACE ITransactionOutcomeEvents $IID_ITransactionOutcomeEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Committed ( _                                 ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   , BYVAL hr AS DWORD _                                ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Aborted ( _                                   ' VTable offset = 16
     BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HeuristicDecision ( _                         ' VTable offset = 20
     BYVAL dwDecision AS DWORD _                        ' __in DWORD dwDecision
   , BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Indoubt ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionOutcomeEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' ITmNodeName interface
' IID = 30274F88-6EE4-474e-9B95-7807BC9EF8CF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITmNodeName_INTERFACE_DEFINED)
    %ITmNodeName_INTERFACE_DEFINED = 1

INTERFACE ITmNodeName $IID_ITmNodeName

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNodeNameSize ( _                           ' VTable offset = 12
     BYREF pcbNodeNameSize AS DWORD _                   ' __out ULONG *pcbNodeNameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeName ( _                               ' VTable offset = 16
     BYVAL cbNodeNameBufferSize AS DWORD _              ' __in ULONG cbNodeNameBufferSize
   , BYREF pNodeNameBuffer AS WSTRINGZ _                ' __inout LPWSTR pNodeNameBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITmNodeName_INTERFACE_DEFINED__ */

' ########################################################################################
' IKernelTransaction interface
' IID = 79427A2B-F895-40E0-BE79-B57DC82ED231
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKernelTransaction_INTERFACE_DEFINED)
    %IKernelTransaction_INTERFACE_DEFINED = 1

INTERFACE IKernelTransaction $IID_IKernelTransaction

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 12
     BYREF pHandle AS DWORD _                           ' __out HANDLE *pHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKernelTransaction_INTERFACE_DEFINED__ */
