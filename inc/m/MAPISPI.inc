' ########################################################################################
' Microsoft Windows
' File: MAPISPI.inc
' Contents: Defines the calls and structures exchanged between MAPI or the spooler and the
' MAPI service providers.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPISPI_INC = 1

#INCLUDE ONCE "mapix.inc"

'/*   The MAPI SPI has a version number.  MAPIX.DLL knows and supports
' *   one or more versions of the SPI.  Each provider supports one or
' *   more versions of the SPI.  Checks are performed in both MAPIX.DLL
' *   and in the provider to ensure that they agree to use exactly one
' *   version of the MAPI SPI.
' *
' *   The SPI version number is composed of a major (8-bit) version,
' *   minor (8-bit) version, and micro (16-bit) version.  The first
' *   retail ship of MAPI 1.0 is expected to be version 1.0.0.
' *   The major version number changes rarely.
' *   The minor version number changes opon each retail ship of
' *   MAPI if the SPI has been modified.
' *   The micro version number changes internally at Microsoft
' *   during development of MAPI.
' *
' *   The version of the SPI documented by this set of header files
' *   is ALWAYS known as "CURRENT_SPI_VERSION".  If you write a
' *   service provider, and get a new set of header files, and update
' *   your code to the new interface, you'll be at the "current" version.
' */
%CURRENT_SPI_VERSION   = &H00010010&

'/*   Here are some well-known SPI version numbers:
' *   (These will eventually be useful for provider-writers who
' *   might choose to make provider DLLs that support more than
' *   one version of the MAPI SPI.
' */
%PDK1_SPI_VERSION   = &H00010000& ' /* 0.1.0  MAPI PDK1 Spring 1993 */

%PDK2_SPI_VERSION   = &H00010008& ' /* 0.1.8  MAPI PDK2 Spring 1994 */

%PDK3_SPI_VERSION   = &H00010010& ' /* 0.1.16 MAPI PDK3 Fall 1994   */

'/*
' * Forward declaration of interface pointers specific to the service
' * provider interface.
' */

'/* IMAPISupport Interface -------------------------------------------------- */

'/* Notification key structure for the MAPI notification engine */

' // Size = 8 bytes
TYPE NOTIFKEY DWORD
   cb AS DWORD                 ' ULONG  /* How big the key is */
   ab(%MAPI_DIM - 1) AS BYTE   ' BYTE   /* Key contents */ [variable-length array]
END TYPE

'/* For Subscribe() */

%NOTIFY_SYNC             = &H40000000???

'/* For Notify() */

%NOTIFY_CANCELED         = &H80000000???


'/* From the Notification Callback function (well, this is really a ulResult) */

%CALLBACK_DISCONTINUE    = &H80000000???

'/* For Transport's SpoolerNotify() */

%NOTIFY_NEWMAIL          = &H00000001???
%NOTIFY_READYTOSEND      = &H00000002???
%NOTIFY_SENTDEFERRED     = &H00000004???
%NOTIFY_CRITSEC          = &H00001000???
%NOTIFY_NONCRIT          = &H00002000???
%NOTIFY_CONFIG_CHANGE    = &H00004000???
%NOTIFY_CRITICAL_ERROR   = &H10000000???

'/* For Message Store's SpoolerNotify() */

%NOTIFY_NEWMAIL_RECEIVED = &H20000000???

'/* For ModifyStatusRow() */

%STATUSROW_UPDATE        = &H10000000???

'/* For IStorageFromStream() */

%STGSTRM_RESET           = &H00000000???
%STGSTRM_CURRENT         = &H10000000???
%STGSTRM_MODIFY          = &H00000002???
%STGSTRM_CREATE          = &H00001000???

'/* For GetOneOffTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

'/* For CreateOneOff() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */
'/****** MAPI_SEND_NO_RICH_INFO   ((ULONG) 0x00010000) */

'/* For ReadReceipt() */
%MAPI_NON_READ         = &H00000001???

'/* For DoConfigPropSheet() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

'/* Preprocessor calls: */

'/* PreprocessMessage, first ordinal in RegisterPreprocessor(). */

DECLARE FUNCTION PreprocessMessage IMPORT "MAPI32.DLL" ALIAS "PreprocessMessage" ( _
   BYVAL lpvSession AS IUnknown _                       ' __in LPVOID lpvSession
 , BYVAL lpMessage AS IMessage _                        ' __in LPMESSAGE lpMessage
 , BYVAL lpAdrBook AS IAddrBook _                       ' __in LPADRBOOK lpAdrBook
 , BYVAL lpFolder AS IMAPIFolder _                      ' __in LPMAPIFOLDER lpFolder
 , BYVAL AllocateBuffer AS DWORD _                      ' __in LPALLOCATEBUFFER AllocateBuffer
 , BYVAL AllocateMore AS DWORD _                        ' __in LPALLOCATEMORE AllocateMore
 , BYVAL FreeBuffer AS DWORD _                          ' __in LPFREEBUFFER FreeBuffer
 , BYREF lpcOutbound AS DWORD _                         ' __out ULONG * lpcOutbound
 , BYREF lpppMessage AS IMessage _                      ' __out LPMESSAGE * * lpppMessage
 , BYREF lppRecipList AS DWORD _                        ' __out LPADRLIST * lppRecipList
 ) AS LONG                                              ' HRESULT

'/* RemovePreprocessInfo, second ordinal in RegisterPreprocessor(). */

DECLARE FUNCTION RemovePreprocessInfo IMPORT "MAPI32.DLL" ALIAS "RemovePreprocessInfo" ( _
   BYVAL lpMessage AS IMessage _                        ' __in LPMESSAGE lpMessage
 ) AS LONG                                              ' HRESULT


'/* Function pointer for GetReleaseInfo */

' ========================================================================================
' IMAPISupport interface
' $IID_IMAPISupport = GUID$("{0002030F-0000-0000-C000-000000000046}")
' The IMAPISupport interface provides implementations for tasks that are commonly
' performed by service providers and message service entry point functions. Service
' providers receive a pointer to their support object when MAPI calls their provider
' object's logon method; message services receive their support object pointer in the call
' to their entry point function.
' ========================================================================================
INTERFACE IMAPISupport $IID_IMAPISupport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemAllocRoutines ( _                       ' VTable offset = 16
     BYREF lpAllocateBuffer AS DWORD _                  ' __out LPALLOCATEBUFFER * lpAllocateBuffer
   , BYREF lpAllocateMore AS DWORD _                    ' __out LPALLOCATEMORE * lpAllocateMore
   , BYREF lpFreeBuffer AS DWORD _                      ' __out LPFREEBUFFER * lpFreeBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Subscribe ( _                                 ' VTable offset = 20
     BYVAL lpKey AS DWORD _                             ' __in LPNOTIFKEY lpKey
   , BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unsubscribe ( _                               ' VTable offset = 24
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 28
     BYVAL lpKey AS NOTIFKEY PTR _                      ' __in LPNOTIFKEY lpKey
   , BYVAL cNotification AS DWORD _                     ' __in ULONG cNotification
   , BYREF lpNotifications AS NOTIFICATION _            ' __in LPNOTIFICATION lpNotifications [array]
   , BYREF lpulFlags AS DWORD _                         ' __in_out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyStatusRow ( _                           ' VTable offset = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpColumnVals AS SPropValue PTR _             ' __in LPSPropValue lpColumnVals
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProfileSection ( _                        ' VTable offset = 36
     BYREF lpUid AS GUID _                              ' __in LPMAPIUID lpUid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppProfileObj AS IProfSect _                 ' __out LPPROFSECT * lppProfileObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterPreprocessor ( _                      ' VTable offset = 40
     BYREF lpMuid AS GUID _                             ' __in LPMAPIUID lpMuid
   , BYREF lpszAdrType AS ASCIIZ _                      ' __in LPTSTR lpszAdrType
   , BYREF lpszDLLName AS ASCIIZ _                      ' __in LPTSTR lpszDLLName
   , BYREF lpszPreprocess AS ASCIIZ _                   ' __in LPSTR /* String8! */ lpszPreprocess
   , BYREF lpszRemovePreprocessInfo AS ASCIIZ _         ' __in LPSTR /* String8! */ lpszRemovePreprocessInfo
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewUID ( _                                    ' VTable offset = 44
     BYREF lpMuid AS GUID _                             ' __in LPMAPIUID lpMuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeInvalid ( _                               ' VTable offset = 48
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpObject AS DWORD _                          ' __in LPVOID lpObject
   , BYVAL ulRefCount AS DWORD _                        ' __in ULONG ulRefCount
   , BYVAL cMethods AS DWORD _                          ' __in ULONG cMethods
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpoolerYield ( _                              ' VTable offset = 52
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpoolerNotify ( _                             ' VTable offset = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpvData AS DWORD _                           ' __in LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateOneOff ( _                              ' VTable offset = 60
     BYREF lpszName AS ASCIIZ _                         ' __in LPTSTR lpszName
   , BYREF lpszAdrType AS ASCIIZ _                      ' __in LPTSTR lpszAdrType
   , BYREF lpszAddress AS ASCIIZ _                      ' __in LPTSTR lpszAddress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcbEntryID AS DWORD _                       ' __out ULONG * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __out LPENTRYID * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProviderUID ( _                            ' VTable offset = 64
     BYREF lpProviderID AS GUID _                       ' __in LPMAPIUID lpProviderID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareEntryIDs ( _                           ' VTable offset = 68
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulCompareFlags AS DWORD _                    ' __in ULONG ulCompareFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenTemplateID ( _                            ' VTable offset = 72
     BYVAL cbTemplateID AS DWORD _                      ' __in ULONG cbTemplateID
   , BYVAL lpTemplateID AS ENTRYID PTR _                ' __in LPENTRYID lpTemplateID
   , BYVAL ulTemplateFlags AS DWORD _                   ' __in ULONG ulTemplateFlags
   , BYVAL lpMAPIPropData AS IUnknown _                 ' __in LPMAPIPROP lpMAPIPropData
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYREF lppMAPIPropNew AS IMAPIProp _                ' __out LPMAPIPROP * lppMAPIPropNew
   , BYVAL lpMAPIPropSibling AS IMAPIProp _             ' __in LPMAPIPROP lpMAPIPropSibling
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offset = 76
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulOpenFlags AS DWORD _                       ' __in ULONG ulOpenFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOneOffTable ( _                            ' VTable offset = 80
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Address ( _                                   ' VTable offset = 84
     BYREF lpulUIParam AS DWORD _                       ' __in_out ULONG_PTR * lpulUIParam
   , BYREF lpAdrParms AS ADRPARM _                      ' __in_out LPADRPARM lpAdrParms
   , BYVAL lppAdrList AS ADRLIST PTR _                  ' __in_out LPADRLIST * lppAdrList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Details ( _                                   ' VTable offset = 88
     BYREF lpulUIParam AS DWORD _                       ' __out ULONG * lpulUIParam
   , BYVAL lpfnDismiss AS DWORD _                       ' __in LPFNDISMISS lpfnDismiss
   , BYVAL lpvDismissContext AS DWORD _                 ' __in LPVOID lpvDismissContext
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL lpfButtonCallback AS DWORD _                 ' __in LPFNBUTTON lpfButtonCallback
   , BYVAL lpvButtonContext AS DWORD _                  ' __in LPVOID lpvButtonContext
   , BYVAL lpszButtonText AS DWORD _                    ' __in LPTSTR lpszButtonText
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewEntry ( _                                  ' VTable offset = 92
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbEIDContainer AS DWORD _                    ' __in ULONG cbEIDContainer
   , BYVAL lpEIDContainer AS ENTRYID PTR _              ' __in LPENTRYID lpEIDContainer
   , BYVAL cbEIDNewEntryTpl AS DWORD _                  ' __in ULONG cbEIDNewEntryTpl
   , BYVAL lpEIDNewEntryTpl AS ENTRYID PTR _            ' __in LPENTRYID lpEIDNewEntryTpl
   , BYREF lpcbEIDNewEntry AS DWORD _                   ' __out ULONG * lpcbEIDNewEntry
   , BYREF lppEIDNewEntry AS DWORD _                    ' __out LPENTRYID * lppEIDNewEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoConfigPropsheet ( _                         ' VTable offset = 96
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszTitle AS ASCIIZ _                        ' __in LPTSTR lpszTitle
   , BYVAL lpDisplayTable AS IMAPITable _               ' __in LPMAPITABLE lpDisplayTable
   , BYVAL lpConfigData AS IMAPIProp _                  ' __in LPMAPIPROP lpConfigData
   , BYVAL ulTopPage AS DWORD _                         ' __in ULONG ulTopPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyMessages ( _                              ' VTable offset = 100
     BYREF lpSrcInterface AS GUID _                     ' __in LPCIID lpSrcInterface
   , BYVAL lpSrcFolder AS DWORD _                       ' __in LPVOID lpSrcFolder
   , BYVAL lpMsgList AS ENTRYLIST PTR _                 ' __in LPENTRYLIST lpMsgList
   , BYREF lpDestInterface AS GUID _                    ' __in LPCIID lpDestInterface
   , BYVAL lpDestFolder AS DWORD _                      ' __in LPVOID lpDestFolder
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyFolder ( _                                ' VTable offset = 104
     BYREF lpSrcInterface AS GUID _                     ' __in LPCIID lpSrcInterface
   , BYVAL lpSrcFolder AS DWORD _                       ' __in LPVOID lpSrcFolder
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpDestInterface AS GUID _                    ' __in LPCIID lpDestInterface
   , BYVAL lpDestFolder AS DWORD _                      ' __in LPVOID lpDestFolder
   , BYREF lszNewFolderName AS ASCIIZ _                 ' __in LPTSTR lszNewFolderName
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoCopyTo ( _                                  ' VTable offset = 108
     BYREF lpSrcInterface AS GUID _                     ' __in LPCIID lpSrcInterface
   , BYVAL lpSrcObj AS DWORD _                          ' __in LPVOID lpSrcObj
   , BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpDestInterface AS GUID _                    ' __in LPCIID lpDestInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppProblems AS DWORD _                       ' __out LPSPropProblemArray * lppProblems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoCopyProps ( _                               ' VTable offset = 112
     BYREF lpSrcInterface AS GUID _                     ' __in LPCIID lpSrcInterface
   , BYVAL lpSrcObj AS DWORD _                          ' __in LPVOID lpSrcObj
   , BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpDestInterface AS GUID _                    ' __in LPCIID lpDestInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __in_out LPSPropProblemArray * lppProblems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoProgressDialog ( _                          ' VTable offset = 116
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppProgress AS IMAPIProgress _               ' __out LPMAPIPROGRESS * lppProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadReceipt ( _                               ' VTable offset = 120
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpReadMessage AS IMessage _                  ' __in LPMESSAGE lpReadMessage
   , BYREF lppEmptyMessage AS IMessage _                ' __in_out LPMESSAGE * lppEmptyMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareSubmit ( _                             ' VTable offset = 124
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYREF lpulFlags AS DWORD _                         ' __in_out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExpandRecips ( _                              ' VTable offset = 128
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYREF lpulFLags AS DWORD _                         ' __out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdatePAB ( _                                 ' VTable offset = 132
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoSentMail ( _                                ' VTable offset = 136
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenAddressBook ( _                           ' VTable offset = 140
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppAdrBook AS IAddrBook _                    ' __out LPADRBOOK * lppAdrBook
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Preprocess ( _                                ' VTable offset = 144
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompleteMsg ( _                               ' VTable offset = 148
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StoreLogoffTransports ( _                     ' VTable offset = 152
     BYREF lpulFlags AS DWORD _                         ' __in_out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StatusRecips ( _                              ' VTable offset = 156
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYVAL lpRecipList AS ADRLIST PTR _                 ' __in LPADRLIST lpRecipList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WrapStoreEntryID ( _                          ' VTable offset = 160
     BYVAL cbOrigEntry AS DWORD _                       ' __in ULONG cbOrigEntry
   , BYVAL lpOrigEntry AS ENTRYID PTR _                 ' __in LPENTRYID lpOrigEntry
   , BYREF lpcbWrappedEntry AS DWORD _                  ' __out ULONG * lpcbWrappedEntry
   , BYREF lppWrappedEntry AS DWORD _                   ' __out LPENTRYID * lppWrappedEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyProfile ( _                             ' VTable offset = 164
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IStorageFromStream ( _                        ' VTable offset = 168
     BYVAL lpUnkIn AS DWORD _                           ' __in LPUNKNOWN lpUnkIn
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppStorageOut AS IStorage _                  ' __out LPSTORAGE * lppStorageOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSvcConfigSupportObj ( _                    ' VTable offset = 172
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppSvcSupport AS IMAPISupport _              ' __out LPMAPISUP * lppSvcSupport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/********************************************************************/
'/*                                                                  */
'/*                     ADDRESS BOOK SPI                             */
'/*                                                                  */
'/********************************************************************/

'/* Address Book Provider ------------------------------------------------- */

'/* OpenTemplateID() */
%FILL_ENTRY            = &H00000001???

'/* For Logon() */

'/*#define AB_NO_DIALOG         ((ULONG) 0x00000001) in mapidefs.h */
'/*#define MAPI_UNICODE         ((ULONG) 0x80000000) in mapidefs.h */


' ========================================================================================
' IABProvider interface
' $IID_IABProvider = GUID$("{00020311-0000-0000-C000-000000000046}")
' The IABProvider interface provides a method to log on to an address book provider object
' and a method to invalidate an address book provider object.
' ========================================================================================
INTERFACE IABProvider $IID_IABProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 12
     BYREF lpulFlags AS DWORD _                         ' __in ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 16
     BYVAL lpMAPISup AS IMAPISupport _                  ' __in LPMAPISUP lpMAPISup
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulcbSecurity AS DWORD _                    ' __in ULONG * lpulcbSecurity
   , BYVAL lppbSecurity AS BYTE PTR _                   ' __in_out LPBYTE * lppbSecurity
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   , BYREF lppABLogon AS IABLogon _                     ' __out LPABLOGON * lppABLogon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* For GetOneOffTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

' ========================================================================================
' IABLogon interface
' $IID_IABLogon = GUID$("{00020314-0000-0000-C000-000000000046}")
' The IABLogon interface is used to access resources in an address book provider.
' ========================================================================================
INTERFACE IABLogon $IID_IABLogon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logoff ( _                                    ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offset = 20
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareEntryIDs ( _                           ' VTable offset = 24
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenStatusEntry ( _                           ' VTable offset = 36
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppMAPIStatus AS IMAPIStatus _               ' __out LPMAPISTATUS * lppMAPIStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenTemplateID ( _                            ' VTable offset = 40
     BYVAL cbTemplateID AS DWORD _                      ' __in ULONG cbTemplateID
   , BYVAL lpTemplateID AS DWORD _                      ' __in LPENTRYID lpTemplateID
   , BYVAL ulTemplateFlags AS DWORD _                   ' __in ULONG ulTemplateFlags
   , BYVAL lpMAPIPropData AS IMAPIProp _                ' __in LPMAPIPROP lpMAPIPropData
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYREF lppMAPIPropNew AS IMAPIProp _                ' __out LPMAPIPROP * lppMAPIPropNew
   , BYVAL lpMAPIPropSibling AS IMAPIProp _             ' __in LPMAPIPROP lpMAPIPropSibling
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOneOffTable ( _                            ' VTable offset = 44
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareRecips ( _                             ' VTable offset = 48
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpPropTagArray AS DWORD _                    ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lpRecipList AS ADRLIST PTR _                 ' __in LPADRLIST lpRecipList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'typedef HRESULT (STDMAPIINITCALLTYPE ABPROVIDERINIT)(
'   HINSTANCE          hInstance,
'   LPMALLOC           lpMalloc,
'   LPALLOCATEBUFFER   lpAllocateBuffer,
'   LPALLOCATEMORE     lpAllocateMore,
'   LPFREEBUFFER       lpFreeBuffer,
'   ULONG              ulFlags,
'   ULONG              ulMAPIVer,
'   ULONG *        lpulProviderVer,
'   LPABPROVIDER * lppABProvider
');


'/********************************************************************/
'/*                                                                  */
'/*                     TRANSPORT SPI                                */
'/*                                                                  */
'/********************************************************************/

'/* For DeinitTransport */

%DEINIT_NORMAL            = &H00000001???
%DEINIT_HURRY             = &H80000000???

'/* For TransportLogon */

'/* Flags that the Spooler may pass to the transport: */

%LOGON_NO_DIALOG          = &H00000001???
%LOGON_NO_CONNECT         = &H00000004???
%LOGON_NO_INBOUND         = &H00000008???
%LOGON_NO_OUTBOUND        = &H00000010???
'/*#define MAPI_UNICODE            ((ULONG) 0x80000000) in mapidefs.h */

'/* Flags that the transport may pass to the Spooler: */

%LOGON_SP_IDLE            = &H00010000???
%LOGON_SP_POLL            = &H00020000???
%LOGON_SP_RESOLVE         = &H00040000???


' ========================================================================================
' IXPProvider interface
' $IID_IXPProvider = GUID$("{00020312-0000-0000-C000-000000000046}")
' The IXPProvider interface is used to initialize a transport provider object and to shut
' down the object when it is no longer needed.
' ========================================================================================
INTERFACE IXPProvider $IID_IXPProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 12
     BYVAL lpulFlags AS DWORD _                         ' __out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransportLogon ( _                            ' VTable offset = 16
     BYVAL lpMAPISup AS DWORD _                         ' __in LPMAPISUP lpMAPISup
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYREF lpulFlags AS DWORD _                         ' __in_out ULONG * lpulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   , BYREF lppXPLogon AS IXPLogon _                     ' __out LPXPLOGON * lppXPLogon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* OptionData returned from call to RegisterOptions */

%OPTION_TYPE_RECIPIENT      = &H00000001???
%OPTION_TYPE_MESSAGE        = &H00000002???

' // Size = 36 bytes
TYPE OPTIONDATA DWORD
   ulFlags        AS DWORD            ' ULONG          /* MAPI_RECIPIENT, MAPI_MESSAGE */
   lpRecipGUID    AS GUID PTR         ' LPGUID         /* Same as returned by AddressTypes() */
   lpszAdrType    AS ASCIIZ PTR       ' LPTSTR         /* Same as returned by AddressTypes() */
   lpszDLLName    AS ASCIIZ PTR       ' LPTSTR         /* Options DLL */
   ulOrdinal      AS DWORD            ' ULONG          /* Ordinal in that DLL */
   cbOptionsData  AS DWORD            ' ULONG          /* Count of bytes in lpbOptionsData */
   lpbOptionsData AS BYTE PTR         ' LPBYTE         /* Providers per [recip|message] option data */
   cOptionsProps  AS DWORD            ' ULONG          /* Count of Options default prop values */
   lpOptionsProps AS SPropValue PTR   ' LPSPropValue   /* Default Options property values */
END TYPE

'typedef SCODE (STDMAPIINITCALLTYPE OPTIONCALLBACK)(
'   HINSTANCE         hInst,
'   LPMALLOC          lpMalloc,
'   ULONG             ulFlags,
'   ULONG             cbOptionData,
'   LPBYTE            lpbOptionData,
'   LPMAPISUP         lpMAPISup,
'   LPMAPIPROP        lpDataSource,
'   LPMAPIPROP *  lppWrappedSource,
'   LPMAPIERROR * lppMAPIError);

'/* For XP_AddressTypes */

'/*#define MAPI_UNICODE            ((ULONG) 0x80000000) in mapidefs.h */

'/* For XP_RegisterRecipOptions */

'/*#define MAPI_UNICODE            ((ULONG) 0x80000000) in mapidefs.h */

'/* For XP_RegisterMessageOptions */

'/*#define MAPI_UNICODE            ((ULONG) 0x80000000) in mapidefs.h */

'/* For TransportNotify */

%NOTIFY_ABORT_DEFERRED        = &H40000000???
%NOTIFY_CANCEL_MESSAGE        = &H80000000???
%NOTIFY_BEGIN_INBOUND         = &H00000001???
%NOTIFY_END_INBOUND           = &H00010000???
%NOTIFY_BEGIN_OUTBOUND        = &H00000002???
%NOTIFY_END_OUTBOUND          = &H00020000???
%NOTIFY_BEGIN_INBOUND_FLUSH   = &H00000004???
%NOTIFY_END_INBOUND_FLUSH     = &H00040000???
%NOTIFY_BEGIN_OUTBOUND_FLUSH  = &H00000008???
%NOTIFY_END_OUTBOUND_FLUSH    = &H00080000???

'/* For TransportLogoff */

%LOGOFF_NORMAL                = &H00000001???
%LOGOFF_HURRY                 = &H80000000???

'/* For SubmitMessage */

%BEGIN_DEFERRED               = &H00000001???

'/* For EndMessage */

'/* Flags that the Spooler may pass to the Transport: */

'/* Flags that the transport may pass to the Spooler: */

%END_RESEND_NOW               = &H00010000???
%END_RESEND_LATER             = &H00020000???
%END_DONT_RESEND              = &H00040000???

' ========================================================================================
' IXPLogon interface
' $IID_IXPLogon = GUID$("{00020315-0000-0000-C000-000000000046}")
' The IXPLogon interface is used to give the MAPI spooler access to a transport provider.
' ========================================================================================
INTERFACE IXPLogon $IID_IXPLogon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddressTypes ( _                              ' VTable offset = 12
     BYREF lpulFlags AS DWORD _                         ' __out ULONG * lpulFlags
   , BYREF lpcAdrType AS DWORD _                        ' __out ULONG * lpcAdrType
   , BYREF lpppAdrTypeArray AS DWORD _                  ' __out LPTSTR * * lpppAdrTypeArray
   , BYREF lpcMAPIUID AS DWORD _                        ' __out ULONG * lpcMAPIUID
   , BYREF lpppUIDArray AS DWORD _                      ' __out LPMAPIUID * * lpppUIDArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterOptions ( _                           ' VTable offset = 16
     BYREF lpulFlags AS DWORD _                         ' __out ULONG * lpulFlags
   , BYREF lpcOptions AS DWORD _                        ' __out ULONG * lpcOptions
   , BYREF lppOptions AS OPTIONDATA _                   ' __out LPOPTIONDATA * lppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransportNotify ( _                           ' VTable offset = 20
     BYREF lpulFlags AS DWORD _                         ' __out ULONG * lpulFlags
   , BYREF lppvData AS DWORD _                          ' __out LPVOID * lppvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Idle ( _                                      ' VTable offset = 24
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransportLogoff ( _                           ' VTable offset = 28
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SubmitMessage ( _                             ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYREF lpulMsgRef AS DWORD _                        ' __out ULONG * lpulMsgRef
   , BYREF lpulReturnParm AS DWORD _                    ' __out ULONG * lpulReturnParm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndMessage ( _                                ' VTable offset = 36
     BYVAL ulMsgRef AS DWORD _                          ' __in ulMsgRef
   , BYREF lpulFlags AS DWORD _                         ' __out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 40
     BYREF lpulIncoming AS DWORD _                      ' __out ULONG * lpulIncoming
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartMessage ( _                              ' VTable offset = 44
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYREF lpulMsgRef AS DWORD _                        ' __out ULONG * lpulMsgRef
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenStatusEntry ( _                           ' VTable offset = 48
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppEntry AS IMAPIStatus _                    ' __out LPMAPISTATUS * lppEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateState ( _                             ' VTable offset = 52
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlushQueues ( _                               ' VTable offset = 56
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL cbTargetTransport AS DWORD _                 ' __in ULONG cbTargetTransport
   , BYVAL lpTargetTransport AS ENTRYID PTR _           ' __in LPENTRYID lpTargetTransport
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* Transport Provider Entry Point */

' ========================================================================================
' XPProviderInit
' The XPProviderInit function initializes a transport provider for operation.
' ========================================================================================
DECLARE FUNCTION XPProviderInit IMPORT "MAPI32.DLL" ALIAS "XPProviderInit" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYVAL lpMalloc AS IMalloc _                          ' __in LPMALLOC lpMalloc
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in LPALLOCATEMORE lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYVAL ulMAPIVer AS DWORD _                           ' __in ULONG ulMAPIVer
 , BYREF lpulProviderVer AS DWORD _                     ' __out ULONG * lpulProviderVer
 , BYREF lppXPProvider AS IXPProvider _                 ' __out LPXPPROVIDER * lppXPProvider
 ) AS LONG                                              ' HRESULT
' ========================================================================================

'/********************************************************************/
'/*                                                                  */
'/*                     MESSAGE STORE SPI                            */
'/*                                                                  */
'/********************************************************************/

'/* Flags and enums */

'/* For Logon() */

'/*#define MAPI_UNICODE          ((ULONG) 0x80000000) in mapidefs.h */
'/*#define MDB_NO_DIALOG         ((ULONG) 0x00000001) in mapidefs.h */
'/*#define MDB_WRITE             ((ULONG) 0x00000004) in mapidefs.h */
'/*#define MAPI_DEFERRED_ERRORS  ((ULONG) 0x00000008) in mapidefs.h */
'/*#define MDB_TEMPORARY         ((ULONG) 0x00000020) in mapidefs.h */
'/*#define MDB_NO_MAIL           ((ULONG) 0x00000080) in mapidefs.h */

'/* For SpoolerLogon() */

'/*#define MAPI_UNICODE          ((ULONG) 0x80000000) in mapidefs.h */
'/*#define MDB_NO_DIALOG         ((ULONG) 0x00000001) in mapidefs.h */
'/*#define MDB_WRITE             ((ULONG) 0x00000004) in mapidefs.h */
'/*#define MAPI_DEFERRED_ERRORS  ((ULONG) 0x00000008) in mapidefs.h */

'/* GetCredentials, SetCredentials */

%LOGON_SP_TRANSPORT      = &H00000001???
%LOGON_SP_PROMPT         = &H00000002???
%LOGON_SP_NEWPW          = &H00000004???
%LOGON_CHANGED           = &H00000008???

'/* DoMCDialog */

%DIALOG_FOLDER           = &H00000001???
%DIALOG_MESSAGE          = &H00000002???
%DIALOG_PROP             = &H00000004???
%DIALOG_ATTACH           = &H00000008???

%DIALOG_MOVE             = &H00000010???
%DIALOG_COPY             = &H00000020???
%DIALOG_DELETE           = &H00000040???

%DIALOG_ALLOW_CANCEL     = &H00000080???
%DIALOG_CONFIRM_CANCEL   = &H00000100???

'/* ExpandRecips */

%NEEDS_PREPROCESSING     = &H00000001???
%NEEDS_SPOOLER           = &H00000002???

'/* PrepareSubmit */

%CHECK_SENDER            = &H00000001???
%NON_STANDARD            = &H00010000???


'/* Message Store Provider Interface (IMSPROVIDER) */

' ========================================================================================
' IMSProvider interface
' $IID_IMSProvider = GUID$("{00020310-0000-0000-C000-000000000046}")
' The IMSProvider interface provides access to a message store provider through a message
' store provider object. This message store provider object is returned at provider logon
' by the message store provider's MSProviderInit entry point function. The message store
' provider object is primarily used by client applications and the MAPI spooler to open
' message stores.
' ========================================================================================
INTERFACE IMSProvider $IID_IMSProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 12
     BYREF lpulFlags AS DWORD _                         ' __out ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 16
     BYVAL lpMAPISup AS IMAPISupport _                  ' __in LPMAPISUP lpMAPISup
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYREF lpcbSpoolSecurity AS DWORD _                 ' __out ULONG * lpcbSpoolSecurity
   , BYREF lppbSpoolSecurity AS DWORD _                 ' __out LPBYTE * lppbSpoolSecurity
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   , BYREF lppMSLogon AS IMSLogon _                     ' __out LPMSLOGON * lppMSLogon
   , BYREF lppMDB AS IMsgStore _                        ' __out LPMDB * lppMDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpoolerLogon ( _                              ' VTable offset = 20
     BYVAL lpMAPISup AS IMAPISupport _                  ' __in LPMAPISUP lpMAPISup
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntrhyID AS ENTRYID PTR _                  ' __in LPENTRYID lpEntrhyID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL cbSpoolSecurity AS DWORD _                   ' __in ULONG cbSpoolSecurity
   , BYVAL lpbSpoolSecurity AS BYTE PTR _               ' __in LPBYTE lpbSpoolSecurity
   , BYREF lppMAPIError AS DWORD _                      ' __in LPMAPIERROR * lppMAPIError
   , BYREF lppMSLogon AS IMSLogon _                     ' __in LPMSLOGON * lppMSLogon
   , BYREF lppMDB AS IMsgStore _                        ' __in LPMDB * lppMDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareStoreIDs ( _                           ' VTable offset = 24
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* The MSLOGON object is returned by the Logon() method of the
' * MSPROVIDER interface.  This object is for use by MAPIX.DLL.
' */

' ========================================================================================
' IMSLogon interface
' $IID_IMSLogon = GUID$("{00020313-0000-0000-C000-000000000046}")
' The IMSLogon interface is used to access resources in a message store logon object.
' ========================================================================================
INTERFACE IMSLogon $IID_IMSLogon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logoff ( _                                    ' VTable offset = 16
     BYREF lpulFlags AS DWORD _                         ' __in ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offset = 20
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareEntryIDs ( _                           ' VTable offset = 24
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenStatusEntry ( _                           ' VTable offset = 36
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppEntry AS IUnknown _                       ' __out LPVOID * lppEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* Message Store Provider Entry Point */

DECLARE FUNCTION MSProviderInit IMPORT "MAPI32.DLL" ALIAS "MSProviderInit" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYVAL lpMalloc AS IMalloc _                          ' __in LPMALLOC lpMalloc
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in LPALLOCATEMORE lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYVAL ulMAPIVer AS DWORD _                           ' __in ULONG ulMAPIVer
 , BYREF lpulProviderVer AS DWORD _                     ' __out ULONG * lpulProviderVer
 , BYREF lppMSProvider AS IMSProvider _                 ' __out LPMSPROVIDER * lppMSProvider
 ) AS LONG                                              ' HRESULT


'/********************************************************************/
'/*                                                                  */
'/*                 MESSAGE SERVICE CONFIGURATION                    */
'/*                                                                  */
'/********************************************************************/

'/* Flags for service configuration entry point */

'/* #define MAPI_UNICODE              0x80000000   */
'/* #define SERVICE_UI_ALWAYS         0x00000002   */
'/* #define SERVICE_UI_ALLOWED        0x00000010   */
%MSG_SERVICE_UI_READ_ONLY    = &H00000008  ' /* display parameters only */
%SERVICE_LOGON_FAILED        = &H00000020  ' /* reconfigure provider */

'/* Contexts for service configuration entry point */

%MSG_SERVICE_INSTALL         = &H00000001
%MSG_SERVICE_CREATE          = &H00000002
%MSG_SERVICE_CONFIGURE       = &H00000003
%MSG_SERVICE_DELETE          = &H00000004
%MSG_SERVICE_UNINSTALL       = &H00000005
%MSG_SERVICE_PROVIDER_CREATE = &H00000006
%MSG_SERVICE_PROVIDER_DELETE = &H00000007

'/* Prototype for service configuration entry point */

'typedef HRESULT (STDAPICALLTYPE MSGSERVICEENTRY)(
'   HINSTANCE       hInstance,
'   LPMALLOC        lpMalloc,
'   LPMAPISUP       lpMAPISup,
'   ULONG           ulUIParam,
'   ULONG           ulFlags,
'   ULONG           ulContext,
'   ULONG           cValues,
'   LPSPropValue    lpProps,
'   LPPROVIDERADMIN lpProviderAdmin,
'   LPMAPIERROR *lppMapiError
');
