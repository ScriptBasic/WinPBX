# Variables, Arrays and User Defined Types

* `Variables` represent numeric or string values. The value of a variable can change during program execution. 
* `Constants` are numbers or strings which cannot be changed after they are defined.
* `Equates` are constants prefixed by the symbols `$` (string equates) or `%` (numeric equates).
* `Enums` are groups of logically related numeric equates.
* `User defined types` (UDTs) are custom data types containing one or more data fields.
* `Unions` are similar to a user defined types, except that the elements of a union occupy the same space in memory.
* `Arrays` are groups of data sharing the same variable name. The individual values that make up an array are called elements.


#### Variable Scope

* `Global` variables are accessible from anywhere in your program. They are initialized when your program starts and are destroyed when the program ends.
* `Local` variables are only accessible within a single procedure or method. They are automatically created and initialized each time you enter the procedure. They are automatically destroyed when you exit the procedure. This is the default variable scope unless you declare otherwise.
* `Static` variables are only accessible within a single proceudre or method. They are initialized when your program starts, but retain their value regardless of how many times the procedure is entered and exited. They are destroyed only when the program ends.

### Variables

| Name       | Description |
| ---------- | ----------- |
| [Dim](#dim) | Declares variables, arrays, objects and user defined types. |
| [ReDim](#redim) | Creates or resizes a dynamic array, preserving contents within range.  |
| [As](#as) | Part of a declaration which specifies a data type. |
| [Let](#let) | Similar to **Dim**, but the type is inferred from the assigned value. |
| [Var](#var) | Defines a set of variables. |
| [Const](#const) | Constant. Non-modifiable variable declaration. |
| [$](#equate1) | Defines an equate (which can be used as constant). |
| [%](#equate2) | Defines an equate (which can be used as constant). |
| [Enum](#enum) | Declares an enumerated type. |
| [Type](#type) | Define a compound variable type. |
| [Union](#union) | Define a union. |

### Modifiers

| Name       | Description |
| ---------- | ----------- |
| [Global](#global) | Declare global (shared) variables between Subs, Functions and Methods. |
| [Local](#local) | Declare local variables inside a Sub, Function or Method. |
| [Static](#static) | Declare static variables inside a Sub, Function or Method. |

### Scope

| Name       | Description |
| ---------- | ----------- |
| [Block](#block) | Starts a block. |
| [Scope](#scope) | Creates a block where variables and functions may be locally defined.  |
