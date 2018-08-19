The **CWSTR** class implements a dynamic unicode null terminated string. Free Basic has a dynamic string data type (STRING) and a fixed length unicode data type (WSTRING), but it lacks a dynamic unicode string. **CWSTR** behaves as if it was a native data type, working directly with the intrinsic Free Basic string functions and operators.

**Include file**: CWSTR.INC.

Quirks:

* MID as a statement: Something like MID(cws, 2, 1) = "x" compiles but does not change the contents of the dynamic unicode string. MID(cws.wstr, 2, 1) = "x" or MID(**cws, 2, 1) = "x" works.
* SELECT CASE: Something like SELECT CASE LEFT(dws, 2) does not compile; we have to use SELECT CASE LEFT(**dws, 2). Same problem with RIGHT, but not with MID.
* Operator []: cwsText[0] = ASC("x") does not compile; we have to use (*cwsText)[0] = ASC("x").

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors) | Initialize the class with the specified value. |
| [Operator \*](#Operator*) | One * returns the address of the CWSTR buffer.<br> Two ** returns the address of the start of the string data. |
| [sptr](#sptr) | Returns the address of the string data. Same as \*. |
| [vptr](#vptr) | Returns the address of the CWSTR buffer. Same as \* |
| [wstr](#wstr) | Returns the string data. Same as \*\*. |
| [Operator &](#Operator&) | Concatenates strings. |
| [Operator +=](#Operator+=) | Appends a string to the CWSTR. |
| [Operator &=](#Operator&=) | Appends a string to the CWSTR. |
| [Operator []](#Operator[]) | Gets the corresponding unicode integer representation of the character at the specified position. |
| [Operator Let](#OperatorLet) | Assigns a string to the CWSTR. It implements the = operator. |
| [Operator Cast](#OperatorCast) | Returns a pointer to the CWSTR buffer or the string data.<br>Casting is automatic. You don't have to call this operator. |
| [bstr](#bstr) | Returns the contents of the CWSTR as a BSTR. |
| [cbstr](#cbstr) | Returns the contents of the CWSTR as a CBSTR. |
| [wchar](#wchar) | Returns the string data as a new unicode string allocated with CoTaskMemAlloc. |
| [Utf8](#Utf8) | Converts from UTF8 to Unicode and from Unicode to UTF8. |
| [Capacity](#Capacity) | Gets/sets the size of the internal buffer. |
| [GrowSize](#GrowSize) | Gets/sets the grow size value, in characters. |
| [Add](#Add) | The passed string parameter is appended to the string starting at the specified position. |
| [Char](#Char) | Gets or sets the corresponding unicode integer representation of the character at the specified position. |
| [Clear](#Clear) | Erases all the data in the class object. |
| [DelChars](#DelChars) | Deletes the specified number of characters starting at the specified position. |
| [Insert](#Insert) | The passed string parameter is inserted in the string starting at the specified position. |
| Left | Returns the leftmost substring of the string. Same as LEFT. |
| Right | Returns the rightmost substring of the string. Same as RIGHT. |
| LeftChars | Returns the leftmost substring of the string. Same as Left. |
| MidChars | Returns a substring of the string. Same as Mid. |
| RightChars | Returns the rightmost substring of the string. Same as Right. |
| Resize | Resizes the string to a length of the specified number of characters. |
| SizeAlloc | Sets the capacity of the buffer in characters. |
| SizeOf | Returns the capacity of the buffer in characters. |
| Val | Converts the string to a floating point number (DOUBLE). |
| ValDouble | Converts the string to a floating point number (DOUBLE). |
| ValInt | Converts the string to a signed 32-bit integer (LONG). |
| ValLong | Converts the string to a signed 32-bit integer (LONG). |
| ValLongInt | Converts the string to a signed 64-bit integer (LONGINT). |
| Value | Converts the string to a floating point number (DOUBLE). |
| ValUInt | Converts the string to a 32.bit unsigned integer (ULONG). |
| ValULong | Converts the string to a 32-bit unsigned integer (ULONG). |
| ValULongInt | Converts the string to a 64-bit unsigned integer (ULONGINT). |
| AfxCWstrArrayAppend | Appends a CWSTR at the end of a not fixed one-dimensional CWSTR array. |
| AfxCWstrArrayInsert | Inserts a new CWSTR element before the specified position in a not fixed one-dimensional CWSTR array. |
| AfxCWstrArrayRemove | Removes the specified element of a not fixed one-dimensional CWSTR array. |
| AfxCWstrArraySort | Sorts a one-dimensional CWSTR array calling the C qsort function. |
| AfxCWstrArrayLogicalSort | Sorts a one-dimensional CWSTR array calling the C qsort function. |
| AfxCWstrLogicalSort | Sorts a one-dimensional CWSTR array calling the C qsort function. |
| AfxCWstrSort | Sorts a one-dimensional CWSTR array calling the C qsort function. |

# <a name="Constructors"></a>Constructors

Initialize the class with the specified value.

```
CONSTRUCTOR CWStr
CONSTRUCTOR CWStr (BYVAL nChars AS UINT, BYVAL bClear AS BOOLEAN)
CONSTRUCTOR CWStr (BYVAL pwszStr AS WSTRING PTR)
CONSTRUCTOR CWStr (BYREF cws AS CWSTR)
CONSTRUCTOR CWstr (BYREF cbs AS CBSTR)
CONSTRUCTOR CWStr (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0)
CONSTRUCTOR CWstr (BYREF n AS LONGINT)
CONSTRUCTOR CWstr (BYREF n AS DOUBLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nChars* | The number of characters to be pre-allocated. |
| *bClear* | The newly allocated memory is initialized (TRUE) or not (FALSE). |
| *pwszStr* | A WSTRING. |
| *cws* | A CWSTR. |
| *cbs* | A CBSTR. |
| *ansiStr* | An ansi string or string literal. |
| *nCodePage* | The code page to be used for ansi to unicode conversions. |
| *n* | A number. |

For a list of code pages see: [Code Page Identifiers](https://msdn.microsoft.com/en-us/library/windows/desktop/dd317756(v=vs.85).aspx)

**CWSTR** works transparently with literals and Free Basic native strings, e.g.

```
DIM cws AS CWSTR = "One"
DIM s AS STRING = "Three"
cws = cws + " Two " + s
PRINT cws
```

It can be used with Windows API functions, e.g.

```
DIM nLen AS LONG = SendMessageW(hwnd, WM_GETTEXTLENGTH, 0, 0)
DIM cwsText AS CWSTR = CWSTR(nLen + 1, 0)
SendMessageW(hwnd, WM_GETTEXT, nLen + 1, cast(LPARAM, *cwsText))
```

We can use arrays of **CWSTR** strings transparently, e.g.

```
DIM rg(1 TO 10) AS CWSTR
FOR i AS LONG = 1 TO 10
   rg(i) = "string " & i
NEXT

FOR i AS LONG = 1 TO 10
   print rg(i)
NEXT
```

A two-dimensional array

```
DIM rg2 (1 TO 2, 1 TO 2) AS CWSTR
rg2(1, 1) = "string 1 1"
rg2(1, 2) = "string 1 2"
rg2(2, 1) = "string 2 1"
rg2(2, 2) = "string 2 2"
print rg2(2, 1)
```

REDIM PRESERVE / ERASE

```
REDIM rg(0) AS CWSTR
rg(0) = "string 0"
REDIM PRESERVE rg(0 TO 2) AS CWSTR
rg(1) = "string 1"
rg(2) = "string 2"
print rg(0)
print rg(1)
print rg(2)
ERASE rg
```

And we can also sort one-dimensional arrays calling the **AfxCWstrSort** procedure:

```
DIM rg(1 TO 10) AS CWSTR
FOR i AS LONG = 1 TO 10
   rg(i) = "string " & i
NEXT
FOR i AS LONG = 1 TO 10
  print rg(i)
NEXT
print "---- after sorting ----"
AfxCWstrSort @rg(1), 10
FOR i AS LONG = 1 TO 10
   print rg(i)
NEXT
```

You can also use it with files:

Using FreeBasic intrinsic statements:

```
DIM cws AS CWSTR = "Дмитрий Дмитриевич Шостакович"
DIM f AS LONG = FREEFILE
OPEN "test.txt" FOR OUTPUT ENCODING "utf16" AS #f
PRINT #f, cws
CLOSE #f
```

Using the Windows API:

```
' // Writing to a file
DIM cwsFilename AS CWSTR = "тест.txt"
DIM cwsText AS CWSTR = "Дмитрий Дмитриевич Шостакович"
DIM hFile AS HANDLE = CreateFileW(cwsFilename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
IF hFile THEN
   DIM dwBytesWritten AS DWORD
   DIM bSuccess AS LONG = WriteFile(hFile, cwsText, LEN(cwsText) * 2, @dwBytesWritten, NULL)
   CloseHandle(hFile)
END IF
```

' // Read the file
```
hFile = CreateFileW(cwsFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
IF hFile THEN
   DIM dwFileSize AS DWORD = GetFileSize(hFile, NULL)
   IF dwFileSize THEN
      DIM cwsOut AS CWSTR = WSPACE(dwFileSize \ 2)
      DIM bSuccess AS LONG = ReadFile(hFile, *cwsOut, dwFileSize, NULL, NULL)
      CloseHandle(hFile)
      PRINT cwsOut
   END IF
END IF
```

Notice that, contrarily to CreateFileW, FreeBasic's OPEN statemente doesn't allow to use unicode for the file name.

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

Gets or sets the corresponding unicode integer representation of the character at the position specified by the *nIndex* parameter.

```
SUB Clear
```

#### <a name="DelChars"></a>DelChars

Deletes the specified number of characters starting at the specified position.

```
FUNCTION DelChars (BYVAL nIndex AS UINT, BYVAL nCount AS UINT) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *nIndex* | The starting position (1 for the first character, 2 for the second, etc.). |
| *nValue* | The number of characters to delete. |

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
