' ########################################################################################
' Microsoft Windows
' File: MAPIHook.inc
' Contents: Defines the SpoolerMsgHook provider interface.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIHOOK_INC = 1

#INCLUDE ONCE "mapiguid.inc"
#INCLUDE ONCE "mapidefs.inc
#INCLUDE ONCE "mapicode.inc
#INCLUDE ONCE "mapitags.inc

'/* ISpoolerHook Interface ------------------------------------------------ */

'/* MsgHooks */

%HOOK_DELETE         = &H00000001???
%HOOK_CANCEL         = &H00000002???

' ========================================================================================
' ISpoolerHook interface
' $IID_ISpoolerHook = GUID$("{00020320-0000-0000-C000-000000000046}")
' The ISpoolerHook interface enables a messaging hook provider to process messages before
' they go to their destination. This processing can include modifying the message,
' changing the list of recipients, saving a copy of the message elsewhere, and so on.
' ========================================================================================

INTERFACE ISpoolerHook $IID_ISpoolerHook

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InboundMsgHook ( _                            ' VTable offset = 12
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYVAL lpFolder AS IMAPIFolder _                    ' __in LPMAPIFOLDER lpFolder
   , BYVAL lpMDB AS IMsgStore _                         ' __in LPMDB lpMDB
   , BYREF lpulFlags AS DWORD _                         ' __out ULONG FAR * lpulFlags
   , BYREF lpcbEntryID AS DWORD _                       ' __in_out ULONG FAR * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __in_out LPBYTE FAR * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OutboundMsgHook ( _                           ' VTable offset = 16
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYVAL lpFolder AS IMAPIFolder _                    ' __in LPMAPIFOLDER lpFolder
   , BYVAL lpMDB AS IMsgStore _                         ' __in LPMDB lpMDB
   , BYREF lpulFlags AS DWORD _                         ' __out ULONG FAR * lpulFlags
   , BYREF lpcbEntryID AS DWORD _                       ' __in_out ULONG FAR * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __in_out LPBYTE FAR * lppEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'/* Hook Provider Entry Point */

%HOOK_INBOUND        = &H00000200???
%HOOK_OUTBOUND       = &H00000400???

'typedef HRESULT (STDMAPIINITCALLTYPE HPPROVIDERINIT)(
'    LPMAPISESSION           lpSession,
'    HINSTANCE               hInstance,
'    LPALLOCATEBUFFER        lpAllocateBuffer,
'    LPALLOCATEMORE          lpAllocateMore,
'    LPFREEBUFFER            lpFreeBuffer,
'    LPMAPIUID               lpSectionUID,
'    ULONG                   ulFlags,
'    LPSPOOLERHOOK FAR *     lppSpoolerHook
');

' Note: This is a prorotype for a function that you have to implement.
'FUNCTION HPProviderInit ( _
'   BYVAL lpSession AS IUnknown _                      ' __in LPMAPISESSION lpSession
' , BYVAL hInstance AS DWORD _                         ' __in HINSTANCE hInstance
' , BYVAL lpAllocateBuffer AS DWORD _                  ' __in LPALLOCATEBUFFER lpAllocateBuffer
' , BYVAL lpAllocateMore AS DWORD _                    ' __in LPALLOCATEMORE lpAllocateMore
' , BYVAL lpFreeBuffer AS DWORD _                      ' __in LPFREEBUFFER lpFreeBuffer
' , BYVAL lpSectionUID AS DWORD _                      ' __in LPMAPIUID lpSectionUID
' , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
' , BYREF lppSpoolerHook AS IUnknown _                 ' __out LPSPOOLERHOOK FAR * lppSpoolerHook
'   ) AS LONG                                          ' HRESULT
