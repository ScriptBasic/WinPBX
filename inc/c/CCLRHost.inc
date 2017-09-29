' ########################################################################################
' Microsoft Windows
' File: CCLRHost.inc
' Contents: Class to host the .NET Common Language Runtime (CLR).
' Copyright (c) 2011 José Roca.
' Portions Copyright (c) Microsoft Corporation.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CCLRHOST_INC = 1

' // Include files for exported files
#INCLUDE ONCE "mscoree.inc"
#INCLUDE ONCE "mscorlib.inc"
#INCLUDE ONCE "metahost.inc"

DECLARE FUNCTION Proto_CLRCreateInstance (BYREF rclsid AS GUID, BYREF riid AS GUID, BYREF ppInterface AS IUnknown) AS LONG
DECLARE FUNCTION Proto_CorBindToRuntimeEx (BYREF pwszVersion AS WSTRINGZ, BYREF pwszBuildFlavor AS WSTRINGZ, _
   BYVAL startupFlags AS DWORD, BYREF rclsid AS GUID, BYREF riid AS GUID, BYREF ppv AS IUnknown) AS LONG

' ########################################################################################
' CCLRHost Class
' ########################################################################################
CLASS CCLRHost

   INSTANCE m_pCorRuntimeHost AS ICorRuntimeHost
   INSTANCE m_pAppDomain AS SystemAppDomain

   ' =====================================================================================
   ' Stops the common language runtime and releases the interfaces.
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Stops execution of code in the runtime
      IF ISOBJECT(m_pCorRuntimeHost) THEN m_pCorRuntimeHost.Stop
      ' // Cleanup
      m_pAppDomain = NOTHING
      m_pCorRuntimeHost = NOTHING
   END METHOD
   ' =====================================================================================

   INTERFACE ICLRHost : INHERIT IAutomation

   ' =====================================================================================
   ' Loads the common language runtime (CLR) into a process and starts it.
   ' Note: CorBindToRuntimeEx has been deprecated in the .NET Framework version 4.
   ' =====================================================================================
   METHOD Init (OPTIONAL BYREF wszVersion AS WSTRINGZ, BYREF wszBuildFlavor AS WSTRINGZ, BYVAL startupFlags AS DWORD) AS ICorRuntimeHost
      LOCAL hr AS LONG
      LOCAL pUnk AS IUnknown
      ' // Create an instance of the ICorRuntimeHost interface
      LOCAL hLib AS DWORD
      hLib = LoadLibrary("MSCOREE.DLL")
      IF hLib = %NULL THEN EXIT METHOD
      LOCAL pProc AS DWORD
      pProc = GetProcAddress(hLib, "CorBindToRuntimeEx")
      IF ISTRUE pProc THEN
         CALL DWORD pProc USING Proto_CorBindToRuntimeEx(wszVersion, wszBuildFlavor, startupFlags, _
            $CLSID_CorRuntimeHost, $IID_ICorRuntimeHost, m_pCorRuntimeHost) TO hr
         IF hr <> %S_OK OR ISNOTHING(m_pCorRuntimeHost) THEN METHOD OBJRESULT = hr : EXIT METHOD
      END IF
      ' // Start the runtime (this also creates a default AppDomain)
      hr = m_pCorRuntimeHost.Start
      IF hr = %S_OK THEN
         ' // Get the default AppDomain
         hr = m_pCorRuntimeHost.GetDefaultDomain(pUnk)
         IF ISOBJECT(pUnk) THEN
            ' // Get a reference to the _IAppDomain interface
            m_pAppDomain = pUnk
            pUnk = NOTHING
         END IF
      END IF
      IF hr THEN METHOD OBJRESULT = hr
      METHOD = m_pCorRuntimeHost
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads the .NET Framework version 4 common language runtime (CLR) into a process and starts it.
   ' =====================================================================================
   METHOD InitCLR4 (OPTIONAL BYREF wszVersion AS WSTRINGZ) AS ICorRuntimeHost
      LOCAL hr AS LONG
      LOCAL pUnk AS IUnknown
      LOCAL pCLRMetaHost AS ICLRMetaHost
      LOCAL pRunTimeInfo AS ICLRRuntimeInfo
      LOCAL wszCLRVersion AS WSTRINGZ * 260
      ' // Create an instance of the ICLRMetaHost interface
      LOCAL hLib AS DWORD
      hLib = LoadLibrary("MSCOREE.DLL")
      IF hLib = %NULL THEN EXIT METHOD
      LOCAL pProc AS DWORD
      pProc = GetProcAddress(hLib, "CLRCreateInstance")
      IF ISTRUE pProc THEN
         CALL DWORD pProc USING Proto_CLRCreateInstance($CLSID_CLRMetaHost, $IID_ICLRMetaHost, pCLRMetaHost) TO hr
         IF hr <> %S_OK OR ISNOTHING(pCLRMetaHost) THEN METHOD OBJRESULT = hr : EXIT METHOD
      ELSE
         METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      END IF
      ' // Gets the ICLRRuntimeInfo interface that corresponds to a particular version of
      ' // the common language runtime (CLR). This method supersedes the CorBindToRuntimeEx
      ' // function used with the STARTUP_LOADER_SAFEMODE flag.
      IF VARPTR(wszVersion) = %NULL THEN wszCLRVersion = "v4.0.30319" ELSE wszCLRVersion = wszVersion
      pUnk = pCLRMetaHost.GetRuntime(wszCLRVersion, $IID_ICLRRuntimeInfo)
      IF OBJRESULT <> %S_OK OR ISNOTHING(pUnk) THEN METHOD OBJRESULT = OBJRESULT : EXIT METHOD
      pRunTimeInfo = pUnk
      pUnk = NOTHING
      ' // See if the runtime associated with this interface can be loaded into
      ' // the current process, taking into account other runtimes that might
      ' // already be loaded into the process.
      IF ISFALSE(pRunTimeInfo.IsLoadable) THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      ' // Loads the CLR into the current process and returns a reference to
      ' // the ICorRuntimeHost interface. ICorRuntimeHost works will all
      ' // versions of the .NET runtime.
      pUnk = pRunTimeInfo.GetInterface($CLSID_CorRuntimeHost, $IID_ICorRuntimeHost)
      IF OBJRESULT <> %S_OK OR ISNOTHING(pUnk) THEN METHOD OBJRESULT = OBJRESULT : EXIT METHOD
      m_pCorRuntimeHost = pUnk
      pUnk = NOTHING
      ' // Start the runtime (this also creates a default AppDomain)
      hr = m_pCorRuntimeHost.Start
      IF hr = %S_OK THEN
         ' // Get the default AppDomain
         hr = m_pCorRuntimeHost.GetDefaultDomain(pUnk)
         IF ISOBJECT(pUnk) THEN
            ' // Get a reference to the IAppDomain interface
            m_pAppDomain = pUnk
            pUnk = NOTHING
         END IF
      END IF
      IF hr THEN METHOD OBJRESULT = hr
      METHOD = m_pCorRuntimeHost
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the ICorRuntimeHost interface.
   ' =====================================================================================
   PROPERTY GET RuntimeHost () AS ICorRuntimeHost
      PROPERTY = m_pCorRuntimeHost
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the default domain.
   ' =====================================================================================
   PROPERTY GET DefaultDomain () AS SystemAppDomain
      PROPERTY = m_pAppDomain
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to domain loaded on the current thread.
   ' =====================================================================================
   PROPERTY GET CurrentDomain () AS SystemAppDomain
      LOCAL hr AS LONG
      LOCAL pUnk AS IUnknown
      LOCAL pDomain AS SystemAppDomain
      hr = m_pCorRuntimeHost.CurrentDomain(pUnk)
      IF hr THEN
         PROPERTY OBJRESULT = hr
      ELSE
         pDomain = pUnk
         pUnk = NOTHING
         PROPERTY = pDomain
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an application domain.
   ' =====================================================================================
   METHOD CreateDomain (OPTIONAL BYREF wszFriendlyName AS WSTRINGZ, BYVAL pIdentityArray AS IUnknown) AS SystemAppDomain
      LOCAL hr AS LONG
      LOCAL pUnk AS IUnknown
      LOCAL pDomain AS SystemAppDomain
      hr = m_pCorRuntimeHost.CreateDomain(wszFriendlyName, pIdentityArray, pUnk)
      IF hr THEN
         METHOD OBJRESULT = hr
      ELSE
         pDomain = pUnk
         pUnk = NOTHING
         METHOD = pDomain
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Unloads the specified application domain from the current process.
   ' =====================================================================================
   METHOD UnloadDomain (BYVAL pDomain AS SystemAppDomain)
      LOCAL hr AS LONG
      IF ISNOTHING(m_pCorRuntimeHost) THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      hr = m_pCorRuntimeHost.UnloadDomain(pDomain)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new instance of the specified type defined in the specified assembly.
   ' =====================================================================================
   METHOD CreateInstance (BYVAL bstrAssemblyName AS WSTRING, BYVAL bstrTypeName AS WSTRING) AS IDispatch
      LOCAL vObj AS VARIANT
      LOCAL pObj AS IDispatch
      LOCAL pObjectHandle AS SystemObjectHandle
      ' // The default domain must exist
      IF ISNOTHING(m_pAppDomain) THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      ' // Create the instance
      pObjectHandle = m_pAppDomain.CreateInstance(bstrAssemblyName, bstrTypeName)
      ' // Unwrap the object
      IF ISOBJECT(pObjectHandle) THEN
         vObj = pObjectHandle.Unwrap
         pObj = vObj
         vObj = EMPTY
         pObjectHandle = NOTHING
         METHOD = pObj
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new instance of the specified type defined in the specified assembly.
   ' =====================================================================================
   METHOD CreateInstance2 (BYVAL pDomain AS SystemAppDomain, BYVAL bstrAssemblyName AS WSTRING, BYVAL bstrTypeName AS WSTRING) AS IDispatch
      LOCAL vObj AS VARIANT
      LOCAL pObj AS IDispatch
      LOCAL pObjectHandle AS SystemObjectHandle
      ' // The default domain must exist
      IF ISNOTHING(m_pAppDomain) THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      ' // Create the instance
      IF ISNOTHING(pDomain) THEN
         pObjectHandle = m_pAppDomain.CreateInstance(bstrAssemblyName, bstrTypeName)
      ELSE
         pObjectHandle = pDomain.CreateInstance(bstrAssemblyName, bstrTypeName)
      END IF
      ' // Unwrap the object
      IF ISOBJECT(pObjectHandle) THEN
         vObj = pObjectHandle.Unwrap
         pObj = vObj
         vObj = EMPTY
         pObjectHandle = NOTHING
         METHOD = pObj
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new instance of a specified type defined in the specified assembly file.
   ' =====================================================================================
   METHOD CreateInstanceFrom (BYVAL bstrAssemblyName AS WSTRING, BYVAL bstrTypeName AS WSTRING) AS IDispatch
      LOCAL vObj AS VARIANT
      LOCAL pObj AS IDispatch
      LOCAL pObjectHandle AS SystemObjectHandle
      ' // The default domain must exist
      IF ISNOTHING(m_pAppDomain) THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      ' // Create the instance
      pObjectHandle = m_pAppDomain.CreateInstanceFrom(bstrAssemblyName, bstrTypeName)
      ' // Unwrap the object
      IF ISOBJECT(pObjectHandle) THEN
         vObj = pObjectHandle.Unwrap
         pObj = vObj
         vObj = EMPTY
         pObjectHandle = NOTHING
         METHOD = pObj
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new instance of a specified type defined in the specified assembly file.
   ' =====================================================================================
   METHOD CreateInstanceFrom2 (BYVAL pDomain AS SystemAppDomain, BYVAL bstrAssemblyName AS WSTRING, BYVAL bstrTypeName AS WSTRING) AS IDispatch
      LOCAL vObj AS VARIANT
      LOCAL pObj AS IDispatch
      LOCAL pObjectHandle AS SystemObjectHandle
      ' // The default domain must exist
      IF ISNOTHING(m_pAppDomain) THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      ' // Create the instance
      IF ISNOTHING(pDomain) THEN
         pObjectHandle = m_pAppDomain.CreateInstanceFrom(bstrAssemblyName, bstrTypeName)
      ELSE
         pObjectHandle = pDomain.CreateInstanceFrom(bstrAssemblyName, bstrTypeName)
      END IF
      ' // Unwrap the object
      IF ISOBJECT(pObjectHandle) THEN
         vObj = pObjectHandle.Unwrap
         pObj = vObj
         vObj = EMPTY
         pObjectHandle = NOTHING
         METHOD = pObj
      END IF
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ========================================================================================
' Creates a new instance of the CCLRHost class and initializes it.
' ========================================================================================
FUNCTION NewCLRHost (OPTIONAL BYREF wszVersion AS WSTRINGZ, BYREF wszBuildFlavor AS WSTRINGZ, BYVAL startupFlags AS DWORD) AS ICLRHost
   LOCAL pCLRHost AS ICLRHost
   ' // Create an instance of the class
   pCLRHost = CLASS "CCLRHost"
   IF ISNOTHING(pCLRHost) THEN EXIT FUNCTION
   ' // Initialize the class
   pCLRHost.Init(wszVersion, wszBuildFlavor, startupFlags)
   FUNCTION = pCLRHost
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new instance of the CCLRHost class and initializes it.
' ========================================================================================
FUNCTION NewCLR4Host (OPTIONAL BYREF wszVersion AS WSTRINGZ) AS ICLRHost
   LOCAL pCLRHost AS ICLRHost
   ' // Create an instance of the class
   pCLRHost = CLASS "CCLRHost"
   IF ISNOTHING(pCLRHost) THEN EXIT FUNCTION
   ' // Initialize the class
   pCLRHost.InitCLR4(wszVersion)
   FUNCTION = pCLRHost
END FUNCTION
' ========================================================================================
