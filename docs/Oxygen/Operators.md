# Oxygen Basic Operators

### Assignment Operators

| Name       | Description |
| ---------- | ----------- |
| [\=](#assignment) | Assigns a value to a variable. |
| [:=](#assignment2) | Assigns a value to a variable. |
| [=>](#assignment3) | Assigns a value to a variable or values to an array. |
| [<=](#assignment4) | Assigns a value to a variable or values to an array. |

### String Operators

| Name       | Description |
| ---------- | ----------- |
| [+](#concat) | Concatenates two strings, converting non-strings to strings as needed. |
| [&](#concat2) | Concatenates two strings, converting non-strings to strings as needed. |
| [stptr](#strptr) | Returns the address of a string's character data. |

### Arithmetic Operators

| Name       | Description |
| ---------- | ----------- |
| [+](#addition) | Sums two numeric expressions. |
| [-](#substraction) | Substracts two numeric expressions. |
| [-](#negate) | Changes the sign of a numeric expression. |
| [\*](#multiplication) | Multiplies two numeric expressions. |
| [/](#division) | Divides two numeric expressions. |
| [\\](#integerdivision) | Divides two integer expressions. |
| [^](#exponentiate) | Raises a numeric expression to a given power. |

### Increment and Decrement Operators

| Name       | Description |
| ---------- | ----------- |
| [++](#increment) | Increments its operand by 1. |
| [--](#decrement) | Decrements its operand by 1. |

### Compound Assignment

| Name       | Description |
| ---------- | ----------- |
| [+=](#addandassign) | Adds and assigns a value to a variable. |
| [-=](#substractandassign) | Subtracts and assigns a value to a variable. |
| [\*=](#multiplyandassign) | Multiplies and assigns a value to a variable. |
| [/=](#divideandassign) | Divides and assigns a value to a variable. |
| [\\=](#integerdivideandassign) | Integer divides and assigns a value to a variable. |
| [&=](#bitwiseandandassign) | Performs a bitwise-and (conjunction) and assigns the result to a variable. |
| [\|=](#bitwiseorandassign) | Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable. |
| [&&=](#booleanandandassign) | Performs a logical and operation and assigns the result to a variable. |
| [\|\|=](#booleanorandassign) | Performs a logical or operation and assigns the result to a variable. |
| [^^=](#booleanxorandassign) | Performs a logical xor operation and assigns the result to a variable. |
| [and=](#bitwiseandandassign2) | Performs a bitwise-and (conjunction) and assigns the result to a variable. |
| [or=](#bitwiseorandassign2) | Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable. |
| [xor=](#bitwisexorandassign2) | Performs a bitwise-xor (exclusive disjunction) and assigns the result to a variable. |

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
| [&&](#booleanand) | Returns the logical And operation of two numeric values. |
| [\|\|](#booleanor) | Returns the logical Or operation of two numeric values. |

### Bitwise Operators

| Name       | Description |
| ---------- | ----------- |
| [&](#bitwiseand) | Bitwise And. |
| [\|](#bitwiseor) | Bitwise Or. |
| [^^](#bitwisexor) | Bitwise Xor. |
| [<<](#shiftleft) | Shifts the bits of a numeric expression to the left. |
| [>>](#shiftright) | Shifts the bits of a numeric expression to the right. |
| [<<<](#rotateleft) | Shifts all bits one place to the left. |
| [>>>](#rotateright) | Shifts all bits one place to the right. |
| [and](#bitwiseand2) | Returns the bitwise-and (conjunction) of two numeric values. |
| [not](#bitwisenot) | Returns the bitwise-not (complement) of a numeric value. |
| [or](#bitwiseor2) | Returns the bitwise-or (inclusive disjunction) of two numeric values. |
| [xor](#bitwisexor2) | Returns the bitwise-xor (exclusive disjunction) of two numeric values. |
| [not](#bitwisenot) | Returns the bitwise-not (complement) of a numeric value. |

### Pointer Operators

| Name       | Description |
| ---------- | ----------- |
| [@](#addressof) | Returns the address of a variable, string literal or procedure. |
| [\*](#valueof) | Dereferenes a pointer. |
| [[]](#pointerindex) | Returns a reference to memory offset from an address. |
| [addr](#addr) | Assembler only. Loads the address of a variable to a register. |

### Casting operators

| Name       | Description |
| ---------- | ----------- |
| [cast](#cast) | Changes or specifies the type of a variable temporarily, in an expression. |
| [()](#explicitcast) | Allows explicit type conversion using syntax similar to the function-call syntax. |
| [?](#castint) | Casts variables as integers. |

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

# <a name="addressof"></a>AddressOf Operator (@)

Returns the address of a variable, string literal or procedure.

```
DIM v AS LONG = 12345
print @v
```
```
print @"Test string"
```
```
sub Foo
end sub
print @Foo
```

Can also be used to read and write data of variables and arrays of variables, by reference. Unlike C, pointer resolution is handled implictly. So the @ operator is required for manipulating pointers. It is similar to the & operator in C. 

```
int a = 42
print @a 'address of a
int *b 'indirect (pointer) variable
@b = @a   'coupled by address
print b   ' 42
```

# <a name="valueof"></a>ValueOf Operator (*)

Dereferenes a pointer. Unlike C, pointer resolution is normally handled implictly. 

```
dim s as asciiz * 260 = "Test string"
dim p as asciiz ptr
@p = strfptr(s)
print p
' Output "Test string"
```
```
dim s as asciiz * 260 = "Test string"
char *p = strptr(s)
print s
```
```
dim s as asciiz2 * 260 = "Test string"
wchar *p = strptr(s)
print s
```
```
dim s as wstring = "Test string"
wchar *p = strptr(s)
print s
```
```
dim s as wide = "Test string"
wchar *p = strptr(s)
print s
```

# <a name="pointerindex"></a>Pointer index operator: []

You can use square brackets to index off a pointer. No bounds checking is performed.

```
dim s as string = "ABCDEFGHIJ"
dim b as byte at strptr(s)
print str(b[3]) " :  " chr(b[3])
b[3] = 84   ' "T"
' --or--
' b[3] = asc("T")
print s
```

# <a name="addr"></a>addr

Assembler only. Loads the address of a variable to a register.

```
sys a
addr ecx,a
```

# <a name="assignment"></a>Assigment operator (=)

Assigns a value to a variable.

```
dim x as long
x = 5
```

Multiple assignments

```
sys a, b, c
a = b = c = 3.5
print a "  " b "  " c
```
```
double a, b, c
a = b = c = 3.5
print a "  " b "  " c
```
```
string a, b, c
a = b = c = "okay"
print a " " b " " c
```

```
' On an array of compoud types
type LabelledPoint single x, y, z, string s
dim as LabelledPoint v[100]
v[2]<=
0,1,2,"point A",
0,3,4,"point B",
1,1,2,"point C",
1,3,4,"point D"
%tab=chr 9
print v[3].x tab v[3].y tab v[3].z  tab v[3].s
```

The `=` operator is also used to compare two expressions for equality, but if the `#assign` directive is on, `==`must always be used to test equality instead of `=`. When this directive is active, **=** emulates the C convention of `=` always being an assignment operator in conditional statements, e.g.

```
#assign on
if hresult = QueryInterface(gu,ob) then ...
```

the *hresult* variable receives the result code of the call to **QueryInterface**.

# <a name="assignment2"></a>Assigment operator (:=)

Assigns a value to a variable.

```
dim x as long
x := 5
```

`:=` is an assignment operator which can be used inside a conditional expression, distinct from `=` as an equality operator.

```
while bRet := GetMessage @wm, 0, 0, 0
   if bRet == -1 then
   '  show an error message
   ...
```

# <a name="assignment2"></a>Assigment operator (=>)

Assigns a value to a variable or values to an array. Can be used instead of `=` to avoid ambiguity in certain cases.

```
dim x as long => 10
dim long a[8] => (2, 4, 6, 8, 10, 12, 42, 99)
long a[8] <= (2,4,6,8,10,12,42,99)
```

# <a name="assignment3"></a>Assigment operator (<=)

Assigns a value to a variable or values to an array. Can be used instead of `=` to avoid ambiguity in certain cases.

```
dim x as long <= 10
long a[8] <= (2,4,6,8,10,12,42,99)
```

# <a name="concat"></a>String concatenation operator (+)

Concatenates two strings, converting non-strings to strings as needed.

```
dim s1 as string = "ABCDEFG"
dim s2 as string = "HIJKLM"
s1 = s1 + s2
```

```
dim s1 as string = "ABCDEFG"
s1 = s1 + "HIJKLM"
```

```
dim s1 as string = "ABCDEFG"
s1 = s1 + 123456
```

# <a name="concat2"></a>String concatenation operator (&)

Concatenates two strings, converting non-strings to strings as needed.

```
dim s1 as string = "ABCDEFG"
dim s2 as string = "HIJKLM"
s1 = s1 & s2
```

```
dim s1 as string = "ABCDEFG"
s1 = s1 & "HIJKLM"
```

```
dim s1 as string = "ABCDEFG"
s1 = s1 & 123456
```

# <a name="strptr"></a>strptr

Returns the address of a string's character data.

```
string s = "Hello"
sys a = strptr(s)
```

# <a name="addition"></a>Addition operator (+)

Sums two expressions.

```
dim x as long
x = 3 + 4
```

# <a name="substraction"></a>Substraction operator (-)

Substracts two expressions.

```
dim x as long
x = 5 - 2
```

# <a name="negate"></a>Negate operator (-)

Returns the negative of the expression.

```
dim x as long = 123
x = -x
```

# <a name="multiplication"></a>Multiplication operator (*)

Multiplies two expressions.

```
dim x as long
x = 5 * 2
```

# <a name="division"></a>Divison operator (/)

Divides two expressions.

```
dim x as long
x = 10 / 2
```

# <a name="integerdivision"></a>Integer divison operator (\)

Divides two integer expressions.

```
dim x as long
x = 13 \ 2
```

# <a name="exponentiate"></a>Exponentiate operator (^)

Raises a numeric expression to a given power.

```
dim x as long
x = 11 ^ 2
```

# <a name="increment"></a>Increment operator (++)

Increments its operand by 1. The increment operator can appear before or after its operand: `++variable` and `variable++`.

The first form is a prefix increment operation. The result of the operation is the value of the operand after it has been incremented.

The second form is a postfix increment operation. The result of the operation is the value of the operand before it has been incremented.

```
dim x as long = 5
dim r as long = ++x
print r
' Output 6
```

```
dim x as long = 5
dim r as long = x++
print r
' Output 5
```

# <a name="decrement"></a>Decrement operator (--)

Decrements its operand by 1. The decrement operator can appear before or after its operand: `--variable` and `variable--`.

The first form is a prefix decrement operation. The result of the operation is the value of the operand "after" it has been decremented. The second form is a postfix decrement operation. The result of the operation is the value of the operand "before" it has been decremented.

```
dim x as long = 5
dim r as long = --x
print r
' Output 4
```

```
dim as long = 5
dim r as long = x--
print r
' Output 5
```

# <a name="addandassign"></a>Add and assign operator (+=)

Adds and assigns a value to a variable.

```
dim x as long = 5
x += 3
```

```
dim s as string = "ABCDEFG"
s += "HIJK"
```

If the target is a string and the value added is a number, it first converts the number to a string.

```
dim s as string = "ABCDEFG"
s += 123456
```

# <a name="substractandassign"></a>Substract and assign operator (-=)

Substracts and assigns a value to a variable.

```
dim x as long = 5
x -= 3
```

# <a name="multiplyandassign"></a>Multiply and assign operator (*=)

Multiplies and assigns a value to a variable.

```
dim x as long = 5
x *= 2
```

# <a name="divideandassign"></a>Divide and assign operator (/=)

Divides and assigns a value to a variable.

```
dim x as long = 10
x /= 2
```

# <a name="divideandassign"></a>Divide and assign operator (/=)

Divides and assigns a value to a variable.

```
dim x as long = 10
x /= 2
```

# <a name="integerdivideandassign"></a>Integer divide and assign operator (\=)

Integer divides and assigns a value to a variable.

```
dim x as long = 13
x \= 2
```

# <a name="bitwiseandandassign"></a>Bitwise And and assign operator (&=)

Performs a bitwise-and (conjunction) and assigns the result to a variable.

```
dim x as long = 11
x &= 1
```

If the variable is a string, it adds and assigns the value to the string (if the value added is a number, it first converts the number to a string).

```
dim s as string = "ABCDEFG"
s += "HIJK"
```

```
dim s as string = "ABCDEFG"
s += 123456
```

# <a name="bitwiseorandassign"></a>Bitwise Or and assign operator (\!=)

Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable.

```
dim x as long = 1
x != 1
```

# <a name="booleanandandassign"></a>Logical And and assign operator (&&=)

Performs a logical And operation and assigns the result to a variable.

```
dim x as long = 1
x &&= 1
```

The second operand is evaluated only if the first operand evaluates to true (nonzero). This evaluation eliminates needless evaluation of the second operand when the logical And expression is false.

# <a name="booleanorandassign"></a>Logical Or and assign operator (\|\|=)

Performs a logical OR operation and assigns the result to a variable.

```
dim x as long = 1
x ||= 1
```

The logical Or operator (||) returns the boolean value true if either or both operands is true and returns false otherwise. The operands are implicitly converted to type bool prior to evaluation, and the result is of type bool. Logical Or has left-to-right associativity.

The operands to the logical Or operator need not be of the same type, but they must be of integral or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before continuing evaluation of the logical Or expression.

The second operand is evaluated only if the first operand evaluates to false (0). This eliminates needless evaluation of the second operand when the logical Or expression is true.

# <a name="booleanxorandassign"></a>Logical Xor and assign operator (^^=)

Performs a logical XOR operation and assigns the result to a variable.

```
dim x as long = 1
x ^^= 1
```

# <a name="bitwiseandandassign2"></a>Bitwise And and assign operator (and=)

Performs a bitwise-and (conjunction) and assigns the result to a variable.

```
dim x as long = 11
x and= 1
```

# <a name="bitwiseorandassign2"></a>Bitwise Or and assign operator (or=)

Performs a bitwise-or (inclusive disjunction) and assigns the result to a variable.

```
Dim x as long = 1
x or= 1
```

# <a name="bitwisexorandassign2"></a>Bitwise Xor and assign operator (xor=)

Performs a bitwise-xor (inclusive disjunction) and assigns the result to a variable.

```
dim x as long = 1
x xor= 1
```

# <a name="equalto"></a>Operator ==

Compares two expressions for equality.

```
dim x1 as long = 1
dim x2 as long = 1
if x1 == x2 then print "Equal"
```

If the #assign directive is on, `==` must always be used to test equality instead of `=`.

# <a name="notequalto"></a>Operator |=

Compares two expressions for inequality.

```
dim x1 as long = 1
dim x2 as long = 2
if x1 |= x2 yhen print "Not equal"
```

# <a name="notequalto2"></a>Operator <>

Compares two expressions for inequality.

```
dim x1 as long = 1
dim x2 as long = 2
if x1 <> x2 then print "Not equal"
```

# <a name="lessthan"></a>Operator <

Compares an expression less than another expression.

```
dim x1 as long = 1
dim x2 as long = 2
if x1 < x2 then print "Less"
```

# <a name="greaterthan"></a>Operator >

Compares an expression greater than another expression.

```
dim x1 as long = 1
dim x2 as long = 2
if x2 > x1 then print "Greater"
```

# <a name="lessthanorqeualto"></a>Operator <=

Compares an expression less than or equal to another expression.

```
dim x1 as long = 1
dim x2 as long = 2
if x1 < x2 then print "Less or equal"
```

# <a name="greaterthanorqeualto"></a>Operator >=

Compares an expression greater than or equal to another expression.

```
dim x1 as long = 1
dim x2 as long = 2
if x2 < x1 then print "Greater or equal"
```

# <a name="booleanand"></a>Operator &&

Returns the logical and operation of two numeric values.

```
dim x1 as long = 1
dim x2 as long = 2
print x1 && x2
```

The logical And operator (&&) returns the boolean value true if both operands are true and returns false otherwise. The operands are implicitly converted to type bool prior to evaluation, and the result is of type bool. Logical And has left-to-right associativity.

The operands to the logical And operator need not be of the same type, but they must be of integral or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before continuing evaluation of the logical And expression.

# <a name="booleanor"></a>Operator \|\|

Returns the logical Or operation of two numeric values.

```
dim x1 as long = 1
dim x2 as long = 2
print x1 || x2
```

The logical Or operator (\|\|) returns the boolean value true if either or both operands is true and returns false otherwise. The operands are implicitly converted to type bool prior to evaluation, and the result is of type bool. Logical Or has left-to-right associativity.

The operands to the logical Or operator need not be of the same type, but they must be of integral or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before continuing evaluation of the logical Or expression.

The second operand is evaluated only if the first operand evaluates to false (0). This eliminates needless evaluation of the second operand when the logical Or expression is true.

# <a name="bitwiseand"></a>Bitwise And Operator (&)

Performs a bitwise And operation.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 & x2
```

# <a name="bitwisenot"></a>Bitwise Not operator

Returns the bitwise-not (complement) of a numeric value. For a boolean type, `not false` returns true (-1) and `not true` returns false (0).

```
dim n AS byte
n = 15 '00001111
print not n
'Result = -16 =     11110000
```

When used on conditional expressions it inverts the conditional logic.

```
if not a > 42 then ...    'if a <= 42 then ...
```

# <a name="bitwiseor"></a>Bitwise Or operator (\|)

Performs a bitwise Or operation.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 | x2
```

# <a name="bitwisexor"></a>Bitwise Xor operator (^^)

Performs a bitwise Xor operation.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 ^^ x2
```

# <a name="shiftleft"></a>Shift left operator (<<)

Shifts the bits of a numeric expression to the left.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 << x2
```

# <a name="shiftright"></a>Shift right operator (>>)

Shifts the bits of a numeric expression to the right.

```
dim x1 as long = 2
dim x2 as long = 1
print x1 >> x2
```

# <a name="rotateleft"></a>Rotate left operator (<<<)

Shifts all bits one place to the left.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 <<< x2
```

# <a name="rotateright"></a>Rotate right operator (>>>)

Shifts all bits one place to the left.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 >>> x2
```

# <a name="bitwiseand2"></a>Bitwise And operator (and)

Performs a bitwise And operation.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 and x2
```

# <a name="bitwiseor2"></a>Bitwise Or operator (or)

Performs a bitwise Or operation.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 Or x2
```

# <a name="bitwisexor2"></a>Bitwise Xor operator (xor)

Performs a bitwise Xor operation.

```
dim x1 as long = 1
dim x2 as long = 1
print x1 xor x2
```

# <a name="cast"></a>cast

Changes or specifies the type of a variable temporarily, in an expression.

```
float f = 100
print hex( cast(int) f)   ' display the hexadecimal form of float f
print hex( (int) f )      ' the same without using the 'cast' word
```

# <a name="explicitcast"></a>Explicit type conversion operator: ()

Allows explicit type conversion using syntax similar to the function-call syntax.

```
dim d as double = 12345.67
int i = int(d)
print i
' Output: 12345
```

# <a name="castint"></a>Integer cast operator: ?

Casts variables as integers.

```
float f = 100
print hex(?f)   ' display the hexadecimal form of float f
```
