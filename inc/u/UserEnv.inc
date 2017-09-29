' ########################################################################################
' Microsoft Windows
' File: UserEnv.inc
' Contents: Header file for user environment API.
' User Profiles, environment variables, and Group Policy
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%USERENV_INC = 1

#INCLUDE ONCE "windows.inc"

#IF NOT %DEF(%WINVER)
%WINVER = &H0601  ' Assume Windows 7
#ENDIF

#INCLUDE ONCE "wbemcli.inc"
#INCLUDE ONCE "oaidl.inc"   ' for SAFEARRAY

'//=============================================================================
'//
'// LoadUserProfile
'//
'// Loads the specified user's profile.
'//
'// Most applications should not need to use this function.  It's used
'// when a user has logged onto the system or a service starts in a named
'// user account.
'//
'// hToken        - Token for the user, returned from LogonUser()
'// lpProfileInfo - Address of a PROFILEINFO structure
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:  The caller of this function must have admin privileges on the machine.
'//
'//        Upon successful return, the hProfile member of the PROFILEINFO
'//        structure is a registry key handle opened to the root
'//        of the user's hive.  It has been opened with full access. If
'//        you need to read or write to the user's registry file, use
'//        this key instead of HKEY_CURRENT_USER.  Do not close this
'//        handle.  Instead pass it to UnloadUserProfile to close
'//        the handle.
'//
'//=============================================================================

#INCLUDE ONCE "profinfo.inc"

%PI_NOUI         = &H00000001???     ' // Prevents displaying of messages
%PI_APPLYPOLICY  = &H00000002???     ' // Apply NT4 style policy

DECLARE FUNCTION LoadUserProfileA IMPORT "USERENV.DLL" ALIAS "LoadUserProfileA" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYREF lpProfileInfo AS PROFILEINFOA _                ' __inout LPPROFILEINFOA lpProfileInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LoadUserProfileW IMPORT "USERENV.DLL" ALIAS "LoadUserProfileW" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYREF lpProfileInfo AS PROFILEINFOW _                ' __inout LPPROFILEINFOW lpProfileInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LoadUserProfile = LoadUserProfileW
#ELSE
   MACRO LoadUserProfile = LoadUserProfileA
#ENDIF

'//=============================================================================
'//
'// UnloadUserProfile
'//
'// Unloads a user's profile that was loaded by LoadUserProfile()
'//
'// hToken        -  Token for the user, returned from LogonUser()
'// hProfile      -  hProfile member of the PROFILEINFO structure
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     The caller of this function must have admin privileges on the machine.
'//
'//=============================================================================

DECLARE FUNCTION UnloadUserProfile IMPORT "USERENV.DLL" ALIAS "UnloadUserProfile" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYVAL hProfile AS DWORD _                            ' __in HANDLE hProfile
 ) AS LONG                                              ' BOOL

'//=============================================================================
'//
'// GetProfilesDirectory
'//
'// Returns the path to the root of where all user profiles are stored.
'//
'// lpProfilesDir  -  Receives the path
'// lpcchSize      -  Size of lpProfilesDir
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     If lpProfilesDir is not large enough or NULL, the function will fail,
'//           and lpcchSize will contain the necessary buffer size.
'//
'// Example return value: C:\Users
'//
'//=============================================================================

DECLARE FUNCTION GetProfilesDirectoryA IMPORT "USERENV.DLL" ALIAS "GetProfilesDirectoryA" ( _
   BYREF lpProfilesDir AS ASCIIZ _                      ' __out LPSTR lpProfilesDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProfilesDirectoryW IMPORT "USERENV.DLL" ALIAS "GetProfilesDirectoryW" ( _
   BYREF lpProfilesDir AS WSTRINGZ _                    ' __out LPWSTR lpProfilesDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetProfilesDirectory = GetProfilesDirectoryW
#ELSE
   MACRO GetProfilesDirectory = GetProfilesDirectoryA
#ENDIF

'//=============================================================================
'//
'//  GetProfileType()
'//
'//  Returns the type of the profile that is loaded for a user.
'//
'//  dwFlags   - Returns the profile flags
'//
'//  Return:     TRUE if successful
'//              FALSE if an error occurs. Call GetLastError for more details
'//
'//  Comments:   if profile is not already loaded the function will return an error.
'//              The caller needs to have access to HKLM part of the registry.
'//              (exists by default)
'//
'//=============================================================================

#IF %WINVER >= &H0500

'//
'// Flags that can be set in the dwFlags field
'//

%PT_TEMPORARY         = &H00000001???     ' // A profile has been allocated that will be deleted at logoff.
%PT_ROAMING           = &H00000002???     ' // The loaded profile is a roaming profile.
%PT_MANDATORY         = &H00000004???     ' // The loaded profile is mandatory.

DECLARE FUNCTION GetProfileType IMPORT "USERENV.DLL" ALIAS "GetProfileType" ( _
   BYREF dwFlags AS DWORD _                             ' __out DWORD *dwFlags
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'//  DeleteProfile()
'//
'//  Deletes the profile and all other user related settings from the machine
'//
'//  lpSidString    - String form of the user sid.
'//  lpProfilePath  - ProfilePath (if Null, lookup in the registry)
'//  lpComputerName - Computer Name from which profile has to be deleted
'//
'//  Return:     TRUE if successful
'//              FALSE if an error occurs. Call GetLastError for more details
'//
'//  Comments:   Deletes the profile directory, registry and appmgmt stuff
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION DeleteProfileA IMPORT "USERENV.DLL" ALIAS "DeleteProfileA" ( _
   BYREF lpSidString AS ASCIIZ _                        ' __in LPCSTR lpSidString
 , OPTIONAL BYREF lpProfilePath AS ASCIIZ _             ' __in_opt LPCSTR lpProfilePath
 , OPTIONAL BYREF lpComputerName AS ASCIIZ _            ' __in_opt LPCSTR lpComputerName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteProfileW IMPORT "USERENV.DLL" ALIAS "DeleteProfileW" ( _
   BYREF lpSidString AS WSTRINGZ _                      ' __in LPCWSTR lpSidString
 , OPTIONAL BYREF lpProfilePath AS WSTRINGZ _           ' __in_opt LPCWSTR lpProfilePath
 , OPTIONAL BYREF lpComputerName AS WSTRINGZ _          ' __in_opt LPCWSTR lpComputerName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteProfile = DeleteProfileW
#ELSE
   MACRO DeleteProfile = DeleteProfileA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */


'//=============================================================================
'//
'//  CreateProfile()
'//
'//  Creating a user profile without loading it.
'//
'//  pszUserSid     - String form of the user sid.
'//  pszUserName    - Name of the user, used as the base name to create the
'//                   profile directory
'//  pszProfilePath - Returned full profile path
'//  cchProfilePath - Size of pszProfilePath buffer
'//
'//  Return:     S_OK : Successfully created the profile
'//              E_ACCESSDENIED : The caller does not have enough permission to
'//                     create the profile. The caller has to be administrators
'//                     in order for this API to succeed.
'//              HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS) : a profile is
'//                     already exists for the given user.
'//              Others : Standard HRESULT error codes.
'//
'//  Comments:
'//=============================================================================

#IF %WINVER >= &H0600

DECLARE FUNCTION CreateProfile IMPORT "USERENV.DLL" ALIAS "CreateProfile" ( _
   BYREF pszUserSid AS WSTRINGZ _                       ' __in LPCWSTR pszUserSid
 , BYREF pszUserName AS WSTRINGZ _                      ' __in LPCWSTR pszUserName
 , BYREF pszProfilePath AS WSTRINGZ _                   ' __in LPWSTR pszProfilePath
 , BYVAL cchProfilePath AS DWORD _                      ' __in DWORD cchProfilePath
 ) AS LONG                                              ' BOOL

#ENDIF ' /* WINVER >= 0x0600 */

'//=============================================================================
'//
'// GetDefaultUserProfilesDirectory
'//
'// Returns the path to the root of the default user profile
'//
'// lpProfileDir   -  Receives the path
'// lpcchSize      -  Size of lpProfileDir
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     If lpProfileDir is not large enough or NULL, the function will fail,
'//           and lpcchSize will contain the necessary buffer size.
'//
'// Example return value: C:\Users\Default
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION GetDefaultUserProfileDirectoryA IMPORT "USERENV.DLL" ALIAS "GetDefaultUserProfileDirectoryA" ( _
   BYREF lpProfileDir AS ASCIIZ _                       ' __out LPSTR lpProfileDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDefaultUserProfileDirectoryW IMPORT "USERENV.DLL" ALIAS "GetDefaultUserProfileDirectoryW" ( _
   BYREF lpProfileDir AS WSTRINGZ  _                    ' __out LPWSTR lpProfileDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetDefaultUserProfileDirectory = GetDefaultUserProfileDirectoryW
#ELSE
   MACRO GetDefaultUserProfileDirectory = GetDefaultUserProfileDirectoryA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// GetAllUsersProfilesDirectory
'//
'// Returns the path to the root of the All Users profile
'//
'// lpProfileDir   -  Receives the path
'// lpcchSize      -  Size of lpProfileDir
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     If lpProfileDir is not large enough or NULL, the function will fail,
'//           and lpcchSize will contain the necessary buffer size.
'//
'// Example return value: C:\Documents and Settings\All Users
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION GetAllUsersProfileDirectoryA IMPORT "USERENV.DLL" ALIAS "GetAllUsersProfileDirectoryA" ( _
   BYREF lpProfileDir AS ASCIIZ _                       ' __out LPSTR lpProfileDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetAllUsersProfileDirectoryW IMPORT "USERENV.DLL" ALIAS "GetAllUsersProfileDirectoryW" ( _
   BYREF lpProfileDir AS WSTRINGZ _                     ' __out LPWSTR lpProfileDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetAllUsersProfileDirectory = GetAllUsersProfileDirectoryW
#ELSE
   MACRO GetAllUsersProfileDirectory = GetAllUsersProfileDirectoryA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// GetUserProfileDirectory
'//
'// Returns the path to the root of the requested user's profile
'//
'// hToken         -  User's token returned from LogonUser()
'// lpProfileDir   -  Receives the path
'// lpcchSize      -  Size of lpProfileDir
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     If lpProfileDir is not large enough or NULL, the function will fail,
'//           and lpcchSize will contain the necessary buffer size.
'//
'// Example return value: C:\Users\Joe
'//
'//=============================================================================

DECLARE FUNCTION GetUserProfileDirectoryA IMPORT "USERENV.DLL" ALIAS "GetUserProfileDirectoryA" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE  hToken
 , BYREF lpProfileDir AS ASCIIZ _                       ' __out LPSTR lpProfileDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUserProfileDirectoryW IMPORT "USERENV.DLL" ALIAS "GetUserProfileDirectoryW" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE  hToken
 , BYREF lpProfileDir AS DWORD _                        ' __out LPSTR lpProfileDir
 , BYREF lpcchSize AS DWORD _                           ' __inout LPDWORD lpcchSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetUserProfileDirectory = GetUserProfileDirectoryW
#ELSE
   MACRO GetUserProfileDirectory = GetUserProfileDirectoryA
#ENDIF

'//=============================================================================
'//
'// CreateEnvironmentBlock
'//
'// Returns the environment variables for the specified user.  This block
'// can then be passed to CreateProcessAsUser().
'//
'// lpEnvironment  -  Receives a pointer to the new environment block
'// hToken         -  User's token returned from LogonUser() (optional, can be NULL)
'// bInherit       -  Inherit from the current process's environment block
'//                   or start from a clean state.
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     If hToken is NULL, the returned environment block will contain
'//           system variables only.
'//
'//           Call DestroyEnvironmentBlock to free the buffer when finished.
'//
'//           If this block is passed to CreateProcessAsUser, the
'//           CREATE_UNICODE_ENVIRONMENT flag must also be set.
'//
'//=============================================================================

DECLARE FUNCTION CreateEnvironmentBlock IMPORT "USERENV.DLL" ALIAS "CreateEnvironmentBlock" ( _
   BYREF lpEnvironment AS ANY _                         ' __out LPVOID *lpEnvironment
 , BYVAL hToken AS DWORD _                              ' __in HANDLE  hToken
 , BYVAL bInherit AS LONG _                             ' __in BOOL    bInherit
 ) AS LONG                                              ' BOOL

'//=============================================================================
'//
'// DestroyEnvironmentBlock
'//
'// Frees environment variables created by CreateEnvironmentBlock
'//
'// lpEnvironment  -  A pointer to the environment block
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'//=============================================================================

DECLARE FUNCTION DestroyEnvironmentBlock IMPORT "USERENV.DLL" ALIAS "DestroyEnvironmentBlock" ( _
   BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 ) AS LONG                                              ' BOOL

'//=============================================================================
'//
'// ExpandEnvironmentStringsForUser
'//
'// Expands the source string using the environment block for the
'// specified user.  If hToken is null, the system environment block
'// will be used (no user environment variables).
'//
'// hToken         -  User's token returned from LogonUser() (optional, can be NULL)
'// lpSrc          -  Pointer to the string with environment variables
'// lpDest         -  Buffer that receives the expanded string
'// dwSize         -  Size of lpDest in characters (max chars)
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:     If the user profile for hToken is not loaded, this api will fail.
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION ExpandEnvironmentStringsForUserA IMPORT "USERENV.DLL" ALIAS "ExpandEnvironmentStringsForUserA" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYREF lpSrc AS ASCIIZ _                              ' __in LPCSTR lpSrc
 , BYREF lpDest AS ASCIIZ _                             ' __out LPSTR lpDest
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ExpandEnvironmentStringsForUserW IMPORT "USERENV.DLL" ALIAS "ExpandEnvironmentStringsForUserW" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYREF lpSrc AS WSTRINGZ _                            ' __in LPCWSTR lpSrc
 , BYREF lpDest AS WSTRINGZ _                           ' __out LPWSTR lpDest
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ExpandEnvironmentStringsForUser = ExpandEnvironmentStringsForUserW
#ELSE
   MACRO ExpandEnvironmentStringsForUser = ExpandEnvironmentStringsForUserA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// RefreshPolicy()
'//
'// Causes group policy to be applied immediately on the client machine
'//
'// bMachine  -  Refresh machine or user policy
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION RefreshPolicy IMPORT "USERENV.DLL" ALIAS "RefreshPolicy" ( _
   BYVAL bMachine AS LONG _                             ' __in BOOL bMachine
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// RefreshPolicyEx()
'//
'// Causes group policy to be applied immediately on the client machine.
'//
'// bMachine  -  Refresh machine or user policy
'// dwOptions -  Option specifying the kind of refresh that needs to be done.
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'//=============================================================================

#IF %WINVER >= &H0500

%RP_FORCE            = 1     ' // Refresh policies without any optimisations.

DECLARE FUNCTION RefreshPolicyEx IMPORT "USERENV.DLL" ALIAS "RefreshPolicyEx" ( _
   BYVAL bMachine AS LONG _                             ' __in BOOL bMachine
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// EnterCriticalPolicySection
'//
'// Pauses the background application of group policy to allow safe
'// reading of the registry.  Applications that need to read multiple
'// policy entries and ensure that the values are not changed while reading
'// them should use this function.
'//
'// The maximum amount of time an application can hold a critical section
'// is 10 minutes.  After 10 minutes, policy can be applied again.
'//
'// bMachine -  Pause machine or user policy
'//
'// Returns:  Handle if successful
'//           NULL if not.  Call GetLastError() for more details
'//
'// Note 1:  The handle returned should be passed to LeaveCriticalPolicySection
'// when finished.  Do not close this handle, LeaveCriticalPolicySection
'// will do that.
'//
'// Note 2:  If both user and machine critical sections need to be acquired then
'// they should be done in this order: first acquire user critical section and
'// then acquire machine critical section.
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION EnterCriticalPolicySection IMPORT "USERENV.DLL" ALIAS "EnterCriticalPolicySection" ( _
   BYVAL bMachine AS LONG _                             ' __in BOOL bMachine
 ) AS DWORD                                             ' HANDLE

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// LeaveCriticalPolicySection
'//
'// Resumes the background application of group policy.  See
'// EnterCriticalPolicySection for more details.
'//
'// hSection - Handle returned from EnterCriticalPolicySection
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Call GetLastError() for more details
'//
'// Note:  This function will close the handle.
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION LeaveCriticalPolicySection IMPORT "USERENV.DLL" ALIAS "LeaveCriticalPolicySection" ( _
   BYVAL hSection AS DWORD _                            ' __in HANDLE hSection
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// RegisterGPNotification
'//
'// Entry point for registering for Group Policy change notification.
'//
'// Parameters: hEvent     -   Event to be notified, by calling SetEvent(hEvent)
'//             bMachine   -   If true, then register machine policy notification
'//                                     else register user policy notification
'//
'// Returns:    True if successful
'//             False if error occurs
'//
'// Notes:      Group Policy Notifications.  There are 2 ways an application can
'//             be notify when Group Policy is finished being applied.
'//
'//             1) Using the RegisterGPNotifcation function and waiting for the
'//                event to be signalled.
'//
'//             2) A WM_SETTINGCHANGE message is broadcast to all desktops.
'//                wParam - 1 if machine policy was applied, 0 if user policy was applied.
'//                lParam - Points to the string "Policy"
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION RegisterGPNotification IMPORT "USERENV.DLL" ALIAS "RegisterGPNotification" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL bMachine AS LONG _                             ' __in BOOL bMachine
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// UnregisterGPNotification
'//
'// Removes registration for a Group Policy change notification.
'//
'// Parameters: hEvent    -   Event to be removed
'//
'// Returns:    True if successful
'//             False if error occurs
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION UnregisterGPNotification IMPORT "USERENV.DLL" ALIAS "UnregisterGPNotification" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// GPOptions flags
'//
'// These are the flags found in the GPOptions property of a DS object
'//
'// For a given DS object (Site, Domain, OU), the GPOptions property
'// contains options that effect all the GPOs link to this SDOU.
'//
'// This is a DWORD type
'//
'//=============================================================================

#IF %WINVER >= &H0500

%GPC_BLOCK_POLICY        = &H00000001???  ' // Block all non-forced policy from above

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// GPLink flags
'//
'// These are the flags found on the GPLink property of a DS object after
'// the GPO path.
'//
'// For a given DS object (Site, Domain, OU), the GPLink property will
'// be in this text format
'//
'// [LDAP://CN={E615A0E3-C4F1-11D1-A3A7-00AA00615092},CN=Policies,CN=System,DC=mydomain,DC=Microsoft,DC=Com;1]
'//
'// The GUID is the GPO name, and the number following the LDAP path are the options
'// for that link from this DS object.  Note, there can be multiple GPOs
'// each in their own square brackets in a prioritized list.
'//
'//=============================================================================

#IF %WINVER >= &H0500

'//
'// Options for a GPO link
'//

%GPO_FLAG_DISABLE        = &H00000001???  ' // This GPO is disabled
%GPO_FLAG_FORCE          = &H00000002???  ' // Don't override the settings in
                                          ' // this GPO with settings from
                                          ' // a GPO below it.
#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// GetGPOList
'//
'//
'// Queries for the list of Group Policy Objects for the specified
'// user or machine.  This function will return a link list
'// of Group Policy Objects.  Call FreeGPOList to free the list.
'//
'// Note, most applications will not need to call this function.
'// This will primarily be used by services acting on behalf of
'// another user or machine.  The caller of this function will
'// need to look in each GPO for their specific policy
'//
'// This function can be called in two different ways.  Either the hToken for
'// a user or machine can be supplied and the correct name and domain
'// controller name will be generated, or hToken is NULL and the caller
'// must supply the name and the domain controller name.
'//
'// Calling this function with an hToken ensures the list of Group Policy
'// Objects is correct for the user or machine since security access checking
'// can be perfomed.  If hToken is not supplied, the security of the caller
'// is used instead which means that list may or may not be 100% correct
'// for the intended user / machine.  However, this is the fastest way
'// to call this function.
'//
'// hToken           - User or machine token, if NULL, lpName and lpHostName must be supplied
'// lpName           - User or machine name in DN format, if hToken is supplied, this must be NULL
'// lpHostName       - Domain DN name or domain controller name. If hToken is supplied, this must be NULL
'// lpComputerName   - Computer name to use to determine site location.  If NULL,
'//                    the local computer is used as the reference. Format:  \\machinename
'// dwFlags          - Flags field.  See flags definition below
'// pGPOList         - Address of a pointer which receives the link list of GPOs
'//
'//
'// Returns:  TRUE if successful
'//           FALSE if not.  Use GetLastError() for more details.
'//
'// Examples:
'//
'// Here's how this function will typically be called for
'// looking up the list of GPOs for a user:
'//
'//      LPGROUP_POLICY_OBJECT  pGPOList;
'//
'//      if (GetGPOList (hToken, NULL, NULL, NULL, 0, &pGPOList))
'//      {
'//          // do processing here...
'//          FreeGPOList (pGPOList);
'//      }
'//
'//
'// Here's how this function will typically be called for
'// looking up the list of GPOs for a machine:
'//
'//      LPGROUP_POLICY_OBJECT  pGPOList;
'//
'//      if (GetGPOList (NULL, lpMachineName, lpHostName, lpMachineName,
'//                      GPO_LIST_FLAG_MACHINE, &pGPOList))
'//      {
'//          // do processing here...
'//          FreeGPOList (pGPOList);
'//      }
'//
'//=============================================================================

#IF %WINVER >= &H0500

'//
'// Each Group Policy Object is associated (linked) with a site, domain,
'// organizational unit, or machine.
'//

' GPO_LINK enum
%GPLinkUnknown            = 0             ' // No link information available
%GPLinkMachine            = 1             ' // GPO linked to a machine (local or remote)
%GPLinkSite               = 2             ' // GPO linked to a site
%GPLinkDomain             = 3             ' // GPO linked to a domain
%GPLinkOrganizationalUnit = 4             ' // GPO linked to a organizational unit

' // Size = 100 bytes
TYPE GROUP_POLICY_OBJECTA DWORD FILL
   dwOptions     AS DWORD                      ' DWORD
   dwVersion     AS DWORD                      ' DWORD
   lpDSPath      AS ASCIIZ PTR                 ' LPSTR
   lpFileSysPath AS ASCIIZ PTR                 ' LPSTR
   lpDisplayName AS ASCIIZ PTR                 ' LPSTR
   szGPOName     AS ASCIIZ * 50                ' CHAR
   GPOLink       AS LONG                       ' GPOLINK
   lParam        AS LONG                       ' LPARAM
   pNext         AS GROUP_POLICY_OBJECTA PTR   ' struct _GROUP_POLICY_OBJECTA
   pPrev         AS GROUP_POLICY_OBJECTA PTR   ' struct _GROUP_POLICY_OBJECTA
   lpExtensions  AS ASCIIZ PTR                 ' LPSTR
   lParam2       AS LONG                       ' LPARAM
   lpLink        AS ASCIIZ PTR                 ' LPSTR
END TYPE

' // Size = 148 bytes
TYPE GROUP_POLICY_OBJECTW DWORD FILL
   dwOptions     AS DWORD                      ' DWORD
   dwVersion     AS DWORD                      ' DWORD
   lpDSPath      AS WSTRINGZ PTR               ' LPWSTR
   lpFileSysPath AS WSTRINGZ PTR               ' LPWSTR
   lpDisplayName AS WSTRINGZ PTR               ' LPWSTR
   szGPOName     AS WSTRINGZ * 50              ' WCHAR
   GPOLink       AS LONG                       ' GPOLINK
   lParam        AS LONG                       ' LPARAM
   pNext         AS GROUP_POLICY_OBJECTW PTR   ' struct _GROUP_POLICY_OBJECTW
   pPrev         AS GROUP_POLICY_OBJECTW PTR   ' struct _GROUP_POLICY_OBJECTW
   lpExtensions  AS WSTRINGZ PTR               ' LPWSTR
   lParam2       AS LONG                       ' LPARAM
   lpLink        AS WSTRINGZ PTR               ' LPWSTR
END TYPE

MACRO GROUP_POLICY_OBJECT = GROUP_POLICY_OBJECTA

'//
'// dwFlags for GetGPOList()
'//

%GPO_LIST_FLAG_MACHINE        = &H00000001???  ' // Return machine policy information
%GPO_LIST_FLAG_SITEONLY       = &H00000002???  ' // Return site policy information only
%GPO_LIST_FLAG_NO_WMIFILTERS  = &H00000004???  ' // Ignore WMI filters when filtering GPO's

DECLARE FUNCTION GetGPOListA IMPORT "USERENV.DLL" ALIAS "GetGPOListA" ( _
   BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYREF lpName AS ASCIIZ _                             ' __in_opt LPCSTR lpName
 , BYREF lpHostName AS ASCIIZ _                         ' __in_opt LPCSTR lpHostName
 , BYREF lpComputerName AS ASCIIZ _                     ' __in_opt LPCSTR lpComputerName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pGPOList AS GROUP_POLICY_OBJECTA _             ' __out PGROUP_POLICY_OBJECTA *pGPOList
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetGPOListW IMPORT "USERENV.DLL" ALIAS "GetGPOListW" ( _
   BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYREF lpName AS WSTRINGZ _                           ' __in_opt LPCWSTR lpName
 , BYREF lpHostName AS WSTRINGZ _                       ' __in_opt LPCWSTR lpHostName
 , BYREF lpComputerName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpComputerName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pGPOList AS GROUP_POLICY_OBJECTW _             ' __out PGROUP_POLICY_OBJECTA *pGPOList
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetGPOList = GetGPOListW
#ELSE
   MACRO GetGPOList = GetGPOListA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// FreeGPOList
'//
'//
'// Frees the linked list returned from GetGPOList
'//
'// pGPOList - Pointer to the linked list of GPOs
'//
'//
'// Returns:  TRUE if successful
'//           FALSE if not
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION FreeGPOListA IMPORT "USERENV.DLL" ALIAS "FreeGPOListA" ( _
   BYREF pGPOList AS GROUP_POLICY_OBJECTA _             ' __in PGROUP_POLICY_OBJECTA pGPOList
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FreeGPOListW IMPORT "USERENV.DLL" ALIAS "FreeGPOListW" ( _
   BYREF pGPOList AS GROUP_POLICY_OBJECTW _             ' __in PGROUP_POLICY_OBJECTW pGPOList
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FreeGPOList = FreeGPOListW
#ELSE
   MACRO FreeGPOList = FreeGPOListA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// GetAppliedGPOList
'//
'// Queries for the list of applied Group Policy Objects for the specified
'// user or machine and specified client side extension. This function will return
'// a linked list of Group Policy Objects.  Call FreeGPOList to free the list.
'//
'// dwFlags          - User or machine policy, if it is GPO_LIST_FLAG_MACHINE then
'//                    return machine policy information
'// pMachineName     - Name of remote computer in the form \\computername. If null
'//                    then local computer is used.
'// pSidUser         - Security id of user (relevant for user policy). If pMachineName is
'//                    null and pSidUser is null then it means current logged on user.
'//                    If pMachine is null and pSidUser is non-null then it means user
'//                    represented by pSidUser on local machine. If pMachineName is non-null
'//                    then and if dwFlags specifies user policy, then pSidUser must be
'//                    non-null.
'// pGuidExtension   - Guid of the specified extension
'// ppGPOList        - Address of a pointer which receives the link list of GPOs
'//
'// The return value is a Win32 error code. ERROR_SUCCESS means the GetAppliedGPOList
'// function completed successfully. Otherwise it indicates that the function failed.
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION GetAppliedGPOListA IMPORT "USERENV.DLL" ALIAS "GetAppliedGPOListA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pMachineName AS ASCIIZ _                       ' __in_opt LPCSTR pMachineName
 , BYVAL pSidUser AS SID PTR _                          ' __in_opt PSID pSidUser
 , BYREF pGuidExtension AS GUID _                       ' __in GUID *pGuidExtension
 , BYREF ppGPOList AS GROUP_POLICY_OBJECTA _            ' __out PGROUP_POLICY_OBJECTA *ppGPOList
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetAppliedGPOListW IMPORT "USERENV.DLL" ALIAS "GetAppliedGPOListW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pMachineName AS WSTRINGZ _                     ' __in_opt LPCWSTR pMachineName
 , BYVAL pSidUser AS SID PTR _                          ' __in_opt PSID pSidUser
 , BYREF pGuidExtension AS GUID _                       ' __in GUID *pGuidExtension
 , BYREF ppGPOList AS GROUP_POLICY_OBJECTW _            ' __out PGROUP_POLICY_OBJECTW *ppGPOList
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetAppliedGPOList = GetAppliedGPOListW
#ELSE
   MACRO GetAppliedGPOList = GetAppliedGPOListA
#ENDIF

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// Group Policy Object client side extension support
'//
'// Flags, data structures and function prototype
'//
'// To register your extension, create a subkey under this key
'//
'// Software\Microsoft\Windows NT\CurrentVersion\Winlogon\GPExtensions
'//
'// The subkey needs to be a guid so that it is unique. The noname value of the subkey
'// can be the friendly name of the extension. Then add these values:
'//
'//     DllName                      REG_EXPAND_SZ  Path to your DLL
'//     ProcessGroupPolicy           REG_SZ       Function name (see PFNPROCESSGROUPPOLICY prototype). This
'//                                                 is obsolete, it has been superseded by ProcessGroupPolicyEx.
'//                                                 It's here for backward compatibility reasons only.
'//     ProcessGroupPolicyEx         REG_SZ       Function name (see PFNPROCESSGROUPPOLICYEX prototype)
'//     GenerateGroupPolicy          REG_SZ       Function name for Rsop (see PFNGENERATEGROUPPOLICY prototype)
'//     NoMachinePolicy              REG_DWORD    True, if extension does not have to be called when
'//                                                 machine policies are being processed.
'//     NoUserPolicy                 REG_DWORD    True, if extension does not have to be called when
'//                                                 user policies are being processed.
'//     NoSlowLink                   REG_DWORD    True, if extension does not have to be called on a slow link
'//     NoBackgroundPolicy           REG_DWORD    True, if extension does not have to be called
'//                                                 for background policy processing.
'//     NoGPOListChanges             REG_DWORD    True, if extension does not have to be called when
'//                                                 there are no changes between cached and current GPO lists.
'//     PerUserLocalSettings         REG_DWORD    True, if user policies have to be cached on a per user and
'//                                                 per machine basis.
'//     RequiresSuccessfulRegistry   REG_DWORD    True, if extension should be called only if registry extension
'//                                                 was successfully processed.
'//     EnableAsynchronousProcessing REG_DWORD    True, if registry extension will complete its processing
'//                                                 asynchronously.
'//     NotifyLinkTransition         REG_DWORD    True, if extension should be called when a change in link
'//                                                 speed is detected between previous policy application and
'//                                                 current policy application.
'//
'// The return value is a Win32 error code. ERROR_SUCCESS means the ProcessGroupPolicy
'// function completed successfully. If return value is ERROR_OVERRIDE_NOCHANGES then it
'// means that the extension will be called the next time even if NoGPOListChanges is set
'// and there are no changes to the GPO list. Any other return value indicates that the
'// ProcessGroupPolicy or ProcessGroupPolicyEx function failed.
'//
'//=============================================================================

#IF %WINVER >= &H0500

'#define GP_DLLNAME                         TEXT("DllName")
'#define GP_ENABLEASYNCHRONOUSPROCESSING    TEXT("EnableAsynchronousProcessing")
'#define GP_MAXNOGPOLISTCHANGESINTERVAL     TEXT("MaxNoGPOListChangesInterval")
'#define GP_NOBACKGROUNDPOLICY              TEXT("NoBackgroundPolicy")
'#define GP_NOGPOLISTCHANGES                TEXT("NoGPOListChanges")
'#define GP_NOMACHINEPOLICY                 TEXT("NoMachinePolicy")
'#define GP_NOSLOWLINK                      TEXT("NoSlowLink")
'#define GP_NOTIFYLINKTRANSITION            TEXT("NotifyLinkTransition")
'#define GP_NOUSERPOLICY                    TEXT("NoUserPolicy")
'#define GP_PERUSERLOCALSETTINGS            TEXT("PerUserLocalSettings")
'#define GP_PROCESSGROUPPOLICY              TEXT("ProcessGroupPolicy")
'#define GP_REQUIRESSUCCESSFULREGISTRY      TEXT("RequiresSuccessfulRegistry")

$GP_DLLNAME                         = "DllName"
$GP_ENABLEASYNCHRONOUSPROCESSING    = "EnableAsynchronousProcessing"
$GP_MAXNOGPOLISTCHANGESINTERVAL     = "MaxNoGPOListChangesInterval"
$GP_NOBACKGROUNDPOLICY              = "NoBackgroundPolicy"
$GP_NOGPOLISTCHANGES                = "NoGPOListChanges"
$GP_NOMACHINEPOLICY                 = "NoMachinePolicy"
$GP_NOSLOWLINK                      = "NoSlowLink"
$GP_NOTIFYLINKTRANSITION            = "NotifyLinkTransition"
$GP_NOUSERPOLICY                    = "NoUserPolicy"
$GP_PERUSERLOCALSETTINGS            = "PerUserLocalSettings"
$GP_PROCESSGROUPPOLICY              = "ProcessGroupPolicy"
$GP_REQUIRESSUCCESSFULREGISTRY      = "RequiresSuccessfulRegistry"

%GPO_INFO_FLAG_MACHINE              = &H00000001???  ' // Apply machine policy rather than user policy
%GPO_INFO_FLAG_BACKGROUND           = &H00000010???  ' // Background refresh of policy (ok to do slow stuff)
%GPO_INFO_FLAG_SLOWLINK             = &H00000020???  ' // Policy is being applied across a slow link
%GPO_INFO_FLAG_VERBOSE              = &H00000040???  ' // Verbose output to the eventlog
%GPO_INFO_FLAG_NOCHANGES            = &H00000080???  ' // No changes were detected to the Group Policy Objects
%GPO_INFO_FLAG_LINKTRANSITION       = &H00000100???  ' // A change in link speed was detected between previous policy
                                                     ' // application and current policy application
%GPO_INFO_FLAG_LOGRSOP_TRANSITION   = &H00000200???  ' // A Change in Rsop Logging was detected between previous policy
                                                     ' // application and current policy application, (new intf only)
%GPO_INFO_FLAG_FORCED_REFRESH       = &H00000400???  ' // Forced Refresh is being applied. redo policies.
%GPO_INFO_FLAG_SAFEMODE_BOOT        = &H00000800???  ' // windows safe mode boot flag
%GPO_INFO_FLAG_ASYNC_FOREGROUND     = &H00001000???  ' // Asynchronous foreground refresh of policy
%GPO_INFO_FLAG_REPORT               = &H00002000???  ' Removed from Vista SDK // Report all settings for one GPO rather than the resultant settings across multiple GPOs

'typedef UINT_PTR ASYNCCOMPLETIONHANDLE;
'typedef DWORD (*PFNSTATUSMESSAGECALLBACK)(BOOL bVerbose, LPWSTR lpMessage);

'typedef DWORD(*PFNPROCESSGROUPPOLICY)(
'    __in DWORD dwFlags,                              // GPO_INFO_FLAGS
'    __in HANDLE hToken,                              // User or machine token
'    __in HKEY hKeyRoot,                              // Root of registry
'    __in PGROUP_POLICY_OBJECT  pDeletedGPOList,      // Linked list of deleted GPOs
'    __in PGROUP_POLICY_OBJECT  pChangedGPOList,      // Linked list of changed GPOs
'    __in ASYNCCOMPLETIONHANDLE pHandle,              // For asynchronous completion
'    __inout BOOL *pbAbort,                           // If true, then abort GPO processing
'    __in_opt PFNSTATUSMESSAGECALLBACK pStatusCallback);  // Callback function for displaying status messages
'                                                     // Note, this can be NULL

'typedef DWORD(*PFNPROCESSGROUPPOLICYEX)(
'    __in DWORD dwFlags,                              // GPO_INFO_FLAGS
'    __in HANDLE hToken,                              // User or machine token
'    __in HKEY hKeyRoot,                              // Root of registry
'    __in PGROUP_POLICY_OBJECT  pDeletedGPOList,      // Linked list of deleted GPOs
'    __in PGROUP_POLICY_OBJECT  pChangedGPOList,      // Linked list of changed GPOs
'    __in ASYNCCOMPLETIONHANDLE pHandle,              // For asynchronous completion
'    __inout BOOL *pbAbort,                           // If true, then abort GPO processing
'    __in_opt PFNSTATUSMESSAGECALLBACK pStatusCallback,   // Callback function for displaying status messages
'                                                     // Note, this can be NULL
'    __in_opt IWbemServices *pWbemServices,           // Pointer to namespace to log diagnostic mode data
'                                                     // Note, this will be NULL when Rsop logging is disabled
'    __out HRESULT *pRsopStatus);                     // RSOP Logging succeeded or not.

'typedef PVOID PRSOPTOKEN;

' // Size = 24 bytes
TYPE RSOP_TARGET DWORD
   pwszAccountName   AS WSTRINGZ PTR              ' WCHAR * // pwszAccountName // Account name
   pwszNewSOM        AS WSTRINGZ PTR              ' WCHAR * // New domain or OU location for account
   psaSecurityGroups AS SAFEARRAY PTR             ' SAFEARRAY * // New security groups
   pRsopToken        AS DWORD                     ' PRSOPTOKEN // Rsop token for use with Rsop security Api's
   pGPOList          AS GROUP_POLICY_OBJECT PTR   ' PGROUP_POLICY_OBJECT pGPOList // Linked list of GPOs
   pWbemServices     AS DWORD PTR                 ' IWbemServices * // Pointer to namespace to log planning mode data
END TYPE

'typedef DWORD(*PFNGENERATEGROUPPOLICY)(
'    __in DWORD dwFlags,                            // GPO_INFO_FLAGS
'    __inout BOOL  *pbAbort,                        // If true, then abort GPO processing
'    __in_opt WCHAR *pwszSite,                      // Site the target computer is in
'    __in_opt PRSOP_TARGET pComputerTarget,         // Computer target info, can be null
'    __in_opt PRSOP_TARGET pUserTarget );           // User target info, can be null

'//
'// GUID that identifies the registry extension
'//

'#define REGISTRY_EXTENSION_GUID  { 0x35378EAC, 0x683F, 0x11D2, 0xA8, 0x9A, 0x00, 0xC0, 0x4F, 0xBB, 0xCF, 0xA2 }
$REGISTRY_EXTENSION_GUID = GUID$("{35378EAC-683F-11D2-A89A-00C04FBBCFA2}")

'//
'// UBPM trigger provider and event GUIDs
'//
$GROUP_POLICY_TRIGGER_EVENT_PROVIDER_GUID = GUID$("{BD2F4252-5E1E-49FC-9A30-F3978AD89EE2}")
$MACHINE_POLICY_PRESENT_TRIGGER_GUID = GUID$("{659FCAE6-5BDB-4DA9-B1FF-CA2A178D46E0}")
$USER_POLICY_PRESENT_TRIGGER_GUID = GUID$("{54FB46C8-F089-464C-B1FD-59D1B62C3B50}")

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// Group Policy Object client side asynchronous extension processing
'//
'// extensionId    - Unique guid identifying the extension
'// pAsyncHandle   - Asynchronous completion handle that was passed to extension in
'//                  ProcessGroupPolicy call
'// dwStatus       - Completion status of asynchronous processing
'//
'// The return value is a Win32 error code. ERROR_SUCCESS means the ProcessGroupPolicyCompleted
'// function completed successfully. Otherwise it indicates that the function failed.
'//
'//=============================================================================

#IF %WINVER >= &H0500

'typedef GUID *REFGPEXTENSIONID;

DECLARE FUNCTION ProcessGroupPolicyCompleted IMPORT "USERENV.DLL" ALIAS "ProcessGroupPolicyCompleted" ( _
   BYVAL extensionId AS DWORD _                         ' __in REFGPEXTENSIONID extensionId
 , BYVAL pAsyncHandle AS DWORD _                        ' __in ASYNCCOMPLETIONHANDLE pAsyncHandle
 , BYVAL dwStatus AS DWORD _                            ' __in DWORD dwStatus
 ) AS DWORD                                             ' DWORD

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// Group Policy Object client side asynchronous extension processing
'//
'// extensionId    - Unique guid identifying the extension
'// pAsyncHandle   - Asynchronous completion handle that was passed to extension in
'//                  ProcessGroupPolicy call
'// dwStatus       - Completion status of asynchronous processing
'// RsopStatus     - RSoP Logging status
'//
'// The return value is a Win32 error code. ERROR_SUCCESS means the ProcessGroupPolicyCompleted
'// function completed successfully. Otherwise it indicates that the function failed.
'//
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION ProcessGroupPolicyCompletedEx IMPORT "USERENV.DLL" ALIAS "ProcessGroupPolicyCompletedEx" ( _
   BYVAL extensionId AS DWORD _                         ' __in REFGPEXTENSIONID extensionId
 , BYVAL pAsyncHandle AS DWORD _                        ' __in ASYNCCOMPLETIONHANDLE pAsyncHandle
 , BYVAL dwStatus AS DWORD _                            ' __in DWORD dwStatus
 , BYVAL RsopStatus AS LONG _                           ' __in HRESULT RsopStatus
 ) AS DWORD                                             ' DWORD

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// Function:    RsopAccessCheckByType
'//
'// Description: Determines whether the security descriptor pointed to by pSecurityDescriptor
'//                              grants the set of access rights specified in dwDesiredAccessMask
'//                              to the client identified by the RSOPTOKEN pointed to by pRsopToken.
'//
'// pSecurityDescriptor  - Security Descriptor on the object
'// pPrincipalSelfSid    - Principal Sid
'// pRsopToken           - Pointer to a valid RSOPTOKEN against which access needs to be checked
'// dwDesiredAccessMask  - Mask of requested generic and/or standard and or specific access rights
'// pObjectTypeList      - Object Type List
'// ObjectTypeListLength - Object Type List Length
'// pGenericMapping      - Generic Mapping
'// pPrivilegeSet        - privilege set
'// pdwPrivilegeSetLength- privilege set length
'// pdwGrantedAccessMask   - On success, if pbAccessStatus is true, it contains
'//                                         the mask of standard and specific rights granted.
'//                                         If pbAccessStatus is false, it is set to 0.
'//                                         On failure, it is not modified.
'// pbAccessStatus       - On success, indicates wether the requested set
'//                                    of access rights was granted.
'//                                    On failure, it is not modified
'//
'// Returns S_OK on success or appropriate error code.
'// For additional details, look at the documentation of AccessCheckByType
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION RsopAccessCheckByType IMPORT "USERENV.DLL" ALIAS "RsopAccessCheckByType" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL pPrincipalSelfSid AS SID PTR _                 ' __in_opt  PSID pPrincipalSelfSid
 , BYVAL pRsopToken AS DWORD _                          ' __in PRSOPTOKEN pRsopToken
 , BYVAL dwDesiredAccessMask AS DWORD _                 ' __in DWORD dwDesiredAccessMask
 , BYREF pObjectTypeList AS OBJECT_TYPE_LIST _          ' __in_opt POBJECT_TYPE_LIST pObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in DWORD ObjectTypeListLength
 , BYREF pGenericMapping AS GENERIC_MAPPING _           ' __in PGENERIC_MAPPING pGenericMapping
 , BYREF pPrivilegeSet AS PRIVILEGE_SET _               ' __in_opt PPRIVILEGE_SET pPrivilegeSet
 , BYVAL pdwPrivilegeSetLength AS DWORD _               ' __in_opt LPDWORD pdwPrivilegeSetLength
 , BYREF pdwGrantedAccessMask AS DWORD _                ' __out LPDWORD pdwGrantedAccessMask
 , BYREF pbAccessStatus AS LONG _                       ' __out LPBOOL pbAccessStatus
 ) AS LONG                                              ' HRESULT

#ENDIF   ' /* WINVER >= 0x0500 */

'//=============================================================================
'//
'// Function:    RsopFileAccessCheck
'//
'// Description: Determines whether the security descriptor on the file grants the set of file access
'//                              rights specified in dwDesiredAccessMask
'//                              to the client identified by the RSOPTOKEN pointed to by pRsopToken.
'//
'// pszFileName          - Name of an existing filename
'// pRsopToken           - Pointer to a valid RSOPTOKEN against which access needs to be checked
'// dwDesiredAccessMask  - Mask of requested generic and/or standard and or specific access rights
'// pdwGrantedAccessMask   - On success, if pbAccessStatus is true, it contains
'//                                         the mask of standard and specific rights granted.
'//                                         If pbAccessStatus is false, it is set to 0.
'//                                         On failure, it is not modified.
'// pbAccessStatus       - On success, indicates wether the requested set
'//                                    of access rights was granted.
'//                                    On failure, it is not modified
'//
'// Returns S_OK on success or appropriate error code
'//=============================================================================

#IF %WINVER >= &H0500

DECLARE FUNCTION RsopFileAccessCheck IMPORT "USERENV.DLL" ALIAS "RsopFileAccessCheck" ( _
   BYREF pszFileName AS WSTRINGZ _                      ' __in  LPWSTR pszFileName
 , BYVAL pRsopToken AS DWORD _                          ' __in  PRSOPTOKEN pRsopToken
 , BYVAL dwDesiredAccessMask AS DWORD _                 ' __in  DWORD dwDesiredAccessMask
 , BYREF pdwGrantedAccessMask AS DWORD _                ' __out LPDWORD pdwGrantedAccessMask
 , BYREF pbAccessStatus AS LONG _                       ' __out LPBOOL pbAccessStatus
 ) AS LONG                                              ' HRESULT

#ENDIF   ' /* WINVER >= 0x0500 */

' SETTINGSTATUS enum
%RSOPUnspecified      = 0
%RSOPApplied          = 1
%RSOPIgnored          = 2
%RSOPFailed           = 3
%RSOPSubsettingFailed = 4

'//=============================================================================
'//
'//  POLICYSETTINGSTATUSINFO
'//
'//  Describes the instance of RSOP_PolicySettingStatus
'//
'//  szKey               - OPTIONAL, if NULL, the key is generated on the fly
'//  szEventSource       - name of the source generation event log messages
'//  szEventLogName      - name of the event log database where the messages are logged
'//  dwEventID           - event log message ID
'//  status              - status of the policy setting
'//  timeLogged          - time at which the event log message was logged
'//
'//=============================================================================

' // Size = 40 bytes
TYPE POLICYSETTINGSTATUSINFO DWORD
   szKey          AS WSTRINGZ PTR   ' LPWSTR         szKey
   szEventSource  AS WSTRINGZ PTR   ' LPWSTR         szEventSource
   szEventLogName AS WSTRINGZ PTR   ' LPWSTR         szEventLogName
   dwEventID      AS DWORD          ' DWORD          dwEventID
   dwErrorCode    AS DWORD          ' DWORD          dwErrorCode
   status         AS LONG           ' SETTINGSTATUS  status
   timeLogged     AS SYSTEMTIME     ' SYSTEMTIME     timeLogged
END TYPE

'//=============================================================================
'//
'//  RsopSetPolicySettingStatus
'//
'//  Creates an instance of RSOP_PolicySettingStatus and RSOP_PolicySettingLink
'//  and links RSOP_PolicySettingStatus to RSOP_PolicySetting
'//
'//  dwFlags             - flags
'//  pServices           - RSOP namespace
'//  pSettingInstance    - instance of RSOP_PolicySetting or its children
'//  nInfo               - number of PolicySettingStatusInfo
'//  pStatus             - array of PolicySettingStatusInfo
'//
'//  Return:     S_OK if successful, HRESULT otherwise
'//
'//=============================================================================

DECLARE FUNCTION RsopSetPolicySettingStatus IMPORT "USERENV.DLL" ALIAS "RsopSetPolicySettingStatus" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pServices AS IWbemServices _                   ' __in IWbemServices* pServices
 , BYVAL pSettingInstance AS IWbemClassObject _         ' __in IWbemClassObject* pSettingInstance
 , BYVAL nInfo AS DWORD _                               ' __in DWORD nInfo
 , BYREF pStatus AS POLICYSETTINGSTATUSINFO _           ' __in POLICYSETTINGSTATUSINFO* pStatus
 ) AS LONG                                              ' HRESULT

'//=============================================================================
'//
'//  RsopResetPolicySettingStatus
'//
'//  Unlinks RSOP_PolicySettingStatus from RSOP_PolicySetting,
'//  deletes the instance of RSOP_PolicySettingStatus and RSOP_PolicySettingLink
'//  and optionally deletes the instance of RSOP_PolicySetting
'//
'//  dwFlags             - flags
'//  pServices           - RSOP namespace
'//  pSettingInstance    - instance of RSOP_PolicySetting or its children
'//
'//  Return:     S_OK if successful, HRESULT otherwise
'//
'//=============================================================================

DECLARE FUNCTION RsopResetPolicySettingStatus IMPORT "USERENV.DLL" ALIAS "RsopResetPolicySettingStatus" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pServices AS IWbemServices _                   ' __in IWbemServices* pServices
 , BYVAL pSettingInstance AS IWbemClassObject _         ' __in IWbemClassObject* pSettingInstance
 ) AS LONG                                              ' HRESULT

'//=============================================================================
'//
'// Flags for RSoP WMI providers
'//
'//=============================================================================

'// planning mode provider flags
%FLAG_NO_GPO_FILTER              = &H80000000???   ' // GPOs are not filtered, implies FLAG_NO_CSE_INVOKE
%FLAG_NO_CSE_INVOKE              = &H40000000???   ' // only GP processing done for planning mode
%FLAG_ASSUME_SLOW_LINK           = &H20000000???   ' // planning mode RSoP assumes slow link
%FLAG_LOOPBACK_MERGE             = &H10000000???   ' // planning mode RSoP assumes merge loop back
%FLAG_LOOPBACK_REPLACE           = &H08000000???   ' // planning mode RSoP assumes replace loop back

%FLAG_ASSUME_USER_WQLFILTER_TRUE = &H04000000???   ' // planning mode RSoP assumes all comp filters to be true
%FLAG_ASSUME_COMP_WQLFILTER_TRUE = &H02000000???   ' // planning mode RSoP assumes all user filters to be true

%FLAG_PLANNING_MODE              = &H01000000???   ' // flag that indicates that a given namespace was created
                                                   ' // for planning mode. This flag cannot be passed in but the
                                                   ' // relevant subnamespace will be marked with this flag

' // diagnostic mode provider flags
%FLAG_NO_USER                    = &H00000001???   ' // Don't get any user data
%FLAG_NO_COMPUTER                = &H00000002???   ' // Don't get any machine data
%FLAG_FORCE_CREATENAMESPACE      = &H00000004???
                                                   ' // Delete and recreate the namespace for this snapshot.

'//=============================================================================
'//
'// Extended Errors returned by RSoP WMI Providers
'//
'//=============================================================================

'// User accessing the rsop provider doesn't have access to user data.
%RSOP_USER_ACCESS_DENIED     = &H00000001???

'// User accessing the rsop provider doesn't have access to computer data.
%RSOP_COMPUTER_ACCESS_DENIED = &H00000002???

'// This user is an interactive non admin user, the temp snapshot namespace already exists
'// and the FLAG_FORCE_CREATENAMESPACE was not passed in
%RSOP_TEMPNAMESPACE_EXISTS   = &H00000004???
