' ========================================================================================
' Determine what kind of device is plugged into a USB port
' ========================================================================================

' SED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "WMI.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL hr AS LONG                                     ' // HRESULT
   LOCAL pIWbemLocator AS IWbemLocator                  ' // IWbemLocator interface reference
   LOCAL pIWbemServices AS IWbemServices                ' // IWbemServices interface reference
   LOCAL pIEnumWbemClassObject AS IEnumWbemClassObject  ' // IEnumWbemClassObject collection reference
   LOCAL pIWbemClassObject AS IWbemClassObject          ' // IWbemClassObject interface reference
   LOCAL bstrNetworkResource AS WSTRING                 ' // WMI namespace path
   LOCAL bstrLanguage AS STRING                         ' // Query language
   LOCAL bstrQuery AS STRING                            ' // Query filter
   LOCAL wszName AS WSTRINGZ * 260                      ' // Name of the Property
   LOCAL puReturned AS DWORD                            ' // Number of returned references
   LOCAL vRes AS VARIANT                                ' // General purpose variamt

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
      STDOUT "CoInitializeSecurity failed with an error code of &H" & HEX$(hr)
      WAITKEY$
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
   ' Connect with the specified machine
   ' -------------------------------------------------------------------------------------
   bstrNetworkResource = "root\cimv2"
   hr = pIWbemLocator.ConnectServer( _
        bstrNetworkResource, _            ' // Object path of WMI namespace
        "", _                             ' // User name. NULL = current user
        "", _                             ' // User password. NULL = current
        "", _                             ' // Locale. NULL indicates current
        0, _                              ' // Security flags
        "", _                             ' // Authority (e.g. Kerberos)
        NOTHING, _                        ' // Context object
        pIWbemServices _                  ' // pointer to IWbemServices proxy
        )
   IF hr <> %S_OK THEN
      STDOUT "IWbemLocator.ConnectServer failed with an error code of &H" & HEX$(hr)
      STDOUT WmiGetErrorCodeText(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Set security levels on the proxy
   ' -------------------------------------------------------------------------------------
   hr = CoSetProxyBlanket( _
        pIWbemServices, _                ' // Indicates the proxy to set
        %RPC_C_AUTHN_WINNT, _            ' // RPC_C_AUTHN_xxx
        %RPC_C_AUTHZ_NONE, _             ' // RPC_C_AUTHZ_xxx
        %NULL, _                         ' // Server principal name
        %RPC_C_AUTHN_LEVEL_CALL, _       ' // RPC_C_AUTHN_LEVEL_xxx
        %RPC_C_IMP_LEVEL_IMPERSONATE, _  ' // RPC_C_IMP_LEVEL_xxx
        %NULL, _                         ' // client identity
        %EOAC_NONE _                     ' // proxy capabilities
        )
   IF hr <> %S_OK THEN
      STDOUT "CoSetProxyBlanket failed with an error code of &H" & HEX$(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Execute the query
   ' -------------------------------------------------------------------------------------
   bstrLanguage = "WQL"
   bstrQuery = "SELECT DeviceID, Description FROM Win32_USBHub"
   hr = pIWbemServices.ExecQuery( _
      bstrLanguage, _                    ' // Query language
      bstrQuery, _                       ' // Query string
      %WBEM_FLAG_FORWARD_ONLY OR _       ' // Forward-only enumerator
      %WBEM_FLAG_RETURN_IMMEDIATELY, _
      NOTHING, _                         ' // Typically NULL
      pIEnumWbemClassObject)             ' // Pointer to the enumerator
   IF hr <> %S_OK THEN
      STDOUT "IWbemServices.ExecQuery failed with an error code of &H" & HEX$(hr)
      STDOUT WmiGetErrorCodeText(hr)
      WAITKEY$
      EXIT FUNCTION
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Enumerate the collection
   ' -------------------------------------------------------------------------------------
   DO

      hr = pIEnumWbemClassObject.Next( _
           %WBEM_INFINITE, _               ' // Timeout
           1, _                            ' // Number of requested objects
           pIWbemClassObject, _            ' // Returned interface pointer
           puReturned _                    ' // number of objects returned
           )
      IF hr <> %S_OK THEN EXIT DO

      ' // Get the device identifier
      wszName = "DeviceID"
      hr = pIWbemClassObject.Get( _
           wszName, _                      ' // Name of the desired property
           0, _                            ' // Reserved. Must be 0.
           vRes, _                         ' // Returned value for the qualifier
           BYVAL %NULL, _                  ' // CIM type of the property
           BYVAL %NULL _                   ' // Origin of the property
           )
      IF hr <> %S_OK THEN
         STDOUT WmiGetErrorCodeText(hr)
         EXIT DO
      END IF
      STDOUT "PNP Device ID = " & VARIANT$(vRes)

      ' // Get the description
      wszName = "Description"
      hr = pIWbemClassObject.Get( _
           wszName, _                      ' // Name of the desired property
           0, _                            ' // Reserved. Must be 0.
           vRes, _                         ' // Returned value for the qualifier
           BYVAL %NULL, _                  ' // CIM type of the property
           BYVAL %NULL _                   ' // Origin of the property
           )
      IF hr <> %S_OK THEN
         STDOUT WmiGetErrorCodeText(hr)
         EXIT DO
      END IF
      STDOUT "Description = " & VARIANT$(vRes)

      ' // Release the collection's object
      pIWbemClassObject = NOTHING

   LOOP
   ' -------------------------------------------------------------------------------------

   WAITKEY$

END FUNCTION
' ========================================================================================
