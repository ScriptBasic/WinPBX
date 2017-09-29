' ########################################################################################
' TypeLib Browser
' File: TLB_PROCS.INC
' Contents: TypeLib Browser procedures
' Compiler: PowerBASIC for Windows 10
' Headers: Windows API Headers III
' Copyright (c) 2012-2014 José Roca. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Customized message box.
' ========================================================================================
FUNCTION TLB_MsgBox (BYVAL hWnd AS DWORD, BYVAL bstrMessage AS WSTRING, OPTIONAL BYVAL dwStyle AS DWORD, BYVAL bstrCaption AS WSTRING) AS LONG

   LOCAL mbp AS MSGBOXPARAMS
   LOCAL wszCaption AS WSTRINGZ * 256

   wszCaption = "TypeLib Browser"
   IF LEN(bstrCaption) THEN wszCaption = bstrCaption
   IF dwStyle = 0 THEN dwStyle = %MB_OK

   ' // Initializes MSGBOXPARAMS
   mbp.cbSize = SIZEOF(mbp)                 ' // Size of the structure
   mbp.hwndOwner = hWnd                     ' // Handle of main window
   mbp.hInstance = GetModuleHandle("")      ' // Instance of application
   mbp.lpszText = STRPTR(bstrMessage)       ' // Text of the message
   mbp.lpszCaption = VARPTR(wszCaption)     ' // Caption
   mbp.dwStyle = dwStyle OR %MB_USERICON    ' // Style
   mbp.lpszIcon = %IDI_TLB_LOGO_32          ' // Icon identifier in the resource file

   FUNCTION = MessageBoxIndirect(mbp)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts LibFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_LibFlagsToStr (BYVAL iFlags AS INTEGER) AS WSTRING

   LOCAL bstrFlags AS WSTRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %LIBFLAG_FRESTRICTED) = %LIBFLAG_FRESTRICTED THEN bstrFlags += " [Restricted]"
   IF (iFlags AND %LIBFLAG_FCONTROL) = %LIBFLAG_FCONTROL THEN bstrFlags += " [Control]"
   IF (iFlags AND %LIBFLAG_FHIDDEN) = %LIBFLAG_FHIDDEN THEN bstrFlags += " [Hidden]"
   IF (iFlags AND %LIBFLAG_FHASDISKIMAGE) = %LIBFLAG_FHASDISKIMAGE THEN bstrFlags += " [HasDiskImage]"

   FUNCTION = bstrFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts InterfaceFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_InterfaceFlagsToStr (BYVAL iFlags AS INTEGER) AS WSTRING

   LOCAL bstrFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %TYPEFLAG_FAPPOBJECT) = %TYPEFLAG_FAPPOBJECT THEN bstrFlags += " [Application]"
   IF (iFlags AND %TYPEFLAG_FCANCREATE) = %TYPEFLAG_FCANCREATE THEN bstrFlags += " [Cancreate]"
   IF (iFlags AND %TYPEFLAG_FLICENSED) = %TYPEFLAG_FLICENSED THEN bstrFlags += " [Licensed]"
   IF (iFlags AND %TYPEFLAG_FPREDECLID) = %TYPEFLAG_FPREDECLID THEN bstrFlags += " [Predefined]"
   IF (iFlags AND %TYPEFLAG_FHIDDEN) = %TYPEFLAG_FHIDDEN THEN bstrFlags += " [Hidden]"
   IF (iFlags AND %TYPEFLAG_FCONTROL) = %TYPEFLAG_FCONTROL THEN bstrFlags += " [Control]"
   IF (iFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN bstrFlags += " [Dual]"
   IF (iFlags AND %TYPEFLAG_FNONEXTENSIBLE) = %TYPEFLAG_FNONEXTENSIBLE THEN bstrFlags += " [Nonextensible]"
   IF (iFlags AND %TYPEFLAG_FOLEAUTOMATION) = %TYPEFLAG_FOLEAUTOMATION THEN bstrFlags += " [Oleautomation]"
   IF (iFlags AND %TYPEFLAG_FRESTRICTED) = %TYPEFLAG_FRESTRICTED THEN bstrFlags += " [Restricted]"
   IF (iFlags AND %TYPEFLAG_FAGGREGATABLE) = %TYPEFLAG_FAGGREGATABLE THEN bstrFlags += " [Aggregatable]"
   IF (iFlags AND %TYPEFLAG_FREPLACEABLE) = %TYPEFLAG_FREPLACEABLE THEN bstrFlags += " [Replaceable]"
   IF (iFlags AND %TYPEFLAG_FDISPATCHABLE) = %TYPEFLAG_FDISPATCHABLE THEN bstrFlags += " [Dispatchable]"
   IF (iFlags AND %TYPEFLAG_FREVERSEBIND) = %TYPEFLAG_FREVERSEBIND THEN bstrFlags += " [Reversebind]"
   IF (iFlags AND %TYPEFLAG_FPROXY) = %TYPEFLAG_FPROXY THEN bstrFlags += " [Proxy]"

   FUNCTION = bstrFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts ImplTypeFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_ImplTypeFlagsToStr (BYVAL iFlags AS INTEGER) AS WSTRING

   LOCAL bstrFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %IMPLTYPEFLAG_FDEFAULT) = %IMPLTYPEFLAG_FDEFAULT THEN bstrFlags += " [Default]"
   IF (iFlags AND %IMPLTYPEFLAG_FSOURCE) = %IMPLTYPEFLAG_FSOURCE THEN bstrFlags += " [Source]"
   IF (iFlags AND %IMPLTYPEFLAG_FRESTRICTED) = %IMPLTYPEFLAG_FRESTRICTED THEN bstrFlags += " [Restricted]"
   IF (iFlags AND %IMPLTYPEFLAG_FDEFAULTVTABLE) = %IMPLTYPEFLAG_FDEFAULTVTABLE THEN bstrFlags += " [Default VTable]"

   FUNCTION = bstrFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts FuncFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_FuncFlagsToStr (BYVAL iFlags AS INTEGER) AS WSTRING

   LOCAL bstrFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %FUNCFLAG_FRESTRICTED) = %FUNCFLAG_FRESTRICTED THEN bstrFlags += " [Restricted]"
   IF (iFlags AND %FUNCFLAG_FSOURCE) = %FUNCFLAG_FSOURCE THEN bstrFlags += " [Source]"
   IF (iFlags AND %FUNCFLAG_FBINDABLE) = %FUNCFLAG_FBINDABLE THEN bstrFlags += " [Bindable]"
   IF (iFlags AND %FUNCFLAG_FREQUESTEDIT) = %FUNCFLAG_FREQUESTEDIT THEN bstrFlags += " [RequestEdit]"
   IF (iFlags AND %FUNCFLAG_FDISPLAYBIND) = %FUNCFLAG_FDISPLAYBIND THEN bstrFlags += " [DisplayBind]"
   IF (iFlags AND %FUNCFLAG_FDEFAULTBIND) = %FUNCFLAG_FDEFAULTBIND THEN bstrFlags += " [DefaultBind]"
   IF (iFlags AND %FUNCFLAG_FHIDDEN) = %FUNCFLAG_FHIDDEN THEN bstrFlags += " [Hidden]"
   IF (iFlags AND %FUNCFLAG_FUSESGETLASTERROR) = %FUNCFLAG_FUSESGETLASTERROR THEN bstrFlags += " [UsesGetLastError]"
   IF (iFlags AND %FUNCFLAG_FDEFAULTCOLLELEM) = %FUNCFLAG_FDEFAULTCOLLELEM THEN bstrFlags += " [DefaultCollELem]"
   IF (iFlags AND %FUNCFLAG_FUIDEFAULT) = %FUNCFLAG_FUIDEFAULT THEN bstrFlags += " [UserInterfaceDefault]"
   IF (iFlags AND %FUNCFLAG_FNONBROWSABLE) = %FUNCFLAG_FNONBROWSABLE THEN bstrFlags += " [NonBrowsable]"
   IF (iFlags AND %FUNCFLAG_FREPLACEABLE) = %FUNCFLAG_FREPLACEABLE THEN bstrFlags += " [Replaceable]"
   IF (iFlags AND %FUNCFLAG_FIMMEDIATEBIND) = %FUNCFLAG_FIMMEDIATEBIND THEN bstrFlags += " [InmediateBind]"

   FUNCTION = bstrFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts ParamFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_ParamflagsToStr (BYVAL iFlags AS INTEGER) AS WSTRING

   LOCAL bstrFlags AS STRING

   IF iFlags = 0 THEN FUNCTION = " [None]" : EXIT FUNCTION
   IF (iFlags AND %PARAMFLAG_FOPT) = %PARAMFLAG_FOPT THEN bstrFlags += " [opt]"
   IF (iFlags AND %PARAMFLAG_FRETVAL) = %PARAMFLAG_FRETVAL THEN bstrFlags += " [retval]"
   IF (iFlags AND %PARAMFLAG_FIN) = %PARAMFLAG_FIN THEN bstrFlags += " [in]"
   IF (iFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT THEN bstrFlags += " [out]"
   IF (iFlags AND %PARAMFLAG_FLCID) = %PARAMFLAG_FLCID THEN bstrFlags += " [lcid]"
   IF (iFlags AND %PARAMFLAG_FHASDEFAULT) = %PARAMFLAG_FHASDEFAULT THEN bstrFlags += " [hasdefault]"
   IF (iFlags AND %PARAMFLAG_FHASCUSTDATA) = %PARAMFLAG_FHASCUSTDATA THEN bstrFlags += " [hascustdata]"

   FUNCTION = bstrFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts VarFlags to a descriptive string.
' ========================================================================================
FUNCTION TLB_VarFlagsToStr (BYVAL iFlags AS INTEGER) AS WSTRING

   LOCAL bstrFlags AS STRING

   IF iFlags = 0 THEN bstrFlags = " [None]"
   IF (iFlags AND %VARFLAG_FREADONLY) = %VARFLAG_FREADONLY THEN bstrFlags += " [ReadOnly]"
   IF (iFlags AND %VARFLAG_FSOURCE) = %VARFLAG_FSOURCE THEN bstrFlags += " [Source]"
   IF (iFlags AND %VARFLAG_FBINDABLE) = %VARFLAG_FBINDABLE THEN bstrFlags += " [Bindable]"
   IF (iFlags AND %VARFLAG_FREQUESTEDIT) = %VARFLAG_FREQUESTEDIT THEN bstrFlags += " [RequestEdit]"
   IF (iFlags AND %VARFLAG_FDISPLAYBIND) = %VARFLAG_FDISPLAYBIND THEN bstrFlags += " [DisplayBind]"
   IF (iFlags AND %VARFLAG_FDEFAULTBIND) = %VARFLAG_FDEFAULTBIND THEN bstrFlags += " [DefaultBind]"
   IF (iFlags AND %VARFLAG_FHIDDEN) = %VARFLAG_FHIDDEN THEN bstrFlags += " [Hidden]"
   IF (iFlags AND %VARFLAG_FRESTRICTED) = %VARFLAG_FRESTRICTED THEN bstrFlags += " [Restricted]"
   IF (iFlags AND %VARFLAG_FDEFAULTCOLLELEM) = %VARFLAG_FDEFAULTCOLLELEM THEN bstrFlags += " [DefaultCollElem]"
   IF (iFlags AND %VARFLAG_FUIDEFAULT) = %VARFLAG_FUIDEFAULT THEN bstrFlags += " [User interface default]"
   IF (iFlags AND %VARFLAG_FNONBROWSABLE) = %VARFLAG_FNONBROWSABLE THEN bstrFlags += " [NoBrowsable]"
   IF (iFlags AND %VARFLAG_FREPLACEABLE) = %VARFLAG_FREPLACEABLE THEN bstrFlags += " [Replaceable]"
   IF (iFlags AND %VARFLAG_FIMMEDIATEBIND) = %VARFLAG_FIMMEDIATEBIND THEN bstrFlags += " [ImmediateBind]"

   FUNCTION = bstrFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a type kind to a descriptive string.
' ========================================================================================
FUNCTION TLB_TypeKindToStr (BYVAL dwTypeKind AS DWORD) AS WSTRING

   LOCAL bstrType AS STRING

   SELECT CASE dwTypeKind
      CASE %TKIND_ENUM      : bstrType = "TKIND_ENUM"
      CASE %TKIND_RECORD    : bstrType = "TKIND_RECORD"
      CASE %TKIND_MODULE    : bstrType = "TKIND_MODULE"
      CASE %TKIND_INTERFACE : bstrType = "TKIND_INTERFACE"
      CASE %TKIND_DISPATCH  : bstrType = "TKIND_DISPATCH"
      CASE %TKIND_COCLASS   : bstrType = "TKIND_COCLASS"
      CASE %TKIND_ALIAS     : bstrType = "TKIND_ALIAS"
      CASE %TKIND_UNION     : bstrType = "TKIND_UNION"
   END SELECT

   FUNCTION = bstrType

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the VarType.
' ========================================================================================
FUNCTION TLB_VarTypeToStr (BYVAL VarType AS LONG, OPTIONAL BYVAL fReturnType AS LONG) AS WSTRING

   LOCAL s AS WSTRING

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
FUNCTION TLB_VarTypeToConstant (BYVAL VarType AS LONG) AS WSTRING

   LOCAL s AS WSTRING

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
FUNCTION TLB_VarTypeToKeyword (BYVAL VarType AS LONG, OPTIONAL BYVAL cElements AS WORD) AS WSTRING

   ' Note: VT_I1 is an array of bytes; translate it to a fixed string

   LOCAL s AS WSTRING

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
FUNCTION TLB_GetUnionMemberName (BYVAL vt AS LONG) AS WSTRING

   LOCAL bstrvt AS WSTRING

   SELECT CASE vt
      CASE %VT_I1, %VT_UI1 : bstrvt = "pbVal"
      CASE %VT_I2 : bstrvt = "piVal"
      CASE %VT_I4, %VT_INT, %VT_UI4, %VT_UINT, %VT_HRESULT : bstrvt = "plVal"
      CASE %VT_R4 : bstrvt = "pfltVal"
      CASE %VT_R8, %VT_I8, %VT_UI8 : bstrvt = "pdblVal"
      CASE %VT_BOOL : bstrvt = "pboolVal"
      CASE %VT_ERROR : bstrvt = "pscode"
      CASE %VT_CY : bstrvt = "pcyVal"
      CASE %VT_DATE : bstrvt = "pdate"
      CASE %VT_BSTR : bstrvt = "pbstrVal"
      CASE %VT_UNKNOWN : bstrvt = "ppunkVal"
      CASE %VT_DISPATCH : bstrvt = "ppdispVal"
      CASE %VT_ARRAY : bstrvt = "psArray"
      CASE %VT_VARIANT : bstrvt = "pVariant"
      CASE ELSE : bstrvt = "plVal"
   END SELECT

   FUNCTION = bstrvt

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
FUNCTION TLB_VarToStr (BYVAL pv AS DWORD) AS WSTRING
   LOCAL pvt AS VARIANT PTR
   IF pv = 0 THEN EXIT FUNCTION
   pvt = pv
   FUNCTION = VARIANT$$(@pvt)
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
' Gets the ProgID from the registry.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION TLB_GetProgID (BYVAL bstrGuid AS WSTRING) AS WSTRING
#ELSE
FUNCTION TLB_GetProgID (BYVAL bstrGuid AS WSTRING) AS STRING
#ENDIF

   LOCAL hKey         AS DWORD                  ' // Handle of the opned key
   LOCAL dwIdx        AS DWORD                  ' // Index of the value to be retrieved
#IF %DEF(%UNICODE)
   LOCAL szKey        AS WSTRINGZ * %MAX_PATH   ' // Name of the subkey to open
   LOCAL szKeyValue   AS WSTRINGZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL szValueName  AS WSTRINGZ * %MAX_PATH   ' // Name of the value
#ELSE
   LOCAL szKey        AS ASCIIZ * %MAX_PATH     ' // Name of the subkey to open
   LOCAL szKeyValue   AS ASCIIZ * %MAX_PATH     ' // Buffer that receives the data
   LOCAL szValueName  AS ASCIIZ * %MAX_PATH     ' // Name of the value
#ENDIF
   LOCAL cValueName   AS DWORD                  ' // Size of szValueName
   LOCAL cbData       AS DWORD                  ' // Size of szKeyValue
   LOCAL KeyType      AS DWORD                  ' // Type of data

   szKey = "CLSID\" & bstrGuid & "\ProgID"
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
#IF %DEF(%UNICODE)
FUNCTION TLB_GetVersionIndependentProgID (BYVAL strGuid AS WSTRING) AS WSTRING
#ELSE
FUNCTION TLB_GetVersionIndependentProgID (BYVAL strGuid AS STRING) AS STRING
#ENDIF

   LOCAL hKey         AS DWORD                  ' // Handle of the opned key
   LOCAL dwIdx        AS DWORD                  ' // Index of the value to be retrieved
#IF %DEF(%UNICODE)
   LOCAL szKey        AS WSTRINGZ * %MAX_PATH   ' // Name of the subkey to open
   LOCAL szKeyValue   AS WSTRINGZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL szValueName  AS WSTRINGZ * %MAX_PATH   ' // Name of the value
#ELSE
   LOCAL szKey        AS ASCIIZ * %MAX_PATH     ' // Name of the subkey to open
   LOCAL szKeyValue   AS ASCIIZ * %MAX_PATH     ' // Buffer that receives the data
   LOCAL szValueName  AS ASCIIZ * %MAX_PATH     ' // Name of the value
#ENDIF
   LOCAL cValueName   AS DWORD                  ' // Size of szValueName
   LOCAL cbData       AS DWORD                  ' // Size of szKeyValue
   LOCAL KeyType      AS DWORD                  ' // Type of data

   szKey = "CLSID\" & strGuid & "\VersionIndependentProgID"
   RegOpenKeyEx %HKEY_CLASSES_ROOT, szKey, 0, %KEY_READ, hKey
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
#IF %DEF(%UNICODE)
FUNCTION TLB_GetInprocServer32 (BYVAL strGuid AS WSTRING) AS WSTRING
#ELSE
FUNCTION TLB_GetInprocServer32 (BYVAL strGuid AS STRING) AS STRING
#ENDIF

   LOCAL hKey         AS DWORD                  ' // Handle of the opned key
   LOCAL dwIdx        AS DWORD                  ' // Index of the value to be retrieved
#IF %DEF(%UNICODE)
   LOCAL szKey        AS WSTRINGZ * %MAX_PATH   ' // Name of the subkey to open
   LOCAL szKeyValue   AS WSTRINGZ * %MAX_PATH   ' // Buffer that receives the data
   LOCAL szValueName  AS WSTRINGZ * %MAX_PATH   ' // Name of the value
#ELSE
   LOCAL szKey        AS ASCIIZ * %MAX_PATH     ' // Name of the subkey to open
   LOCAL szKeyValue   AS ASCIIZ * %MAX_PATH     ' // Buffer that receives the data
   LOCAL szValueName  AS ASCIIZ * %MAX_PATH     ' // Name of the value
#ENDIF
   LOCAL cValueName   AS DWORD                  ' // Size of szValueName
   LOCAL cbData       AS DWORD                  ' // Size of szKeyValue
   LOCAL KeyType      AS DWORD                  ' // Type of data

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
' Retrieves the implemented interface.
' ========================================================================================
FUNCTION TLB_GetImplementedInterface (BYVAL pTypeInfo AS ITypeInfo, OPTIONAL BYVAL idx AS LONG) AS WSTRING

   LOCAL hr            AS LONG               ' // HRESULT
   LOCAL pRefType      AS DWORD              ' // Address to a referenced type description
   LOCAL pImplTypeInfo AS ITypeInfo          ' // Implemented interface type info
   LOCAL bstrName      AS WSTRING            ' // Interface's name (unicode)

   hr = pTypeInfo.GetRefTypeOfImplType(idx, pRefType)
   IF hr <> %S_OK OR pRefType = %NULL THEN EXIT FUNCTION
   hr = pTypeInfo.GetRefTypeInfo(pRefType, pImplTypeInfo)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FUNCTION
   pImplTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   pImplTypeInfo = NOTHING
   FUNCTION = bstrName

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the inherited interface
' ========================================================================================
FUNCTION TLB_GetInheritedInterface (BYVAL pTypeInfo AS ITypeInfo, OPTIONAL BYVAL idx AS LONG) AS WSTRING

   LOCAL hr            AS LONG               ' // HRESULT
   LOCAL pRefType      AS DWORD              ' // Address to a referenced type description
   LOCAL pImplTypeInfo AS ITypeInfo          ' // Implied interface type info
   LOCAL pTypeAttr     AS TYPEATTR PTR       ' // Address of a pointer to the TYPEATTR structure

   hr = pTypeInfo.GetRefTypeOfImplType(idx, pRefType)
   IF hr <> %S_OK OR pRefType = %NULL THEN EXIT FUNCTION
   hr = pTypeInfo.GetRefTypeInfo (pRefType, pImplTypeInfo)
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
FUNCTION TLB_GetBaseClass (BYVAL pTypeLib AS ITypeLib, BYVAL bstrItemName AS WSTRING) AS WSTRING

   LOCAL i                      AS LONG                 ' // Loop counter
   LOCAL hr                     AS LONG                 ' // HRESULT
   LOCAL TypeInfoCount          AS LONG                 ' // Number of TypeInfos
   LOCAL pTypeInfo              AS ITypeInfo            ' // TypeInfo interface
   LOCAL pTypeAttr              AS TYPEATTR PTR         ' // Address of a pointer to the TYPEATTR structure
   LOCAL pTKind                 AS DWORD                ' // TYPEKIND
   LOCAL bstrName               AS WSTRING              ' // Member's name (unicode)
   LOCAL bstrDocString          AS WSTRING              ' // Documentation string (unicode)
   LOCAL pdwHelpContext         AS DWORD                ' // Help context
   LOCAL bstrHelpFile           AS WSTRING              ' // Help file (unicode)
   LOCAL bstrInterfaceName      AS WSTRING              ' // Interface name
   LOCAL pRefType               AS DWORD                ' // Address to a referenced type description
   LOCAL pRefTypeInfo           AS ITypeInfo            ' // Referenced TypeInfo interface
   LOCAL pRefTypeAttr           AS TYPEATTR PTR         ' // Referenced TYPEATTR structure
   LOCAL bstrInheritedInterface AS WSTRING              ' // Inherited interface

   TypeInfoCount = pTypeLib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN EXIT FUNCTION

   FOR i = 0 TO TypeInfoCount - 1
      ' // Get the info type
      hr = pTypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN EXIT FOR
      ' // Get the type info
      hr = pTypeLib.GetTypeInfo(i, pTypeInfo)
      IF hr <> %S_OK THEN EXIT FOR
      ' // Get the type attribute
      hr = pTypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN EXIT FOR
      ' // If it is an interface...
      IF pTKind = %TKIND_INTERFACE OR pTKind = %TKIND_DISPATCH THEN
         ' // Get the name of the interface
         hr = pTypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
         ' // If it is the one we are looking for...
         IF bstrName = bstrItemName THEN
            ' // If it inherits from another interface, recursively search the methods
            IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
               bstrInheritedInterface = TLB_GetInheritedInterface(pTypeInfo, -1)
            ELSE
               bstrInheritedInterface = TLB_GetImplementedInterface(pTypeInfo)
            END IF
            ' // Check also that the interface doesn't inherit from itself!
            IF UCASE$(bstrInheritedInterface) <> "IUNKNOWN" AND UCASE$(bstrInheritedInterface) <> "IDISPATCH" AND UCASE$(bstrInheritedInterface) <> UCASE$(bstrName) THEN
               bstrInheritedInterface = TLB_GetBaseClass(pTypeLib, bstrInheritedInterface)
            END IF
         END IF
      END IF
      pTypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0
      pTypeInfo = NOTHING
   NEXT

   IF pTypeAttr THEN pTypeInfo.ReleaseTypeAttr(pTypeAttr)
   pTypeInfo = NOTHING

   FUNCTION = bstrInheritedInterface

END FUNCTION
' ========================================================================================

' ########################################################################################
' IClassFactory2 interface
' IID = B196B28F-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IClassFactory
' ########################################################################################

#IF NOT %DEF(%IClassFactory2_INTERFACE_DEFINED)
    %IClassFactory2_INTERFACE_DEFINED = 1

' // Size = 12 bytes
TYPE LICINFO DWORD
   cbLicInfo        AS DWORD   ' LONG cbLicInfo
   fRuntimeKeyAvail AS LONG    ' BOOL fRuntimeKeyAvail
   fLicVerified     AS LONG    ' BOOL fLicVerified
END TYPE

$IID_IClassFactory2 = GUID$("{B196B28F-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IClassFactory2 $IID_IClassFactory2

   INHERIT IUnknown

   ' =====================================================================================
   ' IClassFactory Methods
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown * pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void ** ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockServer ( _                                ' VTable offset = 16
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IClassFactory2 Methods
   ' =====================================================================================
   METHOD GetLicInfo ( _                                ' VTable offset = 20
     BYREF pLicInfo AS LICINFO _                        ' __in LICINFO * pLicInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestLicKey ( _                             ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pbstrKey AS WSTRING _                        ' __out BSTR * pbstrKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceLic ( _                         ' VTable offset = 28
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown * pUnkOuter
   , BYVAL pUnkReserved AS IUnknown _                   ' __in IUnknown * pUnkReserved
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL bstrKey AS WSTRING _                         ' __in BSTR bstrKey
   , BYREF ppvObject AS IUnknown _                      ' __out void ** ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClassFactory2_INTERFACE_DEFINED__ */

' ========================================================================================
' Retrieves the license key for licensed controls.
' Note: As CoGetClassObject creates an unitialized instance of the server to access the
' IClassFactory2 interface, it can take some time with remote servers such as WSCRIPT.EXE.
' ========================================================================================
FUNCTION TLB_GetRuntimeLicenseKey (BYVAL ProgramID AS STRING) AS STRING

   LOCAL hr                 AS LONG             ' // HRESULT
   LOCAL pIClassFactory2    AS IClassFactory2   ' // IClassFactory2 interface
   LOCAL IID_IClassFactory2 AS GUID             ' // IClassFactory2 GUID
   LOCAL ClassClsid         AS GUID             ' // CLSID
   LOCAL tLicInfo           AS LICINFO          ' // LICINFO structure
   LOCAL bstrLicKey         AS WSTRING          ' // License key

   ' // Retrieve the CLSID associated with the PROGID of the component
   ClassClsid = CLSID$(ProgramID)

   ' // Get a pointer to the IClassFactory2 interface
   IID_IClassFactory2 = $IID_ICLASSFACTORY2
   hr = CoGetClassObject(ClassClsid, %CLSCTX_ALL, BYVAL %NULL, IID_IClassFactory2, pIClassFactory2)
   IF hr <> %S_OK THEN EXIT FUNCTION

   ' // Fill the LICINFO structure
   tLicInfo.cbLicInfo = SIZEOF(tLicInfo)
   hr = pIClassFactory2.GetLicInfo(tLicInfo)

   ' // If there is a runtime key available retrieve it
   IF hr = %S_OK THEN
      IF tLicInfo.fRuntimeKeyAvail THEN
         pIClassFactory2.RequestLicKey(0, bstrLicKey)
         FUNCTION = bstrLicKey
      END IF
   END IF

   ' // Release the interface
   pIClassFactory2 = NOTHING

END FUNCTION
' ========================================================================================
