' ########################################################################################
' Microsoft Windows
' File: AfxSid.inc
' Contents: SID wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXMISC_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "IPTypes.inc"
#INCLUDE ONCE "Sddl.inc"
#INCLUDE ONCE "LMCons.inc"

' ========================================================================================
' Retrieves the account name given it's SID.
' ========================================================================================
FUNCTION AfxGetAccountNameFromSid (BYVAL pSid AS SID PTR) AS WSTRING

   LOCAL bRes AS LONG

#IF %DEF(%USEPBDECL)
   IF IsValidSid(BYVAL pSid) = 0 THEN EXIT FUNCTION
#ELSE
   IF IsValidSid(pSid) = 0 THEN EXIT FUNCTION
#ENDIF
   ' // Retrieve the account name
   LOCAL bstrNameBuf AS WSTRING
   LOCAL cchName AS DWORD
   LOCAL wszReferencedDomainName AS WSTRINGZ * %MAX_DOMAIN_NAME_LEN
   LOCAL cchReferencedDomainName AS DWORD
   LOCAL peUse AS LONG

   ' // Get the length of the account name
#IF %DEF(%USEPBDECL)
   bRes = LookupAccountSidW("", BYVAL pSid, "", cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ELSE
   bRes = LookupAccountSidW("", pSid, "", cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ENDIF

   IF cchName THEN
      ' // Get the account name
      bstrNameBuf = SPACE$(cchName)
#IF %DEF(%USEPBDECL)
      bRes = LookupAccountSidW("", BYVAL pSid, BYVAL STRPTR(bstrNameBuf), cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ELSE
      bRes = LookupAccountSidW("", pSid, BYVAL STRPTR(bstrNameBuf), cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ENDIF
      IF bRes THEN FUNCTION = LEFT$(bstrNameBuf, cchName)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the account name given it's string SID.
' ========================================================================================
FUNCTION AfxGetAccountNameFromStringSid (BYVAL bstrSid AS WSTRING) AS WSTRING

   LOCAL bRes AS LONG

   ' // Convert the string SID to a SID
   LOCAL pSid AS SID PTR

   bRes = ConvertStringSidToSidW(BYCOPY bstrSid, pSid)
   IF bRes = 0 THEN EXIT FUNCTION
#IF %DEF(%USEPBDECL)
   IF IsValidSid(BYVAL pSid) = 0 THEN EXIT FUNCTION
#ELSE
   IF IsValidSid(pSid) = 0 THEN EXIT FUNCTION
#ENDIF
   ' // Retrieve the account name
   LOCAL bstrNameBuf AS WSTRING
   LOCAL cchName AS DWORD
   LOCAL wszReferencedDomainName AS WSTRINGZ * %MAX_DOMAIN_NAME_LEN
   LOCAL cchReferencedDomainName AS DWORD
   LOCAL peUse AS LONG

   ' // Get the length of the account name
#IF %DEF(%USEPBDECL)
   bRes = LookupAccountSidW("", BYVAL pSid, "", cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ELSE
   bRes = LookupAccountSidW("", pSid, "", cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ENDIF
   IF cchName THEN
      ' // Get the account name
      bstrNameBuf = SPACE$(cchName)
#IF %DEF(%USEPBDECL)
      bRes = LookupAccountSidW("", BYVAL pSid, BYVAL STRPTR(bstrNameBuf), cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ELSE
      bRes = LookupAccountSidW("", pSid, BYVAL STRPTR(bstrNameBuf), cchName, wszReferencedDomainName, cchReferencedDomainName, peUse)
#ENDIF
      IF bRes THEN FUNCTION = LEFT$(bstrNameBuf, cchName)
   END IF

   ' // Free the SID
   LocalFree pSid

END FUNCTION
' ========================================================================================

' ========================================================================================
' Looks up the user name and domain name for the user account associated with the calling thread.
' ========================================================================================
FUNCTION AfxGetCurrentUserAndDomain (BYREF bstrUser AS WSTRING, BYREF bstrDomain AS WSTRING) AS LONG

   LOCAL hToken AS DWORD
   LOCAL ptiUser AS TOKEN_USER PTR
   LOCAL cbti AS DWORD
   LOCAL snu AS LONG  ' SID_NAME_USE enumeration
   LOCAL wszUser AS WSTRINGZ * 256
   LOCAL wszDomain AS WSTRINGZ * %MAX_PATH

   ' // Get the calling thread's access token
   IF ISFALSE OpenThreadToken(GetCurrentThread, %TOKEN_QUERY, %TRUE, hToken) THEN
      IF GetLastError <> %ERROR_NO_TOKEN THEN
         FUNCTION = GetLastError
         EXIT FUNCTION
      END IF
      ' // Retry against process token if no thread token exists
      IF ISFALSE OpenProcessToken(GetCurrentProcess, %TOKEN_QUERY, hToken) THEN
         FUNCTION = GetLastError
         EXIT FUNCTION
      END IF
      ' // Obtain the size of the user information in the token
      IF GetTokenInformation(hToken, %TokenUser, BYVAL %NULL, 0, cbti) <> 0 THEN
         FUNCTION = GetLastError
         GOTO LExit
      END IF
      ' // Call should have failed due to zero-length buffer
      IF GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
         FUNCTION = GetLastError
         GOTO LExit
      END IF
      ' // Allocate buffer for user information in the token
      ptiUser = HeapAlloc(GetProcessHeap, %HEAP_GENERATE_EXCEPTIONS, cbti)
      IF ptiUser = %NULL THEN
         FUNCTION = %E_OUTOFMEMORY
         GOTO LExit
      END IF
      ' // Retrieve the user information from the token
      IF ISFALSE GetTokenInformation(hToken, %TokenUser, BYVAL ptiUser, cbti, cbti) THEN
         FUNCTION = GetLastError
         GOTO LExit
      END IF
      ' // Retrieve user name and domain name based on user's SID.
      IF ISFALSE LookupAccountSidW(BYVAL %NULL, BYVAL @ptiUser.User.Sid, wszUser, SIZEOF(wszUser), _
                 wszDomain, SIZEOF(wszDomain), snu) <> 0 THEN
         FUNCTION = GetLastError
         GOTO LExit
      END IF
      bstrUser = wszUser
      bstrDomain = wszDomain
   END IF

LExit:

   ' // Free resources
   IF hToken THEN CloseHandle(hToken)
   IF ptiUser THEN HeapFree(GetProcessHeap, 0, ptiUser)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Looks up the user name and domain name for the user account associated with the specified
' local process identifier.
' ========================================================================================
FUNCTION AfxGetUserNameAndDomainFromPid (BYVAL pid AS DWORD, BYREF bstrUser AS WSTRING, BYREF bstrDomain AS WSTRING) AS LONG

   LOCAL hProcess AS DWORD
   LOCAL hToken AS DWORD
   LOCAL ptiUser AS TOKEN_USER PTR
   LOCAL cbti AS DWORD
   LOCAL snu AS LONG  ' SID_NAME_USE enumeration
   LOCAL wszUser AS WSTRINGZ * 256
   LOCAL wszDomain AS WSTRINGZ * %MAX_PATH

   ' // Open the local process
   hProcess = OpenProcess(%PROCESS_ALL_ACCESS, %FALSE, pid)
   IF hProcess = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   ' // Get the access token associated with the process
   IF ISFALSE OpenProcessToken(hProcess, %TOKEN_QUERY, hToken) THEN
      FUNCTION = GetLastError
      GOTO LExit
   END IF
   ' // Obtain the size of the user information in the token
   IF GetTokenInformation(hToken, %TokenUser, BYVAL %NULL, 0, cbti) <> 0 THEN
      FUNCTION = GetLastError
      GOTO LExit
   END IF
   ' // Call should have failed due to zero-length buffer
   IF GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      FUNCTION = GetLastError
      GOTO LExit
   END IF
   ' // Allocate buffer for user information in the token
   ptiUser = HeapAlloc(GetProcessHeap, %HEAP_GENERATE_EXCEPTIONS, cbti)
   IF ptiUser = %NULL THEN
      FUNCTION = %E_OUTOFMEMORY
      GOTO LExit
   END IF
   ' // Retrieve the user information from the token
   IF ISFALSE GetTokenInformation(hToken, %TokenUser, BYVAL ptiUser, cbti, cbti) THEN
      FUNCTION = GetLastError
      GOTO LExit
   END IF
   ' // Retrieve user name and domain name based on user's SID.
   IF ISFALSE LookupAccountSidW(BYVAL %NULL, BYVAL @ptiUser.User.Sid, wszUser, SIZEOF(wszUser), _
              wszDomain, SIZEOF(wszDomain), snu) <> 0 THEN
      FUNCTION = GetLastError
      GOTO LExit
      EXIT FUNCTION
   END IF
   bstrUser = wszUser
   bstrDomain = wszDomain

LExit:

   ' // Free resources
   IF hProcess THEN CloseHandle(hProcess)
   IF hToken THEN CloseHandle(hToken)
   IF ptiUser THEN HeapFree(GetProcessHeap, 0, ptiUser)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the SID of an account given the account name.
' The returned pointer must be freed using LocalFree.
' ========================================================================================
FUNCTION AfxGetSidFromAccountName (BYVAL bstrAccountName AS WSTRING) AS DWORD

   ' // Retrieve the length of the SID
   LOCAL bRes AS LONG
   LOCAL cbSid AS DWORD
   LOCAL wszReferencedDomainName AS WSTRINGZ * %MAX_DOMAIN_NAME_LEN
   LOCAL cchReferencedDomainName AS DWORD
   LOCAL peUse AS LONG

   bRes = LookupAccountNameW("", BYVAL STRPTR(bstrAccountName), BYVAL %NULL, cbSid, BYVAL %NULL, %NULL, peUse)
   IF cbSid = 0 THEN EXIT FUNCTION

   ' // Retrieve the SID
   LOCAL pSid AS SID PTR
   pSid = LocalAlloc(0, cbSid)
   cchReferencedDomainName = SIZEOF(wszReferencedDomainName)
   bRes = LookupAccountNameW("", BYVAL STRPTR(bstrAccountName), BYVAL pSid, cbSid, _
                             wszReferencedDomainName, cchReferencedDomainName, peUse)
   IF bRes = 0 THEN
      LocalFree pSid
      EXIT FUNCTION
   END IF

   FUNCTION = pSid

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the SID of the user account.
' The returned pointer must be freed using LocalFree.
' ========================================================================================
FUNCTION AfxGetSidFromUserName () AS DWORD

   LOCAL bRes AS LONG
   LOCAL wszUserName AS WSTRINGZ * %UNLEN + 1
   LOCAL cbUserName AS DWORD
   LOCAL pSid AS SID PTR

   cbUserName = SIZEOF(wszUserName)
   bRes = GetUserNameW(wszUserName, cbUserName)
   IF bRes = 0 THEN EXIT FUNCTION
   wszUserName = LEFT$(wszUserName, cbUserName - 1)
   FUNCTION = AfxGetSidFromAccountName(wszUserName)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the SID of an account in a string format suitable for display, storage, or
' transmission. To convert the string-format SID back to a valid, functional SID, call the
' API function ConvertStringSidToSid function.
' ========================================================================================
FUNCTION AfxGetStringSidFromAccountName (BYVAL bstrAccountName AS WSTRING) AS WSTRING

   ' // Retrieve the length of the SID
   LOCAL bRes AS LONG
   LOCAL cbSid AS DWORD
   LOCAL szReferencedDomainName AS WSTRINGZ * %MAX_DOMAIN_NAME_LEN
   LOCAL cchReferencedDomainName AS DWORD
   LOCAL peUse AS LONG

   bRes = LookupAccountNameW("", BYVAL STRPTR(bstrAccountName), BYVAL %NULL, cbSid, BYVAL %NULL, %NULL, peUse)
   IF cbSid = 0 THEN EXIT FUNCTION

   ' // Retrieve the SID (we are using a string for the buffer because a SID is a
   ' // variable-length structure)
   LOCAL strSidBuf AS WSTRING

   strSidBuf = SPACE$(cbSid)
   cchReferencedDomainName = SIZEOF(szReferencedDomainName)
   bRes = LookupAccountNameW("", BYVAL STRPTR(bstrAccountName), BYVAL STRPTR(strSidBuf), cbSid, _
                            szReferencedDomainName, cchReferencedDomainName, peUse)
   IF bRes = 0 THEN EXIT FUNCTION

   ' // Convert the SID to a readable string format
   LOCAL pStringSid AS WSTRINGZ PTR
   IF IsValidSid(BYVAL STRPTR(strSidBuf)) THEN
      bRes = ConvertSidToStringSidW(BYVAL STRPTR(strSidBuf), pStringSid)
      IF bRes = 0 THEN
         EXIT FUNCTION
      ELSE
         FUNCTION = @pStringSid
         bRes = LocalFree(pStringSid)
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the SID of the user account in a string format suitable for display, storage,
' or transmission. To convert the string-format SID back to a valid, functional SID, call
' the API function ConvertStringSidToSid.
' ========================================================================================
FUNCTION AfxGetStringSidFromUserName () AS WSTRING

   LOCAL bRes AS LONG
   LOCAL wszUserName AS WSTRINGZ * %UNLEN + 1
   LOCAL cbUserName AS DWORD
   LOCAL pSid AS SID PTR

   cbUserName = SIZEOF(wszUserName)
   bRes = GetUserNameW(wszUserName, cbUserName)
   IF bRes = 0 THEN EXIT FUNCTION
   wszUserName = LEFT$(wszUserName, cbUserName - 1)
   FUNCTION = AfxGetStringSidFromAccountName(wszUserName)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests whether the current user is a member of the Administrator's group.
' Caller is NOT expected to be impersonating anyone and is expected to be able to
' open its own process and process token.
' See: http://msdn.microsoft.com/en-us/library/windows/desktop/aa376389%28v=vs.85%29.aspx
' Return Value:
'   TRUE - Caller has Administrators local group.
'   FALSE - Caller does not have Administrators local group.
' Note: Replacement for the Windows API function IsUserAnAdmin because Microsoft warns
' about the use of this function and advices to call CheckTokenMembership directly.
' ========================================================================================
FUNCTION AfxIsUserAnAdmin () AS LONG

   LOCAL IsMember AS LONG
   LOCAL NtAuthority AS SID_IDENTIFIER_AUTHORITY
   LOCAL AdministratorsGroup AS DWORD

   NtAuthority.Value = $SECURITY_NT_AUTHORITY
   IF AllocateAndInitializeSid(NtAuthority, 2, %SECURITY_BUILTIN_DOMAIN_RID, _
         %DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, AdministratorsGroup) = 0 THEN EXIT FUNCTION
   IF CheckTokenMembership(%NULL, BYVAL AdministratorsGroup, IsMember) <> 0 THEN
      FUNCTION = IsMember
   END IF
   FreeSid(BYVAL AdministratorsGroup)

END FUNCTION
' ========================================================================================
