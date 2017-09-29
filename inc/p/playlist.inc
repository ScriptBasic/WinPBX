' ########################################################################################
' Microsoft Windows
' File: PlayList.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PLAYLIST_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "strmif.inc"

$IID_IAMPlayListItem = GUID$("{56a868ff-0ad4-11ce-b03a-0020af0ba770}")
$IID_IAMRebuild = GUID$("{02EF04DD-7580-11d1-BECE-00C04FB6E937}")
$IID_IAMPlayList = GUID$("{56a868fe-0ad4-11ce-b03a-0020af0ba770}")
$SPECIFYPAGES_STATISTICS = GUID$("{4c437b92-6e9e-11d1-a704-006097c4e476}")
$IID_ISpecifyParticularPages = GUID$("{4C437B91-6E9E-11d1-A704-006097C4E476}")

' enum AMPlayListItemFlags
%AMPLAYLISTITEM_CANSKIP = &H1
%AMPLAYLISTITEM_CANBIND = &H2

' ########################################################################################
' Interface name = IAMPlayListItem
' IID = 56a868ff-0ad4-11ce-b03a-0020af0ba770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMPlayListItem_INTERFACE_DEFINED)
    %IAMPlayListItem_INTERFACE_DEFINED = 1

INTERFACE IAMPlayListItem $IID_IAMPlayListItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 12
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceCount ( _                            ' VTable offset = 16
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwSources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceURL ( _                              ' VTable offset = 20
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF pbstrURL AS WSTRING _                        ' __out BSTR *pbstrURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceStart ( _                            ' VTable offset = 24
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF prtStart AS QUAD _                           ' __out REFERENCE_TIME *prtStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceDuration ( _                         ' VTable offset = 28
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF prtDuration AS QUAD _                        ' __out REFERENCE_TIME *prtDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceStartMarker ( _                      ' VTable offset = 32
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF pdwMarker AS DWORD _                         ' __out DWORD *pdwMarker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceEndMarker ( _                        ' VTable offset = 36
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF pdwMarker AS DWORD _                         ' __out DWORD *pdwMarker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceStartMarkerName ( _                  ' VTable offset = 40
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF pbstrStartMarker AS WSTRING _                ' __out BSTR *pbstrStartMarker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceEndMarkerName ( _                    ' VTable offset = 44
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF pbstrEndMarker AS WSTRING _                  ' __out BSTR *pbstrEndMarker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkURL ( _                                ' VTable offset = 48
     BYREF pbstrURL AS WSTRING _                        ' __out BSTR *pbstrURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScanDuration ( _                           ' VTable offset = 52
     BYVAL dwSourceIndex AS DWORD _                     ' __in DWORD dwSourceIndex
   , BYREF prtScanDuration AS QUAD _                    ' __out REFERENCE_TIME *prtScanDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMPlayListItem_INTERFACE_DEFINED__ */


' enum AMPlayListFlags
%AMPLAYLIST_STARTINSCANMODE = &H1
%AMPLAYLIST_FORCEBANNER     = &H2

' enum AMPlayListEventFlags
%AMPLAYLISTEVENT_RESUME     = 0
%AMPLAYLISTEVENT_BREAK      = &H1
%AMPLAYLISTEVENT_NEXT       = &H2
%AMPLAYLISTEVENT_MASK       = &Hf
%AMPLAYLISTEVENT_REFRESH    = &H10


' ########################################################################################
' Interface name = IAMPlayList
' IID = 56a868fe-0ad4-11ce-b03a-0020af0ba770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMPlayList_INTERFACE_DEFINED)
    %IAMPlayList_INTERFACE_DEFINED = 1

INTERFACE IAMPlayList $IID_IAMPlayList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 12
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemCount ( _                              ' VTable offset = 16
     BYREF pdwItems AS DWORD _                          ' __out DWORD *pdwItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 20
     BYVAL dwItemIndex AS DWORD _                       ' __in DWORD dwItemIndex
   , BYREF ppItem AS IAMPlayListItem _                  ' __out IAMPlayListItem **ppItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamedEvent ( _                             ' VTable offset = 24
     BYVAL pwszEventName AS DWORD _                     ' __in WCHAR *pwszEventName
   , BYVAL dwItemIndex AS DWORD _                       ' __in DWORD dwItemIndex
   , BYREF ppItem AS IAMPlayListItem _                  ' __out IAMPlayListItem **ppItem
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRepeatInfo ( _                             ' VTable offset = 28
     BYREF pdwRepeatCount AS DWORD _                    ' __out DWORD *pdwRepeatCount
   , BYREF pdwRepeatStart AS DWORD _                    ' __out DWORD *pdwRepeatStart
   , BYREF pdwRepeatEnd AS DWORD _                      ' __out DWORD *pdwRepeatEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMPlayList_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpecifyParticularPages
' IID = 4C437B91-6E9E-11d1-A704-006097C4E476
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpecifyParticularPages_INTERFACE_DEFINED)
    %ISpecifyParticularPages_INTERFACE_DEFINED = 1

INTERFACE ISpecifyParticularPages $IID_ISpecifyParticularPages

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPages ( _                                  ' VTable offset = 12
     BYREF guidWhatPages AS GUID _                      ' __in REFGUID guidWhatPages
   , BYREF pPages AS CAUUID _                           ' __out CAUUID *pPages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpecifyParticularPages_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMRebuild
' IID = 02EF04DD-7580-11d1-BECE-00C04FB6E937
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMRebuild_INTERFACE_DEFINED)
    %IAMRebuild_INTERFACE_DEFINED = 1

INTERFACE IAMRebuild $IID_IAMRebuild

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RebuildNow ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMRebuild_INTERFACE_DEFINED__ */
