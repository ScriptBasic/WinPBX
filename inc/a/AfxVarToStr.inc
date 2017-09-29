' ########################################################################################
' Microsoft Windows
' File: AfxVarToStr.bas
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXVARTOSTR_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "propvarutil.inc"

' =====================================================================================
' Extracts the variant value of a VARIANT to a newly-allocated string.
' Note: VariantToStringAlloc does not work with float (SINGLE / VT_R4) values, so I'm
' using a workaround.
' =====================================================================================
FUNCTION AfxVarToStr (BYREF varIn AS VARIANT) AS WSTRING

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

   IF VARPTR(varIn) = 0 THEN EXIT FUNCTION
   pv = VARPTR(varIn)
   IF VARIANTVT(varIn) = %VT_R4 THEN
      IF @pv.fltVal THEN FUNCTION = FORMAT$(@pv.fltVal)
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
                  FUNCTION = pSb.String
                  pSb = NOTHING
               END IF
            END IF
         ' // Convert the contents to a string
         END IF
      END IF
      EXIT FUNCTION
   ELSEIF VARIANTVT(varIn) = (%VT_ARRAY OR %VT_I1) OR VARIANTVT(varIn) = (%VT_ARRAY OR %VT_UI1) THEN   ' Array of bytes
      ' ----------------------------------------------------------------
      ' Alternate way. Easier to implement but slower and wastes memory.
      ' ----------------------------------------------------------------
      ' LOCAL nBytes AS LONG
      ' DIM   vByteArray(0) AS BYTE
      ' // Convert the variant to an array of bytes
      ' vByteArray() = varIn
      ' // Convert the array of bytes to a string
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
                  FUNCTION = PEEK$(pData, nBytes)
                  ' // Unlock the array
                  SafeArrayUnaccessData(@pv.parray)
               END IF
            END IF
         END IF
      END IF
   ELSE
      ' // Use VariantToStringAlloc to do the conversion
      VariantToStringAlloc(varIn, ppszBuf)
      ' // Return the result and free allocated memory
      IF ppszBuf THEN
         FUNCTION = @ppszBuf
         CoTaskMemFree(BYVAL ppszBuf)
      END IF
   END IF

END FUNCTION
' =====================================================================================
