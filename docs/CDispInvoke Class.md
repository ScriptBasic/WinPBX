# CDispInvoke Class

*CDispInvoke* allows to call COM methods and properties with Free Basic.

**Include file:* CDispInvoke.inc

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor (IDispatch)](#Constructor1) | Creates a single uninitialized object of the class associated with a pointer to a Dispatch interface. |
| [Constructor (VARIANT)](#Constructor2) | Creates a single uninitialized object of the class associated with a variant of the type VT_DISPATCH. |
| [Constructor (PROGID)](#Constructor3) | Creates a single uninitialized object of the class associated with a specified ProgID or CLSID. |
| [Constructor (CLSID)](#Constructor4) | Creates a single uninitialized object of the class associated with a specified CLSID. |
| [Constructor (LibName)](#Constructor5) | Loads the specified library from file and creates an instance of an object. |

# Operators

| Name       | Description |
| ---------- | ----------- |
| [Operator *](#Operator1) | Returns the underlying IDispatch pointer. |
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

