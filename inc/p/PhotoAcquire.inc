' ########################################################################################
' Microsoft Windows
' File: PhotoAcquire.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: PhotoAcquireObjects
' Version: 1.0, Locale ID = 0
' Description: PhotoAcquireObjects
' Path: C:\Program Files\Windows Photo Viewer\PhotoAcq.dll
' Library GUID: {00F25AE8-3625-4E34-92D4-F0918CF010EE}
' ########################################################################################

#INCLUDE THIS ONCE
%PHOTOACQUIRE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "shobjidl.inc"

#INCLUDE ONCE "PhotoAcquireProperties.inc"

$LIBID_PhotoAcquireObjects = GUID$("{00F25AE8-3625-4E34-92D4-F0918CF010EE}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {00F29A34-B8A1-482C-BCF8-3AC7B0FE8F62}
$PROGID_PhotoAcquireDeviceSelectionDialog1 = "Microsoft.PhotoAcqDeviceSelectionDlg.1"
' CLSID = {00F20EB5-8FD6-4D9D-B75E-36801766C8F1}
$PROGID_PhotoAcquireAutoPlayDropTarget1 = "Microsoft.PhotoAcqDropTarget.1"
' CLSID = {00F2B433-44E4-4D88-B2B0-2698A0A91DBA}
$PROGID_PhotoAcquireAutoPlayHWEventHandler1 = "Microsoft.PhotoAcqHWEventHandler.1"
' CLSID = {00F210A1-62F0-438B-9F7E-9618D72A1831}
$PROGID_PhotoAcquireOptionsDialog1 = "Microsoft.PhotoAcqOptionsDlg.1"
' CLSID = {00F26E02-E9F2-4A9F-9FDD-5A962FB26A98}
$PROGID_PhotoAcquire1 = "Microsoft.PhotoAcquire.1"
' CLSID = {00F24CA0-748F-4E8A-894F-0E0357C6799F}
$PROGID_PhotoProgressDialog1 = "Microsoft.PhotoProgressDialog.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {00F29A34-B8A1-482C-BCF8-3AC7B0FE8F62}
$PROGID_PhotoAcquireDeviceSelectionDialog = "Microsoft.PhotoAcqDeviceSelectionDlg"
' CLSID = {00F20EB5-8FD6-4D9D-B75E-36801766C8F1}
$PROGID_PhotoAcquireAutoPlayDropTarget = "Microsoft.PhotoAcqDropTarget"
' CLSID = {00F2B433-44E4-4D88-B2B0-2698A0A91DBA}
$PROGID_PhotoAcquireAutoPlayHWEventHandler = "Microsoft.PhotoAcqHWEventHandler"
' CLSID = {00F210A1-62F0-438B-9F7E-9618D72A1831}
$PROGID_PhotoAcquireOptionsDialog = "Microsoft.PhotoAcqOptionsDlg"
' CLSID = {00F26E02-E9F2-4A9F-9FDD-5A962FB26A98}
$PROGID_PhotoAcquire = "Microsoft.PhotoAcquire"
' CLSID = {00F24CA0-748F-4E8A-894F-0E0357C6799F}
$PROGID_PhotoProgressDialog = "Microsoft.PhotoProgressDialog"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_PhotoAcquire = GUID$("{00F26E02-E9F2-4A9F-9FDD-5A962FB26A98}")
$CLSID_PhotoAcquireAutoPlayDropTarget = GUID$("{00F20EB5-8FD6-4D9D-B75E-36801766C8F1}")
$CLSID_PhotoAcquireAutoPlayHWEventHandler = GUID$("{00F2B433-44E4-4D88-B2B0-2698A0A91DBA}")
$CLSID_PhotoAcquireDeviceSelectionDialog = GUID$("{00F29A34-B8A1-482C-BCF8-3AC7B0FE8F62}")
$CLSID_PhotoAcquireOptionsDialog = GUID$("{00F210A1-62F0-438B-9F7E-9618D72A1831}")
$CLSID_PhotoProgressDialog = GUID$("{00F24CA0-748F-4E8A-894F-0E0357C6799F}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IPhotoAcquire = GUID$("{00F23353-E31B-4955-A8AD-CA5EBF31E2CE}")
$IID_IPhotoAcquireDeviceSelectionDialog = GUID$("{00F28837-55DD-4F37-AAF5-6855A9640467}")
$IID_IPhotoAcquireItem = GUID$("{00F21C97-28BF-4C02-B842-5E4E90139A30}")
$IID_IPhotoAcquireOptionsDialog = GUID$("{00F2B3EE-BF64-47EE-89F4-4DEDD79643F2}")
$IID_IPhotoAcquireProgressCB = GUID$("{00F2CE1E-935E-4248-892C-130F32C45CB4}")
$IID_IPhotoAcquireSource = GUID$("{00F2C703-8613-4282-A53B-6EC59C5883AC}")
$IID_IPhotoAcquireSettings = GUID$("{00F2B868-DD67-487C-9553-049240767E91}")
$IID_IPhotoProgressActionCB = GUID$("{00F242D0-B206-4E7D-B4C1-4755BCBB9C9F}")
$IID_IPhotoProgressDialog = GUID$("{00F246F9-0750-4F08-9381-2CD8E906A4AE}")

' ########################################################################################
' Interface name = IPhotoAcquireItem
' IID = {00F21C97-28BF-4C02-B842-5E4E90139A30}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquireItem_INTERFACE_DEFINED)
    %IPhotoAcquireItem_INTERFACE_DEFINED = 1

INTERFACE IPhotoAcquireItem $IID_IPhotoAcquireItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetItemName ( _                               ' VTable offset = 12
     BYREF pbstrItemName AS WSTRING _                   ' __out BSTR *pbstrItemName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnail ( _                              ' VTable offset = 16
     BYVAL sizeThumbnail AS SIZE _                      ' __in SIZE sizeThumbnail
   , BYREF phbmpThumbnail AS DWORD _                    ' __out HBITMAP *phbmpThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY *key
   , BYREF pv AS PROPVARIANT _                          ' __out PROPVARIANT *pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY *key
   , BYREF pv AS PROPVARIANT _                          ' __in const PROPVARIANT *pv *pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 28
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanDelete ( _                                 ' VTable offset = 32
     BYREF pfCanDelete AS LONG _                        ' __out BOOL *pfCanDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubItemCount ( _                           ' VTable offset = 40
     BYREF pnCount AS DWORD _                           ' __out UINT* pnCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubItemAt ( _                              ' VTable offset = 44
     BYVAL nItemIndex AS DWORD _                        ' __in UINT nItemIndex
   , BYREF ppPhotoAcquireItem AS IPhotoAcquireItem _    ' __out IPhotoAcquireItem **ppPhotoAcquireItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquireItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUserInputString
' IID = 00f243a1-205b-45ba-ae26-abbc53aa7a6f
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUserInputString_INTERFACE_DEFINED)
    %IUserInputString_INTERFACE_DEFINED = 1

' enum USER_INPUT_STRING_TYPE
%USER_INPUT_DEFAULT      = 0
%USER_INPUT_PATH_ELEMENT = &H1

$IID_IUserInputString = GUID$("{00f243a1-205b-45ba-ae26-abbc53aa7a6f}")

INTERFACE IUserInputString $IID_IUserInputString

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSubmitButtonText ( _                       ' VTable offset = 12
     BYREF pbstrSubmitButtonText AS WSTRING _           ' __out BSTR *pbstrSubmitButtonText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrompt ( _                                 ' VTable offset = 16
     BYREF pbstrPromptTitle AS WSTRING _                ' __out BSTR *pbstrPromptTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringId ( _                               ' VTable offset = 20
     BYREF pbstrStringId AS WSTRING _                   ' __out BSTR *pbstrStringId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringType ( _                             ' VTable offset = 24
     BYREF pnStringType AS LONG _                       ' __out USER_INPUT_STRING_TYPE *pnStringType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTooltipText ( _                            ' VTable offset = 28
     BYREF pbstrTooltipText AS WSTRING _                ' __out BSTR *pbstrTooltipText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxLength ( _                              ' VTable offset = 32
     BYREF pcchMaxLength AS DWORD _                     ' __out UINT *pcchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefault ( _                                ' VTable offset = 36
     BYREF pbstrDefault AS WSTRING _                    ' __out BSTR *pbstrDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMruCount ( _                               ' VTable offset = 40
     BYREF pnMruCount AS DWORD _                        ' __out UINT *pnMruCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMruEntryAt ( _                             ' VTable offset = 44
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF pbstrMruEntry AS WSTRING _                   ' __out BSTR *pbstrMruEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImage ( _                                  ' VTable offset = 48
     BYVAL nSize AS DWORD _                             ' __in UINT nSize
   , BYREF phBitmap AS DWORD _                          ' __inout HBITMAP *phBitmap
   , BYREF phIcon AS DWORD _                            ' __inout HICON *phIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUserInputString_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPhotoAcquireProgressCB
' IID = {00F2CE1E-935E-4248-892C-130F32C45CB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquireProgressCB_INTERFACE_DEFINED)
    %IPhotoAcquireProgressCB_INTERFACE_DEFINED = 1

' enum ERROR_ADVISE_MESSAGE_TYPE
%PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL = 0
%PHOTOACQUIRE_ERROR_RETRYCANCEL     = 1
%PHOTOACQUIRE_ERROR_YESNO           = 2
%PHOTOACQUIRE_ERROR_OK              = 3

' enum ERROR_ADVISE_RESULT
%PHOTOACQUIRE_RESULT_YES            = 0
%PHOTOACQUIRE_RESULT_NO             = 1
%PHOTOACQUIRE_RESULT_OK             = 2
%PHOTOACQUIRE_RESULT_SKIP           = 3
%PHOTOACQUIRE_RESULT_SKIP_ALL       = 4
%PHOTOACQUIRE_RESULT_RETRY          = 5
%PHOTOACQUIRE_RESULT_ABORT          = 6

INTERFACE IPhotoAcquireProgressCB $IID_IPhotoAcquireProgressCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancelled ( _                                 ' VTable offset = 12
     BYREF pfCancelled AS LONG _                        ' __out BOOL *pfCancelled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartEnumeration ( _                          ' VTable offset = 16
     BYVAL pPhotoAcquireSource AS IPhotoAcquireSource _ ' __in IPhotoAcquireSource *pPhotoAcquireSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FoundItem ( _                                 ' VTable offset = 20
     BYVAL pPhotoAcquireItem AS IPhotoAcquireItem _     ' __in IPhotoAcquireItem *pPhotoAcquireItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndEnumeration ( _                            ' VTable offset = 24
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartTransfer ( _                             ' VTable offset = 28
     BYVAL pPhotoAcquireSource AS IPhotoAcquireSource _ ' __in IPhotoAcquireSource *pPhotoAcquireSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartItemTransfer ( _                         ' VTable offset = 32
     BYVAL nItemIndex AS DWORD _                        ' __in UINT nItemIndex
   , BYVAL pPhotoAcquireItem AS IPhotoAcquireItem _     ' __in IPhotoAcquireItem *pPhotoAcquireItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DirectoryCreated ( _                          ' VTable offset = 36
     BYREF pszDirectory AS WSTRINGZ _                   ' __in LPCWSTR pszDirectory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTransferPercent ( _                     ' VTable offset = 40
     BYVAL fOverall AS LONG _                           ' __in BOOL fOverall
   , BYVAL nPercent AS DWORD _                          ' __in UINT nPercent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndItemTransfer ( _                           ' VTable offset = 44
     BYVAL nItemIndex AS DWORD _                        ' __in UINT nItemIndex
   , BYVAL pPhotoAcquireItem AS IPhotoAcquireItem _     ' __in IPhotoAcquireItem *pPhotoAcquireItem
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndTransfer ( _                               ' VTable offset = 48
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartDelete ( _                               ' VTable offset = 52
     BYVAL pPhotoAcquireSource AS IPhotoAcquireSource _ ' __in IPhotoAcquireSource *pPhotoAcquireSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartItemDelete ( _                           ' VTable offset = 56
     BYVAL nItemIndex AS DWORD _                        ' __in UINT nItemIndex
   , BYVAL pPhotoAcquireItem AS IPhotoAcquireItem _     ' __in IPhotoAcquireItem *pPhotoAcquireItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateDeletePercent ( _                       ' VTable offset = 60
     BYVAL nPercent AS DWORD _                          ' __in UINT nPercent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndItemDelete ( _                             ' VTable offset = 64
     BYVAL nItemIndex AS DWORD _                        ' __in UINT nItemIndex
   , BYVAL pPhotoAcquireItem AS IPhotoAcquireItem _     ' __in IPhotoAcquireItem *pPhotoAcquireItem
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndDelete ( _                                 ' VTable offset = 68
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndSession ( _                                ' VTable offset = 72
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeleteAfterAcquire ( _                     ' VTable offset = 76
     BYREF pfDeleteAfterAcquire AS LONG _               ' __out BOOL *pfDeleteAfterAcquire
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ErrorAdvise ( _                               ' VTable offset = 80
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYREF pszErrorMessage AS WSTRINGZ _                ' __in LPCWSTR pszErrorMessage
   , BYVAL nMessageType AS LONG _                       ' __in ERROR_ADVISE_MESSAGE_TYPE nMessageType
   , BYREF pnErrorAdviseResult AS LONG _                ' __out ERROR_ADVISE_RESULT *pnErrorAdviseResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserInput ( _                              ' VTable offset = 84
     BYREF riidType AS GUID _                           ' __in REFIID *riidType
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown VT_UNKNOWN
   , BYREF pPropVarResult AS PROPVARIANT _              ' __out PROPVARIANT *pPropVarResult
   , BYREF pPropVarDefault AS PROPVARIANT _             ' __in const PROPVARIANT *pPropVarDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquireProgressCB_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPhotoProgressActionCB
' IID = {00F242D0-B206-4E7D-B4C1-4755BCBB9C9F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoProgressActionCB_INTERFACE_DEFINED)
    %IPhotoProgressActionCB_INTERFACE_DEFINED = 1

INTERFACE IPhotoProgressActionCB $IID_IPhotoProgressActionCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DoAction ( _                                  ' VTable offset = 12
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoProgressActionCB_INTERFACE_DEFINED__ */


%PROGRESS_INDETERMINATE = -1


' ########################################################################################
' Interface name = IPhotoProgressDialog
' IID = {00F246F9-0750-4F08-9381-2CD8E906A4AE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoProgressDialog_INTERFACE_DEFINED)
    %IPhotoProgressDialog_INTERFACE_DEFINED = 1

' enum PROGRESS_DIALOG_IMAGE_TYPE
%PROGRESS_DIALOG_ICON_SMALL          = 0
%PROGRESS_DIALOG_ICON_LARGE          = &H1
%PROGRESS_DIALOG_ICON_THUMBNAIL      = &H2
%PROGRESS_DIALOG_BITMAP_THUMBNAIL    = &H3

' enum PROGRESS_DIALOG_CHECKBOX_ID
%PROGRESS_DIALOG_CHECKBOX_ID_DEFAULT = 0

INTERFACE IPhotoProgressDialog $IID_IPhotoProgressDialog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 16
     BYREF phwndProgressDialog AS DWORD _               ' __out HWND *phwndProgressDialog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 24
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowCheckbox ( _                              ' VTable offset = 28
     BYVAL nCheckboxId AS LONG _                        ' __in PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId
   , BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckboxText ( _                           ' VTable offset = 32
     BYVAL nCheckboxId AS LONG _                        ' __in PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId
   , BYREF pszCheckboxText AS WSTRINGZ _                ' __in LPCWSTR pszCheckboxText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckboxCheck ( _                          ' VTable offset = 36
     BYVAL nCheckboxId AS LONG _                        ' __in PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId
   , BYVAL fChecked AS LONG _                           ' __in BOOL fChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckboxTooltip ( _                        ' VTable offset = 40
     BYVAL nCheckboxId AS LONG _                        ' __in PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId
   , BYREF pszCheckboxTooltipText AS WSTRINGZ _         ' __in LPCWSTR pszCheckboxTooltipText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCheckboxChecked ( _                         ' VTable offset = 44
     BYVAL nCheckboxId AS LONG _                        ' __in PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId
   , BYREF pfChecked AS LONG _                          ' __out BOOL *pfChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCaption ( _                                ' VTable offset = 48
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImage ( _                                  ' VTable offset = 52
     BYVAL nImageType AS LONG _                         ' __in PROGRESS_DIALOG_IMAGE_TYPE nImageType
   , BYVAL hIcon AS DWORD _                             ' __in HWND hIcon
   , BYVAL hBitmap AS DWORD _                           ' __in HBITMAP hBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPercentComplete ( _                        ' VTable offset = 56
     BYVAL nPercent AS LONG _                           ' __in int nPercent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressText ( _                           ' VTable offset = 60
     BYREF pszProgressText AS WSTRINGZ _                ' __in LPCWSTR pszProgressText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionLinkCallback ( _                     ' VTable offset = 64
     BYVAL pPhotoProgressActionCB AS IPhotoProgressActionCB _ ' __in IPhotoProgressActionCB *pPhotoProgressActionCB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionLinkText ( _                         ' VTable offset = 68
     BYREF pszCaption AS WSTRINGZ _                     ' __in LPCWSTR pszCaption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowActionLink ( _                            ' VTable offset = 72
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCancelled ( _                               ' VTable offset = 76
     BYREF pfCancelled AS LONG _                        ' __out BOOL *pfCancelled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserInput ( _                              ' VTable offset = 80
     BYREF riidType AS GUID _                           ' __in REFIID *riidType
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   , BYREF pPropVarResult AS PROPVARIANT _              ' __out PROPVARIANT *pPropVarResult
   , BYREF pPropVarDefault AS PROPVARIANT _             ' __in PROPVARIANT *pPropVarDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoProgressDialog_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPhotoAcquireSource
' IID = {00F2C703-8613-4282-A53B-6EC59C5883AC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquireSource_INTERFACE_DEFINED)
    %IPhotoAcquireSource_INTERFACE_DEFINED = 1

INTERFACE IPhotoAcquireSource $IID_IPhotoAcquireSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 12
     BYREF pbstrFriendlyName AS WSTRING _               ' __out BSTR *pbstrFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIcons ( _                            ' VTable offset = 16
     BYVAL nSize AS DWORD _                             ' __in UINT nSize
   , BYREF phLargeIcon AS DWORD _                       ' __inout HICON *phLargeIcon
   , BYREF phSmallIcon AS DWORD _                       ' __inout HICON *phSmallIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeItemList ( _                        ' VTable offset = 20
     BYVAL fForceEnumeration AS LONG _                  ' __in BOOL fForceEnumeration
   , BYVAL pPhotoAcquireProgressCB AS IPhotoAcquireProgressCB _ ' __in IPhotoAcquireProgressCB *pPhotoAcquireProgressCB
   , BYREF pnItemCount AS DWORD _                       ' __inout UINT *pnItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemCount ( _                              ' VTable offset = 24
     BYREF pnItemCount AS DWORD _                       ' __out UINT *pnItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemAt ( _                                 ' VTable offset = 28
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppPhotoAcquireItem AS IPhotoAcquireItem _    ' __out IPhotoAcquireItem **ppPhotoAcquireItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPhotoAcquireSettings ( _                   ' VTable offset = 32
     BYREF ppPhotoAcquireSettings AS IPhotoAcquireSettings _ ' __out IPhotoAcquireSettings **ppPhotoAcquireSettings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceId ( _                               ' VTable offset = 36
     BYREF pbstrDeviceId AS WSTRING _                   ' __out BSTR *pbstrDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 40
     BYREF riid AS GUID _                               ' __in REFIID *riid GUID <record>
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquireSource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPhotoAcquire
' IID = {00F23353-E31B-4955-A8AD-CA5EBF31E2CE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquire_INTERFACE_DEFINED)
    %IPhotoAcquire_INTERFACE_DEFINED = 1

INTERFACE IPhotoAcquire $IID_IPhotoAcquire

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePhotoSource ( _                         ' VTable offset = 12
     BYVAL pszDevice AS DWORD _                         ' __in v pszDevice
   , BYREF ppPhotoAcquireSource AS IPhotoAcquireSource _ ' __out IPhotoAcquireSource **ppPhotoAcquireSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 16
     BYVAL pPhotoAcquireSource AS IPhotoAcquireSource _ ' __in IPhotoAcquireSource *pPhotoAcquireSource
   , BYVAL fShowProgress AS LONG _                      ' __in BOOL fShowProgress
   , BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYREF pszApplicationName AS WSTRINGZ _             ' __in LPCWSTR pszApplicationName
   , BYVAL pPhotoAcquireProgressCB AS IPhotoAcquireProgressCB _ ' __in IPhotoAcquireProgressCB *pPhotoAcquireProgressCB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumResults ( _                               ' VTable offset = 20
     BYREF ppEnumFilePaths AS IEnumString _             ' __out IEnumString **ppEnumFilePaths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquire_INTERFACE_DEFINED__ */


'// IPhotoAcquire::Acquire will return this value if a user operation requires a restart.
'// If you receive this you should discard all interfaces and restart completely.
'// You can only receive this if you specify the PHOTOACQ_ABORT_ON_SETTINGS_UPDATE flag.
'#define PHOTOACQ_ERROR_RESTART_REQUIRED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA001)
%PHOTOACQ_ERROR_RESTART_REQUIRED           = &HFFFFA001???
%PHOTOACQ_RUN_DEFAULT                      = &H00000000???

'// Acquisition flags
'// In versions of Windows that don't include Windows Photo Gallery
'// PHOTOACQ_NO_GALLERY_LAUNCH suppresses the explorer window launched after acquisition.
'// In versions of Windows that don't include Windows Photo Gallery
'// PHOTOACQ_DISABLE_DB_INTEGRATION and PHOTOACQ_DISABLE_DUPLICATE_DETECTION are implied.

%PHOTOACQ_NO_GALLERY_LAUNCH                = &H00000001???
%PHOTOACQ_DISABLE_AUTO_ROTATE              = &H00000002???
%PHOTOACQ_DISABLE_PLUGINS                  = &H00000004???
%PHOTOACQ_DISABLE_GROUP_TAG_PROMPT         = &H00000008???
%PHOTOACQ_DISABLE_DB_INTEGRATION           = &H00000010???
%PHOTOACQ_DELETE_AFTER_ACQUIRE             = &H00000020???
%PHOTOACQ_DISABLE_DUPLICATE_DETECTION      = &H00000040???
%PHOTOACQ_ENABLE_THUMBNAIL_CACHING         = &H00000080???
%PHOTOACQ_DISABLE_METADATA_WRITE           = &H00000100???
%PHOTOACQ_DISABLE_THUMBNAIL_PROGRESS       = &H00000200???
%PHOTOACQ_DISABLE_SETTINGS_LINK            = &H00000400???
%PHOTOACQ_ABORT_ON_SETTINGS_UPDATE         = &H00000800???


' ########################################################################################
' Interface name = IPhotoAcquireSettings
' IID = {00F2B868-DD67-487C-9553-049240767E91}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquireSettings_INTERFACE_DEFINED)
    %IPhotoAcquireSettings_INTERFACE_DEFINED = 1

INTERFACE IPhotoAcquireSettings $IID_IPhotoAcquireSettings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeFromRegistry ( _                    ' VTable offset = 12
     BYREF pszRegistryKey AS WSTRINGZ _                 ' __in LPCWSTR pszRegistryKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 16
     BYVAL dwPhotoAcquireFlags AS DWORD _               ' __in DWORD dwPhotoAcquireFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputFilenameTemplate ( _                 ' VTable offset = 20
     BYREF pszTemplate AS WSTRINGZ _                    ' __in LPCWSTR pszTemplate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSequencePaddingWidth ( _                   ' VTable offset = 24
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSequenceZeroPadding ( _                    ' VTable offset = 28
     BYVAL fZeroPad AS LONG _                           ' __in BOOL fZeroPad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGroupTag ( _                               ' VTable offset = 32
     BYREF pszGroupTag AS WSTRINGZ _                    ' __in LPCWSTR pszGroupTag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAcquisitionTime ( _                        ' VTable offset = 36
     BYREF pftAcquisitionTime AS FILETIME _             ' __in FILETIME *pftAcquisitionTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 40
     BYREF pdwPhotoAcquireFlags AS DWORD _              ' __out DWORD *pdwPhotoAcquireFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFilenameTemplate ( _                 ' VTable offset = 44
     BYREF pbstrTemplate AS WSTRING _                   ' __out BSTR *pbstrTemplate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSequencePaddingWidth ( _                   ' VTable offset = 48
     BYREF pdwWidth AS DWORD _                          ' __out DWORD *pdwWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSequenceZeroPadding ( _                    ' VTable offset = 52
     BYREF pfZeroPad AS LONG _                          ' __out BOOL *pfZeroPad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupTag ( _                               ' VTable offset = 56
     BYREF pbstrGroupTag AS WSTRING _                   ' __out BSTR *pbstrGroupTag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAcquisitionTime ( _                        ' VTable offset = 60
     BYREF pftAcquisitionTime AS FILETIME _             ' __out FILETIME *pftAcquisitionTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquireSettings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPhotoAcquireOptionsDialog
' IID = {00F2B3EE-BF64-47EE-89F4-4DEDD79643F2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquireOptionsDialog_INTERFACE_DEFINED)
    %IPhotoAcquireOptionsDialog_INTERFACE_DEFINED = 1

INTERFACE IPhotoAcquireOptionsDialog $IID_IPhotoAcquireOptionsDialog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszRegistryRoot AS WSTRINGZ _                ' __in LPCWSTR pszRegistryRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 16
     BYVAL hWndParent AS DWORD _                        ' __in HEND hWndParent
   , BYREF phWndDialog AS DWORD _                       ' __out HEND *phWndDialog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoModal ( _                                   ' VTable offset = 24
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYREF ppnReturnCode AS DWORD _                     ' __inout INT_PTR *ppnReturnCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveData ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquireOptionsDialog_INTERFACE_DEFINED__ */


%DSF_WPD_DEVICES    = &H00000001???
%DSF_WIA_CAMERAS    = &H00000002???
%DSF_WIA_SCANNERS   = &H00000004???
%DSF_STI_DEVICES    = &H00000008???
%DSF_TWAIN_DEVICES  = &H00000010???
%DSF_FS_DEVICES     = &H00000020???
%DSF_DV_DEVICES     = &H00000040???
%DSF_ALL_DEVICES    = &H0000FFFF???
%DSF_CPL_MODE       = &H00010000???
%DSF_SHOW_OFFLINE   = &H00020000???

' ########################################################################################
' Interface name = IPhotoAcquireDeviceSelectionDialog
' IID = {00F28837-55DD-4F37-AAF5-6855A9640467}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquireDeviceSelectionDialog_INTERFACE_DEFINED)
    %IPhotoAcquireDeviceSelectionDialog_INTERFACE_DEFINED = 1

' enum DEVICE_SELECTION_DEVICE_TYPE
%DST_UNKNOWN_DEVICE = 0
%DST_WPD_DEVICE     = &H1
%DST_WIA_DEVICE     = &H2
%DST_STI_DEVICE     = &H3
%DSF_TWAIN_DEVICE   = &H4
%DST_FS_DEVICE      = &H5
%DST_DV_DEVICE      = &H6


INTERFACE IPhotoAcquireDeviceSelectionDialog $IID_IPhotoAcquireDeviceSelectionDialog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 12
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubmitButtonText ( _                       ' VTable offset = 16
     BYREF pszSubmitButtonText AS WSTRINGZ _            ' __in LPCWSTR pszSubmitButtonText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoModal ( _                                   ' VTable offset = 20
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYVAL dwDeviceFlags AS DWORD _                     ' __in DWORD dwDeviceFlags
   , BYREF pbstrDeviceId AS WSTRING _                   ' __inout BSTR *pbstrDeviceId
   , BYREF pnDeviceType AS LONG _                       ' __inout DEVICE_SELECTION_DEVICE_TYPE *pnDeviceType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquireDeviceSelectionDialog_INTERFACE_DEFINED__ */

%PAPS_PRESAVE   = &H00000000???
%PAPS_POSTSAVE  = &H00000001???
%PAPS_CLEANUP   = &H00000002???

' ########################################################################################
' Interface name = IPhotoAcquirePlugin
' IID = 00f2dceb-ecb8-4f77-8e47-e7a987c83dd0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPhotoAcquirePlugin_INTERFACE_DEFINED)
    %IPhotoAcquirePlugin_INTERFACE_DEFINED = 1

$IID_IPhotoAcquirePlugin = GUID$("{00f2dceb-ecb8-4f77-8e47-e7a987c83dd0}")

INTERFACE IPhotoAcquirePlugin $IID_IPhotoAcquirePlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     OPTIONAL BYVAL pPhotoAcquireSource AS IPhotoAcquireSource _ ' __in_opt IPhotoAcquireSource *pPhotoAcquireSource
   , OPTIONAL BYVAL pPhotoAcquireProgressCB AS IPhotoAcquireProgressCB _ ' __in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessItem ( _                               ' VTable offset = 16
     BYVAL dwAcquireStage AS DWORD _                    ' __in DWORD dwAcquireStage
   , BYVAL pPhotoAcquireItem AS IPhotoAcquireItem _     ' __in_opt IPhotoAcquireItem *pPhotoAcquireItem
   , BYVAL pOriginalItemStream AS IStream _             ' __in_opt IStream *pOriginalItemStream
   , BYREF pszFinalFilename AS WSTRINGZ _               ' __in LPCWSTR pszFinalFilename
   , OPTIONAL BYVAL pPropertyStore AS IPropertyStore _  ' __in_opt IPropertyStore *pPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransferComplete ( _                          ' VTable offset = 20
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayConfigureDialog ( _                    ' VTable offset = 24
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPhotoAcquirePlugin_INTERFACE_DEFINED__ */
