# Oxygen Basic Operators

### Assignment Operators

| Name       | Description |
| ---------- | ----------- |
| [\=](#assignment) | Assigns a value to a variable. |
| [:=](#assignment2) | Assigns a value to a variable. |

### Arithmetic Operators

| Name       | Description |
| ---------- | ----------- |
| [\+](#addition) | Sums two numeric expressions. |
| [-](#substraction) | Substracts two numeric expressions. |
| [\*](#multiplication) | Multiplies two numeric expressions. |
| [/](#division) | Divides two numeric expressions. |
| [\\](#integerdivision) | Divides two integer expressions. |
| [^](#exponentiate) | Raises a numeric expression to a given power. |

### Compound Assignment

| Name       | Description |
| ---------- | ----------- |
| [+=](#addandassign) | Adds and assigns a value to a variable. |
| [-=](#substractandassign) | Subtracts and assigns a value to a variable. |
| [\*=](#multiplyandassign) | Multiplies and assigns a value to a variable. |
| [/=](#divideandassign) | Divides and assigns a value to a variable. |
| [\=](#integerdivideandassign) | Integer divides and assigns a value to a variable. |
| [&=](#bitwiseandandassign) | Performs a bitwise-and (conjunction) and assigns the result to a variable. |
| [\|=](#bitwiseorandassign) | Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable. |
| [&&=](#booleanandandassign) | Performs a logical AND operation and assigns the result to a variable. |
| [\|\|=](#booleanorandassign) | Performs a logical OR operation and assigns the result to a variable. |
| [^^=](#booleanxorandassign) | Performs a logical XOR operation and assigns the result to a variable. |
| [And=](#bitwiseandandassign2) | Performs a bitwise-and (conjunction) and assigns the result to a variable. |
| [Or=](#bitwiseorandassign2) | Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable. |
| [Xor=](#bitwisexorandassign2) | Performs a bitwise-xor (exclusive disjunction) and assigns the result to a variable. |

### Relational and Comparison Operators

| Name       | Description |
| ---------- | ----------- |
| [==](#equalto) | Compares two expressions for equality. |
| [!=](#notequalto) | Compares two expressions for inequality. |
| [<>](#notequalto2) | Compares two expressions for inequality. |
| [<](#lessthan) | Compares an expression less than another expression. |
| [>](#greaterthan) | Compares an expression greater than another expression. |
| [<=](#lessthanorqeualto) | Compares an expression less than or equal to another expression. |
| [>=](#greaterthanorqeualto) | Compares an expression greater than or equal to another expression. |

### Logical Operators

| Name       | Description |
| ---------- | ----------- |
| [&&](#booleanand) | Returns the logical AND operation of two numeric values. |
| [\|\|](#booleanor) | Returns the logical OR of two numeric values. |

### Bitwise Operators

| Name       | Description |
| ---------- | ----------- |
| [&](#bitwiseand) | Bitwise AND. |
| [\|](#bitwiseor) | Bitwise OR. |
| [^^](#bitwisexor) | Bitwise XOR. |
| [<<](#shiftleft) | Shifts the bits of a numeric expression to the left. |
| [>>](#shiftright) | Shifts the bits of a numeric expression to the right. |
| [<<<](#rotateleft) | Shifts all bits one place to the left. |
| [>>>](#rotateright) | Shifts all bits one place to the right. |
| [And](#bitwiseand2) | Returns the bitwise-and (conjunction) of two numeric values. |
| [Or](#bitwiseor2) | Returns the bitwise-or (inclusive disjunction) of two numeric values. |
| [Xor](#bitwisexor2) | Returns the bitwise-xor (exclusive disjunction) of two numeric values. |

# <a name="assignment"></a>Assigment Operator (=)

Assigns a value to a variable.

```
DIM x AS LONG
x = 5
```

# <a name="assignment2"></a>Assigment Operator (:=)

Assigns a value to a variable.

```
DIM x AS LONG
x := 5
```

# <a name="addition"></a>Addition Operator (+)

Sums two expressions.

```
DIM x AS LONG
x = 3 + 4
```

# <a name="substraction"></a>Substraction Operator (-)

Substracts two expressions.

```
DIM x AS LONG
x = 5 - 2
```

# <a name="multiplication"></a>Multiplication Operator (*)

Multiplies two expressions.

```
DIM x AS LONG
x = 5 * 2
```

# <a name="division"></a>Divison Operator (/)

Divides two expressions.

```
DIM x AS LONG
x = 10 / 2
```

# <a name="integerdivision"></a>Integer Divison Operator (\)

Divides two integer expressions.

```
DIM x AS LONG
x = 13 \ 2
```

# <a name="exponentiate"></a>Exponentiate Operator (^)

Raises a numeric expression to a given power.

```
DIM x AS LONG
x = 11 ^ 2
```

# <a name="addandassign"></a>Add and Assign Operator (+=)

Adds and assigns a value to a variable.

```
DIM x AS LONG = 5
x += 3
```

# <a name="substractandassign"></a>Substract and Assign Operator (-=)

Substracts and assigns a value to a variable.

```
DIM x AS LONG = 5
x -= 3
```

# <a name="multiplyandassign"></a>Multiply and Assign Operator (*=)

Multiplies and assigns a value to a variable.

```
DIM x AS LONG = 5
x *= 2
```

# <a name="divideandassign"></a>Divide and Assign Operator (/=)

Divides and assigns a value to a variable.

```
DIM x AS LONG = 10
x /= 2
```

# <a name="divideandassign"></a>Divide and Assign Operator (/=)

Divides and assigns a value to a variable.

```
DIM x AS LONG = 10
x /= 2
```

# <a name="integerdivideandassign"></a>Integer Divide and Assign Operator (\=)

Integer divides and assigns a value to a variable.

```
DIM x AS LONG = 13
x \= 2
```

# <a name="bitwiseandandassign"></a>Bitwise AND and Assign Operator (&=)

Performs a bitwise-and (conjunction) and assigns the result to a variable.

```
DIM x AS LONG = 11
x &= 1
```

# <a name="bitwiseorandassign"></a>Bitwise OR and Assign Operator (\!=)

Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable.

```
DIM x AS LONG = 1
x != 1
```

# <a name="booleanandandassign"></a>Logical AND and Assign Operator (&&=)

Performs a logical AND operation and assigns the result to a variable.

```
DIM x AS LONG = 1
x &&= 1
```

# <a name="booleanorandassign"></a>Logical OR and Assign Operator (\|\|=)

Performs a logical OR operation and assigns the result to a variable.

```
DIM x AS LONG = 1
x ||= 1
```

# <a name="booleanxorandassign"></a>Logical XOR and Assign Operator (^^=)

Performs a logical XOR operation and assigns the result to a variable.

```
DIM x AS LONG = 1
x ^^= 1
```

# <a name="bitwiseandandassign2"></a>Bitwise AND and Assign Operator (And=)

Performs a bitwise-and (conjunction) and assigns the result to a variable.

```
DIM x AS LONG = 11
x And= 1
```

# <a name="bitwiseorandassign2"></a>Bitwise OR and Assign Operator (Or=)

Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable.

```
DIM x AS LONG = 1
x Or= 1
```

# <a name="bitwisexorandassign2"></a>Bitwise XOR and Assign Operator (Xor=)

Performs a bitwise-xor (inclusive disjunction) and assigns the result to a variable.

```
DIM x AS LONG = 1
x Xor= 1
```

# <a name="equalto"></a>Operator ==

Compares two expressions for equality.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
IF x1 == x2 THEN PRINT "Equal"
```

# <a name="notequalto"></a>Operator |=

Compares two expressions for inequality.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
IF x1 |= x2 THEN PRINT "Not equal"
```

# <a name="notequalto2"></a>Operator <>

Compares two expressions for inequality.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
IF x1 <> x2 THEN PRINT "Not equal"
```

# <a name="lessthan"></a>Operator <

Compares an expression less than another expression.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
IF x1 < x2 THEN PRINT "Less"
```

# <a name="lessthan"></a>Operator >

Compares an expression greater than another expression.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
IF x2 > x1 THEN PRINT "Greater"
```

# <a name="lessthanorqeualto"></a>Operator <=

Compares an expression less than or equal to another expression.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
IF x1 < x2 THEN PRINT "Less or equal"
```

# <a name="greaterthanorqeualto"></a>Operator >=

Compares an expression greater than or equal to another expression.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
IF x2 < x1 THEN PRINT "Greater or equal"
```
