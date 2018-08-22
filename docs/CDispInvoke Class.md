# CDispInvoke Class

**CDispInvoke** allows to call COM methods and properties with Free Basic.

**Include file**: CDispInvoke.inc

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor(PROGID)](#Constructor1) | Creates a single uninitialized object of the class associated with a specified ProgID or CLSID. |
| [Constructor(CLSID)](#Constructor2) | Creates a single uninitialized object of the class associated with a specified CLSID. |
| [Constructor(IDispatch)](#Constructor3) | Creates a single uninitialized object of the class associated with a pointer to a Dispatch interface. |
| [Constructor(VARIANT)](#Constructor4) | Creates a single uninitialized object of the class associated with a variant of the type VT_DISPATCH. |
| [Constructor(LibName)](#Constructor5) | Loads the specified library from file and creates an instance of an object. |

# Operators

| Name       | Description |
| ---------- | ----------- |
| [Operator \*](#Operator1) | Returns the underlying IDispatch pointer. |
| [Operator LET](#Operator2) | Assigns an IDispatch pointer and increases the reference count. |

# Methods

| Name       | Description |
| ---------- | ----------- |
| [Attach](#Attach) | Attaches a Dispatch pointer. |
| [Detach](#Detach) | Detaches a Dispatch pointer. |
| [DispInvoke](#DispInvoke) | Calls a method or a get property. |
| [DispObj](#DispObj) | Returns a counted reference of the underlying dispatch pointer. |
| [DispPtr](#DispPtr) | Returns a pointer to the dispatch interface. |
| [Get](#Get) | Calls the specified property of an interface and gets the value returned. |
| [GetArgErr](#GetArgErr) | Returns the index within rgvarg of the first argument that has an error. |
| [GetDescription](#GetDescription) | Gets the exception description. |
| [GetErrorCode](#GetErrorCode) | Returns the error code. |
| [GetHelpFile](#GetHelpFile) | Gets the fully qualified help file path. |
| [GetLastResult](#GetLastResult) | Returns the last result code returned by the last executed method. of the class. |
| [GetSource](#GetSource) | Gets the name of the exception source. |
| [GetVarResult](#GetVarResult) | Returns the last result code returne by a call to the Invoke method. |
| [GetLcid](#GetLcid) | Retrieves de locale identifier used by the class. |
| [Invoke](#Invoke) | Calls a method or a get property. |
| [SetLcid](#SetLcid) | Sets de locale identifier used by the class. |
| [Put](#Put) | Calls the specified property of an interface and sets the passed value. |
| [PutRef](#PutRef) | Assigns a value to an interface member property that contains a reference to an object. |
| [Set](#Set) | Calls the specified property of an interface and sets the passed value. |
| [SetRef](#SetRef) | Assigns a value to an interface member property that contains a reference to an object. |
| [vptr](#vptr) | Clears the contents of the class and returns the address of the underlying IDispatch pointer. |

# <a name="Constructor1"></a>Constructor(ProgID)

Creates a single uninitialized object of the class associated with a specified ProgID or CLSID.

```
CONSTRUCTOR CDispInvoke (BYREF wszProgID AS CONST WSTRING, BYREF wszLicKey AS WSTRING = "")
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszProgID* | The ProgID or the CLSID of the object to create.<br>A ProgID such as "MSCAL.Calendar.7"<br>A CLSID such as "{8E27C92B-1264-101C-8A2F-040224009C02}" |
| *wszLicKey* | Optional. The license key as a unicode string. |

#### Usage example

```
DIM pDispInvoke AS CDispInvoke = "Scripting.Dictionary"
' -or-
pDispInvoke = CDispInvoke(CLSID_Dictionary)
' where CLSID_Dictionary has been declared as
'    CONST CLSID_Dictionary = "{EE09B103-97E0-11CF-978F-00A02463E06F}"
```

#### Example

The following example demonstrates how to use it to create an instance of the VBScript RegExp object and execute a search.

```
#include once "Afx/CDispInvoke.inc"
USING Afx

' // Create an instance of the RegExp object
DIM pDisp AS CDispInvoke = "VBScript.RegExp"
' // To check for success, see if the value returned by the DispPtr method is not null
IF pDisp.DispPtr = NULL THEN END

' // Set some properties
' // Use VARIANT_TRUE or CTRUE, not TRUE, because Free Basic TRUE is a BOOLEAN data type, not a LONG
pDisp.Put("Pattern") = ".is"
pDisp.Put("IgnoreCase") = VARIANT_TRUE
pDisp.Put("Global") = VARIANT_TRUE

' // Execute a search
DIM pMatches AS CDispInvoke = pDisp.Invoke("Execute", "IS1 is2 IS3 is4")
' // Parse the collection of matches
IF pMatches.DispPtr THEN
   ' // Get the number of matches
   DIM nCount AS LONG = VAL(pMatches.Get("Count"))
   ' // This is equivalent to:
   ' DIM cvRes AS CVAR = pMatches.Get("Count")
   ' DIM nCount AS LONG = cvRes.ValInt
   FOR i AS LONG = 0 TO nCount -1
      ' // Get a pointer to the Match object
      ' // When using COM Automation, it's not always necessary to make sure that the
      ' // passed variant with a numeric value is of the exact type, since the standard
      ' // implementation of DispInvoke tries to coerce parameters. However, it is always
      ' // safer to use a syntax like CVAR(i, "LONG")) than CVAR(i)
'      DIM pMatch AS CDIspInvoke = pMatches.Get("Item", CVAR(i, "LONG"))   ' // or CVAR(i, "LONG"))
      DIM pMatch AS CDIspInvoke = pMatches.Get("Item", i)
      IF pMatch.DispPtr THEN
         ' // Get the value of the match and convert it to a string
         print pMatch.Get("Value")
      END IF
   NEXT
END IF

PRINT
PRINT "Press any key..."
SLEEP
```

# <a name="Constructor2"></a>Constructor(CLSID)

Creates a single uninitialized object of the class associated with a specified CLSID.

```
CONSTRUCTOR CDispInvoke (BYREF classID AS CONST CLSID)
CONSTRUCTOR CDispInvoke (BYREF wszClsID AS CONST WSTRING, BYREF wszIID AS CONST WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *classID* | The CLSID (class identifier) associated with the data and code that will be used to create the object. |
| *wszClsID* | A CLSID in string format. |
| *wszIID* | The identifier of the interface to be used to communicate with the object. |

#### Usage examples

```
DIM pDispInvoke AS CDispInvoke = CDispInvoke(CLSID_Dictionary)
' where CLSID_Dictionary has been declared as
'   DIM CLSID_Dictionary AS CLSID = (&hEE09B103, &h97E0, &h11CF, {&h97, &h8F, &h00, &hA0, &h24, &h63, &hE0, &h6F})
```

```
DIM pDispInvoke AS CDispInvoke = (CLSID_Dictionary, IID_IDictionary)
' where CLSID_Dictionary has been declared as
'    CONST CLSID_Dictionary = "{EE09B103-97E0-11CF-978F-00A02463E06F}"
' and IID_IDictionary as
'    CONST IID_IDictionary = "{42C642C1-97E1-11CF-978F-00A02463E06F}"
```

# <a name="Constructor3"></a>Constructor(IDispatch)

Creates a single uninitialized object of the class associated with a pointer to a Dispatch interface.

```
CONSTRUCTOR CDispInvoke (BYVAL pdisp AS IDispatch PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pdisp* | Pointer to a Dispatch interface. |
| *fAddRef* | If it is false, the object takes ownership of the interface pointer without calling AddRef. This is the usual case when we assign directly an already AddRefed pointer returned by a COM method. If it is true, then **AddRef is called**. This is needed when we pass a raw pointer. |

#### Exaample

The following example combines CDispInvoke and CWmiDisp to set the specified printer as the default one.

```
#include once "Afx/CDispInvoke.inc"
#include once "Afx/CWmiDisp.inc"
USING Afx

' // Connect with WMI in the local computer and get the properties of the specified printer
DIM pDisp AS CDispInvoke = CWmiServices( _
   $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2:" & _
   "Win32_Printer.DeviceID='OKI B410'").ServicesObj

' // Set the printer as the default printer
pDisp.Invoke("SetDefaultPrinter")

PRINT
PRINT "Press any key..."
SLEEP
```

# <a name="Constructor4"></a>Constructor(VARIANT)

Creates a single uninitialized object of the class associated with a variant of the type VT_DISPATCH.

```
CONSTRUCTOR CDispInvoke (BYVAL vDisp AS VARIANT PTR, BYVAL fAddRef AS BOOLEAN = TRUE)
CONSTRUCTOR CDispInvoke (BYVAL vDisp AS VARIANT, BYVAL fAddRef AS BOOLEAN = TRUE)
CONSTRUCTOR CDispInvoke (BYREF cvDisp AS CVAR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *vDisp* | A VT_DISPATCH variant. |
| *fAddRef* | If it is false, the object takes ownership of the interface pointer without calling AddRef. This is the usual case when we assign directly an already AddRefed pointer returned by a COM method. If it is true, then **AddRef** is called. This is needed when we pass a raw pointer. |
| *cvDisp* | A VT_DISPATCH CVAR. |

# <a name="Constructor5"></a>Constructor(LibName)

Loads the specified library from file and creates an instance of an object.

```
CONSTRUCTOR CDispInvoke (BYREF wszLibName AS CONST WSTRING, BYREF rclsid AS CONST CLSID, _
   BYREF riid AS CONST IID, BYREF wszLicKey AS WSTRING = "")
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszLibName* | Full path where the library is located. |
| *rclsid* | The CLSID (class identifier) associated with the data and code that will be used to create the object. |
| *riid* | The identifier of the interface to be used to communicate with the object. |
| *wszLicKey* | Optional. The license key. |

#### Remarks

Not every component is a suitable candidate for use under this overloaded method.
* Only in-process servers (DLLs) are supported.
* Components that are system components or part of the operating system, such as XML, Data Access, Internet Explorer, or DirectX, aren't supported
* Components that are part of an application, such Microsoft Office, aren't supported.
* Components intended for use as an add-in or a snap-in, such as an Office add-in or a control in a Web browser, aren't supported.
* Components that manage a shared physical or virtual system resource aren't supported.
* Visual ActiveX controls aren't supported because they need to be initilized and activated by the OLE container.

#### Usage example

```
DIM pDispInvoke AS CDispInvoke = (CLSID_Dictionary, IID_IDictionary)
' where CLSID_Dictionary has been declared as
'    CONST CLSID_Dictionary = "{EE09B103-97E0-11CF-978F-00A02463E06F}"
' and IID_IDictionary as
'    CONST IID_IDictionary = "{42C642C1-97E1-11CF-978F-00A02463E06F}"
```
