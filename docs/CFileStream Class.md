# CFileStream Class

Allows to work with binary file streams. A binary stream consists of one or more bytes of arbitrary information. **CFileStream** provides a stream for a file, allowing read, write and seek operations.

### Constructors

| Name       | Description |
| ---------- | ----------- |
| Constructor (File Name) | Opens or creates a file and retrieves a stream to read or write to that file. |
| Constructor (Stream) | Initializes an instance of the class from an existing stream and attaches it. |

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
| *grfMode* | One or more STGM values that are used to specify the file access mode and how the the stream is created and deleted. |
| *dwAttributes* | One or more flag values that specify file attributes in the case that a new file is created. |
| *fCreate* | A BOOL value that helps specify, in conjunction with *grfMode*, how existing files should be treated when creating the stream. |

```
CONSTRUCTOR CFileStream (BYVAL pstm AS IStream PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pstm* | A pointer to the IStream interface of an existing stream that will be attached to the class. |

### Operators

| Name       | Description |
| ---------- | ----------- |
| LET | Initializes the class from an existing stream and attaches it. |
| CAST | Returns a pointer to the underlying IStream interface of the stream object. |

```
OPERATOR LET (BYVAL pstm AS IStream PTR)
OPERATOR CAST () AS IStream PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pstm* | A pointer to the IStream interface of an existing stream that will be attached to the class. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Attach](#Attach) | Attaches the passed stream to the class. |
| [Detach](#Detach) | Detaches the stream from the class. |
| [Open](#Open) | Opens or creates a file and retrieves a stream to read or write to that file. |
| [Close](#Close) | Releases the stream object. |
| Read | Reads a specified number of bytes from the stream into memory, starting at the current seek pointer. |
| ReadTextA | Reads a specified number of characters from the stream into memory, starting at the current seek pointer, and returns then as an ansi string. |
| ReadTextW | Reads a specified number of characters from the stream into memory, starting at the current seek pointer, and returns then as a unicode string. |
| Write | Writes a specified number of bytes into the stream starting at the current seek pointer. |
| WriteTextA | Writes a ansi string into the stream starting at the current seek pointer. |
| WriteTextW | Writes a unicode string into the stream starting at the current seek pointer. |
| Seek | Changes the seek pointer to a new location. The new location is relative to either the beginning of the stream, the end of the stream, or the current seek pointer. |
| GetSeekPosition | Returns the seek position. |
| ResetSeekPosition | Sets the seek position at the beginning of the stream. |
| SeekAtEndOfFile | Sets the seek position at the end of the stream. |
| GetSize | Returns the size of the stream. |
| SetSize | Changes the size of the stream. |
| CopyTo | Copies a specified number of bytes from the current seek pointer in the stream to the current seek pointer in another stream. |
| Commit | Ensures that any changes made to a stream open in transacted mode are reflected in the parent storage. |
| Revert | Discards all changes that have been made to a transacted stream since the last *Commit* call. On streams open in direct mode this method has no effect. |
| LockRegion | Restricts access to a specified range of bytes in the stream. |
| UnlockRegion | Removes the access restriction on a range of bytes previously restricted with *LockRegion*. |
| Stat | Retrieves the STATSTG structure for this stream. |
| Clone | Creates a new stream with its own seek pointer that references the same bytes as the original stream. |
| GetLastResult | Returns the last result code. |

# <a name="Attach"></a>Attach

Attaches the passed stream to the class.

```
FUNCTION Attach (BYVAL pstm AS IStream PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pstm* | A pointer to the IStream interface of an existing stream that will be attached to the class. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

# <a name="Detach"></a>Detach

Detaches the stream from the class.

```
FUNCTION Detach () AS IStream PTR
```

#### Return value

IStream PTR. A pointer to the IStream interface of the stream object.

# <a name="Open"></a>Open

Opens or creates a file and retrieves a stream to read or write to that file.

```
FUNCTION Open (BYVAL pwszFile AS WSTRING PTR, _
   BYVAL grfMode AS DWORD = STGM_READ, _
   BYVAL dwAttributes AS DWORD = FILE_ATTRIBUTE_NORMAL, _
   BYVAL fCreate AS WINBOOL = FALSE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFile* | A pointer to a unicode null-terminated string that specifies the file name. |
| *grfMode* | One or more STGM values that are used to specify the file access mode and how the stream is created and deleted. The STGM constants are flags that indicate conditions for creating and deleting the stream and access modes for the stream. These elements are often combined using an ORoperator. They are interpreted in groups as listed in the following table. It is not valid to use more than one element from a single group. |
| *dwAttributes* | One or more flag values that specify file attributes in the case that a new file is created.<br>**_0_** = Prevents other processes from opening a file or device if they request delete, read, or write access.<br>**_FILE_SHARE_DELETE_** = Enables subsequent open operations on a file or device to request delete access. Otherwise, other processes cannot open the file or device if they request delete access. If this flag is not specified, but the file or device has been opened for delete access, the function fails. Delete access allows both delete and rename operations.<br>**_FILE_SHARE_READ_** = Enables subsequent open operations on a file or device to request read access. Otherwise, other processes cannot open the file or device if they request read access. If this flag is not specified, but the file or device has been opened for read access, the function fails.<br>**_FILE_SHARE_WRITE_** = Enables subsequent open operations on a file or device to request write access. Otherwise, other processes cannot open the file or device if they request write access. If this flag is not specified, but the file or device has been opened for write access or has a file mapping with write access, the function fails. |
| *fCreate* | BOOL value that helps specify, in conjunction with *grfMode*, how existing files should be treated when creating the stream |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

### STGM Constants

The STGM constants are flags that indicate conditions for creating and deleting the stream and access modes for the stream. These elements are often combined using an **OR** operator. They are interpreted in groups as listed in the following table. It is not valid to use more than one element from a single group.

| Group                       | Flag                  | Value      |
| --------------------------- | --------------------- | ---------- |
| Access                      | STGM_READ             | &h00000000 |
|                             | STGM_WRITE            | &h00000001 |
|                             | STGM_READWRITE        | &h00000002 |
| Sharing                     | STGM_SHARE_DENY_NONE  | &h00000040 |
|                             | STGM_SHARE_DENY_READ  | &h00000030 |
|                             | STGM_SHARE_DENY_WRITE | &h00000020 |
|                             | STGM_SHARE_EXCLUSIVE  | &h00000010 |
| Creation                    | STGM_CREATE           | &h00001000 |
|                             | STGM_FAILIFTHERE      | &h00000000 |
| Transactioning              | STGM_DIRECT           | &h00000000 |
|                             | STGM_TRANSACTED       | &h00010000 |

| Constant   | Meaning     |
| ---------- | ----------- |
| **STGM_READ** | Indicates that the stream is read-only, meaning that modifications cannot be made. For example, if a stream is opened with **STGM_READ**, the **Read** method may be called, but the **Write** method may not. |
| **STGM_WRITE** | Enables you to save changes to the stream, but does not permit access to its data. |
| **STGM_SHARE_DENY_NONE** | Specifies that subsequent openings of the stream are not denied read or write access. If no flag from the sharing group is specified, this flag is assumed. |
| **STGM_SHARE_DENY_READ** | Prevents others from subsequently opening the stream in **STGM_READ** mode. |
| **STGM_SHARE_DENY_WRITE** | Prevents others from subsequently opening the stream for **STGM_WRITE** or **STGM_READWRITE** access. In transacted mode, sharing of **STGM_SHARE_DENY_WRITE** or **STGM_SHARE_EXCLUSIVE** can significantly improve performance because they do not require snapshots. |
| **STGM_SHARE_EXCLUSIVE** | Prevents others from subsequently opening the stream in **STGM_READ** mode. |
| **STGM_CREATE** | Indicates that an existing stream should be removed before the new stream replaces it. A new stream is created when this flag is specified only if the existing stream has been successfully removed. This flag cannot be used with open operations. |
| **STGM_FAILIFTHERE** | Causes the create operation to fail if an existing stream with the specified name exists. In this case, **STG_E_FILEALREADYEXISTS** is returned. This is the default creation mode; that is, if no other create flag is specified, **STGM_FAILIFTHERE** is implied. |
| **STGM_DIRECT** | Indicates that, in direct mode, each change to a stream element is written as it occurs. This is the default if neither **STGM_DIRECT** nor **STGM_TRANSACTED** is specified. |
| **STGM_TRANSACTED** | Indicates that, in transacted mode, changes are buffered and written only if an explicit commit operation is called. To ignore the changes, call the **Revert** method. |

The *grfMode* and *fCreate* parameters work together to specify how the function should behave with respect to existing files.

| grfMode          | fCreate | File exists? | Behavior |
| ---------------- | ------- | ------------ | -------- |
| STGM_CREATE      | Ignored | Yes          | The file is recreated. |
| STGM_CREATE      | Ignored | No           | The file is created. |
| STGM_FAILIFTHERE | FALSE   | Yes          | The file is opened. |
| STGM_FAILIFTHERE | FALSE   | No           | The call fails. |
| STGM_FAILIFTHERE | TRUE    | Yes          | The call fails. |
| STGM_FAILIFTHERE | TRUE    | No           | The file is created. |

# <a name="Close"></a>Close

Releases the stream object.

```
FUNCTION Close
```

# <a name="Read"></a>Read

Reads a specified number of bytes from the stream object into memory, starting at the current seek pointer.

```
FUNCTION Read (BYVAL pv AS ANY PTR, BYVAL cb AS ULONG, BYVAL pcbRead AS ULONG PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pv* | A pointer to the buffer which the stream data is read into. |
| *cb* | The number of bytes of data to read from the stream object. |
| *pcbRead* | A pointer to a ULONG variable that receives the actual number of bytes read from the stream. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

```
FUNCTION Read (BYVAL pv AS ANY PTR, BYVAL cb AS ULONG) AS ULONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pv* | A pointer to the buffer which the stream data is read into. |
| *cb* | The number of bytes of data to read from the stream object. |

#### Return value

ULONG. actual number of bytes read from the stream object. Note: The number of bytes read may be zero.
