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
