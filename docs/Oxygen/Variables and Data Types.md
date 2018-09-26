# Variables and Data Types

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
| [CStr_](#cstr_) | Reserved. |
| [Char](#char) | 8-bit (1 byte) ansi charater type. |
| [GStr_](#gstr_) | Reserved. |
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

Boolean data type. Can hold the values True or False.

# <a name="boolean"></a>Boolean

Boolean data type. Can hold the values True or False.

# <a name="short"></a>Short

16-bit (2 bytes signed integer ranging in value from -32,768 to 32,767.
Also used in conjunction with other types to halve the bit width.

# <a name="long"></a>Long

32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647.
Also used in conjunction with other types to double the bit width.

# <a name="int"></a>Int

32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647.

# <a name="integer"></a>Integer

32-bit (4 bytes signed integer ranging in value from -2,147,483,648 to 2,147,483,647.

# <a name="word"></a>Word

16-bit (2 bytes) unsigned integer ranging in value from 0 to 65,535.

# <a name="dword"></a>DWord

32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295.

# <a name="ulong"></a>ULong

32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295.

# <a name="uint"></a>UInt

32-bit (4 bytes) signed integer ranging in value from 0 to 4 294,967,295.

# <a name="quad"></a>Quad

64-bit (8 bytes) signed integer ranging in value from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807.

# <a name="sys"></a>Sys

32-bit (4 bytes) in 32-bit platforms and 64-bit (8 bytes) in 64-bit platforms.

# <a name="single"></a>Single

32-bit (4 bytes) single-precision floating number ranging in value from +/- 8.43\*10^-37 to 3.40\*10^38.

# <a name="double"></a>Double

64-bit (8 bytes) double-precision floating number ranging in value from +/- 4.19\*10^-307 to 1.79\*10^308.

# <a name="extended"></a>Extended

10 bytes extended-precision floating number ranging in  value from +/- 3.4\*10^-4932 to 1.2\*10^4932.

# <a name="float"></a>Float

32-bit (4 bytes) single-precision floating number ranging in value from +/- 8.43\*10^-37 to 3.40\*10^38.

# <a name="asciiz"></a>AsciiZ

Fixed-length 8-bit null terminated string.

# <a name="asciiz2"></a>AsciiZ2

Fixed-length 16-bit double null terminated string.

# <a name="bstr"></a>Bstr

Variable-length 8-bit string (a BStr is an array of ansi characters).

# <a name="bstring"></a>BString

Variable-length 8-bit string (a BString is an array of ansi characters).

# <a name="bstring2"></a>BString2

Variable-length 8-bit string (a BString is an array of unicode characters).

# <a name="cstr_"></a>CStr_

Reserved.

# <a name="char"></a>Char

8-bit (1 byte) ansi charater type.

# <a name="gstr_"></a>GStr_

Reserved.

# <a name="string"></a>String

Variable-length 8-bit string (a String is an array of characters).

# <a name="string2"></a>String2

Variable-length 16-bit string (a String2 is an array of unicode characters).

# <a name="wstring"></a>WString

Variable-length 16-bit string (a WString is an array of unicode characters).

# <a name="wchar"></a>WChar

16-bit (2 byte) unicode charater type.

# <a name="wide"></a>Wide

Variable-length 16-bit string (a Wide string is an array of unicode characters).
Also used in conjunction with other types to double the bit width.

# <a name="zstring"></a>ZString

Fixed-length 8-bit null terminated string.

# <a name="zstring2"></a>ZString2

Fixed-length 16-bit double null terminated string.
