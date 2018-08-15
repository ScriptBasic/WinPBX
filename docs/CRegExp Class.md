# CRegExp Class

**CRegExp** is a wrapper class on top of the VB Script Regular Expressions.

In a typical search and replace operation, you must provide the exact text for which you are searching. That technique may be adequate for simple search and replace tasks in static text, but it lacks flexibility and makes searching dynamic text difficult, if not impossible.

With regular expressions, you can:

* Test for a pattern within a string. For example, you can test an input string to see if a telephone number pattern or a credit card number pattern occurs within the string. This is called data validation.

* Replace text. You can use a regular expression to identify specific text in a document and either remove it completely or replace it with other text.

* Extract a substring from a string based upon a pattern match. You can find specific text within a document or input field.

#### Include file

CRegExp.inc

### Constructors

```
CONSTRUCTOR CRegExp (BYREF pRegExp AS CRegExp)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pRegExp* | Reference to an instance of a **CRegExp** class to be cloned. |

#### Remarks

This constructor clones the passed object and is used internally by the Execute method.

```
CONSTRUCTOR CRegExp (BYREF cbsPattern AS CBSTR, BYVAL bIgnoreCase AS BOOLEAN = FALSE, _
   BYVAL bGlobal AS BOOLEAN = FALSE, BYVAL bMultiline AS BOOLEAN = FALSE)
```
```
CONSTRUCTOR CRegExp (BYVAL bIgnoreCase AS BOOLEAN = FALSE, _
   BYVAL bGlobal AS BOOLEAN = FALSE, BYVAL bMultiline AS BOOLEAN = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsPattern* | The regular expression pattern being searched for. |
| *bIgnoreCase* | TRUE or FALSE. Indicates if a pattern search is case-sensitive or not. |
| *bGlobal* | TRUE or FALSE. Indicates if a pattern should match all occurrences in an entire search string or just the first one. |
| *bMultiline* | TRUE or FALSE. Whether or not to search in strings across multiple lines. |

### Methods

| Name  | Description |
| ---------- | ----------- |
| [Execute](#Execute) | Executes a regular expression search against a specified string. |
| [Extract](#Extract) | Extracts a substring using VBScript regular expressions search patterns. |
| Find | Find function with VBScript regular expressions search patterns. |
| FindEx | Global, multiline find function with VBScript regular expressions search patterns. |
| GetLastResult | Returns the last result code. |
| MatchCount | Returns the number of matches found. |
| RegExpPtr | Returns a direct pointer to the **Afx_IRegExp2** interface. |
| Remove | Returns a copy of a string with text removed using a regular expression as the search string. |
| Replace | Replaces text found in a regular expression search. |
| SubMatchValue | Retrieves the content of the specified submatch. |
| Test | Executes a regular expression search against a specified string and returns a boolean value that indicates if a pattern match was found. |

### Properties

| Name  | Description |
| ---------- | ----------- |
| Global | Sets or returns a boolean value that indicates if a pattern should match all occurrences in an entire search string or just the first one. |
| IgnoreCase | Sets or returns a boolean value that indicates if a pattern search is case-sensitive or not. |
| MatchLen | Returns the length of a match found in a search string. |
| MatchPos | Returns the position in a search string where a match occurs. |
| MatchValue | Returns the value or text of a match found in a search string. |
| Multiline | Sets or returns a boolean value that indicates whether or not to search in strings across multiple lines. |
| Pattern | Sets or returns a boolean value that indicates whether or not to search in strings across multiple lines. |
| SubMatchCount | Returns the number of submatches. |

# <a name="Execute"></a>Execute

Executes a regular expression search against a specified string.

```
FUNCTION Execute (BYREF cbsSourceString AS CBSTR, BYREF cvReplaceString AS CVAR, _
   BYVAL bIgnoreCase AS BOOLEAN = FALSE, BYVAL bGlobal AS BOOLEAN = TRUE, _
   BYVAL bMultiline AS BOOLEAN = FALSE) AS BOOLEAN
```
```
FUNCTION Execute (BYREF cbsSourceString AS CBSTR, BYREF cbsPattern AS CBSTR, _
   BYREF cvReplaceString AS CVAR,BYVAL bIgnoreCase AS BOOLEAN = FALSE, _
   BYVAL bGlobal AS BOOLEAN = TRUE, BYVAL bMultiline AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsSourceString* | The main string. |
| *cbsPattern* | The regular string expression being searched for. |
| *cvReplaceString* | The replacement text string. |
| *bIgnoreCase* | TRUE or FALSE. Indicates if a pattern search is case-sensitive or not.  |
| *bGlobal* | TRUE or FALSE. Indicates if a pattern should match all occurrences in an entire search string or just the first one. |
| *bMultiline* | TRUE or FALSE. Whether or not to search in strings across multiple lines. |

#### Remarks

In the first overloaded method, the actual pattern for the regular expression search is set using the **Pattern** property.

#### Return value

BOOLEAN. True on success or False on failure.

# <a name="Extract"></a>Extract

Extracts a substring using VBScript regular expressions search patterns.

```
FUNCTION Extract (BYREF cbsSourceString AS CBSTR, BYVAL bIgnoreCase AS BOOLEAN = FALSE, _
   BYVAL bGlobal AS BOOLEAN = FALSE, BYVAL bMultiline AS BOOLEAN = FALSE) AS CBSTR
```
```
FUNCTION Extract (BYREF cbsSourceString AS CBSTR, BYREF cbsPattern AS CBSTR, _
   BYVAL bIgnoreCase AS BOOLEAN = FALSE, BYVAL bGlobal AS BOOLEAN = FALSE, _
   BYVAL bMultiline AS BOOLEAN = FALSE) AS CBSTR
```
```
FUNCTION Extract (BYVAL nStart AS LONG, BYREF cbsSourceString AS CBSTR, _
   BYVAL bIgnoreCase AS BOOLEAN = FALSE) AS CBSTR
```
```
FUNCTION Extract (BYVAL nStart AS LONG, BYREF cbsSourceString AS CBSTR, _
   BYREF cbsPattern AS CBSTR, BYVAL bIgnoreCase AS BOOLEAN = FALSE) AS CBSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *nStart* | The position in the string at which the search will begin. The first character starts at position 1. |
| *cbsSourceString* | The text to be parsed. |
| *cbsPattern* | The pattern to match. |
| *bIgnoreCase* | TRUE or FALSE. Indicates if a pattern search is case-sensitive or not. |
| *bGlobal* | TRUE or FALSE. Indicates if a pattern should match all occurrences in an entire search string or just the first one. |
| *bMultiline* | TRUE or FALSE. Whether or not to search in strings across multiple lines. |

#### Return value

CBSTR. The retrieved string.

#### Usage examples

```
DIM pRegExp AS CRegExp
DIM cbsText AS CBSTR = "blah blah a234 blah blah x345 blah blah"
DIM cbsPattern AS CBSTR = "[a-z][0-9][0-9][0-9]"
DIM cbs AS CBSTR = pRegExp.Extract(cbsText, cbsPattern)
```
```
DIM pRegExp AS CRegExp
DIM cbsText AS CBSTR = "blah blah a234 blah blah x345 blah blah"
DIM cbsPattern AS CBSTR = "[a-z][0-9][0-9][0-9]"
DIM cbs AS CBSTR = pRegExp.Extract(15, cbsText, cbsPattern)
```
```
DIM cbsPattern AS CBSTR = "[a-z][0-9][0-9][0-9]"
DIM cbsText AS CBSTR = "blah blah a234 blah blah x345 blah blah"
DIM cbs AS CBSTR = CRegExp(cbsPattern).Extract(cbsText)
```
```
' // Ignore case
DIM cbsPattern AS CBSTR = "[a-z][0-9][0-9][0-9]"
DIM cbsText AS CBSTR = "blah blah A234 blah blah x345 blah blah"
DIM cbs AS CBSTR = CRegExp(cbsPattern).Extract(cbsText, TRUE)
```
