The **CWSTR** class implements a dynamic unicode null terminated string. Free Basic has a dynamic string data type (STRING) and a fixed length unicode data type (WSTRING), but it lacks a dynamic unicode string. **CWSTR** behaves as if it was a native data type, working directly with the intrinsic Free Basic string functions and operators.

**Include file**: CWSTR.INC.

Quirks:

* MID as a statement: Something like MID(cws, 2, 1) = "x" compiles but does not change the contents of the dynamic unicode string. MID(cws.wstr, 2, 1) = "x" or MID(**cws, 2, 1) = "x" works.
* SELECT CASE: Something like SELECT CASE LEFT(dws, 2) does not compile; we have to use SELECT CASE LEFT(**dws, 2). Same problem with RIGHT, but not with MID.
* Operator []: cwsText[0] = ASC("x") does not compile; we have to use (*cwsText)[0] = ASC("x").
