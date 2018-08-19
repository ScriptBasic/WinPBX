# CVAR Class

The CVar class implements a VARIANT data type. The variant data type is a tagged union that can be used to represent any other data type. While lacking in efficiency, they are heavily used in COM Automation for its flexibility. The main purpose of the CVar class is to make its use as easy as possible when you need to use them to work with COM Automation objects.

**Include file**: CVAR.INC.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructor) | Initialize the class with the specified value. |
| [Operators](#Operators) | Procedures that perform a certain function with their operands. |
| [Attach](#Attach) | Attaches a variant to the class. |
| [Detach](#Detach) | Detaches the variant data from this class and transfers ownership to the passed variant. |
| [ChangeType](#ChangeType) | Converts the variant from one type to another. |
| [ChangeTypeEx](#ChangeTypeEx) | Converts the variant from one type to another. |
| [DecToCY](#DecToCY) | Converts a CVAR of type decimal to a CY structure. |
| [DecToDouble](#DecToDouble) | Converts a CVAR of type decimal to a double. |
| [FormatNumber](#FormatNumber) | Formats a CVAR containing numbers into a string form. |
| [GetBooleanElem](#GetBooleanElem) | Extracts a single boolean element from a safe array of booleans. |
| [GetDim](#GetDim) | Gets the number of dimensions in the array. |
| [GetDoubleElem](#GetDoubleElem) | Extracts a single DOUBLE element from a safe array of doubles. |
| [GetElementCount](#GetElementCount) | Gets the number of elements in the array. |
| [GetLBound](#GetLBound) | Gets the lower bound for the specified dimension of the safe array. |
| [GetLongElem](#GetLongElem) | Extracts a single LONG element from a safe array of longs. |
| [GetLongIntElem](#GetLongIntElem) | Extracts a single LONGINT element from a safe array of long integers. |
| [GetShortElem](#GetShortElem) | Extracts a single SHORT element from a safe array of shorts. |
| [GetStringElem](#GetStringElem) | Extracts a single BSTR element from a safe array of unicode strings. |
| [GetUBound](#GetUBound) | Gets the upper bound for the specified dimension of the safe array. |
| [GetULongElem](#GetULongElem) | Extracts a single ULONG element from a safe array of unsigned longs. |
| [GetULongIntElem](#GetULongIntElem) | Extracts a single ULONGINT element from a safe array of unsigned long integers. |
| [GetUShortElem](#GetUShortElem) | Extracts a single USHORT element from a safe array of unsigned shorts. |
| [GetVariantElem](#GetVariantElem) | Extracts a single Variant element from a safe array of variants. |
| [PutBooleanArray](#PutBooleanArray) | Initializes CVAR from an array of Boolean values. |
| [Put](#Put) | Assigns values to a CVAR. |
| [Put <numeric value>](#PutNumber) | Assigns numeric values to a CVAR. |
| [PutBuffer](#PutBuffer) | Initializes CVAR with the contents of a buffer. |
| [PutDateString](#PutDateString) | Initializes CVAR VT_DATE from a string. |
| [PutDec](#PutDec) | Initializes CVAR with the contents of a DECIMAL structure. |
| [PutDecFromCY](#PutDecFromCY) | Converts a currency value to a variant of type VT_DECIMAL. |
| [PutDecFromDouble](#PutDecFromDouble) | Converts a double value to a variant of type VT_DECIMAL. |
| [PutDecFromStr](#PutDecFromStr) | Initializes CVAR as VT_DECIMAL from a string. |
| [PutDoubleArray](#PutDoubleArray) | Initializes CVAR from an array of unsigned 64-bit integer values. |
| [PutFileTime](#PutFileTime) | Initializes CVAR with the contents of a FILETIME structure. |
| [PutFileTimeArray](#PutFileTimeArray) | Initializes CVAR with an array of FILETIME structures. |
| [PutGuid](#PutGuid) | Initializes CVAR from a GUID. |
| [PutLongArray](#PutLongArray) | Initializes CVAR from an array of signed 32-bit integer values. |
| [PutLongIntArray](#PutLongIntArray) | Initializes CVAR from an array of signed 64-bit integer values. |
| [PutPropVariant](#PutPropVariant) | Initializes CVAR from the contents of a PROPVARIANT structure. |
| [PutRecord](#PutRecord) | Initializes CVAR with a reference to an UDT. |
| [PutRef](#PutRef) | Assigns a value by reference (a pointer to a variable). |
| [PutResource](#PutResource) | Initializes the CVAR based on a string resource imbedded in an executable file. |
| [PutSafeArray](#PutSafeArray) | Initializes CVAR from a safe array. |
| [PutStringArray](#PutStringArray) | Initializes CVAR from an array of unsigned 64-bit integer values. |
