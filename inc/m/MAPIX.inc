' ########################################################################################
' Microsoft Windows
' File: MAPIX.inc
' Contents: Definitions of objects/flags, etc used by Extended MAPI
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIX_INC = 1

'/* Include common MAPI header files if they haven't been already. */
#INCLUDE ONCE "mapiguid.inc"
#INCLUDE ONCE "mapidefs.inc"
#INCLUDE ONCE "mapicode.inc"
#INCLUDE ONCE "mapitags.inc"

'/* ------------------------------------------------------ */
'/* shared with simple mapi */

'typedef ULONG       FLAGS;

'/* MAPILogon() flags.       */

%MAPI_LOGON_UI          = &H00000001???  ' /* Display logon UI               */
%MAPI_NEW_SESSION       = &H00000002???  ' /* Don't use shared session       */
%MAPI_ALLOW_OTHERS      = &H00000008???  ' /* Make this a shared session     */
%MAPI_EXPLICIT_PROFILE  = &H00000010???  ' /* Don't use default profile      */
%MAPI_EXTENDED          = &H00000020???  ' /* Extended MAPI Logon            */
%MAPI_FORCE_DOWNLOAD    = &H00001000???  ' /* Get new mail before return     */
%MAPI_SERVICE_UI_ALWAYS = &H00002000???  ' /* Do logon UI in all providers   */
%MAPI_NO_MAIL           = &H00008000???  ' /* Do not activate transports     */
'/* %MAPI_NT_SERVICE      = &H00010000???   Allow logon from an NT service   */
#IF NOT %DEF(%MAPI_PASSWORD_UI)
%MAPI_PASSWORD_UI       = &H00020000???  ' /* Display password UI only       */
#ENDIF
%MAPI_TIMEOUT_SHORT     = &H00100000???  ' /* Minimal wait for logon resources   */

%MAPI_SIMPLE_DEFAULT  = %MAPI_LOGON_UI OR %MAPI_FORCE_DOWNLOAD OR %MAPI_ALLOW_OTHERS
%MAPI_SIMPLE_EXPLICIT = %MAPI_NEW_SESSION OR %MAPI_FORCE_DOWNLOAD OR %MAPI_EXPLICIT_PROFILE

'/* Structure passed to MAPIInitialize(), and its ulFlags values */

' // Size = 8 bytes
TYPE MAPIINIT_0 DWORD
   ulVersion AS DWORD   ' ULONG
   ulFlags   AS DWORD   ' ULONG
END TYPE

'typedef MAPIINIT_0 MAPIINIT;
' // Size = 8 bytes
TYPE MAPIINIT DWORD
   ulVersion AS DWORD   ' ULONG
   ulFlags   AS DWORD   ' ULONG
END TYPE

%MAPI_INIT_VERSION = 0

%MAPI_MULTITHREAD_NOTIFICATIONS = &H00000001???
'/* Reserved for MAPI              0x40000000 */
'/* #define MAPI_NT_SERVICE        0x00010000   Use from NT service */

'/* MAPI base functions */

DECLARE FUNCTION MAPIInitialize IMPORT "MAPI32.DLL" ALIAS "MAPIInitialize" ( _
   BYREF lpMapiInit AS ANY _                            ' __in LPVOID lpMapiInit
 ) AS LONG                                              ' HRESULT

DECLARE SUB MAPIUninitialize IMPORT "MAPI32.DLL" ALIAS "MAPIUninitialize" ()

'/*  Extended MAPI Logon function */

DECLARE FUNCTION MAPILogonEx IMPORT "MAPI32.DLL" ALIAS "MAPILogonEx" ( _
   BYVAL ulUIParam AS DWORD _                           ' __in ULONG ulUIParam
 , BYREF lpszProfileName AS ASCIIZ _                    ' __in_opt LPTSTR lpszProfileName
 , BYREF lpszPassword AS ASCIIZ _                       ' __in_opt LPTSTR lpszPassword
 , BYVAL flFlags AS DWORD _                             ' __in FLAGS flFlags
 , BYREF lppSession AS IMAPISession _                   ' __out LPMAPISESSION * lppSession
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MAPIAllocateBuffer IMPORT "MAPI32.DLL" ALIAS "MAPIAllocateBuffer" ( _
   BYVAL cbSize AS DWORD _                              ' __in ULONG cbSize
 , BYREF lppBuffer AS ANY _                             ' __out LPVOID * lppBuffer
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION MAPIAllocateMore IMPORT "MAPI32.DLL" ALIAS "MAPIAllocateMore" ( _
   BYVAL cbSize AS DWORD _                              ' __in ULONG cbSize
 , BYVAL lpObject AS DWORD _                            ' __in LPVOID lpObject
 , BYREF lppBuffer AS ANY _                             ' __out LPVOID * lppBuffer
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION MAPIFreeBuffer IMPORT "MAPI32.DLL" ALIAS "MAPIFreeBuffer" ( _
   BYVAL lpBuffer AS DWORD _                            ' __in LPVOID lpBuffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION MAPIAdminProfiles IMPORT "MAPI32.DLL" ALIAS "MAPIAdminProfiles" ( _
   BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF lppProfAdmin AS IProfAdmin _                   ' __out LPPROFADMIN * lppProfAdmin
 ) AS LONG                                              ' HRESULT

'/* IMAPISession Interface -------------------------------------------------- */

'/* Flags for OpenEntry and others */

'/*#define MAPI_MODIFY            ((ULONG) 0x00000001) */

'/* Flags for Logoff */

%MAPI_LOGOFF_SHARED          = &H00000001??? ' /* Close all shared sessions    */
%MAPI_LOGOFF_UI              = &H00000002??? ' /* It's OK to present UI        */

'/* Flags for SetDefaultStore. They are mutually exclusive. */

%MAPI_DEFAULT_STORE          = &H00000001???  ' /* for incoming messages */
%MAPI_SIMPLE_STORE_TEMPORARY = &H00000002???  ' /* for simple MAPI and CMC */
%MAPI_SIMPLE_STORE_PERMANENT = &H00000003???  ' /* for simple MAPI and CMC */
%MAPI_PRIMARY_STORE          = &H00000004???  ' /* Used by some clients */
%MAPI_SECONDARY_STORE        = &H00000005???  ' /* Used by some clients */

'/* Flags for ShowForm. */

%MAPI_POST_MESSAGE           = &H00000001???  ' /* Selects post/send semantics */
%MAPI_NEW_MESSAGE            = &H00000002???  ' /* Governs copying during submission */

'/*  MessageOptions */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

'/*  QueryDefaultMessageOpt */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

' ========================================================================================
' IMAPISession interface
' $IID_IMAPISession = GUID$("{00020300-0000-0000-C000-000000000046}")
' The IMAPISession interface is used to manage objects associated with a MAPI logon session.
' ========================================================================================
INTERFACE IMAPISession $IID_IMAPISession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMsgStoresTable ( _                         ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenMsgStore ( _                              ' VTable offset = 20
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMDB AS IMsgStore _                        ' __out LPMDB * lppMDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenAddressBook ( _                           ' VTable offset = 24
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppAdrBook AS IAddrBook _                    ' __out LPADRBOOK * lppAdrBook
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProfileSection ( _                        ' VTable offset = 28
     BYREF lpUID AS MAPIUID _                           ' __in LPMAPIUID lpUID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONGG ulFlags
   , BYREF lppProfSect AS IProfSect _                   ' __out LPPROFSECT * lppProfSect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatusTable ( _                            ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offset = 36
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareEntryIDs ( _                           ' VTable offset = 40
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 44
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 48
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MessageOptions ( _                            ' VTable offset = 52
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszAdrType AS ASCIIZ _                      ' __in LPTSTR lpszAdrType
   , BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDefaultMessageOpt ( _                    ' VTable offset = 56
     BYREF lpszAdrType AS ASCIIZ _                      ' __in LPTSTR lpszAdrType
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppOptions AS DWORD _                        ' __out LPSPropValue * lppOptions [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAdrTypes ( _                              ' VTable offset = 60
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcAdrTypes AS DWORD _                       ' __out ULONG * lpcAdrTypes
   , BYREF lpppszAdrTypes AS DWORD _                    ' __out LPTSTR * * lpppszAdrTypes [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIdentity ( _                             ' VTable offset = 64
     BYREF lpcbEntryID AS DWORD _                       ' __in ULONG * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __out LPENTRYID * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logoff ( _                                    ' VTable offset = 68
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulReserved AS DWORD _                        ' __in ULONG ulReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultStore ( _                           ' VTable offset = 72
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdminServices ( _                             ' VTable offset = 76
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppServiceAdmin AS IMsgServiceAdmin _        ' __out LPSERVICEADMIN * lppServiceAdmin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowForm ( _                                  ' VTable offset = 80
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL lpMsgStore AS IMsgStore _                    ' __in LPMDB lpMsgStore
   , BYVAL lpParentFolder AS IMAPIFolder _              ' __in LPMAPIFOLDER lpParentFolder
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulMessageToken AS DWORD _                    ' __in ULONG ulMessageToken
   , BYVAL lpMessageSent AS IMessage _                  ' __in LPMESSAGE lpMessageSent
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulMessageStatus AS DWORD _                   ' __in ULONG ulMessageStatus
   , BYVAL ulMessageFlags AS DWORD _                    ' __in ULONG ulMessageFlags
   , BYVAL ulAccess AS DWORD _                          ' __in ULONG ulAccess
   , BYVAL lpszMessageClass AS DWORD _                  ' __in LPSTR lpszMessageClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareForm ( _                               ' VTable offset = 84
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYREF lpulMessageToken AS DWORD _                  ' __out ULONG * lpulMessageToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
' ========================================================================================


'/* IAddrBook Interface ----------------------------------------------------- */

'/*  CreateOneOff */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */
'/****** MAPI_SEND_NO_RICH_INFO      ((ULONG) 0x00010000) */

'/*  RecipOptions */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

'/*  QueryDefaultRecipOpt */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

'/*  GetSearchPath */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */


' ========================================================================================
' IAddrBook interface (inherits from IMAPIProp)
' $IID_IAddrBook = GUID$("{00020309-0000-0000-C000-000000000046}")
' The IAddrBook interface supports access to the MAPI address book and includes operations
' such as displaying common dialog boxes, opening containers, messaging users, and
' distribution lists, and performing name resolution.
' ========================================================================================
INTERFACE IAddrBook $IID_IAddrBook

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAddrBook Methods
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offser = 56
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareEntryIDs ( _                           ' VTable offser = 60
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offser = 64
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offser = 68
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateOneOff ( _                              ' VTable offser = 72
     BYREF lpszName AS ASCIIZ _                         ' __in LPTSTR lpszName
   , BYREF lpszAdrType AS ASCIIZ _                      ' __in LPTSTR lpszAdrType
   , BYREF lpszAddress AS ASCIIZ _                      ' __in LPTSTR lpszAddress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcbEntryID AS DWORD _                       ' __out ULONG * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __out LPENTRYID * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewEntry ( _                                  ' VTable offser = 76
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
   METHOD ResolveName ( _                               ' VTable offser = 80
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpszNewEntryTitle AS DWORD _                 ' __in LPTSTR lpszNewEntryTitle
   , BYVAL lpAdrList AS ADRLIST PTR _                   ' __in_out LPADRLIST lpAdrList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Address ( _                                   ' VTable offser = 84
     BYREF lpulUIParam AS DWORD _                       ' __in_out ULONG_PTR * lpulUIParam
   , BYREF lpAdrParms AS ADRPARM _                      ' __in_out LPADRPARM lpAdrParms
   , BYVAL lppAdrList AS ADRLIST PTR _                  ' __in_out LPADRLIST * lppAdrList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Details ( _                                   ' VTable offser = 88
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
   METHOD RecipOptions ( _                              ' VTable offser = 92
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpRecip AS ADRENTRY PTR _                    ' __in LPADRENTRY lpRecip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDefaultRecipOpt ( _                      ' VTable offser = 96
     BYREF lpszAdrType AS ASCIIZ _                      ' __in LPTSTR lpszAdrType
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppOptions AS DWORD _                        ' __out LPSPropValue * lppOptions [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPAB ( _                                    ' VTable offser = 100
     BYREF lpcbEntryID AS DWORD _                       ' __out ULONG * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __out LPENTRYID * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPAB ( _                                    ' VTable offser = 104
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultDir ( _                             ' VTable offser = 108
     BYREF lpcbEntryID AS DWORD _                       ' __out ULONG * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __out LPENTRYID * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultDir ( _                             ' VTable offser = 112
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchPath ( _                             ' VTable offser = 116
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppSearchPath AS DWORD _                     ' __out LPSRowSet * lppSearchPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSearchPath ( _                             ' VTable offser = 120
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpSearchPath AS SRowSet PTR _                ' __in LPSRowSet lpSearchPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareRecips ( _                             ' VTable offser = 124
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lpRecipList AS ADRLIST PTR _                 ' __in LPADRLIST lpRecipList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'/* IProfAdmin Interface ---------------------------------------------------- */

'/* Flags for CreateProfile */
%MAPI_DEFAULT_SERVICES       = &H00000001???

'/* GetProfileTable */
'/****** MAPI_UNICODE         ((ULONG) = &H80000000) */

' ========================================================================================
' IProfAdmin interface
' $IID_IProfAdmin = GUID$("{00020325-0000-0000-C000-000000000046}")
' The IProfAdmin interface supports the administration of profiles.
' ========================================================================================
INTERFACE IProfAdmin $IID_IProfAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProfileTable ( _                           ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateProfile ( _                             ' VTable offset = 20
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYREF lpszPassword AS ASCIIZ _                     ' __in LPTSTR lpszPassword
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProfile ( _                             ' VTable offset = 24
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeProfilePassword ( _                     ' VTable offset = 28
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYREF lpszOldPassword AS ASCIIZ _                  ' __in LPTSTR lpszOldPassword
   , BYREF lpszNewPassword AS ASCIIZ _                  ' __in LPTSTR lpszNewPassword
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProfile ( _                               ' VTable offset = 32
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYREF lpszOldPassword AS ASCIIZ _                  ' __in LPTSTR lpszOldPassword
   , BYREF lpszNewPassword AS ASCIIZ _                  ' __in LPTSTR lpszNewPassword
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameProfile ( _                             ' VTable offset = 36
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYREF lpszOldPassword AS ASCIIZ _                  ' __in LPTSTR lpszOldPassword
   , BYREF lpszNewProfileName AS ASCIIZ _               ' __in LPTSTR lpszNewProfileName
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultProfile ( _                         ' VTable offset = 40
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdminServices ( _                             ' VTable offset = 44
     BYREF lpszProfileName AS ASCIIZ _                  ' __in LPTSTR lpszProfileName
   , BYREF lpszPassword AS ASCIIZ _                     ' __in LPTSTR lpszPassword
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppServiceAdmin AS IMsgServiceAdmin _        ' __out LPSERVICEADMIN * lppServiceAdmin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMsgServiceAdmin Interface ---------------------------------------------- */

'/* Values for PR_RESOURCE_FLAGS in message service table */

%SERVICE_DEFAULT_STORE       = &H00000001???
%SERVICE_SINGLE_COPY         = &H00000002???
%SERVICE_CREATE_WITH_STORE   = &H00000004???
%SERVICE_PRIMARY_IDENTITY    = &H00000008???
%SERVICE_NO_PRIMARY_IDENTITY = &H00000020???

'/*  GetMsgServiceTable */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

'/*  GetProviderTable */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) */

' ========================================================================================
' IMsgServiceAdmin interface
' $IID_IMsgServiceAdmin = GUID$("{0002031D-0000-0000-C000-000000000046}")
' The IMsgServiceAdmin interface is used to make changes to a message service within a
' profile.
' ========================================================================================
INTERFACE IMsgServiceAdmin $IID_IMsgServiceAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMsgServiceTable ( _                        ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMsgService ( _                          ' VTable offser = 20
     BYREF lpszService AS ASCIIZ _                      ' __in LPTSTR lpszService
   , BYREF lpszDisplayName AS ASCIIZ _                  ' __in LPTSTR lpszDisplayName
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMsgService ( _                          ' VTable offser = 24
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyMsgService ( _                            ' VTable offser = 28
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYREF lpszDisplayName AS ASCIIZ _                  ' __in LPTSTR lpszDisplayName
   , BYREF lpInterfaceToCopy AS GUID _                  ' __in LPCIID lpInterfaceToCopy
   , BYVAL lpObjectDst AS DWORD _                       ' __in LPVOID lpObjectDst
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameMsgService ( _                          ' VTable offser = 32
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszDisplayName AS ASCIIZ _                  ' __in LPTSTR lpszDisplayName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureMsgService ( _                       ' VTable offser = 36
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG_PTR ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYREF lpProps AS SPropValue _                      ' __in LPSPropValue lpProps [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProfileSection ( _                        ' VTable offser = 40
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYREF lpInterface AS DWORD _                       ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppProfSect AS IProfSect _                   ' __out LPPROFSECT * lppProfSect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MsgServiceTransportOrder ( _                  ' VTable offser = 44
     BYVAL cUID AS DWORD _                              ' __in ULONG cUID
   , BYREF lpUIDList AS GUID _                          ' __in LPMAPIUID lpUIDList
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdminProviders ( _                            ' VTable offser = 48
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppProviderAdmin AS IProviderAdmin _         ' __out LPPROVIDERADMIN * lppProviderAdmin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrimaryIdentity ( _                        ' VTable offser = 52
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProviderTable ( _                          ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' The following functions are not included in any C header:

' ========================================================================================
' The ABProviderInit function initializes an address book provider for operation.
' Note: This is a prorotype for a function that you have to implement if you write an
' address book provider.
' ========================================================================================
'DECLARE FUNCTION ABProviderInit ( _
'   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
' , BYVAL lpMalloc AS IMalloc _                          ' __in LPMALLOC lpMalloc
' , BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
' , BYVAL lpAllocateMore AS DWORD _                      ' __in LPALLOCATEMORE lpAllocateMore
' , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
' , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
' , BYVAL ulMAPIVer AS DWORD _                           ' __in ULONG ulMAPIVer
' , BYREF lpulProviderVer AS DWORD _                     ' __out ULONG * lpulProviderVer
' , BYREF lppABProvider AS IABProvider _                 ' __out LPABPROVIDER * lppABProvider
' ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' FGetComponentPath
' The FGetComponentPath function redirects the MAPI call to the private Mapi32.dll.
' FGetComponentPath@20 can also be used as the alias name.
' ========================================================================================
DECLARE FUNCTION FGetComponentPath IMPORT "MAPI32.DLL" ALIAS "FGetComponentPath" ( _
   BYREF szComponent AS ASCIIZ _                        ' __in LPCSTR szComponent
 , BYREF szQualifier AS ASCIIZ _                        ' __in LPSTR szQualifier
 , BYREF szDllPath AS ASCIIZ _                          ' __in LPSTR szDllPath
 , BYVAL cchBufferSize AS DWORD _                       ' __in DWORD cchBufferSize
 , BYVAL fInstall AS LONG _                             ' __in BOOL fInstall
 ) AS LONG                                              ' BOOL
' ========================================================================================
