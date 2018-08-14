# String Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxAcode](#AfxAcode) | Translates unicode bytes to ansi bytes. |
| [AfxBase64Decode](#AfxBase64Decode) | Converts the contents of a Base64 mime encoded string to an ascii string. |
| [AfxBase64Encode](#AfxBase64Encode) | Converts the contents of a string to Base64 mime encoding. |
| [AfxCryptBinaryToString](#AfxCryptBinaryToString) | Converts an array of bytes into a formatted string. |
| [AfxCryptStringToBinary](#AfxCryptStringToBinary) | Converts a formatted string into an array of bytes. |
| [AfxIsBstr](#AfxIsBstr) | Checks if the passed pointer is a BSTR. |
| AfxStrClipLeft | Returns a string with the specified number of characters removed from the left side of the string. |
| AfxStrClipMid | Returns a string with the specified number of characters removed starting at the specified position. |
| AfxStrClipRight | Returns a string with the specified number of characters characters removed from the right side of the string. |
| AfxStrCSet | Returns a string containing a centered string. |
| AfxStrDelete | Deletes a specified number of characters from a string expression. |
| AfxStrExtract | Extracts characters from a string up to (but not including) a string or group of characters. Case sensitive. |
| AfxStrExtractI | Extracts characters from a string up to (but not including) a string or group of characters. Case insensitive. |
| AfxStrExtractAny | Extracts characters from a string up to (but not including) any character in a substring. Case sensitive. |
| AfxStrExtractAnyI | Extracts characters from a string up to (but not including) any character in a substring. Case insensitive. |
| AfxStrFormatByteSize | Converts a numeric value into a string that represents the number expressed as a size value in bytes, kilobytes, megabytes, or gigabytes, depending on the size. |
| AfxStrFormatKBSize | Converts a numeric value into a string that represents the number expressed as a size value in kilobytes. |
| AfxStrFromTimeInterval | Converts a time interval, specified in milliseconds, to a string. |
| AfxStrInsert | Inserts a string at a specified position within another string expression. |
| AfxStrJoin | Returns a string consisting of all of the strings in an array, each separated by a delimiter. |
| AfxStrLCase | Returns a lowercased version of a string. |
| AfxStrLSet | Returns a string containing a left justified string. |
| AfxStrParse | Returns a delimited field from a string expression. |
| AfxStrParseAny | Returns a delimited field from a string expression. Supports more than one character for the delimiter. |
| AfxStrParseCount | Returns the count of delimited fields from a string expression. |
| AfxStrParseCountAny | Returns the count of delimited fields from a string expression. Supports more than one character for the delimiter. |
| AfxStrPathName | Parses a path to extract component parts. |
| AfxStrRemain | Returns the portion of a string following the first occurrence of a substring. Case sensitive. |
| AfxStrRemainI | Returns the portion of a string following the first occurrence of a substring. Case insensitive. |
| AfxStrRemainAny | Returns the portion of a string following the first occurrence of a group of characters. Case sensitive. |
| AfxStrRemainAnyI | Returns the portion of a string following the first occurrence of a group of characters. Case insensitive. |
| AfxStrRemove | Returns a new string with substrings removed. Case sesnsitive. |
| AfxStrRemoveI | Returns a new string with substrings removed. Case insensitive. |
| AfxStrRemoveAny | Returns a new string with characters removed. Case sesnsitive. |
| AfxStrRemoveAnyI | Returns a new string with characters removed. Case insesnsitive. |
| AfxStrRepeat | Returns a string consisting of multiple copies of the specified string. |
| AfxStrReplace | Replaces all the occurrences of a substring with another string. Case sensitive. |
| AfxStrReplaceI | Replaces all the occurrences of a substring with another string. Case insensitive. |
| AfxStrReplaceAny | Replaces all the occurrences of a group of characters with another character. Case sensitive. |
| AfxStrReplaceAnyI | Replaces all the occurrences of a group of characters with another character. Case insensitive. |
| AfxStrRetain | Returns a string containing only the characters contained in a specified match string. Case sensitive. |
| AfxStrRetainI | Returns a string containing only the characters contained in a specified match string. Case insensitive. |
| AfxStrRetainAny | Returns a string containing only the characters contained in a specified group of characters. Case sensitive. |
| AfxStrRetainAnyI | Returns a string containing only the characters contained in a specified group of characters. Case insensitive. |
| AfxStrReverse | Reverses the contents of a string expression. |
| AfxStrRSet | Returns a string containing a right justified string. |
| AfxStrShrink | Shrinks a string to use a consistent single character delimiter. |
| AfxStrSplit | Splits a string into tokens, which are sequences of contiguous characters separated by any of the characters that are part of delimiters. |
| AfxStrSpn | Returns the length of the initial portion of a string which consists only of characters that are part of a specified set of characters. |
| AfxStrTally | Count the number of occurrences of a substring within a string. Case sensitive. |
| AfxStrTallyI | Count the number of occurrences of a substring within a string. Case insensitive. |
| AfxStrTallyAny | Count the number of occurrences of a list of characters within a string. Case sensitive. |
| AfxStrTallyAnyI | Count the number of occurrences of a list of characters within a string. Case insensitive. |
| AfxStrUCase | Returns an uppercased version of a string. |
| AfxStrUnWrap | Removes paired characters to the beginning and end of a string. |
| AfxStrVerify | Determine whether each character of a string is present in another string. Case sensitive. |
| AfxStrVerifyI | Determine whether each character of a string is present in another string. Case insensitive. |
| AfxStrWrap | Adds paired characters to the beginning and end of a string. |
| AfxUcode | Translates ansi bytes to unicode bytes. |
| AfxXmlBase64Decode | Converts the contents of a Base64 mime encoded string to an ascii string. |
| AfxXmlBase64Encode | Converts the contents of a string to Base64 mime encoding. |

#### Include file

AfxStr.inc

# <a name="AfxAcode"></a>AfxAcode

Translates unicode bytes to ansi bytes.

```
FUNCTION AfxAcode (BYVAL pwszStr AS WSTRING PTR, BYVAL nCodePage AS LONG = 0) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszStr* | [in] The WSTRING or CWSTR to convert. |
| *nCodePage* | [in, opt] The code page used in the conversion, e.g. 1251 for Russian. If you specify CP_UTF8, the returned string will be UTF8 encoded. If you don't pass an unicode page, the function will use CP_ACP (0), which is the system default Windows ANSI code page. |

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
# <a name="AfxBase64Decode"></a>AfxBase64Decode

Converts the contents of a Base64 mime encoded string to an ascii string.

```
FUNCTION AfxBase64Decode (BYREF strData AS STRING) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *strData* | [in] The string to decode. |

#### Return value

The decoded string on success, or a null string on failure.

####Remaks

Base64 is a group of similar encoding schemes that represent binary data in an ASCII string format by translating it into a radix-64 representation. The Base64 term originates from a specific MIME content transfer encoding.

Base64 encoding schemes are commonly used when there is a need to encode binary data that needs be stored and transferred over media that are designed to deal with textual data. This is to ensure that the data remains intact without modification during transport. Base64 is used commonly in a number of applications including email via MIME, and storing complex data in XML.

# <a name="AfxBase64Encode"></a>AfxBase64Encode

Converts the contents of a string to Base64 mime encoding.

```
FUNCTION AfxBase64Encode (BYREF strData AS STRING) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *strData* | [in] The string to encode. |

#### Return value

The encoded string on succeess, or a null string on failure.

# Remaks

Base64 is a group of similar encoding schemes that represent binary data in an ASCII string format by translating it into a radix-64 representation. The Base64 term originates from a specific MIME content transfer encoding.

Base64 encoding schemes are commonly used when there is a need to encode binary data that needs be stored and transferred over media that are designed to deal with textual data. This is to ensure that the data remains intact without modification during transport. Base64 is used commonly in a number of applications including email via MIME, and storing complex data in XML.

# <a name="AfxCryptBinaryToString"></a>AfxCryptBinaryToString

Converts an array of bytes into a formatted string.

```
FUNCTION FUNCTION AfxCryptBinaryToStringA ( _
   BYVAL pbBinary AS CONST UBYTE PTR, _
   BYVAL cbBinary AS DWORD, _
   BYVAL dwFlags AS DWORD, _
   BYVAL pszString AS LPSTR, _
   BYVAL pcchString AS DWORD PTR _
) AS WINBOOL
```

```
FUNCTION AfxCryptBinaryToStringW ( _
   BYVAL pbBinary AS CONST UBYTE PTR, _
   BYVAL cbBinary AS DWORD, _
   BYVAL dwFlags AS DWORD, _
   BYVAL pszString AS LPWSTR, _
   BYVAL pcchString AS DWORD PTR _
) AS WINBOOL
```

| Parameter  | Description |
| ---------- | ----------- |
| *pbBinary* | A pointer to the array of bytes to be converted into a string. |
| *cbBinary* | The number of elements in the *pbBinary* array. |
| *dwFlags* | Specifies the format of the resulting formatted string. |
| *pszString* | A pointer to a buffer that receives the converted string. To calculate the number of characters that must be allocated to hold the returned string, set this parameter to NULL. The function will place the required number of characters, including the terminating NULL character, in the value pointed to by *pcchString*. |
| *pcchString* | A pointer to a DWORD variable that contains the size, in characters, of the *pszString* buffer. If *pszString* is NULL, the function calculates the length of the return string (including the terminating null character) in characters and returns it in this parameter. If *pszString* is not NULL and big enough, the function converts the binary data into a specified string format including the terminating null character, but *pcchString* receives the length in characters, not including the terminating null character. |

Values available for the *dwFlags* parameter:

| Value      | Meaning |
| ---------- | ----------- |
| CRYPT_STRING_BASE64HEADER | Base64, with certificate beginning and ending headers. |
| CRYPT_STRING_BASE64 | Base64, without headers. |
| CRYPT_STRING_BINARY | Pure binary copy. |
| CRYPT_STRING_BASE64REQUESTHEADER | Base64, with request beginning and ending headers. |
| CRYPT_STRING_HEX | Hexadecimal only. |
| CRYPT_STRING_HEXASCII | Hexadecimal, with ASCII character display. |
| CRYPT_STRING_BASE64X509CRLHEADER | Base64, with X.509 CRL beginning and ending headers. |
| CRYPT_STRING_HEXADDR | Hexadecimal, with address display. |
| CRYPT_STRING_HEXASCIIADDR | Hexadecimal, with ASCII character and address display. |
| CRYPT_STRING_HEXRAW | A raw hexadecimal string. Not supported in Windows Server 2003 and Windows XP. |
| CRYPT_STRING_STRICT | Enforce strict decoding of ASN.1 text formats. Some ASN.1 binary BLOBS can have the first few bytes of the BLOB incorrectly interpreted as Base64 text. In this case, the rest of the text is ignored. Use this flag to enforce complete decoding of the BLOB. Not suported in Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP. |

In addition to the values above, one or more of the following values can be specified to modify the behavior of the function.

| Value      | Meaning |
| ---------- | ----------- |
| CRYPT_STRING_NOCRLF | Do not append any new line characters to the encoded string. The default behavior is to use a carriage return/line feed (CR/LF) pair (0x0D/0x0A) to represent a new line. Not supported in Windows Server 2003 and Windows XP. |
| CRYPT_STRING_NOCR | Only use the line feed (LF) character (0x0A) for a new line. The default behavior is to use a CR/LF pair (0x0D/0x0A) to represent a new line. |


#### Return value

If the function succeeds, the function returns nonzero (CTRUE).
If the function fails, it returns zero (FALSE).

#### Remarks

With the exception of when **CRYPT_STRING_BINARY** encoding is used, all strings are appended with a new line sequence. By default, the new line sequence is a CR/LF pair (0x0D/0x0A). If the *dwFlags* parameter contains the **CRYPT_STRING_NOCR** flag, then the new line sequence is a LF character (0x0A). If the dwFlags parameter contains the **CRYPT_STRING_NOCRLF** flag, then no new line sequence is appended to the string.

# <a name="AfxCryptStringToBinary"></a>AfxCryptStringToBinary

Converts a formatted string into an array of bytes.

```
FUNCTION AfxCryptStringToBinaryA ( _
   BYVAL pszString AS LPCSTR, _
   BYVAL cchString AS DWORD, _
   BYVAL dwFlags AS DWORD, _
   BYVAL pbBinary AS UBYTE PTR, _
   BYVAL pcbBinary AS DWORD PTR, _
   BYVAL pdwSkip AS DWORD PTR, _
   BYVAL pdwFlags AS DWORD PTR _
) AS WINBOOL
```

```
FUNCTION AfxCryptStringToBinaryW ( _
   BYVAL pszString AS LPCWSTR, _
   BYVAL cchString AS DWORD, _
   BYVAL dwFlags AS DWORD, _
   BYVAL pbBinary AS UBYTE PTR, _
   BYVAL pcbBinary AS DWORD PTR, _
   BYVAL pdwSkip AS DWORD PTR, _
   BYVAL pdwFlags AS DWORD PTR _
) AS WINBOOL
```

| Parameter  | Description |
| ---------- | ----------- |
| *pszString* | A pointer to a string that contains the formatted string to be converted. |
| *cchString* | The number of characters of the formatted string to be converted, not including the terminating NULL character. If this parameter is zero, pszString is considered to be a null-terminated string. |
| *dwFlags* | Indicates the format of the string to be converted. |
| *pbBinary* | A pointer to a buffer that receives the returned sequence of bytes. If this parameter is NULL, the function calculates the length of the buffer needed and returns the size, in bytes, of required memory in the DWORD pointed to by *pcbBinary*. |
| *pcbBinary* | A pointer to a DWORD variable that, on entry, contains the size, in bytes, of the *pbBinary* buffer. After the function returns, this variable contains the number of bytes copied to the buffer. If this value is not large enough to contain all of the data, the function fails and GetLastError returns **ERROR_MORE_DATA**. If *pbBinary* is NULL, the DWORD pointed to by *pcbBinary* is ignored. |
| *pdwSkip* | A pointer to a DWORD value that receives the number of characters skipped to reach the beginning of the actual base64 or hexadecimal strings. This parameter is optional and can be NULL if it is not needed. |
| *pdwFlags* | A pointer to a DWORD value that receives the flags actually used in the conversion. These are the same flags used for the *dwFlags* parameter. In many cases, these will be the same flags that were passed in the dwFlags parameter. If *dwFlags* contains one of the flags inicated below, this value will receive a flag that indicates the actual format of the string. This parameter is optional and can be NULL if it is not needed. |

Values available for the *dwFlags* parameter:

| Value      | Meaning |
| ---------- | ----------- |
| CRYPT_STRING_BASE64HEADER | Base64, with certificate beginning and ending headers. |
| CRYPT_STRING_BASE64 | Base64, without headers. |
| CRYPT_STRING_BINARY | Pure binary copy. |
| CRYPT_STRING_BASE64REQUESTHEADER | Base64, with request beginning and ending headers. |
| CRYPT_STRING_BASE64 | Base64, without headers. |
| CRYPT_STRING_HEX | Hexadecimal only. |
| CRYPT_STRING_HEXASCII | Hexadecimal, with ASCII character display. |
| CRYPT_STRING_BASE64_ANY | Tries the following, in order: CRYPT_STRING_BASE64HEADER, CRYPT_STRING_BASE64. |
| CRYPT_STRING_ANY | Tries the following, in order: CRYPT_STRING_BASE64HEADER, CRYPT_STRING_BASE64, CRYPT_STRING_BINARY. |
| CRYPT_STRING_HEX_ANY | Tries the following, in order: CRYPT_STRING_HEXADDR, CRYPT_STRING_HEXASCIIADDR, CRYPT_STRING_HEX, CRYPT_STRING_HEXRAW, CRYPT_STRING_HEXASCII. |
| CRYPT_STRING_HEX | Hexadecimal only. |
| CRYPT_STRING_BASE64X509CRLHEADER | Base64, with X.509 CRL beginning and ending headers. |
| CRYPT_STRING_HEXADDR | Hexadecimal, with address display. |
| CRYPT_STRING_HEXASCIIADDR | Hexadecimal, with ASCII character and address display. |
| CRYPT_STRING_HEXRAW | A raw hexadecimal string. Not supported in Windows Server 2003 and Windows XP. |
| CRYPT_STRING_STRICT | Enforce strict decoding of ASN.1 text formats. Some ASN.1 binary BLOBS can have the first few bytes of the BLOB incorrectly interpreted as Base64 text. In this case, the rest of the text is ignored. Use this flag to enforce complete decoding of the BLOB. Not suported in Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP. |

Values available for the *pdwFlags* parameter:

| Value      | Meaning |
| ---------- | ----------- |
| CRYPT_STRING_ANY | This variable will receive one of the following values. Each value indicates the actual format of the string. CRYPT_STRING_BASE64HEADER, CRYPT_STRING_BASE64, CRYPT_STRING_BINARY. |
| CRYPT_STRING_BASE64_ANY | This variable will receive one of the following values. Each value indicates the actual format of the string. CRYPT_STRING_BASE64HEADER, CRYPT_STRING_BASE64. |
| CRYPT_STRING_HEX_ANY | This variable will receive one of the following values. Each value indicates the actual format of the string. CRYPT_STRING_HEXADDR, CRYPT_STRING_HEXASCIIADDR, CRYPT_STRING_HEX, CRYPT_STRING_HEXRAW, CRYPT_STRING_HEXASCII. |

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

