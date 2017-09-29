' ########################################################################################
' Microsoft Windows
' File: WinWlx.inc
' WLX == WinLogon eXtension
' Contents: Definitions, data types, and routine prototypes necessary to produce a
' replacement Graphical Identification aNd Authentication (GINA) DLL for Winlogon.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINWLX_INC = 1

#INCLUDE ONCE "windows.inc"

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//  #defines                                                          //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// Revisions of Winlogon API available for use by GINAs
'// Version is two parts: Major revision and minor revision.
'// Major revision is the upper 16-bits, minor is the lower
'// 16-bits.
'//

%WLX_VERSION_1_0     = &H00010000???
%WLX_VERSION_1_1     = &H00010001???
%WLX_VERSION_1_2     = &H00010002???
%WLX_VERSION_1_3     = &H00010003???
%WLX_VERSION_1_4     = &H00010004???
%WLX_CURRENT_VERSION = %WLX_VERSION_1_4

'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// Secure attention sequence types
'// These values are passed to routines that have a dwSasType
'// parameter.
'//
'//  ALL VALUES FROM 0 TO 127 ARE RESERVED FOR MICROSOFT DEFINITION.
'//  VALUES ABOVE 127 ARE RESERVED FOR CUSTOMER DEFINITION.
'//
'//      CTRL_ALT_DEL - used to indicate that the standard ctrl-alt-del
'//          secure attention sequence has been entered.
'//
'//      SCRNSVR_TIMEOUT - used to indicate that keyboard/mouse inactivity
'//          has lead to a screensaver activation.  It is up to the GINA
'//          DLL whether this constitutes a workstation locking event.
'//
'//      SCRNSVR_ACTIVITY - used to indicate that keyboard or mouse
'//          activity occured while a secure screensaver was active.
'//
'//      SC_INSERT - used to indicate that a smart card has been inserted
'//          to a compatible device
'//
'//      SC_REMOVE - used to indicate that a smart card has been removed
'//          from a compatible device
'//

%WLX_SAS_TYPE_TIMEOUT                 = 0
%WLX_SAS_TYPE_CTRL_ALT_DEL            = 1
%WLX_SAS_TYPE_SCRNSVR_TIMEOUT         = 2
%WLX_SAS_TYPE_SCRNSVR_ACTIVITY        = 3
%WLX_SAS_TYPE_USER_LOGOFF             = 4
%WLX_SAS_TYPE_SC_INSERT               = 5
%WLX_SAS_TYPE_SC_REMOVE               = 6
%WLX_SAS_TYPE_AUTHENTICATED           = 7
%WLX_SAS_TYPE_SC_FIRST_READER_ARRIVED = 8
%WLX_SAS_TYPE_SC_LAST_READER_REMOVED  = 9
%WLX_SAS_TYPE_SWITCHUSER              = 10
%WLX_SAS_TYPE_MAX_MSFT_VALUE          = 127

'//
'// This structure is available through WlxGetOption, and is
'// passed as the lParam for any S/C SAS notices sent to windows
'//
' // Size = 16 bytes
TYPE WLX_SC_NOTIFICATION_INFO DWORD
   pszCard           AS WSTRINGZ PTR   ' PWSTR
   pszReader         AS WSTRINGZ PTR   ' PWSTR
   pszContainer      AS WSTRINGZ PTR   ' PWSTR
   pszCryptoProvider AS WSTRINGZ PTR   ' PWSTR
END TYPE

'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// Upon successful logon, the GINA DLL may specify any of the following
'// options to Winlogon (via the dwOptions parameter of the WlxLoggedOutSas()
'// api).  When set, these options specify:
'//
'//      NO_PROFILE - Winlogon must NOT load a profile for the logged
'//                   on user.  Either the GINA DLL will take care of
'//                   this activity, or the user does not need a profile.
'//

%WLX_LOGON_OPT_NO_PROFILE = &H00000001???


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// GINA DLLs are expected to return account information to Winlogon
'// following a successful logon.  This information allows Winlogon
'// to support profile loading and supplemental network providers.
'//
'// To allow different sets of profile information to be returned
'// by GINAs over time, the first DWORD of each profile structure
'// is expected to contain a type-identifier.  The following constants
'// are the defined profile type identifiers.
'//

'//
'// Standard profile is V2_0
'//

%WLX_PROFILE_TYPE_V1_0 = 1
%WLX_PROFILE_TYPE_V2_0 = 2


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// WlxLoggedOnSas() and WlxWkstaLockedSas() return an action
'// value to Winlogon directing Winlogon to either remain unchanged
'// or to perform some action (such as force-log the user off).
'// These are the values that may be returned.  Note, however, that
'// not all of the values may be returned by both of these api.  See
'// the description of each api to see which values are expected from
'// each.
'//
'//  LOGON              - User has logged on
'//  NONE               - Don't change the state of the window station.
'//  LOCK_WKSTA         - Lock the workstation, wait for next SAS.
'//  LOGOFF             - Log the user off of the workstation.
'//  SHUTDOWN           - Log the user off and shutdown the machine.
'//  PWD_CHANGED        - Indicates that the user changed their password.  Notify network providers.
'//  TASKLIST           - Invoke the task list.
'//  UNLOCK_WKSTA       - Unlock the workstation.
'//  FORCE_LOGOFF       - Forcibly log the user off.
'//  SHUTDOWN_POWER_OFF - Turn off machine after shutting down.
'//  SHUTDOWN_REBOOT    - Reboot machine after shutting down.
'//  SHUTDOWN_SLEEP     - Put the machine to sleep
'//  SHUTDOWN_SLEEP2    - Put the machine to sleep and disable wakeup events
'//  SHUTDOWN_HIBERNATE - Hibernate the machine
'//  RECONNECTED        - Session was reconnected to an earlier session
'//

%WLX_SAS_ACTION_LOGON                = 1
%WLX_SAS_ACTION_NONE                 = 2
%WLX_SAS_ACTION_LOCK_WKSTA           = 3
%WLX_SAS_ACTION_LOGOFF               = 4
%WLX_SAS_ACTION_SHUTDOWN             = 5
%WLX_SAS_ACTION_PWD_CHANGED          = 6
%WLX_SAS_ACTION_TASKLIST             = 7
%WLX_SAS_ACTION_UNLOCK_WKSTA         = 8
%WLX_SAS_ACTION_FORCE_LOGOFF         = 9
%WLX_SAS_ACTION_SHUTDOWN_POWER_OFF   = 10
%WLX_SAS_ACTION_SHUTDOWN_REBOOT      = 11
%WLX_SAS_ACTION_SHUTDOWN_SLEEP       = 12
%WLX_SAS_ACTION_SHUTDOWN_SLEEP2      = 13
%WLX_SAS_ACTION_SHUTDOWN_HIBERNATE   = 14
%WLX_SAS_ACTION_RECONNECTED          = 15
%WLX_SAS_ACTION_DELAYED_FORCE_LOGOFF = 16
%WLX_SAS_ACTION_SWITCH_CONSOLE       = 17


'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//  Window Messages                                                   //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

'//
'// The WM_SAS is defined as follows
'//
'//  The wParam parameter has the SAS Type (above)

%WLX_WM_SAS = %WM_USER + 601


'//
'// Dialog return values
'//
'// These may be returned by dialogs started by a GINA dll.
'//

%WLX_DLG_SAS                  = 101
%WLX_DLG_INPUT_TIMEOUT        = 102    ' Input (keys, etc) timed out
%WLX_DLG_SCREEN_SAVER_TIMEOUT = 103    ' Screen Saver activated
%WLX_DLG_USER_LOGOFF          = 104    ' User logged off


'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//  #data types                                                       //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// The WLX_PROFILE_* structure is returned from a GINA DLL
'// following authentication.  This information is used by Winlogon
'// to support supplemental Network Providers and to load the
'// newly logged-on user's profile.
'//
'// Winlogon is responsible for freeing both the profile structure
'// and the fields within the structure that are marked as separately
'// deallocatable.
'//

' // Size = 8 bytes
TYPE WLX_PROFILE_V1_0 DWORD
   dwType     AS DWORD          ' DWORD
   pszProfile AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 24 bytes
TYPE WLX_PROFILE_V2_0 DWORD
   dwType                       AS DWORD         ' DWORD
   pszProfile                   AS WSTRINGZ PTR   ' PWSTR
   pszPolicy                    AS WSTRINGZ PTR   ' PWSTR
   pszNetworkDefaultUserProfile AS WSTRINGZ PTR   ' PWSTR
   pszServerName                AS WSTRINGZ PTR   ' PWSTR
   pszEnvironment               AS WSTRINGZ PTR   ' PWSTR
END TYPE


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// The WLX_NPR_NOTIFICATION_INFO structure is returned
'// from a GINA DLL following successful authentication.
'// This information is used by Winlogon to provide
'// identification and authentication information already
'// collected to network providers.  Winlogon is
'// responsible for freeing both the main structure and all
'// string and other buffers pointed to from within the
'// structure.
'//

' // Size = 16 bytes
TYPE WLX_MPR_NOTIFY_INFO DWORD
   pszUserName    AS WSTRINGZ PTR   ' PWSTR
   pszDomain      AS WSTRINGZ PTR   ' PWSTR
   pszPassword    AS WSTRINGZ PTR   ' PWSTR
   pszOldPassword AS WSTRINGZ PTR   ' PWSTR
END TYPE


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// WLX_TERMINAL_SERVICES_DATA is used by the GINA during a
'// WlxQueryTerminalServicesData() callback into WinLogon from the
'// WlxLoggedOutSAS() context, after the user name and domain are known.
'// This structure relates to TS user configuration information which is
'// retrieved from the Domain Controller and SAM database. Having WinLogon
'// pass this information means the GINA does not need to do the same
'// off-machines lookups again.
'//

%WLX_DIRECTORY_LENGTH = 256

' // Size = 1036 bytes
TYPE WLX_TERMINAL_SERVICES_DATA BYTE
   ProfilePath  AS WSTRINGZ * %WLX_DIRECTORY_LENGTH + 1   ' WCHAR
   HomeDir      AS WSTRINGZ * %WLX_DIRECTORY_LENGTH + 1   ' WCHAR
   HomeDirDrive AS WSTRINGZ * 4                           ' WCHAR
END TYPE


'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// The WLX_CLIENT_CREDENTIALS_INFO structure is returned
'// from winlogon from the WlxQueryClientCredentials() call.
'//
'// This allows a network client WinStation to pass client
'// credentials for automatic logon.
'//
'// The MSGINA DLL is responsible for freeing the memory
'// and substrings with LocalFree().
'//

%WLX_CREDENTIAL_TYPE_V1_0 = 1
%WLX_CREDENTIAL_TYPE_V2_0 = 2

' // Size = 20 bytes
TYPE WLX_CLIENT_CREDENTIALS_INFO_V1_0 DWORD
   dwType             AS DWORD          ' DWORD
   pszUserName        AS WSTRINGZ PTR   ' PWSTR
   pszDomain          AS WSTRINGZ PTR   ' PWSTR
   pszPassword        AS WSTRINGZ PTR   ' PWSTR
   fPromptForPassword AS LONG           ' BOOL
END TYPE

MACRO WLX_CLIENT_CREDENTIALS_INFO = WLX_CLIENT_CREDENTIALS_INFO_V1_0

' // Size = 24 bytes
TYPE WLX_CLIENT_CREDENTIALS_INFO_V2_0 DWORD
   dwType                    AS DWORD          ' DWORD
   pszUserName               AS WSTRINGZ PTR   ' PWSTR
   pszDomain                 AS WSTRINGZ PTR   ' PWSTR
   pszPassword               AS WSTRINGZ PTR   ' PWSTR
   fPromptForPassword        AS LONG           ' BOOL
   fDisconnectOnLogonFailure AS LONG           ' BOOL
END TYPE

MACRO WLX_CLIENT_CREDENTIALS_INFO_2_0 = WLX_CLIENT_CREDENTIALS_INFO_V2_0

'/////////////////////////////////////////////////////////////////////////
'/////////////////////////////////////////////////////////////////////////
'//
'// The WLX_CONSOLESWITCH_CREDENTIALS_INFO structure is returned
'// from gina in response to WlxGetConsoleSwitchCredentials calls.

'// This structure is also returned from winlogon in response to
'// to WlxQueryConsoleSwitchCredentials call
'//
'// This is used to implement single session Terminal Server. A remote
'// session winlogon calls WlxGetConsoleSwitchCredentials to get the token
'// and other info of the logged on user from msgina. This info is then passed to
'// the console session winlogon to autologon the user on the console session.
'// The gina on console session calls WlxQueryConsoleSwitchCredentials to get
'// this info from winlogon and logs on the user.
'//
'// The caller is responsible for freeing the memory
'// and substrings with LocalFree().
'//

%WLX_CONSOLESWITCHCREDENTIAL_TYPE_V1_0 = 1

' // Size = 168 bytes
TYPE WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0  ' Must be 8 byte aligned
   dwType             AS DWORD          ' DWORD
   UserToken          AS DWORD          ' HANDLE
   LogonId            AS QUAD           ' LUID
   Quotas             AS QUOTA_LIMITS   ' QUOTA_LIMITS
   UserName           AS WSTRINGZ PTR   ' PWSTR
   Domain             AS WSTRINGZ PTR   ' PWSTR
   LogonTime          AS QUAD           ' LARGE_INTEGER
   SmartCardLogon     AS LONG           ' BOOL
   ProfileLength      AS DWORD          ' ULONG
   MessageType        AS DWORD          ' DWORD
   LogonCount         AS WORD           ' USHORT
   BadPasswordCount   AS WORD           ' USHORT
   ProfileLogonTime   AS QUAD           ' LARGE_INTEGER
   LogoffTime         AS QUAD           ' LARGE_INTEGER
   KickOffTime        AS QUAD           ' LARGE_INTEGER
   PasswordLastSet    AS QUAD           ' LARGE_INTEGER
   PasswordCanChange  AS QUAD           ' LARGE_INTEGER
   PasswordMustChange AS QUAD           ' LARGE_INTEGER
   LogonScript        AS WSTRINGZ PTR   ' PWSTR
   HomeDirectory      AS WSTRINGZ PTR   ' PWSTR
   FullName           AS WSTRINGZ PTR   ' PWSTR
   ProfilePath        AS WSTRINGZ PTR   ' PWSTR
   HomeDirectoryDrive AS WSTRINGZ PTR   ' PWSTR
   LogonServer        AS WSTRINGZ PTR   ' PWSTR
   UserFlags          AS DWORD          ' ULONG
   PrivateDataLen     AS DWORD          ' ULONG
   PrivateData        AS BYTE PTR       ' PBYTE
   alignment__        AS DWORD          ' // To keep 8 byte alignment
END TYPE

MACRO WLX_CONSOLESWITCH_CREDENTIALS_INFO = WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//  Services that replacement GINAs   ** MUST ** provide              //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WlxNegotiate ALIAS "WlxNegotiate" ( _
   BYVAL dwWinlogonVersion AS DWORD _                   ' __in DWORD  dwWinlogonVersion
 , BYREF pdwDllVersion AS DWORD _                       ' __out PDWORD pdwDllVersion
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WlxInitialize ALIAS "WlxInitialize" ( _
   BYREF lpWinsta AS WSTRINGZ _                         ' __in LPWSTR   lpWinsta
 , BYVAL hWlx AS DWORD _                                ' __in HANDLE   hWlx
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID    pvReserved
 , BYVAL pWinlogonFunctions AS DWORD _                  ' __in PVOID    pWinlogonFunctions
 , BYREF pWlxContext AS ANY _                           ' __out PVOID * pWlxContext
 ) AS LONG                                              ' BOOL

DECLARE SUB WlxDisplaySASNotice ALIAS "WlxDisplaySASNotice" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 )                                                      ' void

DECLARE FUNCTION WlxLoggedOutSAS ALIAS "WlxLoggedOutSAS" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in      PVOID                pWlxContext
 , BYVAL dwSasType AS DWORD _                           ' __in      DWORD                dwSasType
 , BYREF pAuthenticationId AS ANY _                     ' __out     PLUID                pAuthenticationId
 , BYREF pLogonSid AS ANY _                             ' __in_out  PSID                 pLogonSid
 , BYREF pdwOptions AS DWORD _                          ' __out     PDWORD               pdwOptions
 , BYREF phToken AS DWORD _                             ' __out     PHANDLE              phToken
 , BYREF pNprNotifyInfo AS WLX_MPR_NOTIFY_INFO _        ' __out     PWLX_MPR_NOTIFY_INFO pNprNotifyInfo
 , BYREF pProfile AS ANY _                              ' __out     PVOID *              pProfile
 ) AS LONG                                              ' int

DECLARE FUNCTION WlxActivateUserShell ALIAS "WlxActivateUserShell" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 , BYREF pszDesktopName AS WSTRINGZ _                   ' __in PWSTR pszDesktopName
 , BYREF pszMprLogonScript AS WSTRINGZ _                ' __in PWSTR pszMprLogonScript
 , BYVAL pEnvironment AS DWORD _                        ' __in PVOID pEnvironment
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WlxLoggedOnSAS ALIAS "WlxLoggedOnSAS" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 , BYVAL dwSasType AS DWORD _                           ' __in DWORD dwSasType
 , BYVAL pReserved AS DWORD _                           ' __in PVOID pReserved
 ) AS LONG                                              ' int

DECLARE SUB WlxDisplayLockedNotice ALIAS "WlxDisplayLockedNotice" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 )                                                      ' void

DECLARE FUNCTION WlxWkstaLockedSAS ALIAS "WlxWkstaLockedSAS" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 , BYVAL dwSasType AS DWORD _                           ' __in DWORD dwSasType
 ) AS LONG                                              ' int

DECLARE FUNCTION WlxIsLockOk ALIAS "WlxIsLockOk" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WlxIsLogoffOk ALIAS "WlxIsLogoffOk" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 ) AS LONG                                              ' BOOL

DECLARE SUB WlxLogoff ALIAS "WlxLogoff" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 )                                                      ' void

DECLARE SUB WlxShutdown ALIAS "WlxShutdown" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 , BYVAL ShutdownType AS DWORD _                        ' __in DWORD ShutdownType
 )                                                      ' void

'//
'// NEW for version 1.1
'//

DECLARE FUNCTION WlxScreenSaverNotify ALIAS "WlxScreenSaverNotify" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in     PVOID  pWlxContext
 , BYREF pSecure AS LONG _                              ' __in_out BOOL * pSecure
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WlxStartApplication ALIAS "WlxStartApplication" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 , BYREF pszDesktopName AS WSTRINGZ _                   ' __in PWSTR pszDesktopName
 , BYVAL pEnvironment AS DWORD _                        ' __in PVOID pEnvironment
 , BYREF pszCmdLine AS WSTRINGZ _                       ' __in PWSTR pszCmdLine
 ) AS LONG                                              ' BOOL

'//
'// New for 1.3
'//

DECLARE FUNCTION WlxNetworkProviderLoad ALIAS "WlxNetworkProviderLoad" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in  PVOID                pWlxContext
 , BYREF pNprNotifyInfo AS WLX_MPR_NOTIFY_INFO _        ' __out PWLX_MPR_NOTIFY_INFO pNprNotifyInfo
 ) AS LONG                                              ' BOOL

%STATUSMSG_OPTION_NOANIMATION   = &H00000001???
%STATUSMSG_OPTION_SETFOREGROUND = &H00000002???

DECLARE FUNCTION WlxDisplayStatusMessage ALIAS "WlxDisplayStatusMessage" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 , BYVAL hDesktop AS DWORD _                            ' __in HDESK hDesktop
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYREF pTitle AS WSTRINGZ  _                          ' __in PWSTR pTitle
 , BYREF pMessage AS WSTRINGZ _                         ' __in PWSTR pMessage
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WlxGetStatusMessage ALIAS "WlxGetStatusMessage" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in  PVOID   pWlxContext
 , BYREF pdwOptions AS DWORD _                          ' __out DWORD * pdwOptions
 , BYREF pMessage AS WSTRINGZ _                         ' __out PWSTR   pMessage
 , BYVAL dwBufferSize AS DWORD _                        ' __in  DWORD   dwBufferSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WlxRemoveStatusMessage ALIAS "WlxRemoveStatusMessage" (_
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 ) AS LONG                                              ' BOOL

'//
'// New for 1.4
'//

DECLARE FUNCTION WlxGetConsoleSwitchCredentials ALIAS "WlxGetConsoleSwitchCredentials" ( _
   BYVAL pWlxContext AS DWORD _                        ' __in  PVOID pWlxContext
 , BYVAL pCredInfo AS DWORD _                           ' __out PVOID pCredInfo
 ) AS LONG                                              ' BOOL

DECLARE SUB WlxReconnectNotify ALIAS "WlxReconnectNotify" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 )                                                      ' void

DECLARE SUB WlxDisconnectNotify ALIAS "WlxDisconnectNotify" ( _
   BYVAL pWlxContext AS DWORD _                         ' __in PVOID pWlxContext
 )                                                      ' void

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//  Services that Winlogon provides                                   //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

' // Size = 16 bytes
TYPE WLX_DESKTOP DWORD
   Size           AS DWORD          ' DWORD
   Flags          AS DWORD          ' DWORD
   hDesktop       AS DWORD          ' HDESK
   pszDesktopName AS WSTRINGZ PTR   ' PWSTR
END TYPE

%WLX_DESKTOP_NAME   = &H00000001???    ' // Name present
%WLX_DESKTOP_HANDLE = &H00000002???    ' // Handle present


'typedef VOID
'(WINAPI * PWLX_USE_CTRL_ALT_DEL)(
'    HANDLE                  hWlx
'    );

'SUB WLX_USE_CTRL_ALT_DEL ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' )                                                      ' void

'typedef VOID
'(WINAPI * PWLX_SET_CONTEXT_POINTER)(
'    HANDLE                  hWlx,
'    PVOID                   pWlxContext
'    );

'SUB WLX_SET_CONTEXT_POINTER ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL pWlxContext AS DWORD _                         ' PVOID pWlxContext
' )                                                      ' void


'typedef VOID
'(WINAPI * PWLX_SAS_NOTIFY)(
'    HANDLE                  hWlx,
'    DWORD                   dwSasType
'    );

'SUB WLX_SAS_NOTIFY ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL dwSasType AS DWORD _                           ' DWORD dwSasType
' )                                                      ' void

'typedef BOOL
'(WINAPI * PWLX_SET_TIMEOUT)(
'    HANDLE                  hWlx,
'    DWORD                   Timeout);

'FUNCTION WLX_SET_TIMEOUT ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL dwTimeout AS DWORD _                           ' DWORD Timeout
' ) AS LONG                                              ' BOOL

'typedef int
'(WINAPI * PWLX_ASSIGN_SHELL_PROTECTION)(
'    HANDLE                  hWlx,
'    HANDLE                  hToken,
'    HANDLE                  hProcess,
'    HANDLE                  hThread
'    );

'FUNCTION WLX_ASSIGN_SHELL_PROTECTION ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hToken AS DWORD _                              ' HANDLE hToken
' , BYVAL hProcess AS DWORD _                            ' HANDLE hProcess
' , BYVAL hThread AS DWORD _                             ' HANDLE hThread
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_MESSAGE_BOX)(
'    HANDLE                  hWlx,
'    HWND                    hwndOwner,
'    LPWSTR                  lpszText,
'    LPWSTR                  lpszTitle,
'    UINT                    fuStyle
'    );

'FUNCTION WLX_MESSAGE_BOX ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hwndOwner AS DWORD _                           ' HWND hwndOwner
' , BYVAL lpszText AS WSTRINGZ _                         ' LPWSTR lpszText
' , BYVAL lpszTitle AS WSTRINGZ _                        ' LPWSTR lpszTitle
' , BYVAL fuStyle AS DWORD _                             ' UINT fuStyle
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_DIALOG_BOX)(
'    HANDLE                  hWlx,
'    HANDLE                  hInst,
'    LPWSTR                  lpszTemplate,
'    HWND                    hwndOwner,
'    DLGPROC                 dlgprc
'    );

'FUNCTION WLX_DIALOG_BOX ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hInst AS DWORD _                               ' HANDLE hInst
' , BYREF lpszTemplate AS WSTRINGZ _                     ' LPWSTR lpszTemplate
' , BYVAL hwndOwner AS DWORD _                           ' HWND hwndOwner
' , BYVAL dlgprc AS DWORD _                              ' DLGPROC dlgprc
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_DIALOG_BOX_INDIRECT)(
'    HANDLE                  hWlx,
'    HANDLE                  hInst,
'    LPCDLGTEMPLATE          hDialogTemplate,
'    HWND                    hwndOwner,
'    DLGPROC                 dlgprc
'    );

'FUNCTION WLX_DIALOG_BOX_INDIRECT ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hInst AS DWORD _                               ' HANDLE hInst
' , BYREF hDialogTemplate AS DLGTEMPLATE _               ' LPCDLGTEMPLATE hDialogTemplate
' , BYVAL hwndOwner AS DWORD _                           ' HWND hwndOwner
' , BYVAL dlgprc AS DWORD _                              ' DLGPROC DLGPROC
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_DIALOG_BOX_PARAM)(
'    HANDLE                  hWlx,
'    HANDLE                  hInst,
'    LPWSTR                  lpszTemplate,
'    HWND                    hwndOwner,
'    DLGPROC                 dlgprc,
'    LPARAM                  dwInitParam
'    );

'FUNCTION WLX_DIALOG_BOX_PARAM ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hInst AS DWORD _                               ' HANDLE hInst
' , BYREF lpszTemplate AS WSTRINGZ _                     ' LPWSTR lpszTemplate
' , BYVAL hwndOwner AS DWORD _                           ' HWND hwndOwner
' , BYVAL dlgprc AS DWORD _                              ' DLGPROC dlgprc
' , BYVAL dwInitParam AS LONG _                          ' LPARAM dwInitParam
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_DIALOG_BOX_INDIRECT_PARAM)(
'    HANDLE                  hWlx,
'    HANDLE                  hInst,
'    LPCDLGTEMPLATE          hDialogTemplate,
'    HWND                    hwndOwner,
'    DLGPROC                 dlgprc,
'    LPARAM                  dwInitParam
'    );

'FUNCTION WLX_DIALOG_BOX_INDIRECT_PARAM ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hInst AS DWORD _                               ' HANDLE hInst
' , BYREF hDialogTemplate AS DLGTEMPLATE _               ' LPCDLGTEMPLATE hDialogTemplate
' , BYVAL hwndOwner AS DWORD _                           ' HWND hwndOwner
' , BYVAL dlgprc AS DWORD _                              ' DLGPROC dlgprc
' , BYVAL dwInitParam AS LONG _                          ' LPARAM dwInitParam
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_SWITCH_DESKTOP_TO_USER)(
'    HANDLE                  hWlx);

'FUNCTION WLX_SWITCH_DESKTOP_TO_USER ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_SWITCH_DESKTOP_TO_WINLOGON)(
'    HANDLE                  hWlx);

'FUNCTION WLX_SWITCH_DESKTOP_TO_WINLOGON ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' ) AS LONG                                              ' int

'typedef int
'(WINAPI * PWLX_CHANGE_PASSWORD_NOTIFY)(
'    HANDLE                  hWlx,
'    PWLX_MPR_NOTIFY_INFO    pMprInfo,
'    DWORD                   dwChangeInfo
'    );

'FUNCTION WLX_CHANGE_PASSWORD_NOTIFY ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL pMprInfo AS DWORD _                            ' PWLX_MPR_NOTIFY_INFO pMprInfo
' , BYVAL dwChangeInfo AS DWORD _                        ' DWORD dwChangeInfo
' ) AS LONG                                              ' int

'typedef BOOL
'(WINAPI * PWLX_GET_SOURCE_DESKTOP)(
'    HANDLE                  hWlx,
'    PWLX_DESKTOP *          ppDesktop);

'FUNCTION WLX_CHANGE_PASSWORD_NOTIFY ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYREF ppDesktop AS WLX_DESKTOP _                     ' WLX_DESKTOP * ppDesktop
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(WINAPI * PWLX_SET_RETURN_DESKTOP)(
'    HANDLE                  hWlx,
'    PWLX_DESKTOP            pDesktop);

'FUNCTION WLX_SET_RETURN_DESKTOP ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYREF pDesktop AS WLX_DESKTOP _                      ' WLX_DESKTOP pDesktop
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(WINAPI * PWLX_CREATE_USER_DESKTOP)(
'    HANDLE                  hWlx,
'    HANDLE                  hToken,
'    DWORD                   Flags,
'    PWSTR                   pszDesktopName,
'    PWLX_DESKTOP *          ppDesktop);

'FUNCTION WLX_CREATE_USER_DESKTOP ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL hToken AS DWORD _                              ' HANDLE hToken
' , BYVAL Flags AS DWORD _                               ' DWORD Flags
' , BYREF pszDesktopName AS WSTRINGZ _                   ' PWSTR pszDesktopName
' , BYREF ppDesktop AS WLX_DESKTOP _                     ' WLX_DESKTOP * ppDesktop
' ) AS LONG                                              ' BOOL


%WLX_CREATE_INSTANCE_ONLY = &H00000001???
%WLX_CREATE_USER          = &H00000002???


'typedef int
'(WINAPI * PWLX_CHANGE_PASSWORD_NOTIFY_EX)(
'    HANDLE                  hWlx,
'    PWLX_MPR_NOTIFY_INFO    pMprInfo,
'    DWORD                   dwChangeInfo,
'    PWSTR                   ProviderName,
'    PVOID                   Reserved);

'FUNCTION WLX_CHANGE_PASSWORD_NOTIFY_EX ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL pMprInfo AS DWORD _                            ' PWLX_MPR_NOTIFY_INFO pMprInfo
' , BYVAL dwChangeInfo AS DWORD _                        ' DWORD dwChangeInfo
' , BYREF ProviderName AS WSTRINGZ _                     ' PWSTR ProviderName
' , BYVAL Reserved AS DWORD _                            ' PVOID Reserved
' ) AS LONG                                              ' int

'typedef BOOL
'(WINAPI * PWLX_CLOSE_USER_DESKTOP)(
'    HANDLE          hWlx,
'    PWLX_DESKTOP    pDesktop,
'    HANDLE          hToken );

'FUNCTION WLX_CLOSE_USER_DESKTOP ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYREF pDesktop AS WLX_DESKTOP _                      ' PWLX_DESKTOP pDesktop
' , BYVAL hToken AS DWORD _                              ' HANDLE hToken
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(WINAPI * PWLX_SET_OPTION)(
'    HANDLE hWlx,
'    DWORD Option,
'    ULONG_PTR Value,
'    ULONG_PTR * OldValue
'    );

'FUNCTION WLX_SET_OPTION ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL Option AS DWORD _                              ' DWORD Option
' , BYVAL Value AS DWORD _                               ' ULONG_PTR Value
' , BYVAL OldValue AS DWORD _                            ' ULONG_PTR * OldValue
' ) LONG                                                 ' BOOL

'typedef BOOL
'(WINAPI * PWLX_GET_OPTION)(
'    HANDLE hWlx,
'    DWORD Option,
'    ULONG_PTR * Value
'    );

'FUNCTION WLX_GET_OPTION ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYVAL Option AS DWORD _                              ' DWORD Option
' , BYVAL Value AS DWORD _                               ' ULONG_PTR Value
' ) AS LONG                                              ' BOOL

'typedef VOID
'(WINAPI * PWLX_WIN31_MIGRATE)(
'    HANDLE                  hWlx
'    );

'SUB WLX_WIN31_MIGRATE ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' )                                                      ' void

'typedef BOOL
'(WINAPI * PWLX_QUERY_CLIENT_CREDENTIALS)(
'    PWLX_CLIENT_CREDENTIALS_INFO_V1_0 pCred
'    );

'FUNCTION WLX_QUERY_CLIENT_CREDENTIALS ( _
'   BYREF pCred AS WLX_CLIENT_CREDENTIALS_INFO_V1_0 _    ' PWLX_CLIENT_CREDENTIALS_INFO_V1_0 pCred
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(WINAPI * PWLX_QUERY_IC_CREDENTIALS)(
'    PWLX_CLIENT_CREDENTIALS_INFO_V1_0 pCred
'    );

'FUNCTION WLX_QUERY_IC_CREDENTIALS ( _
'   BYREF pCred AS WLX_CLIENT_CREDENTIALS_INFO_V1_0 _    ' PWLX_CLIENT_CREDENTIALS_INFO_V1_0 pCred
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(WINAPI * PWLX_QUERY_TS_LOGON_CREDENTIALS)(
'    PWLX_CLIENT_CREDENTIALS_INFO_V2_0 pCred
'    );

'FUNCTION WLX_QUERY_TS_LOGON_CREDENTIALS ( _
'   BYREF pCred AS WLX_CLIENT_CREDENTIALS_INFO_V2_0 _    ' PWLX_CLIENT_CREDENTIALS_INFO_V2_0 pCred
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(WINAPI * PWLX_DISCONNECT)(
'    );

'FUNCTION WLX_DISCONNECT ( _
' ) AS LONG                                              ' BOOL

'typedef DWORD
'(WINAPI * PWLX_QUERY_TERMINAL_SERVICES_DATA)(
'    HANDLE hWlx,
'    PWLX_TERMINAL_SERVICES_DATA pTSData,
'    WCHAR * UserName,
'    WCHAR * Domain
'    );

'FUNCTION WLX_QUERY_TERMINAL_SERVICES_DATA ( _
'   BYVAL hWlx AS DWORD _                                ' HANDLE hWlx
' , BYREF WLX_TERMINAL_SERVICES_DATA _                   ' PWLX_TERMINAL_SERVICES_DATA pTSData
' , BYREF UserName AS WSTRINGZ _                         ' WCHAR * UserName
' , BYREF Domain AS WSTRINGZ _                           ' WCHAR * Domain
' ) AS DWORD                                             ' DWORD

'typedef DWORD
'(WINAPI * PWLX_QUERY_CONSOLESWITCH_CREDENTIALS)(
'      PWLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0 pCred
'     );

'FUNCTION WLX_QUERY_CONSOLESWITCH_CREDENTIALS ( _
'   BYREF pCred AS WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0 _  ' PWLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0 pCred
' ) AS DWORD                                                  ' DWORD

'FUNCTION WLX_QUERY_CONSOLESWITCH_CREDENTIALS ( _
'   BYREF pCred AS WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0 _  ' PWLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0 pCred
' ) AS DWORD                                                  ' DWORD

''//
''// Options that can be get or set:
''//

%WLX_OPTION_USE_CTRL_ALT_DEL   = &H00000001???
%WLX_OPTION_CONTEXT_POINTER    = &H00000002???
%WLX_OPTION_USE_SMART_CARD     = &H00000003???
%WLX_OPTION_FORCE_LOGOFF_TIME  = &H00000004???
%WLX_OPTION_IGNORE_AUTO_LOGON  = &H00000008???
%WLX_OPTION_NO_SWITCH_ON_SAS   = &H00000009???

'//
'// Options that can be queried only:
'//

%WLX_OPTION_SMART_CARD_PRESENT  = &H00010001???
%WLX_OPTION_SMART_CARD_INFO     = &H00010002???
%WLX_OPTION_DISPATCH_TABLE_SIZE = &H00010003???


'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//  Function dispatch tables.                                         //
'//  One of the following tables will be passed to the GINA DLL        //
'//  in the WlxInitialize() call during initialization.                //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

' // Size = 52 bytes
TYPE WLX_DISPATCH_VERSION_1_0 DWORD
   WlxUseCtrlAltDel           AS DWORD  ' PWLX_USE_CTRL_ALT_DEL
   WlxSetContextPointer       AS DWORD  ' PWLX_SET_CONTEXT_POINTER
   WlxSasNotify               AS DWORD  ' PWLX_SAS_NOTIFY
   WlxSetTimeout              AS DWORD  ' PWLX_SET_TIMEOUT
   WlxAssignShellProtection   AS DWORD  ' PWLX_ASSIGN_SHELL_PROTECTION
   WlxMessageBox              AS DWORD  ' PWLX_MESSAGE_BOX
   WlxDialogBox               AS DWORD  ' PWLX_DIALOG_BOX
   WlxDialogBoxParam          AS DWORD  ' PWLX_DIALOG_BOX_PARAM
   WlxDialogBoxIndirect       AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT
   WlxDialogBoxIndirectParam  AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT_PARAM
   WlxSwitchDesktopToUser     AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_USER
   WlxSwitchDesktopToWinlogon AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_WINLOGON
   WlxChangePasswordNotify    AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY
END TYPE

' // Size = 68 bytes
TYPE WLX_DISPATCH_VERSION_1_1 DWORD
   WlxUseCtrlAltDel           AS DWORD  ' PWLX_USE_CTRL_ALT_DEL
   WlxSetContextPointer       AS DWORD  ' PWLX_SET_CONTEXT_POINTER
   WlxSasNotify               AS DWORD  ' PWLX_SAS_NOTIFY
   WlxSetTimeout              AS DWORD  ' PWLX_SET_TIMEOUT
   WlxAssignShellProtection   AS DWORD  ' PWLX_ASSIGN_SHELL_PROTECTION
   WlxMessageBox              AS DWORD  ' PWLX_MESSAGE_BOX
   WlxDialogBox               AS DWORD  ' PWLX_DIALOG_BOX
   WlxDialogBoxParam          AS DWORD  ' PWLX_DIALOG_BOX_PARAM
   WlxDialogBoxIndirect       AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT
   WlxDialogBoxIndirectParam  AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT_PARAM
   WlxSwitchDesktopToUser     AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_USER
   WlxSwitchDesktopToWinlogon AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_WINLOGON
   WlxChangePasswordNotify    AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY
   WlxGetSourceDesktop        AS DWORD  ' PWLX_GET_SOURCE_DESKTOP
   WlxSetReturnDesktop        AS DWORD  ' PWLX_SET_RETURN_DESKTOP
   WlxCreateUserDesktop       AS DWORD  ' PWLX_CREATE_USER_DESKTOP
   WlxChangePasswordNotifyEx  AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY_EX
END TYPE

' // Size = 72 bytes
TYPE WLX_DISPATCH_VERSION_1_2 DWORD
   WlxUseCtrlAltDel           AS DWORD  ' PWLX_USE_CTRL_ALT_DEL
   WlxSetContextPointer       AS DWORD  ' PWLX_SET_CONTEXT_POINTER
   WlxSasNotify               AS DWORD  ' PWLX_SAS_NOTIFY
   WlxSetTimeout              AS DWORD  ' PWLX_SET_TIMEOUT
   WlxAssignShellProtection   AS DWORD  ' PWLX_ASSIGN_SHELL_PROTECTION
   WlxMessageBox              AS DWORD  ' PWLX_MESSAGE_BOX
   WlxDialogBox               AS DWORD  ' PWLX_DIALOG_BOX
   WlxDialogBoxParam          AS DWORD  ' PWLX_DIALOG_BOX_PARAM
   WlxDialogBoxIndirect       AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT
   WlxDialogBoxIndirectParam  AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT_PARAM
   WlxSwitchDesktopToUser     AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_USER
   WlxSwitchDesktopToWinlogon AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_WINLOGON
   WlxChangePasswordNotify    AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY
   WlxGetSourceDesktop        AS DWORD  ' PWLX_GET_SOURCE_DESKTOP
   WlxSetReturnDesktop        AS DWORD  ' PWLX_SET_RETURN_DESKTOP
   WlxCreateUserDesktop       AS DWORD  ' PWLX_CREATE_USER_DESKTOP
   WlxChangePasswordNotifyEx  AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY_EX
   WlxCloseUserDesktop        AS DWORD  ' PWLX_CLOSE_USER_DESKTOP
END TYPE

' // Size = 100 bytes
TYPE WLX_DISPATCH_VERSION_1_3 DWORD
   WlxUseCtrlAltDel                 AS DWORD  ' PWLX_USE_CTRL_ALT_DEL
   WlxSetContextPointer             AS DWORD  ' PWLX_SET_CONTEXT_POINTER
   WlxSasNotify                     AS DWORD  ' PWLX_SAS_NOTIFY
   WlxSetTimeout                    AS DWORD  ' PWLX_SET_TIMEOUT
   WlxAssignShellProtection         AS DWORD  ' PWLX_ASSIGN_SHELL_PROTECTION
   WlxMessageBox                    AS DWORD  ' PWLX_MESSAGE_BOX
   WlxDialogBox                     AS DWORD  ' PWLX_DIALOG_BOX
   WlxDialogBoxParam                AS DWORD  ' PWLX_DIALOG_BOX_PARAM
   WlxDialogBoxIndirect             AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT
   WlxDialogBoxIndirectParam        AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT_PARAM
   WlxSwitchDesktopToUser           AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_USER
   WlxSwitchDesktopToWinlogon       AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_WINLOGON
   WlxChangePasswordNotify          AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY
   WlxGetSourceDesktop              AS DWORD  ' PWLX_GET_SOURCE_DESKTOP
   WlxSetReturnDesktop              AS DWORD  ' PWLX_SET_RETURN_DESKTOP
   WlxCreateUserDesktop             AS DWORD  ' PWLX_CREATE_USER_DESKTOP
   WlxChangePasswordNotifyEx        AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY_EX
   WlxCloseUserDesktop              AS DWORD  ' PWLX_CLOSE_USER_DESKTOP
   WlxSetOption                     AS DWORD  ' PWLX_SET_OPTION
   WlxGetOption                     AS DWORD  ' PWLX_GET_OPTION
   WlxWin31Migrate                  AS DWORD  ' PWLX_WIN31_MIGRATE
   WlxQueryClientCredentials        AS DWORD  ' PWLX_QUERY_CLIENT_CREDENTIALS
   WlxQueryInetConnectorCredentials AS DWORD  ' PWLX_QUERY_IC_CREDENTIALS
   WlxDisconnect                    AS DWORD  ' PWLX_DISCONNECT
   WlxQueryTerminalServicesData     AS DWORD  ' PWLX_QUERY_TERMINAL_SERVICES_DATA
END TYPE

' // Size = 108 bytes
TYPE WLX_DISPATCH_VERSION_1_4 DWORD
   WlxUseCtrlAltDel                 AS DWORD  ' PWLX_USE_CTRL_ALT_DEL
   WlxSetContextPointer             AS DWORD  ' PWLX_SET_CONTEXT_POINTER
   WlxSasNotify                     AS DWORD  ' PWLX_SAS_NOTIFY
   WlxSetTimeout                    AS DWORD  ' PWLX_SET_TIMEOUT
   WlxAssignShellProtection         AS DWORD  ' PWLX_ASSIGN_SHELL_PROTECTION
   WlxMessageBox                    AS DWORD  ' PWLX_MESSAGE_BOX
   WlxDialogBox                     AS DWORD  ' PWLX_DIALOG_BOX
   WlxDialogBoxParam                AS DWORD  ' PWLX_DIALOG_BOX_PARAM
   WlxDialogBoxIndirect             AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT
   WlxDialogBoxIndirectParam        AS DWORD  ' PWLX_DIALOG_BOX_INDIRECT_PARAM
   WlxSwitchDesktopToUser           AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_USER
   WlxSwitchDesktopToWinlogon       AS DWORD  ' PWLX_SWITCH_DESKTOP_TO_WINLOGON
   WlxChangePasswordNotify          AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY
   WlxGetSourceDesktop              AS DWORD  ' PWLX_GET_SOURCE_DESKTOP
   WlxSetReturnDesktop              AS DWORD  ' PWLX_SET_RETURN_DESKTOP
   WlxCreateUserDesktop             AS DWORD  ' PWLX_CREATE_USER_DESKTOP
   WlxChangePasswordNotifyEx        AS DWORD  ' PWLX_CHANGE_PASSWORD_NOTIFY_EX
   WlxCloseUserDesktop              AS DWORD  ' PWLX_CLOSE_USER_DESKTOP
   WlxSetOption                     AS DWORD  ' PWLX_SET_OPTION
   WlxGetOption                     AS DWORD  ' PWLX_GET_OPTION
   WlxWin31Migrate                  AS DWORD  ' PWLX_WIN31_MIGRATE
   WlxQueryClientCredentials        AS DWORD  ' PWLX_QUERY_CLIENT_CREDENTIALS
   WlxQueryInetConnectorCredentials AS DWORD  ' PWLX_QUERY_IC_CREDENTIALS
   WlxDisconnect                    AS DWORD  ' PWLX_DISCONNECT
   WlxQueryTerminalServicesData     AS DWORD  ' PWLX_QUERY_TERMINAL_SERVICES_DATA
   WlxQueryConsoleSwitchCredentials AS DWORD  ' PWLX_QUERY_CONSOLESWITCH_CREDENTIALS
   WlxQueryTsLogonCredentials       AS DWORD  ' PWLX_QUERY_TS_LOGON_CREDENTIALS
END TYPE

'//
'// Non-GINA notification DLLs
'//

'typedef DWORD (*PFNMSGECALLBACK)(BOOL bVerbose, LPWSTR lpMessage);
'FUNCTION FNMSGECALLBACK (BYVAL bVerbose AS LONG, BYREF lpMessage AS WSTRINGZ) AS DWORD

' // Size = 32 bytes
TYPE WLX_NOTIFICATION_INFO DWORD
   Size            AS DWORD          ' ULONG
   Flags           AS DWORD          ' ULONG
   UserName        AS WSTRINGZ PTR   ' PWSTR
   Domain          AS WSTRINGZ PTR   ' PWSTR
   WindowStation   AS WSTRINGZ PTR   ' PWSTR
   hToken          AS DWORD          ' HANDLE
   hDesktop        AS DWORD          ' HDESK
   pStatusCallback AS DWORD          ' PFNMSGECALLBACK
END TYPE
