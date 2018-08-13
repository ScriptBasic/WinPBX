# CTextStream Class

Allows to read and write sequential text files (sometimes referred to as a text stream).
Works with ASCII and Unicode.
Works with Windows CRLF files and with Linux LF files.

### Methods and properties

| Name       | Description |
| ---------- | ----------- |
| [Create](#Create) | Creates a file and returns a TextStream object that can be used to read from or write to the file. |
| [Open](#Open) | Opens a file and returns a TextStream object that can be used to read from, write to, or append to the file. |
| [OpenUnicode](#OpenUnicode) | Opens a file and returns a TextStream object that can be used to read from, write to, or append to the file. |
| [OpenForInputA](#OpenForInputA) | Opens a file for input and returns a TextStream object that can be used to read from the file. |
| [OpenForInputW](#OpenForInputW) | Opens a file for input and returns a TextStream object that can be used to read from the file. |
| [OpenForOutputA](#OpenForOutputA) | Opens a file for putput and returns a TextStream object that can be used to write to the file. |
| [OpenForOutputW](#OpenForOutputW) | Opens a file for putput and returns a TextStream object that can be used to write to the file. |
| [OpenForAppendA](#OpenForAppendA) | Opens a file for append and returns a TextStream object that can be used to write to the file. |
| [OpenForAppendW](#OpenForAppendW) | Opens a file for append and returns a TextStream object that can be used to write to the file. |
| [Close](#Close) | Closes an open TextStream file. |
| [EOL](#EOL) | Returns TRUE if the file pointer is positioned immediately before the end-of-line marker in a TextStream file; FALSE if it is not. |
| [EOS](#EOS) | Returns TRUE if the file pointer is at the end of a TextStream file; FALSE if it is not. |
| [Read](#Read) | Reads a specified number of characters from a TextStream file and returns the resulting string. |
| [ReadLine](#ReadLine) | Reads an entire line (up to, but not including, the newline character) from a TextStream file and returns the resulting string. |
| [ReadAll](#ReadAll) | Reads an entire TextStream file and returns the resulting string. |
| [Write](#Write) | Writes a specified string to a TextStream file. |
| [WriteLine](#WriteLine) | Writes a specified string and newline character to a TextStream file. |
| [WriteBlankLines](#WriteBlankLines) | Writes a specified number of newline characters to a TextStream file. |
| [Skip](#Skip) | Skips a specified number of characters when reading a TextStream file. |
| [SkipLine](#SkipLine) | Skips the next line when reading a TextStream file. |
| [Line](#Line) | Returns the current line number in a TextStream file. |
| [Column](#Column) | Returns the column number of the current character position in a TextStream file. |
| [GetLastResult](#GetLastResult) | Returns the last result code. |


# <a name="Create"></a>Create

Creates a specified file name and returns a TextStream object that can be used to read from or write to the file.

```
FUNCTION Create (BYREF cbsFileName AS CBSTR, _
   BYVAL bOverwrite AS BOOLEAN = TRUE, _
   BYVAL bUnicode AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsFileName* | CBSTR. String expression that identifies the file to create. |
| *bOverwrite* | Boolean value that indicates whether you can overwrite an existing file. The value is true if the file can be overwritten, false if it can't be overwritten. If omitted, existing files are not overwritten. |
| *bUnicode* | Boolean value that indicates whether the file is created as a Unicode or ASCII file. The value is true if the file is created as a Unicode file, false if it's created as an ASCII file. If omitted, an ASCII file is assumed. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

#### Example

```
#include "Afx/CTextStream.inc"
using Afx

' // Create an instance of the CTextStream class
DIM pTxtStm AS CTextStream
' // Create a text stream
DIM cbsFile AS CBSTR = ExePath & "\Test.txt"
pTxtStm.Create(cbsFile, TRUE)
' // Write a string and an end of line to the stream
pTxtStm.WriteLine "This is a test."
' // Write more strings
pTxtStm.WriteLine "This is a string."
pTxtStm.WriteLine "This is a second string."
pTxtStm.WriteLine "This is the end line."

PRINT
PRINT "Press any key o end..."
SLEEP
```
# <a name="Open"></a>Open

Opens a specified file and returns a TextStream object that can be used to read from, write to, or append to the file.

```
FUNCTION Open (BYREF cbsFileName AS CBSTR, _
   BYVAL IOMode AS LONG = 1, _
   BYVAL bCreate AS BOOLEAN = FALSE, _
   BYVAL bUnicode AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsFileName* | CBSTR. String expression that identifies the file to open. |
| *IOMode* | LONG. Can be one of three constants: IOMode_ForReading, IOMode_ForWriting, or IOMode_ForAppending. |
| *bCreate* | Boolean value that indicates whether a new file can be created if the specified filename doesn't exist. The value is True if a new file is created, False if it isn't created. If omitted, a new file isn't created. |
| *bUnicode* | Boolean value that indicates whether the file is created as a Unicode or ASCII file. The value is true if the file is created as a Unicode file, false if it's created as an ASCII file. If omitted, an ASCII file is assumed. |

The *IOMode argument can have any of the following settings:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| IOMode_ForReading   | 1 | Open a file for reading only. You can't write to this file. |
| IOMode_ForWriting^  | 2 | Open a file for writing. |
| IOMode_ForAppending | 8 | Open a file and write to the end of the file. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.
