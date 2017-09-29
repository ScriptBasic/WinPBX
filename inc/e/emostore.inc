' ########################################################################################
' Microsoft Windows
' File: emostore.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EMOSTORE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "adoint.inc"
#INCLUDE ONCE "cdoex.inc"
#INCLUDE ONCE "cdoexm.inc"

' ========================================================================================
' CDOEXMStoreDBStatus enum
' ========================================================================================

%cdoexmOnline      = 0
%cdoexmOffline     = &H1
%cdoexmMounting    = &H2
%cdoexmDismounting = &H3

' ========================================================================================
' CDOEXMFolderTreeType enum
' ========================================================================================

%cdoexmGeneralPurpose = 0
%cdoexmMAPI           = &H1
%cdoexmNNTPOnly       = &H2

' ========================================================================================
' CDOEXMServerType enum
' ========================================================================================

%cdoexmBackEnd  = 0
%cdoexmFrontEnd = &H1


' ########################################################################################
' Interface name = IExchangeServer
' IID = {25150F47-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IExchangeServer_INTERFACE_DEFINED)
    %CDO_IExchangeServer_INTERFACE_DEFINED = 1

INTERFACE CDO_IExchangeServer $IID_CDO_IExchangeServer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource ( _                          ' VTable offset = 28
   ) AS CDO_IDataSource2                                ' __retval_out IDataSource2 **varDataSource
   ' =====================================================================================
   PROPERTY GET Fields ( _                              ' VTable offset = 32
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *varName
   ' =====================================================================================
   PROPERTY GET ExchangeVersion ( _                     ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *varExchangeVersion
   ' =====================================================================================
   PROPERTY GET StorageGroups ( _                       ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *varStorageGroups
   ' =====================================================================================
   PROPERTY GET SubjectLoggingEnabled ( _               ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pSubjectLoggingEnabled
   ' =====================================================================================
   PROPERTY SET SubjectLoggingEnabled ( _               ' VTable offset = 52
     BYVAL varSubjectLoggingEnabled AS INTEGER _        ' __in VARIANT_BOOL varSubjectLoggingEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageTrackingEnabled ( _              ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pMessageTrackingEnabled
   ' =====================================================================================
   PROPERTY SET MessageTrackingEnabled ( _              ' VTable offset = 60
     BYVAL varMessageTrackingEnabled AS INTEGER _       ' __in VARIANT_BOOL varMessageTrackingEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysBeforeLogFileRemoval ( _            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pDaysBeforeLogFileRemoval
   ' =====================================================================================
   PROPERTY SET DaysBeforeLogFileRemoval ( _            ' VTable offset = 68
     BYVAL varDaysBeforeLogFileRemoval AS LONG _        ' __in long varDaysBeforeLogFileRemoval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerType ( _                          ' VTable offset = 72
   ) AS LONG                                            ' __retval_out CDOEXMServerType *pServerType
   ' =====================================================================================
   PROPERTY SET ServerType ( _                          ' VTable offset = 76
     BYVAL varServerType AS LONG _                      ' __in CDOEXMServerType varServerType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DirectoryServer ( _                     ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *varDirectoryServer
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 84
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IExchangeServer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IStorageGroup
' IID = {25150F46-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IStorageGroup_INTERFACE_DEFINED)
    %CDO_IStorageGroup_INTERFACE_DEFINED = 1

INTERFACE CDO_IStorageGroup $IID_CDO_IStorageGroup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource ( _                          ' VTable offset = 28
   ) AS CDO_IDataSource2                                ' __retval_out IDataSource2 **varDataSource
   ' =====================================================================================
   PROPERTY GET Fields ( _                              ' VTable offset = 32
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 40
     BYVAL varName AS WSTRING _                         ' __in BSTR varName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublicStoreDBs ( _                      ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *varPublicStoreDBs
   ' =====================================================================================
   PROPERTY GET MailboxStoreDBs ( _                     ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *varMailboxStoreDBs
   ' =====================================================================================
   PROPERTY GET LogFilePath ( _                         ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *varLogFilePath
   ' =====================================================================================
   PROPERTY GET SystemFilePath ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *varSystemFilePath
   ' =====================================================================================
   PROPERTY GET CircularLogging ( _                     ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pCircularLogging
   ' =====================================================================================
   PROPERTY SET CircularLogging ( _                     ' VTable offset = 64
     BYVAL varCircularLogging AS INTEGER _              ' __in VARIANT_BOOL varCircularLogging
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ZeroDatabase ( _                        ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pZeroDatabase
   ' =====================================================================================
   PROPERTY SET ZeroDatabase ( _                        ' VTable offset = 72
     BYVAL varZeroDatabase AS INTEGER _                 ' __in VARIANT_BOOL varZeroDatabase
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 76
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD MoveLogFiles ( _                              ' VTable offset = 80
     BYVAL LogFilePath AS WSTRING _                     ' __in BSTR LogFilePath
   , OPTIONAL BYVAL LONG _                              ' __opt_in long Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveSystemFiles ( _                           ' VTable offset = 84
     BYVAL SystemFilePath AS WSTRING _                  ' __in BSTR SystemFilePath
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in long Flags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IStorageGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPublicStoreDB
' IID = {25150F44-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IPublicStoreDB_INTERFACE_DEFINED)
    %CDO_IPublicStoreDB_INTERFACE_DEFINED = 1

INTERFACE CDO_IPublicStoreDB $IID_CDO_IPublicStoreDB

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource ( _                          ' VTable offset = 28
   ) AS CDO_IDataSource2                                ' __retval_out IDataSource2 **varDataSource
   ' =====================================================================================
   PROPERTY GET Fields ( _                              ' VTable offset = 32
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 40
     BYVAL varName AS WSTRING _                         ' __in BSTR varName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FolderTree ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pFolderTree
   ' =====================================================================================
   PROPERTY SET FolderTree ( _                          ' VTable offset = 48
     BYVAL varFolderTree AS WSTRING _                   ' __in BSTR varFolderTree
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DBPath ( _                              ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *varDBPath
   ' =====================================================================================
   PROPERTY GET SLVPath ( _                             ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *varSLVPath
   ' =====================================================================================
   PROPERTY GET Status ( _                              ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CDOEXMStoreDBStatus *varStatus
   ' =====================================================================================
   PROPERTY GET Enabled ( _                             ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled ( _                             ' VTable offset = 68
     BYVAL varEnabled AS INTEGER _                      ' __in VARIANT_BOOL varEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StoreQuota ( _                          ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *pStoreQuota
   ' =====================================================================================
   PROPERTY SET StoreQuota ( _                          ' VTable offset = 76
     BYVAL varStoreQuota AS LONG _                      ' __in long varStoreQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HardLimit ( _                           ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *pHardLimit
   ' =====================================================================================
   PROPERTY SET HardLimit ( _                           ' VTable offset = 84
     BYVAL varHardLimit AS LONG _                       ' __in long varHardLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemSizeLimit ( _                       ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *pItemSizeLimit
   ' =====================================================================================
   PROPERTY SET ItemSizeLimit ( _                       ' VTable offset = 92
     BYVAL varItemSizeLimit AS LONG _                   ' __in long varItemSizeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysBeforeItemExpiration ( _            ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *pDaysBeforeItemExpiration
   ' =====================================================================================
   PROPERTY SET DaysBeforeItemExpiration ( _            ' VTable offset = 100
     BYVAL varDaysBeforeItemExpiration AS LONG _        ' __in long varDaysBeforeItemExpiration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysBeforeGarbageCollection ( _         ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pDaysBeforeGarbageCollection
   ' =====================================================================================
   PROPERTY SET DaysBeforeGarbageCollection ( _         ' VTable offset = 108
     BYVAL varDaysBeforeGarbageCollection AS LONG _     ' __in long varDaysBeforeGarbageCollection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GarbageCollectOnlyAfterBackup ( _       ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pGarbageCollectOnlyAfterBackup
   ' =====================================================================================
   PROPERTY SET GarbageCollectOnlyAfterBackup ( _       ' VTable offset = 116
     BYVAL varGarbageCollectOnlyAfterBackup AS INTEGER _ ' __in VARIANT_BOOL varGarbageCollectOnlyAfterBackup
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 120
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD MoveDataFiles ( _                             ' VTable offset = 124
     BYVAL DBPath AS WSTRING _                          ' __in BSTR DBPath
   , BYVAL SLVPath AS WSTRING _                         ' __in BSTR SLVPath
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in long Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD Mount ( _                                     ' VTable offset = 128
     OPTIONAL BYVAL Timeout AS LONG _                   ' __opt_in long Timeout
   )                                                    ' void
   ' =====================================================================================
   METHOD Dismount ( _                                  ' VTable offset = 132
     OPTIONAL BYVAL Timeout AS LONG _                   ' __opt_in long Timeout
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IPublicStoreDB_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMailboxStoreDB
' IID = {25150F45-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IMailboxStoreDB_INTERFACE_DEFINED)
    %CDO_IMailboxStoreDB_INTERFACE_DEFINED = 1

INTERFACE CDO_IMailboxStoreDB $IID_CDO_IMailboxStoreDB

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource ( _                          ' VTable offset = 28
   ) AS CDO_IDataSource2                                ' __retval_out IDataSource2 **varDataSource
   ' =====================================================================================
   PROPERTY GET Fields ( _                              ' VTable offset = 32
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 40
     BYVAL varName AS WSTRING _                         ' __in BSTR varName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublicStoreDB ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pPublicStoreDB
   ' =====================================================================================
   PROPERTY SET PublicStoreDB ( _                       ' VTable offset = 48
     BYVAL varPublicStoreDB AS WSTRING _                ' __in BSTR varPublicStoreDB
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfflineAddressList ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pOfflineAddressList
   ' =====================================================================================
   PROPERTY SET OfflineAddressList ( _                  ' VTable offset = 56
     BYVAL varOfflineAddressList AS WSTRING _           ' __in BSTR varOfflineAddressList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DBPath ( _                              ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *varDBPath
   ' =====================================================================================
   PROPERTY GET SLVPath ( _                             ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *varSLVPath
   ' =====================================================================================
   PROPERTY GET Status ( _                              ' VTable offset = 68
   ) AS LONG                                            ' __retval_out CDOEXMStoreDBStatus *varStatus
   ' =====================================================================================
   PROPERTY GET Enabled ( _                             ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled ( _                             ' VTable offset = 76
     BYVAL varEnabled AS INTEGER _                      ' __in VARIANT_BOOL varEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StoreQuota ( _                          ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *pStoreQuota
   ' =====================================================================================
   PROPERTY SET StoreQuota ( _                          ' VTable offset = 84
     BYVAL varStoreQuota AS LONG _                      ' __in long varStoreQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverQuotaLimit ( _                      ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *pOverQuotaLimit
   ' =====================================================================================
   PROPERTY SET OverQuotaLimit ( _                      ' VTable offset = 92
     BYVAL varOverQuotaLimit AS LONG _                  ' __in long varOverQuotaLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HardLimit ( _                           ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *pHardLimit
   ' =====================================================================================
   PROPERTY SET HardLimit ( _                           ' VTable offset = 100
     BYVAL varHardLimit AS LONG _                       ' __in long varHardLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysBeforeGarbageCollection ( _         ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pDaysBeforeGarbageCollection
   ' =====================================================================================
   PROPERTY SET DaysBeforeGarbageCollection ( _         ' VTable offset = 108
     BYVAL varDaysBeforeGarbageCollection AS LONG _     ' __in long varDaysBeforeGarbageCollection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysBeforeDeletedMailboxCleanup ( _     ' VTable offset = 112
   ) AS LONG                                            ' __in long varDaysBeforeDeletedMailboxCleanup
   ' =====================================================================================
   PROPERTY SET DaysBeforeDeletedMailboxCleanup ( _     ' VTable offset = 116
     BYVAL varDaysBeforeDeletedMailboxCleanup AS LONG _ ' __in long varDaysBeforeDeletedMailboxCleanup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GarbageCollectOnlyAfterBackup ( _       ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pGarbageCollectOnlyAfterBackup
   ' =====================================================================================
   PROPERTY SET GarbageCollectOnlyAfterBackup ( _       ' VTable offset = 124
     BYVAL varGarbageCollectOnlyAfterBackup AS INTEGER _ ' __in VARIANT_BOOL varGarbageCollectOnlyAfterBackup
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 128
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD MoveDataFiles ( _                             ' VTable offset = 132
     BYVAL DBPath AS WSTRING _                          ' __in BSTR DBPath
   , BYVAL SLVPath AS WSTRING _                         ' __in BSTR SLVPath
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in long Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD Mount ( _                                     ' VTable offset = 136
     OPTIONAL BYVAL Timeout AS LONG _                   ' __opt_in long Timeout
   )                                                    ' void
   ' =====================================================================================
   METHOD Dismount ( _                                  ' VTable offset = 140
     OPTIONAL BYVAL Timeout AS LONG _                   ' __opt_in long Timeout
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IMailboxStoreDB_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IFolderTree
' IID = {25150F43-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IFolderTree_INTERFACE_DEFINED)
    %CDO_IFolderTree_INTERFACE_DEFINED = 1

INTERFACE CDO_IFolderTree $IID_CDO_IFolderTree

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource ( _                          ' VTable offset = 28
   ) AS CDO_IDataSource2                                ' __retval_out IDataSource2 **varDataSource
   ' =====================================================================================
   PROPERTY GET Fields ( _                              ' VTable offset = 32
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 40
     BYVAL varName AS WSTRING _                         ' __in BSTR varName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StoreDBs ( _                            ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *varStoreDBs
   ' =====================================================================================
   PROPERTY GET TreeType ( _                            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out CDOEXMFolderTreeType *varTreeType
   ' =====================================================================================
   PROPERTY GET RootFolderURL ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *varRootFolderURL
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 56
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IFolderTree_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDataSource2
' IID = {25150F48-5734-11D2-A593-00C04F990D8A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDataSource
' ########################################################################################

#IF NOT %DEF(%CDO_IDataSource2_INTERFACE_DEFINED)
    %CDO_IDataSource2_INTERFACE_DEFINED = 1

INTERFACE CDO_IDataSource2 $IID_CDO_IDataSource2

   INHERIT IDispatch

   ' =====================================================================================
   ' IDataSource Methods
   ' =====================================================================================
   PROPERTY GET SourceClass <207> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *varSourceClass
   ' =====================================================================================
   PROPERTY GET Source <208> ( _                        ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **varSource
   ' =====================================================================================
   PROPERTY GET IsDirty <209> ( _                       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsDirty
   ' =====================================================================================
   PROPERTY SET IsDirty <209> ( _                       ' VTable offset = 40
     BYVAL varIsDirty AS INTEGER _                      ' __in VARIANT_BOOL varIsDirty
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceURL <210> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *varSourceURL
   ' =====================================================================================
   PROPERTY GET ActiveConnection <211> ( _              ' VTable offset = 48
   ) AS ADOConnection                                   ' __retval_out _Connection **varActiveConnection
   ' =====================================================================================
   METHOD SaveToObject <251> ( _                        ' VTable offset = 52
     BYVAL Source AS IUnknown _                         ' __in IUnknown *Source
   , BYVAL InterfaceName AS WSTRING _                   ' __in BSTR InterfaceName
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenObject <252> ( _                          ' VTable offset = 56
     BYVAL Source AS IUnknown _                         ' __in IUnknown *Source
   , BYVAL InterfaceName AS WSTRING _                   ' __in BSTR InterfaceName
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveTo <253> ( _                              ' VTable offset = 60
     BYVAL SourceURL AS WSTRING _                       ' __in BSTR SourceURL
   , OPTIONAL BYVAL ActiveConnection AS IDispatch _     ' __opt_in IDispatch *ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <254> ( _                                ' VTable offset = 64
     BYVAL SourceURL AS WSTRING _                       ' __in BSTR SourceURL
   , OPTIONAL BYVAL ActiveConnection AS IDispatch _     ' __opt_in IDispatch *ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <255> ( _                                ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToContainer <256> ( _                     ' VTable offset = 72
     BYVAL ContainerURL AS WSTRING _                    ' __in BSTR ContainerURL
   , OPTIONAL BYVAL ActiveConnection AS IDispatch _     ' __opt_in IDispatch *ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDataSource2 Methods
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveToContainer ( _                           ' VTable offset = 80
     BYVAL ContainerURL AS WSTRING _                    ' __in BSTR ContainerURL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IDataSource2_INTERFACE_DEFINED__ */
