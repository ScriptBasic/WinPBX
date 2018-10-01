# Oxygen Basic Intrinsic Functions

### String Functions

| Name       | Description |
| ---------- | ----------- |
| [asc](#asc) |  |
| [chr](#chr) |  |
| [frees](#frees) |  |
| [hex](#hex) |  |
| [instr](#instr) |  |
| [lcase](#lcase) |  |
| [left](#left) |  |
| [len](#len) |  |
| [ltrim](#ltrim) |  |
| [mid](#mid) |  |
| [news](#nws) |  |
| [nuls](#nuls) |  |
| [right](#right) |  |
| [rtrim](#rtrim) |  |
| [space](#space) |  |
| [str](#str) |  |
| [ucase](#ucase) |  |
| [unic](#unic) |  |
| [val](#val) |  |
| [wchr](#wchr) |  |

### Math Functions

| Name       | Description |
| ---------- | ----------- |
| [abs](#abs) |  |
| [asin](#asin) |  |
| [atan](#atan) |  |
| [atn](#atn) |  |
| [ceil](#ceil) |  |
| [cos](#cos) |  |
| [deg](#deg) |  |
| [floor](#floor) |  |
| [frac](#frac) |  |
| [hypot](#hypot) |  |
| [log](#log) |  |
| [log2](#log2) |  |
| [log10](#log10) |  |
| [logn](#logn) |  |
| [mod](#mod) |  |
| [pi](#pi) |  |
| [pow](#pow) |  |
| [rad](#rad) |  |
| [recip](#recip) |  |
| [round](#round) |  |
| [sgn](#sgn) |  |
| [sin](#sin) |  |
| [sqr](#sqr) |  |
| [sqrt](#sqrt) |  |
| [tan](#tan) |  |
| [trunc](#trunc) |  |

### Bit Manipulation Functions

| Name       | Description |
| ---------- | ----------- |
| [hibyte](#hibyte) |  |
| [hiword](#hiword) |  |
| [lobyte](#lobyte) |  |
| [loword](#loword) |  |

### Memory Functions

| Name       | Description |
| ---------- | ----------- |
| [copy](#copy) | Copies a block of memory. |
| [copyn](#copy) | Copies a block of memory. |
| [copy0](#copy0) |  |
| [copy00](#copy00) |  |

# <a name="copy"></a>copy / copyn

Copies the values of *NumBytes* from the location pointed to by *SourceAddress* directly to the memory block pointed to by *DestinationAddress*. `copy` and `copyn` are the same.

#### Syntax

```
SUB sub copy (DestinationAddress, SourceAddress, NumBytes)
```

The underlying type of the objects pointed to by both the source and destination pointers are irrelevant for this procedure; the result is a binary copy of the data. This proceudre does not check for any terminating null character in source: it always copies exactly num bytes.

To avoid overflows, the size of the memory blocks pointed to by both the *DestinationAddress* and *SourceAddress* parameters, shall be at least *NumBytes*, and should not overlap.

```
copy &dest, &src, n
copyn &dest, &src, n
```
