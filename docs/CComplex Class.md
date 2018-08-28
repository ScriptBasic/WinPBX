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

```
DIM cpx AS CComplex = TYPE(3, 4)
DIM cpx2 AS CComplex = cpx
```
```
DIM cpx AS CComplex = TYPE<_complex>(3, 4)
```

### Operators

| Name       | Description |
| ---------- | ----------- |
| [Operator LET](#Operator1) | Assigns a value to a **CComplex** variable. |
| [CAST operators](#Operator2) | Converts a **CComplex** into another data type. |
| [Comparison operators](#Operator3) | Compares currency numbers. |
| [Math operators](#Operator4) | Add, subtract, multiply or divide currency numbers. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [ArcCosH](#ArcCosH) | Calculates the inverse hyperbolic cosine. |
| [ArcTanH](#ArcTanH) | Returns the inverse hyperbolic tangent of a number. |
| [CAbs](#CAbs) | Returns the magnitude of this complex number. Alias: **CMagnitude**. |
| [CAbs2](#CAbs2) | Returns the squared magnitude of this complex number, otherwise known as the complex norm. Alias: **CNorm**. |
| [CAdd](#CAdd) | Adds a complex number. |
| [CAddImag](#CAddImag) | Adds an imaginary number. |
| [CAddReal](#CAddReal) | Adds a real number. |
| [CArcCos](#CArcCos) | Returns the complex arccosine of this complex number. Alias: **CACos**. |
| [CArcCosH](#CArcCosH) | Returns the complex hyperbolic arccosine of this complex number. The branch cut is on the real axis, less than 1. Alias: **CACosH**. |
| [CArcCosHReal](#CArcCosHReal) | Returns the complex arccosine of this complex number. Alias: **CACos**. |
| [CArcCosHReal](#CArcCosHReal) | Returns the complex hyperbolic arccosine of a real number. Alias: **CACosHReal**. |
| [CArcCosReal](#CArcCosReal) | Returns the complex arccosine of a real number. Alias: **CACosReal**. |
| [CArcCot](#CArcCot) | Returns the complex arccotangent of this complex number. Alias: **CACot**. |
| [CArcCotH](#CArcCotH) | Returns the complex hyperbolic arccotangent of this complex number. Alias: **CACotH**. |
| [CArcCotH](#CArcCotH) | Returns the complex hyperbolic arccotangent of this complex number. Alias: **CACotH**. |
| [CArcCsc](#CArcCsc) | Returns the complex arccosecant of this complex number. Alias: **CACsc**. |
| [CArcCscH](#CArcCscH) | Returns the complex hyperbolic arccosecant of this complex number. Alias: **CACscH**. |
| [CArcCscReal](#CArcCscReal) | Returns the complex arccosecant of a real number. Alias: **CACscReal**. |
| [CArcSec](#CArcSec) | Returns the complex arcsecant of this complex number. Alias: **CASec**. |
| [CArcSecH](#CArcSecH) | Returns the complex hyperbolic arcsecant of this complex number. Alias: **CASecH**. |
| [CArcSecReal](#CArcSecReal) | Returns the complex arcsecant of a real number. Alias: **CASecReal**. |
| [CArcSin](#CArcSin) | Returns the complex arcsine of this complex number. The branch cuts are on the real axis, less than -1 and greater than 1. Alias. **CASin**. |
| [CArcSinH](#CArcSinH) | Returns the complex hyperbolic arcsine of this complex number. The branch cuts are on the imaginary axis, below -i and above i. Alias: **CASinH**. |
| [CArcSinReal](#CArcSinReal) | Returns the complex arcsine of a real number. Alias: **CASinReal**. |
| [CArcTan](#CArcTan) | Returns the complex arctangent of this complex number. The branch cuts are on the imaginary axis, below -i and above i. Alias: **CATan**. |
| [CArcTanH](#CArcTanH) | Returns the complex hyperbolic arctangent of this complex number. The branch cuts are on the real axis, less than -1 and greater than 1. Alias: **CATanH**. |

# <a name="Operator1"></a>Operator LET (=)

Assigns a value to a CComplex variable.

```
OPERATOR LET (BYREF z AS CComplex)
OPERATOR LET (BYREF z AS _complex)
```

| Parameter  | Description |
| ---------- | ----------- |
| *z* | An instance of the **CComplex** class or a **\_complex** structure. |

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

Returns the underlying **\_complex** number.

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
