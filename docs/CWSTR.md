The **CWSTR** class implements a dynamic unicode null terminated string. Free Basic has a dynamic string data type (STRING) and a fixed length unicode data type (WSTRING), but it lacks a dynamic unicode string. **CWSTR** behaves as if it was a native data type, working directly with the intrinsic Free Basic string functions and operators.

**Include file**: CWSTR.INC.

Quirks:

* MID as a statement: Something like MID(cws, 2, 1) = "x" compiles but does not change the contents of the dynamic unicode string. MID(cws.wstr, 2, 1) = "x" or MID(**cws, 2, 1) = "x" works.
* SELECT CASE: Something like SELECT CASE LEFT(dws, 2) does not compile; we have to use SELECT CASE LEFT(**dws, 2). Same problem with RIGHT, but not with MID.
* Operator []: cwsText[0] = ASC("x") does not compile; we have to use (*cwsText)[0] = ASC("x").

| Name       | Description |
| ---------- | ----------- |
| Constructors | Initialize the class with the specified value. |
| \* | One * returns the address of the CWSTR buffer. Two ** returns the address of the start of the string data. |
| sptr | Returns the address of the string data. Same as \*. |
| vptr | Returns the address of the CWSTR buffer. |
| wstr | Returns the string data. Same as \*\*. |
| += | Appends a string to the CWSTR. |
| &= | Appends a string to the CWSTR. |
| \[] | Gets the corresponding unicode integer representation of the character at the specified position. |
| Cast | Returns a pointer to the CWSTR buffer or the string data. |
| bstr | Returns the contents of the CWSTR as a BSTR. |
| cbstr | Returns the contents of the CWSTR as a CBSTR. |
| wchar | Returns the string data as a new unicode string allocated with CoTaskMemAlloc. |
| Utf8 | Converts from UTF8 to Unicode and from Unicode to UTF8. |
| Let | Assigns a string to the CWSTR. |
| Capacity | Gets/sets the size of the internal buffer. |
| GrowSize | Gets/sets the grow size value, in characters. |
| Add | The passed string parameter is appended to the string starting at the specified position. |
| Char | Gets or sets the corresponding unicode integer representation of the character at the specified position. |
| Clear | Erases all the data in the class object. |
| DelChars | Deletes the specified number of characters starting at the specified position. |
| Insert | The passed string parameter is inserted in the string starting at the specified position. |
| LeftChars | Returns the leftmost substring of the string. |
| MidChars | Returns a substring of the string. |
| RightChars | Returns the rightmost substring of the string. |
| Resize | Resizes the string to a length of the specified number of characters. |
| SizeAlloc | Sets the capacity of the buffer in characters. |
| SizeOf | Returns the capacity of the buffer in characters. |
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

# Constructors

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
