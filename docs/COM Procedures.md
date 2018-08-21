# COM Procedures

Assorted COM procedures.

**Include file**: AfxCOM.inc

| Name       | Description |
| ---------- | ----------- |
| [AfxAcode](#AfxAcode) | Translates unicode bytes to ansi bytes. |
| [AfxUcode](#AfxUcode) | Translates ansi bytes to unicode bytes. |
| [AfxIsBstr](#AfxIsBstr) | Checks if the passed pointer is a BSTR. |
| [AfxNewCOM](#AfxNewCOM) | Creates a single uninitialized object of the class associated with a specified ProgID or CLSID. |
| [AfxGuid](#AfxGuid) | Converts a string into a 16-byte (128-bit) Globally Unique Identifier (GUID). |
| [AfxGuidText](#AfxGuidText) | Returns a 38-byte human-readable guid string from a 16-byte GUID. |
| [AfxSafeAddRef](#AfxSafeAddRef) | Increments the reference count for an interface on an object. |
| [AfxSafeRelease](#AfxSafeRelease) | Decrements the reference count for an interface on an object. |
| [AfxAdvise](#AfxAdvise) | Establishes a connection between the connection point object and the client's sink. |
| [AfxUnadvise](#AfxUnadvise) | Releases the events connection identified with the cookie returned by the Advise method. |
| [AfxWstrAlloc](#AfxWstrAlloc) | Takes a null terminated wide string as input, and returns a pointer to a new wide string allocated with CoTaskMemAlloc. |
| [AfxGetOleErrorInfo](#AfxGetOleErrorInfo) | Returns the description of the most recent OLE error in the current logical thread and clears the error state for the thread. |
| [AfxOleCreateFont](#AfxOleCreateFont) | Creates a standard IFont object. |
| [AfxOleCreateFontDisp](#AfxOleCreateFontDisp) | Creates a standard IFontDisp object. |
| [AfxGetVarType](#AfxGetVarType) | Returns the tyè of a variant. |
| [AfxIsVarTypeFloat](#AfxIsVarTypeFloat) | Checks if a variant contains a float value. |
| [AfxIsVariantArray](#AfxIsVariantArray) | Checks if a variant contains an array. |
| [AfxIsVariantString](#AfxIsVariantString) | Checks if a variant contains an string. |
| [AfxIsVarTypeSignedInteger](#AfxIsVarTypeSignedInteger) | Checks if a variant contains a signed integer. |
| [AfxIsVarTypeUnsignedInteger](#AfxIsVarTypeUnsignedInteger) | Checks if a variant contains an unsigned integer. |
| [AfxIsVarTypeInteger](#AfxIsVarTypeInteger) | Checks if a variant contains an integer. |
| [AfxIsVarTypeNumber](#AfxIsVarTypeNumber) | Checks if a variant contains a number. |
| [AfxVariantGetElementCount](#AfxVariantGetElementCount) | Retrieves the element count of a variant structure. |
| [AfxVariantToBuffer](#AfxVariantToBuffer) | Extracts the contents of a variant that contains an array of bytes. |
| [AfxVariantToStringAlloc](#AfxVariantToStringAlloc) | Extracts the variant value of a variant structure to a string. |
| [AfxVarToStr](#AfxVarToStr) | Extracts the contents of a VARIANT and returns them as a CWSTR. |
| [AfxVariantToString](#AfxVariantToString) | Extracts the variant value of a variant structure to a string. |

# <a name="AfxAcode"></a>AfxAcode

Translates unicode bytes to ansi bytes.

```
FUNCTION AfxAcode (BYVAL pwszStr AS WSTRING PTR, BYVAL nCodePage AS LONG = 0) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszStr* | The WSTRING or CWSTR to convert. |
| *nCodePage* | Optional. The code page used in the conversion, e.g. 1251 for Russian. If you specify CP_UTF8, the returned string will be UTF8 encoded. If you don't pass an unicode page, the function will use CP_ACP (0), which is the system default Windows ANSI code page. |

#### Return value

An ansi or UTF8 encoded string.

#### Usage example
(Russian bytes to unicode string:

```
DIM cws AS CWSTR
cws = AfxUcode(CHR(209, 229, 236, 229, 237), 1251)
MessageBoxW 0, cws, "", MB_OK
DIM s AS STRING
s = AfxAcode(cws, 1251)
MessageBoxW 0, s, "", MB_OK
```


# <a name="AfxUcode"></a>AfxUcode

Translates ansi bytes to unicode bytes. This function works like the intrinsic Free Basic WSTR function, but accepting an optional code page.

```
FUNCTION AfxUcode (BYREF ansiStr AS CONST STRING, BYVAL nCodePage AS LONG = 0) AS CWSTR
```
| Parameter  | Description |
| ---------- | ----------- |
| *ansiStr* | Ansi or UTF8 string to convert. |
| *nCodePage* | Optional. The code page used in the conversion, e.g. 1251 for Russian. If you specify CP_UTF8, it is assumed that ansiStr contains an UTF8 encoded string. If you don't pass an unicode page, the function will use CP_ACP (0), which is the system default Windows ANSI code page. |

#### Return value

The ansi or utf-8 string converted to utf-16.

#### Usage example
(Russian bytes to unicode string and then to ansi):

```
DIM cws AS CWSTR
cws = AfxUcode(CHR(209, 229, 236, 229, 237), 1251)
MessageBoxW 0, cws, "", MB_OK
DIM s AS STRING
s = AfxAcode(cws, 1251)
MessageBoxW 0, s, "", MB_OK```
```

# <a name="AfxIsBstr"></a>AfxIsBstr

Checks if the passed pointer is a BSTR.

```
FUNCTION AfxIsBstr (BYVAL pv AS ANY PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pv* | Pointer to the string. |

#### Remarks

Will return FALSE if it is a null pointer.
If it is an OLE string it must have a descriptor; otherwise, don't.
Gets the length in bytes looking at the descriptor and divides by 2 to get the number of unicode characters, that is the value returned by the FreeBASIC LEN operator. If the retrieved length if the same that the returned by LEN, then it must be an OLE string.
