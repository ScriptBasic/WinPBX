# CDicObj Class

**CDicObj** is an associative array of variants. Each item is associated with a unique key. The key is used to retrieve an individual item.

**Include file**: CDicObj.inc

### Methods and Properties

| Name  | Description |
| ---------- | ----------- |
| Add | Adds a key and item pair to the associtive array. |
| Count | Returns the number of items in the associative array. |
| DispPtr | Returns the underlying dispatch pointer. |
| Exists | Checks if a specified key exists in the associative array. |
| GetLastResult | Returns the last result code. |
| HashVal | Returns the hash value for a specified key in the associative array. |
| Item | Sets or returns an item for a specified key in associative array. |
| Items | Returns a safe array containing all the items in the associative array. |
| Key | Sets or returns an item for a specified key in the associative array. |
| Keys | Returns an array containing all the keys in the associative array. |
| NewEnum | Returns a reference to the standard enumerator. |
| Remove | FUNCTION Remove (BYREF cvKey AS CVAR) AS HRESULT |
| RemoveAll | Removes all key, item pairs from the associative array. |
