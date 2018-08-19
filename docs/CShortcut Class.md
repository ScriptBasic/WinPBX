# Shortcut Classes

**CShortcut** allows to create a shortcut programmatically.

**CURLShortcut** allows to create a URL shortcut programmatically.

### Constructors

```
CONSTRUCTOR CShortcut (BYREF cbsPathName AS CBSTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsPathName* | The full path and file name of the shortcut. |

#### Example

```
' Creates a shortcut programatically (if it already exists, opens it)
DIM pShortcut AS CShortcut = ExePath & "\Test.lnk"   ' --> change me
' Sets various properties and saves them to disk
pShortcut.Description = "Hello world"   ' --> change me
pShortcut.WorkingDirectory = ExePath & "\"   ' --> change me
pShortcut.Arguments = "/c"   ' --> change me
pShortcut.HotKey = "Ctrl+Alt+e"   ' --> change me
pShortcut.IconLocation = ExePath & "\Program.ico,0"   ' --> change me
pShortcut.RelativePath = ExePath & "\"   ' --> change me
pShortcut.TargetPath = ExePath & $"\HelloWord.exe"   ' --> change me
pShortcut.WindowStyle = WshNormalFocus
pShortcut.Save
```

```
CONSTRUCTOR CURLShortcut (BYREF cbsPathName AS CBSTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsPathName* | The full path and file name of the shortcut. |

```
' Creates a shortcut programatically (if it already exists, opens it)
DIM pURLShortcut AS CURLShortcut = ExePath & "\Microsoft Web Site.url"   ' --> change me
pURLShortcut.TargetPath = "http://www.microsoft.com"   ' --> change me
pURLShortcut.Save
```

# CShortcut Methods

| Name       | Description |
| ---------- | ----------- |
| [Save](#Save1) | Saves a shortcut object to disk. |
| [GetLastResult](#GetLastResult) | Returns the last result code. |

# CShortcut Properties

| Name       | Description |
| ---------- | ----------- |
| *Arguments* | Gets/sets the arguments for a shortcut, or identifies a shortcut's arguments. |
| *Description* | Returns or sets a shortcut's description. |
| *FullName* | Returns the fully qualified path of the shortcut object's target. |
| *Hotkey* | Assigns a key-combination to a shortcut, or identifies the key-combination assigned to a shortcut. |
| *IconLocation* | Assigns a an icon to a shortcut, or identifies the icon assigned to a shortcut. |
| *RelativePath* | Assigns a relative path to a shortcut. |
| *TargetPath* | Gets/sets the path of the shortcut's executable. |
| *WindowStyle* | Assigns a window style to a shortcut, or identifies the type of window style used by a shortcut. |
| *WorkingDirectory* | Assigns a working directory to a shortcut, or identifies the working directory used by a shortcut. |

# CURLShortcut Methods

| Name       | Description |
| ---------- | ----------- |
| [Save](#Save2) | Saves a URL shortcut object to disk. |
| [GetLastResult](#GetLastResult) | Returns the last result code. |

# CShortcut Properties

| Name       | Description |
| ---------- | ----------- |
| *FullName* | Returns the fully qualified path of the shortcut object's target. |
| *TargetPath* | Gets/sets the path of the shortcut's executable. |

# <a name="Save1"></a>Save (CShortcut)

Saves a shortcut object to disk.

```
FUNCTION Save () AS HRESULT
```

#### Remarks

After creating an instance of the *CShortcut* class to create to create a shortcut object and set the shortcut object's properties, the Save method must be used to save the shortcut object to disk. The **Save** method uses the information in the shortcut object's **FullName** property to determine where to save the shortcut object on a disk. You can only create shortcuts to system objects. This includes files, directories, and drives (but does not include printer links or scheduled tasks).

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

# <a name="Save2"></a>Save (CURLShortcut)

Saves a URL shortcut object to disk.

```
FUNCTION Save () AS HRESULT
```

#### Remarks

After creating an instance of the *CURLShortcut* class to create to create a shortcut object and set the shortcut object's properties, the Save method must be used to save the shortcut object to disk. The **Save** method uses the information in the shortcut object's **FullName** property to determine where to save the shortcut object on a disk. You can only create shortcuts to system objects. This includes files, directories, and drives (but does not include printer links or scheduled tasks).

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

# <a name="GetLastResult"></a>GetLastResult

Returns the last result code.

```
FUNCTION GetLastResult () AS HRESULT
```

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.
