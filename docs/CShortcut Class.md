# Shortcut Classes

**CShortcut** allows to create a shortcut programmatically.

**CURLShortcut** allows to create a URL shortcut programmatically.

# Constructors

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
