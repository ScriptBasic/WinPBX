# CWmiDisp Class

Windows Management Instrumentation (WMI) is the infrastructure for management data and operations on Windows-based operating systems. 

**CWmiDisp** is a wrapper class on top of the WMI scripting interfaces.

**CWmiDisp** supports three ways of retrieving information.

* The first one uses an enumerator (the standard IEnumVARIANT interface).
* The second way is to call the **GetNamedProperties** method after executing the query. **GetNamedProperties** generates a named collection of properties. This has the advantage of not having to use CDispInvoke.
* The third way is to use the **Get** method. It retrieves an object, that is either a class definition or an instance, based on the specified object path. Using this object, it generates a named collection of properties. The disadvantage over **EcexuteQuery** is that you can't choose the properties to return: it returns all the properties of the specified WMI class.

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor(Moniker)](#Constructor1) | Connects to WMI using a moniker. |
| [Constructor(Server)](#Constructor2) | Connects to the namespace that is specified on the cbsNamespace parameter on the computer that is specified in the cbsServer parameter.  The target computer can be either local or remote, but it must have WMI installed. |

# Methods

| Name       | Description |
| ---------- | ----------- |
| [ExecQuery](#ExecQuery) | Executes a query to retrieve objects. |
| Get | Retrieves an object, that is either a class definition or an instance, based on the object path. |
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
