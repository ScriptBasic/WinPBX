' ########################################################################################
' Ole Container
' IID = {D787824E-AE0D-4EE7-833F-068E47917283}
' (C) 2008-2010 José Roca. All rights reserved.
' This software is freeware, not public domain. This means that you can use and modify
' it for your own purposes, even in commercial applications, without paying a fee, but not
' to make derivative works from, sell or redistribute without permission.
' ########################################################################################

' ########################################################################################
' DISCLAIMER: The software and accompanying documentation are provided "as is" and without
' warranties as to performance or merchantability or any other warranties whether
' expressed or implied. Because of the various hardware environments into which the
' software may be used, no warranty of fitness for a particular purpose is offered. The
' user must assume the entire risk of using the software. In no case shall any of the
' contributors to this project be liable for any incidental, special or consequential
' damages or loss, including, without limitation, lost profits or the inability to use
' equipment or access data. This is true even if we are advised of the possibility of such
' damages. We also don't have any obligation of fix eventual bugs or to add new features.
' ########################################################################################

#INCLUDE THIS ONCE
%OLECON_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "olectl.inc"
#INCLUDE ONCE "docobj.inc"
#INCLUDE ONCE "shlguid.inc"
#INCLUDE ONCE "vbinterf.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "MsHtmdid.inc"
#INCLUDE ONCE "ole2utils.inc"

$OC_CLASSNAME = "OC_WIN32"                           ' // Container's class name
$OC_IID = "{D787824E-AE0D-4EE7-833F-068E47917283}"   ' // Container's IID

' ========================================================================================
' Macro for debug
' To allow debugging, define %OC_DEBUG = 1 in your application before including this file.
' ========================================================================================
#IF NOT %DEF(%OC_DEBUG)
%OC_DEBUG = 0   ' // 0 to disable debugging, 1 to enable
#ENDIF
#IF NOT %DEF(%OC_DP)
%OC_DP = 1
MACRO OC_DP(st)
   #IF %OC_DEBUG
      OutputDebugString BYCOPY st
   #ENDIF
END MACRO
#ENDIF
' ========================================================================================

' ========================================================================================
' Converts from Pixel to HiMetric
' Note: Himetric is a scaling unit similar to twips used in computing. It is one
' thousandth of a centimeter and is independent of the screen resolution.
' %HIMETRIC_PER_INCH = 2540   ' 1 inch = 2.54 mm
' ========================================================================================
SUB OC_PixelsToHiMetric (BYREF SizeInPix AS SIZEL, BYREF SizeInHiMetric AS SIZEL)

   LOCAL nPixelsPerInchX AS LONG   ' // Pixels per logical inch along width
   LOCAL nPixelsPerInchY AS LONG   ' // Pixels per logical inch along height

   LOCAL hDCSCreen AS DWORD
   hDCScreen = GetDC(%NULL)
   IF hDCScreen = %NULL THEN EXIT SUB
   nPixelsPerInchX = GetDeviceCaps(hDCScreen, %LOGPIXELSX)
   nPixelsPerInchY = GetDeviceCaps(hDCScreen, %LOGPIXELSY)
   ReleaseDC(%NULL, hDCScreen)

   SizeInHiMetric.cx = MulDiv(SizeInPix.cx, 2540, nPixelsPerInchX)
   SizeInHiMetric.cy = MulDiv(SizeInPix.cy, 2540, nPixelsPerInchY)

END SUB
' ========================================================================================

' ========================================================================================
' External functions and procedures
' ========================================================================================
DECLARE FUNCTION OC_OleRun IMPORT "OLE32.DLL" ALIAS "OleRun" (BYVAL pUnknown AS DWORD) AS LONG
DECLARE FUNCTION OC_OleLockRunning IMPORT "OLE32.DLL" ALIAS "OleLockRunning" (BYVAL pUnknown AS DWORD, BYVAL fLock AS LONG, BYVAL fLastUnlockCloses AS LONG) AS LONG
' ========================================================================================
' ========================================================================================
' This function must be called by ordinal because it isn't exported by name in XP and below.
'DECLARE FUNCTION OC_IUnknown_QueryService IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_QueryService" ( _
'   BYVAL punk AS DWORD _                                ' __in IUnknown* punk
' , BYREF guidService AS GUID _                          ' __in REFGUID guidService
' , BYREF riid AS GUID _                                 ' __in REFIID riid
' , BYREF ppvOut AS DWORD _                              ' __out void ** ppvOut
' ) AS LONG                                              ' HRESULT
' ========================================================================================
' ========================================================================================
FUNCTION OC_IUnknown_QueryService ( _
   BYVAL punk AS DWORD _                                ' __in IUnknown* punk
 , BYREF guidService AS GUID _                          ' __in REFGUID guidService
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvOut AS DWORD _                              ' __out void ** ppvOut
 ) AS LONG                                              ' HRESULT

   ' // Load the shell library
   LOCAL hLib AS DWORD
   hLib = LoadLibrary("Shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   ' // Get the address of the function (ordinal 176)
   LOCAL pProc AS DWORD
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 176, 0))
   IF ISTRUE pProc THEN
      ' // Call the function
      LOCAL hr AS LONG
      CALL DWORD pProc USING OC_IUnknown_QueryService(pUnk, guidService, riid, ppvOut) TO hr
      FUNCTION = hr
   END IF
   ' // Free the library
   FreeLibrary hLib

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the interface name for debugging purposes
' ========================================================================================
FUNCTION OC_GetInterfaceName (BYREF riid AS GUID) AS STRING

   IF riid = $IID_IUnknown THEN
      FUNCTION = "IID_IUnknown"
   ELSEIF riid = $IID_IDispatch THEN
      FUNCTION = "IID_IDispatch"
   ELSEIF riid = $IID_IAdviseSink THEN
      FUNCTION = "IID_IAdviseSink"
   ELSEIF riid = $IID_IErrorInfo THEN
      FUNCTION = "IID_IErrorInfo"
   ELSEIF riid = $IID_IOleClientSite THEN
      FUNCTION = "IID_IOleClientSite"
   ELSEIF riid = $IID_IOleContainer THEN
      FUNCTION = "IID_IOleContainer"
   ELSEIF riid = $IID_IOleControl THEN
      FUNCTION = "IID_IOleControl"
   ELSEIF riid = $IID_IOleControlSite THEN
      FUNCTION = "IID_IOleControlSite"
   ELSEIF riid = $IID_IOleDocumentSite THEN
      FUNCTION = "IID_IOleDocumentSite"
   ELSEIF riid = $IID_IOleInPlaceActiveObject THEN
      FUNCTION = "IID_IOleInPlaceActiveObject"
   ELSEIF riid = $IID_IOleInPlaceFrame THEN
      FUNCTION = "IID_IOleInPlaceFrame"
   ELSEIF riid = $IID_IOleInPlaceObject THEN
      FUNCTION = "IID_IOleInPlaceObject"
   ELSEIF riid = $IID_IOleInPlaceObjectWindowless THEN
      FUNCTION = "IID_IOleInPlaceObjectWindowless"
   ELSEIF riid = $IID_IOleInPlaceSite THEN
      FUNCTION = "IID_IOleInPlaceSite"
   ELSEIF riid = $IID_IOleInPlaceSiteEx THEN
      FUNCTION = "IID_IOleInPlaceSiteEx"
   ELSEIF riid = $IID_IOleInPlaceUIWindow THEN
      FUNCTION = "IID_IOleInPlaceUIWindow"
   ELSEIF riid = $IID_IOleObject THEN
      FUNCTION = "IID_IOleObject"
   ELSEIF riid = $IID_IOleWindow THEN
      FUNCTION = "IID_IOleWindow"
   ELSEIF riid = $IID_IParseDisplayName THEN
      FUNCTION = "IID_IParseDisplayName"
   ELSEIF riid = $IID_IPersistStreamInit THEN
      FUNCTION = "IID_IPersistStreamInit"
   ELSEIF riid = $IID_IPropertyNotifySink THEN
      FUNCTION = "IID_IPropertyNotifySink"
   ELSEIF riid = $IID_IServiceProvider THEN
      FUNCTION = "IID_IServiceProvider"
   ELSEIF riid = $IID_ISimpleFrameSite THEN
      FUNCTION = "IID_ISimpleFrameSite"
   ' // VB-only interfaces - Listed here for debugging purposes
   ELSEIF riid = $IID_IVBGetControl THEN
      FUNCTION = "IID_IVBGetControl"
   ELSEIF riid = $IID_IGetOleObject THEN
      FUNCTION = "IID_IGetOleObject"
   ELSEIF riid = $IID_IVBFormat THEN
      FUNCTION = "IID_IVBFormat"
   ELSEIF riid = $IID_IGetVBAObject THEN
      FUNCTION = "IID_IGetVBAObject"
   ELSE
      FUNCTION = GUIDTXT$(riid)
   END IF

END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container structures.
' ########################################################################################

' ========================================================================================
' Creation parameters structure
' ========================================================================================
TYPE OC_CREATEPARAMS
   clsid            AS GUID                    ' // Required: Class identifier
   riid             AS GUID                    ' // Optional: Interface identifier
   szLicKey         AS ASCIIZ * 256            ' // Required for licensed controls: License key
   szLibName        AS ASCIIZ * %MAX_PATH      ' // Required: Library name and path
END TYPE
' ========================================================================================

' ========================================================================================
' Controlling Download and Execution
' The WebBrowser Control gives you control over what it downloads, displays, and executes.
' To gain this control, you need to implement your host's IDispatch so it handles
' DISPID_AMBIENT_DLCONTROL. When the WebBrowser Control is instantiated, it will call your
' IDispatch::Invoke with this ID. Set pvarResult to a combination of following flags, using
' the bitwise OR operator, to indicate your preferences.
' - DLCTL_DLIMAGES, DLCTL_VIDEOS, and DLCTL_BGSOUNDS: Images, videos, and background sounds
'   will be downloaded from the server and displayed or played if these flags are set. They
'   will not be downloaded and displayed if the flags are not set.
' - DLCTL_NO_SCRIPTS and DLCTL_NO_JAVA: Scripts and Java applets will not be executed.
' - DLCTL_NO_DLACTIVEXCTLS and DLCTL_NO_RUNACTIVEXCTLS : ActiveX controls will not be
'   downloaded or will not be executed.
' - DLCTL_DOWNLOADONLY: The page will only be downloaded, not displayed.
' - DLCTL_NO_FRAMEDOWNLOAD: The WebBrowser Control will download and parse a frameSet, but
'   not the individual frame objects within the frameSet.
' - DLCTL_RESYNCHRONIZE and DLCTL_PRAGMA_NO_CACHE: These flags cause cache refreshes. With
'   DLCTL_RESYNCHRONIZE, the server will be asked for update status. Cached files will be
'   used if the server indicates that the cached information is up-to-date. With
'   DLCTL_PRAGMA_NO_CACHE, files will be re-downloaded from the server regardless of the
'   update status of the files.
' - DLCTL_NO_BEHAVIORS: Behaviors are not downloaded and are disabled in the document.
' - DLCTL_NO_METACHARSET_HTML: Character sets specified in meta elements are suppressed.
' - DLCTL_URL_ENCODING_DISABLE_UTF8 and DLCTL_URL_ENCODING_ENABLE_UTF8: These flags function
'   similarly to the DOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8 and DOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8
'   flags used with IDocHostUIHandler::GetHostInfo. The difference is that the DOCHOSTUIFLAG
'   flags are checked only when the WebBrowser Control is first instantiated. The download
'   flags here for the ambient property change are checked whenever the WebBrowser Control
'   needs to perform a download.
' - DLCTL_NO_CLIENTPULL: No client pull operations will be performed.
' - DLCTL_SILENT: No user interface will be displayed during downloads.
' - DLCTL_FORCEOFFLINE: The WebBrowser Control always operates in offline mode.
' - DLCTL_OFFLINEIFNOTCONNECTED and DLCTL_OFFLINE: These flags are the same. The WebBrowser
'   Control will operate in offline mode if not connected to the Internet.
' DISPID_AMBIENT_DLCONTROL and the flag values are defined in mshtmdid.inc.
' Initially, when the function call to IDispatch.Invoke starts, the VARIANT to which the
' parameter pvarResult points is of type VT_EMPTY. You must switch the type to VT_I4 for
' any settings to have an effect. You can place your flag values in the lVal member of the VARIANT.
' Most of the flag values have negative effects, that is, they prevent behavior that normally
' happens. For instance, scripts are normally executed by the WebBrowser Control if you
' don't customize its behavior. But if you set the DLCTL_NOSCRIPTS flag, no scripts will
' execute in that instance of the control. However, three flags—DLCTL_DLIMAGES, DLCTL_VIDEOS,
' and DLCTL_BGSOUNDS—work exactly opposite. If you set flags at all, you must set these three
' for the WebBrowser Control to behave in its default manner vis-a-vis images, videos and sounds.
' ========================================================================================

' ========================================================================================
' OC_DATA structure
' ========================================================================================
TYPE OC_DATA
   m_hWnd                     AS DWORD         ' // Window handle
   m_hInst                    AS DWORD         ' // Instance handle
   m_hParent                  AS DWORD         ' // Window parent's handle
   m_pthis                    AS DWORD         ' // Address of a pointer to the control's Vtable
   m_pIFontDisp               AS DWORD         ' // IFontDisp interface
   m_dwMiscStatus             AS DWORD         ' // Status bitwise flags
   m_pUnkSink                 AS DWORD         ' // IUnknown of the event class
   m_pEvtObj                  AS DWORD         ' // Pointer to the event class
   m_bLocked                  AS INTEGER       ' // Container locked
   m_bInPlaceActive           AS INTEGER       ' // The control is in-place active
   m_bUIActive                AS INTEGER       ' // The control is UI Active
   m_bHaveFocus               AS INTEGER       ' // The control has focus
   m_AmbientDlControl         AS LONG          ' // Ambient flags to control the WebBrowser behavior
   ' *** Implemented interfaces ***
   m_pIUnknown                AS DWORD         ' // IUnknown interface (implemented)
   m_pIDispatch               AS DWORD         ' // IDispatch interface (implemented)
   m_pIOleClientSite          AS DWORD         ' // IOleClientSite interface (implemented)
   m_pIOleContainer           AS DWORD         ' // IOleContainer interface (implemented)
   m_pIOleControlSite         AS DWORD         ' // IOleControlSite interface (implemented)
   m_pIOleInPlaceFrame        AS DWORD         ' // IOleInPlaceFrame interface (implemented)
   m_pIOleInPlaceSite         AS DWORD         ' // IOleInPlaceSite interface (implemented)
   m_pIOleInplaceSiteEx       AS DWORD         ' // IOleInPlaceSiteEx interface (implemented)
   m_pIOleInPlaceUIWindow     AS DWORD         ' // IOleInplaceUIWindow interface (implemented)
   m_pIOleWindow              AS DWORD         ' // IOleWindow interface (implemented)
   m_pIParseDisplayName       AS DWORD         ' // IParseDisplayName interface (implemented)
   m_pIServiceProvider        AS DWORD         ' // IServiceProvider interface (implemented)
   m_pISimpleFrameSite        AS DWORD         ' // ISimpleFrameSite interface (implemented)
   ' *** Control interfaces ***
   m_pIOleObject              AS DWORD         ' // IOleObject interface
   m_pIOleInPlaceObject       AS DWORD         ' // IOleInPlaceObject interface
   m_pIOleInPlaceActiveObject AS DWORD         ' // IOleInPlaceActiveObject interface
END TYPE
' ========================================================================================

' ########################################################################################
' Ole Container virtual tables.
' ########################################################################################

' ========================================================================================
' IUnknown interface
' ========================================================================================
TYPE OC_IUNKNOWN
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IDispatch interface
' ========================================================================================
TYPE OC_IDISPATCH
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IDispatch methods ===============================================================
   pGetTypeInfoCount       AS DWORD          ' // GetTypeInfoCount method
   pGetTypeInfo            AS DWORD          ' // GetTypeInfo method
   pGetIDsOfNames          AS DWORD          ' // GetIDsOfNames method
   pInvoke                 AS DWORD          ' // Invoke method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleWindow interface
' ========================================================================================
TYPE OC_IOLEWINDOW
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleWindow methods ==============================================================
   pGetWindow              AS DWORD          ' // GetWindow method
   pContextSensitiveHelp   AS DWORD          ' // ContextSensitiveHelp method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleInPlaceUIWindow interface
' ========================================================================================
TYPE OC_IOLEINPLACEUIWINDOW
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleWindow methods ==============================================================
   pGetWindow              AS DWORD          ' // GetWindow method
   pContextSensitiveHelp   AS DWORD          ' // ContextSensitiveHelp method
   ' === IOleInPlaceUIWindow =============================================================
   pGetBorder              AS DWORD          ' // GetBorder method
   pRequestBorderSpace     AS DWORD          ' // RequestBorderSpace method
   pSetBorderSpace         AS DWORD          ' // SerBorderSpace method
   pSetActiveObject        AS DWORD          ' // SetActiveObject method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleInPlaceFrame interface
' ========================================================================================
TYPE OC_IOLEINPLACEFRAME
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleWindow methods ==============================================================
   pGetWindow              AS DWORD          ' // GetWindow method
   pContextSensitiveHelp   AS DWORD          ' // ContextSensitiveHelp method
   ' === IOleInPlaceUIWindow =============================================================
   pGetBorder              AS DWORD          ' // GetBorder method
   pRequestBorderSpace     AS DWORD          ' // RequestBorderSpace method
   pSetBorderSpace         AS DWORD          ' // SerBorderSpace method
   pSetActiveObject        AS DWORD          ' // SetActiveObject method
   ' === IOleInPlaceFrame methods ========================================================
   pInsertMenus            AS DWORD          ' // InsertMenus method
   pSetMenu                AS DWORD          ' // SetMenu method
   pRemoveMenus            AS DWORD          ' // RemoveMenus method
   pSetStatusText          AS DWORD          ' // SetStatusText method
   pEnableModeless         AS DWORD          ' // EnableModeless method
   pTranslateAccelerator   AS DWORD          ' // TranslateAccelerator method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleClientSite interface
' ========================================================================================
TYPE OC_IOLECLIENTSITE
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleClientSite methods ==========================================================
   pSaveObject             AS DWORD          ' // SaveObject method
   pGetMoniker             AS DWORD          ' // GetMoniker method
   pGetContainer           AS DWORD          ' // GetContainer method
   pShowObject             AS DWORD          ' // ShowObject method
   pOnShowWindow           AS DWORD          ' // OnShowWindow method
   pRequestNewObjectLayout AS DWORD          ' // RequestNewObjectLayour method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleInPlaceSite interface
' ========================================================================================
TYPE OC_IOLEINPLACESITE
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleWindow methods ==============================================================
   pGetWindow              AS DWORD          ' // GetWindow method
   pContextSensitiveHelp   AS DWORD          ' // ContextSensitiveHelp method
   ' === IOleInPlaceSite methods =========================================================
   pCanInPlaceActivate     AS DWORD          ' // CanInPlaceActivate method
   pOnInPlaceActivate      AS DWORD          ' // OnInPlaceActivate method
   pOnUIActivate           AS DWORD          ' // OnUIActivate method
   pGetWindowContext       AS DWORD          ' // GetWindowContext method
   pScroll                 AS DWORD          ' // Scroll method
   pOnUIDeactivate         AS DWORD          ' // OnUIDeactivate method
   pOnInPlaceDeactivate    AS DWORD          ' // OnInPlaceDeactivate method
   pDiscardUndoState       AS DWORD          ' // DiscardUndoState method
   pDeactivateAndUndo      AS DWORD          ' // DeactivateAndUndo method
   pOnPosRectChange        AS DWORD          ' // OnPosRectChange method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleInPlaceSiteEx interface
' ========================================================================================
TYPE OC_IOLEINPLACESITEEX
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleWindow methods ==============================================================
   pGetWindow              AS DWORD          ' // GetWindow method
   pContextSensitiveHelp   AS DWORD          ' // ContextSensitiveHelp method
   ' === IOleInPlaceSite methods =========================================================
   pCanInPlaceActivate     AS DWORD          ' // CanInPlaceActivate method
   pOnInPlaceActivate      AS DWORD          ' // OnInPlaceActivate method
   pOnUIActivate           AS DWORD          ' // OnUIActivate method
   pGetWindowContext       AS DWORD          ' // GetWindowContext method
   pScroll                 AS DWORD          ' // Scroll method
   pOnUIDeactivate         AS DWORD          ' // OnUIDeactivate method
   pOnInPlaceDeactivate    AS DWORD          ' // OnInPlaceDeactivate method
   pDiscardUndoState       AS DWORD          ' // DiscardUndoState method
   pDeactivateAndUndo      AS DWORD          ' // DeactivateAndUndo method
   pOnPosRectChange        AS DWORD          ' // OnPosRectChange method
   ' === IOleInPlaceSiteEx ===============================================================
   pOnInPlaceActivateEx    AS DWORD          ' // OnInPlaceActivateEx method
   pOnInPlaceDeactivateEx  AS DWORD          ' // OnInPlaceDeactivateEx method
   pRequestUIActivate      AS DWORD          ' // RequestUIActivate method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IParseDisplayName interface
' ========================================================================================
TYPE OC_IPARSEDISPLAYNAME
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IParseDisplayName methods =======================================================
   pParseDisplayName       AS DWORD          ' // ParseDisplayName method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleContainer interface
' ========================================================================================
TYPE OC_IOLECONTAINER
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IParseDisplayName methods =======================================================
   pParseDisplayName       AS DWORD          ' // ParseDisplayName method
   ' === IOleContainer methods ===========================================================
   pEnumObjects            AS DWORD          ' // EnumObjects method
   pLockContainer          AS DWORD          ' // LockContainer method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IServiceProvider interface
' ========================================================================================
TYPE OC_ISERVICEPROVIDER
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IServiceProvider method =========================================================
   pQueryService           AS DWORD          ' // QueryService method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' IOleControlSite interface
' ========================================================================================
TYPE OC_IOLECONTROLSITE
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === IOleControlSite methods =========================================================
   pOnControlInfoChanged   AS DWORD          ' // OnControlInfoChanged method
   pLockInPlaceActive      AS DWORD          ' // LockInplaceActive method
   pGetExtendedControl     AS DWORD          ' // GetExtendedControl method
   pTransformCoords        AS DWORD          ' // TransformCoords method
   pTranslateAccelerator   AS DWORD          ' // TranslateAccelerator method
   pOnFocus                AS DWORD          ' // OnFocus method
   pShowPropertyFrame      AS DWORD          ' // ShowPropertyFrame method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' ISimpleFrameSite interface
' ========================================================================================
TYPE OC_ISIMPLEFRAMESITE
   ' === IUnknown methods ================================================================
   pQueryInterface         AS DWORD          ' // QueryInterface method
   pAddRef                 AS DWORD          ' // AddRef method
   pRelease                AS DWORD          ' // Release method
   ' === ISimpleFrameSite methods ========================================================
   pPreMessageFilter       AS DWORD          ' // PreMessageFilter method
   pPostMessageFilter      AS DWORD          ' // PostMessageFilter method
   ' === Custom data =====================================================================
   pVtblAddr               AS DWORD          ' // Address of the virtual table
   cRef                    AS DWORD          ' // Reference count
   pData                   AS OC_DATA PTR    ' // Pointer to the OC_DATA structure
   ' =====================================================================================
END TYPE
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IUnknown Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IUnknownVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IUNKNOWN PTR
   LOCAL pUnk AS OC_IUNKNOWN PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IUnknownImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IUnknownImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IUnknownImpl_Release)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIUnknown = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IDispatch Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IDispatchVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IDISPATCH PTR
   LOCAL pUnk AS OC_IDISPATCH PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IDispatchImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IDispatchImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IDispatchImpl_Release)
   @pVtbl.pGetTypeInfoCount       = CODEPTR(OC_IDispatchImpl_GetTypeInfoCount)
   @pVtbl.pGetTypeInfo            = CODEPTR(OC_IDispatchImpl_GetTypeInfo)
   @pVtbl.pGetIDsOfNames          = CODEPTR(OC_IDispatchImpl_GetIDsOfNames)
   @pVtbl.pInvoke                 = CODEPTR(OC_IDispatchImpl_Invoke)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIDispatch = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleWindow Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleWindowVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLEWINDOW PTR
   LOCAL pUnk AS OC_IOLEWINDOW PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleWindowImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleWindowImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleWindowImpl_Release)
   @pVtbl.pGetWindow              = CODEPTR(OC_IOleWindowImpl_GetWindow)
   @pVtbl.pContextSensitiveHelp   = CODEPTR(OC_IOleWindowImpl_ContextSensitiveHelp)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleWindow = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleInPlaceUIWindow Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleInPlaceUIWindowVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLEINPLACEUIWINDOW PTR
   LOCAL pUnk AS OC_IOLEINPLACEUIWINDOW PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleInPlaceUIWindowImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleInPlaceUIWindowImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleInPlaceUIWindowImpl_Release)
   @pVtbl.pGetWindow              = CODEPTR(OC_IOleInPlaceUIWindowImpl_GetWindow)
   @pVtbl.pContextSensitiveHelp   = CODEPTR(OC_IOleInPlaceUIWindowImpl_ContextSensitiveHelp)
   @pVtbl.pGetBorder              = CODEPTR(OC_IOleInPlaceUIWindowImpl_GetBorder)
   @pVtbl.pRequestBorderSpace     = CODEPTR(OC_IOleInPlaceUIWindowImpl_RequestBorderSpace)
   @pVtbl.pSetBorderSpace         = CODEPTR(OC_IOleInPlaceUIWindowImpl_SetBorderSpace)
   @pVtbl.pSetActiveObject        = CODEPTR(OC_IOleInPlaceUIWindowImpl_SetActiveObject)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleInPlaceUIWindow = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleInPlaceFrame Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleInPlaceFrameVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLEINPLACEFRAME PTR
   LOCAL pUnk AS OC_IOLEINPLACEFRAME PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleInPlaceFrameImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleInPlaceFrameImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleInPlaceFrameImpl_Release)
   @pVtbl.pGetWindow              = CODEPTR(OC_IOleInPlaceFrameImpl_GetWindow)
   @pVtbl.pContextSensitiveHelp   = CODEPTR(OC_IOleInPlaceFrameImpl_ContextSensitiveHelp)
   @pVtbl.pGetBorder              = CODEPTR(OC_IOleInPlaceFrameImpl_GetBorder)
   @pVtbl.pRequestBorderSpace     = CODEPTR(OC_IOleInPlaceFrameImpl_RequestBorderSpace)
   @pVtbl.pSetBorderSpace         = CODEPTR(OC_IOleInPlaceFrameImpl_SetBorderSpace)
   @pVtbl.pSetActiveObject        = CODEPTR(OC_IOleInPlaceFrameImpl_SetActiveObject)
   @pVtbl.pInsertMenus            = CODEPTR(OC_IOleInPlaceFrameImpl_InsertMenus)
   @pVtbl.pSetMenu                = CODEPTR(OC_IOleInPlaceFrameImpl_SetMenu)
   @pVtbl.pRemoveMenus            = CODEPTR(OC_IOleInPlaceFrameImpl_RemoveMenus)
   @pVtbl.pSetStatusText          = CODEPTR(OC_IOleInPlaceFrameImpl_SetStatusText)
   @pVtbl.pEnableModeless         = CODEPTR(OC_IOleInPlaceFrameImpl_EnableModeless)
   @pVtbl.pTranslateAccelerator   = CODEPTR(OC_IOleInPlaceFrameImpl_TranslateAccelerator)
   @pVtbl.pVtblAddr               = pVtbl

   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleInPlaceFrame = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleClientSite Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleClientSiteVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLECLIENTSITE PTR
   LOCAL pUnk AS OC_IOLECLIENTSITE PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleClientSiteImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleClientSiteImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleClientSiteImpl_Release)

   @pVtbl.pSaveObject             = CODEPTR(OC_IOleClientSiteImpl_SaveObject)
   @pVtbl.pGetMoniker             = CODEPTR(OC_IOleClientSiteImpl_GetMoniker)
   @pVtbl.pGetContainer           = CODEPTR(OC_IOleClientSiteImpl_GetContainer)
   @pVtbl.pShowObject             = CODEPTR(OC_IOleClientSiteImpl_ShowObject)
   @pVtbl.pOnShowWindow           = CODEPTR(OC_IOleClientSiteImpl_OnShowWindow)
   @pVtbl.pRequestNewObjectLayout = CODEPTR(OC_IOleClientSiteImpl_RequestNewObjectLayout)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleClientSite = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IParseDisplayName Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IParseDisplayNameVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IPARSEDISPLAYNAME PTR
   LOCAL pUnk AS OC_IPARSEDISPLAYNAME PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IParseDisplayNameImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IParseDisplayNameImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IParseDisplayNameImpl_Release)

   @pVtbl.pParseDisplayName       = CODEPTR(OC_IParseDisplayNameImpl_ParseDisplayName)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIParseDisplayName = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleContainer Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleContainerVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLECONTAINER PTR
   LOCAL pUnk AS OC_IOLECONTAINER PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleContainerImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleContainerImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleContainerImpl_Release)

   @pVtbl.pParseDisplayName       = CODEPTR(OC_IOleContainerImpl_ParseDisplayName)
   @pVtbl.pEnumObjects            = CODEPTR(OC_IOleContainerImpl_EnumObjects)
   @pVtbl.pLockContainer          = CODEPTR(OC_IOleContainerImpl_LockContainer)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleContainer = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleInPlaceSite Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleInPlaceSiteVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLEINPLACESITE PTR
   LOCAL pUnk AS OC_IOLEINPLACESITE PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleInPlaceSiteImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleInPlaceSiteImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleInPlaceSiteImpl_Release)
   @pVtbl.pGetWindow              = CODEPTR(OC_IOleInPlaceSiteImpl_GetWindow)
   @pVtbl.pContextSensitiveHelp   = CODEPTR(OC_IOleInPlaceSiteImpl_ContextSensitiveHelp)
   @pVtbl.pCanInPlaceActivate     = CODEPTR(OC_IOleInPlaceSiteImpl_CanInPlaceActivate)
   @pVtbl.pOnInPlaceActivate      = CODEPTR(OC_IOleInPlaceSiteImpl_OnInPlaceActivate)
   @pVtbl.pOnUIActivate           = CODEPTR(OC_IOleInPlaceSiteImpl_OnUIActivate)
   @pVtbl.pGetWindowContext       = CODEPTR(OC_IOleInPlaceSiteImpl_GetWindowContext)
   @pVtbl.pScroll                 = CODEPTR(OC_IOleInPlaceSiteImpl_Scroll)
   @pVtbl.pOnUIDeactivate         = CODEPTR(OC_IOleInPlaceSiteImpl_OnUIDeactivate)
   @pVtbl.pOnInPlaceDeactivate    = CODEPTR(OC_IOleInPlaceSiteImpl_OnInPlaceDeactivate)
   @pVtbl.pDiscardUndoState       = CODEPTR(OC_IOleInPlaceSiteImpl_DiscardUndoState)
   @pVtbl.pDeactivateAndUndo      = CODEPTR(OC_IOleInPlaceSiteImpl_DeactivateAndUndo)
   @pVtbl.pOnPosRectChange        = CODEPTR(OC_IOleInPlaceSiteImpl_OnPosRectChange)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleInPlaceSite = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleInPlaceSiteEx Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleInPlaceSiteVtableEx (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLEINPLACESITEEX PTR
   LOCAL pUnk AS OC_IOLEINPLACESITEEX PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleInPlaceSiteExImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleInPlaceSiteExImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleInPlaceSiteExImpl_Release)
   @pVtbl.pGetWindow              = CODEPTR(OC_IOleInPlaceSiteExImpl_GetWindow)
   @pVtbl.pContextSensitiveHelp   = CODEPTR(OC_IOleInPlaceSiteExImpl_ContextSensitiveHelp)
   @pVtbl.pCanInPlaceActivate     = CODEPTR(OC_IOleInPlaceSiteExImpl_CanInPlaceActivate)
   @pVtbl.pOnInPlaceActivate      = CODEPTR(OC_IOleInPlaceSiteExImpl_OnInPlaceActivate)
   @pVtbl.pOnUIActivate           = CODEPTR(OC_IOleInPlaceSiteExImpl_OnUIActivate)
   @pVtbl.pGetWindowContext       = CODEPTR(OC_IOleInPlaceSiteExImpl_GetWindowContext)
   @pVtbl.pScroll                 = CODEPTR(OC_IOleInPlaceSiteExImpl_Scroll)
   @pVtbl.pOnUIDeactivate         = CODEPTR(OC_IOleInPlaceSiteExImpl_OnUIDeactivate)
   @pVtbl.pOnInPlaceDeactivate    = CODEPTR(OC_IOleInPlaceSiteExImpl_OnInPlaceDeactivate)
   @pVtbl.pDiscardUndoState       = CODEPTR(OC_IOleInPlaceSiteExImpl_DiscardUndoState)
   @pVtbl.pDeactivateAndUndo      = CODEPTR(OC_IOleInPlaceSiteExImpl_DeactivateAndUndo)
   @pVtbl.pOnPosRectChange        = CODEPTR(OC_IOleInPlaceSiteExImpl_OnPosRectChange)
   @pVtbl.pOnInPlaceActivateEx    = CODEPTR(OC_IOleInPlaceSiteExImpl_OnInPlaceActivateEx)
   @pVtbl.pOnInPlaceDeactivateEx  = CODEPTR(OC_IOleInPlaceSiteExImpl_OnInPlaceDeactivateEx)
   @pVtbl.pRequestUIActivate      = CODEPTR(OC_IOleInPlaceSiteExImpl_RequestUIActivate)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleInPlaceSiteEx = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IOleControlSite Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IOleControlSiteVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_IOLECONTROLSITE PTR
   LOCAL pUnk AS OC_IOLECONTROLSITE PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IOleControlSiteImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IOleControlSiteImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IOleControlSiteImpl_Release)

   @pVtbl.pOnControlInfoChanged   = CODEPTR(OC_IOleControlSiteImpl_OnControlInfoChanged)
   @pVtbl.pLockInPlaceActive      = CODEPTR(OC_IOleControlSiteImpl_LockInPlaceActive)
   @pVtbl.pGetExtendedControl     = CODEPTR(OC_IOleControlSiteImpl_GetExtendedControl)
   @pVtbl.pTransformCoords        = CODEPTR(OC_IOleControlSiteImpl_TransformCoords)
   @pVtbl.pTranslateAccelerator   = CODEPTR(OC_IOleControlSiteImpl_TranslateAccelerator)
   @pVtbl.pOnFocus                = CODEPTR(OC_IOleControlSiteImpl_OnFocus)
   @pVtbl.pShowPropertyFrame      = CODEPTR(OC_IOleControlSiteImpl_ShowPropertyFrame)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIOleControlSite = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the IServiceProvider Virtual Table
' ========================================================================================
FUNCTION NEW_OC_IServiceProviderVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_ISERVICEPROVIDER PTR
   LOCAL pUnk AS OC_ISERVICEPROVIDER PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_IServiceProviderImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_IServiceProviderImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_IServiceProviderImpl_Release)

   @pVtbl.pQueryService           = CODEPTR(OC_IServiceProviderImpl_QueryService)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pIServiceProvider = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Builds the ISimpleFrameSite Virtual Table
' ========================================================================================
FUNCTION NEW_OC_ISimpleFrameSiteVtable (BYVAL pData AS OC_DATA PTR) AS DWORD

   LOCAL pVtbl AS OC_ISIMPLEFRAMESITE PTR
   LOCAL pUnk AS OC_ISIMPLEFRAMESITE PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.pQueryInterface         = CODEPTR(OC_ISimpleFrameSiteImpl_QueryInterface)
   @pVtbl.pAddRef                 = CODEPTR(OC_ISimpleFrameSiteImpl_AddRef)
   @pVtbl.pRelease                = CODEPTR(OC_ISimpleFrameSiteImpl_Release)

   @pVtbl.pPreMessageFilter       = CODEPTR(OC_ISimpleFrameSiteImpl_PreMessageFilter)
   @pVtbl.pPostMessageFilter      = CODEPTR(OC_ISimpleFrameSiteImpl_PostMessageFilter)

   @pVtbl.pVtblAddr               = pVtbl
   @pVtbl.cRef                    = 0
   @pVtbl.pData                   = pData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   @pData.m_pISimpleFrameSite = pUnk
   FUNCTION = pUnk

   OC_DP(FUNCNAME$ & " - pUnk = " & STR$(pUnk))

END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the IUnknown interface.
' The IUnknown interface lets clients get pointers to other interfaces on a given object
' through the QueryInterface method, and manage the existence of the object through the
' IUnknown::AddRef and IUnknown::Release methods. All other COM interfaces are inherited,
' directly or indirectly, from IUnknown. Therefore, the three methods in IUnknown are the
' first entries in the VTable for every interface.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' QueryInterface helper function for all the interfaces.
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IUnknown_QueryInterface (BYVAL pData AS OC_DATA PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG

   ppvObj = %NULL
   FUNCTION = %E_NOINTERFACE

   LOCAL pIUnknown               AS OC_IUNKNOWN PTR
   LOCAL pIDispatch              AS OC_IDISPATCH PTR
   LOCAL pIOleClientSite         AS OC_IOLECLIENTSITE PTR
   LOCAL pIOleContainer          AS OC_IOLECONTAINER PTR
   LOCAL pIOleControlSite        AS OC_IOLECONTROLSITE PTR
   LOCAL pIOleInPlaceFrame       AS OC_IOLEINPLACEFRAME PTR
   LOCAL pIOleInPlaceSite        AS OC_IOLEINPLACESITE PTR
   LOCAL pIOleInplaceSiteEx      AS OC_IOLEINPLACESITEEX PTR
   LOCAL pIOleInPlaceUIWindow    AS OC_IOLEINPLACEUIWINDOW PTR
   LOCAL pIOleWindow             AS OC_IOLEWINDOW PTR
   LOCAL pIParseDisplayName      AS OC_IPARSEDISPLAYNAME PTR
   LOCAL pIServiceProvider       AS OC_ISERVICEPROVIDER PTR
   LOCAL pISimpleFrameSite       AS OC_ISIMPLEFRAMESITE PTR

   IF riid = $IID_IUnknown THEN
      IF @pData.m_pIUnknown THEN
         pIUnknown = @pData.m_pIUnknown
         INCR @@pIUnknown.cRef
         ppvObj = pIUnknown
      ELSE
         ppvObj = NEW_OC_IUnknownVtable(pData)
         pIUnknown = ppvObj
         @@pIUnknown.cRef = 1
         @pData.m_pIUnknown = pIUnknown
      END IF
   ELSEIF riid = $IID_IDispatch OR riid = $IID_IVBControlClass THEN
      IF @pData.m_pIDispatch THEN
         pIDispatch = @pData.m_pIDispatch
         INCR @@pIDispatch.cRef
         ppvObj = pIDispatch
      ELSE
         ppvObj = NEW_OC_IDispatchVtable(pData)
         pIDispatch = ppvObj
         @@pIDispatch.cRef = 1
         @pData.m_pIDispatch = pIDispatch
      END IF
   ELSEIF riid = $IID_IOleClientSite THEN
      IF @pData.m_pIOleClientSite THEN
         pIOleClientSite = @pData.m_pIOleClientSite
         INCR @@pIOleClientSite.cRef
         ppvObj = pIOleClientSite
      ELSE
         ppvObj = NEW_OC_IOleClientSiteVtable(pData)
         pIOleClientSite = ppvObj
         @@pIOleClientSite.cRef = 1
         @pData.m_pIOleClientSite = pIOleClientSite
      END IF
   ELSEIF riid = $IID_IOleContainer THEN
      IF @pData.m_pIOleContainer THEN
         pIOleContainer = @pData.m_pIOleContainer
         INCR @@pIOleContainer.cRef
         ppvObj = pIOleContainer
      ELSE
         ppvObj = NEW_OC_IOleContainerVtable(pData)
         pIOleContainer = ppvObj
         @@pIOleContainer.cRef = 1
         @pData.m_pIOleContainer = pIOleContainer
      END IF
   ELSEIF riid = $IID_IOleControlSite THEN
      IF @pData.m_pIOleControlSite THEN
         pIOleControlSite = @pData.m_pIOleControlSite
         INCR @@pIOleControlSite.cRef
         ppvObj = pIOleControlSite
      ELSE
         ppvObj = NEW_OC_IOleControlSiteVtable(pData)
         pIOleControlSite = ppvObj
         @@pIOleControlSite.cRef = 1
         @pData.m_pIOleControlSite = pIOleControlSite
      END IF
   ELSEIF riid = $IID_IOleInPlaceFrame THEN
      IF @pData.m_pIOleInPlaceFrame THEN
         pIOleInPlaceFrame = @pData.m_pIOleInPlaceFrame
         INCR @@pIOleInPlaceFrame.cRef
         ppvObj = pIOleInPlaceFrame
      ELSE
         ppvObj = NEW_OC_IOleInPlaceFrameVtable(pData)
         pIOleInPlaceFrame = ppvObj
         @@pIOleInPlaceFrame.cRef = 1
         @pData.m_pIOleInPlaceFrame = pIOleInPlaceFrame
      END IF
   ELSEIF riid = $IID_IOleInPlaceSite THEN
      IF @pData.m_pIOleInPlaceSite THEN
         pIOleInPlaceSite = @pData.m_pIOleInPlaceSite
         INCR @@pIOleInPlaceSite.cRef
         ppvObj = pIOleInPlaceSite
      ELSE
         ppvObj = NEW_OC_IOleInPlaceSiteVtable(pData)
         pIOleInPlaceSite = ppvObj
         @@pIOleInPlaceSite.cRef = 1
         @pData.m_pIOleInPlaceSite = pIOleInPlaceSite
      END IF
   ELSEIF riid = $IID_IOleInPlaceSiteEx THEN
      IF @pData.m_pIOleInPlaceSiteEx THEN
         pIOleInPlaceSiteEx = @pData.m_pIOleInPlaceSiteEx
         INCR @@pIOleInPlaceSiteEx.cRef
         ppvObj = pIOleInPlaceSiteEx
      ELSE
         ppvObj = NEW_OC_IOleInPlaceSiteVtableEx(pData)
         pIOleInPlaceSiteEx = ppvObj
         @@pIOleInPlaceSiteEx.cRef = 1
         @pData.m_pIOleInPlaceSiteEx = pIOleInPlaceSiteEx
      END IF
   ELSEIF riid = $IID_IOleInPlaceUIWindow THEN
      IF @pData.m_pIOleInPlaceUIWindow THEN
         pIOleInPlaceUIWindow = @pData.m_pIOleInPlaceUIWindow
         INCR @@pIOleInPlaceUIWindow.cRef
         ppvObj = pIOleInPlaceUIWindow
      ELSE
         ppvObj = NEW_OC_IOleInPlaceUIWindowVtable(pData)
         pIOleInPlaceUIWindow = ppvObj
         @@pIOleInPlaceUIWindow.cRef = 1
         @pData.m_pIOleInPlaceUIWindow = pIOleInPlaceUIWindow
      END IF
   ELSEIF riid = $IID_IOleWindow THEN
      IF @pData.m_pIOleWindow THEN
         pIOleWindow = @pData.m_pIOleWindow
         INCR @@pIOleWindow.cRef
         ppvObj = pIOleWindow
      ELSE
         ppvObj = NEW_OC_IOleWindowVtable(pData)
         pIOleWindow = ppvObj
         @@pIOleWindow.cRef = 1
         @pData.m_pIOleWindow = pIOleWindow
      END IF
   ELSEIF riid = $IID_IParseDisplayName THEN
      IF @pData.m_pIParseDisplayName THEN
         pIParseDisplayName = @pData.m_pIParseDisplayName
         INCR @@pIParseDisplayName.cRef
         ppvObj = pIParseDisplayName
      ELSE
         ppvObj = NEW_OC_IParseDisplayNameVtable(pData)
         pIParseDisplayName = ppvObj
         @@pIParseDisplayName.cRef = 1
         @pData.m_pIParseDisplayName = pIParseDisplayName
      END IF
   ELSEIF riid = $IID_IServiceProvider THEN
      IF @pData.m_pIServiceProvider THEN
         pIServiceProvider = @pData.m_pIServiceProvider
         INCR @@pIServiceProvider.cRef
         ppvObj = pIServiceProvider
      ELSE
         ppvObj = NEW_OC_IServiceProviderVtable(pData)
         pIServiceProvider = ppvObj
         @@pIServiceProvider.cRef = 1
         @pData.m_pIServiceProvider = pIServiceProvider
      END IF
   ELSEIF riid = $IID_ISimpleFrameSite THEN
      IF @pData.m_pISimpleFrameSite THEN
         pISimpleFrameSite = @pData.m_pISimpleFrameSite
         INCR @@pISimpleFrameSite.cRef
         ppvObj = pISimpleFrameSite
      ELSE
         ppvObj = NEW_OC_ISimpleFrameSiteVtable(pData)
         pISimpleFrameSite = ppvObj
         @@pISimpleFrameSite.cRef = 1
         @pData.m_pISimpleFrameSite = pISimpleFrameSite
      END IF
   END IF

   IF ppvObj THEN FUNCTION = %S_OK

   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid) & " - " & GUIDTXT$(riid))

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IUnknownImpl_QueryInterface (BYVAL pCookie AS OC_IUNKNOWN PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IUnknown THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IUnknownImpl_AddRef (BYVAL pCookie AS OC_IUNKNOWN PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IUnknownImpl_Release (BYVAL pCookie AS OC_IUNKNOWN PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIUnknown = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & "  *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the IDispatch interface.
' IDispatch interface exposes objects, methods and properties to programming tools and
' other applications that support Automation.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IDispatchImpl_QueryInterface (BYVAL pCookie AS OC_IDISPATCH PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & GUIDTXT$(riid) & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IDispatch THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IDispatchImpl_AddRef (BYVAL pCookie AS OC_IDISPATCH PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP("***" & FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IDispatchImpl_Release (BYVAL pCookie AS OC_IDISPATCH PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIDispatch = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Not required. This method is necessary only for containers that support nonstandard
' ambient properties.
' ========================================================================================
FUNCTION OC_IDispatchImpl_GetTypeInfoCount (BYVAL pCookie AS OC_IDISPATCH PTR, BYREF pctInfo AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   pctInfo = 0
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Not required. This method is necessary only for containers that support nonstandard
' ambient properties.
' ========================================================================================
FUNCTION OC_IDispatchImpl_GetTypeInfo (BYVAL pCookie AS OC_IDISPATCH PTR, BYVAL itinfo AS DWORD, BYVAL lcid AS DWORD, BYREF pptinfo AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Not required. This method is necessary only for containers that support nonstandard
' ambient properties.
' ========================================================================================
FUNCTION OC_IDispatchImpl_GetIDsOfNames (BYVAL pCookie AS OC_IDISPATCH PTR, _
   BYREF riid AS GUID, BYVAL rgszNames AS DWORD, BYVAL cNames AS DWORD, BYVAL lcid AS DWORD, BYREF rgdispid AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' ========================================================================================
FUNCTION OC_IDispatchImpl_Invoke (BYVAL pCookie AS OC_IDISPATCH PTR, BYVAL dispidMember AS LONG, BYREF riid AS GUID, _
   BYVAL lcid AS DWORD, BYVAL wFlags AS WORD, BYREF pdispparams AS DISPPARAMS, BYREF pvarResult AS tagVARIANT, _
   BYREF pexcepinfo AS EXCEPINFO, BYREF puArgErr AS DWORD) AS LONG

   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie) & " - DispID: " & STR$(dispidMember))

   ' riid must be a null guid
   IF riid <> $IID_NULL THEN
      FUNCTION = %DISP_E_UNKNOWNINTERFACE
      EXIT FUNCTION
   END IF

   ' Anything but a property get is invalid.
'   IF (wFlags AND %DISPATCH_PROPERTYGET) <> %DISPATCH_PROPERTYGET THEN
   IF (wFlags AND &H2) <> &H2 THEN
      FUNCTION = %DISP_E_MEMBERNOTFOUND
      EXIT FUNCTION
   END IF

   ' pvarResult can't be null for get properties
   IF VARPTR(pvarResult) = %NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   ELSE
      ' Set the variant to empty
      VariantInit pvarResult
   END IF

   ' Default error code
   FUNCTION = %DISP_E_MEMBERNOTFOUND

   SELECT CASE dispidMember
      CASE -701   ' %DISPID_AMBIENT_BACKCOLOR
         pvarResult.vt = %VT_UI4
         pvarResult.lVal = GetSysColor(%COLOR_WINDOW)
         FUNCTION = %NOERROR
      CASE -703   ' %DISPID_AMBIENT_FONT
         IF @@pCookie.@pData.m_pIFontDisp <> %NULL THEN
            ' Incremenet the reference count
            IUnknown_AddRef @@pCookie.@pData.m_pIFontDisp
            ' Return a reference to the ambient font
            pvarResult.vt = %VT_DISPATCH
            pvarResult.pdispVal = @@pCookie.@pData.m_pIFontDisp
            FUNCTION = %NOERROR
         END IF
      CASE -704   ' %DISPID_AMBIENT_FORECOLOR
         pvarResult.vt = %VT_UI4
         pvarResult.lVal = GetSysColor(%COLOR_WINDOWTEXT)
         FUNCTION = %NOERROR
      CASE -705   ' %DISPID_AMBIENT_LOCALEID
         pvarResult.vt = %VT_I4
         pvarResult.lVal = %LOCALE_USER_DEFAULT
         FUNCTION = %NOERROR
      CASE -706   ' %DISPID_AMBIENT_MESSAGEREFLECT
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = 0
         FUNCTION = %NOERROR
      CASE -709   ' %DISPID_AMBIENT_USERMODE
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = -1
         FUNCTION = %NOERROR
      CASE -710   ' %DISPID_AMBIENT_UIDEAD
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = 0
         FUNCTION = %NOERROR
      CASE -711   ' %DISPID_AMBIENT_SHOWGRABHANDLES
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = 0
         FUNCTION = %NOERROR
      CASE -712   ' %DISPID_AMBIENT_SHOWHATCHING
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = 0
         FUNCTION = %NOERROR
      CASE -712   ' %DISPID_AMBIENT_DISPLAYASDEFAULT
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = 0
         FUNCTION = %NOERROR
      CASE -714   ' %DISPID_AMBIENT_SUPPORTSMNEMONICS
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = -1
         FUNCTION = %NOERROR
      CASE -5501   ' %DISPID_AMBIENT_OFFLINEIFNOTCONNECTED
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = -1
         FUNCTION = %NOERROR
      CASE -5502   ' %DISPID_AMBIENT_SILENT
         pvarResult.vt = %VT_BOOL
         pvarResult.boolVal = -1
         FUNCTION = %NOERROR
      CASE -5512   ' %DISPID_AMBIENT_DLCONTROL
         IF @@pCookie.@pData.m_AmbientDlControl THEN
            pvarResult.vt = %VT_I4
            pvarResult.lVal = @@pCookie.@pData.m_AmbientDlControl
            FUNCTION = %NOERROR
         END IF
'      CASE -702   ' %DISPID_AMBIENT_DISPLAYNAME
'      CASE -707   ' %DISPID_AMBIENT_SCALEUNITS
'      CASE -708   ' %DISPID_AMBIENT_TEXTALIGN
'      CASE -715   ' %DISPID_AMBIENT_AUTOCLIP
'      CASE -716   ' %DISPID_AMBIENT_APPEARANCE
'      CASE -725   ' %DISPID_AMBIENT_CODEPAGE
'      CASE -726   ' %DISPID_AMBIENT_PALETTE
'      CASE -727   ' %DISPID_AMBIENT_CHARSET
'      CASE -732   ' %DISPID_AMBIENT_RIGHTTOLEFT
'      CASE -733   ' %DISPID_AMBIENT_TOPTOBOTTOM
   END SELECT

END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the IOleWindow interface.
' The IOleWindow interface provides methods that allow an application to obtain the handle
' to the various windows that participate in in-place activation, and also to enter and
' exit context-sensitive help mode.
' Several other in-place activation interfaces are derived from the IOleWindow interface.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleWindowImpl_QueryInterface (BYVAL pCookie AS OC_IOLEWINDOW PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleWindow THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleWindowImpl_AddRef (BYVAL pCookie AS OC_IOLEWINDOW PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleWindowImpl_Release (BYVAL pCookie AS OC_IOLEWINDOW PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleWindow = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***"))
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleWindowImpl_GetWindow and derived interfaces ***
' ========================================================================================
FUNCTION OC_IOleWindow_GetWindow (BYVAL pData AS OC_DATA PTR, BYREF phwnd AS DWORD) AS LONG
   IF VARPTR(phwnd) = %NULL THEN
      FUNCTION = %E_INVALIDARG
   ELSE
      phwnd = @pData.m_hwnd
      FUNCTION = %S_OK
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the window handle to one of the windows participating in in-place activation
' (frame, document, parent, or in-place object window).
' ========================================================================================
FUNCTION OC_IOleWindowImpl_GetWindow (BYVAL pCookie AS OC_IOLEWINDOW PTR, BYREF phwnd AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - phwnd: " & STR$(VARPTR(phwnd)))
   FUNCTION = OC_IOleWindow_GetWindow(@@pCookie.pData, phwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleWindowImpl_ContextSensitiveHelp and derived interfaces ***
' ========================================================================================
FUNCTION OC_IOleWindow_ContextSensitiveHelp (BYVAL pData AS OC_DATA PTR, BYVAL fEnterMode AS LONG) AS LONG
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines whether context-sensitive help mode should be entered during an in-place
' activation session.
' ========================================================================================
FUNCTION OC_IOleWindowImpl_ContextSensitiveHelp (BYVAL pCookie AS OC_IOLEWINDOW PTR, BYVAL fEnterMode AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleWindow_ContextSensitiveHelp(@@pCookie.pData, fEnterMode)
END FUNCTION
' ========================================================================================


' ########################################################################################
' Ole Container implementation of the IOleInPlaceUIWindow interface.
' The IOleInPlaceUIWindow interface is implemented by container applications and used by
' object applications to negotiate border space on the document or frame window. The
' container provides a RECT structure in which the object can place toolbars and other
' similar controls, determines if tools can in fact be installed around the object's
' window frame, allocates space for the border, and establishes a communication channel
' between the object and each frame and document window.
' The document window may not exist in all applications. When this is the case,
' IOleInPlaceSite::GetWindowContext returns NULL for IOleInPlaceUIWindow.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_QueryInterface (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleInPlaceUIWindow THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_AddRef (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_Release (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleInPlaceUIWindow = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the window handle to one of the windows participating in in-place activation
' (frame, document, parent, or in-place object window).
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_GetWindow (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYREF phwnd AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - phwnd: " & STR$(VARPTR(phwnd)))
   FUNCTION = OC_IOleWindow_GetWindow(@@pCookie.pData, phwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines whether context-sensitive help mode should be entered during an in-place
' activation session.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_ContextSensitiveHelp (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYVAL fEnterMode AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleWindow_ContextSensitiveHelp(@@pCookie.pData, fEnterMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceUIWindowImpl_GetBorder and derived interfaces ***
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindow_GetBorder (BYVAL pData AS OC_DATA PTR, BYREF lprectBorder AS RECT) AS LONG
   IF VARPTR(lprectBorder) = %NULL THEN
      FUNCTION = %E_INVALIDARG
   ELSE
      FUNCTION = %INPLACE_E_NOTOOLSPACE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Specifies a RECT structure for toolbars and controls.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_GetBorder (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYREF lprectBorder AS RECT) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_GetBorder(@@pCookie.pData, lprectBorder)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceUIWindowImpl_RequestBorderSpace and derived interfaces ***
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindow_RequestBorderSpace (BYVAL pData AS OC_DATA PTR, BYREF pborderwidths AS RECT) AS LONG
   IF VARPTR(pborderwidths) = %NULL THEN
      FUNCTION = %E_INVALIDARG
   ELSE
      FUNCTION = %INPLACE_E_NOTOOLSPACE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines if tools can be installed around object's window frame.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_RequestBorderSpace (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYREF pborderwidths AS RECT) AS DWORD
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_RequestBorderSpace(@@pCookie.pData, pborderwidths)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceUIWindowImpl_SetBorderSpace and derived interfaces ***
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindow_SetBorderSpace (BYVAL pData AS OC_DATA PTR, BYREF pborderwidths AS RECT) AS LONG
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' OC_IOleInPlaceUIWindowImpl_SetBorderSpace
' Allocates space for the border.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_SetBorderSpace (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYREF pborderwidths AS RECT) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_SetBorderSpace(@@pCookie.pData, pborderwidths)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceUIWindowImpl_SetActiveObject and derived interfaces ***
' SetActiveObject will be called with both NULL and non-NULL pointers.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindow_SetActiveObject (BYVAL pData AS OC_DATA PTR, BYVAL pActiveObject AS DWORD, BYVAL pszObjName AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & "- pActiveObject: " & STR$(pActiveObject))
   IF @pData.m_pIOleInPlaceActiveObject <> %NULL THEN
      IUnknown_Release @pData.m_pIOleInPlaceActiveObject
      @pData.m_pIOleInPlaceActiveObject = %NULL
   END IF
   IF pActiveObject THEN
      IUnknown_AddRef pActiveObject
      @pData.m_pIOleInPlaceActiveObject = pActiveObject
   END IF
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Provides for direct communication between the object and each document and frame window.
' ========================================================================================
FUNCTION OC_IOleInPlaceUIWindowImpl_SetActiveObject (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYVAL pActiveObject AS DWORD, BYVAL pszObjName AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_SetActiveObject(@@pCookie.pData, pActiveObject, pszObjName)
END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the IOleInPlaceFrame interface.
' The IOleInPlaceFrame interface controls the container's top-level frame window. This
' control involves allowing the container to insert its menu group into the composite
' menu, install the composite menu into the appropriate window frame, and remove the
' container's menu elements from the composite menu. It sets and displays status text
' relevant to the in-place object. It also enables or disables the frame's modeless dialog
' boxes, and translates accelerator keystrokes intended for the container's frame.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_QueryInterface (BYVAL pCookie AS OC_IOLEINPLACEUIWINDOW PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleInPlaceFrame THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_AddRef (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_Release (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleInPlaceFrame = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the window handle to one of the windows participating in in-place activation
' (frame, document, parent, or in-place object window).
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_GetWindow (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYREF phwnd AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - phwnd: " & STR$(VARPTR(phwnd)))
   FUNCTION = OC_IOleWindow_GetWindow(@@pCookie.pData, phwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Optional. Determines whether context-sensitive help mode should be entered during an
' in-place activation session.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_ContextSensitiveHelp (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL fEnterMode AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleWindow_ContextSensitiveHelp(@@pCookie.pData, fEnterMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Specifies a RECT structure for toolbars and controls.
' Not required. This method is necessary only for containers with toolbar UI.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_GetBorder (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYREF lprectBorder AS RECT) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_GetBorder(@@pCookie.pData, lprectBorder)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines if tools can be installed around object's window frame.
' Not required. This method is necessary only for containers with menu UI.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_RequestBorderSpace (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYREF pborderwidths AS RECT) AS DWORD
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_RequestBorderSpace(@@pCookie.pData, pborderwidths)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Allocates space for the border.
' Not required. This method is necessary only for containers with menu UI.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_SetBorderSpace (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYREF pborderwidths AS RECT) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_SetBorderSpace(@@pCookie.pData, pborderwidths)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Provides for direct communication between the object and each document and frame window.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_SetActiveObject (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL pActiveObject AS DWORD, BYVAL pszObjName AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceUIWindow_SetActiveObject(@@pCookie.pData, pActiveObject, pszObjName)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Allows container to insert menus.
' Not required. This method is necessary only for containers with menu UI.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_InsertMenus (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL hMenuShared AS DWORD, BYREF lpMenuWidths AS OLEMENUGROUPWIDTHS) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Adds a composite menu to window frame.
' Not required. This method is necessary only for containers with menu UI.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_SetMenu (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL hMenuShared AS DWORD,  BYVAL holemenu AS DWORD, BYVAL hwndActiveObject AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Removes a container's menu elements.
' Not required. This method is necessary only for containers with menu UI.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_RemoveMenus (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL hMenuShared AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Sets and displays status text about.
' Not required. This method is necessary only for containers that have a status line.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_SetStatusText (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL pszStatusText AS DWORD)  AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Optional. Enables or disables modeless dialog boxes.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_EnableModeless (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYVAL fEnable AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie) & " - fEnable = " & STR$(fEnable))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Optional. Translates keystrokes.
' ========================================================================================
FUNCTION OC_IOleInPlaceFrameImpl_TranslateAccelerator (BYVAL pCookie AS OC_IOLEINPLACEFRAME PTR, BYREF lpmsg AS tagMsg, BYVAL wID AS WORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_FALSE
END FUNCTION
' ========================================================================================


' ########################################################################################
' Ole Container implementation of the IOleClientSite interface.
' The IOleClientSite interface is the primary means by which an embedded object obtains
' information about the location and extent of its display site, its moniker, its user
' interface, and other resources provided by its container. An object server calls
' IOleClientSite to request services from the container. A container must provide one
' instance of IOleClientSite for every compound-document object it contains.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_QueryInterface (BYVAL pCookie AS OC_IOleClientSite PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleClientSite THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_AddRef (BYVAL pCookie AS OC_IOleClientSite PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_Release (BYVAL pCookie AS OC_IOleClientSite PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleClientSite = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & "  *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Saves embedded object.
' Not required. This method is necessary only if persistence is supported.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_SaveObject (BYVAL pCookie AS OC_IOLECLIENTSITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Requests object's moniker.
' Not required. This method is necessary only if the container supports linking to
' controls within its own form or document.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_GetMoniker (BYVAL pCookie AS OC_IOLECLIENTSITE PTR, BYVAL dwAssign AS DWORD, BYVAL dwWhichMoniker AS DWORD, BYREF ppmk AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   OC_DP("dwAssign = " & STR$(dwAssign))
   OC_DP("dwWhichMoniker = " & STR$(dwWhichMoniker))
   IF VARPTR(ppmk) = %NULL THEN
      FUNCTION = %E_INVALIDARG
   ELSE
      ppmk = %NULL
      FUNCTION = %E_FAIL
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Requests pointer to object's container.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_GetContainer (BYVAL pCookie AS OC_IOLECLIENTSITE PTR, BYREF ppContainer AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   IF VARPTR(ppContainer) = %NULL THEN
      FUNCTION = %E_INVALIDARG
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, $IID_IOleContainer, ppContainer)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Asks container to display object.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_ShowObject (BYVAL pCookie AS OC_IOLECLIENTSITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - hwnd: " & STR$(@@pCookie.@pData.m_hwnd))
   ShowWindow @@pCookie.@pData.m_hwnd, %SW_SHOW
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies container when object becomes visible or invisible.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_OnShowWindow (BYVAL pCookie AS OC_IOLECLIENTSITE PTR, BYVAL fShow AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Asks container to resize display site.
' ========================================================================================
FUNCTION OC_IOleClientSiteImpl_RequestNewObjectLayout (BYVAL pCookie AS OC_IOLECLIENTSITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the IParseDisplayName interface.
' This interface, as well as support for nested simple frames is optional.
' The IParseDisplayName interface parses a displayable name string to convert it into a
' moniker for custom moniker implementations. Display name parsing is necessary when the
' end user inputs a string to identify a component, as in the following situations:
' * A compound document application that supports linked components typically supports
'   the Edit:Links... dialog box. Through this dialog box, the end user can enter a
'   display name to specify a new link source for a specified linked component. The
'   compound document needs to have this input string converted into a moniker.
' * A script language such as the macro language of a spreadsheet can allow textual
'   references to a component. The language's interpreter needs to have such a reference
'   converted into a moniker in order to execute the macro.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IParseDisplayNameImpl_QueryInterface (BYVAL pCookie AS OC_IParseDisplayName PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IParseDisplayName THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IParseDisplayNameImpl_AddRef (BYVAL pCookie AS OC_IParseDisplayName PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IParseDisplayNameImpl_Release (BYVAL pCookie AS OC_IParseDisplayName PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIParseDisplayName = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for OC_IParseDisplayNameImpl_ParseDisplayName and derived interfaces ***
' ========================================================================================
FUNCTION OC_IParseDisplayName_ParseDisplayName (BYVAL pData AS OC_DATA PTR, BYVAL pbc AS DWORD, BYVAL pszDisplayName AS DWORD,  BYREF pchEaten AS DWORD, BYREF ppmkOut AS DWORD) AS LONG
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Parses the display name returning a moniker corresponding to it.
' ========================================================================================
FUNCTION OC_IParseDisplayNameImpl_ParseDisplayName (BYVAL pCookie AS OC_IParseDisplayName PTR, BYVAL pbc AS DWORD, BYVAL pszDisplayName AS DWORD,  BYREF pchEaten AS DWORD, BYREF ppmkOut AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IParseDisplayName_ParseDisplayName(@@pCookie.pData, pbc, pszDisplayName, pchEaten, ppmkOut)
END FUNCTION
' ========================================================================================


' ########################################################################################
' Ole Container implementation of the IOleContainer interface.
' IOleContainer is implemented on the document or form object that holds the container
' sites. Controls use the IOleContainer to navigate to other controls in the same document
' or form.
' The IOleContainer interface is used to enumerate objects in a compound document or lock
' a container in the running state. Container and object applications both implement this
' interface.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleContainerImpl_QueryInterface (BYVAL pCookie AS OC_IOLECONTAINER PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleContainer THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleContainerImpl_AddRef (BYVAL pCookie AS OC_IOLECONTAINER PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleContainerImpl_Release (BYVAL pCookie AS OC_IOLECONTAINER PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleContainer = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Parses the display name returning a moniker corresponding to it.
' Not required. This method is only necessary for containers that link to controls or
' other embedded objects.
' ========================================================================================
FUNCTION OC_IOleContainerImpl_ParseDisplayName (BYVAL pCookie AS OC_IOLECONTAINER PTR, BYVAL pbc AS DWORD, BYVAL pszDisplayName AS DWORD, BYREF pchEaten AS DWORD, BYREF ppmkOut AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IParseDisplayName_ParseDisplayName(@@pCookie.pData, pbc, pszDisplayName, pchEaten, ppmkOut)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Enumerates objects in a container.
' Not required. This method is only necessary to enumerate ActiveX controls.
' ========================================================================================
FUNCTION OC_IOleContainerImpl_EnumObjects (BYVAL pCookie AS OC_IOLECONTAINER PTR, BYVAL grfFlags AS DWORD, BYREF ppenum AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   IF VARPTR(ppenum) = %NULL THEN
      FUNCTION = %E_INVALIDARG
   ELSE
      ppenum = %NULL
      FUNCTION = %E_NOTIMPL
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Keeps container running until explicitly released.
' Not required. This method is only necessary for containers that link to controls or
' other embedded objects.
' ========================================================================================
FUNCTION OC_IOleContainerImpl_LockContainer (BYVAL pCookie AS OC_IOLECONTAINER PTR, BYVAL fLock AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   @@pCookie.@pData.m_bLocked = fLock
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================


' ########################################################################################
' Ole Container implementation of the IOleInPlaceSite interface.
' The IOleInPlaceSite interface manages interaction between the container and the object's
' in-place client site. Recall that the client site is the display site for embedded
' objects, and provides position and conceptual information about the object.
' This interface provides methods that manage in-place objects. With IOleInPlaceSite, you
' can determine if an object can be activated and manage its activation and deactivation.
' You can notify the container when one of its objects is being activated and inform the
' container that a composite menu will replace the container's regular menu. It provides
' methods that make it possible for the in-place object to retrieve the window object
' hierarchy, and the position in the parent window where the object should place its
' in-place activation window. Finally, it determines how the container scrolls the object,
' manages the object undo state, and notifies the object when its borders have changed.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_QueryInterface (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleInPlaceSite THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_AddRef (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_Release (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleInPlaceSite = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the window handle to one of the windows participating in in-place activation
' (frame, document, parent, or in-place object window).
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_GetWindow (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYREF phwnd AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - phwnd: " & STR$(VARPTR(phwnd)))
   FUNCTION = OC_IOleWindow_GetWindow(@@pCookie.pData, phwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Optional. Determines whether context-sensitive help mode should be entered during an
' in-place activation session.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_ContextSensitiveHelp (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYVAL fEnterMode AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleWindow_ContextSensitiveHelp(@@pCookie.pData, fEnterMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_CanInPlaceActivate (BYVAL pData AS OC_DATA PTR) AS LONG
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines whether or not the container can activate the object in place.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_CanInPlaceActivate (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_CanInPlaceActivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_OnInPlaceActivate (BYVAL pData AS OC_DATA PTR) AS LONG
   @pData.m_bInPlaceActive = %TRUE
   IF @pData.m_pIOleObject THEN OC_OleLockRunning @pData.m_pIOleObject, %TRUE, %FALSE
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that one of its objects is being activated in place.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_OnInPlaceActivate (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnInPlaceActivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_OnUIActivate (BYVAL pData AS OC_DATA PTR) AS LONG
   @pData.m_bUIActive = %TRUE
   FUNCTION = %S_OK
END FUNCTION

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that the object is about to be activated in place and that the object
' is going to replace the container's main menu with an in-place composite menu.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_OnUIActivate (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnUIActivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_GetWindowContext (BYVAL pCookie AS DWORD, BYVAL pData AS OC_DATA PTR, _
   BYREF ppFrame AS DWORD, BYREF ppDoc AS DWORD, BYREF lprcPosRect AS RECT, BYREF lprcClipRect AS RECT, _
   BYREF lpFrameInfo AS OLEINPLACEFRAMEINFO) AS LONG

   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))

   IF VARPTR(ppFrame) = %NULL OR VARPTR(ppDoc) = %NULL OR VARPTR(lprcPosRect) = %NULL OR _
      VARPTR(lprcPosRect) = %NULL OR VARPTR(lprcClipRect) = %NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' Required: We must provide our IOleInPlaceFrame, even if we aren't
   ' going to use any of its methods, or the object will be embedded
   ' but not in-place activated.
   IF @pData.m_pIOleInPlaceFrame <> %NULL THEN
      ppFrame = @pData.m_pIOleInPlaceFrame
   ELSE
      OC_IUnknown_QueryInterface(pData, $IID_IOleInPlaceFrame, @pData.m_pIOleInPlaceFrame)
      ppFrame = @pData.m_pIOleInPlaceFrame
   END IF

   IF @pData.m_pIOleInPlaceUIWindow <> %NULL THEN
      ppDoc = @pData.m_pIOleInPlaceUIWindow
   ELSE
      OC_IUnknown_QueryInterface(pData, $IID_IOleInPlaceUIWindow, @pData.m_pIOleInPlaceUIWindow)
      ppDoc = @pData.m_pIOleInPlaceUIWindow
   END IF

   IF VARPTR (lprcPosRect) THEN
      GetClientRect @pData.m_hWnd, lprcPosRect
      GetClientRect @pData.m_hWnd, lprcClipRect
   END IF

   IF VARPTR(lpFrameInfo) THEN
      lpFrameInfo.cb = SIZEOF(OLEINPLACEFRAMEINFO)
      lpFrameInfo.fMDIApp = %FALSE
      lpFrameInfo.hWndFrame = @pData.m_hWnd
      lpFrameInfo.hAccel = 0
      lpFrameInfo.cAccelEntries = 0
   END IF

   FUNCTION = %S_OK

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Enables the in-place object to retrieve the window interfaces that form the window object
' hierarchy, and the position in the parent window where the object's in-place activation
' window should be placed.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_GetWindowContext (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYREF ppFrame AS DWORD, BYREF ppDoc AS DWORD, BYREF lprcPosRect AS RECT, BYREF lprcClipRect AS RECT, BYREF lpFrameInfo AS OLEINPLACEFRAMEINFO) AS LONG
   FUNCTION = OC_IOleInPlaceSite_GetWindowContext(pCookie, @@pCookie.pData, ppFrame, ppDoc, lprcPosRect, lprcClipRect, lpFrameInfo)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_Scroll (BYVAL pData AS OC_DATA PTR, BYREF scrollExtant AS SIZE) AS LONG
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Tells the container to scroll the view of the object by a specified number of pixels.
' Not required. This method can return S_FALSE and perform no action.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_Scroll (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYREF scrollExtant AS SIZE) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_Scroll(@@pCookie.pData, scrollExtant)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_OnUIDeactivate (BYVAL pData AS OC_DATA PTR, BYVAL fUndoable AS LONG) AS LONG
   @pData.m_bUIActive = %FALSE
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container on deactivation that it should reinstall its user interface and take
' focus, and whether or not the object has an undoable state.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_OnUIDeactivate (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYVAL fUndoable AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnUIDeactivate(@@pCookie.pData, fUndoable)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_OnInPlaceDeactivate (BYVAL pData AS OC_DATA PTR) AS LONG
   @pData.m_bInPlaceActive = %FALSE
   IF @pData.m_pIOleObject THEN
      OC_OleLockRunning @pData.m_pIOleObject, %FALSE, %FALSE
   END IF
   IF @pData.m_pIOleInPlaceObject THEN
      IUnknown_Release @pData.m_pIOleInPlaceObject
      @pData.m_pIOleInPlaceObject = %NULL
   END IF
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that the object is no longer active in place.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_OnInPlaceDeactivate (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnInPlaceDeactivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_DiscardUndoState (BYVAL pData AS OC_DATA PTR) AS LONG
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Tells the container that the object no longer has any undo state and that the container
' should not call IOleInPlaceObject::ReActivateAndUndo.
' Not required. This method can return S_OK and perform no action.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_DiscardUndoState (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_DiscardUndoState(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_DeactivateAndUndo (BYVAL pData AS OC_DATA PTR) AS LONG
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Causes the container to end the in-place session, deactivate the object, and revert to its
' own saved undo state.
' Not required. This method must implement deactivation, but undo is optional.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_DeactivateAndUndo (BYVAL pCookie AS OC_IOLEINPLACESITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_DeactivateAndUndo(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' *** Helper function for IOleInPlaceSite and IOleInPlaceSiteEx ***
' ========================================================================================
FUNCTION OC_IOleInPlaceSite_OnPosRectChange (BYVAL pCookie AS DWORD, BYVAL pData AS OC_DATA PTR, BYREF lprcPosRect AS RECT) AS LONG
   IF VARPTR(lprcPosRect) THEN
      OC_DP(FUNCNAME$ & " - pData =" & STR$(pData) & " - " & STR$(lprcPosRect.nLeft) & STR$(lprcPosRect.nRight))
      LOCAL pIOleInPlaceObject AS IOleInPlaceObject
      IF @pData.m_pIOleInPlaceObject THEN
         pIOleInPlaceObject = Ptr2Obj(@pData.m_pIOleInPlaceObject)
         IF ISOBJECT(pIOleInPlaceObject) THEN
            pIOleInPlaceObject.SetObjectRects(lprcPosRect, lprcPosRect)
            pIOleInPlaceObject = NOTHING
         END IF
      END IF
   END IF
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Indicates the object's extents have changed.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteImpl_OnPosRectChange (BYVAL pCookie AS OC_IOLEINPLACESITE PTR, BYREF lprcPosRect AS RECT) AS LONG
   FUNCTION = OC_IOleInPlaceSite_OnPosRectChange(pCookie, @@pCookie.pData, lprcPosRect)
END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the IOleInPlaceSiteEx interface.
' The IOleInPlaceSiteEx interface provides an additional set of activation and
' deactivation notification methods that enable an object to avoid unnecessary flashing on
' the screen when the object is activated and deactivated.
' When an object is activated, it does not know if its visual display is already correct.
' When the object is deactivated, the container does not know if the visual display is
' correct. To avoid a redraw and the associated screen flicker in both cases, the
' container can provide this extension to IOleInPlaceSite.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_QueryInterface (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleInPlaceSiteEx THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_AddRef (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_Release (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleInPlaceSiteEx = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the window handle to one of the windows participating in in-place activation
' (frame, document, parent, or in-place object window).
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_GetWindow (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYREF phwnd AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - phwnd: " & STR$(VARPTR(phwnd)))
   FUNCTION = OC_IOleWindow_GetWindow(@@pCookie.pData, phwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines whether context-sensitive help mode should be entered during an in-place
' activation session.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_ContextSensitiveHelp (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYVAL fEnterMode AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleWindow_ContextSensitiveHelp(@@pCookie.pData, fEnterMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Determines whether or not the container can activate the object in place.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_CanInPlaceActivate (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_CanInPlaceActivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that one of its objects is being activated in place.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnInPlaceActivate (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnInPlaceActivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that the object is about to be activated in place and that the object
' is going to replace the container's main menu with an in-place composite menu.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnUIActivate (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnUIActivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Enables the in-place object to retrieve the window interfaces that form the window object
' hierarchy, and the position in the parent window where the object's in-place activation
' window should be placed.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_GetWindowContext (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYREF ppFrame AS DWORD, BYREF ppDoc AS DWORD, BYREF lprcPosRect AS RECT, BYREF lprcClipRect AS RECT, BYREF lpFrameInfo AS OLEINPLACEFRAMEINFO) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_GetWindowContext(pCookie, @@pCookie.pData, ppFrame, ppDoc, lprcPosRect, lprcClipRect, lpFrameInfo)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Tells the container to scroll the view of the object by a specified number of pixels.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_Scroll (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYREF scrollExtant AS SIZE) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_Scroll(@@pCookie.pData, scrollExtant)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container on deactivation that it should reinstall its user interface and take
' focus, and whether or not the object has an undoable state.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnUIDeactivate (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYVAL fUndoable AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnUIDeactivate(@@pCookie.pData, fUndoable)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that the object is no longer active in place.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnInPlaceDeactivate (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_OnInPlaceDeactivate(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Tells the container that the object no longer has any undo state and that the container
' should not call IOleInPlaceObject::ReActivateAndUndo.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_DiscardUndoState (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_DiscardUndoState(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Causes the container to end the in-place session, deactivate the object, and revert to
' its own saved undo state.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_DeactivateAndUndo (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = OC_IOleInPlaceSite_DeactivateAndUndo(@@pCookie.pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Indicates the object's extents have changed.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnPosRectChange (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYREF lprcPosRect AS RECT) AS LONG
   FUNCTION = OC_IOleInPlaceSite_OnPosRectChange(pCookie, @@pCookie.pData, lprcPosRect)
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Called by the embedded object to determine if it needs to redraw itself upon activation.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnInPlaceActivateEx (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYREF pfNoRedraw AS LONG, BYVAL dwFlags AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie) & " - Flags = " & STR$(dwFlags))
   @@pCookie.@pData.m_bInPlaceActive = %TRUE
   IF @@pCookie.@pData.m_pIOleObject THEN
      OC_OleLockRunning @@pCookie.@pData.m_pIOleObject, %TRUE, %FALSE
   END IF
'   LOCAL rcPos AS RECT
'   LOCAL pIOleInPlaceObject AS IOleInPlaceObject
'   GetClientRect @@pCookie.@pData.m_hWnd, rcPos
'   IF @@pCookie.@pData.m_pIOleInPlaceObject = %NULL THEN
'      IUnknown_QueryInterface(@@pCookie.@pData.m_pthis, $IID_IOleInPlaceObject, @@pCookie.@pData.m_pIOleInPlaceObject)
'   END IF
'   IF @@pCookie.@pData.m_pIOleInPlaceObject THEN
'      pIOleInPlaceObject = Ptr2Obj(@@pCookie.@pData.m_pIOleInPlaceObject)
'      IF ISOBJECT(pIOleInPlaceObject) THEN
'         pIOleInPlaceObject.SetObjectRects(rcPos, rcPos)
'         pIOleInPlaceObject = NOTHING
'      END IF
'   END IF
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container of whether the object needs to be redrawn upon deactivation.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_OnInPlaceDeactivateEx (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR, BYVAL pfNoRedraw AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   IF @@pCookie.@pData.m_pIOleObject THEN
      OC_OleLockRunning @@pCookie.@pData.m_pIOleObject, %FALSE, %FALSE
   END IF
   IF @@pCookie.@pData.m_pIOleInPlaceObject THEN
      IUnknown_Release @@pCookie.@pData.m_pIOleInPlaceObject
      @@pCookie.@pData.m_pIOleInPlaceObject = %NULL
   END IF
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Notifies the container that the object is about to enter the UI-active state.
' ========================================================================================
FUNCTION OC_IOleInPlaceSiteExImpl_RequestUIActivate (BYVAL pCookie AS OC_IOLEINPLACESITEEX PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================


' ########################################################################################
' Ole Container implementation of the IOleControlSite interface.
' The IOleControlSite interface provides the methods that enable a site object to manage
' each embedded control within a container. A site object provides IOleControlSite as well
' as other site interfaces such as IOleClientSite and IOleInPlaceSite. When a control
' requires the services expressed through this interface, it will query one of the other
' client site interfaces for IOleControlSite.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_QueryInterface (BYVAL pCookie AS OC_IOLECONTROLSITE PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IOleControlSite THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_AddRef (BYVAL pCookie AS OC_IOLECONTROLSITE PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_Release (BYVAL pCookie AS OC_IOLECONTROLSITE PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIOleControlSite = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Informs the container that the control's CONTROLINFO structure has changed and that the
' container should call the control's IOleControl::GetControlInfo for an update.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_OnControlInfoChanged (BYVAL pCookie AS OC_IOLECONTROLSITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK ' Returned in all cases
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Optional Indicates whether or not this control should remain in-place active, regardless
' of possible deactivation events.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_LockInPlaceActive (BYVAL pCookie AS OC_IOLECONTROLSITE PTR, BYVAL fLock AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   ' FUNCTION = %S_OK or FUNCTION = %E_NOTIMPL
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Requests an IDispatch pointer to the extended control that the container uses to wrap
' the real control.
' Not required. This method is only necessary for containers that support extended controls.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_GetExtendedControl (BYVAL pCookie AS OC_IOLECONTROLSITE PTR, BYREF ppDisp AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   ' FUNCTION = %S_OK or FUNCTION = %E_NOTIMPL or FUNCTION = %E_POINTER
   IF VARPTR(ppDisp) = %NULL THEN
      FUNCTION = %E_POINTER
   ELSE
      ppDisp = %NULL
      FUNCTION = %E_NOTIMPL
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Converts between a POINTL structure expressed in HIMETRIC units (as is standard in OLE)
' and a POINTF structure expressed in units the container specifies.
' %HIMETRIC_PER_INCH = 2540   ' 1 inch = 2.54 mm
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_TransformCoords (BYVAL pCookie AS OC_IOLECONTROLSITE PTR, BYREF pPtlHimetric AS POINTL, BYREF pPtfContainer AS POINTFLOAT, BYVAL dwFlags AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   ' FUNCTION = %S_OK or FUNCTION = %E_NOTIMPL or FUNCTION = %E_POINTER
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   IF hDC THEN
'      IF (dwFlags AND %XFORMCOORDS_HIMETRICTOCONTAINER) THEN
      IF (dwFlags AND &H4???) THEN
         pPtfContainer.x = MulDiv(pPtlHimetric.x, GetDeviceCaps(hDC, %LOGPIXELSX), 2540)
         pPtfContainer.y = MulDiv(pPtlHimetric.y, GetDeviceCaps(hDC, %LOGPIXELSY), 2540)
'      ELSEIF (dwFlags AND %XFORMCOORDS_CONTAINERTOHIMETRIC) THEN
      ELSEIF (dwFlags AND &H8???) THEN
         pPtlHimetric.x = MulDiv(pPtfContainer.x, 2540, GetDeviceCaps(hDC, %LOGPIXELSX))
         pPtlHimetric.y = MulDiv(pPtfContainer.y, 2540, GetDeviceCaps(hDC, %LOGPIXELSY))
      END IF
   END IF
   ReleaseDC(%NULL, hDC)
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Instructs the container to process a specified keystroke.
' Not required. This method can return S_FALSE and perform no action.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_TranslateAccelerator (BYVAL pCookie AS OC_IOLECONTROLSITE PTR, BYREF pMsg AS tagMSG, BYVAL grfModifiers AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   ' FUNCTION = %S_OK or FUNCTION = %S_FALSE or FUNCTION = %E_NOTIMPL
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Indicates whether the embedded control in this control site has gained or lost the focus.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_OnFocus (BYVAL pCookie AS OC_IOLECONTROLSITE PTR, BYVAL fGotFocus AS LONG) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   FUNCTION = %S_OK ' Returned in all cases
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Instructs the container to show a property page frame for the control object if the
' container so desires.
' Not required. This method is necessary only for containers that want to include their
' own property pages to handle extended control properties in addition to those provided
' by a control.
' ========================================================================================
FUNCTION OC_IOleControlSiteImpl_ShowPropertyFrame (BYVAL pCookie AS OC_IOLECONTROLSITE PTR) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   ' FUNCTION = %S_OK or FUNCTION = %E_NOTIMPL
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ========================================================================================


' ########################################################################################
' Ole Container implementation of the IServiceProvider interface.
' The IServiceProvider interface is a generic access mechanism to locate a globally unique
' identifier (GUID) identified service.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_IServiceProviderImpl_QueryInterface (BYVAL pCookie AS OC_ISERVICEPROVIDER PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_IServiceProvider THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_IServiceProviderImpl_AddRef (BYVAL pCookie AS OC_ISERVICEPROVIDER PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_IServiceProviderImpl_Release (BYVAL pCookie AS OC_ISERVICEPROVIDER PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pIServiceProvider = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Acts as the factory method for any services exposed through an implementation of
' IServiceProvider.
' ========================================================================================
FUNCTION OC_IServiceProviderImpl_QueryService (BYVAL pCookie AS OC_ISERVICEPROVIDER PTR, BYREF guidService AS GUID, BYREF riid AS GUID, BYREF ppv AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie))
   ' FUNCTION = %S_OK or FUNCTION = %E_OUTOFMEMORY or FUNCTION = %E_UNEXPECTED or FUNCTION = %E_NOINTERFACE
   IF VARPTR(guidService) THEN OC_DP(FUNCNAME$ & " - SID = " & GUIDTXT$(guidService))
   IF VARPTR(riid) THEN OC_DP(FUNCNAME$ & " - riid = " & GUIDTXT$(riid))
   LOCAL hr AS LONG
   ppv = %NULL
   hr = %E_NOINTERFACE
   ' // Handle SID_SInPlaceBrowser (needed to enable the filesystem object to navigate
   ' // in-place within the WebBrowser control when running on Windows 7)
   IF guidService = $SID_SInPlaceBrowser THEN
      hr = OC_IUnknown_QueryService(@@pCookie.@pData.m_pthis, $SID_SShellBrowser, riid, ppv)
   END IF
   FUNCTION = hr
END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation of the ISimpleFrameSite interface.
' The ISimpleFrameSite interface supports simple frame controls that act as simple
' containers for other nested controls. Some controls merely contain other controls. In
' such cases, the simple control container, called a simple frame, doesn't have to
' implement all container requirements. It can delegate most of the interface calls from
' its contained controls to the outer container that manages the simple frame.
' ########################################################################################

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Returns the IUnknown of our class and increments the reference counter.
' ========================================================================================
FUNCTION OC_ISimpleFrameSiteImpl_QueryInterface (BYVAL pCookie AS OC_ISIMPLEFRAMESITE PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - " & OC_GetInterfaceName(riid))
   IF riid = $IID_ISimpleFrameSite THEN
      ppvObj = pCookie
      INCR @@pCookie.cRef
      FUNCTION = %S_OK
   ELSE
      FUNCTION = OC_IUnknown_QueryInterface(@@pCookie.pData, riid, ppvObj)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Increments the reference counter.
' ========================================================================================
FUNCTION OC_ISimpleFrameSiteImpl_AddRef (BYVAL pCookie AS OC_ISIMPLEFRAMESITE PTR) AS DWORD
   INCR @@pCookie.cRef
   FUNCTION = @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Releases our class if there is only a reference to him and decrements the reference counter.
' ========================================================================================
FUNCTION OC_ISimpleFrameSiteImpl_Release (BYVAL pCookie AS OC_ISIMPLEFRAMESITE PTR) AS DWORD
   DECR @@pCookie.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pCookie.cRef))
   FUNCTION = @@pCookie.cRef
   IF @@pCookie.cRef = 0 THEN
      IF @@pCookie.pVtblAddr THEN
         @@pCookie.@pData.m_pISimpleFrameSite = %NULL
         HeapFree(GetProcessHeap(), 0, BYVAL @@pCookie.pVtblAddr)
         OC_DP(FUNCNAME$ & " *** Memory released ***")
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Provides a site with the opportunity to process a message that is received by a
' control's own window before the control itself does any processing.
' ========================================================================================
FUNCTION OC_ISimpleFrameSiteImpl_PreMessageFilter (BYVAL pCookie AS OC_ISIMPLEFRAMESITE PTR, _
   BYVAL hwnd AS DWORD, BYVAL msg AS DWORD, BYVAL wp AS DWORD, BYVAL lp AS DWORD, BYREF plResult AS LONG, BYREF pdwCookie AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie) & " - msg = &H" & HEX$(msg, 4))
   ' FUNCTION = %S_OK or FUNCTION = %S_FALSE or FUNCTION = %E_NOINTERFACE or FUNCTION = %E_POINTER
   IF VARPTR(plResult) = %NULL OR VARPTR(pdwCookie) = %NULL THEN
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF
   FUNCTION = %S_OK

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION ***
' Sends the simple frame site a message that is received by a control's own window after
' both ISimpleFrameSite::PreMessageFilter and the control have had a chance to process the
' message.
' ========================================================================================
FUNCTION OC_ISimpleFrameSiteImpl_PostMessageFilter (BYVAL pCookie AS OC_ISIMPLEFRAMESITE PTR, _
   BYVAL hwnd AS DWORD, BYVAL msg AS DWORD, BYVAL wp AS DWORD, BYVAL lp AS DWORD, BYREF plResult AS LONG, BYVAL dwCookie AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - pCookie: " & STR$(pCookie) & " - msg = &H" & HEX$(msg, 4))
   ' FUNCTION = %S_OK or FUNCTION = %S_FALSE or FUNCTION = %E_NOINTERFACE or FUNCTION = %E_POINTER
   IF VARPTR(plResult) = %NULL THEN
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF
   FUNCTION = %S_FALSE
END FUNCTION
' ========================================================================================

' ########################################################################################
' Event Sink Class
' Connects/disconnects from the events fired by a server.
' Call OC_Advise to connect events and OC_Unadvise to disconnect.
' ########################################################################################

' ########################################################################################
' IConnectionPointContainer::FindConnectionPoint
' Returns a pointer to the IConnectionPoint interface of a connection point for a specified IID,
' if that IID describes a supported outgoing interface.
' ########################################################################################
FUNCTION OC_IConnectionPointContainer_FindConnectionPoint (BYVAL pthis AS DWORD PTR, BYREF riid AS GUID, BYREF ppCP AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   CALL DWORD @@pthis[4] USING OC_IConnectionPointContainer_FindConnectionPoint(pthis, riid, ppCP) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ########################################################################################

' ########################################################################################
' IConnectionPoint::Advise
' Establishes a connection between the connection point object and the client's sink.
' ########################################################################################
FUNCTION OC_IConnectionPoint_Advise (BYVAL pthis AS DWORD PTR, BYVAL pUnkSink AS DWORD, BYREF pdwCookie AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   CALL DWORD @@pthis[5] USING OC_IConnectionPoint_Advise(pthis, pUnkSink, pdwCookie) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ########################################################################################

' ########################################################################################
' IConnectionPoint::Unadvise
' Terminates an advisory connection previously established through OC_IConnectionPoint_Advise.
' The dwCookie parameter identifies the connection to terminate.
' ########################################################################################
FUNCTION OC_IConnectionPoint_Unadvise (BYVAL pthis AS DWORD PTR, BYVAL dwCookie AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   CALL DWORD @@pthis[6] USING OC_IConnectionPoint_Unadvise(pthis, dwCookie) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ########################################################################################

' ########################################################################################
' IDispatch virtual table
' ########################################################################################
TYPE OC_IDispatchEventsVtbl
   QueryInterface   AS DWORD   ' // Returns pointers to supported interfaces
   AddRef           AS DWORD   ' // Increments reference count
   Release          AS DWORD   ' // Decrements reference count
   GetTypeInfoCount AS DWORD   ' // Retrieves the number of type descriptions
   GetTypeInfo      AS DWORD   ' // Retrieves a description of object's programmable interface
   GetIDsOfNames    AS DWORD   ' // Maps name of method or property to DispId
   Invoke           AS DWORD   ' // Calls one of the object's methods, or gets/sets one of its properties
   pVtblAddr        AS DWORD   ' // Address of the virtual table
   cRef             AS DWORD   ' // Reference count
   pthis            AS DWORD   ' // IUnknown or IDispatch of the control that fires the events
   pEvtObj          AS DWORD   ' // Pointer of the custom event sink class
   dwCookie         AS DWORD   ' // Cookie
   riid             AS GUID    ' // GUID of the events interface
END TYPE
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' Builds the IDispatch Virtual Table
' ########################################################################################
FUNCTION OC_IDispatchEvents_BuildVtbl (BYVAL pthis AS DWORD, BYREF riid AS GUID) AS DWORD

   OC_DP(FUNCNAME$ & " - riid: " & GUIDTXT$(riid))

   LOCAL pVtbl AS OC_IDispatchEventsVtbl PTR
   LOCAL pUnk AS OC_IDispatchEventsVtbl PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.QueryInterface   = CODEPTR(OC_IDispatchEvents_QueryInterface)
   @pVtbl.AddRef           = CODEPTR(OC_IDIspatchEvents_AddRef)
   @pVtbl.Release          = CODEPTR(OC_IDispatchEvents_Release)
   @pVtbl.GetTypeInfoCount = CODEPTR(OC_IDispatchEvents_GetTypeInfoCount)
   @pVtbl.GetTypeInfo      = CODEPTR(OC_IDispatchEvents_GetTypeInfo)
   @pVtbl.GetIDsOfNames    = CODEPTR(OC_IDispatchEvents_GetIDsOfNames)
   @pVtbl.Invoke           = CODEPTR(OC_IDispatchEvents_Invoke)
   @pVtbl.pVtblAddr        = pVtbl
   @pVtbl.pthis            = pthis
   @pVtbl.riid             = riid

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   FUNCTION = pUnk

END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' HRESULT QueryInterface([in] *GUID riid, [out] **VOID ppvObj)
' Returns the IUnknown of our class and increments the reference counter.
' ########################################################################################
FUNCTION OC_IDispatchEvents_QueryInterface (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR, _
   BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   OC_DP(FUNCNAME$ & " - riid: " & GUIDTXT$(riid))
   IF riid = $IID_IUnknown OR _     ' // IUnknown interface
      riid = $IID_IDispatch OR _    ' // IDispatch interface
      riid = @@pUnkSink.riid THEN   ' // Events dispatch interface
      ppvObj = pUnkSink
      OC_IDIspatchEvents_AddRef pUnkSink
      FUNCTION = %S_OK
   ELSE
      ppvObj = %NULL
      FUNCTION = %E_NOINTERFACE
   END IF
END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' UI4 AddRef()
' Increments the reference count.
' ########################################################################################
FUNCTION OC_IDIspatchEvents_AddRef (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR) AS DWORD
   INCR @@pUnkSink.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pUnkSink.cRef))
   FUNCTION = @@pUnkSink.cRef
END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' UI4 Release()
' Releases our class if there is only a reference to him and decrements the reference counter.
' ########################################################################################
FUNCTION OC_IDispatchEvents_Release (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR) AS DWORD
   LOCAL pVtblAddr AS DWORD
   IF @@pUnkSink.cRef = 1 THEN
      pVtblAddr = @@pUnkSink.pVtblAddr
      IF ISTRUE HeapFree(GetProcessHeap(), 0, BYVAL pVtblAddr) THEN
         OC_DP(FUNCNAME$ & "  *** Memory released ***")
         FUNCTION = 0
         EXIT FUNCTION
      ELSE
         OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pUnkSink.cRef))
         FUNCTION = @@pUnkSink.cRef
         EXIT FUNCTION
      END IF
   END IF
   DECR @@pUnkSink.cRef
   FUNCTION = @@pUnkSink.cRef
   OC_DP(FUNCNAME$ & " - cRef: " & STR$(@@pUnkSink.cRef))
END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' HRESULT GetTypeInfoCount([out] *UINT pctinfo)
' ########################################################################################
FUNCTION OC_IDispatchEvents_GetTypeInfoCount (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR, BYREF pctInfo AS DWORD) AS LONG
   OC_DP(FUNCNAME$)
   IF VARPTR(pctInfo) THEN pctInfo = 0
   FUNCTION = %S_OK
END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' HRESULT GetTypeInfo([in] UINT itinfo, [in] UI4 lcid, [out] **VOID pptinfo)
' ########################################################################################
FUNCTION OC_IDispatchEvents_GetTypeInfo (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR, _
   BYVAL itinfo AS DWORD, BYVAL lcid AS DWORD, BYREF pptinfo AS DWORD) AS LONG
   OC_DP(FUNCNAME$)
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' HRESULT GetIDsOfNames([in] *GUID riid, [in] **I1 rgszNames, [in] UINT cNames, [in] UI4 lcid, [out] *I4 rgdispid)
' ########################################################################################
FUNCTION OC_IDispatchEvents_GetIDsOfNames (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR, _
   BYREF riid AS GUID, BYVAL rgszNames AS DWORD, BYVAL cNames AS DWORD, BYVAL lcid AS DWORD, BYREF rgdispid AS LONG) AS LONG
   OC_DP(FUNCNAME$)
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PRIVATE FUNCTION ***
' HRESULT Invoke([in] I4 dispidMember, [in] *GUID riid, [in] UI4 lcid, [in] UI2 wFlags, [in] *DISPPARAMS pdispparams, [out] *VARIANT pvarResult, [out] *EXCEPINFO pexcepinfo, [out] *UINT puArgErr)
' ########################################################################################
FUNCTION OC_IDispatchEvents_Invoke (BYVAL pUnkSink AS OC_IDispatchEventsVtbl PTR, BYVAL dispidMember AS LONG, BYREF riid AS GUID, _
   BYVAL lcid AS DWORD, BYVAL wFlags AS WORD, BYREF pdispparams AS DISPPARAMS, BYREF pvarResult AS VARIANT, _
   BYREF pexcepinfo AS EXCEPINFO, BYREF puArgErr AS DWORD) AS LONG

   OC_DP(FUNCNAME$ & " - " & STR$(dispidMember))

   LOCAL hr AS LONG
   LOCAL pEvtObj AS IDispatch
   IF @@pUnkSink.pEvtObj THEN
      POKE DWORD, VARPTR(pEvtObj), @@pUnkSink.pEvtObj
      IF ISOBJECT(pEvtObj) THEN
         pEvtObj.AddRef
         hr = pEvtObj.Invoke(dispidMember, riid, lcid, wFlags, pdispparams, _
              pvarResult, BYVAL VARPTR(pexcepinfo), puArgErr)
      ELSE
         POKE DWORD, VARPTR(pEvtObj), 0
      END IF
   END IF
   pEvtObj = NOTHING
   FUNCTION = hr

END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PUBLIC FUNCTION ***
' Establishes a connection between the connection point object and the client's sink.
' Parameters:
'   [in] hwnd = Window handle
'   [in] pEvtObj = Reference to the event class
'   [in, opt] riid = The GUID of the connection point (the iid of the events interface).
' Return value:
'   Returns TRUE or FALSE.
' Remarks:
'   If the riid parameter is not null, the function uses low-level calls to connect events;
'   otherwise, the connection is done calling the EVENTS FROM statement.
' Note: Although most connections will succeed using the EVENTS FROM statement, the
' Windows Media Player fails (error 99) unless pEvtObj is declared as the name of the
' implemented event class, e.g. BYVAL pEvtObj AS WMPOCXEventsImpl.
' ########################################################################################
FUNCTION OC_Advise (BYVAL hwnd AS DWORD, BYVAL pEvtObj AS IDispatch, OPTIONAL BYREF riid AS GUID) AS LONG

   LOCAL hr       AS LONG                         ' // HRESULT code
   LOCAL pData    AS OC_DATA PTR                  ' // OC_DATA structure
   LOCAL pDisp    AS IDispatch                    ' // IDispatch object variable
   LOCAL pCPC     AS DWORD                        ' // IConnectionPointContainer
   LOCAL pCP      AS DWORD                        ' // IConnectionPoint
   LOCAL dwCookie AS DWORD                        ' // Returned token
   LOCAL pUnkSink AS OC_IDispatchEventsVtbl PTR   ' // IUnknown of the event class

   IF VARPTR(riid) THEN
      OC_DP(FUNCNAME$ & " - " & GUIDTXT$(riid))
   ELSE
      OC_DP(FUNCNAME$)
   END IF

   IF ISFALSE IsWindow(hwnd) THEN EXIT FUNCTION
   IF ISNOTHING(pEvtObj) THEN EXIT FUNCTION
   IF GetProp(hWnd, $OC_IID) = %NULL THEN EXIT FUNCTION
   pData = GetWindowLong(hWnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pthis = %NULL THEN EXIT FUNCTION

   ' // Release the previous connection, if any
   IF @pData.m_pUnkSink <> 0 OR @pData.m_pEvtObj <> 0 THEN OC_UnAdvise hwnd

   IF VARPTR(riid) THEN
      ' // Retrieve a reference to the IConnectionPointContainer interface
      hr = IUnknown_QueryInterface(@pData.m_pthis, $IID_IConnectionPointContainer, pCPC)
      IF hr <> %S_OK THEN EXIT FUNCTION
      ' // Retrieve a reference to the IConnectionPoint interface
      hr = OC_IConnectionPointContainer_FindConnectionPoint(pCPC, riid, pCP)
      IUnknown_Release pCPC
      IF hr <> %S_OK THEN EXIT FUNCTION
      ' // Build the Dispatch virtual table
      pUnkSink = OC_IDispatchEvents_BuildVtbl(@pData.m_pthis, riid)
      IF pUnkSink = %NULL THEN
         IUnknown_Release pCP
         EXIT FUNCTION
      END IF
      ' // Connect events
      hr = OC_IConnectionPoint_Advise(pCP, pUnkSink, dwCookie)
      IUnknown_Release pCP
      IF hr <> %S_OK THEN EXIT FUNCTION
      ' // Increase the reference count of the event class
      pEvtObj.AddRef
      ' // Store the data
      @@pUnkSink.pEvtObj = OBJPTR(pEvtObj)
      @@pUnkSink.dwCookie = dwCookie
      @pData.m_pUnkSink = pUnkSink
      FUNCTION = %TRUE
      EXIT FUNCTION
   ELSE
      ' // Convert the the stored pointer to an object variable
      POKE DWORD, VARPTR(pDisp), @pData.m_pthis
      IF ISNOTHING(pDisp) THEN
         POKE DWORD, VARPTR(pDisp), 0
         EXIT FUNCTION
      END IF
      pDisp.AddRef
      ' // Connect events
      ERRCLEAR
      EVENTS FROM pDisp CALL pEvtObj
      IF ERR THEN
         FUNCTION = %FALSE
      ELSE
         ' // Increase the reference count of the event class
         pEvtObj.AddRef
         ' // Store a pointer to it
         @pData.m_pEvtObj = OBJPTR(pEvtObj)
         FUNCTION = %TRUE
      END IF
      ' // Release the object variable
      pDisp = NOTHING
   END IF

END FUNCTION
' ########################################################################################

' ########################################################################################
' *** PUBLIC FUNCTION ***
' Releases the events connection identified with the cookie returned by the OC_Advise function
' Parameter:
'   [in]  hwnd = Window handle
' Return value:
'   Returns TRUE or FALSE.
' Remarks:
'   If the connection has been done using low-level calls, the function uses low-level
'   calls to disconnect events; otherwise, it uses the EVENTS END statement.
' ########################################################################################
FUNCTION OC_Unadvise (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hr       AS LONG                         ' // HRESULT code
   LOCAL pData    AS OC_DATA PTR                  ' // OC_DATA structure
   LOCAL pEvtObj  AS IDispatch                    ' // Events object variable
   LOCAL pCPC     AS DWORD                        ' // IConnectionPointContainer
   LOCAL pCP      AS DWORD                        ' // IConnectionPoint
   LOCAL pUnkSink AS OC_IDispatchEventsVtbl PTR   ' // IUnknown of the event class

   OC_DP(FUNCNAME$)

   IF GetProp(hwnd, $OC_IID) = %NULL THEN EXIT FUNCTION
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pthis = %NULL THEN EXIT FUNCTION
   IF @pData.m_pEvtObj = %NULL AND @pData.m_pUnkSink = %NULL THEN EXIT FUNCTION

   IF @pData.m_pUnkSink THEN
      pUnkSink = @pData.m_pUnkSink
      hr = IUnknown_QueryInterface(@pData.m_pthis, $IID_IConnectionPointContainer, pCPC)
      IF hr <> %S_OK THEN EXIT FUNCTION
      hr = OC_IConnectionPointContainer_FindConnectionPoint(pCPC, @@pUnkSink.riid, pCP)
      IUnknown_Release pCPC
      IF hr <> %S_OK THEN EXIT FUNCTION
      hr = OC_IConnectionPoint_Unadvise(pCP, @@pUnkSink.dwCookie)
      IF hr <> %S_OK THEN
         IUnknown_Release pCP
         EXIT FUNCTION
      END IF
      IF @@pUnkSink.pEvtObj THEN IUnknown_Release @@pUnkSink.pEvtObj
      @pData.m_pUnkSink = %NULL
      IUnknown_Release pCP
      FUNCTION = %TRUE
      EXIT FUNCTION
   ELSE
      ' // Convert the stored pointer to an object variable
      POKE DWORD, VARPTR(pEvtObj), @pData.m_pEvtObj
      IF ISNOTHING(pEvtObj) THEN
         POKE DWORD, VARPTR(pEvtObj), 0
         EXIT FUNCTION
      END IF
      pEvtObj.AddRef
      ' // Disconnet events
      ERRCLEAR
      EVENTS END pEvtObj
      IF ERR THEN FUNCTION = %FALSE ELSE FUNCTION = %TRUE
      ' // Release the reference kept by the control
      IUnknown_Release @pData.m_pEvtObj
      @pData.m_pEvtObj = 0
      ' // Release the object variable
      pEvtObj = NOTHING
   END IF

END FUNCTION
' ########################################################################################

' ########################################################################################
' Ole Container helper functions.
' ########################################################################################

' ========================================================================================
' *** PUBLIC FUNCTION ***
' Returns a reference to the control's default interface given the handle of the window that hosts it.
' ========================================================================================
FUNCTION OC_GetDispatch (BYVAL hWnd AS DWORD) AS IDispatch

   LOCAL hr    AS LONG          ' // HRESULT code
   LOCAL pData AS OC_DATA PTR   ' // OC_DATA structure
   LOCAL pDisp AS IDispatch     ' // IDispatch object variable

   OC_DP(FUNCNAME$)

   IF GetProp(hWnd, $OC_IID) = %NULL THEN EXIT FUNCTION
   pData = GetWindowLong(hWnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pthis = %NULL THEN EXIT FUNCTION

   POKE DWORD, VARPTR(pDisp), @pData.m_pthis
   IF ISOBJECT(pDisp) THEN
      pDisp.AddRef
      FUNCTION = pDisp
   ELSE
      POKE DWORD, VARPTR(pDisp), 0
   END IF
   pDisp = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PUBLIC FUNCTION ***
' Returns a reference to the event sink class given the handle of the window that hosts the control.
' ========================================================================================
FUNCTION OC_GetEventSink (BYVAL hWnd AS DWORD) AS IDispatch

   LOCAL hr       AS LONG                         ' // HRESULT code
   LOCAL pData    AS OC_DATA PTR                  ' // OC_DATA structure
   LOCAL pDisp    AS IDispatch                    ' // IDispatch object variable
   LOCAL pUnkSink AS OC_IDispatchEventsVtbl PTR   ' // IUnknown of the event class

   OC_DP(FUNCNAME$)

   IF GetProp(hwnd, $OC_IID) = %NULL THEN EXIT FUNCTION
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pEvtObj = %NULL AND @pData.m_pUnkSink = %NULL THEN EXIT FUNCTION

   IF @pData.m_pUnkSink THEN
      pUnkSink = @pData.m_pUnkSink
      POKE DWORD, VARPTR(pDisp), @@pUnkSink.pEvtObj
      IF ISOBJECT(pDisp) THEN
         pDisp.AddRef
         FUNCTION = pDisp
      ELSE
         POKE DWORD, VARPTR(pDisp), 0
      END IF
   ELSE
      POKE DWORD, VARPTR(pDisp), @pData.m_pEvtObj
      IF ISOBJECT(pDisp) THEN
         pDisp.AddRef
         FUNCTION = pDisp
      ELSE
         POKE DWORD, VARPTR(pDisp), 0
      END IF
   END IF
   pDisp = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PUBLIC FUNCTION ***
' Forwards the message to the control. Active in-place objects must always be given the
' first chance at translating accelerator keystrokes. You can provide this opportunity by
' calling IOleInPlaceActiveObject::TranslateAccelerator from your container's message loop
' before doing any other translation. You should apply your own translation only when this
' method returns S_FALSE.
' ========================================================================================
FUNCTION OC_ForwardMessage (BYVAL hWnd AS DWORD, BYREF pMsg AS tagMsg) AS LONG

   LOCAL hr AS LONG
   LOCAL hWndCtrl AS DWORD
   LOCAL pData AS OC_DATA PTR
   LOCAL pActiveObject AS DWORD
   LOCAL pIOleInPlaceActiveObject AS IOleInPlaceActiveObject

   DO
      ' // If it has our identifier as a property, then it is our container window
      IF GetProp(hWnd, $OC_IID) THEN
         hWndCtrl = hWnd
         EXIT DO
      END IF
      ' // Get the parent window handle
      hWnd = GetParent(hWnd)
      IF hWnd = 0 THEN EXIT DO
   LOOP

   ' // If it is our container window...
   IF hWndCtrl THEN
      ' // Get the pointer to the window's data
      pData = GetWindowLong(hWndCtrl, 0)
      IF pData THEN
         ' // Translate the message
         hr = IUnknown_QueryInterface(@pData.m_pthis, $IID_IOleInPlaceActiveObject, pActiveObject)
         IF pActiveObject THEN
            pIOleInPlaceActiveObject = Ptr2Obj(pActiveObject)
            IF ISOBJECT(pIOleInPlaceActiveObject) THEN
               hr = pIOleInPlaceActiveObject.TranslateAccelerator(pMsg)
               OC_DP("pIOleInPlaceActiveObject.TranslateAccelerator &H" & HEX$(hr))
               IF hr = %S_OK THEN FUNCTION = %S_FALSE
               pIOleInPlaceActiveObject = NOTHING
            END IF
            hr = IUnknown_Release(pActiveObject)
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PUBLIC FUNCTION ***
' Creates an instance of an object.
' Parameters:
' strProgID
'   Required. String. The ProgID or the CLSID of the object to create.
'   - A ProgID such as "MSCAL.Calendar.7"
'   - A CLSID such as "{8E27C92B-1264-101C-8A2F-040224009C02}"
' pDispatch
'   Required. Dword. Address of pointer variable that receives the dispatch interface
'   pointer. Upon failure, pDispatch contains %NULL.
' Return value:
'   One of the standard HRESULT values or %S_OK
' ========================================================================================
FUNCTION OC_CreateObject (BYVAL strProgID AS STRING, BYREF pDispatch AS DWORD) AS LONG

   LOCAL hr       AS LONG    ' // HRESULT
   LOCAL pUnknown AS DWORD   ' // IUnknown pointer
   LOCAL ClassID  AS GUID    ' // CLSID

   ' // Exit if it is a null pointer
   IF VARPTR(pDispatch) = 0 THEN
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF

   ' // Exit if strProgID is a null string
   IF strProgID = "" THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' // Convert the ProgID in a CLSID
   ClassID = CLSID$(strProgID)

   ' // If it fails, see if it is a CLSID
   IF ClassID = $IID_NULL THEN ClassID = GUID$(strProgID)

   ' // If not a valid ProgID or CLSID return an error
   IF ClassID = $IID_NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' // Create an instance of the object
   ' // Context: &H15 (%CLSCTX_SERVER)
   hr = CoCreateInstance(ClassID, NOTHING, &H15, $IID_IUnknown, pUnknown)
   OC_DP(FUNCNAME$ & " hr - " & STR$(hr) & " - IUnknwon = " & STR$(pUnknown))
   IF hr = %S_OK AND pUnknown <> %NULL THEN
      ' // Query for the IDispatch interface
      hr = IUnknown_QueryInterface(pUnknown, $IID_IDispatch, pDispatch)
      OC_DP(FUNCNAME$ & " hr - " & STR$(hr) & " - IDispatch = " & STR$(pDispatch))
      ' // Release the IUnknown interface
      IUnknown_Release pUnknown
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ########################################################################################
' Ole Container implementation.
' ########################################################################################

' ========================================================================================
' *** PUBLIC FUNCTION ***
' Registers the window class
' ========================================================================================
FUNCTION OC_WinInit () AS WORD

   LOCAL  wcex        AS WNDCLASSEX     ' // WNDCLASSEX structure
   STATIC wAtom       AS WORD           ' // Atom

   ' // Already initialized
   IF wAtom <> 0 THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

   ' // Register the window class
#IF %DEF(%UNICODE)
   LOCAL szClassName AS WSTRINGZ * 256
#ELSE
   LOCAL szClassName AS ASCIIZ * 256
#ENDIF
   szClassName        = $OC_CLASSNAME
   wcex.cbSize        = SIZEOF(wcex)
#IF %PB_EXE = 0
   wcex.style         = %CS_GLOBALCLASS                ' // For use with DLLs
#ELSE
   wcex.style         = 0
#ENDIF
   wcex.lpfnWndProc   = CODEPTR(OC_OleContainerProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4                              ' // For pointer to OC_DATA structure
   wcex.hInstance     = GetModuleHandle(BYVAL %NULL)
   wcex.hbrBackground = %COLOR_3DFACE + 1              ' // GetStockObject(%WHITE_BRUSH)
   wcex.lpszClassName = VARPTR(szClassName)

   wAtom = RegisterClassEx(wcex)
   FUNCTION = wAtom

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** PRIVATE FUNCTION (Don't call it directly) ***
' Control's callback procedure
' ========================================================================================
FUNCTION OC_OleContainerProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hr                  AS LONG                              ' // Result code
   LOCAL idx                 AS LONG                              ' // Index variable
   LOCAL rc                  AS RECT                              ' // RECT structure
   LOCAL pData               AS OC_DATA PTR                       ' // Pointer to the OC_DATA structure
   LOCAL pCreateStruct       AS CREATESTRUCT PTR                  ' // Initialization parameters
   LOCAL pCreateParams       AS OC_CREATEPARAMS PTR               ' // Creation parameters
   LOCAL strProgID           AS STRING                            ' // Program identifier
   LOCAL strLicKey           AS STRING                            ' // License key
   LOCAL pxSize              AS SIZEL                             ' // Size limit for object in pizels
   LOCAL hmSize              AS SIZEL                             ' // Size limit for object in himetric
   LOCAL hWndCtrl            AS DWORD                             ' // Window's handle
   LOCAL pIFontDisp          AS DWORD                             ' // IFontDisp interface pointer
   LOCAL szLibName           AS ASCIIZ * %MAX_PATH                ' // Library name
   LOCAL pDispatch           AS IDispatch                         ' // General purpose object variable
   LOCAL pIOleObject         AS IOleObject                        ' // IOleObject interface
   LOCAL wszContainerApp     AS WSTRINGZ * 260                    ' // Container application name
   LOCAL wszContainerObj     AS WSTRINGZ * 260                    ' // Container object name
   LOCAL pIOleInPlaceObject  AS IOleInPlaceObject                 ' // IOleInPlaceObject interface
   LOCAL psi                 AS DWORD                             ' // IPersistStreamInit interface
   LOCAL pIPersistStreamInit AS IPersistStreamInit                ' // IPersistStreamInit interface
   LOCAL pIOleClientSite     AS IOleClientSite                    ' // IOleClientSite interfae
'#IF %DEF(%UNICODE)
'   LOCAL buffer              AS WSTRING                           ' // General purpose buffer
'#ELSE
   LOCAL buffer              AS STRING                            ' // General purpose buffer
'#ENDIF

   ' // Retrieve the pointer to the OC_DATA structure
   IF hWnd <> 0 AND wMsg <> %WM_CREATE THEN pData = GetWindowLong(hWnd, 0)

   SELECT CASE wMsg

      ' ==================================================================================
      CASE %WM_CREATE
      ' ==================================================================================
         OC_DP("--- WM_CREATE BEGIN ---")

         ' ===============================================================================
         ' // Allocates memory for the control's data
'         pData = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pData))
         pData = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(OC_DATA))
         ' // If it fails, abort the creation of the window
         IF pData = %NULL THEN
            FUNCTION = -1
            EXIT FUNCTION
         END IF
         ' // Stores the pointer in the cbWndExtra member of the window class
         SetWindowLong hwnd, 0, pdata
         ' // Stores the container's iid as a property
         SetProp hwnd, $OC_IID, pData
         ' ===============================================================================

         ' ===============================================================================
         ' // Pointer to the initialization parameters structure
         pCreateStruct = lParam
         ' // Stores the data
         @pData.m_hWnd    = hWnd
         @pData.m_hParent = @pCreateStruct.hWndParent
         @pData.m_hInst   = @pCreateStruct.hInstance
         ' // Retrieves the caption of the window (used to pass the ProgID and license key)
         IF @pCreateStruct.lpszName THEN buffer = @pCreateStruct.@lpszName
         idx = INSTR(buffer, ";")
         IF idx = 0 THEN
            strProgID = buffer
         ELSE
            strProgID = LEFT$(buffer, idx -1)
            buffer = TRIM$(MID$(buffer, idx + 1))
            IF LEFT$(UCASE$(buffer), 7) = "RTLKEY:" THEN strLicKey = TRIM$(MID$(buffer, 8))
         END IF
         OC_DP("ProgID = " & strProgID)
         OC_DP("LicKey = " & strLicKey)
         ' ===============================================================================

         ' ===============================================================================
         ' // Creates an instance of the object
         IF @pCreateStruct.lpCreateParams THEN
            IF INSTR(buffer, "Shell.Explorer") THEN
               ' // Ambient flags for WebBrowser control customization.
               IF @pCreateStruct.lpCreateParams THEN
                  @pData.m_AmbientDlControl = @pCreateStruct.lpCreateParams
               END IF
               hr = OC_CreateObject(strProgID, @pData.m_pthis)
               OC_DP("AmbientDlControl flags = " & FORMAT$(@pData.m_AmbientDlControl))
            ELSE
               OC_DP("CreateInstanceFromDll")
               pCreateParams = @pCreateStruct.lpCreateParams
               IF LEN(strLicKey) = 0 THEN strLicKey = @pCreateParams.szLicKey
               pDispatch = CreateInstanceFromDll(@pCreateParams.szLibName, @pCreateParams.clsid, _
                           @pCreateParams.riid, BYCOPY @pCreateParams.szLicKey)
               IF ISOBJECT(pDispatch) THEN
                  pDispatch.AddRef
                  @pData.m_pthis = OBJPTR(pDispatch)
                  pDispatch = NOTHING
               END IF
               OC_DP("Path = " & @pCreateParams.szLibName)
               OC_DP("clsid = " & GUIDTXT$(@pCreateParams.clsid))
               OC_DP("riid = " & GUIDTXT$(@pCreateParams.riid))
               OC_DP("LicKey = " & @pCreateParams.szLicKey)
            END IF
         ELSEIF LEN(strLicKey) = 0 THEN
            hr = OC_CreateObject(strProgID, @pData.m_pthis)
         ELSE
            OC_DP("CreateControlLic")
            pDispatch = CreateControlLic(strProgID, strLicKey)
            IF ISOBJECT(pDispatch) THEN
               pDispatch.AddRef
               @pData.m_pthis = OBJPTR(pDispatch)
               pDispatch = NOTHING
            END IF
         END IF
         ' // If it fails, abort the creation of the control
         IF @pData.m_pthis = %NULL THEN
            FUNCTION = -1
            EXIT FUNCTION
         END IF
         ' ===============================================================================

         ' ===============================================================================
         ' // Creates a default font
         hr = OleCreateFontDisp("Microsoft Sans Serif", 8, %FW_NORMAL, %ANSI_CHARSET, 0, 0, 0, BYVAL VARPTR(pIFontDisp))
         IF hr = %S_OK AND pIFontDisp <> %NULL THEN @pData.m_pIFontDisp = pIFontDisp
         OC_DP("Font: " & STR$(pIFontDisp))
         ' ===============================================================================

         ' ===============================================================================
         ' // Retrieves the IOleObject interface
         hr = IUnknown_QueryInterface(@pData.m_pthis, $IID_IOleObject, @pData.m_pIOleObject)
         ' If it doesn't exist, it's not a visual control
         IF hr <> %S_OK OR @pData.m_pIOleObject = %NULL THEN EXIT FUNCTION
         pIOleObject = Ptr2Obj(@pData.m_pIOleObject)
         IF ISNOTHING(pIOleObject) THEN EXIT FUNCTION
         ' ===============================================================================

         ' ===============================================================================
         ' // Creates an instance of our implemented IOleClientSite interface
         @pData.m_pIOleClientSite = NEW_OC_IOleClientSiteVtable(pData)
         IF @pData.m_pIOleClientSite = %NULL THEN EXIT FUNCTION
         ' ===============================================================================

         ' ===============================================================================
         ' // Gets the status bitwise flags
         hr = pIOleObject.GetMiscStatus(%DVASPECT_CONTENT, @pData.m_dwMiscStatus)
         OC_DP("IOleObject.GetMiscStatus: hr = " & HEX$(hr) & " - status: &H" & HEX$(@pData.m_dwMiscStatus))
         ' // The control needs to be put on running state
'         IF (@pData.m_dwMiscStatus AND %OLEMISC_ALWAYSRUN) = %OLEMISC_ALWAYSRUN THEN
         IF (@pData.m_dwMiscStatus AND &H800???) = &H800??? THEN
            hr = OC_OleRun(@pData.m_pthis)
            OC_DP("OleRun: " & HEX$(hr))
         END IF
'         IF (@pData.m_dwMiscStatus AND %OLEMISC_SIMPLEFRAME) = %OLEMISC_SIMPLEFRAME THEN
         IF (@pData.m_dwMiscStatus AND &H10000???) = &H10000??? THEN
         OC_DP("--- Simple frame ---")
         END IF
         ' // The control wants that you set the client site first
'         IF (@pData.m_dwMiscStatus AND %OLEMISC_SETCLIENTSITEFIRST) = %OLEMISC_SETCLIENTSITEFIRST THEN
         IF (@pData.m_dwMiscStatus AND &H20000???) = &H20000??? THEN
            ' // Sets the client site
            OC_DP("--- SetClientSite - Begin ---")
            IF @pData.m_pIOleClientSite THEN
               pIOleClientSite = Ptr2Obj(@pData.m_pIOleClientSite)
               IF ISOBJECT(pIOleClientSite) THEN
                  hr = pIOleObject.SetClientSite(pIOleClientSite)
                  pIOleClientSite = NOTHING
                  OC_DP("--- SetClientSite - End --- " & HEX$(hr))
               END IF
            END IF
         END IF
         ' // Sets the host name
         wszContainerApp = $OC_CLASSNAME
         wszContainerObj = ""
         hr = pIOleObject.SetHostNames(wszContainerApp, wszContainerObj)
         OC_DP("SetHostNames: " & HEX$(hr))
         ' // Initializes the object to a default state
         hr = IUnknown_QueryInterface(@pData.m_pthis, $IID_IPersistStreamInit, psi)
         IF hr = %S_OK AND psi <> %NULL THEN
            pIPersistStreamInit = Ptr2Obj(psi)
            IF ISOBJECT(pIPersistStreamInit) THEN
               hr = pIPersistStreamInit.InitNew
               OC_DP("IPersistStreamInit.InitNew - hr: " & HEX$(hr))
               pIPersistStreamInit = NOTHING
            END IF
            IUnknown_Release psi
         END IF
         ' // Sets the client site if it has not been done previously
'         IF (@pData.m_dwMiscStatus AND %OLEMISC_SETCLIENTSITEFIRST) <> %OLEMISC_SETCLIENTSITEFIRST THEN
         IF (@pData.m_dwMiscStatus AND &H20000???) <> &H20000??? THEN
            ' // Sets the client site
            OC_DP("--- SetClientSite - Begin ---")
            IF @pData.m_pIOleClientSite THEN
               pIOleClientSite = Ptr2Obj(@pData.m_pIOleClientSite)
               IF ISOBJECT(pIOleClientSite) THEN
                  hr = pIOleObject.SetClientSite(pIOleClientSite)
                  pIOleClientSite = NOTHING
                  OC_DP("--- SetClientSite - End --- " & HEX$(hr))
               END IF
            END IF
            OC_DP("--- SetClientSite - End --- " & HEX$(hr))
         END IF
         ' ===============================================================================

         ' ===============================================================================
         ' // Gets the size of the container's window
         GetClientRect @pData.m_hWnd, rc
         ' // Converts from pixel to himetric
         pxSize.cx = rc.nRight - rc.nLeft
         pxSize.cy = rc.nBottom - rc.nTop
         OC_PixelsToHiMetric(pxSize, hmSize)
         ' // Sets extent of the object's display area
         hr = pIOleObject.SetExtent(%DVASPECT_CONTENT, hmSize)
         OC_DP("--- DoVerb - INPLACEACTIVATE - Begin ---")
         ' // Activates the control in place
         IF @pData.m_pIOleClientSite THEN
            pIOleClientSite = Ptr2Obj(@pData.m_pIOleClientSite)
            IF ISOBJECT(pIOleClientSite) THEN
'               hr = pIOleObject.DoVerb(%OLEIVERB_INPLACEACTIVATE, BYVAL %NULL, pIOleClientSite, 0, @pData.m_hWnd, rc)
               hr = pIOleObject.DoVerb(-5&, BYVAL %NULL, pIOleClientSite, 0, @pData.m_hWnd, rc)
               pIOleClientSite = NOTHING
               OC_DP("--- DoVerb - INPLACEACTIVATE - End --- " & HEX$(hr))
            END IF
         END IF
         ' ===============================================================================

         ' // Release the interafce
         pIOleObject = NOTHING

         #IF %DEF(%PB_WIN32)
         MOUSEPTR 1   ' // Arrow cursor
         #ENDIF

         OC_DP("--- WM_CREATE END ---")

         EXIT FUNCTION

      ' ==================================================================================
      CASE %WM_DESTROY
      ' ==================================================================================
         OC_DP("--- WM_DESTROY BEGIN ---")
         IF pData = %NULL THEN EXIT FUNCTION
         ' // Disconnects events if needed
         IF @pData.m_pUnkSink <> %NULL OR @pData.m_pEvtObj <> %NULL THEN OC_Unadvise(hWnd)
         ' // Removes the IID property
         hr = RemoveProp(hWnd, BYCOPY $OC_IID)
         OC_DP("RemoveProp = " & STR$(hr) & " - " & STR$(pData))
         ' // Required: Deactivate the IOleInPlaceObject if it active.
         ' // It forces the release of the IOleInPlaceSite interface.
         IF @pData.m_bInPlaceActive THEN
            IF @pData.m_pIOleInPlaceObject THEN
               pIOleInPlaceObject = Ptr2Obj(@pData.m_pIOleInPlaceObject)
               IF ISOBJECT(pIOleInPlaceObject) THEN
                  hr = pIOleInPlaceObject.InPlaceDeactivate
                  OC_DP("IOleInPlaceObject.InPlaceDeactivate - hr = " & STR$(hr))
                  pIOleInPlaceObject = NOTHING
               END IF
            END IF
         END IF
         ' // Closes the control
         IF @pData.m_pIOleObject THEN
            pIOleObject = Ptr2Obj(@pData.m_pIOleObject)
            IF ISOBJECT(pIOleObject) THEN
'               hr = pIOleObject.Close(%OLECLOSE_NOSAVE)
               hr = pIOleObject.Close(1)
               OC_DP("IOleObject.Close - hr = " & STR$(hr))
               hr = pIOleObject.SetClientSite(NOTHING)
               OC_DP("IOleObject.SetClientSite - hr = " & STR$(hr))
               pIOleObject = NOTHING
            END IF
         END IF
         ' // Releases the IFont object
         IF @pData.m_pIFontDisp THEN
            hr = IUnknown_Release(@pData.m_pIFontDisp)
            OC_DP("IFont release - cRef = " & STR$(hr))
            @pData.m_pIFontDisp = %NULL
         END IF
         ' // Releases the IOleInPlaceSite interface
         IF @pData.m_pIOleInPlaceSite THEN
            hr = IUnknown_Release(@pData.m_pIOleInPlaceSite)
            OC_DP("IOleInPlaceSite release: - cRef = " & STR$(hr))
            @pData.m_pIOleInPlaceSite = %NULL
         END IF
         ' // Releases the IOleInPlaceObject interface
         IF @pData.m_pIOleInPlaceObject THEN
            hr = IUnknown_Release(@pData.m_pIOleInPlaceObject)
            OC_DP("IOleInPlaceObject release: - cRef = " & STR$(hr))
            @pData.m_pIOleInPlaceObject = %NULL
         END IF
         ' // Releases the IOleObject interface
         ' // The returned reference count must be at least 1 because the
         ' // ActiveX control holds a reference to it.
         IF @pData.m_pIOleObject THEN
            hr = IUnknown_Release(@pData.m_pIOleObject)
            @pData.m_pIOleObject = %NULL
            OC_DP("IOleObject release: - cRef = " & STR$(hr))
         END IF
         ' // Releases the instance of the ActiveX
         IF @pData.m_pthis THEN
            hr = IUnknown_Release(@pData.m_pthis)
            OC_DP("pthis release: - cRef: " & STR$(hr))
         END IF

         ' // Checks for memory leaks (if a pointer <> 0 then memory leak)
         OC_DP("*** IUnknown = " & STR$(@pData.m_pIUnknown))
         OC_DP("*** IDispatch = " & STR$(@pData.m_pIDispatch))
         OC_DP("*** IOleClientSite = " & STR$(@pData.m_pIOleClientSite))
         OC_DP("*** IOleContainer = " & STR$(@pData.m_pIOleContainer))
         OC_DP("*** IOleControlSite = " & STR$(@pData.m_pIOleControlSite))
         OC_DP("*** IOleInPlaceActiveObject = " & STR$(@pData.m_pIOleInPlaceActiveObject))
         OC_DP("*** IOleInPlaceFrame = " & STR$(@pData.m_pIOleInPlaceFrame))
         OC_DP("*** IOleInPlaceObject = " & STR$(@pData.m_pIOleInPlaceObject))
         OC_DP("*** IOleInPlaceSite = " & STR$(@pData.m_pIOleInPlaceSite))
         OC_DP("*** IOleInPlaceSiteEx = " & STR$(@pData.m_pIOleInPlaceSiteEx))
         OC_DP("*** IOleInPlaceUIWindow = " & STR$(@pData.m_pIOleInPlaceUIWindow))
         OC_DP("*** IOleObject = " & STR$(@pData.m_pIOleObject))
         OC_DP("*** IOleWindow = " & STR$(@pData.m_pIOleWindow))
         OC_DP("*** IParseDisplayName = " & STR$(@pData.m_pIParseDisplayName))
         OC_DP("*** IServiceProvider = " & STR$(@pData.m_pIServiceProvider))
         OC_DP("*** ISimpleFrameSite = " & STR$(@pData.m_pISimpleFrameSite))

         ' // WORKAROUND: The DHTML Edit Control doesn't release this interface
         IF @pData.m_pIOleControlSite THEN
            IUnknown_Release @pData.m_pIOleControlSite
         END IF

         ' // Frees the memory used by our container control
         HeapFree(GetProcessHeap(), 0, BYVAL pData)
         OC_DP("--- WM_DESTROY END ---")

         EXIT FUNCTION

      ' ==================================================================================
      ' Resizes the control to fill the client area of the host window
      ' ==================================================================================
      CASE %WM_SIZE
      ' ==================================================================================
         OC_DP("--- WM_SIZE BEGIN ---")

         IF @pData.m_bInPlaceActive THEN
            ' // Retrieves the coordinates of a window's client area.
            GetClientRect hWnd, rc
            ' // Converts from pixel to himetric
            pxSize.cx = rc.nRight - rc.nLeft
            pxSize.cy = rc.nBottom - rc.nTop
            OC_PixelsToHiMetric(pxSize, hmSize)
            ' // Sets extent of object's display area
            IF @pData.m_pIOleObject THEN
               pIOleObject = Ptr2Obj(@pData.m_pIOleObject)
               IF ISOBJECT(pIOleObject) THEN
                  hr = pIOleObject.SetExtent(%DVASPECT_CONTENT, hmSize)
                  pIOleObject = NOTHING
               END IF
            END IF
            ' // Indicates how much of the in-place object is visible.
            IF @pData.m_pIOleInPlaceObject = %NULL THEN
               IUnknown_QueryInterface(@pData.m_pthis, $IID_IOleInPlaceObject, @pData.m_pIOleInPlaceObject)
            END IF
            IF @pData.m_pIOleInPlaceObject THEN
               pIOleInPlaceObject = Ptr2Obj(@pData.m_pIOleInPlaceObject)
               IF ISOBJECT(pIOleInPlaceObject) THEN
                  pIOleInPlaceObject.SetObjectRects(rc, rc)
                  pIOleInPlaceObject = NOTHING
               END IF
            END IF
         END IF
         OC_DP("--- WM_SIZE_END ---")

         EXIT FUNCTION

      ' ==================================================================================
      CASE %WM_ENABLE
      ' ==================================================================================
         OC_DP("--- WM_ENABLE BEGIN ---")
         InvalidateRect hWnd, BYVAL %NULL, 0
         UpdateWindow hWnd
         OC_DP("--- WM_ENABLE END ---")
         EXIT FUNCTION

      ' ==================================================================================
      CASE %WM_KILLFOCUS
      ' ==================================================================================
         OC_DP("--- WM_KILLFOCUS BEGIN ---")
         @pData.m_bHaveFocus = %FALSE
         OC_DP("--- WM_KILLFOCUS END ---")
         EXIT FUNCTION

      ' ==================================================================================
      CASE %WM_SETFOCUS
      ' ==================================================================================
         OC_DP("--- WM_SETFOCUS BEGIN ---")
         @pData.m_bHaveFocus = %TRUE
         ' // Activates an object in place, along with its full set of user-interface tools.
         IF @pData.m_pIOleObject <> %NULL AND @pData.m_bInPlaceActive = %FALSE THEN
            GetClientRect hWnd, rc
            IF @pData.m_pIOleObject THEN
               pIOleObject = Ptr2Obj(@pData.m_pIOleObject)
               IF ISOBJECT(pIOleObject) THEN
                  IF @pData.m_pIOleClientSite THEN
                     pIOleClientSite = Ptr2Obj(@pData.m_pIOleClientSite)
                     IF ISOBJECT(pIOleClientSite) THEN
'                        hr = pIOleObject.DoVerb(%OLEIVERB_UIACTIVATE, BYVAL %NULL, pIOleClientSite, 0, hWnd, rc)
                        hr = pIOleObject.DoVerb(-4&, BYVAL %NULL, pIOleClientSite, 0, hWnd, rc)
                        OC_DP("--- WM_SETFOCUS - DoVerb OLEIVERB_UIACTIVATE")
                        pIOleClientSite = NOTHING
                     END IF
                  END IF
                  pIOleObject = NOTHING
               END IF
            END IF
         END IF
         IF @pData.m_pIOleInPlaceObject = %NULL THEN
            IUnknown_QueryInterface(@pData.m_pthis, $IID_IOleInPlaceObject, @pData.m_pIOleInPlaceObject)
         END IF
         IF @pData.m_pIOleInPlaceObject THEN
            pIOleInPlaceObject = Ptr2Obj(@pData.m_pIOleInPlaceObject)
            IF ISOBJECT(pIOleInPlaceObject) THEN
               hr = pIOleInPlaceObject.GetWindow(hWndCtrl)
               IF IsWindow(hWndCtrl) THEN SetFocus hWndCtrl
               OC_DP("--- WM_SETFOCUS - hWndCtrl = " & STR$(hWndCtrl))
               pIOleInPlaceObject = NOTHING
            END IF
         END IF

         OC_DP("--- WM_SETFOCUS END ---")
         EXIT FUNCTION

      ' ==================================================================================
      CASE %WM_ERASEBKGND
      ' ==================================================================================
         ' // Don't erase the background to avoid flicker
         FUNCTION = 1
         EXIT FUNCTION

   END SELECT

   ' // Default processing for other messages
   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
