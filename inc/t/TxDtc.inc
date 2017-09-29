' ########################################################################################
' Microsoft Windows
' File: TxDtc.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TXDTC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "txcoord.inc"

'#define XACTTOMSG(dwXact) (dwXact-0x00040000+0x40000000)
MACRO XACTTOMSG(dwXact) = (dwXact-&H00040000+&H40000000)

' enum XACT_DTC_CONSTANTS
%XACT_E_CONNECTION_REQUEST_DENIED = &H8004d100&
%XACT_E_TOOMANY_ENLISTMENTS       = &H8004d101&
%XACT_E_DUPLICATE_GUID            = &H8004d102&
%XACT_E_NOTSINGLEPHASE            = &H8004d103&
%XACT_E_RECOVERYALREADYDONE       = &H8004d104&
%XACT_E_PROTOCOL                  = &H8004d105&
%XACT_E_RM_FAILURE                = &H8004d106&
%XACT_E_RECOVERY_FAILED           = &H8004d107&
%XACT_E_LU_NOT_FOUND              = &H8004d108&
%XACT_E_DUPLICATE_LU              = &H8004d109&
%XACT_E_LU_NOT_CONNECTED          = &H8004d10a&
%XACT_E_DUPLICATE_TRANSID         = &H8004d10b&
%XACT_E_LU_BUSY                   = &H8004d10c&
%XACT_E_LU_NO_RECOVERY_PROCESS    = &H8004d10d&
%XACT_E_LU_DOWN                   = &H8004d10e&
%XACT_E_LU_RECOVERING             = &H8004d10f&
%XACT_E_LU_RECOVERY_MISMATCH      = &H8004d110&
%XACT_E_RM_UNAVAILABLE            = &H8004d111&
%XACT_E_LRMRECOVERYALREADYDONE    = &H8004d112&
%XACT_E_NOLASTRESOURCEINTERFACE   = &H8004d113&
%XACT_S_NONOTIFY                  = &H4d100&
%XACT_OK_NONOTIFY                 = &H4d101&
%dwUSER_MS_SQLSERVER              = &Hffff???

#IF NOT %DEF(%XID_T_DEFINED)
%XID_T_DEFINED = 1
' // Size = 140 bytes
TYPE xid_t DWORD
   formatID     AS LONG   ' long
   gtrid_length AS LONG   ' long
   bqual_length AS LONG   ' long
   data (127)   AS BYTE   ' char data[ 128 ];
END TYPE
MACRO XID = xid_t
#ENDIF

'typedef struct xa_switch_t
'    {
'    char name[ 32 ];
'    long flags;
'    long version;
'    int ( __cdecl *xa_open_entry )(
'        char *__MIDL____MIDL_itf_txdtc_0000_00000000,
'        int __MIDL____MIDL_itf_txdtc_0000_00000001,
'        long __MIDL____MIDL_itf_txdtc_0000_00000002);
'    int ( __cdecl *xa_close_entry )(
'        char *__MIDL____MIDL_itf_txdtc_0000_00000004,
'        int __MIDL____MIDL_itf_txdtc_0000_00000005,
'        long __MIDL____MIDL_itf_txdtc_0000_00000006);
'    int ( __cdecl *xa_start_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000008,
'        int __MIDL____MIDL_itf_txdtc_0000_00000009,
'        long __MIDL____MIDL_itf_txdtc_0000_00000010);
'    int ( __cdecl *xa_end_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000012,
'        int __MIDL____MIDL_itf_txdtc_0000_00000013,
'        long __MIDL____MIDL_itf_txdtc_0000_00000014);
'    int ( __cdecl *xa_rollback_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000016,
'        int __MIDL____MIDL_itf_txdtc_0000_00000017,
'        long __MIDL____MIDL_itf_txdtc_0000_00000018);
'    int ( __cdecl *xa_prepare_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000020,
'        int __MIDL____MIDL_itf_txdtc_0000_00000021,
'        long __MIDL____MIDL_itf_txdtc_0000_00000022);
'    int ( __cdecl *xa_commit_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000024,
'        int __MIDL____MIDL_itf_txdtc_0000_00000025,
'        long __MIDL____MIDL_itf_txdtc_0000_00000026);
'    int ( __cdecl *xa_recover_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000028,
'        long __MIDL____MIDL_itf_txdtc_0000_00000029,
'        int __MIDL____MIDL_itf_txdtc_0000_00000030,
'        long __MIDL____MIDL_itf_txdtc_0000_00000031);
'    int ( __cdecl *xa_forget_entry )(
'        XID *__MIDL____MIDL_itf_txdtc_0000_00000033,
'        int __MIDL____MIDL_itf_txdtc_0000_00000034,
'        long __MIDL____MIDL_itf_txdtc_0000_00000035);
'    int ( __cdecl *xa_complete_entry )(
'        int *__MIDL____MIDL_itf_txdtc_0000_00000037,
'        int *__MIDL____MIDL_itf_txdtc_0000_00000038,
'        int __MIDL____MIDL_itf_txdtc_0000_00000039,
'        long __MIDL____MIDL_itf_txdtc_0000_00000040);
'    }    xa_switch_t;

#IF NOT %DEF(%XA_SWITCH_T_DEFINED)
%XA_SWITCH_T_DEFINED = 1
' // Size = 80 bytes
TYPE xa_switch_t DWORD
   name              AS ASCIIZ * 32   ' char name[ 32 ]
   flags             AS LONG          ' long
   version           AS LONG          ' long
   xa_open_entry     AS DWORD
   xa_close_entry    AS DWORD
   xa_start_entry    AS DWORD
   xa_end_entry      AS DWORD
   xa_rollback_entry AS DWORD
   xa_prepare_entry  AS DWORD
   xa_commit_entry   AS DWORD
   xa_recover_entry  AS DWORD
   xa_forget_entry   AS DWORD
   xa_complete_entry AS DWORD
END TYPE
#ENDIF


' ########################################################################################
' Interface name = IXATransLookup
' IID = F3B1F131-EEDA-11CE-AED4-00AA0051E2C4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXATransLookup_INTERFACE_DEFINED)
    %IXATransLookup_INTERFACE_DEFINED = 1

$IID_IXATransLookup = GUID$("{F3B1F131-EEDA-11CE-AED4-00AA0051E2C4}")

INTERFACE IXATransLookup $IID_IXATransLookup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Lookup ( _                                    ' VTable offset = 12
     BYREF ppTransaction AS ITransaction _              ' __out ITransaction **ppTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXATransLookup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXATransLookup2
' IID = BF193C85-0D1A-4290-B88F-D2CB8873D1E7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXATransLookup2_INTERFACE_DEFINED)
    %IXATransLookup2_INTERFACE_DEFINED = 1

$IID_IXATransLookup2 = GUID$("{BF193C85-0D1A-4290-B88F-D2CB8873D1E7}")

INTERFACE IXATransLookup2 $IID_IXATransLookup2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Lookup ( _                                    ' VTable offset = 12
     BYREF pXID AS XID _                                ' __in XID *pXID
   , BYREF ppTransaction AS ITransaction _              ' __out ITransaction **ppTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXATransLookup2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IResourceManagerSink
' IID = 0D563181-DEFB-11CE-AED1-00AA0051E2C4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResourceManagerSink_INTERFACE_DEFINED)
    %IResourceManagerSink_INTERFACE_DEFINED = 1

$IID_IResourceManagerSink = GUID$("{0D563181-DEFB-11CE-AED1-00AA0051E2C4}")

INTERFACE IResourceManagerSink $IID_IResourceManagerSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TMDown ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceManagerSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IResourceManager
' IID = 13741d21-87EB-11CE-8081-0080C758527E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResourceManager_INTERFACE_DEFINED)
    %IResourceManager_INTERFACE_DEFINED = 1

$IID_IResourceManager = GUID$("{13741d21-87EB-11CE-8081-0080C758527E}")

INTERFACE IResourceManager $IID_IResourceManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Enlist ( _                                    ' VTable offset = 12
     BYVAL pTransaction AS ITransaction _               ' __in ITransaction *pTransaction
   , BYVAL pRes AS ITransactionResourceAsync _          ' __in ITransactionResourceAsync *pRes
   , BYREF pUOW AS GUID _                               ' __out XACTUOW *pUOW
   , BYREF pisoLevel AS LONG _                          ' __out LONG *pisoLevel
   , BYREF ppEnlist AS ITransactionEnlistmentAsync _    ' __out ITransactionEnlistmentAsync **ppEnlist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reenlist ( _                                  ' VTable offset = 16
     BYREF pPrepInfo AS BYTE _                          ' __in (cbPrepInfo) byte *pPrepInfo
   , BYVAL cbPrepInfo AS DWORD _                        ' __in ULONG cbPrepInfo
   , BYVAL lTimeout AS DWORD _                          ' __in DWORD lTimeout
   , BYREF pXactStat AS LONG _                          ' __out XACTSTAT *pXactStat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReenlistmentComplete ( _                      ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDistributedTransactionManager ( _          ' VTable offset = 24
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ILastResourceManager
' IID = 4D964AD4-5B33-11D3-8A91-00C04F79EB6D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILastResourceManager_INTERFACE_DEFINED) = 1
    %ILastResourceManager_INTERFACE_DEFINED = 1

$IID_ILastResourceManager = GUID$("{4D964AD4-5B33-11D3-8A91-00C04F79EB6D}")

INTERFACE ILastResourceManager $IID_ILastResourceManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TransactionCommitted ( _                      ' VTable offset = 12
     BYREF pPrepInfo AS BYTE _                          ' __in (cbPrepInfo) byte *pPrepInfo
   , BYVAL cbPrepInfo AS DWORD _                        ' __in ULONG cbPrepInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILastResourceManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IResourceManager2
' IID = D136C69A-F749-11D1-8F47-00C04F8EE57D
' Inherited interface = IResourceManager
' ########################################################################################

#IF NOT %DEF(%IResourceManager2_INTERFACE_DEFINED)
    %IResourceManager2_INTERFACE_DEFINED = 1

$IID_IResourceManager2 = GUID$("{D136C69A-F749-11D1-8F47-00C04F8EE57D}")

INTERFACE IResourceManager2 $IID_IResourceManager2

   INHERIT IUnknown

   ' =====================================================================================
   ' IResourceManager methods
   ' =====================================================================================
   METHOD Enlist ( _                                    ' VTable offset = 12
     BYVAL pTransaction AS ITransaction _               ' __in ITransaction *pTransaction
   , BYVAL pRes AS ITransactionResourceAsync _          ' __in ITransactionResourceAsync *pRes
   , BYREF pUOW AS GUID _                               ' __out XACTUOW *pUOW
   , BYREF pisoLevel AS LONG _                          ' __out LONG *pisoLevel
   , BYREF ppEnlist AS ITransactionEnlistmentAsync _    ' __out ITransactionEnlistmentAsync **ppEnlist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reenlist ( _                                  ' VTable offset = 16
     BYREF pPrepInfo AS BYTE _                          ' __in (cbPrepInfo) byte *pPrepInfo
   , BYVAL cbPrepInfo AS DWORD _                        ' __in ULONG cbPrepInfo
   , BYVAL lTimeout AS DWORD _                          ' __in DWORD lTimeout
   , BYREF pXactStat AS LONG _                          ' __out XACTSTAT *pXactStat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReenlistmentComplete ( _                      ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDistributedTransactionManager ( _          ' VTable offset = 24
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IResourceManager2 methods
   ' =====================================================================================
   METHOD Enlist2 ( _                                   ' VTable offset = 28
     BYVAL pTransaction AS ITransaction _               ' __in ITransaction *pTransaction
   , BYVAL pResAsync AS ITransactionResourceAsync _     ' __in ITransactionResourceAsync *pResAsync
   , BYREF pUOW AS GUID _                               ' __out XACTUOW *pUOW
   , BYREF pisoLevel AS LONG _                          ' __out LONG *pisoLevel
   , BYREF pXid AS XID _                                ' __out XID *pXid
   , BYREF ppEnlist AS ITransactionEnlistmentAsync _    ' __out ITransactionEnlistmentAsync **ppEnlist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reenlist2 ( _                                 ' VTable offset = 32
     BYVAL pXid AS XID _                                ' __in XID *pXid
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF pXactStat AS LONG _                          ' __out XACTSTAT *pXactStat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceManager2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXAConfig
' IID = C8A6E3A1-9A8C-11CF-A308-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXAConfig_INTERFACE_DEFINED)
    %IXAConfig_INTERFACE_DEFINED = 1

$IID_IXAConfig = GUID$("{C8A6E3A1-9A8C-11CF-A308-00A0C905416E}")

INTERFACE IXAConfig $IID_IXAConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF clsidHelperDll AS GUID _                     ' __in GUID clsidHelperDll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXAConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRMHelper
' IID = E793F6D1-F53D-11CF-A60D-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRMHelper_INTERFACE_DEFINED)
    %IRMHelper_INTERFACE_DEFINED = 1

$IID_IRMHelper = GUID$("{E793F6D1-F53D-11CF-A60D-00A0C905416E}")

INTERFACE IRMHelper $IID_IRMHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RMCount ( _                                   ' VTable offset = 12
     BYVAL dwcTotalNumberOfRMs AS DWORD _               ' __in DWORD dwcTotalNumberOfRMs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RMInfo ( _                                    ' VTable offset = 16
     BYREF pXa_Switch AS xa_switch_t _                  ' __in xa_switch_t *pXa_Switch
   , BYVAL fCDeclCallingConv AS LONG _                  ' __in BOOL fCDeclCallingConv
   , BYREF pszOpenString AS ASCIIZ _                    ' __in __nullterminated  char *pszOpenString
   , BYREF pszCloseString AS ASCIIZ _                   ' __in __nullterminated  char *pszCloseString
   , BYREF guidRMRecovery AS GUID _                     ' __in GUID guidRMRecovery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRMHelper_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXAObtainRMInfo
' IID = E793F6D2-F53D-11CF-A60D-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXAObtainRMInfo_INTERFACE_DEFINED)
    %IXAObtainRMInfo_INTERFACE_DEFINED = 1

$IID_IXAObtainRMInfo = GUID$("{E793F6D2-F53D-11CF-A60D-00A0C905416E}")

INTERFACE IXAObtainRMInfo $IID_IXAObtainRMInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ObtainRMInfo ( _                              ' VTable offset = 12
     BYVAL pIRMHelper AS IRMHelper _                    ' __in IRMHelper *pIRMHelper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXAObtainRMInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IResourceManagerFactory
' IID = 13741D20-87EB-11CE-8081-0080C758527E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResourceManagerFactory_INTERFACE_DEFINED)
    %IResourceManagerFactory_INTERFACE_DEFINED = 1

$IID_IResourceManagerFactory = GUID$("{13741D20-87EB-11CE-8081-0080C758527E}")

INTERFACE IResourceManagerFactory $IID_IResourceManagerFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYREF pguidRM AS GUID _                            ' __in GUID *pguidRM
   , BYREF pszRMName AS ASCIIZ _                        ' __in CHAR *pszRMName
   , BYVAL pIResMgrSink AS IResourceManagerSink _       ' __in IResourceManagerSink *pIResMgrSink
   , BYREF ppResMgr AS IResourceManager _               ' __out IResourceManager **ppResMgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceManagerFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IResourceManagerFactory2
' IID = 6B369C21-FBD2-11D1-8F47-00C04F8EE57D
' Inherited interface = IResourceManagerFactory
' ########################################################################################

#IF NOT %DEF(%IResourceManagerFactory2_INTERFACE_DEFINED)
    %IResourceManagerFactory2_INTERFACE_DEFINED = 1

$IID_IResourceManagerFactory2 = GUID$("{6B369C21-FBD2-11D1-8F47-00C04F8EE57D}")

INTERFACE IResourceManagerFactory2 $IID_IResourceManagerFactory2

   INHERIT IUnknown

   ' =====================================================================================
   ' IResourceManagerFactory method
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYREF pguidRM AS GUID _                            ' __in GUID *pguidRM
   , BYREF pszRMName AS ASCIIZ _                        ' __in CHAR *pszRMName
   , BYVAL pIResMgrSink AS IResourceManagerSink _       ' __in IResourceManagerSink *pIResMgrSink
   , BYREF ppResMgr AS IResourceManager _               ' __out IResourceManager **ppResMgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IResourceManagerFactory2 method
   ' =====================================================================================
   METHOD CreateEx ( _                                  ' VTable offset = 12
     BYREF pguidRM AS GUID _                            ' __in GUID *pguidRM
   , BYREF pszRMName AS ASCIIZ _                        ' __in CHAR *pszRMName
   , BYVAL pIResMgrSink AS IResourceManagerSink _       ' __in IResourceManagerSink *pIResMgrSink
   , BYREF riidRequested AS GUID _                      ' __in REFIID riidRequested
   , BYREF ppvResMgr AS IUnknown _                      ' __out void **ppvResMgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceManagerFactory2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPrepareInfo
' IID = 80C7BFD0-87EE-11CE-8081-0080C758527E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrepareInfo_INTERFACE_DEFINED)
    %IPrepareInfo_INTERFACE_DEFINED = 1

$IID_IPrepareInfo = GUID$("{80C7BFD0-87EE-11CE-8081-0080C758527E}")

INTERFACE IPrepareInfo $IID_IPrepareInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPrepareInfoSize ( _                        ' VTable offset = 12
     BYREF pcbPrepInfo AS DWORD _                       ' __out ULONG *pcbPrepInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrepareInfo ( _                            ' VTable offset = 16
     BYREF pPrepInfo AS BYTE _                          ' __out byte *pPrepInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrepareInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPrepareInfo2
' IID = 5FAB2547-9779-11D1-B886-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrepareInfo2_INTERFACE_DEFINED)
    %IPrepareInfo2_INTERFACE_DEFINED = 1

$IID_IPrepareInfo2 = GUID$("{5FAB2547-9779-11D1-B886-00C04FB9618A}")

INTERFACE IPrepareInfo2 $IID_IPrepareInfo2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPrepareInfoSize ( _                        ' VTable offset = 12
     BYREF pcbPrepInfo AS DWORD _                       ' __out ULONG *pcbPrepInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrepareInfo ( _                            ' VTable offset = 16
     BYVAL cbPrepareInfo AS DWORD _                     ' __in ULONG cbPrepareInfo
   , BYREF pPrepInfo AS BYTE _                          ' __out (cbPrepareInfo) byte *pPrepInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrepareInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGetDispenser
' IID = C23CC370-87EF-11CE-8081-0080C758527E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetDispenser_INTERFACE_DEFINED)
    %IGetDispenser_INTERFACE_DEFINED = 1

$IID_IGetDispenser = GUID$("{C23CC370-87EF-11CE-8081-0080C758527E}")

INTERFACE IGetDispenser $IID_IGetDispenser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDispenser ( _                              ' VTable offset = 12
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetDispenser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionVoterBallotAsync2
' IID = 5433376C-414D-11D3-B206-00C04FC2F3EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionVoterBallotAsync2_INTERFACE_DEFINED)
    %ITransactionVoterBallotAsync2_INTERFACE_DEFINED = 1

$IID_ITransactionVoterBallotAsync2 = GUID$("{5433376C-414D-11D3-B206-00C04FC2F3EF}")

INTERFACE ITransactionVoterBallotAsync2 $IID_ITransactionVoterBallotAsync2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD VoteRequestDone ( _                           ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionVoterBallotAsync2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionVoterNotifyAsync2
' IID = 5433376B-414D-11D3-B206-00C04FC2F3EF
' Inherited interface = ITransactionOutcomeEvents
' ########################################################################################

#IF NOT %DEF(%ITransactionVoterNotifyAsync2_INTERFACE_DEFINED)
    %ITransactionVoterNotifyAsync2_INTERFACE_DEFINED = 1

$IID_ITransactionVoterNotifyAsync2 = GUID$("{5433376B-414D-11D3-B206-00C04FC2F3EF}")

INTERFACE ITransactionVoterNotifyAsync2 $IID_ITransactionVoterNotifyAsync2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITransactionOutcomeEvents methods
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

   ' =====================================================================================
   ' ITransactionVoterNotifyAsync2 method
   ' =====================================================================================
   METHOD VoteRequest ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionVoterNotifyAsync2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionVoterFactory2
' IID = 5433376A-414D-11D3-B206-00C04FC2F3EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionVoterFactory2_INTERFACE_DEFINED)
    %ITransactionVoterFactory2_INTERFACE_DEFINED = 1

$IID_ITransactionVoterFactory2 = GUID$("{5433376A-414D-11D3-B206-00C04FC2F3EF}")

INTERFACE ITransactionVoterFactory2 $IID_ITransactionVoterFactory2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Committed ( _                                 ' VTable offset = 12
     BYVAL pTransaction AS ITransaction _               ' __in ITransaction *pTransaction
   , BYVAL pVoterNotify AS ITransactionVoterNotifyAsync2 _ ' __in ITransactionVoterNotifyAsync2 *pVoterNotify
   , BYREF ppVoterBallot AS ITransactionVoterBallotAsync2 _ ' __out ITransactionVoterBallotAsync2 **ppVoterBallot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionVoterFactory2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionPhase0EnlistmentAsync
' IID = 82DC88E1-A954-11D1-8F88-00600895E7D5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionPhase0EnlistmentAsync_INTERFACE_DEFINED)
    %ITransactionPhase0EnlistmentAsync_INTERFACE_DEFINED = 1

$IID_ITransactionPhase0EnlistmentAsync = GUID$("{82DC88E1-A954-11D1-8F88-00600895E7D5}")

INTERFACE ITransactionPhase0EnlistmentAsync $IID_ITransactionPhase0EnlistmentAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForEnlistment ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Phase0Done ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unenlist ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransaction ( _                            ' VTable offset = 28
     BYREF ppITransaction AS ITransaction _             ' __out ITransaction **ppITransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionPhase0EnlistmentAsync_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionPhase0NotifyAsync
' IID = EF081809-0C76-11D2-87A6-00C04F990F34
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionPhase0NotifyAsync_INTERFACE_DEFINED)
    %ITransactionPhase0NotifyAsync_INTERFACE_DEFINED = 1

$IID_ITransactionPhase0NotifyAsync = GUID$("{EF081809-0C76-11D2-87A6-00C04F990F34}")

INTERFACE ITransactionPhase0NotifyAsync $IID_ITransactionPhase0NotifyAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Phase0Request ( _                             ' VTable offset = 12
     BYVAL fAbortingHint AS LONG _                      ' __in BOOL fAbortingHint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnlistCompleted ( _                           ' VTable offset = 16
     BYVAL status AS LONG _                             ' __in HRESULT status
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionPhase0NotifyAsync_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionPhase0Factory
' IID = 82DC88E0-A954-11D1-8F88-00600895E7D5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionPhase0Factory_INTERFACE_DEFINED)
    %ITransactionPhase0Factory_INTERFACE_DEFINED = 1

$IID_ITransactionPhase0Factory = GUID$("{82DC88E0-A954-11D1-8F88-00600895E7D5}")

INTERFACE ITransactionPhase0Factory $IID_ITransactionPhase0Factory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL pPhase0Notify AS ITransactionPhase0NotifyAsync _ ' __in ITransactionPhase0NotifyAsync *pPhase0Notify
   , BYREF ppPhase0Enlistment AS ITransactionPhase0EnlistmentAsync _ ' __out ITransactionPhase0EnlistmentAsync **ppPhase0Enlistment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionPhase0Factory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionTransmitter
' IID = 59313E01-B36C-11CF-A539-00AA006887C3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionTransmitter_INTERFACE_DEFINED)
    %ITransactionTransmitter_INTERFACE_DEFINED = 1

$IID_ITransactionTransmitter = GUID$("{59313E01-B36C-11CF-A539-00AA006887C3}")

INTERFACE ITransactionTransmitter $IID_ITransactionTransmitter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 12
     BYVAL pTransaction AS ITransaction _               ' __in ITransaction *pTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropagationTokenSize ( _                   ' VTable offset = 16
     BYREF pcbToken AS DWORD _                          ' __out ULONG *pcbToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarshalPropagationToken ( _                   ' VTable offset = 20
     BYVAL cbToken AS DWORD _                           ' __in ULONG cbToken
   , BYREF rgbToken AS BYTE _                           ' __out (cbToken) byte *rgbToken
   , BYREF pcbUsed AS DWORD _                           ' __out ULONG *pcbUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnmarshalReturnToken ( _                      ' VTable offset = 24
     BYVAL cbReturnToken AS DWORD _                     ' __in ULONG cbReturnToken
   , BYREF rgbReturnToken AS BYTE _                     ' __in (cbReturnToken) byte *rgbReturnToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionTransmitter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionTransmitterFactory
' IID = 59313E00-B36C-11CF-A539-00AA006887C3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionTransmitterFactory_INTERFACE_DEFINED)
    %ITransactionTransmitterFactory_INTERFACE_DEFINED = 1

$IID_ITransactionTransmitterFactory = GUID$("{59313E00-B36C-11CF-A539-00AA006887C3}")

INTERFACE ITransactionTransmitterFactory $IID_ITransactionTransmitterFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYREF ppTransmitter AS ITransactionTransmitter _   ' __out ITransactionTransmitter **ppTransmitter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionTransmitterFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionReceiver
' IID = 59313E03-B36C-11CF-A539-00AA006887C3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionReceiver_INTERFACE_DEFINED)
    %ITransactionReceiver_INTERFACE_DEFINED = 1

$IID_ITransactionReceiver = GUID$("{59313E03-B36C-11CF-A539-00AA006887C3}")

INTERFACE ITransactionReceiver $IID_ITransactionReceiver

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UnmarshalPropagationToken ( _                 ' VTable offset = 12
     BYVAL cbToken AS DWORD _                           ' __in ULONG cbToken
   , BYREF rgbToken AS BYTE _                           ' __in (cbToken) byte *rgbToken
   , BYREF ppTransaction AS ITransaction _              ' __out ITransaction **ppTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReturnTokenSize ( _                        ' VTable offset = 16
     BYREF pcbReturnToken AS DWORD _                    ' __out ULONG *pcbReturnToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarshalReturnToken ( _                        ' VTable offset = 20
     BYVAL cbReturnToken AS DWORD _                     ' __in ULONG cbReturnToken
   , BYREF rgbReturnToken AS BYTE _                     ' __out (cbReturnToken) byte *rgbReturnToken
   , BYREF pcbUsed AS DWORD _                           ' __out ULONG *pcbUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionReceiver_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionReceiverFactory
' IID = 59313E02-B36C-11CF-A539-00AA006887C3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionReceiverFactory_INTERFACE_DEFINED)
    %ITransactionReceiverFactory_INTERFACE_DEFINED = 1

$IID_ITransactionReceiverFactory = GUID$("{59313E02-B36C-11CF-A539-00AA006887C3}")

INTERFACE ITransactionReceiverFactory $IID_ITransactionReceiverFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYREF ppReceiver AS ITransactionReceiver _         ' __out ITransactionReceiver **ppReceiver
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionReceiverFactory_INTERFACE_DEFINED__ */


' // Size = 2 bytes
TYPE PROXY_CONFIG_PARAMS WORD
   wcThreadsMax AS WORD
END TYPE


' ########################################################################################
' Interface name = IDtcLuConfigure
' IID = 4131E760-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuConfigure_INTERFACE_DEFINED)
    %IDtcLuConfigure_INTERFACE_DEFINED = 1

$IID_IDtcLuConfigure = GUID$("{4131E760-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuConfigure $IID_IDtcLuConfigure

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYREF pucLuPair AS BYTE _                          ' __in (cbLuPair) byte *pucLuPair
   , BYVAL cbLuPair AS DWORD _                          ' __in DWORD cbLuPair
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 16
     BYREF pucLuPair AS BYTE _                          ' __in (cbLuPair) byte *pucLuPair
   , BYVAL cbLuPair AS DWORD _                          ' __in DWORD cbLuPair
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuConfigure_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRecovery
' IID = AC2B8AD2-D6F0-11D0-B386-00A0C9083365
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecovery_INTERFACE_DEFINED)
    %IDtcLuRecovery_INTERFACE_DEFINED = 1

$IID_IDtcLuRecovery = GUID$("{AC2B8AD2-D6F0-11D0-B386-00A0C9083365}")

INTERFACE IDtcLuRecovery $IID_IDtcLuRecovery

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IDtcLuRecovery_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRecoveryFactory
' IID = 4131E762-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecoveryFactory_INTERFACE_DEFINED)
    %IDtcLuRecoveryFactory_INTERFACE_DEFINED = 1

$IID_IDtcLuRecoveryFactory = GUID$("{4131E762-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRecoveryFactory $IID_IDtcLuRecoveryFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYREF pucLuPair AS BYTE _                          ' __in (cbLuPair) byte *pucLuPair
   , BYVAL cbLuPair AS DWORD _                          ' __in DWORD cbLuPair
   , BYREF ppRecovery AS IDtcLuRecovery _               ' __out IDtcLuRecovery **ppRecovery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRecoveryFactory_INTERFACE_DEFINED__ */


' enum DTCINITIATEDRECOVERYWORK
%TEDRECOVERYWORK_CHECKLUSTATUS = 1
%TEDRECOVERYWORK_TRANS         = %TEDRECOVERYWORK_CHECKLUSTATUS + 1
%TEDRECOVERYWORK_TMDOWN        = %TEDRECOVERYWORK_TRANS         + 1

' enum DTCLUXLN
%DTCLUXLN_COLD   = 1
%DTCLUXLN_WARM   = %DTCLUXLN_COLD + 1

' enum DTCLUXLNCONFIRMATION
%DTCLUXLNCONFIRMATION_CONFIRM          = 1
%DTCLUXLNCONFIRMATION_LOGNAMEMISMATCH  = %DTCLUXLNCONFIRMATION_CONFIRM          + 1
%DTCLUXLNCONFIRMATION_COLDWARMMISMATCH = %DTCLUXLNCONFIRMATION_LOGNAMEMISMATCH  + 1
%DTCLUXLNCONFIRMATION_OBSOLETE         = %DTCLUXLNCONFIRMATION_COLDWARMMISMATCH + 1

' enum DTCLUXLNRESPONSE
%DTCLUXLNRESPONSE_OK_SENDOURXLNBACK   = 1
%DTCLUXLNRESPONSE_OK_SENDCONFIRMATION = %DTCLUXLNRESPONSE_OK_SENDOURXLNBACK   + 1
%DTCLUXLNRESPONSE_LOGNAMEMISMATCH     = %DTCLUXLNRESPONSE_OK_SENDCONFIRMATION + 1
%DTCLUXLNRESPONSE_COLDWARMMISMATCH    = %DTCLUXLNRESPONSE_LOGNAMEMISMATCH     + 1

' enum DTCLUXLNERROR
%DTCLUXLNERROR_PROTOCOL         = 1
%DTCLUXLNERROR_LOGNAMEMISMATCH  = %DTCLUXLNERROR_PROTOCOL        + 1
%DTCLUXLNERROR_COLDWARMMISMATCH = %DTCLUXLNERROR_LOGNAMEMISMATCH + 1

' enum DTCLUCOMPARESTATE
%DTCLUCOMPARESTATE_COMMITTED          = 1
%DTCLUCOMPARESTATE_HEURISTICCOMMITTED = %DTCLUCOMPARESTATE_COMMITTED          + 1
%DTCLUCOMPARESTATE_HEURISTICMIXED     = %DTCLUCOMPARESTATE_HEURISTICCOMMITTED + 1
%DTCLUCOMPARESTATE_HEURISTICRESET     = %DTCLUCOMPARESTATE_HEURISTICMIXED     + 1
%DTCLUCOMPARESTATE_INDOUBT            = %DTCLUCOMPARESTATE_HEURISTICRESET     + 1
%DTCLUCOMPARESTATE_RESET              = %DTCLUCOMPARESTATE_INDOUBT            + 1

' enum DTCLUCOMPARESTATESCONFIRMATION
%DTCLUCOMPARESTATESCONFIRMATION_CONFIRM  = 1
%DTCLUCOMPARESTATESCONFIRMATION_PROTOCOL = %DTCLUCOMPARESTATESCONFIRMATION_CONFIRM + 1

' enum DTCLUCOMPARESTATESERROR
%DTCLUCOMPARESTATESERROR_PROTOCOL = 1

' enum DTCLUCOMPARESTATESRESPONSE
%DTCLUCOMPARESTATESRESPONSE_OK       = 1
%DTCLUCOMPARESTATESRESPONSE_PROTOCOL = %DTCLUCOMPARESTATESRESPONSE_OK + 1


' ########################################################################################
' Interface name = IDtcLuRecoveryInitiatedByDtcTransWork
' IID = 4131E765-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecoveryInitiatedByDtcTransWork_INTERFACE_DEFINED)
    %IDtcLuRecoveryInitiatedByDtcTransWork_INTERFACE_DEFINED = 1

$IID_IDtcLuRecoveryInitiatedByDtcTransWork = GUID$("{4131E765-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRecoveryInitiatedByDtcTransWork $IID_IDtcLuRecoveryInitiatedByDtcTransWork

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLogNameSizes ( _                           ' VTable offset = 12
     BYREF pcbOurLogName AS DWORD _                     ' __out DWORD *pcbOurLogName
   , BYREF pcbRemoteLogName AS DWORD _                  ' __out DWORD *pcbRemoteLogName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOurXln ( _                                 ' VTable offset = 16
     BYREF pXln AS DWORD _                              ' __out DTCLUXLN *pXln
   , BYREF pOurLogName AS DWORD _                       ' __inout unsigned char *pOurLogName
   , BYREF pRemoteLogName AS DWORD _                    ' __inout unsigned char *pRemoteLogName
   , BYREF pdwProtocol AS DWORD _                       ' __out DWORD *pdwProtocol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleConfirmationFromOurXln ( _              ' VTable offset = 20
     BYVAL Confirmation AS LONG _                       ' __in DTCLUXLNCONFIRMATION Confirmation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleTheirXlnResponse ( _                    ' VTable offset = 24
     BYVAL Xln AS LONG _                                ' __in DTCLUXLN Xln
   , BYVAL pRemoteLogName AS DWORD _                    ' __in unsigned char *pRemoteLogName
   , BYVAL cbRemoteLogName AS DWORD _                   ' __in DWORD cbRemoteLogName
   , BYVAL dwProtocol AS DWORD _                        ' __in DWORD dwProtocol
   , BYREF pConfirmation AS LONG _                      ' __out DTCLUXLNCONFIRMATION *pConfirmation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleErrorFromOurXln ( _                     ' VTable offset = 28
     BYVAL Error AS LONG _                              ' __in DTCLUXLNERROR Error
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckForCompareStates ( _                     ' VTable offset = 32
     BYREF fCompareStates AS LONG _                     ' __out BOOL *fCompareStates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOurTransIdSize ( _                         ' VTable offset = 36
     BYREF pcbOurTransId AS DWORD _                     ' __inout DWORD *pcbOurTransId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOurCompareStates ( _                       ' VTable offset = 40
     BYREF pOurTransId AS DWORD _                       ' __inout unsigned char *pOurTransId
   , BYREF pCompareState AS LONG _                      ' __out DTCLUCOMPARESTATE *pCompareState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleTheirCompareStatesResponse ( _          ' VTable offset = 44
     BYVAL CompareState AS LONG _                       ' __in DTCLUCOMPARESTATE CompareState
   , BYREF pConfirmation AS LONG _                      ' __out DTCLUCOMPARESTATESCONFIRMATION *pConfirmation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleErrorFromOurCompareStates ( _           ' VTable offset = 48
     BYVAL Error AS LONG _                              ' __in DTCLUCOMPARESTATESERROR Error
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConversationLost ( _                          ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoverySeqNum ( _                         ' VTable offset = 56
     BYREF plRecoverySeqNum AS LONG _                   ' __out LONG *plRecoverySeqNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ObsoleteRecoverySeqNum ( _                    ' VTable offset = 60
     BYVAL lNewRecoverySeqNum AS LONG _                 ' __in LONG lNewRecoverySeqNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRecoveryInitiatedByDtcTransWork_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRecoveryInitiatedByDtcStatusWork
' IID = 4131E766-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecoveryInitiatedByDtcStatusWork_INTERFACE_DEFINED)
    %IDtcLuRecoveryInitiatedByDtcStatusWork_INTERFACE_DEFINED = 1

$IID_IDtcLuRecoveryInitiatedByDtcStatusWork = GUID$("{4131E766-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRecoveryInitiatedByDtcStatusWork $IID_IDtcLuRecoveryInitiatedByDtcStatusWork

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLogNameSizes ( _                           ' VTable offset = 12
     BYVAL lRecoverySeqNum AS LONG _                    ' __in LONG lRecoverySeqNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRecoveryInitiatedByDtcStatusWork_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRecoveryInitiatedByDtc
' IID = 4131E764-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecoveryInitiatedByDtc_INTERFACE_DEFINED)
    %IDtcLuRecoveryInitiatedByDtc_INTERFACE_DEFINED = 1

$IID_IDtcLuRecoveryInitiatedByDtc = GUID$("{4131E764-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRecoveryInitiatedByDtc $IID_IDtcLuRecoveryInitiatedByDtc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWork ( _                                   ' VTable offset = 12
     BYREF pWork AS LONG _                              ' __inout DTCINITIATEDRECOVERYWORK *pWork
   , BYREF ppv AS IUnknown _                            ' __inout void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRecoveryInitiatedByDtc_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRecoveryInitiatedByLuWork
' IID = AC2B8AD1-D6F0-11D0-B386-00A0C9083365
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecoveryInitiatedByLuWork_INTERFACE_DEFINED)
    %IDtcLuRecoveryInitiatedByLuWork_INTERFACE_DEFINED = 1

$IID_IDtcLuRecoveryInitiatedByLuWork = GUID$("{AC2B8AD1-D6F0-11D0-B386-00A0C9083365}")

INTERFACE IDtcLuRecoveryInitiatedByLuWork $IID_IDtcLuRecoveryInitiatedByLuWork

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HandleTheirXln ( _                            ' VTable offset = 12
     BYVAL lRecoverySeqNum AS LONG _                    ' __in LONG lRecoverySeqNum
   , BYVAL Xln AS LONG _                                ' __in DTCLUXLN Xln
   , BYVAL pRemoteLogName AS DWORD _                    ' __in unsigned char *pRemoteLogName
   , BYVAL cbRemoteLogName AS DWORD _                   ' __in DWORD cbRemoteLogName
   , BYVAL pOurLogName AS DWORD _                       ' __in unsigned char *pOurLogName
   , BYVAL cbOurLogName AS DWORD _                      ' __in DWORD cbOurLogName
   , BYVAL dwProtocol AS DWORD _                        ' __in DWORD dwProtocol
   , BYREF pResponse AS LONG _                          ' __out DTCLUXLNRESPONSE *pResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOurLogNameSize ( _                         ' VTable offset = 16
     BYREF pcbOurLogName AS DWORD _                     ' __inout DWORD *pcbOurLogName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOurXln ( _                                 ' VTable offset = 20
     BYREF pXln AS LONG _                               ' __out DTCLUXLN *pXln
   , BYREF pOurLogName AS DWORD _                       ' __inout unsigned char *pOurLogName
   , BYREF pdwProtocol AS DWORD _                       ' __out DWORD *pdwProtocol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleConfirmationOfOurXln ( _                ' VTable offset = 24
     BYVAL Confirmation AS LONG _                       ' __in DTCLUXLNCONFIRMATION Confirmation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleTheirCompareStates ( _                  ' VTable offset = 28
     BYREF pRemoteTransId AS DWORD _                    ' __inout unsigned char *pRemoteTransId
   , BYVAL cbRemoteTransId AS DWORD _                   ' __in DWORD cbRemoteTransId
   , BYVAL CompareState AS LONG _                       ' __in DTCLUCOMPARESTATE CompareState
   , BYREF pResponse AS LONG _                          ' __out DTCLUCOMPARESTATESRESPONSE *pResponse
   , BYREF pCompareState AS LONG _                      ' __out DTCLUCOMPARESTATE *pCompareState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleConfirmationOfOurCompareStates ( _      ' VTable offset = 32
     BYVAL Confirmation AS LONG _                       ' __in DTCLUCOMPARESTATESCONFIRMATION Confirmation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleErrorFromOurCompareStates ( _           ' VTable offset = 36
     BYVAL Error AS LONG _                              ' __in DTCLUCOMPARESTATESERROR Error
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConversationLost ( _                          ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRecoveryInitiatedByLuWork_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRecoveryInitiatedByLu
' IID = 4131E768-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRecoveryInitiatedByLu_INTERFACE_DEFINED)
    %IDtcLuRecoveryInitiatedByLu_INTERFACE_DEFINED = 1

$IID_IDtcLuRecoveryInitiatedByLu = GUID$("{4131E768-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRecoveryInitiatedByLu $IID_IDtcLuRecoveryInitiatedByLu

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetObjectToHandleWorkFromLu ( _               ' VTable offset = 12
     BYREF ppWork AS IDtcLuRecoveryInitiatedByLuWork _  ' __out IDtcLuRecoveryInitiatedByLuWork **ppWork
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRecoveryInitiatedByLu_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRmEnlistment
' IID = 4131E769-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRmEnlistment_INTERFACE_DEFINED)
    %IDtcLuRmEnlistment_INTERFACE_DEFINED = 1

$IID_IDtcLuRmEnlistment = GUID$("{4131E769-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRmEnlistment $IID_IDtcLuRmEnlistment

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Unplug ( _                                    ' VTable offset = 12
     BYVAL fConversationLost AS LONG _                  ' __in BOOL fConversationLost
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackedOut ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackOut ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Committed ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Forget ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestCommit ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRmEnlistment_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRmEnlistmentSink
' IID = 4131E770-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRmEnlistmentSink_INTERFACE_DEFINED)
    %IDtcLuRmEnlistmentSink_INTERFACE_DEFINED = 1

$IID_IDtcLuRmEnlistmentSink = GUID$("{4131E770-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRmEnlistmentSink $IID_IDtcLuRmEnlistmentSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AckUnplug ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TmDown ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SessionLost ( _                               ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackedOut ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackOut ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Committed ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Forget ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Prepare ( _                                   ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestCommit ( _                             ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRmEnlistmentSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuRmEnlistmentFactory
' IID = 4131E771-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuRmEnlistmentFactory_INTERFACE_DEFINED)
    %IDtcLuRmEnlistmentFactory_INTERFACE_DEFINED = 1

$IID_IDtcLuRmEnlistmentFactory = GUID$("{4131E771-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuRmEnlistmentFactory $IID_IDtcLuRmEnlistmentFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL pucLuPair AS DWORD _                         ' __in unsigned char *pucLuPair
   , BYVAL cbLuPair AS DWORD _                          ' __in DWORD cbLuPair
   , BYVAL pITransaction AS ITransaction _              ' __in ITransaction *pITransaction
   , BYVAL pTransId AS DWORD _                          ' __in unsigned char *pTransId
   , BYVAL cbTransId AS DWORD _                         ' __in DWORD cbTransId
   , BYVAL pRmEnlistmentSink AS IDtcLuRmEnlistmentSink _ ' __in IDtcLuRmEnlistmentSink *pRmEnlistmentSink
   , BYREF ppRmEnlistment AS IDtcLuRmEnlistment _       ' __inout IDtcLuRmEnlistment **ppRmEnlistment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuRmEnlistmentFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuSubordinateDtc
' IID = 4131E773-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuSubordinateDtc_INTERFACE_DEFINED)
    %IDtcLuSubordinateDtc_INTERFACE_DEFINED = 1

$IID_IDtcLuSubordinateDtc = GUID$("{4131E773-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuSubordinateDtc $IID_IDtcLuSubordinateDtc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Unplug ( _                                    ' VTable offset = 12
     BYVAL fConversationLost AS LONG _                  ' __in BOOL fConversationLost
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackedOut ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackOut ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Committed ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Forget ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Prepare ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestCommit ( _                             ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuSubordinateDtc_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuSubordinateDtcSink
' IID = 4131E774-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuSubordinateDtcSink_INTERFACE_DEFINED)
    %IDtcLuSubordinateDtcSink_INTERFACE_DEFINED = 1

$IID_IDtcLuSubordinateDtcSink = GUID$("{4131E774-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuSubordinateDtcSink $IID_IDtcLuSubordinateDtcSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AckUnplug ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TmDown ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SessionLost ( _                               ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackedOut ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackOut ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Committed ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Forget ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestCommit ( _                             ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuSubordinateDtcSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDtcLuSubordinateDtcFactory
' IID = 4131E775-1AEA-11D0-944B-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcLuSubordinateDtcFactory_INTERFACE_DEFINED)
    %IDtcLuSubordinateDtcFactory_INTERFACE_DEFINED = 1

$IID_IDtcLuSubordinateDtcFactory = GUID$("{4131E775-1AEA-11D0-944B-00A0C905416E}")

INTERFACE IDtcLuSubordinateDtcFactory $IID_IDtcLuSubordinateDtcFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL pucLuPair AS DWORD _                         ' __in unsigned char *pucLuPair
   , BYVAL cbLuPair AS DWORD _                          ' __in DWORD cbLuPair
   , BYVAL punkTransactionOuter AS IUnknown _           ' __in IUnknown *punkTransactionOuter
   , BYVAL isoLevel AS LONG _                           ' __in ISOLEVEL isoLevel
   , BYVAL isoFlags AS DWORD _                          ' __in ULONG isoFlags
   , BYVAL pOptions AS ITransactionOptions _            ' __in ITransactionOptions *pOptions
   , BYREF ppTransaction AS ITransaction _              ' __out ITransaction **ppTransaction
   , BYVAL pTransId AS DWORD _                          ' __in unsigned char *pTransId
   , BYVAL cbTransId AS DWORD _                         ' __in DWORD cbTransId
   , BYVAL pSubordinateDtcSink AS IDtcLuSubordinateDtcSink _ ' __in IDtcLuSubordinateDtcSink *pSubordinateDtcSink
   , BYREF ppSubordinateDtc AS IDtcLuSubordinateDtc _   ' __inout IDtcLuSubordinateDtc **ppSubordinateDtc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcLuSubordinateDtcFactory_INTERFACE_DEFINED__ */
