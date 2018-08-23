# COM Procedures

Assorted COM procedures.

**Include file**: AfxCOM.inc

| Name       | Description |
| ---------- | ----------- |
| [AfxAcode](#AfxAcode) | Translates unicode bytes to ansi bytes. |
| [AfxUcode](#AfxUcode) | Translates ansi bytes to unicode bytes. |
| [AfxIsBstr](#AfxIsBstr) | Checks if the passed pointer is a BSTR. |
| [AfxNewCOM(PROGID](#AfxNewCOM1) | Creates a single uninitialized object of the class associated with a specified ProgID or CLSID. |
| [AfxNewCOM(CLSID)](#AfxNewCOM2) | Creates a single uninitialized object of the class associated with a specified CLSID. |
| [AfxNewCOM(CLSID,IID)](#AfxNewCOM3) | Creates a single uninitialized object of the class associated with the specified CLSID and IID. |
| [AfxNewCOM(LibName)](#AfxNewCOM4) | Loads the specified library from file and creates an instance of an object. |
| [AfxGuid](#AfxGuid) | Converts a string into a 16-byte (128-bit) Globally Unique Identifier (GUID). |
| [AfxGuidText](#AfxGuidText) | Returns a 38-byte human-readable guid string from a 16-byte GUID. |
| [AfxSafeAddRef](#AfxSafeAddRef) | Increments the reference count for an interface on an object. |
| [AfxSafeRelease](#AfxSafeRelease) | Decrements the reference count for an interface on an object. |
| [AfxAdvise](#AfxAdvise) | Establishes a connection between the connection point object and the client's sink. |
| [AfxUnadvise](#AfxUnadvise) | Releases the events connection identified with the cookie returned by the Advise method. |
| [AfxWstrAlloc](#AfxWstrAlloc) | Takes a null terminated wide string as input, and returns a pointer to a new wide string allocated with CoTaskMemAlloc. |
| [AfxGetOleErrorInfo](#AfxGetOleErrorInfo) | Returns the description of the most recent OLE error in the current logical thread and clears the error state for the thread. |
| [AfxOleCreateFont](#AfxOleCreateFont) | Creates a standard IFont object. |
| [AfxOleCreateFontDisp](#AfxOleCreateFontDisp) | Creates a standard IFontDisp object. |
| [AfxGetVarType](#AfxGetVarType) | Returns the tyè of a variant. |
| [AfxIsVarTypeFloat](#AfxIsVarTypeFloat) | Checks if a variant contains a float value. |
| [AfxIsVariantArray](#AfxIsVariantArray) | Checks if a variant contains an array. |
| [AfxIsVariantString](#AfxIsVariantString) | Checks if a variant contains an string. |
| [AfxIsVarTypeSignedInteger](#AfxIsVarTypeSignedInteger) | Checks if a variant contains a signed integer. |
| [AfxIsVarTypeUnsignedInteger](#AfxIsVarTypeUnsignedInteger) | Checks if a variant contains an unsigned integer. |
| [AfxIsVarTypeInteger](#AfxIsVarTypeInteger) | Checks if a variant contains an integer. |
| [AfxIsVarTypeNumber](#AfxIsVarTypeNumber) | Checks if a variant contains a number. |
| [AfxVarToStr](#AfxVarToStr) | Extracts the contents of a VARIANT and returns them as a CWSTR. |
| [AfxVariantGetElementCount](#AfxVariantGetElementCount) | Retrieves the element count of a variant structure. |
| [AfxVariantToBuffer](#AfxVariantToBuffer) | Extracts the contents of a variant that contains an array of bytes. |
| [AfxVariantToString](#AfxVariantToString) | Extracts the variant value of a variant structure to a string. |
| [AfxVariantToStringAlloc](#AfxVariantToStringAlloc) | Extracts the variant value of a variant structure to a string. |

# <a name="AfxAcode"></a>AfxAcode

Translates unicode bytes to ansi bytes.

```
FUNCTION AfxAcode (BYVAL pwszStr AS WSTRING PTR, BYVAL nCodePage AS LONG = 0) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszStr* | The WSTRING or CWSTR to convert. |
| *nCodePage* | Optional. The code page used in the conversion, e.g. 1251 for Russian. If you specify CP_UTF8, the returned string will be UTF8 encoded. If you don't pass an unicode page, the function will use CP_ACP (0), which is the system default Windows ANSI code page. |

#### Return value

An ansi or UTF8 encoded string.

#### Usage example
(Russian bytes to unicode string:

```
DIM cws AS CWSTR
cws = AfxUcode(CHR(209, 229, 236, 229, 237), 1251)
MessageBoxW 0, cws, "", MB_OK
DIM s AS STRING
s = AfxAcode(cws, 1251)
MessageBoxW 0, s, "", MB_OK
```


# <a name="AfxUcode"></a>AfxUcode

Translates ansi bytes to unicode bytes. This function works like the intrinsic Free Basic WSTR function, but accepting an optional code page.

```
FUNCTION AfxUcode (BYREF ansiStr AS CONST STRING, BYVAL nCodePage AS LONG = 0) AS CWSTR
```
| Parameter  | Description |
| ---------- | ----------- |
| *ansiStr* | Ansi or UTF8 string to convert. |
| *nCodePage* | Optional. The code page used in the conversion, e.g. 1251 for Russian. If you specify CP_UTF8, it is assumed that ansiStr contains an UTF8 encoded string. If you don't pass an unicode page, the function will use CP_ACP (0), which is the system default Windows ANSI code page. |

#### Return value

The ansi or utf-8 string converted to utf-16.

#### Usage example
(Russian bytes to unicode string and then to ansi):

```
DIM cws AS CWSTR
cws = AfxUcode(CHR(209, 229, 236, 229, 237), 1251)
MessageBoxW 0, cws, "", MB_OK
DIM s AS STRING
s = AfxAcode(cws, 1251)
MessageBoxW 0, s, "", MB_OK```
```

# <a name="AfxIsBstr"></a>AfxIsBstr

Checks if the passed pointer is a BSTR.

```
FUNCTION AfxIsBstr (BYVAL pv AS ANY PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pv* | Pointer to the string. |

#### Remarks

Will return FALSE if it is a null pointer.
If it is an OLE string it must have a descriptor; otherwise, don't.
Gets the length in bytes looking at the descriptor and divides by 2 to get the number of unicode characters, that is the value returned by the FreeBASIC LEN operator. If the retrieved length if the same that the returned by LEN, then it must be an OLE string.

# <a name="AfxNewCOM1"></a>AfxNewCOM (PROGID)

Creates a single uninitialized object of the class associated with a specified ProgID or CLSID.

```
FUNCTION AfxNewCom (BYREF wszProgID AS CONST WSTRING, BYREF wszLicKey AS WSTRING = "") AS ANY PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszProgID* | The ProgID or the CLSID of the object to create.<br>A ProgID such as "MSCAL.Calendar.7"<br>A CLSID such as "{8E27C92B-1264-101C-8A2F-040224009C02}" |
| *wszLicKey* | Optional. The license key as a unicode string. |

#### Return value

An interface pointer or NULL.

#### Usage examples

```
DIM pDic AS IDictionary PTR
pDic = AfxNewCom("Scripting.Dictionary")
-or-
pDic = AfxNewCom(CLSID_Dictionary)
```
where CLSID_Dictionary has been declared as CONST CLSID_Dictionary = "{EE09B103-97E0-11CF-978F-00A02463E06F}"

# <a name="AfxNewCOM2"></a>AfxNewCOM (CLSID)

Creates a single uninitialized object of the class associated with a specified CLSID.

```
FUNCTION AfxNewCom (BYREF classID AS CONST CLSID) AS ANY PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *classID* | The CLSID (class identifier) associated with the data and code that will be used to create the object. |

#### Return value

An interface pointer or NULL.

#### Usage example

```
DIM pDic AS IDictionary PTR
pDic = AfxNewCom(CLSID_Dictionary)
```

where CLSID_Dictionary has been declared as<br>
DIM CLSID_Dictionary AS CLSID = (&hEE09B103, &h97E0, &h11CF, {&h97, &h8F, &h00, &hA0, &h24, &h63, &hE0, &h6F})

# <a name="AfxNewCOM3"></a>AfxNewCOM (CLSID, IID)

Creates a single uninitialized object of the class associated with the specified CLSID and IID.

```
FUNCTION AfxNewCom (BYREF classID AS CONST CLSID, BYREF riid AS CONST IID) AS ANY PTR
FUNCTION AfxNewCom (BYREF wszClsID AS CONST WSTRING, BYREF wszIID AS CONST WSTRING) AS ANY PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *classID* | The CLSID (class identifier) associated with the data and code that will be used to create the object. |
| *riid* | A reference to the identifier of the interface to be used to communicate with the object. |
| *wszClsID* | The CLSID in string format. |
| *wszIID* | The IID in string format. |

#### Return value

An interface pointer or NULL.

#### Usage examples

```
DIM pDic AS IDictionary PTR
pDic = AfxNewCom(CLSID_Dictionary, IID_IDictionary)
```

where CLSID_Dictionary has been declared asCONST CLSID_Dictionary = "{EE09B103-97E0-11CF-978F-00A02463E06F}"<br>
and IID_IDictionary as CONST IID_IDictionary = "{42C642C1-97E1-11CF-978F-00A02463E06F}"

# <a name="AfxNewCOM4"></a>AfxNewCOM (LibName)

Loads the specified library from file and creates an instance of an object.

```
FUNCTION AfxNewCom (BYREF wszLibName AS CONST WSTRING, BYREF rclsid AS CONST CLSID, _
   BYREF riid AS CONST IID, BYREF wszLicKey AS WSTRING) AS ANY PTR
FUNCTION AfxNewCom (BYREF wszLibName AS CONST WSTRING, BYREF wszClsid AS CONST WSTRING, _
   BYREF riid AS CONST IID, BYREF wszLicKey AS WSTRING = "") AS ANY PTR
FUNCTION AfxNewCom (BYREF wszLibName AS CONST WSTRING, BYREF wszClsid AS CONST WSTRING, _
   BYREF wszIid AS CONST WSTRING, BYREF wszLicKey AS WSTRING = "") AS ANY PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszLibName* | Full path where the library is located. |
| *classID* | The CLSID (class identifier) associated with the data and code that will be used to create the object. |
| *riid* | A reference to the identifier of the interface to be used to communicate with the object. |
| *wszClsID* | The CLSID in string format. |
| *wszIID* | The IID in string format. |
| *wszLicKey* | Optional. The license key. |

#### Return value

An interface pointer or NULL.

#### Remarks

* Not every component is a suitable candidate for use under this overloaded **AfxNewCom** function.
* Only in-process servers (DLLs) are supported.
** Components that are system components or part of the operating system, such as XML, Data Access, Internet Explorer, or DirectX, aren't supported.
* Components that are part of an application, such Microsoft Office, aren't supported.
* Components intended for use as an add-in or a snap-in, such as an Office add-in or a control in a Web browser, aren't supported.
* Components that manage a shared physical or virtual system resource aren't supported.
* Visual ActiveX controls aren't supported because they need to be initilized and activated by the OLE container.

# <a name="AfxGuid"></a>AfxGuid

Converts a string into a 16-byte (128-bit) Globally Unique Identifier (GUID). To be valid, the string must contain exactly 32 hexadecimal digits, delimited by hyphens and enclosed by curly braces. For example: {B09DE715-87C1-11D1-8BE3-0000F8754DA1}

If *pwszGuidText* is omited, **AfxGuid** generates a new unique guid.

```
FUNCTION AfxGuid (BYVAL pwszGuidText AS WSTRING PTR = NULL) AS GUID
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszGuidText* | A GUID in string format. |

#### Return value

A GUID.

# <a name="AfxGuidText"></a>AfxGuidText

Returns a 38-byte human-readable guid string from a 16-byte GUID.

```
FUNCTION AfxGuidText (BYVAL classID AS CLSID PTR) AS STRING
FUNCTION AfxGuidText (BYVAL classID AS CLSID) AS STRING
FUNCTION AfxGuidText (BYVAL riid AS REFIID) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *classID, riid* | The GUID to convert. |

#### Return value

A 38-byte human-readable guid string.

# <a name="AfxSafeAddRef"></a>AfxSafeAddRef

Increments the reference count for an interface on an object.

```
FUNCTION AfxSafeAddRef (BYVAL pv AS ANY PTR) AS ULONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pv* | The COM interface pointer. |

#### Return value

The function returns the new reference count. This value is intended to be used only for test purposes.

#### Remarks

This method should be called for every new copy of a pointer to an interface on an object. For example, if you are passing a copy of a pointer back from a method, you must call **AddRef** on that pointer. You must also call **AddRef** on a pointer before passing it as an in-out parameter to a method; the method will call **IUnknown_Release** before copying the out-value on top of it.

Objects use a reference counting mechanism to ensure that the lifetime of the object includes the lifetime of references to it. You use AddRef to stabilize a copy of an interface pointer. It can also be called when the life of a cloned pointer must extend beyond the lifetime of the original pointer. The cloned pointer must be released by calling **AfxSafeRelease**.

# <a name="AfxSafeRelease"></a>AfxSafeRelease

Decrements the reference count for an interface on an object and sets the value of the passed pointer to NULL.

```
FUNCTION AfxSafeRelease (BYVAL pv AS ANY PTR) AS ULONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pv* | The COM interface pointer to release. |

#### Return value

The function returns the new reference count. This value is intended to be used only for test purposes.

#### Remarks

When the reference count on an object reaches zero, Release must cause the interface pointer to free itself. When the released pointer is the only existing reference to an object (whether the object supports single or multiple interfaces), the implementation must free the object.
