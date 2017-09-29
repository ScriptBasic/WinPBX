' ########################################################################################
' Microsoft Windows
' File: ChanMgr.inc
' Library name: CHANNELMGR
' Version: 1.0, Locale ID = 0
' Library GUID: {4804F2E0-D16E-11D0-802B-00C04FD75D13}
' Contents: Microsoft Channel Manager 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CHANMGR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

$CLSID_ChannelMgr = GUID$("{B3CDAE90-D170-11D0-802B-00C04FD75D13}")

' ########################################################################################
' Interface name = IChannelMgr
' IID = 85BD8E82-0FBA-11D1-90C3-00C04FC2F568
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IChannelMgr_INTERFACE_DEFINED)
    %IChannelMgr_INTERFACE_DEFINED = 1

' // Size = 28 bytes
TYPE CHANNELSHORTCUTINFO DWORD
   cbSize      AS DWORD          ' DWORD
   pszTitle    AS WSTRINGZ PTR   ' LPWSTR
   pszURL      AS WSTRINGZ PTR   ' LPWSTR
   pszLogo     AS WSTRINGZ PTR   ' LPWSTR
   pszIcon     AS WSTRINGZ PTR   ' LPWSTR
   pszWideLogo AS WSTRINGZ PTR   ' LPWSTR
   bIsSoftware AS LONG           ' BOOL
END TYPE

' // Size = 24 bytes
TYPE CHANNELCATEGORYINFO DWORD
   cbSize      AS DWORD          ' DWORD
   pszTitle    AS WSTRINGZ PTR   ' LPWSTR
   pszURL      AS WSTRINGZ PTR   ' LPWSTR
   pszLogo     AS WSTRINGZ PTR   ' LPWSTR
   pszIcon     AS WSTRINGZ PTR   ' LPWSTR
   pszWideLogo AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' enum CHANNELENUMFLAGS
%CHANENUM_CHANNELFOLDER    = &H1???
%CHANENUM_SOFTUPDATEFOLDER = &H2???
%CHANENUM_DESKTOPFOLDER    = &H4???
%CHANENUM_TITLE            = &H10000???
%CHANENUM_PATH             = &H20000???
%CHANENUM_URL              = &H40000???
%CHANENUM_SUBSCRIBESTATE   = &H80000???

%CHANENUM_ALLFOLDERS = %CHANENUM_CHANNELFOLDER OR _
                       %CHANENUM_SOFTUPDATEFOLDER OR _
                       %CHANENUM_DESKTOPFOLDER

%CHANENUM_ALLDATA    = %CHANENUM_TITLE OR _
                       %CHANENUM_PATH OR _
                       %CHANENUM_URL OR _
                       %CHANENUM_SUBSCRIBESTATE

%CHANENUM_ALL        = %CHANENUM_CHANNELFOLDER OR _
                       %CHANENUM_SOFTUPDATEFOLDER OR _
                       %CHANENUM_DESKTOPFOLDER OR _
                       %CHANENUM_TITLE OR _
                       %CHANENUM_PATH OR _
                       %CHANENUM_URL OR _
                       %CHANENUM_SUBSCRIBESTATE


$IID_IChannelMgr = GUID$("{85BD8E82-0FBA-11D1-90C3-00C04FC2F568}")

INTERFACE IChannelMgr $IID_IChannelMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddChannelShortcut ( _                        ' VTable offset = 12
     BYREF pChannelInfo AS CHANNELSHORTCUTINFO _        ' __in CHANNELSHORTCUTINFO *pChannelInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteChannelShortcut ( _                     ' VTable offset = 16
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCategory ( _                               ' VTable offset = 20
     BYREF pCategoryInfo AS CHANNELCATEGORYINFO _       ' __in CHANNELCATEGORYINFO *pCategoryInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteCategory ( _                            ' VTable offset = 24
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumChannels ( _                              ' VTable offset = 28
     BYVAL dwEnumFlags AS DWORD _                       ' __in DWORD dwEnumFlags
   , BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pIEnumChannels AS IEnumChannels _            ' __out IEnumChannels **pIEnumChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChannelMgr_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumChannels
' IID = A4C65425-0F82-11D1-90C3-00C04FC2F568
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumChannels_INTERFACE_DEFINED)
    %IEnumChannels_INTERFACE_DEFINED = 1

' enum SUBSCRIPTIONSTATE
%SUBSTATE_NOTSUBSCRIBED       = 0
%SUBSTATE_PARTIALSUBSCRIPTION = %SUBSTATE_NOTSUBSCRIBED       + 1
%SUBSTATE_FULLSUBSCRIPTION    = %SUBSTATE_PARTIALSUBSCRIPTION + 1

' // Size = 16 bytes
TYPE CHANNELENUMINFO DWORD
   pszTitle            AS WSTRINGZ PTR   ' LPOLESTR
   pszPath             AS WSTRINGZ PTR   ' LPOLESTR
   pszURL              AS WSTRINGZ PTR   ' LPOLESTR
   stSubscriptionState AS LONG           ' SUBSCRIPTIONSTATE
END TYPE

$IID_IEnumChannels = GUID$("{A4C65425-0F82-11D1-90C3-00C04FC2F568}")

INTERFACE IEnumChannels $IID_IEnumChannels

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgChanInf AS CHANNELENUMINFO _               ' __out CHANNELENUMINFO *rgChanInf
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumChannels _                    ' __out IEnumChannels **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumChannels_INTERFACE_DEFINED__ */
