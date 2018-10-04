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
| [ms64](#ms64) | Specifies the Microsoft x64 calling convention. |
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

In the `stdcall` calling convention, any parameters are to be passed (pushed onto the stack) from right to left. Registers EAX, ECX, and EDX are designated for use within the function and dont need to be preserved. The procedure must clean up the stack (pop any parameters) before it returns.

#### Syntax

```
declare sub procedurename [alias "aliasname"] [lib "libname"] stdcall ( parameters )
declare function functionname [alias "aliasname"] [lib "libname"] stdcall ( parameters ) as return_type
```
```
declare sub Sleep alias "Sleep" lib "kernel32.dll" stdcall (byval msec as int)
--or--
! Sleep lib "kernel32.dll" stdcall (int msec)
```

# <a name="cdecl"></a>cdecl

Specifies a cdecl-style calling convention in a procedure declaration.

The `cdecl` (which stands for C declaration) is a calling convention that originates from the C programming language and is used by many C compilers for the x86 architecture. In `cdecl`, subroutine arguments are passed on the stack. Integer values and memory addresses are returned in the EAX register, floating point values in the ST0 x87 register. Registers EAX, ECX, and EDX are caller-saved, and the rest are callee-saved. The x87 floating point registers ST0 to ST7 must be empty (popped or freed) when calling a new function, and ST1 to ST7 must be empty on exiting a function. ST0 must also be empty when not used for returning a value. In the context of the C programming language, function arguments are pushed on the stack in the right-to-left order, i.e. the last argument is pushed first. The caller cleans the stack after the function call returns.

#### Syntax

```
declare sub procedurename [alias "aliasname"] [lib "libname"] cdecl ( parameters )
declare function functionname [alias "aliasname"] [lib "libname"] cdecl ( parameters ) as return_type
```

```
declare function strcpy alias "strcpy" lib "msvcrt.dll" cdecl (byval dest as zstring ptr, byval src as zstring ptr) as zstring ptr
--or--
! strcpy lib "kernel32.dll" cdecl (dest as zstring ptr, src as zstring ptr) as zstring ptr
```

# <a name="ms64"></a>ms64

Specifies the Microsoft x64 calling convention.

The Microsoft x64 calling convention is followed on Windows and pre-boot UEFI (for long mode on x86-64). It uses registers RCX, RDX, R8, R9 for the first four integer or pointer arguments (in that order), and XMM0, XMM1, XMM2, XMM3 are used for floating point arguments. Additional arguments are pushed onto the stack (right to left). Integer return values (similar to x86) are returned in RAX if 64 bits or less. Floating point return values are returned in XMM0. Parameters less than 64 bits long are not zero extended; the high bits are not zeroed.

When compiling for the x64 architecture in a Windows context (whether using Microsoft or non-Microsoft tools), there is only one calling convention – the one described here, so that stdcall, thiscall, cdecl, fastcall, etc., are now all one and the same.

In the Microsoft x64 calling convention, it is the caller's responsibility to allocate 32 bytes of "shadow space" on the stack right before calling the function (regardless of the actual number of parameters used), and to pop the stack after the call. The shadow space is used to spill RCX, RDX, R8, and R9, but must be made available to all functions, even those with fewer than four parameters.

The registers RAX, RCX, RDX, R8, R9, R10, R11 are considered volatile (caller-saved).

The registers RBX, RBP, RDI, RSI, RSP, R12, R13, R14, and R15 are considered nonvolatile (callee-saved).

For example, a function taking 5 integer arguments will take the first to fourth in registers, and the fifth will be pushed on the top of the shadow space. So when the called function is entered, the stack will be composed of (in ascending order) the return address, followed by the shadow space (32 bytes) followed by the fifth parameter.

In x86-64, Visual Studio 2008 stores floating point numbers in XMM6 and XMM7 (as well as XMM8 through XMM15); consequently, for x86-64, user-written assembly language routines must preserve XMM6 and XMM7 (as compared to x86 wherein user-written assembly language routines did not need to preserve XMM6 and XMM7). In other words, user-written assembly language routines must be updated to save/restore XMM6 and XMM7 before/after the function when being ported from x86 to x86-64.

# <a name="pascal"></a>pascal

Specifies the Pascal-calling convention.

Based on the Borland Pascal programming language's calling convention, the parameters are pushed on the stack in left-to-right order (opposite of cdecl), and the callee is responsible for removing them from the stack.

Returning the result works as follows:

* Ordinal values are returned in AL (8-bit values), AX (16-bit values), EAX (32-bit values), or DX:AX (32-bit values on 16-bit systems).
* Real values are returned in DX:BX:AX.
* Floating point (8087) values are returned in ST0.
* Pointers are returned in EAX on 32-bit systems and in AX in 16-bit systems.
* Strings are returned in a temporary location pointed by the @Result symbol.

This calling convention was common in the following 16-bit APIs: OS/2 1.x, Microsoft Windows 3.x, and Borland Delphi version 1.x. Modern versions of the Windows API use `stdcall`, which still has the callee restoring the stack as in the Pascal convention, but the parameters are now pushed right to left.

# <a name="any"></a>any

Specifies a parameter of uncertain type, nominally a signed integer of system width (32/64 bits wide).

Using `any` disables type checking for a particular parameter, and passes the address of the variable on the stack. 

```
function f(any*a) {...}
```

```
declare sub procedurename [alias "aliasname"] [lib "libname"] cdecl ( parameters )
```
```
declare sub Sleep alias "Sleep" lib "kernel32.dll" stdcall (byval msec as int)
! Sleep lib "kernel32.dll" stdcall (int msec)
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
