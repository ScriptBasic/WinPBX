' ########################################################################################
' Microsoft Windows
' File: MAPI.inc
' Contents: Messaging Applications Programming Interface
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'/*
' *  Types.
' */
'typedef unsigned long FAR * LPULONG;
'typedef unsigned long       FLAGS;
'typedef ULONG_PTR       LHANDLE, FAR * LPLHANDLE;
'typedef unsigned char FAR * LPBYTE;

%lhSessionNull = 0??

' // Size = 24 bytes
TYPE MapiFileDesc DWORD
   ulReserved   AS DWORD        ' ULONG  // Reserved for future use (must be 0)
   flFlags      AS DWORD        ' ULONG  // Flags
   nPosition    AS DWORD        ' ULONG  // character in text to be replaced by attachment
   lpszPathName AS ASCIIZ PTR   ' LPSTR  // Full path name of attachment file
   lpszFileName AS ASCIIZ PTR   ' LPSTR  // Original file name (optional)
   lpFileType   AS DWORD        ' LPVOID // Attachment file type (can be lpMapiFileTagExt)
END TYPE

%MAPI_OLE                = &H00000001???
%MAPI_OLE_STATIC         = &H00000002???

' // Size = 20 bytes
TYPE MapiFileTagExt DWORD
   ulReserved AS DWORD       ' ULONG  // Reserved, must be zero.
   cbTag      AS DWORD       ' ULONG  // Size (in bytes) of
   lpTag      AS BYTE PTR    ' LPBYTE // X.400 OID for this attachment type
   cbEncoding AS DWORD       ' ULONG  // Size (in bytes) of
   lpEncoding AS BYTE PTR    ' LPBYTE // X.400 OID for this attachment's encoding
END TYPE

' // Size = 24 bytes
TYPE MapiRecipDesc DWORD
   ulReserved   AS DWORD        ' ULONG  // Reserved for future use
   ulRecipClass AS DWORD        ' ULONG  // Recipient class
                                '        // MAPI_TO, MAPI_CC, MAPI_BCC, MAPI_ORIG
   lpszName     AS ASCIIZ PTR   ' LPSTR  // Recipient name
   lpszAddress  AS ASCIIZ PTR   ' LPSTR  // Recipient address (optional)
   ulEIDSize    AS DWORD        ' ULONG  // Count in bytes of size of pEntryID
   lpEntryID    AS DWORD        ' LPVOID // System-specific recipient reference
END TYPE

#IF NOT %DEF(%MAPI_ORIG)          '  /* also defined in mapix.h */
%MAPI_ORIG      = 0               '  /* Recipient is message originator          */
%MAPI_TO        = 1               '  /* Recipient is a primary recipient         */
%MAPI_CC        = 2               '  /* Recipient is a copy recipient            */
%MAPI_BCC       = 3               '  /* Recipient is blind copy recipient        */
#ENDIF

' // Size = 48 bytes
TYPE MapiMessage DWORD
   ulReserved         AS DWORD               ' UKONG // Reserved for future use (M.B. 0)
   lpszSubject        AS ASCIIZ PTR          ' LPSTR // Message Subject
   lpszNoteText       AS ASCIIZ PTR          ' LPSTR // Message Text
   lpszMessageType    AS ASCIIZ PTR          ' LPSTR // Message Class
   lpszDateReceived   AS ASCIIZ PTR          ' LPSTR // in YYYY/MM/DD HH:MM format
   lpszConversationID AS ASCIIZ PTR          ' LPSTR // conversation thread ID
   flFlags            AS DWORD               ' FLAGS // unread,return receipt
   lpOriginator       AS MapiRecipDesc PTR   ' lpMapiRecipDesc // Originator descriptor
   nRecipCount        AS DWORD               ' ULONG // Number of recipients
   lpRecips           AS MapiRecipDesc PTR   ' lpMapiRecipDesc // Recipient descriptors
   nFileCount         AS DWORD               ' ULONG // # of file attachments
   lpFiles            AS MapiFileDesc PTR    ' lpMapiFileDesc // Attachment descriptors
END TYPE

%MAPI_UNREAD             = &H00000001???
%MAPI_RECEIPT_REQUESTED  = &H00000002???
%MAPI_SENT               = &H00000004???


'/*
' *  Entry points.
' */

'/*
' *  flFlags values for Simple MAPI entry points. All documented flags are
' *  shown for each call. Duplicates are commented out but remain present
' *  for every call.
' */

'/* MAPILogon() flags.       */

#IF NOT %DEF(%MAPIX_INC)
%MAPI_LOGON_UI          = &H00000001???  ' /* Display logon UI               */
#IF NOT %DEF(%MAPI_PASSWORD_UI)
%MAPI_PASSWORD_UI       = &H00020000???  ' /* Display password UI only       */
#ENDIF
%MAPI_NEW_SESSION       = &H00000002???  ' /* Don't use shared session       */
%MAPI_FORCE_DOWNLOAD    = &H00001000???  ' /* Get new mail before return     */
%MAPI_EXTENDED          = &H00000020???  ' /* Extended MAPI Logon            */
#ENDIF

'/* MAPISendMail() flags.    */

'/* #define MAPI_LOGON_UI        0x00000001     Display logon UI             */
'/* #define MAPI_NEW_SESSION     0x00000002     Don't use shared session     */

#IF NOT %DEF(%MAPI_DIALOG)              ' /* also defined in MapiDefS.h */
%MAPI_DIALOG             = &H00000008???   ' /* Display a send note UI       */
#ENDIF
'/*# define MAPI_USE_DEFAULT      0x00000040      Use default profile in logon */

'/* MAPIFindNext() flags.    */

%MAPI_UNREAD_ONLY        = &H00000020???  ' /* Only unread messages         */
%MAPI_GUARANTEE_FIFO     = &H00000100???  ' /* use date order               */
%MAPI_LONG_MSGID         = &H00004000???   ' /* allow 512 char returned ID   */

'/* MAPIReadMail() flags.    */

%MAPI_PEEK               = &H00000080???  ' /* Do not mark as read.         */
%MAPI_SUPPRESS_ATTACH    = &H00000800???  ' /* header + body, no files      */
%MAPI_ENVELOPE_ONLY      = &H00000040???  ' /* Only header information      */
%MAPI_BODY_AS_FILE       = &H00000200???

'/* MAPISaveMail() flags.    */

'/* #define MAPI_LOGON_UI        0x00000001     Display logon UI             */
'/* #define MAPI_NEW_SESSION     0x00000002     Don't use shared session     */
'/* #define MAPI_LONG_MSGID      0x00004000   /* allow 512 char returned ID   */

'/* MAPIAddress() flags.     */

'/* #define MAPI_LOGON_UI        0x00000001     Display logon UI             */
'/* #define MAPI_NEW_SESSION     0x00000002     Don't use shared session     */

'/* MAPIDetails() flags.     */

'/* #define MAPI_LOGON_UI        0x00000001     Display logon UI             */
'/* #define MAPI_NEW_SESSION     0x00000002     Don't use shared session     */
%MAPI_AB_NOMODIFY        = &H00000400???   '  /* Don't allow mods of AB entries */

'/* MAPIResolveName() flags. */

'/* #define MAPI_LOGON_UI        0x00000001     Display logon UI             */
'/* #define MAPI_NEW_SESSION     0x00000002     Don't use shared session     */
'/* #define MAPI_DIALOG          0x00000008     Prompt for choices if ambiguous */
'/* #define MAPI_AB_NOMODIFY     0x00000400     Don't allow mods of AB entries */

' ========================================================================================
' The MAPILogon function begins a Simple MAPI session, loading the default message
' store and address book providers.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPILogon IMPORT "MAPI32.DLL" ALIAS "MAPILogon" ( _
   BYVAL ulUIParam AS DWORD _                           ' __in  ULONG_PTR ulUIParam
 , BYREF lpszProfileName AS ASCIIZ _                    ' __in  LPSTR lpszProfileName
 , BYREF lpszPassword AS ASCIIZ _                       ' __in  LPSTR lpszPassword
 , BYVAL flFlags AS DWORD _                             ' __in  FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in  ULONG ulReserved
 , BYREF lplhSession AS DWORD _                         ' __out LPLHANDLE lplhSession
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPILogoff function ends a session with the messaging system.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPILogoff IMPORT "MAPI32.DLL" ALIAS "MAPILogoff" ( _
   BYVAL lhSession AS DWORD _                           ' __in LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in ULONG_PTR ulUIParam
 , BYVAL flFlags AS DWORD _                             ' __in FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in ULONG ulReserved
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPISendMail function sends a message. This function differs from the
' MAPISendDocuments function in that it allows greater flexibility in message generation.
' ========================================================================================
DECLARE FUNCTION MAPISendMail IMPORT "MAPI32.DLL" ALIAS "MAPISendMail" ( _
   BYVAL lhSession AS DWORD _                           ' __in LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in ULONG_PTR ulUIParam
 , BYREF lpMessage AS MapiMessage _                     ' __in lpMapiMessage lpMessage
 , BYVAL flFlags AS DWORD _                             ' __in FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in ULONG ulReserved
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPISendDocuments function sends a standard message with one or more attached files
' and a cover note. The cover note is a dialog box that allows the user to enter a list of
' recipients and an optional message. MAPISendDocuments differs from the MAPISendMail
' function in that it allows less flexibility in message generation.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPISendDocuments IMPORT "MAPI32.DLL" ALIAS "MAPISendDocuments" ( _
   BYVAL ulUIParam AS DWORD _                           ' __in ULONG_PTR ulUIParam
 , BYREF lpszDelimChar AS ASCIIZ _                      ' __in LPSTR lpszDelimChar
 , BYREF lpszFilePaths AS ASCIIZ _                      ' __in LPSTR lpszFilePaths
 , BYREF lpszFileNames AS ASCIIZ _                      ' __in LPSTR lpszFileNames
 , BYVAL ulReserved AS DWORD _                          ' __in ULONG ulReserved
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIFindNext function retrieves the next (or first) message identifier of a
' specified type of incoming message.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIFindNext IMPORT "MAPI32.DLL" ALIAS "MAPIFindNext" ( _
   BYVAL lhSession AS DWORD _                           ' __in  LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in  ULONG_PTR ulUIParam
 , BYREF lpszMessageType AS ASCIIZ _                    ' __in  LPSTR lpszMessageType
 , BYREF lpszSeedMessageID AS ASCIIZ _                  ' __in  LPSTR lpszSeedMessageID
 , BYVAL flFlags AS DWORD _                             ' __in  FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in  ULONG ulReserved
 , BYREF lpszMessageID AS ASCIIZ _                      ' __out LPSTR lpszMessageID
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIReadMail function retrieves a message for reading.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIReadMail IMPORT "MAPI32.DLL" ALIAS "MAPIReadMail" ( _
   BYVAL lhSession AS DWORD _                           ' __in  LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in  ULONG_PTR ulUIParam
 , BYREF lpszMessageID AS ASCIIZ _                      ' __in  LPSTR lpszMessageID
 , BYVAL flFlags AS DWORD _                             ' __in  FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in  ULONG ulReserved
 , BYREF lppMessage AS DWORD _                          ' __out lpMapiMessage FAR *lppMessage
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPISaveMail function saves a message into the message store.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPISaveMail IMPORT "MAPI32.DLL" ALIAS "MAPISaveMail" ( _
   BYVAL lhSession AS DWORD _                           ' __in LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in ULONG_PTR ulUIParam
 , BYREF lpMessage AS MapiMessage _                     ' __in lpMapiMessage lpMessage
 , BYVAL flFlags AS DWORD _                             ' __in FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in ULONG ulReserved
 , BYREF lpszMessageID AS ASCIIZ _                      ' __in_out LPSTR lpszMessageID
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIDeleteMail function deletes a message.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIDeleteMail IMPORT "MAPI32.DLL" ALIAS "MAPIDeleteMail" ( _
   BYVAL lhSession AS DWORD _                           ' __in LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in ULONG_PTR ulUIParam
 , BYREF lpszMessageID AS ASCIIZ _                      ' __in LPSTR lpszMessageID
 , BYVAL flFlags AS DWORD _                             ' __in FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in ULONG ulReserved
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIFreeBuffer function frees memory allocated by the messaging system.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIFreeBuffer IMPORT "MAPI32.DLL" ALIAS "MAPIFreeBuffer" ( _
   BYVAL pv AS DWORD _                                  ' __in LPVOID pv
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIAddress function creates or modifies a set of address list entries.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIAddress IMPORT "MAPI32.DLL" ALIAS "MAPIAddress" ( _
   BYVAL lhSession AS DWORD _                           ' __in  LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in  ULONG_PTR ulUIParam
 , BYREF lpszCaption AS ASCIIZ _                        ' __in  LPSTR lpszCaption
 , BYVAL nEditFields AS DWORD _                         ' __in  ULONG nEditFields
 , BYREF lpszLabels AS ASCIIZ _                         ' __in  LPSTR lpszLabels
 , BYVAL nRecips AS DWORD _                             ' __in  ULONG nRecips
 , BYVAL lpRecips AS DWORD _                            ' __in  lpMapiRecipDesc lpRecips
 , BYVAL flFlags AS DWORD _                             ' __in  FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in  ULONG ulReserved
 , BYREF lpnNewRecips AS DWORD _                        ' __out LPULONG lpnNewRecips
 , BYREF lppNewRecips AS DWORD _                        ' __out lpMapiRecipDesc FAR *lppNewRecips
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIDetails function displays a dialog box containing the details of a selected
' address list entry.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIDetails IMPORT "MAPI32.DLL" ALIAS "MAPIDetails" ( _
   BYVAL lhSession AS DWORD _                           ' __in LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in ULONG_PTR ulUIParam
 , BYREF lpRecip AS MapiRecipDesc _                     ' __in lpMapiRecipDesc lpRecip
 , BYVAL flFlags AS DWORD _                             ' __in FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in ULONG ulReserved
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' The MAPIResolveName function transforms a message recipient's name as entered by a
' user to an unambiguous address list entry.
' Note: Deprecated. The use of this API is discouraged. The API may be removed from future
' releases of Windows.
' ========================================================================================
DECLARE FUNCTION MAPIResolveName IMPORT "MAPI32.DLL" ALIAS "MAPIResolveName" ( _
   BYVAL lhSession AS DWORD _                           ' __in  LHANDLE lhSession
 , BYVAL ulUIParam AS DWORD _                           ' __in  ULONG_PTR ulUIParam
 , BYREF lpszName AS ASCIIZ _                           ' __in  LPSTR lpszName
 , BYVAL flFlags AS DWORD _                             ' __in  FLAGS flFlags
 , BYVAL ulReserved AS DWORD _                          ' __in  ULONG ulReserved
 , BYREF lppRecip AS DWORD _                            ' __out lpMapiRecipDesc FAR *lppRecip
 ) AS DWORD                                             ' ULONG

#IF NOT %DEF(%SUCCESS_SUCCESS)
%SUCCESS_SUCCESS                 = 0
#ENDIF
%MAPI_USER_ABORT                 = 1
%MAPI_E_USER_ABORT               = %MAPI_USER_ABORT
%MAPI_E_FAILURE                  = 2
%MAPI_E_LOGON_FAILURE            = 3
%MAPI_E_LOGIN_FAILURE            = %MAPI_E_LOGON_FAILURE
%MAPI_E_DISK_FULL                = 4
%MAPI_E_INSUFFICIENT_MEMORY      = 5
%MAPI_E_ACCESS_DENIED            = 6
%MAPI_E_TOO_MANY_SESSIONS        = 8
%MAPI_E_TOO_MANY_FILES           = 9
%MAPI_E_TOO_MANY_RECIPIENTS      = 10
%MAPI_E_ATTACHMENT_NOT_FOUND     = 11
%MAPI_E_ATTACHMENT_OPEN_FAILURE  = 12
%MAPI_E_ATTACHMENT_WRITE_FAILURE = 13
%MAPI_E_UNKNOWN_RECIPIENT        = 14
%MAPI_E_BAD_RECIPTYPE            = 15
%MAPI_E_NO_MESSAGES              = 16
%MAPI_E_INVALID_MESSAGE          = 17
%MAPI_E_TEXT_TOO_LARGE           = 18
%MAPI_E_INVALID_SESSION          = 19
%MAPI_E_TYPE_NOT_SUPPORTED       = 20
%MAPI_E_AMBIGUOUS_RECIPIENT      = 21
%MAPI_E_AMBIG_RECIP              = %MAPI_E_AMBIGUOUS_RECIPIENT
%MAPI_E_MESSAGE_IN_USE           = 22
%MAPI_E_NETWORK_FAILURE          = 23
%MAPI_E_INVALID_EDITFIELDS       = 24
%MAPI_E_INVALID_RECIPS           = 25
%MAPI_E_NOT_SUPPORTED            = 26


#IF %DEF(%MAPIX_INC)
'/*  Maps from a simple mapi session to a MAPI 1.0 extended mapi session */

' ========================================================================================
' ScMAPIXFromSMAPI
' The ScMAPIXFromSMAPI function enables a client application to pass in a Simple MAPI
' session handle and get back a pointer to a MAPI session object.
' ========================================================================================
DECLARE FUNCTION ScMAPIXFromSMAPI IMPORT "MAPI32.DLL" ALIAS "ScMAPIXFromSMAPI" ( _
   BYVAL lhSimpleSession AS DWORD _                     ' __in  LHANDLE lhSimpleSession
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG ulFlags
 , BYREF lpInterface AS GUID _                          ' __in  LPCIID lpInterface
 , BYREF lppMAPISession AS IMAPISession _               ' __out LPMAPISESSION FAR * lppMAPISession
 ) AS LONG                                              ' SCODE
' ========================================================================================

#ENDIF   ' /* MAPIX_H */

' ========================================================================================
' PBMapiSendMail
' ========================================================================================
' This function sends mail without a dialog to the given list of recipients and attaches
' the given list of files.
'
' Parameters:
'
' lhSession    =  Simple MAPI session handle.
' strSubject   =  Subject of the email.
' strNote      =  Email text.
' strNames     =  A list of ; delimited names that correspond to the addresses above.
'                   e.g. "Don on US Internet; Don's Compuserve Account"
' strAddresses =  A list of email addresses separated by ;'s Make sure to put in the
'                 message type preceded by a : if it's not being delivered to an MS Mail
'                 post office. For example, if you're sending mail out to the internet via
'                 MS Mail, the mail type is SMTP. You will need to preceed the address
'                 with SMTP:
'                   e.g. "SMTP:ddickinson@usinternet.com;SMTP:ddickinson@compuserve.com"
' strFiles     =  A list of ; delimited file names (full drive letter, file path and file
'                 name must be included). If the file doesn't exist (DIR$(FileName) = "")
'                 then it will be ignored.
' ========================================================================================

FUNCTION PBMapiSendMail ( _
   BYVAL lhSession AS DWORD, _
   BYVAL strSubject AS STRING, _
   BYVAL strNote AS STRING, _
   BYVAL strNames AS STRING, _
   BYVAL strAddresses AS STRING, _
   BYVAL strFiles AS STRING, _
   OPTIONAL BYVAL fShowDialog AS LONG _
   ) AS DWORD

   LOCAL i AS LONG                             ' // Loop counter
   LOCAL dwResult AS LONG                      ' // Result code
   LOCAL numFiles AS LONG                      ' // Number of files
   LOCAL idx AS LONG                           ' // Index variable
   LOCAL flFlags AS DWORD                      ' // Flags
   LOCAL numRecips AS LONG                     ' // Number of recipients
   LOCAL tMessage AS MapiMessage               ' // MapiMessage structure
   LOCAL szSubject AS ASCIIZ * 256             ' // Message subject
   LOCAL szNote AS ASCIIZ * 32768              ' // Message text
   LOCAL szTimeStamp AS ASCIIZ * 50            ' // Time stamp

   DIM   szFiles() AS ASCIIZ * %MAX_PATH       ' // Array of filenames
   DIM   szAddr() AS ASCIIZ * 256              ' // Array of addresses
   DIM   szNames() AS ASCIIZ * 256             ' // Array of names
   DIM   tRecips() AS MapiRecipDesc            ' // Array of MapiRecipDesc structures
   DIM   tFiles() AS MapiFileDesc              ' // Array of MapiFileDesc structures

   ' Message subject, typically limited to 256 characters or less.
   szSubject = TRIM$(strSubject)
   ' The format is YYYY/MM/DD HH:MM, using a 24-hour clock.
   szTimeStamp = DATE$ + " " + TIME$

   ' Create the array of addresses
   IF TRIM$(strNames) = "" THEN
      numRecips = 0
   ELSE
      numRecips = PARSECOUNT(strNames, ";")
   END IF

   REDIM szAddr(1 TO numRecips)
   REDIM szNames(1 TO numRecips)
   REDIM tRecips(1 TO numRecips)

   IF numRecips > 0 THEN
      FOR i = 1 TO numRecips
         szNames(i) = PARSE$(strNames, ";", i)
         szAddr(i) = PARSE$(strAddresses, ";", i)
         tRecips(i).ulReserved = 0
         tRecips(i).ulRecipClass = %MAPI_TO
         tRecips(i).lpszName = VARPTR(szNames(i))
         tRecips(i).lpszAddress = VARPTR(szAddr(i))
         tRecips(i).ulEIDSize = 0
         tRecips(i).lpEntryID = 0
      NEXT
   END IF

   ' Create the array of files
   IF TRIM$(strFiles) = "" THEN
      numFiles = 0
   ELSE
      numFiles = PARSECOUNT(strFiles, ";")
   END IF

   REDIM szFiles(1 TO numFiles)
   REDIM tFiles(1 TO numFiles)

   idx = 0
   szNote = TRIM$(strNote) + CHR$(13) + CHR$(10) + SPACE$(numFiles)

   FOR i = 1 TO numFiles
      szFiles(i) = PARSE$(strFiles, ";", i)
      IF DIR$(szFiles(i)) <> "" THEN
        idx = idx + 1
        tFiles(idx).ulReserved = 0
        tFiles(idx).flFlags = 0
        tFiles(idx).nPosition = LEN(szNote) - 1 - (numFiles - i)
        tFiles(idx).lpszPathName = VARPTR(szFiles(i))
        tFiles(idx).lpszFileName = 0
        tFiles(idx).lpFileType = 0
      END IF
   NEXT

   numFiles = idx

   ' Fill the message structure for passing to the MAPI call.
   tMessage.ulReserved = 0
   tMessage.lpszSubject = VARPTR(szSubject)
   tMessage.lpszNoteText = VARPTR(szNote)
   tMessage.lpszMessageType = 0
   tMessage.lpszDateReceived = VARPTR(szTimeStamp)
   tMessage.lpszConversationID = 0
   tMessage.flFlags = 0
   tMessage.lpOriginator = 0
   tMessage.nRecipCount = numRecips

   IF numRecips > 0 THEN
      tMessage.lpRecips = VARPTR(tRecips(1))
   ELSE
      tMessage.lpRecips = 0
   END IF

   tMessage.nFileCount = numFiles
   IF numFiles > 0 THEN
      tMessage.lpFiles = VARPTR(tFiles(1))
   ELSE
      tMessage.lpFiles = 0
   END IF

   ' Make the call.
   flFlags = %MAPI_LOGON_UI
   IF fShowDialog THEN flFlags = %MAPI_LOGON_UI OR %MAPI_DIALOG
   dwResult = MAPISendMail(lhSession, 0, tMessage, flFlags, 0)

   FUNCTION = dwResult

END FUNCTION
' ========================================================================================

' ========================================================================================
' WRAPPER FUNCTIONS
' Based on previous work by Don Dickinson.
' ========================================================================================

' ========================================================================================
' PBSendMapiMail
' ========================================================================================
' strProfileName =  A profile name, limited to 256 characters or less. This is the profile
'                   to use when logging on. If you pass an empty string, and the flFlags
'                   parameter is set to %MAPI_LOGON_UI, MAPILogon displays a logon dialog
'                   box with an empty name field.
' strPassword    =  A credential string, limited to 256 characters or less. If the
'                   messaging system does not require password credentials, or if it
'                   requires that the user enter them, the strPassword parameter should be
'                   an empty string. When the user must enter credentials, the flFlags
'                   parameter must be set to %MAPI_LOGON_UI to allow a logon dialog box to
'                   be displayed.
' strSubject     =  Subject of the email.
' strNote        =  Email text.
' strAddresses   =  A list of email addresses separated by ;'s Make sure to put in the
'                   message type preceded by a : if it's not being delivered to an MS Mail
'                   post office. For example, if you're sending mail out to the internet
'                   via MS Mail, the mail type is SMTP. You will need to preceed the
'                   address with SMTP:
'                     e.g. "SMTP:ddickinson@usinternet.com;SMTP:ddickinson@compuserve.com"
' strNames       =  A list of ; delimited names that correspond to the addresses above.
'                     e.g. "Don on US Internet; Don's Compuserve Account"
' strFiles       =  A list of ; delimited file names (full drive letter, file path and file
'                   name must be included). If the file doesn't exist (DIR$(FileName) = "")
'                   then it will be ignored.
' ========================================================================================

FUNCTION PBSendMapiMail ( _
   BYVAL strProfileName AS STRING, _
   BYVAL strPassword AS STRING, _
   BYVAL strSubject AS STRING, _
   BYVAL strNote AS STRING, _
   BYVAL strNames AS STRING, _
   BYVAL strAddresses AS STRING, _
   BYVAL strFiles AS STRING, _
   OPTIONAL BYVAL fShowDialog AS LONG _
   ) AS DWORD

   LOCAL lhSession AS DWORD
   LOCAL dwResult AS DWORD
   LOCAL szProfileName AS ASCIIZ * 256
   LOCAL szPassword AS ASCIIZ * 256

   szProfileName = strProfileName
   szPassword = strPassword

   ' Logon
   dwResult = MAPILogon(0, szProfileName, szPassword, %MAPI_LOGON_UI, 0, lhSession)
   IF dwResult <> %SUCCESS_SUCCESS OR ISFALSE lhSession THEN
      FUNCTION = dwResult
      EXIT FUNCTION
   END IF


   ' Provide the list of names, addresses, and attachents.
   ' Note that addresses are OPTIONAL, If you are part of an MS Mail post office, you
   ' can send mail to others in that post office, or to people already in your address
   ' book, by simply referring to them by name. For example, if I want to send Dave,
   ' Troy, and Tim interoffice, MS Mail email, I can do this ...
   '   strAddresses = ""
   '   strNames = "Dave;Troy;Tim"
   '
   ' If you're sending to someone whose alias is not in your address book, you need to
   ' specify both Names and Addresses. If the address is an internet address, you also
   ' need to indicate the transport for the email by putting it in front of the address
   ' and following it with a semi-colon, e.g. I have the internet mail service installed,
   ' so I precede addresses with SMTP: to tell ms mail to deliver via the internet.
   '
   '      strNames = "Don Dickinson"
   '      strAddresses = "SMTP:ddickinson@usinternet.com"
   '
   ' Files are optional. If you want to attach things to the email,  then list the files
   ' separated by ;'s. If you don't want files, just pass ""
   '
   ' strFiles = "c:\code\winsock\test.txt;c:\code\winsock\test.bas;c:\code\winsock\test.fil"

   ' Send the mail
   '   dwResult = PBMapiSendMail(lhSession, "Mail test", "Document XXXX attached", _
   '                             strNames, strAddresses, strFiles, %TRUE)

   dwResult = PBMapiSendMail(lhSession, strSubject, strNote, strNames, _
                             strAddresses, strFiles, fShowDialog)

   ' Logoff
   MAPILogoff lhSession, 0, 0, 0

   FUNCTION = dwResult

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sample code to send an email with an attachement
' Note: Be aware that, depending of the security settings, Microsoft Outlook will not
' attach some type of "dangerous" files, such .bas and .exe.
' ========================================================================================
'#COMPILE EXE
'#DIM ALL
'#INCLUDE "MAPI.INC"

'FUNCTION PBMAIN () AS LONG

'   LOCAL dwResult AS DWORD
'   LOCAL strProfileName AS STRING
'   LOCAL strPassword AS STRING
'   LOCAL strSubject AS STRING
'   LOCAL strNote AS STRING
'   LOCAL strNames AS STRING
'   LOCAL strAddresses AS STRING
'   LOCAL strFiles AS STRING
'   LOCAL fShowDialog AS LONG

'   strProfileName = "Outlook"
'   strPassword = ""
'   strSubject = "Mail test"
'   strNote = "MAPI.INC attached"
'   strNames = "José Roca"
'   strAddresses = "JRoca@com.it-berater.org"
'   strFiles = "C:\WINAPI\MAPI.INC;F:\WINAPI\TestMapi.zip"
'   fShowDialog = %TRUE

'   dwResult = PBSendMapiMail(strProfileName, strPassword, strSubject, strNote, _
'                             strNames, strAddresses, strFiles, fShowDialog)

'END FUNCTION
' ========================================================================================
