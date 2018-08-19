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
| GetLastResult | Returns the last result code. |
| HashVal | Returns the hash value for a specified key in the associative array. |
| Item | Sets or returns an item for a specified key in associative array. |
| Items | Returns a safe array containing all the items in the associative array. |
| Key | Sets or returns an item for a specified key in the associative array. |
| Keys | Returns an array containing all the keys in the associative array. |
| NewEnum | Returns a reference to the standard enumerator. |
| Remove | FUNCTION Remove (BYREF cvKey AS CVAR) AS HRESULT |
| RemoveAll | Removes all key, item pairs from the associative array. |

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

TRUE if a specified key exists in the associative array; FALSE if it does not.
