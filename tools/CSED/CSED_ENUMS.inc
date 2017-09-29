' ########################################################################################
' CSED Editor
' File: CSED_ENUMS.INC
' Contents: Enumerations for control identifiers
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Control identifiers
' ========================================================================================
ENUM CSED_CONTROLIDS_ENUM SINGULAR
   IDC_EDIT = 101         ' // Edit control
   IDC_STATUSBAR          ' // Status bar control
   IDC_TOOLBAR            ' // Tool bar control
   IDC_BOTTOMTOOLBAR      ' // Tool bar control
   IDC_CODEFINDER         ' // Code finder combobox
   IDC_TABMDI             ' // Tab control for MDI windows
END ENUM

' ========================================================================================
' Menu identifiers
' ========================================================================================

' FILE
ENUM CSED_FILE_MENU_ENUM SINGULAR
   IDM_FILEHEADER = 3000
   IDM_INSERTFILE           ' // Insert file
   IDM_NEW                  ' // New file
   IDM_OPEN                 ' // Open file
   IDM_REOPEN               ' // Reopen file
   IDM_SAVE                 ' // Save
   IDM_SAVEAS               ' // Save as
   IDM_SAVEALL              ' // Save all files
   IDM_PRINT                ' // Print file
   IDM_CLOSEFILE            ' // Close file
   IDM_CLOSEALL             ' // Close all files
   IDM_REFRESH              ' // Refresh
   IDM_DOS                  ' // Command prompt
   IDM_EXIT                 ' // Exit
   IDM_CHDIR                ' // Change directory to current directory
   IDT_PRINT                ' // Print without dialog
   IDM_RECENTFILES          ' // Recent files
   IDM_RECENTFILE1          ' // Recent file 1
   IDM_RECENTFILE2          ' // Recent file 2
   IDM_RECENTFILE3          ' // Recent file 3
   IDM_RECENTFILE4          ' // Recent file 4
   IDM_RECENTFILE5          ' // Recent file 5
   IDM_RECENTFILE6          ' // Recent file 6
   IDM_RECENTFILE7          ' // Recent file 7
   IDM_RECENTFILE8          ' // Recent file 8
   IDM_RECENTFILE9          ' // Recent file 9
END ENUM

' EDIT
ENUM CSED_EDIT_MENU_ENUM SINGULAR
   IDM_EDITHEADER = 3200          ' // Edit
   IDM_UNDO                       ' // Undo
   IDM_REDO                       ' // Redo
   IDM_CLEAR                      ' // Clear
   IDM_CLEARALL                   ' // Clear all
   IDM_CUT                        ' // Cut
   IDM_COPY                       ' // Copy
   IDM_PASTE                      ' // Paste
   IDM_SELECTALL                  ' // Select all
   IDM_COMMENT                    ' // Block comment
   IDM_UNCOMMENT                  ' // Block uncomment
   IDM_LINEDELETE                 ' // Delete line
   IDM_AUTOCOMPLETE               ' // Autocomplete
   IDM_HTMLCODE                   ' // Convert to Html
   IDM_SELTOUPPERCASE             ' // Convert selected text to upper case
   IDM_SELTOLOWERCASE             ' // Convert selected text to lower case
   IDM_SELTOMIXEDCASE             ' // Convert selected text to mixed case
   IDM_FORMATREGION               ' // Format selected text
   IDM_TABULATEREGION             ' // Tabulate selected text
   IDM_BLOCKINDENT                ' // Block indent
   IDM_BLOCKUNINDENT              ' // Block unindent
   IDM_GOTOBEGINPROC              ' // Goto to the begining of the procedure or function
   IDM_GOTOENDPROC                ' // Goto to the end of the procedure or function
   IDM_GOTOBEGINTHISPROC          ' // Goto to the begining of the procedure or function
   IDM_GOTOENDTHISPROC            ' // Goto to the end of the procedure or function
   IDM_REPLTABSWITHSPC            ' // Replace tabs with spaces
   IDM_SHRINK                     ' // Shrink text
   IDK_COMMENT                    ' // Line/Block comment
   IDK_UNCOMMENT                  ' // Line/Block uncomment
   IDM_INSERTGUID                 ' // Insert GUID
   IDM_CHARMAP                    ' // Character map
END ENUM

' SEARCH
ENUM CSED_SEARCH_MENU_ENUM SINGULAR
   IDM_SEARCHHEADER = 3300       ' // Search
   IDM_FIND                      ' // Find
   IDM_FINDNEXT                  ' // Find next
   IDM_REPLACE                   ' // Replace
   IDM_GOTOLINE                  ' // Go to line...
   IDM_TOGGLEBOOKMARK            ' // Toggle bookmark
   IDM_NEXTBOOKMARK              ' // Next bookmark
   IDM_PREVIOUSBOOKMARK          ' // Previous bookmark
   IDM_DELETEBOOKMARKS           ' // Delete bookmarks
   IDM_EXPLORER                  ' // Explorer
   IDM_WINDOWSFIND               ' // Windows Find
   IDM_FINDINFILES               ' // Find in files
   IDM_FINDBACKWARDS             ' // Find backwards
   IDM_FINDUPORDOWN              ' // Find up or down
   IDM_CODEFINDER                ' // Code finder combobox
END ENUM

' VIEW
ENUM CSED_VIEW_MENU_ENUM SINGULAR
   IDM_VIEWHEADER = 3400       ' // View
   IDM_TOGGLE                  ' // Toggle current fold point
   IDM_TOGGLEALL               ' // Toggle current onwards
   IDM_FOLDALL                 ' // Fold all
   IDM_UNFOLDALL               ' // Unfold all
   IDM_USETABS                 ' // Use tabs
   IDM_AUTOINDENT              ' // Auto indentation
   IDM_SHOWLINENUM             ' // Show line numbers
   IDM_SHOWMARGIN              ' // Show margin
   IDM_SHOWINDENT              ' // Show indentation guides
   IDM_SHOWEOL                 ' // Show end of line
   IDM_ZOOMIN                  ' // Zoom in
   IDM_ZOOMOUT                 ' // Zoom out
   IDM_SHOWSPACES              ' // Show spaces as dots
   IDM_SHOWEDGE                ' // Show edge
   IDM_CVEOLTOCRLF             ' // Convert end of line characters to $CRLF
   IDM_CVEOLTOCR               ' // Convert end of line characters to $CR
   IDM_CVEOLTOLF               ' // Convert end of line characters to $LF
   IDM_SHOWPROCNAME            ' // Show sub/function name in the statusbar
   IDM_FILEPROPERTIES          ' // Show file properties
   IDM_SYSINFO                 ' // Show system information
END ENUM

' RUN
ENUM CSED_RUN_MENU_ENUM SINGULAR
   IDM_RUNHEADER = 3500         ' // Run
   IDM_COMPILE                  ' // Compile
   IDM_COMPILEANDRUN            ' // Compile and execute
   IDM_COMPILEANDDEBUG          ' // Compile and debug
   IDM_PRIMARYSOURCE            ' // Primary source
   IDM_EXECUTE                  ' // Execute file
   IDM_COMMANDLINE              ' // Command line
   IDM_RUNFILEDLG               ' // Run File Dialog
   IDM_NOTEPAD                  ' // Notepad
   IDM_MSPAINT                  ' // Microsoft Paint
END ENUM

' WINDOW
ENUM CSED_WINDOW_MENU_ENUM SINGULAR
   IDM_WINDOWHEADER = 3600   ' // Window
   IDM_TILEH                 ' // Tile windows horizontally
   IDM_TILEV                 ' // Tile windows vertically
   IDM_CASCADE               ' // Cascade windows
   IDM_ARRANGE               ' // Arrange icons
   IDM_CLOSEWINDOW           ' // Close window
   IDM_CLOSEWINDOWS          ' // Close all
   IDM_RESTOREWSIZE          ' // Restore main window size
   IDM_SWITCHWINDOW          ' // Switch window
END ENUM

' ========================================================================================
' Keyboard Macros - Do not the values change unless you also modify the CSED_InsertMacroText procedure
' ========================================================================================
ENUM CSED_KEYBOARD_MACROS_ENUM SINGULAR
   IDM_ALT0 = 3700
   IDM_ALT1
   IDM_ALT2
   IDM_ALT3
   IDM_ALT4
   IDM_ALT5
   IDM_ALT6
   IDM_ALT7
   IDM_ALT8
   IDM_ALT9
   IDM_CTRL0
   IDM_CTRL1
   IDM_CTRL2
   IDM_CTRL3
   IDM_CTRL4
   IDM_CTRL5
   IDM_CTRL6
   IDM_CTRL7
   IDM_CTRL8
   IDM_CTRL9
END ENUM

' OPTIONS
ENUM CSED_OPTIONS_MENU_ENUM SINGULAR
   IDM_OPTIONSHEADER = 3800   ' // Options
   IDM_EDITOROPT              ' // Editor options
   IDM_COMPILEROPT            ' // Compiler options
   IDM_COLORSOPT              ' // Colors and fonts
   IDM_FOLDOPT                ' // Fold options
   IDM_REGFILEEXT             ' // Register extension filenames with Windows
END ENUM

' TOOLS
ENUM CSED_TOOLS_ENUM SINGULAR
   IDM_TOOLSHEADER = 3900       ' // Tools
   IDM_TOOLS                    ' // Tools
   IDM_PBFORMS                  ' // PBForms
   IDM_PBCOMBR                  ' // PB COM Browser
   IDM_POWERLIB                 ' // PB Library Manager
   IDM_COMPILERRESULTS          ' // Compiler results
   IDM_TYPELIBBR                ' // TypeLib Browser
   IDM_VISDES                   ' // Visual Designer
   IDM_ICONED                   ' // Icon Editor
   IDM_IMGED                    ' // Image Editor
   IDM_PBWINHELP                ' // PBWinHelp
   IDM_PBCCHELP                 ' // PBCC Help
   IDM_RCHELP                   ' // Resource
   IDM_PLATFORMSDKHELP          ' // Platform SDK Help
   IDM_CODETIPSBUILDER          ' // Codetips builder
   IDM_CALCULATOR               ' // Calculator
   IDM_KBDMACROS                ' // Keyboard macros
   IDM_MSGBOXDESIGNER           ' // Message Box designer
   IDM_CODEKEEPER               ' // Code keeper
   IDM_JRSINC1                  ' // José Roca Headers I
   IDM_JRSINC2                  ' // José Roca Headers II
   IDM_PBINC1                   ' // PowerBASIC Headers I
   IDM_PBINC2                   ' // PowerBASIC Headers II
END ENUM

' HELP
ENUM CSED_HELP_MENU_ENUM SINGULAR
   IDM_HELPHEADER = 4000     ' // Help
   IDM_HELP                  ' // Help
   IDM_ABOUT                 ' // About box
   IDM_CSEDHELP              ' // CSED Help
   IDM_HELPCONTENTS          ' // Help contents
   IDM_HELPINDEX             ' // Help index
   IDM_HELPSEARCH            ' // Help search
END ENUM

' SITES
ENUM CSED_SITES_MENU_ENUM SINGULAR
   IDM_SITESHEADER = 4100    ' // Sites
   IDM_MAIL                  ' // Email us
   IDM_JRSSITE               ' // José Roca Software site
   IDM_JRSFORUM              ' // José Roca Software forum
   IDM_PBSITE                ' // Power Basic site
   IDM_MSDNSITE              ' // MSDN site
   IDM_GOOGLE                ' // Google
   IDM_GOOGLECODESEARCH      ' // Google code search
END ENUM

' GUIDES MENU
ENUM CSED_GUIDES_MENU_ENUM SINGULAR
   IDM_GUIDESMENUHEADER = 4200   ' // Guides menu
END ENUM

' TOOLS MENU
ENUM CSED_TOOLS_MENU_ENUM SINGULAR
   IDM_TOOLSMENUHEADER = 4500   ' // Tools menu
END ENUM

ENUM CSED_GOTO_OPTIONS_ENUM SINGULAR
   IDM_GOTOSELFILE = 5000   ' // Goto or load the file that has the same name that the one under the caret
END ENUM

ENUM CSED_FOLD_OPTIONS_ENUM SINGULAR
   IDC_FOLDLEVELNONE = 5100
   IDC_FOLDLEVELKEYWORD
   IDC_FOLDLEVELSUB
   IDC_FOLDSYMBOLARROW
   IDC_FOLDSYMBOLPLUSMINUS
   IDC_FOLDSYMBOLCIRCLE
   IDC_FOLDSYMBOLBOXTREE
   IDBO_FOLDING_HELP
END ENUM

' ========================================================================================
' Keyboard Macros - Do not change unless you also modify the CSED_InsertMacroText procedure
' ========================================================================================
ENUM CSED_COLOR_OPTIONS_ENUM SINGULAR
   IDBO_COLORS_HELP = 5500
   IDC_LBCOLSEL
   IDC_CBFORECOLOR
   IDC_CBBACKCOLOR
   IDC_CBFONTS
   IDC_CBCHARSET
   IDC_CBFONTSIZE
   IDK_BOLD
   IDK_ITALIC
   IDK_UNDERLINE
   IDB_USERFORECOLOR
   IDB_USERBACKCOLOR
   IDK_USEDEFAULTCOLOR
   IDK_USEDEFAULTFONT
   IDK_USEDEFAULTSIZE
END ENUM

' ========================================================================================
' Editor options dialog
' ========================================================================================
ENUM CSED_EDITOR_OPTIONS_ENUM SINGULAR
   IDBO_EDITOR_HELP = 10000
   IDCO_USETABS                        ' // Use tabs
   IDCO_CBTABSIZE                      ' // Tab size
   IDCO_AUTOINDENT                     ' // Auto indentation
   IDCO_CBINDENTSIZE                   ' // Indentation size
   IDCO_LINENUMBERS                    ' // Display line numbers
   IDCO_LINENUMBERSWIDTH               ' // Width of the line numbers margin
   IDCO_MARGIN                         ' // Margin
   IDCO_MARGINWIDTH                    ' // Margin width
   IDCO_EDGECOLUMN                     ' // Edge column
   IDCO_EDGEWIDTH                      ' // Edge width
   IDCO_INDENTGUIDES                   ' // Indentation guides
   IDCO_WHITESPACE                     ' // White space
   IDCO_ENDOFLINE                      ' // End of line
   IDCO_DEFAULT_UPPERCASE              ' // Default case = upper case
   IDCO_DEFAULT_MIXEDCASE              ' // Default case = mixed case
   IDCO_DEFAULT_LOWERCASE              ' // Default case = lower case
   IDCO_KEYWORD_UPPERCASE              ' // Default keyword case = upper case
   IDCO_KEYWORD_MIXEDCASE              ' // Default keyword case = mixed case
   IDCO_KEYWORD_LOWERCASE              ' // Default keyword case = lower case
   IDCO_BUDDY                          ' // Buddy controlo identifier
   IDCO_MAGNIFICATION                  ' // Magnification
   IDCO_SYNTAXHIGH                     ' // Syntax highlighting
   IDCO_CODETIPS                       ' // Code tips
   IDCO_MAXMAINWINDOW                  ' // Maximize main window
   IDCO_MAXEDITWINDOWS                 ' // Maximize edit windows
   IDCO_ASKBEFOREEXIT                  ' // As before exiting the editor
   IDCO_ALLOWMULTINST                  ' // Allow multiple instances
   IDCO_AUTOCONSTRUCT                  ' // Auto complete constructs
   IDCO_AUTOCOMPLTYPES                 ' // Auto complete types
   IDCO_TRIMTRAILBLANKS                ' // Trim trailing blanks
   IDCO_SHOWPROCNAME                   ' // Show procedure name
   IDCO_SHOWCARETLINE                  ' // Show caret line
   IDCO_STARTINLASTFOLDER              ' // Start in last folder
   IDCO_RELOADFILESATSTARTUP           ' // Reload files at startup
   IDCO_BACKUPEDITORFILES              ' // Backup editor files
   IDCO_ADDDATETIME                    ' // Add date time to backup files
   IDCO_SAVEBACKUPFILESTODATABASE      ' // Add date time to backup files
   IDCO_SAVEBOOKMARKS                  ' // Save bookmarks
   IDCO_SAVEWINPLA                     ' // Save/Restore window placement
   IDCO_USEMSDNHELP                    ' // Use MSDN help
   IDCO_PASTECVTEOLS                   ' // Convert end of lines when pasting
   IDCO_MULTIPLESELECTION              ' // Multiple selection
   IDCO_UTF8UNICODE                    ' // Unicode support (UTF-8 encoding)
END ENUM

ENUM CSED_COMPILER_OPTIONS_ENUM SINGULAR
   IDBO_COMPILER_HELP = 11000     ' // Compiler options
   IDCO_PBWIN                     ' // PBWIN
   IDCO_PBCC                      ' // PBCC
   IDCO_JRSINC1                   ' // Use José Roca include files
   IDCO_JRSINC2                   ' // Use José Roca include files
   IDCO_PBINC1                    ' // Use PB include files
   IDCO_PBINC2                    ' // Use PB include files
   IDCO_DISPRES                   ' // Display results
   IDCO_DELLOG                    ' // Delete log file
   IDCO_BEEPONEND                 ' // Beep on completion
   IDCO_PBWINPATH                 ' // PBWIN path
   IDBO_PBWINPATH                 ' // Button: PBWIN path
   IDCO_PBCCPATH                  ' // PBCC path
   IDBO_PBCCPATH                  ' // Button: PBCC path
   IDCO_RCPATH                    ' // Resource compiler path
   IDBO_RCPATH                    ' // Button: Resource compiler path
   IDCO_PBFORMSPATH               ' // PBForms path
   IDBO_PBFORMSPATH               ' // Button: PBForms path
   IDCO_PBCOMBROWSERPATH          ' // PB COM Browser path
   IDBO_PBCOMBROWSERPATH          ' // Button: PB COM Browser path
   IDCO_TYPELIBBROWSERPATH        ' // TypeLib Browser path
   IDBO_TYPELIBBROWSERPATH        ' // Button: TypeLib Browser path
   IDCO_PBINCPATH1                ' // PB includes path
   IDBO_PBINCPATH1                ' // Button: PB includes path
   IDCO_PBINCPATH2                ' // PB includes path
   IDBO_PBINCPATH2                ' // Button: PB includes path
   IDCO_JRSINCPATH1               ' // José Roca includes path
   IDBO_JRSINCPATH1               ' // Button: José Roca includes path
   IDCO_JRSINCPATH2               ' // José Roca includes path
   IDBO_JRSINCPATH2               ' // Button: José Roca includes path
   IDCO_DEBUGTOOLPATH             ' // Debugging tool
   IDBO_DEBUGTOOLPATH             ' // Button: Debugging tool
   IDCO_POWERLIBPATH              ' // PowerBASIC Library Manager
   IDBO_POWERLIBPATH              ' // Button: PowerBASIC Library Manager
   IDCO_PBWINHELPPATH             ' // PBWIN Help path
   IDBO_PBWINHELPPATH             ' // Button: PBWIN Help path
   IDCO_PBCCHELPPATH              ' // PBCC Help path
   IDBO_PBCCHELPPATH              ' // Button: PBCC Help path
   IDCO_SDKHELPPATH               ' // Platform SDK Help path
   IDBO_SDKHELPPATH               ' // Button: Platform SDK Help path
   IDCO_FINDINFILESTOOLPATH       ' // Find in files tool path
   IDBO_FINDINFILESTOOLPATH       ' // Button: Find in files tool
   IDCO_VISDESPATH                ' // Visual designer path
   IDBO_VISDESPATH                ' // Button: Visual designer path
   IDCO_ICONEDITORPATH            ' // Icon editor path
   IDBO_ICONEDITORPATH            ' // Button: Icon editor path
   IDCO_IMAGEEDITORPATH           ' // Image editor path
   IDBO_IMAGEEDITORPATH           ' // Button: Image editor path
   IDBO_COMPILEROPT_HELP          ' // Button: Help for compiler options
END ENUM

' ========================================================================================
' Bottom toolbar
' ========================================================================================
ENUM CSED_BOTTOM_TOOLBAR_ENUM SINGULAR
   IDM_BLOCKOPERATIONS = 7000   ' // Block operations
   IDM_CASECONVERSIONS          ' // Case conversions
   IDM_EOLCHARCONVERSIONS       ' // End of line character conversions
   IDM_SEARCHOPTIONS            ' // Search options
   IDM_BOOKMARKOPTIONS          ' // Bookmark options
   IDM_VIEWOPTIONS              ' // View options
   IDM_FOLDOPTIONS              ' // Fold options
   IDM_TOGGLECOMPILER           ' // Toggle compiler
   IDM_SHOWCOMPILERRESULT       ' // Show compiler result
   IDM_FILESTAMP                ' // File Stamp
   IDM_BACKUPMGR                ' // Backup files manager
   IDM_DEBUGTOOL                ' // Debugging tool
   IDM_LYNX                     ' // Lynx
   IDM_HEADERS                  ' // Headers
END ENUM
