# COM Procedures

**Include file**: AfxCOM.inc

| Name       | Description |
| ---------- | ----------- |
| [AfxAcode](#AfxAcode) | Translates unicode bytes to ansi bytes. |
| [AfxUcode](#AfxUcode) | Translates ansi bytes to unicode bytes. |

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
