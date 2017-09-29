' ########################################################################################
' Microsoft Windows
' File: CVariant.inc
' Contents: Variant wrapper class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CVARIANT_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "propvarutil.inc"
#INCLUDE ONCE "Ole2Utils.inc"

' ########################################################################################
' CVariant Class
' ########################################################################################
CLASS CVariant

   INTERFACE IVariant : INHERIT IAutomation

   ' =====================================================================================
   ' Initializes a VARIANT.
   ' Note It is not really needed since PowerBASIC already initializes structures.
   ' =====================================================================================
   METHOD Init (BYREF pvar AS VARIANT)
      VariantInit(pVar)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears a VARIANT.
   ' =====================================================================================
   METHOD Clear (BYREF pvar AS VARIANT)
      METHOD OBJRESULT = VariantClear(pVar)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of one VARIANT structure to another.
   ' =====================================================================================
   METHOD Copy (BYREF pvarDest AS VARIANT, BYREF pvarSrc AS VARIANT)
      METHOD OBJRESULT = VariantCopy(pvarDest, pvarSrc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Frees any existing content of the destination variant and makes a copy of the source
   ' VARIANT, performing the necessary indirection if the source is specified to be VT_BYREF.
   ' =====================================================================================
   METHOD CopyInd (BYREF pvarDest AS VARIANT, BYREF pvarSrc AS VARIANT)
      METHOD OBJRESULT = VariantCopyInd(pvarDest, pvarSrc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with a Boolean value.
   ' =====================================================================================
   METHOD FromBoolean (BYVAL fVal AS LONG) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_BOOL
      @pv.boolVal = IIF&(fVal <> 0, -1, 0)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a 16-bit integer value.
   ' =====================================================================================
   METHOD FromInt16 (BYVAL iVal AS INTEGER) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_I2
      @pv.iVal = iVal
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with an unsigned 16-bit integer value.
   ' =====================================================================================
   METHOD FromUInt16 (BYVAL uiVal AS WORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_UI2
      @pv.uiVal = uiVal
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a 32-bit integer value.
   ' =====================================================================================
   METHOD FromInt32 (BYVAL lVal AS LONG) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_I4
      @pv.lVal = lVal
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with an unsigned 32-bit integer value.
   ' =====================================================================================
   METHOD FromUInt32 (BYVAL ulVal AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_UI4
      @pv.ulVal = ulVal
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a 64-bit integer value.
   ' =====================================================================================
   METHOD FromInt64 (BYVAL llVal AS QUAD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_I8
      @pv.llVal = llVal
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a value of type DOUBLE.
   ' =====================================================================================
   METHOD FromDouble (BYVAL dblVal AS DOUBLE) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_R8
      @pv.dblVal = dblVal
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a string.
   ' =====================================================================================
   METHOD FromString (BYREF pwsz AS WSTRINGZ) AS VARIANT
      LOCAL hr AS LONG
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_BSTR
      @pv.bstrVal = SysAllocString(pwsz)
      hr = IIF&(@pv.bstrVal <> 0, %S_OK, %E_OUTOFMEMORY)
      IF FAILED(hr) THEN VariantInit(v)
      METHOD OBJRESULT = hr
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT based on an instance of an IDispatch object.
   ' =====================================================================================
   METHOD FromDispatch (BYVAL pDisp AS IDispatch) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_DISPATCH
      @pv.pdispVal = OBJPTR(pDisp)
      IF @pv.pdispVal THEN pDisp.AddRef
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT based on an instance of an IUnknown object.
   ' =====================================================================================
   METHOD FromUnknown (BYVAL pUnk AS IUnknown) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_UNKNOWN
      @pv.punkVal = OBJPTR(pUnk)
      IF @pv.punkVal THEN pUnk.AddRef
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a date and time given in the format used by
   ' Microsoft MS-DOS. The date and time values are converted to the format used to store
   ' date and time in a VARIANT.
   ' =====================================================================================
   METHOD FromDosDateTime (BYVAL wDate AS WORD, BYVAL wTime AS WORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_DATE
      METHOD OBJRESULT = IIF&(DosDateTimeToVariantTime(wDate, wTime, @pv.date) = %TRUE, %S_OK, %S_FALSE)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT based on a string resource imbedded in an executable file.
   ' Creates a VT_BSTR variant. If the resource does not exist, this function initializes
   ' the VARIANT as VT_EMPTY and returns a failure code.
   ' =====================================================================================
   METHOD FromResource (BYVAL hInst AS DWORD, BYVAL id AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromResource(hInst, id, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with the contents of a buffer.
   ' Creates a VT_ARRAY | VT_UI1 variant.
   ' =====================================================================================
   METHOD FromBuffer (BYVAL pv AS DWORD, BYVAL cb AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromBuffer(BYVAL pv, cb, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT based on a GUID. Creates a VT_BSTR variant.
   ' =====================================================================================
   METHOD FromGUIDAsString (BYREF rguid AS GUID) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromGUIDAsString(rguid, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT based on a GUID. The structure is initialized as
   ' VT_ARRAY | VT_UI1.
   ' =====================================================================================
   METHOD FromGUIDAsBuffer (BYREF rguid AS GUID) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromBuffer(rguid, 16, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with the contents of a FILETIME structure.
   ' Creates a VT_DATE variant.
   ' =====================================================================================
   METHOD FromFileTime (BYREF pft AS FILETIME) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromFileTime(pft, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of FILETIME structures.
   ' Creates a VT_ARRAY | VT_DATE variant.
   ' =====================================================================================
   METHOD FromFileTimeArray (BYREF prgft AS FILETIME, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromFileTimeArray(prgft, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a string stored in a STRRET structure.
   ' Creates a VT_BSTR variant.
   ' =====================================================================================
   METHOD FromStrRet (BYREF pstrret AS STRRET, BYVAL pidl AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromStrRet(pstrret, pidl, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with a value stored in another VARIANT.
   ' =====================================================================================
   METHOD FromVariantArrayElem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromVariantArrayElem(varIn, iElem, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT from an array of Boolean values.
   ' Creates a VT_ARRAY | VT_BOOL variant.
   ' =====================================================================================
   METHOD FromBooleanArray (BYREF prgf AS LONG, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromBooleanArray(prgf, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT from an array of 16-bit values.
   ' Creates a VT_ARRAY | VT_I2 variant.
   ' =====================================================================================
   METHOD FromInt16Array (BYREF prgn AS INTEGER, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromInt16Array(prgn, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of unsigned 16-bit integer values.
   ' Creates a VT_ARRAY | VT_UI2 variant.
   ' =====================================================================================
   METHOD FromUInt16Array (BYREF prgn AS WORD, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromUInt16Array(prgn, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of 32-bit integer values.
   ' Creates a VT_ARRAY | VT_I4 variant.
   ' =====================================================================================
   METHOD FromInt32Array (BYREF prgn AS LONG, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromInt32Array(prgn, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of unsigned 32-bit integer values.
   ' Creates a VT_ARRAY | VT_UI4 variant.
   ' =====================================================================================
   METHOD FromUInt32Array (BYREF prgn AS DWORD, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromUInt32Array(prgn, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of 64-bit integer values.
   ' Creates a VT_ARRAY | VT_I8 variant.
   ' =====================================================================================
   METHOD FromInt64Array (BYREF prgn AS QUAD, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromInt64Array(prgn, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of values of type float.
   ' Note The Windows API does not provide a InitVariantFromFloatArray function.
   ' =====================================================================================
   METHOD FromFloatArray (BYREF prgn AS SINGLE, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      IF cElems < 1 OR VARPTR(prgn) = 0 THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      DIM rgflt() AS SINGLE
      REDIM rgflt(cElems - 1) AT VARPTR(prgn)
      v = rgflt()
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of values of type DOUBLE.
   ' Creates a VT_ARRAY | VT_R8 variant.
   ' =====================================================================================
   METHOD FromDoubleArray (BYREF prgn AS DOUBLE, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromDoubleArray(prgn, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with an array of wide strings pointers.
   ' Creates a VT_ARRAY | VT_BSTR variant.
   ' Note: The strings must have been allocated with CoTaskMemAlloc, e.g.
   ' DIM rgwsz(1) AS DWORD
   ' rgwsz(0) = WStrAlloc("Test string 1")
   ' rgwsz(1) = WStrAlloc("Test string 2")
   ' v = pv.FromStringArray(rgwsz(0), 1)
   ' WstrAlloc is a wrapper function included in windows.inc.
   ' =====================================================================================
   METHOD FromStringArray (BYREF prgsz AS DWORD, BYVAL cElems AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = InitVariantFromStringArray(prgsz, cElems, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts the value of a Boolean property from a VARIANT.
   ' Note: Returns 0 or 1 instead of 0 or -1.
   ' =====================================================================================
   METHOD ToBoolean (BYREF varIn AS VARIANT) AS LONG
      LOCAL bRet AS LONG
      METHOD OBJRESULT = VariantToBoolean(varIn, bRet)
      METHOD = bRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts a BOOL value from a VARIANT. If no value exists, then the specified
   ' default value is returned.
   ' Note: Returns 0 or 1 instead of 0 or -1.
   ' =====================================================================================
   METHOD ToBooleanWithDefault (BYREF varIn AS VARIANT, BYVAL fDefault AS LONG) AS LONG
      METHOD = VariantToBooleanWithDefault(varIn, fDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts the Int16 property value of a VARIANT.
   ' =====================================================================================
   METHOD ToInt16 (BYREF varIn AS VARIANT) AS INTEGER
      LOCAL iRet AS INTEGER
      METHOD OBJRESULT = VariantToInt16(varIn, iRet)
      METHOD = iRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an Int16 property value of a VARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToInt16WithDefault (BYREF varIn AS VARIANT, BYVAL iDefault AS INTEGER) AS INTEGER
      METHOD = VariantToInt16WithDefault(varIn, iDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an unsigned Int16 property value of a VARIANT.
   ' =====================================================================================
   METHOD ToUInt16 (BYREF varIn AS VARIANT) AS WORD
      LOCAL uiRet AS WORD
      METHOD OBJRESULT = VariantToUInt16(varIn, uiRet)
      METHOD = uiRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an unsigned Int16 property value of a VARIANT. If no value exists,
   ' then the specified default value is returned.
   ' =====================================================================================
   METHOD ToUInt16WithDefault (BYREF varIn AS VARIANT, BYVAL uiDefault AS WORD) AS WORD
      METHOD = VariantToUInt16WithDefault(varIn, uiDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an Int32 property value of a VARIANT.
   ' =====================================================================================
   METHOD ToInt32 (BYREF varIn AS VARIANT) AS LONG
      LOCAL plRet AS LONG
      METHOD OBJRESULT = VariantToInt32(varIn, plRet)
      METHOD = plRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an Int32 property value of a VARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToInt32WithDefault (BYREF varIn AS VARIANT, BYVAL lDefault AS LONG) AS LONG
      METHOD = VariantToInt32WithDefault(varIn, lDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts unsigned Int32 property value of a VARIANT.
   ' =====================================================================================
   METHOD ToUInt32 (BYREF varIn AS VARIANT) AS DWORD
      LOCAL pulRet AS DWORD
      METHOD OBJRESULT = VariantToUInt32(varIn, pulRet)
      METHOD = pulRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts unsigned Int32 property value of a VARIANT. If no value can be
   ' extracted, then a default value is assigned.
   ' =====================================================================================
   METHOD ToUInt32WithDefault (BYREF varIn AS VARIANT, BYVAL ulDefault AS DWORD) AS DWORD
      METHOD = VariantToUInt32WithDefault(varIn, ulDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an Int64 property value of a VARIANT.
   ' =====================================================================================
   METHOD ToInt64 (BYREF varIn AS VARIANT) AS QUAD
      LOCAL pllRet AS QUAD
      METHOD OBJRESULT = VariantToInt64(varIn, pllRet)
      METHOD = pllRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts unsigned Int32 property value of a VARIANT. If no value can be
   ' extracted, then a default value is assigned.
   ' =====================================================================================
   METHOD ToInt64WithDefault (BYREF varIn AS VARIANT, BYVAL llDefault AS QUAD) AS QUAD
      METHOD = VariantToInt64WithDefault(varIn, llDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts a DOUBLE value from a VARIANT.
   ' =====================================================================================
   METHOD ToDouble (BYREF varIn AS VARIANT) AS DOUBLE
      LOCAL pdblRet AS DOUBLE
      METHOD OBJRESULT = VariantToDouble(varIn, pdblRet)
      METHOD = pdblRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts a DOUBLE value from a VARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToDoubleWithDefault (BYREF varIn AS VARIANT, BYVAL dblDefault AS DOUBLE) AS DOUBLE
      METHOD = VariantToDoubleWithDefault(varIn, dblDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the contents of a buffer stored in a VARIANT of type VT_ARRRAY | VT_UI1.
   ' =====================================================================================
   METHOD ToBuffer (BYREF varIn AS VARIANT, BYVAL pv AS DWORD, BYVAL cb AS DWORD)
      METHOD OBJRESULT = VariantToBuffer(varIn, BYVAL pv, cb)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts a GUID property value of a VARIANT.
   ' =====================================================================================
   METHOD ToGUID (BYREF varIn AS VARIANT) AS GUID
      LOCAL pguid AS GUID
      METHOD OBJRESULT = VariantToGUID(varIn, pguid)
      METHOD = pguid
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts the variant value of a VARIANT to a string.
   ' Note Does not work with float (SINGLE) values.
   ' =====================================================================================
   METHOD ToString (BYREF varIn AS VARIANT, BYREF pszBuf AS WSTRINGZ, BYVAL cchBuf AS DWORD)
      METHOD OBJRESULT = VariantToString(varIn, pszBuf, cchBuf)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts the string property value of a VARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToStringWithDefault (BYREF varIn AS VARIANT, BYREF pszDefault AS WSTRINGZ) AS WSTRING
      LOCAL pwsz AS WSTRINGZ PTR
      pwsz = VariantToStringWithDefault(varIn, pszDefault)
      IF pwsz THEN
         METHOD = @pwsz
         CoTaskMemFree(BYVAL pwsz)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts the variant value of a VARIANT to a newly-allocated string.
   ' Note: VariantToStringAlloc does not work with float (SINGLE / VT_R4) values, so I'm
   ' using a workaround.
   ' =====================================================================================
   METHOD ToStringAlloc (BYREF varIn AS VARIANT) AS WSTRING

      LOCAL i AS LONG
      LOCAL hr AS LONG
      LOCAL ppszBuf AS WSTRINGZ PTR
      LOCAL pv AS tagVARIANT PTR
      LOCAL pvData AS SINGLE PTR
      LOCAL cElems AS LONG
      LOCAL pSb AS IStringBuilderW
      LOCAL nDims AS LONG
      LOCAL nLBound AS LONG
      LOCAL nUBound AS LONG
      LOCAL nBytes AS LONG
      LOCAL pData AS DWORD

      IF VARPTR(varIn) = 0 THEN
         METHOD OBJRESULT = %E_POINTER
         EXIT METHOD
      END IF

      pv = VARPTR(varIn)
      IF VARIANTVT(varIn) = %VT_R4 THEN
         IF @pv.fltVal THEN METHOD = FORMAT$(@pv.fltVal)
      ELSEIF VARIANTVT(varIn) = (%VT_ARRAY OR %VT_R4) THEN
         ' ----------------------------------------------------------------
         ' Alternate way. Easier to implement but slower and wastes memory.
         ' ----------------------------------------------------------------
         ' LOCAL bstr AS WSTRING
         ' // Extract the array
         ' DIM rgflt(0) AS SINGLE
         ' rgflt() = varIn
         '  // Convert the contents to a string
         ' FOR i = LBOUND(rgflt) TO UBOUND(rgflt)
         '    IF rgflt(i) < 0 THEN
         '       bstr += " " & STR$(rgflt(i)) & ";"
         '    ELSE
         '       bstr += STR$(rgflt(i)) & ";"
         '    END IF
         ' NEXT
         ' // Remove the leading space and the trailing ;
         ' IF LEN(bstr) THEN bstr = MID$(bstr, 2, LEN(bstr) - 2)
         ' METHOD = bstr
         ' ----------------------------------------------------------------
         ' // Number of elements in the array
         cElems = VariantGetElementCount(varIn)
         IF cElems THEN
            IF @pv.parray THEN
               ' // Access the data directly and convert it to string
               hr = SafeArrayAccessData(@pv.parray, pvData)
               IF hr = %S_OK THEN
                  pSb = CLASS "StringBuilderW"
                  IF ISOBJECT(pSb) THEN
                     pSb.Capacity = cElems * 20  ' Allocate space
                     FOR i = 0 TO cElems - 1
                        IF i = 0 THEN
                           ' // The first one has not a leading space
                           pSb.Add(FORMAT$(@pvData) & ";")
                        ELSE
                           IF @pvData < 0 THEN
                              ' // Negative numbers
                              pSb.Add(" " & STR$(@pvData) & ";")
                           ELSE
                              IF i < cElems - 1 THEN
                                 pSb.Add(STR$(@pvData) & ";")
                              ELSE
                                 ' // The last one has not a trailing ;
                                 pSb.Add(STR$(@pvData))
                              END IF
                           END IF
                        END IF
                        INCR pvData
                     NEXT
                     SafeArrayUnaccessData @pv.parray
                     METHOD = pSb.String
                     pSb = NOTHING
                  END IF
               END IF
            ' // Convert the contents to a string
            END IF
         END IF
         EXIT METHOD
      ELSEIF VARIANTVT(varIn) = (%VT_ARRAY OR %VT_I1) OR VARIANTVT(varIn) = (%VT_ARRAY OR %VT_UI1) THEN   ' Array of bytes
         ' ----------------------------------------------------------------
         ' Alternate way. Easier to implement but slower and wastes memory.
         ' ----------------------------------------------------------------
         ' LOCAL nBytes AS LONG
         ' DIM   vByteArray(0) AS BYTE
         ' ' // Convert the variant to an array of bytes
         ' vByteArray() = varIn
         ' ' // Convert the array of bytes to a string
         ' nBytes = UBOUND(vByteArray) - LBOUND(vByteArray) + 1
         ' IF nBytes THEN FUNCTION = PEEK$(VARPTR(vByteArray(0)), nBytes)
         ' ----------------------------------------------------------------
         ' // Get a pointer to the returned safearray
         pv = VARPTR(varIn)
         IF @pv.parray THEN
            ' // Retrieve the number of dimensions (must be 1)
            nDims = SafeArrayGetDim(@pv.parray)
            IF nDims = 1 THEN
               ' // Retrieve the number of elements of the array
               SafeArrayGetLBound(@pv.parray, 1, nLBound)
               SafeArrayGetUBound(@pv.parray, 1, nUBound)
               ' // Calculate the number of bytes to read
               nBytes = nUbound - nLBound + 1
               IF nBytes THEN
                  ' // Lock the safearray for access
                  SafeArrayAccessData(@pv.parray, pData)
                  IF pData THEN
                     ' // Read the data
                     METHOD = PEEK$(pData, nBytes)
                     ' // Unlock the array
                     SafeArrayUnaccessData(@pv.parray)
                  END IF
               END IF
            END IF
         END IF
      ELSE
         ' // Use VariantToStringAlloc to do the conversion
         METHOD OBJRESULT = VariantToStringAlloc(varIn, ppszBuf)
         ' // Return the result and free alloctaed memory
         IF ppszBuf THEN
            METHOD = @ppszBuf
            CoTaskMemFree(BYVAL ppszBuf)
         END IF
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a date and time value in Microsoft MS-DOS format from a VARIANT.
   ' =====================================================================================
   METHOD ToDosDateTime (BYREF varIn AS VARIANT, BYREF pwDate AS WORD, BYVAL pwTime AS WORD)
      METHOD OBJRESULT = VariantToDosDateTime(varIn, pwDate, pwTime)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' If the source variant is a VT_BSTR, extracts string and places it into a STRRET structure.
   ' =====================================================================================
   METHOD ToStrRet (BYREF varIn AS VARIANT) AS STRRET
      LOCAL pstrret AS STRRET
      METHOD OBJRESULT = VariantToStrRet(varIn, pstrret)
      METHOD = pstrret
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a FILETIME structure from a VARIANT.
   ' =====================================================================================
   METHOD ToFileTime (BYREF varIn AS VARIANT, BYVAL stfOut AS DWORD) AS FILETIME
      LOCAL pftOut AS FILETIME
      METHOD OBJRESULT = VariantToFileTime(varIn, stfOut, pftOut)
      METHOD = pftOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an array of Boolean values from a VARIANT structure.
   ' =====================================================================================
   METHOD ToBooleanArray (BYREF varIn AS VARIANT, BYREF prgf AS LONG, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToBooleanArray(varIn, prgf, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into an Int16 array.
   ' =====================================================================================
   METHOD ToInt16Array (BYREF varIn AS VARIANT, BYREF prgn AS INTEGER, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToInt16Array(varIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a newly-allocated unsigned Int16 array.
   ' =====================================================================================
   METHOD ToUInt16Array (BYREF varIn AS VARIANT, BYREF prgn AS WORD, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToUInt16Array(varIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into an Int32 array.
   ' =====================================================================================
   METHOD ToInt32Array (BYREF varIn AS VARIANT, BYREF prgn AS LONG, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToInt32Array(varIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into an Int32 array.
   ' =====================================================================================
   METHOD ToUInt32Array (BYREF varIn AS VARIANT, BYREF prgn AS DWORD, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToUInt32Array(varIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into an unsigned Int64 array.
   ' =====================================================================================
   METHOD ToInt64Array (BYREF varIn AS VARIANT, BYREF prgn AS QUAD, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToInt64Array(varIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts an array of DOUBLE values from a VARIANT.
   ' =====================================================================================
   METHOD ToDoubleArray (BYREF varIn AS VARIANT, BYREF prgn AS DOUBLE, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToDoubleArray(varIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a String array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' DIM prgsz(1) AS WSTRINGZ PTR
   ' cElem = pv.ToStringArray(v, prgsz(0), 2)
   ' LOCAL i AS LONG
   ' ' // Display the strings
   ' FOR i = 0 TO cElem - 1
   '    ? @prgsz(i)
   ' NEXT
   ' ' // Free the memory allocated for the strings
   ' FOR i = 0 TO cElem - 1
   '    CoTaskMemFree prgsz(i)
   ' NEXT
   ' =====================================================================================
   METHOD ToStringArray (BYREF varIn AS VARIANT, BYREF prgsz AS DWORD, BYVAL crgsz AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToStringArray(varIn, prgsz, crgsz, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Allocates an array of BOOL values then extracts data from a VARIANT into that array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgf AS LONG PTR
   ' cElem = pv.ToBooleanArrayAlloc(v, pprgf)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgf[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgf THEN CoTaskMemFree pprgf
   ' =====================================================================================
   METHOD ToBooleanArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgf AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToBooleanArrayAlloc(varIn, pprgf, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a newly-allocated Int16 array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS INTEGER PTR
   ' cElem = pv.ToInt16ArrayAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToInt16ArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToInt16ArrayAlloc(varIn, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a vector structure into a newly-allocated Int16 array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS WORD PTR
   ' cElem = pv.ToUInt16ArrayAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToUInt16ArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToUInt16ArrayAlloc(varIn, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a newly-allocated Int32 array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS LONG PTR
   ' cElem = pv.ToInt32ArrayAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToInt32ArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToInt32ArrayAlloc(varIn, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a newly-allocated unsigned Int32 array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS DWORD PTR
   ' cElem = pv.ToUInt32ArrayAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToUInt32ArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToUInt32ArrayAlloc(varIn, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a newly-allocated Int64 array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS QUAD PTR
   ' cElem = pv.ToInt64ArrayAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToInt64ArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToInt64ArrayAlloc(varIn, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a vector structure into a newly-allocated unsigned Int64 array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Note PB does not currently support unsigned quads.
   ' =====================================================================================
'   METHOD ToUInt64ArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
'      LOCAL pcElem AS DWORD
'      METHOD OBJRESULT = VariantToUInt64ArrayAlloc(varIn, pprgn, pcElem)
'      METHOD = pcElem
'   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Allocates an array of DOUBLE values then extracts data from a VARIANT into that array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS DOUBLE PTR
   ' cElem = pv.ToDoubleArrayAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the array
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToDoubleArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToDoubleArrayAlloc(varIn, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Extracts data from a vector structure into a newly-allocated String array.
   ' Note Use CoTaskMemFree to release the returned array.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL prgsz AS DWORD PTR
   ' LOCAL pwsz AS WSTRINGZ PTR
   ' cElem = pv.ToStringArrayAlloc(v, prgsz)
   ' LOCAL i AS LONG
   ' // Display the strings
   ' FOR i = 0 TO cElem - 1
   '   pwsz = @prgsz[i]
   '   ? @pwsz
   ' NEXT
   ' IF prgsz THEN
   '    // Free the memory allocated for the strings
   '    FOR i = 0 TO cElem - 1
   '       pwsz = @prgsz[i]
   '       CoTaskMemFree pwsz
   '    NEXT
   '    // Free the memory allocated for the array
   '    CoTaskMemFree prgsz
   ' END IF
   ' =====================================================================================
   METHOD ToStringArrayAlloc (BYREF varIn AS VARIANT, BYREF pprgsz AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = VariantToStringArrayAlloc(varIn, pprgsz, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Get the element count. Returns number of elements for values of type VT_ARRAY; returns 1 otherwise.
   ' =====================================================================================
   METHOD GetElementCount (BYREF varIn AS VARIANT) AS DWORD
      METHOD = VariantGetElementCount(varIn)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Boolean element from a VARIANT.
   ' =====================================================================================
   METHOD GetBooleanElem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS LONG
      LOCAL pfVal AS DWORD
      METHOD OBJRESULT = VariantGetBooleanElem(varIn, iElem, pfVal)
      METHOD = pfVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Int16 element from a VARIANT.
   ' =====================================================================================
   METHOD GetInt16Elem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS INTEGER
      LOCAL pnVal AS INTEGER
      METHOD OBJRESULT = VariantGetInt16Elem(varIn, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single unsigned Int16 element from a VARIANT.
   ' =====================================================================================
   METHOD GetUInt16Elem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS WORD
      LOCAL pnVal AS INTEGER
      METHOD OBJRESULT = VariantGetUInt16Elem(varIn, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Int32 element from a VARIANT.
   ' =====================================================================================
   METHOD GetInt32Elem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS LONG
      LOCAL pnVal AS LONG
      METHOD OBJRESULT = VariantGetInt32Elem(varIn, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single unsigned Int32 element from a VARIANT.
   ' =====================================================================================
   METHOD GetUInt32Elem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS DWORD
      LOCAL pnVal AS DWORD
      METHOD OBJRESULT = VariantGetUInt32Elem(varIn, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Int64 element from a VARIANT.
   ' =====================================================================================
   METHOD GetInt64Elem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS QUAD
      LOCAL pnVal AS QUAD
      METHOD OBJRESULT = VariantGetInt64Elem(varIn, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts one double element from a VARIANT.
   ' =====================================================================================
   METHOD GetDoubleElem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS DOUBLE
      LOCAL pnVal AS DOUBLE
      METHOD OBJRESULT = VariantGetDoubleElem(varIn, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts one double element from a VARIANT.
   ' =====================================================================================
   METHOD GetStringElem (BYREF varIn AS VARIANT, BYVAL iElem AS DWORD) AS WSTRING
      LOCAL ppszVal AS WSTRINGZ PTR
      METHOD OBJRESULT = VariantGetStringElem(varIn, iElem, ppszVal)
      IF ppszVal THEN
         METHOD = @ppszVal
         CoTaskMemFree BYVAL ppszVal
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Frees the memory and references used by an array of VARIANTs stored in an array.
   ' =====================================================================================
   METHOD ClearVariantArray (BYREF pvars AS VARIANT, BYVAL cvars AS DWORD)
      ClearVariantArray(pvars, cvars)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Compares two VARIANTs, based on default comparison rules.
   ' =====================================================================================
   METHOD Compare (BYREF var1 AS VARIANT, BYREF var2 AS VARIANT) AS LONG
      METHOD = VariantCompare(var1, var2)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a VARTYPE is a float (SINGLE).
   ' =====================================================================================
   METHOD IsVarTypeFloat (BYVAL vt AS WORD) AS LONG
      METHOD = (vt = %VT_R4 OR vt = %VT_R8)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a variant is an array.
   ' =====================================================================================
   METHOD IsVariantArray (BYREF pvar AS VARIANT) AS LONG
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(pvar)
      METHOD = (@pv.vt AND %VT_ARRAY)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a variant is a string.
   ' =====================================================================================
   METHOD IsVariantString (BYREF pvar AS VARIANT) AS LONG
      METHOD = VariantToStringWithDefault(pvar, BYVAL %NULL) <> %NULL
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a VARTYPE is a number.
   ' =====================================================================================
   METHOD IsVarTypeNumber (BYVAL vt AS WORD) AS LONG
      METHOD = IsVarTypeInteger(vt) OR IsVarTypeFloat(vt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a VARTYPE is a signed integer.
   ' =====================================================================================
   METHOD IsVarTypeSignedInteger (BYVAL vt AS WORD) AS LONG
      LOCAL fRet AS LONG
      fRet = %FALSE
      SELECT CASE vt
         CASE %VT_I1, %VT_I2, %VT_I4, %VT_I8
            fRet = %TRUE
      END SELECT
      METHOD = fRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a VARTYPE is an unsigned integer.
   ' =====================================================================================
   METHOD IsVarTypeUnsignedInteger (BYVAL vt AS WORD) AS LONG
      LOCAL fRet AS LONG
      fRet = %FALSE
      SELECT CASE vt
         CASE %VT_UI1, %VT_UI2, %VT_UI4, %VT_UI8
            fRet = %TRUE
      END SELECT
      METHOD = fRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a VARTYPE is an integer.
   ' =====================================================================================
   METHOD IsVarTypeInteger (BYVAL vt AS WORD) AS LONG
      METHOD = IsVarTypeSignedInteger(vt) OR IsVarTypeUnsignedInteger(vt)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   '                                 *** Math methods ***
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the sum of two variants.
   ' =====================================================================================
   METHOD Add (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarAdd(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a bitwise And operation between two variants of any integral type.
   ' =====================================================================================
   METHOD And (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarAnd(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Concatenates two variants and returns the result.
   ' =====================================================================================
   METHOD Cat (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarCat(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the result from dividing two variants.
   ' =====================================================================================
   METHOD Div (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarDiv(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a bitwise equivalence on two variants.
   ' =====================================================================================
   METHOD Eqv (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarDiv(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts two variants of any type to integers then returns the result from dividing them.
   ' =====================================================================================
   METHOD Idiv (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarIdiv(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a bitwise implication on two variants.
   ' =====================================================================================
   METHOD Imp (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarImp(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Divides two variants and returns only the remainder.
   ' =====================================================================================
   METHOD Mod (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarMod(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the result from multiplying two variants.
   ' =====================================================================================
   METHOD Mul (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarMul(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a logical disjunction on two variants.
   ' =====================================================================================
   METHOD Or (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarOr(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the result of performing the power function with two variants.
   ' =====================================================================================
   METHOD Pow (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarPow(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the result of performing the power function with two variants.
   ' =====================================================================================
   METHOD Sub (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarSub(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a logical exclusion on two variants.
   ' =====================================================================================
   METHOD Xor (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarXor(pvarLeft, pvarRight, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a logical exclusion on two variants.
   ' =====================================================================================
   METHOD Abs (BYREF pvarIn AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarAbs(pvarIn, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the integer portion of a variant.
   ' =====================================================================================
   METHOD Fix (BYREF pvarIn AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarFix(pvarIn, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the integer portion of a variant.
   ' =====================================================================================
   METHOD Int (BYREF pvarIn AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarInt(pvarIn, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs logical negation on a variant.
   ' =====================================================================================
   METHOD Neg (BYREF pvarIn AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarNeg(pvarIn, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs the bitwise not negation operation on a variant.
   ' =====================================================================================
   METHOD Not (BYREF pvarIn AS VARIANT) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarNot(pvarIn, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Rounds a variant to the specified number of decimal places.
   ' =====================================================================================
   METHOD Round (BYREF pvarIn AS VARIANT, BYVAL cDecimals AS LONG) AS VARIANT
      LOCAL vRes AS VARIANT
      METHOD OBJRESULT = VarRound(pvarIn, cDecimals, vRes)
      METHOD = vRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs a logical exclusion on two variants.
   ' =====================================================================================
   METHOD Cmp (BYREF pvarLeft AS VARIANT, BYREF pvarRight AS VARIANT, BYVAL lcid AS DWORD, BYVAL dwFlags AS DWORD) AS LONG
      METHOD = VarCmp(pvarLeft, pvarRight, lcid, dwFlags)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   '                               *** Format methods ***
   ' #####################################################################################

   ' =====================================================================================
   ' Formats a variant into string form by parsing a format string.
   ' =====================================================================================
   METHOD Format (BYREF pvarIn AS VARIANT, BYREF pstrFormat AS WSTRINGZ, BYVAL iFirstDay AS LONG, _
      BYVAL iFirstWeek AS LONG, BYVAL dwFlags AS DWORD) AS WSTRING
      LOCAL bstrOut AS WSTRING
      METHOD OBJRESULT = VarFormat(pvarIn, pstrFormat, iFirstDay, iFirstWeek, dwFlags, bstrOut)
      METHOD = bstrOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Formats a variant into string form by parsing a format string.
   ' =====================================================================================
   METHOD FormatDateTime (BYREF pvarIn AS VARIANT, BYVAL iNamedFormat AS LONG, BYVAL dwFlags AS DWORD) AS WSTRING
      LOCAL bstrOut AS WSTRING
      METHOD OBJRESULT = VarFormatDateTime(pvarIn, iNamedFormat, dwFlags, bstrOut)
      METHOD = bstrOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Formats a variant into string form by parsing a format string.
   ' =====================================================================================
   METHOD FormatNumber (BYREF pvarIn AS VARIANT, BYVAL iNumDig AS LONG, BYVAL ilncLead AS LONG, _
      BYVAL iUseParens AS LONG, BYVAL iGroup AS LONG, BYVAL dwFlags AS DWORD) AS WSTRING
      LOCAL bstrOut AS WSTRING
      METHOD OBJRESULT = VarFormatNumber(pvarIn, iNumDig, ilncLead, iUseParens, iGroup, dwFlags, bstrOut)
      METHOD = bstrOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Formats a variant into string form by parsing a format string.
   ' =====================================================================================
   METHOD FormatPercent (BYREF pvarIn AS VARIANT, BYVAL iNumDig AS LONG, BYVAL ilncLead AS LONG, _
      BYVAL iUseParens AS LONG, BYVAL iGroup AS LONG, BYVAL dwFlags AS DWORD) AS WSTRING
      LOCAL bstrOut AS WSTRING
      METHOD OBJRESULT = VarFormatPercent(pvarIn, iNumDig, ilncLead, iUseParens, iGroup, dwFlags, bstrOut)
      METHOD = bstrOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Formats a variant into string form by parsing a format string.
   ' =====================================================================================
   METHOD FormatCurrency (BYREF pvarIn AS VARIANT, BYVAL iNumDig AS LONG, BYVAL ilncLead AS LONG, _
      BYVAL iUseParens AS LONG, BYVAL iGroup AS LONG, BYVAL dwFlags AS DWORD) AS WSTRING
      LOCAL bstrOut AS WSTRING
      METHOD OBJRESULT = VarFormatCurrency(pvarIn, iNumDig, ilncLead, iUseParens, iGroup, dwFlags, bstrOut)
      METHOD = bstrOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Formats a variant into string form by parsing a format string.
   ' =====================================================================================
   METHOD FormatFromTokens (BYREF pvarIn AS VARIANT, BYREF pstrFormat AS WSTRINGZ, BYVAL pbTokCur AS BYTE PTR, _
      BYVAL dwFlags AS DWORD, BYVAL lcid AS DWORD) AS WSTRING
      LOCAL bstrOut AS WSTRING
      METHOD OBJRESULT = VarFormatFromTokens(pvarIn, pstrFormat, pbTokCur, dwFlags, bstrOut, lcid)
      METHOD = bstrOut
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   '                          *** Miscellaneous methods ***
   ' #####################################################################################

   ' =====================================================================================
   ' Converts the variant from one type to another.
   ' =====================================================================================
   METHOD ChangeType (BYREF pvarDest AS VARIANT, BYREF pvarSrc AS VARIANT, BYVAL vtNew AS WORD, OPTIONAL BYVAL wFlags AS WORD)
      METHOD OBJRESULT = VariantChangeType(pvarDest, pvarSrc, wFlags, vtNew)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts the variant from one type to another.
   ' =====================================================================================
   METHOD ChangeTypeEx (BYREF pvarDest AS VARIANT, BYREF pvarSrc AS VARIANT, BYVAL vtNew AS WORD, OPTIONAL BYVAL lcid AS DWORD, BYVAL wFlags AS WORD)
      METHOD OBJRESULT = VariantChangeTypeEx(pvarDest, pvarSrc, lcid, wFlags, vtNew)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a VT_ERROR variant suitable for optional parameters.
   ' =====================================================================================
   METHOD OptPrm () AS VARIANT
      LOCAL v AS VARIANT
      v = ERROR %DISP_E_PARAMNOTFOUND
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a variant containing a null safearray of the specified type, suitable for
   ' parameters that, instead of being optional, require a variant with a null safearray of
   ' a given type.
   ' =====================================================================================
   METHOD NullArray (BYVAL vt AS WORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_ARRAY OR vt
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a variant of type VT_NULL.
   ' =====================================================================================
   METHOD NullVariant () AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_NULL
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' *** Initializes a VARIANT with a Boolean value by reference.
   ' =====================================================================================
   METHOD FromBooleanByRef (BYREF pboolVal AS INTEGER) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_BYREF OR %VT_BOOL
      pboolVal = IIF(pboolVal = 0, 0, -1)
      @pv.pboolVal = VARPTR(pboolVal)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a variant as VT_DECIMAL from string
   ' =====================================================================================
   METHOD FromDecimalString (BYREF strIn AS WSTRINGZ, OPTIONAL BYVAL lcid AS DWORD, BYVAL dwFlags AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = VarDecFromStr(strIn, lcid, dwFlags, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a variant as VT_DECIMAL from a decimal structure.
   ' =====================================================================================
   METHOD FromDecimalByRef (BYREF pdec AS DECIMAL) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_BYREF OR %VT_DECIMAL
      @pv.pdecVal = VARPTR(pdec)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a variant as VT_DATE from string.
   ' =====================================================================================
   METHOD FromDateString (BYREF strDate AS WSTRINGZ, OPTIONAL BYVAL lcid AS DWORD, BYVAL dwFlags AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pdateOut AS DOUBLE
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      METHOD OBJRESULT = VarDateFromStr(strDate, lcid, dwFlags, pdateOut)
      @pv.vt = %VT_DATE
      @pv.date = pdateOut
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a variant as VT_DATE from a DATE type.
   ' =====================================================================================
   METHOD FromVarDate (BYREF vbDate AS DOUBLE) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_DATE
      @pv.date = vbDate
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a variant as VT_DATE from a DATE type by reference.
   ' =====================================================================================
   METHOD FromVarDateByRef (BYREF pDate AS DOUBLE) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_BYREF OR %VT_DATE
      @pv.pdate = VARPTR(pDate)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a SYSTEMTIME to a VT_DATE variant.
   ' =====================================================================================
   METHOD FromSystemTime (BYREF st AS SYSTEMTIME) AS VARIANT
      LOCAL hr AS LONG
      LOCAL vbDate AS DOUBLE
      LOCAL vDate AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      hr = SystemTimeToVariantTime(st, vbDate)
      IF hr = 0 THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      pv = VARPTR(vDate)
      @pv.vt = %VT_DATE
      @pv.date = vbDate
      METHOD = vDate
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a supplied VT_DATE variant to a SYSTEMTIME.
   ' =====================================================================================
   METHOD ToSystemTime (BYREF vDate AS VARIANT) AS SYSTEMTIME
      LOCAL hr AS LONG
      LOCAL st AS SYSTEMTIME
      LOCAL vbDate AS DOUBLE
      LOCAL pv AS tagVARIANT PTR
      IF VARIANTVT(vDate) <> %VT_DATE THEN
         METHOD OBJRESULT = %DISP_E_BADVARTYPE
         EXIT METHOD
      END IF
      pv = VARPTR(vDate)
      vbDate = @pv.date
      hr = VariantTimeToSystemTime(vbDate, st)
      IF hr = 0 THEN
         METHOD OBJRESULT = %E_FAIL
         EXIT METHOD
      END IF
      METHOD = st
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT structure based on an instance of an IDispatch interface.
   ' =====================================================================================
   METHOD FromDispatchPtr (BYVAL pDisp AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_DISPATCH
      @pv.pdispVal = pDisp
      IF pDisp THEN IUnknown_AddRef(pDisp)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT structure based on an instance of an IUnknown interface.
   ' =====================================================================================
   METHOD FromUnknownPtr (BYVAL pUnk AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_UNKNOWN
      @pv.punkVal = pUnk
      IF pUnk THEN IUnknown_AddRef(pUnk)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a VARIANT with a reference to an UDT.
   ' =====================================================================================
   METHOD FromRecord (BYVAL pIRecordInfo AS IRecordInfo, BYVAL pRec AS DWORD) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_RECORD
      @pv.pvRecord = pRec
      @pv.pRecInfo = OBJPTR(pIRecordInfo)
      pIRecordInfo.AddRef
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an unicode string contained in a variant and maps it to an encoded UTF8 code page.
   ' =====================================================================================
   METHOD ToUtf8 (BYREF vVar AS VARIANT) AS STRING

      LOCAL Buffer AS STRING
      LOCAL x AS STRING
      LOCAL l AS LONG
      LOCAL hr AS LONG
      LOCAL pv AS tagVARIANT PTR

      IF VARPTR(vVar) = 0 THEN
         METHOD OBJRESULT = %E_INVALIDARG
         EXIT METHOD
      END IF
      pv = VARPTR(vVar)
      IF @pv.vt <> %VT_BSTR THEN
         METHOD OBJRESULT = %DISP_E_BADVARTYPE
         EXIT METHOD
      END IF
      IF @pv.bstrVal = 0 THEN EXIT METHOD
      l = lstrlenW(BYVAL @pv.bstrVal)
      IF l = 0 THEN EXIT METHOD
      x = PEEK$(@pv.bstrVal, l * 2)
      hr = WideCharToMultiByte (%CP_UTF8, %NULL, BYVAL STRPTR(x), l, _
           BYVAL %NULL, 0, BYVAL %NULL, BYVAL %NULL)
      IF hr = 0 THEN
         METHOD OBJRESULT = hr
         EXIT METHOD
      END IF
      Buffer = SPACE$(hr)
      hr = WideCharToMultiByte (%CP_UTF8, %NULL, BYVAL STRPTR(x), l, _
           BYVAL STRPTR(Buffer), LEN(Buffer), BYVAL %NULL, BYVAL %NULL)
      IF hr = 0 THEN
         METHOD OBJRESULT = hr
         EXIT METHOD
      END IF
      METHOD = Buffer

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an unicode string contained in a variant and maps it to an encoded UTF7 code page.
   ' =====================================================================================
   METHOD ToUtf7 (BYREF vVar AS VARIANT) AS STRING

      LOCAL Buffer AS STRING
      LOCAL x AS STRING
      LOCAL l AS LONG
      LOCAL hr AS LONG
      LOCAL pv AS tagVARIANT PTR

      IF VARPTR(vVar) = 0 THEN
         METHOD OBJRESULT = %E_INVALIDARG
         EXIT METHOD
      END IF
      pv = VARPTR(vVar)
      IF @pv.vt <> %VT_BSTR THEN
         METHOD OBJRESULT = %DISP_E_BADVARTYPE
         EXIT METHOD
      END IF
      IF @pv.bstrVal = 0 THEN EXIT METHOD
      l = lstrlenW(BYVAL @pv.bstrVal)
      IF l = 0 THEN EXIT METHOD
      x = PEEK$(@pv.bstrVal, l * 2)
      hr = WideCharToMultiByte (%CP_UTF7, %NULL, BYVAL STRPTR(x), l, _
           BYVAL %NULL, 0, BYVAL %NULL, BYVAL %NULL)
      IF hr = 0 THEN
         METHOD OBJRESULT = hr
         EXIT METHOD
      END IF
      Buffer = SPACE$(hr)
      hr = WideCharToMultiByte (%CP_UTF7, %NULL, BYVAL STRPTR(x), l, _
           BYVAL STRPTR(Buffer), LEN(Buffer), BYVAL %NULL, BYVAL %NULL)
      IF hr = 0 THEN
         METHOD OBJRESULT = hr
         EXIT METHOD
      END IF
      METHOD = Buffer

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a variant of type decimal to extended-precision floating-point.
   ' =====================================================================================
   METHOD VarDecToExt (BYVAL vDecimal AS VARIANT) AS EXT
      LOCAL vDate AS VARIANT
      LOCAL pv AS DECIMAL PTR
      LOCAL result AS EXT
      IF VARIANTVT(vDate) <> %VT_DECIMAL THEN
         METHOD OBJRESULT = %DISP_E_BADVARTYPE
         EXIT METHOD
      END IF
      pv = VARPTR(vDecimal)
      result = (@pv.Lo64 / (10 ^ @pv.scale)) + @pv.Hi32
      IF @pv.sign = &H80? THEN result = -result
      METHOD = result
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a variant of type decimal to currency.
   ' =====================================================================================
   METHOD VarDecToCy (BYVAL pdecIn AS VARIANT) AS CUR
      LOCAL hr AS LONG
      LOCAL pcyOut AS CUR
      METHOD OBJRESULT = VarCyFromDec(pdecIn, pcyOut)
      METHOD = pcyOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a variant of type decimal to a double.
   ' =====================================================================================
   METHOD VarDecToDouble (BYVAL pdecIn AS VARIANT) AS DOUBLE
      LOCAL hr AS LONG
      LOCAL pdblOut AS DOUBLE
      METHOD OBJRESULT = VarR8FromDec(pdecIn, pdblOut)
      METHOD = pdblOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a currency value to a VARIANT of type VT_DECIMAL.
   ' Note  Decimal numbers are 16 bytes in size, the same that a variant, but have a different
   ' structure, so they can't be converted using the PB function VARIANT#. Here we are using a
   ' variant as a buffer to hold the DECIMAL structure. The first two bytes of this structure
   ' are used to hold the variant type. The returned variant can be converted to a number
   ' using the function CyFromDec.
   ' =====================================================================================
   METHOD VarDecFromCy (BYVAL cyIn AS CUR) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_DECIMAL
      METHOD OBJRESULT = VarDecFromCy(cyIn, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a double value to a variant of type VT_DECIMAL.
   ' =====================================================================================
   METHOD VarDecFromDouble (BYVAL dbIn AS DOUBLE) AS VARIANT
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(v)
      @pv.vt = %VT_DECIMAL
      METHOD OBJRESULT = VarDecFromR8(dbIn, v)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts a VT_DATE variant to a variant representation (double)
   ' =====================================================================================
   METHOD VarDateToDouble (BYVAL vDate AS VARIANT) AS DOUBLE
      IF VARIANTVT(vDate) <> %VT_DATE THEN
         METHOD OBJRESULT = %DISP_E_BADVARTYPE
         EXIT METHOD
      END IF
      LOCAL pv AS tagVARIANT PTR
      pv = VARPTR(vDate)
      METHOD = @pv.date
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a variant to a tagVARIANT structure
   ' =====================================================================================
   METHOD ToVariantStruct (BYREF varIn AS VARIANT) AS tagVARIANT
      LOCAL v AS tagVARIANT
      METHOD OBJRESULT = VariantCopy(v, varIn)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a variant structure to a PowerBASIC VARIANT
   ' =====================================================================================
   METHOD FromVariantStruct (BYREF varIn AS tagVARIANT) AS VARIANT
      LOCAL v AS VARIANT
      METHOD OBJRESULT = VariantCopy(v, varIn)
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts the contents of a PROPVARIANT structure to a VARIANT structure.
   ' =====================================================================================
   METHOD FromPropVariant (BYREF pPropVar AS PROPVARIANT) AS VARIANT
      LOCAL pVar AS VARIANT
      METHOD OBJRESULT = PropVariantToVariant(pPropVar, pVar)
      METHOD = pVar
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a VARIANT structure to a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToPropVariant (BYREF pVar AS VARIANT) AS PROPVARIANT
      LOCAL pPropVar AS PROPVARIANT
      METHOD OBJRESULT = VariantToPropVariant(pPropVar, pVar)
      METHOD = pPropVar
   END METHOD
   ' =====================================================================================

   ' #####################################################################################

   END INTERFACE

END CLASS
' ########################################################################################

' ========================================================================================
' Creates an instance of the class.
' ========================================================================================
FUNCTION NewVariant () AS IVariant
   LOCAL pVar AS IVariant
   pVar = CLASS "CVariant"
   FUNCTION = pVar
END FUNCTION
' ========================================================================================
