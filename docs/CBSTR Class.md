# CBSTR Class

The **CBSTR** class implements a dynamic unicode null terminated string. Free Basic has a dynamic string data type (STRING) and a fixed length unicode data type (WSTRING), but it lacks a dynamic unicode string. **CBSTR** behaves as if it was a native data type, working directly with the intrinsic Free Basic string functions and operators.

**Include file**: CWSTR.INC.

Quirks:

* MID as a statement: Something like MID(cbs, 2, 1) = "x" compiles but does not change the contents of the dynamic unicode string. MID(**cbs, 2, 1) = "x" works.
* SELECT CASE: Something like SELECT CASE LEFT(cbs, 2) does not compile; we have to use SELECT CASE LEFT(**cbs, 2). Same problem with RIGHT, but not with MID.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors) | Initialize the class with the specified value. |
| [Operator \*](#Operator*) | One * returns the address of the CBSTR buffer.<br> Two ** returns the address of the start of the string data. |
| [sptr](#sptr) | Returns the address of the string data. Same as \*. |
| [vptr](#vptr) | Returns the address of the CWSTR buffer. Same as \* |
| [wstr](#wstr) | Returns the string data. Same as \*\*. |
| [Operator &](#Operator&) | Concatenates strings. |
| [Operator +=](#Operator+=) | Appends a string to the CWSTR. |
| [Operator &=](#Operator&=) | Appends a string to the CWSTR. |
| [Operator Let](#OperatorLet) | Assigns a string to the CWSTR. It implements the = operator. |
| [Operator Cast](#OperatorCast) | Returns a pointer to the CWSTR buffer or the string data.<br>Casting is automatic. You don't have to call this operator. |
| [wstr](#wstr) | Returns the string data. Same as **. |
| [wchar](#wchar) | Returns the string data as a new unicode string allocated with CoTaskMemAlloc. |
| [Utf8](#Utf8) | Converts from UTF8 to Unicode and from Unicode to UTF8. |
| [Append](#Append) | Appends a string to the CBSTR. |
| [Attach](#Attach) | Attaches a BSTR to the CBSTR class. |
| [Detach](#Detach) | Detaches the underlying BSTR from the CBSTR class and returns it as the result of the function. |
| [Clear](#Clear) | Frees the underlying BSTR. |
| [Empty](#Clear) | Frees the underlying BSTR. |
| [Left](#Left) | Returns the leftmost substring of the string. Same as LEFT. |
| [Right](#Right) | Returns the rightmost substring of the string. Same as RIGHT. |
| [LeftChars](#LeftChars) | Returns the leftmost substring of the string. Same as Left. |
| [MidChars](#MidChars) | Returns a substring of the string. Same as Mid. |
| [RightChars](#RightChars) | Returns the rightmost substring of the string. Same as Right. |
| [Resize](#Resize) | Resizes the string to a length of the specified number of characters. |
| [SizeAlloc](#SizeAlloc) | Sets the capacity of the buffer in characters. |
| [SizeOf](#SizeOf) | Returns the capacity of the buffer in characters. |
| [Val](#Val) | Converts the string to a floating point number (DOUBLE). |
| [ValDouble](#ValDouble) | Converts the string to a floating point number (DOUBLE). |
| [ValInt](#ValInt) | Converts the string to a signed 32-bit integer (LONG). |
| [ValLong](#ValLong) | Converts the string to a signed 32-bit integer (LONG). |
| [ValLongInt](#ValLongInt) | Converts the string to a signed 64-bit integer (LONGINT). |
| [Value](#Value) | Converts the string to a floating point number (DOUBLE). |
| [ValUInt](#ValUInt) | Converts the string to a 32.bit unsigned integer (ULONG). |
| [ValULong](#ValULong) | Converts the string to a 32-bit unsigned integer (ULONG). |
| [ValULongInt](#ValULongInt) | Converts the string to a 64-bit unsigned integer (ULONGINT). |

# <a name="Constructors"></a>Constructors

Initialize the class with the specified value.

```
CONSTRUCTOR CBStr
CONSTRUCTOR CBStr (BYREF wszStr AS CONST WSTRING = "")
CONSTRUCTOR CBStr (BYREF cws AS CWSTR)
CONSTRUCTOR CBStr (BYREF cbs AS CBSTR)
CONSTRUCTOR CBStr (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0)
CONSTRUCTOR (BYVAL n AS LONGINT)
CONSTRUCTOR (BYVAL n AS DOUBLE)
CONSTRUCTOR (BYREF bstrHandle AS AFX_BSTR = NULL, BYVAL fAttach AS LONG = TRUE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszStr* | A WSTRING. |
| *cws* | A CWSTR. |
| *cbs* | A CBSTR. |
| *ansiStr* | An ansi string or string literal. |
| *nCodePage* | The code page to be used for ansi to unicode conversions. |
| *n* | A number. |
| *bstrHandle* | A handle to a BSTR.. |
| *fAttach* | TRUE = Attaches the BSTR handle to the class. It will be released when the class is destroyed; therefore, don't free the passed handle. FALSE = The contents of the passed BSTR are copied.. |

For a list of code pages see: [Code Page Identifiers](https://msdn.microsoft.com/en-us/library/windows/desktop/dd317756(v=vs.85).aspx)

# Operators

#### <a name="Operator*"></a>Operator *

Deferences the CWSTR.<br>One * returns the address of the CWSTR buffer.<br>Two ** returns the address of the start of the string data.

#### <a name="sptr"></a>sptr

Returns the address of the string data. Same as *.

#### <a name="vptr"></a>vptr

Returns the address of the string buffer. Same as *.

#### <a name="wstr"></a>wstr

Returns the string data. Same as **.

#### <a name="Operator&"></a>Operator &

Concatenates strings.

#### <a name="Operator+="></a>Operator +=

Appends a string to the CWSTR.

#### <a name="Operator&="></a>Operator &=

Appends a string to the CWSTR.

#### <a name="Operator[]"></a>Operator []

Appends a string to the CWSTR.

#### <a name="OperatorLet"></a>Operator Let

Assigns a string to the CWSTR.

```
OPERATOR LET (BYREF wszStr AS CONST WSTRING)
OPERATOR LET (BYVAL pwszStr AS WSTRING PTR)
OPERATOR LET (BYREF cws AS CWStr)
OPERATOR LET (BYREF cbs AS CBStr)
OPERATOR LET (BYREF ansiStr AS STRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszStr* | A WSTRING. |
| *pwszStr* | A pointer to a WSTRING. |
| *cws* | A CWSTR. |
| *cbs* | A CBSTR. |
| *ansiStr* | An ansi string or string literal. |

# Casting and Conversions

#### <a name="OperatorCast"></a>Operator Cast

```
OPERATOR CAST () BYREF AS WSTRING
OPERATOR CAST () AS ANY PTR
```

Returns a pointer to the CWSTR buffer or the string data. These operators aren't called directly.

#### <a name="bstr"></a>bstr

Returns the contents of the CWSTR as a BSTR.

#### <a name="cbstr"></a>cbstr

Returns the contents of the CWSTR as a CBSTR.

#### <a name="wchar"></a>wchar

Returns the string data as a new unicode string allocated with CoTaskMemAlloc.
Useful when we need to pass a pointer to a null terminated wide string to a function or method that will release it. If we pass a WSTRING it will GPF. If the length of the input string is 0, CoTaskMemAlloc allocates a zero-length item and returns a valid pointer to that item. If there is insufficient memory available, CoTaskMemAlloc returns NULL.

#### <a name="Utf8"></a>Utf8

Converts from UTF8 to Unicode and from Unicode to UTF8.

```
PROPERTY Utf8() AS STRING
PROPERTY Utf8 (BYREF utf8String AS STRING)
```

# Methods

#### <a name="Capacity"></a>Capacity

Gets/sets the size of the internal buffer. The size is the number of bytes which can be stored without further expansion.

```
PROPERTY Capacity() AS UINT
PROPERTY Capacity (BYVAL nValue AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nValue* | The new capacity value, in bytes. If the new capacity is equal to the current capacity, no operation is performed; is it is smaller, the buffer is shortened and the contents that exceed the new capacity are lost. If you pass an odd number, 1 is added to the value to make it even. |

#### <a name="GrowSize"></a>GrowSize

Gets/sets the size of the internal buffer. The size is the number of bytes which can be stored without further expansion.

```
PROPERTY GrowSize () AS LONG
PROPERTY GrowSize (BYVAL nChars AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nChars* | The new grow size value, in characters.  A value of less than 0 indicates that it must double the capacity each time that the buffer needs to be resized. |

#### <a name="Add"></a>Add

The passed string parameter is appended to the string starting at the specified position.

```
SUB Add (BYREF cws AS CWSTR, BYVAL nIndex AS UINT)
SUB Add (BYREF cbs AS CBSTR, BYVAL nIndex AS UINT)
SUB Add (BYVAL pwszStr AS WSTRING PTR, BYVAL nIndex AS UINT)
SUB Add (BYREF ansiStr AS STRING, BYVAL nIndex AS UINT, BYVAL nCodePage AS UINT = 0)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszStr* | A WSTRING. |
| *cws* | A CWSTR. |
| *cbs* | A CBSTR. |
| *ansiStr* | An ansi string or string literal. |
| *nIndex* | The starting position (1 for the first character, 2 for the second, etc.). |
| *nCodePage* | The code page to be used for ansi to unicode conversions. |

For a list of code pages see: [Code Page Identifiers](https://msdn.microsoft.com/en-us/library/windows/desktop/dd317756(v=vs.85).aspx)

#### <a name="Char"></a>Char

Gets or sets the corresponding unicode integer representation of the character at the position specified by the *nIndex* parameter.

```
PROPERTY Char (BYVAL nIndex AS UINT) AS USHORT
PROPERTY Char (BYVAL nIndex AS UINT, BYVAL nValue AS USHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nIndex* | The one based index of the character in the string (1 for the first character, 2 for the second, etc.). If nIndex is beyond the current length of the string, a 0 is returned. |
| *nValue* | The unicode integer representation of the character. |

#### <a name="Clear"></a>Clear

Erases all the data in the class object.

```
SUB Clear
```

Actually, this method only sets the buffer length to zero, indicating no string in the buffer. The allocated memory for the buffer is deallocated when the class is destroyed.

#### <a name="DelChars"></a>DelChars

Deletes the specified number of characters starting at the specified position.

```
FUNCTION DelChars (BYVAL nIndex AS UINT, BYVAL nCount AS UINT) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *nIndex* | The starting position (1 for the first character, 2 for the second, etc.). |
| *nCount* | The number of characters to delete. |

#### <a name="Insert"></a>Insert

The passed string parameter is inserted in the string starting at the specified position.

```
FUNCTION Insert (BYVAL pwszStr AS WSTRING PTR, BYVAL nIndex AS UINT) AS BOOLEAN
FUNCTION Insert (BYREF cws AS CWSTR, BYVAL nIndex AS UINT) AS BOOLEAN
FUNCTION Insert (BYREF cbs AS CBSTR, BYVAL nIndex AS UINT) AS BOOLEAN
FUNCTION Insert (BYREF ansiStr AS STRING, BYVAL nIndex AS UINT, BYVAL nCodePage AS UINT = 0) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszStr* | A WSTRING. |
| *cws* | A CWSTR. |
| *cbs* | A CBSTR. |
| *ansiStr* | An ansi string or string literal. |
| *nIndex* | The starting position (1 for the first character, 2 for the second, etc.). |
| *nCodePage* | The code page to be used for ansi to unicode conversions. |

For a list of code pages see: [Code Page Identifiers](https://msdn.microsoft.com/en-us/library/windows/desktop/dd317756(v=vs.85).aspx)

#### <a name="Left"></a>Left

Returns the leftmost substring of the string.

```
FUNCTION Left OVERLOAD (BYREF cws AS CWSTR, BYVAL nChars AS INTEGER) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *cws* | The source CWSTR. |
| *nChars* | The number of characters to return from the source string. |

#### <a name="Right"></a>Right

Returns the rightmost substring of the string.

```
FUNCTION Right OVERLOAD (BYREF cws AS CWSTR, BYVAL nChars AS INTEGER) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *cws* | The source CWSTR. |
| *nChars* | The substring length, in characters. |

#### <a name="LeftChars"></a>LeftChars

Returns the leftmost substring of the string.

```
FUNCTION LeftChars (BYVAL nChars AS LONG) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *nChars* | The number of characters to return from the source string. |

#### <a name="MidChars"></a>MidChars

Returns a substring of the string.

```
MidChars (BYVAL nStart AS LONG, BYVAL nChars AS LONG = 0) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *nStart* | The start position in CWSTR of the substring. The first character starts at position 1. |
| *nChars* | The substring length, in characters. If nChard < 0 or nChars >= length of the CWSTR then all of the remaining characters are returned. |

If CWSTR is empty then the null string ("") is returned. If *nStart* <= 0 then the null string ("") is returned.

#### <a name="RightChars"></a>RightChars

Returns the rightmost substring of the string.

```
FUNCTION RightChars (BYVAL nChars AS LONG) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *nChars* | The substring length, in characters. |

#### <a name="Resize"></a>Resize

Resizes the string to a length of *nSize* characters.

```
FUNCTION Resize (BYVAL nSize AS UINT, BYREF ch AS WSTRING = "")
```

| Parameter  | Description |
| ---------- | ----------- |
| *nSize* | New string length, expressed in number of characters. |
| *ch* | Character used to fill the new character space added to the string (in case the string is expanded). |

If *nSize* is smaller than the current string length, the current value is shortened to its first *nSize* characters. If *nSize* is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of *nSize*. If *ch* is specified, the new elements are initialized as copies of *ch*, otherwise, spaces are added.

#### <a name="SizeAlloc"></a>SizeAlloc

Resizes the string to a length of *nSize* characters.Sets the capacity of the buffer in characters.

```
PROPERTY SizeAlloc (BYVAL nChars AS UINT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nChars* | The new capacity value, in characters. If the new capacity is equal to the current capacity, no operation is performed; is it is smaller, the buffer is shortened and the contents that exceed the new capacity are lost. |

#### <a name="SizeOf"></a>SizeOf

Returns the capacity of the buffer in characters.

```
PROPERTY SizeOf() AS UINT
```

#### <a name="Val"></a>Val

Converts the string to a floating point number (DOUBLE).

```
FUNCTION Val OVERLOAD (BYREF cws AS CWSTR) AS DOUBLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cws* | The source CWSTR. |

#### <a name="ValDouble"></a>ValDouble

Converts the string to a floating point number (DOUBLE).

```
FUNCTION ValDouble () AS DOUBLE
```

#### <a name="ValInt"></a>ValInt

Converts the string to a signed 32-bit integer (LONG).

```
FUNCTION ValInt () AS LONG
```

#### <a name="ValLong"></a>ValLong

Converts the string to a signed 32-bit integer (LONG).

```
FUNCTION ValLong () AS LONG
```

#### <a name="ValLongInt"></a>ValLongInt

Converts the string to a signed 64-bit integer (LONGINT).

```
FUNCTION ValLongInt () AS LONGINT
```

#### <a name="Value"></a>Value

Converts the string to a floating point number (DOUBLE).

```
FUNCTION Value () AS DOUBLE
```

#### <a name="ValUInt"></a>ValUInt

Converts the string to a 32.bit unsigned integer (ULONG).

```
FUNCTION ValUInt () AS ULONG
```

#### <a name="ValULong"></a>ValULong

Converts the string to a 32-bit unsigned integer (ULONG).

```
FUNCTION ValULong () AS ULONG
```

#### <a name="ValULongInt"></a>ValULongInt

Converts the string to a 64-bit unsigned integer (ULONGINT).

```
FUNCTION ValULongInt () AS ULONGINT
```
