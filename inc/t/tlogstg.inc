' ########################################################################################
' Microsoft Windows
' File: tlogstg.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TLOGSTG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "shtypes.inc"

' // Size = 24 bytes
TYPE WINDOWDATA DWORD
   dwWindowID      AS DWORD            ' DWORD
   uiCP            AS DWORD            ' UINT
   pidl            AS ITEMIDLIST PTR   ' PIDLIST_ABSOLUTE
   lpszUrl         AS WSTRINGZ PTR     ' LPWSTR
   lpszUrlLocation AS WSTRINGZ PTR     ' LPWSTR
   lpszTitle       AS WSTRINGZ PTR     ' LPWSTR
END TYPE

' ########################################################################################
' Interface name = ITravelLogEntry
' IID = {7EBFDD87-AD18-11D3-A4C5-00C04F72D6B8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITravelLogEntry_INTERFACE_DEFINED)
    %ITravelLogEntry_INTERFACE_DEFINED = 1

$IID_ITravelLogEntry = GUID$("{7EBFDD87-AD18-11D3-A4C5-00C04F72D6B8}")

INTERFACE ITravelLogEntry $IID_ITravelLogEntry

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTitle ( _                                  ' VTable offset = 12
     BYREF ppszTitle AS DWORD _                         ' __out LPOLESTR *ppszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetURL ( _                                    ' VTable offset = 16
     BYREF ppszURL AS DWORD _                           ' __out LPOLESTR *ppszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITravelLogEntry_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITravelLogClient
' IID = {241C033E-E659-43DA-AA4D-4086DBC4758D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITravelLogClient_INTERFACE_DEFINED)
    %ITravelLogClient_INTERFACE_DEFINED = 1

$IID_ITravelLogClient = GUID$("{241C033E-E659-43DA-AA4D-4086DBC4758D}")

INTERFACE ITravelLogClient $IID_ITravelLogClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindWindowByIndex ( _                         ' VTable offset = 12
     BYVAL dwID AS DWORD _                              ' __in DWORD dwID
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindowData ( _                             ' VTable offset = 16
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF pWinData AS WINDOWDATA _                     ' __out LPWINDOWDATA pWinData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadHistoryPosition ( _                       ' VTable offset = 20
     BYREF pszUrlLocation AS WSTRINGZ _                 ' __in LPWSTR pszUrlLocation
   , BYVAL dwPosition AS DWORD _                        ' __in DWORD dwPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITravelLogClient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumTravelLogEntry
' IID = {7EBFDD85-AD18-11D3-A4C5-00C04F72D6B8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumTravelLogEntry_INTERFACE_DEFINED)
   %IEnumTravelLogEntry_INTERFACE_DEFINED = 1

$IID_IEnumTravelLogEntry = GUID$("{7EBFDD85-AD18-11D3-A4C5-00C04F72D6B8}")

INTERFACE IEnumTravelLogEntry $IID_IEnumTravelLogEntry

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgElt AS ITravelLogEntry _                   ' __out ITravelLogEntry **rgElt
   , BYREF pcEltFetched AS DWORD _                      ' __out ULONG *pcEltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumTravelLogEntry _              ' __out IEnumTravelLogEntry **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumTravelLogEntry_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITravelLogStg
' IID = {7EBFDD80-AD18-11D3-A4C5-00C04F72D6B8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITravelLogStg_INTERFACE_DEFINED)
    %ITravelLogStg_INTERFACE_DEFINED = 1

' enum TLENUM
%TLEF_RELATIVE_INCLUDE_CURRENT = &H1
%TLEF_RELATIVE_BACK            = &H10
%TLEF_RELATIVE_FORE            = &H20
%TLEF_INCLUDE_UNINVOKEABLE     = &H40
%TLEF_ABSOLUTE                 = &H31

'typedef DWORD TLENUMF;

$IID_ITravelLogStg    = GUID$("{7EBFDD80-AD18-11D3-A4C5-00C04F72D6B8}")
$SID_STravelLogCursor = GUID$("{7EBFDD80-AD18-11D3-A4C5-00C04F72D6B8}")

INTERFACE ITravelLogStg $IID_ITravelLogStg

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateEntry ( _                               ' VTable offset = 12
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCOLESTR pszUrl
   , BYREF pszTitle AS WSTRINGZ _                       ' __in LPCOLESTR pszTitle
   , BYVAL ptleRelativeTo AS ITravelLogEntry _          ' __in ITravelLogEntry *ptleRelativeTo
   , BYVAL fPrepend AS LONG _                           ' __in BOOL fPrepend
   , BYREF pptle AS ITravelLogEntry _                   ' __out ITravelLogEntry **pptle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TravelTo ( _                                  ' VTable offset = 16
     BYVAL ptle AS ITravelLogEntry _                    ' __in ITravelLogEntry *ptle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEntries ( _                               ' VTable offset = 20
     BYVAL flags AS DWORD _                             ' __in TLENUMF flags
   , BYREF ppenum AS IEnumTravelLogEntry _              ' __out IEnumTravelLogEntry **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindEntries ( _                               ' VTable offset = 24
     BYVAL flags AS DWORD _                             ' __in TLENUMF flags
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCOLESTR pszUrl
   , BYREF ppenum AS IEnumTravelLogEntry _              ' __out IEnumTravelLogEntry **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYVAL flags AS DWORD _                             ' __in TLENUMF flags
   , BYREF pcEntries AS DWORD _                         ' __out DWORD *pcEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveEntry ( _                               ' VTable offset = 32
     BYVAL ptle AS ITravelLogEntry _                    ' __in ITravelLogEntry *ptle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeEntry ( _                          ' VTable offset = 36
     BYVAL iOffset AS LONG _                            ' __in int iOffset
   , BYREF ptle AS ITravelLogEntry _                    ' __out ITravelLogEntry **ptle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITravelLogStg_INTERFACE_DEFINED__ */
