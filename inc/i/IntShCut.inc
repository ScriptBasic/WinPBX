' ########################################################################################
' Microsoft Windows
' File: IntShCut.inc
' Contents: Internet Shortcut interface definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%INTSHCUT_INC = 1

'/* Headers
' **********/

#INCLUDE ONCE "isguids.inc"


'/* Constants
' ************/

'/* Define API decoration for direct import of DLL functions. */

'/* HRESULTs */

'//
'// MessageId: E_FLAGS
'//
'// MessageText:
'//
'//  The flag combination is invalid.
'//
'#define E_FLAGS                     MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 0x1000)
%E_FLAGS = &H80041000&

'//
'// MessageId: IS_E_EXEC_FAILED
'//
'// MessageText:
'//
'//  The URL's protocol handler failed to run.
'//
'#define IS_E_EXEC_FAILED            MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 0x2002)
%IS_E_EXEC_FAILED = &H80042002&

'//
'// MessageId: URL_E_INVALID_SYNTAX
'//
'// MessageText:
'//
'//  The URL's syntax is invalid.
'//
'#define URL_E_INVALID_SYNTAX        MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 0x1001)
%URL_E_INVALID_SYNTAX = &H80041001&

'//
'// MessageId: URL_E_UNREGISTERED_PROTOCOL
'//
'// MessageText:
'//
'//  The URL's protocol does not have a registered protocol handler.
'//
'#define URL_E_UNREGISTERED_PROTOCOL MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 0x1002)
%URL_E_UNREGISTERED_PROTOCOL = &H80041002&

'/* Interfaces
' *************/

'//
'// Input flags for IUniformResourceLocator::SetURL().
'//

' IURL_SETURL_FLAGS enum
%IURL_SETURL_FL_GUESS_PROTOCOL        = &H0001???   ' // Guess protocol if missing
%IURL_SETURL_FL_USE_DEFAULT_PROTOCOL  = &H0002???   ' // Use default protocol if missing



'//
'// Input flags for IUniformResourceLocator()::InvokeCommand().
'//
' IURL_INVOKECOMMAND_FLAGS enum
%IURL_INVOKECOMMAND_FL_ALLOW_UI         = &H0001???
%IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB = &H0002???   ' // Ignore pcszVerb
%IURL_INVOKECOMMAND_FL_DDEWAIT          = &H0004???   ' // pass DDEWAIT to ShellExec
%IURL_INVOKECOMMAND_FL_ASYNCOK          = &H0008???   ' // pass SEE_MASK_ASYNCOK to ShellExec


'//
'// Command info for IUniformResourceLocator::InvokeCommand().
'//

' // Size = 16 bytes
TYPE URLINVOKECOMMANDINFOA DWORD
   dwcbSize   AS DWORD       ' DWORD  // Size of structure
   dwFlags    AS DWORD       ' DWORD  // Bit field of IURL_INVOKECOMMAND_FLAGS
   hwndParent AS DWORD       ' HWND   // Parent window.  Valid only if IURL_INVOKECOMMAND_FL_ALLOW_UI is set.
   pcszVerb   AS ASCIIZ PTR  ' LPCSTR // Verb to invoke.  Ignored if IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB is set.
END TYPE

' // Size = 16 bytes
TYPE URLINVOKECOMMANDINFOW DWORD
   dwcbSize   AS DWORD          ' DWORD   // Size of structure
   dwFlags    AS DWORD          ' DWORD   // Bit field of IURL_INVOKECOMMAND_FLAGS
   hwndParent AS DWORD          ' HWND    // Parent window.  Valid only if IURL_INVOKECOMMAND_FL_ALLOW_UI is set.
   pcszVerb   AS WSTRINGZ PTR   ' LPCWSTR // Verb to invoke.  Ignored if IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB is set.
END TYPE

#IF %DEF(%UNICODE)
   MACRO URLINVOKECOMMANDINFO = URLINVOKECOMMANDINFOW
#ELSE
   MACRO URLINVOKECOMMANDINFO = URLINVOKECOMMANDINFOA
#ENDIF

' // Size = 16 bytes
TYPE CURLINVOKECOMMANDINFOA DWORD
   dwcbSize   AS DWORD       ' DWORD  // Size of structure
   dwFlags    AS DWORD       ' DWORD  // Bit field of IURL_INVOKECOMMAND_FLAGS
   hwndParent AS DWORD       ' HWND   // Parent window.  Valid only if IURL_INVOKECOMMAND_FL_ALLOW_UI is set.
   pcszVerb   AS ASCIIZ PTR  ' LPCSTR // Verb to invoke.  Ignored if IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB is set.
END TYPE

' // Size = 16 bytes
TYPE CURLINVOKECOMMANDINFOW DWORD
   dwcbSize   AS DWORD          ' DWORD   // Size of structure
   dwFlags    AS DWORD          ' DWORD   // Bit field of IURL_INVOKECOMMAND_FLAGS
   hwndParent AS DWORD          ' HWND    // Parent window.  Valid only if IURL_INVOKECOMMAND_FL_ALLOW_UI is set.
   pcszVerb   AS WSTRINGZ PTR   ' LPCWSTR // Verb to invoke.  Ignored if IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB is set.
END TYPE

#IF %DEF(%UNICODE)
   MACRO CURLINVOKECOMMANDINFO = CURLINVOKECOMMANDINFOW
#ELSE
   MACRO CURLINVOKECOMMANDINFO = CURLINVOKECOMMANDINFOA
#ENDIF

'//===========================================================================
'//
'// IUniformResourceLocator interface
'//
'// [OverView]
'//
'//  Provides access to Internet Shortcuts.
'//
'// [Member functions]
'//
'// IUniformResourceLocator::SetURL
'//
'//   This member function sets an object's URL.
'//
'//   The dwInFlags parameter specifies the behavior:
'//
'//  IURL_SETURL_FL_GUESS_PROTOCOL: The protocol scheme is guessed and added
'//   to the URL, if it is not specified in pcszURL.
'//
'//  IURL_SETURL_FL_USE_DEFAULT_PROTOCOL: The default protocol scheme is added
'//   to the URL, if it is not specified in pcszURL.
'//
'//   The function returns S_OK if the object's URL is set successfully.
'//  Otherwise, an error code is returned:
'//
'//  E_OUTOFMEMORY:  There is not enough memory to complete the operation.
'//
'//  IS_E_EXEC_FAILED:  The URL's protocol handler failed to run.
'//
'//  URL_E_INVALID_SYNTAX:  The URL's syntax is invalid.
'//
'//  URL_E_UNREGISTERED_PROTOCOL:  The URL's protocol does not have a
'//   registered protocol handler.
'//
'//
'// IUniformResourceLocator::GetURL
'//
'//   This member function retrieves an object's URL.  The ppszURL is a
'//  pointer to a PSTR to be filled in which a pointer to the object's
'//  URL.  When finished, this string should be freed using IMalloc::Free().
'//
'//   The function returns S_OK if the object's URL was retrieved
'//  successfully.  If the object does not have a URL associated with it,
'//  then S_FALSE is returned and *ppszURL is set to NULL.  Otherwise, an
'//  error code is returned:
'//
'//  E_OUTOFMEMORY:  There is not enough memory to complete the operation.
'//
'//  IS_E_EXEC_FAILED:  The URL's protocol handler failed to run.
'//
'//  URL_E_INVALID_SYNTAX:  The URL's syntax is invalid.
'//
'//  URL_E_UNREGISTERED_PROTOCOL:  The URL's protocol does not have a
'//   registered protocol handler.
'//
'//
'// IUniformResourceLocator::InvokeCommand
'//
'//   This member function invokes a command on an object's URL.  The purlici
'//  parameter is a pointer to a URLINVOKECOMMANDINFO structure which
'//  describes the command to be invoked.
'//
'//   The function returns S_OK if the object's URL was opened successfully.
'//  If the object does not have a URL associated with it, the function
'//  returns S_FALSE.  Otherwise, an error code is returned:
'//
'//  E_OUTOFMEMORY:  There is not enough memory to complete the operation.
'//
'//  IS_E_EXEC_FAILED:  The URL's protocol handler failed to run.
'//
'//  URL_E_INVALID_SYNTAX:  The URL's syntax is invalid.
'//
'//  URL_E_UNREGISTERED_PROTOCOL:  The URL's protocol does not have a
'//   registered protocol handler.
'//
'//===========================================================================

INTERFACE IUniformResourceLocator $IID_IUniformResourceLocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetURL ( _                                    ' VTable offset = 12
     BYREF pcszURL AS ASCIIZ _                          ' __in LPCSTR pcszURL
   , BYVAL dwInFlags AS DWORD _                         ' __in DWORD dwInFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetURL ( _                                    ' VTable offset = 16
     BYREF ppszURL AS ASCIIZ _                          ' __out LPSTR *ppszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeCommand ( _                             ' VTable offset = 20
     BYREF purlici AS URLINVOKECOMMANDINFOA _           ' __in PURLINVOKECOMMANDINFOA purlici
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


INTERFACE IUniformResourceLocatorW $IID_IUniformResourceLocatorW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetURL ( _                                    ' VTable offset = 12
     BYREF pcszURL AS WSTRINGZ _                        ' __in LPCWSTR pcszURL
   , BYVAL dwInFlags AS DWORD _                         ' __in DWORD dwInFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetURL ( _                                    ' VTable offset = 16
     BYREF ppszURL AS DWORD _                           ' __out LPWSTR *ppszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeCommand ( _                             ' VTable offset = 20
     BYREF purlici AS URLINVOKECOMMANDINFOW _           ' __in PURLINVOKECOMMANDINFOW purlici
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'/* Prototypes
' *************/

'//
'// Input flags for TranslateURL().
'//
' TRANSLATEURL_IN_FLAGS enum
%TRANSLATEURL_FL_GUESS_PROTOCOL         = &H0001???    ' // Guess protocol if missing
%TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL   = &H0002???    ' // Use default protocol if missing


'//
'//   TranslateURL().  This function applies common translations to a URL
'//  string, creating a new URL string.
'//
'//   This function does not perform any validation on the syntax of the input
'//  URL string.  A successful return value does not indicate that the input
'//  or output URL strings are valid URLS.
'//
'//   The function returns S_OK if the URL string is translated successfully
'//  and *ppszTranslatedURL points to the translated URL string.  S_FALSE
'//  is returned if the URL string did not require translation.  An error
'//  code is returned if an error occurs.
'//
'//  Parameters:
'//   pcszURL -- A pointer to the URL string to be translated.
'//   dwInFlags -- A bit field of TRANSLATEURL_IN_FLAGS.
'//   ppszTranslatedURL -- A pointer to the newly created, translated URL
'//     string, if any.  *ppszTranslatedURL is only valid if S_OK is returned.
'//     If valid, *ppszTranslatedURL should be freed by calling LocalFree().
'//     *ppszTranslatedURL is NULL on error.
'//

DECLARE FUNCTION TranslateUrlA IMPORT "URL.DLL" ALIAS "TranslateUrlA" ( _
   BYREF pcszURL AS ASCIIZ _                            ' __in PCSTR pcszURL
 , BYVAL dwInFlags AS DWORD _                           ' __in DWORD dwInFlags
 , BYREF ppszTranslatedURL AS DWORD _                   ' __out PSTR *ppszTranslatedURL
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TranslateUrlW IMPORT "URL.DLL" ALIAS "TranslateUrlW" ( _
   BYREF pcszURL AS WSTRINGZ _                          ' __in PCWSTR pcszURL
 , BYVAL dwInFlags AS DWORD _                           ' __in DWORD dwInFlags
 , BYREF ppszTranslatedURL AS DWORD _                   ' __out PWSTR *ppszTranslatedURL
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO TranslateUrl = TranslateUrlW
#ELSE
   MACRO TranslateUrl = TranslateUrlA
#ENDIF

'//
'// Input flags for URLAssociationDialog().
'//
' URLASSOCIATIONDIALOG_IN_FLAGS enum
%URLASSOCDLG_FL_USE_DEFAULT_NAME = &H0001???
%URLASSOCDLG_FL_REGISTER_ASSOC   = &H0002???


'//
'//   URLAssocationDialog().  This function invokes the unregistered URL
'//  protocol dialog box, providing a standard ui for choosing the handler for
'//  an unregistered URL protocol.
'//
'//  The functions returns S_OK if the application is registered with the
'//  URL protocol.  S_FALSE is returned if nothing is registered (a one-time
'//  execution via the selected application is requested).
'//
'//  Parameters:
'//   hwndParent -- A handle to the window to be used as the parent
'//   dwInFlags -- A bit field of URLASSOCIATIONDIALOG_IN_FLAGS.  The
'//                flags are:
'//
'//                  URLASSOCDLG_FL_USE_DEFAULT_NAME: Use the default Internet
'//                   Shortcut file name.  Ignore pcszFile.
'//
'//                  URLASSOCDLG_FL_REGISTER_ASSOC: The application
'//                   selected is to be registered as the handler for URLs
'//                   of pcszURL's protocol.  An application is only
'//                   registered if this flag is set, and the user indicates
'//                   that a persistent association is to be made.
'//
'//   pcszFile -- The name of the Internet Shortcut file whose URL's protocol
'//               requires a protocol handler.  Before a verb, like "open", can
'//               be invoked on an Internet Shortcut, a protocol handler must be
'//               registered for its URL protocol.  If
'//               URLASSOCDLG_FL_USE_DEFAULT_NAME is set in dwInFlags, pcszFile
'//               is ignored, and a default Internet Shortcut file name is used.
'//               pcszFile is only used for ui.
'//   pcszURL -- The URL whose unregistered protocol requires a handler.
'//   pszAppBuf -- A buffer to be filled in on success with the path
'//                of the application selected by the user.  pszAppBuf's
'//                buffer is filled in with the empty string on failure.
'//   ucAppBufLen -- The length of pszAppBuf's buffer in characters.
'//

DECLARE FUNCTION URLAssociationDialogA IMPORT "URL.DLL" ALIAS "URLAssociationDialogA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL dwInFlags AS DWORD _                           ' __in DWORD dwInFlags
 , BYREF pcszFile AS ASCIIZ _                           ' __in PCSTR pcszFile
 , BYREF pcszURL AS ASCIIZ _                            ' __in PCSTR pcszURL
 , BYREF pszAppBuf AS ASCIIZ _                          ' __in PSTR pszAppBuf
 , BYREF ucAppBufLen AS DWORD _                         ' __in UINT ucAppBufLen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION URLAssociationDialogW IMPORT "URL.DLL" ALIAS "URLAssociationDialogW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL dwInFlags AS DWORD _                           ' __in DWORD dwInFlags
 , BYREF pcszFile AS WSTRINGZ _                         ' __in PCWSTR pcszFile
 , BYREF pcszURL AS WSTRINGZ _                          ' __in PCWSTR pcszURL
 , BYREF pszAppBuf AS WSTRINGZ _                        ' __in PWSTR pszAppBuf
 , BYREF ucAppBufLen AS DWORD _                         ' __in UINT ucAppBufLen
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO URLAssociationDialog = URLAssociationDialogW
#ELSE
   MACRO URLAssociationDialog = URLAssociationDialogA
#ENDIF


'//
'// Input flags for MIMEAssocationDialog().
'//
' MIMEASSOCIATIONDIALOG_IN_FLAGS enum
%MIMEASSOCDLG_FL_REGISTER_ASSOC = &H0001???


'//
'//   MIMEAssociationDialog().  Invokes the unregistered MIME content
'//  type dialog box.
'//
'//   This function does not perform any validation on the syntax of the
'//  input content type string.  A successful return value does not indicate
'//  that the input MIME content type string is a valid content type.
'//
'//   The function returns S_OK if the MIME content type is associated
'//  with the extension.  The extension is associated as the default
'//  extension for the content type.  S_FALSE is returned if nothing is
'//  registered.  Otherwise, the function returns one of the following
'//  errors:
'//
'//  E_ABORT -- The user cancelled the operation.
'//  E_FLAGS -- The flag combination passed in dwFlags is invalid.
'//  E_OUTOFMEMORY -- Not enough memory to complete the operation.
'//  E_POINTER -- One of the input pointers is invalid.
'//
'//  Parameters:
'//   hwndParent -- A handle to the window to be used as the parent
'//                 window of any posted child windows.
'//   dwInFlags -- A bit field of MIMEASSOCIATIONDIALOG_IN_FLAGS.  The
'//                flags are:
'//
'//              MIMEASSOCDLG_FL_REGISTER_ASSOC: If set, the application
'//               selected is to be registered as the handler for files of
'//               the given MIME type.  If clear, no association is to be
'//               registered.  An application is only registered if this
'//               flag is set, and the user indicates that a persistent
'//               association is to be made.  Registration is only possible
'//               if pcszFile contains an extension.
'//
'//   pcszFile -- A pointer to a string indicating the name of the file
'//               containing data of pcszMIMEContentType's content type.
'//   pcszMIMEContentType -- A pointer to a string indicating the content
'//                          type for which an application is sought.
'//   pszAppBuf -- A buffer to be filled in on success with the path of
'//                the application selected by the user.  pszAppBuf's buffer
'//                is filled in with the empty string on failure.
'//   ucAppBufLen -- The length of pszAppBuf's buffer in characters.
'//

' Note: Microsoft Windows XP Service Pack 2 (SP2) or later: This function is no longer
' supported and returns E_NOTIMPL in all situations.
' Implemented as ANSI version only.

'DECLARE FUNCTION MIMEAssociationDialog IMPORT "URL.DLL" ALIAS "MIMEAssociationDialog" ( _
'   BYVAL hwndParent AS DWORD _                          ' HWND hwndParent
' , BYVAL dwInFlags AS DWORD _                           ' DWORD dwInFlags
' , BYREF pcszFile AS ASCIIZ _                           ' PCSTR pcszFile
' , BYREF pcszMIMEContentType AS ASCIIZ _                ' PCSTR pcszMIMEContentType
' , BYREF pszAppBuf AS ASCIIZ _                          ' PSTR pszAppBuf
' , BYVAL ucAppBufLen AS DWORD _                         ' UINT ucAppBufLen
' ) AS LONG                                              ' HRESULT

'//
'//   InetIsOffline().  This function determines if the user wants to be
'//  "offline" (get all information from the cache).  The dwFlags must be
'//  0.
'//
'//   The function returns TRUE to indicate that the local system is not
'//  currently connected to the Internet.  The function returns FALSE to
'//  indicate that either the local system is connected to the Internet,
'//  or no attempt has yet been made to connect the local system to the
'//  Internet.  Applications that wish to support an off-line mode should
'//  do so if InetIsOffline() returns TRUE.
'//
'//   Off-line mode begins when the user has been prompted to dial-in to
'//  an Internet providor, but canceled the attempt.
'//

DECLARE FUNCTION InetIsOffLine IMPORT "URL.DLL" ALIAS "InetIsOffLine" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
