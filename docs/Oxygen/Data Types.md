# Oxygen Basic Data Types

### Integer Types

| Name       | Description |
| ---------- | ----------- |
| [Byte](#byte) | 8-bit (1 byte) unsigned integer ranging in value from 0 to 255. |
| [SByte](#sbyte) | 8-bit (1 byte) signed integerr tanging in value from -128 to 127. |
| [UByte](#ubyte) | 8-bit (1 byte) unsigned integer ranging in value from 0 to 255. |
| [Bool](#bool) | Boolean data type. Can hold the values True or False. |
| [Boolean](#boolean) | Boolean data type. Can hold the values True or False. |
| [Short](#short) | 16-bit (2 bytes signed integer ranging in value from -32,768 to 32,767. |
| [Long](#long) | 32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647. |
| [Int](#int) | 32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647. |
| [Integer](#integer) | 32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647. |
| [Word](#word) | 16-bit (2 bytes) unsigned integer ranging in value from 0 to 65,535. |
| [DWord](#dword) | 32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295. |
| [ULong](#ulong) | 32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295. |
| [UInt](#uint) | 32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295. |
| [Quad](#quad) | 64-bit (8 bytes) signed integer ranging in value from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807. |
| [Sys](#sys) | 32-bit (4 bytes) in 32-bit platforms and 64-bit (8 bytes) in 64-bit platforms. |

### Floating-point Types

| Name       | Description |
| ---------- | ----------- |
| [Single](#single) | 32-bit (4 bytes) single-precision floating number ranging in value from +/- 8.43\*10^-37 to 3.40\*10^38. |
| [Double](#double) | 64-bit (8 bytes) double-precision floating number ranging in value from +/- 4.19\*10^-307 to 1.79\*10^308. |
| [Extended](#extended) | 10 bytes extended-precision floating number ranging in  value from +/- 3.4\*10^-4932 to 1.2\*10^4932. |
| [Float](#float) | 32-bit (4 bytes) single-precision floating number ranging in value from +/- 8.43\*10^-37 to 3.40\*10^38. |

### String Types

| Name       | Description |
| ---------- | ----------- |
| [Asciiz](#asciiz) | Fixed-length 8-bit null terminated string. |
| [Asciiz2](#asciiz2) | Fixed-length 16-bit double null terminated string. |
| [Bstr](#bstr) | Variable-length 8-bit string (a BStr is an array of ansi characters). |
| [BString](#bstring) | Variable-length 8-bit string (a BString is an array of ansi characters). |
| [BString2](#bstring2) | Variable-length 8-bit string (a BString is an array of unicode characters). |
| [Char](#char) | 8-bit (1 byte) ansi charater type. |
| [String](#string) | Variable-length 8-bit string (a String is an array of characters). |
| [String2](#string2) | Variable-length 16-bit string (a String2 is an array of unicode characters). |
| [WString](#wstring) | Variable-length 16-bit string (a WString is an array of unicode characters). |
| [WChar](#wchar) | 16-bit (2 byte) unicode charater type. |
| [Wide](#wide) | Variable-length 16-bit string (a Wide string is an array of unicode characters). |
| [ZString](#zstring) | Fixed-length 8-bit null terminated string. |
| [ZString2](#zstring2) | Fixed-length 16-bit double null terminated string. |

### Modifiers

| Name       | Description |
| ---------- | ----------- |
| [Long](#long) | Used in conjunction with other types to double the bit width. |
| [Short](#short) | Used in conjunction with other types to halve the bit width. |
| [Wide](#wide) | Used in conjunction with other types to double the bit width. |

### Assembler

| Name       | Description |
| ---------- | ----------- |
| [QWord](#qword) | Specify a 64-bit operand in assembly code.  |

# <a name="byte"></a>Byte

8-bit (1 byte) unsigned integer ranging in value from 0 to 255.

```
DIM byteVar AS BYTE
byteVar = 100
```

```
BYTE byteVar
byteVar = 100
```

```
DIM AS BYTE byteVar
byteVar = 100
```

A byte as an addressable unit of data storage large enough to hold any member of the basic character set of the execution environment. It must hold at least 256 different values, and is represented by eight bits.

# <a name="sbyte"></a>SByte

8-bit (1 byte) signed integerr tanging in value from -128 to 127.

```
DIM sbyteVar AS SBYTE
sbyteVar = -100
```

```
SBYTE sbyteVar
sbyteVar = 100
```

```
DIM AS SBYTE sbyteVar
sbyteVar = 100
```

A byte as an addressable unit of data storage large enough to hold any member of the basic character set of the execution environment. It must hold at least 256 different values, and is represented by eight bits.

# <a name="ubyte"></a>UByte

8-bit (1 byte) unsigned integer ranging in value from 0 to 255.

```
DIM ubyteVar AS UBYTE
ubyteVar = 100
```

```
UBYTE ubyteVar
ubyteVar = 100
```

```
DIM AS UBYTE ubyteVar
ubyteVar = 100
```

A byte as an addressable unit of data storage large enough to hold any member of the basic character set of the execution environment. It must hold at least 256 different values, and is represented by eight bits.

# <a name="bool"></a>Bool

Boolean data type. Can hold the values True (<> 0) or False (0).

```
DIM b AS BOOL
b = TRUE
```

```
BOOL b
b = TRUE
```

```
DIM AS BOOL b
b = TRUE
```

Notionally a Boolean type, but in reality it is a LONG (32bit signed integer).

# <a name="boolean"></a>Boolean

Boolean data type. Can hold the values True (<> 0) or False (0).

```
DIM b AS BOOLEAN
b = TRUE
```

```
BOOLEAN b
b = TRUE
```

```
DIM AS BOOLEAN b
b = TRUE
```

Notionally a Boolean type, but in reality it is an UBYTE (8 bit unsigned integer).

# <a name="short"></a>Short

16-bit (2 bytes signed integer ranging in value from -32,768 to 32,767.

```
DIM n AS SHORT
n = 12345
```

```
SHORT n
n = 12345
```

```
DIM AS SHORT n
n = 12345
```

Also used in conjunction with other types to halve the bit width.

```
SHORT LONG n
n = 12345
```

# <a name="long"></a>Long

32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647.

```
DIM n AS LONG
n = 1234567890
```

```
LONG n
n = 1234567890
```

```
DIM AS LONG n
n = 1234567890
```

Also used in conjunction with other types to double the bit width.

```
LONG SHORT n
n = 1234567890
```

# <a name="int"></a>Int

32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647.

```
DIM n AS INT
n = 1234567890
```

```
INT n
n = 1234567890
```

```
DIM AS INT n
n = 1234567890
```

# <a name="integer"></a>Integer

32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647.

```
DIM n AS INTEGER
n = 1234567890
```

```
INTEGER n
n = 1234567890
```

```
DIM AS INTEGER n
n = 1234567890
```

# <a name="word"></a>Word

16-bit (2 bytes) unsigned integer ranging in value from 0 to 65,535.

```
DIM n AS WORD
n = 12345
```

```
WORD n
n = 12345
```

```
DIM AS WORD n
n = 12345
```

If you assign a negative number to a WORD variable, the value is converted to an unsigned WORD, e.g.

```
DIM n AS WORD
n = -1
PRINT n
' Output: 65535
```

# <a name="dword"></a>DWord

32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295.

```
DIM n AS DWORD
n = 1234567890
```

```
DWORD n
n = 1234567890
```

```
DIM AS DWORD n
n = 1234567890
```

# <a name="ulong"></a>ULong

32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295.

```
DIM n AS ULONG
n = 1234567890
```

```
ULONG n
n = 1234567890
```

```
DIM AS ULONG n
n = 1234567890
```

# <a name="uint"></a>UInt

32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295.

```
DIM n AS UINT
n = 1234567890
```

```
UINT n
n = 1234567890
```

```
DIM AS UINT n
n = 1234567890
```

# <a name="quad"></a>Quad

64-bit (8 bytes) signed integer ranging in value from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807.

```
DIM n AS QUAD
n = 9223372036854775
```

```
QUAD n
n = 9223372036854775
```

```
DIM AS QUAD n
n = 9223372036854775
```

# <a name="sys"></a>Sys

32-bit (4 bytes) in 32-bit platforms and 64-bit (8 bytes) in 64-bit platforms. To be used mainly to work with handles and opaque pointers, that are 32-bit in 32-bit systems and 64-bit in 64-bit systems. This type is always wide enough to hold a pointer.

The following example retrieves the handle of a Windows control identified by ID that is child of the Window identifield by the hwnd handle.

```
DIM hCtl AS SYS = GetDlgItem(hwnd, ID)
```

# <a name="single"></a>Single

32-bit (4 bytes) single-precision floating number ranging in value from +/- 8.43\*10^-37 to 3.40\*10^38.

```
DIM n AS SINGLE
n = 123.45
```

```
SINGLE n
n = 123.45
```

```
DIM AS SINGLE n
n = 123.45
```

# <a name="double"></a>Double

64-bit (8 bytes) double-precision floating number ranging in value from +/- 4.19\*10^-307 to 1.79\*10^308.

```
DIM n AS DOUBLE
n = 12356.789
```

```
DOUBLE n
n = 12356.789
```

```
DIM AS DOUBLE n
n = 12356.789
```

# <a name="extended"></a>Extended

10 bytes extended-precision floating number ranging in  value from +/- 3.4\*10^-4932 to 1.2\*10^4932.

```
DIM n AS EXTENDED
n = 12356789.12
```

```
EXTENDED n
n = 12356789.12
```

```
DIM AS EXTENDED n
n = 12356789.12
```

# <a name="float"></a>Float

32-bit (4 bytes) single-precision floating number ranging in value from +/- 8.43\*10^-37 to 3.40\*10^38.

```
DIM n AS FLOAT
n = 123.45
```

```
FLOAT n
n = 123.45
```

```
DIM AS FLOAT n
n = 123.45
```

# <a name="asciiz"></a>Asciiz

Fixed-length 8-bit null terminated string.

```
DIM s AS ASCIIZ * 260
s = "Test string"
```

```
ASCIIZ s * 260
s = "Test string"
```
```
DIM AS ASCIIZ s * 260
s = "Test string"
```

Indirection level 0<br>
Character width 1<br>
Length determined by null terminator byte<br>
Garbage collection not required

# <a name="asciiz2"></a>Asciiz2

Fixed-length 16-bit double null terminated string.

```
DIM s AS ASCIIZ2 * 260
s = "Test string 2"
```

```
ASCIIZ2 s * 260
s = "Test string 2"
```
```
DIM AS ASCIIZ2 s * 260
s = "Test string 2"
```

Indirection level 0<br>
Character width 1<br>
Length determined by 2 null terminator bytes<br>
Garbage collection not required

# <a name="bstr"></a>Bstr

Variable-length 8-bit string (a BStr is an array of ansi characters).

```
DIM b AS BSTR = "Test string"
print b
frees b
```

```
BSTR b = "Test string"
print b
frees b
```

```
DIM AS BSTR b = "Test string"
print b
frees b
```

You must free the string with **FreeS** when no longer reuired.

Indirection level 1<br>
Character width 1<br>
Length given by 4 byte integer immediately before byte content<br>
Also terminated by 2 null bytes<br>
Garbage collection required

# <a name="bstring"></a>BString

Variable-length 8-bit string (a BString is an array of ansi characters).

```
DIM b AS BSTRING = "Test string"
print b
frees b
```

```
BSTRING b = "Test string"
print b
frees b
```

```
DIM AS BSTRING b = "Test string"
print b
frees b
```

You must free the string with **FreeS** when no longer reuired.

Indirection level 1<br>
Character width 1<br>
Length given by 4 byte integer immediately before byte content<br>
Also terminated by 2 null bytes<br>
Garbage collection required

# <a name="bstring2"></a>BString2

Variable-length 8-bit string (a BString is an array of unicode characters).

```
DIM b AS BSTRING2 = "Test string"
print b
frees b
```

```
BSTRING2 b = "Test string"
print b
frees b
```

```
DIM AS BSTRING2 b = "Test string"
print b
frees b
```

You must free the string with **FreeS** when no longer reuired.

Indirection level 1<br>
Character width 2<br>
Length (in bytes) given by 4 byte integer immediately before byte content<br>
Also terminated by 2 null bytes<br>
Garbage collection required

# <a name="char"></a>Char

8-bit (1 byte) ansi character type.

```
DIM c AS CHAR = "A"
```

```
CHAR c = "A"
```

```
DIM AS CHAR c = "A"
```

Indirection level 0<br>
Character width 1<br>
Length determined by null terminator byte<br>
Garbage collection not required

# <a name="string"></a>String

Variable-length 8-bit string (a String is an array of characters).

```
DIM s AS STRING = "Test string"
```

```
STRING s = "Test string"
```

```
DIM AS STRING s = "Test string"
```

Indirection level 2  (1 when passed byval as a parameter)<br>
Character width = 1<br>
Length given by 4 byte integer immediately before byte content<br>
Also terminated by 2 null bytes<br>
Garbage collection automatic


# <a name="string2"></a>String2

Variable-length 16-bit string (a String2 is an array of unicode characters).

```
DIM s AS STRING2 = "Test string"
```

```
STRING2 s = "Test string"
```

```
DIM AS STRING2 s = "Test string"
```

Indirection level 2 (1 when passed byval as a parameter)<br>
Character width 2<br>
Length given by 4 byte integer immediately before byte content<br>
Also terminated by 2 null bytes<br>
Garbage collection automatic

# <a name="wstring"></a>WString

Variable-length 16-bit string (a WString is an array of unicode characters).

```
DIM ws AS WSTRING = "Test string"
```

```
WSTRING ws = "Test string"
```

```
DIM AS WSTRING ws = "Test string"
```

Indirection level 2 (1 when passed byval as a parameter)<br>
Character width 2<br>
Length given by 4 byte integer immediately before byte content<br>
Also terminated by 2 null bytes<br>
Garbage collection automatic

# <a name="wchar"></a>WChar

16-bit (2 byte) unicode character type.

```
DIM c AS WCHAR = "W"
```

```
CHAR c = "W"
```

```
DIM AS CHAR c = "W"
```

Indirection level 0<br>
Character width 2<br>
Length determined by 2 null terminator bytes<br>
Garbage collection not required

# <a name="wide"></a>Wide

Variable-length 16-bit string (a Wide string is an array of unicode characters).

```
DIM ws AS WIDE = "Test string"
```

```
WIDE ws = "Test string"
```

```
DIM AS WIDE ws = "Test string"
```

Also used in conjunction with other types to double the bit width.

```
WIDE CHAR wc
WIDE FLOAT wf   ' a double precision float
```

# <a name="zstring"></a>ZString

Fixed-length 8-bit null terminated string.

```
DIM zs AS ZSTRING * 260 = "Test string"
```

```
ZSTRING * 260 zs = "Test string"
```

```
DIM AS ZSTRING zs = "Test string"
```

Indirection level 0<br>
Character width 1<br>
Length determined by null terminator byte<br>
Garbage collection not required

# <a name="zstring2"></a>ZString2

Fixed-length 16-bit double null terminated string.

```
DIM zs AS ZSTRING2 * 260 = "Test string"
```

```
ZSTRING2 * 260 zs = "Test string"
```

```
DIM AS ZSTRING2 zs = "Test string"
```

Indirection level 0<br>
Character width 2<br>
Length determined by 2 null terminator bytes<br>
Garbage collection not required

# <a name="qword"></a>QWord

Specify a 64 bit operand in assembly code.

```
fld qword d
```
