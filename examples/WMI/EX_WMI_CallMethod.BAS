' ========================================================================================
' Demonstrates how to pass values to a method, how to call it and how to retrieve return
' values. Uses the "StdRegProv" class to retrieve the ProductName in the
' HKEY_LOCAL_MACHINE "Software\Microsoft\Windows NT\CurrentVersion" in the registry.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE "WMI.INC"

FUNCTION PBMAIN

   LOCAL hr AS LONG                                     ' // HRESULT
   LOCAL pIWbemLocator AS IWbemLocator                  ' // IWbemLocator interface reference
   LOCAL pIWbemServices AS IWbemServices                ' // IWbemServices interface reference
   LOCAL bstrNetworkResource AS WSTRING                 ' // WMI namespace path
   LOCAL bstrObjectPath AS WSTRING                      ' // Object path
   LOCAL pIWbemClassObject AS IWbemClassObject          ' // Class object
   LOCAL wszMethodName AS WSTRINGZ * 260                ' // Method name
   LOCAL wszParamName AS WSTRINGZ * 260                 ' // Parameter name
   LOCAL pInParamsDefinition AS IWbemClassObject        ' // IWbemClassObject for IN parameters definition
   LOCAL pOutParamsDefinition AS IWbemClassObject       ' // IWbemClassObject for OUT parameters definition
   LOCAL pIWbemClassObjectInstance AS IWbemClassObject  ' // Object instance
   LOCAL vValue AS VARIANT                              ' // Variant value
   LOCAL vReturnValue AS VARIANT                        ' // Return value

   ' -------------------------------------------------------------------------------------
   ' Set the default security values for the process
   ' -------------------------------------------------------------------------------------
   hr = CoInitializeSecurity( _
        BYVAL %NULL, _                   ' // PSECURITY_DESCRIPTOR
        -1, _                            ' // COM authentication
        BYVAL %NULL, _                   ' // Authentication services
        %NULL, _                         ' // Reserved
        %RPC_C_AUTHN_LEVEL_DEFAULT, _    ' // Default authentication
        %RPC_C_IMP_LEVEL_IMPERSONATE, _  ' // Default Impersonation
        BYVAL %NULL, _                   ' // Authentication info
        %EOAC_NONE, _                    ' // Additional capabilities
        %NULL _                          ' // Reserved
        )
   IF hr <> %S_OK THEN
      AfxShowMsg("CoInitializeSecurity failed with an error code of &H" & HEX$(hr))
      EXIT FUNCTION
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Create an instance of the IWbemLocator interface
   ' -------------------------------------------------------------------------------------
   pIWbemLocator = NEWCOM CLSID $CLSID_WbemLocator
   IF ISNOTHING(pIWbemLocator) THEN EXIT FUNCTION
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Connect with the specified machine.
   ' For  local access to the default namespace, use a simple object path:
   ' "root\default" or "\\.\root\default". For access to the default namespace
   ' on a remote computer include the computer name: "\\myserver\root\default".
   ' The computer name can also be a DNS name or IP address.
   ' -------------------------------------------------------------------------------------
   bstrNetworkResource = "root\default"
   hr = pIWbemLocator.ConnectServer( _
        bstrNetworkResource, _            ' // Object path of WMI namespace
        "", _                             ' // User name. NULL value = current user
        "", _                             ' // User password. NULL value  = current
        "", _                             ' // Locale. NULL value indicates current
        0, _                              ' // Security flags
        "", _                             ' // Authority (e.g. Kerberos)
        NOTHING, _                        ' // Context object
        pIWbemServices _                  ' // pointer to IWbemServices proxy
        )
   IF hr <> %S_OK THEN
      AfxShowMsg("IWbemLocator.ConnectServer failed with an error code of &H" & HEX$(hr) & $CRLF & WmiGetErrorCodeText(hr))
      EXIT FUNCTION
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Retrieve a reference to the WMI "StdRegProv" class object
   ' -------------------------------------------------------------------------------------
   bstrObjectPath = "StdRegProv"
   hr = pIWbemServices.GetObject(bstrObjectPath, 0, NOTHING, pIWbemClassObject, NOTHING)
   IF hr <> %S_OK THEN EXIT FUNCTION
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Retrieve references to the IN and OUT parameters of the GetStringValue method
   ' -------------------------------------------------------------------------------------
   wszMethodName = "GetStringValue"
   hr = pIWbemClassObject.GetMethod(wszMethodName, 0, pInParamsDefinition, pOutParamsDefinition)
   IF hr <> %S_OK THEN EXIT FUNCTION
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Create a new instance of the class and set the values of the parameters
   ' -------------------------------------------------------------------------------------
   IF ISOBJECT(pInParamsDefinition) THEN
      hr = pInParamsDefinition.SpawnInstance(0, pIWbemClassObjectInstance)
      IF hr = %S_OK AND ISOBJECT(pIWbemClassObjectInstance) THEN
         ' // Set the HKEY_LOCAL_MACHINE key
         wszParamName = "hDefKey"
         vValue = "2147483650"   ' must be decimal, not hex
         hr = pIWbemClassObjectInstance.Put(wszParamName, 0, vValue, %CIM_UINT32)
         ' // Set the subkey name
         wszParamName = "sSubKeyName"
         vValue = "Software\Microsoft\Windows NT\CurrentVersion"
         hr = pIWbemClassObjectInstance.Put(wszParamName, 0, vValue, %CIM_STRING)
         ' // Set the requested value
         wszParamName = "sValueName"
         vValue = "ProductName"
         hr = pIWbemClassObjectInstance.Put(wszParamName, 0, vValue, %CIM_STRING)
      END IF
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Execute the method
   ' -------------------------------------------------------------------------------------
   hr = pIWbemServices.ExecMethod(bstrObjectPath, wszMethodName, _
        0, NOTHING, pIWbemClassObjectInstance, pOutParamsDefinition, NOTHING)
   IF hr <> %S_OK THEN AfxShowMsg("ExecMethod hr = " & HEX$(hr))
   IF hr = %S_OK AND ISOBJECT(pOutParamsDefinition) THEN
      wszParamName = "sValue"
      hr = pOutParamsDefinition.Get(wszParamName, 0, vReturnValue, BYVAL %NULL, BYVAL %NULL)
      IF hr THEN
         AfxShowMsg("IWbemClassObject.Get sValue Error - hr = " & HEX$(hr) & $CRLF & WmiGetErrorCodeText(hr))
      ELSE
         AfxShowMsg("sValue = " & VARIANT$(vReturnValue))
      END IF
   END IF
   ' -------------------------------------------------------------------------------------

END FUNCTION
