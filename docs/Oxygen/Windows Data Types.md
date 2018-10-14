# Windows Data Types

The data types supported by Windows are used to define function return values, function and message parameters, and structure members. They define the size and meaning of these elements. For more information about the underlying C/C++ data types, see Data Type Ranges.

The following table contains the following types: character, integer, Boolean, pointer, and handle. The character, integer, and Boolean types are common to most C compilers. Most of the pointer-type names begin with a prefix of P or LP. Handles refer to a resource that has been loaded into memory.

For more information about handling 64-bit integers, see Large Integers.

| Name       | Description |
| ---------- | ----------- |
| **APIENTRY** | The calling convention for system functions.<br>`#define APIENTRY WINAPI`. O2 definition: `#define APIENTRY WINAPI` |
| **ATOM** | An atom. <br>`typedef WORD ATOM;`. O2 definition: `typedef word ATOM;` |
| **BOOL** | A Boolean variable (should be TRUE or FALSE).<br>`typedef int BOOL;`. O2 definition: `typedef bool BOOL;` |
| **BOOLEAN** | A Boolean variable (should be TRUE or FALSE).<br>`typedef BYTE BOOLEAN;`. O2 definition: `typedef boolean BOOLEAN;` |
| **BYTE** | A byte (8 bits).<br>`typedef unsigned char BYTE;`. O2 definition: `typedef byte BYTE;` |
| **CALLBACK** | The calling convention for callback functions.<br>`#define CALLBACK __stdcall`. O2 definition: `#define CALLBACK stdcall` |
| **CCHAR** | An 8-bit Windows (ANSI) character.<br>`typedef char CCHAR;`. O2 definition: `typedef char CCHAR;` |
| **CHAR** | An 8-bit Windows (ANSI) character.<br>`typedef char CHAR;`. O2 definition: `typedef char CHAR;` |
| **COLORREF** | The red, green, blue (RGB) color value (32 bits).<br>`typedef DWORD COLORREF;`. O2 definition: `typedef dword COLORREF;` |
| **CONST** | A variable whose value is to remain constant during execution.<br>`#define CONST const`. O2 definition: N/A |
| **DWORD** | 	A 32-bit unsigned integer. The range is 0 through 4294967295 decimal.<br>`typedef unsigned long DWORD;`. O2 definition: `typedef dword DWORD;` |
| **DWORDLONG** | 	A 64-bit unsigned integer. The range is 0 through 18446744073709551615 decimal.<br>`typedef unsigned __int64 DWORDLONG;`. O2 definition: `typedef unsigned __int64 DWORDLONG;` |
| **DWORD_PTR** | An unsigned long type for pointer precision. Use when casting a pointer to a long type to perform pointer arithmetic. (Also commonly used for general 32-bit parameters that have been extended to 64 bits in 64-bit Windows.)<br>`typedef ULONG_PTR DWORD_PTR;`. O2 definition: `typedef ULONG_PTR DWORD_PTR;` |
| **DWORD32** | A 32-bit unsigned integer.<br>`typedef unsigned int DWORD32;`. O2 definition: `typedef dword DWORD32;` |
| **DWORD64** | A 64-bit unsigned integer.<br>`typedef unsigned __int64 DWORD64;`. O2 definition: `typedef unsigned __int64 DWORD64;` |
| **FLOAT** | A floating-point variable.<br>`typedef float FLOAT;`. O2 definition: `typedef float FLOAT;` |
| **HACCEL** | A handle to an accelerator table.<br>`typedef HANDLE HACCEL;`. O2 definition: `typedef HANDLE HACCEL;` |
