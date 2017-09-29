' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryProviderHelper.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERYPROVIDERHELPER_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "objbase.inc"

CLASS CFDProviderHelper

   INSTANCE m_dwSessionId AS DWORD
   INSTANCE m_hToken AS DWORD
   INSTANCE srwTokenLock AS SRWLOCK

   CLASS METHOD Create
      m_hToken = 0
      m_dwSessionId = &HFFFFFFFF???
      InitializeSRWLock(srwTokenLock)
   END METHOD

   CLASS METHOD Destroy
      IF m_hToken <> %NULL THEN CloseHandle(m_hToken)
   END METHOD

   INTERFACE IFDProviderHelper

      INHERIT IUnknown

      ' /////////////////////////////////////////////////////////////////////////////
      ' // CoSetProxyBlanket
      ' //
      ' // Purpose:
      ' //    If the provider is running in a process that doesn't have permissions
      ' //    to call back into the client process by default then CoSetProxyBlanket
      ' //    must be called to enable impersonation.
      ' //    This function wraps the necessary calls and provides the correct CoSetProxyBlanket
      ' //    parameters in a single function.
      ' //
      ' // Arguments:
      ' //    pIUnk: Interface proxy to enable callbacks on
      ' //
      ' // Returns: S_OK on success, appropriate HRESULT otherwise

      METHOD CoSetProxyBlanket (BYVAL pIUnk AS IUnknown) AS LONG
         LOCAL hr AS LONG
         LOCAL pRealUnknown AS IUnknown
         LOCAL IID_IUnknown AS GUID
         hr = %S_OK
         IID_IUnknown = $IID_IUnknown

         ' // Try to see if it's a COM proxy.  If so, see if it's local to the process or a remote COM proxy.
         ' // If it's remote, set the proxy blanket
         LOCAL ulRpcOptions AS DWORD   ' ULONG_PTR
         ulRpcOptions = ME.GetRpcOptions(pIUnk)

         IF ulRpcOptions <> %SERVER_LOCALITY_PROCESS_LOCAL THEN
            hr = CoImpersonateClient
            IF hr = %S_OK THEN
               hr = pIUnk.QueryInterface(IID_IUnknown, BYVAL VARPTR(pRealUnknown))
               IF hr = %S_OK THEN
                  hr = CoSetProxyBlanket(pRealUnknown, %RPC_C_AUTHN_DEFAULT, %RPC_C_AUTHZ_NONE, %COLE_DEFAULT_PRINCIPAL, %RPC_C_AUTHN_LEVEL_DEFAULT, %RPC_C_IMP_LEVEL_IMPERSONATE, %NULL, %EOAC_STATIC_CLOAKING)
                  IF hr = %S_OK THEN
                     hr = CoSetProxyBlanket(pIUnk, %RPC_C_AUTHN_DEFAULT, %RPC_C_AUTHZ_NONE, %COLE_DEFAULT_PRINCIPAL, %RPC_C_AUTHN_LEVEL_DEFAULT, %RPC_C_IMP_LEVEL_IMPERSONATE, %NULL, %EOAC_STATIC_CLOAKING)
                  END IF
                  IF hr = %E_NOINTERFACE THEN
                     hr = %S_OK   ' // Provider can end up being inproc if we are in the fdPHost process.  Ignore error and try to proceed.
                  END IF
                  pRealUnknown.Release
               END IF
            END IF
            IF hr = %S_OK THEN
               hr = CoRevertToSelf
            ELSE
               CoRevertToSelf  ' // Don't want the return code
            END IF
         END IF

         METHOD = hr

      END METHOD

      ' /////////////////////////////////////////////////////////////////////////////
      ' // CoSetProxyBlanketWithThreadToken
      ' //
      ' // Purpose:
      ' //    If the provider is running in a process that doesn't have permissions
      ' //    to call back into the client process by default then CoSetProxyBlanket
      ' //    must be called to enable impersonation.
      ' //    This function wraps the necessary calls to CoSetProxyBlanket if the
      ' //    provider thread is from a thread pool instead of a thread called directly
      ' //    by FD.
      ' //    If you want to use this method you must call Initialize on the class instance.
      ' //    This is best done in IFunctionDiscoveryProvider::Initialize.
      ' //    Initialize must be called from one of the methods called by the client process.
      ' //
      ' // Arguments:
      ' //    pIUnk: Interface proxy to enable callbacks on
      ' //
      ' // Returns: S_OK on success, appropriate HRESULT otherwise

      METHOD CoSetProxyBlanketWithThreadToken (BYVAL pIUnk AS IUnknown) AS LONG

         IF m_hToken = %NULL THEN
            METHOD = %S_OK
            EXIT METHOD
         END IF

         LOCAL pRealUnknown AS IUnknown
         LOCAL hr AS LONG
         LOCAL IID_IUnknown AS GUID
         hr = %S_OK
         IID_IUnknown = $IID_IUnknown

         AcquireSRWLockShared(srwTokenLock)
         IF SetThreadToken(BYVAL %NULL, m_hToken) = %FALSE THEN
            hr = HRESULT_FROM_WIN32(GetLastError)
         END IF
         ReleaseSRWLockShared(srwTokenLock)

         IF hr = %S_OK THEN
            hr = pIUnk.QueryInterface(IID_IUnknown, BYVAL VARPTR(pRealUnknown))
            IF hr = %S_OK THEN
               hr = CoSetProxyBlanket(pRealUnknown, %RPC_C_AUTHN_DEFAULT, %RPC_C_AUTHZ_NONE, %COLE_DEFAULT_PRINCIPAL, %RPC_C_AUTHN_LEVEL_DEFAULT, %RPC_C_IMP_LEVEL_IMPERSONATE, %NULL, %EOAC_STATIC_CLOAKING)
               IF hr = %S_OK THEN
                  hr = CoSetProxyBlanket(pIUnk, %RPC_C_AUTHN_DEFAULT, %RPC_C_AUTHZ_NONE, %COLE_DEFAULT_PRINCIPAL, %RPC_C_AUTHN_LEVEL_DEFAULT, %RPC_C_IMP_LEVEL_IMPERSONATE, %NULL, %EOAC_STATIC_CLOAKING)
                  IF hr = %E_NOINTERFACE THEN
                     hr = %S_OK   ' // Provider can end up being inproc if we are in the fdPHost process.  Ignore error and try to proceed.
                  END IF
                  pRealUnknown.Release
               END IF
            END IF
         END IF
         IF SetThreadToken(BYVAL %NULL, %NULL) = %FALSE THEN
            IF hr = %S_OK THEN hr = HRESULT_FROM_WIN32(GetLastError)
         END IF

         METHOD = hr

      END METHOD

      ' /////////////////////////////////////////////////////////////////////////////
      ' // Initialize
      ' //
      ' // Purpose:
      ' //    If the provider is running in a process that doesn't have permissions
      ' //    to call back into the client process by default then CoSetProxyBlanket
      ' //    must be called to enable impersonation.
      ' //    CoSetProxyBlanketWithThreadToken wraps the calls necessary to do this.
      ' //    Before using that function you must call Initialize on the class instance.
      ' //    This is best done in IFunctionDiscoveryProvider::Initialize.
      ' //    Initialize must be called from one of the methods called by the client process.
      ' //
      ' //    Note:  There are three cases we we will not impersonate
      ' //    1. If the caller is Local System we will not impersonate and subsequent
      ' //       calls to CoSetProxyBlanketWithThreadToken will effectively noop
      ' //    2. Similary if the provider is actually running in-proc no proxy blanket
      ' //       is required and CoImpersonateClient will fail with:
      ' //          Code=0x80010117 (2147549463): RPC_E_CALL_COMPLETE: "Call context cannot be accessed after call completed."
      ' //          Severity=FAILURE; Code=279 (0x117); Facility=1 (0x1) (FACILITY_RPC)
      ' //       Handle this case gracefully and effectively noop on the
      ' //       CoSetProxyBlanketWithThreadToken as well.
      ' //    3. If we get an inproc proxy to the provider we detect that and subsequent
      ' //       calls to CoSetProxyBlanketWithThreadToken will effectively noop.
      ' //
      ' // Returns: S_OK on success, appropriate HRESULT otherwise

      METHOD Initialize (BYVAL pIUnk AS IUnknown) AS LONG

         IF m_hToken <> %NULL THEN
            METHOD = %S_FALSE
            EXIT METHOD
         END IF

         LOCAL LOCAL_SYSTEM_SID AS SID
         LOCAL_SYSTEM_SID.Revision = %SID_REVISION
         LOCAL_SYSTEM_SID.SubAuthorityCount = 1
         LOCAL_SYSTEM_SID.IdentifierAuthority.Value = CHR$(0,0,0,0,0,5)
         LOCAL_SYSTEM_SID.SubAuthority(0) = %SECURITY_LOCAL_SYSTEM_RID

         LOCAL hr AS LONG

         hr = CoImpersonateClient
         IF hr = %S_OK THEN
            LOCAL isLocalSystem AS LONG
            LOCAL isLocalCall AS LONG
            isLocalSystem = 0
            isLocalCall = (ME.GetRpcOptions(pIUnk) = %SERVER_LOCALITY_PROCESS_LOCAL)
            IF isLocalCall = %FALSE THEN
               IF CheckTokenMembership(%NULL, VARPTR(LOCAL_SYSTEM_SID), isLocalSystem) = %FALSE THEN
                  hr = HRESULT_FROM_WIN32(GetLastError)
               END IF
            END IF
            ' // Only save the impersonation info if
            ' // this is not a local call, and the caller is not System.
            IF hr = %S_OK AND isLocalCall = %FALSE AND isLocalSystem = %FALSE THEN
               AcquireSRWLockExclusive(srwTokenLock)
               IF OpenThreadToken(GetCurrentThread, %TOKEN_IMPERSONATE OR %TOKEN_QUERY, %FALSE, m_hToken) = %FALSE THEN
                  hr = HRESULT_FROM_WIN32(GetLastError)
               END IF
               IF hr = %S_OK THEN
                  LOCAL dwSizeReturned AS DWORD
                  IF GetTokenInformation(m_hToken, %TokenSessionId, m_dwSessionId, SIZEOF(m_dwSessionId), dwSizeReturned) = %FALSE THEN
                     hr = HRESULT_FROM_WIN32(GetLastError)
                  END IF
               END IF
               ReleaseSRWLockExclusive(srwTokenLock)
            END IF
            IF hr = %S_OK THEN
                hr = CoRevertToSelf
            ELSE
                CoRevertToSelf   ' // Don't want the return code
            END IF
         ELSEIF hr = %RPC_E_CALL_COMPLETE THEN
            hr = %S_OK   ' // InProc
         END IF

         METHOD = hr

      END METHOD

      METHOD ReleaseToken (OPTIONAL BYVAL dwSessionId AS DWORD) AS LONG

         AcquireSRWLockExclusive(srwTokenLock)
         IF m_hToken = %NULL THEN EXIT METHOD
         IF dwSessionId <> 0 AND dwSessionId <> m_dwSessionId THEN EXIT METHOD
         CloseHandle(m_hToken)
         m_hToken = %NULL
         ReleaseSRWLockExclusive(srwTokenLock)
         METHOD = %TRUE

      END METHOD

      ' /////////////////////////////////////////////////////////////////////////////
      ' // GetRpcOptions
      ' //
      ' // Purpose:
      ' //    Get the rpc options if this is a proxy.
      ' //
      ' // Arguments:
      ' //    pIUnk: Interface proxy.
      ' //
      ' // Returns: ULONG_PTR rpc options on success, assume it's inproc otherwise (SERVER_LOCALITY_PROCESS_LOCAL)
      METHOD GetRpcOptions (BYVAL pIUnk AS IUnknown) AS DWORD   ' ULONG_PTR
         LOCAL ulOptions AS DWORD   ' ULONG_PTR
         ulOptions = %SERVER_LOCALITY_PROCESS_LOCAL
         LOCAL pRpcOptions AS IRpcOptions
         LOCAL hr AS LONG
         LOCAL IID_IRpcOptions AS GUID
         IID_IRpcOptions = $IID_IRpcOptions
         hr = pIUnk.QueryInterface(IID_IRpcOptions, BYVAL VARPTR(pRpcOptions))
         IF hr = %S_OK THEN
            hr = pRpcOptions.Query(pIUnk, %COMBND_SERVER_LOCALITY, ulOptions)
            pRpcOptions.Release
         END IF
         METHOD = ulOptions
      END METHOD

   END INTERFACE

END CLASS
