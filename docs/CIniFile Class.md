# CIniFile Class

**CIniFile** is a wrapper class to ease the use of .ini files.

Pass the path and name of the .ini file to read or write to when you create an instance of the **CIniFile** class. If you omit the path, the class will use the current directory. If the .ini file does not exist, it will create it.

* To retrieve data from the class, use the methods **GetString**, **GetDouble** or **GetInt**.
* To set data values, call one of the overloaded **WriteValue** methods.
* To delete a key, call the **DeleteKey** method.
* To delete an entire section, call the **DeleteSection** method.

Other useful methods are **GetKeyNames**, that returns a safe array with the names of all the keys of the specified section, **GetSectionNames**, that returns a safe array with the names of all the sections in the .ini file, and **GetSectionValues**, that returns a **Dictionary** object with the names and values of all the keys of the specified section.

#### Include file

CIniFile.inc

### Constructors

```
CONSTRUCTOR CIniFIle ((BYREF wszFileName AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | The path and name of the .ini file. If you omit the path, the class will use the current directory. If the .ini file does not exist, it will create it. |

#### Example

#include once "AFx/CInifile.inc"
USING Afx

DIM cIni AS CInifile = "Test.ini"
cIni.WriteValue("Test", "Name", "Joe Doe")
DIM wszName AS WSTRING * 260
wszName = cIni.GetString("Test", "Name")
print wszName

PRINT "Press any key..."
SLEEP

### Methods

| Name       | Description |
| ---------- | ----------- |
| [DeleteKey](#DeleteKey) | Deletes a key from the specified section of an initialization file. |
| [DeleteSection](#DeleteSection) | Deletes a section from an initialization file. |
| [GetDouble](#GetDouble) | Retrieves a numeric value from the specified section in an initialization file. |
| [GetInt](#GetInt) | Retrieves a numeric value from the specified section in an initialization file. |
| [GetKeyNames](#GetKeyNames) | Returns a safe array with the names of all the keys of the specified section. |
| [GetPath](#GetPath) | Returns the full path of ini file this object instance is operating on. |
| [GetSectionNames](#GetSectionNames) | Returns a safe array with the names of all sections in the ini file. |
| [GetSectionValues](#GetSectionValues) | Returns the keys and values of the specified section as a dictionary object. |
| [GetString](#GetString) | Retrieves a string from the specified section in an initialization file. |
| [WriteValue](#WriteValue) | Writes a value into the specified section of an initialization file. |

# <a name="DeleteKey"></a>DeleteKey

Deletes a key from the specified section of an initialization file.

```
FUNCTION DeleteKey (BYREF wszSectionName AS WSTRING, BYREF wszKeyName AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszSectionName* | The name of the section. |
| *wszKeyName* | The name of the key to delete. |

#### Return value

BOOLEAN. True on success or False on failure.

# <a name="DeleteSection"></a>DeleteSection

Deletes a section from an initialization file.

```
FUNCTION DeleteSection (BYREF wszSectionName AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszSectionName* | The name of the section to delete. |

#### Return value

BOOLEAN. True on success or False on failure.

# <a name="GetDouble"></a>GetDouble

Retrieves a numeric value from the specified section in an initialization file.

```
FUNCTION GetDouble (BYREF wszSectionName AS WSTRING, _
   BYREF wszKeyName AS WSTRING, BYVAL nDefaultValue AS DOUBLE = 0) AS DOUBLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszSectionName* | The name of the section. |
| *wszKeyName* | The name of the key. |
| *nDefaultValue* | A default value to be returned if the key key cannot be found in the initialization file. |

#### Return value

DOUBLE. The retrieved value. If the key key cannot be found in the initialization file, the default value is returned.


