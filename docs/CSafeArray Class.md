# CSafeArray Class

**CSafeArray** is a class that provides wrapper methods for the SAFEARRAY structure, making it easy to create and manage single- and multidimensional arrays of almost any of the VARIANT-supported types. The lower bound of a CSafeArray can start at any user-defined value.

Additional overloaded methods are provided for one and two-dimensional safe arrays, that are the ones most often used in COM programming.

**Include file**: CSafeArray.INC.

# Structures and VARTYPE

| Name       | Description |
| ---------- | ----------- |
| [SAFEARRAY](#SAFEARRAY) | Represents a safe array. |
| [SAFEARRAYBOUND](#SAFEARRAYBOUND) | Represents the bounds of one dimension of the array. |
| [VARTYPE](#VARTYPE) | Safe array Variant type. |

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor (SAFEARRAYBOUND)](#Constructor1) | Creates a CSafeArray. |
| [Constructor (CSafeArray)](#Constructor2) | Creates a CSafeArray from another CSafeArray. |
| [Constructor (SAFEARRAY PTR)](#Constructor3) | Creates a CSafeArray from a safe array. |
| [Constructor (VARIANT PTR)](#Constructor4) | Creates a CSafeArray from a Variant of type VT_ARRAY. |

# Operators

| Name       | Description |
| ---------- | ----------- |
| [Operator \*](#Operator1) | Returns a pointer to the safe array descriptor. |
| [Operator LET](#Operator2) | Assigns a CSafeArray, a safe array or a Variant. |

# Methods

| Name       | Description |
| ---------- | ----------- |
| [AccessData](#AccessData) | Increments the lock count of an array, and retrieves a pointer to the array data. |
| [Append](#Append) | Appends a value to the end of the one-dimensional safe array. |
| Attach | Attaches a safe array to a CSafeArray object. |
| Clear | Like DestroyData, destroys all the data in a safe array. It is the same that Erase and Reset. |
| Copy | Creates a copy of the safe array. |
| CopyData | Copies the source array to the target array after releasing any resources in the target array. |
| CopyFrom | Copies the contents of a safe array. |
| CopyFromVariant | Copies the contents of a VARIANT of type VT_ARRAY to the object. |
| CopyToVariant | Copies the safe array to the passed variant. |
| Count | Returns the number of elements in the specified dimension of the array. |
| Create | Creates a safe array. |
| CreateEx | Creates a safe array from the given VARTYPE, number of dimensions and bounds. |
| CreateVector | Creates a one-dimensional safe array from the given VARTYPE, lower bound and number elements. |
| CreateVectorEx | Creates a one-dimensional safe array from the given VARTYPE, lower bound and number elements. |
| Destroy | Destroys an existing array descriptor and all of the data in the array. |
| DestroyData | Destroys all the data in a safe array. |
| Detach | Detaches the sage array descriptor from the CSafeArray. |
| ElemSize | Returns the size of an element. |
| Erase | Like DestroyData, destroys all the data in a safe array. It is the same that Clear and Reset. |
| Features | Returns the flags used by the safe array. This is the same that the Flags method. |
| Find | Scans the array to search for the specified string. |
| Flags | Returns the flags used by the safe array. This is the same that the Features method. |
| Get | Retrieves a single element of the array. |
| GetIID | Returns the GUID of the interface contained within a given safe array. |
| GetPtr | Returns the address of the safe array. |
| GetRecordInfo | Retrieves the IRecordInfo interface of a UDT contained in a given safe array. |
| GetType | Returns the VARTYPE stored in the given safe array. |
| Insert | Inserts a value at the specified position of the safe array. |
| IsResizable | Tests if the safe array can be resized. |
| LBound | Returns the lower bound for any dimension of a safe array. |
| LocksCount | Returns the number of times the array has been locked without the corresponding unlock. |
| MoveFromVariant | Transfers ownership of the safe array contained in the variant parameter to this object. |
| MoveToVariant | Transfers ownership of the safe array to a variant and detaches it from the class. |
| NumDims | Returns the number of dimensions in the array. |
| PtrOfIndex | Returns a pointer to an array element. |
| Put | Stores the data element at a given location in the array. |
| Redim | Changes the right-most (least significant) bound of a safe array. |
| Remove | Deletes the specified array element. |
| RemoveStr | Deletes the specified string element from the array. |
| RemoveVar | Deletes the specified variant element from the array. |
| Reset | Like DestroyData, destroys all the data in a safe array. It is the same that Clear and Erase. |
| SetIID | Sets the GUID of the interface contained within a given safe array. |
| SetRecordInfo | Sets the IRecordInfo interface of the UDT contained in a given safe array. |
| SetRecordInfo | Sets the IRecordInfo interface of the UDT contained in a given safe array. |
| Sort | Sorts a one-dimensional VT_BSTR CSafeArray calling the C qsort function. |
| UBound | Returns the upper bound for any dimension of a safe array. |
| UnaccessData | Decrements the lock count of an array, and invalidates the pointer retrieved by AccessData. |

# Helper Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxStrJoin](#AfxStrJoin) | Returns a string consisting of all of the strings in an array, each separated by a delimiter. |
| [AfxStrSplit](#AfxStrSplit) | Splits a string into tokens. |
| [AfxXmlBase64Decode](#AfxXmlBase64Decode) | Converts the contents of a Base64 mime encoded string to an ascii string. |
| [AfxXmlBase64Encode](#AfxXmlBase64Encode) | Converts the contents of a string to Base64 mime encoding. |

# Analyzing the safe array API

| Topic |
| ----- |
| About safe arrays |
| Safe array descriptor |
| Creating a safe array |
| Putting data |
| Retrieving data |
| Rediming a safe array |
| Copying a safe array |
| Destroying a safe array |
| Getting the dimensions of a safe array |
| Getting the bounds of a safe array |
| Getting the type of a safe array |
| Setting ad getting the GUID of an interface |
| Setting and getting record information |
| Accessing data |
| Getting the element size |
| Creating vectors |

# <a name="SAFEARRAY"></a>SAFEARRAY Structure

Represents a safe array.

```
TYPE tagSAFEARRAY
   cDims as USHORT
   fFeatures as USHORT
   cbElements as ULONG
   cLocks as ULONG
   pvData as PVOID
   rgsabound(0 to 0) as SAFEARRAYBOUND
EBD TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **cDims** | Count of dimensions of the array. |
| **fFeatures** | Flags. |
| **cbElements** | Size of an element of the array. |
| **cLocks** | Number of times the array has been locked without corresponding unlock. |
| **pvData** | Pointer to the data. |
| **rgsabound** | One bound for each dimension. |

#### fFeatures Flags

| Flag       | Description |
| ---------- | ----------- |
| FADF_AUTO | An array that is allocated on the stack. |
| FADF_STATIC | An array that is statically allocated. |
| FADF_EMBEDDED | An array that is embedded in a structure. |
| FADF_FIXEDSIZE | An array that may not be resized or reallocated. |
| FADF_RECORD | An array that contains records. When set, there will be a pointer to the IRecordinfo interface at negative offset 4 in the array descriptor. |
| FADF_HAVEIID | An array that has an IID identifying interface. When set, there will be a GUID at negative offset 16 in the safe array descriptor. Flag is set only when FADF_DISPATCH or FADF_UNKNOWN is also set. |
| FADF_HAVEVARTYPE | An array that has a VT type. When set, there will be a VT tag at negative offset 4 in the array descriptor that specifies the element type. |
| FADF_BSTR | An array of BSTRs. |
| FADF_UNKNOWN | An array of IUnknown pointers. |
| FADF_DISPATCH | An array of IDispatch pointers. |
| FADF_VARIANT | An array of VARIANTs. |
| FADF_RESERVED | Bits reserved for future use. |

#### Remarks

The array rgsabound is stored with the left-most dimension in rgsabound[0] and the right-most dimension in rgsabound(cDims - 1).

The **fFeatures** flags describe attributes of an array that can affect how the array is released. The fFeatures field describes what type of data is stored in the SAFEARRAY and how the array is allocated. This allows freeing the array without referencing its containing variant. The bits are accessed using the following constants:

#### Thread Safety

All public static members of the SAFEARRAY data type are thread safe. Instance members are not guaranteed to be thread safe.

For example, consider an application that uses the SafeArrayLock and SafeArrayUnlock functions. If these functions are called concurrently from different threads on the same SAFEARRAY data type instance, an inconsistent lock count may be created. This will eventually cause the SafeArrayUnlock function to return E_UNEXPECTED. You can prevent this by providing your own synchronization code.

# <a name="SAFEARRAYBOUND"></a>SAFEARRAYBOUND Structure

Represents the bounds of one dimension of the array. The lower bound of the dimension is represented by **lLbound**, and **cElements** represents the number of elements in the dimension. The structure is defined as follows:

```
TYPE SAFEARRAYBOUND
   cElements as ULONG
   lLbound as LONG
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **cElements** | Number of elements in the dimension. |
| **lLbound** | The lower bound of the dimension. |

# <a name="VARTYPE"></a>Safe array Variant type

The base type of the array (the VARTYPE of each element of the array). The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array. All other types are legal.

| VarType    | Meaning     | Data type | strType |
| ---------- | ----------- | --------- | ------- |
| VT_BSTR | Unicode string | BSTR | "BSTR" |
| VT_I1 | Signed byte | BYTE | "BYTE" |
| VT_UI1 | Unsigned byte | UBYTE | "UBYTE" |
| VT_I2 | Signed short | SHORT | "SHORT" |
| VT_UI2 | Unsigned short | USHORT | "USHORT" |
| VT_I4 | Signed long | LONG | "LONG" |
| VT_INT | Signed long | LONG | "ULONG" |
| VT_UI4 | Unsigned long | ULONG | "LONG" |
| VT_UINT | Unsigned long | ULONG | "ULONG" |
| VT_I8 | Signed quad | LONGINT | "LONGINT" |
| VT_UI8 | Unnsigned quad | ULONGINT | "ULONGINT" |
| VT_R4 | Single | SINGLE | "SINGLE" |
| VT_R8 | Double | DOUBLE | "DOUBLE" |
| VT_CUR | Currency | CY | "CURRENCY" |
| VT_BOOL | Boolean (cast to a signed short) | SHORT | "BOOL" |
| VT_DATE | Date | DATE_ | "DATE" |
| VT_DECIMAL | Decimal structure | DECIMAL | "DECIMAL" |
| VT_VARIANT | Variant | VARIANT | "VARIANT" |
| VT_UNKNOWN | IUnknown pointer | IUnknown PTR | "UNKNOWN" |
| VT_DISPATCH | IDispatch pointer | IDispatch PTR | "DISPATCH" |

# <a name="Constructor1"></a>Constructor (SAFEARRAYBOUND)

Creates a CSafeArray.

Multidimensional array:

```
CONSTRUCTOR CSafeArray (BYVAL vt AS VARTYPE, BYVAL cDims AS UINT, BYVAL prgsabounds AS SAFEARRAYBOUND PTR)
CONSTRUCTOR CSafeArray (BYREF strType AS STRING, BYVAL cDims AS UINT, BYVAL prgsabounds AS SAFEARRAYBOUND PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *vt* | The base type of the array (the VARTYPE of each element of the array). The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array. All other types are legal. |
| *strType* | The base type of the array as a string literal. |
| *cDims* | Number of dimensions in the array. The number cannot be changed after the array is created. |
| *rgsabound* | Pointer to a vector of bounds (one for each dimension) to allocate for the array. |

One-dimensional array:

```
CONSTRUCTOR CSafeArray (BYVAL vt AS VARTYPE, BYVAL cElements AS ULONG = 0, BYVAL lLBound AS LONG = 0)
CONSTRUCTOR (BYREF strType AS STRING, BYVAL cElements AS ULONG = 0, BYVAL lLBound AS LONG = 0)
```

| Parameter  | Description |
| ---------- | ----------- |
| *vt* | The base type of the array (the VARTYPE of each element of the array). The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array. All other types are legal. |
| *strType* | The base type of the array as a string literal. |
| *cElements* | Optional. Number of elements in the array. |
| *lLBound* | Optional. The lower bound of the array. |

Two-dimensional array:

```
CONSTRUCTOR CSafeArray (BYVAL vt AS VARTYPE, BYVAL cElements1 AS ULONG, BYVAL lLBound1 AS LONG, _
   BYVAL cElements2 AS ULONG, BYVAL lLBound2 AS LONG)
CONSTRUCTOR (BYREF strType AS STRING, BYVAL cElements1 AS ULONG, BYVAL lLBound1 AS LONG, _
   BYVAL cElements2 AS ULONG, BYVAL lLBound2 AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *vt* | The base type of the array (the VARTYPE of each element of the array). The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array. All other types are legal. |
| *strType* | The base type of the array as a string literal. |
| *cElements1* | Number of elements in the first dimension of the array. |
| *lLBound1* | The lower bound of the first dimension of the array. |
| *cElements2* | Number of elements in the second dimension of the array. |
| *lLBound2* | The lower bound of the second dimension of the array. |

#### Usage examples

```
' // Two-dimensional array of BSTR
' // 2D: elements = 5, lower bound = 1
' // 2D: elements = 3, lower bound = 1
DIM rgsabounds(0 TO 1) AS SAFEARRAYBOUND = {(5, 1), (3, 1)}
DIM csa AS CSafeArray = CSafeArray(VT_BSTR, 2, @rgsabounds(0))
-or-
' // Two-dimensional array of BSTR
DIM csa AS CSafeArray = CSafeArray(VT_BSTR, 5, 1, 3, 1)

' // One-dimensional array of VT_VARIANT with 0 elements and a lower-bound of 0
DIM csa AS CSafeArray = CSafeArray(VT_VARIANT, 0, 0)
-or-
DIM csa AS CSafeArray = CSafeArray(VT_VARIANT)

' // One-dimensional array of VT_BSTR with 5 elements and a lower-bound of 1
DIM csa AS CSafeArray = CSafeArray(VT_BSTR, 5, 1)
```

# <a name="Constructor2"></a>Constructor (SAFEARRAYBOUND)

Creates a CSafeArray from another CSafeArray.

```
CONSTRUCTOR CSafeArray (BYREF csa AS CSafeArray)
```

| Parameter  | Description |
| ---------- | ----------- |
| *csa* | A CSafeArray object. |

# <a name="Constructor3"></a>CConstructor (SAFEARRAY PTR)

Creates a CSafeArray from a safe array.
```
CONSTRUCTOR CSafeArray (BYVAL psa AS SafeArray PTR)
CONSTRUCTOR CSafeArray (BYVAL psa AS SafeArray PTR, BYVAL fAttach AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *psa* | Pointer to a safe array. |
| *fAttach* | If TRUE, the safe array is attached, else a copy is made. |

# <a name="Constructor4"></a>CConstructor (VARIANT PTR)

Creates a CSafeArray from a Variant of type VT_ARRAY.

```
CONSTRUCTOR CSafeArray (BYVAL pvar AS VARIANT PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pvar* | Pointer to the VARIANT. |

# <a name="Operator1"></a>Operator *

Returns a pointer to the underlying safe array descriptor.

```
OPERATOR * () AS ANY PTR
```

#### Remark

You can also call the **GetPtr** method.

# <a name="Operator2"></a>Operator LET

Assigns a CSafeArray to another CSafeArray.<br>
Assigns a safe array to a CSafeArray.<br>
Assigns a variant of type VT_ARRAY to a CSafeArray.

```
OPERATOR Let (BYREF csa AS CSafeArray)
OPERATOR Let (BYVAL psa AS SAFEARRAY PTR)
OPERATOR Let (BYVAL pvar AS VARIANT PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *csa* | An instance of the CSafeArray class. |
| *psa* | A safe array pointer. |
| *pvar* | Pointer to a VARIANT. |

# <a name="AfxStrJoin"></a>AfxStrJoin

Returns a string consisting of all of the strings in an array, each separated by a delimiter. If the delimiter is a null (zero-length) string then no separators are inserted between the string sections. If the delimiter expression is the 3-byte value of "," which may be expressed in your source code as the string literal """,""" or as Chr(34,44,34) then a leading and trailing double-quote is added to each string section. This ensures that the returned string contains standard comma-delimited quoted fields that can be easily parsed.

```
FUNCTION AfxStrJoin (BYREF cwsa AS CSafeArray, BYREF wszDelimiter AS WSTRING = " ") AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsa* | The one-dimensional VT_BSTR CSafeArray to join. |
| *wszDelimiter* | The delimiter character. |

#### Return value

A CWSTR containing the joined string.

#### Usage example

```
DIM csa AS CSafeArray = CSafeArray("STRING", 3, 1)
csa.PutStr(1, "One")
csa.PutStr(2, "Two")
csa.PutStr(3, "Three")
DIM cws AS CWSTR = AfxStrJoin(csa, ",")
PRINT cws   ' ouput: One,Two,Three
```

# <a name="AfxStrSplit"></a>AfxStrSplit

Splits a string into tokens, which are sequences of contiguous characters separated by any of the characters that are part of delimiters.

```
FUNCTION AfxStrSplit (BYREF wszStr AS CONST WSTRING, BYREF wszDelimiters AS WSTRING = " ") AS CSafeArray
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszStr* | The string to split. |
| *wszDelimiters* | The delimiter characters. |

#### Return value

A CSafeArray containing a token in each element.

#### Usage example

```
DIM cws AS CWSTR = "- This, a sample string."
DIM cwsa AS CSafeArray = AfxStrSplit(cws, " ,.-")
FOR i AS LONG = cwsa.LBound TO cwsa.UBound
  PRINT cwsa.GetStr(i)
NEXT
```
# <a name="AfxXmlBase64Decode"></a>AfxXmlBase64Decode

Converts the contents of a Base64 mime encoded string to an ascii string.

```
FUNCTION AfxXmlBase64Decode (BYREF strData AS STRING) AS STRING
```
| Parameter  | Description |
| ---------- | ----------- |
| *strData* | The string to decode. |

#### Return value

The decoded string on success, or a null string on failure.

Remaks

Base64 is a group of similar encoding schemes that represent binary data in an ASCII string format by translating it into a radix-64 representation. The Base64 term originates from a specific MIME content transfer encoding.

Base64 encoding schemes are commonly used when there is a need to encode binary data that needs be stored and transferred over media that are designed to deal with textual data. This is to ensure that the data remains intact without modification during transport. Base64 is used commonly in a number of applications including email via MIME, and storing complex data in XML.

# <a name="AfxXmlBase64Encode"></a>AfxXmlBase64Encode

Converts the contents of a string to Base64 mime encoding.

```
FUNCTION AfxXmlBase64Encode (BYREF strData AS STRING) AS STRING
```
| Parameter  | Description |
| ---------- | ----------- |
| *strData* | The string to encode. |

#### Return value

The encoded string on succeess, or a null string on failure.

Remaks

Base64 is a group of similar encoding schemes that represent binary data in an ASCII string format by translating it into a radix-64 representation. The Base64 term originates from a specific MIME content transfer encoding.

Base64 encoding schemes are commonly used when there is a need to encode binary data that needs be stored and transferred over media that are designed to deal with textual data. This is to ensure that the data remains intact without modification during transport. Base64 is used commonly in a number of applications including email via MIME, and storing complex data in XML.

# <a name="AccessData"></a>AccessData

Retrieves a pointer to the array data and increments the lock count of an array.

```
FUNCTION AccessData () AS ANY PTR
```

#### Return value

IF it succeeds, it returns a pointer to the array data. If it fails, it returns a null pointer.

# <a name="Append"></a>Append

Appends a value to the end of the one-dimensional safe array.

```
FUNCTION Append (BYVAL pData AS ANY PTR) AS HRESULT
FUNCTION Append (BYREF cbsData AS CBSTR) AS HRESULT
FUNCTION Append (BYREF cvData AS CVAR) AS HRESULT
FUNCTION Append (BYVAL vData AS VARIANT) AS HRESULT
```

#### Return value

S_OK (0) on success or an HREUSLT CODE.

| HREUSLT  | Description |
| ---------- | ----------- |
| DISP_E_BADINDEX | The specified index is not valid. |
| E_INVALIDARG | One of the arguments is not valid. |
| E_OUTOFMEMORY | Memory could not be allocated for the element. |
| E_FAIL | The item pointed to by m_psa is not a safe array descriptor.<br>It is a fixed-size array.<br>It is not a one-dimensional array. |
