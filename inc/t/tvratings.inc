' ########################################################################################
' Microsoft Windows
' File: tvratings.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TVRATINGS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

'EXTERN_C const IID LIBID_TVRATINGSLib;

$CLSID_XDSToRat = GUID$("{C5C5C5B0-3ABC-11D6-B25B-00C04FA0C026}")
$CLSID_EvalRat = GUID$("{C5C5C5F1-3ABC-11D6-B25B-00C04FA0C026}")

' ========================================================================================
' EnTvRat_System enum
' ========================================================================================

%EnTvRat_System_MPAA                 = 0
%EnTvRat_System_US_TV                = 1
%EnTvRat_System_Canadian_English     = 2
%EnTvRat_System_Canadian_French      = 3
%EnTvRat_System_Reserved4            = 4
%EnTvRat_System_System5              = 5
%EnTvRat_System_System6              = 6
%EnTvRat_System_Reserved7            = 7
%EnTvRat_System_PBDA                 = 8
%EnTvRat_System_AgeBased             = 9
%EnTvRat_System_TvRat_kSystems       = 10
%EnTvRat_System_TvRat_SystemDontKnow = 255

' ========================================================================================
' EnTvRat_GenericLevel enum
' ========================================================================================

%EnTvRat_GenericLevel_TvRat_0             = 0
%EnTvRat_GenericLevel_TvRat_1             = 1
%EnTvRat_GenericLevel_TvRat_2             = 2
%EnTvRat_GenericLevel_TvRat_3             = 3
%EnTvRat_GenericLevel_TvRat_4             = 4
%EnTvRat_GenericLevel_TvRat_5             = 5
%EnTvRat_GenericLevel_TvRat_6             = 6
%EnTvRat_GenericLevel_TvRat_7             = 7
%EnTvRat_GenericLevel_TvRat_8             = 8
%EnTvRat_GenericLevel_TvRat_9             = 9
%EnTvRat_GenericLevel_TvRat_10            = 10
%EnTvRat_GenericLevel_TvRat_11            = 11
%EnTvRat_GenericLevel_TvRat_12            = 12
%EnTvRat_GenericLevel_TvRat_13            = 13
%EnTvRat_GenericLevel_TvRat_14            = 14
%EnTvRat_GenericLevel_TvRat_15            = 15
%EnTvRat_GenericLevel_TvRat_16            = 16
%EnTvRat_GenericLevel_TvRat_17            = 17
%EnTvRat_GenericLevel_TvRat_18            = 18
%EnTvRat_GenericLevel_TvRat_19            = 19
%EnTvRat_GenericLevel_TvRat_20            = 20
%EnTvRat_GenericLevel_TvRat_21            = 21
%EnTvRat_GenericLevel_kLevels             = 22
%EnTvRat_GenericLevel_Unblock             = -1
%EnTvRat_GenericLevel_TvRat_LevelDontKnow = 255

' ========================================================================================
' EnTvRat_MPAA enum
' ========================================================================================

%EnTvRat_MPAA_NotApplicable   = %EnTvRat_GenericLevel_TvRat_0
%EnTvRat_MPAA_G               = %EnTvRat_GenericLevel_TvRat_1
%EnTvRat_MPAA_PG              = %EnTvRat_GenericLevel_TvRat_2
%EnTvRat_MPAA_PG13            = %EnTvRat_GenericLevel_TvRat_3
%EnTvRat_MPAA_R               = %EnTvRat_GenericLevel_TvRat_4
%EnTvRat_MPAA_NC17            = %EnTvRat_GenericLevel_TvRat_5
%EnTvRat_MPAA_X               = %EnTvRat_GenericLevel_TvRat_6
%EnTvRat_MPAA_NotRated        = %EnTvRat_GenericLevel_TvRat_7

' ========================================================================================
' EnTvRat_US_TV enum
' ========================================================================================

%EnTvRat_US_TV_None           = %EnTvRat_GenericLevel_TvRat_0
%EnTvRat_US_TV_Y              = %EnTvRat_GenericLevel_TvRat_1
%EnTvRat_US_TV_Y7             = %EnTvRat_GenericLevel_TvRat_2
%EnTvRat_US_TV_G              = %EnTvRat_GenericLevel_TvRat_3
%EnTvRat_US_TV_PG             = %EnTvRat_GenericLevel_TvRat_4
%EnTvRat_US_TV_14             = %EnTvRat_GenericLevel_TvRat_5
%EnTvRat_US_TV_MA             = %EnTvRat_GenericLevel_TvRat_6
%EnTvRat_US_TV_None7          = %EnTvRat_GenericLevel_TvRat_7

' ========================================================================================
' EnTvRat_CAE_TV enum
' ========================================================================================

%EnTvRat_CAE_TV_Exempt        = %EnTvRat_GenericLevel_TvRat_0
%EnTvRat_CAE_TV_C             = %EnTvRat_GenericLevel_TvRat_1
%EnTvRat_CAE_TV_C8            = %EnTvRat_GenericLevel_TvRat_2
%EnTvRat_CAE_TV_G             = %EnTvRat_GenericLevel_TvRat_3
%EnTvRat_CAE_TV_PG            = %EnTvRat_GenericLevel_TvRat_4
%EnTvRat_CAE_TV_14            = %EnTvRat_GenericLevel_TvRat_5
%EnTvRat_CAE_TV_18            = %EnTvRat_GenericLevel_TvRat_6
%EnTvRat_CAE_TV_Reserved      = %EnTvRat_GenericLevel_TvRat_7

' ========================================================================================
' EnTvRat_CAF_TV enum
' ========================================================================================

%EnTvRat_CAF_TV_Exempt        = %EnTvRat_GenericLevel_TvRat_0
%EnTvRat_CAF_TV_G             = %EnTvRat_GenericLevel_TvRat_1
%EnTvRat_CAF_TV_8             = %EnTvRat_GenericLevel_TvRat_2
%EnTvRat_CAF_TV_13            = %EnTvRat_GenericLevel_TvRat_3
%EnTvRat_CAF_TV_16            = %EnTvRat_GenericLevel_TvRat_4
%EnTvRat_CAF_TV_18            = %EnTvRat_GenericLevel_TvRat_5
%EnTvRat_CAF_TV_Reserved6     = %EnTvRat_GenericLevel_TvRat_6
%EnTvRat_CAF_TV_Reserved      = %EnTvRat_GenericLevel_TvRat_7

' ========================================================================================
' BfEnTvRat_GenericAttributes enum
' ========================================================================================

%BfEnTvRat_GenericAttributes_BfAttrNone           = 0
%BfEnTvRat_GenericAttributes_BfIsBlocked          = 1
%BfEnTvRat_GenericAttributes_BfIsAttr_1           = 2
%BfEnTvRat_GenericAttributes_BfIsAttr_2           = 4
%BfEnTvRat_GenericAttributes_BfIsAttr_3           = 8
%BfEnTvRat_GenericAttributes_BfIsAttr_4           = 16
%BfEnTvRat_GenericAttributes_BfIsAttr_5           = 32
%BfEnTvRat_GenericAttributes_BfIsAttr_6           = 64
%BfEnTvRat_GenericAttributes_BfIsAttr_7           = 128
%BfEnTvRat_GenericAttributes_BfValidAttrSubmask   = 255

' BfEnTvRat_Attributes_US_TV
%BfEnTvRat_Attributes_US_TV_IsBlocked                  = %BfEnTvRat_GenericAttributes_BfIsBlocked
%BfEnTvRat_Attributes_US_TV_IsViolent                  = %BfEnTvRat_GenericAttributes_BfIsAttr_1
%BfEnTvRat_Attributes_US_TV_IsSexualSituation          = %BfEnTvRat_GenericAttributes_BfIsAttr_2
%BfEnTvRat_Attributes_US_TV_IsAdultLanguage            = %BfEnTvRat_GenericAttributes_BfIsAttr_3
%BfEnTvRat_Attributes_US_TV_IsSexuallySuggestiveDialog = %BfEnTvRat_GenericAttributes_BfIsAttr_4
%BfEnTvRat_Attributes_US_TV_ValidAttrSubmask           = 31

' BfEnTvRat_Attributes_MPAA enum
%BfEnTvRat_Attributes_MPAA_IsBlocked        = %BfEnTvRat_GenericAttributes_BfIsBlocked
%BfEnTvRat_Attributes_MPAA_ValidAttrSubmask = 1

' BfEnTvRat_Attributes_CAE_TV
%BfEnTvRat_Attributes_CAE_IsBlocked         = %BfEnTvRat_GenericAttributes_BfIsBlocked
%BfEnTvRat_Attributes_CAE_ValidAttrSubmask  = 1

' BfEnTvRat_Attributes_CAF_TV enum
%BfEnTvRat_Attributes_CAF_IsBlocked         = %BfEnTvRat_GenericAttributes_BfIsBlocked
%BfEnTvRat_Attributes_CAF_ValidAttrSubmask  = 1


' ########################################################################################
' Interface name = IXDSToRat
' IID = C5C5C5B0-3ABC-11D6-B25B-00C04FA0C026
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IXDSToRat_INTERFACE_DEFINED)
    %IXDSToRat_INTERFACE_DEFINED = 1

$IID_IXDSToRat = GUID$("{C5C5C5B0-3ABC-11D6-B25B-00C04FA0C026}")

INTERFACE IXDSToRat $IID_IXDSToRat

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ParseXDSBytePair ( _                          ' VTable offset = 32
     BYVAL byte1 AS BYTE _                              ' __in BYTE byte1
   , BYVAL byte2 AS BYTE _                              ' __in BYTE byte2
   , BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnLevel AS LONG _                           ' __out EnTvRat_GenericLevel *pEnLevel
   , BYREF plBfEnAttributes AS LONG _                   ' __out LONG *plBfEnAttributes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXDSToRat_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEvalRat
' IID = C5C5C5B1-3ABC-11D6-B25B-00C04FA0C026
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEvalRat_INTERFACE_DEFINED)
    %IEvalRat_INTERFACE_DEFINED = 1

$IID_IEvalRat = GUID$("{C5C5C5B1-3ABC-11D6-B25B-00C04FA0C026}")

INTERFACE IEvalRat $IID_IEvalRat

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BlockedRatingAttributes ( _             ' VTable offset = 28
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   ) AS LONG                                            ' __retval_out LONG *plbfAttrs
   ' =====================================================================================
   PROPERTY SET BlockedRatingAttributes ( _             ' VTable offset = 32
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enLevel AS LONG _                            ' __in EnTvRat_GenericLevel enLevel
   , BYVAL lbfAttrs AS LONG _                           ' __in LONG lbfAttrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockUnRated ( _                        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *pfBlockUnRatedShows
   ' =====================================================================================
   PROPERTY SET BlockUnRated ( _                        ' VTable offset = 40
     BYVAL fBlockUnRatedShows AS LONG _                 ' __in BOOL fBlockUnRatedShows
   )                                                    ' void
   ' =====================================================================================
   METHOD MostRestrictiveRating ( _                     ' VTable offset = 44
     BYVAL enSystem1 AS LONG _                          ' __in EnTvRat_System enSystem1
   , BYVAL enEnLevel1 AS LONG _                         ' __in EnTvRat_GenericLevel enEnLevel1
   , BYVAL lbfEnAttr1 AS LONG _                         ' __in LONG lbfEnAttr1
   , BYVAL enSystem2 AS LONG _                          ' __in EnTvRat_System enSystem2
   , BYVAL enEnLevel2 AS LONG _                         ' __in EnTvRat_GenericLevel enEnLevel2
   , BYVAL lbfEnAttr2 AS LONG _                         ' __in LONG lbfEnAttr2
   , BYREF penSystem AS LONG _                          ' __out EnTvRat_System *penSystem
   , BYREF penEnLevel AS LONG _                         ' __out EnTvRat_GenericLevel *penEnLevel
   , BYREF plbfEnAttr AS LONG _                         ' __out LONG *plbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   METHOD TestRating ( _                                ' VTable offset = 48
     BYVAL enShowSystem AS LONG _                       ' __in EnTvRat_System enShowSystem
   , BYVAL enShowLevel AS LONG _                        ' __in EnTvRat_GenericLevel enShowLevel
   , BYVAL lbfEnShowAttributes AS LONG _                ' __in LONG lbfEnShowAttributes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEvalRat_INTERFACE_DEFINED__ */
