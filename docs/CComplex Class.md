# CComplex Class

Complex numbers are represented using the type _complex. The real and imaginary part are stored in the members x and y.

```
TYPE _complex
   x AS DOUBLE   ' real part
   y AS DOUBLE   ' imaginary part
END TYPE
```

**Include file**: CComplex.inc.

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

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [ArcCosH](#ArcCosH) | Calculates the inverse hyperbolic cosine. |
| [ArcTanH](#ArcTanH) | Returns the inverse hyperbolic tangent of a number. |
| [CAbs](#CAbs) | Returns the magnitude of this complex number. |
| [CAbs2](#CAbs2) | Returns the squared magnitude of this complex number, otherwise known as the complex norm. |
| [CACos](#CArcCos) | Returns the complex arccosine of this complex number. |
| [CACosH](#CArcCosH) | Returns the complex hyperbolic arccosine of this complex number. The branch cut is on the real axis, less than 1. |
| [CACosHReal](#CArcCosHReal) | Returns the complex arccosine of this complex number. |
| [CACosReal](#CArcCosReal) | Returns the complex arccosine of a real number. |
| [CACot](#CArcCot) | Returns the complex arccotangent of this complex number. |
| [CACotH](#CArcCotH) | Returns the complex hyperbolic arccotangent of this complex number. |
| [CACsc](#CArcCsc) | Returns the complex arccosecant of this complex number. |
| [CACscH](#CArcCscH) | Returns the complex hyperbolic arccosecant of this complex number. |
| [CACscReal](#CArcCscReal) | Returns the complex arccosecant of a real number. |
| [CAdd](#CAdd) | Adds a complex number. |
| [CAddImag](#CAddImag) | Adds an imaginary number. |
| [CAddReal](#CAddReal) | Adds a real number. |
| [CArcCos](#CArcCos) | Returns the complex arccosine of this complex number. |
| [CArcCosH](#CArcCosH) | Returns the complex hyperbolic arccosine of this complex number. The branch cut is on the real axis, less than 1. |
| [CArcCosHReal](#CArcCosHReal) | Returns the complex arccosine of this complex number. |
| [CArcCosReal](#CArcCosReal) | Returns the complex arccosine of a real number. |
| [CArcCot](#CArcCot) | Returns the complex arccotangent of this complex number. |
| [CArcCotH](#CArcCotH) | Returns the complex hyperbolic arccotangent of this complex number. |
| [CArcCsc](#CArcCsc) | Returns the complex arccosecant of this complex number. |
| [CArcCscH](#CArcCscH) | Returns the complex hyperbolic arccosecant of this complex number. |
| [CArcCscReal](#CArcCscReal) | Returns the complex arccosecant of a real number. |
| [CArcSec](#CArcSec) | Returns the complex arcsecant of this complex number. |
| [CArcSecH](#CArcSecH) | Returns the complex hyperbolic arcsecant of this complex number. |
| [CArcSecReal](#CArcSecReal) | Returns the complex arcsecant of a real number. |
| [CArcSin](#CArcSin) | Returns the complex arcsine of this complex number. The branch cuts are on the real axis, less than -1 and greater than 1. |
| [CArcSinH](#CArcSinH) | Returns the complex hyperbolic arcsine of this complex number. The branch cuts are on the imaginary axis, below -i and above i. |
| [CArcSinReal](#CArcSinReal) | Returns the complex arcsine of a real number. |
| [CArcTan](#CArcTan) | Returns the complex arctangent of this complex number. The branch cuts are on the imaginary axis, below -i and above i. |
| [CArcTanH](#CArcTanH) | Returns the complex hyperbolic arctangent of this complex number. The branch cuts are on the real axis, less than -1 and greater than 1. |
| [CArcTanHReal](#CArcTanHReal) | Returns the complex hyperbolic arctangent of a real number. |
| [CArg](#CArg) | Returns the argument of this complex number. |
| [CArgument](#CArg) | Returns the argument of this complex number. |
| [CASec](#CArcSec) | Returns the complex arcsecant of this complex number. |
| [CASecH](#CArcSecH) | Returns the complex hyperbolic arcsecant of this complex number. |
| [CASecReal](#CArcSecReal) | Returns the complex arcsecant of a real number. |
| [CASin](#CArcSin) | Returns the complex arcsine of this complex number. The branch cuts are on the real axis, less than -1 and greater than 1. |
| [CASinH](#CArcSinH) | Returns the complex hyperbolic arcsine of this complex number. The branch cuts are on the imaginary axis, below -i and above i. |
| [CASinReal](#CArcSinReal) | Returns the complex arcsine of a real number. |
| [CATan](#CArcTan) | Returns the complex arctangent of this complex number. The branch cuts are on the imaginary axis, below -i and above i. |
| [CATanH](#CArcTanH) | Returns the complex hyperbolic arctangent of this complex number. The branch cuts are on the real axis, less than -1 and greater than 1. |
| [CATanHReal](#CArcTanHReal) | Returns the complex hyperbolic arctangent of a real number. |
| [CConj](#CConjugate) | Returns the complex conjugate of this complex number. |
| [CConjugate](#CConjugate) | Returns the complex conjugate of this complex number. |
| [CCos](#CCos) | Returns the complex cosine of this complex number. |
| [CCosH](#CCosH) | Returns the complex hyperbolic cosine of this complex number. |
| [CCot](#CCot) | Returns the complex cotangent of this complex number. |
| [CCotH](#CCotH) | Returns the complex hyperbolic cotangent of this complex number. |
| [CCsc](#CCsc) | Returns the complex cosecant of this complex number. |
| [CCscH](#CCscH) | Returns the complex hyperbolic cosecant of this complex number. |
| [CDiv](#CDiv) | Divides by a complex number. |
| [CDivImag](#CDivImag) | Divides by an imaginary number. |
| [CDivReal](#CDivReal) | Divides by a real number. |
| [CExp](#CExp) | Returns the complex exponential of this complex number. |
| [CImag](#CImag) | Gets/sets the imaginary part of a complex number. |
| [CInverse](#CReciprocal) | Returns the inverse, or reciprocal, of a complex number. |
| [CLog](#CLog) | Returns the complex natural logarithm (base e) of this complex number. The branch cut is the negative real axis. |
| [CLog10](#CLog10) | Returns the complex base-10 logarithm of this complex number. |
| [CLogAbs](#CLogAbs) | Returns the natural logarithm of the magnitude of a complex number. |
| [CMagnitude](#CAbs) | Returns the magnitude of this complex number. |
| [CMul](#CMul) | Multiplies by a complex number. |
| [CMulImag](#CMulImag) | Multiplies by an imaginary number. |
| [CMulReal](#CMulReal) | Multiplies by a real number. |
| [CNeg](#CNegate) | Negates the complex number. |
| [CNegative](#CNegate) | Negates the complex number. |
| [CNeg](#CNegate) | Negates the complex number. |
| [CNorm](#CAbs2) | Returns the squared magnitude of this complex number, otherwise known as the complex norm. |
| [CPhase](#CArg) | Returns the argument of this complex number. |
| [CPolar](#CPolar) | Sets the complex number from the polar representation. |
| [CPow](#CPow) | Returns this complex number raised to a complex power or to a real number. |
| [CReal](#CReal) | Gets/sets the real part of a complex number. |
| [CRect](#CSet) | Uses the cartesian components (x,y) to set the real and imaginary parts of the complex number. |
| [CReciprocal](#CReciprocal) | Returns the inverse, or reciprocal, of a complex number. |
| [CSec](#CSec) | Returns the complex secant of this complex number. |
| [CSecH](#CSecH) | Returns the complex hyperbolic secant of this complex number. |
| [CSet](#CSet) | Uses the cartesian components (x,y) to set the real and imaginary parts of the complex number. |
| [CSgn](#CSgn) | Returns the sign of this complex number. |
| [CSin](#CSin) | Returns the complex sine of this complex number. |
| [CSinH](#CSinH) | Returns the complex hyperbolic sine of this complex number. |
| [CSqr](#CSqr) | Returns the square root of the complex number z. The branch cut is the negative real axis. The result always lies in the right half of the complex plane. |
| [CSqrt](#CSqr) | Returns the square root of the complex number z. The branch cut is the negative real axis. The result always lies in the right half of the complex plane. |
| [CSub](#CSub) | Subtracts a complex number. |
| [CSubImag](#CSubImag) | Subtracts an imaginary number. |
| [CSubReal](#CSubReal) | Subtracts a real number. |
| [CSwap](#CSwap) | Exchanges the contents of two complex numbers. |
| [CTan](#CTan) | Returns the complex tangent of this complex number. |
| [CTanH](#CTanH) | Returns the complex hyperbolic tangent of this complex number. |
| [IsInf](#IsInfinity) | Determines whether the argument is an infinity. |
| [IsInfinity](#IsInfinity) | Determines whether the argument is an infinity. |

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

# <a name="ArcCosH"></a>ArcCosH

Calculates the inverse hyperbolic cosine.

```
FUNCTION ArcCosH (BYVAL x AS DOUBLE) AS DOUBLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *x* | A double value. |

#### Example

```
DIM AS double pi = 3.1415926535
DIM AS double x, y
DIM c AS CComplex
x = cosh(pi / 4)
y = c.ArcCosH(x)
print "cosh = ", pi/4, x
print "ArcCosH = ", x, y

Output:
cosh =  0.785398163375      1.324609089232506
acosh = 1.324609089232506   0.7853981633749999
```

# <a name="ArcTanH"></a>ArcTanH

Returns the inverse hyperbolic tangent of a number.

```
FUNCTION ArcTanH (BYVAL x AS DOUBLE) AS DOUBLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *x* | A double value. |

#### Example

```
print atanh(0.76159416)
Output: 1.00000000962972

print atanh(-0.1)
Output: -0.1003353477310756
```

# <a name="CAbs"></a>CAbs / CMagnitude

Returns the magnitude of this complex number.

```
FUNCTION CAbs () AS DOUBLE
FUNCTION CMagnitude () AS DOUBLE
```

#### Example

```
DIM cpx AS CComplex = CComplex(2, 3)
PRINT cpx.CAbs
Output: 3.60555127546399
```

# <a name="CAbs2"></a>CAbs2 / CNorm

Returns the squared magnitude of this complex number, otherwise known as the complex norm.

```
FUNCTION CAbs2 () AS DOUBLE
FUNCTION CNorm () AS DOUBLE
```

#### Example

```
DIM cpx AS CComplex = CComplex(2, 3)
PRINT cpx.CAbs2
Output: 13
```

# <a name="CArcCos"></a>CArcCos / CACos

Returns the complex arccosine of this complex number.

```
FUNCTION CArcCos () AS CComplex
FUNCTION CACos () AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
print cpx.CArcCos(z)
Output: 0.9045568943023814 -1.061275061905036 * i
```

# <a name="CArcCosH"></a>CArcCosH / CACosH

Returns the complex hyperbolic arccosine of this complex number. The branch cut is on the real axis, less than 1.

```
FUNCTION CArcCosH () AS CComplex
FUNCTION CACosH () AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
print cpx.CArcCosH
Output: 1.061275061905036 +0.9045568943023813 * i
```

# <a name="CArcCosHReal"></a>CArcCosHReal / CACosHReal

Returns the complex hyperbolic arccosine of a real number.

```
FUNCTION CArcCosHReal (BYVAL value AS DOUBLE) AS CComplex
FUNCTION CACosHReal (BYVAL value AS DOUBLE) AS CComplex
```

| Parameter  | Description |
| ---------- | ----------- |
| *value* | A double value representing the real part of a complex number. |

# <a name="CArcCosReal"></a>CArcCosReal / CACosReal

Returns the complex arccosine of a real number.<br>
For a between -1 and 1, the function returns a real value in the range \[0, pi].<br>
For a less than -1 the result has a real part of pi and a negative imaginary part.<br>
For a greater than 1 the result is purely imaginary and positive.

```
FUNCTION CArcCosReal (BYVAL value AS DOUBLE) AS CComplex
FUNCTION CACosReal (BYVAL value AS DOUBLE) AS CComplex
```

| Parameter  | Description |
| ---------- | ----------- |
| *value* | A double value representing the real part of a complex number. |

#### Example

```
DIM cpx AS CComplex
print cpx.CArcCosReal(1) ' = 0 0 * i
print cpx.CArcCosReal(-1) ' = 3.141592653589793 0 * i
print cpx.CArcCosReal(2) ' = 0 +1.316957896924817 * i
```

# <a name="CArcCot"></a>CArcCot / CACot

Returns the complex arccotangent of this complex number.

```
FUNCTION CArcCot () AS CComplex
FUNCTION CACot () AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
print cpx.CArcCot
Output: 0.5535743588970452 -0.4023594781085251 * i
```

# <a name="CArcCotH"></a>CArcCotH / CACotH

Returns the complex hyperbolic arccotangent of this complex number. Alias: CACotH.

```
FUNCTION CArcCotH () AS CComplex
FUNCTION CACotH () AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
PRINT cpx.CArcCotH
Output: 0.4023594781085251 -0.5535743588970452 * i
```

# <a name="CArcCsc"></a>CArcCsc / CACsc

Returns the complex arccosecant of this complex number.

```
FUNCTION CArcCsc () AS CComplex
FUNCTION CACsc () AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
print cpx.CArcCsc
Output: 0.4522784471511907 -0.5306375309525178 * i
```

# <a name="CArcCscH"></a>CArcCscH / CACscH

Returns the complex hyperbolic arccosecant of this complex number.

```
FUNCTION CArcCscH () AS CComplex
FUNCTION CACscH () AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
PRINT cpx.CArcCscH
Output: 0.5306375309525179 -0.4522784471511906 * i
```

# <a name="CArcCscReal"></a>CArcCscReal / CACscReal

Returns the complex arccosecant of a real number. 

```
FUNCTION CArcCscReal (BYVAL value AS DOUBLE) AS CComplex
FUNCTION CACscReal (BYVAL value AS DOUBLE) AS CComplex
```

#### Example

```
DIM cpx AS CComplex = CComplex(1, 1)
print cpx.CArcCscReal(1)
Output: 1.570796326794897 0 * i
```

# <a name="CArcSec"></a>CArcSec / CASec

Returns the complex arcsecant of this complex number.

```
FUNCTION CArcSec () AS CComplex
FUNCTION CASec () AS CComplex
```

#### Example

```
DIM cpx AS CComplex
print cpx.CArcSec(1.1)
Output: 1.118517879643706 +0.5306375309525176 * i
```
