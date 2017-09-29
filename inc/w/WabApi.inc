' ########################################################################################
' Microsoft Windows
' File: WabApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Windows Address Book
' New applications should not use this set of interfaces. These interfaces exist for
' backward compatibility with legacy applications. These interfaces will be unavailable in
' the future.
' ========================================================================================

#INCLUDE THIS ONCE
%WABAPI_INC = 2

#INCLUDE ONCE "mapix.inc"

$WAB_DLL_NAME = "WAB32.DLL"
$WAB_DLL_PATH_KEY = "Software\Microsoft\WAB\DLLPath"

' ========================================================================================
' IWABObject interface
' This interface provides access to the Microsoft® Windows® Address Book (WAB) object
' which contains function pointers to memory allocation functions and database maintenance
' functions.
' Note: The address of this interface is returned by the WABOpen/WABOpenEx functions.
' I have been unable to find the IID of this interface (apparently it doesn't have one).
' ========================================================================================
INTERFACE IWABObject GUID$("{00000000-0000-0000-0000-000000000000}")

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR FAR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateBuffer ( _                            ' VTable offset = 16
     BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   , BYREF lppBuffer AS DWORD _                         ' __out LPVOID FAR * lppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateMore ( _                              ' VTable offset = 20
     BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   , BYVAL lpObject AS DWORD _                          ' __in LPVOID lpObject
   , BYREF lppBuffer AS DWORD _                         ' __out LPVOID FAR * lppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 24
     BYVAL lpBuffer AS DWORD _                          ' __in LPVOID lpBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Backup ( _                                    ' VTable offset = 28
     BYREF lpFileName AS ASCIIZ _                       ' __in LPSTR lpFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Import ( _                                    ' VTable offset = 32
     BYREF lpImportParam AS ASCIIZ _                    ' __in LPSTR lpImportParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Find ( _                                      ' VTable offset = 36
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VCardDisplay ( _                              ' VTable offset = 40
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF lpszFileName AS ASCIIZ _                     ' __in LPSTR  lpszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LDAPUrl ( _                                   ' VTable offset = 44
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszURL AS ASCIIZ _                          ' __in LPSTR lpszURL
   , BYREF lppMailUser AS IMailUser _                   ' __out LPMAILUSER *lppMailUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VCardCreate ( _                               ' VTable offset = 48
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszVCard AS ASCIIZ _                        ' __in LPSTR lpszVCard
   , BYVAL lpMailUser AS IMailUser _                    ' __in LPMAILUSER lpMailUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VCardRetrieve ( _                             ' VTable offset = 52
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszVCard AS ASCIIZ _                        ' __in LPSTR lpszVCard
   , BYREF lppMailUser AS IMailUser _                   ' __out LPMAILUSER *lppMailUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMe ( _                                     ' VTable offset = 56
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpdwAction AS DWORD _                        ' __out DWORD * lpdwAction
   , BYREF lpsbEID AS SBinary _                         ' __in SBinary * lpsbEID
   , BYVAL ulParam AS DWORD _                           ' __in ULONG ulParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMe ( _                                     ' VTable offset = 60
     BYVAL lpIAB AS IAddrBook _                         ' __in LPADRBOOK lpIAB
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF sbEID AS SBinary _                           ' __in SBinary sbEID
   , BYVAL ulParam AS DWORD _                           ' __in ULONG ulParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
' ========================================================================================


'/*** WABObject_LDAPUrl flags ***/

'// If this flag is specified and the LDAPUrl returns a single
'// query result, instructs the WAB to return the result in the
'// form of a MailUser object instead of displaying Details on it
'// If there are multiple results to the query, fail ..

%WABOBJECT_LDAPURL_RETURN_MAILUSER = &H00000001

'// WAB 5.0x and higher:
'// If your application supports Unicode and wants to pass ina Unicode
'//  URL to the WAB, you can cast the Unicode URL to an LPSTR and pass it
'// to the LDAPUrl API, *also* setting ulFlags to MAPI_UNICODE to mark the URL
'// as such. Casting is prefered to converting the string because
'// (a) Converting the string may result in loss of data (b) since this is an
'// already published interface we can't modify the interface.
'//      MAPI_UNICODE                        0x80000000



'/*** WABObject_GetMe returned parameter ***/
'// If the GetMe call results in the creation of a new 'Me' contact,
'// the lpdwAction returned parameter will contain this value
'// indicating to the caller that the object is freshly created and
'// does not have any properties in it

%WABOBJECT_ME_NEW = &H00000001


'/*** WABObject_GetMe flags ***/
'// WABObject_GetMe will create a new ME object by default, if
'// none already exists. To force the call to not-create an object, if
'// one doesn't already exist, specify the WABOBJECT_ME_NOCREATE flag.
'// If no me is found, the call fails with MAPI_E_NOT_FOUND.
'// Other flag for WABObject_GetMe is AB_NO_DIALOG defined in wabdefs.h

%WABOBJECT_ME_NOCREATE = &H00000002


'/*** IWABObject_VCard Create/Retrieve ***/
'// Flags the WAB whether the lpszVCard parameter is a filename or if
'// it is a NULL terminated string containing the compelte VCard contents
'//

%WAB_VCARD_FILE = &H00000000
%WAB_VCARD_STREAM = &H00000001


'//
'// Input information to pass to WABOpen
'//

' // Size = 32 bytes
TYPE WAB_PARAM DWORD
   cbSize     AS DWORD        ' ULONG   // sizeof(WAB_PARAM).
   hwnd       AS DWORD        ' HWND    // hWnd of calling client Application. Can be NULL
   szFileName AS ASCIIZ PTR   ' LPTSTR  // WAB File name to open. if NULL, opens default.
   ulFlags    AS DWORD        ' ULONG   // See below
   guidPSExt  AS GUID         ' GUID    // A GUID that identifies the calling application's Property Sheet extensions
                              '         // The GUID can be used to determine whether the extension prop sheets are displayed or not.
END TYPE

''//flags for WAB_PARAM
'#define WAB_USE_OE_SENDMAIL     0x00000001  // Tells WAB to use Outlook Express for e-mail before checking for a
'                                            // default Simple MAPI client. Default behaviour is to check for the
'                                            // Simple MAPI client first

'#define WAB_ENABLE_PROFILES     0x00400000  // Invokes WAB in a Identity-aware session using Identity-Manager
'                                            // based profiles

%WAB_USE_OE_SENDMAIL = &H00000001???
%WAB_ENABLE_PROFILES = &H00400000???


'//
'// Root public entry points for WAB API
'//

'STDMETHODIMP WABOpen(LPADRBOOK FAR * lppAdrBook, LPWABOBJECT FAR * lppWABObject,
'  LPWAB_PARAM lpWP, DWORD Reserved2);

'typedef HRESULT (STDMETHODCALLTYPE WABOPEN)(
'    LPADRBOOK FAR * lppAdrBook,
'    LPWABOBJECT FAR * lppWABObject,
'    LPWAB_PARAM lpWP,
'    DWORD Reserved2
');

' ========================================================================================
' Retrieves the path of the WAB32.DLL and loads it into memory.
' ========================================================================================
FUNCTION LoadWABLibrary (BYREF hLib AS DWORD) AS LONG

   LOCAL hr AS LONG                          ' // Result code
   LOCAL hKey AS DWORD                       ' // Key handle
   LOCAL szPathToWAB AS ASCIIZ * %MAX_PATH   ' // Path of WAB32.DLL

   hr = RegOpenKeyExA(%HKEY_LOCAL_MACHINE, BYCOPY $WAB_DLL_PATH_KEY, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN FUNCTION = hr : EXIT FUNCTION
   hr = RegQueryValueExA(hKey, "", 0, 0, szPathToWAB, SIZEOF(szPathToWAB))
   RegCloseKey hKey
   IF hr <> %ERROR_SUCCESS THEN FUNCTION = hr : EXIT FUNCTION
   hLib = LoadLibraryA(szPathToWAB)
   IF hLib = %NULL THEN FUNCTION = GetLastError

END FUNCTION
' ========================================================================================

' ========================================================================================
' WABOpen Function
' Provides access to the address book through a number of object interfaces. The root
' interface is IAddrBook, which is a subset of the MAPI implementation of IAddrBook.
' Can't be linked to the application. Use LoadLibrary/GetProcAddress.
' ========================================================================================
DECLARE FUNCTION Proto_WABOpen ( _
   BYREF lppAdrBook AS IAddrBook _                      ' __out LPADRBOOK *lppAdrBook
 , BYREF lppWABObject AS IWABObject _                   ' __out LPWABOBJECT *lppWABObject
 , BYREF lpWABParam AS WAB_PARAM _                      ' __in LPWAB_PARAM lpWABParam
 , BYVAL Reserved2 AS DWORD _                           ' __in DWORD Reserved2
   ) AS LONG                                            ' HRESULT
' ========================================================================================

' ========================================================================================
' Wrapper function for WABOpen
' ========================================================================================
FUNCTION WABOpen ( _
   BYVAL hLib AS DWORD _
 , BYREF lppAdrBook AS IAddrBook _
 , BYREF lppWABObject AS IWABObject _
 , BYREF lpWABParam AS WAB_PARAM _
   ) AS LONG

   LOCAL hr AS LONG                           ' // Result code
   LOCAL pProcAddress AS DWORD                ' // Address of the WABOpen function

   IF hLib = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   pProcAddress = GetProcAddress(hLib, "WABOpen")
   IF ISFALSE pProcAddress THEN FUNCTION = GetLastError : EXIT FUNCTION
   CALL DWORD pProcAddress USING Proto_WABOpen(lppAdrBook, lppWABObject, lpWABParam, 0) TO hr
   FUNCTION = hr

END FUNCTION
' ========================================================================================


'STDMETHODIMP WABOpenEx(LPADRBOOK FAR * lppAdrBook,
'  LPWABOBJECT FAR * lppWABObject,
'  LPWAB_PARAM lpWP,
'  DWORD Reserved,
'  ALLOCATEBUFFER * fnAllocateBuffer,
'  ALLOCATEMORE * fnAllocateMore,
'  FREEBUFFER * fnFreeBuffer);

'typedef HRESULT (STDMETHODCALLTYPE WABOPENEX)(
'    LPADRBOOK FAR * lppAdrBook,
'    LPWABOBJECT FAR * lppWABObject,
'    LPWAB_PARAM lpWP,
'    DWORD Reserved,
'    ALLOCATEBUFFER * fnAllocateBuffer,
'    ALLOCATEMORE * fnAllocateMore,
'    FREEBUFFER * fnFreeBuffer
');

' ========================================================================================
' WABOpenEx Function
' Provides access to the Microsoft® Windows® Address Book (WAB) through a number of object
' interfaces. The root interface is IAddrBook, which is a subset of the MAPI
' implementation of IAddrBook.
' Can't be linked to the application. Use LoadLibrary/GetProcAddress.
' ========================================================================================
DECLARE FUNCTION Proto_WABOpenEx ( _
   BYREF lppAdrBook AS IAddrBook _                      ' __out LPADRBOOK *lppAdrBook
 , BYREF lppWABObject AS IWABObject _                   ' __out LPWABOBJECT *lppWABObject
 , BYREF lpWABParam AS WAB_PARAM _                      ' __in LPWAB_PARAM lpWABParam
 , BYVAL Reserved2 AS DWORD _                           ' __in DWORD Reserved2
 , BYVAL lpfnAllocateBuffer AS DWORD _                  ' __in ALLOCATEBUFFER *lpfnAllocateBuffer
 , BYVAL lpfnAllocateMore AS DWORD _                    ' __in ALLOCATEMORE *lpfnAllocateMore
 , BYVAL lpfnFreeBuffer AS DWORD _                      ' __in FREEBUFFER *lpfnFreeBuffer
   ) AS LONG                                            ' HRESULT
' ========================================================================================

' ========================================================================================
' Wrapper function for WABOpenEx
' ========================================================================================
FUNCTION WABOpenEx ( _
   BYVAL hLib AS DWORD _
 , BYREF lppAdrBook AS IAddrBook _
 , BYREF lppWABObject AS IWABObject _
 , BYREF lpWABParam AS WAB_PARAM _
 , BYVAL lpfnAllocateBuffer AS DWORD _
 , BYVAL lpfnAllocateMore AS DWORD _
 , BYVAL lpfnFreeBuffer AS DWORD _
   ) AS LONG

   LOCAL hr AS LONG                           ' // Result code
   LOCAL pProcAddress AS DWORD                ' // Address of the WABOpen function

   IF ISFALSE hLib THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   pProcAddress = GetProcAddress(hLib, "WABOpenEx")
   IF ISFALSE pProcAddress THEN FUNCTION = GetLastError : EXIT FUNCTION
   CALL DWORD pProcAddress USING Proto_WABOpenEx(lppAdrBook, lppWABObject, lpWABParam, 0, lpfnAllocateBuffer, lpfnAllocateMore, lpfnFreeBuffer) TO hr
   FUNCTION = hr

END FUNCTION
' ========================================================================================


' // Size = 20 bytes
TYPE WABIMPORTPARAM DWORD
   cbSize       AS DWORD        ' ULONG        // sizeof(WABIMPORTPARAM)
   lpAdrBook    AS DWORD  PTR   ' IAddrBook *  // ptr to the IAdrBook object (required)
   hwnd         AS DWORD        ' HWND         // Parent HWND for any dialogs
   ulFlags      AS DWORD        ' ULONG        // 0 or MAPI_DIALOG to show progress dialog and messages
   lpszFileName AS ASCIIZ PTR   ' LPSTR        // FileName to import or NULL .. if NULL will show FileOpen dialog
END TYPE


'/* ---- WABEXTDISPLAY ----------------- */
'/* WABEXTDISPLAY Structure used in extending the WAB Details Property Dialogs
'    and for doing WAB Context Menu verb extensions.
'   The structure is passed into the IWABExtInit::Initialize method
'    of the implementor */

'// Flags
'#define WAB_DISPLAY_LDAPURL 0x00000001  // The object being displayed is an LDAP URL
'                                        // The URL can be found in the lpsz struct member

'#define WAB_CONTEXT_ADRLIST 0x00000002  // THe lpv parameter contains a pointer to an
'                                        // AdrList structure corresponding to selected items
'                                        // on which to display a context menu

'#define WAB_DISPLAY_ISNTDS  0x00000004  // Identifies that the entry being displayed originated
'                                        // on the NT Directory Service, for clients that use ADSI and
'                                        // retrieve additional information from the service.

'//      MAPI_UNICODE        0x80000000  // Indicates that the WED.lpsz string is actually a UNICODE
'                                        //  string and should be cast to a (LPWSTR) before using it
'                                        // If this flag is not present then the WED.lpsz is a DBCS string
'                                        //  and should be cast to an LPSTR before using.

%WAB_DISPLAY_LDAPURL = &H00000001???
%WAB_CONTEXT_ADRLIST = &H00000002???
%WAB_DISPLAY_ISNTDS  = &H00000004???


'// Struct
'typedef struct _WABEXTDISPLAY
'{
'    ULONG cbSize;
'    LPWABOBJECT lpWABObject;    // pointer to IWABObject
'    LPADRBOOK lpAdrBook;        // pointer to IAdrBook object
'    LPMAPIPROP lpPropObj;       // Object being displayed
'    BOOL fReadOnly;             // Indicates if this is a ReadOnly mode
'    BOOL fDataChanged;          // Set by extension sheet to signal data change
'    ULONG ulFlags;              // See above
'    LPVOID lpv;                 // Used for passing in specific data
'    LPTSTR lpsz;               // Used for passing in specific data
'} WABEXTDISPLAY, FAR * LPWABEXTDISPLAY;


' // Size = 36 bytes
TYPE WABEXTDISPLAY DWORD
   cbSize       AS DWORD        ' ULONG
   lpWABObject  AS DWORD PTR    ' LPWABOBJECT
   lpAdrBook    AS DWORD PTR    ' LPADRBOOK
   lpPropObj    AS DWORD PTR    ' LPMAPIPRO
   fReadOnly    AS LONG         ' BOOL
   fDataChanged AS LONG         ' BOOL
   ulFlags      AS DWORD        ' ULONG
   lpv          AS DWORD        ' LPVOID
   lpsz         AS ASCIIZ PTR   ' LPTSTR
END TYPE


' ========================================================================================
' IWABExtInit interface
' $IID_IWABExtInit = GUID$("{EA22EBF0-87A4-11D1-9ACF-00A0C91F9C8B}")
' Provides a Microsoft Windows Address Book (WAB) module with information about the object
' being displayed.
' ========================================================================================

$IID_IWABExtInit = GUID$("{ea22ebf0-87a4-11d1-9acf-00a0c91f9c8b}")

INTERFACE IWABExtInit $IID_IWABExtInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _
     BYREF lpWABExtDisplay AS WABEXTDISPLAY _           ' __in WABEXTDISPLAY *lpWABExtDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
' ========================================================================================
