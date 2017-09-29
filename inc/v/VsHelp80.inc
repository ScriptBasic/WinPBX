' ########################################################################################
' Microsoft Windows
' File: VsHelp80.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: VsHelp80
' Version: 1.0, Locale ID = 0
' Description: VsHelp80
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\MSEnv\\vshelp80.olb
' Library GUID: {DB7A405D-208F-4E88-BA0A-132ACFA0B5B6}
' ########################################################################################

#INCLUDE THIS ONCE
%VSHELP80_INC = 1

#INCLUDE ONCE "VsHelp.inc"

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IvsHelp2 = GUID$("{78413D2D-0492-4A9B-AB25-730633679977}")
$IID_IVsHelpFavorites = GUID$("{D1333514-2B6B-4479-8135-A39E286E146D}")
$IID_SVsHelpFavorites = GUID$("{4A81432B-BFCC-4832-9BE9-15977DA82072}")

' ========================================================================================
' __vsSearchFlags enum
' ========================================================================================

%vsSearchFlagsNone                                      = 0            ' &H0
%vsSearchFlagsExecuteSearch                             = 1            ' &H1
%vsSearchFlagsAddToExistingQueryString                  = 2            ' &H2
%vsSearchFlagsFilterTransformSpecified                  = 4            ' &H4

' ========================================================================================
' __vsAskQuestionFlags enum
' ========================================================================================

%vsAskQuestionFlagsAskNew                               = 1            ' &H1
%vsAskQuestionFlagsCheckStatus                          = 2            ' &H2
%vsAskQuestionFlagsSendFeedback                         = 4            ' &H4

' ========================================================================================
' __vsHelpDisplayUrlFlags enum
' ========================================================================================

%vsHelpDisplayUrlFlagsNone                              = 0            ' &H0
%vsHelpDisplayUrlFlagsHighlightTerm                     = 1            ' &H1
%vsHelpDisplayUrlFlagsOpenNewWindow                     = 2            ' &H2
%vsHelpDisplayUrlFlagsGuidLocal                         = 16           ' &H10
%vsHelpDisplayUrlFlagsGuidOnline                        = 32           ' &H20
%vsHelpDisplayUrlFlagsGuidLocale                        = 64           ' &H40
%vsHelpDisplayUrlFlagsGuidFailover                      = 128          ' &H80
%vsHelpDisplayUrlFlagsNamedUrl                          = 256          ' &H100
%vsHelpDisplayUrlFlagsNoHistory                         = 512          ' &H200
%vsHelpDisplayUrlFlagsNoHistoryThisPage                 = 1024         ' &H400

' ========================================================================================
' __vsHelpUrlFromTopicIDFlags enum
' ========================================================================================

%HUFTID_Default                                         = 0            ' &H0
%HUFTID_Local                                           = 1            ' &H1
%HUFTID_Online                                          = 2            ' &H2
%HUFTID_Locale                                          = 4            ' &H4

' ========================================================================================
' vsHelpSearchFilterTransforms
' Note  These constants must be null-terminated unicode strings (LPWSTR).
' ========================================================================================

$vsHelpSearchFilterTransformsHelp                       = "Help"
$vsHelpSearchFilterTransformsControls                   = "Controls"
$vsHelpSearchFilterTransformsSamples                    = "Samples"
$vsHelpSearchFilterTransformsSnippets                   = "Snippets"
$vsHelpSearchFilterTransformsStarterKits                = "StarterKits"
$vsHelpSearchFilterTransformsAddins                     = "Addins"
$vsHelpSearchFilterTransformsUnfiltered                 = "Unfiltered"

' ########################################################################################
' Interface name = Help2
' IID = {78413D2D-0492-4A9B-AB25-730633679977}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = Help
' ########################################################################################

#IF NOT %DEF(%IvsHelp2_INTERFACE_DEFINED)
    %IvsHelp2_INTERFACE_DEFINED = 1

INTERFACE IvsHelp2 $IID_IvsHelp2

   INHERIT IDispatch

   ' =====================================================================================
   ' Help Methods
   ' =====================================================================================
   METHOD Contents <1> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Index <2> ( _                                 ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Search <3> ( _                                ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD IndexResults <4> ( _                          ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD SearchResults <5> ( _                         ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFromId <6> ( _                    ' VTable offset = 48
     BYVAL bstrFile AS WSTRING _                        ' __in BSTR bstrFile
   , BYVAL Id AS DWORD _                                ' __in unsigned long Id
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFromURL <7> ( _                   ' VTable offset = 52
     BYVAL pszURL AS WSTRING _                          ' __in BSTR pszURL
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFromURLEx <8> ( _                 ' VTable offset = 56
     BYVAL pszURL AS WSTRING _                          ' __in BSTR pszURL
   , BYVAL pIVsHelpTopicShowEvents AS IVsHelpTopicShowEvents _ ' __in IVsHelpTopicShowEvents* pIVsHelpTopicShowEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFromKeyword <9> ( _               ' VTable offset = 60
     BYVAL pszKeyword AS WSTRING _                      ' __in BSTR pszKeyword
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFromF1Keyword <10> ( _            ' VTable offset = 64
     BYVAL pszKeyword AS WSTRING _                      ' __in BSTR pszKeyword
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFrom_OLD_Help <11> ( _            ' VTable offset = 68
     BYVAL bstrFile AS WSTRING _                        ' __in BSTR bstrFile
   , BYVAL Id AS DWORD _                                ' __in unsigned long Id
   )                                                    ' void
   ' =====================================================================================
   METHOD SyncContents <12> ( _                         ' VTable offset = 72
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   METHOD CanSyncContents <13> ( _                      ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNextTopic <14> ( _                         ' VTable offset = 80
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrNext
   ' =====================================================================================
   METHOD GetPrevTopic <15> ( _                         ' VTable offset = 84
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPrev
   ' =====================================================================================
   METHOD FilterUI <16> ( _                             ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD CanShowFilterUI <17> ( _                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <18> ( _                                ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD SyncIndex <19> ( _                            ' VTable offset = 100
     BYVAL bstrKeyword AS WSTRING _                     ' __in BSTR bstrKeyword
   , BYVAL fShow AS LONG _                              ' __in long fShow
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCollection <20> ( _                        ' VTable offset = 104
     BYVAL bstrCollection AS WSTRING _                  ' __in BSTR bstrCollection
   , BYVAL bstrFilter AS WSTRING _                      ' __in BSTR bstrFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Collection <21> ( _                     ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCollection
   ' =====================================================================================
   PROPERTY GET Filter <22> ( _                         ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilter
   ' =====================================================================================
   PROPERTY SET Filter <22> ( _                         ' VTable offset = 116
     BYVAL pbstrFilter AS WSTRING _                     ' __in BSTR pbstrFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterQuery <23> ( _                    ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterQuery
   ' =====================================================================================
   PROPERTY GET HelpOwner <24> ( _                      ' VTable offset = 124
   ) AS IVsHelpOwner                                    ' __retval_out IVsHelpOwner** ppObj
   ' =====================================================================================
   PROPERTY SET HelpOwner <24> ( _                      ' VTable offset = 128
     BYVAL IVsHelpOwner _                               ' __in IVsHelpOwner* IVsHelpOwner
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HxSession <25> ( _                      ' VTable offset = 132
   ) AS IDispatch                                       ' __retval_out IDispatch** ppObj
   ' =====================================================================================
   PROPERTY GET Help <26> ( _                           ' VTable offset = 136
   ) AS IDispatch                                       ' __retval_out IDispatch** ppObj
   ' =====================================================================================
   METHOD GetObject <27> ( _                            ' VTable offset = 140
     BYVAL bstrMoniker AS WSTRING _                     ' __in BSTR bstrMoniker
   , BYVAL bstrOptions AS WSTRING _                     ' __in BSTR bstrOptions
   ) AS IDispatch                                       ' __retval_out IDispatch** ppDisp
   ' =====================================================================================

   ' =====================================================================================
   ' IvsHelp2 Methods
   ' =====================================================================================
   METHOD SearchEx <28> ( _                             ' VTable offset = 144
     BYVAL bstrSearchFilterTransform AS WSTRING _       ' __in BSTR bstrSearchFilterTransform
   , BYVAL pszSearchTerm AS WSTRING _                   ' __in BSTR pszSearchTerm
   , BYVAL vssfSearchFlags AS DWORD _                   ' __in unsigned long vssfSearchFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD HowDoI <29> ( _                               ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD Favorites <30> ( _                            ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD AskAQuestion <31> ( _                         ' VTable offset = 156
     BYVAL askQuestionFlags AS DWORD _                  ' __in unsigned long askQuestionFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayTopicFromURLEx2 <32> ( _               ' VTable offset = 160
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   , BYVAL displayUrlFlags AS DWORD _                   ' __in unsigned long displayUrlFlags
   , BYVAL bstrParam AS WSTRING _                       ' __in BSTR bstrParam
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeSettingsToken <33> ( _              ' VTable offset = 164
     BYVAL bstrSettingsToken AS WSTRING _               ' __in BSTR bstrSettingsToken
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IvsHelp2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVsHelpFavorites
' IID = {D1333514-2B6B-4479-8135-A39E286E146D}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVsHelpFavorites_INTERFACE_DEFINED)
    %IVsHelpFavorites_INTERFACE_DEFINED = 1

INTERFACE IVsHelpFavorites $IID_IVsHelpFavorites

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ShowFavorites ( _                             ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFavoriteTopic ( _                          ' VTable offset = 16
     BYVAL strTitle AS WSTRING _                        ' __in BSTR strTitle
   , BYVAL strUrl AS WSTRING _                          ' __in BSTR strUrl
   , BYVAL topicKeyword AS WSTRING _                    ' __in BSTR topicKeyword
   , BYVAL strTopicLocale AS WSTRING _                  ' __in BSTR strTopicLocale
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVsHelpFavorites_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = SVsHelpFavorites
' IID = {4A81432B-BFCC-4832-9BE9-15977DA82072}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%SVsHelpFavorites_INTERFACE_DEFINED)
    %SVsHelpFavorites_INTERFACE_DEFINED = 1

INTERFACE SVsHelpFavorites $IID_SVsHelpFavorites

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __SVsHelpFavorites_INTERFACE_DEFINED__ */
