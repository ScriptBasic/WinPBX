# Menu Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxAddIconToMenuItem](#AfxAddIconToMenuItem) | Converts a hIcon to a bitmap and adds it to the specified hbmpItem field of HMENU item. |
| [AfxCheckMenuItem](#AfxCheckMenuItem) | Checks a menu item. |
| [AfxDisableMenuItem](#AfxDisableMenuItem) | Disables the specified menu item. |
| [AfxEnableMenuItem](#AfxEnableMenuItem) | Enables the specified menu item. |
| [AfxGetMenuFont](#AfxGetMenuFont) | Retrieves information about the font used in menu bars. |
| [AfxGetMenuFontPointSize](#AfxGetMenuFontPointSize) | Retrieves the point size of the font used in menu bars. |
| [AfxGetMenuItemState](#AfxGetMenuItemState) | Retrieves the state of the specified menu item. |
| [AfxGetMenuItemText](#AfxGetMenuItemText) | Retrieves the text of the specified menu item. |
| [AfxGetMenuRect](#AfxGetMenuRect) | Calculates the size of a menu bar or a drop-down menu. |
| [AfxGrayMenuItem](#AfxGrayMenuItem) | Grays the specified menu item. |
| [AfxHiliteMenuItem](#AfxHiliteMenuItem) | Highlights the specified menu item. |
| [AfxIsMenuItemChecked](#AfxIsMenuItemChecked) | Returns TRUE if the specified menu item is checked; FALSE otherwise. |
| [AfxIsMenuItemDisabled](#AfxIsMenuItemDisabled) | Returns TRUE if the specified menu item is disabled; FALSE otherwise. |
| [AfxIsMenuItemEnabled](#AfxIsMenuItemEnabled) | Returns TRUE if the specified menu item is enabled; FALSE otherwise. |
| [AfxIsMenuItemGrayed](#AfxIsMenuItemGrayed) | Returns TRUE if the specified menu item is grayed; FALSE otherwise. |
| [AfxIsMenuItemHighlighted](#AfxIsMenuItemHighlighted) | Returns TRUE if the specified menu item is highlighted; FALSE otherwise. |
| [AfxIsMenuItemOwnerDraw](#AfxIsMenuItemOwnerDraw) | Returns TRUE if the specified menu item is a ownerdraw; FALSE otherwise. |
| [AfxIsMenuItemPopup](#AfxIsMenuItemPopup) | Returns TRUE if the specified menu item is a submenu; FALSE otherwise. |
| [AfxIsMenuItemSeparator](#AfxIsMenuItemSeparator) | Returns TRUE if the specified menu item is a separator; FALSE otherwise. |
| [AfxRemoveCloseMenu](#AfxRemoveCloseMenu) | Removes the system menu close option and disables the X button. |
| [AfxRightJustifyMenuItem](#AfxRightJustifyMenuItem) | Right justifies a top level menu item. |
| [AfxSetMenuItemBold](#AfxSetMenuItemBold) | Changes the text of a menu item to bold. |
| [AfxSetMenuItemState](#AfxSetMenuItemState) | Sets the state of the specified menu item. |
| [AfxSetMenuItemText](#AfxSetMenuItemText) | Sets the text of the specified menu item. |
| [AfxToggleMenuItem](#AfxToggleMenuItem) | Toggles the checked state of a menu item. |
| [AfxUnCheckMenuItem](#AfxUnCheckMenuItem) | Unchecks a menu item. |

# <a name="AfxAddIconToMenuItem"></a>AfxAddIconToMenuItem

Converts a hIcon to a bitmap and adds it to the specified *hbmpItem field* of **HMENU** item.

```
FUNCTION AfxAddIconToMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, _
   BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |
| *hIcon* | Handle of the icon to add to the menu. |
| *fAutoDestroy* | TRUE (the default) or FALSE. If TRUE, **AddIconToMenuItem** destroys the icon before returning. |
| *phbmp* | Out. Location where the bitmap representation of the icon is stored. Can be NULL. |

#### Return value

TRUE or FALSE.

#### Remarks

The caller is responsible for destroying the bitmap generated. The icon will be destroyed if *fAutoDestroy* is set to true. The *hbmpItem* field of the menu item can be used to keep track of the bitmap by passing NULL to *phbmp*.

Using **AfxGdipAddIconFromFile** or **AfxGdipIconFromRes** to load the image from a file or resource and convert it to a icon you can use alphablended .png icons.

#### Usage example

Loading the icon from disc:

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
DIM hIcon AS HICON = LoadImageW(NULL, ExePath & "\undo_32.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE)
IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
```

Loading the icon from a resource file:

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
AfxAddIconToMenuItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInstance, "IDI_UNDO_32"))
```

# <a name="AfxCheckMenuItem"></a>AfxCheckMenuItem

Checks a menu item.

```
FUNCTION AfxCheckMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

The return value specifies the previous state of the menu item (either MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.

# <a name="AfxDisableMenuItem"></a>AfxDisableMenuItem

Disables the specified menu item.

```
FUNCTION AfxDisableMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

# <a name="AfxEnableMenuItem"></a>AfxEnableMenuItem

Enables the specified menu item.

```
FUNCTION AfxEnableMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

# <a name="AfxGetMenuFont"></a>AfxGetMenuFont

Retrieves information about the font used in menu bars.

```
FUNCTION AfxGetMenuFont (BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *plfw* | Pointer to a LOGFONTW structure.

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

