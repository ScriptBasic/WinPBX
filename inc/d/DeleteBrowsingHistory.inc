' ########################################################################################
' Microsoft Windows
' File: DeleteBrowsingHistory.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DELETEBROWSINGHISTORY_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

'// {31caf6e4-d6aa-4090-a050-a5ac8972e9ef}
'DEFINE_GUID( CATID_DeleteBrowsingHistory, 0x31caf6e4,0xd6aa,0x4090,0xa0,0x50,0xa5,0xac,0x89,0x72,0xe9,0xef);
'EXTERN_C const GUID CATID_DeleteBrowsingHistory;
$CATID_DeleteBrowsingHistory = GUID$("{31caf6e4-d6aa-4090-a050-a5ac8972e9ef}")

%DELETE_BROWSING_HISTORY_HISTORY              = &H0001???   ' // Indicates that the History checkbox was selected.
%DELETE_BROWSING_HISTORY_COOKIES              = &H0002???   ' // Indicates that the Cookies checkbox was selected.
%DELETE_BROWSING_HISTORY_TIF                  = &H0004???   ' // Indicates that the Temporary Internet Files checkbox was selected.
%DELETE_BROWSING_HISTORY_FORMDATA             = &H0008???   ' // Indicates that the Form data checkbox was selected.
%DELETE_BROWSING_HISTORY_PASSWORDS            = &H0010???   ' // Indicates that the Passwords checkbox was selected.
%DELETE_BROWSING_HISTORY_PRESERVEFAVORITES    = &H0020???   ' // Indicates that the Preseve Favorite website data checkbox is selected.


#IF NOT %DEF(%IDeleteBrowsingHistory_INTERFACE_DEFINED)
    %IDeleteBrowsingHistory_INTERFACE_DEFINED = 1

$IID_IDeleteBrowsingHistory = GUID$("{cf38ed4b-2be7-4461-8b5e-9a466dc82ae3}")

INTERFACE IDeleteBrowsingHistory $IID_IDeleteBrowsingHistory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeleteBrowsingHistory ( _                     ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeleteBrowsingHistory_INTERFACE_DEFINED__ */
