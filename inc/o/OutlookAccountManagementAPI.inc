' ########################################################################################
' Microsoft Windows
' File: OutlookAccountManagementAPI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Outlook Account Management API Reference
' MSDN Documentation; http://msdn.microsoft.com/en-us/library/bb821156%28office.12%29.aspx
' Note: Microsoft doesn't provide an header file for this API. This file has been
' elaborated based on the documentation and information provided in the following link:
' http://www.codeproject.com/KB/IP/IOlkAccountManager.aspx
' ########################################################################################

#INCLUDE THIS ONCE
%OUTLOOKACCOUNTMANAGEMENTAPI_INC = 1

#INCLUDE ONCE "mapix.inc"
#INCLUDE ONCE "mapidefs.inc"

%ACCT_INIT_NOSYNCH_MAPI_ACCTS = &H00000001???

%E_ACCT_NOT_FOUND             = &H800C8101&
%E_ACCT_WRONG_SORT_ORDER      = &H800C8105&
%E_OLK_ALREADY_INITIALIZED    = &H800C8002&
%E_OLK_NOT_INITIALIZED        = &H800C8005&
%E_OLK_PARAM_NOT_SUPPORTED    = &H800C8003&
%E_OLK_PROP_READ_ONLY         = &H800C800D&
%E_OLK_REGISTRY               = &H800C8002&

%NOTIFY_ACCT_CHANGED          = 1
%NOTIFY_ACCT_CREATED          = 2
%NOTIFY_ACCT_DELETED          = 3
%NOTIFY_ACCT_ORDER_CHANGED    = 4
%NOTIFY_ACCT_PREDELETED       = 5

%OLK_ACCOUNT_NO_FLAGS         = 0


'//Class Identifiers

'//{ed475410-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkAccountManager, 0xed475410, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkAccountManager = GUID$("{ed475410-b0d6-11d2-8c3b-00104b2a6676}")

'//{ed475411-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkPOP3Account, 0xed475411, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkPOP3Account = GUID$("{ed475411-b0d6-11d2-8c3b-00104b2a6676}")

'//{ed475412-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkIMAP4Account, 0xed475412, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkIMAP4Account = GUID$("{ed475412-b0d6-11d2-8c3b-00104b2a6676}")

'//{ed475414-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkMAPIAccount, 0xed475414, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkMAPIAccount = GUID$("{ed475414-b0d6-11d2-8c3b-00104b2a6676}")

'//{ed475418-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkMail, 0xed475418, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkMail = GUID$("{ed475418-b0d6-11d2-8c3b-00104b2a6676}")

'//{ed475419-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkAddressBook, 0xed475419, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkAddressBook = GUID$("{ed475419-b0d6-11d2-8c3b-00104b2a6676}")

'//{ed475420-b0d6-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(CLSID_OlkStore, 0xed475420, 0xb0d6, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$CLSID_OlkStore = GUID$("{ed475420-b0d6-11d2-8c3b-00104b2a6676}")

'//{4db5cbf0-3b77-4852-bc8e-bb81908861f3}
'DEFINE_GUID(CLSID_OlkHotmailAccount, 0x4db5cbf0, 0x3b77, 0x4852, 0xbc, 0x8e, 0xbb, 0x81, 0x90, 0x88, 0x61, 0xf3);
$CLSID_OlkHotmailAccount = GUID$("{4db5cbf0-3b77-4852-bc8e-bb81908861f3}")

'//{4db5cbf2-3b77-4852-bc8e-bb81908861f3}
'DEFINE_GUID(CLSID_OlkLDAPAccount, 0x4db5cbf2, 0x3b77, 0x4852, 0xbc, 0x8e, 0xbb, 0x81, 0x90, 0x88, 0x61, 0xf3);
$CLSID_OlkLDAPAccount = GUID$("{4db5cbf2-3b77-4852-bc8e-bb81908861f3}")

'//Interface Identifiers

'//{9240A6C0-AF41-11d2-8C3B-00104B2A6676}
'DEFINE_GUID(IID_IOlkErrorUnknown, 0x9240a6c0, 0xaf41, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$IID_IOlkErrorUnknown = GUID$("{9240A6C0-AF41-11d2-8C3B-00104B2A6676}")

'//{9240A6C1-AF41-11d2-8C3B-00104B2A6676}
'DEFINE_GUID(IID_IOlkEnum, 0x9240a6c0, 0xaf41, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$IID_IOlkEnum = GUID$("{9240A6C1-AF41-11d2-8C3B-00104B2A6676}")

'//{9240a6c3-af41-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(IID_IOlkAccountNotify, 0x9240a6c3, 0xaf41, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$IID_IOlkAccountNotify = GUID$("{9240a6c3-af41-11d2-8c3b-00104b2a6676}")

'//{9240a6cb-af41-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(IID_IOlkAccountHelper, 0x9240a6cb, 0xaf41, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$IID_IOlkAccountHelper = GUID$("{9240a6cb-af41-11d2-8c3b-00104b2a6676}")

'//{9240a6cd-af41-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(IID_IOlkAccountManager, 0x9240a6cd, 0xaf41, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$IID_IOlkAccountManager = GUID$("{9240a6cd-af41-11d2-8c3b-00104b2a6676}")

'//{9240a6d2-af41-11d2-8c3b-00104b2a6676}
'DEFINE_GUID(IID_IOlkAccount, 0x9240a6d2, 0xaf41, 0x11d2, 0x8c, 0x3b, 0x0, 0x10, 0x4b, 0x2a, 0x66, 0x76);
$IID_IOlkAccount = GUID$("{9240a6d2-af41-11d2-8c3b-00104b2a6676}")

'typedef struct {
'   DWORD  cb;
'   BYTE * pb;
'} ACCT_BIN;

TYPE ACCT_BIN DWORD
   cb AS DWORD      ' DWORD
   pb AS BYTE PTR   ' BYTE *
END TYPE

'typedef struct
'    {
'        DWORD dwType;
'        union
'            {
'            DWORD dw;
'            WCHAR *pwsz;
'            ACCT_BIN bin;
'            } Val;
'    } ACCT_VARIANT;

UNION ACCT_VARIANT_VAL
   dw   AS DWORD          ' DWORD
   pwsz AS WSTRINGZ PTR   ' WCHAR *
   bin  AS ACCT_BIN       ' ACCT_BIN
END UNION

TYPE ACCT_VARIANT
   dwType AS DWORD    ' DWORD
   Val    AS ACCT_VARIANT_VAL
END TYPE

%PR_PRIMARY_SEND_ACCT              = &H0E28001F???   ' PROP_TAG(PT_UNICODE, 0x0e28)
%PR_NEXT_SEND_ACCT                 = &H0E29001F???   ' PROP_TAG(PT_UNICODE, 0x0e29)

%PROP_ACCT_ID                      = &H00010003???   ' PROP_TAG(PT_LONG, 0x1)
%PROP_ACCT_IS_EXCH                 = &H00140003???   ' PROP_TAG(PT_LONG, 0x14)
%PROP_ACCT_NAME                    = &H0002001F???   ' PROP_TAG(PT_UNICODE, 0x2)
%PROP_ACCT_PROFILE_NAME            = &H0007001F???   ' PROP_TAG(PT_UNICODE, 0x7)
%PROP_ACCT_SEND_STAMP              = &H000E001F???   ' PROP_TAG(PT_UNICODE, 0xE)
%PROP_ACCT_STAMP                   = &H000D001F???   ' PROP_TAG(PT_UNICODE, 0xD)

%PROP_ACCT_USER_DISPLAY_NAME       = &H000B001F???   ' PROP_TAG(PT_UNICODE, 0xB)
%PROP_ACCT_TYPE                    = &H0004001F???   ' PROP_TAG(PT_UNICODE, 0x4) //has values like POP/SMTP or IMAP/SMTP
%PROP_ACCT_ADDRESS                 = &H000C001F???   ' PROP_TAG(PT_UNICODE, 0xC)

%PROP_ACCT_POP3_SERVER             = &H0100001F???   ' PROP_TAG(PT_UNICODE, 0x0100)
%PROP_ACCT_POP3_NAME               = &H0101001F???   ' PROP_TAG(PT_UNICODE, 0x0101)
%PROP_ACCT_POP3_PORT               = &H01040003???   ' PROP_TAG(PT_LONG, 0x0104)
%PROP_ACCT_POP3_USE_SSL            = &H01050003???   ' PROP_TAG(PT_LONG, 0x0105)
%PROP_ACCT_POP3_REMEMBER_PASSWORD  = &H01060003???   ' PROP_TAG(PT_LONG, 0x0106)
%PROP_ACCT_POP3_USE_SPA            = &H01080003???   ' PROP_TAG(PT_LONG, 0x0108)

%PROP_ACCT_SMTP_SERVER             = &H0200001F???   ' PROP_TAG(PT_UNICODE, 0x0200)
%PROP_ACCT_SMTP_NAME               = &H0204001F???   ' PROP_TAG(PT_UNICODE, 0x0204) //login ID if PROP_ACCT_SMTP_LOGON_KIND ==1
%PROP_ACCT_SMTP_LOGON_KIND         = &H02080003???   ' PROP_TAG(PT_LONG, 0x0208) //if this is 1, that means SMTP server has different login than the Incoming server

%PROP_ACCT_SMTP_PORT               = &H02010003???   ' PROP_TAG(PT_LONG, 0x0201)
%PROP_ACCT_SMTP_USE_SSL            = &H02020003???   ' PROP_TAG(PT_LONG, 0x0202)
%PROP_ACCT_SMTP_USE_AUTH           = &H02030003???   ' PROP_TAG(PT_LONG, 0x0203)
%PROP_ACCT_USE_SPA                 = &H02070003???   ' PROP_TAG(PT_LONG, 0x0207)
%PROP_ACCT_TIMEOUT                 = &H02090003???   ' PROP_TAG(PT_LONG, 0x0209)

%PROP_ACCT_FLAGS                   = &H10000003???   ' PROP_TAG(PT_LONG, 0x1000)

'//Properties related to profile having exchange account only
%PROP_EXCHANGE_EMAILID             = &H663D001F???   ' PROP_TAG(PT_UNICODE, 0x663D) //email ID
%PROP_EXCHANGE_EMAILID2            = &H6641001F???   ' PROP_TAG(PT_UNICODE, 0x6641) //email ID
%PR_ROH_PROXY_SERVER               = &H6622001F???   ' PROP_TAG(PT_UNICODE, 0x6622) //RPC server name
%PR_INTERNET_CONTENT_ID            = &H662A001F???   ' PROP_TAG(PT_UNICODE, 0x662A) //server name

' OlkAccountManager::DisplayAccountList flags
%E_ACCT_UI_BUSY         = &H800C8102???
%ACCTUI_NO_WARNING      = &H0100???
%ACCTUI_SHOW_DATA_TAB   = &H0200???
%ACCTUI_SHOW_ACCTWIZARD = &H0400???


' ########################################################################################
' IOlkErrorUnknown interface
' IID = 9240A6C0-AF41-11d2-8C3B-00104B2A6676
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOlkErrorUnknown_INTERFACE_DEFINED)
    %IOlkErrorUnknown_INTERFACE_DEFINED = 1

INTERFACE IOlkErrorUnknown $IID_IOlkErrorUnknown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
	  BYVAL hr AS LONG _                                 ' __in HRESULT hr
	, BYREF ppwszError AS DWORD _                        ' __out LPWSTR *ppwszError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOlkErrorUnknown_INTERFACE_DEFINED__ */

' ########################################################################################
' IOlkAccount interface
' IID = 9240a6d2-af41-11d2-8c3b-00104b2a6676
' Inherited interface = IOlkErrorUnknown
' ########################################################################################

#IF NOT %DEF(%IOlkAccount_INTERFACE_DEFINED)
    %IOlkAccount_INTERFACE_DEFINED = 1

INTERFACE IOlkAccount $IID_IOlkAccount

   INHERIT IUnknown

   ' =====================================================================================
   ' IOlkErrorUnknown method
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
	  BYVAL hr AS LONG _                                 ' __in HRESULT hr
	, BYREF ppwszError AS DWORD _                        ' __out LPWSTR *ppwszError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOlkAccount methods
   ' =====================================================================================
   METHOD Placeholder1 ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder2 ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder3 ( _                              ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder4 ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder5 ( _                              ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder6 ( _                              ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAccountInfo ( _                            ' VTable offset = 40
     BYREF pclsidType AS GUID _                         ' __in CLSID* pclsidType
   , BYREF pcCategories AS DWORD _                      ' __out DWORD* pcCategories
   , BYREF prgclsidCategory AS GUID _                   ' __out CLSID** prgclsidCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 44
     BYVAL dwProp AS DWORD _                            ' __in DWORD dwProp
   , BYREF pVar AS ACCT_VARIANT _                       ' __in ACCT_VARIANT* pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProp ( _                                   ' VTable offset = 48
     BYVAL dwProp AS DWORD _                            ' __in DWORD dwProp
   , BYREF pVar AS ACCT_VARIANT _                       ' __out ACCT_VARIANT* pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder7 ( _                              ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder8 ( _                              ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder9 ( _                              ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeMemory ( _                                ' VTable offset = 64
     BYVAL pv AS BYTE PTR _                             ' __in BYTE* pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder10 ( _                             ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOlkAccount_INTERFACE_DEFINED__ */

' ########################################################################################
' IOlkAccountHelper interface
' IID = 9240a6cb-af41-11d2-8c3b-00104b2a6676
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOlkAccountHelper_INTERFACE_DEFINED)
    %IOlkAccountHelper_INTERFACE_DEFINED = 1

INTERFACE IOlkAccountHelper $IID_IOlkAccountHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Placeholder1 ( _                              ' VTable offset = 12
     BYVAL DWORD _                                      ' void*
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIdentity ( _                               ' VTable offset = 16
     BYREF pwszIdentity AS WSTRINGZ _                   ' __inout LPWSTR pwszIdentity
   , BYREF pcch AS DWORD _                              ' __inout DWORD * pcch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMapiSession ( _                            ' VTable offset = 20
     BYREF ppmsess AS IUnknown _                        ' __out LPUNKNOWN * ppmsess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffSession ( _                           ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOlkAccountHelper_INTERFACE_DEFINED__ */

' ########################################################################################
' IOlkAccountNotify interface
' IID = 9240a6c3-af41-11d2-8c3b-00104b2a6676
' Inherited interface = IOlkErrorUnknown
' ########################################################################################

#IF NOT %DEF(%IOlkAccountNotify_INTERFACE_DEFINED)
    %IOlkAccountNotify_INTERFACE_DEFINED = 1

INTERFACE IOlkAccountNotify $IID_IOlkAccountNotify

   INHERIT IUnknown

   ' =====================================================================================
   ' IOlkErrorUnknown method
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
	  BYVAL hr AS LONG _                                 ' __in HRESULT hr
	, BYREF ppwszError AS DWORD _                        ' __out LPWSTR *ppwszError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOlkAccountNotify methods
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 16
     BYVAL dwNotify AS DWORD _                          ' __in DWORD dwNotify
   , BYVAL dwAcctID AS DWORD _                          ' __in DWORD dwAcctID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOlkAccountNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' IOlkEnum interface
' IID = 9240A6C1-AF41-11d2-8C3B-00104B2A6676
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOlkEnum_INTERFACE_DEFINED)
    %IOlkEnum_INTERFACE_DEFINED = 1

INTERFACE IOlkEnum $IID_IOlkEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out DWORD *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNext ( _                                   ' VTable offset = 20
     BYREF ppunk AS IUnknown _                          ' __out LPUNKNOWN* ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL cSkip AS DWORD _                             ' __in DWORD cSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOlkEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' IOlkAccountManager interface
' IID = 9240a6cd-af41-11d2-8c3b-00104b2a6676
' Inherited interface = IOlkErrorUnknown
' ########################################################################################

#IF NOT %DEF(%IOlkAccountManager_INTERFACE_DEFINED)
    %IOlkAccountManager_INTERFACE_DEFINED = 1

INTERFACE IOlkAccountManager $IID_IOlkAccountManager

   INHERIT IUnknown

   ' =====================================================================================
   ' IOlkErrorUnknown method
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
	  BYVAL hr AS LONG _                                 ' __in HRESULT hr
	, BYREF ppwszError AS DWORD _                        ' __out LPWSTR *ppwszError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOlkAccountManager methods
   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 16
     BYVAL pAcctHelper AS IOlkAccountHelper _           ' __in IOlkAccountHelper* pAcctHelper
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' According the MSDN documentation: //virtual STDMETHODIMP PlaceHolder1();
   METHOD DisplayAccountList ( _                        ' VTable offset = 20
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpwszReserved AS WSTRINGZ _                  ' __in LPCWSTR lpwszReserved // Not used
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved // Not used
   , BYREF pclsidReserved1 AS GUID _                    ' __in const CLSID * pclsidReserved1 // Not used
   , BYREF pclsidReserved2 AS GUID _                    ' __in const CLSID * pclsidReserved2 // Not used
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder2 ( _                              ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder3 ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder4 ( _                              ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder5 ( _                              ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder6 ( _                              ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindAccount ( _                               ' VTable offset = 44
     BYVAL dwProp AS DWORD _                            ' __in DWORD dwProp
   , BYREF pVar AS ACCT_VARIANT _                       ' __in ACCT_VARIANT* pVar
   , BYREF ppAccount AS IOlkAccount _                   ' __out IOlkAccount** ppAccount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder7 ( _                              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder8 ( _                              ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder9 ( _                              ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAccount ( _                             ' VTable offset = 56
     BYVAL dwAcctID AS DWORD _                          ' __in DWORD dwAcctID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder10 ( _                             ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offset = 64
     BYVAL dwAcctID AS DWORD _                          ' __in DWORD dwAcctID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOrder ( _                                  ' VTable offset = 68
     BYREF pclsidCategory AS GUID _                     ' __in const CLSID* pclsidCategory
   , BYREF pcAccts AS DWORD _                           ' __out DWORD* pcAccts
   , BYREF prgAccts AS DWORD _                          ' __out DWORD* prgAccts[]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOrder ( _                                  ' VTable offset = 72
     BYREF pclsidCategory AS GUID _                     ' __in const CLSID* pclsidCategory
   , BYREF pcAccts AS DWORD _                           ' __in DWORD* pcAccts
   , BYREF prgAccts AS DWORD _                          ' __in DWORD* prgAccts[]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateAccounts ( _                         ' VTable offset = 76
     BYREF pclsidCategory AS GUID _                     ' __in const CLSID* pclsidCategory
   , BYREF pclsidType AS GUID _                         ' __in const CLSID* pclsidType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnum AS IOlkEnum _                         ' __out IOlkEnum** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder11 ( _                             ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder12 ( _                             ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeMemory ( _                                ' VTable offset = 88
     BYVAL pv AS BYTE PTR _                             ' __in BYTE* pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 92
     BYVAL pNotify AS IOlkAccountNotify _               ' __in IOlkAccountNotify* pNotify
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD* pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 96
     BYREF pdwCookie AS DWORD _                         ' __in DWORD* pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder13 ( _                             ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder14 ( _                             ' VTable offset = 104
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Placeholder15 ( _                             ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOlkAccountManager_INTERFACE_DEFINED__ */
