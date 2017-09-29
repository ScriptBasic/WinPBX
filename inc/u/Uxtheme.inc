' ########################################################################################
' Microsoft Windows
' File: uxtheme.inc
' Contents: Theming API header file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UXTHEME_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "vssym32.inc"

'typedef HANDLE HTHEME;          // handle to a section of theme data for class

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%MAX_THEMECOLOR = 64
%MAX_THEMESIZE  = 64
#ENDIF

'#if (NTDDI_VERSION>= NTDDI_WIN7)
#IF %WINVER >= &H0601
'//---------------------------------------------------------------------------
'// BeginPanningFeedback - Visual feedback init function related to pan gesture
'//   - internally called by DefaultGestureHandler
'//   - called by application
'//
'//  HWND hwnd - The handle to the Target window that will receive feedback
'//
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION BeginPanningFeedback (BYVAL hwnd AS DWORD) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "BeginPanningFeedback")
   IF pProc THEN CALL DWORD pProc USING BeginPanningFeedback(hwnd) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION BeginPanningFeedback IMPORT "UxTheme.dll" ALIAS "BeginPanningFeedback" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'// UpdatePanningFeedback : Visual feedback function related to pan gesture
'// Can Be called only after a BeginPanningFeedback call
'//   - internally called by DefaultGestureHandler
'//   - called by application
'//
'// HWND hwnd                 - The handle to the Target window that will receive feedback
'//                             For the method to succeed this must be the same hwnd as provided in
'//                             BeginPanningFeedback
'//
'// LONG lTotalOverpanOffsetX - The Total displacement that the window has moved in the horizontal direction
'//                             since the end of scrollable region was reached. The API would move the window by the distance specified
'//                             A maximum displacement of 30 pixels is allowed
'//
'// LONG lTotalOverpanOffsetY - The Total displacement that the window has moved in the horizontal direction
'//                             since the end of scrollable
'//                             region was reached. The API would move the window by the distance specified
'//                             A maximum displacement of 30 pixels is allowed
'//
'// BOOL fInInertia           - Flag dictating whether the Application is handling a WM_GESTURE message with the
'//                             GF_INERTIA FLAG set
'//
'//   Incremental calls to UpdatePanningFeedback should make sure they always pass
'//   the sum of the increments and not just the increment themselves
'//   Eg : If the initial displacement is 10 pixels and the next displacement 10 pixels
'//        the second call would be with the parameter as 20 pixels as opposed to 10
'//   Eg : UpdatePanningFeedback(hwnd, 10, 10, TRUE)
'//

#IF %DEF(%USELOADLIBRARY)

FUNCTION UpdatePanningFeedback (BYVAL hwnd AS DWORD, BYVAL lTotalOverpanOffsetX AS LONG, BYVAL lTotalOverpanOffsetY AS LONG, BYVAL fInInertia AS LONG) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "UpdatePanningFeedback")
   IF pProc THEN CALL DWORD pProc USING UpdatePanningFeedback(hwnd, lTotalOverpanOffsetX, lTotalOverpanOffsetY, fInInertia) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION UpdatePanningFeedback IMPORT "UxTheme.dll" ALIAS "UpdatePanningFeedback" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL lTotalOverpanOffsetX AS LONG _                 ' __in LONG lTotalOverpanOffsetX
 , BYVAL lTotalOverpanOffsetY AS LONG _                 ' __in LONG lTotalOverpanOffsetY
 , BYVAL fInInertia AS LONG _                           ' __in BOOL fInInertia
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//
'// EndPanningFeedback :Visual feedback reset function related to pan gesture
'//   - internally called by DefaultGestureHandler
'//   - called by application
'//   Terminates any existing animation that was in process or set up by BeginPanningFeedback and UpdatePanningFeedback
'//   The EndPanningFeedBack needs to be called Prior to calling any BeginPanningFeedBack if we have already
'//   called a BeginPanningFeedBack followed by one/ more UpdatePanningFeedback calls
'//
'//  HWND hwnd         - The handle to the Target window that will receive feedback
'//
'//  BOOL fAnimateBack - Flag to indicate whether you wish the displaced window to move back
'//                      to the original position via animation or a direct jump.
'//                      Either ways the method will try to restore the moved window.
'//                      The latter case exists for compatibility with legacy apps.
'//

#IF %DEF(%USELOADLIBRARY)

FUNCTION EndPanningFeedback (BYVAL hwnd AS DWORD, BYVAL fAnimateBack AS LONG) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "EndPanningFeedback")
   IF pProc THEN CALL DWORD pProc USING EndPanningFeedback(hwnd, fAnimateBack) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION EndPanningFeedback IMPORT "UxTheme.dll" ALIAS "EndPanningFeedback" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL fAnimateBack AS LONG _                         ' __in BOOL fAnimateBack
 ) AS LONG                                              ' BOOL

#ENDIF

#ENDIF   ' // NTDDI_VERSION>= NTDDI_WIN7


'//---------------------------------------------------------------------------
'// NOTE: PartId's and StateId's used in the theme API are defined in the
'//       hdr file <tmschema.h> using the TM_PART and TM_STATE macros.  For
'//       example, "TM_PART(BP, PUSHBUTTON)" defines the PartId "BP_PUSHBUTTON".

'//---------------------------------------------------------------------------
'//  OpenThemeData()     - Open the theme data for the specified HWND and
'//                        semi-colon separated list of class names.
'//
'//                        OpenThemeData() will try each class name, one at
'//                        a time, and use the first matching theme info
'//                        found.  If a match is found, a theme handle
'//                        to the data is returned.  If no match is found,
'//                        a "NULL" handle is returned.
'//
'//                        When the window is destroyed or a WM_THEMECHANGED
'//                        msg is received, "CloseThemeData()" should be
'//                        called to close the theme handle.
'//
'//  hwnd                - window handle of the control/window to be themed
'//
'//  pszClassList        - class name (or list of names) to match to theme data
'//                        section.  if the list contains more than one name,
'//                        the names are tested one at a time for a match.
'//                        If a match is found, OpenThemeData() returns a
'//                        theme handle associated with the matching class.
'//                        This param is a list (instead of just a single
'//                        class name) to provide the class an opportunity
'//                        to get the "best" match between the class and
'//                        the current theme.  For example, a button might
'//                        pass L"OkButton, Button" if its ID=ID_OK.  If
'//                        the current theme has an entry for OkButton,
'//                        that will be used.  Otherwise, we fall back on
'//                        the normal Button entry.
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION OpenThemeData (BYVAL hwnd AS DWORD, BYREF pszClassList AS WSTRINGZ) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "OpenThemeData")
   IF pProc THEN CALL DWORD pProc USING OpenThemeData(hwnd, pszClassList) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

#ELSE

DECLARE FUNCTION OpenThemeData IMPORT "UxTheme.dll" ALIAS "OpenThemeData" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszClassList AS WSTRINGZ _                     ' __in LPCWSTR pszClassList
 ) AS DWORD                                             ' HTHEME

#ENDIF

%OTD_FORCE_RECT_SIZING   = &H00000001???          ' // make all parts size to rect
%OTD_NONCLIENT           = &H00000002???          ' // set if hTheme to be used for nonclient area
%OTD_VALIDBITS           = %OTD_FORCE_RECT_SIZING OR %OTD_NONCLIENT


'//---------------------------------------------------------------------------
'//  OpenThemeDataEx     - Open the theme data for the specified HWND and
'//                        semi-colon separated list of class names.
'//
'//                        OpenThemeData() will try each class name, one at
'//                        a time, and use the first matching theme info
'//                        found.  If a match is found, a theme handle
'//                        to the data is returned.  If no match is found,
'//                        a "NULL" handle is returned.
'//
'//                        When the window is destroyed or a WM_THEMECHANGED
'//                        msg is received, "CloseThemeData()" should be
'//                        called to close the theme handle.
'//
'//  hwnd                - window handle of the control/window to be themed
'//
'//  pszClassList        - class name (or list of names) to match to theme data
'//                        section.  if the list contains more than one name,
'//                        the names are tested one at a time for a match.
'//                        If a match is found, OpenThemeData() returns a
'//                        theme handle associated with the matching class.
'//                        This param is a list (instead of just a single
'//                        class name) to provide the class an opportunity
'//                        to get the "best" match between the class and
'//                        the current theme.  For example, a button might
'//                        pass L"OkButton, Button" if its ID=ID_OK.  If
'//                        the current theme has an entry for OkButton,
'//                        that will be used.  Otherwise, we fall back on
'//                        the normal Button entry.
'//
'//  dwFlags              - allows certain overrides of std features
'//                         (see OTD_XXX defines above)
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION OpenThemeDataEx (BYVAL hwnd AS DWORD, BYREF pszClassList AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "OpenThemeDataEx")
   IF pProc THEN CALL DWORD pProc USING OpenThemeDataEx(hwnd, pszClassList, dwFlags) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

#ELSE

DECLARE FUNCTION OpenThemeDataEx IMPORT "UxTheme.dll" ALIAS "OpenThemeDataEx" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszClassList AS WSTRINGZ _                     ' __in LPCWSTR pszClassList
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HTHEME

#ENDIF

'//---------------------------------------------------------------------------
'//  CloseThemeData()    - closes the theme data handle.  This should be done
'//                        when the window being themed is destroyed or
'//                        whenever a WM_THEMECHANGED msg is received
'//                        (followed by an attempt to create a new Theme data
'//                        handle).
'//
'//  hTheme              - open theme data handle (returned from prior call
'//                        to OpenThemeData() API).
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION CloseThemeData (BYVAL hTheme AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "CloseThemeData")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING CloseThemeData(hTheme) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION CloseThemeData IMPORT "UxTheme.dll" ALIAS "CloseThemeData" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//    functions for basic drawing support
'//---------------------------------------------------------------------------
'// The following methods are the theme-aware drawing services.
'// Controls/Windows are defined in drawable "parts" by their author: a
'// parent part and 0 or more child parts.  Each of the parts can be
'// described in "states" (ex: disabled, hot, pressed).
'//---------------------------------------------------------------------------
'// For the list of all themed classes and the definition of all
'// parts and states, see the file "tmschmea.h".
'//---------------------------------------------------------------------------
'// Each of the below methods takes a "iPartId" param to specify the
'// part and a "iStateId" to specify the state of the part.
'// "iStateId=0" refers to the root part.  "iPartId" = "0" refers to
'// the root class.
'//-----------------------------------------------------------------------
'// Note: draw operations are always scaled to fit (and not to exceed)
'// the specified "Rect".
'//-----------------------------------------------------------------------

'//------------------------------------------------------------------------
'//  DrawThemeBackground()
'//                      - draws the theme-specified border and fill for
'//                        the "iPartId" and "iStateId".  This could be
'//                        based on a bitmap file, a border and fill, or
'//                        other image description.
'//
'//  hTheme              - theme data handle
'//  hdc                 - HDC to draw into
'//  iPartId             - part number to draw
'//  iStateId            - state number (of the part) to draw
'//  pRect               - defines the size/location of the part
'//  pClipRect           - optional clipping rect (don't draw outside it)
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeBackground (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateId AS LONG, BYREF pRect AS RECT, BYREF pClipRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeBackground")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeBackground(hTheme, hdc, iPartId, iStateId, pRect, BYVAL VARPTR(pClipRect)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeBackground IMPORT "UxTheme.dll" ALIAS "DrawThemeBackground" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pRect AS RECT _                                ' __in const RECT *pRect
 , BYREF pClipRect AS RECT _                            ' __in_opt const RECT *pClipRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//---- bits used in dwFlags of DTBGOPTS ----
%DTBG_CLIPRECT           = &H00000001???  ' // rcClip has been specified
%DTBG_DRAWSOLID          = &H00000002???  ' // DEPRECATED: draw transparent/alpha images as solid
%DTBG_OMITBORDER         = &H00000004???  ' // don't draw border of part
%DTBG_OMITCONTENT        = &H00000008???  ' // don't draw content area of part
%DTBG_COMPUTINGREGION    = &H00000010???  ' // TRUE if calling to compute region
%DTBG_MIRRORDC           = &H00000020???  ' // assume the hdc is mirrorred and
                                       ' // flip images as appropriate (currently
                                       ' // only supported for bgtype=imagefile)
%DTBG_NOMIRROR           = &H00000040???  ' // don't mirror the output, overrides everything else
%DTBG_VALIDBITS          = %DTBG_CLIPRECT OR _
                           %DTBG_DRAWSOLID OR _
                           %DTBG_OMITBORDER OR _
                           %DTBG_OMITCONTENT OR _
                           %DTBG_COMPUTINGREGION OR _
                           %DTBG_MIRRORDC OR _
                           %DTBG_NOMIRROR

' // Size = 24 bytes
TYPE DTBGOPTS DWORD
   dwSize  AS DWORD   ' DWORD // size of the struct
   dwFlags AS DWORD   ' DWORD // which options have been specified
   rcClip  AS RECT    ' RECT // clipping rectangle
END TYPE

'//------------------------------------------------------------------------
'//  DrawThemeBackgroundEx()
'//                      - draws the theme-specified border and fill for
'//                        the "iPartId" and "iStateId".  This could be
'//                        based on a bitmap file, a border and fill, or
'//                        other image description.  NOTE: This will be
'//                        merged back into DrawThemeBackground() after
'//                        BETA 2.
'//
'//  hTheme              - theme data handle
'//  hdc                 - HDC to draw into
'//  iPartId             - part number to draw
'//  iStateId            - state number (of the part) to draw
'//  pRect               - defines the size/location of the part
'//  pOptions            - ptr to optional params
'//------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeBackgroundEx (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, BYREF pRect AS RECT, _
   BYVAL pOptions AS DTBGOPTS PTR) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeBackgroundEx")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeBackgroundEx(hTheme, hdc, iPartId, iStateId, _
                 pRect, BYVAL pOptions) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION  DrawThemeBackgroundEx LIB "UxTheme.dll" _
    ALIAS "DrawThemeBackgroundEx" ( _
    BYVAL hTheme   AS DWORD, _  ' HTHEME
    BYVAL hdc      AS DWORD, _  ' HDC
    BYVAL iPartId  AS LONG, _
    BYVAL iStateId AS LONG, _
    pRect          AS RECT, _
    BYVAL pOptions AS DTBGOPTS PTR _
    ) AS LONG  ' HRESULT

#ENDIF

#ELSE

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeBackgroundEx (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, BYREF pRect AS RECT, _
   BYREF pOptions AS DTBGOPTS) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeBackgroundEx")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeBackgroundEx(hTheme, hdc, iPartId, iStateId, _
                 pRect, BYVAL VARPTR(pOptions)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeBackgroundEx IMPORT "UxTheme.dll" ALIAS "DrawThemeBackgroundEx" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pRect AS RECT _                                ' __in const RECT *pRect
 , BYREF pOptions AS DTBGOPTS _                         ' __in _opt OPTIONAL const DTBGOPTS *pOptions
 ) AS LONG                                              ' HRESULT

#ENDIF

#ENDIF

'//---------------------------------------------------------------------------
'//----- DrawThemeText() flags ----

'#define DTT_GRAYED      0x1         // draw a grayed-out string

%DTT_GRAYED          = &H00000001???
%DTT_FLAGS2VALIDBITS = %DTT_GRAYED

'//-------------------------------------------------------------------------
'//  DrawThemeText()     - draws the text using the theme-specified
'//                        color and font for the "iPartId" and
'//                        "iStateId".
'//
'//  hTheme              - theme data handle
'//  hdc                 - HDC to draw into
'//  iPartId             - part number to draw
'//  iStateId            - state number (of the part) to draw
'//  pszText             - actual text to draw
'//  dwCharCount         - number of chars to draw (-1 for all)
'//  dwTextFlags         - same as DrawText() "uFormat" param
'//  dwTextFlags2        - additional drawing options
'//  pRect               - defines the size/location of the part
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeText (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, BYREF pszText AS WSTRINGZ, _
   BYVAL iCharCount AS LONG, BYVAL dwTextFlags AS DWORD, _
   BYVAL dwTextFlags2 AS DWORD, BYREF pRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeText")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeText(hTheme, hdc, iPartId, iStateId, _
                 pszText, iCharCount, dwTextFlags, dwTextFlags2, pRect) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeText IMPORT "UxTheme.dll" ALIAS "DrawThemeText" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pszText AS WSTRINGZ _                          ' __in LPCWSTR pszText
 , BYVAL iCharCount AS LONG _                           ' __in int iCharCount
 , BYVAL dwTextFlags AS DWORD _                         ' __in DWORD dwTextFlags
 , BYVAL dwTextFlags2 AS DWORD  _                       ' __in DWORD dwTextFlags2
 , BYREF pRect AS RECT _                                ' __in const RECT *pRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-------------------------------------------------------------------------
'//  GetThemeBackgroundContentRect()
'//                      - gets the size of the content for the theme-defined
'//                        background.  This is usually the area inside
'//                        the borders or Margins.
'//
'//      hTheme          - theme data handle
'//      hdc             - (optional) device content to be used for drawing
'//      iPartId         - part number to draw
'//      iStateId        - state number (of the part) to draw
'//      pBoundingRect   - the outer RECT of the part being drawn
'//      pContentRect    - RECT to receive the content area
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeBackgroundContentRect (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYREF pBoundingRect AS RECT, BYREF pContentRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeBackgroundContentRect")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeBackgroundContentRect(hTheme, hdc, iPartId, _
                 iStateId, pBoundingRect, pContentRect) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeBackgroundContentRect IMPORT "UxTheme.dll" ALIAS "GetThemeBackgroundContentRect" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pBoundingRect AS RECT _                        ' __in const RECT *pBoundingRect
 , BYREF pContentRect AS RECT _                         ' __out RECT *pContentRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-------------------------------------------------------------------------
'//  GetThemeBackgroundExtent() - calculates the size/location of the theme-
'//                               specified background based on the
'//                               "pContentRect".
'//
'//      hTheme          - theme data handle
'//      hdc             - (optional) device content to be used for drawing
'//      iPartId         - part number to draw
'//      iStateId        - state number (of the part) to draw
'//      pContentRect    - RECT that defines the content area
'//      pBoundingRect   - RECT to receive the overall size/location of part
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeBackgroundExtent (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYREF pContentRect AS RECT, BYREF pExtentRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeBackgroundExtent")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeBackgroundExtent(hTheme, hdc, iPartId, _
                 iStateId, pContentRect, pExtentRect) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeBackgroundExtent IMPORT "UxTheme.dll" ALIAS "GetThemeBackgroundExtent" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pContentRect AS RECT _                         ' __in const RECT *pContentRect
 , BYREF pExtentRect AS RECT _                          ' __out RECT *pExtentRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-------------------------------------------------------------------------
'//  GetThemeBackgroundRegion()
'//                      - computes the region for a regular or partially
'//                        transparent theme-specified background that is
'//                        bound by the specified "pRect".
'//                        If the rectangle is empty, sets the HRGN to NULL
'//                        and return S_FALSE.
'//
'//  hTheme              - theme data handle
'//  hdc                 - optional HDC to draw into (DPI scaling)
'//  iPartId             - part number to draw
'//  iStateId            - state number (of the part)
'//  pRect               - the RECT used to draw the part
'//  pRegion             - receives handle to calculated region
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeBackgroundRegion (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYREF pRect AS RECT, BYREF pRegion AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeBackgroundRegion")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeBackgroundRegion(hTheme, hdc, iPartId, iStateId, pRect, pRegion) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeBackgroundRegion IMPORT "UxTheme.dll" ALIAS "GetThemeBackgroundRegion" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pRect AS RECT _                                ' __in const RECT *pRect
 , BYREF pRegion AS DWORD _                             ' __out HRGN *pRegion
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-------------------------------------------------------------------------
'typedef enum THEMESIZE
'{
'    TS_MIN,             // minimum size
'    TS_TRUE,            // size without stretching
'    TS_DRAW,            // size that theme mgr will use to draw part
'};

%TS_MIN   = 0           ' // minimum size
%TS_TRUE  = 1           ' // size without stretching
%TS_DRAW  = 2           ' // size that theme mgr will use to draw part

'//-------------------------------------------------------------------------
'//  GetThemePartSize() - returns the specified size of the theme part
'//
'//  hTheme              - theme data handle
'//  hdc                 - HDC to select font into & measure against
'//  iPartId             - part number to retrieve size for
'//  iStateId            - state number (of the part)
'//  prc                 - (optional) rect for part drawing destination
'//  eSize               - the type of size to be retreived
'//  psz                 - receives the specified size of the part
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemePartSize (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYREF prc AS RECT, BYVAL eSize AS LONG, BYREF psz AS SIZE) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemePartSize")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemePartSize(hTheme, hdc, iPartId, iStateId, BYVAL VARPTR(prc), eSize, psz) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemePartSize IMPORT "UxTheme.dll" ALIAS "GetThemePartSize" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF prc AS RECT _                                  ' __in_opt RECT *prc
 , BYVAL eSize AS LONG _                                ' __in enum THEMESIZE eSize
 , BYREF psz AS SIZE _                                  ' __out SIZE *psz
 ) AS LONG                                              ' HRESULT

#ENDIF


'//-------------------------------------------------------------------------
'//  GetThemeTextExtent() - calculates the size/location of the specified
'//                         text when rendered in the Theme Font.
'//
'//  hTheme              - theme data handle
'//  hdc                 - HDC to select font & measure into
'//  iPartId             - part number to draw
'//  iStateId            - state number (of the part)
'//  pszText             - the text to be measured
'//  dwCharCount         - number of chars to draw (-1 for all)
'//  dwTextFlags         - same as DrawText() "uFormat" param
'//  pszBoundingRect     - optional: to control layout of text
'//  pszExtentRect       - receives the RECT for text size/location
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeTextExtent (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYREF pszText AS WSTRINGZ, BYVAL iCharCount AS LONG, BYVAL dwTextFlags AS DWORD, _
   BYREF pBoundingRect AS RECT, BYREF pExtentRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeTextExtent")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeTextExtent(hTheme, hdc, iPartId, iStateId, _
                 pszText, iCharCount, dwTextFlags, BYVAL VARPTR(pBoundingRect), pExtentRect) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeTextExtent IMPORT "UxTheme.dll" ALIAS "GetThemeTextExtent" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pszText AS WSTRINGZ _                          ' __in LPCWSTR pszText
 , BYVAL iCharCount AS LONG _                           ' __in int iCharCount
 , BYVAL dwTextFlags AS DWORD _                         ' __in DWORD dwTextFlags
 , BYREF pBoundingRect AS RECT _                        ' __in_opt  const RECT *pBoundingRect
 , BYREF pExtentRect AS RECT _                          ' __out RECT *pExtentRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-------------------------------------------------------------------------
'//  GetThemeTextMetrics()
'//                      - returns info about the theme-specified font
'//                        for the part/state passed in.
'//
'//  hTheme              - theme data handle
'//  hdc                 - optional: HDC for screen context
'//  iPartId             - part number to draw
'//  iStateId            - state number (of the part)
'//  ptm                 - receives the font info
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeTextMetrics (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, BYREF ptm AS TEXTMETRICW) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeTextMetrics")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeTextMetrics(hTheme, hdc, iPartId, iStateId, ptm) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeTextMetrics IMPORT "UxTheme.dll" ALIAS "GetThemeTextMetrics" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF ptm AS TEXTMETRICW _                           ' __out TEXTMETRICW* ptm
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-------------------------------------------------------------------------
'//----- HitTestThemeBackground, HitTestThemeBackgroundRegion flags ----

'//  Theme background segment hit test flag (default). possible return values are:
'//  HTCLIENT: hit test succeeded in the middle background segment
'//  HTTOP, HTLEFT, HTTOPLEFT, etc:  // hit test succeeded in the the respective theme background segment.
'#define HTTB_BACKGROUNDSEG          0x0000

%HTTB_BACKGROUNDSEG = &H0000???

'//  Fixed border hit test option.  possible return values are:
'//  HTCLIENT: hit test succeeded in the middle background segment
'//  HTBORDER: hit test succeeded in any other background segment
'#define HTTB_FIXEDBORDER            0x0002  // Return code may be either HTCLIENT or HTBORDER.

%HTTB_FIXEDBORDER = &H0002???  ' // Return code may be either HTCLIENT or HTBORDER.

'//  Caption hit test option.  Possible return values are:
'//  HTCAPTION: hit test succeeded in the top, top left, or top right background segments
'//  HTNOWHERE or another return code, depending on absence or presence of accompanying flags, resp.
'#define HTTB_CAPTION                0x0004

%HTTB_CAPTION = &H0004???

'//  Resizing border hit test flags.  Possible return values are:
'//  HTCLIENT: hit test succeeded in middle background segment
'//  HTTOP, HTTOPLEFT, HTLEFT, HTRIGHT, etc:    hit test succeeded in the respective system resizing zone
'//  HTBORDER: hit test failed in middle segment and resizing zones, but succeeded in a background border segment
'#define HTTB_RESIZINGBORDER_LEFT    0x0010  // Hit test left resizing border,
'#define HTTB_RESIZINGBORDER_TOP     0x0020  // Hit test top resizing border
'#define HTTB_RESIZINGBORDER_RIGHT   0x0040  // Hit test right resizing border
'#define HTTB_RESIZINGBORDER_BOTTOM  0x0080  // Hit test bottom resizing border

'#define HTTB_RESIZINGBORDER         (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP|\
'                                     HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)

%HTTB_RESIZINGBORDER_LEFT   = &H0010??? ' // Hit test left resizing border,
%HTTB_RESIZINGBORDER_TOP    = &H0020??? ' // Hit test top resizing border
%HTTB_RESIZINGBORDER_RIGHT  = &H0040??? ' // Hit test right resizing border
%HTTB_RESIZINGBORDER_BOTTOM = &H0080??? ' // Hit test bottom resizing border

%HTTB_RESIZINGBORDER = %HTTB_RESIZINGBORDER_LEFT OR %HTTB_RESIZINGBORDER_TOP OR _
                       %HTTB_RESIZINGBORDER_RIGHT OR %HTTB_RESIZINGBORDER_BOTTOM

'// Resizing border is specified as a template, not just window edges.
'// This option is mutually exclusive with HTTB_SYSTEMSIZINGWIDTH; HTTB_SIZINGTEMPLATE takes precedence
'#define HTTB_SIZINGTEMPLATE      0x0100

%HTTB_SIZINGTEMPLATE = &H0100???

'// Use system resizing border width rather than theme content margins.
'// This option is mutually exclusive with HTTB_SIZINGTEMPLATE, which takes precedence.
'#define HTTB_SYSTEMSIZINGMARGINS 0x0200

%HTTB_SYSTEMSIZINGMARGINS = &H0200???

'//-------------------------------------------------------------------------
'//  HitTestThemeBackground()
'//                      - returns a HitTestCode (a subset of the values
'//                        returned by WM_NCHITTEST) for the point "ptTest"
'//                        within the theme-specified background
'//                        (bound by pRect).  "pRect" and "ptTest" should
'//                        both be in the same coordinate system
'//                        (client, screen, etc).
'//
'//      hTheme          - theme data handle
'//      hdc             - HDC to draw into
'//      iPartId         - part number to test against
'//      iStateId        - state number (of the part)
'//      pRect           - the RECT used to draw the part
'//      hrgn            - optional region to use; must be in same coordinates as
'//                      -    pRect and pTest.
'//      ptTest          - the hit point to be tested
'//      dwOptions       - HTTB_xxx constants
'//      pwHitTestCode   - receives the returned hit test code - one of:
'//
'//                        HTNOWHERE, HTLEFT, HTTOPLEFT, HTBOTTOMLEFT,
'//                        HTRIGHT, HTTOPRIGHT, HTBOTTOMRIGHT,
'//                        HTTOP, HTBOTTOM, HTCLIENT
'//-------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION HitTestThemeBackground (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL dwOptions AS DWORD, BYREF pRect AS RECT, BYVAL hrgn AS DWORD, _
   BYVAL ptText AS POINT, BYREF pwHitTestCode AS WORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "HitTestThemeBackground")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING HitTestThemeBackground(hTheme, hdc, iPartId, iStateId, _
                 dwOptions, BYVAL VARPTR(pRect), hrgn, ptText, pwHitTestCode) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION HitTestThemeBackground IMPORT "UxTheme.dll" ALIAS "HitTestThemeBackground" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYREF pRect AS RECT _                                ' __in const RECT *pRect
 , BYVAL hrgn AS DWORD _                                ' __in_opt  HRGN hrgn
 , BYVAL ptText AS POINT  _                             ' __in POINT ptText
 , BYREF pwHitTestCode AS WORD _                        ' __out WORD *pwHitTestCode
 ) AS LONG                                              ' HRESULT

#ENDIF


'//------------------------------------------------------------------------
'//  DrawThemeEdge()     - Similar to the DrawEdge() API, but uses part colors
'//                        and is high-DPI aware
'//  hTheme              - theme data handle
'//  hdc                 - HDC to draw into
'//  iPartId             - part number to draw
'//  iStateId            - state number of part
'//  pDestRect           - the RECT used to draw the line(s)
'//  uEdge               - Same as DrawEdge() API
'//  uFlags              - Same as DrawEdge() API
'//  pContentRect        - Receives the interior rect if (uFlags & BF_ADJUST)
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeEdge (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, BYREF pDestRect AS RECT, _
   BYVAL uEdge AS DWORD, BYVAL uFlags AS DWORD, BYREF pContentRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeEdge")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeEdge(hTheme, hdc, iPartId, iStateId, _
                 pDestRect, uEdge, uFlags, BYVAL VARPTR(pContentRect)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeEdge IMPORT "UxTheme.dll" ALIAS "DrawThemeEdge" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pDestRect AS RECT _                            ' __in const RECT *pDestRect
 , BYVAL uEdge AS DWORD _                               ' __in UINT uEdge
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYREF pContentRect AS RECT _                         ' __out_opt RECT *pContentRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  DrawThemeIcon()     - draws an image within an imagelist based on
'//                        a (possible) theme-defined effect.
'//
'//  hTheme              - theme data handle
'//  hdc                 - HDC to draw into
'//  iPartId             - part number to draw
'//  iStateId            - state number of part
'//  pRect               - the RECT to draw the image within
'//  himl                - handle to IMAGELIST
'//  iImageIndex         - index into IMAGELIST (which icon to draw)
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeIcon (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYREF pRect AS RECT, BYVAL himl AS DWORD, BYVAL iImageIndex AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeIcon")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeIcon(hTheme, hdc, iPartId, iStateId, _
                 pRect, himl, iImageIndex) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeIcon IMPORT "UxTheme.dll" ALIAS "DrawThemeIcon" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pRect AS RECT _                                ' __in const RECT *pRect
 , BYVAL himl AS DWORD  _                               ' __in HIMAGELIST himl
 , BYVAL iImageIndex AS LONG _                          ' __in int iImageIndex
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  IsThemePartDefined() - returns TRUE if the theme has defined parameters
'//                         for the specified "iPartId" and "iStateId".
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number to find definition for
'//  iStateId            - state number of part
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION IsThemePartDefined (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "IsThemePartDefined")
   IF pProc THEN CALL DWORD pProc USING IsThemePartDefined(hTheme, iPartId, iStateId) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION IsThemePartDefined IMPORT "UxTheme.dll" ALIAS "IsThemePartDefined" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//  IsThemeBackgroundPartiallyTransparent()
'//                      - returns TRUE if the theme specified background for
'//                        the part/state has transparent pieces or
'//                        alpha-blended pieces.
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION IsThemeBackgroundPartiallyTransparent (BYVAL hTheme AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "IsThemeBackgroundPartiallyTransparent")
   IF pProc THEN CALL DWORD pProc USING IsThemeBackgroundPartiallyTransparent(hTheme, iPartId, iStateId) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION IsThemeBackgroundPartiallyTransparent IMPORT "UxTheme.dll" ALIAS "IsThemeBackgroundPartiallyTransparent" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//    lower-level theme information services
'//---------------------------------------------------------------------------
'// The following methods are getter routines for each of the Theme Data types.
'// Controls/Windows are defined in drawable "parts" by their author: a
'// parent part and 0 or more child parts.  Each of the parts can be
'// described in "states" (ex: disabled, hot, pressed).
'//---------------------------------------------------------------------------
'// Each of the below methods takes a "iPartId" param to specify the
'// part and a "iStateId" to specify the state of the part.
'// "iStateId=0" refers to the root part.  "iPartId" = "0" refers to
'// the root class.
'//-----------------------------------------------------------------------
'// Each method also take a "iPropId" param because multiple instances of
'// the same primitive type can be defined in the theme schema.
'//-----------------------------------------------------------------------


'//-----------------------------------------------------------------------
'//  GetThemeColor()     - Get the value for the specified COLOR property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  pColor              - receives the value of the property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeColor(BYVAL hTheme AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF pColor AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeColor")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeColor(hTheme, iPartId, iStateId, iPropId, pColor) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeColor IMPORT "UxTheme.dll" ALIAS "GetThemeColor" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pColor AS DWORD _                              ' __out COLORREF *pColor
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeMetric()    - Get the value for the specified metric/size
'//                        property
'//
'//  hTheme              - theme data handle
'//  hdc                 - (optional) hdc to be drawn into (DPI scaling)
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  piVal               - receives the value of the property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeMetric (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF piVal AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeMetric")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeMetric(hTheme, hdc, iPartId, iStateId, iPropId, piVal) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeMetric IMPORT "UxTheme.dll" ALIAS "GetThemeMetric" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF piVal AS LONG _                                ' __out int *piVal
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeString()    - Get the value for the specified string property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  pszBuff             - receives the string property value
'//  cchMaxBuffChars     - max. number of chars allowed in pszBuff
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeString (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateId AS LONG, BYVAL iPropId AS LONG, BYREF pszBuff AS WSTRINGZ, _
   BYVAL cchMaxBuffChars AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeString")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeString(hTheme, iPartId, iStateId, iPropId, _
                 pszBuff, cchMaxBuffChars) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeString IMPORT "UxTheme.dll" ALIAS "GetThemeString" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pszBuff AS WSTRINGZ _                          ' __out LPWSTR pszBuff
 , BYVAL cchMaxBuffChars AS LONG _                      ' __in int cchMaxBuffChars
 ) AS LONG                                              ' HRESULT

#ENDIF


'//-----------------------------------------------------------------------
'//  GetThemeBool()      - Get the value for the specified BOOL property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  pfVal               - receives the value of the property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeBool (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateId AS LONG, BYVAL iPropId AS LONG, BYREF pfVal AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeBool")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeBool(hTheme, iPartId, iStateId, iPropId, pfVal) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeBool IMPORT "UxTheme.dll" ALIAS "GetThemeBool" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pfVal AS LONG _                                ' __out BOOL *pfVal
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeInt()       - Get the value for the specified int property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  piVal               - receives the value of the property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeInt (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateId AS LONG, BYVAL iPropId AS LONG, BYREF piVal AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeInt")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeInt(hTheme, iPartId, iStateId, iPropId, piVal) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeInt IMPORT "UxTheme.dll" ALIAS "GetThemeInt" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF piVal AS LONG _                                ' __out int *piVal
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeEnumValue() - Get the value for the specified ENUM property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  piVal               - receives the value of the enum (cast to int*)
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeEnumValue (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateId AS LONG, BYVAL iPropId AS LONG, BYREF piVal AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeEnumValue")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeEnumValue(hTheme, iPartId, iStateId, iPropId, piVal) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeEnumValue IMPORT "UxTheme.dll" ALIAS "GetThemeEnumValue" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF piVal AS LONG _                                ' __out int *piVal
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemePosition()  - Get the value for the specified position
'//                        property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  pPoint              - receives the value of the position property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemePosition (BYVAL hTheme AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF pPoint AS POINT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemePosition")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemePosition(hTheme, iPartId, iStateId, iPropId, pPoint) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemePosition IMPORT "UxTheme.dll" ALIAS "GetThemePosition" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pPoint AS POINT _                              ' __out POINT *pPoint
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeFont()      - Get the value for the specified font property
'//
'//  hTheme              - theme data handle
'//  hdc                 - (optional) hdc to be drawn to (DPI scaling)
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  pFont               - receives the value of the LOGFONT property
'//                        (scaled for the current logical screen dpi)
'//-----------------------------------------------------------------------

' Note: The C++ declaraton incorrectly declares pFont as a pointer to a
' LOGFONT structure instead of a LOGFONTW structure.
#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeFont (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF pFont AS LOGFONTW) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeFont")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeFont(hTheme, hdc, iPartId, iStateId, iPropId, pFont) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeFont IMPORT "UxTheme.dll" ALIAS "GetThemeFont" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in OPTIONAL HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pFont AS LOGFONTW _                         s   ' __out LOGFONTW *pFont
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeRect()      - Get the value for the specified RECT property
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to get the value for
'//  pRect               - receives the value of the RECT property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeRect (BYVAL hTheme AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF pRect AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeRect")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeRect(hTheme, iPartId, iStateId, iPropId, pRect) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeRect IMPORT "UxTheme.dll" ALIAS "GetThemeRect" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pRect AS RECT _                                ' __out RECT *pRect
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
' // Size = 16 bytes
TYPE MARGINS DWORD
   cxLeftWidth    AS LONG  ' int // width of left border that retains its size
   cxRightWidth   AS LONG  ' int // width of right border that retains its size
   cyTopHeight    AS LONG  ' int // height of top border that retains its size
   cyBottomHeight AS LONG  ' int // height of bottom border that retains its size
END TYPE

'//-----------------------------------------------------------------------
'//  GetThemeMargins()   - Get the value for the specified MARGINS property
'//
'//      hTheme          - theme data handle
'//      hdc             - (optional) hdc to be used for drawing
'//      iPartId         - part number
'//      iStateId        - state number of part
'//      iPropId         - the property number to get the value for
'//      prc             - RECT for area to be drawn into
'//      pMargins        - receives the value of the MARGINS property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeMargins (BYVAL hTheme AS DWORD, _
   BYVAL hdc AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF prc AS RECT, BYREF pMargins AS MARGINS) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeMargins")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeMargins(hTheme, hdc, iPartId, iStateId, iPropId, BYVAL VARPTR(prc), pMargins) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeMargins IMPORT "UxTheme.dll" ALIAS "GetThemeMargins" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in_opt  HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF prc AS RECT _                                  ' __in_opt  RECT *prc
 , BYREF pMargins AS MARGINS _                          ' __out MARGINS *pMargins
 ) AS LONG                                              ' HRESULT

#ENDIF


'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
    %MAX_INTLIST_COUNT = 402
#ELSE
    %MAX_INTLIST_COUNT = 10
#ENDIF

' // Size = 1612 bytes
TYPE INTLIST DWORD
   iValueCount                     AS LONG   ' int // number of values in iValues
   iValues(%MAX_INTLIST_COUNT - 1) AS LONG   ' int iValues[MAX_INTLIST_COUNT]
END TYPE

'//-----------------------------------------------------------------------
'//  GetThemeIntList()   - Get the value for the specified INTLIST struct
'//
'//      hTheme          - theme data handle
'//      iPartId         - part number
'//      iStateId        - state number of part
'//      iPropId         - the property number to get the value for
'//      pIntList        - receives the value of the INTLIST property
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeIntList (BYVAL hTheme AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF pIntList AS INTLIST) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeIntList")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeIntList(hTheme, iPartId, iStateId, iPropId, pIntList) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeIntList IMPORT "UxTheme.dll" ALIAS "GetThemeIntList" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pIntList AS INTLIST _                          ' __out INTLIST *pIntList
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------

' enum PROPERTYORIGIN
%PO_STATE     = 0     ' // property was found in the state section
%PO_PART      = 1     ' // property was found in the part section
%PO_CLASS     = 2     ' // property was found in the class section
%PO_GLOBAL    = 3     ' // property was found in [globals] section
%PO_NOTFOUND  = 4     ' // property was not found

'//-----------------------------------------------------------------------
'//  GetThemePropertyOrigin()
'//                      - searches for the specified theme property
'//                        and sets "pOrigin" to indicate where it was
'//                        found (or not found)
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to search for
'//  pOrigin             - receives the value of the property origin
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemePropertyOrigin (BYVAL hTheme AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF pOrigin AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemePropertyOrigin")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemePropertyOrigin(hTheme, iPartId, iStateId, iPropId, pOrigin) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemePropertyOrigin IMPORT "UxTheme.dll" ALIAS "GetThemePropertyOrigin" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pOrigin AS LONG _                              ' __out enum PROPERTYORIGIN *pOrigin
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  SetWindowTheme()
'//                      - redirects an existing Window to use a different
'//                        section of the current theme information than its
'//                        class normally asks for.
'//
'//  hwnd                - the handle of the window (cannot be NULL)
'//
'//  pszSubAppName       - app (group) name to use in place of the calling
'//                        app's name.  If NULL, the actual calling app
'//                        name will be used.
'//
'//  pszSubIdList        - semicolon separated list of class Id names to
'//                        use in place of actual list passed by the
'//                        window's class.  if NULL, the id list from the
'//                        calling class is used.
'//---------------------------------------------------------------------------
'// The Theme Manager will remember the "pszSubAppName" and the
'// "pszSubIdList" associations thru the lifetime of the window (even
'// if themes are subsequently changed).  The window is sent a
'// "WM_THEMECHANGED" msg at the end of this call, so that the new
'// theme can be found and applied.
'//---------------------------------------------------------------------------
'// When "pszSubAppName" or "pszSubIdList" are NULL, the Theme Manager
'// removes the previously remember association.  To turn off theme-ing for
'// the specified window, you can pass an empty string (L"") so it
'// won't match any section entries.
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION SetWindowTheme (BYVAL hwnd AS DWORD, BYREF pszSubAppName AS WSTRINGZ, BYREF pszSubIdList AS WSTRINGZ) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "SetWindowTheme")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING SetWindowTheme(hwnd, pszSubAppName, pszSubIdList) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION SetWindowTheme IMPORT "UxTheme.dll" ALIAS "SetWindowTheme" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszSubAppName AS WSTRINGZ _                    ' __in LPCWSTR pszSubAppName
 , BYREF pszSubIdList AS WSTRINGZ _                     ' __in LPCWSTR pszSubIdList
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeFilename()  - Get the value for the specified FILENAME property.
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateId            - state number of part
'//  iPropId             - the property number to search for
'//  pszThemeFileName    - output buffer to receive the filename
'//  cchMaxBuffChars     - the size of the return buffer, in chars
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeFilename (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateId AS LONG, BYVAL iPropId AS LONG, _
   BYREF pszThemeFileName AS WSTRINGZ, BYVAL cchMaxBuffChars AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeFilename")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeFilename(hTheme, iPartId, iStateId, iPropId, _
                 pszThemeFileName, cchMaxBuffChars) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeFilename IMPORT "UxTheme.dll" ALIAS "GetThemeFilename" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pszThemeFileName AS WSTRINGZ _                 ' __out LPWSTR pszThemeFileName
 , BYVAL cchMaxBuffChars AS LONG _                      ' __in int cchMaxBuffChars
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeSysColor()  - Get the value of the specified System color.
'//
'//  hTheme              - the theme data handle.  if non-NULL, will return
'//                        color from [SysMetrics] section of theme.
'//                        if NULL, will return the global system color.
'//
'//  iColorId            - the system color index defined in winuser.h
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysColor (BYVAL hTheme AS DWORD, BYVAL iColorId AS LONG) AS DWORD

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysColor")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysColor(hTheme, iColorId) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysColor IMPORT "UxTheme.dll" ALIAS "GetThemeSysColor" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iColorId AS LONG _                             ' __in int iColorId
 ) AS DWORD                                             ' COLORREF

#ENDIF


'//---------------------------------------------------------------------------
'//  GetThemeSysColorBrush()
'//                      - Get the brush for the specified System color.
'//
'//  hTheme              - the theme data handle.  if non-NULL, will return
'//                        brush matching color from [SysMetrics] section of
'//                        theme.  if NULL, will return the brush matching
'//                        global system color.
'//
'//  iColorId            - the system color index defined in winuser.h
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysColorBrush (BYVAL hTheme AS DWORD, BYVAL iColorId AS LONG) AS DWORD

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysColorBrush")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysColorBrush(hTheme, iColorId) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysColorBrush IMPORT "UxTheme.dll" ALIAS "GetThemeSysColorBrush" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iColorId AS LONG _                             ' __in int iColorId
 ) AS DWORD                                             ' HBRUSH

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeSysBool()   - Get the boolean value of specified System metric.
'//
'//  hTheme              - the theme data handle.  if non-NULL, will return
'//                        BOOL from [SysMetrics] section of theme.
'//                        if NULL, will return the specified system boolean.
'//
'//  iBoolId             - the TMT_XXX BOOL number (first BOOL
'//                        is TMT_FLATMENUS)
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysBool (BYVAL hTheme AS DWORD, BYVAL iBoolId AS LONG) AS LONG

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysBool")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysBool(hTheme, iBoolId) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysBool IMPORT "UxTheme.dll" ALIAS "GetThemeSysBool" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iBoolId AS LONG _                              ' __in int iBoolId
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeSysSize()   - Get the value of the specified System size metric.
'//                        (scaled for the current logical screen dpi)
'//
'//  hTheme              - the theme data handle.  if non-NULL, will return
'//                        size from [SysMetrics] section of theme.
'//                        if NULL, will return the global system metric.
'//
'//  iSizeId             - the following values are supported when
'//                        hTheme is non-NULL:
'//
'//                          SM_CXBORDER   (border width)
'//                          SM_CXVSCROLL  (scrollbar width)
'//                          SM_CYHSCROLL  (scrollbar height)
'//                          SM_CXSIZE     (caption width)
'//                          SM_CYSIZE     (caption height)
'//                          SM_CXSMSIZE   (small caption width)
'//                          SM_CYSMSIZE   (small caption height)
'//                          SM_CXMENUSIZE (menubar width)
'//                          SM_CYMENUSIZE (menubar height)
'//
'//                        when hTheme is NULL, iSizeId is passed directly
'//                        to the GetSystemMetrics() function
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysSize (BYVAL hTheme AS DWORD, BYVAL iSizeId AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysSize")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysSize(hTheme, iSizeId) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysSize IMPORT "UxTheme.dll" ALIAS "GetThemeSysSize" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iSizeId AS LONG _                              ' __in int iSizeId
 ) AS LONG                                              ' int

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeSysFont()   - Get the LOGFONT for the specified System font.
'//
'//  hTheme              - the theme data handle.  if non-NULL, will return
'//                        font from [SysMetrics] section of theme.
'//                        if NULL, will return the specified system font.
'//
'//  iFontId             - the TMT_XXX font number (first font
'//                        is TMT_CAPTIONFONT)
'//
'//  plf                 - ptr to LOGFONT to receive the font value.
'//                        (scaled for the current logical screen dpi)
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysFont (BYVAL hTheme AS DWORD, BYVAL iFontId AS LONG, BYREF plf AS LOGFONTW) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysFont")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysFont(hTheme, iFontId, plf) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysFont IMPORT "UxTheme.dll" ALIAS "GetThemeSysFont" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iFontId AS LONG _                              ' __in int iFontId
 , BYREF plf AS LOGFONTW _                              ' __out LOGFONTW *plf
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeSysString() - Get the value of specified System string metric.
'//
'//  hTheme              - the theme data handle (required)
'//
'//  iStringId           - must be one of the following values:
'//
'//                          TMT_CSSNAME
'//                          TMT_XMLNAME
'//
'//  pszStringBuff       - the buffer to receive the string value
'//
'//  cchMaxStringChars   - max. number of chars that pszStringBuff can hold
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysString (BYVAL hTheme AS DWORD, BYVAL iStringId AS LONG, _
   BYREF pszStringBuff AS WSTRINGZ, BYVAL cchMaxStringChars AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysString")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysString(hTheme, iStringId, pszStringBuff, cchMaxStringChars) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysString IMPORT "UxTheme.dll" ALIAS "GetThemeSysString" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iStringId AS LONG _                            ' __in int iStringId
 , BYREF pszStringBuff AS WSTRINGZ _                    ' __out LPWSTR pszStringBuff
 , BYVAL cchMaxStringChars AS LONG _                    ' __in int cchMaxStringChars
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeSysInt() - Get the value of specified System int.
'//
'//  hTheme              - the theme data handle (required)
'//
'//  iIntId              - must be one of the following values:
'//
'//                          TMT_DPIX
'//                          TMT_DPIY
'//                          TMT_MINCOLORDEPTH
'//
'//  piValue             - ptr to int to receive value
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeSysInt (BYVAL hTheme AS DWORD, BYVAL iIntId AS LONG, BYREF piValue AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeSysInt")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeSysInt(hTheme, iIntId, piValue) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeSysInt IMPORT "UxTheme.dll" ALIAS "GetThemeSysInt" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iIntId AS LONG _                               ' __in int iIntId
 , BYREF piVal AS LONG _                                ' __out int *piValue
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  IsThemeActive()     - can be used to test if a system theme is active
'//                        for the current user session.
'//
'//                        use the API "IsAppThemed()" to test if a theme is
'//                        active for the calling process.
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION IsThemeActive () AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "IsThemeActive")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING IsThemeActive TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION IsThemeActive IMPORT "UxTheme.dll" ALIAS "IsThemeActive" ( _
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//  IsAppThemed()       - returns TRUE if a theme is active and available to
'//                        the current process
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION IsAppThemed () AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "IsAppThemed")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING IsAppThemed TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION IsAppThemed IMPORT "UxTheme.dll" ALIAS "IsAppThemed" ( _
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//  GetWindowTheme()    - if window is themed, returns its most recent
'//                        HTHEME from OpenThemeData() - otherwise, returns
'//                        NULL.
'//
'//      hwnd            - the window to get the HTHEME of
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetWindowTheme (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetWindowTheme")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetWindowTheme(hwnd) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetWindowTheme IMPORT "UxTheme.dll" ALIAS "GetWindowTheme" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS DWORD                                             ' HTHEME

#ENDIF

%ETDT_DISABLE                    = &H00000001???
%ETDT_ENABLE                     = &H00000002???
%ETDT_USETABTEXTURE              = &H00000004???

%ETDT_ENABLETAB                 = %ETDT_ENABLE OR %ETDT_USETABTEXTURE

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%ETDT_USEAEROWIZARDTABTEXTURE    = &H00000008???

%ETDT_ENABLEAEROWIZARDTAB        = %ETDT_ENABLE OR %ETDT_USEAEROWIZARDTABTEXTURE

%ETDT_VALIDBITS                  = %ETDT_DISABLE OR _
                                   %ETDT_ENABLE OR _
                                   %ETDT_USETABTEXTURE OR _
                                   %ETDT_USEAEROWIZARDTABTEXTURE
#ENDIF

'//---------------------------------------------------------------------------
'//  EnableThemeDialogTexture()
'//
'//  - Enables/disables dialog background theme.  This method can be used to
'//    tailor dialog compatibility with child windows and controls that
'//    may or may not coordinate the rendering of their client area backgrounds
'//    with that of their parent dialog in a manner that supports seamless
'//    background texturing.
'//
'//      hdlg         - the window handle of the target dialog
'//      dwFlags      - ETDT_ENABLE to enable the theme-defined dialog background texturing,
'//                     ETDT_DISABLE to disable background texturing,
'//                     ETDT_ENABLETAB to enable the theme-defined background
'//                          texturing using the Tab texture
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION EnableThemeDialogTexture (BYVAL hwnd AS DWORD, BYVAL dwFlags AS DWORD) AS DWORD

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "EnableThemeDialogTexture")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING EnableThemeDialogTexture(hwnd, dwFlags) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION EnableThemeDialogTexture IMPORT "UxTheme.dll" ALIAS "EnableThemeDialogTexture" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL dwFLags AS DWORD _                             ' __in DWORD dwFLags
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  IsThemeDialogTextureEnabled()
'//
'//  - Reports whether the dialog supports background texturing.
'//
'//      hdlg         - the window handle of the target dialog
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION IsThemeDialogTextureEnabled (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "IsThemeDialogTextureEnabled")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING IsThemeDialogTextureEnabled(hwnd) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION IsThemeDialogTextureEnabled IMPORT "UxTheme.dll" ALIAS "IsThemeDialogTextureEnabled" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL

#ENDIF

'//---------------------------------------------------------------------------
'//---- flags to control theming within an app ----

%STAP_ALLOW_NONCLIENT  = &H01???   ' (1 << 0)
%STAP_ALLOW_CONTROLS   = &H02???   ' (1 << 1)
%STAP_ALLOW_WEBCONTENT = &H04???   ' (1 << 2)
%STAP_VALIDBITS        = %STAP_ALLOW_NONCLIENT OR _
                         %STAP_ALLOW_CONTROLS OR _
                         %STAP_ALLOW_WEBCONTENT

'//---------------------------------------------------------------------------
'//  GetThemeAppProperties()
'//                      - returns the app property flags that control theming
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeAppProperties () AS DWORD

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeAppProperties")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeAppProperties TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeAppProperties IMPORT "UxTheme.dll" ALIAS "GetThemeAppProperties" ( _
 ) AS DWORD                                             ' DWORD

#ENDIF

'//---------------------------------------------------------------------------
'//  SetThemeAppProperties()
'//                      - sets the flags that control theming within the app
'//
'//      dwFlags         - the flag values to be set
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

SUB SetThemeAppProperties (BYVAL dwFlags AS DWORD)

   LOCAL hr AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib THEN
      pProc = GetProcAddress(hLib, "SetThemeAppProperties")
      IF pProc THEN CALL DWORD pProc USING SetThemeAppProperties(dwFlags)
      FreeLibrary hLib
   END IF

END SUB

#ELSE

DECLARE SUB SetThemeAppProperties IMPORT "UxTheme.dll" ALIAS "SetThemeAppProperties" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 )                                                      ' void

#ENDIF

'//---------------------------------------------------------------------------
'//  GetCurrentThemeName()
'//                      - Get the name of the current theme in-use.
'//                        Optionally, return the ColorScheme name and the
'//                        Size name of the theme.
'//
'//  pszThemeFileName    - receives the theme path & filename
'//  cchMaxNameChars     - max chars allowed in pszNameBuff
'//
'//  pszColorBuff        - (optional) receives the canonical color scheme name
'//                        (not the display name)
'//  cchMaxColorChars    - max chars allowed in pszColorBuff
'//
'//  pszSizeBuff         - (optional) receives the canonical size name
'//                        (not the display name)
'//  cchMaxSizeChars     - max chars allowed in pszSizeBuff
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetCurrentThemeName (BYREF pszThemeFileName AS WSTRINGZ, _
   BYVAL cchMaxNameChars AS LONG, BYREF pszColorBuff AS WSTRINGZ, _
   BYVAL cchMaxColorChars AS LONG, BYREF pszSizeBuff AS WSTRINGZ, _
   BYVAL cchMaxSizeChars AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetCurrentThemeName")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetCurrentThemeName(pszThemeFileName, cchMaxNameChars, _
                 pszColorBuff, cchMaxColorChars, pszSizeBuff, cchMaxSizeChars) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetCurrentThemeName IMPORT "UxTheme.dll" ALIAS "GetCurrentThemeName" ( _
   BYREF pszThemeFileName AS WSTRINGZ _                 ' __out_ecount(cchMaxNameChars) LPWSTR pszThemeFileName
 , BYVAL cchMaxNameChars AS LONG _                      ' __in int cchMaxNameChars
 , BYREF pszColorBuff AS WSTRINGZ _                     ' __out_ecount_opt(cchMaxColorChars) LPWSTR pszColorBuff
 , BYVAL cchMaxColorChars AS LONG _                     ' __in int cchMaxColorChars
 , BYREF pszSizeBuff AS WSTRINGZ _                      ' __out_ecount_opt(cchMaxSizeChars) LPWSTR pszSizeBuff
 , BYVAL cchMaxSizeChars AS LONG _                      ' __in int cchMaxSizeChars
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  GetThemeDocumentationProperty()
'//                      - Get the value for the specified property name from
'//                        the [documentation] section of the themes.ini file
'//                        for the specified theme.  If the property has been
'//                        localized in the theme files string table, the
'//                        localized version of the property value is returned.
'//
'//  pszThemeFileName    - filename of the theme file to query
'//  pszPropertyName     - name of the string property to retreive a value for
'//  pszValueBuff        - receives the property string value
'//  cchMaxValChars      - max chars allowed in pszValueBuff
'//---------------------------------------------------------------------------

$SZ_THDOCPROP_DISPLAYNAME   = "DisplayName"
$SZ_THDOCPROP_CANONICALNAME = "ThemeName"
$SZ_THDOCPROP_TOOLTIP       = "ToolTip"
$SZ_THDOCPROP_AUTHOR        = "author"

'THEMEAPI GetThemeDocumentationProperty(LPCWSTR pszThemeName,
'    LPCWSTR pszPropertyName, OUT LPWSTR pszValueBuff, int cchMaxValChars);

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeDocumentationProperty (BYREF pszThemeName AS WSTRINGZ, BYREF pszPropertyName AS WSTRINGZ, _
   BYREF pszValueBuff AS WSTRINGZ, BYVAL cchMaxValChars AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeDocumentationProperty")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeDocumentationProperty(pszThemeName, pszPropertyName, pszValueBuff, cchMaxValChars) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeDocumentationProperty IMPORT "UxTheme.dll" ALIAS "GetThemeDocumentationProperty" ( _
   BYREF pszThemeName AS WSTRINGZ _                     ' __in LPCWSTR pszThemeName
 , BYREF pszPropertyName AS WSTRINGZ _                  ' __in LPCWSTR pszPropertyName
 , BYREF pszValueBuff AS WSTRINGZ _                     ' __out_ecount(cchMaxValChars) LPWSTR pszValueBuff
 , BYVAL cchMaxValChars AS LONG _                       ' __in int cchMaxValChars
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  Theme API Error Handling
'//
'//      All functions in the Theme API not returning an HRESULT (THEMEAPI_)
'//      use the WIN32 function "SetLastError()" to record any call failures.
'//
'//      To retreive the error code of the last failure on the
'//      current thread for these type of API's, use the WIN32 function
'//      "GetLastError()".
'//
'//      All Theme API error codes (HRESULT's and GetLastError() values)
'//      should be normal win32 errors which can be formatted into
'//      strings using the Win32 API FormatMessage().
'//---------------------------------------------------------------------------

'//---------------------------------------------------------------------------
'// DrawThemeParentBackground()
'//                      - used by partially-transparent or alpha-blended
'//                        child controls to draw the part of their parent
'//                        that they appear in front of.
'//
'//  hwnd                - handle of the child control

'//  hdc                 - hdc of the child control

'//  prc                 - (optional) rect that defines the area to be
'//                        drawn (CHILD coordinates)
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeParentBackground (BYVAL hwnd AS DWORD, BYVAL hdc AS DWORD, BYREF prc AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeParentBackground")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeParentBackground(hwnd, hdc, BYVAL VARPTR(prc)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeParentBackground IMPORT "UxTheme.dll" ALIAS "DrawThemeParentBackground" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF prc AS RECT _                                  ' __in_opt RECT* prc
 ) AS LONG                                              ' HRESULT

#ENDIF

'//---------------------------------------------------------------------------
'//  EnableTheming()     - enables or disables themeing for the current user
'//                        in the current and future sessions.
'//
'//  fEnable             - if FALSE, disable theming & turn themes off.
'//                      - if TRUE, enable themeing and, if user previously
'//                        had a theme active, make it active now.
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION EnableTheming (BYVAL fEnable AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "EnableTheming")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING EnableTheming(fEnable) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION EnableTheming IMPORT "UxTheme.dll" ALIAS "EnableTheming" ( _
   BYVAL fEnable AS LONG _                              ' __in BOOL fEnable
 ) AS LONG                                              ' HRESULT

#ENDIF

%GBF_DIRECT      = &H00000001      ' // direct dereferencing.
%GBF_COPY        = &H00000002      ' // create a copy of the bitmap
%GBF_VALIDBITS   = %GBF_DIRECT OR %GBF_COPY

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

%DTPB_WINDOWDC           = &H00000001???
%DTPB_USECTLCOLORSTATIC  = &H00000002???
%DTPB_USEERASEBKGND      = &H00000004???


'//---------------------------------------------------------------------------
'// DrawThemeParentBackgroundEx()
'//                      - used by partially-transparent or alpha-blended
'//                        child controls to draw the part of their parent
'//                        that they appear in front of.
'//                        Sends a WM_ERASEBKGND message followed by a WM_PRINTCLIENT.
'//
'//  hwnd                - handle of the child control
'//
'//  hdc                 - hdc of the child control
'//
'//  dwFlags             - if 0, only returns S_OK if the parent handled
'//                        WM_PRINTCLIENT.
'//                      - if DTPB_WINDOWDC is set, hdc is assumed to be a window DC,
'//                        not a client DC.
'//                      - if DTPB_USEERASEBKGND is set, the function will return S_OK
'//                        without sending a WM_CTLCOLORSTATIC message if the parent
'//                        actually painted on WM_ERASEBKGND.
'//                      - if DTPB_CTLCOLORSTATIC is set, the function will send
'//                        a WM_CTLCOLORSTATIC message to the parent and use the
'//                        brush if one is provided, else COLOR_BTNFACE.
'//
'//  prc                 - (optional) rect that defines the area to be
'//                        drawn (CHILD coordinates)
'//
'//  Return value        - S_OK if something was painted, S_FALSE if not.
'//---------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeParentBackgroundEx (BYVAL hwnd AS DWORD, BYVAL hdc AS DWORD, BYVAL dwFlags AS DWORD, BYREF prc AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeParentBackgroundEx")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeParentBackgroundEx(hwnd, hdc, dwFlags, BYVAL VARPTR(prc)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeParentBackgroundEx IMPORT "UxTheme.dll" ALIAS "DrawThemeParentBackgroundEx" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF prc AS RECT _                                  ' __in_opt RECT* prc
 ) AS LONG                                              ' HRESULT

#ENDIF

' enum WINDOWTHEMEATTRIBUTETYPE
%WTA_NONCLIENT = 1

' // Size = 8 bytes
TYPE WTA_OPTIONS DWORD
   dwFlags AS DWORD   ' DWORD // values for each style option specified in the bitmask
   dwMask  AS DWORD   ' DWORD // bitmask for flags that are changing
                      ' // valid options are: WTNCA_NODRAWCAPTION, WTNCA_NODRAWICON, WTNCA_NOSYSMENU
END TYPE

%WTNCA_NODRAWCAPTION       = &H00000001???    ' // don't draw the window caption
%WTNCA_NODRAWICON          = &H00000002???    ' // don't draw the system icon
%WTNCA_NOSYSMENU           = &H00000004???    ' // don't expose the system menu icon functionality
%WTNCA_NOMIRRORHELP        = &H00000008???    ' // don't mirror the question mark, even in RTL layout
%WTNCA_VALIDBITS           = %WTNCA_NODRAWCAPTION OR _
                             %WTNCA_NODRAWICON OR _
                             %WTNCA_NOSYSMENU OR _
                             %WTNCA_NOMIRRORHELP

#IF %DEF(%USELOADLIBRARY)

FUNCTION SetWindowThemeAttribute (BYVAL hwnd AS DWORD, BYVAL eAttribute AS LONG, _
   BYVAL pvAttribute AS DWORD, BYVAL cbAttribute AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "SetWindowThemeAttribute")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING SetWindowThemeAttribute(hwnd, eAttribute, pvAttribute, cbAttribute) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION SetWindowThemeAttribute IMPORT "UxTheme.dll" ALIAS "SetWindowThemeAttribute" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL eAttribute AS LONG _                           ' __in enum WINDOWTHEMEATTRIBUTETYPE eAttribute
 , BYVAL pvAttribute AS DWORD _                         ' __in_bcount(cbAttribute) PVOID pvAttribute
 , BYVAL cbAttribute AS DWORD _                         ' __in DWORD cbAttribute
 ) AS LONG                                              ' HRESULT

#ENDIF

'__inline HRESULT SetWindowThemeNonClientAttributes(HWND hwnd, DWORD dwMask, DWORD dwAttributes)
'{
'    WTA_OPTIONS wta;
'    wta.dwFlags = dwAttributes;
'    wta.dwMask = dwMask;
'    return SetWindowThemeAttribute(hwnd, WTA_NONCLIENT, (void*)&(wta), sizeof(wta));
'}

'FUNCTION SetWindowThemeNonClientAttributes(BYVAL hwnd AS DWORD, BYVAL dwMask AS DWORD, BYVAL dwAttributes AS DWORD) AS LONG
'   LOCAL wta AS WTA_OPTIONS
'   wta.dwFlags = dwAttributes
'   wta.dwMask = dwMask
'   FUNCTION = SetWindowThemeAttribute(hwnd, %WTA_NONCLIENT, BYVAL VARPTR(wta), SIZEOF(wta))
'END FUNCTION

' Because the SetWindowThemeAttribute function is only available in Windows Vista, and we
' are calling it, we need to use a macro or the program will fail in other Windows versions.
MACRO FUNCTION SetWindowThemeNonClientAttributes(hwnd, dwMask, dwAttributes)
   MACROTEMP wta
   LOCAL wta AS WTA_OPTIONS
   wta.dwFlags = dwAttributes
   wta.dwMask = dwMask
END MACRO = SetWindowThemeAttribute(hwnd, %WTA_NONCLIENT, BYVAL VARPTR(wta), SIZEOF(wta))

#ENDIF   ' // #if (_WIN32_WINNT >= 0x0600)

'//---------------------------------------------------------------------------
'//
'// DrawThemeTextEx
'//

'// Callback function used by DrawTextWithGlow instead of DrawTextW
'typedef
'int
'(WINAPI *DTT_CALLBACK_PROC)
'(
'    __in HDC hdc,
'    __inout_ecount(cchText) LPWSTR pszText,
'    __in int cchText,
'    __inout LPRECT prc,
'    __in UINT dwFlags,
'    __in LPARAM lParam);

'FUNCTION DTT_CALLBACK_PROC (BYVAL hdc AS DWORD, BYVAL pszText AS DWORD, BYVAL cchText AS LONG, _
'   BYREF prc AS RECT, BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG) AS LONG

'//---- bits used in dwFlags of DTTOPTS ----
%DTT_TEXTCOLOR       = &H1     ' (1UL << 0)      // crText has been specified
%DTT_BORDERCOLOR     = &H2     ' (1UL << 1)      // crBorder has been specified
%DTT_SHADOWCOLOR     = &H4     ' (1UL << 2)      // crShadow has been specified
%DTT_SHADOWTYPE      = &H8     ' (1UL << 3)      // iTextShadowType has been specified
%DTT_SHADOWOFFSET    = &H10    ' (1UL << 4)      // ptShadowOffset has been specified
%DTT_BORDERSIZE      = &H20    ' (1UL << 5)      // iBorderSize has been specified
%DTT_FONTPROP        = &H40    ' (1UL << 6)      // iFontPropId has been specified
%DTT_COLORPROP       = &H80    ' (1UL << 7)      // iColorPropId has been specified
%DTT_STATEID         = &H100   ' (1UL << 8)      // IStateId has been specified
%DTT_CALCRECT        = &H200   ' (1UL << 9)      // Use pRect as and in/out parameter
%DTT_APPLYOVERLAY    = &H400   ' (1UL << 10)     // fApplyOverlay has been specified
%DTT_GLOWSIZE        = &H800   ' (1UL << 11)     // iGlowSize has been specified
%DTT_CALLBACK        = &H1000  ' (1UL << 12)     // pfnDrawTextCallback has been specified
%DTT_COMPOSITED      = &H2000  ' (1UL << 13)     // Draws text with antialiased alpha (needs a DIB section)
%DTT_VALIDBITS       = %DTT_TEXTCOLOR OR _
                       %DTT_BORDERCOLOR OR _
                       %DTT_SHADOWCOLOR OR _
                       %DTT_SHADOWTYPE OR _
                       %DTT_SHADOWOFFSET OR _
                       %DTT_BORDERSIZE OR _
                       %DTT_FONTPROP OR _
                       %DTT_COLORPROP OR _
                       %DTT_STATEID OR _
                       %DTT_CALCRECT OR _
                       %DTT_APPLYOVERLAY OR _
                       %DTT_GLOWSIZE OR _
                       %DTT_COMPOSITED

' // Size = 64 bytes
TYPE DTTOPTS DWORD
   dwSize              AS DWORD      ' DWORD // size of the struct
   dwFlags             AS DWORD      ' DWORD // which options have been specified
   crText              AS DWORD      ' COLORREF // color to use for text fill
   crBorder            AS DWORD      ' COLORREF // color to use for text outline
   crShadow            AS DWORD      ' COLORREF // color to use for text shadow
   iTextShadowType     AS LONG       ' int // TST_SINGLE or TST_CONTINUOUS
   ptShadowOffset      AS POINT      ' POINT // where shadow is drawn (relative to text)
   iBorderSize         AS LONG       ' int // Border radius around text
   iFontPropId         AS LONG       ' int // Font property to use for the text instead of TMT_FONT
   iColorPropId        AS LONG       ' int // Color property to use for the text instead of TMT_TEXTCOLOR
   iStateId            AS LONG       ' int // Alternate state id
   fApplyOverlay       AS LONG       ' BOOL // Overlay text on top of any text effect?
   iGlowSize           AS LONG       ' int // Glow radious around text
   pfnDrawTextCallback AS DWORD      ' DTT_CALLBACK_PROC // Callback for DrawText
   lParam              AS LONG       ' LPARAM // Parameter for callback
END TYPE

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

#IF %DEF(%USELOADLIBRARY)

FUNCTION DrawThemeTextEx (BYVAL hTheme AS DWORD, BYVAL hdc AS DWORD, _
   BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, BYREF pszText AS WSTRINGZ, _
   BYVAL cchText AS LONG, BYVAL dwTextFlags AS DWORD, _
   BYREF pRect AS RECT, BYREF pOptions AS DTTOPTS) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "DrawThemeTextEx")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING DrawThemeTextEx(hTheme, hdc, iPartId, iStateId, _
                 pszText, cchText, dwTextFlags, pRect, BYVAL VARPTR(pOptions)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION DrawThemeTextEx IMPORT "UxTheme.dll" ALIAS "DrawThemeTextEx" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYREF pszText AS WSTRINGZ _                          ' __in LPCWSTR pszText
 , BYVAL cchText AS LONG _                              ' __in int cchText
 , BYVAL dwTextFlags AS DWORD _                         ' __in DWORD dwTextFlags
 , BYREF pRect AS RECT _                                ' __inout const RECT *pRect
 , BYREF pOptions AS DTTOPTS _                          ' __in_opt const DTTOPTS *pOptions
 ) AS LONG                                              ' HRESULT

#ENDIF

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeBitmap (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYVAL dwFlags AS DWORD, BYREF phBitmap AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeBitmap")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeBitmap(hTheme, iPartId, iStateId, iPropId, dwFlags, phBitmap) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeBitmap IMPORT "UxTheme.dll" ALIAS "GetThemeBitmap" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYVAL dwFlags AS DWORD _                             ' __in ULONG dwFlags
 , BYREF phBitmap AS DWORD _                            ' __out HBITMAP* phBitmap
 ) AS LONG                                              ' HRESULT

#ENDIF

'//-----------------------------------------------------------------------
'//  GetThemeStream() - Get the value for the specified STREAM property
'//
'//      hTheme      - theme data handle
'//      iPartId     - part number
'//      iStateId    - state number of part
'//      iPropId     - the property number to get the value for
'//      ppvStream   - if non-null receives the value of the STREAM property (not to be freed)
'//      pcbStream   - if non-null receives the size of the STREAM property
'//      hInst       - NULL when iPropId==TMT_STREAM, HINSTANCE of a loaded msstyles
'//                    file when iPropId==TMT_DISKSTREAM (use GetCurrentThemeName
'//                    and LoadLibraryEx(LOAD_LIBRARY_AS_DATAFILE)
'//-----------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeStream (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, BYVAL iStateId AS LONG, _
   BYVAL iPropId AS LONG, BYREF ppvStream AS DWORD, BYREF pcbStream AS DWORD, BYVAL hInst AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeStream")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeStream(hTheme, iPartId, iStateId, iPropId, ppvStream, pcbStream, hInst) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeStream IMPORT "UxTheme.dll" ALIAS "GetThemeStream" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateId
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF ppvStream AS DWORD _                           ' __out VOID **ppvStream
 , BYREF pcbStream AS DWORD _                           ' __out_opt DWORD *pcbStream
 , BYVAL hInst AS DWORD _                               ' __in hInst
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  BufferedPaintInit() - Initialize the Buffered Paint API.
'//                        Should be called prior to BeginBufferedPaint,
'//                        and should have a matching BufferedPaintUnInit.
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION BufferedPaintInit () AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "BufferedPaintInit")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING BufferedPaintInit() TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION BufferedPaintInit IMPORT "UxTheme.dll" ALIAS "BufferedPaintInit" ( _
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  BufferedPaintUnInit() - Uninitialize the Buffered Paint API.
'//                          Should be called once for each call to BufferedPaintInit,
'//                          when calls to BeginBufferedPaint are no longer needed.
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION BufferedPaintUnInit () AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "BufferedPaintUnInit")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING BufferedPaintUnInit() TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION BufferedPaintUnInit IMPORT "UxTheme.dll" ALIAS "BufferedPaintUnInit" ( _
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  BeginBufferedPaint() - Begins a buffered paint operation.
'//
'//    hdcTarget          - Target DC on which the buffer will be painted
'//    rcTarget           - Rectangle specifying the area of the target DC to paint to
'//    dwFormat           - Format of the buffer (see BP_BUFFERFORMAT)
'//    pPaintParams       - Paint operation parameters (see BP_PAINTPARAMS)
'//    phBufferedPaint    - Pointer to receive handle to new buffered paint context
'//------------------------------------------------------------------------

'// HPAINTBUFFER
'typedef HANDLE HPAINTBUFFER;  // handle to a buffered paint context


'// BP_BUFFERFORMAT
' enum BP_BUFFERFORMAT
%BPBF_COMPATIBLEBITMAP = 0   ' // Compatible bitmap
%BPBF_DIB              = 1   ' // Device-independent bitmap
%BPBF_TOPDOWNDIB       = 2   ' // Top-down device-independent bitmap
%BPBF_TOPDOWNMONODIB   = 3   ' // Top-down monochrome device-independent bitmap

%BPBF_COMPOSITED = %BPBF_TOPDOWNDIB

'// BP_ANIMATIONSTYLE
' enum BP_ANIMATIONSTYLE
%BPAS_NONE   = 0             ' // No animation
%BPAS_LINEAR = 1             ' // Linear fade animation
%BPAS_CUBIC  = 2             ' // Cubic fade animation
%BPAS_SINE   = 3             ' // Sinusoid fade animation

'// BP_ANIMATIONPARAMS
' // Size = 16 bytes
TYPE BP_ANIMATIONPARAMS DWORD
   cbSize     AS DWORD   ' DWORD
   dwFlags    AS DWORD   ' DWORD // BPAF_ flags
   style      AS DWORD   ' BP_ANIMATIONSTYLE
   dwDuration AS DWORD   ' DWORD
END TYPE

%BPPF_ERASE     = &H0001???   ' // Empty the buffer during BeginBufferedPaint()
%BPPF_NOCLIP    = &H0002???   ' // Don't apply the target DC's clip region to the double buffer
%BPPF_NONCLIENT = &H0004???   ' // Using a non-client DC

'// BP_PAINTPARAMS
' // Size = 16 bytes
TYPE BP_PAINTPARAMS DWORD
   cbSize         AS DWORD               ' DWORD
   dwFlags        AS DWORD               ' DWORD // BPPF_ flags
   prcExclude     AS RECT PTR            ' RECT *
   pBlendFunction AS BLENDFUNCTION PTR   ' BLENDFUNCTION *
END TYPE

#IF %DEF(%USELOADLIBRARY)

FUNCTION BeginBufferedPaint (BYVAL hdc AS DWORD, BYREF prcTarget AS RECT, BYVAL dwFormat AS DWORD, _
   BYREF pPaintParams AS BP_PAINTPARAMS, BYREF phdc AS DWORD) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "BeginBufferedPaint")
   IF pProc THEN CALL DWORD pProc USING BeginBufferedPaint(hdc, prcTarget, dwFormat, BYVAL VARPTR(pPaintParams), phdc) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

#ELSE

DECLARE FUNCTION BeginBufferedPaint IMPORT "UxTheme.dll" ALIAS "BeginBufferedPaint" ( _
   BYVAL hdcTarget AS DWORD _                           ' __in HDC hdcTarget
 , BYREF prcTarget AS RECT _                            ' __in const RECT* prcTarget
 , BYVAL dwFormat AS DWORD _                            ' __in BP_BUFFERFORMAT dwFormat
 , BYREF pPaintParams AS BP_PAINTPARAMS _               ' __in_opt BP_PAINTPARAMS *pPaintParams
 , BYREF phdc AS DWORD _                                ' __out HDC *phdc
 ) AS DWORD                                             ' HPAINTBUFFER

#ENDIF

'//------------------------------------------------------------------------
'//  EndBufferedPaint() - Ends a buffered paint operation.
'//
'//    hBufferedPaint   - handle to buffered paint context
'//    fUpdateTarget    - update target DC
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION EndBufferedPaint (BYVAL hBufferedPaint AS DWORD, BYVAL fUpdateTarget AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "EndBufferedPaint")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING EndBufferedPaint(hBufferedPaint, fUpdateTarget) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION EndBufferedPaint IMPORT "UxTheme.dll" ALIAS "EndBufferedPaint" ( _
   BYVAL hBufferedPaint AS DWORD _                      ' __in HPAINTBUFFER hBufferedPaint
 , BYVAL fUpdateTarget AS LONG _                        ' __in BOOL fUpdateTarget
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  GetBufferedPaintTargetRect() - Returns the target rectangle specified during BeginBufferedPaint
'//
'//    hBufferedPaint             - handle to buffered paint context
'//    prc                        - pointer to receive target rectangle
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetBufferedPaintTargetRect (BYVAL hBufferedPaint AS DWORD, BYREF prc AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetBufferedPaintTargetRect")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetBufferedPaintTargetRect(hBufferedPaint, prc) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetBufferedPaintTargetRect IMPORT "UxTheme.dll" ALIAS "GetBufferedPaintTargetRect" ( _
   BYVAL hBufferedPaint AS DWORD _                      ' __in HPAINTBUFFER hBufferedPaint
 , BYREF prc AS RECT _                                  ' __out RECT *prc
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  GetBufferedPaintTargetDC() - Returns the target DC specified during BeginBufferedPaint
'//
'//    hBufferedPaint           - handle to buffered paint context
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetBufferedPaintTargetDC (BYVAL hBufferedPaint AS DWORD) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "GetBufferedPaintTargetDC")
   IF pProc THEN CALL DWORD pProc USING GetBufferedPaintTargetDC(hBufferedPaint) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

#ELSE

DECLARE FUNCTION GetBufferedPaintTargetDC IMPORT "UxTheme.dll" ALIAS "GetBufferedPaintTargetDC" ( _
   BYVAL hBufferedPaint AS DWORD _                      ' __in HPAINTBUFFER hBufferedPaint
 ) AS DWORD                                             ' HDC

#ENDIF

'//------------------------------------------------------------------------
'//  GetBufferedPaintBits() - Obtains a pointer to the buffer bitmap, if the buffer is a DIB
'//
'//    hBufferedPaint       - handle to buffered paint context
'//    ppbBuffer            - pointer to receive pointer to buffer bitmap pixels
'//    pcxRow               - pointer to receive width of buffer bitmap, in pixels;
'//                           this value may not necessarily be equal to the buffer width
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetBufferedPaintBits (BYVAL hBufferedPaint AS DWORD, BYREF ppbBuffer AS DWORD, BYREF pcxRow AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetBufferedPaintBits")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetBufferedPaintBits(hBufferedPaint, ppbBuffer, pcxRow) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetBufferedPaintBits IMPORT "UxTheme.dll" ALIAS "GetBufferedPaintBits" ( _
   BYVAL hBufferedPaint AS DWORD _                      ' __in HPAINTBUFFER hBufferedPaint
 , BYREF ppbBuffer AS DWORD _                           ' __out RGBQUAD **ppbBuffer
 , BYREF pcxRow AS LONG _                               ' __out int *pcxRow
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  BufferedPaintClear() - Clears given rectangle to ARGB = {0, 0, 0, 0}
'//
'//    hBufferedPaint     - handle to buffered paint context
'//    prc                - rectangle to clear; NULL specifies entire buffer
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION BufferedPaintClear (BYVAL hBufferedPaint AS DWORD, BYREF prc AS RECT) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "BufferedPaintClear")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING BufferedPaintClear(hBufferedPaint, BYVAL VARPTR(prc)) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION BufferedPaintClear IMPORT "UxTheme.dll" ALIAS "BufferedPaintClear" ( _
   BYVAL hBufferedPaint AS DWORD _                      ' __in HPAINTBUFFER hBufferedPaint
 , BYREF prc AS RECT _                                  ' __in_opt const RECT *prc
 ) AS LONG                                              ' HRESULT

#ENDIF

'//------------------------------------------------------------------------
'//  BufferedPaintSetAlpha() - Set alpha to given value in given rectangle
'//
'//    hBufferedPaint        - handle to buffered paint context
'//    prc                   - rectangle to set alpha in; NULL specifies entire buffer
'//    alpha                 - alpha value to set in the given rectangle
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION BufferedPaintSetAlpha (BYVAL hBufferedPaint AS DWORD, BYREF prc AS RECT, BYVAL alpha AS BYTE) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "BufferedPaintSetAlpha")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING BufferedPaintSetAlpha(hBufferedPaint, BYVAL VARPTR(prc), alpha) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION BufferedPaintSetAlpha IMPORT "UxTheme.dll" ALIAS "BufferedPaintSetAlpha" ( _
   BYVAL hBufferedPaint AS DWORD _                      ' __in HPAINTBUFFER hBufferedPaint
 , BYREF prc AS RECT _                                  ' __in_opt const RECT *prc
 , BYVAL alpha AS BYTE _                                ' __in BYTE alpha
 ) AS LONG                                              ' HRESULT

#ENDIF

'// Macro for setting the buffer to opaque (alpha = 255)
'#define BufferedPaintMakeOpaque(hBufferedPaint, prc) BufferedPaintSetAlpha(hBufferedPaint, prc, 255)

MACRO BufferedPaintMakeOpaque(hBufferedPaint, prc) = BufferedPaintSetAlpha(hBufferedPaint, prc, 255)

'//------------------------------------------------------------------------
'//  BufferedPaintStopAllAnimations() - Stop all buffer animations for the given window
'//
'//    hwnd                           - window on which to stop all animations
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION BufferedPaintStopAllAnimations (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "BufferedPaintStopAllAnimations")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING BufferedPaintStopAllAnimations(hwnd) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION BufferedPaintStopAllAnimations IMPORT "UxTheme.dll" ALIAS "BufferedPaintStopAllAnimations" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

#ENDIF

'typedef HANDLE HANIMATIONBUFFER;  // handle to a buffered paint animation

#IF %DEF(%USELOADLIBRARY)

FUNCTION BeginBufferedAnimation (BYVAL hwnd AS DWORD, BYVAL hdcTarget AS DWORD, _
   BYREF prcTarget AS RECT, BYVAL dwFormat AS DWORD, BYREF pPaintParams AS BP_PAINTPARAMS, _
   BYREF pAnimationParams AS BP_ANIMATIONPARAMS, BYREF phdcFrom AS DWORD, BYREF phdcTo AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "BeginBufferedAnimation")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING BeginBufferedAnimation(hwnd, hdcTarget, prcTarget, dwFormat, _
                 BYVAL VARPTR(pPaintParams), pAnimationParams, phdcFrom, phdcTo) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION BeginBufferedAnimation IMPORT "UxTheme.dll" ALIAS "BeginBufferedAnimation" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdcTarget
 , BYREF prcTarget AS RECT _                            ' __in const RECT* prcTarget
 , BYVAL dwFormat AS DWORD _                            ' __in BP_BUFFERFORMAT dwFormat
 , BYREF pPaintParams AS BP_PAINTPARAMS _               ' __in_opt BP_PAINTPARAMS *pPaintParams
 , BYREF pAnimationParams AS BP_ANIMATIONPARAMS _       ' __in BP_ANIMATIONPARAMS *pAnimationParams
 , BYREF phdcFrom AS DWORD _                            ' __out HDC *phdcFrom
 , BYREF phdcTo AS DWORD _                              ' __out HDC *phdcTo
 ) AS DWORD                                             ' HANIMATIONBUFFER

#ENDIF

#IF %DEF(%USELOADLIBRARY)

FUNCTION EndBufferedAnimation (BYVAL hbpAnimation AS DWORD, BYVAL fUpdateTarget AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "EndBufferedAnimation")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING EndBufferedAnimation(hbpAnimation, fUpdateTarget) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION EndBufferedAnimation IMPORT "UxTheme.dll" ALIAS "EndBufferedAnimation" ( _
   BYVAL hbpAnimation AS DWORD _                        ' __in HANIMATIONBUFFER hbpAnimation
 , BYVAL fUpdateTarget AS LONG _                        ' __in BOOL fUpdateTarget
 ) AS LONG                                              ' HRESULT

#ENDIF

#IF %DEF(%USELOADLIBRARY)

FUNCTION BufferedPaintRenderAnimation (BYVAL hwnd AS DWORD, BYVAL hdcTarget AS DWORD) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "BufferedPaintRenderAnimation")
   IF pProc THEN CALL DWORD pProc USING BufferedPaintRenderAnimation(hwnd, hdcTarget) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION BufferedPaintRenderAnimation IMPORT "UxTheme.dll" ALIAS "BufferedPaintRenderAnimation" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdcTarget
 ) AS LONG                                              ' BOOL

#ENDIF

'//----------------------------------------------------------------------------
'// Tells if the DWM is running, and composition effects are possible for this
'// process (themes are active).
'// Roughly equivalent to "DwmIsCompositionEnabled() && IsAppthemed()"
'//----------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION IsCompositionActive () AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "IsCompositionActive")
   IF pProc THEN CALL DWORD pProc USING IsCompositionActive() TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#ELSE

DECLARE FUNCTION IsCompositionActive IMPORT "UxTheme.dll" ALIAS "IsCompositionActive" ( _
 ) AS LONG                                              ' BOOL

#ENDIF

'//------------------------------------------------------------------------
'//  GetThemeTransitionDuration()
'//                      - Gets the duration for the specified transition
'//
'//  hTheme              - theme data handle
'//  iPartId             - part number
'//  iStateIdFrom        - starting state number of part
'//  iStateIdTo          - ending state number of part
'//  iPropId             - property id
'//  pdwDuration         - receives the transition duration
'//------------------------------------------------------------------------

#IF %DEF(%USELOADLIBRARY)

FUNCTION GetThemeTransitionDuration (BYVAL hTheme AS DWORD, BYVAL iPartId AS LONG, _
   BYVAL iStateIdFrom AS LONG, BYVAL iStateIdTo AS LONG, BYVAL iPropId AS LONG, BYREF pdwDuration AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("UxTheme.dll")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pProc = GetProcAddress(hLib, "GetThemeTransitionDuration")
   IF pProc = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pProc USING GetThemeTransitionDuration(hTheme, iPartId, iStateIdFrom, iStateIdTo, iPropId, pdwDuration) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

#ELSE

DECLARE FUNCTION GetThemeTransitionDuration IMPORT "UxTheme.dll" ALIAS "GetThemeTransitionDuration" ( _
   BYVAL hTheme AS DWORD _                              ' __in HTHEME hTheme
 , BYVAL iPartId AS LONG _                              ' __in int iPartId
 , BYVAL iStateId AS LONG _                             ' __in int iStateIdFrom
 , BYVAL iStateId AS LONG _                             ' __in int iStateIdTo
 , BYVAL iPropId AS LONG _                              ' __in int iPropId
 , BYREF pdwDuration AS DWORD _                         ' __out DWORD *pdwDuration
 ) AS LONG                                              ' HRESULT

#ENDIF

#ENDIF ' // #if (_WIN32_WINNT >= 0x0600)
