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
| *pStream* | A pointer to an existing ADO **Stream** interface. |
| *fAddRef* | TRUE = increase the reference count; FALSE = don't increase the reference count. |
