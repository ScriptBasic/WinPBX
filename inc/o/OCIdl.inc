' ########################################################################################
' Microsoft Windows
' File: OCIdl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OCIDL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "servprov.inc"
#INCLUDE ONCE "urlmon.inc"

#IF NOT %DEF(%IOleControlTypes_INTERFACE_DEFINED)
    %IOleControlTypes_INTERFACE_DEFINED = 1

' UASFLAGS enum
%UAS_NORMAL         = 0
%UAS_BLOCKED        = &H1
%UAS_NOPARENTENABLE = &H2
%UAS_MASK           = &H3

'/* State values for the DISPID_READYSTATE property */

' READYSTATE enum
%READYSTATE_UNINITIALIZED = 0
%READYSTATE_LOADING       = 1
%READYSTATE_LOADED        = 2
%READYSTATE_INTERACTIVE   = 3
%READYSTATE_COMPLETE      = 4

#ENDIF   ' /* __IOleControlTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumConnections interface
' IID = B196B287-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumConnections_INTERFACE_DEFINED)
    %IEnumConnections_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE CONNECTDATA
   pUnk     AS DWORD PTR  ' IUnknown *pUnk
   dwCookie AS DWORD      ' DWORD dwCookie
END TYPE

$IID_IEnumConnections = GUID$("{B196B287-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IEnumConnections $IID_IEnumConnections

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cConnections AS DWORD _                      ' __in ULONG cConnections
   , BYREF rgpcd AS CONNECTDATA _                       ' __out CONNECTDATA * rgpcd
   , BYREF pcFetched AS DWORD _                         ' __out ULONG * pcFetched
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
     BYREF ppenum AS IEnumConnections _                 ' __out IEnumConnections** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumConnections_INTERFACE_DEFINED__ */


' ########################################################################################
' IConnectionPoint interface
' IID = B196B286-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' NOTE: Renamed because of conflicts with built-in PB definition.
' ########################################################################################

#IF NOT %DEF(%IConnectionPoint_INTERFACE_DEFINED)
   %IConnectionPoint_INTERFACE_DEFINED = 1

$IID_IConnectionPoint = GUID$("{B196B286-BAB4-101A-B69C-00AA00341D07}")

INTERFACE COM_IConnectionPoint $IID_IConnectionPoint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetConnectionInterface ( _                    ' VTable offset = 12
     BYREF pIID AS GUID _                               ' __out IID *pIID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectionPointContainer ( _               ' VTable offset = 16
     BYREF ppCPC AS IConnectionPointContainer _         ' __out IConnectionPointContainer **ppCPC)
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 20
     BYVAL pUnkSink AS IUnknown _                       ' __in IUnknown *pUnkSink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 24
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumConnections ( _                           ' VTable offset = 28
     BYREF ppEnum AS IEnumConnections _                 ' __out IEnumConnections **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConnectionPoint_INTERFACE_DEFINED__ */

' *** As built into the PowerBASIC compiler ***

'INTERFACE IConnectionPoint $IID_IConnectionPoint

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD GetConnectionInterface ( _                    ' VTable offset = 12
'     BYREF pIID AS GUID _                               ' __out IID *pIID
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetConnectionPointContainer ( _               ' VTable offset = 16
'     BYREF ppCPC AS DWORD _                             ' __out IConnectionPointContainer **ppCPC)
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD Advise ( _                                    ' VTable offset = 20
'     BYREF pUnkSink AS DWORD _                          ' __in IUnknown *pUnkSink
'   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD Unadvise ( _                                  ' VTable offset = 24
'     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD EnumConnections ( _                           ' VTable offset = 28
'     BYREF ppEnum AS DWORD _                            ' __out IEnumConnections **ppEnum
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IEnumConnectionPoints interface
' IID = B196B285-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumConnectionPoints_INTERFACE_DEFINED)
    %IEnumConnectionPoints_INTERFACE_DEFINED = 1

$IID_IEnumConnectionPoints = GUID$("{B196B285-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IEnumConnectionPoints $IID_IEnumConnectionPoints

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IConnectionPoint _                  ' __out IConnectionPoint * rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG * pceltFetched
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
     BYREF ppenum AS IEnumConnectionPoints _            ' __out IEnumConnectionPoints** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumConnectionPoints_INTERFACE_DEFINED__ */


' ########################################################################################
' IConnectionPointContainer interface
' IID = B196B284-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' NOTE: Renamed because of conflicts with the built-in PB definition.
' ########################################################################################

#IF NOT %DEF(%IConnectionPointContainer_INTERFACE_DEFINED)
    %IConnectionPointContainer_INTERFACE_DEFINED = 1

$IID_IConnectionPointContainer = GUID$("{B196B284-BAB4-101A-B69C-00AA00341D07}")

INTERFACE COM_IConnectionPointContainer $IID_IConnectionPointContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumConnectionPoints ( _                      ' VTable offset = 12
     BYREF ppEnum AS IEnumConnectionPoints _            ' __out IEnumConnectionPoints **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindConnectionPoint ( _                       ' VTable offset = 14
     BYREF riid AS DWORD _                              ' __in REFIID riid
   , BYREF ppCP AS IConnectionPoint _                   ' __out IConnectionPoint **ppCP
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConnectionPointContainer_INTERFACE_DEFINED__ */

' *** As built into the PowerBASIC compiler ***

'INTERFACE IConnectionPointContainer $IID_IConnectionPointContainer


'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD EnumConnectionPoints ( _                      ' VTable offset = 12
'     BYREF ppEnum AS DWORD _                            ' __out IEnumConnectionPoints **ppEnum
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD FindConnectionPoint ( _                       ' VTable offset = 14
'     BYREF riid AS DWORD _                              ' __in REFIID riid
'   , BYREF ppCP AS DWORD _                              ' __out IConnectionPoint **ppCP
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IClassFactory2 interface
' IID = B196B28F-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IClassFactory
' ########################################################################################

#IF NOT %DEF(%IClassFactory2_INTERFACE_DEFINED)
    %IClassFactory2_INTERFACE_DEFINED = 1

' // Size = 12 bytes
TYPE LICINFO DWORD
   cbLicInfo        AS DWORD   ' LONG cbLicInfo
   fRuntimeKeyAvail AS LONG    ' BOOL fRuntimeKeyAvail
   fLicVerified     AS LONG    ' BOOL fLicVerified
END TYPE

$IID_IClassFactory2 = GUID$("{B196B28F-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IClassFactory2 $IID_IClassFactory2

   INHERIT IUnknown

   ' =====================================================================================
   ' IClassFactory Methods
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown * pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void ** ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockServer ( _                                ' VTable offset = 16
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IClassFactory2 Methods
   ' =====================================================================================
   METHOD GetLicInfo ( _                                ' VTable offset = 20
     BYREF pLicInfo AS LICINFO _                        ' __in LICINFO * pLicInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestLicKey ( _                             ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pbstrKey AS WSTRING _                        ' __out BSTR * pbstrKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceLic ( _                         ' VTable offset = 28
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown * pUnkOuter
   , BYVAL pUnkReserved AS IUnknown _                   ' __in IUnknown * pUnkReserved
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL bstrKey AS WSTRING _                         ' __in BSTR bstrKey
   , BYREF ppvObject AS IUnknown _                      ' __out void ** ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClassFactory2_INTERFACE_DEFINED__ */


' ########################################################################################
' IProvideClassInfo interface
' IID = B196B283-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvideClassInfo_INTERFACE_DEFINED)
    %IProvideClassInfo_INTERFACE_DEFINED = 1

$IID_IProvideClassInfo = GUID$("{B196B283-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IProvideClassInfo $IID_IProvideClassInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassInfo ( _                              ' VTable offset = 12
     BYREF ppTI AS ITypeInfo _                          ' __out ITypeInfo **ppTI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideClassInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IProvideClassInfo2 interface
' IID = A6BC3AC0-DBAA-11CE-9DE3-00AA004BB851
' Inherited interface = IProvideClassInfo
' ########################################################################################

#IF NOT %DEF(%IProvideClassInfo2_INTERFACE_DEFINED)
    %IProvideClassInfo2_INTERFACE_DEFINED = 1

' GUIDKINF enum
%GUIDKIND_DEFAULT_SOURCE_DISP_IID = 1

$IID_IProvideClassInfo2 = GUID$("{A6BC3AC0-DBAA-11CE-9DE3-00AA004BB851}")

INTERFACE IProvideClassInfo2 $IID_IProvideClassInfo2

   INHERIT IUnknown

   ' =====================================================================================
   ' IProvideClassInfo Methods
   ' =====================================================================================
   METHOD GetClassInfo ( _                              ' VTable offset = 12
     BYREF ppTI AS ITypeInfo _                          ' __out ITypeInfo **ppTI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IProvideClassInfo2 Methods
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 16
     BYVAL dwGuidKind AS DWORD _                        ' __in DWORD dwGuidKind
   , BYREF pGUID AS GUID _                              ' __out GUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideClassInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' IProvideMultipleClassInfo interface
' IID = A7ABA9C1-8983-11cf-8F20-00805F2CD064
' Inherited interface = IProvideClassInfo2
' ########################################################################################

#IF NOT %DEF(%IProvideMultipleClassInfo_INTERFACE_DEFINED)
    %IProvideMultipleClassInfo_INTERFACE_DEFINED = 1

%MULTICLASSINFO_GETTYPEINFO           = &H00000001???
%MULTICLASSINFO_GETNUMRESERVEDDISPIDS = &H00000002???
%MULTICLASSINFO_GETIIDPRIMARY         = &H00000004???
%MULTICLASSINFO_GETIIDSOURCE          = &H00000008???
%TIFLAGS_EXTENDDISPATCHONLY           = &H00000001???

$IID_IProvideMultipleClassInfo = GUID$("{A7ABA9C1-8983-11CF-8F20-00805F2CD064}")

INTERFACE IProvideMultipleClassInfo $IID_IProvideMultipleClassInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IProvideClassInfo Methods
   ' =====================================================================================
   METHOD GetClassInfo ( _                              ' VTable offset = 12
     BYREF ppTI AS ITypeInfo _                          ' __out ITypeInfo **ppTI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IProvideClassInfo2 Methods
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 16
     BYVAL dwGuidKind AS DWORD _                        ' __in DWORD dwGuidKind
   , BYREF pGUID AS GUID _                              ' __out GUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IProvideMultipleClassInfo Methods
   ' =====================================================================================
   METHOD GetMultiTypeInfoCount ( _                     ' VTable offset = 20
     BYREF pcti AS DWORD _                              ' __out ULONG *pcti
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfoOfIndex ( _                            ' VTable offset = 24
     BYVAL iti AS DWORD _                               ' __in ULONG iti
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pptiCoClass AS ITypeInfo _                   ' __out ITypeInfo **pptiCoClass
   , BYREF pdwTIFlags AS DWORD _                        ' __out DWORD *pdwTIFlags
   , BYREF pcdispidReserved AS DWORD _                  ' __out ULONG *pcdispidReserved
   , BYREF piidPrimary AS GUID _                        ' __out IID *piidPrimary
   , BYREF piidSource AS GUID _                         ' __out IID *piidSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideMultipleClassInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleControl interface
' IID = B196B288-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleControl_INTERFACE_DEFINED)
    %IOleControl_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE CONTROLINFO DWORD   ' // Must be DWORD aligned
   cb      AS DWORD      ' ULONG cb
   hAccel  AS DWORD      ' HACCEL hAccel
   cAccel  AS WORD       ' USHORT cAccel
   dwFlags AS DWORD      ' DWORD dwFlags
END TYPE

' CTRLINFO enum
%CTRLINFO_EATS_RETURN = 1
%CTRLINFO_EATS_ESCAPE = 2

$IID_IOleControl = GUID$("{B196B288-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IOleControl $IID_IOleControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetControlInfo ( _                            ' VTable offset = 12
     BYREF pCI AS CONTROLINFO _                         ' __out CONTROLINFO *pCI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMnemonic ( _                                ' VTable offset = 16
     BYREF pMsg AS tagMSG _                             ' __in MSG *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAmbientPropertyChange ( _                   ' VTable offset = 20
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreezeEvents ( _                              ' VTable offset = 24
     BYVAL bFreeze AS LONG _                            ' __in BOOL bFreeze
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleControlSite interface
' IID = B196B289-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleControlSite_INTERFACE_DEFINED)
    %IOleControlSite_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE POINTF DWORD
   x AS SINGLE   ' FLOAT x
   y AS SINGLE   ' FLOAT y
END TYPE

' XFORMCOORDS enum
%XFORMCOORDS_POSITION            = &H1???
%XFORMCOORDS_SIZE                = &H2???
%XFORMCOORDS_HIMETRICTOCONTAINER = &H4???
%XFORMCOORDS_CONTAINERTOHIMETRIC = &H8???
%XFORMCOORDS_EVENTCOMPAT         = &H10???

' KEYMODIFIERS enum
' The KEYMODIFIERS enumeration values are flags used in calls to
' IOleControlSite::TranslateAccelerator to describe additional keyboard states that can
' modify the meaning of the keyboard messages that are also passed into
' IOleControlSite.TranslateAccelerator.
%KEYMOD_SHIFT   = &H00000001???
%KEYMOD_CONTROL = &H00000002???
%KEYMOD_ALT     = &H00000004???


$IID_IOleControlSite = GUID$("{B196B289-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IOleControlSite $IID_IOleControlSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnControlInfoChanged ( _                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockInPlaceActive ( _                         ' VTable offset = 16
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedControl ( _                        ' VTable offset = 20
     BYREF ppDisp AS IDispatch _                        ' __out IDispatch **ppDisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransformCoords ( _                           ' VTable offset = 24
     BYREF pPtlHimetric AS POINTL _                     ' __in_out POINTL *pPtlHimetric
   , BYREF pPtfContainer AS POINTF _                    ' __in_out POINTF *pPtfContainer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 28
     BYREF pMsg AS tagMSG _                             ' __in MSG *pMsg
   , BYVAL grfModifiers AS DWORD _                      ' __in DWORD grfModifiers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFocus ( _                                   ' VTable offset = 32
     BYVAL fGotFocus AS LONG _                          ' __in BOOL fGotFocus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowPropertyFrame ( _                         ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleControlSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertyPage interface
' IID = B196B28D-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyPage_INTERFACE_DEFINED)
    %IPropertyPage_INTERFACE_DEFINED = 1

' // Size = 28 bytes
TYPE PROPPAGEINFO DWORD
   cb            AS DWORD          ' ULONG cb
   pszTitle      AS WSTRINGZ PTR   ' LPOLESTR pszTitle
   nsize         AS SIZEL          ' SIZE size
   pszDocString  AS WSTRINGZ PTR   ' LPOLESTR pszDocString
   pszHelpFile   AS WSTRINGZ PTR   ' LPOLESTR pszHelpFile
   dwHelpContext AS DWORD          ' DWORD dwHelpContext
END TYPE

$IID_IPropertyPage = GUID$("{B196B28D-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IPropertyPage $IID_IPropertyPage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPageSite ( _                               ' VTable offset = 12
     BYVAL pPageSite AS IPropertyPageSite _             ' __in IPropertyPageSite *pPageSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 16
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYREF pRect AS RECT _                              ' __in LPCRECT pRect
   , BYVAL bModal AS LONG _                             ' __in BOOL bModal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageInfo ( _                               ' VTable offset = 24
     BYREF pPageInfo AS PROPPAGEINFO _                  ' __out PROPPAGEINFO *pPageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObjects ( _                                ' VTable offset = 28
     BYVAL cObjects AS DWORD _                          ' __in ULONG cObjects
   , BYREF ppUnk AS IUnknown _                          ' __in IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 32
     BYVAL nCmdShow AS DWORD _                          ' __in UINT nCmdShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 36
     BYREF pRect AS RECT _                              ' __in LPCRECT pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPageDirty ( _                               ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Apply ( _                                     ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Help ( _                                      ' VTable offset = 48
     BYREF pszHelpDir AS WSTRINGZ _                     ' __in LPCOLESTR pszHelpDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 52
     BYREF pMsg AS tagMSG _                             ' __in MSG *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyPage_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertyPage2 interface
' IID = 01E44665-24AC-101B-84ED-08002B2EC713
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyPage2_INTERFACE_DEFINED)
    %IPropertyPage2_INTERFACE_DEFINED = 1

$IID_IPropertyPage2 = GUID$("{01E44665-24AC-101B-84ED-08002B2EC713}")

INTERFACE IPropertyPage2 $IID_IPropertyPage2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPageSite ( _                               ' VTable offset = 12
     BYVAL pPageSite AS IPropertyPageSite _             ' __in IPropertyPageSite *pPageSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 16
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYREF pRect AS RECT _                              ' __in LPCRECT pRect
   , BYVAL bModal AS LONG _                             ' __in BOOL bModal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageInfo ( _                               ' VTable offset = 24
     BYREF pPageInfo AS PROPPAGEINFO _                  ' __out PROPPAGEINFO *pPageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObjects ( _                                ' VTable offset = 28
     BYVAL cObjects AS DWORD _                          ' __in ULONG cObjects
   , BYREF ppUnk AS IUnknown _                          ' __in IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 32
     BYVAL nCmdShow AS DWORD _                          ' __in UINT nCmdShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 36
     BYREF pRect AS RECT _                              ' __in LPCRECT pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPageDirty ( _                               ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Apply ( _                                     ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Help ( _                                      ' VTable offset = 48
     BYREF pszHelpDir AS WSTRINGZ _                     ' __in LPCOLESTR pszHelpDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 52
     BYREF pMsg AS tagMSG _                             ' __in MSG *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EditProperty ( _                              ' VTable offset = 56
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyPage2_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertyPageSite interface
' IID = B196B28C-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#if not %DEF(%IPropertyPageSite_INTERFACE_DEFINED)
    %IPropertyPageSite_INTERFACE_DEFINED = 1

' PROPPAGESTATUS enum
%PROPPAGESTATUS_DIRTY    = &H1
%PROPPAGESTATUS_VALIDATE = &H2
%PROPPAGESTATUS_CLEAN    = &H4

$IID_IPropertyPageSite = GUID$("{B196B28C-BAB4-101A-B69C-00AA00341D07}")

INTERFACE IPropertyPageSite $IID_IPropertyPageSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStatusChange ( _                            ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocaleID ( _                               ' VTable offset = 16
     BYREF pLocaleID AS DWORD _                         ' __out LCID *pLocaleID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageContainer ( _                          ' VTable offset = 20
     BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 24
     BYREF pMsg AS tagMSG _                             ' __in MSG *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyPageSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertyNotifySink interface
' IID = 9BFBBC02-EFF1-101A-84ED-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyNotifySink_INTERFACE_DEFINED)
    %IPropertyNotifySink_INTERFACE_DEFINED = 1

$IID_IPropertyNotifySink = GUID$("{9BFBBC02-EFF1-101A-84ED-00AA00341D07}")

INTERFACE IPropertyNotifySink $IID_IPropertyNotifySink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnChanged ( _                                 ' VTable offset = 12
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRequestEdit ( _                             ' VTable offset = 16
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyNotifySink_INTERFACE_DEFINED__ */


' ########################################################################################
' ISpecifyPropertyPages interface
' IID = B196B28B-BAB4-101A-B69C-00AA00341D07
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpecifyPropertyPages_INTERFACE_DEFINED)
    %ISpecifyPropertyPages_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE CAUUID DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS GUID PTR   ' /* [size_is] */ GUID *pElems
END TYPE

$IID_ISpecifyPropertyPages = GUID$("{B196B28B-BAB4-101A-B69C-00AA00341D07}")

INTERFACE ISpecifyPropertyPages $IID_ISpecifyPropertyPages

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPages ( _                                  ' VTable offset = 12
     BYREF pPages AS CAUUID _                           ' __out CAUUID *pPages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpecifyPropertyPages_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistMemory interface
' IID = BD1AE5E0-A6AE-11CE-BD37-504200C10000
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistMemory_INTERFACE_DEFINED)
    %IPersistMemory_INTERFACE_DEFINED = 1

$IID_IPersistMemory = GUID$("{BD1AE5E0-A6AE-11CE-BD37-504200C10000}")

INTERFACE IPersistMemory $IID_IPersistMemory

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
      BYREF pClassID AS GUID _                          ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersist2 Methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pMem AS DWORD _                              ' __in LPVOID pMem
   , BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pMem AS DWORD _                              ' __out LPVOID pMem
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   , BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pCbSize AS DWORD _                           ' __out ULONG *pCbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistMemory_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistStreamInit interface
' IID = 7FD52380-4E07-101B-AE2D-08002B2EC713
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistStreamInit_INTERFACE_DEFINED)
    %IPersistStreamInit_INTERFACE_DEFINED = 1

$IID_IPersistStreamInit = GUID$("{7FD52380-4E07-101B-AE2D-08002B2EC713}")

INTERFACE IPersistStreamInit $IID_IPersistStreamInit

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
      BYREF pClassID AS GUID _                          ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit Methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistStreamInit_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistPropertyBag interface
' IID = 37D84F60-42CB-11CE-8135-00AA004BB851
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistPropertyBag_INTERFACE_DEFINED)
    %IPersistPropertyBag_INTERFACE_DEFINED = 1

$IID_IPersistPropertyBag = GUID$("{37D84F60-42CB-11CE-8135-00AA004BB851}")

INTERFACE IPersistPropertyBag $IID_IPersistPropertyBag

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
      BYREF pClassID AS GUID _                          ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistPropertyBag Methods
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pPropBag AS IPropertyBag _                   ' __in IPropertyBag *pPropBag
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pPropBag AS IPropertyBag _                   ' __in IPropertyBag *pPropBag
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   , BYVAL fSaveAllProperties AS LONG _                 ' __in BOOL fSaveAllProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistPropertyBag_INTERFACE_DEFINED__ */


' ########################################################################################
' ISimpleFrameSite interface
' IID = 742B0E01-14E6-101B-914E-00AA00300CAB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISimpleFrameSite_INTERFACE_DEFINED)
    %ISimpleFrameSite_INTERFACE_DEFINED = 1

$IID_ISimpleFrameSite = GUID$("{742B0E01-14E6-101B-914E-00AA00300CAB}")

INTERFACE ISimpleFrameSite $IID_ISimpleFrameSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PreMessageFilter ( _                          ' VTable offset = 12
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wp AS DWORD _                                ' __in WPARAM wp
   , BYVAL lp AS LONG _                                 ' __in LPARAM lp
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostMessageFilter ( _                         ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wp AS DWORD _                                ' __in WPARAM wp
   , BYVAL lp AS LONG _                                 ' __in LPARAM lp
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   , BYVAL pdwCookie AS DWORD _                         ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISimpleFrameSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IFont interface
' IID = BEF6E002-A874-101A-8BBA-00AA00300CAB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFont_INTERFACE_DEFINED)
    %IFont_INTERFACE_DEFINED = 1

$IID_IFont = GUID$("{BEF6E002-A874-101A-8BBA-00AA00300CAB}")

INTERFACE IFont $IID_IFont

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Name ( _                                  ' VTable offset = 12
     BYREF pname AS WSTRING _                           ' __out BSTR* pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Name ( _                                  ' VTable offset = 16
     BYVAL pname AS WSTRING _                           ' __in BSTR pname
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Size ( _                                  ' VTable offset = 20
     BYREF psize AS CUR _                               ' __out CY* psize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Size ( _                                  ' VTable offset = 24
     BYVAL psize AS CUR _                               ' __in CY psize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Bold ( _                                  ' VTable offset = 28
     BYREF pbold AS LONG _                              ' __out BOOL* pbold
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Bold ( _                                  ' VTable offset = 32
     BYVAL pbold AS LONG _                              ' __in BOOL pbold
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Italic ( _                                ' VTable offset = 36
     BYREF pitalic AS LONG _                            ' __out BOOL* pitalic
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Italic ( _                                ' VTable offset = 40
     BYVAL pitalic AS LONG _                            ' __in BOOL pitalic
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Underline ( _                             ' VTable offset = 44
     BYREF punderline AS LONG _                         ' __out BOOL* punderline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Underline ( _                             ' VTable offset = 48
     BYVAL punderline AS LONG _                         ' __in BOOL punderline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Strikethrough ( _                         ' VTable offset = 52
     BYREF pstrikethrough AS LONG _                     ' __out BOOL* pstrikethrough
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Strikethrough ( _                         ' VTable offset = 56
     BYVAL pstrikethrough AS LONG _                     ' __in BOOL pstrikethrough
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Weight ( _                                ' VTable offset = 60
     BYREF weight AS INTEGER _                          ' __out short* weight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Weight ( _                                ' VTable offset = 64
     BYVAL weight AS INTEGER _                          ' __in short weight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Charset ( _                               ' VTable offset = 68
     BYREF pcharset AS INTEGER _                        ' __out short* pcharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Charset ( _                               ' VTable offset = 72
     BYVAL pcharset AS INTEGER _                        ' __in short pcharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_hFont ( _                                 ' VTable offset = 76
     BYREF phfont AS DWORD _                            ' __out HFONT* phfont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 80
     BYREF phfont AS IFont _                            ' __out IFont** ppfont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 84
     BYVAL pFontOther AS IFont _                        ' __in IFont* pFontOther
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRatio ( _                                  ' VTable offset = 88
     BYVAL cyLogical AS LONG _                          ' __in long cyLogical
   , BYVAL cyLogical AS LONG _                          ' __in long cyHimetric
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryTextMetrics ( _                          ' VTable offset = 92
     BYREF ptm AS TEXTMETRIC _                          ' __in TEXTMETRICOLE* ptm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRefHfont ( _                               ' VTable offset = 96
     BYVAL hfont AS DWORD _                             ' __in HFONT hfont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseHfont ( _                              ' VTable offset = 100
     BYVAL hfont AS DWORD _                             ' __in HFONT hfont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHdc ( _                                    ' VTable offset = 104
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFont_INTERFACE_DEFINED__ */


' ########################################################################################
' IPicture interface
' IID = 7BF80980-BF32-101A-8BBB-00AA00300CAB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPicture_INTERFACE_DEFINED)
    %IPicture_INTERFACE_DEFINED = 1

' PICTUREATTRIBUTES enum
%PICTURE_SCALABLE    = &H1
%PICTURE_TRANSPARENT = &H2

$IID_IPicture = GUID$("{7BF80980-BF32-101A-8BBB-00AA00300CAB}")

INTERFACE IPicture $IID_IPicture

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Handle ( _                                ' VTable offset = 12
     BYREF phandle AS DWORD _                           ' __out OLE_HANDLE* phandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_hPal ( _                                  ' VTable offset = 16
     BYREF phpal AS DWORD _                             ' __out OLE_HANDLE* phpal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Type ( _                                  ' VTable offset = 20
     BYREF ptype AS INTEGER _                           ' __out short* ptype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Width ( _                                 ' VTable offset = 24
     BYREF pwidth AS LONG _                             ' __out OLE_XSIZE_HIMETRIC* pwidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Height ( _                                ' VTable offset = 28
     BYREF pheight AS LONG _                            ' __out OLE_YSIZE_HIMETRIC* pheight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 32
     BYVAL hdc AS LONG _                                ' __in HDC hdc
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   , BYVAL cx AS LONG _                                 ' __in long cx
   , BYVAL cy AS LONG _                                 ' __in long cy
   , BYVAL xSrc AS LONG _                               ' __in OLE_XPOS_HIMETRIC xSrc
   , BYVAL ySrc AS LONG _                               ' __in OLE_YPOS_HIMETRIC ySrc
   , BYVAL cxSrc AS LONG _                              ' __in OLE_XSIZE_HIMETRIC cxSrc
   , BYVAL cySrc AS LONG _                              ' __in OLE_YSIZE_HIMETRIC cySrc
   , BYREF prcWBounds AS RECT _                         ' __in LPCRECT prcWBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD set_hPal ( _                                  ' VTable offset = 36
     BYVAL hpal AS DWORD _                              ' __in OLE_HANDLE hpal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CurDC ( _                                 ' VTable offset = 40
     BYREF phdcOut AS DWORD _                           ' __out HDC* phdcOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectPicture ( _                             ' VTable offset = 44
     BYVAL hdcIn AS DWORD _                             ' __in HDC hdcIn
   , BYREF phdcOut AS DWORD _                           ' __in HDC* phdcOut
   , BYREF phbmpOut AS DWORD _                          ' __in OLE_HANDLE* phbmpOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_KeepOriginalFormat ( _                    ' VTable offset = 48
     BYREF pfkeep AS LONG _                             ' __in BOOL* pfkeep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_KeepOriginalFormat ( _                    ' VTable offset = 52
     BYVAL pfkeep AS LONG _                             ' __in BOOL pfkeep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PictureChanged ( _                            ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveAsFile ( _                                ' VTable offset = 60
     BYVAL pstream AS IStream _                         ' __in IStream * pstream
   , BYVAL fSaveMemCopy AS LONG _                       ' __in BOOL fSaveMemCopy
   , BYREF pcbSize AS LONG _                            ' __out LONG* pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Attributes ( _                            ' VTable offset = 64
     BYREF pdwAttr AS DWORD _                           ' __out DWORD* pdwAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPicture_INTERFACE_DEFINED__ */


' ########################################################################################
' IPicture2 interface
' IID = F5185DD8-2012-4B0B-AAD9-F052C6BD482B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPicture2_INTERFACE_DEFINED)
    %IPicture_INTERFACE_DEFINED = 1

$IID_IPicture2 = GUID$("{F5185DD8-2012-4B0B-AAD9-F052C6BD482B}")

INTERFACE IPicture2 $IID_IPicture2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Handle ( _                                ' VTable offset = 12
     BYREF phandle AS DWORD _                           ' __out HHANDLE* phandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_hPal ( _                                  ' VTable offset = 16
     BYREF phpal AS DWORD _                             ' __out HHANDLE* phpal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Type ( _                                  ' VTable offset = 20
     BYREF ptype AS INTEGER _                           ' __out short* ptype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Width ( _                                 ' VTable offset = 24
     BYREF pwidth AS LONG _                             ' __out OLE_XSIZE_HIMETRIC* pwidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Height ( _                                ' VTable offset = 28
     BYREF pheight AS LONG _                            ' __out OLE_YSIZE_HIMETRIC* pheight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 32
     BYVAL hdc AS LONG _                                ' __in HDC hdc
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   , BYVAL cx AS LONG _                                 ' __in long cx
   , BYVAL cy AS LONG _                                 ' __in long cy
   , BYVAL xSrc AS LONG _                               ' __in OLE_XPOS_HIMETRIC xSrc
   , BYVAL ySrc AS LONG _                               ' __in OLE_YPOS_HIMETRIC ySrc
   , BYVAL cxSrc AS LONG _                              ' __in OLE_XSIZE_HIMETRIC cxSrc
   , BYVAL cySrc AS LONG _                              ' __in OLE_YSIZE_HIMETRIC cySrc
   , BYREF prcWBounds AS RECT _                         ' __in LPCRECT prcWBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD set_hPal ( _                                  ' VTable offset = 36
     BYVAL hpal AS DWORD _                              ' __in HHANDLE hpal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CurDC ( _                                 ' VTable offset = 40
     BYREF phdcOut AS DWORD _                           ' __out HDC* phdcOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectPicture ( _                             ' VTable offset = 44
     BYVAL hdcIn AS DWORD _                             ' __in HDC hdcIn
   , BYREF phdcOut AS DWORD _                           ' __in HDC* phdcOut
   , BYREF phbmpOut AS DWORD _                          ' __in HHANDLE* phbmpOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_KeepOriginalFormat ( _                    ' VTable offset = 48
     BYREF pfkeep AS LONG _                             ' __in BOOL* pfkeep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_KeepOriginalFormat ( _                    ' VTable offset = 52
     BYVAL pfkeep AS LONG _                             ' __in BOOL pfkeep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PictureChanged ( _                            ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveAsFile ( _                                ' VTable offset = 60
     BYVAL pstream AS IStream _                         ' __in IStream * pstream
   , BYVAL fSaveMemCopy AS LONG _                       ' __in BOOL fSaveMemCopy
   , BYREF pcbSize AS LONG _                            ' __out LONG* pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Attributes ( _                            ' VTable offset = 64
     BYREF pdwAttr AS DWORD _                           ' __out DWORD* pdwAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPicture2_INTERFACE_DEFINED__ */

' ########################################################################################
' IFontEventsDisp interface
' IID = 4EF6100A-AF88-11D0-9846-00C04FC29993
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFontEventsDisp_INTERFACE_DEFINED)
    %IFontEventsDisp_INTERFACE_DEFINED = 1

$IID_IFontEventsDisp = GUID$("{4EF6100A-AF88-11D0-9846-00C04FC29993}")

INTERFACE IFontEventsDisp $IID_IFontEventsDisp

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IFontEventsDisp_INTERFACE_DEFINED__ */


' ########################################################################################
' IFontDisp interface
' IID = BEF6E003-A874-101A-8BBA-00AA00300CAB
' Inherited interface = IDispatch
' Note: This interface is a wrapper on top of the IFont interface. You can use it
' calling the Invoke method or casting it to an object variable declared as StdFont.
' The definition for the StdFont interface is included in olectl.inc.
' ########################################################################################

#IF NOT %DEF(%IFontDisp_INTERFACE_DEFINED)
    %IFontDisp_INTERFACE_DEFINED = 1

$IID_IFontDisp = GUID$("{BEF6E003-A874-101A-8BBA-00AA00300CAB}")

INTERFACE IFontDisp $IID_IFontDisp

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IFontDisp_INTERFACE_DEFINED__ */


' ########################################################################################
' IPictureDisp interface
' IID = 7BF80981-BF32-101A-8BBB-00AA00300CAB
' Inherited interface = IDispatch
' Note: This interface is a wrapper on top of the IPicture interface. You can use it
' calling the Invoke method or casting it to an object variable declared as StdPicture.
' The definition for the StdPicture interface is included in olectl.inc.
' ########################################################################################

#IF NOT %DEF(%IPictureDisp_INTERFACE_DEFINED)
    %IPictureDisp_INTERFACE_DEFINED = 1

$IID_IPictureDisp = GUID$("{7BF80981-BF32-101A-8BBB-00AA00300CAB}")

INTERFACE IPictureDisp $IID_IPictureDisp

   INHERIT IDispatch

END INTERFACE

#ENDIF              ' /* __IPictureDisp_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceObjectWindowless interface
' IID = 1C2056CC-5EF4-101B-8BC8-00AA003E3B29
' Inherited interface = IOleInPlaceObject
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceObjectWindowless_INTERFACE_DEFINED)
    %IOleInPlaceObjectWindowless_INTERFACE_DEFINED = 1

$IID_IOleInPlaceObjectWindowless = GUID$("{1C2056CC-5EF4-101B-8BC8-00AA003E3B29}")

INTERFACE IOleInPlaceObjectWindowless $IID_IOleInPlaceObjectWindowless

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleWindow Methods
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceObject Methods
   ' =====================================================================================
   METHOD InPlaceDeactivate ( _                         ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UIDeactivate ( _                              ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObjectRects ( _                            ' VTable offset = 28
     BYREF lprcPosRect AS RECT _                        ' __in LPCRECT lprcPosRect
   , BYREF lprcClipRect AS RECT _                       ' __in LPCRECT lprcClipRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReactivateAndUndo ( _                         ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceObjectWindowless methods
   ' =====================================================================================
   METHOD OnWindowMessage ( _                           ' VTable offset = 36
     BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDropTarget ( _                             ' VTable offset = 40
     BYREF ppDropTarget AS IDropTarget _                ' __out IDropTarget **ppDropTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceSiteEx interface
' IID = 9C2CAD80-3424-11CF-B670-00AA004CD6D8
' Inherited interface = IOleInPlaceSite
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceSiteEx_INTERFACE_DEFINED)
    %IOleInPlaceSiteEx_INTERFACE_DEFINED = 1

' ACTIVATEFLAGS enum
%ACTIVATE_WINDOWLESS = 1

$IID_IOleInPlaceSiteEx = GUID$("{9C2CAD80-3424-11CF-B670-00AA004CD6D8}")

INTERFACE IOleInPlaceSiteEx $IID_IOleInPlaceSiteEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleWindow Methods
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceSite Methods
   ' =====================================================================================
   METHOD CanInPlaceActivate ( _                        ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInPlaceActivate ( _                         ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUIActivate ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindowContext ( _                          ' VTable offset = 32
     BYREF ppFrame AS IOleInPlaceFrame _                ' __out IOleInPlaceFrame **ppFrame
   , BYREF ppDoc AS IOleInPlaceUIWindow _               ' __out IOleInPlaceUIWindow **ppDoc
   , BYREF lprcPosRect AS RECT _                        ' __out LPRECT lprcPosRect
   , BYREF lprcClipRect AS RECT _                       ' __out LPRECT lprcClipRect
   , BYREF lpFrameInfo AS OLEINPLACEFRAMEINFO _         ' __in_out LPOLEINPLACEFRAMEINFO lpFrameInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Scroll ( _                                    ' VTable offset = 36
     BYREF scrollExtant AS SIZE _                       ' __in SIZE scrollExtant
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUIDeactivate ( _                            ' VTable offset = 40
     BYVAL fUndoable AS LONG _                          ' __in BOOL fUndoable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInPlaceDeactivate ( _                       ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardUndoState ( _                          ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeactivateAndUndo ( _                         ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPosRectChange ( _                           ' VTable offset = 56
     BYREF lprcPosRect AS RECT _                        ' __in LPCRECT lprcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceSiteEx Methods
   ' =====================================================================================
   METHOD OnInPlaceActivateEx ( _                       ' VTable offset = 60
     BYREF pfNoRedraw AS LONG _                         ' __out BOOL *pfNoRedraw
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInPlaceDeactivateEx ( _                     ' VTable offset = 64
     BYVAL fNoRedraw AS LONG _                          ' __in BOOL fNoRedraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestUIActivate ( _                         ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleInPlaceSiteEx_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceSiteWindowless interface
' IID = 922EADA0-3424-11CF-B670-00AA004CD6D8
' Inherited interface = IOleInPlaceSiteEx
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceSiteWindowless_INTERFACE_DEFINED)
    %IOleInPlaceSiteWindowless_INTERFACE_DEFINED = 1

' OLEDCFLAGS enum
%OLEDC_NODRAW     = &H1
%OLEDC_PAINTBKGND = &H2
%OLEDC_OFFSCREEN  = &H4

$IID_IOleInPlaceSiteWindowless = GUID$("{922EADA0-3424-11CF-B670-00AA004CD6D8}")

INTERFACE IOleInPlaceSiteWindowless $IID_IOleInPlaceSiteWindowless

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleWindow Methods
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceSite Methods
   ' =====================================================================================
   METHOD CanInPlaceActivate ( _                        ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInPlaceActivate ( _                         ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUIActivate ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindowContext ( _                          ' VTable offset = 32
     BYREF ppFrame AS IOleInPlaceFrame _                ' __out IOleInPlaceFrame **ppFrame
   , BYREF ppDoc AS IOleInPlaceUIWindow _               ' __out IOleInPlaceUIWindow **ppDoc
   , BYREF lprcPosRect AS RECT _                        ' __out LPRECT lprcPosRect
   , BYREF lprcClipRect AS RECT _                       ' __out LPRECT lprcClipRect
   , BYREF lpFrameInfo AS OLEINPLACEFRAMEINFO _         ' __in_out LPOLEINPLACEFRAMEINFO lpFrameInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Scroll ( _                                    ' VTable offset = 36
     BYREF scrollExtant AS SIZE _                       ' __in SIZE scrollExtant
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUIDeactivate ( _                            ' VTable offset = 40
     BYVAL fUndoable AS LONG _                          ' __in BOOL fUndoable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInPlaceDeactivate ( _                       ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardUndoState ( _                          ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeactivateAndUndo ( _                         ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPosRectChange ( _                           ' VTable offset = 56
     BYREF lprcPosRect AS RECT _                        ' __in LPCRECT lprcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceSiteEx Methods
   ' =====================================================================================
   METHOD OnInPlaceActivateEx ( _                       ' VTable offset = 60
     BYREF pfNoRedraw AS LONG _                         ' __out BOOL *pfNoRedraw
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInPlaceDeactivateEx ( _                     ' VTable offset = 64
     BYVAL fNoRedraw AS LONG _                          ' __in BOOL fNoRedraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestUIActivate ( _                         ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceSiteWindowless Methods
   ' =====================================================================================
   METHOD CanWindowlessActivate ( _                     ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapture ( _                                ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCapture ( _                                ' VTable offset = 80
     BYVAL fCapture AS LONG _                           ' __in BOOL fCapture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFocus ( _                                  ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFocus ( _                                  ' VTable offset = 88
     BYVAL fFocus AS LONG _                             ' __in BOOL fFocus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 92
     BYREF pRect AS RECT _                              ' __in LPCRECT pRect
   , BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYREF phDC AS DWORD _                              ' __out HDC *phDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 96
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvalidateRect ( _                            ' VTable offset = 100
     BYREF pRect AS RECT _                              ' __in LPCRECT pRect
   , BYVAL fErase AS LONG _                             ' __in BOOL fErase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvalidateRgn ( _                             ' VTable offset = 104
     BYVAL hRGN AS DWORD _                              ' __in HRGN hRGN
   , BYVAL fErase AS LONG _                             ' __in BOOL fErase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScrollRect ( _                                ' VTable offset = 108
     BYVAL dx AS LONG _                                 ' __in INT dx
   , BYVAL dy AS LONG _                                 ' __in INT dy
   , BYREF pRectScroll AS RECT _                        ' __in LPCRECT pRectScroll
   , BYREF pRectClip AS RECT _                          ' __in LPCRECT pRectClip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdjustRect ( _                                ' VTable offset = 112
     BYREF prc AS RECT _                                ' __in_out LPRECT prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDefWindowMessage ( _                        ' VTable offset = 114
     BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewObjectEx interface
' IID = 3AF24292-0C96-11CE-A0CF-00AA00600AB8
' Inherited interface = IViewObject2
' ########################################################################################

#IF NOT %DEF(%IViewObjectEx_INTERFACE_DEFINED)
    %IViewObjectEx_INTERFACE_DEFINED = 1

' VIEWSTATUS enum
%VIEWSTATUS_OPAQUE              = 1
%VIEWSTATUS_SOLIDBKGND          = 2
%VIEWSTATUS_DVASPECTOPAQUE      = 4
%VIEWSTATUS_DVASPECTTRANSPARENT = 8
%VIEWSTATUS_SURFACE             = 16
%VIEWSTATUS_3DSURFACE           = 32

' HITRESULT enum
%HITRESULT_OUTSIDE     = 0
%HITRESULT_TRANSPARENT = 1
%HITRESULT_CLOSE       = 2
%HITRESULT_HIT         = 3

' DVASPECT2 enum
%DVASPECT_OPAQUE      = 16
%DVASPECT_TRANSPARENT = 32

' // Size = 16 bytes
TYPE DVEXTENTINFO DWORD
   cb            AS DWORD   ' ULONG cb
   dwExtentMode  AS DWORD   ' DWORD dwExtentMode
   sizelProposed AS SIZEL   ' SIZEL sizelProposed
END TYPE

' DVEXTENTMODE enum
%DVEXTENT_CONTENT  = 0
%DVEXTENT_INTEGRAL = 1

' DVASPECTINFOFLAG enum
%DVASPECTINFOFLAG_CANOPTIMIZE = 1

' // Size = 8 bytes
TYPE DVASPECTINFO DWORD
   cb      AS DWORD   ' ULONG cb
   dwFlags AS DWORD   ' DWORD dwFlags
END TYPE

$IID_IViewObjectEx = GUID$("{3AF24292-0C96-11CE-A0CF-00AA00600AB8}")

INTERFACE IViewObjectEx $IID_IViewObjectEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IViewObject Methods
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 12
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   , BYVAL pvAspect AS DWORD _                          ' __in void *pvAspect
   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE *ptd
   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
   , BYVAL DhdcDraw AS WORD _                           ' __in HDC hdcDraw
   , BYREF lprcBounds AS RECTL _                        ' __in LPCRECTL lprcBounds
   , BYREF lprcWBounds AS RECTL _                       ' __in LPCRECTL lprcWBounds
   , BYVAL pfnContinue AS DWORD _                       ' __in BOOL ( STDMETHODCALLTYPE *pfnContinue )(ULONG_PTR dwContinue)
   , BYVAL dwContinue AS DWORD _                        ' __in ULONG_PTR dwContinue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorSet ( _                               ' VTable offset = 16
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   , BYVAL pvAspect AS DWORD _                          ' __in void *pvAspect
   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE *ptd
   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
   , BYREF ppColorSet AS LOGPALETTE _                   ' __out LOGPALETTE **ppColorSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Freeze ( _                                    ' VTable offset = 20
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   , BYVAL pvAspect AS DWORD _                          ' __in void *pvAspect
   , BYREF pdwFreeze AS DWORD _                         ' __out DWORD *pdwFreeze
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unfreeze ( _                                  ' VTable offset = 24
     BYVAL dwFreeze AS DWORD _                          ' __in DWORD dwFreeze
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdvise ( _                                 ' VTable offset = 28
     BYVAL aspect AS DWORD _                            ' __in DWORD aspect
   , BYVAL advf AS DWORD _                              ' __in DWORD advf
   , BYVAL pAdvSink AS IAdviseSink _                    ' __in IAdviseSink *pAdvSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdvise ( _                                 ' VTable offset = 32
     BYREF pAspects AS DWORD _                          ' __out DWORD *pAspects
   , BYREF pAdvf AS DWORD _                             ' __out DWORD *pAdvf
   , BYREF ppAdvSink AS IAdviseSink _                   ' __out IAdviseSink **ppAdvSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IViewObjectEx Methods
   ' =====================================================================================
   METHOD GetExtent ( _                                 ' VTable offset = 36
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE *ptd
   , BYREF lpsizel AS SIZEL _                           ' __out LPSIZEL lpsizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRect ( _                                   ' VTable offset = 40
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYREF pRect AS RECTL _                             ' __out LPRECTL pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewStatus ( _                             ' VTable offset = 44
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryHitPoint ( _                             ' VTable offset = 48
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYREF pRectBounds AS RECT _                        ' __in LPCRECT pRectBounds
   , BYREF ptlLoc AS POINT _                            ' __in POINT ptlLoc
   , BYVAL lCloseHint AS LONG _                         ' __in LONG lCloseHint
   , BYREF pHitResult AS DWORD _                        ' __out DWORD *pHitResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryHitRect ( _                              ' VTable offset = 52
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYREF pRectBounds AS RECT _                        ' __in LPCRECT pRectBounds
   , BYREF pRectLoc AS RECT _                           ' __in LPCRECT pRectLoc
   , BYVAL lCloseHint AS LONG _                         ' __in LONG lCloseHint
   , BYREF pHitResult AS DWORD _                        ' __out DWORD *pHitResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNaturalExtent ( _                          ' VTable offset = 56
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYVAL ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE *ptd
   , BYREF pRectBounds AS RECT _                        ' __in LPCRECT pRectBounds
   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
   , BYREF pExtentInfo AS DVEXTENTINFO _                ' __in DVEXTENTINFO *pExtentInfo
   , BYREF pSizel AS SIZEL _                            ' __out LPSIZEL pSizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IViewObjectEx_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleUndoUnit interface
' IID = 894AD3B0-EF97-11CE-9BC9-00AA00608E01
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleUndoUnit_INTERFACE_DEFINED)
    %IOleUndoUnit_INTERFACE_DEFINED = 1

$IID_IOleUndoUnit = GUID$("{894AD3B0-EF97-11CE-9BC9-00AA00608E01}")

INTERFACE IOleUndoUnit $IID_IOleUndoUnit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Do ( _                                        ' VTable offset = 12
     BYVAL pUndoManager AS IOleUndoManager _            ' __in IOleUndoManager *pUndoManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYREF pBstr AS WSTRING _                           ' __out BSTR *pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnitType ( _                               ' VTable offset = 20
     BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   , BYREF plID AS LONG _                               ' __out LONG *plID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNextAdd ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleUndoUnit_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleParentUndoUnit interface
' IID = A1FAF330-EF97-11CE-9BC9-00AA00608E01
' Inherited interface = IOleUndoUnit
' ########################################################################################

#IF NOT %DEF(%IOleParentUndoUnit_INTERFACE_DEFINED)
    %IOleParentUndoUnit_INTERFACE_DEFINED = 1

$IID_IOleParentUndoUnit = GUID$("{A1FAF330-EF97-11CE-9BC9-00AA00608E01}")

INTERFACE IOleParentUndoUnit $IID_IOleParentUndoUnit

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleUndoUnit Methods
   ' =====================================================================================
   METHOD Do ( _                                        ' VTable offset = 12
     BYVAL pUndoManager AS IOleUndoManager _            ' __in IOleUndoManager *pUndoManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYREF pBstr AS WSTRING _                           ' __out BSTR *pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnitType ( _                               ' VTable offset = 20
     BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   , BYREF plID AS LONG _                               ' __out LONG *plID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNextAdd ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleParentUndoUnit Methods
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 28
     BYVAL pPUU AS IOleParentUndoUnit _                 ' __in IOleParentUndoUnit *pPUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 32
     BYVAL pPUU AS IOleParentUndoUnit _                 ' __in IOleParentUndoUnit *pPUU
   , BYVAL fCommit AS LONG _                            ' __in BOOL fCommit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 36
     BYVAL pUU AS IOleUndoUnit _                        ' __in IOleUndoUnit *pUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindUnit ( _                                  ' VTable offset = 40
     BYVAL pUU AS IOleUndoUnit _                        ' __in IOleUndoUnit *pUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentState ( _                            ' VTable offset = 44
     BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleParentUndoUnit_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumOleUndoUnits interface
' IID = B3E7C340-EF97-11CE-9BC9-00AA00608E01
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumOleUndoUnits_INTERFACE_DEFINED)
    %IEnumOleUndoUnits_INTERFACE_DEFINED = 1

$IID_IEnumOleUndoUnits = GUID$("{B3E7C340-EF97-11CE-9BC9-00AA00608E01}")

INTERFACE IEnumOleUndoUnits $IID_IEnumOleUndoUnits

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgElt AS IOleUndoUnit _                      ' __out IOleUndoUnit **rgElt
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
     BYREF ppEnum AS IEnumOleUndoUnits _                ' __out IEnumOleUndoUnits **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumOleUndoUnits_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleUndoManager interface
' IID = D001F200-EF97-11CE-9BC9-00AA00608E01
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleUndoManager_INTERFACE_DEFINED)
    %IOleUndoManager_INTERFACE_DEFINED = 1

$IID_IOleUndoManager = GUID$("{D001F200-EF97-11CE-9BC9-00AA00608E01}")

INTERFACE IOleUndoManager $IID_IOleUndoManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
     BYVAL pPUU AS IOleParentUndoUnit _                 ' __in IOleParentUndoUnit *pPUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 16
     BYVAL pPUU AS IOleParentUndoUnit _                 ' __in IOleParentUndoUnit *pPUU
   , BYVAL fCommit AS LONG _                            ' __in BOOL fCommit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpAdd ( _                                     ' VTable offset = 20
     BYVAL pPUU AS IOleUndoUnit _                       ' __in IOleUndoUnit *pPUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpenParentState ( _                        ' VTable offset = 24
     BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardFrom ( _                               ' VTable offset = 28
     BYVAL pUU AS IOleUndoUnit _                        ' __in IOleUndoUnit *pUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UndoTo ( _                                    ' VTable offset = 32
     BYVAL pUU AS IOleUndoUnit _                        ' __in IOleUndoUnit *pUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RedoTo ( _                                    ' VTable offset = 36
     BYVAL pUU AS IOleUndoUnit _                        ' __in IOleUndoUnit *pUU
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumUndoable ( _                              ' VTable offset = 40
     BYREF ppEnum AS IEnumOleUndoUnits _                ' __out IEnumOleUndoUnits **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRedoable ( _                              ' VTable offset = 44
     BYREF ppEnum AS IEnumOleUndoUnits _                ' __out IEnumOleUndoUnits **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastUndoDescription ( _                    ' VTable offset = 48
     BYREF pBstr AS WSTRING _                           ' __out BSTR *pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastRedoDescription ( _                    ' VTable offset = 52
     BYREF pBstr AS WSTRING _                           ' __out BSTR *pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 56
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleUndoManager_INTERFACE_DEFINED__ */


' ########################################################################################
' IPointerInactive interface
' IID = 55980BA0-35AA-11CF-B671-00AA004CD6D8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPointerInactive_INTERFACE_DEFINED)
    %IPointerInactive_INTERFACE_DEFINED = 1

' POINTERINACTIVE enum
%POINTERINACTIVE_ACTIVATEONENTRY   = 1
%POINTERINACTIVE_DEACTIVATEONLEAVE = 2
%POINTERINACTIVE_ACTIVATEONDRAG    = 4

$IID_IPointerInactive = GUID$("{55980BA0-35AA-11CF-B671-00AA004CD6D8}")

INTERFACE IPointerInactive $IID_IPointerInactive

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetActivationPolicy ( _                       ' VTable offset = 12
     BYREF pdwPolicy AS DWORD _                         ' __out DWORD *pdwPolicy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInactiveMouseMove ( _                       ' VTable offset = 16
     BYREF pRectBounds AS RECT _                        ' __in LPCRECT pRectBounds
   , BYVAL x AS LONG _                                  ' __in LONG x
   , BYVAL y AS LONG _                                  ' __in LONG y
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInactiveSetCursor ( _                       ' VTable offset = 20
     BYREF pRectBounds AS RECT _                        ' __in LPCRECT pRectBounds
   , BYVAL x AS LONG _                                  ' __in LONG x
   , BYVAL y AS LONG _                                  ' __in LONG y
   , BYVAL dwMouseMsg AS DWORD _                        ' __in DWORD dwMouseMsg
   , BYVAL fSetAlways AS LONG _                         ' __in BOOL fSetAlways
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPointerInactive_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectWithSite interface
' IID = FC4801A3-2BA9-11CF-A229-00AA003D7352
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithSite_INTERFACE_DEFINED)
    %IObjectWithSite_INTERFACE_DEFINED = 1

$IID_IObjectWithSite = GUID$("{FC4801A3-2BA9-11CF-A229-00AA003D7352}")

INTERFACE IObjectWithSite $IID_IObjectWithSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSite ( _                                   ' VTable offset = 12
     BYVAL pUnkSite AS IUnknown _                       ' __in IUnknown *pUnkSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSite ( _                                   ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvSite AS IUnknown _                        ' __out void **ppvSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IPerPropertyBrowsing interface
' IID = 376BD3AA-3845-101B-84ED-08002B2EC713
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPerPropertyBrowsing_INTERFACE_DEFINED)
    %IPerPropertyBrowsing_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE CALPOLESTR DWORD
   cElems AS DWORD          ' ULONG cElems
   pElems AS WSTRINGZ PTR   ' /* [size_is] */ LPOLESTR *pElems
END TYPE

' // Size = 8 bytes
TYPE CADWORD DWORD
   cElems AS DWORD       ' ULONG cElems
   pElems AS DWORD PTR   ' /* [size_is] */ DWORD *pElems
END TYPE

$IID_IPerPropertyBrowsing = GUID$("{376BD3AA-3845-101B-84ED-08002B2EC713}")

INTERFACE IPerPropertyBrowsing $IID_IPerPropertyBrowsing

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDisplayString ( _                          ' VTable offset = 12
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   , BYREF pBstr AS WSTRING _                           ' __out BSTR *pBstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapPropertyToPage ( _                         ' VTable offset = 16
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   , BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPredefinedStrings ( _                      ' VTable offset = 20
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   , BYREF pCaStringsOut AS CALPOLESTR _                ' __out CALPOLESTR *pCaStringsOut
   , BYREF pCaCookiesOut AS CADWORD _                   ' __out CADWORD *pCaCookiesOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPredefinedValue ( _                        ' VTable offset = 24
     BYVAL dispID AS LONG _                             ' __in DISPID dispID
   , BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   , BYREF pVarOut AS VARIANT _                         ' __out VARIANT *pVarOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPerPropertyBrowsing_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertyBag2 interface
' IID = 22F55882-280B-11d0-A8A9-00A0C90C2004
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyBag2_INTERFACE_DEFINED)
    %IPropertyBag2_INTERFACE_DEFINED = 1

' PROPBAG2_TYPE enum
%PROPBAG2_TYPE_UNDEFINED = 0
%PROPBAG2_TYPE_DATA      = 1
%PROPBAG2_TYPE_URL       = 2
%PROPBAG2_TYPE_OBJECT    = 3
%PROPBAG2_TYPE_STREAM    = 4
%PROPBAG2_TYPE_STORAGE   = 5
%PROPBAG2_TYPE_MONIKER   = 6

' // Size = 32 bytes
TYPE PROPBAG2 DWORD FILL
   dwType   AS DWORD          ' DWORD dwType
   vt       AS WORD           ' VARTYPE vt
   cfType   AS WORD           ' CLIPFORMAT cfType
   dwHint   AS DWORD          ' DWORD dwHint
   pstrName AS WSTRINGZ PTR   ' LPOLESTR pstrName
   clsid    AS GUID           ' CLSID clsid
END TYPE

$IID_IPropertyBag2 = GUID$("{22F55882-280B-11D0-A8A9-00A0C90C2004}")

INTERFACE IPropertyBag2 $IID_IPropertyBag2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL cProperties AS DWORD _                       ' __in ULONG cProperties
   , BYREF pPropBag AS PROPBAG2 _                       ' __in PROPBAG2 *pPropBag
   , BYVAL pErrLog AS IErrorLog _                       ' __in IErrorLog *pErrLog
   , BYREF pvarValue AS VARIANT _                       ' __out VARIANT *pvarValue
   , BYREF phrError AS LONG _                           ' __out HRESULT *phrError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL cProperties AS DWORD _                       ' __in ULONG cProperties
   , BYREF pPropBag AS PROPBAG2 _                       ' __in PROPBAG2 *pPropBag
   , BYREF pvarValue AS VARIANT _                       ' __out VARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountProperties ( _                           ' VTable offset = 20
     BYREF pcProperties AS DWORD _                      ' __out ULONG *pcProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyInfo ( _                           ' VTable offset = 24
     BYVAL iProperty AS DWORD _                         ' __in ULONG iProperty
   , BYVAL cProperties AS DWORD _                       ' __in ULONG cProperties
   , BYREF pPropBag AS PROPBAG2 _                       ' __in PROPBAG2 *pPropBag
   , BYREF pcProperties AS DWORD _                      ' __out ULONG *pcProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadObject ( _                                ' VTable offset = 28
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   , BYVAL dwHint AS DWORD _                            ' __in DWORD dwHint
   , BYVAL pUnkObject AS IUnknown _                     ' __in IUnknown *pUnkObject
   , BYVAL pErrLog AS IErrorLog _                       ' __in IErrorLog *pErrLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyBag2_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistPropertyBag2 interface
' IID = 37D84F60-42CB-11CE-8135-00AA004BB851
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistPropertyBag2_INTERFACE_DEFINED)
    %IPersistPropertyBag2_INTERFACE_DEFINED = 1

$IID_IPersistPropertyBag2 = GUID$("{22F55881-280B-11D0-A8A9-00A0C90C2004}")

INTERFACE IPersistPropertyBag2 $IID_IPersistPropertyBag2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
      BYREF pClassID AS GUID _                          ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistPropertyBag2 Methods
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 14
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 16
     BYVAL pPropBag AS IPropertyBag _                   ' __in IPropertyBag *pPropBag
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 20
     BYVAL pPropBag AS IPropertyBag2 _                  ' __in IPropertyBag2 *pPropBag
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   , BYVAL fSaveAllProperties AS LONG _                 ' __in BOOL fSaveAllProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistPropertyBag2_INTERFACE_DEFINED__ */


' ########################################################################################
' IAdviseSinkEx interface
' IID = 0000010f-0000-0000-C000-000000000046
' Inherited interface = IAdviseSink
' ########################################################################################

#IF NOT %DEF(%IAdviseSinkEx_INTERFACE_DEFINED)
    %IAdviseSinkEx_INTERFACE_DEFINED = 1

$IID_IAdviseSinkEx = GUID$("{3AF24290-0C96-11CE-A0CF-00AA00600AB8}")

INTERFACE IAdviseSinkEx $IID_IAdviseSinkEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IAdviseSink Methods
   ' =====================================================================================
   METHOD OnDataChange ( _                              ' VTable offset = 12
     BYREF pFormatetc AS FORMATETC _                    ' __in FORMATETC *pFormatetc
   , BYREF pStgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pStgmed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnViewChange ( _                              ' VTable offset = 16
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRename ( _                                  ' VTable offset = 20
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSave ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClose ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAdviseSinkEx Methods
   ' =====================================================================================
   METHOD OnViewStatusChange ( _                        ' VTable offset = 32
     BYVAL dwViewStatus AS DWORD _                      ' __in DWORD dwViewStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAdviseSinkEx_INTERFACE_DEFINED__ */


' ########################################################################################
' IQuickActivate interface
' IID = CF51ED10-62FE-11CF-BF86-00A0C9034836
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQuickActivate_INTERFACE_DEFINED)
    %IQuickActivate_INTERFACE_DEFINED = 1

' QACONTAINERFLAGS enum
%QACONTAINER_SHOWHATCHING      = &H1
%QACONTAINER_SHOWGRABHANDLES   = &H2
%QACONTAINER_USERMODE          = &H4
%QACONTAINER_DISPLAYASDEFAULT  = &H8
%QACONTAINER_UIDEAD            = &H10
%QACONTAINER_AUTOCLIP          = &H20
%QACONTAINER_MESSAGEREFLECT    = &H40
%QACONTAINER_SUPPORTSMNEMONICS = &H80

' // Size = 64 bytes
TYPE QACONTAINER DWORD
   cbSize              AS DWORD       ' ULONG cbSize
   pClientSite         AS DWORD PTR   ' IOleClientSite *pClientSite
   pAdviseSink         AS DWORD PTR   ' IAdviseSinkEx *pAdviseSink
   pPropertyNotifySink AS DWORD PTR   ' IPropertyNotifySink *pPropertyNotifySink
   pUnkEventSink       AS DWORD PTR   ' IUnknown *pUnkEventSink
   dwAmbientFlags      AS DWORD       ' DWORD dwAmbientFlags
   colorFore           AS DWORD       ' OLE_COLOR colorFore
   colorBack           AS DWORD       ' OLE_COLOR colorBack
   pFont               AS DWORD PTR   ' IFont *pFont
   pUndoMgr            AS DWORD PTR   ' IOleUndoManager *pUndoMgr
   dwAppearance        AS DWORD       ' DWORD dwAppearance
   lcid                AS DWORD       ' LONG lcid
   hpal                AS DWORD       ' HPALETTE hpal
   pBindHost           AS DWORD PTR   ' IBindHost *pBindHost
   pOleControlSite     AS DWORD PTR   ' IOleControlSite *pOleControlSite
   pServiceProvider    AS DWORD PTR   ' IServiceProvider *pServiceProvider
END TYPE

' // Size = 24 bytes
TYPE QACONTROL DWORD
   cbSize                    AS DWORD   ' ULONG cbSize
   dwMiscStatus              AS DWORD   ' DWORD dwMiscStatus
   dwViewStatus              AS DWORD   ' DWORD dwViewStatus
   dwEventCookie             AS DWORD   ' DWORD dwEventCookie
   dwPropNotifyCookie        AS DWORD   ' DWORD dwPropNotifyCookie
   dwPointerActivationPolicy AS DWORD   ' DWORD dwPointerActivationPolicy
END TYPE

$IID_IQuickActivate = GUID$("{CF51ED10-62FE-11CF-BF86-00A0C9034836}")

INTERFACE IQuickActivate $IID_IQuickActivate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QuickActivate ( _                             ' VTable offset = 12
     BYREF pQaContainer AS QACONTAINER _                ' __in QACONTAINER *pQaContainer
   , BYREF pQaControl AS QACONTROL _                    ' __in_out QACONTROL *pQaControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContentExtent ( _                          ' VTable offset = 16
     BYREF pSizel AS SIZEL _                            ' __in LPSIZEL pSizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentExtent ( _                          ' VTable offset = 20
     BYREF pSizel AS SIZEL _                            ' __out LPSIZEL pSizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQuickActivate_INTERFACE_DEFINED__ */
