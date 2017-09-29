' ########################################################################################
' Microsoft Windows
' File: FLASH9.inc
' Library name: ShockwaveFlashObjects
' Version: 1.0, Locale ID = 0
' Library GUID: {D27CDB6B-AE6D-11CF-96B8-444553540000}
' Path: C:\WINDOWS\system32\Macromed\Flash\Flash9d.ocx
' Contents: Shockwave Flash
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Adobe Systems Incorporated
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FLASH9_INC = 1

#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {D27CDB6E-AE6D-11CF-96B8-444553540000}
$PROGID_ShockwaveFlash9 = "ShockwaveFlash.ShockwaveFlash.9"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {D27CDB6E-AE6D-11CF-96B8-444553540000}
$PROGID_ShockwaveFlash = "ShockwaveFlash.ShockwaveFlash"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_FlashObjectInterface = GUID$("{D27CDB71-AE6D-11CF-96B8-444553540000}")
$CLSID_FlashProp = GUID$("{1171A62F-05D2-11D1-83FC-00A0C9089C5A}")
$CLSID_ShockwaveFlash = GUID$("{D27CDB6E-AE6D-11CF-96B8-444553540000}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IFlashFactory = GUID$("{D27CDB70-AE6D-11CF-96B8-444553540000}")
$IID_IFlashObjectInterface = GUID$("{D27CDB72-AE6D-11CF-96B8-444553540000}")
$IID_IShockwaveFlash = GUID$("{D27CDB6C-AE6D-11CF-96B8-444553540000}")
$IID__IShockwaveFlashEvents = GUID$("{D27CDB6D-AE6D-11CF-96B8-444553540000}")

' ########################################################################################
' Interface name = IShockwaveFlash
' IID = {D27CDB6C-AE6D-11CF-96B8-444553540000}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IShockwaveFlash_INTERFACE_DEFINED)
    %IShockwaveFlash_INTERFACE_DEFINED = 1

INTERFACE IShockwaveFlash $IID_IShockwaveFlash

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET TotalFrames <124> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET Playing <125> ( _                       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET Playing <125> ( _                       ' VTable offset = 40
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Quality <105> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pVal
   ' =====================================================================================
   PROPERTY SET Quality <105> ( _                       ' VTable offset = 48
     BYVAL pVal AS LONG _                               ' __in int pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScaleMode <120> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int* pVal
   ' =====================================================================================
   PROPERTY SET ScaleMode <120> ( _                     ' VTable offset = 56
     BYVAL pVal AS LONG _                               ' __in int pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlignMode <121> ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int* pVal
   ' =====================================================================================
   PROPERTY SET AlignMode <121> ( _                     ' VTable offset = 64
     BYVAL pVal AS LONG _                               ' __in int pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackgroundColor <123> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY SET BackgroundColor <123> ( _               ' VTable offset = 72
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Loop <106> ( _                          ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET Loop <106> ( _                          ' VTable offset = 80
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Movie <102> ( _                         ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Movie <102> ( _                         ' VTable offset = 88
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrameNum <107> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY SET FrameNum <107> ( _                      ' VTable offset = 96
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SetZoomRect <109> ( _                         ' VTable offset = 100
     BYVAL left AS LONG _                               ' __in long left
   , BYVAL top AS LONG _                                ' __in long top
   , BYVAL right AS LONG _                              ' __in long right
   , BYVAL bottom AS LONG _                             ' __in long bottom
   )                                                    ' void
   ' =====================================================================================
   METHOD Zoom <118> ( _                                ' VTable offset = 104
     BYVAL factor AS LONG _                             ' __in int factor
   )                                                    ' void
   ' =====================================================================================
   METHOD Pan <119> ( _                                 ' VTable offset = 108
     BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   , BYVAL mode AS LONG _                               ' __in int mode
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <112> ( _                                ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <113> ( _                                ' VTable offset = 116
   )                                                    ' void
   ' =====================================================================================
   METHOD Back <114> ( _                                ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD Forward <115> ( _                             ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Rewind <116> ( _                              ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD StopPlay <126> ( _                            ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD GotoFrame <127> ( _                           ' VTable offset = 136
     BYVAL FrameNum AS LONG _                           ' __in long FrameNum
   )                                                    ' void
   ' =====================================================================================
   METHOD CurrentFrame <128> ( _                        ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long* FrameNum
   ' =====================================================================================
   METHOD IsPlaying <129> ( _                           ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Playing
   ' =====================================================================================
   METHOD PercentLoaded <130> ( _                       ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long* percent
   ' =====================================================================================
   METHOD FrameLoaded <131> ( _                         ' VTable offset = 152
     BYVAL FrameNum AS LONG _                           ' __in long FrameNum
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* loaded
   ' =====================================================================================
   METHOD FlashVersion <132> ( _                        ' VTable offset = 156
   ) AS LONG                                            ' __retval_out long* version
   ' =====================================================================================
   PROPERTY GET WMode <133> ( _                         ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET WMode <133> ( _                         ' VTable offset = 164
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAlign <134> ( _                        ' VTable offset = 168
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET SAlign <134> ( _                        ' VTable offset = 172
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Menu <135> ( _                          ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET Menu <135> ( _                          ' VTable offset = 180
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Base <136> ( _                          ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Base <136> ( _                          ' VTable offset = 188
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scale <137> ( _                         ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Scale <137> ( _                         ' VTable offset = 196
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeviceFont <138> ( _                    ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET DeviceFont <138> ( _                    ' VTable offset = 204
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmbedMovie <139> ( _                    ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET EmbedMovie <139> ( _                    ' VTable offset = 212
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BGColor <140> ( _                       ' VTable offset = 216
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET BGColor <140> ( _                       ' VTable offset = 220
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Quality2 <141> ( _                      ' VTable offset = 224
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Quality2 <141> ( _                      ' VTable offset = 228
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadMovie <142> ( _                           ' VTable offset = 232
     BYVAL layer AS LONG _                              ' __in int layer
   , BYVAL url AS WSTRING _                             ' __in BSTR url
   )                                                    ' void
   ' =====================================================================================
   METHOD TGotoFrame <143> ( _                          ' VTable offset = 236
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL FrameNum AS LONG _                           ' __in long FrameNum
   )                                                    ' void
   ' =====================================================================================
   METHOD TGotoLabel <144> ( _                          ' VTable offset = 240
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL label AS WSTRING _                           ' __in BSTR label
   )                                                    ' void
   ' =====================================================================================
   METHOD TCurrentFrame <145> ( _                       ' VTable offset = 244
     BYVAL target AS WSTRING _                          ' __in BSTR target
   ) AS LONG                                            ' __retval_out long* FrameNum
   ' =====================================================================================
   METHOD TCurrentLabel <146> ( _                       ' VTable offset = 248
     BYVAL target AS WSTRING _                          ' __in BSTR target
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD TPlay <147> ( _                               ' VTable offset = 252
     BYVAL target AS WSTRING _                          ' __in BSTR target
   )                                                    ' void
   ' =====================================================================================
   METHOD TStopPlay <148> ( _                           ' VTable offset = 256
     BYVAL target AS WSTRING _                          ' __in BSTR target
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVariable <151> ( _                         ' VTable offset = 260
     BYVAL name AS WSTRING _                            ' __in BSTR name
   , BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVariable <152> ( _                         ' VTable offset = 264
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD TSetProperty <153> ( _                        ' VTable offset = 268
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL property AS LONG _                           ' __in int property
   , BYVAL value AS WSTRING _                           ' __in BSTR value
   )                                                    ' void
   ' =====================================================================================
   METHOD TGetProperty <154> ( _                        ' VTable offset = 272
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL property AS LONG _                           ' __in int property
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD TCallFrame <155> ( _                          ' VTable offset = 276
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL FrameNum AS LONG _                           ' __in int FrameNum
   )                                                    ' void
   ' =====================================================================================
   METHOD TCallLabel <156> ( _                          ' VTable offset = 280
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL label AS WSTRING _                           ' __in BSTR label
   )                                                    ' void
   ' =====================================================================================
   METHOD TSetPropertyNum <157> ( _                     ' VTable offset = 284
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL property AS LONG _                           ' __in int property
   , BYVAL value AS DOUBLE _                            ' __in double value
   )                                                    ' void
   ' =====================================================================================
   METHOD TGetPropertyNum <158> ( _                     ' VTable offset = 288
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL property AS LONG _                           ' __in int property
   ) AS DOUBLE                                          ' __retval_out double* pVal
   ' =====================================================================================
   METHOD TGetPropertyAsNumber <172> ( _                ' VTable offset = 292
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , BYVAL property AS LONG _                           ' __in int property
   ) AS DOUBLE                                          ' __retval_out double* pVal
   ' =====================================================================================
   PROPERTY GET SWRemote <159> ( _                      ' VTable offset = 296
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET SWRemote <159> ( _                      ' VTable offset = 300
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FlashVars <170> ( _                     ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET FlashVars <170> ( _                     ' VTable offset = 308
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowScriptAccess <171> ( _             ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET AllowScriptAccess <171> ( _             ' VTable offset = 316
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MovieData <190> ( _                     ' VTable offset = 320
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET MovieData <190> ( _                     ' VTable offset = 324
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InlineData <191> ( _                    ' VTable offset = 328
   ) AS IUnknown                                        ' __retval_out IUnknown** ppIUnknown
   ' =====================================================================================
   PROPERTY SET InlineData <191> ( _                    ' VTable offset = 332
     BYVAL ppIUnknown AS IUnknown _                     ' __in IUnknown* ppIUnknown
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeamlessTabbing <192> ( _               ' VTable offset = 336
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET SeamlessTabbing <192> ( _               ' VTable offset = 340
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD EnforceLocalSecurity <193> ( _                ' VTable offset = 344
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Profile <194> ( _                       ' VTable offset = 348
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET Profile <194> ( _                       ' VTable offset = 352
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProfileAddress <195> ( _                ' VTable offset = 356
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET ProfileAddress <195> ( _                ' VTable offset = 360
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProfilePort <196> ( _                   ' VTable offset = 364
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY SET ProfilePort <196> ( _                   ' VTable offset = 368
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD CallFunction <198> ( _                        ' VTable offset = 372
     BYVAL request AS WSTRING _                         ' __in BSTR request
   ) AS WSTRING                                         ' __retval_out BSTR* response
   ' =====================================================================================
   METHOD SetReturnValue <199> ( _                      ' VTable offset = 376
     BYVAL returnValue AS WSTRING _                     ' __in BSTR returnValue
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableLocalSecurity <200> ( _                ' VTable offset = 380
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowNetworking <201> ( _               ' VTable offset = 384
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET AllowNetworking <201> ( _               ' VTable offset = 388
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowFullScreen <202> ( _               ' VTable offset = 392
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET AllowFullScreen <202> ( _               ' VTable offset = 396
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShockwaveFlash_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFlashFactory
' IID = {D27CDB70-AE6D-11CF-96B8-444553540000}
' IFlashFactory Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFlashFactory_INTERFACE_DEFINED)
    %IFlashFactory_INTERFACE_DEFINED = 1

INTERFACE IFlashFactory $IID_IFlashFactory

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IFlashFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFlashObjectInterface
' IID = {D27CDB72-AE6D-11CF-96B8-444553540000}
' IFlashObjectInterface Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatchEx
' ########################################################################################

#IF NOT %DEF(%IFlashObjectInterface_INTERFACE_DEFINED)
    %IFlashObjectInterface_INTERFACE_DEFINED = 1

INTERFACE IFlashObjectInterface $IID_IFlashObjectInterface

   INHERIT IDispatch

   ' =====================================================================================
   ' IDispatchEx Methods
   ' =====================================================================================
   METHOD GetDispID <1610743808> ( _                    ' VTable offset = 28
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL grfdex AS DWORD _                            ' __in unsigned long grfdex
   , BYREF pid AS LONG _                                ' __out long* pid
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoteInvokeEx <1610743809> ( _               ' VTable offset = 32
     BYVAL id AS LONG _                                 ' __in long id
   , BYVAL lcid AS DWORD _                              ' __in unsigned long lcid
   , BYVAL dwFlags AS DWORD _                           ' __in unsigned long dwFlags
   , BYREF pdp AS DISPPARAMS _                          ' __in DISPPARAMS* pdp
   , BYREF pvarRes AS VARIANT _                         ' __out VARIANT* pvarRes
   , BYREF pei AS EXCEPINFO _                           ' __out EXCEPINFO* pei
   , BYVAL pspCaller AS IServiceProvider _              ' __in IServiceProvider* pspCaller
   , BYVAL cvarRefArg AS DWORD _                        ' __in unsigned long cvarRefArg
   , BYREF rgiRefArg AS DWORD _                         ' __in unsigned long *rgiRefArg
   , BYREF rgvarRefArg AS VARIANT _                     ' __in_out VARIANT *rgvarRefArg
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMemberByName <1610743810> ( _           ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL grfdex AS DWORD _                            ' __in unsigned long grfdex
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMemberByDispID <1610743811> ( _         ' VTable offset = 40
     BYVAL id AS LONG _                                 ' __in long id
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMemberProperties <1610743812> ( _          ' VTable offset = 44
     BYVAL id AS LONG _                                 ' __in long id
   , BYVAL grfdexFetch AS DWORD _                       ' __in unsigned long grfdexFetch
   , BYREF pgrfdex AS DWORD _                           ' __out unsigned long* pgrfdex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMemberName <1610743813> ( _                ' VTable offset = 48
     BYVAL id AS LONG _                                 ' __in long id
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR* pbstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNextDispID <1610743814> ( _                ' VTable offset = 52
     BYVAL grfdex AS DWORD _                            ' __in unsigned long grfdex
   , BYVAL id AS LONG _                                 ' __in long id
   , BYREF pid AS LONG _                                ' __out long* pid
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNameSpaceParent <1610743815> ( _           ' VTable offset = 56
     BYREF ppunk AS IUnknown _                          ' __out IUnknown* ppunk
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFlashObjectInterface_INTERFACE_DEFINED__ */
