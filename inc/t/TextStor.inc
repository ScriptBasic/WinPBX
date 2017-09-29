' ########################################################################################
' Microsoft Windows
' File: TextStor.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TEXTSTOR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$GUID_TS_SERVICE_DATAOBJECT = GUID$("{6086FBB5-E225-46CE-A770-C1BBD3E05D7B}")
$GUID_TS_SERVICE_ACCESSIBLE = GUID$("{F9786200-A5BF-4A0F-8C24-FB16F5D1AABB}")
$GUID_TS_SERVICE_ACTIVEX    = GUID$("{EA937A50-C9A6-4B7D-894A-49D99B784834}")

%TS_E_INVALIDPOS      = &H80040200???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200)
%TS_E_NOLOCK          = &H80040201???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0201)
%TS_E_NOOBJECT        = &H80040202???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0202)
%TS_E_NOSERVICE       = &H80040203???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0203)
%TS_E_NOINTERFACE     = &H80040204???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0204)
%TS_E_NOSELECTION     = &H80040205???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0205)
%TS_E_NOLAYOUT        = &H80040206???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0206)
%TS_E_INVALIDPOINT    = &H80040207???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0207)
%TS_E_SYNCHRONOUS     = &H80040208???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0208)
%TS_E_READONLY        = &H80040209???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0209)
%TS_E_FORMAT          = &H8004020A???   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x020a)
%TS_S_ASYNC           = &H00040300???   ' MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 0x0300)

%TS_AS_TEXT_CHANGE    = &H1
%TS_AS_SEL_CHANGE     = &H2
%TS_AS_LAYOUT_CHANGE  = &H4
%TS_AS_ATTR_CHANGE    = &H8
%TS_AS_STATUS_CHANGE  = &H10
%TS_AS_ALL_SINKS      = %TS_AS_TEXT_CHANGE OR %TS_AS_SEL_CHANGE OR %TS_AS_LAYOUT_CHANGE OR %TS_AS_ATTR_CHANGE OR %TS_AS_STATUS_CHANGE
%TS_LF_SYNC           = &H1
%TS_LF_READ           = &H2
%TS_LF_READWRITE      = &H6
%TS_SD_READONLY       = &H1
%TS_SD_LOADING        = &H2
%TS_SS_DISJOINTSEL    = &H1
%TS_SS_REGIONS        = &H2
%TS_SS_TRANSITORY     = &H4
%TS_SS_NOHIDDENTEXT   = &H8
%TS_SD_MASKALL        = %TS_SD_READONLY OR %TS_SD_LOADING
%TS_ST_CORRECTION     = &H1
%TS_IE_CORRECTION     = &H1
%TS_IE_COMPOSITION    = &H2
%TS_TC_CORRECTION     = &H1
%TS_IAS_NOQUERY       = &H1
%TS_IAS_QUERYONLY     = &H2

' GUID = "FEC4F516-C503-45B1-A5FD-7A3D8AB07049"
' // Size = 8 bytes
TYPE TS_STATUS DWORD
   dwDynamicFlags AS DWORD
   dwStaticFlags  AS DWORD
END TYPE

' GUID = "F3181BD6-BCF0-41D3-A81C-474B17EC38FB"
' // Size = 12 bytes
TYPE TS_TEXTCHANGE DWORD
   acpStart  AS LONG
   acpOldEnd AS LONG
   acpNewEnd AS LONG
END TYPE

' TsActiveSelEnd enum
' GUID = "05FCF85B-5E9C-4C3E-AB71-29471D4F38E7"
%TS_AE_NONE  = 0
%TS_AE_START = 1
%TS_AE_END   = 2

' GUID = "7ECC3FFA-8F73-4D91-98ED-76F8AC5B1600"
' // Size = 8 bytes
TYPE TS_SELECTIONSTYLE DWORD
   ase          AS LONG   ' TsActiveSelEnd enum
   fInterimChar AS LONG   ' BOOL
END TYPE

' GUID = "C4B9C33B-8A0D-4426-BEBE-D444A4701FE9"
' // Size = 16 bytes
TYPE TS_SELECTION_ACP DWORD
   acpStart AS LONG
   acpEnd   AS LONG
   style    AS TS_SELECTIONSTYLE
END TYPE

' GUID = "B03413D2-0723-4C4E-9E08-2E9C1FF3772B"
' // Size = 16 bytes
TYPE TS_SELECTION_ANCHOR DWORD
   paStart AS DWORD PTR   ' IAnchor*
   paEnd   AS DWORD PTR   ' IAnchor*
   style   AS TS_SELECTIONSTYLE
END TYPE

%TS_DEFAULT_SELECTION = &HFFFFFFFF???   ' ( ( ULONG  )-1 )
%GXFPF_ROUND_NEAREST  = &H1???
%GXFPF_NEAREST        = &H2???
%TS_CHAR_EMBEDDED     = &HFFFC???
%TS_CHAR_REGION       = 0???
%TS_CHAR_REPLACEMENT  = &HFFFD???

' GUID("ef3457d9-8446-49a7-a9e6-b50d9d5f3fd9")
' GUID TS_ATTRID;

' GUID = "2CC2B33F-1174-4507-B8D9-5BC0EB37C197"
' // Size = 40 bytes
TYPE TS_ATTRVAL DWORD     ' Must be 8 byte aligned
   idAttr      AS GUID    ' TS_ATTRID
   dwOverlapId AS DWORD
   alignment__ AS DWORD
   varValue    AS tagVARIANT
END TYPE

%TS_ATTR_FIND_BACKWARDS   = &H1
%TS_ATTR_FIND_WANT_OFFSET = &H2
%TS_ATTR_FIND_UPDATESTART = &H4
%TS_ATTR_FIND_WANT_VALUE  = &H8
%TS_ATTR_FIND_WANT_END    = &H10
%TS_ATTR_FIND_HIDDEN      = &H20

'typedef /* [uuid] */  DECLSPEC_UUID("1faf509e-44c1-458e-950a-38a96705a62b") DWORD TsViewCookie;

%TS_VCOOKIE_NUL           = &HFFFFFFFF???

' GUID = "7899D7C4-5F07-493C-A89A-FAC8E777F476"
' TsLayoutCode enum
%TS_LC_CREATE  = 0
%TS_LC_CHANGE  = 1
%TS_LC_DESTROY = 2

' GUID = "033B0DF0-F193-4170-B47B-141AFC247878"
' TsRunType enum
%TS_RT_PLAIN  = 0
%TS_RT_HIDDEN = %TS_RT_PLAIN + 1
%TS_RT_OPAQUE = %TS_RT_HIDDEN + 1

' GUID = "A6231949-37C5-4B74-A24E-2A26C327201D"
' // Size = 8 bytes
TYPE TS_RUNINFO DWORD
   uCount AS DWORD   ' ULONG
   type   AS LONG    ' TsRunType enum
END TYPE


' ########################################################################################
' Interface name = ITextStoreACP
' IID = 28888FE3-C2A0-483A-A3EA-8CB1CE51FF3D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreACP_INTERFACE_DEFINED)
    %ITextStoreACP_INTERFACE_DEFINED = 1

$IID_ITextStoreACP = GUID$("{28888FE3-C2A0-483A-A3EA-8CB1CE51FF3D}")

INTERFACE ITextStoreACP $IID_ITextStoreACP

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AdviseSink ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnadviseSink ( _                              ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestLock ( _                               ' VTable offset = 20
     BYVAL dwLockFlags AS DWORD _                       ' __in DWORD dwLockFlags
   , BYREF phrSession AS LONG _                         ' __out HRESULT *phrSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF pdcs AS TS_STATUS _                          ' __out TS_STATUS *pdcs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInsert ( _                               ' VTable offset = 28
     BYVAL acpTestStart AS LONG _                       ' __in LONG acpTestStart
   , BYVAL acpTestEnd AS LONG _                         ' __in LONG acpTestEnd
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF pacpResultStart AS LONG _                    ' __out LONG *pacpResultStart
   , BYREF pacpResultEnd AS LONG _                      ' __out LONG *pacpResultEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 32
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pSelection AS TS_SELECTION_ACP _             ' __out TS_SELECTION_ACP *pSelection
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelection ( _                              ' VTable offset = 36
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pSelection AS TS_SELECTION_ACP _             ' __in const TS_SELECTION_ACP *pSelection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 40
     BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYREF pchPlain AS WSTRINGZ _                       ' __out WCHAR *pchPlain
   , BYVAL cchPlainReq AS DWORD _                       ' __in ULONG cchPlainReq
   , BYREF pcchPlainRet AS DWORD _                      ' __out ULONG *pcchPlainRet
   , BYREF prgRunInfo AS TS_RUNINFO _                   ' __out TS_RUNINFO *prgRunInfo
   , BYVAL cRunInfoReq AS DWORD _                       ' __in ULONG cRunInfoReq
   , BYREF pcRunInfoRet AS DWORD _                      ' __out ULONG *pcRunInfoRet
   , BYREF pacpNext AS LONG _                           ' __out LONG *pacpNext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYREF pchText AS WSTRINGZ _                        ' __in const WCHAR *pchText
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF pChange AS TS_TEXTCHANGE _                   ' __out TS_TEXTCHANGE *pChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormattedText ( _                          ' VTable offset = 48
     BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYREF ppDataObject AS IDataObject _                ' __out IDataObject **ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEmbedded ( _                               ' VTable offset = 52
     BYVAL acpPos AS LONG _                             ' __in LONG acpPos
   , BYREF rguidService AS GUID _                       ' __in REFGUID rguidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInsertEmbedded ( _                       ' VTable offset = 56
     BYREF pguidService AS GUID _                       ' __in const GUID *pguidService
   , BYREF pFormatEtc AS FORMATETC _                    ' __in const FORMATETC *pFormatEtc
   , BYREF pfInsertable AS LONG _                       ' __out BOOL *pfInsertable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertEmbedded ( _                            ' VTable offset = 60
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL acpStart AS DWORD _                          ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   , BYREF pChange AS TS_TEXTCHANGE _                   ' __out TS_TEXTCHANGE *pChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertTextAtSelection ( _                     ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pchText AS WSTRINGZ _                        ' __in const WCHAR *pchText
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF pacpStart AS LONG _                          ' __out LONG *pacpStart
   , BYREF pacpEnd AS LONG _                            ' __out LONG *pacpEnd
   , BYREF pChange AS TS_TEXTCHANGE _                   ' __out TS_TEXTCHANGE *pChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertEmbeddedAtSelection ( _                 ' VTable offset = 68
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   , BYREF pacpStart AS LONG _                          ' __out LONG *pacpStart
   , BYREF pacpEnd AS LONG _                            ' __out LONG *pacpEnd
   , BYREF pChange AS TS_TEXTCHANGE _                   ' __out TS_TEXTCHANGE *pChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestSupportedAttrs ( _                     ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestAttrsAtPosition ( _                    ' VTable offset = 76
     BYVAL acpPos AS LONG _                             ' __in LONG acpPos
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestAttrsTransitioningAtPosition ( _       ' VTable offset = 80
     BYVAL acpPos AS LONG _                             ' __in LONG acpPos
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNextAttrTransition ( _                    ' VTable offset = 84
     BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpHalt AS LONG _                            ' __in LONG acpHalt
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pacpNext AS LONG _                           ' __out LONG *pacpNext
   , BYREF pfFound AS LONG _                            ' __out BOOL *pfFound
   , BYREF plFoundOffset AS LONG _                      ' __out LONG *plFoundOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RetrieveRequestedAttrs ( _                    ' VTable offset = 88
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF paAttrVals AS TS_ATTRVAL _                   ' __out TS_ATTRVAL *paAttrVals
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEndACP ( _                                 ' VTable offset = 92
     BYREF pacp AS LONG _                               ' __out LONG *pacp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveView ( _                             ' VTable offset = 96
     BYREF pvcView AS DWORD _                           ' __out TsViewCookie *pvcView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetACPFromPoint ( _                           ' VTable offset = 100
     BYREF pvcView AS DWORD _                           ' __out TsViewCookie *pvcView
   , BYREF ptScreen AS POINT _                          ' __in const POINT *ptScreen
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pacp AS LONG _                               ' __out LONG *pacp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextExt ( _                                ' VTable offset = 104
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYREF prc AS RECT _                                ' __out RECT *prc
   , BYREF pfClipped AS LONG _                          ' __out BOOL *pfClipped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScreenExt ( _                              ' VTable offset = 108
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYREF prc AS RECT _                                ' __out RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWnd ( _                                    ' VTable offset = 112
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreACP_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITextStoreACPSink
' IID = 22D44C94-A419-4542-A272-AE26093ECECF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreACPSink_INTERFACE_DEFINED)
    %ITextStoreACPSink_INTERFACE_DEFINED = 1

$IID_ITextStoreACPSink = GUID$("{22D44C94-A419-4542-A272-AE26093ECECF}")

INTERFACE ITextStoreACPSink $IID_ITextStoreACPSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTextChange ( _                              ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pChange AS TS_TEXTCHANGE _                   ' __in const TS_TEXTCHANGE *pChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSelectionChange ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLayoutChange ( _                            ' VTable offset = 20
     BYVAL lcode AS LONG _                              ' __in TsLayoutCode lcode
   , BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStatusChange ( _                            ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAttrsChange ( _                             ' VTable offset = 28
     BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYVAL cAttrs AS DWORD _                            ' __in ULONG cAttrs
   , BYREF paAttrs AS GUID _                            ' __in const TS_ATTRID *paAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLockGranted ( _                             ' VTable offset = 32
     BYVAL dwLockFlags AS DWORD _                       ' __in DWORD dwLockFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStartEditTransaction ( _                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEndEditTransaction ( _                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreACPSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAnchor
' IID = 0FEB7E34-5A60-4356-8EF7-ABDEC2FF7CF8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnchor_INTERFACE_DEFINED)
    %IAnchor_INTERFACE_DEFINED = 1

' TsGravity enum
' GUID = "DAA8601E-7695-426F-9BB7-498A6AA64B68"
%TS_GR_BACKWARD = 0
%TS_GR_FORWARD  = 1

' TsShiftDir enum
' GUID = "898E19DF-4FB4-4AF3-8DAF-9B3C1145C79D"
%TS_SD_BACKWARD = 0
%TS_SD_FORWARD  = 1

%TS_CH_PRECEDING_DEL   = 1
%TS_CH_FOLLOWING_DEL   = 2
%TS_SHIFT_COUNT_HIDDEN = &H1
%TS_SHIFT_HALT_HIDDEN  = &H2
%TS_SHIFT_HALT_VISIBLE = &H4
%TS_SHIFT_COUNT_ONLY   = &H8

$IID_IAnchor = GUID$("{0FEB7E34-5A60-4356-8EF7-ABDEC2FF7CF8}")

INTERFACE IAnchor $IID_IAnchor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGravity ( _                                ' VTable offset = 12
      BYVAL gravity AS LONG _                           ' __in TsGravity gravity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGravity ( _                                ' VTable offset = 16
      BYREF pgravity AS LONG _                          ' __out TsGravity *pgravity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 20
     BYVAL paWith AS IAnchor _                          ' __in IAnchor *paWith
   , BYREF pfEqual AS LONG _                            ' __out BOOL *pfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL paWith AS IAnchor _                          ' __in IAnchor *paWith
   , BYREF plResult AS LONG _                           ' __out LONG *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shift ( _                                     ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cchReq AS LONG _                             ' __in LONG cchReq
   , BYREF pcch AS LONG _                               ' __out LONG *pcch
   , BYVAL paHaltAnchor AS IAnchor _                    ' __in IAnchor *paHaltAnchor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShiftTo ( _                                   ' VTable offset = 32
     BYVAL paSite AS IAnchor _                          ' __in IAnchor *paSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShiftRegion ( _                               ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dir AS LONG _                                ' __in TsShiftDir dir
   , BYREF pfNoRegion AS LONG _                         ' __out BOOL *pfNoRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChangeHistoryMask ( _                      ' VTable offset = 40
     BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChangeHistory ( _                          ' VTable offset = 44
     BYREF pdwHistory AS DWORD _                        ' __out DWORD *pdwHistory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearChangeHistory ( _                        ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppaClone AS IAnchor _                        ' __out IAnchor **ppaClone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnchor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITextStoreAnchor
' IID = 9B2077B0-5F18-4DEC-BEE9-3CC722F5DFE0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreAnchor_INTERFACE_DEFINED)
    %ITextStoreAnchor_INTERFACE_DEFINED = 1

%TS_GTA_HIDDEN = &H1
%TS_GEA_HIDDEN = &H1

$IID_ITextStoreAnchor = GUID$("{9B2077B0-5F18-4DEC-BEE9-3CC722F5DFE0}")

INTERFACE ITextStoreAnchor $IID_ITextStoreAnchor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AdviseSink ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnadviseSink ( _                              ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestLock ( _                               ' VTable offset = 20
     BYVAL dwLockFlags AS DWORD _                       ' __in DWORD dwLockFlags
   , BYREF phrSession AS LONG _                         ' __out HRESULT *phrSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF pdcs AS TS_STATUS _                          ' __out TS_STATUS *pdcs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInsert ( _                               ' VTable offset = 28
     BYVAL paTestStart AS IAnchor _                     ' __in IAnchor *paTestStart
   , BYVAL paTestEnd AS IAnchor _                       ' __in IAnchor *paTestEnd
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF ppaResultStart AS IAnchor _                  ' __out IAnchor **ppaResultStart
   , BYREF ppaResultEnd AS IAnchor _                    ' __out IAnchor **ppaResultEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 32
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pSelection AS TS_SELECTION_ANCHOR _          ' __out TS_SELECTION_ANCHOR *pSelection
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelection ( _                              ' VTable offset = 36
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pSelection AS TS_SELECTION_ANCHOR _          ' __in const TS_SELECTION_ANCHOR *pSelection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   , BYREF pchText AS WSTRINGZ _                        ' __out WCHAR *pchText
   , BYVAL cchReq AS DWORD _                            ' __in ULONG cchReq
   , BYREF pcch AS DWORD _                              ' __out ULONG *pcch
   , BYVAL fUpdateAnchor AS LONG _                      ' __in BOOL fUpdateAnchor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   , BYREF pchText AS WSTRINGZ _                        ' __in const WCHAR *pchText
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormattedText ( _                          ' VTable offset = 48
     BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   , BYREF ppDataObject AS IDataObject _                ' __out IDataObject **ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEmbedded ( _                               ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL paPos AS IAnchor _                           ' __in IAnchor *paPos
   , BYREF rguidService AS GUID _                       ' __in REFGUID rguidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertEmbedded ( _                            ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestSupportedAttrs ( _                     ' VTable offset = 60
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestAttrsAtPosition ( _                    ' VTable offset = 64
     BYVAL paPos AS IAnchor _                           ' __in IAnchor *paPos
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestAttrsTransitioningAtPosition ( _       ' VTable offset = 68
     BYVAL paPos AS IAnchor _                           ' __in IAnchor *paPos
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNextAttrTransition ( _                    ' VTable offset = 72
     BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paHalt AS IAnchor _                          ' __in IAnchor *paHalt
   , BYVAL cFilterAttrs AS DWORD _                      ' __in ULONG cFilterAttrs
   , BYREF paFilterAttrs AS GUID _                      ' __in const TS_ATTRID *paFilterAttrs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pfFound AS LONG _                            ' __out BOOL *pfFound
   , BYREF plFoundOffset AS LONG _                      ' __out LONG *plFoundOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RetrieveRequestedAttrs ( _                    ' VTable offset = 76
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF paAttrVals AS TS_ATTRVAL _                   ' __out TS_ATTRVAL *paAttrVals
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStart ( _                                  ' VTable offset = 80
     BYREF ppaStart AS IAnchor _                        ' __out IAnchor **ppaStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnd ( _                                    ' VTable offset = 84
     BYREF ppaEnd AS IAnchor _                          ' __out IAnchor **ppaEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveView ( _                             ' VTable offset = 88
     BYREF pvcView AS DWORD _                           ' __out TsViewCookie *pvcView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnchorFromPoint ( _                        ' VTable offset = 92
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYREF ptScreen AS POINT _                          ' __in const POINT *ptScreen
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppaSite AS IAnchor _                         ' __out IAnchor **ppaSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextExt ( _                                ' VTable offset = 96
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   , BYREF prc AS RECT _                                ' __out RECT *prc
   , BYREF pfClipped AS LONG _                          ' __out BOOL *pfClipped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScreenExt ( _                              ' VTable offset = 100
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYREF prc AS RECT _                                ' __out RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWnd ( _                                    ' VTable offset = 104
     BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInsertEmbedded ( _                       ' VTable offset = 108
     BYREF pguidService AS GUID _                       ' __in const GUID *pguidService
   , BYREF pFormatEtc AS FORMATETC _                    ' __in const FORMATETC *pFormatEtc
   , BYREF pfInsertable AS LONG _                       ' __out BOOL *pfInsertable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertTextAtSelection ( _                     ' VTable offset = 112
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pchText AS WSTRINGZ _                        ' __in const WCHAR *pchText
   , BYVAL cch AS DWORD _                               ' __in ULONG cch
   , BYREF ppaStart AS IAnchor _                        ' __out IAnchor **ppaStart
   , BYREF ppaEnd AS IAnchor _                          ' __out IAnchor **ppaEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertEmbeddedAtSelection ( _                 ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject *pDataObject
   , BYREF ppaStart AS IAnchor _                        ' __out IAnchor **ppaStart
   , BYREF ppaEnd AS IAnchor _                          ' __out IAnchor **ppaEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreAnchor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITextStoreAnchorSink
' IID = AA80E905-2021-11D2-93E0-0060B067B86E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreAnchorSink_INTERFACE_DEFINED)
    %ITextStoreAnchorSink_INTERFACE_DEFINED = 1

$IID_ITextStoreAnchorSink = GUID$("{AA80E905-2021-11D2-93E0-0060B067B86E}")

INTERFACE ITextStoreAnchorSink $IID_ITextStoreAnchorSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTextChange ( _                              ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSelectionChange ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLayoutChange ( _                            ' VTable offset = 20
     BYVAL lcode AS LONG _                              ' __in TsLayoutCode lcode
   , BYVAL vcView AS DWORD _                            ' __in TsViewCookie vcView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStatusChange ( _                            ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAttrsChange ( _                             ' VTable offset = 28
     BYVAL paStart AS IAnchor _                         ' __in IAnchor *paStart
   , BYVAL paEnd AS IAnchor _                           ' __in IAnchor *paEnd
   , BYVAL cAttrs AS DWORD _                            ' __in ULONG cAttrs
   , BYREF paAttrs AS GUID _                            ' __in const TS_ATTRID *paAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLockGranted ( _                             ' VTable offset = 32
     BYVAL dwLockFlags AS DWORD _                       ' __in DWORD dwLockFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStartEditTransaction ( _                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEndEditTransaction ( _                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreAnchorSink_INTERFACE_DEFINED__ */
