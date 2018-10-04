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

# <a name="any"></a>any

Specifies a parameter of uncertain type, nominally a signed integer of system width (32/64 bits wide).

```
function f(any*a) {...}
```

Parameter of any type may be passed by-reference. Like C **void***.


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
