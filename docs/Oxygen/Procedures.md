# Oxygen Basic Procedures

### Declaration

| Name       | Description |
| ---------- | ----------- |
| [!](#declare1) | Declares a procedure. |
| [declare](#declare2) | Declares a procedure. |
| [function](#function) | Defines a procedure that returns a value.  |
| [sub](#sub) | Defines a procedure that does not return a value. |

### Calling Conventions

| Name       | Description |
| ---------- | ----------- |
| [stdcall](#stdcall) | Specifies a stdcall-style calling convention in a procedure declaration. |
| [cdecl](#cdecl) | Specifies a cdecl-style calling convention in a procedure declaration. |
| [ms64](#ms64) | Microsoft x64 calling convention. |
| [pascal](#pascal) | Specifies a Pascal-style calling convention in a procedure declaration. |

### Parameter Passing Conventions

| Name       | Description |
| ---------- | ----------- |
| [any](#any) | Specifies a parameter of uncertain type, nominally a signed integer of system width (32/64 bits wide). |
| [byref](#byref) | Declaration specifier to explicitly pass a parameter by reference. |
| [byval](#byval) | Declaration specifier to explicitly pass a parameter by value. |
| [void](#void) | Specifies a null type. |

### Linkage

| Name       | Description |
| ---------- | ----------- |
| [alias](#alias) | Clause of the Sub and Function statements that provides an alternate internal name. |
| [bind](#bind) | Binds a list of procedures from a Dynamic Link Library (DLL).  |
| [export](#export) | Declaration specifier to indicate that a procedure in a DLL should be visible from other programs.  |
| [extern](#extern) | Associates declared procedures with a calling convention and/or DLL name.  |
| [external](#external) | Attribute that specifies that a procedure can be called from procedures external to Oxygen Basic. |
| [lib](#lib) | Specifies the library where a sub or function can be found as part of a declaration. |
| [library](#library) | Specifies the name of a DLL library to associate with a set of procedure declarations.  |

# <a name="stdcall"></a>stdcall

Specifies a stdcall-style calling convention in a procedure declaration. This is the default calling convention on 32bit Windows platforms.

In the stdcall calling convention, any parameters are to be passed (pushed onto the stack) from right to left. Registers EAX, ECX, and EDX are designated for use within the function and dont need to be preserved. The procedure must clean up the stack (pop any parameters) before it returns.

#### Syntax

```
declare sub procedurename [alias "aliasname"] [lib "libname"] stdcall ( parameters )
```
```
declare sub Sleep alias "Sleep" lib "kernel32.dll" stdcall (byval msec as int)
! Sleep lib "kernel32.dll" stdcall (int msec)
```

# <a name="any"></a>any

Specifies a parameter of uncertain type, nominally a signed integer of system width (32/64 bits wide).

Using `any` disables type checking for a particular parameter, and passes the address of the variable on the stack. 

```
function f(any*a) {...}
```

Parameter of any type may be passed by-reference. Like C **void***.

# <a name="byref"></a>byref

Declaration specifier to explicitly pass a parameter by reference. When parameters are passed by reference, the address of the variable passed to the routine is placed on the stack and its content can be changed by the procedure.

When a constant or a literal expression are passed by reference to a procedure, the compiler passed a temporary variable initialized with the constant or the literal expression.

```
function foo (byref v as long) as long
'equivalent in C notation:
long foo (long * v)
```

```
sub  foo (byref v as long)
    v = v + 1
end sub

dim v as long = 1
Foo v
print v   ' Output: 2
```

# <a name="byval"></a>byval

Declaration specifier to explicitly pass a parameter by value. When parameters are passed by value, a copy of the actual data is placed on the stack. Any changes done to the copy don't alter the content of the passed variable.

```
function foo (byval v as long) as long
'equivalent in C notation:
long foo (long v)
```

```
sub  foo (byval v as long)
    v = v + 1
end sub

dim v as long = 1
Foo v
print v   ' Output: 1
```

`byval`is good for small objects, like numeric types, and avoids the overhead of the pointer used by `byref` (that has to be deferenced at each access to the object) since the data is retrieved from the stack. `byref` is better for passing strings or big UDTs that should not be copied.

# <a name="void"></a>void

Specifies a null type.

In function headers:

```
function foo (byref v as void) as void ptr
void* foo(void*v)
```

Procedures not returning a value:
```
void foo()
```
