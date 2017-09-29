' ########################################################################################
' Microsoft Windows
' File: OleIdl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEIDL_INC = 1

' The following structures must be placed before including ole2.inc
' // Size = 20 bytes
TYPE OLEINPLACEFRAMEINFO DWORD
   cb            AS DWORD   ' UINT
   fMDIApp       AS LONG                     ' BOOL
   hwndFrame     AS DWORD   ' HWND
   haccel        AS DWORD   ' HACCEL
   cAccelEntries AS DWORD   ' UINT
END TYPE

' // Size = 24 bytes
TYPE OLEMENUGROUPWIDTHS DWORD
   lWidth(5) AS LONG   ' LONG width[ 6 ]
END TYPE

#INCLUDE ONCE "ole2.inc"
'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"

' ########################################################################################
' IOleAdviseHolder interface
' IID = 00000111-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleAdviseHolder_INTERFACE_DEFINED)
    %IOleAdviseHolder_INTERFACE_DEFINED = 1

$IID_IOleAdviseHolder = GUID$("{00000111-0000-0000-C000-000000000046}")

INTERFACE IOleAdviseHolder $IID_IOleAdviseHolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL pAdvise AS IAdviseSink _                     ' __in IAdviseSink *pAdvise
   , BYREF pdwConnection AS DWORD _                     ' __out DWORD *pdwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwConnection AS DWORD _                      ' __in DWORD dwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAdvise ( _                                ' VTable offset = 20
     BYREF ppenumAdvise AS IEnumSTATDATA _              ' __out IEnumSTATDATA **ppenumAdvise
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendOnRename ( _                              ' VTable offset = 24
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendOnSave ( _                                ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendOnClose ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleAdviseHolder_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleCache interface
' IID = 0000011e-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleCache_INTERFACE_DEFINED)
    %IOleCache_INTERFACE_DEFINED = 1

$IID_IOleCache = GUID$("{0000011E-0000-0000-C000-000000000046}")

INTERFACE IOleCache $IID_IOleCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cache ( _                                     ' VTable offset = 12
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYVAL advf AS DWORD _                              ' __in DWORD advf
   , BYREF pdwConnection AS DWORD _                     ' __out DWORD *pdwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Uncache ( _                                   ' VTable offset = 16
     BYVAL dwConnection AS DWORD _                      ' __in DWORD dwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCache ( _                                 ' VTable offset = 20
     BYREF ppenumSTATDATA AS IEnumSTATDATA _            ' __out IEnumSTATDATA **ppenumSTATDATA
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitCache ( _                                 ' VTable offset = 24
     BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 28
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYREF pmedium AS STGMEDIUM _                       ' __in STGMEDIUM *pmedium
   , BYVAL fRelease AS LONG _                           ' __in BOOL fRelease
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleCache_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleCache2 interface
' IID = 00000128-0000-0000-C000-000000000046
' Inherited interface = IOleCache
' ########################################################################################

#IF NOT %DEF(%IOleCache2_INTERFACE_DEFINED)
    %IOleCache2_INTERFACE_DEFINED = 1

%UPDFCACHE_NODATACACHE          = &H1???
%UPDFCACHE_ONSAVECACHE          = &H2???
%UPDFCACHE_ONSTOPCACHE          = &H4???
%UPDFCACHE_NORMALCACHE          = &H8???
%UPDFCACHE_IFBLANK              = &H10???
%UPDFCACHE_ONLYIFBLANK          = &H80000000???
%UPDFCACHE_IFBLANKORONSAVECACHE = %UPDFCACHE_IFBLANK OR %UPDFCACHE_ONSAVECACHE
%UPDFCACHE_ALL                  = &H7FFFFFFF???
%UPDFCACHE_ALLBUTNODATACACHE    = &HFFFFFFFE???

' DISCARDCACHE enum
%DISCARDCACHE_SAVEIFDIRTY       = 0
%DISCARDCACHE_NOSAVE            = 1

$IID_IOleCache2 = GUID$("{00000128-0000-0000-C000-000000000046}")

INTERFACE IOleCache2 $IID_IOleCache2

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleCache Methods
   ' =====================================================================================
   METHOD Cache ( _                                     ' VTable offset = 12
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYVAL advf AS DWORD _                              ' __in DWORD advf
   , BYREF pdwConnection AS DWORD _                     ' __out DWORD *pdwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Uncache ( _                                   ' VTable offset = 16
     BYVAL dwConnection AS DWORD _                      ' __in DWORD dwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCache ( _                                 ' VTable offset = 20
     BYREF ppenumSTATDATA AS IEnumSTATDATA _            ' __out IEnumSTATDATA **ppenumSTATDATA
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitCache ( _                                 ' VTable offset = 24
     BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 28
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYREF pmedium AS STGMEDIUM _                       ' __in STGMEDIUM *pmedium
   , BYVAL fRelease AS LONG _                           ' __in BOOL fRelease
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleCache2 Methods
   ' =====================================================================================
   METHOD UpdateCache ( _                               ' VTable offset = 32
     BYVAL pDataObject AS IDataObject _                 ' __in LPDATAOBJECT pDataObject
   , BYVAL grfUpdf AS DWORD _                           ' __in DWORD grfUpdf
   , BYVAL pReserved AS DWORD _                         ' __in LPVOID pReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardCache ( _                              ' VTable offset = 36
     BYVAL dwDiscardOptions AS DWORD _                  ' __in DWORD dwDiscardOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleCache2_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleCacheControl interface
' IID = 00000129-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleCacheControl_INTERFACE_DEFINED)
    %IOleCacheControl_INTERFACE_DEFINED = 1

$IID_IOleCacheControl = GUID$("{00000129-0000-0000-C000-000000000046}")

INTERFACE IOleCacheControl $IID_IOleCacheControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnRun ( _                                     ' VTable offset = 12
     BYVAL pDataObject AS IDataObject _                 ' __in LPDATAOBJECT pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStop ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleCacheControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IParseDisplayName interface
' IID = 0000011a-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IParseDisplayName_INTERFACE_DEFINED)
    %IParseDisplayName_INTERFACE_DEFINED = 1

$IID_IParseDisplayName = GUID$("{0000011A-0000-0000-C000-000000000046}")

INTERFACE IParseDisplayName $IID_IParseDisplayName

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseDisplayName ( _                          ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
   , BYREF ppmkOut AS IMoniker _                        ' __out IMoniker **ppmkOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IParseDisplayName_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleContainer interface
' IID = 0000011b-0000-0000-C000-000000000046
' Inherited interface = IParseDisplayName
' ########################################################################################

#IF NOT %DEF(%IOleContainer_INTERFACE_DEFINED)
    %IOleContainer_INTERFACE_DEFINED = 1

$IID_IOleContainer = GUID$("{0000011B-0000-0000-C000-000000000046}")

INTERFACE IOleContainer $IID_IOleContainer

   INHERIT IUnknown

   ' =====================================================================================
   ' IParseDisplayName Methods
   ' =====================================================================================
   METHOD ParseDisplayName ( _                          ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
   , BYREF ppmkOut AS IMoniker _                        ' __out IMoniker **ppmkOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleContainer Methods
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYREF ppenum AS IEnumUnknown _                     ' __out IEnumUnknown **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockContainer ( _                             ' VTable offset = 20
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleContainer_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleClientSite interface
' IID = 00000118-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleClientSite_INTERFACE_DEFINED)
    %IOleClientSite_INTERFACE_DEFINED = 1

$IID_IOleClientSite = GUID$("{00000118-0000-0000-C000-000000000046}")

INTERFACE IOleClientSite $IID_IOleClientSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SaveObject ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMoniker ( _                                ' VTable offset = 16
     BYVAL dwAssign AS DWORD _                          ' __in DWORD dwAssign
   , BYVAL dwWhichMoniker AS DWORD _                    ' __in DWORD dwWhichMoniker
   , BYREF ppmk AS IMoniker _                           ' __out IMoniker ** ppmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainer ( _                              ' VTable offset = 20
     BYREF ppmk AS IMoniker _                           ' __out IMoniker ** ppmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowObject ( _                                ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnShowWindow ( _                              ' VTable offset = 28
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestNewObjectLayout ( _                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleClientSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleObject interface
' IID = 00000112-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleObject_INTERFACE_DEFINED)
    %IOleObject_INTERFACE_DEFINED = 1

' OLEGETMONIKER enum
%OLEGETMONIKER_ONLYIFTHERE = 1
%OLEGETMONIKER_FORCEASSIGN = 2
%OLEGETMONIKER_UNASSIGN    = 3
%OLEGETMONIKER_TEMPFORUSER = 4

' OLEWHICHMK enum
%OLEWHICHMK_CONTAINER = 1
%OLEWHICHMK_OBJREL    = 2
%OLEWHICHMK_OBJFULL   = 3

' USERCLASSTYPE enum
%USERCLASSTYPE_FULL    = 1
%USERCLASSTYPE_SHORT   = 2
%USERCLASSTYPE_APPNAME = 3

' OLEMISC enum
%OLEMISC_RECOMPOSEONRESIZE            = &H1???
%OLEMISC_ONLYICONIC                   = &H2???
%OLEMISC_INSERTNOTREPLACE             = &H4???
%OLEMISC_STATIC                       = &H8???
%OLEMISC_CANTLINKINSIDE               = &H10???
%OLEMISC_CANLINKBYOLE1                = &H20???
%OLEMISC_ISLINKOBJECT                 = &H40???
%OLEMISC_INSIDEOUT                    = &H80???
%OLEMISC_ACTIVATEWHENVISIBLE          = &H100???
%OLEMISC_RENDERINGISDEVICEINDEPENDENT = &H200???
%OLEMISC_INVISIBLEATRUNTIME           = &H400???
%OLEMISC_ALWAYSRUN                    = &H800???
%OLEMISC_ACTSLIKEBUTTON               = &H1000???
%OLEMISC_ACTSLIKELABEL                = &H2000???
%OLEMISC_NOUIACTIVATE                 = &H4000???
%OLEMISC_ALIGNABLE                    = &H8000???
%OLEMISC_SIMPLEFRAME                  = &H10000???
%OLEMISC_SETCLIENTSITEFIRST           = &H20000???
%OLEMISC_IMEMODE                      = &H40000???
%OLEMISC_IGNOREACTIVATEWHENVISIBLE    = &H80000???
%OLEMISC_WANTSTOMENUMERGE             = &H100000???
%OLEMISC_SUPPORTSMULTILEVELUNDO       = &H200000???

' OLECLOSE enum
%OLECLOSE_SAVEIFDIRTY = 0
%OLECLOSE_NOSAVE      = 1
%OLECLOSE_PROMPTSAVE  = 2

$IID_IOleObject = GUID$("{00000112-0000-0000-C000-000000000046}")

INTERFACE IOleObject $IID_IOleObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetClientSite ( _                             ' VTable offset = 12
     BYVAL pClientSite AS IOleClientSite _              ' __in IOleClientSite *pClientSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClientSite ( _                             ' VTable offset = 16
     BYREF ppClientSite AS IOleClientSite _             ' __out IOleClientSite **ppClientSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHostNames ( _                              ' VTable offset = 20
     BYREF szContainerApp AS WSTRINGZ _                 ' __in LPCOLESTR szContainerApp
   , BYREF szContainerObj AS WSTRINGZ _                 ' __in LPCOLESTR szContainerObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
     BYVAL dwSaveOption AS DWORD _                      ' __in DWORD dwSaveOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMoniker ( _                                ' VTable offset = 28
     BYVAL dwWhichMoniker AS DWORD _                    ' __in DWORD dwWhichMoniker
   , BYVAL pmk AS DWORD _                               ' __in IMoniker *pmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMoniker ( _                                ' VTable offset = 32
     BYVAL dwAssign AS DWORD _                          ' __in DWORD dwAssign
   , BYVAL dwWhichMoniker AS DWORD _                    ' __in DWORD dwWhichMoniker
   , BYREF pmk AS IMoniker _                            ' __out IMoniker **pmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitFromData ( _                              ' VTable offset = 36
     BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   , BYVAL fCreation AS LONG _                          ' __in BOOL fCreation
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipboardData ( _                          ' VTable offset = 40
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF ppDataObject AS IDataObject _                ' __out IDataObject **ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoVerb ( _                                    ' VTable offset = 44
     BYVAL iVerb AS LONG _                              ' __in LONG iVerb
   , BYREF lpmsg AS tagMsg _                            ' __in LPMSG lpmsg
   , BYVAL pActiveSite AS IOleClientSite _              ' __in IOleClientSite *pActiveSite
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF lprcPosRect AS RECT _                        ' __in LPCRECT lprcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumVerbs ( _                                 ' VTable offset = 48
     BYREF ppEnumOleVerb AS IEnumOleVerb _              ' __out IEnumOleVerb **ppEnumOleVerb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUpToDate ( _                                ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserClassID ( _                            ' VTable offset = 60
     BYREF pClsid AS GUID _                             ' __in CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserType ( _                               ' VTable offset = 64
     BYVAL dwFormOfType AS DWORD _                      ' __in DWORD dwFormOfType
   , BYREF pszUserType AS DWORD _                       ' __out LPOLESTR *pszUserType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExtent ( _                                 ' VTable offset = 68
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYREF psizel AS SIZEL _                            ' __in SIZEL *psizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtent ( _                                 ' VTable offset = 72
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYREF psizel AS SIZEL _                            ' __out SIZEL *psizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 76
     BYVAL pAdvSink AS IAdviseSink _                    ' __in IAdviseSink *pAdvSink
   , BYREF pdwConnection AS DWORD _                     ' __out DWORD *pdwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 80
     BYVAL dwConnection AS DWORD _                      ' __in DWORD dwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAdvise ( _                                ' VTable offset = 84
     BYREF ppenumAdvise AS IEnumSTATDATA _              ' __out IEnumSTATDATA **ppenumAdvise
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMiscStatus ( _                             ' VTable offset = 88
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorScheme ( _                            ' VTable offset = 92
     BYREF pLogpal AS LOGPALETTE _                      ' __in LOGPALETTE *pLogpal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleObject_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IOLETypes_INTERFACE_DEFINED)
    %IOLETypes_INTERFACE_DEFINED = 1

' OLERENDER enum
%OLERENDER_NONE   = 0
%OLERENDER_DRAW   = 1
%OLERENDER_FORMAT = 2
%OLERENDER_ASIS   = 3

' // Size = 52 bytes
TYPE OBJECTDESCRIPTOR DWORD
   cbSize             AS DWORD    ' ULONG
   clsid              AS GUID     ' CLSID
   dwDrawAspect       AS DWORD    ' DWORD
   tsizel             AS SIZEL    ' SIZEL
   tpointl            AS POINTL   ' POINTL
   dwStatus           AS DWORD    ' DWORD
   dwFullUserTypeName AS DWORD    ' DWORD
   dwSrcOfCopy        AS DWORD    ' DWORD
END TYPE

#ENDIF   ' /* __IOLETypes_INTERFACE_DEFINED__ */

' ########################################################################################
' IOleWindow interface
' IID = 00000114-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleWindow_INTERFACE_DEFINED)
    %IOleWindow_INTERFACE_DEFINED = 1

$IID_IOleWindow = GUID$("{00000114-0000-0000-C000-000000000046}")

INTERFACE IOleWindow $IID_IOleWindow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleWindow_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleLink interface
' IID = 0000011d-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleLink_INTERFACE_DEFINED)
    %IOleLink_INTERFACE_DEFINED = 1

' OLEUPDATE enum
%OLEUPDATE_ALWAYS = 1
%OLEUPDATE_ONCALL = 3

' OLELINKBIND enum
%OLELINKBIND_EVENIFCLASSDIFF = 1

$IID_IOleLink = GUID$("{0000011D-0000-0000-C000-000000000046}")

INTERFACE IOleLink $IID_IOleLink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetUpdateOptions ( _                          ' VTable offset = 12
     BYVAL dwUpdateOpt AS DWORD _                       ' __in DWORD dwUpdateOpt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUpdateOptions ( _                          ' VTable offset = 16
     BYREF pdwUpdateOpt AS DWORD _                      ' __out DWORD *pdwUpdateOpt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSourceMoniker ( _                          ' VTable offset = 20
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   , BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceMoniker ( _                          ' VTable offset = 24
     BYREF ppmk AS IMoniker _                           ' __out IMoniker **ppmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSourceDisplayName ( _                      ' VTable offset = 28
     BYREF pszStatusText AS WSTRINGZ _                  ' __in LPCOLESTR pszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceDisplayName ( _                      ' VTable offset = 32
     BYREF ppszDisplayName AS DWORD _                   ' __out LPOLESTR *ppszDisplayName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToSource ( _                              ' VTable offset = 36
     BYVAL bindflags AS DWORD _                         ' __in DWORD bindflags
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindIfRunning ( _                             ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoundSource ( _                            ' VTable offset = 44
     BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnbindSource ( _                              ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 52
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleLink_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleItemContainer interface
' IID = 0000011c-0000-0000-C000-000000000046
' Inherited interface = IOleContainer
' ########################################################################################

#IF NOT %DEF(%IOleItemContainer_INTERFACE_DEFINED)
    %IOleItemContainer_INTERFACE_DEFINED = 1

' BINDSPEED enum
%BINDSPEED_INDEFINITE = 1
%BINDSPEED_MODERATE   = 2
%BINDSPEED_IMMEDIATE  = 3

' OLECONTF enum
%OLECONTF_EMBEDDINGS    = 1
%OLECONTF_LINKS         = 2
%OLECONTF_OTHERS        = 4
%OLECONTF_ONLYUSER      = 8
%OLECONTF_ONLYIFRUNNING = 16

$IID_IOleItemContainer = GUID$("{0000011C-0000-0000-C000-000000000046}")

INTERFACE IOleItemContainer $IID_IOleItemContainer

   INHERIT IUnknown

   ' =====================================================================================
   ' IParseDisplayName Methods
   ' =====================================================================================
   METHOD ParseDisplayName ( _                          ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
   , BYREF ppmkOut AS IMoniker _                        ' __out IMoniker **ppmkOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleContainer Methods
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYREF ppenum AS IEnumUnknown _                     ' __out IEnumUnknown **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockContainer ( _                             ' VTable offset = 20
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleItemContainer Methods
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 24
     BYREF pszItem AS WSTRINGZ _                        ' __in LPOLESTR pszItem
   , BYVAL dwSpeedNeeded AS DWORD _                     ' __in DWORD dwSpeedNeeded
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectStorage ( _                          ' VTable offset = 28
     BYREF pszItem AS WSTRINGZ _                        ' __in LPOLESTR pszItem
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvStorage AS IUnknown _                     ' __out void **ppvStorage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 32
     BYREF pszItem AS WSTRINGZ _                        ' __in LPOLESTR pszItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleItemContainer_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceUIWindow interface
' IID = 00000115-0000-0000-C000-000000000046
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceUIWindow_INTERFACE_DEFINED)
    %IOleInPlaceUIWindow_INTERFACE_DEFINED = 1

'typedef RECT BORDERWIDTHS;

' // Size = 16 bytes
TYPE BORDERWIDTHS DWORD
   nLeft   AS LONG
   nTop    AS LONG
   nRight  AS LONG
   nBottom AS LONG
END TYPE

$IID_IOleInPlaceUIWindow = GUID$("{00000115-0000-0000-C000-000000000046}")

INTERFACE IOleInPlaceUIWindow $IID_IOleInPlaceUIWindow

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
   ' IOleInPlaceUIWindow Methods
   ' =====================================================================================
   METHOD GetBorder ( _                                 ' VTable offset = 20
     BYREF pborderwidths AS BORDERWIDTHS _              ' __in LPCBORDERWIDTHS pborderwidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestBorderSpace ( _                        ' VTable offset = 24
     BYREF pborderwidths AS BORDERWIDTHS _              ' __in LPCBORDERWIDTHS pborderwidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderSpace ( _                            ' VTable offset = 28
     BYREF pborderwidths AS BORDERWIDTHS _              ' __in LPCBORDERWIDTHS pborderwidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveObject ( _                           ' VTable offset = 32
     BYVAL pActiveObject AS IOleInPlaceActiveObject _   ' __in IOleInPlaceActiveObject *pActiveObject
   , BYREF pszObjName AS WSTRINGZ _                     ' __in LPCOLESTR pszObjName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleInPlaceUIWindow_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceActiveObject interface
' IID = 00000117-0000-0000-C000-000000000046
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceActiveObject_INTERFACE_DEFINED)
    %IOleInPlaceActiveObject_INTERFACE_DEFINED = 1

$IID_IOleInPlaceActiveObject = GUID$("{00000117-0000-0000-C000-000000000046}")

INTERFACE IOleInPlaceActiveObject $IID_IOleInPlaceActiveObject

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
   ' IOleInPlaceActiveObject Methods
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 20
     BYREF lpmsg AS tagMsg _                            ' __in LPMSG lpmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFrameWindowActivate  ( _                    ' VTable offset = 24
     BYVAL fActivate AS LONG _                          ' __in BOOL fActivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDocWindowActivate  ( _                      ' VTable offset = 28
     BYVAL fActivate AS LONG _                          ' __in BOOL fActivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResizeBorder  ( _                             ' VTable offset = 32
     BYREF prcBorder AS RECT _                          ' __in LPCRECT prcBorder
   , BYVAL pUIWindow AS IOleInPlaceUIWindow _           ' __in IOleInPlaceUIWindow pUIWindow
   , BYVAL fFrameWindow AS LONG _                       ' __in BOOL fFrameWindow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless  ( _                           ' VTable offset = 36
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '/* __IOleInPlaceActiveObject_INTERFACE_DEFINED__

' ########################################################################################
' IOleInPlaceFrame interface
' IID = 00000116-0000-0000-C000-000000000046
' Inherited interface = IOleInPlaceUIWindow
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceFrame_INTERFACE_DEFINED)
    %IOleInPlaceFrame_INTERFACE_DEFINED = 1

'typedef HGLOBAL HOLEMENU;

$IID_IOleInPlaceFrame = GUID$("{00000116-0000-0000-C000-000000000046}")

INTERFACE IOleInPlaceFrame $IID_IOleInPlaceFrame

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
   ' IOleInPlaceUIWindow Methods
   ' =====================================================================================
   METHOD GetBorder ( _                                 ' VTable offset = 20
     BYREF pborderwidths AS BORDERWIDTHS _              ' __in LPCBORDERWIDTHS pborderwidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestBorderSpace ( _                        ' VTable offset = 24
     BYREF pborderwidths AS BORDERWIDTHS _              ' __in LPCBORDERWIDTHS pborderwidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderSpace ( _                            ' VTable offset = 28
     BYREF pborderwidths AS BORDERWIDTHS _              ' __in LPCBORDERWIDTHS pborderwidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveObject ( _                           ' VTable offset = 32
     BYVAL pActiveObject AS IOleInPlaceActiveObject _   ' __in IOleInPlaceActiveObject *pActiveObject
   , BYREF pszObjName AS WSTRINGZ _                     ' __in LPCOLESTR pszObjName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOleInPlaceFrame Methods
   ' =====================================================================================
   METHOD InsertMenus ( _                               ' VTable offset = 36
     BYVAL hmenuShared AS DWORD _                       ' __in HMENU hmenuShared
   , BYREF lpMenuWidths AS OLEMENUGROUPWIDTHS _         ' __in_out LPOLEMENUGROUPWIDTHS lpMenuWidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMenu ( _                                   ' VTable offset = 44
     BYVAL hmenuShared AS DWORD _                       ' __in HMENU hmenuShared
   , BYVAL holemenu AS DWORD _                          ' __in HOLEMENU holemenu
   , BYVAL hwndActiveObject AS DWORD _                  ' __in HWND hwndActiveObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveMenus ( _                               ' VTable offset = 48
     BYVAL hmenuShared AS DWORD _                       ' __in HMENU hmenuShared
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusText ( _                             ' VTable offset = 52
     BYREF pszStatusText AS WSTRINGZ _                  ' __in LPCOLESTR pszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 56
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 60
     BYREF lpmsg AS tagMSG _                            ' __in LPMSG lpmsg
   , BYVAL wID AS WORD _                                ' __in WORD wID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleInPlaceFrame_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceObject interface
' IID = 00000113-0000-0000-C000-000000000046
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceObject_INTERFACE_DEFINED)
    %IOleInPlaceObject_INTERFACE_DEFINED = 1

$IID_IOleInPlaceObject = GUID$("{00000113-0000-0000-C000-000000000046}")

INTERFACE IOleInPlaceObject $IID_IOleInPlaceObject

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

END INTERFACE

#ENDIF   ' /* __IOleInPlaceObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleInPlaceSite interface
' IID = 00000119-0000-0000-C000-000000000046
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IOleInPlaceSite_INTERFACE_DEFINED)
    %IOleInPlaceSite_INTERFACE_DEFINED = 1

$IID_IOleInPlaceSite = GUID$("{00000119-0000-0000-C000-000000000046}")

INTERFACE IOleInPlaceSite $IID_IOleInPlaceSite

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

END INTERFACE

#ENDIF   ' /* __IOleInPlaceSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IContinue interface
' IID = 0000012A-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContinue_INTERFACE_DEFINED)
    %IContinue_INTERFACE_DEFINED = 1

$IID_IContinue = GUID$("{0000012A-0000-0000-C000-000000000046}")

INTERFACE IContinue $IID_IContinue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FContinue ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContinue_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewObject interface
' IID = 0000010d-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IViewObject_INTERFACE_DEFINED)
    %IViewObject_INTERFACE_DEFINED = 1

$IID_IViewObject = GUID$("{0000010d-0000-0000-C000-000000000046}")

INTERFACE IViewObject $IID_IViewObject

   INHERIT IUnknown

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

END INTERFACE

#ENDIF   ' /* __IViewObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewObject2 interface
' IID = 00000127-0000-0000-C000-000000000046
' Inherited interface = IViewObject
' ########################################################################################

#IF NOT %DEF(%IViewObject2_INTERFACE_DEFINED)
    %IViewObject2_INTERFACE_DEFINED = 1

$IID_IViewObject2 = GUID$("{00000127-0000-0000-C000-000000000046}")

INTERFACE IViewObject2 $IID_IViewObject2

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
   ' IViewObject2 Methods
   ' =====================================================================================
   METHOD GetExtent ( _                                 ' VTable offset = 36
     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE *ptd
   , BYREF lpsizel AS SIZEL _                           ' __out LPSIZEL lpsizel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IViewObject2_INTERFACE_DEFINED__ */


' ########################################################################################
' IDropSource interface
' IID = 00000121-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDropSource_INTERFACE_DEFINED)
    %IDropSource_INTERFACE_DEFINED = 1

$IID_IDropSource = GUID$("{00000121-0000-0000-C000-000000000046}")

INTERFACE IDropSource $IID_IDropSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryContinueDrag ( _                         ' VTable offset = 12
     BYVAL fEscapePressed AS LONG _                     ' __in BOOL fEscapePressed
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GiveFeedback ( _                              ' VTable offset = 16
     BYVAL dwEffect AS DWORD _                          ' __in DWORD dwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDropSource_INTERFACE_DEFINED__ */


' ########################################################################################
' IDropTarget interface
' IID = 00000122-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDropTarget_INTERFACE_DEFINED)
    %IDropTarget_INTERFACE_DEFINED = 1

%MK_ALT = &H20

%DROPEFFECT_NONE   = 0
%DROPEFFECT_COPY   = 1
%DROPEFFECT_MOVE   = 2
%DROPEFFECT_LINK   = 4
%DROPEFFECT_SCROLL = &H80000000???

'// default inset-width of the hot zone, in pixels
'//   typical use: GetProfileInt("windows","DragScrollInset",DD_DEFSCROLLINSET)
%DD_DEFSCROLLINSET = 11

'// default delay before scrolling, in milliseconds
'//   typical use: GetProfileInt("windows","DragScrollDelay",DD_DEFSCROLLDELAY)
%DD_DEFSCROLLDELAY = 50

'// default scroll interval, in milliseconds
'//   typical use: GetProfileInt("windows","DragScrollInterval", DD_DEFSCROLLINTERVAL)
%DD_DEFSCROLLINTERVAL = 50

'// default delay before dragging should start, in milliseconds
'//   typical use: GetProfileInt("windows", "DragDelay", DD_DEFDRAGDELAY)
%DD_DEFDRAGDELAY = 200

'// default minimum distance (radius) before dragging should start, in pixels
'//   typical use: GetProfileInt("windows", "DragMinDist", DD_DEFDRAGMINDIST)
%DD_DEFDRAGMINDIST = 2

$IID_IDropTarget = GUID$("{00000122-0000-0000-C000-000000000046}")

INTERFACE IDropTarget $IID_IDropTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DragEnter ( _                                 ' VTable offset = 12
     BYVAL pDataObj AS IDataObject _                    ' __in IDataObject *pDataObj
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   , BYREF pt AS POINTL _                               ' __in POINTL pt
   , BYREF pdwEffect AS DWORD _                         ' __in_out DWORD *pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragOver ( _                                  ' VTable offset = 16
     BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   , BYREF pt AS POINTL _                               ' __in POINTL pt
   , BYREF pdwEffect AS DWORD _                         ' __in_out DWORD *pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragLeave ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Drop ( _                                      ' VTable offset = 24
     BYVAL pDataObj AS IDataObject _                    ' __in IDataObject *pDataObj
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   , BYREF pt AS POINTL _                               ' __in POINTL pt
   , BYREF pdwEffect AS DWORD _                         ' __in_out DWORD *pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDropTarget_INTERFACE_DEFINED__ */


' ########################################################################################
' IDropSourceNotify interface
' IID = 0000012B-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDropSourceNotify_INTERFACE_DEFINED)
    %IDropSourceNotify_INTERFACE_DEFINED = 1

$IID_IDropSourceNotify = GUID$("{0000012B-0000-0000-C000-000000000046}")

INTERFACE IDropSourceNotify $IID_IDropSourceNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DragEnterTarget ( _                           ' VTable offset = 12
     BYVAL hwndTarget AS DWORD _                        ' __in HWND hwndTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragLeaveTarget ( _                           ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDropSourceNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumOLEVERB interface
' IID = 00000104-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumOLEVERB_INTERFACE_DEFINED)
    %IEnumOLEVERB_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE OLEVERB DWORD
   lVerb        AS LONG           ' LONG
   lpszVerbName AS WSTRINGZ PTR   ' LPOLESTR
   fuFlags      AS DWORD          ' DWORD
   grfAttribs   AS DWORD          ' DWORD
END TYPE

' OLEVERBATTRIB enum
%OLEVERBATTRIB_NEVERDIRTIES    = 1
%OLEVERBATTRIB_ONCONTAINERMENU = 2

$IID_IEnumOLEVERB = GUID$("{00000104-0000-0000-C000-000000000046}")

INTERFACE IEnumOLEVERB $IID_IEnumOLEVERB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS OLEVERB _                           ' __out LPOLEVERB rgelt
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
     BYREF ppenum AS IEnumOLEVERB _                     ' __out IEnumOLEVERB **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumOLEVERB_INTERFACE_DEFINED__ */
