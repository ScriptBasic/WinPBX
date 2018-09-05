# CAdoStream Class

Represents a stream of binary data or text.

**Include file**: CAdoStream.inc (include CADODB.inc)

#### Remarks

In tree-structured hierarchies such as a file system or an e-mail system, a **Record** may have a default binary stream of bits associated with it that contains the contents of the file or the e-mail. A **Stream** object can be used to manipulate fields or records containing these streams of data. A **Stream** object can be obtained in these ways:

From a URL pointing to an object (typically a file) containing binary or text data. This object can be a simple document, a **Record** object representing a structured document, or a folder.
By opening the default **Stream** object associated with a **Record** object. You can obtain the default stream associated with a **Record** object when the **Record** is opened, to eliminate a round-trip just to open the stream.
By instantiating a **Stream** object. These **Stream** objects can be used to store data for the purposes of your application. Unlike a **Stream** associated with a URL, or the default **Stream** of a **Record**, an instantiated **Stream** has no association with an underlying source by default.

With the methods and properties of a **Stream** object, you can do the following:

* Open a **Stream** object from a **Record** or URL with the **Open** method.
* Close a **Stream** with the **Close** method.
* Input bytes or text to a **Stream** with the **Write** and **WriteText** methods.
* Read bytes from the **Stream** with the **Read** and **ReadText** methods.
* Write any **Stream** data still in the ADO buffer to the underlying object with the **Flush** method.
* Copy the contents of a **Stream** to another **Stream** with the **CopyTo** method.
* Control how lines are read from the source file with the **SkipLine** method and the **LineSeparator** property.
* Determine the end of stream position with the **EOS** property and **SetEOS** method.
* Save and restore data in files with the **SaveToFile** and **LoadFromFile** methods.
* Specify the character set used for storing the **Stream** with the **Charset** property.
* Halt an asynchronous **Stream** operation with the **Cancel** method.
* Determine the number of bytes in a **Stream** with the **Size** property.
* Control the current position within a **Stream** with the **Position** property.
* Determine the type of data in a **Stream** with the **Type_** property.
* Determine the current state of the **Stream** (closed, open, or executing) with the **State** property.
* Specify the access mode for the **Stream** with the **Mode** property.

**Note**: URLs using the http scheme will automatically invoke the Microsoft OLE DB Provider for Internet Publishing. For more information, see [Absolute and Relative URLs](https://msdn.microsoft.com/en-us/library/office/jj249501.aspx).

# Constructors

Creates an instance of the ADO **Stream** interface.

```
CONSTRUCTOR CAdoStream
```

Attaches an existing instance of the ADO **Stream** interface to the class.

```
CONSTRUCTOR CAdoStream (BYVAL pStream AS Afx_ADOStream PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pStream* | A pointer to an ADO **Stream** interface. |
| *fAddRef* | TRUE = increase the reference count; FALSE = don't increase the reference count. |

#### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [Attach](#Attach) | Attaches an ADO **Stream** to the class. |
| [Cancel](#Cancel) | Cancels execution of a pending, asynchronous method call. |
| [Charset](#Charset) | Indicates the character set into which the contents of a text **Stream** should be translated for storage in the **Stream** object's internal buffer. |
| [Close](#Close) | Closes a **Stream** object and any dependent objects. |
| [CopyTo](#CopyTo) | Copies the specified number of characters or bytes (depending on **Type_**) in the **Stream** to another **Stream** object. |
| [EOS](#EOS) | Indicates whether the current position is at the end of the stream. |
| [Flush](#Flush) | Forces the contents of the **Stream** remaining in the ADO buffer to the underlying object with which the **Stream** is associated. |
| [EOS](#EOS) | Indicates whether the current position is at the end of the stream. |
| [LineSeparator](#LineSeparator) | Indicates the binary character to be used as the line separator in text **Stream** objects. |
| [LoadFromFile](#LoadFromFile) | Loads the contents of an existing file into a **Stream**. |
| [Mode](#Mode) | Indicates the available permissions for modifying data in a **Stream** object. |
| [Open](#Open) | Opens a connection to a data source. |
| [Position](#Position) | Indicates the current position within a **Stream** object. |
| [Read](#Read) | Reads a specified number of bytes from a binary Stream object. |
| [ReadText](#ReadText) | Reads a specified number of characters, an entire line, or the entire stream from a **Stream** object and returns the resulting string. |
| [SaveToFile](#SaveToFile) | Saves the binary contents of a **Stream** to a file. |
| [SetEOS](#SetEOS) | Sets the position that is the end of the stream. |
| [Size](#Size) | Indicates the size of the stream in number of bytes. |
| [SkipLine](#SkipLine) | Skips one entire line when reading a text stream. |
| [SkipLine](#SkipLine) | Skips one entire line when reading a text stream. |
| [State](#State) | Indicates for whether the state of the **Stream** object is open or closed. |
| [Type_](#Type_) | Indicates the type of data contained in the **Stream** (binary or text). |
| [Write](#Write) | Writes binary data to a **Stream** object. |
| [WriteText](#WriteText) | Writes a string to a **Stream** object. |

# <a name="Attach"></a>Attach

Attaches a reference to an ADO **Stream** object to the class, allowing to call the methods and properties of its interface.

```
SUB Attach (BYVAL pStream AS Afx_ADOStream PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pStream* | A pointer to an ADO **Stream** interface. |
| *fAddRef* | TRUE = increase the reference count; FALSE = don't increase the reference count. |

# <a name="Cancel"></a>Cancel

Cancels execution of a pending, asynchronous method call.

```
FUNCTION Cancel () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

Use the **Cancel** method to terminate execution of an asynchronous method call (that is, a method invoked with the **adAsyncConnect**, **adAsyncExecute**, or **adAsyncFetch** option).

For a **Stream** object, the last asynchronous call to the **Open** method is terminated.

# <a name="Charset"></a>Charset

Cancels execution of a pending, asynchronous method call.

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
