# Control Flow

Statements that direct the flow of program execution.

### Transferring Statements

Statements that transfer control to another part of a program.

| Name       | Description |
| ---------- | ----------- |
| [Goto](#goto) | Jumps unconditionally to a specified label in the code. |
| [Gosub](#gosub) | Calls a labelled subroutine. |
| [Return](#return) | Returns from a procedure or **Gosub** |
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
| [Select](#select) | Starts a Case block. |
| [Case](#case) | Specifies a case to match followed by actions to perform.  |
| [Case Else](#caseelse) | Matches any case not already matched. |
| [Break](#break) | Exit a switch block or do/while block. |
| [End Select](#endselect) | Ends the select block. |
| [EndSel](#endselect) | Ends the select block. |

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

Jumps unconditionally to a specified label in the code. The label must e local to the Sub, Function or Method where the `Goto` statement is located. `Goto` differs froom Gosub in that after execution of a `Goto`, the program retains no memory of where it was before it executed the jump.

For better source code readability, overuse of `Goto` should be avoided in favor of more modern structures such as `Do...Loop`, `For...Next`, `Sub`, and `Function`.

```
IF x = 1 THEN Goto LExit
...
...
...

: Lexit
```
