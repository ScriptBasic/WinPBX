# String Procedures

| Name       | Description |
| ---------- | ----------- |
| AfxAcode | Translates unicode bytes to ansi bytes. |
| AfxBase64Decode | Converts the contents of a Base64 mime encoded string to an ascii string. |
| AfxBase64Encode | Converts the contents of a string to Base64 mime encoding. |
| AfxCryptBinaryToString | Converts an array of bytes into a formatted string. |
| AfxCryptStringToBinary | Converts a formatted string into an array of bytes. |
| AfxIsBstr | Checks if the passed pointer is a BSTR. |
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
