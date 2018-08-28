# CComplex Class

Complex numbers are represented using the type _complex. The real and imaginary part are stored in the members x and y.

```
TYPE _complex
   x AS DOUBLE   ' real part
   y AS DOUBLE   ' imaginary part
END TYPE
```

### Constructors

Create a new instance of the **CComplex** class and assigns the values passed to it.

```
CONSTRUCTOR CComplex
CONSTRUCTOR CComplex (BYVAL x AS DOUBLE = 0, BYVAL y AS DOUBLE = 0)
CONSTRUCTOR CComplex (BYREF cpx AS CComplex)
CONSTRUCTOR CComplex (BYREF cpx AS _complex)
```

| Parameter  | Description |
| ---------- | ----------- |
| *x, y* | Uses the cartesian components (x,y) to set the real and imaginary parts of the complex number. |
| *cpx* | An instance of the **CComplex** class or a **\_complex** structure. |

#### Examples

'''
DIM cpx AS CComplex = TYPE(3, 4)
DIM cpx2 AS CComplex = cpx
'''

'''
DIM cpx AS CComplex = TYPE<_complex>(3, 4)
'''

### Operators

| Name       | Description |
| ---------- | ----------- |
| [Operator LET](#Operator1) | Assigns a value to a **CCUR** variable. |
| [CAST operators](#Operator2) | Converts a CCUR into another data type. |
| [Comparison operators](#Operator3) | Compares currency numbers. |
| [Math operators](#Operator4) | Add, subtract, multiply or divide currency numbers. |

# <a name="Operator1"></a>Operator LET (=)

Assigns a value to a CComplex variable.

```
OPERATOR LET (BYREF z AS CComplex)
OPERATOR LET (BYREF z AS _complex)
```

| Parameter  | Description |
| ---------- | ----------- |
| *z* | An instance of the CComplex class or a _complex structure. |

```
DIM cpx AS CComplex = TYPE(3, 4)
DIM cpx2 AS CComplex = cpx
```
```
DIM cpx AS CComplex
cpx = CComplex(3, 4)
```
```
DIM cpx AS CComplex = TYPE<_complex>(3, 4)
```

# <a name="Operator2"></a>Operator CAST

Returns the underlying **_complex** number.

```
OPERATOR CAST () AS _complex
OPERATOR CAST () AS STRING
```

#### Remarks

This overloaded operator is not called directly.

The second overloaded operator returns the complex number as a formatted string that can be used with the PRINT statement.

# <a name="Operator3"></a>Comparison operators

Compares complex numbers for equality or inequality.

```
OPERATOR = (BYREF z1 AS CComplex, BYREF z2 AS CComplex) AS BOOLEAN
OPERATOR <> (BYREF z1 AS CComplex, BYREF z2 AS CComplex) AS BOOLEAN
```

#### Exammple

```
DIM cpx1 AS CComplex = CComplex(1, 2)
DIM cpx2 AS CComplex = CComplex(3, 4)
IF cpx1 = cpx2 THEN PRINT "equal" ELSE PRINT "different"
```

# <a name="Operator4"></a>Math operators

```
OPERATOR + (BYREF z1 AS CComplex, BYREF z2 AS CComplex) AS CComplex
OPERATOR + (BYVAL a AS DOUBLE, BYREF z AS CComplex) AS CComplex
OPERATOR + (BYREF z AS CComplex, BYVAL a AS DOUBLE) AS CComplex
OPERATOR - (BYREF z1 AS CComplex, BYREF z2 AS CComplex) AS CComplex
OPERATOR - (BYVAL a AS DOUBLE, BYREF z AS CComplex) AS CComplex
OPERATOR - (BYREF z AS CComplex, BYVAL a AS DOUBLE) AS CComplex
OPERATOR * (BYREF z1 AS CComplex, BYREF z2 AS CComplex) AS CComplex
OPERATOR * (BYVAL a AS DOUBLE, BYREF z AS CComplex) AS CComplex
OPERATOR * (BYREF z AS CComplex, BYVAL a AS DOUBLE) AS CComplex
OPERATOR / (BYREF leftside AS CComplex, BYREF rightside AS CComplex) AS CComplex
OPERATOR / (BYVAL a AS DOUBLE, BYREF z AS CComplex) AS CComplex
OPERATOR / (BYREF z AS CComplex, BYVAL a AS DOUBLE) AS CComplex
OPERATOR += (BYREF z AS CComplex)
OPERATOR -= (BYREF z AS CComplex)
OPERATOR *= (BYREF z AS CComplex)
OPERATOR /= (BYREF z AS CComplex)
OPERATOR - (BYREF z AS CComplex, BYVAL a AS DOUBLE) AS CComplex
OPERATOR ^ (BYREF value AS CComplex, BYREF power AS CComplex) AS CComplex
OPERATOR ^ (BYREF value AS CComplex, BYVAL power AS DOUBLE) AS CComplex
```

#### Examples

```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex(5, 6)
cpx2 = cpx1 + cpx2
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx2 = cpx1 + 11
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx2 = 11 + cpx1
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx2 = cpx1 - cpx2
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex
cpx2 = cpx1 - 11
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex
cpx2 = 11 - cpx1
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx2 = cpx1 * cpx2
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex
cpx2 = cpx1 * 11
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex
cpx2 = 11 * cpx1
```
```
DIM cpx1 AS CComplex = CComplex(5, 6)
DIM cpx2 AS CComplex = CComplex(2, 3)
cpx2 = cpx1 / cpx2
```
```
DIM cpx1 AS CComplex = CComplex(5, 6)
DIM cpx2 AS CComplex
cpx2 = cpx1 / 11
```
```
DIM cpx1 AS CComplex = CComplex(5, 6)
DIM cpx2 AS CComplex
cpx2 = 11 / cpx1
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx1 += cpx2
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx2 -= cpx1
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx1 *= cpx2
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = CComplex(5, 6)
cpx2 /= cpx1
```
```
DIM cpx1 AS CComplex = CComplex(3, 4)
DIM cpx2 AS CComplex = -cpx1
```
