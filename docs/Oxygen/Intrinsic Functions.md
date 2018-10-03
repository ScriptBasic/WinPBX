# Oxygen Basic Intrinsic Functions

### String Functions

| Name       | Description |
| ---------- | ----------- |
| [asc](#asc) |  |
| [chr](#chr) |  |
| [frees](#frees) |  |
| [hex](#hex) |  |
| [instr](#instr) |  |
| [lcase](#lcase) |  |
| [left](#left) |  |
| [len](#len) |  |
| [ltrim](#ltrim) |  |
| [mid](#mid) |  |
| [news](#nws) |  |
| [nuls](#nuls) |  |
| [right](#right) |  |
| [rtrim](#rtrim) |  |
| [space](#space) |  |
| [str](#str) |  |
| [ucase](#ucase) |  |
| [unic](#unic) |  |
| [val](#val) |  |
| [wchr](#wchr) |  |

### Math Functions

| Name       | Description |
| ---------- | ----------- |
| [abs](#abs) | Returns the absolute value of a number (removes the negative sign). |
| [acos](#acos) | Returns the arccosine of a number. |
| [asin](#asin) | Returns the arcsine of an number. |
| [atan](#atan) | Returns arctangent of a ratio. |
| [atn](#atn) | Returns arctangent of a number. |
| [ceil](#ceil) | Rounds a float number upward. |
| [cos](#cos) | Returns the cosine of an angle of *x* radians. |
| [deg](#deg) | Converts radians to degrees. |
| [floor](#floor) | Rounds a float number downward. |
| [frac](#frac) | Returns the fractional part of a number. |
| [hypot](#hypot) | Returns the hypotenuse (longest side) of a right angle triangle given the other 2 sides. |
| [log](#log) | Returns the natural logarithm of a given number. |
| [log2](#log2) | Returns the binary (base-2) logarithm of a number. |
| [log10](#log10) | Returns the common (base-10) logarithm of a number. |
| [logn](#logn) | Returns the logarthm of the first value to the base of the second value. |
| [mod](#mod) | Returns the remainder of first value divided by the second value.  |
| [pi](#pi) | Returns pi, the ratio of the circumference of a circle to its diameter. |
| [pow](#pow) | Returns the value of the first value raised to the power of the exponent. |
| [rad](#rad) | Converts from degrees to radians. |
| [recip](#recip) | Returns the reciprocal of a value. |
| [round](#round) | Returns the integral value that is nearest to the passed float number. |
| [sgn](#sgn) | Returns the sign part of a number. |
| [sin](#sin) | Returns the sine of an angle. |
| [sqr](#sqr) | Returns the square root of a number. |
| [sqrt](#sqr) | Returns the square root of a number. |
| [tan](#tan) | Returns the tangent of a value given in radians. |
| [trunc](#trunc) | Rounds a float number towards zero. |

### Bit Manipulation Functions

| Name       | Description |
| ---------- | ----------- |
| [hibyte](#hibyte) | Returns the high-order byte of an integer value (bits 8..15). |
| [lobyte](#lobyte) | Returns the low-order byte of an integer value (bits 0..7). |
| [hiword](#hiword) | Returns the high-order word of an integer value (bits 16..31). |
| [loword](#loword) | Returns the low-order word an integer value (bits 0..15). |

### Memory Functions

| Name       | Description |
| ---------- | ----------- |
| [copy](#copy) | Copies a block of memory. |
| [copyn](#copy) | Copies a block of memory. |
| [copy0](#copy0) | Copies a null terminated string to another location. |
| [copy00](#copy00) | Copies a null terminated string of wide (2 bytes) characters to another location. |

# <a name="abs"></a>abs

Returns the absolute value of a number (removes the negative sign).

```
dim d as double
d = abs(-2.5)
' Output: 2.5
```

# <a name="acos"></a>acos

Returns the arccosine of a number. The result is within the range of 0 to Pi. `acos`is the inverse of the `cos` function. The returned angle is measured in radians (not degrees).

```
dim d as double
d = acos(0.5)
```

# <a name="asin"></a>asin

Returns the arcsine of a number. The result is within the range of -Pi/2 to Pi/2. `asin` is the inverse of the `sin` function. The returned angle is measured in radians (not degrees).

```
dim d as double
d = asin(0.5)
```
```
dim d as double
d = asin(0.5) * 180.0 / pi
' the arc sine of 0.5 is 30 degrees
```

# <a name="atan"></a>atan

Returns the arctangent of the ratio *y*/*x*, where *y* is the vertical coordinate and *x* the horizontal coordinate.  The result is withing the range of -Pi to Pi. `atan` is the inverse of the `tan` function. The returned angle is measured in radians (not degrees).

#### Syntax

```
angle = atan(y, x) 
```

| Name       | Description |
| ---------- | ----------- |
| *y* | Value representing the proportion of the y-coordinate. |
| *x* | Value representing the proportion of the x-coordinate. |

```
dim d as double
d = atan(0.5, sqr(0.75))
' Output: 3.1415926535897931
```

# <a name="atn"></a>atn

Returns the arctangent of a number. The result is within the range of -Pi/2..Pi/2. `atn` is the inverse of the `tan` function. The returned angle is measured in radians (not degrees).

#### Syntax

```
angle = atn(number) 
```
```
dim d as double
d = atn(1) * 4
' Output: 3.1415926535897931
```

# <a name="ceil"></a>ceil

Rounds a float number upward, returning the smallest integral value that is not less than the float number.

#### Syntax

```
IntegerValue = ceil(FloatValue) 
```

**Output**:

```
value   round   floor   ceil    trunc
-----   -----   -----   ----    -----
 2.3     2.0     2.0     3.0     2.0
 3.8     4.0     3.0     4.0     3.0
 5.5     6.0     5.0     6.0     5.0
-2.3    -2.0    -3.0    -2.0    -2.0
-3.8    -4.0    -4.0    -3.0    -3.0
-5.5    -6.0    -6.0    -5.0    -5.0
```

# <a name="cos"></a>cos

Returns the cosine of an angle in radians. The result is within the range of -1.0 to 1.0.

```
dim d as double
d = cos(pi / 3)
```
```
dim d as double
d = cos (60.0 * PI / 180.0)
```

# <a name="deg"></a>deg

Converts radians to degrees.

```
dim d as double
d = deg(pi)
' Output: 180
```

# <a name="floor"></a>floor

Rounds a float number downward, returning the largest integral value that is not greater than the float number.

#### Syntax

```
IntegerValue = float(FloatValue) 
```

**Output**:

```
value   round   floor   ceil    trunc
-----   -----   -----   ----    -----
 2.3     2.0     2.0     3.0     2.0
 3.8     4.0     3.0     4.0     3.0
 5.5     6.0     5.0     6.0     5.0
-2.3    -2.0    -3.0    -2.0    -2.0
-3.8    -4.0    -4.0    -3.0    -3.0
-5.5    -6.0    -6.0    -5.0    -5.0
```

# <a name="frac"></a>frac

Returns the fractional part of a number

```
dim d as double
d = frac(123.456)
' Output: 0.456
```

# <a name="hypot"></a>hypot

Returns the hypotenuse (longest side) of a right angle triangle given the other 2 sides.

```
dim d as double
d = hypot(3, 4)
```

# <a name="log"></a>log

Returns the natural logarithm of a given number.

```
dim d as double
d = log(10)
```

# <a name="log2"></a>log2

Returns the binary (base-2) logarithm of a number.

```
dim d as double
d = log2(32)
```

# <a name="log10"></a>log10

Returns the common (base-10) logarithm of a number.

```
dim d as double
d = log10(100)
```

# <a name="logn"></a>logn

Returns the logarthm of the first value to the base of the second value.

```
dim d as double
d = logn(1000, 10)
```

# <a name="mod"></a>mod

Returns the remainder of first value divided by the second value.

```
dim d as double
d = mod(83.5, 10)
' Output: 3.5
```

# <a name="pi"></a>pi

Returns pi, the ratio of the circumference of a circle to its diameter.

```
print pi
' Output: 3.1415926535897931
```

# <a name="pow"></a>pow

Returns the value of the first value raised to the power of the exponent. It is equivalent to the ^ operator.

```
dim d as double
d = pow(3)
' Output: 8
```

# <a name="rad"></a>rad

Converts from degrees to radians.

```
dim d as double
d = rad(180)
' Output: 3.1415926535897931
```

# <a name="recip"></a>recip

Returns the reciprocal of a value (x = 1 / v).

```
dim d as double
d = recip(5 / 4)
' Output: 0.8
```

# <a name="round"></a>round

Returns the integral value that is nearest to the passed float number.

#### Syntax

```
IntegerValue = round(FloatValue) 
```

**Output**:

```
value   round   floor   ceil    trunc
-----   -----   -----   ----    -----
 2.3     2.0     2.0     3.0     2.0
 3.8     4.0     3.0     4.0     3.0
 5.5     6.0     5.0     6.0     5.0
-2.3    -2.0    -3.0    -2.0    -2.0
-3.8    -4.0    -4.0    -3.0    -3.0
-5.5    -6.0    -6.0    -5.0    -5.0
```

# <a name="sgn"></a>sgn

Returns the sign part of a number.

* If number is greater than zero, it returns 1.
* If number is equal to zero, it returns 0.
* If number is less than zero, it returns -1.

```
result = sgn(-42)
```

# <a name="sin"></a>sin

Returns the sine of an angle given its value in radians.

```
dim d as double
d = sin(pi / 6)
' Output: 0.5
```

# <a name="sqr"></a>sqr / sqrt

Returns the square root of a number.

```
dim d as double
d = sqr(9)
' Output: 3
```

# <a name="tan"></a>tan

Returns the tangent of a value given in radians.

```
result = tan(radians)
```

# <a name="trunc"></a>trunc

Rounds a float number towards zero, returning the nearest integral value that is not larger in magnitude than the float number.

#### Syntax

```
IntegerValue = trunc(FloatValue) 
```

**Output**:

```
value   round   floor   ceil    trunc
-----   -----   -----   ----    -----
 2.3     2.0     2.0     3.0     2.0
 3.8     4.0     3.0     4.0     3.0
 5.5     6.0     5.0     6.0     5.0
-2.3    -2.0    -3.0    -2.0    -2.0
-3.8    -4.0    -4.0    -3.0    -3.0
-5.5    -6.0    -6.0    -5.0    -5.0
```

# <a name="hibyte"></a>hibyte

Returns the high-order byte an integer value (bits 8..15).

```
result = hibyte ( expression )
```

# <a name="lobyte"></a>lobyte

Returns the low-order byte an integer value (bits 0..7).

```
result = lobyte ( expression )
```

# <a name="hiword"></a>hiword

Returns the high-order word an integer value (bits 16..31).

```
result = hiword ( expression )
```

# <a name="loword"></a>loword

Returns the low-order word an integer value (bits 0..15).

```
result = loword ( expression )
```

# <a name="copy"></a>copy / copyn

Copies the values of *NumBytes* from the location pointed to by *SourceAddress* directly to the memory block pointed to by *DestinationAddress*. `copy` and `copyn` are the same.

#### Syntax

```
sub copy (DestinationAddress, SourceAddress, NumBytes)
```

The underlying type of the objects pointed to by both the source and destination pointers are irrelevant for this procedure; the result is a binary copy of the data. This proceudre does not check for any terminating null character in source: it always copies exactly num bytes.

To avoid overflows, the size of the memory blocks pointed to by both the *DestinationAddress* and *SourceAddress* parameters, shall be at least *NumBytes*, and should not overlap.

```
copy &dest, &src, n
copyn &dest, &src, n
```

# <a name="copy0"></a>copy0

Copies a null terminated string to another location.

```
sub copy0 (DestinationAddress, SourceAddress)
```

```
copy0 &dest, &src
```

# <a name="copy00"></a>copy00

Copies a null terminated string of wide (2 bytes) characters to another location.

```
sub copy00 (DestinationAddress, SourceAddress)
```

```
copy00 &dest, &src
```
