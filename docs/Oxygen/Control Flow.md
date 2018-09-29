# Control Flow

Statements that direct the flow of program execution.

### Transferring Statements

Statements that transfer control to another part of a program.

| Name       | Description |
| ---------- | ----------- |
| [Goto](#goto) | Jumps unconditionally to a specified label in the code. |
| [Gosub](#gosub) | Calls a labelled subroutine. |
| [Ret](#ret) | Returns from a **Gosub**. |
| [Return](#return) | Returns from a procedure. |
| [Exit Sub](#exitsub) | Exits a procedure. |
| [Exit Function](#exitfunction) | Exits a function. |

### Branching Statements

Statements that execute one of a number of code branches.

| Name       | Description |
| ---------- | ----------- |
| [If](#if) | Starts a conditional block with a test. |
| [Then](#then) | Starts the conditional block where the prior test is met. |
| [ElseIf](#elseif) | Makes an alternative test if the previous condition was not met. |
| [Else](#else) | Starts the alternative block where none of the prior conditions are met. |
| [EndIf](#endif) | Ends the conditional block. |
| [Select](#select) | Starts a case block. |
| [Case](#case) | Specifies a case to match followed by actions to perform.  |
| [Case Else](#caseelse) | Matches any case not already matched. |
| [End Select](#endselect) | Ends the select block. |
| [EndSel](#endselect) | Ends the select block. |
| [Switch](#switch) | Starts a C style case block. |

### Looping Statements

Statements that execute code repeatedly.

| Name       | Description |
| ---------- | ----------- |
| [Do](#do) | Starts a block for repetition (looping). |
| [End Do](#enddo) | Ends a **Do** repeating block. |
| [EndDo](#enddo) | Ends a **Do** repeating block. |
| [Loop](#loop) | Ends a **Do** repeating block. |
| [Exit Do](#exitdo) | Exits a **Do** loop immediately. | |
| [Continue Do](#continuedo) | Goes back to the beginning of a **Do** block. |
| [For](#for) | Starts an iteration block. |
| [To](#to) | Specifies the liit of an iteration. |
| [Step](#step) | Specifies the incremente of an iteration. |
| [Next](#next) | Ends an iteration block. |
| [Exit For](#exitfor) | Exits a **For** loop immediately. |
| [Continue For](#continuefor) | Goes back to the beginning of a **For** block. |
| [While](#while) | Starts a block for conditional repetition. |
| [Wend](#wend) | Ends a **While** block. |
| [End While](#endwhile) | Ends a **While** block. |
| [EndWhile](#endwhile) | Ends a **While** block. |
| [Exit While](#exitwhile) | Exits a **While** block immediately. |
| [Continue While](#continuewhile) | Goes back to the beginning of a **While** block. |
| [Repeat](#repeat) | Starts a block for conditional repetition. |
| [Until](#until) | Continue executing a **Repeat** loop until a condition is met. |
| [Redo](#redo) | Starts a block for conditional repetition. |
| [Break](#break) | Exits a **Switch** block, a **Do** block or a **While** block immediately. |
| [Break When](#breakwhen) | Exits a **Switch** block, a **Do** block or a **While** block when a condition is met. |

# <a name="goto"></a>Goto

Jumps unconditionally to a specified label or line number in the code. The label must be local to the **Sub**, **Function** or **Method** where the `Goto` statement is located. `Goto` differs froom `Gosub` in that after execution of a `Goto`, the program retains no memory of where it was before it executed the jump. `Goto` is considered bad programming practice as it can generate unreadable and untraceable code. It is better to use more modern structures such as `Do...Loop`, `For...Next`, `Sub`, and `Function`.

```
IF x = 1 THEN Goto LExit
...
...
...

: LExit
```

```
10  REM Legacy
20  DIM a AS SINGLE, b AS SINGLE, c AS SINGLE, i AS LONG
30  a = 1.0 : b = 1.0 : i = 0
40  c = a + b
60: i = i + 1
70: IF i < 20 THEN a = b : b = c : GOTO 40
80:   
90: PRINT "APPROX FIBONACCI NUMBER: " STR$(c / b)
```

# <a name="gosub"></a>Gosub

Calls a labelled subroutine. Execution jumps to a subroutine marked by a line label. Always use `Ret` to exit a `Gosub`, execution will continue on next statement after `Gosub`. The line label where `Gosub` jumps must be in the same main/function/sub block as `Gosub`. All the variables in the subroutine are shared with the block and no arguments can be used. `Gosub` is considered bad programming practice as it can generate unreadable and untraceable code. It is better to use `Sub` or `Function` instead.

```
SUB Foo

  INT a = 42
  INT b

  GOSUB g
  PRINT b
  RETURN

g:
  b = a / 2
  RET

END SUB
```

# <a name="ret"></a>Ret

Terminates the execution of a subroutine and returns the control to the statement following the calling `Gosub` statement. A `GoSub` should always have a matching `Ret` statement.

# <a name="return"></a>Return

Syntax

```
Return [expression]
```

Exits from a procedure. A `Sub` cannot specify a return return value. In a `Sub`, it is roughly equivalent to `Exit Sub`. In a `Function`, `Return` must specify a return value. `Return`*expression* is roughly equivalent to `Function = expression : Exit Function`.

```
SUB DisplayMessage (s AS STRING)
   IF s = "" THEN RETURN
   PRINT s
END SUB
```

```
FUNCTION Sum (BYVAL x AS LONG, BYVAL z AS LONG) AS LONG
   RETURN x + z
END FUNCTION

print Sum(5, 3)
' Output: 8
```

# <a name="exitsub"></a>Exit Sub

Exits a procedure.

```
SUB DisplayMessage (s AS STRING)
   IF s = "" THEN EXIT SUB
   PRINT s
END SUB
```

# <a name="exitfunction"></a>Exit Function

Exits a function.

```
FUNCTION Div (BYVAL x AS LONG, BYVAL z AS LONG) AS LONG
   IF z = 0 THEN EXIT FUNCTION
   EXIT FUNCTION
   FUNCTION = x + z
END FUNCTION
```

# <a name="if"></a>If

Starts a conditional block with a test.

```
INT a = 1, b = 2
IF a < b THEN a = b
```

# <a name="then"></a>Then

Starts the conditional block where the prior test is met.

```
INT a = 1, b = 2
IF a < b THEN a = b
```

Syntax variations:

```
IF (a > b) {s = "A > B"} ELSEIF (a = b) {s = "A = B"} ELSE {s = "A < B"}
```
```
IF a > b {s = "A > B"} ELSEIF a = b {s = "A = B"} ELSE {s = "A < B"}
```
```
IF a > b {
   s = "A > B"
} ELSEIF a = b {
   s = "A = B"
} ELSE {
   s = "A < B"
}
```

# <a name="elseif"></a>ElseIf

Makes an alternative test if the previous condition was not met.

```
STRING s
INT a = 1, b = 2
IF a > b THEN
   s = "A > B"
ELSEIF a = b THEN
   s = "A = B"
ELSE
   s = "A < B"
END IF
```

Syntax variations:

```
IF (a > b) {s = "A > B"} ELSEIF (a = b) {s = "A = B"} ELSE {s = "A < B"}
```
```
IF a > b {s = "A > B"} ELSEIF a = b {s = "A = B"} ELSE {s = "A < B"}
```
```
IF a > b {
   s = "A > B"
} ELSEIF a = b {
   s = "A = B"
} ELSE {
   s = "A < B"
}
```

# <a name="else"></a>Else

Starts the alternative block where none of the prior conditions are met.

```
STRING s
INT a = 1, b = 2
IF a > b THEN
   s = "A > B"
ELSEIF a = b THEN
   s = "A = B"
ELSE
   s = "A < B"
END IF
```

Syntax variations:

```
IF (a > b) {s = "A > B"} ELSEIF (a = b) {s = "A = B"} ELSE {s = "A < B"}
```
```
IF a > b {s = "A > B"} ELSEIF a = b {s = "A = B"} ELSE {s = "A < B"}
```
```
IF a > b {
   s = "A > B"
} ELSEIF a = b {
   s = "A = B"
} ELSE {
   s = "A < B"
}
```

# <a name="endif"></a>EndIf

Ends the conditional block.

```
STRING s
INT a = 1, b = 2
IF a > b THEN
   s = "A > B"
ELSEIF a = b THEN
   s = "A = B"
ELSE
   s = "A < B"
END IF
```

# <a name="select"></a>Select Case

Starts a case block.

Compact form:

```
DIM a AS LONG, s AS STRING
a = 3
SELECT a   ' SELECT CASE a
  CASE 1 : s = "A = 1"
  CASE 2 : s = "A = 2"
  CASE 3 : s = "A = 3"
  CASE ELSE : s = "A > 3"
END SELECT   'ENDSEL
```

General form:

```
SELECT a
  CASE 1
    s = "A = 1"
  CASE 2
    s = "A = 2"
  CASE 3
    s = "A = 3"
  CASE ELSE
    s = "A > 3"
END SELECT
```

Syntax variations:

```
SELECT a {
  CASE 1
    s = "A = 1"
  CASE 2
    s = "A = 2"
  CASE 3
    s = "A = 3"
  CASE ELSE
    s = "A > 3"
}
```

Extensions:

```
SELECT a
  CASE 1
    s = "A = 1"
  CASE 2
    s = "A = 2"
  CASE 3
    s = "A = 3"
  CASE 4,5,6
    '
  CASE 7 to 9
    '
  CASE 10 to <20
    '
  CASE ELSE
    s = "A > 3"
END SELECT
```

```
SELECT ASC("qwerty", 1)
  CASE "a" TO "p"
    print "a to p"
  CASE "q" TO "z"
    print "q to z"
  CASE ELSE
    print "not lower case"
END SELECT
```

```
SELECT ASC("qwerty", 1)
  CASE 'a' TO 'p'   ' single quote marks
    print "a to p"
  CASE "q" TO "z"
    print "q to z"
  CASE ELSE
    print "not lower case"
END SELECT
```

# <a name="switch"></a>Switch

Starts a C style case block.

```
DIM a AS LONG, s AS STRING
a = 3
switch a {
  case 1
    s = "A = 1"
    break
  case 2
    s = "A = 2"
    break
  case 3
    s = "A = 3"
    break
  case else
    s = "A > 3"
    break
}
```

# <a name="while"></a>While

Starts a block for conditional repetition.

```
DIM a, b AS LONG
a = 4
WHILE b <= a
   b += 1
WEND
```

# <a name="wend"></a>Wend

Ends a `While` block.

```
DIM a, b AS LONG
a = 4
WHILE b <= a
   b += 1
WEND
```

# <a name="endwhile"></a>End While

Ends a `While` block.

```
DIM a, b AS LONG
a = 4
WHILE b <= a
   b += 1
END WHILE   ' or ENDWHILE
```

# <a name="for"></a>For

Starts an iteration block.

#### Syntax

```
For iterator = startvalue To endvalue [ Step stepvalue ]
   [ statement block ]
Next
```

| Parameter  | Description |
| ---------- | ----------- |
| *iterator* | A variable identifier that is used to iterate from an initial value to an end value. |
| *startvalue* | An expression that denotes the starting value of the iterator. |
| *endvalue* | An expression used to compare with the value of the iterator. |
| *stepvalue* | An expression that is added to the iterator after every iteration. |

```
DIM AS LONG i, n
FOR i = 1 TO 10
   n += 1
NEXT
```

```
DIM AS LONG i, n
FOR i = 1 TO 10 STEP 2
   n += 1
NEXT
```

```
DIM AS SINGLE i
FOR i = 3 TO 0 STEP -0.5
   PRINT i
NEXT
```

```
DIM AS LONG i, b
DIM s AS STRING = "QWERTY"
FOR i = 1 TO LEN(s)
   b += ASC(s,i)
NEXT
```

Syntax variations:

```
FOR i = 1 TO LEN(s) STEP 1 {
   a = ASC(s,i)
   b += a
}
```

```
FOR i = 1, LEN(s), 1 {
   a = ASC(s,i)
   b += a
}
```

```
FOR (i = 1, i <= LEN(s), i++) {
   a = ASCI(s,i)
   b += a
}
```

```
#semicolon separator
FOR (i = 1; i <= LEN(s); i++) {
   a = ASC(s,i)
   b += a
}
#semicolon comment
```

```
FOR (i = 1, i <= LEN(s), i++) {
   a = ASC(s,i)
   b += a
}
```

# <a name="to"></a>To

Specifies the limit of an iteration.

```
DIM AS LONG i, n
FOR i = 1 TO 10 STEP 2
   n += 1
NEXT
```

# <a name="step"></a>Step

Specifies the increment of an iteration.

```
DIM AS LONG i, n
FOR i = 1 TO 10 STEP 2
   n += 1
NEXT
```

```
DIM AS SINGLE i
FOR i = 3 TO 0 STEP -0.5
   PRINT i
NEXT
```

# <a name="next"></a>Next

Ends an iteration block.

```
DIM AS LONG i, n
FOR i = 1 TO 10
   n += 1
NEXT
```

# <a name="exitfor"></a>Exit For

Exits a `For` loop immediately.

```
DIM AS LONG i, n
FOR i = 1 TO 10
   n += 1
   IF n = 5 THEN EXIT FOR
NEXT
```

# <a name="do"></a>Do

Starts a block for repetition (looping).

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b > a THEN EXIT DO
END DO   'or ENDDO
```

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b > a THEN EXIT DO
LOOP
```

```
DIM AS LONG a, b
a = 4
DO
   b += 1
LOOP WHILE b < a
```

```
DIM AS LONG a, b
a = 4
DO
   b += 1
LOOP UNTIL b >= a
```

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b >= a THEN BREAK
LOOP
```

# <a name="enddo"></a>EndDo

Ends a `Do` repeating block.

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b > a THEN EXIT DO
END DO   'or ENDDO
```

# <a name="loop"></a>Loop

Ends a `Do` repeating block.

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b > a THEN EXIT DO
LOOP
```

# <a name="exitdo"></a>Exit Do

Exits a `Do` loop immediately.

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b > a THEN EXIT DO
LOOP
```

# <a name="continuedo"></a>Continue Do

Goes back to the beginning of a `Do` block.

```
DIM AS LONG a, b
a = 4
DO
   b += 1
   IF b < a THEN CONTINUE DO
   IF b >= a THEN EXIT DO
LOOP
```

# <a name="continuefor"></a>Continue For

Goes back to the beginning of a `For` block.

```
DIM a, b, i AS LONG
a = 4
FOR i = 1 TO 10
   b += 1
   IF b < a THEN CONTINUE FOR
   IF b >= a THEN EXIT FOR
NEXT
```

# <a name="continuewhile"></a>Continue While

Goes back to the beginning of a `While` block.

```
DIM a, b AS LONG
a = 4
WHILE b < a
   b += 1
   IF b < a THEN CONTINUE WHILE
WEND
```
# <a name="repeat"></a>Repeat

Starts a block for conditional repetition.

```
DIM a, b AS LONG
a = 4
DO
   b += 1
   IF b < a THEN REPEAT DO
   IF b >= a THEN EXIT DO
LOOP
```

```
DIM a, b AS LONG
a = 4
DO
   b += 1
   REPEAT UNTIL b >= a
   IF b >= a THEN EXIT DO
LOOP
```

# <a name="until"></a>Until

Continue executing a `Repeat` loop until a condition is met.

```
DIM a, b AS LONG
a = 4
DO
   b += 1
   REPEAT UNTIL b >= a
   IF b >= a THEN EXIT DO
LOOP
```

# <a name="redo"></a>Redo

Starts a block for conditional repetition.

```
DIM a, b AS LONG
a = 4
DO
   b += 1
   REDO UNTIL b >= a
   IF b >= a THEN EXIT DO
LOOP
```


# <a name="break"></a>Break

Exits a `Switch`, `Do` or `While` blocks.

```
DIM a AS LONG, s AS STRING
a = 3
switch a {
  case 1
    s = "A = 1"
    break
  case 2
    s = "A = 2"
    break
  case 3
    s = "A = 3"
    break
  case else
    s = "A > 3"
    break
}
```

```
DIM a, b AS LONG
a = 4
DO
   b += 1
   IF b >= a THEN BREAK
LOOP
```

```
DIM a, b AS LONG
a = 4
WHILE b <= a
   b += 1
   IF b = a THEN BREAK
END WHILE
```

# <a name="breakwhen"></a>Break When

Exits a `Switch`, `Do` or `While` block when a condition is met.

```
DIM a, b AS LONG
a = 4
WHILE b <= a
   b += 1
   BREAK WHEN b = a
END WHILE
```

```
DIM a, b AS LONG
a = 4
DO
   b += 1
   BREAK WHEN b = a
LOOP
```

```
DIM a, b AS LONG
a = 4
WHILE b <= a
   b += 1
   BREAK WHEN b = a
WEND
```
