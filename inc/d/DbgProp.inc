' ########################################################################################
' Microsoft Windows
' File: DbgProp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'/* IDebugProperty Intro
' *
' * The IDebugProperty interface provides a language-neutral way to browse entities such as:
' *
' * 	- object properties, methods, and events
' * 	- interfaces
' * 	- local variables
' * 	-·etc.
' *
' * IDebugProperty is not intended to be a general replacement for ITypeInfo.
' * For example, it does not include enough low-level information to construct vtable
' * calls or implement IDispatch.
' *
' * Instead, IDebugProperty is intended to provide human-readable information to
' * allow IDE users to browse and modify objects at design
' * or run-time.  Because of this more limited scope, IDebugProperty is much easier
' * to use and to implement than ITypeInfo.
' *
' * INTERFACE NOTES:
' * ===============
' * 1) Run-time type vs. declared type
' *    The type of a DebugProperty can be determined via two methods.  When the type
' *    is obtained via GetPropertyInfo, the type is the *run-time* type.  However,
' *    when the type obtained via a GetMemberEnum on the parent, the type is the
' *    *declared* type.  In other words, object 'A' will give you its run-time
' *    type, but A's parent will give you A's declared type.
' *
' * ISSUE: other guids?  guidSuperClass, guidMostDerived?
' * ISSUE: too many QIs to get IDebugExtendedProp
' * ISSUE: out of attrib bits
' * ISSUE: specify filters (thru guids?)
' */

#INCLUDE THIS ONCE
%DBGPROP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

'// -----------------------------------------------------------------------
'// OBJECT ATTRIBUTES
'// AD1 type was OBJECT_ATTRIB, enums were OBJECTATTRIB_foo, struct was PropertyInfo
'// AD2 type is  OBJECTATTRIB,  enums are  OBJECT_ATTRIB_foo,struct is DebugPropertyInfo
'// confusing, oh yes indeed, please someone come up with a better solution

' enum OBJECT_ATTRIB_FLAG

'// ---------------------
'// Slot Characteristics
%OBJECT_ATTRIB_NO_ATTRIB            = 0???
%OBJECT_ATTRIB_NO_NAME              = &H1???     ' // this slot has no name
%OBJECT_ATTRIB_NO_TYPE              = &H2???     ' // this slot has no type
%OBJECT_ATTRIB_NO_VALUE             = &H4???     ' // this slot has no value
%OBJECT_ATTRIB_VALUE_IS_INVALID     = &H8???     ' // the value in this slot is invalid
%OBJECT_ATTRIB_VALUE_IS_OBJECT      = &H10???    ' // value is an object that can be expanded into a new object browser
%OBJECT_ATTRIB_VALUE_IS_ENUM        = &H20???    ' // value has enumerated values that might go into a drop down
%OBJECT_ATTRIB_VALUE_IS_CUSTOM      = &H40???    ' // value has a custom viewer (use custom view CLSID)
%OBJECT_ATTRIB_OBJECT_IS_EXPANDABLE = &H70???    ' // the object has children
%OBJECT_ATTRIB_VALUE_HAS_CODE       = &H80???    ' // the value has associated code

'// ---------------------
'// Attributes about a slot's type
%OBJECT_ATTRIB_TYPE_IS_OBJECT       = &H100???   ' // the type has an object browser
%OBJECT_ATTRIB_TYPE_HAS_CODE        = &H200???   ' // the type has associated code
%OBJECT_ATTRIB_TYPE_IS_EXPANDABLE   = &H100???   ' // the type is expandable
%OBJECT_ATTRIB_SLOT_IS_CATEGORY     = &H400???   ' // indication that this slot is a category
%OBJECT_ATTRIB_VALUE_READONLY       = &H800???   ' // the value is read-only

'// ---------------------
'// Common attributes

'// field access control
%OBJECT_ATTRIB_ACCESS_PUBLIC        = &H1000???
%OBJECT_ATTRIB_ACCESS_PRIVATE       = &H2000???
%OBJECT_ATTRIB_ACCESS_PROTECTED     = &H4000???
%OBJECT_ATTRIB_ACCESS_FINAL         = &H8000???
'// storage types
%OBJECT_ATTRIB_STORAGE_GLOBAL       = &H10000???
%OBJECT_ATTRIB_STORAGE_STATIC       = &H20000???
%OBJECT_ATTRIB_STORAGE_FIELD        = &H40000???
'// type modifiers
%OBJECT_ATTRIB_STORAGE_VIRTUAL      = &H80000???    ' // this slot is virtual (do we need pure virtual?)
%OBJECT_ATTRIB_TYPE_IS_CONSTANT     = &H100000???   ' // this slot is a constant value
%OBJECT_ATTRIB_TYPE_IS_SYNCHRONIZED = &H200000???   ' // this slot is thread synchronized
%OBJECT_ATTRIB_TYPE_IS_VOLATILE     = &H400000???   ' // this slot is volatile WRT persistent storage
%OBJECT_ATTRIB_HAS_EXTENDED_ATTRIBS = &H800000???   ' // has attributes above and beyond these predefined bits

'// ---------------------
'// Kind information (I'm not sure how useful these are)
%OBJECT_ATTRIB_IS_CLASS             = &H1000000???
%OBJECT_ATTRIB_IS_FUNCTION          = &H2000000???
%OBJECT_ATTRIB_IS_VARIABLE          = &H4000000???
%OBJECT_ATTRIB_IS_PROPERTY          = &H8000000???
%OBJECT_ATTRIB_IS_MACRO             = &H10000000???
%OBJECT_ATTRIB_IS_TYPE              = &H20000000???
%OBJECT_ATTRIB_IS_INHERITED         = &H40000000???
%OBJECT_ATTRIB_IS_INTERFACE         = &H80000000???

'// -----------------------------------------------------------------------
'// DebugPropertyInfo
'// Basic info that all IDebugProperty implementations must support

'// Flags used to specify DebugPropertyInfo (and ExtendedDebugPropertyInfo) fields
' enum PROP_INFO_FLAGS
%PROP_INFO_NAME       = &H1???         ' // init the bstrName field
%PROP_INFO_TYPE       = &H2???         ' // init the bstrType field
%PROP_INFO_VALUE      = &H4???         ' // init the bstrValue field
%PROP_INFO_FULLNAME   = &H20???        ' // init the full name field
%PROP_INFO_ATTRIBUTES = &H8???         ' // init the dwAttrib field
%PROP_INFO_DEBUGPROP  = &H10???        ' // init the pDebugProp field
%PROP_INFO_AUTOEXPAND = &H8000000???   ' // make the Value result auto-expand

%PROP_INFO_STANDARD =  ((((%PROP_INFO_NAME OR %PROP_INFO_TYPE) OR %PROP_INFO_VALUE) OR %PROP_INFO_ATTRIBUTES))
%PROP_INFO_ALL = ((((((%PROP_INFO_NAME OR %PROP_INFO_TYPE) OR %PROP_INFO_VALUE) OR %PROP_INFO_FULLNAME) OR %PROP_INFO_ATTRIBUTES) OR %PROP_INFO_DEBUGPROP))

' // Size = 28 bytes
TYPE DebugPropertyInfo DWORD
   m_dwValidFields AS DWORD       ' DWORD
   m_bstrName      AS DWORD       ' BSTR
   m_bstrType      AS DWORD       ' BSTR
   m_bstrValue     AS DWORD       ' BSTR
   m_bstrFullName  AS DWORD       ' BSTR
   m_dwAttrib      AS DWORD       ' DWORD
   m_pDebugProp    AS DWORD PTR   ' IDebugProperty *
END TYPE

'// -----------------------------------------------------------------------
'// Extended info that some IDebugProperty implementations support

'// Flags used to specify ExtendedDebugPropertyInfo fields
' enum EX_PROP_INFO_FLAGS
%EX_PROP_INFO_ID           = &H100???    ' // init the nDISPID field
%EX_PROP_INFO_NTYPE        = &H200???    ' // init the nType field
%EX_PROP_INFO_NVALUE       = &H400???    ' // init the varValue field
%EX_PROP_INFO_LOCKBYTES    = &H800???    ' // init the plb field
%EX_PROP_INFO_DEBUGEXTPROP = &H1000???   ' // init the pDebugExtProp field

' // Size = 64 bytes
TYPE ExtendedDebugPropertyInfo QWORD FILL
   dwValidFields AS DWORD            ' DWORD
   pszName       AS WSTRINGZ PTR     ' LPOLESTR
   pszType       AS WSTRINGZ PTR     ' LPOLESTR
   pszValue      AS WSTRINGZ PTR     ' LPOLESTR
   pszFullName   AS WSTRINGZ PTR     ' LPOLESTR
   dwAttrib      AS DWORD            ' DWORD
   pDebugProp    AS DWORD PTR        ' IDebugProperty *
   nDISPID       AS DWORD            ' DWORD
   nType         AS DWORD            ' DWORD
   varValue      AS tagVARIANT       ' VARIANT
   plbValue      AS DWORD PTR        ' ILockBytes *
   pDebugExtProp AS DWORD PTR        ' IDebugExtendedProperty *
END TYPE


' ########################################################################################
' Interface name = IDebugProperty
' IID = 51973C41-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugProperty_INTERFACE_DEFINED)
    %IDebugProperty_INTERFACE_DEFINED = 1

$IID_IDebugProperty = GUID$("{51973C50-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugProperty $IID_IDebugProperty

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPropertyInfo ( _                           ' VTable offset = 12
     BYVAL dwFieldSpec AS DWORD _                       ' __in DWORD dwFieldSpec
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF pPropertyInfo AS DebugPropertyInfo _         ' __out DebugPropertyInfo *pPropertyInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedInfo ( _                           ' VTable offset = 16
     BYVAL cInfos AS DWORD _                            ' __in ULONG cInfos
   , BYREF rgguidExtendedInfo AS GUID _                 ' __in GUID *rgguidExtendedInfo
   , BYREF rgvar AS VARIANT _                           ' __out VARIANT *rgvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValueAsString ( _                          ' VTable offset = 20
     BYREF pszValue AS WSTRINGZ _                       ' __in LPCOLESTR pszValue
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMembers ( _                               ' VTable offset = 24
     BYVAL dwFieldSpec AS DWORD _                       ' __in DWORD dwFieldSpec
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF refiid AS GUID _                             ' __in REFIID refiid
   , BYREF ppepi AS IEnumDebugPropertyInfo _            ' __out IEnumDebugPropertyInfo **ppepi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 28
     BYREF ppDebugProp AS IDebugProperty _              ' __out IDebugProperty **ppDebugProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumDebugPropertyInfo
' IID = 51973C51-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDebugPropertyInfo_INTERFACE_DEFINED)
    %IEnumDebugPropertyInfo_INTERFACE_DEFINED = 1

$IID_IEnumDebugPropertyInfo = GUID$("{51973C51-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumDebugPropertyInfo $IID_IEnumDebugPropertyInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pi AS DebugPropertyInfo _                    ' __out DebugPropertyInfo *pi
   , BYREF pcEltsfetched AS DWORD _                     ' __out ULONG *pcEltsfetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppepi AS IEnumDebugPropertyInfo _            ' __out IEnumDebugPropertyInfo **ppepi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugPropertyInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebugExtendedProperty
' IID = 51973C52-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugProperty
' ########################################################################################

#IF NOT %DEF(%IDebugExtendedProperty_INTERFACE_DEFINED)
    %IDebugExtendedProperty_INTERFACE_DEFINED = 1

$IID_IDebugExtendedProperty = GUID$("{51973C52-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugExtendedProperty $IID_IDebugExtendedProperty

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugProperty methods
   ' =====================================================================================
   METHOD GetPropertyInfo ( _                           ' VTable offset = 12
     BYVAL dwFieldSpec AS DWORD _                       ' __in DWORD dwFieldSpec
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF pPropertyInfo AS DebugPropertyInfo _         ' __out DebugPropertyInfo *pPropertyInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedInfo ( _                           ' VTable offset = 16
     BYVAL cInfos AS DWORD _                            ' __in ULONG cInfos
   , BYREF rgguidExtendedInfo AS GUID _                 ' __in GUID *rgguidExtendedInfo
   , BYREF rgvar AS VARIANT _                           ' __out VARIANT *rgvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValueAsString ( _                          ' VTable offset = 20
     BYREF pszValue AS WSTRINGZ _                       ' __in LPCOLESTR pszValue
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMembers ( _                               ' VTable offset = 24
     BYVAL dwFieldSpec AS DWORD _                       ' __in DWORD dwFieldSpec
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF refiid AS GUID _                             ' __in REFIID refiid
   , BYREF ppepi AS IEnumDebugPropertyInfo _            ' __out IEnumDebugPropertyInfo **ppepi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 28
     BYREF ppDebugProp AS IDebugProperty _              ' __out IDebugProperty **ppDebugProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugExtendedProperty methods
   ' =====================================================================================
   METHOD GetExtendedPropertyInfo ( _                   ' VTable offset = 32
     BYVAL dwFieldSpec AS DWORD _                       ' __in DWORD dwFieldSpec
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF pExtendedPropertyInfo AS ExtendedDebugPropertyInfo _ ' __out ExtendedDebugPropertyInfo *pExtendedPropertyInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumExtendedMembers ( _                       ' VTable offset = 36
     BYVAL dwFieldSpec AS DWORD _                       ' __in DWORD dwFieldSpec
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF ppeepi AS IEnumDebugExtendedPropertyInfo _   ' __out IEnumDebugExtendedPropertyInfo *ppeepi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugExtendedProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumDebugExtendedPropertyInfo
' IID = 51973C53-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED)
    %IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED = 1

$IID_IEnumDebugExtendedPropertyInfo = GUID$("{51973C53-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumDebugExtendedPropertyInfo $IID_IEnumDebugExtendedPropertyInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgExtendedPropertyInfo AS ExtendedDebugPropertyInfo _ ' __out ExtendedDebugPropertyInfo *rgExtendedPropertyInfo
   , BYREF pcEltsfetched AS DWORD _                     ' __out ULONG *pcEltsfetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF pedpe AS IEnumDebugExtendedPropertyInfo _    ' __out IEnumDebugExtendedPropertyInfo **pedpe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPerPropertyBrowsing2
' IID = 51973C54-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPerPropertyBrowsing2_INTERFACE_DEFINED)
    %IPerPropertyBrowsing2_INTERFACE_DEFINED = 1

$IID_IPerPropertyBrowsing2 = GUID$("{51973C54-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IPerPropertyBrowsing2 $IID_IPerPropertyBrowsing2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDisplayString ( _                          ' VTable offset = 12
     BYVAL dispid AS LONG _                             ' __in DISPID dispid
   , BYREF pBstr AS WSTRING _                           ' __out BSTR *pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapPropertyToPage ( _                         ' VTable offset = 16
     BYVAL dispid AS LONG _                             ' __in DISPID dispid
   , BYREF pClsidPropPage AS GUID _                     ' __out CLSID *pClsidPropPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPredefinedStrings ( _                      ' VTable offset = 20
     BYVAL dispid AS LONG _                             ' __in DISPID dispid
   , BYREF pCaStrings AS CALPOLESTR _                   ' __out CALPOLESTR *pCaStrings
   , BYREF pCaCookies AS CADWORD _                      ' __out CADWORD *pCaCookies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPredefinedValue ( _                        ' VTable offset = 24
     BYVAL dispid AS LONG _                             ' __in DISPID dispid
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPerPropertyBrowsing2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebugPropertyEnumType_All
' IID = 51973C55-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugPropertyEnumType_All_INTERFACE_DEFINED)
    %IDebugPropertyEnumType_All_INTERFACE_DEFINED = 1

$IID_IDebugPropertyEnumType_All = GUID$("{51973C55-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugPropertyEnumType_All $IID_IDebugPropertyEnumType_All

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pname AS WSTRING _                           ' __out BSTR *pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugPropertyEnumType_All_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebugPropertyEnumType_Locals
' IID = 51973C56-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugPropertyEnumType_All
' ########################################################################################

#IF NOT %DEF(%IDebugPropertyEnumType_Locals_INTERFACE_DEFINED)
    %IDebugPropertyEnumType_Locals_INTERFACE_DEFINED = 1

$IID_IDebugPropertyEnumType_Locals = GUID$("{51973C56-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugPropertyEnumType_Locals $IID_IDebugPropertyEnumType_Locals

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugPropertyEnumType_All method
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pname AS WSTRING _                           ' __out BSTR *pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebugPropertyEnumType_Arguments
' IID = 51973C57-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugPropertyEnumType_All
' ########################################################################################

#IF NOT %DEF(%IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED)
    %IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED = 1

$IID_IDebugPropertyEnumType_Arguments = GUID$("{51973C57-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugPropertyEnumType_Arguments $IID_IDebugPropertyEnumType_Arguments

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugPropertyEnumType_All method
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pname AS WSTRING _                           ' __out BSTR *pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebugPropertyEnumType_LocalsPlusArgs
' IID = 51973C58-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugPropertyEnumType_All
' ########################################################################################

#IF NOT %DEF(%IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED)
    %IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED = 1

$IID_IDebugPropertyEnumType_LocalsPlusArgs = GUID$("{51973C58-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugPropertyEnumType_LocalsPlusArgs $IID_IDebugPropertyEnumType_LocalsPlusArgs

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugPropertyEnumType_All method
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pname AS WSTRING _                           ' __out BSTR *pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebugPropertyEnumType_Registers
' IID = 51973C59-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugPropertyEnumType_All
' ########################################################################################

#IF NOT %DEF(%IDebugPropertyEnumType_Registers_INTERFACE_DEFINED)
    %IDebugPropertyEnumType_Registers_INTERFACE_DEFINED = 1

$IID_IDebugPropertyEnumType_Registers = GUID$("{51973C59-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugPropertyEnumType_Registers $IID_IDebugPropertyEnumType_Registers

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugPropertyEnumType_All method
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pname AS WSTRING _                           ' __out BSTR *pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__ */
