' ########################################################################################
' Microsoft Windows
' File: TextServ.inc
' Contents: Define interfaces between the Text Services component and the host
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' NOTE: The ITextServices and ITextHost interfaces are unusable with PB direct interface
' support because they use C++ thiscall convention instead of stdcall. The thiscall convention
' is like stdcall except that the "this" parameter is passed in the ECX register instead of
' at the top of the stack. Therefore, the use of assembler is required.

#INCLUDE THIS ONCE
%TEXTSERV_INC = 1

#INCLUDE ONCE "richedit.inc"
#INCLUDE ONCE "objidl.inc"

'EXTERN_C const IID IID_ITextServices;
'EXTERN_C const IID IID_ITextHost;

$IID_ITextServices = GUID$("{8D33F740-CF58-11CE-A89D-00AA006CADC5}")
'$IID_ITextHost     = GUID$("{C5BDD8D0-D26E-11CE-A89E-00AA006CADC5}")
' // Note: The above guid is incorrect. This one is the one really exported.
$IID_ITextHost     = GUID$("{13E670F4-1A5A-11CE-ABEB-00AA00B65EA1}")
' // The following one is the IID for the undocumented ITextHost2 interface.
$IID_ITextHost2    = GUID$("{13E670F5-1A5A-11CE-ABEB-00AA00B65EA1}")

'// Note: error code is first outside of range reserved for OLE.
'#define S_MSG_KEY_IGNORED \
'   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0x201)
%S_MSG_KEY_IGNORED = &H00040201???

'// Enums used by property methods

'/*
' *   TXTBACKSTYLE
' *
' *   @enum   Defines different background styles control
' */
' enum TXTBACKSTYLE
%TXTBACK_TRANSPARENT = 0    ' //@emem   background should show through
%TXTBACK_OPAQUE      = 1    ' //@emem   erase background

'/*
' *   TXTHITRESULT
' *
' *   @enum   Defines different hitresults
' */
' enum TXTHITRESULT
%TXTHITRESULT_NOHIT       = 0   ' //@emem   no hit
%TXTHITRESULT_TRANSPARENT = 1   ' //@emem point is within the text's rectangle, but
                                ' //in a transparent region
%TXTHITRESULT_CLOSE       = 2   ' //@emem   point is close to the text
%TXTHITRESULT_HIT         = 3   ' //@emem dead-on hit

'/*
' *   TXTNATURALSIZE
' *
' *   @enum   useful values for TxGetNaturalSize.
' *
'  *   @xref <mf CTxtEdit::TxGetNaturalSize>
' */
' enum TXTNATURALSIZE
%TXTNS_FITTOCONTENT     = 1   ' //@emem   Get a size that fits the content
%TXTNS_ROUNDTOLINE      = 2   ' //@emem Round to the nearest whole line.

'/*
' *   TXTVIEW
' *
' *   @enum   useful values for TxDraw lViewId parameter
' *
'  *   @xref <mf CTxtEdit::TxDraw>
' */
' enum TXTVIEW
%TXTVIEW_ACTIVE   = 0
%TXTVIEW_INACTIVE = -1

'/*
' *   CHANGETYPE
' *
' *   @enum   used for CHANGENOTIFY.dwChangeType; indicates what happened
' *         for a particular change.
' */
' enum CHANGETYPE
%CN_GENERIC      = 0           ' //@emem Nothing special happened
%CN_TEXTCHANGED  = 1           ' //@emem the text changed
%CN_NEWUNDO      = 2           ' //@emem   A new undo action was added
%CN_NEWREDO      = 4           ' //@emem A new redo action was added

'/*
' *   @struct CHANGENOTIFY  |
' *
' *   passed during an EN_CHANGE notification; contains information about
' *   what actually happened for a change.
' */
' // Size = 8 bytes
TYPE CHANGENOTIFY DWORD
   dwChangeType AS DWORD   ' DWORD  //@field TEXT changed, etc
   pvCookieData AS DWORD   ' void * //@field cookie for the undo action
                           '        // associated with the change.
END TYPE

'// The TxGetPropertyBits and OnTxPropertyBitsChange methods can pass the following bits:

'// NB!!! Do NOT rely on the ordering of these bits yet; the are subject
'// to change.
%TXTBIT_RICHTEXT         = 1          ' // rich-text control
%TXTBIT_MULTILINE        = 2          ' // single vs multi-line control
%TXTBIT_READONLY         = 4          ' // read only text
%TXTBIT_SHOWACCELERATOR  = 8          ' // underline accelerator character
%TXTBIT_USEPASSWORD      = &H10       ' // use password char to display text
%TXTBIT_HIDESELECTION    = &H20       ' // show selection when inactive
%TXTBIT_SAVESELECTION    = &H40       ' // remember selection when inactive
%TXTBIT_AUTOWORDSEL      = &H80       ' // auto-word selection
%TXTBIT_VERTICAL         = &H100      ' // vertical
%TXTBIT_SELBARCHANGE     = &H200      ' // notification that the selection bar width
                                      ' // has changed.
                                      ' // FUTURE: move this bit to the end to
                                      ' // maintain the division between
                                      ' // properties and notifications.
%TXTBIT_WORDWRAP         = &H400      ' // if set, then multi-line controls
                                      ' // should wrap words to fit the available
                                      ' // display
%TXTBIT_ALLOWBEEP        = &H800      ' // enable/disable beeping
%TXTBIT_DISABLEDRAG      = &H1000     ' // disable/enable dragging
%TXTBIT_VIEWINSETCHANGE  = &H2000     ' // the inset changed
%TXTBIT_BACKSTYLECHANGE  = &H4000
%TXTBIT_MAXLENGTHCHANGE  = &H8000
%TXTBIT_SCROLLBARCHANGE  = &H10000
%TXTBIT_CHARFORMATCHANGE = &H20000
%TXTBIT_PARAFORMATCHANGE = &H40000
%TXTBIT_EXTENTCHANGE     = &H80000
%TXTBIT_CLIENTRECTCHANGE = &H100000   ' // the client rectangle changed
%TXTBIT_USECURRENTBKG    = &H200000   ' // tells the renderer to use the current background
                                      ' // color rather than the system default for an entire line

'/*
' *   ITextServices
' *
' *    @class   An interface extending Microsoft's Text Object Model to provide
' *         extra functionality for windowless operation.  In conjunction
' *         with ITextHost, ITextServices provides the means by which the
' *         the RichEdit control can be used *without* creating a window.
' *
' *   @base   public | IUnknown
' */
'class ITextServices : public IUnknown
'{
'public:

'   //@cmember Generic Send Message interface
'   virtual HRESULT    TxSendMessage(
'                     UINT msg,
'                     WPARAM wparam,
'                     LPARAM lparam,
'                     LRESULT *plresult) = 0;

'   //@cmember Rendering
'   virtual HRESULT      TxDraw(
'                     DWORD dwDrawAspect,
'                     LONG  lindex,
'                     void * pvAspect,
'                     DVTARGETDEVICE * ptd,
'                     HDC hdcDraw,
'                     HDC hicTargetDev,
'                     LPCRECTL lprcBounds,
'                     LPCRECTL lprcWBounds,
'                           LPRECT lprcUpdate,
'                     BOOL (CALLBACK * pfnContinue) (DWORD),
'                     DWORD dwContinue,
'                     LONG lViewId) = 0;

'   //@cmember Horizontal scrollbar support
'   virtual HRESULT      TxGetHScroll(
'                     LONG *plMin,
'                     LONG *plMax,
'                     LONG *plPos,
'                     LONG *plPage,
'                     BOOL * pfEnabled ) = 0;

'      //@cmember Horizontal scrollbar support
'   virtual HRESULT      TxGetVScroll(
'                     LONG *plMin,
'                     LONG *plMax,
'                     LONG *plPos,
'                     LONG *plPage,
'                     BOOL * pfEnabled ) = 0;

'   //@cmember Setcursor
'   virtual HRESULT    OnTxSetCursor(
'                     DWORD dwDrawAspect,
'                     LONG  lindex,
'                     void * pvAspect,
'                     DVTARGETDEVICE * ptd,
'                     HDC hdcDraw,
'                     HDC hicTargetDev,
'                     LPCRECT lprcClient,
'                     INT x,
'                     INT y) = 0;

'   //@cmember Hit-test
'   virtual HRESULT    TxQueryHitPoint(
'                     DWORD dwDrawAspect,
'                     LONG  lindex,
'                     void * pvAspect,
'                     DVTARGETDEVICE * ptd,
'                     HDC hdcDraw,
'                     HDC hicTargetDev,
'                     LPCRECT lprcClient,
'                     INT x,
'                     INT y,
'                     DWORD * pHitResult) = 0;

'   //@cmember Inplace activate notification
'   virtual HRESULT      OnTxInPlaceActivate(LPCRECT prcClient) = 0;

'   //@cmember Inplace deactivate notification
'   virtual HRESULT      OnTxInPlaceDeactivate() = 0;

'   //@cmember UI activate notification
'   virtual HRESULT      OnTxUIActivate() = 0;

'   //@cmember UI deactivate notification
'   virtual HRESULT      OnTxUIDeactivate() = 0;

'   //@cmember Get text in control
'   virtual HRESULT      TxGetText(BSTR *pbstrText) = 0;

'   //@cmember Set text in control
'   virtual HRESULT      TxSetText(LPCWSTR pszText) = 0;

'   //@cmember Get x position of
'   virtual HRESULT      TxGetCurTargetX(LONG *) = 0;
'   //@cmember Get baseline position
'   virtual HRESULT      TxGetBaseLinePos(LONG *) = 0;

'   //@cmember Get Size to fit / Natural size
'   virtual HRESULT      TxGetNaturalSize(
'                     DWORD dwAspect,
'                     HDC hdcDraw,
'                     HDC hicTargetDev,
'                     DVTARGETDEVICE *ptd,
'                     DWORD dwMode,
'                     const SIZEL *psizelExtent,
'                     LONG *pwidth,
'                     LONG *pheight) = 0;

'   //@cmember Drag & drop
'   virtual HRESULT      TxGetDropTarget( IDropTarget **ppDropTarget ) = 0;

'   //@cmember Bulk bit property change notifications
'   virtual HRESULT      OnTxPropertyBitsChange(DWORD dwMask, DWORD dwBits) = 0;

'   //@cmember Fetch the cached drawing size
'   virtual   HRESULT      TxGetCachedSize(DWORD *pdwWidth, DWORD *pdwHeight)=0;
'};

'INTERFACE ITextServices $IID_ITextServices

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD TxSendMessage ( _                             ' VTable offset = 12
'     BYVAL msg AS DWORD _                               ' __in  UINT     msg
'   , BYVAL wparam AS DWORD _                            ' __in  WPARAM   wparam
'   , BYVAL lparam AS LONG _                             ' __in  LPARAM   lparam
'   , BYREF plresult AS LONG _                           ' __out LRESULT *plresult
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxDraw ( _                                    ' VTable offset = 16
'     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
'   , BYVAL lindex AS LONG _                             ' __in LONG lindex
'   , BYVAL pvAspect AS DWORD _                          ' __in void * pvAspect
'   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE * ptd
'   , BYVAL hdcDraw AS DWORD _                           ' __in HDC hdcDraw
'   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
'   , BYREF lprcBounds AS RECTL _                        ' __in LPCRECTL lprcBounds
'   , BYREF lprcWBounds AS RECTL _                       ' __in LPCRECTL lprcWBounds
'   , BYREF lprcUpdate AS RECT _                         ' __in LPRECT lprcUpdate
'   , BYVAL pfnContinue AS DWORD _                       ' __in BOOL (CALLBACK * pfnContinue) (DWORD)
'   , BYVAL dwContinue AS DWORD _                        ' __in DWORD dwContinue
'   , BYVAL lViewId AS LONG _                            ' __in LONG lViewId
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetHScroll ( _                              ' VTable offset = 20
'     BYREF plMin AS LONG _                              ' __out LONG *plMin
'   , BYREF plMax AS LONG _                              ' __out LONG *plMax
'   , BYREF plPos AS LONG _                              ' __out LONG *plPos
'   , BYREF plPage AS LONG _                             ' __out LONG *plPage
'   , BYREF pfEnabled AS LONG _                          ' __out BOOL *pfEnabled
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetVScroll ( _                              ' VTable offset = 24
'     BYREF plMin AS LONG _                              ' __out LONG *plMin
'   , BYREF plMax AS LONG _                              ' __out LONG *plMax
'   , BYREF plPos AS LONG _                              ' __out LONG *plPos
'   , BYREF plPage AS LONG _                             ' __out LONG *plPage
'   , BYREF pfEnabled AS LONG _                          ' __out BOOL *pfEnabled
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxSetCursor ( _                             ' VTable offset = 28
'     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
'   , BYVAL lindex AS LONG _                             ' __in LONG lindex
'   , BYVAL pvAspect AS DWORD _                          ' __in void * pvAspect
'   , BYREF DVTARGETDEVICE _                             ' __in DVTARGETDEVICE * ptd
'   , BYVAL ptd AS DWORD _                               ' __in HDC hdcDraw
'   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
'   , BYREF lprcClient AS RECT _                         ' __in LPCRECT lprcClient
'   , BYVAL x AS LONG _                                  ' __in INT x
'   , BYVAL y AS LONG _                                  ' __in INT y
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxQueryHitPoint ( _                           ' VTable offset = 32
'     BYVAL dwDrawAspect AS DWORD _                      ' __in DWORD dwDrawAspect
'   , BYVAL lindex AS LONG _                             ' __in LONG lindex
'   , BYVAL pvAspect AS DWORD _                          ' __in void * pvAspect
'   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE * ptd
'   , BYVAL hdcDraw AS DWORD _                           ' __in HDC hdcDraw
'   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
'   , BYREF lprcClient AS RECT _                         ' __in LPCRECT lprcClient
'   , BYVAL x AS LONG _                                  ' __in INT x
'   , BYVAL y AS LONG _                                  ' __in INT y
'   , BYREF pHitResult AS DWORD _                        ' __out DWORD * pHitResult
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxInPlaceActivate ( _                       ' VTable offset = 36
'     BYREF prcClient AS RECT _                          ' __in LPCRECT prcClient
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxInPlaceDeactivate ( _                     ' VTable offset = 40
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxUIActivate ( _                            ' VTable offset = 44
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxUIDeactivate ( _                          ' VTable offset = 48
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetText ( _                                 ' VTable offset = 52
'     BYREF pbstrText AS WSTRING _                       ' __out BSTR *pbstrText
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxSetText ( _                                 ' VTable offset = 56
'     BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetCurTargetX ( _                           ' VTable offset = 60
'     BYREF px AS LONG _                                 ' __out LONG *px
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetBaseLinePos ( _                          ' VTable offset = 64
'     BYREF pBaseLinePos AS LONG _                       ' __out LONG *pBaseLinePos
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetNaturalSize ( _                          ' VTable offset = 68
'     BYVAL dwAspect AS DWORD _                          ' __in DWORD dwAspect
'   , BYVAL hdcDraw AS DWORD _                           ' __in HDC hdcDraw
'   , BYVAL hicTargetDev AS DWORD _                      ' __in HDC hicTargetDev
'   , BYREF ptd AS DVTARGETDEVICE _                      ' __in DVTARGETDEVICE *ptd
'   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
'   , BYREF psizelExtent AS SIZEL _                      ' __in const SIZEL *psizelExtent
'   , BYREF pwidth AS LONG _                             ' __out LONG *pwidth
'   , BYREF pheight AS LONG _                            ' __out LONG *pheight
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetDropTarget ( _                           ' VTable offset = 72
'     BYREF ppDropTarget AS IDropTarget _                ' __out IDropTarget **ppDropTarget
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxPropertyBitsChange ( _                    ' VTable offset = 76
'     BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
'   , BYVAL dwBits AS DWORD _                            ' __in DWORD dwBits
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetCachedSize ( _                           ' VTable offset = 80
'     BYREF pdwWidth AS DWORD _                          ' __out DWORD *pdwWidth
'   , BYREF pdwHeight AS DWORD _                         ' __out DWORD *pdwHeight
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'/*
' *   ITextHost
' *
' *    @class   Interface to be used by text services to obtain text host services
' *
' *   @base   public | IUnknown
' */
'class ITextHost : public IUnknown
'{
'public:

'   //@cmember Get the DC for the host
'   virtual HDC       TxGetDC() = 0;

'   //@cmember Release the DC gotten from the host
'   virtual INT         TxReleaseDC(HDC hdc) = 0;

'   //@cmember Show the scroll bar
'   virtual BOOL       TxShowScrollBar(INT fnBar, BOOL fShow) = 0;

'   //@cmember Enable the scroll bar
'   virtual BOOL       TxEnableScrollBar (INT fuSBFlags, INT fuArrowflags) = 0;

'   //@cmember Set the scroll range
'   virtual BOOL       TxSetScrollRange(
'                     INT fnBar,
'                     LONG nMinPos,
'                     INT nMaxPos,
'                     BOOL fRedraw) = 0;

'   //@cmember Set the scroll position
'   virtual BOOL       TxSetScrollPos (INT fnBar, INT nPos, BOOL fRedraw) = 0;

'   //@cmember InvalidateRect
'   virtual void      TxInvalidateRect(LPCRECT prc, BOOL fMode) = 0;

'   //@cmember Send a WM_PAINT to the window
'   virtual void       TxViewChange(BOOL fUpdate) = 0;

'   //@cmember Create the caret
'   virtual BOOL      TxCreateCaret(HBITMAP hbmp, INT xWidth, INT yHeight) = 0;

'   //@cmember Show the caret
'   virtual BOOL      TxShowCaret(BOOL fShow) = 0;

'   //@cmember Set the caret position
'   virtual BOOL      TxSetCaretPos(INT x, INT y) = 0;

'   //@cmember Create a timer with the specified timeout
'   virtual BOOL       TxSetTimer(UINT idTimer, UINT uTimeout) = 0;

'   //@cmember Destroy a timer
'   virtual void       TxKillTimer(UINT idTimer) = 0;

'   //@cmember Scroll the content of the specified window's client area
'   virtual void      TxScrollWindowEx (
'                     INT dx,
'                     INT dy,
'                     LPCRECT lprcScroll,
'                     LPCRECT lprcClip,
'                     HRGN hrgnUpdate,
'                     LPRECT lprcUpdate,
'                     UINT fuScroll) = 0;

'   //@cmember Get mouse capture
'   virtual void      TxSetCapture(BOOL fCapture) = 0;

'   //@cmember Set the focus to the text window
'   virtual void      TxSetFocus() = 0;

'   //@cmember Establish a new cursor shape
'   virtual void    TxSetCursor(HCURSOR hcur, BOOL fText) = 0;

'   //@cmember Converts screen coordinates of a specified point to the client coordinates
'   virtual BOOL       TxScreenToClient (LPPOINT lppt) = 0;

'   //@cmember Converts the client coordinates of a specified point to screen coordinates
'   virtual BOOL      TxClientToScreen (LPPOINT lppt) = 0;

'   //@cmember Request host to activate text services
'   virtual HRESULT      TxActivate( LONG * plOldState ) = 0;

'   //@cmember Request host to deactivate text services
'      virtual HRESULT      TxDeactivate( LONG lNewState ) = 0;

'   //@cmember Retrieves the coordinates of a window's client area
'   virtual HRESULT      TxGetClientRect(LPRECT prc) = 0;

'   //@cmember Get the view rectangle relative to the inset
'   virtual HRESULT      TxGetViewInset(LPRECT prc) = 0;

'   //@cmember Get the default character format for the text
'   virtual HRESULT    TxGetCharFormat(const CHARFORMATW **ppCF ) = 0;

'   //@cmember Get the default paragraph format for the text
'   virtual HRESULT      TxGetParaFormat(const PARAFORMAT **ppPF) = 0;

'   //@cmember Get the background color for the window
'   virtual COLORREF   TxGetSysColor(int nIndex) = 0;

'   //@cmember Get the background (either opaque or transparent)
'   virtual HRESULT      TxGetBackStyle(TXTBACKSTYLE *pstyle) = 0;

'   //@cmember Get the maximum length for the text
'   virtual HRESULT      TxGetMaxLength(DWORD *plength) = 0;

'   //@cmember Get the bits representing requested scroll bars for the window
'   virtual HRESULT      TxGetScrollBars(DWORD *pdwScrollBar) = 0;

'   //@cmember Get the character to display for password input
'   virtual HRESULT      TxGetPasswordChar(TCHAR *pch) = 0;

'   //@cmember Get the accelerator character
'   virtual HRESULT      TxGetAcceleratorPos(LONG *pcp) = 0;

'   //@cmember Get the native size
'    virtual HRESULT      TxGetExtent(LPSIZEL lpExtent) = 0;

'   //@cmember Notify host that default character format has changed
'   virtual HRESULT    OnTxCharFormatChange (const CHARFORMATW * pcf) = 0;

'   //@cmember Notify host that default paragraph format has changed
'   virtual HRESULT      OnTxParaFormatChange (const PARAFORMAT * ppf) = 0;

'   //@cmember Bulk access to bit properties
'   virtual HRESULT      TxGetPropertyBits(DWORD dwMask, DWORD *pdwBits) = 0;

'   //@cmember Notify host of events
'   virtual HRESULT      TxNotify(DWORD iNotify, void *pv) = 0;

'   // Far East Methods for getting the Input Context
'//#ifdef WIN95_IME
'   virtual HIMC      TxImmGetContext() = 0;
'   virtual void      TxImmReleaseContext( HIMC himc ) = 0;
'//#endif

'   //@cmember Returns HIMETRIC size of the control bar.
'   virtual HRESULT      TxGetSelectionBarWidth (LONG *lSelBarWidth) = 0;

'};

'INTERFACE ITextHost $IID_ITextHost

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD TxGetDC ( _                                   ' VTable offset = 12
'   ) AS DWORD                                           ' HDC
'   ' =====================================================================================
'   METHOD TxReleaseDC ( _                               ' VTable offset = 16
'     BYVAL hdc AS DWORD _                               ' __in HDC hdc
'   ) AS LONG                                            ' INT
'   ' =====================================================================================
'   METHOD TxShowScrollBar ( _                           ' VTable offset = 20
'     BYVAL fnBar AS LONG _                              ' __in INT fnBar
'   , BYVAL fShow AS LONG _                              ' __in BOOL fShow
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxEnableScrollBar ( _                         ' VTable offset = 24
'     BYVAL fuSBFlags AS LONG _                          ' __in INT fuSBFlags
'   , BYVAL fuArrowflags AS LONG _                       ' __in INT fuArrowflags
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxSetScrollRange ( _                          ' VTable offset = 28
'     BYVAL fnBar AS LONG _                              ' __in INT fnBar
'   , BYVAL nMinPos AS LONG _                            ' __in LONG nMinPos
'   , BYVAL nMaxPos AS LONG _                            ' __in INT nMaxPos
'   , BYVAL fRedraw AS LONG _                            ' __in BOOL fRedraw
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxSetScrollPos ( _                            ' VTable offset = 32
'     BYVAL fnBar AS LONG _                              ' __in INT fnBar
'   , BYVAL nPos AS LONG _                               ' __in INT nPos
'   , BYVAL fRedraw AS LONG _                            ' __in BOOL fRedraw
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxInvalidateRect ( _                          ' VTable offset = 36
'     BYREF prc AS RECT _                                ' __in LPCRECT prc
'   , BYVAL fMode AS LONG _                              ' __in BOOL fMode
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxViewChange ( _                              ' VTable offset = 40
'     BYVAL fUpdate AS LONG _                            ' __in BOOL fUpdate
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxCreateCaret ( _                             ' VTable offset = 44
'     BYVAL hbmp AS DWORD _                              ' __in HBITMAP hbmp
'   , BYVAL xWidth AS LONG _                             ' __in INT xWidth
'   , BYVAL yHeight AS LONG _                            ' __in INT yHeight
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxShowCaret ( _                               ' VTable offset = 48
'     BYVAL fShow AS LONG _                              ' __in BOOL fShow
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxSetCaretPos ( _                             ' VTable offset = 52
'     BYVAL x AS LONG _                                  ' __in INT x
'   , BYVAL y AS LONG _                                  ' __in INT y
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxSetTimer ( _                                ' VTable offset = 56
'     BYVAL idTimer AS DWORD _                           ' __in UINT idTimer
'   , BYVAL uTimeout AS DWORD _                          ' __in UINT uTimeout
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxKillTimer ( _                               ' VTable offset = 60
'     BYVAL idTimer AS DWORD _                           ' __in UINT idTimer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxScrollWindowEx ( _                          ' VTable offset = 64
'     BYVAL dx AS LONG _                                 ' __in INT dx
'   , BYVAL dy AS LONG _                                 ' __in INT dy
'   , BYREF lprcScroll AS RECT _                         ' __in LPCRECT lprcScroll
'   , BYREF lprcClip AS RECT _                           ' __in LPCRECT lprcClip
'   , BYVAL hrgnUpdate AS DWORD _                        ' __in HRGN hrgnUpdate
'   , BYREF lprcUpdate AS RECT _                         ' __in LPRECT lprcUpdate
'   , BYVAL fuScroll AS DWORD _                          ' __in UINT fuScroll
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxSetCapture ( _                              ' VTable offset = 68
'     BYVAL fCapture AS LONG _                           ' __in BOOL fCapture
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxSetFocus ( _                                ' VTable offset = 72
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxSetCursor ( _                               ' VTable offset = 76
'     BYVAL hcur AS DWORD _                              ' __in HCURSOR hcur
'   , BYVAL fText AS LONG _                              ' __in BOOL fText
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxScreenToClient ( _                          ' VTable offset = 80
'     BYREF lppt AS POINT _                              ' __in LPPOINT lppt
'   ) AS LONG                                            ' BOOL
'   ' =====================================================================================
'   METHOD TxActivate ( _                                ' VTable offset = 84
'     BYREF plOldState AS LONG _                         ' __out LONG * plOldState
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxDeactivate ( _                              ' VTable offset = 88
'     BYVAL lNewState AS LONG _                          ' __in LONG lNewState
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetClientRect ( _                           ' VTable offset = 92
'     BYREF prc AS RECT _                                ' __out LPRECT prc
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetViewInset ( _                            ' VTable offset = 96
'     BYREF prc AS RECT _                                ' __out LPRECT prc
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetCharFormat ( _                           ' VTable offset = 100
'     BYREF ppCF AS CHARFORMATW _                        ' __out const CHARFORMATW **ppCF
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetParaFormat ( _                           ' VTable offset = 104
'     BYREF ppPF AS PARAFORMAT _                         ' __out const PARAFORMAT **ppPF
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetSysColor ( _                             ' VTable offset = 108
'     BYVAL nIndex AS LONG _                             ' __in int nIndex
'   ) AS DWORD                                           ' COLORREF
'   ' =====================================================================================
'   METHOD TxGetBackStyle ( _                            ' VTable offset = 112
'     BYREF pstyle AS DWORD _                            ' __out TXTBACKSTYLE *pstyle
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetMaxLength ( _                            ' VTable offset = 116
'     BYREF plength AS DWORD _                           ' __out DWORD *plength
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetScrollBars ( _                           ' VTable offset = 120
'     BYREF pdwScrollBar AS DWORD _                      ' __out DWORD *pdwScrollBar
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetPasswordChar ( _                         ' VTable offset = 124
'     BYREF pch AS WORD _                                ' __out TCHAR *pch
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetAcceleratorPos ( _                       ' VTable offset = 128
'     BYREF pcp AS LONG _                                ' __out LONG *pcp
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetExtent ( _                               ' VTable offset = 132
'     BYREF lpExtent AS SIZEL _                          ' __out LPSIZEL lpExtent
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxCharFormatChange ( _                      ' VTable offset = 136
'     BYREF pcf AS CHARFORMATW _                         ' __out const CHARFORMATW * pcf
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnTxParaFormatChange ( _                      ' VTable offset = 140
'     BYREF ppf AS PARAFORMAT _                          ' __out const PARAFORMAT * ppf
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxGetPropertyBits ( _                         ' VTable offset = 144
'     BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
'   , BYREF pdwBits AS DWORD _                           ' __out DWORD *pdwBits
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxNotify ( _                                  ' VTable offset = 148
'     BYVAL iNotify AS DWORD _                           ' __in DWORD iNotify
'   , BYVAL pv AS DWORD _                                ' __in void *pv
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TxImmGetContext ( _                           ' VTable offset = 152
'   ) AS DWORD                                           ' HIMC
'   ' =====================================================================================
'   METHOD TxImmReleaseContext ( _                       ' VTable offset = 156
'     BYVAL himc AS DWORD _                              ' __in HIMC himc
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD TxGetSelectionBarWidth ( _                    ' VTable offset = 160
'     BYREF lSelBarWidth AS LONG _                       ' __out LONG *lSelBarWidth
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'//+-----------------------------------------------------------------------
'//    Factories
'//------------------------------------------------------------------------

'// Text Services factory
'STDAPI CreateTextServices(
'   IUnknown *punkOuter,
'   ITextHost *pITextHost,
'   IUnknown **ppUnk);

'DECLARE FUNCTION CreateTextServices IMPORT "msftedit.dll" ALIAS "CreateTextServices" ( _
'   BYVAL punkOuter AS IUnknown _                        ' __in  IUnknown *punkOuter
' , BYVAL pITextHost AS ITextHost _                      ' __in  ITextHost *pITextHost
' , BYREF ppUnk AS IUnknown _                            ' __out IUnknown **ppUnk
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (STDAPICALLTYPE * PCreateTextServices)(
'   IUnknown *punkOuter,
'   ITextHost *pITextHost,
'   IUnknown **ppUnk);
