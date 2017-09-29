' ########################################################################################
' Microsoft Windows
' File: filterreg.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FILTERREG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "filter.inc"

' ########################################################################################
' IUrlAccessor ILoadFilter
' IID = C7310722-AC80-11D1-8DF3-00C04FB6EF4F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILoadFilter_INTERFACE_DEFINED)
    %ILoadFilter_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE FILTERED_DATA_SOURCES DWORD
   pwcsExtension AS WSTRINGZ PTR   ' const WCHAR *
   pwcsMime      AS WSTRINGZ PTR   ' const WCHAR *
   pClsid        AS GUID PTR       ' const CLSID *
   pwcsOverride  AS WSTRINGZ PTR   ' const WCHAR *
END TYPE

$IID_ILoadFilter = GUID$("{C7310722-AC80-11D1-8DF3-00C04FB6EF4F}")

INTERFACE ILoadFilter $IID_ILoadFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadIFilter ( _                               ' VTable offset = 12
     BYREF pwcsPath AS WSTRINGZ _                       ' __in LPCWSTR pwcsPath
   , BYREF pFilteredSources AS FILTERED_DATA_SOURCES _  ' __in FILTERED_DATA_SOURCES *pFilteredSources
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL fUseDefault AS LONG _                        ' __in BOOL fUseDefault
   , BYREF pFilterClsid AS GUID _                       ' __inout CLSID *pFilterClsid
   , BYREF SearchDecSize AS LONG _                      ' __inout int *SearchDecSize
   , BYREF pwcsSearchDesc AS WSTRINGZ _                 ' __inout WCHAR **pwcsSearchDesc
   , BYREF ppIFilt AS IFilter _                         ' __inout IFilter **ppIFilt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadIFilterFromStorage ( _                    ' VTable offset = 12
     BYVAL pStg AS IStorage _                           ' __in IStorage *pStg
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pwcsOverride AS WSTRINGZ _                   ' __in LPCWSTR pwcsOverride
   , BYVAL fUseDefault AS LONG _                        ' __in BOOL fUseDefault
   , BYREF pFilterClsid AS GUID _                       ' __inout CLSID *pFilterClsid
   , BYREF SearchDecSize AS LONG _                      ' __inout int *SearchDecSize
   , BYREF pwcsSearchDesc AS WSTRINGZ _                 ' __inout WCHAR **pwcsSearchDesc
   , BYREF ppIFilt AS IFilter _                         ' __inout IFilter **ppIFilt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadIFilterFromStream ( _                     ' VTable offset = 12
     BYVAL pStm AS IStream _                            ' __in IStream *pStm
   , BYREF pFilteredSources AS FILTERED_DATA_SOURCES _  ' __in FILTERED_DATA_SOURCES *pFilteredSources
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL fUseDefault AS LONG _                        ' __in BOOL fUseDefault
   , BYREF pFilterClsid AS GUID _                       ' __inout CLSID *pFilterClsid
   , BYREF SearchDecSize AS LONG _                      ' __inout int *SearchDecSize
   , BYREF pwcsSearchDesc AS WSTRINGZ _                 ' __inout WCHAR **pwcsSearchDesc
   , BYREF ppIFilt AS IFilter _                         ' __inout IFilter **ppIFilt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILoadFilter_INTERFACE_DEFINED__ */
