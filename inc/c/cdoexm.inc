' ########################################################################################
' Microsoft Windows
' File: cdoexm.inc
' Library name: CDOEXM
' Version: 6.0, Locale ID = 0
' Library GUID: {25150F00-5734-11D2-A593-00C04F990D8A}
' Path: C:\Archivos de programa\Microsoft Platform SDK for Windows Server 2003 R2\Lib\cdoexm.tlb
' Contents: Microsoft CDO for Exchange Management Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CDOEXM_INC = 1

$LIBID_CDOEXM = GUID$("{25150F00-5734-11D2-A593-00C04F990D8A}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CDO_ExchangeServer  = GUID$("{25150F27-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_FolderAdmin     = GUID$("{25150F22-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_FolderTree      = GUID$("{25150F23-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_Mailbox         = GUID$("{25150F21-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_MailboxStoreDB  = GUID$("{25150F25-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_MailGroup       = GUID$("{25150F1F-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_MailRecipient   = GUID$("{25150F20-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_PublicStoreDB   = GUID$("{25150F24-5734-11D2-A593-00C04F990D8A}")
$CLSID_CDO_StorageGroup    = GUID$("{25150F26-5734-11D2-A593-00C04F990D8A}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_CDO_IDataSource2      = GUID$("{25150F48-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IDistributionList = GUID$("{25150F3F-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IExchangeServer   = GUID$("{25150F47-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IFolderTree       = GUID$("{25150F43-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IMailboxStore     = GUID$("{25150F41-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IMailboxStoreDB   = GUID$("{25150F45-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IMailRecipient    = GUID$("{25150F40-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IPublicStoreDB    = GUID$("{25150F44-5734-11D2-A593-00C04F990D8A}")
$IID_CDO_IStorageGroup     = GUID$("{25150F46-5734-11D2-A593-00C04F990D8A}")

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "emostore.inc"

' ========================================================================================
' CDOEXMRestrictedAddressType enum
' ========================================================================================

%cdoexmAccept = 0
%cdoexmReject = &H1

' ========================================================================================
' CDOEXMDeliverAndRedirect enum
' ========================================================================================

%cdoexmRecipientOrForward = 0
%cdoexmDeliverToBoth      = &H1

' ########################################################################################
' Interface name = IDistributionList
' IID = {25150F3F-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IDistributionList_INTERFACE_DEFINED)
    %CDO_IDistributionList_INTERFACE_DEFINED = 1

INTERFACE CDO_IDistributionList $IID_CDO_IDistributionList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET HideDLMembership ( _                    ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pHideDLMembership
   ' =====================================================================================
   PROPERTY SET HideDLMembership ( _                    ' VTable offset = 32
     BYVAL varHideDLMembership AS INTEGER _             ' __in VARIANT_BOOL varHideDLMembership
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IDistributionList_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMailRecipient
' IID = {25150F40-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IMailRecipient_INTERFACE_DEFINED)
    %CDO_IMailRecipient_INTERFACE_DEFINED = 1

INTERFACE CDO_IMailRecipient $IID_CDO_IMailRecipient

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IncomingLimit ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pIncomingLimit
   ' =====================================================================================
   PROPERTY SET IncomingLimit ( _                       ' VTable offset = 32
     BYVAL varIncomingLimit AS LONG _                   ' __in long varIncomingLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutgoingLimit ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pOutgoingLimit
   ' =====================================================================================
   PROPERTY SET OutgoingLimit ( _                       ' VTable offset = 40
     BYVAL varOutgoingLimit AS LONG _                   ' __in long varOutgoingLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RestrictedAddressList ( _               ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pRestrictedAddressList
   ' =====================================================================================
   PROPERTY SET RestrictedAddressList ( _               ' VTable offset = 48
     BYVAL varRestrictedAddressList AS VARIANT _        ' __in VARIANT varRestrictedAddressList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RestrictedAddresses ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out CDOEXMRestrictedAddressType *pRestrictedAddresses
   ' =====================================================================================
   PROPERTY SET RestrictedAddresses ( _                 ' VTable offset = 56
     BYVAL varRestrictedAddresses AS LONG _             ' __in CDOEXMRestrictedAddressType varRestrictedAddresses
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForwardTo ( _                           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pForwardTo
   ' =====================================================================================
   PROPERTY SET ForwardTo ( _                           ' VTable offset = 64
     BYVAL varForwardTo AS WSTRING _                    ' __in BSTR varForwardTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForwardingStyle ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out CDOEXMDeliverAndRedirect *pForwardingStyle
   ' =====================================================================================
   PROPERTY SET ForwardingStyle ( _                     ' VTable offset = 72
     BYVAL varForwardingStyle AS LONG _                 ' __in CDOEXMDeliverAndRedirect varForwardingStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HideFromAddressBook ( _                 ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pHideFromAddressBook
   ' =====================================================================================
   PROPERTY SET HideFromAddressBook ( _                 ' VTable offset = 80
     BYVAL varHideFromAddressBook AS INTEGER _          ' __in VARIANT_BOOL varHideFromAddressBook
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET X400Email ( _                           ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pX400Email
   ' =====================================================================================
   PROPERTY SET X400Email ( _                           ' VTable offset = 88
     BYVAL varX400Email AS WSTRING _                    ' __in BSTR varX400Email
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SMTPEmail ( _                           ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pSMTPEmail
   ' =====================================================================================
   PROPERTY SET SMTPEmail ( _                           ' VTable offset = 96
     BYVAL varSMTPEmail AS WSTRING _                    ' __in BSTR varSMTPEmail
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProxyAddresses ( _                      ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pProxyAddresses
   ' =====================================================================================
   PROPERTY SET ProxyAddresses ( _                      ' VTable offset = 104
     BYVAL varProxyAddresses AS VARIANT _               ' __in VARIANT varProxyAddresses
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoGenerateEmailAddresses ( _          ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pAutoGenerateEmailAddresses
   ' =====================================================================================
   PROPERTY SET AutoGenerateEmailAddresses ( _          ' VTable offset = 112
     BYVAL varAutoGenerateEmailAddresses AS INTEGER _   ' __in VARIANT_BOOL varAutoGenerateEmailAddresses
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Alias ( _                               ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pAlias
   ' =====================================================================================
   PROPERTY SET Alias ( _                               ' VTable offset = 120
     BYVAL varAlias AS WSTRING _                        ' __in BSTR varAlias
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TargetAddress ( _                       ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *varTargetAddress
   ' =====================================================================================
   METHOD MailEnable ( _                                ' VTable offset = 128
     OPTIONAL BYVAL TargetMailAddress AS WSTRING _      ' __opt_in BSTR TargetMailAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD MailDisable ( _                               ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IMailRecipient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMailboxStore
' IID = {25150F41-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IMailboxStore_INTERFACE_DEFINED)
    %CDO_IMailboxStore_INTERFACE_DEFINED = 1

INTERFACE CDO_IMailboxStore $IID_CDO_IMailboxStore

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EnableStoreDefaults ( _                 ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pEnableStoreDefaults
   ' =====================================================================================
   PROPERTY SET EnableStoreDefaults ( _                 ' VTable offset = 32
     BYVAL varEnableStoreDefaults AS VARIANT _          ' __in VARIANT varEnableStoreDefaults
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StoreQuota ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pStoreQuota
   ' =====================================================================================
   PROPERTY SET StoreQuota ( _                          ' VTable offset = 40
     BYVAL varStoreQuota AS LONG _                      ' __in long varStoreQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverQuotaLimit ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pOverQuotaLimit
   ' =====================================================================================
   PROPERTY SET OverQuotaLimit ( _                      ' VTable offset = 48
     BYVAL varOverQuotaLimit AS LONG _                  ' __in long varOverQuotaLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HardLimit ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pHardLimit
   ' =====================================================================================
   PROPERTY SET HardLimit ( _                           ' VTable offset = 56
     BYVAL varHardLimit AS LONG _                       ' __in long varHardLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverrideStoreGarbageCollection ( _      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pOverrideStoreGarbageCollection
   ' =====================================================================================
   PROPERTY SET OverrideStoreGarbageCollection ( _      ' VTable offset = 64
     BYVAL varOverrideStoreGarbageCollection AS INTEGER _ ' __in VARIANT_BOOL varOverrideStoreGarbageCollection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysBeforeGarbageCollection ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pDaysBeforeGarbageCollection
   ' =====================================================================================
   PROPERTY SET DaysBeforeGarbageCollection ( _         ' VTable offset = 72
     BYVAL varDaysBeforeGarbageCollection AS LONG _     ' __in long varDaysBeforeGarbageCollection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GarbageCollectOnlyAfterBackup ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pGarbageCollectOnlyAfterBackup
   ' =====================================================================================
   PROPERTY SET GarbageCollectOnlyAfterBackup ( _       ' VTable offset = 80
     BYVAL varGarbageCollectOnlyAfterBackup AS INTEGER _ ' __in VARIANT_BOOL varGarbageCollectOnlyAfterBackup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Delegates ( _                           ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *pDelegates
   ' =====================================================================================
   PROPERTY SET Delegates ( _                           ' VTable offset = 88
     BYVAL varDelegates AS VARIANT _                    ' __in VARIANT varDelegates
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomeMDB ( _                             ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *varHomeMDB
   ' =====================================================================================
   PROPERTY GET RecipientLimit ( _                      ' VTable offset = 96
   ) AS LONG                                            '__retval_out long *pRecipientLimit
   ' =====================================================================================
   PROPERTY SET RecipientLimit ( _                      ' VTable offset = 100
     BYVAL varRecipientLimit AS LONG _                  ' __in long varRecipientLimit
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateMailbox ( _                             ' VTable offset = 104
     BYVAL HomeMDBURL AS WSTRING _                      ' __in BSTR HomeMDBURL
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMailbox ( _                             ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveMailbox ( _                               ' VTable offset = 112
     BYVAL HomeMDBURL AS WSTRING _                      ' __in BSTR HomeMDBURL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IMailboxStore_INTERFACE_DEFINED__ */


#IF NOT %DEF(%CDOEXMInterfaces_MODULE_DEFINED)
    %CDOEXMInterfaces_MODULE_DEFINED = 1

' ========================================================================================
' CDOEXMInterfaces
' IID: {25150F60-5734-11D2-A593-00C04F990D8A}
' Interfaces supported by Microsoft CDO for Exchange Management
' ========================================================================================

$$cdoexmIMailRecipient    = "IMailRecipient"$$
$$cdoexmIMailboxStore     = "IMailboxStore"$$
$$cdoexmIDistributionList = "IDistributionList"$$
$$cdoexmIExchangeServer   = "IExchangeServer"$$
$$cdoexmIFolderTree       = "IFolderTree"$$
$$cdoexmIPublicStoreDB    = "IPublicStoreDB"$$
$$cdoexmIMailboxStoreDB   = "IMailboxStoreDB"$$
$$cdoexmIStorageGroup     = "IStorageGroup"$$
$$cdoexmIFolderAdmin      = "IFolderAdmin"$$
$$cdoexmIADs              = "IADs"$$

#ENDIF   ' #IF NOT %DEF(%CDOEXMInterfaces_MODULE_DEFINED)
