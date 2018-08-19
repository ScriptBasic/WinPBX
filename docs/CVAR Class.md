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
| [PutShortArray](#PutShortArray) | Initializes CVAR from an array of signed 16-bit integer values. |
| [PutStrRet](#PutStrRet) | Initializes CVAR with string stored in a STRRET structure. |
| [PutSystemTime](#PutSystemTime) | Initializes CVAR with the contents of a SYSTEMTIME structure. |
| [PutULongArray](#PutULongArray) | Initializes CVAR from an array of 32-bit unsigned integer values. |
| [PutULongInt](#PutULongInt) | Initialies a CVAR from am ULONGINT. |
| [PutULongArray](#PutULongArray) | Initializes CVAR from an array of unsigned 64-bit integer values. |
| [PutUshortArray](#PutUshortArray) | Initializes CVAR from an array of 16-bit integer values. |
| [PutUtf8](#PutUtf8) | Initializes CVAR with the contents of an UTF-8 string. |
| [PutVariantArrayElem](#PutVariantArrayElem) | Initializes CVAR with a value stored in another VARIANT structure. |
| [PutVbDate](#PutVbDate) | Initializes CVAR with the contents of a DATE value. |
| [Round](#Round) | Rounds a variant to the specified number of decimal places. |
| [ToBooleanArray](#ToBooleanArray) | Extracts an array of boolean values from CVAR. |
| [ToBooleanArrayAlloc](#ToBooleanArrayAlloc) | Extracts an array of boolean values from CVAR. |
| [ToBstr](#ToBstr) | Extracts the content of the underlying variant and returns it as a CBSTR. Same as bstr. |
| [ToBuffer](#ToBuffer) | Extracts the contents of a CVAR of type VT_ARRRAY OR VT_UI1 to a buffer. |
| [ToDosDateTime](#ToDosDateTime) | Extracts a date and time value in Microsoft MS-DOS format from a CVAR of type VT_DATE. |
| [ToDoubleArray](#ToDoubleArray) | Extracts an array of DOUBLE values from CVAR. |
| [ToDoubleArrayAlloc](#ToDoubleArrayAlloc) | Extracts an array of DOUBLE values from CVAR. |
| [ToFileTime](#ToFileTime) | Returns the contents of a CVAR of type VT_DATE as a FILETIME structure. |
| [ToGuid](#ToGuid) | Returns the contents of a CVAR containing a GUID string as a GUID structure. |
| [ToGuidBStr](#ToGuidBStr) | Returns the contents of a CVAR containing a GUID string as an unicode GUID string. Same as ToGuidWstr. |
| [ToGuidStr](#ToGuidStr) | Returns the contents of a CVAR containing a GUID string as an unicode GUID string. Same as ToGuidWstr. |
| [ToGuidWStr](#ToGuidWStr) | Returns the contents of a CVAR containing a GUID string as an unicode GUID string. Same as ToGuidStr. |
| [ToLongArray](#ToLongArray) | Extracts an array of LONG values from CVAR. |
| [ToLongArrayAlloc](#ToLongArrayAlloc) | Extracts an array of LONG values from CVAR. |
| [ToLongIntArray](#ToLongIntArray) | Extracts an array of LONGINT values from CVAR. |
| [ToLongIntArrayAlloc](#ToLongIntArrayAlloc) | Extracts an array of LONGINT values from CVAR. |
| [ToShortArray](#ToShortArray) | Extracts an array of Int16 values from CVAR. |
| [ToShortArrayAlloc](#ToShortArrayAlloc) | Extracts an array of SHORT values from CVAR. |
| [ToStr](#ToStr) | Extracts the content of the underlying variant and returns it as a CWSTR. Same as wstr and ToWStr. |
| [ToStringArray](#ToStringArray) | Extracts data from a vector structure into a PWSTR array. |
| [ToStringArrayAlloc](#ToStringArrayAlloc) | Extracts an array of PWSTR values from CVAR. |
| [ToStrRet](#ToStrRet) | Returns the contents of a CVAR of type VT_BSTR to a STRRET stucture. |
| [ToSystemTime](#ToSystemTime) | Returns the contents of CVAR of type VT_DATE as a FILETIME structure. |
| [ToULongArray](#ToULongArray) | Extracts an array of ULONG values from CVAR. |
| [ToULongArrayAlloc](#ToULongArrayAlloc) | Extracts an array of ULONG values from CVAR. |
| [ToULongIntArray](#ToULongIntArray) | Extracts an array of ULONGINT values from CVAR. |
| [ToULongIntArrayAlloc](#ToULongIntArrayAlloc) | Extracts an array of ULONGINT values from CVAR. |
| [ToUShortArray](#ToUShortArray) | Extracts an array of USHORT values from CVAR. |
| [ToUShortArrayAlloc](#ToUShortArrayAlloc) | Extracts an array of USHORT values from CVAR. |
| [ToUtf8](#ToUtf8) | Returns the contents of a CVAR containing a BSTR as an UTF-8 encoded string. |
| [ToVbDate](#ToVbDate) | Returns the contents of a CVAR of type VT_DATE as a DATE value. |
| [ToWStr](#ToWStr) | Extracts the content of the underlying variant and returns it as a CWSTR. Same as wstr and ToStr. |
| [ValDouble](#ValDouble) | Converts the variant to a floating point number (DOUBLE). |
| [ValInt](#ValInt) | Converts the variant to a signed 32-bit integer (LONG). |
| [ValLong](#ValLong) | Converts the variant to a signed 32-bit integer (LONG). |
| [ValLongInt](#ValLongInt) | Converts the variant to a signed 64-bit integer (LONGINT). |
| [Value](#Value) | Converts the variant to a floating point number (DOUBLE). |
| [ValUInt](#ValUInt) | Converts the variant to a 32.bit unsigned integer (ULONG). |
| [ValULong](#ValULong) | Converts the variant to a 32-bit unsigned integer (ULONG). |
| [ValULongInt](#ValULongInt) | Converts the variant to a 64-bit unsigned integer (ULONGINT). |
| [vtType](#vtType) | Returns the VARIANT type. |
| [bstr](#bstr) | Extracts the content of the underlying variant and returns it as a CBSTR. Same as ToBStr. |
| [sptr](#sptr) | Returns the address of the underlying variant. Same as vptr but without clearing the variant. |
| [vptr](#vptr) | Clears the CVAR and returns the address of the underlying variant. |
| [wstr](#wstr) | Extracts the content of the underlying variant and returns it as a CWSTR. Same as ToStr. |

