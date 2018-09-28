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
| [$](#equate1) | Defines an equate (which can be used as constant). |
| [%](#equate2) | Defines an equate (which can be used as constant). |
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

# <a name="let"></a>Let

Similar to `Dim`but the type is inferred from the assigned value.

```
LET s = "This is a string"
PRINT TypeOf(s)  ' Result: "string"
```

