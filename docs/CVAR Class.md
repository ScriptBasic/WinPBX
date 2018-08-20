# CVAR Class

The CVar class implements a VARIANT data type. The variant data type is a tagged union that can be used to represent any other data type. While lacking in efficiency, they are heavily used in COM Automation for its flexibility. The main purpose of the CVar class is to make its use as easy as possible when you need to use them to work with COM Automation objects.

**Include file**: CVAR.INC.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors) | Initialize the class with the specified value. |
| [Operators](#Operators) | Procedures that perform a certain function with their operands. |
| [vType](#vType) | Returns the VARIANT type. |
| [bstr](#bstr) | Extracts the content of the underlying variant and returns it as a CBSTR. Same as ToBStr. |
| [sptr](#sptr) | Returns the address of the underlying variant. Same as vptr but without clearing the variant. |
| [vptr](#vptr) | Clears the CVAR and returns the address of the underlying variant. |
| [wstr](#wstr) | Extracts the content of the underlying variant and returns it as a CWSTR. Same as ToStr. |
| [Attach](#Attach) | Attaches a variant to the class. |
| [Detach](#Detach) | Detaches the variant data from this class and transfers ownership to the passed variant. |
| [ChangeType](#ChangeType) | Converts the variant from one type to another. |
| [ChangeTypeEx](#ChangeTypeEx) | Converts the variant from one type to another. |
| [GetDim](#GetDim) | Gets the number of dimensions in the array. |
| [GetLBound](#GetLBound) | Gets the lower bound for the specified dimension of the safe array. |
| [GetUBound](#GetUBound) | Gets the upper bound for the specified dimension of the safe array. |
| [DecToCY](#DecToCY) | Converts a CVAR of type decimal to a CY structure. |
| [DecToDouble](#DecToDouble) | Converts a CVAR of type decimal to a double. |
| [FormatNumber](#FormatNumber) | Formats a CVAR containing numbers into a string form. |
| [GetBooleanElem](#GetBooleanElem) | Extracts a single boolean element from a safe array of booleans. |
| [GetDoubleElem](#GetDoubleElem) | Extracts a single DOUBLE element from a safe array of doubles. |
| [GetElementCount](#GetElementCount) | Gets the number of elements in the array. |
| [GetLongElem](#GetLongElem) | Extracts a single LONG element from a safe array of longs. |
| [GetLongIntElem](#GetLongIntElem) | Extracts a single LONGINT element from a safe array of long integers. |
| [GetShortElem](#GetShortElem) | Extracts a single SHORT element from a safe array of shorts. |
| [GetStringElem](#GetStringElem) | Extracts a single BSTR element from a safe array of unicode strings. |
| [GetULongElem](#GetULongElem) | Extracts a single ULONG element from a safe array of unsigned longs. |
| [GetULongIntElem](#GetULongIntElem) | Extracts a single ULONGINT element from a safe array of unsigned long integers. |
| [GetUShortElem](#GetUShortElem) | Extracts a single USHORT element from a safe array of unsigned shorts. |
| [GetVariantElem](#GetVariantElem) | Extracts a single Variant element from a safe array of variants. |
| [Put](#Put) | Assigns values to a CVAR. |
| [PutBool](#PutBool) | Assigns a boolean value. |
| [PutBoolean](#PutBoolean) | Assigns a boolean value. |
| [PutByte](#PutByte) | Assigns a byte value. |
| [PutBooleanArray](#PutBooleanArray) | Initializes CVAR from an array of Boolean values. |
| [PutBuffer](#PutBuffer) | Initializes CVAR with the contents of a buffer. |
| [PutDateString](#PutDateString) | Initializes CVAR VT_DATE from a string. |
| [PutDec](#PutDec) | Initializes CVAR with the contents of a DECIMAL structure. |
| [PutDecFromCY](#PutDecFromCY) | Converts a currency value to a variant of type VT_DECIMAL. |
| [PutDecFromDouble](#PutDecFromDouble) | Converts a double value to a variant of type VT_DECIMAL. |
| [PutDecFromStr](#PutDecFromStr) | Initializes CVAR as VT_DECIMAL from a string. |
| [PutDouble](#PutDouble) | Assigns a double value. |
| [PutDoubleArray](#PutDoubleArray) | Initializes CVAR from an array of unsigned 64-bit integer values. |
| [PutFileTime](#PutFileTime) | Initializes CVAR with the contents of a FILETIME structure. |
| [PutFileTimeArray](#PutFileTimeArray) | Initializes CVAR with an array of FILETIME structures. |
| [PutFloat](#PutFloat) | Assigns a single value. |
| [PutGuid](#PutGuid) | Initializes CVAR from a GUID. |
| [PutInt](#PutInt) | Assigns an int_ value. |
| [PutLong](#PutLong) | Assigns a long value. |
| [PutLongArray](#PutLongArray) | Initializes CVAR from an array of signed 32-bit integer values. |
| [PutLongIntArray](#PutLongIntArray) | Initializes CVAR from an array of signed 64-bit integer values. |
| [PutLongInt](#PutLongInt) | Assigns a longint value. |
| [PutNull](#PutNull) | Assigns a null value. |
| [PutPropVariant](#PutPropVariant) | Initializes CVAR from the contents of a PROPVARIANT structure. |
| [PutRecord](#PutRecord) | Initializes CVAR with a reference to an UDT. |
| [PutRef](#PutRef) | Assigns a value by reference (a pointer to a variable). |
| [PutResource](#PutResource) | Initializes the CVAR based on a string resource imbedded in an executable file. |
| [PutSafeArray](#PutSafeArray) | Initializes CVAR from a safe array. |
| [PutStringArray](#PutStringArray) | Initializes CVAR from an array of unsigned 64-bit integer values. |
| [PutUInt](#PutUInt) | Assigns an uint value. |
| [PutShort](#PutShort) | Assigns a short value. |
| [PutShortArray](#PutShortArray) | Initializes CVAR from an array of signed 16-bit integer values. |
| [PutSingle](#PutSingle) | Assigns a single value. |
| [PutStrRet](#PutStrRet) | Initializes CVAR with string stored in a STRRET structure. |
| [PutSystemTime](#PutSystemTime) | Initializes CVAR with the contents of a SYSTEMTIME structure. |
| [PutUByte](#PutUByte) | Assigns an ubyte value. |
| [PutULong](#PutULong) | Assigns an ulong value. |
| [PutULongArray](#PutULongArray) | Initializes CVAR from an array of 32-bit unsigned integer values. |
| [PutULongInt](#PutULongInt) | Initialies a CVAR from am ULONGINT. |
| [PutULongArray](#PutULongArray) | Initializes CVAR from an array of unsigned 64-bit integer values. |
| [PutULongInt](#PutULongInt) | Assigns an ulongint value. |
| [PutUShort](#PutUShort) | Assigns an ushort value. |
| [PutUshortArray](#PutUshortArray) | Initializes CVAR from an array of 16-bit integer values. |
| [PutUtf8](#PutUtf8) | Initializes CVAR with the contents of an UTF-8 string. |
| [PutVariantArrayElem](#PutVariantArrayElem) | Initializes CVAR with a value stored in another VARIANT structure. |
| [PutVbDate](#PutVbDate) | Initializes CVAR with the contents of a DATE value. |
| [Round](#Round) | Rounds a variant to the specified number of decimal places. |
| [ToBooleanArray](#ToBooleanArray) | Extracts an array of boolean values from CVAR. |
| [ToBooleanArrayAlloc](#ToBooleanArrayAlloc) | Extracts an array of boolean values from CVAR. |
| [ToBstr](#ToBstr) | Extracts the content of the underlying variant and returns it as a CBSTR. Same as bstr. |
| [ToBuffer](#ToBuffer) | Extracts the contents of a CVAR of type VT_ARRRAY OR VT_UI1 to a buffer. |
| [ToDosDateTime](#ToDosDateTime) | Extracts a date and time value in Microsoft MS-DOS format from a CVAR of type VT_DATE. |
| [ToDoubleArray](#ToDoubleArray) | Extracts an array of DOUBLE values from CVAR. |
| [ToDoubleArrayAlloc](#ToDoubleArrayAlloc) | Extracts an array of DOUBLE values from CVAR. |
| [ToFileTime](#ToFileTime) | Returns the contents of a CVAR of type VT_DATE as a FILETIME structure. |
| [ToGuid](#ToGuid) | Returns the contents of a CVAR containing a GUID string as a GUID structure. |
| [ToGuidBStr](#ToGuidBStr) | Returns the contents of a CVAR containing a GUID string as an unicode GUID string. Same as ToGuidWstr. |
| [ToGuidStr](#ToGuidStr) | Returns the contents of a CVAR containing a GUID string as an unicode GUID string. Same as ToGuidWstr. |
| [ToGuidWStr](#ToGuidWStr) | Returns the contents of a CVAR containing a GUID string as an unicode GUID string. Same as ToGuidStr. |
| [ToLongArray](#ToLongArray) | Extracts an array of LONG values from CVAR. |
| [ToLongArrayAlloc](#ToLongArrayAlloc) | Extracts an array of LONG values from CVAR. |
| [ToLongIntArray](#ToLongIntArray) | Extracts an array of LONGINT values from CVAR. |
| [ToLongIntArrayAlloc](#ToLongIntArrayAlloc) | Extracts an array of LONGINT values from CVAR. |
| [ToShortArray](#ToShortArray) | Extracts an array of Int16 values from CVAR. |
| [ToShortArrayAlloc](#ToShortArrayAlloc) | Extracts an array of SHORT values from CVAR. |
| [ToStr](#ToStr) | Extracts the content of the underlying variant and returns it as a CWSTR. Same as wstr and ToWStr. |
| [ToStringArray](#ToStringArray) | Extracts data from a vector structure into a PWSTR array. |
| [ToStringArrayAlloc](#ToStringArrayAlloc) | Extracts an array of PWSTR values from CVAR. |
| [ToStrRet](#ToStrRet) | Returns the contents of a CVAR of type VT_BSTR to a STRRET stucture. |
| [ToSystemTime](#ToSystemTime) | Returns the contents of CVAR of type VT_DATE as a FILETIME structure. |
| [ToULongArray](#ToULongArray) | Extracts an array of ULONG values from CVAR. |
| [ToULongArrayAlloc](#ToULongArrayAlloc) | Extracts an array of ULONG values from CVAR. |
| [ToULongIntArray](#ToULongIntArray) | Extracts an array of ULONGINT values from CVAR. |
| [ToULongIntArrayAlloc](#ToULongIntArrayAlloc) | Extracts an array of ULONGINT values from CVAR. |
| [ToUShortArray](#ToUShortArray) | Extracts an array of USHORT values from CVAR. |
| [ToUShortArrayAlloc](#ToUShortArrayAlloc) | Extracts an array of USHORT values from CVAR. |
| [ToUtf8](#ToUtf8) | Returns the contents of a CVAR containing a BSTR as an UTF-8 encoded string. |
| [ToVbDate](#ToVbDate) | Returns the contents of a CVAR of type VT_DATE as a DATE value. |
| [ToWStr](#ToWStr) | Extracts the content of the underlying variant and returns it as a CWSTR. Same as wstr and ToStr. |

#### Numeric Conversions

| Name       | Description |
| ---------- | ----------- |
| [ValDouble](#ValDouble) | Converts the variant to a floating point number (DOUBLE). |
| [ValInt](#ValInt) | Converts the variant to a signed 32-bit integer (LONG). |
| [ValLong](#ValLong) | Converts the variant to a signed 32-bit integer (LONG). |
| [ValLongInt](#ValLongInt) | Converts the variant to a signed 64-bit integer (LONGINT). |
| [Value](#Value) | Converts the variant to a floating point number (DOUBLE). |
| [ValUInt](#ValUInt) | Converts the variant to a 32.bit unsigned integer (ULONG). |
| [ValULong](#ValULong) | Converts the variant to a 32-bit unsigned integer (ULONG). |
| [ValULongInt](#ValULongInt) | Converts the variant to a 64-bit unsigned integer (ULONGINT). |

#### Helper Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxCVarToStr](#AfxCVarToStr) | Extracts the contents of a CVAR to a CWSTR. |
| [AfxCVarOptPrm](#AfxCVarOptPrm) | Returns a CVAR suitable to be used with optional parameters. |
| [AfxCVariantToBuffer](#AfxCVariantToBuffer) | Extracts the contents of a variant that contains an array of bytes. |

# <a name="Constructors"></a>Constructors

Creates a an instance of the CVAR class.

```
CONSTRUCTOR
CONSTRUCTOR (BYREF cv AS CVAR)
CONSTRUCTOR (BYVAL v AS VARIANT)
CONSTRUCTOR (BYREF wsz AS WSTRING)
CONSTRUCTOR (BYREF cws AS CWSTR)
CONSTRUCTOR (BYREF cbs AS CBSTR)
CONSTRUCTOR (BYVAL pvar AS VARIANT PTR)
CONSTRUCTOR (BYVAL cy AS CURRENCY)
CONSTRUCTOR (BYVAL dec AS DECIMAL)
CONSTRUCTOR (BYREF pDisp AS IDispatch PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
CONSTRUCTOR (BYREF pUnk AS IUnknown PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
CONSTRUCTOR (BYVAL _value AS LONGINT, BYVAL _vType AS WORD = VT_I4)
CONSTRUCTOR (BYVAL _value AS DOUBLE, BYVAL _vType AS WORD = VT_R8)
CONSTRUCTOR (BYVAL _value AS LONGINT, BYREF strType AS STRING)
CONSTRUCTOR (BYVAL _value AS DOUBLE, BYREF strType AS STRING)
CONSTRUCTOR (BYVAL _pvar AS ANY PTR, BYVAL _vType AS WORD)
CONSTRUCTOR (BYVAL _pvar AS ANY PTR, BYREF strType AS STRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cv* | A CVAR. |
| *v* | A VARIANT. |
| *pvar* | Pointer to a VARIANT. |
| *cy* | A currency structure. |
| *dec* | A decimal structure. |
| *pwsz* | Pointer to an unicode string. You can also pass a Free Basic ansi string or a string literal. |
| *cbs* | A CBSTR. |
| *cws* | A CWSTR. |
| *pDisp* | Pointer to a DISPATCH interface. |
| *pUnk* | Pointer to a UNKNOWN interface. |
| *_value* | A numeric value or variable. |
| *_pvar* | Pointer to a variable. This will create a VT_BYREF variant of the specified type. |
| *_vtype* | The variant type, e.g. VT_I4, VT_UI4. |
| *strType* | The variant type as a string: "BOOL", "BYTE", "UBYTE", "SHORT", "USHORT, "INT", UINT", "LONG", "ULONG", "LONGINT", "SINGLE, "DOUBLE", "NULL". |
| *fAddRef* | TRUE or FALSE. If TRUE, increases the reference count of the passed interface. |

# <a name="Operators"></a>Operators

Procedures that perform a certain function with their operands. They do the same actions that the native FreeBasic operators but with variants. For detailed descriptions see the FreeBasic documentation.

Global Operators

```
OPERATOR & (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS CVAR
OPERATOR * (BYREF cv AS CVAR) AS VARIANT PTR
```

Cast Operators

```
OPERATOR Cast () AS VARIANT
OPERATOR Cast () AS VARIANT PTR
```

Assignment operators

```
OPERATOR Let (BYREF cv AS CVAR)
OPERATOR Let (BYVAL v AS VARIANT)
OPERATOR Let (BYVAL pvar AS VARIANT PTR)
OPERATOR Let (BYVAL cy AS CURRENCY)
OPERATOR Let (BYVAL dec AS DECIMAL)
OPERATOR Let (BYREF cbs AS CBSTR)
OPERATOR Let (BYREF cws AS CWSTR)
OPERATOR Let (BYREF pDisp AS IDispatch PTR)
OPERATOR Let (BYREF pUnk AS IUnknown PTR)
OPERATOR Let (BYVAL _value AS LONGINT)
OPERATOR Let (BYVAL _value AS DOUBLE)
OPERATOR += (BYREF cv AS CVAR)
OPERATOR -= (BYREF cv AS CVAR)
OPERATOR *= (BYREF cv AS CVAR)
OPERATOR /= (BYREF cv AS CVAR)
OPERATOR \= (BYREF cv AS CVAR)
OPERATOR Mod= (BYREF cv AS CVAR)
OPERATOR Imp= (BYREF cv AS CVAR)
OPERATOR Eqv= (BYREF cv AS CVAR)
OPERATOR ^= (BYREF cv AS CVAR)
```

Arithmetic operators

```
OPERATOR + (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS CVAR
OPERATOR - (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS CVAR
OPERATOR * (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS CVAR
OPERATOR / (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS CVAR
OPERATOR \ (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS CVAR
OPERATOR ^ (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS DOUBLE
OPERATOR Mod (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS INTEGER
OPERATOR - (BYREF cv AS CVAR) AS CVAR
```

Relational operators

```
OPERATOR = (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS BOOLEAN
OPERATOR <> (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS BOOLEAN
OPERATOR < (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS BOOLEAN
OPERATOR > (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS BOOLEAN
OPERATOR <= (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS BOOLEAN
OPERATOR >= (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS BOOLEAN
```

Bitwise operators

```
OPERATOR And (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS INTEGER
OPERATOR Eqv (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS INTEGER
OPERATOR Imp (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS INTEGER
OPERATOR Not (BYREF cv AS CVAR) AS INTEGER
OPERATOR Or (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS INTEGER
OPERATOR Xor (BYREF cv1 AS CVAR, BYREF cv2 AS CVAR) AS INTEGER
```

# <a name="vType"></a>vType

Returns the VARIANT type.

```
FUNCTION vType () AS VARTYPE
```

For a list of data types, see For a list of data types, see [VARENUM Enumeration](https://msdn.microsoft.com/en-us/library/windows/desktop/ms221170(v=vs.85).aspx)

| Type                | Description                              | VARIANT | Typedesc | Property set | Safe array |
| ------------------- | ---------------------------------------- | ------- | -------- | ------------ | ---------- |
| VT_EMPTY            | Not specified. |
| VT_NULL             | Null. |
| VT_I2               | A 2-byte integer. |
| VT_I4               | A 4-byte integer. |
| VT_R4               | A 4-byte real. |
| VT_R8               | A 8-byte real. |
| VT_CY               | Currency. |
| VT_DATE             | A date. |
| VT_BSTR             | A string. |
| VT_DISPATCH         | An IDispatch pointer. |
| VT_ERROR            | An SCODE value. |
| VT_BOOL             | A Boolean value (True = -1, False = 0) |
| VT_VARIANT          | A variant pointer. |
| VT_UNKNOWN          | An IUnknown pointer. |
| VT_DECIMAL          | A 16-byte fixed-pointer value. |
| VT_I1               | A character. |
| VT_UI1              | An unsigned character. |
| VT_UI2              | An unsigned short. |
| VT_UI4              | An unsigned long. |
| VT_I8               | A 64-bit integer. |
| VT_UI8              | A 64-bit unsigned integer. |
| VT_INT              | An integer. |
| VT_UINT             | An unsigned integer. |
| VT_VOID             | A C-style void. |
| VT_HRESULT          | An HRESULT value. |
| VT_PTR              | A pointer type. |
| VT_SAFEARRAY        | A safe array. Use VT_ARRAY in VARIANT. |
| VT_CARRAY           | A C-style array. |
| VT_USERDEFINED      | A user-defined type. |
| VT_LPSTR            | A null-terminated string. |
| VT_LPWSTR           | A wide null-terminated string. |
| VT_RECORD           | A user-defined type. |
| VT_INT_PTR          | A signed machine register size width. |
| VT_UINT_PTR         | An unsigned machine register size width. |
| VT_FILETIME         | A FILETIME value. |
| VT_BLOB             | Length-prefixed bytes. |
| VT_STREAM           | The name of the stream follows. |
| VT_STORAGE          | The name of the storage follows. |
| VT_STREAMED_OBJECT  | The stream contains an object. |
| VT_STORED_OBJECT    | The storage contains an object. |
| VT_BLOB_OBJECT      | The blob contains an object. |
| VT_CF               | A clipboard format. |
| VT_CLSID            | A class ID. |
| VT_VERSIONED_STREAM | A stream with a GUID version. |
| VT_BSTR_BLOB        | Reserved. |
| VT_VECTOR           | A simple counted array. |
| VT_ARRAY            | A SAFEARRAY pointer. |
| VT_BYREF            | A void pointer for local use. |
| VT_RESERVED         | Reserved. |
| VT_ILLEGAL          |  |
| VT_ILLEGALMASKED    |  |
| VT_TYPEMASK         |  |


# <a name="bstr"></a>bstr

Extracts the content of the underlying variant and returns it as a CBSTR. Same as ToBStr.

```
FUNCTION bstr () AS CBSTR
```

# <a name="sptr"></a>sptr

Returns the address of the underlying variant. Same as vptr but without clearing the variant.

```
FUNCTION sptr () AS VARIANT PTR
```

# <a name="vptr"></a>vptr

Clears the CVAR and returns the address of the underlying variant. Can be used to pass the variant to an OUT BYVAL VARIANT PTR parameter. If we pass a CVAR to a function with an OUT variant parameter without first clearing the contents of the CVAR, we may have a memory leak.

```
FUNCTION vptr () AS VARIANT PTR
```

# <a name="wstr"></a>wstr

Extracts the content of the underlying variant and returns it as a CWSTR. Same as ToStr.

```
FUNCTION wstr () AS CWSTR
```
