# CMemMapFile Class

`CMemMap File` is a wrapper class that encapsulates the Windows memory-mapped procedures.

A memory-mapped file contains the contents of a file in virtual memory. This mapping between a file and memory space enables an application, including multiple processes, to modify the file by reading and writing directly to the memory.

There are two types of memory-mapped files:

* Persisted memory-mapped files

  Persisted files are memory-mapped files that are associated with a source file on a disk. When the last process has finished working with the file, the data is saved to the source file on the disk. These memory-mapped files are suitable for working with extremely large source files.

* Non-persisted memory-mapped files

  Non-persisted files are memory-mapped files that are not associated with a file on a disk. When the last process has finished working with the file, the data is lost and the file is reclaimed by garbage collection. These files are suitable for creating shared memory for inter-process communications (IPC).

## Processes, Views, and Managing Memory

Memory-mapped files can be shared across multiple processes. Processes can map to the same memory-mapped file by using a common name that is assigned by the process that created the file.

To work with a memory-mapped file, you must create a view of the entire memory-mapped file or a part of it. You can also create multiple views to the same part of the memory-mapped file, thereby creating concurrent memory. For two views to remain concurrent, they have to be created from the same memory-mapped file.

Multiple views may also be necessary if the file is greater than the size of the application’s logical memory space available for memory mapping (2 GB on a 32-bit computer).

There are two types of views: stream access view and random access view. Use stream access views for sequential access to a file; this is recommended for non-persisted files and IPC. Random access views are preferred for working with persisted files.

Memory-mapped files are accessed through the operating system’s memory manager, so the file is automatically partitioned into a number of pages and accessed as needed. You do not have to handle the memory management yourself.

## Methods

| Name       | Description |
| ---------- | ----------- |
| [MapFile](#MapFile) | Maps the specified file. |
| [MapMemory](#MapMemory) | Maps the specified amount of memory. |
| [MapSharedMemory](#MapSharedMemory) | Maps shared memory. |
| [Unmap](#Unmap) | Unmaps the file or memory and closes handles. |
| [AccessData](#AccessData) | Returns a pointer to access the data in the memory mapped file. |
| [UnaccessData](#UnaccessData) | Releases the synchronization object. |
| [Flush](#Flush) | Flushes the data to the disk. |
| [GetFileHandle](#GetFileHandle) | Returns the handle of the underlying disk file. |
| [GetFileMappingHandle](#GetFileMappingHandle) | Returns the file mapping handle. |
| [GetFileSize](#GetFileSize) | Returns the size of the underlying disk file. |

# <a name="MapFile"></a>MapFile

Maps the specified file.

```
FUNCTION CMemMapFile.MapFile (BYVAL pwszFileName AS WSTRING PTR, BYVAL bReadOnly AS BOOLEAN = FALSE, _
   BYVAL dwShareMode AS DWORD = 0, BYVAL bGrowable AS BOOLEAN = FALSE, _
   BYVAL pwszMappingName AS WSTRING PTR = NULL, BYVAL pwszMutexName AS WSTRING PTR = NULL, _
   BYVAL dwStartOffset  AS CONST LONGINT = 0, BYVAL nBytesToMap AS CONST SIZE_T = 0, _
   BYVAL lpSecurityAttributes AS LPSECURITY_ATTRIBUTES = NULL) AS BOOLEAN
```

| Name       | Description |
| ---------- | ----------- |
| *pwszFileName* | The filename to map. |
| *bReadOnly* | Set it to TRUE if you don't intend to modify the file. |
| *dwShareMode* | The sharing mode of the file.<br>**0** : Prevents other processes from opening a file or device if they request delete, read, or write access.<br>**FILE_SHARE_READ** : Enables subsequent open operations on a file to request read access.<br>**FILE_SHARE_WRITE** : Enables subsequent open operations on a file to request write access. |
| *bGrowable* | IF TRUE, the underlying file will be set to be a sparse file and you won't get access violations if you write past the end of the file (Windows will grow the file silently). |
| *pwszMappingName* | The name of the file mapping object. If this parameter is NULL, the file mapping object is created without a name. |
| *pwszMutexName* | The name of the mutex object. The name is limited to MAX_PATH characters. Name comparison is case sensitive. If pwszMutexName is NULL, the mutex object is created without a name. |
| *dwStartOffset* | The high-order DWORD is the file offset where the view begins. The low-order DWORD is the file offset where the view is to begin. The combination of the high and low offsets must specify an offset within the file mapping. They must also match the memory allocation granularity of the system. That is, the offset must be a multiple of the allocation granularity. To obtain the memory allocation granularity of the system, use the **GetSystemInfo** function, which fills in the members of a SYSTEM_INFO structure. |
| *nBytesToMap* | The number of bytes of a file mapping to map to the view. All bytes must be within the maximum size specified by **CreateFileMapping**. If this parameter is 0 (zero), the mapping extends from the specified offset to the end of the file mapping. |
| *lpSecurityAttributes* | A pointer to a **SECURITY_ATTRIBUTES** structure that determines whether a returned handle can be inherited by child processes. The *lpSecurityDescriptor* member of the **SECURITY_ATTRIBUTES** structure specifies a security descriptor for a new file mapping object. If *lpAttributes* is NULL, the handle cannot be inherited and the file mapping object gets a default security descriptor. |

#### Return value

TRUE or FALSE.

# <a name="MapMemory"></a>MapMemory

Maps the specified amount of memory.

```
FUNCTION CMemMapFile.MapMemory (BYVAL pwszMappingName AS WSTRING PTR, BYVAL pwszMutexName AS WSTRING PTR, _
   BYVAL nBytesToMap AS SIZE_T, BYVAL bReadOnly AS BOOLEAN = FALSE, BYVAL dwStartOffset AS CONST LONGINT = 0, _
   BYVAL lpSecurityAttributes AS LPSECURITY_ATTRIBUTES = NULL) AS BOOLEAN
```

| Name       | Description |
| ---------- | ----------- |
| *pwszMappingName* | The name of the file mapping object. If this parameter is NULL, the file mapping object is created without a name. |
| *pwszMutexName* | The name of the mutex object. The name is limited to MAX_PATH characters. Name comparison is case sensitive. If pwszMutexName is NULL, the mutex object is created without a name. |
| *nBytesToMap* | The high-order DWORD is the maximum size of the file mapping object. The low-order DWORD of the maximum size of the file mapping object. If this parameter is 0 (zero), the maximum size of the file mapping object is equal to the current size of the file that hFile identifies. An attempt to map a file with a length of 0 (zero) fails with an error code of ERROR_FILE_INVALID. Applications should test for files with a length of 0 (zero) and reject those files. |
| *bReadOnly* | Set it to TRUE if you don't intend to modify the file. |
| *dwStartOffset* | The high-order DWORD is the file offset where the view begins. The low-order DWORD is the file offset where the view is to begin. The combination of the high and low offsets must specify an offset within the file mapping. They must also match the memory allocation granularity of the system. That is, the offset must be a multiple of the allocation granularity. To obtain the memory allocation granularity of the system, use the **GetSystemInfo** function, which fills in the members of a SYSTEM_INFO structure. |
| *lpSecurityAttributes* | A pointer to a **SECURITY_ATTRIBUTES** structure that determines whether a returned handle can be inherited by child processes. The *lpSecurityDescriptor* member of the **SECURITY_ATTRIBUTES** structure specifies a security descriptor for a new file mapping object. If *lpAttributes* is NULL, the handle cannot be inherited and the file mapping object gets a default security descriptor. |

#### Return value

TRUE or FALSE.

# <a name="MapSharedMemory"></a>MapSharedMemory

Maps shared memory.

```
FUNCTION CMemMapFile.MapSharedMemory (BYVAL pwszMappingName AS WSTRING PTR, BYVAL pwszMutexName AS WSTRING PTR, _
   BYVAL nBytesToMap AS SIZE_T, BYVAL bReadOnly AS BOOLEAN = FALSE, _
   BYVAL bInheritHandle AS BOOLEAN = FALSE, BYVAL dwStartOffset AS CONST LONGINT = 0, _
   BYVAL lpSecurityAttributes AS LPSECURITY_ATTRIBUTES = NULL) AS BOOLEAN
```

| Name       | Description |
| ---------- | ----------- |
| *pwszMappingName* | The name of the file mapping object. If this parameter is NULL, the file mapping object is created without a name. |
| *pwszMutexName* | The name of the mutex object. The name is limited to MAX_PATH characters. Name comparison is case sensitive. If pwszMutexName is NULL, the mutex object is created without a name. |
| *nBytesToMap* | The high-order DWORD is the maximum size of the file mapping object. The low-order DWORD of the maximum size of the file mapping object. If this parameter is 0 (zero), the maximum size of the file mapping object is equal to the current size of the file that hFile identifies. An attempt to map a file with a length of 0 (zero) fails with an error code of ERROR_FILE_INVALID. Applications should test for files with a length of 0 (zero) and reject those files. |
| *bReadOnly* | Set it to TRUE if you don't intend to modify the file. |
| *bInheritHandle* | If this parameter is TRUE, a process created by the **CreateProcess** function can inherit the handle; otherwise, the handle cannot be inherited. |
| *dwStartOffset* | The high-order DWORD is the file offset where the view begins. The low-order DWORD is the file offset where the view is to begin. The combination of the high and low offsets must specify an offset within the file mapping. They must also match the memory allocation granularity of the system. That is, the offset must be a multiple of the allocation granularity. To obtain the memory allocation granularity of the system, use the **GetSystemInfo** function, which fills in the members of a SYSTEM_INFO structure. |
| *lpSecurityAttributes* | A pointer to a **SECURITY_ATTRIBUTES** structure that determines whether a returned handle can be inherited by child processes. The *lpSecurityDescriptor* member of the **SECURITY_ATTRIBUTES** structure specifies a security descriptor for a new file mapping object. If *lpAttributes* is NULL, the handle cannot be inherited and the file mapping object gets a default security descriptor. |

#### Return value

TRUE or FALSE.
