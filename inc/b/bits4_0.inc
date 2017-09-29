' ########################################################################################
' Microsoft Windows
' File: Bits4_0.inc
' Library name: BackgroundCopyManager4_0
' Version: 1.0, Locale ID = 0
' Library GUID: {BB6DF56A-CACE-11DC-9992-0019B93A3A84}
' Contents: Microsoft Background Copy Manager 4.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITS4_0_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "bits.inc"
#INCLUDE ONCE "bits1_5.inc"
#INCLUDE ONCE "bits2_0.inc"
#INCLUDE ONCE "bits2_5.inc"
#INCLUDE ONCE "bits3_0.inc"

$CLSID_BackgroundCopyManager4_0 = GUID$("{BB6DF56B-CACE-11DC-9992-0019B93A3A84}")

' ########################################################################################
' IBitsTokenOptions interface
' IID = 9A2584C3-F7D2-457A-9A5E-22B67BFFC7D2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBitsTokenOptions_INTERFACE_DEFINED)
    %IBitsTokenOptions_INTERFACE_DEFINED = 1

%BG_TOKEN_LOCAL_FILE = &H0001???
%BG_TOKEN_NETWORK    = &H0002???

$IID_IBitsTokenOptions = GUID$("{9A2584C3-F7D2-457A-9A5E-22B67BFFC7D2}")

INTERFACE IBitsTokenOptions $IID_IBitsTokenOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHelperTokenFlags ( _                       ' VTable offset = 12
     BYVAL UsageFlags AS DWORD _                        ' __in DWORD UsageFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelperTokenFlags ( _                       ' VTable offset = 16
     BYREF pFlags AS DWORD _                            ' __out DWORD *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelperToken ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearHelperToken ( _                          ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelperTokenSid ( _                         ' VTable offset = 28
     BYREF pSid AS DWORD _                              ' __out LPWSTR *pSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBitsTokenOptions_INTERFACE_DEFINED__ */


' ########################################################################################
' IBackgroundCopyFile4 interface
' IID = EF7E0655-7888-4960-B0E5-730846E03492
' Inherited interface = IBackgroundCopyFile3
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyFile4_INTERFACE_DEFINED)
    %IBackgroundCopyFile4_INTERFACE_DEFINED = 1

$IID_IBackgroundCopyFile4 = GUID$("{EF7E0655-7888-4960-B0E5-730846E03492}")

INTERFACE IBackgroundCopyFile4 $IID_IBackgroundCopyFile4

   INHERIT IUnknown

   ' =====================================================================================
   ' IBackgroundCopyFile3 methods
   ' =====================================================================================
   METHOD SetHelperTokenFlags ( _                       ' VTable offset = 12
     BYVAL UsageFlags AS DWORD _                        ' __in DWORD UsageFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelperTokenFlags ( _                       ' VTable offset = 16
     BYREF pFlags AS DWORD _                            ' __out DWORD *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelperToken ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearHelperToken ( _                          ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelperTokenSid ( _                         ' VTable offset = 28
     BYREF pSid AS DWORD _                              ' __out LPWSTR *pSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBackgroundCopyFile4 method
   ' =====================================================================================
   METHOD GetPeerDownloadStats ( _                      ' VTable offset = 32
     BYREF pFromOrigin AS QUAD _                        ' __out PUINT64 pFromOrigin
   , BYREF pFromPeers AS QUAD _                         ' __out PUINT64 pFromPeers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyFile4_INTERFACE_DEFINED__ */
