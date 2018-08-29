# CFileTime Class

This class provides methods for managing the date and time values associated with the creation, access and modification of files. The methods and data of this class are frequently used in conjunction with **CFileTimeSpan** objects, which deal with relative time values.

The date and time value is stored as a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601. This is the Coordinated Universal Time (UTC) format.

The following static const member variables are provided to simplify calculations (number of 100-nanosecond intervals):

CFileTime_Millisecond    10,000
CFileTime_Second         CFileTime_Millisecond * 1,000
CFileTime_Minute         CFileTime_Second * 60
CFileTime_Hour           CFileTime_Minute * 60
CFileTime_Day            CFileTime_Hour * 24
CFileTime_Week           CFileTime_Day * 7

**Note**: Not all file systems can record creation and last access time and not all file systems record them in the same manner. For example, on the Windows NT FAT file system, create time has a resolution of 10 milliseconds, write time has a resolution of 2 seconds, and access time has a resolution of 1 day (the access date). On NTFS, access time has a resolution of 1 hour. Furthermore, FAT records times on disk in local time, but NTFS records times on disk in UTC. 

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors) | Create new **CFileTime** objects initialized to the specified value. |
| [CAST Operator](#CastOp) | Returns the **CFileTime** value as a long integer. |
| [LET Operator](#LetOp) | Assigns a value to a **CFileTime** object. |
| [Operators](#Operators) | Adds, subtracts or compares **CFileTime** objects. |
| [Day](#Day) | Returns the number of 100-nanosecond intervals that make up one day. |
| [Format](#Format) | Converts a **CFileTime** object to a string. |
| [GetAsFileTime](#GetAsFileTime) | Returns the time as a **FILETIME** structure. |
| [GetAsSystemTime](#GetAsSystemTime) | Returns the time as a **SYSTEMTIME** structure. |
| [GetCurrentTime](#GetCurrentTime) | Returns a **CFileTime** object that represents the current system date and time. |
| [GetTime](#GetTime) | Returns the value of the **CFileTime** object. |
| [Hour](#Hour) | Returns the number of 100-nanosecond intervals that make up one hour. |
| [LocalToUTC](#LocalToUTC) | Converts a local file time to a file time based on the Coordinated Universal Time (UTC). |
| [Millisecond](#Millisecond) | Returns the number of 100-nanosecond intervals that make up one millisecond. |
| [Minute](#Minute) | Returns the number of 100-nanosecond intervals that make up one minute. |
| [Second](#Second) | Returns the number of 100-nanosecond intervals that make up one second. |
| [SetTime](#SetTime) | Sets the date and time of this **CFileTime** object. |
| [UTCToLocal](#UTCToLocal) | Converts time based on the Coordinated Universal Time (UTC) to local file time. |
| [Week](#Week) | Returns the number of 100-nanosecond intervals that make up one week. |

# CFileTimeSpan Class

This class provides methods for managing relative periods of time often encountered when performing operations concerning when a file was created, last accessed or last modified. The methods of this class are frequently used in conjunction with CFileTime class objects.

The CFileTimeSpan object can be created using an existing CFileTimeSpan object, or expressed as a 64-bit value. The default constructor sets the time span to 0.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors) | Create new **CFileTimeSpan** objects initialized to the specified value. |
| [CAST Operator](#CastOp) | Returns the **CFileTimeSpan** value as a long integer. |
| [LET Operator](#LetOp) | Assigns a value to a **CFileTimeSpan** object. |
| [Operators](#Operators) | Adds, subtracts or compares **CFileTimeSpan** objects. |
| [Day](#Day) | Returns the number of 100-nanosecond intervals that make up one day. |
| [GetTimeSpan](#GetTimeSpan) | Returns the value of the **CFileTimeSpan** object. |
| [Hour](#Hour) | Returns the number of 100-nanosecond intervals that make up one hour. |
| [Millisecond](#Millisecond) | Returns the number of 100-nanosecond intervals that make up one millisecond. |
| [Minute](#Minute) | Returns the number of 100-nanosecond intervals that make up one minute. |
| [Second](#Second) | Returns the number of 100-nanosecond intervals that make up one second. |
| [SetTimeSpan](#SetTimeSpan) | Sets the date and time of this **CFileTimeSpan** object. |
| [Week](#Week) | Returns the number of 100-nanosecond intervals that make up one week. |
