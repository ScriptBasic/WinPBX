' ########################################################################################
' Microsoft Windows
' File: NSPlay.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: NSPlay
' Version: 1.0
' Documentation string: Microsoft NetShow Player
' Path: C:\WINDOWS\system32\nscompat.tlb
' Library GUID: {2179C5D0-EBFF-11CF-B6FD-00AA00B4E220}
' ########################################################################################

#INCLUDE THIS ONCE
%NSPLAY_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {2179C5D3-EBFF-11CF-B6FD-00AA00B4E220}
$PROGID_NSPlayNSPlayCtl1 = "NSPlay.NSPlayCtl.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {2179C5D3-EBFF-11CF-B6FD-00AA00B4E220}
$PROGID_NSPlayNSPlayCtl = "NSPlay.NSPlayCtl"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_NSPlay = GUID$("{2179C5D3-EBFF-11CF-B6FD-00AA00B4E220}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DNSOPlayEvents = GUID$("{2179C5D2-EBFF-11CF-B6FD-00AA00B4E220}")
$IID_DNSPlayEvents = GUID$("{E7C4BE81-7960-11D0-B727-00AA00B4E220}")
$IID_INSOPlay = GUID$("{2179C5D1-EBFF-11CF-B6FD-00AA00B4E220}")
$IID_INSPlay = GUID$("{E7C4BE80-7960-11D0-B727-00AA00B4E220}")
$IID_INSPlay1 = GUID$("{265EC141-AE62-11D1-8500-00A0C91F9CA0}")

' ########################################################################################
' Interface name = INSOPlay
' IID = {2179C5D1-EBFF-11CF-B6FD-00AA00B4E220}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INSOPlay_INTERFACE_DEFINED)
    %INSOPlay_INTERFACE_DEFINED = 1

INTERFACE INSOPlay $IID_INSOPlay

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ImageSourceWidth <1001> ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pWidth
   ' =====================================================================================
   PROPERTY GET ImageSourceHeight <1002> ( _            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pHeight
   ' =====================================================================================
   PROPERTY GET Duration <1003> ( _                     ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double* pDuration
   ' =====================================================================================
   PROPERTY GET Author <1004> ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrAuthor
   ' =====================================================================================
   PROPERTY GET Copyright <1005> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCopyright
   ' =====================================================================================
   PROPERTY GET Description <1006> ( _                  ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDescription
   ' =====================================================================================
   PROPERTY GET Rating <1007> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrRating
   ' =====================================================================================
   PROPERTY GET Title <1008> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   PROPERTY GET SourceLink <1009> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSourceLink
   ' =====================================================================================
   PROPERTY GET MarkerCount <1010> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* pMarkerCount
   ' =====================================================================================
   PROPERTY GET CanScan <1011> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanScan
   ' =====================================================================================
   PROPERTY GET CanSeek <1012> ( _                      ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanSeek
   ' =====================================================================================
   PROPERTY GET CanSeekToMarkers <1047> ( _             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanSeekToMarkers
   ' =====================================================================================
   PROPERTY GET CreationDate <1036> ( _                 ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE* pCreationDate
   ' =====================================================================================
   PROPERTY GET Bandwidth <1037> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* pBandwidth
   ' =====================================================================================
   PROPERTY GET ErrorCorrection <1038> ( _              ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrErrorCorrection
   ' =====================================================================================
   PROPERTY GET AutoStart <1017> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAutoStart
   ' =====================================================================================
   PROPERTY SET AutoStart <1017> ( _                    ' VTable offset = 96
     BYVAL pAutoStart AS INTEGER _                      ' __in VARIANT_BOOL pAutoStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoRewind <1018> ( _                   ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAutoRewind
   ' =====================================================================================
   PROPERTY SET AutoRewind <1018> ( _                   ' VTable offset = 104
     BYVAL pAutoRewind AS INTEGER _                     ' __in VARIANT_BOOL pAutoRewind
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowChangeControlType <1019> ( _       ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowChangeControlType
   ' =====================================================================================
   PROPERTY SET AllowChangeControlType <1019> ( _       ' VTable offset = 112
     BYVAL pAllowChangeControlType AS INTEGER _         ' __in VARIANT_BOOL pAllowChangeControlType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InvokeURLs <1020> ( _                   ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pInvokeURLs
   ' =====================================================================================
   PROPERTY SET InvokeURLs <1020> ( _                   ' VTable offset = 120
     BYVAL pInvokeURLs AS INTEGER _                     ' __in VARIANT_BOOL pInvokeURLs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableContextMenu <1021> ( _            ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableContextMenu
   ' =====================================================================================
   PROPERTY SET EnableContextMenu <1021> ( _            ' VTable offset = 128
     BYVAL pEnableContextMenu AS INTEGER _              ' __in VARIANT_BOOL pEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransparentAtStart <1022> ( _           ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pTransparentAtStart
   ' =====================================================================================
   PROPERTY SET TransparentAtStart <1022> ( _           ' VTable offset = 136
     BYVAL pTransparentAtStart AS INTEGER _             ' __in VARIANT_BOOL pTransparentAtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransparentOnStop <1023> ( _            ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pTransparentOnStop
   ' =====================================================================================
   PROPERTY SET TransparentOnStop <1023> ( _            ' VTable offset = 144
     BYVAL pTransparentOnStop AS INTEGER _              ' __in VARIANT_BOOL pTransparentOnStop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClickToPlay <1025> ( _                  ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pClickToPlay
   ' =====================================================================================
   PROPERTY SET ClickToPlay <1025> ( _                  ' VTable offset = 152
     BYVAL pClickToPlay AS INTEGER _                    ' __in VARIANT_BOOL pClickToPlay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <1026> ( _                     ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <1026> ( _                     ' VTable offset = 160
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <1027> ( _              ' VTable offset = 164
   ) AS DOUBLE                                          ' __retval_out double* pCurrentPosition
   ' =====================================================================================
   PROPERTY SET CurrentPosition <1027> ( _              ' VTable offset = 168
     BYVAL pCurrentPosition AS DOUBLE _                 ' __in double pCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <1028> ( _                         ' VTable offset = 172
   ) AS DOUBLE                                          ' __retval_out double* pRate
   ' =====================================================================================
   PROPERTY SET Rate <1028> ( _                         ' VTable offset = 176
     BYVAL pRate AS DOUBLE _                            ' __in double pRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentMarker <1029> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out long* pCurrentMarker
   ' =====================================================================================
   PROPERTY SET CurrentMarker <1029> ( _                ' VTable offset = 184
     BYVAL pCurrentMarker AS LONG _                     ' __in long pCurrentMarker
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayCount <1030> ( _                    ' VTable offset = 188
   ) AS LONG                                            ' __retval_out long* pPlayCount
   ' =====================================================================================
   PROPERTY SET PlayCount <1030> ( _                    ' VTable offset = 192
     BYVAL pPlayCount AS LONG _                         ' __in long pPlayCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentState <1031> ( _                 ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long* pCurrentState
   ' =====================================================================================
   PROPERTY GET DisplaySize <1032> ( _                  ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long* pDisplaySize
   ' =====================================================================================
   PROPERTY SET DisplaySize <1032> ( _                  ' VTable offset = 204
     BYVAL pDisplaySize AS LONG _                       ' __in long pDisplaySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MainWindow <1033> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long* pMainWindow
   ' =====================================================================================
   PROPERTY GET ControlType <1034> ( _                  ' VTable offset = 212
   ) AS LONG                                            ' __retval_out long* pControlType
   ' =====================================================================================
   PROPERTY SET ControlType <1034> ( _                  ' VTable offset = 216
     BYVAL pControlType AS LONG _                       ' __in long pControlType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowScan <1035> ( _                    ' VTable offset = 220
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowScan
   ' =====================================================================================
   PROPERTY SET AllowScan <1035> ( _                    ' VTable offset = 224
     BYVAL pAllowScan AS INTEGER _                      ' __in VARIANT_BOOL pAllowScan
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendKeyboardEvents <1013> ( _           ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendKeyboardEvents
   ' =====================================================================================
   PROPERTY SET SendKeyboardEvents <1013> ( _           ' VTable offset = 232
     BYVAL pSendKeyboardEvents AS INTEGER _             ' __in VARIANT_BOOL pSendKeyboardEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendMouseClickEvents <1014> ( _         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendMouseClickEvents
   ' =====================================================================================
   PROPERTY SET SendMouseClickEvents <1014> ( _         ' VTable offset = 240
     BYVAL pSendMouseClickEvents AS INTEGER _           ' __in VARIANT_BOOL pSendMouseClickEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendMouseMoveEvents <1015> ( _          ' VTable offset = 244
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendMouseMoveEvents
   ' =====================================================================================
   PROPERTY SET SendMouseMoveEvents <1015> ( _          ' VTable offset = 248
     BYVAL pSendMouseMoveEvents AS INTEGER _            ' __in VARIANT_BOOL pSendMouseMoveEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendStateChangeEvents <1016> ( _        ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendStateChangeEvents <1016> ( _        ' VTable offset = 256
     BYVAL pSendStateChangeEvents AS INTEGER _          ' __in VARIANT_BOOL pSendStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedPackets <1039> ( _              ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long* pReceivedPackets
   ' =====================================================================================
   PROPERTY GET RecoveredPackets <1040> ( _             ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long* pRecoveredPackets
   ' =====================================================================================
   PROPERTY GET LostPackets <1041> ( _                  ' VTable offset = 268
   ) AS LONG                                            ' __retval_out long* pLostPackets
   ' =====================================================================================
   PROPERTY GET ReceptionQuality <1042> ( _             ' VTable offset = 272
   ) AS LONG                                            ' __retval_out long* pReceptionQuality
   ' =====================================================================================
   PROPERTY GET BufferingCount <1043> ( _               ' VTable offset = 276
   ) AS LONG                                            ' __retval_out long* pBufferingCount
   ' =====================================================================================
   PROPERTY GET CursorType <1044> ( _                   ' VTable offset = 280
   ) AS LONG                                            ' __retval_out long* pCursorType
   ' =====================================================================================
   PROPERTY SET CursorType <1044> ( _                   ' VTable offset = 284
     BYVAL pCursorType AS LONG _                        ' __in long pCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnimationAtStart <1045> ( _             ' VTable offset = 288
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAnimationAtStart
   ' =====================================================================================
   PROPERTY SET AnimationAtStart <1045> ( _             ' VTable offset = 292
     BYVAL pAnimationAtStart AS INTEGER _               ' __in VARIANT_BOOL pAnimationAtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnimationOnStop <1046> ( _              ' VTable offset = 296
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAnimationOnStop
   ' =====================================================================================
   PROPERTY SET AnimationOnStop <1046> ( _              ' VTable offset = 300
     BYVAL pAnimationOnStop AS INTEGER _                ' __in VARIANT_BOOL pAnimationOnStop
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <2001> ( _                               ' VTable offset = 304
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <2002> ( _                              ' VTable offset = 308
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <2003> ( _                               ' VTable offset = 312
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMarkerTime <2004> ( _                      ' VTable offset = 316
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS DOUBLE                                          ' __retval_out double* pMarkerTime
   ' =====================================================================================
   METHOD GetMarkerName <2005> ( _                      ' VTable offset = 320
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrMarkerName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INSOPlay_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INSPlay
' IID = {E7C4BE80-7960-11D0-B727-00AA00B4E220}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = INSOPlay
' ########################################################################################

#IF NOT %DEF(%INSPlay_INTERFACE_DEFINED)
    %INSPlay_INTERFACE_DEFINED = 1

INTERFACE INSPlay $IID_INSPlay

   INHERIT IDispatch

   ' =====================================================================================
   ' INSOPlay Methods
   ' =====================================================================================
   PROPERTY GET ImageSourceWidth <1001> ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pWidth
   ' =====================================================================================
   PROPERTY GET ImageSourceHeight <1002> ( _            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pHeight
   ' =====================================================================================
   PROPERTY GET Duration <1003> ( _                     ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double* pDuration
   ' =====================================================================================
   PROPERTY GET Author <1004> ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrAuthor
   ' =====================================================================================
   PROPERTY GET Copyright <1005> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCopyright
   ' =====================================================================================
   PROPERTY GET Description <1006> ( _                  ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDescription
   ' =====================================================================================
   PROPERTY GET Rating <1007> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrRating
   ' =====================================================================================
   PROPERTY GET Title <1008> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   PROPERTY GET SourceLink <1009> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSourceLink
   ' =====================================================================================
   PROPERTY GET MarkerCount <1010> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* pMarkerCount
   ' =====================================================================================
   PROPERTY GET CanScan <1011> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanScan
   ' =====================================================================================
   PROPERTY GET CanSeek <1012> ( _                      ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanSeek
   ' =====================================================================================
   PROPERTY GET CanSeekToMarkers <1047> ( _             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanSeekToMarkers
   ' =====================================================================================
   PROPERTY GET CreationDate <1036> ( _                 ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE* pCreationDate
   ' =====================================================================================
   PROPERTY GET Bandwidth <1037> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* pBandwidth
   ' =====================================================================================
   PROPERTY GET ErrorCorrection <1038> ( _              ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrErrorCorrection
   ' =====================================================================================
   PROPERTY GET AutoStart <1017> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAutoStart
   ' =====================================================================================
   PROPERTY SET AutoStart <1017> ( _                    ' VTable offset = 96
     BYVAL pAutoStart AS INTEGER _                      ' __in VARIANT_BOOL pAutoStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoRewind <1018> ( _                   ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAutoRewind
   ' =====================================================================================
   PROPERTY SET AutoRewind <1018> ( _                   ' VTable offset = 104
     BYVAL pAutoRewind AS INTEGER _                     ' __in VARIANT_BOOL pAutoRewind
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowChangeControlType <1019> ( _       ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowChangeControlType
   ' =====================================================================================
   PROPERTY SET AllowChangeControlType <1019> ( _       ' VTable offset = 112
     BYVAL pAllowChangeControlType AS INTEGER _         ' __in VARIANT_BOOL pAllowChangeControlType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InvokeURLs <1020> ( _                   ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pInvokeURLs
   ' =====================================================================================
   PROPERTY SET InvokeURLs <1020> ( _                   ' VTable offset = 120
     BYVAL pInvokeURLs AS INTEGER _                     ' __in VARIANT_BOOL pInvokeURLs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableContextMenu <1021> ( _            ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableContextMenu
   ' =====================================================================================
   PROPERTY SET EnableContextMenu <1021> ( _            ' VTable offset = 128
     BYVAL pEnableContextMenu AS INTEGER _              ' __in VARIANT_BOOL pEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransparentAtStart <1022> ( _           ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pTransparentAtStart
   ' =====================================================================================
   PROPERTY SET TransparentAtStart <1022> ( _           ' VTable offset = 136
     BYVAL pTransparentAtStart AS INTEGER _             ' __in VARIANT_BOOL pTransparentAtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransparentOnStop <1023> ( _            ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pTransparentOnStop
   ' =====================================================================================
   PROPERTY SET TransparentOnStop <1023> ( _            ' VTable offset = 144
     BYVAL pTransparentOnStop AS INTEGER _              ' __in VARIANT_BOOL pTransparentOnStop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClickToPlay <1025> ( _                  ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pClickToPlay
   ' =====================================================================================
   PROPERTY SET ClickToPlay <1025> ( _                  ' VTable offset = 152
     BYVAL pClickToPlay AS INTEGER _                    ' __in VARIANT_BOOL pClickToPlay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <1026> ( _                     ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <1026> ( _                     ' VTable offset = 160
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <1027> ( _              ' VTable offset = 164
   ) AS DOUBLE                                          ' __retval_out double* pCurrentPosition
   ' =====================================================================================
   PROPERTY SET CurrentPosition <1027> ( _              ' VTable offset = 168
     BYVAL pCurrentPosition AS DOUBLE _                 ' __in double pCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <1028> ( _                         ' VTable offset = 172
   ) AS DOUBLE                                          ' __retval_out double* pRate
   ' =====================================================================================
   PROPERTY SET Rate <1028> ( _                         ' VTable offset = 176
     BYVAL pRate AS DOUBLE _                            ' __in double pRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentMarker <1029> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out long* pCurrentMarker
   ' =====================================================================================
   PROPERTY SET CurrentMarker <1029> ( _                ' VTable offset = 184
     BYVAL pCurrentMarker AS LONG _                     ' __in long pCurrentMarker
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayCount <1030> ( _                    ' VTable offset = 188
   ) AS LONG                                            ' __retval_out long* pPlayCount
   ' =====================================================================================
   PROPERTY SET PlayCount <1030> ( _                    ' VTable offset = 192
     BYVAL pPlayCount AS LONG _                         ' __in long pPlayCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentState <1031> ( _                 ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long* pCurrentState
   ' =====================================================================================
   PROPERTY GET DisplaySize <1032> ( _                  ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long* pDisplaySize
   ' =====================================================================================
   PROPERTY SET DisplaySize <1032> ( _                  ' VTable offset = 204
     BYVAL pDisplaySize AS LONG _                       ' __in long pDisplaySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MainWindow <1033> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long* pMainWindow
   ' =====================================================================================
   PROPERTY GET ControlType <1034> ( _                  ' VTable offset = 212
   ) AS LONG                                            ' __retval_out long* pControlType
   ' =====================================================================================
   PROPERTY SET ControlType <1034> ( _                  ' VTable offset = 216
     BYVAL pControlType AS LONG _                       ' __in long pControlType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowScan <1035> ( _                    ' VTable offset = 220
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowScan
   ' =====================================================================================
   PROPERTY SET AllowScan <1035> ( _                    ' VTable offset = 224
     BYVAL pAllowScan AS INTEGER _                      ' __in VARIANT_BOOL pAllowScan
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendKeyboardEvents <1013> ( _           ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendKeyboardEvents
   ' =====================================================================================
   PROPERTY SET SendKeyboardEvents <1013> ( _           ' VTable offset = 232
     BYVAL pSendKeyboardEvents AS INTEGER _             ' __in VARIANT_BOOL pSendKeyboardEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendMouseClickEvents <1014> ( _         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendMouseClickEvents
   ' =====================================================================================
   PROPERTY SET SendMouseClickEvents <1014> ( _         ' VTable offset = 240
     BYVAL pSendMouseClickEvents AS INTEGER _           ' __in VARIANT_BOOL pSendMouseClickEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendMouseMoveEvents <1015> ( _          ' VTable offset = 244
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendMouseMoveEvents
   ' =====================================================================================
   PROPERTY SET SendMouseMoveEvents <1015> ( _          ' VTable offset = 248
     BYVAL pSendMouseMoveEvents AS INTEGER _            ' __in VARIANT_BOOL pSendMouseMoveEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendStateChangeEvents <1016> ( _        ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendStateChangeEvents <1016> ( _        ' VTable offset = 256
     BYVAL pSendStateChangeEvents AS INTEGER _          ' __in VARIANT_BOOL pSendStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedPackets <1039> ( _              ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long* pReceivedPackets
   ' =====================================================================================
   PROPERTY GET RecoveredPackets <1040> ( _             ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long* pRecoveredPackets
   ' =====================================================================================
   PROPERTY GET LostPackets <1041> ( _                  ' VTable offset = 268
   ) AS LONG                                            ' __retval_out long* pLostPackets
   ' =====================================================================================
   PROPERTY GET ReceptionQuality <1042> ( _             ' VTable offset = 272
   ) AS LONG                                            ' __retval_out long* pReceptionQuality
   ' =====================================================================================
   PROPERTY GET BufferingCount <1043> ( _               ' VTable offset = 276
   ) AS LONG                                            ' __retval_out long* pBufferingCount
   ' =====================================================================================
   PROPERTY GET CursorType <1044> ( _                   ' VTable offset = 280
   ) AS LONG                                            ' __retval_out long* pCursorType
   ' =====================================================================================
   PROPERTY SET CursorType <1044> ( _                   ' VTable offset = 284
     BYVAL pCursorType AS LONG _                        ' __in long pCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnimationAtStart <1045> ( _             ' VTable offset = 288
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAnimationAtStart
   ' =====================================================================================
   PROPERTY SET AnimationAtStart <1045> ( _             ' VTable offset = 292
     BYVAL pAnimationAtStart AS INTEGER _               ' __in VARIANT_BOOL pAnimationAtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnimationOnStop <1046> ( _              ' VTable offset = 296
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAnimationOnStop
   ' =====================================================================================
   PROPERTY SET AnimationOnStop <1046> ( _              ' VTable offset = 300
     BYVAL pAnimationOnStop AS INTEGER _                ' __in VARIANT_BOOL pAnimationOnStop
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <2001> ( _                               ' VTable offset = 304
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <2002> ( _                              ' VTable offset = 308
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <2003> ( _                               ' VTable offset = 312
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMarkerTime <2004> ( _                      ' VTable offset = 316
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS DOUBLE                                          ' __retval_out double* pMarkerTime
   ' =====================================================================================
   METHOD GetMarkerName <2005> ( _                      ' VTable offset = 320
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrMarkerName
   ' =====================================================================================

   ' =====================================================================================
   ' INSPlay Methods
   ' =====================================================================================
   PROPERTY GET ChannelName <1050> ( _                  ' VTable offset = 324
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrChannelName
   ' =====================================================================================
   PROPERTY GET ChannelDescription <1051> ( _           ' VTable offset = 328
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrChannelDescription
   ' =====================================================================================
   PROPERTY GET ChannelURL <1052> ( _                   ' VTable offset = 332
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrChannelURL
   ' =====================================================================================
   PROPERTY GET ContactAddress <1053> ( _               ' VTable offset = 336
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrContactAddress
   ' =====================================================================================
   PROPERTY GET ContactPhone <1054> ( _                 ' VTable offset = 340
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrContactPhone
   ' =====================================================================================
   PROPERTY GET ContactEmail <1055> ( _                 ' VTable offset = 344
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrContactEmail
   ' =====================================================================================
   PROPERTY GET AllowChangeDisplaySize <1056> ( _       ' VTable offset = 348
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowChangeDisplaySize
   ' =====================================================================================
   PROPERTY SET AllowChangeDisplaySize <1056> ( _       ' VTable offset = 352
     BYVAL pAllowChangeDisplaySize AS INTEGER _         ' __in VARIANT_BOOL pAllowChangeDisplaySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodecCount <1057> ( _                   ' VTable offset = 356
   ) AS LONG                                            ' __retval_out long* pCodecCount
   ' =====================================================================================
   PROPERTY GET IsBroadcast <1058> ( _                  ' VTable offset = 360
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pIsBroadcast
   ' =====================================================================================
   PROPERTY GET IsDurationValid <1059> ( _              ' VTable offset = 364
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pIsDurationValid
   ' =====================================================================================
   PROPERTY GET SourceProtocol <1060> ( _               ' VTable offset = 368
   ) AS LONG                                            ' __retval_out long* pSourceProtocol
   ' =====================================================================================
   PROPERTY GET OpenState <1061> ( _                    ' VTable offset = 372
   ) AS LONG                                            ' __retval_out long* pOpenState
   ' =====================================================================================
   PROPERTY GET SendOpenStateChangeEvents <1062> ( _    ' VTable offset = 376
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendOpenStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendOpenStateChangeEvents <1062> ( _    ' VTable offset = 380
     BYVAL pSendOpenStateChangeEvents AS INTEGER _      ' __in VARIANT_BOOL pSendOpenStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendWarningEvents <1063> ( _            ' VTable offset = 384
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendWarningEvents
   ' =====================================================================================
   PROPERTY SET SendWarningEvents <1063> ( _            ' VTable offset = 388
     BYVAL pSendWarningEvents AS INTEGER _              ' __in VARIANT_BOOL pSendWarningEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendErrorEvents <1064> ( _              ' VTable offset = 392
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendErrorEvents
   ' =====================================================================================
   PROPERTY SET SendErrorEvents <1064> ( _              ' VTable offset = 396
     BYVAL pSendErrorEvents AS INTEGER _                ' __in VARIANT_BOOL pSendErrorEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HasError <1065> ( _                     ' VTable offset = 400
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pHasError
   ' =====================================================================================
   PROPERTY GET ErrorDescription <1066> ( _             ' VTable offset = 404
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrErrorDescription
   ' =====================================================================================
   PROPERTY GET ErrorCode <1067> ( _                    ' VTable offset = 408
   ) AS LONG                                            ' __retval_out long* pErrorCode
   ' =====================================================================================
   PROPERTY GET PlayState <1068> ( _                    ' VTable offset = 412
   ) AS LONG                                            ' __retval_out long* pPlayState
   ' =====================================================================================
   PROPERTY GET SendPlayStateChangeEvents <1069> ( _    ' VTable offset = 416
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendPlayStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendPlayStateChangeEvents <1069> ( _    ' VTable offset = 420
     BYVAL pSendPlayStateChangeEvents AS INTEGER _      ' __in VARIANT_BOOL pSendPlayStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferingTime <1070> ( _                ' VTable offset = 424
   ) AS DOUBLE                                          ' __retval_out double* pBufferingTime
   ' =====================================================================================
   PROPERTY SET BufferingTime <1070> ( _                ' VTable offset = 428
     BYVAL pBufferingTime AS DOUBLE _                   ' __in double pBufferingTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseFixedUDPPort <1071> ( _              ' VTable offset = 432
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pUseFixedUDPPort
   ' =====================================================================================
   PROPERTY SET UseFixedUDPPort <1071> ( _              ' VTable offset = 436
     BYVAL pUseFixedUDPPort AS INTEGER _                ' __in VARIANT_BOOL pUseFixedUDPPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FixedUDPPort <1072> ( _                 ' VTable offset = 440
   ) AS LONG                                            ' __retval_out long* pFixedUDPPort
   ' =====================================================================================
   PROPERTY SET FixedUDPPort <1072> ( _                 ' VTable offset = 444
     BYVAL pFixedUDPPort AS LONG _                      ' __in long pFixedUDPPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseHTTPProxy <1073> ( _                 ' VTable offset = 448
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pUseHTTPProxy
   ' =====================================================================================
   PROPERTY SET UseHTTPProxy <1073> ( _                 ' VTable offset = 452
     BYVAL pUseHTTPProxy AS INTEGER _                   ' __in VARIANT_BOOL pUseHTTPProxy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableAutoProxy <1081> ( _              ' VTable offset = 456
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableAutoProxy
   ' =====================================================================================
   PROPERTY SET EnableAutoProxy <1081> ( _              ' VTable offset = 460
     BYVAL pEnableAutoProxy AS INTEGER _                ' __in VARIANT_BOOL pEnableAutoProxy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HTTPProxyHost <1074> ( _                ' VTable offset = 464
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrHTTPProxyHost
   ' =====================================================================================
   PROPERTY SET HTTPProxyHost <1074> ( _                ' VTable offset = 468
     BYVAL pbstrHTTPProxyHost AS WSTRING _              ' __in BSTR pbstrHTTPProxyHost
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HTTPProxyPort <1075> ( _                ' VTable offset = 472
   ) AS LONG                                            ' __retval_out long* pHTTPProxyPort
   ' =====================================================================================
   PROPERTY SET HTTPProxyPort <1075> ( _                ' VTable offset = 476
     BYVAL pHTTPProxyPort AS LONG _                     ' __in long pHTTPProxyPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableMulticast <1076> ( _              ' VTable offset = 480
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableMulticast
   ' =====================================================================================
   PROPERTY SET EnableMulticast <1076> ( _              ' VTable offset = 484
     BYVAL pEnableMulticast AS INTEGER _                ' __in VARIANT_BOOL pEnableMulticast
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableUDP <1077> ( _                    ' VTable offset = 488
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableUDP
   ' =====================================================================================
   PROPERTY SET EnableUDP <1077> ( _                    ' VTable offset = 492
     BYVAL pEnableUDP AS INTEGER _                      ' __in VARIANT_BOOL pEnableUDP
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableTCP <1078> ( _                    ' VTable offset = 496
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableTCP
   ' =====================================================================================
   PROPERTY SET EnableTCP <1078> ( _                    ' VTable offset = 500
     BYVAL pEnableTCP AS INTEGER _                      ' __in VARIANT_BOOL pEnableTCP
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableHTTP <1079> ( _                   ' VTable offset = 504
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableHTTP
   ' =====================================================================================
   PROPERTY SET EnableHTTP <1079> ( _                   ' VTable offset = 508
     BYVAL pEnableHTTP AS INTEGER _                     ' __in VARIANT_BOOL pEnableHTTP
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferingProgress <1080> ( _            ' VTable offset = 512
   ) AS LONG                                            ' __retval_out long* pBufferingProgress
   ' =====================================================================================
   PROPERTY GET BaseURL <1082> ( _                      ' VTable offset = 516
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrBaseURL
   ' =====================================================================================
   PROPERTY SET BaseURL <1082> ( _                      ' VTable offset = 520
     BYVAL pbstrBaseURL AS WSTRING _                    ' __in BSTR pbstrBaseURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultFrame <1083> ( _                 ' VTable offset = 524
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDefaultFrame
   ' =====================================================================================
   PROPERTY SET DefaultFrame <1083> ( _                 ' VTable offset = 528
     BYVAL pbstrDefaultFrame AS WSTRING _               ' __in BSTR pbstrDefaultFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 532
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <2006> ( _                             ' VTable offset = 536
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCodecInstalled <2007> ( _                  ' VTable offset = 540
     BYVAL CodecNum AS LONG _                           ' __in long CodecNum
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCodecInstalled
   ' =====================================================================================
   METHOD GetCodecDescription <2008> ( _                ' VTable offset = 544
     BYVAL CodecNum AS LONG _                           ' __in long CodecNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCodecDescription
   ' =====================================================================================
   METHOD GetCodecURL <2009> ( _                        ' VTable offset = 548
     BYVAL CodecNum AS LONG _                           ' __in long CodecNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCodecURL
   ' =====================================================================================
   METHOD Open <2010> ( _                               ' VTable offset = 552
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INSPlay_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INSPlay1
' IID = {265EC141-AE62-11D1-8500-00A0C91F9CA0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = INSPlay
' ########################################################################################

#IF NOT %DEF(%INSPlay1_INTERFACE_DEFINED)
    %INSPlay1_INTERFACE_DEFINED = 1

INTERFACE INSPlay1 $IID_INSPlay1

   INHERIT IDispatch

   ' =====================================================================================
   ' INSOPlay Methods
   ' =====================================================================================
   PROPERTY GET ImageSourceWidth <1001> ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pWidth
   ' =====================================================================================
   PROPERTY GET ImageSourceHeight <1002> ( _            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pHeight
   ' =====================================================================================
   PROPERTY GET Duration <1003> ( _                     ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double* pDuration
   ' =====================================================================================
   PROPERTY GET Author <1004> ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrAuthor
   ' =====================================================================================
   PROPERTY GET Copyright <1005> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCopyright
   ' =====================================================================================
   PROPERTY GET Description <1006> ( _                  ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDescription
   ' =====================================================================================
   PROPERTY GET Rating <1007> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrRating
   ' =====================================================================================
   PROPERTY GET Title <1008> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   PROPERTY GET SourceLink <1009> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSourceLink
   ' =====================================================================================
   PROPERTY GET MarkerCount <1010> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* pMarkerCount
   ' =====================================================================================
   PROPERTY GET CanScan <1011> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanScan
   ' =====================================================================================
   PROPERTY GET CanSeek <1012> ( _                      ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanSeek
   ' =====================================================================================
   PROPERTY GET CanSeekToMarkers <1047> ( _             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCanSeekToMarkers
   ' =====================================================================================
   PROPERTY GET CreationDate <1036> ( _                 ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE* pCreationDate
   ' =====================================================================================
   PROPERTY GET Bandwidth <1037> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* pBandwidth
   ' =====================================================================================
   PROPERTY GET ErrorCorrection <1038> ( _              ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrErrorCorrection
   ' =====================================================================================
   PROPERTY GET AutoStart <1017> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAutoStart
   ' =====================================================================================
   PROPERTY SET AutoStart <1017> ( _                    ' VTable offset = 96
     BYVAL pAutoStart AS INTEGER _                      ' __in VARIANT_BOOL pAutoStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoRewind <1018> ( _                   ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAutoRewind
   ' =====================================================================================
   PROPERTY SET AutoRewind <1018> ( _                   ' VTable offset = 104
     BYVAL pAutoRewind AS INTEGER _                     ' __in VARIANT_BOOL pAutoRewind
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowChangeControlType <1019> ( _       ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowChangeControlType
   ' =====================================================================================
   PROPERTY SET AllowChangeControlType <1019> ( _       ' VTable offset = 112
     BYVAL pAllowChangeControlType AS INTEGER _         ' __in VARIANT_BOOL pAllowChangeControlType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InvokeURLs <1020> ( _                   ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pInvokeURLs
   ' =====================================================================================
   PROPERTY SET InvokeURLs <1020> ( _                   ' VTable offset = 120
     BYVAL pInvokeURLs AS INTEGER _                     ' __in VARIANT_BOOL pInvokeURLs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableContextMenu <1021> ( _            ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableContextMenu
   ' =====================================================================================
   PROPERTY SET EnableContextMenu <1021> ( _            ' VTable offset = 128
     BYVAL pEnableContextMenu AS INTEGER _              ' __in VARIANT_BOOL pEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransparentAtStart <1022> ( _           ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pTransparentAtStart
   ' =====================================================================================
   PROPERTY SET TransparentAtStart <1022> ( _           ' VTable offset = 136
     BYVAL pTransparentAtStart AS INTEGER _             ' __in VARIANT_BOOL pTransparentAtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransparentOnStop <1023> ( _            ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pTransparentOnStop
   ' =====================================================================================
   PROPERTY SET TransparentOnStop <1023> ( _            ' VTable offset = 144
     BYVAL pTransparentOnStop AS INTEGER _              ' __in VARIANT_BOOL pTransparentOnStop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClickToPlay <1025> ( _                  ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pClickToPlay
   ' =====================================================================================
   PROPERTY SET ClickToPlay <1025> ( _                  ' VTable offset = 152
     BYVAL pClickToPlay AS INTEGER _                    ' __in VARIANT_BOOL pClickToPlay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <1026> ( _                     ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <1026> ( _                     ' VTable offset = 160
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <1027> ( _              ' VTable offset = 164
   ) AS DOUBLE                                          ' __retval_out double* pCurrentPosition
   ' =====================================================================================
   PROPERTY SET CurrentPosition <1027> ( _              ' VTable offset = 168
     BYVAL pCurrentPosition AS DOUBLE _                 ' __in double pCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <1028> ( _                         ' VTable offset = 172
   ) AS DOUBLE                                          ' __retval_out double* pRate
   ' =====================================================================================
   PROPERTY SET Rate <1028> ( _                         ' VTable offset = 176
     BYVAL pRate AS DOUBLE _                            ' __in double pRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentMarker <1029> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out long* pCurrentMarker
   ' =====================================================================================
   PROPERTY SET CurrentMarker <1029> ( _                ' VTable offset = 184
     BYVAL pCurrentMarker AS LONG _                     ' __in long pCurrentMarker
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayCount <1030> ( _                    ' VTable offset = 188
   ) AS LONG                                            ' __retval_out long* pPlayCount
   ' =====================================================================================
   PROPERTY SET PlayCount <1030> ( _                    ' VTable offset = 192
     BYVAL pPlayCount AS LONG _                         ' __in long pPlayCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentState <1031> ( _                 ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long* pCurrentState
   ' =====================================================================================
   PROPERTY GET DisplaySize <1032> ( _                  ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long* pDisplaySize
   ' =====================================================================================
   PROPERTY SET DisplaySize <1032> ( _                  ' VTable offset = 204
     BYVAL pDisplaySize AS LONG _                       ' __in long pDisplaySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MainWindow <1033> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long* pMainWindow
   ' =====================================================================================
   PROPERTY GET ControlType <1034> ( _                  ' VTable offset = 212
   ) AS LONG                                            ' __retval_out long* pControlType
   ' =====================================================================================
   PROPERTY SET ControlType <1034> ( _                  ' VTable offset = 216
     BYVAL pControlType AS LONG _                       ' __in long pControlType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowScan <1035> ( _                    ' VTable offset = 220
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowScan
   ' =====================================================================================
   PROPERTY SET AllowScan <1035> ( _                    ' VTable offset = 224
     BYVAL pAllowScan AS INTEGER _                      ' __in VARIANT_BOOL pAllowScan
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendKeyboardEvents <1013> ( _           ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendKeyboardEvents
   ' =====================================================================================
   PROPERTY SET SendKeyboardEvents <1013> ( _           ' VTable offset = 232
     BYVAL pSendKeyboardEvents AS INTEGER _             ' __in VARIANT_BOOL pSendKeyboardEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendMouseClickEvents <1014> ( _         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendMouseClickEvents
   ' =====================================================================================
   PROPERTY SET SendMouseClickEvents <1014> ( _         ' VTable offset = 240
     BYVAL pSendMouseClickEvents AS INTEGER _           ' __in VARIANT_BOOL pSendMouseClickEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendMouseMoveEvents <1015> ( _          ' VTable offset = 244
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendMouseMoveEvents
   ' =====================================================================================
   PROPERTY SET SendMouseMoveEvents <1015> ( _          ' VTable offset = 248
     BYVAL pSendMouseMoveEvents AS INTEGER _            ' __in VARIANT_BOOL pSendMouseMoveEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendStateChangeEvents <1016> ( _        ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendStateChangeEvents <1016> ( _        ' VTable offset = 256
     BYVAL pSendStateChangeEvents AS INTEGER _          ' __in VARIANT_BOOL pSendStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedPackets <1039> ( _              ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long* pReceivedPackets
   ' =====================================================================================
   PROPERTY GET RecoveredPackets <1040> ( _             ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long* pRecoveredPackets
   ' =====================================================================================
   PROPERTY GET LostPackets <1041> ( _                  ' VTable offset = 268
   ) AS LONG                                            ' __retval_out long* pLostPackets
   ' =====================================================================================
   PROPERTY GET ReceptionQuality <1042> ( _             ' VTable offset = 272
   ) AS LONG                                            ' __retval_out long* pReceptionQuality
   ' =====================================================================================
   PROPERTY GET BufferingCount <1043> ( _               ' VTable offset = 276
   ) AS LONG                                            ' __retval_out long* pBufferingCount
   ' =====================================================================================
   PROPERTY GET CursorType <1044> ( _                   ' VTable offset = 280
   ) AS LONG                                            ' __retval_out long* pCursorType
   ' =====================================================================================
   PROPERTY SET CursorType <1044> ( _                   ' VTable offset = 284
     BYVAL pCursorType AS LONG _                        ' __in long pCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnimationAtStart <1045> ( _             ' VTable offset = 288
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAnimationAtStart
   ' =====================================================================================
   PROPERTY SET AnimationAtStart <1045> ( _             ' VTable offset = 292
     BYVAL pAnimationAtStart AS INTEGER _               ' __in VARIANT_BOOL pAnimationAtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnimationOnStop <1046> ( _              ' VTable offset = 296
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAnimationOnStop
   ' =====================================================================================
   PROPERTY SET AnimationOnStop <1046> ( _              ' VTable offset = 300
     BYVAL pAnimationOnStop AS INTEGER _                ' __in VARIANT_BOOL pAnimationOnStop
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <2001> ( _                               ' VTable offset = 304
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <2002> ( _                              ' VTable offset = 308
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <2003> ( _                               ' VTable offset = 312
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMarkerTime <2004> ( _                      ' VTable offset = 316
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS DOUBLE                                          ' __retval_out double* pMarkerTime
   ' =====================================================================================
   METHOD GetMarkerName <2005> ( _                      ' VTable offset = 320
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrMarkerName
   ' =====================================================================================

   ' =====================================================================================
   ' INSPlay Methods
   ' =====================================================================================
   PROPERTY GET ChannelName <1050> ( _                  ' VTable offset = 324
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrChannelName
   ' =====================================================================================
   PROPERTY GET ChannelDescription <1051> ( _           ' VTable offset = 328
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrChannelDescription
   ' =====================================================================================
   PROPERTY GET ChannelURL <1052> ( _                   ' VTable offset = 332
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrChannelURL
   ' =====================================================================================
   PROPERTY GET ContactAddress <1053> ( _               ' VTable offset = 336
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrContactAddress
   ' =====================================================================================
   PROPERTY GET ContactPhone <1054> ( _                 ' VTable offset = 340
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrContactPhone
   ' =====================================================================================
   PROPERTY GET ContactEmail <1055> ( _                 ' VTable offset = 344
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrContactEmail
   ' =====================================================================================
   PROPERTY GET AllowChangeDisplaySize <1056> ( _       ' VTable offset = 348
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowChangeDisplaySize
   ' =====================================================================================
   PROPERTY SET AllowChangeDisplaySize <1056> ( _       ' VTable offset = 352
     BYVAL pAllowChangeDisplaySize AS INTEGER _         ' __in VARIANT_BOOL pAllowChangeDisplaySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodecCount <1057> ( _                   ' VTable offset = 356
   ) AS LONG                                            ' __retval_out long* pCodecCount
   ' =====================================================================================
   PROPERTY GET IsBroadcast <1058> ( _                  ' VTable offset = 360
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pIsBroadcast
   ' =====================================================================================
   PROPERTY GET IsDurationValid <1059> ( _              ' VTable offset = 364
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pIsDurationValid
   ' =====================================================================================
   PROPERTY GET SourceProtocol <1060> ( _               ' VTable offset = 368
   ) AS LONG                                            ' __retval_out long* pSourceProtocol
   ' =====================================================================================
   PROPERTY GET OpenState <1061> ( _                    ' VTable offset = 372
   ) AS LONG                                            ' __retval_out long* pOpenState
   ' =====================================================================================
   PROPERTY GET SendOpenStateChangeEvents <1062> ( _    ' VTable offset = 376
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendOpenStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendOpenStateChangeEvents <1062> ( _    ' VTable offset = 380
     BYVAL pSendOpenStateChangeEvents AS INTEGER _      ' __in VARIANT_BOOL pSendOpenStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendWarningEvents <1063> ( _            ' VTable offset = 384
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendWarningEvents
   ' =====================================================================================
   PROPERTY SET SendWarningEvents <1063> ( _            ' VTable offset = 388
     BYVAL pSendWarningEvents AS INTEGER _              ' __in VARIANT_BOOL pSendWarningEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendErrorEvents <1064> ( _              ' VTable offset = 392
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendErrorEvents
   ' =====================================================================================
   PROPERTY SET SendErrorEvents <1064> ( _              ' VTable offset = 396
     BYVAL pSendErrorEvents AS INTEGER _                ' __in VARIANT_BOOL pSendErrorEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HasError <1065> ( _                     ' VTable offset = 400
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pHasError
   ' =====================================================================================
   PROPERTY GET ErrorDescription <1066> ( _             ' VTable offset = 404
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrErrorDescription
   ' =====================================================================================
   PROPERTY GET ErrorCode <1067> ( _                    ' VTable offset = 408
   ) AS LONG                                            ' __retval_out long* pErrorCode
   ' =====================================================================================
   PROPERTY GET PlayState <1068> ( _                    ' VTable offset = 412
   ) AS LONG                                            ' __retval_out long* pPlayState
   ' =====================================================================================
   PROPERTY GET SendPlayStateChangeEvents <1069> ( _    ' VTable offset = 416
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pSendPlayStateChangeEvents
   ' =====================================================================================
   PROPERTY SET SendPlayStateChangeEvents <1069> ( _    ' VTable offset = 420
     BYVAL pSendPlayStateChangeEvents AS INTEGER _      ' __in VARIANT_BOOL pSendPlayStateChangeEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferingTime <1070> ( _                ' VTable offset = 424
   ) AS DOUBLE                                          ' __retval_out double* pBufferingTime
   ' =====================================================================================
   PROPERTY SET BufferingTime <1070> ( _                ' VTable offset = 428
     BYVAL pBufferingTime AS DOUBLE _                   ' __in double pBufferingTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseFixedUDPPort <1071> ( _              ' VTable offset = 432
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pUseFixedUDPPort
   ' =====================================================================================
   PROPERTY SET UseFixedUDPPort <1071> ( _              ' VTable offset = 436
     BYVAL pUseFixedUDPPort AS INTEGER _                ' __in VARIANT_BOOL pUseFixedUDPPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FixedUDPPort <1072> ( _                 ' VTable offset = 440
   ) AS LONG                                            ' __retval_out long* pFixedUDPPort
   ' =====================================================================================
   PROPERTY SET FixedUDPPort <1072> ( _                 ' VTable offset = 444
     BYVAL pFixedUDPPort AS LONG _                      ' __in long pFixedUDPPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseHTTPProxy <1073> ( _                 ' VTable offset = 448
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pUseHTTPProxy
   ' =====================================================================================
   PROPERTY SET UseHTTPProxy <1073> ( _                 ' VTable offset = 452
     BYVAL pUseHTTPProxy AS INTEGER _                   ' __in VARIANT_BOOL pUseHTTPProxy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableAutoProxy <1081> ( _              ' VTable offset = 456
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableAutoProxy
   ' =====================================================================================
   PROPERTY SET EnableAutoProxy <1081> ( _              ' VTable offset = 460
     BYVAL pEnableAutoProxy AS INTEGER _                ' __in VARIANT_BOOL pEnableAutoProxy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HTTPProxyHost <1074> ( _                ' VTable offset = 464
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrHTTPProxyHost
   ' =====================================================================================
   PROPERTY SET HTTPProxyHost <1074> ( _                ' VTable offset = 468
     BYVAL pbstrHTTPProxyHost AS WSTRING _              ' __in BSTR pbstrHTTPProxyHost
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HTTPProxyPort <1075> ( _                ' VTable offset = 472
   ) AS LONG                                            ' __retval_out long* pHTTPProxyPort
   ' =====================================================================================
   PROPERTY SET HTTPProxyPort <1075> ( _                ' VTable offset = 476
     BYVAL pHTTPProxyPort AS LONG _                     ' __in long pHTTPProxyPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableMulticast <1076> ( _              ' VTable offset = 480
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableMulticast
   ' =====================================================================================
   PROPERTY SET EnableMulticast <1076> ( _              ' VTable offset = 484
     BYVAL pEnableMulticast AS INTEGER _                ' __in VARIANT_BOOL pEnableMulticast
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableUDP <1077> ( _                    ' VTable offset = 488
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableUDP
   ' =====================================================================================
   PROPERTY SET EnableUDP <1077> ( _                    ' VTable offset = 492
     BYVAL pEnableUDP AS INTEGER _                      ' __in VARIANT_BOOL pEnableUDP
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableTCP <1078> ( _                    ' VTable offset = 496
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableTCP
   ' =====================================================================================
   PROPERTY SET EnableTCP <1078> ( _                    ' VTable offset = 500
     BYVAL pEnableTCP AS INTEGER _                      ' __in VARIANT_BOOL pEnableTCP
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableHTTP <1079> ( _                   ' VTable offset = 504
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnableHTTP
   ' =====================================================================================
   PROPERTY SET EnableHTTP <1079> ( _                   ' VTable offset = 508
     BYVAL pEnableHTTP AS INTEGER _                     ' __in VARIANT_BOOL pEnableHTTP
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferingProgress <1080> ( _            ' VTable offset = 512
   ) AS LONG                                            ' __retval_out long* pBufferingProgress
   ' =====================================================================================
   PROPERTY GET BaseURL <1082> ( _                      ' VTable offset = 516
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrBaseURL
   ' =====================================================================================
   PROPERTY SET BaseURL <1082> ( _                      ' VTable offset = 520
     BYVAL pbstrBaseURL AS WSTRING _                    ' __in BSTR pbstrBaseURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultFrame <1083> ( _                 ' VTable offset = 524
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDefaultFrame
   ' =====================================================================================
   PROPERTY SET DefaultFrame <1083> ( _                 ' VTable offset = 528
     BYVAL pbstrDefaultFrame AS WSTRING _               ' __in BSTR pbstrDefaultFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 532
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <2006> ( _                             ' VTable offset = 536
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCodecInstalled <2007> ( _                  ' VTable offset = 540
     BYVAL CodecNum AS LONG _                           ' __in long CodecNum
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pCodecInstalled
   ' =====================================================================================
   METHOD GetCodecDescription <2008> ( _                ' VTable offset = 544
     BYVAL CodecNum AS LONG _                           ' __in long CodecNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCodecDescription
   ' =====================================================================================
   METHOD GetCodecURL <2009> ( _                        ' VTable offset = 548
     BYVAL CodecNum AS LONG _                           ' __in long CodecNum
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCodecURL
   ' =====================================================================================
   METHOD Open <2010> ( _                               ' VTable offset = 552
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' INSPlay1 Methods
   ' =====================================================================================
   PROPERTY GET MediaPlayer <1111> ( _                  ' VTable offset = 556
   ) AS IDispatch                                       ' __retval_out IDispatch** ppdispatch
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INSPlay1_INTERFACE_DEFINED__ */
