' ########################################################################################
' Microsoft Windows
' File: UIRibbonPropertyHelpers.inc
' Contents: Property helper functions for the Windows Ribbon Framework
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UIRIBBONPROPERTYHELPERS_INC = 1

'#pragma once

#INCLUDE ONCE "propvarutil.inc"
#INCLUDE ONCE "UIRibbon.inc"

'interface IUIImage;

'#ifndef TUIPROPERTYKEYDEFINED
'// A version of PROPERTYKEY whose VARTYPE can be tested at compile time.
'#include <pshpack8.h>
'template<VARTYPE T>
'struct TUIPROPERTYKEY
'{
'  GUID fmtid;
'  DWORD pid;
'  inline operator const PROPERTYKEY&() const { return reinterpret_cast<const PROPERTYKEY&>(*this); }
'  inline const PROPERTYKEY* operator&() const { return reinterpret_cast<const PROPERTYKEY*>(this); }
'};
'#include <poppack.h>

'C_ASSERT(sizeof(TUIPROPERTYKEY<VT_BOOL>) == sizeof(PROPERTYKEY));

'#define TUIPROPERTYKEYDEFINED
'#endif // TUIPROPERTYKEYDEFINED

'// UIBreakCheckType is being used to do both Compilation and Runtime checking of types on PROPVARIANTs

'struct UIWrongType {};

'template<class A, VARTYPE B>
'struct UIBreakCheckType
'{
'    // If a PROPERTYKEY/type combination is invalid, compilation will break (it will try to cast a bool to UIWrongType)
'    typedef UIWrongType _Type;
'    static bool Validate(REFPROPERTYKEY key) { UNREFERENCED_PARAMETER(key); return false; }
'};

'#define UI_REGISTER_TYPE( type ) \
'    template<> struct UIBreakCheckType< TUIPROPERTYKEY<type>, type > \
'    { \
'        typedef bool _Type; \
'        static bool Validate(REFPROPERTYKEY key) { UNREFERENCED_PARAMETER(key); return true; } \
'    }; \
'    template<> struct UIBreakCheckType< PROPERTYKEY, type > \
'    { \
'        typedef bool _Type; \
'        /* we cannot catch at compilation time when PROPERTYKEYs are by reference, so check at runtime */ \
'        static bool Validate(REFPROPERTYKEY key) { return (type) == key.pid; }\
'    };

'// Register known types
'UI_REGISTER_TYPE( VT_BOOL )
'UI_REGISTER_TYPE( VT_UI4 )
'UI_REGISTER_TYPE( VT_LPWSTR )
'UI_REGISTER_TYPE( VT_DECIMAL )
'UI_REGISTER_TYPE( VT_UNKNOWN )
'UI_REGISTER_TYPE( VT_ARRAY|VT_UNKNOWN )

'//======================================================================================
'// PROPVARIANT initializer helpers

'template<class T>
'HRESULT UIInitPropertyFromBoolean(const T& propertyKey, BOOL fVal, __out PROPVARIANT* pPropVar)
'{
'    // If this fails to compile, it means this property is not of type VT_BOOL
'    UIBreakCheckType<T, VT_BOOL>::_Type valid = UIBreakCheckType<T, VT_BOOL>::Validate(propertyKey);
'    return valid ? InitPropVariantFromBoolean(fVal, pPropVar) : E_INVALIDARG;
'}

FUNCTION UIInitPropertyFromBoolean (BYVAL fVal AS LONG, BYREF pPropVar AS PROPVARIANT) AS LONG
   FUNCTION = InitPropVariantFromBoolean(fVal, pPropVar)
END FUNCTION


'template<class T>
'HRESULT UIInitPropertyFromUInt32(const T& propertyKey, UINT ulVal, __out PROPVARIANT* pPropVar)
'{
'    // If this fails to compile, it means this property is not of type VT_UI4
'    UIBreakCheckType<T, VT_UI4>::_Type valid = UIBreakCheckType<T, VT_UI4>::Validate(propertyKey);
'    return valid ? InitPropVariantFromUInt32(ulVal, pPropVar) : E_INVALIDARG;
'}

FUNCTION UIInitPropertyFromUInt32 (BYVAL ulVal AS DWORD, BYREF pPropVar AS PROPVARIANT) AS LONG
   FUNCTION = InitPropVariantFromUInt32(ulVal, pPropVar)
END FUNCTION


'template<class T>
'HRESULT UIInitPropertyFromString(const T& propertyKey, __in PCWSTR psz, __out PROPVARIANT* pPropVar)
'{
'    // If this fails to compile, it means this property is not of type VT_LPWSTR
'    UIBreakCheckType<T, VT_LPWSTR>::_Type valid = UIBreakCheckType<T, VT_LPWSTR>::Validate(propertyKey);
'    return valid ? InitPropVariantFromString(psz, pPropVar) : E_INVALIDARG;
'}

FUNCTION UIInitPropertyFromString (BYREF psz AS WSTRINGZ, BYREF pPropVar AS PROPVARIANT) AS LONG
   FUNCTION = InitPropVariantFromString(psz, pPropVar)
END FUNCTION

'template<class T>
'HRESULT UIInitPropertyFromDecimal(const T& propertyKey, const DECIMAL& decValue, __out PROPVARIANT* pPropVar)
'{
'    // If this fails to compile, it means this property is not of type VT_DECIMAL
'    UIBreakCheckType<T, VT_DECIMAL>::_Type valid = UIBreakCheckType<T, VT_DECIMAL>::Validate(propertyKey);
'    if (valid)
'    {
'        //  Must set decVal before vt because the two overlap.
'        pPropVar->decVal = decValue;
'        pPropVar->vt = VT_DECIMAL;
'        return S_OK;
'    }
'    return E_INVALIDARG;
'}

FUNCTION UIInitPropertyFromDecimal (BYREF decValue AS DECIMAL, BYREF pPropVar AS PROPVARIANT) AS LONG
   ' //  Must set decVal before vt because the two overlap.
   pPropVar.decVal = decValue
   pPropVar.vt = %VT_DECIMAL
   FUNCTION = %S_OK
END FUNCTION


'template<class T>
'HRESULT UIInitPropertyFromInterface(const T& propertyKey, __in IUnknown* pUnk, __out PROPVARIANT* pPropVar)
'{
'    // If this fails to compile, it means this property is not of type VT_UNKNOWN
'    UIBreakCheckType<T, VT_UNKNOWN>::_Type valid = UIBreakCheckType<T, VT_UNKNOWN>::Validate(propertyKey);
'    if (valid)
'    {
'        pPropVar->vt = VT_UNKNOWN;
'        pPropVar->punkVal = pUnk;
'        if (pUnk)
'        {
'            pUnk->AddRef();
'        }
'        return S_OK;
'    }
'    return E_INVALIDARG;
'}

FUNCTION UIInitPropertyFromInterface (BYVAL pUnk AS IUnknown, BYREF pPropVar AS PROPVARIANT) AS LONG
   pPropVar.vt = %VT_UNKNOWN
   IF ISOBJECT(pUnk) THEN pUnk.AddRef
   pPropVar.punkVal = OBJPTR(pUnk)
   FUNCTION = %S_OK
END FUNCTION


'template<class T>
'HRESULT UIInitPropertyFromImage(const T& propertyKey, __in IUIImage* pImage, __out PROPVARIANT* pPropVar)
'{
'    return UIInitPropertyFromInterface(propertyKey, pImage, pPropVar);
'}

FUNCTION UIInitPropertyFromImage (BYVAL pImage AS IUIImage, BYREF pPropVar AS PROPVARIANT) AS LONG
   FUNCTION = UIInitPropertyFromInterface(pImage, pPropVar)
END FUNCTION


'template<class T>
'HRESULT UIInitPropertyFromIUnknownArray(const T& propertyKey, __in SAFEARRAY* psa, __out PROPVARIANT* pPropVar)
'{
'    // If this fails to compile, it means this property is not of type VT_ARRAY
'    UIBreakCheckType<T, VT_ARRAY|VT_UNKNOWN>::_Type valid = UIBreakCheckType<T, VT_ARRAY|VT_UNKNOWN>::Validate(propertyKey);
'    if (valid && (psa->fFeatures & FADF_UNKNOWN) )
'    {
'        HRESULT hr = ::SafeArrayCopy(psa, &pPropVar->parray);
'        if (SUCCEEDED(hr))
'        {
'            pPropVar->vt = VT_ARRAY|VT_UNKNOWN;
'        }
'        return hr;
'    }
'    return E_INVALIDARG;
'}

FUNCTION UIInitPropertyFromIUnknownArray (BYVAL psa AS SAFEARRAY PTR, BYREF pPropVar AS PROPVARIANT) AS LONG
   LOCAL hr AS LONG
   IF (@psa.fFeatures AND %FADF_UNKNOWN) THEN
      hr = SafeArrayCopy(psa, pPropVar.parray)
      IF SUCCEEDED(hr) THEN
         pPropVar.vt = %VT_ARRAY OR %VT_UNKNOWN
         FUNCTION = hr
      END IF
   ELSE
      FUNCTION = %E_INVALIDARG
   END IF
END FUNCTION


'//======================================================================================
'// Extract value from PROPVARIANT

'template<class T>
'HRESULT UIPropertyToBoolean(const T& propertyKey, REFPROPVARIANT propvarIn, __out BOOL *pfRet)
'{
'    // If this fails to compile, it means this property is not of type VT_BOOL
'    UIBreakCheckType<T, VT_BOOL>::_Type valid = UIBreakCheckType<T, VT_BOOL>::Validate(propertyKey);
'    return valid ? PropVariantToBoolean(propvarIn, pfRet) : E_INVALIDARG;
'}

FUNCTION UIPropertyToBoolean (BYREF propvarIn AS PROPVARIANT, BYREF pfRet AS LONG) AS LONG
   FUNCTION = PropVariantToBoolean(propvarIn, pfRet)
END FUNCTION

'template<class T>
'HRESULT UIPropertyToUInt32(const T& propertyKey, REFPROPVARIANT propvarIn, __out UINT *pulVal)
'{
'    // If this fails to compile, it means this property is not of type VT_UI4
'    UIBreakCheckType<T, VT_UI4>::_Type valid = UIBreakCheckType<T, VT_UI4>::Validate(propertyKey);
'    return valid ? PropVariantToUInt32(propvarIn, pulVal) : E_INVALIDARG;
'}

FUNCTION UIPropertyToUInt32 (BYREF propvarIn AS PROPVARIANT, BYREF pulVal AS DWORD) AS LONG
   FUNCTION = PropVariantToUInt32(propvarIn, pulVal)
END FUNCTION

'// Allocate a new string and return it in ppszOut
'template<class T>
'HRESULT UIPropertyToStringAlloc(const T& propertyKey, REFPROPVARIANT propvarIn, __deref_out PWSTR *ppszOut)
'{
'    // If this fails to compile, it means this property is not of type VT_LPWSTR
'    UIBreakCheckType<T, VT_LPWSTR>::_Type valid = UIBreakCheckType<T, VT_LPWSTR>::Validate(propertyKey);
'    return valid ? PropVariantToStringAlloc(propvarIn, ppszOut) : E_INVALIDARG;
'}

FUNCTION UIPropertyToStringAlloc (BYREF propvarIn AS PROPVARIANT, BYREF ppszOut AS DWORD) AS LONG
   FUNCTION = PropVariantToStringAlloc(propvarIn, ppszOut)
END FUNCTION

'template<class T>
'HRESULT UIPropertyToDecimal(const T& propertyKey, REFPROPVARIANT propvarIn, __out DECIMAL *pDecValue)
'{
'    // If this fails to compile, it means this property is not of type VT_DECIMAL
'    UIBreakCheckType<T, VT_DECIMAL>::_Type valid = UIBreakCheckType<T, VT_DECIMAL>::Validate(propertyKey);
'    if (valid && propvarIn.vt == VT_DECIMAL)
'    {
'        *pDecValue = propvarIn.decVal;
'        return S_OK;
'    }
'    return E_INVALIDARG;
'}

FUNCTION UIPropertyToDecimal (BYREF propvarIn AS PROPVARIANT, BYREF pDecValue AS DECIMAL) AS LONG
   IF propvarIn.vt = %VT_DECIMAL THEN
      pDecValue = propvarIn.decVal
      FUNCTION = %S_OK
   ELSE
      FUNCTION = %E_INVALIDARG
   END IF
END FUNCTION

'template<class T, class TInterface>
'HRESULT UIPropertyToInterface(const T& propertyKey, REFPROPVARIANT propvarIn, __deref_out TInterface** ppObj)
'{
'    *ppObj = NULL;
'    // If this fails to compile, it means this property is not of type VT_UNKNOWN
'    UIBreakCheckType<T, VT_UNKNOWN>::_Type valid = UIBreakCheckType<T, VT_UNKNOWN>::Validate(propertyKey);
'    if (valid && propvarIn.vt == VT_UNKNOWN)
'    {
'        if (propvarIn.punkVal)
'        {
'            return propvarIn.punkVal->QueryInterface(__uuidof(TInterface), (void**)ppObj);
'        }
'        return S_OK;
'    }
'    return E_INVALIDARG;
'}

DECLARE FUNCTION UIPropertyToInterface_QueryInterface (BYVAL pthis AS DWORD PTR, BYREF riid AS GUID, BYREF ppObj AS IUnknown) AS LONG
FUNCTION UIPropertyToInterface (BYREF propvarIn AS PROPVARIANT, BYREF ppObj AS IUnknown) AS LONG
   LOCAL hr AS LONG
   IF propvarIn.vt = %VT_UNKNOWN THEN
      IF propvarIn.punkVal THEN
         CALL DWORD propvarIn.@@punkVal[0] USING UIPropertyToInterface_QueryInterface(propvarIn.punkVal, $IID_IUNKNOWN, ppObj) TO hr
         FUNCTION = hr
      ELSE
         FUNCTION = %S_OK
      END IF
   ELSE
      FUNCTION = %E_INVALIDARG
   END IF
END FUNCTION

'template<class T>
'HRESULT UIPropertyToImage(const T& propertyKey, REFPROPVARIANT propvarIn, __deref_out IUIImage** ppImage)
'{
'    return UIPropertyToInterface(propertyKey, propvarIn, ppImage);
'}

DECLARE FUNCTION UIPropertyToImage_QueryInterface (BYVAL pthis AS DWORD PTR, BYREF riid AS GUID, BYREF ppImage AS IUIImage) AS LONG
FUNCTION UIPropertyToImage (BYREF propvarIn AS PROPVARIANT, BYREF ppImage AS IUIImage) AS LONG
   LOCAL hr AS LONG
   IF propvarIn.vt = %VT_UNKNOWN THEN
      IF propvarIn.punkVal THEN
         CALL DWORD propvarIn.@@punkVal[0] USING UIPropertyToImage_QueryInterface(propvarIn.punkVal, $IID_IUIImage, ppImage) TO hr
         FUNCTION = hr
      ELSE
         FUNCTION = %S_OK
      END IF
   ELSE
      FUNCTION = %E_INVALIDARG
   END IF
END FUNCTION


'template<class T>
'HRESULT UIPropertyToIUnknownArrayAlloc(const T& propertyKey, REFPROPVARIANT propvarIn, __deref_out SAFEARRAY** ppsa)
'{
'    // If this fails to compile, it means this property is not of type VT_ARRAY
'    UIBreakCheckType<T, VT_ARRAY|VT_UNKNOWN>::_Type valid = UIBreakCheckType<T, VT_ARRAY|VT_UNKNOWN>::Validate(propertyKey);
'    if (valid && propvarIn.vt == (VT_ARRAY|VT_UNKNOWN) )
'    {
'        return ::SafeArrayCopy(propvarIn.parray, ppsa);
'    }
'    return E_INVALIDARG;
'}

FUNCTION UIPropertyToIUnknownArrayAlloc (BYREF propvarIn AS PROPVARIANT, BYREF ppsa AS DWORD) AS LONG
   IF propvarIn.vt = %VT_ARRAY OR %VT_UNKNOWN THEN
      FUNCTION = SafeArrayCopy(propvarIn.parray, ppsa)
   ELSE
      FUNCTION = %E_INVALIDARG
   END IF
END FUNCTION
