# CDispInvoke Class

**CDispInvoke** allows to call COM methods and properties with Free Basic.

**Include file**: CDispInvoke.inc

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor(IDispatch)](#Constructor1) | Creates a single uninitialized object of the class associated with a pointer to a Dispatch interface. |
| [Constructor(VARIANT)](#Constructor2) | Creates a single uninitialized object of the class associated with a variant of the type VT_DISPATCH. |
| [Constructor(PROGID)](#Constructor3) | Creates a single uninitialized object of the class associated with a specified ProgID or CLSID. |
| [Constructor(CLSID)](#Constructor4) | Creates a single uninitialized object of the class associated with a specified CLSID. |
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

# <a name="Constructor1"></a>Constructor(IDispatch)

Creates a single uninitialized object of the class associated with a pointer to a Dispatch interface.

```
CONSTRUCTOR CDispInvoke (BYVAL pdisp AS IDispatch PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pdisp* | Pointer to a Dispatch interface. |
| *fAddRef* | If it is false, the object takes ownership of the interface pointer without calling AddRef. This is the usual case when we assign directly an already AddRefed pointer returned by a COM method. If it is true, then **AddRef is called**. This is needed when we pass a raw pointer. |

# <a name="Constructor2"></a>Constructor(VARIANT)

Creates a single uninitialized object of the class associated with a variant of the type VT_DISPATCH.

```
CONSTRUCTOR CDispInvoke (BYVAL vDisp AS VARIANT PTR, BYVAL fAddRef AS BOOLEAN = TRUE)
CONSTRUCTOR CDispInvoke (BYVAL vDisp AS VARIANT, BYVAL fAddRef AS BOOLEAN = TRUE)
CONSTRUCTOR CDispInvoke (BYREF cvDisp AS CVAR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *vDisp* | A VT_DISPATCH variant. |
| *fAddRef* | If it is false, the object takes ownership of the interface pointer without calling AddRef. This is the usual case when we assign directly an already AddRefed pointer returned by a COM method. If it is true, then **AddRef is called**. This is needed when we pass a raw pointer. |
| *cvDisp* | A VT_DISPATCH CVAR. |

# <a name="Constructor3"></a>Constructor(ProgID)

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

# <a name="Constructor4"></a>Constructor(CLSID)

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

Usage examples:

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
