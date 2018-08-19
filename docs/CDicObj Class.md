# CDicObj Class

**CDicObj** is an associative array of variants. Each item is associated with a unique key. The key is used to retrieve an individual item.

**Include file**: CDicObj.inc

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [Add](#Add) | Adds a key and item pair to the associtive array. |
| [Count](#Count) | Returns the number of items in the associative array. |
| [DispPtr](#DispPtr) | Returns the underlying dispatch pointer. |
| [Exists](#Exists) | Checks if a specified key exists in the associative array. |
| [GetLastResult](#GetLastResult) | Returns the last result code. |
| [HashVal](#HashVal) | Returns the hash value for a specified key in the associative array. |
| [Item](#Item) | Sets or returns an item for a specified key in associative array. |
| [Items](#Items) | Returns a safe array containing all the items in the associative array. |
| [Key](#Key) | Sets or returns an item for a specified key in the associative array. |
| [Keys](#Keys) | Returns an array containing all the keys in the associative array. |
| [NewEnum](#NewEnum) | Returns a reference to the standard enumerator. |
| [Remove](#Remove) | FUNCTION Remove (BYREF cvKey AS CVAR) AS HRESULT |
| [RemoveAll](#RemoveAll) | Removes all key, item pairs from the associative array. |

# <a name="Add"></a>Add

Adds a key and item pair to the associtive array.

```
FUNCTION Add (BYREF cbKey AS CVAR, BYREF cvItem AS CVAR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cvKey* | The key associated with the item being added. |
| *cvItem* | The item associated with the key being added. |

#### Return value

An error occurs if the key already exists.

# <a name="DispPtr"></a>DispPtr

Returns the underlying dispatch pointer.

```
FUNCTION DispPtr () AS ANY PTR
```

#### Remark

As it is a raw pointer, don't call IUnknown_Release on it.

# <a name="Count"></a>Count

Returns the number of items in the associative array.

```
FUNCTION Count () AS LONG
```

# <a name="Exists"></a>Exists

Checks if a specified key exists in the associative array.

```
FUNCTION Exists (BYREF cvKey AS CVAR) AS BOOLEAN
```

#### Return value

# <a name="GetLastResult"></a>GetLastResult

Returns the last result code.

```
FUNCTION GetLastResult () AS HRESULT
```

# <a name="HashVal"></a>HashVal

Returns the hash value for a specified key in the associative array.

```
FUNCTION HashVal (BYREF cvKey AS CVAR) AS CVAR
```

# <a name="Item"></a>Item

Sets or returns an item for a specified key in associative array.

```
PROPERTY Item (BYREF cvKey AS CVAR) AS CBSTR
PROPERTY Item (BYREF cvKey AS CVAR, BYREF cvNewItem AS CVAR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *cvKey* | Key associated with the item being retrieved or added. |
| *cvNewvItem* | The new value associated with the specified key. |

#### Return value

The item value.

#### Remarks

If key is not found when changing an item, a new key is created with the specified *cvNewvItem*. If key is not found when attempting to return an existing item, a new key is created and its corresponding item is left empty.
