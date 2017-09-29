' ########################################################################################
' Microsoft Windows
' File: TxCoord.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TXCOORD_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "transact.inc"
#INCLUDE ONCE "objidl.inc"

' ########################################################################################
' Interface name = ITransactionResourceAsync
' IID = 69E971F0-23CE-11CF-AD60-00AA00A74CCD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionResourceAsync_INTERFACE_DEFINED)
    %ITransactionResourceAsync_INTERFACE_DEFINED = 1

$IID_ITransactionResourceAsync = GUID$("{69E971F0-23CE-11CF-AD60-00AA00A74CCD}")

INTERFACE ITransactionResourceAsync $IID_ITransactionResourceAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PrepareRequest ( _                            ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   , BYVAL fWantMoniker AS LONG _                       ' __in BOOL fWantMoniker
   , BYVAL fSinglePhase AS LONG _                       ' __in BOOL fSinglePhase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitRequest ( _                             ' VTable offset = 16
     BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   , BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortRequest ( _                              ' VTable offset = 20
     BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TMDown ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionResourceAsync_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionLastResourceAsync
' IID = C82BD532-5B30-11D3-8A91-00C04F79EB6D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionLastResourceAsync_INTERFACE_DEFINED)
    %ITransactionLastResourceAsync_INTERFACE_DEFINED = 1

$IID_ITransactionLastResourceAsync = GUID$("{C82BD532-5B30-11D3-8A91-00C04F79EB6D}")

INTERFACE ITransactionLastResourceAsync $IID_ITransactionLastResourceAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DelegateCommit ( _                            ' VTable offset = 12
     BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ForgetRequest ( _                             ' VTable offset = 16
     BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionLastResourceAsync_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionResource
' IID = EE5FF7B3-4572-11D0-9452-00A0C905416E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionResource_INTERFACE_DEFINED)
    %ITransactionResource_INTERFACE_DEFINED = 1

$IID_ITransactionResource = GUID$("{EE5FF7B3-4572-11D0-9452-00A0C905416E}")

INTERFACE ITransactionResource $IID_ITransactionResource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PrepareRequest ( _                            ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   , BYVAL fWantMoniker AS LONG _                       ' __in BOOL fWantMoniker
   , BYVAL fSinglePhase AS LONG _                       ' __in BOOL fSinglePhase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitRequest ( _                             ' VTable offset = 16
     BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   , BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortRequest ( _                              ' VTable offset = 20
     BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYREF pNewUOW AS GUID _                            ' __in XACTUOW *pNewUOW
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TMDown ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionEnlistmentAsync
' IID = 0FB15081-AF41-11CE-BD2B-204C4F4F5020
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionEnlistmentAsync_INTERFACE_DEFINED)
    %ITransactionEnlistmentAsync_INTERFACE_DEFINED = 1

$IID_ITransactionEnlistmentAsync = GUID$("{0FB15081-AF41-11CE-BD2B-204C4F4F5020}")

INTERFACE ITransactionEnlistmentAsync $IID_ITransactionEnlistmentAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PrepareRequestDone ( _                        ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   , BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitRequestDone ( _                         ' VTable offset = 16
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortRequestDone ( _                          ' VTable offset = 20
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionEnlistmentAsync_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionLastEnlistmentAsync
' IID = C82BD533-5B30-11D3-8A91-00C04F79EB6D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionLastEnlistmentAsync_INTERFACE_DEFINED)
    %ITransactionLastEnlistmentAsync_INTERFACE_DEFINED = 1

$IID_ITransactionLastEnlistmentAsync = GUID$("{C82BD533-5B30-11D3-8A91-00C04F79EB6D}")

INTERFACE ITransactionLastEnlistmentAsync $IID_ITransactionLastEnlistmentAsync

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TransactionOutcome ( _                        ' VTable offset = 12
     BYVAL XactStat AS LONG _                           ' __in XACTSTAT XactStat
   , BYREF pboidReason AS GUID _                        ' __in BOID *pboidReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionLastEnlistmentAsync_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionExportFactory
' IID = E1CF9B53-8745-11CE-A9BA-00AA006C3706
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionExportFactory_INTERFACE_DEFINED)
    %ITransactionExportFactory_INTERFACE_DEFINED = 1

$IID_ITransactionExportFactory = GUID$("{E1CF9B53-8745-11CE-A9BA-00AA006C3706}")

INTERFACE ITransactionExportFactory $IID_ITransactionExportFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRemoteClassId ( _                          ' VTable offset = 12
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 16
     BYVAL cbWhereabouts AS DWORD _                     ' __in ULONG cbWhereabouts
   , BYREF rgbWhereabouts AS BYTE _                     ' __in (cbWhereabouts) byte *rgbWhereabouts
   , BYREF ppExport AS ITransactionExport _             ' __out ITransactionExport **ppExport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionExportFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionImportWhereabouts
' IID = 0141FDA4-8FC0-11CE-BD18-204C4F4F5020
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionImportWhereabouts_INTERFACE_DEFINED)
    %ITransactionImportWhereabouts_INTERFACE_DEFINED = 1

$IID_ITransactionImportWhereabouts = GUID$("{0141FDA4-8FC0-11CE-BD18-204C4F4F5020}")

INTERFACE ITransactionImportWhereabouts $IID_ITransactionImportWhereabouts

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWhereaboutsSize ( _                        ' VTable offset = 12
     BYREF pcbWhereabouts AS DWORD _                    ' __out ULONG *pcbWhereabouts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWhereabouts ( _                            ' VTable offset = 16
     BYVAL cbWhereabouts AS DWORD _                     ' __in ULONG cbWhereabouts
   , BYREF rgbWhereabouts AS BYTE _                     ' __out byte *rgbWhereabouts
   , BYREF pcbUsed AS DWORD _                           ' __out ULONG *pcbUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionImportWhereabouts_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionExport
' IID = 0141FDA5-8FC0-11CE-BD18-204C4F4F5020
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionExport_INTERFACE_DEFINED)
    %ITransactionExport_INTERFACE_DEFINED = 1

$IID_ITransactionExport = GUID$("{0141FDA5-8FC0-11CE-BD18-204C4F4F5020}")

INTERFACE ITransactionExport $IID_ITransactionExport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Export ( _                                    ' VTable offset = 12
     BYVAL punkTransaction AS IUnknown _                ' __in IUnknown *punkTransaction
   , BYREF pcbTransactionCookie AS DWORD _              ' __out ULONG *pcbTransactionCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionCookie ( _                      ' VTable offset = 16
     BYVAL punkTransaction AS IUnknown _                ' __in IUnknown *punkTransaction
   , BYVAL cbTransactionCookie AS DWORD _               ' __in ULONG cbTransactionCookie
   , BYREF rgbTransactionCookie AS BYTE _               ' __out byte *rgbTransactionCookie
   , BYREF pcbUsed AS DWORD _                           ' __out ULONG *pcbUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionExport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransactionImport
' IID = E1CF9B5A-8745-11CE-A9BA-00AA006C3706
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionImport_INTERFACE_DEFINED)
    %ITransactionImport_INTERFACE_DEFINED = 1

$IID_ITransactionImport = GUID$("{E1CF9B5A-8745-11CE-A9BA-00AA006C3706}")

INTERFACE ITransactionImport $IID_ITransactionImport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Import ( _                                    ' VTable offset = 12
     BYVAL cbTransactionCookie AS DWORD _               ' __in ULONG cbTransactionCookie
   , BYREF rgbTransactionCookie AS BYTE _               ' __in (cbTransactionCookie) byte *rgbTransactionCookie
   , BYREF piid AS GUID _                               ' __in IID *piid
   , BYREF ppvTransaction AS IUnknown _                 ' __out void **ppvTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionImport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITipTransaction
' IID = 17CF72D0-BAC5-11D1-B1BF-00C04FC2F3EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITipTransaction_INTERFACE_DEFINED)
    %ITipTransaction_INTERFACE_DEFINED = 1

$IID_ITipTransaction = GUID$("{17CF72D0-BAC5-11D1-B1BF-00C04FC2F3EF}")

INTERFACE ITipTransaction $IID_ITipTransaction

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Push ( _                                      ' VTable offset = 12
     BYREF i_pszRemoteTmUrl AS ASCIIZ _                 ' __in char *i_pszRemoteTmUrl
   , BYREF o_ppszRemoteTxUrl AS DWORD _                 ' __out char **o_ppszRemoteTxUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionUrl ( _                         ' VTable offset = 16
     BYREF o_ppszLocalTxUrl AS DWORD _                  ' __out char **o_ppszLocalTxUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITipTransaction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITipHelper
' IID = 17CF72D1-BAC5-11D1-B1BF-00C04FC2F3EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITipHelper_INTERFACE_DEFINED)
    %ITipHelper_INTERFACE_DEFINED = 1

$IID_ITipHelper = GUID$("{17CF72D1-BAC5-11D1-B1BF-00C04FC2F3EF}")

INTERFACE ITipHelper $IID_ITipHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Pull ( _                                      ' VTable offset = 12
     BYREF i_pszTxUrl AS ASCIIZ _                       ' __in char *i_pszTxUrl
   , BYREF o_ppITransaction AS ITransaction _           ' __out ITransaction **o_ppITransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PullAsync ( _                                 ' VTable offset = 16
     BYREF i_pszTxUrl AS ASCIIZ _                       ' __in char *i_pszTxUrl
   , BYVAL i_pTipPullSink AS ITipPullSink _             ' __in ITipPullSink *i_pTipPullSink
   , BYREF o_ppITransaction AS ITransaction _           ' __out ITransaction **o_ppITransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalTmUrl ( _                             ' VTable offset = 20
     BYREF o_ppszLocalTmUrl AS DWORD _                  ' __out char **o_ppszLocalTmUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITipHelper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITipPullSink
' IID = 17CF72D2-BAC5-11D1-B1BF-00C04FC2F3EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITipPullSink_INTERFACE_DEFINED)
    %ITipPullSink_INTERFACE_DEFINED = 1

$IID_ITipPullSink = GUID$("{17CF72D2-BAC5-11D1-B1BF-00C04FC2F3EF}")

INTERFACE ITipPullSink $IID_ITipPullSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PullComplete ( _                              ' VTable offset = 12
     BYVAL i_hrPull AS LONG _                           ' __in HRESULT i_hrPull
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITipPullSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDtcNetworkAccessConfig
' IID = 9797C15D-A428-4291-87B6-0995031A678D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDtcNetworkAccessConfig_INTERFACE_DEFINED)
    %IDtcNetworkAccessConfig_INTERFACE_DEFINED = 1

$IID_IDtcNetworkAccessConfig = GUID$("{9797C15D-A428-4291-87B6-0995031A678D}")

INTERFACE IDtcNetworkAccessConfig $IID_IDtcNetworkAccessConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PullComplete ( _                              ' VTable offset = 12
     BYREF pbAnyNetworkAccess AS LONG _                 ' __out BOOL *pbAnyNetworkAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAnyNetworkAccess ( _                       ' VTable offset = 16
     BYVAL bAnyNetworkAccess AS LONG _                  ' __in BOOL bAnyNetworkAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkAdministrationAccess ( _            ' VTable offset = 20
     BYREF pbNetworkAdministrationAccess AS LONG _      ' __out BOOL *pbNetworkAdministrationAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkAdministrationAccess ( _            ' VTable offset = 24
     BYVAL bNetworkAdministrationAccess AS LONG _       ' __in BOOL bNetworkAdministrationAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkTransactionAccess ( _               ' VTable offset = 28
     BYREF pbNetworkTransactionAccess AS LONG _         ' __out BOOL *pbNetworkTransactionAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkTransactionAccess ( _               ' VTable offset = 32
     BYVAL bNetworkTransactionAccess AS LONG _          ' __in BOOL bNetworkTransactionAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkClientAccess ( _                    ' VTable offset = 36
     BYREF pbNetworkClientAccess AS LONG _              ' __out BOOL *pbNetworkClientAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkClientAccess ( _                    ' VTable offset = 40
     BYVAL bNetworkClientAccess AS LONG _               ' __in BOOL bNetworkClientAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkTIPAccess ( _                       ' VTable offset = 44
     BYREF pbNetworkTIPAccess AS LONG _                 ' __out BOOL *pbNetworkTIPAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkTIPAccess ( _                       ' VTable offset = 48
     BYVAL bNetworkTIPAccess AS LONG _                  ' __in BOOL bNetworkTIPAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXAAccess ( _                               ' VTable offset = 52
     BYREF pbXAAccess AS LONG _                         ' __out BOOL *pbXAAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetXAAccess ( _                               ' VTable offset = 56
     BYVAL bXAAccess AS LONG _                          ' __in BOOL bXAAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartDtcService ( _                         ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcNetworkAccessConfig_INTERFACE_DEFINED__ */


' enum AUTHENTICATION_LEVEL
%NO_AUTHENTICATION_REQUIRED       = 0
%INCOMING_AUTHENTICATION_REQUIRED = 1
%MUTUAL_AUTHENTICATION_REQUIRED   = 2


' ########################################################################################
' Interface name = IDtcNetworkAccessConfig2
' IID = A7AA013B-EB7D-4F42-B41C-B2DEC09AE034
' Inherited interface = IDtcNetworkAccessConfig
' ########################################################################################

#IF NOT %DEF(%IDtcNetworkAccessConfig2_INTERFACE_DEFINED)
    %IDtcNetworkAccessConfig2_INTERFACE_DEFINED = 1

$IID_IDtcNetworkAccessConfig2 = GUID$("{A7AA013B-EB7D-4F42-B41C-B2DEC09AE034}")

INTERFACE IDtcNetworkAccessConfig2 $IID_IDtcNetworkAccessConfig2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDtcNetworkAccessConfig methods
   ' =====================================================================================
   METHOD PullComplete ( _                              ' VTable offset = 12
     BYREF pbAnyNetworkAccess AS LONG _                 ' __out BOOL *pbAnyNetworkAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAnyNetworkAccess ( _                       ' VTable offset = 16
     BYVAL bAnyNetworkAccess AS LONG _                  ' __in BOOL bAnyNetworkAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkAdministrationAccess ( _            ' VTable offset = 20
     BYREF pbNetworkAdministrationAccess AS LONG _      ' __out BOOL *pbNetworkAdministrationAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkAdministrationAccess ( _            ' VTable offset = 24
     BYVAL bNetworkAdministrationAccess AS LONG _       ' __in BOOL bNetworkAdministrationAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkTransactionAccess ( _               ' VTable offset = 28
     BYREF pbNetworkTransactionAccess AS LONG _         ' __out BOOL *pbNetworkTransactionAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkTransactionAccess ( _               ' VTable offset = 32
     BYVAL bNetworkTransactionAccess AS LONG _          ' __in BOOL bNetworkTransactionAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkClientAccess ( _                    ' VTable offset = 36
     BYREF pbNetworkClientAccess AS LONG _              ' __out BOOL *pbNetworkClientAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkClientAccess ( _                    ' VTable offset = 40
     BYVAL bNetworkClientAccess AS LONG _               ' __in BOOL bNetworkClientAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkTIPAccess ( _                       ' VTable offset = 44
     BYREF pbNetworkTIPAccess AS LONG _                 ' __out BOOL *pbNetworkTIPAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkTIPAccess ( _                       ' VTable offset = 48
     BYVAL bNetworkTIPAccess AS LONG _                  ' __in BOOL bNetworkTIPAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXAAccess ( _                               ' VTable offset = 52
     BYREF pbXAAccess AS LONG _                         ' __out BOOL *pbXAAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetXAAccess ( _                               ' VTable offset = 56
     BYVAL bXAAccess AS LONG _                          ' __in BOOL bXAAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartDtcService ( _                         ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDtcNetworkAccessConfig2 methods
   ' =====================================================================================
   METHOD GetNetworkInboundAccess ( _                   ' VTable offset = 64
     BYREF pbInbound AS LONG _                          ' __out BOOL *pbInbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkOutboundAccess ( _                  ' VTable offset = 68
     BYREF pbOutbound AS LONG _                         ' __out BOOL *pbOutbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkInboundAccess ( _                   ' VTable offset = 72
     BYVAL bInbound AS LONG _                           ' __in BOOL bInbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkOutboundAccess ( _                  ' VTable offset = 76
     BYVAL bOutbound AS LONG _                          ' __in BOOL bOutbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthenticationLevel ( _                    ' VTable offset = 80
     BYREF pAuthLevel AS LONG _                         ' __out AUTHENTICATION_LEVEL *pAuthLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAuthenticationLevel ( _                    ' VTable offset = 84
     BYVAL AuthLevel AS LONG _                          ' __in AUTHENTICATION_LEVEL AuthLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcNetworkAccessConfig2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDtcNetworkAccessConfig3
' IID = A7AA013B-EB7D-4F42-B41C-B2DEC09AE034
' Inherited interface = IDtcNetworkAccessConfig2
' ########################################################################################

#IF NOT %DEF(%IDtcNetworkAccessConfig3_INTERFACE_DEFINED)
    %IDtcNetworkAccessConfig3_INTERFACE_DEFINED = 1

$IID_IDtcNetworkAccessConfig3 = GUID$("{76E4B4F3-2CA5-466B-89D5-FD218EE75B49}")

INTERFACE IDtcNetworkAccessConfig3 $IID_IDtcNetworkAccessConfig3

   INHERIT IUnknown

   ' =====================================================================================
   ' IDtcNetworkAccessConfig methods
   ' =====================================================================================
   METHOD PullComplete ( _                              ' VTable offset = 12
     BYREF pbAnyNetworkAccess AS LONG _                 ' __out BOOL *pbAnyNetworkAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAnyNetworkAccess ( _                       ' VTable offset = 16
     BYVAL bAnyNetworkAccess AS LONG _                  ' __in BOOL bAnyNetworkAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkAdministrationAccess ( _            ' VTable offset = 20
     BYREF pbNetworkAdministrationAccess AS LONG _      ' __out BOOL *pbNetworkAdministrationAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkAdministrationAccess ( _            ' VTable offset = 24
     BYVAL bNetworkAdministrationAccess AS LONG _       ' __in BOOL bNetworkAdministrationAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkTransactionAccess ( _               ' VTable offset = 28
     BYREF pbNetworkTransactionAccess AS LONG _         ' __out BOOL *pbNetworkTransactionAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkTransactionAccess ( _               ' VTable offset = 32
     BYVAL bNetworkTransactionAccess AS LONG _          ' __in BOOL bNetworkTransactionAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkClientAccess ( _                    ' VTable offset = 36
     BYREF pbNetworkClientAccess AS LONG _              ' __out BOOL *pbNetworkClientAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkClientAccess ( _                    ' VTable offset = 40
     BYVAL bNetworkClientAccess AS LONG _               ' __in BOOL bNetworkClientAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkTIPAccess ( _                       ' VTable offset = 44
     BYREF pbNetworkTIPAccess AS LONG _                 ' __out BOOL *pbNetworkTIPAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkTIPAccess ( _                       ' VTable offset = 48
     BYVAL bNetworkTIPAccess AS LONG _                  ' __in BOOL bNetworkTIPAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXAAccess ( _                               ' VTable offset = 52
     BYREF pbXAAccess AS LONG _                         ' __out BOOL *pbXAAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetXAAccess ( _                               ' VTable offset = 56
     BYVAL bXAAccess AS LONG _                          ' __in BOOL bXAAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartDtcService ( _                         ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDtcNetworkAccessConfig2 methods
   ' =====================================================================================
   METHOD GetNetworkInboundAccess ( _                   ' VTable offset = 64
     BYREF pbInbound AS LONG _                          ' __out BOOL *pbInbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkOutboundAccess ( _                  ' VTable offset = 68
     BYREF pbOutbound AS LONG _                         ' __out BOOL *pbOutbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkInboundAccess ( _                   ' VTable offset = 72
     BYVAL bInbound AS LONG _                           ' __in BOOL bInbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkOutboundAccess ( _                  ' VTable offset = 76
     BYVAL bOutbound AS LONG _                          ' __in BOOL bOutbound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthenticationLevel ( _                    ' VTable offset = 80
     BYREF pAuthLevel AS LONG _                         ' __out AUTHENTICATION_LEVEL *pAuthLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAuthenticationLevel ( _                    ' VTable offset = 84
     BYVAL AuthLevel AS LONG _                          ' __in AUTHENTICATION_LEVEL AuthLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDtcNetworkAccessConfig3 methods
   ' =====================================================================================
   METHOD GetLUAccess ( _                               ' VTable offset = 88
     BYREF pbLUAccess AS LONG _                         ' __out BOOL *pbLUAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLUAccess ( _                               ' VTable offset = 92
     BYVAL bLUAccess AS LONG _                          ' __in BOOL bLUAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDtcNetworkAccessConfig3_INTERFACE_DEFINED__ */
