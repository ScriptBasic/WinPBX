' ########################################################################################
' Microsoft Windows
' File: ActivAut.inc
' Contents: Declarations for ActiveX Script Authoring
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACTIVAUT_INC = 1

' /* header files for imported files */
#INCLUDE "ocidl.inc"

'//
'// Declarations for ActiveX Script Authoring.
'//

'/* GUIDs
' ********/

'#ifndef _NO_AUTHOR_GUIDS
$CATID_ActiveScriptAuthor = GUID$("{0AEE2A92-BCBB-11d0-8C72-00C04FC2B085}")
$IID_IActiveScriptAuthor = GUID$("{9C109DA0-7006-11d1-B36C-00A0C911E8B2}")
$IID_IScriptNode = GUID$("{0AEE2A94-BCBB-11d0-8C72-00C04FC2B085}")
$IID_IScriptEntry = GUID$("{0AEE2A95-BCBB-11d0-8C72-00C04FC2B085}")
$IID_IScriptScriptlet = GUID$("{0AEE2A96-BCBB-11d0-8C72-00C04FC2B085}")
$IID_IActiveScriptAuthorProcedure = GUID$("{7E2D4B70-BD9A-11d0-9336-00A0C90DCAA9}")
'#endif // _NO_AUTHOR_GUIDS

'/* Interfaces
' *************/

'// Output flags for GetLanguageFlags
%fasaPreferInternalHandler    = &H0001???
%fasaSupportInternalHandler   = &H0002???
%fasaCaseSensitive            = &H0004???

'// Flags for statement completion
%SCRIPT_CMPL_NOLIST           = &H0000???
%SCRIPT_CMPL_MEMBERLIST       = &H0001???
%SCRIPT_CMPL_ENUMLIST         = &H0002???
%SCRIPT_CMPL_PARAMTIP         = &H0004???
%SCRIPT_CMPL_GLOBALLIST       = &H0008???

%SCRIPT_CMPL_ENUM_TRIGGER     = &H0001???
%SCRIPT_CMPL_MEMBER_TRIGGER   = &H0002???
%SCRIPT_CMPL_PARAM_TRIGGER    = &H0003???
%SCRIPT_CMPL_COMMIT           = &H0004???

'// Flags for getting attributes
%GETATTRTYPE_NORMAL           = &H0000???
%GETATTRTYPE_DEPSCAN          = &H0001???

'// GETATTRFLAG_THIS can be used with either GETATTRTYPE_NORMAL or GETATTRTYPE_DEPSCAN
%GETATTRFLAG_THIS             = &H0100???
%GETATTRFLAG_HUMANTEXT        = &H8000???

'// When the GETATTR_LOCALIZE flag is set the following bit will be
'// set for source attributes that should be considered localized
%SOURCETEXT_ATTR_HUMANTEXT    = &H8000???

'// Valid attributes returned for GETATTR_DEPSCAN
%SOURCETEXT_ATTR_IDENTIFIER   = &H0100???
%SOURCETEXT_ATTR_MEMBERLOOKUP = &H0200???

'// When the GETATTRFLAG_THIS flag is set the following bit will be
'// set for the this pointer (JS) or me pointer (VBS)
%SOURCETEXT_ATTR_THIS         = &H0400???


'typedef WORD SOURCE_TEXT_ATTR;
' // This macro is also defined in activdbg.inc
#IF NOT %DEF(%SOURCE_TEXT_ATTR_DEFINED)
%SOURCE_TEXT_ATTR_DEFINED = 1
MACRO SOURCE_TEXT_ATTR = WORD
#ENDIF

' ########################################################################################
' Interface name = IScriptNode
' IID = 0AEE2A94-BCBB-11D0-8C72-00C04FC2B085
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IScriptNode_INTERFACE_DEFINED)
    %IScriptNode_INTERFACE_DEFINED = 1

INTERFACE IScriptNode $IID_IScriptNode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Alive ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 20
     BYREF ppsnParent AS IScriptNode _                  ' __out IScriptNode **ppsnParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexInParent ( _                          ' VTable offset = 24
     BYREF pisn AS DWORD _                              ' __out ULONG *pisn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCookie ( _                                 ' VTable offset = 28
     BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfChildren ( _                       ' VTable offset = 32
     BYREF pcsn AS DWORD _                              ' __out ULONG *pcsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 36
     BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYREF ppsn AS IScriptNode _                        ' __out IScriptNode **ppsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 40
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildEntry ( _                          ' VTable offset = 44
     BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildHandler ( _                        ' VTable offset = 48
     BYREF pszDefaultName AS WSTRINGZ _                 ' __in LPCOLESTR pszDefaultName
   , BYREF prgpszNames AS WSTRINGZ _                    ' __in LPCOLESTR *prgpszNames
   , BYVAL cpszNames AS DWORD _                         ' __in ULONG cpszNames
   , BYREF pszEvent AS WSTRINGZ _                       ' __in LPCOLESTR pszEvent
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL ptiSignature AS ITypeInfo _                  ' __in ITypeInfo *ptiSignature
   , BYVAL iMethodSignature AS DWORD _                  ' __in ULONG iMethodSignature
   , BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScriptNode_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IScriptEntry
' IID = 0AEE2A95-BCBB-11D0-8C72-00C04FC2B085
' Inherited interface = IScriptNode
' ########################################################################################

#IF NOT %DEF(%IScriptEntry_INTERFACE_DEFINED)
    %IScriptEntry_INTERFACE_DEFINED = 1

INTERFACE IScriptEntry $IID_IScriptEntry

   INHERIT IUnknown

   ' =====================================================================================
   ' IScriptNode methods
   ' =====================================================================================
   METHOD Alive ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 20
     BYREF ppsnParent AS IScriptNode _                  ' __out IScriptNode **ppsnParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexInParent ( _                          ' VTable offset = 24
     BYREF pisn AS DWORD _                              ' __out ULONG *pisn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCookie ( _                                 ' VTable offset = 28
     BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfChildren ( _                       ' VTable offset = 32
     BYREF pcsn AS DWORD _                              ' __out ULONG *pcsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 36
     BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYREF ppsn AS IScriptNode _                        ' __out IScriptNode **ppsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 40
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildEntry ( _                          ' VTable offset = 44
     BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildHandler ( _                        ' VTable offset = 48
     BYREF pszDefaultName AS WSTRINGZ _                 ' __in LPCOLESTR pszDefaultName
   , BYREF prgpszNames AS WSTRINGZ _                    ' __in LPCOLESTR *prgpszNames
   , BYVAL cpszNames AS DWORD _                         ' __in ULONG cpszNames
   , BYREF pszEvent AS WSTRINGZ _                       ' __in LPCOLESTR pszEvent
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL ptiSignature AS ITypeInfo _                  ' __in ITypeInfo *ptiSignature
   , BYVAL iMethodSignature AS DWORD _                  ' __in ULONG iMethodSignature
   , BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IScriptEntry methods
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 52
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 56
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 60
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBody ( _                                   ' VTable offset = 64
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 68
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 72
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemName ( _                               ' VTable offset = 76
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemName ( _                               ' VTable offset = 80
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignature ( _                              ' VTable offset = 84
     BYREF ppti AS ITypeInfo _                          ' __out ITypeInfo **ppti
   , BYREF piMethod AS DWORD _                          ' __out ULONG *piMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignature ( _                              ' VTable offset = 88
     BYVAL pti AS ITypeInfo _                           ' __in ITypeInfo *pti
   , BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 92
     BYREF pichMin AS DWORD _                           ' __out ULONG *pichMin
   , BYREF pcch AS DWORD _                              ' __out ULONG *pcch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScriptEntry_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IScriptScriptlet
' IID = 0AEE2A96-BCBB-11D0-8C72-00C04FC2B085
' Inherited interface = IScriptEntry
' ########################################################################################

#IF NOT %DEF(%IScriptScriptlet_INTERFACE_DEFINED)
    %IScriptScriptlet_INTERFACE_DEFINED = 1

INTERFACE IScriptScriptlet $IID_IScriptScriptlet

   INHERIT IUnknown

   ' =====================================================================================
   ' IScriptNode methods
   ' =====================================================================================
   METHOD Alive ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 20
     BYREF ppsnParent AS IScriptNode _                  ' __out IScriptNode **ppsnParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexInParent ( _                          ' VTable offset = 24
     BYREF pisn AS DWORD _                              ' __out ULONG *pisn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCookie ( _                                 ' VTable offset = 28
     BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfChildren ( _                       ' VTable offset = 32
     BYREF pcsn AS DWORD _                              ' __out ULONG *pcsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 36
     BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYREF ppsn AS IScriptNode _                        ' __out IScriptNode **ppsn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 40
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildEntry ( _                          ' VTable offset = 44
     BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildHandler ( _                        ' VTable offset = 48
     BYREF pszDefaultName AS WSTRINGZ _                 ' __in LPCOLESTR pszDefaultName
   , BYREF prgpszNames AS WSTRINGZ _                    ' __in LPCOLESTR *prgpszNames
   , BYVAL cpszNames AS DWORD _                         ' __in ULONG cpszNames
   , BYREF pszEvent AS WSTRINGZ _                       ' __in LPCOLESTR pszEvent
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL ptiSignature AS ITypeInfo _                  ' __in ITypeInfo *ptiSignature
   , BYVAL iMethodSignature AS DWORD _                  ' __in ULONG iMethodSignature
   , BYVAL isn AS DWORD _                               ' __in ULONG isn
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IScriptEntry methods
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 52
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 56
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 60
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBody ( _                                   ' VTable offset = 64
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 68
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 72
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemName ( _                               ' VTable offset = 76
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemName ( _                               ' VTable offset = 80
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignature ( _                              ' VTable offset = 84
     BYREF ppti AS ITypeInfo _                          ' __out ITypeInfo **ppti
   , BYREF piMethod AS DWORD _                          ' __out ULONG *piMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignature ( _                              ' VTable offset = 88
     BYVAL pti AS ITypeInfo _                           ' __in ITypeInfo *pti
   , BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 92
     BYREF pichMin AS DWORD _                           ' __out ULONG *pichMin
   , BYREF pcch AS DWORD _                              ' __out ULONG *pcch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IScriptScriptlet methods
   ' =====================================================================================
   METHOD GetSubItemName ( _                            ' VTable offset = 96
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubItemName ( _                            ' VTable offset = 100
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventName ( _                              ' VTable offset = 104
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventName ( _                              ' VTable offset = 108
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSimpleEventName ( _                        ' VTable offset = 112
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSimpleEventName ( _                        ' VTable offset = 112
     BYREF psz AS WSTRINGZ _                            ' __in LPCOLESTR psz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScriptScriptlet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptAuthor
' IID = 9C109DA0-7006-11D1-B36C-00A0C911E8B2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptAuthor_INTERFACE_DEFINED)
    %IActiveScriptAuthor_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptAuthor $IID_IActiveScriptAuthor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddNamedItem ( _                              ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __in LPCOLESTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pdisp AS IDispatch _                         ' __in IDispatch *pdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddScriptlet ( _                              ' VTable offset = 16
     BYREF pszDefaultName AS WSTRINGZ _                 ' __in LPCOLESTR pszDefaultName
   , BYREF pszCode AS WSTRINGZ _                        ' __in LPCOLESTR pszCode
   , BYREF pszItemName AS WSTRINGZ _                    ' __in LPCOLESTR pszItemName
   , BYREF pszSubItemName AS WSTRINGZ _                 ' __in LPCOLESTR pszSubItemName
   , BYREF pszEventName AS WSTRINGZ _                   ' __in LPCOLESTR pszEventName
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseScriptText ( _                           ' VTable offset = 20
     BYREF pszCode AS WSTRINGZ _                        ' __in LPCOLESTR pszCode
   , BYREF pszItemName AS WSTRINGZ _                    ' __in LPCOLESTR pszItemName
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptTextAttributes ( _                   ' VTable offset = 24
     BYVAL pszCode AS DWORD _                           ' __in LPCOLESTR pszCode
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptletTextAttributes ( _                ' VTable offset = 28
     BYREF pszCode AS WSTRINGZ _                        ' __in LPCOLESTR pszCode
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRoot ( _                                   ' VTable offset = 32
     BYREF ppsp AS IScriptNode _                        ' __out IScriptNode **ppsp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageFlags ( _                          ' VTable offset = 36
     BYREF pgrfasa AS DWORD _                           ' __out DWORD *pgrfasa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventHandler ( _                           ' VTable offset = 40
     BYVAL pdisp AS IDispatch _                         ' __in IDispatch *pdisp
   , BYREF pszItem AS WSTRINGZ _                        ' __in LPCOLESTR pszItem
   , BYREF pszSubItem AS WSTRINGZ _                     ' __in LPCOLESTR pszSubItem
   , BYREF pszEvent AS WSTRINGZ _                       ' __in LPCOLESTR pszEvent
   , BYREF ppse AS IScriptEntry _                       ' __out IScriptEntry **ppse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveNamedItem ( _                           ' VTable offset = 44
     BYREF pszName AS WSTRINGZ _                        ' __in LPCOLESTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTypeLib ( _                                ' VTable offset = 48
     BYREF rguidTypeLib AS GUID _                       ' __in REFGUID rguidTypeLib
   , BYVAL dwMajor AS DWORD _                           ' __in DWORD dwMajor
   , BYVAL dwMinor AS DWORD _                           ' __in DWORD dwMinor
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveTypeLib ( _                             ' VTable offset = 52
     BYREF rguidTypeLib AS GUID _                       ' __in REFGUID rguidTypeLib
   , BYVAL dwMajor AS DWORD _                           ' __in DWORD dwMajor
   , BYVAL dwMinor AS DWORD _                           ' __in DWORD dwMinor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChars ( _                                  ' VTable offset = 56
     BYVAL fRequestedList AS DWORD _                    ' __in DWORD fRequestedList
   , BYREF pbstrChars AS WSTRING _                      ' __out BSTR *pbstrChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfoFromContext ( _                        ' VTable offset = 60
     BYREF pszCode AS WSTRINGZ _                        ' __in LPCOLESTR pszCode
   , BYVAL cchCode AS DWORD _                           ' __in ULONG cchCode
   , BYVAL ichCurrentPosition AS DWORD _                ' __in ULONG ichCurrentPosition
   , BYVAL dwListTypesRequested AS DWORD _              ' __in DWORD dwListTypesRequested
   , BYREF pdwListTypesProvided AS DWORD _              ' __out DWORD *pdwListTypesProvided
   , BYREF pichListAnchorPosition AS DWORD _            ' __out ULONG *pichListAnchorPosition
   , BYREF pichFuncAnchorPosition AS DWORD _            ' __out ULONG *pichFuncAnchorPosition
   , BYREF pmemid AS LONG _                             ' __out MEMBERID *pmemid
   , BYREF piCurrentParameter AS LONG _                 ' __out LONG *piCurrentParameter
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCommitChar ( _                              ' VTable offset = 64
     BYREF ch AS WSTRINGZ _                             ' __in OLECHAR ch
   , BYREF pfcommit AS LONG _                           ' __out BOOL *pfcommit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptAuthor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptAuthorProcedure
' IID = 7E2D4B70-BD9A-11D0-9336-00A0C90DCAA9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptAuthorProcedure_INTERFACE_DEFINED)
    %IActiveScriptAuthorProcedure_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptAuthorProcedure $IID_IActiveScriptAuthorProcedure

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pszCode AS WSTRINGZ _                        ' __in LPCOLESTR pszCode
   , BYREF pszFormalParams AS WSTRINGZ _                ' __in LPCOLESTR pszFormalParams
   , BYREF pszProcedureName AS WSTRINGZ _               ' __in LPCOLESTR pszProcedureName
   , BYREF pszItemName AS WSTRINGZ _                    ' __in LPCOLESTR pszItemName
   , BYREF pszDelimiter AS WSTRINGZ _                   ' __in LPCOLESTR pszDelimiter
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pdispFor AS IDispatch _                      ' __in IDispatch *pdispFor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptAuthorProcedure_INTERFACE_DEFINED__ */
