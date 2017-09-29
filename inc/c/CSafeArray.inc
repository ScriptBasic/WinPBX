' ########################################################################################
' Microsoft Windows
' File: CSafeArray.inc
' Contents: Safe array wrapper class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CSAFEARRAY_INC = 1

#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the
' VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array.
' All other types are legal.
' SafeArrayPutElement, called by the put data methods, automatically calls SafeArrayLock
' and SafeArrayUnlock before and after assigning the element. If the data element is a
' string, object, or variant, the function copies it correctly when the safe array is
' destroyed. If the existing element is a string, object, or variant, it is cleared
' correctly. If the data element is a VT_DISPATCH or VT_UNKNOWN, AddRef is called to
' increment the object's reference count.
' ========================================================================================

' ########################################################################################
' CSafeArray Class
' ########################################################################################
CLASS CSafeArray

   INSTANCE m_psa AS SAFEARRAY PTR
   INSTANCE m_ArrayInfo AS WSTRING

   ' =====================================================================================
   ' Destroys the SafeArray when the class is destroyed
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_psa THEN
         SafeArrayUnlock(m_psa)
         SafeArrayDestroy(m_psa)
      END IF
   END METHOD
   ' =====================================================================================

   INTERFACE ISafeArray : INHERIT IAutomation

   ' =====================================================================================
   ' Creates a safe array from the given VARTYPE, number of dimensions and bounds.
   ' Parameters:
   ' vt
   '   [in] Base type of the array (the VARTYPE of each element of the array).
   '   The VARTYPE is restricted to a subset of the variant types.
   '   Neither VT_ARRAY nor the VT_BYREF flag can be set.
   '   VT_EMPTY and VT_NULL are not valid base types for the array.
   '   All other types are legal.
   ' cDims
   '   [in] Number of dimensions in the array.
   '   The number cannot be changed after the array is created.
   ' rgsabound
   '   [in] Pointer to a vector of bounds (one for each dimension) to allocate for the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_Create (BYVAL vt AS WORD, BYVAL cDims AS DWORD, BYREF rgsabound AS SAFEARRAYBOUND) THREADSAFE
      IF m_psa <> %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF VARPTR(rgsabound) = %NULL THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      IF cDims < 1 THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      m_psa = SafeArrayCreate(vt, cDims, rgsabound)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_OUTOFMEMORY
      METHOD OBJRESULT = SafeArrayLock(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a safe array from the given VARTYPE, number of dimensions and bounds.
   ' Parameters:
   ' vt
   '   [in] The base type or the VARTYPE of each element of the array. The FADF_RECORD
   '   flag can be set for a variant type VT_RECORD, The FADF_HAVEIID flag can be set
   '   for VT_DISPATCH or VT_UNKNOWN, and FADF_HAVEVARTYPE can be set for all other VARTYPEs.
   ' cDims
   '   [in] Number of dimensions in the array.
   '   The number cannot be changed after the array is created.
   ' rgsabound
   '   [in] Pointer to a vector of bounds (one for each dimension) to allocate for the array.
   ' pvExtra
   '   Points to the type information of the user-defined type, if you are creating a
   '   safe array of user-defined types. If the vt parameter is VT_RECORD, then
   '   pvExtra will be a pointer to an IRecordInfo describing the record. If the vt
   '   parameter is VT_DISPATCH or VT_UNKNOWN, then pvExtra will contain a pointer to
   '   a GUID representing the type of interface being passed to the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' Comments:
   '   If the VARTYPE is VT_RECORD then SafeArraySetRecordInfo is called. If the
   '   VARTYPE is VT_DISPATCH or VT_UNKNOWN then the elements of the array must contain
   '   interfaces of the same type. Part of the process of marshaling this array to
   '   other processes does include generating the proxy/stub code of the IID pointed
   '   to by pvExtra parameter. To actually pass heterogeneous interfaces one will need
   '   to specify either IID_IUnknown or IID_IDispatch in pvExtra and provide some
   '   other means for the caller to identify how to query for the actual interface.
   ' =====================================================================================
   METHOD SA_CreateEx (BYVAL vt AS WORD, BYVAL cDims AS DWORD, BYREF rgsabound AS SAFEARRAYBOUND, BYVAL pvExtra AS DWORD) THREADSAFE
      IF m_psa <> %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF VARPTR(rgsabound) = %NULL THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      IF cDims < 1 THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      m_psa = SafeArrayCreateEx(vt, cDims, rgsabound, pvExtra)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_OUTOFMEMORY : EXIT METHOD
      METHOD OBJRESULT = SafeArrayLock(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a one-dimensional SafeArray
   ' Parameters:
   ' vt
   '   [in] Base type of the array (the VARTYPE of each element of the array).
   '   The VARTYPE is restricted to a subset of the variant types.
   '   Neither VT_ARRAY nor the VT_BYREF flag can be set.
   '   VT_EMPTY and VT_NULL are not valid base types for the array.
   '   All other types are legal.
   ' lLBound
   '   The lower bound value; that is, the index of the first element in the array.
   '   Can be negative.
   ' cElements
   '   The number of elements in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_Create (BYVAL vt AS WORD, BYVAL lLBound AS LONG, BYVAL cElements AS DWORD) THREADSAFE
      LOCAL rgsabound AS SAFEARRAYBOUND
      rgsabound.cElements = cElements
      rgsabound.lLBound = lLBound
      ME.SA_Create(vt, 1, rgsabound)
      METHOD OBJRESULT = OBJRESULT
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a one-dimensional array. A safe array created with SafeArrayCreateVector
   ' is a fixed size, so the constant FADF_FIXEDSIZE is always set.
   ' Parameters:
   ' vt
   '   [in] Base type of the array (the VARTYPE of each element of the array).
   '   The VARTYPE is restricted to a subset of the variant types.
   '   Neither VT_ARRAY nor the VT_BYREF flag can be set.
   '   VT_EMPTY and VT_NULL are not valid base types for the array.
   '   All other types are legal.
   ' cElements
   '   The number of elements in the array.
   ' lLBound
   '   The lower bound value; that is, the index of the first element in the array.
   '   Can be negative.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' Comments:
   '  SafeArrayCreateVector allocates a single block of memory containing a SAFEARRAY
   '  structure for a single-dimension array (24 bytes), immediately followed by the
   '  array data. All of the existing safe array functions work correctly for safe
   '  arrays that are allocated with SafeArrayCreateVector.
   '  A SafeArrayCreateVector is allocated as a single block of memory. Both the
   '  SafeArray descriptor and the array data block are allocated contiguously in one
   '  allocation, which speeds up array allocation.
   ' =====================================================================================
   METHOD SA_CreateVector (BYVAL vt AS WORD, BYVAL lLBound AS LONG, BYVAL cElements AS DWORD) THREADSAFE
      IF m_psa <> %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      m_psa = SafeArrayCreateVector(vt, lLBound, cElements)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_OUTOFMEMORY : EXIT METHOD
      METHOD OBJRESULT = SafeArrayLock(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a one-dimensional array of the specified type and bounds.
   ' Parameters:
   ' vt
   '   The base type of the array (the VARTYPE of each element of the array). The
   '   FADF_RECORD flag can be set for VT_RECORD. The FADF_HAVEIID can be set for
   '   VT_DISPATCH or VT_UNKNOWN and FADF_HAVEVARTYPE can be set for all other types.
   ' cElements
   '   The number of elements in the array.
   ' lLBound
   '   The lower bound value; that is, the index of the first element in the array.
   '   Can be negative.
   ' pvExtra
   '   Points to the type information of the user-defined type, if you are creating a
   '   safe array of user-defined types. If the vt parameter is VT_RECORD, then
   '   pvExtra will be a pointer to an IRecordInfo describing the record. If the vt
   '   parameter is VT_DISPATCH or VT_UNKNOWN, then pvExtra will contain a pointer to
   '   a GUID representing the type of interface being passed to the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_CreateVectorEx (BYVAL vt AS WORD, BYVAL lLBound AS LONG, BYVAL cElements AS DWORD, BYVAL pvExtra AS DWORD) THREADSAFE
      IF m_psa <> %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      m_psa = SafeArrayCreateVectorEx(vt, lLBound, cElements, pvExtra)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_OUTOFMEMORY : EXIT METHOD
      METHOD OBJRESULT = SafeArrayLock(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroys an existing array descriptor and all of the data in the array. If objects
   ' are stored in the array, Release is called on each object in the array.
   ' Safe arrays of variant will have VariantClear called on each member and safe arrays
   ' of BSTR will have SysFreeString called on each element. IRecordInfo::RecordClear
   ' will be called to release object references and other values of a record without
   ' deallocating the record.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_Destroy () THREADSAFE
      LOCAL hr AS LONG
      IF m_psa = %NULL THEN EXIT METHOD
      hr = SafeArrayUnlock(m_psa)
      IF SUCCEEDED(hr) THEN
         hr = SafeArrayDestroy(m_psa)
         IF SUCCEEDED(hr) THEN m_psa = %NULL
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroys all the data in a safe array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' Comments:
   '   This method is typically used when freeing safe arrays that contain elements with
   '   data types other than variants. If objects are stored in the array, Release is
   '   called on each object in the array. Safe arrays of variant will have VariantClear
   '   called on each member and safe arrays of BSTR will have SysFreeString called on
   '   each element. IRecordInfo::RecordClear will be called to release object references
   '   and other values of a record without deallocating the record.
   ' =====================================================================================
   METHOD SA_DestroyData ()  THREADSAFE
      LOCAL hr AS LONG
      IF m_psa = %NULL THEN EXIT METHOD
      hr = SafeArrayUnlock(m_psa)
      IF SUCCEEDED(hr) THEN
         hr = SafeArrayDestroyData(m_psa)
         SafeArrayLock(m_psa)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Attaches a SAFEARRAY structure to a CSafeArray object.
   ' Parameters:
   ' psaSrc
   '   A pointer to the SAFEARRAY structure.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_Attach (BYVAL psaSrc AS SAFEARRAY PTR) THREADSAFE
      LOCAL hr AS LONG
      IF psaSrc = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      ME.SA_Destroy
      hr = OBJRESULT
      IF SUCCEEDED(hr) THEN
         m_psa = psaSrc
         hr = SafeArrayLock(m_psa)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method detaches the SAFEARRAY from the CSafeArray object.
   ' Return Value
   '   Returns a pointer to a SAFEARRAY object.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_Detach () THREADSAFE AS DWORD   ' SAFEARRAY PTR
      LOCAL hr AS LONG
      IF m_psa <> %NULL THEN
         hr = SafeArrayUnlock(m_psa)
         IF SUCCEEDED(hr) THEN
            METHOD = m_psa
            m_psa = %NULL
         END IF
         METHOD OBJRESULT = hr
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of dimensions in the array.
   ' =====================================================================================
   METHOD SA_GetDim () THREADSAFE AS DWORD
      IF m_psa <> %NULL THEN METHOD = SafeArrayGetDim(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the lower bound for any dimension of a safe array.
   ' Parameter:
   ' nDim
   '   The array dimension for which to get the lower bound.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetLBound (BYVAL nDim AS DWORD) THREADSAFE AS LONG
      LOCAL hr AS LONG, plLBound AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetLBound(m_psa, nDim, plLBound)
      IF hr = %S_OK THEN METHOD = plLBound
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SA_1D_GetLBound () THREADSAFE AS LONG
      LOCAL hr AS LONG, plLBound AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetLBound(m_psa, 1, plLBound)
      IF hr = %S_OK THEN METHOD = plLBound
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the upper bound for any dimension of a safe array.
   ' Parameter:
   ' nDim
   '   The array dimension for which to get the upper bound.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetUBound (BYVAL nDim AS DWORD) THREADSAFE AS LONG
      LOCAL hr AS LONG, plUBound AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetUBound(m_psa, nDim, plUBound)
      IF hr = %S_OK THEN METHOD = plUBound
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SA_1D_GetUBound () THREADSAFE AS LONG
      LOCAL hr AS LONG, plUBound AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetUBound(m_psa, 1, plUBound)
      IF hr = %S_OK THEN METHOD = plUBound
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of elements in the specified dimension of the array.
   ' Parameter:
   ' nDim
   '   The array dimension for which to get the number of elements.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetCount (BYVAL nDim AS DWORD) THREADSAFE AS DWORD
      LOCAL hr AS LONG, plLBound AS LONG, plUBound AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF nDim > SafeArrayGetDim(m_psa) THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      hr = SafeArrayGetLBound(m_psa, nDim, plLBound)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      hr = SafeArrayGetUBound(m_psa, nDim, plUBound)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      METHOD = plUbound - plLBound + 1
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SA_1D_GetCount () THREADSAFE AS DWORD
      LOCAL hr AS LONG, plLBound AS LONG, plUBound AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetLBound(m_psa, 1, plLBound)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      hr = SafeArrayGetUBound(m_psa, 1, plUBound)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      METHOD = plUbound - plLBound + 1
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the size (in bytes) of an element of the array.
   ' Does not include size of pointed-to data.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetElemsize () THREADSAFE AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD = SafeArrayGetElemsize(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Tests if the safe array can be resized.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_IsResizable () THREADSAFE AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD = (@m_psa.fFeatures AND %FADF_FIXEDSIZE) <> %FADF_FIXEDSIZE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Changes the right-most (least significant) bound of a safe array.
   ' Parameter:
   ' psaboundNew
   '   Pointer to a new safe array bound structure that contains the new array boundary.
   '   You can change only the least significant dimension of an array.
   ' Comments:
   '   If you reduce the bound of an array, SafeArrayRedim deallocates the array
   '   elements outside the new array boundary. If the bound of an array is increased,
   '   SafeArrayRedim allocates and initializes the new array elements. The data is
   '   preserved for elements that exist in both the old and new array.
   ' OBJRESULT:
   '   S_OK Success.
   '   %DISP_E_ARRAYISLOCKED The array is currently locked.
   '   E_INVALIDARG psaboundNew is a null pointer.
   '   E_FAIL The item pointed to by m_psa is not a safe array descriptor.
   '          It is a fixed-size array.
   ' =====================================================================================
   METHOD SA_Redim (BYREF psaboundNew AS SAFEARRAYBOUND) THREADSAFE
      LOCAL hr AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF VARPTR(psaboundNew) = %NULL THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayUnlock(m_psa)
      IF SUCCEEDED(hr) THEN
         hr = SafeArrayRedim(m_psa, psaboundNew)
         SafeArrayLock(m_psa)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Changes the right-most (least significant) bound of a safe array.
   ' Parameter:
   ' cElements
   '   Number of elements of the array.
   ' OBJRESULT:
   '   S_OK Success.
   '   %DISP_E_ARRAYISLOCKED The array is currently locked.
   '   E_FAIL The item pointed to by m_psa is not a safe array descriptor.
   '          It is a fixed-size array.
   '          It is not a one-dimensional array.
   ' =====================================================================================
   METHOD SA_1D_Redim (BYVAL cElements AS DWORD) THREADSAFE
      LOCAL hr AS LONG, psaboundNew AS SAFEARRAYBOUND
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      psaboundNew.cElements = cElements
      psaboundNew.lLBound = @m_psa.rgsabound(0).lLBound
      hr = SafeArrayUnlock(m_psa)
      IF SUCCEEDED(hr) THEN
         hr = SafeArrayRedim(m_psa, psaboundNew)
         SafeArrayLock(m_psa)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the VARTYPE stored in the given safe array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetVartype () THREADSAFE AS WORD
      LOCAL pvt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayGetVartype(m_psa, pvt)
      METHOD = pvt
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of Number of times the array has been locked without
   ' the corresponding unlock.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetLocksCount () THREADSAFE AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD = @m_psa.cLocks
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the flags used by the safe array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetFlags () THREADSAFE AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD = @m_psa.fFeatures
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the address of the SafeArray.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_GetPtr () THREADSAFE AS DWORD
      METHOD = m_psa
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a copy of the safe array.
   ' Return Value:
   '   Pointer of the new array descriptor. You must free this pointer calling the API
   '   function SafeArrayDestroy.
   ' OBJRESULT:
   '   S_OK Success.
   '   E_INVALIDARG The argument ppsaOut was not a valid safe array descriptor.
   '   E_OUTOFMEMORY Insufficient memory to create the copy.
   ' Comments:
   '   SafeArrayCopy calls the string or variant manipulation functions if the array to
   '   copy contains either of these data types. If the array being copied contains
   '   object references, the reference counts for the objects are incremented.
   ' =====================================================================================
   METHOD SA_Copy () THREADSAFE AS DWORD
      LOCAL hr AS LONG, ppsaOut AS SAFEARRAY PTR
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayCopy(m_psa, ppsaOut)
      IF hr = %S_OK THEN METHOD = ppsaOut
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the source array to the target array after releasing any resources in the
   ' target array. This is similar to SafeArrayCopy, except that the target array has
   ' to be set up by the caller. The target is not allocated or reallocated.
   ' Parameter:
   ' psaTarget
   '   The target safe array. On exit, the array referred to by psaTarget contains a
   '   copy of the data in m_psa.
   ' OBJRESULT:
   '   S_OK Success.
   '   E_INVALIDARG The dimensions or the number of dimensions don't match.
   '   E_OUTOFMEMORY Insufficient memory to create the copy.
   ' =====================================================================================
   METHOD SA_CopyData (BYVAL psaTarget AS SAFEARRAY PTR) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayCopyData(m_psa, psaTarget)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a safe array.
   ' Parameter:
   ' psaSrc
   '   Pointer to an array descriptor created by SafeArrayCreate.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' Comments:
   '   SafeArrayCopy calls the string or variant manipulation functions if the array to
   '   copy contains either of these data types. If the array being copied contains
   '   object references, the reference counts for the objects are incremented.
   ' =====================================================================================
   METHOD SA_CopyFrom (BYVAL psaSrc AS SAFEARRAY PTR) THREADSAFE
      LOCAL hr AS LONG
      IF psaSrc = %NULL THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      IF m_psa THEN ME.SA_Destroy
      hr = SafeArrayCopy(psaSrc, m_psa)
      IF SUCCEEDED(hr) AND m_psa <> %NULL THEN SafeArrayLock(m_psa)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Transfers ownership of the safe array to a variant and detaches it from the object.
   ' =====================================================================================
   METHOD SA_MoveToVariant () THREADSAFE AS VARIANT
      LOCAL hr AS LONG
      LOCAL vt AS WORD
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      ' // Get the safe array type
      hr = SafeArrayGetVartype(m_psa, vt)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      ' // Unlock the safe array
      SafeArrayUnlock(m_psa)
      ' // Transfers ownership of the safe array to the variant
      pv = VARPTR(v)
      @pv.vt = %VT_ARRAY OR vt
      @pv.parray = m_psa
      METHOD = v
      ' // Detaches the safe array
      m_psa = %NULL
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Transfers ownership of the safe array contained in the variant parameter to this
   ' object. The variant is then changed to %VT_EMPTY.
   ' =====================================================================================
   METHOD SA_MoveFromVariant (BYREF v AS VARIANT) THREADSAFE
      LOCAL pv AS tagVARIANT PTR
      IF VARPTR(v) = 0 THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      pv = VARPTR(v)
      IF (@pv.vt AND %VT_ARRAY) <> %VT_ARRAY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      ' // Copies the safe array contained in the variant
      ME.SA_CopyFrom(@pv.parray)
      ' // Empties the variant
      v = EMPTY
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a variant containing a copy of the safe array.
   ' =====================================================================================
   METHOD SA_CopyToVariant () THREADSAFE AS VARIANT
      LOCAL hr AS LONG
      LOCAL vt AS WORD
      LOCAL v AS VARIANT
      LOCAL pv AS tagVARIANT PTR
      LOCAL psaNew AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      ' // Get the safe array type
      hr = SafeArrayGetVartype(m_psa, vt)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      ' // Make a copy of the safe array and transfer ownership of it to the variant
      hr = SafeArrayCopy(m_psa, psaNew)
      IF hr <> %S_OK THEN METHOD OBJRESULT = hr : EXIT METHOD
      pv = VARPTR(v)
      @pv.vt = %VT_ARRAY OR vt
      @pv.parray = psaNew
      METHOD = v
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the contents of a VARIANT of type VT_ARRAY, i.e. containing a safe array, to
   ' the object. The VARIANT remains unaltered.
   ' =====================================================================================
   METHOD SA_CopyFromVariant (BYREF v AS VARIANT) THREADSAFE
      LOCAL pv AS tagVARIANT PTR
      IF VARPTR(v) = 0 THEN METHOD OBJRESULT = %E_INVALIDARG : EXIT METHOD
      pv = VARPTR(v)
      IF (@pv.vt AND %VT_ARRAY) <> %VT_ARRAY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      ' // Copies the safe array contained in the variant
      ME.SA_CopyFrom(@pv.parray)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to an array element.
   ' Parameters:
   ' rgIndices
   '   An array of index values that identify an element of the array. All indexes for
   '   the element must be specified.
   ' Return Value:
   '   Pointer to the array element.
   ' OBJRESULT:
   '   The return value obtained from the returned HRESULT is one of the following.
   '   S_OK Success.
   '   DISP_E_BADINDEX The specified index was invalid.
   ' =====================================================================================
   METHOD SA_PtrOfIndex (BYREF rgIndices AS LONG) THREADSAFE AS DWORD
      LOCAL hr AS LONG, ppvData AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayPtrOfIndex(m_psa, rgIndices, ppvData)
      IF hr = %S_OK THEN METHOD = ppvData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to an array element.
   ' Parameters:
   ' idx
   '   Index value that identifies an element of the array.
   ' ppvData
   '   On return, pointer to the element identified by the values in idx.
   ' Return Value:
   '   Pointer to the array element.
   ' OBJRESULT:
   '   The return value obtained from the returned HRESULT is one of the following.
   '   S_OK Success.
   '   DISP_E_BADINDEX The specified index was invalid.
   ' =====================================================================================
   METHOD SA_1D_PtrOfIndex (BYVAL idx AS LONG) THREADSAFE AS DWORD
      LOCAL hr AS LONG, ppvData AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayPtrOfIndex(m_psa, idx, ppvData)
      IF hr = %S_OK THEN METHOD = ppvData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Increments the lock count of an array, and retrieves a pointer to the array data.
   ' Return Value:
   '   The lock count of the array.
   ' OBJRESULT:
   '   E_FAIL If m_psa is null.
   '   E_UNEXPECTED The array could not be unlocked.
   ' =====================================================================================
   METHOD SA_AccessData () THREADSAFE AS DWORD
      LOCAL hr AS LONG, ppvData AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayAccessData(m_psa, ppvData)
      IF hr = %S_OK THEN METHOD = ppvData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Decrements the lock count of an array, and invalidates the pointer retrieved by
   ' SafeArrayAccessData.
   ' OBJRESULT:
   '   E_FAIL If m_psa is null.
   '   E_UNEXPECTED The array could not be unlocked.
   ' =====================================================================================
   METHOD SA_UnaccessData () THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayUnaccessData(m_psa)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the GUID of the interface contained within a given safe array.
   ' Return Value:
   '   The GUID of the interface, on success, or a null guid on failure.
   ' OBJRESULT:
   '   S_OK Success.
   '   E_FAIL If m_psa is null.
   '   E_INVALIDARG If the array descriptor does not have the FADF_HAVEIID flag set.
   ' =====================================================================================
   METHOD SA_GetIID () THREADSAFE AS GUID
      LOCAL hr AS LONG, pguid AS GUID
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_HAVEIID) <> %FADF_HAVEIID THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetIID(m_psa, pguid)
      IF hr = %S_OK THEN METHOD = pguid
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the GUID of the interface contained within a given safe array.
   ' OBJRESULT:
   '   S_OK Success.
   '   E_FAIL If m_psa is null.
   '   E_INVALIDARG If the array descriptor does not have the FADF_HAVEIID flag set.
   ' =====================================================================================
   METHOD SA_SetIID (BYREF pguid AS GUID) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_HAVEIID) <> %FADF_HAVEIID THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      METHOD OBJRESULT = SafeArraySetIID(m_psa, pguid)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the IRecordInfo Interface of the UDT contained in a given safe array.
   ' OBJRESULT:
   '   S_OK Success.
   '   E_FAIL If m_psa is null.
   '   E_INVALIDARG If the array descriptor does not have the FADF_RECORD flag set.
   ' =====================================================================================
   METHOD SA_GetRecordInfo () THREADSAFE AS IRecordInfo
      LOCAL hr AS LONG, prinfo AS IRecordInfo
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_RECORD) <> %FADF_RECORD THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetRecordInfo(m_psa, prinfo)
      IF hr = %S_OK THEN METHOD = prinfo
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the IRecordInfo Interface of the UDT contained in a given safe array.
   ' OBJRESULT:
   '   S_OK Success.
   '   E_FAIL If m_psa is null.
   '   E_INVALIDARG If the array descriptor does not have the FADF_RECORD flag set.
   ' =====================================================================================
   METHOD SA_SetRecordInfo (BYVAL prinfo AS IRecordInfo) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_RECORD) <> %FADF_RECORD THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      METHOD OBJRESULT = SafeArraySetRecordInfo(m_psa, prinfo)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a single element of the array.
   ' Parameters:
   ' rgIndices
   '   Pointer to a vector of indexes for each dimension of the array. The right-most
   '   (least significant) dimension is rgIndices[0]. The left-most dimension is stored
   '   at rgIndices[psa->cDims – 1].
   ' pData
   '   Pointer to the location to place the element of the array.
   ' Comments:
   '   This function calls SafeArrayLock and SafeArrayUnlock automatically, before and
   '   after retrieving the element. The caller must provide a storage area of the
   '   correct size to receive the data. If the data element is a string, object, or
   '   variant, the function copies the element in the correct way.
   ' OBJRESULT:
   '   The return value obtained from the returned HRESULT is one of the following.
   '   S_OK Success.
   '   DISP_E_BADINDEX The specified index is invalid.
   '   E_INVALIDARG One of the arguments is invalid.
   '   E_OUTOFMEMORY Memory could not be allocated for the element.
   ' =====================================================================================
   METHOD SA_GetElement (BYREF rgIndices AS LONG, BYVAL pData AS DWORD) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayGetElement(m_psa, rgIndices, BYVAL pData)
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SA_1D_GetElement (BYVAL idx AS LONG, BYVAL pData AS DWORD) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayGetElement(m_psa, idx, BYVAL pData)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the data element at a given location in the array.
   ' Parameters
   ' rgIndices
   '   Pointer to a vector of indexes for each dimension of the array. The right-most
   '   (least significant) dimension is rgIndices[0]. The left-most dimension is stored
   '   at rgIndices[psa->cDims – 1].
   ' pData
   '   Pointer to the data to assign to the array. The variant types VT_DISPATCH,
   '   VT_UNKNOWN, and VT_BSTR are pointers, and do not require another level of indirection.
   ' Comments:
   '   This function automatically calls SafeArrayLock and SafeArrayUnlock before and
   '   after assigning the element. If the data element is a string, object, or variant,
   '   the function copies it correctly when the safe array is destroyed. If the
   '   existing element is a string, object, or variant, it is cleared correctly. If
   '   the data element is a VT_DISPATCH or VT_UNKNOWN, AddRef is called to increment
   '   the object's reference count.
   ' Note
   '   Multiple locks can be on an array. Elements can be put into an array while the
   '   array is locked by other operations.
   ' OBJRESULT:
   '   The return value obtained from the returned HRESULT is one of the following.
   '   S_OK Success.
   '   DISP_E_BADINDEX The specified index was invalid.
   '   E_INVALIDARG One of the arguments is invalid.
   '   E_OUTOFMEMORY Memory could not be allocated for the element.
   ' =====================================================================================
   METHOD SA_PutElement (BYREF rgIndices AS LONG, BYVAL pData AS DWORD) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayPutElement(m_psa, rgIndices, BYVAL pData)
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SA_1D_PutElement (BYVAL idx AS LONG, BYVAL pData AS DWORD) THREADSAFE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      METHOD OBJRESULT = SafeArrayPutElement(m_psa, idx, BYVAL pData)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a VARIANT element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetVariant (BYVAL idx AS LONG) THREADSAFE AS VARIANT
      LOCAL hr AS LONG, vt AS WORD, vData AS VARIANT
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_VARIANT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, vData)
      IF SUCCEEDED(hr) THEN METHOD = vData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the VARIANT element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutVariant (BYVAL idx AS LONG, BYVAL vData AS VARIANT) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_VARIANT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, vData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a VARIANT to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendVariant (BYVAL vData AS VARIANT) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_VARIANT, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_VARIANT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, vData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a WSTRING element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetWString (BYVAL idx AS LONG) THREADSAFE AS WSTRING
      LOCAL hr AS LONG, vt AS WORD, bstrData AS WSTRING
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_BSTR THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, bstrData)
      METHOD = bstrData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the WSTRING element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutWString (BYVAL idx AS LONG, BYVAL bstrData AS WSTRING) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_BSTR THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, BYVAL STRPTR(bstrData))
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a WSTRING to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendWString (BYVAL bstrData AS WSTRING) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_BSTR, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_BSTR THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, BYVAL STRPTR(bstrData))
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a BYTE element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetByte (BYVAL idx AS LONG) THREADSAFE AS BYTE
      LOCAL hr AS LONG, vt AS WORD, bData AS BYTE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I1 AND vt <> %VT_UI1 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, bData)
      METHOD = bData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the BYTE element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutByte (BYVAL idx AS LONG, BYVAL bData AS BYTE) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I1 AND vt <> %VT_UI1 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, bData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a BYTE to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendByte (BYVAL bData AS BYTE) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_UI1, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I1 AND vt <> %VT_UI1 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, bData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a WORD element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetWord (BYVAL idx AS LONG) THREADSAFE AS WORD
      LOCAL hr AS LONG, vt AS WORD, wData AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UI2 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, wData)
      METHOD = wData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the WORD element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutWord (BYVAL idx AS LONG, BYVAL wData AS WORD) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UI2 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, wData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a WORD to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendWord (BYVAL wData AS WORD) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_UI2, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UI2 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, wData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves an INTEGER element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetInteger (BYVAL idx AS LONG) THREADSAFE AS INTEGER
      LOCAL hr AS LONG, vt AS WORD, iData AS INTEGER
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I2 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, iData)
      METHOD = iData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the INTEGER element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutInteger (BYVAL idx AS LONG, BYVAL iData AS INTEGER) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I2 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, iData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends an INTEGER to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendInteger (BYVAL iData AS INTEGER) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_I2, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I2 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, iData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a LONG element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetLong (BYVAL idx AS LONG) THREADSAFE AS LONG
      LOCAL hr AS LONG, vt AS WORD, lData AS LONG
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I4 AND vt <> %VT_INT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, lData)
      METHOD = lData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the LONG element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutLong (BYVAL idx AS LONG, BYVAL lData AS LONG) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I4 AND vt <> %VT_INT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, lData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a LONG to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendLong (BYVAL lData AS LONG) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_I4, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_I4 AND vt <> %VT_INT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, lData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a DWORD element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetDword (BYVAL idx AS LONG) THREADSAFE AS DWORD
      LOCAL hr AS LONG, vt AS WORD, dwData AS DWORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UI4 AND vt <> %VT_UINT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, dwData)
      METHOD = dwData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the DWORD element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutDword (BYVAL idx AS LONG, BYVAL dwData AS DWORD) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UI4 AND vt <> %VT_UINT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, dwData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a DWORD to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendDword (BYVAL dwData AS DWORD) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_UI4, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UI4 AND vt <> %VT_UINT THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, dwData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a SINGLE element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetSingle (BYVAL idx AS LONG) THREADSAFE AS SINGLE
      LOCAL hr AS LONG, vt AS WORD, flData AS SINGLE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_R4 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, flData)
      METHOD = flData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the SINGLE element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutSingle (BYVAL idx AS LONG, BYVAL flData AS SINGLE) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_R4 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, flData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a SINGLE to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendSingle (BYVAL flData AS SINGLE) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_R4, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_R4 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, flData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a DOUBLE element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetDouble (BYVAL idx AS LONG) THREADSAFE AS DOUBLE
      LOCAL hr AS LONG, vt AS WORD, dblData AS DOUBLE
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_R8 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, dblData)
      METHOD = dblData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the DOUBLE element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutDouble (BYVAL idx AS LONG, BYVAL dblData AS DOUBLE) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_R8 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, dblData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a DOUBLE to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendDouble (BYVAL dblData AS DOUBLE) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_R8, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_R8 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, dblData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a CURRENCY element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetCurrency (BYVAL idx AS LONG) THREADSAFE AS CURRENCY
      LOCAL hr AS LONG, vt AS WORD, cyData AS CURRENCY
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_CY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, cyData)
      METHOD = cyData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the CURRENCY element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutCurrency (BYVAL idx AS LONG, BYVAL cyData AS CURRENCY) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_CY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, cyData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a CURRENCY to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendCurrency (BYVAL cyData AS CURRENCY) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_CY, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_CY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, cyData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a QUAD element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetQuad (BYVAL idx AS LONG) THREADSAFE AS QUAD
      LOCAL hr AS LONG, vt AS WORD, qData AS QUAD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_CY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, qData)
      METHOD = qData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the QUAD element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutQuad (BYVAL idx AS LONG, BYVAL qData AS QUAD) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_CY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, qData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a QUAD to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendQuad (BYVAL qData AS QUAD) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_I8, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_CY THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, qData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a DECIMAL element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetDecimal (BYVAL idx AS LONG) THREADSAFE AS DECIMAL
      LOCAL hr AS LONG, vt AS WORD, decData AS DECIMAL
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_DECIMAL THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, decData)
      METHOD = decData
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the DECIMAL element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutDecimal (BYVAL idx AS LONG, BYVAL decData AS DECIMAL) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_DECIMAL THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, decData)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends a DECIMAL to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendDecimal (BYVAL decData AS DECIMAL) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_DECIMAL, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_DECIMAL THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, decData)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves an IUnknown element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetUnknown (BYVAL idx AS LONG) THREADSAFE AS IUnknown
      LOCAL hr AS LONG, vt AS WORD, pUnk AS IUnknown
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UNKNOWN THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, pUnk)
      METHOD = pUnk
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the IUnknown element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutUnknown (BYVAL idx AS LONG, BYVAL pUnk AS IUnknown) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UNKNOWN THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, pUnk)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends an IUnknown to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendUnknown (BYVAL pUnk AS IUnknown) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_UNKNOWN, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_UNKNOWN THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, pUnk)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves an IUnknown element of the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_GetDispatch (BYVAL idx AS LONG) THREADSAFE AS IDispatch
      LOCAL hr AS LONG, vt AS WORD, pDisp AS IDispatch
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_DISPATCH THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayGetElement(m_psa, idx, pDisp)
      METHOD = pDisp
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stores the IUnknown element at a given location in the array.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_PutDispatch (BYVAL idx AS LONG, BYVAL pDisp AS IDispatch) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_DISPATCH THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      hr = SafeArrayPutElement(m_psa, idx, pDisp)
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Appends an IUnknown to the end of the safe array.
   ' If the safe array doesn't exist, an empty one-dimensional array is created.
   ' OBJRESULT:
   '   Returns S_OK on success, or an error HRESULT on failure.
   ' =====================================================================================
   METHOD SA_1D_AppendDispatch (BYVAL pDisp AS IDispatch) THREADSAFE
      LOCAL hr AS LONG, vt AS WORD, cElements AS DWORD, lLBound AS LONG, idx AS DWORD
      IF m_psa = %NULL THEN ME.SA_1D_Create(%VT_DISPATCH, 0, 0)
      IF m_psa = %NULL THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF (@m_psa.fFeatures AND %FADF_FIXEDSIZE) = %FADF_FIXEDSIZE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SafeArrayGetDim(m_psa) <> 1 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      hr = SafeArrayGetVartype(m_psa, vt)
      IF vt <> %VT_DISPATCH THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_DATA)
         EXIT METHOD
      END IF
      cElements = @m_psa.rgsabound(0).cElements + 1
      lLBound = @m_psa.rgsabound(0).lLBound
      ME.SA_1D_Redim(cElements)
      hr = OBJRESULT
      IF hr = %S_OK THEN
         idx = cElements - 1 + lLBound
         hr = SafeArrayPutElement(m_psa, idx, pDisp)
      END IF
      METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' You can attach a wide text string to an array for informational or documentation.
   ' =====================================================================================
   PROPERTY GET SA_ArrayInfo () THREADSAFE AS WSTRING
      PROPERTY = m_ArrayInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET SA_ArrayInfo (BYVAL bstrInfo AS WSTRING) THREADSAFE
      m_ArrayInfo = bstrInfo
   END PROPERTY
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ========================================================================================
' Creates an instance of the class.
' ========================================================================================
FUNCTION NewSafeArray () AS ISafeArray
   LOCAL psa AS ISafeArray
   psa = CLASS "CSafeArray"
   FUNCTION = psa
END FUNCTION
' ========================================================================================
