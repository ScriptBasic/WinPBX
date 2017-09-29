' ########################################################################################
' TypeLib Browser
' File: TLB_ENUMTLBS.INC
' Contents: Enumerates type libraries
' Compiler: PowerBASIC for Windows 10
' Headers: Windows API Headers III
' Copyright (c) 2012-2014 José Roca. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Converts short paths to long paths.
' Use GetLongPathName with Windows 98 or superior, and an alternate way with Windows 95
' and Windows NT, that doesn't support this function.
' ========================================================================================
FUNCTION TLB_ShortPathToLongPath (BYVAL strPath AS WSTRING) AS WSTRING

   LOCAL dwLen    AS DWORD
   LOCAL vi       AS OSVERSIONINFO
   LOCAL iPos     AS LONG
   LOCAL iSafety  AS LONG
   LOCAL strTemp  AS STRING
   LOCAL strNew   AS STRING
   LOCAL szPath   AS WSTRINGZ * %MAX_PATH

   IF LEN(strPath) = 0 THEN EXIT FUNCTION
   vi.dwOsVersionInfoSize = SIZEOF(vi)
   GetVersionEx vi
   IF ((vi.dwPlatformId = %VER_PLATFORM_WIN32_WINDOWS) AND (vi.dwMinorVersion <> 0) OR _
      vi.dwMajorVersion => 5) AND INSTR(strPath, "%") = 0 THEN
      dwLen = GetLongPathName(BYCOPY strPath, szPath, %MAX_PATH)
      FUNCTION = szPath
   ELSE
      DO UNTIL TALLY(strPath, "%") < 2
         iPos = INSTR(1, strPath, "%")   ' // Get first position
         strTemp = MID$(strPath, iPos + 1, (INSTR(iPos + 1, strPath, "%") - (iPos + 1)))
         strNew = ENVIRON$(strTemp)
         IF LEN(strNew) THEN REPLACE "%" + strTemp + "%" WITH strNew IN strPath
         INCR iSafety
         IF iSafety > 5 THEN EXIT LOOP   ' // If we find more than 5 vars...  something is wrong
      LOOP
      FUNCTION = strPath
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for the win32 subkey.
' ========================================================================================
FUNCTION TLB_RegSearchWin32 (BYREF szKey AS WSTRINGZ) AS WSTRING

   LOCAL hr        AS LONG
   LOCAL dwIdx     AS DWORD
   LOCAL ft        AS FILETIME
   LOCAL hKey      AS DWORD
   LOCAL szKeyName AS WSTRINGZ * %MAX_PATH
   LOCAL szClass   AS WSTRINGZ * %MAX_PATH

   ' // Recursively searches for the win32 directory
   DO
      hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      IF hKey = 0 THEN EXIT FUNCTION
      hr = RegEnumKeyEx (hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr THEN EXIT DO
      IF UCASE$(szKeyName) = "WIN32" THEN EXIT DO
      dwIdx = dwIdx + 1
   LOOP WHILE hr = 0

   ' // Closes the registry and returns the result
   RegCloseKey hKey
   IF hr <> 0 OR szKeyName = "" THEN EXIT FUNCTION
   FUNCTION = szKey

END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for the win16 subkey.
' ========================================================================================
FUNCTION TLB_RegSearchWin16 (BYREF szKey AS WSTRINGZ) AS WSTRING

   LOCAL hr        AS LONG
   LOCAL dwIdx     AS DWORD
   LOCAL ft        AS FILETIME
   LOCAL hKey      AS DWORD
   LOCAL szKeyName AS WSTRINGZ * %MAX_PATH
   LOCAL szClass   AS WSTRINGZ * %MAX_PATH

   dwIdx = 0
   DO
   hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      IF hKey = 0 THEN EXIT FUNCTION
      hr = RegEnumKeyEx(hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr THEN EXIT DO
      IF UCASE$(szKeyName) = "WIN16" THEN EXIT DO
      dwIdx = dwIdx + 1
   LOOP WHILE hr = 0

   ' // Closes the registry and returns the result
   RegCloseKey hKey
   IF hr <> 0 OR szKeyName = "" THEN EXIT FUNCTION
   FUNCTION = szKey

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the path of the typelib.
' ========================================================================================
FUNCTION TLB_RegEnumDirectory (BYVAL strKey AS WSTRING) AS WSTRING

   LOCAL hr          AS LONG
   LOCAL dwIdx       AS DWORD
   LOCAL ft          AS FILETIME
   LOCAL hKey        AS DWORD
   LOCAL KeyType     AS DWORD
   LOCAL cValueName  AS DWORD
   LOCAL cbData      AS DWORD
   LOCAL IsWin32     AS LONG
   LOCAL strSubkey   AS WSTRING
   LOCAL szKey       AS WSTRINGZ * %MAX_PATH
   LOCAL szKeyName   AS WSTRINGZ * %MAX_PATH
   LOCAL szClass     AS WSTRINGZ * %MAX_PATH
   LOCAL szValueName AS WSTRINGZ * %MAX_PATH
   LOCAL szKeyValue  AS WSTRINGZ * %MAX_PATH

   ' // Searches the HKEY_CLASSES_ROOT\TypeLib\<LIBID> node.
   szKey = strKey
   hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
   IF hKey = 0 THEN EXIT FUNCTION
   dwIdx = 0
   DO
      hr = RegEnumKeyEx(hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr THEN EXIT DO
      strSubkey = TLB_RegSearchWin32(szKey & "\" & szKeyName)
      IF LEN(strSubkey) THEN
         IsWIn32 = -1
         EXIT DO
      END IF
      strSubkey = TLB_RegSearchWin16(szKey & "\" & szKeyName)
      IF LEN(strSubkey) THEN EXIT DO
      dwIdx += 1
   LOOP
   RegCloseKey hKey
   IF hr <> 0 OR strSubkey = "" THEN EXIT FUNCTION

   ' // win32 node
   IF ISTRUE IsWin32 THEN
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      szKey = strSubkey & "\" & "win32"
      hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      hr = RegEnumValue(hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
   ELSE
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      szKey = strSubkey & "\" & "win16"
      hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      hr = RegEnumValue(hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
   END IF

   ' // Closes the registry and returns the value
   RegCloseKey hKey
   FUNCTION = szKeyValue

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the different versions of the typelib.
' ========================================================================================
FUNCTION TLB_RegEnumVersions (BYVAL hListView AS DWORD, BYREF szCLSID AS WSTRINGZ) AS LONG

   LOCAL hr          AS LONG
   LOCAL hKey        AS DWORD
   LOCAL dwIdx       AS DWORD
   LOCAL PathPos     AS LONG
   LOCAL i           AS LONG
   LOCAL KeyType     AS DWORD
   LOCAL cValueName  AS DWORD
   LOCAL cbData      AS DWORD
   LOCAL hVerKey     AS DWORD
   LOCAL verIdx      AS DWORD
   LOCAL lItemIdx    AS LONG
   LOCAL ft          AS FILETIME
   LOCAL tlvi        AS LVITEM
   LOCAL szKey       AS WSTRINGZ * %MAX_PATH
   LOCAL szKeyName   AS WSTRINGZ * 255
   LOCAL szClass     AS WSTRINGZ * %MAX_PATH
   LOCAL szValueName AS WSTRINGZ * 16383
   LOCAL szKeyValue  AS WSTRINGZ * %MAX_PATH
   LOCAL szTemp      AS WSTRINGZ * %MAX_PATH
   LOCAL szDesc      AS WSTRINGZ * %MAX_PATH
   LOCAL szPath      AS WSTRINGZ * %MAX_PATH
   LOCAL szFile      AS WSTRINGZ * %MAX_PATH
   LOCAL strVer      AS WSTRING

   IF hListView = %NULL OR VARPTR(szCLSID) = %NULL OR szCLSID = "" THEN EXIT FUNCTION

   ' // Searches the HKEY_CLASSES_ROOT\TypeLib\<LIBID> node.
   szKey = "TypeLib\" & szCLSID
   hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
   IF hKey = 0 THEN EXIT FUNCTION

   ' // Opens the subtrees of the different versions of the TyleLib library
   dwIdx = 0
   DO
      hr = RegEnumKeyEx(hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr <> %ERROR_SUCCESS THEN EXIT DO
      ' // Gets the default value
      hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey & "\" & szKeyName, 0, %KEY_READ, hVerKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT DO
      strVer = szKeyName
      ' // Enumerate the entries until the default one, if any, is found.
      ' // RegEnumValue returns values in any order. This includes unnamed values.
      ' // A key may have one unnamed value. An unnamed value is displayed as (Default)
      ' // in Regedit.exe. If an unnamed value doesn't exist under a given key, it is
      ' // displayed as (value not set) in Regedit.exe.
      ' // Only existing unnamed values can be enumerated. If an unnamed value is enumerated, the
      ' // RegEnumValue function sets szValueName to an empty string ("") and it sets cValueName to 0.
      verIdx = 0
      DO
         cValueName = 16383
         cbData     = %MAX_PATH * 2
         szValueName = ""
         szKeyValue = ""
         hr = RegEnumValue(hVerKey, verIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
         IF szValueName = "" THEN EXIT DO   ' // This is the default, unnamed value
         IF hr <> %ERROR_SUCCESS THEN EXIT DO
         ' // Increment the index of the value to be retrieved.
         verIdx += 1
      LOOP
      ' // Closes the handle of the registry key
      RegCloseKey hVerKey
      ' // If szValueName is an empty string, assume that the value name is the key value.
      IF szValueName = "" THEN szDesc = szKeyValue ELSE szDesc = szValueName
      ' // Increment the index of the subkey
      dwIdx += 1
      ' // Find the path of the type library
      szPath = TLB_RegEnumDirectory(szKey & "\" & szKeyName)
      ' // If there is not path, skip the typelib because we can't retrieve it
      IF LEN(szPath) = 0 THEN ITERATE DO
      ' // Remove double quotes (if any)
      szPath = REMOVE$(szPath, $DQ)
      ' // Convert short paths to long paths
      ' // Dont use it with all files or these ending with version numbers
      ' // (a \ and a number) will we skipped.
      IF INSTR(szPath, "~") <> 0 OR INSTR(szPath, "%") <> 0 THEN szPath = TLB_ShortPathToLongPath(szPath)
      PathPos = INSTR(-1, szPath, "\")
      szFile = MID$(szPath, PathPos + 1)
      ' // Some have added a backslah and a number
      IF INSTR(szFile, ".") = 0 THEN
         i = -(LEN(szFile) + 2)
         PathPos = INSTR(i, szPath, "\")
         szFile = UCASE$(MID$(szPath, PathPos + 1))
      END IF
      szFile = UCASE$(szFile)
      ' // Skip .OCA files
      szTemp = szPath
      IF MID$(szTemp, -2, 1) = "\" THEN szTemp = LEFT$(szTemp, LEN(szTemp) - 2)
      IF MID$(szTemp, -3, 1) = "\" THEN szTemp = LEFT$(szTemp, LEN(szTemp) - 3)
      ' // .OCA files are created by Visual Basic (we don't need them)
      IF UCASE$(RIGHT$(szTemp, 4)) = ".OCA" THEN szPath = ""
      IF LEN(szPath) THEN
         ' // If the description is empty, use the file name
         IF szDesc = "" THEN szDesc = "[" & szFile & "]"
         ' // Add the version number
         szDesc += " (Ver " & strVer & ")"
         ' // Add the items ro the list view
         lItemIdx = ListView_AddItem(hListView, 0, 0, szDesc)
         ListView_SetItemText(hListView, lItemIdx, 1, szFile)
         ListView_SetItemText(hListView, lItemIdx, 2, szPath)
         ListView_SetItemText(hListView, lItemIdx, 3, szCLSID)
      END IF
   LOOP

   ' // Closes the registry key
   RegCloseKey hKey

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates all the typelibs.
' ========================================================================================
FUNCTION TLB_RegEnumTypeLibs (BYVAL hListView AS DWORD) AS LONG

   LOCAL hr        AS LONG
   LOCAL dwIdx     AS DWORD
   LOCAL ft        AS FILETIME
   LOCAL hKey      AS DWORD
   LOCAL szKey     AS WSTRINGZ * %MAX_PATH
   LOCAL szKeyName AS WSTRINGZ * %MAX_PATH
   LOCAL szClass   AS WSTRINGZ * %MAX_PATH

   IF hListView = %NULL THEN EXIT FUNCTION

   ' // Opens the HKEY_CLASSES_ROOT\TypeLib subtree.
   szKey = "TypeLib"
   hr = RegOpenKeyEx(%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
   IF hKey = 0 THEN EXIT FUNCTION
   dwIdx = 0
   ' // Parses all the TypeLib subtree and gets the CLSIDs of all the TypeLibs.
   DO
      hr = RegEnumKeyEx(hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr <> %ERROR_SUCCESS THEN EXIT DO
      TLB_RegEnumVersions hListView, szKeyName
      dwIdx = dwIdx + 1
   LOOP

   ' // Closes the registry
   RegCloseKey hKey

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sorts the items of the listview
' ========================================================================================

TYPE TLB_ITEMDATA
  strCol0 AS WSTRING * %MAX_PATH
  strCol1 AS WSTRING * %MAX_PATH
  strCol2 AS WSTRING * %MAX_PATH
  strCol3 AS WSTRING * %MAX_PATH
END TYPE

FUNCTION TLB_ListviewSortItems (BYVAL hListView AS DWORD) AS LONG

   LOCAL i         AS LONG
   LOCAL lItemIdx  AS LONG
   LOCAL tlvi      AS LVITEM
   LOCAL nCount    AS LONG
   LOCAL nItem     AS LONG
   DIM   atid (0)  AS TLB_ITEMDATA
   LOCAL szValue   AS WSTRINGZ * %MAX_PATH
   LOCAL szSelItem AS WSTRINGZ * 260

   ' // Retrieve the selected item to restore it later
   LOCAL iItem AS LONG
   iItem = ListView_GetSelectionMark(hListView)
   IF iItem THEN szSelItem = ListView_GetText(hListView, iItem, 0)

   IF pTLB.PrevColSort <> pTLB.ColumnToSort THEN
      pTLB.PrevColSort = pTLB.ColumnToSort
      pTLB.ColumnSortOrder = "DESCEND"
   ELSE
      IF pTLB.ColumnSortOrder = "DESCEND" THEN pTLB.ColumnSortOrder = "ASCEND" ELSE pTLB.ColumnSortOrder = "DESCEND"
   END IF

   IF hListView = %NULL THEN EXIT FUNCTION
   nCount = ListView_GetItemCount(hListView)
   IF nCount = 0 THEN EXIT FUNCTION
   REDIM atid(nCount - 1)

   FOR i = 0 TO nCount - 1
      atid(i).strCol0 = ListView_GetText(hListView, i, 0)
      atid(i).strCol1 = ListView_GetText(hListView, i, 1)
      atid(i).strCol2 = ListView_GetText(hListView, i, 2)
      atid(i).strCol3 = ListView_GetText(hListView, i, 3)
   NEXT

   IF pTLB.ColumnSortOrder = "DESCEND" THEN
      SELECT CASE pTLB.ColumnToSort
         CASE 0 : ARRAY SORT atid(), FROM 1 TO %MAX_PATH, COLLATE UCASE, DESCEND
         CASE 1 : ARRAY SORT atid(), FROM (%MAX_PATH * 1 * 2) + 1 TO (%MAX_PATH * 2 * 2), COLLATE UCASE, DESCEND
         CASE 2 : ARRAY SORT atid(), FROM (%MAX_PATH * 2 * 2) + 1 TO (%MAX_PATH * 3 * 2), COLLATE UCASE, DESCEND
         CASE 3 : ARRAY SORT atid(), FROM (%MAX_PATH * 3 * 2) + 1 TO (%MAX_PATH * 4 * 2), COLLATE UCASE, DESCEND
      END SELECT
   ELSE
      SELECT CASE pTLB.ColumnToSort
         CASE 0 : ARRAY SORT atid(), FROM 1 TO %MAX_PATH, COLLATE UCASE, ASCEND
         CASE 1 : ARRAY SORT atid(), FROM (%MAX_PATH * 1 * 2) + 1 TO (%MAX_PATH * 2 * 2), COLLATE UCASE, ASCEND
         CASE 2 : ARRAY SORT atid(), FROM (%MAX_PATH * 2 * 2) + 1 TO (%MAX_PATH * 3 * 2), COLLATE UCASE, ASCEND
         CASE 3 : ARRAY SORT atid(), FROM (%MAX_PATH * 3 * 2) + 1 TO (%MAX_PATH * 4 * 2), COLLATE UCASE, ASCEND
      END SELECT
   END IF

   ' // Deletes all the items
   ListView_DeleteAllItems(hListView)

   ' // Disables redraw to minimize flicker
   AfxDisableWindowRedraw(hListView)

   ' // Inserts the sorted items
   FOR i = 0 TO nCount - 1
      lItemIdx = ListView_AddItem(hListView, 0, 0, TRIM$(atid(i).strCol0))
      ListView_SetItemText(hListView, lItemIdx, 1, TRIM$(atid(i).strCol1))
      ListView_SetItemText(hListView, lItemIdx, 2, TRIM$(atid(i).strCol2))
      ListView_SetItemText(hListView, lItemIdx, 3, TRIM$(atid(i).strCol3))
   NEXT

   ' // Restore the selected item
   nItem = ListView_FindString(hListView, szSelItem)
   IF iItem THEN
      ListView_SetItemState(hListView, nItem, %LVIS_SELECTED OR %LVIS_FOCUSED, %LVIS_SELECTED OR %LVIS_FOCUSED)
      ListView_EnsureVisible(hListView, nItem, %TRUE)
   END IF

   ' // Enables redraw and repaints the control
   AfxEnableWindowRedraw(hListView)
   AfxRedrawWindow(hListView)

END FUNCTION
' ========================================================================================
