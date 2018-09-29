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
| [Break](#break) | Exits a **Switch** block or **Do**/**While** block. |

### Looping Statements

Statements that execute code repeatedly.

| Name       | Description |
| ---------- | ----------- |
| [While](#while) | Starts a block for conditional repetition. |
| [Wend](#wend) | Ends a **While** block. |
| [End While](#endwhile) | Ends a **While** block. |
| [EndWhile](#endwhile) | Ends a **While** block. |
| [For](#for) | Starts an iteration block. |
| [Step](#step) | Specifies the incremente of an iteration. |
| [Next](#next) | Ends an iteration block. |
| [Do](#do) | Starts a block for repetition (looping). |
| [End Do](#enddo) | Ends a **Do** repeating block. |
| [EndDo](#enddo) | Ends a **Do** repeating block. |
| [Loop](#loop) | Ends a **Do** repeating block. |
| [Continue](#continue) | Go back to the beginning of a **Do**, **While** or **For** block. |
| [Continue Do](#continuedo) | Go back to the beginning of a **Do** block. |
| [Continue For](#continuefor) | Go back to the beginning of a **For** block. |
| [Continue While](#continuewhile) | Go back to the beginning of a **While** block. | |
| [Repeat](#repeat) | Starts a block for conditional repetition. |
| [Redo](#redo) | Starts a block for conditional repetition. |
| [Until](#until) | Continue executing a **Repeat** loop until a condition is met. |
| [Break](#break) | Exit a switch block, a **Do** block or a **While** block immediately. |
| [Break When](#breakwhen) | Exit a switch block, a **Do** block or a **While** block when a condition is met. |
| [Exit While](#exitwhile) | Exit a **While** block immediately. |
| [Exit For](#exitfor) | Exit a **For** loop immediately. |
| [Exit Do](#exitdo) | Exit a **Do** loop immediately. | |

# <a name="goto"></a>Goto

Jumps unconditionally to a specified label in the code. The label must be local to the **Sub**, **Function** or **Method** where the `Goto` statement is located. `Goto` differs froom `Gosub` in that after execution of a `Goto`, the program retains no memory of where it was before it executed the jump. `Goto` is considered bad programming practice as it can generate unreadable and untraceable code. It is better to use more modern structures such as `Do...Loop`, `For...Next`, `Sub`, and `Function`.

```
IF x = 1 THEN Goto LExit
...
...
...

: LExit
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

# <a name="beak"></a>Break

Exits a **Switch** block or **Do**/**While** blocks.

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
