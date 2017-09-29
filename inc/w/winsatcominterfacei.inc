' ########################################################################################
' Microsoft Windows
' File: winsatcominterfacei.inc
' Contents: Windows System Assessment Tool (WinSAT)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WINSATLib
' Version: 1.0, Locale ID = 0
' Description: Winsat 1.0 Type Library
' Documentation string: WinSAT 1.0 Type Library
' Path: C:\Windows\system32\WinSATAPI.dll
' Library GUID: {15AE3A36-E53B-454D-A816-A7C61CBAB8A4}
' ########################################################################################

#INCLUDE THIS ONCE
%WINSATCOMINTERFACEI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "msxml.inc"
#INCLUDE ONCE "oleacc.inc"
#INCLUDE ONCE "taskschd.inc"

$LIBID_WINSATLib = GUID$("{15AE3A36-E53B-454D-A816-A7C61CBAB8A4}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {05DF8D13-C355-47F4-A11E-851B338CEFB8}
$PROGID_CQueryAllWinSAT = "QueryAllWinSAT"
' CLSID = {F3BDFAD3-F276-49E9-9B17-C474F48F0764}
$PROGID_CQueryWinSAT = "QueryWinSAT"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CWinSATTaskMangerTask = GUID$("{A9A33436-678B-4C9C-A211-7CC38785E79D}")
$CLSID_CAccessiblityWinSAT = GUID$("{6E18F9C6-A3EB-495A-89B7-956482E19F7A}")
$CLSID_CInitiateWinSAT = GUID$("{489331DC-F5E0-4528-9FDA-45331BF4A571}")
$CLSID_CProvideWinSATVisuals = GUID$("{9F377D7E-E551-44F8-9F94-9DB392B03B7B}")
$CLSID_CQueryOEMWinSATCustomization = GUID$("{C47A41B7-B729-424F-9AF9-5CB3934F2DFA}")
$CLSID_CQueryAllWinSAT = GUID$("{05DF8D13-C355-47F4-A11E-851B338CEFB8}")
$CLSID_CQueryWinSAT = GUID$("{F3BDFAD3-F276-49E9-9B17-C474F48F0764}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IWinSATTaskMangerTask = GUID$("{295D2F4E-0B80-4892-A6CE-78C6957BD75A}")
$IID_IProvideWinSATAssessmentInfo = GUID$("{0CD1C380-52D3-4678-AC6F-E929E480BE9E}")
$IID_IProvideWinSATResultsInfo = GUID$("{F8334D5D-568E-4075-875F-9DF341506640}")
$IID_IQueryRecentWinSATAssessment = GUID$("{F8AD5D1F-3B47-4BDC-9375-7C6B1DA4ECA7}")
$IID_IProvideWinSATVisuals = GUID$("{A9F4ADE0-871A-42A3-B813-3078D25162C9}")
$IID_IQueryAllWinSATAssessments = GUID$("{0B89ED1D-6398-4FEA-87FC-567D8D19176F}")
$IID_IWinSATInitiateEvents = GUID$("{262A1918-BA0D-41D5-92C2-FAB4633EE74F}")
$IID_IInitiateWinSATAssessment = GUID$("{D983FC50-F5BF-49D5-B5ED-CCCB18AA7FC1}")
$IID_IAccessibleWinSAT = GUID$("{30E6018A-94A8-4FF8-A69A-71B67413F07B}")
$IID_IQueryOEMWinSATCustomization = GUID$("{BC9A6A9F-AD4E-420E-9953-B34671E9DF22}")

' ========================================================================================
' WINSAT_OEM_CUSTOMIZATION_STATE enum
' ========================================================================================

%WINSAT_OEM_DATA_VALID                = 0
%WINSAT_OEM_DATA_NON_SYS_CONFIG_MATCH = 1
%WINSAT_OEM_DATA_INVALID              = 2
%WINSAT_OEM_NO_DATA_SUPPLIED          = 3

' ========================================================================================
' WINSAT_ASSESSMENT_STATE enum
' ========================================================================================

%WINSAT_ASSESSMENT_STATE_MIN                      = 0
%WINSAT_ASSESSMENT_STATE_UNKNOWN                  = 0
%WINSAT_ASSESSMENT_STATE_VALID                    = 1
%WINSAT_ASSESSMENT_STATE_INCOHERENT_WITH_HARDWARE = 2
%WINSAT_ASSESSMENT_STATE_NOT_AVAILABLE            = 3
%WINSAT_ASSESSMENT_STATE_INVALID                  = 4
%WINSAT_ASSESSMENT_STATE_MAX                      = 4

' ========================================================================================
' WINSAT_ASSESSMENT_TYPE enum
' ========================================================================================

%WINSAT_ASSESSMENT_MEMORY   = 0
%WINSAT_ASSESSMENT_CPU      = 1
%WINSAT_ASSESSMENT_DISK     = 2
%WINSAT_ASSESSMENT_D3D      = 3
%WINSAT_ASSESSMENT_GRAPHICS = 4

' ========================================================================================
' WINSAT_BITMAP_SIZE enum
' ========================================================================================

%WINSAT_BITMAP_SIZE_SMALL  = 0
%WINSAT_BITMAP_SIZE_NORMAL = 1

' ########################################################################################
' Interface name = IWinSATTaskMangerTask
' IID = 295D2F4E-0B80-4892-A6CE-78C6957BD75A"
' Inherited interface = ITaskHandler
' ########################################################################################

#IF NOT %DEF(%IWinSATTaskMangerTask_INTERFACE_DEFINED)
    %IWinSATTaskMangerTask_INTERFACE_DEFINED = 1

INTERFACE IWinSATTaskMangerTask $IID_IWinSATTaskMangerTask

   INHERIT IUnknown

   ' =====================================================================================
   ' ITaskHandler Methods
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYVAL pHandlerServices AS IUnknown _               ' __in IUnknown* pHandlerServices
   , BYVAL Data AS WSTRING _                            ' __in BSTR Data
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
     BYREF pRetCode AS LONG _                           ' __out HRESULT* pRetCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWinSATTaskMangerTask Methods
   ' =====================================================================================
   ' This interface has no additional methods

END INTERFACE

#ENDIF   ' /* __IWinSATTaskMangerTask_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProvideWinSATAssessmentInfo
' IID = {0CD1C380-52D3-4678-AC6F-E929E480BE9E}
' Attributes = 4160 [&H00001040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IProvideWinSATAssessmentInfo_INTERFACE_DEFINED)
    %IProvideWinSATAssessmentInfo_INTERFACE_DEFINED = 1

INTERFACE IProvideWinSATAssessmentInfo $IID_IProvideWinSATAssessmentInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Score <1> ( _                           ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float *score
   ' =====================================================================================
   PROPERTY GET Title <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *title
   ' =====================================================================================
   PROPERTY GET Description <4> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideWinSATAssessmentInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProvideWinSATResultsInfo
' IID = {F8334D5D-568E-4075-875F-9DF341506640}
' Attributes = 4160 [&H00001040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IProvideWinSATResultsInfo_INTERFACE_DEFINED)
    %IProvideWinSATResultsInfo_INTERFACE_DEFINED = 1

INTERFACE IProvideWinSATResultsInfo $IID_IProvideWinSATResultsInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetAssessmentInfo <1> ( _                     ' VTable offset = 28
     BYVAL assessment AS LONG _                         ' __in WINSAT_ASSESSMENT_TYPE assessment
   ) AS IProvideWinSATAssessmentInfo                    ' __retval_out IProvideWinSATAssessmentInfo **ppinfo
   ' =====================================================================================
   PROPERTY GET AssessmentState <2> ( _                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out WINSAT_ASSESSMENT_STATE *state
   ' =====================================================================================
   PROPERTY GET AssessmentDateTime <3> ( _              ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *fileTime
   ' =====================================================================================
   PROPERTY GET SystemRating <4> ( _                    ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out float *level
   ' =====================================================================================
   PROPERTY GET RatingStateDesc <5> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideWinSATResultsInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQueryRecentWinSATAssessment
' IID = {F8AD5D1F-3B47-4BDC-9375-7C6B1DA4ECA7}
' Attributes = 4160 [&H00001040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IQueryRecentWinSATAssessment_INTERFACE_DEFINED)
    %IQueryRecentWinSATAssessment_INTERFACE_DEFINED = 1

INTERFACE IQueryRecentWinSATAssessment $IID_IQueryRecentWinSATAssessment

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET xml <1> ( _                             ' VTable offset = 28
     BYVAL xPath AS WSTRING _                           ' __in BSTR xPath
   , OPTIONAL BYVAL namespaces AS WSTRING _             ' __in_opt BSTR namespaces
   ) AS IXMLDOMNodeList                                 ' __retval_out IXMLDOMNodeList **ppDomNodeList
   ' =====================================================================================
   PROPERTY GET Info <2> ( _                            ' VTable offset = 32
   ) AS IProvideWinSATResultsInfo                       ' __retval_out IProvideWinSATResultsInfo **ppWinSATAssessmentInfo
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryRecentWinSATAssessment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProvideWinSATVisuals
' IID = {A9F4ADE0-871A-42A3-B813-3078D25162C9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvideWinSATVisuals_INTERFACE_DEFINED)
    %IProvideWinSATVisuals_INTERFACE_DEFINED = 1

INTERFACE IProvideWinSATVisuals $IID_IProvideWinSATVisuals

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Bitmap ( _                                ' VTable offset = 12
     BYVAL bitmapSize AS LONG _                         ' __in WINSAT_BITMAP_SIZE bitmapSize
   , BYVAL state AS LONG _                              ' __in WINSAT_ASSESSMENT_STATE state
   , BYVAL rating AS SINGLE _                           ' __in float rating
   , BYREF pBitmap AS DWORD _                           ' __out HBITMAP *pBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideWinSATVisuals_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQueryAllWinSATAssessments
' IID = {0B89ED1D-6398-4FEA-87FC-567D8D19176F}
' Attributes = 4160 [&H00001040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IQueryAllWinSATAssessments_INTERFACE_DEFINED)
    %IQueryAllWinSATAssessments_INTERFACE_DEFINED = 1

INTERFACE IQueryAllWinSATAssessments $IID_IQueryAllWinSATAssessments

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AllXML <1> ( _                          ' VTable offset = 28
     BYVAL xPath AS WSTRING _                           ' __in BSTR xPath
   , OPTIONAL BYVAL namespaces AS WSTRING _             ' __in_opt BSTR namespaces
   ) AS IXMLDOMNodeList                                 ' __retval_out IXMLDOMNodeList **ppDomNodeList
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryAllWinSATAssessments_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWinSATInitiateEvents
' IID = {262A1918-BA0D-41D5-92C2-FAB4633EE74F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWinSATInitiateEvents_INTERFACE_DEFINED)
    %IWinSATInitiateEvents_INTERFACE_DEFINED = 1

INTERFACE IWinSATInitiateEvents $IID_IWinSATInitiateEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD WinSATComplete ( _                            ' VTable offset = 12
     BYVAL hresult AS LONG _                            ' __in HRESULT hresult
   , BYREF strDescription AS WSTRINGZ _                 ' __in LPCWSTR strDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WinSATUpdate ( _                              ' VTable offset = 16
     BYVAL uCurrentTick AS DWORD _                      ' __in UINT uCurrentTick
   , BYVAL uTickTotal AS DWORD _                        ' __in UINT uTickTotal
   , BYREF strCurrentState AS WSTRINGZ _                ' __in LPCWSTR strCurrentState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinSATInitiateEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IInitiateWinSATAssessment
' IID = {D983FC50-F5BF-49D5-B5ED-CCCB18AA7FC1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitiateWinSATAssessment_INTERFACE_DEFINED)
    %IInitiateWinSATAssessment_INTERFACE_DEFINED = 1

INTERFACE IInitiateWinSATAssessment $IID_IInitiateWinSATAssessment

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitiateAssessment ( _                        ' VTable offset = 12
     BYREF cmdLine AS WSTRINGZ _                        ' __in LPCWSTR cmdLine
   , BYVAL pCallbacks AS IWinSATInitiateEvents _        ' __in_opt IWinSATInitiateEvents *pCallbacks
   , BYVAL callerHwnd AS DWORD _                        ' __in_opt HWND callerHwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitiateFormalAssessment ( _                  ' VTable offset = 16
     BYVAL pCallbacks AS IWinSATInitiateEvents _        ' __in_opt IWinSATInitiateEvents *pCallbacks
   , BYVAL callerHwnd AS DWORD _                        ' __in_opt HWND callerHwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelAssessment ( _                          ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitiateWinSATAssessment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAccessibleWinSAT
' IID = {30E6018A-94A8-4FF8-A69A-71B67413F07B}
' Attributes = 4096 [&H00001000] [Dispatchable]
' Inherited interface = IAccessible
' ########################################################################################

#IF NOT %DEF(%IAccessibleWinSAT_INTERFACE_DEFINED)
    %IAccessibleWinSAT_INTERFACE_DEFINED = 1

INTERFACE IAccessibleWinSAT $IID_IAccessibleWinSAT

   INHERIT IDispatch

   ' =====================================================================================
   ' IAccessible Methods
   ' =====================================================================================
   PROPERTY GET accParent <-5000> ( _                   ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdispParent
   ' =====================================================================================
   PROPERTY GET accChildCount <-5001> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pcountChildren
   ' =====================================================================================
   PROPERTY GET accChild <-5002> ( _                    ' VTable offset = 36
     BYVAL varChild AS VARIANT _                        ' __in VARIANT varChild
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdispChild
   ' =====================================================================================
   PROPERTY GET accName <-5003> ( _                     ' VTable offset = 40
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszName
   ' =====================================================================================
   PROPERTY GET accValue <-5004> ( _                    ' VTable offset = 44
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszValue
   ' =====================================================================================
   PROPERTY GET accDescription <-5005> ( _              ' VTable offset = 48
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszDescription
   ' =====================================================================================
   PROPERTY GET accRole <-5006> ( _                     ' VTable offset = 52
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRole
   ' =====================================================================================
   PROPERTY GET accState <-5007> ( _                    ' VTable offset = 56
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarState
   ' =====================================================================================
   PROPERTY GET accHelp <-5008> ( _                     ' VTable offset = 60
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszHelp
   ' =====================================================================================
   PROPERTY GET accHelpTopic <-5009> ( _                ' VTable offset = 64
     BYREF IN pszHelpFile AS WSTRING _                  ' __out BSTR *pszHelpFile
   , OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS LONG                                            ' __retval_out long *pidTopic
   ' =====================================================================================
   PROPERTY GET accKeyboardShortcut <-5010> ( _         ' VTable offset = 68
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszKeyboardShortcut
   ' =====================================================================================
   PROPERTY GET accFocus <-5011> ( _                    ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarChild
   ' =====================================================================================
   PROPERTY GET accSelection <-5012> ( _                ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarChildren
   ' =====================================================================================
   PROPERTY GET accDefaultAction <-5013> ( _            ' VTable offset = 80
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszDefaultAction
   ' =====================================================================================
   METHOD accSelect <-5014> ( _                         ' VTable offset = 84
     BYVAL flagsSelect AS LONG _                        ' __in long flagsSelect
   , OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   )                                                    ' void
   ' =====================================================================================
   METHOD accLocation <-5015> ( _                       ' VTable offset = 88
     BYREF pxLeft AS LONG _                             ' __out long *pxLeft
   , BYREF pyTop AS LONG _                              ' __out long *pyTop
   , BYREF pcxWidth AS LONG _                           ' __out long *pcxWidth
   , BYREF pcyHeight AS LONG _                          ' __out long *pcyHeight
   , OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   )                                                    ' void
   ' =====================================================================================
   METHOD accNavigate <-5016> ( _                       ' VTable offset = 92
     BYVAL navDir AS LONG _                             ' __in long navDir
   , OPTIONAL BYVAL varStart AS VARIANT _               ' __opt_in VARIANT varStart
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarEndUpAt
   ' =====================================================================================
   METHOD accHitTest <-5017> ( _                        ' VTable offset = 96
     BYVAL xLeft AS LONG _                              ' __in long xLeft
   , BYVAL yTop AS LONG _                               ' __in long yTop
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarChild
   ' =====================================================================================
   METHOD accDoDefaultAction <-5018> ( _                ' VTable offset = 100
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET accName <-5003> ( _                     ' VTable offset = 104
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   , BYVAL szName AS WSTRING _                          ' __in BSTR szName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET accValue <-5004> ( _                    ' VTable offset = 108
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   , BYVAL szValue AS WSTRING _                         ' __in BSTR szValue
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAccessibleWinSAT Methods
   ' =====================================================================================
   METHOD SetAccessiblityData <1610809344> ( _          ' VTable offset = 112
     BYREF wsName AS WSTRINGZ _                         ' __in LPCWSTR wsName
   , BYREF wsValue AS WSTRINGZ _                        ' __in LPCWSTR wsValue
   , BYREF wsDesc AS WSTRINGZ _                         ' __in LPCWSTR wsDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccessibleWinSAT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQueryOEMWinSATCustomization
' IID = {BC9A6A9F-AD4E-420E-9953-B34671E9DF22}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryOEMWinSATCustomization_INTERFACE_DEFINED)
    %IQueryOEMWinSATCustomization_INTERFACE_DEFINED = 1

INTERFACE IQueryOEMWinSATCustomization $IID_IQueryOEMWinSATCustomization

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOEMPrePopulationInfo ( _                   ' VTable offset = 12
     BYREF state AS LONG _                              ' __retval_out WINSAT_OEM_CUSTOMIZATION_STATE *state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryOEMWinSATCustomization_INTERFACE_DEFINED__ */
