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
| [alias](#alias) | Clause of the `Sub` and `Function` statements that provides an alternate internal name. |
| [bind](#bind) | Binds a list of procedures from a Dynamic Link Library (DLL).  |
| [export](#export) | Declaration specifier to indicate that a procedure in a DLL should be visible from other programs.  |
| [extern](#extern) | Associates declared procedures with a calling convention and/or DLL name.  |
| [external](#external) | Attribute that specifies that a procedure can be called from procedures external to Oxygen Basic. |
| [lib](#lib) | Declaration specifier to indicate where a sub or function can be found. |
| [library](#library) | Specifies the name of a DLL library to associate with a set of procedure declarations. |

# <a name="declare1"></a>!

Declares a procedure with or without its prototype (may be external or declared in advance).

External, with prototype:

```
extern lib "user32.dll"
! MessageBox "MessageBoxA"(sys hWnd, char* lpText, char* lpCaption, dword uType) as int
end extern
MessageBox 0,"Hello World", "declare",0
```

External, without prototype (it may be added later):

```
extern lib "user32.dll"
! MessageBox "MessageBoxA"
end extern
declare MessageBox(sys hWnd, char* lpText, char* lpCaption, dword uType) as int at @MessageBox
MessageBox 0,"Hello World", "declare",0
```

Forward declaration:

```
! fun (float a,b,c,d) as float
' or: ! function fun (float a, b, c, d) as float

print fun(1, 2, 3, 4)

function fun (float a, b, c, d) as float
   function = a + b + c + d
end function
```

# <a name="function"></a>function

Defines a procedure that returns a value.

#### Syntax

```
function functionname [alias external_identifier] [cdecl|pascal|stdcall] [([parameter_list])] as return_type
   [statements]
   [Return return_value]
   [Function = return_value]
   [functionname = return_value]
end function
```

| Name       | Description |
| ---------- | ----------- |
| *functionname* | The name of the function. |
| *external_identifier* | Externally visible (to the linker) name enclosed in quotes. |
| *parameter_list* | List of parameters. |
| *parameter* | \[byref\|byval] identifier \[as type] \[= default_value]. |
| *type* | The type of variable. |
| *default_value* | The value of the argument if none is specified in the call. |
| *return_type* | The type of variable returned by the function. |
| *statements* | One or more statements that make up the function body. |
| *return_value* | The value returned by the function. |

```
function triple(byval i as int) as int
   return i*3
end function
```
```
function triple(i as int) as int
   return i*3
end function
```
```
function cube(f as float) as float
  function = f*f*f
end function
```
```
function cube(f as float) as float {return f*f*f}
```
```
function cube(f as float) as float {
  return f*f*f
}
```
```
float cube(f as float) {
  return f*f*f
}
```
```
float cube(float f) {
  return f*f*f
}
```

Passing an array by reference:

```
dim as float f() = {1,2,3,4,5}

function cubes(byref f as float, byval n as int)
  indexbase 1
  int i
  float v
  for i = 1 to n
    v = f[i]
    print v*v*v
  next
end function

function cubes(float *f, int n)
  indexbase 1
  int i
  float v
  for i = 1 to n
    v = f[i]
    print v*v*v
  next
end function

cubes f(2),3
cubes f, countof(f)
```

With optional parameter:

```
dim as float f() = {1,2,3,4,5}

function cubes(byref f as float, optional byval n as int)
  if n = 0 then n = 1
  indexbase 1
  int i
  float v
  for i = 1 to n
    v = f[i]
    print v*v*v
  next
end function

cubes f(3)
cubes f(3),1
cubes float{1,2,3,4}, countof  ' passing literal data set
```

With default value:

```
dim as float f() = {1,2,3,4,5}

function cubes(float *f, int n = 2)
  indexbase 1
  int i
  float v
  for i = 1 to n
    v = f[i]
    print v*v*v
  next
end function

cubes f(3)
cubes f(3),2
```

With ellipsis:

```
function cubes(int n, ...)
  indexbase 0
  int i
  float v
  for i = 1 to n
    v = (int) param[i]
    print v*v*v
  next
end function

cubes 3, 2,3,4
```

# <a name="sub"></a>sub

Defines a procedure that does not returns a value.

#### Syntax

```
sub subname [alias external_identifier] [cdecl|pascal|stdcall] [([parameter_list])]
   [statements]
   [Return]
end sub
```

| Name       | Description |
| ---------- | ----------- |
| *functionname* | The name of the function. |
| *external_identifier* | Externally visible (to the linker) name enclosed in quotes. |
| *parameter_list* | List of parameters. |
| *parameter* | \[byref\|byval] identifier \[as type] \[= default_value]. |
| *type* | The type of variable. |
| *default_value* | The value of the argument if none is specified in the call. |
| *statements* | One or more statements that make up the function body. |

As a `sub`can't return a value, we need to pass a variable by reference to receive the result.

```
sub cube (byval f as float, byref g as float)
  g = f*f*f
end sub

dim float a
cube 2, a
print a
```

When calling a subroutine, parentheses after the subroutine name (surrounding the argument list if any) are optional.

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

Parameters of any type may be passed by-reference. Like C **void***.

# <a name="bind"></a>bind

Binds a list of procedures from a Dynamic Link Library (DLL).

Used for low level (without protoype) calls to DLL functions. The first name is the one used in the program. The second is the name used in the DLL. A prototype may be attached to any of these keywords later.

```
sys kernel32=LoadLibrary `kernel32.dll`
sys user32=LoadLibrary `user32.dll`
sys GDI32=LoadLibrary `GDI32.dll`

bind kernel32
  (
    GetCommandLine  GetCommandLineA   ; @0
    GetModuleHandle GetModuleHandleA  ; @4
    ExitProcess     ExitProcess       ; @4
  )

bind user32
  (
    LoadIcon         LoadIconA         ; @8
    LoadCursor       LoadCursorA       ; @8
    RegisterClass    RegisterClassA    ; @4
    MessageBox       MessageBoxA       ; @4
    CreateWindowEx   CreateWindowExA   ; @48
    ShowWindow       ShowWindow        ; @8
    UpdateWindow     UpdateWindow      ; @4
    GetMessage       GetMessageA       ; @16
    TranslateMessage TranslateMessage  ; @4
    DispatchMessage  DispatchMessageA  ; @4
    PostQuitMessage  PostQuitMessage   ; @4
    BeginPaint       BeginPaint        ; @8
    EndPaint         EndPaint          ; @8
    GetClientRect    GetClientRect     ; @8  
    DrawText         DrawTextA         ; @20
    PostMessage      PostMessageA      ; @16
    DefWindowProc    DefWindowProcA    ; @16
  )

bind GDI32
  (
    GetStockObject   GetStockObject    ; @4
  )

' Attach a function prototype to the address of MessageBox.
declare MessageBox(sys hWnd, char* lpText, char* lpCaption,   
   dword uType) as int at @MessageBox

' Call the function.
MessageBox 0,"Hello World", "binding",0
```

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

# <a name="alias"></a>alias

Clause of the `Sub` and `Function` statements that provides an alternate internal name.

#### Syntax

```
[Declare] { sub | function } usablename alias "alternatename" (...)
```

An `alias` clause may be used to give an alternate name for imported or exported procedures. This alternate name cannot be used within the program to call the procedure, but it is visible to the linker when linking with code written in other languages. The alias name must be specified by a string literal which provides the name and capitalization of the procedure in the external DLL.

`Alias` is commonly used for procedures in libraries written in other languages when such procedure names contain characters that are invalid in Basic.

```
Declare sub LegalName alias "Illegal$Name""
```

# <a name="export"></a>export

Declaration specifier to indicate that a procedure in a DLL should be visible from other programs.

If a function is declared with this clause in a DLL, it is added to the public export table, so external programs can dynamically link to it using `GetProcAddress`. If a procedure is not marked with `export`, it is hidden from the outside.

```
function HelloA (string s) as string, export
 return "HelloA "+s
end function

function HelloW (wstring s) as wstring, export
 return "HelloW "+s
end function
```

# <a name="extern"></a>extern

Aassociates declared procedures with a calling convention and/or DLL name.

```
extern stdcall lib "kernel32.dll"
  declare function QueryPerformanceCounter(lpPerformanceCount as quad) as sys
  declare function QueryPerformanceFrequency(lpPerformanceFrequency as quad) as sys
end extern
```

# <a name="external"></a>external
 
Functions with the `external` attribute expect to be called from procedures external to Oxygen Basic. Additional register management is
enlisted to support external calls.

```
function fs (single a, single b) as single external
   function = a + b
end function
```

# <a name="lib"></a>lib

Declaration specifier to indicate where a sub or function can be found.

```
declare sub procedurename [alias "aliasname"] [lib "libname"] stdcall ( parameters )
declare function functionname [alias "aliasname"] [lib "libname"] stdcall ( parameters ) as return_type
```
```
declare sub Sleep alias "Sleep" lib "kernel32.dll" stdcall (byval msec as int)
--or--
! Sleep lib "kernel32.dll" stdcall (int msec)
```

`lib` may be specified in the `declare` statement or it may be specified in an `extern` statement, referring to an entire group
of declarations.

```
extern stdcall lib "kernel32.dll"
  declare function QueryPerformanceCounter(lpPerformanceCount as quad) as sys
  declare function QueryPerformanceFrequency(lpPerformanceFrequency as quad) as sys
end extern
```

# <a name="library"></a>library

Specifies the name of a DLL library to associate with a set of procedure declarations.

```
extern stdcall library "kernel32.dll"   ' or: extern stdcall lib "kernel32.dll"
  declare function QueryPerformanceCounter(lpPerformanceCount as quad) as sys
  declare function QueryPerformanceFrequency(lpPerformanceFrequency as quad) as sys
end extern
```
