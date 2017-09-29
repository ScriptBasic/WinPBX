' ########################################################################################
' Microsoft Windows
' File: CAfxFileDialog.inc
' Contents: Open/Save File Dialog class.
' Copyright (c) 2011 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXOPENFILEDIALOG_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "commdlg.inc"

' ########################################################################################
' CAfxFileDialog class.
' Note: Requires Windows 2000 or superior.
' ########################################################################################
CLASS CAfxFileDialog

   INSTANCE m_hwndOwner AS DWORD
   INSTANCE m_dwFlags AS DWORD
   INSTANCE m_dwFlagsEx AS DWORD
   INSTANCE m_dwBufLen AS DWORD
   INSTANCE m_dwFilterIndex AS DWORD
   INSTANCE m_lCustData AS LONG
   INSTANCE m_pfnHook AS DWORD
   INSTANCE m_pFiles AS IPowerCollection
   INSTANCE m_bstrTitle AS WSTRING
   INSTANCE m_bstrFilespec AS WSTRING
   INSTANCE m_bstrFilter AS WSTRING
   INSTANCE m_bstrDefaultFolder AS WSTRING
   INSTANCE m_bstrDefExt AS WSTRING
   INSTANCE m_bstrPath AS WSTRING

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      m_dwFilterIndex = 1
      m_dwBufLen = 32768   ' // 32 Kb buffer (enough for at least 126 files)
      m_pFiles = CLASS "PowerCollection"
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxFileDialog : INHERIT IAutomation

   ' =====================================================================================
   ' Gets the handle of the owner window.
   ' =====================================================================================
   PROPERTY GET hwndOwner() AS DWORD
      PROPERTY = m_hwndOwner
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the handle of the owner window.
   ' =====================================================================================
   PROPERTY SET hwndOwner (BYVAL hwndOwner AS DWORD)
      m_hwndOwner = hwndOwner
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the length of the buffer.
   ' =====================================================================================
   PROPERTY GET BufLen() AS DWORD
      PROPERTY = m_dwBufLen
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the length of the buffer.
   ' =====================================================================================
   PROPERTY SET BufLen (BYVAL dwBufLen AS DWORD)
      IF dwBufLen < 260 THEN dwBufLen = 260
      m_dwBufLen = dwBufLen
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the option flags.
   ' =====================================================================================
   PROPERTY GET Options() AS DWORD
      PROPERTY = m_dwFlags
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets flags to control the behavior of the dialog.
   ' =====================================================================================
   PROPERTY SET Options (BYVAL dwFlags AS DWORD)
      m_dwFlags = dwFlags
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the extended option flags.
   ' =====================================================================================
   PROPERTY GET OptionsEx() AS DWORD
      PROPERTY = m_dwFlagsEx
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets flags to control the behavior of the dialog.
   ' =====================================================================================
   PROPERTY SET OptionsEx (BYVAL dwFlagsEx AS DWORD)
      m_dwFlagsEx = dwFlagsEx
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the filter index.
   ' =====================================================================================
   PROPERTY GET FilterIndex() AS DWORD
      PROPERTY = m_dwFilterIndex
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the filter index.
   ' =====================================================================================
   PROPERTY SET FilterIndex (BYVAL dwFilterIndex AS DWORD)
      m_dwFilterIndex = dwFilterIndex
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the caption of the dialog.
   ' =====================================================================================
   PROPERTY GET Title () AS WSTRING
      PROPERTY = m_bstrTitle
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the caption of the dialog.
   ' =====================================================================================
   PROPERTY SET Title (BYVAL bstrTitle AS WSTRING)
      m_bstrTitle = bstrTitle
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the initial directory
   ' =====================================================================================
   PROPERTY GET DefaultFolder () AS WSTRING
      PROPERTY = m_bstrDefaultFolder
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the initial directory
   ' =====================================================================================
   PROPERTY SET DefaultFolder (BYVAL bstrDefaultFolder AS WSTRING)
      m_bstrDefaultFolder = bstrDefaultFolder
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the file name.
   ' =====================================================================================
   PROPERTY GET FileName () AS WSTRING
      PROPERTY = m_bstrFileSpec
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the file name.
   ' =====================================================================================
   PROPERTY SET FileName (BYVAL bstrFileName AS WSTRING)
      m_bstrFileSpec = bstrFileName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the caption of the dialog.
   ' =====================================================================================
   PROPERTY GET Filter () AS WSTRING
      PROPERTY = m_bstrFilter
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the caption of the dialog.
   ' =====================================================================================
   PROPERTY SET Filter (BYVAL bstrFilter AS WSTRING)
      m_bstrFilter = bstrFilter
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the default extension.
   ' =====================================================================================
   PROPERTY GET DefaultExtension () AS WSTRING
      PROPERTY = m_bstrDefExt
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the default extension.
   ' =====================================================================================
   PROPERTY SET DefaultExtension (BYVAL bstrDefExt AS WSTRING)
      m_bstrDefExt = bstrDefExt
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the callback hook procedure.
   ' =====================================================================================
   PROPERTY SET Hook (BYVAL pfnHook AS DWORD)
      m_pfnHook = pfnHook
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the custom data.
   ' =====================================================================================
   PROPERTY SET CustData (BYVAL lCustData AS DWORD)
      m_lCustData = lCustData
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the selected path.
   ' =====================================================================================
   PROPERTY GET SelectedPath () AS WSTRING
      PROPERTY = m_bstrPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a reference to the collection of selected files.
   ' =====================================================================================
   PROPERTY GET Files() AS IPowerCollection
      PROPERTY = m_pFiles
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Displays the open file dialog.
   ' =====================================================================================
   METHOD ShowOpenDialog () AS LONG
      LOCAL ix AS LONG
      LOCAL nCount AS LONG
      LOCAL bstrIdx AS WSTRING
      LOCAL bstrFiles AS WSTRING
      LOCAL bstrFileName AS WSTRING
      LOCAL ofn AS OPENFILENAMEW
      ' // If the initial directory has not been specified, assume the current directory
      IF LEN(m_bstrDefaultFolder) = 0 THEN m_bstrDefaultFolder = CURDIR$
      ' // The filename must be null terminated
      ix = INSTR(m_bstrFilespec, $NUL)
      IF ix THEN m_bstrFilespec = LEFT$(m_bstrFilespec, ix) ELSE m_bstrFilespec = m_bstrFilespec & $NUL
      ' // Fill the buffer to the max length
      IF LEN(m_bstrFilespec) < m_dwBufLen THEN m_bstrFilespec += SPACE$(m_dwBufLen - LEN(m_bstrFilespec))
      ' // Fill the members of the structure
      IF AfxGetWindowsVersion < 5 THEN
         ofn.lStructSize   = 76
      ELSE
         ofn.lStructSize   = SIZEOF(ofn)
      END IF
      ofn.hwndOwner        = m_hwndOwner
      ofn.lpstrFilter      = STRPTR(m_bstrFilter)
      ofn.nFilterIndex     = m_dwFilterIndex
      ofn.lpstrFile        = STRPTR(m_bstrFilespec)
      ofn.nMaxFile         = LEN(m_bstrFilespec)
      ofn.lpstrInitialDir  = STRPTR(m_bstrDefaultFolder)
      IF LEN(m_bstrTitle) THEN
         ofn.lpstrTitle    = STRPTR(m_bstrTitle)
      END IF
      ofn.Flags            = m_dwFlags
      IF LEN(m_bstrDefExt) THEN
         ofn.lpstrDefExt   = STRPTR(m_bstrDefExt)
      END IF
      ofn.lCustData        = m_lCustData
      ofn.lpfnHook         = m_pfnHook
      ofn.FlagsEx          = m_dwFlagsEx
      METHOD = GetOpenFilenameW(ofn)
      ' // Clear the collection
      m_pFiles.Clear
      ' // Parse the selected files
      ix = INSTR(m_bstrFilespec, $NUL & $NUL)
      IF ix THEN
         m_bstrFilespec = LEFT$(m_bstrFilespec, ix - 1)
      ELSE
         ix = INSTR(m_bstrFilespec, $NUL)
         IF ix THEN
            m_bstrFilespec = LEFT$(m_bstrFilespec, ix - 1)
         ELSE
            m_bstrFilespec = ""
         END IF
      END IF
      bstrFiles = RTRIM$(m_bstrFilespec, CHR$(0))
      nCount = PARSECOUNT(bstrFiles, CHR$(0))
      IF nCount = 1 THEN
         m_bstrPath = PATHNAME$(PATH, bstrFiles)
         m_pFiles.Add "1", PATHNAME$(NAMEX, bstrFiles)
      ELSE
         m_bstrPath = PARSE$(bstrFiles, CHR$(0), 1)
         IF RIGHT$(m_bstrPath, 1) <> "\" THEN m_bstrPath = m_bstrPath & "\"
         FOR ix = 2 TO nCount
            bstrFileName = PARSE$(bstrFiles, CHR$(0), ix)
            IF LEN(bstrFileName) THEN
               bstrIdx = FORMAT$(ix - 1)
               m_pFiles.Add bstrIdx, bstrFileName
            END IF
         NEXT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Displays the open file dialog.
   ' =====================================================================================
   METHOD ShowSaveDialog () AS LONG
      LOCAL ix AS LONG
      LOCAL nCount AS LONG
      LOCAL bstrIdx AS WSTRING
      LOCAL bstrFiles AS WSTRING
      LOCAL bstrFileName AS WSTRING
      LOCAL ofn AS OPENFILENAMEW
      ' // If the initial directory has not been specified, assume the current directory
      IF LEN(m_bstrDefaultFolder) = 0 THEN m_bstrDefaultFolder = CURDIR$
      IF LEN(m_bstrFilespec) < m_dwBufLen THEN m_bstrFilespec += SPACE$(m_dwBufLen - LEN(m_bstrFilespec))
      ' // Fill the members of the structure
      IF AfxGetWindowsVersion < 5 THEN
         ofn.lStructSize   = 76
      ELSE
         ofn.lStructSize   = SIZEOF(ofn)
      END IF
      ofn.hwndOwner        = m_hwndOwner
      ofn.lpstrFilter      = STRPTR(m_bstrFilter)
      ofn.nFilterIndex     = m_dwFilterIndex
      ofn.lpstrFile        = STRPTR(m_bstrFilespec)
      ofn.nMaxFile         = LEN(m_bstrFilespec)
      ofn.lpstrInitialDir  = STRPTR(m_bstrDefaultFolder)
      IF LEN(m_bstrTitle) THEN
         ofn.lpstrTitle    = STRPTR(m_bstrTitle)
      END IF
      ofn.Flags            = m_dwFlags
      IF LEN(m_bstrDefExt) THEN
         ofn.lpstrDefExt   = STRPTR(m_bstrDefExt)
      END IF
      ofn.lCustData        = m_lCustData
      ofn.lpfnHook         = m_pfnHook
      ofn.FlagsEx          = m_dwFlagsEx
      METHOD = GetSaveFilenameW(ofn)
      ' // Clear the collection
      m_pFiles.Clear
      ' // Parse the selected file name
      ix = INSTR(m_bstrFilespec, $NUL)
      IF ix THEN
         m_bstrFilespec = LEFT$(m_bstrFilespec, ix - 1)
      ELSE
         m_bstrFilespec = ""
      END IF
      ' // Return a full path
      m_bstrPath = m_bstrFilespec
   END METHOD
   ' =====================================================================================

   END INTERFACE
   ' =====================================================================================

END CLASS
' ########################################################################################
