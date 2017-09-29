' ########################################################################################
' Microsoft Windows
' File: iextag.inc
' Library name: IEXTagLib
' Version: 1.0, Locale ID = 0
' Library GUID: {7E8BC440-AEFF-11D1-89C2-00C04FB6BFC4}
' Path: C:\WINDOWS\system32\iepeers.dll
' Contents: iextag 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IEXTAG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_IEXTagLib = GUID$("{7E8BC440-AEFF-11D1-89C2-00C04FB6BFC4}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {3050F6D4-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CDeviceRect1 = "DeviceRect.DeviceRect.1"
' CLSID = {3050F5BE-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CDownloadBehavior1 = "DownloadBehavior.DownloadBehavior.1"
' CLSID = {766BF2AE-D650-11D1-9811-00C04FC31D2E}
$PROGID_HomePage1 = "HomePage.HomePage.1"
' CLSID = {3050F664-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CLayoutRect1 = "LayoutRect.LayoutRect.1"
' CLSID = {3050F4CF-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_PeerFactory1 = "PeerFactory.PeerFactory.1"
' CLSID = {3050F6B3-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CTemplatePrinter1 = "TemplatePrinter.TemplatePrinter.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {3050F6D4-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CDeviceRect = "DeviceRect.DeviceRect"
' CLSID = {3050F5BE-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CDownloadBehavior = "DownloadBehavior.DownloadBehavior"
' CLSID = {766BF2AE-D650-11D1-9811-00C04FC31D2E}
$PROGID_HomePage = "HomePage.HomePage"
' CLSID = {3050F664-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CLayoutRect = "LayoutRect.LayoutRect"
' CLSID = {3050F4CF-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_PeerFactory = "PeerFactory.PeerFactory"
' CLSID = {3050F6B3-98B5-11CF-BB82-00AA00BDCE0B}
$PROGID_CTemplatePrinter = "TemplatePrinter.TemplatePrinter"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AnchorClick = GUID$("{13D5413C-33B9-11D2-95A7-00C04F8ECB02}")
$CLSID_CPersistDataPeer = GUID$("{3050F487-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CPersistHistory = GUID$("{3050F4C8-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CPersistShortcut = GUID$("{3050F4C6-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CPersistSnapshot = GUID$("{3050F4C9-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CPersistUserData = GUID$("{3050F48E-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_HomePage = GUID$("{766BF2AE-D650-11D1-9811-00C04FC31D2E}")
$CLSID_IntelliForms = GUID$("{613AB92E-16BF-11D2-BCA5-00C04FD929DB}")
$CLSID_wfolders = GUID$("{BAE31F9A-1B81-11D2-A97A-00C04F8ECB02}")
$CLSID_CDeviceRect = GUID$("{3050F6D4-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CDownloadBehavior = GUID$("{3050F5BE-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CHeaderFooter = GUID$("{3050F6CD-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_ClientCaps = GUID$("{7E8BC44E-AEFF-11D1-89C2-00C04FB6BFC4}")
$CLSID_CLayoutRect = GUID$("{3050F664-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_PeerFactory = GUID$("{3050F4CF-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CTemplatePrinter = GUID$("{3050F6B3-98B5-11CF-BB82-00AA00BDCE0B}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_HTMLPersistEvents = GUID$("{3050F4C7-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IAnchorClick = GUID$("{13D5413B-33B9-11D2-95A7-00C04F8ECB02}")
$IID_IClientCaps = GUID$("{7E8BC44D-AEFF-11D1-89C2-00C04FB6BFC4}")
$IID_IDeviceRect = GUID$("{3050F6D5-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IDownloadBehavior = GUID$("{3050F5BD-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IHeaderFooter = GUID$("{3050F6CE-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IHeaderFooter2 = GUID$("{305104A5-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IHomePage = GUID$("{766BF2AF-D650-11D1-9811-00C04FC31D2E}")
$IID_IHTMLPersistData = GUID$("{3050F4C5-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IHTMLPersistDataOM = GUID$("{3050F4C0-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IHTMLUserDataOM = GUID$("{3050F48F-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IIntelliForms = GUID$("{9B9F68E6-1AAA-11D2-BCA5-00C04FD929DB}")
$IID_ILayoutRect = GUID$("{3050F665-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IPeerFactory = GUID$("{6663F9D3-B482-11D1-89C6-00C04FB6BFC4}")
$IID_ITemplatePrinter = GUID$("{3050F6B4-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_ITemplatePrinter2 = GUID$("{3050F83F-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_ITemplatePrinter3 = GUID$("{305104A3-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_Iwfolders = GUID$("{BAE31F98-1B81-11D2-A97A-00C04F8ECB02}")
$IID_LayoutRectEvents = GUID$("{3050F674-98B5-11CF-BB82-00AA00BDCE0B}")

' ########################################################################################
' Interface name = IPeerFactory
' IID = {6663F9D3-B482-11D1-89C6-00C04FB6BFC4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPeerFactory_INTERFACE_DEFINED)
    %IPeerFactory_INTERFACE_DEFINED = 1

INTERFACE IPeerFactory $IID_IPeerFactory

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IPeerFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHomePage
' IID = {766BF2AF-D650-11D1-9811-00C04FC31D2E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHomePage_INTERFACE_DEFINED)
   %IHomePage_INTERFACE_DEFINED = 1

INTERFACE IHomePage $IID_IHomePage

   INHERIT IDispatch

   ' =====================================================================================
   METHOD navigateHomePage <1> ( _                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD setHomePage <2> ( _                           ' VTable offset = 32
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   METHOD isHomePage <3> ( _                            ' VTable offset = 36
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHomePage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IClientCaps
' IID = {7E8BC44D-AEFF-11D1-89C2-00C04FB6BFC4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IClientCaps_INTERFACE_DEFINED)
   %IClientCaps_INTERFACE_DEFINED = 1

INTERFACE IClientCaps $IID_IClientCaps

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET javaEnabled <1> ( _                     ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET cookieEnabled <2> ( _                   ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET cpuClass <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY GET systemLanguage <4> ( _                  ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY GET userLanguage <6> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY GET platform <7> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY GET connectionSpeed <9> ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET onLine <10> ( _                         ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY GET colorDepth <11> ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET bufferDepth <12> ( _                    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET width <13> ( _                          ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET height <14> ( _                         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET availHeight <15> ( _                    ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET availWidth <16> ( _                     ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET connectionType <17> ( _                 ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   METHOD isComponentInstalled <18> ( _                 ' VTable offset = 88
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   , OPTIONAL BYVAL bStrVer AS WSTRING _                ' __in_opt BSTR bStrVer
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD getComponentVersion <19> ( _                  ' VTable offset = 92
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVer
   ' =====================================================================================
   METHOD compareVersions <20> ( _                      ' VTable offset = 96
     BYVAL bstrVer1 AS WSTRING _                        ' __in BSTR bstrVer1
   , BYVAL bstrVer2 AS WSTRING _                        ' __in BSTR bstrVer2
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   METHOD addComponentRequest <21> ( _                  ' VTable offset = 100
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   , OPTIONAL BYVAL bstrVer AS WSTRING _                ' __in_opt BSTR bstrVer = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD doComponentRequest <22> ( _                   ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD clearComponentRequest <23> ( _                ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClientCaps_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIntelliForms
' IID = {9B9F68E6-1AAA-11D2-BCA5-00C04FD929DB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IIntelliForms_INTERFACE_DEFINED)
   %IIntelliForms_INTERFACE_DEFINED = 1

INTERFACE IIntelliForms $IID_IIntelliForms

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET enabled <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET enabled <1> ( _                         ' VTable offset = 32
     BYVAL bVal AS INTEGER _                            ' __in VARIANT_BOOL bVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIntelliForms_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Iwfolders
' IID = {BAE31F98-1B81-11D2-A97A-00C04F8ECB02}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%Iwfolders_INTERFACE_DEFINED)
   %Iwfolders_INTERFACE_DEFINED = 1

INTERFACE Iwfolders $IID_Iwfolders

   INHERIT IDispatch

   ' =====================================================================================
   METHOD navigate <1> ( _                              ' VTable offset = 28
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRetVal
   ' =====================================================================================
   METHOD navigateFrame <2> ( _                         ' VTable offset = 32
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   , BYVAL bstrTargetFrame AS WSTRING _                 ' __in BSTR bstrTargetFrame
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRetVal
   ' =====================================================================================
   METHOD navigateNoSite <3> ( _                        ' VTable offset = 36
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   , BYVAL bstrTargetFrame AS WSTRING _                 ' __in BSTR bstrTargetFrame
   , BYVAL dwhwnd AS DWORD _                            ' __in DWORD dwhwnd
   , BYVAL pwb AS IUnknown _                            ' __in IUnknown *pwb
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Iwfolders_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnchorClick
' IID = {13D5413B-33B9-11D2-95A7-00C04F8ECB02}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAnchorClick_INTERFACE_DEFINED)
   %IAnchorClick_INTERFACE_DEFINED = 1

INTERFACE IAnchorClick $IID_IAnchorClick

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ProcOnClick <1> ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnchorClick_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHTMLUserDataOM
' IID = {3050F48F-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHTMLUserDataOM_INTERFACE_DEFINED)
   %IHTMLUserDataOM_INTERFACE_DEFINED = 1

INTERFACE IHTMLUserDataOM $IID_IHTMLUserDataOM

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET XMLDocument <1> ( _                     ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **p
   ' =====================================================================================
   METHOD save <2> ( _                                  ' VTable offset = 32
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   )                                                    ' void
   ' =====================================================================================
   METHOD load <3> ( _                                  ' VTable offset = 36
     BYVAL strName AS WSTRING _                         '  __in BSTR strName
   )                                                    ' void
   ' =====================================================================================
   METHOD getAttribute <4> ( _                          ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD setAttribute <5> ( _                          ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in BSTR name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   METHOD removeAttribute <6> ( _                       ' VTable offset = 48
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET expires <7> ( _                         ' VTable offset = 52
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET expires <7> ( _                         ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHTMLUserDataOM_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHTMLPersistDataOM
' IID = {3050F4C0-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHTMLPersistDataOM_INTERFACE_DEFINED)
   %IHTMLPersistDataOM_INTERFACE_DEFINED = 1

INTERFACE IHTMLPersistDataOM $IID_IHTMLPersistDataOM

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET XMLDocument <3> ( _                     ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **p
   ' =====================================================================================
   METHOD getAttribute <4> ( _                          ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD setAttribute <5> ( _                          ' VTable offset = 36
     BYVAL name AS WSTRING _                            ' __in BSTR name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   METHOD removeAttribute <6> ( _                       ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHTMLPersistDataOM_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHTMLPersistData
' IID = {3050F4C5-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 64 [&H40] [Dual]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHTMLPersistData_INTERFACE_DEFINED)
   %IHTMLPersistData_INTERFACE_DEFINED = 1

INTERFACE IHTMLPersistData $IID_IHTMLPersistData

   INHERIT IDispatch

   ' =====================================================================================
   METHOD save <1> ( _                                  ' VTable offset = 12
     BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   , BYVAL lType AS LONG _                              ' __in long lType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fContinueBroacast
   ' =====================================================================================
   METHOD load <2> ( _                                  ' VTable offset = 16
     BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   , BYVAL lType AS LONG _                              ' __in long lType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fDoDefault
   ' =====================================================================================
   METHOD queryType <3> ( _                             ' VTable offset = 20
     BYVAL lType AS LONG _                              ' __in long lType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfSupportsType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHTMLPersistData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDownloadBehavior
' IID = {3050F5BD-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDownloadBehavior_INTERFACE_DEFINED)
   %IDownloadBehavior_INTERFACE_DEFINED = 1

INTERFACE IDownloadBehavior $IID_IDownloadBehavior

   INHERIT IDispatch

   ' =====================================================================================
   METHOD startDownload <1> ( _                         ' VTable offset = 28
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   , BYVAL pdispCallback AS IDispatch _                 ' __in IDispatch *pdispCallback
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDownloadBehavior_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILayoutRect
' IID = {3050F665-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILayoutRect_INTERFACE_DEFINED)
   %ILayoutRect_INTERFACE_DEFINED = 1

INTERFACE ILayoutRect $IID_ILayoutRect

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET nextRect <1> ( _                        ' VTable offset = 28
     BYVAL bstrElementId AS WSTRING _                   ' __in BSTR bstrElementId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nextRect <1> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrElementId
   ' =====================================================================================
   PROPERTY SET contentSrc <2> ( _                      ' VTable offset = 36
     BYVAL varContentSrc AS VARIANT _                   ' __in VARIANT varContentSrc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET contentSrc <2> ( _                      ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarContentSrc
   ' =====================================================================================
   PROPERTY SET honorPageBreaks <3> ( _                 ' VTable offset = 44
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET honorPageBreaks <3> ( _                 ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET honorPageRules <4> ( _                  ' VTable offset = 52
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET honorPageRules <4> ( _                  ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET nextRectElement <5> ( _                 ' VTable offset = 60
     BYVAL pElem AS IDispatch _                         ' __in IDispatch *pElem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET nextRectElement <5> ( _                 ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppElem
   ' =====================================================================================
   PROPERTY GET contentDocument <6> ( _                 ' VTable offset = 68
   ) AS IDispatch                                       ' __retval_out IDispatch **pDoc
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILayoutRect_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceRect
' IID = {3050F6D5-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDeviceRect_INTERFACE_DEFINED)
   %IDeviceRect_INTERFACE_DEFINED = 1

INTERFACE IDeviceRect $IID_IDeviceRect

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IDeviceRect_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITemplatePrinter
' IID = {3050F6B4-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITemplatePrinter_INTERFACE_DEFINED)
   %ITemplatePrinter_INTERFACE_DEFINED = 1

INTERFACE ITemplatePrinter $IID_ITemplatePrinter

   INHERIT IDispatch

   ' =====================================================================================
   METHOD startDoc <1> ( _                              ' VTable offset = 28
     BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD stopDoc <2> ( _                               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD printBlankPage <3> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD printPage <4> ( _                             ' VTable offset = 40
     BYVAL pElemDisp AS IDispatch _                     ' __in IDispatch *pElemDisp
   )                                                    ' void
   ' =====================================================================================
   METHOD ensurePrintDialogDefaults <5> ( _             ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD showPrintDialog <6> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD showPageSetupDialog <7> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD printNonNative <8> ( _                        ' VTable offset = 56
     BYVAL pMarkup AS IUnknown _                        ' __in IUnknown *pMarkup
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD printNonNativeFrames <9> ( _                  ' VTable offset = 60
     BYVAL pMarkup AS IUnknown _                        ' __in IUnknown *pMarkup
   , BYVAL fActiveFrame AS INTEGER _                    ' __in VARIANT_BOOL fActiveFrame
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET framesetDocument <10> ( _               ' VTable offset = 64
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET framesetDocument <10> ( _               ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameActive <11> ( _                    ' VTable offset = 72
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameActive <11> ( _                    ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameAsShown <12> ( _                   ' VTable offset = 80
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameAsShown <12> ( _                   ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET selection <13> ( _                      ' VTable offset = 88
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selection <13> ( _                      ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET selectedPages <14> ( _                  ' VTable offset = 96
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selectedPages <14> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET currentPage <15> ( _                    ' VTable offset = 104
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPage <15> ( _                    ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET currentPageAvail <16> ( _               ' VTable offset = 112
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPageAvail <16> ( _               ' VTable offset = 116
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY SET collate <17> ( _                        ' VTable offset = 120
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET collate <17> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY GET duplex <18> ( _                         ' VTable offset = 128
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY SET copies <19> ( _                         ' VTable offset = 132
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET copies <19> ( _                         ' VTable offset = 136
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET pageFrom <20> ( _                       ' VTable offset = 140
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageFrom <20> ( _                       ' VTable offset = 144
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET pageTo <21> ( _                         ' VTable offset = 148
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageTo <21> ( _                         ' VTable offset = 152
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET tableOfLinks <22> ( _                   ' VTable offset = 156
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET tableOfLinks <22> ( _                   ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET allLinkedDocuments <23> ( _             ' VTable offset = 164
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET allLinkedDocuments <23> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET header <24> ( _                         ' VTable offset = 172
     BYVAL bstrHeader AS WSTRING _                      ' __in BSTR bstrHeader
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET header <24> ( _                         ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *bstrHeader
   ' =====================================================================================
   PROPERTY SET footer <25> ( _                         ' VTable offset = 180
     BYVAL bstrFooter AS WSTRING _                      ' __in BSTR bstrFooter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET footer <25> ( _                         ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *bstrFooter
   ' =====================================================================================
   PROPERTY SET marginLeft <26> ( _                     ' VTable offset = 188
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginLeft <26> ( _                     ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginRight <27> ( _                    ' VTable offset = 196
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginRight <27> ( _                    ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginTop <28> ( _                      ' VTable offset = 204
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginTop <28> ( _                      ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginBottom <29> ( _                   ' VTable offset = 212
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginBottom <29> ( _                   ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET pageWidth <30> ( _                      ' VTable offset = 220
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET pageHeight <31> ( _                     ' VTable offset = 224
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableLeft <32> ( _                ' VTable offset = 228
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableTop <33> ( _                 ' VTable offset = 232
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableRight <34> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableBottom <35> ( _              ' VTable offset = 240
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   METHOD updatePageStatus <36> ( _                     ' VTable offset = 244
     BYREF p AS LONG _                                  ' __in long *p
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITemplatePrinter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITemplatePrinter2
' IID = {3050F83F-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITemplatePrinter
' ########################################################################################

#IF NOT %DEF(%ITemplatePrinter2_INTERFACE_DEFINED)
   %ITemplatePrinter2_INTERFACE_DEFINED = 1

INTERFACE ITemplatePrinter2 $IID_ITemplatePrinter2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITemplatePrinter Methods
   ' =====================================================================================
   METHOD startDoc <1> ( _                              ' VTable offset = 28
     BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD stopDoc <2> ( _                               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD printBlankPage <3> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD printPage <4> ( _                             ' VTable offset = 40
     BYVAL pElemDisp AS IDispatch _                     ' __in IDispatch *pElemDisp
   )                                                    ' void
   ' =====================================================================================
   METHOD ensurePrintDialogDefaults <5> ( _             ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD showPrintDialog <6> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD showPageSetupDialog <7> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD printNonNative <8> ( _                        ' VTable offset = 56
     BYVAL pMarkup AS IUnknown _                        ' __in IUnknown *pMarkup
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD printNonNativeFrames <9> ( _                  ' VTable offset = 60
     BYVAL pMarkup AS IUnknown _                        ' __in IUnknown *pMarkup
   , BYVAL fActiveFrame AS INTEGER _                    ' __in VARIANT_BOOL fActiveFrame
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET framesetDocument <10> ( _               ' VTable offset = 64
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET framesetDocument <10> ( _               ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameActive <11> ( _                    ' VTable offset = 72
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameActive <11> ( _                    ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameAsShown <12> ( _                   ' VTable offset = 80
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameAsShown <12> ( _                   ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET selection <13> ( _                      ' VTable offset = 88
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selection <13> ( _                      ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET selectedPages <14> ( _                  ' VTable offset = 96
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selectedPages <14> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET currentPage <15> ( _                    ' VTable offset = 104
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPage <15> ( _                    ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET currentPageAvail <16> ( _               ' VTable offset = 112
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPageAvail <16> ( _               ' VTable offset = 116
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY SET collate <17> ( _                        ' VTable offset = 120
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET collate <17> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY GET duplex <18> ( _                         ' VTable offset = 128
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY SET copies <19> ( _                         ' VTable offset = 132
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET copies <19> ( _                         ' VTable offset = 136
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET pageFrom <20> ( _                       ' VTable offset = 140
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageFrom <20> ( _                       ' VTable offset = 144
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET pageTo <21> ( _                         ' VTable offset = 148
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageTo <21> ( _                         ' VTable offset = 152
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET tableOfLinks <22> ( _                   ' VTable offset = 156
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET tableOfLinks <22> ( _                   ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET allLinkedDocuments <23> ( _             ' VTable offset = 164
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET allLinkedDocuments <23> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET header <24> ( _                         ' VTable offset = 172
     BYVAL bstrHeader AS WSTRING _                      ' __in BSTR bstrHeader
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET header <24> ( _                         ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *bstrHeader
   ' =====================================================================================
   PROPERTY SET footer <25> ( _                         ' VTable offset = 180
     BYVAL bstrFooter AS WSTRING _                      ' __in BSTR bstrFooter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET footer <25> ( _                         ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *bstrFooter
   ' =====================================================================================
   PROPERTY SET marginLeft <26> ( _                     ' VTable offset = 188
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginLeft <26> ( _                     ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginRight <27> ( _                    ' VTable offset = 196
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginRight <27> ( _                    ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginTop <28> ( _                      ' VTable offset = 204
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginTop <28> ( _                      ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginBottom <29> ( _                   ' VTable offset = 212
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginBottom <29> ( _                   ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET pageWidth <30> ( _                      ' VTable offset = 220
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET pageHeight <31> ( _                     ' VTable offset = 224
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableLeft <32> ( _                ' VTable offset = 228
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableTop <33> ( _                 ' VTable offset = 232
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableRight <34> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableBottom <35> ( _              ' VTable offset = 240
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   METHOD updatePageStatus <36> ( _                     ' VTable offset = 244
     BYREF p AS LONG _                                  ' __in long *p
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITemplatePrinter2 Methods
   ' =====================================================================================
   PROPERTY SET selectionEnabled <37> ( _               ' VTable offset = 248
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selectionEnabled <37> ( _               ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameActiveEnabled <38> ( _             ' VTable offset = 256
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameActiveEnabled <38> ( _             ' VTable offset = 260
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET orientation <39> ( _                    ' VTable offset = 264
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET orientation <39> ( _                    ' VTable offset = 268
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET usePrinterCopyCollate <40> ( _          ' VTable offset = 272
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET usePrinterCopyCollate <40> ( _          ' VTable offset = 276
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   METHOD deviceSupports <41> ( _                       ' VTable offset = 280
     BYVAL bstrProperty AS WSTRING _                    ' __in BSTR bstrProperty
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITemplatePrinter2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITemplatePrinter3
' IID = {305104A3-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITemplatePrinter2
' ########################################################################################

#IF NOT %DEF(%ITemplatePrinter3_INTERFACE_DEFINED)
   %ITemplatePrinter3_INTERFACE_DEFINED = 1

INTERFACE ITemplatePrinter3 $IID_ITemplatePrinter3

   INHERIT IDispatch

   ' =====================================================================================
   ' ITemplatePrinter Methods
   ' =====================================================================================
   METHOD startDoc <1> ( _                              ' VTable offset = 28
     BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD stopDoc <2> ( _                               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD printBlankPage <3> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD printPage <4> ( _                             ' VTable offset = 40
     BYVAL pElemDisp AS IDispatch _                     ' __in IDispatch *pElemDisp
   )                                                    ' void
   ' =====================================================================================
   METHOD ensurePrintDialogDefaults <5> ( _             ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD showPrintDialog <6> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD showPageSetupDialog <7> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD printNonNative <8> ( _                        ' VTable offset = 56
     BYVAL pMarkup AS IUnknown _                        ' __in IUnknown *pMarkup
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   METHOD printNonNativeFrames <9> ( _                  ' VTable offset = 60
     BYVAL pMarkup AS IUnknown _                        ' __in IUnknown *pMarkup
   , BYVAL fActiveFrame AS INTEGER _                    ' __in VARIANT_BOOL fActiveFrame
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET framesetDocument <10> ( _               ' VTable offset = 64
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET framesetDocument <10> ( _               ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameActive <11> ( _                    ' VTable offset = 72
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameActive <11> ( _                    ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameAsShown <12> ( _                   ' VTable offset = 80
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameAsShown <12> ( _                   ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET selection <13> ( _                      ' VTable offset = 88
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selection <13> ( _                      ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET selectedPages <14> ( _                  ' VTable offset = 96
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selectedPages <14> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET currentPage <15> ( _                    ' VTable offset = 104
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPage <15> ( _                    ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET currentPageAvail <16> ( _               ' VTable offset = 112
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPageAvail <16> ( _               ' VTable offset = 116
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY SET collate <17> ( _                        ' VTable offset = 120
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET collate <17> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY GET duplex <18> ( _                         ' VTable offset = 128
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   PROPERTY SET copies <19> ( _                         ' VTable offset = 132
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET copies <19> ( _                         ' VTable offset = 136
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET pageFrom <20> ( _                       ' VTable offset = 140
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageFrom <20> ( _                       ' VTable offset = 144
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET pageTo <21> ( _                         ' VTable offset = 148
     BYVAL v AS WORD _                                  ' __in WORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageTo <21> ( _                         ' VTable offset = 152
   ) AS WORD                                            ' __retval_out WORD *p
   ' =====================================================================================
   PROPERTY SET tableOfLinks <22> ( _                   ' VTable offset = 156
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET tableOfLinks <22> ( _                   ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET allLinkedDocuments <23> ( _             ' VTable offset = 164
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET allLinkedDocuments <23> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET header <24> ( _                         ' VTable offset = 172
     BYVAL bstrHeader AS WSTRING _                      ' __in BSTR bstrHeader
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET header <24> ( _                         ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *bstrHeader
   ' =====================================================================================
   PROPERTY SET footer <25> ( _                         ' VTable offset = 180
     BYVAL bstrFooter AS WSTRING _                      ' __in BSTR bstrFooter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET footer <25> ( _                         ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *bstrFooter
   ' =====================================================================================
   PROPERTY SET marginLeft <26> ( _                     ' VTable offset = 188
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginLeft <26> ( _                     ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginRight <27> ( _                    ' VTable offset = 196
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginRight <27> ( _                    ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginTop <28> ( _                      ' VTable offset = 204
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginTop <28> ( _                      ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY SET marginBottom <29> ( _                   ' VTable offset = 212
     BYVAL v AS LONG _                                  ' __in long v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET marginBottom <29> ( _                   ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET pageWidth <30> ( _                      ' VTable offset = 220
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET pageHeight <31> ( _                     ' VTable offset = 224
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableLeft <32> ( _                ' VTable offset = 228
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableTop <33> ( _                 ' VTable offset = 232
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableRight <34> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   PROPERTY GET unprintableBottom <35> ( _              ' VTable offset = 240
   ) AS LONG                                            ' __retval_out long *p
   ' =====================================================================================
   METHOD updatePageStatus <36> ( _                     ' VTable offset = 244
     BYREF p AS LONG _                                  ' __in long *p
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITemplatePrinter2 Methods
   ' =====================================================================================
   PROPERTY SET selectionEnabled <37> ( _               ' VTable offset = 248
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET selectionEnabled <37> ( _               ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET frameActiveEnabled <38> ( _             ' VTable offset = 256
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameActiveEnabled <38> ( _             ' VTable offset = 260
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *p
   ' =====================================================================================
   PROPERTY SET orientation <39> ( _                    ' VTable offset = 264
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET orientation <39> ( _                    ' VTable offset = 268
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET usePrinterCopyCollate <40> ( _          ' VTable offset = 272
     BYVAL v AS INTEGER _                               ' __in VARIANT_BOOL v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET usePrinterCopyCollate <40> ( _          ' VTable offset = 276
   ) AS INTEGER                                         ' __in VARIANT_BOOL v
   ' =====================================================================================
   METHOD deviceSupports <41> ( _                       ' VTable offset = 280
     BYVAL bstrProperty AS WSTRING _                    ' __in BSTR bstrProperty
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================

   ' =====================================================================================
   ' ITemplatePrinter3 Methods
   ' =====================================================================================
   PROPERTY SET headerFooterFont <42> ( _               ' VTable offset = 284
     BYVAL bstrFooter AS WSTRING _                      ' __in BSTR bstrFooter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET headerFooterFont <42> ( _               ' VTable offset = 288
   ) AS WSTRING                                         ' __retval_out BSTR *bstrFooter
   ' =====================================================================================
   METHOD getPageMarginTop <43> ( _                     ' VTable offset = 292
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   , BYVAL pageWidth AS LONG _                          ' __in long pageWidth
   , BYVAL pageHeight AS LONG _                         ' __in long pageHeight
   ) AS VARIANT                                         ' __retval_out VARIANT *pMargin
   ' =====================================================================================
   METHOD getPageMarginRight <44> ( _                   ' VTable offset = 296
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   , BYVAL pageWidth AS LONG _                          ' __in long pageWidth
   , BYVAL pageHeight AS LONG _                         ' __in long pageHeight
   ) AS VARIANT                                         ' __retval_out VARIANT *pMargin
   ' =====================================================================================
   METHOD getPageMarginBottom <45> ( _                  ' VTable offset = 300
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   , BYVAL pageWidth AS LONG _                          ' __in long pageWidth
   , BYVAL pageHeight AS LONG _                         ' __in long pageHeight
   ) AS VARIANT                                         ' __retval_out VARIANT *pMargin
   ' =====================================================================================
   METHOD getPageMarginLeft <46> ( _                    ' VTable offset = 304
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   , BYVAL pageWidth AS LONG _                          ' __in long pageWidth
   , BYVAL pageHeight AS LONG _                         ' __in long pageHeight
   ) AS VARIANT                                         ' __retval_out VARIANT *pMargin
   ' =====================================================================================
   METHOD getPageMarginTopImportant <47> ( _            ' VTable offset = 308
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbImportant
   ' =====================================================================================
   METHOD getPageMarginRightImportant <48> ( _          ' VTable offset = 312
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbImportant
   ' =====================================================================================
   METHOD getPageMarginBottomImportant <49> ( _         ' VTable offset = 316
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbImportant
   ' =====================================================================================
   METHOD getPageMarginLeftImportant <50> ( _           ' VTable offset = 320
     BYVAL pageRule AS IDispatch _                      ' __in IDispatch *pageRule
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbImportant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITemplatePrinter3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHeaderFooter
' IID = {3050F6CE-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHeaderFooter_INTERFACE_DEFINED)
   %IHeaderFooter_INTERFACE_DEFINED = 1

INTERFACE IHeaderFooter $IID_IHeaderFooter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET htmlHead <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY GET htmlFoot <2> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET textHead <3> ( _                        ' VTable offset = 36
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET textHead <3> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET textFoot <4> ( _                        ' VTable offset = 44
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET textFoot <4> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET page <5> ( _                            ' VTable offset = 52
     BYVAL v AS DWORD _                                 ' __in DWORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET page <5> ( _                            ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out DWORD *p
   ' =====================================================================================
   PROPERTY SET pageTotal <6> ( _                       ' VTable offset = 60
     BYVAL v AS DWORD _                                 ' __in DWORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageTotal <6> ( _                       ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out DWORD *p
   ' =====================================================================================
   PROPERTY SET URL <7> ( _                             ' VTable offset = 68
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <7> ( _                             ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET title <8> ( _                           ' VTable offset = 76
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET title <8> ( _                           ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET dateShort <9> ( _                       ' VTable offset = 84
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dateShort <9> ( _                       ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET dateLong <10> ( _                       ' VTable offset = 92
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dateLong <10> ( _                       ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET timeShort <11> ( _                      ' VTable offset = 100
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timeShort <11> ( _                      ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET timeLong <12> ( _                       ' VTable offset = 108
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timeLong <12> ( _                       ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHeaderFooter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHeaderFooter2
' IID = {305104A5-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IHeaderFooter
' ########################################################################################

#IF NOT %DEF(%IHeaderFooter2_INTERFACE_DEFINED)
    %IHeaderFooter2_INTERFACE_DEFINED = 1

INTERFACE IHeaderFooter2 $IID_IHeaderFooter2

   INHERIT IDispatch

   ' =====================================================================================
   ' IHeaderFooter methods
   ' =====================================================================================
   PROPERTY GET htmlHead <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY GET htmlFoot <2> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET textHead <3> ( _                        ' VTable offset = 36
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET textHead <3> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET textFoot <4> ( _                        ' VTable offset = 44
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET textFoot <4> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET page <5> ( _                            ' VTable offset = 52
     BYVAL v AS DWORD _                                 ' __in DWORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET page <5> ( _                            ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out DWORD *p
   ' =====================================================================================
   PROPERTY SET pageTotal <6> ( _                       ' VTable offset = 60
     BYVAL v AS DWORD _                                 ' __in DWORD v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET pageTotal <6> ( _                       ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out DWORD *p
   ' =====================================================================================
   PROPERTY SET URL <7> ( _                             ' VTable offset = 68
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <7> ( _                             ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET title <8> ( _                           ' VTable offset = 76
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET title <8> ( _                           ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET dateShort <9> ( _                       ' VTable offset = 84
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dateShort <9> ( _                       ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET dateLong <10> ( _                       ' VTable offset = 92
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET dateLong <10> ( _                       ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET timeShort <11> ( _                      ' VTable offset = 100
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timeShort <11> ( _                      ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================
   PROPERTY SET timeLong <12> ( _                       ' VTable offset = 108
     BYVAL v AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET timeLong <12> ( _                       ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *p
   ' =====================================================================================

   ' =====================================================================================
   ' IHeaderFooter2 Methods
   ' =====================================================================================
   PROPERTY SET font <13> ( _                           ' VTable offset = 116
     BYVAL p AS WSTRING _                               ' __in BSTR v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET font <13> ( _                           ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out *p VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHeaderFooter2_INTERFACE_DEFINED__ */
