# CAdoStream Class

An alternative to work with memory streams is to use the ADO stream object. To avoid confussons, the documentation for **CAdoStream** has been adapted to remove references to its use with URLs and ADO Record objects.

With the methods and properties of a **Stream** object, you can do the following:

* Input bytes or text to a **Stream** with the **Write** and **WriteText** methods.
* Read bytes from the **Stream** with the **Read** and **ReadText** methods.
* Copy the contents of a **Stream** to another **Stream** with the **CopyTo** method.
* Control how lines are read from the source file with the **SkipLine** method and the **LineSeparator** property.
* Determine the end of stream position with the **EOS** property and **SetEOS** method.
* Save and restore data in files with the **SaveToFile** and **LoadFromFile** methods.
* Specify the character set used for storing the **Stream** with the **Charset** property.
* Determine the number of bytes in a **Stream** with the **Size** property.
* Control the current position within a **Stream** with the **Position** property.
* Determine the type of data in a **Stream** with the **Type_** property.
* Determine the current state of the **Stream** (closed, open, or executing) with the **State** property.
* Specify the access mode for the **Stream** with the **Mode** property.
* Close a **Stream** with the **Close** method.

**Include file**: CAdoStream.inc (include CADODB.inc)

# Constructor

Creates an instance of the ADO **Stream** interface.

```
CONSTRUCTOR CAdoStream
```

#### Usage example

```
DIM pStm AS CAdoStream
```

#### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [Charset](#Charset) | Indicates the character set into which the contents of a text **Stream** should be translated for storage in the **Stream** object's internal buffer. |
| [Close](#Close) | Closes a **Stream** object and any dependent objects. |
| [CopyTo](#CopyTo) | Copies the specified number of characters or bytes (depending on **Type_**) in the **Stream** to another **Stream** object. |
| [EOS](#EOS) | Indicates whether the current position is at the end of the stream. |
| [LineSeparator](#LineSeparator) | Indicates the binary character to be used as the line separator in text **Stream** objects. |
| [LoadFromFile](#LoadFromFile) | Loads the contents of an existing file into a **Stream**. |
| [Mode](#Mode) | Indicates the available permissions for modifying data in a **Stream** object. |
| [Open](#Open) | Opens the stream. |
| [Position](#Position) | Indicates the current position within a **Stream** object. |
| [Read](#Read) | Reads a specified number of bytes from a binary Stream object. |
| [ReadText](#ReadText) | Reads a specified number of characters, an entire line, or the entire stream from a **Stream** object and returns the resulting string. |
| [SaveToFile](#SaveToFile) | Saves the binary contents of a **Stream** to a file. |
| [SetEOS](#SetEOS) | Sets the position that is the end of the stream. |
| [Size](#Size) | Indicates the size of the stream in number of bytes. |
| [SkipLine](#SkipLine) | Skips one entire line when reading a text stream. |
| [State](#State) | Indicates for whether the state of the **Stream** object is open or closed. |
| [Type_](#Type_) | Indicates the type of data contained in the **Stream** (binary or text). |
| [Write](#Write) | Writes binary data to a **Stream** object. |
| [WriteText](#WriteText) | Writes a string to a **Stream** object. |

# <a name="Charset"></a>Charset

Indicates the character set into which the contents of a text **Stream** should be translated for storage in the **Stream** object's internal buffer.

```
PROPERTY Charset () AS CBSTR
PROPERTY Charset (BYREF cbsCharset AS CBSTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsCharset* | CBSTR. A value that specifies the character set into which the contents of the **Stream** will be translated. The default value is "Unicode". Allowed values are typical strings passed over the interface as Internet character set strings (for example, "iso-8859-1", "Windows-1252", etc.). For a list of the character set strings that is known by a system, see the subkeys of HKEY_CLASSES_ROOT\MIME\Database\Charset in the Windows Registry. |

#### Return value

CBSTR. The character set.

#### Remarks

In a text **Stream** object, text data is stored in the character set specified by the **Charset** property. The default is Unicode. The **Charset** property is used for converting data going into the **Stream** or coming out of the **Stream**. For example, if the **Stream** contains ISO-8859-1 data and that data is copied to a **BSTR**, the **Stream** object will convert the data to Unicode. The reverse is also true.

For an open **Stream**, the current **Position** must be at the beginning of the **Stream** (0) to be able to set **Charset**.

**Charset** is used only with text **Stream** objects (**Type_** is **adTypeText**). This property is ignored if **Type_** is **adTypeBinary**.

# <a name="Close"></a>Close

Closes a **Stream** object and any dependent objects.

```
FUNCTION Close () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="CopyTo"></a>CopyTo

Copies the specified number of characters or bytes (depending on **Type_**) in the **Stream** to another **Stream** object.

```
FUNCTION CopyTo (BYVAL pDestStream AS ADOStream PTR, BYVAL CharNumber AS LONG = adReadAll) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pDestStream* | An object variable value that contains a reference to an open **Stream** object. The current **Stream** is copied to the destination **Stream** specified by *pDestStream*. The destination Stream must already be open. If not, a run-time error occurs. **Note**: The *pDestStream* parameter may not be a proxy of **Stream** object because this requires access to a private interface on the **Stream** object that cannot be remoted to the client. |
| *CharNumber* | Optional. An integer value that specifies the number of bytes or characters to be copied from the current position in the source **Stream** to the destination **Stream**. The default value is *adReadAll* (-1), which specifies that all characters or bytes are copied from the current position to **EOS**. |

#### Return value

CBSTR. The character set.

#### Remarks

This method copies the specified number of characters or bytes, starting from the current position specified by the **Position** property. If the specified number is more than the available number of bytes until **EOS**, then only characters or bytes from the current position to **EOS** are copied. If the value of *NumChars* is –1, or omitted, all characters or bytes starting from the current position are copied.

If there are existing characters or bytes in the destination stream, all contents beyond the point where the copy ends remain, and are not truncated. Position becomes the byte immediately following the last byte copied. If you want to truncate these bytes, call **SetEOS**.

**CopyTo** should be used to copy data to a destination **Stream** of the same type as the source **Stream** (their **Type_** property settings are both **adTypeText** or both **adTypeBinary**). For text **Stream** objects, you can change the **Charset** property setting of the destination **Stream** to translate from one character set to another. Also, text **Stream** objects can be successfully copied into binary **Stream objects**, but binary **Stream** objects cannot be copied into text **Stream** objects.

# <a name="EOS"></a>EOS

Indicates whether the current position is at the end of the stream.

```
FUNCTION EOS () AS BOOLEAN
```

#### Return value

A Boolean value that indicates whether the current position is at the end of the stream. **EOS** returns True if there are no more bytes in the stream; it returns False if there are more bytes following the current position.

To set the end of stream position, use the **SetEOS** method. To determine the current position, use the **Position** property.

# <a name="LineSeparator"></a>LineSeparator

Indicates the binary character to be used as the line separator in text **Stream** objects.

```
PROPERTY LineSeparator () AS LineSeparatorEnum
PROPERTY LineSeparator (BYVAL LS AS LineSeparatorEnum)
```

| Parameter  | Description |
| ---------- | ----------- |
| *LS* | A **LineSeparatorEnum** value that indicates the line separator character used in the **Stream**. The default value is *adCRLF*. |

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adCR** | 13 | Indicates carriage return. |
| **adCRLF** | -1 | Default. Indicates carriage return line feed. |
| **adLF** | 10 | Indicates line feed. |

#### Return value

LONG. A **LineSeparatorEnum** value.

#### Remarks

**LineSeparator** is used to interpret lines when reading the content of a text **Stream**. Lines can be skipped with the **SkipLine** method.

**LineSeparator** is used only with text **Stream** objects (**Type_** is **adTypeText**). This property is ignored if **Type_** is **adTypeBinary**.

# <a name="LoadFromFile"></a>LoadFromFile

Loads the contents of an existing file into a **Stream**.

```
FUNCTION LoadFromFile (BYREF cbsFileName AS CBSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsFileName* | An string value that contains the name of a file to be loaded into the **Stream**. *cbsFileName* can contain any valid path and name in UNC format. If the specified file does not exist, a run-time error occurs. |

#### Remarks

This method may be used to load the contents of a local file into a **Stream** object. This may be used to upload the contents of a local file to a server.

The **Stream** object must be already open before calling LoadFromFile. This method does not change the binding of the **Stream** object; it will still be bound to the object specified by the URL or **Record** with which the Stream was originally opened.

**LoadFromFile** overwrites the current contents of the **Stream** object with data read from the file. Any existing bytes in the **Stream** are overwritten by the contents of the file. Any previously existing and remaining bytes following the **EOS** created by **LoadFromFile**, are truncated.

After a call to **LoadFromFile**, the current position is set to the beginning of the **Stream** (Position is 0).

Because 2 bytes may be added to the beginning of the stream for encoding, the size of the stream may not exactly match the size of the file from which it was loaded.

# <a name="Mode"></a>Mode

Indicates the available permissions for modifying data in a **Stream** object.

```
PROPERTY GET Mode () AS ConnectModeEnum
PROPERTY SET Mode (BYVAL nMode AS ConnectModeEnum)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMode* | LONG. A **ConnectModeEnum** value. The default value for a Stream associated with an underlying source (opened with a URL as the source, or as the default **Stream** of a **Record**) is **adModeRead**. The default value for a **Stream** not associated with an underlying source (instantiated in memory) is **adModeUnknown**. |

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adModeRead** | 1 | Indicates read-only permissions. |
| **adModeReadWrite** | 3 | Indicates read/write permissions. |
| **adModeWrite** | 2 | Indicates write-only permissions. |

#### Return value

LONG. A **ConnectionModeEnum** value.

#### Remarks

This property is read/write while the object is closed and read-only while the object is open.

# <a name="Open"></a>Open

Opens the stream.

```
FUNCTION Open () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

Instantiates a **Stream** object in memory without associating it with an underlying source. You can dynamically add data to the stream simply by writing binary or text data to the **Stream** with **Write** or **WriteText**, or by loading data from a file with **LoadFromFile**.

While the **Stream** is not open, it is possible to read all the read-only properties of the **Stream**.

#### Example

```
#define UNICODE
#include "Afx/CADODB/CADODB.inc"
using Afx

' // Open a stream in memory
DIM pStream AS CAdoStream
pStream.Type_ = adTypeText
pStream.LineSeparator = adCRLF
pStream.Open

' // Write some text to it
pStream.WriteText "This is a test string", adWriteLine
pStream.WriteText "This is another test string", adWriteLine

' // Set the position at the beginning of the file
pStream.Position = 0
' // Read the lines
DIM cbsText AS CBSTR = pStream.ReadText(adReadLine)
print cbsText
cbsText = pStream.ReadText(adReadLine)
print cbsText

' // Save the contents to a file
pStream.SaveToFile "TestStream.txt", adSaveCreateOverWrite
pStream.Close

PRINT
PRINT "Press any key..."
SLEEP
```

# <a name="Position"></a>Position

Indicates the current position within a **Stream** object.

```
PROPERTY Position () AS LONG
PROPERTY Position (BYVAL nPos AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nPos* | LONG. A value that specifies the offset, in number of bytes, of the current position from the beginning of the stream. A value of 0 represents the first byte in the stream. |

#### Return value

LONG. The offset, in number of bytes, of the current position from the beginning of the stream.

#### Remarks

The current position can be moved to a point after the end of the stream. If you specify the current position beyond the end of the stream, the **Size** of the **Stream** object will be increased accordingly. Any new bytes added in this way will be null.

**Notes**: **Position** always measures bytes. For text streams using multibyte character sets, multiply the position by the character size to determine the character number. For example, for a two-byte character set, the first character is at position 0, the second character at position 2, the third character at position 4, and so on.

Negative values cannot be used to change the current position in a **Stream**. Only positive numbers can be used for **Position**.

For read-only **Stream** objects, ADO will not return an error if **Position** is set to a value greater than the **Size** of the **Stream**. This does not change the size of the **Stream**, or alter the Stream contents in any way. However, doing this should be avoided because it results in a meaningless **Position** value.

# <a name="Read"></a>Read

Reads a specified number of bytes from a binary **Stream** object.

```
FUNCTION Read (BYVAL NumBytes AS LONG = adReadAll) AS CVAR
FUNCTION Read (BYVAL NumBytes AS LONG = adReadAll, BYREF cvValue AS CVAR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *NumBytes* | Optional. A Long value that specifies the number of bytes to read from the file or the **StreamReadEnum** value **adReadAll**, which is the default. |
| *cvValue* | Reference to a **CVAR** variable that will receive the bytes read. |

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adReadAll** | -1 | Default. Reads all bytes from the stream, from the current position onwards to the EOS marker. This is the only valid StreamReadEnum value with binary streams (**Type_** is **adTypeBinary**). |
| **adReadLine** | -2 | Reads the next line from the stream (designated by the **LineSeparator** property). |

#### Return value

CVAR. The bytes read.

#### Remarks

If *NumBytes* is more than the number of bytes left in the **Stream**, only the bytes remaining are returned. The data read is not padded to match the length specified by *NumBytes*. If there are no bytes left to read, a variant with a null value is returned. Read cannot be used to read backwards.

**Note**: *NumBytes* always measures bytes. For text **Stream** objects (**Type_** is **adTypeText**), use **ReadText**.

# <a name="ReadText"></a>ReadText

Reads a specified number of characters, an entire line, or the entire stream from a **Stream** object and returns the resulting string.

```
FUNCTION ReadText (BYVAL NumChars AS LONG = adReadAll) AS CBSTR
FUNCTION ReadText (BYVAL NumChars AS LONG = adReadAll, BYREF cbsText AS CBSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *NumChars* | Optional. A Long value that specifies the number of characters to read from the file, or a **StreamReadEnum* value. The default value is **adReadAll**. |
| *cbsText* | Reference to a **CBSTR** variable that will receive the charecters read. |

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adReadAll** | -1 | Default. Reads all bytes from the stream, from the current position onwards to the EOS marker. This is the only valid StreamReadEnum value with binary streams (**Type_** is **adTypeBinary**). |
| **adReadLine** | -2 | Reads the next line from the stream (designated by the **LineSeparator** property). |

#### Return value

CBSTR. The characters read.

#### Remarks

If *NumChars* is more than the number of characters left in the stream, only the characters remaining are returned. The string read is not padded to match the length specified by *NumChars*. If there are no characters left to read, a variant whose value is null is returned. **ReadText** cannot be used to read backwards.

**Note**: The **ReadText** method is used with text streams (**Type_** is **adTypeText**). For binary streams (**Type_** is **adTypeBinary**), use **Read**.

# <a name="SaveToFile"></a>SaveToFile

Saves the binary contents of a **Stream** to a file.

```
FUNCTION SaveToFile (BYREF cbsFileName AS CBSTR, BYVAL Options AS LONG = adSaveCreateNotExist) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsFileName* | Am string value that contains the fully-qualified name of the file to which the contents of the **Stream** will be saved. You can save to any valid local location, or any location you have access to via a UNC value. |
| *Options* | Optional. A **SaveOptionsEnum** value that specifies whether a new file should be created by **SaveToFile**, if it does not already exist. Default value is **adSaveCreateNotExists**. With these options you can specify that an error occurs if the specified file does not exist. You can also specify that **SaveToFile** overwrites the current contents of an existing file. **Note**: If you overwrite an existing file (when **adSaveCreateOverwrite** is set), **SaveToFile** truncates any bytes from the original existing file that follow the new **EOS**. |

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adSaveCreateNotExist** | 1 | Default. Creates a new file if the file specified by the *cbsFileName* parameter does not already exist. |
| **adSaveCreateOverWrite** | -2 | Overwrites the file with the data from the currently open Stream object, if the file specified by the *cbsFileName* parameter already exists. |

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

**SaveToFile** may be used to copy the contents of a **Stream** object to a local file. There is no change in the contents or properties of the **Stream object**. The **Stream** object must be open before calling **SaveToFile**.

This method does not change the association of the **Stream** object to its underlying source. The **Stream** object will still be associated with the original URL or **Record** that was its source when opened.

After a **SaveToFile** operation, the current position (**Position**) in the stream is set to the beginning of the stream (0).

# <a name="SetEOS"></a>SetEOS

Sets the position that is the end of the stream.

```
FUNCTION SetEOS () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

**SetEOS** updates the value of the **EOS** property, by making the current **Position** the end of the stream. Any bytes or characters following the current position are truncated.

Since **Write**, **WriteText**, and **CopyTo** do not truncate any extra values in existing **Stream** objects, you can truncate these bytes or characters by setting the new end-of-stream position with **SetEOS**.

**Caution**: If you set **EOS** to a position before the actual end of the stream, you will lose all data after the new **EOS** position.

# <a name="Size"></a>Size

Indicates the size of the stream in number of bytes.

```
PROPERTY Size () AS LONG
```

#### Return value

LONG. The size of the stream in number of bytes.

# <a name="SkipLine"></a>SkipLine

Skips one entire line when reading a text stream.

```
FUNCTION SkipLine () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

All characters up to, and including the next line separator, are skipped. By default, the **LineSeparator** is **adCRLF**. If you attempt to skip past **EOS**, the current position will simply remain at **EOS**.

The **SkipLine** method is used with text streams (**Type_** is **adTypeText**).

# <a name="State"></a>State

Indicates for whether the state of the **Stream** object is open or closed.

```
PROPERTY State () AS ObjectStateEnum
```

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adStateClosed** | 0 | Indicates that the object is closed. |
| **adStateOpen** | &H1 | Indicates that the object is open. |
| **adStateConnecting** | &H2 | Indicates that the object is connecting. |
| **adStateExecuting** | &H4 | Indicates that the object is executing a command. |
| **adStateFetching** | &H8 | Indicates that the rows of the object are being retrieved. |

#### Return value

LONG. The current **Stream** state.

# <a name="Type_"></a>Type_

Indicates the type of data contained in the **Stream** (binary or text).

```
PROPERTY Type_ () AS StreamTypeEnum
PROPERTY Type_ (BYVAL nType AS StreamTypeEnum)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nType* | LONG. A **StreamTypeEn

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adTypeBinary** | 1 | Indicates binary data. |
| **adTypeText** | 2 | Default. Indicates text data, which is in the character set specified by Charset.
um** value that specifies the type of data contained in the **Stream** object. The default value is **adTypeText**. However, if binary data is initially written to a new, empty stream, the **Type_** will be changed to **adTypeBinary**. |

#### Return value

LONG. A **StreamTypeEnum** value.

#### Remarks

The **Type_** property is read/write only when the current position is at the beginning of the **Stream** (**Position** is 0), and read-only at any other position.

The **Type_** property determines which methods should be used for reading and writing the **Stream**. For text streams, use **ReadText** and **WriteText**. For binary streams, use **Read** and **Write**.

# <a name="Write"></a>Write

Writes binary data to a **Stream** object.

```
FUNCTION Write (BYREF cvBuffer AS CVAR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cvBuffer* | A **CVAR** that contains an array of bytes to be written. |

#### Return value

S_OK (0) or an HRESULT code.

# <a name="WriteText"></a>WriteText

Writes a string to a **Stream** object.

```
FUNCTION WriteText (BYREF cbsData AS CBSTR, BYVAL Options AS StreamWriteEnum = adWriteChar) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsData* | An string value that contains the text in characters to be written. |
| *Options* | Optional. A **StreamWriteEnum** value that specifies whether a line separator character must be written at the end of the specified string. |

| Constant   | Value | Description |
| ---------- | ----- | ----------- |
| **adWriteChar** | 0 | Default. Writes the specified text string (specified by the Data parameter) to the Stream object. |
| **adWriteLine** | 1 | Writes a text string and a line separator character to a Stream object. If the LineSeparator property is not defined, then this returns a run-time error. |

#### Return value

Specified strings are written to the **Stream** object without any intervening spaces or characters between each string.

The current **Position** is set to the character following the written data. The **WriteText** method does not truncate the rest of the data in a stream. If you want to truncate these characters, call **SetEOS**.

If you write past the current **EOS** position, the **Size** of the **Stream** will be increased to contain any new characters, and **EOS** will move to the new last byte in the **Stream**.

**Note**: The **WriteText** method is used with text streams (**Type_** is **adTypeText**). For binary streams (**Type_** is **adTypeBinary**), use **Write**.
