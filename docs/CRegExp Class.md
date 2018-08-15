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

