# CFileStream Class

Allows to work with binary file streams. A binary stream consists of one or more bytes of arbitrary information. You can write the value stored in an arbitrary object to a (byte-oriented) binary stream and read exactly what was stored in the object when you wrote it. CFileStream provides a stream for a file, allowing read, write and seek operations.

### Constructors

| Name       | Description |
| ---------- | ----------- |
| Constructor(File Name) | Opens or creates a file and retrieves a stream to read or write to that file. |
| Constructor(Stream) | Initializes an instance of the class from an existing Stream object and attaches it. |

```
CONSTRUCTOR CFileStream ( _
   BYVAL pwszFile AS WSTRING PTR, _
   BYVAL grfMode AS DWORD = STGM_READ, _
   BYVAL dwAttributes AS DWORD = FILE_ATTRIBUTE_NORMAL, _
   BYVAL fCreate AS WINBOOL = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFile* | A pointer to a unicode null-terminated string that specifies the file name. |
| *grfMode* | One or more STGM values that are used to specify the file access mode and how the object that exposes the stream is created and deleted. |
| *dwAttributes* | One or more flag values that specify file attributes in the case that a new file is created. |
| *fCreate* | A BOOL value that helps specify, in conjunction with *grfMode*, how existing files should be treated when creating the stream. |

```
CONSTRUCTOR CFileStream (BYVAL pstm AS IStream PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pstm* | A pointer to the IStream interface of an existing stream object that will be attached to the class. |

### Operators

| Name       | Description |
| ---------- | ----------- |
| LET | Initializes an instance of the class from an existing Stream object and attaches it. |
| CAST | Returns a pointer to the underlying IStream interface of the Stream object. |

```
OPERATOR LET (BYVAL pstm AS IStream PTR)
OPERATOR CAST () AS IStream PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pstm* | A pointer to the IStream interface of an existing stream object that will be attached to the class. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Attach](#Attach) | Attaches the passed stream object to the class. |
| [Detach](#Detach) | Detaches the stream object from the class. |
| Open | Opens or creates a file and retrieves a stream to read or write to that file. |
| Close | Releases the stream object. |
| Read | Reads a specified number of bytes from the stream object into memory, starting at the current seek pointer. |
| ReadTextA | Reads a specified number of characters from the stream object into memory, starting at the current seek pointer, and returns then as an ansi string. |
| ReadTextW | Reads a specified number of characters from the stream object into memory, starting at the current seek pointer, and returns then as a unicode string. |
| Write | Writes a specified number of bytes into the stream object starting at the current seek pointer. |
| WriteTextA | Writes a ansi string into the stream object starting at the current seek pointer. |
| WriteTextW | Writes a unicode string into the stream object starting at the current seek pointer. |
| Seek | Changes the seek pointer to a new location. The new location is relative to either the beginning of the stream, the end of the stream, or the current seek pointer. |
| GetSeekPosition | Returns the seek position. |
| ResetSeekPosition | Sets the seek position at the beginning of the stream. |
| SeekAtEndOfFile | Sets the seek position at the end of the stream. |
| GetSize | Returns the size of the stream. |
| SetSize | Changes the size of the stream object. |
| CopyTo | Copies a specified number of bytes from the current seek pointer in the stream to the current seek pointer in another stream. |
| Commit | Ensures that any changes made to a stream object open in transacted mode are reflected in the parent storage. |
| Revert | Discards all changes that have been made to a transacted stream since the last *Commit* call. On streams open in direct mode this method has no effect. |
| LockRegion | Restricts access to a specified range of bytes in the stream. |
| UnlockRegion | Removes the access restriction on a range of bytes previously restricted with *LockRegion*. |
| Stat | Retrieves the STATSTG structure for this stream. |
| Clone | Creates a new stream object with its own seek pointer that references the same bytes as the original stream. |
| GetLastResult | Returns the last result code. |

# <a name="Attach"></a>Attach

Attaches the passed stream object to the class.

```
FUNCTION Attach (BYVAL pstm AS IStream PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pstm* | A pointer to the IStream interface of an existing stream object that will be attached to the class. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

# <a name="Detach"></a>Detach

Detaches the stream object from the class.

```
FUNCTION Detach () AS IStream PTR
```

#### Return value

IStream PTR. A pointer to the IStream interface of the stream object.


