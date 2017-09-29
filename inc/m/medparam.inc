' ########################################################################################
' Microsoft Windows
' File: medparam.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MEDPARAM_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "strmif.inc"

'typedef float MP_DATA;

' enum MP_TYPE
%MPT_INT   = 0
%MPT_FLOAT = %MPT_INT   + 1
%MPT_BOOL  = %MPT_FLOAT + 1
%MPT_ENUM  = %MPT_BOOL  + 1
%MPT_MAX   = %MPT_ENUM  + 1

%MPBOOL_TRUE  = 1
%MPBOOL_FALSE = 0

' enum MP_CURVE_TYPE
%MP_CURVE_JUMP      = &H1
%MP_CURVE_LINEAR    = &H2
%MP_CURVE_SQUARE    = &H4
%MP_CURVE_INVSQUARE = &H8
%MP_CURVE_SINE      = &H10

'typedef DWORD MP_CAPS;

%MP_CAPS_CURVE_JUMP      = %MP_CURVE_JUMP
%MP_CAPS_CURVE_LINEAR    = %MP_CURVE_LINEAR
%MP_CAPS_CURVE_SQUARE    = %MP_CURVE_SQUARE
%MP_CAPS_CURVE_INVSQUARE = %MP_CURVE_INVSQUARE
%MP_CAPS_CURVE_SINE      = %MP_CURVE_SINE

' // Size = 148 bytes
TYPE MP_PARAMINFO DWORD
   mpType          AS LONG            ' MP_TYPE
   mopCaps         AS DWORD           ' MP_CAPS
   mpdMinValue     AS SINGLE          ' MP_DATA
   mpdMaxValue     AS SINGLE          ' MP_DATA
   mpdNeutralValue AS SINGLE          ' MP_DATA
   szUnitText      AS WSTRINGZ * 32   ' WCHAR[32]
   szLabel         AS WSTRINGZ * 32   ' WCHAR[32]
END TYPE

'typedef DWORD DWORD;

%DWORD_ALLPARAMS = -1

'typedef DWORD MP_TIMEDATA;

$GUID_TIME_REFERENCE = GUID$("{93ad712b-daa0-4ffe-bc81-b0ce500fcdd9}")
$GUID_TIME_MUSIC = GUID$("{0574c49d-5b04-4b15-a542-ae282030117b}")
$GUID_TIME_SAMPLES = GUID$("{a8593d05-0c43-4984-9a63-97af9e02c4c0}")

'typedef DWORD MP_FLAGS;

%MPF_ENVLP_STANDARD         = 0
%MPF_ENVLP_BEGIN_CURRENTVAL = &H1
%MPF_ENVLP_BEGIN_NEUTRALVAL = &H2

' // Size = 32 bytes
TYPE MP_ENVELOPE_SEGMENT   ' Must be 8 byte aligned
   rtStart  AS QUAD     ' REFERENCE_TIME
   rtEnd    AS QUAD     ' REFERENCE_TIME
   valStart AS SINGLE   ' MP_DATA
   valEnd   AS SINGLE   ' MP_DATA
   iCurve   AS LONG     ' MP_CURVE_TYPE
   flags    AS DWORD    ' MP_FLAGS
END TYPE

%MPF_PUNCHIN_REFTIME = 0
%MPF_PUNCHIN_NOW     = &H1
%MPF_PUNCHIN_STOPPED = &H2

' ########################################################################################
' IMediaParamInfo interface
' IID = 6d6cbb60-a223-44aa-842f-a2f06750be6d
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaParamInfo_INTERFACE_DEFINED)
    %IMediaParamInfo_INTERFACE_DEFINED = 1

$IID_IMediaParamInfo = GUID$("{6d6cbb60-a223-44aa-842f-a2f06750be6d}")

INTERFACE IMediaParamInfo $IID_IMediaParamInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParamCount ( _                             ' VTable offset = 12
     BYREF pdwParams AS DWORD _                         ' __out DWORD *pdwParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParamInfo ( _                              ' VTable offset = 16
     BYVAL dwParamIndex AS DWORD _                      ' __in DWORD dwParamIndex
   , BYREF pInfo AS MP_PARAMINFO _                      ' __out MP_PARAMINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParamText ( _                              ' VTable offset = 20
     BYVAL dwParamIndex AS DWORD _                      ' __in DWORD dwParamIndex
   , BYREF ppwchText AS DWORD _                         ' __out WCHAR **ppwchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumTimeFormats ( _                         ' VTable offset = 24
     BYREF pdwNumTimeFormats AS DWORD _                 ' __out DWORD *pdwNumTimeFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedTimeFormat ( _                    ' VTable offset = 28
     BYVAL dwFormatIndex AS DWORD _                     ' __in DWORD dwFormatIndex
   , BYREF pguidTimeFormat AS GUID _                    ' __out GUID *pguidTimeFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTimeFormat ( _                      ' VTable offset = 32
     BYREF pguidTimeFormat AS GUID _                    ' __out GUID *pguidTimeFormat
   , BYREF pTimeData AS DWORD _                         ' __out MP_TIMEDATA *pTimeData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaParamInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IMediaParams interface
' IID = 6d6cbb61-a223-44aa-842f-a2f06750be6e
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaParams_INTERFACE_DEFINED)
    %IMediaParams_INTERFACE_DEFINED = 1

$IID_IMediaParams = GUID$("{6d6cbb61-a223-44aa-842f-a2f06750be6e}")

INTERFACE IMediaParams $IID_IMediaParams

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParam ( _                                  ' VTable offset = 12
     BYVAL dwParamIndex AS DWORD _                      ' __in DWORD dwParamIndex
   , BYREF pValue AS SINGLE _                           ' __out MP_DATA *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParam ( _                                  ' VTable offset = 16
     BYVAL dwParamIndex AS DWORD _                      ' __in DWORD dwParamIndex
   , BYVAL value AS SINGLE _                            ' __out MP_DATA value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddEnvelope ( _                               ' VTable offset = 20
     BYVAL dwParamIndex AS DWORD _                      ' __in DWORD dwParamIndex
   , BYVAL cSegments AS DWORD _                         ' __in DWORD cSegments
   , BYREF pEnvelopeSegments AS MP_ENVELOPE_SEGMENT _   ' __in MP_ENVELOPE_SEGMENT *pEnvelopeSegments
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlushEnvelope ( _                             ' VTable offset = 24
     BYVAL dwParamIndex AS DWORD _                      ' __in DWORD dwParamIndex
   , BYVAL refTimeStart AS QUAD _                       ' __in REFERENCE_TIME refTimeStart
   , BYVAL refTimeEnd AS QUAD _                         ' __in REFERENCE_TIME refTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimeFormat ( _                             ' VTable offset = 28
     BYVAL guidTimeFormat AS GUID _                     ' __in GUID guidTimeFormat
   , BYVAL mpTimeData AS DWORD _                        ' __in MP_TIMEDATA mpTimeData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaParams_INTERFACE_DEFINED__ */
