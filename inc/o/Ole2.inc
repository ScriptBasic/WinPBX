' ########################################################################################
' Microsoft Windows
' File: Ole2.inc
' Contents: Main OLE2 header; Defines Linking and Emmebbeding interfaces, and API's.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLE2_INC = 1

#INCLUDE ONCE "windows.inc"

'// Set packing to 8
'#include <pshpack8.h>

#INCLUDE ONCE "winerror.inc"
#INCLUDE ONCE "objbase.inc"
#INCLUDE ONCE "oleauto.inc"

'// View OBJECT Error Codes

%E_DRAW                  = %VIEW_E_DRAW

'// IDataObject Error Codes
%DATA_E_FORMATETC        = %DV_E_FORMATETC


'// Common stuff gleamed from OLE.2,

'/* verbs */
%OLEIVERB_PRIMARY          =  0&
%OLEIVERB_SHOW             = -1&
%OLEIVERB_OPEN             = -2&
%OLEIVERB_HIDE             = -3&
%OLEIVERB_UIACTIVATE       = -4&
%OLEIVERB_INPLACEACTIVATE  = -5&
%OLEIVERB_DISCARDUNDOSTATE = -6&
%OLEIVERB_PROPERTIES       = -7&

'// for OleCreateEmbeddingHelper flags; roles in low word; options in high word
%EMBDHLP_INPROC_HANDLER    = &H0000???
%EMBDHLP_INPROC_SERVER     = &H0001???
%EMBDHLP_CREATENOW         = &H00000000???
%EMBDHLP_DELAYCREATE       = &H00010000???

'/* extended create function flags */
%OLECREATE_LEAVERUNNING    = &H00000001???

'/* pull in the MIDL generated header */

#INCLUDE ONCE "oleidl.inc"


'/****** DV APIs ***********************************************************/


'/* This function is declared in objbase.h and ole2.h.
'   IsolationAware support is via objbase.h.
'*/
'#if    !defined(ISOLATION_AWARE_ENABLED) \
'    || !ISOLATION_AWARE_ENABLED \
'    || !defined(_OBJBASE_H_) \
'    || !defined(CreateDataAdviseHolder)
'WINOLEAPI CreateDataAdviseHolder(OUT LPDATAADVISEHOLDER FAR* ppDAHolder);
'#endif


'/****** OLE API Prototypes ************************************************/

DECLARE FUNCTION OleBuildVersion IMPORT "OLE32.DLL" ALIAS "OleBuildVersion" ( _
 ) AS DWORD                                             ' DWORD

'/* helper functions */
DECLARE FUNCTION ReadClassStg IMPORT "OLE32.DLL" ALIAS "ReadClassStg" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYREF pclsid AS GUID _                               ' __out CLSID* pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WriteClassStg IMPORT "OLE32.DLL" ALIAS "WriteClassStg" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ReadClassStm IMPORT "OLE32.DLL" ALIAS "ReadClassStm" ( _
   BYVAL pStm AS IStream _                              ' __in IStream* pStm
 , BYREF pclsid AS GUID _                               ' __out CLSID* pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WriteClassStm IMPORT "OLE32.DLL" ALIAS "WriteClassStm" ( _
   BYVAL pStm AS IStream _                              ' __in IStream* pStm
 , BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WriteFmtUserTypeStg IMPORT "OLE32.DLL" ALIAS "WriteFmtUserTypeStg" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYVAL cf AS DWORD _                                  ' __in CLIPFORMAT cf
 , BYREF lpszUserType AS WSTRINGZ _                     ' __in LPWSTR* lpszUserType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ReadFmtUserTypeStg IMPORT "OLE32.DLL" ALIAS "ReadFmtUserTypeStg" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYREF pcf AS DWORD _                                 ' __out CLIPFORMAT* pcf
 , BYREF lplpszUserType AS DWORD _                      ' __out LPWSTR* lplpszUserType
 ) AS LONG                                              ' HRESULT


'/* init/term */

DECLARE FUNCTION OleInitialize IMPORT "OLE32.DLL" ALIAS "OleInitialize" ( _
   OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE SUB OleUninitialize IMPORT "OLE32.DLL" ALIAS "OleUninitialize" ()   ' void


'/* APIs to query whether (Embedded/Linked) object can be created from
'   the data object */

DECLARE FUNCTION OleQueryLinkFromData IMPORT "OLE32.DLL" ALIAS "OleQueryLinkFromData" ( _
   BYVAL pSrcDataObject AS IDataObject _                ' __in IDataObject * pSrcDataObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleQueryCreateFromData IMPORT "OLE32.DLL" ALIAS "OleQueryCreateFromData" ( _
   BYVAL pSrcDataObject AS IDataObject _                ' __in IDataObject * pSrcDataObject
 ) AS LONG                                              ' HRESULT


'/* Object creation APIs */

DECLARE FUNCTION OleCreate IMPORT "OLE32.DLL" ALIAS "OleCreate" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in FORMATETC * pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in IOleClientSite * pClientSite
 , BYVAL pStg AS IStorage _                             ' __in IStorage * pStg
 , BYREF ppvObject AS ANY _                             ' __out void ** ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateEx IMPORT "OLE32.DLL" ALIAS "OleCreateEx" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYVAL cFormats AS DWORD _                            ' __in ULONG cFormats
 , BYREF rgAdvf AS DWORD _                              ' __in DWORD rgAdvf [array]
 , BYREF rgFormatEtc AS FORMATETC _                     ' __in LPFORMATETC rgFormatEtc [array]
 , BYVAL pAdviseSink AS IAdviseSink _                   ' __in LPADVISESINK pAdviseSink
 , BYREF rgdwConnection AS DWORD _                      ' __out DWORD* rgdwConnection [array]
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPOLECLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateFromData IMPORT "OLE32.DLL" ALIAS "OleCreateFromData" ( _
   BYVAL pSrcDataObj AS IDataObject _                   ' __in LPDATAOBJECT pSrcDataObj
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPOLECLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateFromDataEx IMPORT "OLE32.DLL" ALIAS "OleCreateFromDataEx" ( _
   BYVAL pSrcDataObj AS IDataObject _                   ' __in LPDATAOBJECT pSrcDataObj
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYVAL cFormats AS DWORD _                            ' __in ULONG cFormats
 , BYREF rgAdvf AS DWORD _                              ' __in DWORD rgAdvf [array]
 , BYREF rgFormatEtc AS FORMATETC _                     ' __in LPFORMATETC rgFormatEtc [array]
 , BYVAL pAdviseSink AS IAdviseSink _                   ' __in LPADVISESINK pAdviseSink
 , BYREF rgdwConnection AS DWORD _                      ' __out DWORD FAR* rgdwConnection [array]
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateLinkFromData IMPORT "OLE32.DLL" ALIAS "OleCreateLinkFromData" ( _
   BYVAL pSrcDataObj AS IDataObject _                   ' __in LPDATAOBJECT pSrcDataObj
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateLinkFromDataEx IMPORT "OLE32.DLL" ALIAS "OleCreateLinkFromDataEx" ( _
   BYVAL pSrcDataObj AS IDataObject _                   ' __in LPDATAOBJECT pSrcDataObj
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYVAL cFormats AS DWORD _                            ' __in ULONG cFormats
 , BYREF rgAdvf AS DWORD _                              ' __in DWORD rgAdvf [array]
 , BYREF rgFormatEtc AS FORMATETC _                     ' __in LPFORMATETC rgFormatEtc [array]
 , BYVAL pAdviseSink AS IAdviseSink _                   ' __in LPADVISESINK pAdviseSink
 , BYREF rgdwConnection AS DWORD _                      ' __out DWORD FAR* rgdwConnection [array]
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateStaticFromData IMPORT "OLE32.DLL" ALIAS "OleCreateStaticFromData" ( _
   BYVAL pSrcDataObj AS IDataObject _                   ' __in LPDATAOBJECT pSrcDataObj
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateLink IMPORT "OLE32.DLL" ALIAS "OleCreateLink" ( _
   BYVAL pmkLinkSrc AS IMoniker _                       ' __in LPMONIKER pmkLinkSrc
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateLinkEx IMPORT "OLE32.DLL" ALIAS "OleCreateLinkEx" ( _
   BYVAL pmkLinkSrc AS IMoniker _                       ' __in LPMONIKER pmkLinkSrc
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYVAL cFormats AS DWORD _                            ' __in ULONG cFormats
 , BYREF rgAdvf AS DWORD _                              ' __in DWORD* rgAdvf
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL lpAdviseSink AS IAdviseSink _                  ' __in IAdviseSink FAR* lpAdviseSink
 , BYREF rgdwConnection AS DWORD _                      ' __out DWORD FAR* rgdwConnection
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateLinkToFile IMPORT "OLE32.DLL" ALIAS "OleCreateLinkToFile" ( _
   BYREF lpszFileName AS WSTRINGZ _                     ' __in LPWSTR lpszFileName
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateLinkToFileEx IMPORT "OLE32.DLL" ALIAS "OleCreateLinkToFileEx" ( _
   BYREF lpszFileName AS WSTRINGZ _                     ' __in LPWSTR lpszFileName
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYVAL cFormats AS DWORD _                            ' __in ULONG cFormats
 , BYREF rgAdvf AS DWORD _                              ' __in DWORD rgAdvf [array]
 , BYREF rgFormatEtc AS FORMATETC _                     ' __in LPFORMATETC rgFormatEtc [array]
 , BYVAL pAdviseSink AS IAdviseSink _                   ' __in LPADVISESINK pAdviseSink
 , BYREF rgdwConnection AS DWORD _                      ' __out DWORD FAR* rgdwConnection [array]
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateFromFile IMPORT "OLE32.DLL" ALIAS "OleCreateFromFile" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF lpszFileName AS WSTRINGZ _                     ' __in LPCOLESTR lpszFileName
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYREF pFormatEtc AS FORMATETC _                      ' __in LPFORMATETC pFormatEtc
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPOLECLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateFromFileEx IMPORT "OLE32.DLL" ALIAS "OleCreateFromFileEx" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF lpszFileName AS WSTRINGZ _                     ' __in LPCOLESTR lpszFileName
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL renderopt AS DWORD _                           ' __in DWORD renderopt
 , BYVAL cFormats AS DWORD _                            ' __in ULONG cFormats
 , BYREF rgAdvf AS DWORD _                              ' __in DWORD rgAdvf [array]
 , BYREF rgFormatEtc AS FORMATETC _                     ' __in LPFORMATETC rgFormatEtc [array]
 , BYVAL pAdviseSink AS IAdviseSink _                   ' __in LPADVISESINK pAdviseSink
 , BYREF rgdwConnection AS DWORD _                      ' __out DWORD FAR* rgdwConnection [array]
 , BYVAL pClientSite AS IOleClientSite _                ' __in LPCLIENTSITE pClientSite
 , BYVAL pStg AS IStorage _                             ' __in LPSTORAGE pStg
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR* ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoad IMPORT "OLE32.DLL" ALIAS "OleLoad" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage * pStg
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL pClientSite AS IOleClientSite _                ' __in IOleClientSite * pClientSite
 , BYREF ppvObj AS ANY _                                ' __out LPVOID * ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleSave IMPORT "OLE32.DLL" ALIAS "OleSave" ( _
   BYVAL pPS AS IPersistStorage _                       ' __in IPersistStorage * pPS
 , BYVAL pStg AS IStorage _                             ' __in IStorage * pStg
 , BYVAL fSameAsLoad AS LONG _                          ' __in BOOL fSameAsLoad
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoadFromStream IMPORT "OLE32.DLL" ALIAS "OleLoadFromStream" ( _
   BYVAL pStm AS IStream _                              ' __in IStream * pStm
 , BYREF iidInterface AS GUID _                         ' __in REFIID iidInterface
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleSaveToStream IMPORT "OLE32.DLL" ALIAS "OleSaveToStream" ( _
   BYVAL pPStm AS IPersistStream _                      ' __in IPersistStream * pPStm
 , BYVAL pStm AS IStream _                              ' __in IStream * pStm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleSetContainedObject IMPORT "OLE32.DLL" ALIAS "OleSetContainedObject" ( _
   BYVAL pUnk AS IUnknown _                             ' __in LPUNKNOWN pUnk
 , BYVAL fContained AS LONG _                           ' __in BOOL fContained
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleNoteObjectVisible IMPORT "OLE32.DLL" ALIAS "OleNoteObjectVisible" ( _
   BYVAL pUnknown AS IUnknown _                         ' __in LPUNKNOWN pUnknown
 , BYVAL fVisible AS LONG _                             ' __in BOOL fVisible
 ) AS LONG                                              ' HRESULT


'/* Drag/Drop APIs */

DECLARE FUNCTION RegisterDragDrop IMPORT "OLE32.DLL" ALIAS "RegisterDragDrop" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL pDropTarget As IDropTarget _                   ' __in IDropTarget * pDropTarget
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RevokeDragDrop IMPORT "OLE32.DLL" ALIAS "RevokeDragDrop" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DoDragDrop IMPORT "OLE32.DLL" ALIAS "DoDragDrop" ( _
   BYVAL pDataObject AS IDataObject _                   ' __in IDataObject * pDataObject
 , BYVAL pDropSource AS IDropSource _                   ' __in IDropSource * pDropSource
 , BYVAL dwOKEffect AS DWORD _                          ' __in DWORD dwOKEffect
 , BYREF pdwEffect AS DWORD _                           ' __out DWORD * pdwEffect
 ) AS LONG                                              ' HRESULT

'/* Clipboard APIs */

DECLARE FUNCTION OleSetClipboard IMPORT "OLE32.DLL" ALIAS "OleSetClipboard" ( _
   BYVAL pDataObj AS IDataObject _                      ' __in IDataObject * pDataObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleGetClipboard IMPORT "OLE32.DLL" ALIAS "OleGetClipboard" ( _
   BYREF ppDataObj AS IDataObject _                     ' __out IDataObject ** ppDataObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleFlushClipboard IMPORT "OLE32.DLL" ALIAS "OleFlushClipboard" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleIsCurrentClipboard IMPORT "OLE32.DLL" ALIAS "OleIsCurrentClipboard" ( _
   BYVAL pDataObject AS IDataObject _                   ' __in IDataObject * pDataObject
 ) AS LONG                                              ' HRESULT


'/* InPlace Editing APIs */

DECLARE FUNCTION OleCreateMenuDescriptor IMPORT "OLE32.DLL" ALIAS "OleCreateMenuDescriptor" ( _
   BYVAL hmenuCombined AS DWORD _                       ' __in HMENU hmenuCombined
 , BYREF lpMenuWidths AS OLEMENUGROUPWIDTHS _           ' __in LPOLEMENUGROUPWIDTHS lpMenuWidths
 ) AS DWORD                                             ' HOLEMENU

DECLARE FUNCTION OleSetMenuDescriptor IMPORT "OLE32.DLL" ALIAS "OleSetMenuDescriptor" ( _
   BYVAL holemenu AS DWORD _                            ' __in HOLEMENU holemenu
 , BYVAL hwndFrame AS DWORD _                           ' __in HWND hwndFrame
 , BYVAL hwndActiveObject AS DWORD _                    ' __in HWND hwndActiveObject
 , BYVAL lpFrame AS IOleInPlaceFrame _                  ' __in LPOLEINPLACEFRAME lpFrame
 , BYVAL lpActiveObj AS IOleInPlaceActiveObject _       ' __in LPOLEINPLACEACTIVEOBJECT lpActiveObj
 ) AS LONG                                              ' HRESULT

DECLARE SUB OleDestroyMenuDescriptor IMPORT "OLE32.DLL" ALIAS "OleDestroyMenuDescriptor" ( _
   BYVAL holemenu AS DWORD _                            ' __in HOLEMENU holemenu
 )                                                      ' void

DECLARE FUNCTION OleTranslateAccelerator IMPORT "OLE32.DLL" ALIAS "OleTranslateAccelerator" ( _
   BYVAL lpFrame AS IOleInPlaceFrame _                  ' __in LPOLEINPLACEFRAME lpFrame
 , BYVAL lpFrameInfo AS OLEINPLACEFRAMEINFO _           ' __in LPOLEINPLACEFRAMEINFO lpFrameInfo
 , BYREF lpmsg AS tagMsg _                              ' __in LPMSG lpmsg
 ) AS LONG                                              ' HRESULT

'/* Helper APIs */
DECLARE FUNCTION OleDuplicateData IMPORT "OLE32.DLL" ALIAS "OleDuplicateData" ( _
   BYVAL hSrc AS DWORD _                                ' __in HANDLE hSrc
 , BYVAL cfFormat AS DWORD _                            ' __in CLIPFORMAT cfFormat
 , BYVAL uiFlags AS DWORD _                             ' __in UINT uiFlags
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OleDraw IMPORT "OLE32.DLL" ALIAS "OleDraw" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL dwAspect AS DWORD _                            ' __in DWORD dwAspect
 , BYVAL hdcDraw AS DWORD _                             ' __in HDC hdcDraw
 , BYREF lprcBounds AS RECT _                           ' __in LPCRECT lprcBounds
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleRun IMPORT "OLE32.DLL" ALIAS "OleRun" ( _
   BYVAL pUnknown AS IUnknown _                         ' __in LPUNKNOWN pUnknown
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleIsRunning IMPORT "OLE32.DLL" ALIAS "OleIsRunning" ( _
   BYVAL pObject AS IOleObject _                        ' __in LPOLEOBJECT pObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLockRunning IMPORT "OLE32.DLL" ALIAS "OleLockRunning" ( _
   BYVAL pUnknown AS IUnknown _                         ' __in LPUNKNOWN pUnknown
 , BYVAL fLock AS LONG _                                ' __in BOOL fLock
 , BYVAL fLastUnlockCloses AS LONG _                    ' __in BOOL fLastUnlockCloses
 ) AS LONG                                              ' HRESULT

DECLARE SUB ReleaseStgMedium IMPORT "OLE32.DLL" ALIAS "ReleaseStgMedium" ( _
   BYREF pmedium AS STGMEDIUM _                         ' __in STGMEDIUM * pmedium
 )                                                      ' void

DECLARE FUNCTION CreateOleAdviseHolder IMPORT "OLE32.DLL" ALIAS "CreateOleAdviseHolder" ( _
   BYREF ppOAHolder AS IOleAdviseHolder _               ' __out LPOLEADVISEHOLDER FAR* ppOAHolder
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateDefaultHandler IMPORT "OLE32.DLL" ALIAS "OleCreateDefaultHandler" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYVAL pUnkOuter AS IUnknown _                        ' __in LPUNKNOWN pUnkOuter
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR * ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateEmbeddingHelper IMPORT "OLE32.DLL" ALIAS "OleCreateEmbeddingHelper" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYVAL pUnkOuter AS IUnknown _                        ' __in LPUNKNOWN pUnkOuter
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYVAL pCF AS IClassFactory _                         ' __in LPCLASSFACTORY pCF
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out LPVOID * ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IsAccelerator IMPORT "OLE32.DLL" ALIAS "IsAccelerator" ( _
   BYVAL hAccel AS DWORD _                              ' __in HACCEL hAccel
 , BYVAL cAccelEntries AS LONG _                        ' __in INT cAccelEntries
 , BYREF lpMsg AS tagMsg _                              ' __in LPMSG lpMsg
 , BYREF lpwCmd AS WORD _                               ' __out WORD * lpwCmd
 ) AS LONG                                              ' BOOL

'/* Icon extraction Helper APIs */

DECLARE FUNCTION OleGetIconOfFile IMPORT "OLE32.DLL" ALIAS "OleGetIconOfFile" ( _
   BYREF lpszPath AS WSTRINGZ _                         ' __in LPOLESTR lpszPath
 , BYVAL fUseFileAsLabel AS LONG _                      ' __in BOOL fUseFileAsLabel
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION OleGetIconOfClass IMPORT "OLE32.DLL" ALIAS "OleGetIconOfClass" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF lpszLabel AS WSTRINGZ _                        ' __in LPOLESTR lpszLabel
 , BYVAL fUseTypeAsLabel AS LONG _                      ' __in BOOL fUseTypeAsLabel
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION OleMetafilePictFromIconAndLabel IMPORT "OLE32.DLL" ALIAS "OleMetafilePictFromIconAndLabel" ( _
   BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 , BYREF lpszLabel AS WSTRINGZ _                        ' __in LPOLESTR lpszLabel
 , BYREF lpszSourceFile AS WSTRINGZ _                   ' __in LPOLESTR lpszSourceFile
 , BYVAL iIconIndex AS DWORD _                          ' __in UINT iIconIndex
 ) AS DWORD                                             ' HGLOBAL


'/* Registration Database Helper APIs */

DECLARE FUNCTION OleRegGetUserType IMPORT "OLE32.DLL" ALIAS "OleRegGetUserType" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYVAL dwFormOfType AS DWORD _                        ' __in DWORD dwFormOfType
 , BYREF pszUserType AS DWORD _                         ' __out LPOLESTR * pszUserType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleRegGetMiscStatus IMPORT "OLE32.DLL" ALIAS "OleRegGetMiscStatus" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYVAL dwAspect AS DWORD _                            ' __in DWORD dwAspect
 , BYREF pdwStatus AS DWORD _                           ' __out DWORD * pdwStatus
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleRegEnumFormatEtc IMPORT "OLE32.DLL" ALIAS "OleRegEnumFormatEtc" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYVAL dwDirection AS DWORD _                         ' __in DWORD dwDirection
 , BYREF ppenumFormatetc AS IEnumFORMATETC _            ' __out LPENUMFORMATETC * ppenumFormatetc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleRegEnumVerbs IMPORT "OLE32.DLL" ALIAS "OleRegEnumVerbs" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYREF ppenumOleVerb AS IEnumOleVERB _                ' __out LPENUMOLEVERB * ppenumOleVerb
 ) AS LONG                                              ' HRESULT

'/* OLE 1.0 conversion APIS */

'/***** OLE 1.0 OLESTREAM declarations *************************************/

'typedef struct _OLESTREAM FAR*  LPOLESTREAM;

'typedef struct _OLESTREAMVTBL
'{
'    DWORD (CALLBACK* Get)(LPOLESTREAM, void FAR*, DWORD);
'    DWORD (CALLBACK* Put)(LPOLESTREAM, const void FAR*, DWORD);
'} OLESTREAMVTBL;
'typedef  OLESTREAMVTBL FAR*  LPOLESTREAMVTBL;

'typedef struct _OLESTREAM
'{
'    LPOLESTREAMVTBL lpstbl;
'} OLESTREAM;


DECLARE FUNCTION OleConvertOLESTREAMToIStorage IMPORT "OLE32.DLL" ALIAS "OleConvertOLESTREAMToIStorage" ( _
   BYREF lpolestream AS ANY _                           ' __in LPOLESTREAM lpolestream
 , BYREF pstg AS IStorage _                             ' __out IStorage* pstg
 , BYREF ptd AS DVTARGETDEVICE _                        ' __in const DVTARGETDEVICE* ptd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleConvertIStorageToOLESTREAM IMPORT "OLE32.DLL" ALIAS "OleConvertIStorageToOLESTREAM" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYREF lpolestream AS ANY _                           ' __out LPOLESTREAM lpolestream
 ) AS LONG                                              ' HRESULT

'/* Storage Utility APIs */

DECLARE FUNCTION GetHGlobalFromILockBytes IMPORT "OLE32.DLL" ALIAS "GetHGlobalFromILockBytes" ( _
   BYVAL pLkbyt AS ILockBytes _                         ' __in ILockBytes* pLkbyt
 , BYREF phglobal AS DWORD _                            ' __out HGLOBAL* phglobal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateILockBytesOnHGlobal IMPORT "OLE32.DLL" ALIAS "CreateILockBytesOnHGlobal" ( _
   BYVAL hGlobal AS DWORD _                             ' __in HGLOBL hGlobal
 , BYVAL fDeleteOnRelease AS LONG _                     ' __in BOOL fDeleteOnRelease
 , BYREF ppLkbyt AS ILockBytes _                        ' __out ILockBytes** ppLkbyt
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetHGlobalFromStream IMPORT "OLE32.DLL" ALIAS "GetHGlobalFromStream" ( _
   BYVAL pstm AS IStream _                              ' __in IStream* pstm
 , BYREF phglobal AS DWORD _                            ' __out HGLOBAL* phglobal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateStreamOnHGlobal IMPORT "OLE32.DLL" ALIAS "CreateStreamOnHGlobal" ( _
   BYVAL hGlobal AS DWORD _                             ' __in HGLOBL hGlobal
 , BYVAL fDeleteOnRelease AS LONG _                     ' __in BOOL fDeleteOnRelease
 , BYREF ppstm AS IStream _                             ' __out LPSTREAM* ppstm
 ) AS LONG                                              ' HRESULT

'/* ConvertTo APIS */

DECLARE FUNCTION OleDoAutoConvert IMPORT "OLE32.DLL" ALIAS "OleDoAutoConvert" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage * pStg
 , BYREF pClsidNew AS GUID _                            ' __out LPCLSID pClsidNew
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleGetAutoConvert IMPORT "OLE32.DLL" ALIAS "OleGetAutoConvert" ( _
   BYREF clsidOld AS GUID _                             ' __in REFCLSID clsidOld
 , BYREF pClsidNew AS GUID _                            ' __out LPCLSID pClsidNew
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleSetAutoConvert IMPORT "OLE32.DLL" ALIAS "OleSetAutoConvert" ( _
   BYREF clsidOld AS GUID _                             ' __in REFCLSID clsidOld
 , BYREF clsidNew AS GUID _                             ' __out REFCLSID clsidNew
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetConvertStg IMPORT "OLE32.DLL" ALIAS "GetConvertStg" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SetConvertStg IMPORT "OLE32.DLL" ALIAS "SetConvertStg" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYVAL fConvert AS LONG _                             ' __in BOOL fConvert
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleConvertIStorageToOLESTREAMEx IMPORT "OLE32.DLL" ALIAS "OleConvertIStorageToOLESTREAMEx" ( _
   BYVAL pStg AS IStorage _                             ' __in IStorage* pStg
 , BYVAL cfFormat AS DWORD _                            ' __in CLIPFORMAT cfFormat
 , BYVAL lWidth AS LONG _                               ' __in LONG lWidth
 , BYVAL lHeight AS LONG _                              ' __in LONG lHeight
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 , BYREF pmedium AS STGMEDIUM _                         ' __in STGMEDIUM pmedium
 , BYREF lpolestm AS ANY _                              ' __out LPOLESTREAM lpolestm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleConvertOLESTREAMToIStorageEx IMPORT "OLE32.DLL" ALIAS "OleConvertOLESTREAMToIStorageEx" ( _
   BYREF lpolestm AS ANY _                              ' __in LPOLESTREAM lpolestm
 , BYREF pstg AS IStorage _                             ' __out IStorage* pstg
 , BYREF pcfFormat AS DWORD _                           ' __out CLIPFORMAT* pcfFormat
 , BYREF plWidth AS LONG _                              ' __out LONG* plWidth
 , BYREF plHeight AS LONG _                             ' __out LONG* plHeight
 , BYREF pdwSize AS DWORD _                             ' __out DWORD* pdwSize
 , BYREF pmedium AS STGMEDIUM _                         ' __out STGMEDIUM pmedium
 ) AS LONG                                              ' HRESULT
