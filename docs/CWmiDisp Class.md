# Windows Management Instrumentation (WMI)

Windows Management Instrumentation (WMI) is the infrastructure for management data and operations on Windows-based operating systems. 

**CWmiServices** is a wrapper class on top of the WMI scripting interfaces.

**CWmiServices** supports three ways of retrieving information.

* The first one uses an enumerator (the standard IEnumVARIANT interface).
* The second way is to call the **GetNamedProperties** method after executing the query. **GetNamedProperties** generates a named collection of properties. This has the advantage of not having to use CDispInvoke.
* The third way is to use the **Get** method. It retrieves an object, that is either a class definition or an instance, based on the specified object path. Using this object, it generates a named collection of properties. The disadvantage over **EcexuteQuery** is that you can't choose the properties to return: it returns all the properties of the specified WMI class.

**Include file**: CWmiDisp.inc.

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor(Moniker)](#Constructor1) | Connects to WMI using a moniker. |
| [Constructor(Server)](#Constructor2) | Connects to the namespace that is specified on the cbsNamespace parameter on the computer that is specified in the cbsServer parameter.  The target computer can be either local or remote, but it must have WMI installed. |

# Methods

| Name       | Description |
| ---------- | ----------- |
| [ExecQuery](#ExecQuery) | Executes a query to retrieve objects. |
| [Get](#Get) | Retrieves an object, that is either a class definition or an instance, based on the object path. |
| GetErrorCodeText | Returns the text string description associated with the WMI error code. |
| GetFacilityCodeText | Returns the name of the subsystem where the error occurred, such as "Windows", "WBEM", "SSPI", or "RPC". |
| GetLastResult | Returns the last result code. |
| GetNamedProperties | Retrieves a named collection of the properties for the current class or instance. |
| InstancesOf | Creates an enumerator that returns the instances of a specified class according to the user-specified selection criteria. |
| NewEnum | Retrieves an enumerator for the collection. |
| NextObject | Retrieves the next item in the enumeration sequence. |
| ObjectsCount | Returns the number of objects in the collection. |
| ObjectSetPtr | Returns a pointer to the **ISWbemObjectSet** interface. Don't call **IUnknown_Release** on it. |
| PropertySetPtr | Returns a pointer to the **ISWbemPropertySet** interface. Don't call **IUnknown_Release** on it. |
| PropsCount | Returns the number of objects in the property set collection. |
| PropValue | Retrieves de variant value of the WMI property. |
| ResetEnum | Resets the enumeration sequence to the beginning. |
| ServicesObj | Returns a counted reference of the underlying dispatch pointer. You must release it, e.g. calling call **IUnknown_Release** or the function **AfxSafeRelease** when no longer need it. |
| ServicesPtr | Returns a pointer to the ISWbemServices interface. Don't call **IUnknown_Release** on it. |
| WmiDateToStr | Converts a date and time value in the CIM DATETIME format to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy". |
| WmiTimeToFileTime | Converts a date and time value in the CIM DATETIME format to the FILETIME format. |
| WmiTimeToStr | Converts a date and time value in the CIM DATETIME format to a string containing the date based on the specified mask, e.g. "hh':'mm':'ss tt". |

# <a name="Constructor1"></a>Constructor(Moniker)

Connects to WMI using a moniker.

```
CONSTRUCTOR CWmiServices (BYREF wszDisplayName AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszDisplayName* | The display name of the object to be created. |

#### Examples

```
' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
```

This example uses **CWmiServices** and **CDispInvoke** to easily set the specified printer as the default printer:

```
' // Connect with WMI in the local computer and get the properties of the specified printer
DIM pDisp AS CDispInvoke = CWmiServices( _
   $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2:" & _
   "Win32_Printer.DeviceID='OKI B410'").ServicesObj

' // Set the printer as the default printer
DIM cvRes AS CVAR = pDisp.Invoke("SetDefaultPrinter")
print "Result: ", cvRes.ValLong
```

# <a name="Constructor2"></a>Constructor(Server)

Connects to the namespace that is specified on the *cbsNamespace* parameter on the computer that is specified in the *cbsServer* parameter. The target computer can be either local or remote, but it must have WMI installed.

```
CONSTRUCTOR CWmiServices (BYREF cbsServer AS CBSTR, BYREF cbsNamespace AS CBSTR, BYREF cbsUser AS CBSTR = "", _
   BYREF cbsPassword AS CBSTR = "", BYREF cbsLocale AS CBSTR = "", BYREF cbsAuthority AS CBSTR = "", _
   BYVAL iSecurityFlags AS LONG = wbemConnectFlagUseMaxWait)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsServer* | Computer name to which you are connecting. If the remote computer is in a different domain than the user account under which you log in, then use the fully qualified computer name. If you do not provide this parameter, the call defaults to the local computer.<br>Example: server1.network.fabrikam<br>You also can use an IP address in this parameter. If the IP address is in IPv6 format, the target computer must be running IPv6. An address in IPv4 looks like 111.222.333.444. An IP address in IPv6 format looks like 2010:836B:4179::836B:4179 |
| *cbsNamespace* | String that specifies the namespace to which you log on. For example, to log on to the root\default namespace, use root\\default. If you do not specify this parameter, it defaults to the namespace that is configured as the default namespace for scripting.<br>Example: DIM pServices AS CWmiServices = CWmiServices(".", "root\\cimv2")<br>where "." is a shortcut for the local computer. |
| *cbUser* | User name to use to connect. The string can be in the form of either a user name or a Domain\\Username. Leave this parameter blank to use the current security context. The *cbsUser* parameter should only be used with connections to remote WMI servers. If you attempt to specify cbsUser for a local WMI connection, the connection attempt fails.<br>If Kerberos authentication is in use, then the username and password that is specified in *cbsUser* and *cbsPassword* cannot be intercepted on a network. You can use the UPN format to specify the *cbsUser*.<br>Example: "DomainName\\UserName"<br>Note: If a domain is specified in *cbsAuthority*, then the domain must not be specified here. Specifying the domain in both parameters results in an Invalid Parameter error. |
| *cbsPassword* | String that specifies the password to use when attempting to connect. Leave the parameter blank to use the current security context. The *cbsPassword* parameter should only be used with connections to remote WMI servers. If you attempt to specify *cbsPassword* for a local WMI connection, the connection attempt fails. If Kerberos authentication is in use then the username and password that is specified in *cbsUser* and *cbsPassword* cannot be intercepted on the network. |
| *cbsLocale* | String that specifies the localization code. If you want to use the current locale, leave it blank. If not blank, this parameter must be a string that indicates the desired locale where information must be retrieved. For Microsoft locale identifiers, the format of the string is "MS_xxxx", where xxxx is a string in the hexadecimal form that indicates the LCID. For example, American English would appear as "MS_409". |
| *cbsAuthority* | Optional.<br>"": This parameter is optional. However, if it is specified, only Kerberos or NTLMDomain can be used.<br> "Kerberos": If the *cbsAuthority* parameter begins with the string "Kerberos:", then Kerberos authentication is used and this parameter should contain a Kerberos principal name. The Kerberos principal name is specified as Kerberos:domain, such as Kerberos:fabrikam where fabrikam is the server to which you are  attempting to connect. Example: "Kerberos:DOMAIN"<br>"NTLMDomain": To use NT Lan Manager (NTLM) authentication, you must specify it as NTLMDomain:domain, such as NTLMDomain:fabrikam where fabrikam is the name of the domain. Example: "NTLMDomain:DOMAIN"<br>If you leave this parameter blank, the operating system negotiates with COM to determine whether NTLM or Kerberos authentication is used. This parameter should only be used with connections to remote WMI servers. If you attempt to set the authority for a local WMI connection, the connection attempt fails.<>Note: If the domain is specified in *cbsUser*, which is the preferred location, then it must not be specified here. Specifying the domain in both parameters results in an Invalid Parameter error. |
| *iSecurityFlags* | Optional. Used to pass flag values to the *ConnectServer* method of the ISWbemLocator interface.<br>*0 (&h0)*: A value of 0 for this parameter causes the call to *ConnectServer* to return only after the connection to the server is established. This could cause your program to stop responding indefinitely if the connection cannot be established.<br>*wbemConnectFlagUseMaxWait (128 (&H80))*<> The *ConnectServer* call is guaranteed to return in 2 minutes or less. Use this flag to prevent your program from ceasing to respond indefinitely if the connection cannot be established. |

#### Return value

If successful, WMI returns an **SWbemServices** object that is bound to the namespace that is specified in *cbsNamespace* on the computer that is specified in *cbsServer*.

**Usage example** (with the local computer):

```
DIM pServices AS CWmiServices = CWmiServices(".", "root\\cimv2")
```

### Remarks

The *ConnectServer* method is often used when connecting to an account with a different username and password—credentials—on a remote computer because you cannot specify a different password in a moniker string.

Using an IPv4 address to connect to a remote server may result in unexpected behavior. The likely cause is stale DNS entries in your environment. In these circumstances, the stale PTR entry for the machine will be used, with unpredictable results. To avoid this behavior, you can append a period (".") to the IP address before calling *ConnectServer*. This causes the reverse DNS lookup to fail, but may allow the *ConnectServer* call to succeed on the correct machine.

# <a name="ExecQuery"></a>ExecQuery

Executes a query to retrieve objects. These objects are available through the retrieved **SWbemObjectSet** collection.

```
FUNCTION ExecQuery (BYREF cbsQuery AS CBSTR, BYVAL iFlags AS LONG = wbemFlagReturnWhenComplete) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsQuery* | Required. String that contains the text of the query. This parameter cannot be blank. |
| *iFlags* | Optional. Integer that determines the behavior of the query and determines whether this call returns immediately. The default value for this parameter is *wbemFlagReturnWhenComplete*. This parameter can accept the following values. |

| Flag       | Description |
| ---------- | ----------- |
| *wbemFlagForwardOnly* | Causes a forward-only enumerator to be returned. Forward-only enumerators are generally much faster and use less memory than conventional enumerators, but they do not allow calls to SWbemObject.Clone_. |
| *wbemFlagReturnWhenComplete* | Causes this call to block until the query is complete. This flag calls the method in the synchronous mode. |
| *wbemFlagBidirectional* | Causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator. |
| *wbemFlagReturnImmediately* | Causes the call to return immediately. |
| *wbemQueryFlagPrototype* | Used for prototyping. This flag stops the query from happening and returns an object that looks like a typical result object. |
| *wbemFlagUseAmendedQualifiers* | Causes WMI to return class amendment data with the base class definition. |

#### Return value

Returns S_OK (0) on success, or an HRESULT code on failure.

#### Examples

Using an enumerator (the standard IEnumVARIANT interface) to retrieve the information:

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx
' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END
' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END
' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Count: ", nCount
IF nCount = 0 THEN PRINT "No objects found" : SLEEP : END
' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
IF pDispServ.DispPtr THEN
   PRINT "Caption: "; pDispServ.Get("Caption")
   PRINT "Serial number: "; pDispServ.Get("SerialNumber")
END IF
PRINT
PRINT "Press any key..."
SLEEP
```

If the query returns more than one object, then we will use a loop:

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Count: ", nCount
IF nCount = 0 THEN PRINT "No objects found" : SLEEP : END

' // Enumerate the objects
FOR i AS LONG = 0 TO nCount - 1
   PRINT "--- Index " & STR(i) & " ---"
   DIM pDispServ AS CDispInvoke = pServices.NextObject
   IF pDispServ.DispPtr THEN
      PRINT "Caption: "; pDispServ.Get("Caption")
      PRINT "Capabilities "; pDispServ.Get("Capabilities")
   END IF
NEXT

PRINT
PRINT "Press any key..."
SLEEP
```

To improve enumeration performance set the iFlags parameter if the ExecQuery method to WbemFlagReturnImmediately and WbemFlagForwardOnly (the combined value of these flags is 48) to allow semisynchronous return of the data with an enumerator that discards each item from WMI as it is delivered. In this case don't call the ObjectsCount method because it will return 0, since the operation has not been completed.

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS", 48)
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
IF pDispServ.DispPtr THEN
   PRINT "Caption: "; pDispServ.Get("Caption").ToStr
   PRINT "Serial number: "; pDispServ.Get("SerialNumber").ToStr
END IF

PRINT
PRINT "Press any key..."
SLEEP
```

If there are several objects in the collection, we can use a loop:

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer", 48)
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke
DO
   pDispServ = pServices.NextObject
   IF pDispServ.DispPtr = NULL THEN EXIT DO
   PRINT "Caption: "; pDispServ.Get("Caption").ToStr
   PRINT "Capabilities "; pDispServ.Get("Capabilities").ToStr
LOOP

PRINT
PRINT "Press any key..."
SLEEP
```

Calling the GetNamedProperties method after executing the query. GetNamedProperties generates a named collection of properties. This has the advantage of not having to use CDispInvoke.

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Number of objects: ", nCount
IF nCount = 0 THEN PRINT "No objects found" : SLEEP : END

' // Get a collection of named properties
IF pServices.GetNamedProperties <> S_OK THEN PRINT "Failed to get the named properties" : SLEEP : END

' // Retrieve the value of the properties
'DIM cv AS CVAR = pServices.PropValue("Caption")
'PRINT cv.ToStr
PRINT pServices.PropValue("Caption").ToStr
PRINT pServices.PropValue("SerialNumber").ToStr

PRINT
PRINT "Press any key..."
SLEEP
```

Using a loop:

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Number of objects: ", nCount
IF nCount = 0 THEN PRINT "No objects found" : SLEEP : END

' // Enumerate the objects
FOR i AS LONG = 0 TO nCount - 1
   PRINT "--- Index " & STR(i) & " ---"
   ' // Get a collection of named properties
   IF pServices.GetNamedProperties(i) = S_OK THEN
      PRINT pServices.PropValue("Caption").ToStr
      PRINT pServices.PropValue("Capabilities").ToStr
   END IF
NEXT

PRINT
PRINT "Press any key..."
SLEEP
```

# <a name="Get"></a>Get

Retrieves an object, that is either a class definition or an instance, based on the object path. This method retrieves only objects from the namespace that is associated with the current **SWbemServices** object.

```
FUNCTION Get (BYREF cbsObjectPath AS CBSTR, BYVAL iFlags AS LONG = 0, _
   BYVAL objWbemNamedValueSet AS Afx_IDispatch PTR = NULL) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsObjectPath* | String that contains the object path of the object to retrieve. If this value is empty, the empty object that is returned can become a new class. |
| *iFlags* | Optional. Integer value that determines the behavior of the query. This parameter can accept the folñlowing value:<br>*wbemFlagUseAmendedQualifiers*: Causes WMI to return class amendment data with the base class definition. |
| *objWbemNamedValueSet* | Optional. Typically, this is undefined. Otherwise, this is an **SWbemNamedValueSet** object whose elements represent the context information that can be used by the provider that is servicing the request. A provider that supports or requires such information must document the recognized value names, data type of the value, allowed values, and semantics. |

#### Return value

S_OK on success or an error code.

May return one of the error codes in the following list:

| Error      | Value       | Description |
| ---------- | ----------- | ----------- |
| *wbemErrAccessDenied* | -2147749891 (&j80041003) | Current user does not have the permission to access the object. |
| *wbemErrFailed* | -2147749889 (&h80041001) | Unspecified error. |
| *wbemErrInvalidParameter* | -2147749896 (&h80041008) | A specified parameter is not valid. |
| *wbemErrInvalidObjectPath* | -2147749946 (&h8004103A) | Specified path was not valid. |
| *wbemErrNotFound* | -2147749890 (&h80041002) | Requested object could not be found. |
| *wbemErrOutOfMemory* | -2147749894 (&h80041006) | Not enough memory to complete the operation. |

#### Example

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN END
 
' // Get an instance of the printer "OKI B410" --> change me
DIM hr AS HRESULT = pServices.Get("Win32_Printer.DeviceID='OKI B410'")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Number of properties
PRINT "Number of properties: ", pServices.PropsCount
PRINT

' // Display some properties
PRINT "Port name: "; pServices.PropValue("PortName")
PRINT "Attributes: "; pServices.PropValue("Attributes")
PRINT "Paper sizes supported: "; pServices.PropValue("PaperSizesSupported")

PRINT
PRINT "Press any key..."
SLEEP
```

Example

```
#include "windows.bi"
#include "Afx/CWmiDisp.inc"
using Afx

' // Connect to WMI using a moniker
'DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
' Use the constructor for server connection, just for trying...
DIM pServices AS CWmiServices = CWmiServices(".", "root\cimv2")
IF pServices.ServicesPtr = NULL THEN END
 
 '// Get an instance of a file --> change me
DIM cbsPath AS CBSTR = ExePath & "\EX_CWMI_Get_02.bas"   ' --> change me
DIM hr AS HRESULT = pServices.Get("CIM_DataFile.Name='" & cbsPath & "'")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : SLEEP : END

' // Number of properties
PRINT "Number of properties: ", pServices.PropsCount
PRINT

' // Display some properties
PRINT "Relative path: "; pServices.PropValue("Path")
PRINT "FileName: "; pServices.PropValue("FileName")
PRINT "Extension: "; pServices.PropValue("Extension")
PRINT "Size: "; pServices.PropValue("Filesize")
'PRINT pServices.PropValue("LastModified")
PRINT "Date last modified: "; pServices.WmiDateToStr(pServices.PropValue("LastModified"), "dd-MM-yyyy")   ' // change the mask if needed

PRINT
PRINT "Press any key..."
SLEEP
```