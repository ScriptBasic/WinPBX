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
| [Global](#global) | Declare global (shared) variables between procedures. |
| [Local](#local) | Declare local variables inside a poceudre. |
| [Static](#static) | Declare static variables inside a procedure. |

### Scope

| Name       | Description |
| ---------- | ----------- |
| [Block](#block) | Starts a block. |
| [Scope](#scope) | Creates a block where variables and functions may be locally defined.  |

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
DIM LONG a(10) => (2, 4, 6, 8, 10, 12, 42, 99)
DIM LONG a[10] => (2, 4, 6, 8, 10, 12, 42, 99)
DIM a[10] => (2, 4, 6, 8, 10, 12, 42, 99)
LONG a[10] => (2, 4, 6, 8, 10, 12, 42, 99)
LONG a[] => (2, 4, 6, 8, 10, 12, 42, 99)
LONG a => (2, 4, 6, 8, 10, 12, 42, 99)
LONG a {2, 4, 6, 8, 10, 12, 42, 99}
```

Pointered variable

```
DIM a AS STRING = "ABCDEFGHI"
DIM AS STRING a =  "ABCDEFGHI"
DIM VYTE b AT STRPTR(a)
DIM BYTE BYREF b : @b = STRPTR(a)
BYTE b AT STRPTR(a)
BYTE *b = STRPTR(a)
PRINT b[7]   ' 71 G
```

Using dynamic memory

```
DIM FLoAT f AT GetMemory 1024 * 4
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


