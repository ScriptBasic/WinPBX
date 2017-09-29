' ########################################################################################
' Microsoft Windows
' File: AdsProp.inc
' Contents: Functions and definitions used in the creation of AD property sheets.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADSPROP_INC = 1

#INCLUDE ONCE "iads.inc"

%WM_ADSPROP_NOTIFY_PAGEINIT   = %WM_USER + 1101  ' // where LPARAM is the PADSPROPINITPARAMS pointer.
%WM_ADSPROP_NOTIFY_PAGEHWND   = %WM_USER + 1102  ' // where WPARAM => page's HWND and LPARAM => page's Title
%WM_ADSPROP_NOTIFY_CHANGE     = %WM_USER + 1103  ' // used to send a change notification to a parent sheet
%WM_ADSPROP_NOTIFY_APPLY      = %WM_USER + 1104  ' // pages send this to the notification object.
%WM_ADSPROP_NOTIFY_SETFOCUS   = %WM_USER + 1105  ' // used internally by the notification object.
%WM_ADSPROP_NOTIFY_FOREGROUND = %WM_USER + 1106  ' // used internally by the notification object.
%WM_ADSPROP_NOTIFY_EXIT       = %WM_USER + 1107  ' // sent on page release
%WM_ADSPROP_NOTIFY_ERROR      = %WM_USER + 1110  ' // used to send the notification object an error message

'//+----------------------------------------------------------------------------
'//
'//  Structure:  ADSPROPINITPARAMS
'//
'//  Usage:      Used to pass page initialization information to new pages from
'//              the notify object.
'//
'//-----------------------------------------------------------------------------

' // Size = 24 bytes
TYPE ADSPROPINITPARAMS DWORD
   dwSize         AS DWORD               ' DWORD   // Set this to the size of the struct.
   dwFlags        AS DWORD               ' DWORD   // Reserved for future use.
   hr             AS LONG                ' HRESULT // If this is non-zero, then the others
   pDsObj         AS DWORD PTR           ' IDirectoryObject *// should be ignored.
   pwzCN          AS WSTRINGZ PTR        ' LPWSTR
   pWritableAttrs AS ADS_ATTR_INFO PTR   ' PADS_ATTR_INFO
END TYPE

'//+----------------------------------------------------------------------------
'//
'//  Structure:  ADSPROPERROR
'//
'//  Usage:      Used to pass page error information to the notify object
'//
'//-----------------------------------------------------------------------------

' // Size = 24 bytes
TYPE ADSPROPERROR DWORD
   hwndPage     AS DWORD          ' HWND    // The HWND of the page that had the error
   pszPageTitle AS WSTRINGZ PTR   ' PWSTR   // The title of the page that had the error
   pszObjPath   AS WSTRINGZ PTR   ' PWSTR   // Path to the object that the error occurred on
   pszObjClass  AS WSTRINGZ PTR   ' PWSTR   // Class of the object that the error occurred on
   hr           AS LONG           ' HRESULT // If this is non-zero, then the others
                                  '         // pszError will be ignored
   pszError     AS WSTRINGZ PTR   ' PWSTR   // An error message.  Used only if hr is zero
END TYPE

'//+----------------------------------------------------------------------------
'//
'//  Function:   ADsPropCreateNotifyObj
'//
'//  Synopsis:   Checks to see if the notification window/object exists for this
'//              sheet instance and if not creates it.
'//
'//  Arguments:  [pAppThdDataObj] - the unmarshalled data object pointer.
'//              [pwzADsObjName]  - object path name.
'//              [phNotifyObj]    - to return the notificion window handle.
'//
'//  Returns:    HRESULTs.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropCreateNotifyObj IMPORT "DSPROP.DLL" ALIAS "ADsPropCreateNotifyObj" ( _
   BYVAL pAppThdDataObj AS IDataObject _                ' __in  LPDATAOBJECT pAppThdDataObj
 , BYREF pwzADsObjName AS WSTRINGZ _                    ' __in  PWSTR pwzADsObjName
 , BYREF phNotifyObj AS DWORD _                         ' __out HWND* phNotifyObj
 ) AS LONG                                              ' HRESULT

'//+----------------------------------------------------------------------------
'//
'//  Function:   ADsPropGetInitInfo
'//
'//  Synopsis:   Pages call this at their init time to retreive DS object info.
'//
'//  Arguments:  [hNotifyObj]  - the notificion window handle.
'//              [pInitParams] - struct filled in with DS object info. This
'//                              struct must be allocated by the caller before
'//                              the call.
'//
'//  Returns:    FALSE if the notify window has gone away for some reason or
'//              if the parameters are invalid.
'//
'//  Notes:      This call results in the sending of the
'//              WM_ADSPROP_NOTIFY_PAGEINIT message to the notify window.
'//              pInitParams->pWritableAttrs can be NULL if there are no
'//              writable attributes.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropGetInitInfo IMPORT "DSPROP.DLL" ALIAS "ADsPropGetInitInfo" ( _
   BYVAL hNotifyObj AS DWORD _                          ' __in  HWND hNotifyObj
 , BYREF pInitParams AS ADSPROPINITPARAMS _             ' __out PADSPROPINITPARAMS pInitParams
 ) AS LONG                                              ' HRESULT

'//+----------------------------------------------------------------------------
'//
'//  Function:   ADsPropSetHwndWithTitle
'//
'//  Synopsis:   Pages call this at their dialog init time to send their hwnd
'//              to the Notify object.
'//
'//  Arguments:  [hNotifyObj]  - the notificion window handle.
'//              [hPage]       - the page's window handle.
'//              [ptzTitle]    - the page's title
'//
'//  Returns:    FALSE if the notify window has gone away for some reason.
'//
'//  Notes:      Sends the WM_ADSPROP_NOTIFY_PAGEHWND message to the notify
'//              window. Use this function instead of ADsPropSetHwnd for
'//              multi-select property pages
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropSetHwndWithTitle IMPORT "DSPROP.DLL" ALIAS "ADsPropSetHwndWithTitle" ( _
   BYVAL hNotifyObj AS DWORD _                          ' __in  HWND hNotifyObj
 , BYVAL hPage AS DWORD _                               ' __in  HWND hPage
 , BYREF ptzTitle AS WSTRINGZ _                         ' __in  PTSTR ptzTitle
 ) AS LONG                                              ' HRESULT

'//+----------------------------------------------------------------------------
'//
'//  Function:   ADsPropSetHwnd
'//
'//  Synopsis:   Pages call this at their dialog init time to send their hwnd
'//              to the Notify object.
'//
'//  Arguments:  [hNotifyObj]  - the notificion window handle.
'//              [hPage]       - the page's window handle.
'//
'//  Returns:    FALSE if the notify window has gone away for some reason.
'//
'//  Notes:      Sends the WM_ADSPROP_NOTIFY_PAGEHWND message to the notify
'//              window.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropSetHwnd IMPORT "DSPROP.DLL" ALIAS "ADsPropSetHwnd" ( _
   BYVAL hNotifyObj AS DWORD _                          ' __in  HWND hNotifyObj
 , BYVAL hPage AS DWORD _                               ' __in  HWND hPage
 ) AS LONG                                              ' HRESULT

'//+----------------------------------------------------------------------------
'//
'//  function:   ADsPropCheckIfWritable
'//
'//  Synopsis:   See if the attribute is writable by checking if it is in
'//              the allowedAttributesEffective array.
'//
'//  Arguments:  [pwzAttr]        - the attribute name.
'//              [pWritableAttrs] - the array of writable attributes.
'//
'//  Returns:    FALSE if the attribute name is not found in the writable-attrs
'//              array or if the array pointer is NULL.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropCheckIfWritable IMPORT "DSPROP.DLL" ALIAS "ADsPropCheckIfWritable" ( _
   BYREF pwzAttr AS WSTRINGZ _                          ' __in  const PWSTR pwzAttr
 , BYREF pWritableAttrs AS ADS_ATTR_INFO _              ' __in  const PADS_ATTR_INFO pWritableAttrs
 ) AS LONG                                              ' HRESULT

'//+----------------------------------------------------------------------------
'//
'//  function:   ADsPropSendErrorMessage
'//
'//  Synopsis:   Adds an error message to a list which is presented when
'//              ADsPropShowErrorDialog is called
'//
'//  Arguments:  [hNotifyObj]  - the notificion window handle.
'//              [pError]      - the error structure
'//
'//  Returns:    FALSE if the notify window has gone away for some reason.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropSendErrorMessage IMPORT "DSPROP.DLL" ALIAS "ADsPropSendErrorMessage" ( _
   BYVAL hNotifyObj AS DWORD _                          ' __in  HWND hNotifyObj
 , BYREF pError AS ADSPROPERROR _                       ' __out PADSPROPERROR pError
 ) AS LONG                                              ' BOOL

'//+----------------------------------------------------------------------------
'//
'//  function:   ADsPropShowErrorDialog
'//
'//  Synopsis:   Presents an error dialog with the error messages accumulated
'//              through calls to ADsPropSendErrorMessage
'//
'//  Arguments:  [hNotifyObj]  - the notificion window handle.
'//              [hPage]       - the property page window handle.
'//
'//  Returns:    FALSE if the notify window has gone away for some reason.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION ADsPropShowErrorDialog IMPORT "DSPROP.DLL" ALIAS "ADsPropShowErrorDialog" ( _
   BYVAL hNotifyObj AS DWORD _                          ' __in  HWND hNotifyObj
 , BYVAL hPage AS DWORD _                               ' __in  HWND hPage
 ) AS LONG                                              ' BOOL
