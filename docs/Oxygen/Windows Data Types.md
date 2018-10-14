# Windows Data Types

The data types supported by Windows are used to define function return values, function and message parameters, and structure members. They define the size and meaning of these elements. For more information about the underlying C/C++ data types, see Data Type Ranges.

The following table contains the following types: character, integer, Boolean, pointer, and handle. The character, integer, and Boolean types are common to most C compilers. Most of the pointer-type names begin with a prefix of P or LP. Handles refer to a resource that has been loaded into memory.

For more information about handling 64-bit integers, see Large Integers.

| Name       | Description | C++ definition | O2 definition |
| ---------- | ----------- | -------------- | ------------- |
| **APIENTRY** | The calling convention for system functions. | `#define APIENTRY WINAPI` | `#define APIENTRY WINAPI` |
| **ATOM** | An atom. | `typedef WORD ATOM;` | `typedef word ATOM;` |
| **BOOL** | A Boolean variable (should be TRUE or FALSE). | `typedef int BOOL;` | `typedef bool BOOL;` |
| **BOOLEAN** | A Boolean variable (should be TRUE or FALSE). | `typedef BYTE BOOLEAN;` | `typedef boolean BOOLEAN;` |
| **BYTE** | A byte (8 bits). | `typedef unsigned char BYTE;` | `typedef byte BYTE;` |
| **CALLBACK** | The calling convention for callback functions. | `#define CALLBACK __stdcall` | `#define CALLBACK stdcall` |
| **CCHAR** | An 8-bit Windows (ANSI) character. | `typedef char CCHAR;` | `typedef char CCHAR;` |
