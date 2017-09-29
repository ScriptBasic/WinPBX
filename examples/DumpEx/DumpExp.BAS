#COMPILE EXE
#INCLUDE "win32api.inc"

GLOBAL hDlg                             AS LONG
GLOBAL fNo AS LONG

%IMAGE_DOS_SIGNATURE                    = &H5A4D
%IMAGE_NT_SIGNATURE                     = &H00004550
%IMAGE_SIZEOF_SHORT_NAME                = 8
%IMAGE_SIZEOF_SECTION_HEADER            = 40
%IMAGE_ORDINAL_FLAG                     = &H80000000

UNION MISC
    PhysicalAddress                     AS DWORD
    VirtualSize                         AS DWORD
END UNION

'TYPE IMAGE_DATA_DIRECTORY
'  VirtualAddress                        AS DWORD
'  nSize                                 AS DWORD
'END TYPE

'TYPE IMAGE_FILE_HEADER
'  Machine                               AS WORD
'  NumberOfSections                      AS WORD
'  TimeDateStamp                         AS DWORD
'  PointerToSymbolTable                  AS DWORD
'  NumberOfSymbols                       AS DWORD
'  SizeOfOptionalHeader                  AS WORD
'  Characteristics                       AS WORD
'END TYPE

'TYPE IMAGE_NT_HEADERS
'  Signature                             AS DWORD
'  FileHeader                            AS IMAGE_FILE_HEADER
'  OptionalHeader                        AS IMAGE_OPTIONAL_HEADER
'END TYPE

'TYPE IMAGE_IMPORT_DESCRIPTOR
'    OriginalFirstThunk                  AS DWORD
'    TimeDateStamp                       AS DWORD
'    ForwarderChain                      AS DWORD
'    Name_                               AS DWORD
'    FirstThunk                          AS DWORD
'END TYPE

'TYPE IMAGE_IMPORT_BY_NAME
'    Hint                                AS WORD
'    Name_                               AS BYTE
'END TYPE

'UNION u1    DWORD
'    ForwarderString                     AS BYTE PTR
'    pFunction                           AS DWORD PTR
'    Ordinal                             AS DWORD
'    AddressOfData                       AS DWORD
'END UNION

'TYPE IMAGE_THUNK_DATA
'    u1                                  AS u1
'END TYPE

TYPE IMAGE_DOS_HEADER
  e_magic                               AS WORD
  e_cblp                                AS WORD
  e_cp                                  AS WORD
  e_crlc                                AS WORD
  e_cparhdr                             AS WORD
  e_minalloc                            AS WORD
  e_maxalloc                            AS WORD
  e_ss                                  AS WORD
  e_sp                                  AS WORD
  e_csum                                AS WORD
  e_ip                                  AS WORD
  e_cs                                  AS WORD
  e_lfarlc                              AS WORD
  e_ovno                                AS WORD
  e_res(3)                              AS WORD
  e_oemid                               AS WORD
  e_oeminfo                             AS WORD
  e_res2(9)                             AS WORD
  e_lfanew                              AS LONG
END TYPE

FUNCTION PtrToString(BYVAL inPtr AS BYTE PTR) AS STRING

    DIM i                               AS LONG
    DIM s                               AS STRING

    DO WHILE @inPtr[i] <> 0
        s = s + CHR$(@inPtr[i])
        INCR i
    LOOP

    FUNCTION = s

END FUNCTION

FUNCTION IMAGE_FIRST_SECTION(BYVAL pNTHeader AS IMAGE_NT_HEADERS PTR) AS DWORD

    FUNCTION =  pNTHeader + 24 + @pNTHeader.FileHeader.SizeOfOptionalHeader

END FUNCTION

FUNCTION GetEnclosingSectionHeader(BYVAL rva AS DWORD, BYVAL pNTHeader AS IMAGE_NT_HEADERS PTR) AS DWORD

    DIM section                         AS IMAGE_SECTION_HEADER PTR
    DIM i                               AS LONG

    section = IMAGE_FIRST_SECTION(BYVAL pNTHeader)

    FOR i=0 TO @pNTHeader.FileHeader.NumberOfSections
        IF ( (rva >= @section.VirtualAddress) AND (rva < (@section.VirtualAddress + @section.Misc.VirtualSize))) THEN
            FUNCTION = section
            EXIT FUNCTION
        END IF
        section = section + SIZEOF(@section)
    NEXT

END FUNCTION

FUNCTION DumpImportsSection(BYVAL pBase AS DWORD, BYVAL pNTHeader AS IMAGE_NT_HEADERS PTR) AS LONG

    DIM pHeader                         AS IMAGE_SECTION_HEADER PTR
    DIM pImportDesc                     AS IMAGE_IMPORT_DESCRIPTOR PTR
    DIM pThunk                          AS IMAGE_THUNK_DATA32 PTR
    DIM delta                           AS LONG
    DIM importsStartRVA                 AS DWORD
    DIM importsEndRVA                   AS DWORD
    DIM entryPointRVA                   AS DWORD
    DIM exportsStartRVA                 AS DWORD
    DIM exportsEndRVA                   AS DWORD
    DIM i                               AS DWORD
    DIM j                               AS DWORD
    DIM sFunctionName                   AS ASCIIZ * 512
    DIM sDll                            AS ASCIIZ * 512

    importsStartRVA = @pNTHeader.OptionalHeader.DataDirectory(%IMAGE_DIRECTORY_ENTRY_IMPORT).VirtualAddress
    importsEndRVA = importsStartRVA + @pNTHeader.OptionalHeader.DataDirectory(%IMAGE_DIRECTORY_ENTRY_IMPORT).nSize

    pHeader = GetEnclosingSectionHeader( importsStartRVA, BYVAL pNTHeader )

    IF pHeader = 0 THEN
        EXIT FUNCTION
    END IF

    delta = @pHeader.VirtualAddress - @pHeader.PointerToRawData
    pImportDesc = pBase + importsStartRVA - delta

    i = 0
    DO
        IF (@pImportDesc[i].TimeDateStamp = 0) AND (@pImportDesc[i].Name = 0 ) THEN
            EXIT DO
        END IF
        sDll = PtrToString(BYVAL @pImportDesc[i].Name - delta + pBase)
        CONTROL SEND hDlg, 1007, %LB_INSERTSTRING, -1&, VARPTR(sDll)
        j = 0
        pThunk = @pImportDesc[i].FirstThunk - delta + pBase

        exportsStartRVA = @pHeader.VirtualAddress
        exportsEndRVA= exportsStartRVA + @pHeader.SizeOfRawData

        IF (pThunk <= exportsStartRVA) OR (pThunk >= exportsEndRVA) THEN
            IF (@pImportDesc[i].OriginalFirstThunk = 0) THEN
                EXIT FUNCTION
            END IF
            pThunk = @pImportDesc[i].OriginalFirstThunk
            IF (pThunk <= exportsStartRVA) OR (pThunk >= exportsEndRVA) THEN
                EXIT FUNCTION
            END IF
            pThunk = pThunk - delta + pBase
        END IF

        DO
            IF (@pThunk[j].AddressOfData = 0) THEN
                EXIT DO
            END IF
            IF (@pThunk[j].Ordinal AND %IMAGE_ORDINAL_FLAG) THEN
                sFunctionName = "    #" + FORMAT$(@pThunk[j].Ordinal AND &HFFFF??)
            ELSE
                sFunctionName = "    " + PtrToString(BYVAL @pThunk[j].AddressOfData - delta + pBase + 2)
            END IF
            CONTROL SEND hDlg, 1007, %LB_INSERTSTRING, -1&, VARPTR(sFunctionName)
            INCR j
        LOOP
        INCR i
    LOOP

END FUNCTION

FUNCTION DumpExportsSection(BYVAL pBase AS DWORD, BYVAL pNTHeader AS IMAGE_NT_HEADERS PTR) AS LONG

    DIM pExportDir                      AS IMAGE_EXPORT_DIRECTORY PTR
    DIM pHeader                         AS IMAGE_SECTION_HEADER PTR
    DIM delta                           AS LONG
    DIM entryPointRVA                   AS DWORD
    DIM exportsStartRVA                 AS DWORD
    DIM exportsEndRVA                   AS DWORD
    DIM pFunctions                      AS DWORD PTR
    DIM pOrdinals                       AS WORD PTR
    DIM pNames                          AS DWORD PTR
    DIM i                               AS DWORD
    DIM j                               AS DWORD
    DIM flag                            AS LONG
    DIM sFunctionName                   AS ASCIIZ * 256

    exportsStartRVA = @pNTHeader.OptionalHeader.DataDirectory(%IMAGE_DIRECTORY_ENTRY_EXPORT).VirtualAddress
    exportsEndRVA = exportsStartRVA + @pNTHeader.OptionalHeader.DataDirectory(%IMAGE_DIRECTORY_ENTRY_EXPORT).nSize

    pHeader = GetEnclosingSectionHeader( exportsStartRVA, BYVAL pNTHeader )

    IF pHeader = 0 THEN
        EXIT FUNCTION
    END IF

    delta = @pHeader.VirtualAddress - @pHeader.PointerToRawData
    pExportDir  = pBASE + exportsStartRVA - delta
    pFunctions  = @pExportDir.AddressOfFunctions    - delta + pBase
    pOrdinals   = @pExportDir.AddressOfNameOrdinals - delta + pBase
    pNames      = @pExportDir.AddressOfNames        - delta + pBase
    FOR i = 0 TO @pExportDir.NumberOfFunctions - 1
        entryPointRVA   = @pFunctions[i]
        j               = 0
        flag            = 0

        IF entryPointRVA <> 0 THEN
            FOR j=0 TO @pExportDir.NumberOfNames - 1
                IF @pOrdinals[j] = i THEN
                    sFunctionName = PtrToString(BYVAL @pNames[j] - delta + pBase)
                    CONTROL SEND hDlg, 1005, %LB_INSERTSTRING, -1&, VARPTR(sFunctionName)
                    ' -------------------------------
                    PRINT #fNo, sFunctionName
                    ' -------------------------------
                    flag    =   1
                END IF
            NEXT
            IF (entryPointRVA >= exportsStartRVA) AND (entryPointRVA <= exportsEndRVA) THEN
                sFunctionName = PtrToString(BYVAL entryPointRVA - delta + pBase)
                flag    =   1
            END IF
        END IF
    NEXT

END FUNCTION

FUNCTION DumpExeFile(BYVAL dosHeader AS IMAGE_DOS_HEADER PTR) AS LONG

    DIM pNTHeader                       AS IMAGE_NT_HEADERS PTR
    DIM pBase                           AS DWORD

    pBase       = dosHeader
    pNTHeader   = dosHeader + @dosHeader.e_lfanew

    CONTROL SEND hDlg, 1005, %LB_RESETCONTENT, 0&, 0&
    CONTROL SEND hDlg, 1007, %LB_RESETCONTENT, 0&, 0&

    IF ( IsBadReadPtr(pNTHeader, SIZEOF(pNTHeader)) OR  @pNTHeader.Signature <> %IMAGE_NT_SIGNATURE ) THEN
        MSGBOX "Unhandled EXE type, or invalid .EXE"
        EXIT FUNCTION
    END IF

    CALL DumpExportsSection(pBase, BYVAL pNTHeader)
    CALL DumpImportsSection(pBase, BYVAL pNTHeader)

END FUNCTION

FUNCTION Dump() AS LONG

    DIM hFile                           AS LONG
    DIM hFileMapping                    AS LONG
    DIM lpFileBase                      AS LONG
    DIM dosHeader                       AS IMAGE_DOS_HEADER PTR
    DIM fName                           AS ASCIIZ * 512

    CONTROL GET TEXT hDlg, 1002 TO fName
    ' --------------------------------------------
    fNo = FREEFILE
    OPEN AfxGetFileName(fName) & ".def" FOR OUTPUT AS fNo
    PRINT #fNo, "LIBRARY " & AfxGetFileNameX(fName)
    PRINT #fNo, "EXPORTS"
    ' --------------------------------------------

    hFile = CreateFile(fName, %GENERIC_READ, %FILE_SHARE_READ, BYVAL 0&, %OPEN_EXISTING, %FILE_ATTRIBUTE_NORMAL, 0)

    IF hFile = %INVALID_HANDLE_VALUE THEN
        MSGBOX "Couldn't open file with CreateFile()"
        EXIT FUNCTION
    END IF

    hFileMapping = CreateFileMapping(hFile, BYVAL 0&, %PAGE_READONLY, 0, 0, BYVAL 0&)
    IF hFileMapping = 0 THEN
        CALL CloseHandle(hFile)
        MSGBOX "Couldn't open file mapping with CreateFileMapping()"
        EXIT FUNCTION
    END IF

    lpFileBase = MapViewOfFile(hFileMapping, %FILE_MAP_READ, 0, 0, 0)
    IF lpFileBase = 0 THEN
        CALL CloseHandle(hFileMapping)
        CALL CloseHandle(hFile)
        MSGBOX "Couldn't map view of file with MapViewOfFile()"
        EXIT FUNCTION
    END IF

    dosHeader = lpFileBase
    IF ( @dosHeader.e_magic = %IMAGE_DOS_SIGNATURE ) THEN
        CALL DumpExeFile(BYVAL dosHeader)
    END IF

    CALL UnmapViewOfFile(lpFileBase)
    CALL CloseHandle(hFileMapping)
    CALL CloseHandle(hFile)

    ' --------------------------------------------
    CLOSE fNo
    ' --------------------------------------------

END FUNCTION

FUNCTION PBMAIN

    DIALOG NEW %HWND_DESKTOP, "Enum Export/Import Functions from an Executable Image", 10, 10, 400, 200, %DS_CENTER OR %WS_SYSMENU TO hDlg
    CONTROL ADD LABEL, hDlg, 1001, "Image Path", 2, 3, 40, 12,
    CONTROL ADD TEXTBOX, hDlg, 1002, "c:\windows\system32\kernel32.dll", 48, 2, 294, 12,
    CONTROL ADD BUTTON, hDlg, 1003, "Enum", 346, 2, 47, 12, CALL Dump()
    CONTROL ADD LABEL, hDlg, 1004, "Exports", 2, 16, 40, 9,
    CONTROL ADD LISTBOX, hDlg, 1005, ,   2, 26, 194, 163,
    CONTROL ADD LABEL, hDlg, 1006, "Imports", 200, 16, 40, 9,
    CONTROL ADD LISTBOX, hDlg, 1007, , 200, 26, 194, 163,

    DIALOG SHOW MODAL hDlg

END FUNCTION
