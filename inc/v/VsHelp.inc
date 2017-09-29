' ########################################################################################
' Microsoft Windows
' File: VsHelp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: VsHelp
' Version: 1.0, Locale ID = 0
' Description: VsHelp
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\MSEnv\vshelp.tlb
' Library GUID: {83285928-227C-11D3-B870-00C04F79F802}
' ########################################################################################

#INCLUDE THIS ONCE
%VSHELP_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {4A79114D-19E4-11D3-B86B-00C04F79F802}
$PROGID_DExploreAppObj7 = "DExplore.AppObj.7"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {4A79114D-19E4-11D3-B86B-00C04F79F802}
$PROGID_DExploreAppObj = "DExplore.AppObj"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DExploreAppObj = GUID$("{4A79114D-19E4-11D3-B86B-00C04F79F802}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IvsHelp = GUID$("{4A791148-19E4-11D3-B86B-00C04F79F802}")
$IID_IVsHelpEvents = GUID$("{507E4490-5A8C-11D3-B897-00C04F79F802}")
$IID_IVsHelpOwner = GUID$("{B9B0983A-364C-4866-873F-D5ED190138FB}")
$IID_IVsHelpTopicShowEvents = GUID$("{D1AAC64A-6A25-4274-B2C6-BC3B840B6E54}")

' ########################################################################################
' Interface name = IVsHelpOwner
' IID = {B9B0983A-364C-4866-873F-D5ED190138FB}
' IVsHelpOwner Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IVsHelpOwner_INTERFACE_DEFINED)
    %IVsHelpOwner_INTERFACE_DEFINED = 1

INTERFACE IVsHelpOwner $IID_IVsHelpOwner

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BringHelpToTop <1> ( _                        ' VTable offset = 28
     BYVAL hwndHelpApp AS LONG _                        ' __in long hwndHelpApp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutomationObject <10> ( _               ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch** ppObj
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVsHelpOwner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVsHelpTopicShowEvents
' IID = {D1AAC64A-6A25-4274-B2C6-BC3B840B6E54}
' IVsHelpTopicEvents Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IVsHelpTopicShowEvents_INTERFACE_DEFINED)
    %IVsHelpTopicShowEvents_INTERFACE_DEFINED = 1

INTERFACE IVsHelpTopicShowEvents $IID_IVsHelpTopicShowEvents

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnBeforeTopicShow <1> ( _                     ' VTable offset = 28
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   , BYVAL pWB AS IDispatch _                           ' __in IDispatch* pWB
   )                                                    ' void
   ' =====================================================================================
   METHOD OnTopicShowComplete <2> ( _                   ' VTable offset = 32
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   , BYVAL pWB AS IDispatch _                           ' __in IDispatch* pWB
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVsHelpTopicShowEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Help
' IID = {4A791148-19E4-11D3-B86B-00C04F79F802}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IvsHelp_INTERFACE_DEFINED)
    %IvsHelp_INTERFACE_DEFINED = 1

INTERFACE IvsHelp $IID_IvsHelp

   INHERIT IDispatch

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

END INTERFACE

#ENDIF   ' /* __IvsHelp_INTERFACE_DEFINED__ */
