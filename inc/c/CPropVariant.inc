' ########################################################################################
' Microsoft Windows
' File: CPropVariant.inc
' Contents: Propvariant wrapper class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CPROPVARIANT_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "propvarutil.inc"

' ########################################################################################
' CPropVariant Class
' ########################################################################################
CLASS CPropVariant

   INTERFACE IPropVariant : INHERIT IAutomation

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure.
   ' Note It is not really needed since PowerBASIC already initializes structures.
   ' =====================================================================================
   METHOD Init (BYREF propvar AS PROPVARIANT)
      ZeroMemory(BYVAL VARPTR(propvar), SIZEOF(PROPVARIANT))
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Frees all elements that can be freed in a given PROPVARIANT structure. For complex
   ' elements with known element pointers, the underlying elements are freed prior to
   ' freeing the containing element.
   ' =====================================================================================
   METHOD Clear (BYREF propvar AS PROPVARIANT)
      METHOD OBJRESULT = PropVariantClear(propvar)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of one PROPVARIANT structure to another.
   ' =====================================================================================
   METHOD Copy (BYREF propvarDest AS PROPVARIANT, BYREF propvarSrc AS PROPVARIANT)
      METHOD OBJRESULT = PropVariantCopy(propvarDest, propvarSrc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Coerces a value stored as a PROPVARIANT structure to an equivalent value of a
   ' different propvariant type.
   ' =====================================================================================
   METHOD ChangeType (BYREF propvarSrc AS PROPVARIANT, BYVAL vtNew AS WORD, OPTIONAL BYVAL flags AS LONG) AS PROPVARIANT
      LOCAL ppropvarDest AS PROPVARIANT
      METHOD OBJRESULT = PropVariantChangeType(ppropvarDest, propvarSrc, flags, vtNew)
      METHOD = ppropvarDest
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a VARIANT structure to a PROPVARIANT structure.
   ' =====================================================================================
   METHOD FromVariant (BYREF pVar AS VARIANT) AS PROPVARIANT
      LOCAL pPropVar AS PROPVARIANT
      METHOD OBJRESULT = VariantToPropVariant(pPropVar, pVar)
      METHOD = pPropVar
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts the contents of a PROPVARIANT structure to a VARIANT structure.
   ' =====================================================================================
   METHOD ToVariant (BYREF pPropVar AS PROPVARIANT) AS VARIANT
      LOCAL pVar AS VARIANT
      METHOD OBJRESULT = PropVariantToVariant(pVar, pPropVar)
      METHOD = pVar
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a VARIANT structure to a PROPVARIANT structure.
   ' =====================================================================================
   METHOD FromVariantStruct (BYREF pVar AS tagVARIANT) AS PROPVARIANT
      LOCAL pPropVar AS PROPVARIANT
      METHOD OBJRESULT = VariantToPropVariant(pPropVar, pVar)
      METHOD = pPropVar
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts the contents of a PROPVARIANT structure to a VARIANT structure.
   ' =====================================================================================
   METHOD ToVariantStruct (BYREF pPropVar AS PROPVARIANT) AS tagVARIANT
      LOCAL pVar AS tagVARIANT
      METHOD OBJRESULT = PropVariantToVariant(pVar, pPropVar)
      METHOD = pVar
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a Boolean value.
   ' =====================================================================================
   METHOD FromBoolean (BYVAL fVal AS LONG) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_BOOL
      pv.boolVal = IIF&(fVal <> 0, -1, 0)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a 16-bit integer value.
   ' =====================================================================================
   METHOD FromInt16 (BYVAL iVal AS INTEGER) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_I2
      pv.iVal = iVal
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with an unsigned 16-bit integer value.
   ' =====================================================================================
   METHOD FromUInt16 (BYVAL uiVal AS WORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_UI2
      pv.uiVal = uiVal
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a 32-bit integer value.
   ' =====================================================================================
   METHOD FromInt32 (BYVAL lVal AS LONG) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_I4
      pv.lVal = lVal
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with an unsigned 32-bit integer value.
   ' =====================================================================================
   METHOD FromUInt32 (BYVAL ulVal AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_UI4
      pv.ulVal = ulVal
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a 64-bit integer value.
   ' =====================================================================================
   METHOD FromInt64 (BYVAL llVal AS QUAD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_I8
      pv.hVal = llVal
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a value of type DOUBLE.
   ' =====================================================================================
   METHOD FromDouble (BYVAL dblVal AS DOUBLE) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_R8
      pv.dblVal = dblVal
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a string.
   ' =====================================================================================
   METHOD FromString (BYREF pwsz AS WSTRINGZ) AS PROPVARIANT
      LOCAL hr AS LONG
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_LPWSTR
      hr = SHStrDupW(pwsz, pv.pwszVal)
      IF FAILED(hr) THEN PropVariantInit(pv)
      METHOD OBJRESULT = hr
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT based on a string resource imbedded in an executable file.
   ' Creates a VT_LPWSTR propvariant. If the resource does not exist, this function initializes
   ' the PROPVARIANT with an empty string. Resource strings longer than 1024 characters
   ' are truncated and null-terminated.
   ' =====================================================================================
   METHOD FromResource (BYVAL hInst AS DWORD, BYVAL id AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromResource(hInst, id, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with the contents of a buffer.
   ' Creates a VT_VECTOR | VT_UI1 propvariant.
   ' =====================================================================================
   METHOD FromBuffer (BYVAL pBuffer AS DWORD, BYVAL cb AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromBuffer(BYVAL pBuffer, cb, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT based on a class identifier (CLSID).
   ' Creates a VT_CLSID propvariant.
   ' =====================================================================================
   METHOD FromCLSID (BYREF rclsid AS GUID) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromCLSID(rclsid, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT based on a GUID. Creates a VT_LPWSTR propvariant.
   ' =====================================================================================
   METHOD FromGUIDAsString (BYREF rguid AS GUID) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromGUIDAsString(rguid, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT based on a GUID. The structure is initialized as
   ' VT_ARRAY | VT_UI1.
   ' =====================================================================================
   METHOD FromGUIDAsBuffer (BYREF rguid AS GUID) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromBuffer(rguid, 16, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with the contents of a FILETIME structure.
   ' Creates a VT_FILETIME variant.
   ' =====================================================================================
   METHOD FromFileTime (BYREF pft AS FILETIME) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromFileTime(pft, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure from a specified vector of FILETIME values.
   ' Creates a VT_VECTOR | VT_FILETIME variant.
   ' =====================================================================================
   METHOD FromFileTimeVector (BYREF prgft AS FILETIME, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromFileTimeVector(prgft, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT with a string stored in a STRRET structure.
   ' Creates a VT_LPWSTR variant.
   ' =====================================================================================
   METHOD FromStrRet (BYREF pstrret AS STRRET, BYVAL pidl AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromStrRet(pstrret, pidl, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a specified PROPVARIANT vector element.
   ' =====================================================================================
   METHOD FromPropVariantVectorElem (BYREF propvarIn AS PROPVARIANT, BYVAL iElem AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromPropVariantVectorElem(propvarIn, iElem, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a vector element in a PROPVARIANT structure with a value stored in
   ' another PROPVARIANT.
   ' =====================================================================================
   METHOD VectorFromPropVariant (BYREF propvarSingle AS PROPVARIANT, BYVAL iElem AS DWORD) AS PROPVARIANT
      LOCAL ppropvarVector AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromPropVariantVectorElem(propvarSingle, iElem, ppropvarVector)
      METHOD = ppropvarVector
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure from a specified Boolean vector.
   ' Creates a VT_BOOL | VT_VECTOR propvariant.
   ' =====================================================================================
   METHOD FromBooleanVector (BYREF prgf AS LONG, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromBooleanVector(prgf, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a vector of Int164 values.
   ' Creates a VT_VECTOR | VT_I2 propvariant.
   ' =====================================================================================
   METHOD FromInt16Vector (BYREF prgn AS INTEGER, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromInt16Vector(prgn, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a vector of UInt16 values.
   ' Creates a VT_VECTOR | VT_UI2 propvariant.
   ' =====================================================================================
   METHOD FromUInt16Vector (BYREF prgn AS WORD, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromUInt16Vector(prgn, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a vector of Int32 values.
   ' Creates a VT_VECTOR | VT_I4 propvariant.
   ' =====================================================================================
   METHOD FromInt32Vector (BYREF prgn AS LONG, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromInt32Vector(prgn, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a vector of UInt32 values.
   ' Creates a VT_VECTOR | VT_UI4 propvariant.
   ' =====================================================================================
   METHOD FromUInt32Vector (BYREF prgn AS DWORD, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromUInt32Vector(prgn, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a vector of Int64 values.
   ' Creates a VT_VECTOR | VT_I8 propvariant.
   ' =====================================================================================
   METHOD FromInt64Vector (BYREF prgn AS QUAD, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitVariantFromInt64Array(prgn, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure based on a specified vector of double values.
   ' Creates a VT_VECTOR | VT_R8 propvariant.
   ' =====================================================================================
   METHOD FromDoubleVector (BYREF prgn AS DOUBLE, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromDoubleVector(prgn, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure from a specified string vector.
   ' Creates a VT_VECTOR | VT_LPWSTR variant.
   ' Note: The strings must have been allocated with CoTaskMemAlloc, e.g.
   ' DIM rgwsz(1) AS DWORD
   ' rgwsz(0) = WStrAlloc("Test string 1")
   ' rgwsz(1) = WStrAlloc("Test string 2")
   ' v = pv.FromStringArray(rgwsz(0), 1)
   ' WstrAlloc is a wrapper function included in windows.inc.
   ' =====================================================================================
   METHOD FromStringVector (BYREF prgsz AS DWORD, BYVAL cElems AS DWORD) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromStringVector(prgsz, cElems, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PROPVARIANT structure from a specified string. The string is parsed as
   ' a semi-colon delimited list (for example: "A;B;C").
   ' =====================================================================================
   METHOD FromStringAsVector (BYREF pwsz AS WSTRINGZ) AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      METHOD OBJRESULT = InitPropVariantFromStringAsVector(pwsz, pv)
      METHOD = pv
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the value of a Boolean property from a PROPVARIANT.
   ' Note: Returns 0 or 1 instead of 0 or -1.
   ' =====================================================================================
   METHOD ToBoolean (BYREF propvarIn AS PROPVARIANT) AS LONG
      LOCAL pfRet AS LONG
      METHOD OBJRESULT = VariantToBoolean(propvarIn, pfRet)
      METHOD = pfRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a BOOL value from a PROPVARIANT. If no value exists, then the specified
   ' default value is returned.
   ' Note: Returns 0 or 1 instead of 0 or -1.
   ' =====================================================================================
   METHOD ToBooleanWithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL fDefault AS LONG) AS LONG
      METHOD = PropVariantToBooleanWithDefault(propvarIn, fDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the Int16 property value of a PROPVARIANT.
   ' =====================================================================================
   METHOD ToInt16 (BYREF propvarIn AS PROPVARIANT) AS INTEGER
      LOCAL piRet AS INTEGER
      METHOD OBJRESULT = VariantToInt16(propvarIn, piRet)
      METHOD = piRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an Int16 property value of a PROPVARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToInt16WithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL iDefault AS INTEGER) AS INTEGER
      METHOD = PropVariantToInt16WithDefault(propvarIn, iDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an unsigned Int16 property value of a PROPVARIANT.
   ' =====================================================================================
   METHOD ToUInt16 (BYREF propvarIn AS PROPVARIANT) AS WORD
      LOCAL puiRet AS WORD
      METHOD OBJRESULT = PropVariantToUInt16(propvarIn, puiRet)
      METHOD = puiRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an unsigned Int16 property value of a PROPVARIANT. If no value exists,
   ' then the specified default value is returned.
   ' =====================================================================================
   METHOD ToUInt16WithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL uiDefault AS WORD) AS WORD
      METHOD = PropVariantToUInt16WithDefault(propvarIn, uiDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an Int32 property value of a PROPVARIANT.
   ' =====================================================================================
   METHOD ToInt32 (BYREF propvarIn AS PROPVARIANT) AS LONG
      LOCAL plRet AS LONG
      METHOD OBJRESULT = PropVariantToInt32(propvarIn, plRet)
      METHOD = plRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an Int32 property value of a PROPVARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToInt32WithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL lDefault AS LONG) AS LONG
      METHOD = PropVariantToInt32WithDefault(propvarIn, lDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts unsigned Int32 property value of a PROPVARIANT.
   ' =====================================================================================
   METHOD ToUInt32 (BYREF propvarIn AS PROPVARIANT) AS DWORD
      LOCAL pulRet AS DWORD
      METHOD OBJRESULT = PropVariantToUInt32(propvarIn, pulRet)
      METHOD = pulRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts unsigned Int32 property value of a PROPVARIANT. If no value can be
   ' extracted, then a default value is assigned.
   ' =====================================================================================
   METHOD ToUInt32WithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL ulDefault AS DWORD) AS DWORD
      METHOD = PropVariantToUInt32WithDefault(propvarIn, ulDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts an Int64 property value of a PROPVARIANT.
   ' =====================================================================================
   METHOD ToInt64 (BYREF propvarIn AS PROPVARIANT) AS QUAD
      LOCAL pllRet AS QUAD
      METHOD OBJRESULT = PropVariantToInt64(propvarIn, pllRet)
      METHOD = pllRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts unsigned Int32 property value of a PROPVARIANT. If no value can be
   ' extracted, then a default value is assigned.
   ' =====================================================================================
   METHOD ToInt64WithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL llDefault AS QUAD) AS QUAD
      METHOD = PropVariantToInt64WithDefault(propvarIn, llDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a DOUBLE value from a PROPVARIANT.
   ' =====================================================================================
   METHOD ToDouble (BYREF propvarIn AS PROPVARIANT) AS DOUBLE
      LOCAL pdblRet AS DOUBLE
      METHOD OBJRESULT = PropVariantToDouble(propvarIn, pdblRet)
      METHOD = pdblRet
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a DOUBLE value from a PROPVARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToDoubleWithDefault (BYREF propvarIn AS PROPVARIANT, BYVAL dblDefault AS DOUBLE) AS DOUBLE
      METHOD = PropVariantToDoubleWithDefault(propvarIn, dblDefault)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the contents of a buffer stored in a PROPVARIANT of type VT_ARRRAY | VT_UI1.
   ' =====================================================================================
   METHOD ToBuffer (BYREF propvarIn AS PROPVARIANT, BYVAL pBuffer AS DWORD, BYVAL cb AS DWORD)
      METHOD OBJRESULT = PropVariantToBuffer(propvarIn, BYVAL pBuffer, cb)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts class identifier (CLSID) property value of a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToCLSID (BYREF propvarIn AS PROPVARIANT) AS GUID
      LOCAL pclsid AS GUID
      METHOD OBJRESULT = PropVariantToCLSID(propvarIn, pclsid)
      METHOD = pclsid
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a GUID value from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToGUID (BYREF propvar AS PROPVARIANT) AS GUID
      LOCAL rguid AS GUID
      METHOD OBJRESULT = PropVariantToCLSID(propvar, rguid)
      METHOD = rguid
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the variant value of a PROPVARIANT to a string.
   ' =====================================================================================
   METHOD ToString (BYREF propvarIn AS PROPVARIANT, BYREF pwszBuf AS WSTRINGZ, BYVAL cchBuf AS DWORD)
      METHOD OBJRESULT = PropVariantToString(propvarIn, pwszBuf, cchBuf)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the string property value of a PROPVARIANT. If no value exists, then the
   ' specified default value is returned.
   ' =====================================================================================
   METHOD ToStringWithDefault (BYREF propvarIn AS PROPVARIANT, BYREF pwszDefault AS WSTRINGZ) AS WSTRING
      LOCAL pwsz AS WSTRINGZ PTR
      pwsz = PropVariantToStringWithDefault(propvarIn, pwszDefault)
      IF pwsz THEN
         METHOD = @pwsz
         CoTaskMemFree(BYVAL pwsz)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of strings from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToStringAlloc (BYREF propvarIn AS PROPVARIANT) AS WSTRING
      LOCAL ppwszBuf AS WSTRINGZ PTR
      METHOD OBJRESULT = PropVariantToStringAlloc(propvarIn, ppwszBuf)
      ' // Return the result and free alloctaed memory
      IF ppwszBuf THEN
         METHOD = @ppwszBuf
         CoTaskMemFree(BYVAL ppwszBuf)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts the BSTR property value of a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToBSTR (BYREF propvarIn AS PROPVARIANT) AS WSTRING
      LOCAL pbstrOut AS WSTRING
      METHOD OBJRESULT = PropVariantToBSTR(propvarIn, pbstrOut)
      METHOD = pbstrOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a string from a PROPVARIANT structure and places it into a STRRET structure.
   ' =====================================================================================
   METHOD ToStrRet (BYREF propvarIn AS PROPVARIANT) AS STRRET
      LOCAL pstrret AS STRRET
      METHOD OBJRESULT = PropVariantToStrRet(propvarIn, pstrret)
      METHOD = pstrret
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a FILETIME structure from a PROPVARIANT.
   ' =====================================================================================
   METHOD ToFileTime (BYREF propvarIn AS PROPVARIANT, BYVAL pstfOut AS DWORD) AS FILETIME
      LOCAL pftOut AS FILETIME
      METHOD OBJRESULT = PropVariantToFileTime(propvarIn, pstfOut, pftOut)
      METHOD = pftOut
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into a FILETIME vector.
   ' =====================================================================================
   METHOD ToFileTimeVector (BYREF propvar AS PROPVARIANT, BYREF prgft AS FILETIME, BYVAL crgft AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToFileTimeVector(propvar, prgft, crgft, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a Boolean vector from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToBooleanVector (BYREF propvarIn AS PROPVARIANT, BYREF prgf AS LONG, BYVAL crgf AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToBooleanVector(propvarIn, prgf, crgf, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of Int16 values from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToInt16Vector (BYREF propvarIn AS PROPVARIANT, BYREF prgn AS INTEGER, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToInt16Vector(propvarIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into an unsigned short vector.
   ' =====================================================================================
   METHOD ToUInt16Vector (BYREF propvarIn AS PROPVARIANT, BYREF prgn AS WORD, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToUInt16Vector(propvarIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of Int32 values from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToInt32Vector (BYREF propvarIn AS PROPVARIANT, BYREF prgn AS LONG, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToInt32Vector(propvarIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of UInt32 values from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToUInt32Vector (BYREF propvarIn AS PROPVARIANT, BYREF prgn AS DWORD, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToUInt32Vector(propvarIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of UInt64 values from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToInt64Vector (BYREF propvarIn AS PROPVARIANT, BYREF prgn AS QUAD, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToInt64Vector(propvarIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of DOUBLE values from a PROPVARIANT structure.
   ' =====================================================================================
   METHOD ToDoubleVector (BYREF propvarIn AS PROPVARIANT, BYREF prgn AS DOUBLE, BYVAL crgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToDoubleVector(propvarIn, prgn, crgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a vector of strings from a PROPVARIANT structure.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' DIM prgsz(1) AS WSTRINGZ PTR
   ' cElem = pv.ToStringVector(v, prgsz(0), 2)
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
   METHOD ToStringVector (BYREF propvar AS PROPVARIANT, BYREF prgsz AS DWORD, BYVAL crgsz AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToStringVector(propvar, prgsz, crgsz, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into a newly allocated Boolean vector.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgf AS LONG PTR
   ' cElem = pv.ToBooleanVectorAlloc(v, pprgf)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgf[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgf THEN CoTaskMemFree pprgf
   ' =====================================================================================
   METHOD ToBooleanVectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgf AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToBooleanVectorAlloc(propvar, pprgf, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into a newly allocated Int16 vector.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS INTEGER PTR
   ' cElem = pv.ToInt16VectorAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToInt16VectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToInt16VectorAlloc(propvar, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into a newly allocated UInt16 vector.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS WORD PTR
   ' cElem = pv.ToUInt16VectorAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToUInt16VectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToUInt16VectorAlloc(propvar, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a vector structure into a newly-allocated Int32 array.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS LONG PTR
   ' cElem = pv.ToInt32VectorAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToInt32VectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToInt32VectorAlloc(propvar, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a vector structure into a newly-allocated unsigned Int32 array.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS DWORD PTR
   ' cElem = pv.ToUInt32VectorAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToUInt32VectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToUInt32VectorAlloc(propvar, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a vector structure into a newly-allocated Int64 array.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS QUAD PTR
   ' cElem = pv.ToInt64VectorAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToInt64VectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToInt64VectorAlloc(propvar, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a vector structure into a newly-allocated Int64 array.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Note PB does not currently support unsigned quads.
   ' =====================================================================================
'   METHOD ToUInt64VectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
'      LOCAL pcElem AS DWORD
'      METHOD OBJRESULT = PropVariantToUInt64VectorAlloc(propvar, pprgn, pcElem)
'      METHOD = pcElem
'   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Allocates an array of DOUBLE values then extracts data from a PROPVARIANT into that array.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL pprgn AS DOUBLE PTR
   ' cElem = pv.ToDoubleVectorAlloc(v, pprgn)
   ' LOCAL i AS LONG
   ' // Display the values
   ' FOR i = 0 TO cElem - 1
   '    ? @pprgn[i]
   ' NEXT
   ' // Free the memory allocated for the vector
   ' IF pprgn THEN CoTaskMemFree pprgn
   ' =====================================================================================
   METHOD ToDoubleVectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgn AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToDoubleVectorAlloc(propvar, pprgn, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into a newly allocated strings in a newly allocated vector.
   ' Note Use CoTaskMemFree to release the returned vector.
   ' Usage example:
   ' LOCAL cElem AS DWORD
   ' LOCAL prgsz AS DWORD PTR
   ' LOCAL pwsz AS WSTRINGZ PTR
   ' cElem = pv.ToStringVectorAlloc(v, prgsz)
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
   '    // Free the memory allocated for the vector
   '    CoTaskMemFree prgsz
   ' END IF
   ' =====================================================================================
   METHOD ToStringVectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgsz AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToStringVectorAlloc(propvar, pprgsz, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts data from a PROPVARIANT structure into a newly-allocated FILETIME vector.
   ' =====================================================================================
   METHOD ToFileTimeVectorAlloc (BYREF propvar AS PROPVARIANT, BYREF pprgft AS DWORD) AS DWORD
      LOCAL pcElem AS DWORD
      METHOD OBJRESULT = PropVariantToFileTimeVectorAlloc(propvar, pprgft, pcElem)
      METHOD = pcElem
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the element count of a PROPVARIANT structure.
   ' =====================================================================================
   METHOD GetElementCount (BYREF propvar AS PROPVARIANT) AS DWORD
      METHOD = PropVariantGetElementCount(propvar)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Boolean element from a PROPVARIANT structure of type VT_BOOL,
   ' VT_VECTOR | VT_BOOL, or VT_ARRAY | VT_BOOL.
   ' =====================================================================================
   METHOD GetBooleanElem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS LONG
      LOCAL pfVal AS DWORD
      METHOD OBJRESULT = PropVariantGetBooleanElem(propvar, iElem, pfVal)
      METHOD = pfVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Int16 element from a PROPVARIANT structure of type VT_I2,
   ' VT_VECTOR | VT_I2, or VT_ARRAY | VT_I2.
   ' =====================================================================================
   METHOD GetInt16Elem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS INTEGER
      LOCAL pnVal AS INTEGER
      METHOD OBJRESULT = PropVariantGetInt16Elem(propvar, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single unsigned Int16 element from a PROPVARIANT structure of type VT_U12,
   ' VT_VECTOR | VT_U12, or VT_ARRAY | VT_U12.
   ' =====================================================================================
   METHOD GetUInt16Elem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS WORD
      LOCAL pnVal AS INTEGER
      METHOD OBJRESULT = PropVariantGetUInt16Elem(propvar, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Int32 element from a PROPVARIANT of type VT_I4, VT_VECTOR | VT_I4,
   ' or VT_ARRAY | VT_I4.
   ' =====================================================================================
   METHOD GetInt32Elem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS LONG
      LOCAL pnVal AS LONG
      METHOD OBJRESULT = PropVariantGetInt32Elem(propvar, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single unsigned Int32 element from a PROPVARIANT structure of type VT_UI4,
   ' VT_VECTOR | VT_UI4, or VT_ARRAY | VT_UI4.
   ' =====================================================================================
   METHOD GetUInt32Elem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS DWORD
      LOCAL pnVal AS DWORD
      METHOD OBJRESULT = PropVariantGetUInt32Elem(propvar, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Int64 element from a PROPVARIANT structure of type VT_I8,
   ' VT_VECTOR | VT_I8, or VT_ARRAY | VT_I8.
   ' =====================================================================================
   METHOD GetInt64Elem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS QUAD
      LOCAL pnVal AS QUAD
      METHOD OBJRESULT = PropVariantGetInt64Elem(propvar, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single double element from a PROPVARIANT structure of type VT_R8,
   ' VT_VECTOR | VT_R8, or VT_ARRAY | VT_R8.
   ' =====================================================================================
   METHOD GetDoubleElem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS DOUBLE
      LOCAL pnVal AS DOUBLE
      METHOD OBJRESULT = PropVariantGetDoubleElem(propvar, iElem, pnVal)
      METHOD = pnVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single Unicode string element from a PROPVARIANT structure of type VT_LPWSTR,
   ' VT_BSTR, VT_VECTOR | VT_LPWSTR, VT_VECTOR | VT_BSTR, or VT_ARRAY | VT_BSTR.
   ' =====================================================================================
   METHOD GetStringElem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS WSTRING
      LOCAL ppszVal AS WSTRINGZ PTR
      METHOD OBJRESULT = VariantGetStringElem(propvar, iElem, ppszVal)
      IF ppszVal THEN
         METHOD = @ppszVal
         CoTaskMemFree BYVAL ppszVal
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extracts a single FILETIME element from a PROPVARIANT structure of type VT_FILETIME,
   ' VT_VECTOR | VT_FILETIME, or VT_ARRAY | VT_FILETIME.
   ' =====================================================================================
   METHOD GetFileTimeElem (BYREF propvar AS PROPVARIANT, BYVAL iElem AS DWORD) AS FILETIME
      LOCAL pftVal AS FILETIME
      METHOD OBJRESULT = PropVariantGetFileTimeElem(propvar, iElem, pftVal)
      METHOD = pftVal
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Frees the memory and references used by an array of PROPVARIANT structures stored in an array.
   ' =====================================================================================
   METHOD ClearPropVariantArray (BYREF rgPropVar AS PROPVARIANT, BYVAL cvars AS DWORD)
      ClearPropVariantArray(rgPropVar, cvars)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Compares two PROPVARIANT structures, based on default comparison units and settings.
   ' =====================================================================================
   METHOD Compare (BYREF propvar1 AS PROPVARIANT, BYREF propvar2 AS PROPVARIANT) AS LONG
      METHOD = PropVariantCompareEx(propvar1, propvar2, %PVCU_DEFAULT, %PVCF_DEFAULT)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Extends PropVariantCompare by allowing the caller to compare two PROPVARIANT
   ' structures based on specified comparison units and flags.
   ' =====================================================================================
   METHOD CompareEx (BYREF propvar1 AS PROPVARIANT, BYREF propvar2 AS PROPVARIANT, BYVAL unit AS LONG, BYVAL flags AS DWORD) AS LONG
      METHOD = PropVariantCompareEx(propvar1, propvar2, unit, flags)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a PROPVARIANT has a vector type.
   ' =====================================================================================
   METHOD IsPropVariantVector (BYREF propvar AS PROPVARIANT) AS LONG
      METHOD = propvar.vt AND (%VT_ARRAY OR %VT_VECTOR)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns whether a PROPVARIANT is an array.
   ' =====================================================================================
   METHOD IsPropVariantString (BYREF propvar AS PROPVARIANT) AS LONG
      METHOD = PropVariantToStringWithDefault(propvar, BYVAL %NULL) <> %NULL
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Serializes a specified PROPVARIANT structure, creating a SERIALIZEDPROPERTYVALUE structure.
   ' =====================================================================================
   METHOD StgSerialize (BYREF ppropvar AS PROPVARIANT, BYREF ppProp AS DWORD, BYREF pcb AS DWORD)
      METHOD OBJRESULT = StgSerializePropVariant(ppropvar, BYVAL ppProp, pcb)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Deserializes a specified SERIALIZEDPROPERTYVALUE structure, creating a PROPVARIANT structure.
   ' =====================================================================================
   METHOD StgDeserialize (BYVAL pprop AS DWORD, BYVAL cbMax AS DWORD) AS PROPVARIANT
      LOCAL ppropvar AS PROPVARIANT
      METHOD OBJRESULT = StgDeserializePropVariant(pprop, cbMax, ppropvar)
      METHOD = ppropvar
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a VT_ERROR propvariant suitable for optional parameters.
   ' =====================================================================================
   METHOD OptPrm () AS PROPVARIANT
      LOCAL pv AS PROPVARIANT
      pv.vt = %VT_ERROR
      pv.scode = %DISP_E_PARAMNOTFOUND
      METHOD = pv
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ========================================================================================
' Creates an instance of the class.
' ========================================================================================
FUNCTION NewPropVariant () AS IPropVariant
   LOCAL pVar AS IPropVariant
   pVar = CLASS "CPropVariant"
   FUNCTION = pVar
END FUNCTION
' ========================================================================================
