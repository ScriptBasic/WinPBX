' ########################################################################################
' CSED Editor
' File: CSED_MENU.INC
' Contents: CSED editor menu and keyboard accelerators
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Creates a table of keyboard accelerators
' ========================================================================================
FUNCTION CSED_CreateAcceleratorTable (BYVAL pWindow AS IWindow) AS DWORD

   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F1,     %IDM_HELP                ' // F1            - Context help
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F2,     %IDM_NEXTBOOKMARK        ' // F2            - Next bookmark
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F3,     %IDM_FINDNEXT            ' // F3            - Find next
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F4,     %IDM_CODEFINDER          ' // F4            - Codefinder combobox
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F5,     %IDM_COMPILEANDRUN       ' // F5            - Compile and execute
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F6,     %IDM_COMPILEANDDEBUG     ' // F6            - Compile and debug
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F7,     %IDM_PBFORMS             ' // F7            - PBFORMS
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F8,     %IDM_TOGGLE              ' // F8            - Toggle current fold
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F9,     %IDM_CODEKEEPER          ' // F9            - Code keeper
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F10,    %IDM_MSGBOXDESIGNER      ' // F10           - Message box designer
   pWindow.AddAccelerator %FVIRTKEY,                         %VK_F11,    %IDM_TOOLS               ' // F11           - External tools

   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_F2,     %IDM_TOGGLEBOOKMARK      ' // Ctrl+F2       - Togle bookmark
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_F4,     %IDM_CLOSEFILE           ' // Ctr+F4        - Close file
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_F5,     %IDM_COMPILE             ' // Ctr+F5        - Compile
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_F8,     %IDM_TOGGLEALL           ' // Ctrl+F8       - Toggle current fold and all below
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_F10,    %IDM_VISDES              ' // Ctrl+F10      - Visual designer
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_SPACE,  %IDM_AUTOCOMPLETE        ' // Ctrl+Spacebar - Autocomplete (same as Ctrl+Enter)
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_RETURN, %IDM_AUTOCOMPLETE        ' // Ctrl+Enter    - Autocomplete
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "B",        %IDM_FORMATREGION        ' // Ctrl+B        - Formats selected text
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "E",        %IDM_COMPILEANDRUN       ' // Ctrl+E        - Compile and execute
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "F",        %IDM_FIND                ' // Ctrl+F        - Find
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "G",        %IDM_GOTOLINE            ' // Ctrl+G        - Go to line...
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "K",        %IDM_REDO                ' // Ctrl+K        - Redo
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "M",        %IDM_COMPILE             ' // Ctrl+M        - Compile
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "N",        %IDM_NEW                 ' // Ctrl+N        - New
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "O",        %IDM_OPEN                ' // Ctrl+O        - Open
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "P",        %IDM_PRINT               ' // Ctrl+P        - Print
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "Q",        %IDK_COMMENT             ' // Ctrl+Q        - Block comment
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "R",        %IDM_REPLACE             ' // Ctrl+R        - Find and replace
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "S",        %IDM_SAVE                ' // Ctrl+S        - Save As...
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "W",        %IDM_SWITCHWINDOW        ' // Ctrl+W        - Switch window
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            "Y",        %IDM_LINEDELETE          ' // Ctrl+Y        - Delete line

   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_F4,     %IDM_EXIT                ' // Alt+F4        - Exit the editor
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_F7,     %IDM_GOTOSELFILE         ' // Alt+F7        - Goto or load the file with has the same name as the one under the caret
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_F8,     %IDM_FOLDALL             ' // Alt+F8        - Fold all
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                "X",        %IDM_EXIT                ' // Alt+X         - Quit the application

   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT,              %VK_F2,     %IDM_PREVIOUSBOOKMARK    ' // Shift+F2      - Previous bookmark
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT,              %VK_F3,     %IDM_FINDBACKWARDS       ' // Shift+F3      - Search backwards
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT,              %VK_F8,     %IDM_UNFOLDALL           ' // Shift+F8      - Expand all

   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, %VK_F2,     %IDM_DELETEBOOKMARKS     ' // Ctrl+Shift+F2 - Delete bookmarks
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "A",        %IDM_AUTOINDENT          ' // Ctrl+Shift+A  - Auto indentation on/off
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "D",        %IDM_SHOWEOL             ' // Ctrl+Shift+D  - Show/hide end of lines
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "G",        %IDM_SHOWEDGE            ' // Ctrl+Shift+G  - Show/hide edge
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "I",        %IDM_SHOWINDENT          ' // Ctrl+Shift+I  - Show/hide indentation lines
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "L",        %IDM_SHOWLINENUM         ' // Ctrl+Shift+L  - Show/hide line numbers
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "M",        %IDM_SHOWMARGIN          ' // Ctrl+Shift+M  - Show/hide margin
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "Q",        %IDK_UNCOMMENT           ' // Ctrl+Shift+Q  - Block uncomment
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "T",        %IDM_USETABS             ' // Ctrl+Shift+T  - Use tabs on/off
   pWindow.AddAccelerator %FVIRTKEY OR %FSHIFT OR %FCONTROL, "W",        %IDM_SHOWSPACES          ' // Ctrl+Shift+W  - Show/hide white spaces

   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   %VK_F1,     %IDM_HELPCONTENTS        ' // Ctrl+Alt+F1   - Help contents
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   %VK_F2,     %IDM_HELPINDEX           ' // Ctrl+Alt+F2   - Help index
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   %VK_F3,     %IDM_HELPSEARCH          ' // Ctrl+Alt+F3   - Help search
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   %VK_UP,     %IDM_GOTOBEGINTHISPROC   ' // Ctrl+Alt+Up arrow - Goto to the begining of the current procedure or function
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   %VK_DOWN,   %IDM_GOTOENDTHISPROC     ' // Ctrl+Alt+Down arrow - Goto to the end of the current procedure or function
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   "F",        %IDM_WINDOWSFIND         ' // Ctrl+Alt+F    - Windows Find
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   "G",        %IDM_INSERTGUID          ' // Ctrl+Alt+G    - Insert GUID
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   "L",        %IDM_SELTOLOWERCASE      ' // Ctrl+Alt+L    - Convert selected text to lower case
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   "M",        %IDM_SELTOMIXEDCASE      ' // Ctrl+Alt+M    - Convert selected text to mixed case
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   "O",        %IDM_DOS                 ' // Ctrl+Alt+O    - Command prompt
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FALT,   "U",        %IDM_SELTOUPPERCASE      ' // Ctrl+Alt+U    - Convert selected text to upper case

   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, %VK_UP,     %IDM_GOTOBEGINPROC       ' // Ctrl+Shift+Up arrow - Goto to the begining of the procedure or function
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, %VK_DOWN,   %IDM_GOTOENDPROC         ' // Ctrl+Shift+Down arrow - Goto to the end of the procedure or function
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "B",        %IDM_TABULATEREGION      ' // Ctrl+Shift+B  - Tabulates text
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "E",        %IDM_EXECUTE             ' // Ctrl+Shift+E  - Execute without compiling
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "F",        %IDM_FINDINFILES         ' // Ctrl+Shift+F  - Find in Files (Gotcha)
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "K",        %IDM_CHARMAP             ' // Ctrl+Shift+K  - Charmap
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "N",        %IDM_NOTEPAD             ' // Ctrl+Shift+N  - Notepad
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "O",        %IDM_EXPLORER            ' // Ctrl+Shift+E  - Launches Explorer
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "P",        %IDM_MSPAINT             ' // Ctrl+Shift+P  - Microsoft Paint
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "R",        %IDM_RUNFILEDLG          ' // Ctrl+Shift+R  - Run file dialog
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "S",        %IDM_SHOWPROCNAME        ' // Ctrl+Shift+S  - Show procedure/function name
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL OR %FSHIFT, "U",        %IDM_COMPILE             ' // Ctrl+Shift+U  - Calculator

   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_0,      %IDM_ALT0                ' // Alt+0         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_1,      %IDM_ALT1                ' // Alt+1         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_2,      %IDM_ALT2                ' // Alt+2         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_3,      %IDM_ALT3                ' // Alt+3         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_4,      %IDM_ALT4                ' // Alt+4         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_5,      %IDM_ALT5                ' // Alt+5         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_6,      %IDM_ALT6                ' // Alt+6         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_7,      %IDM_ALT7                ' // Alt+7         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_8,      %IDM_ALT8                ' // Alt+8         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FALT,                %VK_9,      %IDM_ALT9                ' // Alt+9         - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_0,      %IDM_CTRL0               ' // Ctrl+0        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_1,      %IDM_CTRL1               ' // Ctrl+1        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_2,      %IDM_CTRL2               ' // Ctrl+2        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_3,      %IDM_CTRL3               ' // Ctrl+3        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_4,      %IDM_CTRL4               ' // Ctrl+4        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_5,      %IDM_CTRL5               ' // Ctrl+5        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_6,      %IDM_CTRL6               ' // Ctrl+6        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_7,      %IDM_CTRL7               ' // Ctrl+7        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_8,      %IDM_CTRL8               ' // Ctrl+8        - Macros
   pWindow.AddAccelerator %FVIRTKEY OR %FCONTROL,            %VK_9,      %IDM_CTRL9               ' // Ctrl+9        - Macros

   FUNCTION = pWindow.CreateAcceleratorTable

END FUNCTION
' ========================================================================================

' ========================================================================================
' Builds and attaches the menu
' ========================================================================================
FUNCTION CSED_CreateMenu (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hMenu AS DWORD
   LOCAL hPopUpMenu AS DWORD
   LOCAL hPopUpSubmenu AS DWORD

   hMenu = CreateMenu
   pSed.hMenu = hMenu
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuFile = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&File"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_NEW, "&New" & $TAB & "Ctrl+N"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_OPEN, "&Open..." & $TAB & "Ctrl+O"
         hPopUpSubmenu = CreatePopUpMenu
         pSed.hSubMenuRecentFiles = hPopUpSubmenu
            AppendMenu hPopUpMenu, %MF_POPUP OR %MF_ENABLED, hPopUpSubmenu, "&Recent Files..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_INSERTFILE, "&Insert File..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SAVE, "&Save" & $TAB & "Ctrl+S"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SAVEAS, "Save &As..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SAVEALL, "Save All"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLOSEFILE, "&Close" & $TAB & "Ctrl+F4"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLOSEALL, "Close A&ll Files"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CHDIR, "Ch&Dir to File Path"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PRINT, "&Print..." & $TAB & "Ctrl+P"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FILEPROPERTIES, "File Properties"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SYSINFO, "System Information"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_DOS, "Comman&d Prompt" & $TAB & "Ctrl+Alt+O"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_EXIT, "E&xit" & $TAB & "Alt+F4"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuEdit = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Edit"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_UNDO, "&Undo" & $TAB & "Ctrl+Z"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_REDO, "Red&o" & $TAB & "Ctrl+K"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_LINEDELETE, "&Delete Line" & $TAB & "Ctrl+Y"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLEAR, "Clea&r"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLEARALL, "Cl&ear All"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CUT, "Cu&t" & $TAB & "Ctrl+X"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COPY, "&Copy" & $TAB & "Ctrl+C"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PASTE, "&Paste" & $TAB & "Ctrl+V"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SELECTALL, "Select &All" & $TAB & "Ctrl+A"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         hPopUpSubmenu = CreatePopUpMenu
         pSed.hSubMenuBlockOperations = hPopUpSubmenu
            AppendMenu hPopUpMenu, %MF_POPUP OR %MF_ENABLED, hPopUpSubmenu, "&Block Operations"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_BLOCKINDENT, "Block &Indent" & $TAB & "Tab"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_BLOCKUNINDENT, "Block &Unindent" & $TAB & "Shift+Tab"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_COMMENT, "&Block Comment" & $TAB & "Ctrl+Q"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_UNCOMMENT, "Bloc&k Uncomment" & $TAB & "Ctrl+Shift+Q"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_FORMATREGION, "&Format Text" & $TAB & "Ctrl+B"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_TABULATEREGION, "&Tabulate Text" & $TAB & "Ctrl+Shift+B"
         hPopUpSubmenu = CreatePopUpMenu
         pSed.hSubMenuCaseConversions = hPopUpSubmenu
            AppendMenu hPopUpMenu, %MF_POPUP OR %MF_ENABLED, hPopUpSubmenu, "&Case Conversions"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_SELTOUPPERCASE, "Selection to &Upper Case" & $TAB & "Ctrl+Alt+U"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_SELTOLOWERCASE, "Selection to &Lower Case" & $TAB & "Ctrl+Alt+L"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_SELTOMIXEDCASE, "Selection to &Mixed Case" & $TAB & "Ctrl+Alt+M"
         hPopUpSubmenu = CreatePopUpMenu
         pSed.hSubMenuEndOfLineConversions = hPopUpSubmenu
            AppendMenu hPopUpMenu, %MF_POPUP OR %MF_ENABLED, hPopUpSubmenu, "End of &Line Characters Conversions"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_CVEOLTOCRLF, "Convert End of Line Characters to $CRLF"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_CVEOLTOCR, "Convert End of Line Characters to $CR"
            AppendMenu hPopUpSubmenu, %MF_ENABLED, %IDM_CVEOLTOLF, "Convert End of Line Characters to $LF"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_REPLTABSWITHSPC, "Replace Tabs with Spaces"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHRINK, "Shrink Text"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CHARMAP, "Character Map" & $TAB & "Ctrl+Shift+K"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_HTMLCODE, "Convert to &Html"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuSearch = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Search"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FIND, "&Find..." & $TAB & "Ctrl+F"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FINDNEXT, "Find &Next" & $TAB & "F3"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FINDBACKWARDS, "Find &Backwards" & $TAB & "Shift+F3"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_REPLACE, "Find and R&eplace..." & $TAB & "Ctrl+R"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_GOTOLINE,  "&Go to Line..." & $TAB & "Ctrl+G"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CODEFINDER, "&Code Finder..." & $TAB & "F4"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TOGGLEBOOKMARK, "Toggle Bookmark" & $TAB & "Ctrl+F2"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_NEXTBOOKMARK, "Next Bookmark" & $TAB & "F2"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PREVIOUSBOOKMARK, "Previous Bookmark" & $TAB & "Shift+F2"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_DELETEBOOKMARKS, "Delete Bookmarks" & $TAB & "Ctrl+Shift+F2"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FINDINFILES, "Find in Files..." & $TAB & "Ctrl+Shift+F"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_EXPLORER, "Explorer..." & $TAB & "Ctrl+Shift+O"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_WINDOWSFIND, "Windows Find..." & $TAB & "Ctrl+Alt+F"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuRun = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Run"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COMPILE, "&Compile" & $TAB & "Ctrl+F5 or Ctrl+M"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COMPILEANDRUN, "Compile and &Execute" & $TAB & "F5 or Ctrl+E"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COMPILEANDDEBUG, "Compile and &Debug" & $TAB & "F6"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_EXECUTE, "E&xecute Without Compiling" & $TAB & "Ctrl+Shift+E"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COMMANDLINE, "Co&mmand Line..."
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_RUNFILEDLG, "&Run File Dialog..." & $TAB & "Ctrl+Shift+R"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuView = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&View"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TOGGLE, "Toggle &Current Fold Point" & $TAB & "F8"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TOGGLEALL, "Toggle Current and All &Below" & $TAB & "Ctrl+F8"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FOLDALL, "&Fold All" & $TAB & "Alt+F8"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_UNFOLDALL, "&Unfold All" & $TAB & "Shift+F8"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_ZOOMIN, "Zoom In" & $TAB & "Ctrl++"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_ZOOMOUT, "Zoom Out" & $TAB & "Ctrl+-"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_USETABS, "Use &Tabs" & $TAB & "Ctrl+Shift+T"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_AUTOINDENT, "&Auto Indentation" & $TAB & "Ctrl+Shift+A"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWLINENUM, "&Line Numbers" & $TAB & "Ctrl+Shift+L"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWMARGIN, "&Margin" & $TAB & "Ctrl+Shift+M"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWINDENT, "&Indentation Guides" & $TAB & "Ctrl+Shift+I"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWSPACES, "&Whitespace" & $TAB & "Ctrl+Shift+W"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWEOL, "&End of Line" & $TAB & "Ctrl+Shift+D"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWEDGE, "Ed&ge" & $TAB & "Ctrl+Shift+G"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SHOWPROCNAME, "&Show Procedure Name" & $TAB & "Ctrl+Shift+S"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuWindow = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Window"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CASCADE, "&Cascade"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TILEH, "Tile &Horizontal"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TILEV, "Tile &Vertical"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_ARRANGE, "&Arrange &Icons"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLOSEWINDOW, "&Close" & $TAB & "Ctrl+F4"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLOSEWINDOWS, "Close &All"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_RESTOREWSIZE, "&Restore Main Window Size"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SWITCHWINDOW, "&Switch Window" & $TAB & "Ctrl+W"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuOptions = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Options"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_EDITOROPT, "&Editor..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COMPILEROPT, "&Compiler and Paths..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_COLORSOPT, "C&olors and Fonts..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_FOLDOPT, "&Folding..."
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_REGFILEEXT, "&Register File &Extensions"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuTools = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Tools"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuGuides = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Guides"
   hPopUpMenu = CreatePopUpMenu
   pSed.hMenuHelp = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Help"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_HELP, "&Help Context" & $TAB & "F1"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_HELPCONTENTS, "Help Contents" & $TAB & "Ctrl+Alt+F1"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_HELPINDEX, "Help Index" & $TAB & "Ctrl+Alt+F2"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_HELPSEARCH, "Help Search" & $TAB & "Ctrl+Alt+F3"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_ABOUT, "&About CSED"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CSEDHELP, "&CSED Help"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PBWINHELP, "PBWin Help"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PBCCHELP, "PBCC Help"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_RCHELP, "Resource Help"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PLATFORMSDKHELP, "Microsoft Platform SDK"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_JRSSITE, "&José Roca Software Website"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_JRSFORUM, "José &Roca Software Forum"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_PBSITE, "&PowerBasic on the Net"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_MSDNSITE, "&MSDN Home Page"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_GOOGLE, "&Google"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_GOOGLECODESEARCH, "G&oogle Code Search"

   ' // Search the .chm files
   LOCAL idx AS LONG
   LOCAL hToolsFile AS LONG
   LOCAL RecordStr AS STRING
   LOCAL nCount AS LONG
   LOCAL tTools AS CSED_TOOLSTYPE
#IF %DEF(%UNICODE)
   LOCAL strDbPath AS WSTRING
   LOCAL strName AS WSTRING
   LOCAL strPath AS WSTRING
   LOCAL strMenu AS WSTRING
#ELSE
   LOCAL strDbPath AS STRING
   LOCAL strName AS STRING
   LOCAL strPath AS STRING
   LOCAL strMenu AS STRING
#ENDIF

   pSed.MenuGuidesCount = 1
   pSed.MenuToolsCount = 1
   strDbPath = EXE.Path$ & "CSED_TOOLS\CSED_TOOLS.TRM"
   IF ISFILE(strDbPath) THEN
      hToolsFile = trm_Open(BYCOPY strDbPath, %TRUE)
      IF hToolsFile > 0 THEN
         RecordStr = trm_GetFirst(hToolsFile, 1)
         WHILE LEN(RecordStr)
            AfxDoEvents pWindow.hwnd
            LSET tTools = RecordStr
            strName = TRIM$(tTools.strName)
            strPath = TRIM$(tTools.strPath)
            IF VAL(tTools.strMenu) = 1 THEN
               IF UCASE$(RIGHT$(strPath, 4)) = ".CHM" OR UCASE$(RIGHT$(strPath, 4)) = ".PDF" THEN
                  AppendMenu pSed.hMenuGuides, %MF_ENABLED, %IDM_GUIDESMENUHEADER + pSed.MenuGuidesCount, BYCOPY strName
                  pSed.MenuGuidesCount = pSed.MenuGuidesCount + 1
               ELSE
                  AppendMenu pSed.hMenuTools, %MF_ENABLED, %IDM_TOOLSMENUHEADER + pSed.MenuToolsCount, BYCOPY strName
                  pSed.MenuToolsCount = pSed.MenuToolsCount + 1
               END IF
            END IF
            RecordStr = trm_GetNext(hToolsFile)
         WEND
         trm_Close(hToolsFile)
      END IF
   END IF

   ' // Right justify some menus
   AfxRightJustifyMenuItem(hMenu, 7)
   AfxRightJustifyMenuItem(hMenu, 8)
   AfxRightJustifyMenuItem(hMenu, 9)
   ' // Bold the text of the Help menu
   AfxSetMenuItemBold(hMenu, 9)
   ' // Bold the text of Exit
   AfxSetMenuItemBold(pSed.hMenuFile, 18)

   ' // Attach the menu to the main window
   SetMenu pWindow.hwnd, hMenu

   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create the context menu
' ========================================================================================
FUNCTION CSED_CreateContextMenu (BYVAL strWord AS STRING) AS DWORD

   LOCAL hPopupMenu AS DWORD

   hPopupMenu = CreatePopUpMenu
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_UNDO, "&Undo" & $TAB & "Ctrl+Z"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_REDO, "Red&o" & $TAB & "Ctrl+K"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_CUT, "Cu&t" & $TAB & "Ctrl+X"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_COPY, "&Copy" & $TAB & "Ctrl+C"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_PASTE, "&Paste" & $TAB & "Ctrl+V"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_CLEAR, "Clea&r"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_CLEARALL, "Cl&ear All"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_LINEDELETE, "&Delete Line" & $TAB & "Ctrl+Y"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_SELECTALL, "Select &All" & $TAB & "Ctrl+A"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_BLOCKINDENT, "Block &Indent" & $TAB & "Tab"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_BLOCKUNINDENT, "Block &Unindent" & $TAB & "Shift+Tab"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_COMMENT, "&Block Comment" & $TAB & "Ctrl+Q"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_UNCOMMENT, "Bloc&k Uncomment" & $TAB & "Ctrl+Shift+Q"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_FORMATREGION, "&Format Text" & $TAB & "Ctrl+B"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_TABULATEREGION, "&Tabulate Text" & $TAB & "Ctrl+Shift+B"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_SELTOUPPERCASE, "Selection to &Upper Case" & $TAB & "Ctrl+Alt+U"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_SELTOLOWERCASE, "Selection to &Lower Case" & $TAB & "Ctrl+Alt+L"
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_SELTOMIXEDCASE, "Selection to &Mixed Case" & $TAB & "Ctrl+Alt+M"
   AppendMenu hPopupMenu, %MF_SEPARATOR, 0, ""
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_TOGGLEBOOKMARK, "Toggle Bookmark" & $TAB & "Ctrl+F2"
   AppendMenu hPopupMenu, %MF_SEPARATOR, 0, ""
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_INSERTGUID, "Insert &GUID" & $TAB & "Ctrl+Alt+G"
   AppendMenu hPopupMenu, %MF_SEPARATOR, 0, ""
   AppendMenu hPopupMenu, %MF_ENABLED, %IDM_HELP, "&Help" & $TAB & "F1"

   IF SCI_GetSelectionStart(pSed.hEdit) = SCI_GetSelectionEnd(pSed.hEdit) THEN
      IF UCASE$(RIGHT$(strWord, 4)) = ".BAS" OR UCASE$(RIGHT$(strWord, 4)) = ".INC" OR _
         UCASE$(RIGHT$(strWord, 3)) = ".BI" OR UCASE$(RIGHT$(strWord, 4)) = ".INL" OR _
         UCASE$(RIGHT$(strWord, 5)) = ".HTML" OR UCASE$(RIGHT$(strWord, 4)) = ".HTM" OR _
         UCASE$(RIGHT$(strWord, 6)) = ".SHTML" OR UCASE$(RIGHT$(strWord, 4)) = ".XSL" OR _
         UCASE$(RIGHT$(strWord, 4)) = ".XSD" OR UCASE$(RIGHT$(strWord, 2)) = ".C" OR _
         UCASE$(RIGHT$(strWord, 3)) = ".CC" OR UCASE$(RIGHT$(strWord, 4)) = ".CPP" OR _
         UCASE$(RIGHT$(strWord, 4)) = ".CXX" OR UCASE$(RIGHT$(strWord, 2)) = ".H" OR _
         UCASE$(RIGHT$(strWord, 3)) = ".HH" OR UCASE$(RIGHT$(strWord, 4)) = ".HPP" OR _
         UCASE$(RIGHT$(strWord, 4)) = ".HXX" OR UCASE$(RIGHT$(strWord, 4)) = ".XML" OR _
         UCASE$(RIGHT$(strWord, 5)) = ".JAVA" OR UCASE$(RIGHT$(strWord, 4)) = ".JAD" OR _
         UCASE$(RIGHT$(strWord, 3)) = ".JS" OR UCASE$(RIGHT$(strWord, 3)) = ".RC" OR _
         UCASE$(RIGHT$(strWord, 4)) = ".RC2" OR UCASE$(RIGHT$(strWord, 4)) = ".DLG" OR _
         UCASE$(RIGHT$(strWord, 4)) = ".IDL" OR UCASE$(RIGHT$(strWord, 4)) = ".ODL" THEN
         AppendMenu hPopupMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopupMenu, %MF_ENABLED, %IDM_GOTOSELFILE, "Open " & strWord
      END IF
      ' // Remove unusable menu items to keep size manageable
      RemoveMenu hPopupMenu, %IDM_CUT, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_COPY, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_CLEAR, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_BLOCKINDENT, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_BLOCKUNINDENT, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_COMMENT, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_UNCOMMENT, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_FORMATREGION, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_TABULATEREGION, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_SELTOUPPERCASE, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_SELTOLOWERCASE, %MF_BYCOMMAND
      RemoveMenu hPopupMenu, %IDM_SELTOMIXEDCASE, %MF_BYCOMMAND
   END IF

   IF ISFALSE SCI_CanUndo(pSed.hEdit) THEN RemoveMenu hPopupMenu, %IDM_UNDO, %MF_BYCOMMAND
   IF ISFALSE SCI_CanRedo(pSed.hEdit) THEN RemoveMenu hPopupMenu, %IDM_REDO, %MF_BYCOMMAND
   IF ISFALSE SCI_CanPaste(pSed.hEdit) THEN RemoveMenu hPopupMenu, %IDM_PASTE, %MF_BYCOMMAND

   FUNCTION = hPopupMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks or unchecks some of the menu options
' ========================================================================================
SUB CSED_CheckMenuOptions (BYVAL hMenu AS DWORD)

   CheckMenuItem hMenu, %IDM_USETABS, IIF&(pSed.UseTabs = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_AUTOINDENT, IIF&(pSed.AutoIndent = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWLINENUM, IIF&(pSed.LineNumbers = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWMARGIN, IIF&(pSed.Margin = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWINDENT, IIF&(pSed.IndentGuides = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWSPACES, IIF&(pSed.WhiteSpace = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWEDGE, IIF&(pSed.EdgeColumn = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWEOL, IIF&(pSed.EndOfLine = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)
   CheckMenuItem hMenu, %IDM_SHOWPROCNAME, IIF&(pSed.ShowProcedureName = %BST_CHECKED, %MF_CHECKED, %MF_UNCHECKED)

END SUB
' ========================================================================================

' ========================================================================================
' Disable Edit, View and Run submenus
' If there are MDI windows opened the position changes because MDI adds a system menu
' ========================================================================================
SUB CSED_DisableSubmenus

   LOCAL lMenuItem AS LONG
   LOCAL hMenuHandle AS DWORD

   FOR lMenuItem = 0 TO 255
      hMenuHandle = GetSubMenu(pSed.hMenu, lMenuItem)
      IF hMenuHandle = 0 THEN EXIT FOR
      IF hMenuHandle = pSed.hMenuEdit OR hMenuHandle = pSed.hMenuView THEN
         EnableMenuItem pSed.hMenu, lMenuItem, %MF_BYPOSITION OR %MF_GRAYED
      END IF
   NEXT
   DrawMenuBar pSed.hwndMain

END SUB
' ========================================================================================

' ========================================================================================
' Enable Edit, View and Run submenus
' If there are MDI windows opened the position changes because MDI adds a system menu
' ========================================================================================
SUB CSED_EnableSubmenus

   LOCAL lMenuItem AS LONG
   LOCAL hMenuHandle AS DWORD

   FOR lMenuItem = 0 TO 255
      hMenuHandle = GetSubMenu(pSed.hMenu, lMenuItem)
      IF hMenuHandle = 0 THEN EXIT FOR
      IF hMenuHandle = pSed.hMenuEdit OR hMenuHandle = pSed.hMenuView THEN
         EnableMenuItem pSed.hMenu, lMenuItem, %MF_BYPOSITION OR %MF_ENABLED
      END IF
   NEXT
   DrawMenuBar pSed.hwndMain

END SUB
' ========================================================================================

' ========================================================================================
' Disable menu items
' ========================================================================================
SUB CSED_DisableMenuItems

   ' // Disable Edit and Run submenus
   CSED_DisableSubmenus

   ' // File menu
   EnableMenuItem pSed.hMenuFile, %IDM_INSERTFILE, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_SAVE, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_SAVEAS, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_SAVEALL, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_CLOSEFILE, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_CLOSEALL, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_PRINT, %MF_GRAYED
   EnableMenuItem pSed.hMenuFile, %IDM_CHDIR, %MF_GRAYED

   ' // Search menu
   EnableMenuItem pSed.hMenuSearch, %IDM_FIND, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_FINDNEXT, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_FINDBACKWARDS, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_REPLACE, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_GOTOLINE, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_TOGGLEBOOKMARK, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_NEXTBOOKMARK, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_PREVIOUSBOOKMARK, %MF_GRAYED
   EnableMenuItem pSed.hMenuSearch, %IDM_DELETEBOOKMARKS, %MF_GRAYED

   ' // Run menu
   EnableMenuItem pSed.hMenuRun, %IDM_COMPILE, %MF_GRAYED
   EnableMenuItem pSed.hMenuRun, %IDM_COMPILEANDRUN, %MF_GRAYED
   EnableMenuItem pSed.hMenuRun, %IDM_COMPILEANDDEBUG, %MF_GRAYED
   EnableMenuItem pSed.hMenuRun, %IDM_PRIMARYSOURCE, %MF_GRAYED
   EnableMenuItem pSed.hMenuRun, %IDM_COMMANDLINE, %MF_GRAYED
   EnableMenuItem pSed.hMenuRun, %IDM_EXECUTE, %MF_GRAYED

   ' // View menu
   EnableMenuItem pSed.hMenuView, %IDM_TOGGLE, %MF_GRAYED
   EnableMenuItem pSed.hMenuView, %IDM_TOGGLEALL, %MF_GRAYED
   EnableMenuItem pSed.hMenuView, %IDM_FOLDALL, %MF_GRAYED
   EnableMenuItem pSed.hMenuView, %IDM_UNFOLDALL, %MF_GRAYED
   EnableMenuItem pSed.hMenuView, %IDM_ZOOMIN, %MF_GRAYED
   EnableMenuItem pSed.hMenuView, %IDM_ZOOMOUT, %MF_GRAYED

   ' // Window menu
   EnableMenuItem pSed.hMenuWindow, %IDM_CASCADE, %MF_GRAYED
   EnableMenuItem pSed.hMenuWindow, %IDM_TILEH, %MF_GRAYED
   EnableMenuItem pSed.hMenuWindow, %IDM_TILEV, %MF_GRAYED
   EnableMenuItem pSed.hMenuWindow, %IDM_ARRANGE, %MF_GRAYED
   EnableMenuItem pSed.hMenuWindow, %IDM_CLOSEWINDOW, %MF_GRAYED
   EnableMenuItem pSed.hMenuWindow, %IDM_CLOSEWINDOWS, %MF_GRAYED
   EnableMenuItem pSed.hMenuWindow, %IDM_SWITCHWINDOW, %MF_GRAYED

END SUB
' ========================================================================================

' ========================================================================================
' Change menu items's state
' ========================================================================================
SUB CSED_ChangeMenuItemsState

   ' // Disables menu items if there is not any file being edited
   IF pSed.hEdit = 0 THEN
      CSED_DisableMenuItems
      EXIT SUB
   END IF

   ' // Enables or disables menu items
   IF SCI_CanPaste(pSed.hEdit) = 0 THEN EnableMenuItem(pSed.hMenuEdit, %IDM_PASTE, %MF_GRAYED) ELSE EnableMenuItem(pSed.hMenuEdit, %IDM_PASTE, %MF_ENABLED)
   IF SCI_GetSelectionStart(pSed.hEdit) = SCI_GetSelectionEnd(pSed.hEdit) THEN
      EnableMenuItem(pSed.hEdit, %IDM_CUT, %MF_GRAYED)
      EnableMenuItem(pSed.hEdit, %IDM_COPY, %MF_GRAYED)
   ELSE
      EnableMenuItem(pSed.hEdit, %IDM_CUT, %MF_ENABLED)
      EnableMenuItem(pSed.hEdit, %IDM_COPY, %MF_ENABLED)
   END IF
   IF SCI_GetModify(pSed.hEdit) = 0 THEN EnableMenuItem(pSed.hMenuFile, %IDM_SAVE, %MF_GRAYED) ELSE EnableMenuItem(pSed.hMenuFile, %IDM_SAVE, %MF_ENABLED)
   IF SCI_CanUndo(pSed.hEdit) = 0 THEN EnableMenuItem(pSed.hMenuEdit, %IDM_UNDO, %MF_GRAYED) ELSE EnableMenuItem(pSed.hMenuEdit, %IDM_UNDO, %MF_ENABLED)
   IF SCI_CanRedo(pSed.hEdit) = 0 THEN EnableMenuItem(pSed.hMenuEdit, %IDM_REDO, %MF_GRAYED) ELSE EnableMenuItem(pSed.hMenuEdit, %IDM_REDO, %MF_ENABLED)
   IF SCI_CanPaste(pSed.hEdit) = 0 THEN Toolbar_DisableButton(pSed.hToolbar, %IDM_PASTE) ELSE Toolbar_EnableButton(pSed.hToolbar, %IDM_PASTE)

   ' // Enable Edit and Run submenus
   CSED_EnableSubmenus

   ' // File menu
   EnableMenuItem pSed.hMenuFile, %IDM_INSERTFILE, %MF_ENABLED
   EnableMenuItem pSed.hMenuFile, %IDM_SAVEAS, %MF_ENABLED
   EnableMenuItem pSed.hMenuFile, %IDM_SAVEALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuFile, %IDM_CLOSEFILE, %MF_ENABLED
   EnableMenuItem pSed.hMenuFile, %IDM_CLOSEALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuFile, %IDM_PRINT, %MF_ENABLED
   EnableMenuItem pSed.hMenuFile, %IDM_CHDIR, %MF_ENABLED

   ' // Edit menu
   EnableMenuItem pSed.hMenuEdit, %IDM_LINEDELETE, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_CLEAR, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_CLEARALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_SELECTALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_BLOCKINDENT, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_BLOCKUNINDENT, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_COMMENT, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_UNCOMMENT, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_FORMATREGION, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_TABULATEREGION, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_SELTOUPPERCASE, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_SELTOLOWERCASE, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_SELTOMIXEDCASE, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_CVEOLTOCRLF, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_CVEOLTOCR, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_CVEOLTOLF, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_REPLTABSWITHSPC, %MF_ENABLED
   EnableMenuItem pSed.hMenuEdit, %IDM_HTMLCODE, %MF_ENABLED

   ' // Search menu
   EnableMenuItem pSed.hMenuSearch, %IDM_FIND, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_FINDNEXT, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_FINDBACKWARDS, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_REPLACE, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_GOTOLINE, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_TOGGLEBOOKMARK, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_NEXTBOOKMARK, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_PREVIOUSBOOKMARK, %MF_ENABLED
   EnableMenuItem pSed.hMenuSearch, %IDM_DELETEBOOKMARKS, %MF_ENABLED

   ' // Run menu
   EnableMenuItem pSed.hMenuRun, %IDM_COMPILE, %MF_ENABLED
   EnableMenuItem pSed.hMenuRun, %IDM_COMPILEANDRUN, %MF_ENABLED
   EnableMenuItem pSed.hMenuRun, %IDM_COMPILEANDDEBUG, %MF_ENABLED
   EnableMenuItem pSed.hMenuRun, %IDM_EXECUTE, %MF_ENABLED
   EnableMenuItem pSed.hMenuRun, %IDM_PRIMARYSOURCE, %MF_ENABLED
   EnableMenuItem pSed.hMenuRun, %IDM_COMMANDLINE, %MF_ENABLED

   ' // View menu
   EnableMenuItem pSed.hMenuView, %IDM_TOGGLE, %MF_ENABLED
   EnableMenuItem pSed.hMenuView, %IDM_TOGGLEALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuView, %IDM_FOLDALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuView, %IDM_UNFOLDALL, %MF_ENABLED
   EnableMenuItem pSed.hMenuView, %IDM_ZOOMIN, %MF_ENABLED
   EnableMenuItem pSed.hMenuView, %IDM_ZOOMOUT, %MF_ENABLED

   ' // Window menu
   EnableMenuItem pSed.hMenuWindow, %IDM_CASCADE, %MF_ENABLED
   EnableMenuItem pSed.hMenuWindow, %IDM_TILEH, %MF_ENABLED
   EnableMenuItem pSed.hMenuWindow, %IDM_TILEV, %MF_ENABLED
   EnableMenuItem pSed.hMenuWindow, %IDM_ARRANGE, %MF_ENABLED
   EnableMenuItem pSed.hMenuWindow, %IDM_CLOSEWINDOW, %MF_ENABLED
   EnableMenuItem pSed.hMenuWindow, %IDM_CLOSEWINDOWS, %MF_ENABLED
   EnableMenuItem pSed.hMenuWindow, %IDM_SWITCHWINDOW, %MF_ENABLED

   ' // If the starting and ending selection are the same there is not selection,
   IF SCI_GetSelectionStart(pSed.hEdit) = SCI_GetSelectionEnd(pSed.hEdit) THEN
      EnableMenuItem pSed.hMenuEdit, %IDM_BLOCKINDENT, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_BLOCKUNINDENT, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_COMMENT, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_UNCOMMENT, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_FORMATREGION, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_TABULATEREGION, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_SELTOUPPERCASE, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_SELTOLOWERCASE, %MF_GRAYED
      EnableMenuItem pSed.hMenuEdit, %IDM_SELTOMIXEDCASE, %MF_GRAYED
   END IF

   ' // If the file is empty, disable find and bookmark options
   IF SCI_GetLineCount(pSed.hEdit) = 0 THEN
      EnableMenuItem pSed.hMenuSearch, %IDM_FIND, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_FINDNEXT, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_FINDBACKWARDS, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_REPLACE, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_GOTOLINE, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_TOGGLEBOOKMARK, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_NEXTBOOKMARK, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_PREVIOUSBOOKMARK, %MF_GRAYED
      EnableMenuItem pSed.hMenuSearch, %IDM_DELETEBOOKMARKS, %MF_GRAYED
   END IF

END SUB
' ========================================================================================
