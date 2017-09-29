' ########################################################################################
' Microsoft Windows
' File: ObjIdl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OBJIDL_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "wtypes.inc"

' // Size = 16 bytes
TYPE COSERVERINFO DWORD
   dwReserved1 AS DWORD            ' DWORD dwReserved1
   pwszName    AS WSTRINGZ PTR     ' LPWSTR pwszName
   pAuthInfo   AS COAUTHINFO PTR   ' COAUTHINFO *pAuthInfo
   dwReserved2 AS DWORD            ' DWORD dwReserved2
END TYPE

' ########################################################################################
' IMarshal interface
' IID = 00000003-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMarshal_INTERFACE_DEFINED)
    %IMarshal_INTERFACE_DEFINED = 1

$IID_IMarshal = GUID$("{00000003-0000-0000-C000-000000000046}")

INTERFACE IMarshal $IID_IMarshal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetUnmarshalClass ( _                         ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pv AS DWORD _                                ' __in_opt void *pv
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYVAL mshlflags AS DWORD _                         ' __in DWORD mshlflags
   , BYREF pCid AS GUID _                               ' __out CLSID *pCid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMarshalSizeMax ( _                         ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pv AS DWORD _                                ' __in_opt void *pv
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYVAL mshlflags AS DWORD _                         ' __in DWORD mshlflags
   , BYREF pSize AS DWORD _                             ' __out DWORD *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarshalInterface ( _                          ' VTable offset = 20
     BYVAL IStream _                                    ' __in IStream *pStm
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pv AS DWORD _                                ' __in_opt void *pv
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYVALmshlflags AS  DWORD _                         ' __in DWORD mshlflags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnmarshalInterface ( _                        ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream *pStm
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseMarshalData ( _                        ' VTable offset = 28
     BYVAL pStm AS IStream _                            ' __in IStream *pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectObject ( _                          ' VTable offset = 32
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMarshal_INTERFACE_DEFINED__ */


' ########################################################################################
' IMarshal2 interface
' IID = 000001CF-0000-0000-C000-000000000046
' Inherited interface = IMarshal
' ########################################################################################

#IF NOT %DEF(%IMarshal2_INTERFACE_DEFINED)
    %IMarshal2_INTERFACE_DEFINED = 1

$IID_IMarshal2 = GUID$("{000001CF-0000-0000-C000-000000000046}")

INTERFACE IMarshal2 $IID_IMarshal2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMarshal Methods
   ' =====================================================================================
   METHOD GetUnmarshalClass ( _                         ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pv AS DWORD _                                ' __in_opt void *pv
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYVAL mshlflags AS DWORD _                         ' __in DWORD mshlflags
   , BYREF pCid AS GUID _                               ' __out CLSID *pCid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMarshalSizeMax ( _                         ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pv AS DWORD _                                ' __in_opt void *pv
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYVAL mshlflags AS DWORD _                         ' __in DWORD mshlflags
   , BYREF pSize AS DWORD _                             ' __out DWORD *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarshalInterface ( _                          ' VTable offset = 20
     BYVAL IStream _                                    ' __in IStream *pStm
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pv AS DWORD _                                ' __in_opt void *pv
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYVALmshlflags AS  DWORD _                         ' __in DWORD mshlflags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnmarshalInterface ( _                        ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream *pStm
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseMarshalData ( _                        ' VTable offset = 28
     BYVAL pStm AS IStream _                            ' __in IStream *pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectObject ( _                          ' VTable offset = 32
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMarshal2_INTERFACE_DEFINED__ */


' ########################################################################################
' IMalloc interface
' IID = 00000002-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMalloc_INTERFACE_DEFINED)
    %IMalloc_INTERFACE_DEFINED = 1

$IID_IMalloc = GUID$("{00000002-0000-0000-C000-000000000046}")

INTERFACE IMalloc $IID_IMalloc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Alloc ( _                                     ' VTable offset = 12
     BYVAL cb AS DWORD _                                ' __in ULONG cb
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD Realloc ( _                                   ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in_opt void * pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD Free ( _                                      ' VTable offset = 20
     BYVAL pv AS DWORD _                                ' __in_opt void * pv
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 24
     BYVAL pv AS DWORD _                                ' __in_opt void * pv
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================
   METHOD DidAlloc ( _                                  ' VTable offset = 28
     BYVAL pv AS DWORD _                                ' __in_opt void * pv
   ) AS LONG                                            ' int
   ' =====================================================================================
   METHOD HeapMinimize ( _                              ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMalloc_INTERFACE_DEFINED__ */


' ########################################################################################
' IMallocSpy interface
' IID = 0000001D-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMallocSpy_INTERFACE_DEFINED)
    %IMallocSpy_INTERFACE_DEFINED = 1

$IID_IMallocSpy = GUID$("{0000001D-0000-0000-C000-000000000046}")

INTERFACE IMallocSpy $IID_IMallocSpy

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PreAlloc ( _                                  ' VTable offset = 12
     BYVAL cbRequest AS DWORD _                         ' __in ULONG cbRequest
   ) AS DWORD                                           ' SIZE_T
   ' =====================================================================================
   METHOD PostAlloc ( _                                 ' VTable offset = 16
     BYVAL pActual AS DWORD _                           ' __in void *pActual
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD PreFree ( _                                   ' VTable offset = 20
     BYVAL pRequest AS DWORD _                          ' __in void *pRequest
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD PostFree ( _                                  ' VTable offset = 24
     BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   )                                                    ' void
   ' =====================================================================================
   METHOD PreRealloc ( _                                ' VTable offset = 28
     BYVAL pRequest AS DWORD _                          ' __in void *pRequest
   , BYVAL cbRequest AS DWORD _                         ' __in ULONG cbRequest
   , BYREF ppNewRequest AS DWORD _                      ' __out void **ppNewRequest
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   ) AS DWORD                                           ' SIZE_T
   ' =====================================================================================
   METHOD PostRealloc ( _                               ' VTable offset = 32
     BYVAL pActual AS DWORD _                           ' __in void *pActual
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD PreGetSize ( _                                ' VTable offset = 36
     BYVAL pRequest AS DWORD _                          ' __in void *pRequest
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD PostGetSize ( _                               ' VTable offset = 40
     BYVAL cbActual AS DWORD _                          ' __in ULONG cbActual
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   ) AS DWORD                                           ' SIZE_T
   ' =====================================================================================
   METHOD PreDidAlloc ( _                               ' VTable offset = 44
     BYVAL pRequest AS DWORD _                          ' __in void *pRequest
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD PostDidAlloc ( _                              ' VTable offset = 48
     BYVAL pRequest AS DWORD _                          ' __in void *pRequest
   , BYVAL fSpyed AS LONG _                             ' __in BOOL fSpyed
   , BYVAL fActual AS LONG _                            ' __in int fActual
   ) AS LONG                                            ' int
   ' =====================================================================================
   METHOD PreHeapMinimize ( _                           ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD PostHeapMinimize ( _                          ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMallocSpy_INTERFACE_DEFINED__ */


' ########################################################################################
' IStdMarshalInfo interface
' IID = 00000018-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStdMarshalInfo_INTERFACE_DEFINED)
    %IStdMarshalInfo_INTERFACE_DEFINED = 1

$IID_IStdMarshalInfo = GUID$("{00000018-0000-0000-C000-000000000046}")

INTERFACE IStdMarshalInfo $IID_IStdMarshalInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassForHandler ( _                        ' VTable offset = 12
     BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in void *pvDestContext
   , BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStdMarshalInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IExternalConnection interface
' IID = 00000019-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExternalConnection_INTERFACE_DEFINED)
    %IExternalConnection_INTERFACE_DEFINED = 1

' EXTCONN enum
%EXTCONN_STRONG   = &H1???
%EXTCONN_WEAK     = &H2???
%EXTCONN_CALLABLE = &H4???

$IID_IExternalConnection = GUID$("{00000019-0000-0000-C000-000000000046}")

INTERFACE IExternalConnection $IID_IExternalConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddConnection ( _                             ' VTable offset = 12
     BYVAL extconn AS DWORD _                           ' __in DWORD extconn
   , BYVAL reserved AS DWORD _                          ' __in DWORD reserved
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD ReleaseConnection ( _                         ' VTable offset = 16
     BYVAL extconn AS DWORD _                           ' __in DWORD extconn
   , BYVAL reserved AS DWORD _                          ' __in DWORD reserved
   , BYVAL fLastReleaseCloses AS DWORD _                ' __in BOOL fLastReleaseCloses
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExternalConnection_INTERFACE_DEFINED__ */


' // Size = 12 bytes
TYPE MULTI_QI DWORD
   pIID AS GUID PTR    ' const IID *pIID
   pItf AS DWORD PTR   ' IUnknown *pItf
   hr   AS LONG        ' HRESULT hr
END TYPE


' ########################################################################################
' IMultiQI interface
' IID = 00000020-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultiQI_INTERFACE_DEFINED)
    %IMultiQI_INTERFACE_DEFINED = 1

$IID_IMultiQI = GUID$("{00000020-0000-0000-C000-000000000046}")

INTERFACE IMultiQI $IID_IMultiQI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryMultipleInterfaces ( _                   ' VTable offset = 12
     BYVAL cMQIs AS DWORD _                             ' __in ULONG cMQIs
   , BYREF pMQIs AS MULTI_QI _                          ' __in_out MULTI_QI *pMQIs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiQI_INTERFACE_DEFINED__ */


' ########################################################################################
' AsyncIMultiQI interface
' IID = 000E0020-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIMultiQI_INTERFACE_DEFINED)
    %AsyncIMultiQI_INTERFACE_DEFINED = 1

$IID_AsyncIMultiQI = GUID$("{000E0020-0000-0000-C000-000000000046}")

INTERFACE AsyncIMultiQI $IID_AsyncIMultiQI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_QueryMultipleInterfaces ( _             ' VTable offset = 12
     BYVAL cMQIs AS DWORD _                             ' __in ULONG cMQIs
   , BYREF pMQIs AS MULTI_QI _                          ' __in_out MULTI_QI *pMQIs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_QueryMultipleInterfaces ( _            ' VTable offset = 16
     BYREF pMQIs AS MULTI_QI _                          ' __in_out MULTI_QI *pMQIs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIMultiQI_INTERFACE_DEFINED__ */


' ########################################################################################
' IInternalUnknown interface
' IID = 00000021-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternalUnknown_INTERFACE_DEFINED)
    %IInternalUnknown_INTERFACE_DEFINED = 1

$IID_IInternalUnknown = GUID$("{00000021-0000-0000-C000-000000000046}")

INTERFACE IInternalUnknown $IID_IInternalUnknown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryInternalInterface ( _                    ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* IInternalUnknown_INTERFACE_DEFINED */


' ########################################################################################
' Interface name = IEnumUnknown
' IID = {00000100-0000-0000-C000-000000000046}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumUnknown_INTERFACE_DEFINED)
    %IEnumUnknown_INTERFACE_DEFINED = 1

$IID_IEnumUnknown = GUID$("{00000100-0000-0000-C000-000000000046}")

INTERFACE IEnumUnknown $IID_IEnumUnknown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IUnknown _                          ' __out IUnknown * rgelt
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
     BYREF ppenum AS IEnumUnknown _                     ' __out IEnumUnknown** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumUnknown_INTERFACE_DEFINED__ */


' ########################################################################################
' IBindCtx interface
' IID = 0000000E-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBindCtx_INTERFACE_DEFINED)
    %IBindCtx_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE BIND_OPTS DWORD
   cbStruct            AS DWORD   ' DWORD cbStruct
   grfFlags            AS DWORD   ' DWORD grfFlags
   grfMode             AS DWORD   ' DWORD grfMode
   dwTickCountDeadline AS DWORD   ' DWORD dwTickCountDeadline
END TYPE

' // Size = 32 bytes
TYPE BIND_OPTS2 DWORD
   cbStruct            AS DWORD              ' DWORD cbStruct
   grfFlags            AS DWORD              ' DWORD grfFlags
   grfMode             AS DWORD              ' DWORD grfMode
   dwTickCountDeadline AS DWORD              ' DWORD dwTickCountDeadline
   dwTrackFlags        AS DWORD              ' DWORD dwTrackFlags
   dwClassContext      AS DWORD              ' DWORD dwClassContext
   locale              AS DWORD              ' LCID locale
   pServerInfo         AS COSERVERINFO PTR   ' COSERVERINFO *pServerInfo
END TYPE

' BIND_FLAGS enum
%BIND_MAYBOTHERUSER     = 1
%BIND_JUSTTESTEXISTENCE = 2

$IID_IBindCtx = GUID$("{0000000E-0000-0000-C000-000000000046}")

INTERFACE IBindCtx $IID_IBindCtx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterObjectBound ( _                       ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown * punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeObjectBound ( _                         ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown * punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBoundObjects ( _                       ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBindOptions ( _                            ' VTable offset = 24
     BYREF pbindopts AS BIND_OPTS _                     ' __in BIND_OPTS * pbindopts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindOptions ( _                            ' VTable offset = 28
     BYREF pbindopts AS BIND_OPTS _                     ' __in BIND_OPTS * pbindopts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRunningObjectTable ( _                     ' VTable offset = 32
     BYREF pprot AS IRunningObjectTable _               ' __in IRunningObjectTable ** pprot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterObjectParam ( _                       ' VTable offset = 36
     BYREF pszKey AS WSTRINGZ _                         ' __in LPOLESTR pszKey
   , BYVAL punk AS IUnknown _                           ' __in IUnknown * punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectParam ( _                            ' VTable offset = 40
     BYREF pszKey AS WSTRINGZ _                         ' __in LPOLESTR pszKey
   , BYREF punk AS IUnknown _                           ' __out IUnknown ** ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjectParam ( _                           ' VTable offset = 44
     BYREF ppenum AS IEnumString _                      ' __out IEnumString ** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeObjectParam ( _                         ' VTable offset = 48
     BYREF pszKey AS WSTRINGZ _                         ' __in LPOLESTR pszKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindCtx_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumMoniker interface
' IID = 00000102-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMoniker_INTERFACE_DEFINED)
    %IEnumMoniker_INTERFACE_DEFINED = 1

$IID_IEnumMoniker = GUID$("{00000102-0000-0000-C000-000000000046}")

INTERFACE IEnumMoniker $IID_IEnumMoniker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IMoniker _                          ' __out IMoniker * rgelt
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
     BYREF ppenum AS IEnumMoniker _                     ' __out IEnumMoniker** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMoniker_INTERFACE_DEFINED__ */


' ########################################################################################
' IRunnableObject interface
' IID = F29F6BC0-5021-11CE-AA15-00006901293F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRunnableObject_INTERFACE_DEFINED)
    %IRunnableObject_INTERFACE_DEFINED = 1

$IID_IRunnableObject = GUID$("{00000126-0000-0000-C000-000000000046}")

INTERFACE IRunnableObject $IID_IRunnableObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRunningClass ( _                           ' VTable offset = 12
     BYREF lpClsid AS GUID _                            ' __out LPCLSID lpClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 16
     BYVAL pbc AS IBindCtx _                            ' __in LPBINDCTX pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 20
     ) AS LONG                                          ' BOOL
   ' =====================================================================================
   METHOD LockRunning ( _                               ' VTable offset = 24
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   , BYVAL fLastUnlockCloses AS LONG _                  ' __in BOOL fLastUnlockCloses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContainedObject ( _                        ' VTable offset = 28
     BYVAL fContained AS LONG _                         ' __in BOOL fContained
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRunnableObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IRunningObjectTable interface
' IID = 00000010-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRunningObjectTable_INTERFACE_DEFINED)
    %IRunningObjectTable_INTERFACE_DEFINED = 1

$IID_IRunningObjectTable = GUID$("{00000010-0000-0000-C000-000000000046}")

INTERFACE IRunningObjectTable $IID_IRunningObjectTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown * punkObject
   , BYVAL pmkObjectName AS IMoniker _                  ' __in IMoniker * pmkObjectName
   , BYREF pdwRegister AS DWORD _                       ' __out DWORD * pdwRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revoke ( _                                    ' VTable offset = 16
     BYVAL dwRegister AS DWORD _                        ' __in DWORD dwRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 20
     BYVAL pmkObjectName AS IMoniker _                  ' __in IMoniker * pmkObjectName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 24
     BYVAL pmkObjectName AS IMoniker _                  ' __in IMoniker * pmkObjectName
   , BYREF ppunkObject AS IUnknown _                    ' __out IUnknown ** ppunkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NoteChangeTime ( _                            ' VTable offset = 28
     BYVAL dwRegister AS DWORD _                        ' __in DWORD dwRegister
   , BYREF pfiletime AS FILETIME _                      ' __in FILETIME * pfiletime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeOfLastChange ( _                       ' VTable offset = 32
     BYVAL pmkObjectName AS IMoniker _                  ' __in IMoniker * pmkObjectName
   , BYREF pfiletime AS FILETIME _                      ' __out FILETIME * pfiletime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRunning ( _                               ' VTable offset = 36
     BYREF ppenumMoniker AS IEnumMoniker _              ' __out IEnumMoniker ** ppenumMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRunningObjectTable_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersist interface
' IID = 0000010C-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPersist_INTERFACE_DEFINED)
    %IPersist_INTERFACE_DEFINED = 1

$IID_IPersist = GUID$("{0000010C-0000-0000-C000-000000000046}")

INTERFACE IPersist $IID_IPersist

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersist_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistStream interface
' IID = 00000109-0000-0000-C000-000000000046
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistStream_INTERFACE_DEFINED)
    %IPersistStream_INTERFACE_DEFINED = 1

$IID_IPersistStream = GUID$("{00000109-0000-0000-C000-000000000046}")

INTERFACE IPersistStream $IID_IPersistStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
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

END INTERFACE

#ENDIF   ' /* __IPersistStream_INTERFACE_DEFINED__ */


' ########################################################################################
' IMoniker interface
' IID = 0000000F-0000-0000-C000-000000000046
' Inherited interface = IPersistStream
' ########################################################################################

#IF NOT %DEF(%IMoniker_INTERFACE_DEFINED)
   %IMoniker_INTERFACE_DEFINED = 1

' MKSYS enum
%MKSYS_NONE             = 0
%MKSYS_GENERICCOMPOSITE = 1
%MKSYS_FILEMONIKER      = 2
%MKSYS_ANTIMONIKER      = 3
%MKSYS_ITEMMONIKER      = 4
%MKSYS_POINTERMONIKER   = 5
%MKSYS_CLASSMONIKER     = 7
%MKSYS_OBJREFMONIKER    = 8
%MKSYS_SESSIONMONIKER   = 9
%MKSYS_LUAMONIKER       = 10

' MKRREDUCE enum
%MKRREDUCE_ONE         = 196608 ' 3<<16
%MKRREDUCE_TOUSER      = 131072 ' 2<<16
%MKRREDUCE_THROUGHUSER = 65536  ' 1<<16
%MKRREDUCE_ALL         = 0

$IID_IMoniker = GUID$("{0000000F-0000-0000-C000-000000000046}")

INTERFACE IMoniker $IID_IMoniker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
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
   METHOD BindToObject ( _                              ' VTable offset = 32
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL pmkToLeft AS IMoniker _                      ' __in IMoniker * pmkToLeft
   , BYREF riidResult AS GUID _                         ' __in REFIID riidResult
   , BYREF ppvResult AS IUnknown _                      ' __out void ** ppvResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStorage ( _                             ' VTable offset = 36
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL pmkToLeft AS IMoniker _                      ' __in IMoniker * pmkToLeft
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out void ** ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reduce ( _                                    ' VTable offset = 40
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL dwReduceHowFar AS DWORD _                    ' __in DWORD dwReduceHowFar
   , BYREF ppmkToLeft AS IMoniker _                     ' __in_out IMoniker ** ppmkToLeft
   , BYREF ppmkReduced AS IMoniker _                    ' __out IMoniker ** ppmkReduced
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComposeWith ( _                               ' VTable offset = 44
     BYVAL pmkRight AS IMoniker _                       ' __in IMoniker * pmkRight
   , BYVAL fOnlyIfNotGeneric AS LONG _                  ' __in BOOL fOnlyIfNotGeneric
   , BYREF ppmkComposite AS IMoniker _                  ' __out IMoniker ** ppmkComposite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enum ( _                                      ' VTable offset = 48
     BYVAL fForward AS LONG _                           ' __in BOOL fForward
   , BYREF ppenumMoniker AS IEnumMoniker _              ' __out IEnumMoniker ** ppenumMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 52
     BYVAL pmkOtherMoniker AS IMoniker _                ' __in IMoniker * pmkOtherMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Hash ( _                                      ' VTable offset = 56
     BYVAL pdwHash AS DWORD _                           ' __out DWORD * pdwHash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 60
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL pmkToLeft AS IMoniker _                      ' __in IMoniker * pmkToLeft
   , BYVAL pmkNewlyRunning AS IMoniker _                ' __in IMoniker * pmkNewlyRunning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeOfLastChange ( _                       ' VTable offset = 64
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL pmkToLeft AS IMoniker _                      ' __in IMoniker * pmkToLeft
   , BYREF pFileTime AS FILETIME _                      ' __out FILETIME * pFileTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Inverse ( _                                   ' VTable offset = 68
     BYREF ppmk AS IMoniker _                           ' __out IMoniker ** ppmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommonPrefixWith ( _                          ' VTable offset = 72
     BYVAL pmkOther AS IMoniker _                       ' __in IMoniker * pmkOther
   , BYREF ppmkPrefix AS IMoniker _                     ' __out IMoniker ** ppmkPrefix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RelativePathTo ( _                            ' VTable offset = 76
     BYVAL pmkOther AS IMoniker _                       ' __in IMoniker * pmkOther
   , BYREF ppmkRelPath AS IMoniker _                    ' __out IMoniker ** ppmkRelPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 80
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL IMoniker _                                   ' __in IMoniker * pmkToLeft
   , BYREF ppszDisplayName AS DWORD _                   ' __out LPOLESTR * ppszDisplayName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseDisplayName ( _                          ' VTable offset = 84
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx * pbc
   , BYVAL pmkToLeft AS IMoniker _                      ' __in IMoniker * pmkToLeft
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYREF pchEaten AS LONG _                           ' __out ULONG * pchEaten
   , BYREF ppmkOut AS IMoniker _                        ' __out IMoniker ** ppmkOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSystemMoniker ( _                           ' VTable offset = 88
     BYREF pdwMksys AS DWORD _                          ' __out DWORD * pdwMksys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMoniker_INTERFACE_DEFINED__ */


' ########################################################################################
' IROTData interface
' IID = F29F6BC0-5021-11CE-AA15-00006901293F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IROTData_INTERFACE_DEFINED)
   %IROTData_INTERFACE_DEFINED = 1

$IID_IROTData = GUID$("{F29F6BC0-5021-11CE-AA15-00006901293F}")

INTERFACE IROTData $IID_IROTData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetComparisonData ( _                         ' VTable offset = 12
     BYVAL pbData AS BYTE PTR _                         ' __out byte *pbData
   , BYVAL cbMax AS DWORD _                             ' __in ULONG cbMax
   , BYREF pcbData AS DWORD _                           ' __out ULONG *pcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IROTData_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumString interface
' IID = 00000101-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumString_INTERFACE_DEFINED)
    %IEnumString_INTERFACE_DEFINED = 1

$IID_IEnumString = GUID$("{00000101-0000-0000-C000-000000000046}")

INTERFACE IEnumString $IID_IEnumString

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS DWORD _                             ' __out LPOLESTR * rgelt
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
     BYREF ppenum AS IEnumString _                      ' __out IEnumString** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumString_INTERFACE_DEFINED__ */


' ########################################################################################
' ISequentialStream interface
' IID = 0C733A30-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISequentialStream_INTERFACE_DEFINED)
    %ISequentialStream_INTERFACE_DEFINED = 1

$IID_ISequentialStream = GUID$("{0C733A30-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE ISequentialStream $IID_ISequentialStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISequentialStream_INTERFACE_DEFINED__ */


' ########################################################################################
' IStream interface
' IID = 0000000C-0000-0000-C000-000000000046
' Inherited interface = ISequentialStream
' ########################################################################################

#IF NOT %DEF(%IStream_INTERFACE_DEFINED)
    %IStream_INTERFACE_DEFINED = 1

' // Size = 72 bytes
TYPE STATSTG DWORD
   pwcsName          AS WSTRINGZ PTR   ' LPOLESTR pwcsName
   type              AS DWORD          ' DWORD type
   cbSize            AS QUAD           ' ULARGE_INTEGER cbSize
   mtime             AS FILETIME       ' FILETIME mtime
   ctime             AS FILETIME       ' FILETIME ctime
   atime             AS FILETIME       ' FILETIME atime
   grfMode           AS DWORD          ' DWORD grfMode
   grfLocksSupported AS DWORD          ' DWORD grfLocksSupported
   clsid             AS GUID           ' CLSID clsid
   grfStateBits      AS DWORD          ' DWORD grfStateBits
   reserved          AS DWORD          ' DWORD reserved
END TYPE

' STGTY enum
%STGTY_STORAGE   = 1
%STGTY_STREAM    = 2
%STGTY_LOCKBYTES = 3
%STGTY_PROPERTY  = 4

' STREAM_SEEK enum
%STREAM_SEEK_SET = 0
%STREAM_SEEK_CUR = 1
%STREAM_SEEK_END = 2

' LOCKTYPE enum
%LOCK_WRITE     = 1
%LOCK_EXCLUSIVE = 2
%LOCK_ONLYONCE  = 4

$IID_IStream = GUID$("{0000000C-0000-0000-C000-000000000046}")

INTERFACE IStream $IID_IStream

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStream_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumSTATSTG interface
' IID = 0000000D-0000-0000-c000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSTATSTG_INTERFACE_DEFINED)
   %IEnumSTATSTG_INTERFACE_DEFINED = 1

$IID_IEnumSTATSTG = GUID$("{0000000D-0000-0000-c000-000000000046}")

INTERFACE IEnumSTATSTG $IID_IEnumSTATSTG

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS STATSTG _                           ' __out STATSTG* rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG* pceltFetched
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
     BYREF ppenum AS IEnumSTATSTG _                     ' __out IEnumSTATSTG** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSTATSTG_INTERFACE_DEFINED__ */


' ########################################################################################
' IStorage interface
' IID = 0000000B-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStorage_INTERFACE_DEFINED)
   %IStorage_INTERFACE_DEFINED = 1

' // Size = 12 bytes
TYPE RemSNB DWORD
   ulCntStr    AS DWORD          ' unsigned long ulCntStr
   ulCntChar   AS DWORD          ' unsigned long ulCntChar
   rgString(0) AS WSTRINGZ PTR   ' /* [size_is] */ OLECHAR rgString[ 1 ]
END TYPE

$IID_IStorage = GUID$("{0000000B-0000-0000-C000-000000000046}")

INTERFACE IStorage $IID_IStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateStream ( _                              ' VTable offset = 12
     BYREF pwcsName AS WSTRINGZ _                       ' __in const WCHAR* pwcsName
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYVAL reserved1 AS DWORD _                         ' __in DWORD reserved1
   , BYVAL reserved2 AS DWORD _                         ' __in DWORD reserved2
   , BYREF IStream _                                    ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenStream ( _                                ' VTable offset = 16
     BYREF pwcsName AS WSTRINGZ _                       ' __in const WCHAR* pwcsName
   , BYVAL reserved1 AS DWORD _                         ' __in DWORD reserved1
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYVAL reserved2 AS DWORD _                         ' __in DWORD reserved2
   , BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStorage ( _                             ' VTable offset = 20
     BYREF pwcsName AS WSTRINGZ _                       ' __in const WCHAR* pwcsName
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYVAL reserved1 AS DWORD _                         ' __in DWORD reserved1
   , BYVAL reserved2 AS DWORD _                         ' __in DWORD reserved2
   , BYREF ppstg AS IStorage _                          ' __out IStorage** ppstg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenStorage ( _                               ' VTable offset = 24
     BYREF pwcsName AS WSTRINGZ _                       ' __in const WCHAR* pwcsName
   , BYVAL pstgPriority AS IStorage _                   ' __in IStorage* pstgPriority
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYVAL snbExclude AS DWORD _                        ' __in SNB snbExclude
   , BYVAL reserved AS DWORD _                          ' __in DWORD reserved
   , BYREF ppstg AS IStorage _                          ' __out IStorage** ppstg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL ciidExclude AS DWORD _                       ' __in DWORD ciidExclude
   , BYVAL rgiidExclude AS DWORD _                      ' __in IID const* rgiidExclude
   , BYVAL snbExclude AS DWORD _                        ' __in SNB snbExclude
   , BYVAL pstgDest AS DWORD _                          ' __in IStorage* pstgDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveElementTo ( _                             ' VTable offset = 32
     BYREF pwcsName AS WSTRINGZ _                       ' __in const WCHAR* pwcsName
   , BYVAL pstgDest AS IStorage _                       ' __in IStorage* pstgDest
   , BYREF pwcsNewName AS WSTRINGZ _                    ' __in LPWSTR pwcsNewName
   , BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 36
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumElements ( _                              ' VTable offset = 44
     BYVAL reserved1 AS DWORD _                         ' __in DWORD reserved1
   , BYVAL reserved2 AS DWORD _                         ' __in void* reserved2
   , BYVAL reserved3 AS DWORD _                         ' __in DWORD reserved3
   , BYREF ppenum AS IEnumSTATSTG _                     ' __out IEnumSTATSTG** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyElement ( _                            ' VTable offset = 48
     BYREF pwcsName AS WSTRINGZ _                       ' __in wchar* pwcsName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameElement ( _                             ' VTable offset = 52
     BYREF pwcsOldName AS WSTRINGZ _                    ' __in const WCHAR* pwcsOldName
   , BYREF pwcsNewName AS WSTRINGZ _                    ' __in const WCHAR* pwcsNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetElementTimes ( _                           ' VTable offset = 56
     BYREF pwcsName AS WSTRINGZ _                       ' __in const WCHAR* pwcsName
   , BYREF pctime AS FILETIME _                         ' __in FILETIME const* pctime
   , BYREF patime AS FILETIME _                         ' __in FILETIME const* patime
   , BYREF pmtime AS FILETIME _                         ' __in FILETIME const* pmtime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClass ( _                                  ' VTable offset = 60
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStateBits ( _                              ' VTable offset = 64
     BYVAL grfStateBits AS DWORD _                      ' __in DWORD grfStateBits
   , BYVAL grfMask AS DWORD _                           ' __in DWORD grfMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 68
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistFile interface
' IID = 0000010B-0000-0000-C000-000000000046
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistFile_INTERFACE_DEFINED)
    %IPersistFile_INTERFACE_DEFINED = 1

$IID_IPersistFile = GUID$("{0000010B-0000-0000-C000-000000000046}")

INTERFACE IPersistFile $IID_IPersistFile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCOLESTR pszFileName
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCOLESTR pszFileName
   , BYVAL fRemember AS LONG _                          ' __in BOOL fRemember
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCompleted ( _                             ' VTable offset = 28
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCOLESTR pszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurFile ( _                                ' VTable offset = 32
     BYREF ppszFileName AS DWORD _                      ' __out LPOLESTR *ppszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistFile_INTERFACE_DEFINED__ */


' ########################################################################################
' IPersistStorage interface
' IID = 0000010A-0000-0000-C000-000000000046
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistStorage_INTERFACE_DEFINED)
    %IPersistStorage_INTERFACE_DEFINED = 1

$IID_IPersistStorage = GUID$("{0000010A-0000-0000-C000-000000000046}")

INTERFACE IPersistStorage $IID_IPersistStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 20
     BYVAL pStg AS IStorage _                           ' __in IStorage *pStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 24
     BYVAL pStg AS IStorage _                           ' __in IStorage *pStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 28
     BYVAL pStgSave AS IStorage _                       ' __in IStorage *pStgSave
   , BYVAL fSameAsLoad AS LONG _                        ' __in BOOL fSameAsLoad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCompleted ( _                             ' VTable offset = 32
     BYVAL pStgNew AS IStorage _                        ' __in IStorage *pStgNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffStorage ( _                           ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' ILockBytes interface
' IID = 0000000A-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILockBytes_INTERFACE_DEFINED)
    %ILockBytes_INTERFACE_DEFINED = 1

$IID_ILockBytes = GUID$("{0000000A-0000-0000-C000-000000000046}")

INTERFACE ILockBytes $IID_ILockBytes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadAt ( _                                    ' VTable offset = 12
     BYVAL ulOffset AS QUAD _                           ' __in ULARGE_INTEGER ulOffset
   , BYVAL pv AS DWORD _                                ' __in void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG* pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteAt ( _                                   ' VTable offset = 16
     BYVAL ulOffset AS QUAD _                           ' __in ULARGE_INTEGER ulOffset
   , BYVAL pv AS DWORD _                                ' __in void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 28
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 32
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 36
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILockBytes_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumFORMATETC interface
' IID = 00000103-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumFORMATETC_INTERFACE_DEFINED)
    %IEnumFORMATETC_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE DVTARGETDEVICE
   tdSize             AS DWORD  ' DWORD tdSize
   tdDriverNameOffset AS WORD   ' WORD tdDriverNameOffset
   tdDeviceNameOffset AS WORD   ' WORD tdDeviceNameOffset
   tdPortNameOffset   AS WORD   ' WORD tdPortNameOffset
   tdExtDevmodeOffset AS WORD   ' WORD tdExtDevmodeOffset
   tdData(3)          AS BYTE   ' /* [size_is] */ BYTE tdData[ 1 ]
   ' Note: We are using tdData(3) instead of tdData(0) to keep DWORD alignment
END TYPE

' // Size = 20 bytes
TYPE FORMATETC DWORD
   cfFormat AS DWORD                ' CLIPFORMAT cfFormat
   ptd      AS DVTARGETDEVICE PTR   ' /* [unique] */ DVTARGETDEVICE *ptd
   dwAspect AS DWORD                ' DWORD dwAspect
   lindex   AS LONG                 ' LONG lindex
   tymed    AS DWORD                ' DWORD tymed
END TYPE

$IID_IEnumFORMATETC = GUID$("{00000103-0000-0000-C000-000000000046}")

INTERFACE IEnumFORMATETC $IID_IEnumFORMATETC

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS FORMATETC _                         ' __out FORMATETC * rgelt
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
      BYREF ppenum AS IEnumFORMATETC _                  ' __out IenumFORMATETC** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumFORMATETC_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumSTATDATA interface
' IID = 00000105-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSTATDATA_INTERFACE_DEFINED)
    %IEnumSTATDATA_INTERFACE_DEFINED = 1

' ADVF enum
%ADVF_NODATA            = 1
%ADVF_PRIMEFIRST        = 2
%ADVF_ONLYONCE          = 4
%ADVF_DATAONSTOP        = 64
%ADVFCACHE_NOHANDLER    = 8
%ADVFCACHE_FORCEBUILTIN = 16
%ADVFCACHE_ONSAVE       = 32

' // Size = 32 bytes
TYPE STATDATA DWORD
   tFormatetc   AS FORMATETC   ' FORMATETC formatetc
   grfAdvf      AS DWORD       ' DWORD advf
   pIAdvSink    AS DWORD       ' /* [unique] */ IAdviseSink *pAdvSink
   dwConnection AS DWORD       ' DWORD dwConnection
END TYPE

$IID_IEnumSTATDATA = GUID$("{00000105-0000-0000-C000-000000000046}")

INTERFACE IEnumSTATDATA $IID_IEnumSTATDATA

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS STATDATA _                          ' __out STATDATA rgelt
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
     BYREF ppenum AS IEnumSTATDATA _                    ' __out IEnumSTATDATA **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSTATDATA_INTERFACE_DEFINED__ */


' ########################################################################################
' IRootStorage interface
' IID = 00000012-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRootStorage_INTERFACE_DEFINED)
    %IRootStorage_INTERFACE_DEFINED = 1

$IID_IRootStorage = GUID$("{00000012-0000-0000-C000-000000000046}")

INTERFACE IRootStorage $IID_IRootStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SwitchToFile ( _                              ' VTable offset = 12
     BYREF pszFile AS WSTRINGZ _                        ' __in LPOLESTR pszFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRootStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' IAdviseSink interface
' IID = 0000010F-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAdviseSink_INTERFACE_DEFINED)
    %IAdviseSink_INTERFACE_DEFINED = 1

' TYMED enum
%TYMED_HGLOBAL  = 1
%TYMED_FILE     = 2
%TYMED_ISTREAM  = 4
%TYMED_ISTORAGE = 8
%TYMED_GDI      = 16
%TYMED_MFPICT   = 32
%TYMED_ENHMF    = 64
%TYMED_NULL     = 0

' // Size = 4 bytes
UNION STGMEDIUMDATA DWORD
  hBitmap        AS DWORD          ' HBITMAP hBitmap
  hMetaFilePict  AS DWORD          ' HMETAFILEPICT hMetaFilePict
  hEnhMetaFile   AS DWORD          ' HENHMETAFILE hEnhMetaFile
  hGlobal        AS DWORD          ' HGLOBAL hGlobal
  lpszFileName   AS WSTRINGZ PTR   ' LPOLESTR lpszFileName
  pstm           AS DWORD          ' IStream *lpszFileName
  pstg           AS DWORD          ' IStorage *pstg
END UNION

' // Size = 12 bytes
TYPE STGMEDIUM DWORD
  tymed          AS DWORD   ' DWORD tymed
  STGMEDIUMDATA
  pUnkForRelease AS DWORD   ' IUnknown *pUnkForRelease
END TYPE

$IID_IAdviseSink = GUID$("{0000010F-0000-0000-C000-000000000046}")

INTERFACE IAdviseSink $IID_IAdviseSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDataChange ( _                              ' VTable offset = 12
     BYREF pFormatetc AS FORMATETC _                    ' __in FORMATETC *pFormatetc
   , BYREF pStgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pStgmed
   )                                                    ' void
   ' =====================================================================================
   METHOD OnViewChange ( _                              ' VTable offset = 16
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   )                                                    ' void
   ' =====================================================================================
   METHOD OnRename ( _                                  ' VTable offset = 20
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSave ( _                                    ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD OnClose ( _                                   ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAdviseSink_INTERFACE_DEFINED__ */


' ########################################################################################
' AsyncIAdviseSink interface
' IID = 00000150-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIAdviseSink_INTERFACE_DEFINED)
    %AsyncIAdviseSink_INTERFACE_DEFINED = 1

$IID_AsyncIAdviseSink = GUID$("{00000150-0000-0000-C000-000000000046}")

INTERFACE AsyncIAdviseSink $IID_AsyncIAdviseSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_OnDataChange ( _                        ' VTable offset = 12
     BYREF pFormatetc AS FORMATETC _                    ' __in FORMATETC *pFormatetc
   , BYREF pStgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pStgmed
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnDataChange ( _                       ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnViewChange ( _                        ' VTable offset = 20
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnViewChange ( _                       ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnRename ( _                            ' VTable offset = 28
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnRename ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnSave ( _                              ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnSave ( _                             ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnClose ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnClose ( _                            ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIAdviseSink_INTERFACE_DEFINED__ */


' ########################################################################################
' IAdviseSink2 interface
' IID = 00000125-0000-0000-C000-000000000046
' Inherited interface = IAdviseSink
' ########################################################################################

#IF NOT %DEF(%IAdviseSink2_INTERFACE_DEFINED)
    %IAdviseSink2_INTERFACE_DEFINED = 1

$IID_IAdviseSink2 = GUID$("{00000125-0000-0000-C000-000000000046}")

INTERFACE IAdviseSink2 $IID_IAdviseSink2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDataChange ( _                              ' VTable offset = 12
     BYREF pFormatetc AS FORMATETC _                    ' __in FORMATETC *pFormatetc
   , BYREF pStgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pStgmed
   )                                                    ' void
   ' =====================================================================================
   METHOD OnViewChange ( _                              ' VTable offset = 16
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   )                                                    ' void
   ' =====================================================================================
   METHOD OnRename ( _                                  ' VTable offset = 20
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSave ( _                                    ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD OnClose ( _                                   ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD OnLinkSrcChange ( _                           ' VTable offset = 32
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAdviseSink2_INTERFACE_DEFINED__ */


' ########################################################################################
' AsyncIAdviseSink2 interface
' IID = 00000151-0000-0000-C000-000000000046
' Inherited interface = AsyncIAdviseSink
' ########################################################################################

#IF NOT %DEF(%AsyncIAdviseSink2_INTERFACE_DEFINED)
    %AsyncIAdviseSink2_INTERFACE_DEFINED = 1

$IID_AsyncIAdviseSink2 = GUID$("{00000151-0000-0000-C000-000000000046}")

INTERFACE AsyncIAdviseSink2 $IID_AsyncIAdviseSink2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_OnDataChange ( _                        ' VTable offset = 12
     BYREF pFormatetc AS FORMATETC _                    ' __in FORMATETC *pFormatetc
   , BYREF pStgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pStgmed
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnDataChange ( _                       ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnViewChange ( _                        ' VTable offset = 20
     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
   , BYVAL lindex AS LONG _                             ' __in LONG lindex
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnViewChange ( _                       ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnRename ( _                            ' VTable offset = 28
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnRename ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnSave ( _                              ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnSave ( _                             ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnClose ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnClose ( _                            ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Begin_OnLinkSrcChange ( _                     ' VTable offset = 52
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish_OnLinkSrcChange ( _                    ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIAdviseSink2_INTERFACE_DEFINED__ */


' ########################################################################################
' IDataObject interface
' IID = 0000010E-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDataObject_INTERFACE_DEFINED)
    %IDataObject_INTERFACE_DEFINED = 1

' DATADIR enum
%DATADIR_GET = 1
%DATADIR_SET = 2

$IID_IDataObject = GUID$("{0000010E-0000-0000-C000-000000000046}")

INTERFACE IDataObject $IID_IDataObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 12
     BYREF pformatetcIn AS FORMATETC _                  ' __in FORMATETC *pformatetcIn
   , BYREF pmedium AS STGMEDIUM _                       ' __out STGMEDIUM *pmedium
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataHere ( _                               ' VTable offset = 16
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYREF pmedium AS STGMEDIUM _                       ' __in_out STGMEDIUM *pmedium
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryGetData ( _                              ' VTable offset = 20
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalFormatEtc ( _                     ' VTable offset = 24
     BYREF pformatetcIn AS FORMATETC _                  ' __in FORMATETC *pformatetcIn
   , BYREF pformatetcOut AS FORMATETC _                 ' __out FORMATETC *pformatetcOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 28
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYREF pmedium AS STGMEDIUM _                       ' __in STGMEDIUM *pmedium
   , BYVAL fRelease AS LONG _                           ' __in BOOL fRelease
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumFormatEtc ( _                             ' VTable offset = 32
     BYVAL dwDirection AS DWORD _                       ' __in DWORD dwDirection
   , BYREF ppenumFormatEtc AS IEnumFORMATETC _          ' __out IEnumFORMATETC **ppenumFormatEtc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DAdvise ( _                                   ' VTable offset = 36
     BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYVAL advf AS DWORD _                              ' __in DWORD advf
   , BYVAL pAdvSink AS IAdviseSink _                    ' __in IAdviseSink *pAdvSink
   , BYREF pdwConnection AS DWORD _                     ' __out DWORD *pdwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DUnadvise ( _                                 ' VTable offset = 40
     BYVAL dwConnection AS DWORD _                      ' __in DWORD dwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDAdvise ( _                               ' VTable offset = 44
     BYREF ppenumAdvise AS IEnumSTATDATA _              ' __out IEnumSTATDATA **ppenumAdvise
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IDataAdviseHolder interface
' IID = 00000110-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDataAdviseHolder_INTERFACE_DEFINED)
    %IDataAdviseHolder_INTERFACE_DEFINED = 1

$IID_IDataAdviseHolder = GUID$("{00000110-0000-0000-C000-000000000046}")

INTERFACE IDataAdviseHolder $IID_IDataAdviseHolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   , BYREF pFetc AS FORMATETC _                         ' __in FORMATETC *pFetc
   , BYVAL advf AS DWORD _                              ' __in DWORD advf
   , BYVAL pAdvise AS IAdviseSink _                     ' __in IAdviseSink *pAdvise
   , BYREF pdwConnection AS DWORD _                     ' __out DWORD *pdwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwConnection AS DWORD _                      ' __in DWORD dwConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAdvise ( _                                ' VTable offset = 20
     BYREF ppenumAdvise AS IEnumSTATDATA _              ' __in IEnumSTATDATA **ppenumAdvise
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendOnDataChange ( _                          ' VTable offset = 24
     BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL advf AS DWORD _                              ' __in DWORD advf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataAdviseHolder_INTERFACE_DEFINED__ */


' ########################################################################################
' IMessageFilter interface
' IID = 00000016-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMessageFilter_INTERFACE_DEFINED)
    %IMessageFilter_INTERFACE_DEFINED = 1

' CALLTYPE enum
%CALLTYPE_TOPLEVEL             = 1
%CALLTYPE_NESTED               = 2
%CALLTYPE_ASYNC                = 3
%CALLTYPE_TOPLEVEL_CALLPENDING = 4
%CALLTYPE_ASYNC_CALLPENDING    = 5

' SERVERCALL enum
%SERVERCALL_ISHANDLED  = 0
%SERVERCALL_REJECTED   = 1
%SERVERCALL_RETRYLATER = 2

' PENDINGTYPE enum
%PENDINGTYPE_TOPLEVEL = 1
%PENDINGTYPE_NESTED   = 2

' PENDINGMSG enum
%PENDINGMSG_CANCELCALL     = 0
%PENDINGMSG_WAITNOPROCESS  = 1
%PENDINGMSG_WAITDEFPROCESS = 2

' // Size = 24 bytes
TYPE INTERFACEINFO DWORD
   pUnk    AS DWORD   ' IUnknown *pUnk
   iid     AS GUID    ' IID iid
   wMethod AS WORD    ' WORD wMethod
END TYPE

$IID_IMessageFilter = GUID$("{00000016-0000-0000-C000-000000000046}")

INTERFACE IMessageFilter $IID_IMessageFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HandleInComingCall ( _                        ' VTable offset = 12
     BYVAL dwCallType AS DWORD _                        ' __in DWORD dwCallType
   , BYVAL htaskCaller AS DWORD _                       ' __in HTASK htaskCaller
   , BYVAL dwTickCount AS DWORD _                       ' __in DWORD dwTickCount
   , BYREF lpInterfaceInfo AS INTERFACEINFO _           ' __in LPINTERFACEINFO lpInterfaceInfo
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD RetryRejectedCall ( _                         ' VTable offset = 16
     BYVAL htaskCaller AS DWORD _                       ' __in HTASK htaskCallee
   , BYVAL dwTickCount AS DWORD _                       ' __in DWORD dwTickCount
   , BYVAL dwRejectType AS DWORD _                      ' __in DWORD dwRejectType
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD MessagePending ( _                            ' VTable offset = 20
     BYVAL htaskCallee AS DWORD _                       ' __in HTASK htaskCallee
   , BYVAL dwTickCount AS DWORD _                       ' __in DWORD dwTickCount
   , BYVAL dwPendingType AS DWORD _                     ' __in DWORD dwPendingType
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMessageFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcChannelBuffer interface
' IID = D5F56B60-593B-101A-B569-08002B2DBF7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRpcChannelBuffer_INTERFACE_DEFINED)
    %IRpcChannelBuffer_INTERFACE_DEFINED = 1

' // Size = 44 bytes
TYPE RPCOLEMESSAGE DWORD
   reserved1          AS DWORD   ' void *reserved1
   dataRepresentation AS DWORD   ' RPCOLEDATAREP dataRepresentation
   pBuffer            AS DWORD   ' void *Buffer
   cbBuffer           AS DWORD   ' ULONG cbBuffer
   iMethod            AS DWORD   ' ULONG iMethod
   reserved2(4)       AS DWORD   ' void *reserved2[ 5 ]
   rpcFlags           AS DWORD   ' ULONG rpcFlags
END TYPE

$IID_IRpcChannelBuffer = GUID$("{D5F56B60-593B-101A-B569-08002B2DBF7A}")

INTERFACE IRpcChannelBuffer $IID_IRpcChannelBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 12
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendReceive ( _                               ' VTable offset = 16
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in_out RPCOLEMESSAGE *pMessage
   , BYREF pStatus AS DWORD _                           ' __out ULONG *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 20
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestCtx ( _                                ' VTable offset = 24
     BYREF pdwDestContext AS DWORD _                    ' __out DWORD *pdwDestContext
   , BYREF ppvDestContext AS IUnknown _                 ' __out void **ppvDestContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcChannelBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcChannelBuffer2 interface
' IID = D5F56B60-593B-101A-B569-08002B2DBF7A
' Inherited interface = IRpcChannelBuffer
' ########################################################################################

#IF NOT %DEF(%IRpcChannelBuffer2_INTERFACE_DEFINED)
    %IRpcChannelBuffer2_INTERFACE_DEFINED = 1

$IID_IRpcChannelBuffer2 = GUID$("{594F31D0-7F19-11D0-B194-00A0C90DC8BF}")

INTERFACE IRpcChannelBuffer2 $IID_IRpcChannelBuffer2

   INHERIT IUnknown

   ' =====================================================================================
   ' IRpcChannelBuffer Methods
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 12
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendReceive ( _                               ' VTable offset = 16
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in_out RPCOLEMESSAGE *pMessage
   , BYREF pStatus AS DWORD _                           ' __out ULONG *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 20
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestCtx ( _                                ' VTable offset = 24
     BYREF pdwDestContext AS DWORD _                    ' __out DWORD *pdwDestContext
   , BYREF ppvDestContext AS IUnknown _                 ' __out void **ppvDestContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IRpcChannelBuffer2 Methods
   ' =====================================================================================
   METHOD GetProtocolVersion ( _                        ' VTable offset = 32
     BYREF pdwVersion AS DWORD _                        ' __in_out DWORD *pdwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcChannelBuffer2_INTERFACE_DEFINED__ */


' ########################################################################################
' IAsyncRpcChannelBuffer interface
' IID = a5029fb6-3c34-11d1-9c99-00c04fb998aa
' Inherited interface = IRpcChannelBuffer2
' ########################################################################################

#IF NOT %DEF(%IAsyncRpcChannelBuffer_INTERFACE_DEFINED)
    %IAsyncRpcChannelBuffer_INTERFACE_DEFINED = 1

$IID_IAsyncRpcChannelBuffer = GUID$("{a5029fb6-3c34-11d1-9c99-00c04fb998aa}")

INTERFACE IAsyncRpcChannelBuffer $IID_IAsyncRpcChannelBuffer

   INHERIT IUnknown

   ' =====================================================================================
   ' IRpcChannelBuffer Methods
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 12
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendReceive ( _                               ' VTable offset = 16
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in_out RPCOLEMESSAGE *pMessage
   , BYREF pStatus AS DWORD _                           ' __out ULONG *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 20
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestCtx ( _                                ' VTable offset = 24
     BYREF pdwDestContext AS DWORD _                    ' __out DWORD *pdwDestContext
   , BYREF ppvDestContext AS IUnknown _                 ' __out void **ppvDestContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IRpcChannelBuffer2 Methods
   ' =====================================================================================
   METHOD GetProtocolVersion ( _                        ' VTable offset = 32
     BYREF pdwVersion AS DWORD _                        ' __in_out DWORD *pdwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAsyncRpcChannelBuffer Methods
   ' =====================================================================================
   METHOD Send ( _                                      ' VTable offset = 36
     BYREF pMsg AS RPCOLEMESSAGE _                      ' __in_out RPCOLEMESSAGE *pMsg
   , BYVAL pSync AS ISynchronize _                      ' __in ISynchronize *pSync
   , BYREF pulStatus AS DWORD _                         ' __out ULONG *pulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Receive ( _                                   ' VTable offset = 40
     BYREF pMsg AS RPCOLEMESSAGE _                      ' __in_out RPCOLEMESSAGE *pMsg
   , BYREF pulStatus AS DWORD _                         ' __out ULONG *pulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestCtxEx ( _                              ' VTable offset = 44
     BYREF pMsg AS RPCOLEMESSAGE _                      ' __in_out RPCOLEMESSAGE *pMsg
   , BYREF pdwDestContext AS DWORD _                    ' __out DWORD *pdwDestContext
   , BYREF ppvDestContext AS IUnknown _                 ' __out void **ppvDestContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcChannelBuffer3 interface
' IID = 25B15600-0115-11d0-BF0D-00AA00B8DFD2
' Inherited interface = IRpcChannelBuffer2
' ########################################################################################

#IF NOT %DEF(%IRpcChannelBuffer3_INTERFACE_DEFINED)
    %IRpcChannelBuffer3_INTERFACE_DEFINED = 1

$IID_IRpcChannelBuffer3 = GUID$("{25B15600-0115-11d0-BF0D-00AA00B8DFD2}")

INTERFACE IRpcChannelBuffer3 $IID_IRpcChannelBuffer3

   INHERIT IUnknown

   ' =====================================================================================
   ' IRpcChannelBuffer Methods
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 12
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendReceive ( _                               ' VTable offset = 16
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in_out RPCOLEMESSAGE *pMessage
   , BYREF pStatus AS DWORD _                           ' __out ULONG *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 20
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestCtx ( _                                ' VTable offset = 24
     BYREF pdwDestContext AS DWORD _                    ' __out DWORD *pdwDestContext
   , BYREF ppvDestContext AS IUnknown _                 ' __out void **ppvDestContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IRpcChannelBuffer2 Methods
   ' =====================================================================================
   METHOD GetProtocolVersion ( _                        ' VTable offset = 32
     BYREF pdwVersion AS DWORD _                        ' __in_out DWORD *pdwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IRpcChannelBuffer3 Methods
   ' =====================================================================================
   METHOD Send ( _                                      ' VTable offset = 36
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in_out RPCOLEMESSAGE *pMessage
   , BYREF pulStatus AS DWORD _                         ' __out ULONG *pulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Receive ( _                                   ' VTable offset = 40
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in_out RPCOLEMESSAGE *pMessage
   , BYVAL ulSize AS DWORD _                            ' __in ULONG ulSize
   , BYREF pulStatus AS DWORD _                         ' __out ULONG *pulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 44
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallContext ( _                            ' VTable offset = 48
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pInterface AS IUnknown _                     ' __out void **pInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestCtxEx ( _                              ' VTable offset = 52
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF pdwDestContext AS DWORD _                    ' __out DWORD *pdwDestContext
   , BYREF ppvDestContext AS IUnknown _                 ' __out void **ppvDestContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 56
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYREF pState AS DWORD _                            ' __out DWORD *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAsync ( _                             ' VTable offset = 60
     BYREF pMessage AS RPCOLEMESSAGE _                  ' __in RPCOLEMESSAGE *pMessage
   , BYVAL pAsyncMgr AS IAsyncManager _                 ' __in IAsyncManager *pAsyncMgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcChannelBuffer3_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcSyntaxNegotiate interface
' IID = 58a08519-24c8-4935-b482-3fd823333a4f
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRpcSyntaxNegotiate_INTERFACE_DEFINED)
    %IRpcSyntaxNegotiate_INTERFACE_DEFINED = 1

$IID_IRpcSyntaxNegotiate = GUID$("{58a08519-24c8-4935-b482-3fd823333a4f}")

INTERFACE IRpcSyntaxNegotiate $IID_IRpcSyntaxNegotiate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NegotiateSyntax ( _                           ' VTable offset = 12
     BYREF pMsg AS RPCOLEMESSAGE _                      ' __in RPCOLEMESSAGE *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcSyntaxNegotiate_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcProxyBuffer interface
' IID = D5F56A34-593B-101A-B569-08002B2DBF7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRpcProxyBuffer_INTERFACE_DEFINED)
    %IRpcProxyBuffer_INTERFACE_DEFINED = 1

$IID_IRpcProxyBuffer = GUID$("{D5F56A34-593B-101A-B569-08002B2DBF7A}")

INTERFACE IRpcProxyBuffer $IID_IRpcProxyBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 12
     BYVAL pRpcChannelBuffer AS IRpcChannelBuffer _     ' __in IRpcChannelBuffer *pRpcChannelBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcProxyBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcStubBuffer interface
' IID = D5F56AFC-593B-101A-B569-08002B2DBF7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRpcStubBuffer_INTERFACE_DEFINED)
    %IRpcStubBuffer_INTERFACE_DEFINED = 1

$IID_IRpcStubBuffer = GUID$("{D5F56AFC-593B-101A-B569-08002B2DBF7A}")

INTERFACE IRpcStubBuffer $IID_IRpcStubBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Connect ( _                                     ' VTable offset = 12
     BYVAL pUnkServer AS IUnknown _                       ' __in IUnknown *pUnkServer
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                  ' VTable offset = 16
   )                                                      ' void
   ' =====================================================================================
   METHOD Invoke ( _                                      ' VTable offset = 20
     BYREF prpcmsg AS RPCOLEMESSAGE _                     ' __in RPCOLEMESSAGE *_prpcmsg
   , BYVAL pRpcChannelBuffer AS IRpcChannelBuffer _       ' __in IRpcChannelBuffer *_pRpcChannelBuffer
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD IsIIDSupported ( _                              ' VTable offset = 24
     BYREF riid AS GUID _                                 ' __in REFIID riid
   ) AS IRpcStubBuffer                                    ' IRpcStubBuffer *
   ' =====================================================================================
   METHOD CountRefs ( _                                   ' VTable offset = 28
   ) AS DWORD                                             ' ULONG
   ' =====================================================================================
   METHOD DebugServerQueryInterface ( _                   ' VTable offset = 32
     BYREF ppv AS IUnknown _                              ' __out void **ppv
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD DebugServerRelease ( _                          ' VTable offset = 36
     BYVAL pv AS DWORD _                                  ' __in void *pv
   )                                                      ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcStubBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' IPSFactoryBuffer interface
' IID = D5F569D0-593B-101A-B569-08002B2DBF7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPSFactoryBuffer_INTERFACE_DEFINED)
    %IPSFactoryBuffer_INTERFACE_DEFINED = 1

$IID_IPSFactoryBuffer = GUID$("{D5F569D0-593B-101A-B569-08002B2DBF7A}")

INTERFACE IPSFactoryBuffer $IID_IPSFactoryBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateProxy ( _                               ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppProxy AS IRpcProxyBuffer _                 ' __out IRpcProxyBuffer **ppProxy
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStub ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pUnkServer AS IUnknown _                     ' __in IUnknown *pUnkServer
   , BYREF ppStub AS IUnknown _                         ' __out IRpcStubBuffer **ppStub
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPSFactoryBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' IChannelHook interface
' IID = 1008c4a0-7613-11cf-9af1-0020af6e72f4
' Inherited interface = IUnknown
' ########################################################################################

'#if  (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
'// This interface is only valid on Windows NT 4.0

'typedef struct SChannelHookCallInfo
'    {
'    IID iid;
'    DWORD cbSize;
'    GUID uCausality;
'    DWORD dwServerPid;
'    DWORD iMethod;
'    void *pObject;
'    }    SChannelHookCallInfo;

'TYPE SChannelHookCallInfo DWORD
'   iid         AS GUID
'   cbSize      AS DWORD
'   uCausality  AS GUID
'   dwServerPid AS DWORD
'   iMethod     AS DWORD
'   pObject     AS DWORD
'END TYPE

'#IF NOT %DEF(%IChannelHook_INTERFACE_DEFINED)
'    %IChannelHook_INTERFACE_DEFINED = 1

'$IID_IChannelHook = GUID$("{1008c4a0-7613-11cf-9af1-0020af6e72f4}")

'    MIDL_INTERFACE("1008c4a0-7613-11cf-9af1-0020af6e72f4")
'    IChannelHook : public IUnknown
'    {
'    public:
'        virtual void STDMETHODCALLTYPE ClientGetSize(
'            __in REFGUID uExtent,
'            __in REFIID riid,
'            __out ULONG *pDataSize) = 0;

'        virtual void STDMETHODCALLTYPE ClientFillBuffer(
'            __in REFGUID uExtent,
'            __in REFIID riid,
'            __in_out ULONG *pDataSize,
'            __in void *pDataBuffer) = 0;

'        virtual void STDMETHODCALLTYPE ClientNotify(
'            __in REFGUID uExtent,
'            __in REFIID riid,
'            __in ULONG cbDataSize,
'            __in void *pDataBuffer,
'            __in DWORD lDataRep,
'            __in HRESULT hrFault) = 0;

'        virtual void STDMETHODCALLTYPE ServerNotify(
'            __in REFGUID uExtent,
'            __in REFIID riid,
'            __in ULONG cbDataSize,
'            __in void *pDataBuffer,
'            __in DWORD lDataRep) = 0;

'        virtual void STDMETHODCALLTYPE ServerGetSize(
'            __in REFGUID uExtent,
'            __in REFIID riid,
'            __in HRESULT hrFault,
'            __out ULONG *pDataSize) = 0;

'        virtual void STDMETHODCALLTYPE ServerFillBuffer(
'            __in REFGUID uExtent,
'            __in REFIID riid,
'            __in_out ULONG *pDataSize,
'            __in void *pDataBuffer,
'            __in HRESULT hrFault) = 0;

'    };

'#ENDIF   ' /* __IChannelHook_INTERFACE_DEFINED__ */


'// Well-known Property Set Format IDs
'extern const FMTID FMTID_SummaryInformation;
'extern const FMTID FMTID_DocSummaryInformation;
'extern const FMTID FMTID_UserDefinedProperties;
'extern const FMTID FMTID_DiscardableInformation;
'extern const FMTID FMTID_ImageSummaryInformation;
'extern const FMTID FMTID_AudioSummaryInformation;
'extern const FMTID FMTID_VideoSummaryInformation;
'extern const FMTID FMTID_MediaFileSummaryInformation;

'#if  (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
'// This interface is only valid on Windows NT 4.0


' ########################################################################################
' IClientSecurity interface
' IID = 0000013D-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IClientSecurity_INTERFACE_DEFINED)
    %IClientSecurity_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE SOLE_AUTHENTICATION_SERVICE DWORD
   dwAuthnSvc     AS DWORD          ' DWORD dwAuthnSvc
   dwAuthzSvc     AS DWORD          ' DWORD dwAuthzSvc
   pPrincipalName AS WSTRINGZ PTR   ' OLECHAR *pPrincipalName
   hr             AS LONG           ' HRESULT hr
END TYPE

' EOLE_AUTHENTICATION_CAPABILITIES enum
%EOAC_NONE              = &H0
%EOAC_MUTUAL_AUTH       = &H1
%EOAC_SECURE_REFS       = &H2
%EOAC_ACCESS_CONTROL    = &H4
%EOAC_APPID             = &H8
%EOAC_DYNAMIC           = &H10
%EOAC_STATIC_CLOAKING   = &H20
%EOAC_DYNAMIC_CLOAKING  = &H40
%EOAC_ANY_AUTHORITY     = &H80
%EOAC_MAKE_FULLSIC      = &H100
%EOAC_REQUIRE_FULLSIC   = &H200
%EOAC_AUTO_IMPERSONATE  = &H400
%EOAC_DEFAULT           = &H800
%EOAC_NO_CUSTOM_MARSHAL = &H2000
%EOAC_DISABLE_AAA       = &H1000

'#define   COLE_DEFAULT_PRINCIPAL   ( ( OLECHAR * )-1 )
'#define   COLE_DEFAULT_AUTHINFO   ( ( void * )-1 )

%COLE_DEFAULT_PRINCIPAL = &HFFFFFFFF???
%COLE_DEFAULT_AUTHINFO  = &HFFFFFFFF???

' // Size = 12 bytes
TYPE SOLE_AUTHENTICATION_INFO DWORD
   dwAuthnSvc AS DWORD       ' DWORD dwAuthnSvc
   dwAuthzSvc AS DWORD       ' DWORD dwAuthzSvc
   pAuthInfo  AS DWORD PTR   ' void *pAuthInfo
END TYPE

' // Size = 8 bytes
TYPE SOLE_AUTHENTICATION_LIST DWORD
   cAuthInfo AS DWORD                                    ' DWORD cAuthInfo
   aAuthInfo AS SOLE_AUTHENTICATION_INFO PTR   ' SOLE_AUTHENTICATION_INFO *aAuthInfo
END TYPE

$IID_IClientSecurity = GUID$("{0000013D-0000-0000-C000-000000000046}")

INTERFACE IClientSecurity $IID_IClientSecurity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryBlanket ( _                              ' VTable offset = 12
     BYVAL pProxy AS IUnknown _                         ' __in IUnknown * pProxy
   , BYREF pAuthnSvc AS DWORD _                         ' __out DWORD * pAuthnSvc
   , BYREF pAuthzSvc AS DWORD _                         ' __out DWORD * pAuthzSvc
   , BYREF pServerPrincName AS DWORD _                  ' __out OLECHAR ** pServerPrincName
   , BYREF pAuthnLevel AS DWORD _                       ' __out DWORD * pAuthnLevel
   , BYREF pImpLevel AS DWORD _                         ' __out DWORD * pImpLevel
   , BYREF pAuthInfo AS DWORD _                         ' __out RPC_AUTH_IDENTITY_HANDLE * pAuthInfo
   , BYREF pCapabilities AS DWORD _                     ' __out DWORD * pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlanket ( _                                ' VTable offset = 16
     BYVAL pProxy AS IUnknown _                         ' __in IUnknown * pProxy
   , BYVAL dwAuthnSvc AS DWORD _                        ' __out DWORD dwAuthnSvc
   , BYVAL dwAuthzSvc AS DWORD _                        ' __out DWORD dwAuthzSvc
   , BYREF pServerPrincName AS WSTRINGZ _               ' __out OLECHAR * pServerPrincName
   , BYVAL dwAuthnLevel AS DWORD _                      ' __out DWORD dwAuthnLevel
   , BYVAL dwImpLevel AS DWORD _                        ' __out DWORD dwImpLevel
   , BYVAL pAuthInfo AS DWORD _                         ' __out RPC_AUTH_IDENTITY_HANDLE pAuthInfo
   , BYVAL dwCapabilities AS DWORD _                    ' __out DWORD dwCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProxy ( _                                 ' VTable offset = 20
     BYVAL pProxy AS IUnknown _                         ' __in IUnknown * pProxy
   , BYREF ppCopy AS IUnknown _                         ' __out IUnknown ** ppCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClientSecurity_INTERFACE_DEFINED__ */


' ########################################################################################
' IServerSecurity interface
' IID = 0000013E-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServerSecurity_INTERFACE_DEFINED)
    %IServerSecurity_INTERFACE_DEFINED = 1

$IID_IServerSecurity = GUID$("{0000013E-0000-0000-C000-000000000046}")

INTERFACE IServerSecurity $IID_IServerSecurity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryBlanket ( _                              ' VTable offset = 12
     BYREF pAuthnSvc AS DWORD _                         ' __out DWORD *pAuthnSvc
   , BYREF pAuthzSvc AS DWORD _                         ' __out DWORD *pAuthzSvc
   , BYREF pServerPrincName AS DWORD _                  ' __out OLECHAR **pServerPrincName
   , BYREF pAuthnLevel AS DWORD _                       ' __out DWORD *pAuthnLevel
   , BYREF pImpLevel AS DWORD _                         ' __out DWORD *pImpLevel
   , BYREF pPrivs AS DWORD _                            ' __out void **pPrivs
   , BYREF pCapabilities AS DWORD _                     ' __in_out DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ImpersonateClient ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevertToSelf ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsImpersonating ( _                           ' VTable offset = 25
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServerSecurity_INTERFACE_DEFINED__ */


' ########################################################################################
' IClassActivator interface
' IID = 00000140-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IClassActivator_INTERFACE_DEFINED)
    %IClassActivator_INTERFACE_DEFINED = 1

$IID_IClassActivator = GUID$("{00000140-0000-0000-C000-000000000046}")

INTERFACE IClassActivator $IID_IClassActivator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassObject ( _                            ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __in REFCLSID * pClassID
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYVAL locale AS DWORD _                            ' __in LCID locale
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void ** ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClassActivator_INTERFACE_DEFINED__ */


' enum RPCOPT_PROPERTIES
%COMBND_RPCTIMEOUT      = &H1
%COMBND_SERVER_LOCALITY = &H2

' enum RPCOPT_SERVER_LOCALITY_VALUES
%SERVER_LOCALITY_PROCESS_LOCAL   = 0
%SERVER_LOCALITY_MACHINE_LOCAL   = 1
%SERVER_LOCALITY_REMOTE          = 2


' ########################################################################################
' IRpcOptions interface
' IID = 00000144-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRpcOptions_INTERFACE_DEFINED)
    %IRpcOptions_INTERFACE_DEFINED = 1

$IID_IRpcOptions = GUID$("{00000144-0000-0000-C000-000000000046}")

INTERFACE IRpcOptions $IID_IRpcOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 12
     BYVAL pPrx AS IUnknown _                           ' __in IUnknown *pPrx
   , BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYVAL dwValue AS DWORD _                           ' __in ULONG_PTR dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 16
     BYVAL pPrx AS IUnknown _                           ' __in IUnknown *pPrx
   , BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pdwValue AS DWORD _                          ' __out ULONG_PTR *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcOptions_INTERFACE_DEFINED__ */


' enum GLOBALOPT_PROPERTIES
%COMGLB_EXCEPTION_HANDLING     = 1
%COMGLB_APPID                  = 2
%COMGLB_RPC_THREADPOOL_SETTING = 3

' enum GLOBALOPT_EH_VALUES
%COMGLB_EXCEPTION_HANDLE             = 0
%COMGLB_EXCEPTION_DONOT_HANDLE_FATAL = 1
%COMGLB_EXCEPTION_DONOT_HANDLE       = %COMGLB_EXCEPTION_DONOT_HANDLE_FATAL
%COMGLB_EXCEPTION_DONOT_HANDLE_ANY   = 2

' enum GLOBALOPT_RPCTP_VALUES
%COMGLB_RPC_THREADPOOL_SETTING_DEFAULT_POOL = 0
%COMGLB_RPC_THREADPOOL_SETTING_PRIVATE_POOL = 1


' ########################################################################################
' IGlobalOptions interface
' IID = 0000015B-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGlobalOptions_INTERFACE_DEFINED)
    %IGlobalOptions_INTERFACE_DEFINED = 1

$IID_IGlobalOptions = GUID$("{0000015B-0000-0000-C000-000000000046}")

INTERFACE IGlobalOptions $IID_IGlobalOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 12
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYVAL dwValue AS DWORD _                           ' __in ULONG_PTR dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 16
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pdwValue AS DWORD _                          ' __out ULONG_PTR *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGlobalOptions_INTERFACE_DEFINED__ */


' ########################################################################################
' IFillLockBytes interface
' IID = 99CAF010-415E-11CF-8814-00AA00B569F5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFillLockBytes_INTERFACE_DEFINED)
    %IFillLockBytes_INTERFACE_DEFINED = 1

$IID_IFillLockBytes = GUID$("{99CAF010-415E-11CF-8814-00AA00B569F5}")

INTERFACE IFillLockBytes $IID_IFillLockBytes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FillAppend ( _                                ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillAt ( _                                    ' VTable offset = 16
     BYVAL uIOffset AS QUAD _                           ' __in ULARGE_INTEGER uIOffset
   , BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFillSize ( _                               ' VTable offset = 20
     BYVAL uISize AS QUAD _                             ' __in ULARGE_INTEGER uISize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 24
     BYVAL bCanceled AS LONG _                          ' __in BOOL bCanceled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFillLockBytes_INTERFACE_DEFINED__ */


' ########################################################################################
' IProgressNotify interface
' IID = A9D758A0-4617-11CF-95FC-00AA00680DB4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProgressNotify_INTERFACE_DEFINED)
    %IProgressNotify_INTERFACE_DEFINED = 1

$IID_IProgressNotify = GUID$("{A9D758A0-4617-11CF-95FC-00AA00680DB4}")

INTERFACE IProgressNotify $IID_IProgressNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 12
     BYVAL dwProgressCurrent AS DWORD _                 ' __in DWORD dwProgressCurrent
   , BYVAL dwProgressMaximum AS DWORD _                 ' __in DWORD dwProgressMaximum
   , BYVAL fAccurate AS LONG _                          ' __in BOOL fAccurate
   , BYVAL fOwner AS LONG _                             ' __in BOOL fOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProgressNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' ILayoutStorage interface
' IID = 0E6D4D90-6738-11CF-9608-00AA00680DB4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILayoutStorage_INTERFACE_DEFINED)
    %ILayoutStorage_INTERFACE_DEFINED = 1

' // Size = 24 bytes
TYPE StorageLayout DWORD
   LayoutType      AS DWORD          ' DWORD LayoutType
   pwcsElementName AS WSTRINGZ PTR   ' OLECHAR *pwcsElementName
   cOffset         AS QUAD           ' LARGE_INTEGER cOffset
   cBytes          AS QUAD           ' LARGE_INTEGER cBytes
END TYPE

$IID_ILayoutStorage = GUID$("{0E6D4D90-6738-11CF-9608-00AA00680DB4}")

INTERFACE ILayoutStorage $IID_ILayoutStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LayoutScript ( _                              ' VTable offset = 12
     BYVAL pStorageLayout AS StorageLayout _            ' __in StorageLayout* pStorageLayout
   , BYVAL nEntries AS DWORD _                          ' __in DWORD nEntries
   , BYVAL glfInterleavedFlag AS DWORD _                ' __in DWORD glfInterleavedFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginMonitor ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndMonitor ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReLayoutDocfile ( _                           ' VTable offset = 24
     BYREF pwcsNewDfName AS WSTRINGZ _                  ' __in OLECHAR* pwcsNewDfName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReLayoutDocfileOnILockBytes ( _               ' VTable offset = 28
     BYREF pwcsNewDfName AS WSTRINGZ _                  ' __in OLECHAR* pwcsNewDfName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILayoutStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' IBlockingLock interface
' IID = 30F3D47A-6447-11D1-8E3C-00C04FB9386D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBlockingLock_INTERFACE_DEFINED)
    %IBlockingLock_INTERFACE_DEFINED = 1

$IID_IBlockingLock = GUID$("{30F3D47A-6447-11D1-8E3C-00C04FB9386D}")

INTERFACE IBlockingLock $IID_IBlockingLock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 12
     BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBlockingLock_INTERFACE_DEFINED__ */


' ########################################################################################
' ITimeAndNoticeControl interface
' IID = BC0BF6AE-8878-11D1-83E9-00C04FC2C6D4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITimeAndNoticeControl_INTERFACE_DEFINED)
    %ITimeAndNoticeControl_INTERFACE_DEFINED = 1

$IID_ITimeAndNoticeControl = GUID$("{BC0BF6AE-8878-11D1-83E9-00C04FC2C6D4}")

INTERFACE ITimeAndNoticeControl $IID_ITimeAndNoticeControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SuppressChanges ( _                           ' VTable offset = 12
     BYVAL res1 AS DWORD _                              ' __in DWORD res1
   , BYVAL res2 AS DWORD _                              ' __in DWORD res2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITimeAndNoticeControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IOplockStorage interface
' IID = 8D19C834-8879-11D1-83E9-00C04FC2C6D4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOplockStorage_INTERFACE_DEFINED)
    %IOplockStorage_INTERFACE_DEFINED = 1

$IID_IOplockStorage = GUID$("{8D19C834-8879-11D1-83E9-00C04FC2C6D4}")

INTERFACE IOplockStorage $IID_IOplockStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateStorageEx ( _                           ' VTable offset = 12
     BYREF pwcsName AS WSTRINGZ _                       ' __in LPCWSTR pwcsName
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYVAL stgfmt AS DWORD _                            ' __in DWORD stgfmt
   , BYVAL grfAttrs AS DWORD _                          ' __in DWORD grfAttrs
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppstgOpen AS IUnknown _                      ' __out void **ppstgOpen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenStorageEx ( _                             ' VTable offset = 16
     BYREF pwcsName AS WSTRINGZ _                       ' __in LPCWSTR pwcsName
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYVAL stgfmt AS DWORD _                            ' __in DWORD stgfmt
   , BYVAL grfAttrs AS DWORD _                          ' __in DWORD grfAttrs
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppstgOpen AS IUnknown _                      ' __out void **ppstgOpen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOplockStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' ISurrogate interface
' IID = 00000022-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISurrogate_INTERFACE_DEFINED)
    %ISurrogate_INTERFACE_DEFINED = 1

$IID_ISurrogate = GUID$("{00000022-0000-0000-C000-000000000046}")

INTERFACE ISurrogate $IID_ISurrogate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadDllServer ( _                             ' VTable offset = 12
     BYREF Clsid AS GUID _                              ' __in REFCLSID Clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeSurrogate ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISurrogate_INTERFACE_DEFINED__ */


' ########################################################################################
' IGlobalInterfaceTable interface
' IID = 00000146-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGlobalInterfaceTable_INTERFACE_DEFINED)
    %IGlobalInterfaceTable_INTERFACE_DEFINED = 1

$IID_IGlobalInterfaceTable = GUID$("{00000146-0000-0000-C000-000000000046}")

INTERFACE IGlobalInterfaceTable $IID_IGlobalInterfaceTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterInterfaceInGlobal ( _                   ' VTable offset = 12
     BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
   , BYREF riid AS GUID _                                 ' __in REFIID riid
   , BYREF pdwCookie AS DWORD _                           ' __out DWORD * pdwCookie
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD RevokeInterfaceFromGlobal ( _                   ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                            ' __in DWORD dwCookie
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetInterfaceFromGlobal ( _                      ' VTable offset = 20
     BYVAL dwCookie AS DWORD _                            ' __in DWORD dwCookie
   , BYREF riid AS GUID _                                 ' __in REFIID riid
   , BYREF ppv AS IUnknown _                              ' __out void ** ppv
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGlobalInterfaceTable_INTERFACE_DEFINED__ */


' ########################################################################################
' IDirectWriterLock interface
' IID = 0E6D4D92-6738-11CF-9608-00AA00680DB4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectWriterLock_INTERFACE_DEFINED)
    %IDirectWriterLock_INTERFACE_DEFINED = 1

$IID_IDirectWriterLock = GUID$("{0E6D4D92-6738-11CF-9608-00AA00680DB4}")

INTERFACE IDirectWriterLock $IID_IDirectWriterLock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD WaitForWriteAccess ( _                        ' VTable offset = 12
     BYREF pszFile AS WSTRINGZ _                        ' __in LPOLESTR pszFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseWriteAccess ( _                        ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HaveWriteAccess ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectWriterLock_INTERFACE_DEFINED__ */


' ########################################################################################
' ISynchronize interface
' IID = 00000030-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISynchronize_INTERFACE_DEFINED)
    %ISynchronize_INTERFACE_DEFINED = 1

$IID_ISynchronize = GUID$("{00000030-0000-0000-C000-000000000046}")

INTERFACE ISynchronize $IID_ISynchronize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Signal ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISynchronize_INTERFACE_DEFINED__ */


' ########################################################################################
' ISynchronizeHandle interface
' IID = 00000031-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISynchronizeHandle_INTERFACE_DEFINED)
   %ISynchronizeHandle_INTERFACE_DEFINED = 1

$IID_ISynchronizeHandle = GUID$("{00000031-0000-0000-C000-000000000046}")

INTERFACE ISynchronizeHandle $IID_ISynchronizeHandle

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 12
     BYREF ph AS DWORD _                                ' __out HANDLE *ph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __ISynchronizeHandle_INTERFACE_DEFINED__ */


' ########################################################################################
' ISynchronizeEvent interface
' IID = 00000032-0000-0000-C000-000000000046
' Inherited interface = ISynchronizeHandle
' ########################################################################################

#IF NOT %DEF(%ISynchronizeEvent_INTERFACE_DEFINED)
    %ISynchronizeEvent_INTERFACE_DEFINED = 1

$IID_ISynchronizeEvent = GUID$("{00000032-0000-0000-C000-000000000046}")

INTERFACE ISynchronizeEvent $IID_ISynchronizeEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 12
     BYREF ph AS DWORD _                                ' __out HANDLE *ph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventHandle ( _                            ' VTable offset = 16
     BYVAL ph AS DWORD _                                ' __in HANDLE *ph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISynchronizeEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' ISynchronizeContainer interface
' IID = 00000033-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISynchronizeContainer_INTERFACE_DEFINED)
    %ISynchronizeContainer_INTERFACE_DEFINED = 1

$IID_ISynchronizeContainer = GUID$("{00000033-0000-0000-C000-000000000046}")

INTERFACE ISynchronizeContainer $IID_ISynchronizeContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddSynchronize ( _                            ' VTable offset = 12
     BYVAL pSync AS ISynchronize _                      ' __in ISynchronize *pSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitMultiple ( _                              ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwTimeOut AS DWORD _                         ' __in DWORD dwTimeOut
   , BYREF ppSync AS ISynchronize _                     ' __out ISynchronize **ppSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISynchronizeContainer_INTERFACE_DEFINED__ */


' ########################################################################################
' ISynchronizeMutex interface
' IID = 00000025-0000-0000-C000-000000000046
' Inherited interface = ISynchronize
' ########################################################################################

#IF NOT %DEF(%ISynchronizeMutex_INTERFACE_DEFINED)
    %ISynchronizeMutex_INTERFACE_DEFINED = 1

$IID_ISynchronizeMutex = GUID$("{00000025-0000-0000-C000-000000000046}")

INTERFACE ISynchronizeMutex $IID_ISynchronizeMutex

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Signal ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseMutex ( _                              ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISynchronizeMutex_INTERFACE_DEFINED__ */


' ########################################################################################
' ICancelMethodCalls interface
' IID = 00000029-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICancelMethodCalls_INTERFACE_DEFINED)
    %ICancelMethodCalls_INTERFACE_DEFINED = 1

$IID_ICancelMethodCalls = GUID$("{00000029-0000-0000-C000-000000000046}")

INTERFACE ICancelMethodCalls $IID_ICancelMethodCalls

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
     BYVAL ulSeconds AS DWORD _                         ' __in ULONG ulSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TestCancel ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICancelMethodCalls_INTERFACE_DEFINED__ */


' ########################################################################################
' IAsyncManager interface
' IID = 0000002A-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAsyncManager_INTERFACE_DEFINED)
    %IAsyncManager_INTERFACE_DEFINED = 1

' DCOM_CALL_STATE enum
%DCOM_NONE          = 0
%DCOM_CALL_COMPLETE = &H1
%DCOM_CALL_CANCELED = &H2

$IID_IAsyncManager = GUID$("{0000002A-0000-0000-C000-000000000046}")

INTERFACE IAsyncManager $IID_IAsyncManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CompleteCall ( _                              ' VTable offset = 12
     BYVAL Result AS LONG _                             ' __in HRESULT Result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallContext ( _                            ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pInterface AS IUnknown _                     ' __out void **pInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 20
     BYREF pulStateFlags AS DWORD _                     ' __out ULONG *pulStateFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAsyncManager_INTERFACE_DEFINED__ */


' ########################################################################################
' ICallFactory interface
' IID = 1C733A30-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICallFactory_INTERFACE_DEFINED)
   %ICallFactory_INTERFACE_DEFINED = 1

$IID_ICallFactory = GUID$("{1C733A30-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE ICallFactory $IID_ICallFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateCall ( _                                ' VTable offset = 12
     BYREF riid1 AS GUID _                              ' __in REFIID riid1
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown * pUnk
   , BYREF riid2 AS GUID _                              ' __in REFIID riid2
   , BYREF ppObj AS IUnknown _                          ' __out IUnknown ** ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' IRpcHelper interface
' IID = 00000149-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRpcHelper_INTERFACE_DEFINED)
   %IRpcHelper_INTERFACE_DEFINED = 1

$IID_IRpcHelper = GUID$("{00000149-0000-0000-C000-000000000046}")

INTERFACE IRpcHelper $IID_IRpcHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDCOMProtocolVersion ( _                    ' VTable offset = 12
     BYREF pComVersion AS DWORD _                       ' __out DWORD *pComVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIIDFromOBJREF ( _                          ' VTable offset = 16
     BYVAL pObjRef AS DWORD _                           ' __in void *pObjRef
   , BYREF piid AS GUID _                               ' __out IID **piid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRpcHelper_INTERFACE_DEFINED__ */


' ########################################################################################
' IReleaseMarshalBuffers interface
' IID = EB0CB9E8-7996-11D2-872E-0000F8080859
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IReleaseMarshalBuffers_INTERFACE_DEFINED)
   %IReleaseMarshalBuffers_INTERFACE_DEFINED = 1

$IID_IReleaseMarshalBuffers = GUID$("{EB0CB9E8-7996-11D2-872E-0000F8080859}")

INTERFACE IReleaseMarshalBuffers $IID_IReleaseMarshalBuffers

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReleaseMarshalBuffer ( _                      ' VTable offset = 12
     BYREF pMsg AS RPCOLEMESSAGE _                      ' __in RPCOLEMESSAGE *pMsg
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pChnl AS IUnknown _                          ' __in IUnknown *pChnl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReleaseMarshalBuffers_INTERFACE_DEFINED__ */


' ########################################################################################
' IWaitMultiple interface
' IID = 0000002B-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWaitMultiple_INTERFACE_DEFINED)
   %IWaitMultiple_INTERFACE_DEFINED = 1

$IID_IWaitMultiple = GUID$("{0000002B-0000-0000-C000-000000000046}")

INTERFACE IWaitMultiple $IID_IWaitMultiple

   INHERIT IUnknown

   ' =====================================================================================
   METHOD WaitMultiple ( _                              ' VTable offset = 12
     BYVAL timeout AS DWORD _                           ' __in DWORD timeout
   , BYREF pSync AS ISynchronize _                      ' __out ISynchronize **pSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddSynchronize ( _                            ' VTable offset = 16
     BYVAL pSync AS ISynchronize _                      ' __in ISynchronize *pSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWaitMultiple_INTERFACE_DEFINED__ */


' ########################################################################################
' IUrlMon interface
' IID = 00000026-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' This interface supports the VSIP infrastructure and is not intended to be used directly
' from your code.
' ########################################################################################

#IF NOT %DEF(%IUrlMon_INTERFACE_DEFINED)
   %IUrlMon_INTERFACE_DEFINED = 1

$IID_IUrlMon = GUID$("{00000026-0000-0000-C000-000000000046}")

INTERFACE IUrlMon $IID_IUrlMon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AsyncGetClassBits ( _                         ' VTable offset = 12
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF pszType AS WSTRINGZ _                        ' __in LPCWSTR pszTYPE
   , BYREF pszExt AS WSTRINGZ _                         ' __in LPCWSTR pszExt
   , BYVAL dwFileVersionMS AS DWORD _                   ' __in DWORD dwFileVersionMS
   , BYVAL dwFileVersionLS AS DWORD _                   ' __in DWORD dwFileVersionLS
   , BYREF pszCodeBase AS WSTRINGZ _                    ' __in LPCWSTR pszCodeBase
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYVAL dwClassContext AS DWORD _                    ' __in DWORD dwClassContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL flags AS DWORD _                             ' __in DWORD flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlMon_INTERFACE_DEFINED__ */


' ########################################################################################
' IForegroundTransfer interface
' IID = 00000145-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IForegroundTransfer_INTERFACE_DEFINED)
    %IForegroundTransfer_INTERFACE_DEFINED = 1

$IID_IForegroundTransfer = GUID$("{00000145-0000-0000-C000-000000000046}")

INTERFACE IForegroundTransfer $IID_IForegroundTransfer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AllowForegroundTransfer ( _                   ' VTable offset = 12
     BYVAL lpvReserved AS DWORD _                       ' __in void *lpvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IForegroundTransfer_INTERFACE_DEFINED__ */


' ########################################################################################
' IAddrTrackingControl interface
' IID = 00000147-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAddrTrackingControl_INTERFACE_DEFINED)
    %IAddrTrackingControl_INTERFACE_DEFINED = 1

$IID_IAddrTrackingControl = GUID$("{00000147-0000-0000-C000-000000000046}")

INTERFACE IAddrTrackingControl $IID_IAddrTrackingControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnableCOMDynamicAddrTracking ( _              ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisableCOMDynamicAddrTracking ( _             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAddrTrackingControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IAddrExclusionControl interface
' IID = 00000148-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAddrExclusionControl_INTERFACE_DEFINED)
    %IAddrExclusionControl_INTERFACE_DEFINED = 1

$IID_IAddrExclusionControl = GUID$("{00000148-0000-0000-C000-000000000046}")

INTERFACE IAddrExclusionControl $IID_IAddrExclusionControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentAddrExclusionList ( _               ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppEnumerator AS IUnknown _                   ' __out void **ppEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAddrExclusionList ( _                   ' VTable offset = 16
     BYVAL pEnumerator AS IUnknown _                    ' __in IUnknown *pEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAddrExclusionControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IPipeByte interface
' IID = DB2F3ACA-2F86-11D1-8E04-00C04FB9989A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPipeByte_INTERFACE_DEFINED)
    %IPipeByte_INTERFACE_DEFINED = 1

$IID_IPipeByte = GUID$("{DB2F3ACA-2F86-11D1-8E04-00C04FB9989A}")

INTERFACE IPipeByte $IID_IPipeByte

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Pull ( _                                      ' VTable offset = 12
     BYVAL buf AS BYTE PTR _                            ' __out BYTE *buf
   , BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   , BYREF pcReturned AS DWORD _                        ' __out ULONG *pcReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Push ( _                                      ' VTable offset = 16
     BYVAL buf AS BYTE PTR _                            ' __in BYTE *buf
   , BYVAL cSent AS DWORD _                             ' __in ULONG cSent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPipeByte_INTERFACE_DEFINED__ */


' ########################################################################################
' AsyncIPipeByte interface
' IID = DB2F3ACB-2F86-11D1-8E04-00C04FB9989A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIPipeByte_INTERFACE_DEFINED)
    %AsyncIPipeByte_INTERFACE_DEFINED = 1

$IID_AsyncIPipeByte = GUID$("{DB2F3ACB-2F86-11D1-8E04-00C04FB9989A}")

INTERFACE AsyncIPipeByte $IID_AsyncIPipeByte

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_Pull ( _                                ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Pull ( _                               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Push ( _                                ' VTable offset = 20
      BYVAL buf AS BYTE PTR _                           ' __in BYTE *buf
   ,  BYVAL cSent AS DWORD _                            ' __in ULONG cSent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Push ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIPipeByte_INTERFACE_DEFINED__ */


' ########################################################################################
' IPipeLong interface
' IID = DB2F3ACC-2F86-11D1-8E04-00C04FB9989A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPipeLong_INTERFACE_DEFINED)
    %IPipeLong_INTERFACE_DEFINED = 1

$IID_IPipeLong = GUID$("{DB2F3ACC-2F86-11D1-8E04-00C04FB9989A}")

INTERFACE IPipeLong $IID_IPipeLong

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Pull ( _                                      ' VTable offset = 12
     BYREF buf AS LONG _                                ' __out LONG *buf
   , BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   , BYREF pcReturned AS DWORD _                        ' __out ULONG *pcReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Push ( _                                      ' VTable offset = 16
     BYREF buf AS LONG _                                ' __in LONG *buf
   , BYVAL cSent AS DWORD _                             ' __in ULONG cSent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPipeLong_INTERFACE_DEFINED__ */

' ########################################################################################
' AsyncIPipeLong interface
' IID = DB2F3ACD-2F86-11D1-8E04-00C04FB9989A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIPipeLong_INTERFACE_DEFINED)
    %AsyncIPipeLong_INTERFACE_DEFINED = 1

$IID_AsyncIPipeLong = GUID$("{DB2F3ACD-2F86-11D1-8E04-00C04FB9989A}")

INTERFACE AsyncIPipeLong $IID_AsyncIPipeLong

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_Pull ( _                                ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Pull ( _                               ' VTable offset = 16
     BYREF buf AS LONG _                                ' __out LONG *buf
   , BYREF pcReturned AS DWORD _                        ' __out ULONG *pcReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Push ( _                                ' VTable offset = 20
     BYREF buf AS LONG _                                ' __in LONG *buf
   , BYVAL cSent AS DWORD _                             ' __in ULONG cSent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Push ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIPipeLong_INTERFACE_DEFINED__ */


' ########################################################################################
' IPipeDouble interface
' IID = DB2F3ACE-2F86-11D1-8E04-00C04FB9989A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPipeDouble_INTERFACE_DEFINED)
    %IPipeDouble_INTERFACE_DEFINED = 1

$IID_IPipeDouble = GUID$("{DB2F3ACE-2F86-11D1-8E04-00C04FB9989A}")

INTERFACE IPipeDouble $IID_IPipeDouble

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Pull ( _                                      ' VTable offset = 12
     BYREF buf AS DOUBLE _                              ' __out DOUBLE *buf
   , BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   , BYREF pcReturned AS DWORD _                        ' __out ULONG *pcReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Push ( _                                      ' VTable offset = 16
     BYREF buf AS DOUBLE _                              ' __in DOUBLE *buf
   , BYVAL cSent AS DWORD _                             ' __in ULONG cSent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPipeDouble_INTERFACE_DEFINED__ */


' ########################################################################################
' AsyncIPipeDouble interface
' IID = DB2F3ACF-2F86-11D1-8E04-00C04FB9989A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIPipeDouble_INTERFACE_DEFINED)
    %AsyncIPipeDouble_INTERFACE_DEFINED = 1

$IID_AsyncIPipeDouble = GUID$("{DB2F3ACF-2F86-11D1-8E04-00C04FB9989A}")

INTERFACE AsyncIPipeDouble $IID_AsyncIPipeDouble

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_Pull ( _                                ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Pull ( _                               ' VTable offset = 16
     BYREF buf AS DOUBLE _                              ' __out DOUBLE *buf
   , BYREF pcReturned AS DWORD _                        ' __out ULONG *pcReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_Push ( _                                ' VTable offset = 20
     BYREF buf AS DOUBLE _                              ' __in DOUBLE *buf
   , BYVAL cSent AS DWORD _                             ' __in ULONG cSent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_Push ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIf   ' /* __AsyncIPipeDouble_INTERFACE_DEFINED__ */


' ########################################################################################
' IThumbnailExtractor interface
' IID = 969DC708-5C76-11D1-8D86-0000F804B057
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IThumbnailExtractor_INTERFACE_DEFINED)
    %IThumbnailExtractor_INTERFACE_DEFINED = 1

$IID_IThumbnailExtractor = GUID$("{969DC708-5C76-11D1-8D86-0000F804B057}")

INTERFACE IThumbnailExtractor $IID_IThumbnailExtractor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ExtractThumbnail ( _                          ' VTable offset = 12
     BYVAL pStg AS IStorage _                           ' __in IStorage *pStg
   , BYVAL ulLength AS DWORD _                          ' __in ULONG ulLength
   , BYVAL ulHeight AS DWORD _                          ' __in ULONG ulHeight
   , BYREF pulOutputLength AS DWORD _                   ' __out ULONG *pulOutputLength
   , BYREF pulOutputHeight AS DWORD _                   ' __out ULONG *pulOutputHeight
   , BYREF phOutputBitmap AS DWORD _                    ' __out HBITMAP *phOutputBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFileUpdated ( _                             ' VTable offset = 16
     BYVAL pStg AS IStorage _                           ' __in IStorage *pStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IThumbnailExtractor_INTERFACE_DEFINED__ */


' ########################################################################################
' IDummyHICONIncluder interface
' IID = 947990de-cc28-11d2-a0f7-00805f858fb1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDummyHICONIncluder_INTERFACE_DEFINED)
    %IDummyHICONIncluder_INTERFACE_DEFINED = 1

$IID_IDummyHICONIncluder = GUID$("{947990de-cc28-11d2-a0f7-00805f858fb1}")

INTERFACE IDummyHICONIncluder $IID_IDummyHICONIncluder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Dummy ( _                                     ' VTable offset = 12
     BYVAL h1 AS DWORD _                                ' __in HICON h1
   , BYREF h2 AS DWORD _                                ' __in HDC h2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDummyHICONIncluder_INTERFACE_DEFINED__ */


'#if defined USE_COM_CONTEXT_DEF || defined BUILDTYPE_COMSVCS || defined _OLE32_

'typedef DWORD CPFLAGS;

' // Size = 24 bytes
TYPE ContextProperty
   policyId AS GUID    ' GUID policyId
   flags    AS DWORD   ' CPFLAGS flags
   pUnk     AS DWORD   ' /* [unique] */ IUnknown *pUnk
END TYPE


' ########################################################################################
' IEnumContextProps interface
' IID = 000001C1-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumContextProps_INTERFACE_DEFINED)
    %IEnumContextProps_INTERFACE_DEFINED = 1

$IID_IEnumContextProps = GUID$("{000001C1-0000-0000-C000-000000000046}")

INTERFACE IEnumContextProps $IID_IEnumContextProps

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pContextProperties AS ContextProperty _      ' __out ContextProperty *pContextProperties
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppEnumContextProps AS IEnumContextProps _    ' __out IEnumContextProps **ppEnumContextProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 28
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumContextProps_INTERFACE_DEFINED__ */


' ########################################################################################
' IContext interface
' IID = 000001C0-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContext_INTERFACE_DEFINED)
   %IContext_INTERFACE_DEFINED = 1

$IID_IContext = GUID$("{000001C0-0000-0000-C000-000000000046}")

INTERFACE IContext $IID_IContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 12
     BYREF rPolicyId AS GUID _                          ' __in REFGUID rPolicyId
   , BYVAL flags AS DWORD _                             ' __in CPFLAGS flags
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveProperty ( _                            ' VTable offset = 16
     BYREF rPolicyId AS GUID _                          ' __in REFGUID rPolicyId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rGuid AS GUID _                              ' __in REFGUID rGuid
   , BYREF pFlags AS DWORD _                            ' __out CPFLAGS *pFlags
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumContextProps ( _                          ' VTable offset = 24
     BYREF ppEnumContextProps AS IEnumContextProps _    ' __out IEnumContextProps **ppEnumContextProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContext_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjContext interface
' IID = 000001C6-0000-0000-C000-000000000046
' Inherited interface = IContext
' ########################################################################################

#IF NOT %DEF(%IObjContext_INTERFACE_DEFINED)
   %IObjContext_INTERFACE_DEFINED = 1

$IID_IObjContext = GUID$("{000001C6-0000-0000-C000-000000000046}")

INTERFACE IObjContext $IID_IObjContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 12
     BYREF rPolicyId AS GUID _                          ' __in REFGUID rPolicyId
   , BYVAL flags AS DWORD _                             ' __in CPFLAGS flags
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveProperty ( _                            ' VTable offset = 16
     BYREF rPolicyId AS GUID _                          ' __in REFGUID rPolicyId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rGuid AS GUID _                              ' __in REFGUID rGuid
   , BYREF pFlags AS DWORD _                            ' __out CPFLAGS *pFlags
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumContextProps ( _                          ' VTable offset = 24
     BYREF ppEnumContextProps AS IEnumContextProps _    ' __out IEnumContextProps **ppEnumContextProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved1 ( _                                 ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved2 ( _                                 ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved3 ( _                                 ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved4 ( _                                 ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved5 ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved6 ( _                                 ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved7 ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjContext_INTERFACE_DEFINED__ */


' ApplicationType enum
%ServerApplication  = 0
%LibraryApplication = %ServerApplication + 1

' ShutdownType enum
%IdleShutdown       = 0
%ForcedShutdown     = %IdleShutdown + 1


' ########################################################################################
' IProcessLock interface
' IID = 000001D5-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ProcessLock_INTERFACE_DEFINED)
    %ProcessLock_INTERFACE_DEFINED = 1

$IID_IProcessLock = GUID$("{000001D5-0000-0000-C000-000000000046}")

INTERFACE IProcessLock $IID_IProcessLock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefOnProcess ( _                           ' VTable offset = 12
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================
   METHOD ReleaseRefOnProcess ( _                       ' VTable offset = 16
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessLock_INTERFACE_DEFINED__ */


' ########################################################################################
' ISurrogateService interface
' IID = 000001D4-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISurrogateService_INTERFACE_DEFINED)
    %ISurrogateService_INTERFACE_DEFINED = 1

$IID_ISurrogateService = GUID$("{000001D4-0000-0000-C000-000000000046}")

INTERFACE ISurrogateService $IID_ISurrogateService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYREF rguidProcessID AS GUID _                     ' __in REFGUID rguidProcessID
   , BYVAL pProcessLock AS IProcessLock _               ' __in IProcessLock *pProcessLock
   , BYREF pfApplicationAware AS LONG _                 ' __out BOOL *pfApplicationAware
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplicationLaunch ( _                         ' VTable offset = 16
     BYREF rguidApplID AS GUID _                        ' __in REFGUID rguidApplID
   , BYVAL appType AS DWORD _                           ' __in ApplicationType appType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplicationFree ( _                           ' VTable offset = 20
     BYREF rguidApplID AS GUID _                        ' __in REFGUID rguidApplID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CatalogRefresh ( _                            ' VTable offset = 24
     BYVAL ulReserved AS DWORD _                        ' __in ULONG ulReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessShutdown ( _                           ' VTable offset = 28
     BYVAL shutdownType AS DWORD _                      ' __in ShutdownType shutdownType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISurrogateService_INTERFACE_DEFINED__ */


' enum _APTTYPEQUALIFIER
%APTTYPEQUALIFIER_NONE               = 0
%APTTYPEQUALIFIER_IMPLICIT_MTA       = 1
%APTTYPEQUALIFIER_NA_ON_MTA          = 2
%APTTYPEQUALIFIER_NA_ON_STA          = 3
%APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA = 4
%APTTYPEQUALIFIER_NA_ON_MAINSTA      = 5

' APTTYPE enum
%APTTYPE_CURRENT = -1
%APTTYPE_STA     = 0
%APTTYPE_MTA     = 1
%APTTYPE_NA      = 2
%APTTYPE_MAINSTA = 3

' THDTYPE enum
%THDTYPE_BLOCKMESSAGES   = 0
%THDTYPE_PROCESSMESSAGES = 1

'typedef DWORD APARTMENTID;


' ########################################################################################
' IComThreadingInfo interface
' IID = 000001CE-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComThreadingInfo_INTERFACE_DEFINED)
    %IComThreadingInfo_INTERFACE_DEFINED = 1

$IID_IComThreadingInfo = GUID$("{000001CE-0000-0000-C000-000000000046}")

INTERFACE IComThreadingInfo $IID_IComThreadingInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentApartmentType ( _                     ' VTable offset = 12
     BYREF pAptType AS DWORD _                            ' __out APTTYPE *pAptType
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentThreadType ( _                        ' VTable offset = 16
     BYREF pThreadType AS DWORD _                         ' __out THDTYPE *pThreadType
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentLogicalThreadId ( _                   ' VTable offset = 20
     BYREF pguidLogicalThreadId AS GUID _                 ' __out GUID *pguidLogicalThreadId
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentLogicalThreadId ( _                   ' VTable offset = 24
     BYREF rguid AS GUID _                                ' __in REFGUID rguid
   ) AS LONG                                              ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComThreadingInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IProcessInitControl interface
' IID = 72380D55-8D2B-43A3-8513-2B6EF31434E9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProcessInitControl_INTERFACE_DEFINED)
    %IProcessInitControl_INTERFACE_DEFINED = 1

$IID_IProcessInitControl = GUID$("{72380D55-8D2B-43A3-8513-2B6EF31434E9}")

INTERFACE IProcessInitControl $IID_IProcessInitControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResetInitializerTimeout ( _                   ' VTable offset = 12
     BYVAL dwSecondsRemaining AS DWORD _                ' __in DWORD dwSecondsRemaining
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessInitControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IInitializeSpy interface
' IID = 00000034-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeSpy_INTERFACE_DEFINED)
    %IInitializeSpy_INTERFACE_DEFINED = 1

$IID_IInitializeSpy = GUID$("{00000034-0000-0000-C000-000000000046}")

INTERFACE IInitializeSpy $IID_IInitializeSpy

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PreInitialize ( _                             ' VTable offset = 12
     BYVAL dwCoInit AS DWORD _                          ' __in DWORD dwCoInit
   , BYVAL dwCurThreadAptRefs AS DWORD _                ' __in DWORD dwCurThreadAptRefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostInitialize ( _                            ' VTable offset = 16
     BYVAL hrCoInit AS LONG _                           ' __in HRESULT hrCoInit
   , BYVAL dwCoInit AS DWORD _                          ' __in DWORD dwCoInit
   , BYVAL dwNewThreadAptRefs AS DWORD _                ' __in DWORD dwNewThreadAptRefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreUninitialize ( _                           ' VTable offset = 20
     BYVAL dwCurThreadAptRefs AS DWORD _                ' __in DWORD dwCurThreadAptRefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostUninitialize ( _                          ' VTable offset = 24
     BYVAL dwNewThreadAptRefs AS DWORD _                ' __in DWORD dwNewThreadAptRefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeSpy_INTERFACE_DEFINED__ */

#INCLUDE ONCE "ole2.inc"
'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
