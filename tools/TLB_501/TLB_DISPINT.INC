' ========================================================================================
' TLB_DISPINT.INC - Include file for the TypeLyb Browser
' (C) 2011 by José Roca. All rights reserved.
' Generates code for dispatch interfaces
' ========================================================================================

' ========================================================================================
' Add the definition of the StdFont interface
' ========================================================================================
SUB TLB_AddStdFontDefinition (BYVAL strPrefix AS STRING)

   TLB_AddLine("' ########################################################################################")
   TLB_AddLine("' CoClass name = StdFont")
   TLB_AddLine("' Interface name = Font")
   TLB_AddLine("' IID = {BEF6E003-A874-101A-8BBA-00AA00300CAB}")
   TLB_AddLine("' Attributes = 4096 [&H1000] [Dispatchable]")
   TLB_AddLine("' Inherited interface = IDispatch")
   TLB_AddLine("' ########################################################################################")
   TLB_AddLine("")
   TLB_AddLine("#IF NOT %DEF(%" & strPrefix & "StdFont_DISPINTERFACE_DEFINED)")
   TLB_AddLine("    %" & strPrefix & "StdFont_DISPINTERFACE_DEFINED = 1")
   TLB_AddLine("")
   TLB_AddLine("INTERFACE IDBIND " & strPrefix & "StdFont")
   TLB_AddLine("   MEMBER GET  Name <0> () AS STRING")
   TLB_AddLine("   MEMBER LET  Name <0> ()   ' Parameter Type AS STRING")
   TLB_AddLine("   MEMBER GET  Size <2> () AS CUR")
   TLB_AddLine("   MEMBER LET  Size <2> ()   ' Parameter Type AS CUR")
   TLB_AddLine("   MEMBER GET  Bold <3> () AS INTEGER")
   TLB_AddLine("   MEMBER LET  Bold <3> ()   ' Parameter Type AS INTEGER")
   TLB_AddLine("   MEMBER GET  Italic <4> () AS INTEGER")
   TLB_AddLine("   MEMBER LET  Italic <4> ()   ' Parameter Type AS INTEGER")
   TLB_AddLine("   MEMBER GET  Underline <5> () AS INTEGER")
   TLB_AddLine("   MEMBER LET  Underline <5> ()   ' Parameter Type AS INTEGER")
   TLB_AddLine("   MEMBER GET  Strikethrough <6> () AS INTEGER")
   TLB_AddLine("   MEMBER LET  Strikethrough <6> ()   ' Parameter Type AS INTEGER")
   TLB_AddLine("   MEMBER GET  Weight <7> () AS INTEGER")
   TLB_AddLine("   MEMBER LET  Weight <7> ()   ' Parameter Type AS INTEGER")
   TLB_AddLine("   MEMBER GET  Charset <8> () AS INTEGER")
   TLB_AddLine("   MEMBER LET  Charset <8> ()   ' Parameter Type AS INTEGER")
   TLB_AddLine("END INTERFACE")
   TLB_AddLine("")
   TLB_AddLine("#ENDIF   ' /* __" & strPrefix & "StdFont_DISPINTERFACE_DEFINED__ */")
   TLB_AddLine("")

END SUB
' ========================================================================================

' ========================================================================================
' Add the definition of the StdPicture interface
' ========================================================================================
SUB TLB_AddStdPictureDefinition (BYVAL strPrefix AS STRING)

   TLB_AddLine("' ########################################################################################")
   TLB_AddLine("' CoClass name = StdPicture")
   TLB_AddLine("' Interface name = Picture")
   TLB_AddLine("' IID = {7BF80981-BF32-101A-8BBB-00AA00300CAB}")
   TLB_AddLine("' Attributes = 4096 [&H1000] [Dispatchable]")
   TLB_AddLine("' Inherited interface = IDispatch")
   TLB_AddLine("' ########################################################################################")
   TLB_AddLine("")
   TLB_AddLine("#IF NOT %DEF(%" & strPrefix & "StdPicture_DISPINTERFACE_DEFINED)")
   TLB_AddLine("    %" & strPrefix & "StdPicture_DISPINTERFACE_DEFINED = 1")
   TLB_AddLine("")
   TLB_AddLine("INTERFACE IDBIND " & strPrefix & "StdPicture")
   TLB_AddLine("   MEMBER CALL Render <6> (IN hdc AS LONG<&H00000000>,  _")
   TLB_AddLine("               IN x AS LONG<1>,  _")
   TLB_AddLine("               IN y AS LONG<2>,  _")
   TLB_AddLine("               IN cx AS LONG<3>,  _")
   TLB_AddLine("               IN cy AS LONG<4>,  _")
   TLB_AddLine("               IN xSrc AS LONG<5>,  _")
   TLB_AddLine("               IN ySrc AS LONG<6>,  _")
   TLB_AddLine("               IN cxSrc AS LONG<7>,  _")
   TLB_AddLine("               IN cySrc AS LONG<8>,  _")
   TLB_AddLine("               IN prcWBounds AS DWORD<9>)")
   TLB_AddLine("   MEMBER GET  Handle <0> () AS LONG   ' OLE_HANDLE")
   TLB_AddLine("   MEMBER GET  hPal <2> () AS LONG   ' OLE_HANDLE")
   TLB_AddLine("   MEMBER LET  hPal <2> ()   ' Parameter Type AS LONG <OLE_HANDLE>")
   TLB_AddLine("   MEMBER GET  Type <3> () AS INTEGER")
   TLB_AddLine("   MEMBER GET  Width <4> () AS LONG   ' OLE_XSIZE_HIMETRIC")
   TLB_AddLine("   MEMBER GET  Height <5> () AS LONG   ' OLE_YSIZE_HIMETRIC")
   TLB_AddLine("END INTERFACE")
   TLB_AddLine("")
   TLB_AddLine("#ENDIF   ' /* __" & strPrefix & "StdPicture_DISPINTERFACE_DEFINED__ */")
   TLB_AddLine("")

END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the CoClass name for the interface from the array
' ========================================================================================
FUNCTION TLB_GetCoClassNameFromArray (BYVAL strInterfaceName AS STRING) AS STRING

   LOCAL idx AS LONG

   strInterfaceName = strInterfaceName & ";"
   IF UBOUND(TLB_DefaultInterfacesArray) > - 1 THEN
      ARRAY SCAN TLB_DefaultInterfacesArray(), FROM 1 TO LEN(strInterfaceName), = strInterfaceName, TO idx
      IF idx THEN
         FUNCTION = PARSE$(TLB_DefaultInterfacesArray(idx - 1), ";", 2)
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates the Datamembers (accessible global or static variables)
' ========================================================================================
SUB TLB_PBInterfaceDataMembers ( _
   BYVAL hWnd AS DWORD, _                    ' // Window handle
   BYVAL ptinfo AS ITypeInfo, _              ' // ITypeInfo interface
   BYVAL cVars AS LONG _                     ' // Number of variables
   )

   LOCAL hr AS DWORD                         ' // HRESULT
   LOCAL pRefTypeInfo AS ITypeInfo           ' // Address to a referenced type description
   LOCAL pVarTypeAttr AS TYPEATTR PTR        ' // Type attribute for the parameter
   LOCAL i AS LONG                           ' // Loop counter
   LOCAL lptdesc AS TYPEDESC PTR             ' // Pointer to a TYPEDESC structure
   LOCAL vt AS WORD                          ' // Variant type
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL pVarDesc AS VARDESC PTR             ' // Pointer to a VARDESC structure
   LOCAL wIndirectionLevel AS WORD           ' // Indirection level
   LOCAL strVarName AS STRING                ' // Variable name
   LOCAL strName AS STRING                   ' // Parameter name
   LOCAL strGet AS STRING                    ' // General purpose variable
   LOCAL strPut AS STRING                    ' // General purpose variable
   LOCAL strAliasName AS STRING              ' // Alias name
   LOCAL szAliasTypeKind AS ASCIIZ * 256     ' // Alias type
   LOCAL typekind AS LONG                    ' // Alias type
   LOCAL szGuid AS ASCIIZ * 256              ' // Guid
   LOCAL strCoClassName AS STRING            ' // CoClassName
   LOCAL strPrefix AS STRING                 ' // Prefix
   LOCAL idx AS LONG                         ' // General purpose variable

   IF m_UsePrefix THEN strPrefix = TLB_PrefixStr

   FOR i = 0 TO cVars - 1

      ' ----------------------------------------------------------------------------------
      ' Allow for a breath and check the abort flag
      ' ----------------------------------------------------------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Gets a reference to the VarDesc interface
      ' ----------------------------------------------------------------------------------
      hr = ptinfo.GetVarDesc(i, pVarDesc)
      IF hr <> %S_OK OR pVarDesc = %NULL THEN EXIT FOR

      ' ----------------------------------------------------------------------------------
      ' Variable name
      ' ----------------------------------------------------------------------------------
      hr = ptinfo.GetDocumentation(@pVarDesc.memid, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
      strVarName = bstrName
      strName = strVarName
      ' ----------------------------------------------------------------------------------

      IF hr = %S_OK AND LEFT$(strName, 1) <> "_" THEN

         ' -------------------------------------------------------------------------------
         ' Resolve the type of the variable
         ' -------------------------------------------------------------------------------
         typekind = 0
         vt = @pVarDesc.elemdescVar.tdesc.vt
         IF vt = %VT_USERDEFINED THEN
            hr = ptinfo.GetRefTypeInfo(@pVarDesc.elemdescVar.tdesc.hreftype, pRefTypeInfo)
            IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
               hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
               IF hr = %S_OK THEN strName = bstrName
               hr = pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
               IF pVarTypeAttr <> %NULL THEN
                  typekind = @pVarTypeAttr.typekind
                  SELECT CASE @pVarTypeAttr.typekind
                     CASE %TKIND_ENUM, %TKIND_MODULE
                        strGet = " AS LONG   ' " & strName
                        strPut = "   ' Parameter Type AS LONG <" & strName & ">"
                     CASE %TKIND_RECORD, %TKIND_UNION
'                        strGet = " AS VARIANT   ' " & strName
'                        strPut = "   ' Parameter Type AS VARIANT <" & strAliasName & ">"
                        strGet = " AS DWORD   ' " & strName
                        strPut = "   ' Parameter Type AS DWORD <" & strName & ">"
                     CASE %TKIND_COCLASS
                        idx = 0
                        ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                        IF idx THEN
                           IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                           strGet = " AS " & strPrefix & strName
                           strPut = "   ' Parameter Type AS " & strPrefix & strName
                        ELSE
                           strGet = " AS IDispatch"
                           strPut = "   ' Parameter Type AS " & strName
                        END IF
                     CASE %TKIND_INTERFACE
                        idx = 0
                        ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                        IF idx THEN
                           IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                           strGet = " AS " & strPrefix & strName
                           strPut = "   ' Parameter Type AS " & strPrefix & strName
                        ELSE
                           strGet = " AS IUnknown"
                           strPut = "   ' Parameter Type AS " & strName
                        END IF
                     CASE %TKIND_DISPATCH
                        IF UCASE$(GUIDTXT$(@pVarTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                           strGet = " AS " & strPrefix & "StdFont"
                           strPut = "   ' Parameter Type AS " & strPrefix & "StdFont"
                           TLB_UsesFontInterface = %TRUE
                        ELSEIF UCASE$(GUIDTXT$(@pVarTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                           strGet = " AS " & strPrefix & "StdPicture"
                           strPut = "   ' Parameter Type AS " & strPrefix & "StdPicture"
                           TLB_UsesPictureInterface = %TRUE
                        ELSE
'                           strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                           IF LEN(strCoClassName) THEN
'                              strGet = " AS " & strPrefix & strCoClassName
'                              strPut = "   ' Parameter Type AS " & strPrefix & strCoClassName
'                           ELSE
'                              IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                              strGet = " AS " & strPrefix & strName
'                              strPut = "   ' Parameter Type AS " & strPrefix & strName
'                           END IF
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                           IF idx THEN
                              IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                              strGet = " AS " & strPrefix & strName
                              strPut = "   ' Parameter Type AS " & strPrefix & strName
                           ELSE
                              strGet = " AS IDispatch"
                              strPut = "   ' Parameter Type AS " & strName
                           END IF
                        END IF
                     CASE %TKIND_ALIAS
                        IF @pVarTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                           strGet = " AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt) & "   ' " & strName
                           strPut = "   ' Parameter Type AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt) & " <" & strName & ">"
                        ELSE
                           strAliasName = TLB_GetAliasName (pRefTypeInfo, @pVarTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                           IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                              strAliasName = "StdFont"
                              TLB_UsesFontInterface = %TRUE
                           END IF
                           IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                              strAliasName = "StdPicture"
                              TLB_UsesPictureInterface = %TRUE
                           END IF
                           SELECT CASE typekind
                              CASE %TKIND_ENUM, %TKIND_MODULE
'                                 strGet = " AS LONG   ' " & strAliasName
'                                 strPut = "   ' Parameter Type AS LONG <" & strAliasName & ">"
                                 strGet = " AS LONG   ' " & strName
                                 strPut = "   ' Parameter Type AS LONG <" & strName & ">"
                              CASE %TKIND_RECORD, %TKIND_UNION
'                                 strGet = " AS VARIANT   ' " & strAliasName
'                                 strPut = "   ' Parameter Type AS VARIANT <" & strAliasName & ">"
                                 strGet = " AS DWORD   ' " & strAliasName
                                 strPut = "   ' Parameter Type AS DWORD <" & strAliasName & ">"
                              CASE %TKIND_COCLASS
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                    strGet = " AS " & strPrefix & strAliasName
                                    strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                 ELSE
                                    strGet = " AS IDispatch"
                                    strPut = "   ' Parameter Type AS " & strAliasName
                                 END IF
                              CASE %TKIND_INTERFACE
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                    strGet = " AS " & strPrefix & strAliasName
                                    strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                 ELSE
                                    strGet = " AS IUnknown"
                                    strPut = "   ' Parameter Type AS " & strAliasName
                                 END IF
                              CASE %TKIND_DISPATCH
'                                 strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                                 IF LEN(strCoClassName) THEN
'                                    strGet = " AS " & strPrefix & strAliasName
'                                    strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
'                                 ELSE
'                                    IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                    strGet = " AS " & strPrefix & strAliasName
'                                    strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
'                                 END IF
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                    strGet = " AS " & strPrefix & strAliasName
                                    strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                 ELSE
                                    strGet = " AS IDispatch"
                                    strPut = "   ' Parameter Type AS " & strAliasName
                                 END IF
                              CASE ELSE
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strGet = " AS " & strPrefix & strAliasName
                                 strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                           END SELECT
                        END IF
                     CASE ELSE
                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                        strGet = " AS " & strPrefix & strName
                        strPut = "   ' Parameter Type AS " & strPrefix & strName
                  END SELECT
                  pRefTypeInfo.ReleaseTypeAttr pVarTypeAttr
                  pVarTypeAttr = 0
               END IF
            END IF
         ELSEIF vt = %VT_PTR THEN
            wIndirectionLevel = 1
            ' // Gets a pointer to another TYPEDESC structure
            lptdesc = @pVarDesc.elemdescVar.tdesc.lptdesc
            DO
               ' // VarType
               vt = @lptdesc.vt
               SELECT CASE vt
                  ' // If it is another pointer, loop again
                  CASE %VT_PTR
                     INCR wIndirectionLevel
                     lptdesc = @lptdesc.lptdesc
                  ' // If it is a userdefined type (record or enum), get the name
                  ' // of the referenced type and store it
                  CASE %VT_USERDEFINED
                     hr = ptinfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
                     IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
                        hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                        IF hr = %S_OK THEN
                           strName = bstrName
                           hr = pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
                           IF pVarTypeAttr <> %NULL THEN
                              typekind = @pVarTypeAttr.typekind
                              SELECT CASE @pVarTypeAttr.typekind
                                 CASE %TKIND_ENUM
                                    strGet = " AS LONG   ' " & strName
                                    strPut = "   ' Parameter Type AS LONG <" & strName & ">"
                                 CASE %TKIND_RECORD, %TKIND_UNION
'                                    strGet = " AS VARIANT   ' " & strName
'                                    strPut = "   ' Parameter Type AS VARIANT <" & strName & ">"
                                    strGet = " AS DWORD   ' " & strName
                                    strPut = "   ' Parameter Type AS DWORD <" & strName & ">"
                                 CASE %TKIND_COCLASS
                                    idx = 0
                                    ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                    IF idx THEN
                                       IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                       strGet = " AS " & strPrefix & strName
                                       strPut = "   ' Parameter Type AS " & strPrefix & strName
                                    ELSE
                                       strGet = " AS IDispatch"
                                       strPut = "   ' Parameter Type AS " & strName
                                    END IF
                                 CASE %TKIND_INTERFACE
                                    idx = 0
                                    ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                    IF idx THEN
                                       IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                       strGet = " AS " & strPrefix & strName
                                       strPut = "   ' Parameter Type AS " & strPrefix & strName
                                    ELSE
                                       strGet = " AS IUnknown"
                                       strPut = "   ' Parameter Type AS " & strName
                                    END IF
                                 CASE %TKIND_DISPATCH
                                    IF UCASE$(GUIDTXT$(@pVarTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                       strGet = " AS " & strPrefix & "StdFont"
                                       strPut = "   ' Parameter Type AS " & strPrefix & "StdFont"
                                       TLB_UsesFontInterface = %TRUE
                                    ELSEIF UCASE$(GUIDTXT$(@pVarTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                       strGet = " AS " & strPrefix & "StdPicture"
                                       strPut = "   ' Parameter Type AS " & strPrefix & "StdPicture"
                                       TLB_UsesPictureInterface = %TRUE
                                    ELSE
'                                       strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                                       IF LEN(strCoClassName) THEN
'                                          strGet = " AS " & strPrefix & strCoClassName
'                                          strPut = "   ' Parameter Type AS " & strPrefix & strCoClassName
'                                       ELSE
'                                          IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                                          strGet = " AS " & strPrefix & strName
'                                          strPut = "   ' Parameter Type AS " & strPrefix & strName
'                                       END IF
                                       idx = 0
                                       ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                       IF idx THEN
                                          IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                          strGet = " AS " & strPrefix & strName
                                          strPut = "   ' Parameter Type AS " & strPrefix & strName
                                       ELSE
                                          strGet = " AS IDispatch"
                                          strPut = "   ' Parameter Type AS " & strName
                                       END IF
                                    END IF
                                 CASE %TKIND_ALIAS
                                    IF @pVarTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                       strGet = " AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt) & "   ' " & strName
                                       strPut = "   ' Parameter Type AS " & VarTypeToKeyword(@pVarTypeAttr.tdescalias.vt) & " < " & strName & ">"
                                    ELSE
                                       IF @pVarTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                          strGet = " AS " & VarTypeToKeyword(vt)
                                          strPut = "   ' Parameter Type AS " & VarTypeToKeyword(vt)
                                       ELSE
                                          strAliasName = TLB_GetAliasName (pRefTypeInfo, @pVarTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                                          IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                             strAliasName = "StdFont"
                                             TLB_UsesFontInterface = %TRUE
                                          END IF
                                          IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                             strAliasName = "StdPicture"
                                             TLB_UsesPictureInterface = %TRUE
                                          END IF
                                          SELECT CASE typekind
                                             CASE %TKIND_ENUM, %TKIND_MODULE
'                                                strGet = " AS LONG   ' " & strAliasName
'                                                strPut = "   ' Parameter Type AS LONG <" & strAliasName & ">"
                                                strGet = " AS LONG   ' " & strName
                                                strPut = "   ' Parameter Type AS LONG <" & strName & ">"
                                             CASE %TKIND_RECORD, %TKIND_UNION
'                                                strGet = " AS VARIANT   ' " & strAliasName
'                                                strPut = "   ' Parameter Type AS VARIANT <" & strAliasName & ">"
                                                strGet = " AS DWORD   ' " & strAliasName
                                                strPut = "   ' Parameter Type AS DWORD <" & strAliasName & ">"
                                             CASE %TKIND_COCLASS
                                                idx = 0
                                                ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                                IF idx THEN
                                                   IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                                   strGet = " AS " & strPrefix & strAliasName
                                                   strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                                ELSE
                                                   strGet = " AS IDispatch"
                                                   strPut = "   ' Parameter Type AS " & strAliasName
                                                END IF
                                             CASE %TKIND_INTERFACE
                                                idx = 0
                                                ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                                IF idx THEN
                                                   IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                                   strGet = " AS " & strPrefix & strAliasName
                                                   strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                                ELSE
                                                   strGet = " AS IUnknown"
                                                   strPut = "   ' Parameter Type AS " & strAliasName
                                                END IF
                                             CASE %TKIND_DISPATCH
'                                                strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                                                IF LEN(strCoClassName) THEN
'                                                   strGet = " AS " & strPrefix & strAliasName
'                                                   strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
'                                                ELSE
'                                                   IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                                   strGet = " AS " & strPrefix & strAliasName
'                                                   strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
'                                                END IF
                                                idx = 0
                                                ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                                IF idx THEN
                                                   IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                                   strGet = " AS " & strPrefix & strAliasName
                                                   strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                                ELSE
                                                   strGet = " AS IDispatch"
                                                   strPut = "   ' Parameter Type AS " & strAliasName
                                                END IF
                                             CASE ELSE
                                                IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                                strGet = " AS " & strPrefix & strAliasName
                                                strPut = "   ' Parameter Type AS " & strPrefix & strAliasName
                                          END SELECT
                                       END IF
                                    END IF
                                 CASE ELSE
                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                    strGet = " AS " & strPrefix & strName
                                    strPut = "   ' Parameter Type AS " & strPrefix & strName
                              END SELECT
                              pRefTypeInfo.ReleaseTypeAttr pVarTypeAttr
                              pVarTypeAttr = 0
                           END IF
                        END IF
                     END IF
                     EXIT DO
                  CASE ELSE
                     strGet = " AS " & VarTypeToKeyword(vt)
                     strPut = "   ' Parameter Type AS " & VarTypeToKeyword(vt)
                     EXIT DO
               END SELECT
            LOOP
         ELSE
            strGet = " AS " & VarTypeToKeyword(vt)
            strPut = "   ' Parameter Type AS " & VarTypeToKeyword(vt)
         END IF
         ' -------------------------------------------------------------------------------
'         TLB_AddLine("   MEMBER GET  " & strVarName & "<&H" & HEX$(@pVarDesc.memid, 8) & ">()" & strGet)
         TLB_AddLine("   MEMBER GET  " & strVarName & " <" & FORMAT$(@pVarDesc.memid) & "> ()" & strGet)
         IF (@pVarDesc.wVarFlags AND %VARFLAG_FREADONLY) <> %VARFLAG_FREADONLY THEN
            IF typekind = %TKIND_INTERFACE OR typekind = %TKIND_COCLASS OR typekind = %TKIND_DISPATCH THEN
'               TLB_AddLine("   MEMBER SET  " & strVarName & "<&H" & HEX$(@pVarDesc.memid, 8) & ">()" & strPut)
               TLB_AddLine("   MEMBER SET  " & strVarName & " <" & FORMAT$(@pVarDesc.memid) & "> ()" & strPut)
            ELSE
'               TLB_AddLine("   MEMBER LET  " & strVarName & "<&H" & HEX$(@pVarDesc.memid, 8) & ">()" & strPut)
               TLB_AddLine("   MEMBER LET  " & strVarName & " <" & FORMAT$(@pVarDesc.memid) & "> ()" & strPut)
            END IF
         END IF
      END IF

      ' ----------------------------------------------------------------------------------
      ' Releases the VarDesc interface
      ' ----------------------------------------------------------------------------------
      ptinfo.ReleaseVarDesc pVarDesc
      pVarDesc = 0
      ' ----------------------------------------------------------------------------------

   NEXT

   ' ----------------------------------------------------------------------------------
   ' Releases the VarDesc interface in the case of an early exit
   ' ----------------------------------------------------------------------------------
   IF pVarDesc THEN ptinfo.ReleaseVarDesc pVarDesc
   ' ----------------------------------------------------------------------------------

END SUB
' ========================================================================================

' ========================================================================================
' Retrieves information about the parameter for put and putref properties
' ========================================================================================
FUNCTION TLB_PBInterfaceGetPutParameter ( _
    BYVAL hWnd AS DWORD, _                   ' // Main window handle
    BYVAL ptlib AS ITypeLib, _               ' // Indirect pointer to the TypeLib
    BYVAL ptinfo AS ITypeInfo, _             ' // Indirect pointer to the TypeInfo
    BYVAL pFuncDesc AS FUNCDESC PTR _        ' // Indirect pointer to the function description
    ) AS STRING                              ' // Returns the parameter type

   LOCAL hr AS LONG                          ' // HRESULT
   LOCAL cParams AS LONG                     ' // Number of parameters
   LOCAL pcNames AS DWORD                    ' // Number of names returned by GetNames
   LOCAL pParam AS ELEMDESC PTR              ' // Pointer to an array of parameters
   LOCAL x AS LONG                           ' // Loop counter
   LOCAL szName AS ASCIIZ * 255              ' // Name
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL vt AS WORD                          ' // Variant type
   LOCAL pRefTypeInfo AS ITypeInfo           ' // Address to a referenced type description
   LOCAL pPrmTypeAttr AS TYPEATTR PTR        ' // Type attribute for the parameter
   LOCAL lptdesc AS TYPEDESC PTR             ' // Pointer to a TYPEDESC structure
   LOCAL strName AS STRING                   ' // Name
   LOCAL wFlags AS WORD                      ' // Parameter flags
   LOCAL wIndirectionLevel AS WORD           ' // Indirection level
   LOCAL vtOld AS WORD                       ' // Variant type
   LOCAL strVtPtr AS STRING                  ' // VT_PTR vartype
   LOCAL strReturn AS STRING                 ' // Output string
   LOCAL strAliasName AS STRING              ' // Alias name
   LOCAL szAliasTypeKind AS ASCIIZ * 256     ' // Alias type
   LOCAL typekind AS LONG                    ' // Alias type
   LOCAL szGuid AS ASCIIZ * 256              ' // Guid
   LOCAL strCoClassName AS STRING            ' // CoClas name
   LOCAL strPrefix AS STRING                 ' // Prefix
   LOCAL idx AS LONG                         ' // General purpose variable

   IF m_UsePrefix THEN strPrefix = TLB_PrefixStr

   ' Number of parameters
   cParams = @pFuncDesc.cParams

   ' -------------------------------------------------------------------------------------
   ' Gets the name of all the parameters.
   ' The first one is the name of the function.
   ' If the member ID identifies a property that is implemented with property functions,
   ' the property name is returned.For property get functions, the names of the function
   ' and its parameters are always returned.
   ' For property put and put reference functions, the right side of the assignment is
   ' unnamed. If cMaxNames is less than is required to return all of the names of the
   ' parameters of a function, then only the names of the first cMaxNames-1 parameters
   ' are returned. The names of the parameters are returned in the array in the same
   ' order that they appear elsewhere in the interface (for example, the same order in
   ' the parameter array associated with the FUNCDESC enumeration).
   ' -------------------------------------------------------------------------------------
   REDIM rgbstrNames(cParams) AS WSTRING
   hr = ptinfo.GetNames(@pFuncDesc.memid, rgbstrNames(0), cParams + 1, pcNames)
   IF hr <> %S_OK THEN EXIT FUNCTION
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Pointer to an ELEMDESC structure
   ' -------------------------------------------------------------------------------------
   pParam = @pFuncDesc.lprgelemdescParam
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Retrieves information about all the parameters
   ' -------------------------------------------------------------------------------------
   FOR x = 0 TO cParams - 1

      ' ----------------------------------------------------------------------------------
      ' Allow for a breath and check the abort flag
      ' ----------------------------------------------------------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Parameter name and type
      ' ----------------------------------------------------------------------------------
      szName = rgbstrNames(x + 1)
      vt = @pParam[x].tdesc.vt
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Attributes
      ' ----------------------------------------------------------------------------------
      wFlags = @pParam[x].paramdesc.wParamFlags
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Resolve the type of the parameter
      ' ----------------------------------------------------------------------------------
      strName = ""
      strVtPtr = ""
      wIndirectionLevel = 0
      vtOld = 0
      IF vt = %VT_VOID THEN
         strReturn = "DWORD"
      ELSEIF vt = %VT_USERDEFINED THEN
         hr = ptinfo.GetRefTypeInfo(@pParam[x].tdesc.hreftype, pRefTypeInfo)
         IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
            hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN strName = bstrName
            hr = pRefTypeInfo.GetTypeAttr(pPrmTypeAttr)
            IF pPrmTypeAttr <> %NULL THEN
               SELECT CASE @pPrmTypeAttr.typekind
                  CASE %TKIND_ENUM
                     strReturn = "LONG <" & strPrefix & strName & ">"
                  CASE %TKIND_RECORD
'                      IF LEFT$(strName, 1) = "_" THEN
'                         strReturn = "tag" & strName
'                      ELSE
'                         strReturn = strName
'                      END IF
                       strReturn = "DWORD"
                  CASE %TKIND_UNION
'                      IF LEFT$(strName, 1) = "_" THEN
'                         strReturn = "u" & strName
'                      ELSE
'                         strReturn = strName
'                      END IF
                       strReturn = "DWORD"
                  CASE %TKIND_COCLASS
                     idx = 0
                     ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                     IF idx THEN
                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                        strReturn = strPrefix & strName
                     ELSE
                        strReturn = "IDispatch"
                     END IF
                  CASE %TKIND_INTERFACE
                     idx = 0
                     ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                     IF idx THEN
                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                        strReturn = strPrefix & strName
                     ELSE
                        strReturn = "IUnknown"
                     END IF
                  CASE %TKIND_DISPATCH
                     IF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                        strReturn = strPrefix & "StdFont"
                        TLB_UsesFontInterface = %TRUE
                     ELSEIF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                        strReturn = strPrefix & "StdPicture"
                        TLB_UsesPictureInterface = %TRUE
                     ELSE
'                        strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                        IF LEN(strCoClassName) THEN
'                           strReturn = strPrefix & strCoClassName
'                        ELSE
'                           IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                           strReturn = strPrefix & strName
'                        END IF
                        idx = 0
                        ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                        IF idx THEN
                           IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                           strReturn = strPrefix & strName
                        ELSE
                           strReturn = "IDispatch"
                        END IF
                     END IF
                  CASE %TKIND_ALIAS
                     IF @pPrmTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                        strReturn = VarTypeToKeyword(@pPrmTypeAttr.tdescalias.vt) & " <" & strName & ">"
                     ELSE
                        strAliasName = TLB_GetAliasName (pRefTypeInfo, @pPrmTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                        IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                           strAliasName = "StdFont"
                           TLB_UsesFontInterface = %TRUE
                        END IF
                        IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                           strAliasName = "StdPicture"
                           TLB_UsesPictureInterface = %TRUE
                        END IF
                        SELECT CASE typekind
                           CASE %TKIND_ENUM, %TKIND_MODULE
'                              strReturn = "LONG <" & strPrefix & strAliasName & ">"
                              strReturn = "LONG <" & strPrefix & strName & ">"
                           CASE %TKIND_RECORD
'                               IF LEFT$(strAliasName, 1) = "_" THEN
'                                  strReturn = "tag" & strAliasName
'                               ELSE
'                                  strReturn = strAliasName
'                               END IF
                               strReturn = "DWORD"
                           CASE %TKIND_UNION
'                               IF LEFT$(strAliasName, 1) = "_" THEN
'                                  strReturn = "u" & strAliasName
'                               ELSE
'                                  strReturn = strAliasName
'                               END IF
                               strReturn = "DWORD"
                           CASE %TKIND_COCLASS
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                              IF idx THEN
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strReturn = strPrefix & strAliasName
                              ELSE
                                 strReturn = "IDispatch"
                              END IF
                           CASE %TKIND_INTERFACE
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                              IF idx THEN
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strReturn = strPrefix & strAliasName
                              ELSE
                                 strReturn = "IUnknown"
                              END IF
                           CASE %TKIND_DISPATCH
'                              strCoClassName = TLB_GetCoClassNameFromArray(strAliasName)
'                              IF LEN(strCoClassName) THEN
'                                 strReturn = strPrefix & strCoClassName
'                              ELSE
'                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                 strReturn = strPrefix & strAliasName
'                              END IF
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                              IF idx THEN
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strReturn = strPrefix & strAliasName
                              ELSE
                                 strReturn = "IDispatch"
                              END IF
                           CASE ELSE
                              IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                              strReturn = strPrefix & strAliasName
                        END SELECT
                     END IF
                  CASE ELSE
                     IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                     strReturn = strPrefix & strName
               END SELECT
               pRefTypeInfo.ReleaseTypeAttr pPrmTypeAttr
               pPrmTypeAttr = 0
            END IF
         END IF
      ELSEIF vt = %VT_PTR THEN
         vtOld = vt
         strVtPtr = "VT_PTR"
         wIndirectionLevel = 1
         ' // Gets a pointer to another TYPEDESC structure
         lptdesc = @pParam[x].tdesc.lptdesc
         DO
            ' // VarType
            vt = @lptdesc.vt
            SELECT CASE vt
               ' // If it is another pointer, loop again
               CASE %VT_PTR
                  strVtPtr = strVtPtr & "->VT_PTR"
                  INCR wIndirectionLevel
                  lptdesc = @lptdesc.lptdesc
               ' // If it is a userdefined type (record or enum), get the name
               ' // of the referenced type and store it
               CASE %VT_USERDEFINED
                  vtOld = vt
                  strVtPtr = strVtPtr & "->VT_USERDEFINED"
                  hr = ptinfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
                  IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
                     hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                     IF hr = %S_OK THEN
                        strName = bstrName
                        hr = pRefTypeInfo.GetTypeAttr(pPrmTypeAttr)
                        IF pPrmTypeAttr <> %NULL THEN
                           SELECT CASE @pPrmTypeAttr.typekind
                              CASE %TKIND_ENUM
                                 strReturn = "LONG <" & strPrefix & strName & ">"
                              CASE %TKIND_RECORD
'                                 IF LEFT$(strName, 1) = "_" THEN
'                                    strReturn = "tag" & strName
'                                 ELSE
'                                    strReturn = strName
'                                 END IF
                                 strReturn = "DWORD"
                              CASE %TKIND_UNION
'                                 IF LEFT$(strName, 1) = "_" THEN
'                                    strReturn = "u" & strName
'                                 ELSE
'                                    strReturn = strName
'                                 END IF
                                 strReturn = "DWORD"
                              CASE %TKIND_COCLASS
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                    strReturn = strPrefix & strName
                                 ELSE
                                    strReturn = "IDispatch"
                                 END IF
                              CASE %TKIND_INTERFACE
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                    strReturn = strPrefix & strName
                                 ELSE
                                    strReturn = "IUnknown"
                                 END IF
                              CASE %TKIND_DISPATCH
                                 IF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                    strReturn = strPrefix & "StdFont"
                                    TLB_UsesFontInterface = %TRUE
                                 ELSEIF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                    strReturn = strPrefix & "StdPicture"
                                    TLB_UsesPictureInterface = %TRUE
                                 ELSE
'                                    strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                                    IF LEN(strCoClassName) THEN
'                                       strReturn = strPrefix & strCoClassName
'                                    ELSE
'                                       IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                                       strReturn = strPrefix & strName
'                                    END IF
                                    idx = 0
                                    ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                    IF idx THEN
                                       IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                       strReturn = strPrefix & strName
                                    ELSE
                                       strReturn = "IDispatch"
                                    END IF
                                 END IF
                              CASE %TKIND_ALIAS
                                 IF @pPrmTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                    strReturn = VarTypeToKeyword(@pPrmTypeAttr.tdescalias.vt)
                                 ELSE
                                    strAliasName = TLB_GetAliasName (pRefTypeInfo, @pPrmTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                                    IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                       strAliasName = "StdFont"
                                       TLB_UsesFontInterface = %TRUE
                                    END IF
                                    IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                       strAliasName = "StdPicture"
                                       TLB_UsesPictureInterface = %TRUE
                                    END IF
                                    SELECT CASE typekind
                                       CASE %TKIND_ENUM, %TKIND_MODULE
'                                          strReturn = "LONG <" & strPrefix & strAliasName & ">"
                                           strReturn = "LONG <" & strPrefix & strName & ">"
                                       CASE %TKIND_RECORD
'                                           IF LEFT$(strAliasName, 1) = "_" THEN
'                                              strReturn = "tag" & strAliasName
'                                           ELSE
'                                              strReturn = strAliasName
'                                           END IF
                                           strReturn = "DWORD"
                                       CASE %TKIND_UNION
'                                           IF LEFT$(strAliasName, 1) = "_" THEN
'                                              strReturn = "u" & strAliasName
'                                           ELSE
'                                              strReturn = strAliasName
'                                           END IF
                                           strReturn = "DWORD"
                                       CASE %TKIND_COCLASS
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                          IF idx THEN
                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                             strReturn = strPrefix & strAliasName
                                          ELSE
                                             strReturn = "IDispatch"
                                          END IF
                                       CASE %TKIND_INTERFACE
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                          IF idx THEN
                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                             strReturn = strPrefix & strAliasName
                                          ELSE
                                             strReturn = "IUnknown"
                                          END IF
                                       CASE %TKIND_DISPATCH
'                                          strCoClassName = TLB_GetCoClassNameFromArray(strAliasName)
'                                          IF LEN(strCoClassName) THEN
'                                             strReturn = strPrefix & strCoClassName
'                                          ELSE
'                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                             strReturn = strPrefix & strAliasName
'                                          END IF
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                          IF idx THEN
                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                             strReturn = strPrefix & strAliasName
                                          ELSE
                                             strReturn = "IDispatch"
                                          END IF
                                       CASE ELSE
                                          IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                          strReturn = strPrefix & strAliasName
                                    END SELECT
                                 END IF
                              CASE ELSE
                                 IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                 strReturn = strPrefix & strName
                           END SELECT
                           pRefTypeInfo.ReleaseTypeAttr pPrmTypeAttr
                           pPrmTypeAttr = 0
                        END IF
                     END IF
                  END IF
                  EXIT DO
               CASE ELSE
                  IF vt = %VT_VARIANT THEN
                     strReturn = "VARIANT"
                  ELSEIF vt = %VT_BSTR THEN
                     strReturn = "WSTRING"
                  ELSEIF vt = %VT_LPWSTR THEN
                     strReturn = "DWORD"
                  ELSE
                     strReturn = VarTypeToKeyword(vt)
                  END IF
                  EXIT DO
            END SELECT
         LOOP
      ELSEIF vt = %VT_BSTR THEN
         strReturn = "WSTRING"
      ELSEIF vt = %VT_LPWSTR THEN
         strReturn = "DWORD"
      ELSEIF vt = %VT_VARIANT THEN
         strReturn = "VARIANT"
'      ELSEIF vt = %VT_DISPATCH OR vt = %VT_UNKNOWN THEN
'         strReturn = "VARIANT"
      ELSEIF vt = %VT_UNKNOWN THEN
         strReturn = "IUnknown"
      ELSEIF vt = %VT_DISPATCH THEN
         strReturn = "IDispatch"
      ELSE
         strReturn = VarTypeToKeyword(vt)
      END IF

   NEXT

   ' -------------------------------------------------------------------------------------
   ' Return the parameter lines of the function
   ' -------------------------------------------------------------------------------------
   FUNCTION = strReturn
   ' -------------------------------------------------------------------------------------

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information relative to the return type.
' The FUNCDESC structure contains a member called elemdescFunc that is an ELEMDESC stucture
' that contains the return type of the function. To retrieve the description of this type, we
' have to access the tdesc member of the ELEMDESC structure, that is another structure called
' TYPEDESC one of whose members is an union with a meber called hreftype.
' ========================================================================================
FUNCTION TLB_GetPBInterfaceReturnType ( _
   BYVAL hWnd AS DWORD, _                    ' // Window handle
   BYVAL ptlib AS ITypeLib, _                ' // ITypeLib interface
   BYVAL ptinfo AS ITypeInfo, _              ' // ITypeInfo interface
   BYVAL pFuncDesc AS FUNCDESC PTR _         ' // FUNCDESC structure
   ) AS STRING

   LOCAL hr AS LONG                          ' // HRESULT
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL strName AS STRING                   ' // Name
   LOCAL pRefTypeInfo AS ITypeInfo           ' // Address to a referenced type description
   LOCAL lptdesc AS TYPEDESC PTR             ' // Pointer to a TYPEDESC structure
   LOCAL vt AS WORD                          ' // Variant type
   LOCAL pRetTypeAttr AS TYPEATTR PTR        ' // Type attribute
   LOCAL strTypeKind AS STRING               ' // Type of variable
   LOCAL strAliasName AS STRING              ' // Alias name
   LOCAL typekind AS LONG                    ' // Alias type
   LOCAL szAliasTypeKind AS ASCIIZ * 256     ' // Alias type kind
   LOCAL szGuid AS ASCIIZ * 256              ' // Guid
   LOCAL strCoClassName AS STRING            ' // CoClass name
   LOCAL strPrefix AS STRING                 ' // Prefix
   LOCAL idx AS LONG                         ' // General purpose variable

   IF m_UsePrefix THEN strPrefix = TLB_PrefixStr

   ' Return type
   IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_VOID THEN
      strTypeKind = ""
   ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_USERDEFINED THEN
      hr = ptinfo.GetRefTypeInfo(@pFuncDesc.elemdescFunc.tdesc.hreftype, pRefTypeInfo)
      IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
         hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         IF hr = %S_OK THEN strName = bstrName
         hr = pRefTypeInfo.GetTypeAttr(pRetTypeAttr)
         IF pRetTypeAttr <> %NULL THEN
            SELECT CASE @pRetTypeAttr.typekind
               CASE %TKIND_ENUM
                  strTypeKind = "LONG   ' " & strPrefix & strName & " <enum>"
               CASE %TKIND_MODULE
                  strTypeKind = "LONG   ' " & strPrefix & strName & " <module>"
               CASE %TKIND_RECORD
'                  IF LEFT$(strName, 1) = "_" THEN
'                     strTypeKind = "tag" & strName
'                  ELSE
'                     strTypeKind = strName
'                  END IF
                  strTypeKind = "DWORD   ' " & strName & " <record>"
               CASE %TKIND_UNION
'                  IF LEFT$(strName, 1) = "_" THEN
'                     strTypeKind = "u" & strName
'                  ELSE
'                     strTypeKind = strName
'                  END IF
                  strTypeKind = "DWORD   ' " & strName & " <union>"
               CASE %TKIND_COCLASS
                  idx = 0
                  ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                  IF idx THEN
                     IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                     strTypeKind = strPrefix & strName & "   ' <coclass>"
                  ELSE
                     strTypeKind = "IDispatch   ' " & strName & " <coclass>"
                  END IF
               CASE %TKIND_INTERFACE
                  idx = 0
                  ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                  IF idx THEN
                     IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                     strTypeKind = strPrefix & strName & "   ' <interface>"
                  ELSE
                     strTypeKind = "IUnknown   ' " & strName & " <interface>"
                  END IF
               CASE %TKIND_DISPATCH
                  IF UCASE$(GUIDTXT$(@pRetTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                     strTypeKind = strPrefix & "StdFont" & "   ' <dispinterface>"
                     TLB_UsesFontInterface = %TRUE
                  ELSEIF UCASE$(GUIDTXT$(@pRetTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                     strTypeKind = strPrefix & "StdPicture" & "   ' <dispinterface>"
                     TLB_UsesPictureInterface = %TRUE
                  ELSE
'                     strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                     IF LEN(strCoClassName) THEN
'                        strTypeKind = strPrefix & strCoClassName & "   ' <dispinterface>"
'                     ELSE
'                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                        strTypeKind = strPrefix & strName & "   ' <dispinterface>"
'                     END IF
                     idx = 0
                     ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                     IF idx THEN
                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                        strTypeKind = strPrefix & strName & "   ' <dispinterface>"
                     ELSE
                        strTypeKind = "IDispatch   ' " & strName & " <dispinterface>"
                     END IF
                  END IF
               CASE %TKIND_ALIAS
                  IF @pRetTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                     strTypeKind = VarTypeToKeyword(@pRetTypeAttr.tdescalias.vt) & "   ' " & strName
                  ELSE
                     strAliasName = TLB_GetAliasName (pRefTypeInfo, @pRetTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                     IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                        strAliasName = "StdFont"
                        TLB_UsesFontInterface = %TRUE
                     END IF
                     IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                        strAliasName = "StdPicture"
                        TLB_UsesPictureInterface = %TRUE
                     END IF
                     SELECT CASE typekind
                        CASE %TKIND_ENUM
'                           strTypeKind = "LONG   ' " & strPrefix & strAliasName & " <enum>"
                           strTypeKind = "LONG   ' " & strPrefix & strName & " <enum>"
                        CASE %TKIND_MODULE
'                           strTypeKind = "LONG   ' " & strPrefix & strAliasName & " <module>"
                           strTypeKind = "LONG   ' " & strPrefix & strName & " <module>"
                        CASE %TKIND_RECORD
'                           IF LEFT$(strAliasName, 1) = "_" THEN
'                              strTypeKind = "tag" & strAliasName
'                           ELSE
'                              strTypeKind = strAliasName
'                           END IF
                           strTypeKind = "DWORD   ' " & strAliasName & " <record>"
                        CASE %TKIND_UNION
'                           IF LEFT$(strAliasName, 1) = "_" THEN
'                              strTypeKind = "u" & strAliasName
'                           ELSE
'                              strTypeKind = strAliasName
'                           END IF
                           strTypeKind = "DWORD   ' " & strAliasName & " <union>"
                        CASE %TKIND_COCLASS
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                           IF idx THEN
                              IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                              strTypeKind = strPrefix & strAliasName & "   ' <coclass>"
                           ELSE
                              strTypeKind = "IDispatch   ' " & strAliasName & " <coclass>"
                           END IF
                        CASE %TKIND_INTERFACE
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                           IF idx THEN
                              IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                              strTypeKind = strPrefix & strAliasName & "   ' <interface>"
                           ELSE
                              strTypeKind = "IUnknown   ' " & strAliasName & " <interface>"
                           END IF
                        CASE %TKIND_DISPATCH
'                           strCoClassName = TLB_GetCoClassNameFromArray(strAliasName)
'                           IF LEN(strCoClassName) THEN
'                              strTypeKind = strPrefix & strCoClassName & "   ' <dispinterface>"
'                           ELSE
'                              IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                              strTypeKind = strPrefix & strAliasName & "   ' <dispinterface>"
'                           END IF
                           idx = 0
                           ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                           IF idx THEN
                              IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                              strTypeKind = strPrefix & strAliasName & "   ' <dispinterface>"
                           ELSE
                              strTypeKind = "IDispatch   ' " & strAliasName & " <dispinterface>"
                           END IF
                        CASE ELSE
                           strTypeKind = strPrefix & strAliasName
                     END SELECT
                  END IF
            END SELECT
            pRefTypeInfo.ReleaseTypeAttr pRetTypeAttr
            pRetTypeAttr = 0
         END IF
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
               hr = ptinfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
               IF ISTRUE ISOBJECT(pRefTypeInfo) <> %NULL THEN
                  hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr = %S_OK THEN
                     strName = bstrName
                     hr = pRefTypeInfo.GetTypeAttr(pRetTypeAttr)
                     IF pRetTypeAttr <> %NULL THEN
                        SELECT CASE @pRetTypeAttr.typekind
                           CASE %TKIND_ENUM
                              strTypeKind = "LONG   ' " & strPrefix & strName & " <enum>"
                           CASE %TKIND_MODULE
                              strTypeKind = "LONG   ' " & strPrefix & strName & " <module>"
                           CASE %TKIND_RECORD
'                               IF LEFT$(strName, 1) = "_" THEN
'                                  strTypeKind = "tag" & strName
'                               ELSE
'                                  strTypeKind = strName
'                               END IF
                               strTypeKind = "DWORD   ' " & strName & " <record>"
                           CASE %TKIND_UNION
'                               IF LEFT$(strName, 1) = "_" THEN
'                                  strTypeKind = "u" & strName
'                               ELSE
'                                  strTypeKind = strName
'                               END IF
                               strTypeKind = "DWORD   ' " & strName & " <union>"
                           CASE %TKIND_COCLASS
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                              IF idx THEN
                                 IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                 strTypeKind = strPrefix & strName & "   ' <coclass>"
                              ELSE
                                 strTypeKind = "IDispatch   ' " & strName & " <coclass>"
                              END IF
                           CASE %TKIND_INTERFACE
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                              IF idx THEN
                                 IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                 strTypeKind = strPrefix & strName & "   ' <interface>"
                              ELSE
                                 strTypeKind = "IUnknown   ' " & strName & " <interface>"
                              END IF
                           CASE %TKIND_DISPATCH
                              IF UCASE$(GUIDTXT$(@pRetTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                 strTypeKind = strPrefix & "StdFont" & "   ' <dispinterface>"
                                 TLB_UsesFontInterface = %TRUE
                              ELSEIF UCASE$(GUIDTXT$(@pRetTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                 strTypeKind = strPrefix & "StdPicture" & "   ' <dispinterface>"
                                 TLB_UsesPictureInterface = %TRUE
                              ELSE
'                                 strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                                 IF LEN(strCoClassName) THEN
'                                    strTypeKind = strPrefix & strCoClassName & "   ' <dispinterface>"
'                                 ELSE
'                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                                    strTypeKind = strPrefix & strName & "   ' <dispinterface>"
'                                 END IF
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                    strTypeKind = strPrefix & strName & "   ' <dispinterface>"
                                 ELSE
                                    strTypeKind = "IDispatch   ' " & strName & " <dispinterface>"
                                 END IF
                              END IF
                           CASE %TKIND_ALIAS
                              IF @pRetTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                 strTypeKind = VarTypeToKeyword(@pRetTypeAttr.tdescalias.vt) & "   ' " & strName
                              ELSE
                                 strAliasName = TLB_GetAliasName (pRefTypeInfo, @pRetTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                                 IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                    strAliasName = "StdFont"
                                    TLB_UsesFontInterface = %TRUE
                                 END IF
                                 IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                    strAliasName = "StdPicture"
                                    TLB_UsesPictureInterface = %TRUE
                                 END IF
                                 SELECT CASE typekind
                                    CASE %TKIND_ENUM
'                                       strTypeKind = "LONG   ' " & strPrefix & strAliasName & " <enum>"
                                       strTypeKind = "LONG   ' " & strPrefix & strName & " <enum>"
                                    CASE %TKIND_MODULE
'                                       strTypeKind = "LONG   ' " & strPrefix & strAliasName & " <module>"
                                       strTypeKind = "LONG   ' " & strPrefix & strName & " <module>"
                                    CASE %TKIND_RECORD
'                                        IF LEFT$(strAliasName, 1) = "_" THEN
'                                           strTypeKind = "tag" & strAliasName
'                                        ELSE
'                                           strTypeKind = strAliasName
'                                        END IF
                                        strTypeKind = "DWORD   ' " & strAliasName & " <record>"
                                    CASE %TKIND_UNION
'                                        IF LEFT$(strAliasName, 1) = "_" THEN
'                                           strTypeKind = "u" & strAliasName
'                                        ELSE
'                                           strTypeKind = strAliasName
'                                        END IF
                                        strTypeKind = "DWORD   ' " & strAliasName & " <union>"
                                    CASE %TKIND_COCLASS
                                       idx = 0
                                       ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                       IF idx THEN
                                          IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                          strTypeKind = strPrefix & strAliasName & "   ' <coclass>"
                                       ELSE
                                          strTypeKind = "IDispatch   ' " & strAliasName & " <coclass>"
                                       END IF
                                    CASE %TKIND_INTERFACE
                                       idx = 0
                                       ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                       IF idx THEN
                                          IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                          strTypeKind = strPrefix & strAliasName & "   ' <interface>"
                                       ELSE
                                          strTypeKind = "IUnknown   ' " & strAliasName & " <interface>"
                                       END IF
                                    CASE %TKIND_DISPATCH
'                                       strCoClassName = TLB_GetCoClassNameFromArray(strAliasName)
'                                       IF LEN(strCoClassName) THEN
'                                          strTypeKind = strPrefix & strCoClassName & "   ' <dispinterface>"
'                                       ELSE
'                                          IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                          strTypeKind = strPrefix & strAliasName & "   ' <dispinterface>"
'                                       END IF
                                       idx = 0
                                       ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                       IF idx THEN
                                          IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                          strTypeKind = strPrefix & strAliasName & "   ' <dispinterface>"
                                       ELSE
                                          strTypeKind = "IDispatch   ' " & strAliasName & " <dispinterface>"
                                       END IF
                                    CASE ELSE
                                       strTypeKind = strPrefix & strAliasName
                                 END SELECT
                              END IF
                        END SELECT
                        pRefTypeInfo.ReleaseTypeAttr pRetTypeAttr
                        pRetTypeAttr = 0
                     END IF
                  END IF
               END IF
              EXIT DO
            CASE ELSE
               strTypeKind = VarTypeToKeyword(vt)
               EXIT DO
         END SELECT
      LOOP
   ELSE
'      IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_DISPATCH OR @pFuncDesc.elemdescFunc.tdesc.vt = %VT_UNKNOWN THEN
'         strTypeKind = "VARIANT"
      IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_UNKNOWN THEN
         strTypeKind = "IUnknown"
      ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_DISPATCH THEN
         strTypeKind = "IDispatch"
      ELSE
         strTypeKind = VarTypeToKeyword(@pFuncDesc.elemdescFunc.tdesc.vt)
      END IF
   END IF

   FUNCTION = strTypeKind

'OutputDebugString "" & strTypeKind

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the parameters
' ========================================================================================
FUNCTION TLB_PBInterfaceGetParametersInfo ( _
   BYVAL hWnd AS DWORD, _                    ' // Main window handle
   BYVAL ptlib AS ITypeLib, _                ' // ITypeLib interface
   BYVAL ptinfo AS ITypeInfo, _              ' // ITypeInfo interface
   BYVAL pFuncDesc AS FUNCDESC PTR, _        ' // FUNCDESC structure
   OPTIONAL BYVAL bLastParamOnly AS LONG _   ' // Return only the last parameter
   ) AS STRING

   LOCAL hr AS LONG                          ' // HRESULT
   LOCAL cParams AS LONG                     ' // Number of parameters
   LOCAL pcNames AS DWORD                    ' // Number of names returned by GetNames
   LOCAL pParam AS ELEMDESC PTR              ' // Pointer to an array of parameters
   LOCAL x AS LONG                           ' // Loop counter
   LOCAL szName AS ASCIIZ * 255              ' // Name
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL vt AS WORD                          ' // Variant type
   LOCAL pRefTypeInfo AS ITypeInfo           ' // Address to a referenced type description
   LOCAL pPrmTypeAttr AS TYPEATTR PTR        ' // Type attribute for the parameter
   LOCAL lptdesc AS TYPEDESC PTR             ' // Pointer to a TYPEDESC structure
   LOCAL strName AS STRING                   ' // General purpose variable
   LOCAL wFlags AS WORD                      ' // Parameter flags
   LOCAL wIndirectionLevel AS WORD           ' // Indirection level
   LOCAL vtOld AS WORD                       ' // Variant type
   LOCAL strVtPtr AS STRING                  ' // VT_PTR vartype
   LOCAL strParam AS STRING                  ' // Parameter
   LOCAL strParams AS STRING                 ' // Parameters
   LOCAL strAliasName AS STRING              ' // Alias name
   LOCAL szAliasTypeKind AS ASCIIZ * 256     ' // Alias type
   LOCAL typekind AS LONG                    ' // Alias type
   LOCAL strFlags AS STRING                  ' // Flags
   LOCAL szGuid AS ASCIIZ * 256              ' // Guid
   LOCAL strCoClassName AS STRING            ' // CoClass name
   LOCAL strPrefix AS STRING                 ' // Prefix
   LOCAL idx AS LONG                         ' // General purpose variable

   IF m_UsePrefix THEN strPrefix = TLB_PrefixStr

   ' Number of parameters
   cParams = @pFuncDesc.cParams
   ' Skip the last parameter for Put and PutRef properties
   IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT OR @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN cParams = cParams - 1
   IF cParams = 0 THEN EXIT FUNCTION

   ' -------------------------------------------------------------------------------------
   ' Gets the name of all the parameters.
   ' The first one is the name of the function.
   ' If the member ID identifies a property that is implemented with property functions,
   ' the property name is returned.For property get functions, the names of the function
   ' and its parameters are always returned.
   ' For property put and put reference functions, the right side of the assignment is
   ' unnamed. If cMaxNames is less than is required to return all of the names of the
   ' parameters of a function, then only the names of the first cMaxNames- 1 parameters
   ' are returned. The names of the parameters are returned in the array in the same
   ' order that they appear elsewhere in the interface (for example, the same order in
   ' the parameter array associated with the FUNCDESC enumeration).
   ' -------------------------------------------------------------------------------------
   REDIM rgbstrNames(cParams) AS WSTRING
   hr = ptinfo.GetNames(@pFuncDesc.memid, rgbstrNames(0), cParams + 1, pcNames)
   IF hr <> %S_OK THEN EXIT FUNCTION
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Pointer to an ELEMDESC structure
   ' -------------------------------------------------------------------------------------
   pParam = @pFuncDesc.lprgelemdescParam
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Retrieves information about all the parameters
   ' -------------------------------------------------------------------------------------
   FOR x = 0 TO cParams - 1

      ' ----------------------------------------------------------------------------------
      ' Allow for a breath and check the abort flag
      ' ----------------------------------------------------------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Parameter name and type
      ' ----------------------------------------------------------------------------------
      szName = rgbstrNames(x + 1)
      vt = @pParam[x].tdesc.vt
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Attributes
      ' ----------------------------------------------------------------------------------
      wFlags = @pParam[x].paramdesc.wParamFlags
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Resolve the type of the parameter
      ' ----------------------------------------------------------------------------------
      strName = ""
      strVtPtr = ""
      wIndirectionLevel = 0
      vtOld = 0
      IF vt = %VT_VOID THEN
         strParam = "DWORD"
      ELSEIF vt = %VT_USERDEFINED THEN
         hr = ptinfo.GetRefTypeInfo(@pParam[x].tdesc.hreftype, pRefTypeInfo)
         IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
            hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
            IF hr = %S_OK THEN strName = bstrName
            hr = pRefTypeInfo.GetTypeAttr(pPrmTypeAttr)
            IF pPrmTypeAttr <> %NULL THEN
               SELECT CASE @pPrmTypeAttr.typekind
                  CASE %TKIND_ENUM
                     strParam = "LONG"
                  CASE %TKIND_RECORD
'                      IF LEFT$(bstrName, 1) = "_" THEN
'                         strParam = "tag" & strName
'                      ELSE
'                         strParam = strName
'                      END IF
                       strParam = "DWORD"
                  CASE %TKIND_UNION
'                      IF LEFT$(strName, 1) = "_" THEN
'                         strParam = "u" & strName
'                      ELSE
'                         strParam = strName
'                      END IF
                       strParam = "DWORD"
                  CASE %TKIND_COCLASS
                     idx = 0
                     ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                     IF idx THEN
                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                        strParam = strPrefix & strName
                     ELSE
                        strParam = "IDispatch"
                     END IF
                  CASE %TKIND_INTERFACE
                     idx = 0
                     ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                     IF idx THEN
                        IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                        strParam = strPrefix & strName
                     ELSE
                        strParam = "IUnknown"
                     END IF
                  CASE %TKIND_DISPATCH
                     IF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                        strParam = "StdFont"
                        TLB_UsesFontInterface = %TRUE
                     ELSEIF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                        strParam = "StdPicture"
                        TLB_UsesPictureInterface = %TRUE
                     ELSE
'                        strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                        IF LEN(strCoClassName) THEN
'                           strParam = strPrefix & strCoClassName
'                        ELSE
'                           IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                           strParam = strPrefix & strName
'                        END IF
                        idx = 0
                        ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                        IF idx THEN
                           IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                           strParam = strPrefix & strName
                        ELSE
                           strParam = "IDispatch"
                        END IF
                     END IF
                  CASE %TKIND_ALIAS
                     IF @pPrmTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                        IF @pPrmTypeAttr.tdescalias.vt = %VT_BSTR THEN
                           strParam = "WSTRING"
                        ELSEIF @pPrmTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                           strParam = "WSTRINGZ"
                        ELSEIF @pPrmTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                           strParam = "ASCIIZ"
                        ELSEIF @pPrmTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                           strParam = "VARIANT"
                        ELSE
                           strParam = VarTypeToKeyword(@pPrmTypeAttr.tdescalias.vt)
                        END IF
                     ELSE
                        strAliasName = TLB_GetAliasName (pRefTypeInfo, @pPrmTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                        IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                           strAliasName = "StdFont"
                           TLB_UsesFontInterface = %TRUE
                        END IF
                        IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                           strAliasName = "StdPicture"
                           TLB_UsesPictureInterface = %TRUE
                        END IF
                        IF LEN(strAliasName) THEN
                           IF LEFT$(strAliasName, 1) = "_" THEN
                              IF typekind = %TKIND_RECORD THEN strAliasName = "tag" & strAliasName
                              IF typekind = %TKIND_UNION THEN strAliasName = "u" & strAliasName
                           END IF
                           IF typekind = %TKIND_ENUM OR typekind = %TKIND_MODULE THEN
'                              strParam = "LONG <" & strPrefix & strAliasName & ">"
                               strParam = "LONG"
                           ELSEIF typekind = %TKIND_COCLASS THEN
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                              IF idx THEN
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strParam = strPrefix & strAliasName
                              ELSE
                                 strParam = "IDispatch"
                              END IF
                           ELSEIF typekind = %TKIND_INTERFACE THEN
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                              IF idx THEN
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strParam = strPrefix & strAliasName
                              ELSE
                                 strParam = "IUnknown"
                              END IF
                           ELSEIF typekind = %TKIND_DISPATCH  THEN
'                              strCoClassName = TLB_GetCoClassNameFromArray(strAliasName)
'                              IF LEN(strCoClassName) THEN
'                                 strParam = strPrefix & strCoClassName
'                              ELSE
'                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                 strParam = strPrefix & strAliasName
'                              END IF
                              idx = 0
                              ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                              IF idx THEN
                                 IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                 strParam = strPrefix & strAliasName
                              ELSE
                                 strParam = "IDispatch"
                              END IF
                           ELSEIF typekind = %TKIND_RECORD OR typekind = %TKIND_UNION THEN
'                              strParam = strAliasName
                              strParam = "DWORD"
                           ELSE
                              strParam = strAliasName
                           END IF
                        ELSE
                           strParam = "DWORD"
                        END IF
                     END IF
               END SELECT
               pRefTypeInfo.ReleaseTypeAttr pPrmTypeAttr
               pPrmTypeAttr = 0
            END IF
         END IF
      ELSEIF vt = %VT_PTR THEN
         vtOld = vt
         strVtPtr = "VT_PTR"
         wIndirectionLevel = 1
         ' // Gets a pointer to another TYPEDESC structure
         lptdesc = @pParam[x].tdesc.lptdesc
         DO
            ' // VarType
            vt = @lptdesc.vt
            SELECT CASE vt
               ' // If it is another pointer, loop again
               CASE %VT_PTR
                  strVtPtr = strVtPtr & "->VT_PTR"
                  INCR wIndirectionLevel
                  lptdesc = @lptdesc.lptdesc
               ' // If it is a userdefined type (record or enum), get the name
               ' // of the referenced type and store it
               CASE %VT_USERDEFINED
                  vtOld = vt
                  strVtPtr = strVtPtr & "->VT_USERDEFINED"
                  hr = ptinfo.GetRefTypeInfo(@lptdesc.hreftype, pRefTypeInfo)
                  IF ISTRUE ISOBJECT(pRefTypeInfo) THEN
                     hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                     IF hr = %S_OK THEN
                        strName = bstrName
                        hr = pRefTypeInfo.GetTypeAttr(pPrmTypeAttr)
                        IF pPrmTypeAttr <> %NULL THEN
                           SELECT CASE @pPrmTypeAttr.typekind
                              CASE %TKIND_ENUM
                                 strParam = "LONG"
                              CASE %TKIND_RECORD
'                                 IF LEFT$(strName, 1) = "_" THEN
'                                    strParam = "tag" & strName
'                                 ELSE
'                                    strParam = strName
'                                 END IF
                                  strParam = "DWORD"
                              CASE %TKIND_UNION
'                                 IF LEFT$(strName, 1) = "_" THEN
'                                    strParam = "u" & strName
'                                 ELSE
'                                    strParam = strName
'                                 END IF
                                  strParam = "DWORD"
                              CASE %TKIND_COCLASS
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                    strParam = strPrefix & strName
                                 ELSE
                                    strParam = "IDispatch"
                                 END IF
                              CASE %TKIND_INTERFACE
                                 idx = 0
                                 ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                 IF idx THEN
                                    IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                    strParam = strPrefix & strName
                                 ELSE
                                    strParam = "IUnknown"
                                 END IF
                              CASE %TKIND_DISPATCH
                                 IF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                    strParam = "StdFont"
                                    TLB_UsesFontInterface = %TRUE
                                 ELSEIF UCASE$(GUIDTXT$(@pPrmTypeAttr.guid)) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                    strParam = "StdPicture"
                                    TLB_UsesPictureInterface = %TRUE
                                 ELSE
'                                    strCoClassName = TLB_GetCoClassNameFromArray(strName)
'                                    IF LEN(strCoClassName) THEN
'                                       strParam = strPrefix & strCoClassName
'                                    ELSE
'                                       IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
'                                       strParam = strPrefix & strName
'                                    END IF
                                    idx = 0
                                    ARRAY SCAN TLB_InterfacesArray(), = strName, TO idx
                                    IF idx THEN
                                       IF LEFT$(strName, 1) = "_" THEN strName = MID$(strName, 2)
                                       strParam = strPrefix & strName
                                    ELSE
                                       strParam = "IUnknown"
                                    END IF
                                 END IF
                              CASE %TKIND_ALIAS
                                 IF @pPrmTypeAttr.tdescalias.vt <> %VT_USERDEFINED THEN
                                    IF @pPrmTypeAttr.tdescalias.vt = %VT_BSTR THEN
                                       strParam = "WSTRING"
                                    ELSEIF @pPrmTypeAttr.tdescalias.vt = %VT_LPWSTR THEN
                                       strParam = "WSTRINGZ"
                                    ELSEIF @pPrmTypeAttr.tdescalias.vt = %VT_LPSTR THEN
                                       strParam = "ASCIIZ"
                                    ELSEIF @pPrmTypeAttr.tdescalias.vt = %VT_VARIANT THEN
                                       strParam = "VARIANT"
                                    ELSE
                                       strParam = VarTypeToKeyword(@pPrmTypeAttr.tdescalias.vt)
                                    END IF
                                 ELSE
                                    strAliasName = TLB_GetAliasName (pRefTypeInfo, @pPrmTypeAttr.tdescalias.hreftype, szAliasTypeKind, typekind, szGuid)
                                    IF UCASE$(szGuid) = "{BEF6E003-A874-101A-8BBA-00AA00300CAB}" THEN
                                       strAliasName = "StdFont"
                                       TLB_UsesFontInterface = %TRUE
                                    END IF
                                    IF UCASE$(szGuid) = "{7BF80981-BF32-101A-8BBB-00AA00300CAB}" THEN
                                       strAliasName = "StdPicture"
                                       TLB_UsesPictureInterface = %TRUE
                                    END IF
                                    IF LEN(strAliasName) THEN
                                       IF LEFT$(strAliasName, 1) = "_" THEN
                                          IF typekind = %TKIND_RECORD THEN strAliasName = "tag" & strAliasName
                                          IF typekind = %TKIND_UNION THEN strAliasName = "u" & strAliasName
                                       END IF
                                       IF typekind = %TKIND_ENUM OR typekind = %TKIND_MODULE THEN
'                                           strParam = "LONG <" & strPrefix & strAliasName & ">"
                                           strParam = "LONG"
                                       ELSEIF typekind = %TKIND_COCLASS THEN
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                          IF idx THEN
                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                             strParam = strPrefix & strAliasName
                                          ELSE
                                             strParam = "IDispatch"
                                          END IF
                                       ELSEIF typekind = %TKIND_INTERFACE THEN
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                          IF idx THEN
                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                             strParam = strPrefix & strAliasName
                                          ELSE
                                             strParam = "IUnknown"
                                          END IF
                                       ELSEIF typekind = %TKIND_DISPATCH  THEN
'                                          strCoClassName = TLB_GetCoClassNameFromArray(strAliasName)
'                                          IF LEN(strCoClassName) THEN
'                                             strParam = strPrefix & strCoClassName
'                                          ELSE
'                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
'                                             strParam = strPrefix & strAliasName
'                                          END IF
                                          idx = 0
                                          ARRAY SCAN TLB_InterfacesArray(), = strAliasName, TO idx
                                          IF idx THEN
                                             IF LEFT$(strAliasName, 1) = "_" THEN strAliasName = MID$(strAliasName, 2)
                                             strParam = strPrefix & strAliasName
                                          ELSE
                                             strParam = "IDispatch"
                                          END IF
                                       ELSEIF typekind = %TKIND_RECORD OR typekind = %TKIND_UNION THEN
'                                          strParam = strAliasName
                                          strParam = "DWORD"
                                       ELSE
                                          strParam = strAliasName
                                       END IF
                                    ELSE
                                       strParam = "DWORD"
                                    END IF
                                 END IF
                           END SELECT
                           pRefTypeInfo.ReleaseTypeAttr pPrmTypeAttr
                           pPrmTypeAttr = 0
                        END IF
                     END IF
                  END IF
                  EXIT DO
               CASE ELSE
                  IF vt = %VT_VARIANT THEN
                     strParam = "VARIANT"
                  ELSEIF vt = %VT_BSTR THEN
                     strParam = "WSTRING"
                  ELSEIF vt = %VT_LPWSTR THEN
                     strParam = "WSTRINGZ"
                  ELSE
                     strParam = VarTypeToKeyword(vt)
                  END IF
                  EXIT DO
            END SELECT
         LOOP
      ELSEIF vt = %VT_BSTR THEN
         strParam = "WSTRING"
      ELSEIF vt = %VT_LPWSTR THEN
         strParam = "WSTRINGZ"
      ELSEIF vt = %VT_VARIANT THEN
         strParam = "VARIANT"
'      ELSEIF vt = %VT_DISPATCH OR vt = %VT_UNKNOWN THEN
'         strParam = "VARIANT"
      ELSEIF vt = %VT_UNKNOWN THEN
         strParam = "IUnknown"
      ELSEIF vt = %VT_DISPATCH THEN
         strParam = "IDispatch"
      ELSE
         strParam = VarTypeToKeyword(vt)
      END IF

      strFlags = ""
'      IF wFlags = 0 THEN
'         IF wIndirectionLevel <= 1 THEN wFlags = %PARAMFLAG_FIN ELSE wFlags = %PARAMFLAG_FOUT
'      END IF
      IF (wFlags AND %PARAMFLAG_FOPT) = %PARAMFLAG_FOPT THEN strFlags = "OPTIONAL "
      IF ((wFlags AND %PARAMFLAG_FIN) = %PARAMFLAG_FIN)  AND ((wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT) THEN
         strFlags = strFlags & "INOUT "
      ELSEIF (wFlags AND %PARAMFLAG_FIN) = %PARAMFLAG_FIN THEN
         strFlags = strFlags & "IN "
      ELSEIF (wFlags AND %PARAMFLAG_FOUT) = %PARAMFLAG_FOUT THEN
         strFlags = strFlags & "OUT "
      END IF

      ' Add a prefix to avoid name conflicts
      IF ISTRUE m_AddParameterNamesPrefix THEN
         IF LEFT$(UCASE$(szName), 5) <> "PARAM" AND LEFT$(UCASE$(szName), 3) <> "PRM" THEN szName = "prm_" & szName
      END IF
      IF x > 0 THEN strParams = strParams & "               "
'      strParams = strParams & strFlags & szName & " AS " & strParam & "<&H" & HEX$(x, 8) & ">"
      strParams = strParams & strFlags & szName & " AS " & strParam & "<" & FORMAT$(x) & ">"
      IF x < cParams - 1 THEN
'         strParams = strParams & ", "
         strParams = strParams & ", _ " & $CRLF
      END IF

   NEXT

   ' Workaround for buggy libraries with GET parameters with a wrong return type
   ' because the last parameters has not been flagged as [out, retval]
   IF ISTRUE bLastParamOnly THEN strParams = strParam

   FUNCTION = strParams

END FUNCTION
' ========================================================================================

' ========================================================================================
' Generates the code for the definition
' ========================================================================================
FUNCTION TLB_MakePBDefinitionCode ( _
   BYVAL hWnd AS DWORD, _                    ' // Window handle
   BYVAL typekind AS DWORD, _                ' // Type kind
   BYVAL ptlib AS ITypeLib, _                ' // ITypeLib interface
   BYVAL ptinfo AS ITypeInfo, _              ' // ITypeInfo interface
   BYVAL pTypeAttr AS TYPEATTR PTR _         ' // TYPEATTR structure
   ) AS LONG

   LOCAL hr AS LONG                          ' // HRESULT
   LOCAL pFuncDesc AS FUNCDESC PTR           ' // Pointer to a FUNCDESC structure
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL bstrDocString AS WSTRING            ' // Documentation string (unicode)
   LOCAL strFuncName AS STRING               ' // General purpose variable
   LOCAL strInvKind AS STRING                ' // Invoke kind
   LOCAL x AS LONG                           ' // Loop counter
   LOCAL strReturn AS STRING                 ' // Return type string
   LOCAL s AS STRING                         ' // General purpose variable
   LOCAL strParams AS STRING                 ' // Parameters

   IF @pTypeAttr.cFuncs = 0 THEN EXIT FUNCTION

   FOR x = 0 TO @pTypeAttr.cFuncs - 1

      ' Allow for a breath and check the abort flag
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR

      ' Gets a reference to the FuncDesc interface
      hr = ptinfo.GetFuncDesc(x, pFuncDesc)
      IF hr <> %S_OK OR pFuncDesc = %NULL THEN EXIT FOR
      ' Retrieve the name of the function
      hr = ptinfo.GetDocumentation(@pFuncDesc.memid, bstrName, bstrDocString, BYVAL %NULL, BYVAL %NULL)
      strFuncName = bstrName

      ' Skip restricted interfaces
'      IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FRESTRICTED) <> %TYPEFLAG_FRESTRICTED THEN

      ' Skip interfaces interfaces that only have the hidden attribute = &H10 (16)

'      If @pTypeAttr.wTypeFlags <> &H10 Then

         ' Skip unwanted methods and properties
'         IF strFuncName <> "QueryInterface" AND _
'            strFuncName <> "AddRef" AND _
'            strFuncName <> "Release" AND _
'            strFuncName <> "GetTypeInfoCount" AND _
'            strFuncName <> "GetTypeInfo" AND _
'            strFuncName <> "GetIDsOfNames" AND _
'            strFuncName <> "Invoke" AND _
'            LEFT$(strFuncName, 1) <> "_" AND _
'            ((@pFuncDesc.wFuncFlags AND %FUNCFLAG_FRESTRICTED) <> %FUNCFLAG_FRESTRICTED) THEN

         IF strFuncName <> "QueryInterface" AND _
            strFuncName <> "AddRef" AND _
            strFuncName <> "Release" AND _
            strFuncName <> "GetTypeInfoCount" AND _
            strFuncName <> "GetTypeInfo" AND _
            strFuncName <> "GetIDsOfNames" AND _
            strFuncName <> "Invoke" THEN

            IF UCASE$(strFuncName) = "_NEWENUM" THEN strFuncName = MID$(strFuncName, 2)
            DO
               IF LEFT$(strFuncName, 1) <> "_" THEN EXIT DO
               strFuncName = MID$(strFuncName, 2) & "_"
            LOOP

            ' ----------------------------------------------------------------------------
            ' Invoke kind
            ' ----------------------------------------------------------------------------
            strInvKind = ""
            SELECT CASE @pFuncDesc.invkind
               CASE %INVOKE_FUNC
                  strInvKind = "MEMBER CALL"
               CASE %INVOKE_PROPERTYGET
                  strInvKind = "MEMBER GET "
               CASE %INVOKE_PROPERTYPUT
                  strInvKind = "MEMBER LET "
               CASE %INVOKE_PROPERTYPUTREF
                  strInvKind = "MEMBER SET "
            END SELECT
            ' ----------------------------------------------------------------------------

            ' ----------------------------------------------------------------------------
            ' Parameters
            ' ----------------------------------------------------------------------------
            strParams = ""
'            s = "   " & strInvKind & " " & strFuncName & "<&H" & HEX$(@pFuncDesc.memid, 8) & ">"
            s = "   " & strInvKind & " " & strFuncName & " <" & FORMAT$(@pFuncDesc.memid) & "> "
            IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_VOID THEN
               IF @pFuncDesc.invkind = %INVOKE_FUNC THEN
                  strParams = TLB_PBInterfaceGetParametersInfo(hWnd, ptlib, ptinfo, pFuncDesc)
                  s = s & "(" & strParams & ")"
               ELSEIF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT OR @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN
                  strParams = TLB_PBInterfaceGetParametersInfo(hWnd, ptlib, ptinfo, pFuncDesc)
                  strReturn = TLB_PBInterfaceGetPutParameter(hWnd, ptlib, ptinfo, pFuncDesc)
                  s = s & "(" & strParams & ")   ' Parameter Type AS " & strReturn
               ELSEIF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN
                  ' Workaround for buggy libraries. GET properties always must return a value!
                  strReturn = TLB_PBInterfaceGetParametersInfo(hWnd, ptlib, ptinfo, pFuncDesc, %TRUE)
                  s = s & "(" & strParams & ") AS " & strReturn
               END IF
            ELSE
               strParams = TLB_PBInterfaceGetParametersInfo(hWnd, ptlib, ptinfo, pFuncDesc)
               strReturn = TLB_GetPBInterfaceReturnType(hWnd, ptlib, ptinfo, pFuncDesc)
               s = s & "(" & strParams & ") AS " & strReturn
            END IF
            TLB_AddLine(s)
            ' ----------------------------------------------------------------------------

         END IF

   '      End If
         ' ----------------------------------------------------------------------------------

'      END IF
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Release the FuncDesc interface
      ' ----------------------------------------------------------------------------------
      ptinfo.ReleaseFuncDesc pFuncDesc
      pFuncDesc = 0

   NEXT


END FUNCTION
' ========================================================================================

' ========================================================================================
' Generates code for the methods and properties definitions
' ========================================================================================
SUB TLB_MakePBInterfaceDefinitions (BYVAL hWnd AS DWORD, BYVAL ptlib AS ITypeLib)

   LOCAL hr AS LONG                          ' // HRESULT
   LOCAL bstrName AS WSTRING                 ' // Member's name (unicode)
   LOCAL bstrDocString AS WSTRING            ' // Documentation string (unicode)
   LOCAL pdwHelpContext AS DWORD             ' // Help context
   LOCAL bstrHelpFile AS WSTRING             ' // Help file (unicode)
   LOCAL pTypeAttr AS TYPEATTR PTR           ' // Address of a pointer to the TYPEATTR structure
   LOCAL ptinfo AS ITypeInfo                 ' // Reference to the TypeInfo interface
   LOCAL TypeInfoCount AS LONG               ' // Number of TypeInfos
   LOCAL pTKind AS DWORD                     ' // TYPEKIND
   LOCAL idx AS LONG                         ' // Index variable
   LOCAL i AS LONG                           ' // Loop counter
   LOCAL szText AS ASCIIZ * 256              ' // General purpose variable
   LOCAL strImplementedInterface AS STRING   ' // Implemented interface
   LOCAL strIntName AS STRING                ' // Interface name
   LOCAL strCoClassName AS STRING            ' // CoClass name
   LOCAL szEnumName AS ASCIIZ * 256          ' // Enumeration name
   LOCAL strAlias AS STRING                  ' // Alias name
   LOCAL strPrefix AS STRING                 ' // Prefix

   IF m_UsePrefix THEN strPrefix = TLB_PrefixStr

   TLB_UsesFontInterface = %FALSE
   TLB_UsesPictureInterface = %FALSE

   ' -------------------------------------------------------------------------------------
   ' Retrieves the number of TypeInfos
   ' -------------------------------------------------------------------------------------
   TypeInfoCount = ptlib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN
      MessageBox BYVAL %NULL, "This TypeLib doesn' have Type Infos" , _
         " " & FUNCNAME$ & ": ITypeLib_GetTypeInfoCount", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      GOTO Terminate
   END IF
   ' -------------------------------------------------------------------------------------

   ' -------------------------------------------------------------------------------------
   ' Parses the TypeLib
   ' -------------------------------------------------------------------------------------
   FOR i = 0 TO TypeInfoCount - 1

      ' ----------------------------------------------------------------------------------
      ' Allow for a breath and check the abort flag
      ' ----------------------------------------------------------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Retrieves the TypeKind
      ' ----------------------------------------------------------------------------------
      hr = ptlib.GetTypeInfoType(i, pTKind)
      IF hr THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the InfoType", _
            " " & FUNCNAME$ & ": ITypeLib_GetTypeInfoType", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Retrieves the TypeInfo interface
      ' ----------------------------------------------------------------------------------
      hr = ptlib.GetTypeInfo(i, ptinfo)
      IF hr <> %S_OK OR ISNOTHING(ptinfo) THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the TypeInfo interface" , _
            " " & FUNCNAME$ & ": ITypeLib_GetTypeInfo", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Gets the address of a pointer to the TYPEATTR structure
      ' ----------------------------------------------------------------------------------
      hr = ptinfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the address of the TypeAttr structure" , _
            " " & FUNCNAME$ & ": ITypeInfo_GetTypeAttr", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF
      ' ----------------------------------------------------------------------------------

      SELECT CASE pTKind

         ' ==================================================================================
         ' If it is an enumeration...
         ' ==================================================================================

         IF pTKind = %TKIND_ENUM THEN
            ' --- Retrieves the enumeration's name ------------------------------------------
            hr = ptlib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
            ' -- If it is the enumeration we are looking for... -----------------------------
            szEnumName = bstrName
            ' See if the name is an alias
            strAlias = TLB_GetAliasNameFromArray(szEnumName)
            DO
               IF LEFT$(strAlias, 1) <> "_" THEN EXIT DO
               strAlias = MID$(strAlias, 2)
            LOOP
            IF hr = %S_OK THEN
               ' --- Shows general information ----------------------------------------------
               IF @pTypeAttr.cVars THEN
                  TLB_AddLine("' ========================================================================================")
                  IF LEN(strAlias) THEN
                     TLB_AddLine("' " & strAlias & " enum")
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
                  TLB_EnumConstants(hWnd, ptinfo, @pTypeAttr.cVars, 0, szEnumName, strAlias, %FALSE)
                  TLB_AddLine("")
               END IF
            END IF
         END IF

         ' ==================================================================================
         ' If it is a dispatch interface...
         ' ==================================================================================
         CASE %TKIND_DISPATCH

            hr = ptlib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
            strIntName = bstrName
            ' Skip events interfaces
            idx = 0
            ARRAY SCAN TLB_EventsArray(), = strIntName, TO idx
'            IF ISFALSE idx AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FRESTRICTED) <> %TYPEFLAG_FRESTRICTED THEN
            IF ISFALSE idx THEN
               IF @pTypeAttr.cFuncs > 0 OR @pTypeAttr.cVars > 0 THEN
                  ' -------------------------------------------------------------------------
                  ' Information about the interface
                  ' -------------------------------------------------------------------------
                  strCoClassName = TLB_GetCoClassNameFromArray(strIntName)
                  TLB_AddLine("' ########################################################################################")
                  IF LEN(strCoClassName) THEN TLB_AddLine("' CoClass name = " & strCoClassName)
                  TLB_AddLine("' Interface name = " & strIntName)
                  szText = GUIDTXT$(@pTypeAttr.guid)
                  IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID = " & szText)
                  szText = bstrDocString
                  REPLACE ANY $CR & $LF WITH "  " IN szText
                  IF LEN(szText) THEN TLB_AddLine("' " & szText)
                  IF @pTypeAttr.wTypeFlags THEN TLB_AddLine("' Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
                  ' For dual interfaces, you obtain the base type of the interface
                  ' with GetRefTypeOfImplType(-1).
                  IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                     strImplementedInterface = TLB_GetInheritedInterface(ptinfo, -1)
                  ELSE
                     strImplementedInterface = TLB_GetImplementedInterface(ptinfo)
                  END IF
                  IF LEN(strImplementedInterface) THEN TLB_AddLine("' Inherited interface = " & strImplementedInterface)
                  TLB_AddLine("' ########################################################################################")
                  TLB_AddLine("")
                  IF LEFT$(strIntName, 1) = "_" THEN strIntName = MID$(strIntName, 2)
                  TLB_AddLine("#IF NOT %DEF(%" & strPrefix & strIntName & "_DISPINTERFACE_DEFINED)")
                  TLB_AddLine("    %" & strPrefix & strIntName & "_DISPINTERFACE_DEFINED = 1")
                  TLB_AddLine("")
'                  IF LEN(strCoClassName) THEN
'                     TLB_AddLine("INTERFACE IDBIND " & strPrefix & strCoClassName)
'                  ELSE
'                     TLB_AddLine("INTERFACE IDBIND " & strPrefix & strIntName)
'                  END IF
                  TLB_AddLine("INTERFACE IDBIND " & strPrefix & strIntName)
               END IF
               ' Enumerate the methods and properties
               IF @pTypeAttr.cFuncs > 0 THEN
                  TLB_MakePBDefinitionCode(hWnd, pTKind, ptlib, ptinfo, pTypeAttr)
               END IF
               ' Enumerate the data members
               IF @pTypeAttr.cVars > 0 THEN
                  TLB_PBInterfaceDataMembers(hWnd, ptinfo, @pTypeAttr.cVars)
               END IF
               ' Interface footer
               IF @pTypeAttr.cFuncs > 0 OR @pTypeAttr.cVars > 0 THEN
                  TLB_AddLine("END INTERFACE")
                  TLB_AddLine("")
                  TLB_AddLine("#ENDIF   ' /* __" & strPrefix & strIntName & "_DISPINTERFACE_DEFINED__ */")
                  TLB_AddLine("")
               END IF
            END IF

      END SELECT
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Releases the TYPEATTR structure
      ' ----------------------------------------------------------------------------------
      ptinfo.ReleaseTypeAttr pTypeAttr
      pTypeAttr = 0
      ' ----------------------------------------------------------------------------------

      ' ----------------------------------------------------------------------------------
      ' Releases the TypeInfo interface
      ' ----------------------------------------------------------------------------------
      ptinfo = NOTHING
      ' ----------------------------------------------------------------------------------

   NEXT
   ' -------------------------------------------------------------------------------------

Terminate:

   ' -------------------------------------------------------------------------------------
   ' Releases the interfaces
   ' -------------------------------------------------------------------------------------
   IF pTypeAttr <> %NULL THEN ptinfo.ReleaseTypeAttr pTypeAttr
   ptinfo = NOTHING
   ' -------------------------------------------------------------------------------------

   IF ISTRUE TLB_UsesFontInterface THEN TLB_AddStdFontDefinition(strPrefix)
   IF ISTRUE TLB_UsesPictureInterface THEN TLB_AddStdPictureDefinition(strPrefix)

END SUB
' ========================================================================================

' ========================================================================================
' Enumerates dispatch interfaces
' ========================================================================================
FUNCTION TLB_EnumDispInterfaces (BYVAL hWnd AS DWORD) AS LONG

   LOCAL hr                    AS LONG                 ' // HRESULT
   LOCAL hPageCtrl             AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hTreeView             AS DWORD                ' // TreeView handle
   LOCAL pITypeLib             AS ITypeLib             ' // TypeLib interface
   LOCAL hStatusBar            AS DWORD                ' // Handle of the status bar
   LOCAL hPrefixBox            AS DWORD                ' // Handle of the edit box
   LOCAL szText                AS ASCIIZ * 256         ' // General purpose variable
   LOCAL wszPath               AS WSTRINGZ * %MAX_PATH ' // Path (unicode)
   LOCAL hRichEditBox          AS DWORD                ' // Handle of the RichEdit control
   LOCAL hMenu                 AS DWORD                ' // Menu handle
   LOCAL hSubMenu              AS DWORD                ' // Submenu handle

   IF hWnd = %NULL THEN EXIT FUNCTION
   IF LEN(m_SelPath) = 0 THEN EXIT FUNCTION
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   hTreeView = GetDlgItem(hPageCtrl, %IDC_DIALOG1_TREEVIEW2)
   IF ISTRUE m_Busy THEN EXIT FUNCTION

   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
   IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
   IF hPrefixBox THEN GetWindowText(hPrefixBox, szText, SIZEOF(szText))
   TLB_PrefixStr = szText

   ' --- Loads the TypeLib ---------------------------------------------------------------
   wszPath = m_SelPath
   hr = LoadTypeLibEx(wszPath, %REGKIND_NONE, pITypeLib)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeLib) THEN
      MessageBox BYVAL %NULL, "Error &H" & HEX$(hr, 8) & " loading " & m_SelPath, _
             " " & FUNCNAME$ & ": LoadTypeLibEx", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      EXIT FUNCTION
   END IF

   m_Buffer = ""
   m_BufLen = 0
   MOUSEPTR 11   ' Hourglass cursor
   m_Busy = %TRUE
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_STOP, MAKLNG(%TRUE, 0))

   ' Header
   TLB_LibraryHeader(%ENUM_DISPINTERFACES)
   ' Ientifiers
   TLB_EnumIdentifiers(hWnd)
   ' Interface definitions
   TLB_MakePBInterfaceDefinitions hWnd, pITypeLib

   ' --- Show the report --------------------------------------------------------------
   MOUSEPTR 1   ' Arrow cursor
   ' Fill the richedit box with the generated code
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_CODE)
   IF hPageCtrl THEN
      hRichEditBox = GetDlgItem(hPageCtrl, %IDC_DIALOG1_RICHEDIT_VIEWCODE)
      szText = ""
      SendMessage hRichEditBox, %WM_SETTEXT, 0, VARPTR(szText)
      m_Buffer = LEFT$(m_Buffer, m_BufLen)
      SendMessage hRichEditBox, %WM_SETTEXT, 0, STRPTR(m_Buffer)
   END IF
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
   ' SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%FALSE, 0))
   ' SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%TRUE, 0))
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_STOP, MAKLNG(%FALSE, 0))
   hMenu = GetMenu(hWnd)
   hSubmenu = GetSubMenu(hMenu, 0)
   CoolMenu_EnableMenuItem hSubMenu, %IDM_RELOAD, %MF_GRAYED
   CoolMenu_EnableMenuItem hSubMenu, %IDM_SAVE, %MF_ENABLED
   ' CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
   SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_CODE))

   ' Release the interface
   pITypeLib = NOTHING

   ' Clear buffer and flags
   m_Buffer = ""
   m_BufLen = 0
   m_Busy = %FALSE
   m_Abort = %FALSE
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
