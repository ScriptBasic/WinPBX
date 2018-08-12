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
