' ========================================================================================
' TLB_PROCS.INC - Include file for the TypeLyb Browser
' (C) 2011 by José Roca. All rights reserved.
' ========================================================================================

$INIFILE  = "TLB_501.INI"
$cVersion = "5.0.1"
$cCaption = "TypeLib Browser 5.0.1 (c) 2011 by José Roca"
$cCopyright = "Copyright (c) 2011 by José Roca"

' ========================================================================================
' Library's documentation and attributes
' ========================================================================================
TYPE TLB_DOCUMENTATION
   szName       AS ASCIIZ * 255         ' // Library name
   szPath       AS ASCIIZ * %MAX_PATH   ' // Library path
   szHelpString AS ASCIIZ * 255         ' // Documentation string
   HelpContext  AS LONG                 ' // Help context
   szHelpFile   AS ASCIIZ * %MAX_PATH   ' // Help file
   szGuid       AS ASCIIZ * 39          ' // Library guid
   lcid         AS LONG                 ' // Library lcid
   syskind      AS LONG                 ' // SYSKIND
   MajorVersion AS INTEGER              ' // Major version number
   MinorVersion AS INTEGER              ' // Minor version number
   iAttr        AS INTEGER              ' // Attributes
END TYPE
' ========================================================================================

' ========================================================================================
' Library's attributes
' ========================================================================================
TYPE TLB_ATTRIBUTES
   guid         AS GUID                ' // Library guid
   lcid         AS LONG                ' // Library lcid
   syskind      AS DWORD               ' // SYSKIND
   wMajorVerNum AS WORD                ' // Major version number
   wMinorVerNum AS WORD                ' // Minor version number
   wLibFlags    AS WORD                ' // Flags
END TYPE
' ========================================================================================

' ========================================================================================
' GUIDs
' ========================================================================================
TYPE TLB_GUID
   szVIProgID AS ASCIIZ * 255          ' // Version independent ProgID
   szProgID   AS ASCIIZ * 255          ' // ProgID
   szName     AS ASCIIZ * 255          ' // Name of the interface or CoClass
   guid       AS GUID                  ' // GUID
   szPBSyntax AS ASCIIZ * %MAX_PATH    ' // PB Syntax
END TYPE
' ========================================================================================

' ========================================================================================
' Structure used to store information about variables
' ========================================================================================
TYPE TLB_VARDESC_STRUCT DWORD
   wIndirectionLevel AS WORD           ' // Indirection level
   vt                AS WORD           ' // Variant type
   vtOld             AS WORD           ' // Old variant type
   typekind          AS LONG           ' // Type description kind
   szName            AS ASCIIZ * 256   ' // Original name
   szPBName          AS ASCIIZ * 256   ' // PB name
   szPBSyntax        AS ASCIIZ * 256   ' // PB syntax
   szAliasName       AS ASCIIZ * 256   ' // Alias name
   szText            AS ASCIIZ * 256   ' // Comment text
   szTypeKind        AS ASCIIZ * 256   ' // Type description kind
   szGuid            AS ASCIIZ * 256   ' // GUID
   szVtPtr           AS ASCIIZ * 256   ' // Pointer's chain
END TYPE
' ========================================================================================

' ========================================================================================
' Structure used to store information about parameters
' ========================================================================================
TYPE TLB_PARAMDESC_STRUCT DWORD
   wIndirectionLevel AS WORD           ' // Indirection level
   vt                AS WORD           ' // Variant type
   vtOld             AS WORD           ' // Old variant type
   typekind          AS LONG           ' // Type description kind
   szName            AS ASCIIZ * 256   ' // Parameter name
   szOrigName        AS ASCIIZ * 256   ' // Original parameter name
   szPBName          AS ASCIIZ * 256   ' // PB name
   szPBSyntax        AS ASCIIZ * 256   ' // PB syntax
   szAliasName       AS ASCIIZ * 256   ' // Alias name
   szText            AS ASCIIZ * 256   ' // Comment text
   szTypeKind        AS ASCIIZ * 256   ' // Type description kind
   szGuid            AS ASCIIZ * 256   ' // GUID
   szVtPtr           AS ASCIIZ * 256   ' // Pointer's chain
   szDefaultValue    AS ASCIIZ * 256   ' // Default value
   vtIsPtr           AS LONG           ' // VarType is a pointer
   vtIsObject        AS LONG           ' // VarType is an object
   szIntName         AS ASCIIZ * 256   ' // Interface name
END TYPE
' ========================================================================================

' ========================================================================================
' Globals
' ========================================================================================

GLOBAL TLB_LibName AS STRING                      ' // Library name
GLOBAL TLB_GuidsArray () AS TLB_GUID              ' // GUIDs array
GLOBAL TLB_IIDsArray () AS TLB_GUID               ' // IIDs array
GLOBAL TLB_ProgIDsArray () AS ASCIIZ * %MAX_PATH  ' // ProgIDs array
GLOBAL TLB_EventsArray () AS STRING               ' // Events array
GLOBAL TLB_InterfacesArray () AS STRING           ' // Interfaces/CoClasses array
GLOBAL TLB_DefaultInterfacesArray () AS STRING    ' // Default interfaces/CoClasses array
GLOBAL TLB_AliasArray () AS STRING                ' // Alias array
GLOBAL TLB_AliasArray2 () AS STRING               ' // Alias array
GLOBAL TLB_LibDoc AS TLB_DOCUMENTATION            ' // Library documentation record
GLOBAL TLB_CanCreate AS LONG                      ' // One or more CoClasses are creatable and non visual
GLOBAL TLB_HasControl AS LONG                     ' // One or more CoClasses are visual
GLOBAL TLB_HasDualInterfaces AS LONG              ' // There are dual interfaces
GLOBAL TLB_HasDispatchOnly AS LONG                ' // There are dispatch only interfaces
GLOBAL TLB_PrefixStr AS STRING                    ' // Prefix string
GLOBAL TLB_strLicKey AS STRING                    ' // License key
GLOBAL TLB_UsesFontInterface AS LONG              ' // Uses the Font interface
GLOBAL TLB_UsesPictureInterface AS LONG           ' // Uses the Picture interface

GLOBAL m_IAutomation AS LONG                      ' // IAutomation interface
GLOBAL m_UseMethod AS LONG                        ' // Use METHOD
GLOBAL m_UsePropGetSet AS LONG                    ' // Use PROPERTY GET/SET
GLOBAL m_UseAutomationView AS LONG                ' // Use Automation view
GLOBAL m_UsePrefix AS LONG                        ' // Use prefix
GLOBAL m_UseEnumPrefix AS LONG                    ' // Use enumeration prefix
GLOBAL m_UseHexNumbers AS LONG                    ' // Use hexadecimal numbers in constants
GLOBAL m_UseSetPrefix AS LONG                     ' // Use set_ instead of put_ as prefix
GLOBAL m_UseIntNamesWithExObj AS LONG             ' // Use interface names with external objects
GLOBAL m_UseParameterNames AS LONG                ' // Use parameter names in interface declarations
GLOBAL m_AddParameterNamesPrefix AS LONG          ' // Add prefix to the parameter names in interface declarations
GLOBAL m_MixDispInterfaces AS LONG                ' // Mix dispatch-only interfaces
GLOBAL m_RetrieveLicenseKey AS LONG               ' // Retrieve license key
GLOBAL m_CodeGeneration AS LONG                   ' // Type of code generation
GLOBAL m_ColumnToSort AS LONG                     ' // Column to sort
GLOBAL m_PrevColSort AS LONG                      ' // Previous column sorted
GLOBAL m_SortOrder AS STRING                      ' // Sort order
GLOBAL m_SelPath AS STRING                        ' // Path of the selected typelib
GLOBAL m_SelDesc AS STRING                        ' // Description of the selected typelib
GLOBAL m_Busy AS LONG                             ' // Busy flag
GLOBAL m_Abort AS LONG                            ' // Abort flag
GLOBAL m_Buffer AS STRING                         ' // Buffer for generated code
GLOBAL m_BufLen AS LONG                           ' // Length of used buffer
GLOBAL m_ItemName AS STRING                       ' // Name of the item to enumerate
GLOBAL m_LastPath AS STRING                       ' // Name of the last accessed path

' Type of code enumeration
%ENUM_ALL                = -1                     ' // All enumerations
%ENUM_COCLASSES          = 1                      ' // CoClasses
%ENUM_CONSTANTS          = 2                      ' // Enumerations
%ENUM_RECORDS            = 3                      ' // Records (structures)
%ENUM_MODULES            = 4                      ' // Modules
%ENUM_TYPEDEFS           = 5                      ' // Typedefs
%ENUM_INTERFACES         = 6                      ' // Interfaces
%ENUM_DISPINTERFACES     = 7                      ' // Dispatch interfaces
%ENUM_CUSTINTERFACES     = 7                      ' // IUnknown interfaces

' Type of code generation (interfaces)
%CODEGEN_DLL             = 1                      ' // External DLL
%CODEGEN_CSTYLE          = 2                      ' // C-Style interfaces
%CODEGEN_VBSTYLE         = 3                      ' // VB-Style interfaces
%CODEGEN_EVENTS          = 4                      ' // Events

' Flags for TLB_Enumerate
%REPORT_VIEWONLY         = 1                      ' // View only
%REPORT_VIEWCODE         = 2                      ' // Generate and show code
%REPORT_CODEONLY         = 4                      ' // Generate code but don't show it

' ========================================================================================
' Procedure for fast concatenation of the string buffer used for generated code.
' ========================================================================================
SUB TLB_AddLine(BYREF strText AS STRING)
   strText = strText & $CRLF
   IF LEN(strText) + m_BufLen > LEN(m_Buffer) THEN
      m_Buffer = m_Buffer & SPACE$(1000000)
   END IF
   MID$(m_Buffer, m_BufLen + 1, LEN(strText)) = strText
   m_BufLen = m_BufLen + LEN(strText)
END SUB
' ========================================================================================

' ========================================================================================
' Customized message box.
' ========================================================================================
FUNCTION TLB_MsgBox (BYVAL hWnd AS DWORD, BYVAL strMessage AS STRING, OPTIONAL BYVAL dwStyle AS DWORD, BYVAL strCaption AS STRING) AS LONG

   LOCAL mbp       AS MSGBOXPARAMS
   LOCAL szCaption AS ASCIIZ * 256

   szCaption = "TypeLib Browser"
   IF LEN(strCaption) THEN szCaption = strCaption
   IF dwStyle = 0 THEN dwStyle = %MB_OK

   ' Initializes MSGBOXPARAMS
   mbp.cbSize = SIZEOF(mbp)                 ' // Size of the structure
   mbp.hwndOwner = hWnd                     ' // Handle of main window
   mbp.hInstance = GetModuleHandle("")      ' // Instance of application
   mbp.lpszText = STRPTR(strMessage)        ' // Text of the message
   mbp.lpszCaption = VARPTR(szCaption)      ' // Caption
   mbp.dwStyle = dwStyle OR %MB_USERICON    ' // Style
   mbp.lpszIcon = %IDI_TLB_LOGO_32          ' // Icon identifier in the resource file

   FUNCTION = MessageBoxIndirect(mbp)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Allows for a breath during long processes and to be able to abort the process clicking
' the Stop button.
' ========================================================================================
SUB TLB_DoEvents (BYVAL hWnd AS DWORD)
   LOCAL Msg AS tagMsg
   WHILE PeekMessage(Msg, %NULL, %NULL, %NULL, %PM_REMOVE)
      IF ISFALSE IsDialogMessage(hWnd, Msg) THEN
         TranslateMessage Msg
         DispatchMessage Msg
      END IF
   WEND
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the path of the application.
' ========================================================================================
FUNCTION TLB_ExePath () AS STRING
   LOCAL buffer AS ASCIIZ * %MAX_PATH
   LOCAL PathPos AS LONG
   GetModuleFileName %NULL, buffer, SIZEOF(buffer)
   PathPos = INSTR(-1, buffer, "\")
   FUNCTION = UCASE$(LEFT$(buffer, PathPos))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks for the existence of the specified file.
' Returns -1 if it exists or 0 otherwise.
' Excludes directories and temporary files.
' ========================================================================================
FUNCTION TLB_FileExist (BYVAL strFileSpec AS STRING) AS LONG

   LOCAL fd     AS WIN32_FIND_DATA
   LOCAL hFound AS DWORD

   IF LEN(strFileSpec) THEN
      hFound = FindFirstFile (BYCOPY strFileSpec, fd)
      IF hFound = %INVALID_HANDLE_VALUE THEN EXIT FUNCTION
      FindClose hFound
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         FUNCTION = -1
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks for the existence of the specified folder.
' ========================================================================================
FUNCTION TLB_FolderExist (BYVAL strFileSpec AS STRING) AS LONG

   LOCAL fd    AS WIN32_FIND_DATA
   LOCAL hFind AS DWORD

   IF ISTRUE LEN (strFileSpec) THEN
      hFind = FindFirstFile (BYCOPY strFileSpec, fd)
      IF hFind = %INVALID_HANDLE_VALUE THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         FUNCTION = -1
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks for the existence of the folder ExePath + \TEMP and creates it if it doesn't exist.
' ========================================================================================
FUNCTION TLB_TempFolder () AS STRING
   LOCAL FileSpec AS STRING
   FileSpec = TLB_ExePath & "TEMP"
   IF ISFALSE TLB_FolderExist(FileSpec) THEN MKDIR FileSpec
   FUNCTION = FileSpec & "\"
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows the Open File dialog.
' ========================================================================================
FUNCTION TLB_OpenTypeLib (BYVAL hWnd AS DWORD) AS STRING

   LOCAL dwStyle AS DWORD
   LOCAL Buffer  AS STRING
   LOCAL f       AS STRING
   LOCAL strPath AS STRING
   LOCAL nPos    AS LONG

   f      = "*.TLB;*.OLB;*.EXE;*.DLL;*.OCX"
   IF LEN(m_LastPath) THEN
      strPath = m_LastPath
   ELSE
      strPath   = CURDIR$
   END IF
   Buffer =          "Type/Object Files (*.TLB,*.OLB)|*.TLB;*.OLB|"
   Buffer = Buffer & "Object modules (*.EXE,*.DLL,*.OCX)|*.EXE;*.DLL;*.OCX|"
   Buffer = Buffer & "All Files (*.*)|*.*"
   dwStyle  = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST

   IF OpenFileDialog(hWnd, "", f, strPath, Buffer, "DLL" , dwStyle) THEN
      SLEEP 1        ' Take a breath...
      nPos = INSTR(-1, f, ANY "/\")
      m_LastPath = LEFT$(f, nPos)
      FUNCTION = f
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves rich edit control's contents to file.
' ========================================================================================
SUB TLB_SaveReport (BYVAL hWnd AS DWORD, BYVAL f AS STRING)

   LOCAL hFile        AS DWORD
   LOCAL dwStyle      AS DWORD
   LOCAL fOptions     AS STRING
   LOCAL Buffer       AS STRING
   LOCAL strPath      AS STRING
   LOCAL fType        AS STRING
   LOCAL hFocus       AS DWORD
   LOCAL nPos         AS LONG
   LOCAL hPageCtrl    AS DWORD
   LOCAL hRichEditBox AS DWORD

   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_CODE)
   IF hPageCtrl = %NULL THEN EXIT SUB
   hRichEditBox = GetDlgItem(hPageCtrl, %IDC_DIALOG1_RICHEDIT_VIEWCODE)
   IF hRichEditBox = %NULL THEN EXIT SUB

   hFocus = GetFocus

   Buffer = Edit_GetText(hRichEditBox)
   IF LEN(Buffer) = 0 THEN
      MessageBox BYVAL %NULL, "There is not code to save", _
         " " & FUNCNAME$ & ": Save file", %MB_OK OR %MB_ICONINFORMATION OR %MB_TASKMODAL
      SetFocus hFocus
      EXIT SUB
   END IF

   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR _
             %OFN_HIDEREADONLY OR %OFN_OVERWRITEPROMPT
   fOptions =            "PB Code Files (*.BAS,*.INC)|*.BAS;*.INC|"
   fOptions = fOptions & "Text Files (*.TXT)|*.TXT|"
   fOptions = fOptions & "All Files (*.*)|*.*"

   IF LEN(f) = 0 THEN
      IF LEN(m_LastPath) THEN
         strPath = m_LastPath
      ELSE
         strPath  = CURDIR$
      END IF
      f     = "NONAME.INC"
      fType = "INC"
   ELSE
      nPos = INSTR(-1, f, ANY "/\")
      IF nPos THEN
         strPath = LEFT$(f, nPos)
         f    = MID$(f, nPos + 1)  ' Dialog will return full strPath and file name
         IF INSTR(-1, f, ".") THEN
            fType = MID$(f, INSTR(-1, f, ".") + 1 )
         END IF
      END IF
   END IF

   ' Show Save dialog. If user selects Cancel in Save dialog, exit.
   IF ISFALSE(SaveFileDialog(hWnd, "", f, strPath, fOptions, fType, dwStyle)) THEN
      SetFocus hFocus
      EXIT SUB
   END IF

   SLEEP 1 ' Take a breath..

   hFile = FREEFILE                                        ' Get free file handle
   OPEN f FOR BINARY AS hFile LEN = 8192                   ' Open file for binary write
   IF ERR THEN
      MessageBox hWnd, "Error " & FORMAT$(ERR) & " saving the file", "Error", %MB_OK OR %MB_ICONEXCLAMATION
   ELSE
      PUT$ hFile, Buffer                                   ' Write Buffer to disk
      SETEOF hFile                                         ' Truncate file to proper length
      CLOSE hFile                                          ' Close file handle
   END IF

   nPos = INSTR(-1, f, ANY "/\")
   m_LastPath = LEFT$(f, nPos)

   SetFocus hFocus
   EXIT SUB

END SUB
' ========================================================================================

' ========================================================================================
' Function    : TLB_IniRead
' Description : Reads data from the Applications INI file.
' Usage       : sText = IniRead ("INIFILE", "SECTION", "KEY", "DEFAULT")
'             : lVal  = VAL (IniRead ("INIFILE", "SECTION", "KEY", "DEFAULT"))
' ========================================================================================
FUNCTION TLB_IniRead (BYVAL strIniFile AS STRING, _
                      BYVAL strSection AS STRING, _
                      BYVAL strKey     AS STRING, _
                      BYVAL strDefault AS STRING) AS STRING

   LOCAL hr        AS LONG
   LOCAL szSection AS ASCIIZ * 125
   LOCAL szKey     AS ASCIIZ * 125
   LOCAL szData    AS ASCIIZ * 150
   LOCAL szDefault AS ASCIIZ * 150
   LOCAL szIniFile AS ASCIIZ * %MAX_PATH

   szSection = strSection
   szKey     = strKey
   szIniFile = strIniFile
   szDefault = strDefault

   hr = GetPrivateProfileString(szSection, szKey, szDefault, szData, SIZEOF(szData), szIniFile)

   FUNCTION = szData

END FUNCTION
' ========================================================================================

' ========================================================================================
' Function    : TLB_IniWrite
' Description : Saves data to the Applications INI file.
' Usage       : lResult = IniWrite ("INIFILE", "SECTION", "KEY", "VALUE")
' ========================================================================================
FUNCTION TLB_IniWrite (BYVAL strIniFile AS STRING, _
                       BYVAL strSection AS STRING, _
                       BYVAL strKey     AS STRING, _
                       BYVAL strValue   AS STRING) AS LONG

   LOCAL szSection AS ASCIIZ * 125
   LOCAL szKey     AS ASCIIZ * 125
   LOCAL szValue   AS ASCIIZ * 150
   LOCAL szIniFile AS ASCIIZ * %MAX_PATH

   szSection = strSection
   szKey     = strKey
   szIniFile = strIniFile
   szValue   = TRIM$(strValue)

   FUNCTION = WritePrivateProfileString(szSection, szKey, szValue, szIniFile)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts LibFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_LibFlagsToStr (BYVAL iFlags AS INTEGER) AS STRING

   LOCAL strFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %LIBFLAG_FRESTRICTED) = %LIBFLAG_FRESTRICTED THEN strFlags += " [Restricted]"
   IF (iFlags AND %LIBFLAG_FCONTROL) = %LIBFLAG_FCONTROL THEN strFlags += " [Control]"
   IF (iFlags AND %LIBFLAG_FHIDDEN) = %LIBFLAG_FHIDDEN THEN strFlags += " [Hidden]"
   IF (iFlags AND %LIBFLAG_FHASDISKIMAGE) = %LIBFLAG_FHASDISKIMAGE THEN strFlags += " [HasDiskImage]"

   FUNCTION = strFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts InterfaceFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_InterfaceFlagsToStr (BYVAL iFlags AS INTEGER) AS STRING

   LOCAL strFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %TYPEFLAG_FAPPOBJECT) = %TYPEFLAG_FAPPOBJECT THEN strFlags += " [Application]"
   IF (iFlags AND %TYPEFLAG_FCANCREATE) = %TYPEFLAG_FCANCREATE THEN strFlags += " [Cancreate]"
   IF (iFlags AND %TYPEFLAG_FLICENSED) = %TYPEFLAG_FLICENSED THEN strFlags += " [Licensed]"
   IF (iFlags AND %TYPEFLAG_FPREDECLID) = %TYPEFLAG_FPREDECLID THEN strFlags += " [Predefined]"
   IF (iFlags AND %TYPEFLAG_FHIDDEN) = %TYPEFLAG_FHIDDEN THEN strFlags += " [Hidden]"
   IF (iFlags AND %TYPEFLAG_FCONTROL) = %TYPEFLAG_FCONTROL THEN strFlags += " [Control]"
   IF (iFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN strFlags += " [Dual]"
   IF (iFlags AND %TYPEFLAG_FNONEXTENSIBLE) = %TYPEFLAG_FNONEXTENSIBLE THEN strFlags += " [Nonextensible]"
   IF (iFlags AND %TYPEFLAG_FOLEAUTOMATION) = %TYPEFLAG_FOLEAUTOMATION THEN strFlags += " [Oleautomation]"
   IF (iFlags AND %TYPEFLAG_FRESTRICTED) = %TYPEFLAG_FRESTRICTED THEN strFlags += " [Restricted]"
   IF (iFlags AND %TYPEFLAG_FAGGREGATABLE) = %TYPEFLAG_FAGGREGATABLE THEN strFlags += " [Aggregatable]"
   IF (iFlags AND %TYPEFLAG_FREPLACEABLE) = %TYPEFLAG_FREPLACEABLE THEN strFlags += " [Replaceable]"
   IF (iFlags AND %TYPEFLAG_FDISPATCHABLE) = %TYPEFLAG_FDISPATCHABLE THEN strFlags += " [Dispatchable]"
   IF (iFlags AND %TYPEFLAG_FREVERSEBIND) = %TYPEFLAG_FREVERSEBIND THEN strFlags += " [Reversebind]"
   IF (iFlags AND %TYPEFLAG_FPROXY) = %TYPEFLAG_FPROXY THEN strFlags += " [Proxy]"

   FUNCTION = strFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts ImplTypeFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_ImplTypeFlagsToStr (BYVAL iFlags AS INTEGER) AS STRING

   LOCAL strFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %IMPLTYPEFLAG_FDEFAULT) = %IMPLTYPEFLAG_FDEFAULT THEN strFlags += " [Default]"
   IF (iFlags AND %IMPLTYPEFLAG_FSOURCE) = %IMPLTYPEFLAG_FSOURCE THEN strFlags += " [Source]"
   IF (iFlags AND %IMPLTYPEFLAG_FRESTRICTED) = %IMPLTYPEFLAG_FRESTRICTED THEN strFlags += " [Restricted]"
   IF (iFlags AND %IMPLTYPEFLAG_FDEFAULTVTABLE) = %IMPLTYPEFLAG_FDEFAULTVTABLE THEN strFlags += " [Default VTable]"

   FUNCTION = strFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts FuncFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_FuncFlagsToStr (BYVAL iFlags AS INTEGER) AS STRING

   LOCAL strFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %FUNCFLAG_FRESTRICTED) = %FUNCFLAG_FRESTRICTED THEN strFlags += " [Restricted]"
   IF (iFlags AND %FUNCFLAG_FSOURCE) = %FUNCFLAG_FSOURCE THEN strFlags += " [Source]"
   IF (iFlags AND %FUNCFLAG_FBINDABLE) = %FUNCFLAG_FBINDABLE THEN strFlags += " [Bindable]"
   IF (iFlags AND %FUNCFLAG_FREQUESTEDIT) = %FUNCFLAG_FREQUESTEDIT THEN strFlags += " [RequestEdit]"
   IF (iFlags AND %FUNCFLAG_FDISPLAYBIND) = %FUNCFLAG_FDISPLAYBIND THEN strFlags += " [DisplayBind]"
   IF (iFlags AND %FUNCFLAG_FDEFAULTBIND) = %FUNCFLAG_FDEFAULTBIND THEN strFlags += " [DefaultBind]"
   IF (iFlags AND %FUNCFLAG_FHIDDEN) = %FUNCFLAG_FHIDDEN THEN strFlags += " [Hidden]"
   IF (iFlags AND %FUNCFLAG_FUSESGETLASTERROR) = %FUNCFLAG_FUSESGETLASTERROR THEN strFlags += " [UsesGetLastError]"
   IF (iFlags AND %FUNCFLAG_FDEFAULTCOLLELEM) = %FUNCFLAG_FDEFAULTCOLLELEM THEN strFlags += " [DefaultCollELem]"
   IF (iFlags AND %FUNCFLAG_FUIDEFAULT) = %FUNCFLAG_FUIDEFAULT THEN strFlags += " [UserInterfaceDefault]"
   IF (iFlags AND %FUNCFLAG_FNONBROWSABLE) = %FUNCFLAG_FNONBROWSABLE THEN strFlags += " [NonBrowsable]"
   IF (iFlags AND %FUNCFLAG_FREPLACEABLE) = %FUNCFLAG_FREPLACEABLE THEN strFlags += " [Replaceable]"
   IF (iFlags AND %FUNCFLAG_FIMMEDIATEBIND) = %FUNCFLAG_FIMMEDIATEBIND THEN strFlags += " [InmediateBind]"

   FUNCTION = strFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts ParamFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_ParamflagsToStr (BYVAL iFlags AS INTEGER) AS STRING

   LOCAL strFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %PARAMFLAG_FOPT) = %PARAMFLAG_FOPT THEN strFlags += " [opt]"
   IF (iFlags AND %PARAMFLAG_FRETVAL) = %PARAMFLAG_FRETVAL THEN strFlags += " [retval]"
   IF (iFlags AND %PARAMFLAG_FIN) = %PARAMFLAG_FIN THEN strFlags += " [in]"
   IF (iFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT THEN strFlags += " [out]"
   IF (iFlags AND %PARAMFLAG_FLCID) = %PARAMFLAG_FLCID THEN strFlags += " [lcid]"
   IF (iFlags AND %PARAMFLAG_FHASDEFAULT) = %PARAMFLAG_FHASDEFAULT THEN strFlags += " [hasdefault]"
   IF (iFlags AND %PARAMFLAG_FHASCUSTDATA) = %PARAMFLAG_FHASCUSTDATA THEN strFlags += " [hascustdata]"

   FUNCTION = strFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts VarFlags to a descriptive string.
' ========================================================================================
  FUNCTION TLB_VarFlagsToStr (BYVAL iFlags AS INTEGER) AS STRING

     LOCAL strFlags AS STRING

     IF iFlags = 0 THEN strFlags = " [None]"
     IF (iFlags AND %VARFLAG_FREADONLY) = %VARFLAG_FREADONLY THEN strFlags += " [ReadOnly]"
     IF (iFlags AND %VARFLAG_FSOURCE) = %VARFLAG_FSOURCE THEN strFlags += " [Source]"
     IF (iFlags AND %VARFLAG_FBINDABLE) = %VARFLAG_FBINDABLE THEN strFlags += " [Bindable]"
     IF (iFlags AND %VARFLAG_FREQUESTEDIT) = %VARFLAG_FREQUESTEDIT THEN strFlags += " [RequestEdit]"
     IF (iFlags AND %VARFLAG_FDISPLAYBIND) = %VARFLAG_FDISPLAYBIND THEN strFlags += " [DisplayBind]"
     IF (iFlags AND %VARFLAG_FDEFAULTBIND) = %VARFLAG_FDEFAULTBIND THEN strFlags += " [DefaultBind]"
     IF (iFlags AND %VARFLAG_FHIDDEN) = %VARFLAG_FHIDDEN THEN strFlags += " [Hidden]"
     IF (iFlags AND %VARFLAG_FRESTRICTED) = %VARFLAG_FRESTRICTED THEN strFlags += " [Restricted]"
     IF (iFlags AND %VARFLAG_FDEFAULTCOLLELEM) = %VARFLAG_FDEFAULTCOLLELEM THEN strFlags += " [DefaultCollElem]"
     IF (iFlags AND %VARFLAG_FUIDEFAULT) = %VARFLAG_FUIDEFAULT THEN strFlags += " [User interface default]"
     IF (iFlags AND %VARFLAG_FNONBROWSABLE) = %VARFLAG_FNONBROWSABLE THEN strFlags += " [NoBrowsable]"
     IF (iFlags AND %VARFLAG_FREPLACEABLE) = %VARFLAG_FREPLACEABLE THEN strFlags += " [Replaceable]"
     IF (iFlags AND %VARFLAG_FIMMEDIATEBIND) = %VARFLAG_FIMMEDIATEBIND THEN strFlags += " [ImmediateBind]"

     FUNCTION = strFlags

  END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the VarType.
' ========================================================================================
FUNCTION VarTypeToStr (BYVAL VarType AS LONG, OPTIONAL BYVAL fReturnType AS LONG) AS STRING

   LOCAL s AS STRING

   SELECT CASE AS LONG VarType
      CASE     0 : s = "VT_EMPTY"
      CASE     1 : s = "VT_NULL"
      CASE     2 : s = "VT_I2 <Integer>"
      CASE     3 : s = "VT_I4 <Long>"
      CASE     4 : s = "VT_R4 <Single>"
      CASE     5 : s = "VT_R8 <Double>"
      CASE     6 : s = "VT_CY <Cur>"
      CASE     7 : s = "VT_DATE <Double>"
      CASE     8 : s = "VT_BSTR"
      CASE     9 : s = "VT_DISPATCH <IDispatch>"
      CASE    10 : s = "VT_ERROR <Long>"
      CASE    11 : s = "VT_BOOL <Integer>"
      CASE    12 : s = "VT_VARIANT <Variant>"
      CASE    13 : s = "VT_UNKNOWN <IUnknown>"
      CASE    14 : s = "VT_DECIMAL"
      CASE    16 : s = "VT_I1 <Byte>"
      CASE    17 : s = "VT_UI1 <Byte>"
      CASE    18 : s = "VT_UI2 <Word>"
      CASE    19 : s = "VT_UI4 <Dword>"
      CASE    20 : s = "VT_I8 <Quad>"
      CASE    21 : s = "VT_UI8 <Quad>"
      CASE    22 : s = "VT_INT <Long>"
      CASE    23 : s = "VT_UINT <Dword>"
      CASE    24 :
         IF ISTRUE fReturnType THEN
            s = "VT_VOID"
         ELSE
            s = "VT_VOID <Dword>"
         END IF
      CASE    25 : s = "VT_HRESULT <Long>"
      CASE    26 : s = "VT_PTR <Pointer>"
      CASE    27 : s = "VT_SAFEARRAY"
      CASE    28 : s = "VT_CARRAY"
      CASE    29 : s = "VT_USERDEFINED"
      CASE    30 : s = "VT_LPSTR"
      CASE    31 : s = "VT_LPWSTR"
      CASE    36 : s = "VT_RECORD"
      CASE    64 : s = "VT_FILETIME"
      CASE    65 : s = "VT_BLOB"
      CASE    66 : s = "VT_STREAM"
      CASE    67 : s = "VT_STORAGE"
      CASE    68 : s = "VT_STREAMED_OBJECT"
      CASE    69 : s = "VT_STORED_OBJECT"
      CASE    70 : s = "VT_BLOB_OBJECT"
      CASE    71 : s = "VT_CF"
      CASE    72 : s = "VT_CLSID <Guid>"
      CASE  4096 : s = "VT_VECTOR"
      CASE  8192 : s = "VT_ARRAY"
      CASE 16384 : s = "VT_BYREF"
      CASE 32768 : s = "VT_RESERVED"
   END SELECT

   FUNCTION = s

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the VarType.
' ========================================================================================
FUNCTION VarTypeToConstant (BYVAL VarType AS LONG) AS STRING

   LOCAL s AS STRING

   SELECT CASE AS LONG VarType
      CASE     0 : s = "VT_EMPTY"
      CASE     1 : s = "VT_NULL"
      CASE     2 : s = "VT_I2"
      CASE     3 : s = "VT_I4"
      CASE     4 : s = "VT_R4"
      CASE     5 : s = "VT_R8"
      CASE     6 : s = "VT_CY"
      CASE     7 : s = "VT_DATE"
      CASE     8 : s = "VT_BSTR"
      CASE     9 : s = "VT_DISPATCH"
      CASE    10 : s = "VT_ERROR"
      CASE    11 : s = "VT_BOOL"
      CASE    12 : s = "VT_VARIANT"
      CASE    13 : s = "VT_UNKNOWN"
      CASE    14 : s = "VT_DECIMAL"
      CASE    16 : s = "VT_I1"
      CASE    17 : s = "VT_UI1"
      CASE    18 : s = "VT_UI2"
      CASE    19 : s = "VT_UI4"
      CASE    20 : s = "VT_I8"
      CASE    21 : s = "VT_UI8"
      CASE    22 : s = "VT_INT"
      CASE    23 : s = "VT_UINT"
      CASE    24 : s = "VT_VOID"
      CASE    25 : s = "VT_HRESULT"
      CASE    26 : s = "VT_PTR"
      CASE    27 : s = "VT_SAFEARRAY"
      CASE    28 : s = "VT_CARRAY"
      CASE    29 : s = "VT_USERDEFINED"
      CASE    30 : s = "VT_LPSTR"
      CASE    31 : s = "VT_LPWSTR"
      CASE    36 : s = "VT_RECORD"
      CASE    64 : s = "VT_FILETIME"
      CASE    65 : s = "VT_BLOB"
      CASE    66 : s = "VT_STREAM"
      CASE    67 : s = "VT_STORAGE"
      CASE    68 : s = "VT_STREAMED_OBJECT"
      CASE    69 : s = "VT_STORED_OBJECT"
      CASE    70 : s = "VT_BLOB_OBJECT"
      CASE    71 : s = "VT_CF"
      CASE    72 : s = "VT_CLSID"
      CASE  4096 : s = "VT_VECTOR"
      CASE  8192 : s = "VT_ARRAY"
      CASE 16384 : s = "VT_BYREF"
      CASE 32768 : s = "VT_RESERVED"
   END SELECT

   FUNCTION = s

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the VarType.
' ========================================================================================
FUNCTION VarTypeToKeyword (BYVAL VarType AS LONG, OPTIONAL BYVAL cElements AS WORD) AS STRING

   ' Note: VT_I1 is an array of bytes; translate it to a fixed string

   LOCAL s AS STRING

   SELECT CASE AS LONG VarType
      CASE     0 : s = "DWORD"                              ' VT_EMPTY
      CASE     1 : s = "DWORD"                              ' VT_NULL
      CASE     2 : s = "INTEGER"                            ' VT_I2
      CASE     3 : s = "LONG"                               ' VT_I4
      CASE     4 : s = "SINGLE"                             ' VT_R4
      CASE     5 : s = "DOUBLE"                             ' VT_R8
      CASE     6 : s = "CUR"                                ' VT_CY
      CASE     7 : s = "DOUBLE"                             ' VT_DATE
      CASE     8 : s = "WSTRING"                            ' VT_BSTR
      CASE     9 : s = "IDispatch"                          ' VT_DISPATCH
      CASE    10 : s = "LONG"                               ' VT_ERROR
      CASE    11 : s = "INTEGER"                            ' VT_BOOL
      CASE    12 : s = "VARIANT"                            ' VT_VARIANT
      CASE    13 : s = "IUnknown"                           ' VT_UNKNOWN
      CASE    14 : s = "DWORD"                              ' VT_DECIMAL
      CASE 16, 17                                           ' VT_I1, VT_UI1
         IF cElements THEN
            s = "STRING * " & FORMAT$(cElements)            ' Byte array
         ELSE
            s = "BYTE"
         END IF
      CASE    18 : s = "WORD"                               ' VT_UI2
      CASE    19 : s = "DWORD"                              ' VT_UI4
      CASE    20 : s = "QUAD"                               ' VT_I8
      CASE    21 : s = "QUAD"                               ' VT_UI8
      CASE    22 : s = "LONG"                               ' VT_INT
      CASE    23 : s = "DWORD"                              ' VT_UINT
      CASE    24 : s = "DWORD"                              ' VT_VOID
      CASE    25 : s = "LONG"                               ' VT_HRESULT
      CASE    26 : s = "DWORD"                              ' VT_PTR
      CASE    27 : s = "DWORD"                              ' VT_SAFEARRAY
      CASE    28 : s = "DWORD"                              ' VT_CARRAY
      CASE    29 : s = "DWORD"                              ' VT_USERDEFINED
      CASE    30 : s = "ASCIIZ"                             ' VT_LPSTR
      CASE    31 : s = "WSTRINGZ"                           ' VT_LPWSTR
      CASE    36 : s = "DWORD"                              ' VT_RECORD
      CASE    64 : s = "FILETIME"                           ' VT_FILETIME
      CASE    65 : s = "DWORD"                              ' VT_BLOB
      CASE    66 : s = "DWORD"                              ' VT_STREAM
      CASE    67 : s = "DWORD"                              ' VT_STORAGE
      CASE    68 : s = "DWORD"                              ' VT_STREAMED_OBJECT
      CASE    69 : s = "DWORD"                              ' VT_STORED_OBJECT
      CASE    70 : s = "DWORD"                              ' VT_BLOB_OBJECT
      CASE    71 : s = "DWORD"                              ' VT_CF
      CASE    72 : s = "GUID"                               ' VT_CLSID
      CASE  4096 : s = "DWORD"                              ' VT_VECTOR
      CASE  8192 : s = "DWORD"                              ' VT_ARRAY
      CASE 16384 : s = "VT_BYREF"
      CASE 32768 : s = "VT_RESERVED"
   END SELECT

   FUNCTION = s

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the appropiate member name of the variant union for byref parameters.
' Note: VT_HRESULT isn't an automation compatible type, but the CreatePartnershipComplete
' event of Windows Media Player has a parameter of this type.
' ========================================================================================
FUNCTION GetUnionMemberName (BYVAL vt AS LONG) AS STRING

   LOCAL strvt AS STRING

   SELECT CASE vt
      CASE %VT_I1, %VT_UI1 : strvt = "pbVal"
      CASE %VT_I2 : strvt = "piVal"
      CASE %VT_I4, %VT_INT, %VT_UI4, %VT_UINT, %VT_HRESULT : strvt = "plVal"
      CASE %VT_R4 : strvt = "pfltVal"
      CASE %VT_R8, %VT_I8, %VT_UI8 : strvt = "pdblVal"
      CASE %VT_BOOL : strvt = "pboolVal"
      CASE %VT_ERROR : strvt = "pscode"
      CASE %VT_CY : strvt = "pcyVal"
      CASE %VT_DATE : strvt = "pdate"
      CASE %VT_BSTR : strvt = "pbstrVal"
      CASE %VT_UNKNOWN : strvt = "ppunkVal"
      CASE %VT_DISPATCH : strvt = "ppdispVal"
      CASE %VT_ARRAY : strvt = "psArray"
      CASE %VT_VARIANT : strvt = "pVariant"
      CASE ELSE : strvt = "plVal"
   END SELECT

   FUNCTION = strvt

END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function to return the type of a variant given its address.
' ========================================================================================
FUNCTION TLB_VarType (BYVAL pv AS DWORD) AS DWORD
   LOCAL pvt AS VARIANT PTR
   IF pv = 0 THEN EXIT FUNCTION
   pvt = pv
   FUNCTION = VARIANTVT(@pvt)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function to read the contents of a VARIANT containing an string given its address.
' This can be used to retrieve the result of functions that return the adddress of a variant
' as the result.
' ========================================================================================
FUNCTION TLB_VarToStr (BYVAL pv AS DWORD) AS STRING
   LOCAL pvt AS VARIANT PTR
   IF pv = 0 THEN EXIT FUNCTION
   pvt = pv
   FUNCTION = VARIANT$(@pvt)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function to read the contents of a VARIANT containing a numeric value given its address.
' This can be used to retrieve the result of functions that return the adddress of a variant
' as the result.
' ========================================================================================
FUNCTION TLB_VarToNum (BYVAL pv AS DWORD) AS EXT
   LOCAL pvt AS VARIANT PTR
   IF pv = 0 THEN EXIT FUNCTION
   pvt = pv
   FUNCTION = VARIANT#(@pvt)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the guid of the typelib that implements a given interface.
' strIID is the human readable guid of the interface.
' ========================================================================================
FUNCTION TLB_GetTypeLibFromInterfaceIID ( _
   BYVAL strIID            AS STRING _
 , BYREF strTypeLibGuid    AS STRING _
 , BYREF strTypelibVersion AS STRING _
 , BYREF wTypeLibVerMajor  AS WORD _
 , BYREF wTypeLibVerMinor  AS WORD _
 , BYREF strTypeLibPath    AS STRING _
   ) AS LONG

   LOCAL szKey           AS ASCIIZ * %MAX_PATH
   LOCAL hKey            AS DWORD
   LOCAL dwIdx           AS DWORD
   LOCAL hr              AS LONG
   LOCAL szValueName     AS ASCIIZ * %MAX_PATH
   LOCAL KeyType         AS DWORD
   LOCAL szKeyValue      AS ASCIIZ * %MAX_PATH
   LOCAL cbValueName     AS DWORD
   LOCAL cbData          AS DWORD
   LOCAL p               AS LONG
   LOCAL rTypeLibGuid    AS GUID
   LOCAL bstrTypeLibPath AS WSTRING

   ' Searches the HKEY_CLASSES_ROOT\Interface\<IID>\Typelib node.
   szKey = "Interface\" & strIID & "\TypeLib"
   hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN
      FUNCTION = hr
      EXIT FUNCTION
   END IF

   ' Retrieves the Guid of the TypeLib
   dwIdx = 0
   cbValueName = %MAX_PATH
   cbData = %MAX_PATH
   KeyType = %REG_SZ
   hr = RegEnumValue (hKey, dwIdx, szValueName, cbValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
   strTypeLibGuid = szKeyValue
   rTypeLibGuid = GUID$(strTypeLibGuid)

   ' Retrieves the version
   DO
      dwIdx = dwIdx + 1
      cbValueName = %MAX_PATH
      cbData = %MAX_PATH
      KeyType = %REG_SZ
      szValueName = ""
      hr = RegEnumValue (hKey, dwIdx, szValueName, cbValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
      IF hr <> %ERROR_SUCCESS THEN EXIT DO
      IF UCASE$(szValueName) = "VERSION" THEN
         strTypeLibVersion = szKeyValue
         p = INSTR(strTypeLibVersion, ".")
         IF p = 0 THEN
            wTypelibVerMajor = VAL(strTypeLibVersion)
         ELSE
            wTypeLibVerMajor = VAL(LEFT$(strTypeLibVersion, p - 1))
            wTypelibVerMinor = VAL(MID$(strTypeLibVersion, p + 1))
         END IF
         EXIT DO
      END IF
   LOOP

   ' Closes the registry
   RegCloseKey hKey

   ' Retrieves the path of the TypeLib
   hr = QueryPathOfRegTypeLib(rTypeLibGuid, wTypeLibVerMajor, wTypeLibVerMinor, 0, bstrTypeLibPath)
   strTypeLibPath = bstrTypeLibPath

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the implemented interface.
' ========================================================================================
FUNCTION TLB_GetImplementedInterfaceIID ( _
   BYVAL pITypeInfo AS ITypeInfo _
 , OPTIONAL BYVAL idx AS LONG _
   ) AS STRING

   LOCAL hr            AS LONG               ' // HRESULT
   LOCAL pRefType      AS DWORD              ' // Address to a referenced type description
   LOCAL pImplTypeInfo AS ITypeInfo          ' // Implemented interface type info
   LOCAL pTypeAttr     AS TYPEATTR PTR       ' // Address of a pointer to the TYPEATTR structure
   LOCAL bstrName      AS WSTRING            ' // Interface's name (unicode)

   hr = pITypeInfo.GetRefTypeOfImplType(idx, pRefType)
   IF hr <> %S_OK OR pRefType = %NULL THEN EXIT FUNCTION
   hr = pITypeInfo.GetRefTypeInfo(pRefType, pImplTypeInfo)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FUNCTION
   pImplTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   FUNCTION = bstrName
   hr = pImplTypeInfo.GetTypeAttr(pTypeAttr)
   IF hr = %S_OK AND pTypeAttr <> %NULL THEN
      FUNCTION = (GUIDTXT$(@pTypeAttr.guid))
      pImplTypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pImplTypeInfo = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the implemented interface.
' ========================================================================================
FUNCTION TLB_GetImplementedInterface ( _
   BYVAL pITypeInfo AS ITypeInfo _
 , OPTIONAL BYVAL idx AS LONG _
   ) AS STRING

   LOCAL hr            AS LONG               ' // HRESULT
   LOCAL pRefType      AS DWORD              ' // Address to a referenced type description
   LOCAL pImplTypeInfo AS ITypeInfo          ' // Implemented interface type info
   LOCAL bstrName      AS WSTRING            ' // Interface's name (unicode)

   hr = pITypeInfo.GetRefTypeOfImplType(idx, pRefType)
   IF hr <> %S_OK OR pRefType = %NULL THEN EXIT FUNCTION
   hr = pITypeInfo.GetRefTypeInfo(pRefType, pImplTypeInfo)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FUNCTION
   pImplTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   FUNCTION = bstrName
   pImplTypeInfo = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the inherited interface
' ========================================================================================
FUNCTION TLB_GetInheritedInterface ( _
   BYVAL pITypeInfo AS ITypeInfo _
 , OPTIONAL BYVAL idx AS LONG _
   ) AS STRING

   LOCAL hr            AS LONG               ' // HRESULT
   LOCAL pRefType      AS DWORD              ' // Address to a referenced type description
   LOCAL pImplTypeInfo AS ITypeInfo          ' // Implied interface type info
   LOCAL pTypeAttr     AS TYPEATTR PTR       ' // Address of a pointer to the TYPEATTR structure

   hr = pITypeInfo.GetRefTypeOfImplType(idx, pRefType)
   IF hr <> %S_OK OR pRefType = %NULL THEN EXIT FUNCTION
   hr = pITypeInfo.GetRefTypeInfo (pRefType, pImplTypeInfo)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FUNCTION
   hr = pImplTypeInfo.GetTypeAttr(pTypeAttr)
   IF hr = %S_OK AND pTypeAttr <> %NULL THEN
      IF @pTypeAttr.cImplTypes = 1 THEN
         FUNCTION = TLB_GetImplementedInterface(pImplTypeInfo, 0)
      END IF
      pImplTypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pImplTypeInfo = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the base class
' ========================================================================================
FUNCTION TLB_GetBaseClass ( _
   BYVAL hWnd                  AS DWORD _              ' // Handle of the main window
 , BYVAL pITypeLib             AS ITypeLib _           ' // ITypeLib interface
 , BYVAL strItemName           AS STRING _             ' // Item to retrieve
   ) AS STRING

   LOCAL hr                    AS LONG                 ' // HRESULT
   LOCAL i                     AS LONG                 ' // Loop counter
   LOCAL TypeInfoCount         AS LONG                 ' // Number of TypeInfos
   LOCAL pITypeInfo            AS ITypeInfo            ' // TypeInfo interface
   LOCAL pTypeAttr             AS TYPEATTR PTR         ' // Address of a pointer to the TYPEATTR structure
   LOCAL pTKind                AS DWORD                ' // TYPEKIND
   LOCAL bstrName              AS WSTRING              ' // Member's name (unicode)
   LOCAL bstrDocString         AS WSTRING              ' // Documentation string (unicode)
   LOCAL pdwHelpContext        AS DWORD                ' // Help context
   LOCAL bstrHelpFile          AS WSTRING              ' // Help file (unicode)
   LOCAL szInterfaceName       AS ASCIIZ * 256         ' // Interface name
   LOCAL pRefType              AS DWORD                ' // Address to a referenced type description
   LOCAL pRefTypeInfo          AS ITypeInfo            ' // Referenced TypeInfo interface
   LOCAL pRefTypeAttr          AS TYPEATTR PTR         ' // Referenced TYPEATTR structure
   LOCAL strInheritedInterface AS STRING               ' // Inherited interface

   TypeInfoCount = pITypeLib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN EXIT FUNCTION

   FOR i = 0 TO TypeInfoCount - 1

      ' --- Allow for a breath and check the abort flag ---------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR
      ' --- Retrieves the TypeKind ------------------------------------------------------
      hr = pITypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN EXIT FOR
      ' --- Retrieves the TypeInfo interface --------------------------------------------
      hr = pITypeLib.GetTypeInfo(i, pITypeInfo)
      IF hr <> %S_OK THEN EXIT FOR
      ' --- Gets the address of a pointer to the TYPEATTR structure ---------------------
      hr = pITypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN EXIT FOR
      ' --- If it is an interface ... ---------------------------------------------------
      IF pTKind = %TKIND_INTERFACE OR pTKind = %TKIND_DISPATCH THEN
         hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' -- If it is the interface we are looking for... ------------------------------
         szInterfaceName = bstrName
         IF szInterfaceName = strItemName THEN
            ' --- If it inherits from another interface, recursively search the methods
            IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
               strInheritedInterface = TLB_GetInheritedInterface(pITypeInfo, -1)
            ELSE
               strInheritedInterface = TLB_GetImplementedInterface(pITypeInfo)
            END IF
            ' Check also that the interface doesn't inherit from itself!
            IF UCASE$(strInheritedInterface) <> "IUNKNOWN" AND UCASE$(strInheritedInterface) <> "IDISPATCH" AND UCASE$(strInheritedInterface) <> UCASE$(szInterfaceName) THEN
               strInheritedInterface = TLB_GetBaseClass(hWnd, pITypeLib, strInheritedInterface)
            END IF
            ' --- End recursion ---------------------------------------------------------
         END IF
      END IF
      ' --- Releases the TYPEATTR structure ---------------------------------------------
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0
      ' --- Releases the TypeInfo interface ---------------------------------------------
      pITypeInfo = NOTHING
   NEXT

   ' --- Releases the interfaces --------------------------------------------------------
   IF ISTRUE pTypeAttr THEN
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pITypeInfo = NOTHING
   pITypeLib = NOTHING

   FUNCTION = strInheritedInterface

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the ProgID from the registry.
' ========================================================================================
FUNCTION TLB_GetProgID (BYVAL strGuid AS STRING) AS STRING

   LOCAL hKey        AS DWORD                ' // Handle of the opned key
   LOCAL dwIdx       AS DWORD                ' // Index of the value to be retrieved
   LOCAL szKey       AS ASCIIZ * %MAX_PATH   ' // Name of the subkey to open
   LOCAL szKeyValue  AS ASCIIZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL szValueName AS ASCIIZ * %MAX_PATH   ' // Name of the value
   LOCAL cValueName  AS DWORD                ' // Size of szValueName
   LOCAL cbData      AS DWORD                ' // Size of szKeyValue
   LOCAL KeyType     AS DWORD                ' // Type of data

   szKey = "CLSID\" & strGuid & "\ProgID"
   RegOpenKeyEx %HKEY_CLASSES_ROOT, szKey , 0, %KEY_READ, hKey
   IF hKey THEN
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      RegEnumValue hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData
      RegCloseKey hKey
      FUNCTION = szKeyValue
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Version Independent ProgID from the registry.
' ========================================================================================
FUNCTION TLB_GetVersionIndependentProgID (BYVAL strGuid AS STRING) AS STRING

   LOCAL hKey        AS DWORD                ' // Handle of the opned key
   LOCAL dwIdx       AS DWORD                ' // Index of the value to be retrieved
   LOCAL szKey       AS ASCIIZ * %MAX_PATH   ' // Name of the subkey to open
   LOCAL szKeyValue  AS ASCIIZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL szValueName AS ASCIIZ * %MAX_PATH   ' // Name of the value
   LOCAL cValueName  AS DWORD                ' // Size of szValueName
   LOCAL cbData      AS DWORD                ' // Size of szKeyValue
   LOCAL KeyType     AS DWORD                ' // Type of data

   szKey = "CLSID\" & strGuid & "\VersionIndependentProgID"
   RegOpenKeyEx %HKEY_CLASSES_ROOT, szKey , 0, %KEY_READ, hKey
   IF hKey THEN
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      RegEnumValue hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData
      RegCloseKey hKey
      FUNCTION = szKeyValue
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the InprocServer32 from the registry.
' ========================================================================================
FUNCTION TLB_GetInprocServer32 (BYVAL strGuid AS STRING) AS STRING

   LOCAL hKey        AS DWORD                ' // Handle of the opned key
   LOCAL dwIdx       AS DWORD                ' // Index of the value to be retrieved
   LOCAL szKey       AS ASCIIZ * %MAX_PATH   ' // Name of the subkey to open
   LOCAL szKeyValue  AS ASCIIZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL szValueName AS ASCIIZ * %MAX_PATH   ' // Name of the value
   LOCAL cValueName  AS DWORD                ' // Size of szValueName
   LOCAL cbData      AS DWORD                ' // Size of szKeyValue
   LOCAL KeyType     AS DWORD                ' // Type of data

   szKey = "CLSID\" & strGuid & "\InprocServer32"
   RegOpenKeyEx %HKEY_CLASSES_ROOT, szKey , 0, %KEY_READ, hKey
   IF hKey THEN
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      RegEnumValue hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData
      RegCloseKey hKey
      FUNCTION = szKeyValue
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the license key for licensed controls.
' Note: As CoGetClassObject creates an unitialized instance of the server to access the
' IClassFactory2 interface, it can take some time with remote servers such as WSCRIPT.EXE.
' ========================================================================================
FUNCTION TLB_GetRuntimeLicenseKey (BYVAL ProgramID AS STRING) AS STRING

   LOCAL hr                 AS LONG
   LOCAL pIClassFactory2    AS IClassFactory2
   LOCAL IID_IClassFactory2 AS GUID
   LOCAL ClassClsid         AS GUID
   LOCAL tLicInfo           AS LICINFO
   LOCAL bstrLicKey         AS WSTRING

   ' Retrieve the CLSID associated with the PROGID of the component
   ClassClsid = CLSID$(ProgramID)

   ' Get a pointer to the IClassFactory2 interface
   IID_IClassFactory2 = $IID_ICLASSFACTORY2
   hr = CoGetClassObject(ClassClsid, %CLSCTX_ALL, BYVAL %NULL, IID_IClassFactory2, pIClassFactory2)
   IF hr <> %S_OK THEN EXIT FUNCTION

   ' Fill the LICINFO structure
   tLicInfo.cbLicInfo = SIZEOF(tLicInfo)
   hr = pIClassFactory2.GetLicInfo(tLicInfo)

   ' If there is a runtime key available retrieve it
   IF hr = %S_OK THEN
      IF tLicInfo.fRuntimeKeyAvail THEN
         pIClassFactory2.RequestLicKey(0, bstrLicKey)
         FUNCTION = bstrLicKey
      END IF
   END IF

   ' Release the interface
   pIClassFactory2 = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the alias name from the array.
' ========================================================================================
FUNCTION TLB_GetAliasNameFromArray (BYVAL strAlias AS STRING) AS STRING

   LOCAL idx AS LONG
   strAlias += ";"
   IF UBOUND(TLB_AliasArray) > - 1 THEN
      ARRAY SCAN TLB_AliasArray(), FROM 1 TO LEN(strAlias), = strAlias, TO idx
      IF idx THEN
         FUNCTION = PARSE$(TLB_AliasArray(idx - 1), ";", 2)
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the alias name from the array.
' ========================================================================================
FUNCTION TLB_GetAliasNameFromArray2 (BYVAL strAlias AS STRING) AS STRING

   LOCAL idx AS LONG
   strAlias += ";"
   IF UBOUND(TLB_AliasArray2) > - 1 THEN
      ARRAY SCAN TLB_AliasArray2(), FROM 1 TO LEN(strAlias), = strAlias, TO idx
      IF idx THEN
         FUNCTION = PARSE$(TLB_AliasArray2(idx - 1), ";", 2)
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' TLB_GetAliasName helper function.
' Retrieves the alias name, guid and typekind.
' ========================================================================================
FUNCTION TLB_GetAliasName ( _
   BYVAL pITypeInfo    AS ITypeInfo _    ' [in] ITypeInfo interface reference
 , BYVAL hRefType      AS DWORD _        ' [in] Handle to the referenced type description to be returned.
 , BYREF szTypeKind    AS ASCIIZ _       ' [out] The kind of type this information describes in human readable form
 , BYREF typekind      AS LONG _         ' [out] The kind of type this information describes
 , BYREF szGUID        AS ASCIIZ _       ' [out] The GUID of the type information
   ) AS STRING                           ' [reval] The alias name (ansi)

   LOCAL hr            AS LONG           ' HRESULT code
   LOCAL pRefTypeInfo  AS ITypeInfo      ' Points a pointer to a pointer to the referenced type description
   LOCAL pTypeAttr     AS TYPEATTR PTR   ' Attributes of an ITypeInfo
   LOCAL bstrAliasName AS WSTRING        ' The alias name (unicode)

   ' Check for null pointers
   IF VARPTR(szTypeKind) = %NULL THEN EXIT FUNCTION
   IF VARPTR(typekind) = %NULL THEN EXIT FUNCTION
   IF VARPTR(szGuid) = %NULL THEN EXIT FUNCTION

   ' Clear the contents of the passed parameters
   szTypeKind = ""
   typekind = 0
   szGuid = ""

   ' If a type description references other type description, it retrieves the referenced type description
   hr = pITypeInfo.GetRefTypeInfo(hRefType, pRefTypeInfo)
   ' Exit on failure
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pRefTypeInfo) THEN EXIT FUNCTION

   ' Retrieves the name of the rederenced type description
   pRefTypeInfo.GetDocumentation(-1, bstrAliasName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   ' Retrieves a pointer to a TYPEATTR structure that contains the attributes of the type description
   hr = pRefTypeInfo.GetTypeAttr(pTypeAttr)
   ' Exit on failure
   IF hr <> %S_OK OR pTypeAttr = %NULL THEN
      pRefTypeInfo = NOTHING
      EXIT FUNCTION
   END IF

   ' The GUID of the type information
   szGUID = GUIDTXT$(@pTypeAttr.guid)
   IF szGUID = "{00000000-0000-0000-0000-000000000000}" THEN szGUID = ""

   ' The kind of type this information describes
   typekind = @pTypeAttr.typekind
   SELECT CASE typekind
      CASE %TKIND_ENUM      : szTypeKind = "<enum>"
      CASE %TKIND_RECORD    : szTypeKind = "<record>"
      CASE %TKIND_MODULE    : szTypeKind = "<module>"
      CASE %TKIND_INTERFACE : szTypeKind = "<interface>"
      CASE %TKIND_DISPATCH  : szTypeKind = "<dispinterface>"
      CASE %TKIND_COCLASS   : szTypeKind = "<coclass>"
      CASE %TKIND_ALIAS     : szTypeKind = "<alias>"
      CASE %TKIND_UNION     : szTypeKind = "<union>"
   END SELECT

   ' Releases the TYPEATTR structure
   pRefTypeInfo.ReleaseTypeAttr(pTypeAttr)

   ' Releases the ITypeInfo interface
   pRefTypeInfo = NOTHING

   ' Returns the alias name as an ansi string
   FUNCTION = bstrAliasName

END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts an item in the TreeView.
' ========================================================================================
FUNCTION TV_InsertItem (BYVAL hTreeView AS DWORD, BYVAL hParent AS DWORD, szText AS ASCIIZ) AS DWORD

   LOCAL tinsert AS TVINSERTSTRUCTA
   LOCAL titem   AS TVITEMA

   IF hParent THEN
      titem.mask      = %TVIF_CHILDREN OR %TVIF_HANDLE
      titem.hItem     = hParent
      titem.cchildren = 1
      TreeView_SetItemA hTreeView, titem
   END IF

   tinsert.hParent         = hParent
   tinsert.Item.mask       = %TVIF_TEXT
   tinsert.Item.pszText    = VARPTR(szText)
   tinsert.Item.cchTextMax = LEN(szText)

   FUNCTION = TreeView_InsertItemA(hTreeView, tinsert)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the selected treview item name.
' ========================================================================================
FUNCTION TV_GetItemText (BYVAL hTreeView AS DWORD, BYVAL hItem AS DWORD) AS STRING

   LOCAL titem  AS TVITEMA              ' // Attributes of a TreeView item
   LOCAL szText AS ASCIIZ * %MAX_PATH

   IF hItem = 0 THEN EXIT FUNCTION

   titem.hitem = hItem
   titem.mask = %TVIF_TEXT
   titem.psztext = VARPTR(szText)
   titem.cchtextmax = SIZEOF(szText)
   IF ISFALSE TreeView_GetItemA(hTreeView, titem) THEN EXIT FUNCTION
   FUNCTION = szText

END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts an item in the TreeView and expands the child node.
' ========================================================================================
SUB TV_InsertItemEx (BYVAL hTreeView1 AS DWORD, hNode AS DWORD, szTitle AS ASCIIZ, szText AS ASCIIZ)
   LOCAL hParent AS DWORD
   hParent = TV_InsertItem(hTreeView1, hNode, szTitle)
   IF hParent = 0 THEN EXIT SUB
   IF LEN(szText) = 0 THEN EXIT SUB
   TV_InsertItem(hTreeView1, hParent, szText)
   TreeView_Expand(hTreeView1, hParent, %TVE_EXPAND)
END SUB
' ========================================================================================

' ========================================================================================
' Adds the IDispatch methods to the output.
' ========================================================================================
SUB TLB_AddIDispatchMedthods

   TLB_AddLine("   ' =====================================================================================")
   TLB_AddLine("   ' IDispatch Methods")
   TLB_AddLine("   ' =====================================================================================")
   TLB_AddLine("   METHOD GetTypeInfoCount ( _                ' VTable offset = 12")
   TLB_AddLine("     BYREF DWORD _                            ' /* [out] */ unsigned int FAR* pctinfo")
   TLB_AddLine("   ) AS LONG                                  ' HRESULT")
   TLB_AddLine("   ' =====================================================================================")
   TLB_AddLine("   METHOD GetTypeInfo ( _                     ' VTable offset = 16")
   TLB_AddLine("     BYVAL DWORD _                            ' /* [in] */ unsigned int  iTInfo")
   TLB_AddLine("   , BYVAL DWORD _                            ' /* [in] */ LCID lcid")
   TLB_AddLine("   , BYREF IUnknown _                         ' /* [out] */ ITypeInfo FAR* FAR* ppTInfo")
   TLB_AddLine("   ) AS LONG                                  ' HRESULT")
   TLB_AddLine("   ' =====================================================================================")
   TLB_AddLine("   METHOD GetIDsOfNames ( _                   ' VTable offset = 20")
   TLB_AddLine("     BYREF GUID _                             ' /* [in] */ REFIID riid")
   TLB_AddLine("   , BYREF STRING _                           ' /* [in] */ OLECHAR FAR* FAR* rgszNames")
   TLB_AddLine("   , BYVAL DWORD _                            ' /* [in] */ unsigned int cNames")
   TLB_AddLine("   , BYVAL DWORD _                            ' /* [in] */ LCID lcid")
   TLB_AddLine("   , BYREF LONG _                             ' /* [out] */ DISPID FAR* rgDispId")
   TLB_AddLine("   ) AS LONG                                  ' HRESULT")
   TLB_AddLine("   ' =====================================================================================")
   TLB_AddLine("   METHOD Invoke ( _                          ' VTable offset = 24")
   TLB_AddLine("     BYVAL LONG _                             ' /* [in] */ DISPID dispIdMember")
   TLB_AddLine("   , BYREF GUID _                             ' /* [in] */ REFIID riid")
   TLB_AddLine("   , BYVAL DWORD _                            ' /* [in] */ LCID lcid")
   TLB_AddLine("   , BYVAL WORD _                             ' /* [in] */ WORD wFlags")
   TLB_AddLine("   , BYREF DISPPARAMS _                       ' /* [in] */ DISPPARAMS FAR* pDispParams")
   TLB_AddLine("   , BYREF VARIANT _                          ' /* [out] */ VARIANT FAR* pVarResult")
   TLB_AddLine("   , BYVAL DWORD _                            ' /* [out] */ EXCEPINFO FAR*  pExcepInfo")
   TLB_AddLine("   , BYREF DWORD _                            ' /* [out] */ unsigned int FAR*  puArgErr")
   TLB_AddLine("   ) AS LONG                                  ' HRESULT")
   TLB_AddLine("   ' =====================================================================================")
   TLB_AddLine("")

END SUB
' ========================================================================================

' ========================================================================================
' Enumerates the typeinfos and classifies the retrieved information.
' ========================================================================================
FUNCTION TLB_Enumerator (BYVAL hWnd AS DWORD, BYVAL strPath AS STRING) AS LONG

   LOCAL hr                        AS DWORD                ' // HRESULT
   LOCAL pITypeLib                 AS ITypeLib             ' // ITypeLib interface
   LOCAL pITypeInfo                AS ITypeInfo            ' // ITypeInfo interface
   LOCAL pTLibAttr                 AS TLIBATTR PTR         ' // Address of a pointer to the TLIBATTR structure
   LOCAL pTypeAttr                 AS TYPEATTR PTR         ' // Address of a pointer to the TYPEATTR structure
   LOCAL pRefType                  AS DWORD                ' // Address to a referenced type description
   LOCAL pRefTypeInfo              AS ITypeInfo            ' // TypeInfo of the referenced type description
   LOCAL pImplTypeInfo             AS ITypeInfo            ' // Reference to the implemented interface TypeInfo
   LOCAL wszFile                   AS WSTRINGZ * %MAX_PATH ' // Name of the TypeLib (unicode)
   LOCAL bstrName                  AS WSTRING              ' // Member's name (unicode)
   LOCAL bstrDocString             AS WSTRING              ' // Documentation string (unicode)
   LOCAL pdwHelpContext            AS DWORD                ' // Help context
   LOCAL bstrHelpFile              AS WSTRING              ' // Help file (unicode)
   LOCAL TypeInfoCount             AS LONG                 ' // Number of TypeInfos
   LOCAL pTKind                    AS DWORD                ' // TYPEKIND
   LOCAL szName                    AS ASCIIZ * 255         ' // Name
   LOCAL szText                    AS ASCIIZ * 255         ' // General purpose variable
   LOCAL szKeyValue                AS ASCIIZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL i                         AS LONG                 ' // Loop counter
   LOCAL x                         AS LONG                 ' // Loop counter
   LOCAL idx                       AS LONG                 ' // Index
   LOCAL hRoot                     AS DWORD                ' // Root node handle
   LOCAL hDocNode                  AS DWORD                ' // Documentation node handle
   LOCAL hNode                     AS DWORD                ' // Node name
   LOCAL hChild                    AS DWORD                ' // Child node
   LOCAL cImplTypes                AS LONG                 ' // Number of implemented interfaces
   LOCAL lImplTypeFlags            AS LONG                 ' // Implemented interfaces flags
   LOCAL p                         AS LONG                 ' // Position
   LOCAL fBool                     AS LONG                 ' // Boolean variable
   LOCAL strVerIndProgID           AS STRING               ' // Version independent ProgID
   LOCAL lptdesc                   AS TYPEDESC PTR         ' // Pointer to a TYPEDESC structure
   LOCAL vt                        AS WORD                 ' // Variant type
   LOCAL szInterfaceName           AS ASCIIZ * 255         ' // Interface name
   LOCAL szCoClassName             AS ASCIIZ * 255         ' // CoClass name
   LOCAL szAliasName               AS ASCIIZ * 255         ' // Alias name
   LOCAL strImplementedInterface   AS STRING               ' // Implemented interface
   LOCAL hTreeView1                AS DWORD                ' // Handle of the first TreeView
   LOCAL hTreeView2                AS DWORD                ' // Handle of the second TreeView
   LOCAL hStatusbar                AS DWORD                ' // Handle of the status bar
   LOCAL hPageCtrl                 AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hPrefixBox                AS DWORD                ' // Handle of the Prefix edit box
   LOCAL hRichEditBox              AS DWORD                ' // Handle of the RichEdit control
   LOCAL strCaption                AS STRING               ' // Caption
   LOCAL strMessage                AS STRING               ' // Messages
   LOCAL dwStyle                   AS DWORD                ' // Style
   LOCAL hMenu                     AS DWORD                ' // Menu handle
   LOCAL hSubMenu                  AS DWORD                ' // Submenu handle

   DIM szCoClasses()               AS ASCIIZ * 255
   DIM szInterfaces()              AS ASCIIZ * 255
   DIM szOleautomationInterfaces() AS ASCIIZ * 255
   DIM szDualInterfaces()          AS ASCIIZ * 255
   DIM szDispInterfaces()          AS ASCIIZ * 255
   DIM szDispatchableInterfaces()  AS ASCIIZ * 255
'   DIM szHiddenInterfaces()        AS ASCIIZ * 255
'   DIM szRestrictedInterfaces()    AS ASCIIZ * 255
   DIM szEnums()                   AS ASCIIZ * 255
   DIM szModules()                 AS ASCIIZ * 255
   DIM szRecords()                 AS ASCIIZ * 255
   DIM szUnions()                  AS ASCIIZ * 255
   DIM szTypeDefs()                AS ASCIIZ * 255
   DIM szAlias()                   AS ASCIIZ * 255

   ' ===========================================================================
   ' Closes the COM library on the current thread, unloads all DLLs loaded by
   ' the thread, frees any other resources that the thread maintains, and forces
   ' all RPC connections on the thread to close.
   ' Note: This is necessary after requesting the license key because
   ' CoGetClassObject creates an uninitialized instance of the server and, if it
   ' is not unloaded, the next call to CoGetClassObject returns incorrect pointers
   ' and then a GPF in the call to IClassFactory2.RequestLicKey.
   ' ===========================================================================
   CoUninitialize

   ' ===========================================================================
   ' Initializes the COM library for use by the calling thread, sets the thread's
   ' concurrency model, and creates a new apartment for the thread if one is required.
   ' ===========================================================================
   CoInitializeEx BYVAL 0, 0
   ' ===========================================================================

   ' ===========================================================================
   ' Gets the handles of the TreeViews
   ' ===========================================================================
   ' Retrieves the handle of the page of the tab control that contains the TreeViews
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   IF hPageCtrl = %NULL THEN EXIT FUNCTION
   ' Retrieves the handle of the TreeViews
   hTreeView1 = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW1)
   IF hTreeView1 = %NULL THEN EXIT FUNCTION
   hTreeView2 = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF hTreeView2 = %NULL THEN EXIT FUNCTION
   ' Empties the contents of the rich edit box
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_CODE)
   IF hPageCtrl = %NULL THEN EXIT FUNCTION
   hRichEditBox = GetDlgItem(hPageCtrl, %IDC_DIALOG1_RICHEDIT_VIEWCODE)
   IF hRichEditBox = %NULL THEN EXIT FUNCTION
   szText = ""
   SendMessage hRichEditBox, %WM_SETTEXT, 0, VARPTR(szText)

   ' ===========================================================================
   ' Clears the flags
   ' ===========================================================================
   TLB_CanCreate         = %FALSE
   TLB_HasControl        = %FALSE
   TLB_HasDualInterfaces = %FALSE
   TLB_HasDispatchOnly   = %FALSE

   ' ===========================================================================
   ' Erases the globals
   ' ===========================================================================
   TLB_PrefixStr = ""                    ' // Prefix string
   TLB_strLicKey = ""                    ' // License key
   TYPE SET TLB_LibDoc = ""              ' // Library documentation record
   ERASE TLB_GuidsArray                  ' // Guids array
   ERASE TLB_IIDsArray                   ' // IIDs array
   ERASE TLB_ProgIdsArray                ' // ProgIDs array
   ERASE TLB_EventsArray                 ' // Events array
   ERASE TLB_InterfacesArray             ' // Interfaces array
   ERASE TLB_DefaultInterfacesArray      ' // Default interfaces array
   ERASE TLB_AliasArray                  ' // Alias array
   ERASE TLB_AliasArray2                 ' // Alias array

   ' ===========================================================================
   ' Disables redraw to minimize flicker
   ' ===========================================================================
   SendMessage hTreeView1, %WM_SETREDRAW, %FALSE, 0
   SendMessage hTreeView2, %WM_SETREDRAW, %FALSE, 0

   ' ===========================================================================
   ' Deletes the items
   ' ===========================================================================
   IF TreeView_GetCount(hTreeView1) THEN TreeView_DeleteAllItems(hTreeView1)
   IF TreeView_GetCount(hTreeView2) THEN TreeView_DeleteAllItems(hTreeView2)

   ' ===========================================================================
   ' Loads the TypeLib
   ' ===========================================================================

   wszFile = strPath
   hr = LoadTypeLibEx(wszFile, %REGKIND_NONE, pITypeLib)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeLib) THEN
      dwStyle = %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL
      strCaption = FUNCNAME$ & " - LoadTypeLibEx"
      strMessage = "Error &H" & HEX$(hr, 8) & " loading " & strPath
      TLB_MsgBox hWnd, strMessage, dwStyle, strCaption
      EXIT FUNCTION
   END IF

   ' ===========================================================================
   ' Gets the documentation and stores it in the structure
   ' ===========================================================================
   hr = pITypeLib.GetDocumentation(-1, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
   IF hr <> %S_OK THEN
      dwStyle = %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL
      strCaption = FUNCNAME$ & " - GetDocumentation"
      strMessage = "Error &H" & HEX$(hr, 8) & " retrieving the documentation"
      TLB_MsgBox hWnd, strMessage, dwStyle, strCaption
      GOTO Terminate
   END IF
   TLB_LibName = bstrName
   TLB_LibDoc.szName = bstrName
   TLB_LibDoc.szPath = strPath
   TLB_LibDoc.szHelpString = bstrDocString
   TLB_LibDoc.HelpContext = pdwHelpContext
   TLB_LibDoc.szHelpFile = bstrHelpFile

   ' ===========================================================================
   ' Gets the attributes of the library and stores them in the structure
   ' ===========================================================================
   hr = pITypeLib.GetLibAttr(pTLibAttr)
   IF hr = %S_OK AND pTLibAttr <> %NULL THEN
      TLB_LibDoc.szGuid = GUIDTXT$(@pTLibAttr.guid)
      TLB_LibDoc.lcid = @pTLibAttr.lcid
      TLB_LibDoc.syskind = @pTLibAttr.syskind
      TLB_LibDoc.MajorVersion = @pTLibAttr.wMajorVerNum
      TLB_LibDoc.MinorVersion = @pTLibAttr.wMinorVerNum
      TLB_LibDoc.iAttr = @pTLibAttr.wLibFlags
      pITypeLib.ReleaseTLibAttr(pTLibAttr)
   END IF

   ' ===========================================================================
   ' Root node
   ' ===========================================================================
   hRoot = TV_InsertItem(hTreeView1, 0, TLB_LibDoc.szName)

   ' ===========================================================================
   ' Documentation node
   ' ===========================================================================
   hDocNode = TV_InsertItem(hTreeView1, hRoot, "Documentation")
   TV_InsertItem hTreeView1, hDocNode, "GUID = " & TLB_LibDoc.szGuid
   TV_InsertItem hTreeView1, hDocNode, "LCID = " & FORMAT$(TLB_LibDoc.lcid)
   TV_InsertItem hTreeView1, hDocNode, "Major version = " & FORMAT$(TLB_LibDoc.MajorVersion)
   TV_InsertItem hTreeView1, hDocNode, "Minor version = " & FORMAT$(TLB_LibDoc.MinorVersion)
   IF LEN(TLB_LibDoc.szHelpString) THEN TV_InsertItem hTreeView1, hDocNode, "Help string = " & TLB_LibDoc.szHelpString
   TV_InsertItem hTreeView1, hDocNode, "Path = " & strPath
   IF TLB_LibDoc.HelpContext THEN TV_InsertItem hTreeView1, hDocNode, "Help context = " & FORMAT$(TLB_LibDoc.HelpContext)
   IF LEN(TLB_LibDoc.szHelpFile) THEN TV_InsertItem hTreeView1, hDocNode, "Help file = " & TLB_LibDoc.szHelpFile
   TV_InsertItem hTreeView1, hDocNode, "Attributes = " & FORMAT$(TLB_LibDoc.iAttr) & " [&H" & HEX$(TLB_LibDoc.iAttr, 8) & "] " & TLB_LibFlagsToStr(TLB_LibDoc.iAttr)
   SELECT CASE AS LONG TLB_LibDoc.syskind
      CASE %SYS_WIN16 : TV_InsertItem hTreeView1, hDocNode, "Target OS = " & FORMAT$(TLB_LibDoc.syskind) & " (Win16)"
      CASE %SYS_WIN32 : TV_InsertItem hTreeView1, hDocNode, "Target OS = " & FORMAT$(TLB_LibDoc.syskind) & " (Win32)"
      CASE %SYS_MAC : TV_InsertItem hTreeView1, hDocNode, "Target OS = " & FORMAT$(TLB_LibDoc.syskind) & " (MAC)"
   END SELECT
   TreeView_Expand hTreeView1, hDocNode, %TVE_EXPAND

   ' ===========================================================================
   ' Expands the root node
   ' ===========================================================================
   TreeView_Expand(hTreeView1, hRoot, %TVE_EXPAND)

   ' ===========================================================================
   ' Retrieves the number of TypeInfos
   ' ===========================================================================
   TypeInfoCount = pITypeLib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN
      dwStyle = %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL
      strCaption = FUNCNAME$ & " - GetTypeInfoCount"
      strMessage = "This TypeLib doesn't have Type Infos"
      TLB_MsgBox hWnd, strMessage, dwStyle, strCaption
      GOTO Terminate
   END IF

   ' ===========================================================================
   ' Parses the TypeLib
   ' ===========================================================================
   FOR i = 0 TO TypeInfoCount - 1

      ' --- Allow for a breath and check the abort flag ----------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR

      ' ------------------------------------------------------------------------
      ' Retrieves the TypeKind
      ' ------------------------------------------------------------------------
      hr = pITypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN
         dwStyle = %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL
         strCaption = FUNCNAME$ & " - GetTypeInfoType"
         strMessage = "Error &H" & HEX$(hr, 8) & " retrieving the InfoType"
         TLB_MsgBox hWnd, strMessage, dwStyle, strCaption
         EXIT FOR
      END IF

      ' ------------------------------------------------------------------------
      ' Retrieves the TypeInfo interface
      ' ------------------------------------------------------------------------
      hr = pITypeLib.GetTypeInfo(i, pITypeInfo)
      IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeInfo) THEN
         dwStyle = %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL
         strCaption = FUNCNAME$ & " - GetTypeInfo"
         strMessage = "Error &H" & HEX$(hr, 8) & " retrieving the TypeInfo interface"
         TLB_MsgBox hWnd, strMessage, dwStyle, strCaption
         EXIT FOR
      END IF

      ' ------------------------------------------------------------------------
      ' Gets the address of a pointer to the TYPEATTR structure
      ' ------------------------------------------------------------------------
      hr = pITypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN
         dwStyle = %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL
         strCaption = FUNCNAME$ & " - GetTypeAttr"
         strMessage = "Error &H" & HEX$(hr, 8) & " retrieving the address of the TypeAttr structure"
         TLB_MsgBox hWnd, strMessage, dwStyle, strCaption
         EXIT FOR
      END IF

      ' ------------------------------------------------------------------------
      ' Retrieve information
      ' ------------------------------------------------------------------------
      SELECT CASE pTKind

         CASE %TKIND_COCLASS

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               REDIM PRESERVE szCoClasses(UBOUND(szCoClasses) + 1)
               szCoClassName = bstrName
               szCoClasses(UBOUND(szCoClasses)) = szCoclassName
               REDIM PRESERVE TLB_InterfacesArray(UBOUND(TLB_InterfacesArray) + 1)
               TLB_InterfacesArray(UBOUND(TLB_InterfacesArray)) = szCoclassName
               ' ---------------------------------------------------------------------
               ' ClsIDs
               ' ---------------------------------------------------------------------
               REDIM PRESERVE TLB_GuidsArray(UBOUND(TLB_GuidsArray) + 1)
               TLB_GuidsArray(UBOUND(TLB_GuidsArray)).szName = szCoClassName
               TLB_GuidsArray(UBOUND(TLB_GuidsArray)).guid = @pTypeAttr.guid
               TLB_GuidsArray(UBOUND(TLB_GuidsArray)).szPBSyntax = "$CLSID_" & szCoClassName & " = GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")"
               ' ---------------------------------------------------------------------
               ' Gets the ProgID
               ' ---------------------------------------------------------------------
               ' Some external programs, such McAffee Antivirus, modify the typelibs of
               ' components such Windows Script Host to redirect it to its own server.
               ' This originates duplicate ProgIDs, so we need to search if the ProgID
               ' is already in the array to avoid duplicates.
               idx = 0
               szKeyValue = TLB_GetProgID(GUIDTXT$(@pTypeAttr.guid))
               IF LEN(szKeyValue) THEN
                  ARRAY SCAN TLB_ProgIDsArray(), FROM 1 TO LEN(szKeyValue), = szKeyValue, TO idx
                  IF ISFALSE idx THEN
                     REDIM PRESERVE TLB_ProgIDsArray(UBOUND(TLB_ProgIDsArray) + 1)
                     TLB_ProgIDsArray(UBOUND(TLB_ProgIDsArray)) = szKeyValue
                     TLB_GuidsArray(UBOUND(TLB_GuidsArray)).szProgID = szKeyValue
                  END IF
               END IF
               ' ---------------------------------------------------------------------
               ' Store the flags
               ' ---------------------------------------------------------------------
               IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FCANCREATE) = %TYPEFLAG_FCANCREATE AND _
                  (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FCONTROL) <> %TYPEFLAG_FCONTROL THEN TLB_CanCreate = %TRUE
               IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FCONTROL) = %TYPEFLAG_FCONTROL THEN TLB_HasControl = %TRUE
               ' ---------------------------------------------------------------------
               ' Gets the default events interfaces for each CoClass
               ' ---------------------------------------------------------------------
               cImplTypes = @pTypeAttr.cImplTypes
               FOR x = 0 TO cImplTypes - 1
                  lImplTypeFlags = 0
                  hr = pITypeInfo.GetImplTypeFlags(x, lImplTypeFlags)
                  IF hr <> %S_OK THEN EXIT FOR
                  pRefType = 0
                  hr = pITypeInfo.GetRefTypeOfImplType(x, pRefType)
                  IF hr <> %S_OK THEN EXIT FOR
                  hr = pITypeInfo.GetRefTypeInfo(pRefType, pImplTypeInfo)
                  IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FOR
                  hr = pImplTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr <> %S_OK THEN EXIT FOR
                  pImplTypeInfo = NOTHING
                  szInterfaceName = bstrName
                  IF lImplTypeFlags = 1 THEN        ' // Default interface
                     IF LEN(szInterfaceName) THEN
                        REDIM PRESERVE TLB_DefaultInterfacesArray(UBOUND(TLB_DefaultInterfacesArray) + 1)
                        TLB_DefaultInterfacesArray(UBOUND(TLB_DefaultInterfacesArray)) = szInterfaceName & ";" & szCoClassName
                     END IF
                  ELSEIF lImplTypeFlags = 2 OR lImplTypeFlags = 3 THEN    ' // Events interface / Default events interface
                     idx = 0
                     ARRAY SCAN TLB_EventsArray(), = szInterfaceName, TO idx
                     IF ISFALSE idx THEN
                        REDIM PRESERVE TLB_EventsArray(UBOUND(TLB_EventsArray) + 1)
                        TLB_EventsArray(UBOUND(TLB_EventsArray)) = szInterfaceName
                     END IF
                  END IF
               NEXT
               pImplTypeInfo = NOTHING
               ' ---------------------------------------------------------------------
            END IF

         CASE %TKIND_INTERFACE

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               szName = bstrName
               REDIM PRESERVE TLB_InterfacesArray(UBOUND(TLB_InterfacesArray) + 1)
               TLB_InterfacesArray(UBOUND(TLB_InterfacesArray)) = szName
               ' ---------------------------------------------------------------------
               ' IIDS
               ' ---------------------------------------------------------------------
               REDIM PRESERVE TLB_IIDsArray(UBOUND(TLB_IIDsArray) + 1)
               TLB_IIDsArray(UBOUND(TLB_IIDsArray)).szName = szName
               TLB_IIDsArray(UBOUND(TLB_IIDsArray)).guid = @pTypeAttr.guid
               TLB_IIDsArray(UBOUND(TLB_IIDsArray)).szPBSyntax = "$IID_" & szName & " = GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")"
               ' ---------------------------------------------------------------------
               ' Interfaces
               ' ---------------------------------------------------------------------
'               IF @pTypeAttr.wTypeFlags = %TYPEFLAG_FHIDDEN THEN
'                  REDIM PRESERVE szHiddenInterfaces(UBOUND(szHiddenInterfaces) + 1)
'                  szHiddenInterfaces(UBOUND(szHiddenInterfaces)) = szName
'               ELSEIF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FRESTRICTED) = %TYPEFLAG_FRESTRICTED THEN
'                  REDIM PRESERVE szRestrictedInterfaces(UBOUND(szRestrictedInterfaces) + 1)
'                  szRestrictedInterfaces(UBOUND(szRestrictedInterfaces)) = szName
'               ELSE
                  strImplementedInterface = UCASE$(TLB_GetImplementedInterface(pITypeInfo))
                  IF strImplementedInterface <> "" THEN
                     IF strImplementedInterface <> "IUNKNOWN" AND strImplementedInterface <> "IDISPATCH" THEN
                        strImplementedInterface = TLB_GetBaseClass(hWnd, pITypeLib, szName)
                     END IF
                  END IF
                  IF strImplementedInterface = "IUNKNOWN" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FOLEAUTOMATION) = %TYPEFLAG_FOLEAUTOMATION THEN
                     REDIM PRESERVE szOleautomationInterfaces(UBOUND(szOleautomationInterfaces) + 1)
                     szOleautomationInterfaces(UBOUND(szOleautomationInterfaces)) = szName
                  ELSEIF strImplementedInterface = "IDISPATCH" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) <> %TYPEFLAG_FDUAL THEN
                     REDIM PRESERVE szDispatchableInterfaces(UBOUND(szDispatchableInterfaces) + 1)
                     szDispatchableInterfaces(UBOUND(szDispatchableInterfaces)) = szName
                  ELSE
                     REDIM PRESERVE szInterfaces(UBOUND(szInterfaces) + 1)
                     szInterfaces(UBOUND(szInterfaces)) = szName
                  END IF
'               END IF
               ' ---------------------------------------------------------------------
            END IF

         CASE %TKIND_DISPATCH

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               szName = bstrName
               REDIM PRESERVE TLB_InterfacesArray(UBOUND(TLB_InterfacesArray) + 1)
               TLB_InterfacesArray(UBOUND(TLB_InterfacesArray)) = szName
               ' ---------------------------------------------------------------------
               ' IIDS
               ' ---------------------------------------------------------------------
               REDIM PRESERVE TLB_IIDsArray(UBOUND(TLB_IIDsArray) + 1)
               TLB_IIDsArray(UBOUND(TLB_IIDsArray)).szName = szName
               TLB_IIDsArray(UBOUND(TLB_IIDsArray)).guid = @pTypeAttr.guid
               TLB_IIDsArray(UBOUND(TLB_IIDsArray)).szPBSyntax = "$IID_" & szName & " = GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")"
               ' ---------------------------------------------------------------------
               ' Interfaces
               ' ---------------------------------------------------------------------
'               IF @pTypeAttr.wTypeFlags = %TYPEFLAG_FHIDDEN THEN
'                  REDIM PRESERVE szHiddenInterfaces(UBOUND(szHiddenInterfaces) + 1)
'                  szHiddenInterfaces(UBOUND(szHiddenInterfaces)) = szName
'               ELSEIF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FRESTRICTED) = %TYPEFLAG_FRESTRICTED THEN
'                  REDIM PRESERVE szRestrictedInterfaces(UBOUND(szRestrictedInterfaces) + 1)
'                  szRestrictedInterfaces(UBOUND(szRestrictedInterfaces)) = szName
               IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                  TLB_HasDualInterfaces = %TRUE
                  REDIM PRESERVE szDualInterfaces(UBOUND(szDualInterfaces) + 1)
                  szDualInterfaces(UBOUND(szDualInterfaces)) = szName
               ELSE
                  REDIM PRESERVE szDispInterfaces(UBOUND(szDispInterfaces) + 1)
                  szDispInterfaces(UBOUND(szDispInterfaces)) = szName
               END IF
               ' ---------------------------------------------------------------------
            END IF

         CASE %TKIND_ENUM

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               REDIM PRESERVE szEnums(UBOUND(szEnums) + 1)
               szEnums(UBOUND(szEnums)) = bstrName
            END IF

         CASE %TKIND_MODULE

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               REDIM PRESERVE szModules(UBOUND(szModules) + 1)
               szModules(UBOUND(szModules)) = bstrName
            END IF

         CASE %TKIND_RECORD

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               REDIM PRESERVE szRecords(UBOUND(szRecords) + 1)
               szRecords(UBOUND(szRecords)) = bstrName
            END IF

         CASE %TKIND_UNION

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN
               REDIM PRESERVE szUnions(UBOUND(szUnions) + 1)
               szUnions(UBOUND(szUnions)) = bstrName
            END IF

         CASE %TKIND_ALIAS

            hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            szName = bstrName
            IF hr = %S_OK THEN
               IF @pTypeAttr.tdescAlias.vt = %VT_USERDEFINED THEN
                  ' If it is a user defined type, retrieve his name
                  hr = pITypeInfo.GetRefTypeInfo(@pTypeAttr.tdescAlias.hreftype, pRefTypeInfo)
                  IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                     hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                     IF hr = %S_OK THEN
                        szAliasName = bstrName
                        REDIM PRESERVE szAlias(UBOUND(szAlias) + 1)
                        szAlias(UBOUND(szAlias)) = szName & " = " & szAliasName
                        REDIM PRESERVE TLB_AliasArray(UBOUND(TLB_AliasArray) + 1)
                        TLB_AliasArray(UBOUND(TLB_AliasArray)) = szName & ";" & szAliasName
                        REDIM PRESERVE TLB_AliasArray2(UBOUND(TLB_AliasArray2) + 1)
                        TLB_AliasArray2(UBOUND(TLB_AliasArray2)) = szAliasName & ";" & szName
                     END IF
                     pRefTypeInfo = NOTHING
                  END IF
               ELSEIF @pTypeAttr.tdescAlias.vt = %VT_PTR THEN
                  ' Pointer to a TYPEDESC structure
                  lptdesc = @pTypeAttr.tdescAlias.lptdesc
                  DO
                     ' VarType
                     vt = @lptdesc.vt
                     SELECT CASE vt
                        ' If it is a pointer, do it again
                        CASE %VT_PTR
                           lptdesc = @lptdesc.lptdesc
                        CASE %VT_USERDEFINED
                           ' Retrieve the name of the userdefined type
                           hr = pITypeInfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
                           IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                              hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                              IF hr = %S_OK THEN
                                 szAliasName = bstrName
                                 REDIM PRESERVE szAlias(UBOUND(szAlias) + 1)
                                 szAlias(UBOUND(szAlias)) = szName & " = " & szAliasName
                                 REDIM PRESERVE TLB_AliasArray(UBOUND(TLB_AliasArray) + 1)
                                 TLB_AliasArray(UBOUND(TLB_AliasArray)) = szName & ";" & szAliasName
                                 REDIM PRESERVE TLB_AliasArray2(UBOUND(TLB_AliasArray2) + 1)
                                 TLB_AliasArray2(UBOUND(TLB_AliasArray2)) = szAliasName & ";" & szName
                              END IF
                              pRefTypeInfo = NOTHING
                           END IF
                           EXIT DO
                        CASE ELSE
                           ' Show the equivalent type
                           REDIM PRESERVE szTypeDefs(UBOUND(szTypeDefs) + 1)
                           szTypeDefs(UBOUND(szTypeDefs)) = szName & " = " & VarTypeToConstant(@pTypeAttr.tdescAlias.vt) & " <" & VarTypeToKeyword(@pTypeAttr.tdescAlias.vt) & ">"
                           EXIT DO
                     END SELECT
                  LOOP
               ELSE
                  ' Show the equivalent type
                  szName = szName & " = " & VarTypeToConstant(@pTypeAttr.tdescAlias.vt) & " <" & VarTypeToKeyword(@pTypeAttr.tdescAlias.vt) & ">"
                  REDIM PRESERVE szTypeDefs(UBOUND(szTypeDefs) + 1)
                  szTypeDefs(UBOUND(szTypeDefs)) = szName
               END IF
            END IF

      END SELECT
      ' ------------------------------------------------------------------------

      ' ------------------------------------------------------------------------
      ' Releases the TYPEATTR structure
      ' ------------------------------------------------------------------------
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0

      ' ------------------------------------------------------------------------
      ' Releases the TypeInfo interface
      ' ------------------------------------------------------------------------
      pITypeInfo = NOTHING

   NEXT
   ' ========================================================================================

   ' ---------------------------------------------------------------------------
   ' Retrieves the license key
   ' ---------------------------------------------------------------------------
   IF m_RetrieveLicenseKey THEN
      IF UBOUND(TLB_ProgIDsArray) > -1 THEN
         TLB_StrLicKey = TLB_GetRuntimeLicenseKey(TLB_ProgIDsArray(LBOUND(TLB_ProgIDsArray)))
         IF LEN(TLB_strLicKey) THEN TV_InsertItem(hTreeView1, hDocNode, "License key = " & TLB_strLicKey)
      END IF
   END IF

   ' ---------------------------------------------------------------------------
   ' Makes a prefix
   ' ---------------------------------------------------------------------------
   TLB_PrefixStr = ""
   IF UBOUND(TLB_ProgIDsArray) > -1 THEN
      TLB_PrefixStr = TLB_ProgIDsArray(LBOUND(TLB_ProgIDsArray))
   END IF
   IF LEN(TLB_PrefixStr) = 0 THEN TLB_PrefixStr = TLB_LibName
   IF LEN(TLB_PrefixStr) THEN
      p = INSTR (TLB_PrefixStr, ".")
      IF p THEN TLB_PrefixStr = LEFT$(TLB_PrefixStr, p - 1)
   END IF
   TLB_PrefixStr = REMOVE$(TLB_PrefixStr, $DQ)
   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
   IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
   IF hPrefixBox THEN SetWindowText hPrefixBox, BYCOPY TLB_PrefixStr
   TV_InsertItem hTreeView1, hDocNode, "Prefix = " & TLB_PrefixStr

   ' ---------------------------------------------------------------------------
   ' Sort the arrays
   ' ---------------------------------------------------------------------------
   IF UBOUND(szCoClasses) > - 1 THEN ARRAY SORT szCoClasses(), COLLATE UCASE
   IF UBOUND(TLB_ProgIDsArray) > - 1 THEN ARRAY SORT TLB_ProgIDsArray(), COLLATE UCASE
   IF UBOUND(TLB_EventsArray) > - 1 THEN ARRAY SORT TLB_EventsArray(), COLLATE UCASE
   IF UBOUND(TLB_GuidsArray) > - 1 THEN ARRAY SORT TLB_GuidsArray(), COLLATE UCASE
   IF UBOUND(TLB_IIDsArray) > - 1 THEN ARRAY SORT TLB_IIDsArray(), COLLATE UCASE
   IF UBOUND(szInterfaces) > - 1 THEN ARRAY SORT szInterfaces(), COLLATE UCASE
   IF UBOUND(szOleautomationInterfaces) > - 1 THEN ARRAY SORT szOleautomationInterfaces(), COLLATE UCASE
   IF UBOUND(szDualInterfaces) > - 1 THEN ARRAY SORT szDualInterfaces(), COLLATE UCASE
   IF UBOUND(szDispInterfaces) > - 1 THEN ARRAY SORT szDispInterfaces(), COLLATE UCASE
   IF UBOUND(szDispatchableInterfaces) > - 1 THEN ARRAY SORT szDispatchableInterfaces(), COLLATE UCASE
'   IF UBOUND(szHiddenInterfaces) > - 1 THEN ARRAY SORT szHiddenInterfaces(), COLLATE UCASE
'   IF UBOUND(szRestrictedInterfaces) > - 1 THEN ARRAY SORT szRestrictedInterfaces(), COLLATE UCASE
   IF UBOUND(szEnums) > - 1 THEN ARRAY SORT szEnums(), COLLATE UCASE
   IF UBOUND(szModules) > - 1 THEN ARRAY SORT szModules(), COLLATE UCASE
   IF UBOUND(szRecords) > - 1 THEN ARRAY SORT szRecords(), COLLATE UCASE
   IF UBOUND(szUnions) > - 1 THEN ARRAY SORT szUnions(), COLLATE UCASE
   IF UBOUND(szTypeDefs) > - 1 THEN ARRAY SORT szTypeDefs(), COLLATE UCASE
   IF UBOUND(szAlias) > - 1 THEN ARRAY SORT szAlias(), COLLATE UCASE

   ' ---------------------------------------------------------------------------
   ' Shows the ProgIDs
   ' ---------------------------------------------------------------------------
   IF UBOUND(TLB_ProgIDsArray) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "ProgIDs (Program identifiers)")
      FOR i = LBOUND(TLB_ProgIDsArray) TO UBOUND(TLB_ProgIDsArray)
         hChild = TV_InsertItem(hTreeView1, hNode, TLB_ProgIDsArray(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the version independent ProgIDs
   ' Note: Search if it already exists because there are components like
   ' MSXML that allow side-by-side installation of several versions that have
   ' different ProgIDs but, of course, the same independent version ProgID.
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(TLB_GuidsArray) > - 1 THEN
      FOR i = LBOUND(TLB_GuidsArray) TO UBOUND(TLB_GuidsArray)
         strVerIndProgID = TLB_GetVersionIndependentProgID(GUIDTXT$(TLB_GuidsArray(i).guid))
         IF LEN(strVerIndProgID) THEN
            ARRAY SCAN TLB_GuidsArray(), FROM 1 TO LEN(strVerIndProgID), = strVerIndProgID, TO idx
            IF ISFALSE idx THEN
               TLB_GuidsArray(i).szVIProgID = strVerIndProgID
               IF ISFALSE fBool THEN
                  hNode = TV_InsertItem(hTreeView1, hRoot, "Version independent ProgIDs")
                  fBool = %TRUE
               END IF
               hChild = TV_InsertItem(hTreeView1, hNode, BYCOPY strVerIndProgID)
               TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
            END IF
         END IF
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the ClsIDs
   ' ---------------------------------------------------------------------------
   IF UBOUND(TLB_GuidsArray) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "ClsIDs (Class identifiers)")
      FOR i = LBOUND(TLB_GuidsArray) TO UBOUND(TLB_GuidsArray)
         hChild = TV_InsertItem(hTreeView1, hNode, TLB_GuidsArray(i).szPBSyntax)
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the IIDs
   ' ---------------------------------------------------------------------------
   IF UBOUND(TLB_IIDsArray) > - 1 THEN
      ARRAY SORT TLB_IIDsArray(), COLLATE UCASE
      hNode = TV_InsertItem(hTreeView1, hRoot, "IIDs (Interface identifiers)")
      FOR i = LBOUND(TLB_IIDsArray) TO UBOUND(TLB_IIDsArray)
         hChild = TV_InsertItem(hTreeView1, hNode, TLB_IIDsArray(i).szPBSyntax)
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the CoClasses
   ' ---------------------------------------------------------------------------
   IF UBOUND(szCoClasses) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "CoClasses")
      FOR i = LBOUND(szCoClasses) TO UBOUND(szCoClasses)
         hChild = TV_InsertItem(hTreeView1, hNode, szCoClasses(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the enums
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szEnums) > - 1 THEN
      FOR i = LBOUND(szEnums) TO UBOUND(szEnums)
         IF ISFALSE fBool THEN
            hNode = TV_InsertItem(hTreeView1, hRoot, "Enumerations")
            fBool = %TRUE
         END IF
         hChild = TV_InsertItem(hTreeView1, hNode, szEnums(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the modules
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szModules) > - 1 THEN
      FOR i = LBOUND(szModules) TO UBOUND(szModules)
         IF ISFALSE fBool THEN
            hNode = TV_InsertItem(hTreeView1, hRoot, "Modules")
            fBool = %TRUE
         END IF
         hChild = TV_InsertItem(hTreeView1, hNode, szModules(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the records
   ' ---------------------------------------------------------------------------
   IF UBOUND(szRecords) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "Structures")
      FOR i = LBOUND(szRecords) TO UBOUND(szRecords)
         hChild = TV_InsertItem(hTreeView1, hNode, szRecords(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the unions
   ' ---------------------------------------------------------------------------
   IF UBOUND(szUnions) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "Unions")
      FOR i = LBOUND(szUnions) TO UBOUND(szUnions)
         hChild = TV_InsertItem(hTreeView1, hNode, szUnions(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the typedefs
   ' ---------------------------------------------------------------------------
   IF UBOUND(szTypedefs) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "Typedefs")
      FOR i = LBOUND(szTypedefs) TO UBOUND(szTypedefs)
         hChild = TV_InsertItem(hTreeView1, hNode, szTypedefs(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the alias
   ' ---------------------------------------------------------------------------
   IF UBOUND(szAlias) > - 1 THEN
      hNode = TV_InsertItem(hTreeView1, hRoot, "Alias")
      FOR i = LBOUND(szAlias) TO UBOUND(szAlias)
         hChild = TV_InsertItem(hTreeView1, hNode, szAlias(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the interfaces
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szInterfaces) > - 1 THEN
      FOR i = LBOUND(szInterfaces) TO UBOUND(szInterfaces)
         ' If it is not an events interface...
         idx = 0
         ARRAY SCAN TLB_EventsArray(), = szInterfaces(i), TO idx
         IF ISFALSE idx THEN
            IF ISFALSE fBool THEN
               hNode = TV_InsertItem(hTreeView1, hRoot, "Interfaces")
               fBool = %TRUE
            END IF
            hChild = TV_InsertItem(hTreeView1, hNode, szInterfaces(i))
            TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
         END IF
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the IAutomation interfaces
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szOleautomationInterfaces) > - 1 THEN
      FOR i = LBOUND(szOleautomationInterfaces) TO UBOUND(szOleautomationInterfaces)
         ' If it is not an events interface...
         idx = 0
         ARRAY SCAN TLB_EventsArray(), = szOleautomationInterfaces(i), TO idx
         IF ISFALSE idx THEN
            IF ISFALSE fBool THEN
               hNode = TV_InsertItem(hTreeView1, hRoot, "Oleautomation interfaces")
               fBool = %TRUE
            END IF
            hChild = TV_InsertItem(hTreeView1, hNode, szOleautomationInterfaces(i))
            TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
         END IF
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the dual interfaces
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szDualInterfaces) > - 1 THEN
      FOR i = LBOUND(szDualInterfaces) TO UBOUND(szDualInterfaces)
         ' If it is not an events interface...
         idx = 0
         ARRAY SCAN TLB_EventsArray(), = szDualInterfaces(i), TO idx
         IF ISFALSE idx THEN
            IF ISFALSE fBool THEN
               hNode = TV_InsertItem(hTreeView1, hRoot, "Dual interfaces")
               fBool = %TRUE
            END IF
            hChild = TV_InsertItem(hTreeView1, hNode, szDualInterfaces(i))
            TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
         END IF
      NEXT
   END IF

   ' ------------------------------------------------------------------------------------
   ' Shows the dispatch interfaces
   ' ------------------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szDispInterfaces) > - 1 THEN
      FOR i = LBOUND(szDispInterfaces) TO UBOUND(szDispInterfaces)
         ' If it is not an events interface...
         idx = 0
         ARRAY SCAN TLB_EventsArray(), = szDispInterfaces(i), TO idx
         IF ISFALSE idx THEN
            ' Set the flag and show the interface
            TLB_HasDispatchOnly = %TRUE
            IF ISFALSE fBool THEN
               hNode = TV_InsertItem(hTreeView1, hRoot, "Dispatch interfaces")
               fBool = %TRUE
            END IF
            hChild = TV_InsertItem(hTreeView1, hNode, szDispInterfaces(i))
            TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
         END IF
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the dispatchable interfaces
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(szDispatchableInterfaces) > - 1 THEN
      FOR i = LBOUND(szDispatchableInterfaces) TO UBOUND(szDispatchableInterfaces)
         ' If it is not an events interface...
         idx = 0
         ARRAY SCAN TLB_EventsArray(), = szDispatchableInterfaces(i), TO idx
         IF ISFALSE idx THEN
            IF ISFALSE fBool THEN
               hNode = TV_InsertItem(hTreeView1, hRoot, "Dispatchable interfaces")
               fBool = %TRUE
            END IF
            hChild = TV_InsertItem(hTreeView1, hNode, szDispatchableInterfaces(i))
            TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
         END IF
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the hidden interfaces
   ' ---------------------------------------------------------------------------
'   fBool = %FALSE
'   IF UBOUND(szHiddenInterfaces) > - 1 THEN
'      FOR i = LBOUND(szHiddenInterfaces) TO UBOUND(szHiddenInterfaces)
'         ' If it is not an events interface...
'         idx = 0
'         ARRAY SCAN TLB_EventsArray(), = szHiddenInterfaces(i), TO idx
'         IF ISFALSE idx THEN
'            IF ISFALSE fBool THEN
'               hNode = TV_InsertItem(hTreeView1, hRoot, "Hidden interfaces")
'               fBool = %TRUE
'            END IF
'            hChild = TV_InsertItem(hTreeView1, hNode, szHiddenInterfaces(i))
'            TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
'         END IF
'      NEXT
'   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the restricted interfaces
   ' ---------------------------------------------------------------------------
'   fBool = %FALSE
'   IF UBOUND(szRestrictedInterfaces) > - 1 THEN
'      FOR i = LBOUND(szRestrictedInterfaces) TO UBOUND(szRestrictedInterfaces)
'         IF ISFALSE fBool THEN
'            hNode = TV_InsertItem(hTreeView1, hRoot, "Restricted interfaces")
'            fBool = %TRUE
'         END IF
'         hChild = TV_InsertItem(hTreeView1, hNode, szRestrictedInterfaces(i))
'         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
'      NEXT
'   END IF

   ' ---------------------------------------------------------------------------
   ' Shows the events interfaces
   ' ---------------------------------------------------------------------------
   fBool = %FALSE
   IF UBOUND(TLB_EventsArray) > - 1 THEN
      FOR i = LBOUND(TLB_EventsArray) TO UBOUND(TLB_EventsArray)
         IF ISFALSE fBool THEN
            hNode = TV_InsertItem(hTreeView1, hRoot, "Events interfaces")
            fBool = %TRUE
         END IF
         hChild = TV_InsertItem(hTreeView1, hNode, BYCOPY TLB_EventsArray(i))
         TreeView_Expand(hTreeView1, hChild, %TVE_EXPAND)
      NEXT
   END IF

   ' ---------------------------------------------------------------------------
   ' Enables redraw and repaints the control
   ' ---------------------------------------------------------------------------
   SendMessage hTreeView1, %WM_SETREDRAW, %TRUE, 0
   InvalidateRect hTreeView1, BYVAL %NULL, %TRUE
   UpdateWindow hTreeView1
   SendMessage hTreeView2, %WM_SETREDRAW, %TRUE, 0

   ' ---------------------------------------------------------------------------
   ' Hides the ListView and shows the TreeViews
   ' ---------------------------------------------------------------------------
   ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_GRID), %SW_HIDE
   ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_TREES), %SW_SHOW
   SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_SETCURSEL, 1, 0
   'SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_SETCURFOCUS, 1, 0
   ' Enable/disable toolbar buttons
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%TRUE, 0))
   IF UBOUND(TLB_EventsArray) > - 1 THEN
      SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%TRUE, 0))
   ELSEIF (SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_GETSTATE, %TB_ENABLEBUTTON, 0) AND %TBSTATE_ENABLED) = %TBSTATE_ENABLED THEN
      SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
   END IF
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%FALSE, 0))
   IF LEN(TLB_LibDoc.szHelpFile) THEN
      SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_TOOLBAR_HELP, MAKLNG(%TRUE, 0))
   ELSE
      SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_TOOLBAR_HELP, MAKLNG(%FALSE, 0))
   END IF
   ' Disable/enable menu items
   hMenu = GetMenu(hWnd)
   hSubMenu = GetSubMenu(hMenu, 0)
   CoolMenu_EnableMenuItem hSubMenu, %IDM_RELOAD, %MF_GRAYED
   CoolMenu_EnableMenuItem hSubMenu, %IDM_SAVE, %MF_GRAYED
   CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_ENABLED
   hSubMenu = GetSubMenu(hMenu, 1)
   IF UBOUND(TLB_GuidsArray) > - 1 OR UBOUND(TLB_ProgIDsArray) > - 1 OR UBOUND(TLB_IIDsArray) > - 1 THEN
      CoolMenu_EnableMenuItem hSubMenu, %IDM_IDENTIFIERS, %MF_ENABLED
   ELSE
      CoolMenu_EnableMenuItem hSubMenu, %IDM_IDENTIFIERS, %MF_GRAYED
   END IF
'   IF UBOUND(szInterfaces) > - 1 OR UBOUND(szDualInterfaces) > - 1 OR _
'      UBOUND(szDispInterfaces) > -1 OR UBOUND(szHiddenInterfaces) > - 1 OR _
'      UBOUND(szRestrictedInterfaces) > - 1 THEN
'      CoolMenu_EnableMenuItem hSubMenu, %IDM_INTERFACES, %MF_ENABLED
'   ELSE
'      CoolMenu_EnableMenuItem hSubMenu, %IDM_INTERFACES, %MF_GRAYED
'   END IF
   IF UBOUND(szInterfaces) > - 1 OR UBOUND(szDualInterfaces) > - 1 OR _
      UBOUND(szDispInterfaces) > -1 OR UBOUND(szOleautomationInterfaces) > - 1 OR _
      UBOUND(szDispatchableInterfaces) > - 1 THEN
      CoolMenu_EnableMenuItem hSubMenu, %IDM_INTERFACES, %MF_ENABLED
   ELSE
      CoolMenu_EnableMenuItem hSubMenu, %IDM_INTERFACES, %MF_GRAYED
   END IF
   IF UBOUND(szDualInterfaces) > - 1 OR UBOUND(szDispInterfaces) > -1 THEN
      CoolMenu_EnableMenuItem hSubMenu, %IDM_DISPINTERFACES, %MF_ENABLED
   ELSE
      CoolMenu_EnableMenuItem hSubMenu, %IDM_DISPINTERFACES, %MF_GRAYED
   END IF
   IF UBOUND(szEnums) > - 1 THEN
      CoolMenu_EnableMenuItem hSubMenu, %IDM_ENUMERATIONS, %MF_ENABLED
   ELSE
      CoolMenu_EnableMenuItem hSubMenu, %IDM_ENUMERATIONS, %MF_GRAYED
   END IF
   IF UBOUND(szModules) > - 1 THEN
      CoolMenu_EnableMenuItem hSubMenu, %IDM_MODULES, %MF_ENABLED
   ELSE
      CoolMenu_EnableMenuItem hSubMenu, %IDM_MODULES, %MF_GRAYED
   END IF
   IF UBOUND(szRecords) > - 1 OR UBOUND(szUnions) > - 1 THEN
      CoolMenu_EnableMenuItem hSubMenu, %IDM_RECORDS, %MF_ENABLED
   ELSE
      CoolMenu_EnableMenuItem hSubMenu, %IDM_RECORDS, %MF_GRAYED
   END IF
   DrawMenuBar hWnd

   ' Set the focus in the first TreeView
   SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_TREES))

   FUNCTION = %TRUE

Terminate:

   ' ---------------------------------------------------------------------------
   ' Releases the interfaces
   ' ---------------------------------------------------------------------------
   IF pTypeAttr THEN
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pITypeInfo = NOTHING
   pITypeLib = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sorts the items of the listview
' ========================================================================================
TYPE TLB_ITEMDATA
  strCol0 AS STRING * %MAX_PATH
  strCol1 AS STRING * %MAX_PATH
  strCol2 AS STRING * %MAX_PATH
  strCol3 AS STRING * %MAX_PATH
END TYPE

FUNCTION TLB_ListviewSortItems (BYVAL hListView AS DWORD) AS LONG

   LOCAL  tlvi         AS LVITEM
   LOCAL  nCount       AS LONG
   LOCAL  i            AS LONG
   LOCAL  lItemIdx     AS LONG
   LOCAL  szValue      AS ASCIIZ * %MAX_PATH
   DIM    atid (0)     AS TLB_ITEMDATA

   ' --- Retrieve the selected item to restore it later ---
   LOCAL iItem         AS LONG
   LOCAL szSelItemName AS ASCIIZ * %MAX_PATH
   iItem = ListView_GetSelectionMark(hListView)
   tlvi.mask = %LVIF_TEXT
   tlvi.cchTextMax = %MAX_PATH
   tlvi.iItem = iItem
   tlvi.pszText = VARPTR(szSelItemName)
   tlvi.iSubItem = 0
   SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi))
   ' ------------------------------------------------------

   IF m_PrevColSort <> m_ColumnToSort THEN
      m_PrevColSort = m_ColumnToSort
      m_SortOrder = "DESCEND"
   ELSE
      IF m_SortOrder = "DESCEND" THEN m_SortOrder = "ASCEND" ELSE m_SortOrder = "DESCEND"
   END IF

   IF hListView = %NULL THEN EXIT FUNCTION
   nCount = SendMessage(hListView, %LVM_GETITEMCOUNT, 0, 0)
   IF nCount = 0 THEN EXIT FUNCTION
   REDIM atid(nCount - 1)

   FOR i = 0 TO nCount - 1
      tlvi.mask = %LVIF_TEXT
      tlvi.cchTextMax = %MAX_PATH
      tlvi.iItem = i
      tlvi.pszText = VARPTR(szValue)
      tlvi.iSubItem = 0
      IF SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi)) = %TRUE THEN
         atid(i).strCol0 = szValue
      END IF
      szValue = ""
      tlvi.pszText = VARPTR(szValue)
      tlvi.iSubItem = 1
      IF SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi)) = %TRUE THEN
         atid(i).strCol1 = szValue
      END IF
      szValue = ""
      tlvi.pszText = VARPTR(szValue)
      tlvi.iSubItem = 2
      IF SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi)) = %TRUE THEN
         atid(i).strCol2 = szValue
      END IF
      szValue = ""
      tlvi.pszText = VARPTR(szValue)
      tlvi.iSubItem = 3
      IF SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi)) = %TRUE THEN
         atid(i).strCol3 = szValue
      END IF
   NEXT

   IF m_SortOrder = "DESCEND" THEN
      SELECT CASE m_ColumnToSort
         CASE 0 : ARRAY SORT atid(), FROM 1 TO %MAX_PATH, COLLATE UCASE, DESCEND
         CASE 1 : ARRAY SORT atid(), FROM (%MAX_PATH * 1) + 1 TO (%MAX_PATH * 2), COLLATE UCASE, DESCEND
         CASE 2 : ARRAY SORT atid(), FROM (%MAX_PATH * 2) + 1 TO (%MAX_PATH * 3), COLLATE UCASE, DESCEND
         CASE 3 : ARRAY SORT atid(), FROM (%MAX_PATH * 3) + 1 TO (%MAX_PATH * 4), COLLATE UCASE, DESCEND
      END SELECT
   ELSE
      SELECT CASE m_ColumnToSort
         CASE 0 : ARRAY SORT atid(), FROM 1 TO %MAX_PATH, COLLATE UCASE, ASCEND
         CASE 1 : ARRAY SORT atid(), FROM (%MAX_PATH * 1) + 1 TO (%MAX_PATH * 2), COLLATE UCASE, ASCEND
         CASE 2 : ARRAY SORT atid(), FROM (%MAX_PATH * 2) + 1 TO (%MAX_PATH * 3), COLLATE UCASE, ASCEND
         CASE 3 : ARRAY SORT atid(), FROM (%MAX_PATH * 3) + 1 TO (%MAX_PATH * 4), COLLATE UCASE, ASCEND
      END SELECT
   END IF

   ' Deletes all the items
   SendMessage(hListView, %LVM_DELETEALLITEMS, 0, 0)

   ' Inserts the sorted items
   FOR i = 0 TO nCount - 1
      tlvi.mask       = %LVIF_TEXT
      tlvi.iItem      = 0
      tlvi.iSubItem   = 0
      szValue = TRIM$(atid(i).strCol0)
      tlvi.pszText    = VARPTR(szValue)
      lItemIdx = SendMessage(hListView, %LVM_INSERTITEM, 0, BYVAL VARPTR(tlvi))
      tlvi.iItem      = lItemIdx
      tlvi.iSubItem   = 1
      szValue = TRIM$(atid(i).strCol1)
      tlvi.pszText    = VARPTR(szValue)
      SendMessage(hListView, %LVM_SETITEM, 0, BYVAL VARPTR(tlvi))
      tlvi.iItem      = lItemIdx
      tlvi.iSubItem   = 2
      szValue = TRIM$(atid(i).strCol2)
      tlvi.pszText    = VARPTR(szValue)
      SendMessage(hListView, %LVM_SETITEM, 0, BYVAL VARPTR(tlvi))
      tlvi.iItem      = lItemIdx
      tlvi.iSubItem   = 3
      szValue = TRIM$(atid(i).strCol3)
      tlvi.pszText    = VARPTR(szValue)
      SendMessage(hListView, %LVM_SETITEM, 0, BYVAL VARPTR(tlvi))
   NEXT

   ' --- Restore the selected item ------------------------
   LOCAL tlvf AS LV_FINDINFO
   tlvf.flags = %LVFI_STRING
   tlvf.psz = VARPTR(szSelItemName)
   tlvi.iItem = ListView_FindItem(hListView, -1, tlvf)
   IF tlvi.iItem > 0 THEN
      ListView_SetItemState hListView, tlvi.iItem, %LVIS_SELECTED OR %LVIS_FOCUSED, %LVIS_SELECTED OR %LVIS_FOCUSED
      ListView_EnsureVisible(hListView, tlvi.iItem, %TRUE)
   END IF
   ' ------------------------------------------------------

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts short paths to long paths.
' Use GetLongPathName with Windows 98 or superior, and an alternate way with Windows 95
' and Windows NT, that doesn't support this function.
' ========================================================================================
FUNCTION TLB_ShortPathToLongPath (BYVAL strPath AS STRING) AS STRING

   LOCAL dwLen    AS DWORD
   LOCAL vi       AS OSVERSIONINFO
   LOCAL szPath   AS ASCIIZ * %MAX_PATH
   LOCAL iPos     AS LONG
   LOCAL iSafety  AS LONG
   LOCAL strTemp  AS STRING
   LOCAL strNew   AS STRING

   IF LEN(strPath) = 0 THEN EXIT FUNCTION
   vi.dwOsVersionInfoSize = SIZEOF(vi)
   GetVersionEx vi
   IF ((vi.dwPlatformId = %VER_PLATFORM_WIN32_WINDOWS) AND (vi.dwMinorVersion <> 0) OR _
      vi.dwMajorVersion => 5) AND INSTR(strPath, "%") = 0 THEN
      dwLen = GetLongPathName(BYCOPY strPath, szPath, %MAX_PATH)
      FUNCTION = szPath
   ELSE
      DO UNTIL TALLY(strPath, "%") < 2
         iPos = INSTR(1, strPath, "%")   'Get first position
         strTemp = MID$(strPath, iPos + 1, (INSTR(iPos + 1, strPath, "%") - (iPos + 1)))
         strNew = ENVIRON$(strTemp)
         IF LEN(strNew) THEN REPLACE "%" + strTemp + "%" WITH strNew IN strPath
         INCR iSafety
         IF iSafety > 5 THEN EXIT LOOP 'If we find more than 5 vars...  something is wrong
      LOOP
      FUNCTION = strPath
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for the win32 subkey.
' ========================================================================================
FUNCTION TLB_RegSearchWin32 (BYREF szKey AS ASCIIZ) AS STRING

   LOCAL hr        AS LONG
   LOCAL dwIdx     AS DWORD
   LOCAL szKeyName AS ASCIIZ * %MAX_PATH
   LOCAL szClass   AS ASCIIZ * %MAX_PATH
   LOCAL ft        AS FILETIME
   LOCAL hKey      AS DWORD

   ' Recursively searches for the win32 directory
   DO
      hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      IF hKey = 0 THEN EXIT FUNCTION
      hr = RegEnumKeyEx (hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr THEN EXIT DO
      IF UCASE$(szKeyName) = "WIN32" THEN EXIT DO
      dwIdx = dwIdx + 1
   LOOP WHILE hr = 0

   ' Closes the registry and returns the result
   RegCloseKey hKey
   IF hr <> 0 OR szKeyName = "" THEN EXIT FUNCTION
   FUNCTION = szKey

END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for the win16 subkey.
' ========================================================================================
FUNCTION TLB_RegSearchWin16 (BYREF szKey AS ASCIIZ) AS STRING

   LOCAL hr        AS LONG
   LOCAL dwIdx     AS DWORD
   LOCAL szKeyName AS ASCIIZ * %MAX_PATH
   LOCAL szClass   AS ASCIIZ * %MAX_PATH
   LOCAL ft        AS FILETIME
   LOCAL hKey      AS DWORD

   dwIdx = 0
   DO
   hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      IF hKey = 0 THEN EXIT FUNCTION
      hr = RegEnumKeyEx (hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr THEN EXIT DO
      IF UCASE$(szKeyName) = "WIN16" THEN EXIT DO
      dwIdx = dwIdx + 1
   LOOP WHILE hr = 0

   ' Closes the registry and returns the result
   RegCloseKey hKey
   IF hr <> 0 OR szKeyName = "" THEN EXIT FUNCTION
   FUNCTION = szKey

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the path of the typelib.
' ========================================================================================
FUNCTION TLB_RegEnumDirectory (BYVAL strKey AS STRING) AS STRING

   LOCAL hr          AS LONG
   LOCAL dwIdx       AS DWORD
   LOCAL szKey       AS ASCIIZ * %MAX_PATH
   LOCAL szKeyName   AS ASCIIZ * %MAX_PATH
   LOCAL szClass     AS ASCIIZ * %MAX_PATH
   LOCAL ft          AS FILETIME
   LOCAL hKey        AS DWORD
   LOCAL strSubkey   AS STRING
   LOCAL szValueName AS ASCIIZ * %MAX_PATH
   LOCAL KeyType     AS DWORD
   LOCAL szKeyValue  AS ASCIIZ * %MAX_PATH
   LOCAL cValueName  AS DWORD
   LOCAL cbData      AS DWORD
   LOCAL IsWin32     AS LONG

   ' Searches the HKEY_CLASSES_ROOT\TypeLib\<LIBID> node.
   szKey = strKey
   hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
   IF hKey = 0 THEN EXIT FUNCTION
   dwIdx = 0
   DO
      hr = RegEnumKeyEx (hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr THEN EXIT DO
      strSubkey = TLB_RegSearchWin32(szKey & "\" & szKeyName)
      IF LEN(strSubkey) THEN
         IsWIn32 = -1
         EXIT DO
      END IF
      strSubkey = TLB_RegSearchWin16(szKey & "\" & szKeyName)
      IF LEN(strSubkey) THEN EXIT DO
      dwIdx = dwIdx + 1
   LOOP
   RegCloseKey hKey
   IF hr <> 0 OR strSubkey = "" THEN EXIT FUNCTION

   ' win32 node
   IF ISTRUE IsWin32 THEN
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      szKey = strSubkey & "\" & "win32"
      hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      hr = RegEnumValue (hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
   ELSE
      dwIdx = 0
      cValueName = %MAX_PATH
      cbData = %MAX_PATH
      szKey = strSubkey & "\" & "win16"
      hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
      IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
      hr = RegEnumValue (hKey, dwIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)
   END IF

   ' Closes the registry and returns the value
   RegCloseKey hKey
   FUNCTION = szKeyValue

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the different versions of the typelib.
' ========================================================================================
FUNCTION TLB_RegEnumVersions (BYVAL hListView AS DWORD, BYREF szCLSID AS ASCIIZ) AS LONG

   LOCAL hr          AS LONG
   LOCAL szKey       AS ASCIIZ * %MAX_PATH
   LOCAL szKeyName   AS ASCIIZ * %MAX_PATH
   LOCAL szClass     AS ASCIIZ * %MAX_PATH
   LOCAL ft          AS FILETIME
   LOCAL hKey        AS DWORD
   LOCAL dwIdx       AS DWORD
   LOCAL PathPos     AS LONG
   LOCAL i           AS LONG
   LOCAL szValueName AS ASCIIZ * %MAX_PATH
   LOCAL KeyType     AS DWORD
   LOCAL szKeyValue  AS ASCIIZ * %MAX_PATH
   LOCAL cValueName  AS DWORD
   LOCAL cbData      AS DWORD
   LOCAL hVerKey     AS DWORD
   LOCAL verIdx      AS DWORD
   LOCAL szTemp      AS ASCIIZ * %MAX_PATH
   LOCAL szDesc      AS ASCIIZ * %MAX_PATH
   LOCAL szPath      AS ASCIIZ * %MAX_PATH
   LOCAL szFile      AS ASCIIZ * %MAX_PATH
   LOCAL tlvi        AS LVITEM
   LOCAL lItemIdx    AS LONG

   IF hListView = %NULL OR VARPTR(szCLSID) = %NULL OR szCLSID = "" THEN EXIT FUNCTION

   cValueName = %MAX_PATH
   cbData     = %MAX_PATH

   ' Searches the HKEY_CLASSES_ROOT\TypeLib\<LIBID> node.
   szKey = "TypeLib\" & szCLSID
   hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
   IF hKey = 0 THEN EXIT FUNCTION
   dwIdx = 0

   ' Opens the subtrees of the different versions of the TyleLib library
   ' and stores the filenames, descriptions, paths and CLSIDs in a 4D array.
   DO
      hr = RegEnumKeyEx (hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr <> %ERROR_SUCCESS THEN EXIT DO
      ' Gets the default value
      verIdx = 0
      hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey & "\" & szKeyName, 0, %KEY_READ, hVerKey)
      hr = RegEnumValue(hVerKey, verIdx, szValueName, cValueName, BYVAL %NULL, KeyType, szKeyValue, cbData)   'Default value
      RegCloseKey hVerKey
      IF szValueName = "" THEN
         szDesc = szKeyValue
      ELSE
         szDesc = szValueName
      END IF
      szDesc += " (Ver " & szKeyName & ")"
      szPath = TLB_RegEnumDirectory(szKey & "\" & szKeyName)
      ' Remove double quotes (if any)
      szPath = REMOVE$(szPath, $DQ)
      ' Convert short paths to long paths
      ' Dont use it with all files or these ending with version numbers
      ' (a \ and a number) will we skipped.
      IF INSTR(szPath, "~") <> 0 OR INSTR(szPath, "%") <> 0 THEN szPath = TLB_ShortPathToLongPath(szPath)
      PathPos = INSTR(-1, szPath, "\")
      szFile = MID$(szPath, PathPos + 1)
      ' Some have added a backslah and a number
      IF INSTR(szFile, ".") = 0 THEN
         i = -(LEN(szFile) + 2)
         PathPos = INSTR(i, szPath, "\")
         szFile = UCASE$(MID$(szPath, PathPos + 1))
      END IF
      szFile = UCASE$(szFile)
      dwIdx = dwIdx + 1
      ' Skip .OCA files
      szTemp = szPath
      IF MID$(szTemp, -2, 1) = "\" THEN szTemp = LEFT$(szTemp, LEN(szTemp) - 2)
      IF MID$(szTemp, -3, 1) = "\" THEN szTemp = LEFT$(szTemp, LEN(szTemp) - 3)
      IF UCASE$(RIGHT$(szTemp, 4)) = ".OCA" THEN szPath = ""
      ' If there is not path skip the typelib
      IF LEN(szPath) THEN
         ' Add the items
         tlvi.mask       = %LVIF_TEXT
         tlvi.iItem      = 0
         tlvi.iSubItem   = 0
         tlvi.pszText    = VARPTR(szDesc)
         lItemIdx = SendMessage(hListView, %LVM_INSERTITEM, 0, BYVAL VARPTR(tlvi))
         tlvi.mask       = %LVIF_TEXT
         tlvi.iItem      = lItemIdx
         tlvi.iSubItem   = 1
         tlvi.pszText    = VARPTR(szFile)
         SendMessage hListView, %LVM_SETITEM, 0, BYVAL VARPTR(tlvi)
         tlvi.mask       = %LVIF_TEXT
         tlvi.iItem      = lItemIdx
         tlvi.iSubItem   = 2
         tlvi.pszText    = VARPTR(szPath)
         SendMessage hListView, %LVM_SETITEM, 0, BYVAL VARPTR(tlvi)
         szCLSID = UCASE$(szCLSID)
         tlvi.mask       = %LVIF_TEXT
         tlvi.iItem      = lItemIdx
         tlvi.iSubItem   = 3
         tlvi.pszText    = VARPTR(szCLSID)
         SendMessage hListView, %LVM_SETITEM, 0, BYVAL VARPTR(tlvi)
      END IF
   LOOP

   ' Closes the registry
   RegCloseKey hKey

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates all the typelibs.
' ========================================================================================
FUNCTION TLB_RegEnumTypeLibs (BYVAL hListView AS DWORD) AS LONG

   LOCAL hr        AS LONG
   LOCAL dwIdx     AS DWORD
   LOCAL szKey     AS ASCIIZ * %MAX_PATH
   LOCAL szKeyName AS ASCIIZ * %MAX_PATH
   LOCAL szClass   AS ASCIIZ * %MAX_PATH
   LOCAL ft        AS FILETIME
   LOCAL hKey      AS DWORD

   IF hListView = %NULL THEN EXIT FUNCTION

   ' Opens the HKEY_CLASSES_ROOT\TypeLib subtree.
   szKey = "TypeLib"
   hr = RegOpenKeyEx (%HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey)
   IF hr <> %ERROR_SUCCESS THEN EXIT FUNCTION
   IF hKey = 0 THEN EXIT FUNCTION
   dwIdx = 0
   ' Parses all the TypeLib subtree and gets the CLSIDs of all the TypeLibs.
   DO
      hr = RegEnumKeyEx (hKey, dwIdx, szKeyName, %MAX_PATH, 0, szClass, %MAX_PATH, ft)
      IF hr <> %ERROR_SUCCESS THEN EXIT DO
      TLB_RegEnumVersions hListView, szKeyName
      dwIdx = dwIdx + 1
   LOOP

   ' Closes the registry
   RegCloseKey hKey

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Documentation header
' ========================================================================================
SUB TLB_LibraryHeader (OPTIONAL BYVAL nItemType AS LONG)

   LOCAL szFmt AS ASCIIZ * 15                ' Date format
   LOCAL szDate AS ASCIIZ * %MAX_PATH        ' Formatted date

   szFmt = "dd MMM yyyy"
   GetDateFormat %LOCALE_USER_DEFAULT, 0, BYVAL %NULL, szFmt, szDate, SIZEOF(szDate)

   TLB_AddLine("' ########################################################################################")
   TLB_AddLine("' Library name: " & TLB_LibDoc.szName)
   TLB_AddLine("' Version: " & FORMAT$(TLB_LibDoc.MajorVersion) & "." & FORMAT$(TLB_LibDoc.MinorVersion) & ", Locale ID = " & FORMAT$(TLB_LibDoc.lcid))
   IF LEN(m_SelDesc) THEN TLB_AddLine("' Description: " & m_SelDesc)
   IF LEN(TLB_LibDoc.szHelpString) THEN
      IF TLB_LibDoc.szHelpString <> m_SelDesc THEN TLB_AddLine("' Documentation string: " & TLB_LibDoc.szHelpString)
   END IF
   TLB_AddLine("' Path: " & TLB_LibDoc.szPath)
   TLB_AddLine("' Library GUID: " & TLB_LibDoc.szGuid)
   IF LEN(TLB_LibDoc.szHelpFile) THEN TLB_AddLine("' Help file: " & TLB_LibDoc.szHelpFile)
   IF LEN(TLB_strLicKey) THEN TLB_AddLine("' License key: " & TLB_strLicKey)
   TLB_AddLine("' Code generated by the " & $cCaption)
   TLB_AddLine("' Date: " & szDate & "   Time: " & TIME$)
   TLB_AddLine("' Options used to generate the code:")
   IF m_UsePropGetSet THEN TLB_AddLine("' - Use METHOD and PROPERTY GET/SET statements")
   IF m_UseMethod THEN TLB_AddLine("' - Use METHOD statements only")
   IF m_UseSetPrefix THEN TLB_AddLine("' - Use SET_ instead of PUT_ as prefix")
   IF m_UseParameterNames THEN TLB_AddLine("' - Use parameter names in interface declarations")
   IF m_AddParameterNamesPrefix THEN TLB_AddLine("' - Add prefix in parameter names")
   IF m_UseIntNamesWithExObj THEN TLB_AddLine("' - Use interface names with external objects")
   IF m_UsePrefix THEN TLB_AddLine("' - Use prefix in interface names. Prefix = " & TLB_PrefixStr)
   IF m_UseEnumPrefix THEN TLB_AddLine("' - Use enumeration names as prefix in constants")
   IF m_UseHexNumbers THEN TLB_AddLine("' - Use hexadecimal numbers in constants")
   IF m_MixDispInterfaces THEN TLB_AddLine("' - Include dispatch only interfaces")
   IF m_MixDispInterfaces THEN TLB_AddLine("' - Retrieve license key")
   IF m_UseAutomationView THEN TLB_AddLine("' - Use automation view")
   TLB_AddLine("' ########################################################################################")
   TLB_AddLine("")

END SUB
' ========================================================================================

' ========================================================================================
' TLB_EnumIdentifiers helper procedure
' Enumerates the identifiers previously retrieved and stored in arrays.
' ========================================================================================
SUB TLB_EnumIdentifiers ( _
   BYVAL hWnd AS DWORD _                     ' Handle of the main window
   )

   LOCAL hPageCtrl   AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hTreeView   AS DWORD                ' // TreeView handle
   LOCAL strPrefix   AS STRING               ' // Prefix string
   LOCAL strText     AS STRING               ' // General purpose variable
   LOCAL strProgID   AS STRING               ' // ProgID
   LOCAL strClsID    AS STRING               ' // CLSID
   LOCAL strIID      AS STRING               ' // IID
   LOCAL fFirstTime  AS LONG                 ' // Flag
   LOCAL i           AS LONG                 ' // Loop counter
   LOCAL p           AS LONG                 ' // Position
   LOCAL strVerNum   AS STRING               ' // Version number
   LOCAL hStatusBar  AS DWORD                ' // Handle of the status bar
   LOCAL hPrefixBox  AS DWORD                ' // Handle of the edit box
   LOCAL szText      AS ASCIIZ * 255         ' // General purpose variable

   IF hWnd = %NULL THEN EXIT SUB
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF hTreeView = %NULL THEN EXIT SUB

   ' Prefix to use
   IF m_UsePrefix = %BST_CHECKED THEN
      hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
      IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
      IF hPrefixBox THEN GetWindowText(hPrefixBox, szText, SIZEOF(szText))
      TLB_PrefixStr = szText
      strPrefix = szText
   END IF

   ' Enumerates the ProgIDs
   fFirstTime = %TRUE
   IF UBOUND(TLB_GuidsArray) > -1 THEN
      FOR i = LBOUND(TLB_GuidsArray) TO UBOUND(TLB_GuidsArray)
         strProgID = ""
         IF TLB_GuidsArray(i).szProgID <> "" THEN
            strProgID = TLB_GuidsArray(i).szProgID
         END IF
         IF strProgID <> "" THEN
            IF ISTRUE fFirstTime THEN
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("' ProgIDs (Program identifiers)")
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
               fFirstTime = %FALSE
            END IF
            strText = "' CLSID = " & GUIDTXT$(TLB_GuidsArray(i).guid)
            TLB_AddLine(strText)
            p = 0
            strVernum = ""
            strText = ""
            p = INSTR(-1, strProgID, ".")
            IF p THEN
               strVerNum = MID$(strProgID, p + 1)
               strVerNum = RETAIN$(strVerNum, ANY "0123456789")
               strText = LEFT$(strProgID, p - 1)
               ' Some versions have two numbers, e.g. "xxx.4.0"
               p = INSTR(-1, strText, ".")
               IF p THEN
                  strVerNum = MID$(strText, p + 1) & strVernum
                  strVerNum = RETAIN$(strVerNum, ANY "0123456789")
               ELSE
                  ' And some have two numbers but only a dot, e.g. "xxx1.0"
                  IF LEN(strVernum) THEN
                     strText = RIGHT$(strText, 1)
                     strText = RETAIN$(strText, ANY "0123456789")
                     IF LEN(strText) THEN strVerNum = strText & strVernum
                  END IF
               END IF
            END IF
            ' Some coclasses already include the version number
            ' But don't use the code below, because it will generate
            ' duplicate equates in some cases, e.g. ieframe.dll
'            strText = RIGHT$(TLB_GuidsArray(i).szName, 1)
'            strText = RETAIN$(strText, ANY "0123456789")
'            IF LEN(strText) THEN strVerNum = ""
            ' HelpCtr.exe\1 has ProgIDs with quotes
            IF LEFT$(strProgID, 1) = $DQ THEN strProgID = $DQ & strProgID
            IF RIGHT$(strProgID, 1) = $DQ THEN strProgID = strProgID & $DQ
            strText = "$PROGID_" & strPrefix & TLB_GuidsArray(i).szName & strVernum & " = " & $DQ & strProgID & $DQ
            TLB_AddLine(strText)
         END IF
      NEXT
      IF ISFALSE fFirstTime THEN TLB_AddLine("")
   END IF

   ' Version independent ProgIDs
   fFirstTime = %TRUE
   IF UBOUND(TLB_GuidsArray) > -1 THEN
      FOR i = LBOUND(TLB_GuidsArray) TO UBOUND(TLB_GuidsArray)
         strProgID = ""
         IF UCASE$(TLB_GuidsArray(i).szProgID) <> UCASE$(TLB_GuidsArray(i).szVIProgID) THEN
            strProgID = TLB_GuidsArray(i).szVIProgID
         END IF
         IF strProgID <> "" THEN
            IF ISTRUE fFirstTime THEN
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("' Version independent ProgIDs")
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
               fFirstTime = %FALSE
            END IF
            strText = "' CLSID = " & GUIDTXT$(TLB_GuidsArray(i).guid)
            TLB_AddLine(strText)
            strText = "$PROGID_" & strPrefix & TLB_GuidsArray(i).szName & " = " & $DQ & strProgID & $DQ
            TLB_AddLine(strText)
         END IF
      NEXT
      IF ISFALSE fFirstTime THEN TLB_AddLine("")
   END IF

   ' Enumerates the ClsIDs
   IF UBOUND(TLB_GuidsArray) > -1 THEN
      TLB_AddLine("' ========================================================================================")
      TLB_AddLine("' ClsIDs (Class identifiers)")
      TLB_AddLine("' ========================================================================================")
      TLB_AddLine("")
      FOR i = LBOUND(TLB_GuidsArray) TO UBOUND(TLB_GuidsArray)
'         TLB_AddLine(LEFT$(TLB_GuidsArray(i).szPBSyntax, 1) & strPrefix & MID$(TLB_GuidsArray(i).szPBSyntax, 2))
         IF LEN(strPrefix) = 0 THEN
            TLB_AddLine(BYCOPY TLB_GuidsArray(i).szPBSyntax)
         ELSE
            strClsID = LEFT$(TLB_GuidsArray(i).szPBSyntax, 6)
            strText = MID$(TLB_GuidsArray(i).szPBSyntax, 7)
            DO
               IF LEFT$(strText, 1) <> "_" THEN EXIT DO
               strClsID += "_"
               strText = MID$(strText, 2)
            LOOP
            strClsID += strPrefix & strText
            TLB_AddLine(strClsID)
         END IF
      NEXT
      TLB_AddLine("")
   END IF

   ' Enumerates the IIDs
   IF UBOUND(TLB_IIDsArray) > -1 THEN
      TLB_AddLine("' ========================================================================================")
      TLB_AddLine("' IIDs (Interface identifiers)")
      TLB_AddLine("' ========================================================================================")
      TLB_AddLine("")
      FOR i = LBOUND(TLB_IIDsArray) TO UBOUND(TLB_IIDsArray)
'         TLB_AddLine(LEFT$(TLB_IIDsArray(i).szPBSyntax, 1) & strPrefix & MID$(TLB_IIDsArray(i).szPBSyntax, 2))
         IF LEN(strPrefix) = 0 THEN
            TLB_AddLine(BYCOPY TLB_IIDsArray(i).szPBSyntax)
         ELSE
            strIID = LEFT$(TLB_IIDsArray(i).szPBSyntax, 4)
            strText = MID$(TLB_IIDsArray(i).szPBSyntax, 5)
            DO
               IF LEFT$(strText, 1) <> "_" THEN EXIT DO
               strIID += "_"
               strText = MID$(strText, 2)
            LOOP
            strIID += strPrefix & strText
            TLB_AddLine(strIID)
         END IF
      NEXT
      TLB_AddLine("")
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Enumerates the CoClasses
' ========================================================================================
SUB TLB_EnumCoClasses (BYVAL hWnd AS DWORD, BYVAL strItemName AS STRING, OPTIONAL BYVAL nItemType AS LONG, BYVAL flags AS LONG)

   LOCAL hr AS LONG                          ' // HRESULT
   LOCAL hTreeView AS DWORD                  ' // TreeView handle
   LOCAL hPageCtrl AS DWORD                  ' // Handle of the page of the Tab control
   LOCAL pITypeLib AS ITypeLib               ' // Reference to the TypeLib interface
   LOCAL pITypeInfo AS ITypeInfo             ' // Reference to the TypeInfo interface
   LOCAL pImplTypeInfo AS ITypeInfo          ' // To switch views
   LOCAL pTypeAttr AS TYPEATTR PTR           ' // Address of a pointer to the TYPEATTR structure
   LOCAL pImplTypeAttr AS TYPEATTR PTR       ' // Address of a pointer to the TYPEATTR structure
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL bstrDocString AS WSTRING            ' // Documentation string (unicode)
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH     ' // Path (unicode)
   LOCAL szText AS ASCIIZ * 255              ' // General purpose variable
   LOCAL pdwHelpContext AS DWORD             ' // Help context
   LOCAL bstrHelpFile AS WSTRING             ' // Help file (unicode)
   LOCAL TypeInfoCount AS LONG               ' // Number of TypeInfos
   LOCAL pTKind AS DWORD                     ' // TYPEKIND
   LOCAL i AS LONG                           ' // Loop counter
   LOCAL x AS LONG                           ' // Loop counter
   LOCAL hRoot AS DWORD                      ' // Root node handle
   LOCAL hNode AS DWORD                      ' // Node name
   LOCAL pRefType AS DWORD                   ' // Address to a referenced type description
   LOCAL szKeyValue AS ASCIIZ * %MAX_PATH    ' // Buffer that receives the data
   LOCAL lImplTypeFlags AS DWORD             ' // Implemented interfaces flags
   DIM   szInterfaces() AS ASCIIZ * 255      ' // Implemented interfaces

   IF LEN(m_SelPath) = 0 THEN EXIT SUB
   IF LEN(strItemName) = 0 THEN EXIT SUB
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   IF hPageCtrl = %NULL THEN EXIT SUB
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF hTreeView = %NULL THEN EXIT SUB

   ' --- Loads the TypeLib ---------------------------------------------------------------
   wszPath = m_SelPath
   hr = LoadTypeLibEx(wszPath, %REGKIND_NONE, pITypeLib)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeLib) THEN
      MessageBox BYVAL %NULL, "Error &H" & HEX$(hr, 8) & " loading " & m_SelPath, _
             " " & FUNCNAME$ & " - LoadTypeLibEx", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      EXIT SUB
   END IF

   ' --- Retrieves the number of TypeInfos -----------------------------------------------
   TypeInfoCount = pITypeLib.GetTypeInfoCount()
   IF TypeInfoCount = 0 THEN
      MessageBox BYVAL %NULL, "This TypeLib doesn' have Type Infos" , _
         " " & FUNCNAME$ & " - ITypeLib::GetTypeInfoCount", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      pITypeLib = NOTHING
      EXIT SUB
   END IF

   ' Disables redraw to minimize flicker
   SendMessage hTreeView, %WM_SETREDRAW, %FALSE, 0
   ' Deletes the items
   IF TreeView_GetCount(hTreeView) THEN TreeView_DeleteAllItems(hTreeView)

   ' ========================================================================================
   ' Parses the TypeLib
   ' ========================================================================================
   FOR i = 0 TO TypeInfoCount - 1

      ' --- Allow for a breath and check the abort flag ---------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR

      ' --- Retrieves the TypeKind -------------------------------------------------------
      hr = pITypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the InfoType", _
            " " & FUNCNAME$ & " - ITypeLib.GetTypeInfoType", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' --- Retrieves the TypeInfo interface ---------------------------------------------
      hr = pITypeLib.GetTypeInfo(i, pITypeInfo)
      IF hr <> %S_OK THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the TypeInfo interface" , _
            " " & FUNCNAME$ & " - ITypeLib.GetTypeInfo", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' --- Gets the address of a pointer to the TYPEATTR structure ----------------------
      hr = pITypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the address of the TypeAttr structure" , _
            " " & FUNCNAME$ & " - ITypeInfo.GetTypeAttr", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' ==================================================================================
      ' If it is a CoClass ...
      ' ==================================================================================
      IF pTKind = %TKIND_COCLASS THEN

         pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         IF bstrName = strItemName OR nItemType = %ENUM_ALL THEN
            IF flags = %REPORT_CODEONLY THEN
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("' CoClass name: " & bstrName)
               TLB_AddLine("' ========================================================================================")
            END IF
            ' Root node
            IF flags = %REPORT_CODEONLY THEN
               TLB_AddLine("' CLSID (Class identifier): " & GUIDTXT$(@pTypeAttr.guid))
            ELSE
               hRoot = TV_InsertItem(hTreeView, 0, BYCOPY bstrName)
               hNode = TV_InsertItem(hTreeView, hRoot, "CLSID")
               TV_InsertItem hTreeView, hNode, GUIDTXT$(@pTypeAttr.guid)
               TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
            END IF
            szText = TRIM$(bstrDocString)
            IF LEN(szText) THEN
               IF flags = %REPORT_CODEONLY THEN
                  TLB_AddLine("' Help string: " & szText)
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "Help string")
                  TV_InsertItem hTreeView, hNode, szText
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            IF pdwHelpContext THEN
               IF flags = %REPORT_CODEONLY THEN
                  ' IF nItemType = %ENUM_ALL THEN TLB_AddLine("' Help context: " & FORMAT$(pdwHelpContext) & " [&H" & HEX$(pdwHelpContext, 8) & "]")
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "Help context")
                  TV_InsertItem hTreeView, hNode, FORMAT$(pdwHelpContext) & " [&H" & HEX$(pdwHelpContext, 8) & "]"
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            szText = TRIM$(bstrHelpFile)
            IF LEN(szText) THEN
               IF flags = %REPORT_CODEONLY THEN
                  ' TLB_AddLine("' Help file: " & szText)
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "Help file")
                  TV_InsertItem hTreeView, hNode, szText
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FCONTROL) = %TYPEFLAG_FCONTROL THEN TLB_HasControl = %TRUE
            IF @pTypeAttr.wTypeFlags THEN
               IF flags = %REPORT_CODEONLY THEN
                  TLB_AddLine("' Attributes: " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "Attributes")
                  TV_InsertItem(hTreeView, hNode, FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            ' -- Get the ProgId ----------------------------------------------------
            szKeyValue = TLB_GetProgID(GUIDTXT$(@pTypeAttr.guid))
            IF LEN(szKeyValue) THEN
               IF flags = %REPORT_CODEONLY THEN
                  TLB_AddLine("' ProgID (Program identifier): " & szKeyValue)
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "ProgID")
                  TV_InsertItem hTreeView, hNode, szKeyValue
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            ' -----------------------------------------------------------------------
            ' -- VersionIndependentProgID -------------------------------------------
            szKeyValue = TLB_GetVersionIndependentProgID(GUIDTXT$(@pTypeAttr.guid))
            IF LEN(szKeyValue) THEN
               IF flags = %REPORT_CODEONLY THEN
                  TLB_AddLine("' Version independent ProgID: " & szKeyValue)
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "Version independent ProgID")
                  TV_InsertItem hTreeView, hNode, szKeyValue
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            ' -----------------------------------------------------------------------
            ' -- InprocServer32 -----------------------------------------------------
            szKeyValue = TLB_GetInprocServer32(GUIDTXT$(@pTypeAttr.guid))
            IF LEN(szKeyValue) THEN
               IF flags = %REPORT_CODEONLY THEN
                  ' IF nItemType = %ENUM_ALL THEN TLB_AddLine("' InprocServer32: " & szKeyValue)
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "InprocServer32")
                  TV_InsertItem hTreeView, hNode, szKeyValue
                  TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
               END IF
            END IF
            ' -----------------------------------------------------------------------
            ' Implemented interfaces
            ' Note: Don't release pRefType or it will explode
            ' -----------------------------------------------------------------------
            FOR x = 0 TO @pTypeAttr.cImplTypes - 1
               lImplTypeFlags = 0
               hr = pITypeInfo.GetImplTypeFlags(x, lImplTypeFlags)
               IF hr <> %S_OK THEN EXIT FOR
               pRefType = 0
               hr = pITypeInfo.GetRefTypeOfImplType(x, pRefType)
               IF hr <> %S_OK THEN EXIT FOR
               hr = pITypeInfo.GetRefTypeInfo(pRefType, pImplTypeInfo)
               IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FOR
               pImplTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
               pImplTypeAttr = 0
               pImplTypeInfo.GetTypeAttr(pImplTypeAttr)
               REDIM PRESERVE szInterfaces(UBOUND(szInterfaces) + 1)
               szInterfaces(UBOUND(szInterfaces)) = bstrName
               IF lImplTypeFlags = 1 THEN        ' // Default interface
                  szInterfaces(UBOUND(szInterfaces)) = szInterfaces(UBOUND(szInterfaces)) & " (default interface)"
                  IF flags = %REPORT_CODEONLY THEN
                     TLB_AddLine("' Default interface: " & bstrName)
                  ELSE
                     hNode = TV_InsertItem(hTreeView, hRoot, "Default interface")
                     TV_InsertItem(hTreeView, hNode, BYCOPY bstrName)
                     TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                  END IF
                  IF pImplTypeAttr THEN
                     IF flags = %REPORT_CODEONLY THEN
                        TLB_AddLine("' Default interface IID: " & GUIDTXT$(@pImplTypeAttr.guid))
                     ELSE
                        hNode = TV_InsertItem(hTreeView, hRoot, "Default interface IID")
                        TV_InsertItem(hTreeView, hNode, GUIDTXT$(@pImplTypeAttr.guid))
                        TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                     END IF
                  END IF
               ELSEIF lImplTypeFlags = 2 THEN    ' // Events interface
                  szInterfaces(UBOUND(szInterfaces)) = szInterfaces(UBOUND(szInterfaces)) & " (events interface)"
                  IF flags = %REPORT_CODEONLY THEN
                     TLB_AddLine("' Events interface: " & bstrName)
                  ELSE
                     hNode = TV_InsertItem(hTreeView, hRoot, "Events interface")
                     TV_InsertItem(hTreeView, hNode, BYCOPY bstrName)
                     TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                  END IF
                  IF pImplTypeAttr THEN
                     IF flags = %REPORT_CODEONLY THEN
                        TLB_AddLine("' Default interface IID: " & GUIDTXT$(@pImplTypeAttr.guid))
                     ELSE
                        hNode = TV_InsertItem(hTreeView, hRoot, "Events interface IID")
                        TV_InsertItem(hTreeView, hNode, GUIDTXT$(@pImplTypeAttr.guid))
                        TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                     END IF
                  END IF
               ELSEIF lImplTypeFlags = 3 THEN    ' // Default events interface
                  szInterfaces(UBOUND(szInterfaces)) = szInterfaces(UBOUND(szInterfaces)) & " (default events interface)"
                  IF flags = %REPORT_CODEONLY THEN
                     TLB_AddLine("' Default events interface: " & bstrName)
                  ELSE
                     hNode = TV_InsertItem(hTreeView, hRoot, "Default events interface")
                     TV_InsertItem(hTreeView, hNode, BYCOPY bstrName)
                     TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                  END IF
                  IF pImplTypeAttr THEN
                     IF flags = %REPORT_CODEONLY THEN
                        TLB_AddLine("' Default events interface IID: " & GUIDTXT$(@pImplTypeAttr.guid))
                     ELSE
                        hNode = TV_InsertItem(hTreeView, hRoot, "Default events interface IID")
                        TV_InsertItem(hTreeView, hNode, GUIDTXT$(@pImplTypeAttr.guid))
                        TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                     END IF
                  END IF
               END IF
            NEXT
            ' --- Releases the TYPEATTR atructure --------------------------------------
            IF pImplTypeAttr THEN
               pImplTypeInfo.ReleaseTypeAttr(pImplTypeAttr)
               pImplTypeAttr = 0
            END IF
            ' --- Releases the interface -----------------------------------------------
            pImplTypeInfo = NOTHING
            ' --- Shows the interfaces -------------------------------------------------
            IF UBOUND(szInterfaces) > - 1 THEN
               IF flags = %REPORT_CODEONLY THEN
                  TLB_AddLine("' Implemented interfaces:")
               ELSE
                  hNode = TV_InsertItem(hTreeView, hRoot, "Implemented interfaces")
               END IF
               FOR x = LBOUND(szInterfaces) TO UBOUND(szInterfaces)
                  IF flags = %REPORT_CODEONLY THEN
                     TLB_AddLine("'  " & szInterfaces(x))
                  ELSE
                     TV_InsertItem hTreeView, hNode, szInterfaces(x)
                     TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
                  END IF
               NEXT
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
            END IF
            ' -----------------------------------------------------------------------
            ERASE szInterfaces
         END IF
      END IF
      ' ==================================================================================

      ' Releases the TYPEATTR structure
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0

      ' Releases the TypeInfo interface
      pITypeInfo = NOTHING

   NEXT
   ' ========================================================================================

Terminate:

   ' Releases the interfaces
   IF ISTRUE pTypeAttr THEN
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pITypeInfo = NOTHING
   pITypeLib = NOTHING

   ' Expands the root node
   TreeView_Expand(hTreeView, hRoot, %TVE_EXPAND)

   ' Enables redraw and repaints the control
   SendMessage hTreeView, %WM_SETREDRAW, %TRUE, 0
   InvalidateRect hTreeView, BYVAL %NULL, %TRUE
   UpdateWindow hTreeView

END SUB
' ========================================================================================

' ========================================================================================
' TLB_GetVarDescInfo helper procedure
' Retrieves information about a variable, constant, or data member described by the
' VARDESC structure and returns and string formatted according the PB syntax.
' ========================================================================================
SUB TLB_GetVarDescInfo ( _
   BYVAL pITypeInfo AS ITypeInfo _
 , BYVAL pVarDesc AS VARDESC PTR _
 , BYREF tvd AS TLB_VARDESC_STRUCT _
   )

   LOCAL hr                AS LONG                 ' // HRESULT
   LOCAL bstrName          AS WSTRING              ' // Member's name (unicode)
   LOCAL lpadesc           AS ARRAYDESC PTR        ' // Pointer to an ARRAYDESC structure
   LOCAL cDims             AS WORD                 ' // Number of dimensions of the array
   LOCAL cElements         AS LONG                 ' // Elements of the array
   LOCAL x                 AS LONG                 ' // Loop counter
   LOCAL pRefTypeInfo      AS ITypeInfo            ' // Address to a referenced TypeInfo
   LOCAL pVarTypeAttr      AS TYPEATTR PTR         ' // Type attribute for the member
   LOCAL lptdesc           AS TYPEDESC PTR         ' // Pointer to a TYPEDESC structure
   LOCAL strAlias          AS STRING               ' // Alias name
   LOCAL strText           AS STRING               ' // General purpose variable

   tvd.szText = ""
   tvd.szVtPtr = ""
   tvd.wIndirectionLevel = 0
   tvd.vtOld = 0

   ' Variable type
   tvd.vt = @pVarDesc.elemdescVar.tdesc.vt

   ' -------------------------------------------------------------------------------------
   ' Void
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_VOID THEN
      tvd.szText = VarTypeToStr(tvd.vt)
      tvd.szPBSyntax = tvd.szPbName & " AS DWORD"
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' BSTR (Unicode dynamic string)
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_BSTR THEN
      tvd.szText = VarTypeToStr(tvd.vt)
      tvd.szPBSyntax = tvd.szPBName & " AS WSTRING PTR"
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' LPWSTR (Null terminated unicode string)
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_LPWSTR THEN
      tvd.szText = VarTypeToStr(tvd.vt)
      tvd.szPBSyntax = tvd.szPBName & " AS WSTRINGZ PTR"
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' LPSTR (null-terminated ANSI string)
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_LPSTR THEN
      tvd.szText = VarTypeToStr(tvd.vt)
      tvd.szPBSyntax = tvd.szPBName & " AS ASCIIZ PTR"
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' VARIANT
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_VARIANT THEN
      tvd.szText = VarTypeToStr(tvd.vt)
      tvd.szPBSyntax = tvd.szPBName & " AS tagVARIANT"
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Array
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_CARRAY THEN
      ' Search for array bounds
      lpadesc = @pVarDesc.elemdescVar.tdesc.lpadesc
      cDims = @lpadesc.cDims
      tvd.szText = "%VT_CARRAY <" & VarTypeToStr(@lpadesc.tdescElem.vt) & ">"
      IF @lpadesc.tdescElem.vt = 16 OR @lpadesc.tdescElem.vt = 17 THEN  ' Byte
         cElements = @lpadesc.rgbounds(0).cElements
         tvd.szPBSyntax = tvd.szPBName & " AS STRING * " & FORMAT$(cElements)
      ELSEIF @lpadesc.tdescElem.vt = 18 THEN  ' Word (Unicode string)
         cElements = @lpadesc.rgbounds(0).cElements
         tvd.szPBSyntax = tvd.szPBName & " AS WSTRING * " & FORMAT$(cElements)
      ELSE
         tvd.szPBSyntax = tvd.szPBName & " ("
         FOR x = 0 TO cDims - 1
            tvd.szPBSyntax += FORMAT$(@lpadesc.rgbounds(x).lLBound) & " TO "
            tvd.szPBSyntax += FORMAT$(@lpadesc.rgbounds(x).lLBound + @lpadesc.rgbounds(x).cElements - 1)
            IF cDims > 1 THEN tvd.szPBSyntax += ", "
         NEXT
         IF @lpadesc.tdescElem.vt = %VT_BSTR THEN
            tvd.szPBSyntax += ") AS WSTRING PTR"
            tvd.szText = "%VT_CARRAY <" & VarTypeToStr(@lpadesc.tdescElem.vt) & ">"
         ELSEIF @lpadesc.tdescElem.vt = %VT_LPWSTR THEN
            tvd.szPBSyntax += ") AS WSTRINGZ PTR"
            tvd.szText = "%VT_CARRAY <" & VarTypeToStr(@lpadesc.tdescElem.vt) & ">"
         ELSEIF @lpadesc.tdescElem.vt = %VT_LPSTR THEN
            tvd.szPBSyntax += ") AS ASCIIZ PTR"
            tvd.szText = "%VT_CARRAY <" & VarTypeToStr(@lpadesc.tdescElem.vt) & ">"
         ELSEIF @lpadesc.tdescElem.vt = %VT_USERDEFINED THEN
            hr = pITypeInfo.GetRefTypeInfo(@lpadesc.tdescElem.hreftype, pRefTypeInfo)
            IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
               hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
               IF hr = %S_OK THEN tvd.szText = "%VT_CARRAY <" & bstrName & ">"
               hr = pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
               IF hr = %S_OK AND pVarTypeAttr <> %NULL THEN
                  SELECT CASE @pVarTypeAttr.typekind
                     CASE %TKIND_ENUM
                        tvd.szPBSyntax += ") AS LONG"
                     CASE %TKIND_RECORD
                        IF LEFT$(bstrName, 1) = "_" THEN
                           tvd.szPBSyntax += ") AS tag" & bstrName
                        ELSE
                           tvd.szPBSyntax += ") AS " & bstrName
                        END IF
                     CASE %TKIND_UNION
                        IF LEFT$(bstrName, 1) = "_" THEN
                           tvd.szPBSyntax += ") AS u" & bstrName
                        ELSE
                           tvd.szPBSyntax += ") AS " & bstrName
                        END IF
                     CASE %TKIND_ALIAS
                        IF @pVarTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                           strAlias = TLB_GetAliasNameFromArray2(bstrName)
                           IF LEN(strAlias) THEN
                              tvd.szAliasName = strAlias
                              tvd.szText += " <alias> " & strAlias
                           ELSE
                              tvd.szText += " <alias> <" & VarTypeToConstant(@pVarTypeAttr.tdescalias.vt) & ">"
                           END IF
                           IF @pVarTypeAttr.tdescalias.vt = %VT_BSTR THEN
                              tvd.szPBSyntax = tvd.szPBName & " AS WSTRING"
                           ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                              tvd.szPBSyntax = tvd.szPBName & " AS WSTRINGZ"
                           ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                              tvd.szPBSyntax = tvd.szPBName & " AS ASCIIZ"
                           ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                              tvd.szPBSyntax = tvd.szPBName & " AS tagVARIANT"
                           ELSE
                              tvd.szPBSyntax = tvd.szPBName & " AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt)
                           END IF
                        ELSE
                           tvd.szAliasName = TLB_GetAliasName (pRefTypeInfo, @pVarTypeAttr.tdescalias.hreftype, tvd.szTypeKind, tvd.typekind, tvd.szGuid)
                           IF LEN(tvd.szAliasName) THEN
                              tvd.szText += " <alias> " & tvd.szAliasName
                              IF tvd.typekind = %TKIND_RECORD THEN tvd.szText += " <record>"
                              IF tvd.typekind = %TKIND_UNION THEN tvd.szText += " <union>"
                              IF LEFT$(tvd.szAliasName, 1) = "_" THEN
                                 IF tvd.typekind = %TKIND_RECORD THEN tvd.szAliasName = "tag" & tvd.szAliasName
                                 IF tvd.typekind = %TKIND_UNION THEN tvd.szAliasName = "u" & tvd.szAliasName
                              END IF
                              IF tvd.typekind = %TKIND_ENUM OR tvd.typekind = %TKIND_MODULE THEN
                                 tvd.szPBSyntax = tvd.szPBName & " AS LONG"
                              ELSEIF tvd.typekind = %TKIND_INTERFACE OR tvd.typekind = %TKIND_DISPATCH OR tvd.typekind = %TKIND_COCLASS THEN
                                 tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                              ELSEIF tvd.typekind = %TKIND_RECORD OR tvd.typekind = %TKIND_UNION THEN
                                 'tvd.szPBSyntax = tvd.szPBName & " AS " & tvd.szAliasName
                                 tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                              ELSE
                                 'tvd.szPBSyntax = tvd.szPBName & " AS " & tvd.szAliasName
                                 tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                              END IF
                           ELSE
                              tvd.szText = tvd.szText & " <alias> <" & VarTypeToConstant(@pVarTypeAttr.tdescalias.vt) & ">"
                              tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                           END IF
                        END IF
                     CASE ELSE
                        tvd.szPBSyntax += ") AS " & VarTypeToKeyword(@lpadesc.tdescElem.vt)
                  END SELECT
                  pRefTypeInfo.ReleaseTypeAttr(pVarTypeAttr)
                  pVarTypeAttr = %NULL
               END IF
               pRefTypeInfo = NOTHING
            END IF
         ELSE
            tvd.szPBSyntax += ") AS " & VarTypeToKeyword(@lpadesc.tdescElem.vt)
         END IF
         tvd.szPBSyntax = REMOVE$(tvd.szPBSyntax, "0 TO ")
      END IF
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' User defined
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_USERDEFINED THEN
      hr = pITypeInfo.GetRefTypeInfo(@pVarDesc.elemdescVar.tdesc.hreftype, pRefTypeInfo)
      IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
         hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         IF hr = %S_OK THEN tvd.szText = bstrName
         hr = pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
         IF hr = %S_OK AND pVarTypeAttr <> %NULL THEN
            SELECT CASE @pVarTypeAttr.typekind
               CASE %TKIND_ENUM
                  tvd.szText += " <enum>"
                  tvd.szPBSyntax = tvd.szPBName & " AS LONG"
               CASE %TKIND_RECORD
                  tvd.szText += " <record>"
                  IF LEFT$(bstrName, 1) = "_" THEN
                     tvd.szPBSyntax = tvd.szPBName & " AS tag" & bstrName
                  ELSE
                     tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                  END IF
               CASE %TKIND_UNION
                  tvd.szText += " <union>"
                  IF LEFT$(bstrName, 1) = "_" THEN
                     tvd.szPBSyntax = tvd.szPBName & " AS u" & bstrName
                  ELSE
                     tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                  END IF
               CASE %TKIND_MODULE
                  tvd.szText += " <module>"
               CASE %TKIND_INTERFACE
                  tvd.szText += " <interface>"
                  tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
               CASE %TKIND_DISPATCH
                  tvd.szText += " <dispinterface>"
                  tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
               CASE %TKIND_COCLASS
                  tvd.szText += " <coclass>"
                  tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
               CASE %TKIND_ALIAS
                  IF @pVarTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                     strAlias = TLB_GetAliasNameFromArray2(bstrName)
                     IF LEN(strAlias) THEN
                        tvd.szAliasName = strAlias
                        tvd.szText += " <alias> " & strAlias
                     ELSE
                        tvd.szText += " <alias> <" & VarTypeToConstant(@pVarTypeAttr.tdescalias.vt) & ">"
                     END IF
                     IF @pVarTypeAttr.tdescalias.vt = %VT_BSTR THEN
                        tvd.szPBSyntax = tvd.szPBName & " AS WSTRING"
                     ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                        tvd.szPBSyntax = tvd.szPBName & " AS WSTRINGZ"
                     ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                        tvd.szPBSyntax = tvd.szPBName & " AS ASCIIZ"
                     ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                        tvd.szPBSyntax = tvd.szPBName & " AS tagVARIANT"
                     ELSE
                        tvd.szPBSyntax = tvd.szPBName & " AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt)
                     END IF
                  ELSE
                     tvd.szAliasName = TLB_GetAliasName (pRefTypeInfo, @pVarTypeAttr.tdescalias.hreftype, tvd.szTypeKind, tvd.typekind, tvd.szGuid)
                     IF LEN(tvd.szAliasName) THEN
                        tvd.szText += " <alias> " & tvd.szAliasName
                        IF tvd.typekind = %TKIND_RECORD THEN tvd.szText = tvd.szText & " <record>"
                        IF tvd.typekind = %TKIND_UNION THEN tvd.szText = tvd.szText & " <union>"
                        IF LEFT$(tvd.szAliasName, 1) = "_" THEN
                           IF tvd.typekind = %TKIND_RECORD THEN tvd.szAliasName = "tag" & tvd.szAliasName
                           IF tvd.typekind = %TKIND_UNION THEN tvd.szAliasName = "u" & tvd.szAliasName
                        END IF
                        IF tvd.typekind = %TKIND_ENUM OR tvd.typekind = %TKIND_MODULE THEN
                           tvd.szPBSyntax = tvd.szPBName & " AS LONG"
                        ELSEIF tvd.typekind = %TKIND_INTERFACE OR tvd.typekind = %TKIND_DISPATCH OR tvd.typekind = %TKIND_COCLASS THEN
                           tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                        ELSEIF tvd.typekind = %TKIND_RECORD OR tvd.typekind = %TKIND_UNION THEN
                           'tvd.szPBSyntax = tvd.szPBName & " AS " & tvd.szAliasName
                           tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                        ELSE
                           'tvd.szPBSyntax = tvd.szPBName & " AS " & tvd.szAliasName
                           tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                        END IF
                     ELSE
                        tvd.szText = tvd.szText & " <alias> <" & VarTypeToConstant(@pVarTypeAttr.tdescalias.vt) & ">"
                        tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                     END IF
                  END IF
            END SELECT
            pRefTypeInfo.ReleaseTypeAttr(pVarTypeAttr)
            pVarTypeAttr = %NULL
         END IF
         pRefTypeInfo = NOTHING
      ELSE
         ' GetRefTypeInfo fails with four of the members of the VSPROPSHEETPAGE structure (in BINED.DLL)
         tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
         tvd.szText += "<GetRefTypeInfo failed - Error = &H" & HEX$(hr, 8) & ">"
      END IF
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Pointer or safearray
   ' -------------------------------------------------------------------------------------
   IF tvd.vt = %VT_PTR OR tvd.vt = %VT_SAFEARRAY THEN
      tvd.vtOld = tvd.vt
      tvd.wIndirectionLevel = 1
      IF tvd.vt = %VT_PTR THEN tvd.szVtPtr = "VT_PTR"
      IF tvd.vt = %VT_SAFEARRAY THEN tvd.szVtPtr = "VT_SAFEARRAY"
      ' Gets a pointer to another TYPEDESC structure
      lptdesc = @pVarDesc.elemdescVar.tdesc.lptdesc
      DO
         ' VarType
         tvd.vt = @lptdesc.vt
         SELECT CASE tvd.vt
            ' If it is another pointer, loop again
            CASE %VT_PTR
               INCR tvd.wIndirectionLevel
               tvd.szVtPtr = tvd.szVtPtr & "->VT_PTR"
               lptdesc = @lptdesc.lptdesc
            ' If it is a userdefined type (record or enum), get the name
            ' of the referenced type and store it
            CASE %VT_USERDEFINED
               tvd.vtOld = tvd.vt
               tvd.szVtPtr = tvd.szVtPtr & "->VT_USERDEFINED"
               hr = pITypeInfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
               IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                  hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr = %S_OK THEN
                     tvd.szText = bstrName
                     pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
                     IF ISTRUE pVarTypeAttr THEN
                        SELECT CASE @pVarTypeAttr.typekind
                           CASE %TKIND_ENUM
                              tvd.szPBSyntax = tvd.szPBName & " AS LONG"
                              tvd.szText += " <enum>"
                           CASE %TKIND_RECORD
                              strAlias = TLB_GetAliasNameFromArray2(tvd.szText)
                              IF LEN(strAlias) THEN
                                 strText = tvd.szText
                                 tvd.szText = strAlias
                              END IF
                              IF LEFT$(tvd.szText, 1) = "_" THEN
                                 tvd.szPBSyntax = tvd.szPBName & " AS " & "tag" & tvd.szText & " PTR"
                              ELSE
                                 tvd.szPBSyntax = tvd.szPBName & " AS " & tvd.szText & " PTR"
                              END IF
                              IF LEN(strAlias) THEN tvd.szText = strAlias & " <alias> " & strText & " <record>"
                           CASE %TKIND_UNION
                              strAlias = TLB_GetAliasNameFromArray2(tvd.szText)
                              IF LEN(strAlias) THEN
                                 strText = tvd.szText
                                 tvd.szText = strAlias
                              END IF
                              IF LEFT$(tvd.szText, 1) = "_" THEN
                                 tvd.szPBSyntax = tvd.szPBName & " AS " & "u" & tvd.szText & " PTR"
                              ELSE
                                 tvd.szPBSyntax = tvd.szPBName & " AS " & tvd.szText & " PTR"
                              END IF
                              IF LEN(strAlias) THEN tvd.szText = strAlias & " <alias> " & strText & " <union>"
                           CASE %TKIND_MODULE
                              tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                              tvd.szText += " <module>"
                           CASE %TKIND_INTERFACE
                              tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                              tvd.szText += " <interface>"
                           CASE %TKIND_DISPATCH
                              tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                              tvd.szText += " <dispinterface>"
                           CASE %TKIND_COCLASS
                              tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                              tvd.szText += " <coclass>"
                           CASE %TKIND_ALIAS
                              IF @pVarTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                 strAlias = TLB_GetAliasNameFromArray2(bstrName)
                                 IF LEN(strAlias) THEN
                                    tvd.szAliasName = strAlias
                                    tvd.szText += " <alias> " & strAlias
                                 ELSE
                                    tvd.szText += " <alias> <" & VarTypeToConstant(@pVarTypeAttr.tdescalias.vt) & ">"
                                 END IF
                                 IF @pVarTypeAttr.tdescalias.vt = %VT_BSTR THEN
                                    tvd.szPBSyntax = tvd.szPBName & " AS WSTRING"
                                 ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                                    tvd.szPBSyntax = tvd.szPBName & " AS WSTRINGZ"
                                 ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                                    tvd.szPBSyntax = tvd.szPBName & " AS ASCIIZ"
                                 ELSEIF @pVarTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                                    tvd.szPBSyntax = tvd.szPBName & " AS tagVARIANT"
                                 ELSE
                                    tvd.szPBSyntax = tvd.szPBName & " AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt)
                                 END IF
                              ELSE
                                 tvd.szAliasName = TLB_GetAliasName(pRefTypeInfo, @pVarTypeAttr.tdescalias.hreftype, tvd.szTypeKind, tvd.typekind, tvd.szGuid)
                                 IF LEN(tvd.szAliasName) THEN
                                    tvd.szText += " <alias> " & strAlias
                                    IF tvd.typekind = %TKIND_RECORD THEN tvd.szText = tvd.szText & " <record>"
                                    IF tvd.typekind = %TKIND_UNION THEN tvd.szText = tvd.szText & " <union>"
                                    IF LEFT$(tvd.szAliasName, 1) = "_" THEN
                                       IF tvd.typekind = %TKIND_RECORD THEN tvd.szAliasName = "tag" & tvd.szAliasName
                                       IF tvd.typekind = %TKIND_UNION THEN tvd.szAliasName = "u" & tvd.szAliasName
                                    END IF
                                    IF tvd.typekind = %TKIND_ENUM OR tvd.typekind = %TKIND_MODULE THEN
                                       tvd.szPBSyntax = tvd.szPBName & " AS LONG"
                                    ELSEIF tvd.typekind = %TKIND_INTERFACE OR tvd.typekind = %TKIND_DISPATCH OR tvd.typekind = %TKIND_COCLASS THEN
                                       tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                                    ELSEIF tvd.typekind = %TKIND_RECORD OR tvd.typekind = %TKIND_UNION THEN
                                       'tvd.szPBSyntax = tvd.szPBName & ") AS " & tvd.szAliasName
                                       tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                                    ELSE
                                       'tvd.szPBSyntax = tvd.szPBName & ") AS " & tvd.szAliasName
                                       tvd.szPBSyntax = tvd.szPBName & " AS " & bstrName
                                    END IF
                                 ELSE
                                    tvd.szText += " <alias> <" & VarTypeToConstant(@pVarTypeAttr.tdescalias.vt) & ">"
                                    tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                                 END IF
                              END IF
                        END SELECT
                        pRefTypeInfo.ReleaseTypeAttr(pVarTypeAttr)
                        pVarTypeAttr = %NULL
                        tvd.szText = STRING$(tvd.wIndirectionLevel, "*") & tvd.szText
                     END IF
                  END IF
                  pRefTypeInfo = NOTHING
               ELSE
                  tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                  tvd.szText += "<GetRefTypeInfo failed - Error = &H" & HEX$(hr, 8) & ">"
               END IF
               EXIT DO
            CASE ELSE
               tvd.szText = STRING$(tvd.wIndirectionLevel, "*") & VarTypeToStr(tvd.vt)
               IF tvd.vt = %VT_VARIANT THEN
                  tvd.szPBSyntax = tvd.szPBName & " AS tagVARIANT PTR"
               ELSEIF tvd.vt = %VT_BSTR THEN
                  tvd.szPBSyntax = tvd.szPBName & " AS WSTRING PTR"
               ELSEIF tvd.vt = %VT_LPWSTR THEN
                  tvd.szPBSyntax = tvd.szPBName & " AS WSTRINGZ PTR"
               ELSEIF tvd.vt = %VT_LPSTR THEN
                  tvd.szPBSyntax = tvd.szPBName & " AS ASCIIZ PTR"
               ELSE
                  ' It is a pointer
                  IF tvd.vtOld THEN tvd.szText = STRING$(tvd.wIndirectionLevel, "*") & VarTypeToStr(tvd.vtOld) & " <" & VarTypeToKeyword(tvd.vt) & ">"
                  'IF tvd.vtOld = %VT_SAFEARRAY THEN
                  '   tvd.szPBSyntax = tvd.szPBName & " AS SAFEARRAY PTR"
                  'ELSE
                  '   tvd.szPBSyntax = tvd.szPBName & " AS " & VarTypeToKeyword(tvd.vt) & " PTR"
                  'END IF
                  IF tvd.vtOld = %VT_SAFEARRAY THEN
                     tvd.szPBSyntax = tvd.szPBName & " AS DWORD"
                  ELSE
                     tvd.szPBSyntax = tvd.szPBName & " AS " & VarTypeToKeyword(tvd.vt) & " PTR"
                  END IF
               END IF
               EXIT DO
         END SELECT
      LOOP
      EXIT SUB
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Other
   ' -------------------------------------------------------------------------------------
   tvd.szText = VarTypeToStr(tvd.vt)
   tvd.szPBSyntax = tvd.szPBName & " AS " & VarTypeToKeyword(tvd.vt)
   ' -------------------------------------------------------------------------------------

END SUB
' ========================================================================================

' ========================================================================================
' TLB_GetMembers helper procedure
' Retrieves information about the members of a record or union, or about datamembers.
' ========================================================================================
SUB TLB_GetMembers ( _
   BYVAL hWnd              AS DWORD _
 , BYVAL pITypeInfo        AS ITypeInfo _
 , BYVAL cVars             AS LONG _
 , BYVAL hRoot             AS DWORD _
 , BYVAL pITypeLib         AS ITypeLib _
 , BYVAL bIsRecord         AS LONG _
 , BYVAL bViewOnly         AS LONG _
   )

   LOCAL hPageCtrl         AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hTreeView         AS DWORD                ' // TreeView handle
   LOCAL tvd               AS TLB_VARDESC_STRUCT   ' // Custom data
   LOCAL hr                AS DWORD                ' // HRESULT
   LOCAL pVarDesc          AS VARDESC PTR          ' // Pointer to a VARDESC structure
   LOCAL bstrName          AS WSTRING              ' // Member's name (unicode)
   LOCAL hNode             AS DWORD                ' // Node handle
   LOCAL hChildNode        AS DWORD                ' // Child node
   LOCAL lpadesc           AS ARRAYDESC PTR        ' // Pointer to an ARRAYDESC structure
   LOCAL strLine           AS STRING               ' // General purpose variable
   LOCAL i                 AS LONG                 ' // Loop counter
   LOCAL x                 AS LONG                 ' // Loop counter
   LOCAL strAlias          AS STRING               ' // Alias

'   IF ISFALSE bViewOnly AND ISFALSE hFile THEN EXIT SUB

   IF hWnd = %NULL THEN EXIT SUB
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF bViewOnly = %TRUE AND hTreeView = %NULL THEN EXIT SUB

   FOR i = 0 TO cVars - 1

      ' --- Allow for a breath and check the abort flag ----------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR

      ' --- Gets a reference to the VarDesc interface ------------------------------------
      hr = pITypeInfo.GetVarDesc(i, pVarDesc)
      IF hr <> %S_OK OR pVarDesc = %NULL THEN EXIT FOR

      ' --- Variable name ----------------------------------------------------------------
      pITypeInfo.GetDocumentation(@pVarDesc.memid, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
      tvd.szName = bstrName
      IF LEFT$(tvd.szName, 1) = "_" THEN tvd.szName = "m" & tvd.szName
      tvd.szPBName = tvd.szName
      ' Records and unions allow all names excepting "END"
      IF bIsRecord THEN
         IF UCASE$(tvd.szName) = "END" THEN
            tvd.szPBName = tvd.szName & "_"
         END IF
      END IF

      ' --- Retrieves information about the variable or parameter ------------------------
      TLB_GetVarDescInfo(pITypeInfo, pVarDesc, tvd)
      REPLACE "IUnknown" WITH "DWORD" IN tvd.szPBSyntax
      REPLACE "IDispatch" WITH "DWORD" IN tvd.szPBSyntax

      ' --- Shows the information --------------------------------------------------------
      IF bViewOnly THEN
         hNode = TV_InsertItem(hTreeView, hRoot, tvd.szName)
         TV_InsertItem(hTreeView, hNode, "DispID = " & FORMAT$(@pVarDesc.memid) & " [&H" & HEX$(@pVarDesc.memid, 8) & "]")
         IF @pVarDesc.wVarFlags THEN TV_InsertItem(hTreeView, hNode, "Attributes = " & FORMAT$(@pVarDesc.wVarFlags) & " [&H" & HEX$(@pVarDesc.wVarFlags, 8) & "]" & TLB_VarFlagsToStr(@pVarDesc.wVarFlags))
         IF @pVarDesc.elemdescVar.tdesc.vt = %VT_CARRAY THEN
            lpadesc = @pVarDesc.elemdescVar.tdesc.lpadesc
            hChildNode = TV_InsertItem(hTreeView, hNode, "Dimensions = " & FORMAT$(@lpadesc.cDims))
            TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
            FOR x = 0 TO @lpadesc.cDims - 1
               TV_InsertItem(hTreeView, hChildNode, "Dimension " & FORMAT$(x + 1) & " lower bound = " & FORMAT$(@lpadesc.rgbounds(x).lLBound))
               TV_InsertItem(hTreeView, hChildNode, "Dimension " & FORMAT$(x + 1) & " elements = " & FORMAT$(@lpadesc.rgbounds(x).cElements))
               TreeView_Expand(hTreeView, hChildNode, %TVE_EXPAND)
            NEXT
         END IF
         TV_InsertItem(hTreeView, hNode, "Indirection level = " & FORMAT$(tvd.wIndirectionLevel))
         IF LEN(tvd.szVtPtr) THEN
            TV_InsertItem(hTreeView, hNode, "VarType = " & tvd.szVtPtr)
            TV_InsertItem(hTreeView, hNode, "Resolved VarType = " & tvd.szText)
         ELSE
            TV_InsertItem(hTreeView, hNode, "VarType = " & tvd.szText)
         END IF
         IF bIsRecord THEN TV_InsertItem(hTreeView, hNode, "PB syntax = " & tvd.szPBSyntax)
         TreeView_Expand(hTreeView, hNode, %TVE_EXPAND)
      ELSE
         ' Generates a line of code formatted according the PB syntax
         strLine = "   " & tvd.szPBSyntax
         strLine = strLine & AfxSpaces(55 - LEN(strLine)) & " ' " & tvd.szText
         TLB_AddLine(strLine)
      END IF
      ' ----------------------------------------------------------------------------------

      ' --- Releases the VarDesc structure -----------------------------------------------
      pITypeInfo.ReleaseVarDesc(pVarDesc)
      pVarDesc = %NULL

   NEXT

   ' --- Releases the VarDesc structure in the case of an early exit ---------------------
   IF pVarDesc THEN
      pITypeInfo.ReleaseVarDesc(pVarDesc)
   END IF

   ' --- Expands the root node -----------------------------------------------------------
   IF bViewOnly THEN TreeView_Expand(hTreeView, hRoot, %TVE_EXPAND)

END SUB
' ========================================================================================

' ========================================================================================
' TLB_EnumConstants helper procedure
' Retrieves the names and values of the constants.
' ========================================================================================
SUB TLB_EnumConstants ( _
   BYVAL hWnd           AS DWORD _
 , BYVAL pITypeInfo     AS ITypeInfo _
 , BYVAL cVars          AS LONG _
 , BYVAL hRoot          AS DWORD _
 , BYVAL strEnumName    AS STRING _
 , BYVAL strAlias       AS STRING _
 , BYVAL bViewOnly      AS LONG _
   )

   LOCAL hr             AS LONG                 ' // HRESULT
   LOCAL hPageCtrl      AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hTreeView      AS DWORD                ' // TreeView handle
   LOCAL pVarDesc       AS VARDESC PTR          ' // Pointer to a VARDESC structure
   LOCAL hNode          AS DWORD                ' // Node name
   LOCAL bstrName       AS WSTRING              ' // Member's name (unicode)
   LOCAL szName         AS ASCIIZ * 256         ' // Name
   LOCAL szValue        AS ASCIIZ * 256         ' // Value
   LOCAL strValue       AS STRING               ' // Value
   LOCAL strEnumPrefix  AS STRING               ' // Enum prefix
   LOCAL strText        AS STRING               ' // General purpose variable
   LOCAL bstrLen        AS LONG                 ' // Length of the unicode string
   LOCAL wstrLen        AS LONG                 ' // Length of the widestring string
   LOCAL strType        AS STRING               ' // Constant type
   LOCAL vtPtr          AS tagVARIANT PTR       ' // Pointer to a tagVARIANT structure
   LOCAL x              AS LONG                 ' // Loop counter

   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF bViewOnly = %TRUE AND hTreeView = %NULL THEN EXIT SUB

   ' // Use ENUM/END ENUM
   IF ISFALSE bViewOnly THEN
      IF LEN(strAlias) THEN strEnumName = strAlias
      DO
         IF LEFT$(strEnumName, 1) <> "_" THEN EXIT DO
         strEnumName = MID$(strEnumName, 2)
      LOOP
      IF m_UseEnumPrefix = %BST_CHECKED THEN
         TLB_AddLine("ENUM " & strEnumName)
      ELSE
         TLB_AddLine("ENUM " & strEnumName & " SINGULAR")
      END IF
   END IF

   FOR x = 0 TO cVars - 1
      szName = ""
      strType = ""
      szValue = ""
      ' Gets a reference to the VARDESC structure
      hr = pITypeInfo.GetVarDesc(x, pVarDesc)
      IF hr <> %S_OK OR pVarDesc = %NULL THEN EXIT FOR
      ' Retrieves the name of the constant
      pITypeInfo.GetDocumentation(@pVarDesc.memid, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
      szName = bstrName
      IF LEN(szName) THEN
         IF ISFALSE bViewOnly THEN
            ' Adds a prefix to the constants
'            IF m_UseEnumPrefix = %BST_CHECKED THEN
'               ' Uses the name of the enumeration as prefix
'               strEnumPrefix = strEnumName
'               IF LEN(strAlias) THEN strEnumPrefix = strAlias
'               DO
'                  IF LEFT$(strEnumPrefix, 1) <> "_" THEN EXIT DO
'                  strEnumPrefix = MID$(strEnumPrefix, 2)
'               LOOP
'               szName = strEnumPrefix & "_" & bstrName
'            END IF
            ' Some components use spaces in the names of enumeration members!
            REPLACE " " WITH "_" IN szName
         END IF
      END IF
      ' Pointer to the variant that stores the value of the constant
      vtPtr = @pVarDesc.lpvarvalue
      ' Gets the value of the constant
      SELECT CASE @pVarDesc.elemdescVar.tdesc.vt
         CASE %VT_BSTR
            bstrLen = SysStringByteLen(BYVAL @vtPtr.bstrVal)
            IF bstrLen THEN
               szValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, bstrLen)) & $DQ
            ELSE
               szValue = $DQ & $DQ
            END IF
            strValue = szValue
            strText = "$" & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_LPWSTR, %VT_LPSTR
            ' Note: bstrVal is used because the correct name, pwszVal,
            ' isn't defined in the variant structure
            wstrlen = lstrlenW(BYVAL @vtPtr.bstrVal)
            IF wstrlen THEN
               szValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, wstrlen * 2)) & $DQ
            ELSE
               szValue = $DQ & $DQ
            END IF
            IF @pVarDesc.elemdescVar.tdesc.vt = %VT_LPWSTR THEN
               strValue = szValue & "$$"
               strText = "$$" & szName
            ELSE
               strValue = szValue
               strText = "$" & szName
            END IF
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_I1, %VT_UI1
            IF m_UseHexNumbers THEN
               szValue = HEX$(@vtPtr.bVal, 8) & " [" & FORMAT$(@vtPtr.bVal) & "]"
               strValue = "&H" & HEX$(@vtPtr.bVal, 8)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' " & FORMAT$(@vtPtr.bVal)
            ELSE
               szValue = FORMAT$(@vtPtr.bVal) & " [&H" & HEX$(@vtPtr.bVal, 8) & "]"
               strValue = FORMAT$(@vtPtr.bVal)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' &H" & HEX$(@vtPtr.bVal, 8)
            END IF
            'strText = "%" & szName
            strText = "   " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_BOOL
            IF m_UseHexNumbers THEN
               szValue = HEX$(@vtPtr.boolVal, 8) & " [" & FORMAT$(@vtPtr.boolVal) & "]"
               strValue = "&H" & HEX$(@vtPtr.boolVal, 8)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' " & FORMAT$(@vtPtr.boolVal)
            ELSE
               szValue = FORMAT$(@vtPtr.boolVal) & " [&H" & HEX$(@vtPtr.boolVal, 8) & "]"
               strValue = FORMAT$(@vtPtr.boolVal)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' &H" & HEX$(@vtPtr.boolVal, 8)
            END IF
            'strText = "%" & szName
            strText = "   " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_I2
            IF m_UseHexNumbers THEN
               szValue = HEX$(@vtPtr.iVal, 8) & " [" & FORMAT$(@vtPtr.iVal) & "]"
               strValue = "&H" & HEX$(@vtPtr.iVal, 8)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' " & FORMAT$(@vtPtr.iVal)
            ELSE
               szValue = FORMAT$(@vtPtr.iVal) & " [&H" & HEX$(@vtPtr.iVal, 8) & "]"
               strValue = FORMAT$(@vtPtr.iVal)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' &H" & HEX$(@vtPtr.iVal, 8)
            END IF
            'strText = "%" & szName
            strText = "   " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_INT
            IF TLB_LibDoc.syskind = %SYS_WIN16 THEN
               IF m_UseHexNumbers THEN
                  szValue = HEX$(@vtPtr.iVal, 8) & " [" & FORMAT$(@vtPtr.iVal) & "]"
                  strValue = "&H" & HEX$(@vtPtr.iVal, 8)
                  strValue += AfxSpaces(13 - LEN(strValue)) & "' " & FORMAT$(@vtPtr.iVal)
               ELSE
                  szValue = FORMAT$(@vtPtr.iVal) & " [&H" & HEX$(@vtPtr.iVal, 8) & "]"
                  strValue = FORMAT$(@vtPtr.iVal)
                  strValue += AfxSpaces(13 - LEN(strValue)) & "' &H" & HEX$(@vtPtr.iVal, 8)
               END IF
            ELSE
               IF m_UseHexNumbers THEN
                  szValue = HEX$(@vtPtr.lVal, 8) & " [" & FORMAT$(@vtPtr.lVal) & "]"
                  strValue = "&H" & HEX$(@vtPtr.lVal, 8)
                  strValue += AfxSpaces(13 - LEN(strValue)) & "' " & FORMAT$(@vtPtr.lVal)
               ELSE
                  szValue = FORMAT$(@vtPtr.lVal) & " [&H" & HEX$(@vtPtr.lVal, 8) & "]"
                  strValue = FORMAT$(@vtPtr.lVal)
                  strValue += AfxSpaces(13 - LEN(strValue)) & "' &H" & HEX$(@vtPtr.lVal, 8)
               END IF
            END IF
            'strText = "%" & szName
            strText = "   " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_I4, %VT_UI2, %VT_UINT
            IF m_UseHexNumbers THEN
               szValue = HEX$(@vtPtr.lVal, 8) & " [" & FORMAT$(@vtPtr.lVal) & "]"
               strValue = "&H" & HEX$(@vtPtr.lVal, 8)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' " & FORMAT$(@vtPtr.lVal)
            ELSE
               szValue = FORMAT$(@vtPtr.lVal) & " [&H" & HEX$(@vtPtr.lVal, 8) & "]"
               strValue = FORMAT$(@vtPtr.lVal)
               strValue += AfxSpaces(13 - LEN(strValue)) & "' &H" & HEX$(@vtPtr.lVal, 8)
            END IF
            'strText = "%" & szName
            strText = "   " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_R4
            szValue = FORMAT$(@vtPtr.fltVal, "0.000000E+##")
            strValue = FORMAT$(@vtPtr.fltVal, "0.000000E+##")
            strText = "MACRO " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_R8
            szValue = FORMAT$(@vtPtr.dblVal, "0.000000000000E+##")
            strValue = FORMAT$(@vtPtr.dblVal, "0.000000000000E+##")
            strText = "MACRO " & szName
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
         CASE %VT_PTR
            LOCAL ptdesc AS TYPEDESC PTR
            strType = VarTypeToStr(@pVarDesc.elemdescVar.tdesc.vt)
            ptdesc = @pVarDesc.elemdescVar.tdesc.lptdesc
            IF ptdesc THEN
               strType += "->" & VarTypeToStr(@ptdesc.vt)
               ' WORD PTR (null terminated unicode string)
               ' hxds.dll contains a module with these kind of constants.
               IF @ptdesc.vt = %VT_UI2 THEN
                  wstrlen = lstrlenW(BYVAL @vtPtr.bstrVal)
                  IF wstrlen THEN
                     szValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, wstrlen * 2)) & $DQ
                  ELSE
                     szValue = $DQ & $DQ
                  END IF
                  strValue = szValue
                  strText = "$" & szName
               END IF
            END IF
         ' Other types can be VT_CARRAY and VT_USERDEFINED, but don't have a typelib to test
      END SELECT
      IF bViewOnly THEN
         hNode = TV_InsertItem(hTreeView, hRoot, szName & " = " & szValue)
         TV_InsertItem(hTreeView, hNode, "TYPE = " & strType)
         TV_InsertItem(hTreeView, hNode, "VALUE = " & szValue)
         TV_InsertItem(hTreeView, hNode, "ID = " & FORMAT$(@pVarDesc.memid))
      ELSE
         IF LEN(strText) THEN
            strText += AfxSpaces(55 - LEN(strText)) & " = " & strValue
            IF LEFT$(szName, 1) = "_" THEN strText = "'" & strText
            TLB_AddLine(strText)
         END IF
      END IF
      ' Releases the VARDESC structure
      pITypeInfo.ReleaseVarDesc(pVarDesc)
      pVarDesc = 0
   NEXT

   IF ISFALSE bViewOnly THEN
      TLB_AddLine("END ENUM ")
   END IF

   ' Releases the VARDESC structure in the case of a premature exit
   IF pVarDesc THEN
      pITypeInfo.ReleaseVarDesc(pVarDesc)
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Retrieves information about the function.
' ========================================================================================
SUB TLB_GetFunctionInfo ( _
   BYVAL hWnd                 AS DWORD _
 , BYVAL strFuncName          AS STRING _
 , BYVAL pITypeInfo           AS ITypeInfo _
 , BYVAL pFuncDesc            AS FUNCDESC PTR _
 , BYVAL hNode                AS LONG _
 , BYVAL bShowOffset          AS LONG _
 , BYVAL nCodeType            AS LONG _
 , BYVAL bViewOnly            AS LONG _
   )

   LOCAL hr                   AS LONG           ' // Result code
   LOCAL hPageCtrl            AS DWORD          ' // Handle of the page of the Tab control
   LOCAL hTreeView            AS DWORD          ' // TreeView handle
   LOCAL strDllName           AS STRING         ' // DLL name
   LOCAL bstrDllName          AS WSTRING        ' // DLL name (unicode)
   LOCAL strEntryPoint        AS STRING         ' // Entry point
   LOCAL bstrEntryPoint       AS WSTRING        ' // Entry point (unicode)
   LOCAL wOrdinal             AS WORD           ' // Ordinal
   LOCAL strText              AS STRING         ' // General purpose variable

   IF hWnd = %NULL THEN EXIT SUB
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF bViewOnly = %TRUE AND hTreeView = %NULL THEN EXIT SUB

   IF bViewOnly THEN
      IF ISTRUE bShowOffset THEN TV_InsertItem(hTreeView, hNode, "VTable offset = " & FORMAT$(@pFuncDesc.oVft) & " [&H" & HEX$(@pFuncDesc.oVft, 8)& "]")
      TV_InsertItem(hTreeView, hNode, "DispID = " & FORMAT$(@pFuncDesc.memid) & " [&H" & HEX$(@pFuncDesc.memid, 8) & "]")
   END IF

   ' Show information about the external DLL for declarations contained in a module
   IF nCodeType = %CODEGEN_DLL THEN
      hr = pITypeInfo.GetDllEntry(@pFuncDesc.memid, @pFuncDesc.invkind, bstrDllName, bstrEntryPoint, wOrdinal)
      IF hr = %S_OK THEN
         strDllName = bstrDllName
         IF UCASE$(RIGHT$(strDllName, 4)) <> ".DLL" THEN strDllName = strDllName & ".DLL"
         strEntryPoint = bstrEntryPoint
         IF bViewOnly THEN
            IF LEN(strDllName) THEN TV_InsertItem(hTreeView, hNode, "DLL Name = " & strDllName)
            IF LEN(strEntryPoint) THEN
               TV_InsertItem(hTreeView, hNode, "Entry point = " & strEntryPoint)
            ELSE
               IF ISTRUE wOrdinal THEN TV_InsertItem(hTreeView, hNode, "Entry point = " & FORMAT$(wOrdinal))
            END IF
         ELSE
            IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_VOID THEN
               strText = "DECLARE SUB " & strFuncName
            ELSE
               strText = "DECLARE FUNCTION " & strFuncName
            END IF
            IF LEN(strDllName) THEN strText = strText & " LIB " & $DQ & strDllName & $DQ
            IF LEN(strEntryPoint) THEN
               strText += " ALIAS " & $DQ & strEntryPoint & $DQ
            ELSEIF ISTRUE wOrdinal THEN
               strText += " ALIAS " & $DQ & "#" & FORMAT$(wOrdinal) & $DQ
            END IF
            strText += " ( _"
            TLB_AddLine(strText)
         END IF
      END IF
   END IF

   IF bViewOnly THEN

      ' Kind of function
      SELECT CASE @pFuncDesc.funckind
         CASE %FUNC_VIRTUAL
            TV_InsertItem(hTreeView, hNode, "FuncKind = Virtual")
         CASE %FUNC_PUREVIRTUAL
            TV_InsertItem(hTreeView, hNode, "FuncKind = Pure virtual")
         CASE %FUNC_NONVIRTUAL
            TV_InsertItem(hTreeView, hNode, "FuncKind = Non virtual")
         CASE %FUNC_STATIC
            TV_InsertItem(hTreeView, hNode, "FuncKind = Static")
         CASE %FUNC_DISPATCH
            TV_InsertItem(hTreeView, hNode, "FuncKind = Dispatch")
      END SELECT

      ' Invoke kind
      SELECT CASE @pFuncDesc.invkind
         CASE %INVOKE_FUNC
            TV_InsertItem(hTreeView, hNode, "InvokeKind = Function")
         CASE %INVOKE_PROPERTYGET
            TV_InsertItem(hTreeView, hNode, "InvokeKind = Get property")
         CASE %INVOKE_PROPERTYPUT
            TV_InsertItem(hTreeView, hNode, "InvokeKind = Put property")
         CASE %INVOKE_PROPERTYPUTREF
            TV_InsertItem(hTreeView, hNode, "InvokeKind = PutRef property")
      END SELECT

      ' Calling convention
      SELECT CASE @pFuncDesc.callconv
         CASE %CC_FASTCALL
            TV_InsertItem(hTreeView, hNode, "Calling convention = FASTCALL")
         CASE %CC_CDECL
            TV_InsertItem(hTreeView, hNode, "Calling convention = CDECL")
         CASE %CC_MACPASCAL
            TV_InsertItem(hTreeView, hNode, "Calling convention = MACPASCAL")
         CASE %CC_STDCALL
            TV_InsertItem(hTreeView, hNode, "Calling convention = STDCALL")
         CASE %CC_FPFASTCALL
            TV_InsertItem(hTreeView, hNode, "Calling convention = FPFASTCALL")
         CASE %CC_SYSCALL
            TV_InsertItem(hTreeView, hNode, "Calling convention = SYSCALL")
         CASE %CC_MPWCDECL
            TV_InsertItem(hTreeView, hNode, "Calling convention = MPWCDECL")
         CASE %CC_MPWPASCAL
            TV_InsertItem(hTreeView, hNode, "Calling convention = MPWPASCAL")
      END SELECT

      ' More general information
      IF @pFuncDesc.cParamsOpt THEN TV_InsertItem(hTreeView, hNode, "Number of optional variant parameters = " & FORMAT$(@pFuncDesc.cParamsOpt))
      IF @pFuncDesc.cScodes THEN TV_InsertItem(hTreeView, hNode, "Count of permitted return values = " & FORMAT$(@pFuncDesc.cScodes))
      IF @pFuncDesc.wFuncFlags THEN TV_InsertItem(hTreeView, hNode, "Attributes = " & FORMAT$(@pFuncDesc.wFuncFlags)& " [&H" & HEX$(@pFuncDesc.wFuncFlags, 8) & "]" & TLB_FuncFLagsToStr(@pFuncDesc.wFuncFlags))

   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Shows information relative to the return type.
' The FUNCDESC structure contains a member called elemdescFunc that is an ELEMDESC
' stucture that contains the return type of the function. To retrieve the description of
' this type, we have to access the tdesc member of the ELEMDESC structure, that is another
' structure called TYPEDESC one of whose members is an union with a meber called hreftype.
' ========================================================================================
FUNCTION TLB_GetReturnType ( _
   BYVAL hWnd               AS DWORD _
 , BYVAL pITypeInfo         AS ITypeInfo _
 , BYVAL pFuncDesc          AS FUNCDESC PTR _
 , BYVAL hNode              AS LONG _
 , BYVAL nCodeType          AS LONG _
 , BYVAL bViewOnly          AS LONG _
   ) AS STRING

   LOCAL hr                 AS LONG           ' // HRESULT
   LOCAL hPageCtrl          AS DWORD          ' // Handle of the page of the Tab control
   LOCAL hTreeView          AS DWORD          ' // TreeView handle
   LOCAL bstrName           AS WSTRING        ' // Member's name (unicode)
   LOCAL strText            AS STRING         ' // General purpose variable
   LOCAL pRefTypeInfo       AS ITypeInfo      ' // Address to a referenced type description
   LOCAL lptdesc            AS TYPEDESC PTR   ' // Pointer to a TYPEDESC structure
   LOCAL vt                 AS WORD           ' // Variant type
   LOCAL pRetTypeAttr       AS TYPEATTR PTR   ' // Type attribute
   LOCAL strAliasName       AS STRING         ' // Alias name
   LOCAL typekind           AS LONG           ' // typekind
   LOCAL strTypeKind        AS STRING         ' // typekind
   LOCAL szAliasTypeKind    AS ASCIIZ * 256   ' // Alias typekind
   LOCAL strReturnType      AS STRING         ' // Return type
   LOCAL szGuid             AS ASCIIZ * 256   ' // Guid
   LOCAL strReturn          AS STRING         ' // Return string
   LOCAL hStatusBar         AS DWORD          ' // Handle of the status bar
   LOCAL hPrefixBox         AS DWORD          ' // Handle of the edit box
   LOCAL szText             AS ASCIIZ * 256   ' // General purpose variable
   LOCAL strPrefix          AS STRING         ' // Prefix
   LOCAL strIntName         AS STRING         ' // Interface name

   IF hWnd = %NULL THEN EXIT FUNCTION
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF bViewOnly = %TRUE AND hTreeView = %NULL THEN EXIT FUNCTION

   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
   IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
   IF hPrefixBox THEN GetWindowText(hPrefixBox, szText, SIZEOF(szText))
   TLB_PrefixStr = szText
   IF m_UsePrefix = %BST_CHECKED THEN strPrefix = TLB_PrefixStr

   IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_VOID THEN
      strTypeKind = ""
      strReturnType = ""
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt, %TRUE)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_USERDEFINED THEN
'      pITypeInfo.GetRefTypeInfo(@pFuncDesc.elemdescFunc.tdesc.hreftype, VARPTR(pRefTypeInfo))
      hr = pITypeInfo.GetRefTypeInfo(@pFuncDesc.elemdescFunc.tdesc.hreftype, pRefTypeInfo)
      IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
         hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         IF hr = %S_OK THEN strText = bstrName
         hr = pRefTypeInfo.GetTypeAttr(pRetTypeAttr)
         IF hr = %S_OK AND pRetTypeAttr <> %NULL THEN
            SELECT CASE @pRetTypeAttr.typekind
               CASE %TKIND_ENUM
                  strTypeKind = "LONG"
                  strReturnType = "LONG"
                  strText += " <enum>"
               CASE %TKIND_RECORD
                  strTypeKind = "DWORD"
                  strReturnType = strText
                  IF LEFT$(strReturnType, 1) = "_" THEN strReturnType = "tag" & strReturnType
                  strText += " <record>"
               CASE %TKIND_UNION
                  strTypeKind = "DWORD"
                  strReturnType = strText
                  IF LEFT$(strReturnType, 1) = "_" THEN strReturnType = "u" & strReturnType
                  strText += " <union>"
               CASE %TKIND_MODULE
                  strTypeKind = "DWORD"
                  strReturnType = "DWORD"
                  strText += " <module>"
               CASE %TKIND_INTERFACE
                  strTypeKind = "DWORD"
'                  strReturnType = "IUnknown"
                  strIntName = strText
                  DO
                     IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                     strIntName = MID$(strIntName, 2)
                  LOOP
                  strReturnType = strPrefix & strIntName
                  strText += " <interface>"
               CASE %TKIND_DISPATCH
                  strTypeKind = "DWORD"
'                  strReturnType = "IDispatch"
                  strIntName = strText
                  DO
                     IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                     strIntName = MID$(strIntName, 2)
                  LOOP
                  strReturnType = strPrefix & strIntName
                  strText += " <dispinterface>"
               CASE %TKIND_COCLASS
                  strTypeKind = "DWORD"
                  strReturnType = "IDispatch"
                  strIntName = strText
                  DO
                     IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                     strIntName = MID$(strIntName, 2)
                  LOOP
'                  strReturnType = strPrefix & strIntName
                  strText += " <coclass>"
               CASE %TKIND_ALIAS
                  IF @pRetTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                     strAliasName = TLB_GetAliasNameFromArray(bstrName)
                     IF LEN(strAliasName) THEN
                        strText += " <alias> " & strAliasName
                     ELSE
                        strText += " <alias> <" & VarTypeToConstant(@pRetTypeAttr.tdescalias.vt) & ">"
                     END IF
                     IF @pRetTypeAttr.tdescalias.vt = %VT_BSTR THEN
                        strTypeKind = "WSTRING"
                        strReturnType = "WSTRING"
                     ELSEIF @pRetTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                        strTypeKind = "DWORD"
                        strReturnType = "DWORD"
                     ELSEIF @pRetTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                        strTypeKind = "DWORD"
                        strReturnType = "DWORD"
                     ELSEIF @pRetTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                        strTypeKind = "VARIANT"
                        strReturnType = "VARIANT"
                     ELSE
                        strTypeKind = VarTypeToKeyword(@pRetTypeAttr.tdescalias.vt)
                        strReturnType = StrTypeKind
                     END IF
                  ELSE
                     strAliasName = TLB_GetAliasName(pRefTypeInfo, @pRetTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                     IF LEN(strAliasName) THEN
                        strText += " <alias> " & strAliasName
                        IF LEFT$(strAliasName, 1) = "_" THEN
                           IF typekind = %TKIND_RECORD THEN strAliasName = "tag" & strAliasName
                           IF typekind = %TKIND_UNION THEN strAliasName = "u" & strAliasName
                        END IF
                        IF typekind = %TKIND_ENUM OR typekind = %TKIND_MODULE THEN
                           strTypeKind = "LONG"
                           strReturnType = "LONG"
                        ELSEIF typekind = %TKIND_INTERFACE THEN
                           strTypeKind = "DWORD"
'                           strReturnType = "IUnknown"
                           strIntName = strAliasName
                           DO
                              IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                              strIntName = MID$(strIntName, 2)
                           LOOP
                           strReturnType = strPrefix & strIntName
                        ELSEIF typekind = %TKIND_DISPATCH OR typekind = %TKIND_COCLASS THEN
                           strTypeKind = "DWORD"
                           strIntName = strAliasName
                           DO
                              IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                              strIntName = MID$(strIntName, 2)
                           LOOP
                           IF typekind = %TKIND_COCLASS THEN
                              strReturnType = "IDispatch"
                           ELSE
                              strReturnType = strPrefix & strIntName
                           END IF
                        ELSEIF typekind = %TKIND_RECORD OR typekind = %TKIND_UNION THEN
                           strTypeKind = "DWORD"
                           strReturnType = strAliasName
                        ELSE
                           strTypeKind = "DWORD"
                           strReturnType = strAliasName
                        END IF
                     ELSE
                        strText = strText & " <alias> <" & VarTypeToConstant(@pRetTypeAttr.tdescalias.vt) & ">"
                        strTypeKind = "DWORD"
                        strReturnType = "DWORD"
                     END IF
                  END IF
            END SELECT
            pRefTypeInfo.ReleaseTypeAttr(pRetTypeAttr)
            pRetTypeAttr = 0
         END IF
         pRefTypeInfo = NOTHING
      END IF
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_PTR THEN
      ' // Gets a pointer to another TYPEDESC structure
      lptdesc = @pFuncDesc.elemdescFunc.tdesc.lptdesc
      DO
         ' // VarType
         vt = @lptdesc.vt
         SELECT CASE vt
            ' // If it is another pointer, loop again
            CASE %VT_PTR
               lptdesc = @lptdesc.lptdesc
            ' // If it is a userdefined type (record or enum), get the name
            ' // of the referenced type and store it
            CASE %VT_USERDEFINED
'               pITypeInfo.GetRefTypeInfo(@lptdesc.hreftype, VARPTR(pRefTypeInfo))
               hr = pITypeInfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
               IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                  hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr = %S_OK THEN
                     strText = bstrName
                     hr = pRefTypeInfo.GetTypeAttr(pRetTypeAttr)
                     IF hr = %S_OK AND pRetTypeAttr <> %NULL THEN
                        SELECT CASE @pRetTypeAttr.typekind
                           CASE %TKIND_ENUM
                              strTypeKind = "LONG"
                              strReturnType = "LONG"
                              strText += " <enum>"
                           CASE %TKIND_RECORD
                              strTypeKind = "DWORD"
                              strReturnType = strText
                              IF LEFT$(strReturnType, 1) = "_" THEN strReturnType = "tag" & strReturnType
                              strText += " <record>"
                           CASE %TKIND_UNION
                              strTypeKind = "DWORD"
                              strReturnType = strText
                              IF LEFT$(strReturnType, 1) = "_" THEN strReturnType = "u" & strReturnType
                              strText += " <union>"
                           CASE %TKIND_MODULE
                              strTypeKind = "DWORD"
                              strReturnType = "DWORD"
                              strText += " <module>"
                           CASE %TKIND_INTERFACE
                              strTypeKind = "DWORD"
'                              strReturnType = "IUnknown"
                              strIntName = strText
                              DO
                                 IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                                 strIntName = MID$(strIntName, 2)
                              LOOP
                              strReturnType = strPrefix & strIntName
                              strText += " <interface>"
                           CASE %TKIND_DISPATCH
                              strTypeKind = "DWORD"
'                              strReturnType = "IDispatch"
                              strIntName = strText
                              DO
                                 IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                                 strIntName = MID$(strIntName, 2)
                              LOOP
                              strReturnType = strPrefix & strIntName
                              strText += " <dispinterface>"
                           CASE %TKIND_COCLASS
                              strTypeKind = "DWORD"
                              strReturnType = "IDispatch"
                              strIntName = strText
                              DO
                                 IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                                 strIntName = MID$(strIntName, 2)
                              LOOP
'                              strReturnType = strPrefix & strIntName
                              strText += " <coclass>"
                           CASE %TKIND_ALIAS
                              IF @pRetTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                 strAliasName = TLB_GetAliasNameFromArray(bstrName)
                                 IF LEN(strAliasName) THEN
                                    strText += " <alias> " & strAliasName
                                 ELSE
                                    strText += " <alias> <" & VarTypeToConstant(@pRetTypeAttr.tdescalias.vt) & ">"
                                 END IF
                                 IF @pRetTypeAttr.tdescalias.vt = %VT_BSTR THEN
                                    strTypeKind = "WSTRING"
                                    strReturnType = "WSTRING"
                                 ELSEIF @pRetTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                                    strTypeKind = "DWORD"
                                    strReturnType = "DWORD"
                                 ELSEIF @pRetTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                                    strTypeKind = "DWORD"
                                    strReturnType = "DWORD"
                                 ELSEIF @pRetTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                                    strTypeKind = "VARIANT"
                                    strReturnType = "VARIANT"
                                 ELSE
                                    strTypeKind = VarTypeToKeyword(@pRetTypeAttr.tdescalias.vt)
                                    strReturnType = StrTypeKind
                                 END IF
                              ELSE
                                 strAliasName = TLB_GetAliasName(pRefTypeInfo, @pRetTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                                 IF LEN(strAliasName) THEN
                                    strText += " <alias> " & strAliasName
                                    IF LEFT$(strAliasName, 1) = "_" THEN
                                       IF typekind = %TKIND_RECORD THEN strAliasName = "tag" & strAliasName
                                       IF typekind = %TKIND_UNION THEN strAliasName = "u" & strAliasName
                                    END IF
                                    IF typekind = %TKIND_ENUM OR typekind = %TKIND_MODULE THEN
                                       strTypeKind = "LONG"
                                       strReturnType = "LONG"
                                    ELSEIF typekind = %TKIND_INTERFACE THEN
                                       strTypeKind = "DWORD"
'                                       strReturnType = "IUnknown"
                                       strIntName = strAliasName
                                       DO
                                          IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                                          strIntName = MID$(strIntName, 2)
                                       LOOP
                                       strReturnType = strPrefix & strIntName
                                    ELSEIF typekind = %TKIND_DISPATCH OR typekind = %TKIND_COCLASS THEN
                                       strTypeKind = "DWORD"
                                       strIntName = strAliasName
                                       DO
                                          IF LEFT$(strIntName, 1) <> "_" THEN EXIT DO
                                          strIntName = MID$(strIntName, 2)
                                       LOOP
                                       IF typekind = %TKIND_COCLASS THEN
                                          strReturnType = "IDispatch"
                                       ELSE
                                          strReturnType = strPrefix & strIntName
                                       END IF
                                    ELSEIF typekind = %TKIND_RECORD OR typekind = %TKIND_UNION THEN
                                       strTypeKind = "DWORD"
                                       strReturnType = strAliasName
                                    ELSE
                                       strTypeKind = "DWORD"
                                       strReturnType = strAliasName
                                    END IF
                                 ELSE
                                    strText = strText & " <alias> <" & VarTypeToConstant(@pRetTypeAttr.tdescalias.vt) & ">"
                                    strTypeKind = "DWORD"
                                    strReturnType = "DWORD"
                                 END IF
                              END IF
                        END SELECT
                        pRefTypeInfo.ReleaseTypeAttr(pRetTypeAttr)
                        pRetTypeAttr = 0
                     END IF
                  END IF
               END IF
               EXIT DO
            CASE ELSE
               strTypeKind = VarTypeToKeyword(vt)
               strReturnType = strTypeKind
               strText = VarTypeToStr(vt)
               EXIT DO
         END SELECT
      LOOP
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_BSTR THEN
      strReturnType = "STRING"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_LPWSTR THEN
      strReturnType = "DWORD"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_LPSTR THEN
      strReturnType = "DWORD"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_VARIANT THEN
      strReturnType = "VARIANT"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_CARRAY THEN
      strReturnType = "DWORD"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_UNKNOWN THEN
      strReturnType = "IUnknown"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_DISPATCH THEN
      strReturnType = "IDispatch"
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   ELSE
      strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      strReturnType = strTypeKind
      strText = VarTypeToStr(@pFuncDesc.elemdescFunc.tdesc.vt)
   END IF

   IF bViewOnly THEN
      TV_InsertItem(hTreeView, hNode, "Return type = " & strText)
      IF LEN(szGuid) THEN TV_InsertItem(hTreeView, hNode, "GUID = " & szGuid)
   END IF

   ' ------------------------------------------------------------------
   ' Change the alias names of the standard Picture and Font interfaces.
   ' ------------------------------------------------------------------
   IF UCASE$(strReturnType) = "PICTURE" THEN
      IF m_UseIntNamesWithExObj THEN
         strReturnType = "IPictureDisp"
      ELSE
         strReturnType = "IDispatch"
      END IF
   ELSEIF UCASE$(strReturnType) = "FONT" THEN
      IF m_UseIntNamesWithExObj THEN
         strReturnType = "IFontDisp"
      ELSE
         strReturnType = "IDispatch"
      END IF
   END IF
   IF UCASE$(strReturnType) = UCASE$(strPrefix) & "PICTURE" THEN
      IF m_UseIntNamesWithExObj THEN
         strReturnType = "IPictureDisp"
      ELSE
         strReturnType = "IDispatch"
      END IF
   ELSEIF UCASE$(strReturnType) = UCASE$(strPrefix) & "FONT" THEN
      IF m_UseIntNamesWithExObj THEN
         strReturnType = "IFontDisp"
      ELSE
         strReturnType = "IDispatch"
      END IF
   END IF
   ' ------------------------------------------------------------------

   IF nCodeType = %CODEGEN_DLL THEN
      ' We can't return a variant in PB, so return a DWORD
      IF strTypeKind = "VARIANT" THEN strTypeKind = "DWORD"
      IF LEN(strTypeKind) THEN strTypeKind = " AS " & strTypeKind
      strReturn = strTypeKind & AfxSpaces(54 - LEN(strTypeKind))
   ELSEIF nCodeType = %CODEGEN_VBSTYLE THEN
      IF LEN(strReturnType) THEN strReturnType = " AS " & strReturnType
      strReturn = strReturnType & AfxSpaces(52 - LEN(strReturnType))
   ELSE
      IF LEN(strReturnType) THEN strReturnType = " AS " & strReturnType
      strReturn = strReturnType & AfxSpaces(52 - LEN(strReturnType))
   END IF

   ' Workaround for buggy libraries that don't have the last parameter
   ' of GET properties flagged as [out, retval] when using the Automation view option.
   IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET AND strReturnType = "" THEN
      strReturn = " AS LONG" & SPACE$(44)
      strText = "VT_HRESULT <Long>"
   END IF

   strReturn += "' " & strText
   FUNCTION = strReturn

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the parameters.
' ========================================================================================
FUNCTION TLB_GetParametersInfo ( _
   BYVAL hWnd AS DWORD _
 , BYVAL pITypeInfo AS ITypeInfo _
 , BYVAL pFuncDesc AS FUNCDESC PTR _
 , BYVAL strFuncName AS STRING _
 , BYVAL hNode AS LONG _
 , BYVAL nCodeType AS LONG _
 , BYVAL bViewOnly AS LONG _
 , BYVAL VBView AS LONG _
 , BYVAL strReturn AS STRING _
 , BYVAL bIsUnknown AS LONG _
   ) AS STRING

   LOCAL tpd                  AS TLB_PARAMDESC_STRUCT
   LOCAL hr                   AS LONG            ' // HRESULT
   LOCAL hPageCtrl            AS DWORD           ' // Handle of the page of the Tab control
   LOCAL hTreeView            AS DWORD           ' // TreeView handle
   LOCAL hChildNode           AS DWORD           ' // Child node
   LOCAL cParams              AS LONG            ' // Number of parameters
   LOCAL pcNames              AS DWORD           ' // Number of names returned by GetNames
   LOCAL pParam               AS ELEMDESC PTR    ' // Pointer to an array of parameters
   LOCAL x                    AS LONG            ' // Loop counter
   LOCAL z                    AS LONG            ' // Loop counter
   LOCAL bstrName             AS WSTRING         ' // Member's name (unicode)
   LOCAL pRefTypeInfo         AS ITypeInfo       ' // Pointer to a referenced type description
   LOCAL pTypeAttr            AS TYPEATTR PTR    ' // Type attribute for the parameter
   LOCAL lptdesc              AS TYPEDESC PTR    ' // Pointer to a TYPEDESC structure
   LOCAL pex                  AS PARAMDESCEX PTR ' // Pointer to a PARAMDESCEX structure
   LOCAL bstrLen              AS LONG            ' // Length of the unicode string
   LOCAL wFlags               AS WORD            ' // Parameter flags
   LOCAL lLBound              AS WORD            ' // Array lower bound
   LOCAL cDims                AS WORD            ' // Number of dimensions of the array
   LOCAL cElements            AS LONG            ' // Elements of the array
   LOCAL lpadesc              AS ARRAYDESC PTR   ' // Pointer to an ARRAYDESC structure
   LOCAL szArrayType          AS ASCIIZ * 255    ' // Array type
   LOCAL strTypeLibGuid       AS STRING          ' // TypeLib guid
   LOCAL strTypeLibVersion    AS STRING          ' // TypeLib version
   LOCAL wTypeLibVerMajor     AS WORD            ' // Major version
   LOCAL wTypeLibVerMinor     AS WORD            ' // Minor version
   LOCAL strTypeLibPath       AS STRING          ' // TypeLib path
   LOCAL strFlags             AS STRING          ' // Flags
   LOCAL strVarName           AS STRING          ' // Variable name
   LOCAL strText              AS STRING          ' // General purpose variable
   LOCAL strAlias             AS STRING          ' // Alias name
   LOCAL strRetVal            AS STRING          ' // Return value
   LOCAL hStatusBar           AS DWORD           ' // Handle of the status bar
   LOCAL hPrefixBox           AS DWORD           ' // Handle of the edit box
   LOCAL szText               AS ASCIIZ * 256    ' // General purpose variable
   LOCAL strPrefix            AS STRING          ' // Prefix
   LOCAL idx                  AS LONG            ' // General purpose variable

   IF hWnd = %NULL THEN EXIT FUNCTION
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF bViewOnly = %TRUE AND hTreeView = %NULL THEN EXIT FUNCTION

   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
   IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
   IF hPrefixBox THEN GetWindowText(hPrefixBox, szText, SIZEOF(szText))
   TLB_PrefixStr = szText
   IF m_UsePrefix = %BST_CHECKED THEN strPrefix = TLB_PrefixStr

   ' Number of parameters
   cParams = @pFuncDesc.cParams
   IF cParams = 0 AND nCodeType <> %CODEGEN_CSTYLE THEN
      strRetVal = SPACE$(51) & " ' void"
      FUNCTION = strRetVal
      EXIT FUNCTION
   END IF

   ' ----------------------------------------------------------------------------------
   ' Gets the name of all the parameters.
   ' The first one is the name of the function.
   ' If the member ID identifies a property that is implemented with property functions,
   ' the property name is returned. For property get functions, the names of the function
   ' and its parameters are always returned.
   ' For property put and put reference functions, the right side of the assignment is
   ' unnamed. If cMaxNames is less than is required to return all of the names of the
   ' parameters of a function, then only the names of the first cMaxNames-1 parameters
   ' are returned. The names of the parameters are returned in the array in the same
   ' order that they appear elsewhere in the interface (for example, the same order in
   ' the parameter array associated with the FUNCDESC enumeration).
   ' ----------------------------------------------------------------------------------
   REDIM rgbstrNames(cParams) AS WSTRING
   hr = pITypeInfo.GetNames(@pFuncDesc.memid, rgbstrNames(0), cParams + 1, pcNames)
   IF hr <> %S_OK THEN EXIT FUNCTION
   ' ----------------------------------------------------------------------------------

   ' ----------------------------------------------------------------------------------
   ' Pointer to an ELEMDESC structure
   ' ----------------------------------------------------------------------------------
   pParam = @pFuncDesc.lprgelemdescParam
   ' ----------------------------------------------------------------------------------

   ' ==================================================================================
   ' Retrieves information about all the parameters
   ' ==================================================================================
   FOR x = 0 TO cParams - 1

      RESET tpd
      strTypeLibGuid = ""
      strTypeLibVersion = ""
      wTypeLibVerMajor = 0
      wTypeLibVerMinor = 0
      strTypeLibPath = ""

      ' -------------------------------------------------------------------------------
      ' Parameter name
      ' -------------------------------------------------------------------------------
      tpd.szOrigName = rgbstrNames(x + 1)
      tpd.szName = tpd.szOrigName
      IF tpd.szOrigName = "" THEN tpd.szOrigName = "prm" & FORMAT$(x + 1)
      IF tpd.szName = "" THEN tpd.szName = "[Unnamed]"
      IF (@pFuncDesc.invkind = %INVOKE_PROPERTYPUT OR _
         @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF) AND _
         x = cParams - 1 AND nCodeType <> %CODEGEN_CSTYLE THEN
         IF bViewOnly THEN
            IF tpd.szName = "[Unnamed]" THEN tpd.szName = "[Assignment value]"
         ELSE
            IF tpd.szName = "[Unnamed]" THEN tpd.szName = "[pVal]"
         END IF
      ELSEIF x = cParams - 1 THEN
         IF tpd.szName = "[Unnamed]" THEN tpd.szName = "[pRetVal]"
      END IF
      tpd.vt = @pParam[x].tdesc.vt
      IF bViewOnly THEN hChildNode = TV_InsertItem(hTreeView, hNode, tpd.szName)
      ' -------------------------------------------------------------------------------

      ' -------------------------------------------------------------------------------
      ' Attributes
      ' -------------------------------------------------------------------------------
      wFlags = @pParam[x].paramdesc.wParamFlags
      strText = TLB_ParamflagsToStr(wFlags)
      IF bViewOnly THEN TV_InsertItem(hTreeView, hChildNode, "Attributes = " & FORMAT$(wFlags) & " [&H" & HEX$(wFlags, 8) & "] " & strText)
      ' -------------------------------------------------------------------------------

      ' -------------------------------------------------------------------------------
      ' Some typelibs, such TLBINF32.DLL, have exported functions with parameters flaged as
      ' PARAMFLAG_FRETVAL. Remove it.
      ' -------------------------------------------------------------------------------
      IF ((wFlags AND %PARAMFLAG_FRETVAL) = %PARAMFLAG_FRETVAL) AND nCodeType = %CODEGEN_DLL THEN
         wFlags = wFlags AND NOT %PARAMFLAG_FRETVAL
      END IF

      ' -------------------------------------------------------------------------------
      ' Resolve the type of the parameter
      ' -------------------------------------------------------------------------------
      IF tpd.vt = %VT_VOID THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPBSyntax = "DWORD"
      ELSEIF tpd.vt = %VT_USERDEFINED THEN
         hr = pITypeInfo.GetRefTypeInfo(@pParam[x].tdesc.hreftype, pRefTypeInfo)
         IF hr = %S_OK OR ISTRUE ISOBJECT(pRefTypeInfo) THEN
            hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr <> %S_OK THEN EXIT FOR
            tpd.szText = bstrName
            hr = pRefTypeInfo.GetTypeAttr(pTypeAttr)
            IF hr <> %S_OK OR pTypeAttr = %NULL THEN EXIT FOR
            tpd.typekind = @pTypeAttr.typekind
            SELECT CASE @pTypeAttr.typekind
               CASE %TKIND_ENUM
                  tpd.szText += " <enum>"
                  tpd.szPBSyntax = "LONG"
               CASE %TKIND_RECORD
                  tpd.szText += " <record>"
                  IF LEFT$(bstrName, 1) = "_" THEN
                     tpd.szPBSyntax = "tag" & bstrName
                  ELSE
                     tpd.szPBSyntax = bstrName
                  END IF
               CASE %TKIND_UNION
                  tpd.szText = tpd.szText & " <union>"
                  IF LEFT$(bstrName, 1) = "_" THEN
                     tpd.szPBSyntax = "u" & bstrName
                  ELSE
                     tpd.szPBSyntax = bstrName
                  END IF
               CASE %TKIND_MODULE
                  tpd.szText += " <module>"
                  tpd.szPBSyntax = "DWORD"
               CASE %TKIND_INTERFACE
                  idx = 0
                  ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                  tpd.szIntName = tpd.szText
                  DO
                     IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                     tpd.szIntName = MID$(tpd.szIntName, 2)
                  LOOP
                  IF idx THEN
                     tpd.szIntName = strPrefix & tpd.szIntName
                  ELSE
                     IF m_UseIntNamesWithExObj THEN
                        tpd.szIntName = strPrefix & tpd.szIntName
                     ELSE
                        tpd.szIntName = "IUnknown"   ' external interface
                     END IF
                  END IF
                  tpd.szText = tpd.szText & " <interface>"
'                  tpd.szPBSyntax = "IUnknown"
                  tpd.szPBSyntax = tpd.szIntName
                  tpd.szGuid = GUIDTXT$(@pTypeAttr.guid)
                  hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
               CASE %TKIND_DISPATCH
                  idx = 0
                  ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                  tpd.szIntName = tpd.szText
                  DO
                     IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                     tpd.szIntName = MID$(tpd.szIntName, 2)
                  LOOP
                  IF idx THEN
                     tpd.szIntName = strPrefix & tpd.szIntName
                  ELSE
                     IF m_UseIntNamesWithExObj THEN
                        tpd.szIntName = strPrefix & tpd.szIntName
                     ELSE
                        tpd.szIntName = "IDispatch"   ' external interface
                     END IF
                  END IF
                  tpd.szText = tpd.szText & " <dispinterface>"
'                  tpd.szPBSyntax = "IDispatch"
                  tpd.szPBSyntax = tpd.szIntName
                  tpd.szGuid = GUIDTXT$(@pTypeAttr.guid)
                  hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
               CASE %TKIND_COCLASS
                  idx = 0
                  ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                  tpd.szIntName = tpd.szText
                  DO
                     IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                     tpd.szIntName = MID$(tpd.szIntName, 2)
                  LOOP
                  IF idx THEN
                     tpd.szIntName = strPrefix & tpd.szIntName
                  ELSE
                     IF m_UseIntNamesWithExObj THEN
                        tpd.szIntName = strPrefix & tpd.szIntName
                     ELSE
                        tpd.szIntName = "IDispatch"   ' external interface
                     END IF
                  END IF
                  tpd.szText = tpd.szText & " <coclass>"
'                  tpd.szPBSyntax = tpd.szIntName
                  tpd.szPBSyntax = "IDispatch"
                  tpd.szGuid = GUIDTXT$(@pTypeAttr.guid)
                  hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
               CASE %TKIND_ALIAS
                  IF @pTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                     tpd.szAliasName = TLB_GetAliasNameFromArray(bstrName)
                     IF LEN(tpd.szAliasName) THEN
                        tpd.szText += " <alias> " & tpd.szAliasName
                     ELSE
                        tpd.szText += " <alias> <" & VarTypeToConstant(@pTypeAttr.tdescalias.vt) & ">"
                     END IF
                     IF @pTypeAttr.tdescalias.vt = %VT_BSTR THEN
                        tpd.szPBSyntax = "WSTRING"
                     ELSEIF @pTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                        tpd.szPBSyntax = "WSTRINGZ"
                     ELSEIF @pTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                        tpd.szPBSyntax = "ASCIIZ"
                     ELSEIF @pTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                        tpd.szPBSyntax = "VARIANT"
                     ELSE
                        tpd.szPBSyntax = VarTypeToKeyword(@pTypeAttr.tdescalias.vt)
                     END IF
                  ELSE
                     tpd.szAliasName = TLB_GetAliasName(pRefTypeInfo, @pTypeAttr.tdescalias.hreftype, tpd.szTypeKind, tpd.typekind, tpd.szGuid)
                     IF LEN(tpd.szAliasName) THEN
                        tpd.szText += " <alias> " & tpd.szAliasName
                        IF tpd.typekind = %TKIND_RECORD THEN
                           tpd.szText += " <record>"
                           tpd.szPBSyntax = bstrName
                           IF LEFT$(tpd.szPBSyntax, 1) = "_" THEN tpd.szPBSyntax = "tag" & tpd.szPBSyntax
                        ELSEIF tpd.typekind = %TKIND_UNION THEN
                           tpd.szText += " <union>"
                           tpd.szPBSyntax = bstrName
                           IF LEFT$(tpd.szPBSyntax, 1) = "_" THEN tpd.szPBSyntax = "u" & tpd.szPBSyntax
                        ELSEIF tpd.typekind = %TKIND_ENUM OR tpd.typekind = %TKIND_MODULE THEN
                           tpd.szPBSyntax = "LONG"
                        ELSEIF tpd.typekind = %TKIND_INTERFACE THEN
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = tpd.szAliasName, TO idx
                           tpd.szIntName = tpd.szAliasName
                           DO
                              IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                              tpd.szIntName = MID$(tpd.szIntName, 2)
                           LOOP
                           IF idx THEN
                              tpd.szIntName = strPrefix & tpd.szIntName
                           ELSE
                              IF m_UseIntNamesWithExObj THEN
                                 tpd.szIntName = strPrefix & tpd.szIntName
                              ELSE
                                 tpd.szIntName = "IUnknown"   ' external interface
                              END IF
                           END IF
'                           tpd.szPBSyntax = "IUnknown"
                           tpd.szPBSyntax = tpd.szIntName
                           hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                        ELSEIF tpd.typekind = %TKIND_DISPATCH OR tpd.typekind = %TKIND_COCLASS THEN
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = tpd.szAliasName, TO idx
                           tpd.szIntName = tpd.szAliasName
                           DO
                              IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                              tpd.szIntName = MID$(tpd.szIntName, 2)
                           LOOP
                           IF idx THEN
                              tpd.szIntName = strPrefix & tpd.szIntName
                           ELSE
                              IF m_UseIntNamesWithExObj THEN
                                 tpd.szIntName = strPrefix & tpd.szIntName
                              ELSE
                                 tpd.szIntName = "IDispatch"   ' external interface
                              END IF
                           END IF
                           IF tpd.typekind = %TKIND_COCLASS THEN
                              tpd.szPBSyntax = "IDispatch"
                           ELSE
                              tpd.szPBSyntax = tpd.szIntName
                           END IF
                           hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                        ELSE
                           tpd.szPBSyntax = bstrName
                        END IF
                     ELSE
                        tpd.szText += " <alias> <" & VarTypeToConstant(@pTypeAttr.tdescalias.vt) & ">"
                        IF tpd.typekind = %TKIND_ENUM OR tpd.typekind = %TKIND_MODULE THEN
                           tpd.szPBSyntax = "LONG"
                        ELSEIF tpd.typekind = %TKIND_INTERFACE THEN
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                           tpd.szIntName = tpd.szText
                           DO
                              IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                              tpd.szIntName = MID$(tpd.szIntName, 2)
                           LOOP
                           IF idx THEN
                              tpd.szIntName = strPrefix & tpd.szIntName
                           ELSE
                              IF m_UseIntNamesWithExObj THEN
                                 tpd.szIntName = strPrefix & tpd.szIntName
                              ELSE
                                 tpd.szIntName = "IUnknown"   ' external interface
                              END IF
                           END IF
'                           tpd.szPBSyntax = "IUnknown"
                           tpd.szPBSyntax = tpd.szIntName
                        ELSEIF tpd.typekind = %TKIND_DISPATCH OR tpd.typekind = %TKIND_COCLASS THEN
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                           tpd.szIntName = tpd.szText
                           DO
                              IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                              tpd.szIntName = MID$(tpd.szIntName, 2)
                           LOOP
                           IF idx THEN
                              tpd.szIntName = strPrefix & tpd.szIntName
                           ELSE
                              IF m_UseIntNamesWithExObj THEN
                                 tpd.szIntName = strPrefix & tpd.szIntName
                              ELSE
                                 tpd.szIntName = "IDispatch"   ' external interface
                              END IF
                           END IF
                           IF tpd.typekind = %TKIND_COCLASS THEN
                              tpd.szPBSyntax = "IDispatch"
                           ELSE
                              tpd.szPBSyntax = tpd.szIntName
                           END IF
                        ELSE
                           tpd.szPBSyntax = "DWORD"
                        END IF
                     END IF
                  END IF
            END SELECT
            pRefTypeInfo.ReleaseTypeAttr(pTypeAttr)
            pTypeAttr = 0
            pRefTypeInfo = NOTHING
         ELSE
            tpd.szPBSyntax = "DWORD"
            tpd.szText = tpd.szText & "<GetRefTypeInfo failed - Error = &H" & HEX$(hr, 8) & ">"
         END IF
      ELSEIF tpd.vt = %VT_PTR THEN
         tpd.vtOld = tpd.vt
         tpd.szVtPtr = "VT_PTR"
         tpd.wIndirectionLevel = 1
         ' // Gets a pointer to another TYPEDESC structure
         lptdesc = @pParam[x].tdesc.lptdesc
         DO
            ' // VarType
            tpd.vt = @lptdesc.vt
            SELECT CASE tpd.vt
               ' // If it is another pointer, loop again
               CASE %VT_PTR
                  tpd.szVtPtr = tpd.szVtPtr & "->VT_PTR"
                  INCR tpd.wIndirectionLevel
                  lptdesc = @lptdesc.lptdesc
               ' // If it is a userdefined type (record or enum), get the name
               ' // of the referenced type and store it
               CASE %VT_USERDEFINED
                  tpd.vtOld = tpd.vt
                  tpd.szVtPtr = tpd.szVtPtr & "->VT_USERDEFINED"
                  hr = pITypeInfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
                  IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                     hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                     IF hr = %S_OK THEN
                        tpd.szText = bstrName
                        hr = pRefTypeInfo.GetTypeAttr(pTypeAttr)
                        IF hr = %S_OK AND pTypeAttr <> %NULL THEN
                           tpd.typekind = @pTypeAttr.typekind
                           SELECT CASE @pTypeAttr.typekind
                              CASE %TKIND_ENUM
                                 tpd.szText += " <enum>"
                                 tpd.szPBSyntax = "LONG"
                              CASE %TKIND_RECORD
                                 IF LEFT$(tpd.szText, 1) = "_" THEN
                                    tpd.szPBSyntax = "tag" & tpd.szText
                                 ELSE
                                    tpd.szPBSyntax = tpd.szText
                                 END IF
                                 tpd.szText += " <record>"
                              CASE %TKIND_UNION
                                 IF LEFT$(tpd.szText, 1) = "_" THEN
                                    tpd.szPBSyntax = "u" & tpd.szText
                                 ELSE
                                    tpd.szPBSyntax = tpd.szText
                                 END IF
                                 tpd.szText += " <union>"
                              CASE %TKIND_MODULE
                                 tpd.szText += " <module>"
                                 tpd.szPBSyntax = "DWORD"
                              CASE %TKIND_INTERFACE
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                                 tpd.szIntName = tpd.szText
                                 DO
                                    IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                    tpd.szIntName = MID$(tpd.szIntName, 2)
                                 LOOP
                                 IF idx THEN
                                    tpd.szIntName = strPrefix & tpd.szIntName
                                 ELSE
                                    IF m_UseIntNamesWithExObj THEN
                                       tpd.szIntName = strPrefix & tpd.szIntName
                                    ELSE
                                       tpd.szIntName = "IUnknown"   ' external interface
                                    END IF
                                 END IF
                                 tpd.szText += " <interface>"
                                 tpd.szGuid = GUIDTXT$(@pTypeAttr.guid)
'                                 tpd.szPBSyntax = "IUnknown"
                                 tpd.szPBSyntax = tpd.szIntName
                                 hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                              CASE %TKIND_DISPATCH
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                                 tpd.szIntName = tpd.szText
                                 DO
                                    IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                    tpd.szIntName = MID$(tpd.szIntName, 2)
                                 LOOP
                                 IF idx THEN
                                    tpd.szIntName = strPrefix & tpd.szIntName
                                 ELSE
                                    IF m_UseIntNamesWithExObj THEN
                                       tpd.szIntName = strPrefix & tpd.szIntName
                                    ELSE
                                       tpd.szIntName = "IDispatch"   ' external interface
                                    END IF
                                 END IF
                                 tpd.szText += " <dispinterface>"
                                 tpd.szGuid = GUIDTXT$(@pTypeAttr.guid)
'                                 tpd.szPBSyntax = "IDispatch"
                                 tpd.szPBSyntax = tpd.szIntName
                                 hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                              CASE %TKIND_COCLASS
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = tpd.szText, TO idx
                                 tpd.szIntName = tpd.szText
                                 DO
                                    IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                    tpd.szIntName = MID$(tpd.szIntName, 2)
                                 LOOP
                                 IF idx THEN
                                    tpd.szIntName = strPrefix & tpd.szIntName
                                 ELSE
                                    IF m_UseIntNamesWithExObj THEN
                                       tpd.szIntName = strPrefix & tpd.szIntName
                                    ELSE
                                       tpd.szIntName = "IDispatch"   ' external interface
                                    END IF
                                 END IF
                                 tpd.szText += " <coclass>"
                                 tpd.szGuid = GUIDTXT$(@pTypeAttr.guid)
'                                 tpd.szPBSyntax = tpd.szIntName
                                 tpd.szPBSyntax = "IDispatch"
                                 hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                              CASE %TKIND_ALIAS
                                 IF @pTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                    tpd.szAliasName = TLB_GetAliasNameFromArray(bstrName)
                                    IF LEN(tpd.szAliasName) THEN
                                       tpd.szText += " <alias> " & tpd.szAliasName
                                    ELSE
                                       tpd.szText += " <alias> <" & VarTypeToConstant(@pTypeAttr.tdescalias.vt) & ">"
                                    END IF
                                    IF @pTypeAttr.tdescalias.vt = %VT_BSTR THEN
                                       tpd.szPBSyntax = "WSTRING"
                                    ELSEIF @pTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                                       tpd.szPBSyntax = "WSTRINGZ"
                                    ELSEIF @pTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                                       tpd.szPBSyntax = "ASCIIZ"
                                    ELSEIF @pTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                                       tpd.szPBSyntax = "VARIANT"
                                    ELSE
                                       tpd.szPBSyntax = VarTypeToKeyword(@pTypeAttr.tdescalias.vt)
                                    END IF
                                 ELSE
                                    tpd.szAliasName = TLB_GetAliasName(pRefTypeInfo, @pTypeAttr.tdescalias.hreftype, tpd.szTypeKind, tpd.typekind, tpd.szGuid)
                                    IF LEN(tpd.szAliasName) THEN
                                       tpd.szText += " <alias> " & tpd.szAliasName
                                       IF tpd.typekind = %TKIND_RECORD THEN
                                          tpd.szText += " <record>"
                                          tpd.szPBSyntax = bstrName
                                          IF LEFT$(tpd.szPBSyntax, 1) = "_" THEN tpd.szPBSyntax = "tag" & tpd.szPBSyntax
                                       ELSEIF tpd.typekind = %TKIND_UNION THEN
                                          tpd.szText += " <union>"
                                          tpd.szPBSyntax = bstrName
                                          IF LEFT$(tpd.szPBSyntax, 1) = "_" THEN tpd.szPBSyntax = "u" & tpd.szPBSyntax
                                       ELSEIF tpd.typekind = %TKIND_ENUM OR tpd.typekind = %TKIND_MODULE THEN
                                          tpd.szPBSyntax = "LONG"
                                       ELSEIF tpd.typekind = %TKIND_INTERFACE THEN
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = tpd.szAliasName, TO idx
                                          tpd.szIntName = tpd.szAliasName
                                          DO
                                             IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                             tpd.szIntName = MID$(tpd.szIntName, 2)
                                          LOOP
                                          IF idx THEN
                                             tpd.szIntName = strPrefix & tpd.szIntName
                                          ELSE
                                             IF m_UseIntNamesWithExObj THEN
                                                tpd.szIntName = strPrefix & tpd.szIntName
                                             ELSE
                                                tpd.szIntName = "IUnknown"   ' external interface
                                             END IF
                                          END IF
'                                          tpd.szPBSyntax = "IUnknown"
                                          tpd.szPBSyntax = tpd.szIntName
                                          hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                                       ELSEIF tpd.typekind = %TKIND_DISPATCH OR tpd.typekind = %TKIND_COCLASS THEN
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = tpd.szAliasName, TO idx
                                          tpd.szIntName = tpd.szAliasName
                                          DO
                                             IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                             tpd.szIntName = MID$(tpd.szIntName, 2)
                                          LOOP
                                          IF idx THEN
                                             tpd.szIntName = strPrefix & tpd.szIntName
                                          ELSE
                                             IF m_UseIntNamesWithExObj THEN
                                                tpd.szIntName = strPrefix & tpd.szIntName
                                             ELSE
                                                tpd.szIntName = "IDispatch"   ' external interface
                                             END IF
                                          END IF
                                          IF tpd.typekind = %TKIND_COCLASS THEN
                                             tpd.szPBSyntax = "IDispatch"
                                          ELSE
                                             tpd.szPBSyntax = tpd.szIntName
                                          END IF
                                          hr = TLB_GetTypeLibFromInterfaceIID(tpd.szGuid, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
                                       ELSE
                                          tpd.szPBSyntax = bstrName
                                       END IF
                                    ELSE
                                       tpd.szText += " <alias> <" & VarTypeToConstant(@pTypeAttr.tdescalias.vt) & ">"
                                       IF tpd.typekind = %TKIND_ENUM OR tpd.typekind = %TKIND_MODULE THEN
                                          tpd.szPBSyntax = "LONG"
                                       ELSEIF tpd.typekind = %TKIND_INTERFACE THEN
                                          tpd.szIntName = tpd.szText
                                          DO
                                             IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                             tpd.szIntName = MID$(tpd.szIntName, 2)
                                          LOOP
                                          tpd.szIntName = strPrefix & tpd.szIntName
'                                          tpd.szPBSyntax = "IUnknown"
                                          tpd.szPBSyntax = tpd.szIntName
                                       ELSEIF tpd.typekind = %TKIND_DISPATCH OR tpd.typekind = %TKIND_COCLASS THEN
                                          tpd.szIntName = tpd.szText
                                          DO
                                             IF LEFT$(tpd.szIntName, 1) <> "_" THEN EXIT DO
                                             tpd.szIntName = MID$(tpd.szIntName, 2)
                                          LOOP
                                          tpd.szIntName = strPrefix & tpd.szIntName
                                          IF tpd.typekind = %TKIND_COCLASS THEN
                                             tpd.szPBSyntax = "IDispatch"
                                          ELSE
                                             tpd.szPBSyntax = tpd.szIntName
                                          END IF
                                       ELSE
                                          tpd.szPBSyntax = "DWORD"
                                       END IF
                                    END IF
                                 END IF
                           END SELECT
                           pRefTypeInfo.ReleaseTypeAttr pTypeAttr
                           pTypeAttr = 0
                           pRefTypeInfo = NOTHING
'                           tpd.szText = STRING$(tpd.wIndirectionLevel, "*") & tpd.szText
                        END IF
                     END IF
                  ELSE
                     tpd.szPBSyntax = "DWORD"
                     tpd.szText += "<GetRefTypeInfo failed - Error = &H" & HEX$(hr, 8) & ">"
                  END IF
                  EXIT DO
               CASE ELSE
                  tpd.szVtPtr = tpd.szVtPtr & "->" & VarTypeToConstant(tpd.vt)
                  IF tpd.vt = %VT_VARIANT THEN
                     tpd.szPBSyntax = "VARIANT"
                  ELSEIF tpd.vt = %VT_LPWSTR THEN
                     tpd.szPBSyntax = "WSTRINGZ"
                  ELSEIF tpd.vt = %VT_BSTR THEN
                     tpd.szPBSyntax = "WSTRING"
                  ELSEIF tpd.vt = %VT_LPSTR THEN
                     tpd.szPBSyntax = "ASCIIZ"
                  ELSEIF tpd.vt = %VT_SAFEARRAY THEN
                     tpd.szPBSyntax = "DWORD"
                  ELSEIF tpd.vt = %VT_DECIMAL THEN
                     tpd.szPBSyntax = "DECIMAL"
                  ELSE
                     IF tpd.vtOld = %VT_PTR THEN tpd.vtIsPtr = %TRUE
                     IF tpd.vt = %VT_UNKNOWN OR tpd.vt = %VT_DISPATCH THEN tpd.vtIsObject = %TRUE
                     IF tpd.vt = %VT_UNKNOWN THEN
                        tpd.szPBSyntax = "IUnknown"
                        tpd.wIndirectionLevel += 1
                     ELSEIF tpd.vt = %VT_DISPATCH THEN
                        tpd.szPBSyntax = "IDispatch"
                        tpd.wIndirectionLevel += 1
                     ELSE
                        tpd.szPBSyntax = VarTypeToKeyword(tpd.vt)
                     END IF
                  END IF
'                  tpd.szText = STRING$(tpd.wIndirectionLevel, "*") & VarTypeToStr(tpd.vt)
                  tpd.szText = VarTypeToStr(tpd.vt)
                  EXIT DO
            END SELECT
         LOOP
      ELSEIF tpd.vt = %VT_BSTR THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPBSyntax = "WSTRING"
      ELSEIF tpd.vt = %VT_LPWSTR THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPBSyntax = "WSTRINGZ"
      ELSEIF tpd.vt = %VT_LPSTR THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPBSyntax = "ASCIIZ"
      ELSEIF tpd.vt = %VT_VARIANT THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPBSyntax = "VARIANT"
      ELSEIF tpd.vt = %VT_CARRAY THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPbSyntax = "DWORD"
      ELSEIF tpd.vt = %VT_UNKNOWN THEN
'         tpd.szText = "*" & VarTypeToStr(tpd.vt)
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPbSyntax = "IUnknown"
         tpd.wIndirectionLevel += 1
      ELSEIF tpd.vt = %VT_DISPATCH THEN
'         tpd.szText = "*" & VarTypeToStr(tpd.vt)
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPbSyntax = "IDispatch"
         tpd.wIndirectionLevel += 1
      ELSEIF tpd.vt = %VT_DECIMAL THEN
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPbSyntax = "DECIMAL"
      ELSE
         tpd.szText = VarTypeToStr(tpd.vt)
         tpd.szPBSyntax = VarTypeToKeyword(tpd.vt)
      END IF

      strFlags = ""
      IF (wFlags AND %PARAMFLAG_FOPT) = %PARAMFLAG_FOPT THEN strFlags += "[opt]"
      IF (wFlags AND %PARAMFLAG_FRETVAL) = %PARAMFLAG_FRETVAL THEN strFlags += "[retval]"
      IF (wFlags AND %PARAMFLAG_FIN) = %PARAMFLAG_FIN THEN strFlags += "[in]"
      IF (wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT THEN strFlags += "[out]"
'      IF wFlags = 0 THEN strFlags = "[" & FORMAT$(tpd.wIndirectionLevel) & "] "

      ' ------------------------------------------------------------------
      ' Change the alias names of the standard Picture and Font interfaces.
      ' ------------------------------------------------------------------
      IF UCASE$(tpd.szPBSyntax) = "PICTURE" THEN
         tpd.szPBSyntax = "IPictureDisp"
      ELSEIF UCASE$(tpd.szPBSyntax) = "FONT" THEN
         tpd.szPBSyntax = "IFontDisp"
      END IF
      IF UCASE$(tpd.szIntName) = "PICTURE" THEN
         tpd.szIntName = "IPictureDisp"
      ELSEIF UCASE$(tpd.szIntName) = "FONT" THEN
         tpd.szIntName = "IFontDisp"
      END IF
      IF UCASE$(tpd.szPBSyntax) = UCASE$(strPrefix) & "PICTURE" THEN
         tpd.szPBSyntax = "IPictureDisp"
      ELSEIF UCASE$(tpd.szPBSyntax) = UCASE$(strPrefix) & "FONT" THEN
         tpd.szPBSyntax = "IFontDisp"
      END IF
      IF UCASE$(tpd.szIntName) = UCASE$(strPrefix) & "PICTURE" THEN
         tpd.szIntName = "IPictureDisp"
      ELSEIF UCASE$(tpd.szIntName) = UCASE$(strPrefix) & "FONT" THEN
         tpd.szIntName = "IFontDisp"
      END IF

      ' ------------------------------------------------------------------
      ' Change the names of other standard alias
      ' ------------------------------------------------------------------
      IF tpd.szAliasName = "ULONG_PTR" THEN
         tpd.szPBSyntax = "DWORD"
      ELSEIF tpd.szAliasName = "LONG_PTR" THEN
         tpd.szPBSyntax = "LONG"
      END IF

      ' Return value
      IF (((wFlags AND %PARAMFLAG_FRETVAL) = %PARAMFLAG_FRETVAL) AND nCodeType <> %CODEGEN_CSTYLE) OR _
         (@pFuncDesc.invkind = %INVOKE_PROPERTYGET AND cParams = 1 AND ISFALSE VBView AND nCodeType <> %CODEGEN_CSTYLE) THEN
         IF tpd.typekind = %TKIND_COCLASS THEN
            strRetVal = " AS " & tpd.szPbSyntax
         ELSE
            IF LEN(tpd.szIntName) THEN
               strRetVal = " AS " & tpd.szIntName
            ELSE
               strRetVal = " AS " & tpd.szPbSyntax
            END IF
         END IF
         IF wFlags = 0 THEN strFlags = "[out] "
      ELSEIF (x = cParams - 1) AND (@pFuncDesc.invkind = %INVOKE_PROPERTYGET) AND _
         ((wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT) AND (ISFALSE VBView)  AND (@pFuncDesc.elemdescFunc.tdesc.vt = %VT_HRESULT) THEN
         ' Some get properties (e.g. Item property of the IQESortFields interface of crqe.dll)
         ' don't have the return parameter flagged as retval, so if the last parameter is OUT
         ' and the return type VT_HRESULT, assume that it is the return value.
         IF tpd.typekind = %TKIND_COCLASS THEN
            strRetVal = " AS " & tpd.szPbSyntax
         ELSE
            IF LEN(tpd.szIntName) THEN
               strRetVal = " AS " & tpd.szIntName
            ELSE
               strRetVal = " AS " & tpd.szPbSyntax
            END IF
         END IF
         IF wFlags = 0 THEN strFlags = "[out] "
      ELSEIF (x = cParams - 1) AND (@pFuncDesc.invkind = %INVOKE_PROPERTYGET) AND _
         ((wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT) AND (ISTRUE VBView) THEN
         IF tpd.typekind = %TKIND_COCLASS THEN
            strRetVal = " AS " & tpd.szPbSyntax
         ELSE
            IF LEN(tpd.szIntName) THEN
               strRetVal = " AS " & tpd.szIntName
            ELSE
               strRetVal = " AS " & tpd.szPbSyntax
            END IF
         END IF
         IF wFlags = 0 THEN strFlags = "[out] "
      ELSE
         ' Display the indirection level for checking purposes
'         IF ISFALSE bViewOnly THEN strFlags = "[" & FORMAT$(tpd.wIndirectionLevel) & "] " & strFlags
      END IF

      IF LEN(strFlags) THEN
         IF RIGHT$(strFlags, 1) <> " " THEN strFlags += " "
      END IF

      ' ------------------------------------------------------------------
      ' Decide if to pass the parameter by value or by reference
      ' ------------------------------------------------------------------
      LOCAL strInOut AS STRING
      strInOut = ""
      SELECT CASE tpd.vt
         CASE %VT_LPSTR, %VT_LPWSTR
            ' Null terminated strings must be always passed by reference
            strInOut = "BYREF"
'         CASE %VT_LPWSTR
            ' With null-terminated unicode strings we can't rely in the indirection level alone
            ' because it returns 0 for both IN and IN/OUT, and 1 for OUT or IN arrays.
'            IF ((wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT AND _
'               (wFlags AND %PARAMFLAG_FIN) = %PARAMFLAG_FIN) OR _
'               (wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT THEN
'               strInOut = "BYREF"
'            ELSE
'               IF tpd.wIndirectionLevel = 0 THEN strInOut = "BYVAL" ELSE strInOut = "BYREF"
'            END IF
         CASE %VT_VOID, %VT_UNKNOWN, %VT_DISPATCH
            IF tpd.wIndirectionLevel = 2 THEN strInOut = "BYREF" ELSE strInOut = "BYVAL"
         CASE %VT_USERDEFINED
            SELECT CASE tpd.typekind
               CASE %TKIND_INTERFACE, %TKIND_DISPATCH, %TKIND_COCLASS
                  IF tpd.wIndirectionLevel = 2 THEN strInOut = "BYREF" ELSE strInOut = "BYVAL"
               CASE ELSE
                  IF tpd.wIndirectionLevel = 0 THEN strInOut = "BYVAL" ELSE strInOut = "BYREF"
            END SELECT
         CASE ELSE
            IF tpd.wIndirectionLevel = 0 THEN strInOut = "BYVAL" ELSE strInOut = "BYREF"
      END SELECT
      tpd.szPBSyntax = strInOut & " " & tpd.szPBSyntax

      ' // Some typelibs for VB declare ASCIIZ strings as user defined
      IF tpd.szPBSyntax = "BYVAL ASCIIZ" THEN tpd.szPBSyntax = "BYREF ASCIIZ"

      ' ------------------------------------------------------------------
      ' Add PTR to BYVAL pointers and use BYREF DWORD for BYREF pointers
      ' since PB doesn't allow to declare BYREF ... AS ... PTR
      ' VOID pointers should be translated as BYREF ANY, but PB only
      ' allows the use of ANY with external functions, so we are using
      ' BYVAL DWORD PTR.
      ' ------------------------------------------------------------------
      IF ISTRUE tpd.vtIsPtr AND tpd.wIndirectionLEvel <> 2 THEN
         SELECT CASE tpd.szPBSyntax
'            CASE "BYVAL DWORD"   : tpd.szPbSyntax = "BYVAL DWORD PTR"
            CASE "BYVAL LONG"    : tpd.szPbSyntax = "BYVAL LONG PTR"
            CASE "BYVAL STRING"  : tpd.szPbSyntax = "BYVAL STRING PTR"
            CASE "BYVAL BYTE"    : tpd.szPbSyntax = "BYVAL BYTE PTR"
            CASE "BYVAL WORD"    : tpd.szPbSyntax = "BYVAL WORD PTR"
            CASE "BYVAL INTEGER" : tpd.szPbSyntax = "BYVAL INTEGER PTR"
            CASE "BYVAL SINGLE"  : tpd.szPbSyntax = "BYVAL SINGLE PTR"
            CASE "BYVAL DOUBLE"  : tpd.szPbSyntax = "BYVAL DOUBLE PTR"
         END SELECT
      END IF

      IF ISTRUE tpd.vtIsPtr AND tpd.wIndirectionLEvel = 2 THEN
         SELECT CASE tpd.szPBSyntax
            CASE "BYREF LONG"    : tpd.szPbSyntax = "BYREF DWORD"
            CASE "BYREF STRING"  : tpd.szPbSyntax = "BYREF DWORD"
            CASE "BYREF WORD"    : tpd.szPbSyntax = "BYREF DWORD"
            CASE "BYREF INTEGER" : tpd.szPbSyntax = "BYREF DWORD"
            CASE "BYREF SINGLE"  : tpd.szPbSyntax = "BYREF DWORD"
            CASE "BYREF DOUBLE"  : tpd.szPbSyntax = "BYREF DWORD"
            ' CASE "BYREF BYTE"    : tpd.szPbSyntax = "BYREF DWORD"
            CASE "BYREF BYTE"
               IF bIsUnknown THEN
                  tpd.szPbSyntax = "BYREF DWORD"
               ELSE
                  ' // If it is an IDispatch interface then it must be an OLESTR or an
                  ' // array of OLECHAR strings. An example is the rgszNames parameter
                  ' // of the GetIDsOfNames method of the IDispatch interface.
                  tpd.szPbSyntax = "BYREF WSTRING"
               END IF
         END SELECT
      END IF

      ' ------------------------------------------------------------------
      ' Change the alias names of the standard Picture and Font interfaces.
      ' ------------------------------------------------------------------
      IF LEN(strPrefix) = 0 THEN
         IF RIGHT$(UCASE$(tpd.szPbSyntax), 8) = " PICTURE" THEN
            tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, LEN(tpd.szPbSyntax) - 8) & " IPictureDisp"
         ELSEIF RIGHT$(UCASE$(tpd.szPbSyntax), 5) = " FONT" THEN
            tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, LEN(tpd.szPbSyntax) - 5) & " IFontDisp"
         END IF
      ELSE
         IF RIGHT$(UCASE$(tpd.szPbSyntax), 8 + LEN(strPrefix)) = UCASE$(strPrefix) & " PICTURE" THEN
            tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, LEN(tpd.szPbSyntax) - (8 + LEN(strPrefix))) & " IPictureDisp"
         ELSEIF RIGHT$(UCASE$(tpd.szPbSyntax), 5 + LEN(strPrefix)) = UCASE$(strPrefix) & " FONT" THEN
            tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, LEN(tpd.szPbSyntax) - (5 + LEN(strPrefix))) & " IFontDisp"
         END IF
      END IF

      ' ------------------------------------------------------------------
      ' Show the information
      ' ------------------------------------------------------------------
      IF bViewOnly THEN
         TV_InsertItem(hTreeView, hChildNode, "Indirection level = " & FORMAT$(tpd.wIndirectionLevel))
         szArrayType = ""
         IF tpd.vt = %VT_CARRAY THEN
            ' Search for array bounds
            cDims = 0 : cElements = 0 : lLBound = 0
            lpadesc = @pParam[x].tdesc.lpadesc
            cDims = @lpadesc.cDims
            TV_InsertItem(hTreeView, hChildNode, "Dimensions = " & FORMAT$(cDims))
            ' Lower bound and number of elements
            FOR z = 0 TO cDims - 1
               lLBound = @lpadesc.rgbounds(z).lLBound
               cElements = @lpadesc.rgbounds(z).cElements
               TV_InsertItem(hTreeView, hChildNode, "Dimension " & FORMAT$(z + 1) & " lower bound = " & FORMAT$(lLBound))
               TV_InsertItem(hTreeView, hChildNode, "Dimension " & FORMAT$(z + 1) & " elements = " & FORMAT$(cElements))
            NEXT
            IF @lpadesc.tdescElem.vt = %VT_USERDEFINED THEN
               hr = pITypeInfo.GetRefTypeInfo(@lpadesc.tdescElem.hreftype, pRefTypeInfo)
               IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                  hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr = %S_OK THEN szArrayType = bstrName
               END IF
            ELSE
               szArrayType = VarTypeToStr(@lpadesc.tdescElem.vt)
            END IF
            TV_InsertItem(hTreeView, hChildNode, "VarType = " & "<" & VarTypeToStr(@lpadesc.tdescElem.vt) & ">")
         END IF
         IF LEN(tpd.szVtPtr) THEN
            TV_InsertItem(hTreeView, hChildNode, "VarType = " & tpd.szVtPtr)
            TV_InsertItem(hTreeView, hChildNode, "Resolved VarType = " & tpd.szText)
         ELSE
            IF LEN(szArrayType) THEN
               TV_InsertItem(hTreeView, hChildNode, "VarType = " & tpd.szText & " <" & szArrayType & ">")
            ELSE
               TV_InsertItem(hTreeView, hChildNode, "VarType = " & tpd.szText)
            END IF
         END IF
         IF LEN(tpd.szGuid) THEN TV_InsertItem(hTreeView, hChildNode, "IID = " & tpd.szGuid)
         IF LEN(strTypeLibGuid) THEN TV_InsertItem(hTreeView, hChildNode, "TypeLib GUID = " & strTypeLibGuid)
         IF LEN(strTypeLibVersion) THEN TV_InsertItem(hTreeView, hChildNode, "TypeLib Version = " & strTypeLibVersion)
         IF LEN(strTypeLibPath) THEN TV_InsertItem(hTreeView, hChildNode, "TypeLib Path = " & strTypeLibPath)
         strText = tpd.szPBSyntax
         TV_InsertItem(hTreeView, hChildNode, "PBSyntax = " & strText)
         TreeView_Expand hTreeView, hChildNode, %TVE_EXPAND
      END IF
      ' -------------------------------------------------------------------------------

      ' ------------------------------------------------------------------
      ' Add the name of the parameter if required
      ' ------------------------------------------------------------------
      IF nCodeType = %CODEGEN_EVENTS THEN
         IF ISTRUE m_AddParameterNamesPrefix THEN
            IF LEFT$(UCASE$(tpd.szName), 5) <> "PARAM" AND LEFT$(UCASE$(tpd.szName), 3) <> "PRM" THEN
               tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, 6) & "prm_" & tpd.szOrigName & " AS " & MID$(tpd.szPbSyntax, 7)
            ELSE
               tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, 6) & tpd.szOrigName & " AS " & MID$(tpd.szPbSyntax, 7)
            END IF
         ELSE
            tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, 6) & tpd.szOrigName & " AS " & MID$(tpd.szPbSyntax, 7)
         END IF
      ELSEIF ISTRUE m_UseParameterNames THEN
         IF ISTRUE m_AddParameterNamesPrefix THEN
            IF LEFT$(UCASE$(tpd.szName), 5) <> "PARAM" AND LEFT$(UCASE$(tpd.szName), 3) <> "PRM" THEN
               tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, 6) & "prm_" & tpd.szOrigName & " AS " & MID$(tpd.szPbSyntax, 7)
            ELSE
               tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, 6) & tpd.szOrigName & " AS " & MID$(tpd.szPbSyntax, 7)
            END IF
         ELSE
            tpd.szPbSyntax = LEFT$(tpd.szPbSyntax, 6) & tpd.szOrigName & " AS " & MID$(tpd.szPbSyntax, 7)
         END IF
      END IF

      ' -------------------------------------------------------------------------------
      ' If using Property Get/Set syntax, add IN after BYREF so the compiler will
      ' know that it has to pass a pointer by value.
      ' -------------------------------------------------------------------------------
      IF nCodeType <> %CODEGEN_CSTYLE THEN
         IF ISTRUE m_UsePropGetSet AND @pFuncDesc.invkind <> %INVOKE_FUNC THEN
            IF LEFT$(tpd.szPbSyntax, 5) = "BYREF" THEN
               tpd.szPbSyntax = "BYREF IN" & MID$(tpd.szPbSyntax, 6)
            END IF
         END IF
      END IF

      ' -------------------------------------------------------------------------------
      ' Default value
      ' -------------------------------------------------------------------------------
      IF (@pParam[x].paramdesc.wParamFlags AND %PARAMFLAG_FHASDEFAULT) = %PARAMFLAG_FHASDEFAULT THEN
         ' // Pointer to a PARAMDESCEX structure
         pex = @pParam[x].paramdesc.pparamdescex
         ' // Vartype
         IF @pex.vardefaultvalue.vt = %VT_BSTR THEN
            ' // Get the content of the unicode string
            bstrLen = SysStringByteLen(BYVAL @pex.varDefaultValue.bstrVal)
            IF bstrLen THEN
               tpd.szDefaultValue = $DQ & ACODE$(PEEK$(@pex.varDefaultValue.bstrVal, bstrLen)) & $DQ
            ELSE
               tpd.szDefaultValue = $DQ & $DQ
            END IF
         ELSE
            ' // Get the integer value
            IF TLB_LibDoc.syskind = %SYS_WIN16 THEN
               tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.iVal)
            ELSE
               SELECT CASE @pex.vardefaultvalue.vt
                  CASE %VT_BOOL
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.boolVal)
                  CASE %VT_I2, %VT_INT
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.iVal)
                  CASE %VT_UI1, %VT_I1
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.bVal)
                  CASE %VT_R4
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.fltVal)
                  CASE %VT_R8
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.dblVal)
                  CASE %VT_CY, %VT_I8, %VT_UI8
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.cyVal)
                  CASE %VT_DATE
                     tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.date)
                  CASE ELSE
                    tpd.szDefaultValue = FORMAT$(@pex.varDefaultValue.lVal)
               END SELECT
            END IF
         END IF
      END IF
      IF LEN(tpd.szDefaultValue) THEN
         IF bViewOnly THEN
            TV_InsertItem(hTreeView, hChildNode, "Default value = " & tpd.szDefaultValue)
            TreeView_Expand hTreeView, hChildNode, %TVE_EXPAND
         END IF
      END IF
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Optional parameters
      ' ----------------------------------------------------------------------------------
      IF (wFlags AND %PARAMFLAG_FOPT) = %PARAMFLAG_FOPT THEN
         IF nCodeType <> %CODEGEN_CSTYLE THEN tpd.szPbSyntax = "OPTIONAL " & tpd.szPbSyntax
      END IF
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      strText = ""
      IF tpd.szName = "[pVal]" OR tpd.szName = "[pRetVal]" THEN tpd.szName = ""
      strVarName = tpd.szName
      IF tpd.vt = %VT_SAFEARRAY THEN tpd.wIndirectionLevel += 1
      IF LEN(strVarName) THEN strVarName = STRING$(tpd.wIndirectionLevel, "*") & strVarName & " "
'      IF ISFALSE bViewOnly AND ISTRUE m_UseParameterNames THEN strVarName = ""
      IF ISFALSE bViewOnly THEN
         IF nCodeType = %CODEGEN_CSTYLE OR nCodeType = %CODEGEN_VBSTYLE OR nCodeType = %CODEGEN_EVENTS THEN
            IF x = 0 THEN
               strText = "     " & tpd.szPbSyntax & " _"
            ELSE
               strText = "   , " & tpd.szPbSyntax & " _"
            END IF
         ELSE
            IF x = 0 THEN
               strText = "   " & tpd.szPbSyntax & " _"
            ELSE
               strText = " , " & tpd.szPbSyntax & " _"
            END IF
         END IF
'         strText += AfxSpaces(55 - LEN(strText)) & " ' " & strFlags & strVarName & "/* " & tpd.szText & " */"
         strText += AfxSpaces(55 - LEN(strText)) & " ' " & strFlags & strVarName & tpd.szText
         IF LEN(tpd.szDefaultValue) THEN strText = strText & " [default value = " & tpd.szDefaultValue & "]"

         ' --- Workaround for GET properties in buggy libraries.
         IF nCodeType = %CODEGEN_CSTYLE THEN
            TLB_AddLine(strText)
         ELSEIF (((wFlags AND %PARAMFLAG_FRETVAL) = %PARAMFLAG_FRETVAL) AND nCodeType <> %CODEGEN_CSTYLE) OR _
            (@pFuncDesc.invkind = %INVOKE_PROPERTYGET AND cParams = 1 AND ISFALSE VBView AND nCodeType <> %CODEGEN_CSTYLE) THEN
'            strRetVal += AfxSpaces(55 - LEN(strRetVal) - 4) &  " ' " & strFlags & strVarName & "/* " & tpd.szText & " */"
            strRetVal += AfxSpaces(55 - LEN(strRetVal) - 4) &  " ' " & strFlags & strVarName & tpd.szText
         ELSEIF (x = cParams - 1) AND (@pFuncDesc.invkind = %INVOKE_PROPERTYGET) AND _
            ((wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT) AND (ISFALSE VBView) AND (@pFuncDesc.elemdescFunc.tdesc.vt = %VT_HRESULT) THEN
            ' Some get properties (e.g. Item property of the IQESortFields interface of crqe.dll)
            ' don't have the return parameter flagged as retval, so if the last parameter is OUT
            ' and the return type VT_HRESULT , assume that it is the return value.
'            strRetVal += AfxSpaces(55 - LEN(strRetVal) - 4) &  " ' " & strFlags & strVarName & "/* " & tpd.szText & " */"
            strRetVal += AfxSpaces(55 - LEN(strRetVal) - 4) &  " ' " & strFlags & strVarName & tpd.szText
         ELSEIF (x = cParams - 1) AND (@pFuncDesc.invkind = %INVOKE_PROPERTYGET) AND _
            ((wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT) AND (ISTRUE VBView) THEN
'            strRetVal += AfxSpaces(55 - LEN(strRetVal) - 4) &  " ' " & strFlags & strVarName & "/* " & tpd.szText & " */"
            strRetVal += AfxSpaces(55 - LEN(strRetVal) - 4) &  " ' " & strFlags & strVarName & tpd.szText
            ' If it has a return value then it means that it is not a buggy typelib,
            ' but a GET property with a BYREF parameter.
            IF INSTR(UCASE$(strReturn), "VT_VOID") = 0 THEN TLB_AddLine(strText)
         ELSE
            TLB_AddLine(strText)
         END IF
      END IF
      ' ----------------------------------------------------------------------------------

   NEXT

   IF strRetVal = "" THEN strRetVal = SPACE$(51) & " ' void"

   FUNCTION = strRetVal

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates the functions.
' ========================================================================================
SUB TLB_EnumFunctions ( _
   BYVAL hWnd                 AS DWORD _
 , BYVAL pTypeAttr            AS TYPEATTR PTR _
 , BYVAL pITypeInfo           AS ITypeInfo _
 , BYVAL hRoot                AS DWORD _
 , BYVAL bShowOffset          AS LONG _
 , BYVAL nCodeType            AS LONG _
 , BYVAL bViewOnly            AS LONG _
 , BYVAL bIsUnknown           AS LONG _
 , BYVAL VBView               AS LONG _
 , OPTIONAL BYVAL strIntName  AS STRING _
   )

   LOCAL hr                   AS LONG           ' // HRESULT
   LOCAL hPageCtrl            AS DWORD          ' // Handle of the page of the Tab control
   LOCAL hTreeView            AS DWORD          ' // TreeView handle
   LOCAL hNode                AS DWORD          ' // Node name
   LOCAL szName               AS ASCIIZ * 255   ' // Name
   LOCAL bstrName             AS WSTRING        ' // Member's name (unicode)
   LOCAL bstrDocString        AS WSTRING        ' // Documentation string
   LOCAL szText               AS ASCIIZ * 255   ' // General purpose variable
   LOCAL pFuncDesc            AS FUNCDESC PTR   ' // Pointer to a FUNCDESC structure
   LOCAL pdwHelpContext       AS DWORD          ' // Help context
   LOCAL strReturn            AS STRING         ' // Return type
   LOCAL x                    AS LONG           ' // Loop counter
   LOCAL strImplInterface     AS STRING         ' // Implemented interface
   LOCAL strImplInterfaceIID  AS STRING         ' // Implemented interface IID
   LOCAL prevOffset           AS LONG           ' // Previous offset
   LOCAL gap                  AS LONG           ' // Gap
   LOCAL i                    AS LONG           ' // Loop counter
   LOCAL count                AS LONG           ' // Number of functions listed
   LOCAL bFirstTime           AS LONG           ' // Boolean
   LOCAL strRetVal            AS STRING         ' // Return value
   LOCAL cFuncs               AS LONG           ' // Number of functions

   IF pTypeAttr = %NULL THEN EXIT SUB
   cFuncs = @pTypeAttr.cFuncs
   IF cFuncs = 0 THEN EXIT SUB

   bFirstTime = %TRUE
   IF hWnd = %NULL THEN EXIT SUB
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF bViewOnly = %TRUE AND hTreeView = %NULL THEN EXIT SUB

   ' Retrieves the implemented interface
   strImplInterface = UCASE$(TLB_GetImplementedInterface(pITypeInfo))

   ' --- Retrieves the functions ---------------------------------------------------------
   FOR x = 0 TO cFuncs - 1
      ' Gets a reference to the FuncDesc structure
      hr = pITypeInfo.GetFuncDesc(x, pFuncDesc)
      IF hr <> %S_OK OR pFuncDesc = %NULL THEN EXIT FOR
      ' Retrieve the name of the function
      pITypeInfo.GetDocumentation(@pFuncDesc.memid, bstrName, bstrDocString, pdwHelpContext, BYVAL %NULL)
      szName = bstrName
      ' Exit if it is a dispatch only interface
      IF @pFuncdesc.oVft = 0 AND szName <> "QueryInterface" AND ISFALSE bViewOnly AND nCodeType <> %CODEGEN_DLL THEN EXIT FOR
      ' --- Deal with missing offsets ----------------------------------------------------
      IF @pFuncdesc.oVft > 0 AND prevOffset > 0 THEN
         IF @pFuncdesc.oVft <> prevOffset + 4 THEN
            gap = (@pFuncdesc.oVft \ 4) - (prevOffset \ 4) - 1
            FOR i = 1 TO gap
               TLB_AddLine("   ' =====================================================================================")
               szText = "   METHOD Missing" & FORMAT$((prevOffset + (4 * i)) \ 4) & " ()"
               szText += AfxSpaces(55 - LEN(szText)) & " ' VTable offset = " & FORMAT$(prevOffset + (4 * i))
               TLB_AddLine(BYCOPY szText)
            NEXT
         END IF
      END IF
      prevOffset = @pFuncdesc.oVft
      ' ----------------------------------------------------------------------------------
      szText = TRIM$(bstrDocString)
      IF ISFALSE bViewOnly AND strImplInterface <> "IUNKNOWN" THEN
         ' ------------------------------------------------------------------
         ' Workaround for buggy libraries that can have illegal method names.
         ' For example, TLBINF32.DLL has a property called GetTypeInfo.
         ' ------------------------------------------------------------------
         IF szName = "QueryInterface" AND @pFuncdesc.oVft > 24 THEN szName = "QueryInterface_"
         IF szName = "AddRef" AND @pFuncdesc.oVft > 24 THEN szName = "AddRef_"
         IF szName = "Release" AND @pFuncdesc.oVft > 24 THEN szName = "Release_"
         IF szName = "GetTypeInfoCount" AND @pFuncdesc.oVft > 24 THEN szName = "GetTypeInfoCount_"
         IF szName = "GetTypeInfo" AND @pFuncdesc.oVft > 24 THEN szName = "GetTypeInfo_"
         IF szName = "Invoke" AND @pFuncdesc.oVft > 24 THEN szName = "Invoke_"
         ' ------------------------------------------------------------------
         IF szName = "QueryInterface" OR _
            szName = "AddRef" OR _
            szName = "Release" OR _
            szName = "GetTypeInfoCount" OR _
            szName = "GetTypeInfo" OR _
            szName = "GetIDsOfNames" OR _
            szName = "Invoke" THEN
            pITypeInfo.ReleaseFuncDesc(pFuncDesc)
            pFuncDesc = 0
            ITERATE FOR
         END IF
      END IF
      count = count + 1
      IF bViewOnly THEN
         hNode = TV_InsertItem(hTreeView, hRoot, szName)
         IF LEN(szText) THEN TV_InsertItem(hTreeView, hNode, "Help string = " & szText)
         IF pdwHelpContext THEN TV_InsertItem(hTreeView, hNode, "Help Context = " & FORMAT$(pdwHelpContext))
      ELSE
         IF nCodeType = %CODEGEN_DLL THEN
            TLB_AddLine("' ========================================================================================")
         ELSE
            IF bFirstTime THEN
               bFirstTime = %FALSE
               IF LEN(strIntName) THEN
                  TLB_AddLine("   ' =====================================================================================")
                  TLB_AddLine("   ' " & strIntName & " Methods")
               END IF
            END IF
            TLB_AddLine("   ' =====================================================================================")
            szText = szName
            IF UCASE$(szText) = "_NEWENUM" THEN szText = MID$(szText, 2) & "_"
            DO
               IF LEFT$(szText, 1) <> "_" THEN EXIT DO
               szText = MID$(szText, 2) & "_"
            LOOP
            IF INSTR(LEFT$(szText, 1), ANY "012345689") THEN szText = "x" & szText
            IF ISTRUE m_IAutomation AND ISTRUE m_UsePropGetSet THEN   ' IAutomation interfaces
               IF @pFuncDesc.invkind = %INVOKE_FUNC THEN szText = "   METHOD " & szText & " ( _"
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN szText = "   PROPERTY GET " & szText & " ( _"
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN szText = "   PROPERTY SET " & szText & " ( _"
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN szText = "   PROPERTY SET putref_" & szText & " ( _"
            ELSEIF ((@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL AND ISTRUE m_UsePropGetSet) OR _
               (ISFALSE bIsUnknown AND ISTRUE m_UsePropGetSet) THEN
               IF @pFuncDesc.invkind = %INVOKE_FUNC THEN szText = "   METHOD " & szText & " <" & FORMAT$(@pFuncDesc.memid) & "> ( _"
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN szText = "   PROPERTY GET " & szText & " <" & FORMAT$(@pFuncDesc.memid) & "> ( _"
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN szText = "   PROPERTY SET " & szText & " <" & FORMAT$(@pFuncDesc.memid) & "> ( _"
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN szText = "   PROPERTY SET putref_" & szText & " <" & FORMAT$(@pFuncDesc.memid) & "> ( _"
            ELSE
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN szText = "get_" & szText
               IF m_UseSetPrefix THEN
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN szText = "set_" & szText
               ELSE
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN szText = "put_" & szText
               END IF
               IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN szText = "putref_" & szText
               IF UCASE$(szText) = "GET_NEWENUM_" THEN szText = MID$(szText, 5)
               szText = "   METHOD " & szText & " ( _"
            END IF
            szText += AfxSpaces(55 - LEN(szText)) & " ' VTable offset = " & FORMAT$(@pFuncdesc.oVft)
            TLB_AddLine(BYCOPY szText)
         END IF
      END IF
      ' Show information about the function
      TLB_GetFunctionInfo(hWnd, szName, pITypeInfo, pFuncDesc, hNode, bShowOffset, nCodeType, bViewOnly)
      IF bViewOnly THEN
         ' Expand the node
         IF nCodeType = %CODEGEN_DLL THEN
            TreeView_Expand hTreeView, hNode, %TVE_EXPAND
         ELSEIF strImplInterface = "IUNKNOWN" THEN
            TreeView_Expand hTreeView, hNode, %TVE_EXPAND
         ELSEIF szName <> "QueryInterface" AND _
            szName <> "AddRef" AND _
            szName <> "Release" AND _
            szName <> "GetTypeInfoCount" AND _
            szName <> "GetTypeInfo" AND _
            szName <> "GetIDsOfNames" AND _
            szName <> "Invoke" THEN
            TreeView_Expand hTreeView, hNode, %TVE_EXPAND
         END IF
      END IF
      ' Retrieve information about the return type
      strReturn = TLB_GetReturnType(hWnd, pITypeInfo, pFuncDesc, hNode, nCodeType, bViewOnly)
      IF bViewOnly THEN
         ' Number of parameters in a new node
         hNode = TV_InsertItem(hTreeView, hNode, "Number of parameters = " & FORMAT$(@pFuncDesc.cParams))
         ' Expand the node
         TreeView_Expand hTreeView, hNode, %TVE_EXPAND
      END IF
      ' Retrieve information about the parameters
      strRetVal = TLB_GetParametersInfo(hWnd, pITypeInfo, pFuncDesc, szName, hNode, nCodeType, bViewOnly, VBView, strReturn, bIsUnknown)
      ' Expand the node
      IF bViewOnly THEN
         TreeView_Expand hTreeView, hNode, %TVE_EXPAND
      END IF
      IF ISFALSE bViewOnly THEN
         IF nCodeType = %CODEGEN_DLL THEN
'            TLB_AddLine("    )" & strReturn)
            TLB_AddLine(" )" & strReturn)
            TLB_AddLine("' ========================================================================================")
            TLB_AddLine("")
         ELSEIF VBView THEN   ' Uses Automation view
'            IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET AND @pFuncDesc.cParams > 0 THEN
            IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN
               ' Workaround for buggy libraries that don't have the last parameter
               ' of GET properties flagged as [out, retval].
               IF INSTR(UCASE$(strReturn), "VT_VOID") <> 0 AND _
                  INSTR(UCASE$(strRetVal), "VOID") = 0 THEN
                  TLB_AddLine("   )" & strRetVal)
               ELSE
                  TLB_AddLine("   )" & strReturn)
               END IF
            ELSE
               TLB_AddLine("   )" & strReturn)
            END IF
         ELSEIF @pFuncDesc.invkind = %INVOKE_PROPERTYGET AND @pFuncDesc.cParams > 0 THEN
            ' Workaround for buggy libraries that don't have the last parameter
            ' of GET properties flagged as [out, retval].
            IF UCASE$(RIGHT$(strRetVal, 4)) = "VOID" THEN
               TLB_AddLine("   )" & strReturn)
            ELSE
               TLB_AddLine("   )" & strRetVal)
            END IF
         ELSEIF @pFuncDesc.invkind = %INVOKE_PROPERTYGET AND @pFuncDesc.cParams = 0 THEN
            ' Some get properties doesn't use an out retval parameter, but instead use the
            ' return value (e.g. GET Parent property of the DocumentProperty interface of MSO.DLL)
            TLB_AddLine("   )" & strReturn)
         ELSEIF ISTRUE bIsUnknown THEN
            TLB_AddLine("   )" & strReturn)
         ELSE
            TLB_AddLine("   )" & strRetVal)
         END IF
      END IF
      ' Releases the FuncDesc interface
      pITypeInfo.ReleaseFuncDesc(pFuncDesc)
      pFuncDesc = 0
   NEXT
   ' -------------------------------------------------------------------------------------

   ' Releases the FuncDesc interface in the case of a premature exit
   IF pFuncDesc THEN
      pITypeInfo.ReleaseFuncDesc(pFuncDesc)
   END IF

   ' Expands the root node
   IF bViewOnly THEN
      TreeView_Expand(hTreeView, hRoot, %TVE_EXPAND)
   ELSE
      IF nCodeType <> %CODEGEN_DLL THEN
         IF count THEN
            TLB_AddLine("   ' =====================================================================================")
            TLB_AddLine("")
         END IF
      END IF
   END IF

END SUB
' ========================================================================================

' ########################################################################################
' Enumerates inherited interfaces
' ########################################################################################
FUNCTION TLB_EnumInheritedInterfaces ( _
   BYVAL hWnd                  AS DWORD _              ' // Handle of the main window
 , BYVAL pITypeLib             AS ITypeLib _           ' // ITypeLib interface
 , BYVAL strItemName           AS STRING _             ' // Item to retrieve
 , BYVAL fFlags                AS LONG _               ' // Flags
 , BYVAL bIsUnknown            AS LONG _               ' // Is an IUnknwon interface
   ) AS STRING

   LOCAL hr                    AS LONG                 ' // HRESULT
   LOCAL TypeInfoCount         AS LONG                 ' // Number of TypeInfos
   LOCAL pITypeInfo            AS ITypeInfo            ' // TypeInfo interface
   LOCAL pTypeAttr             AS TYPEATTR PTR         ' // Address of a pointer to the TYPEATTR structure
   LOCAL pTKind                AS DWORD                ' // TYPEKIND
   LOCAL i                     AS LONG                 ' // Loop counter
   LOCAL bstrName              AS WSTRING              ' // Member's name (unicode)
   LOCAL bstrDocString         AS WSTRING              ' // Documentation string (unicode)
   LOCAL pdwHelpContext        AS DWORD                ' // Help context
   LOCAL bstrHelpFile          AS WSTRING             ' // Help file (unicode)
   LOCAL szInterfaceName       AS ASCIIZ * 256         ' // Interface name
   LOCAL pRefType              AS DWORD                ' // Address to a referenced type description
   LOCAL pRefTypeInfo          AS ITypeInfo            ' // Referenced TypeInfo interface
   LOCAL pRefTypeAttr          AS TYPEATTR PTR         ' // Referenced TYPEATTR structure
   LOCAL hRoot                 AS DWORD                ' // Root node handle
   LOCAL bViewOnly             AS LONG                 ' // View only
   LOCAL strInheritedInterface AS STRING               ' // Inherited interface

   hRoot = 0
   bViewOnly = %FALSE

   TypeInfoCount = pITypeLib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN EXIT FUNCTION

   ' If this function returns the same interface name than the one passed to it,
   ' it means that the inherited interface has not been found and must be located
   ' in another type library.
   strInheritedInterface = strItemName

   FOR i = 0 TO TypeInfoCount - 1

      ' --- Allow for a breath and check the abort flag ---------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR
      ' --- Retrieves the TypeKind ------------------------------------------------------
      hr = pITypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN EXIT FOR
      ' --- Retrieves the TypeInfo interface --------------------------------------------
      hr = pITypeLib.GetTypeInfo(i, pITypeInfo)
      IF hr <> %S_OK THEN EXIT FOR
      ' --- Gets the address of a pointer to the TYPEATTR structure ---------------------
      hr = pITypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN EXIT FOR
      ' --- If it is an interface ... ---------------------------------------------------
      IF pTKind = %TKIND_INTERFACE OR pTKind = %TKIND_DISPATCH THEN
         hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' -- If it is the interface we are looking for... ------------------------------
         szInterfaceName = bstrName
         IF szInterfaceName = strItemName THEN
            ' --- If it inherits from another interface, recursively search the methods
            IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
               strInheritedInterface = TLB_GetInheritedInterface(pITypeInfo, -1)
            ELSE
               strInheritedInterface = TLB_GetImplementedInterface(pITypeInfo)
            END IF
            ' Check also that the interface doesn't inherit from itself!
            IF strInheritedInterface <> "" AND UCASE$(strInheritedInterface) <> "IUNKNOWN" AND UCASE$(strInheritedInterface) <> "IDISPATCH" AND UCASE$(strInheritedInterface) <> UCASE$(szInterfaceName) THEN
               strInheritedInterface = TLB_EnumInheritedInterfaces(hWnd, pITypeLib, strInheritedInterface, fFlags, bIsUnknown)
            END IF
            ' --- End recursion ---------------------------------------------------------
            IF @pTypeAttr.cFuncs THEN
               IF pTKind = %TKIND_DISPATCH AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                  ' Attempt to change the view to VTable
                  pRefType = %NULL
                  hr = pITypeInfo.GetRefTypeOfImplType(-1, pRefType)
                  IF hr = %S_OK AND pRefType <> %NULL THEN
                     hr = pITypeInfo.GetRefTypeInfo(pRefType, pRefTypeInfo)
                     IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                        pRefTypeAttr = %NULL
                        hr = pRefTypeInfo.GetTypeAttr(pRefTypeAttr)
                        ' Enumerate the functions
                        IF hr <> %S_OK OR pRefTypeAttr = %NULL THEN
                           TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strItemName)
                        ELSE
                           TLB_EnumFunctions(hWnd, pRefTypeAttr, pRefTypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strItemName)
                           pRefTypeInfo.ReleaseTypeAttr pRefTypeAttr
                           pRefTypeAttr = %NULL
                        END IF
                        pRefTypeInfo = NOTHING
                     END IF
                  ELSE
                     TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strItemName)
                  END IF
               ELSE
                  TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strItemName)
               END IF
            END IF
         END IF
      END IF
      ' --- Releases the TYPEATTR structure ---------------------------------------------
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0
      ' --- Releases the TypeInfo interface ---------------------------------------------
      pITypeInfo = NOTHING
   NEXT

   ' --- Releases the interfaces --------------------------------------------------------
   IF ISTRUE pTypeAttr THEN
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pITypeInfo = NOTHING
   pITypeLib = NOTHING

   FUNCTION = strInheritedInterface

END FUNCTION

' ########################################################################################
' Enumerates external interfaces
' ########################################################################################
FUNCTION TLB_EnumExternalInterfaces ( _
   BYVAL hWnd                  AS DWORD _              ' // Handle of the main window
 , BYVAL pITypeInfo            AS ITypeInfo _          ' // ITypeinfo interface
 , BYVAL strItemName           AS STRING _             ' // Item to retrieve
 , BYVAL fFlags                AS LONG _               ' // Flags
 , BYVAL bIsUnknown            AS LONG _               ' // Is an IUnknwon interface
   ) AS LONG

   IF ISNOTHING(pITypeInfo) THEN EXIT FUNCTION
   IF strItemName = "" THEN EXIT FUNCTION

   LOCAL hr                    AS LONG                 ' // HRESULT
   LOCAL strImplInterface      AS STRING               ' // Implemented interface
   LOCAL strImplInterfaceIID   AS STRING               ' // Implemented interface IID
   LOCAL strTypeLibGuid        AS STRING               ' // Type library guid
   LOCAL strTypeLibVersion     AS STRING               ' // Type library version
   LOCAL wTypeLibVerMajor      AS WORD                 ' // Type library major version
   LOCAL wTypeLibVerMinor      AS WORD                 ' // Type library minor version
   LOCAL strTypeLibPath        AS STRING               ' // Type library path
   LOCAL wszTypeLibPath        AS WSTRINGZ * %MAX_PATH ' // Type library path (unicode)
   LOCAL pITypeLib             AS ITypeLib             ' // Pointer to ITypeLib interface
   LOCAL TypeInfoCount         AS LONG                 ' // Number of typeinfos
   LOCAL pExtTypeInfo          AS ITypeInfo            ' // Pointer to ITypeInfo interface
   LOCAL pExtTypeAttr          AS TYPEATTR PTR         ' // Pointer to TYPEATTR structure
   LOCAL bstrName              AS WSTRING              ' // Interface name
   LOCAL bstrDocString         AS WSTRING              ' // Documentation string
   LOCAL pdwHelpContext        AS DWORD                ' // Help context
   LOCAL bstrHelpFile          AS WSTRING              ' // Help file
   LOCAL szInterfaceName       AS ASCIIZ * 256         ' // Interface name
   LOCAL pTKind                AS DWORD                ' // Interface type
   LOCAL i                     AS LONG                 ' // Loop counter
   LOCAL pRefType              AS DWORD                ' // Reference type
   LOCAL pRefTypeInfo          AS ITypeInfo            ' // Pointer to ITypeInfo
   LOCAL pRefTypeAttr          AS TYPEATTR PTR         ' // Pointer to a TYPEATTR structure
   LOCAL strInheritedInterface AS STRING               ' // Inherited interface name
   LOCAL strNewInhInterface    AS STRING               ' // New inherited interface name
   LOCAL old_UsePropGetSet     AS LONG

   strImplInterface = UCASE$(TLB_GetImplementedInterface(pITypeInfo))
   IF strImplInterface <> "" AND strImplInterface <> "IUNKNOWN" AND strImplInterface <> "IDISPATCH" THEN
      strImplInterfaceIID = TLB_GetImplementedInterfaceIID(pITypeInfo)
      hr = TLB_GetTypeLibFromInterfaceIID(strImplInterfaceIID, strTypeLibGuid, strTypeLibVersion, wTypeLibVerMajor, wTypeLibVerMinor, strTypeLibPath)
      IF hr = %S_OK AND strTypeLibPath <> "" THEN
         wszTypeLibPath = strTypeLibPath
         hr = LoadTypeLibEx(wszTypeLibPath, %REGKIND_NONE, pITypeLib)
         IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeLib) THEN EXIT FUNCTION
         ' --- Retrieves the number of TypeInfos -----------------------------------------------
         TypeInfoCount = pITypeLib.GetTypeInfoCount
         IF TypeInfoCount = 0 THEN
            pITypeLib = NOTHING
            EXIT FUNCTION
         END IF
         ' --- Parses the TypeInfos ------------------------------------------------------------
         FOR i = 0 TO TypeInfoCount - 1
            ' --- Allow for a breath and check the abort flag ---------------------------------
            TLB_DoEvents hWnd
            IF m_Abort THEN EXIT FOR
            ' --- Retrieves the TypeKind ------------------------------------------------------
            hr = pITypeLib.GetTypeInfoType(i, pTKind)
            IF hr <> %S_OK THEN EXIT FOR
            ' --- Retrieves the TypeInfo interface --------------------------------------------
            hr = pITypeLib.GetTypeInfo(i, pExtTypeInfo)
            IF hr <> %S_OK THEN EXIT FOR
            ' --- Gets the address of a pointer to the TYPEATTR structure ---------------------
            hr = pExtTypeInfo.GetTypeAttr(pExtTypeAttr)
            IF hr <> %S_OK OR pExtTypeAttr = %NULL THEN EXIT FOR
            ' --- If it is an interface ... ---------------------------------------------------
            IF pTKind = %TKIND_INTERFACE OR pTKind = %TKIND_DISPATCH THEN
               hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
               ' -- If it is the interface we are looking for... ------------------------------
               szInterfaceName = bstrName
               IF szInterfaceName = strItemName THEN
                  IF (@pExtTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                     strInheritedInterface = TLB_GetInheritedInterface(pExtTypeInfo, -1)
                  ELSE
                     strInheritedInterface = TLB_GetImplementedInterface(pITypeInfo)
                  END IF
                  IF pTKind = %TKIND_DISPATCH THEN
                     ' Attempt to change the view to VTable
                     hr = pExtTypeInfo.GetRefTypeOfImplType(-1, pRefType)
                     IF hr = %S_OK AND pRefType <> %NULL THEN
                        hr = pExtTypeInfo.GetRefTypeInfo(pRefType, pRefTypeInfo)
                        IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                           hr = pRefTypeInfo.GetTypeAttr(pRefTypeAttr)
                           ' Enumerate the functions
                           IF hr <> %S_OK OR pRefTypeAttr = %NULL THEN
                              TLB_EnumFunctions(hWnd, pExtTypeAttr, pExtTypeInfo, 0, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), 0, bIsUnknown, %FALSE, szInterfaceName)
                           ELSE
                              IF strInheritedInterface <> "" AND UCASE$(strInheritedInterface) <> "IDISPATCH" AND UCASE$(strInheritedInterface) <> "IUNKNOWN" THEN
                                 strNewInhInterface = TLB_EnumInheritedInterfaces(hWnd, pITypeLib, strInheritedInterface, fFlags, bIsUnknown)
                                 ' If the returned interface name is the same, it must be an external interface
                                 IF strNewInhInterface = strInheritedInterface THEN
                                    TLB_EnumExternalInterfaces(hWnd, pRefTypeInfo, strInheritedInterface, fFlags, bIsUnknown)
                                 END IF
                              END IF
                              TLB_EnumFunctions(hWnd, pRefTypeAttr, pRefTypeInfo, 0, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), 0, bIsUnknown, %FALSE, szInterfaceName)
                              pRefTypeInfo.ReleaseTypeAttr(pRefTypeAttr)
                              pRefTypeAttr = %NULL
                           END IF
                        END IF
                     ELSE
                        TLB_EnumFunctions(hWnd, pExtTypeAttr, pExtTypeInfo, 0, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), 0, bIsUnknown, %FALSE, szInterfaceName)
                     END IF
                  ELSE
                     IF strInheritedInterface <> "" AND UCASE$(strInheritedInterface) <> "IDISPATCH" AND UCASE$(strInheritedInterface) <> "IUNKNOWN" THEN
                        strNewInhInterface = TLB_EnumInheritedInterfaces(hWnd, pITypeLib, strInheritedInterface, fFlags, bIsUnknown)
                        ' If the returned interface name is the same, it must be an external interface
                        IF strNewInhInterface = strInheritedInterface THEN
                           TLB_EnumExternalInterfaces(hWnd, pITypeInfo, strInheritedInterface, fFlags, bIsUnknown)
                        END IF
                     END IF
                     TLB_EnumFunctions(hWnd, pExtTypeAttr, pExtTypeInfo, 0, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), 0, bIsUnknown, %FALSE, szInterfaceName)
                  END IF
               END IF
            END IF
            IF ISTRUE pExtTypeAttr THEN
               pExtTypeInfo.ReleaseTypeAttr(pExtTypeAttr)
               pExtTypeAttr = %NULL
            END IF
            pExtTypeInfo = NOTHING
         NEXT
         pITypeLib = NOTHING
      END IF
   END IF

END FUNCTION

' ########################################################################################
' Enumerates enums, interfaces...
' ########################################################################################
FUNCTION TLB_EnumTypeLibs ( _
   BYVAL hWnd                  AS DWORD _              ' // Handle of the main window
 , BYVAL strItemName           AS STRING _             ' // Item to retrieve
 , BYVAL nItemType             AS LONG _               ' // Item type
 , BYVAL fFlags                AS LONG _               ' // Flags
   ) AS LONG

   LOCAL hr                    AS LONG                 ' // HRESULT
   LOCAL hPageCtrl             AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hTreeView             AS DWORD                ' // TreeView handle
   LOCAL pITypeLib             AS ITypeLib             ' // TypeLib interface
   LOCAL pITypeInfo            AS ITypeInfo            ' // TypeInfo interface
   LOCAL pTypeAttr             AS TYPEATTR PTR         ' // Address of a pointer to the TYPEATTR structure
   LOCAL lptdesc               AS TYPEDESC PTR         ' // Pointer to a TYPEDESC structure
   LOCAL pRefType              AS DWORD                ' // Address to a referenced type description
   LOCAL pRefTypeInfo          AS ITypeInfo            ' // Referenced TypeInfo interface
   LOCAL pRefTypeAttr          AS TYPEATTR PTR         ' // Referenced TYPEATTR structure
   LOCAL bstrName              AS WSTRING              ' // Member's name (unicode)
   LOCAL bstrDocString         AS WSTRING              ' // Documentation string (unicode)
   LOCAL pdwHelpContext        AS DWORD                ' // Help context
   LOCAL bstrHelpFile          AS WSTRING              ' // Help file (unicode)
   LOCAL TypeInfoCount         AS LONG                 ' // Number of TypeInfos
   LOCAL pTKind                AS DWORD                ' // TYPEKIND
   LOCAL hRoot                 AS DWORD                ' // Root node handle
   LOCAL szName                AS ASCIIZ * 256         ' // Name
   LOCAL szText                AS ASCIIZ * 256         ' // General purpose variable
   LOCAL szEnumName            AS ASCIIZ * 256         ' // Enumeration name
   LOCAL szRecordName          AS ASCIIZ * 256         ' // Record name
   LOCAL szModuleName          AS ASCIIZ * 256         ' // Module name
   LOCAL szInterfaceName       AS ASCIIZ * 256         ' // Interface name
   LOCAL strIntName            AS STRING               ' // Interface name
   LOCAL szOrigInterfaceName   AS ASCIIZ * 256         ' // Original interface name
   LOCAL strAlias              AS STRING               ' // Alias name
   LOCAL strText               AS STRING               ' // General purpose variable
   LOCAL strMacro              AS STRING               ' // Generated macro
   LOCAL strIID                AS STRING               ' // IID
   LOCAL fFirstTime            AS LONG                 ' // Flag
   LOCAL vt                    AS WORD                 ' // Variant type
   LOCAL i                     AS LONG                 ' // Loop counter
   LOCAL hRichEditBox          AS DWORD                ' // Handle of the rich edit box
   LOCAL hMenu                 AS DWORD                ' // Menu handle
   LOCAL hSubMenu              AS DWORD                ' // Submenu handle
   LOCAL hStatusBar            AS DWORD                ' // Handle of the status bar
   LOCAL hPrefixBox            AS DWORD                ' // Handle of the edit box
   LOCAL bViewOnly             AS LONG                 ' // View only
   LOCAL strInheritedInterface AS STRING               ' // Inherited interface
   LOCAL strOrigInheritedInt   AS STRING               ' // Original inherited interface name
   LOCAL strImplInterface      AS STRING               ' // Implemented interface
   LOCAL strPrefix             AS STRING               ' // Prefix
   LOCAL bIsUnknown            AS LONG                 ' // Is an IUnknwon interface
   LOCAL wszPath               AS WSTRINGZ * %MAX_PATH ' // Path (unicode)
   LOCAL idx                   AS LONG                 ' // Index
   LOCAL old_UsePropGetSet     AS LONG                 ' // Flag
   LOCAL strCoClassName        AS STRING               ' // CoClass name
   LOCAL strBaseClass          AS STRING               ' // Base class
   LOCAL strNewInhInterface    AS STRING               ' // New inherited interface

   IF hWnd = %NULL THEN EXIT FUNCTION
   IF LEN(m_SelPath) = 0 THEN EXIT FUNCTION
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF fFlags = %REPORT_VIEWONLY AND hTreeView = %NULL THEN EXIT FUNCTION
   fFirstTime = %TRUE
   IF ISTRUE m_Busy THEN EXIT FUNCTION
   IF fFlags = %REPORT_VIEWONLY THEN bViewOnly = %TRUE

   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
   IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
   IF hPrefixBox THEN GetWindowText(hPrefixBox, szText, SIZEOF(szText))
   TLB_PrefixStr = szText

   ' Flags to add the StdFont and StdPicture interfaces if needed
   ' when using the m_MixDispInterfaces option
   TLB_UsesFontInterface = %FALSE
   TLB_UsesPictureInterface = %FALSE

   ' --- Loads the TypeLib ---------------------------------------------------------------
   wszPath = m_SelPath
   hr = LoadTypeLibEx(wszPath, %REGKIND_NONE, pITypeLib)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeLib) THEN
      MessageBox BYVAL %NULL, "Error &H" & HEX$(hr, 8) & " loading " & m_SelPath, _
             " " & FUNCNAME$ & " - LoadTypeLibEx", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      EXIT FUNCTION
   END IF

   ' --- Retrieves the number of TypeInfos -----------------------------------------------
   TypeInfoCount = pITypeLib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN
      MessageBox BYVAL %NULL, "This TypeLib doesn't have Type Infos" , _
         " " & FUNCNAME$ & " - ITypeLib.GetTypeInfoCount", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      pITypeLib = NOTHING
      EXIT FUNCTION
   END IF

   ' --- Clears the TreeView or clears the buffer ----------------------------------------
   IF fFlags = %REPORT_VIEWONLY THEN
      ' Disables redraw to minimize flicker
      SendMessage hTreeView, %WM_SETREDRAW, %FALSE, 0
      ' Deletes the items
      IF TreeView_GetCount(hTreeView) THEN TreeView_DeleteAllItems(hTreeView)
   ELSE
      MOUSEPTR 11   ' Hourglass cursor
   END IF

   ' Activate flag
   m_Busy = %TRUE

   IF (fFlags AND %REPORT_CODEONLY) <> %REPORT_CODEONLY THEN
      m_Buffer = ""
      m_BufLen = 0
      ' Report header
      TLB_LibraryHeader(nItemType)
   END IF

   IF nItemType = %ENUM_ALL THEN
      ' Identifiers
      TLB_EnumIdentifiers(hWnd)
   END IF

   ' =====================================================================================
   '  Parses the TypeLib
   ' =====================================================================================
   FOR i = 0 TO TypeInfoCount - 1

      ' --- Allow for a breath and check the abort flag ----------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR

      ' --- Retrieves the TypeKind -------------------------------------------------------
      hr = pITypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the InfoType", _
            " " & FUNCNAME$ & " - ITypeLib.GetTypeInfoType", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' --- Retrieves the TypeInfo interface ---------------------------------------------
      hr = pITypeLib.GetTypeInfo(i, pITypeInfo)
      IF hr <> %S_OK THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the TypeInfo interface" , _
            " " & FUNCNAME$ & " - ITypeLib.GetTypeInfo", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' --- Gets the address of a pointer to the TYPEATTR structure ----------------------
      hr = pITypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the address of the TypeAttr structure" , _
            " " & FUNCNAME$ & " - ITypeInfo.GetTypeAttr", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' ==================================================================================
      ' If it is an enumeration ...
      ' ==================================================================================
      IF pTKind = %TKIND_ENUM AND (nItemType = %ENUM_ALL OR nItemType = %ENUM_CONSTANTS) THEN
         ' --- Retrieves the enumeration's name ------------------------------------------
         hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' -- If it is the enumeration we are looking for... -----------------------------
         szEnumName = bstrName
         ' See if the name is an alias
         strAlias = TLB_GetAliasNameFromArray2(szEnumName)
         DO
            IF LEFT$(strAlias, 1) <> "_" THEN EXIT DO
            strAlias = MID$(strAlias, 2)
         LOOP
         IF hr = %S_OK AND (strItemName = "" OR szEnumName = strItemName) THEN
            ' --- Shows general information ----------------------------------------------
            IF fFlags = %REPORT_VIEWONLY THEN
               hRoot = TV_InsertItem(hTreeView, 0, BYCOPY strItemName)
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TV_InsertItem hTreeView, hRoot, "IID: " & szText
               szText = bstrDocString
               IF LEN(szText) THEN TV_InsertItem(hTreeView, hRoot, "Documentation string: " & szText)
               TV_InsertItem(hTreeView, hRoot, "Number of constants: " & FORMAT$(@pTypeAttr.cVars))
               TLB_EnumConstants(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, szEnumName, strAlias, %TRUE)
            ELSEIF @pTypeAttr.cVars THEN
               TLB_AddLine("' ========================================================================================")
               IF LEN(strAlias) THEN
'                  TLB_AddLine("' " & szEnumName & " enum <alias> " & strAlias)
                  TLB_AddLine("' " & strAlias & " enum <alias> " & szEnumName)
               ELSE
                  TLB_AddLine("' " & szEnumName & " enum")
               END IF
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID: " & szText)
               szText = bstrDocString
               REPLACE ANY $CR & $LF WITH "  " IN szText
               IF LEN(szText) THEN TLB_AddLine("' " & szText)
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
               ' Enumerates the constants
               TLB_EnumConstants(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, szEnumName, strAlias, %FALSE)
               TLB_AddLine("")
            END IF
         END IF
      END IF
      ' ==================================================================================

      ' ==================================================================================
      ' If it is a record or union ...
      ' ==================================================================================
      IF (pTKind = %TKIND_RECORD OR pTKind = %TKIND_UNION) AND (nItemType = %ENUM_ALL OR nItemType = %ENUM_RECORDS) THEN
         ' --- Retrieves the record's name -----------------------------------------------
         hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' -- If it is the record we are looking for... ----------------------------------
         szRecordName = bstrName
         IF hr = %S_OK AND (strItemName = "" OR szRecordName = strItemName) THEN
            ' --- Shows general information ----------------------------------------------
            IF fFlags = %REPORT_VIEWONLY THEN
               hRoot = TV_InsertItem(hTreeView, 0, BYCOPY strItemName)
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TV_InsertItem hTreeView, hRoot, "IID = " & szText
               szText = bstrDocString
               IF LEN(szText) THEN TV_InsertItem(hTreeView, hRoot, "Documentation string = " & szText)
               szText = bstrHelpFile
               IF LEN(szText) THEN TV_InsertItem(hTreeView, hRoot, "Help file = " & szText)
               IF pdwHelpContext THEN TV_InsertItem(hTreeView, hRoot, "Help context = " & FORMAT$(pdwHelpContext) & " [&H" & HEX$(pdwHelpContext, 8) & "]")
               IF @pTypeAttr.wTypeFlags THEN TV_InsertItem(hTreeView, hRoot, "Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
               IF @pTypeAttr.cVars THEN TV_InsertItem(hTreeView, hRoot, "Number of members = " & FORMAT$(@pTypeAttr.cVars))
            ELSE
'               IF ISFALSE fNotePrinted THEN
'                  fNotePrinted = %TRUE
'                  TLB_AddLine("' ========================================================================================")
'                  TLB_AddLine("' Note: You may need to change the placement in the code of some structures that are")
'                  TLB_AddLine("' referenced before they are defined, something not allowed by the PB compilers. Another")
'                  TLB_AddLine("' problem are structures and unions with cross references, e.g. an structure with a")
'                  TLB_AddLine("' member thas is an union having that same structure as one of its members. In such cases,")
'                  TLB_AddLine("' you will need to declare the member as DWORD.")
'                  TLB_AddLine("' ========================================================================================")
'                  TLB_AddLine("")
'               END IF
               TLB_AddLine("' ========================================================================================")
               strAlias = ""
               IF pTKind = %TKIND_RECORD THEN
                  strAlias = TLB_GetAliasNameFromArray2(szRecordName)
                  ' Keep the original name of the structure if it is not a "__MIDL__" one
                  IF LEN(strAlias) > 0 AND LEFT$(szRecordName, 8) <> "__MIDL__" THEN
                     szText = strAlias
                     strAlias = szRecordName
                     szRecordName = szText
                  END IF
                  IF LEN(strAlias) THEN
'                     TLB_AddLine("' " & szRecordName & " record <alias> " & strAlias)
                     TLB_AddLine("' " & strAlias & " record <alias> " & szRecordName)
                  ELSE
                     TLB_AddLine("' " & szRecordName & " record")
                  END IF
               ELSEIF pTKind = %TKIND_UNION THEN
                  strAlias = TLB_GetAliasNameFromArray2(szRecordName)
                  IF LEN(strAlias) THEN
'                     TLB_AddLine("' " & szRecordName & " union <alias> " & strAlias)
                     TLB_AddLine("' " & strAlias & " union <alias> " & szRecordName)
                  ELSE
                     TLB_AddLine("' " & szRecordName & " union")
                  END IF
               END IF
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID = " & szText)
               IF @pTypeAttr.cVars THEN TLB_AddLine("' Number of members = " & FORMAT$(@pTypeAttr.cVars))
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
            END IF
            ' -- Enumerate the members ---------------------------------------------------
            IF fFlags = %REPORT_VIEWONLY THEN
               TLB_GetMembers(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, pITypeLib, %TRUE, %TRUE)
            ELSE
'               IF pTKind = %TKIND_RECORD AND LEFT$(szRecordName, 1) = "_" THEN szRecordName = "tag" & szRecordName
'               IF pTKind = %TKIND_UNION AND LEFT$(szRecordName, 1) = "_" THEN szRecordName = "u" & szRecordName
'               IF pTKind = %TKIND_RECORD THEN TLB_AddLine("TYPE " & szRecordName)
'               IF pTKind = %TKIND_UNION THEN TLB_AddLine("UNION " & szRecordName)
'               IF pTKind = %TKIND_RECORD THEN
'                  IF strAlias = "" THEN
'                     IF LEFT$(szRecordName, 1) = "_" THEN szRecordName = "tag" & szRecordName
'                     TLB_AddLine("TYPE " & szRecordName)
'                  ELSE
'                     IF LEFT$(strAlias, 1) = "_" THEN strAlias = "tag" & strAlias
'                     TLB_AddLine("TYPE " & strAlias)
'                  END IF
'               END IF
'               IF pTKind = %TKIND_UNION THEN
'                  IF strAlias = "" THEN
'                     IF LEFT$(szRecordName, 1) = "_" THEN szRecordName = "u" & szRecordName
'                     TLB_AddLine("UNION " & szRecordName)
'                  ELSE
'                     IF LEFT$(strAlias, 1) = "_" THEN strAlias = "u" & strAlias
'                     TLB_AddLine("UNION " & strAlias)
'                  END IF
'               END IF
               IF pTKind = %TKIND_RECORD THEN
                  IF LEN(strAlias) THEN
                     IF LEFT$(strAlias, 1) = "_" THEN strAlias = "tag" & strAlias
                     TLB_AddLine("#IF NOT %DEF(%" & strAlias & "_DEFINED)")
                     TLB_AddLine("%" & strAlias & "_DEFINED = 1")
                     TLB_AddLine("")
                     TLB_AddLine("TYPE " & strAlias)
                  ELSE
                     IF LEFT$(szRecordName, 1) = "_" THEN szRecordName = "tag" & szRecordName
                     TLB_AddLine("#IF NOT %DEF(%" & szRecordName & "_DEFINED)")
                     TLB_AddLine("%" & szRecordName & "_DEFINED = 1")
                     TLB_AddLine("")
                     TLB_AddLine("TYPE " & szRecordName)
                  END IF
               ELSEIF pTKind = %TKIND_UNION THEN
                  IF LEN(strAlias) THEN
                     IF LEFT$(strAlias, 1) = "_" THEN strAlias = "u" & strAlias
                     TLB_AddLine("#IF NOT %DEF(%" & strAlias & "_DEFINED)")
                     TLB_AddLine("%" & strAlias & "_DEFINED = 1")
                     TLB_AddLine("")
                     TLB_AddLine("UNION " & strAlias)
                  ELSE
                     IF LEFT$(szRecordName, 1) = "_" THEN szRecordName = "u" & szRecordName
                     TLB_AddLine("#IF NOT %DEF(%" & szRecordName & "_DEFINED)")
                     TLB_AddLine("%" & szRecordName & "_DEFINED = 1")
                     TLB_AddLine("")
                     TLB_AddLine("UNION " & szRecordName)
                  END IF
               END IF
               TLB_GetMembers(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, pITypeLib, %TRUE, %FALSE)
               IF pTKind = %TKIND_RECORD THEN TLB_AddLine("END TYPE")
               IF pTKind = %TKIND_UNION THEN TLB_AddLine("END UNION")
               ' Make a MACRO for aliased structure names, so we can use both names
               IF LEN(strAlias) THEN
                  IF pTKind = %TKIND_RECORD AND LEFT$(szRecordName, 1) = "_" THEN szRecordName = "tag" & szRecordName
                  IF pTKind = %TKIND_UNION AND LEFT$(szRecordName, 1) = "_" THEN szRecordName = "u" & szRecordName
                  TLB_AddLine("")
'                  TLB_AddLine("#IF NOT %DEF(%MACRO_" & szRecordName & "_DEFINED)")
'                  TLB_AddLine("%MACRO_" & szRecordName & "_DEFINED = 1")
                  TLB_AddLine("MACRO " & szRecordName & " = " & strAlias)
'                  TLB_AddLine("#ENDIF")
               END IF
               TLB_AddLine("")
               TLB_AddLine("#ENDIF")
               TLB_AddLine("")
            END IF
         END IF
      END IF
      ' ==================================================================================

      ' ==================================================================================
      ' If it is a typedef ...
      ' ==================================================================================
      IF pTKind = %TKIND_ALIAS AND nItemType = %ENUM_TYPEDEFS THEN
         strMacro = ""
         hr = pITypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         szName = bstrName
         IF hr = %S_OK THEN
            IF @pTypeAttr.tdescAlias.vt = %VT_USERDEFINED THEN
               ' If it is a user defined type, retrieve his name
               hr = pITypeInfo.GetRefTypeInfo(@pTypeAttr.tdescAlias.hreftype, pRefTypeInfo)
               IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                  hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr = %S_OK THEN
                     szName = szName & " = " & bstrName
                     ' Do not save it in the file, its an alias
                  END IF
                  pRefTypeInfo = NOTHING
               END IF
            ELSEIF @pTypeAttr.tdescAlias.vt = %VT_PTR THEN
               ' Pointer to a TYPEDESC structure
               lptdesc = @pTypeAttr.tdescAlias.lptdesc
               DO
                  ' VarType
                  vt = @lptdesc.vt
                  SELECT CASE vt
                     ' If it is a pointer, do it again
                     CASE %VT_PTR
                        lptdesc = @lptdesc.lptdesc
                     CASE %VT_USERDEFINED
                        ' Retrieve the name of the userdefined type
                        hr = pITypeInfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
                        IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                           hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                           IF hr = %S_OK THEN
                              szName = szName & " = " & bstrName
                              ' Do nothing, is an alias
                           END IF
                           pRefTypeInfo = NOTHING
                        END IF
                        EXIT DO
                     CASE ELSE
                        ' Make the macro
                        strMacro = "MACRO " & szName
                        strText = VarTypeToKeyword(@pTypeAttr.tdescAlias.vt)
                        strText += AfxSpaces(15 - LEN(strText))
                        strMacro = strMacro & AfxSpaces(55 - LEN(strMacro)) & " = " & strText & "   ' " & VarTypeToConstant(@pTypeAttr.tdescAlias.vt)
                        EXIT DO
                  END SELECT
               LOOP
            ELSE
               ' Make the macro
               strMacro = "MACRO " & szName
               strText = VarTypeToKeyword(@pTypeAttr.tdescAlias.vt)
               strText += AfxSpaces(15 - LEN(strText))
               strMacro = strMacro & AfxSpaces(55 - LEN(strMacro)) & " = " & strText & "   ' " & VarTypeToConstant(@pTypeAttr.tdescAlias.vt)
            END IF
         END IF
         ' --- Save the generated macro --------------------------------------------------
         IF LEN(strMacro) THEN
            IF fFirstTime THEN
               fFirstTime = %FALSE
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("' Typedefs")
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
            END IF
            TLB_AddLine(strMacro)
         END IF
      END IF
      ' ==================================================================================

      ' ==================================================================================
      ' If it is a module ...
      ' ==================================================================================
      IF pTKind = %TKIND_MODULE AND nItemType = %ENUM_MODULES THEN
         ' --- Retrieves the module's name -----------------------------------------------
         hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' -- If it is the module we are looking for... ----------------------------------
         szModuleName = bstrName
         ' See if the name is an alias
         strAlias = TLB_GetAliasNameFromArray(szModuleName)
         DO
            IF LEFT$(strAlias, 1) <> "_" THEN EXIT DO
            strAlias = MID$(strAlias, 2)
         LOOP
         IF hr = %S_OK AND (strItemName = "" OR szModuleName = strItemName) THEN
            ' --- Shows general information ----------------------------------------------
            IF fFlags = %REPORT_VIEWONLY THEN
               hRoot = TV_InsertItem(hTreeView, 0, BYCOPY strItemName)
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TV_InsertItem hTreeView, hRoot, "IID: " & szText
               szText = bstrDocString
               IF LEN(szText) THEN TV_InsertItem(hTreeView, hRoot, "Documentation string: " & szText)
               IF @pTypeAttr.wTypeFlags THEN TV_InsertItem(hTreeView, hRoot, "Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
               IF @pTypeAttr.cVars THEN TV_InsertItem(hTreeView, hRoot, "Number of constants = " & FORMAT$(@pTypeAttr.cVars))
               IF @pTypeAttr.cFuncs THEN TV_InsertItem(hTreeView, hRoot, "Number of functions = " & FORMAT$(@pTypeAttr.cFuncs))
               ' Enumerates the constants
               TLB_EnumConstants(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, szModuleName, strAlias, %TRUE)
            ELSEIF @pTypeAttr.cVars THEN
               TLB_AddLine("' ========================================================================================")
               IF LEN(strAlias) THEN
                  TLB_AddLine("' " & strAlias)
               ELSE
                  TLB_AddLine("' " & szModuleName)
               END IF
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID: " & szText)
               szText = bstrDocString
               REPLACE ANY $CR & $LF WITH "  " IN szText
               IF LEN(szText) THEN TLB_AddLine("' " & szText)
               TLB_AddLine("' ========================================================================================")
               TLB_AddLine("")
               ' Enumerates the constants
               TLB_EnumConstants(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, szModuleName, strAlias, %FALSE)
               TLB_AddLine("")
            END IF
            ' Enumerates the functions
            TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %FALSE, %CODEGEN_DLL, bViewOnly, %FALSE, %FALSE)
         END IF
      END IF
      ' ==================================================================================

      ' ==================================================================================
      ' If it is an interface ...
      ' ==================================================================================
      IF (pTKind = %TKIND_DISPATCH OR pTKind = %TKIND_INTERFACE) AND (nItemType = %ENUM_ALL OR nItemType = %ENUM_INTERFACES) THEN
         ' --- Retrieves the interface's name --------------------------------------------
         hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' -- If it is the interface we are looking for... -------------------------------
         szOrigInterfaceName = bstrName
         szInterfaceName = szOrigInterfaceName
         bIsUnknown = %FALSE
         m_IAutomation = %FALSE
         strBaseClass = ""
'         IF @pTypeAttr.wTypeFlags = &H100 THEN m_IAutomation = %TRUE
         strImplInterface = TLB_GetImplementedInterface(pITypeInfo, 0)
         IF strImplInterface <> "" THEN
            IF UCASE$(strImplInterface) = "IUNKNOWN" OR UCASE$(strImplInterface) = "IDISPATCH" THEN
               strBaseClass = strImplInterface
            ELSE
               strBaseClass = TLB_GetBaseClass(hWnd, pITypeLib, szInterfaceName)
            END IF
         END IF
         strImplInterface = UCASE$(strImplInterface)
         IF pTKind = %TKIND_INTERFACE AND UCASE$(strBaseClass) = "IUNKNOWN" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FOLEAUTOMATION) = %TYPEFLAG_FOLEAUTOMATION THEN m_IAutomation = %TRUE
         IF hr = %S_OK AND (strItemName = "" OR szInterfaceName = strItemName) THEN
            IF fFlags = %REPORT_VIEWONLY THEN
               hRoot = TV_InsertItem(hTreeView, 0, BYCOPY strItemName)
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TV_InsertItem hTreeView, hRoot, "IID: " & szText
               szText = bstrDocString
               IF LEN(szText) THEN TV_InsertItem(hTreeView, hRoot, "Documentation string: " & szText)
               IF @pTypeAttr.wTypeFlags THEN TV_InsertItem(hTreeView, hRoot, "Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
               IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                  strInheritedInterface = TLB_GetInheritedInterface(pITypeInfo, -1)
               ELSE
                  strInheritedInterface = TLB_GetImplementedInterface(pITypeInfo)
'                  IF ISTRUE m_IAutomation THEN strInheritedInterface = "IAutomation"
               END IF
               IF LEN(strInheritedInterface) THEN TV_InsertItem(hTreeView, hRoot, "Inherited interface = " & strInheritedInterface)
               IF @pTypeAttr.cVars THEN
                  TV_InsertItem(hTreeView, hRoot, "Number of datamembers = " & FORMAT$(@pTypeAttr.cVars))
               END IF
               IF @pTypeAttr.cFuncs THEN
                  TV_InsertItem(hTreeView, hRoot, "Number of functions = " & FORMAT$(@pTypeAttr.cFuncs))
               END IF
               IF @pTypeAttr.cVars THEN
                  TLB_GetMembers(hWnd, pITypeInfo, @pTypeAttr.cVars, hRoot, pITypeLib, %FALSE, %TRUE)
               END IF
               IF @pTypeAttr.cFuncs THEN
                  IF pTKind = %TKIND_DISPATCH AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                     IF ISTRUE m_UseAutomationView THEN
                        TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE)
                     ELSE
                        ' Attempt to change the view to VTable
                        pRefType = %NULL
                        hr = pITypeInfo.GetRefTypeOfImplType(-1, pRefType)
                        IF hr = %S_OK AND pRefType <> %NULL THEN
                           hr = pITypeInfo.GetRefTypeInfo(pRefType, pRefTypeInfo)
                           IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                              pRefTypeAttr = %NULL
                              hr = pRefTypeInfo.GetTypeAttr(pRefTypeAttr)
                              ' Enumerate the functions
                              IF hr <> %S_OK OR pRefTypeAttr = %NULL THEN
                                 TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE)
                              ELSE
                                 TLB_EnumFunctions(hWnd, pRefTypeAttr, pRefTypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE)
                                 pRefTypeInfo.ReleaseTypeAttr pRefTypeAttr
                                 pRefTypeAttr = %NULL
                              END IF
                              pRefTypeInfo = NOTHING
                           END IF
                        ELSE
                           TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE)
                        END IF
                     END IF
                  ELSEIF pTKind = %TKIND_DISPATCH THEN
                     TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE)
                  ELSE
                     bIsUnknown = %TRUE
                     TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE)
                  END IF
               END IF
               ' Select the root node as the first visible
               TreeView_SelectSetFirstVisible(hTreeView, hRoot)
            ELSE
               idx = 0
               ARRAY SCAN TLB_EventsArray(), = szInterfaceName, TO idx
               IF ISFALSE idx THEN
                  IF pTKind = %TKIND_INTERFACE OR (pTKind = %TKIND_DISPATCH AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL) THEN
                     IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                        strInheritedInterface = TLB_GetInheritedInterface(pITypeInfo, -1)
                     ELSE
                        strInheritedInterface = TLB_GetImplementedInterface(pITypeInfo)
                     END IF
                     strOrigInheritedInt = strInheritedInterface
                     TLB_AddLine("' ########################################################################################")
                     TLB_AddLine("' Interface name = " & szInterfaceName)
                     szText = GUIDTXT$(@pTypeAttr.guid)
                     IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID = " & szText)
                     szText = bstrDocString
                     REPLACE ANY $CR & $LF WITH "  " IN szText
                     IF LEN(szText) THEN TLB_AddLine("' " & szText)
                     IF @pTypeAttr.wTypeFlags THEN TLB_AddLine("' Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
                     IF LEN(strInheritedInterface) THEN TLB_AddLine("' Inherited interface = " & strInheritedInterface)
                     TLB_AddLine("' ########################################################################################")
                     TLB_AddLine("")
                     IF LEFT$(szInterfaceName, 1) = "_" THEN szInterfaceName = MID$(szInterfaceName, 2)
                     IF LEFT$(strInheritedInterface, 1) = "_" THEN strInheritedInterface = MID$(strInheritedInterface, 2)
                     strPrefix = ""
                     IF m_UsePrefix = %BST_CHECKED THEN strPrefix = TLB_PrefixStr
                     TLB_AddLine("#IF NOT %DEF(%" & strPrefix & szInterfaceName & "_INTERFACE_DEFINED)")
                     TLB_AddLine("    %" & strPrefix & szInterfaceName & "_INTERFACE_DEFINED = 1")
                     TLB_AddLine("")
                     strIID = "$IID_"
                     strText = szOrigInterfaceName
                     DO
                        IF LEFT$(strText, 1) <> "_" THEN EXIT DO
                        strIID += "_"
                        strText = MID$(strText, 2)
                     LOOP
                     strIID = strIID & strPrefix & strText
'                     strImplInterface = UCASE$(TLB_GetImplementedInterface(pITypeInfo, 0))
                     IF strImplInterface = "" THEN
                        TLB_AddLine("'INTERFACE " & strPrefix & szInterfaceName & " " & strIID)
                     ELSE
                        TLB_AddLine("INTERFACE " & strPrefix & szInterfaceName & " " & strIID)
                     END IF
                     TLB_AddLine("")
                     strIntName = ""
                     IF strImplInterface = "" THEN
                        TLB_AddLine("   ' Invalid interface")
                        TLB_AddLine("   ' Interface does not inherit a base class")
                        TLB_AddLine("")
                     ELSEIF strImplInterface = "IUNKNOWN" THEN
                        IF m_UseAutomationView THEN
                           ' Force IUnknown interfaces to be treated as IAutomation interfaces
                           m_IAutomation = %TRUE
                        END IF
                        IF m_IAutomation THEN   ' OleAutomation only
                           TLB_AddLine("   INHERIT IAutomation")
                        ELSE
                           TLB_AddLine("   INHERIT IUnknown")
                        END IF
                        TLB_AddLine("")
                     ELSEIF strImplInterface = "IDISPATCH" THEN
'                        TLB_AddLine("   INHERIT DUAL")
                        TLB_AddLine("   INHERIT IDispatch")
                        TLB_AddLine("")
                     ELSE
                        IF ISTRUE m_IAutomation THEN
                           TLB_AddLine("   INHERIT IAutomation")
                        ELSEIF UCASE$(strBaseClass) = "IUNKNOWN" AND ISTRUE m_UseAutomationView THEN
                           ' Force IUnknown interfaces to be treated as IAutomation interfaces
                           m_IAutomation = %TRUE
                           TLB_AddLine("   INHERIT IAutomation")
                        ELSE
                           IF UCASE$(strBaseClass) = "IDISPATCH" THEN
'                              TLB_AddLine("   INHERIT DUAL")
                              TLB_AddLine("   INHERIT IDispatch")
                           ELSE
                              TLB_AddLine("   INHERIT " & strBaseClass)
                           END IF
                        END IF
                        strImplInterface = UCASE$(strBaseClass)
                        TLB_AddLine("")
                     END IF
                     IF strImplInterface <> "" THEN
                        IF pTKind = %TKIND_DISPATCH AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                           IF ISTRUE m_UseAutomationView THEN
                              IF strImplInterface <> "IDISPATCH" THEN
                                 old_UsePropGetSet = m_UsePropGetSet
                                 m_UsePropGetSet = %FALSE
                                 TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %TRUE, strIntName)
                                 m_UsePropGetSet = old_UsePropGetSet
                              ELSE
                                 TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %TRUE, strIntName)
                              END IF
                           ELSE
                              ' Attempt to change the view to VTable
                              pRefType = %NULL
                              hr = pITypeInfo.GetRefTypeOfImplType(-1, pRefType)
                              IF hr = %S_OK AND pRefType <> %NULL THEN
                                 hr = pITypeInfo.GetRefTypeInfo(pRefType, pRefTypeInfo)
                                 IF hr = %S_OK AND ISTRUE ISOBJECT(pRefTypeInfo) THEN
                                    pRefTypeAttr = %NULL
                                    hr = pRefTypeInfo.GetTypeAttr(pRefTypeAttr)
                                    ' Enumerate the functions
                                    IF hr <> %S_OK OR pRefTypeAttr = %NULL THEN
                                       IF strImplInterface <> "IDISPATCH" THEN
                                          old_UsePropGetSet = m_UsePropGetSet
                                          m_UsePropGetSet = %FALSE
                                          TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                                          m_UsePropGetSet = old_UsePropGetSet
                                       ELSE
                                          TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                                       END IF
                                    ELSE
                                       ' Enumerate inherited interfaces
                                       IF UCASE$(strOrigInheritedInt) <> "IDISPATCH" THEN
                                          strNewInhInterface = TLB_EnumInheritedInterfaces(hWnd, pITypeLib, strOrigInheritedInt, fFlags, bIsUnknown)
                                          ' If the returned interface name is the same, it must be an external interface
                                          IF strNewInhInterface = strOrigInheritedInt THEN
                                             TLB_EnumExternalInterfaces(hWnd, pRefTypeInfo, strOrigInheritedInt, fFlags, bIsUnknown)
                                          END IF
                                          IF @pRefTypeAttr.cFuncs THEN
                                             TLB_AddLine("   ' =====================================================================================")
                                             TLB_AddLine("   ' " & szInterfaceName & " Methods")
                                          END IF
                                       END IF
                                       IF strImplInterface <> "IDISPATCH" THEN
                                          old_UsePropGetSet = m_UsePropGetSet
                                          m_UsePropGetSet = %FALSE
                                          TLB_EnumFunctions(hWnd, pRefTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                                          m_UsePropGetSet = old_UsePropGetSet
                                       ELSE
                                          TLB_EnumFunctions(hWnd, pRefTypeAttr, pRefTypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                                       END IF
                                       pRefTypeInfo.ReleaseTypeAttr pRefTypeAttr
                                       pRefTypeAttr = 0
                                    END IF
                                    pRefTypeInfo = NOTHING
                                 END IF
                              ELSE
                                 IF strImplInterface <> "IDISPATCH" THEN
                                    old_UsePropGetSet = m_UsePropGetSet
                                    m_UsePropGetSet = %FALSE
                                    TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                                    m_UsePropGetSet = old_UsePropGetSet
                                 ELSE
                                    TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                                 END IF
                              END IF
                           END IF
                        ELSEIF pTKind = %TKIND_INTERFACE THEN
                           ' Check also for IDispatch because some servers have interfaces that inherit from IDispatch
                           IF strImplInterface <> "IDISPATCH" THEN bIsUnknown = %TRUE
                           ' IAutomation interfaces inherit from IUnknown but follows the rules of Automation.
                           IF m_IAutomation THEN bIsUnknown = %FALSE
                           ' If it inherits from another interface, search first its methods
                           IF UCASE$(strOrigInheritedInt) <> "IDISPATCH" AND UCASE$(strOrigInheritedInt) <> "IUNKNOWN" THEN
                              strNewInhInterface = TLB_EnumInheritedInterfaces(hWnd, pITypeLib, strOrigInheritedInt, fFlags, bIsUnknown)
                              ' If the returned interface name is the same, it must be an external interface
                              IF strNewInhInterface = strOrigInheritedInt THEN
                                 TLB_EnumExternalInterfaces(hWnd, pITypeInfo, strOrigInheritedInt, fFlags, bIsUnknown)
                              END IF
                              IF @pTypeAttr.cFuncs THEN
                                 TLB_AddLine("   ' =====================================================================================")
                                 TLB_AddLine("   ' " & szInterfaceName & " Methods")
                              END IF
                           END IF
                           IF strImplInterface <> "IDISPATCH" AND ISFALSE m_IAutomation THEN
                              old_UsePropGetSet = m_UsePropGetSet
                              m_UsePropGetSet = %FALSE
                              TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                              m_UsePropGetSet = old_UsePropGetSet
                           ELSE
                              TLB_EnumFunctions(hWnd, pTypeAttr, pITypeInfo, hRoot, %TRUE, IIF&(bIsUnknown = %TRUE, %CODEGEN_CSTYLE, %CODEGEN_VBSTYLE), bViewOnly, bIsUnknown, %FALSE, strIntName)
                           END IF
                        END IF
                     END IF
                     IF strImplInterface = "" THEN
                        TLB_AddLine("'END INTERFACE")
                     ELSE
                        TLB_AddLine("END INTERFACE")
                     END IF
                     TLB_AddLine("")
                     TLB_AddLine("#ENDIF   ' /* __" & strPrefix & szInterfaceName & "_INTERFACE_DEFINED__ */")
                     TLB_AddLine("")
                  END IF  ' IF pTKind = %TKIND_INTERFACE...
                  ' -------------------------------------------------------------------------------
                  ' If the mixed option is checked, generate IDBIND interface declarations for all
                  ' the dispatch only interfaces.
                  ' -------------------------------------------------------------------------------
'                  IF pTKind = %TKIND_DISPATCH AND ISTRUE m_MixDispInterfaces THEN
                  IF ISTRUE m_MixDispInterfaces AND pTKind = %TKIND_DISPATCH AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) <> %TYPEFLAG_FDUAL THEN
                     IF @pTypeAttr.cFuncs > 0 OR @pTypeAttr.cVars > 0 THEN
                        strPrefix = ""
                        IF m_UsePrefix = %BST_CHECKED THEN strPrefix = TLB_PrefixStr
                        ' -------------------------------------------------------------------------
                        ' Information about the interface
                        ' -------------------------------------------------------------------------
                        strCoClassName = TLB_GetCoClassNameFromArray(szInterfaceName)
                        TLB_AddLine("' ########################################################################################")
                        IF LEN(strCoClassName) THEN TLB_AddLine("' CoClass name = " & strCoClassName)
                        TLB_AddLine("' Interface name = " & szInterfaceName)
                        szText = GUIDTXT$(@pTypeAttr.guid)
                        IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID = " & szText)
                        szText = bstrDocString
                        REPLACE ANY $CR & $LF WITH "  " IN szText
                        IF LEN(szText) THEN TLB_AddLine("' " & szText)
                        IF @pTypeAttr.wTypeFlags THEN TLB_AddLine("' Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
                        ' For dual interfaces, you obtain the base type of the interface with GetRefTypeOfImplType(-1).
                        IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                           strImplInterface = TLB_GetInheritedInterface(pITypeInfo, -1)
                        ELSE
                           strImplInterface = TLB_GetImplementedInterface(pITypeInfo)
                        END IF
                        IF LEN(strImplInterface) THEN TLB_AddLine("' Inherited interface = " & strImplInterface)
                        TLB_AddLine("' ########################################################################################")
                        TLB_AddLine("")
                        IF LEFT$(szInterfaceName, 1) = "_" THEN szInterfaceName = MID$(szInterfaceName, 2)
                        TLB_AddLine("#IF NOT %DEF(%" & strPrefix & szInterfaceName & "_DISPINTERFACE_DEFINED)")
                        TLB_AddLine("    %" & strPrefix & szInterfaceName & "_DISPINTERFACE_DEFINED = 1")
                        TLB_AddLine("")
'                        IF LEN(strCoClassName) THEN
'                           TLB_AddLine("INTERFACE IDBIND " & strPrefix & strCoClassName)
'                        ELSE
'                           TLB_AddLine("INTERFACE IDBIND " & strPrefix & szInterfaceName)
'                        END IF
                           TLB_AddLine("INTERFACE IDBIND " & strPrefix & szInterfaceName)
                     END IF
                     ' Enumerate the methods and properties
                     IF @pTypeAttr.cFuncs > 0 THEN
                        TLB_MakePBDefinitionCode(hWnd, pTKind, pITypeLib, pITypeInfo, pTypeAttr)
                     END IF
                     ' Enumerate the data members
                     IF @pTypeAttr.cVars > 0 THEN
                        TLB_PBInterfaceDataMembers(hWnd, pITypeInfo, @pTypeAttr.cVars)
                     END IF
                     ' Interface footer
                     IF @pTypeAttr.cFuncs > 0 OR @pTypeAttr.cVars > 0 THEN
                        TLB_AddLine("END INTERFACE")
                        TLB_AddLine("")
                        TLB_AddLine("#ENDIF   ' /* __" & strPrefix & szInterfaceName & "_DISPINTERFACE_DEFINED__ */")
                        TLB_AddLine("")
                     END IF
                  END IF
               END IF  ' IF ISFALSE idx
            END IF
         END IF
      END IF
      ' ==================================================================================

      ' --- Releases the TYPEATTR structure ----------------------------------------------
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0

      ' --- Releases the TypeInfo interface ----------------------------------------------
      pITypeInfo = NOTHING

   NEXT
   ' =====================================================================================

Terminate:

   IF ISTRUE m_Abort THEN
      ' Arrow cursor
      MOUSEPTR 1
      ' Clear buffer and flags
      m_Busy = %FALSE
      m_Abort = %FALSE
      EXIT FUNCTION
   END IF

   ' --- Releases the interfaces ---------------------------------------------------------
   IF ISTRUE pTypeAttr THEN
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
   END IF
   pITypeInfo = NOTHING
   pITypeLib = NOTHING

   IF fFlags = %REPORT_VIEWONLY THEN
      ' --- Expands the root node --------------------------------------------------------
      TreeView_Expand(hTreeView, hRoot, %TVE_EXPAND)
      ' --- Enables redraw and repaints the control --------------------------------------
      SendMessage hTreeView, %WM_SETREDRAW, %TRUE, 0
      InvalidateRect hTreeView, BYVAL %NULL, %TRUE
      UpdateWindow hTreeView
   ELSE
      ' --- Show the report --------------------------------------------------------------
      IF (fFlags AND %REPORT_VIEWCODE) = %REPORT_VIEWCODE THEN
         ' Add definitions for StdFont and StdPicture interfaces if needed
         IF ISTRUE m_MixDispInterfaces THEN
            IF ISTRUE TLB_UsesFontInterface THEN TLB_AddStdFontDefinition(strPrefix)
            IF ISTRUE TLB_UsesPictureInterface THEN TLB_AddStdPictureDefinition(strPrefix)
         END IF
         ' Fill the richedit box with the generated code
         hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_CODE)
         IF hPageCtrl THEN
            hRichEditBox = GetDlgItem(hPageCtrl, %IDC_DIALOG1_RICHEDIT_VIEWCODE)
            szText = ""
            SendMessage hRichEditBox, %WM_SETTEXT, 0, VARPTR(szText)
            m_Buffer = LEFT$(m_Buffer, m_BufLen)
            SendMessage hRichEditBox, %WM_SETTEXT, 0, STRPTR(m_Buffer)
         END IF
         ' Hide the Options tab
         hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS)
         IF hPageCtrl THEN ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS), %SW_HIDE
         ' Hide the Trees tab and show the Code tab
         hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
         IF hPageCtrl THEN
            ' Hides all the pages excepting the Code page
            ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_GRID), %SW_HIDE
            ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_TREES), %SW_HIDE
            ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS), %SW_HIDE
            ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_CODE), %SW_SHOW
            SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_SETCURSEL, 2, 0
            SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_SETCURFOCUS, 2, 0
         END IF
         SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
'         SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%FALSE, 0))
'         SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%TRUE, 0))
         hMenu = GetMenu(hWnd)
         hSubmenu = GetSubMenu(hMenu, 0)
         CoolMenu_EnableMenuItem hSubMenu, %IDM_RELOAD, %MF_GRAYED
         CoolMenu_EnableMenuItem hSubMenu, %IDM_SAVE, %MF_ENABLED
'         CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
         SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_CODE))
      END IF
   END IF

   ' Clear buffer and flags
   m_Busy = %FALSE
   m_Abort = %FALSE

   IF (fFlags AND %REPORT_CODEONLY) <> %REPORT_CODEONLY THEN
      m_Buffer = ""
      m_BufLen = 0
   END IF

   FUNCTION = %TRUE

END FUNCTION
' ########################################################################################

' ########################################################################################
' Enumeration dispatcher
' ########################################################################################
FUNCTION TLB_Enumerate ( _
   BYVAL hWnd                  AS DWORD _              ' // Handle of the main window
 , BYVAL strItemName           AS STRING _             ' // Item to retrieve
 , BYVAL nItemType             AS LONG _               ' // Item type
 , BYVAL fFlags                AS LONG _               ' // Flags
   ) AS LONG

   m_Buffer = ""
   m_BufLen = 0

   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_STOP, MAKLNG(%TRUE, 0))

   ' Report header
   TLB_LibraryHeader(nItemType)

   SELECT CASE nItemType
      CASE %ENUM_ALL
         TLB_EnumCoClasses(hWnd, "ALL", nItemType, %REPORT_CODEONLY)
         TLB_EnumIdentifiers(hWnd)
         TLB_EnumTypeLibs(hWnd, strItemName, %ENUM_CONSTANTS, %REPORT_CODEONLY)
         TLB_EnumTypeLibs(hWnd, strItemName, %ENUM_RECORDS, %REPORT_CODEONLY)
         TLB_EnumTypeLibs(hWnd, strItemName, %ENUM_INTERFACES, %REPORT_CODEONLY OR %REPORT_VIEWCODE)
      CASE ELSE
         TLB_EnumTypeLibs(hWnd, strItemName, nItemType, fFlags)
   END SELECT

   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_STOP, MAKLNG(%FALSE, 0))

   m_Buffer = ""
   m_BufLen = 0

END FUNCTION
' ########################################################################################
