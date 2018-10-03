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
| [abs](#abs) |  |
| [asin](#asin) |  |
| [atan](#atan) |  |
| [atn](#atn) |  |
| [ceil](#ceil) |  |
| [cos](#cos) |  |
| [deg](#deg) |  |
| [floor](#floor) |  |
| [frac](#frac) |  |
| [hypot](#hypot) |  |
| [log](#log) |  |
| [log2](#log2) |  |
| [log10](#log10) |  |
| [logn](#logn) |  |
| [mod](#mod) |  |
| [pi](#pi) |  |
| [pow](#pow) |  |
| [rad](#rad) |  |
| [recip](#recip) |  |
| [round](#round) |  |
| [sgn](#sgn) |  |
| [sin](#sin) |  |
| [sqr](#sqr) |  |
| [sqrt](#sqrt) |  |
| [tan](#tan) |  |
| [trunc](#trunc) |  |

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

# <a name="asin"></a>asin

Returns angle in radians given the ratio y-coordinate/radius. In trigonometrics, arc sine is the inverse operation of sine. One radian is equivalent to 180/PI degrees.

```
dim d as double
d = asin(0.5)
```
```
dim d as double
d = asin(0.5) * 180.0 / pi
' the arc sine of 0.5 is 30 degrees
```

# <a name="cos"></a>cos

Returns the cosine of an angle of *x* radians.

```
dim d as double
d = cos(pi / 3)
```
```
dim d as double
d = cos (60.0 * PI / 180.0)
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

# <a name="trunc"></a>trunc

Rounds a float number toward zero, returning the nearest integral value that is not larger in magnitude than the float number.

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

# <a name="tan"></a>tan

Returns the tangent of a value given in radians.

```
result = tan(radians)
```

# <a name="atn"></a>atn

Returns an angle in radians given the ratio of the *y* and *x* coordinates.

#### Syntax

```
angle = atn(YXRatio) 
```
```
dim d as double
d = atn(1) * 4
' Output: 3.1415926535897931
```

# <a name="atan"></a>atan

Returns the principal value of the arc tangent of *y*/*x*, expressed in radians. One radian is equivalent to 180/PI degrees.

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
