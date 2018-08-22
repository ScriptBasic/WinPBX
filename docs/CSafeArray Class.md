# CSafeArray Class

**CSafeArray** is a class that provides wrapper methods for the SAFEARRAY structure, making it easy to create and manage single- and multidimensional arrays of almost any of the VARIANT-supported types. The lower bound of a CSafeArray can start at any user-defined value.

Additional overloaded methods are provided for one and two-dimensional safe arrays, that are the ones most often used in COM programming.

**Include file**: CSafeArray.INC.

# Constructors

| Name       | Description |
| ---------- | ----------- |
| Constructor (SAFEARRAYBOUND) | Creates a safe array. |
| Constructor (CSafeArray) | Creates a safe array from another CSafeArray. |
| Constructor (SAFEARRAY PTR) | Creates a safe array from a SafeArray. |
| Constructor (VARIANT PTR) | Creates a safe array from a variant of type VT_ARRAY. |

# Operators

| Name       | Description |
| ---------- | ----------- |
| Operator * | Returns a pointer to the safe array descriptor. |
| Operator LET | Assigns a CSafeArray, a safe array or a Variant. |

# Structures

| Name       | Description |
| ---------- | ----------- |
| SAFEARRAY | Represents a safe array. |
| SAFEARRAYBOUND | Represents the bounds of one dimension of the array. |

# Methods

| Name       | Description |
| ---------- | ----------- |
| AccessData | Increments the lock count of an array, and retrieves a pointer to the array data. |
| Append | Appends a value to the end of the one-dimensional safe array. |
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
| AfxStrSplit | Splits a string into tokens. |
| AfxStrJoin | Returns a string consisting of all of the strings in an array, each separated by a delimiter. |
| AfxXmlBase64Decode | Converts the contents of a Base64 mime encoded string to an ascii string. |
| AfxXmlBase64Encode | Converts the contents of a string to Base64 mime encoding. |

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

#### Important note

Because it uses COM, you must initialize the COM library before calling this function.

**Include file**: CSafeArray.inc

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

#### Important note

Because it uses COM, you must initialize the COM library before calling this function.