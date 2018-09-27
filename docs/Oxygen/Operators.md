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
| [-](#negate) | Changes the sign of a numeric expression. |
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
| [\|\|](#booleanor) | Returns the logical OR operation of two numeric values. |

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

### Explicit Type Conversion Operator

| Name       | Description |
| ---------- | ----------- |
| [()](#explicitcast) | Allows explicit type conversion using syntax similar to the function-call syntax. |

### Overloading Operators

Customised operations can be associated with UDTs and classes.

This is done using an extension of the macro system. This scheme supports both Basic and Assembler in-line code, without additional overheads.

Operator macros have the same name as the type with `_op` tacked on to the end. Each operator is defined in an internal macro, named with a dot followed by  the operator in double quotes.

`."load"` and `."save"` are invoked at the start and end of expressions respectively, and also when opening and closing brackets, including automatic operator-precedence inserted brackets.

**Example 1.** xyz vectors:

```
'PARTIAL DEMO

type vector3f
  float x,y,z
end type

macro vector3f_op(a)
  macro ."load"(a)
    vector3f acc
    acc.x = a.x
    acc.y = a.y
    acc.z = a.z
  end macro
  macro ."save"(a)
    a.x = acc.x
    a.y = acc.y
    a.z = acc.z
  end macro
  macro ."neg"(a)
    vector3f acc
    acc.x = -a.x
    acc.y = -a.y
    acc.z = -a.z
  end macro
  macro ."+"(a)
    acc.x += a.x
    acc.y += a.y
    acc.z += a.z
  end macro
  macro ."-"(a)
    acc.x -= a.x
    acc.y -= a.y
    acc.z -= a.z
  end macro
  macro ."*"(a)
    acc.x *= a.x
    acc.y *= a.y
    acc.z *= a.z
  end macro
  macro ."/"(a)
    acc.x /= a.x
    acc.y /= a.y
    acc.z /= a.z
  end macro
  '
  macro ."str" string (out,a) 'CORE FUNCTIONS
    out=str(a.x)+","+str(a.y)+","+str(a.z)
  end macro
  '
end macro

'TESTS
'#recordof "r.txt" vector3f_op
dim vector3f A = {1,2,3}
dim vector3f B = {10,20,30}
dim vector3f C = {10,100,1000}

print str(A)
print str(A+B)
print str(C*(A+B))
```
**Example 2.** Assembly Code:

```
'PARTIAL DEMO / 32bit ASSEMBLER CODING

type int32i
  int i
end type

macro int32i_op(a)
  macro ."load"(a)
    push eax
    mov eax,a.i
  end macro
  macro ."save"(a)
    mov a.i,eax
    pop eax
  end macro
  macro ."neg"(a)
    push eax
    mov eax,a.i
    neg eax
  end macro
  macro ."+"(a)
    add eax,a.i
  end macro
  macro ."-"(a)
    add eax,a.i
  end macro
  macro ."*"(a)
    imul a.i
  end macro
  macro ."/"(a)
    idiv a.i
  end macro
  '
  macro ."str" string (out,a)
    out=str(a.i)
  end macro
  '
end macro

'TESTS
'#recordof int32i_op
dim int32i A={1}
dim int32i B={10}
dim int32i C={100}

print str(A)
print str(A+B)
print str(C*(A+B))
```

# <a name="assignment"></a>Assigment Operator (=)

Assigns a value to a variable.

```
DIM x AS LONG
x = 5
```

The `=` operator is also used to compare two expressions for equality, but if the #assign directive is on, `==`must always be used to test equality instead of `=`. When this directive is active, **=** emulates the C convention of `=` always being an assignment operator in conditional statements, e.g.

```
#assign on
if hresult = QueryInterface(gu,ob) then ...
```

the hresult variable receives the result code of the call to QueryInterface.

# <a name="assignment2"></a>Assigment Operator (:=)

Assigns a value to a variable.

```
DIM x AS LONG
x := 5
```

`:=` is an assignment operator which can be used inside a conditional expression, distinct from `=` as an equality operator.

```
while bRet := GetMessage @wm, 0, 0, 0
   if bRet == -1 then
   '  show an error message
   ...
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

# <a name="negate"></a>Negate Operator (-)

Returns the negative of the expression.

```
DIM x AS LONG = 123
x = -x
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

The second operand is evaluated only if the first operand evaluates to true (nonzero). This evaluation eliminates needless evaluation of the second operand when the logical AND expression is false.

# <a name="booleanorandassign"></a>Logical OR and Assign Operator (\|\|=)

Performs a logical OR operation and assigns the result to a variable.

```
DIM x AS LONG = 1
x ||= 1
```

The logical OR operator (||) returns the boolean value true if either or both operands is true and returns false otherwise. The operands are implicitly converted to type bool prior to evaluation, and the result is of type bool. Logical OR has left-to-right associativity.

The operands to the logical OR operator need not be of the same type, but they must be of integral or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before continuing evaluation of the logical OR expression.

The second operand is evaluated only if the first operand evaluates to false (0). This eliminates needless evaluation of the second operand when the logical OR expression is true.
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

If the #assign directive is on, `==` must always be used to test equality instead of `=`.

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

# <a name="greaterthan"></a>Operator >

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

# <a name="booleanand"></a>Operator &&

Returns the logical AND operation of two numeric values.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
PRINT x1 && x2
```

The logical AND operator (&&) returns the boolean value true if both operands are true and returns false otherwise. The operands are implicitly converted to type bool prior to evaluation, and the result is of type bool. Logical AND has left-to-right associativity.

The operands to the logical AND operator need not be of the same type, but they must be of integral or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before continuing evaluation of the logical AND expression.

# <a name="booleanor"></a>Operator \|\|

Returns the logical OR operation of two numeric values.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 2
PRINT x1 || x2
```

The logical OR operator (\|\|) returns the boolean value true if either or both operands is true and returns false otherwise. The operands are implicitly converted to type bool prior to evaluation, and the result is of type bool. Logical OR has left-to-right associativity.

The operands to the logical OR operator need not be of the same type, but they must be of integral or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before continuing evaluation of the logical OR expression.

The second operand is evaluated only if the first operand evaluates to false (0). This eliminates needless evaluation of the second operand when the logical OR expression is true.

# <a name="bitwiseand"></a>Bitwise AND Operator (&)

Performs a bitwise AND operation.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 & x2
```

# <a name="bitwiseor"></a>Bitwise OR Operator (\|)

Performs a bitwise OR operation.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 | x2
```

# <a name="bitwisexor"></a>Bitwise XOR Operator (^^)

Performs a bitwise XOR operation.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 ^^ x2
```

# <a name="shiftleft"></a>Shift Left Operator (<<)

Shifts the bits of a numeric expression to the left.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 << x2
```

# <a name="shiftright"></a>Shift Right Operator (>>)

Shifts the bits of a numeric expression to the right.

```
DIM x1 AS LONG = 2
DIM x2 AS LONG = 1
PRINT x1 >> x2
```

# <a name="rotateleft"></a>Rotate Left Operator (<<<)

Shifts all bits one place to the left.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 <<< x2
```

# <a name="rotateright"></a>Rotate Right Operator (>>>)

Shifts all bits one place to the left.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 >>> x2
```

# <a name="bitwiseand2"></a>Bitwise AND Operator (And)

Performs a bitwise AND operation.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 And x2
```

# <a name="bitwiseor2"></a>Bitwise OR Operator (Or)

Performs a bitwise OR operation.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 Or x2
```

# <a name="bitwisexor2"></a>Bitwise XOR Operator (Xor)

Performs a bitwise XOR operation.

```
DIM x1 AS LONG = 1
DIM x2 AS LONG = 1
PRINT x1 Xor x2
```

# <a name="explicitcast"></a>Explicit Type Conversion Operator: ()

Allows explicit type conversion using syntax similar to the function-call syntax.

```
int i = int(d)
```
