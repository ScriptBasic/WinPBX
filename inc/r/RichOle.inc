' ########################################################################################
' Microsoft Windows
' File: RichOle.inc
' Contents: OLE Extensions to the Rich Text Editor
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RICHOLE_INC = 1

#INCLUDE ONCE "richedit.inc"
#INCLUDE ONCE "oleidl.inc"

'// Structure passed to GetObject and InsertObject
' // Size = 56 bytes
TYPE REOBJECT DWORD
   cbStruct AS DWORD        ' DWORD           cbStruct  // Size of structure
   cp       AS LONG         ' LONG            cp        // Character position of object
   clsid    AS GUID         ' CLSID           clsid     // Class ID of object// Class ID of object
   poleobj  AS DWORD        ' LPOLEOBJECT     poleobj   // OLE object interface
   pstg     AS DWORD        ' LPSTORAGE       pstg      // Associated storage interface
   polesite AS DWORD        ' LPOLECLIENTSITE polesite  // Associated client site interface
   sizel    AS SIZEL        ' SIZEL           sizel     // Size of object (may be 0,0)
   dvaspect AS DWORD        ' DWORD           dvaspect  // Display aspect to use
   dwFlags  AS DWORD        ' DWORD           dwFlags   // Object status flags
   dwUser   AS DWORD        ' DWORD           dwUser    // Dword for user's use
END TYPE

'// Flags to specify which interfaces should be returned in the structure above
%REO_GETOBJ_NO_INTERFACES   = &H00000000???
%REO_GETOBJ_POLEOBJ         = &H00000001???
%REO_GETOBJ_PSTG            = &H00000002???
%REO_GETOBJ_POLESITE        = &H00000004???
%REO_GETOBJ_ALL_INTERFACES  = &H00000007???

' // Note: Although the C++ headers cast REO_CP_SELECTION, REO_IOB_SELECTION and REO_IOB_USE_CP, the
' // target is the cp member of the REOBJECT structure, which is a long, and as struct members are
' // assigned via the FPU and the value is too large to fit, the FPU assigns a masked error value instead.
' // This is the IEEE standard for the FPU.

'// Place object at selection
'%REO_CP_SELECTION    = &HFFFFFFFF???   ' ((ULONG) -1L)
%REO_CP_SELECTION    = -1&              ' ((ULONG) -1L)

'// Use character position to specify object instead of index
'%REO_IOB_SELECTION   = &HFFFFFFFF???   ' ((ULONG) -1L)
%REO_IOB_SELECTION   = -1&              ' ((ULONG) -1L)
'%REO_IOB_USE_CP      = &HFFFFFFFE???   ' ((ULONG) -2L)
%REO_IOB_USE_CP      = -2&              ' ((ULONG) -2L)

'// Object flags
%REO_NULL            = &H00000000???   ' // No flags
%REO_READWRITEMASK   = &H0000003F???   ' // Mask out RO bits
%REO_DONTNEEDPALETTE = &H00000020???   ' // Object doesn't need palette
%REO_BLANK           = &H00000010???   ' // Object is blank
%REO_DYNAMICSIZE     = &H00000008???   ' // Object defines size always
%REO_INVERTEDSELECT  = &H00000004???   ' // Object drawn all inverted if sel
%REO_BELOWBASELINE   = &H00000002???   ' // Object sits below the baseline
%REO_RESIZABLE       = &H00000001???   ' // Object may be resized
%REO_LINK            = &H80000000???   ' // Object is a link (RO)
%REO_STATIC          = &H40000000???   ' // Object is static (RO)
%REO_SELECTED        = &H08000000???   ' // Object selected (RO)
%REO_OPEN            = &H04000000???   ' // Object open in its server (RO)
%REO_INPLACEACTIVE   = &H02000000???   ' // Object in place active (RO)
%REO_HILITED         = &H01000000???   ' // Object is to be hilited (RO)
%REO_LINKAVAILABLE   = &H00800000???   ' // Link believed available (RO)
%REO_GETMETAFILE     = &H00400000???   ' // Object requires metafile (RO)

'// flags for IRichEditOle::GetClipboardData(),
'// IRichEditOleCallback::GetClipboardData() and
'// IRichEditOleCallback::QueryAcceptData()
%RECO_PASTE          = &H00000000???           ' // paste from clipboard
%RECO_DROP           = &H00000001???           ' // drop
%RECO_COPY           = &H00000002???           ' // copy to the clipboard
%RECO_CUT            = &H00000003???           ' // cut to the clipboard
%RECO_DRAG           = &H00000004???           ' // drag

'// RichEdit interface GUIDs
$IID_IRichEditOle         = GUID$("{00020D00-0000-0000-C000-000000000046}")
$IID_IRichEditOleCallback = GUID$("{00020D03-0000-0000-C000-000000000046}")

' ########################################################################################
' IRichEditOle interface
' IID = 00020D00-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

'/*
' *   IRichEditOle
' *
' *   Purpose:
' *      Interface used by the client of RichEdit to perform OLE-related
' *      operations.
' *
' *   //$ REVIEW:
' *      The methods herein may just want to be regular Windows messages.
' */

INTERFACE IRichEditOle $IID_IRichEditOle

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClientSite ( _                             ' VTable offset = 12
     BYREF lplpolesite AS IOleClientSite _              ' __out LPOLECLIENTSITE *lplpolesite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectCount ( _                            ' VTable offset = 16
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD GetLinkCount ( _                              ' VTable offset = 20
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 24
     BYVAL iob AS LONG _                                ' __in  LONG iob
   , BYREF lpreobject AS REOBJECT _                     ' __out REOBJECT *lpreobject
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertObject ( _                              ' VTable offset = 28
     BYREF lpreobject AS REOBJECT _                     ' __in REOBJECT *lpreobject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertObject ( _                             ' VTable offset = 32
     BYVAL iob AS LONG _                                ' __in  LONG iob
   , BYREF rclsidNew AS GUID _                          ' __in  REFCLSID rclsidNew
   , BYREF lpstrUserTypeNew AS ASCIIZ _                 ' __in LPCSTR lpstrUserTypeNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateAs ( _                                ' VTable offset = 36
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF rclsidAs AS GUID _                           ' __in REFCLSID rclsidAs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHostNames ( _                              ' VTable offset = 40
     BYREF lpstrContainerApp AS ASCIIZ _                ' __in LPCSTR lpstrContainerApp
   , BYREF lpstrContainerObj AS ASCIIZ _                ' __in LPCSTR lpstrContainerObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLinkAvailable ( _                          ' VTable offset = 44
     BYVAL iob AS LONG _                                ' __in LONG iob
   , BYVAL fAvailable AS LONG _                         ' __in BOOL fAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDvaspect ( _                               ' VTable offset = 48
     BYVAL iob AS LONG _                                ' __in LONG iob
   , BYVAL dvaspect AS LONG _                           ' __in DWORD dvaspect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffStorage ( _                           ' VTable offset = 52
     BYVAL iob AS LONG _                                ' __in LONG iob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCompleted ( _                             ' VTable offset = 56
     BYVAL iob AS LONG _                                ' __in LONG iob
   , BYVAL lpstg AS IStorage _                          ' __in LPSTORAGE lpstg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InPlaceDeactivate ( _                         ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 64
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipboardData ( _                          ' VTable offset = 68
     BYREF lpchrg AS CHARRANGE _                        ' __in  CHARRANGE *lpchrg
   , BYVAL reco AS DWORD _                              ' __in  DWORD reco
   , BYREF lplpdataobj AS IDataObject _                 ' __out LPDATAOBJECT *lplpdataobj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ImportDataObject ( _                          ' VTable offset = 72
     BYVAL lpdataobj AS IDataObject _                   ' __in LPDATAOBJECT lpdataobj
   , BYVAL cf AS DWORD _                                ' __in CLIPFORMAT cf
   , BYVAL hMetaPict AS DWORD _                         ' __in HGLOBAL hMetaPict
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IRichEditOleCallback interface
' IID = 00020D03-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

'/*
' *   IRichEditOleCallback
' *
' *   Purpose:
' *      Interface used by the RichEdit to get OLE-related stuff from the
' *      application using RichEdit.
' */

INTERFACE IRichEditOleCallback $IID_IRichEditOleCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNewStorage ( _                             ' VTable offset = 12
     BYREF lplpstg AS IStorage _                        ' __out LPSTORAGE *lplpstg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInPlaceContext ( _                         ' VTable offset = 16
     BYREF lplpFrame AS IOleInPlaceFrame _              ' __out LPOLEINPLACEFRAME *lplpFrame
   , BYREF lplpDoc AS IOleInPlaceUIWindow _             ' __out LPOLEINPLACEUIWINDOW *lplpDoc
   , BYREF lpFrameInfo AS OLEINPLACEFRAMEINFO _         ' __out LPOLEINPLACEFRAMEINFO lpFrameInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowContainerUI ( _                           ' VTable offset = 20
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInsertObject ( _                         ' VTable offset = 24
     BYREF lpclsid AS GUID _                            ' __in LPCLSID lpclsid
   , BYVAL lpstg AS IStorage _                          ' __in LPSTORAGE lpstg
   , BYVAL cp AS LONG _                                 ' __in LONG cp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteObject ( _                              ' VTable offset = 28
     BYVAL lpoleobj AS IDataObject _                    ' __in LPOLEOBJECT lpoleobj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAcceptData ( _                           ' VTable offset = 32
     BYVAL lpdataobj AS IDataObject _                   ' __in LPDATAOBJECT lpdataobj
   , BYREF lpcfFormat AS DWORD _                        ' __in_out CLIPFORMAT *lpcfFormat
   , BYVAL reco AS DWORD _                              ' __in DWORD reco
   , BYVAL fReally AS LONG _                            ' __in BOOL fReally
   , BYVAL hMetaPict AS DWORD _                         ' __in HGLOBAL hMetaPict
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 36
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipboardData ( _                          ' VTable offset = 40
     BYREF lpchrg AS CHARRANGE _                        ' __in CHARRANGE *lpchrg
   , BYVAL reco AS DWORD _                              ' __in DWORD reco
   , BYREF lplpdataobj AS IDataObject _                 ' LPDATAOBJECT *lplpdataobj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDragDropEffect ( _                         ' VTable offset = 44
     BYVAL fDrag AS LONG _                              ' __in  BOOL fDrag
   , BYVAL grfKeyState AS DWORD _                       ' __in  DWORD grfKeyState
   , BYREF pdwEffect AS DWORD _                         ' __out LPDWORD pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextMenu ( _                            ' VTable offset = 48
     BYVAL seltype AS WORD _                            ' __in  WORD seltype
   , BYVAL lpoleobj AS IDataObject _                    ' __in  LPOLEOBJECT lpoleobj
   , BYREF lpchrg AS CHARRANGE _                        ' __in  CHARRANGE *lpchrg
   , BYREF lphmenu AS DWORD _                           ' __out HMENU *lphmenu
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
