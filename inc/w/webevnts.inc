' ########################################################################################
' Microsoft Windows
' File: webevnts.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WEBEVNTS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"

' ########################################################################################
' IWebBrowserEventsService interface
' IID = 54A8F188-9EBD-4795-AD16-9B4945119636
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWebBrowserEventsService_INTERFACE_DEFINED)
    %IWebBrowserEventsService_INTERFACE_DEFINED = 1

$IID_IWebBrowserEventsService = GUID$("{54A8F188-9EBD-4795-AD16-9B4945119636}")

INTERFACE IWebBrowserEventsService $IID_IWebBrowserEventsService

   INHERIT IAutomation

   ' =====================================================================================
   METHOD FireBeforeNavigate2Event ( _                  ' VTable offset = 12
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCancel
   ' =====================================================================================
   METHOD FireDownloadBeginEvent ( _                    ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD FireDownloadCompleteEvent ( _                 ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD FireDocumentCompleteEvent ( _                 ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebBrowserEventsService_INTERFACE_DEFINED__ */


' ########################################################################################
' IWebBrowserEventsUrlService interface
' IID = 87CC5D04-EAFA-4833-9820-8F986530CC00
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWebBrowserEventsUrlService_INTERFACE_DEFINED)
    %IWebBrowserEventsUrlService_INTERFACE_DEFINED = 1

$IID_IWebBrowserEventsUrlService = GUID$("{87CC5D04-EAFA-4833-9820-8F986530CC00}")

INTERFACE IWebBrowserEventsUrlService $IID_IWebBrowserEventsUrlService

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetUrlForEvents ( _                           ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pUrl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebBrowserEventsUrlService_INTERFACE_DEFINED__ */
