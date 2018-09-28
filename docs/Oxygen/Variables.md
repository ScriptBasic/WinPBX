# Variables, Arrays and User Defined Types

* `Variables` represent numeric or string values. The value of a variable can change during program execution. 
* `Constants` are numbers or strings which cannot be changed after they are defined.
* `Equates` are constants prefixed by the symbols `$` (string equates) or `%` (numeric equates).
* `Enums` are groups of logically related numeric equates.
* `User defined types` (UDTs) are custom data types containing one or more data fields.
* `Unions` are similar to a user defined types, except that the elements of a union occupy the same space in memory.
* `Arrays` are groups of data sharing the same variable name. The individual values that make up an array are called elements.


#### Variable Scope

* `Global` variables are accessible from anywhere in your program. They are initialized when your program starts and are destroyed when the program ends.
* `Local` variables are only accessible within a single procedure or method. They are automatically created and initialized each time you enter the procedure. They are automatically destroyed when you exit the procedure. This is the default variable scope unless you declare otherwise.
* `Static` variables are only accessible within a single proceudre or method. They are initialized when your program starts, but retain their value regardless of how many times the procedure is entered and exited. They are destroyed only when the program ends.

### Variables

| Name       | Description |
| ---------- | ----------- |
| [Dim](#dim) | Declares variables, arrays, objects and user defined types. |
| [ReDim](#redim) | Creates or resizes a dynamic array, preserving contents within range.  |
| [As](#as) | Part of a declaration which specifies a data type. |
| [Let](#let) | Similar to **Dim**, but the type is inferred from the assigned value. |
| [Var](#var) | Defines a set of variables. |
| [Const](#const) | Constant. Non-modifiable variable declaration. |
| [$](#equate1) | Defines a string equate (which can be used as constant). |
| [%](#equate2) | Defines a numeric equate (which can be used as constant). |
| [Enum](#enum) | Declares an enumerated type. |
| [Type](#type) | Define a compound variable type. |
| [Union](#union) | Define a union. |

### Modifiers

| Name       | Description |
| ---------- | ----------- |
| [Global](#global) | Declares global (shared) variables. |
| [Local](#local) | Declares local variables inside a poceudre. |
| [Static](#static) | Declares static variables inside a procedure. |

### Blocks and Scopes

| Name       | Description |
| ---------- | ----------- |
| [Block](#block) | Creates a block of code. |
| [Rem](#rem | Comments till end of line. |
| [//](#rem2| Comments till end of line. |
| [\/\*](#rem3) | Comments till end of block. |
| [\*/](#rem4) | Terminates comment block. |
| [Scope](#scope) | Creates a block where variables and functions may be locally defined. |
| [Skip](#skip) | Prevents code within the block from being executed. |

# <a name="dim"></a>Dim

Declares variables, arrays, objects and user defined types.

#### Syntax

Post define type

```
DIM x AS LONG
DIM i, j, k AS LONG
```

Pre define type

```
DIM AS LONG x
DIM AS LONG i, j, k
```

Mixed types

```
DIM AS LONG i, j, k, AS STRING s, t
```

Multiline

```
DIM AS LONG i, j, k,
    AS STRING s,t
```

```
DIM AS LONG,
   i,
   j,
   k
```

Initial values

```
DIM AS LONG,
   i = 1,
   j = 2,
   k = 42
```

Spread lines and comments

```
DIM AS LONG,
   i = 1,  ' these can be spread over many lines
   ' ---------
   j = 2,  ' with intervening comments
   ' ---------
   k = 42  '
```

Multiple assignments

```
DIM AS LONG a(10) => (2, 4, 6, 8, 10, 12, 42, 99)
```

Syntax variations

```
DIM LONG a(10) => (2,4,6,8,10,12,42,99)  
DIM LONG a[10] => (2,4,6,8,10,12,42,99)  
LONG a[10] => (2,4,6,8,10,12,42,99)  
LONG a[10] <= (2,4,6,8,10,12,42,99)  
LONG a[10] = {2,4,6,8,10,12,42,99}
LONG a[] = {2,4,6,8,10,12,42,99}
LONG a = {2,4,6,8,10,12,42,99}
```

Pointered variable

```
DIM a AS STRING = "ABCDEFGHI"
DIM AS STRING a =  "ABCDEFGHI"
DIM BYTE b AT STRPTR(a)
DIM BYTE BYREF b : @b = STRPTR(a)
BYTE b AT STRPTR(a)
BYTE *b = STRPTR(a)
PRINT b[7]   ' 71 G
```

Using dynamic memory

```
DIM FLOAT f AT GetMemory 1024 * 4
f => (1.5, 2.5, 3.5)
PRINT f[2]
FreeMemory @f   ' release allocated memory
```

Global, static, local

```
GLOBAL int g = 1
FUNCTION f (p AS INT) AS INT
   STATIC INT s = 0
   LOCAL INT l = 100
   s += 10
   RETURN p + l + s + g
END FUNCTION
PRINT f(1000)   ' 1111
PRINT f(1000)   ' 1121
```

Limiting scope

```
DIM LONG a = 16
SCOPE
   DIM LONG a = 1
   PRINT a   ' 1
END SCOPE
PRINT a   ' 16
```

Static arrays

```
DIM AS LONG a(10 )= {2,4,6,8,10,12}
a(10) = a(1) + a(4)
print a(10)
```

Dynamic arrays

```
DIM AS LONG a AT GetMemory(10 * SIZEOF(long))
a = {2,4,6,8,10,12}
...
FreeMemoty @a
```

```
DIM AS LONG a(10) = {2,4,6,8,10,12}
```

Overlays

```
DIM AS STRING s = "ABCDEFGHIJ"
DIM AS BYTE b AT STRPTR(s)
PRINT STR(b[3]) ":  " CHR(b[3])
```

Multidimensional arrays

```
MACRO a(x,y) av(y * 1024 + x)
DIM INT av[1024 * 1024]
a(100,200) = 42
PRINT a(100,200)   ' 42
```

Index base

```
DIM INT a[100] = {10,20,30,40}
IndexBase 1    ' default: first element is indexed as 1
PRINT a[2]   ' 20
IndexBase 0
PRINT a[2]   ' 30
```

Pseudo arrays

```
DIM av[100]

FUNCTION a(int i,v)   ' setter
   i *= 2
   av[i]=v
END FUNCTION
  
FUNCTION a(int i) AS INT   ' getter
   i *= 2
   RETURN av[i]
END FUNCTION

a(7) = 42   ' this is interpreted as a(7,42)
PRINT a(7)
```

# <a name="redim"></a>ReDim

Creates or resizes a dynamic array, preserving contents within range. Used to extend or reduce an array size at runtime.

```
REDIM string s(20)
```

To flush an array's contents, redim it with 0 elements first. But avoid doing this with arrays of strings; the orphaned strings are not garbage-collected until the end of the program, and will accumulate on each iteration where the redim reduces the number of elements.


# <a name="as"></a>As

Part of a declaration which specifies a data type. `As` is used to declare the type of variables, fields or arguments.

```
DIM x AS LONG
DIM AS LONG x
```

# <a name="let"></a>Let

Similar to `Dim` but the type is inferred from the assigned value.

```
LET s = "This is a string"
PRINT TypeOf(s)  ' Result: "string"
```

# <a name="var"></a>Var

Defines a set of variables.

```
Var string s,t,u(64),v  
```

`Var` is normally only used internally. it accepts `*` for indirect variables and `AT`for variable mapping. Arrays are also supported.


# <a name="const"></a>Const

Non-modifiable variable declaration.

#### Syntax

```
Const symbolname1 [AS DataType] = value1 [, symbolname2 [AS DataType] = value2, ...]
Const [AS DataType] symbolname1 = value1 [, symbolname2 = value2, ...]
```

```
CONST x = 10
CONST x = 10, y = 11, z = 12
CONST s AS STRING = "Hello"
CONST AS STRING s = "Hello"
```

# <a name="equate1"></a>String equate ($)

Defines a string equate, which can be used as a constant.

```
$s = "Hello World"
$ s = "Hello World"
```

# <a name="equate2"></a>String equate (%)

Defines a numeric equate, which can be used as a constant.

```
%n = 12345
% n = 12345
%n = 12345.56
```

# <a name="emum"></a>Enum

Declares an enumerated type (a set of equates twhich are logically related).

```
ENUM MyEnum
   option1   ' becomes 0
   option2   ' becomes 1
   option3   ' becomes 2
END ENUM
```

```
ENUM MyEnum
   option1 = 100   ' becomes 100
   option2         ' becomes 101
   option3         ' becomes 102
END ENUM
```

```
ENUM MyEnum
   option1 = 100   ' becomes 100
   option2 = 222   ' becomes 222
   option3         ' becomes 223
END ENUM
```

```
ENUM MyEnum
   option1, option2, option3
END ENUM
```

C syntax is supported for this construct.

```
ENUM MyEnum
{
   option1
   option2
   option3
}
```

```
ENUM MyEnum {option1, option2, option3}
```

Also `enum bit` (`bit`must be lowercase) assigns values 1,2,4,8,16.. instead of 0,1,2,3,4..

```
ENUM bit MyEnum
   option1
   option2
   option3
END ENUM
```

New definitions override older ones:

```
ENUM MyEnum
   option1 = 1
   option2
   option3
END ENUM

ENUM MyEum2
   option1 = 10
END ENUM
```

In the above code, *option1* becomes 10. To trap duplicate definitions use `#unique on`. `#unique` may be switched on and off for any section of code.

Overriding definitions always allowed within a new scope:

```
#unique on
ENUM x
   a = 1, b, c
END ENUM

SCOPE
  ENUM y
     a = 10, b, c
  END ENUM
  PRINT b   'output: 11
END SCOPE
PRINT b   ' output: 2
```

# <a name="type"></a>Type

Defines a compound variable type.

```
TYPE rgbacolor
  red   AS BYTE
  green AS BYTE
  blue  AS BYTE
  alpha AS BYTE
END TYPE
```

Derived type

```
TYPE color32
   r AS BYTE
   g AS BYTE
   b AS BYTE
   a AS BYTE
   =
   rgba AS LONG   ' Union
END TYPE

TYPE colortext
   txt AS STRING
   c AS color32
END TYPE

DIM t AS colortext
  
t.txt = "Color code"
t.c.r = 8
t.c.b = 16
t.c.g = 32
t.c.a = 64
  
PRINT t.txt & ": " & HEX(t.c.rgba)
```
#### Syntax variations

```
type color32
   byte r
   byte g
   byte b
   byte a
   =
   long rgba  'UNION    
end type
```

```
type color32
   byte r,g,b,a
   =
   long rgba  'UNION    
end type 
```

```
type color32 byte r, g, b, a = long rgba
```

```
type colortext string txt, color32 c
```

```
struct color32 { 
   byte r,g,b,a
   =
   long rgba
}
```

```
typedef struct _color32 { 
   byte r,g,b,a
   =
   long rgba
} color32, *pcolor32
```

```
typedef struct _color32 {
   union { 
      struct {
        byte r,g,b,a
      }
      long rgba
  }  
} color32, *pcolor32
```

# <a name="union"></a>Union

Allows different variables to occupy the same space.

```
UNION MyUnion
   b AS BYTE
   w AS SHORT
   i AS LONG
END UNION

DIM v AS MyUnion
v.b = 42
PRINT v.b
print v.w
print v.i

Result: v.b = 42 : v.w = 42 : v.i = 42
```

#### Syntax variation:

```
union MyUnion
{
  byte  b
  short w
  long  i
}
```

# <a name="global"></a>Global

Declares global (shared) variables. `Global` variables are accessible from anywhere in your program. They are initialized when your program starts and are destroyed when the program ends.

```
GLOBAL n AS LONG = 123
GLOBAL AS LONG n = 123
DIM GLOBAL AS LONG n = 123
```

# <a name="local"></a>Local

Declares local variables inside a poceudre. `Local` variables are only accessible within a single procedure or method. They are automatically created and initialized each time you enter the procedure. They are automatically destroyed when you exit the procedure. This is the default variable scope unless you declare otherwise.

```
LOCAL LONG n = 123
LOCAL AS LONG n = 123
LOCAL STRING s = "Test string"
LOCAL AS STRING s = "Test string"
```

# <a name="static"></a>Static

Declares static variables inside a poceudre. `Static` variables are only accessible within a single proceudre or method. They are initialized when your program starts, but retain their value regardless of how many times the procedure is entered and exited. They are destroyed only when the program ends.

```
STATIC LONG n = 123
STATIC AS LONG n = 123
STATIC STRING s = "Test string"
STATIC AS STRING s = "Test string"
```

# <a name="block"></a>Block

Creates a block of code. When a variable is (re)defined with `Dim` within a block structure, this local working variable can be used from its (re)definition until the end of the block. During this time, any variables outside the scope that have the same name will be ignored, and will not be accessible by that name. Any statements in the `Block` before the variable is redefined will use the variable as defined outside the block.

```
SYS i = 4
BLOCK
   SYS i = 8
   PRINT "inner block i = " i
END BLOCK
PRINT i
```

```
(
  DIM INT i = 2
  PRINT i
)
```

```
BLOCK {
  DIM INT i = 2
  PRINT i
}
```

Non executable blocks

```
SKIP {
  DIM INT i = 2
  PRINT i
}
```

```
/*
  DIM INT i = 2
  PRINT i
*/
```

Assembly code blocks

```
mov eax,0
mov ecx,5
block
 inc eax
 dec ecx
 jg repeat 'jump back to 'block'
end block
```

```
mov eax,0
mov ecx,5
(
 inc eax
 dec ecx
 jg repeat 'jump back to '('
)
```

```
mov eax,0
mov ecx,5
(
 dec ecx
 jl exit 'jump forward to ')'
 inc eax
 repeat 'jump back to '('
)
print eax
```

# <a name="rem"></a>Rem

Comments till end of line.

```
REM this is a comment
```

# <a name="rem2"></a>Rem (//)

Comments till end of line.

```
// this is a comment
```

# <a name="rem3"></a>Rem (\/\* \*/)

Comments a block

```
/* this is a comment */
```

# <a name="scope"></a>Scope

Creates a block where variables and functions may be locally defined. When a variable is (re)defined with `Dim` within a scope structure, this local working variable can be used from its (re)definition until the end of the scope. During this time, any variables outside the scope that have the same name will be ignored, and will not be accessible by that name. Any statements in the `Scope` block before the variable is redefined will use the variable as defined outside the scope.

```
SYS i = 4
SCOPE
   SYS i = 8
   PRINT "inner scope i = " i
END SCOPE
PRINT i
```

```
SYS i = 4
SCOPE {
   SYS i = 8
   PRINT "inner block i = " i
}
PRINT i
```

# <a name="skip"></a>Skip

Prevents code within the block from being executed.

```
SKIP {
  DIM INT i = 2
  PRINT i
}
```
